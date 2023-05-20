/*
 * _coder_main_scanner_mex.h
 *
 * Code generation for function '_coder_main_scanner_mex'
 *
 */

#pragma once

/* Include files */
#include "main_scanner_types.h"
#include "rtwtypes.h"
#include "covrt.h"
#include "emlrt.h"
#include "mex.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function Declarations */
void main_scanner_mexFunction(main_scannerStackData *SD, int32_T nlhs,
                              mxArray *plhs[2], int32_T nrhs,
                              const mxArray *prhs[6]);

MEXFUNCTION_LINKAGE void mexFunction(int32_T nlhs, mxArray *plhs[],
                                     int32_T nrhs, const mxArray *prhs[]);

emlrtCTX mexFunctionCreateRootTLS(void);

/* End of code generation (_coder_main_scanner_mex.h) */
