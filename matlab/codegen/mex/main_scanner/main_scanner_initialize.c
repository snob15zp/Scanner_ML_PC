/*
 * main_scanner_initialize.c
 *
 * Code generation for function 'main_scanner_initialize'
 *
 */

/* Include files */
#include "main_scanner_initialize.h"
#include "_coder_main_scanner_mex.h"
#include "main_scanner_data.h"
#include "rt_nonfinite.h"

/* Function Declarations */
static void main_scanner_once(void);

/* Function Definitions */
static void main_scanner_once(void)
{
  mex_InitInfAndNan();
  /* Allocate instance data */
  covrtAllocateInstanceData(&emlrtCoverageInstance);
  /* Initialize Coverage Information */
  covrtScriptInit(
      &emlrtCoverageInstance,
      "D:\\User\\dropbox_nsel16zp\\ZERDLab "
      "Dropbox\\Nsel\\GIT\\Scanner\\Scanner_ML_PC\\matlab\\main_scanner.m",
      0U, 1U, 6U, 2U, 0U, 0U, 0U, 0U, 1U, 0U, 0U);
  /* Initialize Function Information */
  covrtFcnInit(&emlrtCoverageInstance, 0U, 0U, "main_scanner", 0, -1, 1493);
  /* Initialize Basic Block Information */
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 5U, 1382, -1, 1472);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 4U, 1266, -1, 1356);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 3U, 1006, -1, 1117);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 2U, 850, -1, 964);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 1U, 487, -1, 658);
  covrtBasicBlockInit(&emlrtCoverageInstance, 0U, 0U, 91, -1, 233);
  /* Initialize If Information */
  covrtIfInit(&emlrtCoverageInstance, 0U, 0U, 723, 748, -1, 996);
  covrtIfInit(&emlrtCoverageInstance, 0U, 1U, 1228, 1253, 1365, 1484);
  /* Initialize MCDC Information */
  /* Initialize For Information */
  /* Initialize While Information */
  covrtWhileInit(&emlrtCoverageInstance, 0U, 0U, 323, 336, 1493);
  /* Initialize Switch Information */
  /* Start callback for coverage engine */
  covrtScriptStart(&emlrtCoverageInstance, 0U);
  /* Allocate instance data */
  covrtAllocateInstanceData(&emlrtCoverageInstance);
  /* Initialize Coverage Information */
  covrtScriptInit(
      &emlrtCoverageInstance,
      "D:\\User\\dropbox_nsel16zp\\ZERDLab "
      "Dropbox\\Nsel\\GIT\\Scanner\\Scanner_ML_PC\\matlab\\tone_search.m",
      1U, 1U, 9U, 1U, 0U, 0U, 0U, 2U, 1U, 0U, 0U);
  /* Initialize Function Information */
  covrtFcnInit(&emlrtCoverageInstance, 1U, 0U, "tone_search", 0, -1, 3006);
  /* Initialize Basic Block Information */
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 5U, 1657, -1, 1662);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 4U, 1548, -1, 1557);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 3U, 1380, -1, 1392);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 2U, 1226, -1, 1339);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 1U, 1005, -1, 1088);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 8U, 2513, -1, 2967);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 7U, 2068, -1, 2385);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 6U, 1928, -1, 1953);
  covrtBasicBlockInit(&emlrtCoverageInstance, 1U, 0U, 132, -1, 833);
  /* Initialize If Information */
  covrtIfInit(&emlrtCoverageInstance, 1U, 0U, 1468, 1475, -1, 1648);
  /* Initialize MCDC Information */
  /* Initialize For Information */
  covrtForInit(&emlrtCoverageInstance, 1U, 0U, 1147, 1160, 1371);
  covrtForInit(&emlrtCoverageInstance, 1U, 1U, 1997, 2010, 2435);
  /* Initialize While Information */
  covrtWhileInit(&emlrtCoverageInstance, 1U, 0U, 913, 931, 1735);
  /* Initialize Switch Information */
  /* Start callback for coverage engine */
  covrtScriptStart(&emlrtCoverageInstance, 1U);
  /* Allocate instance data */
  covrtAllocateInstanceData(&emlrtCoverageInstance);
  /* Initialize Coverage Information */
  covrtScriptInit(
      &emlrtCoverageInstance,
      "D:\\User\\dropbox_nsel16zp\\ZERDLab "
      "Dropbox\\Nsel\\GIT\\Scanner\\Scanner_ML_PC\\matlab\\filesave_ceval.m",
      2U, 1U, 5U, 3U, 0U, 0U, 0U, 0U, 0U, 0U, 0U);
  /* Initialize Function Information */
  covrtFcnInit(&emlrtCoverageInstance, 2U, 0U, "filesave_ceval", 0, -1, 1096);
  /* Initialize Basic Block Information */
  covrtBasicBlockInit(&emlrtCoverageInstance, 2U, 4U, 843, -1, 863);
  covrtBasicBlockInit(&emlrtCoverageInstance, 2U, 3U, 801, -1, 825);
  covrtBasicBlockInit(&emlrtCoverageInstance, 2U, 2U, 772, -1, 792);
  covrtBasicBlockInit(&emlrtCoverageInstance, 2U, 1U, 283, -1, 754);
  covrtBasicBlockInit(&emlrtCoverageInstance, 2U, 0U, 141, -1, 163);
  /* Initialize If Information */
  covrtIfInit(&emlrtCoverageInstance, 2U, 0U, 164, 189, 253, 1092);
  covrtIfInit(&emlrtCoverageInstance, 2U, 1U, 757, 765, -1, 798);
  covrtIfInit(&emlrtCoverageInstance, 2U, 2U, 828, 836, -1, 869);
  /* Initialize MCDC Information */
  /* Initialize For Information */
  /* Initialize While Information */
  /* Initialize Switch Information */
  /* Start callback for coverage engine */
  covrtScriptStart(&emlrtCoverageInstance, 2U);
}

void main_scanner_initialize(void)
{
  emlrtStack st = {
      NULL, /* site */
      NULL, /* tls */
      NULL  /* prev */
  };
  mexFunctionCreateRootTLS();
  emlrtBreakCheckR2012bFlagVar = emlrtGetBreakCheckFlagAddressR2012b();
  st.tls = emlrtRootTLSGlobal;
  emlrtClearAllocCountR2012b(&st, false, 0U, NULL);
  emlrtEnterRtStackR2012b(&st);
  if (emlrtFirstTimeR2012b(emlrtRootTLSGlobal)) {
    main_scanner_once();
  }
}

/* End of code generation (main_scanner_initialize.c) */
