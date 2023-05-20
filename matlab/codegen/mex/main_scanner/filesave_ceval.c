/*
 * filesave_ceval.c
 *
 * Code generation for function 'filesave_ceval'
 *
 */

/* Include files */
#include "filesave_ceval.h"
#include "main_scanner_data.h"
#include "rt_nonfinite.h"
#include "filesave.h"

/* Function Definitions */
void filesave_ceval(void)
{
  covrtLogFcn(&emlrtCoverageInstance, 2U, 0U);
  covrtLogBasicBlock(&emlrtCoverageInstance, 2U, 0U);
  /* ----------------------------------- */
  /* columnwise */
  /* ----------------------------------- */
  covrtLogIf(&emlrtCoverageInstance, 2U, 0U, 0, false);
  covrtLogBasicBlock(&emlrtCoverageInstance, 2U, 1U);
  /* path='c:\prezerv\'; */
  /* coder.updateBuildInfo('addIncludePaths','$(START_DIR)\codegen\lib\combineXY');
   */
  /* coder.cinclude('myabsval_initialize.h'); */
  /* coder.cinclude('myabsval.h'); */
  /* coder.cinclude('myabsval_terminate.h'); */
  /* void filesave(const double *data, int  size1,int size2, char* path, char
   * *filename); */
  /* s1=int32(0); */
  /* [s1,s2]=sz;%size(data); */
  covrtLogIf(&emlrtCoverageInstance, 2U, 0U, 1, false);
  covrtLogBasicBlock(&emlrtCoverageInstance, 2U, 3U);
  covrtLogIf(&emlrtCoverageInstance, 2U, 0U, 2, false);
  /*    ActVal2=[]; */
  /*    ActVal2(1:s1i,1:s2i)=data(1:s1i,1:s2i); */
  /* coder.ceval('filesave',
   * coder.ref(data),s1i,s2i,coder.ref(cpath),[filename,0],cast(t,"int32")); */
  /* coder.ceval('filecomp', coder.ref(cpath),[filename,0]); */
}

/* End of code generation (filesave_ceval.c) */
