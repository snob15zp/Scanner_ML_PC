/*
 * File: tone_search_emxAPI.h
 *
 * MATLAB Coder version            : 5.3
 * C/C++ source code generated on  : 10-May-2023 13:37:04
 */

#ifndef TONE_SEARCH_EMXAPI_H
#define TONE_SEARCH_EMXAPI_H

/* Include Files */
#include "rtwtypes.h"
#include "tone_search_types.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
extern emxArray_real_T *emxCreateND_real_T(int numDimensions, const int *size);

extern emxArray_real_T *
emxCreateWrapperND_real_T(double *data, int numDimensions, const int *size);

extern emxArray_real_T *emxCreateWrapper_real_T(double *data, int rows,
                                                int cols);

extern emxArray_real_T *emxCreate_real_T(int rows, int cols);

extern void emxDestroyArray_real_T(emxArray_real_T *emxArray);

extern void emxInitArray_real_T(emxArray_real_T **pEmxArray, int numDimensions);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for tone_search_emxAPI.h
 *
 * [EOF]
 */
