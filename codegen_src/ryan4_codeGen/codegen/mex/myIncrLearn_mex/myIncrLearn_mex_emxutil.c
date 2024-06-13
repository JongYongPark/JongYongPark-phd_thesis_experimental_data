/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * myIncrLearn_mex_emxutil.c
 *
 * Code generation for function 'myIncrLearn_mex_emxutil'
 *
 */

/* Include files */
#include "myIncrLearn_mex_emxutil.h"
#include "myIncrLearn_mex_types.h"
#include "rt_nonfinite.h"
#include <string.h>

/* Function Definitions */
void c_emxFreeStruct_incrementalClas(const emlrtStack *sp,
                                     e_incrementalClassificationLine *pStruct)
{
  emxFreeStruct_categorical(sp, &pStruct->ClassNames);
}

void c_emxInitStruct_incrementalClas(const emlrtStack *sp,
                                     e_incrementalClassificationLine *pStruct,
                                     const emlrtRTEInfo *srcLocation)
{
  emxInitStruct_categorical(sp, &pStruct->ClassNames, srcLocation);
}

void emxCopyStruct_cell_wrap_1(const emlrtStack *sp, cell_wrap_1 *dst,
                               const cell_wrap_1 *src,
                               const emlrtRTEInfo *srcLocation)
{
  emxCopy_char_T(sp, &dst->f1, &src->f1, srcLocation);
}

void emxCopy_char_T(const emlrtStack *sp, emxArray_char_T **dst,
                    emxArray_char_T *const *src,
                    const emlrtRTEInfo *srcLocation)
{
  int32_T i;
  int32_T numElDst;
  int32_T numElSrc;
  numElDst = 1;
  numElSrc = 1;
  for (i = 0; i < (*dst)->numDimensions; i++) {
    numElDst *= (*dst)->size[i];
    numElSrc *= (*src)->size[i];
  }
  for (i = 0; i < (*dst)->numDimensions; i++) {
    (*dst)->size[i] = (*src)->size[i];
  }
  emxEnsureCapacity_char_T(sp, *dst, numElDst, srcLocation);
  for (i = 0; i < numElSrc; i++) {
    (*dst)->data[i] = (*src)->data[i];
  }
}

void emxEnsureCapacity_cell_wrap_1(const emlrtStack *sp, cell_wrap_1 data[4],
                                   int32_T size, int32_T oldNumel,
                                   const emlrtRTEInfo *srcLocation)
{
  if (oldNumel < 0) {
    oldNumel = 0;
  }
  if (oldNumel > size) {
    emxTrim_cell_wrap_1_4(sp, data, size, oldNumel);
  } else if (oldNumel < size) {
    emxExpand_cell_wrap_1_4(sp, data, oldNumel, size, srcLocation);
  }
}

void emxEnsureCapacity_cell_wrap_11(const emlrtStack *sp, cell_wrap_1 data[2],
                                    int32_T size, int32_T oldNumel,
                                    const emlrtRTEInfo *srcLocation)
{
  if (oldNumel < 0) {
    oldNumel = 0;
  }
  if (oldNumel > size) {
    emxTrim_cell_wrap_1_2(sp, data, size, oldNumel);
  } else if (oldNumel < size) {
    emxExpand_cell_wrap_1_2(sp, data, oldNumel, size, srcLocation);
  }
}

void emxEnsureCapacity_cell_wrap_12(const emlrtStack *sp,
                                    emxArray_cell_wrap_1 *emxArray,
                                    int32_T oldNumel,
                                    const emlrtRTEInfo *srcLocation)
{
  int32_T i;
  int32_T newNumel;
  void *newData;
  if (oldNumel < 0) {
    oldNumel = 0;
  }
  newNumel = 1;
  for (i = 0; i < emxArray->numDimensions; i++) {
    newNumel = (int32_T)emlrtSizeMulR2012b((size_t)(uint32_T)newNumel,
                                           (size_t)(uint32_T)emxArray->size[i],
                                           srcLocation, (emlrtCTX)sp);
  }
  if (newNumel > emxArray->allocatedSize) {
    i = emxArray->allocatedSize;
    if (i < 16) {
      i = 16;
    }
    while (i < newNumel) {
      if (i > 1073741823) {
        i = MAX_int32_T;
      } else {
        i *= 2;
      }
    }
    newData = emlrtCallocMex((uint32_T)i, sizeof(cell_wrap_1));
    if (newData == NULL) {
      emlrtHeapAllocationErrorR2012b(srcLocation, (emlrtCTX)sp);
    }
    if (emxArray->data != NULL) {
      memcpy(newData, emxArray->data, sizeof(cell_wrap_1) * oldNumel);
      if (emxArray->canFreeData) {
        emlrtFreeMex(emxArray->data);
      }
    }
    emxArray->data = (cell_wrap_1 *)newData;
    emxArray->allocatedSize = i;
    emxArray->canFreeData = true;
  }
  if (oldNumel > newNumel) {
    emxTrim_cell_wrap_1(sp, emxArray, newNumel, oldNumel);
  } else if (oldNumel < newNumel) {
    emxExpand_cell_wrap_1(sp, emxArray, oldNumel, newNumel, srcLocation);
  }
}

