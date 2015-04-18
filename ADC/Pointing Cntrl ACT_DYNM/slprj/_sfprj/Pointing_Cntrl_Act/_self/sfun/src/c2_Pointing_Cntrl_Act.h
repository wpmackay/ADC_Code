#ifndef __c2_Pointing_Cntrl_Act_h__
#define __c2_Pointing_Cntrl_Act_h__

/* Include files */
#include "sfc_sf.h"
#include "sfc_mex.h"
#include "rtwtypes.h"

/* Type Definitions */
#ifndef typedef_SFc2_Pointing_Cntrl_ActInstanceStruct
#define typedef_SFc2_Pointing_Cntrl_ActInstanceStruct

typedef struct {
  SimStruct *S;
  ChartInfoStruct chartInfo;
  uint32_T chartNumber;
  uint32_T instanceNumber;
  int32_T c2_sfEvent;
  boolean_T c2_isStable;
  boolean_T c2_doneDoubleBufferReInit;
  uint8_T c2_is_active_c2_Pointing_Cntrl_Act;
} SFc2_Pointing_Cntrl_ActInstanceStruct;

#endif                                 /*typedef_SFc2_Pointing_Cntrl_ActInstanceStruct*/

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */
extern const mxArray *sf_c2_Pointing_Cntrl_Act_get_eml_resolved_functions_info
  (void);

/* Function Definitions */
extern void sf_c2_Pointing_Cntrl_Act_get_check_sum(mxArray *plhs[]);
extern void c2_Pointing_Cntrl_Act_method_dispatcher(SimStruct *S, int_T method,
  void *data);

#endif
