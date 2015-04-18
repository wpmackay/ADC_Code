/*
 * norm.c
 *
 * Code generation for function 'norm'
 *
 * C source code generated on: Thu Jan 29 17:46:45 2015
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "kalmanStepRedux.h"
#include "norm.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */

/* Function Definitions */
real_T b_norm(const real_T x[3])
{
  real_T y;
  real_T scale;
  int32_T k;
  real_T absxk;
  real_T t;
  y = 0.0;
  scale = 2.2250738585072014E-308;
  for (k = 0; k < 3; k++) {
    absxk = fabs(x[k]);
    if (absxk > scale) {
      t = scale / absxk;
      y = 1.0 + y * t * t;
      scale = absxk;
    } else {
      t = absxk / scale;
      y += t * t;
    }
  }

  return scale * sqrt(y);
}

real_T norm(const real_T x_data[36], const int32_T x_size[2])
{
  real_T y;
  int32_T j;
  boolean_T exitg1;
  real_T s;
  int32_T i;
  y = 0.0;
  j = 0;
  exitg1 = FALSE;
  while ((exitg1 == 0U) && (j <= x_size[1] - 1)) {
    s = 0.0;
    for (i = 0; i <= x_size[0] - 1; i++) {
      s += fabs(x_data[i + x_size[0] * j]);
    }

    if (rtIsNaN(s)) {
      y = rtNaN;
      exitg1 = TRUE;
    } else {
      if (s > y) {
        y = s;
      }

      j++;
    }
  }

  return y;
}

/* End of code generation (norm.c) */
