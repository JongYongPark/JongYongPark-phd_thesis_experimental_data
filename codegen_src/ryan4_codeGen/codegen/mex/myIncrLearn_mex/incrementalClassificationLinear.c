/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * incrementalClassificationLinear.c
 *
 * Code generation for function 'incrementalClassificationLinear'
 *
 */

/* Include files */
#include "incrementalClassificationLinear.h"
#include "ClassificationModel.h"
#include "categorical.h"
#include "myIncrLearn_mex_data.h"
#include "myIncrLearn_mex_emxutil.h"
#include "myIncrLearn_mex_types.h"
#include "rt_nonfinite.h"
#include "sumMatrixIncludeNaN.h"
#include "mwmathutil.h"
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo pc_emlrtRSI = {
    176,                                                 /* lineNo */
    "incrementalClassificationLinear/transformAndLabel", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\stats\\incremental\\+incremental\\+"
    "coder\\incrementalClassificationLinear.m" /* pathName */
};

static emlrtRSInfo qc_emlrtRSI = {
    656,                            /* lineNo */
    "ClassificationModel/maxScore", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\stats\\incremental\\+incremental\\+"
    "coder\\+classif\\ClassificationModel.m" /* pathName */
};

static emlrtRSInfo rc_emlrtRSI = {
    705,                            /* lineNo */
    "ClassificationModel/maxScore", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\stats\\incremental\\+incremental\\+"
    "coder\\+classif\\ClassificationModel.m" /* pathName */
};

static emlrtRSInfo sc_emlrtRSI = {
    707,                            /* lineNo */
    "ClassificationModel/maxScore", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\stats\\incremental\\+incremental\\+"
    "coder\\+classif\\ClassificationModel.m" /* pathName */
};

static emlrtRSInfo tc_emlrtRSI = {
    716,                            /* lineNo */
    "ClassificationModel/maxScore", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\stats\\incremental\\+incremental\\+"
    "coder\\+classif\\ClassificationModel.m" /* pathName */
};

static emlrtRSInfo uc_emlrtRSI = {
    28,       /* lineNo */
    "repmat", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\eml\\lib\\matlab\\elmat\\repmat.m" /* pathName
                                                                         */
};

static emlrtRSInfo vc_emlrtRSI = {
    144,      /* lineNo */
    "repmat", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\eml\\lib\\matlab\\elmat\\repmat.m" /* pathName
                                                                         */
};

static emlrtRSInfo wc_emlrtRSI = {
    126,                       /* lineNo */
    "categorical/categorical", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\matlab\\datatypes\\codegen\\categorical\\+"
    "matlab\\+internal\\+coder\\@categorical\\categorical.m" /* pathName */
};

static emlrtRSInfo xc_emlrtRSI = {
    240,                       /* lineNo */
    "categorical/categorical", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\matlab\\datatypes\\codegen\\categorical\\+"
    "matlab\\+internal\\+coder\\@categorical\\categorical.m" /* pathName */
};

static emlrtRSInfo yc_emlrtRSI = {
    21,                /* lineNo */
    "cellstr_strtrim", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\matlab\\datatypes\\shared\\codegen\\+"
    "matlab\\+internal\\+coder\\+datatypes\\cellstr_strtrim.m" /* pathName */
};

static emlrtRSInfo ad_emlrtRSI = {
    23,        /* lineNo */
    "strtrim", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\eml\\lib\\matlab\\strfun\\strtrim.m" /* pathName
                                                                           */
};

static emlrtRSInfo bd_emlrtRSI = {
    24,        /* lineNo */
    "strtrim", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\eml\\lib\\matlab\\strfun\\strtrim.m" /* pathName
                                                                           */
};

static emlrtRSInfo cd_emlrtRSI = {
    32,         /* lineNo */
    "firstcol", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\eml\\lib\\matlab\\strfun\\strtrim.m" /* pathName
                                                                           */
};

static emlrtRSInfo dd_emlrtRSI = {
    51,          /* lineNo */
    "allwspace", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\eml\\lib\\matlab\\strfun\\strtrim.m" /* pathName
                                                                           */
};

static emlrtRSInfo
    ed_emlrtRSI =
        {
            15,          /* lineNo */
            "isstrprop", /* fcnName */
            "C:\\Program "
            "Files\\MATLAB\\R2022a\\toolbox\\eml\\lib\\matlab\\strfun\\isstrpro"
            "p.m" /* pathName */
};

static emlrtRSInfo
    fd_emlrtRSI =
        {
            23,                         /* lineNo */
            "apply_property_predicate", /* fcnName */
            "C:\\Program "
            "Files\\MATLAB\\R2022a\\toolbox\\eml\\lib\\matlab\\strfun\\isstrpro"
            "p.m" /* pathName */
};

static emlrtRSInfo gd_emlrtRSI = {
    41,        /* lineNo */
    "lastcol", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\eml\\lib\\matlab\\strfun\\strtrim.m" /* pathName
                                                                           */
};

static emlrtRSInfo ah_emlrtRSI = {
    194,                                                         /* lineNo */
    "incrementalClassificationLinear/prepareDataAndUpdateState", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\stats\\incremental\\+incremental\\+"
    "coder\\incrementalClassificationLinear.m" /* pathName */
};

