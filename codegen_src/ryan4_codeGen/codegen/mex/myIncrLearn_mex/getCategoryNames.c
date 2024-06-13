/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * getCategoryNames.c
 *
 * Code generation for function 'getCategoryNames'
 *
 */

/* Include files */
#include "getCategoryNames.h"
#include "any.h"
#include "myIncrLearn_mex_data.h"
#include "myIncrLearn_mex_emxutil.h"
#include "myIncrLearn_mex_types.h"
#include "rt_nonfinite.h"
#include <string.h>

/* Variable Definitions */
static emlrtBCInfo oc_emlrtBCI = {
    -1,                             /* iFirst */
    -1,                             /* iLast */
    104,                            /* lineNo */
    17,                             /* colNo */
    "",                             /* aName */
    "categorical/getCategoryNames", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\matlab\\datatypes\\codegen\\categorical\\+"
    "matlab\\+internal\\+coder\\@categorical\\getCategoryNam"
    "es.m", /* pName */
    0       /* checkKind */
};

static emlrtBCInfo pc_emlrtBCI = {
    -1,                             /* iFirst */
    -1,                             /* iLast */
    104,                            /* lineNo */
    39,                             /* colNo */
    "",                             /* aName */
    "categorical/getCategoryNames", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\matlab\\datatypes\\codegen\\categorical\\+"
    "matlab\\+internal\\+coder\\@categorical\\getCategoryNam"
    "es.m", /* pName */
    0       /* checkKind */
};

static emlrtBCInfo qc_emlrtBCI = {
    -1,                             /* iFirst */
    -1,                             /* iLast */
    102,                            /* lineNo */
    40,                             /* colNo */
    "",                             /* aName */
    "categorical/getCategoryNames", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\matlab\\datatypes\\codegen\\categorical\\+"
    "matlab\\+internal\\+coder\\@categorical\\getCategoryNam"
    "es.m", /* pName */
    0       /* checkKind */
};

static emlrtBCInfo rc_emlrtBCI = {
    -1,                             /* iFirst */
    -1,                             /* iLast */
    97,                             /* lineNo */
    22,                             /* colNo */
    "",                             /* aName */
    "categorical/getCategoryNames", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\matlab\\datatypes\\codegen\\categorical\\+"
    "matlab\\+internal\\+coder\\@categorical\\getCategoryNam"
    "es.m", /* pName */
    0       /* checkKind */
};

static emlrtBCInfo sc_emlrtBCI = {
    -1,                             /* iFirst */
    -1,                             /* iLast */
    104,                            /* lineNo */
    34,                             /* colNo */
    "",                             /* aName */
    "categorical/getCategoryNames", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\matlab\\datatypes\\codegen\\categorical\\+"
    "matlab\\+internal\\+coder\\@categorical\\getCategoryNam"
    "es.m", /* pName */
    0       /* checkKind */
};

static emlrtBCInfo tc_emlrtBCI = {
    -1,                             /* iFirst */
    -1,                             /* iLast */
    104,                            /* lineNo */
    48,                             /* colNo */
    "",                             /* aName */
    "categorical/getCategoryNames", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\matlab\\datatypes\\codegen\\categorical\\+"
    "matlab\\+internal\\+coder\\@categorical\\getCategoryNam"
    "es.m", /* pName */
    0       /* checkKind */
};

static emlrtBCInfo uc_emlrtBCI = {
    -1,                             /* iFirst */
    -1,                             /* iLast */
    97,                             /* lineNo */
    41,                             /* colNo */
    "",                             /* aName */
    "categorical/getCategoryNames", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\matlab\\datatypes\\codegen\\categorical\\+"
    "matlab\\+internal\\+coder\\@categorical\\getCategoryNam"
    "es.m", /* pName */
    0       /* checkKind */
};

static emlrtRTEInfo h_emlrtRTEI = {
    100,                            /* lineNo */
    35,                             /* colNo */
    "categorical/getCategoryNames", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\matlab\\datatypes\\codegen\\categorical\\+"
    "matlab\\+internal\\+coder\\@categorical\\getCategoryNam"
    "es.m" /* pName */
};

static emlrtRTEInfo i_emlrtRTEI = {
    91,                             /* lineNo */
    35,                             /* colNo */
    "categorical/getCategoryNames", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\matlab\\datatypes\\codegen\\categorical\\+"
    "matlab\\+internal\\+coder\\@categorical\\getCategoryNam"
    "es.m" /* pName */
};

static emlrtRTEInfo j_emlrtRTEI = {
    90,                             /* lineNo */
    80,                             /* colNo */
    "categorical/getCategoryNames", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\matlab\\datatypes\\codegen\\categorical\\+"
    "matlab\\+internal\\+coder\\@categorical\\getCategoryNam"
    "es.m" /* pName */
};

static emlrtRTEInfo k_emlrtRTEI = {
    89,                             /* lineNo */
    79,                             /* colNo */
    "categorical/getCategoryNames", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\matlab\\datatypes\\codegen\\categorical\\+"
    "matlab\\+internal\\+coder\\@categorical\\getCategoryNam"
    "es.m" /* pName */
};

