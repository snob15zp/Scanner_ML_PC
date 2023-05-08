/*
 * File: generation_test_signal.c
 *
 * MATLAB Coder version            : 5.3
 * C/C++ source code generated on  : 08-May-2023 13:56:17
 */

/* Include Files */
#include "generation_test_signal.h"
#include "randn.h"
#include "rt_nonfinite.h"
#include "sind.h"

/* Function Definitions */
/*
 * UNTITLED2 Summary of this function goes here
 *    Detailed explanation goes here
 *
 * Arguments    : double Signal[2250001]
 *                double T[2250001]
 * Return Type  : void
 */
void generation_test_signal(double Signal[2250001], double T[2250001])
{
  static double b[2250001];
  static double dv[2250001];
  double kd;
  int k;
  /*  number of FFT samples */
  T[0] = 0.0;
  T[2250000] = 0.9;
  for (k = 0; k < 1124999; k++) {
    kd = ((double)k + 1.0) * 4.0E-7;
    T[k + 1] = kd;
    T[2249999 - k] = 0.9 - kd;
  }
  T[1125000] = 0.45;
  /*  Array of time samples */
  randn(b);
  /*  An array of random noise with a length equal to the array of time */
  for (k = 0; k < 2250001; k++) {
    Signal[k] = 1.08E+8 * T[k] + 237.0;
  }
  b_sind(Signal);
  for (k = 0; k < 2250001; k++) {
    dv[k] = 1.0800036E+8 * T[k];
  }
  b_sind(dv);
  for (k = 0; k < 2250001; k++) {
    Signal[k] = (Signal[k] + 5.0E-7 * dv[k]) + 7.0E-5 * b[k];
  }
  /*  Signal array (mix of 2 tones + constant) */
}

/*
 * File trailer for generation_test_signal.c
 *
 * [EOF]
 */
