/*
 * File: calculation_amplitude_phase_vector_method.c
 *
 * MATLAB Coder version            : 3.3
 * C/C++ source code generated on  : 03-May-2023 17:58:10
 */

/* Include Files */
#include "rt_nonfinite.h"
#include "calculation_amplitude_phase_vector_method.h"
#include "sind.h"
#include "cosd.h"
#include "calculation_amplitude_phase_vector_method_emxutil.h"
#include "calculation_amplitude_phase_vector_method_rtwutil.h"

/* Function Declarations */
static void dobluesteinfft(const double x[2250001], int N2, int n1, const
  emxArray_real_T *costab, const emxArray_real_T *sintab, const emxArray_real_T *
  sintabinv, emxArray_creal_T *y);
static void eml_fft(const double x[2250001], int n, emxArray_creal_T *y);
static void r2br_r2dit_trig_impl(const emxArray_creal_T *x, int unsigned_nRows,
  const emxArray_real_T *costab, const emxArray_real_T *sintab, emxArray_creal_T
  *y);
static double rt_hypotd_snf(double u0, double u1);

/* Function Definitions */

/*
 * Arguments    : const double x[2250001]
 *                int N2
 *                int n1
 *                const emxArray_real_T *costab
 *                const emxArray_real_T *sintab
 *                const emxArray_real_T *sintabinv
 *                emxArray_creal_T *y
 * Return Type  : void
 */
