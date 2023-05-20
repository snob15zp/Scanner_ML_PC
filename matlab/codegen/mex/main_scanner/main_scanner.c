/*
 * main_scanner.c
 *
 * Code generation for function 'main_scanner'
 *
 */

/* Include files */
#include "main_scanner.h"
#include "filesave_ceval.h"
#include "main_scanner_data.h"
#include "main_scanner_emxutil.h"
#include "main_scanner_mexutil.h"
#include "main_scanner_types.h"
#include "rt_nonfinite.h"
#include "tone_search.h"
#include "mwmathutil.h"
#include <string.h>

/* Variable Definitions */
static emlrtRSInfo emlrtRSI = {
    7,              /* lineNo */
    "main_scanner", /* fcnName */
    "D:\\User\\dropbox_nsel16zp\\ZERDLab "
    "Dropbox\\Nsel\\GIT\\Scanner\\Scanner_ML_PC\\matlab\\main_scanner.m" /* pathName
                                                                          */
};

static emlrtRSInfo b_emlrtRSI = {
    16,             /* lineNo */
    "main_scanner", /* fcnName */
    "D:\\User\\dropbox_nsel16zp\\ZERDLab "
    "Dropbox\\Nsel\\GIT\\Scanner\\Scanner_ML_PC\\matlab\\main_scanner.m" /* pathName
                                                                          */
};

static emlrtRSInfo c_emlrtRSI = {
    23,             /* lineNo */
    "main_scanner", /* fcnName */
    "D:\\User\\dropbox_nsel16zp\\ZERDLab "
    "Dropbox\\Nsel\\GIT\\Scanner\\Scanner_ML_PC\\matlab\\main_scanner.m" /* pathName
                                                                          */
};

static emlrtRSInfo wb_emlrtRSI = {
    28,        /* lineNo */
    "sprintf", /* fcnName */
    "D:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\eml\\lib\\matlab\\strfun\\sprintf.m" /* pathName
                                                                           */
};

static emlrtMCInfo c_emlrtMCI = {
    52,              /* lineNo */
    14,              /* colNo */
    "nonConstPrint", /* fName */
    "D:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\eml\\lib\\matlab\\strfun\\sprintf.m" /* pName
                                                                           */
};

static emlrtMCInfo d_emlrtMCI = {
    54,              /* lineNo */
    15,              /* colNo */
    "nonConstPrint", /* fName */
    "D:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\eml\\lib\\matlab\\strfun\\sprintf.m" /* pName
                                                                           */
};

static emlrtBCInfo emlrtBCI = {
    1,              /* iFirst */
    100,            /* iLast */
    8,              /* lineNo */
    21,             /* colNo */
    "Out",          /* aName */
    "main_scanner", /* fName */
    "D:\\User\\dropbox_nsel16zp\\ZERDLab "
    "Dropbox\\Nsel\\GIT\\Scanner\\Scanner_ML_PC\\matlab\\main_scanner.m", /* pName
                                                                           */
    3 /* checkKind */
};

static emlrtDCInfo emlrtDCI = {
    56,              /* lineNo */
    53,              /* colNo */
    "nonConstPrint", /* fName */
    "D:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\eml\\lib\\matlab\\strfun\\sprintf.m", /* pName
                                                                            */
    4 /* checkKind */
};

static emlrtDCInfo b_emlrtDCI = {
    4,              /* lineNo */
    18,             /* colNo */
    "main_scanner", /* fName */
    "D:\\User\\dropbox_nsel16zp\\ZERDLab "
    "Dropbox\\Nsel\\GIT\\Scanner\\Scanner_ML_PC\\matlab\\main_scanner.m", /* pName
                                                                           */
    1 /* checkKind */
};

static emlrtDCInfo c_emlrtDCI = {
    4,              /* lineNo */
    18,             /* colNo */
    "main_scanner", /* fName */
    "D:\\User\\dropbox_nsel16zp\\ZERDLab "
    "Dropbox\\Nsel\\GIT\\Scanner\\Scanner_ML_PC\\matlab\\main_scanner.m", /* pName
                                                                           */
    4 /* checkKind */
};

static emlrtDCInfo d_emlrtDCI = {
    4,              /* lineNo */
    5,              /* colNo */
    "main_scanner", /* fName */
    "D:\\User\\dropbox_nsel16zp\\ZERDLab "
    "Dropbox\\Nsel\\GIT\\Scanner\\Scanner_ML_PC\\matlab\\main_scanner.m", /* pName
                                                                           */
    1 /* checkKind */
};

static emlrtRTEInfo j_emlrtRTEI = {
    4,              /* lineNo */
    5,              /* colNo */
    "main_scanner", /* fName */
    "D:\\User\\dropbox_nsel16zp\\ZERDLab "
    "Dropbox\\Nsel\\GIT\\Scanner\\Scanner_ML_PC\\matlab\\main_scanner.m" /* pName
                                                                          */
};

