/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * myPredictIncrLearn.c
 *
 * Code generation for function 'myPredictIncrLearn'
 *
 */

/* Include files */
#include "myPredictIncrLearn.h"
#include "Linear.h"
#include "myInitialModelIncrLearn_data.h"
#include "myInitialModelIncrLearn_initialize.h"
#include "myInitialModelIncrLearn_types.h"
#include "rt_nonfinite.h"
#include "rt_nonfinite.h"

/* Function Definitions */
void myPredictIncrLearn(const incrementalRegressionLinear incrementalModel,
                        const double X[100], double labels[5])
{
  int ii;
  bool indsToExclude[5];
  if (!isInitialized_myInitialModelIncrLearn) {
    myInitialModelIncrLearn_initialize();
  }
  /*  MYPREDICTINCRLEARN Predict labels and classification scores on new data */
  for (ii = 0; ii < 5; ii++) {
    int jj;
    bool exitg1;
    indsToExclude[ii] = false;
    jj = 0;
    exitg1 = false;
    while ((!exitg1) && (jj < 20)) {
      if (rtIsNaN(X[ii + 5 * jj])) {
        indsToExclude[ii] = true;
        exitg1 = true;
      } else {
        jj++;
      }
    }
  }
  Linear_score(incrementalModel.Impl.Beta, incrementalModel.Impl.Bias, X,
               indsToExclude, labels);
}

/* End of code generation (myPredictIncrLearn.c) */
