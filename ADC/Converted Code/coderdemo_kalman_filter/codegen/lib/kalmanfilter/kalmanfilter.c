/*
 * kalmanfilter.c
 *
 * Code generation for function 'kalmanfilter'
 *
 * C source code generated on: Sat Oct 18 14:35:15 2014
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "kalmanfilter.h"
#include "kalmanfilter_data.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */

/* Function Definitions */
void kalmanfilter(const real_T z[2], real_T y[2])
{
  int8_T Q[36];
  int32_T r2;
  real_T a[36];
  int32_T r1;
  real_T x_prd[6];
  static const int8_T b_a[36] = { 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 1, 0,
    0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0, 1 };

  int32_T k;
  real_T p_prd[36];
  real_T a21;
  static const int8_T b[36] = { 1, 0, 1, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0,
    1, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 1 };

  real_T klm_gain[12];
  static const int8_T c_a[12] = { 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0 };

  real_T S[4];
  static const int8_T b_b[12] = { 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0 };

  static const int16_T R[4] = { 1000, 0, 0, 1000 };

  real_T B[12];
  real_T a22;
  real_T Y[12];
  real_T b_z[2];

  /*    Copyright 2010 The MathWorks, Inc. */
  /*  Initialize state transition matrix */
  /*      % [x  ] */
  /*      % [y  ] */
  /*      % [Vx] */
  /*      % [Vy] */
  /*      % [Ax] */
  /*  [Ay] */
  /*  Initialize measurement matrix */
  for (r2 = 0; r2 < 36; r2++) {
    Q[r2] = 0;
  }

  for (r1 = 0; r1 < 6; r1++) {
    Q[r1 + 6 * r1] = 1;

    /*  Initial state conditions */
    /*  Predicted state and covariance */
    x_prd[r1] = 0.0;
    for (r2 = 0; r2 < 6; r2++) {
      x_prd[r1] += (real_T)b_a[r1 + 6 * r2] * x_est[r2];
    }

    for (r2 = 0; r2 < 6; r2++) {
      a[r1 + 6 * r2] = 0.0;
      for (k = 0; k < 6; k++) {
        a[r1 + 6 * r2] += (real_T)b_a[r1 + 6 * k] * p_est[k + 6 * r2];
      }
    }
  }

  for (r2 = 0; r2 < 6; r2++) {
    for (k = 0; k < 6; k++) {
      a21 = 0.0;
      for (r1 = 0; r1 < 6; r1++) {
        a21 += a[r2 + 6 * r1] * (real_T)b[r1 + 6 * k];
      }

      p_prd[r2 + 6 * k] = a21 + (real_T)Q[r2 + 6 * k];
    }
  }

  /*  Estimation */
  for (r2 = 0; r2 < 2; r2++) {
    for (k = 0; k < 6; k++) {
      klm_gain[r2 + (k << 1)] = 0.0;
      for (r1 = 0; r1 < 6; r1++) {
        klm_gain[r2 + (k << 1)] += (real_T)c_a[r2 + (r1 << 1)] * p_prd[k + 6 *
          r1];
      }
    }
  }

  for (r2 = 0; r2 < 2; r2++) {
    for (k = 0; k < 2; k++) {
      a21 = 0.0;
      for (r1 = 0; r1 < 6; r1++) {
        a21 += klm_gain[r2 + (r1 << 1)] * (real_T)b_b[r1 + 6 * k];
      }

      S[r2 + (k << 1)] = a21 + (real_T)R[r2 + (k << 1)];
    }
  }

  for (r2 = 0; r2 < 2; r2++) {
    for (k = 0; k < 6; k++) {
      B[r2 + (k << 1)] = 0.0;
      for (r1 = 0; r1 < 6; r1++) {
        B[r2 + (k << 1)] += (real_T)c_a[r2 + (r1 << 1)] * p_prd[k + 6 * r1];
      }
    }
  }

  if (fabs(S[1]) > fabs(S[0])) {
    r1 = 1;
    r2 = 0;
  } else {
    r1 = 0;
    r2 = 1;
  }

  a21 = S[r2] / S[r1];
  a22 = S[2 + r2] - a21 * S[2 + r1];
  for (k = 0; k < 6; k++) {
    Y[1 + (k << 1)] = (B[r2 + (k << 1)] - B[r1 + (k << 1)] * a21) / a22;
    Y[k << 1] = (B[r1 + (k << 1)] - Y[1 + (k << 1)] * S[2 + r1]) / S[r1];
  }

  for (r2 = 0; r2 < 2; r2++) {
    for (k = 0; k < 6; k++) {
      klm_gain[k + 6 * r2] = Y[r2 + (k << 1)];
    }
  }

  /*  Estimated state and covariance */
  for (r2 = 0; r2 < 2; r2++) {
    a21 = 0.0;
    for (k = 0; k < 6; k++) {
      a21 += (real_T)c_a[r2 + (k << 1)] * x_prd[k];
    }

    b_z[r2] = z[r2] - a21;
  }

  for (r2 = 0; r2 < 6; r2++) {
    a21 = 0.0;
    for (k = 0; k < 2; k++) {
      a21 += klm_gain[r2 + 6 * k] * b_z[k];
    }

    x_est[r2] = x_prd[r2] + a21;
  }

  for (r2 = 0; r2 < 6; r2++) {
    for (k = 0; k < 6; k++) {
      a[r2 + 6 * k] = 0.0;
      for (r1 = 0; r1 < 2; r1++) {
        a[r2 + 6 * k] += klm_gain[r2 + 6 * r1] * (real_T)c_a[r1 + (k << 1)];
      }
    }
  }

  for (r2 = 0; r2 < 6; r2++) {
    for (k = 0; k < 6; k++) {
      a21 = 0.0;
      for (r1 = 0; r1 < 6; r1++) {
        a21 += a[r2 + 6 * r1] * p_prd[r1 + 6 * k];
      }

      p_est[r2 + 6 * k] = p_prd[r2 + 6 * k] - a21;
    }
  }

  /*  Compute the estimated measurements */
  for (r2 = 0; r2 < 2; r2++) {
    y[r2] = 0.0;
    for (k = 0; k < 6; k++) {
      y[r2] += (real_T)c_a[r2 + (k << 1)] * x_est[k];
    }
  }

  /*  of the function */
}

/* End of code generation (kalmanfilter.c) */
