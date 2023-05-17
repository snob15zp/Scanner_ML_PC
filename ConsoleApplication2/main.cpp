#include <chrono>
#include <fstream>
#include <iostream>
#include <string.h>
#include <vector>

extern "C" {
#include "tone_search.h"
}

void main_scanner(double Tm, double Fd, double mz, double FftL,
                  double T[2500001], double Signal[2500001])
{
  double Am = 1;
  double a = 0;
  double f = 0;
  double p = 0;
  int i = 0;
  emxArray_real_T FfTs;
  FfTs.size = new int[2];
  FfTs.data = nullptr;

  while (Am > 0.0001) {
    tone_search(Tm, Fd, mz, FftL, T, Signal, &a, &f, &p, &FfTs, &Am);
    std::cout << i++ << "\t" << a << ", " << f << ", " << p << std::endl;
  }
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

  main_scanner(Tm, Fd, mz, FftL, T, Signal);

  std::chrono::duration<double> duration =
      std::chrono::system_clock::now() - start;

  std::cout << "Total time: " << duration.count() << "s" << std::endl;
  return 0;
}
