//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: find.cpp
//
// MATLAB Coder version            : 5.4
// C/C++ source code generated on  : 12-Apr-2022 11:44:16
//

// Include Files
#include "find.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <string.h>

// Function Definitions
//
// Arguments    : coder::array<int, 1U> &in1
//                const coder::array<double, 1U> &in2
//                const coder::array<double, 1U> &in3
// Return Type  : void
//
void binary_expand_op(coder::array<int, 1U> &in1,
                      const coder::array<double, 1U> &in2,
                      const coder::array<double, 1U> &in3)
{
  coder::array<bool, 1U> b_in2;
  int i;
  int loop_ub;
  int stride_0_0;
  int stride_1_0;
  if (in3.size(0) == 1) {
    i = in2.size(0);
  } else {
    i = in3.size(0);
  }
  b_in2.set_size(i);
  stride_0_0 = (in2.size(0) != 1);
  stride_1_0 = (in3.size(0) != 1);
  if (in3.size(0) == 1) {
    loop_ub = in2.size(0);
  } else {
    loop_ub = in3.size(0);
  }
  for (i = 0; i < loop_ub; i++) {
    b_in2[i] = ((in2[i * stride_0_0] == 0.0) && (in3[i * stride_1_0] == 0.0));
  }
  coder::eml_find(b_in2, in1);
}

//
// Arguments    : coder::array<int, 1U> &in1
//                const coder::array<bool, 1U> &in2
//                const coder::array<bool, 1U> &in3
// Return Type  : void
//
void c_binary_expand_op(coder::array<int, 1U> &in1,
                        const coder::array<bool, 1U> &in2,
                        const coder::array<bool, 1U> &in3)
{
  coder::array<bool, 1U> b_in2;
  int i;
  int loop_ub;
  int stride_0_0;
  int stride_1_0;
  if (in3.size(0) == 1) {
    i = in2.size(0);
  } else {
    i = in3.size(0);
  }
  b_in2.set_size(i);
  stride_0_0 = (in2.size(0) != 1);
  stride_1_0 = (in3.size(0) != 1);
  if (in3.size(0) == 1) {
    loop_ub = in2.size(0);
  } else {
    loop_ub = in3.size(0);
  }
  for (i = 0; i < loop_ub; i++) {
    b_in2[i] = (in2[i * stride_0_0] && (!in3[i * stride_1_0]));
  }
  coder::eml_find(b_in2, in1);
}

//
// Arguments    : const ::coder::array<bool, 2U> &x
//                ::coder::array<int, 1U> &i
// Return Type  : void
//
namespace coder {
void b_eml_find(const ::coder::array<bool, 2U> &x, ::coder::array<int, 1U> &i)
{
  int idx;
  int ii;
  int nx;
  bool exitg1;
  nx = x.size(0) * x.size(1);
  idx = 0;
  i.set_size(nx);
  ii = 0;
  exitg1 = false;
  while ((!exitg1) && (ii <= nx - 1)) {
    if (x[ii]) {
      idx++;
      i[idx - 1] = ii + 1;
      if (idx >= nx) {
        exitg1 = true;
      } else {
        ii++;
      }
    } else {
      ii++;
    }
  }
  if (nx == 1) {
    if (idx == 0) {
      i.set_size(0);
    }
  } else {
    if (idx < 1) {
      idx = 0;
    }
    i.set_size(idx);
  }
}

//
// Arguments    : const ::coder::array<bool, 1U> &x
//                ::coder::array<int, 1U> &i
// Return Type  : void
//
void eml_find(const ::coder::array<bool, 1U> &x, ::coder::array<int, 1U> &i)
{
  int idx;
  int ii;
  int nx;
  bool exitg1;
  nx = x.size(0);
  idx = 0;
  i.set_size(x.size(0));
  ii = 0;
  exitg1 = false;
  while ((!exitg1) && (ii <= nx - 1)) {
    if (x[ii]) {
      idx++;
      i[idx - 1] = ii + 1;
      if (idx >= nx) {
        exitg1 = true;
      } else {
        ii++;
      }
    } else {
      ii++;
    }
  }
  if (x.size(0) == 1) {
    if (idx == 0) {
      i.set_size(0);
    }
  } else {
    if (idx < 1) {
      idx = 0;
    }
    i.set_size(idx);
  }
}

//
// Arguments    : coder::array<int, 1U> &in1
//                const coder::array<bool, 1U> &in2
//                const coder::array<bool, 1U> &in3
// Return Type  : void
//
} // namespace coder
void d_binary_expand_op(coder::array<int, 1U> &in1,
                        const coder::array<bool, 1U> &in2,
                        const coder::array<bool, 1U> &in3)
{
  coder::array<bool, 1U> b_in2;
  int i;
  int loop_ub;
  int stride_0_0;
  int stride_1_0;
  if (in3.size(0) == 1) {
    i = in2.size(0);
  } else {
    i = in3.size(0);
  }
  b_in2.set_size(i);
  stride_0_0 = (in2.size(0) != 1);
  stride_1_0 = (in3.size(0) != 1);
  if (in3.size(0) == 1) {
    loop_ub = in2.size(0);
  } else {
    loop_ub = in3.size(0);
  }
  for (i = 0; i < loop_ub; i++) {
    b_in2[i] = ((!in2[i * stride_0_0]) && in3[i * stride_1_0]);
  }
  coder::eml_find(b_in2, in1);
}

//
// File trailer for find.cpp
//
// [EOF]
//
