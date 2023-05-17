/*
 * File: FFTImplementationCallback.h
 *
 * MATLAB Coder version            : 5.3
 * C/C++ source code generated on  : 14-May-2023 01:58:12
 */

#ifndef FFTIMPLEMENTATIONCALLBACK_H
#define FFTIMPLEMENTATIONCALLBACK_H

/* Include Files */
#include "main_scanner_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
void c_FFTImplementationCallback_doH(const double x[2500001],
                                     emxArray_creal_T *y, int unsigned_nRows,
                                     const emxArray_real_T *costab,
                                     const emxArray_real_T *sintab);

void c_FFTImplementationCallback_dob(const double x[2500001], int n2blue,
                                     int nfft, const emxArray_real_T *costab,
                                     const emxArray_real_T *sintab,
                                     const emxArray_real_T *sintabinv,
                                     emxArray_creal_T *y);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for FFTImplementationCallback.h
 *
 * [EOF]
 */
