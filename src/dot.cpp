//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: dot.cpp
//
// MATLAB Coder version            : 5.4
// C/C++ source code generated on  : 12-Apr-2022 11:44:16
//

// Include Files
#include "dot.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <string.h>

// Function Definitions
//
// Arguments    : const double a[4]
//                const double b[4]
// Return Type  : double
//
namespace coder {
double b_dot(const double a[4], const double b[4])
{
  return ((a[0] * b[0] + a[1] * b[1]) + a[2] * b[2]) + a[3] * b[3];
}

//
// Arguments    : const double a[3]
//                const double b[3]
// Return Type  : double
//
double dot(const double a[3], const double b[3])
{
  return (a[0] * b[0] + a[1] * b[1]) + a[2] * b[2];
}

//
// Arguments    : const ::coder::array<double, 2U> &a
//                const ::coder::array<double, 2U> &b
//                ::coder::array<double, 1U> &c
// Return Type  : void
//
void dot(const ::coder::array<double, 2U> &a,
         const ::coder::array<double, 2U> &b, ::coder::array<double, 1U> &c)
{
  int i1;
  int vstride;
  c.set_size(a.size(0));
  vstride = a.size(0);
  i1 = -1;
  for (int j{0}; j < vstride; j++) {
    i1++;
    c[j] = (a[i1] * b[i1] + a[i1 + vstride] * b[i1 + vstride]) +
           a[i1 + (vstride << 1)] * b[i1 + (vstride << 1)];
  }
}

} // namespace coder

//
// File trailer for dot.cpp
//
// [EOF]
//
