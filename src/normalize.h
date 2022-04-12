//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: normalize.h
//
// MATLAB Coder version            : 5.4
// C/C++ source code generated on  : 12-Apr-2022 11:44:16
//

#ifndef NORMALIZE_H
#define NORMALIZE_H

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
void binary_expand_op(coder::array<double, 2U> &in1,
                      const coder::quaternion *in2);

void e_binary_expand_op(coder::array<double, 2U> &in1,
                        const coder::array<double, 2U> &in2,
                        const coder::array<double, 2U> &in3,
                        const coder::array<double, 2U> &in4,
                        const coder::array<double, 2U> &in5);

#endif
//
// File trailer for normalize.h
//
// [EOF]
//
