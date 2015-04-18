/* Include files */

#include <stddef.h>
#include "blas.h"
#include "Pointing_Cntrl_Act_sfun.h"
#include "c10_Pointing_Cntrl_Act.h"
#include "mwmathutil.h"
#define CHARTINSTANCE_CHARTNUMBER      (chartInstance->chartNumber)
#define CHARTINSTANCE_INSTANCENUMBER   (chartInstance->instanceNumber)
#include "Pointing_Cntrl_Act_sfun_debug_macros.h"
#define _SF_MEX_LISTEN_FOR_CTRL_C(S)   sf_mex_listen_for_ctrl_c(sfGlobalDebugInstanceStruct,S);

/* Type Definitions */

/* Named Constants */
#define CALL_EVENT                     (-1)

/* Variable Declarations */

/* Variable Definitions */
static const char * c10_debug_family_names[16] = { "s1", "s2", "s3", "c1", "c2",
  "c3", "A", "nargin", "nargout", "phi_des", "theta_des", "psi_des", "q1_des",
  "q2_des", "q3_des", "q4_des" };

/* Function Declarations */
static void initialize_c10_Pointing_Cntrl_Act
  (SFc10_Pointing_Cntrl_ActInstanceStruct *chartInstance);
static void initialize_params_c10_Pointing_Cntrl_Act
  (SFc10_Pointing_Cntrl_ActInstanceStruct *chartInstance);
static void enable_c10_Pointing_Cntrl_Act(SFc10_Pointing_Cntrl_ActInstanceStruct
  *chartInstance);
static void disable_c10_Pointing_Cntrl_Act
  (SFc10_Pointing_Cntrl_ActInstanceStruct *chartInstance);
static void c10_update_debugger_state_c10_Pointing_Cntrl_Act
  (SFc10_Pointing_Cntrl_ActInstanceStruct *chartInstance);
static const mxArray *get_sim_state_c10_Pointing_Cntrl_Act
  (SFc10_Pointing_Cntrl_ActInstanceStruct *chartInstance);
static void set_sim_state_c10_Pointing_Cntrl_Act
  (SFc10_Pointing_Cntrl_ActInstanceStruct *chartInstance, const mxArray *c10_st);
static void finalize_c10_Pointing_Cntrl_Act
  (SFc10_Pointing_Cntrl_ActInstanceStruct *chartInstance);
static void sf_c10_Pointing_Cntrl_Act(SFc10_Pointing_Cntrl_ActInstanceStruct
  *chartInstance);
static void initSimStructsc10_Pointing_Cntrl_Act
  (SFc10_Pointing_Cntrl_ActInstanceStruct *chartInstance);
static void registerMessagesc10_Pointing_Cntrl_Act
  (SFc10_Pointing_Cntrl_ActInstanceStruct *chartInstance);
static void init_script_number_translation(uint32_T c10_machineNumber, uint32_T
  c10_chartNumber);
static const mxArray *c10_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData);
static real_T c10_emlrt_marshallIn(SFc10_Pointing_Cntrl_ActInstanceStruct
  *chartInstance, const mxArray *c10_q4_des, const char_T *c10_identifier);
static real_T c10_b_emlrt_marshallIn(SFc10_Pointing_Cntrl_ActInstanceStruct
  *chartInstance, const mxArray *c10_u, const emlrtMsgIdentifier *c10_parentId);
static void c10_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c10_mxArrayInData, const char_T *c10_varName, void *c10_outData);
static const mxArray *c10_b_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData);
static void c10_c_emlrt_marshallIn(SFc10_Pointing_Cntrl_ActInstanceStruct
  *chartInstance, const mxArray *c10_u, const emlrtMsgIdentifier *c10_parentId,
  real_T c10_y[9]);
static void c10_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c10_mxArrayInData, const char_T *c10_varName, void *c10_outData);
static void c10_eml_error(SFc10_Pointing_Cntrl_ActInstanceStruct *chartInstance);
static const mxArray *c10_c_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData);
static int32_T c10_d_emlrt_marshallIn(SFc10_Pointing_Cntrl_ActInstanceStruct
  *chartInstance, const mxArray *c10_u, const emlrtMsgIdentifier *c10_parentId);
static void c10_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c10_mxArrayInData, const char_T *c10_varName, void *c10_outData);
static uint8_T c10_e_emlrt_marshallIn(SFc10_Pointing_Cntrl_ActInstanceStruct
  *chartInstance, const mxArray *c10_b_is_active_c10_Pointing_Cntrl_Act, const
  char_T *c10_identifier);
static uint8_T c10_f_emlrt_marshallIn(SFc10_Pointing_Cntrl_ActInstanceStruct
  *chartInstance, const mxArray *c10_u, const emlrtMsgIdentifier *c10_parentId);
static void init_dsm_address_info(SFc10_Pointing_Cntrl_ActInstanceStruct
  *chartInstance);

/* Function Definitions */
static void initialize_c10_Pointing_Cntrl_Act
  (SFc10_Pointing_Cntrl_ActInstanceStruct *chartInstance)
{
  chartInstance->c10_sfEvent = CALL_EVENT;
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  chartInstance->c10_is_active_c10_Pointing_Cntrl_Act = 0U;
}

static void initialize_params_c10_Pointing_Cntrl_Act
  (SFc10_Pointing_Cntrl_ActInstanceStruct *chartInstance)
{
}

static void enable_c10_Pointing_Cntrl_Act(SFc10_Pointing_Cntrl_ActInstanceStruct
  *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void disable_c10_Pointing_Cntrl_Act
  (SFc10_Pointing_Cntrl_ActInstanceStruct *chartInstance)
{
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
}

static void c10_update_debugger_state_c10_Pointing_Cntrl_Act
  (SFc10_Pointing_Cntrl_ActInstanceStruct *chartInstance)
{
}

static const mxArray *get_sim_state_c10_Pointing_Cntrl_Act
  (SFc10_Pointing_Cntrl_ActInstanceStruct *chartInstance)
{
  const mxArray *c10_st;
  const mxArray *c10_y = NULL;
  real_T c10_hoistedGlobal;
  real_T c10_u;
  const mxArray *c10_b_y = NULL;
  real_T c10_b_hoistedGlobal;
  real_T c10_b_u;
  const mxArray *c10_c_y = NULL;
  real_T c10_c_hoistedGlobal;
  real_T c10_c_u;
  const mxArray *c10_d_y = NULL;
  real_T c10_d_hoistedGlobal;
  real_T c10_d_u;
  const mxArray *c10_e_y = NULL;
  uint8_T c10_e_hoistedGlobal;
  uint8_T c10_e_u;
  const mxArray *c10_f_y = NULL;
  real_T *c10_q1_des;
  real_T *c10_q2_des;
  real_T *c10_q3_des;
  real_T *c10_q4_des;
  c10_q4_des = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c10_q3_des = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c10_q2_des = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c10_q1_des = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c10_st = NULL;
  c10_st = NULL;
  c10_y = NULL;
  sf_mex_assign(&c10_y, sf_mex_createcellarray(5), FALSE);
  c10_hoistedGlobal = *c10_q1_des;
  c10_u = c10_hoistedGlobal;
  c10_b_y = NULL;
  sf_mex_assign(&c10_b_y, sf_mex_create("y", &c10_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c10_y, 0, c10_b_y);
  c10_b_hoistedGlobal = *c10_q2_des;
  c10_b_u = c10_b_hoistedGlobal;
  c10_c_y = NULL;
  sf_mex_assign(&c10_c_y, sf_mex_create("y", &c10_b_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c10_y, 1, c10_c_y);
  c10_c_hoistedGlobal = *c10_q3_des;
  c10_c_u = c10_c_hoistedGlobal;
  c10_d_y = NULL;
  sf_mex_assign(&c10_d_y, sf_mex_create("y", &c10_c_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c10_y, 2, c10_d_y);
  c10_d_hoistedGlobal = *c10_q4_des;
  c10_d_u = c10_d_hoistedGlobal;
  c10_e_y = NULL;
  sf_mex_assign(&c10_e_y, sf_mex_create("y", &c10_d_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c10_y, 3, c10_e_y);
  c10_e_hoistedGlobal = chartInstance->c10_is_active_c10_Pointing_Cntrl_Act;
  c10_e_u = c10_e_hoistedGlobal;
  c10_f_y = NULL;
  sf_mex_assign(&c10_f_y, sf_mex_create("y", &c10_e_u, 3, 0U, 0U, 0U, 0), FALSE);
  sf_mex_setcell(c10_y, 4, c10_f_y);
  sf_mex_assign(&c10_st, c10_y, FALSE);
  return c10_st;
}

static void set_sim_state_c10_Pointing_Cntrl_Act
  (SFc10_Pointing_Cntrl_ActInstanceStruct *chartInstance, const mxArray *c10_st)
{
  const mxArray *c10_u;
  real_T *c10_q1_des;
  real_T *c10_q2_des;
  real_T *c10_q3_des;
  real_T *c10_q4_des;
  c10_q4_des = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c10_q3_des = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c10_q2_des = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c10_q1_des = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  chartInstance->c10_doneDoubleBufferReInit = TRUE;
  c10_u = sf_mex_dup(c10_st);
  *c10_q1_des = c10_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c10_u, 0)), "q1_des");
  *c10_q2_des = c10_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c10_u, 1)), "q2_des");
  *c10_q3_des = c10_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c10_u, 2)), "q3_des");
  *c10_q4_des = c10_emlrt_marshallIn(chartInstance, sf_mex_dup(sf_mex_getcell
    (c10_u, 3)), "q4_des");
  chartInstance->c10_is_active_c10_Pointing_Cntrl_Act = c10_e_emlrt_marshallIn
    (chartInstance, sf_mex_dup(sf_mex_getcell(c10_u, 4)),
     "is_active_c10_Pointing_Cntrl_Act");
  sf_mex_destroy(&c10_u);
  c10_update_debugger_state_c10_Pointing_Cntrl_Act(chartInstance);
  sf_mex_destroy(&c10_st);
}

