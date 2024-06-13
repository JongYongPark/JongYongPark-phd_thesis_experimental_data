

/* Include files */
#include "main.h"
#include "RegressionLinearModel_terminate.h"
#include "RegressionLinearModel_types.h"
#include "predict.h"
#include "rt_nonfinite.h"
#include "update.h"

///////// ryan add 
#include <stdlib.h>
#include <errno.h>
#include <limits.h>
#include <string.h>


#include <stdio.h>
#include "debug.h"



#define x_size                  20      
#define win_size                5
#define changeMargin            20

#define MAX_BAT_SIZE            2000 


#if TEST_BAT_NUM_1
#include "../bat_header/x_norm_1.h" 
#include "../bat_header/y_norm_1.h"
#include "../bat_header/Y_1.h"
int             bat_num = 1;
#endif

#if TEST_BAT_NUM_1_CHANGE_21
#include "../bat_header/x_norm_21.h" 
#include "../bat_header/y_norm_21.h"
#include "../bat_header/Y_21.h"
int             bat_num = 21;
#endif


#if TEST_BAT_NUM_1_CHANGE_211
#include "../bat_header/x_norm_211.h" 
#include "../bat_header/y_norm_211.h"
#include "../bat_header/Y_211.h"
int             bat_num = 211;
#endif


#if TEST_BAT_NUM_1_CHANGE_23
#include "../bat_header/x_norm_23.h" 
#include "../bat_header/y_norm_23.h"
#include "../bat_header/Y_23.h"
int             bat_num = 23;
#endif

#if TEST_BAT_NUM_1_CHANGE_233
#include "../bat_header/x_norm_233.h" 
#include "../bat_header/y_norm_233.h"
#include "../bat_header/Y_233.h"
int             bat_num = 233;
#endif


#if TEST_BAT_NUM_2
#include "../bat_header/x_norm_2.h" 
#include "../bat_header/y_norm_2.h"
#include "../bat_header/Y_2.h"
int             bat_num = 2;
#endif



#include <math.h> // fabs 
#include <stddef.h> // NULL 

// for debug
//#define TEST_SINGLE             1
//#define DEBUG_SINGLE            1
//#define DEBUG_PRED_ALL          1  
//#define DEBUG_PRED              1 
// for release
#define TEST_SINGLE             0
#define DEBUG_SINGLE            0 
#define DEBUG_PRED_ALL          0 
#define DEBUG_PRED              1 



// print scenario 12 data
#define USE_SCENARIO_12         1


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
double          Y_error_all[MAX_BAT_SIZE];
double          Y_absolute_error_all[MAX_BAT_SIZE];
double          Y_absolute_percentage_error_all[MAX_BAT_SIZE];
double          Y_hat_diff_all[MAX_BAT_SIZE];

/* Function Declarations */
static void argInit_20x1_real_T(double result[20]);

static double argInit_real_T(void);

static void argInit_struct0_T(struct0_T * result);

//static void main_predict(void);
static double main_predict(double dv[20]);

static void main_update(struct0_T r);


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


static double argInit_real_T(void)
{
  return 0.0;
}


static void argInit_struct0_T(struct0_T * result)
{
  /* Set the value of each structure field.
  Change this value to the value that the application requires. */
  argInit_20x1_real_T(result->Beta);
  result->Bias        = argInit_real_T();
}


static double main_predict(double dv[20])
{
  if (DEBUG_LOW) printf("\n==> main_predict");

  //double          dv[20];
  double          varargout_1;

  /* Initialize function 'predict' input arguments. */
  /* Initialize function input argument 'X'. */
  /* Call the entry-point 'predict'. */
  if (DEBUG_LOW) printf("\ndv[0] = %.4f ", dv[0]);

  //argInit_20x1_real_T(dv);
  if (DEBUG_LOW) printf("\ndv[0] = %.4f ", dv[0]);

  varargout_1         = predict(dv);

  if (DEBUG_LOW) printf("\n<-- main_predict");

  return varargout_1;
}


