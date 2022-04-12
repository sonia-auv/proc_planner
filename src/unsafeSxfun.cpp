//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: unsafeSxfun.cpp
//
// MATLAB Coder version            : 5.4
// C/C++ source code generated on  : 12-Apr-2022 11:44:16
//

// Include Files
#include "unsafeSxfun.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <string.h>

// Function Definitions
//
// Arguments    : coder::array<double, 1U> &in1
//                const coder::array<double, 1U> &in3
//                const coder::array<double, 1U> &in4
// Return Type  : void
//
void e_binary_expand_op(coder::array<double, 1U> &in1,
                        const coder::array<double, 1U> &in3,
                        const coder::array<double, 1U> &in4)
{
  coder::array<double, 1U> b_in3;
  int i;
  int loop_ub;
  int stride_0_0;
  int stride_1_0;
  if (in4.size(0) == 1) {
    i = in3.size(0);
  } else {
    i = in4.size(0);
  }
  b_in3.set_size(i);
  stride_0_0 = (in3.size(0) != 1);
  stride_1_0 = (in4.size(0) != 1);
  if (in4.size(0) == 1) {
    loop_ub = in3.size(0);
  } else {
    loop_ub = in4.size(0);
  }
  for (i = 0; i < loop_ub; i++) {
    b_in3[i] = in3[i * stride_0_0] - in4[i * stride_1_0];
  }
  in1.set_size(b_in3.size(0));
  loop_ub = b_in3.size(0);
  for (i = 0; i < loop_ub; i++) {
    double varargin_1;
    varargin_1 = b_in3[i];
    in1[i] = varargin_1 * varargin_1;
  }
}

//
// File trailer for unsafeSxfun.cpp
//
// [EOF]
//
