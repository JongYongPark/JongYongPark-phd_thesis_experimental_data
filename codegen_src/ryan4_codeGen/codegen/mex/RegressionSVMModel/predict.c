/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * predict.c
 *
 * Code generation for function 'predict'
 *
 */

/* Include files */
#include "predict.h"
#include "Gaussian.h"
#include "Linear.h"
#include "Poly.h"
#include "RegressionSVMModel_data.h"
#include "RegressionSVMModel_types.h"
#include "mtimes.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo h_emlrtRSI = {
    3,         /* lineNo */
    "predict", /* fcnName */
    "C:\\nobackup\\_phd_work\\_battery_soh\\_matlab_battery\\_mywork\\_"
    "latest\\ryan4_codeGen\\predict.m" /* pathName */
};

static emlrtRSInfo i_emlrtRSI = {
    19,           /* lineNo */
    "initialize", /* fcnName */
    "C:\\nobackup\\_phd_work\\_battery_soh\\_matlab_battery\\_mywork\\_"
    "latest\\ryan4_codeGen\\initialize.m" /* pathName */
};

static emlrtRSInfo j_emlrtRSI = {
    176,                            /* lineNo */
    "CompactRegressionSVM/predict", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\stats\\classreg\\+classreg\\+learning\\+"
    "coder\\+regr\\CompactRegressionSVM.m" /* pathName */
};

static emlrtRSInfo k_emlrtRSI = {
    179,                            /* lineNo */
    "CompactRegressionSVM/predict", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\stats\\classreg\\+classreg\\+learning\\+"
    "coder\\+regr\\CompactRegressionSVM.m" /* pathName */
};

static emlrtRSInfo l_emlrtRSI = {
    249,                /* lineNo */
    "CompactSVM/score", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\stats\\classreg\\+classreg\\+learning\\+"
    "coder\\+model\\CompactSVM.m" /* pathName */
};

static emlrtRSInfo m_emlrtRSI = {
    323,                      /* lineNo */
    "CompactSVM/kernelScore", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\stats\\classreg\\+classreg\\+learning\\+"
    "coder\\+model\\CompactSVM.m" /* pathName */
};

static emlrtRSInfo n_emlrtRSI = {
    324,                      /* lineNo */
    "CompactSVM/kernelScore", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\stats\\classreg\\+classreg\\+learning\\+"
    "coder\\+model\\CompactSVM.m" /* pathName */
};

static emlrtRSInfo o_emlrtRSI = {
    342,                      /* lineNo */
    "CompactSVM/kernelScore", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\stats\\classreg\\+classreg\\+learning\\+"
    "coder\\+model\\CompactSVM.m" /* pathName */
};

static emlrtRSInfo p_emlrtRSI = {
    343,                      /* lineNo */
    "CompactSVM/kernelScore", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\stats\\classreg\\+classreg\\+learning\\+"
    "coder\\+model\\CompactSVM.m" /* pathName */
};

static emlrtRSInfo v_emlrtRSI = {
    41,                                         /* lineNo */
    "CompactRegressionModel/transformResponse", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\stats\\classreg\\+classreg\\+learning\\+"
    "coder\\+regr\\CompactRegressionModel.m" /* pathName */
};

static emlrtRSInfo w_emlrtRSI = {
    123,                          /* lineNo */
    "CompactPredictor/transform", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\stats\\classreg\\+classreg\\+learning\\+"
    "coder\\CompactPredictor.m" /* pathName */
};

static emlrtRSInfo x_emlrtRSI = {
    125,                          /* lineNo */
    "CompactPredictor/transform", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\stats\\classreg\\+classreg\\+learning\\+"
    "coder\\CompactPredictor.m" /* pathName */
};

static emlrtRSInfo y_emlrtRSI = {
    127,                          /* lineNo */
    "CompactPredictor/transform", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\stats\\classreg\\+classreg\\+learning\\+"
    "coder\\CompactPredictor.m" /* pathName */
};

static emlrtRSInfo ab_emlrtRSI = {
    131,                          /* lineNo */
    "CompactPredictor/transform", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\stats\\classreg\\+classreg\\+learning\\+"
    "coder\\CompactPredictor.m" /* pathName */
};

static emlrtRSInfo bb_emlrtRSI = {
    137,                          /* lineNo */
    "CompactPredictor/transform", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\stats\\classreg\\+classreg\\+learning\\+"
    "coder\\CompactPredictor.m" /* pathName */
};

static emlrtRSInfo cb_emlrtRSI = {
    15,         /* lineNo */
    "invlogit", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\stats\\classreg\\+classreg\\+learning\\+"
    "coder\\+transform\\invlogit.m" /* pathName */
};

static emlrtRTEInfo emlrtRTEI = {
    358,                      /* lineNo */
    55,                       /* colNo */
    "CompactSVM/kernelScore", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\stats\\classreg\\+classreg\\+learning\\+"
    "coder\\+model\\CompactSVM.m" /* pName */
};

static emlrtRTEInfo b_emlrtRTEI =
    {
        14,    /* lineNo */
        9,     /* colNo */
        "log", /* fName */
        "C:\\Program "
        "Files\\MATLAB\\R2022a\\toolbox\\eml\\lib\\matlab\\elfun\\log.m" /* pName
                                                                          */
};

