//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: quaternionC2fit.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 05-Feb-2022 14:39:35
//

#ifndef QUATERNIONC2FIT_H
#define QUATERNIONC2FIT_H

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
namespace coder {
namespace fusion {
namespace scenario {
namespace internal {
void getang(const quaternion *qi, const quaternion *qf,
            ::coder::array<double, 1U> &dtheta, ::coder::array<double, 2U> &e);

void rates(double n, const ::coder::array<double, 1U> &h,
           const ::coder::array<double, 1U> &dtheta,
           const ::coder::array<double, 2U> &e, ::coder::array<double, 2U> &w);

} // namespace internal
} // namespace scenario
} // namespace fusion
} // namespace coder

#endif
//
// File trailer for quaternionC2fit.h
//
// [EOF]
//
