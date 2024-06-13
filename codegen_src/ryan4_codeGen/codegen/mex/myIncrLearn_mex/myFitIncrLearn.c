/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * myFitIncrLearn.c
 *
 * Code generation for function 'myFitIncrLearn'
 *
 */

/* Include files */
#include "myFitIncrLearn.h"
#include "Learner.h"
#include "myIncrLearn_mex_data.h"
#include "myIncrLearn_mex_emxutil.h"
#include "myIncrLearn_mex_types.h"
#include "rt_nonfinite.h"

/* Variable Definitions */
static emlrtRSInfo lg_emlrtRSI = {
    3,                /* lineNo */
    "myFitIncrLearn", /* fcnName */
    "C:\\nobackup\\_phd_work\\_battery_soh\\_matlab_battery\\_mywork\\_"
    "latest\\ryan4_codeGen\\myFitIncrLearn.m" /* pathName */
};

static emlrtRSInfo mg_emlrtRSI = {
    67,                                    /* lineNo */
    "incrementalClassificationLinear/fit", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\stats\\incremental\\+incremental\\+"
    "coder\\incrementalClassificationLinear.m" /* pathName */
};

static emlrtRSInfo ng_emlrtRSI = {
    131,           /* lineNo */
    "Learner/fit", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\stats\\incremental\\+incremental\\+"
    "coder\\Learner.m" /* pathName */
};

static emlrtRSInfo og_emlrtRSI = {
    423,                  /* lineNo */
    "Learner/fitLearner", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\stats\\incremental\\+incremental\\+"
    "coder\\Learner.m" /* pathName */
};

static emlrtRSInfo pg_emlrtRSI = {
    424,                  /* lineNo */
    "Learner/fitLearner", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\stats\\incremental\\+incremental\\+"
    "coder\\Learner.m" /* pathName */
};

static emlrtRTEInfo fd_emlrtRTEI = {
    767,       /* lineNo */
    9,         /* colNo */
    "Learner", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\stats\\incremental\\+incremental\\+"
    "coder\\Learner.m" /* pName */
};

/* Function Definitions */
void myFitIncrLearn(myIncrLearn_mexStackData *SD, const emlrtStack *sp,
                    e_incrementalClassificationLine *incrementalModel,
                    const emxArray_real_T *X, const c_categorical *Y)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack st;
  emxArray_real_T *r;
  real_T *r1;
  int32_T i;
  int32_T loop_ub;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  /*  MYFITINCRLEARN Fit model to new data */
  st.site = &lg_emlrtRSI;
  b_st.site = &mg_emlrtRSI;
  c_st.site = &ng_emlrtRSI;
  d_st.site = &og_emlrtRSI;
  e_st.site = &e_emlrtRSI;
  if ((uint32_T)X->size[0] != (uint32_T)Y->codes.size[0]) {
    emlrtErrorWithMessageIdR2018a(
        &e_st, &m_emlrtRTEI,
        "stats:classreg:learning:FullClassificationRegressionModel:"
        "prepareDataCR:InputSizeMismatch",
        "stats:classreg:learning:FullClassificationRegressionModel:"
        "prepareDataCR:InputSizeMismatch",
        0);
  }
  emxInit_real_T(&e_st, &r, 1, &fd_emlrtRTEI);
  i = r->size[0];
  r->size[0] = X->size[0];
  emxEnsureCapacity_real_T(&c_st, r, i, &fd_emlrtRTEI);
  r1 = r->data;
  loop_ub = X->size[0];
  for (i = 0; i < loop_ub; i++) {
    r1[i] = 1.0;
  }
  d_st.site = &pg_emlrtRSI;
  Learner_fitWithoutValidation(SD, &d_st, incrementalModel, X, Y, r);
  emxFree_real_T(sp, &r);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

/* End of code generation (myFitIncrLearn.c) */
