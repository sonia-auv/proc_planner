//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: eml_mtimes_helper.h
//
// MATLAB Coder version            : 5.4
// C/C++ source code generated on  : 12-Apr-2022 11:44:16
//

#ifndef EML_MTIMES_HELPER_H
#define EML_MTIMES_HELPER_H

// Include Files
#include "rtwtypes.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
void binary_expand_op(coder::array<double, 1U> &in1,
                      const coder::array<double, 1U> &in2,
                      const coder::array<double, 1U> &in3, double in4);

void binary_expand_op(coder::array<creal_T, 1U> &in1,
                      const coder::array<double, 1U> &in3,
                      const coder::array<double, 1U> &in4);

void binary_expand_op(coder::array<creal_T, 1U> &in1,
                      const coder::array<double, 1U> &in3,
                      const coder::array<double, 1U> &in4,
                      const coder::array<double, 1U> &in5);

void binary_expand_op(coder::array<creal_T, 1U> &in1,
                      const coder::array<creal_T, 1U> &in2,
                      const coder::array<double, 1U> &in3);

#endif
//
// File trailer for eml_mtimes_helper.h
//
// [EOF]
//
