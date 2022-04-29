//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: xaxpy.h
//
// MATLAB Coder version            : 5.4
// C/C++ source code generated on  : 28-Apr-2022 22:18:34
//

#ifndef XAXPY_H
#define XAXPY_H

// Include Files
#include "rtwtypes.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace coder {
namespace internal {
namespace blas {
void xaxpy(double a, const double x[12], int ix0, double y[4]);

void xaxpy(double a, const double x[4], double y[12], int iy0);

void xaxpy(int n, double a, int ix0, double y[12], int iy0);

void xaxpy(double a, double y[9], int iy0);

} // namespace blas
} // namespace internal
} // namespace coder

#endif
//
// File trailer for xaxpy.h
//
// [EOF]
//