void emxEnsureCapacity_char_T(const emlrtStack *sp, emxArray_char_T *emxArray,
                              int32_T oldNumel, const emlrtRTEInfo *srcLocation)
{
  int32_T i;
  int32_T newNumel;
  void *newData;
  if (oldNumel < 0) {
    oldNumel = 0;
  }
  newNumel = 1;
  for (i = 0; i < emxArray->numDimensions; i++) {
    newNumel = (int32_T)emlrtSizeMulR2012b((size_t)(uint32_T)newNumel,
                                           (size_t)(uint32_T)emxArray->size[i],
                                           srcLocation, (emlrtCTX)sp);
  }
  if (newNumel > emxArray->allocatedSize) {
    i = emxArray->allocatedSize;
    if (i < 16) {
      i = 16;
    }
    while (i < newNumel) {
      if (i > 1073741823) {
        i = MAX_int32_T;
      } else {
        i *= 2;
      }
    }
    newData = emlrtCallocMex((uint32_T)i, sizeof(char_T));
    if (newData == NULL) {
      emlrtHeapAllocationErrorR2012b(srcLocation, (emlrtCTX)sp);
    }
    if (emxArray->data != NULL) {
      memcpy(newData, emxArray->data, sizeof(char_T) * oldNumel);
      if (emxArray->canFreeData) {
        emlrtFreeMex(emxArray->data);
      }
    }
    emxArray->data = (char_T *)newData;
    emxArray->allocatedSize = i;
    emxArray->canFreeData = true;
  }
}

void emxEnsureCapacity_int32_T(const emlrtStack *sp, emxArray_int32_T *emxArray,
                               int32_T oldNumel,
                               const emlrtRTEInfo *srcLocation)
{
  int32_T i;
  int32_T newNumel;
  void *newData;
  if (oldNumel < 0) {
    oldNumel = 0;
  }
  newNumel = 1;
  for (i = 0; i < emxArray->numDimensions; i++) {
    newNumel = (int32_T)emlrtSizeMulR2012b((size_t)(uint32_T)newNumel,
                                           (size_t)(uint32_T)emxArray->size[i],
                                           srcLocation, (emlrtCTX)sp);
  }
  if (newNumel > emxArray->allocatedSize) {
    i = emxArray->allocatedSize;
    if (i < 16) {
      i = 16;
    }
    while (i < newNumel) {
      if (i > 1073741823) {
        i = MAX_int32_T;
      } else {
        i *= 2;
      }
    }
    newData = emlrtCallocMex((uint32_T)i, sizeof(int32_T));
    if (newData == NULL) {
      emlrtHeapAllocationErrorR2012b(srcLocation, (emlrtCTX)sp);
    }
    if (emxArray->data != NULL) {
      memcpy(newData, emxArray->data, sizeof(int32_T) * oldNumel);
      if (emxArray->canFreeData) {
        emlrtFreeMex(emxArray->data);
      }
    }
    emxArray->data = (int32_T *)newData;
    emxArray->allocatedSize = i;
    emxArray->canFreeData = true;
  }
}

