/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * main.c
 *
 * Code generation for function 'main'
 *
 */

/*************************************************************************/
/* This automatically generated example C main file shows how to call    */
/* entry-point functions that MATLAB Coder generated. You must customize */
/* this file for your application. Do not modify this file directly.     */
/* Instead, make a copy of this file, modify it, and integrate it into   */
/* your development environment.                                         */
/*                                                                       */
/* This file initializes entry-point function arguments to a default     */
/* size and value before calling the entry-point functions. It does      */
/* not store or use any values returned from the entry-point functions.  */
/* If necessary, it does pre-allocate memory for returned values.        */
/* You can use this file as a starting point for a main function that    */
/* you can deploy in your application.                                   */
/*                                                                       */
/* After you copy the file, and before you deploy it, you must make the  */
/* following changes:                                                    */
/* * For variable-size function arguments, change the example sizes to   */
/* the sizes that your application requires.                             */
/* * Change the example values of function arguments to the values that  */
/* your application requires.                                            */
/* * If the entry-point functions return values, store these values or   */
/* otherwise use them as required by your application.                   */
/*                                                                       */
/*************************************************************************/

/* Include files */
#include "main.h"
#include "myFitIncrLearn.h"
#include "myInitialModelIncrLearn.h"
#include "myInitialModelIncrLearn_terminate.h"
#include "myInitialModelIncrLearn_types.h"
#include "myMAE.h"
#include "myMAPE.h"
#include "myMSE.h"
#include "myPredictIncrLearn.h"
#include "myRMSE.h"
#include "myUpdateMetricsAndFitIncrLearn.h"
#include "rt_nonfinite.h"

//#include "myPredictIncrLearn.h"
#include "Linear.h"
#include "myInitialModelIncrLearn_data.h"
#include "myInitialModelIncrLearn_initialize.h"
//#include "myInitialModelIncrLearn_types.h"
//#include "rt_nonfinite.h"
//#include "rt_nonfinite.h"

#include <string.h>
#include <stdio.h>
#include "debug.h"

#include "x_norm.h" 
#include "y_norm.h"
#include "y.h"

#define TEST_SINGLE   1
#define DEBUG_SINGLE  1 
#define DEBUG_PRED    1 

/* Function Declarations */
static void argInit_20x1_real_T(double result[20]);

static void argInit_25x1_real_T(double result[25]);

static void argInit_5x1_real_T(double result[5]);

static void argInit_5x20_real_T(double result[100]);

static bool argInit_boolean_T(void);

static double argInit_real_T(void);

static struct0_T argInit_struct0_T(void);

static struct1_T argInit_struct1_T(void);

static unsigned int argInit_uint32_T(void);

static void
c_argInit_incrementalRegression(incrementalRegressionLinear *result);

static void
c_argInit_incremental_coder_imp(incremental_coder_impl_SGDImpl *result);

static void c_main_myUpdateMetricsAndFitInc(void);

static void main_myFitIncrLearn(void);

static void main_myInitialModelIncrLearn(void);

static void main_myMAE(void);

static void main_myMAPE(void);

static void main_myMSE(void);

static void main_myPredictIncrLearn(void);

static void main_myRMSE(void);

/* Function Definitions */
static void argInit_20x1_real_T(double result[20])
{
  int idx0;
  /* Loop over the array to initialize each element. */
  for (idx0 = 0; idx0 < 20; idx0++) {
    /* Set the value of the array element.
Change this value to the value that the application requires. */
    result[idx0] = argInit_real_T();
  }
}

static void argInit_25x1_real_T(double result[25])
{
  int idx0;
  /* Loop over the array to initialize each element. */
  for (idx0 = 0; idx0 < 25; idx0++) {
    /* Set the value of the array element.
Change this value to the value that the application requires. */
    result[idx0] = argInit_real_T();
  }
}

static void argInit_5x1_real_T(double result[5])
{
  int idx0;
  /* Loop over the array to initialize each element. */
  for (idx0 = 0; idx0 < 5; idx0++) {
    /* Set the value of the array element.
Change this value to the value that the application requires. */
    result[idx0] = argInit_real_T();
  }
}

