/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * myInitialModelIncrLearn_types.h
 *
 * Code generation for function 'myInitialModelIncrLearn'
 *
 */

#ifndef MYINITIALMODELINCRLEARN_TYPES_H
#define MYINITIALMODELINCRLEARN_TYPES_H

/* Include files */
#include "rtwtypes.h"

/* Type Definitions */
#ifndef typedef_struct1_T
#define typedef_struct1_T
typedef struct {
  double Cumulative;
  double Window;
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
  double LearnRate;
  double Epsilon;
  double Beta[20];
  double Bias;
  double Lambda;
  unsigned int BatchIndex;
} incremental_coder_impl_SGDImpl;
#endif /* typedef_incremental_coder_impl_SGDImpl */

#ifndef typedef_incrementalRegressionLinear
#define typedef_incrementalRegressionLinear
typedef struct {
  unsigned int NumTrainingObservations;
  bool IsWarm;
  struct0_T Metrics;
  double MetricBuffer[25];
  double WeightBuffer[25];
  unsigned int BufferSize;
  unsigned int NumMetricObservations;
  unsigned int NumEstimationObservations;
  bool parametersAdjusted;
  incremental_coder_impl_SGDImpl Impl;
  bool EpsilonMetricAdjusted;
} incrementalRegressionLinear;
#endif /* typedef_incrementalRegressionLinear */

#endif
/* End of code generation (myInitialModelIncrLearn_types.h) */
