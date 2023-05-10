/*
 * File: _coder_tone_search_mex.h
 *
 * MATLAB Coder version            : 5.3
 * C/C++ source code generated on  : 10-May-2023 18:07:25
 */

#ifndef _CODER_TONE_SEARCH_MEX_H
#define _CODER_TONE_SEARCH_MEX_H

/* Include Files */
#include "emlrt.h"
#include "mex.h"
#include "tmwtypes.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
MEXFUNCTION_LINKAGE void mexFunction(int32_T nlhs, mxArray *plhs[],
                                     int32_T nrhs, const mxArray *prhs[]);

emlrtCTX mexFunctionCreateRootTLS(void);

void unsafe_tone_search_mexFunction(int32_T nlhs, mxArray *plhs[6],
                                    int32_T nrhs, const mxArray *prhs[9]);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for _coder_tone_search_mex.h
 *
 * [EOF]
 */