void emxEnsureCapacity_real_T(const emlrtStack *sp, emxArray_real_T *emxArray,
                              int32_T oldNumel, const emlrtRTEInfo *srcLocation)
{
  int32_T i;
  int32_T newNumel;
  void *newData;
  if (oldNumel < 0) {
    oldNumel = 0;
  }
  newNumel = 1;
  for (i = 0; i < emxArray->numDimensions; i++) {
    newNumel = (int32_T)emlrtSizeMulR2012b((size_t)(uint32_T)newNumel,
                                           (size_t)(uint32_T)emxArray->size[i],
                                           srcLocation, (emlrtCTX)sp);
  }
  if (newNumel > emxArray->allocatedSize) {
    i = emxArray->allocatedSize;
    if (i < 16) {
      i = 16;
    }
    while (i < newNumel) {
      if (i > 1073741823) {
        i = MAX_int32_T;
      } else {
        i *= 2;
      }
    }
    newData = emlrtCallocMex((uint32_T)i, sizeof(real_T));
    if (newData == NULL) {
      emlrtHeapAllocationErrorR2012b(srcLocation, (emlrtCTX)sp);
    }
    if (emxArray->data != NULL) {
      memcpy(newData, emxArray->data, sizeof(real_T) * oldNumel);
      if (emxArray->canFreeData) {
        emlrtFreeMex(emxArray->data);
      }
    }
    emxArray->data = (real_T *)newData;
    emxArray->allocatedSize = i;
    emxArray->canFreeData = true;
  }
}

void emxEnsureCapacity_uint32_T(const emlrtStack *sp,
                                emxArray_uint32_T *emxArray, int32_T oldNumel,
                                const emlrtRTEInfo *srcLocation)
{
  int32_T i;
  int32_T newNumel;
  void *newData;
  if (oldNumel < 0) {
    oldNumel = 0;
  }
  newNumel = 1;
  for (i = 0; i < emxArray->numDimensions; i++) {
    newNumel = (int32_T)emlrtSizeMulR2012b((size_t)(uint32_T)newNumel,
                                           (size_t)(uint32_T)emxArray->size[i],
                                           srcLocation, (emlrtCTX)sp);
  }
  if (newNumel > emxArray->allocatedSize) {
    i = emxArray->allocatedSize;
    if (i < 16) {
      i = 16;
    }
    while (i < newNumel) {
      if (i > 1073741823) {
        i = MAX_int32_T;
      } else {
        i *= 2;
      }
    }
    newData = emlrtCallocMex((uint32_T)i, sizeof(uint32_T));
    if (newData == NULL) {
      emlrtHeapAllocationErrorR2012b(srcLocation, (emlrtCTX)sp);
    }
    if (emxArray->data != NULL) {
      memcpy(newData, emxArray->data, sizeof(uint32_T) * oldNumel);
      if (emxArray->canFreeData) {
        emlrtFreeMex(emxArray->data);
      }
    }
    emxArray->data = (uint32_T *)newData;
    emxArray->allocatedSize = i;
    emxArray->canFreeData = true;
  }
}

void emxExpand_cell_wrap_1(const emlrtStack *sp, emxArray_cell_wrap_1 *emxArray,
                           int32_T fromIndex, int32_T toIndex,
                           const emlrtRTEInfo *srcLocation)
{
  int32_T i;
  for (i = fromIndex; i < toIndex; i++) {
    emxInitStruct_cell_wrap_1(sp, &emxArray->data[i], srcLocation, false);
  }
}

void emxExpand_cell_wrap_1_2(const emlrtStack *sp, cell_wrap_1 data[2],
                             int32_T fromIndex, int32_T toIndex,
                             const emlrtRTEInfo *srcLocation)
{
  int32_T i;
  for (i = fromIndex; i < toIndex; i++) {
    emxInitStruct_cell_wrap_1(sp, &data[i], srcLocation, false);
  }
}

void emxExpand_cell_wrap_1_4(const emlrtStack *sp, cell_wrap_1 data[4],
                             int32_T fromIndex, int32_T toIndex,
                             const emlrtRTEInfo *srcLocation)
{
  int32_T i;
  for (i = fromIndex; i < toIndex; i++) {
    emxInitStruct_cell_wrap_1(sp, &data[i], srcLocation, false);
  }
}

void emxFreeMatrix_cell_wrap_1(const emlrtStack *sp, cell_wrap_1 pMatrix[2])
{
  int32_T i;
  for (i = 0; i < 2; i++) {
    emxFreeStruct_cell_wrap_1(sp, &pMatrix[i]);
  }
}

void emxFreeMatrix_cell_wrap_11(const emlrtStack *sp, cell_wrap_1 pMatrix[3])
{
  int32_T i;
  for (i = 0; i < 3; i++) {
    emxFreeStruct_cell_wrap_1(sp, &pMatrix[i]);
  }
}

void emxFreeStruct_categorical(const emlrtStack *sp, categorical *pStruct)
{
  emxFreeMatrix_cell_wrap_1(sp, pStruct->categoryNames);
}

void emxFreeStruct_categorical1(const emlrtStack *sp, b_categorical *pStruct)
{
  emxFree_uint32_T(sp, &pStruct->codes);
  emxFree_cell_wrap_1(sp, &pStruct->categoryNames);
}

