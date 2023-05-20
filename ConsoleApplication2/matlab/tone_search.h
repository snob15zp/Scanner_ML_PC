/*
 * File: tone_search.h
 *
 * MATLAB Coder version            : 5.3
 * C/C++ source code generated on  : 20-May-2023 21:00:38
 */

#ifndef TONE_SEARCH_H
#define TONE_SEARCH_H

/* Include Files */
#include "main_scanner_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
void tone_search(double Tm, double Fd, double mz, double FftL,
                 const double T[250001], double Signal[250001], double *a,
                 double *f, double *p, emxArray_real_T *FftS, double *Am);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for tone_search.h
 *
 * [EOF]
 */
