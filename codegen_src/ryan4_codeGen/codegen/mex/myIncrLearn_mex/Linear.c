/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Linear.c
 *
 * Code generation for function 'Linear'
 *
 */

/* Include files */
#include "Linear.h"
#include "LinearImpl.h"
#include "myIncrLearn_mex_types.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"

/* Variable Definitions */
static emlrtRSInfo nc_emlrtRSI = {
    53,             /* lineNo */
    "Linear/score", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\stats\\incremental\\+incremental\\+"
    "coder\\Linear.m" /* pathName */
};

static emlrtRSInfo jh_emlrtRSI = {
    46,                                 /* lineNo */
    "Linear/fitModelWithoutValidation", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\stats\\incremental\\+incremental\\+"
    "coder\\Linear.m" /* pathName */
};

static emlrtRSInfo kh_emlrtRSI = {
    200,              /* lineNo */
    "LinearImpl/fit", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\stats\\incremental\\+incremental\\+"
    "coder\\+impl\\LinearImpl.m" /* pathName */
};

static emlrtRSInfo lh_emlrtRSI = {
    79,                             /* lineNo */
    "ScaleInvariantImpl/fitLinear", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\stats\\incremental\\+incremental\\+"
    "coder\\+impl\\ScaleInvariantImpl.m" /* pathName */
};

static emlrtRSInfo mh_emlrtRSI = {
    248,     /* lineNo */
    "train", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\stats\\incremental\\+incremental\\+"
    "coder\\+impl\\ScaleInvariantImpl.m" /* pathName */
};

static emlrtRSInfo nh_emlrtRSI = {
    233,     /* lineNo */
    "train", /* fcnName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\stats\\incremental\\+incremental\\+"
    "coder\\+impl\\ScaleInvariantImpl.m" /* pathName */
};

static emlrtRTEInfo s_emlrtRTEI = {
    13,     /* lineNo */
    9,      /* colNo */
    "sqrt", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\eml\\lib\\matlab\\elfun\\sqrt.m" /* pName
                                                                       */
};

static emlrtBCInfo pg_emlrtBCI = {
    -1,      /* iFirst */
    -1,      /* iLast */
    191,     /* lineNo */
    19,      /* colNo */
    "",      /* aName */
    "train", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\stats\\incremental\\+incremental\\+"
    "coder\\+impl\\ScaleInvariantImpl.m", /* pName */
    0                                     /* checkKind */
};

static emlrtBCInfo qg_emlrtBCI = {
    -1,      /* iFirst */
    -1,      /* iLast */
    269,     /* lineNo */
    72,      /* colNo */
    "",      /* aName */
    "train", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\stats\\incremental\\+incremental\\+"
    "coder\\+impl\\ScaleInvariantImpl.m", /* pName */
    0                                     /* checkKind */
};

static emlrtBCInfo rg_emlrtBCI = {
    -1,      /* iFirst */
    -1,      /* iLast */
    189,     /* lineNo */
    23,      /* colNo */
    "",      /* aName */
    "train", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\stats\\incremental\\+incremental\\+"
    "coder\\+impl\\ScaleInvariantImpl.m", /* pName */
    0                                     /* checkKind */
};

/* Function Definitions */
void Linear_score(const emlrtStack *sp, const real_T this_Impl_Beta[60],
                  real_T this_Impl_Bias, const emxArray_real_T *X,
                  const boolean_T indsToExclude_data[],
                  const int32_T *indsToExclude_size, emxArray_real_T *s)
{
  emlrtStack st;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &nc_emlrtRSI;
  LinearImpl_score(&st, this_Impl_Beta, this_Impl_Bias, X, indsToExclude_data,
                   *indsToExclude_size, s);
}

