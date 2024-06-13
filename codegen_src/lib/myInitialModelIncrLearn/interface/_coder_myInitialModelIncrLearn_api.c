/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_myInitialModelIncrLearn_api.c
 *
 * Code generation for function 'myInitialModelIncrLearn'
 *
 */

/* Include files */
#include "_coder_myInitialModelIncrLearn_api.h"
#include "_coder_myInitialModelIncrLearn_mex.h"

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

#ifndef typedef_cell_wrap_1
#define typedef_cell_wrap_1
typedef struct {
  char_T f1[3];
} cell_wrap_1;
#endif /* typedef_cell_wrap_1 */

#ifndef typedef_cell_wrap_2
#define typedef_cell_wrap_2
typedef struct {
  char_T f1[18];
} cell_wrap_2;
#endif /* typedef_cell_wrap_2 */

/* Variable Definitions */
emlrtCTX emlrtRootTLSGlobal = NULL;

emlrtContext emlrtContextGlobal = {
    true,                                                 /* bFirstTime */
    false,                                                /* bInitialized */
    131626U,                                              /* fVersionInfo */
    NULL,                                                 /* fErrorFunction */
    "myInitialModelIncrLearn",                            /* fFunctionName */
    NULL,                                                 /* fRTCallStack */
    false,                                                /* bDebugMode */
    {2045744189U, 2170104910U, 2743257031U, 4284093946U}, /* fSigWrd */
    NULL                                                  /* fSigMem */
};

/* Function Declarations */
static real_T (*b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                   const emlrtMsgIdentifier *parentId))[5];

static const mxArray *b_emlrt_marshallOut(const uint32_T u);

static void c_emlrt_marshallIn(const emlrtStack *sp,
                               const mxArray *incrementalModel,
                               const char_T *identifier,
                               incrementalRegressionLinear *y);

static const mxArray *c_emlrt_marshallOut(const real_T u);

static void d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               incrementalRegressionLinear *y);

static const mxArray *d_emlrt_marshallOut(const real_T u[25]);

static uint32_T e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                   const emlrtMsgIdentifier *parentId);

static const mxArray *e_emlrt_marshallOut(const emlrtStack *sp,
                                          const char_T u[3]);

static real_T (*emlrt_marshallIn(const emlrtStack *sp, const mxArray *z,
                                 const char_T *identifier))[5];

static const mxArray *emlrt_marshallOut(const emlrtStack *sp,
                                        const incrementalRegressionLinear *u);

static boolean_T f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                    const emlrtMsgIdentifier *parentId);

static const mxArray *
f_emlrt_marshallOut(const emlrtStack *sp,
                    const incremental_coder_impl_SGDImpl *u);

static struct0_T g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                    const emlrtMsgIdentifier *parentId);

static const mxArray *g_emlrt_marshallOut(const real_T u[20]);

static struct1_T h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                    const emlrtMsgIdentifier *parentId);

static const mxArray *h_emlrt_marshallOut(const emlrtStack *sp,
                                          const cell_wrap_2 u);

static real_T i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                 const emlrtMsgIdentifier *parentId);

static const mxArray *i_emlrt_marshallOut(const real_T u[5]);

static void j_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               real_T y[25]);

static const mxArray *j_emlrt_marshallOut(const emlrtStack *sp);

static void k_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               incremental_coder_impl_SGDImpl *y);

static void l_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               real_T y[20]);

static void m_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId);

static void n_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId);

static real_T (*o_emlrt_marshallIn(const emlrtStack *sp, const mxArray *X,
                                   const char_T *identifier))[100];

static real_T (*p_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                   const emlrtMsgIdentifier *parentId))[100];

static real_T (*q_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                   const emlrtMsgIdentifier *msgId))[5];

static uint32_T r_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                   const emlrtMsgIdentifier *msgId);

static boolean_T s_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                    const emlrtMsgIdentifier *msgId);

static real_T t_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                 const emlrtMsgIdentifier *msgId);

static void u_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId, real_T ret[25]);

static void v_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId, real_T ret[20]);

static void w_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId);

static void x_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId);

static real_T (*y_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                   const emlrtMsgIdentifier *msgId))[100];

