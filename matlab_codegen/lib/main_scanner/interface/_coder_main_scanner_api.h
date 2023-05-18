/*
 * File: _coder_main_scanner_api.h
 *
 * MATLAB Coder version            : 5.3
 * C/C++ source code generated on  : 18-May-2023 15:36:56
 */

#ifndef _CODER_MAIN_SCANNER_API_H
#define _CODER_MAIN_SCANNER_API_H

/* Include Files */
#include "emlrt.h"
#include "tmwtypes.h"
#include <string.h>

/* Type Definitions */
#ifndef struct_emxArray_real_T
#define struct_emxArray_real_T
struct emxArray_real_T {
  real_T *data;
  int32_T *size;
  int32_T allocatedSize;
  int32_T numDimensions;
  boolean_T canFreeData;
};
#endif /* struct_emxArray_real_T */
#ifndef typedef_emxArray_real_T
#define typedef_emxArray_real_T
typedef struct emxArray_real_T emxArray_real_T;
#endif /* typedef_emxArray_real_T */

/* Variable Declarations */
extern emlrtCTX emlrtRootTLSGlobal;
extern emlrtContext emlrtContextGlobal;

#ifdef __cplusplus
extern "C" {
#endif

/* Function Declarations */
void main_scanner(real_T Tm, real_T Fd, real_T mz, real_T FftL,
                  real_T T[2500001], real_T Signal[2500001], real_T Out[300],
                  emxArray_real_T *FftS);

void main_scanner_api(const mxArray *const prhs[6], int32_T nlhs,
                      const mxArray *plhs[2]);

void main_scanner_atexit(void);

void main_scanner_initialize(void);

void main_scanner_terminate(void);

void main_scanner_xil_shutdown(void);

void main_scanner_xil_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for _coder_main_scanner_api.h
 *
 * [EOF]
 */
