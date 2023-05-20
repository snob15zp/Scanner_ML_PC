/*
 * mldivide.c
 *
 * Code generation for function 'mldivide'
 *
 */

/* Include files */
#include "mldivide.h"
#include "main_scanner_data.h"
#include "rt_nonfinite.h"
#include "warning.h"
#include "mwmathutil.h"

/* Variable Definitions */
static emlrtRSInfo gb_emlrtRSI = {
    20,         /* lineNo */
    "mldivide", /* fcnName */
    "D:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\eml\\lib\\matlab\\ops\\mldivide.m" /* pathName
                                                                         */
};

static emlrtRSInfo hb_emlrtRSI = {
    42,      /* lineNo */
    "mldiv", /* fcnName */
    "D:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\eml\\lib\\matlab\\ops\\mldivide.m" /* pathName
                                                                         */
};

static emlrtRSInfo
    ib_emlrtRSI =
        {
            55,        /* lineNo */
            "lusolve", /* fcnName */
            "D:\\Program "
            "Files\\MATLAB\\R2021b\\toolbox\\eml\\eml\\+coder\\+"
            "internal\\lusolve.m" /* pathName */
};

static emlrtRSInfo
    jb_emlrtRSI =
        {
            210,          /* lineNo */
            "lusolve2x2", /* fcnName */
            "D:\\Program "
            "Files\\MATLAB\\R2021b\\toolbox\\eml\\eml\\+coder\\+"
            "internal\\lusolve.m" /* pathName */
};

static emlrtRSInfo
    kb_emlrtRSI =
        {
            90,              /* lineNo */
            "warn_singular", /* fcnName */
            "D:\\Program "
            "Files\\MATLAB\\R2021b\\toolbox\\eml\\eml\\+coder\\+"
            "internal\\lusolve.m" /* pathName */
};

/* Function Definitions */
void mldivide(const emlrtStack *sp, const real_T A[4], const real_T B[2],
              real_T Y[2])
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack st;
  real_T a21;
  real_T a22;
  real_T a22_tmp;
  int32_T r1;
  int32_T r2;
  st.prev = sp;
  st.tls = sp->tls;
  st.site = &gb_emlrtRSI;
  b_st.prev = &st;
  b_st.tls = st.tls;
  c_st.prev = &b_st;
  c_st.tls = b_st.tls;
  d_st.prev = &c_st;
  d_st.tls = c_st.tls;
  e_st.prev = &d_st;
  e_st.tls = d_st.tls;
  b_st.site = &hb_emlrtRSI;
  c_st.site = &ib_emlrtRSI;
  if (muDoubleScalarAbs(A[1]) > muDoubleScalarAbs(A[0])) {
    r1 = 1;
    r2 = 0;
  } else {
    r1 = 0;
    r2 = 1;
  }
  a21 = A[r2] / A[r1];
  a22_tmp = A[r1 + 2];
  a22 = A[r2 + 2] - a21 * a22_tmp;
  if ((a22 == 0.0) || (A[r1] == 0.0)) {
    d_st.site = &jb_emlrtRSI;
    e_st.site = &kb_emlrtRSI;
    warning(&e_st);
  }
  Y[1] = (B[r2] - B[r1] * a21) / a22;
  Y[0] = (B[r1] - Y[1] * a22_tmp) / A[r1];
}

/* End of code generation (mldivide.c) */