void c_Linear_fitModelWithoutValidat(const emlrtStack *sp,
                                     e_incrementalClassificationLine *this,
                                     const emxArray_real_T *X,
                                     const emxArray_int32_T *Y,
                                     const boolean_T indsToExclude_data[],
                                     int32_T indsToExclude_size,
                                     uint32_T obsCount)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack st;
  const real_T *X_data;
  const int32_T *Y_data;
  int32_T i;
  int32_T ii;
  int32_T jj;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  Y_data = Y->data;
  X_data = X->data;
  st.site = &jh_emlrtRSI;
  b_st.site = &kh_emlrtRSI;
  if (X->size[0] != 0) {
    real_T denom;
    uint32_T u;
    denom = (real_T)X->size[0] - (real_T)obsCount;
    if (denom >= 0.0) {
      u = (uint32_T)denom;
    } else {
      u = 0U;
    }
    if ((int32_T)u != 0) {
      real_T bias;
      real_T learnrate;
      real_T val_tmp_tmp;
      c_st.site = &lh_emlrtRSI;
      bias = this->Impl.Bias;
      val_tmp_tmp = this->Impl.Ymt;
      learnrate = this->Impl.LearnRate;
      if ((this->Impl.Ymt > 0.0) && (this->Impl.Ymt != 1.0)) {
        for (i = 0; i < 60; i++) {
          this->Impl.Beta[i] /= this->Impl.Ymt;
        }
        bias = this->Impl.Bias / this->Impl.Ymt;
      }
      i = X->size[0];
      for (ii = 0; ii < i; ii++) {
        if (ii + 1 > indsToExclude_size) {
          emlrtDynamicBoundsCheckR2012b(ii + 1, 1, indsToExclude_size,
                                        &rg_emlrtBCI, &c_st);
        }
        if (!indsToExclude_data[ii]) {
          real_T theta;
          int32_T b_theta;
          if (ii + 1 > X->size[0]) {
            emlrtDynamicBoundsCheckR2012b(ii + 1, 1, X->size[0], &pg_emlrtBCI,
                                          &c_st);
          }
          for (jj = 0; jj < 60; jj++) {
            this->Impl.Mt[jj] = muDoubleScalarMax(
                this->Impl.Mt[jj],
                muDoubleScalarAbs(X_data[ii + X->size[0] * jj]));
          }
          this->Impl.Mt[60] = muDoubleScalarMax(this->Impl.Mt[60], 1.0);
          for (jj = 0; jj < 60; jj++) {
            if ((this->Impl.Mt[jj] == 0.0) && (this->Impl.Gt[jj] == 0.0)) {
              this->Impl.Beta[jj] = 0.0;
            } else {
              d_st.site = &nh_emlrtRSI;
              denom =
                  this->Impl.S2t[jj] + this->Impl.Mt[jj] * this->Impl.Mt[jj];
              if (denom < 0.0) {
                emlrtErrorWithMessageIdR2018a(
                    &d_st, &s_emlrtRTEI, "Coder:toolbox:ElFunDomainError",
                    "Coder:toolbox:ElFunDomainError", 3, 4, 4, "sqrt");
              }
              denom = muDoubleScalarSqrt(denom);
              theta = this->Impl.Gt[jj] / denom;
              if (theta > 0.0) {
                b_theta = 1;
              } else {
                b_theta = -1;
              }
              this->Impl.Beta[jj] =
                  0.5 * (real_T)b_theta *
                  muDoubleScalarMin(muDoubleScalarAbs(theta), 1.0) *
                  this->Impl.Etat[jj] / denom;
            }
          }
          if ((this->Impl.Mt[60] == 0.0) && (this->Impl.Gt[60] == 0.0)) {
            bias = 0.0;
          } else {
            d_st.site = &mh_emlrtRSI;
            denom = this->Impl.S2t[60] + this->Impl.Mt[60] * this->Impl.Mt[60];
            if (denom < 0.0) {
              emlrtErrorWithMessageIdR2018a(
                  &d_st, &s_emlrtRTEI, "Coder:toolbox:ElFunDomainError",
                  "Coder:toolbox:ElFunDomainError", 3, 4, 4, "sqrt");
            }
            denom = muDoubleScalarSqrt(denom);
            theta = this->Impl.Gt[60] / denom;
            if (theta > 0.0) {
              b_theta = 1;
            } else {
              b_theta = -1;
            }
            bias = 0.5 * (real_T)b_theta *
                   muDoubleScalarMin(muDoubleScalarAbs(theta), 1.0) *
                   this->Impl.Etat[60] / denom;
          }
          denom = 0.0;
          for (jj = 0; jj < 60; jj++) {
            denom += X_data[ii + X->size[0] * jj] * this->Impl.Beta[jj];
          }
          denom += bias;
          if ((val_tmp_tmp > 0.0) && (val_tmp_tmp != 1.0)) {
            denom *= val_tmp_tmp;
          }
          if (ii + 1 > Y->size[0]) {
            emlrtDynamicBoundsCheckR2012b(ii + 1, 1, Y->size[0], &qg_emlrtBCI,
                                          &c_st);
          }
          theta = 0.0;
          jj = Y_data[ii];
          if (denom * (real_T)jj < 1.0) {
            theta = -(real_T)jj;
          }
          if ((val_tmp_tmp > 0.0) && (val_tmp_tmp != 1.0)) {
            theta /= val_tmp_tmp;
          }
          for (jj = 0; jj < 60; jj++) {
            denom = theta * X_data[ii + X->size[0] * jj];
            this->Impl.Gt[jj] -= denom * learnrate;
            this->Impl.S2t[jj] += denom * denom;
            this->Impl.Etat[jj] -= denom * this->Impl.Beta[jj];
          }
          this->Impl.Gt[60] -= theta * learnrate;
          this->Impl.S2t[60] += theta * theta;
          this->Impl.Etat[60] -= theta * bias;
        }
      }
      if ((this->Impl.Ymt != 0.0) && (this->Impl.Ymt != 1.0)) {
        for (i = 0; i < 60; i++) {
          this->Impl.Beta[i] *= this->Impl.Ymt;
        }
        bias *= this->Impl.Ymt;
      }
      this->Impl.Bias = bias;
    }
  }
}

/* End of code generation (Linear.c) */
