/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * RegressionModel.h
 *
 * Code generation for function 'RegressionModel'
 *
 */

#ifndef REGRESSIONMODEL_H
#define REGRESSIONMODEL_H

/* Include files */
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
void RegressionModel_prepareData(const double X[100], const double Y[5],
                                 bool cleanWX, bool indsToExclude[5]);

#ifdef __cplusplus
}
#endif

#endif
/* End of code generation (RegressionModel.h) */
