/*
 * tone_search.c
 *
 * Code generation for function 'tone_search'
 *
 */

/* Include files */
#include "tone_search.h"
#include "cosd.h"
#include "eml_int_forloop_overflow_check.h"
#include "fft.h"
#include "main_scanner_data.h"
#include "main_scanner_emxutil.h"
#include "main_scanner_types.h"
#include "mean.h"
#include "mldivide.h"
#include "rt_nonfinite.h"
#include "sind.h"
#include "mwmathutil.h"

/* Variable Definitions */
static emlrtRSInfo d_emlrtRSI = {
    4,             /* lineNo */
    "tone_search", /* fcnName */
    "D:\\User\\dropbox_nsel16zp\\ZERDLab "
    "Dropbox\\Nsel\\GIT\\Scanner\\Scanner_ML_PC\\matlab\\tone_search.m" /* pathName
                                                                         */
};

static emlrtRSInfo e_emlrtRSI = {
    7,             /* lineNo */
    "tone_search", /* fcnName */
    "D:\\User\\dropbox_nsel16zp\\ZERDLab "
    "Dropbox\\Nsel\\GIT\\Scanner\\Scanner_ML_PC\\matlab\\tone_search.m" /* pathName
                                                                         */
};

static emlrtRSInfo f_emlrtRSI = {
    18,            /* lineNo */
    "tone_search", /* fcnName */
    "D:\\User\\dropbox_nsel16zp\\ZERDLab "
    "Dropbox\\Nsel\\GIT\\Scanner\\Scanner_ML_PC\\matlab\\tone_search.m" /* pathName
                                                                         */
};

static emlrtRSInfo g_emlrtRSI = {
    28,            /* lineNo */
    "tone_search", /* fcnName */
    "D:\\User\\dropbox_nsel16zp\\ZERDLab "
    "Dropbox\\Nsel\\GIT\\Scanner\\Scanner_ML_PC\\matlab\\tone_search.m" /* pathName
                                                                         */
};

static emlrtRSInfo h_emlrtRSI = {
    29,            /* lineNo */
    "tone_search", /* fcnName */
    "D:\\User\\dropbox_nsel16zp\\ZERDLab "
    "Dropbox\\Nsel\\GIT\\Scanner\\Scanner_ML_PC\\matlab\\tone_search.m" /* pathName
                                                                         */
};

static emlrtRSInfo i_emlrtRSI = {
    36,            /* lineNo */
    "tone_search", /* fcnName */
    "D:\\User\\dropbox_nsel16zp\\ZERDLab "
    "Dropbox\\Nsel\\GIT\\Scanner\\Scanner_ML_PC\\matlab\\tone_search.m" /* pathName
                                                                         */
};

static emlrtRSInfo j_emlrtRSI = {
    37,            /* lineNo */
    "tone_search", /* fcnName */
    "D:\\User\\dropbox_nsel16zp\\ZERDLab "
    "Dropbox\\Nsel\\GIT\\Scanner\\Scanner_ML_PC\\matlab\\tone_search.m" /* pathName
                                                                         */
};

static emlrtRSInfo k_emlrtRSI = {
    38,            /* lineNo */
    "tone_search", /* fcnName */
    "D:\\User\\dropbox_nsel16zp\\ZERDLab "
    "Dropbox\\Nsel\\GIT\\Scanner\\Scanner_ML_PC\\matlab\\tone_search.m" /* pathName
                                                                         */
};

static emlrtRSInfo t_emlrtRSI =
    {
        18,    /* lineNo */
        "abs", /* fcnName */
        "D:\\Program "
        "Files\\MATLAB\\R2021b\\toolbox\\eml\\lib\\matlab\\elfun\\abs.m" /* pathName
                                                                          */
};

static emlrtRSInfo u_emlrtRSI = {
    74,                    /* lineNo */
    "applyScalarFunction", /* fcnName */
    "D:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\applyScalarFunction.m" /* pathName */
};

