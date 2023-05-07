/*
 * File: approximation_freq_max_vector.c
 *
 * MATLAB Coder version            : 3.3
 * C/C++ source code generated on  : 03-May-2023 17:47:49
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "approximation_freq_max_vector.h"

/* Function Declarations */
static double rt_remd_snf(double u0, double u1);

/* Function Definitions */

/*
 * Arguments    : double u0
 *                double u1
 * Return Type  : double
 */
static double rt_remd_snf(double u0, double u1)
{
  double y;
  double b_u1;
  double q;
  if (!((!rtIsNaN(u0)) && (!rtIsInf(u0)) && ((!rtIsNaN(u1)) && (!rtIsInf(u1)))))
  {
    y = rtNaN;
  } else {
    if (u1 < 0.0) {
      b_u1 = ceil(u1);
    } else {
      b_u1 = floor(u1);
    }

    if ((u1 != 0.0) && (u1 != b_u1)) {
      q = fabs(u0 / u1);
      if (fabs(q - floor(q + 0.5)) <= DBL_EPSILON * q) {
        y = 0.0 * u0;
      } else {
        y = fmod(u0, u1);
      }
    } else {
      y = fmod(u0, u1);
    }
  }

  return y;
}

/*
 * UNTITLED13 Summary of this function goes here
 *    Detailed explanation goes here
 * Arguments    : double Tm
 *                double Fd
 *                const double Signal[2250001]
 *                double *f
 * Return Type  : void
 */
void approximation_freq_max_vector(double Tm, double Fd, const double Signal
  [2250001], double *f)
{
  double hf;
  double ff;
  double sc;
  double ss;
  double d0;
  int i;
  double s;
  double absx;
  signed char n;
  hf = 0.01;
  ff = 0.0;

  /*  step and accuracy are optimized for speed, deviation ff reset */
  while (fabs(hf) > 1.0E-6) {
    /*  if the step has not reached the optimal accuracy, then */
    *f += hf;

    /*  frequency is incremented by a step */
    sc = 0.0;
    ss = 0.0;

    /*  initial assignments to amounts */
    d0 = Tm * Fd;
    for (i = 0; i < (int)(d0 + 1.0); i++) {
      /*  number of time array indexes Tm*Fd+1 */
      s = *f * 360.0 * (double)i / Fd;
      if (!((!rtIsInf(s)) && (!rtIsNaN(s)))) {
        s = rtNaN;
      } else {
        s = rt_remd_snf(s, 360.0);
        absx = fabs(s);
        if (absx > 180.0) {
          if (s > 0.0) {
            s -= 360.0;
          } else {
            s += 360.0;
          }

          absx = fabs(s);
        }

        if (absx <= 45.0) {
          s *= 0.017453292519943295;
          n = 0;
        } else if (absx <= 135.0) {
          if (s > 0.0) {
            s = 0.017453292519943295 * (s - 90.0);
            n = 1;
          } else {
            s = 0.017453292519943295 * (s + 90.0);
            n = -1;
          }
        } else if (s > 0.0) {
          s = 0.017453292519943295 * (s - 180.0);
          n = 2;
        } else {
          s = 0.017453292519943295 * (s + 180.0);
          n = -2;
        }

        if (n == 0) {
          s = cos(s);
        } else if (n == 1) {
          s = -sin(s);
        } else if (n == -1) {
          s = sin(s);
        } else {
          s = -cos(s);
        }
      }

      sc += Signal[i] * s;

      /*  the first sum of the vector */
      s = *f * 360.0 * (double)i / Fd;
      if (!((!rtIsInf(s)) && (!rtIsNaN(s)))) {
        s = rtNaN;
      } else {
        s = rt_remd_snf(s, 360.0);
        absx = fabs(s);
        if (absx > 180.0) {
          if (s > 0.0) {
            s -= 360.0;
          } else {
            s += 360.0;
          }

          absx = fabs(s);
        }

        if (absx <= 45.0) {
          s *= 0.017453292519943295;
          n = 0;
        } else if (absx <= 135.0) {
          if (s > 0.0) {
            s = 0.017453292519943295 * (s - 90.0);
            n = 1;
          } else {
            s = 0.017453292519943295 * (s + 90.0);
            n = -1;
          }
        } else if (s > 0.0) {
          s = 0.017453292519943295 * (s - 180.0);
          n = 2;
        } else {
          s = 0.017453292519943295 * (s + 180.0);
          n = -2;
        }

        if (n == 0) {
          s = sin(s);
        } else if (n == 1) {
          s = cos(s);
        } else if (n == -1) {
          s = -cos(s);
        } else {
          s = -sin(s);
        }
      }

      ss += Signal[i] * s;

      /*  second vector sum */
    }

    s = sc * sc + ss * ss;

    /*  variance function - sum of squares of vector sums */
    if (s < ff) {
      /*  if the maximum value is skipped, then */
      hf = -hf / 2.0;

      /*  dividing by 2 and reversing the step in the opposite direction */
    }

    ff = s;

    /*  the past sum is equal to the current one */
  }

  /*  end of approximation in frequency */
}

/*
 * File trailer for approximation_freq_max_vector.c
 *
 * [EOF]
 */
