/*
 * File: _coder_tone_search_api.c
 *
 * MATLAB Coder version            : 5.3
 * C/C++ source code generated on  : 10-May-2023 17:26:57
 */

/* Include Files */
#include "_coder_tone_search_api.h"
#include "_coder_tone_search_mex.h"

/* Variable Definitions */
emlrtCTX emlrtRootTLSGlobal = NULL;

emlrtContext emlrtContextGlobal = {
    true,                                                 /* bFirstTime */
    false,                                                /* bInitialized */
    131611U,                                              /* fVersionInfo */
    NULL,                                                 /* fErrorFunction */
    "tone_search",                                        /* fFunctionName */
    NULL,                                                 /* fRTCallStack */
    false,                                                /* bDebugMode */
    {2045744189U, 2170104910U, 2743257031U, 4284093946U}, /* fSigWrd */
    NULL                                                  /* fSigMem */
};

/* Function Declarations */
static real_T b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                 const emlrtMsgIdentifier *parentId);

static const mxArray *b_emlrt_marshallOut(const emxArray_real_T *u);

static real_T (*c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *T,
                                   const char_T *identifier))[2500001];

static const mxArray *c_emlrt_marshallOut(const real_T u);

static real_T (
    *d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                        const emlrtMsgIdentifier *parentId))[2500001];

static real_T e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                 const emlrtMsgIdentifier *msgId);

static real_T emlrt_marshallIn(const emlrtStack *sp, const mxArray *Tm,
                               const char_T *identifier);

static void emlrt_marshallOut(const real_T u[2500001], const mxArray *y);

static void emxFree_real_T(const emlrtStack *sp, emxArray_real_T **pEmxArray);

static void emxInit_real_T(const emlrtStack *sp, emxArray_real_T **pEmxArray);

static real_T (*f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                   const emlrtMsgIdentifier *msgId))[2500001];

/* Function Definitions */
/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 * Return Type  : real_T
 */