static emlrtRTEInfo dc_emlrtRTEI = {
    1,                  /* lineNo */
    29,                 /* colNo */
    "getCategoryNames", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\matlab\\datatypes\\codegen\\categorical\\+"
    "matlab\\+internal\\+coder\\@categorical\\getCategoryNam"
    "es.m" /* pName */
};

static emlrtRTEInfo ec_emlrtRTEI = {
    102,                /* lineNo */
    40,                 /* colNo */
    "getCategoryNames", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\matlab\\datatypes\\codegen\\categorical\\+"
    "matlab\\+internal\\+coder\\@categorical\\getCategoryNam"
    "es.m" /* pName */
};

static emlrtRTEInfo fc_emlrtRTEI = {
    104,                /* lineNo */
    17,                 /* colNo */
    "getCategoryNames", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\matlab\\datatypes\\codegen\\categorical\\+"
    "matlab\\+internal\\+coder\\@categorical\\getCategoryNam"
    "es.m" /* pName */
};

/* Function Definitions */
void categorical_getCategoryNames(const emlrtStack *sp,
                                  const emxArray_cell_wrap_1 *valueSet,
                                  emxArray_cell_wrap_1 *outCategoryNames)
{
  static const char_T b_cv[9] = {'<', 'm', 'i', 's', 's', 'i', 'n', 'g', '>'};
  const cell_wrap_1 *valueSet_data;
  cell_wrap_1 *outCategoryNames_data;
  int32_T i;
  int32_T k;
  int32_T kstr;
  int8_T mask_data[24075];
  valueSet_data = valueSet->data;
  if (valueSet->size[0] != 0) {
    int32_T bool_size;
    int32_T exitg1;
    int32_T nb;
    int16_T unnamed_idx_0;
    boolean_T bool_data[24075];
    boolean_T exitg2;
    boolean_T x;
    bool_size = valueSet->size[0];
    nb = valueSet->size[0];
    for (k = 0; k < nb; k++) {
      bool_data[k] = false;
      if (valueSet_data[k].f1->size[1] == 11) {
        kstr = 0;
        do {
          exitg1 = 0;
          if (kstr < 11) {
            if (cv[kstr] != valueSet_data[k].f1->data[kstr]) {
              exitg1 = 1;
            } else {
              kstr++;
            }
          } else {
            bool_data[k] = true;
            exitg1 = 1;
          }
        } while (exitg1 == 0);
      }
    }
    x = any(bool_data, bool_size);
    if (x) {
      emlrtErrorWithMessageIdR2018a(
          sp, &k_emlrtRTEI, "MATLAB:categorical:UndefinedLabelCategoryName",
          "MATLAB:categorical:UndefinedLabelCategoryName", 3, 4, 11,
          "<undefined>");
    }
    bool_size = valueSet->size[0];
    nb = valueSet->size[0];
    for (k = 0; k < nb; k++) {
      bool_data[k] = false;
      if (valueSet_data[k].f1->size[1] == 9) {
        kstr = 0;
        do {
          exitg1 = 0;
          if (kstr < 9) {
            if (b_cv[kstr] != valueSet_data[k].f1->data[kstr]) {
              exitg1 = 1;
            } else {
              kstr++;
            }
          } else {
            bool_data[k] = true;
            exitg1 = 1;
          }
        } while (exitg1 == 0);
      }
    }
    x = any(bool_data, bool_size);
    if (x) {
      emlrtErrorWithMessageIdR2018a(
          sp, &j_emlrtRTEI, "MATLAB:categorical:UndefinedLabelCategoryName",
          "MATLAB:categorical:UndefinedLabelCategoryName", 3, 4, 9,
          "<missing>");
    }
    bool_size = valueSet->size[0];
    nb = valueSet->size[0];
    for (k = 0; k < nb; k++) {
      bool_data[k] = false;
      if (valueSet_data[k].f1->size[1] == 0) {
        bool_data[k] = true;
      } else if (valueSet_data[k].f1->size[1] == 0) {
        bool_data[k] = true;
      }
    }
    x = any(bool_data, bool_size);
    if (x) {
      emlrtErrorWithMessageIdR2018a(sp, &i_emlrtRTEI,
                                    "MATLAB:categorical:EmptyCategoryName",
                                    "MATLAB:categorical:EmptyCategoryName", 0);
    }
    nb = valueSet->size[0];
    bool_size = valueSet->size[0];
    memset(&mask_data[0], 0, bool_size * sizeof(int8_T));
    i = valueSet->size[0];
    for (k = 0; k < i; k++) {
      if (k > valueSet->size[0] - 1) {
        emlrtDynamicBoundsCheckR2012b(k, 0, valueSet->size[0] - 1, &uc_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      if (k + 1 > nb) {
        emlrtDynamicBoundsCheckR2012b(k + 1, 1, nb, &rc_emlrtBCI, (emlrtCTX)sp);
      }
      mask_data[k] = 1;
    }
    for (i = 0; i < nb; i++) {
      bool_data[i] = (mask_data[i] == 1);
    }
    x = true;
    bool_size = 1;
    exitg2 = false;
    while ((!exitg2) && (bool_size <= nb)) {
      if (!bool_data[bool_size - 1]) {
        x = false;
        exitg2 = true;
      } else {
        bool_size++;
      }
    }
    if (!x) {
      emlrtErrorWithMessageIdR2018a(
          sp, &h_emlrtRTEI, "MATLAB:categorical:CantCreateCategoryNames",
          "MATLAB:categorical:CantCreateCategoryNames", 0);
    }
    unnamed_idx_0 = (int16_T)valueSet->size[0];
    i = outCategoryNames->size[0];
    outCategoryNames->size[0] = valueSet->size[0];
    emxEnsureCapacity_cell_wrap_12(sp, outCategoryNames, i, &dc_emlrtRTEI);
    outCategoryNames_data = outCategoryNames->data;
    for (i = 0; i < unnamed_idx_0; i++) {
      bool_size = outCategoryNames->size[0] - 1;
      if (i > outCategoryNames->size[0] - 1) {
        emlrtDynamicBoundsCheckR2012b(i, 0, outCategoryNames->size[0] - 1,
                                      &qc_emlrtBCI, (emlrtCTX)sp);
      }
      nb = outCategoryNames_data[i].f1->size[0] *
           outCategoryNames_data[i].f1->size[1];
      outCategoryNames_data[i].f1->size[0] = 1;
      emxEnsureCapacity_char_T(sp, outCategoryNames_data[i].f1, nb,
                               &dc_emlrtRTEI);
      if (i > bool_size) {
        emlrtDynamicBoundsCheckR2012b(i, 0, bool_size, &qc_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      outCategoryNames_data[i].f1->size[1] = 0;
    }
    i = valueSet->size[0];
    nb = outCategoryNames->size[0];
    outCategoryNames->size[0] = valueSet->size[0];
    emxEnsureCapacity_cell_wrap_12(sp, outCategoryNames, nb, &ec_emlrtRTEI);
    outCategoryNames_data = outCategoryNames->data;
    for (kstr = 0; kstr < i; kstr++) {
      if (kstr > valueSet->size[0] - 1) {
        emlrtDynamicBoundsCheckR2012b(kstr, 0, valueSet->size[0] - 1,
                                      &tc_emlrtBCI, (emlrtCTX)sp);
      }
      bool_size = valueSet_data[kstr].f1->size[1] - 1;
      if (kstr > outCategoryNames->size[0] - 1) {
        emlrtDynamicBoundsCheckR2012b(kstr, 0, outCategoryNames->size[0] - 1,
                                      &sc_emlrtBCI, (emlrtCTX)sp);
      }
      nb = outCategoryNames_data[kstr].f1->size[0] *
           outCategoryNames_data[kstr].f1->size[1];
      outCategoryNames_data[kstr].f1->size[0] = 1;
      emxEnsureCapacity_char_T(sp, outCategoryNames_data[kstr].f1, nb,
                               &fc_emlrtRTEI);
      if (kstr > valueSet->size[0] - 1) {
        emlrtDynamicBoundsCheckR2012b(kstr, 0, valueSet->size[0] - 1,
                                      &tc_emlrtBCI, (emlrtCTX)sp);
      }
      if (kstr > outCategoryNames->size[0] - 1) {
        emlrtDynamicBoundsCheckR2012b(kstr, 0, outCategoryNames->size[0] - 1,
                                      &sc_emlrtBCI, (emlrtCTX)sp);
      }
      nb = outCategoryNames_data[kstr].f1->size[0] *
           outCategoryNames_data[kstr].f1->size[1];
      outCategoryNames_data[kstr].f1->size[1] = valueSet_data[kstr].f1->size[1];
      emxEnsureCapacity_char_T(sp, outCategoryNames_data[kstr].f1, nb,
                               &fc_emlrtRTEI);
      nb = outCategoryNames->size[0];
      if (kstr > outCategoryNames->size[0] - 1) {
        emlrtDynamicBoundsCheckR2012b(kstr, 0, outCategoryNames->size[0] - 1,
                                      &sc_emlrtBCI, (emlrtCTX)sp);
      }
      for (k = 0; k <= bool_size; k++) {
        if (kstr > nb - 1) {
          emlrtDynamicBoundsCheckR2012b(kstr, 0, nb - 1, &oc_emlrtBCI,
                                        (emlrtCTX)sp);
        }
        if (kstr > valueSet->size[0] - 1) {
          emlrtDynamicBoundsCheckR2012b(kstr, 0, valueSet->size[0] - 1,
                                        &pc_emlrtBCI, (emlrtCTX)sp);
        }
        outCategoryNames_data[kstr].f1->data[k] =
            valueSet_data[kstr].f1->data[k];
      }
    }
  } else {
    outCategoryNames->size[0] = 0;
  }
}

/* End of code generation (getCategoryNames.c) */
