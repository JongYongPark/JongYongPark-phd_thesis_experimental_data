/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * myInitialModelIncrLearn.c
 *
 * Code generation for function 'myInitialModelIncrLearn'
 *
 */

/* Include files */
#include "myInitialModelIncrLearn.h"
#include "myIncrLearn_mex_emxutil.h"
#include "myIncrLearn_mex_types.h"
#include "rt_nonfinite.h"
#include <string.h>

/* Variable Definitions */
static emlrtRTEInfo t_emlrtRTEI = {
    240,           /* lineNo */
    25,            /* colNo */
    "categorical", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\matlab\\datatypes\\codegen\\categorical\\+"
    "matlab\\+internal\\+coder\\@categorical\\categorical.m" /* pName */
};

static emlrtRTEInfo u_emlrtRTEI = {
    500,           /* lineNo */
    17,            /* colNo */
    "categorical", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\matlab\\datatypes\\codegen\\categorical\\+"
    "matlab\\+internal\\+coder\\@categorical\\categorical.m" /* pName */
};

static emlrtRTEInfo v_emlrtRTEI = {
    1,                         /* lineNo */
    29,                        /* colNo */
    "myInitialModelIncrLearn", /* fName */
    "C:\\nobackup\\_phd_work\\_battery_soh\\_matlab_battery\\_mywork\\_"
    "latest\\ryan4_codeGen\\myInitialModelIncrLearn.m" /* pName */
};

/* Function Definitions */
void myInitialModelIncrLearn(const emlrtStack *sp,
                             e_incrementalClassificationLine *incrementalModel)
{
  static const char_T b_cv1[14] = {'I', 'N', 'd', 'o', 'l', 't', 'e',
                                   'I', ' ', 'd', ' ', 'l', ' ', 'e'};
  static const char_T b_cv[7] = {'N', 'o', 't', 'I', 'd', 'l', 'e'};
  cell_wrap_1 r;
  cell_wrap_1 r1;
  int32_T i;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  /*  MYINITIALMODELINCRLEARN Load and return configured linear model for */
  /*  binary classification InitialMdl */
  incrementalModel->NumEstimationObservations = 0U;
  incrementalModel->parametersAdjusted = false;
  memset(&incrementalModel->Impl.Beta[0], 0, 60U * sizeof(real_T));
  incrementalModel->Impl.Bias = 0.0;
  incrementalModel->Impl.BatchIndex = 0U;
  incrementalModel->Impl.Epsilon = -1.0;
  incrementalModel->Impl.LearnRate = 1.0;
  for (i = 0; i < 61; i++) {
    incrementalModel->Impl.S2t[i] = 0.0;
    incrementalModel->Impl.Gt[i] = 0.0;
    incrementalModel->Impl.Mt[i] = 0.0;
    incrementalModel->Impl.Etat[i] = 1.0;
  }
  incrementalModel->Impl.Ymt = 1.0;
  incrementalModel->Impl.Rho = 0.0;
  incrementalModel->Impl.YmtSet = false;
  incrementalModel->NumTrainingObservations = 0U;
  incrementalModel->IsWarm = false;
  incrementalModel->BufferSize = 0U;
  memset(&incrementalModel->MetricBuffer[0], 0, 400U * sizeof(real_T));
  memset(&incrementalModel->WeightBuffer[0], 0, 200U * sizeof(real_T));
  emxInitStruct_cell_wrap_1(sp, &r, &v_emlrtRTEI, true);
  emxInitStruct_cell_wrap_1(sp, &r1, &v_emlrtRTEI, true);
  incrementalModel->NumMetricObservations = 0U;
  incrementalModel->Metrics.ClassificationError.Cumulative = -1.0;
  incrementalModel->Metrics.ClassificationError.Window = -1.0;
  incrementalModel->Metrics.HingeLoss.Cumulative = -1.0;
  incrementalModel->Metrics.HingeLoss.Window = -1.0;
  i = r.f1->size[0] * r.f1->size[1];
  r.f1->size[0] = 1;
  r.f1->size[1] = 4;
  emxEnsureCapacity_char_T(sp, r.f1, i, &t_emlrtRTEI);
  r.f1->data[0] = 'I';
  r.f1->data[1] = 'd';
  r.f1->data[2] = 'l';
  r.f1->data[3] = 'e';
  i = r1.f1->size[0] * r1.f1->size[1];
  r1.f1->size[0] = 1;
  r1.f1->size[1] = 7;
  emxEnsureCapacity_char_T(sp, r1.f1, i, &t_emlrtRTEI);
  for (i = 0; i < 7; i++) {
    r1.f1->data[i] = b_cv[i];
  }
  emxCopyStruct_cell_wrap_1(sp, &incrementalModel->ClassNames.categoryNames[0],
                            &r, &u_emlrtRTEI);
  emxCopyStruct_cell_wrap_1(sp, &incrementalModel->ClassNames.categoryNames[1],
                            &r1, &u_emlrtRTEI);
  incrementalModel->ClassNames.codes[0] = 1U;
  incrementalModel->ClassNames.codes[1] = 2U;
  emxFreeStruct_cell_wrap_1(sp, &r1);
  emxFreeStruct_cell_wrap_1(sp, &r);
  for (i = 0; i < 14; i++) {
    incrementalModel->CharClassNames[i] = b_cv1[i];
  }
  incrementalModel->PriorDefined = false;
  incrementalModel->PriorReset = false;
  incrementalModel->Prior[0] = -1.0;
  incrementalModel->WeightsPerClass[0] = 0.0;
  incrementalModel->Prior[1] = -1.0;
  incrementalModel->WeightsPerClass[1] = 0.0;
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

/* End of code generation (myInitialModelIncrLearn.c) */
