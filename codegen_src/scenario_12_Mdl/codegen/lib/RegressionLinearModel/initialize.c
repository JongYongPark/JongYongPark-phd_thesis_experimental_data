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
      -0.0010261413478958351,  -0.00083772340380834827, -0.00075479743136497768,
      -0.00071173965498412973, -0.00067755092917588106, -0.0006386249308620107,
      -0.000602734159262815,   -0.00056328459076641912, -0.00051303353443749684,
      -0.00043384078591520396, -0.00031101058318206575, -0.0001135311983267443,
      0.00021886760446327,     0.00083579433215577787,  0.0021624095561059973,
      0.0053796409271614437,   0.01158826320520979,     7.1426901985837866E-6,
      1.1354237102725078E-5,   1.1354237102725078E-5};
  model.ResponseTransform = Identity;
  model.Bias = 0.24725144910260405;
  memcpy(&model.Beta[0], &dv[0], 20U * sizeof(double));
  
  
  for (i = 0; i < 20; i++) if(DEBUG_LOW && i == 0 ) printf("\n model.Beta[%d] = %.4f", i, model.Beta[i]);
  if(DEBUG_LOW) printf("\n Address of model.Beta[0]: %p\n", &model.Beta[0]);

  if(DEBUG_LOW) printf("\n<-- initialize_init");	
}

/* End of code generation (initialize.c) */
