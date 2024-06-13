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
#include "LinearImpl.h"
#include "rt_nonfinite.h"

/* Function Definitions */
void Linear_score(const double this_Impl_Beta[20], double this_Impl_Bias,
                  const double X[100], const bool indsToExclude[5], double s[5])
{
  LinearImpl_score(this_Impl_Beta, this_Impl_Bias, X, indsToExclude, s);
}

/* End of code generation (Linear.c) */
