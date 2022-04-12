//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: eml_mtimes_helper.cpp
//
// MATLAB Coder version            : 5.4
// C/C++ source code generated on  : 12-Apr-2022 11:44:16
//

// Include Files
#include "eml_mtimes_helper.h"
#include "proc_planner_data.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <string.h>

// Function Definitions
//
// Arguments    : coder::array<double, 1U> &in1
//                const coder::array<double, 1U> &in2
//                const coder::array<double, 1U> &in3
//                double in4
// Return Type  : void
//
void binary_expand_op(coder::array<double, 1U> &in1,
                      const coder::array<double, 1U> &in2,
                      const coder::array<double, 1U> &in3, double in4)
{
  coder::array<double, 1U> b_in1;
  int i;
  int loop_ub;
  int stride_0_0;
  int stride_1_0;
  int stride_2_0;
  if (in3.size(0) == 1) {
    if (in2.size(0) == 1) {
      i = in1.size(0);
    } else {
      i = in2.size(0);
    }
  } else {
    i = in3.size(0);
  }
  b_in1.set_size(i);
  stride_0_0 = (in1.size(0) != 1);
  stride_1_0 = (in2.size(0) != 1);
  stride_2_0 = (in3.size(0) != 1);
  if (in3.size(0) == 1) {
    if (in2.size(0) == 1) {
      loop_ub = in1.size(0);
    } else {
      loop_ub = in2.size(0);
    }
  } else {
    loop_ub = in3.size(0);
  }
  for (i = 0; i < loop_ub; i++) {
    b_in1[i] =
        ((in1[i * stride_0_0] + in2[i * stride_1_0]) + in3[i * stride_2_0]) *
        (in4 + 1.0);
  }
  in1.set_size(b_in1.size(0));
  loop_ub = b_in1.size(0);
  for (i = 0; i < loop_ub; i++) {
    in1[i] = b_in1[i];
  }
}

//
// Arguments    : coder::array<creal_T, 1U> &in1
//                const coder::array<double, 1U> &in3
//                const coder::array<double, 1U> &in4
// Return Type  : void
//
void binary_expand_op(coder::array<creal_T, 1U> &in1,
                      const coder::array<double, 1U> &in3,
                      const coder::array<double, 1U> &in4)
{
  int i;
  int loop_ub;
  int stride_0_0;
  int stride_1_0;
  if (in4.size(0) == 1) {
    i = in3.size(0);
  } else {
    i = in4.size(0);
  }
  in1.set_size(i);
  stride_0_0 = (in3.size(0) != 1);
  stride_1_0 = (in4.size(0) != 1);
  if (in4.size(0) == 1) {
    loop_ub = in3.size(0);
  } else {
    loop_ub = in4.size(0);
  }
  for (i = 0; i < loop_ub; i++) {
    double d;
    d = in4[i * stride_1_0];
    in1[i].re = (in3[i * stride_0_0] - d) * 0.0;
    in1[i].im = in3[i * stride_0_0] - d;
  }
}

//
// Arguments    : coder::array<creal_T, 1U> &in1
//                const coder::array<double, 1U> &in3
//                const coder::array<double, 1U> &in4
//                const coder::array<double, 1U> &in5
// Return Type  : void
//
void binary_expand_op(coder::array<creal_T, 1U> &in1,
                      const coder::array<double, 1U> &in3,
                      const coder::array<double, 1U> &in4,
                      const coder::array<double, 1U> &in5)
{
  int i;
  int loop_ub;
  int stride_0_0;
  int stride_1_0;
  int stride_2_0;
  if (in5.size(0) == 1) {
    i = in4.size(0);
  } else {
    i = in5.size(0);
  }
  if (i == 1) {
    i = in3.size(0);
  } else if (in5.size(0) == 1) {
    i = in4.size(0);
  } else {
    i = in5.size(0);
  }
  in1.set_size(i);
  stride_0_0 = (in3.size(0) != 1);
  stride_1_0 = (in4.size(0) != 1);
  stride_2_0 = (in5.size(0) != 1);
  if (in5.size(0) == 1) {
    i = in4.size(0);
  } else {
    i = in5.size(0);
  }
  if (i == 1) {
    loop_ub = in3.size(0);
  } else if (in5.size(0) == 1) {
    loop_ub = in4.size(0);
  } else {
    loop_ub = in5.size(0);
  }
  for (i = 0; i < loop_ub; i++) {
    double d;
    d = in4[i * stride_1_0] / in5[i * stride_2_0];
    in1[i].re = (in3[i * stride_0_0] - d) * 0.0;
    in1[i].im = in3[i * stride_0_0] - d;
  }
}

//
// Arguments    : coder::array<creal_T, 1U> &in1
//                const coder::array<creal_T, 1U> &in2
//                const coder::array<double, 1U> &in3
// Return Type  : void
//
void binary_expand_op(coder::array<creal_T, 1U> &in1,
                      const coder::array<creal_T, 1U> &in2,
                      const coder::array<double, 1U> &in3)
{
  int i;
  int loop_ub;
  int stride_0_0;
  int stride_1_0;
  if (in3.size(0) == 1) {
    i = in2.size(0);
  } else {
    i = in3.size(0);
  }
  in1.set_size(i);
  stride_0_0 = (in2.size(0) != 1);
  stride_1_0 = (in3.size(0) != 1);
  if (in3.size(0) == 1) {
    loop_ub = in2.size(0);
  } else {
    loop_ub = in3.size(0);
  }
  for (i = 0; i < loop_ub; i++) {
    double ai;
    double br;
    double in2_im;
    double in2_re;
    in2_im = in2[i * stride_0_0].re;
    ai = in2[i * stride_0_0].im;
    br = in3[i * stride_1_0];
    if (ai == 0.0) {
      in2_re = in2_im / br;
      in2_im = 0.0;
    } else if (in2_im == 0.0) {
      in2_re = 0.0;
      in2_im = ai / br;
    } else {
      in2_re = in2_im / br;
      in2_im = ai / br;
    }
    in1[i].re = -2.0 * in2_re;
    in1[i].im = -2.0 * in2_im;
  }
}

//
// File trailer for eml_mtimes_helper.cpp
//
// [EOF]
//
