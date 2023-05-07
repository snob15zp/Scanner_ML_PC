/*
 * File: generation_test_signal_emxutil.h
 *
 * MATLAB Coder version            : 3.3
 * C/C++ source code generated on  : 03-May-2023 17:04:01
 */

#ifndef GENERATION_TEST_SIGNAL_EMXUTIL_H
#define GENERATION_TEST_SIGNAL_EMXUTIL_H

/* Include Files */
#include <float.h>
#include <math.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rt_nonfinite.h"
#include "rtwtypes.h"
#include "generation_test_signal_types.h"

/* Function Declarations */
extern void emxEnsureCapacity(emxArray__common *emxArray, int oldNumel, unsigned
  int elementSize);
extern void emxFree_real_T(emxArray_real_T **pEmxArray);
extern void emxInit_real_T(emxArray_real_T **pEmxArray, int numDimensions);

#endif

/*
 * File trailer for generation_test_signal_emxutil.h
 *
 * [EOF]
 */
