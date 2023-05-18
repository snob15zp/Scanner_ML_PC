/*
 * File: tone_search.c
 *
 * MATLAB Coder version            : 5.3
 * C/C++ source code generated on  : 18-May-2023 15:36:56
 */

/* Include Files */
#include "tone_search.h"
#include "cosd.h"
#include "fft.h"
#include "main_scanner_emxutil.h"
#include "main_scanner_rtwutil.h"
#include "main_scanner_types.h"
#include "mean.h"
#include "rt_nonfinite.h"
#include "sind.h"
#include "rt_nonfinite.h"
#include <math.h>

/* Function Declarations */
static double rt_hypotd_snf(double u0, double u1);

/* Function Definitions */
/*
 * Arguments    : double u0
 *                double u1
 * Return Type  : double
 */
static double rt_hypotd_snf(double u0, double u1)
{
  double a;
  double y;
  a = fabs(u0);
  y = fabs(u1);
  if (a < y) {
    a /= y;
    y *= sqrt(a * a + 1.0);
  } else if (a > y) {
    y /= a;
    y = a * sqrt(y * y + 1.0);
  } else if (!rtIsNaN(y)) {
    y = a * 1.4142135623730951;
  }
  return y;
}

/*
 * search and delete tones function
 *
 * Arguments    : double Tm
 *                double Fd
 *                double mz
 *                double FftL
 *                const double T[2500001]
 *                double Signal[2500001]
 *                double *a
 *                double *f
 *                double *p
 *                emxArray_real_T *FftS
 *                double *Am
 * Return Type  : void
 */