static real_T b_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                 const emlrtMsgIdentifier *parentId)
{
  real_T y;
  y = e_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

/*
 * Arguments    : const emxArray_real_T *u
 * Return Type  : const mxArray *
 */
static const mxArray *b_emlrt_marshallOut(const emxArray_real_T *u)
{
  static const int32_T iv[2] = {0, 0};
  const mxArray *m;
  const mxArray *y;
  const real_T *u_data;
  u_data = u->data;
  y = NULL;
  m = emlrtCreateNumericArray(2, (const void *)&iv[0], mxDOUBLE_CLASS, mxREAL);
  emlrtMxSetData((mxArray *)m, (void *)&u_data[0]);
  emlrtSetDimensions((mxArray *)m, &u->size[0], 2);
  emlrtAssign(&y, m);
  return y;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *T
 *                const char_T *identifier
 * Return Type  : real_T (*)[2500001]
 */
static real_T (*c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *T,
                                   const char_T *identifier))[2500001]
{
  emlrtMsgIdentifier thisId;
  real_T(*y)[2500001];
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = d_emlrt_marshallIn(sp, emlrtAlias(T), &thisId);
  emlrtDestroyArray(&T);
  return y;
}

/*
 * Arguments    : const real_T u
 * Return Type  : const mxArray *
 */
static const mxArray *c_emlrt_marshallOut(const real_T u)
{
  const mxArray *m;
  const mxArray *y;
  y = NULL;
  m = emlrtCreateDoubleScalar(u);
  emlrtAssign(&y, m);
  return y;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *u
 *                const emlrtMsgIdentifier *parentId
 * Return Type  : real_T (*)[2500001]
 */
static real_T (*d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                   const emlrtMsgIdentifier *parentId))[2500001]
{
  real_T(*y)[2500001];
  y = f_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 * Return Type  : real_T
 */
static real_T e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                 const emlrtMsgIdentifier *msgId)
{
  static const int32_T dims = 0;
  real_T ret;
  emlrtCheckBuiltInR2012b((emlrtCTX)sp, msgId, src, (const char_T *)"double",
                          false, 0U, (void *)&dims);
  ret = *(real_T *)emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *Tm
 *                const char_T *identifier
 * Return Type  : real_T
 */
static real_T emlrt_marshallIn(const emlrtStack *sp, const mxArray *Tm,
                               const char_T *identifier)
{
  emlrtMsgIdentifier thisId;
  real_T y;
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = b_emlrt_marshallIn(sp, emlrtAlias(Tm), &thisId);
  emlrtDestroyArray(&Tm);
  return y;
}

/*
 * Arguments    : const real_T u[2500001]
 *                const mxArray *y
 * Return Type  : void
 */
static void emlrt_marshallOut(const real_T u[2500001], const mxArray *y)
{
  static const int32_T iv[2] = {1, 2500001};
  emlrtMxSetData((mxArray *)y, (void *)&u[0]);
  emlrtSetDimensions((mxArray *)y, &iv[0], 2);
}

/*
 * Arguments    : const emlrtStack *sp
 *                emxArray_real_T **pEmxArray
 * Return Type  : void
 */
static void emxFree_real_T(const emlrtStack *sp, emxArray_real_T **pEmxArray)
{
  if (*pEmxArray != (emxArray_real_T *)NULL) {
    if (((*pEmxArray)->data != (real_T *)NULL) && (*pEmxArray)->canFreeData) {
      emlrtFreeMex((*pEmxArray)->data);
    }
    emlrtFreeMex((*pEmxArray)->size);
    emlrtRemoveHeapReference((emlrtCTX)sp, (void *)pEmxArray);
    emlrtFreeEmxArray(*pEmxArray);
    *pEmxArray = (emxArray_real_T *)NULL;
  }
}

/*
 * Arguments    : const emlrtStack *sp
 *                emxArray_real_T **pEmxArray
 * Return Type  : void
 */
static void emxInit_real_T(const emlrtStack *sp, emxArray_real_T **pEmxArray)
{
  emxArray_real_T *emxArray;
  int32_T i;
  *pEmxArray = (emxArray_real_T *)emlrtMallocEmxArray(sizeof(emxArray_real_T));
  emlrtPushHeapReferenceStackEmxArray((emlrtCTX)sp, true, (void *)pEmxArray,
                                      (void *)&emxFree_real_T, NULL, NULL,
                                      NULL);
  emxArray = *pEmxArray;
  emxArray->data = (real_T *)NULL;
  emxArray->numDimensions = 2;
  emxArray->size = (int32_T *)emlrtMallocMex(sizeof(int32_T) * 2U);
  emxArray->allocatedSize = 0;
  emxArray->canFreeData = true;
  for (i = 0; i < 2; i++) {
    emxArray->size[i] = 0;
  }
}

/*
 * Arguments    : const emlrtStack *sp
 *                const mxArray *src
 *                const emlrtMsgIdentifier *msgId
 * Return Type  : real_T (*)[2500001]
 */
static real_T (*f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                   const emlrtMsgIdentifier *msgId))[2500001]
{
  static const int32_T dims[2] = {1, 2500001};
  real_T(*ret)[2500001];
  emlrtCheckBuiltInR2012b((emlrtCTX)sp, msgId, src, (const char_T *)"double",
                          false, 2U, (void *)&dims[0]);
  ret = (real_T(*)[2500001])emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

/*
 * Arguments    : const mxArray * const prhs[9]
 *                int32_T nlhs
 *                const mxArray *plhs[6]
 * Return Type  : void
 */
void tone_search_api(const mxArray *const prhs[9], int32_T nlhs,
                     const mxArray *plhs[6])
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  emxArray_real_T *FftS;
  const mxArray *prhs_copy_idx_0;
  const mxArray *prhs_copy_idx_1;
  const mxArray *prhs_copy_idx_2;
  const mxArray *prhs_copy_idx_3;
  const mxArray *prhs_copy_idx_4;
  const mxArray *prhs_copy_idx_5;
  real_T(*Signal)[2500001];
  real_T(*T)[2500001];
  real_T Am;
  real_T Fd;
  real_T FftL;
  real_T Tm;
  real_T a;
  real_T f;
  real_T mz;
  real_T p;
  st.tls = emlrtRootTLSGlobal;
  emlrtHeapReferenceStackEnterFcnR2012b(&st);
  emxInit_real_T(&st, &FftS);
  prhs_copy_idx_0 = prhs[0];
  prhs_copy_idx_1 = prhs[1];
  prhs_copy_idx_2 = prhs[2];
  prhs_copy_idx_3 = prhs[3];
  prhs_copy_idx_4 = prhs[4];
  prhs_copy_idx_5 = emlrtProtectR2012b(prhs[5], 5, true, -1);
  /* Marshall function inputs */
  Tm = emlrt_marshallIn(&st, emlrtAliasP(prhs_copy_idx_0), "Tm");
  Fd = emlrt_marshallIn(&st, emlrtAliasP(prhs_copy_idx_1), "Fd");
  mz = emlrt_marshallIn(&st, emlrtAliasP(prhs_copy_idx_2), "mz");
  FftL = emlrt_marshallIn(&st, emlrtAliasP(prhs_copy_idx_3), "FftL");
  T = c_emlrt_marshallIn(&st, emlrtAlias(prhs_copy_idx_4), "T");
  Signal = c_emlrt_marshallIn(&st, emlrtAlias(prhs_copy_idx_5), "Signal");
  a = emlrt_marshallIn(&st, emlrtAliasP(prhs[6]), "a");
  f = emlrt_marshallIn(&st, emlrtAliasP(prhs[7]), "f");
  p = emlrt_marshallIn(&st, emlrtAliasP(prhs[8]), "p");
  /* Invoke the target function */
  tone_search(Tm, Fd, mz, FftL, *T, *Signal, &a, &f, &p, FftS, &Am);
  /* Marshall function outputs */
  emlrt_marshallOut(*Signal, prhs_copy_idx_5);
  plhs[0] = prhs_copy_idx_5;
  if (nlhs > 1) {
    FftS->canFreeData = false;
    plhs[1] = b_emlrt_marshallOut(FftS);
  }
  emxFree_real_T(&st, &FftS);
  if (nlhs > 2) {
    plhs[2] = c_emlrt_marshallOut(Am);
  }
  if (nlhs > 3) {
    plhs[3] = c_emlrt_marshallOut(a);
  }
  if (nlhs > 4) {
    plhs[4] = c_emlrt_marshallOut(f);
  }
  if (nlhs > 5) {
    plhs[5] = c_emlrt_marshallOut(p);
  }
  emlrtHeapReferenceStackLeaveFcnR2012b(&st);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void tone_search_atexit(void)
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtEnterRtStackR2012b(&st);
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
  tone_search_xil_terminate();
  tone_search_xil_shutdown();
  emlrtExitTimeCleanup(&emlrtContextGlobal);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void tone_search_initialize(void)
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  mexFunctionCreateRootTLS();
  st.tls = emlrtRootTLSGlobal;
  emlrtClearAllocCountR2012b(&st, false, 0U, NULL);
  emlrtEnterRtStackR2012b(&st);
  emlrtFirstTimeR2012b(emlrtRootTLSGlobal);
}

/*
 * Arguments    : void
 * Return Type  : void
 */
void tone_search_terminate(void)
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  st.tls = emlrtRootTLSGlobal;
  emlrtLeaveRtStackR2012b(&st);
  emlrtDestroyRootTLS(&emlrtRootTLSGlobal);
}

/*
 * File trailer for _coder_tone_search_api.c
 *
 * [EOF]
 */