/* Function Definitions */
void predict(const emlrtStack *sp, const real_T X[200], real_T varargout_1[100])
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack st;
  real_T svT[150];
  real_T in[100];
  real_T svInnerProduct[75];
  real_T c_tmp;
  int32_T i;
  int32_T i2;
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
  /*  Autogenerated by MATLAB, 05-Jun-2022 21:01:47 */
  st.site = &h_emlrtRSI;
  /*  Autogenerated by MATLAB, 05-Jun-2022 21:01:47 */
  /*  Predict Inputs: X */
  b_st.site = &i_emlrtRSI;
  c_st.site = &j_emlrtRSI;
  d_st.site = &l_emlrtRSI;
  for (i2 = 0; i2 < 150; i2++) {
    svT[i2] = model.SupportVectorsT[i2] / model.Scale;
  }
  switch (model.KernelFunction) {
  case linear: {
    real_T b_X[200];
    for (i2 = 0; i2 < 200; i2++) {
      b_X[i2] = X[i2] / model.Scale;
    }
    real_T innerProduct[7500];
    e_st.site = &m_emlrtRSI;
    Linear(svT, b_X, innerProduct);
    e_st.site = &n_emlrtRSI;
    memcpy(&svInnerProduct[0], &model.Alpha[0], 75U * sizeof(real_T));
    b_mtimes(innerProduct, svInnerProduct, varargout_1);
    for (i2 = 0; i2 < 100; i2++) {
      varargout_1[i2] += model.Bias;
    }
  } break;
  case polynomial: {
    real_T b_X[200];
    for (i2 = 0; i2 < 200; i2++) {
      b_X[i2] = X[i2] / model.Scale;
    }
    real_T innerProduct[7500];
    e_st.site = &o_emlrtRSI;
    Poly(&e_st, svT, model.Order, b_X, innerProduct);
    e_st.site = &p_emlrtRSI;
    memcpy(&svInnerProduct[0], &model.Alpha[0], 75U * sizeof(real_T));
    b_mtimes(innerProduct, svInnerProduct, varargout_1);
    for (i2 = 0; i2 < 100; i2++) {
      varargout_1[i2] += model.Bias;
    }
  } break;
  default: {
    if ((int32_T)model.KernelFunction != 2) {
      emlrtErrorWithMessageIdR2018a(
          &d_st, &emlrtRTEI,
          "stats:classreg:learning:modelparams:SVMParams:make:"
          "KernelFunctionNotRecognized",
          "stats:classreg:learning:modelparams:SVMParams:make:"
          "KernelFunctionNotRecognized",
          0);
    }
    i2 = 1;
    for (i = 0; i < 75; i++) {
      int32_T i1;
      i1 = i2 - 1;
      i2 += 2;
      c_tmp = svT[i1 + 1];
      svInnerProduct[i] = svT[i1] * svT[i1] + c_tmp * c_tmp;
    }
    for (i = 0; i < 100; i++) {
      real_T dv[75];
      real_T c_X[2];
      c_X[0] = X[i] / model.Scale;
      c_X[1] = X[i + 100] / model.Scale;
      Gaussian(svT, svInnerProduct, c_X, dv);
      c_tmp = 0.0;
      for (i2 = 0; i2 < 75; i2++) {
        c_tmp += dv[i2] * model.Alpha[i2];
      }
      varargout_1[i] = c_tmp + model.Bias;
    }
  } break;
  }
  c_st.site = &k_emlrtRSI;
  d_st.site = &v_emlrtRSI;
  switch (model.ResponseTransform) {
  case Logit:
    e_st.site = &w_emlrtRSI;
    for (i = 0; i < 100; i++) {
      varargout_1[i] = 1.0 / (muDoubleScalarExp(-varargout_1[i]) + 1.0);
    }
    break;
  case Doublelogit:
    e_st.site = &x_emlrtRSI;
    for (i = 0; i < 100; i++) {
      varargout_1[i] = 1.0 / (muDoubleScalarExp(-2.0 * varargout_1[i]) + 1.0);
    }
    break;
  case Invlogit:
    e_st.site = &y_emlrtRSI;
    memcpy(&in[0], &varargout_1[0], 100U * sizeof(real_T));
    for (i = 0; i < 100; i++) {
      c_tmp = in[i];
      if (c_tmp == 0.0) {
        varargout_1[i] = rtMinusInf;
      } else if (c_tmp == 1.0) {
        varargout_1[i] = rtInf;
      } else if (muDoubleScalarIsNaN(c_tmp)) {
        varargout_1[i] = rtNaN;
      } else {
        f_st.site = &cb_emlrtRSI;
        c_tmp /= 1.0 - c_tmp;
        if (c_tmp < 0.0) {
          emlrtErrorWithMessageIdR2018a(
              &f_st, &b_emlrtRTEI, "Coder:toolbox:ElFunDomainError",
              "Coder:toolbox:ElFunDomainError", 3, 4, 3, "log");
        }
        varargout_1[i] = muDoubleScalarLog(c_tmp);
      }
    }
    break;
  case Ismax:
    for (i = 0; i < 100; i++) {
      varargout_1[i] = 1.0;
    }
    break;
  case Sign:
    e_st.site = &ab_emlrtRSI;
    for (i = 0; i < 100; i++) {
      c_tmp = varargout_1[i];
      if (c_tmp < 0.0) {
        c_tmp = -1.0;
      } else {
        c_tmp = (c_tmp > 0.0);
      }
      varargout_1[i] = c_tmp;
    }
    break;
  case Symmetric:
    for (i2 = 0; i2 < 100; i2++) {
      varargout_1[i2] = 2.0 * varargout_1[i2] - 1.0;
    }
    break;
  case Symmetricismax:
    for (i = 0; i < 100; i++) {
      varargout_1[i] = 1.0;
    }
    break;
  case Symmetriclogit:
    e_st.site = &bb_emlrtRSI;
    for (i = 0; i < 100; i++) {
      varargout_1[i] =
          2.0 * (1.0 / (muDoubleScalarExp(-varargout_1[i]) + 1.0)) - 1.0;
    }
    break;
  }
}

/* End of code generation (predict.c) */
