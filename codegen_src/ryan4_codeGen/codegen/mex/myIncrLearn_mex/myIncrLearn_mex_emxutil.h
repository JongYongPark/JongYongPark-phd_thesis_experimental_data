/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * myIncrLearn_mex_emxutil.h
 *
 * Code generation for function 'myIncrLearn_mex_emxutil'
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
void c_emxFreeStruct_incrementalClas(const emlrtStack *sp,
                                     e_incrementalClassificationLine *pStruct);

void c_emxInitStruct_incrementalClas(const emlrtStack *sp,
                                     e_incrementalClassificationLine *pStruct,
                                     const emlrtRTEInfo *srcLocation);

void emxCopyStruct_cell_wrap_1(const emlrtStack *sp, cell_wrap_1 *dst,
                               const cell_wrap_1 *src,
                               const emlrtRTEInfo *srcLocation);

void emxCopy_char_T(const emlrtStack *sp, emxArray_char_T **dst,
                    emxArray_char_T *const *src,
                    const emlrtRTEInfo *srcLocation);

void emxEnsureCapacity_cell_wrap_1(const emlrtStack *sp, cell_wrap_1 data[4],
                                   int32_T size, int32_T oldNumel,
                                   const emlrtRTEInfo *srcLocation);

void emxEnsureCapacity_cell_wrap_11(const emlrtStack *sp, cell_wrap_1 data[2],
                                    int32_T size, int32_T oldNumel,
                                    const emlrtRTEInfo *srcLocation);

void emxEnsureCapacity_cell_wrap_12(const emlrtStack *sp,
                                    emxArray_cell_wrap_1 *emxArray,
                                    int32_T oldNumel,
                                    const emlrtRTEInfo *srcLocation);

void emxEnsureCapacity_char_T(const emlrtStack *sp, emxArray_char_T *emxArray,
                              int32_T oldNumel,
                              const emlrtRTEInfo *srcLocation);

void emxEnsureCapacity_int32_T(const emlrtStack *sp, emxArray_int32_T *emxArray,
                               int32_T oldNumel,
                               const emlrtRTEInfo *srcLocation);

void emxEnsureCapacity_real_T(const emlrtStack *sp, emxArray_real_T *emxArray,
                              int32_T oldNumel,
                              const emlrtRTEInfo *srcLocation);

void emxEnsureCapacity_uint32_T(const emlrtStack *sp,
                                emxArray_uint32_T *emxArray, int32_T oldNumel,
                                const emlrtRTEInfo *srcLocation);

void emxExpand_cell_wrap_1(const emlrtStack *sp, emxArray_cell_wrap_1 *emxArray,
                           int32_T fromIndex, int32_T toIndex,
                           const emlrtRTEInfo *srcLocation);

void emxExpand_cell_wrap_1_2(const emlrtStack *sp, cell_wrap_1 data[2],
                             int32_T fromIndex, int32_T toIndex,
                             const emlrtRTEInfo *srcLocation);

void emxExpand_cell_wrap_1_4(const emlrtStack *sp, cell_wrap_1 data[4],
                             int32_T fromIndex, int32_T toIndex,
                             const emlrtRTEInfo *srcLocation);

void emxFreeMatrix_cell_wrap_1(const emlrtStack *sp, cell_wrap_1 pMatrix[2]);

void emxFreeMatrix_cell_wrap_11(const emlrtStack *sp, cell_wrap_1 pMatrix[3]);

void emxFreeStruct_categorical(const emlrtStack *sp, categorical *pStruct);

void emxFreeStruct_categorical1(const emlrtStack *sp, b_categorical *pStruct);

void emxFreeStruct_cell_wrap_1(const emlrtStack *sp, cell_wrap_1 *pStruct);

void emxFree_cell_wrap_1(const emlrtStack *sp,
                         emxArray_cell_wrap_1 **pEmxArray);

void emxFree_cell_wrap_1_2(const emlrtStack *sp,
                           emxArray_cell_wrap_1_2 *pEmxArray);

void emxFree_cell_wrap_1_4(const emlrtStack *sp,
                           emxArray_cell_wrap_1_4 *pEmxArray);

void emxFree_char_T(const emlrtStack *sp, emxArray_char_T **pEmxArray);

void emxFree_int32_T(const emlrtStack *sp, emxArray_int32_T **pEmxArray);

void emxFree_real_T(const emlrtStack *sp, emxArray_real_T **pEmxArray);

void emxFree_uint32_T(const emlrtStack *sp, emxArray_uint32_T **pEmxArray);

void emxInitMatrix_cell_wrap_1(const emlrtStack *sp, cell_wrap_1 pMatrix[2],
                               const emlrtRTEInfo *srcLocation);

void emxInitMatrix_cell_wrap_11(const emlrtStack *sp, cell_wrap_1 pMatrix[3],
                                const emlrtRTEInfo *srcLocation);

void emxInitStruct_categorical(const emlrtStack *sp, categorical *pStruct,
                               const emlrtRTEInfo *srcLocation);

void emxInitStruct_categorical1(const emlrtStack *sp, b_categorical *pStruct,
                                const emlrtRTEInfo *srcLocation);

void emxInitStruct_cell_wrap_1(const emlrtStack *sp, cell_wrap_1 *pStruct,
                               const emlrtRTEInfo *srcLocation,
                               boolean_T doPush);

void emxInit_cell_wrap_1(const emlrtStack *sp, emxArray_cell_wrap_1 **pEmxArray,
                         const emlrtRTEInfo *srcLocation);

void emxInit_cell_wrap_1_2(emxArray_cell_wrap_1_2 *pEmxArray);

void emxInit_cell_wrap_1_4(emxArray_cell_wrap_1_4 *pEmxArray);

void emxInit_char_T(const emlrtStack *sp, emxArray_char_T **pEmxArray,
                    const emlrtRTEInfo *srcLocation, boolean_T doPush);

void emxInit_int32_T(const emlrtStack *sp, emxArray_int32_T **pEmxArray,
                     int32_T numDimensions, const emlrtRTEInfo *srcLocation);

void emxInit_real_T(const emlrtStack *sp, emxArray_real_T **pEmxArray,
                    int32_T numDimensions, const emlrtRTEInfo *srcLocation);

void emxInit_uint32_T(const emlrtStack *sp, emxArray_uint32_T **pEmxArray,
                      const emlrtRTEInfo *srcLocation);

void emxTrim_cell_wrap_1(const emlrtStack *sp, emxArray_cell_wrap_1 *emxArray,
                         int32_T fromIndex, int32_T toIndex);

void emxTrim_cell_wrap_1_2(const emlrtStack *sp, cell_wrap_1 data[2],
                           int32_T fromIndex, int32_T toIndex);

void emxTrim_cell_wrap_1_4(const emlrtStack *sp, cell_wrap_1 data[4],
                           int32_T fromIndex, int32_T toIndex);

/* End of code generation (myIncrLearn_mex_emxutil.h) */
