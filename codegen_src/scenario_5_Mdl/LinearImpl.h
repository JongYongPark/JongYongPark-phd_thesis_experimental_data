/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * LinearImpl.h
 *
 * Code generation for function 'LinearImpl'
 *
 */

#ifndef LINEARIMPL_H
#define LINEARIMPL_H

/* Include files */
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
void LinearImpl_score(const double this_Beta[20], double this_Bias,
                      const double X[100], const bool indsToExclude[5],
                      double s[5]);

#ifdef __cplusplus
}
#endif

#endif
/* End of code generation (LinearImpl.h) */