static void dobluesteinfft(const double x[2250001], int N2, int n1, const
  emxArray_real_T *costab, const emxArray_real_T *sintab, const emxArray_real_T *
  sintabinv, emxArray_creal_T *y)
{
  emxArray_creal_T *wwc;
  int nInt2m1;
  int nInt2;
  int idx;
  int rt;
  int j;
  int ihi;
  double twid_im;
  double r;
  emxArray_creal_T *fy;
  emxArray_creal_T *fv;
  int nRowsD2;
  int nRowsD4;
  int i;
  boolean_T tst;
  double temp_re;
  double temp_im;
  double fv_re;
  double fv_im;
  double wwc_im;
  double b_fv_re;
  emxInit_creal_T(&wwc, 1);
  nInt2m1 = (n1 + n1) - 1;
  nInt2 = wwc->size[0];
  wwc->size[0] = nInt2m1;
  emxEnsureCapacity((emxArray__common *)wwc, nInt2, sizeof(creal_T));
  idx = n1;
  rt = 0;
  wwc->data[n1 - 1].re = 1.0;
  wwc->data[n1 - 1].im = 0.0;
  nInt2 = n1 << 1;
  for (j = 1; j < n1; j++) {
    ihi = (j << 1) - 1;
    if (nInt2 - rt <= ihi) {
      rt += ihi - nInt2;
    } else {
      rt += ihi;
    }

    twid_im = -3.1415926535897931 * (double)rt / (double)n1;
    if (twid_im == 0.0) {
      r = 1.0;
      twid_im = 0.0;
    } else {
      r = cos(twid_im);
      twid_im = sin(twid_im);
    }

    wwc->data[idx - 2].re = r;
    wwc->data[idx - 2].im = -twid_im;
    idx--;
  }

  idx = 0;
  for (j = nInt2m1 - 1; j >= n1; j--) {
    wwc->data[j] = wwc->data[idx];
    idx++;
  }

  if (n1 < 2250001) {
    rt = n1;
  } else {
    rt = 2250001;
  }

  nInt2 = y->size[0];
  y->size[0] = n1;
  emxEnsureCapacity((emxArray__common *)y, nInt2, sizeof(creal_T));
  if (n1 > 2250001) {
    ihi = y->size[0];
    nInt2 = y->size[0];
    y->size[0] = ihi;
    emxEnsureCapacity((emxArray__common *)y, nInt2, sizeof(creal_T));
    for (nInt2 = 0; nInt2 < ihi; nInt2++) {
      y->data[nInt2].re = 0.0;
      y->data[nInt2].im = 0.0;
    }
  }

  idx = 0;
  for (j = 0; j + 1 <= rt; j++) {
    r = wwc->data[(n1 + j) - 1].re;
    twid_im = wwc->data[(n1 + j) - 1].im;
    y->data[j].re = r * x[idx];
    y->data[j].im = twid_im * -x[idx];
    idx++;
  }

  while (rt + 1 <= n1) {
    y->data[rt].re = 0.0;
    y->data[rt].im = 0.0;
    rt++;
  }

  emxInit_creal_T(&fy, 1);
  r2br_r2dit_trig_impl(y, N2, costab, sintab, fy);
  nInt2m1 = wwc->size[0];
  if (!(nInt2m1 < N2)) {
    nInt2m1 = N2;
  }

  emxInit_creal_T(&fv, 1);
  nRowsD2 = N2 / 2;
  nRowsD4 = nRowsD2 / 2;
  nInt2 = fv->size[0];
  fv->size[0] = N2;
  emxEnsureCapacity((emxArray__common *)fv, nInt2, sizeof(creal_T));
  if (N2 > wwc->size[0]) {
    idx = fv->size[0];
    nInt2 = fv->size[0];
    fv->size[0] = idx;
    emxEnsureCapacity((emxArray__common *)fv, nInt2, sizeof(creal_T));
    for (nInt2 = 0; nInt2 < idx; nInt2++) {
      fv->data[nInt2].re = 0.0;
      fv->data[nInt2].im = 0.0;
    }
  }

  rt = 0;
  nInt2 = 0;
  idx = 0;
  for (i = 1; i < nInt2m1; i++) {
    fv->data[idx] = wwc->data[rt];
    idx = N2;
    tst = true;
    while (tst) {
      idx >>= 1;
      nInt2 ^= idx;
      tst = ((nInt2 & idx) == 0);
    }

    idx = nInt2;
    rt++;
  }

  fv->data[idx] = wwc->data[rt];
  if (N2 > 1) {
    for (i = 0; i <= N2 - 2; i += 2) {
      temp_re = fv->data[i + 1].re;
      temp_im = fv->data[i + 1].im;
      fv->data[i + 1].re = fv->data[i].re - fv->data[i + 1].re;
      fv->data[i + 1].im = fv->data[i].im - fv->data[i + 1].im;
      fv->data[i].re += temp_re;
      fv->data[i].im += temp_im;
    }
  }

  idx = 2;
  rt = 4;
  nInt2 = 1 + ((nRowsD4 - 1) << 2);
  while (nRowsD4 > 0) {
    for (i = 0; i < nInt2; i += rt) {
      temp_re = fv->data[i + idx].re;
      temp_im = fv->data[i + idx].im;
      fv->data[i + idx].re = fv->data[i].re - temp_re;
      fv->data[i + idx].im = fv->data[i].im - temp_im;
      fv->data[i].re += temp_re;
      fv->data[i].im += temp_im;
    }

    nInt2m1 = 1;
    for (j = nRowsD4; j < nRowsD2; j += nRowsD4) {
      r = costab->data[j];
      twid_im = sintab->data[j];
      i = nInt2m1;
      ihi = nInt2m1 + nInt2;
      while (i < ihi) {
        temp_re = r * fv->data[i + idx].re - twid_im * fv->data[i + idx].im;
        temp_im = r * fv->data[i + idx].im + twid_im * fv->data[i + idx].re;
        fv->data[i + idx].re = fv->data[i].re - temp_re;
        fv->data[i + idx].im = fv->data[i].im - temp_im;
        fv->data[i].re += temp_re;
        fv->data[i].im += temp_im;
        i += rt;
      }

      nInt2m1++;
    }

    nRowsD4 /= 2;
    idx = rt;
    rt += rt;
    nInt2 -= idx;
  }

  nInt2 = fy->size[0];
  emxEnsureCapacity((emxArray__common *)fy, nInt2, sizeof(creal_T));
  idx = fy->size[0];
  for (nInt2 = 0; nInt2 < idx; nInt2++) {
    r = fy->data[nInt2].re;
    twid_im = fy->data[nInt2].im;
    fv_re = fv->data[nInt2].re;
    fv_im = fv->data[nInt2].im;
    fy->data[nInt2].re = r * fv_re - twid_im * fv_im;
    fy->data[nInt2].im = r * fv_im + twid_im * fv_re;
  }

  nInt2m1 = fy->size[0];
  if (!(nInt2m1 < N2)) {
    nInt2m1 = N2;
  }

  nRowsD2 = N2 / 2;
  nRowsD4 = nRowsD2 / 2;
  nInt2 = fv->size[0];
  fv->size[0] = N2;
  emxEnsureCapacity((emxArray__common *)fv, nInt2, sizeof(creal_T));
  if (N2 > fy->size[0]) {
    idx = fv->size[0];
    nInt2 = fv->size[0];
    fv->size[0] = idx;
    emxEnsureCapacity((emxArray__common *)fv, nInt2, sizeof(creal_T));
    for (nInt2 = 0; nInt2 < idx; nInt2++) {
      fv->data[nInt2].re = 0.0;
      fv->data[nInt2].im = 0.0;
    }
  }

  rt = 0;
  nInt2 = 0;
  idx = 0;
  for (i = 1; i < nInt2m1; i++) {
    fv->data[idx] = fy->data[rt];
    idx = N2;
    tst = true;
    while (tst) {
      idx >>= 1;
      nInt2 ^= idx;
      tst = ((nInt2 & idx) == 0);
    }

    idx = nInt2;
    rt++;
  }

  fv->data[idx] = fy->data[rt];
  emxFree_creal_T(&fy);
  if (N2 > 1) {
    for (i = 0; i <= N2 - 2; i += 2) {
      temp_re = fv->data[i + 1].re;
      temp_im = fv->data[i + 1].im;
      fv->data[i + 1].re = fv->data[i].re - fv->data[i + 1].re;
      fv->data[i + 1].im = fv->data[i].im - fv->data[i + 1].im;
      fv->data[i].re += temp_re;
      fv->data[i].im += temp_im;
    }
  }

  idx = 2;
  rt = 4;
  nInt2 = 1 + ((nRowsD4 - 1) << 2);
  while (nRowsD4 > 0) {
    for (i = 0; i < nInt2; i += rt) {
      temp_re = fv->data[i + idx].re;
      temp_im = fv->data[i + idx].im;
      fv->data[i + idx].re = fv->data[i].re - temp_re;
      fv->data[i + idx].im = fv->data[i].im - temp_im;
      fv->data[i].re += temp_re;
      fv->data[i].im += temp_im;
    }

    nInt2m1 = 1;
    for (j = nRowsD4; j < nRowsD2; j += nRowsD4) {
      r = costab->data[j];
      twid_im = sintabinv->data[j];
      i = nInt2m1;
      ihi = nInt2m1 + nInt2;
      while (i < ihi) {
        temp_re = r * fv->data[i + idx].re - twid_im * fv->data[i + idx].im;
        temp_im = r * fv->data[i + idx].im + twid_im * fv->data[i + idx].re;
        fv->data[i + idx].re = fv->data[i].re - temp_re;
        fv->data[i + idx].im = fv->data[i].im - temp_im;
        fv->data[i].re += temp_re;
        fv->data[i].im += temp_im;
        i += rt;
      }

      nInt2m1++;
    }

    nRowsD4 /= 2;
    idx = rt;
    rt += rt;
    nInt2 -= idx;
  }

  if (fv->size[0] > 1) {
    r = 1.0 / (double)fv->size[0];
    nInt2 = fv->size[0];
    emxEnsureCapacity((emxArray__common *)fv, nInt2, sizeof(creal_T));
    idx = fv->size[0];
    for (nInt2 = 0; nInt2 < idx; nInt2++) {
      fv->data[nInt2].re *= r;
      fv->data[nInt2].im *= r;
    }
  }

  idx = 0;
  for (j = n1 - 1; j + 1 <= wwc->size[0]; j++) {
    r = wwc->data[j].re;
    fv_re = fv->data[j].re;
    twid_im = wwc->data[j].im;
    fv_im = fv->data[j].im;
    temp_re = wwc->data[j].re;
    temp_im = fv->data[j].im;
    wwc_im = wwc->data[j].im;
    b_fv_re = fv->data[j].re;
    y->data[idx].re = r * fv_re + twid_im * fv_im;
    y->data[idx].im = temp_re * temp_im - wwc_im * b_fv_re;
    idx++;
  }

  emxFree_creal_T(&fv);
  emxFree_creal_T(&wwc);
}

