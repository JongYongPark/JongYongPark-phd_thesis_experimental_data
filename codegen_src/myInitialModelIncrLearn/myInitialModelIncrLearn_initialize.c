/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * myInitialModelIncrLearn_initialize.c
 *
 * Code generation for function 'myInitialModelIncrLearn_initialize'
 *
 */

/* Include files */
#include "myInitialModelIncrLearn_initialize.h"
#include "eml_rand_mt19937ar_stateful.h"
#include "myInitialModelIncrLearn_data.h"
#include "rt_nonfinite.h"

#include <stdio.h>
#include "debug.h"

/* Function Definitions */
void myInitialModelIncrLearn_initialize(void)
{
  if(DEBUG_LOW) printf("\n =>myInitialModelIncrLearn_initialize");	
	
  c_eml_rand_mt19937ar_stateful_i();
  isInitialized_myInitialModelIncrLearn = true;
}

/* End of code generation (myInitialModelIncrLearn_initialize.c) */