static emlrtRTEInfo k_emlrtRTEI = {
    1,              /* lineNo */
    25,             /* colNo */
    "main_scanner", /* fName */
    "D:\\User\\dropbox_nsel16zp\\ZERDLab "
    "Dropbox\\Nsel\\GIT\\Scanner\\Scanner_ML_PC\\matlab\\main_scanner.m" /* pName
                                                                          */
};

static emlrtRSInfo yb_emlrtRSI = {
    52,              /* lineNo */
    "nonConstPrint", /* fcnName */
    "D:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\eml\\lib\\matlab\\strfun\\sprintf.m" /* pathName
                                                                           */
};

static emlrtRSInfo ac_emlrtRSI = {
    54,              /* lineNo */
    "nonConstPrint", /* fcnName */
    "D:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\eml\\lib\\matlab\\strfun\\sprintf.m" /* pathName
                                                                           */
};

static emlrtRSInfo bc_emlrtRSI = {
    57,              /* lineNo */
    "nonConstPrint", /* fcnName */
    "D:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\eml\\lib\\matlab\\strfun\\sprintf.m" /* pathName
                                                                           */
};

/* Function Declarations */
static void c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *tmpStr,
                               const char_T *identifier, emxArray_char_T *y);

static const mxArray *c_feval(const emlrtStack *sp, const mxArray *m1,
                              const mxArray *m2, const mxArray *m3,
                              emlrtMCInfo *location);

static void d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               emxArray_char_T *y);

static void h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId,
                               emxArray_char_T *ret);

static const mxArray *length(const emlrtStack *sp, const mxArray *m1,
                             emlrtMCInfo *location);

/* Function Definitions */
static void c_emlrt_marshallIn(const emlrtStack *sp, const mxArray *tmpStr,
                               const char_T *identifier, emxArray_char_T *y)
{
  emlrtMsgIdentifier thisId;
  thisId.fIdentifier = (const char_T *)identifier;
  thisId.fParent = NULL;
  thisId.bParentIsCell = false;
  d_emlrt_marshallIn(sp, emlrtAlias(tmpStr), &thisId, y);
  emlrtDestroyArray(&tmpStr);
}

static const mxArray *c_feval(const emlrtStack *sp, const mxArray *m1,
                              const mxArray *m2, const mxArray *m3,
                              emlrtMCInfo *location)
{
  const mxArray *pArrays[3];
  const mxArray *m;
  pArrays[0] = m1;
  pArrays[1] = m2;
  pArrays[2] = m3;
  return emlrtCallMATLABR2012b((emlrtCTX)sp, 1, &m, 3, &pArrays[0],
                               (const char_T *)"feval", true, location);
}

static void d_emlrt_marshallIn(const emlrtStack *sp, const mxArray *u,
                               const emlrtMsgIdentifier *parentId,
                               emxArray_char_T *y)
{
  h_emlrt_marshallIn(sp, emlrtAlias(u), parentId, y);
  emlrtDestroyArray(&u);
}

static void h_emlrt_marshallIn(const emlrtStack *sp, const mxArray *src,
                               const emlrtMsgIdentifier *msgId,
                               emxArray_char_T *ret)
{
  static const int32_T dims[2] = {1, -1};
  int32_T iv[2];
  int32_T i;
  char_T *ret_data;
  const boolean_T bv[2] = {false, true};
  emlrtCheckVsBuiltInR2012b((emlrtCTX)sp, msgId, src, (const char_T *)"char",
                            false, 2U, (void *)&dims[0], &bv[0], &iv[0]);
  i = ret->size[0] * ret->size[1];
  ret->size[0] = iv[0];
  ret->size[1] = iv[1];
  emxEnsureCapacity_char_T(sp, ret, i, (emlrtRTEInfo *)NULL);
  ret_data = ret->data;
  emlrtImportArrayR2015b((emlrtCTX)sp, src, &ret_data[0], 1, false);
  emlrtDestroyArray(&src);
}

static const mxArray *length(const emlrtStack *sp, const mxArray *m1,
                             emlrtMCInfo *location)
{
  const mxArray *m;
  const mxArray *pArray;
  pArray = m1;
  return emlrtCallMATLABR2012b((emlrtCTX)sp, 1, &m, 1, &pArray,
                               (const char_T *)"length", true, location);
}

