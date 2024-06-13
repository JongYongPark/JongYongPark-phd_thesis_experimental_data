/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * heapsort.c
 *
 * Code generation for function 'heapsort'
 *
 */

/* Include files */
#include "heapsort.h"
#include "cellstr_sort.h"
#include "eml_int_forloop_overflow_check.h"
#include "myIncrLearn_mex_data.h"
#include "myIncrLearn_mex_types.h"
#include "rt_nonfinite.h"

/* Variable Definitions */
static emlrtRSInfo ud_emlrtRSI = {
    19,         /* lineNo */
    "heapsort", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\shared\\coder\\coder\\lib\\+coder\\+"
    "internal\\heapsort.m" /* pathName */
};

static emlrtRSInfo vd_emlrtRSI = {
    20,         /* lineNo */
    "heapsort", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\shared\\coder\\coder\\lib\\+coder\\+"
    "internal\\heapsort.m" /* pathName */
};

static emlrtRSInfo wd_emlrtRSI = {
    26,         /* lineNo */
    "heapsort", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\shared\\coder\\coder\\lib\\+coder\\+"
    "internal\\heapsort.m" /* pathName */
};

static emlrtRSInfo xd_emlrtRSI = {
    35,         /* lineNo */
    "makeHeap", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\shared\\coder\\coder\\lib\\+coder\\+"
    "internal\\heapsort.m" /* pathName */
};

static emlrtRSInfo yd_emlrtRSI = {
    56,        /* lineNo */
    "heapify", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\shared\\coder\\coder\\lib\\+coder\\+"
    "internal\\heapsort.m" /* pathName */
};

static emlrtRSInfo ae_emlrtRSI = {
    60,        /* lineNo */
    "heapify", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\shared\\coder\\coder\\lib\\+coder\\+"
    "internal\\heapsort.m" /* pathName */
};

static emlrtRSInfo be_emlrtRSI = {
    72,        /* lineNo */
    "heapify", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\shared\\coder\\coder\\lib\\+coder\\+"
    "internal\\heapsort.m" /* pathName */
};

/* Function Declarations */
static void heapify(const emlrtStack *sp, emxArray_int32_T *x, int32_T idx,
                    int32_T xstart, int32_T xend,
                    const emxArray_cell_wrap_1 *cmp_workspace_c);

/* Function Definitions */
static void heapify(const emlrtStack *sp, emxArray_int32_T *x, int32_T idx,
                    int32_T xstart, int32_T xend,
                    const emxArray_cell_wrap_1 *cmp_workspace_c)
{
  emlrtStack b_st;
  emlrtStack st;
  int32_T extremum;
  int32_T extremumIdx;
  int32_T leftIdx;
  int32_T *x_data;
  boolean_T changed;
  boolean_T exitg1;
  boolean_T varargout_1;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  x_data = x->data;
  changed = true;
  extremumIdx = (idx + xstart) - 2;
  leftIdx = ((idx << 1) + xstart) - 1;
  exitg1 = false;
  while ((!exitg1) && (leftIdx < xend)) {
    int32_T cmpIdx;
    int32_T xcmp;
    changed = false;
    extremum = x_data[extremumIdx];
    cmpIdx = leftIdx - 1;
    xcmp = x_data[leftIdx - 1];
    st.site = &yd_emlrtRSI;
    b_st.site = &gb_emlrtRSI;
    varargout_1 = cellstr_sort_anonFcn1(&b_st, cmp_workspace_c,
                                        x_data[leftIdx - 1], x_data[leftIdx]);
    if (varargout_1) {
      cmpIdx = leftIdx;
      xcmp = x_data[leftIdx];
    }
    st.site = &ae_emlrtRSI;
    b_st.site = &gb_emlrtRSI;
    varargout_1 = cellstr_sort_anonFcn1(&b_st, cmp_workspace_c,
                                        x_data[extremumIdx], xcmp);
    if (varargout_1) {
      x_data[extremumIdx] = xcmp;
      x_data[cmpIdx] = extremum;
      extremumIdx = cmpIdx;
      leftIdx = ((((cmpIdx - xstart) + 2) << 1) + xstart) - 1;
      changed = true;
    } else {
      exitg1 = true;
    }
  }
  if (changed && (leftIdx <= xend)) {
    extremum = x_data[extremumIdx];
    st.site = &be_emlrtRSI;
    b_st.site = &gb_emlrtRSI;
    varargout_1 = cellstr_sort_anonFcn1(
        &b_st, cmp_workspace_c, x_data[extremumIdx], x_data[leftIdx - 1]);
    if (varargout_1) {
      x_data[extremumIdx] = x_data[leftIdx - 1];
      x_data[leftIdx - 1] = extremum;
    }
  }
}

void b_heapsort(const emlrtStack *sp, emxArray_int32_T *x, int32_T xstart,
                int32_T xend, const emxArray_cell_wrap_1 *cmp_workspace_c)
{
  emlrtStack b_st;
  emlrtStack st;
  int32_T idx;
  int32_T k;
  int32_T n;
  int32_T *x_data;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  x_data = x->data;
  n = xend - xstart;
  st.site = &ud_emlrtRSI;
  for (idx = n + 1; idx >= 1; idx--) {
    b_st.site = &xd_emlrtRSI;
    heapify(&b_st, x, idx, xstart, xend, cmp_workspace_c);
    x_data = x->data;
  }
  st.site = &vd_emlrtRSI;
  if (n > 2147483646) {
    b_st.site = &x_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }
  for (k = 0; k < n; k++) {
    int32_T t;
    idx = (xend - k) - 1;
    t = x_data[idx];
    x_data[idx] = x_data[xstart - 1];
    x_data[xstart - 1] = t;
    st.site = &wd_emlrtRSI;
    heapify(&st, x, 1, xstart, (xend - k) - 1, cmp_workspace_c);
    x_data = x->data;
  }
}

/* End of code generation (heapsort.c) */
