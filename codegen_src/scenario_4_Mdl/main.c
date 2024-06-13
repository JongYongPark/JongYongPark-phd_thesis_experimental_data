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
///////// ryan add 
#include <stdlib.h>
#include <errno.h>
#include <limits.h>
#include <string.h>


#include <stdio.h>
#include "debug.h"
#define TEST_BAT_NUM_1          1  
#define TEST_BAT_NUM_2          0  

#define x_size                  20      
#define win_size                5

#if TEST_BAT_NUM_1
#include "../bat_header/x_norm_1.h" 
#include "../bat_header/y_norm_1.h"
#include "../bat_header/Y_1.h"
int             bat_num = 1;

#define MAX_BAT_SIZE            2000 

//#define MAX_BAT_SIZE            315 
#endif

#if TEST_BAT_NUM_2
#include "../bat_header/x_norm_2.h" 
#include "../bat_header/y_norm_2.h"
#include "../bat_header/Y_2.h"
int             bat_num = 2;

#define MAX_BAT_SIZE            1024 
#endif

#include <math.h> // fabs 
#include <stddef.h> // NULL 

//#define TEST_SINGLE             1
//#define DEBUG_SINGLE            1 
//#define DEBUG_PRED              1 

#define TEST_SINGLE             0
#define DEBUG_SINGLE            0 
#define DEBUG_PRED              1 


#define null                    0

double const    xrate_Vd_RUL = 1.3307;
double const    xmin_Vd_RUL = 1.9987;
double const    yrate_RUL = 1170;
double const    ymin_RUL = 1;


double          x_norm[MAX_BAT_SIZE][x_size];
double          y_norm[MAX_BAT_SIZE][1];
double          Y[MAX_BAT_SIZE][1];
double          Y_hat_all[MAX_BAT_SIZE];
double          Y_observed_all[MAX_BAT_SIZE];
double          Y_square_error_all[MAX_BAT_SIZE];
double          Y_absolute_error_all[MAX_BAT_SIZE];
double          Y_absolute_percentage_error_all[MAX_BAT_SIZE];

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

static void c_argInit_incrementalRegression(incrementalRegressionLinear * result);

static void c_argInit_incremental_coder_imp(incremental_coder_impl_SGDImpl * result);

//static void c_main_myUpdateMetricsAndFitInc(void);
static double * c_main_myUpdateMetricsAndFitInc(incrementalRegressionLinear *incrementalModel,double dv[100], double dv1[5] );

static void main_myFitIncrLearn(void);

static void main_myInitialModelIncrLearn(void);

static void main_myMAE(void);

static void main_myMAPE(void);

static void main_myMSE(void);

//static void main_myPredictIncrLearn(void);
//static double* main_myPredictIncrLearn(double          dv[100],double labels[5]);
static double* main_myPredictIncrLearn(incrementalRegressionLinear incrementalModel, double          dv[100],double labels[5]);


static void main_myRMSE(void);

/* Function Definitions */
static void argInit_20x1_real_T(double result[20])
{
  int             idx0;

  /* Loop over the array to initialize each element. */
  for (idx0 = 0; idx0 < 20; idx0++) {
    /* Set the value of the array element.
    Change this value to the value that the application requires. */
    result[idx0]        = argInit_real_T();
  }
}


static void argInit_25x1_real_T(double result[25])
{
  int             idx0;

  /* Loop over the array to initialize each element. */
  for (idx0 = 0; idx0 < 25; idx0++) {
    /* Set the value of the array element.
    Change this value to the value that the application requires. */
    result[idx0]        = argInit_real_T();
  }
}


static void argInit_5x1_real_T(double result[5])
{
  int             idx0;

  /* Loop over the array to initialize each element. */
  for (idx0 = 0; idx0 < 5; idx0++) {
    /* Set the value of the array element.
    Change this value to the value that the application requires. */
    result[idx0]        = argInit_real_T();
  }
}


static void argInit_5x20_real_T(double result[100])
{
  int             idx0;
  int             idx1;

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
  struct0_T       result;

  /* Set the value of each structure field.
  Change this value to the value that the application requires. */
  result.MeanSquaredError = argInit_struct1_T();
  return result;
}


