/*
 * File: fft.c
 *
 * MATLAB Coder version            : 5.3
 * C/C++ source code generated on  : 14-May-2023 01:58:12
 */

/* Include Files */
#include "fft.h"
#include "FFTImplementationCallback.h"
#include "main_scanner_emxutil.h"
#include "main_scanner_types.h"
#include "rt_nonfinite.h"
#include <math.h>

/* Function Definitions */
/*
 * Arguments    : const double x[2500001]
 *                double varargin_1
 *                emxArray_creal_T *y
 * Return Type  : void
 */
void fft(const double x[2500001], double varargin_1, emxArray_creal_T *y)
{
  emxArray_creal_T *yCol;
  emxArray_real_T *costab;
  emxArray_real_T *costab1q;
  emxArray_real_T *sintab;
  emxArray_real_T *sintabinv;
  creal_T *yCol_data;
  creal_T *y_data;
  double temp_im;
  double temp_re;
  double temp_re_tmp;
  double twid_im;
  double twid_re;
  double *costab1q_data;
  double *costab_data;
  double *sintab_data;
  double *sintabinv_data;
  int b_temp_re_tmp;
  int i;
  int ihi;
  int j;
  int ju;
  int k;
  int nRowsD2;
  int pmax;
  int pmin;
  int pow2p;
  boolean_T exitg1;
  boolean_T useRadix2;
  if (0 == (int)varargin_1) {
    pow2p = y->size[0] * y->size[1];
    y->size[0] = 1;
    y->size[1] = (int)varargin_1;
    emxEnsureCapacity_creal_T(y, pow2p);
    y_data = y->data;
    pmax = (int)varargin_1;
    for (pow2p = 0; pow2p < pmax; pow2p++) {
      y_data[pow2p].re = 0.0;
      y_data[pow2p].im = 0.0;
    }
  } else {
    useRadix2 = (((int)varargin_1 > 0) &&
                 (((int)varargin_1 & ((int)varargin_1 - 1)) == 0));
    pmin = 1;
    if (useRadix2) {
      pmax = (int)varargin_1;
    } else {
      if ((int)varargin_1 > 0) {
        j = ((int)varargin_1 + (int)varargin_1) - 1;
        pmax = 31;
        if (j <= 1) {
          pmax = 0;
        } else {
          pmin = 0;
          exitg1 = false;
          while ((!exitg1) && (pmax - pmin > 1)) {
            k = (pmin + pmax) >> 1;
            pow2p = 1 << k;
            if (pow2p == j) {
              pmax = k;
              exitg1 = true;
            } else if (pow2p > j) {
              pmax = k;
            } else {
              pmin = k;
            }
          }
        }
        pmin = 1 << pmax;
      }
      pmax = pmin;
    }
    emxInit_real_T(&costab1q);
    temp_im = 6.2831853071795862 / (double)pmax;
    j = pmax / 2 / 2;
    pow2p = costab1q->size[0] * costab1q->size[1];
    costab1q->size[0] = 1;
    costab1q->size[1] = j + 1;
    emxEnsureCapacity_real_T(costab1q, pow2p);
    costab1q_data = costab1q->data;
    costab1q_data[0] = 1.0;
    pmax = j / 2 - 1;
    for (k = 0; k <= pmax; k++) {
      costab1q_data[k + 1] = cos(temp_im * ((double)k + 1.0));
    }
    pow2p = pmax + 2;
    pmax = j - 1;
    for (k = pow2p; k <= pmax; k++) {
      costab1q_data[k] = sin(temp_im * (double)(j - k));
    }
    costab1q_data[j] = 0.0;
    emxInit_real_T(&costab);
    emxInit_real_T(&sintab);
    emxInit_real_T(&sintabinv);
    if (!useRadix2) {
      j = costab1q->size[1] - 1;
      pmax = (costab1q->size[1] - 1) << 1;
      pow2p = costab->size[0] * costab->size[1];
      costab->size[0] = 1;
      costab->size[1] = pmax + 1;
      emxEnsureCapacity_real_T(costab, pow2p);
      costab_data = costab->data;
      pow2p = sintab->size[0] * sintab->size[1];
      sintab->size[0] = 1;
      sintab->size[1] = pmax + 1;
      emxEnsureCapacity_real_T(sintab, pow2p);
      sintab_data = sintab->data;
      costab_data[0] = 1.0;
      sintab_data[0] = 0.0;
      pow2p = sintabinv->size[0] * sintabinv->size[1];
      sintabinv->size[0] = 1;
      sintabinv->size[1] = pmax + 1;
      emxEnsureCapacity_real_T(sintabinv, pow2p);
      sintabinv_data = sintabinv->data;
      for (k = 0; k < j; k++) {
        sintabinv_data[k + 1] = costab1q_data[(j - k) - 1];
      }
      pow2p = costab1q->size[1];
      for (k = pow2p; k <= pmax; k++) {
        sintabinv_data[k] = costab1q_data[k - j];
      }
      for (k = 0; k < j; k++) {
        costab_data[k + 1] = costab1q_data[k + 1];
        sintab_data[k + 1] = -costab1q_data[(j - k) - 1];
      }
      pow2p = costab1q->size[1];
      for (k = pow2p; k <= pmax; k++) {
        costab_data[k] = -costab1q_data[pmax - k];
        sintab_data[k] = -costab1q_data[k - j];
      }
    } else {
      j = costab1q->size[1] - 1;
      pmax = (costab1q->size[1] - 1) << 1;
      pow2p = costab->size[0] * costab->size[1];
      costab->size[0] = 1;
      costab->size[1] = pmax + 1;
      emxEnsureCapacity_real_T(costab, pow2p);
      costab_data = costab->data;
      pow2p = sintab->size[0] * sintab->size[1];
      sintab->size[0] = 1;
      sintab->size[1] = pmax + 1;
      emxEnsureCapacity_real_T(sintab, pow2p);
      sintab_data = sintab->data;
      costab_data[0] = 1.0;
      sintab_data[0] = 0.0;
      for (k = 0; k < j; k++) {
        costab_data[k + 1] = costab1q_data[k + 1];
        sintab_data[k + 1] = -costab1q_data[(j - k) - 1];
      }
      pow2p = costab1q->size[1];
      for (k = pow2p; k <= pmax; k++) {
        costab_data[k] = -costab1q_data[pmax - k];
        sintab_data[k] = -costab1q_data[k - j];
      }
      sintabinv->size[0] = 1;
      sintabinv->size[1] = 0;
    }
    emxFree_real_T(&costab1q);
    emxInit_creal_T(&yCol, 1);
    if (useRadix2) {
      pow2p = yCol->size[0];
      yCol->size[0] = (int)varargin_1;
      emxEnsureCapacity_creal_T(yCol, pow2p);
      yCol_data = yCol->data;
      if ((int)varargin_1 > 2500001) {
        pow2p = yCol->size[0];
        yCol->size[0] = (int)varargin_1;
        emxEnsureCapacity_creal_T(yCol, pow2p);
        yCol_data = yCol->data;
        pmax = (int)varargin_1;
        for (pow2p = 0; pow2p < pmax; pow2p++) {
          yCol_data[pow2p].re = 0.0;
          yCol_data[pow2p].im = 0.0;
        }
      }
      if ((int)varargin_1 != 1) {
        c_FFTImplementationCallback_doH(x, yCol, (int)varargin_1, costab,
                                        sintab);
        yCol_data = yCol->data;
      } else {
        if (2500001 <= (int)varargin_1) {
          pmin = 2499999;
        } else {
          pmin = (int)varargin_1 - 2;
        }
        pow2p = (int)varargin_1 - 2;
        nRowsD2 = (int)varargin_1 / 2;
        k = nRowsD2 / 2;
        pmax = 0;
        ju = 0;
        for (i = 0; i <= pmin; i++) {
          yCol_data[pmax].re = x[i];
          yCol_data[pmax].im = 0.0;
          j = (int)varargin_1;
          useRadix2 = true;
          while (useRadix2) {
            j >>= 1;
            ju ^= j;
            useRadix2 = ((ju & j) == 0);
          }
          pmax = ju;
        }
        yCol_data[pmax].re = x[pmin + 1];
        yCol_data[pmax].im = 0.0;
        if ((int)varargin_1 > 1) {
          for (i = 0; i <= pow2p; i += 2) {
            temp_re_tmp = yCol_data[i + 1].re;
            temp_im = yCol_data[i + 1].im;
            temp_re = yCol_data[i].re;
            twid_re = yCol_data[i].im;
            yCol_data[i + 1].re = temp_re - temp_re_tmp;
            yCol_data[i + 1].im = twid_re - temp_im;
            yCol_data[i].re = temp_re + temp_re_tmp;
            yCol_data[i].im = twid_re + temp_im;
          }
        }
        pmax = 2;
        pmin = 4;
        pow2p = ((k - 1) << 2) + 1;
        while (k > 0) {
          for (i = 0; i < pow2p; i += pmin) {
            b_temp_re_tmp = i + pmax;
            temp_re = yCol_data[b_temp_re_tmp].re;
            temp_im = yCol_data[b_temp_re_tmp].im;
            yCol_data[b_temp_re_tmp].re = yCol_data[i].re - temp_re;
            yCol_data[b_temp_re_tmp].im = yCol_data[i].im - temp_im;
            yCol_data[i].re += temp_re;
            yCol_data[i].im += temp_im;
          }
          ju = 1;
          for (j = k; j < nRowsD2; j += k) {
            twid_re = costab_data[j];
            twid_im = sintab_data[j];
            i = ju;
            ihi = ju + pow2p;
            while (i < ihi) {
              b_temp_re_tmp = i + pmax;
              temp_re_tmp = yCol_data[b_temp_re_tmp].im;
              temp_im = yCol_data[b_temp_re_tmp].re;
              temp_re = twid_re * temp_im - twid_im * temp_re_tmp;
              temp_im = twid_re * temp_re_tmp + twid_im * temp_im;
              yCol_data[b_temp_re_tmp].re = yCol_data[i].re - temp_re;
              yCol_data[b_temp_re_tmp].im = yCol_data[i].im - temp_im;
              yCol_data[i].re += temp_re;
              yCol_data[i].im += temp_im;
              i += pmin;
            }
            ju++;
          }
          k /= 2;
          pmax = pmin;
          pmin += pmin;
          pow2p -= pmax;
        }
      }
    } else {
      c_FFTImplementationCallback_dob(x, pmin, (int)varargin_1, costab, sintab,
                                      sintabinv, yCol);
      yCol_data = yCol->data;
    }
    emxFree_real_T(&sintabinv);
    emxFree_real_T(&sintab);
    emxFree_real_T(&costab);
    pow2p = y->size[0] * y->size[1];
    y->size[0] = 1;
    y->size[1] = (int)varargin_1;
    emxEnsureCapacity_creal_T(y, pow2p);
    y_data = y->data;
    pmax = (int)varargin_1;
    for (pow2p = 0; pow2p < pmax; pow2p++) {
      y_data[pow2p] = yCol_data[pow2p];
    }
    emxFree_creal_T(&yCol);
  }
}

/*
 * File trailer for fft.c
 *
 * [EOF]
 */
