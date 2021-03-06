//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// diff.cpp
//
// Code generation for function 'diff'
//

// Include files
#include "diff.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Definitions
namespace coder {
void diff(const ::coder::array<double, 1U> &x, ::coder::array<double, 1U> &y)
{
  array<double, 1U> work;
  int dimSize;
  dimSize = x.size(0);
  if (x.size(0) == 0) {
    y.set_size(0);
  } else {
    int u0;
    u0 = x.size(0) - 1;
    if (u0 > 1) {
      u0 = 1;
    }
    if (u0 < 1) {
      y.set_size(0);
    } else {
      work.set_size(1);
      y.set_size(x.size(0) - 1);
      if (x.size(0) - 1 != 0) {
        work[0] = x[0];
        for (u0 = 2; u0 <= dimSize; u0++) {
          double tmp2;
          double work_tmp;
          tmp2 = work[0];
          work_tmp = x[u0 - 1];
          work[0] = work_tmp;
          y[u0 - 2] = work_tmp - tmp2;
        }
      }
    }
  }
}

} // namespace coder

// End of code generation (diff.cpp)