static struct1_T argInit_struct1_T(void)
{
  struct1_T       result;
  double          result_tmp;

  /* Set the value of each structure field.
  Change this value to the value that the application requires. */
  result_tmp          = argInit_real_T();
  result.Window       = result_tmp;
  result.Cumulative   = result_tmp;
  return result;
}


static unsigned int argInit_uint32_T(void)
{
  return 0U;
}


static void c_argInit_incrementalRegression(incrementalRegressionLinear * result)
{
  if (DEBUG_LOW) printf("\n==> c_argInit_incrementalRegression");
  unsigned int    result_tmp;
  bool            b_result_tmp;

  /* Set the value of each structure field.
  Change this value to the value that the application requires. */
  argInit_25x1_real_T(result->MetricBuffer);
  result_tmp          = argInit_uint32_T();
  result->BufferSize  = result_tmp;
  result->NumMetricObservations = result_tmp;
  result->NumEstimationObservations = result_tmp;
  b_result_tmp        = argInit_boolean_T();
  result->parametersAdjusted = b_result_tmp;
  result->EpsilonMetricAdjusted = b_result_tmp;
  result->NumTrainingObservations = result_tmp;
  result->IsWarm      = b_result_tmp;
  result->Metrics     = argInit_struct0_T();
  c_argInit_incremental_coder_imp(&result->Impl);
  memcpy(&result->WeightBuffer[0], &result->MetricBuffer[0], 
    25U * sizeof(double));
  int             i   = 0;

  if (DEBUG_LOW) printf("\n result->WeightBuffer[%d] = %.4f", i, result->WeightBuffer[0]);
  if (DEBUG_LOW) printf("\n Address of result->WeightBuffer[0]: %p\n", &result->WeightBuffer[0]);
  if (DEBUG_LOW) printf("\n<-- c_argInit_incrementalRegression");
}


static void c_argInit_incremental_coder_imp(incremental_coder_impl_SGDImpl * result)
{
  double          result_tmp;

  /* Set the value of each structure field.
  Change this value to the value that the application requires. */
  result_tmp          = argInit_real_T();
  result->Epsilon     = result_tmp;
  result->Bias        = result_tmp;
  result->Lambda      = result_tmp;
  result->LearnRate   = result_tmp;
  argInit_20x1_real_T(result->Beta);
  result->BatchIndex  = argInit_uint32_T();
}


static double * c_main_myUpdateMetricsAndFitInc(incrementalRegressionLinear *incrementalModel,double dv[100], double dv1[5])
{
  if (DEBUG_LOW) printf("\n==> c_main_myUpdateMetricsAndFitInc");
  //incrementalRegressionLinear incrementalModel;

  //double          dv[100];
  //double          dv1[5];

  /* Initialize function 'myUpdateMetricsAndFitIncrLearn' input arguments. */
  /* Initialize function input argument 'incrementalModel'. */
  /* Initialize function input argument 'X'. */
  /* Initialize function input argument 'Y'. */
  /* Call the entry-point 'myUpdateMetricsAndFitIncrLearn'. */
  //c_argInit_incrementalRegression(&incrementalModel);
  //argInit_5x20_real_T(dv);
  //argInit_5x1_real_T(dv1);
  myUpdateMetricsAndFitIncrLearn(incrementalModel, dv, dv1);
  if (DEBUG_LOW) printf("\n<-- c_main_myUpdateMetricsAndFitInc");
  return & dv1[0];
}


static void main_myFitIncrLearn(void)
{
  incrementalRegressionLinear incrementalModel;
  double          dv[100];
  double          dv1[5];

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
  double          result[5];
  double          z_tmp[5];

  /* Initialize function 'myMAE' input arguments. */
  /* Initialize function input argument 'z'. */
  argInit_5x1_real_T(z_tmp);

  /* Initialize function input argument 'zfit'. */
  /* Call the entry-point 'myMAE'. */
  myMAE(z_tmp, z_tmp, result);
}


