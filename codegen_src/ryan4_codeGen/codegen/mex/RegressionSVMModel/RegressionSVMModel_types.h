/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * RegressionSVMModel_types.h
 *
 * Code generation for function 'update'
 *
 */

#pragma once

/* Include files */
#include "rtwtypes.h"
#include "emlrt.h"

/* Type Definitions */
#ifndef enum_c_classreg_learning_coderutils_
#define enum_c_classreg_learning_coderutils_
enum c_classreg_learning_coderutils_
{
  Logit = 0, /* Default value */
  Doublelogit,
  Invlogit,
  Ismax,
  Sign,
  Symmetric,
  Symmetricismax,
  Symmetriclogit,
  Identity
};
#endif /* enum_c_classreg_learning_coderutils_ */
#ifndef typedef_c_classreg_learning_coderutils_
#define typedef_c_classreg_learning_coderutils_
typedef enum c_classreg_learning_coderutils_ c_classreg_learning_coderutils_;
#endif /* typedef_c_classreg_learning_coderutils_ */

#ifndef enum_d_classreg_learning_coderutils_
#define enum_d_classreg_learning_coderutils_
enum d_classreg_learning_coderutils_
{
  linear = 1, /* Default value */
  gaussian = 2,
  rbf = 2,
  polynomial = 3
};
#endif /* enum_d_classreg_learning_coderutils_ */
#ifndef typedef_d_classreg_learning_coderutils_
#define typedef_d_classreg_learning_coderutils_
typedef enum d_classreg_learning_coderutils_ d_classreg_learning_coderutils_;
#endif /* typedef_d_classreg_learning_coderutils_ */

#ifndef typedef_struct0_T
#define typedef_struct0_T
typedef struct {
  real_T Alpha[75];
  real_T SupportVectors[150];
  real_T Scale;
  real_T Bias;
} struct0_T;
#endif /* typedef_struct0_T */

#ifndef typedef_c_classreg_learning_regr_Compac
#define typedef_c_classreg_learning_regr_Compac
typedef struct {
  real_T Alpha[75];
  real_T Bias;
  real_T SupportVectorsT[150];
  real_T Scale;
  real_T Order;
  d_classreg_learning_coderutils_ KernelFunction;
  c_classreg_learning_coderutils_ ResponseTransform;
} c_classreg_learning_regr_Compac;
#endif /* typedef_c_classreg_learning_regr_Compac */

/* End of code generation (RegressionSVMModel_types.h) */
