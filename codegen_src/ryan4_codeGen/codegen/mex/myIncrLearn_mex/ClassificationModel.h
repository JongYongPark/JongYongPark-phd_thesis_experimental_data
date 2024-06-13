/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * ClassificationModel.h
 *
 * Code generation for function 'ClassificationModel'
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
void c_ClassificationModel_adjustWei(
    myIncrLearn_mexStackData *SD, const emlrtStack *sp,
    const uint8_T this_ClassNames_codes[2],
    const cell_wrap_1 this_ClassNames_categoryNames[2],
    const real_T this_Prior[2], boolean_T this_PriorDefined,
    const real_T this_Impl_Beta[60], real_T this_Impl_Bias,
    const emxArray_real_T *X, const uint8_T Y_codes_data[],
    const int32_T Y_codes_size[2], const cell_wrap_22 Y_categoryNames[2],
    boolean_T Y_isProtected, boolean_T Y_isOrdinal,
    real_T Y_numCategoriesUpperBound, emxArray_real_T *W,
    emxArray_real_T *windowMetrics, boolean_T indsToExclude_data[],
    int32_T *indsToExclude_size);

void c_ClassificationModel_predictWi(
    myIncrLearn_mexStackData *SD, const emlrtStack *sp,
    const uint8_T this_ClassNames_codes[2],
    const cell_wrap_1 this_ClassNames_categoryNames[2],
    const real_T this_Prior[2], const real_T this_Impl_Beta[60],
    real_T this_Impl_Bias, const emxArray_real_T *X,
    const boolean_T indsToExclude_data[], int32_T indsToExclude_size,
    b_categorical *varargout_1, emxArray_real_T *varargout_2);

void c_ClassificationModel_prepareRa(
    const emlrtStack *sp, const e_incrementalClassificationLine *this,
    const emxArray_real_T *X, const c_categorical *Y, const emxArray_real_T *W,
    boolean_T indsToExclude_data[], int32_T *indsToExclude_size);

void c_ClassificationModel_verifyCla(
    const emlrtStack *sp, const uint8_T this_ClassNames_codes[2],
    const cell_wrap_1 this_ClassNames_categoryNames[2],
    const uint8_T Y_codes_data[], const int32_T Y_codes_size[2],
    const cell_wrap_22 Y_categoryNames[2], boolean_T Y_isOrdinal,
    const boolean_T indsToExclude_data[], int32_T indsToExclude_size,
    emxArray_int32_T *Ynum);

/* End of code generation (ClassificationModel.h) */
