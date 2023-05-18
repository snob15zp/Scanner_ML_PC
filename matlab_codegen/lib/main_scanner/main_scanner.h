/*
 * File: main_scanner.h
 *
 * MATLAB Coder version            : 5.3
 * C/C++ source code generated on  : 18-May-2023 15:36:56
 */

#ifndef MAIN_SCANNER_H
#define MAIN_SCANNER_H

/* Include Files */
#include "main_scanner_types.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
extern void main_scanner(double Tm, double Fd, double mz, double FftL,
                         const double T[2500001], double Signal[2500001],
                         double Out[300], emxArray_real_T *FftS);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for main_scanner.h
 *
 * [EOF]
 */