static emlrtRSInfo bh_emlrtRSI = {
    181,                                             /* lineNo */
    "ClassificationModel/prepareDataAndUpdateState", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\stats\\incremental\\+incremental\\+"
    "coder\\+classif\\ClassificationModel.m" /* pathName */
};

static emlrtRSInfo ch_emlrtRSI = {
    182,                                             /* lineNo */
    "ClassificationModel/prepareDataAndUpdateState", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\stats\\incremental\\+incremental\\+"
    "coder\\+classif\\ClassificationModel.m" /* pathName */
};

static emlrtRSInfo dh_emlrtRSI = {
    184,                                             /* lineNo */
    "ClassificationModel/prepareDataAndUpdateState", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\stats\\incremental\\+incremental\\+"
    "coder\\+classif\\ClassificationModel.m" /* pathName */
};

static emlrtRSInfo eh_emlrtRSI = {
    187,                                             /* lineNo */
    "ClassificationModel/prepareDataAndUpdateState", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\stats\\incremental\\+incremental\\+"
    "coder\\+classif\\ClassificationModel.m" /* pathName */
};

static emlrtRSInfo fh_emlrtRSI = {
    197,                                             /* lineNo */
    "ClassificationModel/prepareDataAndUpdateState", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\stats\\incremental\\+incremental\\+"
    "coder\\+classif\\ClassificationModel.m" /* pathName */
};

static emlrtRSInfo gh_emlrtRSI = {
    424,                                                 /* lineNo */
    "ClassificationModel/updatePriorAndWeightsPerClass", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\stats\\incremental\\+incremental\\+"
    "coder\\+classif\\ClassificationModel.m" /* pathName */
};

static emlrtBCInfo ye_emlrtBCI = {
    -1,                             /* iFirst */
    -1,                             /* iLast */
    661,                            /* lineNo */
    56,                             /* colNo */
    "",                             /* aName */
    "ClassificationModel/maxScore", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\stats\\incremental\\+incremental\\+"
    "coder\\+classif\\ClassificationModel.m", /* pName */
    0                                         /* checkKind */
};

static emlrtBCInfo af_emlrtBCI = {
    -1,                /* iFirst */
    -1,                /* iLast */
    21,                /* lineNo */
    36,                /* colNo */
    "",                /* aName */
    "cellstr_strtrim", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\matlab\\datatypes\\shared\\codegen\\+"
    "matlab\\+internal\\+coder\\+datatypes\\cellstr_strtrim.m", /* pName */
    0                                                           /* checkKind */
};

static emlrtRTEInfo q_emlrtRTEI = {
    15,                      /* lineNo */
    9,                       /* colNo */
    "assertSupportedString", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\assertSupportedString.m" /* pName */
};

static emlrtDCInfo d_emlrtDCI = {
    712,                            /* lineNo */
    52,                             /* colNo */
    "ClassificationModel/maxScore", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\stats\\incremental\\+incremental\\+"
    "coder\\+classif\\ClassificationModel.m", /* pName */
    1                                         /* checkKind */
};

static emlrtBCInfo bf_emlrtBCI = {
    -1,                             /* iFirst */
    -1,                             /* iLast */
    712,                            /* lineNo */
    39,                             /* colNo */
    "",                             /* aName */
    "ClassificationModel/maxScore", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\stats\\incremental\\+incremental\\+"
    "coder\\+classif\\ClassificationModel.m", /* pName */
    0                                         /* checkKind */
};

static emlrtBCInfo cf_emlrtBCI = {
    -1,                             /* iFirst */
    -1,                             /* iLast */
    660,                            /* lineNo */
    39,                             /* colNo */
    "",                             /* aName */
    "ClassificationModel/maxScore", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\stats\\incremental\\+incremental\\+"
    "coder\\+classif\\ClassificationModel.m", /* pName */
    0                                         /* checkKind */
};

static emlrtBCInfo df_emlrtBCI = {
    -1,                             /* iFirst */
    -1,                             /* iLast */
    661,                            /* lineNo */
    37,                             /* colNo */
    "",                             /* aName */
    "ClassificationModel/maxScore", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\stats\\incremental\\+incremental\\+"
    "coder\\+classif\\ClassificationModel.m", /* pName */
    0                                         /* checkKind */
};

static emlrtBCInfo ef_emlrtBCI = {
    -1,                             /* iFirst */
    -1,                             /* iLast */
    711,                            /* lineNo */
    47,                             /* colNo */
    "",                             /* aName */
    "ClassificationModel/maxScore", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\stats\\incremental\\+incremental\\+"
    "coder\\+classif\\ClassificationModel.m", /* pName */
    0                                         /* checkKind */
};

static emlrtBCInfo ff_emlrtBCI = {
    -1,                             /* iFirst */
    -1,                             /* iLast */
    712,                            /* lineNo */
    61,                             /* colNo */
    "",                             /* aName */
    "ClassificationModel/maxScore", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\stats\\incremental\\+incremental\\+"
    "coder\\+classif\\ClassificationModel.m", /* pName */
    0                                         /* checkKind */
};

static emlrtDCInfo e_emlrtDCI = {
    712,                            /* lineNo */
    46,                             /* colNo */
    "ClassificationModel/maxScore", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\stats\\incremental\\+incremental\\+"
    "coder\\+classif\\ClassificationModel.m", /* pName */
    1                                         /* checkKind */
};

