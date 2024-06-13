/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * LinearImpl.c
 *
 * Code generation for function 'LinearImpl'
 *
 */

/* Include files */
#include "LinearImpl.h"
#include "myIncrLearn_mex_emxutil.h"
#include "myIncrLearn_mex_types.h"
#include "rt_nonfinite.h"

/* Variable Definitions */
static emlrtBCInfo ub_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    174,                /* lineNo */
    39,                 /* colNo */
    "",                 /* aName */
    "LinearImpl/score", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\stats\\incremental\\+incremental\\+"
    "coder\\+impl\\LinearImpl.m", /* pName */
    0                             /* checkKind */
};

static emlrtBCInfo vb_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    173,                /* lineNo */
    43,                 /* colNo */
    "",                 /* aName */
    "LinearImpl/score", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\stats\\incremental\\+incremental\\+"
    "coder\\+impl\\LinearImpl.m", /* pName */
    0                             /* checkKind */
};

static emlrtBCInfo wb_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    174,                /* lineNo */
    31,                 /* colNo */
    "",                 /* aName */
    "LinearImpl/score", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\stats\\incremental\\+incremental\\+"
    "coder\\+impl\\LinearImpl.m", /* pName */
    0                             /* checkKind */
};

static emlrtRTEInfo qb_emlrtRTEI = {
    163,          /* lineNo */
    17,           /* colNo */
    "LinearImpl", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\stats\\incremental\\+incremental\\+"
    "coder\\+impl\\LinearImpl.m" /* pName */
};

/* Function Definitions */
void LinearImpl_score(const emlrtStack *sp, const real_T this_Beta[60],
                      real_T this_Bias, const emxArray_real_T *X,
                      const boolean_T indsToExclude_data[],
                      int32_T indsToExclude_size, emxArray_real_T *s)
{
  const real_T *X_data;
  real_T *s_data;
  int32_T i;
  int32_T i1;
  int32_T loop_ub;
  X_data = X->data;
  i = s->size[0];
  s->size[0] = X->size[0];
  emxEnsureCapacity_real_T(sp, s, i, &qb_emlrtRTEI);
  s_data = s->data;
  loop_ub = X->size[0];
  for (i = 0; i < loop_ub; i++) {
    s_data[i] = rtNaN;
  }
  i = X->size[0];
  for (loop_ub = 0; loop_ub < i; loop_ub++) {
    if (loop_ub + 1 > indsToExclude_size) {
      emlrtDynamicBoundsCheckR2012b(loop_ub + 1, 1, indsToExclude_size,
                                    &vb_emlrtBCI, (emlrtCTX)sp);
    }
    if (!indsToExclude_data[loop_ub]) {
      real_T b_X;
      if (loop_ub + 1 > X->size[0]) {
        emlrtDynamicBoundsCheckR2012b(loop_ub + 1, 1, X->size[0], &ub_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      b_X = 0.0;
      for (i1 = 0; i1 < 60; i1++) {
        b_X += X_data[loop_ub + X->size[0] * i1] * this_Beta[i1];
      }
      if (loop_ub + 1 > s->size[0]) {
        emlrtDynamicBoundsCheckR2012b(loop_ub + 1, 1, s->size[0], &wb_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      s_data[loop_ub] = b_X + this_Bias;
    }
  }
}

/* End of code generation (LinearImpl.c) */
