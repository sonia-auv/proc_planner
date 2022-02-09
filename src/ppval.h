//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: ppval.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 08-Feb-2022 23:30:50
//

#ifndef PPVAL_H
#define PPVAL_H

// Include Files
#include "rtwtypes.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace coder {
void ppval(const ::coder::array<double, 2U> &pp_breaks,
           const ::coder::array<double, 3U> &pp_coefs,
           const ::coder::array<double, 1U> &x, ::coder::array<double, 2U> &v);

void ppval(const ::coder::array<double, 2U> &pp_breaks,
           const ::coder::array<double, 3U> &pp_coefs, double x,
           ::coder::array<double, 1U> &v);

} // namespace coder

#endif
//
// File trailer for ppval.h
//
// [EOF]
//
