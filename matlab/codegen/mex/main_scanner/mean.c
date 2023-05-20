/*
 * mean.c
 *
 * Code generation for function 'mean'
 *
 */

/* Include files */
#include "mean.h"
#include "main_scanner_data.h"
#include "main_scanner_types.h"
#include "rt_nonfinite.h"
#include "sumMatrixIncludeNaN.h"

/* Variable Definitions */
static emlrtRSInfo lb_emlrtRSI = {
    49,     /* lineNo */
    "mean", /* fcnName */
    "D:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\eml\\lib\\matlab\\datafun\\mean.m" /* pathName
                                                                         */
};

static emlrtRSInfo mb_emlrtRSI = {
    74,                      /* lineNo */
    "combineVectorElements", /* fcnName */
    "D:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\eml\\lib\\matlab\\datafun\\private\\combin"
    "eVectorElements.m" /* pathName */
};

static emlrtRSInfo nb_emlrtRSI = {
    99,                 /* lineNo */
    "blockedSummation", /* fcnName */
    "D:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\eml\\lib\\matlab\\datafun\\private\\blocke"
    "dSummation.m" /* pathName */
};

static emlrtRSInfo ob_emlrtRSI = {
    22,                    /* lineNo */
    "sumMatrixIncludeNaN", /* fcnName */
    "D:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\eml\\lib\\matlab\\datafun\\private\\sumMat"
    "rixIncludeNaN.m" /* pathName */
};

static emlrtRSInfo pb_emlrtRSI = {
    42,                 /* lineNo */
    "sumMatrixColumns", /* fcnName */
    "D:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\eml\\lib\\matlab\\datafun\\private\\sumMat"
    "rixIncludeNaN.m" /* pathName */
};

static emlrtRSInfo qb_emlrtRSI = {
    57,                 /* lineNo */
    "sumMatrixColumns", /* fcnName */
    "D:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\eml\\lib\\matlab\\datafun\\private\\sumMat"
    "rixIncludeNaN.m" /* pathName */
};

/* Function Definitions */
real_T mean(const emlrtStack *sp, const emxArray_real_T *x)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack st;
  emxArray_real_T c_x;
  real_T s;
  int32_T b_x;
  int32_T d_x;
  int32_T e_x;
  int32_T f_x;
  int32_T g_x;
  int32_T ib;
  int32_T inb;
  int32_T nfb;
  int32_T nleft;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &lb_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  b_st.site = &mb_emlrtRSI;
  if (x->size[1] == 0) {
    s = 0.0;
  } else {
    c_st.site = &nb_emlrtRSI;
    d_st.site = &ob_emlrtRSI;
    if (x->size[1] < 4096) {
      b_x = x->size[1];
      c_x = *x;
      d_x = b_x;
      c_x.size = &d_x;
      c_x.numDimensions = 1;
      e_st.site = &pb_emlrtRSI;
      s = sumColumnB(&e_st, &c_x, x->size[1]);
    } else {
      nfb = x->size[1] / 4096;
      inb = nfb << 12;
      nleft = x->size[1] - inb;
      b_x = x->size[1];
      c_x = *x;
      e_x = b_x;
      c_x.size = &e_x;
      c_x.numDimensions = 1;
      s = sumColumnB4(&c_x, 1);
      if (2 <= nfb) {
        b_x = x->size[1];
      }
      for (ib = 2; ib <= nfb; ib++) {
        c_x = *x;
        f_x = b_x;
        c_x.size = &f_x;
        c_x.numDimensions = 1;
        s += sumColumnB4(&c_x, ((ib - 1) << 12) + 1);
      }
      if (nleft > 0) {
        b_x = x->size[1];
        c_x = *x;
        g_x = b_x;
        c_x.size = &g_x;
        c_x.numDimensions = 1;
        e_st.site = &qb_emlrtRSI;
        s += b_sumColumnB(&e_st, &c_x, nleft, inb + 1);
      }
    }
  }
  return s / (real_T)x->size[1];
}

/* End of code generation (mean.c) */
