/*
 * File: _coder_calculation_amplitude_phase_vector_method_api.c
 *
 * MATLAB Coder version            : 3.3
 * C/C++ source code generated on  : 03-May-2023 17:58:10
 */

/* Include Files */
#include "tmwtypes.h"
#include "_coder_calculation_amplitude_phase_vector_method_api.h"
#include "_coder_calculation_amplitude_phase_vector_method_mex.h"

/* Variable Definitions */
emlrtCTX emlrtRootTLSGlobal = NULL;
emlrtContext emlrtContextGlobal = { true,/* bFirstTime */
  false,                               /* bInitialized */
  131450U,                             /* fVersionInfo */
  NULL,                                /* fErrorFunction */
  "calculation_amplitude_phase_vector_method",/* fFunctionName */
  NULL,                                /* fRTCallStack */
  false,                               /* bDebugMode */
  { 2045744189U, 2170104910U, 2743257031U, 4284093946U },/* fSigWrd */
  NULL                                 /* fSigMem */
};

/* Function Declarations */
static real_T b_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier
  *parentId);
static const mxArray *b_emlrt_marshallOut(const real_T u[2250001]);
static real_T (*c_emlrt_marshallIn(const mxArray *Signal, const char_T
  *identifier))[2250001];
static const mxArray *c_emlrt_marshallOut(const emxArray_real_T *u);
static real_T (*d_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier
  *parentId))[2250001];
static real_T (*e_emlrt_marshallIn(const mxArray *FftS, const char_T *identifier))
  [45000000];
static real_T emlrt_marshallIn(const mxArray *Tm, const char_T *identifier);
static const mxArray *emlrt_marshallOut(const real_T u);
static void emxFree_real_T(emxArray_real_T **pEmxArray);
static void emxInit_real_T(emxArray_real_T **pEmxArray, int32_T numDimensions,
  boolean_T doPush);
static real_T (*f_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier
  *parentId))[45000000];
static real_T g_emlrt_marshallIn(const mxArray *src, const emlrtMsgIdentifier
  *msgId);
static real_T (*h_emlrt_marshallIn(const mxArray *src, const emlrtMsgIdentifier *
  msgId))[2250001];
