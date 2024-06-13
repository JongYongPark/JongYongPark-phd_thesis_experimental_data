/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * myMAE.c
 *
 * Code generation for function 'myMAE'
 *
 */

/* Include files */
#include "myMAE.h"
#include "myInitialModelIncrLearn_data.h"
#include "myInitialModelIncrLearn_initialize.h"
#include "rt_nonfinite.h"
#include <math.h>

/* Function Definitions */
void myMAE(const double z[5], const double zfit[5], double result[5])
{
  int k;
  if (!isInitialized_myInitialModelIncrLearn) {
    myInitialModelIncrLearn_initialize();
  }
  /*  MYINITIALMODELINCRLEARN Load and return configured linear model for */
  /*  binary classification InitialMdl */
  for (k = 0; k < 5; k++) {
    result[k] = fabs(z[k] - zfit[k]);
  }
}

/* End of code generation (myMAE.c) */
