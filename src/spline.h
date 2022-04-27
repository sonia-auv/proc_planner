//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: spline.h
//
// MATLAB Coder version            : 5.4
// C/C++ source code generated on  : 26-Apr-2022 22:23:20
//

#ifndef SPLINE_H
#define SPLINE_H

// Include Files
#include "rtwtypes.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace coder {
void spline(const ::coder::array<double, 1U> &x,
            const ::coder::array<double, 2U> &y,
            ::coder::array<double, 2U> &output_breaks,
            ::coder::array<double, 2U> &output_coefs);

}

#endif
//
// File trailer for spline.h
//
// [EOF]
//
