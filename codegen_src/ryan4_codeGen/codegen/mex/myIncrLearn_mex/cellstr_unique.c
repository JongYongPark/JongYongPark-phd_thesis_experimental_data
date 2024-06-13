/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * cellstr_unique.c
 *
 * Code generation for function 'cellstr_unique'
 *
 */

/* Include files */
#include "cellstr_unique.h"
#include "find.h"
#include "introsort.h"
#include "myIncrLearn_mex_data.h"
#include "myIncrLearn_mex_emxutil.h"
#include "myIncrLearn_mex_types.h"
#include "rt_nonfinite.h"
#include "strcmp.h"
#include "mwmathutil.h"
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo kd_emlrtRSI = {
    28,               /* lineNo */
    "cellstr_unique", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\matlab\\datatypes\\shared\\codegen\\+"
    "matlab\\+internal\\+coder\\+datatypes\\cellstr_unique.m" /* pathName */
};

static emlrtRSInfo ld_emlrtRSI = {
    44,               /* lineNo */
    "cellstr_unique", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\matlab\\datatypes\\shared\\codegen\\+"
    "matlab\\+internal\\+coder\\+datatypes\\cellstr_unique.m" /* pathName */
};

static emlrtRSInfo he_emlrtRSI = {
    15,    /* lineNo */
    "sum", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\eml\\lib\\matlab\\datafun\\sum.m" /* pathName
                                                                        */
};

static emlrtRSInfo je_emlrtRSI = {
    12,       /* lineNo */
    "cumsum", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\eml\\lib\\matlab\\datafun\\cumsum.m" /* pathName
                                                                           */
};

static emlrtRSInfo ke_emlrtRSI = {
    16,      /* lineNo */
    "cumop", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\cumop."
    "m" /* pathName */
};

static emlrtECInfo b_emlrtECI = {
    -1,               /* nDims */
    56,               /* lineNo */
    5,                /* colNo */
    "cellstr_unique", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\matlab\\datatypes\\shared\\codegen\\+"
    "matlab\\+internal\\+coder\\+datatypes\\cellstr_unique.m" /* pName */
};

static emlrtDCInfo b_emlrtDCI = {
    28,               /* lineNo */
    29,               /* colNo */
    "cellstr_unique", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\matlab\\datatypes\\shared\\codegen\\+"
    "matlab\\+internal\\+coder\\+datatypes\\cellstr_unique.m", /* pName */
    4                                                          /* checkKind */
};

static emlrtBCInfo xb_emlrtBCI = {
    -1,             /* iFirst */
    -1,             /* iLast */
    27,             /* lineNo */
    19,             /* colNo */
    "",             /* aName */
    "cellstr_sort", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\matlab\\datatypes\\shared\\codegen\\+"
    "matlab\\+internal\\+coder\\+datatypes\\cellstr_sort.m", /* pName */
    0                                                        /* checkKind */
};

static emlrtBCInfo yb_emlrtBCI = {
    -1,             /* iFirst */
    -1,             /* iLast */
    27,             /* lineNo */
    12,             /* colNo */
    "",             /* aName */
    "cellstr_sort", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\matlab\\datatypes\\shared\\codegen\\+"
    "matlab\\+internal\\+coder\\+datatypes\\cellstr_sort.m", /* pName */
    0                                                        /* checkKind */
};

static emlrtBCInfo ac_emlrtBCI = {
    -1,               /* iFirst */
    -1,               /* iLast */
    59,               /* lineNo */
    18,               /* colNo */
    "",               /* aName */
    "cellstr_unique", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\matlab\\datatypes\\shared\\codegen\\+"
    "matlab\\+internal\\+coder\\+datatypes\\cellstr_unique.m", /* pName */
    0                                                          /* checkKind */
};

static emlrtBCInfo bc_emlrtBCI = {
    -1,             /* iFirst */
    -1,             /* iLast */
    27,             /* lineNo */
    23,             /* colNo */
    "",             /* aName */
    "cellstr_sort", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\matlab\\datatypes\\shared\\codegen\\+"
    "matlab\\+internal\\+coder\\+datatypes\\cellstr_sort.m", /* pName */
    0                                                        /* checkKind */
};

