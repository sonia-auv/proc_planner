//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: div.h
//
// MATLAB Coder version            : 5.4
// C/C++ source code generated on  : 12-Apr-2022 11:44:16
//

#ifndef DIV_H
#define DIV_H

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
void binary_expand_op(coder::quaternion *in1,
                      const coder::array<double, 2U> &in2);

void binary_expand_op(coder::quaternion *in1, const coder::quaternion *in2,
                      const coder::array<double, 2U> &in3);

void binary_expand_op(coder::quaternion *in1,
                      const coder::array<double, 2U> &in2,
                      const coder::array<double, 2U> &in3);

void binary_expand_op(coder::array<double, 2U> &in1,
                      const coder::array<double, 2U> &in2,
                      const coder::array<double, 2U> &in3,
                      const coder::array<double, 2U> &in4,
                      const coder::array<double, 2U> &in5);

void binary_expand_op(coder::array<double, 1U> &in1,
                      const coder::array<double, 1U> &in2,
                      const coder::array<double, 1U> &in3);

void binary_expand_op(coder::array<double, 1U> &in1,
                      const coder::array<creal_T, 1U> &in2);

void binary_expand_op(coder::array<creal_T, 1U> &in1,
                      const coder::array<creal_T, 1U> &in2, int in3);

void binary_expand_op(coder::array<creal_T, 1U> &in1,
                      const coder::array<creal_T, 1U> &in2,
                      const coder::array<creal_T, 1U> &in4, int in5);

void binary_expand_op(coder::array<creal_T, 1U> &in1,
                      const coder::array<double, 1U> &in2,
                      const coder::array<creal_T, 1U> &in3,
                      const coder::array<double, 1U> &in6);

void binary_expand_op(coder::array<creal_T, 1U> &in1,
                      const coder::array<creal_T, 1U> &in3,
                      const coder::array<creal_T, 1U> &in4);

void binary_expand_op(coder::array<creal_T, 1U> &in1,
                      const coder::array<double, 1U> &in2);

void binary_expand_op(coder::array<double, 1U> &in1,
                      const coder::array<double, 1U> &in2);

void e_binary_expand_op(coder::quaternion *in1,
                        const coder::array<double, 2U> &in2);

void e_binary_expand_op(coder::array<creal_T, 1U> &in1,
                        const coder::array<double, 1U> &in3,
                        const coder::array<double, 1U> &in4,
                        const coder::array<double, 1U> &in5);

void e_binary_expand_op(coder::quaternion *in1,
                        const coder::array<double, 2U> &in2,
                        const coder::array<double, 2U> &in3);

void e_binary_expand_op(coder::quaternion *in1, const coder::quaternion *in2,
                        const coder::array<double, 2U> &in3);

void f_binary_expand_op(coder::quaternion *in1,
                        const coder::array<double, 2U> &in2,
                        const coder::array<double, 2U> &in3);

void f_binary_expand_op(coder::quaternion *in1,
                        const coder::array<double, 2U> &in2);

void f_binary_expand_op(coder::quaternion *in1, const coder::quaternion *in2,
                        const coder::array<double, 2U> &in3);

void g_binary_expand_op(coder::quaternion *in1,
                        const coder::array<double, 2U> &in2,
                        const coder::array<double, 2U> &in3);

void g_binary_expand_op(coder::quaternion *in1,
                        const coder::array<double, 2U> &in2);

void g_binary_expand_op(coder::quaternion *in1, const coder::quaternion *in2,
                        const coder::array<double, 2U> &in3);

void rdivide(coder::array<double, 1U> &in1,
             const coder::array<double, 1U> &in2);

void rdivide(coder::array<creal_T, 1U> &in1,
             const coder::array<creal_T, 1U> &in2);

#endif
//
// File trailer for div.h
//
// [EOF]
//
