/*
 * mpower.c
 *
 * Code generation for function 'mpower'
 *
 * C source code generated on: Thu Jan 29 17:46:45 2015
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "kalmanStepRedux.h"
#include "mpower.h"
#include "norm.h"
#include "inv.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */

/* Function Definitions */
void mpower(const real_T a_data[36], const int32_T a_size[2], real_T c_data[36],
            int32_T c_size[2])
{
  int8_T c[2];
  int32_T a_idx_0;
  real_T b_a_data[36];
  int32_T loop_ub;
  int32_T b_loop_ub;
  int32_T i1;
  int32_T x_size[2];
  real_T x_data[36];
  int32_T b_c_size[2];
  for (a_idx_0 = 0; a_idx_0 < 2; a_idx_0++) {
    c[a_idx_0] = (int8_T)a_size[a_idx_0];
  }

  c_size[0] = c[0];
  c_size[1] = c[1];
  a_idx_0 = a_size[0] * a_size[1];
  loop_ub = a_idx_0 - 1;
  for (a_idx_0 = 0; a_idx_0 <= loop_ub; a_idx_0++) {
    b_a_data[a_idx_0] = a_data[a_idx_0];
  }

  for (a_idx_0 = 0; a_idx_0 < 2; a_idx_0++) {
    c[a_idx_0] = (int8_T)c_size[a_idx_0];
  }

  c_size[0] = c[0];
  c_size[1] = c[1];
  loop_ub = c[1] - 1;
  for (a_idx_0 = 0; a_idx_0 <= loop_ub; a_idx_0++) {
    b_loop_ub = c[0] - 1;
    for (i1 = 0; i1 <= b_loop_ub; i1++) {
      c_data[i1 + c_size[0] * a_idx_0] = b_a_data[i1 + c[0] * a_idx_0];
    }
  }

  x_size[0] = c_size[0];
  x_size[1] = c_size[1];
  loop_ub = c_size[0] * c_size[1] - 1;
  for (a_idx_0 = 0; a_idx_0 <= loop_ub; a_idx_0++) {
    x_data[a_idx_0] = c_data[a_idx_0];
  }

  b_c_size[0] = c_size[0];
  b_c_size[1] = c_size[1];
  loop_ub = c_size[0] * c_size[1] - 1;
  for (a_idx_0 = 0; a_idx_0 <= loop_ub; a_idx_0++) {
    b_a_data[a_idx_0] = c_data[a_idx_0];
  }

  invNxN(b_a_data, b_c_size, c_data, c_size);
  norm(x_data, x_size);
  norm(c_data, c_size);
}

/* End of code generation (mpower.c) */
