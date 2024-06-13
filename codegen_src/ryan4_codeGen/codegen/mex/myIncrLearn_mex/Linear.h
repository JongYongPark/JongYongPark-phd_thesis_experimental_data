/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Linear.h
 *
 * Code generation for function 'Linear'
 *
 */

#pragma once

/* Include files */
#include "myIncrLearn_mex_types.h"
#include "rtwtypes.h"
#include "emlrt.h"
#include "mex.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function Declarations */
void Linear_score(const emlrtStack *sp, const real_T this_Impl_Beta[60],
                  real_T this_Impl_Bias, const emxArray_real_T *X,
                  const boolean_T indsToExclude_data[],
                  const int32_T *indsToExclude_size, emxArray_real_T *s);

void c_Linear_fitModelWithoutValidat(const emlrtStack *sp,
                                     e_incrementalClassificationLine *this,
                                     const emxArray_real_T *X,
                                     const emxArray_int32_T *Y,
                                     const boolean_T indsToExclude_data[],
                                     int32_T indsToExclude_size,
                                     uint32_T obsCount);

/* End of code generation (Linear.h) */
