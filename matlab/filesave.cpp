#include <iostream>
#include <fstream>
#include <string>
//#include "csv_parser.hpp"
//#include "prezerv.h"

//#include "globalconst.h"

void filesave(const double *data, int  size1,int size2, char* path, char *filename, int t)
{
/*    std::string FullFileName;
    //FullFileName=std::string(path);
    getpath(FullFileName);
    FullFileName+=std::string(filename);


//    std::ofstream os("c:\\1"); // текстовый файл для вывода

//     // проверка, открыт ли файл
//     if (!os)
//     {
//         std::cout << "Cannot open the file to output. \n";
//       return;
//     }

//     char str[80];

//     std::cout << "Save the lines to HDD. Enter ! to stop." << std::endl;





//       os << "345" << std::endl; // записать в файл строку str


//     os.close(); // закрыть файл


    std::ofstream f;
   f.open(FullFileName.c_str());
   //f.open("c:\\55");
   if (!f)
   {
       std::cout << "Cannot open "<<FullFileName<<std::endl;
     return;
   }
   for(int i1=0;i1<size1;i1++)
        {   for(int i2=0;i2<size2;i2++)
            {
              if (1==t)
              { f << data[i2+i1*size2] << '\t';
              }
              else
              { f << data[i2*size1+i1] << '\t';
              }    
            }
            f << std::endl;
         }
    f.close();
 */   
}

void filecomp(char* path, char *filename1)
{
    /*
#ifdef DebugCheckData
std::string FullFileName1;
std::string FullFileName2;

getpath(FullFileName1);
FullFileName1+=std::string(filename1);

getpath(FullFileName2);
FullFileName2+="REF_"+std::string(filename1);

//FullFileName1=std::string(path)+std::string(filename1);
//FullFileName2=std::string(path)+"REF_"+std::string(filename1);

 std::cout <<filename1<<" is checking"<< std::endl;

csv_parser_t<double> csv2(FullFileName2);
csv_parser_t<double> csv1(FullFileName1);

int size21=csv2.size();
int size22=csv2[0].size();
double *S2 = new double [size21*size22];

   int row_num2 = 0;
   int S2index=0;
   for (std::vector<double> row : csv2)
   {

       for(double val : row)
       {
           S2[S2index++]=val;
       }
       row_num2 += 1;
   }

   int size11=csv1.size();
   int size12=csv1[0].size();
   double *S1 = new double [size11*size12];

      int row_num1 = 0;
      int S1index=0;
      for (std::vector<double> row : csv1)
      {

          for(double val : row)
          {
              S1[S1index++]=val;
          }
          row_num1 += 1;
      }



if (size11!=size21)
      {std::cout <<"size11 "<<size11<<" size21 "<<size21<<" ERROR" <<std::endl;
       return;
      }
if (size12!=size22)
    {std::cout <<"size12 "<<size12<<" size22 "<<size22<<" ERROR" <<std::endl;
     return;
    }
for(int i1=0;i1<size11;i1++)
    for(int i2=0;i2<size12;i2++)
    {   double err;
        if (0==S2[i1*size12+i2])
        {err=std::abs((S1[i1*size12+i2]-S2[i1*size12+i2]));}
        else
        {err=std::abs((S1[i1*size12+i2]-S2[i1*size12+i2])/S2[i1*size12+i2]);};
        if (err>0.01)
            {std::cout <<"i1 "<<i1<<" i2 "<<i2<<" ERROR" <<std::endl;
             return;
            }
    }

    std::cout <<filename1<<" ok"<< std::endl;
#endif
*/
}
