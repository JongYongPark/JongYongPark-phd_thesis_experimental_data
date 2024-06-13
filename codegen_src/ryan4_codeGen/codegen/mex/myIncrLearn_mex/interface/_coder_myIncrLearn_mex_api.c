/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_myIncrLearn_mex_api.c
 *
 * Code generation for function '_coder_myIncrLearn_mex_api'
 *
 */

/* Include files */
#include "_coder_myIncrLearn_mex_api.h"
#include "myFitIncrLearn.h"
#include "myIncrLearn_mex_data.h"
#include "myIncrLearn_mex_emxutil.h"
#include "myIncrLearn_mex_types.h"
#include "myInitialModelIncrLearn.h"
#include "myPredictIncrLearn.h"
#include "myUpdateMetricsIncrLearn.h"
#include "rt_nonfinite.h"

/* Type Definitions */
#ifndef enum_incremental_coderutils_Loss
#define enum_incremental_coderutils_Loss
enum incremental_coderutils_Loss
{
  ClassificationError = 0, /* Default value */
  HingeLoss,
  QuadraticLoss,
  LogitLoss,
  ExponentialLoss,
  BinomialDeviance,
  MeanSquaredError,
  EpsilonInsensitiveLoss
};
#endif /* enum_incremental_coderutils_Loss */
#ifndef typedef_incremental_coderutils_Loss
#define typedef_incremental_coderutils_Loss
typedef enum incremental_coderutils_Loss incremental_coderutils_Loss;
#endif /* typedef_incremental_coderutils_Loss */

#ifndef enum_c_classreg_learning_coderutils_
#define enum_c_classreg_learning_coderutils_
enum c_classreg_learning_coderutils_
{
  Logit = 0, /* Default value */
  Doublelogit,
  Invlogit,
  Ismax,
  Sign,
  Symmetric,
  Symmetricismax,
  Symmetriclogit,
  Identity
};
#endif /* enum_c_classreg_learning_coderutils_ */
#ifndef typedef_c_classreg_learning_coderutils_
#define typedef_c_classreg_learning_coderutils_
typedef enum c_classreg_learning_coderutils_ c_classreg_learning_coderutils_;
#endif /* typedef_c_classreg_learning_coderutils_ */

/* Variable Definitions */
static emlrtRTEInfo gc_emlrtRTEI = {
    1,                            /* lineNo */
    1,                            /* colNo */
    "_coder_myIncrLearn_mex_api", /* fName */
    ""                            /* pName */
};

static const char_T cv1[15] = {'s', 'c', 'a', 'l', 'e', '-', 'i', 'n',
                               'v', 'a', 'r', 'i', 'a', 'n', 't'};

static const char_T *sv[5] = {"codes", "categoryNames", "isProtected",
                              "isOrdinal", "numCategoriesUpperBound"};

static const char_T *sv1[5] = {
    "matlab.internal.coder.categorical", "matlab.internal.coder.categorical",
    "matlab.internal.coder.categorical", "matlab.internal.coder.categorical",
    "matlab.internal.coder.categorical"};

/* Function Declarations */
static void ab_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                const emlrtMsgIdentifier *parentId,
                                char_T y_data[], int32_T y_size[2]);

static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               e_incrementalClassificationLine *y);

static const mxArray *
b_emlrt_marshallOut(const emlrtStack *sp,
                    const e_incrementalClassificationLine *u);

static uint32_T bb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                    const emlrtMsgIdentifier *msgId);

static uint32_T c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                   const emlrtMsgIdentifier *parentId);

static const mxArray *c_emlrt_marshallOut(const uint32_T u);

static boolean_T cb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                     const emlrtMsgIdentifier *msgId);

static boolean_T d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                    const emlrtMsgIdentifier *parentId);

static const mxArray *d_emlrt_marshallOut(const emlrtStack *sp,
                                          const char_T u[6]);

static real_T db_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                  const emlrtMsgIdentifier *msgId);

static struct0_T e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                    const emlrtMsgIdentifier *parentId);

static const mxArray *e_emlrt_marshallOut(const boolean_T u);

static void eb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                const emlrtMsgIdentifier *msgId,
                                real_T ret[400]);

static void emlrt_marshallIn(const emlrtStack *sp,
                             const mxArray *incrementalModel,
                             const char_T *identifier,
                             e_incrementalClassificationLine *y);

static const mxArray *emlrt_marshallOut(const emlrtStack *sp,
                                        const char_T u[15]);

static struct1_T f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                    const emlrtMsgIdentifier *parentId);

static const mxArray *
f_emlrt_marshallOut(const emlrtStack *sp,
                    const incremental_coderutils_Loss u[2]);

static void fb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                const emlrtMsgIdentifier *msgId,
                                real_T ret[200]);

static real_T g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                 const emlrtMsgIdentifier *parentId);

static const mxArray *g_emlrt_marshallOut(const boolean_T u[2]);

static void gb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                const emlrtMsgIdentifier *msgId,
                                uint8_T ret[2]);

static void h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               real_T y[400]);

static const mxArray *h_emlrt_marshallOut(const struct0_T u);

static void hb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                const emlrtMsgIdentifier *msgId,
                                emxArray_char_T *ret);

static void i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               real_T y[200]);

static const mxArray *i_emlrt_marshallOut(const real_T u[400]);

static void ib_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                const emlrtMsgIdentifier *msgId, real_T ret[2]);

static void j_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               categorical *y);

static const mxArray *j_emlrt_marshallOut(const real_T u[200]);

static void jb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                const emlrtMsgIdentifier *msgId,
                                char_T ret[14]);

static void k_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               uint8_T y[2]);

static const mxArray *k_emlrt_marshallOut(const emlrtStack *sp,
                                          const categorical u);

static void kb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                const emlrtMsgIdentifier *msgId,
                                real_T ret[60]);

static void l_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               cell_wrap_1 y[2]);

static const mxArray *l_emlrt_marshallOut(const real_T u[2]);

static void lb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                const emlrtMsgIdentifier *msgId);

static void m_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               emxArray_char_T *y);

static const mxArray *m_emlrt_marshallOut(void);

static void mb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                const emlrtMsgIdentifier *msgId,
                                real_T ret[61]);

static void n_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId, real_T y[2]);

static const mxArray *n_emlrt_marshallOut(const emlrtStack *sp,
                                          const char_T u[14]);

static void nb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                const emlrtMsgIdentifier *msgId,
                                emxArray_real_T *ret);

static void o_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               char_T y[14]);

static const mxArray *
o_emlrt_marshallOut(const emlrtStack *sp,
                    const c_incremental_coder_impl_ScaleI *u);

static void ob_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                const emlrtMsgIdentifier *msgId,
                                uint8_T ret_data[], int32_T ret_size[2]);

static void p_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               c_incremental_coder_impl_ScaleI *y);

static const mxArray *p_emlrt_marshallOut(const real_T u[60]);

static void pb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                const emlrtMsgIdentifier *msgId,
                                char_T ret_data[], int32_T ret_size[2]);

static void q_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               real_T y[60]);

static const mxArray *q_emlrt_marshallOut(const real_T u[61]);

static void r_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId);

static const mxArray *r_emlrt_marshallOut(const emlrtStack *sp,
                                          const b_categorical u);

static void s_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               real_T y[61]);

static const mxArray *s_emlrt_marshallOut(const emxArray_real_T *u);

static void t_emlrt_marshallIn(const emlrtStack *sp, const mxArray *X,
                               const char_T *identifier, emxArray_real_T *y);

static const mxArray *t_emlrt_marshallOut(void);

static void u_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               emxArray_real_T *y);

static const mxArray *u_emlrt_marshallOut(void);

static void v_emlrt_marshallIn(const emlrtStack *sp, const mxArray *Y,
                               const char_T *identifier, c_categorical *y);

static const mxArray *v_emlrt_marshallOut(const emlrtStack *sp);

static void w_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               c_categorical *y);

static const mxArray *w_emlrt_marshallOut(const emlrtStack *sp);

static void x_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               uint8_T y_data[], int32_T y_size[2]);

static void y_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               cell_wrap_22 y[2]);

/* Function Definitions */
static void ab_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                const emlrtMsgIdentifier *parentId,
                                char_T y_data[], int32_T y_size[2])
{
  pb_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y_data, y_size);
  emlrtDestroyArray(&u);
}

static void b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               e_incrementalClassificationLine *y)
{
  emlrtMsgIdentifier thisId;
  const mxArray *propValues[16];
  int32_T i;
  const char_T *propClasses[16] = {
      "incremental.coder.Learner",
      "incremental.coder.Learner",
      "incremental.coder.Learner",
      "incremental.coder.Learner",
      "incremental.coder.Learner",
      "incremental.coder.Learner",
      "incremental.coder.Learner",
      "incremental.coder.classif.ClassificationModel",
      "incremental.coder.classif.ClassificationModel",
      "incremental.coder.classif.ClassificationModel",
      "incremental.coder.classif.ClassificationModel",
      "incremental.coder.classif.ClassificationModel",
      "incremental.coder.classif.ClassificationModel",
      "incremental.coder.Estimator",
      "incremental.coder.Estimator",
      "incremental.coder.Linear"};
  const char_T *propNames[16] = {"NumTrainingObservations",
                                 "IsWarm",
                                 "Metrics",
                                 "MetricBuffer",
                                 "WeightBuffer",
                                 "BufferSize",
                                 "NumMetricObservations",
                                 "ClassNames",
                                 "Prior",
                                 "CharClassNames",
                                 "WeightsPerClass",
                                 "PriorDefined",
                                 "PriorReset",
                                 "NumEstimationObservations",
                                 "parametersAdjusted",
                                 "Impl"};
  for (i = 0; i < 16; i++) {
    propValues[i] = NULL;
  }
  thisId.fParent = parentId;
  thisId.bParentIsCell = false;
  emlrtCheckMcosClass2017a((emlrtCTX)sp, parentId, u,
                           (const char_T *)"incrementalClassificationLinear");
  emlrtAssign(
      &u,
      emlrtConvertInstanceToRedirectTarget(
          (emlrtCTX)sp, u, 0,
          (const char_T *)"incremental.coder.incrementalClassificationLinear"));
  emlrtCheckMcosClass2017a(
      (emlrtCTX)sp, parentId, u,
      (const char_T *)"incremental.coder.incrementalClassificationLinear");
  emlrtGetAllProperties((emlrtCTX)sp, u, 0, 16, (const char_T **)&propNames[0],
                        (const char_T **)&propClasses[0], &propValues[0]);
  thisId.fIdentifier = "NumTrainingObservations";
  y->NumTrainingObservations =
      c_emlrt_marshallIn(sp, emlrtAlias(propValues[0]), &thisId);
  thisId.fIdentifier = "IsWarm";
  y->IsWarm = d_emlrt_marshallIn(sp, emlrtAlias(propValues[1]), &thisId);
  thisId.fIdentifier = "Metrics";
  y->Metrics = e_emlrt_marshallIn(sp, emlrtAlias(propValues[2]), &thisId);
  thisId.fIdentifier = "MetricBuffer";
  h_emlrt_marshallIn(sp, emlrtAlias(propValues[3]), &thisId, y->MetricBuffer);
  thisId.fIdentifier = "WeightBuffer";
  i_emlrt_marshallIn(sp, emlrtAlias(propValues[4]), &thisId, y->WeightBuffer);
  thisId.fIdentifier = "BufferSize";
  y->BufferSize = c_emlrt_marshallIn(sp, emlrtAlias(propValues[5]), &thisId);
  thisId.fIdentifier = "NumMetricObservations";
  y->NumMetricObservations =
      c_emlrt_marshallIn(sp, emlrtAlias(propValues[6]), &thisId);
  thisId.fIdentifier = "ClassNames";
  j_emlrt_marshallIn(sp, emlrtAlias(propValues[7]), &thisId, &y->ClassNames);
  thisId.fIdentifier = "Prior";
  n_emlrt_marshallIn(sp, emlrtAlias(propValues[8]), &thisId, y->Prior);
  thisId.fIdentifier = "CharClassNames";
  o_emlrt_marshallIn(sp, emlrtAlias(propValues[9]), &thisId, y->CharClassNames);
  thisId.fIdentifier = "WeightsPerClass";
  n_emlrt_marshallIn(sp, emlrtAlias(propValues[10]), &thisId,
                     y->WeightsPerClass);
  thisId.fIdentifier = "PriorDefined";
  y->PriorDefined = d_emlrt_marshallIn(sp, emlrtAlias(propValues[11]), &thisId);
  thisId.fIdentifier = "PriorReset";
  y->PriorReset = d_emlrt_marshallIn(sp, emlrtAlias(propValues[12]), &thisId);
  thisId.fIdentifier = "NumEstimationObservations";
  y->NumEstimationObservations =
      c_emlrt_marshallIn(sp, emlrtAlias(propValues[13]), &thisId);
  thisId.fIdentifier = "parametersAdjusted";
  y->parametersAdjusted =
      d_emlrt_marshallIn(sp, emlrtAlias(propValues[14]), &thisId);
  thisId.fIdentifier = "Impl";
  p_emlrt_marshallIn(sp, emlrtAlias(propValues[15]), &thisId, &y->Impl);
  emlrtDestroyArrays(16, &propValues[0]);
  emlrtDestroyArray(&u);
}

