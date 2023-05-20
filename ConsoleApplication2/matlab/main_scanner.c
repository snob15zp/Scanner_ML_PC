/*
 * File: main_scanner.c
 *
 * MATLAB Coder version            : 5.3
 * C/C++ source code generated on  : 20-May-2023 21:00:38
 */

/* Include Files */
#include "main_scanner.h"
#include "filesave_ceval.h"
#include "main_scanner_emxutil.h"
#include "main_scanner_types.h"
#include "rt_nonfinite.h"
#include "sprintf.h"
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
 *                const double T[250001]
 *                double Signal[250001]
 *                double Out[300]
 *                emxArray_real_T *FftS
 * Return Type  : void
 */
void main_scanner(double Tm, double Fd, double mz, double FftL,
                  const double T[250001], double Signal[250001],
                  double Out[300], emxArray_real_T *FftS)
{
  static const char b_fn3[6] = {'s', 'i', 'g', 'n', 'a', 'l'};
  emxArray_char_T *fn3;
  emxArray_char_T *fn3a;
  emxArray_real_T *b_Signal;
  double Am;
  double a;
  double f;
  double p;
  double *FftS_data;
  int b_i;
  int i;
  int loop_ub_tmp;
  char *fn3_data;
  char *fn3a_data;
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
  emxInit_char_T(&fn3a);
  emxInit_char_T(&fn3);
  emxInit_real_T(&b_Signal, 2);
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
    b_sprintf(i + 1, fn3a);
    fn3a_data = fn3a->data;
    /* coder.varsize('ActVal1',[qblobs,DmaxSize]); */
    /* ActVal1(1:qblobs,:)=ActVal(1:qblobs,:); */
    b_i = fn3->size[0] * fn3->size[1];
    fn3->size[0] = 1;
    fn3->size[1] = fn3a->size[1] + 11;
    emxEnsureCapacity_char_T(fn3, b_i);
    fn3_data = fn3->data;
    for (b_i = 0; b_i < 6; b_i++) {
      fn3_data[b_i] = b_fn3[b_i];
    }
    loop_ub_tmp = fn3a->size[1];
    for (b_i = 0; b_i < loop_ub_tmp; b_i++) {
      fn3_data[b_i + 6] = fn3a_data[b_i];
    }
    fn3_data[fn3a->size[1] + 6] = '.';
    fn3_data[fn3a->size[1] + 7] = 't';
    fn3_data[fn3a->size[1] + 8] = 'x';
    fn3_data[fn3a->size[1] + 9] = 't';
    fn3_data[fn3a->size[1] + 10] = '\x00';
    b_i = b_Signal->size[0] * b_Signal->size[1];
    b_Signal->size[0] = 1;
    b_Signal->size[1] = 250001;
    emxEnsureCapacity_real_T(b_Signal, b_i);
    FftS_data = b_Signal->data;
    for (b_i = 0; b_i < 250001; b_i++) {
      FftS_data[b_i] = Signal[b_i];
    }
    filesave_ceval(b_Signal, fn3);
  }
  emxFree_real_T(&b_Signal);
  emxFree_char_T(&fn3);
  emxFree_char_T(&fn3a);
}

/*
 * File trailer for main_scanner.c
 *
 * [EOF]
 */
