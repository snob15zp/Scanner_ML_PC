/*
 * File: main_file_test.c
 *
 * MATLAB Coder version            : 5.3
 * C/C++ source code generated on  : 08-May-2023 13:56:17
 */

/* Include Files */
#include "main_file_test.h"
#include "calculation_amplitude_phase_vector_method.h"
#include "cosd.h"
#include "fft.h"
#include "generation_test_signal.h"
#include "main_file_test_data.h"
#include "main_file_test_initialize.h"
#include "main_file_test_rtwutil.h"
#include "rt_nonfinite.h"
#include "sind.h"
#include "rt_nonfinite.h"
#include <math.h>

/* Function Definitions */
/*
 * UNTITLED2 Summary of this function goes here
 *    Detailed explanation goes here
 *
 * Arguments    : void
 * Return Type  : void
 */
void main_file_test(void)
{
  static creal_T x[45000000];
  static double FftR[45000000];
  static double FftS[45000000];
  static double RS[2250001];
  static double Signal[2250001];
  static double T[2250001];
  double d;
  double d1;
  double d2;
  double f;
  double ff;
  double hf;
  double sc;
  double ss;
  int i;
  int idx;
  int k;
  boolean_T exitg1;
  if (!isInitialized_main_file_test) {
    main_file_test_initialize();
  }
  /*  Functions that are skipped during C code generation */
  /*  %% Parameters unchanged (set by the customer) */
  /*  Duration of the measured signal (s) */
  /*  Sampling frequency (Hz) */
  /*  zero padding multiplier - limited by the speed of the customer's computer
   */
  /*     %% Parameters changeable (input signal) */
  /*  DC */
  /*  Amplitude of the first tone */
  /*  Amplitude of the second tone */
  /*  First tone frequency (Hz) */
  /*  Second tone frequency (Hz) */
  /*  Initial phase of the first tone (Degrees) */
  /*  Initial phase of the second tone (Degrees) */
  /*  noise level */
  /*     %% Generation of working arrays (input signal) */
  generation_test_signal(Signal, T);
  /* -------------------------------- Signal */
  /*  Create a new window */
  /*  Building a signal */
  /*  time interval on the x-axis */
  /*  Graph caption */
  /*  Plot x-axis label */
  /*  Chart y-axis label */
  /*     %% Spectral representation of the input signal */
  /* UNTITLED7 Summary of this function goes here */
  /*    Detailed explanation goes here */
  fft(Signal, x);
  /*  Signal Fourier Transform Amplitudes */
  for (k = 0; k < 45000000; k++) {
    FftS[k] = 2.0 * rt_hypotd_snf(x[k].re, x[k].im) / 4.5E+7;
  }
  /*  Spectrum normalization by amplitude */
  FftS[0] /= 2.0;
  /*  Normalization of the constant component in the spectrum */
  /* -------------------------------- Range */
  /*  Create a new window */
  /*  Array of frequencies of the calculated spectrum */
  /*  draw... */
  /*  X-axis frequency interval */
  /*  Graph caption */
  /*  Chart x-axis label */
  /*  Chart y-axis label */
  /*     %% Search for the frequency of the first tone and calculate the
   * frequency correction factor */
  /* UNTITLED11 Summary of this function goes here */
  /*    Detailed explanation goes here */
  if (!rtIsNaN(FftS[0])) {
    idx = 1;
  } else {
    idx = 0;
    k = 2;
    exitg1 = false;
    while ((!exitg1) && (k < 45000001)) {
      if (!rtIsNaN(FftS[k - 1])) {
        idx = k;
        exitg1 = true;
      } else {
        k++;
      }
    }
  }
  if (idx == 0) {
    idx = 1;
  } else {
    ss = FftS[idx - 1];
    i = idx + 1;
    for (k = i; k < 45000001; k++) {
      d = FftS[k - 1];
      if (ss < d) {
        ss = d;
        idx = k;
      }
    }
  }
  /*  maximum in the spectrum , where Am is the amplitude of the match , im is
   * the index in the array FftS starting from 1 and not from 0 */
  f = ((double)idx - 1.0) * 2.5E+6 / 4.5E+7;
  /*  calculating the frequency of the first tone, im-1 because i starts at 1
   * and not at 0 */
  /*     %% Approximation of the residue frequency by the maximum of the vector
   */
  /* UNTITLED13 Summary of this function goes here */
  /*    Detailed explanation goes here */
  hf = 0.01;
  ff = 0.0;
  /*  step and accuracy are optimized for speed, deviation ff reset */
  while (fabs(hf) > 1.0E-6) {
    /*  if the step has not reached the optimal accuracy, then */
    f += hf;
    /*  frequency is incremented by a step */
    sc = 0.0;
    ss = 0.0;
    /*  initial assignments to amounts */
    for (k = 0; k < 2250001; k++) {
      /*  number of time array indexes Tm*Fd+1 */
      d = f * 360.0 * (double)k / 2.5E+6;
      d1 = d;
      b_cosd(&d1);
      d2 = Signal[k];
      sc += d2 * d1;
      /*  the first sum of the vector */
      c_sind(&d);
      ss += d2 * d;
      /*  second vector sum */
    }
    ss = sc * sc + ss * ss;
    /*  variance function - sum of squares of vector sums */
    if (ss < ff) {
      /*  if the maximum value is skipped, then */
      hf = -hf / 2.0;
      /*  dividing by 2 and reversing the step in the opposite direction */
    }
    ff = ss;
    /*  the past sum is equal to the current one */
  }
  /*  end of approximation in frequency */
  /*     %% Calculation of the amplitude and phase by the vector method,
   * provided that the frequency is known */
  c_calculation_amplitude_phase_v(Signal, FftS, T, f, &ss, &sc, RS, FftR);
  /* -------------------------------- Signal */
  /*  Create a new window */
  /*  Construction - difference signal */
  /*  time interval on the x-axis */
  /*  Graph caption */
  /*  Plot x-axis label */
  /*  Chart y-axis label */
  /* -------------------------------- Range */
  /*  Create a new window */
  /*  Array of frequencies of the calculated spectrum */
  /*  draw... */
  /*  X-axis frequency interval */
  /*  Graph caption */
  /*  Chart x-axis label */
  /*  Chart y-axis label */
  /*     %% Second tone frequency calculation */
  /*  results in absolute errors to the input data */
}

/*
 * File trailer for main_file_test.c
 *
 * [EOF]
 */
