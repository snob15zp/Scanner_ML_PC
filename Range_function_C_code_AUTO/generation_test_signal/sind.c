/*
 * File: sind.c
 *
 * MATLAB Coder version            : 3.3
 * C/C++ source code generated on  : 03-May-2023 17:04:01
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "generation_test_signal.h"
#include "sind.h"

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
 * Arguments    : emxArray_real_T *x
 * Return Type  : void
 */
void b_sind(emxArray_real_T *x)
{
  int nx;
  int k;
  double b_x;
  double absx;
  signed char n;
  nx = x->size[1];
  for (k = 0; k + 1 <= nx; k++) {
    if (!((!rtIsInf(x->data[k])) && (!rtIsNaN(x->data[k])))) {
      b_x = rtNaN;
    } else {
      b_x = rt_remd_snf(x->data[k], 360.0);
      absx = fabs(b_x);
      if (absx > 180.0) {
        if (b_x > 0.0) {
          b_x -= 360.0;
        } else {
          b_x += 360.0;
        }

        absx = fabs(b_x);
      }

      if (absx <= 45.0) {
        b_x *= 0.017453292519943295;
        n = 0;
      } else if (absx <= 135.0) {
        if (b_x > 0.0) {
          b_x = 0.017453292519943295 * (b_x - 90.0);
          n = 1;
        } else {
          b_x = 0.017453292519943295 * (b_x + 90.0);
          n = -1;
        }
      } else if (b_x > 0.0) {
        b_x = 0.017453292519943295 * (b_x - 180.0);
        n = 2;
      } else {
        b_x = 0.017453292519943295 * (b_x + 180.0);
        n = -2;
      }

      if (n == 0) {
        b_x = sin(b_x);
      } else if (n == 1) {
        b_x = cos(b_x);
      } else if (n == -1) {
        b_x = -cos(b_x);
      } else {
        b_x = -sin(b_x);
      }
    }

    x->data[k] = b_x;
  }
}

/*
 * File trailer for sind.c
 *
 * [EOF]
 */