static emlrtBCInfo cc_emlrtBCI = {
    -1,             /* iFirst */
    -1,             /* iLast */
    11,             /* lineNo */
    27,             /* colNo */
    "",             /* aName */
    "cellstr_diff", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\matlab\\datatypes\\shared\\codegen\\+"
    "matlab\\+internal\\+coder\\+datatypes\\cellstr_diff.m", /* pName */
    0                                                        /* checkKind */
};

static emlrtBCInfo dc_emlrtBCI = {
    -1,             /* iFirst */
    -1,             /* iLast */
    11,             /* lineNo */
    32,             /* colNo */
    "",             /* aName */
    "cellstr_diff", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\matlab\\datatypes\\shared\\codegen\\+"
    "matlab\\+internal\\+coder\\+datatypes\\cellstr_diff.m", /* pName */
    0                                                        /* checkKind */
};

static emlrtBCInfo ec_emlrtBCI = {
    -1,             /* iFirst */
    -1,             /* iLast */
    11,             /* lineNo */
    11,             /* colNo */
    "",             /* aName */
    "cellstr_diff", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\matlab\\datatypes\\shared\\codegen\\+"
    "matlab\\+internal\\+coder\\+datatypes\\cellstr_diff.m", /* pName */
    0                                                        /* checkKind */
};

static emlrtBCInfo fc_emlrtBCI = {
    -1,             /* iFirst */
    -1,             /* iLast */
    27,             /* lineNo */
    17,             /* colNo */
    "",             /* aName */
    "cellstr_sort", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\matlab\\datatypes\\shared\\codegen\\+"
    "matlab\\+internal\\+coder\\+datatypes\\cellstr_sort.m", /* pName */
    0                                                        /* checkKind */
};

static emlrtBCInfo gc_emlrtBCI = {
    -1,             /* iFirst */
    -1,             /* iLast */
    27,             /* lineNo */
    5,              /* colNo */
    "",             /* aName */
    "cellstr_sort", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\matlab\\datatypes\\shared\\codegen\\+"
    "matlab\\+internal\\+coder\\+datatypes\\cellstr_sort.m", /* pName */
    0                                                        /* checkKind */
};

static emlrtDCInfo c_emlrtDCI = {
    39,               /* lineNo */
    30,               /* colNo */
    "cellstr_unique", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\matlab\\datatypes\\shared\\codegen\\+"
    "matlab\\+internal\\+coder\\+datatypes\\cellstr_unique.m", /* pName */
    1                                                          /* checkKind */
};

static emlrtBCInfo hc_emlrtBCI = {
    -1,               /* iFirst */
    -1,               /* iLast */
    39,               /* lineNo */
    30,               /* colNo */
    "",               /* aName */
    "cellstr_unique", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\matlab\\datatypes\\shared\\codegen\\+"
    "matlab\\+internal\\+coder\\+datatypes\\cellstr_unique.m", /* pName */
    0                                                          /* checkKind */
};

static emlrtBCInfo ic_emlrtBCI = {
    -1,               /* iFirst */
    -1,               /* iLast */
    37,               /* lineNo */
    30,               /* colNo */
    "",               /* aName */
    "cellstr_unique", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\matlab\\datatypes\\shared\\codegen\\+"
    "matlab\\+internal\\+coder\\+datatypes\\cellstr_unique.m", /* pName */
    0                                                          /* checkKind */
};

static emlrtBCInfo jc_emlrtBCI = {
    -1,               /* iFirst */
    -1,               /* iLast */
    56,               /* lineNo */
    5,                /* colNo */
    "",               /* aName */
    "cellstr_unique", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\matlab\\datatypes\\shared\\codegen\\+"
    "matlab\\+internal\\+coder\\+datatypes\\cellstr_unique.m", /* pName */
    0                                                          /* checkKind */
};

static emlrtRTEInfo rb_emlrtRTEI =
    {
        172,     /* lineNo */
        20,      /* colNo */
        "colon", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2022a\\toolbox\\eml\\lib\\matlab\\ops\\colon.m" /* pName
                                                                          */
};

