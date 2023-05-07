/*
 * File: calculation_second_tone_freq.c
 *
 * MATLAB Coder version            : 3.3
 * C/C++ source code generated on  : 03-May-2023 17:35:58
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "calculation_second_tone_freq.h"

/* Function Definitions */

/*
 * UNTITLED18 Summary of this function goes here
 *    Detailed explanation goes here
 * Arguments    : const double FftR[45000000]
 *                double Fd
 *                double FftL
 *                double *fv
 *                double *Am
 *                double *im
 * Return Type  : void
 */
void calculation_second_tone_freq(const double FftR[45000000], double Fd, double
  FftL, double *fv, double *Am, double *im)
{
  int ixstart;
  int itmp;
  int ix;
  boolean_T exitg1;
  ixstart = 1;
  *Am = FftR[0];
  itmp = 1;
  if (rtIsNaN(FftR[0])) {
    ix = 2;
    exitg1 = false;
    while ((!exitg1) && (ix < 45000001)) {
      ixstart = ix;
      if (!rtIsNaN(FftR[ix - 1])) {
        *Am = FftR[ix - 1];
        itmp = ix;
        exitg1 = true;
      } else {
        ix++;
      }
    }
  }

  if (ixstart < 45000000) {
    while (ixstart + 1 < 45000001) {
      if (FftR[ixstart] > *Am) {
        *Am = FftR[ixstart];
        itmp = ixstart + 1;
      }

      ixstart++;
    }
  }

  *im = itmp;

  /*  Maximum in the spectrum , where Am is the amplitude , im is the index in the array FftR starting from 1 and not from 0 */
  *fv = ((double)itmp - 1.0) * Fd / FftL;

  /*  calculating tone frequency 2 , im-1 because i starts at 1 and not at 0 */
}

/*
 * File trailer for calculation_second_tone_freq.c
 *
 * [EOF]
 */
