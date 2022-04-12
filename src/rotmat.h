//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: rotmat.h
//
// MATLAB Coder version            : 5.4
// C/C++ source code generated on  : 12-Apr-2022 11:44:16
//

#ifndef ROTMAT_H
#define ROTMAT_H

// Include Files
#include "rtwtypes.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdlib>

// Type Declarations
namespace coder {
class quaternion;

}

// Function Declarations
void binary_expand_op(coder::array<double, 1U> &in1,
                      const coder::quaternion *in2);

void e_binary_expand_op(coder::array<double, 1U> &in1,
                        const coder::quaternion *in2);

void f_binary_expand_op(coder::array<double, 1U> &in1,
                        const coder::quaternion *in2);

void g_binary_expand_op(coder::array<double, 1U> &in1,
                        const coder::quaternion *in2);

void h_binary_expand_op(coder::array<double, 1U> &in1,
                        const coder::quaternion *in2);

void i_binary_expand_op(coder::array<double, 1U> &in1,
                        const coder::quaternion *in2);

#endif
//
// File trailer for rotmat.h
//
// [EOF]
//
