//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: quatmultiply.cpp
//
// MATLAB Coder version            : 5.4
// C/C++ source code generated on  : 07-Jun-2022 23:08:47
//

// Include Files
#include "quatmultiply.h"
#include "rt_nonfinite.h"

// Function Definitions
//
// Arguments    : const double q[4]
//                const double r[4]
//                double qout[4]
// Return Type  : void
//
namespace coder {
void quatmultiply(const double q[4], const double r[4], double qout[4])
{
  qout[0] = ((q[0] * r[0] - q[1] * r[1]) - q[2] * r[2]) - q[3] * r[3];
  qout[1] = (q[0] * r[1] + r[0] * q[1]) + (q[2] * r[3] - r[2] * q[3]);
  qout[2] = (q[0] * r[2] + r[0] * q[2]) + (r[1] * q[3] - q[1] * r[3]);
  qout[3] = (q[0] * r[3] + r[0] * q[3]) + (q[1] * r[2] - r[1] * q[2]);
}

} // namespace coder

//
// File trailer for quatmultiply.cpp
//
// [EOF]
//