static void finalize_c10_Pointing_Cntrl_Act
  (SFc10_Pointing_Cntrl_ActInstanceStruct *chartInstance)
{
}

static void sf_c10_Pointing_Cntrl_Act(SFc10_Pointing_Cntrl_ActInstanceStruct
  *chartInstance)
{
  real_T c10_hoistedGlobal;
  real_T c10_b_hoistedGlobal;
  real_T c10_c_hoistedGlobal;
  real_T c10_phi_des;
  real_T c10_theta_des;
  real_T c10_psi_des;
  uint32_T c10_debug_family_var_map[16];
  real_T c10_s1;
  real_T c10_s2;
  real_T c10_s3;
  real_T c10_c1;
  real_T c10_c2;
  real_T c10_c3;
  real_T c10_A[9];
  real_T c10_nargin = 3.0;
  real_T c10_nargout = 4.0;
  real_T c10_q1_des;
  real_T c10_q2_des;
  real_T c10_q3_des;
  real_T c10_q4_des;
  real_T c10_x;
  real_T c10_b_x;
  real_T c10_c_x;
  real_T c10_d_x;
  real_T c10_e_x;
  real_T c10_f_x;
  real_T c10_g_x;
  real_T c10_h_x;
  real_T c10_i_x;
  real_T c10_j_x;
  real_T c10_k_x;
  real_T c10_l_x;
  real_T c10_a;
  real_T c10_b;
  real_T c10_y;
  real_T c10_b_a;
  real_T c10_b_b;
  real_T c10_b_y;
  real_T c10_c_a;
  real_T c10_c_b;
  real_T c10_c_y;
  real_T c10_d_a;
  real_T c10_d_b;
  real_T c10_d_y;
  real_T c10_e_a;
  real_T c10_e_b;
  real_T c10_e_y;
  real_T c10_f_a;
  real_T c10_f_b;
  real_T c10_f_y;
  real_T c10_g_a;
  real_T c10_g_b;
  real_T c10_g_y;
  real_T c10_h_a;
  real_T c10_h_b;
  real_T c10_h_y;
  real_T c10_i_a;
  real_T c10_i_b;
  real_T c10_i_y;
  real_T c10_j_a;
  real_T c10_j_b;
  real_T c10_j_y;
  real_T c10_k_a;
  real_T c10_k_b;
  real_T c10_k_y;
  real_T c10_l_a;
  real_T c10_l_b;
  real_T c10_l_y;
  real_T c10_m_a;
  real_T c10_m_b;
  real_T c10_m_y;
  real_T c10_n_a;
  real_T c10_n_b;
  real_T c10_n_y;
  real_T c10_o_a;
  real_T c10_o_b;
  real_T c10_o_y;
  real_T c10_p_a;
  real_T c10_p_b;
  real_T c10_p_y;
  real_T c10_q_b;
  real_T c10_q_y;
  real_T c10_m_x;
  real_T c10_n_x;
  real_T c10_r_b;
  real_T c10_r_y;
  real_T c10_o_x;
  real_T c10_p_x;
  real_T c10_s_b;
  real_T c10_s_y;
  real_T c10_q_x;
  real_T c10_r_x;
  real_T c10_t_b;
  real_T c10_t_y;
  real_T c10_s_x;
  real_T c10_t_x;
  real_T *c10_b_phi_des;
  real_T *c10_b_q1_des;
  real_T *c10_b_q2_des;
  real_T *c10_b_q3_des;
  real_T *c10_b_q4_des;
  real_T *c10_b_theta_des;
  real_T *c10_b_psi_des;
  c10_b_psi_des = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
  c10_b_theta_des = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
  c10_b_q4_des = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
  c10_b_q3_des = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
  c10_b_q2_des = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
  c10_b_q1_des = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
  c10_b_phi_des = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
  _sfTime_ = (real_T)ssGetT(chartInstance->S);
  _SFD_CC_CALL(CHART_ENTER_SFUNCTION_TAG, 7U, chartInstance->c10_sfEvent);
  _SFD_DATA_RANGE_CHECK(*c10_b_phi_des, 0U);
  _SFD_DATA_RANGE_CHECK(*c10_b_q1_des, 1U);
  _SFD_DATA_RANGE_CHECK(*c10_b_q2_des, 2U);
  _SFD_DATA_RANGE_CHECK(*c10_b_q3_des, 3U);
  _SFD_DATA_RANGE_CHECK(*c10_b_q4_des, 4U);
  _SFD_DATA_RANGE_CHECK(*c10_b_theta_des, 5U);
  _SFD_DATA_RANGE_CHECK(*c10_b_psi_des, 6U);
  chartInstance->c10_sfEvent = CALL_EVENT;
  _SFD_CC_CALL(CHART_ENTER_DURING_FUNCTION_TAG, 7U, chartInstance->c10_sfEvent);
  c10_hoistedGlobal = *c10_b_phi_des;
  c10_b_hoistedGlobal = *c10_b_theta_des;
  c10_c_hoistedGlobal = *c10_b_psi_des;
  c10_phi_des = c10_hoistedGlobal;
  c10_theta_des = c10_b_hoistedGlobal;
  c10_psi_des = c10_c_hoistedGlobal;
  _SFD_SYMBOL_SCOPE_PUSH_EML(0U, 16U, 16U, c10_debug_family_names,
    c10_debug_family_var_map);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_s1, 0U, c10_sf_marshallOut,
    c10_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_s2, 1U, c10_sf_marshallOut,
    c10_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_s3, 2U, c10_sf_marshallOut,
    c10_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_c1, 3U, c10_sf_marshallOut,
    c10_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_c2, 4U, c10_sf_marshallOut,
    c10_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_c3, 5U, c10_sf_marshallOut,
    c10_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(c10_A, 6U, c10_b_sf_marshallOut,
    c10_b_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_nargin, 7U, c10_sf_marshallOut,
    c10_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_nargout, 8U, c10_sf_marshallOut,
    c10_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c10_phi_des, 9U, c10_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c10_theta_des, 10U, c10_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML(&c10_psi_des, 11U, c10_sf_marshallOut);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_q1_des, 12U, c10_sf_marshallOut,
    c10_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_q2_des, 13U, c10_sf_marshallOut,
    c10_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_q3_des, 14U, c10_sf_marshallOut,
    c10_sf_marshallIn);
  _SFD_SYMBOL_SCOPE_ADD_EML_IMPORTABLE(&c10_q4_des, 15U, c10_sf_marshallOut,
    c10_sf_marshallIn);
  CV_EML_FCN(0, 0);
  _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 5);
  c10_x = c10_phi_des;
  c10_s1 = c10_x;
  c10_b_x = c10_s1;
  c10_s1 = c10_b_x;
  c10_s1 = muDoubleScalarSin(c10_s1);
  _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 6);
  c10_c_x = c10_theta_des;
  c10_s2 = c10_c_x;
  c10_d_x = c10_s2;
  c10_s2 = c10_d_x;
  c10_s2 = muDoubleScalarSin(c10_s2);
  _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 7);
  c10_e_x = c10_psi_des;
  c10_s3 = c10_e_x;
  c10_f_x = c10_s3;
  c10_s3 = c10_f_x;
  c10_s3 = muDoubleScalarSin(c10_s3);
  _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 8);
  c10_g_x = c10_phi_des;
  c10_c1 = c10_g_x;
  c10_h_x = c10_c1;
  c10_c1 = c10_h_x;
  c10_c1 = muDoubleScalarCos(c10_c1);
  _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 9);
  c10_i_x = c10_theta_des;
  c10_c2 = c10_i_x;
  c10_j_x = c10_c2;
  c10_c2 = c10_j_x;
  c10_c2 = muDoubleScalarCos(c10_c2);
  _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 10);
  c10_k_x = c10_psi_des;
  c10_c3 = c10_k_x;
  c10_l_x = c10_c3;
  c10_c3 = c10_l_x;
  c10_c3 = muDoubleScalarCos(c10_c3);
  _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 12);
  c10_a = c10_c1;
  c10_b = c10_c3;
  c10_y = c10_a * c10_b;
  c10_b_a = c10_s1;
  c10_b_b = c10_c2;
  c10_b_y = c10_b_a * c10_b_b;
  c10_c_a = c10_b_y;
  c10_c_b = c10_s3;
  c10_c_y = c10_c_a * c10_c_b;
  c10_d_a = c10_c1;
  c10_d_b = c10_s3;
  c10_d_y = c10_d_a * c10_d_b;
  c10_e_a = c10_s1;
  c10_e_b = c10_c2;
  c10_e_y = c10_e_a * c10_e_b;
  c10_f_a = c10_e_y;
  c10_f_b = c10_c3;
  c10_f_y = c10_f_a * c10_f_b;
  c10_g_a = c10_s1;
  c10_g_b = c10_s2;
  c10_g_y = c10_g_a * c10_g_b;
  c10_h_a = -c10_s1;
  c10_h_b = c10_c3;
  c10_h_y = c10_h_a * c10_h_b;
  c10_i_a = c10_c1;
  c10_i_b = c10_c2;
  c10_i_y = c10_i_a * c10_i_b;
  c10_j_a = c10_i_y;
  c10_j_b = c10_s3;
  c10_j_y = c10_j_a * c10_j_b;
  c10_k_a = -c10_s1;
  c10_k_b = c10_s3;
  c10_k_y = c10_k_a * c10_k_b;
  c10_l_a = c10_c1;
  c10_l_b = c10_c2;
  c10_l_y = c10_l_a * c10_l_b;
  c10_m_a = c10_l_y;
  c10_m_b = c10_c3;
  c10_m_y = c10_m_a * c10_m_b;
  c10_n_a = c10_c1;
  c10_n_b = c10_s2;
  c10_n_y = c10_n_a * c10_n_b;
  c10_o_a = c10_s2;
  c10_o_b = c10_s3;
  c10_o_y = c10_o_a * c10_o_b;
  c10_p_a = -c10_s2;
  c10_p_b = c10_c3;
  c10_p_y = c10_p_a * c10_p_b;
  c10_A[0] = c10_y - c10_c_y;
  c10_A[3] = c10_d_y + c10_f_y;
  c10_A[6] = c10_g_y;
  c10_A[1] = c10_h_y - c10_j_y;
  c10_A[4] = c10_k_y + c10_m_y;
  c10_A[7] = c10_n_y;
  c10_A[2] = c10_o_y;
  c10_A[5] = c10_p_y;
  c10_A[8] = c10_c2;
  _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 17);
  c10_q_b = ((1.0 + c10_A[0]) - c10_A[4]) - c10_A[8];
  c10_q_y = 0.25 * c10_q_b;
  c10_m_x = c10_q_y;
  c10_q1_des = c10_m_x;
  if (c10_q1_des < 0.0) {
    c10_eml_error(chartInstance);
  }

  c10_n_x = c10_q1_des;
  c10_q1_des = c10_n_x;
  c10_q1_des = muDoubleScalarSqrt(c10_q1_des);
  _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 18);
  c10_r_b = ((1.0 + c10_A[4]) - c10_A[0]) - c10_A[8];
  c10_r_y = 0.25 * c10_r_b;
  c10_o_x = c10_r_y;
  c10_q2_des = c10_o_x;
  if (c10_q2_des < 0.0) {
    c10_eml_error(chartInstance);
  }

  c10_p_x = c10_q2_des;
  c10_q2_des = c10_p_x;
  c10_q2_des = muDoubleScalarSqrt(c10_q2_des);
  _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 19);
  c10_s_b = ((1.0 + c10_A[8]) - c10_A[0]) - c10_A[4];
  c10_s_y = 0.25 * c10_s_b;
  c10_q_x = c10_s_y;
  c10_q3_des = c10_q_x;
  if (c10_q3_des < 0.0) {
    c10_eml_error(chartInstance);
  }

  c10_r_x = c10_q3_des;
  c10_q3_des = c10_r_x;
  c10_q3_des = muDoubleScalarSqrt(c10_q3_des);
  _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, 20);
  c10_t_b = ((1.0 + c10_A[0]) + c10_A[4]) + c10_A[8];
  c10_t_y = 0.25 * c10_t_b;
  c10_s_x = c10_t_y;
  c10_q4_des = c10_s_x;
  if (c10_q4_des < 0.0) {
    c10_eml_error(chartInstance);
  }

  c10_t_x = c10_q4_des;
  c10_q4_des = c10_t_x;
  c10_q4_des = muDoubleScalarSqrt(c10_q4_des);
  _SFD_EML_CALL(0U, chartInstance->c10_sfEvent, -20);
  _SFD_SYMBOL_SCOPE_POP();
  *c10_b_q1_des = c10_q1_des;
  *c10_b_q2_des = c10_q2_des;
  *c10_b_q3_des = c10_q3_des;
  *c10_b_q4_des = c10_q4_des;
  _SFD_CC_CALL(EXIT_OUT_OF_FUNCTION_TAG, 7U, chartInstance->c10_sfEvent);
  _SFD_CHECK_FOR_STATE_INCONSISTENCY(_Pointing_Cntrl_ActMachineNumber_,
    chartInstance->chartNumber, chartInstance->instanceNumber);
}

