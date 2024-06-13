/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * ClassificationModel.c
 *
 * Code generation for function 'ClassificationModel'
 *
 */

/* Include files */
#include "ClassificationModel.h"
#include "Linear.h"
#include "cellstr_ismember.h"
#include "incrementalClassificationLinear.h"
#include "myIncrLearn_mex_data.h"
#include "myIncrLearn_mex_emxutil.h"
#include "myIncrLearn_mex_types.h"
#include "rt_nonfinite.h"
#include "sumMatrixIncludeNaN.h"
#include "validateattributes.h"
#include "mwmathutil.h"
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo i_emlrtRSI = {
    266,                                                   /* lineNo */
    "ClassificationModel/adjustWeightAndCalculateMetrics", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\stats\\incremental\\+incremental\\+"
    "coder\\+classif\\ClassificationModel.m" /* pathName */
};

static emlrtRSInfo j_emlrtRSI = {
    279,                                                   /* lineNo */
    "ClassificationModel/adjustWeightAndCalculateMetrics", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\stats\\incremental\\+incremental\\+"
    "coder\\+classif\\ClassificationModel.m" /* pathName */
};

static emlrtRSInfo k_emlrtRSI = {
    372,                                         /* lineNo */
    "ClassificationModel/classifLossForMetrics", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\stats\\incremental\\+incremental\\+"
    "coder\\+classif\\ClassificationModel.m" /* pathName */
};

static emlrtRSInfo l_emlrtRSI = {
    373,                                         /* lineNo */
    "ClassificationModel/classifLossForMetrics", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\stats\\incremental\\+incremental\\+"
    "coder\\+classif\\ClassificationModel.m" /* pathName */
};

static emlrtRSInfo m_emlrtRSI = {
    374,                                         /* lineNo */
    "ClassificationModel/classifLossForMetrics", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\stats\\incremental\\+incremental\\+"
    "coder\\+classif\\ClassificationModel.m" /* pathName */
};

static emlrtRSInfo n_emlrtRSI = {
    375,                                         /* lineNo */
    "ClassificationModel/classifLossForMetrics", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\stats\\incremental\\+incremental\\+"
    "coder\\+classif\\ClassificationModel.m" /* pathName */
};

static emlrtRSInfo o_emlrtRSI = {
    377,                                         /* lineNo */
    "ClassificationModel/classifLossForMetrics", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\stats\\incremental\\+incremental\\+"
    "coder\\+classif\\ClassificationModel.m" /* pathName */
};

static emlrtRSInfo q_emlrtRSI = {
    390,                                         /* lineNo */
    "ClassificationModel/classifLossForMetrics", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\stats\\incremental\\+incremental\\+"
    "coder\\+classif\\ClassificationModel.m" /* pathName */
};

static emlrtRSInfo t_emlrtRSI = {
    452,                               /* lineNo */
    "ClassificationModel/prepareData", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\stats\\incremental\\+incremental\\+"
    "coder\\+classif\\ClassificationModel.m" /* pathName */
};

static emlrtRSInfo v_emlrtRSI = {
    498,                               /* lineNo */
    "ClassificationModel/prepareData", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\stats\\incremental\\+incremental\\+"
    "coder\\+classif\\ClassificationModel.m" /* pathName */
};

static emlrtRSInfo y_emlrtRSI = {
    208,                                    /* lineNo */
    "ClassificationModel/verifyClassNames", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\stats\\incremental\\+incremental\\+"
    "coder\\+classif\\ClassificationModel.m" /* pathName */
};

static emlrtRSInfo ab_emlrtRSI = {
    221,                                    /* lineNo */
    "ClassificationModel/verifyClassNames", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\stats\\incremental\\+incremental\\+"
    "coder\\+classif\\ClassificationModel.m" /* pathName */
};

static emlrtRSInfo bb_emlrtRSI = {
    239,                                    /* lineNo */
    "ClassificationModel/verifyClassNames", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\stats\\incremental\\+incremental\\+"
    "coder\\+classif\\ClassificationModel.m" /* pathName */
};

static emlrtRSInfo cb_emlrtRSI = {
    67,                    /* lineNo */
    "categorical/isequal", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\matlab\\datatypes\\codegen\\categorical\\+"
    "matlab\\+internal\\+coder\\@categorical\\isequal.m" /* pathName */
};

static emlrtRSInfo nb_emlrtRSI = {
    79,                         /* lineNo */
    "categorical/convertCodes", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\matlab\\datatypes\\codegen\\categorical\\+"
    "matlab\\+internal\\+coder\\@categorical\\convertCodes.m" /* pathName */
};

static emlrtRSInfo jc_emlrtRSI = {
    360,                                            /* lineNo */
    "ClassificationModel/predictWithoutValidation", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\stats\\incremental\\+incremental\\+"
    "coder\\+classif\\ClassificationModel.m" /* pathName */
};

static emlrtRSInfo kc_emlrtRSI = {
    361,                                            /* lineNo */
    "ClassificationModel/predictWithoutValidation", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\stats\\incremental\\+incremental\\+"
    "coder\\+classif\\ClassificationModel.m" /* pathName */
};

static emlrtRSInfo lc_emlrtRSI = {
    205,                                     /* lineNo */
    "incrementalClassificationLinear/score", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\stats\\incremental\\+incremental\\+"
    "coder\\incrementalClassificationLinear.m" /* pathName */
};

static emlrtRSInfo bf_emlrtRSI = {
    337,                                 /* lineNo */
    "ClassificationModel/adjustWeights", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\stats\\incremental\\+incremental\\+"
    "coder\\+classif\\ClassificationModel.m" /* pathName */
};

static emlrtRSInfo cf_emlrtRSI = {
    349,                                 /* lineNo */
    "ClassificationModel/adjustWeights", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\stats\\incremental\\+incremental\\+"
    "coder\\+classif\\ClassificationModel.m" /* pathName */
};

static emlrtRSInfo df_emlrtRSI = {
    350,                                 /* lineNo */
    "ClassificationModel/adjustWeights", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\stats\\incremental\\+incremental\\+"
    "coder\\+classif\\ClassificationModel.m" /* pathName */
};

static emlrtRSInfo ef_emlrtRSI = {
    20,    /* lineNo */
    "sum", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\eml\\lib\\matlab\\datafun\\sum.m" /* pathName
                                                                        */
};

static emlrtRSInfo ff_emlrtRSI = {
    99,        /* lineNo */
    "sumprod", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\sumpro"
    "d.m" /* pathName */
};

static emlrtRSInfo gf_emlrtRSI = {
    74,                      /* lineNo */
    "combineVectorElements", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\combin"
    "eVectorElements.m" /* pathName */
};

static emlrtRSInfo hf_emlrtRSI = {
    99,                 /* lineNo */
    "blockedSummation", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\blocke"
    "dSummation.m" /* pathName */
};

static emlrtRSInfo if_emlrtRSI = {
    22,                    /* lineNo */
    "sumMatrixIncludeNaN", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\eml\\lib\\matlab\\datafun\\private\\sumMat"
    "rixIncludeNaN.m" /* pathName */
};

static emlrtRSInfo nf_emlrtRSI = {
    681,                /* lineNo */
    "Learner/evaluate", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\stats\\incremental\\+incremental\\+"
    "coder\\Learner.m" /* pathName */
};

static emlrtRSInfo pf_emlrtRSI = {
    32,             /* lineNo */
    "classiferror", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\stats\\classreg\\+classreg\\+learning\\+"
    "coder\\+loss\\+unnormalized\\classiferror.m" /* pathName */
};

static emlrtRSInfo qf_emlrtRSI = {
    36,             /* lineNo */
    "classiferror", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\stats\\classreg\\+classreg\\+learning\\+"
    "coder\\+loss\\+unnormalized\\classiferror.m" /* pathName */
};

static emlrtRSInfo sf_emlrtRSI = {
    683,                /* lineNo */
    "Learner/evaluate", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\stats\\incremental\\+incremental\\+"
    "coder\\Learner.m" /* pathName */
};

static emlrtRSInfo uf_emlrtRSI = {
    28,      /* lineNo */
    "hinge", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\stats\\classreg\\+classreg\\+learning\\+"
    "coder\\+loss\\+unnormalized\\hinge.m" /* pathName */
};

static emlrtRSInfo vg_emlrtRSI = {
    171,                                                /* lineNo */
    "ClassificationModel/prepareRawDataAndUpdateState", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\stats\\incremental\\+incremental\\+"
    "coder\\+classif\\ClassificationModel.m" /* pathName */
};

static emlrtRSInfo wg_emlrtRSI = {
    172,                                                /* lineNo */
    "ClassificationModel/prepareRawDataAndUpdateState", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\stats\\incremental\\+incremental\\+"
    "coder\\+classif\\ClassificationModel.m" /* pathName */
};

static emlrtRSInfo xg_emlrtRSI = {
    173,                                                /* lineNo */
    "ClassificationModel/prepareRawDataAndUpdateState", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\stats\\incremental\\+incremental\\+"
    "coder\\+classif\\ClassificationModel.m" /* pathName */
};

static emlrtRSInfo yg_emlrtRSI = {
    503,                               /* lineNo */
    "ClassificationModel/prepareData", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\stats\\incremental\\+incremental\\+"
    "coder\\+classif\\ClassificationModel.m" /* pathName */
};

static emlrtBCInfo emlrtBCI = {
    -1,                         /* iFirst */
    -1,                         /* iLast */
    144,                        /* lineNo */
    19,                         /* colNo */
    "",                         /* aName */
    "categorical/convertCodes", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\matlab\\datatypes\\codegen\\categorical\\+"
    "matlab\\+internal\\+coder\\@categorical\\convertCodes.m", /* pName */
    0                                                          /* checkKind */
};

static emlrtBCInfo b_emlrtBCI = {
    -1,                         /* iFirst */
    -1,                         /* iLast */
    144,                        /* lineNo */
    35,                         /* colNo */
    "",                         /* aName */
    "categorical/convertCodes", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\matlab\\datatypes\\codegen\\categorical\\+"
    "matlab\\+internal\\+coder\\@categorical\\convertCodes.m", /* pName */
    0                                                          /* checkKind */
};

