/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * myUpdateMetricsAndFitIncrLearn.h
 *
 * Code generation for function 'myUpdateMetricsAndFitIncrLearn'
 *
 */

#ifndef MYUPDATEMETRICSANDFITINCRLEARN_H
#define MYUPDATEMETRICSANDFITINCRLEARN_H

/* Include files */
#include "myInitialModelIncrLearn_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
extern void
myUpdateMetricsAndFitIncrLearn(incrementalRegressionLinear *incrementalModel,
                               const double X[100], const double Y[5]);

#ifdef __cplusplus
}
#endif

#endif
/* End of code generation (myUpdateMetricsAndFitIncrLearn.h) */
