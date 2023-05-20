/*
 * tone_search.h
 *
 * Code generation for function 'tone_search'
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
void tone_search(main_scannerStackData *SD, const emlrtStack *sp, real_T Tm,
                 real_T Fd, real_T mz, real_T FftL, const real_T T[250001],
                 real_T Signal[250001], real_T *a, real_T *f, real_T *p,
                 emxArray_real_T *FftS, real_T *Am);

/* End of code generation (tone_search.h) */
