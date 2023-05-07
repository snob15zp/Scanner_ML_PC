/*
 * File: _coder_calculation_second_tone_freq_api.c
 *
 * MATLAB Coder version            : 3.3
 * C/C++ source code generated on  : 03-May-2023 17:35:58
 */

/* Include Files */
#include "tmwtypes.h"
#include "_coder_calculation_second_tone_freq_api.h"
#include "_coder_calculation_second_tone_freq_mex.h"

/* Variable Definitions */
emlrtCTX emlrtRootTLSGlobal = NULL;
emlrtContext emlrtContextGlobal = { true,/* bFirstTime */
  false,                               /* bInitialized */
  131450U,                             /* fVersionInfo */
  NULL,                                /* fErrorFunction */
  "calculation_second_tone_freq",      /* fFunctionName */
  NULL,                                /* fRTCallStack */
  false,                               /* bDebugMode */
  { 2045744189U, 2170104910U, 2743257031U, 4284093946U },/* fSigWrd */
  NULL                                 /* fSigMem */
};

/* Function Declarations */
static real_T (*b_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier
  *parentId))[45000000];
static real_T c_emlrt_marshallIn(const mxArray *Fd, const char_T *identifier);
static real_T d_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier
  *parentId);
static real_T (*e_emlrt_marshallIn(const mxArray *src, const emlrtMsgIdentifier *
  msgId))[45000000];
static real_T (*emlrt_marshallIn(const mxArray *FftR, const char_T *identifier))
  [45000000];
static const mxArray *emlrt_marshallOut(const real_T u);
static real_T f_emlrt_marshallIn(const mxArray *src, const emlrtMsgIdentifier
  *msgId);

/* Function Definitions */

/*
 * Arguments    : const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 * Return Type  : real_T (*)[45000000]
 */
static real_T (*b_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier
  *parentId))[45000000]
{
  real_T (*y)[45000000];
  y = e_emlrt_marshallIn(emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}
/*
 * Arguments    : const mxArray *Fd
 *                const char_T *identifier
 * Return Type  : real_T
 */
  static real_T c_emlrt_marshallIn(const mxArray *Fd, const char_T *identifier)
{
  real_T y;
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = d_emlrt_marshallIn(emlrtAlias(Fd), &thisId);
  emlrtDestroyArray(&Fd);
  return y;
}

/*
 * Arguments    : const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 * Return Type  : real_T
 */
static real_T d_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier
  *parentId)
{
  real_T y;
  y = f_emlrt_marshallIn(emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

/*
 * Arguments    : const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 * Return Type  : real_T (*)[45000000]
 */
static real_T (*e_emlrt_marshallIn(const mxArray *src, const emlrtMsgIdentifier *
  msgId))[45000000]
{
  real_T (*ret)[45000000];
  static const int32_T dims[2] = { 1, 45000000 };

  emlrtCheckBuiltInR2012b(emlrtRootTLSGlobal, msgId, src, "double", false, 2U,
    dims);
  ret = (real_T (*)[45000000])mxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}
/*
 * Arguments    : const mxArray *FftR
 *                const char_T *identifier
 * Return Type  : real_T (*)[45000000]
 */
  static real_T (*emlrt_marshallIn(const mxArray *FftR, const char_T *identifier))
  [45000000]
{
  real_T (*y)[45000000];
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = b_emlrt_marshallIn(emlrtAlias(FftR), &thisId);
  emlrtDestroyArray(&FftR);
  return y;
}

/*
 * Arguments    : const real_T u
 * Return Type  : const mxArray *
 */
static const mxArray *emlrt_marshallOut(const real_T u)
{
  const mxArray *y;
  const mxArray *m0;
  y = NULL;
  m0 = emlrtCreateDoubleScalar(u);
  emlrtAssign(&y, m0);
  return y;
}

/*
 * Arguments    : const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 * Return Type  : real_T
 */
static real_T f_emlrt_marshallIn(const mxArray *src, const emlrtMsgIdentifier
  *msgId)
{
  real_T ret;
  static const int32_T dims = 0;
  emlrtCheckBuiltInR2012b(emlrtRootTLSGlobal, msgId, src, "double", false, 0U,
    &dims);
  ret = *(real_T *)mxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

/*
 * Arguments    : const mxArray * const prhs[3]
 *                const mxArray *plhs[3]
 * Return Type  : void
 */
void calculation_second_tone_freq_api(const mxArray * const prhs[3], const
  mxArray *plhs[3])
{
  real_T (*FftR)[45000000];
  real_T Fd;
  real_T FftL;
  real_T fv;
  real_T Am;
  real_T im;

  /* Marshall function inputs */
  FftR = emlrt_marshallIn(emlrtAlias(prhs[0]), "FftR");
  Fd = c_emlrt_marshallIn(emlrtAliasP(prhs[1]), "Fd");
  FftL = c_emlrt_marshallIn(emlrtAliasP(prhs[2]), "FftL");

  /* Invoke the target function */
  calculation_second_tone_freq(*FftR, Fd, FftL, &fv, &Am, &im);

  /* Marshall function outputs */
  plhs[0] = emlrt_marshallOut(fv);
  plhs[1] = emlrt_marshallOut(Am);
  plhs[2] = emlrt_marshallOut(im);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void calculation_second_tone_freq_atexit(void)
{
  mexFunctionCreateRootTLS();
  emlrtEnterRtStackR2012b(emlrtRootTLSGlobal);
  emlrtLeaveRtStackR2012b(emlrtRootTLSGlobal);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
  calculation_second_tone_freq_xil_terminate();
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void calculation_second_tone_freq_initialize(void)
{
  mexFunctionCreateRootTLS();
  emlrtClearAllocCountR2012b(emlrtRootTLSGlobal, false, 0U, 0);
  emlrtEnterRtStackR2012b(emlrtRootTLSGlobal);
  emlrtFirstTimeR2012b(emlrtRootTLSGlobal);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void calculation_second_tone_freq_terminate(void)
{
  emlrtLeaveRtStackR2012b(emlrtRootTLSGlobal);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

/*
 * File trailer for _coder_calculation_second_tone_freq_api.c
 *
 * [EOF]
 */
