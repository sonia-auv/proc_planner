//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: quat2eul.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 19-Feb-2022 14:46:56
//

// Include Files
#include "quat2eul.h"
#include "proc_planner_rtwutil.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <cmath>
#include <string.h>

// Function Definitions
//
// Arguments    : double q[4]
//                double eul[3]
// Return Type  : void
//
namespace coder {
void quat2eul(double q[4], double eul[3])
{
  array<double, 1U> r;
  array<double, 1U> x;
  double aSinInput;
  int b_trueCount;
  int k;
  int trueCount;
  bool mask1;
  bool mask2;
  aSinInput = 1.0 / std::sqrt(((q[0] * q[0] + q[1] * q[1]) + q[2] * q[2]) +
                              q[3] * q[3]);
  q[0] *= aSinInput;
  q[1] *= aSinInput;
  q[2] *= aSinInput;
  q[3] *= aSinInput;
  aSinInput = -2.0 * (q[1] * q[3] - q[0] * q[2]);
  mask1 = (aSinInput >= 0.99999999999999778);
  mask2 = (aSinInput <= -0.99999999999999778);
  trueCount = 0;
  if (aSinInput >= 0.99999999999999778) {
    aSinInput = 1.0;
  }
  if (mask2) {
    trueCount = 1;
  }
  for (k = 0; k < trueCount; k++) {
    aSinInput = -1.0;
  }
  double b_eul_tmp;
  double c_eul_tmp;
  double d_eul_tmp;
  double eul_tmp;
  eul_tmp = q[0] * q[0];
  b_eul_tmp = q[1] * q[1];
  c_eul_tmp = q[2] * q[2];
  d_eul_tmp = q[3] * q[3];
  eul[0] = rt_atan2d_snf(2.0 * (q[1] * q[2] + q[0] * q[3]),
                         ((eul_tmp + b_eul_tmp) - c_eul_tmp) - d_eul_tmp);
  eul[1] = std::asin(aSinInput);
  eul[2] = rt_atan2d_snf(2.0 * (q[2] * q[3] + q[0] * q[1]),
                         ((eul_tmp - b_eul_tmp) - c_eul_tmp) + d_eul_tmp);
  trueCount = 0;
  if (mask1 || mask2) {
    trueCount = 1;
  }
  x.set_size(trueCount);
  for (k = 0; k < trueCount; k++) {
    x[0] = aSinInput;
  }
  for (k = 0; k < trueCount; k++) {
    aSinInput = x[0];
    if (x[0] < 0.0) {
      aSinInput = -1.0;
    } else if (x[0] > 0.0) {
      aSinInput = 1.0;
    } else if (x[0] == 0.0) {
      aSinInput = 0.0;
    }
    x[0] = aSinInput;
  }
  b_trueCount = 0;
  if (mask1 || mask2) {
    b_trueCount = 1;
  }
  r.set_size(b_trueCount);
  for (k = 0; k < b_trueCount; k++) {
    r[0] = rt_atan2d_snf(q[1], q[0]);
  }
  if (0 <= trueCount - 1) {
    eul[0] = -x[0] * 2.0 * r[0];
  }
  trueCount = 0;
  if (mask1 || mask2) {
    trueCount = 1;
  }
  if (0 <= trueCount - 1) {
    eul[2] = 0.0;
  }
}

} // namespace coder

//
// File trailer for quat2eul.cpp
//
// [EOF]
//
