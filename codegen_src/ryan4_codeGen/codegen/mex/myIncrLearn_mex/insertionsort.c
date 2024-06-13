/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * insertionsort.c
 *
 * Code generation for function 'insertionsort'
 *
 */

/* Include files */
#include "insertionsort.h"
#include "cellstr_sort.h"
#include "eml_int_forloop_overflow_check.h"
#include "myIncrLearn_mex_data.h"
#include "myIncrLearn_mex_types.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"

/* Variable Definitions */
static emlrtRSInfo eb_emlrtRSI = {
    18,              /* lineNo */
    "insertionsort", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\shared\\coder\\coder\\lib\\+coder\\+"
    "internal\\insertionsort.m" /* pathName */
};

static emlrtRSInfo fb_emlrtRSI = {
    21,              /* lineNo */
    "insertionsort", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\shared\\coder\\coder\\lib\\+coder\\+"
    "internal\\insertionsort.m" /* pathName */
};

static emlrtBCInfo sg_emlrtBCI = {
    0,            /* iFirst */
    1,            /* iLast */
    35,           /* lineNo */
    8,            /* colNo */
    "",           /* aName */
    "sortidxCmp", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\matlab\\datatypes\\shared\\codegen\\+"
    "matlab\\+internal\\+coder\\+datatypes\\cellstr_sort.m", /* pName */
    0                                                        /* checkKind */
};

static emlrtBCInfo tg_emlrtBCI = {
    0,            /* iFirst */
    1,            /* iLast */
    36,           /* lineNo */
    8,            /* colNo */
    "",           /* aName */
    "sortidxCmp", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\matlab\\datatypes\\shared\\codegen\\+"
    "matlab\\+internal\\+coder\\+datatypes\\cellstr_sort.m", /* pName */
    0                                                        /* checkKind */
};

/* Function Definitions */
void b_insertionsort(const emlrtStack *sp, int32_T x[2],
                     const cell_wrap_1 cmp_workspace_c[2])
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  int32_T i;
  int32_T idx;
  int32_T j;
  int32_T k;
  int32_T n;
  int32_T xc;
  boolean_T varargout_1;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &eb_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  xc = x[1] - 1;
  idx = 1;
  st.site = &fb_emlrtRSI;
  j = x[0];
  b_st.site = &gb_emlrtRSI;
  c_st.site = &hb_emlrtRSI;
  if ((xc < 0) || (xc > 1)) {
    emlrtDynamicBoundsCheckR2012b(xc, 0, 1, &sg_emlrtBCI, &c_st);
  }
  i = x[0] - 1;
  if ((i < 0) || (i > 1)) {
    emlrtDynamicBoundsCheckR2012b(i, 0, 1, &tg_emlrtBCI, &c_st);
  }
  n = (int32_T)muDoubleScalarMin(cmp_workspace_c[xc].f1->size[1],
                                 cmp_workspace_c[x[0] - 1].f1->size[1]);
  varargout_1 =
      (cmp_workspace_c[xc].f1->size[1] < cmp_workspace_c[x[0] - 1].f1->size[1]);
  k = 0;
  int32_T exitg1;
  do {
    exitg1 = 0;
    if (k <= n - 1) {
      i = cmp_workspace_c[xc].f1->size[1];
      if (k + 1 > i) {
        emlrtDynamicBoundsCheckR2012b(k + 1, 1, i, &kc_emlrtBCI, &c_st);
      }
      i = cmp_workspace_c[j - 1].f1->size[1];
      if (k + 1 > i) {
        emlrtDynamicBoundsCheckR2012b(k + 1, 1, i, &lc_emlrtBCI, &c_st);
      }
      if (cmp_workspace_c[xc].f1->data[k] !=
          cmp_workspace_c[x[0] - 1].f1->data[k]) {
        varargout_1 = (cmp_workspace_c[xc].f1->data[k] <
                       cmp_workspace_c[x[0] - 1].f1->data[k]);
        exitg1 = 1;
      } else {
        k++;
      }
    } else {
      if (cmp_workspace_c[xc].f1->size[1] ==
          cmp_workspace_c[j - 1].f1->size[1]) {
        varargout_1 = (xc + 1 < j);
      }
      exitg1 = 1;
    }
  } while (exitg1 == 0);
  if (varargout_1) {
    x[1] = x[0];
    idx = 0;
  }
  x[idx] = xc + 1;
}

void insertionsort(const emlrtStack *sp, emxArray_int32_T *x, int32_T xstart,
                   int32_T xend, const emxArray_cell_wrap_1 *cmp_workspace_c)
{
  emlrtStack b_st;
  emlrtStack st;
  int32_T a;
  int32_T k;
  int32_T *x_data;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  x_data = x->data;
  a = xstart + 1;
  st.site = &eb_emlrtRSI;
  if ((xstart + 1 <= xend) && (xend > 2147483646)) {
    b_st.site = &x_emlrtRSI;
    check_forloop_overflow_error(&b_st);
  }
  for (k = a; k <= xend; k++) {
    int32_T idx;
    int32_T xc;
    boolean_T exitg1;
    xc = x_data[k - 1];
    idx = k - 1;
    exitg1 = false;
    while ((!exitg1) && (idx >= xstart)) {
      boolean_T varargout_1;
      st.site = &fb_emlrtRSI;
      b_st.site = &gb_emlrtRSI;
      varargout_1 =
          cellstr_sort_anonFcn1(&b_st, cmp_workspace_c, xc, x_data[idx - 1]);
      if (varargout_1) {
        x_data[idx] = x_data[idx - 1];
        idx--;
      } else {
        exitg1 = true;
      }
    }
    x_data[idx] = xc;
  }
}

/* End of code generation (insertionsort.c) */
