/*
 * main_scanner_mexutil.h
 *
 * Code generation for function 'main_scanner_mexutil'
 *
 */

#pragma once

/* Include files */
#include "rtwtypes.h"
#include "covrt.h"
#include "emlrt.h"
#include "mex.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function Declarations */
real_T b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                          const emlrtMsgIdentifier *parentId);

real_T emlrt_marshallIn(const emlrtStack *sp,
                        const mxArray *a__output_of_length_,
                        const char_T *identifier);

real_T g_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                          const emlrtMsgIdentifier *msgId);

/* End of code generation (main_scanner_mexutil.h) */