static const mxArray *
b_emlrt_marshallOut(const emlrtStack *sp,
                    const e_incrementalClassificationLine *u)
{
  static const int32_T iv1[2] = {0, 0};
  static const int32_T iv2[2] = {0, 0};
  static const int32_T iv3[2] = {0, 0};
  static const int32_T iv4[2] = {0, 0};
  static const char_T b_cv[6] = {'d', 'o', 'u', 'b', 'l', 'e'};
  const mxArray *propValues[44];
  const mxArray *b_y;
  const mxArray *c_y;
  const mxArray *d_y;
  const mxArray *e_y;
  const mxArray *f_y;
  const mxArray *g_y;
  const mxArray *h_y;
  const mxArray *m;
  const mxArray *m1;
  const mxArray *m10;
  const mxArray *m11;
  const mxArray *m12;
  const mxArray *m13;
  const mxArray *m14;
  const mxArray *m15;
  const mxArray *m16;
  const mxArray *m17;
  const mxArray *m18;
  const mxArray *m19;
  const mxArray *m2;
  const mxArray *m20;
  const mxArray *m21;
  const mxArray *m22;
  const mxArray *m23;
  const mxArray *m24;
  const mxArray *m25;
  const mxArray *m26;
  const mxArray *m27;
  const mxArray *m28;
  const mxArray *m29;
  const mxArray *m3;
  const mxArray *m30;
  const mxArray *m31;
  const mxArray *m32;
  const mxArray *m33;
  const mxArray *m34;
  const mxArray *m35;
  const mxArray *m36;
  const mxArray *m37;
  const mxArray *m38;
  const mxArray *m39;
  const mxArray *m4;
  const mxArray *m40;
  const mxArray *m41;
  const mxArray *m42;
  const mxArray *m43;
  const mxArray *m44;
  const mxArray *m5;
  const mxArray *m6;
  const mxArray *m7;
  const mxArray *m8;
  const mxArray *m9;
  const mxArray *y;
  int32_T iv[2];
  const char_T *propClasses[44] = {
      "incremental.coder.Learner",
      "incremental.coder.Learner",
      "incremental.coder.Learner",
      "incremental.coder.Learner",
      "incremental.coder.Learner",
      "incremental.coder.Learner",
      "incremental.coder.Learner",
      "incremental.coder.Learner",
      "incremental.coder.Learner",
      "incremental.coder.Learner",
      "incremental.coder.Learner",
      "incremental.coder.Learner",
      "incremental.coder.Learner",
      "incremental.coder.Learner",
      "incremental.coder.Learner",
      "incremental.coder.Learner",
      "incremental.coder.Learner",
      "incremental.coder.classif.ClassificationModel",
      "incremental.coder.classif.ClassificationModel",
      "incremental.coder.classif.ClassificationModel",
      "incremental.coder.classif.ClassificationModel",
      "incremental.coder.classif.ClassificationModel",
      "incremental.coder.classif.ClassificationModel",
      "incremental.coder.classif.ClassificationModel",
      "incremental.coder.classif.ClassificationModel",
      "incremental.coder.classif.ClassificationModel",
      "incremental.coder.classif.ClassificationModel",
      "incremental.coder.classif.ClassificationModel",
      "incremental.coder.classif.ClassificationModel",
      "incremental.coder.classif.ClassificationModel",
      "incremental.coder.classif.ClassificationModel",
      "incremental.coder.classif.ClassificationModel",
      "incremental.coder.classif.ClassificationModel",
      "incremental.coder.classif.ClassificationModel",
      "incremental.coder.classif.ClassificationModel",
      "incremental.coder.Estimator",
      "incremental.coder.Estimator",
      "incremental.coder.Estimator",
      "incremental.coder.Linear",
      "incremental.coder.Linear",
      "incremental.coder.Linear",
      "incremental.coder.incrementalClassificationLinear",
      "incremental.coder.incrementalClassificationLinear",
      "incremental.coder.incrementalClassificationLinear"};
  const char_T *propNames[44] = {"NumPredictors",
                                 "NumTrainingObservations",
                                 "PredictorClass",
                                 "PredictorClassFixed",
                                 "CustomMetricsFun",
                                 "BuiltInMetricsFun",
                                 "BuiltInMetrics",
                                 "EstimatorNeeded",
                                 "WisRaw",
                                 "MetricsWarmupPeriod",
                                 "MetricsWindowSize",
                                 "IsWarm",
                                 "Metrics",
                                 "MetricBuffer",
                                 "WeightBuffer",
                                 "BufferSize",
                                 "NumMetricObservations",
                                 "ClassNames",
                                 "Prior",
                                 "ClassType",
                                 "ClassNamesLength",
                                 "MaxNumClasses",
                                 "Cost",
                                 "CharClassNames",
                                 "ScoreTransform",
                                 "CustomScoreTransform",
                                 "AllowedClassifMetrics",
                                 "IgnoreXNaNs",
                                 "WeightsPerClass",
                                 "IsOrdinal",
                                 "IsBinary",
                                 "IsAdaptive",
                                 "PriorisState",
                                 "PriorDefined",
                                 "PriorReset",
                                 "EstimationPeriod",
                                 "NumEstimationObservations",
                                 "parametersAdjusted",
                                 "Mode",
                                 "Impl",
                                 "Solver",
                                 "fitPosterior",
                                 "ScoreTransformArguments",
                                 "ScoreTransformArgumentsNum"};
  boolean_T bv[2];
  incremental_coderutils_Loss rv[2];
  y = NULL;
  m = NULL;
  m1 = NULL;
  m2 = NULL;
  m3 = NULL;
  m4 = NULL;
  m5 = NULL;
  m6 = NULL;
  m7 = NULL;
  m8 = NULL;
  m9 = NULL;
  m10 = NULL;
  m11 = NULL;
  m12 = NULL;
  m13 = NULL;
  m14 = NULL;
  m15 = NULL;
  m16 = NULL;
  m17 = NULL;
  m18 = NULL;
  m19 = NULL;
  m20 = NULL;
  m21 = NULL;
  m22 = NULL;
  m23 = NULL;
  m24 = NULL;
  m25 = NULL;
  m26 = NULL;
  m27 = NULL;
  m28 = NULL;
  m29 = NULL;
  m30 = NULL;
  m31 = NULL;
  m32 = NULL;
  m33 = NULL;
  m34 = NULL;
  m35 = NULL;
  m36 = NULL;
  m37 = NULL;
  m38 = NULL;
  m39 = NULL;
  m40 = NULL;
  m41 = NULL;
  m42 = NULL;
  m43 = NULL;
  emlrtAssign(
      &y,
      emlrtCreateClassInstance2022a(
          (emlrtCTX)sp,
          (const char_T *)"incremental.coder.incrementalClassificationLinear"));
  m = NULL;
  emlrtAssign(&m, c_emlrt_marshallOut(60U));
  propValues[0] = m;
  m1 = NULL;
  emlrtAssign(&m1, c_emlrt_marshallOut(u->NumTrainingObservations));
  propValues[1] = m1;
  m2 = NULL;
  emlrtAssign(&m2, d_emlrt_marshallOut(sp, b_cv));
  propValues[2] = m2;
  m3 = NULL;
  emlrtAssign(&m3, e_emlrt_marshallOut(false));
  propValues[3] = m3;
  m4 = NULL;
  b_y = NULL;
  iv[0] = 0;
  iv[1] = 0;
  emlrtAssign(&b_y, emlrtCreateCellArrayR2014a(2, &iv[0]));
  emlrtAssign(&m4, b_y);
  propValues[4] = m4;
  rv[0] = ClassificationError;
  rv[1] = HingeLoss;
  m5 = NULL;
  emlrtAssign(&m5, f_emlrt_marshallOut(sp, rv));
  propValues[5] = m5;
  m6 = NULL;
  bv[0] = true;
  bv[1] = true;
  emlrtAssign(&m6, g_emlrt_marshallOut(bv));
  propValues[6] = m6;
  m7 = NULL;
  emlrtAssign(&m7, e_emlrt_marshallOut(false));
  propValues[7] = m7;
  m8 = NULL;
  emlrtAssign(&m8, e_emlrt_marshallOut(true));
  propValues[8] = m8;
  m9 = NULL;
  emlrtAssign(&m9, c_emlrt_marshallOut(1000U));
  propValues[9] = m9;
  m10 = NULL;
  emlrtAssign(&m10, c_emlrt_marshallOut(200U));
  propValues[10] = m10;
  m11 = NULL;
  emlrtAssign(&m11, e_emlrt_marshallOut(u->IsWarm));
  propValues[11] = m11;
  m12 = NULL;
  emlrtAssign(&m12, h_emlrt_marshallOut(u->Metrics));
  propValues[12] = m12;
  m13 = NULL;
  emlrtAssign(&m13, i_emlrt_marshallOut(u->MetricBuffer));
  propValues[13] = m13;
  m14 = NULL;
  emlrtAssign(&m14, j_emlrt_marshallOut(u->WeightBuffer));
  propValues[14] = m14;
  m15 = NULL;
  emlrtAssign(&m15, c_emlrt_marshallOut(u->BufferSize));
  propValues[15] = m15;
  m16 = NULL;
  emlrtAssign(&m16, c_emlrt_marshallOut(u->NumMetricObservations));
  propValues[16] = m16;
  m17 = NULL;
  emlrtAssign(&m17, k_emlrt_marshallOut(sp, u->ClassNames));
  propValues[17] = m17;
  m18 = NULL;
  emlrtAssign(&m18, l_emlrt_marshallOut(u->Prior));
  propValues[18] = m18;
  m19 = NULL;
  emlrtAssign(&m19, t_emlrt_marshallOut());
  propValues[19] = m19;
  m20 = NULL;
  emlrtAssign(&m20, u_emlrt_marshallOut());
  propValues[20] = m20;
  m21 = NULL;
  c_y = NULL;
  m44 = emlrtCreateDoubleScalar(2.0);
  emlrtAssign(&c_y, m44);
  emlrtAssign(&m21, c_y);
  propValues[21] = m21;
  m22 = NULL;
  d_y = NULL;
  m44 =
      emlrtCreateNumericArray(2, (const void *)&iv1[0], mxDOUBLE_CLASS, mxREAL);
  emlrtAssign(&d_y, m44);
  emlrtAssign(&m22, d_y);
  propValues[22] = m22;
  m23 = NULL;
  emlrtAssign(&m23, n_emlrt_marshallOut(sp, u->CharClassNames));
  propValues[23] = m23;
  m24 = NULL;
  emlrtAssign(&m24, w_emlrt_marshallOut(sp));
  propValues[24] = m24;
  m25 = NULL;
  emlrtAssign(&m25, e_emlrt_marshallOut(false));
  propValues[25] = m25;
  m26 = NULL;
  emlrtAssign(&m26, v_emlrt_marshallOut(sp));
  propValues[26] = m26;
  m27 = NULL;
  emlrtAssign(&m27, e_emlrt_marshallOut(false));
  propValues[27] = m27;
  m28 = NULL;
  emlrtAssign(&m28, l_emlrt_marshallOut(u->WeightsPerClass));
  propValues[28] = m28;
  m29 = NULL;
  emlrtAssign(&m29, e_emlrt_marshallOut(false));
  propValues[29] = m29;
  m30 = NULL;
  emlrtAssign(&m30, e_emlrt_marshallOut(true));
  propValues[30] = m30;
  m31 = NULL;
  emlrtAssign(&m31, e_emlrt_marshallOut(false));
  propValues[31] = m31;
  m32 = NULL;
  emlrtAssign(&m32, e_emlrt_marshallOut(true));
  propValues[32] = m32;
  m33 = NULL;
  emlrtAssign(&m33, e_emlrt_marshallOut(u->PriorDefined));
  propValues[33] = m33;
  m34 = NULL;
  emlrtAssign(&m34, e_emlrt_marshallOut(u->PriorReset));
  propValues[34] = m34;
  m35 = NULL;
  emlrtAssign(&m35, c_emlrt_marshallOut(0U));
  propValues[35] = m35;
  m36 = NULL;
  emlrtAssign(&m36, c_emlrt_marshallOut(u->NumEstimationObservations));
  propValues[36] = m36;
  m37 = NULL;
  emlrtAssign(&m37, e_emlrt_marshallOut(u->parametersAdjusted));
  propValues[37] = m37;
  m38 = NULL;
  e_y = NULL;
  m44 = emlrtCreateDoubleScalar(2.0);
  emlrtAssign(&e_y, m44);
  emlrtAssign(&m38, e_y);
  propValues[38] = m38;
  m39 = NULL;
  emlrtAssign(&m39, o_emlrt_marshallOut(sp, &u->Impl));
  propValues[39] = m39;
  m40 = NULL;
  emlrtAssign(&m40, emlrt_marshallOut(sp, cv1));
  propValues[40] = m40;
  m41 = NULL;
  f_y = NULL;
  m44 =
      emlrtCreateNumericArray(2, (const void *)&iv2[0], mxDOUBLE_CLASS, mxREAL);
  emlrtAssign(&f_y, m44);
  emlrtAssign(&m41, f_y);
  propValues[41] = m41;
  m42 = NULL;
  g_y = NULL;
  m44 =
      emlrtCreateNumericArray(2, (const void *)&iv3[0], mxDOUBLE_CLASS, mxREAL);
  emlrtAssign(&g_y, m44);
  emlrtAssign(&m42, g_y);
  propValues[42] = m42;
  m43 = NULL;
  h_y = NULL;
  m44 =
      emlrtCreateNumericArray(2, (const void *)&iv4[0], mxDOUBLE_CLASS, mxREAL);
  emlrtAssign(&h_y, m44);
  emlrtAssign(&m43, h_y);
  propValues[43] = m43;
  emlrtSetAllProperties((emlrtCTX)sp, &y, 0, 44, (const char_T **)&propNames[0],
                        (const char_T **)&propClasses[0], &propValues[0]);
  emlrtAssign(
      &y,
      emlrtConvertInstanceToRedirectSource(
          (emlrtCTX)sp, y, 0,
          (const char_T *)"incremental.coder.incrementalClassificationLinear"));
  return y;
}

