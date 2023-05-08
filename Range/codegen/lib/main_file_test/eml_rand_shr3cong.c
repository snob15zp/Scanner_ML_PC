/*
 * File: eml_rand_shr3cong.c
 *
 * MATLAB Coder version            : 5.3
 * C/C++ source code generated on  : 08-May-2023 13:56:17
 */

/* Include Files */
#include "eml_rand_shr3cong.h"
#include "rt_nonfinite.h"
#include <math.h>

/* Function Definitions */
/*
 * Arguments    : unsigned int d_state[2]
 * Return Type  : double
 */
double eml_rand_shr3cong(unsigned int d_state[2])
{
  static const double dv[65] = {
      0.340945,  0.4573146, 0.5397793, 0.6062427, 0.6631691, 0.7136975,
      0.7596125, 0.8020356, 0.8417227, 0.8792102, 0.9148948, 0.9490791,
      0.9820005, 1.0138492, 1.044781,  1.0749254, 1.1043917, 1.1332738,
      1.161653,  1.189601,  1.2171815, 1.2444516, 1.2714635, 1.298265,
      1.3249008, 1.3514125, 1.3778399, 1.4042211, 1.4305929, 1.4569915,
      1.4834527, 1.5100122, 1.5367061, 1.5635712, 1.5906454, 1.617968,
      1.6455802, 1.6735255, 1.7018503, 1.7306045, 1.7598422, 1.7896223,
      1.8200099, 1.851077,  1.8829044, 1.9155831, 1.9492166, 1.9839239,
      2.0198431, 2.0571356, 2.095993,  2.136645,  2.1793713, 2.2245175,
      2.2725186, 2.3239338, 2.3795008, 2.4402218, 2.5075117, 2.5834658,
      2.6713916, 2.7769942, 2.7769942, 2.7769942, 2.7769942};
  double r;
  double s;
  double x;
  double y;
  unsigned int icng;
  int j;
  unsigned int jsr;
  unsigned int ui;
  icng = 69069U * d_state[0] + 1234567U;
  jsr = d_state[1] ^ d_state[1] << 13;
  jsr ^= jsr >> 17;
  jsr ^= jsr << 5;
  ui = icng + jsr;
  j = (int)((ui & 63U) + 1U);
  r = (double)(int)ui * 4.6566128730773926E-10 * dv[j];
  x = fabs(r);
  y = dv[j - 1];
  if (!(x <= y)) {
    x = (x - y) / (dv[j] - y);
    icng = 69069U * icng + 1234567U;
    jsr ^= jsr << 13;
    jsr ^= jsr >> 17;
    jsr ^= jsr << 5;
    y = (double)(int)(icng + jsr) * 2.328306436538696E-10 + 0.5;
    s = x + y;
    if (s > 1.301198) {
      if (r < 0.0) {
        r = 0.4878992 * x - 0.4878992;
      } else {
        r = 0.4878992 - 0.4878992 * x;
      }
    } else if (!(s <= 0.9689279)) {
      x = 0.4878992 - 0.4878992 * x;
      if (y > 12.67706 - 12.37586 * exp(-0.5 * x * x)) {
        if (r < 0.0) {
          r = -x;
        } else {
          r = x;
        }
      } else if (!(exp(-0.5 * dv[j] * dv[j]) + y * 0.01958303 / dv[j] <=
                   exp(-0.5 * r * r))) {
        do {
          icng = 69069U * icng + 1234567U;
          jsr ^= jsr << 13;
          jsr ^= jsr >> 17;
          jsr ^= jsr << 5;
          x = log((double)(int)(icng + jsr) * 2.328306436538696E-10 + 0.5) /
              2.776994;
          icng = 69069U * icng + 1234567U;
          jsr ^= jsr << 13;
          jsr ^= jsr >> 17;
          jsr ^= jsr << 5;
        } while (
            !(-2.0 *
                  log((double)(int)(icng + jsr) * 2.328306436538696E-10 + 0.5) >
              x * x));
        if (r < 0.0) {
          r = x - 2.776994;
        } else {
          r = 2.776994 - x;
        }
      }
    }
  }
  d_state[0] = icng;
  d_state[1] = jsr;
  return r;
}

/*
 * File trailer for eml_rand_shr3cong.c
 *
 * [EOF]
 */
