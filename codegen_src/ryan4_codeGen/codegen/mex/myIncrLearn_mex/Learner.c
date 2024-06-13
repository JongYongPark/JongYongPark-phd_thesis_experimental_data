/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Learner.c
 *
 * Code generation for function 'Learner'
 *
 */

/* Include files */
#include "Learner.h"
#include "ClassificationModel.h"
#include "Linear.h"
#include "incrementalClassificationLinear.h"
#include "myIncrLearn_mex_emxutil.h"
#include "myIncrLearn_mex_types.h"
#include "rt_nonfinite.h"

/* Variable Definitions */
static emlrtRSInfo rg_emlrtRSI = {
    444,                            /* lineNo */
    "Learner/fitWithoutValidation", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\stats\\incremental\\+incremental\\+"
    "coder\\Learner.m" /* pathName */
};

static emlrtRSInfo tg_emlrtRSI = {
    442,                            /* lineNo */
    "Learner/fitWithoutValidation", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\stats\\incremental\\+incremental\\+"
    "coder\\Learner.m" /* pathName */
};

static emlrtRSInfo ug_emlrtRSI = {
    430,                            /* lineNo */
    "Learner/fitWithoutValidation", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\stats\\incremental\\+incremental\\+"
    "coder\\Learner.m" /* pathName */
};

static emlrtRTEInfo gd_emlrtRTEI = {
    427,       /* lineNo */
    25,        /* colNo */
    "Learner", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\stats\\incremental\\+incremental\\+"
    "coder\\Learner.m" /* pName */
};

/* Function Definitions */
void Learner_fitWithoutValidation(myIncrLearn_mexStackData *SD,
                                  const emlrtStack *sp,
                                  e_incrementalClassificationLine *this,
                                  const emxArray_real_T *X,
                                  const c_categorical *Y,
                                  const emxArray_real_T *W)
{
  emlrtStack st;
  emxArray_int32_T *Yout;
  int32_T indsToExclude_size;
  int32_T k;
  int32_T nz;
  uint32_T numObs_tmp;
  uint32_T qY;
  boolean_T indsToExclude_data[24075];
  st.prev = sp;
  st.tls = sp->tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  emxInit_int32_T(sp, &Yout, 1, &gd_emlrtRTEI);
  st.site = &ug_emlrtRSI;
  c_ClassificationModel_prepareRa(&st, this, X, Y, W, indsToExclude_data,
                                  &indsToExclude_size);
  st.site = &tg_emlrtRSI;
  d_incrementalClassificationLine(SD, &st, this, Y->codes.data, Y->codes.size,
                                  Y->categoryNames, Y->isOrdinal, W,
                                  indsToExclude_data, indsToExclude_size, Yout);
  if (indsToExclude_size == 0) {
    nz = 0;
  } else {
    nz = indsToExclude_data[0];
    for (k = 2; k <= indsToExclude_size; k++) {
      nz += indsToExclude_data[k - 1];
    }
  }
  if (nz < 0) {
    nz = 0;
  }
  st.site = &rg_emlrtRSI;
  c_Linear_fitModelWithoutValidat(&st, this, X, Yout, indsToExclude_data,
                                  indsToExclude_size, (uint32_T)nz);
  qY = (uint32_T)Yout->size[0] - nz;
  if (qY > (uint32_T)Yout->size[0]) {
    qY = 0U;
  }
  emxFree_int32_T(sp, &Yout);
  numObs_tmp = this->NumTrainingObservations;
  if (MAX_uint32_T - this->NumTrainingObservations >= qY) {
    qY += numObs_tmp;
    if (qY < numObs_tmp) {
      qY = MAX_uint32_T;
    }
    numObs_tmp = qY;
  }
  this->NumTrainingObservations = numObs_tmp;
  if ((!this->IsWarm) && this->PriorDefined && (numObs_tmp >= 1000U)) {
    this->IsWarm = true;
  }
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

/* End of code generation (Learner.c) */
