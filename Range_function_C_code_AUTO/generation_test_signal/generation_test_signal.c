/*
 * File: generation_test_signal.c
 *
 * MATLAB Coder version            : 3.3
 * C/C++ source code generated on  : 03-May-2023 17:04:01
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "generation_test_signal.h"
#include "generation_test_signal_emxutil.h"
#include "sind.h"
#include "randn.h"

/* Function Definitions */

/*
 * UNTITLED2 Summary of this function goes here
 *    Detailed explanation goes here
 * Arguments    : double Tm
 *                double Fd
 *                double mz
 *                double Ak
 *                double A1
 *                double A2
 *                double F1
 *                double F2
 *                double P1
 *                double P2
 *                double An
 *                emxArray_real_T *Signal
 *                emxArray_real_T *T
 *                double *FftL
 * Return Type  : void
 */
void generation_test_signal(double Tm, double Fd, double mz, double Ak, double
  A1, double A2, double F1, double F2, double P1, double P2, double An,
  emxArray_real_T *Signal, emxArray_real_T *T, double *FftL)
{
  double y;
  int k;
  double ndbl;
  double apnd;
  emxArray_real_T *b;
  double cdiff;
  int nm1d2;
  int n;
  emxArray_real_T *b_b;

  /*  number of FFT samples */
  y = 1.0 / Fd;
  if (rtIsNaN(y) || rtIsNaN(Tm)) {
    k = T->size[0] * T->size[1];
    T->size[0] = 1;
    T->size[1] = 1;
    emxEnsureCapacity((emxArray__common *)T, k, sizeof(double));
    T->data[0] = rtNaN;
  } else if ((y == 0.0) || ((0.0 < Tm) && (y < 0.0)) || ((Tm < 0.0) && (y > 0.0)))
  {
    k = T->size[0] * T->size[1];
    T->size[0] = 1;
    T->size[1] = 0;
    emxEnsureCapacity((emxArray__common *)T, k, sizeof(double));
  } else if (rtIsInf(Tm) && (rtIsInf(y) || (0.0 == Tm))) {
    k = T->size[0] * T->size[1];
    T->size[0] = 1;
    T->size[1] = 1;
    emxEnsureCapacity((emxArray__common *)T, k, sizeof(double));
    T->data[0] = rtNaN;
  } else if (rtIsInf(y)) {
    k = T->size[0] * T->size[1];
    T->size[0] = 1;
    T->size[1] = 1;
    emxEnsureCapacity((emxArray__common *)T, k, sizeof(double));
    T->data[0] = 0.0;
  } else if (floor(y) == y) {
    k = T->size[0] * T->size[1];
    T->size[0] = 1;
    T->size[1] = (int)floor(Tm / y) + 1;
    emxEnsureCapacity((emxArray__common *)T, k, sizeof(double));
    nm1d2 = (int)floor(Tm / y);
    for (k = 0; k <= nm1d2; k++) {
      T->data[T->size[0] * k] = y * (double)k;
    }
  } else {
    ndbl = floor(Tm / y + 0.5);
    apnd = ndbl * y;
    if (y > 0.0) {
      cdiff = apnd - Tm;
    } else {
      cdiff = Tm - apnd;
    }

    if (fabs(cdiff) < 4.4408920985006262E-16 * fabs(Tm)) {
      ndbl++;
      apnd = Tm;
    } else if (cdiff > 0.0) {
      apnd = (ndbl - 1.0) * y;
    } else {
      ndbl++;
    }

    if (ndbl >= 0.0) {
      n = (int)ndbl;
    } else {
      n = 0;
    }

    k = T->size[0] * T->size[1];
    T->size[0] = 1;
    T->size[1] = n;
    emxEnsureCapacity((emxArray__common *)T, k, sizeof(double));
    if (n > 0) {
      T->data[0] = 0.0;
      if (n > 1) {
        T->data[n - 1] = apnd;
        nm1d2 = (n - 1) / 2;
        for (k = 1; k < nm1d2; k++) {
          ndbl = (double)k * y;
          T->data[k] = ndbl;
          T->data[(n - k) - 1] = apnd - ndbl;
        }

        if (nm1d2 << 1 == n - 1) {
          T->data[nm1d2] = apnd / 2.0;
        } else {
          ndbl = (double)nm1d2 * y;
          T->data[nm1d2] = ndbl;
          T->data[nm1d2 + 1] = apnd - ndbl;
        }
      }
    }
  }

  emxInit_real_T(&b, 2);

  /*  Array of time samples */
  randn(T->size[1], b);

  /*  An array of random noise with a length equal to the array of time */
  k = Signal->size[0] * Signal->size[1];
  Signal->size[0] = 1;
  Signal->size[1] = T->size[1];
  emxEnsureCapacity((emxArray__common *)Signal, k, sizeof(double));
  ndbl = F1 * 360.0;
  nm1d2 = T->size[0] * T->size[1];
  for (k = 0; k < nm1d2; k++) {
    Signal->data[k] = ndbl * T->data[k] + P1;
  }

  emxInit_real_T(&b_b, 2);
  b_sind(Signal);
  k = b_b->size[0] * b_b->size[1];
  b_b->size[0] = 1;
  b_b->size[1] = T->size[1];
  emxEnsureCapacity((emxArray__common *)b_b, k, sizeof(double));
  ndbl = F2 * 360.0;
  nm1d2 = T->size[0] * T->size[1];
  for (k = 0; k < nm1d2; k++) {
    b_b->data[k] = ndbl * T->data[k] + P2;
  }

  b_sind(b_b);
  k = Signal->size[0] * Signal->size[1];
  Signal->size[0] = 1;
  emxEnsureCapacity((emxArray__common *)Signal, k, sizeof(double));
  nm1d2 = Signal->size[0];
  k = Signal->size[1];
  nm1d2 *= k;
  for (k = 0; k < nm1d2; k++) {
    Signal->data[k] = ((Ak + A1 * Signal->data[k]) + A2 * b_b->data[k]) + An *
      b->data[k];
  }

  emxFree_real_T(&b_b);
  emxFree_real_T(&b);

  /*  Signal array (mix of 2 tones + constant) */
  *FftL = Tm * Fd * mz;
}

/*
 * File trailer for generation_test_signal.c
 *
 * [EOF]
 */
