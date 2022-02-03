//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: sum.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 03-Feb-2022 14:08:22
//

// Include Files
#include "sum.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <string.h>

// Function Definitions
//
// Arguments    : const ::coder::array<double, 2U> &x
//                ::coder::array<double, 1U> &y
// Return Type  : void
//
namespace coder {
void sum(const ::coder::array<double, 2U> &x, ::coder::array<double, 1U> &y)
{
  if (x.size(0) == 0) {
    y.set_size(0);
  } else {
    int vstride;
    int xj;
    vstride = x.size(0);
    y.set_size(x.size(0));
    for (xj = 0; xj < vstride; xj++) {
      y[xj] = x[xj];
    }
    for (int k{0}; k < 2; k++) {
      int xoffset;
      xoffset = (k + 1) * vstride;
      for (xj = 0; xj < vstride; xj++) {
        y[xj] = y[xj] + x[xoffset + xj];
      }
    }
  }
}

} // namespace coder

//
// File trailer for sum.cpp
//
// [EOF]
//
