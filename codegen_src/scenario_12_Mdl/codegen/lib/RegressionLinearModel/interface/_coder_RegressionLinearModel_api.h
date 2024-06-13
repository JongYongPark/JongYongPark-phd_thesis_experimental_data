/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_RegressionLinearModel_api.h
 *
 * Code generation for function 'update'
 *
 */

#ifndef _CODER_REGRESSIONLINEARMODEL_API_H
#define _CODER_REGRESSIONLINEARMODEL_API_H

/* Include files */
#include "emlrt.h"
#include "tmwtypes.h"
#include <string.h>

/* Type Definitions */
#ifndef typedef_struct0_T
#define typedef_struct0_T
typedef struct {
  real_T Beta[20];
  real_T Bias;
} struct0_T;
#endif /* typedef_struct0_T */

/* Variable Declarations */
extern emlrtCTX emlrtRootTLSGlobal;
extern emlrtContext emlrtContextGlobal;

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
void RegressionLinearModel_atexit(void);

void RegressionLinearModel_initialize(void);

void RegressionLinearModel_terminate(void);

void RegressionLinearModel_xil_shutdown(void);

void RegressionLinearModel_xil_terminate(void);

real_T predict(real_T X[20]);

void predict_api(const mxArray *prhs, const mxArray **plhs);

void update(struct0_T *varargin_1);

void update_api(const mxArray *prhs);

#ifdef __cplusplus
}
#endif

#endif
/* End of code generation (_coder_RegressionLinearModel_api.h) */
