//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: discretize.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 09-Feb-2022 14:06:20
//

// Include Files
#include "discretize.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <cmath>
#include <string.h>

// Function Definitions
//
// Arguments    : double x
//                const ::coder::array<double, 1U> &edges
// Return Type  : double
//
namespace coder {
double mapElementsToBins(double x, const ::coder::array<double, 1U> &edges)
{
  double bins;
  bins = rtNaN;
  if ((x >= edges[0]) && (x <= edges[edges.size(0) - 1])) {
    bins = std::ceil((x - edges[0]) / (edges[1] - edges[0]));
    if ((!(bins >= 1.0)) || (!(bins < edges.size(0))) ||
        (!(x >= edges[static_cast<int>(bins) - 1])) ||
        (!(x < edges[static_cast<int>(bins)]))) {
      int high_i;
      int low_i;
      int low_ip1;
      high_i = edges.size(0);
      low_i = 1;
      low_ip1 = 2;
      while (high_i > low_ip1) {
        int mid_i;
        mid_i = (low_i >> 1) + (high_i >> 1);
        if (((low_i & 1) == 1) && ((high_i & 1) == 1)) {
          mid_i++;
        }
        if (x >= edges[mid_i - 1]) {
          low_i = mid_i;
          low_ip1 = mid_i + 1;
        } else {
          high_i = mid_i;
        }
      }
      bins = low_i;
    }
  }
  return bins;
}

} // namespace coder

//
// File trailer for discretize.cpp
//
// [EOF]
//
