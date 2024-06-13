/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * RegressionSVMModel_initialize.c
 *
 * Code generation for function 'RegressionSVMModel_initialize'
 *
 */

/* Include files */
#include "RegressionSVMModel_initialize.h"
#include "RegressionSVMModel_data.h"
#include "_coder_RegressionSVMModel_mex.h"
#include "initialize.h"
#include "rt_nonfinite.h"

/* Function Declarations */
static void RegressionSVMModel_once(void);

/* Function Definitions */
static void RegressionSVMModel_once(void)
{
  mex_InitInfAndNan();
  initialize_init();
}

void RegressionSVMModel_initialize(void)
{
  static const volatile char_T *emlrtBreakCheckR2012bFlagVar = NULL;
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  mexFunctionCreateRootTLS();
  emlrtBreakCheckR2012bFlagVar = emlrtGetBreakCheckFlagAddressR2012b();
  st.tls = emlrtRootTLSGlobal;
  emlrtClearAllocCountR2012b(&st, false, 0U, NULL);
  emlrtEnterRtStackR2012b(&st);
  if (emlrtFirstTimeR2012b(emlrtRootTLSGlobal)) {
    RegressionSVMModel_once();
  }
}

/* End of code generation (RegressionSVMModel_initialize.c) */
