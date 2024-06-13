/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * initialize.c
 *
 * Code generation for function 'initialize'
 *
 */

/* Include files */
#include "initialize.h"
#include "RegressionLinearModel_data.h"
#include "RegressionLinearModel_types.h"
#include "rt_nonfinite.h"
#include <string.h>

#include <stdio.h>
#include "debug.h"

/* Function Definitions */
void initialize_init(void)
{
  int i;
  if(DEBUG_LOW) printf("\n==> initialize_init");		
  static const double dv[20] = {
      -0.42997605270260425,  -0.24711799399727324,  -0.056473321691659355,
      0.036007825676545452,  0.16132292316435351,   0.33048390301438635,
      0.49494610696888586,   0.5662022852461851,    0.45752539693099548,
      0.24277411624058964,   0.050338334120058739,  -0.092353033610206081,
      -0.077117324376923049, -0.003411004998634224, 0.13978506015100217,
      -0.031703433428532837, 1.0318332478129191,    0.27087748723516464,
      -0.49464291416451917,  -0.48236545732124547};
  model.ResponseTransform = Identity;
  model.Bias = -1.0687184316391805;
  memcpy(&model.Beta[0], &dv[0], 20U * sizeof(double));
  
  
  for (i = 0; i < 20; i++) if(DEBUG_LOW && i == 0 ) printf("\n model.Beta[%d] = %.10f", i, model.Beta[i]);
  if(DEBUG_LOW) printf("\n Address of model.Beta[0]: %p\n", &model.Beta[0]);

  if(DEBUG_LOW) printf("\n<-- initialize_init");	
}

/* End of code generation (initialize.c) */
