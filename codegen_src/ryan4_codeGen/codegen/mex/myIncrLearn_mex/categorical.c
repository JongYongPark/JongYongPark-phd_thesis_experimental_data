/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * categorical.c
 *
 * Code generation for function 'categorical'
 *
 */

/* Include files */
#include "categorical.h"
#include "any.h"
#include "cellstr_unique.h"
#include "find.h"
#include "getCategoryNames.h"
#include "myIncrLearn_mex_data.h"
#include "myIncrLearn_mex_emxutil.h"
#include "myIncrLearn_mex_types.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo hd_emlrtRSI = {
    494,                    /* lineNo */
    "categorical/initData", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\matlab\\datatypes\\codegen\\categorical\\+"
    "matlab\\+internal\\+coder\\@categorical\\categorical.m" /* pathName */
};

static emlrtRSInfo id_emlrtRSI = {
    478,                    /* lineNo */
    "categorical/initData", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\matlab\\datatypes\\codegen\\categorical\\+"
    "matlab\\+internal\\+coder\\@categorical\\categorical.m" /* pathName */
};

static emlrtRSInfo jd_emlrtRSI = {
    455,                    /* lineNo */
    "categorical/initData", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\matlab\\datatypes\\codegen\\categorical\\+"
    "matlab\\+internal\\+coder\\@categorical\\categorical.m" /* pathName */
};

static emlrtRSInfo pe_emlrtRSI = {
    678,          /* lineNo */
    "removeUtil", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\matlab\\datatypes\\codegen\\categorical\\+"
    "matlab\\+internal\\+coder\\@categorical\\categorical.m" /* pathName */
};

static emlrtRSInfo qe_emlrtRSI = {
    679,          /* lineNo */
    "removeUtil", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\matlab\\datatypes\\codegen\\categorical\\+"
    "matlab\\+internal\\+coder\\@categorical\\categorical.m" /* pathName */
};

static emlrtBCInfo kf_emlrtBCI = {
    -1,                     /* iFirst */
    -1,                     /* iLast */
    475,                    /* lineNo */
    60,                     /* colNo */
    "",                     /* aName */
    "categorical/initData", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\matlab\\datatypes\\codegen\\categorical\\+"
    "matlab\\+internal\\+coder\\@categorical\\categorical.m", /* pName */
    0                                                         /* checkKind */
};

static emlrtECInfo d_emlrtECI = {
    -1,                     /* nDims */
    510,                    /* lineNo */
    13,                     /* colNo */
    "categorical/initData", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\matlab\\datatypes\\codegen\\categorical\\+"
    "matlab\\+internal\\+coder\\@categorical\\categorical.m" /* pName */
};

static emlrtBCInfo lf_emlrtBCI = {
    -1,                     /* iFirst */
    -1,                     /* iLast */
    475,                    /* lineNo */
    34,                     /* colNo */
    "",                     /* aName */
    "categorical/initData", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\matlab\\datatypes\\codegen\\categorical\\+"
    "matlab\\+internal\\+coder\\@categorical\\categorical.m", /* pName */
    0                                                         /* checkKind */
};

static emlrtECInfo e_emlrtECI = {
    -1,           /* nDims */
    680,          /* lineNo */
    31,           /* colNo */
    "removeUtil", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\matlab\\datatypes\\codegen\\categorical\\+"
    "matlab\\+internal\\+coder\\@categorical\\categorical.m" /* pName */
};

static emlrtBCInfo mf_emlrtBCI = {
    -1,           /* iFirst */
    -1,           /* iLast */
    686,          /* lineNo */
    24,           /* colNo */
    "",           /* aName */
    "removeUtil", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\matlab\\datatypes\\codegen\\categorical\\+"
    "matlab\\+internal\\+coder\\@categorical\\categorical.m", /* pName */
    0                                                         /* checkKind */
};

static emlrtBCInfo nf_emlrtBCI = {
    -1,           /* iFirst */
    -1,           /* iLast */
    686,          /* lineNo */
    17,           /* colNo */
    "",           /* aName */
    "removeUtil", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\matlab\\datatypes\\codegen\\categorical\\+"
    "matlab\\+internal\\+coder\\@categorical\\categorical.m", /* pName */
    0                                                         /* checkKind */
};

