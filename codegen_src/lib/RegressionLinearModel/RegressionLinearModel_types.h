/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * RegressionLinearModel_types.h
 *
 * Code generation for function 'update'
 *
 */

#ifndef REGRESSIONLINEARMODEL_TYPES_H
#define REGRESSIONLINEARMODEL_TYPES_H

/* Include files */
#include "rtwtypes.h"

/* Type Definitions */
#ifndef typedef_struct0_T
#define typedef_struct0_T
typedef struct {
  double Beta[20];
  double Bias;
} struct0_T;
#endif /* typedef_struct0_T */

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

#ifndef typedef_RegressionLinear
#define typedef_RegressionLinear
typedef struct {
  double Beta[20];
  double Bias;
  c_classreg_learning_coderutils_ ResponseTransform;
} RegressionLinear;
#endif /* typedef_RegressionLinear */

#endif
/* End of code generation (RegressionLinearModel_types.h) */
