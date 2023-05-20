/*
 * File: filesave_ceval.c
 *
 * MATLAB Coder version            : 5.3
 * C/C++ source code generated on  : 20-May-2023 21:00:38
 */

/* Include Files */
#include "filesave_ceval.h"
#include "main_scanner_emxutil.h"
#include "main_scanner_types.h"
#include "rt_nonfinite.h"
#include "filesave.h"

/* Function Definitions */
/*
 * -----------------------------------
 * columnwise
 * -----------------------------------
 *
 * Arguments    : emxArray_real_T *data
 *                const emxArray_char_T *filename
 * Return Type  : void
 */
void filesave_ceval(emxArray_real_T *data, const emxArray_char_T *filename)
{
  emxArray_char_T *r;
  emxArray_char_T *r2;
  double *data_data;
  int i;
  int loop_ub;
  const char *filename_data;
  char cpath;
  char *r1;
  char *r3;
  filename_data = filename->data;
  data_data = data->data;
  emxInit_char_T(&r);
  /* path='c:\prezerv\'; */
  cpath = '\x00';
  /* coder.updateBuildInfo('addIncludePaths','$(START_DIR)\codegen\lib\combineXY');
   */
  /* coder.cinclude('myabsval_initialize.h'); */
  /* coder.cinclude('myabsval.h'); */
  /* coder.cinclude('myabsval_terminate.h'); */
  /* void filesave(const double *data, int  size1,int size2, char* path, char
   * *filename); */
  /* s1=int32(0); */
  /* [s1,s2]=sz;%size(data); */
  /*    ActVal2=[]; */
  /*    ActVal2(1:s1i,1:s2i)=data(1:s1i,1:s2i); */
  i = r->size[0] * r->size[1];
  r->size[0] = 1;
  r->size[1] = filename->size[1] + 1;
  emxEnsureCapacity_char_T(r, i);
  r1 = r->data;
  loop_ub = filename->size[1];
  for (i = 0; i < loop_ub; i++) {
    r1[i] = filename_data[i];
  }
  emxInit_char_T(&r2);
  r1[filename->size[1]] = '\x00';
  i = r2->size[0] * r2->size[1];
  r2->size[0] = 1;
  r2->size[1] = r->size[1];
  emxEnsureCapacity_char_T(r2, i);
  r3 = r2->data;
  loop_ub = r->size[1];
  for (i = 0; i < loop_ub; i++) {
    r3[i] = r1[i];
  }
  filesave(&data_data[0], 1, 250001, &cpath, &r3[0], 1);
  filecomp(&cpath, &r1[0]);
  emxFree_char_T(&r);
  emxFree_char_T(&r2);
}

/*
 * File trailer for filesave_ceval.c
 *
 * [EOF]
 */
