/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * find.h
 *
 * Code generation for function 'find'
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
void b_eml_find(const emlrtStack *sp, const boolean_T x_data[], int32_T x_size,
                emxArray_int32_T *i);

void eml_find(const emlrtStack *sp, const boolean_T x[2], int32_T i_data[],
              int32_T *i_size);

/* End of code generation (find.h) */