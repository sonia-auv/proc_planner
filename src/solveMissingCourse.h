//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: solveMissingCourse.h
//
// MATLAB Coder version            : 5.4
// C/C++ source code generated on  : 12-Apr-2022 11:44:16
//

#ifndef SOLVEMISSINGCOURSE_H
#define SOLVEMISSINGCOURSE_H

// Include Files
#include "rtwtypes.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdlib>

// Type Declarations
namespace coder {
class waypointTrajectory;

}

// Function Declarations
void b_binary_expand_op(coder::array<bool, 1U> &in1,
                        const coder::waypointTrajectory *in2, int in3, int in4,
                        int in5, int in6, int in7, int in8);

namespace coder {
namespace matlabshared {
namespace tracking {
namespace internal {
namespace scenario {
void clothoidG2FitMissingCourse(const ::coder::array<double, 2U> &waypoints,
                                ::coder::array<double, 1U> &course);

}
} // namespace internal
} // namespace tracking
} // namespace matlabshared
} // namespace coder

#endif
//
// File trailer for solveMissingCourse.h
//
// [EOF]
//