static uint32_T bb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                    const emlrtMsgIdentifier *msgId)
{
  static const int32_T dims = 0;
  uint32_T ret;
  emlrtCheckBuiltInR2012b((emlrtCTX)sp, msgId, src, (const char_T *)"uint32",
                          false, 0U, (void *)&dims);
  ret = *(uint32_T *)emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

static uint32_T c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                   const emlrtMsgIdentifier *parentId)
{
  uint32_T y;
  y = bb_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static const mxArray *c_emlrt_marshallOut(const uint32_T u)
{
  const mxArray *m;
  const mxArray *y;
  y = NULL;
  m = emlrtCreateNumericMatrix(1, 1, mxUINT32_CLASS, mxREAL);
  *(uint32_T *)emlrtMxGetData(m) = u;
  emlrtAssign(&y, m);
  return y;
}

static boolean_T cb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                     const emlrtMsgIdentifier *msgId)
{
  static const int32_T dims = 0;
  boolean_T ret;
  emlrtCheckBuiltInR2012b((emlrtCTX)sp, msgId, src, (const char_T *)"logical",
                          false, 0U, (void *)&dims);
  ret = *emlrtMxGetLogicals(src);
  emlrtDestroyArray(&src);
  return ret;
}

static boolean_T d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                    const emlrtMsgIdentifier *parentId)
{
  boolean_T y;
  y = cb_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static const mxArray *d_emlrt_marshallOut(const emlrtStack *sp,
                                          const char_T u[6])
{
  static const int32_T iv[2] = {1, 6};
  const mxArray *m;
  const mxArray *y;
  y = NULL;
  m = emlrtCreateCharArray(2, &iv[0]);
  emlrtInitCharArrayR2013a((emlrtCTX)sp, 6, m, &u[0]);
  emlrtAssign(&y, m);
  return y;
}

static real_T db_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                  const emlrtMsgIdentifier *msgId)
{
  static const int32_T dims = 0;
  real_T ret;
  emlrtCheckBuiltInR2012b((emlrtCTX)sp, msgId, src, (const char_T *)"double",
                          false, 0U, (void *)&dims);
  ret = *(real_T *)emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

static struct0_T e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                    const emlrtMsgIdentifier *parentId)
{
  static const int32_T dims = 0;
  static const char_T *fieldNames[2] = {"ClassificationError", "HingeLoss"};
  emlrtMsgIdentifier thisId;
  struct0_T y;
  thisId.fParent = parentId;
  thisId.bParentIsCell = false;
  emlrtCheckStructR2012b((emlrtCTX)sp, parentId, u, 2,
                         (const char_T **)&fieldNames[0], 0U, (void *)&dims);
  thisId.fIdentifier = "ClassificationError";
  y.ClassificationError = f_emlrt_marshallIn(
      sp,
      emlrtAlias(emlrtGetFieldR2017b((emlrtCTX)sp, u, 0, 0,
                                     (const char_T *)"ClassificationError")),
      &thisId);
  thisId.fIdentifier = "HingeLoss";
  y.HingeLoss = f_emlrt_marshallIn(
      sp,
      emlrtAlias(emlrtGetFieldR2017b((emlrtCTX)sp, u, 0, 1,
                                     (const char_T *)"HingeLoss")),
      &thisId);
  emlrtDestroyArray(&u);
  return y;
}

static const mxArray *e_emlrt_marshallOut(const boolean_T u)
{
  const mxArray *m;
  const mxArray *y;
  y = NULL;
  m = emlrtCreateLogicalScalar(u);
  emlrtAssign(&y, m);
  return y;
}

static void eb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                const emlrtMsgIdentifier *msgId,
                                real_T ret[400])
{
  static const int32_T dims[2] = {200, 2};
  real_T(*r)[400];
  int32_T i;
  emlrtCheckBuiltInR2012b((emlrtCTX)sp, msgId, src, (const char_T *)"double",
                          false, 2U, (void *)&dims[0]);
  r = (real_T(*)[400])emlrtMxGetData(src);
  for (i = 0; i < 400; i++) {
    ret[i] = (*r)[i];
  }
  emlrtDestroyArray(&src);
}

static void emlrt_marshallIn(const emlrtStack *sp,
                             const mxArray *incrementalModel,
                             const char_T *identifier,
                             e_incrementalClassificationLine *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  b_emlrt_marshallIn(sp, emlrtAlias(incrementalModel), &thisId, y);
  emlrtDestroyArray(&incrementalModel);
}

static const mxArray *emlrt_marshallOut(const emlrtStack *sp,
                                        const char_T u[15])
{
  static const int32_T iv[2] = {1, 15};
  const mxArray *m;
  const mxArray *y;
  y = NULL;
  m = emlrtCreateCharArray(2, &iv[0]);
  emlrtInitCharArrayR2013a((emlrtCTX)sp, 15, m, &u[0]);
  emlrtAssign(&y, m);
  return y;
}

static struct1_T f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                    const emlrtMsgIdentifier *parentId)
{
  static const int32_T dims = 0;
  static const char_T *fieldNames[2] = {"Cumulative", "Window"};
  emlrtMsgIdentifier thisId;
  struct1_T y;
  thisId.fParent = parentId;
  thisId.bParentIsCell = false;
  emlrtCheckStructR2012b((emlrtCTX)sp, parentId, u, 2,
                         (const char_T **)&fieldNames[0], 0U, (void *)&dims);
  thisId.fIdentifier = "Cumulative";
  y.Cumulative = g_emlrt_marshallIn(
      sp,
      emlrtAlias(emlrtGetFieldR2017b((emlrtCTX)sp, u, 0, 0,
                                     (const char_T *)"Cumulative")),
      &thisId);
  thisId.fIdentifier = "Window";
  y.Window =
      g_emlrt_marshallIn(sp,
                         emlrtAlias(emlrtGetFieldR2017b(
                             (emlrtCTX)sp, u, 0, 1, (const char_T *)"Window")),
                         &thisId);
  emlrtDestroyArray(&u);
  return y;
}

