//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: derivpp.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 02-Feb-2022 17:45:08
//

#ifndef DERIVPP_H
#define DERIVPP_H

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
void derivpp(const ::coder::array<double, 2U> &pp_breaks,
             const ::coder::array<double, 2U> &pp_coefs,
             ::coder::array<double, 2U> &dpp_breaks,
             ::coder::array<double, 3U> &dpp_coefs);

void derivpp(const ::coder::array<double, 2U> &pp_breaks,
             const ::coder::array<double, 3U> &pp_coefs,
             ::coder::array<double, 2U> &dpp_breaks,
             ::coder::array<double, 3U> &dpp_coefs);

} // namespace scenario
} // namespace internal
} // namespace tracking
} // namespace matlabshared
} // namespace coder

#endif
//
// File trailer for derivpp.h
//
// [EOF]
//
