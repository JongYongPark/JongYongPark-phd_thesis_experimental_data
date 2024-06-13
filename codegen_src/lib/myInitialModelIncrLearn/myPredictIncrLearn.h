/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * myPredictIncrLearn.h
 *
 * Code generation for function 'myPredictIncrLearn'
 *
 */

#ifndef MYPREDICTINCRLEARN_H
#define MYPREDICTINCRLEARN_H

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
myPredictIncrLearn(const incrementalRegressionLinear incrementalModel,
                   const double X[100], double labels[5]);

#ifdef __cplusplus
}
#endif

#endif
/* End of code generation (myPredictIncrLearn.h) */
