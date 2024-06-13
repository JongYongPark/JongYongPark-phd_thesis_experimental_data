/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * find.c
 *
 * Code generation for function 'find'
 *
 */

/* Include files */
#include "find.h"
#include "indexShapeCheck.h"
#include "myIncrLearn_mex_emxutil.h"
#include "myIncrLearn_mex_types.h"
#include "rt_nonfinite.h"

/* Variable Definitions */
static emlrtRSInfo yb_emlrtRSI = {
    144,        /* lineNo */
    "eml_find", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\eml\\lib\\matlab\\elmat\\find.m" /* pathName
                                                                       */
};

static emlrtRSInfo ac_emlrtRSI = {
    402,                  /* lineNo */
    "find_first_indices", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\eml\\lib\\matlab\\elmat\\find.m" /* pathName
                                                                       */
};

static emlrtRTEInfo g_emlrtRTEI = {
    392,                  /* lineNo */
    1,                    /* colNo */
    "find_first_indices", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\eml\\lib\\matlab\\elmat\\find.m" /* pName
                                                                       */
};

static emlrtRTEInfo mb_emlrtRTEI = {
    369,    /* lineNo */
    24,     /* colNo */
    "find", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\eml\\lib\\matlab\\elmat\\find.m" /* pName
                                                                       */
};

static emlrtRTEInfo nb_emlrtRTEI = {
    144,    /* lineNo */
    9,      /* colNo */
    "find", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\eml\\lib\\matlab\\elmat\\find.m" /* pName
                                                                       */
};

/* Function Definitions */
void b_eml_find(const emlrtStack *sp, const boolean_T x_data[], int32_T x_size,
                emxArray_int32_T *i)
{
  emlrtStack b_st;
  emlrtStack st;
  int32_T b_i;
  int32_T idx;
  int32_T ii;
  int32_T *i_data;
  boolean_T exitg1;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &yb_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  idx = 0;
  b_i = i->size[0];
  i->size[0] = x_size;
  emxEnsureCapacity_int32_T(&st, i, b_i, &mb_emlrtRTEI);
  i_data = i->data;
  ii = 0;
  exitg1 = false;
  while ((!exitg1) && (ii <= x_size - 1)) {
    if (x_data[ii]) {
      idx++;
      i_data[idx - 1] = ii + 1;
      if (idx >= x_size) {
        exitg1 = true;
      } else {
        ii++;
      }
    } else {
      ii++;
    }
  }
  if (idx > x_size) {
    emlrtErrorWithMessageIdR2018a(&st, &g_emlrtRTEI,
                                  "Coder:builtins:AssertionFailed",
                                  "Coder:builtins:AssertionFailed", 0);
  }
  if (x_size == 1) {
    if (idx == 0) {
      i->size[0] = 0;
    }
  } else {
    int32_T iv[2];
    if (idx < 1) {
      b_i = 0;
    } else {
      b_i = idx;
    }
    iv[0] = 1;
    iv[1] = b_i;
    b_st.site = &ac_emlrtRSI;
    indexShapeCheck(&b_st, i->size[0], iv);
    ii = i->size[0];
    i->size[0] = b_i;
    emxEnsureCapacity_int32_T(&st, i, ii, &nb_emlrtRTEI);
  }
}

void eml_find(const emlrtStack *sp, const boolean_T x[2], int32_T i_data[],
              int32_T *i_size)
{
  emlrtStack b_st;
  emlrtStack st;
  int32_T iv[2];
  int32_T idx;
  int32_T ii;
  boolean_T exitg1;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &yb_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  idx = 0;
  ii = 0;
  exitg1 = false;
  while ((!exitg1) && (ii < 2)) {
    if (x[ii]) {
      idx++;
      i_data[idx - 1] = ii + 1;
      if (idx >= 2) {
        exitg1 = true;
      } else {
        ii++;
      }
    } else {
      ii++;
    }
  }
  if (idx < 1) {
    *i_size = 0;
  } else {
    *i_size = idx;
  }
  iv[0] = 1;
  iv[1] = *i_size;
  b_st.site = &ac_emlrtRSI;
  indexShapeCheck(&b_st, 2, iv);
}

/* End of code generation (find.c) */
