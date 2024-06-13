/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * getCategoryNames.h
 *
 * Code generation for function 'getCategoryNames'
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
void categorical_getCategoryNames(const emlrtStack *sp,
                                  const emxArray_cell_wrap_1 *valueSet,
                                  emxArray_cell_wrap_1 *outCategoryNames);

/* End of code generation (getCategoryNames.h) */
