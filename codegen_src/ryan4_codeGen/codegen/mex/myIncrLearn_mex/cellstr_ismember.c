/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * cellstr_ismember.c
 *
 * Code generation for function 'cellstr_ismember'
 *
 */

/* Include files */
#include "cellstr_ismember.h"
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
static emlrtRSInfo ob_emlrtRSI = {
    167,                /* lineNo */
    "cellstr_ismember", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\matlab\\datatypes\\shared\\codegen\\+"
    "matlab\\+internal\\+coder\\+datatypes\\cellstr_ismember.m" /* pathName */
};

static emlrtRSInfo pb_emlrtRSI = {
    159,                /* lineNo */
    "cellstr_ismember", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\matlab\\datatypes\\shared\\codegen\\+"
    "matlab\\+internal\\+coder\\+datatypes\\cellstr_ismember.m" /* pathName */
};

static emlrtRSInfo qb_emlrtRSI = {
    87,                 /* lineNo */
    "cellstr_ismember", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\matlab\\datatypes\\shared\\codegen\\+"
    "matlab\\+internal\\+coder\\+datatypes\\cellstr_ismember.m" /* pathName */
};

static emlrtRSInfo rb_emlrtRSI = {
    63,                 /* lineNo */
    "cellstr_ismember", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\matlab\\datatypes\\shared\\codegen\\+"
    "matlab\\+internal\\+coder\\+datatypes\\cellstr_ismember.m" /* pathName */
};

static emlrtBCInfo j_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    164,                /* lineNo */
    71,                 /* colNo */
    "",                 /* aName */
    "cellstr_ismember", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\matlab\\datatypes\\shared\\codegen\\+"
    "matlab\\+internal\\+coder\\+datatypes\\cellstr_ismember.m", /* pName */
    0                                                            /* checkKind */
};

static emlrtBCInfo k_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    164,                /* lineNo */
    55,                 /* colNo */
    "",                 /* aName */
    "cellstr_ismember", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\matlab\\datatypes\\shared\\codegen\\+"
    "matlab\\+internal\\+coder\\+datatypes\\cellstr_ismember.m", /* pName */
    0                                                            /* checkKind */
};

static emlrtBCInfo l_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    157,                /* lineNo */
    46,                 /* colNo */
    "",                 /* aName */
    "cellstr_ismember", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\matlab\\datatypes\\shared\\codegen\\+"
    "matlab\\+internal\\+coder\\+datatypes\\cellstr_ismember.m", /* pName */
    0                                                            /* checkKind */
};

static emlrtBCInfo m_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    157,                /* lineNo */
    30,                 /* colNo */
    "",                 /* aName */
    "cellstr_ismember", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\matlab\\datatypes\\shared\\codegen\\+"
    "matlab\\+internal\\+coder\\+datatypes\\cellstr_ismember.m", /* pName */
    0                                                            /* checkKind */
};

static emlrtBCInfo q_emlrtBCI = {
    0,              /* iFirst */
    1,              /* iLast */
    27,             /* lineNo */
    19,             /* colNo */
    "",             /* aName */
    "cellstr_sort", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\matlab\\datatypes\\shared\\codegen\\+"
    "matlab\\+internal\\+coder\\+datatypes\\cellstr_sort.m", /* pName */
    0                                                        /* checkKind */
};

static emlrtBCInfo r_emlrtBCI = {
    0,                /* iFirst */
    1,                /* iLast */
    59,               /* lineNo */
    18,               /* colNo */
    "",               /* aName */
    "cellstr_unique", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\matlab\\datatypes\\shared\\codegen\\+"
    "matlab\\+internal\\+coder\\+datatypes\\cellstr_unique.m", /* pName */
    0                                                          /* checkKind */
};

static emlrtBCInfo u_emlrtBCI = {
    1,                /* iFirst */
    2,                /* iLast */
    39,               /* lineNo */
    30,               /* colNo */
    "",               /* aName */
    "cellstr_unique", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\matlab\\datatypes\\shared\\codegen\\+"
    "matlab\\+internal\\+coder\\+datatypes\\cellstr_unique.m", /* pName */
    0                                                          /* checkKind */
};

static emlrtBCInfo w_emlrtBCI = {
    0,                /* iFirst */
    1,                /* iLast */
    59,               /* lineNo */
    16,               /* colNo */
    "",               /* aName */
    "cellstr_unique", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\matlab\\datatypes\\shared\\codegen\\+"
    "matlab\\+internal\\+coder\\+datatypes\\cellstr_unique.m", /* pName */
    0                                                          /* checkKind */
};