void main_scanner(main_scannerStackData *SD, const emlrtStack *sp, real_T Tm,
                  real_T Fd, real_T mz, real_T FftL, const real_T T[250001],
                  real_T Signal[250001], real_T Out[300], emxArray_real_T *FftS)
{
  static const int32_T iv[2] = {1, 7};
  static const int32_T iv1[2] = {1, 2};
  static const char_T u[7] = {'s', 'p', 'r', 'i', 'n', 't', 'f'};
  static const char_T formatSpec[2] = {'%', 'i'};
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack st;
  emxArray_char_T *tmpStr;
  const mxArray *b_tmpStr;
  const mxArray *b_y;
  const mxArray *c_y;
  const mxArray *m;
  const mxArray *y;
  real_T Am;
  real_T a;
  real_T f;
  real_T p;
  real_T strSize;
  real_T *FftS_data;
  int32_T b_i;
  int32_T i;
  int32_T loop_ub;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  covrtLogFcn(&emlrtCoverageInstance, 0U, 0U);
  covrtLogBasicBlock(&emlrtCoverageInstance, 0U, 0U);
  /*  scanner function */
  Am = 1.0;
  a = 0.0;
  f = 0.0;
  p = 0.0;
  i = 0;
  /*  initial assignments to enter the search and subtract tone loop */
  memset(&Out[0], 0, 300U * sizeof(real_T));
  b_i = FftS->size[0] * FftS->size[1];
  FftS->size[0] = 1;
  emxEnsureCapacity_real_T(sp, FftS, b_i, &j_emlrtRTEI);
  if (!(FftL >= 0.0)) {
    emlrtNonNegativeCheckR2012b(FftL, &c_emlrtDCI, (emlrtCTX)sp);
  }
  strSize = (int32_T)muDoubleScalarFloor(FftL);
  if (FftL != strSize) {
    emlrtIntegerCheckR2012b(FftL, &b_emlrtDCI, (emlrtCTX)sp);
  }
  b_i = FftS->size[0] * FftS->size[1];
  loop_ub = (int32_T)FftL;
  FftS->size[1] = (int32_T)FftL;
  emxEnsureCapacity_real_T(sp, FftS, b_i, &j_emlrtRTEI);
  FftS_data = FftS->data;
  if (FftL != strSize) {
    emlrtIntegerCheckR2012b(FftL, &d_emlrtDCI, (emlrtCTX)sp);
  }
  for (b_i = 0; b_i < loop_ub; b_i++) {
    FftS_data[b_i] = 0.0;
  }
  /*         %% The main cycle of searching and subtracting the tone of maximum
   * amplitude */
  emxInit_char_T(sp, &tmpStr, &k_emlrtRTEI);
  while (covrtLogWhile(&emlrtCoverageInstance, 0U, 0U, 0, Am > 0.001)) {
    covrtLogBasicBlock(&emlrtCoverageInstance, 0U, 1U);
    /*  if the amplitude of the subtraction is greater than the specified
     * threshold , then we look for and subtract the next tone */
    st.site = &emlrtRSI;
    tone_search(SD, &st, Tm, Fd, mz, FftL, T, Signal, &a, &f, &p, FftS, &Am);
    /*  tone search and subtraction function */
    i++;
    if (i > 100) {
      emlrtDynamicBoundsCheckR2012b(101, 1, 100, &emlrtBCI, (emlrtCTX)sp);
    }
    loop_ub = 3 * (i - 1);
    Out[loop_ub] = a;
    Out[loop_ub + 1] = f;
    Out[loop_ub + 2] = p;
    /*  fill the output array : amplitude , frequency , phase */
    covrtLogIf(&emlrtCoverageInstance, 0U, 0U, 0, false);
    covrtLogBasicBlock(&emlrtCoverageInstance, 0U, 3U);
    st.site = &b_emlrtRSI;
    b_st.site = &wb_emlrtRSI;
    b_tmpStr = NULL;
    y = NULL;
    m = emlrtCreateCharArray(2, &iv[0]);
    emlrtInitCharArrayR2013a(&b_st, 7, m, &u[0]);
    emlrtAssign(&y, m);
    b_y = NULL;
    m = emlrtCreateCharArray(2, &iv1[0]);
    emlrtInitCharArrayR2013a(&b_st, 2, m, &formatSpec[0]);
    emlrtAssign(&b_y, m);
    c_y = NULL;
    m = emlrtCreateNumericMatrix(1, 1, mxINT32_CLASS, mxREAL);
    *(int32_T *)emlrtMxGetData(m) = i;
    emlrtAssign(&c_y, m);
    c_st.site = &yb_emlrtRSI;
    emlrtAssign(&b_tmpStr, c_feval(&c_st, y, b_y, c_y, &c_emlrtMCI));
    c_st.site = &ac_emlrtRSI;
    strSize = emlrt_marshallIn(&c_st,
                               length(&c_st, emlrtAlias(b_tmpStr), &d_emlrtMCI),
                               "<output of length>");
    if (!(strSize >= 0.0)) {
      emlrtNonNegativeCheckR2012b(strSize, &emlrtDCI, &b_st);
    }
    c_st.site = &bc_emlrtRSI;
    c_emlrt_marshallIn(&c_st, emlrtAlias(b_tmpStr), "tmpStr", tmpStr);
    emlrtDestroyArray(&b_tmpStr);
    /* coder.varsize('ActVal1',[qblobs,DmaxSize]); */
    /* ActVal1(1:qblobs,:)=ActVal(1:qblobs,:); */
    covrtLogIf(&emlrtCoverageInstance, 0U, 0U, 1, false);
    covrtLogBasicBlock(&emlrtCoverageInstance, 0U, 5U);
    st.site = &c_emlrtRSI;
    filesave_ceval();
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  emxFree_char_T(sp, &tmpStr);
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

/* End of code generation (main_scanner.c) */
