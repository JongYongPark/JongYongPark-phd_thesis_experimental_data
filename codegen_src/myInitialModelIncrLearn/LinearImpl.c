/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * LinearImpl.c
 *
 * Code generation for function 'LinearImpl'
 *
 */

/* Include files */
#include "LinearImpl.h"
#include "rt_nonfinite.h"

/* Function Definitions */
void LinearImpl_score(const double this_Beta[20], double this_Bias,
                      const double X[100], const bool indsToExclude[5],
                      double s[5])
{
  int i;
  int ii;
  for (ii = 0; ii < 5; ii++) {
    s[ii] = rtNaN;
    if (!indsToExclude[ii]) {
      double b_X;
      b_X = 0.0;
      for (i = 0; i < 20; i++) {
        b_X += X[ii + 5 * i] * this_Beta[i];
      }
      s[ii] = b_X + this_Bias;
    }
  }
}

/* End of code generation (LinearImpl.c) */
