/*
 * File: _coder_generation_test_signal_api.h
 *
 * MATLAB Coder version            : 3.3
 * C/C++ source code generated on  : 03-May-2023 17:04:01
 */

#ifndef _CODER_GENERATION_TEST_SIGNAL_API_H
#define _CODER_GENERATION_TEST_SIGNAL_API_H

/* Include Files */
#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"
#include <stddef.h>
#include <stdlib.h>
#include "_coder_generation_test_signal_api.h"

/* Type Definitions */
#ifndef struct_emxArray_real_T
#define struct_emxArray_real_T

struct emxArray_real_T
{
  real_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};

#endif                                 /*struct_emxArray_real_T*/

#ifndef typedef_emxArray_real_T
#define typedef_emxArray_real_T

typedef struct emxArray_real_T emxArray_real_T;

#endif                                 /*typedef_emxArray_real_T*/

/* Variable Declarations */
extern emlrtCTX emlrtRootTLSGlobal;
extern emlrtContext emlrtContextGlobal;

/* Function Declarations */
extern void generation_test_signal(real_T Tm, real_T Fd, real_T mz, real_T Ak,
  real_T A1, real_T A2, real_T F1, real_T F2, real_T P1, real_T P2, real_T An,
  emxArray_real_T *Signal, emxArray_real_T *T, real_T *FftL);
extern void generation_test_signal_api(const mxArray * const prhs[11], const
  mxArray *plhs[3]);
extern void generation_test_signal_atexit(void);
extern void generation_test_signal_initialize(void);
extern void generation_test_signal_terminate(void);
extern void generation_test_signal_xil_terminate(void);

#endif

/*
 * File trailer for _coder_generation_test_signal_api.h
 *
 * [EOF]
 */
