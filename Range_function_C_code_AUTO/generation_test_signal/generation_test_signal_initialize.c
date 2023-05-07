/*
 * File: generation_test_signal_initialize.c
 *
 * MATLAB Coder version            : 3.3
 * C/C++ source code generated on  : 03-May-2023 17:04:01
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "generation_test_signal.h"
#include "generation_test_signal_initialize.h"
#include "eml_rand_mt19937ar_stateful.h"

/* Function Definitions */

/*
 * Arguments    : void
 * Return Type  : void
 */
void generation_test_signal_initialize(void)
{
  rt_InitInfAndNaN(8U);
  c_eml_rand_mt19937ar_stateful_i();
}

/*
 * File trailer for generation_test_signal_initialize.c
 *
 * [EOF]
 */
