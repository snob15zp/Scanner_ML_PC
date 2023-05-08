/*
 * File: calculation_amplitude_phase_vector_method.h
 *
 * MATLAB Coder version            : 5.3
 * C/C++ source code generated on  : 08-May-2023 14:46:01
 */

#ifndef CALCULATION_AMPLITUDE_PHASE_VECTOR_METHOD_H
#define CALCULATION_AMPLITUDE_PHASE_VECTOR_METHOD_H

/* Include Files */
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
void c_calculation_amplitude_phase_v(const double Signal[2250001],
                                     const double FftS[45000000],
                                     const double T[2250001], double f,
                                     double *a, double *p, double RS[2250001],
                                     double FftR[45000000]);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for calculation_amplitude_phase_vector_method.h
 *
 * [EOF]
 */
