/*
 * averaging_filter_initialize.c
 *
 * Code generation for function 'averaging_filter_initialize'
 *
 * C source code generated on: Sat Oct 25 14:16:56 2014
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "averaging_filter.h"
#include "averaging_filter_initialize.h"
#include "averaging_filter_data.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */

/* Function Definitions */
void averaging_filter_initialize(void)
{
  rt_InitInfAndNaN(8U);
  memset(&buffer[0], 0, sizeof(real_T) << 4);
}

/* End of code generation (averaging_filter_initialize.c) */
