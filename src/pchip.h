//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: pchip.h
//
// MATLAB Coder version            : 5.4
// C/C++ source code generated on  : 12-Apr-2022 11:44:16
//

#ifndef PCHIP_H
#define PCHIP_H

// Include Files
#include "rtwtypes.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace coder {
void pchip(const ::coder::array<double, 1U> &x,
           const ::coder::array<double, 1U> &y,
           ::coder::array<double, 2U> &v_breaks,
           ::coder::array<double, 2U> &v_coefs);

}

#endif
//
// File trailer for pchip.h
//
// [EOF]
//
