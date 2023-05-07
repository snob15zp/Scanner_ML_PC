/*
 * File: _coder_calculation_second_tone_freq_mex.c
 *
 * MATLAB Coder version            : 3.3
 * C/C++ source code generated on  : 03-May-2023 17:35:58
 */

/* Include Files */
#include "_coder_calculation_second_tone_freq_api.h"
#include "_coder_calculation_second_tone_freq_mex.h"

/* Function Declarations */
static void c_calculation_second_tone_freq_(int32_T nlhs, mxArray *plhs[3],
  int32_T nrhs, const mxArray *prhs[3]);

/* Function Definitions */

/*
 * Arguments    : int32_T nlhs
 *                const mxArray *plhs[3]
 *                int32_T nrhs
 *                const mxArray *prhs[3]
 * Return Type  : void
 */
static void c_calculation_second_tone_freq_(int32_T nlhs, mxArray *plhs[3],
  int32_T nrhs, const mxArray *prhs[3])
{
  int32_T n;
  const mxArray *inputs[3];
  const mxArray *outputs[3];
  int32_T b_nlhs;

  /* Check for proper number of arguments. */
  if (nrhs != 3) {
    emlrtErrMsgIdAndTxt(emlrtRootTLSGlobal, "EMLRT:runTime:WrongNumberOfInputs",
                        5, 12, 3, 4, 28, "calculation_second_tone_freq");
  }

  if (nlhs > 3) {
    emlrtErrMsgIdAndTxt(emlrtRootTLSGlobal,
                        "EMLRT:runTime:TooManyOutputArguments", 3, 4, 28,
                        "calculation_second_tone_freq");
  }

  /* Temporary copy for mex inputs. */
  for (n = 0; n < nrhs; n++) {
    inputs[n] = prhs[n];
  }

  /* Call the function. */
  calculation_second_tone_freq_api(inputs, outputs);

  /* Copy over outputs to the caller. */
  if (nlhs < 1) {
    b_nlhs = 1;
  } else {
    b_nlhs = nlhs;
  }

  emlrtReturnArrays(b_nlhs, plhs, outputs);

  /* Module termination. */
  calculation_second_tone_freq_terminate();
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
  mexAtExit(calculation_second_tone_freq_atexit);

  /* Initialize the memory manager. */
  /* Module initialization. */
  calculation_second_tone_freq_initialize();

  /* Dispatch the entry-point. */
  c_calculation_second_tone_freq_(nlhs, plhs, nrhs, prhs);
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
 * File trailer for _coder_calculation_second_tone_freq_mex.c
 *
 * [EOF]
 */
