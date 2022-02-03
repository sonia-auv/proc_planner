//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: quaternion.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 03-Feb-2022 14:08:22
//

#ifndef QUATERNION_H
#define QUATERNION_H

// Include Files
#include "rtwtypes.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdlib>

// Type Definitions
namespace coder {
class quaternion {
public:
  void init(const ::coder::array<double, 2U> &varargin_1);
  void rotmat(::coder::array<double, 3U> &r);
  void init();
  array<double, 2U> a;
  array<double, 2U> b;
  array<double, 2U> c;
  array<double, 2U> d;
};

class b_quaternion {
public:
  double a;
  double b;
  double c;
  double d;
};

} // namespace coder

#endif
//
// File trailer for quaternion.h
//
// [EOF]
//
