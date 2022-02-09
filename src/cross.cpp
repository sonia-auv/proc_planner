//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: cross.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 08-Feb-2022 23:30:50
//

// Include Files
#include "cross.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <string.h>

// Function Definitions
//
// Arguments    : const ::coder::array<double, 2U> &a
//                const ::coder::array<double, 2U> &b
//                ::coder::array<double, 2U> &c
// Return Type  : void
//
namespace coder {
void cross(const ::coder::array<double, 2U> &a,
           const ::coder::array<double, 2U> &b, ::coder::array<double, 2U> &c)
{
  c.set_size(a.size(0), 3);
  if (a.size(0) != 0) {
    int iNext;
    int stride;
    stride = a.size(0);
    iNext = a.size(0) * 3;
    for (int iStart{1}; iNext < 0 ? iStart >= 1 : iStart <= 1;
         iStart += iNext) {
      for (int i1{1}; i1 <= stride; i1++) {
        int i2;
        int i3;
        i2 = (i1 + stride) - 1;
        i3 = i2 + stride;
        c[i1 - 1] = a[i2] * b[i3] - a[i3] * b[i2];
        c[i2] = a[i3] * b[i1 - 1] - a[i1 - 1] * b[i3];
        c[i3] = a[i1 - 1] * b[i2] - a[i2] * b[i1 - 1];
      }
    }
  }
}

} // namespace coder

//
// File trailer for cross.cpp
//
// [EOF]
//
