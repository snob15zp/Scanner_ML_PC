/*
 * File: _coder_approximation_freq_max_vector_api.h
 *
 * MATLAB Coder version            : 3.3
 * C/C++ source code generated on  : 03-May-2023 17:47:49
 */

#ifndef _CODER_APPROXIMATION_FREQ_MAX_VECTOR_API_H
#define _CODER_APPROXIMATION_FREQ_MAX_VECTOR_API_H

/* Include Files */
#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"
#include <stddef.h>
#include <stdlib.h>
#include "_coder_approximation_freq_max_vector_api.h"

/* Variable Declarations */
extern emlrtCTX emlrtRootTLSGlobal;
extern emlrtContext emlrtContextGlobal;

/* Function Declarations */
extern void approximation_freq_max_vector(real_T Tm, real_T Fd, real_T Signal
  [2250001], real_T *f);
extern void approximation_freq_max_vector_api(const mxArray * const prhs[4],
  const mxArray *plhs[1]);
extern void approximation_freq_max_vector_atexit(void);
extern void approximation_freq_max_vector_initialize(void);
extern void approximation_freq_max_vector_terminate(void);
extern void approximation_freq_max_vector_xil_terminate(void);

#endif

/*
 * File trailer for _coder_approximation_freq_max_vector_api.h
 *
 * [EOF]
 */
