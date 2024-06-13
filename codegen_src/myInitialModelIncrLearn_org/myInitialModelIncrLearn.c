/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * myInitialModelIncrLearn.c
 *
 * Code generation for function 'myInitialModelIncrLearn'
 *
 */

/* Include files */
#include "myInitialModelIncrLearn.h"
#include "myInitialModelIncrLearn_data.h"
#include "myInitialModelIncrLearn_initialize.h"
#include "myInitialModelIncrLearn_types.h"
#include "rt_nonfinite.h"
#include <string.h>

#include <stdio.h>
#include "debug.h"

/* ryan from matlab 

function incrementalModel = myInitialModelIncrLearn() %#codegen
% MYINITIALMODELINCRLEARN Load and return configured linear model for
% binary classification InitialMdl
    incrementalModel = loadLearnerForCoder('InitialMdl');
end


*/

/* Function Definitions */
void myInitialModelIncrLearn(incrementalRegressionLinear *incrementalModel)
{
	
  if(DEBUG_LOW) printf("\n==> myInitialModelIncrLearn");		
	
  static const double dv[20] = {
      -0.42997605270260425,  -0.24711799399727324,  -0.056473321691659355,
      0.036007825676545452,  0.16132292316435351,   0.33048390301438635,
      0.49494610696888586,   0.5662022852461851,    0.45752539693099548,
      0.24277411624058964,   0.050338334120058739,  -0.092353033610206081,
      -0.077117324376923049, -0.003411004998634224, 0.13978506015100217,
      -0.031703433428532837, 1.0318332478129191,    0.27087748723516464,
      -0.49464291416451917,  -0.48236545732124547};
	  
    int i;
	  
  if (!isInitialized_myInitialModelIncrLearn) {
    myInitialModelIncrLearn_initialize();
  }
  /*  MYINITIALMODELINCRLEARN Load and return configured linear model for */
  /*  binary classification InitialMdl */
  incrementalModel->NumTrainingObservations = 0U;
  incrementalModel->IsWarm = false;
  incrementalModel->BufferSize = 0U;
  memset(&incrementalModel->MetricBuffer[0], 0, 25U * sizeof(double));
  memset(&incrementalModel->WeightBuffer[0], 0, 25U * sizeof(double));
  incrementalModel->NumMetricObservations = 0U;
  incrementalModel->Metrics.MeanSquaredError.Cumulative = -1.0;
  incrementalModel->Metrics.MeanSquaredError.Window = -1.0;
  incrementalModel->NumEstimationObservations = 0U;
  incrementalModel->parametersAdjusted = false;
  memcpy(&incrementalModel->Impl.Beta[0], &dv[0], 20U * sizeof(double));
  incrementalModel->Impl.Bias = -1.0687184316391805;
  incrementalModel->Impl.BatchIndex = 0U;
  incrementalModel->Impl.Epsilon = -1.0;
  incrementalModel->Impl.LearnRate = 0.1;
  incrementalModel->Impl.Lambda = 0.001;
  incrementalModel->EpsilonMetricAdjusted = false;
  

  for (i = 0; i < 20; i++) {
	if(DEBUG_LOW && i==0) printf("\n incrementalModel->Impl.Beta[%d] = %.4f", i, incrementalModel->Impl.Beta[i]);  
  }  
  if(DEBUG_LOW) printf("\n Address of incrementalModel->Impl.Beta[0]: %p\n", &incrementalModel->Impl.Beta[0]);

  if(DEBUG_LOW) printf("\n<-- myInitialModelIncrLearn");
}

/* End of code generation (myInitialModelIncrLearn.c) */
