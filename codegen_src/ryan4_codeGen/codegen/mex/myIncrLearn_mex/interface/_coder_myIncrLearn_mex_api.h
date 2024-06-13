/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * _coder_myIncrLearn_mex_api.h
 *
 * Code generation for function '_coder_myIncrLearn_mex_api'
 *
 */

#pragma once

/* Include files */
#include "myIncrLearn_mex_types.h"
#include "rtwtypes.h"
#include "emlrt.h"
#include "mex.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function Declarations */
void myFitIncrLearn_api(myIncrLearn_mexStackData *SD,
                        const mxArray *const prhs[3], const mxArray **plhs);

void myInitialModelIncrLearn_api(const mxArray **plhs);

void myPredictIncrLearn_api(myIncrLearn_mexStackData *SD,
                            const mxArray *const prhs[2], int32_T nlhs,
                            const mxArray *plhs[2]);

void myUpdateMetricsIncrLearn_api(myIncrLearn_mexStackData *SD,
                                  const mxArray *const prhs[3],
                                  const mxArray **plhs);

/* End of code generation (_coder_myIncrLearn_mex_api.h) */
