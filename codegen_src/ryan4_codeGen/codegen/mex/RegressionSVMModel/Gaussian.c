/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Gaussian.c
 *
 * Code generation for function 'Gaussian'
 *
 */

/* Include files */
#include "Gaussian.h"
#include "rt_nonfinite.h"
#include "mwmathutil.h"

/* Function Definitions */
void Gaussian(const real_T svT[150], const real_T svInnerProduct[75],
              const real_T x[2], real_T kernelProduct[75])
{
  real_T b_x;
  real_T d;
  real_T d1;
  int32_T k;
  b_x = x[0] * x[0] + x[1] * x[1];
  d = x[0];
  d1 = x[1];
  for (k = 0; k < 75; k++) {
    int32_T i;
    i = k << 1;
    kernelProduct[k] = muDoubleScalarExp(
        -(((-2.0 * d * svT[i] + -2.0 * d1 * svT[i + 1]) + b_x) +
          svInnerProduct[k]));
  }
}

/* End of code generation (Gaussian.c) */
