/*
 * File: calculation_amplitude_phase_vector_method_rtwutil.c
 *
 * MATLAB Coder version            : 3.3
 * C/C++ source code generated on  : 03-May-2023 17:58:10
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "calculation_amplitude_phase_vector_method.h"
#include "calculation_amplitude_phase_vector_method_rtwutil.h"

/* Function Definitions */

/*
 * Arguments    : double u0
 *                double u1
 * Return Type  : double
 */
double rt_remd_snf(double u0, double u1)
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
 * File trailer for calculation_amplitude_phase_vector_method_rtwutil.c
 *
 * [EOF]
 */
