//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: accumarray.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 09-Feb-2022 14:06:20
//

// Include Files
#include "accumarray.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <string.h>

// Function Definitions
//
// Arguments    : const ::coder::array<double, 2U> &subs
//                const ::coder::array<double, 1U> &val
//                const double sz[2]
//                ::coder::array<double, 2U> &A
// Return Type  : void
//
namespace coder {
void accumarray(const ::coder::array<double, 2U> &subs,
                const ::coder::array<double, 1U> &val, const double sz[2],
                ::coder::array<double, 2U> &A)
{
  array<int, 2U> counts;
  array<bool, 2U> filled;
  if (val.size(0) == 1) {
    int k;
    int loop_ub_tmp;
    int nsubs;
    nsubs = subs.size(0);
    counts.set_size(static_cast<int>(sz[0]), static_cast<int>(sz[1]));
    loop_ub_tmp = static_cast<int>(sz[0]) * static_cast<int>(sz[1]);
    for (k = 0; k < loop_ub_tmp; k++) {
      counts[k] = 0;
    }
    for (k = 0; k < nsubs; k++) {
      double s_idx_0;
      double s_idx_1;
      s_idx_0 = subs[k];
      s_idx_1 = subs[k + subs.size(0)];
      counts[(static_cast<int>(s_idx_0) +
              counts.size(0) * (static_cast<int>(s_idx_1) - 1)) -
             1] = counts[(static_cast<int>(s_idx_0) +
                          counts.size(0) * (static_cast<int>(s_idx_1) - 1)) -
                         1] +
                  1;
    }
    A.set_size(static_cast<int>(sz[0]), static_cast<int>(sz[1]));
    for (k = 0; k < loop_ub_tmp; k++) {
      if (counts[k] == 0) {
        A[k] = 0.0;
      } else {
        A[k] = static_cast<double>(counts[k]) * val[0];
      }
    }
  } else {
    int k;
    int loop_ub_tmp;
    int nsubs;
    nsubs = subs.size(0);
    filled.set_size(static_cast<int>(sz[0]), static_cast<int>(sz[1]));
    loop_ub_tmp = static_cast<int>(sz[0]) * static_cast<int>(sz[1]);
    A.set_size(static_cast<int>(sz[0]), static_cast<int>(sz[1]));
    for (k = 0; k < loop_ub_tmp; k++) {
      filled[k] = true;
      A[k] = 0.0;
    }
    for (k = 0; k < nsubs; k++) {
      double s_idx_0;
      double s_idx_1;
      s_idx_0 = subs[k];
      s_idx_1 = subs[k + subs.size(0)];
      if (filled[(static_cast<int>(s_idx_0) +
                  filled.size(0) * (static_cast<int>(s_idx_1) - 1)) -
                 1]) {
        filled[(static_cast<int>(s_idx_0) +
                filled.size(0) * (static_cast<int>(s_idx_1) - 1)) -
               1] = false;
        A[(static_cast<int>(s_idx_0) +
           A.size(0) * (static_cast<int>(s_idx_1) - 1)) -
          1] = val[k];
      } else {
        A[(static_cast<int>(s_idx_0) +
           A.size(0) * (static_cast<int>(s_idx_1) - 1)) -
          1] = A[(static_cast<int>(s_idx_0) +
                  A.size(0) * (static_cast<int>(s_idx_1) - 1)) -
                 1] +
               val[k];
      }
    }
  }
}

} // namespace coder

//
// File trailer for accumarray.cpp
//
// [EOF]
//
