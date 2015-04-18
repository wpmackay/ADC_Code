/*
 * averaging_filter.c
 *
 * Code generation for function 'averaging_filter'
 *
 * C source code generated on: Sat Oct 25 14:16:56 2014
 *
 */

/* Include files */
#include "rt_nonfinite.h"
#include "averaging_filter.h"
#include "averaging_filter_data.h"

/* Type Definitions */

/* Named Constants */

/* Variable Declarations */

/* Variable Definitions */

/* Function Declarations */

/* Function Definitions */
void averaging_filter(const real_T x_data[1000], const int32_T x_size[1], real_T
                      y_data[1000], int32_T y_size[1])
{
  int32_T loop_ub;
  int32_T k;
  real_T dv0[15];
  real_T y;

  /*  y = averaging_filter(x) */
  /*  Take an input vector signal 'x' and produce an output vector signal 'y' with */
  /*  same type and shape as 'x' but filtered. */
  /*  Use a persistent variable 'buffer' that represents a sliding window of */
  /*  16 samples at a time. */
  y_size[0] = (int16_T)x_size[0];
  loop_ub = (int16_T)x_size[0];
  for (k = 0; k < loop_ub; k++) {
    y_data[k] = 0.0;
  }

  for (loop_ub = 0; loop_ub < x_size[0]; loop_ub++) {
    /*  Scroll the buffer */
    memcpy(&dv0[0], &buffer[0], 15U * sizeof(real_T));
    memcpy(&buffer[1], &dv0[0], 15U * sizeof(real_T));

    /*  Add a new sample value to the buffer */
    buffer[0] = x_data[loop_ub];

    /*  Compute the current average value of the window and */
    /*  write result */
    y = buffer[0];
    for (k = 0; k < 15; k++) {
      y += buffer[k + 1];
    }

    y_data[loop_ub] = y / 16.0;
  }
}

/* End of code generation (averaging_filter.c) */
