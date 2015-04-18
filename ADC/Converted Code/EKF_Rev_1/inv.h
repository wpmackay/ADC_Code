/*
 * inv.h
 *
 * Code generation for function 'inv'
 *
 * C source code generated on: Thu Jan 29 17:46:45 2015
 *
 */

#ifndef __INV_H__
#define __INV_H__
/* Include files */
#include <float.h>
#include <math.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rt_nonfinite.h"

#include "rtwtypes.h"
#include "kalmanStepRedux_types.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern void invNxN(const real_T x_data[36], const int32_T x_size[2], real_T y_data[36], int32_T y_size[2]);
#endif
/* End of code generation (inv.h) */