static void argInit_5x20_real_T(double result[100])
{
  int idx0;
  int idx1;
  /* Loop over the array to initialize each element. */
  for (idx0 = 0; idx0 < 5; idx0++) {
    for (idx1 = 0; idx1 < 20; idx1++) {
      /* Set the value of the array element.
Change this value to the value that the application requires. */
      result[idx0 + 5 * idx1] = argInit_real_T();
    }
  }
}

static bool argInit_boolean_T(void)
{
  return false;
}

static double argInit_real_T(void)
{
  return 0.0;
}

static struct0_T argInit_struct0_T(void)
{
  struct0_T result;
  /* Set the value of each structure field.
Change this value to the value that the application requires. */
  result.MeanSquaredError = argInit_struct1_T();
  return result;
}

static struct1_T argInit_struct1_T(void)
{
  struct1_T result;
  double result_tmp;
  /* Set the value of each structure field.
Change this value to the value that the application requires. */
  result_tmp = argInit_real_T();
  result.Window = result_tmp;
  result.Cumulative = result_tmp;
  return result;
}

static unsigned int argInit_uint32_T(void)
{
  return 0U;
}

static void c_argInit_incrementalRegression(incrementalRegressionLinear *result)
{
  if(DEBUG_LOW) printf("\n =>c_argInit_incrementalRegression");	
  unsigned int result_tmp;
  bool b_result_tmp;
  /* Set the value of each structure field.
Change this value to the value that the application requires. */
  argInit_25x1_real_T(result->MetricBuffer);
  result_tmp = argInit_uint32_T();
  result->BufferSize = result_tmp;
  result->NumMetricObservations = result_tmp;
  result->NumEstimationObservations = result_tmp;
  b_result_tmp = argInit_boolean_T();
  result->parametersAdjusted = b_result_tmp;
  result->EpsilonMetricAdjusted = b_result_tmp;
  result->NumTrainingObservations = result_tmp;
  result->IsWarm = b_result_tmp;
  result->Metrics = argInit_struct0_T();
  c_argInit_incremental_coder_imp(&result->Impl);
  memcpy(&result->WeightBuffer[0], &result->MetricBuffer[0],
         25U * sizeof(double));
 int i = 0;		 
 if(DEBUG_LOW) printf("\n Beta[%d] = %.10f", i, result->WeightBuffer[0]);		 
 if(DEBUG_LOW) printf("\n Address of result->WeightBuffer[0]: %p\n", &result->WeightBuffer[0]);		 
}

static void
c_argInit_incremental_coder_imp(incremental_coder_impl_SGDImpl *result)
{
  double result_tmp;
  /* Set the value of each structure field.
Change this value to the value that the application requires. */
  result_tmp = argInit_real_T();
  result->Epsilon = result_tmp;
  result->Bias = result_tmp;
  result->Lambda = result_tmp;
  result->LearnRate = result_tmp;
  argInit_20x1_real_T(result->Beta);
  result->BatchIndex = argInit_uint32_T();
}

static void c_main_myUpdateMetricsAndFitInc(void)
{
  incrementalRegressionLinear incrementalModel;
  double dv[100];
  double dv1[5];
  /* Initialize function 'myUpdateMetricsAndFitIncrLearn' input arguments. */
  /* Initialize function input argument 'incrementalModel'. */
  /* Initialize function input argument 'X'. */
  /* Initialize function input argument 'Y'. */
  /* Call the entry-point 'myUpdateMetricsAndFitIncrLearn'. */
  c_argInit_incrementalRegression(&incrementalModel);
  argInit_5x20_real_T(dv);
  argInit_5x1_real_T(dv1);
  myUpdateMetricsAndFitIncrLearn(&incrementalModel, dv, dv1);
}

static void main_myFitIncrLearn(void)
{
  incrementalRegressionLinear incrementalModel;
  double dv[100];
  double dv1[5];
  /* Initialize function 'myFitIncrLearn' input arguments. */
  /* Initialize function input argument 'incrementalModel'. */
  /* Initialize function input argument 'X'. */
  /* Initialize function input argument 'Y'. */
  /* Call the entry-point 'myFitIncrLearn'. */
  c_argInit_incrementalRegression(&incrementalModel);
  argInit_5x20_real_T(dv);
  argInit_5x1_real_T(dv1);
  myFitIncrLearn(&incrementalModel, dv, dv1);
}