static void initSimStructsc10_Pointing_Cntrl_Act
  (SFc10_Pointing_Cntrl_ActInstanceStruct *chartInstance)
{
}

static void registerMessagesc10_Pointing_Cntrl_Act
  (SFc10_Pointing_Cntrl_ActInstanceStruct *chartInstance)
{
}

static void init_script_number_translation(uint32_T c10_machineNumber, uint32_T
  c10_chartNumber)
{
}

static const mxArray *c10_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData)
{
  const mxArray *c10_mxArrayOutData = NULL;
  real_T c10_u;
  const mxArray *c10_y = NULL;
  SFc10_Pointing_Cntrl_ActInstanceStruct *chartInstance;
  chartInstance = (SFc10_Pointing_Cntrl_ActInstanceStruct *)chartInstanceVoid;
  c10_mxArrayOutData = NULL;
  c10_u = *(real_T *)c10_inData;
  c10_y = NULL;
  sf_mex_assign(&c10_y, sf_mex_create("y", &c10_u, 0, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c10_mxArrayOutData, c10_y, FALSE);
  return c10_mxArrayOutData;
}

static real_T c10_emlrt_marshallIn(SFc10_Pointing_Cntrl_ActInstanceStruct
  *chartInstance, const mxArray *c10_q4_des, const char_T *c10_identifier)
{
  real_T c10_y;
  emlrtMsgIdentifier c10_thisId;
  c10_thisId.fIdentifier = c10_identifier;
  c10_thisId.fParent = NULL;
  c10_y = c10_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c10_q4_des),
    &c10_thisId);
  sf_mex_destroy(&c10_q4_des);
  return c10_y;
}