static const mxArray *
f_emlrt_marshallOut(const emlrtStack *sp,
                    const incremental_coderutils_Loss u[2])
{
  static const int32_T enumValues[8] = {0, 1, 2, 3, 4, 5, 6, 7};
  static const char_T *enumNames[8] = {
      "ClassificationError", "HingeLoss",
      "QuadraticLoss",       "LogitLoss",
      "ExponentialLoss",     "BinomialDeviance",
      "MeanSquaredError",    "EpsilonInsensitiveLoss"};
  const mxArray *b_y;
  const mxArray *c_y;
  const mxArray *m;
  const mxArray *m1;
  const mxArray *y;
  int32_T iv[2];
  y = NULL;
  iv[0] = 1;
  iv[1] = 2;
  emlrtAssign(&y, emlrtCreateCellArrayR2014a(2, &iv[0]));
  b_y = NULL;
  m = NULL;
  emlrtCheckEnumR2012b((emlrtCTX)sp,
                       (const char_T *)"incremental.coderutils.Loss", 8,
                       (const char_T **)&enumNames[0], &enumValues[0]);
  c_y = NULL;
  m1 = emlrtCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
  *(int32_T *)emlrtMxGetData(m1) = (int32_T)u[0];
  emlrtAssign(&c_y, m1);
  emlrtAssign(&m, c_y);
  emlrtAssign(&b_y, emlrtCreateEnumR2012b(
                        (emlrtCTX)sp,
                        (const char_T *)"incremental.coderutils.Loss", m));
  emlrtDestroyArray(&m);
  emlrtSetCell(y, 0, b_y);
  b_y = NULL;
  m = NULL;
  emlrtCheckEnumR2012b((emlrtCTX)sp,
                       (const char_T *)"incremental.coderutils.Loss", 8,
                       (const char_T **)&enumNames[0], &enumValues[0]);
  c_y = NULL;
  m1 = emlrtCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
  *(int32_T *)emlrtMxGetData(m1) = (int32_T)u[1];
  emlrtAssign(&c_y, m1);
  emlrtAssign(&m, c_y);
  emlrtAssign(&b_y, emlrtCreateEnumR2012b(
                        (emlrtCTX)sp,
                        (const char_T *)"incremental.coderutils.Loss", m));
  emlrtDestroyArray(&m);
  emlrtSetCell(y, 1, b_y);
  return y;
}

static void fb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                const emlrtMsgIdentifier *msgId,
                                real_T ret[200])
{
  static const int32_T dims = 200;
  real_T(*r)[200];
  int32_T i;
  emlrtCheckBuiltInR2012b((emlrtCTX)sp, msgId, src, (const char_T *)"double",
                          false, 1U, (void *)&dims);
  r = (real_T(*)[200])emlrtMxGetData(src);
  for (i = 0; i < 200; i++) {
    ret[i] = (*r)[i];
  }
  emlrtDestroyArray(&src);
}

static real_T g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                 const emlrtMsgIdentifier *parentId)
{
  real_T y;
  y = db_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static const mxArray *g_emlrt_marshallOut(const boolean_T u[2])
{
  static const int32_T i = 2;
  const mxArray *m;
  const mxArray *y;
  y = NULL;
  m = emlrtCreateLogicalArray(1, &i);
  emlrtInitLogicalArray(2, m, &u[0]);
  emlrtAssign(&y, m);
  return y;
}

static void gb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                const emlrtMsgIdentifier *msgId, uint8_T ret[2])
{
  static const int32_T dims = 2;
  uint8_T(*r)[2];
  emlrtCheckBuiltInR2012b((emlrtCTX)sp, msgId, src, (const char_T *)"uint8",
                          false, 1U, (void *)&dims);
  r = (uint8_T(*)[2])emlrtMxGetData(src);
  ret[0] = (*r)[0];
  ret[1] = (*r)[1];
  emlrtDestroyArray(&src);
}

static void h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               real_T y[400])
{
  eb_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static const mxArray *h_emlrt_marshallOut(const struct0_T u)
{
  static const char_T *b_sv[2] = {"ClassificationError", "HingeLoss"};
  static const char_T *b_sv1[2] = {"Cumulative", "Window"};
  const mxArray *b_y;
  const mxArray *c_y;
  const mxArray *d_y;
  const mxArray *e_y;
  const mxArray *f_y;
  const mxArray *g_y;
  const mxArray *m;
  const mxArray *y;
  y = NULL;
  emlrtAssign(&y, emlrtCreateStructMatrix(1, 1, 2, (const char_T **)&b_sv[0]));
  b_y = NULL;
  emlrtAssign(&b_y,
              emlrtCreateStructMatrix(1, 1, 2, (const char_T **)&b_sv1[0]));
  c_y = NULL;
  m = emlrtCreateDoubleScalar(u.ClassificationError.Cumulative);
  emlrtAssign(&c_y, m);
  emlrtSetFieldR2017b(b_y, 0, (const char_T *)"Cumulative", c_y, 0);
  d_y = NULL;
  m = emlrtCreateDoubleScalar(u.ClassificationError.Window);
  emlrtAssign(&d_y, m);
  emlrtSetFieldR2017b(b_y, 0, (const char_T *)"Window", d_y, 1);
  emlrtSetFieldR2017b(y, 0, (const char_T *)"ClassificationError", b_y, 0);
  e_y = NULL;
  emlrtAssign(&e_y,
              emlrtCreateStructMatrix(1, 1, 2, (const char_T **)&b_sv1[0]));
  f_y = NULL;
  m = emlrtCreateDoubleScalar(u.HingeLoss.Cumulative);
  emlrtAssign(&f_y, m);
  emlrtSetFieldR2017b(e_y, 0, (const char_T *)"Cumulative", f_y, 0);
  g_y = NULL;
  m = emlrtCreateDoubleScalar(u.HingeLoss.Window);
  emlrtAssign(&g_y, m);
  emlrtSetFieldR2017b(e_y, 0, (const char_T *)"Window", g_y, 1);
  emlrtSetFieldR2017b(y, 0, (const char_T *)"HingeLoss", e_y, 1);
  return y;
}

static void hb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                const emlrtMsgIdentifier *msgId,
                                emxArray_char_T *ret)
{
  static const int32_T dims[2] = {1, -1};
  int32_T iv[2];
  int32_T i;
  char_T *ret_data;
  const boolean_T bv[2] = {false, true};
  emlrtCheckVsBuiltInR2012b((emlrtCTX)sp, msgId, src, (const char_T *)"char",
                            false, 2U, (void *)&dims[0], &bv[0], &iv[0]);
  i = ret->size[0] * ret->size[1];
  ret->size[0] = iv[0];
  ret->size[1] = iv[1];
  emxEnsureCapacity_char_T(sp, ret, i, (emlrtRTEInfo *)NULL);
  ret_data = ret->data;
  emlrtImportArrayR2015b((emlrtCTX)sp, src, &ret_data[0], 1, false);
  emlrtDestroyArray(&src);
}

static void i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               real_T y[200])
{
  fb_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static const mxArray *i_emlrt_marshallOut(const real_T u[400])
{
  static const int32_T iv[2] = {200, 2};
  const mxArray *m;
  const mxArray *y;
  real_T *pData;
  int32_T b_i;
  int32_T c_i;
  int32_T i;
  y = NULL;
  m = emlrtCreateNumericArray(2, (const void *)&iv[0], mxDOUBLE_CLASS, mxREAL);
  pData = emlrtMxGetPr(m);
  i = 0;
  for (b_i = 0; b_i < 2; b_i++) {
    for (c_i = 0; c_i < 200; c_i++) {
      pData[i + c_i] = u[c_i + 200 * b_i];
    }
    i += 200;
  }
  emlrtAssign(&y, m);
  return y;
}

static void ib_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                const emlrtMsgIdentifier *msgId, real_T ret[2])
{
  static const int32_T dims[2] = {1, 2};
  real_T(*r)[2];
  emlrtCheckBuiltInR2012b((emlrtCTX)sp, msgId, src, (const char_T *)"double",
                          false, 2U, (void *)&dims[0]);
  r = (real_T(*)[2])emlrtMxGetData(src);
  ret[0] = (*r)[0];
  ret[1] = (*r)[1];
  emlrtDestroyArray(&src);
}

static void j_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               categorical *y)
{
  emlrtMsgIdentifier thisId;
  const mxArray *propValues[2];
  const char_T *propClasses[2] = {"matlab.internal.coder.categorical",
                                  "matlab.internal.coder.categorical"};
  const char_T *propNames[2] = {"codes", "categoryNames"};
  propValues[0] = NULL;
  propValues[1] = NULL;
  thisId.fParent = parentId;
  thisId.bParentIsCell = false;
  emlrtCheckMcosClass2017a((emlrtCTX)sp, parentId, u,
                           (const char_T *)"categorical");
  emlrtAssign(&u, emlrtConvertInstanceToRedirectTarget(
                      (emlrtCTX)sp, u, 0,
                      (const char_T *)"matlab.internal.coder.categorical"));
  emlrtCheckMcosClass2017a((emlrtCTX)sp, parentId, u,
                           (const char_T *)"matlab.internal.coder.categorical");
  emlrtGetAllProperties((emlrtCTX)sp, u, 0, 2, (const char_T **)&propNames[0],
                        (const char_T **)&propClasses[0], &propValues[0]);
  thisId.fIdentifier = "codes";
  k_emlrt_marshallIn(sp, emlrtAlias(propValues[0]), &thisId, y->codes);
  thisId.fIdentifier = "categoryNames";
  l_emlrt_marshallIn(sp, emlrtAlias(propValues[1]), &thisId, y->categoryNames);
  emlrtDestroyArrays(2, &propValues[0]);
  emlrtDestroyArray(&u);
}

static const mxArray *j_emlrt_marshallOut(const real_T u[200])
{
  static const int32_T i = 200;
  const mxArray *m;
  const mxArray *y;
  real_T *pData;
  int32_T b_i;
  y = NULL;
  m = emlrtCreateNumericArray(1, (const void *)&i, mxDOUBLE_CLASS, mxREAL);
  pData = emlrtMxGetPr(m);
  for (b_i = 0; b_i < 200; b_i++) {
    pData[b_i] = u[b_i];
  }
  emlrtAssign(&y, m);
  return y;
}

static void jb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                const emlrtMsgIdentifier *msgId, char_T ret[14])
{
  static const int32_T dims[2] = {2, 7};
  emlrtCheckBuiltInR2012b((emlrtCTX)sp, msgId, src, (const char_T *)"char",
                          false, 2U, (void *)&dims[0]);
  emlrtImportCharArrayR2015b((emlrtCTX)sp, src, &ret[0], 14);
  emlrtDestroyArray(&src);
}

