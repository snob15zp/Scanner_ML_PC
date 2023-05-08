/*
 * File: fft.c
 *
 * MATLAB Coder version            : 5.3
 * C/C++ source code generated on  : 08-May-2023 14:46:01
 */

/* Include Files */
#include "fft.h"
#include "FFTImplementationCallback.h"
#include "rt_nonfinite.h"
#include <math.h>

/* Function Definitions */
/*
 * Arguments    : const double x[2250001]
 *                creal_T y[45000000]
 * Return Type  : void
 */
void fft(const double x[2250001], creal_T y[45000000])
{
  static double costab[67108865];
  static double sintab[67108865];
  static double sintabinv[67108865];
  static double costab1q[33554433];
  double b_sintabinv_tmp;
  double sintabinv_tmp;
  int k;
  costab1q[0] = 1.0;
  for (k = 0; k < 16777216; k++) {
    costab1q[k + 1] = cos(4.6813378536549108E-8 * ((double)k + 1.0));
  }
  for (k = 0; k < 16777215; k++) {
    costab1q[k + 16777217] = sin(4.6813378536549108E-8 *
                                 (3.3554432E+7 - ((double)k + 1.6777217E+7)));
  }
  costab1q[33554432] = 0.0;
  costab[0] = 1.0;
  sintab[0] = 0.0;
  for (k = 0; k < 33554432; k++) {
    sintabinv_tmp = costab1q[33554431 - k];
    sintabinv[k + 1] = sintabinv_tmp;
    b_sintabinv_tmp = costab1q[k + 1];
    sintabinv[k + 33554433] = b_sintabinv_tmp;
    costab[k + 1] = b_sintabinv_tmp;
    sintab[k + 1] = -sintabinv_tmp;
    costab[k + 33554433] = -sintabinv_tmp;
    sintab[k + 33554433] = -b_sintabinv_tmp;
  }
  c_FFTImplementationCallback_dob(x, costab, sintab, sintabinv, y);
}

/*
 * File trailer for fft.c
 *
 * [EOF]
 */
