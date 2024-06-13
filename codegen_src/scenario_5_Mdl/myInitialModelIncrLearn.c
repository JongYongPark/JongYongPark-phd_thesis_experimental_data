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
      4.3055816999835481E-6, 3.2993629315966377E-6, 2.9136463650522936E-6,
      3.8663371106069126E-9, 2.1558058200280471E-6, 8.2332138270933512E-6,
      1.1712572168337082E-5, 1.943987921960933E-5,  1.4941389475582265E-5,
      1.1862060490470264E-5, 5.92269065602711E-6,   2.2119107493399908E-6,
      1.2426319212588317E-7, 1.3565546177206684E-5, 4.566460959809132E-5,
      8.0692899317277351E-5, 8.4428364254106924E-5, 7.9554110893675974E-5,
      4.6314121921325362E-5, 2.6531659206355952E-5, 6.8049742241146279E-6,
      4.9915407553643064E-6, 2.1660994289102088E-6, 2.6506893510179041E-6,
      1.3665399762401469E-6};
  static const double dv1[20] = {
      -0.42925905497244016,  -0.24645600946254217,   -0.055843262190169281,
      0.036620096815561581,  0.16191339889345868,    0.33104669179582835,
      0.49548118229562571,   0.56672049854911732,    0.45804807990023411,
      0.24331268195260408,   0.050886987667440389,   -0.091805863980190486,
      -0.076602514190333426, -0.0029617712122157543, 0.14011708581200494,
      -0.031471965503039205, 1.0317540490392554,     0.2708446134243121,
      -0.4945808715412251,   -0.48230493691384513};
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
  incrementalModel->Metrics.MeanSquaredError.Cumulative = 0.0001003728211042947;
  incrementalModel->Metrics.MeanSquaredError.Window = 7.1786767895439781E-6;
  incrementalModel->NumEstimationObservations = 0U;
  incrementalModel->parametersAdjusted = false;
  memcpy(&incrementalModel->Impl.Beta[0], &dv1[0], 20U * sizeof(double));
  incrementalModel->Impl.Bias = -1.0679965844508872;
  incrementalModel->Impl.BatchIndex = 62U;
  incrementalModel->Impl.Epsilon = -1.0;
  incrementalModel->Impl.LearnRate = 0.002;
  incrementalModel->Impl.Lambda = 0.001;
  incrementalModel->EpsilonMetricAdjusted = false;
  

  for (i = 0; i < 20; i++) {
	if(DEBUG_LOW && i==0) printf("\n incrementalModel->Impl.Beta[%d] = %.4f", i, incrementalModel->Impl.Beta[i]);  
  }  
  if(DEBUG_LOW) printf("\n Address of incrementalModel->Impl.Beta[0]: %p\n", &incrementalModel->Impl.Beta[0]);

  if(DEBUG_LOW) printf("\n<-- myInitialModelIncrLearn");
}


/* End of code generation (myInitialModelIncrLearn.c) */
