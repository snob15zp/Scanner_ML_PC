//#include <QCoreApplication>
#include "csv_parser.hpp"
#include <filesystem>
#include <iostream>
#include <string>
#include <vector>

#include "main_algorithm2.h"
#include "coder_array.h"
#include "prezerv.h"
//#pragma comment(linker, "/STACK:16777216")

static std::string pathOnly;

void getpath(std::string &s)
{
    s=pathOnly;
};

int Prezerv(int argc, char *argv[])
{   char folder[50]="";
    std::string _path("C:\\prezerv\\2-28_Ale_2021-02-28-029-X50-60-NormalizedContrast.txt");
    if (argc >= 2) {
        _path = argv[1];
     }
    std::filesystem::path p(_path);
    pathOnly=p.parent_path().string()+"\\";
    strncpy_s(folder,p.parent_path().string().c_str(),49);
    strncat_s(folder,"\\",1);

    std::cout << "using: " << _path << " file" << std::endl;
    csv_parser_t<double> csv(_path);

    /**
     * Iterate over parsed data
     */
    //   int row_num = 0;
    //   for (std::vector<double> row : csv)
    //   {
    //       std::cout << "------ Row: " << row_num << " --------" << std::endl << "| ";
    //       for(double val : row)
    //       {
    //           std::cout << val << " | ";
    //       }
    //       std::cout << std::endl;
    //       row_num += 1;
    //   }



    /**
    *   Access only to one row and one element
    */
    std::cout << "------ Row: 100, element: 16 = " << csv[100][16] << " --------" << std::endl;
    std::cout << "------ Row: 0, element: 0 = " << csv[0][0] << " --------" << std::endl;
    int size1 = csv.size();
    int size2 = csv[0].size();
    double *S0 = new double [size1 * size2];

    int row_num = 0;
    int S0index = 0;
    for (std::vector<double> row : csv) {

        for (double val : row) {
            S0[S0index++] = val;
        }
        row_num += 1;
    }

    double *S01 = new double [size1 * size2];

    for (int i1 = 0; i1 < size1; i1++ )
        for (int i2 = 0; i2 < size2; i2++ )
            S01[i2 * size1 + i1] = S0[i2 + i1 * size2];

    //double *a1,*a2,*a3,*a4;
    //coder::array<double, 2U> retval;
    //double *gain = new double[413];
    //coder::array<double, 2U> PointCloud_In;
    //double *Phi1=new double [845824];
    //double *Phi1_Z=new double [2];
    int *S01size=new int[2];

    //void main_algorithm2(const double S0[2246720], coder::array<double, 2U> &retval,
    //                     coder::array<double, 2U> &PointCloud_In,
    //                     double Phi1[845824], double Phi1_Z[2], double Phi1_Y[2])


    S01size[0]=size1;
    S01size[1]=size2;
    main_algorithm2(S01,S01size,folder);

    delete[] S0;
    delete[] S01;
    //delete[]retval;
    //delete[] gain;
    return 0;// a.exec();
}
