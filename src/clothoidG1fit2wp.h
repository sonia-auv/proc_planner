//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: clothoidG1fit2wp.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 02-Feb-2022 17:45:08
//

#ifndef CLOTHOIDG1FIT2WP_H
#define CLOTHOIDG1FIT2WP_H

// Include Files
#include "rtwtypes.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace coder {
namespace matlabshared {
namespace tracking {
namespace internal {
namespace scenario {
void clothoidG1fit2wp(const ::coder::array<creal_T, 1U> &z0,
                      const ::coder::array<double, 1U> &theta0,
                      const ::coder::array<creal_T, 1U> &z1,
                      const ::coder::array<double, 1U> &theta1,
                      ::coder::array<double, 1U> &k0,
                      ::coder::array<double, 1U> &k1,
                      ::coder::array<double, 1U> &l,
                      ::coder::array<double, 1U> &dk0_dtheta0,
                      ::coder::array<double, 1U> &dk0_dtheta1,
                      ::coder::array<double, 1U> &dk1_dtheta0,
                      ::coder::array<double, 1U> &dk1_dtheta1);

void clothoidG1fit2wp(const ::coder::array<creal_T, 1U> &z0,
                      const ::coder::array<double, 1U> &theta0,
                      const ::coder::array<creal_T, 1U> &z1,
                      const ::coder::array<double, 1U> &theta1,
                      ::coder::array<double, 1U> &k0,
                      ::coder::array<double, 1U> &k1,
                      ::coder::array<double, 1U> &l);

} // namespace scenario
} // namespace internal
} // namespace tracking
} // namespace matlabshared
} // namespace coder

#endif
//
// File trailer for clothoidG1fit2wp.h
//
// [EOF]
//
