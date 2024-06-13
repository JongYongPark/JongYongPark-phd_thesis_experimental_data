/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * myUpdateMetricsIncrLearn.c
 *
 * Code generation for function 'myUpdateMetricsIncrLearn'
 *
 */

/* Include files */
#include "myUpdateMetricsIncrLearn.h"
#include "ClassificationModel.h"
#include "circshift.h"
#include "myIncrLearn_mex_data.h"
#include "myIncrLearn_mex_emxutil.h"
#include "myIncrLearn_mex_types.h"
#include "rt_nonfinite.h"

/* Variable Definitions */
static emlrtRSInfo emlrtRSI = {
    3,                          /* lineNo */
    "myUpdateMetricsIncrLearn", /* fcnName */
    "C:\\nobackup\\_phd_work\\_battery_soh\\_matlab_battery\\_mywork\\_"
    "latest\\ryan4_codeGen\\myUpdateMetricsIncrLearn.m" /* pathName */
};

static emlrtRSInfo b_emlrtRSI = {
    135,                                             /* lineNo */
    "incrementalClassificationLinear/updateMetrics", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\stats\\incremental\\+incremental\\+"
    "coder\\incrementalClassificationLinear.m" /* pathName */
};

static emlrtRSInfo c_emlrtRSI = {
    215,                     /* lineNo */
    "Learner/updateMetrics", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\stats\\incremental\\+incremental\\+"
    "coder\\Learner.m" /* pathName */
};

static emlrtRSInfo d_emlrtRSI = {
    216,                     /* lineNo */
    "Learner/updateMetrics", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\stats\\incremental\\+incremental\\+"
    "coder\\Learner.m" /* pathName */
};

static emlrtRSInfo f_emlrtRSI = {
    385,                                      /* lineNo */
    "Learner/updateMetricsWithoutValidation", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\stats\\incremental\\+incremental\\+"
    "coder\\Learner.m" /* pathName */
};

static emlrtRSInfo g_emlrtRSI = {
    387,                                      /* lineNo */
    "Learner/updateMetricsWithoutValidation", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\stats\\incremental\\+incremental\\+"
    "coder\\Learner.m" /* pathName */
};

static emlrtRSInfo h_emlrtRSI = {
    389,                                      /* lineNo */
    "Learner/updateMetricsWithoutValidation", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\stats\\incremental\\+incremental\\+"
    "coder\\Learner.m" /* pathName */
};

static emlrtRSInfo cg_emlrtRSI = {
    597,                           /* lineNo */
    "Learner/updateWindowMetrics", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\stats\\incremental\\+incremental\\+"
    "coder\\Learner.m" /* pathName */
};

static emlrtRSInfo dg_emlrtRSI = {
    606,                           /* lineNo */
    "Learner/updateWindowMetrics", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\stats\\incremental\\+incremental\\+"
    "coder\\Learner.m" /* pathName */
};

static emlrtBCInfo xc_emlrtBCI = {
    -1,                                /* iFirst */
    -1,                                /* iLast */
    507,                               /* lineNo */
    39,                                /* colNo */
    "",                                /* aName */
    "Learner/updateCumulativeMetrics", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\stats\\incremental\\+incremental\\+"
    "coder\\Learner.m", /* pName */
    0                   /* checkKind */
};

static emlrtBCInfo yc_emlrtBCI = {
    -1,                                /* iFirst */
    -1,                                /* iLast */
    508,                               /* lineNo */
    39,                                /* colNo */
    "",                                /* aName */
    "Learner/updateCumulativeMetrics", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\stats\\incremental\\+incremental\\+"
    "coder\\Learner.m", /* pName */
    0                   /* checkKind */
};

static emlrtBCInfo ad_emlrtBCI = {
    -1,                                /* iFirst */
    -1,                                /* iLast */
    508,                               /* lineNo */
    57,                                /* colNo */
    "",                                /* aName */
    "Learner/updateCumulativeMetrics", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\stats\\incremental\\+incremental\\+"
    "coder\\Learner.m", /* pName */
    0                   /* checkKind */
};

