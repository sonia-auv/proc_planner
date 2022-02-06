//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: find.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 05-Feb-2022 14:39:35
//

// Include Files
#include "find.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <string.h>

// Function Definitions
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
    if (1 > idx) {
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
    if (1 > idx) {
      idx = 0;
    }
    i.set_size(idx);
  }
}

} // namespace coder

//
// File trailer for find.cpp
//
// [EOF]
//