void emxFreeStruct_cell_wrap_1(const emlrtStack *sp, cell_wrap_1 *pStruct)
{
  emxFree_char_T(sp, &pStruct->f1);
}

void emxFree_cell_wrap_1(const emlrtStack *sp, emxArray_cell_wrap_1 **pEmxArray)
{
  int32_T i;
  if (*pEmxArray != (emxArray_cell_wrap_1 *)NULL) {
    if ((*pEmxArray)->data != (cell_wrap_1 *)NULL) {
      int32_T numEl;
      numEl = 1;
      for (i = 0; i < (*pEmxArray)->numDimensions; i++) {
        numEl *= (*pEmxArray)->size[i];
      }
      for (i = 0; i < numEl; i++) {
        emxFreeStruct_cell_wrap_1(sp, &(*pEmxArray)->data[i]);
      }
      if ((*pEmxArray)->canFreeData) {
        emlrtFreeMex((*pEmxArray)->data);
      }
    }
    emlrtFreeMex((*pEmxArray)->size);
    emlrtRemoveHeapReference((emlrtCTX)sp, (void *)pEmxArray);
    emlrtFreeEmxArray(*pEmxArray);
    *pEmxArray = (emxArray_cell_wrap_1 *)NULL;
  }
}

void emxFree_cell_wrap_1_2(const emlrtStack *sp,
                           emxArray_cell_wrap_1_2 *pEmxArray)
{
  int32_T i;
  int32_T numEl;
  numEl = pEmxArray->size[0];
  for (i = 0; i < numEl; i++) {
    emxFreeStruct_cell_wrap_1(sp, &pEmxArray->data[i]);
  }
}

void emxFree_cell_wrap_1_4(const emlrtStack *sp,
                           emxArray_cell_wrap_1_4 *pEmxArray)
{
  int32_T i;
  int32_T numEl;
  numEl = pEmxArray->size[0];
  for (i = 0; i < numEl; i++) {
    emxFreeStruct_cell_wrap_1(sp, &pEmxArray->data[i]);
  }
}

void emxFree_char_T(const emlrtStack *sp, emxArray_char_T **pEmxArray)
{
  if (*pEmxArray != (emxArray_char_T *)NULL) {
    if (((*pEmxArray)->data != (char_T *)NULL) && (*pEmxArray)->canFreeData) {
      emlrtFreeMex((*pEmxArray)->data);
    }
    emlrtFreeMex((*pEmxArray)->size);
    emlrtRemoveHeapReference((emlrtCTX)sp, (void *)pEmxArray);
    emlrtFreeEmxArray(*pEmxArray);
    *pEmxArray = (emxArray_char_T *)NULL;
  }
}

void emxFree_int32_T(const emlrtStack *sp, emxArray_int32_T **pEmxArray)
{
  if (*pEmxArray != (emxArray_int32_T *)NULL) {
    if (((*pEmxArray)->data != (int32_T *)NULL) && (*pEmxArray)->canFreeData) {
      emlrtFreeMex((*pEmxArray)->data);
    }
    emlrtFreeMex((*pEmxArray)->size);
    emlrtRemoveHeapReference((emlrtCTX)sp, (void *)pEmxArray);
    emlrtFreeEmxArray(*pEmxArray);
    *pEmxArray = (emxArray_int32_T *)NULL;
  }
}

void emxFree_real_T(const emlrtStack *sp, emxArray_real_T **pEmxArray)
{
  if (*pEmxArray != (emxArray_real_T *)NULL) {
    if (((*pEmxArray)->data != (real_T *)NULL) && (*pEmxArray)->canFreeData) {
      emlrtFreeMex((*pEmxArray)->data);
    }
    emlrtFreeMex((*pEmxArray)->size);
    emlrtRemoveHeapReference((emlrtCTX)sp, (void *)pEmxArray);
    emlrtFreeEmxArray(*pEmxArray);
    *pEmxArray = (emxArray_real_T *)NULL;
  }
}

void emxFree_uint32_T(const emlrtStack *sp, emxArray_uint32_T **pEmxArray)
{
  if (*pEmxArray != (emxArray_uint32_T *)NULL) {
    if (((*pEmxArray)->data != (uint32_T *)NULL) && (*pEmxArray)->canFreeData) {
      emlrtFreeMex((*pEmxArray)->data);
    }
    emlrtFreeMex((*pEmxArray)->size);
    emlrtRemoveHeapReference((emlrtCTX)sp, (void *)pEmxArray);
    emlrtFreeEmxArray(*pEmxArray);
    *pEmxArray = (emxArray_uint32_T *)NULL;
  }
}

