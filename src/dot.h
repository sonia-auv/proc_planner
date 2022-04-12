//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: dot.h
//
// MATLAB Coder version            : 5.4
// C/C++ source code generated on  : 12-Apr-2022 11:44:16
//

#ifndef DOT_H
#define DOT_H

// Include Files
#include "rtwtypes.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace coder {
double b_dot(const double a[4], const double b[4]);

double dot(const double a[3], const double b[3]);

void dot(const ::coder::array<double, 2U> &a,
         const ::coder::array<double, 2U> &b, ::coder::array<double, 1U> &c);

} // namespace coder

#endif
//
// File trailer for dot.h
//
// [EOF]
//