/* Function Definitions */
static real_T (*b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                   const emlrtMsgIdentifier *parentId))[5]
{
  real_T(*y)[5];
  y = q_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static const mxArray *b_emlrt_marshallOut(const uint32_T u)
{
  const mxArray *m;
  const mxArray *y;
  y = NULL;
  m = emlrtCreateNumericMatrix(1, 1, mxUINT32_CLASS, mxREAL);
  *(uint32_T *)emlrtMxGetData(m) = u;
  emlrtAssign(&y, m);
  return y;
}

static void c_emlrt_marshallIn(const emlrtStack *sp,
                               const mxArray *incrementalModel,
                               const char_T *identifier,
                               incrementalRegressionLinear *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  d_emlrt_marshallIn(sp, emlrtAlias(incrementalModel), &thisId, y);
  emlrtDestroyArray(&incrementalModel);
}

static const mxArray *c_emlrt_marshallOut(const real_T u)
{
  const mxArray *m;
  const mxArray *y;
  y = NULL;
  m = emlrtCreateDoubleScalar(u);
  emlrtAssign(&y, m);
  return y;
}

static void d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               incrementalRegressionLinear *y)
{
  emlrtMsgIdentifier thisId;
  const mxArray *propValues[11];
  int32_T i;
  const char_T *propClasses[11] = {
      "incremental.coder.Learner",
      "incremental.coder.Learner",
      "incremental.coder.Learner",
      "incremental.coder.Learner",
      "incremental.coder.Learner",
      "incremental.coder.Learner",
      "incremental.coder.Learner",
      "incremental.coder.Estimator",
      "incremental.coder.Estimator",
      "incremental.coder.Linear",
      "incremental.coder.incrementalRegressionLinear"};
  const char_T *propNames[11] = {"NumTrainingObservations",
                                 "IsWarm",
                                 "Metrics",
                                 "MetricBuffer",
                                 "WeightBuffer",
                                 "BufferSize",
                                 "NumMetricObservations",
                                 "NumEstimationObservations",
                                 "parametersAdjusted",
                                 "Impl",
                                 "EpsilonMetricAdjusted"};
  for (i = 0; i < 11; i++) {
    propValues[i] = NULL;
  }
  thisId.fParent = parentId;
  thisId.bParentIsCell = false;
  emlrtCheckMcosClass2017a((emlrtCTX)sp, parentId, u,
                           (const char_T *)"incrementalRegressionLinear");
  emlrtAssign(
      &u, emlrtConvertInstanceToRedirectTarget(
              (emlrtCTX)sp, u, 0,
              (const char_T *)"incremental.coder.incrementalRegressionLinear"));
  emlrtCheckMcosClass2017a(
      (emlrtCTX)sp, parentId, u,
      (const char_T *)"incremental.coder.incrementalRegressionLinear");
  emlrtGetAllProperties((emlrtCTX)sp, u, 0, 11, (const char_T **)&propNames[0],
                        (const char_T **)&propClasses[0], &propValues[0]);
  thisId.fIdentifier = "NumTrainingObservations";
  y->NumTrainingObservations =
      e_emlrt_marshallIn(sp, emlrtAlias(propValues[0]), &thisId);
  thisId.fIdentifier = "IsWarm";
  y->IsWarm = f_emlrt_marshallIn(sp, emlrtAlias(propValues[1]), &thisId);
  thisId.fIdentifier = "Metrics";
  y->Metrics = g_emlrt_marshallIn(sp, emlrtAlias(propValues[2]), &thisId);
  thisId.fIdentifier = "MetricBuffer";
  j_emlrt_marshallIn(sp, emlrtAlias(propValues[3]), &thisId, y->MetricBuffer);
  thisId.fIdentifier = "WeightBuffer";
  j_emlrt_marshallIn(sp, emlrtAlias(propValues[4]), &thisId, y->WeightBuffer);
  thisId.fIdentifier = "BufferSize";
  y->BufferSize = e_emlrt_marshallIn(sp, emlrtAlias(propValues[5]), &thisId);
  thisId.fIdentifier = "NumMetricObservations";
  y->NumMetricObservations =
      e_emlrt_marshallIn(sp, emlrtAlias(propValues[6]), &thisId);
  thisId.fIdentifier = "NumEstimationObservations";
  y->NumEstimationObservations =
      e_emlrt_marshallIn(sp, emlrtAlias(propValues[7]), &thisId);
  thisId.fIdentifier = "parametersAdjusted";
  y->parametersAdjusted =
      f_emlrt_marshallIn(sp, emlrtAlias(propValues[8]), &thisId);
  thisId.fIdentifier = "Impl";
  k_emlrt_marshallIn(sp, emlrtAlias(propValues[9]), &thisId, &y->Impl);
  thisId.fIdentifier = "EpsilonMetricAdjusted";
  y->EpsilonMetricAdjusted =
      f_emlrt_marshallIn(sp, emlrtAlias(propValues[10]), &thisId);
  emlrtDestroyArrays(11, &propValues[0]);
  emlrtDestroyArray(&u);
}

static const mxArray *d_emlrt_marshallOut(const real_T u[25])
{
  static const int32_T i = 25;
  const mxArray *m;
  const mxArray *y;
  real_T *pData;
  int32_T b_i;
  y = NULL;
  m = emlrtCreateNumericArray(1, (const void *)&i, mxDOUBLE_CLASS, mxREAL);
  pData = emlrtMxGetPr(m);
  for (b_i = 0; b_i < 25; b_i++) {
    pData[b_i] = u[b_i];
  }
  emlrtAssign(&y, m);
  return y;
}

