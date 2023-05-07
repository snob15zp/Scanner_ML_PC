/*
 * File: _coder_freq_first_tone_and_freq_corr_api.c
 *
 * MATLAB Coder version            : 3.3
 * C/C++ source code generated on  : 03-May-2023 17:42:44
 */

/* Include Files */
#include "tmwtypes.h"
#include "_coder_freq_first_tone_and_freq_corr_api.h"
#include "_coder_freq_first_tone_and_freq_corr_mex.h"

/* Variable Definitions */
emlrtCTX emlrtRootTLSGlobal = NULL;
emlrtContext emlrtContextGlobal = { true,/* bFirstTime */
  false,                               /* bInitialized */
  131450U,                             /* fVersionInfo */
  NULL,                                /* fErrorFunction */
  "freq_first_tone_and_freq_corr",     /* fFunctionName */
  NULL,                                /* fRTCallStack */
  false,                               /* bDebugMode */
  { 2045744189U, 2170104910U, 2743257031U, 4284093946U },/* fSigWrd */
  NULL                                 /* fSigMem */
};

/* Function Declarations */
static real_T (*b_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier
  *parentId))[45000000];
static real_T c_emlrt_marshallIn(const mxArray *FftL, const char_T *identifier);
static real_T d_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier
  *parentId);
static real_T (*e_emlrt_marshallIn(const mxArray *src, const emlrtMsgIdentifier *
  msgId))[45000000];
static real_T (*emlrt_marshallIn(const mxArray *FftS, const char_T *identifier))
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
 * Arguments    : const mxArray *FftL
 *                const char_T *identifier
 * Return Type  : real_T
 */
  static real_T c_emlrt_marshallIn(const mxArray *FftL, const char_T *identifier)
{
  real_T y;
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = d_emlrt_marshallIn(emlrtAlias(FftL), &thisId);
  emlrtDestroyArray(&FftL);
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
 * Arguments    : const mxArray *FftS
 *                const char_T *identifier
 * Return Type  : real_T (*)[45000000]
 */
  static real_T (*emlrt_marshallIn(const mxArray *FftS, const char_T *identifier))
  [45000000]
{
  real_T (*y)[45000000];
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = b_emlrt_marshallIn(emlrtAlias(FftS), &thisId);
  emlrtDestroyArray(&FftS);
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
 *                const mxArray *plhs[1]
 * Return Type  : void
 */
void freq_first_tone_and_freq_corr_api(const mxArray * const prhs[3], const
  mxArray *plhs[1])
{
  real_T (*FftS)[45000000];
  real_T FftL;
  real_T Fd;

  /* Marshall function inputs */
  FftS = emlrt_marshallIn(emlrtAlias(prhs[0]), "FftS");
  FftL = c_emlrt_marshallIn(emlrtAliasP(prhs[1]), "FftL");
  Fd = c_emlrt_marshallIn(emlrtAliasP(prhs[2]), "Fd");

  /* Invoke the target function */
  FftL = freq_first_tone_and_freq_corr(*FftS, FftL, Fd);

  /* Marshall function outputs */
  plhs[0] = emlrt_marshallOut(FftL);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void freq_first_tone_and_freq_corr_atexit(void)
{
  mexFunctionCreateRootTLS();
  emlrtEnterRtStackR2012b(emlrtRootTLSGlobal);
  emlrtLeaveRtStackR2012b(emlrtRootTLSGlobal);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
  freq_first_tone_and_freq_corr_xil_terminate();
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void freq_first_tone_and_freq_corr_initialize(void)
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
void freq_first_tone_and_freq_corr_terminate(void)
{
  emlrtLeaveRtStackR2012b(emlrtRootTLSGlobal);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

/*
 * File trailer for _coder_freq_first_tone_and_freq_corr_api.c
 *
 * [EOF]
 */