static emlrtBCInfo bb_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    159,                /* lineNo */
    34,                 /* colNo */
    "",                 /* aName */
    "cellstr_ismember", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\matlab\\datatypes\\shared\\codegen\\+"
    "matlab\\+internal\\+coder\\+datatypes\\cellstr_ismember.m", /* pName */
    0                                                            /* checkKind */
};

static emlrtBCInfo cb_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    159,                /* lineNo */
    40,                 /* colNo */
    "",                 /* aName */
    "cellstr_ismember", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\matlab\\datatypes\\shared\\codegen\\+"
    "matlab\\+internal\\+coder\\+datatypes\\cellstr_ismember.m", /* pName */
    0                                                            /* checkKind */
};

static emlrtBCInfo db_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    160,                /* lineNo */
    28,                 /* colNo */
    "",                 /* aName */
    "cellstr_ismember", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\matlab\\datatypes\\shared\\codegen\\+"
    "matlab\\+internal\\+coder\\+datatypes\\cellstr_ismember.m", /* pName */
    0                                                            /* checkKind */
};

static emlrtBCInfo eb_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    161,                /* lineNo */
    38,                 /* colNo */
    "",                 /* aName */
    "cellstr_ismember", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\matlab\\datatypes\\shared\\codegen\\+"
    "matlab\\+internal\\+coder\\+datatypes\\cellstr_ismember.m", /* pName */
    0                                                            /* checkKind */
};

static emlrtBCInfo fb_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    161,                /* lineNo */
    30,                 /* colNo */
    "",                 /* aName */
    "cellstr_ismember", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\matlab\\datatypes\\shared\\codegen\\+"
    "matlab\\+internal\\+coder\\+datatypes\\cellstr_ismember.m", /* pName */
    0                                                            /* checkKind */
};

static emlrtBCInfo gb_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    167,                /* lineNo */
    52,                 /* colNo */
    "",                 /* aName */
    "cellstr_ismember", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\matlab\\datatypes\\shared\\codegen\\+"
    "matlab\\+internal\\+coder\\+datatypes\\cellstr_ismember.m", /* pName */
    0                                                            /* checkKind */
};

static emlrtBCInfo hb_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    167,                /* lineNo */
    58,                 /* colNo */
    "",                 /* aName */
    "cellstr_ismember", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\matlab\\datatypes\\shared\\codegen\\+"
    "matlab\\+internal\\+coder\\+datatypes\\cellstr_ismember.m", /* pName */
    0                                                            /* checkKind */
};

static emlrtBCInfo ib_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    168,                /* lineNo */
    32,                 /* colNo */
    "",                 /* aName */
    "cellstr_ismember", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\matlab\\datatypes\\shared\\codegen\\+"
    "matlab\\+internal\\+coder\\+datatypes\\cellstr_ismember.m", /* pName */
    0                                                            /* checkKind */
};

static emlrtBCInfo jb_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    169,                /* lineNo */
    42,                 /* colNo */
    "",                 /* aName */
    "cellstr_ismember", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\matlab\\datatypes\\shared\\codegen\\+"
    "matlab\\+internal\\+coder\\+datatypes\\cellstr_ismember.m", /* pName */
    0                                                            /* checkKind */
};

static emlrtBCInfo kb_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    169,                /* lineNo */
    34,                 /* colNo */
    "",                 /* aName */
    "cellstr_ismember", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\matlab\\datatypes\\shared\\codegen\\+"
    "matlab\\+internal\\+coder\\+datatypes\\cellstr_ismember.m", /* pName */
    0                                                            /* checkKind */
};

static emlrtBCInfo lb_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    179,                /* lineNo */
    25,                 /* colNo */
    "",                 /* aName */
    "cellstr_ismember", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\matlab\\datatypes\\shared\\codegen\\+"
    "matlab\\+internal\\+coder\\+datatypes\\cellstr_ismember.m", /* pName */
    0                                                            /* checkKind */
};

static emlrtBCInfo mb_emlrtBCI = {
    -1,                 /* iFirst */
    -1,                 /* iLast */
    178,                /* lineNo */
    22,                 /* colNo */
    "",                 /* aName */
    "cellstr_ismember", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\matlab\\datatypes\\shared\\codegen\\+"
    "matlab\\+internal\\+coder\\+datatypes\\cellstr_ismember.m", /* pName */
    0                                                            /* checkKind */
};