static real_T c10_b_emlrt_marshallIn(SFc10_Pointing_Cntrl_ActInstanceStruct
  *chartInstance, const mxArray *c10_u, const emlrtMsgIdentifier *c10_parentId)
{
  real_T c10_y;
  real_T c10_d0;
  sf_mex_import(c10_parentId, sf_mex_dup(c10_u), &c10_d0, 1, 0, 0U, 0, 0U, 0);
  c10_y = c10_d0;
  sf_mex_destroy(&c10_u);
  return c10_y;
}

static void c10_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c10_mxArrayInData, const char_T *c10_varName, void *c10_outData)
{
  const mxArray *c10_q4_des;
  const char_T *c10_identifier;
  emlrtMsgIdentifier c10_thisId;
  real_T c10_y;
  SFc10_Pointing_Cntrl_ActInstanceStruct *chartInstance;
  chartInstance = (SFc10_Pointing_Cntrl_ActInstanceStruct *)chartInstanceVoid;
  c10_q4_des = sf_mex_dup(c10_mxArrayInData);
  c10_identifier = c10_varName;
  c10_thisId.fIdentifier = c10_identifier;
  c10_thisId.fParent = NULL;
  c10_y = c10_b_emlrt_marshallIn(chartInstance, sf_mex_dup(c10_q4_des),
    &c10_thisId);
  sf_mex_destroy(&c10_q4_des);
  *(real_T *)c10_outData = c10_y;
  sf_mex_destroy(&c10_mxArrayInData);
}

static const mxArray *c10_b_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData)
{
  const mxArray *c10_mxArrayOutData = NULL;
  int32_T c10_i0;
  int32_T c10_i1;
  int32_T c10_i2;
  real_T c10_b_inData[9];
  int32_T c10_i3;
  int32_T c10_i4;
  int32_T c10_i5;
  real_T c10_u[9];
  const mxArray *c10_y = NULL;
  SFc10_Pointing_Cntrl_ActInstanceStruct *chartInstance;
  chartInstance = (SFc10_Pointing_Cntrl_ActInstanceStruct *)chartInstanceVoid;
  c10_mxArrayOutData = NULL;
  c10_i0 = 0;
  for (c10_i1 = 0; c10_i1 < 3; c10_i1++) {
    for (c10_i2 = 0; c10_i2 < 3; c10_i2++) {
      c10_b_inData[c10_i2 + c10_i0] = (*(real_T (*)[9])c10_inData)[c10_i2 +
        c10_i0];
    }

    c10_i0 += 3;
  }

  c10_i3 = 0;
  for (c10_i4 = 0; c10_i4 < 3; c10_i4++) {
    for (c10_i5 = 0; c10_i5 < 3; c10_i5++) {
      c10_u[c10_i5 + c10_i3] = c10_b_inData[c10_i5 + c10_i3];
    }

    c10_i3 += 3;
  }

  c10_y = NULL;
  sf_mex_assign(&c10_y, sf_mex_create("y", c10_u, 0, 0U, 1U, 0U, 2, 3, 3), FALSE);
  sf_mex_assign(&c10_mxArrayOutData, c10_y, FALSE);
  return c10_mxArrayOutData;
}

static void c10_c_emlrt_marshallIn(SFc10_Pointing_Cntrl_ActInstanceStruct
  *chartInstance, const mxArray *c10_u, const emlrtMsgIdentifier *c10_parentId,
  real_T c10_y[9])
{
  real_T c10_dv0[9];
  int32_T c10_i6;
  sf_mex_import(c10_parentId, sf_mex_dup(c10_u), c10_dv0, 1, 0, 0U, 1, 0U, 2, 3,
                3);
  for (c10_i6 = 0; c10_i6 < 9; c10_i6++) {
    c10_y[c10_i6] = c10_dv0[c10_i6];
  }

  sf_mex_destroy(&c10_u);
}

static void c10_b_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c10_mxArrayInData, const char_T *c10_varName, void *c10_outData)
{
  const mxArray *c10_A;
  const char_T *c10_identifier;
  emlrtMsgIdentifier c10_thisId;
  real_T c10_y[9];
  int32_T c10_i7;
  int32_T c10_i8;
  int32_T c10_i9;
  SFc10_Pointing_Cntrl_ActInstanceStruct *chartInstance;
  chartInstance = (SFc10_Pointing_Cntrl_ActInstanceStruct *)chartInstanceVoid;
  c10_A = sf_mex_dup(c10_mxArrayInData);
  c10_identifier = c10_varName;
  c10_thisId.fIdentifier = c10_identifier;
  c10_thisId.fParent = NULL;
  c10_c_emlrt_marshallIn(chartInstance, sf_mex_dup(c10_A), &c10_thisId, c10_y);
  sf_mex_destroy(&c10_A);
  c10_i7 = 0;
  for (c10_i8 = 0; c10_i8 < 3; c10_i8++) {
    for (c10_i9 = 0; c10_i9 < 3; c10_i9++) {
      (*(real_T (*)[9])c10_outData)[c10_i9 + c10_i7] = c10_y[c10_i9 + c10_i7];
    }

    c10_i7 += 3;
  }

  sf_mex_destroy(&c10_mxArrayInData);
}

