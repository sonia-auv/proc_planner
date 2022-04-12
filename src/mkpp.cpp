//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: mkpp.cpp
//
// MATLAB Coder version            : 5.4
// C/C++ source code generated on  : 12-Apr-2022 11:44:16
//

// Include Files
#include "mkpp.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <string.h>

// Function Definitions
//
// Arguments    : coder::array<double, 3U> &in1
//                const coder::array<signed char, 2U> &in2
//                const coder::array<double, 2U> &in3
//                const coder::array<double, 2U> &in4
// Return Type  : void
//
void binary_expand_op(coder::array<double, 3U> &in1,
                      const coder::array<signed char, 2U> &in2,
                      const coder::array<double, 2U> &in3,
                      const coder::array<double, 2U> &in4)
{
  coder::array<double, 2U> b_in2;
  int i;
  int loop_ub;
  int stride_0_0;
  int stride_1_0;
  if (in3.size(0) == 1) {
    i = in2.size(0);
  } else {
    i = in3.size(0);
  }
  b_in2.set_size(i, 4);
  stride_0_0 = (in2.size(0) != 1);
  stride_1_0 = (in3.size(0) != 1);
  if (in3.size(0) == 1) {
    loop_ub = in2.size(0);
  } else {
    loop_ub = in3.size(0);
  }
  for (i = 0; i < 4; i++) {
    for (int i1{0}; i1 < loop_ub; i1++) {
      b_in2[i1 + b_in2.size(0) * i] =
          static_cast<double>(in2[i1 * stride_0_0 + in2.size(0) * i]) *
          in3[i1 * stride_1_0 + in3.size(0) * i];
    }
  }
  stride_0_0 = in4.size(1) - 1;
  in1.set_size(1, stride_0_0, 4);
  for (i = 0; i < 4; i++) {
    for (int i1{0}; i1 < stride_0_0; i1++) {
      in1[in1.size(0) * i1 + in1.size(0) * in1.size(1) * i] =
          b_in2[i1 + stride_0_0 * i];
    }
  }
}

//
// File trailer for mkpp.cpp
//
// [EOF]
//