static emlrtBCInfo c_emlrtBCI = {
    -1,                         /* iFirst */
    -1,                         /* iLast */
    144,                        /* lineNo */
    45,                         /* colNo */
    "",                         /* aName */
    "categorical/convertCodes", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\matlab\\datatypes\\codegen\\categorical\\+"
    "matlab\\+internal\\+coder\\@categorical\\convertCodes.m", /* pName */
    0                                                          /* checkKind */
};

static emlrtBCInfo d_emlrtBCI = {
    1,                          /* iFirst */
    3,                          /* iLast */
    155,                        /* lineNo */
    29,                         /* colNo */
    "",                         /* aName */
    "categorical/convertCodes", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\matlab\\datatypes\\codegen\\categorical\\+"
    "matlab\\+internal\\+coder\\@categorical\\convertCodes.m", /* pName */
    0                                                          /* checkKind */
};

static emlrtBCInfo e_emlrtBCI = {
    -1,                                     /* iFirst */
    -1,                                     /* iLast */
    222,                                    /* lineNo */
    42,                                     /* colNo */
    "",                                     /* aName */
    "ClassificationModel/verifyClassNames", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\stats\\incremental\\+incremental\\+"
    "coder\\+classif\\ClassificationModel.m", /* pName */
    0                                         /* checkKind */
};

static emlrtBCInfo f_emlrtBCI = {
    -1,                                     /* iFirst */
    -1,                                     /* iLast */
    209,                                    /* lineNo */
    35,                                     /* colNo */
    "",                                     /* aName */
    "ClassificationModel/verifyClassNames", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\stats\\incremental\\+incremental\\+"
    "coder\\+classif\\ClassificationModel.m", /* pName */
    0                                         /* checkKind */
};

static emlrtBCInfo g_emlrtBCI = {
    -1,                         /* iFirst */
    -1,                         /* iLast */
    144,                        /* lineNo */
    29,                         /* colNo */
    "",                         /* aName */
    "categorical/convertCodes", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\matlab\\datatypes\\codegen\\categorical\\+"
    "matlab\\+internal\\+coder\\@categorical\\convertCodes.m", /* pName */
    0                                                          /* checkKind */
};

static emlrtECInfo emlrtECI = {
    -1,                         /* nDims */
    125,                        /* lineNo */
    9,                          /* colNo */
    "categorical/convertCodes", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\matlab\\datatypes\\codegen\\categorical\\+"
    "matlab\\+internal\\+coder\\@categorical\\convertCodes.m" /* pName */
};

static emlrtBCInfo i_emlrtBCI = {
    -1,                           /* iFirst */
    -1,                           /* iLast */
    258,                          /* lineNo */
    31,                           /* colNo */
    "",                           /* aName */
    "categorical/parenReference", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\matlab\\datatypes\\codegen\\categorical\\+"
    "matlab\\+internal\\+coder\\@categorical\\categorical.m", /* pName */
    0                                                         /* checkKind */
};

static emlrtRTEInfo d_emlrtRTEI = {
    240,                                    /* lineNo */
    123,                                    /* colNo */
    "ClassificationModel/verifyClassNames", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\stats\\incremental\\+incremental\\+"
    "coder\\+classif\\ClassificationModel.m" /* pName */
};

static emlrtBCInfo pb_emlrtBCI = {
    -1,                                      /* iFirst */
    -1,                                      /* iLast */
    209,                                     /* lineNo */
    39,                                      /* colNo */
    "",                                      /* aName */
    "incrementalClassificationLinear/score", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\stats\\incremental\\+incremental\\+"
    "coder\\incrementalClassificationLinear.m", /* pName */
    0                                           /* checkKind */
};

static emlrtBCInfo qb_emlrtBCI = {
    -1,                                      /* iFirst */
    -1,                                      /* iLast */
    210,                                     /* lineNo */
    38,                                      /* colNo */
    "",                                      /* aName */
    "incrementalClassificationLinear/score", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\stats\\incremental\\+incremental\\+"
    "coder\\incrementalClassificationLinear.m", /* pName */
    0                                           /* checkKind */
};

static emlrtBCInfo rb_emlrtBCI = {
    -1,                                      /* iFirst */
    -1,                                      /* iLast */
    210,                                     /* lineNo */
    27,                                      /* colNo */
    "",                                      /* aName */
    "incrementalClassificationLinear/score", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\stats\\incremental\\+incremental\\+"
    "coder\\incrementalClassificationLinear.m", /* pName */
    0                                           /* checkKind */
};

static emlrtBCInfo sb_emlrtBCI = {
    -1,                                      /* iFirst */
    -1,                                      /* iLast */
    211,                                     /* lineNo */
    37,                                      /* colNo */
    "",                                      /* aName */
    "incrementalClassificationLinear/score", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\stats\\incremental\\+incremental\\+"
    "coder\\incrementalClassificationLinear.m", /* pName */
    0                                           /* checkKind */
};

static emlrtBCInfo tb_emlrtBCI = {
    -1,                                      /* iFirst */
    -1,                                      /* iLast */
    211,                                     /* lineNo */
    27,                                      /* colNo */
    "",                                      /* aName */
    "incrementalClassificationLinear/score", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\stats\\incremental\\+incremental\\+"
    "coder\\incrementalClassificationLinear.m", /* pName */
    0                                           /* checkKind */
};

static emlrtBCInfo ud_emlrtBCI = {
    -1,      /* iFirst */
    -1,      /* iLast */
    29,      /* lineNo */
    37,      /* colNo */
    "",      /* aName */
    "hinge", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\stats\\classreg\\+classreg\\+learning\\+"
    "coder\\+loss\\+unnormalized\\hinge.m", /* pName */
    0                                       /* checkKind */
};

static emlrtBCInfo vd_emlrtBCI = {
    -1,      /* iFirst */
    -1,      /* iLast */
    28,      /* lineNo */
    58,      /* colNo */
    "",      /* aName */
    "hinge", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\stats\\classreg\\+classreg\\+learning\\+"
    "coder\\+loss\\+unnormalized\\hinge.m", /* pName */
    0                                       /* checkKind */
};

static emlrtBCInfo wd_emlrtBCI = {
    -1,      /* iFirst */
    -1,      /* iLast */
    20,      /* lineNo */
    28,      /* colNo */
    "",      /* aName */
    "hinge", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\stats\\classreg\\+classreg\\+learning\\+"
    "coder\\+loss\\+unnormalized\\hinge.m", /* pName */
    0                                       /* checkKind */
};

static emlrtBCInfo xd_emlrtBCI = {
    -1,             /* iFirst */
    -1,             /* iLast */
    36,             /* lineNo */
    58,             /* colNo */
    "",             /* aName */
    "classiferror", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\stats\\classreg\\+classreg\\+learning\\+"
    "coder\\+loss\\+unnormalized\\classiferror.m", /* pName */
    0                                              /* checkKind */
};

static emlrtBCInfo yd_emlrtBCI = {
    -1,             /* iFirst */
    -1,             /* iLast */
    32,             /* lineNo */
    58,             /* colNo */
    "",             /* aName */
    "classiferror", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\stats\\classreg\\+classreg\\+learning\\+"
    "coder\\+loss\\+unnormalized\\classiferror.m", /* pName */
    0                                              /* checkKind */
};

static emlrtBCInfo ae_emlrtBCI = {
    -1,             /* iFirst */
    -1,             /* iLast */
    25,             /* lineNo */
    28,             /* colNo */
    "",             /* aName */
    "classiferror", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\stats\\classreg\\+classreg\\+learning\\+"
    "coder\\+loss\\+unnormalized\\classiferror.m", /* pName */
    0                                              /* checkKind */
};

static emlrtECInfo c_emlrtECI = {
    -1,                                                    /* nDims */
    279,                                                   /* lineNo */
    21,                                                    /* colNo */
    "ClassificationModel/adjustWeightAndCalculateMetrics", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\stats\\incremental\\+incremental\\+"
    "coder\\+classif\\ClassificationModel.m" /* pName */
};

static emlrtBCInfo be_emlrtBCI = {
    -1,             /* iFirst */
    -1,             /* iLast */
    33,             /* lineNo */
    18,             /* colNo */
    "",             /* aName */
    "classiferror", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\stats\\classreg\\+classreg\\+learning\\+"
    "coder\\+loss\\+unnormalized\\classiferror.m", /* pName */
    0                                              /* checkKind */
};

static emlrtBCInfo ce_emlrtBCI = {
    -1,      /* iFirst */
    -1,      /* iLast */
    26,      /* lineNo */
    18,      /* colNo */
    "",      /* aName */
    "hinge", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\stats\\classreg\\+classreg\\+learning\\+"
    "coder\\+loss\\+unnormalized\\hinge.m", /* pName */
    0                                       /* checkKind */
};

static emlrtBCInfo de_emlrtBCI = {
    -1,             /* iFirst */
    -1,             /* iLast */
    43,             /* lineNo */
    18,             /* colNo */
    "",             /* aName */
    "classiferror", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\stats\\classreg\\+classreg\\+learning\\+"
    "coder\\+loss\\+unnormalized\\classiferror.m", /* pName */
    0                                              /* checkKind */
};

static emlrtBCInfo ee_emlrtBCI = {
    -1,      /* iFirst */
    -1,      /* iLast */
    29,      /* lineNo */
    18,      /* colNo */
    "",      /* aName */
    "hinge", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\stats\\classreg\\+classreg\\+learning\\+"
    "coder\\+loss\\+unnormalized\\hinge.m", /* pName */
    0                                       /* checkKind */
};

static emlrtBCInfo fe_emlrtBCI = {
    -1,             /* iFirst */
    -1,             /* iLast */
    38,             /* lineNo */
    35,             /* colNo */
    "",             /* aName */
    "classiferror", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\stats\\classreg\\+classreg\\+learning\\+"
    "coder\\+loss\\+unnormalized\\classiferror.m", /* pName */
    0                                              /* checkKind */
};

