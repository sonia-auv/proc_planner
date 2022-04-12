//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: getPositionalState.cpp
//
// MATLAB Coder version            : 5.4
// C/C++ source code generated on  : 12-Apr-2022 11:44:16
//

// Include Files
#include "getPositionalState.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <string.h>

// Function Definitions
//
// Arguments    : coder::array<creal_T, 1U> &in1
//                const creal_T in2
//                const coder::array<double, 1U> &in3
//                const creal_T in4
//                const coder::array<double, 1U> &in5
// Return Type  : void
//
void binary_expand_op(coder::array<creal_T, 1U> &in1, const creal_T in2,
                      const coder::array<double, 1U> &in3, const creal_T in4,
                      const coder::array<double, 1U> &in5)
{
  int i;
  int loop_ub;
  int stride_0_0;
  int stride_1_0;
  if (in5.size(0) == 1) {
    i = in3.size(0);
  } else {
    i = in5.size(0);
  }
  in1.set_size(i);
  stride_0_0 = (in3.size(0) != 1);
  stride_1_0 = (in5.size(0) != 1);
  if (in5.size(0) == 1) {
    loop_ub = in3.size(0);
  } else {
    loop_ub = in5.size(0);
  }
  for (i = 0; i < loop_ub; i++) {
    double d;
    d = in5[i * stride_1_0];
    in1[i].re = in2.re * in3[i * stride_0_0] + in4.re * d;
    in1[i].im = in2.im * in3[i * stride_0_0] + in4.im * d;
  }
}

//
// File trailer for getPositionalState.cpp
//
// [EOF]
//