static emlrtRTEInfo sb_emlrtRTEI = {
    23,             /* lineNo */
    1,              /* colNo */
    "cellstr_sort", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\matlab\\datatypes\\shared\\codegen\\+"
    "matlab\\+internal\\+coder\\+datatypes\\cellstr_sort.m" /* pName */
};

static emlrtRTEInfo tb_emlrtRTEI = {
    25,             /* lineNo */
    30,             /* colNo */
    "cellstr_sort", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\matlab\\datatypes\\shared\\codegen\\+"
    "matlab\\+internal\\+coder\\+datatypes\\cellstr_sort.m" /* pName */
};

static emlrtRTEInfo ub_emlrtRTEI = {
    27,             /* lineNo */
    5,              /* colNo */
    "cellstr_sort", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\matlab\\datatypes\\shared\\codegen\\+"
    "matlab\\+internal\\+coder\\+datatypes\\cellstr_sort.m" /* pName */
};

static emlrtRTEInfo vb_emlrtRTEI = {
    32,               /* lineNo */
    10,               /* colNo */
    "cellstr_unique", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\matlab\\datatypes\\shared\\codegen\\+"
    "matlab\\+internal\\+coder\\+datatypes\\cellstr_unique.m" /* pName */
};

static emlrtRTEInfo wb_emlrtRTEI = {
    44,               /* lineNo */
    5,                /* colNo */
    "cellstr_unique", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\matlab\\datatypes\\shared\\codegen\\+"
    "matlab\\+internal\\+coder\\+datatypes\\cellstr_unique.m" /* pName */
};

static emlrtRTEInfo xb_emlrtRTEI = {
    56,               /* lineNo */
    5,                /* colNo */
    "cellstr_unique", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\matlab\\datatypes\\shared\\codegen\\+"
    "matlab\\+internal\\+coder\\+datatypes\\cellstr_unique.m" /* pName */
};

static emlrtRTEInfo yb_emlrtRTEI = {
    1,                /* lineNo */
    24,               /* colNo */
    "cellstr_unique", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\matlab\\datatypes\\shared\\codegen\\+"
    "matlab\\+internal\\+coder\\+datatypes\\cellstr_unique.m" /* pName */
};

static emlrtRTEInfo bc_emlrtRTEI = {
    39,               /* lineNo */
    30,               /* colNo */
    "cellstr_unique", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\matlab\\datatypes\\shared\\codegen\\+"
    "matlab\\+internal\\+coder\\+datatypes\\cellstr_unique.m" /* pName */
};

static emlrtRTEInfo cc_emlrtRTEI = {
    22,             /* lineNo */
    8,              /* colNo */
    "cellstr_sort", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\matlab\\datatypes\\shared\\codegen\\+"
    "matlab\\+internal\\+coder\\+datatypes\\cellstr_sort.m" /* pName */
};

