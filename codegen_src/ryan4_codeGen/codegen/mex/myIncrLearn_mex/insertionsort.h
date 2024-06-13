/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * insertionsort.h
 *
 * Code generation for function 'insertionsort'
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
void b_insertionsort(const emlrtStack *sp, int32_T x[2],
                     const cell_wrap_1 cmp_workspace_c[2]);

void insertionsort(const emlrtStack *sp, emxArray_int32_T *x, int32_T xstart,
                   int32_T xend, const emxArray_cell_wrap_1 *cmp_workspace_c);

/* End of code generation (insertionsort.h) */
