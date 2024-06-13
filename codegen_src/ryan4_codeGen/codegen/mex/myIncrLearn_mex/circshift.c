/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * circshift.c
 *
 * Code generation for function 'circshift'
 *
 */

/* Include files */
#include "circshift.h"
#include "eml_int_forloop_overflow_check.h"
#include "myIncrLearn_mex_data.h"
#include "rt_nonfinite.h"
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo eg_emlrtRSI = {
    42,          /* lineNo */
    "circshift", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\eml\\lib\\matlab\\elmat\\circshift.m" /* pathName
                                                                            */
};

static emlrtRSInfo fg_emlrtRSI = {
    69,                     /* lineNo */
    "circshift_single_dim", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\eml\\lib\\matlab\\elmat\\circshift.m" /* pathName
                                                                            */
};

static emlrtRSInfo gg_emlrtRSI = {
    133,              /* lineNo */
    "circshift_core", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\eml\\lib\\matlab\\elmat\\circshift.m" /* pathName
                                                                            */
};

static emlrtRSInfo hg_emlrtRSI = {
    129,              /* lineNo */
    "circshift_core", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\eml\\lib\\matlab\\elmat\\circshift.m" /* pathName
                                                                            */
};

static emlrtRSInfo ig_emlrtRSI = {
    125,              /* lineNo */
    "circshift_core", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\eml\\lib\\matlab\\elmat\\circshift.m" /* pathName
                                                                            */
};

static emlrtRSInfo jg_emlrtRSI = {
    120,              /* lineNo */
    "circshift_core", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\eml\\lib\\matlab\\elmat\\circshift.m" /* pathName
                                                                            */
};

static emlrtRSInfo kg_emlrtRSI = {
    112,              /* lineNo */
    "circshift_core", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\eml\\lib\\matlab\\elmat\\circshift.m" /* pathName
                                                                            */
};

/* Function Definitions */
void circshift(const emlrtStack *sp, real_T a[200], int32_T p)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack st;
  real_T a__1[100];
  int32_T k;
  int32_T ns;
  boolean_T shiftright;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &eg_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  ns = -p;
  shiftright = false;
  if (-p > 100) {
    ns = p + 200;
    shiftright = true;
  }
  b_st.site = &fg_emlrtRSI;
  memset(&a__1[0], 0, 100U * sizeof(real_T));
  if (shiftright) {
    int32_T b;
    c_st.site = &kg_emlrtRSI;
    for (k = 0; k < ns; k++) {
      a__1[k] = a[(k - ns) + 200];
    }
    b = ns + 1;
    for (k = 200; k >= b; k--) {
      a[k - 1] = a[(k - ns) - 1];
    }
    c_st.site = &jg_emlrtRSI;
    memcpy(&a[0], &a__1[0], ns * sizeof(real_T));
  } else {
    int32_T b;
    c_st.site = &ig_emlrtRSI;
    memcpy(&a__1[0], &a[0], ns * sizeof(real_T));
    b = 199 - ns;
    c_st.site = &hg_emlrtRSI;
    if (200 - ns > 2147483646) {
      d_st.site = &x_emlrtRSI;
      check_forloop_overflow_error(&d_st);
    }
    for (k = 0; k <= b; k++) {
      a[k] = a[k + ns];
    }
    c_st.site = &gg_emlrtRSI;
    for (k = 0; k < ns; k++) {
      a[(k - ns) + 200] = a__1[k];
    }
  }
}

/* End of code generation (circshift.c) */
