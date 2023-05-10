/*
 * File: main.c
 *
 * MATLAB Coder version            : 5.3
 * C/C++ source code generated on  : 10-May-2023 13:37:04
 */

/*************************************************************************/
/* This automatically generated example C main file shows how to call    */
/* entry-point functions that MATLAB Coder generated. You must customize */
/* this file for your application. Do not modify this file directly.     */
/* Instead, make a copy of this file, modify it, and integrate it into   */
/* your development environment.                                         */
/*                                                                       */
/* This file initializes entry-point function arguments to a default     */
/* size and value before calling the entry-point functions. It does      */
/* not store or use any values returned from the entry-point functions.  */
/* If necessary, it does pre-allocate memory for returned values.        */
/* You can use this file as a starting point for a main function that    */
/* you can deploy in your application.                                   */
/*                                                                       */
/* After you copy the file, and before you deploy it, you must make the  */
/* following changes:                                                    */
/* * For variable-size function arguments, change the example sizes to   */
/* the sizes that your application requires.                             */
/* * Change the example values of function arguments to the values that  */
/* your application requires.                                            */
/* * If the entry-point functions return values, store these values or   */
/* otherwise use them as required by your application.                   */
/*                                                                       */
/*************************************************************************/

/* Include Files */
#include "main.h"
#include "rt_nonfinite.h"
#include "tone_search.h"
#include "tone_search_emxAPI.h"
#include "tone_search_terminate.h"
#include "tone_search_types.h"
#include <string.h>

/* Function Declarations */
static void argInit_1x2500001_real_T(double result[2500001]);

static double argInit_real_T(void);

static void main_tone_search(void);

/* Function Definitions */
/*
 * Arguments    : double result[2500001]
 * Return Type  : void
 */
static void argInit_1x2500001_real_T(double result[2500001])
{
  int idx1;
  /* Loop over the array to initialize each element. */
  for (idx1 = 0; idx1 < 2500001; idx1++) {
    /* Set the value of the array element.
Change this value to the value that the application requires. */
    result[idx1] = argInit_real_T();
  }
}

/*
 * Arguments    : void
 * Return Type  : double
 */
static double argInit_real_T(void)
{
  return 0.0;
}

/*
 * Arguments    : void
 * Return Type  : void
 */
static void main_tone_search(void)
{
  static double T_tmp[2500001];
  static double b_T_tmp[2500001];
  emxArray_real_T *FftS;
  double Am;
  double Tm_tmp;
  double a;
  double f;
  double p;
  emxInitArray_real_T(&FftS, 2);
  /* Initialize function 'tone_search' input arguments. */
  Tm_tmp = argInit_real_T();
  /* Initialize function input argument 'T'. */
  argInit_1x2500001_real_T(T_tmp);
  /* Initialize function input argument 'Signal'. */
  /* Call the entry-point 'tone_search'. */
  a = Tm_tmp;
  f = Tm_tmp;
  p = Tm_tmp;
  memcpy(&b_T_tmp[0], &T_tmp[0], 2500001U * sizeof(double));
  tone_search(Tm_tmp, Tm_tmp, Tm_tmp, Tm_tmp, b_T_tmp, T_tmp, &a, &f, &p, FftS,
              &Am);
  emxDestroyArray_real_T(FftS);
}

/*
 * Arguments    : int argc
 *                char **argv
 * Return Type  : int
 */
int main(int argc, char **argv)
{
  (void)argc;
  (void)argv;
  /* The initialize function is being called automatically from your entry-point
   * function. So, a call to initialize is not included here. */
  /* Invoke the entry-point functions.
You can call entry-point functions multiple times. */
  main_tone_search();
  /* Terminate the application.
You do not need to do this more than one time. */
  tone_search_terminate();
  return 0;
}

/*
 * File trailer for main.c
 *
 * [EOF]
 */