void tone_search(double Tm, double Fd, double mz, double FftL,
                 const double T[2500001], double Signal[2500001], double *a,
                 double *f, double *p, emxArray_real_T *FftS, double *Am)
{
  emxArray_creal_T *x;
  emxArray_real_T *b_FftS;
  emxArray_real_T *c_FftS;
  creal_T *x_data;
  double A[4];
  double B[2];
  double absx;
  double cc;
  double d;
  double ex;
  double ff;
  double hf;
  double ss;
  double yc;
  double ys;
  double *FftS_data;
  double *b_FftS_data;
  int i;
  int k;
  int last;
  int nx;
  signed char n;
  boolean_T exitg1;
  *f *= 360.0;
  for (k = 0; k < 2500001; k++) {
    d = *f * T[k] + *p;
    if (rtIsInf(d) || rtIsNaN(d)) {
      d = rtNaN;
    } else {
      hf = rt_remd_snf(d, 360.0);
      absx = fabs(hf);
      if (absx > 180.0) {
        if (hf > 0.0) {
          hf -= 360.0;
        } else {
          hf += 360.0;
        }
        absx = fabs(hf);
      }
      if (absx <= 45.0) {
        hf *= 0.017453292519943295;
        n = 0;
      } else if (absx <= 135.0) {
        if (hf > 0.0) {
          hf = 0.017453292519943295 * (hf - 90.0);
          n = 1;
        } else {
          hf = 0.017453292519943295 * (hf + 90.0);
          n = -1;
        }
      } else if (hf > 0.0) {
        hf = 0.017453292519943295 * (hf - 180.0);
        n = 2;
      } else {
        hf = 0.017453292519943295 * (hf + 180.0);
        n = -2;
      }
      if (n == 0) {
        d = sin(hf);
      } else if (n == 1) {
        d = cos(hf);
      } else if (n == -1) {
        d = -cos(hf);
      } else {
        d = -sin(hf);
      }
    }
    Signal[k] -= *a * d;
  }
  emxInit_creal_T(&x, 2);
  /*  calculate the difference signal */
  /*         %% Spectral representation of the input signal */
  fft(Signal, FftL, x);
  x_data = x->data;
  nx = x->size[1];
  i = FftS->size[0] * FftS->size[1];
  FftS->size[0] = 1;
  FftS->size[1] = x->size[1];
  emxEnsureCapacity_real_T(FftS, i);
  FftS_data = FftS->data;
  for (k = 0; k < nx; k++) {
    FftS_data[k] = rt_hypotd_snf(x_data[k].re, x_data[k].im);
  }
  emxFree_creal_T(&x);
  /*  signal Fourier transform amplitude */
  i = FftS->size[0] * FftS->size[1];
  FftS->size[0] = 1;
  emxEnsureCapacity_real_T(FftS, i);
  FftS_data = FftS->data;
  last = FftS->size[1] - 1;
  for (i = 0; i <= last; i++) {
    FftS_data[i] = 2.0 * FftS_data[i] / FftL;
  }
  /*  amplitude normalization of the spectrum */
  /*         %% Tone frequency search and calculation */
  last = FftS->size[1];
  if (FftS->size[1] <= 2) {
    if (FftS->size[1] == 1) {
      ex = FftS_data[0];
      nx = 1;
    } else if ((FftS_data[0] < FftS_data[FftS->size[1] - 1]) ||
               (rtIsNaN(FftS_data[0]) &&
                (!rtIsNaN(FftS_data[FftS->size[1] - 1])))) {
      ex = FftS_data[FftS->size[1] - 1];
      nx = FftS->size[1];
    } else {
      ex = FftS_data[0];
      nx = 1;
    }
  } else {
    if (!rtIsNaN(FftS_data[0])) {
      nx = 1;
    } else {
      nx = 0;
      k = 2;
      exitg1 = false;
      while ((!exitg1) && (k <= last)) {
        if (!rtIsNaN(FftS_data[k - 1])) {
          nx = k;
          exitg1 = true;
        } else {
          k++;
        }
      }
    }
    if (nx == 0) {
      ex = FftS_data[0];
      nx = 1;
    } else {
      ex = FftS_data[nx - 1];
      i = nx + 1;
      for (k = i; k <= last; k++) {
        d = FftS_data[k - 1];
        if (ex < d) {
          ex = d;
          nx = k;
        }
      }
    }
  }
  /*  maximum in the spectrum , where Am is the amplitude of the match , im is
   * the index in the array FftS starting from 1 and not from 0 */
  *f = ((double)nx - 1.0) * Fd / FftL;
  /*  calculating the tone frequency, im-1 because i starts at 1 and not at 0 */
  /*         %% Approximation of the residue frequency by the maximum of the
   * vector */
  hf = 0.01;
  ff = 0.0;
  /*  step and error optimized for speed, deviation ff reset */
  while (fabs(hf) > 1.0E-6) {
    /*  if the step did not reach the optimal error, then */
    *f += hf;
    /*  frequency is incremented by a step */
    absx = 0.0;
    ss = 0.0;
    /*  initial assignments to amounts */
    i = (int)(Tm * Fd + 1.0);
    for (nx = 0; nx < i; nx++) {
      /*  number of time array indexes Tm*Fd+1 */
      d = *f * 360.0 * (double)nx / Fd;
      cc = d;
      b_cosd(&cc);
      absx += Signal[nx] * cc;
      /*  the first sum of the vector */
      b_sind(&d);
      ss += Signal[nx] * d;
      /*  second vector sum */
    }
    absx = absx * absx + ss * ss;
    /*  variance function - sum of squares of vector sums */
    if (absx < ff) {
      /*  if the maximum value is skipped, then */
      hf = -hf / 2.0;
      /*  dividing by 2 and reversing the step in the opposite direction */
    }
    ff = absx;
    /*  the past sum is equal to the current one */
  }
  /*  end of approximation in frequency */
  /*         %% Calculation of the amplitude and phase of the residue by the
   * vector method, provided that the frequency is known */
  ff = 0.0;
  cc = 0.0;
  ss = 0.0;
  yc = 0.0;
  ys = 0.0;
  /*  initial assignments to amounts */
  i = (int)(Fd * Tm + 1.0);
  for (nx = 0; nx < i; nx++) {
    /*  number of time array indexes */
    d = *f * 720.0 * (double)nx / Fd;
    b_sind(&d);
    ff += d / 2.0;
    /*  simplification cos(x)*sin(x)=sin(2*x)/2 */
    absx = *f * 360.0 * (double)nx / Fd;
    hf = absx;
    b_cosd(&hf);
    cc += hf * hf;
    /*  time starts from zero, */
    *a = absx;
    b_sind(a);
    ss += *a * *a;
    /*  and the index starts from one */
    yc += Signal[nx] * hf;
    /*  so in sines and cosines is i */
    b_sind(&absx);
    ys += Signal[nx] * absx;
    /*  and the signal contains the index i + 1 */
  }
  /*  end of accumulation of sums for the matrix */
  A[0] = cc;
  A[2] = ff;
  A[1] = ff;
  A[3] = ss;
  /*  solution of a system of linear equations */
  /*  assigning sums to matrix A */
  B[0] = yc;
  B[1] = ys;
  /*  assign sums to matrix B */
  if (fabs(ff) > fabs(cc)) {
    nx = 1;
    last = 0;
  } else {
    nx = 0;
    last = 1;
  }
  absx = A[last] / A[nx];
  hf = A[nx + 2];
  ff = (B[last] - B[nx] * absx) / (A[last + 2] - absx * hf);
  absx = (B[nx] - ff * hf) / A[nx];
  /*  solution vector */
  d = 299990.0 * mz;
  if (1.0 > d) {
    last = 0;
  } else {
    last = (int)d;
  }
  d = 300050.0 * mz;
  cc = Fd * mz / 2.0;
  if (d > cc) {
    i = 0;
    nx = 0;
  } else {
    i = (int)d - 1;
    nx = (int)cc;
  }
  emxInit_real_T(&b_FftS, 2);
  /*  average noise amplitude */
  k = b_FftS->size[0] * b_FftS->size[1];
  b_FftS->size[0] = 1;
  b_FftS->size[1] = last;
  emxEnsureCapacity_real_T(b_FftS, k);
  b_FftS_data = b_FftS->data;
  for (k = 0; k < last; k++) {
    b_FftS_data[k] = FftS_data[k];
  }
  emxInit_real_T(&c_FftS, 2);
  k = c_FftS->size[0] * c_FftS->size[1];
  c_FftS->size[0] = 1;
  last = nx - i;
  c_FftS->size[1] = last;
  emxEnsureCapacity_real_T(c_FftS, k);
  b_FftS_data = c_FftS->data;
  for (nx = 0; nx < last; nx++) {
    b_FftS_data[nx] = FftS_data[i + nx];
  }
  *a = sqrt(absx * absx + ff * ff) - (mean(b_FftS) + mean(c_FftS)) / 2.0;
  /*  subtraction signal amplitude */
  hf = absx;
  emxFree_real_T(&c_FftS);
  emxFree_real_T(&b_FftS);
  if (absx < 0.0) {
    hf = -1.0;
  } else if (absx > 0.0) {
    hf = 1.0;
  } else if (absx == 0.0) {
    hf = 0.0;
  }
  *p = 90.0 * (2.0 - hf) - 57.295779513082323 * atan(1.0 / (absx / ff));
  /*  subtraction signal phase 0...360 */
  *Am = ex;
}

/*
 * File trailer for tone_search.c
 *
 * [EOF]
 */
