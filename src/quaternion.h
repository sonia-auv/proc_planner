//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: quaternion.h
//
// MATLAB Coder version            : 5.4
// C/C++ source code generated on  : 12-Apr-2022 11:44:16
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

// Function Declarations
void binary_expand_op(coder::array<double, 2U> &in1,
                      const coder::quaternion *in2,
                      const coder::quaternion *in3,
                      const coder::array<double, 2U> &in4,
                      const coder::quaternion *in5,
                      const coder::array<double, 2U> &in6);

void binary_expand_op(coder::array<double, 2U> &in1,
                      const coder::quaternion *in2,
                      const coder::quaternion *in3,
                      const coder::quaternion *in4,
                      const coder::array<double, 2U> &in5);

void e_binary_expand_op(coder::array<double, 2U> &in1,
                        const coder::quaternion *in2,
                        const coder::quaternion *in3,
                        const coder::array<double, 2U> &in4,
                        const coder::quaternion *in5,
                        const coder::array<double, 2U> &in6);

void f_binary_expand_op(coder::array<double, 2U> &in1,
                        const coder::quaternion *in2,
                        const coder::quaternion *in3,
                        const coder::array<double, 2U> &in4,
                        const coder::quaternion *in5,
                        const coder::array<double, 2U> &in6);

#endif
//
// File trailer for quaternion.h
//
// [EOF]
//
