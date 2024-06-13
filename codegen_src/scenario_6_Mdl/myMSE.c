/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * myMSE.c
 *
 * Code generation for function 'myMSE'
 *
 */

/* Include files */
#include "myMSE.h"
#include "myInitialModelIncrLearn_data.h"
#include "myInitialModelIncrLearn_initialize.h"
#include "rt_nonfinite.h"

/* Function Definitions */
double myMSE(const double z[5], const double zfit[5])
{
  double y[5];
  int k;
  if (!isInitialized_myInitialModelIncrLearn) {
    myInitialModelIncrLearn_initialize();
  }
  /*  MYINITIALMODELINCRLEARN Load and return configured linear model for */
  /*  binary classification InitialMdl */
  for (k = 0; k < 5; k++) {
    double d;
    d = z[k] - zfit[k];
    y[k] = d * d;
  }
  return ((((y[0] + y[1]) + y[2]) + y[3]) + y[4]) / 5.0;
}

/* End of code generation (myMSE.c) */
