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
void Learner_fitWithoutValidation(myIncrLearn_mexStackData *SD,
                                  const emlrtStack *sp,
                                  e_incrementalClassificationLine *this,
                                  const emxArray_real_T *X,
                                  const c_categorical *Y,
                                  const emxArray_real_T *W);

/* End of code generation (Learner.h) */
