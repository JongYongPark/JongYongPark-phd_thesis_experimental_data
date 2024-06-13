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
      3.3409474063163904E-6, 5.0917385629794333E-6, 6.57315940825909E-6,
      2.0402002594999169E-5, 3.8503848650891857E-5, 3.8811478355991331E-5,
      5.0114103597381828E-5, 6.9041790513901645E-5, 7.819258472424183E-5,
      8.8616836069942546E-5, 3.2515032384913215E-5, 2.8590789529395142E-5,
      1.8374601668871786E-5, 3.3070926323979912E-6, 1.7266386338975125E-7,
      1.3485788780941893E-5, 1.412475339014344E-5,  1.3348202328870758E-5,
      5.7964972135750628E-6, 2.2911585034989233E-6, 2.5216153081547425E-6,
      3.8682689406008338E-6, 7.2200616391594192E-6, 7.5089517233116936E-6,
      1.0711463249604361E-5};
  static const double dv1[20] = {
      -0.4278998330521297,   -0.24615167890204753,   -0.056677181393774534,
      0.035240270435936673,  0.15979041758199486,    0.32791626399886575,
      0.49137327918840112,   0.56219936906507273,    0.45420381702264079,
      0.2407906374887423,    0.049563616269836817,   -0.092202738413109137,
      -0.076943418866970217, -0.0033153262376325677, 0.13895334062654219,
      -0.03135242978949293,  1.024500909972063,      0.26920746872313406,
      -0.49159636452202587,  -0.47939455887377125};
  int i;
  if (!isInitialized_myInitialModelIncrLearn) {
    myInitialModelIncrLearn_initialize();
  }
  /*  MYINITIALMODELINCRLEARN Load and return configured linear model for */
  /*  binary classification InitialMdl */
  incrementalModel->NumTrainingObservations = 310U;
  incrementalModel->IsWarm = true;
  incrementalModel->BufferSize = 10U;
  for (i = 0; i < 25; i++) {
    incrementalModel->MetricBuffer[i] = dv[i];
    incrementalModel->WeightBuffer[i] = 1.0;
  }
  incrementalModel->NumMetricObservations = 260U;
  incrementalModel->Metrics.MeanSquaredError.Cumulative = 5.9800714449819493E-5;
  incrementalModel->Metrics.MeanSquaredError.Window = 2.1627878865567044E-5;
  incrementalModel->NumEstimationObservations = 0U;
  incrementalModel->parametersAdjusted = false;
  memcpy(&incrementalModel->Impl.Beta[0], &dv1[0], 20U * sizeof(double));
  incrementalModel->Impl.Bias = -1.0693310396205389;
  incrementalModel->Impl.BatchIndex = 62U;
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