/* Function Definitions */
void cellstr_unique(const emlrtStack *sp, const emxArray_cell_wrap_1 *a,
                    emxArray_cell_wrap_1 *u, emxArray_real_T *ia,
                    emxArray_real_T *ic)
{
  const cell_wrap_1 *a_data;
  cell_wrap_1 *u_data;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack st;
  emxArray_cell_wrap_1 *c;
  emxArray_int32_T *idx;
  emxArray_int32_T *ii;
  emxArray_int32_T *y;
  emxArray_real_T *b_ic;
  emxArray_real_T *b_y;
  real_T *b_ic_data;
  real_T *ia_data;
  real_T *ic_data;
  int32_T b_i;
  int32_T i;
  int32_T i1;
  int32_T k;
  int32_T *idx_data;
  int32_T *ii_data;
  boolean_T b_d_data[24075];
  boolean_T d_data[24074];
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  a_data = a->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  if (a->size[0] == 0) {
    u->size[0] = 0;
    ia->size[0] = 0;
    ic->size[0] = 0;
  } else {
    int32_T b_d_size;
    int32_T d_size;
    int32_T n;
    int32_T yk;
    emxInit_int32_T(sp, &y, 2, &cc_emlrtRTEI);
    st.site = &sb_emlrtRSI;
    n = a->size[0];
    i = y->size[0] * y->size[1];
    y->size[0] = 1;
    y->size[1] = a->size[0];
    emxEnsureCapacity_int32_T(&st, y, i, &rb_emlrtRTEI);
    ii_data = y->data;
    ii_data[0] = 1;
    yk = 1;
    for (k = 2; k <= n; k++) {
      yk++;
      ii_data[k - 1] = yk;
    }
    emxInit_int32_T(&st, &idx, 1, &yb_emlrtRTEI);
    i = idx->size[0];
    idx->size[0] = y->size[1];
    emxEnsureCapacity_int32_T(&st, idx, i, &sb_emlrtRTEI);
    idx_data = idx->data;
    n = y->size[1];
    for (i = 0; i < n; i++) {
      idx_data[i] = ii_data[i];
    }
    emxFree_int32_T(&st, &y);
    emxInit_cell_wrap_1(&st, &c, &yb_emlrtRTEI);
    b_st.site = &db_emlrtRSI;
    b_introsort(&b_st, idx, a->size[0], a);
    idx_data = idx->data;
    i = c->size[0];
    c->size[0] = a->size[0];
    emxEnsureCapacity_cell_wrap_12(&st, c, i, &tb_emlrtRTEI);
    u_data = c->data;
    i = a->size[0];
    for (b_i = 0; b_i < i; b_i++) {
      if (b_i + 1 > idx->size[0]) {
        emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, idx->size[0], &bc_emlrtBCI,
                                      &st);
      }
      i1 = idx_data[b_i] - 1;
      if ((i1 < 0) || (i1 > a->size[0] - 1)) {
        emlrtDynamicBoundsCheckR2012b(i1, 0, a->size[0] - 1, &xb_emlrtBCI, &st);
      }
      if (b_i + 1 > idx->size[0]) {
        emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, idx->size[0], &bc_emlrtBCI,
                                      &st);
      }
      i1 = idx_data[b_i] - 1;
      if ((i1 < 0) || (i1 > a->size[0] - 1)) {
        emlrtDynamicBoundsCheckR2012b(i1, 0, a->size[0] - 1, &xb_emlrtBCI, &st);
      }
      n = a_data[idx_data[b_i] - 1].f1->size[1] - 1;
      if (b_i > c->size[0] - 1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, c->size[0] - 1, &yb_emlrtBCI,
                                      &st);
      }
      i1 = u_data[b_i].f1->size[0] * u_data[b_i].f1->size[1];
      u_data[b_i].f1->size[0] = 1;
      emxEnsureCapacity_char_T(&st, u_data[b_i].f1, i1, &ub_emlrtRTEI);
      if (b_i + 1 > idx->size[0]) {
        emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, idx->size[0], &bc_emlrtBCI,
                                      &st);
      }
      i1 = idx_data[b_i] - 1;
      if ((i1 < 0) || (i1 > a->size[0] - 1)) {
        emlrtDynamicBoundsCheckR2012b(i1, 0, a->size[0] - 1, &xb_emlrtBCI, &st);
      }
      if (b_i > c->size[0] - 1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, c->size[0] - 1, &yb_emlrtBCI,
                                      &st);
      }
      i1 = u_data[b_i].f1->size[0] * u_data[b_i].f1->size[1];
      u_data[b_i].f1->size[1] = a_data[idx_data[b_i] - 1].f1->size[1];
      emxEnsureCapacity_char_T(&st, u_data[b_i].f1, i1, &ub_emlrtRTEI);
      i1 = c->size[0];
      if (b_i > c->size[0] - 1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, c->size[0] - 1, &yb_emlrtBCI,
                                      &st);
      }
      for (k = 0; k <= n; k++) {
        if (b_i + 1 > idx->size[0]) {
          emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, idx->size[0], &fc_emlrtBCI,
                                        &st);
        }
        yk = idx_data[b_i] - 1;
        if ((yk < 0) || (yk > a->size[0] - 1)) {
          emlrtDynamicBoundsCheckR2012b(yk, 0, a->size[0] - 1, &fc_emlrtBCI,
                                        &st);
        }
        if (b_i > i1 - 1) {
          emlrtDynamicBoundsCheckR2012b(b_i, 0, i1 - 1, &gc_emlrtBCI, &st);
        }
        u_data[b_i].f1->data[k] = a_data[yk].f1->data[k];
      }
    }
    st.site = &tb_emlrtRSI;
    d_size = c->size[0] - 1;
    n = c->size[0];
    if (n - 2 >= 0) {
      memset(&d_data[0], 0, (n - 1) * sizeof(boolean_T));
    }
    i = c->size[0];
    for (b_i = 0; b_i <= i - 2; b_i++) {
      if (b_i > c->size[0] - 1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, c->size[0] - 1, &cc_emlrtBCI,
                                      &st);
      }
      if (b_i + 1 > c->size[0] - 1) {
        emlrtDynamicBoundsCheckR2012b(b_i + 1, 0, c->size[0] - 1, &dc_emlrtBCI,
                                      &st);
      }
      if (b_i + 1 > d_size) {
        emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, d_size, &ec_emlrtBCI, &st);
      }
      b_st.site = &jb_emlrtRSI;
      d_data[b_i] = !b_strcmp(&b_st, u_data[b_i].f1, u_data[b_i + 1].f1);
    }
    emxFree_cell_wrap_1(&st, &c);
    b_d_size = d_size + 1;
    b_d_data[0] = true;
    if (d_size - 1 >= 0) {
      memcpy(&b_d_data[1], &d_data[0], d_size * sizeof(boolean_T));
    }
    st.site = &kd_emlrtRSI;
    b_st.site = &he_emlrtRSI;
    yk = b_d_data[0];
    for (k = 2; k <= b_d_size; k++) {
      yk += b_d_data[k - 1];
    }
    i = (int32_T)muDoubleScalarMin(yk, a->size[0]);
    if (i < 0) {
      emlrtNonNegativeCheckR2012b(i, &b_emlrtDCI, (emlrtCTX)sp);
    }
    emxInit_int32_T(sp, &ii, 1, &ac_emlrtRTEI);
    i = u->size[0];
    u->size[0] = (int32_T)muDoubleScalarMin(yk, a->size[0]);
    emxEnsureCapacity_cell_wrap_12(sp, u, i, &ib_emlrtRTEI);
    u_data = u->data;
    st.site = &ub_emlrtRSI;
    b_st.site = &xb_emlrtRSI;
    b_eml_find(&b_st, b_d_data, d_size + 1, ii);
    ii_data = ii->data;
    i = ia->size[0];
    ia->size[0] = ii->size[0];
    emxEnsureCapacity_real_T(sp, ia, i, &vb_emlrtRTEI);
    ia_data = ia->data;
    i = ii->size[0];
    emxInit_real_T(sp, &b_y, 2, &bc_emlrtRTEI);
    ic_data = b_y->data;
    for (b_i = 0; b_i < i; b_i++) {
      if (b_i + 1 != ii->size[0]) {
        real_T d;
        st.site = &vb_emlrtRSI;
        if (b_i + 1 > ii->size[0]) {
          emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, ii->size[0], &n_emlrtBCI,
                                        &st);
        }
        if (b_i + 2 > ii->size[0]) {
          emlrtDynamicBoundsCheckR2012b(b_i + 2, 1, ii->size[0], &o_emlrtBCI,
                                        &st);
        }
        b_st.site = &cc_emlrtRSI;
        d = (real_T)ii_data[b_i + 1] - 1.0;
        i1 = ii_data[b_i];
        if (d < i1) {
          b_y->size[0] = 1;
          b_y->size[1] = 0;
        } else {
          k = b_y->size[0] * b_y->size[1];
          b_y->size[0] = 1;
          n = (int32_T)d - i1;
          b_y->size[1] = n + 1;
          emxEnsureCapacity_real_T(&b_st, b_y, k, &bb_emlrtRTEI);
          ic_data = b_y->data;
          for (k = 0; k <= n; k++) {
            ic_data[k] = (real_T)i1 + (real_T)k;
          }
        }
        st.site = &vb_emlrtRSI;
        n = b_y->size[1];
        for (i1 = 0; i1 < n; i1++) {
          k = (int32_T)ic_data[i1];
          if (ic_data[i1] != k) {
            emlrtIntegerCheckR2012b(ic_data[i1], &emlrtDCI, &st);
          }
          if ((k < 1) || (k > idx->size[0])) {
            emlrtDynamicBoundsCheckR2012b(k, 1, idx->size[0], &ic_emlrtBCI,
                                          &st);
          }
        }
        b_st.site = &dc_emlrtRSI;
        c_st.site = &ec_emlrtRSI;
        d_st.site = &fc_emlrtRSI;
        if (b_y->size[1] < 1) {
          emlrtErrorWithMessageIdR2018a(
              &d_st, &e_emlrtRTEI, "Coder:toolbox:eml_min_or_max_varDimZero",
              "Coder:toolbox:eml_min_or_max_varDimZero", 0);
        }
        yk = b_y->size[1];
        n = idx_data[(int32_T)ic_data[0] - 1];
        for (k = 2; k <= yk; k++) {
          i1 = idx_data[(int32_T)ic_data[k - 1] - 1];
          if (n > i1) {
            n = i1;
          }
        }
        if (b_i + 1 > ia->size[0]) {
          emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, ia->size[0], &v_emlrtBCI,
                                        (emlrtCTX)sp);
        }
        ia_data[b_i] = n;
      } else {
        st.site = &wb_emlrtRSI;
        if (b_i + 1 > ii->size[0]) {
          emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, ii->size[0], &p_emlrtBCI,
                                        &st);
        }
        b_st.site = &cc_emlrtRSI;
        if (idx->size[0] < ii_data[b_i]) {
          b_y->size[0] = 1;
          b_y->size[1] = 0;
        } else {
          i1 = b_y->size[0] * b_y->size[1];
          b_y->size[0] = 1;
          b_y->size[1] = (idx->size[0] - ii_data[b_i]) + 1;
          emxEnsureCapacity_real_T(&b_st, b_y, i1, &bb_emlrtRTEI);
          ic_data = b_y->data;
          n = idx->size[0] - ii_data[b_i];
          for (i1 = 0; i1 <= n; i1++) {
            ic_data[i1] = ii_data[b_i] + i1;
          }
        }
        st.site = &wb_emlrtRSI;
        n = b_y->size[1];
        for (i1 = 0; i1 < n; i1++) {
          if (ic_data[i1] != ic_data[i1]) {
            emlrtIntegerCheckR2012b(ic_data[i1], &c_emlrtDCI, &st);
          }
          k = (int32_T)ic_data[i1];
          if ((k < 1) || (k > idx->size[0])) {
            emlrtDynamicBoundsCheckR2012b(k, 1, idx->size[0], &hc_emlrtBCI,
                                          &st);
          }
        }
        b_st.site = &dc_emlrtRSI;
        c_st.site = &ec_emlrtRSI;
        d_st.site = &fc_emlrtRSI;
        if (b_y->size[1] < 1) {
          emlrtErrorWithMessageIdR2018a(
              &d_st, &e_emlrtRTEI, "Coder:toolbox:eml_min_or_max_varDimZero",
              "Coder:toolbox:eml_min_or_max_varDimZero", 0);
        }
        yk = b_y->size[1];
        n = idx_data[(int32_T)ic_data[0] - 1];
        for (k = 2; k <= yk; k++) {
          i1 = idx_data[(int32_T)ic_data[k - 1] - 1];
          if (n > i1) {
            n = i1;
          }
        }
        if (b_i + 1 > ia->size[0]) {
          emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, ia->size[0], &ab_emlrtBCI,
                                        (emlrtCTX)sp);
        }
        ia_data[b_i] = n;
      }
    }
    emxFree_real_T(sp, &b_y);
    st.site = &ld_emlrtRSI;
    i = ic->size[0];
    ic->size[0] = d_size + 1;
    emxEnsureCapacity_real_T(&st, ic, i, &wb_emlrtRTEI);
    ic_data = ic->data;
    for (i = 0; i < b_d_size; i++) {
      ic_data[i] = b_d_data[i];
    }
    b_st.site = &je_emlrtRSI;
    yk = 2;
    if (ic->size[0] != 1) {
      yk = 1;
    }
    c_st.site = &ke_emlrtRSI;
    if ((yk == 1) && (ic->size[0] != 1)) {
      i = ic->size[0];
      for (k = 0; k <= i - 2; k++) {
        ic_data[k + 1] += ic_data[k];
      }
    }
    if (idx->size[0] != ic->size[0]) {
      emlrtSubAssignSizeCheck1dR2017a(idx->size[0], ic->size[0], &b_emlrtECI,
                                      (emlrtCTX)sp);
    }
    emxInit_real_T(sp, &b_ic, 1, &xb_emlrtRTEI);
    yk = ic->size[0];
    i = b_ic->size[0];
    b_ic->size[0] = ic->size[0];
    emxEnsureCapacity_real_T(sp, b_ic, i, &xb_emlrtRTEI);
    b_ic_data = b_ic->data;
    n = ic->size[0];
    for (i = 0; i < n; i++) {
      b_ic_data[i] = ic_data[i];
    }
    n = b_ic->size[0];
    for (i = 0; i < n; i++) {
      if ((idx_data[i] < 1) || (idx_data[i] > yk)) {
        emlrtDynamicBoundsCheckR2012b(idx_data[i], 1, yk, &jc_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      ic_data[idx_data[i] - 1] = b_ic_data[i];
    }
    emxFree_real_T(sp, &b_ic);
    emxFree_int32_T(sp, &idx);
    i = ii->size[0];
    emxFree_int32_T(sp, &ii);
    for (b_i = 0; b_i < i; b_i++) {
      if (b_i + 1 > ia->size[0]) {
        emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, ia->size[0], &t_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      i1 = (int32_T)ia_data[b_i] - 1;
      if ((i1 < 0) || (i1 > a->size[0] - 1)) {
        emlrtDynamicBoundsCheckR2012b(i1, 0, a->size[0] - 1, &ac_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      if (b_i + 1 > ia->size[0]) {
        emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, ia->size[0], &t_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      i1 = (int32_T)ia_data[b_i] - 1;
      if ((i1 < 0) || (i1 > a->size[0] - 1)) {
        emlrtDynamicBoundsCheckR2012b(i1, 0, a->size[0] - 1, &ac_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      n = a_data[(int32_T)ia_data[b_i] - 1].f1->size[1] - 1;
      if (b_i > u->size[0] - 1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, u->size[0] - 1, &s_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      i1 = u_data[b_i].f1->size[0] * u_data[b_i].f1->size[1];
      u_data[b_i].f1->size[0] = 1;
      emxEnsureCapacity_char_T(sp, u_data[b_i].f1, i1, &kb_emlrtRTEI);
      if (b_i + 1 > ia->size[0]) {
        emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, ia->size[0], &t_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      i1 = (int32_T)ia_data[b_i] - 1;
      if ((i1 < 0) || (i1 > a->size[0] - 1)) {
        emlrtDynamicBoundsCheckR2012b(i1, 0, a->size[0] - 1, &ac_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      if (b_i > u->size[0] - 1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, u->size[0] - 1, &s_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      i1 = u_data[b_i].f1->size[0] * u_data[b_i].f1->size[1];
      u_data[b_i].f1->size[1] = a_data[(int32_T)ia_data[b_i] - 1].f1->size[1];
      emxEnsureCapacity_char_T(sp, u_data[b_i].f1, i1, &kb_emlrtRTEI);
      i1 = u->size[0];
      if (b_i > u->size[0] - 1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, u->size[0] - 1, &s_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      if (b_i > u->size[0] - 1) {
        emlrtDynamicBoundsCheckR2012b(b_i, 0, u->size[0] - 1, &s_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      for (k = 0; k <= n; k++) {
        if (b_i + 1 > ia->size[0]) {
          emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, ia->size[0], &x_emlrtBCI,
                                        (emlrtCTX)sp);
        }
        yk = (int32_T)ia_data[b_i] - 1;
        if ((yk < 0) || (yk > a->size[0] - 1)) {
          emlrtDynamicBoundsCheckR2012b(yk, 0, a->size[0] - 1, &x_emlrtBCI,
                                        (emlrtCTX)sp);
        }
        if (b_i > i1 - 1) {
          emlrtDynamicBoundsCheckR2012b(b_i, 0, i1 - 1, &y_emlrtBCI,
                                        (emlrtCTX)sp);
        }
        u_data[b_i].f1->data[k] = a_data[yk].f1->data[k];
      }
    }
  }
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

/* End of code generation (cellstr_unique.c) */