static emlrtRSInfo v_emlrtRSI = {
    17,    /* lineNo */
    "max", /* fcnName */
    "D:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\eml\\lib\\matlab\\datafun\\max.m" /* pathName
                                                                        */
};

static emlrtRSInfo w_emlrtRSI =
    {
        38,         /* lineNo */
        "minOrMax", /* fcnName */
        "D:\\Program "
        "Files\\MATLAB\\R2021b\\toolbox\\eml\\eml\\+coder\\+internal\\minOrMax."
        "m" /* pathName */
};

static emlrtRSInfo x_emlrtRSI =
    {
        77,        /* lineNo */
        "maximum", /* fcnName */
        "D:\\Program "
        "Files\\MATLAB\\R2021b\\toolbox\\eml\\eml\\+coder\\+internal\\minOrMax."
        "m" /* pathName */
};

static emlrtRSInfo y_emlrtRSI = {
    169,             /* lineNo */
    "unaryMinOrMax", /* fcnName */
    "D:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\unaryMinOrMax.m" /* pathName */
};

static emlrtRSInfo ab_emlrtRSI = {
    62,                      /* lineNo */
    "vectorMinOrMaxInPlace", /* fcnName */
    "D:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\vectorMinOrMaxInPlace.m" /* pathName */
};

static emlrtRSInfo bb_emlrtRSI = {
    54,                      /* lineNo */
    "vectorMinOrMaxInPlace", /* fcnName */
    "D:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\vectorMinOrMaxInPlace.m" /* pathName */
};

static emlrtRSInfo cb_emlrtRSI = {
    103,         /* lineNo */
    "findFirst", /* fcnName */
    "D:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\vectorMinOrMaxInPlace.m" /* pathName */
};

static emlrtRSInfo db_emlrtRSI = {
    120,                        /* lineNo */
    "minOrMaxRealVectorKernel", /* fcnName */
    "D:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\vectorMinOrMaxInPlace.m" /* pathName */
};

static emlrtRSInfo eb_emlrtRSI = {
    44,       /* lineNo */
    "mpower", /* fcnName */
    "D:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\eml\\lib\\matlab\\matfun\\mpower.m" /* pathName
                                                                          */
};

static emlrtRSInfo fb_emlrtRSI =
    {
        71,      /* lineNo */
        "power", /* fcnName */
        "D:\\Program "
        "Files\\MATLAB\\R2021b\\toolbox\\eml\\lib\\matlab\\ops\\power.m" /* pathName
                                                                          */
};

static emlrtRTEInfo e_emlrtRTEI = {
    13,     /* lineNo */
    9,      /* colNo */
    "sqrt", /* fName */
    "D:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\eml\\lib\\matlab\\elfun\\sqrt.m" /* pName
                                                                       */
};

static emlrtRTEInfo f_emlrtRTEI = {
    130,             /* lineNo */
    27,              /* colNo */
    "unaryMinOrMax", /* fName */
    "D:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\unaryMinOrMax.m" /* pName */
};

static emlrtBCInfo b_emlrtBCI = {
    -1,            /* iFirst */
    -1,            /* iLast */
    37,            /* lineNo */
    51,            /* colNo */
    "FftS",        /* aName */
    "tone_search", /* fName */
    "D:\\User\\dropbox_nsel16zp\\ZERDLab "
    "Dropbox\\Nsel\\GIT\\Scanner\\Scanner_ML_PC\\matlab\\tone_search.m", /* pName
                                                                          */
    0 /* checkKind */
};

static emlrtDCInfo e_emlrtDCI = {
    37,            /* lineNo */
    51,            /* colNo */
    "tone_search", /* fName */
    "D:\\User\\dropbox_nsel16zp\\ZERDLab "
    "Dropbox\\Nsel\\GIT\\Scanner\\Scanner_ML_PC\\matlab\\tone_search.m", /* pName
                                                                          */
    1 /* checkKind */
};

