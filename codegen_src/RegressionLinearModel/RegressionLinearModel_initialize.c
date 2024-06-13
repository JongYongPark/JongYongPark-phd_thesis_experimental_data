/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * RegressionLinearModel_initialize.c
 *
 * Code generation for function 'RegressionLinearModel_initialize'
 *
 */

/* Include files */
#include "RegressionLinearModel_initialize.h"
#include "RegressionLinearModel_data.h"
#include "initialize.h"
#include "rt_nonfinite.h"

#include <stdio.h>
#include "debug.h"

/* Function Definitions */
void RegressionLinearModel_initialize(void)
{
  if(DEBUG_LOW) printf("\n==> RegressionLinearModel_initialize");	
  initialize_init();
  isInitialized_RegressionLinearModel = true;
  if(DEBUG_LOW) printf("\n<-- RegressionLinearModel_initialize");	
}

/* End of code generation (RegressionLinearModel_initialize.c) */
