/*
 * File: _coder_generation_test_signal_api.c
 *
 * MATLAB Coder version            : 3.3
 * C/C++ source code generated on  : 03-May-2023 17:04:01
 */

/* Include Files */
#include "tmwtypes.h"
#include "_coder_generation_test_signal_api.h"
#include "_coder_generation_test_signal_mex.h"

/* Variable Definitions */
emlrtCTX emlrtRootTLSGlobal = NULL;
emlrtContext emlrtContextGlobal = { true,/* bFirstTime */
  false,                               /* bInitialized */
  131450U,                             /* fVersionInfo */
  NULL,                                /* fErrorFunction */
  "generation_test_signal",            /* fFunctionName */
  NULL,                                /* fRTCallStack */
  false,                               /* bDebugMode */
  { 2045744189U, 2170104910U, 2743257031U, 4284093946U },/* fSigWrd */
  NULL                                 /* fSigMem */
};

/* Function Declarations */
static real_T b_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier
  *parentId);
static const mxArray *b_emlrt_marshallOut(const real_T u);
static real_T c_emlrt_marshallIn(const mxArray *src, const emlrtMsgIdentifier
  *msgId);
static real_T emlrt_marshallIn(const mxArray *Tm, const char_T *identifier);
static const mxArray *emlrt_marshallOut(const emxArray_real_T *u);
static void emxFree_real_T(emxArray_real_T **pEmxArray);
static void emxInit_real_T(emxArray_real_T **pEmxArray, int32_T numDimensions,
  boolean_T doPush);

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
  y = c_emlrt_marshallIn(emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

/*
 * Arguments    : const real_T u
 * Return Type  : const mxArray *
 */
static const mxArray *b_emlrt_marshallOut(const real_T u)
{
  const mxArray *y;
  const mxArray *m1;
  y = NULL;
  m1 = emlrtCreateDoubleScalar(u);
  emlrtAssign(&y, m1);
  return y;
}

/*
 * Arguments    : const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 * Return Type  : real_T
 */
static real_T c_emlrt_marshallIn(const mxArray *src, const emlrtMsgIdentifier
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
 * Arguments    : const emxArray_real_T *u
 * Return Type  : const mxArray *
 */
static const mxArray *emlrt_marshallOut(const emxArray_real_T *u)
{
  const mxArray *y;
  const mxArray *m0;
  static const int32_T iv0[2] = { 0, 0 };

  y = NULL;
  m0 = emlrtCreateNumericArray(2, iv0, mxDOUBLE_CLASS, mxREAL);
  mxSetData((mxArray *)m0, (void *)&u->data[0]);
  emlrtSetDimensions((mxArray *)m0, u->size, 2);
  emlrtAssign(&y, m0);
  return y;
}

/*
 * Arguments    : emxArray_real_T **pEmxArray
 * Return Type  : void
 */
static void emxFree_real_T(emxArray_real_T **pEmxArray)
{
  if (*pEmxArray != (emxArray_real_T *)NULL) {
    if (((*pEmxArray)->data != (real_T *)NULL) && (*pEmxArray)->canFreeData) {
      emlrtFreeMex((void *)(*pEmxArray)->data);
    }

    emlrtFreeMex((void *)(*pEmxArray)->size);
    emlrtFreeMex((void *)*pEmxArray);
    *pEmxArray = (emxArray_real_T *)NULL;
  }
}

/*
 * Arguments    : emxArray_real_T **pEmxArray
 *                int32_T numDimensions
 *                boolean_T doPush
 * Return Type  : void
 */
static void emxInit_real_T(emxArray_real_T **pEmxArray, int32_T numDimensions,
  boolean_T doPush)
{
  emxArray_real_T *emxArray;
  int32_T i;
  *pEmxArray = (emxArray_real_T *)emlrtMallocMex(sizeof(emxArray_real_T));
  if (doPush) {
    emlrtPushHeapReferenceStackR2012b(emlrtRootTLSGlobal, (void *)pEmxArray,
      (void (*)(void *))emxFree_real_T);
  }

  emxArray = *pEmxArray;
  emxArray->data = (real_T *)NULL;
  emxArray->numDimensions = numDimensions;
  emxArray->size = (int32_T *)emlrtMallocMex((uint32_T)(sizeof(int32_T)
    * numDimensions));
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < numDimensions; i++) {
    emxArray->size[i] = 0;
  }
}

/*
 * Arguments    : const mxArray * const prhs[11]
 *                const mxArray *plhs[3]
 * Return Type  : void
 */
void generation_test_signal_api(const mxArray * const prhs[11], const mxArray
  *plhs[3])
{
  emxArray_real_T *Signal;
  emxArray_real_T *T;
  real_T Tm;
  real_T Fd;
  real_T mz;
  real_T Ak;
  real_T A1;
  real_T A2;
  real_T F1;
  real_T F2;
  real_T P1;
  real_T P2;
  real_T An;
  real_T FftL;
  emlrtHeapReferenceStackEnterFcnR2012b(emlrtRootTLSGlobal);
  emxInit_real_T(&Signal, 2, true);
  emxInit_real_T(&T, 2, true);

  /* Marshall function inputs */
  Tm = emlrt_marshallIn(emlrtAliasP(prhs[0]), "Tm");
  Fd = emlrt_marshallIn(emlrtAliasP(prhs[1]), "Fd");
  mz = emlrt_marshallIn(emlrtAliasP(prhs[2]), "mz");
  Ak = emlrt_marshallIn(emlrtAliasP(prhs[3]), "Ak");
  A1 = emlrt_marshallIn(emlrtAliasP(prhs[4]), "A1");
  A2 = emlrt_marshallIn(emlrtAliasP(prhs[5]), "A2");
  F1 = emlrt_marshallIn(emlrtAliasP(prhs[6]), "F1");
  F2 = emlrt_marshallIn(emlrtAliasP(prhs[7]), "F2");
  P1 = emlrt_marshallIn(emlrtAliasP(prhs[8]), "P1");
  P2 = emlrt_marshallIn(emlrtAliasP(prhs[9]), "P2");
  An = emlrt_marshallIn(emlrtAliasP(prhs[10]), "An");

  /* Invoke the target function */
  generation_test_signal(Tm, Fd, mz, Ak, A1, A2, F1, F2, P1, P2, An, Signal, T,
    &FftL);

  /* Marshall function outputs */
  plhs[0] = emlrt_marshallOut(Signal);
  plhs[1] = emlrt_marshallOut(T);
  plhs[2] = b_emlrt_marshallOut(FftL);
  T->canFreeData = false;
  emxFree_real_T(&T);
  Signal->canFreeData = false;
  emxFree_real_T(&Signal);
  emlrtHeapReferenceStackLeaveFcnR2012b(emlrtRootTLSGlobal);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void generation_test_signal_atexit(void)
{
  mexFunctionCreateRootTLS();
  emlrtEnterRtStackR2012b(emlrtRootTLSGlobal);
  emlrtLeaveRtStackR2012b(emlrtRootTLSGlobal);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
  generation_test_signal_xil_terminate();
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void generation_test_signal_initialize(void)
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
void generation_test_signal_terminate(void)
{
  emlrtLeaveRtStackR2012b(emlrtRootTLSGlobal);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

/*
 * File trailer for _coder_generation_test_signal_api.c
 *
 * [EOF]
 */
