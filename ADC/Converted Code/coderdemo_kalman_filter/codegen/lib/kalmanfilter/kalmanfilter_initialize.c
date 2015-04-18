/*
 * kalmanfilter_initialize.c
 *
 * Code generation for function 'kalmanfilter_initialize'
 *
 * C source code generated on: Sat Oct 18 14:35:15 2014
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "kalmanfilter.h"
#include "kalmanfilter_initialize.h"
#include "kalmanfilter_data.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */

/* Function Definitions */
void kalmanfilter_initialize(void)
{
  int32_T i;
  rt_InitInfAndNaN(8U);
  for (i = 0; i < 6; i++) {
    x_est[i] = 0.0;
  }

  memset(&p_est[0], 0, 36U * sizeof(real_T));
}

/* End of code generation (kalmanfilter_initialize.c) */
