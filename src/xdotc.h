//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// xdotc.h
//
// Code generation for function 'xdotc'
//

#ifndef XDOTC_H
#define XDOTC_H

// Include files
#include "rtwtypes.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace coder {
namespace internal {
namespace blas {
double xdotc(int n, const double x[12], int ix0, const double y[12], int iy0);

double xdotc(const double x[9], const double y[9], int iy0);

} // namespace blas
} // namespace internal
} // namespace coder

#endif
// End of code generation (xdotc.h)
