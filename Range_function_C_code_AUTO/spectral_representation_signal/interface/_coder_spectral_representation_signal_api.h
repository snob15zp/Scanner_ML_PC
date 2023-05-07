/*
 * File: _coder_spectral_representation_signal_api.h
 *
 * MATLAB Coder version            : 3.3
 * C/C++ source code generated on  : 03-May-2023 17:17:21
 */

#ifndef _CODER_SPECTRAL_REPRESENTATION_SIGNAL_API_H
#define _CODER_SPECTRAL_REPRESENTATION_SIGNAL_API_H

/* Include Files */
#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"
#include <stddef.h>
#include <stdlib.h>
#include "_coder_spectral_representation_signal_api.h"

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
extern void spectral_representation_signal(real_T Signal[2250001], real_T FftL,
  emxArray_real_T *FftS);
extern void spectral_representation_signal_api(const mxArray * const prhs[2],
  const mxArray *plhs[1]);
extern void spectral_representation_signal_atexit(void);
extern void spectral_representation_signal_initialize(void);
extern void spectral_representation_signal_terminate(void);
extern void spectral_representation_signal_xil_terminate(void);

#endif

/*
 * File trailer for _coder_spectral_representation_signal_api.h
 *
 * [EOF]
 */