static uint32_T e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                   const emlrtMsgIdentifier *parentId)
{
  uint32_T y;
  y = r_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static const mxArray *e_emlrt_marshallOut(const emlrtStack *sp,
                                          const char_T u[3])
{
  static const int32_T iv[2] = {1, 3};
  const mxArray *m;
  const mxArray *y;
  y = NULL;
  m = emlrtCreateCharArray(2, &iv[0]);
  emlrtInitCharArrayR2013a((emlrtCTX)sp, 3, m, &u[0]);
  emlrtAssign(&y, m);
  return y;
}

static real_T (*emlrt_marshallIn(const emlrtStack *sp, const mxArray *z,
                                 const char_T *identifier))[5]
{
  emlrtMsgIdentifier thisId;
  real_T(*y)[5];
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = b_emlrt_marshallIn(sp, emlrtAlias(z), &thisId);
  emlrtDestroyArray(&z);
  return y;
}

static const mxArray *emlrt_marshallOut(const emlrtStack *sp,
                                        const incrementalRegressionLinear *u)
{
  static const int32_T enumValues[9] = {0, 1, 2, 3, 4, 5, 6, 7, 8};
  static const int32_T iv[2] = {1, 6};
  static const int32_T iv2[2] = {1, 3};
  static const int32_T iv3[2] = {1, 3};
  static const char_T t1_f1[18] = {'e', 'p', 's', 'i', 'l', 'o', 'n', 'i', 'n',
                                   's', 'e', 'n', 's', 'i', 't', 'i', 'v', 'e'};
  static const char_T *enumNames[9] = {
      "Logit",     "Doublelogit",    "Invlogit",       "Ismax",   "Sign",
      "Symmetric", "Symmetricismax", "Symmetriclogit", "Identity"};
  static const char_T b_u[6] = {'d', 'o', 'u', 'b', 'l', 'e'};
  static const char_T c_u[3] = {'s', 'g', 'd'};
  static const char_T *sv[2] = {"Cumulative", "Window"};
  static const char_T *s = "MeanSquaredError";
  cell_wrap_1 r;
  cell_wrap_2 r1;
  const mxArray *propValues[28];
  const mxArray *ab_y;
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
  const mxArray *m4;
  const mxArray *m5;
  const mxArray *m6;
  const mxArray *m7;
  const mxArray *m8;
  const mxArray *m9;
  const mxArray *m_y;
  const mxArray *n_y;
  const mxArray *o_y;
  const mxArray *p_y;
  const mxArray *q_y;
  const mxArray *r_y;
  const mxArray *s_y;
  const mxArray *t_y;
  const mxArray *u_y;
  const mxArray *v_y;
  const mxArray *w_y;
  const mxArray *x_y;
  const mxArray *y;
  const mxArray *y_y;
  int32_T iv1[2];
  int32_T i;
  const char_T *propClasses[28] = {
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
      "incremental.coder.regr.RegressionModel",
      "incremental.coder.regr.RegressionModel",
      "incremental.coder.regr.RegressionModel",
      "incremental.coder.Estimator",
      "incremental.coder.Estimator",
      "incremental.coder.Estimator",
      "incremental.coder.Linear",
      "incremental.coder.Linear",
      "incremental.coder.Linear",
      "incremental.coder.incrementalRegressionLinear",
      "incremental.coder.incrementalRegressionLinear"};
  const char_T *propNames[28] = {"NumPredictors",
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
                                 "ResponseTransform",
                                 "CustomResponseTransform",
                                 "AllowedRegrMetrics",
                                 "EstimationPeriod",
                                 "NumEstimationObservations",
                                 "parametersAdjusted",
                                 "Mode",
                                 "Impl",
                                 "Solver",
                                 "ModelSpecificMetrics",
                                 "EpsilonMetricAdjusted"};
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
  emlrtAssign(
      &y, emlrtCreateClassInstance2022a(
              (emlrtCTX)sp,
              (const char_T *)"incremental.coder.incrementalRegressionLinear"));
  m = NULL;
  b_y = NULL;
  m28 = emlrtCreateNumericMatrix(1, 1, mxUINT32_CLASS, mxREAL);
  *(uint32_T *)emlrtMxGetData(m28) = 20U;
  emlrtAssign(&b_y, m28);
  emlrtAssign(&m, b_y);
  propValues[0] = m;
  m1 = NULL;
  c_y = NULL;
  m28 = emlrtCreateNumericMatrix(1, 1, mxUINT32_CLASS, mxREAL);
  *(uint32_T *)emlrtMxGetData(m28) = u->NumTrainingObservations;
  emlrtAssign(&c_y, m28);
  emlrtAssign(&m1, c_y);
  propValues[1] = m1;
  m2 = NULL;
  d_y = NULL;
  m28 = emlrtCreateCharArray(2, &iv[0]);
  emlrtInitCharArrayR2013a((emlrtCTX)sp, 6, m28, &b_u[0]);
  emlrtAssign(&d_y, m28);
  emlrtAssign(&m2, d_y);
  propValues[2] = m2;
  m3 = NULL;
  e_y = NULL;
  m28 = emlrtCreateLogicalScalar(true);
  emlrtAssign(&e_y, m28);
  emlrtAssign(&m3, e_y);
  propValues[3] = m3;
  m4 = NULL;
  f_y = NULL;
  iv1[0] = 0;
  iv1[1] = 0;
  emlrtAssign(&f_y, emlrtCreateCellArrayR2014a(2, &iv1[0]));
  emlrtAssign(&m4, f_y);
  propValues[4] = m4;
  m5 = NULL;
  emlrtAssign(&m5, j_emlrt_marshallOut(sp));
  propValues[5] = m5;
  m6 = NULL;
  g_y = NULL;
  m28 = emlrtCreateLogicalScalar(true);
  emlrtAssign(&g_y, m28);
  emlrtAssign(&m6, g_y);
  propValues[6] = m6;
  m7 = NULL;
  h_y = NULL;
  m28 = emlrtCreateLogicalScalar(false);
  emlrtAssign(&h_y, m28);
  emlrtAssign(&m7, h_y);
  propValues[7] = m7;
  m8 = NULL;
  i_y = NULL;
  m28 = emlrtCreateLogicalScalar(true);
  emlrtAssign(&i_y, m28);
  emlrtAssign(&m8, i_y);
  propValues[8] = m8;
  m9 = NULL;
  j_y = NULL;
  m28 = emlrtCreateNumericMatrix(1, 1, mxUINT32_CLASS, mxREAL);
  *(uint32_T *)emlrtMxGetData(m28) = 50U;
  emlrtAssign(&j_y, m28);
  emlrtAssign(&m9, j_y);
  propValues[9] = m9;
  m10 = NULL;
  k_y = NULL;
  m28 = emlrtCreateNumericMatrix(1, 1, mxUINT32_CLASS, mxREAL);
  *(uint32_T *)emlrtMxGetData(m28) = 25U;
  emlrtAssign(&k_y, m28);
  emlrtAssign(&m10, k_y);
  propValues[10] = m10;
  m11 = NULL;
  l_y = NULL;
  m28 = emlrtCreateLogicalScalar(u->IsWarm);
  emlrtAssign(&l_y, m28);
  emlrtAssign(&m11, l_y);
  propValues[11] = m11;
  m12 = NULL;
  m_y = NULL;
  emlrtAssign(&m_y, emlrtCreateStructMatrix(1, 1, 1, (const char_T **)&s));
  n_y = NULL;
  emlrtAssign(&n_y, emlrtCreateStructMatrix(1, 1, 2, (const char_T **)&sv[0]));
  emlrtSetFieldR2017b(
      n_y, 0, (const char_T *)"Cumulative",
      c_emlrt_marshallOut(u->Metrics.MeanSquaredError.Cumulative), 0);
  emlrtSetFieldR2017b(n_y, 0, (const char_T *)"Window",
                      c_emlrt_marshallOut(u->Metrics.MeanSquaredError.Window),
                      1);
  emlrtSetFieldR2017b(m_y, 0, (const char_T *)"MeanSquaredError", n_y, 0);
  emlrtAssign(&m12, m_y);
  propValues[12] = m12;
  m13 = NULL;
  emlrtAssign(&m13, d_emlrt_marshallOut(u->MetricBuffer));
  propValues[13] = m13;
  m14 = NULL;
  emlrtAssign(&m14, d_emlrt_marshallOut(u->WeightBuffer));
  propValues[14] = m14;
  m15 = NULL;
  o_y = NULL;
  m28 = emlrtCreateNumericMatrix(1, 1, mxUINT32_CLASS, mxREAL);
  *(uint32_T *)emlrtMxGetData(m28) = u->BufferSize;
  emlrtAssign(&o_y, m28);
  emlrtAssign(&m15, o_y);
  propValues[15] = m15;
  m16 = NULL;
  p_y = NULL;
  m28 = emlrtCreateNumericMatrix(1, 1, mxUINT32_CLASS, mxREAL);
  *(uint32_T *)emlrtMxGetData(m28) = u->NumMetricObservations;
  emlrtAssign(&p_y, m28);
  emlrtAssign(&m16, p_y);
  propValues[16] = m16;
  m17 = NULL;
  q_y = NULL;
  m29 = NULL;
  emlrtCheckEnumR2012b((emlrtCTX)sp,
                       (const char_T *)"classreg.learning.coderutils.Transform",
                       9, (const char_T **)&enumNames[0], &enumValues[0]);
  r_y = NULL;
  m28 = emlrtCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
  *(int32_T *)emlrtMxGetData(m28) = 8;
  emlrtAssign(&r_y, m28);
  emlrtAssign(&m29, r_y);
  emlrtAssign(
      &q_y, emlrtCreateEnumR2012b(
                (emlrtCTX)sp,
                (const char_T *)"classreg.learning.coderutils.Transform", m29));
  emlrtDestroyArray(&m29);
  emlrtAssign(&m17, q_y);
  propValues[17] = m17;
  m18 = NULL;
  s_y = NULL;
  m28 = emlrtCreateLogicalScalar(false);
  emlrtAssign(&s_y, m28);
  emlrtAssign(&m18, s_y);
  propValues[18] = m18;
  r.f1[0] = 'm';
  r.f1[1] = 's';
  r.f1[2] = 'e';
  m19 = NULL;
  t_y = NULL;
  i = 1;
  emlrtAssign(&t_y, emlrtCreateCellArrayR2014a(1, &i));
  u_y = NULL;
  m28 = emlrtCreateCharArray(2, &iv2[0]);
  emlrtInitCharArrayR2013a((emlrtCTX)sp, 3, m28, &r.f1[0]);
  emlrtAssign(&u_y, m28);
  emlrtSetCell(t_y, 0, u_y);
  emlrtAssign(&m19, t_y);
  propValues[19] = m19;
  m20 = NULL;
  v_y = NULL;
  m28 = emlrtCreateNumericMatrix(1, 1, mxUINT32_CLASS, mxREAL);
  *(uint32_T *)emlrtMxGetData(m28) = 0U;
  emlrtAssign(&v_y, m28);
  emlrtAssign(&m20, v_y);
  propValues[20] = m20;
  m21 = NULL;
  w_y = NULL;
  m28 = emlrtCreateNumericMatrix(1, 1, mxUINT32_CLASS, mxREAL);
  *(uint32_T *)emlrtMxGetData(m28) = u->NumEstimationObservations;
  emlrtAssign(&w_y, m28);
  emlrtAssign(&m21, w_y);
  propValues[21] = m21;
  m22 = NULL;
  x_y = NULL;
  m28 = emlrtCreateLogicalScalar(u->parametersAdjusted);
  emlrtAssign(&x_y, m28);
  emlrtAssign(&m22, x_y);
  propValues[22] = m22;
  m23 = NULL;
  emlrtAssign(&m23, c_emlrt_marshallOut(0.0));
  propValues[23] = m23;
  m24 = NULL;
  emlrtAssign(&m24, f_emlrt_marshallOut(sp, &u->Impl));
  propValues[24] = m24;
  m25 = NULL;
  y_y = NULL;
  m28 = emlrtCreateCharArray(2, &iv3[0]);
  emlrtInitCharArrayR2013a((emlrtCTX)sp, 3, m28, &c_u[0]);
  emlrtAssign(&y_y, m28);
  emlrtAssign(&m25, y_y);
  propValues[25] = m25;
  for (i = 0; i < 18; i++) {
    r1.f1[i] = t1_f1[i];
  }
  m26 = NULL;
  emlrtAssign(&m26, h_emlrt_marshallOut(sp, r1));
  propValues[26] = m26;
  m27 = NULL;
  ab_y = NULL;
  m28 = emlrtCreateLogicalScalar(u->EpsilonMetricAdjusted);
  emlrtAssign(&ab_y, m28);
  emlrtAssign(&m27, ab_y);
  propValues[27] = m27;
  emlrtSetAllProperties((emlrtCTX)sp, &y, 0, 28, (const char_T **)&propNames[0],
                        (const char_T **)&propClasses[0], &propValues[0]);
  emlrtAssign(
      &y, emlrtConvertInstanceToRedirectSource(
              (emlrtCTX)sp, y, 0,
              (const char_T *)"incremental.coder.incrementalRegressionLinear"));
  return y;
}

static boolean_T f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                    const emlrtMsgIdentifier *parentId)
{
  boolean_T y;
  y = s_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static const mxArray *
f_emlrt_marshallOut(const emlrtStack *sp,
                    const incremental_coder_impl_SGDImpl *u)
{
  static const int32_T iv[2] = {1, 8};
  static const int32_T iv1[2] = {1, 0};
  static const int32_T iv10[2] = {0, 0};
  static const int32_T iv11[2] = {1, 12};
  static const int32_T iv12[2] = {0, 0};
  static const int32_T iv13[2] = {1, 5};
  static const int32_T iv2[2] = {1, 0};
  static const int32_T iv3[2] = {0, 0};
  static const int32_T iv4[2] = {0, 0};
  static const int32_T iv5[2] = {0, 0};
  static const int32_T iv6[2] = {0, 0};
  static const int32_T iv7[2] = {0, 0};
  static const int32_T iv8[2] = {0, 0};
  static const int32_T iv9[2] = {0, 0};
  static const char_T c_u[12] = {'l', 'e', 'a', 's', 't', 's',
                                 'q', 'u', 'a', 'r', 'e', 's'};
  static const char_T b_u[8] = {'d', 'e', 'c', 'a', 'y', 'i', 'n', 'g'};
  static const char_T d_u[5] = {'r', 'i', 'd', 'g', 'e'};
  static const char_T cv[3] = {'m', 's', 'e'};
  static const char_T cv1[3] = {'s', 'g', 'd'};
  const mxArray *propValues[35];
  const mxArray *ab_y;
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
  const mxArray *m4;
  const mxArray *m5;
  const mxArray *m6;
  const mxArray *m7;
  const mxArray *m8;
  const mxArray *m9;
  const mxArray *m_y;
  const mxArray *n_y;
  const mxArray *o_y;
  const mxArray *p_y;
  const mxArray *q_y;
  const mxArray *r_y;
  const mxArray *s_y;
  const mxArray *t_y;
  const mxArray *u_y;
  const mxArray *v_y;
  const mxArray *w_y;
  const mxArray *x_y;
  const mxArray *y;
  const mxArray *y_y;
  const char_T *propClasses[35] = {
      "incremental.coder.impl.Impl",       "incremental.coder.impl.Impl",
      "incremental.coder.impl.Impl",       "incremental.coder.impl.LinearImpl",
      "incremental.coder.impl.LinearImpl", "incremental.coder.impl.LinearImpl",
      "incremental.coder.impl.LinearImpl", "incremental.coder.impl.LinearImpl",
      "incremental.coder.impl.LinearImpl", "incremental.coder.impl.LinearImpl",
      "incremental.coder.impl.LinearImpl", "incremental.coder.impl.LinearImpl",
      "incremental.coder.impl.LinearImpl", "incremental.coder.impl.LinearImpl",
      "incremental.coder.impl.LinearImpl", "incremental.coder.impl.LinearImpl",
      "incremental.coder.impl.LinearImpl", "incremental.coder.impl.LinearImpl",
      "incremental.coder.impl.LinearImpl", "incremental.coder.impl.LinearImpl",
      "incremental.coder.impl.LinearImpl", "incremental.coder.impl.LinearImpl",
      "incremental.coder.impl.LinearImpl", "incremental.coder.impl.LinearImpl",
      "incremental.coder.impl.LinearImpl", "incremental.coder.impl.LinearImpl",
      "incremental.coder.impl.LinearImpl", "incremental.coder.impl.LinearImpl",
      "incremental.coder.impl.LinearImpl", "incremental.coder.impl.LinearImpl",
      "incremental.coder.impl.LinearImpl", "incremental.coder.impl.SGDImpl",
      "incremental.coder.impl.SGDImpl",    "incremental.coder.impl.SGDImpl",
      "incremental.coder.impl.SGDImpl"};
  const char_T *propNames[35] = {"ImplMode",
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
                                 "EstimateLearnRate",
                                 "LearnRateDenominatorHat",
                                 "LearnRateEstimationNeeded",
                                 "Regularization"};
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
  emlrtAssign(
      &y, emlrtCreateClassInstance2022a(
              (emlrtCTX)sp, (const char_T *)"incremental.coder.impl.SGDImpl"));
  m = NULL;
  b_y = NULL;
  m35 = emlrtCreateNumericMatrix(1, 1, mxUINT8_CLASS, mxREAL);
  *(uint8_T *)emlrtMxGetData(m35) = 0U;
  emlrtAssign(&b_y, m35);
  emlrtAssign(&m, b_y);
  propValues[0] = m;
  m1 = NULL;
  c_y = NULL;
  m35 = emlrtCreateLogicalScalar(true);
  emlrtAssign(&c_y, m35);
  emlrtAssign(&m1, c_y);
  propValues[1] = m1;
  m2 = NULL;
  emlrtAssign(&m2, c_emlrt_marshallOut(2.2204460492503131E-14));
  propValues[2] = m2;
  m3 = NULL;
  emlrtAssign(&m3, b_emlrt_marshallOut(5U));
  propValues[3] = m3;
  m4 = NULL;
  emlrtAssign(&m4, c_emlrt_marshallOut(u->LearnRate));
  propValues[4] = m4;
  m5 = NULL;
  emlrtAssign(&m5, c_emlrt_marshallOut(u->Epsilon));
  propValues[5] = m5;
  m6 = NULL;
  d_y = NULL;
  m35 = emlrtCreateLogicalScalar(true);
  emlrtAssign(&d_y, m35);
  emlrtAssign(&m6, d_y);
  propValues[6] = m6;
  m7 = NULL;
  e_y = NULL;
  m35 = emlrtCreateCharArray(2, &iv[0]);
  emlrtInitCharArrayR2013a((emlrtCTX)sp, 8, m35, &b_u[0]);
  emlrtAssign(&e_y, m35);
  emlrtAssign(&m7, e_y);
  propValues[7] = m7;
  m8 = NULL;
  emlrtAssign(&m8, g_emlrt_marshallOut(u->Beta));
  propValues[8] = m8;
  m9 = NULL;
  emlrtAssign(&m9, c_emlrt_marshallOut(u->Bias));
  propValues[9] = m9;
  m10 = NULL;
  f_y = NULL;
  m35 =
      emlrtCreateNumericArray(2, (const void *)&iv1[0], mxDOUBLE_CLASS, mxREAL);
  emlrtAssign(&f_y, m35);
  emlrtAssign(&m10, f_y);
  propValues[10] = m10;
  m11 = NULL;
  g_y = NULL;
  m35 =
      emlrtCreateNumericArray(2, (const void *)&iv2[0], mxDOUBLE_CLASS, mxREAL);
  emlrtAssign(&g_y, m35);
  emlrtAssign(&m11, g_y);
  propValues[11] = m11;
  m12 = NULL;
  emlrtAssign(&m12, c_emlrt_marshallOut(u->Lambda));
  propValues[12] = m12;
  m13 = NULL;
  emlrtAssign(&m13, e_emlrt_marshallOut(sp, cv));
  propValues[13] = m13;
  m14 = NULL;
  emlrtAssign(&m14, e_emlrt_marshallOut(sp, cv1));
  propValues[14] = m14;
  m15 = NULL;
  h_y = NULL;
  m35 = emlrtCreateLogicalScalar(false);
  emlrtAssign(&h_y, m35);
  emlrtAssign(&m15, h_y);
  propValues[15] = m15;
  m16 = NULL;
  i_y = NULL;
  m35 =
      emlrtCreateNumericArray(2, (const void *)&iv3[0], mxDOUBLE_CLASS, mxREAL);
  emlrtAssign(&i_y, m35);
  emlrtAssign(&m16, i_y);
  propValues[16] = m16;
  m17 = NULL;
  j_y = NULL;
  m35 =
      emlrtCreateNumericArray(2, (const void *)&iv4[0], mxDOUBLE_CLASS, mxREAL);
  emlrtAssign(&j_y, m35);
  emlrtAssign(&m17, j_y);
  propValues[17] = m17;
  m18 = NULL;
  k_y = NULL;
  m35 =
      emlrtCreateNumericArray(2, (const void *)&iv5[0], mxDOUBLE_CLASS, mxREAL);
  emlrtAssign(&k_y, m35);
  emlrtAssign(&m18, k_y);
  propValues[18] = m18;
  m19 = NULL;
  l_y = NULL;
  m35 =
      emlrtCreateNumericArray(2, (const void *)&iv6[0], mxDOUBLE_CLASS, mxREAL);
  emlrtAssign(&l_y, m35);
  emlrtAssign(&m19, l_y);
  propValues[19] = m19;
  m20 = NULL;
  m_y = NULL;
  m35 =
      emlrtCreateNumericArray(2, (const void *)&iv7[0], mxDOUBLE_CLASS, mxREAL);
  emlrtAssign(&m_y, m35);
  emlrtAssign(&m20, m_y);
  propValues[20] = m20;
  m21 = NULL;
  n_y = NULL;
  m35 =
      emlrtCreateNumericArray(2, (const void *)&iv8[0], mxDOUBLE_CLASS, mxREAL);
  emlrtAssign(&n_y, m35);
  emlrtAssign(&m21, n_y);
  propValues[21] = m21;
  m22 = NULL;
  o_y = NULL;
  m35 =
      emlrtCreateNumericArray(2, (const void *)&iv9[0], mxDOUBLE_CLASS, mxREAL);
  emlrtAssign(&o_y, m35);
  emlrtAssign(&m22, o_y);
  propValues[22] = m22;
  m23 = NULL;
  p_y = NULL;
  m35 = emlrtCreateNumericArray(2, (const void *)&iv10[0], mxDOUBLE_CLASS,
                                mxREAL);
  emlrtAssign(&p_y, m35);
  emlrtAssign(&m23, p_y);
  propValues[23] = m23;
  m24 = NULL;
  emlrtAssign(&m24, b_emlrt_marshallOut(u->BatchIndex));
  propValues[24] = m24;
  m25 = NULL;
  q_y = NULL;
  m35 = emlrtCreateLogicalScalar(false);
  emlrtAssign(&q_y, m35);
  emlrtAssign(&m25, q_y);
  propValues[25] = m25;
  m26 = NULL;
  r_y = NULL;
  m35 = emlrtCreateLogicalScalar(false);
  emlrtAssign(&r_y, m35);
  emlrtAssign(&m26, r_y);
  propValues[26] = m26;
  m27 = NULL;
  s_y = NULL;
  m35 = emlrtCreateLogicalScalar(false);
  emlrtAssign(&s_y, m35);
  emlrtAssign(&m27, s_y);
  propValues[27] = m27;
  m28 = NULL;
  t_y = NULL;
  m35 = emlrtCreateLogicalScalar(false);
  emlrtAssign(&t_y, m35);
  emlrtAssign(&m28, t_y);
  propValues[28] = m28;
  m29 = NULL;
  u_y = NULL;
  m35 = emlrtCreateLogicalScalar(false);
  emlrtAssign(&u_y, m35);
  emlrtAssign(&m29, u_y);
  propValues[29] = m29;
  m30 = NULL;
  v_y = NULL;
  m35 = emlrtCreateCharArray(2, &iv11[0]);
  emlrtInitCharArrayR2013a((emlrtCTX)sp, 12, m35, &c_u[0]);
  emlrtAssign(&v_y, m35);
  emlrtAssign(&m30, v_y);
  propValues[30] = m30;
  m31 = NULL;
  w_y = NULL;
  m35 = emlrtCreateLogicalScalar(false);
  emlrtAssign(&w_y, m35);
  emlrtAssign(&m31, w_y);
  propValues[31] = m31;
  m32 = NULL;
  x_y = NULL;
  m35 = emlrtCreateNumericArray(2, (const void *)&iv12[0], mxDOUBLE_CLASS,
                                mxREAL);
  emlrtAssign(&x_y, m35);
  emlrtAssign(&m32, x_y);
  propValues[32] = m32;
  m33 = NULL;
  y_y = NULL;
  m35 = emlrtCreateLogicalScalar(false);
  emlrtAssign(&y_y, m35);
  emlrtAssign(&m33, y_y);
  propValues[33] = m33;
  m34 = NULL;
  ab_y = NULL;
  m35 = emlrtCreateCharArray(2, &iv13[0]);
  emlrtInitCharArrayR2013a((emlrtCTX)sp, 5, m35, &d_u[0]);
  emlrtAssign(&ab_y, m35);
  emlrtAssign(&m34, ab_y);
  propValues[34] = m34;
  emlrtSetAllProperties((emlrtCTX)sp, &y, 0, 35, (const char_T **)&propNames[0],
                        (const char_T **)&propClasses[0], &propValues[0]);
  emlrtAssign(&y, emlrtConvertInstanceToRedirectSource(
                      (emlrtCTX)sp, y, 0,
                      (const char_T *)"incremental.coder.impl.SGDImpl"));
  return y;
}

static struct0_T g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                    const emlrtMsgIdentifier *parentId)
{
  static const int32_T dims = 0;
  static const char_T *fieldNames = "MeanSquaredError";
  emlrtMsgIdentifier thisId;
  struct0_T y;
  thisId.fParent = parentId;
  thisId.bParentIsCell = false;
  emlrtCheckStructR2012b((emlrtCTX)sp, parentId, u, 1,
                         (const char_T **)&fieldNames, 0U, (void *)&dims);
  thisId.fIdentifier = "MeanSquaredError";
  y.MeanSquaredError = h_emlrt_marshallIn(
      sp,
      emlrtAlias(emlrtGetFieldR2017b((emlrtCTX)sp, u, 0, 0,
                                     (const char_T *)"MeanSquaredError")),
      &thisId);
  emlrtDestroyArray(&u);
  return y;
}

