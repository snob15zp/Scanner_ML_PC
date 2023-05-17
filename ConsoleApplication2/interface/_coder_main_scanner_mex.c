/*
 * File: _coder_main_scanner_mex.c
 *
 * MATLAB Coder version            : 5.3
 * C/C++ source code generated on  : 14-May-2023 01:58:12
 */

/* Include Files */
#include "_coder_main_scanner_mex.h"
#include "_coder_main_scanner_api.h"

/* Function Definitions */
/*
 * Arguments    : int32_T nlhs
 *                mxArray *plhs[]
 *                int32_T nrhs
 *                const mxArray *prhs[]
 * Return Type  : void
 */
void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs,
                 const mxArray *prhs[])
{
  mexAtExit(&main_scanner_atexit);
  /* Module initialization. */
  main_scanner_initialize();
  /* Dispatch the entry-point. */
  unsafe_main_scanner_mexFunction(nlhs, plhs, nrhs, prhs);
  /* Module termination. */
  main_scanner_terminate();
}

/*
 * Arguments    : void
 * Return Type  : emlrtCTX
 */
emlrtCTX mexFunctionCreateRootTLS(void)
{
  emlrtCreateRootTLSR2021a(&emlrtRootTLSGlobal, &emlrtContextGlobal, NULL, 1,
                           NULL);
  return emlrtRootTLSGlobal;
}

/*
 * Arguments    : int32_T nlhs
 *                mxArray *plhs[1]
 *                int32_T nrhs
 *                const mxArray *prhs[6]
 * Return Type  : void
 */
void unsafe_main_scanner_mexFunction(int32_T nlhs, mxArray *plhs[1],
                                     int32_T nrhs, const mxArray *prhs[6])
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  const mxArray *outputs;
  st.tls = emlrtRootTLSGlobal;
  /* Check for proper number of arguments. */
  if (nrhs != 6) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 6, 4,
                        12, "main_scanner");
  }
  if (nlhs > 1) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 12,
                        "main_scanner");
  }
  /* Call the function. */
  main_scanner_api(prhs, &outputs);
  /* Copy over outputs to the caller. */
  emlrtReturnArrays(1, &plhs[0], &outputs);
}

/*
 * File trailer for _coder_main_scanner_mex.c
 *
 * [EOF]
 */