/*
 * Arguments    : const double x[2250001]
 *                int n
 *                emxArray_creal_T *y
 * Return Type  : void
 */
static void eml_fft(const double x[2250001], int n, emxArray_creal_T *y)
{
  boolean_T useRadix2;
  int pmax;
  int pmin;
  int nn1m1;
  emxArray_real_T *costab1q;
  double e;
  int nRowsD4;
  boolean_T exitg1;
  int b_n;
  int pow2p;
  emxArray_real_T *costab;
  emxArray_real_T *sintab;
  emxArray_real_T *sintabinv;
  int nRowsD2;
  int i;
  double temp_re;
  double temp_im;
  double twid_im;
  int ihi;
  if (n == 0) {
    pmax = y->size[0];
    y->size[0] = 0;
    emxEnsureCapacity((emxArray__common *)y, pmax, sizeof(creal_T));
  } else {
    useRadix2 = ((!(n <= 0)) && ((n & (n - 1)) == 0));
    pmin = 1;
    if (useRadix2) {
      nn1m1 = n;
    } else {
      if (n > 0) {
        nn1m1 = (n + n) - 1;
        pmax = 31;
        if (nn1m1 <= 1) {
          pmax = 0;
        } else {
          pmin = 0;
          exitg1 = false;
          while ((!exitg1) && (pmax - pmin > 1)) {
            b_n = (pmin + pmax) >> 1;
            pow2p = 1 << b_n;
            if (pow2p == nn1m1) {
              pmax = b_n;
              exitg1 = true;
            } else if (pow2p > nn1m1) {
              pmax = b_n;
            } else {
              pmin = b_n;
            }
          }
        }

        pmin = 1 << pmax;
      }

      nn1m1 = pmin;
    }

    emxInit_real_T(&costab1q, 2);
    e = 6.2831853071795862 / (double)nn1m1;
    nRowsD4 = nn1m1 / 2 / 2;
    pmax = costab1q->size[0] * costab1q->size[1];
    costab1q->size[0] = 1;
    costab1q->size[1] = nRowsD4 + 1;
    emxEnsureCapacity((emxArray__common *)costab1q, pmax, sizeof(double));
    costab1q->data[0] = 1.0;
    nn1m1 = nRowsD4 / 2;
    for (pmax = 1; pmax <= nn1m1; pmax++) {
      costab1q->data[pmax] = cos(e * (double)pmax);
    }

    for (pmax = nn1m1 + 1; pmax < nRowsD4; pmax++) {
      costab1q->data[pmax] = sin(e * (double)(nRowsD4 - pmax));
    }

    costab1q->data[nRowsD4] = 0.0;
    emxInit_real_T(&costab, 2);
    emxInit_real_T(&sintab, 2);
    emxInit_real_T(&sintabinv, 2);
    if (!useRadix2) {
      b_n = costab1q->size[1] - 1;
      nn1m1 = (costab1q->size[1] - 1) << 1;
      pmax = costab->size[0] * costab->size[1];
      costab->size[0] = 1;
      costab->size[1] = nn1m1 + 1;
      emxEnsureCapacity((emxArray__common *)costab, pmax, sizeof(double));
      pmax = sintab->size[0] * sintab->size[1];
      sintab->size[0] = 1;
      sintab->size[1] = nn1m1 + 1;
      emxEnsureCapacity((emxArray__common *)sintab, pmax, sizeof(double));
      costab->data[0] = 1.0;
      sintab->data[0] = 0.0;
      pmax = sintabinv->size[0] * sintabinv->size[1];
      sintabinv->size[0] = 1;
      sintabinv->size[1] = nn1m1 + 1;
      emxEnsureCapacity((emxArray__common *)sintabinv, pmax, sizeof(double));
      for (pmax = 1; pmax <= b_n; pmax++) {
        sintabinv->data[pmax] = costab1q->data[b_n - pmax];
      }

      for (pmax = costab1q->size[1]; pmax <= nn1m1; pmax++) {
        sintabinv->data[pmax] = costab1q->data[pmax - b_n];
      }

      for (pmax = 1; pmax <= b_n; pmax++) {
        costab->data[pmax] = costab1q->data[pmax];
        sintab->data[pmax] = -costab1q->data[b_n - pmax];
      }

      for (pmax = costab1q->size[1]; pmax <= nn1m1; pmax++) {
        costab->data[pmax] = -costab1q->data[nn1m1 - pmax];
        sintab->data[pmax] = -costab1q->data[pmax - b_n];
      }
    } else {
      b_n = costab1q->size[1] - 1;
      nn1m1 = (costab1q->size[1] - 1) << 1;
      pmax = costab->size[0] * costab->size[1];
      costab->size[0] = 1;
      costab->size[1] = nn1m1 + 1;
      emxEnsureCapacity((emxArray__common *)costab, pmax, sizeof(double));
      pmax = sintab->size[0] * sintab->size[1];
      sintab->size[0] = 1;
      sintab->size[1] = nn1m1 + 1;
      emxEnsureCapacity((emxArray__common *)sintab, pmax, sizeof(double));
      costab->data[0] = 1.0;
      sintab->data[0] = 0.0;
      for (pmax = 1; pmax <= b_n; pmax++) {
        costab->data[pmax] = costab1q->data[pmax];
        sintab->data[pmax] = -costab1q->data[b_n - pmax];
      }

      for (pmax = costab1q->size[1]; pmax <= nn1m1; pmax++) {
        costab->data[pmax] = -costab1q->data[nn1m1 - pmax];
        sintab->data[pmax] = -costab1q->data[pmax - b_n];
      }

      pmax = sintabinv->size[0] * sintabinv->size[1];
      sintabinv->size[0] = 1;
      sintabinv->size[1] = 0;
      emxEnsureCapacity((emxArray__common *)sintabinv, pmax, sizeof(double));
    }

    emxFree_real_T(&costab1q);
    if (useRadix2) {
      if (2250001 < n) {
        pow2p = 2250001;
      } else {
        pow2p = n;
      }

      nRowsD2 = n / 2;
      nRowsD4 = nRowsD2 / 2;
      pmax = y->size[0];
      y->size[0] = n;
      emxEnsureCapacity((emxArray__common *)y, pmax, sizeof(creal_T));
      if (n > 2250001) {
        nn1m1 = y->size[0];
        pmax = y->size[0];
        y->size[0] = nn1m1;
        emxEnsureCapacity((emxArray__common *)y, pmax, sizeof(creal_T));
        for (pmax = 0; pmax < nn1m1; pmax++) {
          y->data[pmax].re = 0.0;
          y->data[pmax].im = 0.0;
        }
      }

      pmax = 0;
      pmin = 0;
      nn1m1 = 0;
      for (i = 1; i < pow2p; i++) {
        y->data[nn1m1].re = x[pmax];
        y->data[nn1m1].im = 0.0;
        b_n = n;
        useRadix2 = true;
        while (useRadix2) {
          b_n >>= 1;
          pmin ^= b_n;
          useRadix2 = ((pmin & b_n) == 0);
        }

        nn1m1 = pmin;
        pmax++;
      }

      y->data[nn1m1].re = x[pmax];
      y->data[nn1m1].im = 0.0;
      if (n > 1) {
        for (i = 0; i <= n - 2; i += 2) {
          temp_re = y->data[i + 1].re;
          temp_im = y->data[i + 1].im;
          y->data[i + 1].re = y->data[i].re - y->data[i + 1].re;
          y->data[i + 1].im = y->data[i].im - y->data[i + 1].im;
          y->data[i].re += temp_re;
          y->data[i].im += temp_im;
        }
      }

      nn1m1 = 2;
      pmax = 4;
      pmin = 1 + ((nRowsD4 - 1) << 2);
      while (nRowsD4 > 0) {
        for (i = 0; i < pmin; i += pmax) {
          temp_re = y->data[i + nn1m1].re;
          temp_im = y->data[i + nn1m1].im;
          y->data[i + nn1m1].re = y->data[i].re - temp_re;
          y->data[i + nn1m1].im = y->data[i].im - temp_im;
          y->data[i].re += temp_re;
          y->data[i].im += temp_im;
        }

        b_n = 1;
        for (pow2p = nRowsD4; pow2p < nRowsD2; pow2p += nRowsD4) {
          e = costab->data[pow2p];
          twid_im = sintab->data[pow2p];
          i = b_n;
          ihi = b_n + pmin;
          while (i < ihi) {
            temp_re = e * y->data[i + nn1m1].re - twid_im * y->data[i + nn1m1].
              im;
            temp_im = e * y->data[i + nn1m1].im + twid_im * y->data[i + nn1m1].
              re;
            y->data[i + nn1m1].re = y->data[i].re - temp_re;
            y->data[i + nn1m1].im = y->data[i].im - temp_im;
            y->data[i].re += temp_re;
            y->data[i].im += temp_im;
            i += pmax;
          }

          b_n++;
        }

        nRowsD4 /= 2;
        nn1m1 = pmax;
        pmax += pmax;
        pmin -= nn1m1;
      }
    } else {
      dobluesteinfft(x, pmin, n, costab, sintab, sintabinv, y);
    }

    emxFree_real_T(&sintabinv);
    emxFree_real_T(&sintab);
    emxFree_real_T(&costab);
  }
}