static emlrtBCInfo nb_emlrtBCI = {
    1,                /* iFirst */
    2,                /* iLast */
    56,               /* lineNo */
    8,                /* colNo */
    "",               /* aName */
    "cellstr_unique", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\matlab\\datatypes\\shared\\codegen\\+"
    "matlab\\+internal\\+coder\\+datatypes\\cellstr_unique.m", /* pName */
    3                                                          /* checkKind */
};

static emlrtBCInfo ob_emlrtBCI = {
    1,                /* iFirst */
    2,                /* iLast */
    56,               /* lineNo */
    5,                /* colNo */
    "",               /* aName */
    "cellstr_unique", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\matlab\\datatypes\\shared\\codegen\\+"
    "matlab\\+internal\\+coder\\+datatypes\\cellstr_unique.m", /* pName */
    3                                                          /* checkKind */
};

static emlrtRTEInfo jb_emlrtRTEI = {
    37,               /* lineNo */
    25,               /* colNo */
    "cellstr_unique", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\matlab\\datatypes\\shared\\codegen\\+"
    "matlab\\+internal\\+coder\\+datatypes\\cellstr_unique.m" /* pName */
};

static emlrtRTEInfo lb_emlrtRTEI = {
    37,               /* lineNo */
    30,               /* colNo */
    "cellstr_unique", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\matlab\\datatypes\\shared\\codegen\\+"
    "matlab\\+internal\\+coder\\+datatypes\\cellstr_unique.m" /* pName */
};

