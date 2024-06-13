/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * CompactRegressionSVM.h
 *
 * Code generation for function 'CompactRegressionSVM'
 *
 */

#pragma once

/* Include files */
#include "RegressionSVMModel_types.h"
#include "rtwtypes.h"
#include "emlrt.h"
#include "mex.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function Declarations */
void CompactRegressionSVM_update(const emlrtStack *sp,
                                 c_classreg_learning_regr_Compac *obj,
                                 const real_T varargin_1_Alpha[75],
                                 const real_T varargin_1_SupportVectors[150],
                                 real_T varargin_1_Scale,
                                 real_T varargin_1_Bias);

/* End of code generation (CompactRegressionSVM.h) */
