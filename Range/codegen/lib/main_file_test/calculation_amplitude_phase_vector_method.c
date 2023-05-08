/*
 * File: calculation_amplitude_phase_vector_method.c
 *
 * MATLAB Coder version            : 5.3
 * C/C++ source code generated on  : 08-May-2023 13:56:17
 */

/* Include Files */
#include "calculation_amplitude_phase_vector_method.h"
#include "cosd.h"
#include "fft.h"
#include "main_file_test_rtwutil.h"
#include "rt_nonfinite.h"
#include "sind.h"
#include <math.h>

/* Function Definitions */
/*
 * UNTITLED15 Summary of this function goes here
 *    Detailed explanation goes here
 *
 * Arguments    : const double Signal[2250001]
 *                const double FftS[45000000]
 *                const double T[2250001]
 *                double f
 *                double *a
 *                double *p
 *                double RS[2250001]
 *                double FftR[45000000]
 * Return Type  : void
 */
void c_calculation_amplitude_phase_v(const double Signal[2250001],
                                     const double FftS[45000000],
                                     const double T[2250001], double f,
                                     double *a, double *p, double RS[2250001],
                                     double FftR[45000000])
{
  static creal_T x[45000000];
  double A[4];
  double B[2];
  double a_tmp;
  double a_tmp_tmp;
  double cc;
  double cs;
  double d;
  double ss;
  double yc;
  double ys;
  int hi;
  int r1;
  int r2;
  int xblockoffset;
  cs = 0.0;
  cc = 0.0;
  ss = 0.0;
  yc = 0.0;
  ys = 0.0;
  /*  initial assignments to amounts */
  for (r1 = 0; r1 < 2250001; r1++) {
    /*  number of time array indexes */
    d = f * 720.0 * (double)r1 / 2.5E+6;
    c_sind(&d);
    cs += d / 2.0;
    /*  simplification cos(x)*sin(x)=sin(2*x)/2 */
    a_tmp_tmp = f * 360.0 * (double)r1 / 2.5E+6;
    a_tmp = a_tmp_tmp;
    b_cosd(&a_tmp);
    cc += a_tmp * a_tmp;
    /*  time starts from zero, */
    c_sind(&a_tmp_tmp);
    ss += a_tmp_tmp * a_tmp_tmp;
    /*  and the index starts from one */
    d = Signal[r1];
    yc += d * a_tmp;
    /*  so in sines and cosines is i */
    ys += d * a_tmp_tmp;
    /*  and the signal contains the index i + 1 */
  }
  /*  end of accumulation of sums for the matrix */
  A[0] = cc;
  A[2] = cs;
  A[1] = cs;
  A[3] = ss;
  /*  solution of a system of linear equations (SLE) */
  /*  assigning sums to matrix A */
  B[0] = yc;
  B[1] = ys;
  /*  assign sums to matrix B */
  if (fabs(cs) > fabs(cc)) {
    r1 = 1;
    r2 = 0;
  } else {
    r1 = 0;
    r2 = 1;
  }
  cs = A[r2] / A[r1];
  cc = A[r1 + 2];
  yc = (B[r2] - B[r1] * cs) / (A[r2 + 2] - cs * cc);
  ss = (B[r1] - yc * cc) / A[r1];
  /*  SLE decision vector */
  cc = FftS[0];
  for (r1 = 0; r1 < 1023; r1++) {
    cc += FftS[r1 + 1];
  }
  for (r2 = 0; r2 < 43945; r2++) {
    xblockoffset = (r2 + 1) << 10;
    cs = FftS[xblockoffset];
    if (r2 + 2 == 43946) {
      hi = 320;
    } else {
      hi = 1024;
    }
    for (r1 = 2; r1 <= hi; r1++) {
      cs += FftS[(xblockoffset + r1) - 1];
    }
    cc += cs;
  }
  *a = sqrt(ss * ss + yc * yc) - cc / 4.5E+7;
  /*  subtraction signal amplitude */
  cs = ss / yc;
  if (ss < 0.0) {
    ss = -1.0;
  } else if (ss > 0.0) {
    ss = 1.0;
  } else if (ss == 0.0) {
    ss = 0.0;
  }
  if (yc < 0.0) {
    yc = -1.0;
  } else if (yc > 0.0) {
    yc = 1.0;
  } else if (yc == 0.0) {
    yc = 0.0;
  }
  *p = ss * (57.295779513082323 * acos(yc / sqrt(cs * cs + 1.0)) - 180.0) +
       180.0;
  /*  subtraction signal phase 0...360 */
  cs = f * 360.0;
  for (r1 = 0; r1 < 2250001; r1++) {
    RS[r1] = cs * T[r1] + *p;
  }
  b_sind(RS);
  for (r1 = 0; r1 < 2250001; r1++) {
    RS[r1] = Signal[r1] - *a * RS[r1];
  }
  /*  calculate the difference signal */
  fft(RS, x);
  /*  difference signal match amplitude */
  for (r1 = 0; r1 < 45000000; r1++) {
    FftR[r1] = 2.0 * rt_hypotd_snf(x[r1].re, x[r1].im) / 4.5E+7;
  }
  /*  Spectrum normalization by amplitude */
}

/*
 * File trailer for calculation_amplitude_phase_vector_method.c
 *
 * [EOF]
 */
