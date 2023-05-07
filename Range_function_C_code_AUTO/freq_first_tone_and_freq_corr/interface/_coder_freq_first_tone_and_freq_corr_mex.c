/*
 * File: _coder_freq_first_tone_and_freq_corr_mex.c
 *
 * MATLAB Coder version            : 3.3
 * C/C++ source code generated on  : 03-May-2023 17:42:44
 */

/* Include Files */
#include "_coder_freq_first_tone_and_freq_corr_api.h"
#include "_coder_freq_first_tone_and_freq_corr_mex.h"

/* Function Declarations */
static void c_freq_first_tone_and_freq_corr(int32_T nlhs, mxArray *plhs[1],
  int32_T nrhs, const mxArray *prhs[3]);

/* Function Definitions */

/*
 * Arguments    : int32_T nlhs
 *                const mxArray *plhs[1]
 *                int32_T nrhs
 *                const mxArray *prhs[3]
 * Return Type  : void
 */
static void c_freq_first_tone_and_freq_corr(int32_T nlhs, mxArray *plhs[1],
  int32_T nrhs, const mxArray *prhs[3])
{
  int32_T n;
  const mxArray *inputs[3];
  const mxArray *outputs[1];
  int32_T b_nlhs;

  /* Check for proper number of arguments. */
  if (nrhs != 3) {
    emlrtErrMsgIdAndTxt(emlrtRootTLSGlobal, "EMLRT:runTime:WrongNumberOfInputs",
                        5, 12, 3, 4, 29, "freq_first_tone_and_freq_corr");
  }

  if (nlhs > 1) {
    emlrtErrMsgIdAndTxt(emlrtRootTLSGlobal,
                        "EMLRT:runTime:TooManyOutputArguments", 3, 4, 29,
                        "freq_first_tone_and_freq_corr");
  }

  /* Temporary copy for mex inputs. */
  for (n = 0; n < nrhs; n++) {
    inputs[n] = prhs[n];
  }

  /* Call the function. */
  freq_first_tone_and_freq_corr_api(inputs, outputs);

  /* Copy over outputs to the caller. */
  if (nlhs < 1) {
    b_nlhs = 1;
  } else {
    b_nlhs = nlhs;
  }

  emlrtReturnArrays(b_nlhs, plhs, outputs);

  /* Module termination. */
  freq_first_tone_and_freq_corr_terminate();
}

/*
 * Arguments    : int32_T nlhs
 *                const mxArray * const plhs[]
 *                int32_T nrhs
 *                const mxArray * const prhs[]
 * Return Type  : void
 */
void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs, const mxArray
                 *prhs[])
{
  mexAtExit(freq_first_tone_and_freq_corr_atexit);

  /* Initialize the memory manager. */
  /* Module initialization. */
  freq_first_tone_and_freq_corr_initialize();

  /* Dispatch the entry-point. */
  c_freq_first_tone_and_freq_corr(nlhs, plhs, nrhs, prhs);
}

/*
 * Arguments    : void
 * Return Type  : emlrtCTX
 */
emlrtCTX mexFunctionCreateRootTLS(void)
{
  emlrtCreateRootTLS(&emlrtRootTLSGlobal, &emlrtContextGlobal, NULL, 1);
  return emlrtRootTLSGlobal;
}

/*
 * File trailer for _coder_freq_first_tone_and_freq_corr_mex.c
 *
 * [EOF]
 */