static void k_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId, uint8_T y[2])
{
  gb_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static const mxArray *k_emlrt_marshallOut(const emlrtStack *sp,
                                          const categorical u)
{
  static const int32_T i = 2;
  const mxArray *propValues[5];
  const mxArray *b_y;
  const mxArray *c_y;
  const mxArray *d_y;
  const mxArray *e_y;
  const mxArray *f_y;
  const mxArray *g_y;
  const mxArray *m;
  const mxArray *m1;
  const mxArray *m2;
  const mxArray *m3;
  const mxArray *m4;
  const mxArray *m5;
  const mxArray *y;
  int32_T iv[2];
  int32_T i1;
  uint8_T *pData;
  y = NULL;
  m = NULL;
  m1 = NULL;
  m2 = NULL;
  m3 = NULL;
  m4 = NULL;
  emlrtAssign(&y, emlrtCreateClassInstance2022a(
                      (emlrtCTX)sp,
                      (const char_T *)"matlab.internal.coder.categorical"));
  m = NULL;
  b_y = NULL;
  m5 = emlrtCreateNumericArray(1, (const void *)&i, mxUINT8_CLASS, mxREAL);
  pData = (uint8_T *)emlrtMxGetData(m5);
  *pData = u.codes[0];
  pData[1] = u.codes[1];
  emlrtAssign(&b_y, m5);
  emlrtAssign(&m, b_y);
  propValues[0] = m;
  m1 = NULL;
  c_y = NULL;
  i1 = 2;
  emlrtAssign(&c_y, emlrtCreateCellArrayR2014a(1, &i1));
  d_y = NULL;
  iv[0] = 1;
  iv[1] = u.categoryNames[0].f1->size[1];
  m5 = emlrtCreateCharArray(2, &iv[0]);
  emlrtInitCharArrayR2013a((emlrtCTX)sp, u.categoryNames[0].f1->size[1], m5,
                           &u.categoryNames[0].f1->data[0]);
  emlrtAssign(&d_y, m5);
  emlrtSetCell(c_y, 0, d_y);
  d_y = NULL;
  iv[0] = 1;
  iv[1] = u.categoryNames[1].f1->size[1];
  m5 = emlrtCreateCharArray(2, &iv[0]);
  emlrtInitCharArrayR2013a((emlrtCTX)sp, u.categoryNames[1].f1->size[1], m5,
                           &u.categoryNames[1].f1->data[0]);
  emlrtAssign(&d_y, m5);
  emlrtSetCell(c_y, 1, d_y);
  emlrtAssign(&m1, c_y);
  propValues[1] = m1;
  m2 = NULL;
  e_y = NULL;
  m5 = emlrtCreateLogicalScalar(false);
  emlrtAssign(&e_y, m5);
  emlrtAssign(&m2, e_y);
  propValues[2] = m2;
  m3 = NULL;
  f_y = NULL;
  m5 = emlrtCreateLogicalScalar(false);
  emlrtAssign(&f_y, m5);
  emlrtAssign(&m3, f_y);
  propValues[3] = m3;
  m4 = NULL;
  g_y = NULL;
  m5 = emlrtCreateDoubleScalar(2.0);
  emlrtAssign(&g_y, m5);
  emlrtAssign(&m4, g_y);
  propValues[4] = m4;
  emlrtSetAllProperties((emlrtCTX)sp, &y, 0, 5, (const char_T **)&sv[0],
                        (const char_T **)&sv1[0], &propValues[0]);
  emlrtAssign(&y, emlrtConvertInstanceToRedirectSource(
                      (emlrtCTX)sp, y, 0,
                      (const char_T *)"matlab.internal.coder.categorical"));
  return y;
}

static void kb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                const emlrtMsgIdentifier *msgId, real_T ret[60])
{
  static const int32_T dims = 60;
  real_T(*r)[60];
  int32_T i;
  emlrtCheckBuiltInR2012b((emlrtCTX)sp, msgId, src, (const char_T *)"double",
                          false, 1U, (void *)&dims);
  r = (real_T(*)[60])emlrtMxGetData(src);
  for (i = 0; i < 60; i++) {
    ret[i] = (*r)[i];
  }
  emlrtDestroyArray(&src);
}

static void l_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               cell_wrap_1 y[2])
{
  emlrtMsgIdentifier thisId;
  int32_T i;
  char_T str[11];
  boolean_T b;
  thisId.fParent = parentId;
  thisId.bParentIsCell = true;
  b = false;
  i = 2;
  emlrtCheckCell((emlrtCTX)sp, parentId, u, 1U, &i, &b);
  sprintf(&str[0], "%d", 1);
  thisId.fIdentifier = &str[0];
  m_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 0)),
                     &thisId, y[0].f1);
  sprintf(&str[0], "%d", 2);
  thisId.fIdentifier = &str[0];
  m_emlrt_marshallIn(sp, emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 1)),
                     &thisId, y[1].f1);
  emlrtDestroyArray(&u);
}

static const mxArray *l_emlrt_marshallOut(const real_T u[2])
{
  static const int32_T iv[2] = {1, 2};
  const mxArray *m;
  const mxArray *y;
  real_T *pData;
  y = NULL;
  m = emlrtCreateNumericArray(2, (const void *)&iv[0], mxDOUBLE_CLASS, mxREAL);
  pData = emlrtMxGetPr(m);
  pData[0] = u[0];
  pData[1] = u[1];
  emlrtAssign(&y, m);
  return y;
}

static void lb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                const emlrtMsgIdentifier *msgId)
{
  static const int32_T dims[2] = {0, 0};
  emlrtCheckBuiltInR2012b((emlrtCTX)sp, msgId, src, (const char_T *)"double",
                          false, 2U, (void *)&dims[0]);
  emlrtMxGetData(src);
  emlrtDestroyArray(&src);
}

static void m_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               emxArray_char_T *y)
{
  hb_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static const mxArray *m_emlrt_marshallOut(void)
{
  static const int32_T iv[2] = {0, 0};
  const mxArray *m;
  const mxArray *y;
  y = NULL;
  m = emlrtCreateNumericArray(2, (const void *)&iv[0], mxDOUBLE_CLASS, mxREAL);
  emlrtAssign(&y, m);
  return y;
}

static void mb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                const emlrtMsgIdentifier *msgId, real_T ret[61])
{
  static const int32_T dims = 61;
  real_T(*r)[61];
  int32_T i;
  emlrtCheckBuiltInR2012b((emlrtCTX)sp, msgId, src, (const char_T *)"double",
                          false, 1U, (void *)&dims);
  r = (real_T(*)[61])emlrtMxGetData(src);
  for (i = 0; i < 61; i++) {
    ret[i] = (*r)[i];
  }
  emlrtDestroyArray(&src);
}

static void n_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId, real_T y[2])
{
  ib_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static const mxArray *n_emlrt_marshallOut(const emlrtStack *sp,
                                          const char_T u[14])
{
  static const int32_T iv[2] = {2, 7};
  const mxArray *m;
  const mxArray *y;
  y = NULL;
  m = emlrtCreateCharArray(2, &iv[0]);
  emlrtInitCharArrayR2013a((emlrtCTX)sp, 14, m, &u[0]);
  emlrtAssign(&y, m);
  return y;
}

static void nb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                const emlrtMsgIdentifier *msgId,
                                emxArray_real_T *ret)
{
  static const int32_T dims[2] = {24075, 60};
  int32_T iv[2];
  int32_T i;
  const boolean_T bv[2] = {true, false};
  emlrtCheckVsBuiltInR2012b((emlrtCTX)sp, msgId, src, (const char_T *)"double",
                            false, 2U, (void *)&dims[0], &bv[0], &iv[0]);
  ret->allocatedSize = iv[0] * iv[1];
  i = ret->size[0] * ret->size[1];
  ret->size[0] = iv[0];
  ret->size[1] = iv[1];
  emxEnsureCapacity_real_T(sp, ret, i, (emlrtRTEInfo *)NULL);
  ret->data = (real_T *)emlrtMxGetData(src);
  ret->canFreeData = false;
  emlrtDestroyArray(&src);
}