static emlrtBCInfo gf_emlrtBCI = {
    -1,                             /* iFirst */
    -1,                             /* iLast */
    712,                            /* lineNo */
    46,                             /* colNo */
    "",                             /* aName */
    "ClassificationModel/maxScore", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\stats\\incremental\\+incremental\\+"
    "coder\\+classif\\ClassificationModel.m", /* pName */
    0                                         /* checkKind */
};

static emlrtBCInfo hf_emlrtBCI = {
    -1,                             /* iFirst */
    -1,                             /* iLast */
    712,                            /* lineNo */
    33,                             /* colNo */
    "",                             /* aName */
    "ClassificationModel/maxScore", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\stats\\incremental\\+incremental\\+"
    "coder\\+classif\\ClassificationModel.m", /* pName */
    0                                         /* checkKind */
};

static emlrtBCInfo if_emlrtBCI = {
    -1,                        /* iFirst */
    -1,                        /* iLast */
    126,                       /* lineNo */
    21,                        /* colNo */
    "",                        /* aName */
    "categorical/categorical", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\matlab\\datatypes\\codegen\\categorical\\+"
    "matlab\\+internal\\+coder\\@categorical\\categorical.m", /* pName */
    0                                                         /* checkKind */
};

static emlrtBCInfo jf_emlrtBCI = {
    -1,                /* iFirst */
    -1,                /* iLast */
    21,                /* lineNo */
    13,                /* colNo */
    "",                /* aName */
    "cellstr_strtrim", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\matlab\\datatypes\\shared\\codegen\\+"
    "matlab\\+internal\\+coder\\+datatypes\\cellstr_strtrim.m", /* pName */
    0                                                           /* checkKind */
};

static emlrtBCInfo gg_emlrtBCI = {
    -1,                                         /* iFirst */
    -1,                                         /* iLast */
    621,                                        /* lineNo */
    34,                                         /* colNo */
    "",                                         /* aName */
    "ClassificationModel/BatchWeightsPerClass", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\stats\\incremental\\+incremental\\+"
    "coder\\+classif\\ClassificationModel.m", /* pName */
    0                                         /* checkKind */
};

static emlrtBCInfo hg_emlrtBCI = {
    -1,                                         /* iFirst */
    -1,                                         /* iLast */
    620,                                        /* lineNo */
    24,                                         /* colNo */
    "",                                         /* aName */
    "ClassificationModel/BatchWeightsPerClass", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\stats\\incremental\\+incremental\\+"
    "coder\\+classif\\ClassificationModel.m", /* pName */
    0                                         /* checkKind */
};

static emlrtBCInfo ig_emlrtBCI = {
    -1,                                         /* iFirst */
    -1,                                         /* iLast */
    620,                                        /* lineNo */
    58,                                         /* colNo */
    "",                                         /* aName */
    "ClassificationModel/BatchWeightsPerClass", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\stats\\incremental\\+incremental\\+"
    "coder\\+classif\\ClassificationModel.m", /* pName */
    0                                         /* checkKind */
};

static emlrtBCInfo jg_emlrtBCI = {
    -1,                                         /* iFirst */
    -1,                                         /* iLast */
    620,                                        /* lineNo */
    39,                                         /* colNo */
    "",                                         /* aName */
    "ClassificationModel/BatchWeightsPerClass", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\stats\\incremental\\+incremental\\+"
    "coder\\+classif\\ClassificationModel.m", /* pName */
    0                                         /* checkKind */
};

static emlrtBCInfo kg_emlrtBCI = {
    -1,                                              /* iFirst */
    -1,                                              /* iLast */
    188,                                             /* lineNo */
    39,                                              /* colNo */
    "",                                              /* aName */
    "ClassificationModel/prepareDataAndUpdateState", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\stats\\incremental\\+incremental\\+"
    "coder\\+classif\\ClassificationModel.m", /* pName */
    0                                         /* checkKind */
};

static emlrtBCInfo lg_emlrtBCI = {
    -1,                                              /* iFirst */
    -1,                                              /* iLast */
    189,                                             /* lineNo */
    33,                                              /* colNo */
    "",                                              /* aName */
    "ClassificationModel/prepareDataAndUpdateState", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\stats\\incremental\\+incremental\\+"
    "coder\\+classif\\ClassificationModel.m", /* pName */
    0                                         /* checkKind */
};

static emlrtBCInfo mg_emlrtBCI = {
    -1,                                              /* iFirst */
    -1,                                              /* iLast */
    192,                                             /* lineNo */
    34,                                              /* colNo */
    "",                                              /* aName */
    "ClassificationModel/prepareDataAndUpdateState", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\stats\\incremental\\+incremental\\+"
    "coder\\+classif\\ClassificationModel.m", /* pName */
    0                                         /* checkKind */
};

static emlrtBCInfo ng_emlrtBCI = {
    -1,                                              /* iFirst */
    -1,                                              /* iLast */
    190,                                             /* lineNo */
    34,                                              /* colNo */
    "",                                              /* aName */
    "ClassificationModel/prepareDataAndUpdateState", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\stats\\incremental\\+incremental\\+"
    "coder\\+classif\\ClassificationModel.m", /* pName */
    0                                         /* checkKind */
};

