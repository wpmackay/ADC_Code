/*
 * kalmanStepRedux.c
 *
 * Code generation for function 'kalmanStepRedux'
 *
 * C source code generated on: Thu Jan 29 17:46:45 2015
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "kalmanStepRedux.h"
#include "sind.h"
#include "norm.h"
#include "mpower.h"
#include "cpm.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
static real_T rt_powd_snf(real_T u0, real_T u1);

/* Function Definitions */
static real_T rt_powd_snf(real_T u0, real_T u1)
{
  real_T y;
  real_T d0;
  real_T d1;
  if (rtIsNaN(u0) || rtIsNaN(u1)) {
    y = rtNaN;
  } else {
    d0 = fabs(u0);
    d1 = fabs(u1);
    if (rtIsInf(u1)) {
      if (d0 == 1.0) {
        y = rtNaN;
      } else if (d0 > 1.0) {
        if (u1 > 0.0) {
          y = rtInf;
        } else {
          y = 0.0;
        }
      } else if (u1 > 0.0) {
        y = 0.0;
      } else {
        y = rtInf;
      }
    } else if (d1 == 0.0) {
      y = 1.0;
    } else if (d1 == 1.0) {
      if (u1 > 0.0) {
        y = u0;
      } else {
        y = 1.0 / u0;
      }
    } else if (u1 == 2.0) {
      y = u0 * u0;
    } else if ((u1 == 0.5) && (u0 >= 0.0)) {
      y = sqrt(u0);
    } else if ((u0 < 0.0) && (u1 > floor(u1))) {
      y = rtNaN;
    } else {
      y = pow(u0, u1);
    }
  }

  return y;
}

