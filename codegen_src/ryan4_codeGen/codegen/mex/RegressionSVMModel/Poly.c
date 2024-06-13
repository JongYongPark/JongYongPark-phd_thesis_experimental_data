/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Poly.c
 *
 * Code generation for function 'Poly'
 *
 */

/* Include files */
#include "Poly.h"
#include "mtimes.h"
#include "rt_nonfinite.h"

/* Variable Definitions */
static emlrtRTEInfo c_emlrtRTEI = {
    12,     /* lineNo */
    9,      /* colNo */
    "Poly", /* fName */
    "C:\\Program "
    "Files\\MATLAB\\R2022a\\toolbox\\stats\\classreg\\+classreg\\+learning\\+"
    "coder\\+kernel\\Poly.m" /* pName */
};

/* Function Definitions */
void Poly(const emlrtStack *sp, const real_T svT[150], real_T order,
          const real_T x[200], real_T kernelProduct[7500])
{
  real_T temp[7500];
  int32_T b_i;
  int32_T i;
  int32_T i1;
  mtimes(x, svT, kernelProduct);
  for (i = 0; i < 7500; i++) {
    real_T d;
    d = kernelProduct[i] + 1.0;
    kernelProduct[i] = d;
    temp[i] = d;
  }
  i = (int32_T)(order - 1.0);
  emlrtForLoopVectorCheckR2021a(1.0, 1.0, order - 1.0, mxDOUBLE_CLASS,
                                (int32_T)(order - 1.0), &c_emlrtRTEI,
                                (emlrtCTX)sp);
  for (b_i = 0; b_i < i; b_i++) {
    for (i1 = 0; i1 < 7500; i1++) {
      kernelProduct[i1] *= temp[i1];
    }
  }
}

/* End of code generation (Poly.c) */
