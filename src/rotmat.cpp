//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: rotmat.cpp
//
// MATLAB Coder version            : 5.4
// C/C++ source code generated on  : 12-Apr-2022 11:44:16
//

// Include Files
#include "rotmat.h"
#include "quaternion.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <string.h>

// Function Definitions
//
// Arguments    : coder::array<double, 1U> &in1
//                const coder::quaternion *in2
// Return Type  : void
//
void binary_expand_op(coder::array<double, 1U> &in1,
                      const coder::quaternion *in2)
{
  int b_in2_idx_0;
  int c_in2_idx_0;
  int in2_idx_0;
  int stride_1_0;
  in2_idx_0 = in2->c.size(1);
  b_in2_idx_0 = in2->d.size(1);
  if (b_in2_idx_0 == 1) {
    c_in2_idx_0 = in2_idx_0;
  } else {
    c_in2_idx_0 = b_in2_idx_0;
  }
  in1.set_size(c_in2_idx_0);
  c_in2_idx_0 = (in2_idx_0 != 1);
  stride_1_0 = (b_in2_idx_0 != 1);
  if (b_in2_idx_0 != 1) {
    in2_idx_0 = b_in2_idx_0;
  }
  for (b_in2_idx_0 = 0; b_in2_idx_0 < in2_idx_0; b_in2_idx_0++) {
    in1[b_in2_idx_0] = in2->c[b_in2_idx_0 * c_in2_idx_0] *
                       in2->d[b_in2_idx_0 * stride_1_0] * 2.0;
  }
}

//
// Arguments    : coder::array<double, 1U> &in1
//                const coder::quaternion *in2
// Return Type  : void
//
void e_binary_expand_op(coder::array<double, 1U> &in1,
                        const coder::quaternion *in2)
{
  int b_in2_idx_0;
  int c_in2_idx_0;
  int in2_idx_0;
  int stride_1_0;
  in2_idx_0 = in2->b.size(1);
  b_in2_idx_0 = in2->d.size(1);
  if (b_in2_idx_0 == 1) {
    c_in2_idx_0 = in2_idx_0;
  } else {
    c_in2_idx_0 = b_in2_idx_0;
  }
  in1.set_size(c_in2_idx_0);
  c_in2_idx_0 = (in2_idx_0 != 1);
  stride_1_0 = (b_in2_idx_0 != 1);
  if (b_in2_idx_0 != 1) {
    in2_idx_0 = b_in2_idx_0;
  }
  for (b_in2_idx_0 = 0; b_in2_idx_0 < in2_idx_0; b_in2_idx_0++) {
    in1[b_in2_idx_0] = in2->b[b_in2_idx_0 * c_in2_idx_0] *
                       in2->d[b_in2_idx_0 * stride_1_0] * 2.0;
  }
}

//
// Arguments    : coder::array<double, 1U> &in1
//                const coder::quaternion *in2
// Return Type  : void
//
void f_binary_expand_op(coder::array<double, 1U> &in1,
                        const coder::quaternion *in2)
{
  int b_in2_idx_0;
  int c_in2_idx_0;
  int in2_idx_0;
  int stride_1_0;
  in2_idx_0 = in2->b.size(1);
  b_in2_idx_0 = in2->c.size(1);
  if (b_in2_idx_0 == 1) {
    c_in2_idx_0 = in2_idx_0;
  } else {
    c_in2_idx_0 = b_in2_idx_0;
  }
  in1.set_size(c_in2_idx_0);
  c_in2_idx_0 = (in2_idx_0 != 1);
  stride_1_0 = (b_in2_idx_0 != 1);
  if (b_in2_idx_0 != 1) {
    in2_idx_0 = b_in2_idx_0;
  }
  for (b_in2_idx_0 = 0; b_in2_idx_0 < in2_idx_0; b_in2_idx_0++) {
    in1[b_in2_idx_0] = in2->b[b_in2_idx_0 * c_in2_idx_0] *
                       in2->c[b_in2_idx_0 * stride_1_0] * 2.0;
  }
}

