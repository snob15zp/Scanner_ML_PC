#include <chrono>
#include <fstream>
#include <iostream>
#include <string.h>
#include <vector>

extern "C" {
#include "main_scanner.h"
//#include "main.h"
#include "main_scanner.h"
#include "main_scanner_emxAPI.h"
#include "main_scanner_terminate.h"
#include "main_scanner_types.h"
#include "rt_nonfinite.h"
#include "rtwtypes.h"
#include <stddef.h>
#include <stdlib.h>
}

//void main_scanner(double Tm, double Fd, double mz, double FftL,
//                  double T[2500001], double Signal[2500001])
//{
//  double Am = 1;
//  double a = 0;
//  double f = 0;
//  double p = 0;
//  int i = 0;
//  emxArray_real_T FfTs;
//  FfTs.size = new int[2];
//  FfTs.data = nullptr;
//
//  while (Am > 0.0001) {
//    tone_search(Tm, Fd, mz, FftL, T, Signal, &a, &f, &p, &FfTs, &Am);
//    std::cout << i++ << "\t" << a << ", " << f << ", " << p << std::endl;
//  }
//}
//extern void main_scanner(double Tm, double Fd, double mz, double FftL,
//                         const double T[2500001], double Signal[2500001],
//                         double Out[300], emxArray_real_T *FftS);
static double argInit_real_T(void)
{
  return 0.0;
}
static void argInit_1x2500001_real_T(double result[2500001])
{
  int idx1;
  /* Loop over the array to initialize each element. */
  for (idx1 = 0; idx1 < 2500001; idx1++) {
    /* Set the value of the array element.
Change this value to the value that the application requires. */
    result[idx1] = argInit_real_T();
  }
}

/*
 * Arguments    : void
 * Return Type  : double
 */


static void main_main_scanner(double Tm, double Fd, double mz, double FftL,
                  double T[2500001], double Signal[2500001])
{
  static double T_tmp[2500001];
  static double b_T_tmp[2500001];
  emxArray_real_T *FftS;
  double Out[300];
  double Tm_tmp;
  emxInitArray_real_T(&FftS, 2);
  /* Initialize function 'main_scanner' input arguments. */
  Tm_tmp = argInit_real_T();
  /* Initialize function input argument 'T'. */
  argInit_1x2500001_real_T(T_tmp);
  /* Initialize function input argument 'Signal'. */
  /* Call the entry-point 'main_scanner'. */
  memcpy(&b_T_tmp[0], &T_tmp[0], 2500001U * sizeof(double));
  main_scanner(Tm, Fd, mz, FftL, T, Signal, Out, FftS);
  emxDestroyArray_real_T(FftS);
}

int main(int argc, char **argv)
{
  auto start = std::chrono::system_clock::now();

  double Tm = 1;
  double Fd = 2500000;
  double mz = 20;
  double FftL = Tm * Fd * mz;

  double *Signal = new double[2500001];
  double *T = new double[2500001];
  std::fill_n(T, 2500001, 1 / Fd);

  std::fstream signalData("Signal.txt", std::ios_base::in);

  std::cout << "Read data from file" << std::endl;
  int idx = 0;
  while (!signalData.eof()) {
    double value;
    signalData >> value;
    if (signalData.bad()) {
      std::cerr << "Number formatting error " << idx << std::endl;
      return 0;
    }
    Signal[idx++] = value;
    char c;
    signalData >> c;
  }

  std::cout << "Data successfully read. Size - " << idx << std::endl;

  main_main_scanner(Tm, Fd, mz, FftL, T, Signal);

  std::chrono::duration<double> duration =
      std::chrono::system_clock::now() - start;

  std::cout << "Total time: " << duration.count() << "s" << std::endl;
  return 0;
}