static emlrtBCInfo c_emlrtBCI = {
    -1,            /* iFirst */
    -1,            /* iLast */
    37,            /* lineNo */
    42,            /* colNo */
    "FftS",        /* aName */
    "tone_search", /* fName */
    "D:\\User\\dropbox_nsel16zp\\ZERDLab "
    "Dropbox\\Nsel\\GIT\\Scanner\\Scanner_ML_PC\\matlab\\tone_search.m", /* pName
                                                                          */
    0 /* checkKind */
};

static emlrtDCInfo f_emlrtDCI = {
    37,            /* lineNo */
    42,            /* colNo */
    "tone_search", /* fName */
    "D:\\User\\dropbox_nsel16zp\\ZERDLab "
    "Dropbox\\Nsel\\GIT\\Scanner\\Scanner_ML_PC\\matlab\\tone_search.m", /* pName
                                                                          */
    1 /* checkKind */
};

static emlrtBCInfo d_emlrtBCI = {
    -1,            /* iFirst */
    -1,            /* iLast */
    37,            /* lineNo */
    21,            /* colNo */
    "FftS",        /* aName */
    "tone_search", /* fName */
    "D:\\User\\dropbox_nsel16zp\\ZERDLab "
    "Dropbox\\Nsel\\GIT\\Scanner\\Scanner_ML_PC\\matlab\\tone_search.m", /* pName
                                                                          */
    0 /* checkKind */
};

static emlrtDCInfo g_emlrtDCI = {
    37,            /* lineNo */
    21,            /* colNo */
    "tone_search", /* fName */
    "D:\\User\\dropbox_nsel16zp\\ZERDLab "
    "Dropbox\\Nsel\\GIT\\Scanner\\Scanner_ML_PC\\matlab\\tone_search.m", /* pName
                                                                          */
    1 /* checkKind */
};

static emlrtRTEInfo h_emlrtRTEI = {
    26,            /* lineNo */
    11,            /* colNo */
    "tone_search", /* fName */
    "D:\\User\\dropbox_nsel16zp\\ZERDLab "
    "Dropbox\\Nsel\\GIT\\Scanner\\Scanner_ML_PC\\matlab\\tone_search.m" /* pName
                                                                         */
};

static emlrtRTEInfo i_emlrtRTEI = {
    14,            /* lineNo */
    15,            /* colNo */
    "tone_search", /* fName */
    "D:\\User\\dropbox_nsel16zp\\ZERDLab "
    "Dropbox\\Nsel\\GIT\\Scanner\\Scanner_ML_PC\\matlab\\tone_search.m" /* pName
                                                                         */
};

static emlrtBCInfo e_emlrtBCI = {
    1,             /* iFirst */
    250001,        /* iLast */
    15,            /* lineNo */
    26,            /* colNo */
    "Signal",      /* aName */
    "tone_search", /* fName */
    "D:\\User\\dropbox_nsel16zp\\ZERDLab "
    "Dropbox\\Nsel\\GIT\\Scanner\\Scanner_ML_PC\\matlab\\tone_search.m", /* pName
                                                                          */
    0 /* checkKind */
};

static emlrtBCInfo f_emlrtBCI = {
    1,             /* iFirst */
    250001,        /* iLast */
    16,            /* lineNo */
    26,            /* colNo */
    "Signal",      /* aName */
    "tone_search", /* fName */
    "D:\\User\\dropbox_nsel16zp\\ZERDLab "
    "Dropbox\\Nsel\\GIT\\Scanner\\Scanner_ML_PC\\matlab\\tone_search.m", /* pName
                                                                          */
    0 /* checkKind */
};

static emlrtBCInfo g_emlrtBCI = {
    1,             /* iFirst */
    250001,        /* iLast */
    30,            /* lineNo */
    22,            /* colNo */
    "Signal",      /* aName */
    "tone_search", /* fName */
    "D:\\User\\dropbox_nsel16zp\\ZERDLab "
    "Dropbox\\Nsel\\GIT\\Scanner\\Scanner_ML_PC\\matlab\\tone_search.m", /* pName
                                                                          */
    0 /* checkKind */
};

