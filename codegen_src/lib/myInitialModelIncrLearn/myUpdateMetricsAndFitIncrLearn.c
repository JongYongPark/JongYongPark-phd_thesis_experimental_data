/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * myUpdateMetricsAndFitIncrLearn.c
 *
 * Code generation for function 'myUpdateMetricsAndFitIncrLearn'
 *
 */

/* Include files */
#include "myUpdateMetricsAndFitIncrLearn.h"
#include "Learner.h"
#include "Linear.h"
#include "RegressionModel.h"
#include "myInitialModelIncrLearn_data.h"
#include "myInitialModelIncrLearn_initialize.h"
#include "myInitialModelIncrLearn_types.h"
#include "rt_nonfinite.h"
#include <string.h>

/* Function Definitions */
void myUpdateMetricsAndFitIncrLearn(
    incrementalRegressionLinear *incrementalModel, const double X[100],
    const double Y[5])
{
  double a[25];
  double a__1[12];
  int i;
  if (!isInitialized_myInitialModelIncrLearn) {
    myInitialModelIncrLearn_initialize();
  }
  /*  MYUPDATEMETRICSINCRLEARN Measure model performance metrics on new data */
  if (incrementalModel->IsWarm) {
    double W[5];
    double YFit[5];
    double windowMetrics[5];
    double denom;
    double nw;
    double ratio;
    int nz;
    unsigned int q0;
    unsigned int qY;
    bool indsToExclude[5];
    for (i = 0; i < 5; i++) {
      W[i] = 1.0;
    }
    RegressionModel_prepareData(X, Y, false, indsToExclude);
    Linear_score(incrementalModel->Impl.Beta, incrementalModel->Impl.Bias, X,
                 indsToExclude, YFit);
    nw = 0.0;
    for (i = 0; i < 5; i++) {
      if (!indsToExclude[i]) {
        nw++;
      }
    }
    if (nw > 0.0) {
      for (i = 0; i < 5; i++) {
        if (!indsToExclude[i]) {
          W[i] /= nw;
        }
      }
    }
    for (i = 0; i < 5; i++) {
      nw = YFit[i] - Y[i];
      windowMetrics[i] = nw * nw;
    }
    nz = (((indsToExclude[0] + indsToExclude[1]) + indsToExclude[2]) +
          indsToExclude[3]) +
         indsToExclude[4];
    if (incrementalModel->NumMetricObservations == 0U) {
      ratio = -1.0;
    } else {
      ratio =
          (5.0 - (double)nz) / (double)incrementalModel->NumMetricObservations;
    }
    nw = 0.0;
    denom = 0.0;
    for (i = 0; i < 5; i++) {
      if (!indsToExclude[i]) {
        nw += W[i] * windowMetrics[i];
        denom += W[i];
      }
    }
    nw /= denom;
    if (ratio == -1.0) {
      incrementalModel->Metrics.MeanSquaredError.Cumulative = nw;
    } else {
      incrementalModel->Metrics.MeanSquaredError.Cumulative =
          (incrementalModel->Metrics.MeanSquaredError.Cumulative + nw * ratio) /
          (ratio + 1.0);
    }
    qY = incrementalModel->NumMetricObservations;
    if (MAX_uint32_T - incrementalModel->NumMetricObservations >= 5U - nz) {
      q0 = incrementalModel->NumMetricObservations;
      qY = (q0 - nz) + 5U;
      if (qY < q0) {
        qY = MAX_uint32_T;
      }
    }
    incrementalModel->NumMetricObservations = qY;
    if ((int)(5U - nz) != 0) {
      q0 = incrementalModel->BufferSize;
      qY = (q0 - nz) + 5U;
      if (qY < q0) {
        qY = MAX_uint32_T;
      }
      if (qY >= 25U) {
        int kk;
        int ns_tmp;
        ns_tmp = (int)(nz + 20U);
        for (i = 0; i < ns_tmp; i++) {
          incrementalModel->WeightBuffer[i] =
              incrementalModel->WeightBuffer[(i - nz) + 5];
        }
        kk = 25;
        i = 4;
        while ((i + 1 > 0) && (kk != (int)(nz + 20U))) {
          if (!indsToExclude[i]) {
            incrementalModel->WeightBuffer[kk - 1] = W[i] * (5.0 - (double)nz);
            kk--;
          }
          i--;
        }
        for (i = 0; i < ns_tmp; i++) {
          incrementalModel->MetricBuffer[i] =
              incrementalModel->MetricBuffer[(i - nz) + 5];
        }
        kk = 25;
        i = 4;
        while ((i + 1 > 0) && (kk != (int)(nz + 20U))) {
          if (!indsToExclude[i]) {
            incrementalModel->MetricBuffer[kk - 1] = windowMetrics[i];
            kk--;
          }
          i--;
        }
        nw = 0.0;
        denom = 0.0;
        for (i = 0; i < 25; i++) {
          nw += incrementalModel->MetricBuffer[i] *
                incrementalModel->WeightBuffer[i];
          denom += incrementalModel->WeightBuffer[i];
        }
        incrementalModel->Metrics.MeanSquaredError.Window = nw / denom;
        incrementalModel->BufferSize = 0U;
      } else {
        int b_i;
        int kk;
        int ns_tmp;
        memcpy(&a[0], &incrementalModel->WeightBuffer[0], 25U * sizeof(double));
        ns_tmp = 4 - nz;
        memset(&a__1[0], 0, 12U * sizeof(double));
        memcpy(&a__1[0], &a[0], (ns_tmp + 1) * sizeof(double));
        b_i = nz + 19;
        for (i = 0; i <= b_i; i++) {
          incrementalModel->WeightBuffer[i] =
              incrementalModel->WeightBuffer[(i - nz) + 5];
        }
        for (i = 0; i <= ns_tmp; i++) {
          incrementalModel->WeightBuffer[(i + nz) + 20] = a__1[i];
        }
        kk = 24;
        for (i = 4; i >= 0; i--) {
          if (!indsToExclude[i]) {
            incrementalModel->WeightBuffer[kk] = W[i] * (5.0 - (double)nz);
            kk--;
          }
        }
        memcpy(&a[0], &incrementalModel->MetricBuffer[0], 25U * sizeof(double));
        memset(&a__1[0], 0, 12U * sizeof(double));
        memcpy(&a__1[0], &a[0], (ns_tmp + 1) * sizeof(double));
        for (i = 0; i <= b_i; i++) {
          incrementalModel->MetricBuffer[i] =
              incrementalModel->MetricBuffer[(i - nz) + 5];
        }
        for (i = 0; i <= ns_tmp; i++) {
          incrementalModel->MetricBuffer[(i + nz) + 20] = a__1[i];
        }
        kk = 24;
        for (i = 4; i >= 0; i--) {
          if (!indsToExclude[i]) {
            incrementalModel->MetricBuffer[kk] = windowMetrics[i];
            kk--;
          }
        }
        incrementalModel->BufferSize = qY;
      }
    }
  }
  Learner_fitWithoutValidation(incrementalModel, X, Y);
}

/* End of code generation (myUpdateMetricsAndFitIncrLearn.c) */