void emxInitMatrix_cell_wrap_1(const emlrtStack *sp, cell_wrap_1 pMatrix[2],
                               const emlrtRTEInfo *srcLocation)
{
  int32_T i;
  for (i = 0; i < 2; i++) {
    emxInitStruct_cell_wrap_1(sp, &pMatrix[i], srcLocation, true);
  }
}

void emxInitMatrix_cell_wrap_11(const emlrtStack *sp, cell_wrap_1 pMatrix[3],
                                const emlrtRTEInfo *srcLocation)
{
  int32_T i;
  for (i = 0; i < 3; i++) {
    emxInitStruct_cell_wrap_1(sp, &pMatrix[i], srcLocation, true);
  }
}

void emxInitStruct_categorical(const emlrtStack *sp, categorical *pStruct,
                               const emlrtRTEInfo *srcLocation)
{
  emxInitMatrix_cell_wrap_1(sp, pStruct->categoryNames, srcLocation);
}

void emxInitStruct_categorical1(const emlrtStack *sp, b_categorical *pStruct,
                                const emlrtRTEInfo *srcLocation)
{
  emxInit_uint32_T(sp, &pStruct->codes, srcLocation);
  emxInit_cell_wrap_1(sp, &pStruct->categoryNames, srcLocation);
}

void emxInitStruct_cell_wrap_1(const emlrtStack *sp, cell_wrap_1 *pStruct,
                               const emlrtRTEInfo *srcLocation,
                               boolean_T doPush)
{
  emxInit_char_T(sp, &pStruct->f1, srcLocation, doPush);
}

void emxInit_cell_wrap_1(const emlrtStack *sp, emxArray_cell_wrap_1 **pEmxArray,
                         const emlrtRTEInfo *srcLocation)
{
  emxArray_cell_wrap_1 *emxArray;
  *pEmxArray =
      (emxArray_cell_wrap_1 *)emlrtMallocEmxArray(sizeof(emxArray_cell_wrap_1));
  if ((void *)*pEmxArray == NULL) {
    emlrtHeapAllocationErrorR2012b(srcLocation, (emlrtCTX)sp);
  }
  emlrtPushHeapReferenceStackEmxArray((emlrtCTX)sp, true, (void *)pEmxArray,
                                      (void *)&emxFree_cell_wrap_1, NULL, NULL,
                                      NULL);
  emxArray = *pEmxArray;
  emxArray->data = (cell_wrap_1 *)NULL;
  emxArray->numDimensions = 1;
  emxArray->size = (int32_T *)emlrtMallocMex(sizeof(int32_T));
  if ((void *)emxArray->size == NULL) {
    emlrtHeapAllocationErrorR2012b(srcLocation, (emlrtCTX)sp);
  }
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  emxArray->size[0] = 0;
}

void emxInit_cell_wrap_1_2(emxArray_cell_wrap_1_2 *pEmxArray)
{
  pEmxArray->size[0] = 0;
}

void emxInit_cell_wrap_1_4(emxArray_cell_wrap_1_4 *pEmxArray)
{
  pEmxArray->size[0] = 0;
}

void emxInit_char_T(const emlrtStack *sp, emxArray_char_T **pEmxArray,
                    const emlrtRTEInfo *srcLocation, boolean_T doPush)
{
  emxArray_char_T *emxArray;
  int32_T i;
  *pEmxArray = (emxArray_char_T *)emlrtMallocEmxArray(sizeof(emxArray_char_T));
  if ((void *)*pEmxArray == NULL) {
    emlrtHeapAllocationErrorR2012b(srcLocation, (emlrtCTX)sp);
  }
  if (doPush) {
    emlrtPushHeapReferenceStackEmxArray((emlrtCTX)sp, true, (void *)pEmxArray,
                                        (void *)&emxFree_char_T, NULL, NULL,
                                        NULL);
  }
  emxArray = *pEmxArray;
  emxArray->data = (char_T *)NULL;
  emxArray->numDimensions = 2;
  emxArray->size = (int32_T *)emlrtMallocMex(sizeof(int32_T) * 2U);
  if ((void *)emxArray->size == NULL) {
    emlrtHeapAllocationErrorR2012b(srcLocation, (emlrtCTX)sp);
  }
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < 2; i++) {
    emxArray->size[i] = 0;
  }
}