//
// Arguments    : coder::array<double, 1U> &in1
//                const coder::quaternion *in2
// Return Type  : void
//
void g_binary_expand_op(coder::array<double, 1U> &in1,
                        const coder::quaternion *in2)
{
  int b_in2_idx_0;
  int c_in2_idx_0;
  int in2_idx_0;
  int stride_1_0;
  in2_idx_0 = in2->a.size(1);
  b_in2_idx_0 = in2->d.size(1);
  if (b_in2_idx_0 == 1) {
    c_in2_idx_0 = in2_idx_0;
  } else {
    c_in2_idx_0 = b_in2_idx_0;
  }
  in1.set_size(c_in2_idx_0);
  c_in2_idx_0 = (in2_idx_0 != 1);
  stride_1_0 = (b_in2_idx_0 != 1);
  if (b_in2_idx_0 != 1) {
    in2_idx_0 = b_in2_idx_0;
  }
  for (b_in2_idx_0 = 0; b_in2_idx_0 < in2_idx_0; b_in2_idx_0++) {
    in1[b_in2_idx_0] = in2->a[b_in2_idx_0 * c_in2_idx_0] *
                       in2->d[b_in2_idx_0 * stride_1_0] * 2.0;
  }
}

//
// Arguments    : coder::array<double, 1U> &in1
//                const coder::quaternion *in2
// Return Type  : void
//
void h_binary_expand_op(coder::array<double, 1U> &in1,
                        const coder::quaternion *in2)
{
  int b_in2_idx_0;
  int c_in2_idx_0;
  int in2_idx_0;
  int stride_1_0;
  in2_idx_0 = in2->a.size(1);
  b_in2_idx_0 = in2->c.size(1);
  if (b_in2_idx_0 == 1) {
    c_in2_idx_0 = in2_idx_0;
  } else {
    c_in2_idx_0 = b_in2_idx_0;
  }
  in1.set_size(c_in2_idx_0);
  c_in2_idx_0 = (in2_idx_0 != 1);
  stride_1_0 = (b_in2_idx_0 != 1);
  if (b_in2_idx_0 != 1) {
    in2_idx_0 = b_in2_idx_0;
  }
  for (b_in2_idx_0 = 0; b_in2_idx_0 < in2_idx_0; b_in2_idx_0++) {
    in1[b_in2_idx_0] = in2->a[b_in2_idx_0 * c_in2_idx_0] *
                       in2->c[b_in2_idx_0 * stride_1_0] * 2.0;
  }
}

//
// Arguments    : coder::array<double, 1U> &in1
//                const coder::quaternion *in2
// Return Type  : void
//
void i_binary_expand_op(coder::array<double, 1U> &in1,
                        const coder::quaternion *in2)
{
  int b_in2_idx_0;
  int c_in2_idx_0;
  int in2_idx_0;
  int stride_1_0;
  in2_idx_0 = in2->a.size(1);
  b_in2_idx_0 = in2->b.size(1);
  if (b_in2_idx_0 == 1) {
    c_in2_idx_0 = in2_idx_0;
  } else {
    c_in2_idx_0 = b_in2_idx_0;
  }
  in1.set_size(c_in2_idx_0);
  c_in2_idx_0 = (in2_idx_0 != 1);
  stride_1_0 = (b_in2_idx_0 != 1);
  if (b_in2_idx_0 != 1) {
    in2_idx_0 = b_in2_idx_0;
  }
  for (b_in2_idx_0 = 0; b_in2_idx_0 < in2_idx_0; b_in2_idx_0++) {
    in1[b_in2_idx_0] = in2->a[b_in2_idx_0 * c_in2_idx_0] *
                       in2->b[b_in2_idx_0 * stride_1_0] * 2.0;
  }
}

//
// File trailer for rotmat.cpp
//
// [EOF]
//
