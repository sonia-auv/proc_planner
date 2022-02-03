//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: clothoidG2fitMissingCourse.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 02-Feb-2022 17:45:08
//

#ifndef CLOTHOIDG2FITMISSINGCOURSE_H
#define CLOTHOIDG2FITMISSINGCOURSE_H

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
void clothoidG2fitMissingCourse(const ::coder::array<double, 2U> &waypoints,
                                ::coder::array<double, 1U> &course);

void fitCourse_anonFcn3(const ::coder::array<double, 2U> &waypoints,
                        const ::coder::array<double, 1U> &course,
                        const ::coder::array<double, 1U> &x,
                        ::coder::array<double, 1U> &varargout_1,
                        ::coder::array<double, 2U> &varargout_2);

void fitCourse_anonFcn4(const ::coder::array<double, 2U> &waypoints,
                        const ::coder::array<double, 1U> &course,
                        const ::coder::array<double, 1U> &x,
                        ::coder::array<double, 1U> &varargout_1,
                        ::coder::array<double, 2U> &varargout_2);

} // namespace scenario
} // namespace internal
} // namespace tracking
} // namespace matlabshared
} // namespace coder

#endif
//
// File trailer for clothoidG2fitMissingCourse.h
//
// [EOF]
//