void emxInit_int32_T(const emlrtStack *sp, emxArray_int32_T **pEmxArray,
                     int32_T numDimensions, const emlrtRTEInfo *srcLocation)
{
  emxArray_int32_T *emxArray;
  int32_T i;
  *pEmxArray =
      (emxArray_int32_T *)emlrtMallocEmxArray(sizeof(emxArray_int32_T));
  if ((void *)*pEmxArray == NULL) {
    emlrtHeapAllocationErrorR2012b(srcLocation, (emlrtCTX)sp);
  }
  emlrtPushHeapReferenceStackEmxArray((emlrtCTX)sp, true, (void *)pEmxArray,
                                      (void *)&emxFree_int32_T, NULL, NULL,
                                      NULL);
  emxArray = *pEmxArray;
  emxArray->data = (int32_T *)NULL;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int32_T *)emlrtMallocMex(sizeof(int32_T) * numDimensions);
  if ((void *)emxArray->size == NULL) {
    emlrtHeapAllocationErrorR2012b(srcLocation, (emlrtCTX)sp);
  }
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < numDimensions; i++) {
    emxArray->size[i] = 0;
  }
}

void emxInit_real_T(const emlrtStack *sp, emxArray_real_T **pEmxArray,
                    int32_T numDimensions, const emlrtRTEInfo *srcLocation)
{
  emxArray_real_T *emxArray;
  int32_T i;
  *pEmxArray = (emxArray_real_T *)emlrtMallocEmxArray(sizeof(emxArray_real_T));
  if ((void *)*pEmxArray == NULL) {
    emlrtHeapAllocationErrorR2012b(srcLocation, (emlrtCTX)sp);
  }
  emlrtPushHeapReferenceStackEmxArray((emlrtCTX)sp, true, (void *)pEmxArray,
                                      (void *)&emxFree_real_T, NULL, NULL,
                                      NULL);
  emxArray = *pEmxArray;
  emxArray->data = (real_T *)NULL;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int32_T *)emlrtMallocMex(sizeof(int32_T) * numDimensions);
  if ((void *)emxArray->size == NULL) {
    emlrtHeapAllocationErrorR2012b(srcLocation, (emlrtCTX)sp);
  }
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < numDimensions; i++) {
    emxArray->size[i] = 0;
  }
}

void emxInit_uint32_T(const emlrtStack *sp, emxArray_uint32_T **pEmxArray,
                      const emlrtRTEInfo *srcLocation)
{
  emxArray_uint32_T *emxArray;
  *pEmxArray =
      (emxArray_uint32_T *)emlrtMallocEmxArray(sizeof(emxArray_uint32_T));
  if ((void *)*pEmxArray == NULL) {
    emlrtHeapAllocationErrorR2012b(srcLocation, (emlrtCTX)sp);
  }
  emlrtPushHeapReferenceStackEmxArray((emlrtCTX)sp, true, (void *)pEmxArray,
                                      (void *)&emxFree_uint32_T, NULL, NULL,
                                      NULL);
  emxArray = *pEmxArray;
  emxArray->data = (uint32_T *)NULL;
  emxArray->numDimensions = 1;
  emxArray->size = (int32_T *)emlrtMallocMex(sizeof(int32_T));
  if ((void *)emxArray->size == NULL) {
    emlrtHeapAllocationErrorR2012b(srcLocation, (emlrtCTX)sp);
  }
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  emxArray->size[0] = 0;
}

void emxTrim_cell_wrap_1(const emlrtStack *sp, emxArray_cell_wrap_1 *emxArray,
                         int32_T fromIndex, int32_T toIndex)
{
  int32_T i;
  for (i = fromIndex; i < toIndex; i++) {
    emxFreeStruct_cell_wrap_1(sp, &emxArray->data[i]);
  }
}

void emxTrim_cell_wrap_1_2(const emlrtStack *sp, cell_wrap_1 data[2],
                           int32_T fromIndex, int32_T toIndex)
{
  int32_T i;
  for (i = fromIndex; i < toIndex; i++) {
    emxFreeStruct_cell_wrap_1(sp, &data[i]);
  }
}

void emxTrim_cell_wrap_1_4(const emlrtStack *sp, cell_wrap_1 data[4],
                           int32_T fromIndex, int32_T toIndex)
{
  int32_T i;
  for (i = fromIndex; i < toIndex; i++) {
    emxFreeStruct_cell_wrap_1(sp, &data[i]);
  }
}

/* End of code generation (myIncrLearn_mex_emxutil.c) */
