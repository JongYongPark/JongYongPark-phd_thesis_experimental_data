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

int main(int argc, char **argv)
{
  (void)argc;
  (void)argv;
  /* The initialize function is being called automatically from your entry-point
   * function. So, a call to initialize is not included here. */
  /* Invoke the entry-point functions.
You can call entry-point functions multiple times. */
  main_update();
  main_predict();
  /* Terminate the application.
You do not need to do this more than one time. */
  RegressionLinearModel_terminate();
  return 0;
}

/* End of code generation (main.c) */