static emlrtBCInfo ge_emlrtBCI = {
    -1,             /* iFirst */
    -1,             /* iLast */
    39,             /* lineNo */
    36,             /* colNo */
    "",             /* aName */
    "classiferror", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\stats\\classreg\\+classreg\\+learning\\+"
    "coder\\+loss\\+unnormalized\\classiferror.m", /* pName */
    0                                              /* checkKind */
};

static emlrtBCInfo he_emlrtBCI = {
    -1,                                          /* iFirst */
    -1,                                          /* iLast */
    382,                                         /* lineNo */
    36,                                          /* colNo */
    "",                                          /* aName */
    "ClassificationModel/classifLossForMetrics", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\stats\\incremental\\+incremental\\+"
    "coder\\+classif\\ClassificationModel.m", /* pName */
    0                                         /* checkKind */
};

static emlrtBCInfo ie_emlrtBCI = {
    -1,                                          /* iFirst */
    -1,                                          /* iLast */
    382,                                         /* lineNo */
    55,                                          /* colNo */
    "",                                          /* aName */
    "ClassificationModel/classifLossForMetrics", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\stats\\incremental\\+incremental\\+"
    "coder\\+classif\\ClassificationModel.m", /* pName */
    0                                         /* checkKind */
};

static emlrtBCInfo je_emlrtBCI = {
    -1,                                          /* iFirst */
    -1,                                          /* iLast */
    394,                                         /* lineNo */
    32,                                          /* colNo */
    "",                                          /* aName */
    "ClassificationModel/classifLossForMetrics", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\stats\\incremental\\+incremental\\+"
    "coder\\+classif\\ClassificationModel.m", /* pName */
    0                                         /* checkKind */
};

static emlrtRTEInfo o_emlrtRTEI = {
    401,                                         /* lineNo */
    17,                                          /* colNo */
    "ClassificationModel/classifLossForMetrics", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\stats\\incremental\\+incremental\\+"
    "coder\\+classif\\ClassificationModel.m" /* pName */
};

static emlrtBCInfo se_emlrtBCI = {
    -1,                                          /* iFirst */
    -1,                                          /* iLast */
    380,                                         /* lineNo */
    35,                                          /* colNo */
    "",                                          /* aName */
    "ClassificationModel/classifLossForMetrics", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\stats\\incremental\\+incremental\\+"
    "coder\\+classif\\ClassificationModel.m", /* pName */
    0                                         /* checkKind */
};

static emlrtBCInfo te_emlrtBCI = {
    -1,                                          /* iFirst */
    -1,                                          /* iLast */
    393,                                         /* lineNo */
    35,                                          /* colNo */
    "",                                          /* aName */
    "ClassificationModel/classifLossForMetrics", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\stats\\incremental\\+incremental\\+"
    "coder\\+classif\\ClassificationModel.m", /* pName */
    0                                         /* checkKind */
};

static emlrtBCInfo ue_emlrtBCI = {
    -1,                                          /* iFirst */
    -1,                                          /* iLast */
    383,                                         /* lineNo */
    43,                                          /* colNo */
    "",                                          /* aName */
    "ClassificationModel/classifLossForMetrics", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\stats\\incremental\\+incremental\\+"
    "coder\\+classif\\ClassificationModel.m", /* pName */
    0                                         /* checkKind */
};

static emlrtBCInfo ve_emlrtBCI = {
    -1,                                          /* iFirst */
    -1,                                          /* iLast */
    394,                                         /* lineNo */
    42,                                          /* colNo */
    "",                                          /* aName */
    "ClassificationModel/classifLossForMetrics", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\stats\\incremental\\+incremental\\+"
    "coder\\+classif\\ClassificationModel.m", /* pName */
    0                                         /* checkKind */
};

static emlrtBCInfo we_emlrtBCI = {
    -1,                                          /* iFirst */
    -1,                                          /* iLast */
    395,                                         /* lineNo */
    39,                                          /* colNo */
    "",                                          /* aName */
    "ClassificationModel/classifLossForMetrics", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\stats\\incremental\\+incremental\\+"
    "coder\\+classif\\ClassificationModel.m", /* pName */
    0                                         /* checkKind */
};

static emlrtBCInfo xe_emlrtBCI = {
    -1,                                /* iFirst */
    -1,                                /* iLast */
    498,                               /* lineNo */
    47,                                /* colNo */
    "",                                /* aName */
    "ClassificationModel/prepareData", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\stats\\incremental\\+incremental\\+"
    "coder\\+classif\\ClassificationModel.m", /* pName */
    0                                         /* checkKind */
};

static emlrtBCInfo uf_emlrtBCI = {
    -1,                                  /* iFirst */
    -1,                                  /* iLast */
    350,                                 /* lineNo */
    32,                                  /* colNo */
    "",                                  /* aName */
    "ClassificationModel/adjustWeights", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\stats\\incremental\\+incremental\\+"
    "coder\\+classif\\ClassificationModel.m", /* pName */
    0                                         /* checkKind */
};

static emlrtBCInfo vf_emlrtBCI = {
    -1,                                  /* iFirst */
    -1,                                  /* iLast */
    340,                                 /* lineNo */
    32,                                  /* colNo */
    "",                                  /* aName */
    "ClassificationModel/adjustWeights", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\stats\\incremental\\+incremental\\+"
    "coder\\+classif\\ClassificationModel.m", /* pName */
    0                                         /* checkKind */
};

static emlrtBCInfo wf_emlrtBCI = {
    -1,                                  /* iFirst */
    -1,                                  /* iLast */
    339,                                 /* lineNo */
    22,                                  /* colNo */
    "",                                  /* aName */
    "ClassificationModel/adjustWeights", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\stats\\incremental\\+incremental\\+"
    "coder\\+classif\\ClassificationModel.m", /* pName */
    0                                         /* checkKind */
};

static emlrtBCInfo xf_emlrtBCI = {
    -1,                                  /* iFirst */
    -1,                                  /* iLast */
    339,                                 /* lineNo */
    56,                                  /* colNo */
    "",                                  /* aName */
    "ClassificationModel/adjustWeights", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\stats\\incremental\\+incremental\\+"
    "coder\\+classif\\ClassificationModel.m", /* pName */
    0                                         /* checkKind */
};

static emlrtBCInfo yf_emlrtBCI = {
    -1,                                  /* iFirst */
    -1,                                  /* iLast */
    339,                                 /* lineNo */
    37,                                  /* colNo */
    "",                                  /* aName */
    "ClassificationModel/adjustWeights", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\stats\\incremental\\+incremental\\+"
    "coder\\+classif\\ClassificationModel.m", /* pName */
    0                                         /* checkKind */
};

static emlrtBCInfo ag_emlrtBCI = {
    -1,                                  /* iFirst */
    -1,                                  /* iLast */
    338,                                 /* lineNo */
    34,                                  /* colNo */
    "",                                  /* aName */
    "ClassificationModel/adjustWeights", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\stats\\incremental\\+incremental\\+"
    "coder\\+classif\\ClassificationModel.m", /* pName */
    0                                         /* checkKind */
};

static emlrtBCInfo bg_emlrtBCI = {
    -1,                                  /* iFirst */
    -1,                                  /* iLast */
    350,                                 /* lineNo */
    19,                                  /* colNo */
    "",                                  /* aName */
    "ClassificationModel/adjustWeights", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\stats\\incremental\\+incremental\\+"
    "coder\\+classif\\ClassificationModel.m", /* pName */
    0                                         /* checkKind */
};

static emlrtBCInfo cg_emlrtBCI = {
    -1,                                /* iFirst */
    -1,                                /* iLast */
    503,                               /* lineNo */
    116,                               /* colNo */
    "",                                /* aName */
    "ClassificationModel/prepareData", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\stats\\incremental\\+incremental\\+"
    "coder\\+classif\\ClassificationModel.m", /* pName */
    0                                         /* checkKind */
};

static emlrtBCInfo dg_emlrtBCI = {
    -1,                                /* iFirst */
    -1,                                /* iLast */
    503,                               /* lineNo */
    99,                                /* colNo */
    "",                                /* aName */
    "ClassificationModel/prepareData", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\stats\\incremental\\+incremental\\+"
    "coder\\+classif\\ClassificationModel.m", /* pName */
    0                                         /* checkKind */
};

static emlrtBCInfo eg_emlrtBCI = {
    -1,                                /* iFirst */
    -1,                                /* iLast */
    503,                               /* lineNo */
    87,                                /* colNo */
    "",                                /* aName */
    "ClassificationModel/prepareData", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\stats\\incremental\\+incremental\\+"
    "coder\\+classif\\ClassificationModel.m", /* pName */
    0                                         /* checkKind */
};

static emlrtBCInfo fg_emlrtBCI = {
    -1,                                /* iFirst */
    -1,                                /* iLast */
    503,                               /* lineNo */
    51,                                /* colNo */
    "",                                /* aName */
    "ClassificationModel/prepareData", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\stats\\incremental\\+incremental\\+"
    "coder\\+classif\\ClassificationModel.m", /* pName */
    0                                         /* checkKind */
};

static emlrtRTEInfo w_emlrtRTEI = {
    207,                   /* lineNo */
    13,                    /* colNo */
    "ClassificationModel", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\stats\\incremental\\+incremental\\+"
    "coder\\+classif\\ClassificationModel.m" /* pName */
};

static emlrtRTEInfo x_emlrtRTEI = {
    259,           /* lineNo */
    13,            /* colNo */
    "categorical", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\matlab\\datatypes\\codegen\\categorical\\+"
    "matlab\\+internal\\+coder\\@categorical\\categorical.m" /* pName */
};

static emlrtRTEInfo cb_emlrtRTEI = {
    139,            /* lineNo */
    69,             /* colNo */
    "convertCodes", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\matlab\\datatypes\\codegen\\categorical\\+"
    "matlab\\+internal\\+coder\\@categorical\\convertCodes.m" /* pName */
};

static emlrtRTEInfo db_emlrtRTEI = {
    142,            /* lineNo */
    19,             /* colNo */
    "convertCodes", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\matlab\\datatypes\\codegen\\categorical\\+"
    "matlab\\+internal\\+coder\\@categorical\\convertCodes.m" /* pName */
};

