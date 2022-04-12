//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: cat.cpp
//
// MATLAB Coder version            : 5.4
// C/C++ source code generated on  : 12-Apr-2022 11:44:16
//

// Include Files
#include "cat.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <string.h>

// Function Definitions
//
// Arguments    : coder::array<double, 2U> &in1
//                const coder::array<double, 1U> &in2
//                int in3
//                int in4
//                const coder::array<double, 1U> &in5
//                int in6
//                const coder::array<double, 1U> &in7
//                int in8
//                int in9
//                const coder::array<double, 1U> &in10
//                int in11
//                int in12
// Return Type  : void
//
void binary_expand_op(coder::array<double, 2U> &in1,
                      const coder::array<double, 1U> &in2, int in3, int in4,
                      const coder::array<double, 1U> &in5, int in6,
                      const coder::array<double, 1U> &in7, int in8, int in9,
                      const coder::array<double, 1U> &in10, int in11, int in12)
{
  coder::array<double, 1U> b_in5;
  int b_in9;
  int loop_ub;
  int stride_1_0;
  if ((in9 - in8) + 1 == 1) {
    b_in9 = in6 + 1;
  } else {
    b_in9 = (in9 - in8) + 1;
  }
  b_in5.set_size(b_in9);
  b_in9 = (in6 + 1 != 1);
  stride_1_0 = ((in9 - in8) + 1 != 1);
  if ((in9 - in8) + 1 == 1) {
    loop_ub = in6 + 1;
  } else {
    loop_ub = (in9 - in8) + 1;
  }
  for (int i{0}; i < loop_ub; i++) {
    b_in5[i] = in5[i * b_in9] - in7[in8 + i * stride_1_0];
  }
  loop_ub = in4 - in3;
  in1.set_size(loop_ub + 2, 3);
  for (int i{0}; i <= loop_ub; i++) {
    in1[i] = in2[in3 + i];
  }
  in1[loop_ub + 1] = 0.0;
  loop_ub = b_in5.size(0);
  for (int i{0}; i < loop_ub; i++) {
    in1[i + in1.size(0)] = b_in5[i];
  }
  b_in9 = in12 - in11;
  for (int i{0}; i <= b_in9; i++) {
    in1[i + in1.size(0) * 2] = -in10[in11 + i];
  }
  in1[(b_in9 + in1.size(0) * 2) + 1] = 0.0;
}

//
// Arguments    : coder::array<double, 2U> &in1
//                const coder::array<double, 1U> &in2
//                int in3
//                int in4
//                const coder::array<double, 1U> &in5
//                int in6
//                const coder::array<double, 1U> &in7
//                int in8
//                int in9
//                const coder::array<double, 2U> &in10
//                const coder::array<double, 1U> &in11
//                int in12
//                int in13
// Return Type  : void
//
void binary_expand_op(coder::array<double, 2U> &in1,
                      const coder::array<double, 1U> &in2, int in3, int in4,
                      const coder::array<double, 1U> &in5, int in6,
                      const coder::array<double, 1U> &in7, int in8, int in9,
                      const coder::array<double, 2U> &in10,
                      const coder::array<double, 1U> &in11, int in12, int in13)
{
  coder::array<double, 1U> b_in5;
  int b_in9;
  int loop_ub;
  int stride_1_0;
  if ((in9 - in8) + 1 == 1) {
    b_in9 = in6 + 1;
  } else {
    b_in9 = (in9 - in8) + 1;
  }
  b_in5.set_size(b_in9);
  b_in9 = (in6 + 1 != 1);
  stride_1_0 = ((in9 - in8) + 1 != 1);
  if ((in9 - in8) + 1 == 1) {
    loop_ub = in6 + 1;
  } else {
    loop_ub = (in9 - in8) + 1;
  }
  for (int i{0}; i < loop_ub; i++) {
    b_in5[i] = in5[i * b_in9] - in7[in8 + i * stride_1_0];
  }
  loop_ub = in4 - in3;
  in1.set_size(loop_ub + 2, 3);
  for (int i{0}; i <= loop_ub; i++) {
    in1[i] = in2[in3 + i];
  }
  in1[loop_ub + 1] = 0.0;
  loop_ub = b_in5.size(0);
  for (int i{0}; i < loop_ub; i++) {
    in1[i + in1.size(0)] = b_in5[i];
  }
  in1[b_in5.size(0) + in1.size(0)] = in5[in10.size(0) - 2];
  b_in9 = in13 - in12;
  for (int i{0}; i <= b_in9; i++) {
    in1[i + in1.size(0) * 2] = -in11[in12 + i];
  }
  in1[(b_in9 + in1.size(0) * 2) + 1] = 0.0;
}

