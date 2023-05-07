/*
 * File: _coder_calculation_second_tone_freq_api.h
 *
 * MATLAB Coder version            : 3.3
 * C/C++ source code generated on  : 03-May-2023 17:35:58
 */

#ifndef _CODER_CALCULATION_SECOND_TONE_FREQ_API_H
#define _CODER_CALCULATION_SECOND_TONE_FREQ_API_H

/* Include Files */
#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"
#include <stddef.h>
#include <stdlib.h>
#include "_coder_calculation_second_tone_freq_api.h"

/* Variable Declarations */
extern emlrtCTX emlrtRootTLSGlobal;
extern emlrtContext emlrtContextGlobal;

/* Function Declarations */
extern void calculation_second_tone_freq(real_T FftR[45000000], real_T Fd,
  real_T FftL, real_T *fv, real_T *Am, real_T *im);
extern void calculation_second_tone_freq_api(const mxArray * const prhs[3],
  const mxArray *plhs[3]);
extern void calculation_second_tone_freq_atexit(void);
extern void calculation_second_tone_freq_initialize(void);
extern void calculation_second_tone_freq_terminate(void);
extern void calculation_second_tone_freq_xil_terminate(void);

#endif

/*
 * File trailer for _coder_calculation_second_tone_freq_api.h
 *
 * [EOF]
 */
