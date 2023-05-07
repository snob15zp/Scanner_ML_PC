/*
 * File: _coder_calculation_amplitude_phase_vector_method_mex.c
 *
 * MATLAB Coder version            : 3.3
 * C/C++ source code generated on  : 03-May-2023 17:58:10
 */

/* Include Files */
#include "_coder_calculation_amplitude_phase_vector_method_api.h"
#include "_coder_calculation_amplitude_phase_vector_method_mex.h"

/* Function Declarations */
static void c_calculation_amplitude_phase_v(int32_T nlhs, mxArray *plhs[4],
  int32_T nrhs, const mxArray *prhs[7]);

/* Function Definitions */

/*
 * Arguments    : int32_T nlhs
 *                const mxArray *plhs[4]
 *                int32_T nrhs
 *                const mxArray *prhs[7]
 * Return Type  : void
 */
static void c_calculation_amplitude_phase_v(int32_T nlhs, mxArray *plhs[4],
  int32_T nrhs, const mxArray *prhs[7])
{
  int32_T n;
  const mxArray *inputs[7];
  const mxArray *outputs[4];
  int32_T b_nlhs;

  /* Check for proper number of arguments. */
  if (nrhs != 7) {
    emlrtErrMsgIdAndTxt(emlrtRootTLSGlobal, "EMLRT:runTime:WrongNumberOfInputs",
                        5, 12, 7, 4, 41,
                        "calculation_amplitude_phase_vector_method");
  }

  if (nlhs > 4) {
    emlrtErrMsgIdAndTxt(emlrtRootTLSGlobal,
                        "EMLRT:runTime:TooManyOutputArguments", 3, 4, 41,
                        "calculation_amplitude_phase_vector_method");
  }

  /* Temporary copy for mex inputs. */
  for (n = 0; n < nrhs; n++) {
    inputs[n] = prhs[n];
  }

  /* Call the function. */
  calculation_amplitude_phase_vector_method_api(inputs, outputs);

  /* Copy over outputs to the caller. */
  if (nlhs < 1) {
    b_nlhs = 1;
  } else {
    b_nlhs = nlhs;
  }

  emlrtReturnArrays(b_nlhs, plhs, outputs);

  /* Module termination. */
  calculation_amplitude_phase_vector_method_terminate();
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
  mexAtExit(calculation_amplitude_phase_vector_method_atexit);

  /* Initialize the memory manager. */
  /* Module initialization. */
  calculation_amplitude_phase_vector_method_initialize();

  /* Dispatch the entry-point. */
  c_calculation_amplitude_phase_v(nlhs, plhs, nrhs, prhs);
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
 * File trailer for _coder_calculation_amplitude_phase_vector_method_mex.c
 *
 * [EOF]
 */