static emlrtBCInfo h_emlrtBCI = {
    1,             /* iFirst */
    250001,        /* iLast */
    31,            /* lineNo */
    22,            /* colNo */
    "Signal",      /* aName */
    "tone_search", /* fName */
    "D:\\User\\dropbox_nsel16zp\\ZERDLab "
    "Dropbox\\Nsel\\GIT\\Scanner\\Scanner_ML_PC\\matlab\\tone_search.m", /* pName
                                                                          */
    0 /* checkKind */
};

static emlrtRTEInfo o_emlrtRTEI = {
    30,                    /* lineNo */
    21,                    /* colNo */
    "applyScalarFunction", /* fName */
    "D:\\Program "
    "Files\\MATLAB\\R2021b\\toolbox\\eml\\eml\\+coder\\+"
    "internal\\applyScalarFunction.m" /* pName */
};

static emlrtRTEInfo p_emlrtRTEI = {
    5,             /* lineNo */
    5,             /* colNo */
    "tone_search", /* fName */
    "D:\\User\\dropbox_nsel16zp\\ZERDLab "
    "Dropbox\\Nsel\\GIT\\Scanner\\Scanner_ML_PC\\matlab\\tone_search.m" /* pName
                                                                         */
};

static emlrtRTEInfo q_emlrtRTEI = {
    37,            /* lineNo */
    14,            /* colNo */
    "tone_search", /* fName */
    "D:\\User\\dropbox_nsel16zp\\ZERDLab "
    "Dropbox\\Nsel\\GIT\\Scanner\\Scanner_ML_PC\\matlab\\tone_search.m" /* pName
                                                                         */
};

static emlrtRTEInfo r_emlrtRTEI = {
    37,            /* lineNo */
    37,            /* colNo */
    "tone_search", /* fName */
    "D:\\User\\dropbox_nsel16zp\\ZERDLab "
    "Dropbox\\Nsel\\GIT\\Scanner\\Scanner_ML_PC\\matlab\\tone_search.m" /* pName
                                                                         */
};

static emlrtRTEInfo s_emlrtRTEI = {
    4,             /* lineNo */
    14,            /* colNo */
    "tone_search", /* fName */
    "D:\\User\\dropbox_nsel16zp\\ZERDLab "
    "Dropbox\\Nsel\\GIT\\Scanner\\Scanner_ML_PC\\matlab\\tone_search.m" /* pName
                                                                         */
};

