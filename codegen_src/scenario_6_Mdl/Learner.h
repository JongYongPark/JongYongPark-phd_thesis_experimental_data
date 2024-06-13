/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Learner.h
 *
 * Code generation for function 'Learner'
 *
 */

#ifndef LEARNER_H
#define LEARNER_H

/* Include files */
#include "myInitialModelIncrLearn_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
void Learner_fitWithoutValidation(incrementalRegressionLinear *this,
                                  const double X[100], const double Y[5]);

#ifdef __cplusplus
}
#endif

#endif
/* End of code generation (Learner.h) */
