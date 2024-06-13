/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * RegressionLinear.c
 *
 * Code generation for function 'RegressionLinear'
 *
 */

/* Include files */
#include "RegressionLinear.h"
#include "RegressionLinearModel_types.h"
#include "rt_nonfinite.h"
#include <string.h>

/* Function Definitions */
void RegressionLinear_update(RegressionLinear *obj,
                             const double varargin_1_Beta[20],
                             double varargin_1_Bias)
{
  memcpy(&obj->Beta[0], &varargin_1_Beta[0], 20U * sizeof(double));
  obj->Bias = varargin_1_Bias;
}

/* End of code generation (RegressionLinear.c) */
