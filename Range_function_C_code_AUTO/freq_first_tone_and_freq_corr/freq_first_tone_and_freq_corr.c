/*
 * File: freq_first_tone_and_freq_corr.c
 *
 * MATLAB Coder version            : 3.3
 * C/C++ source code generated on  : 03-May-2023 17:42:44
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "freq_first_tone_and_freq_corr.h"

/* Function Definitions */

/*
 * UNTITLED11 Summary of this function goes here
 *    Detailed explanation goes here
 * Arguments    : const double FftS[45000000]
 *                double FftL
 *                double Fd
 * Return Type  : double
 */
double freq_first_tone_and_freq_corr(const double FftS[45000000], double FftL,
  double Fd)
{
  double f;
  int ixstart;
  double mtmp;
  int itmp;
  int ix;
  boolean_T exitg1;
  ixstart = 1;
  mtmp = FftS[0];
  itmp = 1;
  if (rtIsNaN(FftS[0])) {
    ix = 2;
    exitg1 = false;
    while ((!exitg1) && (ix < 45000001)) {
      ixstart = ix;
      if (!rtIsNaN(FftS[ix - 1])) {
        mtmp = FftS[ix - 1];
        itmp = ix;
        exitg1 = true;
      } else {
        ix++;
      }
    }
  }

  if (ixstart < 45000000) {
    while (ixstart + 1 < 45000001) {
      if (FftS[ixstart] > mtmp) {
        mtmp = FftS[ixstart];
        itmp = ixstart + 1;
      }

      ixstart++;
    }
  }

  /*  maximum in the spectrum , where Am is the amplitude of the match , im is the index in the array FftS starting from 1 and not from 0 */
  f = ((double)itmp - 1.0) * Fd / FftL;

  /*  calculating the frequency of the first tone, im-1 because i starts at 1 and not at 0 */
  return f;
}

/*
 * File trailer for freq_first_tone_and_freq_corr.c
 *
 * [EOF]
 */
