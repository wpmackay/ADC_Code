/*
 * Control_Block.c
 *
 * Code generation for function 'Control_Block'
 *
 * C source code generated on: Sat Jan 31 16:54:30 2015
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "Control_Block.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */

/* Function Definitions */
void Control_Block(const real_T omega[3], const real_T omega_des[3], const
                   real_T q[4], const real_T q_des[4], real_T T[3])
{
  real_T b_q_des[12];
  int32_T i0;
  real_T d0;
  int32_T i1;

  /* This is a function that emulates the Controller Block of the simulink */
  /* pointing controller. */
  b_q_des[0] = q_des[3];
  b_q_des[1] = -q_des[2];
  b_q_des[2] = q_des[1];
  b_q_des[3] = q_des[2];
  b_q_des[4] = q_des[3];
  b_q_des[5] = -q_des[0];
  b_q_des[6] = -q_des[1];
  b_q_des[7] = q_des[0];
  b_q_des[8] = q_des[3];
  b_q_des[9] = -q_des[0];
  b_q_des[10] = -q_des[1];
  b_q_des[11] = -q_des[2];
  for (i0 = 0; i0 < 3; i0++) {
    d0 = 0.0;
    for (i1 = 0; i1 < 4; i1++) {
      d0 += b_q_des[i0 + 3 * i1] * q[i1];
    }

    T[i0] = -(omega[i0] - omega_des[i0]) + -d0;
  }
}

/* End of code generation (Control_Block.c) */