static void main_myInitialModelIncrLearn(void)
{
  incrementalRegressionLinear incrementalModel;
  /* Call the entry-point 'myInitialModelIncrLearn'. */
  myInitialModelIncrLearn(&incrementalModel);
}

static void main_myMAE(void)
{
  double result[5];
  double z_tmp[5];
  /* Initialize function 'myMAE' input arguments. */
  /* Initialize function input argument 'z'. */
  argInit_5x1_real_T(z_tmp);
  /* Initialize function input argument 'zfit'. */
  /* Call the entry-point 'myMAE'. */
  myMAE(z_tmp, z_tmp, result);
}

static void main_myMAPE(void)
{
  double z_tmp[5];
  double result;
  /* Initialize function 'myMAPE' input arguments. */
  /* Initialize function input argument 'z'. */
  argInit_5x1_real_T(z_tmp);
  /* Initialize function input argument 'zfit'. */
  /* Call the entry-point 'myMAPE'. */
  result = myMAPE(z_tmp, z_tmp);
}

static void main_myMSE(void)
{
  double z_tmp[5];
  double result;
  /* Initialize function 'myMSE' input arguments. */
  /* Initialize function input argument 'z'. */
  argInit_5x1_real_T(z_tmp);
  /* Initialize function input argument 'zfit'. */
  /* Call the entry-point 'myMSE'. */
  result = myMSE(z_tmp, z_tmp);
}

static void main_myPredictIncrLearn(void)
{
  incrementalRegressionLinear r;
  double dv[100];
  double labels[5];
  /* Initialize function 'myPredictIncrLearn' input arguments. */
  /* Initialize function input argument 'incrementalModel'. */
  /* Initialize function input argument 'X'. */
  /* Call the entry-point 'myPredictIncrLearn'. */
  c_argInit_incrementalRegression(&r);
  argInit_5x20_real_T(dv);
  myPredictIncrLearn(r, dv, labels);
}

static void main_myRMSE(void)
{
  double z_tmp[5];
  double result;
  /* Initialize function 'myRMSE' input arguments. */
  /* Initialize function input argument 'z'. */
  argInit_5x1_real_T(z_tmp);
  /* Initialize function input argument 'zfit'. */
  /* Call the entry-point 'myRMSE'. */
  result = myRMSE(z_tmp, z_tmp);
}



/* Function Definitions */
void helloworld(void)
{
  printf("hello world!\n");
  fflush(stdout);
  printf("I am running on Raspberry Pi !!!!\n\n");
  fflush(stdout);
}


/* Include files */
#include "LinearImpl.h"
//#include "rt_nonfinite.h"

double predict_return[5];
/* Function Definitions */
double * myLinear_score(const double this_Beta[20], double this_Bias,
                      const double X[100], const bool indsToExclude[5]
                      )
{
 // ryan  - beta is changed ***************	
 if(DEBUG_LOW) printf("\n =>myLinear_score");	
 if(DEBUG_LOW) printf("\n Beta[%d] = %.10f", 0, this_Beta[0]);		 
 if(DEBUG_LOW) printf("\n Address of this_Beta[0]: %p\n", &this_Beta[0]);	
 
  int i;
  int ii;
  
  for (ii = 0; ii < 5; ii++) {
    predict_return[ii] = rtNaN;
    if (!indsToExclude[ii]) {
      double b_X;
      b_X = 0.0;
      for (i = 0; i < 20; i++) {
        b_X += X[ii + 5 * i] * this_Beta[i];
      }
      predict_return[ii] = b_X + this_Bias;
    }
  }
  return &(predict_return[0]);
}