const mxArray *sf_c10_Pointing_Cntrl_Act_get_eml_resolved_functions_info(void)
{
  const mxArray *c10_nameCaptureInfo;
  c10_ResolvedFunctionInfo c10_info[12];
  c10_ResolvedFunctionInfo (*c10_b_info)[12];
  const mxArray *c10_m0 = NULL;
  int32_T c10_i10;
  c10_ResolvedFunctionInfo *c10_r0;
  c10_nameCaptureInfo = NULL;
  c10_nameCaptureInfo = NULL;
  c10_b_info = (c10_ResolvedFunctionInfo (*)[12])c10_info;
  (*c10_b_info)[0].context = "";
  (*c10_b_info)[0].name = "sin";
  (*c10_b_info)[0].dominantType = "double";
  (*c10_b_info)[0].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  (*c10_b_info)[0].fileTimeLo = 1343851986U;
  (*c10_b_info)[0].fileTimeHi = 0U;
  (*c10_b_info)[0].mFileTimeLo = 0U;
  (*c10_b_info)[0].mFileTimeHi = 0U;
  (*c10_b_info)[1].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sin.m";
  (*c10_b_info)[1].name = "eml_scalar_sin";
  (*c10_b_info)[1].dominantType = "double";
  (*c10_b_info)[1].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sin.m";
  (*c10_b_info)[1].fileTimeLo = 1286840336U;
  (*c10_b_info)[1].fileTimeHi = 0U;
  (*c10_b_info)[1].mFileTimeLo = 0U;
  (*c10_b_info)[1].mFileTimeHi = 0U;
  (*c10_b_info)[2].context = "";
  (*c10_b_info)[2].name = "cos";
  (*c10_b_info)[2].dominantType = "double";
  (*c10_b_info)[2].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  (*c10_b_info)[2].fileTimeLo = 1343851972U;
  (*c10_b_info)[2].fileTimeHi = 0U;
  (*c10_b_info)[2].mFileTimeLo = 0U;
  (*c10_b_info)[2].mFileTimeHi = 0U;
  (*c10_b_info)[3].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/cos.m";
  (*c10_b_info)[3].name = "eml_scalar_cos";
  (*c10_b_info)[3].dominantType = "double";
  (*c10_b_info)[3].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_cos.m";
  (*c10_b_info)[3].fileTimeLo = 1286840322U;
  (*c10_b_info)[3].fileTimeHi = 0U;
  (*c10_b_info)[3].mFileTimeLo = 0U;
  (*c10_b_info)[3].mFileTimeHi = 0U;
  (*c10_b_info)[4].context = "";
  (*c10_b_info)[4].name = "mtimes";
  (*c10_b_info)[4].dominantType = "double";
  (*c10_b_info)[4].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mtimes.m";
  (*c10_b_info)[4].fileTimeLo = 1289541292U;
  (*c10_b_info)[4].fileTimeHi = 0U;
  (*c10_b_info)[4].mFileTimeLo = 0U;
  (*c10_b_info)[4].mFileTimeHi = 0U;
  (*c10_b_info)[5].context = "";
  (*c10_b_info)[5].name = "mrdivide";
  (*c10_b_info)[5].dominantType = "double";
  (*c10_b_info)[5].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  (*c10_b_info)[5].fileTimeLo = 1357973148U;
  (*c10_b_info)[5].fileTimeHi = 0U;
  (*c10_b_info)[5].mFileTimeLo = 1319751566U;
  (*c10_b_info)[5].mFileTimeHi = 0U;
  (*c10_b_info)[6].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/mrdivide.p";
  (*c10_b_info)[6].name = "rdivide";
  (*c10_b_info)[6].dominantType = "double";
  (*c10_b_info)[6].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  (*c10_b_info)[6].fileTimeLo = 1346531988U;
  (*c10_b_info)[6].fileTimeHi = 0U;
  (*c10_b_info)[6].mFileTimeLo = 0U;
  (*c10_b_info)[6].mFileTimeHi = 0U;
  (*c10_b_info)[7].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  (*c10_b_info)[7].name = "eml_scalexp_compatible";
  (*c10_b_info)[7].dominantType = "double";
  (*c10_b_info)[7].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_scalexp_compatible.m";
  (*c10_b_info)[7].fileTimeLo = 1286840396U;
  (*c10_b_info)[7].fileTimeHi = 0U;
  (*c10_b_info)[7].mFileTimeLo = 0U;
  (*c10_b_info)[7].mFileTimeHi = 0U;
  (*c10_b_info)[8].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/ops/rdivide.m";
  (*c10_b_info)[8].name = "eml_div";
  (*c10_b_info)[8].dominantType = "double";
  (*c10_b_info)[8].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_div.m";
  (*c10_b_info)[8].fileTimeLo = 1313369410U;
  (*c10_b_info)[8].fileTimeHi = 0U;
  (*c10_b_info)[8].mFileTimeLo = 0U;
  (*c10_b_info)[8].mFileTimeHi = 0U;
  (*c10_b_info)[9].context = "";
  (*c10_b_info)[9].name = "sqrt";
  (*c10_b_info)[9].dominantType = "double";
  (*c10_b_info)[9].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m";
  (*c10_b_info)[9].fileTimeLo = 1343851986U;
  (*c10_b_info)[9].fileTimeHi = 0U;
  (*c10_b_info)[9].mFileTimeLo = 0U;
  (*c10_b_info)[9].mFileTimeHi = 0U;
  (*c10_b_info)[10].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m";
  (*c10_b_info)[10].name = "eml_error";
  (*c10_b_info)[10].dominantType = "char";
  (*c10_b_info)[10].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/eml/eml_error.m";
  (*c10_b_info)[10].fileTimeLo = 1343851958U;
  (*c10_b_info)[10].fileTimeHi = 0U;
  (*c10_b_info)[10].mFileTimeLo = 0U;
  (*c10_b_info)[10].mFileTimeHi = 0U;
  (*c10_b_info)[11].context =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/sqrt.m";
  (*c10_b_info)[11].name = "eml_scalar_sqrt";
  (*c10_b_info)[11].dominantType = "double";
  (*c10_b_info)[11].resolved =
    "[ILXE]$matlabroot$/toolbox/eml/lib/matlab/elfun/eml_scalar_sqrt.m";
  (*c10_b_info)[11].fileTimeLo = 1286840338U;
  (*c10_b_info)[11].fileTimeHi = 0U;
  (*c10_b_info)[11].mFileTimeLo = 0U;
  (*c10_b_info)[11].mFileTimeHi = 0U;
  sf_mex_assign(&c10_m0, sf_mex_createstruct("nameCaptureInfo", 1, 12), FALSE);
  for (c10_i10 = 0; c10_i10 < 12; c10_i10++) {
    c10_r0 = &c10_info[c10_i10];
    sf_mex_addfield(c10_m0, sf_mex_create("nameCaptureInfo", c10_r0->context, 15,
      0U, 0U, 0U, 2, 1, strlen(c10_r0->context)), "context", "nameCaptureInfo",
                    c10_i10);
    sf_mex_addfield(c10_m0, sf_mex_create("nameCaptureInfo", c10_r0->name, 15,
      0U, 0U, 0U, 2, 1, strlen(c10_r0->name)), "name", "nameCaptureInfo",
                    c10_i10);
    sf_mex_addfield(c10_m0, sf_mex_create("nameCaptureInfo",
      c10_r0->dominantType, 15, 0U, 0U, 0U, 2, 1, strlen(c10_r0->dominantType)),
                    "dominantType", "nameCaptureInfo", c10_i10);
    sf_mex_addfield(c10_m0, sf_mex_create("nameCaptureInfo", c10_r0->resolved,
      15, 0U, 0U, 0U, 2, 1, strlen(c10_r0->resolved)), "resolved",
                    "nameCaptureInfo", c10_i10);
    sf_mex_addfield(c10_m0, sf_mex_create("nameCaptureInfo", &c10_r0->fileTimeLo,
      7, 0U, 0U, 0U, 0), "fileTimeLo", "nameCaptureInfo", c10_i10);
    sf_mex_addfield(c10_m0, sf_mex_create("nameCaptureInfo", &c10_r0->fileTimeHi,
      7, 0U, 0U, 0U, 0), "fileTimeHi", "nameCaptureInfo", c10_i10);
    sf_mex_addfield(c10_m0, sf_mex_create("nameCaptureInfo",
      &c10_r0->mFileTimeLo, 7, 0U, 0U, 0U, 0), "mFileTimeLo", "nameCaptureInfo",
                    c10_i10);
    sf_mex_addfield(c10_m0, sf_mex_create("nameCaptureInfo",
      &c10_r0->mFileTimeHi, 7, 0U, 0U, 0U, 0), "mFileTimeHi", "nameCaptureInfo",
                    c10_i10);
  }

  sf_mex_assign(&c10_nameCaptureInfo, c10_m0, FALSE);
  sf_mex_emlrtNameCapturePostProcessR2012a(&c10_nameCaptureInfo);
  return c10_nameCaptureInfo;
}

static void c10_eml_error(SFc10_Pointing_Cntrl_ActInstanceStruct *chartInstance)
{
  int32_T c10_i11;
  static char_T c10_cv0[30] = { 'C', 'o', 'd', 'e', 'r', ':', 't', 'o', 'o', 'l',
    'b', 'o', 'x', ':', 'E', 'l', 'F', 'u', 'n', 'D', 'o', 'm', 'a', 'i', 'n',
    'E', 'r', 'r', 'o', 'r' };

  char_T c10_u[30];
  const mxArray *c10_y = NULL;
  int32_T c10_i12;
  static char_T c10_cv1[4] = { 's', 'q', 'r', 't' };

  char_T c10_b_u[4];
  const mxArray *c10_b_y = NULL;
  for (c10_i11 = 0; c10_i11 < 30; c10_i11++) {
    c10_u[c10_i11] = c10_cv0[c10_i11];
  }

  c10_y = NULL;
  sf_mex_assign(&c10_y, sf_mex_create("y", c10_u, 10, 0U, 1U, 0U, 2, 1, 30),
                FALSE);
  for (c10_i12 = 0; c10_i12 < 4; c10_i12++) {
    c10_b_u[c10_i12] = c10_cv1[c10_i12];
  }

  c10_b_y = NULL;
  sf_mex_assign(&c10_b_y, sf_mex_create("y", c10_b_u, 10, 0U, 1U, 0U, 2, 1, 4),
                FALSE);
  sf_mex_call_debug("error", 0U, 1U, 14, sf_mex_call_debug("message", 1U, 2U, 14,
    c10_y, 14, c10_b_y));
}

static const mxArray *c10_c_sf_marshallOut(void *chartInstanceVoid, void
  *c10_inData)
{
  const mxArray *c10_mxArrayOutData = NULL;
  int32_T c10_u;
  const mxArray *c10_y = NULL;
  SFc10_Pointing_Cntrl_ActInstanceStruct *chartInstance;
  chartInstance = (SFc10_Pointing_Cntrl_ActInstanceStruct *)chartInstanceVoid;
  c10_mxArrayOutData = NULL;
  c10_u = *(int32_T *)c10_inData;
  c10_y = NULL;
  sf_mex_assign(&c10_y, sf_mex_create("y", &c10_u, 6, 0U, 0U, 0U, 0), FALSE);
  sf_mex_assign(&c10_mxArrayOutData, c10_y, FALSE);
  return c10_mxArrayOutData;
}