static emlrtBCInfo bd_emlrtBCI = {
    -1,                                /* iFirst */
    -1,                                /* iLast */
    509,                               /* lineNo */
    43,                                /* colNo */
    "",                                /* aName */
    "Learner/updateCumulativeMetrics", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\stats\\incremental\\+incremental\\+"
    "coder\\Learner.m", /* pName */
    0                   /* checkKind */
};

static emlrtBCInfo cd_emlrtBCI = {
    -1,                            /* iFirst */
    -1,                            /* iLast */
    539,                           /* lineNo */
    43,                            /* colNo */
    "",                            /* aName */
    "Learner/updateWindowMetrics", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\stats\\incremental\\+incremental\\+"
    "coder\\Learner.m", /* pName */
    0                   /* checkKind */
};

static emlrtBCInfo dd_emlrtBCI = {
    -1,                            /* iFirst */
    -1,                            /* iLast */
    600,                           /* lineNo */
    43,                            /* colNo */
    "",                            /* aName */
    "Learner/updateWindowMetrics", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\stats\\incremental\\+incremental\\+"
    "coder\\Learner.m", /* pName */
    0                   /* checkKind */
};

static emlrtBCInfo ed_emlrtBCI = {
    -1,                            /* iFirst */
    -1,                            /* iLast */
    540,                           /* lineNo */
    55,                            /* colNo */
    "",                            /* aName */
    "Learner/updateWindowMetrics", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\stats\\incremental\\+incremental\\+"
    "coder\\Learner.m", /* pName */
    0                   /* checkKind */
};

static emlrtBCInfo fd_emlrtBCI = {
    -1,                            /* iFirst */
    -1,                            /* iLast */
    540,                           /* lineNo */
    64,                            /* colNo */
    "",                            /* aName */
    "Learner/updateWindowMetrics", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\stats\\incremental\\+incremental\\+"
    "coder\\Learner.m", /* pName */
    0                   /* checkKind */
};

static emlrtBCInfo gd_emlrtBCI = {
    -1,                            /* iFirst */
    -1,                            /* iLast */
    601,                           /* lineNo */
    55,                            /* colNo */
    "",                            /* aName */
    "Learner/updateWindowMetrics", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\stats\\incremental\\+incremental\\+"
    "coder\\Learner.m", /* pName */
    0                   /* checkKind */
};

static emlrtBCInfo hd_emlrtBCI = {
    1,                             /* iFirst */
    200,                           /* iLast */
    601,                           /* lineNo */
    47,                            /* colNo */
    "",                            /* aName */
    "Learner/updateWindowMetrics", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\stats\\incremental\\+incremental\\+"
    "coder\\Learner.m", /* pName */
    3                   /* checkKind */
};

static emlrtBCInfo id_emlrtBCI = {
    1,                             /* iFirst */
    200,                           /* iLast */
    557,                           /* lineNo */
    67,                            /* colNo */
    "",                            /* aName */
    "Learner/updateWindowMetrics", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\stats\\incremental\\+incremental\\+"
    "coder\\Learner.m", /* pName */
    0                   /* checkKind */
};

static emlrtBCInfo jd_emlrtBCI = {
    -1,                            /* iFirst */
    -1,                            /* iLast */
    541,                           /* lineNo */
    47,                            /* colNo */
    "",                            /* aName */
    "Learner/updateWindowMetrics", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\stats\\incremental\\+incremental\\+"
    "coder\\Learner.m", /* pName */
    0                   /* checkKind */
};

static emlrtBCInfo kd_emlrtBCI = {
    -1,                            /* iFirst */
    -1,                            /* iLast */
    565,                           /* lineNo */
    43,                            /* colNo */
    "",                            /* aName */
    "Learner/updateWindowMetrics", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\stats\\incremental\\+incremental\\+"
    "coder\\Learner.m", /* pName */
    0                   /* checkKind */
};

static emlrtBCInfo ld_emlrtBCI = {
    -1,                            /* iFirst */
    -1,                            /* iLast */
    566,                           /* lineNo */
    55,                            /* colNo */
    "",                            /* aName */
    "Learner/updateWindowMetrics", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\stats\\incremental\\+incremental\\+"
    "coder\\Learner.m", /* pName */
    0                   /* checkKind */
};

