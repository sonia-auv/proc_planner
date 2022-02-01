//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: fresnel.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 01-Feb-2022 18:48:34
//

#ifndef FRESNEL_H
#define FRESNEL_H

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
void fresnel(const ::coder::array<double, 2U> &x,
             ::coder::array<creal_T, 2U> &z);

void fresnelr(const ::coder::array<double, 1U> &x,
              ::coder::array<creal_T, 1U> &z);

} // namespace scenario
} // namespace internal
} // namespace tracking
} // namespace matlabshared
} // namespace coder

#endif
//
// File trailer for fresnel.h
//
// [EOF]
//
