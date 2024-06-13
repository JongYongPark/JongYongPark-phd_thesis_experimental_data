/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_myInitialModelIncrLearn_api.h
 *
 * Code generation for function 'myInitialModelIncrLearn'
 *
 */

#ifndef _CODER_MYINITIALMODELINCRLEARN_API_H
#define _CODER_MYINITIALMODELINCRLEARN_API_H

/* Include files */
#include "emlrt.h"
#include "tmwtypes.h"
#include <string.h>

/* Type Definitions */
#ifndef typedef_struct1_T
#define typedef_struct1_T
typedef struct {
  real_T Cumulative;
  real_T Window;
} struct1_T;
#endif /* typedef_struct1_T */

#ifndef typedef_struct0_T
#define typedef_struct0_T
typedef struct {
  struct1_T MeanSquaredError;
} struct0_T;
#endif /* typedef_struct0_T */

#ifndef typedef_incremental_coder_impl_SGDImpl
#define typedef_incremental_coder_impl_SGDImpl
typedef struct {
  real_T LearnRate;
  real_T Epsilon;
  real_T Beta[20];
  real_T Bias;
  real_T Lambda;
  uint32_T BatchIndex;
} incremental_coder_impl_SGDImpl;
#endif /* typedef_incremental_coder_impl_SGDImpl */

#ifndef typedef_incrementalRegressionLinear
#define typedef_incrementalRegressionLinear
typedef struct {
  uint32_T NumTrainingObservations;
  boolean_T IsWarm;
  struct0_T Metrics;
  real_T MetricBuffer[25];
  real_T WeightBuffer[25];
  uint32_T BufferSize;
  uint32_T NumMetricObservations;
  uint32_T NumEstimationObservations;
  boolean_T parametersAdjusted;
  incremental_coder_impl_SGDImpl Impl;
  boolean_T EpsilonMetricAdjusted;
} incrementalRegressionLinear;
#endif /* typedef_incrementalRegressionLinear */

/* Variable Declarations */
extern emlrtCTX emlrtRootTLSGlobal;
extern emlrtContext emlrtContextGlobal;

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
void c_myUpdateMetricsAndFitIncrLear(const mxArray *const prhs[3],
                                     const mxArray **plhs);

void myFitIncrLearn(incrementalRegressionLinear *incrementalModel,
                    real_T X[100], real_T Y[5]);

void myFitIncrLearn_api(const mxArray *const prhs[3], const mxArray **plhs);

void myInitialModelIncrLearn(incrementalRegressionLinear *incrementalModel);

void myInitialModelIncrLearn_api(const mxArray **plhs);

void myInitialModelIncrLearn_atexit(void);

void myInitialModelIncrLearn_initialize(void);

void myInitialModelIncrLearn_terminate(void);

void myInitialModelIncrLearn_xil_shutdown(void);

void myInitialModelIncrLearn_xil_terminate(void);

void myMAE(real_T z[5], real_T zfit[5], real_T result[5]);

void myMAE_api(const mxArray *const prhs[2], const mxArray **plhs);

real_T myMAPE(real_T z[5], real_T zfit[5]);

void myMAPE_api(const mxArray *const prhs[2], const mxArray **plhs);

real_T myMSE(real_T z[5], real_T zfit[5]);

void myMSE_api(const mxArray *const prhs[2], const mxArray **plhs);

void myPredictIncrLearn(incrementalRegressionLinear incrementalModel,
                        real_T X[100], real_T labels[5]);

void myPredictIncrLearn_api(const mxArray *const prhs[2], const mxArray **plhs);

real_T myRMSE(real_T z[5], real_T zfit[5]);

void myRMSE_api(const mxArray *const prhs[2], const mxArray **plhs);

void myUpdateMetricsAndFitIncrLearn(
    incrementalRegressionLinear *incrementalModel, real_T X[100], real_T Y[5]);

#ifdef __cplusplus
}
#endif

#endif
/* End of code generation (_coder_myInitialModelIncrLearn_api.h) */
