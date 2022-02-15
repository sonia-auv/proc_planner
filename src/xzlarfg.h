//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: xzlarfg.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 09-Feb-2022 14:06:20
//

#ifndef XZLARFG_H
#define XZLARFG_H

// Include Files
#include "rtwtypes.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace coder {
namespace internal {
namespace reflapack {
double xzlarfg(int n, double *alpha1, ::coder::array<double, 2U> &x, int ix0);

double xzlarfg(int n, double *alpha1, double x[3]);

} // namespace reflapack
} // namespace internal
} // namespace coder

#endif
//
// File trailer for xzlarfg.h
//
// [EOF]
//