/*
 * Arguments    : const emxArray_creal_T *x
 *                int unsigned_nRows
 *                const emxArray_real_T *costab
 *                const emxArray_real_T *sintab
 *                emxArray_creal_T *y
 * Return Type  : void
 */
static void r2br_r2dit_trig_impl(const emxArray_creal_T *x, int unsigned_nRows,
  const emxArray_real_T *costab, const emxArray_real_T *sintab, emxArray_creal_T
  *y)
{
  int j;
  int nRowsD2;
  int nRowsD4;
  int iy;
  int iDelta;
  int ix;
  int ju;
  int i;
  boolean_T tst;
  double temp_re;
  double temp_im;
  double twid_re;
  double twid_im;
  int ihi;
  j = x->size[0];
  if (!(j < unsigned_nRows)) {
    j = unsigned_nRows;
  }

  nRowsD2 = unsigned_nRows / 2;
  nRowsD4 = nRowsD2 / 2;
  iy = y->size[0];
  y->size[0] = unsigned_nRows;
  emxEnsureCapacity((emxArray__common *)y, iy, sizeof(creal_T));
  if (unsigned_nRows > x->size[0]) {
    iDelta = y->size[0];
    iy = y->size[0];
    y->size[0] = iDelta;
    emxEnsureCapacity((emxArray__common *)y, iy, sizeof(creal_T));
    for (iy = 0; iy < iDelta; iy++) {
      y->data[iy].re = 0.0;
      y->data[iy].im = 0.0;
    }
  }

  ix = 0;
  ju = 0;
  iy = 0;
  for (i = 1; i < j; i++) {
    y->data[iy] = x->data[ix];
    iDelta = unsigned_nRows;
    tst = true;
    while (tst) {
      iDelta >>= 1;
      ju ^= iDelta;
      tst = ((ju & iDelta) == 0);
    }

    iy = ju;
    ix++;
  }

  y->data[iy] = x->data[ix];
  if (unsigned_nRows > 1) {
    for (i = 0; i <= unsigned_nRows - 2; i += 2) {
      temp_re = y->data[i + 1].re;
      temp_im = y->data[i + 1].im;
      y->data[i + 1].re = y->data[i].re - y->data[i + 1].re;
      y->data[i + 1].im = y->data[i].im - y->data[i + 1].im;
      y->data[i].re += temp_re;
      y->data[i].im += temp_im;
    }
  }

  iDelta = 2;
  iy = 4;
  ix = 1 + ((nRowsD4 - 1) << 2);
  while (nRowsD4 > 0) {
    for (i = 0; i < ix; i += iy) {
      temp_re = y->data[i + iDelta].re;
      temp_im = y->data[i + iDelta].im;
      y->data[i + iDelta].re = y->data[i].re - temp_re;
      y->data[i + iDelta].im = y->data[i].im - temp_im;
      y->data[i].re += temp_re;
      y->data[i].im += temp_im;
    }

    ju = 1;
    for (j = nRowsD4; j < nRowsD2; j += nRowsD4) {
      twid_re = costab->data[j];
      twid_im = sintab->data[j];
      i = ju;
      ihi = ju + ix;
      while (i < ihi) {
        temp_re = twid_re * y->data[i + iDelta].re - twid_im * y->data[i +
          iDelta].im;
        temp_im = twid_re * y->data[i + iDelta].im + twid_im * y->data[i +
          iDelta].re;
        y->data[i + iDelta].re = y->data[i].re - temp_re;
        y->data[i + iDelta].im = y->data[i].im - temp_im;
        y->data[i].re += temp_re;
        y->data[i].im += temp_im;
        i += iy;
      }

      ju++;
    }

    nRowsD4 /= 2;
    iDelta = iy;
    iy += iy;
    ix -= iDelta;
  }
}

