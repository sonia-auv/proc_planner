//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: dot.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 19-Feb-2022 14:46:56
//

// Include Files
#include "dot.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <string.h>

// Function Definitions
//
// Arguments    : const ::coder::array<double, 2U> &a
//                const ::coder::array<double, 2U> &b
//                ::coder::array<double, 1U> &c
// Return Type  : void
//
namespace coder {
void dot(const ::coder::array<double, 2U> &a,
         const ::coder::array<double, 2U> &b, ::coder::array<double, 1U> &c)
{
  int i1;
  int vstride;
  c.set_size(a.size(0));
  vstride = a.size(0);
  i1 = -1;
  for (int j{0}; j < vstride; j++) {
    int b_c_tmp;
    int c_tmp;
    i1++;
    c_tmp = i1 + vstride;
    b_c_tmp = i1 + (vstride << 1);
    c[j] = (a[i1] * b[i1] + a[c_tmp] * b[c_tmp]) + a[b_c_tmp] * b[b_c_tmp];
  }
}

} // namespace coder

//
// File trailer for dot.cpp
//
// [EOF]
//
