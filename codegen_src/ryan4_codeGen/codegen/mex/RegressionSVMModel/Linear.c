/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Linear.c
 *
 * Code generation for function 'Linear'
 *
 */

/* Include files */
#include "Linear.h"
#include "mtimes.h"
#include "rt_nonfinite.h"

/* Function Definitions */
void Linear(const real_T svT[150], const real_T x[200],
            real_T kernelProduct[7500])
{
  mtimes(x, svT, kernelProduct);
}

/* End of code generation (Linear.c) */