static void o_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId, char_T y[14])
{
  jb_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static const mxArray *
o_emlrt_marshallOut(const emlrtStack *sp,
                    const c_incremental_coder_impl_ScaleI *u)
{
  static const int32_T iv[2] = {1, 8};
  static const int32_T iv1[2] = {1, 5};
  static const int32_T iv2[2] = {1, 15};
  static const int32_T iv3[2] = {1, 3};
  static const char_T b_u[8] = {'c', 'o', 'n', 's', 't', 'a', 'n', 't'};
  static const char_T c_u[5] = {'h', 'i', 'n', 'g', 'e'};
  static const char_T d_u[3] = {'s', 'v', 'm'};
  const mxArray *propValues[40];
  const mxArray *b_y;
  const mxArray *c_y;
  const mxArray *d_y;
  const mxArray *e_y;
  const mxArray *f_y;
  const mxArray *g_y;
  const mxArray *h_y;
  const mxArray *i_y;
  const mxArray *j_y;
  const mxArray *k_y;
  const mxArray *l_y;
  const mxArray *m;
  const mxArray *m1;
  const mxArray *m10;
  const mxArray *m11;
  const mxArray *m12;
  const mxArray *m13;
  const mxArray *m14;
  const mxArray *m15;
  const mxArray *m16;
  const mxArray *m17;
  const mxArray *m18;
  const mxArray *m19;
  const mxArray *m2;
  const mxArray *m20;
  const mxArray *m21;
  const mxArray *m22;
  const mxArray *m23;
  const mxArray *m24;
  const mxArray *m25;
  const mxArray *m26;
  const mxArray *m27;
  const mxArray *m28;
  const mxArray *m29;
  const mxArray *m3;
  const mxArray *m30;
  const mxArray *m31;
  const mxArray *m32;
  const mxArray *m33;
  const mxArray *m34;
  const mxArray *m35;
  const mxArray *m36;
  const mxArray *m37;
  const mxArray *m38;
  const mxArray *m39;
  const mxArray *m4;
  const mxArray *m40;
  const mxArray *m5;
  const mxArray *m6;
  const mxArray *m7;
  const mxArray *m8;
  const mxArray *m9;
  const mxArray *m_y;
  const mxArray *n_y;
  const mxArray *y;
  const char_T *propClasses[40] = {"incremental.coder.impl.Impl",
                                   "incremental.coder.impl.Impl",
                                   "incremental.coder.impl.Impl",
                                   "incremental.coder.impl.LinearImpl",
                                   "incremental.coder.impl.LinearImpl",
                                   "incremental.coder.impl.LinearImpl",
                                   "incremental.coder.impl.LinearImpl",
                                   "incremental.coder.impl.LinearImpl",
                                   "incremental.coder.impl.LinearImpl",
                                   "incremental.coder.impl.LinearImpl",
                                   "incremental.coder.impl.LinearImpl",
                                   "incremental.coder.impl.LinearImpl",
                                   "incremental.coder.impl.LinearImpl",
                                   "incremental.coder.impl.LinearImpl",
                                   "incremental.coder.impl.LinearImpl",
                                   "incremental.coder.impl.LinearImpl",
                                   "incremental.coder.impl.LinearImpl",
                                   "incremental.coder.impl.LinearImpl",
                                   "incremental.coder.impl.LinearImpl",
                                   "incremental.coder.impl.LinearImpl",
                                   "incremental.coder.impl.LinearImpl",
                                   "incremental.coder.impl.LinearImpl",
                                   "incremental.coder.impl.LinearImpl",
                                   "incremental.coder.impl.LinearImpl",
                                   "incremental.coder.impl.LinearImpl",
                                   "incremental.coder.impl.LinearImpl",
                                   "incremental.coder.impl.LinearImpl",
                                   "incremental.coder.impl.LinearImpl",
                                   "incremental.coder.impl.LinearImpl",
                                   "incremental.coder.impl.LinearImpl",
                                   "incremental.coder.impl.LinearImpl",
                                   "incremental.coder.impl.ScaleInvariantImpl",
                                   "incremental.coder.impl.ScaleInvariantImpl",
                                   "incremental.coder.impl.ScaleInvariantImpl",
                                   "incremental.coder.impl.ScaleInvariantImpl",
                                   "incremental.coder.impl.ScaleInvariantImpl",
                                   "incremental.coder.impl.ScaleInvariantImpl",
                                   "incremental.coder.impl.ScaleInvariantImpl",
                                   "incremental.coder.impl.ScaleInvariantImpl",
                                   "incremental.coder.impl.ScaleInvariantImpl"};
  const char_T *propNames[40] = {"ImplMode",
                                 "IsXDouble",
                                 "EpsilonX",
                                 "BatchSize",
                                 "LearnRate",
                                 "Epsilon",
                                 "FitBias",
                                 "LearnRateSchedule",
                                 "Beta",
                                 "Bias",
                                 "Mu",
                                 "Sigma",
                                 "Lambda",
                                 "LossFunction",
                                 "Solver",
                                 "EstimateEpsilon",
                                 "MuHat",
                                 "VarHat",
                                 "StandardizeWeights",
                                 "PerClassMuHat",
                                 "PerClassVarHat",
                                 "KnownPrior",
                                 "YHat",
                                 "Stream",
                                 "BatchIndex",
                                 "EstimateMuSigma",
                                 "MuSigmaEstimationNeeded",
                                 "PerClassEstimationNeeded",
                                 "EpsilonEstimationNeeded",
                                 "Standardize",
                                 "Learner",
                                 "S2t",
                                 "Gt",
                                 "Mt",
                                 "Etat",
                                 "Ymt",
                                 "Rho",
                                 "YmtSet",
                                 "Shuffle",
                                 "SolverMode"};
  y = NULL;
  m = NULL;
  m1 = NULL;
  m2 = NULL;
  m3 = NULL;
  m4 = NULL;
  m5 = NULL;
  m6 = NULL;
  m7 = NULL;
  m8 = NULL;
  m9 = NULL;
  m10 = NULL;
  m11 = NULL;
  m12 = NULL;
  m13 = NULL;
  m14 = NULL;
  m15 = NULL;
  m16 = NULL;
  m17 = NULL;
  m18 = NULL;
  m19 = NULL;
  m20 = NULL;
  m21 = NULL;
  m22 = NULL;
  m23 = NULL;
  m24 = NULL;
  m25 = NULL;
  m26 = NULL;
  m27 = NULL;
  m28 = NULL;
  m29 = NULL;
  m30 = NULL;
  m31 = NULL;
  m32 = NULL;
  m33 = NULL;
  m34 = NULL;
  m35 = NULL;
  m36 = NULL;
  m37 = NULL;
  m38 = NULL;
  m39 = NULL;
  emlrtAssign(&y,
              emlrtCreateClassInstance2022a(
                  (emlrtCTX)sp,
                  (const char_T *)"incremental.coder.impl.ScaleInvariantImpl"));
  m = NULL;
  b_y = NULL;
  m40 = emlrtCreateNumericMatrix(1, 1, mxUINT8_CLASS, mxREAL);
  *(uint8_T *)emlrtMxGetData(m40) = 2U;
  emlrtAssign(&b_y, m40);
  emlrtAssign(&m, b_y);
  propValues[0] = m;
  m1 = NULL;
  emlrtAssign(&m1, e_emlrt_marshallOut(true));
  propValues[1] = m1;
  m2 = NULL;
  c_y = NULL;
  m40 = emlrtCreateDoubleScalar(2.2204460492503131E-14);
  emlrtAssign(&c_y, m40);
  emlrtAssign(&m2, c_y);
  propValues[2] = m2;
  m3 = NULL;
  emlrtAssign(&m3, c_emlrt_marshallOut(1U));
  propValues[3] = m3;
  m4 = NULL;
  d_y = NULL;
  m40 = emlrtCreateDoubleScalar(u->LearnRate);
  emlrtAssign(&d_y, m40);
  emlrtAssign(&m4, d_y);
  propValues[4] = m4;
  m5 = NULL;
  e_y = NULL;
  m40 = emlrtCreateDoubleScalar(u->Epsilon);
  emlrtAssign(&e_y, m40);
  emlrtAssign(&m5, e_y);
  propValues[5] = m5;
  m6 = NULL;
  emlrtAssign(&m6, e_emlrt_marshallOut(true));
  propValues[6] = m6;
  m7 = NULL;
  f_y = NULL;
  m40 = emlrtCreateCharArray(2, &iv[0]);
  emlrtInitCharArrayR2013a((emlrtCTX)sp, 8, m40, &b_u[0]);
  emlrtAssign(&f_y, m40);
  emlrtAssign(&m7, f_y);
  propValues[7] = m7;
  m8 = NULL;
  emlrtAssign(&m8, p_emlrt_marshallOut(u->Beta));
  propValues[8] = m8;
  m9 = NULL;
  g_y = NULL;
  m40 = emlrtCreateDoubleScalar(u->Bias);
  emlrtAssign(&g_y, m40);
  emlrtAssign(&m9, g_y);
  propValues[9] = m9;
  m10 = NULL;
  emlrtAssign(&m10, m_emlrt_marshallOut());
  propValues[10] = m10;
  m11 = NULL;
  emlrtAssign(&m11, m_emlrt_marshallOut());
  propValues[11] = m11;
  m12 = NULL;
  h_y = NULL;
  m40 = emlrtCreateDoubleScalar(-1.0);
  emlrtAssign(&h_y, m40);
  emlrtAssign(&m12, h_y);
  propValues[12] = m12;
  m13 = NULL;
  i_y = NULL;
  m40 = emlrtCreateCharArray(2, &iv1[0]);
  emlrtInitCharArrayR2013a((emlrtCTX)sp, 5, m40, &c_u[0]);
  emlrtAssign(&i_y, m40);
  emlrtAssign(&m13, i_y);
  propValues[13] = m13;
  m14 = NULL;
  j_y = NULL;
  m40 = emlrtCreateCharArray(2, &iv2[0]);
  emlrtInitCharArrayR2013a((emlrtCTX)sp, 15, m40, &cv1[0]);
  emlrtAssign(&j_y, m40);
  emlrtAssign(&m14, j_y);
  propValues[14] = m14;
  m15 = NULL;
  emlrtAssign(&m15, e_emlrt_marshallOut(false));
  propValues[15] = m15;
  m16 = NULL;
  emlrtAssign(&m16, m_emlrt_marshallOut());
  propValues[16] = m16;
  m17 = NULL;
  emlrtAssign(&m17, m_emlrt_marshallOut());
  propValues[17] = m17;
  m18 = NULL;
  emlrtAssign(&m18, m_emlrt_marshallOut());
  propValues[18] = m18;
  m19 = NULL;
  emlrtAssign(&m19, m_emlrt_marshallOut());
  propValues[19] = m19;
  m20 = NULL;
  emlrtAssign(&m20, m_emlrt_marshallOut());
  propValues[20] = m20;
  m21 = NULL;
  emlrtAssign(&m21, m_emlrt_marshallOut());
  propValues[21] = m21;
  m22 = NULL;
  emlrtAssign(&m22, m_emlrt_marshallOut());
  propValues[22] = m22;
  m23 = NULL;
  emlrtAssign(&m23, m_emlrt_marshallOut());
  propValues[23] = m23;
  m24 = NULL;
  emlrtAssign(&m24, c_emlrt_marshallOut(u->BatchIndex));
  propValues[24] = m24;
  m25 = NULL;
  emlrtAssign(&m25, e_emlrt_marshallOut(false));
  propValues[25] = m25;
  m26 = NULL;
  emlrtAssign(&m26, e_emlrt_marshallOut(false));
  propValues[26] = m26;
  m27 = NULL;
  emlrtAssign(&m27, e_emlrt_marshallOut(false));
  propValues[27] = m27;
  m28 = NULL;
  emlrtAssign(&m28, e_emlrt_marshallOut(false));
  propValues[28] = m28;
  m29 = NULL;
  emlrtAssign(&m29, e_emlrt_marshallOut(false));
  propValues[29] = m29;
  m30 = NULL;
  k_y = NULL;
  m40 = emlrtCreateCharArray(2, &iv3[0]);
  emlrtInitCharArrayR2013a((emlrtCTX)sp, 3, m40, &d_u[0]);
  emlrtAssign(&k_y, m40);
  emlrtAssign(&m30, k_y);
  propValues[30] = m30;
  m31 = NULL;
  emlrtAssign(&m31, q_emlrt_marshallOut(u->S2t));
  propValues[31] = m31;
  m32 = NULL;
  emlrtAssign(&m32, q_emlrt_marshallOut(u->Gt));
  propValues[32] = m32;
  m33 = NULL;
  emlrtAssign(&m33, q_emlrt_marshallOut(u->Mt));
  propValues[33] = m33;
  m34 = NULL;
  emlrtAssign(&m34, q_emlrt_marshallOut(u->Etat));
  propValues[34] = m34;
  m35 = NULL;
  l_y = NULL;
  m40 = emlrtCreateDoubleScalar(u->Ymt);
  emlrtAssign(&l_y, m40);
  emlrtAssign(&m35, l_y);
  propValues[35] = m35;
  m36 = NULL;
  m_y = NULL;
  m40 = emlrtCreateDoubleScalar(u->Rho);
  emlrtAssign(&m_y, m40);
  emlrtAssign(&m36, m_y);
  propValues[36] = m36;
  m37 = NULL;
  emlrtAssign(&m37, e_emlrt_marshallOut(u->YmtSet));
  propValues[37] = m37;
  m38 = NULL;
  emlrtAssign(&m38, e_emlrt_marshallOut(false));
  propValues[38] = m38;
  m39 = NULL;
  n_y = NULL;
  m40 = emlrtCreateDoubleScalar(2.0);
  emlrtAssign(&n_y, m40);
  emlrtAssign(&m39, n_y);
  propValues[39] = m39;
  emlrtSetAllProperties((emlrtCTX)sp, &y, 0, 40, (const char_T **)&propNames[0],
                        (const char_T **)&propClasses[0], &propValues[0]);
  emlrtAssign(&y,
              emlrtConvertInstanceToRedirectSource(
                  (emlrtCTX)sp, y, 0,
                  (const char_T *)"incremental.coder.impl.ScaleInvariantImpl"));
  return y;
}

static void ob_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                const emlrtMsgIdentifier *msgId,
                                uint8_T ret_data[], int32_T ret_size[2])
{
  static const int32_T dims[2] = {24075, 1};
  int32_T iv[2];
  const boolean_T bv[2] = {true, true};
  emlrtCheckVsBuiltInR2012b((emlrtCTX)sp, msgId, src, (const char_T *)"uint8",
                            false, 2U, (void *)&dims[0], &bv[0], &iv[0]);
  ret_size[0] = iv[0];
  ret_size[1] = iv[1];
  emlrtImportArrayR2015b((emlrtCTX)sp, src, &ret_data[0], 1, false);
  emlrtDestroyArray(&src);
}