static emlrtBCInfo of_emlrtBCI = {
    -1,           /* iFirst */
    -1,           /* iLast */
    680,          /* lineNo */
    39,           /* colNo */
    "",           /* aName */
    "removeUtil", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\matlab\\datatypes\\codegen\\categorical\\+"
    "matlab\\+internal\\+coder\\@categorical\\categorical.m", /* pName */
    0                                                         /* checkKind */
};

static emlrtBCInfo pf_emlrtBCI = {
    -1,           /* iFirst */
    -1,           /* iLast */
    681,          /* lineNo */
    18,           /* colNo */
    "",           /* aName */
    "removeUtil", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\matlab\\datatypes\\codegen\\categorical\\+"
    "matlab\\+internal\\+coder\\@categorical\\categorical.m", /* pName */
    0                                                         /* checkKind */
};

static emlrtBCInfo qf_emlrtBCI = {
    -1,           /* iFirst */
    -1,           /* iLast */
    684,          /* lineNo */
    23,           /* colNo */
    "",           /* aName */
    "removeUtil", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\matlab\\datatypes\\codegen\\categorical\\+"
    "matlab\\+internal\\+coder\\@categorical\\categorical.m", /* pName */
    0                                                         /* checkKind */
};

static emlrtBCInfo rf_emlrtBCI = {
    -1,           /* iFirst */
    -1,           /* iLast */
    686,          /* lineNo */
    26,           /* colNo */
    "",           /* aName */
    "removeUtil", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\matlab\\datatypes\\codegen\\categorical\\+"
    "matlab\\+internal\\+coder\\@categorical\\categorical.m", /* pName */
    0                                                         /* checkKind */
};

static emlrtBCInfo sf_emlrtBCI = {
    -1,           /* iFirst */
    -1,           /* iLast */
    686,          /* lineNo */
    22,           /* colNo */
    "",           /* aName */
    "removeUtil", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\matlab\\datatypes\\codegen\\categorical\\+"
    "matlab\\+internal\\+coder\\@categorical\\categorical.m", /* pName */
    0                                                         /* checkKind */
};

static emlrtBCInfo tf_emlrtBCI = {
    -1,           /* iFirst */
    -1,           /* iLast */
    686,          /* lineNo */
    13,           /* colNo */
    "",           /* aName */
    "removeUtil", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\matlab\\datatypes\\codegen\\categorical\\+"
    "matlab\\+internal\\+coder\\@categorical\\categorical.m", /* pName */
    0                                                         /* checkKind */
};

static emlrtRTEInfo wc_emlrtRTEI = {
    510,           /* lineNo */
    13,            /* colNo */
    "categorical", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\matlab\\datatypes\\codegen\\categorical\\+"
    "matlab\\+internal\\+coder\\@categorical\\categorical.m" /* pName */
};

static emlrtRTEInfo xc_emlrtRTEI = {
    433,           /* lineNo */
    22,            /* colNo */
    "categorical", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\matlab\\datatypes\\codegen\\categorical\\+"
    "matlab\\+internal\\+coder\\@categorical\\categorical.m" /* pName */
};

static emlrtRTEInfo yc_emlrtRTEI = {
    692,           /* lineNo */
    5,             /* colNo */
    "categorical", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\matlab\\datatypes\\codegen\\categorical\\+"
    "matlab\\+internal\\+coder\\@categorical\\categorical.m" /* pName */
};

static emlrtRTEInfo ad_emlrtRTEI = {
    679,           /* lineNo */
    5,             /* colNo */
    "categorical", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\matlab\\datatypes\\codegen\\categorical\\+"
    "matlab\\+internal\\+coder\\@categorical\\categorical.m" /* pName */
};

static emlrtRTEInfo bd_emlrtRTEI = {
    680,           /* lineNo */
    39,            /* colNo */
    "categorical", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\matlab\\datatypes\\codegen\\categorical\\+"
    "matlab\\+internal\\+coder\\@categorical\\categorical.m" /* pName */
};

static emlrtRTEInfo cd_emlrtRTEI = {
    673,           /* lineNo */
    21,            /* colNo */
    "categorical", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\matlab\\datatypes\\codegen\\categorical\\+"
    "matlab\\+internal\\+coder\\@categorical\\categorical.m" /* pName */
};

static emlrtRTEInfo dd_emlrtRTEI = {
    684,           /* lineNo */
    23,            /* colNo */
    "categorical", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\matlab\\datatypes\\codegen\\categorical\\+"
    "matlab\\+internal\\+coder\\@categorical\\categorical.m" /* pName */
};

