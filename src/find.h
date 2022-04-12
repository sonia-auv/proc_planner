//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: find.h
//
// MATLAB Coder version            : 5.4
// C/C++ source code generated on  : 12-Apr-2022 11:44:16
//

#ifndef FIND_H
#define FIND_H

// Include Files
#include "rtwtypes.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
void binary_expand_op(coder::array<int, 1U> &in1,
                      const coder::array<double, 1U> &in2,
                      const coder::array<double, 1U> &in3);

void c_binary_expand_op(coder::array<int, 1U> &in1,
                        const coder::array<bool, 1U> &in2,
                        const coder::array<bool, 1U> &in3);

namespace coder {
void b_eml_find(const ::coder::array<bool, 2U> &x, ::coder::array<int, 1U> &i);

void eml_find(const ::coder::array<bool, 1U> &x, ::coder::array<int, 1U> &i);

} // namespace coder
void d_binary_expand_op(coder::array<int, 1U> &in1,
                        const coder::array<bool, 1U> &in2,
                        const coder::array<bool, 1U> &in3);

#endif
//
// File trailer for find.h
//
// [EOF]
//
