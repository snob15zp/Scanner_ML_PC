/*
 * _coder_main_scanner_api.c
 *
 * Code generation for function '_coder_main_scanner_api'
 *
 */

/* Include files */
#include "_coder_main_scanner_api.h"
#include "main_scanner.h"
#include "main_scanner_data.h"
#include "main_scanner_emxutil.h"
#include "main_scanner_mexutil.h"
#include "main_scanner_types.h"
#include "rt_nonfinite.h"

/* Variable Definitions */
static emlrtRTEInfo n_emlrtRTEI = {
    1,                         /* lineNo */
    1,                         /* colNo */
    "_coder_main_scanner_api", /* fName */
    ""                         /* pName */
};

/* Function Declarations */
static const mxArray *b_emlrt_marshallOut(const emxArray_real_T *u);

static real_T (*e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *T,
                                   const char_T *identifier))[250001];

static const mxArray *emlrt_marshallOut(const real_T u[300]);

static real_T (*f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                   const emlrtMsgIdentifier *parentId))[250001];

static real_T (*i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                   const emlrtMsgIdentifier *msgId))[250001];

/* Function Definitions */
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

static real_T (*e_emlrt_marshallIn(const emlrtStack *sp, const mxArray *T,
                                   const char_T *identifier))[250001]
{
  emlrtMsgIdentifier thisId;
  real_T(*y)[250001];
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  y = f_emlrt_marshallIn(sp, emlrtAlias(T), &thisId);
  emlrtDestroyArray(&T);
  return y;
}

static const mxArray *emlrt_marshallOut(const real_T u[300])
{
  static const int32_T iv[2] = {0, 0};
  static const int32_T iv1[2] = {3, 100};
  const mxArray *m;
  const mxArray *y;
  y = NULL;
  m = emlrtCreateNumericArray(2, (const void *)&iv[0], mxDOUBLE_CLASS, mxREAL);
  emlrtMxSetData((mxArray *)m, (void *)&u[0]);
  emlrtSetDimensions((mxArray *)m, &iv1[0], 2);
  emlrtAssign(&y, m);
  return y;
}

static real_T (*f_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                                   const emlrtMsgIdentifier *parentId))[250001]
{
  real_T(*y)[250001];
  y = i_emlrt_marshallIn(sp, emlrtAlias(u), parentId);
  emlrtDestroyArray(&u);
  return y;
}

static real_T (*i_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                                   const emlrtMsgIdentifier *msgId))[250001]
{
  static const int32_T dims[2] = {1, 250001};
  real_T(*ret)[250001];
  emlrtCheckBuiltInR2012b((emlrtCTX)sp, msgId, src, (const char_T *)"double",
                          false, 2U, (void *)&dims[0]);
  ret = (real_T(*)[250001])emlrtMxGetData(src);
  emlrtDestroyArray(&src);
  return ret;
}

void main_scanner_api(main_scannerStackData *SD, const mxArray *const prhs[6],
                      int32_T nlhs, const mxArray *plhs[2])
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  emxArray_real_T *FftS;
  const mxArray *prhs_copy_idx_5;
  real_T(*Signal)[250001];
  real_T(*T)[250001];
  real_T(*Out)[300];
  real_T Fd;
  real_T FftL;
  real_T Tm;
  real_T mz;
  st.tls = emlrtRootTLSGlobal;
  Out = (real_T(*)[300])mxMalloc(sizeof(real_T[300]));
  emlrtHeapReferenceStackEnterFcnR2012b(&st);
  emxInit_real_T(&st, &FftS, &n_emlrtRTEI);
  prhs_copy_idx_5 = emlrtProtectR2012b(prhs[5], 5, false, -1);
  /* Marshall function inputs */
  Tm = emlrt_marshallIn(&st, emlrtAliasP(prhs[0]), "Tm");
  Fd = emlrt_marshallIn(&st, emlrtAliasP(prhs[1]), "Fd");
  mz = emlrt_marshallIn(&st, emlrtAliasP(prhs[2]), "mz");
  FftL = emlrt_marshallIn(&st, emlrtAliasP(prhs[3]), "FftL");
  T = e_emlrt_marshallIn(&st, emlrtAlias(prhs[4]), "T");
  Signal = e_emlrt_marshallIn(&st, emlrtAlias(prhs_copy_idx_5), "Signal");
  /* Invoke the target function */
  main_scanner(SD, &st, Tm, Fd, mz, FftL, *T, *Signal, *Out, FftS);
  /* Marshall function outputs */
  plhs[0] = emlrt_marshallOut(*Out);
  if (nlhs > 1) {
    FftS->canFreeData = false;
    plhs[1] = b_emlrt_marshallOut(FftS);
  }
  emxFree_real_T(&st, &FftS);
  emlrtHeapReferenceStackLeaveFcnR2012b(&st);
}

/* End of code generation (_coder_main_scanner_api.c) */
