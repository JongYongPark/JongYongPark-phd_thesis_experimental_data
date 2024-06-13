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
#include "RegressionLinearModel_terminate.h"
#include "RegressionLinearModel_types.h"
#include "predict.h"
#include "rt_nonfinite.h"
#include "update.h"

///////// ryan add 
#include <stdio.h>
#include "x_norm.h" 
#include "y_norm.h"
#include "y.h"
#include "debug.h"
#include <math.h> // fabs 

#include "RegressionLinearModel_initialize.h"
#include "RegressionLinearModel_data.h"
#include "initialize.h"
//#include "rt_nonfinite.h"
////////// end


/* Function Declarations */
static void argInit_20x1_real_T(double result[20]);

static double argInit_real_T(void);

static void argInit_struct0_T(struct0_T *result);

static void main_predict(void);

static void main_update(void);

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

static double argInit_real_T(void)
{
  return 0.0;
}

static void argInit_struct0_T(struct0_T *result)
{
  /* Set the value of each structure field.
Change this value to the value that the application requires. */
  argInit_20x1_real_T(result->Beta);
  result->Bias = argInit_real_T();
}


static void main_predict(void)
{
  double dv[20];
  double varargout_1;
  /* Initialize function 'predict' input arguments. */
  /* Initialize function input argument 'X'. */
  /* Call the entry-point 'predict'. */
  argInit_20x1_real_T(dv);
  varargout_1 = predict(dv);
}


static void main_update(void)
{
  struct0_T r;
  /* Initialize function 'update' input arguments. */
  /* Initialize function input argument 'varargin_1'. */
  /* Call the entry-point 'update'. */
  argInit_struct0_T(&r);
  update(&r);
}

/* Function Definitions */
void helloworld(void)
{
  printf("hello world!\n");
  fflush(stdout);
  printf("I am running on Raspberry Pi !!!!\n\n");
  fflush(stdout);
}

double const xrate_Vd_RUL =    1.3307 ;
double const xmin_Vd_RUL =    1.9987 ;
double const yrate_RUL =        1170 ;
double const ymin_RUL =            1 ;
double const data_size =         315 ;

double denormal_x(double x)
{
	return (x * xrate_Vd_RUL) + xmin_Vd_RUL;
}

double denormal_y(double y)
{
	return (y * yrate_RUL) + ymin_RUL;
}

#define TEST_SINGLE   0
#define DEBUG_SINGLE  0 
#define DEBUG_PRED    1 

int main(int argc, char **argv)
{
  (void)argc;
  (void)argv;
  
 ///////////////////// 
  helloworld();
  
////////////////////////////
// prepare data
  double dv[100];
  double dv1[5];
  double dv2[5];
  
  
  int i = 0;
  int j = 0;
  int k = 0;
  
  ////////////////
  double x_in[20] ;
  double y_out,Y_out;
  
  double y_hat[315];
  double y_real[315];
  double y_square_error[315];
  double y_absolute_error[315];
  double y_absolute_percentage_error[315];
  double y_rmse;
  double y_mape;
  
  int idx;
  
 
#if TEST_SINGLE

  //#define DEBUG_SINGLE  1
  for(idx = 0; idx < 1 ; idx++)

#else

  for(idx = 0; idx < data_size ; idx++)

#endif 	
  {
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
			if(DEBUG_SINGLE) printf("\n x_in[%d] = %.10f ", j, x_in[j]);    
			
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
			if(DEBUG_SINGLE) printf("\n x_in[%d] = %.10f ", j, x_in[j]);    
			
		}
	  
	  y_out = predict(x_in);
	  Y_out = denormal_y(y_out);
	  
	  y_hat[idx] = Y_out;
	  y_real[idx] = y[idx][0];
	  y_absolute_error[idx] = fabs( y_real[idx] - y_hat[idx] );
	  y_square_error[idx] = pow(y_absolute_error[idx] , 2 ); 
	  y_absolute_percentage_error[idx] = y_absolute_error[idx] / y_real[idx];

	  if(DEBUG_PRED) printf("\n\n Predict    norm  = %.10f ",y_out);
	  if(DEBUG_PRED) printf("\n Observered norm  = %.10f ",y_norm[idx][0]);
	  if(DEBUG_PRED) printf("\n Predict          = %.10f ",Y_out);
	  if(DEBUG_PRED) printf("\n Observered       = %.10f ",y[idx][0]);
	  if(DEBUG_PRED) printf("\n RUL              = %.10f ",data_size + 1 - idx);
	  if(DEBUG_PRED) printf("\n AE               = %.10f ",y_absolute_error[idx]);
	  if(DEBUG_PRED) printf("\n APE              = %.10f ",y_absolute_percentage_error[idx]);
	  fflush(stdout);
	  

  }
  

  y_mape = 0;
  y_rmse = 0;
  for(i=0;i<315;i++)
  {
	y_mape +=  y_absolute_percentage_error[i];
	y_rmse +=  y_square_error[i];
  }	  
  
  y_mape = y_mape / 315 * 100;
  y_rmse = sqrt(y_rmse / 315);

  if(DEBUG_PRED) printf("\n RMSE  = %.10f ",y_rmse);
  if(DEBUG_PRED) printf("\n MAPE  = %.10f ",y_mape);
  
  printf("\n Congraturation, It works !!! \n"); 
  /* Terminate the application.
You do not need to do this more than one time. */
  RegressionLinearModel_terminate();
  return 0;
}

/* End of code generation (main.c) */
