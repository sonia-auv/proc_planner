//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: diff.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 19-Feb-2022 14:46:56
//

// Include Files
#include "diff.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <string.h>

// Function Definitions
//
// Arguments    : const ::coder::array<creal_T, 2U> &x
//                ::coder::array<creal_T, 2U> &y
// Return Type  : void
//
namespace coder {
void diff(const ::coder::array<creal_T, 2U> &x, ::coder::array<creal_T, 2U> &y)
{
  array<creal_T, 1U> work;
  int dimSize;
  dimSize = x.size(1);
  if (x.size(1) == 0) {
    y.set_size(1, 0);
  } else {
    int u0;
    u0 = x.size(1) - 1;
    if (u0 > 1) {
      u0 = 1;
    }
    if (u0 < 1) {
      y.set_size(1, 0);
    } else {
      work.set_size(1);
      y.set_size(1, x.size(1) - 1);
      if (x.size(1) - 1 != 0) {
        work[0] = x[0];
        for (u0 = 2; u0 <= dimSize; u0++) {
          double tmp1_im;
          double tmp1_re;
          double tmp2_im;
          double tmp2_re;
          tmp1_re = x[u0 - 1].re;
          tmp1_im = x[u0 - 1].im;
          tmp2_re = work[0].re;
          tmp2_im = work[0].im;
          work[0].re = tmp1_re;
          work[0].im = tmp1_im;
          tmp1_re -= tmp2_re;
          tmp1_im -= tmp2_im;
          y[u0 - 2].re = tmp1_re;
          y[u0 - 2].im = tmp1_im;
        }
      }
    }
  }
}

} // namespace coder

//
// File trailer for diff.cpp
//
// [EOF]
//
