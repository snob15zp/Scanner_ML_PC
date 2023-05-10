/*
 * File: tone_search.h
 *
 * MATLAB Coder version            : 5.3
 * C/C++ source code generated on  : 10-May-2023 13:37:04
 */

#ifndef TONE_SEARCH_H
#define TONE_SEARCH_H

/* Include Files */
#include "rtwtypes.h"
#include "tone_search_types.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
extern void tone_search(double Tm, double Fd, double mz, double FftL,
                        const double T[2500001], double Signal[2500001],
                        double *a, double *f, double *p, emxArray_real_T *FftS,
                        double *Am);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for tone_search.h
 *
 * [EOF]
 */