static const mxArray *g_emlrt_marshallOut(const real_T u[20])
{
  static const int32_T i = 20;
  const mxArray *m;
  const mxArray *y;
  real_T *pData;
  int32_T b_i;
  y = NULL;
  m = emlrtCreateNumericArray(1, (const void *)&i, mxDOUBLE_CLASS, mxREAL);
  pData = emlrtMxGetPr(m);
  for (b_i = 0; b_i < 20; b_i++) {
    pData[b_i] = u[b_i];
  }
  emlrtAssign(&y, m);
  return y;
}

static struct1_T h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
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
  y.Cumulative = i_emlrt_marshallIn(
      sp,
      emlrtAlias(emlrtGetFieldR2017b((emlrtCTX)sp, u, 0, 0,
                                     (const char_T *)"Cumulative")),
      &thisId);
  thisId.fIdentifier = "Window";
  y.Window =
      i_emlrt_marshallIn(sp,
                         emlrtAlias(emlrtGetFieldR2017b(
                             (emlrtCTX)sp, u, 0, 1, (const char_T *)"Window")),
                         &thisId);
  emlrtDestroyArray(&u);
  return y;
}

static const mxArray *h_emlrt_marshallOut(const emlrtStack *sp,
                                          const cell_wrap_2 u)
{
  static const int32_T iv[2] = {1, 18};
  const mxArray *b_y;
  const mxArray *m;
  const mxArray *y;
  int32_T i;
  y = NULL;
  i = 1;
  emlrtAssign(&y, emlrtCreateCellArrayR2014a(1, &i));
  b_y = NULL;
  m = emlrtCreateCharArray(2, &iv[0]);
  emlrtInitCharArrayR2013a((emlrtCTX)sp, 18, m, &u.f1[0]);
  emlrtAssign(&b_y, m);
  emlrtSetCell(y, 0, b_y);
  return y;
}

