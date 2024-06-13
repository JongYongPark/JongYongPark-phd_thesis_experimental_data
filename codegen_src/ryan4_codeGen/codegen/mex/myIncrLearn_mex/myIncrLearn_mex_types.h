/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * myIncrLearn_mex_types.h
 *
 * Code generation for function 'myInitialModelIncrLearn'
 *
 */

#pragma once

/* Include files */
#include "rtwtypes.h"
#include "emlrt.h"

/* Type Definitions */
#ifndef typedef_struct1_T
#define typedef_struct1_T
typedef struct {
  real_T Cumulative;
  real_T Window;
} struct1_T;
#endif /* typedef_struct1_T */

#ifndef typedef_struct0_T
#define typedef_struct0_T
typedef struct {
  struct1_T ClassificationError;
  struct1_T HingeLoss;
} struct0_T;
#endif /* typedef_struct0_T */

#ifndef struct_emxArray_char_T
#define struct_emxArray_char_T
struct emxArray_char_T {
  char_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};
#endif /* struct_emxArray_char_T */
#ifndef typedef_emxArray_char_T
#define typedef_emxArray_char_T
typedef struct emxArray_char_T emxArray_char_T;
#endif /* typedef_emxArray_char_T */

#ifndef typedef_cell_wrap_1
#define typedef_cell_wrap_1
typedef struct {
  emxArray_char_T *f1;
} cell_wrap_1;
#endif /* typedef_cell_wrap_1 */

#ifndef typedef_categorical
#define typedef_categorical
typedef struct {
  uint8_T codes[2];
  cell_wrap_1 categoryNames[2];
} categorical;
#endif /* typedef_categorical */

#ifndef struct_emxArray_uint8_T_24075x1
#define struct_emxArray_uint8_T_24075x1
struct emxArray_uint8_T_24075x1 {
  uint8_T data[24075];
  int32_T size[2];
};
#endif /* struct_emxArray_uint8_T_24075x1 */
#ifndef typedef_emxArray_uint8_T_24075x1
#define typedef_emxArray_uint8_T_24075x1
typedef struct emxArray_uint8_T_24075x1 emxArray_uint8_T_24075x1;
#endif /* typedef_emxArray_uint8_T_24075x1 */

#ifndef struct_emxArray_char_T_1x7
#define struct_emxArray_char_T_1x7
struct emxArray_char_T_1x7 {
  char_T data[7];
  int32_T size[2];
};
#endif /* struct_emxArray_char_T_1x7 */
#ifndef typedef_emxArray_char_T_1x7
#define typedef_emxArray_char_T_1x7
typedef struct emxArray_char_T_1x7 emxArray_char_T_1x7;
#endif /* typedef_emxArray_char_T_1x7 */

#ifndef typedef_cell_wrap_22
#define typedef_cell_wrap_22
typedef struct {
  emxArray_char_T_1x7 f1;
} cell_wrap_22;
#endif /* typedef_cell_wrap_22 */

#ifndef struct_emxArray_int32_T
#define struct_emxArray_int32_T
struct emxArray_int32_T {
  int32_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};
#endif /* struct_emxArray_int32_T */
#ifndef typedef_emxArray_int32_T
#define typedef_emxArray_int32_T
typedef struct emxArray_int32_T emxArray_int32_T;
#endif /* typedef_emxArray_int32_T */

#ifndef typedef_emxArray_cell_wrap_1_4
#define typedef_emxArray_cell_wrap_1_4
typedef struct {
  cell_wrap_1 data[4];
  int32_T size[1];
} emxArray_cell_wrap_1_4;
#endif /* typedef_emxArray_cell_wrap_1_4 */

#ifndef typedef_emxArray_cell_wrap_1_2
#define typedef_emxArray_cell_wrap_1_2
typedef struct {
  cell_wrap_1 data[2];
  int32_T size[1];
} emxArray_cell_wrap_1_2;
#endif /* typedef_emxArray_cell_wrap_1_2 */

#ifndef struct_emxArray_real_T
#define struct_emxArray_real_T
struct emxArray_real_T {
  real_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};
