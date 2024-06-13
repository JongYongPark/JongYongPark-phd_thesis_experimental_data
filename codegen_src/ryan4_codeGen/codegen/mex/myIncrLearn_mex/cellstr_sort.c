/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * cellstr_sort.c
 *
 * Code generation for function 'cellstr_sort'
 *
 */

/* Include files */
#include "cellstr_sort.h"
#include "myIncrLearn_mex_data.h"
#include "myIncrLearn_mex_types.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"

/* Variable Definitions */
static emlrtBCInfo mc_emlrtBCI = {
    -1,           /* iFirst */
    -1,           /* iLast */
    35,           /* lineNo */
    8,            /* colNo */
    "",           /* aName */
    "sortidxCmp", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\matlab\\datatypes\\shared\\codegen\\+"
    "matlab\\+internal\\+coder\\+datatypes\\cellstr_sort.m", /* pName */
    0                                                        /* checkKind */
};

static emlrtBCInfo nc_emlrtBCI = {
    -1,           /* iFirst */
    -1,           /* iLast */
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
boolean_T cellstr_sort_anonFcn1(const emlrtStack *sp,
                                const emxArray_cell_wrap_1 *c, int32_T i,
                                int32_T j)
{
  const cell_wrap_1 *c_data;
  emlrtStack st;
  int32_T k;
  int32_T n;
  boolean_T varargout_1;
  st.prev = sp;
  st.tls = sp->tls;
  c_data = c->data;
  st.site = &hb_emlrtRSI;
  if ((i - 1 < 0) || (i - 1 > c->size[0] - 1)) {
    emlrtDynamicBoundsCheckR2012b(i - 1, 0, c->size[0] - 1, &mc_emlrtBCI, &st);
  }
  if ((j - 1 < 0) || (j - 1 > c->size[0] - 1)) {
    emlrtDynamicBoundsCheckR2012b(j - 1, 0, c->size[0] - 1, &nc_emlrtBCI, &st);
  }
  n = (int32_T)muDoubleScalarMin(c_data[i - 1].f1->size[1],
                                 c_data[j - 1].f1->size[1]);
  varargout_1 = (c_data[i - 1].f1->size[1] < c_data[j - 1].f1->size[1]);
  k = 0;
  int32_T exitg1;
  do {
    exitg1 = 0;
    if (k <= n - 1) {
      int32_T b_i;
      b_i = c_data[i - 1].f1->size[1];
      if (k + 1 > b_i) {
        emlrtDynamicBoundsCheckR2012b(k + 1, 1, b_i, &kc_emlrtBCI, &st);
      }
      b_i = c_data[j - 1].f1->size[1];
      if (k + 1 > b_i) {
        emlrtDynamicBoundsCheckR2012b(k + 1, 1, b_i, &lc_emlrtBCI, &st);
      }
      if (c_data[i - 1].f1->data[k] != c_data[j - 1].f1->data[k]) {
        varargout_1 = (c_data[i - 1].f1->data[k] < c_data[j - 1].f1->data[k]);
        exitg1 = 1;
      } else {
        k++;
      }
    } else {
      if (c_data[i - 1].f1->size[1] == c_data[j - 1].f1->size[1]) {
        varargout_1 = (i < j);
      }
      exitg1 = 1;
    }
  } while (exitg1 == 0);
  return varargout_1;
}

/* End of code generation (cellstr_sort.c) */