static real_T i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                 const emlrtMsgIdentifier *parentId)
{
  real_T y;
  y = t_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static const mxArray *i_emlrt_marshallOut(const real_T u[5])
{
  static const int32_T i = 0;
  static const int32_T i1 = 5;
  const mxArray *m;
  const mxArray *y;
  y = NULL;
  m = emlrtCreateNumericArray(1, (const void *)&i, mxDOUBLE_CLASS, mxREAL);
  emlrtMxSetData((mxArray *)m, (void *)&u[0]);
  emlrtSetDimensions((mxArray *)m, &i1, 1);
  emlrtAssign(&y, m);
  return y;
}

static void j_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId, real_T y[25])
{
  u_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static const mxArray *j_emlrt_marshallOut(const emlrtStack *sp)
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
  int32_T i;
  y = NULL;
  i = 1;
  emlrtAssign(&y, emlrtCreateCellArrayR2014a(1, &i));
  b_y = NULL;
  m = NULL;
  emlrtCheckEnumR2012b((emlrtCTX)sp,
                       (const char_T *)"incremental.coderutils.Loss", 8,
                       (const char_T **)&enumNames[0], &enumValues[0]);
  c_y = NULL;
  m1 = emlrtCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
  *(int32_T *)emlrtMxGetData(m1) = (int32_T)MeanSquaredError;
  emlrtAssign(&c_y, m1);
  emlrtAssign(&m, c_y);
  emlrtAssign(&b_y, emlrtCreateEnumR2012b(
                        (emlrtCTX)sp,
                        (const char_T *)"incremental.coderutils.Loss", m));
  emlrtDestroyArray(&m);
  emlrtSetCell(y, 0, b_y);
  return y;
}

