/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * incrementalClassificationLinear.h
 *
 * Code generation for function 'incrementalClassificationLinear'
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
void c_incrementalClassificationLine(
    myIncrLearn_mexStackData *SD, const emlrtStack *sp,
    const uint8_T this_ClassNames_codes[2],
    const cell_wrap_1 this_ClassNames_categoryNames[2],
    const real_T this_Prior[2], const emxArray_real_T *scores,
    const boolean_T indsToExclude_data[], int32_T indsToExclude_size,
    b_categorical *labels);

void d_incrementalClassificationLine(
    myIncrLearn_mexStackData *SD, const emlrtStack *sp,
    e_incrementalClassificationLine *this, const uint8_T Y_codes_data[],
    const int32_T Y_codes_size[2], const cell_wrap_22 Y_categoryNames[2],
    boolean_T Y_isOrdinal, const emxArray_real_T *W,
    const boolean_T indsToExclude_data[], int32_T indsToExclude_size,
    emxArray_int32_T *Yout);

/* End of code generation (incrementalClassificationLinear.h) */
