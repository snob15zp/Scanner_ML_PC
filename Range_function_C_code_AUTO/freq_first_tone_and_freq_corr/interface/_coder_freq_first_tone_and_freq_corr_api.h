/*
 * File: _coder_freq_first_tone_and_freq_corr_api.h
 *
 * MATLAB Coder version            : 3.3
 * C/C++ source code generated on  : 03-May-2023 17:42:44
 */

#ifndef _CODER_FREQ_FIRST_TONE_AND_FREQ_CORR_API_H
#define _CODER_FREQ_FIRST_TONE_AND_FREQ_CORR_API_H

/* Include Files */
#include "tmwtypes.h"
#include "mex.h"
#include "emlrt.h"
#include <stddef.h>
#include <stdlib.h>
#include "_coder_freq_first_tone_and_freq_corr_api.h"

/* Variable Declarations */
extern emlrtCTX emlrtRootTLSGlobal;
extern emlrtContext emlrtContextGlobal;

/* Function Declarations */
extern real_T freq_first_tone_and_freq_corr(real_T FftS[45000000], real_T FftL,
  real_T Fd);
extern void freq_first_tone_and_freq_corr_api(const mxArray * const prhs[3],
  const mxArray *plhs[1]);
extern void freq_first_tone_and_freq_corr_atexit(void);
extern void freq_first_tone_and_freq_corr_initialize(void);
extern void freq_first_tone_and_freq_corr_terminate(void);
extern void freq_first_tone_and_freq_corr_xil_terminate(void);

#endif

/*
 * File trailer for _coder_freq_first_tone_and_freq_corr_api.h
 *
 * [EOF]
 */
