/*
 * File: eml_randn.c
 *
 * MATLAB Coder version            : 5.3
 * C/C++ source code generated on  : 08-May-2023 14:46:01
 */

/* Include Files */
#include "eml_randn.h"
#include "main_file_test_data.h"
#include "rt_nonfinite.h"

/* Function Definitions */
/*
 * Arguments    : void
 * Return Type  : void
 */
void eml_randn_init(void)
{
  method = 0U;
  state[0] = 362436069U;
  state[1] = 521288629U;
}

/*
 * File trailer for eml_randn.c
 *
 * [EOF]
 */