static void main_myMAPE(void)
{
  double          z_tmp[5];
  double          result;

  /* Initialize function 'myMAPE' input arguments. */
  /* Initialize function input argument 'z'. */
  argInit_5x1_real_T(z_tmp);

  /* Initialize function input argument 'zfit'. */
  /* Call the entry-point 'myMAPE'. */
  result              = myMAPE(z_tmp, z_tmp);
}


static void main_myMSE(void)
{
  double          z_tmp[5];
  double          result;

  /* Initialize function 'myMSE' input arguments. */
  /* Initialize function input argument 'z'. */
  argInit_5x1_real_T(z_tmp);

  /* Initialize function input argument 'zfit'. */
  /* Call the entry-point 'myMSE'. */
  result              = myMSE(z_tmp, z_tmp);
}


static double* main_myPredictIncrLearn(incrementalRegressionLinear incrementalModel, double          dv[100],double labels[5])
{
  if (DEBUG_LOW) printf("\n==> main_myPredictIncrLearn");
  
  //incrementalRegressionLinear r;
  //double          dv[100];
  //double          labels[5];

  /* Initialize function 'myPredictIncrLearn' input arguments. */
  /* Initialize function input argument 'incrementalModel'. */
  /* Initialize function input argument 'X'. */
  /* Call the entry-point 'myPredictIncrLearn'. */

  //c_argInit_incrementalRegression(&r);
  //argInit_5x20_real_T(dv);

  //if (DEBUG_LOW) printf("\n r.WeightBuffer[0] = %.4f ", r.WeightBuffer[0] );
  if (DEBUG_LOW) printf("\n incrementalModel.WeightBuffer[0] = %.4f ",incrementalModel.WeightBuffer[0] );


  //myPredictIncrLearn(r, dv, labels);
  myPredictIncrLearn(incrementalModel, dv, labels);

  //if (DEBUG_LOW) printf("\n r.WeightBuffer[0] = %.4f ", r.WeightBuffer[0] );
  if (DEBUG_LOW) printf("\n incrementalModel.WeightBuffer[0] = %.4f ",incrementalModel.WeightBuffer[0] );
  if (DEBUG_LOW) printf("\n<-- main_myPredictIncrLearn");
  
  return &labels[0];
}


static void main_myRMSE(void)
{
  double          z_tmp[5];
  double          result;

  /* Initialize function 'myRMSE' input arguments. */
  /* Initialize function input argument 'z'. */
  argInit_5x1_real_T(z_tmp);

  /* Initialize function input argument 'zfit'. */
  /* Call the entry-point 'myRMSE'. */
  result              = myRMSE(z_tmp, z_tmp);
}




/* Function Definitions */
void helloworld(void)
{
  printf("hello world!\n");
  fflush(stdout);
  printf("I am running on Raspberry Pi !!!!\n\n");
  fflush(stdout);
}


double denormal_x(double x)
{
  return (x * xrate_Vd_RUL) +xmin_Vd_RUL;
}


double denormal_y(double y)
{
  return (y * yrate_RUL) +ymin_RUL;
}


double * denormal_y5(double y[win_size], double Y[win_size])
{
  int             i;

  //double Y[win_size];
  for (i = 0; i < win_size; i++) {
    Y[i]                = (y[i] *yrate_RUL) +ymin_RUL;
  }
  return & Y[0];
}


void denormal_y5_test()
{
  int             i;
  double          y_fit_win[win_size], Y_fit_win[win_size];
  double *        ret;

  printf("\n denormal_y5_test ");
  

  y_fit_win[0]        = 0.000;
  y_fit_win[1]        = 0.010;
  y_fit_win[2]        = 0.020;
  y_fit_win[3]        = 0.030;
  y_fit_win[4]        = 0.040;

  Y_fit_win[0]        = 0.000;
  Y_fit_win[1]        = 0.000;
  Y_fit_win[2]        = 0.000;
  Y_fit_win[3]        = 0.000;
  Y_fit_win[4]        = 0.000;


  ret                 = denormal_y5(y_fit_win, Y_fit_win);

  printf("\n y_fit_win = %.4f %.4f %.4f %.4f %.4f ", y_fit_win[0], y_fit_win[1], y_fit_win[2], y_fit_win[3],
     y_fit_win[4]);
  printf("\n Y_fit_win = %.4f %.4f %.4f %.4f %.4f ", Y_fit_win[0], Y_fit_win[1], Y_fit_win[2], Y_fit_win[3],
     Y_fit_win[4]);
  
  printf("\n ret = %.4f %.4f %.4f %.4f %.4f ", ret[0], ret[1], ret[2], ret[3], ret[4]);
  printf("\n ");
}