static emlrtBCInfo og_emlrtBCI = {
    -1,                                         /* iFirst */
    -1,                                         /* iLast */
    619,                                        /* lineNo */
    35,                                         /* colNo */
    "",                                         /* aName */
    "ClassificationModel/BatchWeightsPerClass", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\stats\\incremental\\+incremental\\+"
    "coder\\+classif\\ClassificationModel.m", /* pName */
    0                                         /* checkKind */
};

static emlrtRTEInfo oc_emlrtRTEI = {
    654,                   /* lineNo */
    13,                    /* colNo */
    "ClassificationModel", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\stats\\incremental\\+incremental\\+"
    "coder\\+classif\\ClassificationModel.m" /* pName */
};

static emlrtRTEInfo pc_emlrtRTEI = {
    92,       /* lineNo */
    25,       /* colNo */
    "repmat", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\eml\\lib\\matlab\\elmat\\repmat.m" /* pName
                                                                         */
};

static emlrtRTEInfo qc_emlrtRTEI = {
    147,      /* lineNo */
    25,       /* colNo */
    "repmat", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\eml\\lib\\matlab\\elmat\\repmat.m" /* pName
                                                                         */
};

static emlrtRTEInfo rc_emlrtRTEI = {
    17,                /* lineNo */
    39,                /* colNo */
    "cellstr_strtrim", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\matlab\\datatypes\\shared\\codegen\\+"
    "matlab\\+internal\\+coder\\+datatypes\\cellstr_strtrim.m" /* pName */
};

static emlrtRTEInfo sc_emlrtRTEI = {
    712,                   /* lineNo */
    33,                    /* colNo */
    "ClassificationModel", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\stats\\incremental\\+incremental\\+"
    "coder\\+classif\\ClassificationModel.m" /* pName */
};

static emlrtRTEInfo tc_emlrtRTEI = {
    126,           /* lineNo */
    21,            /* colNo */
    "categorical", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\matlab\\datatypes\\codegen\\categorical\\+"
    "matlab\\+internal\\+coder\\@categorical\\categorical.m" /* pName */
};

static emlrtRTEInfo uc_emlrtRTEI = {
    705,                   /* lineNo */
    21,                    /* colNo */
    "ClassificationModel", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\stats\\incremental\\+incremental\\+"
    "coder\\+classif\\ClassificationModel.m" /* pName */
};

static emlrtRTEInfo vc_emlrtRTEI = {
    630,                   /* lineNo */
    26,                    /* colNo */
    "ClassificationModel", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\stats\\incremental\\+incremental\\+"
    "coder\\+classif\\ClassificationModel.m" /* pName */
};