static void p_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               c_incremental_coder_impl_ScaleI *y)
{
  emlrtMsgIdentifier thisId;
  const mxArray *propValues[17];
  int32_T i;
  const char_T *propClasses[17] = {"incremental.coder.impl.LinearImpl",
                                   "incremental.coder.impl.LinearImpl",
                                   "incremental.coder.impl.LinearImpl",
                                   "incremental.coder.impl.LinearImpl",
                                   "incremental.coder.impl.LinearImpl",
                                   "incremental.coder.impl.LinearImpl",
                                   "incremental.coder.impl.LinearImpl",
                                   "incremental.coder.impl.LinearImpl",
                                   "incremental.coder.impl.LinearImpl",
                                   "incremental.coder.impl.LinearImpl",
                                   "incremental.coder.impl.ScaleInvariantImpl",
                                   "incremental.coder.impl.ScaleInvariantImpl",
                                   "incremental.coder.impl.ScaleInvariantImpl",
                                   "incremental.coder.impl.ScaleInvariantImpl",
                                   "incremental.coder.impl.ScaleInvariantImpl",
                                   "incremental.coder.impl.ScaleInvariantImpl",
                                   "incremental.coder.impl.ScaleInvariantImpl"};
  const char_T *propNames[17] = {
      "LearnRate", "Epsilon", "Beta",   "Bias",       "Mu",    "Sigma",
      "MuHat",     "VarHat",  "Stream", "BatchIndex", "S2t",   "Gt",
      "Mt",        "Etat",    "Ymt",    "Rho",        "YmtSet"};
  for (i = 0; i < 17; i++) {
    propValues[i] = NULL;
  }
  thisId.fParent = parentId;
  thisId.bParentIsCell = false;
  emlrtCheckMcosClass2017a(
      (emlrtCTX)sp, parentId, u,
      (const char_T *)"incremental.coder.impl.ScaleInvariantImpl");
  emlrtGetAllProperties((emlrtCTX)sp, u, 0, 17, (const char_T **)&propNames[0],
                        (const char_T **)&propClasses[0], &propValues[0]);
  thisId.fIdentifier = "LearnRate";
  y->LearnRate = g_emlrt_marshallIn(sp, emlrtAlias(propValues[0]), &thisId);
  thisId.fIdentifier = "Epsilon";
  y->Epsilon = g_emlrt_marshallIn(sp, emlrtAlias(propValues[1]), &thisId);
  thisId.fIdentifier = "Beta";
  q_emlrt_marshallIn(sp, emlrtAlias(propValues[2]), &thisId, y->Beta);
  thisId.fIdentifier = "Bias";
  y->Bias = g_emlrt_marshallIn(sp, emlrtAlias(propValues[3]), &thisId);
  thisId.fIdentifier = "Mu";
  r_emlrt_marshallIn(sp, emlrtAlias(propValues[4]), &thisId);
  thisId.fIdentifier = "Sigma";
  r_emlrt_marshallIn(sp, emlrtAlias(propValues[5]), &thisId);
  thisId.fIdentifier = "MuHat";
  r_emlrt_marshallIn(sp, emlrtAlias(propValues[6]), &thisId);
  thisId.fIdentifier = "VarHat";
  r_emlrt_marshallIn(sp, emlrtAlias(propValues[7]), &thisId);
  thisId.fIdentifier = "Stream";
  r_emlrt_marshallIn(sp, emlrtAlias(propValues[8]), &thisId);
  thisId.fIdentifier = "BatchIndex";
  y->BatchIndex = c_emlrt_marshallIn(sp, emlrtAlias(propValues[9]), &thisId);
  thisId.fIdentifier = "S2t";
  s_emlrt_marshallIn(sp, emlrtAlias(propValues[10]), &thisId, y->S2t);
  thisId.fIdentifier = "Gt";
  s_emlrt_marshallIn(sp, emlrtAlias(propValues[11]), &thisId, y->Gt);
  thisId.fIdentifier = "Mt";
  s_emlrt_marshallIn(sp, emlrtAlias(propValues[12]), &thisId, y->Mt);
  thisId.fIdentifier = "Etat";
  s_emlrt_marshallIn(sp, emlrtAlias(propValues[13]), &thisId, y->Etat);
  thisId.fIdentifier = "Ymt";
  y->Ymt = g_emlrt_marshallIn(sp, emlrtAlias(propValues[14]), &thisId);
  thisId.fIdentifier = "Rho";
  y->Rho = g_emlrt_marshallIn(sp, emlrtAlias(propValues[15]), &thisId);
  thisId.fIdentifier = "YmtSet";
  y->YmtSet = d_emlrt_marshallIn(sp, emlrtAlias(propValues[16]), &thisId);
  emlrtDestroyArrays(17, &propValues[0]);
  emlrtDestroyArray(&u);
}

static const mxArray *p_emlrt_marshallOut(const real_T u[60])
{
  static const int32_T i = 60;
  const mxArray *m;
  const mxArray *y;
  real_T *pData;
  int32_T b_i;
  y = NULL;
  m = emlrtCreateNumericArray(1, (const void *)&i, mxDOUBLE_CLASS, mxREAL);
  pData = emlrtMxGetPr(m);
  for (b_i = 0; b_i < 60; b_i++) {
    pData[b_i] = u[b_i];
  }
  emlrtAssign(&y, m);
  return y;
}

static void pb_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                const emlrtMsgIdentifier *msgId,
                                char_T ret_data[], int32_T ret_size[2])
{
  static const int32_T dims[2] = {1, 7};
  int32_T iv[2];
  const boolean_T bv[2] = {false, true};
  emlrtCheckVsBuiltInR2012b((emlrtCTX)sp, msgId, src, (const char_T *)"char",
                            false, 2U, (void *)&dims[0], &bv[0], &iv[0]);
  ret_size[0] = iv[0];
  ret_size[1] = iv[1];
  emlrtImportArrayR2015b((emlrtCTX)sp, src, &ret_data[0], 1, false);
  emlrtDestroyArray(&src);
}

static void q_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId, real_T y[60])
{
  kb_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static const mxArray *q_emlrt_marshallOut(const real_T u[61])
{
  static const int32_T i = 61;
  const mxArray *m;
  const mxArray *y;
  real_T *pData;
  int32_T b_i;
  y = NULL;
  m = emlrtCreateNumericArray(1, (const void *)&i, mxDOUBLE_CLASS, mxREAL);
  pData = emlrtMxGetPr(m);
  for (b_i = 0; b_i < 61; b_i++) {
    pData[b_i] = u[b_i];
  }
  emlrtAssign(&y, m);
  return y;
}

static void r_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId)
{
  lb_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
}

static const mxArray *r_emlrt_marshallOut(const emlrtStack *sp,
                                          const b_categorical u)
{
  const mxArray *propValues[5];
  const mxArray *b_y;
  const mxArray *c_y;
  const mxArray *d_y;
  const mxArray *e_y;
  const mxArray *f_y;
  const mxArray *g_y;
  const mxArray *m;
  const mxArray *m1;
  const mxArray *m2;
  const mxArray *m3;
  const mxArray *m4;
  const mxArray *m5;
  const mxArray *y;
  int32_T iv[2];
  int32_T b_i;
  int32_T i;
  uint32_T *pData;
  y = NULL;
  m = NULL;
  m1 = NULL;
  m2 = NULL;
  m3 = NULL;
  m4 = NULL;
  emlrtAssign(&y, emlrtCreateClassInstance2022a(
                      (emlrtCTX)sp,
                      (const char_T *)"matlab.internal.coder.categorical"));
  m = NULL;
  b_y = NULL;
  m5 = emlrtCreateNumericArray(1, &u.codes->size[0], mxUINT32_CLASS, mxREAL);
  pData = (uint32_T *)emlrtMxGetData(m5);
  i = 0;
  for (b_i = 0; b_i < u.codes->size[0]; b_i++) {
    pData[i] = u.codes->data[b_i];
    i++;
  }
  emlrtAssign(&b_y, m5);
  emlrtAssign(&m, b_y);
  propValues[0] = m;
  m1 = NULL;
  c_y = NULL;
  emlrtAssign(&c_y, emlrtCreateCellArrayR2014a(1, &u.categoryNames->size[0]));
  if (u.categoryNames->size[0] > 0) {
    iv[0] = 1;
  }
  for (i = 0; i < u.categoryNames->size[0]; i++) {
    d_y = NULL;
    iv[1] = u.categoryNames->data[i].f1->size[1];
    m5 = emlrtCreateCharArray(2, &iv[0]);
    emlrtInitCharArrayR2013a((emlrtCTX)sp, u.categoryNames->data[i].f1->size[1],
                             m5, &u.categoryNames->data[i].f1->data[0]);
    emlrtAssign(&d_y, m5);
    emlrtSetCell(c_y, i, d_y);
  }
  emlrtAssign(&m1, c_y);
  propValues[1] = m1;
  m2 = NULL;
  e_y = NULL;
  m5 = emlrtCreateLogicalScalar(false);
  emlrtAssign(&e_y, m5);
  emlrtAssign(&m2, e_y);
  propValues[2] = m2;
  m3 = NULL;
  f_y = NULL;
  m5 = emlrtCreateLogicalScalar(false);
  emlrtAssign(&f_y, m5);
  emlrtAssign(&m3, f_y);
  propValues[3] = m3;
  m4 = NULL;
  g_y = NULL;
  m5 = emlrtCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
  *(int32_T *)emlrtMxGetData(m5) = 2147483646;
  emlrtAssign(&g_y, m5);
  emlrtAssign(&m4, g_y);
  propValues[4] = m4;
  emlrtSetAllProperties((emlrtCTX)sp, &y, 0, 5, (const char_T **)&sv[0],
                        (const char_T **)&sv1[0], &propValues[0]);
  emlrtAssign(&y, emlrtConvertInstanceToRedirectSource(
                      (emlrtCTX)sp, y, 0,
                      (const char_T *)"matlab.internal.coder.categorical"));
  return y;
}