static emlrtRTEInfo eb_emlrtRTEI = {
    144,            /* lineNo */
    19,             /* colNo */
    "convertCodes", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\matlab\\datatypes\\codegen\\categorical\\+"
    "matlab\\+internal\\+coder\\@categorical\\convertCodes.m" /* pName */
};

static emlrtRTEInfo fb_emlrtRTEI = {
    239,                   /* lineNo */
    55,                    /* colNo */
    "ClassificationModel", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\stats\\incremental\\+incremental\\+"
    "coder\\+classif\\ClassificationModel.m" /* pName */
};

static emlrtRTEInfo hb_emlrtRTEI = {
    221,                   /* lineNo */
    64,                    /* colNo */
    "ClassificationModel", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\stats\\incremental\\+incremental\\+"
    "coder\\+classif\\ClassificationModel.m" /* pName */
};

static emlrtRTEInfo ob_emlrtRTEI = {
    206,                               /* lineNo */
    17,                                /* colNo */
    "incrementalClassificationLinear", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\stats\\incremental\\+incremental\\+"
    "coder\\incrementalClassificationLinear.m" /* pName */
};

static emlrtRTEInfo pb_emlrtRTEI = {
    357,                   /* lineNo */
    32,                    /* colNo */
    "ClassificationModel", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\stats\\incremental\\+incremental\\+"
    "coder\\+classif\\ClassificationModel.m" /* pName */
};

static emlrtRTEInfo jc_emlrtRTEI = {
    268,                   /* lineNo */
    17,                    /* colNo */
    "ClassificationModel", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\stats\\incremental\\+incremental\\+"
    "coder\\+classif\\ClassificationModel.m" /* pName */
};

static emlrtRTEInfo kc_emlrtRTEI = {
    279,                   /* lineNo */
    43,                    /* colNo */
    "ClassificationModel", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\stats\\incremental\\+incremental\\+"
    "coder\\+classif\\ClassificationModel.m" /* pName */
};

static emlrtRTEInfo lc_emlrtRTEI = {
    262,                   /* lineNo */
    52,                    /* colNo */
    "ClassificationModel", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\stats\\incremental\\+incremental\\+"
    "coder\\+classif\\ClassificationModel.m" /* pName */
};

static emlrtRTEInfo mc_emlrtRTEI = {
    373,                   /* lineNo */
    13,                    /* colNo */
    "ClassificationModel", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\stats\\incremental\\+incremental\\+"
    "coder\\+classif\\ClassificationModel.m" /* pName */
};

static emlrtRTEInfo nc_emlrtRTEI = {
    377,                   /* lineNo */
    13,                    /* colNo */
    "ClassificationModel", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\stats\\incremental\\+incremental\\+"
    "coder\\+classif\\ClassificationModel.m" /* pName */
};

static emlrtRTEInfo hd_emlrtRTEI = {
    172,                   /* lineNo */
    13,                    /* colNo */
    "ClassificationModel", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\stats\\incremental\\+incremental\\+"
    "coder\\+classif\\ClassificationModel.m" /* pName */
};

/* Function Declarations */
static void ClassificationModel_prepareData(const emlrtStack *sp,
                                            const emxArray_real_T *X,
                                            const c_categorical *Y,
                                            boolean_T indsToExclude_data[],
                                            int32_T *indsToExclude_size);

static void c_ClassificationModel_classifLo(
    myIncrLearn_mexStackData *SD, const emlrtStack *sp,
    const uint8_T this_ClassNames_codes[2],
    const cell_wrap_1 this_ClassNames_categoryNames[2],
    const real_T this_Prior[2], boolean_T this_PriorDefined,
    const real_T this_Impl_Beta[60], real_T this_Impl_Bias,
    const emxArray_real_T *X, const uint8_T Y_codes_data[],
    const int32_T Y_codes_size[2], const cell_wrap_22 Y_categoryNames[2],
    boolean_T Y_isProtected, boolean_T Y_isOrdinal,
    real_T Y_numCategoriesUpperBound, emxArray_real_T *W, boolean_T C_data[],
    int32_T C_size[2], emxArray_real_T *s, boolean_T indsToExclude_data[],
    int32_T *indsToExclude_size);

static void d_ClassificationModel_adjustWei(
    const emlrtStack *sp, const real_T this_Prior[2], const boolean_T C_data[],
    const int32_T C_size[2], emxArray_real_T *W,
    const boolean_T indsToExclude_data[], int32_T indsToExclude_size);

/* Function Definitions */
static void ClassificationModel_prepareData(const emlrtStack *sp,
                                            const emxArray_real_T *X,
                                            const c_categorical *Y,
                                            boolean_T indsToExclude_data[],
                                            int32_T *indsToExclude_size)
{
  emlrtStack st;
  int32_T ii;
  int32_T n;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &t_emlrtRSI;
  validateattributes(&st, Y->codes.size, X->size[0]);
  n = Y->codes.size[0];
  *indsToExclude_size = Y->codes.size[0];
  for (ii = 0; ii < n; ii++) {
    int32_T i;
    st.site = &v_emlrtRSI;
    i = Y->codes.size[0] * Y->codes.size[1];
    if (ii + 1 > i) {
      emlrtDynamicBoundsCheckR2012b(ii + 1, 1, i, &i_emlrtBCI, &st);
    }
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(&st);
    }
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(&st);
    }
    if (ii + 1 > *indsToExclude_size) {
      emlrtDynamicBoundsCheckR2012b(ii + 1, 1, *indsToExclude_size,
                                    &xe_emlrtBCI, (emlrtCTX)sp);
    }
    indsToExclude_data[ii] = (Y->codes.data[ii] == 0);
  }
}

