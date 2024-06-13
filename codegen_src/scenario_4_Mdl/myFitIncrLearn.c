/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * myFitIncrLearn.c
 *
 * Code generation for function 'myFitIncrLearn'
 *
 */

/* Include files */
#include "myFitIncrLearn.h"
#include "Learner.h"
#include "myInitialModelIncrLearn_data.h"
#include "myInitialModelIncrLearn_initialize.h"
#include "myInitialModelIncrLearn_types.h"
#include "rt_nonfinite.h"

#include <stdio.h>
#include "debug.h"

/* Function Definitions */
void myFitIncrLearn(incrementalRegressionLinear *incrementalModel,
                    const double X[100], const double Y[5])
{

  if(DEBUG_LOW) printf("\n==> myFitIncrLearn ");  

  if (!isInitialized_myInitialModelIncrLearn) {
    myInitialModelIncrLearn_initialize();
  }
  /*  MYFITINCRLEARN Fit model to new data */
  Learner_fitWithoutValidation(incrementalModel, X, Y);

  if(DEBUG_LOW) printf("\n<-- myFitIncrLearn ");	
}

/* End of code generation (myFitIncrLearn.c) */
