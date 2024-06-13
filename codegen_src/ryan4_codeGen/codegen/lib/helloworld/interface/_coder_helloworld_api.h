/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_helloworld_api.h
 *
 * Code generation for function 'helloworld'
 *
 */

#ifndef _CODER_HELLOWORLD_API_H
#define _CODER_HELLOWORLD_API_H

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
void helloworld(void);

void helloworld_api(void);

void helloworld_atexit(void);

void helloworld_initialize(void);

void helloworld_terminate(void);

void helloworld_xil_shutdown(void);

void helloworld_xil_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
/* End of code generation (_coder_helloworld_api.h) */
