/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Gaussian.h
 *
 * Code generation for function 'Gaussian'
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
void Gaussian(const real_T svT[150], const real_T svInnerProduct[75],
              const real_T x[2], real_T kernelProduct[75]);

/* End of code generation (Gaussian.h) */
