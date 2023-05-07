/*
 * File: calculation_amplitude_phase_vector_method.h
 *
 * MATLAB Coder version            : 3.3
 * C/C++ source code generated on  : 03-May-2023 17:58:10
 */

#ifndef CALCULATION_AMPLITUDE_PHASE_VECTOR_METHOD_H
#define CALCULATION_AMPLITUDE_PHASE_VECTOR_METHOD_H

/* Include Files */
#include <float.h>
#include <math.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "rt_nonfinite.h"
#include "rtwtypes.h"
#include "calculation_amplitude_phase_vector_method_types.h"

/* Function Declarations */
extern void calculation_amplitude_phase_vector_method(double Tm, double Fd,
  const double Signal[2250001], double FftL, const double FftS[45000000], const
  double T[2250001], double f, double *a, double *p, double RS[2250001],
  emxArray_real_T *FftR);

#endif

/*
 * File trailer for calculation_amplitude_phase_vector_method.h
 *
 * [EOF]
 */
