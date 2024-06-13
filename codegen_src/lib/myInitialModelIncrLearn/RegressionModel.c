/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * RegressionModel.c
 *
 * Code generation for function 'RegressionModel'
 *
 */

/* Include files */
#include "RegressionModel.h"
#include "rt_nonfinite.h"
#include "rt_nonfinite.h"

/* Function Definitions */
void RegressionModel_prepareData(const double X[100], const double Y[5],
                                 bool cleanWX, bool indsToExclude[5])
{
  int ii;
  int k;
  if (!cleanWX) {
    for (ii = 0; ii < 5; ii++) {
      indsToExclude[ii] = rtIsNaN(Y[ii]);
    }
  } else {
    for (ii = 0; ii < 5; ii++) {
      bool b[20];
      bool b_b;
      bool exitg1;
      for (k = 0; k < 20; k++) {
        b[k] = rtIsNaN(X[ii + 5 * k]);
      }
      b_b = false;
      k = 0;
      exitg1 = false;
      while ((!exitg1) && (k < 20)) {
        if (b[k]) {
          b_b = true;
          exitg1 = true;
        } else {
          k++;
        }
      }
      indsToExclude[ii] = (rtIsNaN(Y[ii]) || b_b);
    }
  }
}

/* End of code generation (RegressionModel.c) */
