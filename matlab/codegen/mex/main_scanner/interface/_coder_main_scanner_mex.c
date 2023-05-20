/*
 * _coder_main_scanner_mex.c
 *
 * Code generation for function '_coder_main_scanner_mex'
 *
 */

/* Include files */
#include "_coder_main_scanner_mex.h"
#include "_coder_main_scanner_api.h"
#include "main_scanner_data.h"
#include "main_scanner_initialize.h"
#include "main_scanner_terminate.h"
#include "main_scanner_types.h"
#include "rt_nonfinite.h"

/* Function Definitions */
void main_scanner_mexFunction(main_scannerStackData *SD, int32_T nlhs,
                              mxArray *plhs[2], int32_T nrhs,
                              const mxArray *prhs[6])
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  const mxArray *outputs[2];
  int32_T nOutputs;
  st.tls = emlrtRootTLSGlobal;
  /* Check for proper number of arguments. */
  if (nrhs != 6) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:WrongNumberOfInputs", 5, 12, 6, 4,
                        12, "main_scanner");
  }
  if (nlhs > 2) {
    emlrtErrMsgIdAndTxt(&st, "EMLRT:runTime:TooManyOutputArguments", 3, 4, 12,
                        "main_scanner");
  }
  /* Call the function. */
  main_scanner_api(SD, prhs, nlhs, outputs);
  /* Copy over outputs to the caller. */
  if (nlhs < 1) {
    nOutputs = 1;
  } else {
    nOutputs = nlhs;
  }
  emlrtReturnArrays(nOutputs, &plhs[0], &outputs[0]);
}

void mexFunction(int32_T nlhs, mxArray *plhs[], int32_T nrhs,
                 const mxArray *prhs[])
{
  main_scannerStackData *main_scannerStackDataGlobal = NULL;
  main_scannerStackDataGlobal = (main_scannerStackData *)emlrtMxCalloc(
      (size_t)1, (size_t)1U * sizeof(main_scannerStackData));
  mexAtExit(&main_scanner_atexit);
  /* Module initialization. */
  main_scanner_initialize();
  /* Dispatch the entry-point. */
  main_scanner_mexFunction(main_scannerStackDataGlobal, nlhs, plhs, nrhs, prhs);
  /* Module termination. */
  main_scanner_terminate();
  emlrtMxFree(main_scannerStackDataGlobal);
}

emlrtCTX mexFunctionCreateRootTLS(void)
{
  emlrtCreateRootTLSR2021a(&emlrtRootTLSGlobal, &emlrtContextGlobal, NULL, 1,
                           NULL);
  return emlrtRootTLSGlobal;
}

/* End of code generation (_coder_main_scanner_mex.c) */