// need to change. 
static void main_update(struct0_T r)
{
  if (DEBUG_LOW) {
    printf("\n==> main_update");
  }

  //struct0_T       r;

  /* Initialize function 'update' input arguments. */
  /* Initialize function input argument 'varargin_1'. */
  /* Call the entry-point 'update'. */
  argInit_struct0_T(&r);
  update(&r);

  if (DEBUG_LOW) {
    printf("\n<-- main_update");
  }
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


  double          Y_rmse;
  double          Y_mape;
  double          Y_rmse_pre;
  double          Y_mape_pre;
  double          Y_rmse_post;
  double          Y_mape_post;
  int             idx;


#if TEST_BAT_NUM_1
  idxCount            = sizeof(Y_1) / 8;
  printf("\n idxCount = %d ", idxCount);
  printf("\n charge/discharge patten does not change ");

  for (i = 0; i < idxCount; i++) {
    for (j = 0; j < 20; j++) {
      x_norm[i][j]        = x_norm_1[i][j];
    }
    y_norm[i][0]        = y_norm_1[i][0];
    Y[i][0]             = Y_1[i][0];
  }
#endif


#if TEST_BAT_NUM_1_CHANGE_21
  idxCount            = sizeof(Y_21) / 8;
  printf("\n idxCount = %d ", idxCount);
  printf("\n charge/discharge patten changes at 210 cycle ");
  for (i = 0; i < idxCount; i++) {
    for (j = 0; j < 20; j++) {
      x_norm[i][j]        = x_norm_21[i][j];
    }
    y_norm[i][0]        = y_norm_21[i][0];
    Y[i][0]             = Y_21[i][0];
  }
#endif

#if TEST_BAT_NUM_1_CHANGE_211
  idxCount            = sizeof(Y_211) / 8;
  printf("\n idxCount = %d ", idxCount);
  printf("\n charge/discharge patten changes at 210 cycle ");
  for (i = 0; i < idxCount; i++) {
    for (j = 0; j < 20; j++) {
      x_norm[i][j]        = x_norm_211[i][j];
    }
    y_norm[i][0]        = y_norm_211[i][0];
    Y[i][0]             = Y_211[i][0];
  }
#endif


#if TEST_BAT_NUM_1_CHANGE_23
  idxCount            = sizeof(Y_23) / 8;
  printf("\n idxCount = %d ", idxCount);
  printf("\n charge/discharge patten changes at 210 cycle ");
  for (i = 0; i < idxCount; i++) {
    for (j = 0; j < 20; j++) {
      x_norm[i][j]        = x_norm_23[i][j];
    }
    y_norm[i][0]        = y_norm_23[i][0];
    Y[i][0]             = Y_23[i][0];
  }
#endif

#if TEST_BAT_NUM_1_CHANGE_233
  idxCount            = sizeof(Y_233) / 8;
  printf("\n idxCount = %d ", idxCount);
  printf("\n charge/discharge patten changes at 210 cycle ");
  for (i = 0; i < idxCount; i++) {
    for (j = 0; j < 20; j++) {
      x_norm[i][j]        = x_norm_233[i][j];
    }
    y_norm[i][0]        = y_norm_233[i][0];
    Y[i][0]             = Y_233[i][0];
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
  if(DEBUG_SINGLE) printVector2D20(x_norm, 1, "\n\n x_norm data \n----------------\n");
  if(DEBUG_SINGLE) printVector2D1(y_norm, 1, "\n\n y_norm data \n----------------\n");
  if(DEBUG_SINGLE) printVector2D1(Y, 1, "\n\n Y data \n----------------\n");


  if(DEBUG_SINGLE) printf("\n -------  start for loop -------------- \n");
  if(DEBUG_PRED) printf("\n\n idx, Predict, Observed, AE, SE, APE(%%), PredictNorm, ObservedNorm ");
  for (idx = 0; idx < idxCount; idx++) {

    for (j = 0; j < 20; j++) {
      x_in[j]             = x_norm[idx][j];
    }
    y_out               = y_norm[idx][0];
    Y_observed          = Y[idx][0];

    if (DEBUG_SINGLE) {
      printVector1D(x_in, 20, "\n x_in norm =\n");
      printDouble(y_out, "\n y_out norm =\n");
      printDouble(Y_observed, "\n Y_observed=\n");
    }

    /* The initialize function is being called automatically from your entry-point
     * function. So, a call to initialize is not included here. */
    /* Invoke the entry-point functions.
    You can call entry-point functions multiple times. */
    // ryan del - do not call this 
    //main_update();
    y_fit               = main_predict(x_in);
    Y_fit               = denormal_y(y_fit);

    Y_hat_all[idx]      = Y_fit;
    if(idx == 0) Y_hat_diff_all[idx] = 0;
    else Y_hat_diff_all[idx] = Y_hat_all[idx-1] - Y_hat_all[idx];  
    Y_observed_all[idx] = Y[idx][0]; 
    Y_error_all[idx] = Y_observed_all[idx] -Y_hat_all[idx];
    Y_absolute_error_all[idx] = fabs(Y_error_all[idx]);
    Y_square_error_all[idx] = pow(Y_absolute_error_all[idx], 2);
    Y_absolute_percentage_error_all[idx] = Y_absolute_error_all[idx] / Y_observed_all[idx] * 100;

    if (DEBUG_PRED_ALL) printf("\n\n idx            = %4d    ", idx);
    if (DEBUG_PRED_ALL) printf("\n Predict    norm  = %.4f ", y_fit);
    if (DEBUG_PRED_ALL) printf("\n Observered norm  = %.4f ", y_norm[idx][0]);
    if (DEBUG_PRED_ALL) printf("\n Predict          = %.4f ", Y_fit);
    if (DEBUG_PRED_ALL) printf("\n Observered       = %.4f ", Y[idx][0]);
    if (DEBUG_PRED_ALL) printf("\n RUL              = %.4f ", idxCount + 1.0 - idx);
    if (DEBUG_PRED_ALL) printf("\n AE               = %.4f ", Y_absolute_error_all[idx]);
    if (DEBUG_PRED_ALL) printf("\n SE               = %.4f ", Y_square_error_all[idx]);
    if (DEBUG_PRED_ALL) printf("\n APE              = %.4f ", Y_absolute_percentage_error_all[idx]);

    //if(DEBUG_PRED) printf("\n\n  idx, Predict, Observed, AE, SE, APE, PredictNorm, ObservedNorm ");
    if(DEBUG_PRED) printf("\n %4d, [%.4f, %d], [%4f, %4f, %4f], %4f, %4f ",  \
      idx,Y_fit,(int) Y[idx][0], \
      Y_absolute_error_all[idx],Y_square_error_all[idx],Y_absolute_percentage_error_all[idx], \
      y_fit,y_norm[idx][0] );
    
    fflush(stdout);

#if TEST_SINGLE
    if (idx == 4) break;
#endif

  }

  Y_mape              = 0;
  Y_rmse              = 0;
  Y_mape_pre          = 0;
  Y_rmse_pre          = 0;
  Y_mape_post         = 0;
  Y_rmse_post         = 0;
  int             idxCountPre = 50;
  int             idxCountPost = idxCount - idxCountPre;

#if USE_SCENARIO_12

  for (i = 0; i < idxCountPre; i++) {
    Y_mape_pre          += Y_absolute_percentage_error_all[i];
    Y_rmse_pre          += Y_square_error_all[i];
  }

  Y_mape_pre          = Y_mape_pre / idxCountPre ;
  Y_rmse_pre          = sqrt(Y_rmse_pre / idxCountPre);

  if (DEBUG_PRED) {
    printf("\n\n ---- summary of battery # %2d pre= 1 ~ 50 (cycle) -----", bat_num);
    printf("\n RMSE_pre = %.4f ", Y_rmse_pre);
    printf("\n MAPE_pre = %.4f ", Y_mape_pre);
  }

  ///////////////
  for (; i < idxCount; i++) {
    Y_mape_post         += Y_absolute_percentage_error_all[i];
    Y_rmse_post         += Y_square_error_all[i];
  }

  Y_mape_post         = Y_mape_post / idxCountPost ;
  Y_rmse_post         = sqrt(Y_rmse_post / idxCountPost);

  if (DEBUG_PRED) {
    printf("\n\n ---- summary of battery # %2d post= 51 ~ %d (cycle) -----", idxCount);
    printf("\n RMSE_post = %.4f ", Y_rmse_post);
    printf("\n MAPE_post = %.4f ", Y_mape_post);
  }

#endif 

  int Y_hat_diff_abs =0;

  if (DEBUG_PRED) printf("\n");
  
  for (i = 0; i < idxCount; i++) {
    Y_mape              += Y_absolute_percentage_error_all[i];
    Y_rmse              += Y_square_error_all[i];
  
    Y_hat_diff_abs = (int) fabs(Y_hat_diff_all[i]);
    if(Y_hat_diff_all[i] > changeMargin ) { 
      if (DEBUG_PRED) printf("\n Patten changes at %d cycle to decrease %d RUL. Bad !!!",i,Y_hat_diff_abs);
    }
    else if(Y_hat_diff_all[i] < -changeMargin ) { 
      if (DEBUG_PRED) printf("\n Patten changes at %d cycle to increase % RUL Good !!!",i,Y_hat_diff_abs);
    }
    
  }
  Y_mape              = Y_mape / idxCount ;
  Y_rmse              = sqrt(Y_rmse / idxCount);

  if (DEBUG_PRED) {
    printf("\n\n ---- summary of battery # %2d -----", bat_num);
    printf("\n RMSE = %.4f ", Y_rmse);
    printf("\n MAPE = %.4f ", Y_mape);
  }

  printf("\n\n Congraturation, It works !!! \n");

  /* Terminate the application.
  You do not need to do this more than one time. */
  RegressionLinearModel_terminate();
  return 0;
}


/* End of code generation (main.c) */