static int32_T c10_d_emlrt_marshallIn(SFc10_Pointing_Cntrl_ActInstanceStruct
  *chartInstance, const mxArray *c10_u, const emlrtMsgIdentifier *c10_parentId)
{
  int32_T c10_y;
  int32_T c10_i13;
  sf_mex_import(c10_parentId, sf_mex_dup(c10_u), &c10_i13, 1, 6, 0U, 0, 0U, 0);
  c10_y = c10_i13;
  sf_mex_destroy(&c10_u);
  return c10_y;
}

static void c10_c_sf_marshallIn(void *chartInstanceVoid, const mxArray
  *c10_mxArrayInData, const char_T *c10_varName, void *c10_outData)
{
  const mxArray *c10_b_sfEvent;
  const char_T *c10_identifier;
  emlrtMsgIdentifier c10_thisId;
  int32_T c10_y;
  SFc10_Pointing_Cntrl_ActInstanceStruct *chartInstance;
  chartInstance = (SFc10_Pointing_Cntrl_ActInstanceStruct *)chartInstanceVoid;
  c10_b_sfEvent = sf_mex_dup(c10_mxArrayInData);
  c10_identifier = c10_varName;
  c10_thisId.fIdentifier = c10_identifier;
  c10_thisId.fParent = NULL;
  c10_y = c10_d_emlrt_marshallIn(chartInstance, sf_mex_dup(c10_b_sfEvent),
    &c10_thisId);
  sf_mex_destroy(&c10_b_sfEvent);
  *(int32_T *)c10_outData = c10_y;
  sf_mex_destroy(&c10_mxArrayInData);
}

static uint8_T c10_e_emlrt_marshallIn(SFc10_Pointing_Cntrl_ActInstanceStruct
  *chartInstance, const mxArray *c10_b_is_active_c10_Pointing_Cntrl_Act, const
  char_T *c10_identifier)
{
  uint8_T c10_y;
  emlrtMsgIdentifier c10_thisId;
  c10_thisId.fIdentifier = c10_identifier;
  c10_thisId.fParent = NULL;
  c10_y = c10_f_emlrt_marshallIn(chartInstance, sf_mex_dup
    (c10_b_is_active_c10_Pointing_Cntrl_Act), &c10_thisId);
  sf_mex_destroy(&c10_b_is_active_c10_Pointing_Cntrl_Act);
  return c10_y;
}

static uint8_T c10_f_emlrt_marshallIn(SFc10_Pointing_Cntrl_ActInstanceStruct
  *chartInstance, const mxArray *c10_u, const emlrtMsgIdentifier *c10_parentId)
{
  uint8_T c10_y;
  uint8_T c10_u0;
  sf_mex_import(c10_parentId, sf_mex_dup(c10_u), &c10_u0, 1, 3, 0U, 0, 0U, 0);
  c10_y = c10_u0;
  sf_mex_destroy(&c10_u);
  return c10_y;
}

static void init_dsm_address_info(SFc10_Pointing_Cntrl_ActInstanceStruct
  *chartInstance)
{
}

/* SFunction Glue Code */
#ifdef utFree
#undef utFree
#endif

#ifdef utMalloc
#undef utMalloc
#endif

#ifdef __cplusplus

extern "C" void *utMalloc(size_t size);
extern "C" void utFree(void*);

#else

extern void *utMalloc(size_t size);
extern void utFree(void*);

#endif

void sf_c10_Pointing_Cntrl_Act_get_check_sum(mxArray *plhs[])
{
  ((real_T *)mxGetPr((plhs[0])))[0] = (real_T)(577427880U);
  ((real_T *)mxGetPr((plhs[0])))[1] = (real_T)(3792673358U);
  ((real_T *)mxGetPr((plhs[0])))[2] = (real_T)(3938042797U);
  ((real_T *)mxGetPr((plhs[0])))[3] = (real_T)(3570067331U);
}

mxArray *sf_c10_Pointing_Cntrl_Act_get_autoinheritance_info(void)
{
  const char *autoinheritanceFields[] = { "checksum", "inputs", "parameters",
    "outputs", "locals" };

  mxArray *mxAutoinheritanceInfo = mxCreateStructMatrix(1,1,5,
    autoinheritanceFields);

  {
    mxArray *mxChecksum = mxCreateString("X7QRctxf07wMOnRwgxAdS");
    mxSetField(mxAutoinheritanceInfo,0,"checksum",mxChecksum);
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,3,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,2,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,2,"type",mxType);
    }

    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"inputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"parameters",mxCreateDoubleMatrix(0,0,
                mxREAL));
  }

  {
    const char *dataFields[] = { "size", "type", "complexity" };

    mxArray *mxData = mxCreateStructMatrix(1,4,3,dataFields);

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,0,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,0,"type",mxType);
    }

    mxSetField(mxData,0,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,1,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,1,"type",mxType);
    }

    mxSetField(mxData,1,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,2,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,2,"type",mxType);
    }

    mxSetField(mxData,2,"complexity",mxCreateDoubleScalar(0));

    {
      mxArray *mxSize = mxCreateDoubleMatrix(1,2,mxREAL);
      double *pr = mxGetPr(mxSize);
      pr[0] = (double)(1);
      pr[1] = (double)(1);
      mxSetField(mxData,3,"size",mxSize);
    }

    {
      const char *typeFields[] = { "base", "fixpt" };

      mxArray *mxType = mxCreateStructMatrix(1,1,2,typeFields);
      mxSetField(mxType,0,"base",mxCreateDoubleScalar(10));
      mxSetField(mxType,0,"fixpt",mxCreateDoubleMatrix(0,0,mxREAL));
      mxSetField(mxData,3,"type",mxType);
    }

    mxSetField(mxData,3,"complexity",mxCreateDoubleScalar(0));
    mxSetField(mxAutoinheritanceInfo,0,"outputs",mxData);
  }

  {
    mxSetField(mxAutoinheritanceInfo,0,"locals",mxCreateDoubleMatrix(0,0,mxREAL));
  }

  return(mxAutoinheritanceInfo);
}

mxArray *sf_c10_Pointing_Cntrl_Act_third_party_uses_info(void)
{
  mxArray * mxcell3p = mxCreateCellMatrix(1,0);
  return(mxcell3p);
}

static const mxArray *sf_get_sim_state_info_c10_Pointing_Cntrl_Act(void)
{
  const char *infoFields[] = { "chartChecksum", "varInfo" };

  mxArray *mxInfo = mxCreateStructMatrix(1, 1, 2, infoFields);
  const char *infoEncStr[] = {
    "100 S1x5'type','srcId','name','auxInfo'{{M[1],M[5],T\"q1_des\",},{M[1],M[6],T\"q2_des\",},{M[1],M[7],T\"q3_des\",},{M[1],M[8],T\"q4_des\",},{M[8],M[0],T\"is_active_c10_Pointing_Cntrl_Act\",}}"
  };

  mxArray *mxVarInfo = sf_mex_decode_encoded_mx_struct_array(infoEncStr, 5, 10);
  mxArray *mxChecksum = mxCreateDoubleMatrix(1, 4, mxREAL);
  sf_c10_Pointing_Cntrl_Act_get_check_sum(&mxChecksum);
  mxSetField(mxInfo, 0, infoFields[0], mxChecksum);
  mxSetField(mxInfo, 0, infoFields[1], mxVarInfo);
  return mxInfo;
}

