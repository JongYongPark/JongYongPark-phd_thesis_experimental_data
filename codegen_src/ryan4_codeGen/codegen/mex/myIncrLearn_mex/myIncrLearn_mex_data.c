/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * myIncrLearn_mex_data.c
 *
 * Code generation for function 'myIncrLearn_mex_data'
 *
 */

/* Include files */
#include "myIncrLearn_mex_data.h"
#include "rt_nonfinite.h"

/* Variable Definitions */
emlrtCTX emlrtRootTLSGlobal = NULL;

const volatile char_T *emlrtBreakCheckR2012bFlagVar = NULL;

emlrtContext emlrtContextGlobal = {
    true,                                                 /* bFirstTime */
    false,                                                /* bInitialized */
    131626U,                                              /* fVersionInfo */
    NULL,                                                 /* fErrorFunction */
    "myIncrLearn_mex",                                    /* fFunctionName */
    NULL,                                                 /* fRTCallStack */
    false,                                                /* bDebugMode */
    {2045744189U, 2170104910U, 2743257031U, 4284093946U}, /* fSigWrd */
    NULL                                                  /* fSigMem */
};

emlrtRSInfo e_emlrtRSI = {
    253,                                                   /* lineNo */
    "incrementalClassificationLinear/validateAndFillData", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\stats\\incremental\\+incremental\\+"
    "coder\\incrementalClassificationLinear.m" /* pathName */
};

emlrtRSInfo x_emlrtRSI = {
    20,                               /* lineNo */
    "eml_int_forloop_overflow_check", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\eml\\lib\\matlab\\eml\\eml_int_forloop_"
    "overflow_check.m" /* pathName */
};

emlrtRSInfo db_emlrtRSI = {
    23,             /* lineNo */
    "cellstr_sort", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\matlab\\datatypes\\shared\\codegen\\+"
    "matlab\\+internal\\+coder\\+datatypes\\cellstr_sort.m" /* pathName */
};

emlrtRSInfo gb_emlrtRSI = {
    63,                               /* lineNo */
    "function_handle/parenReference", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\eml\\eml\\+coder\\+internal\\function_"
    "handle.m" /* pathName */
};

emlrtRSInfo hb_emlrtRSI = {
    23,                               /* lineNo */
    "@(i,j)sortidxCmp(i,j,c,cmpFun)", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\matlab\\datatypes\\shared\\codegen\\+"
    "matlab\\+internal\\+coder\\+datatypes\\cellstr_sort.m" /* pathName */
};

emlrtRSInfo jb_emlrtRSI = {
    11,             /* lineNo */
    "cellstr_diff", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\matlab\\datatypes\\shared\\codegen\\+"
    "matlab\\+internal\\+coder\\+datatypes\\cellstr_diff.m" /* pathName */
};

emlrtRSInfo sb_emlrtRSI = {
    17,               /* lineNo */
    "cellstr_unique", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\matlab\\datatypes\\shared\\codegen\\+"
    "matlab\\+internal\\+coder\\+datatypes\\cellstr_unique.m" /* pathName */
};

emlrtRSInfo tb_emlrtRSI = {
    20,               /* lineNo */
    "cellstr_unique", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\matlab\\datatypes\\shared\\codegen\\+"
    "matlab\\+internal\\+coder\\+datatypes\\cellstr_unique.m" /* pathName */
};

emlrtRSInfo ub_emlrtRSI = {
    30,               /* lineNo */
    "cellstr_unique", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\matlab\\datatypes\\shared\\codegen\\+"
    "matlab\\+internal\\+coder\\+datatypes\\cellstr_unique.m" /* pathName */
};

emlrtRSInfo vb_emlrtRSI = {
    37,               /* lineNo */
    "cellstr_unique", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\matlab\\datatypes\\shared\\codegen\\+"
    "matlab\\+internal\\+coder\\+datatypes\\cellstr_unique.m" /* pathName */
};

emlrtRSInfo wb_emlrtRSI = {
    39,               /* lineNo */
    "cellstr_unique", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\matlab\\datatypes\\shared\\codegen\\+"
    "matlab\\+internal\\+coder\\+datatypes\\cellstr_unique.m" /* pathName */
};

emlrtRSInfo xb_emlrtRSI = {
    39,     /* lineNo */
    "find", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\eml\\lib\\matlab\\elmat\\find.m" /* pathName
                                                                       */
};

