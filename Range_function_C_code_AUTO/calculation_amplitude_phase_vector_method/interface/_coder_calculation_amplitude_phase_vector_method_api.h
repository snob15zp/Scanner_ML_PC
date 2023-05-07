/*
 * File: _coder_calculation_amplitude_phase_vector_method_api.h
 *
 * MATLAB Coder version            : 3.3
 * C/C++ source code generated on  : 03-May-2023 17:58:10
 */

#ifndef _CODER_CALCULATION_AMPLITUDE_PHASE_VECTOR_METHOD_API_H
#define _CODER_CALCULATION_AMPLITUDE_PHASE_VECTOR_METHOD_API_H

/* Include Files */
#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"
#include <stddef.h>
#include <stdlib.h>
#include "_coder_calculation_amplitude_phase_vector_method_api.h"

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
extern void calculation_amplitude_phase_vector_method(real_T Tm, real_T Fd,
  real_T Signal[2250001], real_T FftL, real_T FftS[45000000], real_T T[2250001],
  real_T f, real_T *a, real_T *p, real_T RS[2250001], emxArray_real_T *FftR);
extern void calculation_amplitude_phase_vector_method_api(const mxArray * const
  prhs[7], const mxArray *plhs[4]);
extern void calculation_amplitude_phase_vector_method_atexit(void);
extern void calculation_amplitude_phase_vector_method_initialize(void);
extern void calculation_amplitude_phase_vector_method_terminate(void);
extern void calculation_amplitude_phase_vector_method_xil_terminate(void);

#endif

/*
 * File trailer for _coder_calculation_amplitude_phase_vector_method_api.h
 *
 * [EOF]
 */
