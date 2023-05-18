/*
 * File: main_scanner.c
 *
 * MATLAB Coder version            : 5.3
 * C/C++ source code generated on  : 18-May-2023 15:36:56
 */

/* Include Files */
#include "main_scanner.h"
#include "main_scanner_emxutil.h"
#include "main_scanner_types.h"
#include "rt_nonfinite.h"
#include "tone_search.h"
#include <string.h>

/* Function Definitions */
/*
 * scanner function
 *
 * Arguments    : double Tm
 *                double Fd
 *                double mz
 *                double FftL
 *                const double T[2500001]
 *                double Signal[2500001]
 *                double Out[300]
 *                emxArray_real_T *FftS
 * Return Type  : void
 */
void main_scanner(double Tm, double Fd, double mz, double FftL,
                  const double T[2500001], double Signal[2500001],
                  double Out[300], emxArray_real_T *FftS)
{
  double Am;
  double a;
  double f;
  double p;
  double *FftS_data;
  int b_i;
  int i;
  int loop_ub_tmp;
  Am = 1.0;
  a = 0.0;
  f = 0.0;
  p = 0.0;
  i = -1;
  /*  initial assignments to enter the search and subtract tone loop */
  memset(&Out[0], 0, 300U * sizeof(double));
  b_i = FftS->size[0] * FftS->size[1];
  FftS->size[0] = 1;
  loop_ub_tmp = (int)FftL;
  FftS->size[1] = (int)FftL;
  emxEnsureCapacity_real_T(FftS, b_i);
  FftS_data = FftS->data;
  for (b_i = 0; b_i < loop_ub_tmp; b_i++) {
    FftS_data[b_i] = 0.0;
  }
  /*         %% The main cycle of searching and subtracting the tone of maximum
   * amplitude */
  while (Am > 0.001) {
    /*  if the amplitude of the subtraction is greater than the specified
     * threshold , then we look for and subtract the next tone */
    tone_search(Tm, Fd, mz, FftL, T, Signal, &a, &f, &p, FftS, &Am);
    /*  tone search and subtraction function */
    i++;
    Out[3 * i] = a;
    Out[3 * i + 1] = f;
    Out[3 * i + 2] = p;
    /*  fill the output array : amplitude , frequency , phase */
  }
}

/*
 * File trailer for main_scanner.c
 *
 * [EOF]
 */
