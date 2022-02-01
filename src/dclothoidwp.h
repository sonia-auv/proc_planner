//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: dclothoidwp.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 01-Feb-2022 18:48:34
//

#ifndef DCLOTHOIDWP_H
#define DCLOTHOIDWP_H

// Include Files
#include "rtwtypes.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace coder {
namespace matlabshared {
namespace tracking {
namespace internal {
namespace scenario {
void dclothoidwp(const ::coder::array<double, 1U> &x,
                 const ::coder::array<double, 1U> &y,
                 const double varargin_1[2], const double varargin_2[2],
                 ::coder::array<double, 1U> &u, ::coder::array<double, 1U> &v);

void dclothoidwp(const ::coder::array<double, 1U> &x,
                 const ::coder::array<double, 1U> &y,
                 ::coder::array<double, 1U> &u, ::coder::array<double, 1U> &v);

} // namespace scenario
} // namespace internal
} // namespace tracking
} // namespace matlabshared
} // namespace coder

#endif
//
// File trailer for dclothoidwp.h
//
// [EOF]
//