/*
 * Arguments    : double u0
 *                double u1
 * Return Type  : double
 */
static double rt_hypotd_snf(double u0, double u1)
{
  double y;
  double a;
  double b;
  a = fabs(u0);
  b = fabs(u1);
  if (a < b) {
    a /= b;
    y = b * sqrt(a * a + 1.0);
  } else if (a > b) {
    b /= a;
    y = a * sqrt(b * b + 1.0);
  } else if (rtIsNaN(b)) {
    y = b;
  } else {
    y = a * 1.4142135623730951;
  }

  return y;
}

/*
 * UNTITLED15 Summary of this function goes here
 *    Detailed explanation goes here
 * Arguments    : double Tm
 *                double Fd
 *                const double Signal[2250001]
 *                double FftL
 *                const double FftS[45000000]
 *                const double T[2250001]
 *                double f
 *                double *a
 *                double *p
 *                double RS[2250001]
 *                emxArray_real_T *FftR
 * Return Type  : void
 */
void calculation_amplitude_phase_vector_method(double Tm, double Fd, const
  double Signal[2250001], double FftL, const double FftS[45000000], const double
  T[2250001], double f, double *a, double *p, double RS[2250001],
  emxArray_real_T *FftR)
{
  double cs;
  double cc;
  double ss;
  double yc;
  double ys;
  double d0;
  int r1;
  double a21;
  double A[4];
  double b_a;
  double B[2];
  int r2;
  emxArray_creal_T *b_y1;
  signed char n;
  cs = 0.0;
  cc = 0.0;
  ss = 0.0;
  yc = 0.0;
  ys = 0.0;

  /*  initial assignments to amounts */
  d0 = Fd * Tm;
  for (r1 = 0; r1 < (int)(d0 + 1.0); r1++) {
    /*  number of time array indexes */
    a21 = f * 720.0 * (double)r1 / Fd;
    b_sind(&a21);
    cs += a21 / 2.0;

    /*  simplification cos(x)*sin(x)=sin(2*x)/2 */
    b_a = f * 360.0 * (double)r1 / Fd;
    b_cosd(&b_a);
    cc += b_a * b_a;

    /*  time starts from zero, */
    b_a = f * 360.0 * (double)r1 / Fd;
    b_sind(&b_a);
    ss += b_a * b_a;

    /*  and the index starts from one */
    a21 = f * 360.0 * (double)r1 / Fd;
    b_cosd(&a21);
    yc += Signal[r1] * a21;

    /*  so in sines and cosines is i */
    a21 = f * 360.0 * (double)r1 / Fd;
    b_sind(&a21);
    ys += Signal[r1] * a21;

    /*  and the signal contains the index i + 1 */
  }

  /*  end of accumulation of sums for the matrix */
  /*  solution of a system of linear equations (SLE) */
  A[0] = cc;
  A[2] = cs;
  A[1] = cs;
  A[3] = ss;

  /*  assigning sums to matrix A */
  B[0] = yc;
  B[1] = ys;

  /*  assign sums to matrix B */
  if (fabs(cs) > fabs(cc)) {
    r1 = 1;
    r2 = 0;
  } else {
    r1 = 0;
    r2 = 1;
  }

  a21 = A[r2] / A[r1];
  a21 = (B[r2] - B[r1] * a21) / (A[2 + r2] - a21 * A[2 + r1]);
  cs = (B[r1] - a21 * A[2 + r1]) / A[r1];

  /*  SLE decision vector */
  cc = FftS[0];
  for (r1 = 0; r1 < 44999999; r1++) {
    cc += FftS[r1 + 1];
  }

  b_a = sqrt(cs * cs + a21 * a21) - cc / 4.5E+7;

  /*  subtraction signal amplitude */
  yc = cs;
  if (cs < 0.0) {
    yc = -1.0;
  } else if (cs > 0.0) {
    yc = 1.0;
  } else {
    if (cs == 0.0) {
      yc = 0.0;
    }
  }

  ss = a21;
  if (a21 < 0.0) {
    ss = -1.0;
  } else if (a21 > 0.0) {
    ss = 1.0;
  } else {
    if (a21 == 0.0) {
      ss = 0.0;
    }
  }

  cc = cs / a21;
  cc = 180.0 + yc * (57.295779513082323 * acos(ss / sqrt(1.0 + cc * cc)) - 180.0);

  /*  subtraction signal phase 0...360 */
  a21 = f * 360.0;
  for (r1 = 0; r1 < 2250001; r1++) {
    RS[r1] = a21 * T[r1] + cc;
  }

  for (r1 = 0; r1 < 2250001; r1++) {
    if (!((!rtIsInf(RS[r1])) && (!rtIsNaN(RS[r1])))) {
      yc = rtNaN;
    } else {
      yc = rt_remd_snf(RS[r1], 360.0);
      a21 = fabs(yc);
      if (a21 > 180.0) {
        if (yc > 0.0) {
          yc -= 360.0;
        } else {
          yc += 360.0;
        }

        a21 = fabs(yc);
      }

      if (a21 <= 45.0) {
        yc *= 0.017453292519943295;
        n = 0;
      } else if (a21 <= 135.0) {
        if (yc > 0.0) {
          yc = 0.017453292519943295 * (yc - 90.0);
          n = 1;
        } else {
          yc = 0.017453292519943295 * (yc + 90.0);
          n = -1;
        }
      } else if (yc > 0.0) {
        yc = 0.017453292519943295 * (yc - 180.0);
        n = 2;
      } else {
        yc = 0.017453292519943295 * (yc + 180.0);
        n = -2;
      }

      if (n == 0) {
        yc = sin(yc);
      } else if (n == 1) {
        yc = cos(yc);
      } else if (n == -1) {
        yc = -cos(yc);
      } else {
        yc = -sin(yc);
      }
    }

    RS[r1] = yc;
  }

  for (r1 = 0; r1 < 2250001; r1++) {
    RS[r1] = Signal[r1] - b_a * RS[r1];
  }

  emxInit_creal_T(&b_y1, 1);

  /*  calculate the difference signal */
  eml_fft(RS, (int)FftL, b_y1);
  r1 = FftR->size[0] * FftR->size[1];
  FftR->size[0] = 1;
  FftR->size[1] = (int)FftL;
  emxEnsureCapacity((emxArray__common *)FftR, r1, sizeof(double));
  for (r1 = 0; r1 + 1 <= (int)FftL; r1++) {
    a21 = b_y1->data[r1].re;
    cs = b_y1->data[r1].im;
    FftR->data[r1] = rt_hypotd_snf(a21, cs);
  }

  emxFree_creal_T(&b_y1);

  /*  difference signal match amplitude */
  r1 = FftR->size[0] * FftR->size[1];
  FftR->size[0] = 1;
  emxEnsureCapacity((emxArray__common *)FftR, r1, sizeof(double));
  r1 = FftR->size[0];
  r2 = FftR->size[1];
  r2 *= r1;
  for (r1 = 0; r1 < r2; r1++) {
    FftR->data[r1] = 2.0 * FftR->data[r1] / FftL;
  }

  /*  Spectrum normalization by amplitude */
  *a = b_a;
  *p = cc;
}

/*
 * File trailer for calculation_amplitude_phase_vector_method.c
 *
 * [EOF]
 */
