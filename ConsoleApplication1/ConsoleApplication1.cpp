#include <iostream>
extern "C" {
#include "rt_nonfinite.h"
#include "generation_test_signal.h"
#include "generation_test_signal_terminate.h"
#include "generation_test_signal_emxAPI.h"
#include "generation_test_signal_initialize.h"
}

static double argInit_real_T(void);
static void main_generation_test_signal(void);

static double argInit_real_T(void)
{
    return 0.0;
}

/*
 * Arguments    : void
 * Return Type  : void
 */
static void main_generation_test_signal(void)
{
    emxArray_real_T* Signal;
    emxArray_real_T* T;
    double FftL;
    emxInitArray_real_T(&Signal, 2);
    emxInitArray_real_T(&T, 2);

    /* Initialize function 'generation_test_signal' input arguments. */
    /* Call the entry-point 'generation_test_signal'. */
    generation_test_signal(argInit_real_T(), argInit_real_T(), argInit_real_T(),
        argInit_real_T(), argInit_real_T(), argInit_real_T(), argInit_real_T(),
        argInit_real_T(), argInit_real_T(), argInit_real_T(), argInit_real_T(),
        Signal, T, &FftL);
    emxDestroyArray_real_T(T);
    emxDestroyArray_real_T(Signal);
}


int main()
{
    generation_test_signal_initialize();

    /* Invoke the entry-point functions.
       You can call entry-point functions multiple times. */
    main_generation_test_signal();

    /* Terminate the application.
       You do not need to do this more than one time. */
    generation_test_signal_terminate();
}
