/*
 * File: spectral_representation_signal_emxutil.h
 *
 * MATLAB Coder version            : 3.3
 * C/C++ source code generated on  : 03-May-2023 17:17:21
 */

#ifndef SPECTRAL_REPRESENTATION_SIGNAL_EMXUTIL_H
#define SPECTRAL_REPRESENTATION_SIGNAL_EMXUTIL_H

/* Include Files */
#include <math.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rt_nonfinite.h"
#include "rtwtypes.h"
#include "spectral_representation_signal_types.h"

/* Function Declarations */
extern void emxEnsureCapacity(emxArray__common *emxArray, int oldNumel, unsigned
  int elementSize);
extern void emxFree_creal_T(emxArray_creal_T **pEmxArray);
extern void emxFree_real_T(emxArray_real_T **pEmxArray);
extern void emxInit_creal_T(emxArray_creal_T **pEmxArray, int numDimensions);
extern void emxInit_real_T(emxArray_real_T **pEmxArray, int numDimensions);

#endif

/*
 * File trailer for spectral_representation_signal_emxutil.h
 *
 * [EOF]
 */