static emlrtRTEInfo ed_emlrtRTEI = {
    686,           /* lineNo */
    13,            /* colNo */
    "categorical", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\matlab\\datatypes\\codegen\\categorical\\+"
    "matlab\\+internal\\+coder\\@categorical\\categorical.m" /* pName */
};

/* Function Declarations */
static void removeUtil(myIncrLearn_mexStackData *SD, const emlrtStack *sp,
                       const emxArray_cell_wrap_1 *c, emxArray_real_T *ic,
                       const boolean_T t_data[], int32_T t_size,
                       emxArray_cell_wrap_1 *out);

/* Function Definitions */
static void removeUtil(myIncrLearn_mexStackData *SD, const emlrtStack *sp,
                       const emxArray_cell_wrap_1 *c, emxArray_real_T *ic,
                       const boolean_T t_data[], int32_T t_size,
                       emxArray_cell_wrap_1 *out)
{
  const cell_wrap_1 *c_data;
  cell_wrap_1 *out_data;
  emlrtStack b_st;
  emlrtStack st;
  emxArray_int32_T *ii;
  emxArray_int32_T *q;
  real_T *ic_data;
  int32_T convert_size;
  int32_T i;
  int32_T i2;
  int32_T *ii_data;
  int32_T *q_data;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  ic_data = ic->data;
  c_data = c->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  st.site = &pe_emlrtRSI;
  if (any(t_data, t_size)) {
    int32_T i1;
    int32_T loop_ub;
    int32_T tmp_size_idx_1;
    int16_T unnamed_idx_0;
    boolean_T b_t_data[24075];
    st.site = &qe_emlrtRSI;
    for (i = 0; i < t_size; i++) {
      b_t_data[i] = !t_data[i];
    }
    emxInit_int32_T(&st, &q, 1, &ad_emlrtRTEI);
    emxInit_int32_T(&st, &ii, 1, &ac_emlrtRTEI);
    b_st.site = &xb_emlrtRSI;
    b_eml_find(&b_st, b_t_data, t_size, ii);
    ii_data = ii->data;
    i = q->size[0];
    q->size[0] = ii->size[0];
    emxEnsureCapacity_int32_T(&st, q, i, &ad_emlrtRTEI);
    q_data = q->data;
    loop_ub = ii->size[0];
    for (i = 0; i < loop_ub; i++) {
      q_data[i] = ii_data[i];
    }
    convert_size = c->size[0];
    loop_ub = c->size[0];
    if (loop_ub - 1 >= 0) {
      memset(&SD->u1.f0.convert_data[0], 0, loop_ub * sizeof(int16_T));
    }
    i = ii->size[0];
    ii->size[0] = q->size[0];
    emxEnsureCapacity_int32_T(sp, ii, i, &bd_emlrtRTEI);
    ii_data = ii->data;
    loop_ub = q->size[0];
    for (i = 0; i < loop_ub; i++) {
      if ((q_data[i] < 1) || (q_data[i] > c->size[0])) {
        emlrtDynamicBoundsCheckR2012b(q_data[i], 1, c->size[0], &of_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      ii_data[i] = q_data[i];
    }
    if (q->size[0] < 1) {
      tmp_size_idx_1 = 0;
    } else {
      tmp_size_idx_1 = q->size[0];
      loop_ub = q->size[0] - 1;
      for (i = 0; i <= loop_ub; i++) {
        SD->u1.f0.tmp_data[i] = (int16_T)(i + 1);
      }
    }
    if (ii->size[0] != tmp_size_idx_1) {
      emlrtSubAssignSizeCheck1dR2017a(ii->size[0], tmp_size_idx_1, &e_emlrtECI,
                                      (emlrtCTX)sp);
    }
    loop_ub = ii->size[0];
    for (i = 0; i < loop_ub; i++) {
      SD->u1.f0.convert_data[ii_data[i] - 1] = SD->u1.f0.tmp_data[i];
    }
    emxFree_int32_T(sp, &ii);
    loop_ub = ic->size[0];
    for (i = 0; i < loop_ub; i++) {
      i1 = (int32_T)ic_data[i];
      if ((i1 < 1) || (i1 > convert_size)) {
        emlrtDynamicBoundsCheckR2012b(i1, 1, convert_size, &pf_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      ic_data[i] = SD->u1.f0.convert_data[i1 - 1];
    }
    unnamed_idx_0 = (int16_T)q->size[0];
    i = out->size[0];
    out->size[0] = q->size[0];
    emxEnsureCapacity_cell_wrap_12(sp, out, i, &cd_emlrtRTEI);
    out_data = out->data;
    for (i = 0; i < unnamed_idx_0; i++) {
      tmp_size_idx_1 = out->size[0] - 1;
      if (i > out->size[0] - 1) {
        emlrtDynamicBoundsCheckR2012b(i, 0, out->size[0] - 1, &qf_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      i1 = out_data[i].f1->size[0] * out_data[i].f1->size[1];
      out_data[i].f1->size[0] = 1;
      emxEnsureCapacity_char_T(sp, out_data[i].f1, i1, &cd_emlrtRTEI);
      if (i > tmp_size_idx_1) {
        emlrtDynamicBoundsCheckR2012b(i, 0, tmp_size_idx_1, &qf_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      out_data[i].f1->size[1] = 0;
    }
    i = q->size[0];
    i1 = out->size[0];
    out->size[0] = q->size[0];
    emxEnsureCapacity_cell_wrap_12(sp, out, i1, &dd_emlrtRTEI);
    out_data = out->data;
    for (convert_size = 0; convert_size < i; convert_size++) {
      if (convert_size + 1 > q->size[0]) {
        emlrtDynamicBoundsCheckR2012b(convert_size + 1, 1, q->size[0],
                                      &rf_emlrtBCI, (emlrtCTX)sp);
      }
      i1 = q_data[convert_size] - 1;
      if ((i1 < 0) || (i1 > c->size[0] - 1)) {
        emlrtDynamicBoundsCheckR2012b(i1, 0, c->size[0] - 1, &mf_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      if (convert_size + 1 > q->size[0]) {
        emlrtDynamicBoundsCheckR2012b(convert_size + 1, 1, q->size[0],
                                      &rf_emlrtBCI, (emlrtCTX)sp);
      }
      i1 = q_data[convert_size] - 1;
      if ((i1 < 0) || (i1 > c->size[0] - 1)) {
        emlrtDynamicBoundsCheckR2012b(i1, 0, c->size[0] - 1, &mf_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      loop_ub = c_data[q_data[convert_size] - 1].f1->size[1] - 1;
      if (convert_size > out->size[0] - 1) {
        emlrtDynamicBoundsCheckR2012b(convert_size, 0, out->size[0] - 1,
                                      &nf_emlrtBCI, (emlrtCTX)sp);
      }
      i1 = out_data[convert_size].f1->size[0] *
           out_data[convert_size].f1->size[1];
      out_data[convert_size].f1->size[0] = 1;
      emxEnsureCapacity_char_T(sp, out_data[convert_size].f1, i1,
                               &ed_emlrtRTEI);
      if (convert_size + 1 > q->size[0]) {
        emlrtDynamicBoundsCheckR2012b(convert_size + 1, 1, q->size[0],
                                      &rf_emlrtBCI, (emlrtCTX)sp);
      }
      i1 = q_data[convert_size] - 1;
      if ((i1 < 0) || (i1 > c->size[0] - 1)) {
        emlrtDynamicBoundsCheckR2012b(i1, 0, c->size[0] - 1, &mf_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      if (convert_size > out->size[0] - 1) {
        emlrtDynamicBoundsCheckR2012b(convert_size, 0, out->size[0] - 1,
                                      &nf_emlrtBCI, (emlrtCTX)sp);
      }
      i1 = out_data[convert_size].f1->size[0] *
           out_data[convert_size].f1->size[1];
      out_data[convert_size].f1->size[1] =
          c_data[q_data[convert_size] - 1].f1->size[1];
      emxEnsureCapacity_char_T(sp, out_data[convert_size].f1, i1,
                               &ed_emlrtRTEI);
      i1 = out->size[0];
      if (convert_size > out->size[0] - 1) {
        emlrtDynamicBoundsCheckR2012b(convert_size, 0, out->size[0] - 1,
                                      &nf_emlrtBCI, (emlrtCTX)sp);
      }
      for (i2 = 0; i2 <= loop_ub; i2++) {
        if (convert_size + 1 > q->size[0]) {
          emlrtDynamicBoundsCheckR2012b(convert_size + 1, 1, q->size[0],
                                        &sf_emlrtBCI, (emlrtCTX)sp);
        }
        tmp_size_idx_1 = q_data[convert_size] - 1;
        if ((tmp_size_idx_1 < 0) || (tmp_size_idx_1 > c->size[0] - 1)) {
          emlrtDynamicBoundsCheckR2012b(tmp_size_idx_1, 0, c->size[0] - 1,
                                        &sf_emlrtBCI, (emlrtCTX)sp);
        }
        if (convert_size > i1 - 1) {
          emlrtDynamicBoundsCheckR2012b(convert_size, 0, i1 - 1, &tf_emlrtBCI,
                                        (emlrtCTX)sp);
        }
        out_data[convert_size].f1->data[i2] =
            c_data[tmp_size_idx_1].f1->data[i2];
      }
    }
    emxFree_int32_T(sp, &q);
  } else {
    int32_T loop_ub;
    i = out->size[0];
    out->size[0] = c->size[0];
    emxEnsureCapacity_cell_wrap_12(sp, out, i, &yc_emlrtRTEI);
    out_data = out->data;
    loop_ub = c->size[0];
    for (i = 0; i < loop_ub; i++) {
      emxCopyStruct_cell_wrap_1(sp, &out_data[i], &c_data[i], &yc_emlrtRTEI);
    }
  }
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

void categorical_initData(myIncrLearn_mexStackData *SD, const emlrtStack *sp,
                          b_categorical *b,
                          const emxArray_cell_wrap_1 *inputData)
{
  cell_wrap_1 *tempValueSet_data;
  emlrtStack st;
  emxArray_cell_wrap_1 *tempValueSet;
  emxArray_cell_wrap_1 *valueSet;
  emxArray_real_T *a__17;
  emxArray_real_T *icats;
  real_T *icats_data;
  int32_T i;
  int32_T loop_ub;
  int32_T mask_size;
  boolean_T mask_data[24075];
  st.prev = sp;
  st.tls = sp->tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  emxInit_real_T(sp, &a__17, 1, &xc_emlrtRTEI);
  emxInit_cell_wrap_1(sp, &tempValueSet, &xc_emlrtRTEI);
  emxInit_real_T(sp, &icats, 1, &xc_emlrtRTEI);
  st.site = &jd_emlrtRSI;
  cellstr_unique(&st, inputData, tempValueSet, a__17, icats);
  tempValueSet_data = tempValueSet->data;
  mask_size = tempValueSet->size[0];
  loop_ub = tempValueSet->size[0];
  emxFree_real_T(sp, &a__17);
  if (loop_ub - 1 >= 0) {
    memset(&mask_data[0], 0, loop_ub * sizeof(boolean_T));
  }
  i = tempValueSet->size[0];
  for (loop_ub = 0; loop_ub < i; loop_ub++) {
    if (loop_ub > tempValueSet->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(loop_ub, 0, tempValueSet->size[0] - 1,
                                    &kf_emlrtBCI, (emlrtCTX)sp);
    }
    if (loop_ub + 1 > mask_size) {
      emlrtDynamicBoundsCheckR2012b(loop_ub + 1, 1, mask_size, &lf_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    mask_data[loop_ub] = (tempValueSet_data[loop_ub].f1->size[1] == 0);
  }
  emxInit_cell_wrap_1(sp, &valueSet, &xc_emlrtRTEI);
  st.site = &id_emlrtRSI;
  removeUtil(SD, &st, tempValueSet, icats, mask_data, mask_size, valueSet);
  icats_data = icats->data;
  st.site = &hd_emlrtRSI;
  categorical_getCategoryNames(&st, valueSet, b->categoryNames);
  i = b->codes->size[0];
  b->codes->size[0] = icats->size[0];
  emxEnsureCapacity_uint32_T(sp, b->codes, i, &wc_emlrtRTEI);
  loop_ub = icats->size[0];
  emxFree_cell_wrap_1(sp, &valueSet);
  emxFree_cell_wrap_1(sp, &tempValueSet);
  for (i = 0; i < loop_ub; i++) {
    real_T d;
    uint32_T u;
    d = muDoubleScalarRound(icats_data[i]);
    if (d < 4.294967296E+9) {
      if (d >= 0.0) {
        u = (uint32_T)d;
      } else {
        u = 0U;
      }
    } else if (d >= 4.294967296E+9) {
      u = MAX_uint32_T;
    } else {
      u = 0U;
    }
    b->codes->data[i] = u;
  }
  emxFree_real_T(sp, &icats);
  i = b->codes->size[0];
  if (inputData->size[0] != i) {
    emlrtSubAssignSizeCheck1dR2017a(inputData->size[0], i, &d_emlrtECI,
                                    (emlrtCTX)sp);
  }
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

/* End of code generation (categorical.c) */
