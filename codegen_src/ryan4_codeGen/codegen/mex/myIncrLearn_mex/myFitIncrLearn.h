/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * myFitIncrLearn.h
 *
 * Code generation for function 'myFitIncrLearn'
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
void myFitIncrLearn(myIncrLearn_mexStackData *SD, const emlrtStack *sp,
                    e_incrementalClassificationLine *incrementalModel,
                    const emxArray_real_T *X, const c_categorical *Y);

/* End of code generation (myFitIncrLearn.h) */