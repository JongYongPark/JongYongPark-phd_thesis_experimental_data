/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * validateattributes.c
 *
 * Code generation for function 'validateattributes'
 *
 */

/* Include files */
#include "validateattributes.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"

/* Variable Definitions */
static emlrtRSInfo w_emlrtRSI = {
    92,                   /* lineNo */
    "validateattributes", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\eml\\lib\\matlab\\lang\\validateattributes"
    ".m" /* pathName */
};

static emlrtRTEInfo emlrtRTEI = {
    10,              /* lineNo */
    23,              /* colNo */
    "validatenrows", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "valattr\\validatenrows.m" /* pName */
};

static emlrtRTEInfo b_emlrtRTEI = {
    18,              /* lineNo */
    23,              /* colNo */
    "validatenrows", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "valattr\\validatenrows.m" /* pName */
};

static emlrtRTEInfo c_emlrtRTEI = {
    13,                 /* lineNo */
    37,                 /* colNo */
    "validatenonempty", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "valattr\\validatenonempty.m" /* pName */
};

/* Function Definitions */
void validateattributes(const emlrtStack *sp, const int32_T a_codes_size[2],
                        real_T attributesMixed_f2)
{
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &w_emlrtRSI;
  if (!(muDoubleScalarFloor(attributesMixed_f2) == attributesMixed_f2)) {
    emlrtErrorWithMessageIdR2018a(&st, &emlrtRTEI,
                                  "Coder:toolbox:ValidateattributesBadNrows",
                                  "MATLAB:validateattributes:badnrows", 0);
  }
  if (!(a_codes_size[0] == attributesMixed_f2)) {
    emlrtErrorWithMessageIdR2018a(
        &st, &b_emlrtRTEI, "Coder:toolbox:ValidateattributesincorrectNumrows",
        "MATLAB:ClassificationModel:incorrectNumrows", 5, 4, 6, "Labels", 6,
        attributesMixed_f2);
  }
  st.site = &w_emlrtRSI;
  if ((a_codes_size[0] == 0) || (a_codes_size[1] == 0)) {
    emlrtErrorWithMessageIdR2018a(
        &st, &c_emlrtRTEI, "Coder:toolbox:ValidateattributesexpectedNonempty",
        "MATLAB:ClassificationModel:expectedNonempty", 3, 4, 6, "Labels");
  }
}

/* End of code generation (validateattributes.c) */
