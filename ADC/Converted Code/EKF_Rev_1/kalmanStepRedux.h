/*
 * kalmanStepRedux.h
 *
 * Code generation for function 'kalmanStepRedux'
 *
 * C source code generated on: Thu Jan 29 17:46:45 2015
 *
 */

#ifndef __KALMANSTEPREDUX_H__
#define __KALMANSTEPREDUX_H__
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
extern void kalmanStepRedux(const real_T B_in[3], const real_T B_meas_in[3], const real_T rr_meas_in[3], const real_T q_meas_in[4], real_T trackerAvail, const real_T w_meas_in[3], real_T q_hat_in[4], real_T P_in[36], real_T B_hat_in[3], real_T q_hat_out[4], real_T w_hat[3], real_T *theta_hat, real_T *psi_hat, real_T *phi_hat, real_T sig3_out[6], real_T B_hat_out[3], real_T P_out[36]);
#endif
/* End of code generation (kalmanStepRedux.h) */