static void k_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               incremental_coder_impl_SGDImpl *y)
{
  emlrtMsgIdentifier thisId;
  const mxArray *propValues[11];
  int32_T i;
  const char_T *propClasses[11] = {
      "incremental.coder.impl.LinearImpl", "incremental.coder.impl.LinearImpl",
      "incremental.coder.impl.LinearImpl", "incremental.coder.impl.LinearImpl",
      "incremental.coder.impl.LinearImpl", "incremental.coder.impl.LinearImpl",
      "incremental.coder.impl.LinearImpl", "incremental.coder.impl.LinearImpl",
      "incremental.coder.impl.LinearImpl", "incremental.coder.impl.LinearImpl",
      "incremental.coder.impl.LinearImpl"};
  const char_T *propNames[11] = {"LearnRate", "Epsilon", "Beta",      "Bias",
                                 "Mu",        "Sigma",   "Lambda",    "MuHat",
                                 "VarHat",    "Stream",  "BatchIndex"};
  for (i = 0; i < 11; i++) {
    propValues[i] = NULL;
  }
  thisId.fParent = parentId;
  thisId.bParentIsCell = false;
  emlrtCheckMcosClass2017a((emlrtCTX)sp, parentId, u,
                           (const char_T *)"incremental.coder.impl.SGDImpl");
  emlrtGetAllProperties((emlrtCTX)sp, u, 0, 11, (const char_T **)&propNames[0],
                        (const char_T **)&propClasses[0], &propValues[0]);
  thisId.fIdentifier = "LearnRate";
  y->LearnRate = i_emlrt_marshallIn(sp, emlrtAlias(propValues[0]), &thisId);
  thisId.fIdentifier = "Epsilon";
  y->Epsilon = i_emlrt_marshallIn(sp, emlrtAlias(propValues[1]), &thisId);
  thisId.fIdentifier = "Beta";
  l_emlrt_marshallIn(sp, emlrtAlias(propValues[2]), &thisId, y->Beta);
  thisId.fIdentifier = "Bias";
  y->Bias = i_emlrt_marshallIn(sp, emlrtAlias(propValues[3]), &thisId);
  thisId.fIdentifier = "Mu";
  m_emlrt_marshallIn(sp, emlrtAlias(propValues[4]), &thisId);
  thisId.fIdentifier = "Sigma";
  m_emlrt_marshallIn(sp, emlrtAlias(propValues[5]), &thisId);
  thisId.fIdentifier = "Lambda";
  y->Lambda = i_emlrt_marshallIn(sp, emlrtAlias(propValues[6]), &thisId);
  thisId.fIdentifier = "MuHat";
  n_emlrt_marshallIn(sp, emlrtAlias(propValues[7]), &thisId);
  thisId.fIdentifier = "VarHat";
  n_emlrt_marshallIn(sp, emlrtAlias(propValues[8]), &thisId);
  thisId.fIdentifier = "Stream";
  n_emlrt_marshallIn(sp, emlrtAlias(propValues[9]), &thisId);
  thisId.fIdentifier = "BatchIndex";
  y->BatchIndex = e_emlrt_marshallIn(sp, emlrtAlias(propValues[10]), &thisId);
  emlrtDestroyArrays(11, &propValues[0]);
  emlrtDestroyArray(&u);
}