static emlrtBCInfo md_emlrtBCI = {
    1,                             /* iFirst */
    200,                           /* iLast */
    566,                           /* lineNo */
    47,                            /* colNo */
    "",                            /* aName */
    "Learner/updateWindowMetrics", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\stats\\incremental\\+incremental\\+"
    "coder\\Learner.m", /* pName */
    3                   /* checkKind */
};

static emlrtBCInfo nd_emlrtBCI = {
    -1,                            /* iFirst */
    -1,                            /* iLast */
    609,                           /* lineNo */
    47,                            /* colNo */
    "",                            /* aName */
    "Learner/updateWindowMetrics", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\stats\\incremental\\+incremental\\+"
    "coder\\Learner.m", /* pName */
    0                   /* checkKind */
};

static emlrtBCInfo od_emlrtBCI = {
    -1,                            /* iFirst */
    -1,                            /* iLast */
    610,                           /* lineNo */
    74,                            /* colNo */
    "",                            /* aName */
    "Learner/updateWindowMetrics", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\stats\\incremental\\+incremental\\+"
    "coder\\Learner.m", /* pName */
    0                   /* checkKind */
};

static emlrtBCInfo pd_emlrtBCI = {
    1,                             /* iFirst */
    200,                           /* iLast */
    610,                           /* lineNo */
    51,                            /* colNo */
    "",                            /* aName */
    "Learner/updateWindowMetrics", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\stats\\incremental\\+incremental\\+"
    "coder\\Learner.m", /* pName */
    3                   /* checkKind */
};

static emlrtBCInfo qd_emlrtBCI = {
    1,                             /* iFirst */
    200,                           /* iLast */
    574,                           /* lineNo */
    74,                            /* colNo */
    "",                            /* aName */
    "Learner/updateWindowMetrics", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\stats\\incremental\\+incremental\\+"
    "coder\\Learner.m", /* pName */
    0                   /* checkKind */
};

static emlrtBCInfo rd_emlrtBCI = {
    -1,                            /* iFirst */
    -1,                            /* iLast */
    582,                           /* lineNo */
    47,                            /* colNo */
    "",                            /* aName */
    "Learner/updateWindowMetrics", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\stats\\incremental\\+incremental\\+"
    "coder\\Learner.m", /* pName */
    0                   /* checkKind */
};

static emlrtBCInfo sd_emlrtBCI = {
    -1,                            /* iFirst */
    -1,                            /* iLast */
    583,                           /* lineNo */
    74,                            /* colNo */
    "",                            /* aName */
    "Learner/updateWindowMetrics", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\stats\\incremental\\+incremental\\+"
    "coder\\Learner.m", /* pName */
    0                   /* checkKind */
};

static emlrtBCInfo td_emlrtBCI = {
    1,                             /* iFirst */
    200,                           /* iLast */
    583,                           /* lineNo */
    51,                            /* colNo */
    "",                            /* aName */
    "Learner/updateWindowMetrics", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\stats\\incremental\\+incremental\\+"
    "coder\\Learner.m", /* pName */
    3                   /* checkKind */
};

static emlrtRTEInfo hc_emlrtRTEI = {
    385,       /* lineNo */
    28,        /* colNo */
    "Learner", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\stats\\incremental\\+incremental\\+"
    "coder\\Learner.m" /* pName */
};

static emlrtRTEInfo ic_emlrtRTEI = {
    1,                          /* lineNo */
    29,                         /* colNo */
    "myUpdateMetricsIncrLearn", /* fName */
    "C:\\nobackup\\_phd_work\\_battery_soh\\_matlab_battery\\_mywork\\_"
    "latest\\ryan4_codeGen\\myUpdateMetricsIncrLearn.m" /* pName */
};

