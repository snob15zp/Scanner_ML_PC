/*
 * main_scanner.h
 *
 * Code generation for function 'main_scanner'
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
void main_scanner(main_scannerStackData *SD, const emlrtStack *sp, real_T Tm,
                  real_T Fd, real_T mz, real_T FftL, const real_T T[250001],
                  real_T Signal[250001], real_T Out[300],
                  emxArray_real_T *FftS);

/* End of code generation (main_scanner.h) */