int main(int argc, char **argv)
{
  (void)argc;
  (void)argv;
  helloworld();


  /* The initialize function is being called automatically from your entry-point
   * function. So, a call to initialize is not included here. */
  /* Invoke the entry-point functions.
You can call entry-point functions multiple times. */
  // call inc model

  main_myInitialModelIncrLearn();
  
//  incrementalRegressionLinear incrementalModel;
//  /* Call the entry-point 'myInitialModelIncrLearn'. */
//  myInitialModelIncrLearn(&incrementalModel);
  
  
  //return 0;

//  main_myMAE();
//  main_myRMSE();
//  main_myMAPE();
//  main_myMSE();


////////////////////////////
// prepare data
  double dv[100];
  double dv1[5];
  double dv2[5];
  
  
  double x_in[20] ;
  double y_out,Y_out;
  
  double y_hat[315];
  double y_real[315];
  double y_square_error[315];
  double y_absolute_error[315];
  double y_absolute_percentage_error[315];
  double y_rmse;
  double y_mape;
  
  int idx,i,j,k;
  
//main_myInitialModelIncrLearn();

  incrementalRegressionLinear incrementalModel;
  /* Call the entry-point 'myInitialModelIncrLearn'. */
  myInitialModelIncrLearn(&incrementalModel);
	  
 
#if TEST_SINGLE

  //#define DEBUG_SINGLE  1
  for(idx = 0; idx < 1 ; idx++)

#else

  for(idx = 0; idx < data_size ; idx++)

#endif 	
  {
  //return 0;
  
	  //return 0;

	  if(DEBUG_SINGLE) printf("\n\nx_norm data \n----------------\n");
	  
	  //return 0;
	  
	  k=0;
	  //for( i = 0 ; i < 5 ; i++)
	  {
		for( j = 0 ; j < 20 ; j++ )
		{
			dv[k] = x_norm[idx][j];
			
			if(DEBUG_SINGLE) printf("%d %d %.10f\n", idx, j ,dv[k]);
			k++;
		}
		if(DEBUG_SINGLE) printf("\n");
	  }

	  
	  
	  ///////////////////

	  j=0,k=0;
	  if(DEBUG_SINGLE) printf("\n\ny_norm data \n----------------\n");
	  //for( i = 0 ; i < 5 ; i++)
	  {
		dv1[0] = y_norm[idx][0];
		if(DEBUG_SINGLE) printf("%.10f \n",dv1[idx]);
	  }

	  
	  ///////////////////
	  //i=0;
	  j=0,k=0;
	  if(DEBUG_SINGLE) printf("\n\ny data \n----------------\n");
	  //for( i = 0 ; i < 5 ; i++)
	  {
		dv2[0] = y[idx][0];
		if(DEBUG_SINGLE) printf("%.10f \n",dv2[idx]);
	  }
	  
		//i=0;
		//k=0;
		for( j = 0 ; j < 20 ; j++ )
		{
			x_in[j] = x_norm[0][j];
			if(j==0) if(DEBUG_SINGLE) printf("\n x_in[%d] = %.10f ", j, x_in[j]);    
			
		}

	////////////////////////	
		
	  /* The initialize function is being called automatically from your entry-point
	   * function. So, a call to initialize is not included here. */
	  /* Invoke the entry-point functions.
	You can call entry-point functions multiple times. */
	  //RegressionLinearModel_initialize();
	  //main_update();
	  //main_predict();
	  //y_out = main_predict(x_in)
	  
	  // ryan --- DO NOT USE argInit_20x1_real_T
	  //argInit_20x1_real_T(x_in);

	  if(DEBUG_SINGLE) printf("\n check input param for Predict");
		//i=0;
		k=0;
		for( j = 0 ; j < 20 ; j++ )
		{
			x_in[j] = x_norm[idx][j];
			if(j==0) if(DEBUG_SINGLE) printf("\n x_in[%d] = %.10f ", j, x_in[j]);    
			
		}
		
	if(DEBUG_SINGLE) printf("\n *** incrementalModel.Impl.Beta[0] = %.10f ", incrementalModel.Impl.Beta[0]);  
	
  //return 0;
	////////////////////////////////////////////
	//  c_main_myUpdateMetricsAndFitInc();
	 
	//incrementalRegressionLinear incrementalModel;
	  

	  
	  /* Initialize function 'myUpdateMetricsAndFitIncrLearn' input arguments. */
	  /* Initialize function input argument 'incrementalModel'. */
	  /* Initialize function input argument 'X'. */
	  /* Initialize function input argument 'Y'. */
	  /* Call the entry-point 'myUpdateMetricsAndFitIncrLearn'. */
	  //c_argInit_incrementalRegression(&incrementalModel);
	  //argInit_5x20_real_T(dv);
	  //argInit_5x1_real_T(dv1);
	  
	  if(idx < 50 ) incrementalModel.IsWarm = true;
	  
	  myUpdateMetricsAndFitIncrLearn(&incrementalModel, dv, dv1);
	/////////////////////////////////

	  // return 0;

	#if 0
//	///////////////////////////////
//	//  main_myFitIncrLearn();
//	//{
//	  incrementalRegressionLinear incrementalModel;
//	  double dv[100];
//	  double dv1[5];
//	  /* Initialize function 'myFitIncrLearn' input arguments. */
//	  /* Initialize function input argument 'incrementalModel'. */
//	  /* Initialize function input argument 'X'. */
//	  /* Initialize function input argument 'Y'. */
//	  /* Call the entry-point 'myFitIncrLearn'. */
//	  c_argInit_incrementalRegression(&incrementalModel);
//	  //argInit_5x20_real_T(dv);
//	  //argInit_5x1_real_T(dv1);
//	  myFitIncrLearn(&incrementalModel, dv, dv1);
//	//}
//	////////////////////////////////////
	#endif   
	  
	///////////////////////////////////////////////  
	///  myPredictIncrLearn(r, dv, labels);
	//  incrementalRegressionLinear r;
	//  double dv[100];
	  double labels[5];
	  /* Initialize function 'myPredictIncrLearn' input arguments. */
	  /* Initialize function input argument 'incrementalModel'. */
	  /* Initialize function input argument 'X'. */
	  /* Call the entry-point 'myPredictIncrLearn'. */
	  //c_argInit_incrementalRegression(&incrementalModel);
	  //argInit_5x20_real_T(dv);
	  //myPredictIncrLearn(incrementalModel, dv, labels);
	 
	 
	 ////////////////////////////
	//void myPredictIncrLearn(const incrementalRegressionLinear incrementalModel,
	//                        const double X[100], double labels[5])
	//{
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
		  if (rtIsNaN(dv[ii + 5 * jj])) {
			indsToExclude[ii] = true;
			exitg1 = true;
		  } else {
			jj++;
		  }
		}
	  }
	  
	  //myLinear_score(incrementalModel.Impl.Beta, incrementalModel.Impl.Bias, dv,
	  //             indsToExclude, labels);
		double *predict_val ;
		double *score ;
		if(DEBUG_SINGLE) printf("\n incrementalModel.Impl.Beta[0] = %.10f ", incrementalModel.Impl.Beta[0]);    
		score = myLinear_score(incrementalModel.Impl.Beta, incrementalModel.Impl.Bias, dv,indsToExclude );
						  
	// }
	////////////////////////
	 
	//  main_myPredictIncrLearn();
	  //incrementalRegressionLinear r;
	  //double dv[100];
	  //double labels[5];
	  /* Initialize function 'myPredictIncrLearn' input arguments. */
	  /* Initialize function input argument 'incrementalModel'. */
	  /* Initialize function input argument 'X'. */
	  /* Call the entry-point 'myPredictIncrLearn'. */
	  //c_argInit_incrementalRegression(&IncremetalModel);
	 // argInit_5x20_real_T(dv);
	  myPredictIncrLearn(incrementalModel, dv, labels);
	  predict_val = &labels[0];
	//////////////////////////////////////
	  i=0,j=0,k=0;
	  printf("Predict Y data %n");
	  for( i = 0 ; i < 5 ; i++)
	  {
		printf("%.10f \n", predict_val[i]);
	  }
	  fflush(stdout);
  }

  /* Terminate the application.
You do not need to do this more than one time. */
  myInitialModelIncrLearn_terminate();


  return 0;
}

/* End of code generation (main.c) */
