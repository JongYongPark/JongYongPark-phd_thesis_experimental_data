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
  static const double dv[25] = {
      2.4772911544478711E-6,  4.7501947731101874E-6, 7.2400755821064637E-6,
      2.3363213007275362E-5,  4.638206549537087E-5,  2.8504664460836925E-5,
      4.2157597391630219E-5,  6.36030816237226E-5,   9.1766330183014314E-5,
      0.00012405521881833718, 2.1228716927411579E-5, 2.3393321194035549E-5,
      2.0517632979089791E-5,  8.3121805494062576E-6, 2.1013220041115961E-6,
      1.0111350402240825E-5,  9.8779719467432161E-6, 1.0140468915720685E-5,
      7.599307318697795E-6,   6.6309420490673864E-6, 1.2670216070993235E-6,
      2.3214858963882636E-6,  4.935112453363625E-6,  6.2099903605461546E-6,
      9.6998567487149342E-6};
  static const double dv1[20] = {
      -0.4282648499323396,  -0.24651655582719481,   -0.057056585497936289,
      0.03485509231606268,  0.15939623941136621,    0.3275092262946333,
      0.4909542059374139,   0.56177791211250816,    0.45379808893133089,
      0.24041170319838295,  0.049210520892019896,   -0.09253290428639048,
      -0.07726247665567626, -0.0036145835885560635, 0.13867364744867725,
      -0.0315833676986072,  1.0241899176290972,     0.26918068559932451,
      -0.49154717846131363, -0.47934658535461216};
  int i;
  if (!isInitialized_myInitialModelIncrLearn) {
    myInitialModelIncrLearn_initialize();
  }
  /*  MYINITIALMODELINCRLEARN Load and return configured linear model for */
  /*  binary classification InitialMdl */
  incrementalModel->NumTrainingObservations = 315U;
  incrementalModel->IsWarm = true;
  incrementalModel->BufferSize = 15U;
  for (i = 0; i < 25; i++) {
    incrementalModel->MetricBuffer[i] = dv[i];
    incrementalModel->WeightBuffer[i] = 1.0;
  }
  incrementalModel->NumMetricObservations = 265U;
  incrementalModel->Metrics.MeanSquaredError.Cumulative = 6.2365939214418766E-5;
  incrementalModel->Metrics.MeanSquaredError.Window = 2.2190683654057091E-5;
  incrementalModel->NumEstimationObservations = 0U;
  incrementalModel->parametersAdjusted = false;
  memcpy(&incrementalModel->Impl.Beta[0], &dv1[0], 20U * sizeof(double));
  incrementalModel->Impl.Bias = -1.0697799073333656;
  incrementalModel->Impl.BatchIndex = 63U;
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
