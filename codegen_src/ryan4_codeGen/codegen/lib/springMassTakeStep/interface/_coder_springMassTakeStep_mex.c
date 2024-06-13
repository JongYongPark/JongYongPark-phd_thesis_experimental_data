/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_springMassTakeStep_mex.c
 *
 * Code generation for function 'springMassTakeStep'
 *
 */

/* Include files */
#include "_coder_springMassTakeStep_mex.h"
#include "_coder_springMassTakeStep_api.h"

/* Function Definitions */
void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs,
                 const mxArray *prhs[])
{
  mexAtExit(&springMassTakeStep_atexit);
  /* Module initialization. */
  springMassTakeStep_initialize();
  /* Dispatch the entry-point. */
  unsafe_springMassTakeStep_mexFunction(nlhs, plhs, nrhs, prhs);
  /* Module termination. */
  springMassTakeStep_terminate();
}

emlrtCTX mexFunctionCreateRootTLS(void)
{
  emlrtCreateRootTLSR2022a(&emlrtRootTLSGlobal, &emlrtContextGlobal, NULL, 1,
                           NULL, (const char_T *)"windows-1252", true);
  return emlrtRootTLSGlobal;
}

void unsafe_springMassTakeStep_mexFunction(int32_T nlhs, mxArray *plhs[2],
                                           int32_T nrhs, const mxArray *prhs[5])
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  const mxArray *outputs[2];
  int32_T b_nlhs;
  st.tls = emlrtRootTLSGlobal;
  /* Check for proper number of arguments. */
  if (nrhs != 5) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 5, 4,
                        18, "springMassTakeStep");
  }
  if (nlhs > 2) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 18,
                        "springMassTakeStep");
  }
  /* Call the function. */
  springMassTakeStep_api(prhs, nlhs, outputs);
  /* Copy over outputs to the caller. */
  if (nlhs < 1) {
    b_nlhs = 1;
  } else {
    b_nlhs = nlhs;
  }
  emlrtReturnArrays(b_nlhs, &plhs[0], &outputs[0]);
}

/* End of code generation (_coder_springMassTakeStep_mex.c) */
