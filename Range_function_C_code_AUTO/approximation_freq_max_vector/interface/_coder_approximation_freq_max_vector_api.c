/*
 * File: _coder_approximation_freq_max_vector_api.c
 *
 * MATLAB Coder version            : 3.3
 * C/C++ source code generated on  : 03-May-2023 17:47:49
 */

/* Include Files */
#include "tmwtypes.h"
#include "_coder_approximation_freq_max_vector_api.h"
#include "_coder_approximation_freq_max_vector_mex.h"

/* Variable Definitions */
emlrtCTX emlrtRootTLSGlobal = NULL;
emlrtContext emlrtContextGlobal = { true,/* bFirstTime */
  false,                               /* bInitialized */
  131450U,                             /* fVersionInfo */
  NULL,                                /* fErrorFunction */
  "approximation_freq_max_vector",     /* fFunctionName */
  NULL,                                /* fRTCallStack */
  false,                               /* bDebugMode */
  { 2045744189U, 2170104910U, 2743257031U, 4284093946U },/* fSigWrd */
  NULL                                 /* fSigMem */
};

/* Function Declarations */
static real_T b_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier
  *parentId);
static real_T (*c_emlrt_marshallIn(const mxArray *Signal, const char_T
  *identifier))[2250001];
static real_T (*d_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier
  *parentId))[2250001];
static real_T e_emlrt_marshallIn(const mxArray *src, const emlrtMsgIdentifier
  *msgId);
static real_T emlrt_marshallIn(const mxArray *Tm, const char_T *identifier);
static const mxArray *emlrt_marshallOut(const real_T u);
static real_T (*f_emlrt_marshallIn(const mxArray *src, const emlrtMsgIdentifier *
  msgId))[2250001];

/* Function Definitions */

/*
 * Arguments    : const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 * Return Type  : real_T
 */
static real_T b_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier
  *parentId)
{
  real_T y;
  y = e_emlrt_marshallIn(emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

/*
 * Arguments    : const mxArray *Signal
 *                const char_T *identifier
 * Return Type  : real_T (*)[2250001]
 */
static real_T (*c_emlrt_marshallIn(const mxArray *Signal, const char_T
  *identifier))[2250001]
{
  real_T (*y)[2250001];
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = d_emlrt_marshallIn(emlrtAlias(Signal), &thisId);
  emlrtDestroyArray(&Signal);
  return y;
}
/*
 * Arguments    : const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 * Return Type  : real_T (*)[2250001]
 */
  static real_T (*d_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier *
  parentId))[2250001]
{
  real_T (*y)[2250001];
  y = f_emlrt_marshallIn(emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

/*
 * Arguments    : const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 * Return Type  : real_T
 */
static real_T e_emlrt_marshallIn(const mxArray *src, const emlrtMsgIdentifier
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
 * Arguments    : const mxArray *Tm
 *                const char_T *identifier
 * Return Type  : real_T
 */
static real_T emlrt_marshallIn(const mxArray *Tm, const char_T *identifier)
{
  real_T y;
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = b_emlrt_marshallIn(emlrtAlias(Tm), &thisId);
  emlrtDestroyArray(&Tm);
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
 * Return Type  : real_T (*)[2250001]
 */
static real_T (*f_emlrt_marshallIn(const mxArray *src, const emlrtMsgIdentifier *
  msgId))[2250001]
{
  real_T (*ret)[2250001];
  static const int32_T dims[2] = { 1, 2250001 };

  emlrtCheckBuiltInR2012b(emlrtRootTLSGlobal, msgId, src, "double", false, 2U,
    dims);
  ret = (real_T (*)[2250001])mxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}
/*
 * Arguments    : const mxArray * const prhs[4]
 *                const mxArray *plhs[1]
 * Return Type  : void
 */
  void approximation_freq_max_vector_api(const mxArray * const prhs[4], const
  mxArray *plhs[1])
{
  real_T Tm;
  real_T Fd;
  real_T (*Signal)[2250001];
  real_T f;

  /* Marshall function inputs */
  Tm = emlrt_marshallIn(emlrtAliasP(prhs[0]), "Tm");
  Fd = emlrt_marshallIn(emlrtAliasP(prhs[1]), "Fd");
  Signal = c_emlrt_marshallIn(emlrtAlias(prhs[2]), "Signal");
  f = emlrt_marshallIn(emlrtAliasP(prhs[3]), "f");

  /* Invoke the target function */
  approximation_freq_max_vector(Tm, Fd, *Signal, &f);

  /* Marshall function outputs */
  plhs[0] = emlrt_marshallOut(f);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void approximation_freq_max_vector_atexit(void)
{
  mexFunctionCreateRootTLS();
  emlrtEnterRtStackR2012b(emlrtRootTLSGlobal);
  emlrtLeaveRtStackR2012b(emlrtRootTLSGlobal);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
  approximation_freq_max_vector_xil_terminate();
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void approximation_freq_max_vector_initialize(void)
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
void approximation_freq_max_vector_terminate(void)
{
  emlrtLeaveRtStackR2012b(emlrtRootTLSGlobal);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

/*
 * File trailer for _coder_approximation_freq_max_vector_api.c
 *
 * [EOF]
 */
