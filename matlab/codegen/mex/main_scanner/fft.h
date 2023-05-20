/*
 * fft.h
 *
 * Code generation for function 'fft'
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
void fft(const emlrtStack *sp, const real_T x[250001], real_T varargin_1,
         emxArray_creal_T *y);

/* End of code generation (fft.h) */