#endif /* struct_emxArray_real_T */
#ifndef typedef_emxArray_real_T
#define typedef_emxArray_real_T
typedef struct emxArray_real_T emxArray_real_T;
#endif /* typedef_emxArray_real_T */

#ifndef struct_emxArray_uint32_T
#define struct_emxArray_uint32_T
struct emxArray_uint32_T {
  uint32_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};
#endif /* struct_emxArray_uint32_T */
#ifndef typedef_emxArray_uint32_T
#define typedef_emxArray_uint32_T
typedef struct emxArray_uint32_T emxArray_uint32_T;
#endif /* typedef_emxArray_uint32_T */

#ifndef typedef_emxArray_cell_wrap_1
#define typedef_emxArray_cell_wrap_1
typedef struct {
  cell_wrap_1 *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
} emxArray_cell_wrap_1;
#endif /* typedef_emxArray_cell_wrap_1 */

#ifndef typedef_b_categorical
#define typedef_b_categorical
typedef struct {
  emxArray_uint32_T *codes;
  emxArray_cell_wrap_1 *categoryNames;
} b_categorical;
#endif /* typedef_b_categorical */

#ifndef typedef_c_categorical
#define typedef_c_categorical
typedef struct {
  emxArray_uint8_T_24075x1 codes;
  cell_wrap_22 categoryNames[2];
  boolean_T isProtected;
  boolean_T isOrdinal;
  real_T numCategoriesUpperBound;
} c_categorical;
#endif /* typedef_c_categorical */

#ifndef typedef_c_incremental_coder_impl_ScaleI
#define typedef_c_incremental_coder_impl_ScaleI
typedef struct {
  real_T LearnRate;
  real_T Epsilon;
  real_T Beta[60];
  real_T Bias;
  uint32_T BatchIndex;
  real_T S2t[61];
  real_T Gt[61];
  real_T Mt[61];
  real_T Etat[61];
  real_T Ymt;
  real_T Rho;
  boolean_T YmtSet;
} c_incremental_coder_impl_ScaleI;
#endif /* typedef_c_incremental_coder_impl_ScaleI */

#ifndef typedef_e_incrementalClassificationLine
#define typedef_e_incrementalClassificationLine
typedef struct {
  uint32_T NumTrainingObservations;
  boolean_T IsWarm;
  struct0_T Metrics;
  real_T MetricBuffer[400];
  real_T WeightBuffer[200];
  uint32_T BufferSize;
  uint32_T NumMetricObservations;
  categorical ClassNames;
  real_T Prior[2];
  char_T CharClassNames[14];
  real_T WeightsPerClass[2];
  boolean_T PriorDefined;
  boolean_T PriorReset;
  uint32_T NumEstimationObservations;
  boolean_T parametersAdjusted;
  c_incremental_coder_impl_ScaleI Impl;
} e_incrementalClassificationLine;
#endif /* typedef_e_incrementalClassificationLine */

#ifndef typedef_b_removeUtil
#define typedef_b_removeUtil
typedef struct {
  int16_T convert_data[24075];
  int16_T tmp_data[24075];
} b_removeUtil;
#endif /* typedef_b_removeUtil */

#ifndef typedef_f_incrementalClassificationLine
#define typedef_f_incrementalClassificationLine
typedef struct {
  boolean_T C_data[48150];
} f_incrementalClassificationLine;
#endif /* typedef_f_incrementalClassificationLine */

#ifndef typedef_e_ClassificationModel_adjustWei
#define typedef_e_ClassificationModel_adjustWei
typedef struct {
  boolean_T C_data[48150];
} e_ClassificationModel_adjustWei;
#endif /* typedef_e_ClassificationModel_adjustWei */

#ifndef typedef_myIncrLearn_mexStackData
#define typedef_myIncrLearn_mexStackData
typedef struct {
  union {
    b_removeUtil f0;
    f_incrementalClassificationLine f1;
  } u1;
  e_ClassificationModel_adjustWei f2;
} myIncrLearn_mexStackData;
#endif /* typedef_myIncrLearn_mexStackData */

/* End of code generation (myIncrLearn_mex_types.h) */