static void chart_debug_initialization(SimStruct *S, unsigned int
  fullDebuggerInitialization)
{
  if (!sim_mode_is_rtw_gen(S)) {
    SFc10_Pointing_Cntrl_ActInstanceStruct *chartInstance;
    chartInstance = (SFc10_Pointing_Cntrl_ActInstanceStruct *) ((ChartInfoStruct
      *)(ssGetUserData(S)))->chartInstance;
    if (ssIsFirstInitCond(S) && fullDebuggerInitialization==1) {
      /* do this only if simulation is starting */
      {
        unsigned int chartAlreadyPresent;
        chartAlreadyPresent = sf_debug_initialize_chart
          (sfGlobalDebugInstanceStruct,
           _Pointing_Cntrl_ActMachineNumber_,
           10,
           1,
           1,
           7,
           0,
           0,
           0,
           0,
           0,
           &(chartInstance->chartNumber),
           &(chartInstance->instanceNumber),
           ssGetPath(S),
           (void *)S);
        if (chartAlreadyPresent==0) {
          /* this is the first instance */
          init_script_number_translation(_Pointing_Cntrl_ActMachineNumber_,
            chartInstance->chartNumber);
          sf_debug_set_chart_disable_implicit_casting
            (sfGlobalDebugInstanceStruct,_Pointing_Cntrl_ActMachineNumber_,
             chartInstance->chartNumber,1);
          sf_debug_set_chart_event_thresholds(sfGlobalDebugInstanceStruct,
            _Pointing_Cntrl_ActMachineNumber_,
            chartInstance->chartNumber,
            0,
            0,
            0);
          _SFD_SET_DATA_PROPS(0,1,1,0,"phi_des");
          _SFD_SET_DATA_PROPS(1,2,0,1,"q1_des");
          _SFD_SET_DATA_PROPS(2,2,0,1,"q2_des");
          _SFD_SET_DATA_PROPS(3,2,0,1,"q3_des");
          _SFD_SET_DATA_PROPS(4,2,0,1,"q4_des");
          _SFD_SET_DATA_PROPS(5,1,1,0,"theta_des");
          _SFD_SET_DATA_PROPS(6,1,1,0,"psi_des");
          _SFD_STATE_INFO(0,0,2);
          _SFD_CH_SUBSTATE_COUNT(0);
          _SFD_CH_SUBSTATE_DECOMP(0);
        }

        _SFD_CV_INIT_CHART(0,0,0,0);

        {
          _SFD_CV_INIT_STATE(0,0,0,0,0,0,NULL,NULL);
        }

        _SFD_CV_INIT_TRANS(0,0,NULL,NULL,0,NULL);

        /* Initialization of MATLAB Function Model Coverage */
        _SFD_CV_INIT_EML(0,1,1,0,0,0,0,0,0,0,0);
        _SFD_CV_INIT_EML_FCN(0,0,"eML_blk_kernel",0,-1,706);
        _SFD_TRANS_COV_WTS(0,0,0,1,0);
        if (chartAlreadyPresent==0) {
          _SFD_TRANS_COV_MAPS(0,
                              0,NULL,NULL,
                              0,NULL,NULL,
                              1,NULL,NULL,
                              0,NULL,NULL);
        }

        _SFD_SET_DATA_COMPILED_PROPS(0,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c10_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(1,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c10_sf_marshallOut,(MexInFcnForType)c10_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(2,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c10_sf_marshallOut,(MexInFcnForType)c10_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(3,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c10_sf_marshallOut,(MexInFcnForType)c10_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(4,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c10_sf_marshallOut,(MexInFcnForType)c10_sf_marshallIn);
        _SFD_SET_DATA_COMPILED_PROPS(5,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c10_sf_marshallOut,(MexInFcnForType)NULL);
        _SFD_SET_DATA_COMPILED_PROPS(6,SF_DOUBLE,0,NULL,0,0,0,0.0,1.0,0,0,
          (MexFcnForType)c10_sf_marshallOut,(MexInFcnForType)NULL);

        {
          real_T *c10_phi_des;
          real_T *c10_q1_des;
          real_T *c10_q2_des;
          real_T *c10_q3_des;
          real_T *c10_q4_des;
          real_T *c10_theta_des;
          real_T *c10_psi_des;
          c10_psi_des = (real_T *)ssGetInputPortSignal(chartInstance->S, 2);
          c10_theta_des = (real_T *)ssGetInputPortSignal(chartInstance->S, 1);
          c10_q4_des = (real_T *)ssGetOutputPortSignal(chartInstance->S, 4);
          c10_q3_des = (real_T *)ssGetOutputPortSignal(chartInstance->S, 3);
          c10_q2_des = (real_T *)ssGetOutputPortSignal(chartInstance->S, 2);
          c10_q1_des = (real_T *)ssGetOutputPortSignal(chartInstance->S, 1);
          c10_phi_des = (real_T *)ssGetInputPortSignal(chartInstance->S, 0);
          _SFD_SET_DATA_VALUE_PTR(0U, c10_phi_des);
          _SFD_SET_DATA_VALUE_PTR(1U, c10_q1_des);
          _SFD_SET_DATA_VALUE_PTR(2U, c10_q2_des);
          _SFD_SET_DATA_VALUE_PTR(3U, c10_q3_des);
          _SFD_SET_DATA_VALUE_PTR(4U, c10_q4_des);
          _SFD_SET_DATA_VALUE_PTR(5U, c10_theta_des);
          _SFD_SET_DATA_VALUE_PTR(6U, c10_psi_des);
        }
      }
    } else {
      sf_debug_reset_current_state_configuration(sfGlobalDebugInstanceStruct,
        _Pointing_Cntrl_ActMachineNumber_,chartInstance->chartNumber,
        chartInstance->instanceNumber);
    }
  }
}

static const char* sf_get_instance_specialization(void)
{
  return "5CEQwcCvU9UTjPcN4XMysB";
}

static void sf_opaque_initialize_c10_Pointing_Cntrl_Act(void *chartInstanceVar)
{
  chart_debug_initialization(((SFc10_Pointing_Cntrl_ActInstanceStruct*)
    chartInstanceVar)->S,0);
  initialize_params_c10_Pointing_Cntrl_Act
    ((SFc10_Pointing_Cntrl_ActInstanceStruct*) chartInstanceVar);
  initialize_c10_Pointing_Cntrl_Act((SFc10_Pointing_Cntrl_ActInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_enable_c10_Pointing_Cntrl_Act(void *chartInstanceVar)
{
  enable_c10_Pointing_Cntrl_Act((SFc10_Pointing_Cntrl_ActInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_disable_c10_Pointing_Cntrl_Act(void *chartInstanceVar)
{
  disable_c10_Pointing_Cntrl_Act((SFc10_Pointing_Cntrl_ActInstanceStruct*)
    chartInstanceVar);
}

static void sf_opaque_gateway_c10_Pointing_Cntrl_Act(void *chartInstanceVar)
{
  sf_c10_Pointing_Cntrl_Act((SFc10_Pointing_Cntrl_ActInstanceStruct*)
    chartInstanceVar);
}

extern const mxArray* sf_internal_get_sim_state_c10_Pointing_Cntrl_Act(SimStruct*
  S)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_raw2high");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = (mxArray*) get_sim_state_c10_Pointing_Cntrl_Act
    ((SFc10_Pointing_Cntrl_ActInstanceStruct*)chartInfo->chartInstance);/* raw sim ctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c10_Pointing_Cntrl_Act();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_raw2high'.\n");
  }

  return plhs[0];
}

extern void sf_internal_set_sim_state_c10_Pointing_Cntrl_Act(SimStruct* S, const
  mxArray *st)
{
  ChartInfoStruct *chartInfo = (ChartInfoStruct*) ssGetUserData(S);
  mxArray *plhs[1] = { NULL };

  mxArray *prhs[4];
  int mxError = 0;
  prhs[0] = mxCreateString("chart_simctx_high2raw");
  prhs[1] = mxCreateDoubleScalar(ssGetSFuncBlockHandle(S));
  prhs[2] = mxDuplicateArray(st);      /* high level simctx */
  prhs[3] = (mxArray*) sf_get_sim_state_info_c10_Pointing_Cntrl_Act();/* state var info */
  mxError = sf_mex_call_matlab(1, plhs, 4, prhs, "sfprivate");
  mxDestroyArray(prhs[0]);
  mxDestroyArray(prhs[1]);
  mxDestroyArray(prhs[2]);
  mxDestroyArray(prhs[3]);
  if (mxError || plhs[0] == NULL) {
    sf_mex_error_message("Stateflow Internal Error: \nError calling 'chart_simctx_high2raw'.\n");
  }

  set_sim_state_c10_Pointing_Cntrl_Act((SFc10_Pointing_Cntrl_ActInstanceStruct*)
    chartInfo->chartInstance, mxDuplicateArray(plhs[0]));
  mxDestroyArray(plhs[0]);
}

static const mxArray* sf_opaque_get_sim_state_c10_Pointing_Cntrl_Act(SimStruct*
  S)
{
  return sf_internal_get_sim_state_c10_Pointing_Cntrl_Act(S);
}

static void sf_opaque_set_sim_state_c10_Pointing_Cntrl_Act(SimStruct* S, const
  mxArray *st)
{
  sf_internal_set_sim_state_c10_Pointing_Cntrl_Act(S, st);
}

static void sf_opaque_terminate_c10_Pointing_Cntrl_Act(void *chartInstanceVar)
{
  if (chartInstanceVar!=NULL) {
    SimStruct *S = ((SFc10_Pointing_Cntrl_ActInstanceStruct*) chartInstanceVar
      )->S;
    if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
      sf_clear_rtw_identifier(S);
      unload_Pointing_Cntrl_Act_optimization_info();
    }

    finalize_c10_Pointing_Cntrl_Act((SFc10_Pointing_Cntrl_ActInstanceStruct*)
      chartInstanceVar);
    utFree((void *)chartInstanceVar);
    ssSetUserData(S,NULL);
  }
}

static void sf_opaque_init_subchart_simstructs(void *chartInstanceVar)
{
  initSimStructsc10_Pointing_Cntrl_Act((SFc10_Pointing_Cntrl_ActInstanceStruct*)
    chartInstanceVar);
}

extern unsigned int sf_machine_global_initializer_called(void);
static void mdlProcessParameters_c10_Pointing_Cntrl_Act(SimStruct *S)
{
  int i;
  for (i=0;i<ssGetNumRunTimeParams(S);i++) {
    if (ssGetSFcnParamTunable(S,i)) {
      ssUpdateDlgParamAsRunTimeParam(S,i);
    }
  }

  if (sf_machine_global_initializer_called()) {
    initialize_params_c10_Pointing_Cntrl_Act
      ((SFc10_Pointing_Cntrl_ActInstanceStruct*)(((ChartInfoStruct *)
         ssGetUserData(S))->chartInstance));
  }
}

static void mdlSetWorkWidths_c10_Pointing_Cntrl_Act(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S) || sim_mode_is_external(S)) {
    mxArray *infoStruct = load_Pointing_Cntrl_Act_optimization_info();
    int_T chartIsInlinable =
      (int_T)sf_is_chart_inlinable(S,sf_get_instance_specialization(),infoStruct,
      10);
    ssSetStateflowIsInlinable(S,chartIsInlinable);
    ssSetRTWCG(S,sf_rtw_info_uint_prop(S,sf_get_instance_specialization(),
                infoStruct,10,"RTWCG"));
    ssSetEnableFcnIsTrivial(S,1);
    ssSetDisableFcnIsTrivial(S,1);
    ssSetNotMultipleInlinable(S,sf_rtw_info_uint_prop(S,
      sf_get_instance_specialization(),infoStruct,10,
      "gatewayCannotBeInlinedMultipleTimes"));
    sf_update_buildInfo(S,sf_get_instance_specialization(),infoStruct,10);
    if (chartIsInlinable) {
      ssSetInputPortOptimOpts(S, 0, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 1, SS_REUSABLE_AND_LOCAL);
      ssSetInputPortOptimOpts(S, 2, SS_REUSABLE_AND_LOCAL);
      sf_mark_chart_expressionable_inputs(S,sf_get_instance_specialization(),
        infoStruct,10,3);
      sf_mark_chart_reusable_outputs(S,sf_get_instance_specialization(),
        infoStruct,10,4);
    }

    {
      unsigned int outPortIdx;
      for (outPortIdx=1; outPortIdx<=4; ++outPortIdx) {
        ssSetOutputPortOptimizeInIR(S, outPortIdx, 1U);
      }
    }

    {
      unsigned int inPortIdx;
      for (inPortIdx=0; inPortIdx < 3; ++inPortIdx) {
        ssSetInputPortOptimizeInIR(S, inPortIdx, 1U);
      }
    }

    sf_set_rtw_dwork_info(S,sf_get_instance_specialization(),infoStruct,10);
    ssSetHasSubFunctions(S,!(chartIsInlinable));
  } else {
  }

  ssSetOptions(S,ssGetOptions(S)|SS_OPTION_WORKS_WITH_CODE_REUSE);
  ssSetChecksum0(S,(288827196U));
  ssSetChecksum1(S,(3591252830U));
  ssSetChecksum2(S,(1871629825U));
  ssSetChecksum3(S,(124524746U));
  ssSetmdlDerivatives(S, NULL);
  ssSetExplicitFCSSCtrl(S,1);
  ssSupportsMultipleExecInstances(S,1);
}

static void mdlRTW_c10_Pointing_Cntrl_Act(SimStruct *S)
{
  if (sim_mode_is_rtw_gen(S)) {
    ssWriteRTWStrParam(S, "StateflowChartType", "Embedded MATLAB");
  }
}

static void mdlStart_c10_Pointing_Cntrl_Act(SimStruct *S)
{
  SFc10_Pointing_Cntrl_ActInstanceStruct *chartInstance;
  chartInstance = (SFc10_Pointing_Cntrl_ActInstanceStruct *)utMalloc(sizeof
    (SFc10_Pointing_Cntrl_ActInstanceStruct));
  memset(chartInstance, 0, sizeof(SFc10_Pointing_Cntrl_ActInstanceStruct));
  if (chartInstance==NULL) {
    sf_mex_error_message("Could not allocate memory for chart instance.");
  }

  chartInstance->chartInfo.chartInstance = chartInstance;
  chartInstance->chartInfo.isEMLChart = 1;
  chartInstance->chartInfo.chartInitialized = 0;
  chartInstance->chartInfo.sFunctionGateway =
    sf_opaque_gateway_c10_Pointing_Cntrl_Act;
  chartInstance->chartInfo.initializeChart =
    sf_opaque_initialize_c10_Pointing_Cntrl_Act;
  chartInstance->chartInfo.terminateChart =
    sf_opaque_terminate_c10_Pointing_Cntrl_Act;
  chartInstance->chartInfo.enableChart = sf_opaque_enable_c10_Pointing_Cntrl_Act;
  chartInstance->chartInfo.disableChart =
    sf_opaque_disable_c10_Pointing_Cntrl_Act;
  chartInstance->chartInfo.getSimState =
    sf_opaque_get_sim_state_c10_Pointing_Cntrl_Act;
  chartInstance->chartInfo.setSimState =
    sf_opaque_set_sim_state_c10_Pointing_Cntrl_Act;
  chartInstance->chartInfo.getSimStateInfo =
    sf_get_sim_state_info_c10_Pointing_Cntrl_Act;
  chartInstance->chartInfo.zeroCrossings = NULL;
  chartInstance->chartInfo.outputs = NULL;
  chartInstance->chartInfo.derivatives = NULL;
  chartInstance->chartInfo.mdlRTW = mdlRTW_c10_Pointing_Cntrl_Act;
  chartInstance->chartInfo.mdlStart = mdlStart_c10_Pointing_Cntrl_Act;
  chartInstance->chartInfo.mdlSetWorkWidths =
    mdlSetWorkWidths_c10_Pointing_Cntrl_Act;
  chartInstance->chartInfo.extModeExec = NULL;
  chartInstance->chartInfo.restoreLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.restoreBeforeLastMajorStepConfiguration = NULL;
  chartInstance->chartInfo.storeCurrentConfiguration = NULL;
  chartInstance->S = S;
  ssSetUserData(S,(void *)(&(chartInstance->chartInfo)));/* register the chart instance with simstruct */
  init_dsm_address_info(chartInstance);
  if (!sim_mode_is_rtw_gen(S)) {
  }

  sf_opaque_init_subchart_simstructs(chartInstance->chartInfo.chartInstance);
  chart_debug_initialization(S,1);
}

void c10_Pointing_Cntrl_Act_method_dispatcher(SimStruct *S, int_T method, void
  *data)
{
  switch (method) {
   case SS_CALL_MDL_START:
    mdlStart_c10_Pointing_Cntrl_Act(S);
    break;

   case SS_CALL_MDL_SET_WORK_WIDTHS:
    mdlSetWorkWidths_c10_Pointing_Cntrl_Act(S);
    break;

   case SS_CALL_MDL_PROCESS_PARAMETERS:
    mdlProcessParameters_c10_Pointing_Cntrl_Act(S);
    break;

   default:
    /* Unhandled method */
    sf_mex_error_message("Stateflow Internal Error:\n"
                         "Error calling c10_Pointing_Cntrl_Act_method_dispatcher.\n"
                         "Can't handle method %d.\n", method);
    break;
  }
}
