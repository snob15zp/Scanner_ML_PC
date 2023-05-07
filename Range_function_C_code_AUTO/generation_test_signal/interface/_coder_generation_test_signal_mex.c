/*
 * File: _coder_generation_test_signal_mex.c
 *
 * MATLAB Coder version            : 3.3
 * C/C++ source code generated on  : 03-May-2023 17:04:01
 */

/* Include Files */
#include "_coder_generation_test_signal_api.h"
#include "_coder_generation_test_signal_mex.h"

/* Function Declarations */
static void c_generation_test_signal_mexFun(int32_T nlhs, mxArray *plhs[3],
  int32_T nrhs, const mxArray *prhs[11]);

/* Function Definitions */

/*
 * Arguments    : int32_T nlhs
 *                const mxArray *plhs[3]
 *                int32_T nrhs
 *                const mxArray *prhs[11]
 * Return Type  : void
 */
static void c_generation_test_signal_mexFun(int32_T nlhs, mxArray *plhs[3],
  int32_T nrhs, const mxArray *prhs[11])
{
  int32_T n;
  const mxArray *inputs[11];
  const mxArray *outputs[3];
  int32_T b_nlhs;

  /* Check for proper number of arguments. */
  if (nrhs != 11) {
    emlrtErrMsgIdAndTxt(emlrtRootTLSGlobal, "EMLRT:runTime:WrongNumberOfInputs",
                        5, 12, 11, 4, 22, "generation_test_signal");
  }

  if (nlhs > 3) {
    emlrtErrMsgIdAndTxt(emlrtRootTLSGlobal,
                        "EMLRT:runTime:TooManyOutputArguments", 3, 4, 22,
                        "generation_test_signal");
  }

  /* Temporary copy for mex inputs. */
  for (n = 0; n < nrhs; n++) {
    inputs[n] = prhs[n];
  }

  /* Call the function. */
  generation_test_signal_api(inputs, outputs);

  /* Copy over outputs to the caller. */
  if (nlhs < 1) {
    b_nlhs = 1;
  } else {
    b_nlhs = nlhs;
  }

  emlrtReturnArrays(b_nlhs, plhs, outputs);

  /* Module termination. */
  generation_test_signal_terminate();
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
  mexAtExit(generation_test_signal_atexit);

  /* Initialize the memory manager. */
  /* Module initialization. */
  generation_test_signal_initialize();

  /* Dispatch the entry-point. */
  c_generation_test_signal_mexFun(nlhs, plhs, nrhs, prhs);
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
 * File trailer for _coder_generation_test_signal_mex.c
 *
 * [EOF]
 */
