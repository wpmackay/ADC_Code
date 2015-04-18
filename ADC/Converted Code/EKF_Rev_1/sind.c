/*
 * sind.c
 *
 * Code generation for function 'sind'
 *
 * C source code generated on: Thu Jan 29 17:46:45 2015
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "kalmanStepRedux.h"
#include "sind.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
static real_T rt_remd_snf(real_T u0, real_T u1);
static real_T rt_roundd_snf(real_T u);

/* Function Definitions */
static real_T rt_remd_snf(real_T u0, real_T u1)
{
  real_T y;
  boolean_T b_y;
  boolean_T c_y;
  real_T tr;
  if (u1 < 0.0) {
    y = ceil(u1);
  } else {
    y = floor(u1);
  }

  b_y = ((!rtIsNaN(u0)) && (!rtIsInf(u0)));
  c_y = ((!rtIsNaN(u1)) && (!rtIsInf(u1)));
  if ((u1 != 0.0) && (u1 != y) && (b_y && c_y)) {
    tr = u0 / u1;
    if (fabs(tr - rt_roundd_snf(tr)) <= DBL_EPSILON * fabs(tr)) {
      y = 0.0;
    } else {
      y = fmod(u0, u1);
    }
  } else {
    y = fmod(u0, u1);
  }

  return y;
}

static real_T rt_roundd_snf(real_T u)
{
  real_T y;
  if (fabs(u) < 4.503599627370496E+15) {
    if (u >= 0.5) {
      y = floor(u + 0.5);
    } else if (u > -0.5) {
      y = -0.0;
    } else {
      y = ceil(u - 0.5);
    }
  } else {
    y = u;
  }

  return y;
}

void sind(real_T *x)
{
  real_T b_x;
  real_T ix;
  int32_T n;
  if (!((!rtIsInf(*x)) && (!rtIsNaN(*x)))) {
    *x = rtNaN;
  } else {
    b_x = rt_remd_snf(*x, 360.0);
    ix = fabs(b_x);
    if (ix > 180.0) {
      if (b_x > 0.0) {
        b_x -= 360.0;
      } else {
        b_x += 360.0;
      }

      ix = fabs(b_x);
    }

    if (ix <= 45.0) {
      b_x *= 0.017453292519943295;
      n = 0;
    } else if (ix <= 135.0) {
      if (b_x > 0.0) {
        b_x = 0.017453292519943295 * (b_x - 90.0);
        n = 1;
      } else {
        b_x = 0.017453292519943295 * (b_x + 90.0);
        n = -1;
      }
    } else if (b_x > 0.0) {
      b_x = 0.017453292519943295 * (b_x - 180.0);
      n = 2;
    } else {
      b_x = 0.017453292519943295 * (b_x + 180.0);
      n = -2;
    }

    if (n == 0) {
      *x = sin(b_x);
    } else if (n == 1) {
      *x = cos(b_x);
    } else if (n == -1) {
      *x = -cos(b_x);
    } else {
      *x = -sin(b_x);
    }
  }
}

/* End of code generation (sind.c) */