static void l_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId, real_T y[20])
{
  v_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void m_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId)
{
  w_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
}

static void n_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId)
{
  x_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
}

static real_T (*o_emlrt_marshallIn(const emlrtStack *sp, const mxArray *X,
                                   const char_T *identifier))[100]
{
  emlrtMsgIdentifier thisId;
  real_T(*y)[100];
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = p_emlrt_marshallIn(sp, emlrtAlias(X), &thisId);
  emlrtDestroyArray(&X);
  return y;
}

static real_T (*p_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                   const emlrtMsgIdentifier *parentId))[100]
{
  real_T(*y)[100];
  y = y_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static real_T (*q_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                   const emlrtMsgIdentifier *msgId))[5]
{
  static const int32_T dims = 5;
  real_T(*ret)[5];
  emlrtCheckBuiltInR2012b((emlrtCTX)sp, msgId, src, (const char_T *)"double",
                          false, 1U, (void *)&dims);
  ret = (real_T(*)[5])emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

static uint32_T r_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
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

static boolean_T s_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
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

static real_T t_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
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

static void u_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId, real_T ret[25])
{
  static const int32_T dims = 25;
  real_T(*r)[25];
  int32_T i;
  emlrtCheckBuiltInR2012b((emlrtCTX)sp, msgId, src, (const char_T *)"double",
                          false, 1U, (void *)&dims);
  r = (real_T(*)[25])emlrtMxGetData(src);
  for (i = 0; i < 25; i++) {
    ret[i] = (*r)[i];
  }
  emlrtDestroyArray(&src);
}

static void v_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId, real_T ret[20])
{
  static const int32_T dims = 20;
  real_T(*r)[20];
  int32_T i;
  emlrtCheckBuiltInR2012b((emlrtCTX)sp, msgId, src, (const char_T *)"double",
                          false, 1U, (void *)&dims);
  r = (real_T(*)[20])emlrtMxGetData(src);
  for (i = 0; i < 20; i++) {
    ret[i] = (*r)[i];
  }
  emlrtDestroyArray(&src);
}

static void w_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId)
{
  static const int32_T dims[2] = {1, 0};
  emlrtCheckBuiltInR2012b((emlrtCTX)sp, msgId, src, (const char_T *)"double",
                          false, 2U, (void *)&dims[0]);
  emlrtMxGetData(src);
  emlrtDestroyArray(&src);
}

static void x_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId)
{
  static const int32_T dims[2] = {0, 0};
  emlrtCheckBuiltInR2012b((emlrtCTX)sp, msgId, src, (const char_T *)"double",
                          false, 2U, (void *)&dims[0]);
  emlrtMxGetData(src);
  emlrtDestroyArray(&src);
}

