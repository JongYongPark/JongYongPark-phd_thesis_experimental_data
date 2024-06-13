/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * RegressionLinear.h
 *
 * Code generation for function 'RegressionLinear'
 *
 */

#ifndef REGRESSIONLINEAR_H
#define REGRESSIONLINEAR_H

/* Include files */
#include "RegressionLinearModel_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
void RegressionLinear_update(RegressionLinear *obj,
                             const double varargin_1_Beta[20],
                             double varargin_1_Bias);

#ifdef __cplusplus
}
#endif

#endif
/* End of code generation (RegressionLinear.h) */
