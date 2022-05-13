//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: xdotc.cpp
//
// MATLAB Coder version            : 5.4
// C/C++ source code generated on  : 12-May-2022 22:37:14
//

// Include Files
#include "xdotc.h"
#include "rt_nonfinite.h"

// Function Definitions
//
// Arguments    : int n
//                const double x[12]
//                int ix0
//                const double y[12]
//                int iy0
// Return Type  : double
//
namespace coder {
namespace internal {
namespace blas {
double xdotc(int n, const double x[12], int ix0, const double y[12], int iy0)
{
  double d;
  d = 0.0;
  if (n >= 1) {
    for (int k{0}; k < n; k++) {
      d += x[(ix0 + k) - 1] * y[(iy0 + k) - 1];
    }
  }
  return d;
}

//
// Arguments    : const double x[9]
//                const double y[9]
//                int iy0
// Return Type  : double
//
double xdotc(const double x[9], const double y[9], int iy0)
{
  double d;
  d = 0.0;
  for (int k{0}; k < 2; k++) {
    d += x[k + 1] * y[(iy0 + k) - 1];
  }
  return d;
}

} // namespace blas
} // namespace internal
} // namespace coder

//
// File trailer for xdotc.cpp
//
// [EOF]
//
