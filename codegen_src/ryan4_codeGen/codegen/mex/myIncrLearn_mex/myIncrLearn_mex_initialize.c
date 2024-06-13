/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * myIncrLearn_mex_initialize.c
 *
 * Code generation for function 'myIncrLearn_mex_initialize'
 *
 */

/* Include files */
#include "myIncrLearn_mex_initialize.h"
#include "_coder_myIncrLearn_mex_mex.h"
#include "myIncrLearn_mex_data.h"
#include "rt_nonfinite.h"

/* Function Definitions */
void myIncrLearn_mex_initialize(void)
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  mex_InitInfAndNan();
  mexFunctionCreateRootTLS();
  emlrtBreakCheckR2012bFlagVar = emlrtGetBreakCheckFlagAddressR2012b();
  st.tls = emlrtRootTLSGlobal;
  emlrtClearAllocCountR2012b(&st, false, 0U, NULL);
  emlrtEnterRtStackR2012b(&st);
  emlrtFirstTimeR2012b(emlrtRootTLSGlobal);
}

/* End of code generation (myIncrLearn_mex_initialize.c) */
