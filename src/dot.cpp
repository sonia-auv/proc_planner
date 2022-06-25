//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: dot.cpp
//
// MATLAB Coder version            : 5.4
// C/C++ source code generated on  : 25-Jun-2022 15:23:16
//

// Include Files
#include "dot.h"
#include "rt_nonfinite.h"

// Function Definitions
//
// Arguments    : const double a[3]
//                const double b[3]
// Return Type  : double
//
namespace coder {
double b_dot(const double a[3], const double b[3])
{
  return (a[0] * b[0] + a[1] * b[1]) + a[2] * b[2];
}

//
// Arguments    : const double a[4]
//                const double b[4]
// Return Type  : double
//
double dot(const double a[4], const double b[4])
{
  return ((a[0] * b[0] + a[1] * b[1]) + a[2] * b[2]) + a[3] * b[3];
}

} // namespace coder

//
// File trailer for dot.cpp
//
// [EOF]
//
