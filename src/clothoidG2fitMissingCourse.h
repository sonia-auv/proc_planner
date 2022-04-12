//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: clothoidG2fitMissingCourse.h
//
// MATLAB Coder version            : 5.4
// C/C++ source code generated on  : 12-Apr-2022 11:44:16
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
void fillPartitions(const ::coder::array<double, 2U> &waypoints,
                    ::coder::array<double, 1U> &course,
                    const ::coder::array<double, 1U> &ibegin,
                    const ::coder::array<double, 1U> &iend);

void fitCourse(const ::coder::array<double, 2U> &waypoints,
               ::coder::array<double, 1U> &course);

void fitCourse_anonFcn3(const ::coder::array<double, 2U> &waypoints,
                        const ::coder::array<double, 1U> &course,
                        const ::coder::array<double, 1U> &x,
                        ::coder::array<double, 1U> &varargout_1,
                        ::coder::array<double, 2U> &varargout_2);

void fitLoopCourse_anonFcn1(const ::coder::array<double, 2U> &waypoints,
                            const ::coder::array<double, 1U> &x,
                            ::coder::array<double, 1U> &varargout_1,
                            ::coder::array<double, 2U> &varargout_2);

void partitionCourse(const ::coder::array<double, 1U> &course,
                     ::coder::array<double, 1U> &ibegin,
                     ::coder::array<double, 1U> &iend);

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
