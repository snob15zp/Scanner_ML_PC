/*
 * File: main_scanner.h
 *
 * MATLAB Coder version            : 5.3
 * C/C++ source code generated on  : 20-May-2023 21:00:38
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
                         const double T[250001], double Signal[250001],
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