static void c_ClassificationModel_classifLo(
    myIncrLearn_mexStackData *SD, const emlrtStack *sp,
    const uint8_T this_ClassNames_codes[2],
    const cell_wrap_1 this_ClassNames_categoryNames[2],
    const real_T this_Prior[2], boolean_T this_PriorDefined,
    const real_T this_Impl_Beta[60], real_T this_Impl_Bias,
    const emxArray_real_T *X, const uint8_T Y_codes_data[],
    const int32_T Y_codes_size[2], const cell_wrap_22 Y_categoryNames[2],
    boolean_T Y_isProtected, boolean_T Y_isOrdinal,
    real_T Y_numCategoriesUpperBound, emxArray_real_T *W, boolean_T C_data[],
    int32_T C_size[2], emxArray_real_T *s, boolean_T indsToExclude_data[],
    int32_T *indsToExclude_size)
{
  b_categorical a__6;
  c_categorical Y;
  emlrtStack st;
  emxArray_int32_T *Yout;
  real_T *s_data;
  int32_T i;
  int32_T ii;
  int32_T jj;
  int32_T n;
  int32_T *Yout_data;
  boolean_T exitg1;
  boolean_T guard1 = false;
  st.prev = sp;
  st.tls = sp->tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  Y.codes.size[0] = Y_codes_size[0];
  Y.codes.size[1] = Y_codes_size[1];
  n = Y_codes_size[0] * Y_codes_size[1];
  if (n - 1 >= 0) {
    memcpy(&Y.codes.data[0], &Y_codes_data[0], n * sizeof(uint8_T));
  }
  emxInit_int32_T(sp, &Yout, 1, &mc_emlrtRTEI);
  Y.categoryNames[0] = Y_categoryNames[0];
  Y.categoryNames[1] = Y_categoryNames[1];
  Y.isProtected = Y_isProtected;
  Y.isOrdinal = Y_isOrdinal;
  Y.numCategoriesUpperBound = Y_numCategoriesUpperBound;
  st.site = &k_emlrtRSI;
  ClassificationModel_prepareData(&st, X, &Y, indsToExclude_data,
                                  indsToExclude_size);
  st.site = &l_emlrtRSI;
  c_ClassificationModel_verifyCla(
      &st, this_ClassNames_codes, this_ClassNames_categoryNames, Y.codes.data,
      Y.codes.size, Y.categoryNames, Y_isOrdinal, indsToExclude_data,
      *indsToExclude_size, Yout);
  Yout_data = Yout->data;
  st.site = &m_emlrtRSI;
  if (this_PriorDefined) {
    n = Yout->size[0];
    for (ii = 0; ii < n; ii++) {
      if (ii + 1 > *indsToExclude_size) {
        emlrtDynamicBoundsCheckR2012b(ii + 1, 1, *indsToExclude_size,
                                      &le_emlrtBCI, &st);
      }
      if (!indsToExclude_data[ii]) {
        if (ii + 1 > Yout->size[0]) {
          emlrtDynamicBoundsCheckR2012b(ii + 1, 1, Yout->size[0], &ke_emlrtBCI,
                                        &st);
        }
        i = Yout_data[ii];
        if ((i < 1) || (i > 2)) {
          emlrtDynamicBoundsCheckR2012b(i, 1, 2, &me_emlrtBCI, &st);
        }
        if (this_Prior[i - 1] == 0.0) {
          if (ii + 1 > *indsToExclude_size) {
            emlrtDynamicBoundsCheckR2012b(ii + 1, 1, *indsToExclude_size,
                                          &ne_emlrtBCI, &st);
          }
          indsToExclude_data[ii] = true;
        }
      }
    }
  }
  st.site = &n_emlrtRSI;
  C_size[0] = Yout->size[0];
  C_size[1] = 2;
  n = Yout->size[0] << 1;
  if (n - 1 >= 0) {
    memset(&C_data[0], 0, n * sizeof(boolean_T));
  }
  i = Yout->size[0];
  for (ii = 0; ii < i; ii++) {
    if (ii + 1 > *indsToExclude_size) {
      emlrtDynamicBoundsCheckR2012b(ii + 1, 1, *indsToExclude_size,
                                    &oe_emlrtBCI, &st);
    }
    if (!indsToExclude_data[ii]) {
      if (ii + 1 > C_size[0]) {
        emlrtDynamicBoundsCheckR2012b(ii + 1, 1, C_size[0], &pe_emlrtBCI, &st);
      }
      if (ii + 1 > Yout->size[0]) {
        emlrtDynamicBoundsCheckR2012b(ii + 1, 1, Yout->size[0], &re_emlrtBCI,
                                      &st);
      }
      n = Yout_data[ii];
      if ((n < 1) || (n > 2)) {
        emlrtDynamicBoundsCheckR2012b(n, 1, 2, &qe_emlrtBCI, &st);
      }
      C_data[ii + C_size[0] * (n - 1)] = true;
    }
  }
  emxFree_int32_T(&st, &Yout);
  emxInitStruct_categorical1(&st, &a__6, &nc_emlrtRTEI);
  st.site = &o_emlrtRSI;
  c_ClassificationModel_predictWi(
      SD, &st, this_ClassNames_codes, this_ClassNames_categoryNames, this_Prior,
      this_Impl_Beta, this_Impl_Bias, X, indsToExclude_data,
      *indsToExclude_size, &a__6, s);
  s_data = s->data;
  i = s->size[0];
  emxFreeStruct_categorical1(sp, &a__6);
  for (ii = 0; ii < i; ii++) {
    if (ii + 1 > *indsToExclude_size) {
      emlrtDynamicBoundsCheckR2012b(ii + 1, 1, *indsToExclude_size,
                                    &se_emlrtBCI, (emlrtCTX)sp);
    }
    if (!indsToExclude_data[ii]) {
      jj = 0;
      exitg1 = false;
      while ((!exitg1) && (jj < 2)) {
        if (ii + 1 > s->size[0]) {
          emlrtDynamicBoundsCheckR2012b(ii + 1, 1, s->size[0], &he_emlrtBCI,
                                        (emlrtCTX)sp);
        }
        if (muDoubleScalarIsNaN(s_data[ii + s->size[0] * jj])) {
          if (ii + 1 > *indsToExclude_size) {
            emlrtDynamicBoundsCheckR2012b(ii + 1, 1, *indsToExclude_size,
                                          &ue_emlrtBCI, (emlrtCTX)sp);
          }
          indsToExclude_data[ii] = true;
          exitg1 = true;
        } else {
          n = W->size[0];
          if (ii + 1 > n) {
            emlrtDynamicBoundsCheckR2012b(ii + 1, 1, n, &ie_emlrtBCI,
                                          (emlrtCTX)sp);
          }
          jj++;
        }
      }
    }
  }
  st.site = &q_emlrtRSI;
  d_ClassificationModel_adjustWei(&st, this_Prior, C_data, C_size, W,
                                  indsToExclude_data, *indsToExclude_size);
  s_data = W->data;
  i = W->size[0];
  for (ii = 0; ii < i; ii++) {
    if (ii + 1 > *indsToExclude_size) {
      emlrtDynamicBoundsCheckR2012b(ii + 1, 1, *indsToExclude_size,
                                    &te_emlrtBCI, (emlrtCTX)sp);
    }
    if (!indsToExclude_data[ii]) {
      n = W->size[0];
      if (ii + 1 > n) {
        emlrtDynamicBoundsCheckR2012b(ii + 1, 1, n, &je_emlrtBCI, (emlrtCTX)sp);
      }
      guard1 = false;
      if (muDoubleScalarIsNaN(s_data[ii])) {
        guard1 = true;
      } else {
        n = W->size[0];
        if (ii + 1 > n) {
          emlrtDynamicBoundsCheckR2012b(ii + 1, 1, n, &ve_emlrtBCI,
                                        (emlrtCTX)sp);
        }
        if (s_data[ii] == 0.0) {
          guard1 = true;
        }
      }
      if (guard1) {
        if (ii + 1 > *indsToExclude_size) {
          emlrtDynamicBoundsCheckR2012b(ii + 1, 1, *indsToExclude_size,
                                        &we_emlrtBCI, (emlrtCTX)sp);
        }
        indsToExclude_data[ii] = true;
      }
    }
  }
  guard1 = false;
  if (W->size[0] != Y_codes_size[0]) {
    guard1 = true;
  } else {
    boolean_T x_data[24075];
    boolean_T y;
    jj = W->size[0];
    n = W->size[0];
    for (i = 0; i < n; i++) {
      x_data[i] = (s_data[i] < 0.0);
    }
    y = false;
    n = 1;
    exitg1 = false;
    while ((!exitg1) && (n <= jj)) {
      if (x_data[n - 1]) {
        y = true;
        exitg1 = true;
      } else {
        n++;
      }
    }
    if (y) {
      guard1 = true;
    }
  }
  if (guard1) {
    emlrtErrorWithMessageIdR2018a(
        sp, &o_emlrtRTEI,
        "stats:classreg:learning:internal:regrCheck:BadWeights",
        "stats:classreg:learning:internal:regrCheck:BadWeights", 2, 6,
        (real_T)Y_codes_size[0]);
  }
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

static void d_ClassificationModel_adjustWei(
    const emlrtStack *sp, const real_T this_Prior[2], const boolean_T C_data[],
    const int32_T C_size[2], emxArray_real_T *W,
    const boolean_T indsToExclude_data[], int32_T indsToExclude_size)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack st;
  real_T Wj_idx_0;
  real_T Wj_idx_1;
  real_T adjWFactor_idx_0;
  real_T adjWFactor_idx_1;
  real_T *W_data;
  int32_T WC_size_idx_0_tmp;
  int32_T ii;
  int32_T loop_ub;
  int8_T WC_data[48150];
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
  W_data = W->data;
  WC_size_idx_0_tmp = (int16_T)C_size[0];
  loop_ub = (int16_T)C_size[0] << 1;
  if (loop_ub - 1 >= 0) {
    memset(&WC_data[0], 0, loop_ub * sizeof(int8_T));
  }
  Wj_idx_0 = 0.0;
  adjWFactor_idx_0 = 0.0;
  Wj_idx_1 = 0.0;
  adjWFactor_idx_1 = 0.0;
  st.site = &bf_emlrtRSI;
  for (ii = 0; ii < WC_size_idx_0_tmp; ii++) {
    if (ii + 1 > indsToExclude_size) {
      emlrtDynamicBoundsCheckR2012b(ii + 1, 1, indsToExclude_size, &ag_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    if (!indsToExclude_data[ii]) {
      loop_ub = W->size[0];
      if (ii + 1 > loop_ub) {
        emlrtDynamicBoundsCheckR2012b(ii + 1, 1, loop_ub, &xf_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      if (ii + 1 > C_size[0]) {
        emlrtDynamicBoundsCheckR2012b(ii + 1, 1, C_size[0], &yf_emlrtBCI,
                                      (emlrtCTX)sp);
      }
      if (ii + 1 > WC_size_idx_0_tmp) {
        emlrtDynamicBoundsCheckR2012b(ii + 1, 1, WC_size_idx_0_tmp,
                                      &wf_emlrtBCI, (emlrtCTX)sp);
      }
      WC_data[ii] = (int8_T)C_data[ii];
      loop_ub = ii + WC_size_idx_0_tmp;
      WC_data[loop_ub] = (int8_T)C_data[ii + C_size[0]];
      if (ii + 1 > WC_size_idx_0_tmp) {
        emlrtDynamicBoundsCheckR2012b(ii + 1, 1, WC_size_idx_0_tmp,
                                      &vf_emlrtBCI, (emlrtCTX)sp);
      }
      Wj_idx_0 += (real_T)WC_data[ii];
      Wj_idx_1 += (real_T)WC_data[loop_ub];
    }
  }
  if (Wj_idx_0 != 0.0) {
    adjWFactor_idx_0 = this_Prior[0] / Wj_idx_0;
  }
  if (Wj_idx_1 != 0.0) {
    adjWFactor_idx_1 = this_Prior[1] / Wj_idx_1;
  }
  loop_ub = W->size[0];
  st.site = &cf_emlrtRSI;
  for (ii = 0; ii < loop_ub; ii++) {
    real_T WC[2];
    int32_T i;
    st.site = &df_emlrtRSI;
    if (ii + 1 > WC_size_idx_0_tmp) {
      emlrtDynamicBoundsCheckR2012b(ii + 1, 1, WC_size_idx_0_tmp, &uf_emlrtBCI,
                                    &st);
    }
    b_st.site = &ef_emlrtRSI;
    c_st.site = &ff_emlrtRSI;
    d_st.site = &gf_emlrtRSI;
    e_st.site = &hf_emlrtRSI;
    f_st.site = &if_emlrtRSI;
    WC[0] = (real_T)WC_data[ii] * adjWFactor_idx_0;
    WC[1] = (real_T)WC_data[ii + WC_size_idx_0_tmp] * adjWFactor_idx_1;
    i = W->size[0];
    if (ii + 1 > i) {
      emlrtDynamicBoundsCheckR2012b(ii + 1, 1, i, &bg_emlrtBCI, &f_st);
    }
    W_data[ii] = sumColumnB(WC);
  }
}

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
    int32_T *indsToExclude_size)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  emxArray_real_T *r;
  emxArray_real_T *s;
  real_T *r1;
  real_T *s_data;
  real_T *windowMetrics_data;
  int32_T C_size[2];
  int32_T i;
  int32_T ii;
  int32_T iindx;
  int32_T jj;
  int32_T y;
  int32_T yfit;
  boolean_T allScoresNaN;
  boolean_T exitg1;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  emxInit_real_T(sp, &s, 2, &lc_emlrtRTEI);
  st.site = &i_emlrtRSI;
  c_ClassificationModel_classifLo(
      SD, &st, this_ClassNames_codes, this_ClassNames_categoryNames, this_Prior,
      this_PriorDefined, this_Impl_Beta, this_Impl_Bias, X, Y_codes_data,
      Y_codes_size, Y_categoryNames, Y_isProtected, Y_isOrdinal,
      Y_numCategoriesUpperBound, W, SD->f2.C_data, C_size, s,
      indsToExclude_data, indsToExclude_size);
  s_data = s->data;
  i = windowMetrics->size[0] * windowMetrics->size[1];
  windowMetrics->size[0] = X->size[0];
  windowMetrics->size[1] = 2;
  emxEnsureCapacity_real_T(sp, windowMetrics, i, &jc_emlrtRTEI);
  windowMetrics_data = windowMetrics->data;
  yfit = X->size[0] << 1;
  for (i = 0; i < yfit; i++) {
    windowMetrics_data[i] = 0.0;
  }
  if ((this_Prior[0] < this_Prior[1]) ||
      (muDoubleScalarIsNaN(this_Prior[0]) &&
       (!muDoubleScalarIsNaN(this_Prior[1])))) {
    iindx = 2;
  } else {
    iindx = 1;
  }
  emxInit_real_T(sp, &r, 1, &lc_emlrtRTEI);
  st.site = &j_emlrtRSI;
  b_st.site = &nf_emlrtRSI;
  i = r->size[0];
  r->size[0] = s->size[0];
  emxEnsureCapacity_real_T(&b_st, r, i, &kc_emlrtRTEI);
  r1 = r->data;
  yfit = s->size[0];
  for (i = 0; i < yfit; i++) {
    r1[i] = 0.0;
  }
  yfit = -1;
  i = s->size[0];
  for (ii = 0; ii < i; ii++) {
    allScoresNaN = true;
    jj = 0;
    exitg1 = false;
    while ((!exitg1) && (jj < 2)) {
      if (ii + 1 > s->size[0]) {
        emlrtDynamicBoundsCheckR2012b(ii + 1, 1, s->size[0], &ae_emlrtBCI,
                                      &b_st);
      }
      if (!muDoubleScalarIsNaN(s_data[ii + s->size[0] * jj])) {
        allScoresNaN = false;
        exitg1 = true;
      } else {
        jj++;
      }
    }
    if (allScoresNaN) {
      c_st.site = &pf_emlrtRSI;
      if (ii + 1 > C_size[0]) {
        emlrtDynamicBoundsCheckR2012b(ii + 1, 1, C_size[0], &yd_emlrtBCI,
                                      &c_st);
      }
      y = 2;
      jj = 0;
      exitg1 = false;
      while ((!exitg1) && (jj < 2)) {
        if (SD->f2.C_data[ii + C_size[0] * jj]) {
          y = jj + 1;
          exitg1 = true;
        } else {
          jj++;
        }
      }
      if (ii + 1 > r->size[0]) {
        emlrtDynamicBoundsCheckR2012b(ii + 1, 1, r->size[0], &be_emlrtBCI,
                                      &b_st);
      }
      r1[ii] = (y != iindx);
    } else {
      real_T maxyfit;
      maxyfit = rtMinusInf;
      c_st.site = &qf_emlrtRSI;
      if (ii + 1 > C_size[0]) {
        emlrtDynamicBoundsCheckR2012b(ii + 1, 1, C_size[0], &xd_emlrtBCI,
                                      &c_st);
      }
      y = 2;
      jj = 0;
      exitg1 = false;
      while ((!exitg1) && (jj < 2)) {
        if (SD->f2.C_data[ii + C_size[0] * jj]) {
          y = jj + 1;
          exitg1 = true;
        } else {
          jj++;
        }
      }
      if (ii + 1 > s->size[0]) {
        emlrtDynamicBoundsCheckR2012b(ii + 1, 1, s->size[0], &fe_emlrtBCI,
                                      &b_st);
      }
      if (s_data[ii] > rtMinusInf) {
        if (ii + 1 > s->size[0]) {
          emlrtDynamicBoundsCheckR2012b(ii + 1, 1, s->size[0], &ge_emlrtBCI,
                                        &b_st);
        }
        maxyfit = s_data[ii];
        yfit = 0;
      }
      if (ii + 1 > s->size[0]) {
        emlrtDynamicBoundsCheckR2012b(ii + 1, 1, s->size[0], &fe_emlrtBCI,
                                      &b_st);
      }
      if (maxyfit < s_data[ii + s->size[0]]) {
        if (ii + 1 > s->size[0]) {
          emlrtDynamicBoundsCheckR2012b(ii + 1, 1, s->size[0], &ge_emlrtBCI,
                                        &b_st);
        }
        yfit = 1;
      }
      if (ii + 1 > r->size[0]) {
        emlrtDynamicBoundsCheckR2012b(ii + 1, 1, r->size[0], &de_emlrtBCI,
                                      &b_st);
      }
      r1[ii] = (y != yfit + 1);
    }
  }
  emlrtSubAssignSizeCheckR2012b(&X->size[0], 1, &r->size[0], 1, &c_emlrtECI,
                                (emlrtCTX)sp);
  yfit = r->size[0];
  for (i = 0; i < yfit; i++) {
    windowMetrics_data[i] = r1[i];
  }
  st.site = &j_emlrtRSI;
  b_st.site = &sf_emlrtRSI;
  i = r->size[0];
  r->size[0] = s->size[0];
  emxEnsureCapacity_real_T(&b_st, r, i, &kc_emlrtRTEI);
  r1 = r->data;
  yfit = s->size[0];
  for (i = 0; i < yfit; i++) {
    r1[i] = 0.0;
  }
  i = s->size[0];
  for (ii = 0; ii < i; ii++) {
    allScoresNaN = true;
    jj = 0;
    exitg1 = false;
    while ((!exitg1) && (jj < 2)) {
      if (ii + 1 > s->size[0]) {
        emlrtDynamicBoundsCheckR2012b(ii + 1, 1, s->size[0], &wd_emlrtBCI,
                                      &b_st);
      }
      if (!muDoubleScalarIsNaN(s_data[ii + s->size[0] * jj])) {
        allScoresNaN = false;
        exitg1 = true;
      } else {
        jj++;
      }
    }
    if (allScoresNaN) {
      if (ii + 1 > r->size[0]) {
        emlrtDynamicBoundsCheckR2012b(ii + 1, 1, r->size[0], &ce_emlrtBCI,
                                      &b_st);
      }
      r1[ii] = rtNaN;
    } else {
      c_st.site = &uf_emlrtRSI;
      if (ii + 1 > C_size[0]) {
        emlrtDynamicBoundsCheckR2012b(ii + 1, 1, C_size[0], &vd_emlrtBCI,
                                      &c_st);
      }
      y = 2;
      jj = 0;
      exitg1 = false;
      while ((!exitg1) && (jj < 2)) {
        if (SD->f2.C_data[ii + C_size[0] * jj]) {
          y = jj + 1;
          exitg1 = true;
        } else {
          jj++;
        }
      }
      if (ii + 1 > s->size[0]) {
        emlrtDynamicBoundsCheckR2012b(ii + 1, 1, s->size[0], &ud_emlrtBCI,
                                      &b_st);
      }
      if (ii + 1 > r->size[0]) {
        emlrtDynamicBoundsCheckR2012b(ii + 1, 1, r->size[0], &ee_emlrtBCI,
                                      &b_st);
      }
      r1[ii] = muDoubleScalarMax(0.0, 1.0 - s_data[ii + s->size[0] * (y - 1)]);
    }
  }
  emxFree_real_T(&b_st, &s);
  emlrtSubAssignSizeCheckR2012b(&windowMetrics->size[0], 1, &r->size[0], 1,
                                &c_emlrtECI, (emlrtCTX)sp);
  yfit = r->size[0];
  for (i = 0; i < yfit; i++) {
    windowMetrics_data[i + windowMetrics->size[0]] = r1[i];
  }
  emxFree_real_T(sp, &r);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

void c_ClassificationModel_predictWi(
    myIncrLearn_mexStackData *SD, const emlrtStack *sp,
    const uint8_T this_ClassNames_codes[2],
    const cell_wrap_1 this_ClassNames_categoryNames[2],
    const real_T this_Prior[2], const real_T this_Impl_Beta[60],
    real_T this_Impl_Bias, const emxArray_real_T *X,
    const boolean_T indsToExclude_data[], int32_T indsToExclude_size,
    b_categorical *varargout_1, emxArray_real_T *varargout_2)
{
  emlrtStack b_st;
  emlrtStack st;
  emxArray_real_T *f;
  real_T *f_data;
  real_T *varargout_2_data;
  int32_T i;
  int32_T loop_ub;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  emxInit_real_T(sp, &f, 1, &pb_emlrtRTEI);
  st.site = &jc_emlrtRSI;
  b_st.site = &lc_emlrtRSI;
  Linear_score(&b_st, this_Impl_Beta, this_Impl_Bias, X, indsToExclude_data,
               &indsToExclude_size, f);
  f_data = f->data;
  i = varargout_2->size[0] * varargout_2->size[1];
  varargout_2->size[0] = f->size[0];
  varargout_2->size[1] = 2;
  emxEnsureCapacity_real_T(&st, varargout_2, i, &ob_emlrtRTEI);
  varargout_2_data = varargout_2->data;
  loop_ub = f->size[0] << 1;
  for (i = 0; i < loop_ub; i++) {
    varargout_2_data[i] = rtNaN;
  }
  i = f->size[0];
  for (loop_ub = 0; loop_ub < i; loop_ub++) {
    if (loop_ub + 1 > indsToExclude_size) {
      emlrtDynamicBoundsCheckR2012b(loop_ub + 1, 1, indsToExclude_size,
                                    &pb_emlrtBCI, &st);
    }
    if (!indsToExclude_data[loop_ub]) {
      if (loop_ub + 1 > f->size[0]) {
        emlrtDynamicBoundsCheckR2012b(loop_ub + 1, 1, f->size[0], &qb_emlrtBCI,
                                      &st);
      }
      if (loop_ub + 1 > varargout_2->size[0]) {
        emlrtDynamicBoundsCheckR2012b(loop_ub + 1, 1, varargout_2->size[0],
                                      &rb_emlrtBCI, &st);
      }
      varargout_2_data[loop_ub] = -f_data[loop_ub];
      if (loop_ub + 1 > f->size[0]) {
        emlrtDynamicBoundsCheckR2012b(loop_ub + 1, 1, f->size[0], &sb_emlrtBCI,
                                      &st);
      }
      if (loop_ub + 1 > varargout_2->size[0]) {
        emlrtDynamicBoundsCheckR2012b(loop_ub + 1, 1, varargout_2->size[0],
                                      &tb_emlrtBCI, &st);
      }
      varargout_2_data[loop_ub + varargout_2->size[0]] = f_data[loop_ub];
    }
  }
  emxFree_real_T(&st, &f);
  st.site = &kc_emlrtRSI;
  c_incrementalClassificationLine(
      SD, &st, this_ClassNames_codes, this_ClassNames_categoryNames, this_Prior,
      varargout_2, indsToExclude_data, indsToExclude_size, varargout_1);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

void c_ClassificationModel_prepareRa(
    const emlrtStack *sp, const e_incrementalClassificationLine *this,
    const emxArray_real_T *X, const c_categorical *Y, const emxArray_real_T *W,
    boolean_T indsToExclude_data[], int32_T *indsToExclude_size)
{
  emlrtStack b_st;
  emlrtStack st;
  emxArray_int32_T *Yout;
  const real_T *X_data;
  int32_T ii;
  int32_T k;
  int32_T n;
  int32_T *Yout_data;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  X_data = X->data;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  st.site = &vg_emlrtRSI;
  b_st.site = &t_emlrtRSI;
  validateattributes(&b_st, Y->codes.size, X->size[0]);
  n = Y->codes.size[0];
  *indsToExclude_size = Y->codes.size[0];
  for (ii = 0; ii < n; ii++) {
    boolean_T b[60];
    boolean_T b_b;
    boolean_T exitg1;
    b_st.site = &yg_emlrtRSI;
    k = Y->codes.size[0] * Y->codes.size[1];
    if (ii + 1 > k) {
      emlrtDynamicBoundsCheckR2012b(ii + 1, 1, k, &i_emlrtBCI, &b_st);
    }
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(&b_st);
    }
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b(&b_st);
    }
    k = X->size[0];
    if (ii + 1 > k) {
      emlrtDynamicBoundsCheckR2012b(ii + 1, 1, k, &eg_emlrtBCI, &st);
    }
    for (k = 0; k < 60; k++) {
      b[k] = muDoubleScalarIsNaN(X_data[ii + X->size[0] * k]);
    }
    b_b = false;
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 60)) {
      if (b[k]) {
        b_b = true;
        exitg1 = true;
      } else {
        k++;
      }
    }
    k = W->size[0];
    if (ii + 1 > k) {
      emlrtDynamicBoundsCheckR2012b(ii + 1, 1, k, &dg_emlrtBCI, &st);
    }
    k = W->size[0];
    if (ii + 1 > k) {
      emlrtDynamicBoundsCheckR2012b(ii + 1, 1, k, &cg_emlrtBCI, &st);
    }
    if (ii + 1 > *indsToExclude_size) {
      emlrtDynamicBoundsCheckR2012b(ii + 1, 1, *indsToExclude_size,
                                    &fg_emlrtBCI, &st);
    }
    indsToExclude_data[ii] = ((Y->codes.data[ii] == 0) || b_b);
  }
  emxInit_int32_T(&st, &Yout, 1, &hd_emlrtRTEI);
  st.site = &wg_emlrtRSI;
  c_ClassificationModel_verifyCla(
      &st, this->ClassNames.codes, this->ClassNames.categoryNames,
      Y->codes.data, Y->codes.size, Y->categoryNames, Y->isOrdinal,
      indsToExclude_data, *indsToExclude_size, Yout);
  Yout_data = Yout->data;
  st.site = &xg_emlrtRSI;
  if (this->PriorDefined) {
    n = Yout->size[0];
    for (ii = 0; ii < n; ii++) {
      if (ii + 1 > *indsToExclude_size) {
        emlrtDynamicBoundsCheckR2012b(ii + 1, 1, *indsToExclude_size,
                                      &le_emlrtBCI, &st);
      }
      if (!indsToExclude_data[ii]) {
        if (ii + 1 > Yout->size[0]) {
          emlrtDynamicBoundsCheckR2012b(ii + 1, 1, Yout->size[0], &ke_emlrtBCI,
                                        &st);
        }
        k = Yout_data[ii];
        if ((k < 1) || (k > 2)) {
          emlrtDynamicBoundsCheckR2012b(k, 1, 2, &me_emlrtBCI, &st);
        }
        if (this->Prior[k - 1] == 0.0) {
          if (ii + 1 > *indsToExclude_size) {
            emlrtDynamicBoundsCheckR2012b(ii + 1, 1, *indsToExclude_size,
                                          &ne_emlrtBCI, &st);
          }
          indsToExclude_data[ii] = true;
        }
      }
    }
  }
  emxFree_int32_T(&st, &Yout);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

void c_ClassificationModel_verifyCla(
    const emlrtStack *sp, const uint8_T this_ClassNames_codes[2],
    const cell_wrap_1 this_ClassNames_categoryNames[2],
    const uint8_T Y_codes_data[], const int32_T Y_codes_size[2],
    const cell_wrap_22 Y_categoryNames[2], boolean_T Y_isOrdinal,
    const boolean_T indsToExclude_data[], int32_T indsToExclude_size,
    emxArray_int32_T *Ynum)
{
  cell_wrap_1 names[3];
  cell_wrap_1 b_b_categoryNames[2];
  cell_wrap_1 b_categoryNames[2];
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  emxArray_cell_wrap_1_4 bnamesout;
  int32_T b_ii;
  int32_T i;
  int32_T i1;
  int32_T i2;
  int32_T i3;
  int32_T ii;
  int32_T loop_ub;
  int32_T *Ynum_data;
  int8_T ib_data[2];
  int8_T ii_data[2];
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  i = Ynum->size[0];
  Ynum->size[0] = Y_codes_size[0];
  emxEnsureCapacity_int32_T(sp, Ynum, i, &w_emlrtRTEI);
  Ynum_data = Ynum->data;
  loop_ub = Y_codes_size[0];
  for (i = 0; i < loop_ub; i++) {
    Ynum_data[i] = 0;
  }
  i = Y_codes_size[0];
  st.site = &y_emlrtRSI;
  emxInitMatrix_cell_wrap_1(sp, b_categoryNames, &fb_emlrtRTEI);
  emxInitMatrix_cell_wrap_11(sp, names, &gb_emlrtRTEI);
  emxInitMatrix_cell_wrap_1(sp, b_b_categoryNames, &hb_emlrtRTEI);
  emxInit_cell_wrap_1_4(&bnamesout);
  for (ii = 0; ii < i; ii++) {
    if (ii + 1 > indsToExclude_size) {
      emlrtDynamicBoundsCheckR2012b(ii + 1, 1, indsToExclude_size, &f_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    if (!indsToExclude_data[ii]) {
      int32_T jj;
      boolean_T classmatch;
      boolean_T exitg1;
      classmatch = false;
      jj = 0;
      exitg1 = false;
      while ((!exitg1) && (jj < 2)) {
        boolean_T t;
        st.site = &ab_emlrtRSI;
        i1 = Y_codes_size[0] * Y_codes_size[1];
        if (ii + 1 > i1) {
          emlrtDynamicBoundsCheckR2012b(ii + 1, 1, i1, &i_emlrtBCI, &st);
        }
        for (i1 = 0; i1 < 2; i1++) {
          i2 = b_b_categoryNames[i1].f1->size[0] *
               b_b_categoryNames[i1].f1->size[1];
          b_b_categoryNames[i1].f1->size[0] = 1;
          loop_ub = Y_categoryNames[i1].f1.size[1];
          b_b_categoryNames[i1].f1->size[1] = loop_ub;
          emxEnsureCapacity_char_T(&st, b_b_categoryNames[i1].f1, i2,
                                   &x_emlrtRTEI);
          for (i2 = 0; i2 < loop_ub; i2++) {
            b_b_categoryNames[i1].f1->data[i2] =
                Y_categoryNames[i1].f1.data[i2];
          }
          if (*emlrtBreakCheckR2012bFlagVar != 0) {
            emlrtBreakCheckR2012b(&st);
          }
        }
        st.site = &ab_emlrtRSI;
        if (this_ClassNames_codes[jj] != 0) {
          if (Y_isOrdinal) {
            t = false;
          } else {
            int32_T idx;
            boolean_T exitg2;
            t = true;
            loop_ub = 0;
            exitg2 = false;
            while ((!exitg2) && (loop_ub < 2)) {
              boolean_T p;
              p = (b_b_categoryNames[loop_ub].f1->size[1] ==
                   this_ClassNames_categoryNames[loop_ub].f1->size[1]);
              if (p && (b_b_categoryNames[loop_ub].f1->size[1] != 0) &&
                  (this_ClassNames_categoryNames[loop_ub].f1->size[1] != 0)) {
                boolean_T exitg3;
                idx = 0;
                exitg3 = false;
                while (
                    (!exitg3) &&
                    (idx <=
                     this_ClassNames_categoryNames[loop_ub].f1->size[1] - 1)) {
                  if (b_b_categoryNames[loop_ub].f1->data[idx] !=
                      this_ClassNames_categoryNames[loop_ub].f1->data[idx]) {
                    p = false;
                    exitg3 = true;
                  } else {
                    idx++;
                  }
                }
              }
              if (!p) {
                t = false;
                exitg2 = true;
              } else {
                loop_ub++;
              }
            }
            if (t) {
              t = (Y_codes_data[ii] == this_ClassNames_codes[jj]);
            } else {
              real_T ia[2];
              real_T d;
              int32_T ii_size_idx_1;
              uint32_T b2a[3];
              uint32_T u;
              boolean_T tf[2];
              boolean_T x[2];
              b_st.site = &cb_emlrtRSI;
              c_st.site = &nb_emlrtRSI;
              cellstr_ismember(&c_st, b_b_categoryNames,
                               this_ClassNames_categoryNames, tf, ia);
              b2a[0] = 0U;
              d = muDoubleScalarRound(ia[0]);
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
              b2a[1] = u;
              d = muDoubleScalarRound(ia[1]);
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
              b2a[2] = u;
              x[0] = !tf[0];
              x[1] = !tf[1];
              idx = 0;
              b_ii = 0;
              exitg2 = false;
              while ((!exitg2) && (b_ii < 2)) {
                if (x[b_ii]) {
                  idx++;
                  ii_data[idx - 1] = (int8_T)(b_ii + 1);
                  if (idx >= 2) {
                    exitg2 = true;
                  } else {
                    b_ii++;
                  }
                } else {
                  b_ii++;
                }
              }
              if (idx < 1) {
                ii_size_idx_1 = 0;
              } else {
                ii_size_idx_1 = idx;
              }
              if (ii_size_idx_1 - 1 >= 0) {
                memcpy(&ib_data[0], &ii_data[0],
                       ii_size_idx_1 * sizeof(int8_T));
              }
              t = true;
              loop_ub = 0;
              exitg2 = false;
              while ((!exitg2) && (loop_ub < 2)) {
                if (!tf[loop_ub]) {
                  t = false;
                  exitg2 = true;
                } else {
                  loop_ub++;
                }
              }
              if (!t) {
                int8_T y_data[24075];
                int8_T tmp_data[2];
                for (i1 = 0; i1 < ii_size_idx_1; i1++) {
                  ii_data[i1] = (int8_T)(ib_data[i1] + 1);
                }
                if (ii_size_idx_1 < 1) {
                  idx = 0;
                } else {
                  idx = ii_size_idx_1;
                  loop_ub = ii_size_idx_1 - 1;
                  for (i1 = 0; i1 <= loop_ub; i1++) {
                    y_data[i1] = (int8_T)(i1 + 1);
                  }
                }
                for (i1 = 0; i1 < idx; i1++) {
                  tmp_data[i1] = (int8_T)(y_data[i1] + 2);
                }
                if (ii_size_idx_1 != idx) {
                  emlrtSubAssignSizeCheck1dR2017a(ii_size_idx_1, idx, &emlrtECI,
                                                  &b_st);
                }
                for (i1 = 0; i1 < idx; i1++) {
                  b2a[ii_data[i1] - 1] = (uint32_T)tmp_data[i1];
                }
                i1 = bnamesout.size[0];
                bnamesout.size[0] = ii_size_idx_1 + 2;
                emxEnsureCapacity_cell_wrap_1(&b_st, bnamesout.data,
                                              ii_size_idx_1 + 2, i1,
                                              &cb_emlrtRTEI);
                i1 = ii_size_idx_1 + 1;
                for (b_ii = 0; b_ii <= i1; b_ii++) {
                  if (b_ii + 1 <= 2) {
                    i2 = bnamesout.data[b_ii].f1->size[0] *
                         bnamesout.data[b_ii].f1->size[1];
                    bnamesout.data[b_ii].f1->size[0] = 1;
                    bnamesout.data[b_ii].f1->size[1] =
                        this_ClassNames_categoryNames[b_ii].f1->size[1];
                    emxEnsureCapacity_char_T(&b_st, bnamesout.data[b_ii].f1, i2,
                                             &db_emlrtRTEI);
                    loop_ub = this_ClassNames_categoryNames[b_ii].f1->size[1];
                    for (i2 = 0; i2 < loop_ub; i2++) {
                      bnamesout.data[b_ii].f1->data[i2] =
                          this_ClassNames_categoryNames[b_ii].f1->data[i2];
                    }
                  } else {
                    if ((b_ii - 1 < 1) || (b_ii - 1 > ii_size_idx_1)) {
                      emlrtDynamicBoundsCheckR2012b(b_ii - 1, 1, ii_size_idx_1,
                                                    &c_emlrtBCI, &b_st);
                    }
                    idx = ib_data[b_ii - 2] - 1;
                    loop_ub = b_b_categoryNames[idx].f1->size[1] - 1;
                    if (b_ii > bnamesout.size[0] - 1) {
                      emlrtDynamicBoundsCheckR2012b(
                          b_ii, 0, bnamesout.size[0] - 1, &g_emlrtBCI, &b_st);
                    }
                    i2 = bnamesout.data[b_ii].f1->size[0] *
                         bnamesout.data[b_ii].f1->size[1];
                    bnamesout.data[b_ii].f1->size[0] = 1;
                    emxEnsureCapacity_char_T(&b_st, bnamesout.data[b_ii].f1, i2,
                                             &eb_emlrtRTEI);
                    if ((b_ii - 1 < 1) || (b_ii - 1 > ii_size_idx_1)) {
                      emlrtDynamicBoundsCheckR2012b(b_ii - 1, 1, ii_size_idx_1,
                                                    &c_emlrtBCI, &b_st);
                    }
                    if (b_ii > bnamesout.size[0] - 1) {
                      emlrtDynamicBoundsCheckR2012b(
                          b_ii, 0, bnamesout.size[0] - 1, &g_emlrtBCI, &b_st);
                    }
                    i2 = bnamesout.data[b_ii].f1->size[0] *
                         bnamesout.data[b_ii].f1->size[1];
                    bnamesout.data[b_ii].f1->size[1] =
                        b_b_categoryNames[idx].f1->size[1];
                    emxEnsureCapacity_char_T(&b_st, bnamesout.data[b_ii].f1, i2,
                                             &eb_emlrtRTEI);
                    i2 = bnamesout.size[0];
                    if (b_ii > bnamesout.size[0] - 1) {
                      emlrtDynamicBoundsCheckR2012b(
                          b_ii, 0, bnamesout.size[0] - 1, &g_emlrtBCI, &b_st);
                    }
                    for (i3 = 0; i3 <= loop_ub; i3++) {
                      if (b_ii > i2 - 1) {
                        emlrtDynamicBoundsCheckR2012b(b_ii, 0, i2 - 1,
                                                      &emlrtBCI, &b_st);
                      }
                      if ((b_ii - 1 < 1) || (b_ii - 1 > ii_size_idx_1)) {
                        emlrtDynamicBoundsCheckR2012b(
                            b_ii - 1, 1, ii_size_idx_1, &b_emlrtBCI, &b_st);
                      }
                      bnamesout.data[b_ii].f1->data[i3] =
                          b_b_categoryNames[idx].f1->data[i3];
                    }
                  }
                }
              }
              i1 = (int32_T)(Y_codes_data[ii] + 1U);
              if ((uint32_T)i1 > 255U) {
                i1 = 255;
              }
              if (i1 > 3) {
                emlrtDynamicBoundsCheckR2012b(i1, 1, 3, &d_emlrtBCI, &b_st);
              }
              t = (b2a[i1 - 1] == this_ClassNames_codes[jj]);
            }
          }
        } else {
          t = false;
        }
        if (t) {
          if (ii + 1 > Ynum->size[0]) {
            emlrtDynamicBoundsCheckR2012b(ii + 1, 1, Ynum->size[0], &e_emlrtBCI,
                                          (emlrtCTX)sp);
          }
          Ynum_data[ii] = jj + 1;
          classmatch = true;
          exitg1 = true;
        } else {
          jj++;
        }
      }
      st.site = &bb_emlrtRSI;
      i1 = Y_codes_size[0] * Y_codes_size[1];
      if (ii + 1 > i1) {
        emlrtDynamicBoundsCheckR2012b(ii + 1, 1, i1, &i_emlrtBCI, &st);
      }
      for (i1 = 0; i1 < 2; i1++) {
        i2 = b_categoryNames[i1].f1->size[0] * b_categoryNames[i1].f1->size[1];
        b_categoryNames[i1].f1->size[0] = 1;
        loop_ub = Y_categoryNames[i1].f1.size[1];
        b_categoryNames[i1].f1->size[1] = loop_ub;
        emxEnsureCapacity_char_T(&st, b_categoryNames[i1].f1, i2, &x_emlrtRTEI);
        for (i2 = 0; i2 < loop_ub; i2++) {
          b_categoryNames[i1].f1->data[i2] = Y_categoryNames[i1].f1.data[i2];
        }
        if (*emlrtBreakCheckR2012bFlagVar != 0) {
          emlrtBreakCheckR2012b(&st);
        }
      }
      st.site = &bb_emlrtRSI;
      i1 = names[0].f1->size[0] * names[0].f1->size[1];
      names[0].f1->size[0] = 1;
      names[0].f1->size[1] = 11;
      emxEnsureCapacity_char_T(&st, names[0].f1, i1, &y_emlrtRTEI);
      for (i1 = 0; i1 < 11; i1++) {
        names[0].f1->data[i1] = cv[i1];
      }
      i1 = names[1].f1->size[0] * names[1].f1->size[1];
      names[1].f1->size[0] = 1;
      names[1].f1->size[1] = b_categoryNames[0].f1->size[1];
      emxEnsureCapacity_char_T(&st, names[1].f1, i1, &ab_emlrtRTEI);
      loop_ub = b_categoryNames[0].f1->size[1];
      for (i1 = 0; i1 < loop_ub; i1++) {
        names[1].f1->data[i1] = b_categoryNames[0].f1->data[i1];
      }
      i1 = names[2].f1->size[0] * names[2].f1->size[1];
      names[2].f1->size[0] = 1;
      names[2].f1->size[1] = b_categoryNames[1].f1->size[1];
      emxEnsureCapacity_char_T(&st, names[2].f1, i1, &ab_emlrtRTEI);
      loop_ub = b_categoryNames[1].f1->size[1];
      for (i1 = 0; i1 < loop_ub; i1++) {
        names[2].f1->data[i1] = b_categoryNames[1].f1->data[i1];
      }
      b_st.site = &gc_emlrtRSI;
      i1 = (int32_T)(Y_codes_data[ii] + 1U);
      i2 = i1;
      if ((uint32_T)i1 > 255U) {
        i2 = 255;
        i1 = 255;
      }
      if (i1 - 1 > 2) {
        emlrtDynamicBoundsCheckR2012b(i1 - 1, 0, 2, &h_emlrtBCI, &b_st);
      }
      if (!classmatch) {
        emlrtErrorWithMessageIdR2018a(
            sp, &d_emlrtRTEI,
            "stats:classreg:learning:internal:classCount:UnknownClass",
            "stats:classreg:learning:internal:classCount:UnknownClass", 6, 4,
            names[i2 - 1].f1->size[1], &names[i2 - 1].f1->data[0], 4, 11,
            "categorical");
      }
    }
  }
  emxFree_cell_wrap_1_4(sp, &bnamesout);
  emxFreeMatrix_cell_wrap_1(sp, b_b_categoryNames);
  emxFreeMatrix_cell_wrap_11(sp, names);
  emxFreeMatrix_cell_wrap_1(sp, b_categoryNames);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

/* End of code generation (ClassificationModel.c) */