//
// Arguments    : coder::array<double, 2U> &in1
//                const coder::array<double, 1U> &in2
//                int in3
//                const coder::array<double, 1U> &in4
//                const coder::array<double, 1U> &in5
//                int in6
//                int in7
//                int in8
//                const coder::array<double, 1U> &in9
//                int in10
// Return Type  : void
//
void binary_expand_op(coder::array<double, 2U> &in1,
                      const coder::array<double, 1U> &in2, int in3,
                      const coder::array<double, 1U> &in4,
                      const coder::array<double, 1U> &in5, int in6, int in7,
                      int in8, const coder::array<double, 1U> &in9, int in10)
{
  coder::array<double, 1U> b_in5;
  int b_in8;
  int loop_ub;
  int stride_1_0;
  if ((in8 - in7) + 1 == 1) {
    b_in8 = in6 + 1;
  } else {
    b_in8 = (in8 - in7) + 1;
  }
  b_in5.set_size(b_in8);
  b_in8 = (in6 + 1 != 1);
  stride_1_0 = ((in8 - in7) + 1 != 1);
  if ((in8 - in7) + 1 == 1) {
    loop_ub = in6 + 1;
  } else {
    loop_ub = (in8 - in7) + 1;
  }
  for (int i{0}; i < loop_ub; i++) {
    b_in5[i] = in5[i * b_in8] - in4[in7 + i * stride_1_0];
  }
  in1.set_size(in3 + 2, 3);
  for (int i{0}; i <= in3; i++) {
    in1[i] = in2[i];
  }
  in1[in3 + 1] = 0.0;
  in1[in1.size(0)] = 0.0 - in4[0];
  loop_ub = b_in5.size(0);
  for (int i{0}; i < loop_ub; i++) {
    in1[(i + in1.size(0)) + 1] = b_in5[i];
  }
  for (int i{0}; i <= in10; i++) {
    in1[i + in1.size(0) * 2] = -in9[i];
  }
  in1[(in10 + in1.size(0) * 2) + 1] = 0.0;
}

//
// Arguments    : coder::array<double, 2U> &in1
//                const coder::array<double, 1U> &in2
//                const coder::array<double, 1U> &in3
//                const coder::array<double, 1U> &in4
//                int in5
//                int in6
//                int in7
//                const coder::array<double, 2U> &in8
//                const coder::array<double, 1U> &in9
// Return Type  : void
//
void binary_expand_op(coder::array<double, 2U> &in1,
                      const coder::array<double, 1U> &in2,
                      const coder::array<double, 1U> &in3,
                      const coder::array<double, 1U> &in4, int in5, int in6,
                      int in7, const coder::array<double, 2U> &in8,
                      const coder::array<double, 1U> &in9)
{
  coder::array<double, 1U> b_in4;
  int b_in7;
  int loop_ub;
  int stride_1_0;
  if ((in7 - in6) + 1 == 1) {
    b_in7 = in5 + 1;
  } else {
    b_in7 = (in7 - in6) + 1;
  }
  b_in4.set_size(b_in7);
  b_in7 = (in5 + 1 != 1);
  stride_1_0 = ((in7 - in6) + 1 != 1);
  if ((in7 - in6) + 1 == 1) {
    loop_ub = in5 + 1;
  } else {
    loop_ub = (in7 - in6) + 1;
  }
  for (int i{0}; i < loop_ub; i++) {
    b_in4[i] = in4[i * b_in7] - in3[in6 + i * stride_1_0];
  }
  in1.set_size(in2.size(0) + 1, 3);
  loop_ub = in2.size(0);
  for (int i{0}; i < loop_ub; i++) {
    in1[i] = in2[i];
  }
  in1[in2.size(0)] = 0.0;
  in1[in1.size(0)] = 0.0 - in3[0];
  loop_ub = b_in4.size(0);
  for (int i{0}; i < loop_ub; i++) {
    in1[(i + in1.size(0)) + 1] = b_in4[i];
  }
  in1[(b_in4.size(0) + in1.size(0)) + 1] = in4[in8.size(0) - 2];
  loop_ub = in9.size(0);
  for (int i{0}; i < loop_ub; i++) {
    in1[i + in1.size(0) * 2] = -in9[i];
  }
  in1[in9.size(0) + in1.size(0) * 2] = 0.0;
}

//
// Arguments    : coder::array<double, 2U> &in1
//                const coder::array<double, 1U> &in2
//                const coder::array<double, 1U> &in3
//                const coder::array<double, 1U> &in4
//                const coder::array<double, 1U> &in5
// Return Type  : void
//
void binary_expand_op(coder::array<double, 2U> &in1,
                      const coder::array<double, 1U> &in2,
                      const coder::array<double, 1U> &in3,
                      const coder::array<double, 1U> &in4,
                      const coder::array<double, 1U> &in5)
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
  in1.set_size(in2.size(0), 3);
  loop_ub = in2.size(0);
  for (i = 0; i < loop_ub; i++) {
    in1[i] = in2[i];
  }
  loop_ub = b_in3.size(0);
  for (i = 0; i < loop_ub; i++) {
    in1[i + in1.size(0)] = b_in3[i];
  }
  loop_ub = in5.size(0);
  for (i = 0; i < loop_ub; i++) {
    in1[i + in1.size(0) * 2] = -in5[i];
  }
}

//
// File trailer for cat.cpp
//
// [EOF]
//
