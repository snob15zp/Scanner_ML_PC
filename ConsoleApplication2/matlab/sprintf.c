/*
 * File: sprintf.c
 *
 * MATLAB Coder version            : 5.3
 * C/C++ source code generated on  : 20-May-2023 21:00:38
 */

/* Include Files */
#include "sprintf.h"
#include "main_scanner_emxutil.h"
#include "main_scanner_types.h"
#include "rt_nonfinite.h"
#include <stddef.h>
#include <stdio.h>

/* Function Definitions */
/*
 * Arguments    : int varargin_1
 *                emxArray_char_T *str
 * Return Type  : void
 */
void b_sprintf(int varargin_1, emxArray_char_T *str)
{
  int i;
  int nbytes;
  char *str_data;
  nbytes = snprintf(NULL, 0, "%i", varargin_1);
  i = str->size[0] * str->size[1];
  str->size[0] = 1;
  str->size[1] = nbytes + 1;
  emxEnsureCapacity_char_T(str, i);
  str_data = str->data;
  snprintf(&str_data[0], (size_t)(nbytes + 1), "%i", varargin_1);
  i = str->size[0] * str->size[1];
  if (1 > nbytes) {
    str->size[1] = 0;
  } else {
    str->size[1] = nbytes;
  }
  emxEnsureCapacity_char_T(str, i);
}

/*
 * File trailer for sprintf.c
 *
 * [EOF]
 */
