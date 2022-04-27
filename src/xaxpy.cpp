//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: xaxpy.cpp
//
// MATLAB Coder version            : 5.4
// C/C++ source code generated on  : 26-Apr-2022 22:23:20
//

// Include Files
#include "xaxpy.h"
#include "rt_nonfinite.h"

// Function Definitions
//
// Arguments    : double a
//                const double x[12]
//                int ix0
//                double y[4]
// Return Type  : void
//
namespace coder {
namespace internal {
namespace blas {
void xaxpy(double a, const double x[12], int ix0, double y[4])
{
  if (!(a == 0.0)) {
    for (int k{0}; k < 3; k++) {
      y[k + 1] += a * x[(ix0 + k) - 1];
    }
  }
}

//
// Arguments    : double a
//                const double x[4]
//                double y[12]
//                int iy0
// Return Type  : void
//
void xaxpy(double a, const double x[4], double y[12], int iy0)
{
  if (!(a == 0.0)) {
    for (int k{0}; k < 3; k++) {
      int i;
      i = (iy0 + k) - 1;
      y[i] += a * x[k + 1];
    }
  }
}

//
// Arguments    : int n
//                double a
//                int ix0
//                double y[12]
//                int iy0
// Return Type  : void
//
void xaxpy(int n, double a, int ix0, double y[12], int iy0)
{
  if ((n >= 1) && (!(a == 0.0))) {
    int i;
    i = n - 1;
    for (int k{0}; k <= i; k++) {
      int i1;
      i1 = (iy0 + k) - 1;
      y[i1] += a * y[(ix0 + k) - 1];
    }
  }
}

//
// Arguments    : double a
//                double y[9]
//                int iy0
// Return Type  : void
//
void xaxpy(double a, double y[9], int iy0)
{
  if (!(a == 0.0)) {
    for (int k{0}; k < 2; k++) {
      int i;
      i = (iy0 + k) - 1;
      y[i] += a * y[k + 1];
    }
  }
}

} // namespace blas
} // namespace internal
} // namespace coder

//
// File trailer for xaxpy.cpp
//
// [EOF]
//
