/*
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * springMassTakeStep_emxutil.h
 *
 * Code generation for function 'springMassTakeStep_emxutil'
 *
 */

#ifndef SPRINGMASSTAKESTEP_EMXUTIL_H
#define SPRINGMASSTAKESTEP_EMXUTIL_H

/* Include files */
#include "rtwtypes.h"
#include "springMassTakeStep_types.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
extern void emxEnsureCapacity_real_T(emxArray_real_T *emxArray, int oldNumel);

extern void emxFree_real_T(emxArray_real_T **pEmxArray);

extern void emxInit_real_T(emxArray_real_T **pEmxArray);

#ifdef __cplusplus
}
#endif

#endif
/* End of code generation (springMassTakeStep_emxutil.h) */
