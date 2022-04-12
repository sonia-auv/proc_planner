//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: normalize.cpp
//
// MATLAB Coder version            : 5.4
// C/C++ source code generated on  : 12-Apr-2022 11:44:16
//

// Include Files
#include "normalize.h"
#include "quaternion.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <string.h>

// Function Definitions
//
// Arguments    : coder::array<double, 2U> &in1
//                const coder::quaternion *in2
// Return Type  : void
//
void binary_expand_op(coder::array<double, 2U> &in1,
                      const coder::quaternion *in2)
{
  int i;
  int loop_ub;
  int stride_0_1;
  int stride_1_1;
  int stride_2_1;
  int stride_3_1;
  if (in2->d.size(1) == 1) {
    if (in2->c.size(1) == 1) {
      if (in2->b.size(1) == 1) {
        i = in2->a.size(1);
      } else {
        i = in2->b.size(1);
      }
    } else {
      i = in2->c.size(1);
    }
  } else {
    i = in2->d.size(1);
  }
  in1.set_size(1, i);
  stride_0_1 = (in2->a.size(1) != 1);
  stride_1_1 = (in2->b.size(1) != 1);
  stride_2_1 = (in2->c.size(1) != 1);
  stride_3_1 = (in2->d.size(1) != 1);
  if (in2->d.size(1) == 1) {
    if (in2->c.size(1) == 1) {
      if (in2->b.size(1) == 1) {
        loop_ub = in2->a.size(1);
      } else {
        loop_ub = in2->b.size(1);
      }
    } else {
      loop_ub = in2->c.size(1);
    }
  } else {
    loop_ub = in2->d.size(1);
  }
  for (i = 0; i < loop_ub; i++) {
    double d;
    double d1;
    double d2;
    d = in2->b[i * stride_1_1];
    d1 = in2->c[i * stride_2_1];
    d2 = in2->d[i * stride_3_1];
    in1[i] =
        ((in2->a[i * stride_0_1] * in2->a[i * stride_0_1] + d * d) + d1 * d1) +
        d2 * d2;
  }
}

//
// Arguments    : coder::array<double, 2U> &in1
//                const coder::array<double, 2U> &in2
//                const coder::array<double, 2U> &in3
//                const coder::array<double, 2U> &in4
//                const coder::array<double, 2U> &in5
// Return Type  : void
//
void e_binary_expand_op(coder::array<double, 2U> &in1,
                        const coder::array<double, 2U> &in2,
                        const coder::array<double, 2U> &in3,
                        const coder::array<double, 2U> &in4,
                        const coder::array<double, 2U> &in5)
{
  int i;
  int loop_ub;
  int stride_0_1;
  int stride_1_1;
  int stride_2_1;
  int stride_3_1;
  if (in5.size(1) == 1) {
    if (in4.size(1) == 1) {
      if (in3.size(1) == 1) {
        i = in2.size(1);
      } else {
        i = in3.size(1);
      }
    } else {
      i = in4.size(1);
    }
  } else {
    i = in5.size(1);
  }
  in1.set_size(1, i);
  stride_0_1 = (in2.size(1) != 1);
  stride_1_1 = (in3.size(1) != 1);
  stride_2_1 = (in4.size(1) != 1);
  stride_3_1 = (in5.size(1) != 1);
  if (in5.size(1) == 1) {
    if (in4.size(1) == 1) {
      if (in3.size(1) == 1) {
        loop_ub = in2.size(1);
      } else {
        loop_ub = in3.size(1);
      }
    } else {
      loop_ub = in4.size(1);
    }
  } else {
    loop_ub = in5.size(1);
  }
  for (i = 0; i < loop_ub; i++) {
    double d;
    double d1;
    double d2;
    d = in3[i * stride_1_1];
    d1 = in4[i * stride_2_1];
    d2 = in5[i * stride_3_1];
    in1[i] = ((in2[i * stride_0_1] * in2[i * stride_0_1] + d * d) + d1 * d1) +
             d2 * d2;
  }
}

//
// File trailer for normalize.cpp
//
// [EOF]
//
