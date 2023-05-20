/*
 * fft.c
 *
 * Code generation for function 'fft'
 *
 */

/* Include files */
#include "fft.h"
#include "main_scanner_data.h"
#include "main_scanner_emxutil.h"
#include "main_scanner_types.h"
#include "rt_nonfinite.h"

/* Variable Definitions */
static emlrtRSInfo l_emlrtRSI = {
    63,    /* lineNo */
    "fft", /* fcnName */
    "D:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\eml\\lib\\matlab\\datafun\\fft.m" /* pathName
                                                                        */
};

static emlrtRSInfo m_emlrtRSI =
    {
        31,    /* lineNo */
        "fft", /* fcnName */
        "D:\\Program "
        "Files\\MATLAB\\R2021b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
        "fft\\fft.m" /* pathName */
};

static emlrtRSInfo n_emlrtRSI =
    {
        58,                /* lineNo */
        "executeCallback", /* fcnName */
        "D:\\Program "
        "Files\\MATLAB\\R2021b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
        "fft\\fft.m" /* pathName */
};

static emlrtRSInfo o_emlrtRSI = {
    44,                        /* lineNo */
    "Custom1DFFTCallback/fft", /* fcnName */
    "D:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\shared\\coder\\coder\\lib\\+coder\\+"
    "internal\\Custom1DFFTCallback.m" /* pathName */
};

static emlrtRSInfo p_emlrtRSI = {
    54,                            /* lineNo */
    "Custom1DFFTCallback/fftLoop", /* fcnName */
    "D:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\shared\\coder\\coder\\lib\\+coder\\+"
    "internal\\Custom1DFFTCallback.m" /* pathName */
};

static emlrtRTEInfo emlrtRTEI = {
    52,    /* lineNo */
    35,    /* colNo */
    "fft", /* fName */
    "D:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\eml\\lib\\matlab\\datafun\\fft.m" /* pName
                                                                        */
};

static emlrtRTEInfo b_emlrtRTEI = {
    48,    /* lineNo */
    35,    /* colNo */
    "fft", /* fName */
    "D:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\eml\\lib\\matlab\\datafun\\fft.m" /* pName
                                                                        */
};

static emlrtRTEInfo l_emlrtRTEI = {
    63,    /* lineNo */
    5,     /* colNo */
    "fft", /* fName */
    "D:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\eml\\lib\\matlab\\datafun\\fft.m" /* pName
                                                                        */
};

static emlrtRTEInfo m_emlrtRTEI = {
    26,                   /* lineNo */
    32,                   /* colNo */
    "MATLABFFTWCallback", /* fName */
    "D:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\eml\\eml\\+coder\\+internal\\+"
    "fft\\MATLABFFTWCallback.m" /* pName */
};

/* Function Definitions */
void fft(const emlrtStack *sp, const real_T x[250001], real_T varargin_1,
         emxArray_creal_T *y)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack st;
  creal_T *y_data;
  int32_T i;
  int32_T loop_ub;
  st.prev = sp;
  st.tls = sp->tls;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  if (!(varargin_1 == varargin_1)) {
    emlrtErrorWithMessageIdR2018a(sp, &b_emlrtRTEI,
                                  "MATLAB:fftfcn:lengthNotNonNegInt",
                                  "MATLAB:fftfcn:lengthNotNonNegInt", 0);
  }
  if (!(varargin_1 <= 2.147483647E+9)) {
    emlrtErrorWithMessageIdR2018a(sp, &emlrtRTEI, "MATLAB:pmaxsize",
                                  "MATLAB:pmaxsize", 0);
  }
  st.site = &l_emlrtRSI;
  if (0 == (int32_T)varargin_1) {
    i = y->size[0] * y->size[1];
    y->size[0] = 1;
    y->size[1] = (int32_T)varargin_1;
    emxEnsureCapacity_creal_T(&st, y, i, &l_emlrtRTEI);
    y_data = y->data;
    loop_ub = (int32_T)varargin_1;
    for (i = 0; i < loop_ub; i++) {
      y_data[i].re = 0.0;
      y_data[i].im = 0.0;
    }
  } else {
    b_st.site = &m_emlrtRSI;
    c_st.site = &n_emlrtRSI;
    d_st.site = &o_emlrtRSI;
    e_st.site = &p_emlrtRSI;
    emlrtFFTWSetNumThreads(6);
    i = y->size[0] * y->size[1];
    y->size[0] = 1;
    y->size[1] = (int32_T)varargin_1;
    emxEnsureCapacity_creal_T(&e_st, y, i, &m_emlrtRTEI);
    y_data = y->data;
    emlrtFFTW_1D_R2C(&x[0], (real_T *)&y_data[0], 1, (int32_T)varargin_1,
                     250001, 1, -1);
  }
}

/* End of code generation (fft.c) */
