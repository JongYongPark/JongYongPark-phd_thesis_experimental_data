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
void myPredictIncrLearn(myIncrLearn_mexStackData *SD, const emlrtStack *sp,
                        const e_incrementalClassificationLine incrementalModel,
                        const emxArray_real_T *X, b_categorical *labels,
                        emxArray_real_T *scores);

/* End of code generation (myPredictIncrLearn.h) */