void kalmanStepRedux(const real_T B_in[3], const real_T B_meas_in[3], const
                     real_T rr_meas_in[3], const real_T q_meas_in[4], real_T
                     trackerAvail, const real_T w_meas_in[3], real_T q_hat_in[4],
                     real_T P_in[36], real_T B_hat_in[3], real_T q_hat_out[4],
                     real_T w_hat[3], real_T *theta_hat, real_T *psi_hat, real_T
                     *phi_hat, real_T sig3_out[6], real_T B_hat_out[3], real_T
                     P_out[36])
{
  real_T R_data[36];
  static const real_T dv0[36] = { 40000.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 40000.0,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 40000.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0001101, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0001101, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0001101 };

  static const real_T dv1[9] = { 40000.0, 0.0, 0.0, 0.0, 40000.0, 0.0, 0.0, 0.0,
    40000.0 };

  real_T A_hat[9];
  real_T PSI[3];
  int32_T i0;
  int32_T br;
  real_T b_A_hat[3];
  real_T I[9];
  real_T dv2[9];
  real_T C_data[36];
  int32_T H_size_idx_0;
  real_T H_data[36];
  real_T b_I[18];
  real_T y_data[36];
  int32_T c;
  int32_T cr;
  int32_T ic;
  int32_T ar;
  int32_T ib;
  int32_T ia;
  real_T K_data[36];
  real_T b_C_data[36];
  int32_T C_size[2];
  int32_T R_size[2];
  real_T F[36];
  real_T y[36];
  real_T dx[6];
  real_T h_data[6];
  real_T b_y_data[6];
  real_T b_q_hat_in[12];
  real_T dv3[12];
  static const int8_T b[9] = { 1, 0, 0, 0, 1, 0, 0, 0, 1 };

  real_T b_y;
  real_T scale;
  real_T absxk;
  real_T t;
  real_T x[16];
  static const real_T c_y[36] = { 3.6858255210000003E-9, 0.0, 0.0, 0.0, 0.0, 0.0,
    0.0, 3.6858255210000003E-9, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0,
    3.6858255210000003E-9, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 3.6858255209999989E-15,
    0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 3.6858255209999989E-15, 0.0, 0.0, 0.0, 0.0,
    0.0, 0.0, 3.6858255209999989E-15 };

  /* % Performs one kalman operation. */
  /* % Inputs: */
  /*    B_in - 1x3 - IGRF components */
  /*    B_meas_in - 1 x 3 - Magnetometer measurements */
  /*    rr_meas -   1 x 3 - star tracker reference vector measurement */
  /*    q_hat_in -  4 x 1 - Previous estimated quaternion */
  /*    q_meas_in - 4 x 1 - star tracker measured quaternion */
  /*    P_in -      6 x 6 - Previous covariance matrix */
  /*    w_meas_in - 3 x 1 - Gyro rate measurement in rad/s */
  /*    B_hat_in  - 3 x 1 - Previous Gyro bias estimate */
  /*    trackerAvail- 1 x 1 - 0 or 1 value indicating whether a star tracker */
  /*    measurement is available */
  /* % Outputs: */
  /*    q_hat_out - 4 x 1 - Current Estimated Quaternion */
  /*    B_hat_out - 3 x 1 - Current Gyro Bias Estimate */
  /*    sig3_out  - 6 x 1 - 3 sigma bounds for Euler Angle error */
  /*    theta_hat - 1 x 1 - Theta angle in degrees */
  /*    psi_hat   - 1 x 1 - Psi angle in degrees */
  /*    phi_hat   - 1 x 1 - Phi angle in degrees */
  /*    w_hat     - 3 x 1 - estimated angular rates in rad/s */
  /*    P_out     - 6 x 6 - Current covarian */
  if (trackerAvail == 1.0) {
    /* && t(k)~=0 %If a star tracker measurement is available */
    memcpy(&R_data[0], &dv0[0], 36U * sizeof(real_T));
  } else {
    memcpy(&R_data[0], &dv1[0], 9U * sizeof(real_T));
  }

  /*  If weights of the star tracker and magnetometers are adjusted, can tune */
  /*  filter performance. */
  /*  Gain */
  /*  This function converts a quaternion to an attitude matrix. */
  /*  Andrew Dianetti */
  /*  5 December 2014 */
  A_hat[0] = ((rt_powd_snf(q_hat_in[0], 2.0) - rt_powd_snf(q_hat_in[1], 2.0)) -
              rt_powd_snf(q_hat_in[2], 2.0)) + rt_powd_snf(q_hat_in[3], 2.0);
  A_hat[3] = 2.0 * (q_hat_in[0] * q_hat_in[1] + q_hat_in[2] * q_hat_in[3]);
  A_hat[6] = 2.0 * (q_hat_in[0] * q_hat_in[2] - q_hat_in[1] * q_hat_in[3]);
  A_hat[1] = 2.0 * (q_hat_in[0] * q_hat_in[1] - q_hat_in[2] * q_hat_in[3]);
  A_hat[4] = ((-rt_powd_snf(q_hat_in[0], 2.0) + rt_powd_snf(q_hat_in[1], 2.0)) -
              rt_powd_snf(q_hat_in[2], 2.0)) + rt_powd_snf(q_hat_in[3], 2.0);
  A_hat[7] = 2.0 * (q_hat_in[1] * q_hat_in[2] + q_hat_in[0] * q_hat_in[3]);
  A_hat[2] = 2.0 * (q_hat_in[0] * q_hat_in[2] + q_hat_in[1] * q_hat_in[3]);
  A_hat[5] = 2.0 * (q_hat_in[1] * q_hat_in[2] - q_hat_in[0] * q_hat_in[3]);
  A_hat[8] = ((-rt_powd_snf(q_hat_in[0], 2.0) - rt_powd_snf(q_hat_in[1], 2.0)) +
              rt_powd_snf(q_hat_in[2], 2.0)) + rt_powd_snf(q_hat_in[3], 2.0);
  if (trackerAvail == 1.0) {
    /* && t(k)~=0 %If a star tracker measurement is available */
    for (i0 = 0; i0 < 3; i0++) {
      PSI[i0] = 0.0;
      for (br = 0; br < 3; br++) {
        PSI[i0] += A_hat[i0 + 3 * br] * rr_meas_in[br];
      }

      b_A_hat[i0] = 0.0;
      for (br = 0; br < 3; br++) {
        b_A_hat[i0] += A_hat[i0 + 3 * br] * B_in[br];
      }
    }

    cpm(PSI, I);
    cpm(b_A_hat, dv2);
    for (i0 = 0; i0 < 3; i0++) {
      for (br = 0; br < 3; br++) {
        C_data[br + 6 * i0] = dv2[br + 3 * i0];
      }
    }

    for (i0 = 0; i0 < 3; i0++) {
      for (br = 0; br < 3; br++) {
        C_data[br + 6 * (i0 + 3)] = 0.0;
      }
    }

    for (i0 = 0; i0 < 3; i0++) {
      for (br = 0; br < 3; br++) {
        C_data[(br + 6 * i0) + 3] = I[br + 3 * i0];
      }
    }

    for (i0 = 0; i0 < 3; i0++) {
      for (br = 0; br < 3; br++) {
        C_data[(br + 6 * (i0 + 3)) + 3] = 0.0;
      }
    }

    H_size_idx_0 = 6;
    for (i0 = 0; i0 < 6; i0++) {
      for (br = 0; br < 6; br++) {
        H_data[br + 6 * i0] = C_data[br + 6 * i0];
      }
    }
  } else {
    for (i0 = 0; i0 < 3; i0++) {
      PSI[i0] = 0.0;
      for (br = 0; br < 3; br++) {
        PSI[i0] += A_hat[i0 + 3 * br] * B_in[br];
      }
    }

    cpm(PSI, I);
    for (i0 = 0; i0 < 3; i0++) {
      for (br = 0; br < 3; br++) {
        b_I[br + 3 * i0] = I[br + 3 * i0];
      }
    }

    for (i0 = 0; i0 < 3; i0++) {
      for (br = 0; br < 3; br++) {
        b_I[br + 3 * (i0 + 3)] = 0.0;
      }
    }

    H_size_idx_0 = 3;
    for (i0 = 0; i0 < 6; i0++) {
      for (br = 0; br < 3; br++) {
        H_data[br + 3 * i0] = b_I[br + 3 * i0];
      }
    }
  }

  for (i0 = 0; i0 < 6; i0++) {
    c = H_size_idx_0 - 1;
    for (br = 0; br <= c; br++) {
      y_data[br + H_size_idx_0 * i0] = 0.0;
    }
  }

  c = H_size_idx_0 * 5;
  for (cr = 0; cr <= c; cr += H_size_idx_0) {
    i0 = cr + H_size_idx_0;
    for (ic = cr; ic + 1 <= i0; ic++) {
      y_data[ic] = 0.0;
    }
  }

  br = 0;
  for (cr = 0; cr <= c; cr += H_size_idx_0) {
    ar = 0;
    for (ib = br; ib + 1 <= br + 6; ib++) {
      if (P_in[ib] != 0.0) {
        ia = ar;
        i0 = cr + H_size_idx_0;
        for (ic = cr; ic + 1 <= i0; ic++) {
          ia++;
          y_data[ic] += P_in[ib] * H_data[ia - 1];
        }
      }

      ar += H_size_idx_0;
    }

    br += 6;
  }

  c = H_size_idx_0 - 1;
  for (i0 = 0; i0 <= c; i0++) {
    for (br = 0; br < 6; br++) {
      K_data[br + 6 * i0] = H_data[i0 + H_size_idx_0 * br];
    }
  }

  c = H_size_idx_0 - 1;
  for (i0 = 0; i0 <= c; i0++) {
    cr = H_size_idx_0 - 1;
    for (br = 0; br <= cr; br++) {
      b_C_data[br + H_size_idx_0 * i0] = 0.0;
    }
  }

  c = H_size_idx_0 * (H_size_idx_0 - 1);
  for (cr = 0; cr <= c; cr += H_size_idx_0) {
    i0 = cr + H_size_idx_0;
    for (ic = cr; ic + 1 <= i0; ic++) {
      b_C_data[ic] = 0.0;
    }
  }

  br = 0;
  for (cr = 0; cr <= c; cr += H_size_idx_0) {
    ar = 0;
    for (ib = br; ib + 1 <= br + 6; ib++) {
      if (K_data[ib] != 0.0) {
        ia = ar;
        i0 = cr + H_size_idx_0;
        for (ic = cr; ic + 1 <= i0; ic++) {
          ia++;
          b_C_data[ic] += K_data[ib] * y_data[ia - 1];
        }
      }

      ar += H_size_idx_0;
    }

    br += 6;
  }

  c = H_size_idx_0 - 1;
  for (i0 = 0; i0 <= c; i0++) {
    for (br = 0; br < 6; br++) {
      K_data[br + 6 * i0] = H_data[i0 + H_size_idx_0 * br];
    }
  }

  c = H_size_idx_0 - 1;
  for (i0 = 0; i0 <= c; i0++) {
    for (br = 0; br < 6; br++) {
      y_data[br + 6 * i0] = 0.0;
    }
  }

  c = 6 * (H_size_idx_0 - 1);
  for (cr = 0; cr <= c; cr += 6) {
    for (ic = cr; ic + 1 <= cr + 6; ic++) {
      y_data[ic] = 0.0;
    }
  }

  br = 0;
  for (cr = 0; cr <= c; cr += 6) {
    ar = 0;
    for (ib = br; ib + 1 <= br + 6; ib++) {
      if (K_data[ib] != 0.0) {
        ia = ar;
        for (ic = cr; ic + 1 <= cr + 6; ic++) {
          ia++;
          y_data[ic] += K_data[ib] * P_in[ia - 1];
        }
      }

      ar += 6;
    }

    br += 6;
  }

  C_size[0] = H_size_idx_0;
  C_size[1] = H_size_idx_0;
  c = H_size_idx_0 * H_size_idx_0 - 1;
  for (i0 = 0; i0 <= c; i0++) {
    C_data[i0] = b_C_data[i0] + R_data[i0];
  }

  mpower(C_data, C_size, R_data, R_size);
  c = (int8_T)R_size[1] - 1;
  for (i0 = 0; i0 <= c; i0++) {
    for (br = 0; br < 6; br++) {
      K_data[br + 6 * i0] = 0.0;
    }
  }

  c = 6 * (R_size[1] - 1);
  for (cr = 0; cr <= c; cr += 6) {
    for (ic = cr; ic + 1 <= cr + 6; ic++) {
      K_data[ic] = 0.0;
    }
  }

  br = 0;
  for (cr = 0; cr <= c; cr += 6) {
    ar = 0;
    i0 = br + H_size_idx_0;
    for (ib = br; ib + 1 <= i0; ib++) {
      if (R_data[ib] != 0.0) {
        ia = ar;
        for (ic = cr; ic + 1 <= cr + 6; ic++) {
          ia++;
          K_data[ic] += R_data[ib] * y_data[ia - 1];
        }
      }

      ar += 6;
    }

    br += H_size_idx_0;
  }

  /*  Update */
  memset(&F[0], 0, 36U * sizeof(real_T));
  for (c = 0; c < 6; c++) {
    F[c + 6 * c] = 1.0;
  }

  memset(&y[0], 0, 36U * sizeof(real_T));
  for (cr = 0; cr < 32; cr += 6) {
    for (ic = cr; ic + 1 <= cr + 6; ic++) {
      y[ic] = 0.0;
    }
  }

  br = 0;
  for (cr = 0; cr < 32; cr += 6) {
    ar = 0;
    i0 = br + (int8_T)R_size[1];
    for (ib = br; ib + 1 <= i0; ib++) {
      if (H_data[ib] != 0.0) {
        ia = ar;
        for (ic = cr; ic + 1 <= cr + 6; ic++) {
          ia++;
          y[ic] += H_data[ib] * K_data[ia - 1];
        }
      }

      ar += 6;
    }

    br += (int8_T)R_size[1];
  }

  for (i0 = 0; i0 < 6; i0++) {
    for (br = 0; br < 6; br++) {
      y_data[br + 6 * i0] = F[br + 6 * i0] - y[br + 6 * i0];
    }
  }

  for (i0 = 0; i0 < 6; i0++) {
    for (br = 0; br < 6; br++) {
      C_data[i0 + 6 * br] = 0.0;
      for (c = 0; c < 6; c++) {
        C_data[i0 + 6 * br] += y_data[i0 + 6 * c] * P_in[c + 6 * br];
      }
    }
  }

  for (i0 = 0; i0 < 6; i0++) {
    for (br = 0; br < 6; br++) {
      P_in[br + 6 * i0] = C_data[br + 6 * i0];
    }
  }

  if (trackerAvail == 1.0) {
    /* && t(k)~=0 %If a star tracker measurement is available */
    for (i0 = 0; i0 < 3; i0++) {
      PSI[i0] = 0.0;
      for (br = 0; br < 3; br++) {
        PSI[i0] += A_hat[i0 + 3 * br] * B_in[br];
      }

      b_A_hat[i0] = 0.0;
      for (br = 0; br < 3; br++) {
        b_A_hat[i0] += A_hat[i0 + 3 * br] * rr_meas_in[br];
      }

      dx[i0] = PSI[i0];
    }

    for (i0 = 0; i0 < 3; i0++) {
      dx[i0 + 3] = b_A_hat[i0];
    }

    for (i0 = 0; i0 < 6; i0++) {
      h_data[i0] = dx[i0];
    }

    /*  This function converts a quaternion to an attitude matrix. */
    /*  Andrew Dianetti */
    /*  5 December 2014 */
    dv2[0] = ((rt_powd_snf(q_meas_in[0], 2.0) - rt_powd_snf(q_meas_in[1], 2.0))
              - rt_powd_snf(q_meas_in[2], 2.0)) + rt_powd_snf(q_meas_in[3], 2.0);
    dv2[3] = 2.0 * (q_meas_in[0] * q_meas_in[1] + q_meas_in[2] * q_meas_in[3]);
    dv2[6] = 2.0 * (q_meas_in[0] * q_meas_in[2] - q_meas_in[1] * q_meas_in[3]);
    dv2[1] = 2.0 * (q_meas_in[0] * q_meas_in[1] - q_meas_in[2] * q_meas_in[3]);
    dv2[4] = ((-rt_powd_snf(q_meas_in[0], 2.0) + rt_powd_snf(q_meas_in[1], 2.0))
              - rt_powd_snf(q_meas_in[2], 2.0)) + rt_powd_snf(q_meas_in[3], 2.0);
    dv2[7] = 2.0 * (q_meas_in[1] * q_meas_in[2] + q_meas_in[0] * q_meas_in[3]);
    dv2[2] = 2.0 * (q_meas_in[0] * q_meas_in[2] + q_meas_in[1] * q_meas_in[3]);
    dv2[5] = 2.0 * (q_meas_in[1] * q_meas_in[2] - q_meas_in[0] * q_meas_in[3]);
    dv2[8] = ((-rt_powd_snf(q_meas_in[0], 2.0) - rt_powd_snf(q_meas_in[1], 2.0))
              + rt_powd_snf(q_meas_in[2], 2.0)) + rt_powd_snf(q_meas_in[3], 2.0);
    for (i0 = 0; i0 < 3; i0++) {
      PSI[i0] = 0.0;
      for (br = 0; br < 3; br++) {
        PSI[i0] += dv2[i0 + 3 * br] * rr_meas_in[br];
      }

      dx[i0] = B_meas_in[i0];
    }

    for (i0 = 0; i0 < 3; i0++) {
      dx[i0 + 3] = PSI[i0];
    }

    c = 6;
    for (i0 = 0; i0 < 6; i0++) {
      b_y_data[i0] = dx[i0];
    }

    /* Measurement */
  } else {
    c = 3;
    for (i0 = 0; i0 < 3; i0++) {
      PSI[i0] = 0.0;
      for (br = 0; br < 3; br++) {
        PSI[i0] += A_hat[i0 + 3 * br] * B_in[br];
      }

      h_data[i0] = PSI[i0];
      b_y_data[i0] = B_meas_in[i0];
    }

    /* Measurement */
  }

  c--;
  for (i0 = 0; i0 <= c; i0++) {
    b_y_data[i0] -= h_data[i0];
  }

  for (ic = 0; ic < 6; ic++) {
    dx[ic] = 0.0;
  }

  ar = 0;
  for (ib = 0; ib + 1 <= (int8_T)R_size[1]; ib++) {
    if (b_y_data[ib] != 0.0) {
      ia = ar;
      for (ic = 0; ic < 6; ic++) {
        ia++;
        dx[ic] += b_y_data[ib] * K_data[ia - 1];
      }
    }

    ar += 6;
  }

  /*  This function computes the Xi matrix for a quaternion. */
  /*  Andrew Dianetti */
  /*  5 December 2014 */
  /*  Required functions: */
  /*    cpm.m - Calculates cross product matrix */
  /*  Function cpm computes the standard cross-product matrix for a given */
  /*  3-vector. */
  dv2[0] = 0.0;
  dv2[3] = -q_hat_in[2];
  dv2[6] = q_hat_in[1];
  dv2[1] = q_hat_in[2];
  dv2[4] = 0.0;
  dv2[7] = -q_hat_in[0];
  dv2[2] = -q_hat_in[1];
  dv2[5] = q_hat_in[0];
  dv2[8] = 0.0;
  for (i0 = 0; i0 < 3; i0++) {
    for (br = 0; br < 3; br++) {
      b_q_hat_in[br + (i0 << 2)] = q_hat_in[3] * (real_T)b[br + 3 * i0] + dv2[br
        + 3 * i0];
    }

    b_q_hat_in[3 + (i0 << 2)] = -q_hat_in[i0];
    for (br = 0; br < 4; br++) {
      dv3[br + (i0 << 2)] = 0.5 * b_q_hat_in[br + (i0 << 2)];
    }
  }

  for (i0 = 0; i0 < 4; i0++) {
    b_y = 0.0;
    for (br = 0; br < 3; br++) {
      b_y += dv3[i0 + (br << 2)] * dx[br];
    }

    q_hat_in[i0] += b_y;
  }

  b_y = 0.0;
  scale = 2.2250738585072014E-308;
  for (c = 0; c < 4; c++) {
    absxk = fabs(q_hat_in[c]);
    if (absxk > scale) {
      t = scale / absxk;
      b_y = 1.0 + b_y * t * t;
      scale = absxk;
    } else {
      t = absxk / scale;
      b_y += t * t;
    }
  }

  b_y = scale * sqrt(b_y);
  for (i0 = 0; i0 < 4; i0++) {
    q_hat_in[i0] /= b_y;
  }

  /* Re-normalize q */
  for (i0 = 0; i0 < 3; i0++) {
    b_y = B_hat_in[i0] + dx[3 + i0];

    /*  Propagation */
    w_hat[i0] = w_meas_in[i0] - b_y;
    B_hat_in[i0] = b_y;
  }

  /*  Function cpm computes the standard cross-product matrix for a given */
  /*  3-vector. */
  memset(&I[0], 0, 9U * sizeof(real_T));
  dv2[0] = 0.0;
  dv2[3] = -w_hat[2];
  dv2[6] = w_hat[1];
  dv2[1] = w_hat[2];
  dv2[4] = 0.0;
  dv2[7] = -w_hat[0];
  dv2[2] = -w_hat[1];
  dv2[5] = w_hat[0];
  dv2[8] = 0.0;
  for (c = 0; c < 3; c++) {
    I[c + 3 * c] = 1.0;
    for (i0 = 0; i0 < 3; i0++) {
      F[i0 + 6 * c] = -dv2[i0 + 3 * c];
    }
  }

  for (i0 = 0; i0 < 3; i0++) {
    for (br = 0; br < 3; br++) {
      F[br + 6 * (i0 + 3)] = -I[br + 3 * i0];
    }
  }

  for (i0 = 0; i0 < 6; i0++) {
    for (br = 0; br < 3; br++) {
      F[(br + 6 * i0) + 3] = 0.0;
    }
  }

  /*  Next time step: */
  /*      q_hat_out=q_hat_in+dt*q_dot; */
  b_y = sin(0.5 * b_norm(w_hat) * 0.1);
  scale = b_norm(w_hat);
  for (c = 0; c < 3; c++) {
    PSI[c] = b_y * w_hat[c] / scale;
  }

  b_y = cos(0.5 * b_norm(w_hat) * 0.1);

  /*  Function cpm computes the standard cross-product matrix for a given */
  /*  3-vector. */
  /* cpm returns cross product matrix */
  dv2[0] = 0.0;
  dv2[3] = -PSI[2];
  dv2[6] = PSI[1];
  dv2[1] = PSI[2];
  dv2[4] = 0.0;
  dv2[7] = -PSI[0];
  dv2[2] = -PSI[1];
  dv2[5] = PSI[0];
  dv2[8] = 0.0;
  for (i0 = 0; i0 < 3; i0++) {
    for (br = 0; br < 3; br++) {
      x[br + (i0 << 2)] = b_y * (real_T)b[br + 3 * i0] - dv2[br + 3 * i0];
    }
  }

  for (i0 = 0; i0 < 3; i0++) {
    x[12 + i0] = PSI[i0];
  }

  for (i0 = 0; i0 < 3; i0++) {
    x[3 + (i0 << 2)] = -PSI[i0];
  }

  x[15] = cos(0.5 * b_norm(w_hat) * 0.1);
  for (i0 = 0; i0 < 4; i0++) {
    q_hat_out[i0] = 0.0;
    for (br = 0; br < 4; br++) {
      q_hat_out[i0] += x[i0 + (br << 2)] * q_hat_in[br];
    }
  }

  for (i0 = 0; i0 < 6; i0++) {
    for (br = 0; br < 6; br++) {
      y_data[i0 + 6 * br] = 0.0;
      for (c = 0; c < 6; c++) {
        y_data[i0 + 6 * br] += F[i0 + 6 * c] * P_in[c + 6 * br];
      }

      C_data[i0 + 6 * br] = 0.0;
      for (c = 0; c < 6; c++) {
        C_data[i0 + 6 * br] += P_in[i0 + 6 * c] * F[br + 6 * c];
      }
    }
  }

  for (i0 = 0; i0 < 6; i0++) {
    for (br = 0; br < 6; br++) {
      P_out[br + 6 * i0] = P_in[br + 6 * i0] + 0.1 * ((y_data[br + 6 * i0] +
        C_data[br + 6 * i0]) + c_y[br + 6 * i0]);
    }
  }

  for (c = 0; c < 3; c++) {
    B_hat_out[c] = B_hat_in[c];
  }

  /* 3-sigma bounds */
  for (c = 0; c < 6; c++) {
    /* UNTITLED2 Summary of this function goes here */
    /*    Detailed explanation goes here */
    sig3_out[c] = rt_powd_snf(P_out[7 * c], 0.5) * 3.0 * 57.295779513082323;
  }

  /* Estimated Euler angles for each time step: */
  *theta_hat = 57.295779513082323 * acos(A_hat[8]);

  /* degrees */
  b_y = *theta_hat;
  sind(&b_y);
  *psi_hat = 57.295779513082323 * acos(A_hat[5] / b_y);

  /* degrees */
  b_y = *theta_hat;
  sind(&b_y);
  *phi_hat = 57.295779513082323 * acos(A_hat[7] / -b_y);

  /* degrees */
}

/* End of code generation (kalmanStepRedux.c) */