emlrtRSInfo cc_emlrtRSI =
    {
        28,      /* lineNo */
        "colon", /* fcnName */
        "C:\\Program "
        "Files\\MATLAB\\R2022a\\toolbox\\eml\\lib\\matlab\\ops\\colon.m" /* pathName
                                                                          */
};

emlrtRSInfo dc_emlrtRSI = {
    15,    /* lineNo */
    "min", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\eml\\lib\\matlab\\datafun\\min.m" /* pathName
                                                                        */
};

emlrtRSInfo ec_emlrtRSI =
    {
        46,         /* lineNo */
        "minOrMax", /* fcnName */
        "C:\\Program "
        "Files\\MATLAB\\R2022a\\toolbox\\eml\\eml\\+coder\\+internal\\minOrMax."
        "m" /* pathName */
};

emlrtRSInfo fc_emlrtRSI =
    {
        92,        /* lineNo */
        "minimum", /* fcnName */
        "C:\\Program "
        "Files\\MATLAB\\R2022a\\toolbox\\eml\\eml\\+coder\\+internal\\minOrMax."
        "m" /* pathName */
};

emlrtRSInfo gc_emlrtRSI = {
    13,                    /* lineNo */
    "categorical/cellstr", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\matlab\\datatypes\\codegen\\categorical\\+"
    "matlab\\+internal\\+coder\\@categorical\\cellstr.m" /* pathName */
};

emlrtBCInfo h_emlrtBCI = {
    0,                        /* iFirst */
    2,                        /* iLast */
    51,                       /* lineNo */
    17,                       /* colNo */
    "",                       /* aName */
    "cellstr_parenReference", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\matlab\\datatypes\\shared\\codegen\\+"
    "matlab\\+internal\\+coder\\+datatypes\\cellstr_parenReferenc"
    "e.m", /* pName */
    0      /* checkKind */
};

emlrtBCInfo n_emlrtBCI = {
    -1,               /* iFirst */
    -1,               /* iLast */
    37,               /* lineNo */
    35,               /* colNo */
    "",               /* aName */
    "cellstr_unique", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\matlab\\datatypes\\shared\\codegen\\+"
    "matlab\\+internal\\+coder\\+datatypes\\cellstr_unique.m", /* pName */
    0                                                          /* checkKind */
};

emlrtBCInfo o_emlrtBCI = {
    -1,               /* iFirst */
    -1,               /* iLast */
    37,               /* lineNo */
    44,               /* colNo */
    "",               /* aName */
    "cellstr_unique", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\matlab\\datatypes\\shared\\codegen\\+"
    "matlab\\+internal\\+coder\\+datatypes\\cellstr_unique.m", /* pName */
    0                                                          /* checkKind */
};

emlrtBCInfo p_emlrtBCI = {
    -1,               /* iFirst */
    -1,               /* iLast */
    39,               /* lineNo */
    35,               /* colNo */
    "",               /* aName */
    "cellstr_unique", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\matlab\\datatypes\\shared\\codegen\\+"
    "matlab\\+internal\\+coder\\+datatypes\\cellstr_unique.m", /* pName */
    0                                                          /* checkKind */
};

emlrtRTEInfo e_emlrtRTEI = {
    135,             /* lineNo */
    27,              /* colNo */
    "unaryMinOrMax", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\unaryMinOrMax.m" /* pName */
};

emlrtBCInfo s_emlrtBCI = {
    -1,               /* iFirst */
    -1,               /* iLast */
    59,               /* lineNo */
    11,               /* colNo */
    "",               /* aName */
    "cellstr_unique", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\matlab\\datatypes\\shared\\codegen\\+"
    "matlab\\+internal\\+coder\\+datatypes\\cellstr_unique.m", /* pName */
    0                                                          /* checkKind */
};

emlrtBCInfo t_emlrtBCI = {
    -1,               /* iFirst */
    -1,               /* iLast */
    59,               /* lineNo */
    21,               /* colNo */
    "",               /* aName */
    "cellstr_unique", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\matlab\\datatypes\\shared\\codegen\\+"
    "matlab\\+internal\\+coder\\+datatypes\\cellstr_unique.m", /* pName */
    0                                                          /* checkKind */
};

