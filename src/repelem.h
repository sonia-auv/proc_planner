//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: repelem.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 03-Feb-2022 14:08:22
//

#ifndef REPELEM_H
#define REPELEM_H

// Include Files
#include "rtwtypes.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdlib>

// Type Declarations
struct geometry_msgs_TransformStruct_T;

struct geometry_msgs_TwistStruct_T;

// Function Declarations
namespace coder {
void repelem(const geometry_msgs_TransformStruct_T *x, double varargin_1,
             ::coder::array<geometry_msgs_TransformStruct_T, 2U> &y);

void repelem(const geometry_msgs_TwistStruct_T *x, double varargin_1,
             ::coder::array<geometry_msgs_TwistStruct_T, 2U> &y);

} // namespace coder

#endif
//
// File trailer for repelem.h
//
// [EOF]
//
