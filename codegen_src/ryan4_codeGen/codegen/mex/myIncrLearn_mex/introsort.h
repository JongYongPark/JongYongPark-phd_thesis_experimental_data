/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * introsort.h
 *
 * Code generation for function 'introsort'
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
void b_introsort(const emlrtStack *sp, emxArray_int32_T *x, int32_T xend,
                 const emxArray_cell_wrap_1 *cmp_workspace_c);

void introsort(const emlrtStack *sp, const cell_wrap_1 cmp_workspace_c[2],
               int32_T x[2]);

/* End of code generation (introsort.h) */
