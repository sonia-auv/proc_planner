//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: repelem.cpp
//
// MATLAB Coder version            : 5.4
// C/C++ source code generated on  : 07-Jun-2022 23:08:47
//

// Include Files
#include "repelem.h"
#include "proc_planner_types.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Definitions
//
// Arguments    : const geometry_msgs_TwistStruct_T *x
//                double varargin_1
//                ::coder::array<geometry_msgs_TwistStruct_T, 2U> &y
// Return Type  : void
//
namespace coder {
void repelem(const geometry_msgs_TwistStruct_T *x, double varargin_1,
             ::coder::array<geometry_msgs_TwistStruct_T, 2U> &y)
{
  int i;
  i = static_cast<int>(varargin_1);
  y.set_size(1, i);
  for (int j{0}; j < i; j++) {
    y[j] = *x;
  }
}

} // namespace coder

//
// File trailer for repelem.cpp
//
// [EOF]
//
