/*
 * File: _coder_tone_search_mex.c
 *
 * MATLAB Coder version            : 5.3
 * C/C++ source code generated on  : 10-May-2023 17:26:57
 */

/* Include Files */
#include "_coder_tone_search_mex.h"
#include "_coder_tone_search_api.h"

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
  mexAtExit(&tone_search_atexit);
  /* Module initialization. */
  tone_search_initialize();
  /* Dispatch the entry-point. */
  unsafe_tone_search_mexFunction(nlhs, plhs, nrhs, prhs);
  /* Module termination. */
  tone_search_terminate();
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
 *                mxArray *plhs[6]
 *                int32_T nrhs
 *                const mxArray *prhs[9]
 * Return Type  : void
 */
void unsafe_tone_search_mexFunction(int32_T nlhs, mxArray *plhs[6],
                                    int32_T nrhs, const mxArray *prhs[9])
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  const mxArray *outputs[6];
  int32_T b_nlhs;
  st.tls = emlrtRootTLSGlobal;
  /* Check for proper number of arguments. */
  if (nrhs != 9) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 9, 4,
                        11, "tone_search");
  }
  if (nlhs > 6) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 11,
                        "tone_search");
  }
  /* Call the function. */
  tone_search_api(prhs, nlhs, outputs);
  /* Copy over outputs to the caller. */
  if (nlhs < 1) {
    b_nlhs = 1;
  } else {
    b_nlhs = nlhs;
  }
  emlrtReturnArrays(b_nlhs, &plhs[0], &outputs[0]);
}

/*
 * File trailer for _coder_tone_search_mex.c
 *
 * [EOF]
 */