static real_T (*y_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                   const emlrtMsgIdentifier *msgId))[100]
{
  static const int32_T dims[2] = {5, 20};
  real_T(*ret)[100];
  emlrtCheckBuiltInR2012b((emlrtCTX)sp, msgId, src, (const char_T *)"double",
                          false, 2U, (void *)&dims[0]);
  ret = (real_T(*)[100])emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

void c_myUpdateMetricsAndFitIncrLear(const mxArray *const prhs[3],
                                     const mxArray **plhs)
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  incrementalRegressionLinear incrementalModel;
  real_T(*X)[100];
  real_T(*Y)[5];
  st.tls = emlrtRootTLSGlobal;
  /* Marshall function inputs */
  c_emlrt_marshallIn(&st, emlrtAliasP(prhs[0]), "incrementalModel",
                     &incrementalModel);
  X = o_emlrt_marshallIn(&st, emlrtAlias(prhs[1]), "X");
  Y = emlrt_marshallIn(&st, emlrtAlias(prhs[2]), "Y");
  /* Invoke the target function */
  myUpdateMetricsAndFitIncrLearn(&incrementalModel, *X, *Y);
  /* Marshall function outputs */
  *plhs = emlrt_marshallOut(&st, &incrementalModel);
}

void myFitIncrLearn_api(const mxArray *const prhs[3], const mxArray **plhs)
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  incrementalRegressionLinear incrementalModel;
  real_T(*X)[100];
  real_T(*Y)[5];
  st.tls = emlrtRootTLSGlobal;
  /* Marshall function inputs */
  c_emlrt_marshallIn(&st, emlrtAliasP(prhs[0]), "incrementalModel",
                     &incrementalModel);
  X = o_emlrt_marshallIn(&st, emlrtAlias(prhs[1]), "X");
  Y = emlrt_marshallIn(&st, emlrtAlias(prhs[2]), "Y");
  /* Invoke the target function */
  myFitIncrLearn(&incrementalModel, *X, *Y);
  /* Marshall function outputs */
  *plhs = emlrt_marshallOut(&st, &incrementalModel);
}

void myInitialModelIncrLearn_api(const mxArray **plhs)
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  incrementalRegressionLinear incrementalModel;
  st.tls = emlrtRootTLSGlobal;
  /* Invoke the target function */
  myInitialModelIncrLearn(&incrementalModel);
  /* Marshall function outputs */
  *plhs = emlrt_marshallOut(&st, &incrementalModel);
}

void myInitialModelIncrLearn_atexit(void)
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtEnterRtStackR2012b(&st);
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
  myInitialModelIncrLearn_xil_terminate();
  myInitialModelIncrLearn_xil_shutdown();
  emlrtExitTimeCleanup(&emlrtContextGlobal);
}

void myInitialModelIncrLearn_initialize(void)
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtClearAllocCountR2012b(&st, false, 0U, NULL);
  emlrtEnterRtStackR2012b(&st);
  emlrtFirstTimeR2012b(emlrtRootTLSGlobal);
}

void myInitialModelIncrLearn_terminate(void)
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  st.tls = emlrtRootTLSGlobal;
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

void myMAE_api(const mxArray *const prhs[2], const mxArray **plhs)
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  real_T(*result)[5];
  real_T(*z)[5];
  real_T(*zfit)[5];
  st.tls = emlrtRootTLSGlobal;
  result = (real_T(*)[5])mxMalloc(sizeof(real_T[5]));
  /* Marshall function inputs */
  z = emlrt_marshallIn(&st, emlrtAlias(prhs[0]), "z");
  zfit = emlrt_marshallIn(&st, emlrtAlias(prhs[1]), "zfit");
  /* Invoke the target function */
  myMAE(*z, *zfit, *result);
  /* Marshall function outputs */
  *plhs = i_emlrt_marshallOut(*result);
}

void myMAPE_api(const mxArray *const prhs[2], const mxArray **plhs)
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  real_T(*z)[5];
  real_T(*zfit)[5];
  real_T result;
  st.tls = emlrtRootTLSGlobal;
  /* Marshall function inputs */
  z = emlrt_marshallIn(&st, emlrtAlias(prhs[0]), "z");
  zfit = emlrt_marshallIn(&st, emlrtAlias(prhs[1]), "zfit");
  /* Invoke the target function */
  result = myMAPE(*z, *zfit);
  /* Marshall function outputs */
  *plhs = c_emlrt_marshallOut(result);
}

void myMSE_api(const mxArray *const prhs[2], const mxArray **plhs)
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  real_T(*z)[5];
  real_T(*zfit)[5];
  real_T result;
  st.tls = emlrtRootTLSGlobal;
  /* Marshall function inputs */
  z = emlrt_marshallIn(&st, emlrtAlias(prhs[0]), "z");
  zfit = emlrt_marshallIn(&st, emlrtAlias(prhs[1]), "zfit");
  /* Invoke the target function */
  result = myMSE(*z, *zfit);
  /* Marshall function outputs */
  *plhs = c_emlrt_marshallOut(result);
}

void myPredictIncrLearn_api(const mxArray *const prhs[2], const mxArray **plhs)
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  incrementalRegressionLinear incrementalModel;
  real_T(*X)[100];
  real_T(*labels)[5];
  st.tls = emlrtRootTLSGlobal;
  labels = (real_T(*)[5])mxMalloc(sizeof(real_T[5]));
  /* Marshall function inputs */
  c_emlrt_marshallIn(&st, emlrtAliasP(prhs[0]), "incrementalModel",
                     &incrementalModel);
  X = o_emlrt_marshallIn(&st, emlrtAlias(prhs[1]), "X");
  /* Invoke the target function */
  myPredictIncrLearn(incrementalModel, *X, *labels);
  /* Marshall function outputs */
  *plhs = i_emlrt_marshallOut(*labels);
}

void myRMSE_api(const mxArray *const prhs[2], const mxArray **plhs)
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  real_T(*z)[5];
  real_T(*zfit)[5];
  real_T result;
  st.tls = emlrtRootTLSGlobal;
  /* Marshall function inputs */
  z = emlrt_marshallIn(&st, emlrtAlias(prhs[0]), "z");
  zfit = emlrt_marshallIn(&st, emlrtAlias(prhs[1]), "zfit");
  /* Invoke the target function */
  result = myRMSE(*z, *zfit);
  /* Marshall function outputs */
  *plhs = c_emlrt_marshallOut(result);
}

/* End of code generation (_coder_myInitialModelIncrLearn_api.c) */