static void s_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId, real_T y[61])
{
  mb_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static const mxArray *s_emlrt_marshallOut(const emxArray_real_T *u)
{
  static const int32_T iv[2] = {0, 0};
  const mxArray *m;
  const mxArray *y;
  const real_T *u_data;
  u_data = u->data;
  y = NULL;
  m = emlrtCreateNumericArray(2, (const void *)&iv[0], mxDOUBLE_CLASS, mxREAL);
  emlrtMxSetData((mxArray *)m, (void *)&u_data[0]);
  emlrtSetDimensions((mxArray *)m, &u->size[0], 2);
  emlrtAssign(&y, m);
  return y;
}

static void t_emlrt_marshallIn(const emlrtStack *sp, const mxArray *X,
                               const char_T *identifier, emxArray_real_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  u_emlrt_marshallIn(sp, emlrtAlias(X), &thisId, y);
  emlrtDestroyArray(&X);
}

static const mxArray *t_emlrt_marshallOut(void)
{
  const mxArray *m;
  const mxArray *y;
  y = NULL;
  m = emlrtCreateNumericMatrix(1, 1, mxINT8_CLASS, mxREAL);
  *(int8_T *)emlrtMxGetData(m) = 5;
  emlrtAssign(&y, m);
  return y;
}

static void u_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               emxArray_real_T *y)
{
  nb_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static const mxArray *u_emlrt_marshallOut(void)
{
  static const int32_T i = 2;
  const mxArray *m;
  const mxArray *y;
  real_T *pData;
  y = NULL;
  m = emlrtCreateNumericArray(1, (const void *)&i, mxDOUBLE_CLASS, mxREAL);
  pData = emlrtMxGetPr(m);
  pData[0] = 4.0;
  pData[1] = 7.0;
  emlrtAssign(&y, m);
  return y;
}

static void v_emlrt_marshallIn(const emlrtStack *sp, const mxArray *Y,
                               const char_T *identifier, c_categorical *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  w_emlrt_marshallIn(sp, emlrtAlias(Y), &thisId, y);
  emlrtDestroyArray(&Y);
}

static const mxArray *v_emlrt_marshallOut(const emlrtStack *sp)
{
  static const int32_T iv1[2] = {1, 12};
  static const int32_T iv2[2] = {1, 5};
  static const int32_T iv3[2] = {1, 5};
  static const int32_T iv4[2] = {1, 9};
  static const int32_T iv5[2] = {1, 11};
  static const int32_T iv6[2] = {1, 12};
  static const char_T f_u[12] = {'b', 'i', 'n', 'o', 'd', 'e',
                                 'v', 'i', 'a', 'n', 'c', 'e'};
  static const char_T u[12] = {'c', 'l', 'a', 's', 's', 'i',
                               'f', 'e', 'r', 'r', 'o', 'r'};
  static const char_T e_u[11] = {'e', 'x', 'p', 'o', 'n', 'e',
                                 'n', 't', 'i', 'a', 'l'};
  static const char_T d_u[9] = {'q', 'u', 'a', 'd', 'r', 'a', 't', 'i', 'c'};
  static const char_T b_u[5] = {'h', 'i', 'n', 'g', 'e'};
  static const char_T c_u[5] = {'l', 'o', 'g', 'i', 't'};
  const mxArray *b_y;
  const mxArray *c_y;
  const mxArray *d_y;
  const mxArray *e_y;
  const mxArray *f_y;
  const mxArray *g_y;
  const mxArray *m;
  const mxArray *y;
  int32_T iv[2];
  y = NULL;
  iv[0] = 1;
  iv[1] = 6;
  emlrtAssign(&y, emlrtCreateCellArrayR2014a(2, &iv[0]));
  b_y = NULL;
  m = emlrtCreateCharArray(2, &iv1[0]);
  emlrtInitCharArrayR2013a((emlrtCTX)sp, 12, m, &u[0]);
  emlrtAssign(&b_y, m);
  emlrtSetCell(y, 0, b_y);
  c_y = NULL;
  m = emlrtCreateCharArray(2, &iv2[0]);
  emlrtInitCharArrayR2013a((emlrtCTX)sp, 5, m, &b_u[0]);
  emlrtAssign(&c_y, m);
  emlrtSetCell(y, 1, c_y);
  d_y = NULL;
  m = emlrtCreateCharArray(2, &iv3[0]);
  emlrtInitCharArrayR2013a((emlrtCTX)sp, 5, m, &c_u[0]);
  emlrtAssign(&d_y, m);
  emlrtSetCell(y, 2, d_y);
  e_y = NULL;
  m = emlrtCreateCharArray(2, &iv4[0]);
  emlrtInitCharArrayR2013a((emlrtCTX)sp, 9, m, &d_u[0]);
  emlrtAssign(&e_y, m);
  emlrtSetCell(y, 3, e_y);
  f_y = NULL;
  m = emlrtCreateCharArray(2, &iv5[0]);
  emlrtInitCharArrayR2013a((emlrtCTX)sp, 11, m, &e_u[0]);
  emlrtAssign(&f_y, m);
  emlrtSetCell(y, 4, f_y);
  g_y = NULL;
  m = emlrtCreateCharArray(2, &iv6[0]);
  emlrtInitCharArrayR2013a((emlrtCTX)sp, 12, m, &f_u[0]);
  emlrtAssign(&g_y, m);
  emlrtSetCell(y, 5, g_y);
  return y;
}

static void w_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               c_categorical *y)
{
  emlrtMsgIdentifier thisId;
  const mxArray *propValues[5];
  int32_T i;
  for (i = 0; i < 5; i++) {
    propValues[i] = NULL;
  }
  thisId.fParent = parentId;
  thisId.bParentIsCell = false;
  emlrtCheckMcosClass2017a((emlrtCTX)sp, parentId, u,
                           (const char_T *)"categorical");
  emlrtAssign(&u, emlrtConvertInstanceToRedirectTarget(
                      (emlrtCTX)sp, u, 0,
                      (const char_T *)"matlab.internal.coder.categorical"));
  emlrtCheckMcosClass2017a((emlrtCTX)sp, parentId, u,
                           (const char_T *)"matlab.internal.coder.categorical");
  emlrtGetAllProperties((emlrtCTX)sp, u, 0, 5, (const char_T **)&sv[0],
                        (const char_T **)&sv1[0], &propValues[0]);
  thisId.fIdentifier = "codes";
  x_emlrt_marshallIn(sp, emlrtAlias(propValues[0]), &thisId, y->codes.data,
                     y->codes.size);
  thisId.fIdentifier = "categoryNames";
  y_emlrt_marshallIn(sp, emlrtAlias(propValues[1]), &thisId, y->categoryNames);
  thisId.fIdentifier = "isProtected";
  y->isProtected = d_emlrt_marshallIn(sp, emlrtAlias(propValues[2]), &thisId);
  thisId.fIdentifier = "isOrdinal";
  y->isOrdinal = d_emlrt_marshallIn(sp, emlrtAlias(propValues[3]), &thisId);
  thisId.fIdentifier = "numCategoriesUpperBound";
  y->numCategoriesUpperBound =
      g_emlrt_marshallIn(sp, emlrtAlias(propValues[4]), &thisId);
  emlrtDestroyArrays(5, &propValues[0]);
  emlrtDestroyArray(&u);
}

static const mxArray *w_emlrt_marshallOut(const emlrtStack *sp)
{
  static const int32_T enumValues[9] = {0, 1, 2, 3, 4, 5, 6, 7, 8};
  static const char_T *enumNames[9] = {
      "Logit",     "Doublelogit",    "Invlogit",       "Ismax",   "Sign",
      "Symmetric", "Symmetricismax", "Symmetriclogit", "Identity"};
  const mxArray *b_y;
  const mxArray *m;
  const mxArray *m1;
  const mxArray *y;
  y = NULL;
  m = NULL;
  emlrtCheckEnumR2012b((emlrtCTX)sp,
                       (const char_T *)"classreg.learning.coderutils.Transform",
                       9, (const char_T **)&enumNames[0], &enumValues[0]);
  b_y = NULL;
  m1 = emlrtCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
  *(int32_T *)emlrtMxGetData(m1) = (int32_T)Identity;
  emlrtAssign(&b_y, m1);
  emlrtAssign(&m, b_y);
  emlrtAssign(&y,
              emlrtCreateEnumR2012b(
                  (emlrtCTX)sp,
                  (const char_T *)"classreg.learning.coderutils.Transform", m));
  emlrtDestroyArray(&m);
  return y;
}

static void x_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               uint8_T y_data[], int32_T y_size[2])
{
  ob_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y_data, y_size);
  emlrtDestroyArray(&u);
}

static void y_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               cell_wrap_22 y[2])
{
  emlrtMsgIdentifier thisId;
  int32_T i;
  char_T str[11];
  boolean_T b;
  thisId.fParent = parentId;
  thisId.bParentIsCell = true;
  b = false;
  i = 2;
  emlrtCheckCell((emlrtCTX)sp, parentId, u, 1U, &i, &b);
  sprintf(&str[0], "%d", 1);
  thisId.fIdentifier = &str[0];
  ab_emlrt_marshallIn(sp,
                      emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 0)),
                      &thisId, y[0].f1.data, y[0].f1.size);
  sprintf(&str[0], "%d", 2);
  thisId.fIdentifier = &str[0];
  ab_emlrt_marshallIn(sp,
                      emlrtAlias(emlrtGetCell((emlrtCTX)sp, parentId, u, 1)),
                      &thisId, y[1].f1.data, y[1].f1.size);
  emlrtDestroyArray(&u);
}

void myFitIncrLearn_api(myIncrLearn_mexStackData *SD,
                        const mxArray *const prhs[3], const mxArray **plhs)
{
  c_categorical Y;
  e_incrementalClassificationLine incrementalModel;
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  emxArray_real_T *X;
  st.tls = emlrtRootTLSGlobal;
  emlrtHeapReferenceStackEnterFcnR2012b(&st);
  c_emxInitStruct_incrementalClas(&st, &incrementalModel, &gc_emlrtRTEI);
  emxInit_real_T(&st, &X, 2, &gc_emlrtRTEI);
  /* Marshall function inputs */
  emlrt_marshallIn(&st, emlrtAliasP(prhs[0]), "incrementalModel",
                   &incrementalModel);
  X->canFreeData = false;
  t_emlrt_marshallIn(&st, emlrtAlias(prhs[1]), "X", X);
  v_emlrt_marshallIn(&st, emlrtAliasP(prhs[2]), "Y", &Y);
  /* Invoke the target function */
  myFitIncrLearn(SD, &st, &incrementalModel, X, &Y);
  /* Marshall function outputs */
  *plhs = b_emlrt_marshallOut(&st, &incrementalModel);
  emxFree_real_T(&st, &X);
  c_emxFreeStruct_incrementalClas(&st, &incrementalModel);
  emlrtHeapReferenceStackLeaveFcnR2012b(&st);
}

void myInitialModelIncrLearn_api(const mxArray **plhs)
{
  e_incrementalClassificationLine r;
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  st.tls = emlrtRootTLSGlobal;
  emlrtHeapReferenceStackEnterFcnR2012b(&st);
  c_emxInitStruct_incrementalClas(&st, &r, &gc_emlrtRTEI);
  /* Invoke the target function */
  /* Marshall function outputs */
  myInitialModelIncrLearn(&st, &r);
  *plhs = b_emlrt_marshallOut(&st, &r);
  c_emxFreeStruct_incrementalClas(&st, &r);
  emlrtHeapReferenceStackLeaveFcnR2012b(&st);
}

void myPredictIncrLearn_api(myIncrLearn_mexStackData *SD,
                            const mxArray *const prhs[2], int32_T nlhs,
                            const mxArray *plhs[2])
{
  b_categorical labels;
  e_incrementalClassificationLine incrementalModel;
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  emxArray_real_T *X;
  emxArray_real_T *scores;
  st.tls = emlrtRootTLSGlobal;
  emlrtHeapReferenceStackEnterFcnR2012b(&st);
  c_emxInitStruct_incrementalClas(&st, &incrementalModel, &gc_emlrtRTEI);
  emxInit_real_T(&st, &X, 2, &gc_emlrtRTEI);
  emxInitStruct_categorical1(&st, &labels, &gc_emlrtRTEI);
  emxInit_real_T(&st, &scores, 2, &gc_emlrtRTEI);
  /* Marshall function inputs */
  emlrt_marshallIn(&st, emlrtAliasP(prhs[0]), "incrementalModel",
                   &incrementalModel);
  X->canFreeData = false;
  t_emlrt_marshallIn(&st, emlrtAlias(prhs[1]), "X", X);
  /* Invoke the target function */
  myPredictIncrLearn(SD, &st, incrementalModel, X, &labels, scores);
  /* Marshall function outputs */
  plhs[0] = r_emlrt_marshallOut(&st, labels);
  emxFreeStruct_categorical1(&st, &labels);
  emxFree_real_T(&st, &X);
  c_emxFreeStruct_incrementalClas(&st, &incrementalModel);
  if (nlhs > 1) {
    scores->canFreeData = false;
    plhs[1] = s_emlrt_marshallOut(scores);
  }
  emxFree_real_T(&st, &scores);
  emlrtHeapReferenceStackLeaveFcnR2012b(&st);
}

void myUpdateMetricsIncrLearn_api(myIncrLearn_mexStackData *SD,
                                  const mxArray *const prhs[3],
                                  const mxArray **plhs)
{
  c_categorical Y;
  e_incrementalClassificationLine incrementalModel;
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  emxArray_real_T *X;
  st.tls = emlrtRootTLSGlobal;
  emlrtHeapReferenceStackEnterFcnR2012b(&st);
  c_emxInitStruct_incrementalClas(&st, &incrementalModel, &gc_emlrtRTEI);
  emxInit_real_T(&st, &X, 2, &gc_emlrtRTEI);
  /* Marshall function inputs */
  emlrt_marshallIn(&st, emlrtAliasP(prhs[0]), "incrementalModel",
                   &incrementalModel);
  X->canFreeData = false;
  t_emlrt_marshallIn(&st, emlrtAlias(prhs[1]), "X", X);
  v_emlrt_marshallIn(&st, emlrtAliasP(prhs[2]), "Y", &Y);
  /* Invoke the target function */
  myUpdateMetricsIncrLearn(SD, &st, &incrementalModel, X, &Y);
  /* Marshall function outputs */
  *plhs = b_emlrt_marshallOut(&st, &incrementalModel);
  emxFree_real_T(&st, &X);
  c_emxFreeStruct_incrementalClas(&st, &incrementalModel);
  emlrtHeapReferenceStackLeaveFcnR2012b(&st);
}

/* End of code generation (_coder_myIncrLearn_mex_api.c) */
