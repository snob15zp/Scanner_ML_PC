/*
 * File: _coder_tone_search_api.h
 *
 * MATLAB Coder version            : 5.3
 * C/C++ source code generated on  : 10-May-2023 18:07:25
 */

#ifndef _CODER_TONE_SEARCH_API_H
#define _CODER_TONE_SEARCH_API_H

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
void tone_search(real_T Tm, real_T Fd, real_T mz, real_T FftL,
                 real_T T[2500001], real_T Signal[2500001], real_T *a,
                 real_T *f, real_T *p, emxArray_real_T *FftS, real_T *Am);

void tone_search_api(const mxArray *const prhs[9], int32_T nlhs,
                     const mxArray *plhs[6]);

void tone_search_atexit(void);

void tone_search_initialize(void);

void tone_search_terminate(void);

void tone_search_xil_shutdown(void);

void tone_search_xil_terminate(void);

#ifdef __cplusplus
}
#endif

#endif
/*
 * File trailer for _coder_tone_search_api.h
 *
 * [EOF]
 */
