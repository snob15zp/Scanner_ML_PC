/*
 * File: tone_search.c
 *
 * MATLAB Coder version            : 5.3
 * C/C++ source code generated on  : 10-May-2023 13:37:04
 */

/* Include Files */
#include "tone_search.h"
#include "cosd.h"
#include "fft.h"
#include "rt_nonfinite.h"
#include "sind.h"
#include "tone_search_emxutil.h"
#include "tone_search_rtwutil.h"
#include "tone_search_types.h"
#include "rt_nonfinite.h"
#include <math.h>

/* Function Declarations */
static double rt_hypotd_snf(double u0, double u1);

/* Function Definitions */
/*
 * Arguments    : double u0
 *                double u1
 * Return Type  : double
 */
static double rt_hypotd_snf(double u0, double u1)
{
  double a;
  double y;
  a = fabs(u0);
  y = fabs(u1);
  if (a < y) {
    a /= y;
    y *= sqrt(a * a + 1.0);
  } else if (a > y) {
    y /= a;
    y = a * sqrt(y * y + 1.0);
  } else if (!rtIsNaN(y)) {
    y = a * 1.4142135623730951;
  }
  return y;
}

/*
 * функция поиска и удаления тонов
 *
 * Arguments    : double Tm
 *                double Fd
 *                double mz
 *                double FftL
 *                const double T[2500001]
 *                double Signal[2500001]
 *                double *a
 *                double *f
 *                double *p
 *                emxArray_real_T *FftS
 *                double *Am
 * Return Type  : void
 */
