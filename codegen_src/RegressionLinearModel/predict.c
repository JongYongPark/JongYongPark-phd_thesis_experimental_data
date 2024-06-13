/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * predict.c
 *
 * Code generation for function 'predict'
 *
 */

/* Include files */
#include "predict.h"
#include "RegressionLinearModel_data.h"
#include "RegressionLinearModel_initialize.h"
#include "RegressionLinearModel_types.h"
#include "rt_nonfinite.h"
#include "rt_nonfinite.h"
#include <math.h>

#include <stdio.h>
#include "debug.h"

/* Function Definitions */
double predict(const double X[20])
{
  if(DEBUG_LOW) printf("\n==> predict");	
  
  double b_X;
  double varargout_1;
  int i;
    
  if(DEBUG_LOW) printf("\n check input");
  for(i=0;i<20;i++)	if(DEBUG_LOW && i==0) printf("\n X[%d] = %.10f ", i, X[i]);    
 
  
  if (!isInitialized_RegressionLinearModel) {
	  if(DEBUG_LOW) printf("\n isInitialized_RegressionLinearModel == false");
    RegressionLinearModel_initialize();
  }
  
  // ryan add - this line because model's data is reset anywhere 
  //RegressionLinearModel_initialize();

  for (i = 0; i < 20; i++) 	if(DEBUG_LOW && i == 0 ) printf("\n model.Beta[%d] = %.10f", i, model.Beta[i]);  
  if(DEBUG_LOW) printf("\n Address of model.Beta[0]: %p\n", &model.Beta[0]);

  
  /*  Autogenerated by MATLAB, 05-Jun-2022 21:39:25 */
  /*  Predict Inputs: X */
  b_X = 0.0;
  for (i = 0; i < 20; i++) {

    //ryan add
	  if(DEBUG_LOW && i==0) printf("\n X[i] = %.10f model.Beta[%d] = %.10f", i, X[i], i, model.Beta[i]);  
	  
    b_X += X[i] * model.Beta[i];
  }
  varargout_1 = b_X + model.Bias;
  switch (model.ResponseTransform) {
  case Logit:
    varargout_1 = 1.0 / (exp(-varargout_1) + 1.0);
    break;
  case Doublelogit:
    varargout_1 = 1.0 / (exp(-2.0 * varargout_1) + 1.0);
    break;
  case Invlogit:
    if (varargout_1 == 0.0) {
      varargout_1 = rtMinusInf;
    } else if (varargout_1 == 1.0) {
      varargout_1 = rtInf;
    } else if (rtIsNaN(varargout_1)) {
      varargout_1 = rtNaN;
    } else {
      varargout_1 /= 1.0 - varargout_1;
      varargout_1 = log(varargout_1);
    }
    break;
  case Ismax:
    varargout_1 = 1.0;
    break;
  case Sign:
    if (varargout_1 < 0.0) {
      varargout_1 = -1.0;
    } else {
      varargout_1 = (varargout_1 > 0.0);
    }
    break;
  case Symmetric:
    varargout_1 = 2.0 * varargout_1 - 1.0;
    break;
  case Symmetricismax:
    varargout_1 = 1.0;
    break;
  case Symmetriclogit:
    varargout_1 = 2.0 * (1.0 / (exp(-varargout_1) + 1.0)) - 1.0;
    break;
  }
  
  if(DEBUG_LOW) printf("\n<-- predict");	
  
  return varargout_1;
}

/* End of code generation (predict.c) */