emlrtDCInfo emlrtDCI = {
    37,               /* lineNo */
    30,               /* colNo */
    "cellstr_unique", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\matlab\\datatypes\\shared\\codegen\\+"
    "matlab\\+internal\\+coder\\+datatypes\\cellstr_unique.m", /* pName */
    1                                                          /* checkKind */
};

emlrtBCInfo v_emlrtBCI = {
    -1,               /* iFirst */
    -1,               /* iLast */
    37,               /* lineNo */
    16,               /* colNo */
    "",               /* aName */
    "cellstr_unique", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\matlab\\datatypes\\shared\\codegen\\+"
    "matlab\\+internal\\+coder\\+datatypes\\cellstr_unique.m", /* pName */
    0                                                          /* checkKind */
};

emlrtBCInfo x_emlrtBCI = {
    -1,               /* iFirst */
    -1,               /* iLast */
    59,               /* lineNo */
    16,               /* colNo */
    "",               /* aName */
    "cellstr_unique", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\matlab\\datatypes\\shared\\codegen\\+"
    "matlab\\+internal\\+coder\\+datatypes\\cellstr_unique.m", /* pName */
    0                                                          /* checkKind */
};

emlrtBCInfo y_emlrtBCI = {
    -1,               /* iFirst */
    -1,               /* iLast */
    59,               /* lineNo */
    9,                /* colNo */
    "",               /* aName */
    "cellstr_unique", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\matlab\\datatypes\\shared\\codegen\\+"
    "matlab\\+internal\\+coder\\+datatypes\\cellstr_unique.m", /* pName */
    0                                                          /* checkKind */
};

emlrtBCInfo ab_emlrtBCI = {
    -1,               /* iFirst */
    -1,               /* iLast */
    39,               /* lineNo */
    16,               /* colNo */
    "",               /* aName */
    "cellstr_unique", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\matlab\\datatypes\\shared\\codegen\\+"
    "matlab\\+internal\\+coder\\+datatypes\\cellstr_unique.m", /* pName */
    0                                                          /* checkKind */
};

emlrtBCInfo kc_emlrtBCI = {
    -1,           /* iFirst */
    -1,           /* iLast */
    40,           /* lineNo */
    17,           /* colNo */
    "",           /* aName */
    "sortidxCmp", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\matlab\\datatypes\\shared\\codegen\\+"
    "matlab\\+internal\\+coder\\+datatypes\\cellstr_sort.m", /* pName */
    0                                                        /* checkKind */
};

emlrtBCInfo lc_emlrtBCI = {
    -1,           /* iFirst */
    -1,           /* iLast */
    41,           /* lineNo */
    17,           /* colNo */
    "",           /* aName */
    "sortidxCmp", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\matlab\\datatypes\\shared\\codegen\\+"
    "matlab\\+internal\\+coder\\+datatypes\\cellstr_sort.m", /* pName */
    0                                                        /* checkKind */
};

emlrtRTEInfo m_emlrtRTEI = {
    646,                           /* lineNo */
    13,                            /* colNo */
    "Learner/validateAndFillData", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\stats\\incremental\\+incremental\\+"
    "coder\\Learner.m" /* pName */
};

emlrtBCInfo ke_emlrtBCI = {
    -1,                                    /* iFirst */
    -1,                                    /* iLast */
    566,                                   /* lineNo */
    32,                                    /* colNo */
    "",                                    /* aName */
    "ClassificationModel/filterZeroPrior", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\stats\\incremental\\+incremental\\+"
    "coder\\+classif\\ClassificationModel.m", /* pName */
    0                                         /* checkKind */
};

emlrtBCInfo le_emlrtBCI = {
    -1,                                    /* iFirst */
    -1,                                    /* iLast */
    565,                                   /* lineNo */
    35,                                    /* colNo */
    "",                                    /* aName */
    "ClassificationModel/filterZeroPrior", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\stats\\incremental\\+incremental\\+"
    "coder\\+classif\\ClassificationModel.m", /* pName */
    0                                         /* checkKind */
};

emlrtBCInfo me_emlrtBCI = {
    1,                                     /* iFirst */
    2,                                     /* iLast */
    567,                                   /* lineNo */
    35,                                    /* colNo */
    "",                                    /* aName */
    "ClassificationModel/filterZeroPrior", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\stats\\incremental\\+incremental\\+"
    "coder\\+classif\\ClassificationModel.m", /* pName */
    0                                         /* checkKind */
};

