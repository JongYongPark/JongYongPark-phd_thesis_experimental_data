/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_springMassTakeStep_api.h
 *
 * Code generation for function 'springMassTakeStep'
 *
 */

#ifndef _CODER_SPRINGMASSTAKESTEP_API_H
#define _CODER_SPRINGMASSTAKESTEP_API_H

/* Include files */
#include "emlrt.h"
#include "tmwtypes.h"
#include <string.h>

/* Variable Declarations */
extern emlrtCTX emlrtRootTLSGlobal;
extern emlrtContext emlrtContextGlobal;

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
void springMassTakeStep(real_T xi, real_T vi, real_T ti, real_T dt, real_T g,
                        real_T *xf, real_T *vf);

void springMassTakeStep_api(const mxArray *const prhs[5], int32_T nlhs,
                            const mxArray *plhs[2]);

void springMassTakeStep_atexit(void);

void springMassTakeStep_initialize(void);

void springMassTakeStep_terminate(void);

void springMassTakeStep_xil_shutdown(void);

void springMassTakeStep_xil_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
/* End of code generation (_coder_springMassTakeStep_api.h) */