// https://stackoverflow.com/questions/8767166/passing-a-2d-array-to-a-c-function
void printDouble(double data, char * title)
{

  if (title != null) {
    printf("\n %s\n", title);
  }
  printf(" %.4f\n", data);
}


void printVector1D(double data[], int count, char * title)
{
  int             i;

  if (title != null) {
    printf("\n %s\n", title);
  }

  for (i = 0; i < count; i++) {
    printf(" %d %.4f\n", i, data[i]);
  }


}


void printVector2D20(double data[][20], int rowCount, char * title)
{
  int             i, j;

  if (title != null) {
    printf("\n %s\n", title);
  }


  for (i = 0; i < rowCount; i++) {
    for (j = 0; j < 20; j++) {
      printf(" %d %d %.4f\n", i, j, data[i][j]);
    }
  }
}


void printVector2D1(double data[][1], int rowCount, char * title)
{
  int             i;

  if (title != null) {
    printf("\n %s\n", title);
  }


  for (i = 0; i < rowCount; i++) {
    printf(" %d %.4f\n", i, data[i][0]);
  }
}


///////////
/// main 
////////////
int main(int argc, char * *argv)
{
  //  (void)
  //  argc;
  //  (void)
  //  argv;
  //  int counter;
  //  printf("Program Name Is: %s",argv[0]);
  //  if(argc==1)
  //      printf("\nNo Extra Command Line Argument Passed Other Than Program Name");
  //  if(argc>=2)
  //  {
  //      printf("\nNumber Of Arguments Passed: %d",argc);
  //      printf("\n----Following Are The Command Line Arguments Passed----");
  //      for(counter=0;counter<argc;counter++)
  //          printf("\nargv[%d]: %s",counter,argv[counter]);
  //  }
  //  printf("\n\n");
#define   USE_ARGV                0

#if USE_ARGV

  // https://stackoverflow.com/questions/9748393/how-can-i-get-argv-as-int
  char *          p;

  errno               = 0;                          // not 'int errno', because the '#include' already defined it
  long            arg = strtol(argv[1], &p, 10);

  if (*p != '\0' || errno != 0) {
    return 1; // In main(), returning non-zero means failure
  }

  if (arg < INT_MIN || arg > INT_MAX) {
    return 1;
  }
  int             arg_int = arg;

  // Everything went well, print it as a regular number plus a newline
  printf("Your value was: %d\n", arg_int);

  // ryan - do later to select battery using argv
#endif

  denormal_y5_test();
  //return 0;

  helloworld();
  double          dv[100];
  double          dv1[5];
  double          dv2[5];
  int             i   = 0;
  int             j   = 0;
  int             k   = 0;                          ////////////////

  int             idxCount;


  int             loop;
  double          x_in[x_size];
  double          y_fit, Y_fit, y_out, Y_out;
  double          Y_observed;

  double          x_in_win[x_size * win_size];
  double          y_fit_win[win_size], Y_fit_win[win_size], y_obsered_win[win_size];
  double          Y_observed_win[win_size];
  double          y_fit_win_before[win_size], Y_fit_win_before[win_size];

  double          Y_rmse;
  double          Y_mape;
  int             idx;


#if TEST_BAT_NUM_1
  idxCount            = sizeof(Y_1) / 8;
  printf("\n idxCount = %d ", idxCount);

  for (i = 0; i < idxCount; i++) {
    for (j = 0; j < 20; j++) {
      x_norm[i][j]        = x_norm_1[i][j];
    }
    y_norm[i][0]        = y_norm_1[i][0];
    Y[i][0]             = Y_1[i][0];
  }
#endif


#if TEST_BAT_NUM_2
  idxCount            = sizeof(Y_2) / 8;
  printf("\n idxCount = %d ", idxCount);

  for (i = 0; i < idxCount; i++) {
    for (j = 0; j < 20; j++) {
      x_norm[i][j]        = x_norm_2[i][j];
    }
    y_norm[i][0]        = y_norm_2[i][0];
    Y[i][0]             = Y_2[i][0];
  }
#endif


  //  size_t x_size  = sizeof(x_norm);
  //  size_t y_size  = sizeof(y_norm);
  //
  //   printf("\n x_size = %d ",x_size);
  //   printf("\n y_size = %d ",y_size);
  //  
  //  //     x_size = 50400
  //  //     y_size = 2520
  //////////////////////////////////////////////////
  //return 0;
#if 0  
  printVector2D20(x_norm, 1, "\n\n x_norm data \n----------------\n");
  printVector2D1(y_norm, 1, "\n\n y_norm data \n----------------\n");
  printVector2D1(Y, 1, "\n\n Y data \n----------------\n");
#endif 

  /* The initialize function is being called automatically from your entry-point
   * function. So, a call to initialize is not included here. */
  /* Invoke the entry-point functions.
  You can call entry-point functions multiple times. */


#if 0  
  main_myInitialModelIncrLearn();
#else
  incrementalRegressionLinear incrementalModel;
  if (DEBUG_LOW) printf("\n incrementalModel.WeightBuffer[0] = %.4f ",incrementalModel.WeightBuffer[0] );
  if (DEBUG_LOW) printf("\n incrementalModel.Impl.Beta[0] = %.4f ",incrementalModel.Impl.Beta[0] );
  /* Call the entry-point 'myInitialModelIncrLearn'. */
  myInitialModelIncrLearn(&incrementalModel);
  if (DEBUG_LOW) printf("\n incrementalModel.WeightBuffer[0] = %.4f ",incrementalModel.WeightBuffer[0] );
  if (DEBUG_LOW) printf("\n incrementalModel.Impl.Beta[0] = %.4f ",incrementalModel.Impl.Beta[0] );
#endif  
  

  printf("\n -------  start for loop -------------- \n");

  int             win_offset;
  int             win_count = 0;


  for (idx = 0; idx < idxCount; idx++) {


    win_offset          = idx % win_size;
    for (j = 0; j < 20; j++) {
      x_in_win[(win_offset * x_size) +j] = x_norm[idx][j];
    }
    y_obsered_win[win_offset] = y_norm[idx][0];
    Y_observed_win[win_offset] = Y[idx][0];

    if (DEBUG_SINGLE) printf("\n idx = %d / win_offset = %d / win_count = %d ", idx, win_offset, win_count);

    if (win_offset != (win_size - 1)) continue;

    /////////////////////////////////////////////////////

    
    win_count           = win_count + 1;
    if (DEBUG_SINGLE) printf("\n win_count up   = %d    ", win_count);

    //    for (j = 0; j < 20; j++) {
    //      x_in[j]             = x_norm[idx][j];
    //    }
    //    y_out               = y_norm[idx][0];
    //    Y_observed          = Y[idx][0];
    if (DEBUG_SINGLE) {
      printVector1D(x_in_win, x_size * win_size, "\n x_in_win norm =\n");
      printVector1D(y_obsered_win, win_size, "\n y_obsered_win norm =\n");
      printVector1D(Y_observed_win, win_size, "\n Y_observed_win=\n");
    }


//    main_myMAE();
//    main_myRMSE();
//    main_myMAPE();
//    main_myMSE();

    // matlab - IsWarm is always false
    //if(idx < 50 ) incrementalModel.IsWarm = true;

    for(i=0;i<20;i++){
      if (DEBUG_LOW) printf("\n incrementalModel.Impl.Beta[%d] = %.4f ",i,incrementalModel.Impl.Beta[i] );
    }

    // case 1 : put labeled y 
    c_main_myUpdateMetricsAndFitInc(&incrementalModel,x_in_win, y_obsered_win);
    if (DEBUG_LOW)  printVector1D(y_fit_win_before,5, "\n y_fit_win_before");
    denormal_y5(y_fit_win_before, Y_fit_win_before);
    if (DEBUG_LOW)  printVector1D(Y_fit_win_before,5, "\n Y_fit_win_before");


    if (DEBUG_LOW) printf("\n incrementalModel.WeightBuffer[0] = %.4f ",incrementalModel.WeightBuffer[0] );
    //if (DEBUG_LOW) printf("\n incrementalModel.Impl.Beta[0] = %.4f ",incrementalModel.Impl.Beta[0] );
    for(i=0;i<20;i++){
      if (DEBUG_LOW) printf("\n incrementalModel.Impl.Beta[%d] = %.4f ",i,incrementalModel.Impl.Beta[i] );
    }
    //main_myFitIncrLearn();

    main_myPredictIncrLearn(incrementalModel,x_in_win, y_fit_win);
  
    if (DEBUG_LOW)  printVector1D(y_fit_win,5, "\n y_fit_win");
    denormal_y5(y_fit_win, Y_fit_win);
    if (DEBUG_LOW) printVector1D(Y_fit_win,5, "\n Y_fit_win");

    if (DEBUG_LOW) printf("\n incrementalModel.WeightBuffer[0] = %.4f ",incrementalModel.WeightBuffer[0] );
    //if (DEBUG_LOW) printf("\n incrementalModel.Impl.Beta[0] = %.4f ",incrementalModel.Impl.Beta[0] );
    for(i=0;i<20;i++){
      if (DEBUG_LOW) printf("\n incrementalModel.Impl.Beta[%d] = %.4f ",i,incrementalModel.Impl.Beta[i] );
    }      
    

    int idx_new;
    
    for(i=4,j=0;i>=0;i--,j++){
      idx_new = idx - i;

#define USE_FROM_FIT  0
#if USE_FROM_FIT
      Y_fit = Y_fit_win_before[j];
      y_fit = y_fit_win_before[j];
#else
      Y_fit = Y_fit_win[j];
      y_fit = y_fit_win[j];
#endif 
    
      Y_hat_all[idx_new]      = Y_fit;
      Y_observed_all[idx_new] = Y[idx_new][0];
      Y_absolute_error_all[idx_new] = fabs(Y_observed_all[idx_new] -Y_hat_all[idx_new]);
      Y_square_error_all[idx_new] = pow(Y_absolute_error_all[idx_new], 2);
      Y_absolute_percentage_error_all[idx_new] = Y_absolute_error_all[idx_new] / Y_observed_all[idx_new];

      if (DEBUG_PRED) printf("\n\n idx            = %d    ", idx_new);
      if (DEBUG_PRED) printf("\n Predict    norm  = %.4f ", y_fit);
      if (DEBUG_PRED) printf("\n Observered norm  = %.4f ", y_norm[idx_new][0]);
      if (DEBUG_PRED) printf("\n Predict          = %.4f ", Y_fit);
      if (DEBUG_PRED) printf("\n Observered       = %.4f ", Y[idx_new][0]);
      if (DEBUG_PRED) printf("\n RUL              = %.4f ", idxCount + 1.0 - idx_new);
      if (DEBUG_PRED) printf("\n AE               = %.4f ", Y_absolute_error_all[idx_new]);
      if (DEBUG_PRED) printf("\n APE              = %.4f ", Y_absolute_percentage_error_all[idx_new]);
      fflush(stdout);
    }

#if TEST_SINGLE
    if (win_count == 1) break;
#endif
  }
  Y_mape              = 0;
  Y_rmse              = 0;

  for (i = 0; i < idxCount; i++) {
    Y_mape              += Y_absolute_percentage_error_all[i];
    Y_rmse              += Y_square_error_all[i];
  }


  Y_mape              = Y_mape / idxCount * 100;
  Y_rmse              = sqrt(Y_rmse / idxCount);

  if (DEBUG_PRED) {
    printf("\n\n ---- summary of battery # %2d -----", bat_num);
    printf("\n RMSE = %.4f ", Y_rmse);
    printf("\n MAPE = %.4f ", Y_mape);

  }


  printf("\n\n Congraturation, It works !!! \n");
  /* Terminate the application.
  You do not need to do this more than one time. */
  myInitialModelIncrLearn_terminate();
  return 0;
}


/* End of code generation (main.c) */