/* Function Definitions */
void c_incrementalClassificationLine(
    myIncrLearn_mexStackData *SD, const emlrtStack *sp,
    const uint8_T this_ClassNames_codes[2],
    const cell_wrap_1 this_ClassNames_categoryNames[2],
    const real_T this_Prior[2], const emxArray_real_T *scores,
    const boolean_T indsToExclude_data[], int32_T indsToExclude_size,
    b_categorical *labels)
{
  static const boolean_T bv[128] = {
      false, false, false, false, false, false, false, false, false, true,
      true,  true,  true,  true,  false, false, false, false, false, false,
      false, false, false, false, false, false, false, false, true,  true,
      true,  true,  true,  false, false, false, false, false, false, false,
      false, false, false, false, false, false, false, false, false, false,
      false, false, false, false, false, false, false, false, false, false,
      false, false, false, false, false, false, false, false, false, false,
      false, false, false, false, false, false, false, false, false, false,
      false, false, false, false, false, false, false, false, false, false,
      false, false, false, false, false, false, false, false, false, false,
      false, false, false, false, false, false, false, false, false, false,
      false, false, false, false, false, false, false, false, false, false,
      false, false, false, false, false, false, false, false};
  cell_wrap_1 names[3];
  cell_wrap_1 *inData_data;
  cell_wrap_1 *ycell_data;
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack g_st;
  emlrtStack h_st;
  emlrtStack i_st;
  emlrtStack st;
  emxArray_cell_wrap_1 *inData;
  emxArray_cell_wrap_1 *ycell;
  emxArray_real_T *classnum;
  const real_T *scores_data;
  real_T a__8;
  real_T *classnum_data;
  int32_T N;
  int32_T i;
  int32_T i1;
  int32_T idx;
  int32_T j2;
  int32_T loop_ub;
  int32_T ntilerows;
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
  f_st.prev = &e_st;
  f_st.tls = e_st.tls;
  g_st.prev = &f_st;
  g_st.tls = f_st.tls;
  h_st.prev = &g_st;
  h_st.tls = g_st.tls;
  i_st.prev = &h_st;
  i_st.tls = h_st.tls;
  scores_data = scores->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  st.site = &pc_emlrtRSI;
  N = scores->size[0] - 1;
  j2 = 0;
  a__8 = rtMinusInf;
  if (this_Prior[0] > rtMinusInf) {
    a__8 = this_Prior[0];
  }
  if (a__8 < this_Prior[1]) {
    j2 = 1;
  }
  emxInit_real_T(&st, &classnum, 1, &vc_emlrtRTEI);
  i = classnum->size[0];
  classnum->size[0] = scores->size[0];
  emxEnsureCapacity_real_T(&st, classnum, i, &oc_emlrtRTEI);
  classnum_data = classnum->data;
  loop_ub = scores->size[0];
  for (i = 0; i < loop_ub; i++) {
    classnum_data[i] = rtNaN;
  }
  b_st.site = &qc_emlrtRSI;
  for (idx = 0; idx <= N; idx++) {
    if (idx + 1 > indsToExclude_size) {
      emlrtDynamicBoundsCheckR2012b(idx + 1, 1, indsToExclude_size,
                                    &cf_emlrtBCI, &st);
    }
    if (!indsToExclude_data[idx]) {
      i = scores->size[0];
      if (idx + 1 > i) {
        emlrtDynamicBoundsCheckR2012b(idx + 1, 1, i, &ye_emlrtBCI, &st);
      }
      if ((scores_data[idx] < scores_data[idx + scores->size[0]]) ||
          (muDoubleScalarIsNaN(scores_data[idx]) &&
           (!muDoubleScalarIsNaN(scores_data[idx + scores->size[0]])))) {
        ntilerows = 2;
      } else {
        ntilerows = 1;
      }
      if (idx + 1 > classnum->size[0]) {
        emlrtDynamicBoundsCheckR2012b(idx + 1, 1, classnum->size[0],
                                      &df_emlrtBCI, &st);
      }
      classnum_data[idx] = ntilerows;
    }
  }
  emxInitMatrix_cell_wrap_11(&st, names, &gb_emlrtRTEI);
  b_st.site = &rc_emlrtRSI;
  i = names[0].f1->size[0] * names[0].f1->size[1];
  names[0].f1->size[0] = 1;
  names[0].f1->size[1] = 11;
  emxEnsureCapacity_char_T(&b_st, names[0].f1, i, &y_emlrtRTEI);
  for (i = 0; i < 11; i++) {
    names[0].f1->data[i] = cv[i];
  }
  i = names[1].f1->size[0] * names[1].f1->size[1];
  names[1].f1->size[0] = 1;
  names[1].f1->size[1] = this_ClassNames_categoryNames[0].f1->size[1];
  emxEnsureCapacity_char_T(&b_st, names[1].f1, i, &ab_emlrtRTEI);
  loop_ub = this_ClassNames_categoryNames[0].f1->size[1];
  for (i = 0; i < loop_ub; i++) {
    names[1].f1->data[i] = this_ClassNames_categoryNames[0].f1->data[i];
  }
  i = names[2].f1->size[0] * names[2].f1->size[1];
  names[2].f1->size[0] = 1;
  names[2].f1->size[1] = this_ClassNames_categoryNames[1].f1->size[1];
  emxEnsureCapacity_char_T(&b_st, names[2].f1, i, &ab_emlrtRTEI);
  loop_ub = this_ClassNames_categoryNames[1].f1->size[1];
  for (i = 0; i < loop_ub; i++) {
    names[2].f1->data[i] = this_ClassNames_categoryNames[1].f1->data[i];
  }
  c_st.site = &gc_emlrtRSI;
  i = (int32_T)(this_ClassNames_codes[j2] + 1U);
  i1 = i;
  if ((uint32_T)i > 255U) {
    i1 = 255;
    i = 255;
  }
  if (i - 1 > 2) {
    emlrtDynamicBoundsCheckR2012b(i - 1, 0, 2, &h_emlrtBCI, &c_st);
  }
  emxInit_cell_wrap_1(&c_st, &ycell, &uc_emlrtRTEI);
  b_st.site = &rc_emlrtRSI;
  c_st.site = &uc_emlrtRSI;
  i = ycell->size[0];
  ycell->size[0] = scores->size[0];
  emxEnsureCapacity_cell_wrap_12(&b_st, ycell, i, &pc_emlrtRTEI);
  ycell_data = ycell->data;
  if (scores->size[0] != 0) {
    ntilerows = scores->size[0];
    c_st.site = &vc_emlrtRSI;
    for (j2 = 0; j2 < ntilerows; j2++) {
      i = ycell_data[j2].f1->size[0] * ycell_data[j2].f1->size[1];
      ycell_data[j2].f1->size[0] = 1;
      ycell_data[j2].f1->size[1] = names[(uint8_T)i1 - 1].f1->size[1];
      emxEnsureCapacity_char_T(&b_st, ycell_data[j2].f1, i, &qc_emlrtRTEI);
      loop_ub = names[(uint8_T)i1 - 1].f1->size[1];
      for (i = 0; i < loop_ub; i++) {
        ycell_data[j2].f1->data[i] = names[(uint8_T)i1 - 1].f1->data[i];
      }
    }
  }
  emxFreeMatrix_cell_wrap_11(&b_st, names);
  b_st.site = &sc_emlrtRSI;
  for (idx = 0; idx <= N; idx++) {
    if (idx + 1 > indsToExclude_size) {
      emlrtDynamicBoundsCheckR2012b(idx + 1, 1, indsToExclude_size,
                                    &ef_emlrtBCI, &st);
    }
    if (!indsToExclude_data[idx]) {
      if (idx + 1 > classnum->size[0]) {
        emlrtDynamicBoundsCheckR2012b(idx + 1, 1, classnum->size[0],
                                      &ff_emlrtBCI, &st);
      }
      a__8 = classnum_data[idx];
      if (a__8 != (int32_T)a__8) {
        emlrtIntegerCheckR2012b(a__8, &d_emlrtDCI, &st);
      }
      if (idx + 1 > classnum->size[0]) {
        emlrtDynamicBoundsCheckR2012b(idx + 1, 1, classnum->size[0],
                                      &ff_emlrtBCI, &st);
      }
      a__8 = classnum_data[idx];
      if (a__8 != (int32_T)a__8) {
        emlrtIntegerCheckR2012b(a__8, &d_emlrtDCI, &st);
      }
      loop_ub = this_ClassNames_categoryNames[(int32_T)classnum_data[idx] - 1]
                    .f1->size[1] -
                1;
      if (idx > ycell->size[0] - 1) {
        emlrtDynamicBoundsCheckR2012b(idx, 0, ycell->size[0] - 1, &bf_emlrtBCI,
                                      &st);
      }
      i = ycell_data[idx].f1->size[0] * ycell_data[idx].f1->size[1];
      ycell_data[idx].f1->size[0] = 1;
      emxEnsureCapacity_char_T(&st, ycell_data[idx].f1, i, &sc_emlrtRTEI);
      if (idx + 1 > classnum->size[0]) {
        emlrtDynamicBoundsCheckR2012b(idx + 1, 1, classnum->size[0],
                                      &ff_emlrtBCI, &st);
      }
      a__8 = classnum_data[idx];
      if (a__8 != (int32_T)a__8) {
        emlrtIntegerCheckR2012b(a__8, &d_emlrtDCI, &st);
      }
      if (idx > ycell->size[0] - 1) {
        emlrtDynamicBoundsCheckR2012b(idx, 0, ycell->size[0] - 1, &bf_emlrtBCI,
                                      &st);
      }
      i = ycell_data[idx].f1->size[0] * ycell_data[idx].f1->size[1];
      ycell_data[idx].f1->size[1] =
          this_ClassNames_categoryNames[(int32_T)classnum_data[idx] - 1]
              .f1->size[1];
      emxEnsureCapacity_char_T(&st, ycell_data[idx].f1, i, &sc_emlrtRTEI);
      i = ycell->size[0];
      if (idx > ycell->size[0] - 1) {
        emlrtDynamicBoundsCheckR2012b(idx, 0, ycell->size[0] - 1, &bf_emlrtBCI,
                                      &st);
      }
      for (i1 = 0; i1 <= loop_ub; i1++) {
        if (idx + 1 > classnum->size[0]) {
          emlrtDynamicBoundsCheckR2012b(idx + 1, 1, classnum->size[0],
                                        &gf_emlrtBCI, &st);
        }
        a__8 = classnum_data[idx];
        if (a__8 != (int32_T)a__8) {
          emlrtIntegerCheckR2012b(a__8, &e_emlrtDCI, &st);
        }
        if (idx > i - 1) {
          emlrtDynamicBoundsCheckR2012b(idx, 0, i - 1, &hf_emlrtBCI, &st);
        }
        ycell_data[idx].f1->data[i1] =
            this_ClassNames_categoryNames[(int32_T)a__8 - 1].f1->data[i1];
      }
    }
  }
  emxFree_real_T(&st, &classnum);
  emxInit_cell_wrap_1(&st, &inData, &tc_emlrtRTEI);
  b_st.site = &tc_emlrtRSI;
  labels->codes->size[0] = 0;
  labels->categoryNames->size[0] = 0;
  c_st.site = &wc_emlrtRSI;
  i = inData->size[0];
  inData->size[0] = ycell->size[0];
  emxEnsureCapacity_cell_wrap_12(&c_st, inData, i, &rc_emlrtRTEI);
  inData_data = inData->data;
  i = ycell->size[0];
  for (idx = 0; idx < i; idx++) {
    char_T x;
    boolean_T exitg1;
    boolean_T p;
    d_st.site = &yc_emlrtRSI;
    if (idx > ycell->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(idx, 0, ycell->size[0] - 1, &af_emlrtBCI,
                                    &d_st);
    }
    e_st.site = &ad_emlrtRSI;
    ntilerows = 0;
    exitg1 = false;
    while ((!exitg1) && (ntilerows + 1 <= ycell_data[idx].f1->size[1])) {
      f_st.site = &cd_emlrtRSI;
      g_st.site = &dd_emlrtRSI;
      x = ycell_data[idx].f1->data[ntilerows];
      h_st.site = &ed_emlrtRSI;
      i_st.site = &fd_emlrtRSI;
      if ((uint8_T)x > 127) {
        emlrtErrorWithMessageIdR2018a(
            &i_st, &q_emlrtRTEI, "Coder:toolbox:unsupportedString",
            "Coder:toolbox:unsupportedString", 2, 12, 127);
      }
      if ((!bv[(uint8_T)x & 127]) ||
          (ycell_data[idx].f1->data[ntilerows] == '\x00')) {
        p = false;
      } else {
        p = true;
      }
      if (p) {
        ntilerows++;
      } else {
        exitg1 = true;
      }
    }
    e_st.site = &bd_emlrtRSI;
    j2 = ycell_data[idx].f1->size[1] - 1;
    exitg1 = false;
    while ((!exitg1) && (j2 + 1 > 0)) {
      f_st.site = &gd_emlrtRSI;
      g_st.site = &dd_emlrtRSI;
      x = ycell_data[idx].f1->data[j2];
      h_st.site = &ed_emlrtRSI;
      i_st.site = &fd_emlrtRSI;
      if ((uint8_T)x > 127) {
        emlrtErrorWithMessageIdR2018a(
            &i_st, &q_emlrtRTEI, "Coder:toolbox:unsupportedString",
            "Coder:toolbox:unsupportedString", 2, 12, 127);
      }
      if ((!bv[(uint8_T)x & 127]) || (ycell_data[idx].f1->data[j2] == '\x00')) {
        p = false;
      } else {
        p = true;
      }
      if (p) {
        j2--;
      } else {
        exitg1 = true;
      }
    }
    if (ntilerows + 1 > j2 + 1) {
      ntilerows = 0;
      j2 = -1;
    }
    N = inData->size[0] - 1;
    if (idx > inData->size[0] - 1) {
      emlrtDynamicBoundsCheckR2012b(idx, 0, inData->size[0] - 1, &if_emlrtBCI,
                                    &d_st);
    }
    i1 = inData_data[idx].f1->size[0] * inData_data[idx].f1->size[1];
    inData_data[idx].f1->size[0] = 1;
    emxEnsureCapacity_char_T(&d_st, inData_data[idx].f1, i1, &tc_emlrtRTEI);
    if (idx > N) {
      emlrtDynamicBoundsCheckR2012b(idx, 0, N, &if_emlrtBCI, &d_st);
    }
    loop_ub = j2 - ntilerows;
    i1 = inData_data[idx].f1->size[0] * inData_data[idx].f1->size[1];
    inData_data[idx].f1->size[1] = loop_ub + 1;
    emxEnsureCapacity_char_T(&d_st, inData_data[idx].f1, i1, &tc_emlrtRTEI);
    for (i1 = 0; i1 <= loop_ub; i1++) {
      if (idx > N) {
        emlrtDynamicBoundsCheckR2012b(idx, 0, N, &jf_emlrtBCI, &d_st);
      }
      inData_data[idx].f1->data[i1] = ycell_data[idx].f1->data[ntilerows + i1];
    }
  }
  emxFree_cell_wrap_1(&c_st, &ycell);
  c_st.site = &xc_emlrtRSI;
  categorical_initData(SD, &c_st, labels, inData);
  emxFree_cell_wrap_1(sp, &inData);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

void d_incrementalClassificationLine(
    myIncrLearn_mexStackData *SD, const emlrtStack *sp,
    e_incrementalClassificationLine *this, const uint8_T Y_codes_data[],
    const int32_T Y_codes_size[2], const cell_wrap_22 Y_categoryNames[2],
    boolean_T Y_isOrdinal, const emxArray_real_T *W,
    const boolean_T indsToExclude_data[], int32_T indsToExclude_size,
    emxArray_int32_T *Yout)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  real_T batchWeightsPerClass_idx_0;
  real_T batchWeightsPerClass_idx_1;
  int32_T C_size_idx_0;
  int32_T WC_size_idx_0_tmp;
  int32_T i;
  int32_T ii;
  int32_T n;
  int32_T *Yout_data;
  int8_T WC_data[48150];
  boolean_T b_indsToExclude_data[24075];
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &ah_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  b_st.site = &bh_emlrtRSI;
  c_ClassificationModel_verifyCla(&b_st, this->ClassNames.codes,
                                  this->ClassNames.categoryNames, Y_codes_data,
                                  Y_codes_size, Y_categoryNames, Y_isOrdinal,
                                  indsToExclude_data, indsToExclude_size, Yout);
  Yout_data = Yout->data;
  b_st.site = &ch_emlrtRSI;
  if (indsToExclude_size - 1 >= 0) {
    memcpy(&b_indsToExclude_data[0], &indsToExclude_data[0],
           indsToExclude_size * sizeof(boolean_T));
  }
  if (this->PriorDefined) {
    n = Yout->size[0];
    for (ii = 0; ii < n; ii++) {
      if (ii + 1 > indsToExclude_size) {
        emlrtDynamicBoundsCheckR2012b(ii + 1, 1, indsToExclude_size,
                                      &le_emlrtBCI, &b_st);
      }
      if (!b_indsToExclude_data[ii]) {
        if (ii + 1 > Yout->size[0]) {
          emlrtDynamicBoundsCheckR2012b(ii + 1, 1, Yout->size[0], &ke_emlrtBCI,
                                        &b_st);
        }
        i = Yout_data[ii];
        if ((i < 1) || (i > 2)) {
          emlrtDynamicBoundsCheckR2012b(i, 1, 2, &me_emlrtBCI, &b_st);
        }
        if (this->Prior[i - 1] == 0.0) {
          if (ii + 1 > indsToExclude_size) {
            emlrtDynamicBoundsCheckR2012b(ii + 1, 1, indsToExclude_size,
                                          &ne_emlrtBCI, &b_st);
          }
          b_indsToExclude_data[ii] = true;
        }
      }
    }
  }
  b_st.site = &dh_emlrtRSI;
  C_size_idx_0 = Yout->size[0];
  n = Yout->size[0] << 1;
  if (n - 1 >= 0) {
    memset(&SD->u1.f1.C_data[0], 0, n * sizeof(boolean_T));
  }
  i = Yout->size[0];
  for (ii = 0; ii < i; ii++) {
    if (ii + 1 > indsToExclude_size) {
      emlrtDynamicBoundsCheckR2012b(ii + 1, 1, indsToExclude_size, &oe_emlrtBCI,
                                    &b_st);
    }
    if (!b_indsToExclude_data[ii]) {
      if (ii + 1 > C_size_idx_0) {
        emlrtDynamicBoundsCheckR2012b(ii + 1, 1, C_size_idx_0, &pe_emlrtBCI,
                                      &b_st);
      }
      if (ii + 1 > Yout->size[0]) {
        emlrtDynamicBoundsCheckR2012b(ii + 1, 1, Yout->size[0], &re_emlrtBCI,
                                      &b_st);
      }
      n = Yout_data[ii];
      if ((n < 1) || (n > 2)) {
        emlrtDynamicBoundsCheckR2012b(n, 1, 2, &qe_emlrtBCI, &b_st);
      }
      SD->u1.f1.C_data[ii + C_size_idx_0 * (n - 1)] = true;
    }
  }
  b_st.site = &eh_emlrtRSI;
  for (ii = 0; ii < indsToExclude_size; ii++) {
    if (ii + 1 > indsToExclude_size) {
      emlrtDynamicBoundsCheckR2012b(ii + 1, 1, indsToExclude_size, &kg_emlrtBCI,
                                    &st);
    }
    if (!b_indsToExclude_data[ii]) {
      if (ii + 1 > Yout->size[0]) {
        emlrtDynamicBoundsCheckR2012b(ii + 1, 1, Yout->size[0], &lg_emlrtBCI,
                                      &st);
      }
      if (Yout_data[ii] == 1) {
        if (ii + 1 > Yout->size[0]) {
          emlrtDynamicBoundsCheckR2012b(ii + 1, 1, Yout->size[0], &ng_emlrtBCI,
                                        &st);
        }
        Yout_data[ii] = -1;
      } else {
        if (ii + 1 > Yout->size[0]) {
          emlrtDynamicBoundsCheckR2012b(ii + 1, 1, Yout->size[0], &mg_emlrtBCI,
                                        &st);
        }
        Yout_data[ii] = 1;
      }
    }
  }
  b_st.site = &fh_emlrtRSI;
  c_st.site = &gh_emlrtRSI;
  WC_size_idx_0_tmp = (int16_T)C_size_idx_0;
  n = (int16_T)C_size_idx_0 << 1;
  if (n - 1 >= 0) {
    memset(&WC_data[0], 0, n * sizeof(int8_T));
  }
  batchWeightsPerClass_idx_0 = 0.0;
  batchWeightsPerClass_idx_1 = 0.0;
  for (ii = 0; ii < WC_size_idx_0_tmp; ii++) {
    if (ii + 1 > indsToExclude_size) {
      emlrtDynamicBoundsCheckR2012b(ii + 1, 1, indsToExclude_size, &og_emlrtBCI,
                                    &c_st);
    }
    if (!b_indsToExclude_data[ii]) {
      i = W->size[0];
      if (ii + 1 > i) {
        emlrtDynamicBoundsCheckR2012b(ii + 1, 1, i, &ig_emlrtBCI, &c_st);
      }
      if (ii + 1 > C_size_idx_0) {
        emlrtDynamicBoundsCheckR2012b(ii + 1, 1, C_size_idx_0, &jg_emlrtBCI,
                                      &c_st);
      }
      if (ii + 1 > (int16_T)C_size_idx_0) {
        emlrtDynamicBoundsCheckR2012b(ii + 1, 1, (int16_T)C_size_idx_0,
                                      &hg_emlrtBCI, &c_st);
      }
      WC_data[ii] = (int8_T)SD->u1.f1.C_data[ii];
      n = ii + (int16_T)C_size_idx_0;
      WC_data[n] = (int8_T)SD->u1.f1.C_data[ii + C_size_idx_0];
      if (ii + 1 > (int16_T)C_size_idx_0) {
        emlrtDynamicBoundsCheckR2012b(ii + 1, 1, (int16_T)C_size_idx_0,
                                      &gg_emlrtBCI, &c_st);
      }
      batchWeightsPerClass_idx_0 += (real_T)WC_data[ii];
      batchWeightsPerClass_idx_1 += (real_T)WC_data[n];
    }
  }
  this->WeightsPerClass[0] += batchWeightsPerClass_idx_0;
  this->WeightsPerClass[1] += batchWeightsPerClass_idx_1;
  batchWeightsPerClass_idx_0 = sumColumnB(this->WeightsPerClass);
  if (batchWeightsPerClass_idx_0 > 0.0) {
    this->Prior[0] = this->WeightsPerClass[0] / batchWeightsPerClass_idx_0;
    this->Prior[1] = this->WeightsPerClass[1] / batchWeightsPerClass_idx_0;
  }
  if (!this->PriorDefined) {
    boolean_T exitg1;
    boolean_T priorisNegative;
    priorisNegative = false;
    ii = 0;
    exitg1 = false;
    while ((!exitg1) && (ii < 2)) {
      if (this->Prior[ii] < 0.0) {
        priorisNegative = true;
        exitg1 = true;
      } else {
        ii++;
      }
    }
    if (!priorisNegative) {
      this->PriorDefined = true;
    }
  }
}

/* End of code generation (incrementalClassificationLinear.c) */
