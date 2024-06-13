/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * LinearImpl.h
 *
 * Code generation for function 'LinearImpl'
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
void LinearImpl_score(const emlrtStack *sp, const real_T this_Beta[60],
                      real_T this_Bias, const emxArray_real_T *X,
                      const boolean_T indsToExclude_data[],
                      int32_T indsToExclude_size, emxArray_real_T *s);

/* End of code generation (LinearImpl.h) */