void tone_search(double Tm, double Fd, double mz, double FftL,
                 const double T[2500001], double Signal[2500001], double *a,
                 double *f, double *p, emxArray_real_T *FftS, double *Am)
{
  emxArray_creal_T *x;
  creal_T *x_data;
  double A[4];
  double B[2];
  double a21;
  double absx;
  double d;
  double ex;
  double ff;
  double hf;
  double ss;
  double yc;
  double ys;
  double *FftS_data;
  int i;
  int k;
  int last;
  int nx;
  signed char n;
  boolean_T exitg1;
  (void)mz;
  *f *= 360.0;
  for (k = 0; k < 2500001; k++) {
    d = *f * T[k] + *p;
    if (rtIsInf(d) || rtIsNaN(d)) {
      d = rtNaN;
    } else {
      a21 = rt_remd_snf(d, 360.0);
      absx = fabs(a21);
      if (absx > 180.0) {
        if (a21 > 0.0) {
          a21 -= 360.0;
        } else {
          a21 += 360.0;
        }
        absx = fabs(a21);
      }
      if (absx <= 45.0) {
        a21 *= 0.017453292519943295;
        n = 0;
      } else if (absx <= 135.0) {
        if (a21 > 0.0) {
          a21 = 0.017453292519943295 * (a21 - 90.0);
          n = 1;
        } else {
          a21 = 0.017453292519943295 * (a21 + 90.0);
          n = -1;
        }
      } else if (a21 > 0.0) {
        a21 = 0.017453292519943295 * (a21 - 180.0);
        n = 2;
      } else {
        a21 = 0.017453292519943295 * (a21 + 180.0);
        n = -2;
      }
      if (n == 0) {
        d = sin(a21);
      } else if (n == 1) {
        d = cos(a21);
      } else if (n == -1) {
        d = -cos(a21);
      } else {
        d = -sin(a21);
      }
    }
    Signal[k] -= *a * d;
  }
  emxInit_creal_T(&x, 2);
  /*  вычисляем разностный сигнал */
  /*          %% Спектральное представление входного сигнала */
  fft(Signal, FftL, x);
  x_data = x->data;
  nx = x->size[1];
  i = FftS->size[0] * FftS->size[1];
  FftS->size[0] = 1;
  FftS->size[1] = x->size[1];
  emxEnsureCapacity_real_T(FftS, i);
  FftS_data = FftS->data;
  for (k = 0; k < nx; k++) {
    FftS_data[k] = rt_hypotd_snf(x_data[k].re, x_data[k].im);
  }
  emxFree_creal_T(&x);
  /*  амплитуды преобразования Фурье сигнала */
  i = FftS->size[0] * FftS->size[1];
  FftS->size[0] = 1;
  emxEnsureCapacity_real_T(FftS, i);
  FftS_data = FftS->data;
  nx = FftS->size[1] - 1;
  for (i = 0; i <= nx; i++) {
    FftS_data[i] = 2.0 * FftS_data[i] / FftL;
  }
  /*  нормировка спектра по амплитуде */
  /* FftS(1)=FftS(1)/2;              % нормировка постоянной составляющей в
   * спектре */
  /*         %% Поиск частоты тона и вычисление */
  last = FftS->size[1];
  if (FftS->size[1] <= 2) {
    if (FftS->size[1] == 1) {
      ex = FftS_data[0];
      nx = 1;
    } else if ((FftS_data[0] < FftS_data[FftS->size[1] - 1]) ||
               (rtIsNaN(FftS_data[0]) &&
                (!rtIsNaN(FftS_data[FftS->size[1] - 1])))) {
      ex = FftS_data[FftS->size[1] - 1];
      nx = FftS->size[1];
    } else {
      ex = FftS_data[0];
      nx = 1;
    }
  } else {
    if (!rtIsNaN(FftS_data[0])) {
      nx = 1;
    } else {
      nx = 0;
      k = 2;
      exitg1 = false;
      while ((!exitg1) && (k <= last)) {
        if (!rtIsNaN(FftS_data[k - 1])) {
          nx = k;
          exitg1 = true;
        } else {
          k++;
        }
      }
    }
    if (nx == 0) {
      ex = FftS_data[0];
      nx = 1;
    } else {
      ex = FftS_data[nx - 1];
      i = nx + 1;
      for (k = i; k <= last; k++) {
        d = FftS_data[k - 1];
        if (ex < d) {
          ex = d;
          nx = k;
        }
      }
    }
  }
  /*  максимум в спектре , где Am - амплитуда спички , im - индекс в массиве
   * FftS начиная с 1 а не с 0 */
  *f = ((double)nx - 1.0) * Fd / FftL;
  /*  вычисление частоты тона , im-1 потому что i начинается с 1 а не с 0 */
  /*         %% Аппроксимация частоты вычета по максимуму вектора */
  hf = 0.01;
  ff = 0.0;
  /*  шаг и точность оптимизированы на быстродействие , отклонение ff сбросить
   */
  while (fabs(hf) > 1.0E-6) {
    /*  если шаг не дошол до оптимальной точности , то */
    *f += hf;
    /*  частоту инкрементируем на шаг  */
    a21 = 0.0;
    ss = 0.0;
    /*  начальные присвоения суммам */
    i = (int)(Tm * Fd + 1.0);
    for (nx = 0; nx < i; nx++) {
      /*  количество индексов массива времени Tm*Fd+1 */
      d = *f * 360.0 * (double)nx / Fd;
      absx = d;
      b_cosd(&absx);
      a21 += Signal[nx] * absx;
      /*  первая сумма вектора */
      b_sind(&d);
      ss += Signal[nx] * d;
      /*  вторая сумма вектора */
    }
    a21 = a21 * a21 + ss * ss;
    /*  функция отклонения - сумма квадратов сумм вектора */
    if (a21 < ff) {
      /*  если проскочили максимальное значение , то */
      hf = -hf / 2.0;
      /*  деление на 2 и разворот шага в обратную сторону */
    }
    ff = a21;
    /*  прошлая сумма равна текущей */
  }
  /*  конец аппроксимации по частоте */
  /*         %% Расчёт амплитуды и фазы по векторному методу , при условии
   * известной частоты */
  hf = 0.0;
  ff = 0.0;
  ss = 0.0;
  yc = 0.0;
  ys = 0.0;
  /*  начальные присвоения суммам */
  i = (int)(Fd * Tm + 1.0);
  for (nx = 0; nx < i; nx++) {
    /*  количество индексов массива времени */
    d = *f * 720.0 * (double)nx / Fd;
    b_sind(&d);
    hf += d / 2.0;
    /*  упрощение cos(x)*sin(x)=sin(2*x)/2 */
    a21 = *f * 360.0 * (double)nx / Fd;
    absx = a21;
    b_cosd(&absx);
    ff += absx * absx;
    /*  время начинается с нуля , */
    *a = a21;
    b_sind(a);
    ss += *a * *a;
    /*  а индекс начинается с единицы */
    yc += Signal[nx] * absx;
    /*  поэтому в синусах и косинусах стоит i */
    b_sind(&a21);
    ys += Signal[nx] * a21;
    /*  а в сигнале стоит индекс i+1 */
  }
  /*  конец накопления сумм для матрицы */
  A[0] = ff;
  A[2] = hf;
  A[1] = hf;
  A[3] = ss;
  /*  решение системы линейных уравнений (СЛУ) */
  /*  присвоение сумм матрице А */
  B[0] = yc;
  B[1] = ys;
  /*  присвоение сумм матрице В */
  if (fabs(hf) > fabs(ff)) {
    nx = 1;
    last = 0;
  } else {
    nx = 0;
    last = 1;
  }
  a21 = A[last] / A[nx];
  absx = A[nx + 2];
  hf = (B[last] - B[nx] * a21) / (A[last + 2] - a21 * absx);
  a21 = (B[nx] - hf * absx) / A[nx];
  /*  вектор решения СЛУ */
  /* (mean(FftS(1:299990*mz))+mean(FftS(300050*mz:Fd*mz/2)))/2; % средняя
   * амплитуда шума */
  *a = sqrt(a21 * a21 + hf * hf);
  /*  амплитуда сигнала вычета */
  absx = a21 / hf;
  if (a21 < 0.0) {
    a21 = -1.0;
  } else if (a21 > 0.0) {
    a21 = 1.0;
  } else if (a21 == 0.0) {
    a21 = 0.0;
  }
  if (hf < 0.0) {
    hf = -1.0;
  } else if (hf > 0.0) {
    hf = 1.0;
  } else if (hf == 0.0) {
    hf = 0.0;
  }
  *p = a21 * (57.295779513082323 * acos(hf / sqrt(absx * absx + 1.0)) - 180.0) +
       180.0;
  /*  фаза сигнала вычета 0...360 */
  *Am = ex;
}

/*
 * File trailer for tone_search.c
 *
 * [EOF]
 */
