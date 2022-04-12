//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: quaternionBase.h
//
// MATLAB Coder version            : 5.4
// C/C++ source code generated on  : 12-Apr-2022 11:44:16
//

#ifndef QUATERNIONBASE_H
#define QUATERNIONBASE_H

// Include Files
#include "rtwtypes.h"
#include <cstddef>
#include <cstdlib>

// Type Declarations
namespace coder {
class quaternion;

class b_quaternion;

} // namespace coder

// Function Declarations
void binary_expand_op(coder::quaternion *in1, const coder::quaternion *in2,
                      const coder::b_quaternion in3);

void e_binary_expand_op(coder::quaternion *in1, const coder::quaternion *in2,
                        const coder::b_quaternion in3);

void f_binary_expand_op(coder::quaternion *in1, const coder::quaternion *in2,
                        const coder::b_quaternion in3);

void g_binary_expand_op(coder::quaternion *in1, const coder::quaternion *in2,
                        const coder::b_quaternion in3);

#endif
//
// File trailer for quaternionBase.h
//
// [EOF]
//
