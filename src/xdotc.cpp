//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// xdotc.cpp
//
// Code generation for function 'xdotc'
//

// Include files
#include "xdotc.h"
#include "rt_nonfinite.h"

// Function Definitions
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

// End of code generation (xdotc.cpp)
