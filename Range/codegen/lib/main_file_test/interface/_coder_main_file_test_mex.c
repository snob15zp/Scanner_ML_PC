/*
 * File: _coder_main_file_test_mex.c
 *
 * MATLAB Coder version            : 5.3
 * C/C++ source code generated on  : 08-May-2023 13:56:17
 */

/* Include Files */
#include "_coder_main_file_test_mex.h"
#include "_coder_main_file_test_api.h"

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
  (void)plhs;
  (void)prhs;
  mexAtExit(&main_file_test_atexit);
  /* Module initialization. */
  main_file_test_initialize();
  /* Dispatch the entry-point. */
  unsafe_main_file_test_mexFunction(nlhs, nrhs);
  /* Module termination. */
  main_file_test_terminate();
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
 *                int32_T nrhs
 * Return Type  : void
 */
void unsafe_main_file_test_mexFunction(int32_T nlhs, int32_T nrhs)
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  st.tls = emlrtRootTLSGlobal;
  /* Check for proper number of arguments. */
  if (nrhs != 0) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 0, 4,
                        14, "main_file_test");
  }
  if (nlhs > 0) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 14,
                        "main_file_test");
  }
  /* Call the function. */
  main_file_test_api();
}

/*
 * File trailer for _coder_main_file_test_mex.c
 *
 * [EOF]
 */
