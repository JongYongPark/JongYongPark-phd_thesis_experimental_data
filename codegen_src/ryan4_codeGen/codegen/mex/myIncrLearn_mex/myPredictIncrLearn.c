/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * myPredictIncrLearn.c
 *
 * Code generation for function 'myPredictIncrLearn'
 *
 */

/* Include files */
#include "myPredictIncrLearn.h"
#include "ClassificationModel.h"
#include "myIncrLearn_mex_types.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo qh_emlrtRSI = {
    3,                    /* lineNo */
    "myPredictIncrLearn", /* fcnName */
    "C:\\nobackup\\_phd_work\\_battery_soh\\_matlab_battery\\_mywork\\_"
    "latest\\ryan4_codeGen\\myPredictIncrLearn.m" /* pathName */
};

static emlrtRSInfo rh_emlrtRSI = {
    40,                                        /* lineNo */
    "incrementalClassificationLinear/predict", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\stats\\incremental\\+incremental\\+"
    "coder\\incrementalClassificationLinear.m" /* pathName */
};

static emlrtRSInfo sh_emlrtRSI = {
    96,                            /* lineNo */
    "ClassificationModel/predict", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\stats\\incremental\\+incremental\\+"
    "coder\\+classif\\ClassificationModel.m" /* pathName */
};

static emlrtRSInfo th_emlrtRSI = {
    97,                            /* lineNo */
    "ClassificationModel/predict", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\stats\\incremental\\+incremental\\+"
    "coder\\+classif\\ClassificationModel.m" /* pathName */
};

static emlrtBCInfo vc_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    403,                /* lineNo */
    37,                 /* colNo */
    "",                 /* aName */
    "Learner/prepareX", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\stats\\incremental\\+incremental\\+"
    "coder\\Learner.m", /* pName */
    0                   /* checkKind */
};

static emlrtBCInfo wc_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    404,                /* lineNo */
    43,                 /* colNo */
    "",                 /* aName */
    "Learner/prepareX", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\stats\\incremental\\+incremental\\+"
    "coder\\Learner.m", /* pName */
    0                   /* checkKind */
};

/* Function Definitions */
void myPredictIncrLearn(myIncrLearn_mexStackData *SD, const emlrtStack *sp,
                        const e_incrementalClassificationLine incrementalModel,
                        const emxArray_real_T *X, b_categorical *labels,
                        emxArray_real_T *scores)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  const real_T *X_data;
  int32_T ii;
  int32_T indsToExclude_size;
  int32_T loop_ub;
  boolean_T indsToExclude_data[24075];
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  X_data = X->data;
  /*  MYPREDICTINCRLEARN Predict labels and classification scores on new data */
  st.site = &qh_emlrtRSI;
  b_st.site = &rh_emlrtRSI;
  c_st.site = &sh_emlrtRSI;
  indsToExclude_size = X->size[0];
  loop_ub = X->size[0];
  if (loop_ub - 1 >= 0) {
    memset(&indsToExclude_data[0], 0, loop_ub * sizeof(boolean_T));
  }
  loop_ub = X->size[0];
  for (ii = 0; ii < loop_ub; ii++) {
    int32_T jj;
    boolean_T exitg1;
    jj = 0;
    exitg1 = false;
    while ((!exitg1) && (jj < 60)) {
      if (ii + 1 > X->size[0]) {
        emlrtDynamicBoundsCheckR2012b(ii + 1, 1, X->size[0], &vc_emlrtBCI,
                                      &c_st);
      }
      if (muDoubleScalarIsNaN(X_data[ii + X->size[0] * jj])) {
        if (ii + 1 > indsToExclude_size) {
          emlrtDynamicBoundsCheckR2012b(ii + 1, 1, indsToExclude_size,
                                        &wc_emlrtBCI, &c_st);
        }
        indsToExclude_data[ii] = true;
        exitg1 = true;
      } else {
        jj++;
      }
    }
  }
  c_st.site = &th_emlrtRSI;
  c_ClassificationModel_predictWi(
      SD, &c_st, incrementalModel.ClassNames.codes,
      incrementalModel.ClassNames.categoryNames, incrementalModel.Prior,
      incrementalModel.Impl.Beta, incrementalModel.Impl.Bias, X,
      indsToExclude_data, indsToExclude_size, labels, scores);
}

/* End of code generation (myPredictIncrLearn.c) */