emlrtBCInfo ne_emlrtBCI = {
    -1,                                    /* iFirst */
    -1,                                    /* iLast */
    568,                                   /* lineNo */
    39,                                    /* colNo */
    "",                                    /* aName */
    "ClassificationModel/filterZeroPrior", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\stats\\incremental\\+incremental\\+"
    "coder\\+classif\\ClassificationModel.m", /* pName */
    0                                         /* checkKind */
};

emlrtBCInfo oe_emlrtBCI = {
    -1,                               /* iFirst */
    -1,                               /* iLast */
    256,                              /* lineNo */
    35,                               /* colNo */
    "",                               /* aName */
    "ClassificationModel/classCount", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\stats\\incremental\\+incremental\\+"
    "coder\\+classif\\ClassificationModel.m", /* pName */
    0                                         /* checkKind */
};

emlrtBCInfo pe_emlrtBCI = {
    -1,                               /* iFirst */
    -1,                               /* iLast */
    257,                              /* lineNo */
    23,                               /* colNo */
    "",                               /* aName */
    "ClassificationModel/classCount", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\stats\\incremental\\+incremental\\+"
    "coder\\+classif\\ClassificationModel.m", /* pName */
    0                                         /* checkKind */
};

emlrtBCInfo qe_emlrtBCI = {
    1,                                /* iFirst */
    2,                                /* iLast */
    257,                              /* lineNo */
    26,                               /* colNo */
    "",                               /* aName */
    "ClassificationModel/classCount", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\stats\\incremental\\+incremental\\+"
    "coder\\+classif\\ClassificationModel.m", /* pName */
    3                                         /* checkKind */
};

emlrtBCInfo re_emlrtBCI = {
    -1,                               /* iFirst */
    -1,                               /* iLast */
    257,                              /* lineNo */
    28,                               /* colNo */
    "",                               /* aName */
    "ClassificationModel/classCount", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\stats\\incremental\\+incremental\\+"
    "coder\\+classif\\ClassificationModel.m", /* pName */
    0                                         /* checkKind */
};

emlrtRTEInfo y_emlrtRTEI = {
    8,         /* lineNo */
    1,         /* colNo */
    "cellstr", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\matlab\\datatypes\\codegen\\categorical\\+"
    "matlab\\+internal\\+coder\\@categorical\\cellstr.m" /* pName */
};

emlrtRTEInfo ab_emlrtRTEI = {
    10,        /* lineNo */
    5,         /* colNo */
    "cellstr", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\matlab\\datatypes\\codegen\\categorical\\+"
    "matlab\\+internal\\+coder\\@categorical\\cellstr.m" /* pName */
};

emlrtRTEInfo bb_emlrtRTEI =
    {
        28,      /* lineNo */
        9,       /* colNo */
        "colon", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2022a\\toolbox\\eml\\lib\\matlab\\ops\\colon.m" /* pName
                                                                          */
};

emlrtRTEInfo gb_emlrtRTEI = {
    7,         /* lineNo */
    1,         /* colNo */
    "cellstr", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\matlab\\datatypes\\codegen\\categorical\\+"
    "matlab\\+internal\\+coder\\@categorical\\cellstr.m" /* pName */
};

emlrtRTEInfo ib_emlrtRTEI = {
    28,               /* lineNo */
    50,               /* colNo */
    "cellstr_unique", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\matlab\\datatypes\\shared\\codegen\\+"
    "matlab\\+internal\\+coder\\+datatypes\\cellstr_unique.m" /* pName */
};

emlrtRTEInfo kb_emlrtRTEI = {
    59,               /* lineNo */
    9,                /* colNo */
    "cellstr_unique", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\matlab\\datatypes\\shared\\codegen\\+"
    "matlab\\+internal\\+coder\\+datatypes\\cellstr_unique.m" /* pName */
};

emlrtRTEInfo ac_emlrtRTEI = {
    31,     /* lineNo */
    6,      /* colNo */
    "find", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\eml\\lib\\matlab\\elmat\\find.m" /* pName
                                                                       */
};

const char_T cv[11] = {'<', 'u', 'n', 'd', 'e', 'f', 'i', 'n', 'e', 'd', '>'};

/* End of code generation (myIncrLearn_mex_data.c) */
