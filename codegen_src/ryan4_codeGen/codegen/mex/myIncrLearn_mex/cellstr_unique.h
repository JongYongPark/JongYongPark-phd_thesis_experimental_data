/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * cellstr_unique.h
 *
 * Code generation for function 'cellstr_unique'
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
void cellstr_unique(const emlrtStack *sp, const emxArray_cell_wrap_1 *a,
                    emxArray_cell_wrap_1 *u, emxArray_real_T *ia,
                    emxArray_real_T *ic);

/* End of code generation (cellstr_unique.h) */
