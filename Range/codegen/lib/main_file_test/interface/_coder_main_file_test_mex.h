/*
 * File: _coder_main_file_test_mex.h
 *
 * MATLAB Coder version            : 5.3
 * C/C++ source code generated on  : 08-May-2023 13:56:17
 */

#ifndef _CODER_MAIN_FILE_TEST_MEX_H
#define _CODER_MAIN_FILE_TEST_MEX_H

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

void unsafe_main_file_test_mexFunction(int32_T nlhs, int32_T nrhs);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for _coder_main_file_test_mex.h
 *
 * [EOF]
 */
