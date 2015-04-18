/*
 * inv.c
 *
 * Code generation for function 'inv'
 *
 * C source code generated on: Thu Jan 29 17:46:45 2015
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "kalmanStepRedux.h"
#include "inv.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */

/* Function Definitions */
void invNxN(const real_T x_data[36], const int32_T x_size[2], real_T y_data[36],
            int32_T y_size[2])
{
  int32_T i2;
  int32_T yk;
  int32_T i;
  int32_T jj;
  real_T A_data[36];
  int32_T n;
  int32_T ipiv_data[6];
  int32_T jA;
  int32_T ldap1;
  int32_T u1;
  int32_T j;
  int32_T mmj;
  int32_T jp1j;
  int32_T c;
  int32_T ix;
  real_T smax;
  real_T s;
  int32_T p_data[6];
  for (i2 = 0; i2 < 2; i2++) {
    y_size[i2] = x_size[i2];
  }

  yk = y_size[1] - 1;
  for (i2 = 0; i2 <= yk; i2++) {
    i = y_size[0] - 1;
    for (jj = 0; jj <= i; jj++) {
      y_data[jj + y_size[0] * i2] = 0.0;
    }
  }

  yk = x_size[0] * x_size[1] - 1;
  for (i2 = 0; i2 <= yk; i2++) {
    A_data[i2] = x_data[i2];
  }

  yk = x_size[0];
  n = x_size[0];
  if (yk <= n) {
    n = yk;
  }

  ipiv_data[0] = 1;
  yk = 1;
  for (jA = 2; jA <= n; jA++) {
    yk++;
    ipiv_data[jA - 1] = yk;
  }

  ldap1 = x_size[0] + 1;
  yk = x_size[0] - 1;
  u1 = x_size[0];
  if (yk <= u1) {
    u1 = yk;
  }

  for (j = 1; j <= u1; j++) {
    mmj = x_size[0] - j;
    jj = (j - 1) * ldap1;
    jp1j = jj + 2;
    c = mmj + 1;
    if (c < 1) {
      yk = 0;
    } else {
      yk = 1;
      if (c > 1) {
        ix = jj;
        smax = fabs(A_data[jj]);
        for (jA = 2; jA <= c; jA++) {
          ix++;
          s = fabs(A_data[ix]);
          if (s > smax) {
            yk = jA;
            smax = s;
          }
        }
      }
    }

    if (A_data[(jj + yk) - 1] != 0.0) {
      if (yk - 1 != 0) {
        ipiv_data[j - 1] = (j + yk) - 1;
        ix = j - 1;
        yk = (j + yk) - 2;
        for (jA = 1; jA <= x_size[0]; jA++) {
          smax = A_data[ix];
          A_data[ix] = A_data[yk];
          A_data[yk] = smax;
          ix += x_size[0];
          yk += x_size[0];
        }
      }

      i2 = (jp1j + mmj) - 1;
      for (i = jp1j; i <= i2; i++) {
        A_data[i - 1] /= A_data[jj];
      }
    }

    c = x_size[0] - j;
    jA = jj + ldap1;
    yk = jj + x_size[0];
    for (jj = 1; jj <= c; jj++) {
      smax = A_data[yk];
      if (A_data[yk] != 0.0) {
        ix = jp1j;
        i2 = mmj + jA;
        for (i = jA; i + 1 <= i2; i++) {
          A_data[i] += A_data[ix - 1] * -smax;
          ix++;
        }
      }

      yk += x_size[0];
      jA += x_size[0];
    }
  }

  p_data[0] = 1;
  yk = 1;
  for (jA = 2; jA <= x_size[0]; jA++) {
    yk++;
    p_data[jA - 1] = yk;
  }

  for (jA = 0; jA <= n - 1; jA++) {
    if (ipiv_data[jA] > 1 + jA) {
      yk = p_data[ipiv_data[jA] - 1];
      p_data[ipiv_data[jA] - 1] = p_data[jA];
      p_data[jA] = yk;
    }
  }

  for (jA = 0; jA + 1 <= x_size[0]; jA++) {
    y_data[jA + y_size[0] * (p_data[jA] - 1)] = 1.0;
    for (j = jA; j + 1 <= x_size[0]; j++) {
      if (y_data[j + y_size[0] * (p_data[jA] - 1)] != 0.0) {
        for (i = j + 1; i + 1 <= x_size[0]; i++) {
          y_data[i + y_size[0] * (p_data[jA] - 1)] -= y_data[j + y_size[0] *
            (p_data[jA] - 1)] * A_data[i + x_size[0] * j];
        }
      }
    }
  }

  for (j = 1; j <= x_size[0]; j++) {
    c = x_size[0] * (j - 1);
    for (jA = x_size[0] - 1; jA + 1 > 0; jA--) {
      yk = x_size[0] * jA;
      if (y_data[jA + c] != 0.0) {
        y_data[jA + c] /= A_data[jA + yk];
        for (i = 1; i <= jA; i++) {
          y_data[(i + c) - 1] -= y_data[jA + c] * A_data[(i + yk) - 1];
        }
      }
    }
  }
}

/* End of code generation (inv.c) */
