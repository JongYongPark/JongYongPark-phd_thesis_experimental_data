/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Poly.h
 *
 * Code generation for function 'Poly'
 *
 */

#pragma once

/* Include files */
#include "rtwtypes.h"
#include "emlrt.h"
#include "mex.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function Declarations */
void Poly(const emlrtStack *sp, const real_T svT[150], real_T order,
          const real_T x[200], real_T kernelProduct[7500]);

/* End of code generation (Poly.h) */