/* Function Definitions */
void cellstr_ismember(const emlrtStack *sp, const cell_wrap_1 a[2],
                      const cell_wrap_1 b[2], boolean_T lia[2], real_T locb[2])
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack st;
  emxArray_cell_wrap_1_2 uA;
  emxArray_cell_wrap_1_2 uB;
  emxArray_int32_T *varargin_1;
  emxArray_real_T *y;
  real_T b_y_data[2];
  real_T *y_data;
  int32_T a__2_data[2];
  int32_T ib_data[2];
  int32_T idx[2];
  int32_T ii_data[2];
  int32_T b_i;
  int32_T c_i;
  int32_T i;
  int32_T ib_size;
  int32_T ii_size;
  int32_T j;
  int32_T minSize;
  int32_T uAInUB_size;
  int32_T *varargin_1_data;
  int8_T icA[2];
  boolean_T b_d[2];
  boolean_T d;
  boolean_T exitg1;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  st.site = &rb_emlrtRSI;
  b_st.site = &sb_emlrtRSI;
  c_st.site = &db_emlrtRSI;
  introsort(&c_st, a, idx);
  if ((idx[0] - 1 < 0) || (idx[0] - 1 > 1)) {
    emlrtDynamicBoundsCheckR2012b(idx[0] - 1, 0, 1, &q_emlrtBCI, &b_st);
  }
  if ((idx[1] - 1 < 0) || (idx[1] - 1 > 1)) {
    emlrtDynamicBoundsCheckR2012b(idx[1] - 1, 0, 1, &q_emlrtBCI, &b_st);
  }
  emxInit_cell_wrap_1_2(&uA);
  b_st.site = &tb_emlrtRSI;
  c_st.site = &jb_emlrtRSI;
  d = !b_strcmp(&c_st, a[idx[0] - 1].f1, a[idx[1] - 1].f1);
  b_d[0] = true;
  b_d[1] = d;
  i = uA.size[0];
  uA.size[0] = d + 1;
  emxEnsureCapacity_cell_wrap_11(&st, uA.data, d + 1, i, &ib_emlrtRTEI);
  b_st.site = &ub_emlrtRSI;
  c_st.site = &xb_emlrtRSI;
  eml_find(&c_st, b_d, ii_data, &ii_size);
  emxInit_real_T(&st, &y, 2, &lb_emlrtRTEI);
  y_data = y->data;
  emxInit_int32_T(&st, &varargin_1, 1, &jb_emlrtRTEI);
  for (b_i = 0; b_i < ii_size; b_i++) {
    if (b_i + 1 != ii_size) {
      if (b_i + 2 > ii_size) {
        emlrtDynamicBoundsCheckR2012b(b_i + 2, 1, ii_size, &o_emlrtBCI, &st);
      }
      b_st.site = &vb_emlrtRSI;
      if (b_i + 1 > ii_size) {
        emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, ii_size, &n_emlrtBCI, &b_st);
      }
      c_st.site = &cc_emlrtRSI;
      i = ii_data[b_i];
      if ((real_T)ii_data[1] - 1.0 < i) {
        y->size[0] = 1;
        y->size[1] = 0;
      } else {
        uAInUB_size = y->size[0] * y->size[1];
        y->size[0] = 1;
        c_i = (int32_T)(((real_T)ii_data[1] - 1.0) - (real_T)i);
        y->size[1] = c_i + 1;
        emxEnsureCapacity_real_T(&c_st, y, uAInUB_size, &bb_emlrtRTEI);
        y_data = y->data;
        for (uAInUB_size = 0; uAInUB_size <= c_i; uAInUB_size++) {
          y_data[uAInUB_size] = (real_T)i + (real_T)uAInUB_size;
        }
      }
      b_st.site = &vb_emlrtRSI;
      i = varargin_1->size[0];
      varargin_1->size[0] = y->size[1];
      emxEnsureCapacity_int32_T(&b_st, varargin_1, i, &jb_emlrtRTEI);
      varargin_1_data = varargin_1->data;
      c_i = y->size[1];
      for (i = 0; i < c_i; i++) {
        uAInUB_size = (int32_T)y_data[i];
        if (y_data[i] != uAInUB_size) {
          emlrtIntegerCheckR2012b(y_data[i], &emlrtDCI, &b_st);
        }
        varargin_1_data[i] = idx[uAInUB_size - 1];
      }
      c_st.site = &dc_emlrtRSI;
      d_st.site = &ec_emlrtRSI;
      e_st.site = &fc_emlrtRSI;
      if (y->size[1] < 1) {
        emlrtErrorWithMessageIdR2018a(
            &e_st, &e_emlrtRTEI, "Coder:toolbox:eml_min_or_max_varDimZero",
            "Coder:toolbox:eml_min_or_max_varDimZero", 0);
      }
      if (b_i + 1 > ii_size) {
        emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, ii_size, &v_emlrtBCI, &st);
      }
      a__2_data[b_i] = varargin_1_data[0];
    } else {
      b_st.site = &wb_emlrtRSI;
      if (b_i + 1 > ii_size) {
        emlrtDynamicBoundsCheckR2012b(2, 1, ii_size, &p_emlrtBCI, &b_st);
      }
      c_st.site = &cc_emlrtRSI;
      i = ii_data[b_i];
      j = 3 - i;
      c_i = 2 - i;
      for (uAInUB_size = 0; uAInUB_size <= c_i; uAInUB_size++) {
        b_y_data[uAInUB_size] = (real_T)ii_data[b_i] + (real_T)uAInUB_size;
      }
      b_st.site = &wb_emlrtRSI;
      for (uAInUB_size = 0; uAInUB_size < j; uAInUB_size++) {
        minSize = (int32_T)b_y_data[uAInUB_size];
        if ((minSize < 1) || (minSize > 2)) {
          emlrtDynamicBoundsCheckR2012b(minSize, 1, 2, &u_emlrtBCI, &b_st);
        }
      }
      c_st.site = &dc_emlrtRSI;
      d_st.site = &ec_emlrtRSI;
      e_st.site = &fc_emlrtRSI;
      if (3 - i < 1) {
        emlrtErrorWithMessageIdR2018a(
            &e_st, &e_emlrtRTEI, "Coder:toolbox:eml_min_or_max_varDimZero",
            "Coder:toolbox:eml_min_or_max_varDimZero", 0);
      }
      minSize = idx[(int32_T)b_y_data[0] - 1];
      for (c_i = 2; c_i <= j; c_i++) {
        i = idx[(int32_T)b_y_data[1] - 1];
        if (minSize > i) {
          minSize = i;
        }
      }
      if (b_i + 1 > ii_size) {
        emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, ii_size, &ab_emlrtBCI, &st);
      }
      a__2_data[b_i] = minSize;
    }
  }
  icA[0] = 1;
  icA[1] = (int8_T)(d + 1);
  if ((idx[0] < 1) || (idx[0] > 2)) {
    emlrtDynamicBoundsCheckR2012b(idx[0], 1, 2, &ob_emlrtBCI, &st);
  }
  icA[idx[0] - 1] = 1;
  if ((idx[1] < 1) || (idx[1] > 2)) {
    emlrtDynamicBoundsCheckR2012b(idx[1], 1, 2, &ob_emlrtBCI, &st);
  }
  icA[idx[1] - 1] = (int8_T)(d + 1);
  for (b_i = 0; b_i < ii_size; b_i++) {
    if (b_i + 1 > ii_size) {
      emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, ii_size, &t_emlrtBCI, &st);
    }
    i = a__2_data[b_i];
    if ((i - 1 < 0) || (i - 1 > 1)) {
      emlrtDynamicBoundsCheckR2012b(i - 1, 0, 1, &r_emlrtBCI, &st);
    }
    if (b_i + 1 > ii_size) {
      emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, ii_size, &t_emlrtBCI, &st);
    }
    if ((i - 1 < 0) || (i - 1 > 1)) {
      emlrtDynamicBoundsCheckR2012b(i - 1, 0, 1, &r_emlrtBCI, &st);
    }
    c_i = a[i - 1].f1->size[1] - 1;
    if (b_i > uA.size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(1, 0, uA.size[0] - 1, &s_emlrtBCI, &st);
    }
    uAInUB_size = uA.data[b_i].f1->size[0] * uA.data[b_i].f1->size[1];
    uA.data[b_i].f1->size[0] = 1;
    emxEnsureCapacity_char_T(&st, uA.data[b_i].f1, uAInUB_size, &kb_emlrtRTEI);
    if (b_i + 1 > ii_size) {
      emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, ii_size, &t_emlrtBCI, &st);
    }
    if ((i - 1 < 0) || (i - 1 > 1)) {
      emlrtDynamicBoundsCheckR2012b(i - 1, 0, 1, &r_emlrtBCI, &st);
    }
    if (b_i > uA.size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(1, 0, uA.size[0] - 1, &s_emlrtBCI, &st);
    }
    uAInUB_size = uA.data[b_i].f1->size[0] * uA.data[b_i].f1->size[1];
    uA.data[b_i].f1->size[1] = a[i - 1].f1->size[1];
    emxEnsureCapacity_char_T(&st, uA.data[b_i].f1, uAInUB_size, &kb_emlrtRTEI);
    i = uA.size[0];
    if (b_i > uA.size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(1, 0, uA.size[0] - 1, &s_emlrtBCI, &st);
    }
    if (b_i > uA.size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(1, 0, uA.size[0] - 1, &s_emlrtBCI, &st);
    }
    for (uAInUB_size = 0; uAInUB_size <= c_i; uAInUB_size++) {
      if (b_i + 1 > ii_size) {
        emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, ii_size, &x_emlrtBCI, &st);
      }
      minSize = a__2_data[b_i] - 1;
      if ((minSize < 0) || (minSize > 1)) {
        emlrtDynamicBoundsCheckR2012b(minSize, 0, 1, &w_emlrtBCI, &st);
      }
      if (b_i > i - 1) {
        emlrtDynamicBoundsCheckR2012b(1, 0, i - 1, &y_emlrtBCI, &st);
      }
      uA.data[b_i].f1->data[uAInUB_size] = a[minSize].f1->data[uAInUB_size];
    }
  }
  st.site = &qb_emlrtRSI;
  b_st.site = &sb_emlrtRSI;
  c_st.site = &db_emlrtRSI;
  introsort(&c_st, b, idx);
  if ((idx[0] - 1 < 0) || (idx[0] - 1 > 1)) {
    emlrtDynamicBoundsCheckR2012b(idx[0] - 1, 0, 1, &q_emlrtBCI, &b_st);
  }
  if ((idx[1] - 1 < 0) || (idx[1] - 1 > 1)) {
    emlrtDynamicBoundsCheckR2012b(idx[1] - 1, 0, 1, &q_emlrtBCI, &b_st);
  }
  emxInit_cell_wrap_1_2(&uB);
  b_st.site = &tb_emlrtRSI;
  c_st.site = &jb_emlrtRSI;
  d = !b_strcmp(&c_st, b[idx[0] - 1].f1, b[idx[1] - 1].f1);
  b_d[0] = true;
  b_d[1] = d;
  i = uB.size[0];
  uB.size[0] = d + 1;
  emxEnsureCapacity_cell_wrap_11(&st, uB.data, d + 1, i, &ib_emlrtRTEI);
  b_st.site = &ub_emlrtRSI;
  c_st.site = &xb_emlrtRSI;
  eml_find(&c_st, b_d, ii_data, &ii_size);
  ib_size = ii_size;
  for (b_i = 0; b_i < ii_size; b_i++) {
    if (b_i + 1 != ii_size) {
      real_T c_d;
      if (b_i + 2 > ii_size) {
        emlrtDynamicBoundsCheckR2012b(b_i + 2, 1, ii_size, &o_emlrtBCI, &st);
      }
      b_st.site = &vb_emlrtRSI;
      if (b_i + 1 > ii_size) {
        emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, ii_size, &n_emlrtBCI, &b_st);
      }
      c_st.site = &cc_emlrtRSI;
      c_d = ii_data[b_i];
      if ((real_T)ii_data[1] - 1.0 < c_d) {
        y->size[0] = 1;
        y->size[1] = 0;
      } else {
        i = y->size[0] * y->size[1];
        y->size[0] = 1;
        c_i = (int32_T)(((real_T)ii_data[1] - 1.0) - c_d);
        y->size[1] = c_i + 1;
        emxEnsureCapacity_real_T(&c_st, y, i, &bb_emlrtRTEI);
        y_data = y->data;
        for (i = 0; i <= c_i; i++) {
          y_data[i] = c_d + (real_T)i;
        }
      }
      b_st.site = &vb_emlrtRSI;
      i = varargin_1->size[0];
      varargin_1->size[0] = y->size[1];
      emxEnsureCapacity_int32_T(&b_st, varargin_1, i, &jb_emlrtRTEI);
      varargin_1_data = varargin_1->data;
      c_i = y->size[1];
      for (i = 0; i < c_i; i++) {
        uAInUB_size = (int32_T)y_data[i];
        if (y_data[i] != uAInUB_size) {
          emlrtIntegerCheckR2012b(y_data[i], &emlrtDCI, &b_st);
        }
        varargin_1_data[i] = idx[uAInUB_size - 1];
      }
      c_st.site = &dc_emlrtRSI;
      d_st.site = &ec_emlrtRSI;
      e_st.site = &fc_emlrtRSI;
      if (y->size[1] < 1) {
        emlrtErrorWithMessageIdR2018a(
            &e_st, &e_emlrtRTEI, "Coder:toolbox:eml_min_or_max_varDimZero",
            "Coder:toolbox:eml_min_or_max_varDimZero", 0);
      }
      if (b_i + 1 > ii_size) {
        emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, ii_size, &v_emlrtBCI, &st);
      }
      ib_data[b_i] = varargin_1_data[0];
    } else {
      b_st.site = &wb_emlrtRSI;
      if (b_i + 1 > ii_size) {
        emlrtDynamicBoundsCheckR2012b(2, 1, ii_size, &p_emlrtBCI, &b_st);
      }
      c_st.site = &cc_emlrtRSI;
      i = ii_data[b_i];
      j = 3 - i;
      c_i = 2 - i;
      for (uAInUB_size = 0; uAInUB_size <= c_i; uAInUB_size++) {
        b_y_data[uAInUB_size] = (real_T)ii_data[b_i] + (real_T)uAInUB_size;
      }
      b_st.site = &wb_emlrtRSI;
      for (uAInUB_size = 0; uAInUB_size < j; uAInUB_size++) {
        minSize = (int32_T)b_y_data[uAInUB_size];
        if ((minSize < 1) || (minSize > 2)) {
          emlrtDynamicBoundsCheckR2012b(minSize, 1, 2, &u_emlrtBCI, &b_st);
        }
      }
      c_st.site = &dc_emlrtRSI;
      d_st.site = &ec_emlrtRSI;
      e_st.site = &fc_emlrtRSI;
      if (3 - i < 1) {
        emlrtErrorWithMessageIdR2018a(
            &e_st, &e_emlrtRTEI, "Coder:toolbox:eml_min_or_max_varDimZero",
            "Coder:toolbox:eml_min_or_max_varDimZero", 0);
      }
      minSize = idx[(int32_T)b_y_data[0] - 1];
      for (c_i = 2; c_i <= j; c_i++) {
        i = idx[(int32_T)b_y_data[1] - 1];
        if (minSize > i) {
          minSize = i;
        }
      }
      if (b_i + 1 > ii_size) {
        emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, ii_size, &ab_emlrtBCI, &st);
      }
      ib_data[b_i] = minSize;
    }
  }
  emxFree_int32_T(&st, &varargin_1);
  emxFree_real_T(&st, &y);
  if ((idx[0] < 1) || (idx[0] > 2)) {
    emlrtDynamicBoundsCheckR2012b(idx[0], 1, 2, &nb_emlrtBCI, &st);
  }
  if ((idx[1] < 1) || (idx[1] > 2)) {
    emlrtDynamicBoundsCheckR2012b(idx[1], 1, 2, &nb_emlrtBCI, &st);
  }
  for (b_i = 0; b_i < ii_size; b_i++) {
    if (b_i + 1 > ii_size) {
      emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, ii_size, &t_emlrtBCI, &st);
    }
    i = ib_data[b_i];
    if ((i - 1 < 0) || (i - 1 > 1)) {
      emlrtDynamicBoundsCheckR2012b(i - 1, 0, 1, &r_emlrtBCI, &st);
    }
    if (b_i + 1 > ii_size) {
      emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, ii_size, &t_emlrtBCI, &st);
    }
    if ((i - 1 < 0) || (i - 1 > 1)) {
      emlrtDynamicBoundsCheckR2012b(i - 1, 0, 1, &r_emlrtBCI, &st);
    }
    c_i = b[i - 1].f1->size[1] - 1;
    if (b_i > uB.size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(1, 0, uB.size[0] - 1, &s_emlrtBCI, &st);
    }
    uAInUB_size = uB.data[b_i].f1->size[0] * uB.data[b_i].f1->size[1];
    uB.data[b_i].f1->size[0] = 1;
    emxEnsureCapacity_char_T(&st, uB.data[b_i].f1, uAInUB_size, &kb_emlrtRTEI);
    if (b_i + 1 > ii_size) {
      emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, ii_size, &t_emlrtBCI, &st);
    }
    if ((i - 1 < 0) || (i - 1 > 1)) {
      emlrtDynamicBoundsCheckR2012b(i - 1, 0, 1, &r_emlrtBCI, &st);
    }
    if (b_i > uB.size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(1, 0, uB.size[0] - 1, &s_emlrtBCI, &st);
    }
    uAInUB_size = uB.data[b_i].f1->size[0] * uB.data[b_i].f1->size[1];
    uB.data[b_i].f1->size[1] = b[i - 1].f1->size[1];
    emxEnsureCapacity_char_T(&st, uB.data[b_i].f1, uAInUB_size, &kb_emlrtRTEI);
    i = uB.size[0];
    if (b_i > uB.size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(1, 0, uB.size[0] - 1, &s_emlrtBCI, &st);
    }
    if (b_i > uB.size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(1, 0, uB.size[0] - 1, &s_emlrtBCI, &st);
    }
    for (uAInUB_size = 0; uAInUB_size <= c_i; uAInUB_size++) {
      if (b_i + 1 > ii_size) {
        emlrtDynamicBoundsCheckR2012b(b_i + 1, 1, ii_size, &x_emlrtBCI, &st);
      }
      minSize = ib_data[b_i] - 1;
      if ((minSize < 0) || (minSize > 1)) {
        emlrtDynamicBoundsCheckR2012b(minSize, 0, 1, &w_emlrtBCI, &st);
      }
      if (b_i > i - 1) {
        emlrtDynamicBoundsCheckR2012b(1, 0, i - 1, &y_emlrtBCI, &st);
      }
      uB.data[b_i].f1->data[uAInUB_size] = b[minSize].f1->data[uAInUB_size];
    }
  }
  uAInUB_size = uA.size[0];
  c_i = uA.size[0];
  memset(&b_d[0], 0, c_i * sizeof(boolean_T));
  ii_size = uA.size[0];
  c_i = uA.size[0];
  memset(&ii_data[0], 0, c_i * sizeof(int32_T));
  j = 0;
  b_i = 0;
  exitg1 = false;
  while ((!exitg1) && (b_i <= uA.size[0] - 1)) {
    if (b_i > uA.size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(1, 0, uA.size[0] - 1, &m_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    if (j > uB.size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(j, 0, uB.size[0] - 1, &l_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    minSize = uA.data[b_i].f1->size[1];
    c_i = uB.data[j].f1->size[1];
    minSize = muIntScalarMin_sint32(minSize, c_i);
    if (minSize == 0) {
      d = (uA.data[b_i].f1->size[1] < uB.data[j].f1->size[1]);
    } else {
      c_i = 0;
      while ((c_i + 1 <= minSize) &&
             (uA.data[b_i].f1->data[c_i] == uB.data[j].f1->data[c_i])) {
        c_i++;
      }
      if (c_i + 1 == minSize + 1) {
        d = (uA.data[b_i].f1->size[1] < uB.data[j].f1->size[1]);
      } else {
        d = (uA.data[b_i].f1->data[c_i] < uB.data[j].f1->data[c_i]);
      }
    }
    if (!d) {
      if (b_i > uA.size[0] - 1) {
        emlrtDynamicBoundsCheckR2012b(1, 0, uA.size[0] - 1, &bb_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      if (j > uB.size[0] - 1) {
        emlrtDynamicBoundsCheckR2012b(1, 0, uB.size[0] - 1, &cb_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      st.site = &pb_emlrtRSI;
      if (b_strcmp(&st, uA.data[b_i].f1, uB.data[j].f1)) {
        if (b_i + 1 > uAInUB_size) {
          emlrtDynamicBoundsCheckR2012b(2, 1, uAInUB_size, &db_emlrtBCI,
                                        (emlrtCTX)sp);
        }
        b_d[b_i] = true;
        if (j + 1 > ib_size) {
          emlrtDynamicBoundsCheckR2012b(j + 1, 1, ib_size, &eb_emlrtBCI,
                                        (emlrtCTX)sp);
        }
        if (b_i + 1 > ii_size) {
          emlrtDynamicBoundsCheckR2012b(2, 1, ii_size, &fb_emlrtBCI,
                                        (emlrtCTX)sp);
        }
        ii_data[b_i] = ib_data[j];
        j++;
      } else {
        boolean_T exitg2;
        exitg2 = false;
        while ((!exitg2) && (j + 1 <= uB.size[0])) {
          if (b_i > uA.size[0] - 1) {
            emlrtDynamicBoundsCheckR2012b(1, 0, uA.size[0] - 1, &k_emlrtBCI,
                                          (emlrtCTX)sp);
          }
          if (j > uB.size[0] - 1) {
            emlrtDynamicBoundsCheckR2012b(j, 0, uB.size[0] - 1, &j_emlrtBCI,
                                          (emlrtCTX)sp);
          }
          minSize = uA.data[b_i].f1->size[1];
          c_i = uB.data[j].f1->size[1];
          minSize = muIntScalarMin_sint32(minSize, c_i);
          if (minSize == 0) {
            d = (uA.data[b_i].f1->size[1] > uB.data[j].f1->size[1]);
          } else {
            c_i = 0;
            while ((c_i + 1 <= minSize) &&
                   (uA.data[b_i].f1->data[c_i] == uB.data[j].f1->data[c_i])) {
              c_i++;
            }
            if (c_i + 1 == minSize + 1) {
              d = (uA.data[b_i].f1->size[1] > uB.data[j].f1->size[1]);
            } else {
              d = (uA.data[b_i].f1->data[c_i] > uB.data[j].f1->data[c_i]);
            }
          }
          if (d) {
            j++;
          } else {
            exitg2 = true;
          }
        }
        if (j + 1 <= uB.size[0]) {
          if (b_i > uA.size[0] - 1) {
            emlrtDynamicBoundsCheckR2012b(1, 0, uA.size[0] - 1, &gb_emlrtBCI,
                                          (emlrtCTX)sp);
          }
          if (j > uB.size[0] - 1) {
            emlrtDynamicBoundsCheckR2012b(j, 0, uB.size[0] - 1, &hb_emlrtBCI,
                                          (emlrtCTX)sp);
          }
          st.site = &ob_emlrtRSI;
          if (b_strcmp(&st, uA.data[b_i].f1, uB.data[j].f1)) {
            if (b_i + 1 > uAInUB_size) {
              emlrtDynamicBoundsCheckR2012b(2, 1, uAInUB_size, &ib_emlrtBCI,
                                            (emlrtCTX)sp);
            }
            b_d[b_i] = true;
            if (j + 1 > ib_size) {
              emlrtDynamicBoundsCheckR2012b(j + 1, 1, ib_size, &jb_emlrtBCI,
                                            (emlrtCTX)sp);
            }
            if (b_i + 1 > ii_size) {
              emlrtDynamicBoundsCheckR2012b(2, 1, ii_size, &kb_emlrtBCI,
                                            (emlrtCTX)sp);
            }
            ii_data[b_i] = ib_data[j];
            j++;
          }
        }
      }
    }
    if (j + 1 > uB.size[0]) {
      exitg1 = true;
    } else {
      b_i++;
    }
  }
  emxFree_cell_wrap_1_2(sp, &uB);
  emxFree_cell_wrap_1_2(sp, &uA);
  if (icA[0] > uA.size[0]) {
    emlrtDynamicBoundsCheckR2012b(2, 1, uA.size[0], &mb_emlrtBCI, (emlrtCTX)sp);
  }
  lia[0] = b_d[icA[0] - 1];
  if (icA[1] > uA.size[0]) {
    emlrtDynamicBoundsCheckR2012b(2, 1, 1, &mb_emlrtBCI, (emlrtCTX)sp);
  }
  lia[1] = b_d[icA[1] - 1];
  if (icA[0] > uA.size[0]) {
    emlrtDynamicBoundsCheckR2012b(2, 1, uA.size[0], &lb_emlrtBCI, (emlrtCTX)sp);
  }
  locb[0] = ii_data[icA[0] - 1];
  if (icA[1] > uA.size[0]) {
    emlrtDynamicBoundsCheckR2012b(2, 1, 1, &lb_emlrtBCI, (emlrtCTX)sp);
  }
  locb[1] = ii_data[icA[1] - 1];
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

/* End of code generation (cellstr_ismember.c) */