/* Function Definitions */
void tone_search(main_scannerStackData *SD, const emlrtStack *sp, real_T Tm,
                 real_T Fd, real_T mz, real_T FftL, const real_T T[250001],
                 real_T Signal[250001], real_T *a, real_T *f, real_T *p,
                 emxArray_real_T *FftS, real_T *Am)
{
  emlrtStack b_st;
  emlrtStack c_st;
  emlrtStack d_st;
  emlrtStack e_st;
  emlrtStack f_st;
  emlrtStack g_st;
  emlrtStack h_st;
  emlrtStack st;
  emxArray_creal_T *x;
  emxArray_real_T *b_FftS;
  emxArray_real_T *c_FftS;
  creal_T *x_data;
  real_T cc[4];
  real_T X[2];
  real_T b_yc[2];
  real_T an;
  real_T d;
  real_T ex;
  real_T ff;
  real_T hf;
  real_T sc;
  real_T ss;
  real_T yc;
  real_T ys;
  real_T *FftS_data;
  real_T *b_FftS_data;
  int32_T b_a;
  int32_T idx;
  int32_T k;
  int32_T nx;
  boolean_T exitg1;
  boolean_T overflow;
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
  f_st.prev = &e_st;
  f_st.tls = e_st.tls;
  g_st.prev = &f_st;
  g_st.tls = f_st.tls;
  h_st.prev = &g_st;
  h_st.tls = g_st.tls;
  emlrtHeapReferenceStackEnterFcnR2012b((emlrtCTX)sp);
  covrtLogFcn(&emlrtCoverageInstance, 1U, 0U);
  covrtLogBasicBlock(&emlrtCoverageInstance, 1U, 0U);
  /*  search and delete tones function */
  *f *= 360.0;
  for (k = 0; k < 250001; k++) {
    SD->f0.dv[k] = *f * T[k] + *p;
  }
  b_sind(SD->f0.dv);
  for (k = 0; k < 250001; k++) {
    Signal[k] -= *a * SD->f0.dv[k];
  }
  emxInit_creal_T(sp, &x, &s_emlrtRTEI);
  /*  calculate the difference signal */
  /*         %% Spectral representation of the input signal */
  st.site = &d_emlrtRSI;
  b_st.site = &d_emlrtRSI;
  fft(&b_st, Signal, FftL, x);
  x_data = x->data;
  b_st.site = &t_emlrtRSI;
  nx = x->size[1];
  k = FftS->size[0] * FftS->size[1];
  FftS->size[0] = 1;
  FftS->size[1] = x->size[1];
  emxEnsureCapacity_real_T(&b_st, FftS, k, &o_emlrtRTEI);
  FftS_data = FftS->data;
  c_st.site = &u_emlrtRSI;
  overflow = ((1 <= x->size[1]) && (x->size[1] > 2147483646));
  if (overflow) {
    d_st.site = &q_emlrtRSI;
    check_forloop_overflow_error(&d_st);
  }
  for (k = 0; k < nx; k++) {
    FftS_data[k] = muDoubleScalarHypot(x_data[k].re, x_data[k].im);
  }
  emxFree_creal_T(&b_st, &x);
  /*  signal Fourier transform amplitude */
  k = FftS->size[0] * FftS->size[1];
  FftS->size[0] = 1;
  emxEnsureCapacity_real_T(sp, FftS, k, &p_emlrtRTEI);
  FftS_data = FftS->data;
  nx = FftS->size[1] - 1;
  for (k = 0; k <= nx; k++) {
    FftS_data[k] = 2.0 * FftS_data[k] / FftL;
  }
  /*  amplitude normalization of the spectrum */
  /*         %% Tone frequency search and calculation */
  st.site = &e_emlrtRSI;
  b_st.site = &v_emlrtRSI;
  c_st.site = &w_emlrtRSI;
  d_st.site = &x_emlrtRSI;
  if (FftS->size[1] < 1) {
    emlrtErrorWithMessageIdR2018a(&d_st, &f_emlrtRTEI,
                                  "Coder:toolbox:eml_min_or_max_varDimZero",
                                  "Coder:toolbox:eml_min_or_max_varDimZero", 0);
  }
  e_st.site = &y_emlrtRSI;
  nx = FftS->size[1];
  if (FftS->size[1] <= 2) {
    if (FftS->size[1] == 1) {
      ex = FftS_data[0];
      idx = 1;
    } else if ((FftS_data[0] < FftS_data[1]) ||
               (muDoubleScalarIsNaN(FftS_data[0]) &&
                (!muDoubleScalarIsNaN(FftS_data[1])))) {
      ex = FftS_data[1];
      idx = 2;
    } else {
      ex = FftS_data[0];
      idx = 1;
    }
  } else {
    f_st.site = &bb_emlrtRSI;
    if (!muDoubleScalarIsNaN(FftS_data[0])) {
      idx = 1;
    } else {
      idx = 0;
      g_st.site = &cb_emlrtRSI;
      if (FftS->size[1] > 2147483646) {
        h_st.site = &q_emlrtRSI;
        check_forloop_overflow_error(&h_st);
      }
      k = 2;
      exitg1 = false;
      while ((!exitg1) && (k <= nx)) {
        if (!muDoubleScalarIsNaN(FftS_data[k - 1])) {
          idx = k;
          exitg1 = true;
        } else {
          k++;
        }
      }
    }
    if (idx == 0) {
      ex = FftS_data[0];
      idx = 1;
    } else {
      f_st.site = &ab_emlrtRSI;
      ex = FftS_data[idx - 1];
      b_a = idx + 1;
      g_st.site = &db_emlrtRSI;
      overflow = ((idx + 1 <= FftS->size[1]) && (FftS->size[1] > 2147483646));
      if (overflow) {
        h_st.site = &q_emlrtRSI;
        check_forloop_overflow_error(&h_st);
      }
      for (k = b_a; k <= nx; k++) {
        d = FftS_data[k - 1];
        if (ex < d) {
          ex = d;
          idx = k;
        }
      }
    }
  }
  /*  maximum in the spectrum , where Am is the amplitude of the match , im is
   * the index in the array FftS starting from 1 and not from 0 */
  *f = ((real_T)idx - 1.0) * Fd / FftL;
  /*  calculating the tone frequency, im-1 because i starts at 1 and not at 0 */
  /*         %% Approximation of the residue frequency by the maximum of the
   * vector */
  hf = 0.01;
  ff = 0.0;
  /*  step and error optimized for speed, deviation ff reset */
  while (covrtLogWhile(&emlrtCoverageInstance, 1U, 0U, 0,
                       muDoubleScalarAbs(hf) > 1.0E-6)) {
    covrtLogBasicBlock(&emlrtCoverageInstance, 1U, 1U);
    /*  if the step did not reach the optimal error, then */
    *f += hf;
    /*  frequency is incremented by a step */
    sc = 0.0;
    ss = 0.0;
    /*  initial assignments to amounts */
    d = Tm * Fd;
    k = (int32_T)(d + 1.0);
    emlrtForLoopVectorCheckR2021a(0.0, 1.0, d, mxDOUBLE_CLASS,
                                  (int32_T)(d + 1.0), &i_emlrtRTEI,
                                  (emlrtCTX)sp);
    for (nx = 0; nx < k; nx++) {
      covrtLogFor(&emlrtCoverageInstance, 1U, 0U, 0, 1);
      covrtLogBasicBlock(&emlrtCoverageInstance, 1U, 2U);
      /*  number of time array indexes Tm*Fd+1 */
      d = *f * 360.0 * (real_T)nx / Fd;
      an = d;
      b_cosd(&an);
      if (((int32_T)(nx + 1U) < 1) || ((int32_T)(nx + 1U) > 250001)) {
        emlrtDynamicBoundsCheckR2012b((int32_T)(nx + 1U), 1, 250001,
                                      &e_emlrtBCI, (emlrtCTX)sp);
      }
      sc += Signal[nx] * an;
      /*  the first sum of the vector */
      c_sind(&d);
      if (((int32_T)(nx + 1U) < 1) || ((int32_T)(nx + 1U) > 250001)) {
        emlrtDynamicBoundsCheckR2012b((int32_T)(nx + 1U), 1, 250001,
                                      &f_emlrtBCI, (emlrtCTX)sp);
      }
      ss += Signal[nx] * d;
      /*  second vector sum */
      if (*emlrtBreakCheckR2012bFlagVar != 0) {
        emlrtBreakCheckR2012b((emlrtCTX)sp);
      }
    }
    covrtLogFor(&emlrtCoverageInstance, 1U, 0U, 0, 0);
    covrtLogBasicBlock(&emlrtCoverageInstance, 1U, 3U);
    st.site = &f_emlrtRSI;
    b_st.site = &eb_emlrtRSI;
    c_st.site = &fb_emlrtRSI;
    st.site = &f_emlrtRSI;
    b_st.site = &eb_emlrtRSI;
    c_st.site = &fb_emlrtRSI;
    an = sc * sc + ss * ss;
    /*  variance function - sum of squares of vector sums */
    if (covrtLogIf(&emlrtCoverageInstance, 1U, 0U, 0, an < ff)) {
      covrtLogBasicBlock(&emlrtCoverageInstance, 1U, 4U);
      /*  if the maximum value is skipped, then */
      hf = -hf / 2.0;
      /*  dividing by 2 and reversing the step in the opposite direction */
    }
    covrtLogBasicBlock(&emlrtCoverageInstance, 1U, 5U);
    ff = an;
    /*  the past sum is equal to the current one */
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  covrtLogBasicBlock(&emlrtCoverageInstance, 1U, 6U);
  /*  end of approximation in frequency */
  /*         %% Calculation of the amplitude and phase of the residue by the
   * vector method, provided that the frequency is known */
  hf = 0.0;
  ff = 0.0;
  ss = 0.0;
  yc = 0.0;
  ys = 0.0;
  /*  initial assignments to amounts */
  d = Fd * Tm;
  k = (int32_T)(d + 1.0);
  emlrtForLoopVectorCheckR2021a(0.0, 1.0, d, mxDOUBLE_CLASS, (int32_T)(d + 1.0),
                                &h_emlrtRTEI, (emlrtCTX)sp);
  for (nx = 0; nx < k; nx++) {
    covrtLogFor(&emlrtCoverageInstance, 1U, 0U, 1, 1);
    covrtLogBasicBlock(&emlrtCoverageInstance, 1U, 7U);
    /*  number of time array indexes */
    d = *f * 720.0 * (real_T)nx / Fd;
    c_sind(&d);
    hf += d / 2.0;
    /*  simplification cos(x)*sin(x)=sin(2*x)/2 */
    st.site = &g_emlrtRSI;
    an = *f * 360.0 * (real_T)nx / Fd;
    sc = an;
    b_cosd(&sc);
    b_st.site = &eb_emlrtRSI;
    c_st.site = &fb_emlrtRSI;
    ff += sc * sc;
    /*  time starts from zero, */
    st.site = &h_emlrtRSI;
    *a = an;
    c_sind(a);
    b_st.site = &eb_emlrtRSI;
    c_st.site = &fb_emlrtRSI;
    ss += *a * *a;
    /*  and the index starts from one */
    if (((int32_T)(nx + 1U) < 1) || ((int32_T)(nx + 1U) > 250001)) {
      emlrtDynamicBoundsCheckR2012b((int32_T)(nx + 1U), 1, 250001, &g_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    yc += Signal[nx] * sc;
    /*  so in sines and cosines is i */
    c_sind(&an);
    if (((int32_T)(nx + 1U) < 1) || ((int32_T)(nx + 1U) > 250001)) {
      emlrtDynamicBoundsCheckR2012b((int32_T)(nx + 1U), 1, 250001, &h_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    ys += Signal[nx] * an;
    /*  and the signal contains the index i + 1 */
    if (*emlrtBreakCheckR2012bFlagVar != 0) {
      emlrtBreakCheckR2012b((emlrtCTX)sp);
    }
  }
  covrtLogFor(&emlrtCoverageInstance, 1U, 0U, 1, 0);
  covrtLogBasicBlock(&emlrtCoverageInstance, 1U, 8U);
  /*  end of accumulation of sums for the matrix */
  /*  solution of a system of linear equations */
  /*  assigning sums to matrix A */
  /*  assign sums to matrix B */
  cc[0] = ff;
  cc[2] = hf;
  cc[1] = hf;
  cc[3] = ss;
  b_yc[0] = yc;
  b_yc[1] = ys;
  st.site = &i_emlrtRSI;
  mldivide(&st, cc, b_yc, X);
  /*  solution vector */
  d = 29999.0 * mz;
  if (1.0 > d) {
    nx = 0;
  } else {
    if (d != (int32_T)muDoubleScalarFloor(d)) {
      emlrtIntegerCheckR2012b(d, &g_emlrtDCI, (emlrtCTX)sp);
    }
    if (((int32_T)d < 1) || ((int32_T)d > FftS->size[1])) {
      emlrtDynamicBoundsCheckR2012b((int32_T)d, 1, FftS->size[1], &d_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    nx = (int32_T)d;
  }
  d = 30005.0 * mz;
  an = Fd * mz / 2.0;
  if (d > an) {
    k = 0;
    idx = 0;
  } else {
    if (d != (int32_T)muDoubleScalarFloor(d)) {
      emlrtIntegerCheckR2012b(d, &f_emlrtDCI, (emlrtCTX)sp);
    }
    if (((int32_T)d < 1) || ((int32_T)d > FftS->size[1])) {
      emlrtDynamicBoundsCheckR2012b((int32_T)d, 1, FftS->size[1], &c_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    k = (int32_T)d - 1;
    if (an != (int32_T)muDoubleScalarFloor(an)) {
      emlrtIntegerCheckR2012b(an, &e_emlrtDCI, (emlrtCTX)sp);
    }
    if (((int32_T)an < 1) || ((int32_T)an > FftS->size[1])) {
      emlrtDynamicBoundsCheckR2012b((int32_T)an, 1, FftS->size[1], &b_emlrtBCI,
                                    (emlrtCTX)sp);
    }
    idx = (int32_T)an;
  }
  emxInit_real_T(sp, &b_FftS, &q_emlrtRTEI);
  b_a = b_FftS->size[0] * b_FftS->size[1];
  b_FftS->size[0] = 1;
  b_FftS->size[1] = nx;
  emxEnsureCapacity_real_T(sp, b_FftS, b_a, &q_emlrtRTEI);
  b_FftS_data = b_FftS->data;
  for (b_a = 0; b_a < nx; b_a++) {
    b_FftS_data[b_a] = FftS_data[b_a];
  }
  emxInit_real_T(sp, &c_FftS, &r_emlrtRTEI);
  b_a = c_FftS->size[0] * c_FftS->size[1];
  c_FftS->size[0] = 1;
  nx = idx - k;
  c_FftS->size[1] = nx;
  emxEnsureCapacity_real_T(sp, c_FftS, b_a, &r_emlrtRTEI);
  b_FftS_data = c_FftS->data;
  for (idx = 0; idx < nx; idx++) {
    b_FftS_data[idx] = FftS_data[k + idx];
  }
  st.site = &j_emlrtRSI;
  an = (mean(&st, b_FftS) + mean(&st, c_FftS)) / 2.0;
  /*  average noise amplitude */
  st.site = &k_emlrtRSI;
  b_st.site = &eb_emlrtRSI;
  c_st.site = &fb_emlrtRSI;
  st.site = &k_emlrtRSI;
  b_st.site = &eb_emlrtRSI;
  c_st.site = &fb_emlrtRSI;
  st.site = &k_emlrtRSI;
  sc = X[0] * X[0] + X[1] * X[1];
  emxFree_real_T(&st, &c_FftS);
  emxFree_real_T(&st, &b_FftS);
  if (sc < 0.0) {
    emlrtErrorWithMessageIdR2018a(
        &st, &e_emlrtRTEI, "Coder:toolbox:ElFunDomainError",
        "Coder:toolbox:ElFunDomainError", 3, 4, 4, "sqrt");
  }
  sc = muDoubleScalarSqrt(sc);
  *a = sc - an;
  /*  subtraction signal amplitude */
  *p = 90.0 * (2.0 - muDoubleScalarSign(X[0])) -
       57.295779513082323 * muDoubleScalarAtan(1.0 / (X[0] / X[1]));
  /*  subtraction signal phase 0...360 */
  *Am = ex;
  emlrtHeapReferenceStackLeaveFcnR2012b((emlrtCTX)sp);
}

/* End of code generation (tone_search.c) */