static real_T (*i_emlrt_marshallIn(const mxArray *src, const emlrtMsgIdentifier *
  msgId))[45000000];

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
  y = g_emlrt_marshallIn(emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

/*
 * Arguments    : const real_T u[2250001]
 * Return Type  : const mxArray *
 */
static const mxArray *b_emlrt_marshallOut(const real_T u[2250001])
{
  const mxArray *y;
  const mxArray *m1;
  static const int32_T iv0[2] = { 0, 0 };

  static const int32_T iv1[2] = { 1, 2250001 };

  y = NULL;
  m1 = emlrtCreateNumericArray(2, iv0, mxDOUBLE_CLASS, mxREAL);
  mxSetData((mxArray *)m1, (void *)&u[0]);
  emlrtSetDimensions((mxArray *)m1, iv1, 2);
  emlrtAssign(&y, m1);
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
 * Arguments    : const emxArray_real_T *u
 * Return Type  : const mxArray *
 */
  static const mxArray *c_emlrt_marshallOut(const emxArray_real_T *u)
{
  const mxArray *y;
  const mxArray *m2;
  static const int32_T iv2[2] = { 0, 0 };

  y = NULL;
  m2 = emlrtCreateNumericArray(2, iv2, mxDOUBLE_CLASS, mxREAL);
  mxSetData((mxArray *)m2, (void *)&u->data[0]);
  emlrtSetDimensions((mxArray *)m2, u->size, 2);
  emlrtAssign(&y, m2);
  return y;
}

/*
 * Arguments    : const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 * Return Type  : real_T (*)[2250001]
 */
static real_T (*d_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier
  *parentId))[2250001]
{
  real_T (*y)[2250001];
  y = h_emlrt_marshallIn(emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}
/*
 * Arguments    : const mxArray *FftS
 *                const char_T *identifier
 * Return Type  : real_T (*)[45000000]
 */
  static real_T (*e_emlrt_marshallIn(const mxArray *FftS, const char_T
  *identifier))[45000000]
{
  real_T (*y)[45000000];
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = f_emlrt_marshallIn(emlrtAlias(FftS), &thisId);
  emlrtDestroyArray(&FftS);
  return y;
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
 * Arguments    : const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 * Return Type  : real_T (*)[45000000]
 */
static real_T (*f_emlrt_marshallIn(const mxArray *u, const emlrtMsgIdentifier
  *parentId))[45000000]
{
  real_T (*y)[45000000];
  y = i_emlrt_marshallIn(emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}
/*
 * Arguments    : const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 * Return Type  : real_T
 */
  static real_T g_emlrt_marshallIn(const mxArray *src, const emlrtMsgIdentifier *
  msgId)
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
 * Arguments    : const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 * Return Type  : real_T (*)[2250001]
 */
static real_T (*h_emlrt_marshallIn(const mxArray *src, const emlrtMsgIdentifier *
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
 * Arguments    : const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 * Return Type  : real_T (*)[45000000]
 */
  static real_T (*i_emlrt_marshallIn(const mxArray *src, const
  emlrtMsgIdentifier *msgId))[45000000]
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
 * Arguments    : const mxArray * const prhs[7]
 *                const mxArray *plhs[4]
 * Return Type  : void
 */
void calculation_amplitude_phase_vector_method_api(const mxArray * const prhs[7],
  const mxArray *plhs[4])
{
  real_T (*RS)[2250001];
  emxArray_real_T *FftR;
  real_T Tm;
  real_T Fd;
  real_T (*Signal)[2250001];
  real_T FftL;
  real_T (*FftS)[45000000];
  real_T (*T)[2250001];
  real_T f;
  real_T a;
  real_T p;
  RS = (real_T (*)[2250001])mxMalloc(sizeof(real_T [2250001]));
  emlrtHeapReferenceStackEnterFcnR2012b(emlrtRootTLSGlobal);
  emxInit_real_T(&FftR, 2, true);

  /* Marshall function inputs */
  Tm = emlrt_marshallIn(emlrtAliasP(prhs[0]), "Tm");
  Fd = emlrt_marshallIn(emlrtAliasP(prhs[1]), "Fd");
  Signal = c_emlrt_marshallIn(emlrtAlias(prhs[2]), "Signal");
  FftL = emlrt_marshallIn(emlrtAliasP(prhs[3]), "FftL");
  FftS = e_emlrt_marshallIn(emlrtAlias(prhs[4]), "FftS");
  T = c_emlrt_marshallIn(emlrtAlias(prhs[5]), "T");
  f = emlrt_marshallIn(emlrtAliasP(prhs[6]), "f");

  /* Invoke the target function */
  calculation_amplitude_phase_vector_method(Tm, Fd, *Signal, FftL, *FftS, *T, f,
    &a, &p, *RS, FftR);

  /* Marshall function outputs */
  plhs[0] = emlrt_marshallOut(a);
  plhs[1] = emlrt_marshallOut(p);
  plhs[2] = b_emlrt_marshallOut(*RS);
  plhs[3] = c_emlrt_marshallOut(FftR);
  FftR->canFreeData = false;
  emxFree_real_T(&FftR);
  emlrtHeapReferenceStackLeaveFcnR2012b(emlrtRootTLSGlobal);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void calculation_amplitude_phase_vector_method_atexit(void)
{
  mexFunctionCreateRootTLS();
  emlrtEnterRtStackR2012b(emlrtRootTLSGlobal);
  emlrtLeaveRtStackR2012b(emlrtRootTLSGlobal);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
  calculation_amplitude_phase_vector_method_xil_terminate();
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void calculation_amplitude_phase_vector_method_initialize(void)
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
void calculation_amplitude_phase_vector_method_terminate(void)
{
  emlrtLeaveRtStackR2012b(emlrtRootTLSGlobal);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

/*
 * File trailer for _coder_calculation_amplitude_phase_vector_method_api.c
 *
 * [EOF]
 */
