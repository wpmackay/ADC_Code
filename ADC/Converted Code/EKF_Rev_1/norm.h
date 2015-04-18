/*
 * norm.h
 *
 * Code generation for function 'norm'
 *
 * C source code generated on: Thu Jan 29 17:46:45 2015
 *
 */

#ifndef __NORM_H__
#define __NORM_H__
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
extern real_T b_norm(const real_T x[3]);
extern real_T norm(const real_T x_data[36], const int32_T x_size[2]);
#endif
/* End of code generation (norm.h) */
