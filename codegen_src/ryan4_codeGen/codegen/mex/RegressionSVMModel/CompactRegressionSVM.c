/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * CompactRegressionSVM.c
 *
 * Code generation for function 'CompactRegressionSVM'
 *
 */

/* Include files */
#include "CompactRegressionSVM.h"
#include "RegressionSVMModel_types.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"

/* Variable Definitions */
static emlrtRSInfo c_emlrtRSI = {
    189,                           /* lineNo */
    "CompactRegressionSVM/update", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\stats\\classreg\\+classreg\\+learning\\+"
    "coder\\+regr\\CompactRegressionSVM.m" /* pathName */
};

static emlrtRSInfo d_emlrtRSI = {
    469,                    /* lineNo */
    "CompactSVM/updateSVM", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\stats\\classreg\\+classreg\\+learning\\+"
    "coder\\+model\\CompactSVM.m" /* pathName */
};

static emlrtRSInfo e_emlrtRSI = {
    490,                    /* lineNo */
    "CompactSVM/updateSVM", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\stats\\classreg\\+classreg\\+learning\\+"
    "coder\\+model\\CompactSVM.m" /* pathName */
};

static emlrtRSInfo f_emlrtRSI = {
    523,                    /* lineNo */
    "CompactSVM/updateSVM", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\stats\\classreg\\+classreg\\+learning\\+"
    "coder\\+model\\CompactSVM.m" /* pathName */
};

static emlrtRSInfo g_emlrtRSI = {
    92,                   /* lineNo */
    "validateattributes", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\eml\\lib\\matlab\\lang\\validateattributes"
    ".m" /* pathName */
};

static emlrtRTEInfo d_emlrtRTEI = {
    14,               /* lineNo */
    37,               /* colNo */
    "validatenonnan", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "valattr\\validatenonnan.m" /* pName */
};

static emlrtRTEInfo e_emlrtRTEI = {
    14,                 /* lineNo */
    37,                 /* colNo */
    "validatepositive", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "valattr\\validatepositive.m" /* pName */
};

/* Function Definitions */
void CompactRegressionSVM_update(const emlrtStack *sp,
                                 c_classreg_learning_regr_Compac *obj,
                                 const real_T varargin_1_Alpha[75],
                                 const real_T varargin_1_SupportVectors[150],
                                 real_T varargin_1_Scale,
                                 real_T varargin_1_Bias)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  int32_T i;
  int32_T k;
  boolean_T exitg1;
  boolean_T p;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &c_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  b_st.site = &d_emlrtRSI;
  c_st.site = &g_emlrtRSI;
  p = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 75)) {
    if (!muDoubleScalarIsNaN(varargin_1_Alpha[k])) {
      k++;
    } else {
      p = false;
      exitg1 = true;
    }
  }
  if (!p) {
    emlrtErrorWithMessageIdR2018a(
        &c_st, &d_emlrtRTEI, "Coder:toolbox:ValidateattributesexpectedNonNaN",
        "MATLAB:CompactSVM:expectedNonNaN", 3, 4, 5, "Alpha");
  }
  for (i = 0; i < 75; i++) {
    obj->Alpha[i] = varargin_1_Alpha[i];
    k = i << 1;
    obj->SupportVectorsT[k] = varargin_1_SupportVectors[i];
    obj->SupportVectorsT[k + 1] = varargin_1_SupportVectors[i + 75];
  }
  b_st.site = &e_emlrtRSI;
  c_st.site = &g_emlrtRSI;
  if (muDoubleScalarIsNaN(varargin_1_Bias)) {
    emlrtErrorWithMessageIdR2018a(
        &c_st, &d_emlrtRTEI, "Coder:toolbox:ValidateattributesexpectedNonNaN",
        "MATLAB:CompactSVM:expectedNonNaN", 3, 4, 4, "Bias");
  }
  obj->Bias = varargin_1_Bias;
  b_st.site = &f_emlrtRSI;
  c_st.site = &g_emlrtRSI;
  if (varargin_1_Scale <= 0.0) {
    emlrtErrorWithMessageIdR2018a(
        &c_st, &e_emlrtRTEI, "Coder:toolbox:ValidateattributesexpectedPositive",
        "MATLAB:CompactSVM:expectedPositive", 3, 4, 5, "Scale");
  }
  c_st.site = &g_emlrtRSI;
  if (muDoubleScalarIsNaN(varargin_1_Scale)) {
    emlrtErrorWithMessageIdR2018a(
        &c_st, &d_emlrtRTEI, "Coder:toolbox:ValidateattributesexpectedNonNaN",
        "MATLAB:CompactSVM:expectedNonNaN", 3, 4, 5, "Scale");
  }
  obj->Scale = varargin_1_Scale;
}

/* End of code generation (CompactRegressionSVM.c) */
