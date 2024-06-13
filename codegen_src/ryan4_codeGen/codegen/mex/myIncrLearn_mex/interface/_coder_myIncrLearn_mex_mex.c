/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_myIncrLearn_mex_mex.c
 *
 * Code generation for function '_coder_myIncrLearn_mex_mex'
 *
 */

/* Include files */
#include "_coder_myIncrLearn_mex_mex.h"
#include "_coder_myIncrLearn_mex_api.h"
#include "myIncrLearn_mex_data.h"
#include "myIncrLearn_mex_initialize.h"
#include "myIncrLearn_mex_terminate.h"
#include "myIncrLearn_mex_types.h"
#include "rt_nonfinite.h"

/* Function Definitions */
void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs,
                 const mxArray *prhs[])
{
  static const char_T *emlrtEntryPoints[4] = {
      "myInitialModelIncrLearn", "myUpdateMetricsIncrLearn", "myFitIncrLearn",
      "myPredictIncrLearn"};
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  myIncrLearn_mexStackData *myIncrLearn_mexStackDataGlobal = NULL;
  myIncrLearn_mexStackDataGlobal = (myIncrLearn_mexStackData *)emlrtMxCalloc(
      (size_t)1, (size_t)1U * sizeof(myIncrLearn_mexStackData));
  mexAtExit(&myIncrLearn_mex_atexit);
  /* Module initialization. */
  myIncrLearn_mex_initialize();
  st.tls = emlrtRootTLSGlobal;
  /* Dispatch the entry-point. */
  switch (emlrtGetEntryPointIndexR2016a(
      &st, nrhs, &prhs[0], (const char_T **)&emlrtEntryPoints[0], 4)) {
  case 0:
    myInitialModelIncrLearn_mexFunction(nlhs, plhs, nrhs - 1);
    break;
  case 1:
    myUpdateMetricsIncrLearn_mexFunction(myIncrLearn_mexStackDataGlobal, nlhs,
                                         plhs, nrhs - 1, &prhs[1]);
    break;
  case 2:
    myFitIncrLearn_mexFunction(myIncrLearn_mexStackDataGlobal, nlhs, plhs,
                               nrhs - 1, &prhs[1]);
    break;
  case 3:
    myPredictIncrLearn_mexFunction(myIncrLearn_mexStackDataGlobal, nlhs, plhs,
                                   nrhs - 1, &prhs[1]);
    break;
  }
  /* Module termination. */
  myIncrLearn_mex_terminate();
  emlrtMxFree(myIncrLearn_mexStackDataGlobal);
}

emlrtCTX mexFunctionCreateRootTLS(void)
{
  emlrtCreateRootTLSR2022a(&emlrtRootTLSGlobal, &emlrtContextGlobal, NULL, 1,
                           NULL, (const char_T *)"windows-1252", true);
  return emlrtRootTLSGlobal;
}

void myFitIncrLearn_mexFunction(myIncrLearn_mexStackData *SD, int32_T nlhs,
                                mxArray *plhs[1], int32_T nrhs,
                                const mxArray *prhs[3])
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  const mxArray *outputs;
  st.tls = emlrtRootTLSGlobal;
  /* Check for proper number of arguments. */
  if (nrhs != 3) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 3, 4,
                        14, "myFitIncrLearn");
  }
  if (nlhs > 1) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 14,
                        "myFitIncrLearn");
  }
  /* Call the function. */
  myFitIncrLearn_api(SD, prhs, &outputs);
  /* Copy over outputs to the caller. */
  emlrtReturnArrays(1, &plhs[0], &outputs);
}

void myInitialModelIncrLearn_mexFunction(int32_T nlhs, mxArray *plhs[1],
                                         int32_T nrhs)
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  const mxArray *outputs;
  st.tls = emlrtRootTLSGlobal;
  /* Check for proper number of arguments. */
  if (nrhs != 0) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 0, 4,
                        23, "myInitialModelIncrLearn");
  }
  if (nlhs > 1) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 23,
                        "myInitialModelIncrLearn");
  }
  /* Call the function. */
  myInitialModelIncrLearn_api(&outputs);
  /* Copy over outputs to the caller. */
  emlrtReturnArrays(1, &plhs[0], &outputs);
}

void myPredictIncrLearn_mexFunction(myIncrLearn_mexStackData *SD, int32_T nlhs,
                                    mxArray *plhs[2], int32_T nrhs,
                                    const mxArray *prhs[2])
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
  if (nrhs != 2) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 2, 4,
                        18, "myPredictIncrLearn");
  }
  if (nlhs > 2) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 18,
                        "myPredictIncrLearn");
  }
  /* Call the function. */
  myPredictIncrLearn_api(SD, prhs, nlhs, outputs);
  /* Copy over outputs to the caller. */
  if (nlhs < 1) {
    b_nlhs = 1;
  } else {
    b_nlhs = nlhs;
  }
  emlrtReturnArrays(b_nlhs, &plhs[0], &outputs[0]);
}

void myUpdateMetricsIncrLearn_mexFunction(myIncrLearn_mexStackData *SD,
                                          int32_T nlhs, mxArray *plhs[1],
                                          int32_T nrhs, const mxArray *prhs[3])
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  const mxArray *outputs;
  st.tls = emlrtRootTLSGlobal;
  /* Check for proper number of arguments. */
  if (nrhs != 3) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 3, 4,
                        24, "myUpdateMetricsIncrLearn");
  }
  if (nlhs > 1) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 24,
                        "myUpdateMetricsIncrLearn");
  }
  /* Call the function. */
  myUpdateMetricsIncrLearn_api(SD, prhs, &outputs);
  /* Copy over outputs to the caller. */
  emlrtReturnArrays(1, &plhs[0], &outputs);
}

/* End of code generation (_coder_myIncrLearn_mex_mex.c) */
