/*
 * File: sind.c
 *
 * MATLAB Coder version            : 3.3
 * C/C++ source code generated on  : 03-May-2023 17:58:10
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "calculation_amplitude_phase_vector_method.h"
#include "sind.h"
#include "calculation_amplitude_phase_vector_method_rtwutil.h"

/* Function Definitions */

/*
 * Arguments    : double *x
 * Return Type  : void
 */
void b_sind(double *x)
{
  double absx;
  signed char n;
  if (!((!rtIsInf(*x)) && (!rtIsNaN(*x)))) {
    *x = rtNaN;
  } else {
    *x = rt_remd_snf(*x, 360.0);
    absx = fabs(*x);
    if (absx > 180.0) {
      if (*x > 0.0) {
        *x -= 360.0;
      } else {
        *x += 360.0;
      }

      absx = fabs(*x);
    }

    if (absx <= 45.0) {
      *x *= 0.017453292519943295;
      n = 0;
    } else if (absx <= 135.0) {
      if (*x > 0.0) {
        *x = 0.017453292519943295 * (*x - 90.0);
        n = 1;
      } else {
        *x = 0.017453292519943295 * (*x + 90.0);
        n = -1;
      }
    } else if (*x > 0.0) {
      *x = 0.017453292519943295 * (*x - 180.0);
      n = 2;
    } else {
      *x = 0.017453292519943295 * (*x + 180.0);
      n = -2;
    }

    if (n == 0) {
      *x = sin(*x);
    } else if (n == 1) {
      *x = cos(*x);
    } else if (n == -1) {
      *x = -cos(*x);
    } else {
      *x = -sin(*x);
    }
  }
}

/*
 * File trailer for sind.c
 *
 * [EOF]
 */