/* Function Definitions */
void myUpdateMetricsIncrLearn(myIncrLearn_mexStackData *SD,
                              const emlrtStack *sp,
                              e_incrementalClassificationLine *incrementalModel,
                              const emxArray_real_T *X, const c_categorical *Y)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack st;
  emxArray_real_T *W;
  emxArray_real_T *windowMetrics;
  real_T *W_data;
  real_T *windowMetrics_data;
  int32_T i;
  int32_T ii;
  int32_T indsToExclude_size;
  int32_T jj;
  int32_T k;
  boolean_T indsToExclude_data[24075];
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  /*  MYUPDATEMETRICSINCRLEARN Measure model performance metrics on new data */
  st.site = &emlrtRSI;
  b_st.site = &b_emlrtRSI;
  if (incrementalModel->IsWarm) {
    real_T denom;
    real_T num;
    real_T ratio;
    real_T totalLoss;
    int32_T N;
    uint32_T b_qY;
    uint32_T q0;
    uint32_T qY;
    c_st.site = &c_emlrtRSI;
    d_st.site = &e_emlrtRSI;
    N = X->size[0];
    if ((uint32_T)X->size[0] != (uint32_T)Y->codes.size[0]) {
      emlrtErrorWithMessageIdR2018a(
          &d_st, &m_emlrtRTEI,
          "stats:classreg:learning:FullClassificationRegressionModel:"
          "prepareDataCR:InputSizeMismatch",
          "stats:classreg:learning:FullClassificationRegressionModel:"
          "prepareDataCR:InputSizeMismatch",
          0);
    }
    emxInit_real_T(&d_st, &W, 1, &ic_emlrtRTEI);
    c_st.site = &d_emlrtRSI;
    i = W->size[0];
    W->size[0] = X->size[0];
    emxEnsureCapacity_real_T(&c_st, W, i, &hc_emlrtRTEI);
    W_data = W->data;
    for (i = 0; i < N; i++) {
      W_data[i] = 1.0;
    }
    emxInit_real_T(&c_st, &windowMetrics, 2, &ic_emlrtRTEI);
    d_st.site = &f_emlrtRSI;
    c_ClassificationModel_adjustWei(
        SD, &d_st, incrementalModel->ClassNames.codes,
        incrementalModel->ClassNames.categoryNames, incrementalModel->Prior,
        incrementalModel->PriorDefined, incrementalModel->Impl.Beta,
        incrementalModel->Impl.Bias, X, Y->codes.data, Y->codes.size,
        Y->categoryNames, Y->isProtected, Y->isOrdinal,
        Y->numCategoriesUpperBound, W, windowMetrics, indsToExclude_data,
        &indsToExclude_size);
    windowMetrics_data = windowMetrics->data;
    W_data = W->data;
    d_st.site = &g_emlrtRSI;
    if (indsToExclude_size == 0) {
      N = 0;
    } else {
      N = indsToExclude_data[0];
      for (k = 2; k <= indsToExclude_size; k++) {
        N += indsToExclude_data[k - 1];
      }
    }
    if (N < 0) {
      N = 0;
    }
    qY = (uint32_T)W->size[0] - N;
    if (qY > (uint32_T)W->size[0]) {
      qY = 0U;
    }
    if (incrementalModel->NumMetricObservations == 0U) {
      ratio = -1.0;
    } else {
      ratio =
          (real_T)(int32_T)qY / (real_T)incrementalModel->NumMetricObservations;
    }
    num = 0.0;
    denom = 0.0;
    i = W->size[0];
    for (jj = 0; jj < i; jj++) {
      if (jj + 1 > indsToExclude_size) {
        emlrtDynamicBoundsCheckR2012b(jj + 1, 1, indsToExclude_size,
                                      &xc_emlrtBCI, &d_st);
      }
      if (!indsToExclude_data[jj]) {
        if (jj + 1 > W->size[0]) {
          emlrtDynamicBoundsCheckR2012b(jj + 1, 1, W->size[0], &yc_emlrtBCI,
                                        &d_st);
        }
        if (jj + 1 > windowMetrics->size[0]) {
          emlrtDynamicBoundsCheckR2012b(jj + 1, 1, windowMetrics->size[0],
                                        &ad_emlrtBCI, &d_st);
        }
        num += W_data[jj] * windowMetrics_data[jj];
        if (jj + 1 > W->size[0]) {
          emlrtDynamicBoundsCheckR2012b(jj + 1, 1, W->size[0], &bd_emlrtBCI,
                                        &d_st);
        }
        denom += W_data[jj];
      }
    }
    totalLoss = num / denom;
    if (ratio == -1.0) {
      incrementalModel->Metrics.ClassificationError.Cumulative = totalLoss;
    } else {
      incrementalModel->Metrics.ClassificationError.Cumulative =
          (incrementalModel->Metrics.ClassificationError.Cumulative +
           totalLoss * ratio) /
          (ratio + 1.0);
    }
    num = 0.0;
    denom = 0.0;
    i = W->size[0];
    for (jj = 0; jj < i; jj++) {
      if (jj + 1 > indsToExclude_size) {
        emlrtDynamicBoundsCheckR2012b(jj + 1, 1, indsToExclude_size,
                                      &xc_emlrtBCI, &d_st);
      }
      if (!indsToExclude_data[jj]) {
        if (jj + 1 > W->size[0]) {
          emlrtDynamicBoundsCheckR2012b(jj + 1, 1, W->size[0], &yc_emlrtBCI,
                                        &d_st);
        }
        if (jj + 1 > windowMetrics->size[0]) {
          emlrtDynamicBoundsCheckR2012b(jj + 1, 1, windowMetrics->size[0],
                                        &ad_emlrtBCI, &d_st);
        }
        num += W_data[jj] * windowMetrics_data[jj + windowMetrics->size[0]];
        if (jj + 1 > W->size[0]) {
          emlrtDynamicBoundsCheckR2012b(jj + 1, 1, W->size[0], &bd_emlrtBCI,
                                        &d_st);
        }
        denom += W_data[jj];
      }
    }
    totalLoss = num / denom;
    if (ratio == -1.0) {
      incrementalModel->Metrics.HingeLoss.Cumulative = totalLoss;
    } else {
      incrementalModel->Metrics.HingeLoss.Cumulative =
          (incrementalModel->Metrics.HingeLoss.Cumulative + totalLoss * ratio) /
          (ratio + 1.0);
    }
    b_qY = incrementalModel->NumMetricObservations;
    if (MAX_uint32_T - incrementalModel->NumMetricObservations >= qY) {
      q0 = incrementalModel->NumMetricObservations;
      b_qY = q0 + qY;
      if (b_qY < q0) {
        b_qY = MAX_uint32_T;
      }
    }
    incrementalModel->NumMetricObservations = b_qY;
    d_st.site = &h_emlrtRSI;
    if ((int32_T)qY != 0) {
      if (qY >= 200U) {
        boolean_T exitg1;
        num = 0.0;
        denom = 0.0;
        N = 0;
        jj = windowMetrics->size[0];
        exitg1 = false;
        while ((!exitg1) && (jj > 0)) {
          if (jj > indsToExclude_size) {
            emlrtDynamicBoundsCheckR2012b(jj, 1, indsToExclude_size,
                                          &cd_emlrtBCI, &d_st);
          }
          if (!indsToExclude_data[jj - 1]) {
            if (jj > windowMetrics->size[0]) {
              emlrtDynamicBoundsCheckR2012b(jj, 1, windowMetrics->size[0],
                                            &ed_emlrtBCI, &d_st);
            }
            if (jj > W->size[0]) {
              emlrtDynamicBoundsCheckR2012b(jj, 1, W->size[0], &fd_emlrtBCI,
                                            &d_st);
            }
            totalLoss = W_data[jj - 1];
            num += windowMetrics_data[jj - 1] * totalLoss;
            if (jj > W->size[0]) {
              emlrtDynamicBoundsCheckR2012b(jj, 1, W->size[0], &jd_emlrtBCI,
                                            &d_st);
            }
            denom += totalLoss;
            N++;
          }
          if (N == 200) {
            exitg1 = true;
          } else {
            jj--;
          }
        }
        incrementalModel->Metrics.ClassificationError.Window = num / denom;
        num = 0.0;
        denom = 0.0;
        N = 0;
        jj = windowMetrics->size[0];
        exitg1 = false;
        while ((!exitg1) && (jj > 0)) {
          if (jj > indsToExclude_size) {
            emlrtDynamicBoundsCheckR2012b(jj, 1, indsToExclude_size,
                                          &cd_emlrtBCI, &d_st);
          }
          if (!indsToExclude_data[jj - 1]) {
            if (jj > windowMetrics->size[0]) {
              emlrtDynamicBoundsCheckR2012b(jj, 1, windowMetrics->size[0],
                                            &ed_emlrtBCI, &d_st);
            }
            if (jj > W->size[0]) {
              emlrtDynamicBoundsCheckR2012b(jj, 1, W->size[0], &fd_emlrtBCI,
                                            &d_st);
            }
            totalLoss = W_data[jj - 1];
            num += windowMetrics_data[(jj + windowMetrics->size[0]) - 1] *
                   totalLoss;
            if (jj > W->size[0]) {
              emlrtDynamicBoundsCheckR2012b(jj, 1, W->size[0], &jd_emlrtBCI,
                                            &d_st);
            }
            denom += totalLoss;
            N++;
          }
          if (N == 200) {
            exitg1 = true;
          } else {
            jj--;
          }
        }
        incrementalModel->Metrics.HingeLoss.Window = num / denom;
        incrementalModel->BufferSize = 0U;
      } else {
        q0 = incrementalModel->BufferSize;
        b_qY = q0 + qY;
        if (b_qY < q0) {
          b_qY = MAX_uint32_T;
        }
        if (b_qY >= 200U) {
          k = (int32_T)(200U - qY);
          for (ii = 0; ii < k; ii++) {
            i = (ii + (int32_T)qY) + 1;
            if (i > 200) {
              emlrtDynamicBoundsCheckR2012b(i, 1, 200, &id_emlrtBCI, &d_st);
            }
            incrementalModel->WeightBuffer[ii] =
                incrementalModel->WeightBuffer[i - 1];
          }
          N = 200;
          ii = windowMetrics->size[0];
          while ((ii > 0) && (N != (int32_T)(200U - qY))) {
            if (ii > indsToExclude_size) {
              emlrtDynamicBoundsCheckR2012b(ii, 1, indsToExclude_size,
                                            &kd_emlrtBCI, &d_st);
            }
            if (!indsToExclude_data[ii - 1]) {
              if (ii > W->size[0]) {
                emlrtDynamicBoundsCheckR2012b(ii, 1, W->size[0], &ld_emlrtBCI,
                                              &d_st);
              }
              if (N < 1) {
                emlrtDynamicBoundsCheckR2012b(N, 1, 200, &md_emlrtBCI, &d_st);
              }
              incrementalModel->WeightBuffer[N - 1] =
                  W_data[ii - 1] * (real_T)qY;
              N--;
            }
            ii--;
          }
          for (jj = 0; jj < k; jj++) {
            i = (jj + (int32_T)qY) + 1;
            if (i > 200) {
              emlrtDynamicBoundsCheckR2012b(i, 1, 200, &qd_emlrtBCI, &d_st);
            }
            incrementalModel->MetricBuffer[jj] =
                incrementalModel->MetricBuffer[i - 1];
          }
          N = 200;
          jj = windowMetrics->size[0];
          while ((jj > 0) && (N != (int32_T)(200U - qY))) {
            if (jj > indsToExclude_size) {
              emlrtDynamicBoundsCheckR2012b(jj, 1, indsToExclude_size,
                                            &rd_emlrtBCI, &d_st);
            }
            if (!indsToExclude_data[jj - 1]) {
              if (jj > windowMetrics->size[0]) {
                emlrtDynamicBoundsCheckR2012b(jj, 1, windowMetrics->size[0],
                                              &sd_emlrtBCI, &d_st);
              }
              if (N < 1) {
                emlrtDynamicBoundsCheckR2012b(N, 1, 200, &td_emlrtBCI, &d_st);
              }
              incrementalModel->MetricBuffer[N - 1] =
                  windowMetrics_data[jj - 1];
              N--;
            }
            jj--;
          }
          num = 0.0;
          denom = 0.0;
          for (jj = 0; jj < 200; jj++) {
            num += incrementalModel->MetricBuffer[jj] *
                   incrementalModel->WeightBuffer[jj];
            denom += incrementalModel->WeightBuffer[jj];
          }
          incrementalModel->Metrics.ClassificationError.Window = num / denom;
          for (jj = 0; jj < k; jj++) {
            i = (jj + (int32_T)qY) + 1;
            if (i > 200) {
              emlrtDynamicBoundsCheckR2012b(i, 1, 200, &qd_emlrtBCI, &d_st);
            }
            incrementalModel->MetricBuffer[jj + 200] =
                incrementalModel->MetricBuffer[i + 199];
          }
          N = 200;
          jj = windowMetrics->size[0];
          while ((jj > 0) && (N != (int32_T)(200U - qY))) {
            if (jj > indsToExclude_size) {
              emlrtDynamicBoundsCheckR2012b(jj, 1, indsToExclude_size,
                                            &rd_emlrtBCI, &d_st);
            }
            if (!indsToExclude_data[jj - 1]) {
              if (jj > windowMetrics->size[0]) {
                emlrtDynamicBoundsCheckR2012b(jj, 1, windowMetrics->size[0],
                                              &sd_emlrtBCI, &d_st);
              }
              if (N < 1) {
                emlrtDynamicBoundsCheckR2012b(N, 1, 200, &td_emlrtBCI, &d_st);
              }
              incrementalModel->MetricBuffer[N + 199] =
                  windowMetrics_data[(jj + windowMetrics->size[0]) - 1];
              N--;
            }
            jj--;
          }
          num = 0.0;
          denom = 0.0;
          for (jj = 0; jj < 200; jj++) {
            num += incrementalModel->MetricBuffer[jj + 200] *
                   incrementalModel->WeightBuffer[jj];
            denom += incrementalModel->WeightBuffer[jj];
          }
          incrementalModel->Metrics.HingeLoss.Window = num / denom;
          incrementalModel->BufferSize = 0U;
        } else {
          e_st.site = &cg_emlrtRSI;
          circshift(&e_st, incrementalModel->WeightBuffer, -(int32_T)qY);
          N = 200;
          i = windowMetrics->size[0];
          for (ii = i; ii >= 1; ii--) {
            if (ii > indsToExclude_size) {
              emlrtDynamicBoundsCheckR2012b(ii, 1, indsToExclude_size,
                                            &dd_emlrtBCI, &d_st);
            }
            if (!indsToExclude_data[ii - 1]) {
              if (ii > W->size[0]) {
                emlrtDynamicBoundsCheckR2012b(ii, 1, W->size[0], &gd_emlrtBCI,
                                              &d_st);
              }
              if (N < 1) {
                emlrtDynamicBoundsCheckR2012b(0, 1, 200, &hd_emlrtBCI, &d_st);
              }
              incrementalModel->WeightBuffer[N - 1] =
                  W_data[ii - 1] * (real_T)qY;
              N--;
            }
          }
          i = windowMetrics->size[0];
          for (ii = 0; ii < 2; ii++) {
            e_st.site = &dg_emlrtRSI;
            circshift(&e_st,
                      *(real_T(*)[200]) &
                          incrementalModel->MetricBuffer[200 * ii],
                      -(int32_T)qY);
            N = 200;
            for (jj = i; jj >= 1; jj--) {
              if (jj > indsToExclude_size) {
                emlrtDynamicBoundsCheckR2012b(jj, 1, indsToExclude_size,
                                              &nd_emlrtBCI, &d_st);
              }
              if (!indsToExclude_data[jj - 1]) {
                if (jj > windowMetrics->size[0]) {
                  emlrtDynamicBoundsCheckR2012b(jj, 1, windowMetrics->size[0],
                                                &od_emlrtBCI, &d_st);
                }
                if (N < 1) {
                  emlrtDynamicBoundsCheckR2012b(0, 1, 200, &pd_emlrtBCI, &d_st);
                }
                incrementalModel->MetricBuffer[(N + 200 * ii) - 1] =
                    windowMetrics_data[(jj + windowMetrics->size[0] * ii) - 1];
                N--;
              }
            }
          }
          incrementalModel->BufferSize = b_qY;
        }
      }
    }
    emxFree_real_T(&d_st, &W);
    emxFree_real_T(&d_st, &windowMetrics);
  }
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

/* End of code generation (myUpdateMetricsIncrLearn.c) */
