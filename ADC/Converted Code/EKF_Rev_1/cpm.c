/*
 * cpm.c
 *
 * Code generation for function 'cpm'
 *
 * C source code generated on: Thu Jan 29 17:46:45 2015
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "kalmanStepRedux.h"
#include "cpm.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */

/* Function Definitions */
void cpm(const real_T invec[3], real_T outmat[9])
{
  /*  Function cpm computes the standard cross-product matrix for a given */
  /*  3-vector. */
  outmat[0] = 0.0;
  outmat[3] = -invec[2];
  outmat[6] = invec[1];
  outmat[1] = invec[2];
  outmat[4] = 0.0;
  outmat[7] = -invec[0];
  outmat[2] = -invec[1];
  outmat[5] = invec[0];
  outmat[8] = 0.0;
}

/* End of code generation (cpm.c) */
