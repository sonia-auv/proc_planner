//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: std_msgs_MultiArrayDimensionStruct.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 01-Feb-2022 18:48:34
//

// Include Files
#include "std_msgs_MultiArrayDimensionStruct.h"
#include "proc_planner_types.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <string.h>

// Function Definitions
//
// Message struct definition for std_msgs/MultiArrayDimension
//
// Arguments    : std_msgs_MultiArrayDimensionStruct_T *msg
// Return Type  : void
//
void std_msgs_MultiArrayDimensionStruct(
    std_msgs_MultiArrayDimensionStruct_T *msg)
{
  static const char b_cv[28]{'s', 't', 'd', '_', 'm', 's', 'g', 's', '/', 'M',
                             'u', 'l', 't', 'i', 'A', 'r', 'r', 'a', 'y', 'D',
                             'i', 'm', 'e', 'n', 's', 'i', 'o', 'n'};
  for (int i{0}; i < 28; i++) {
    msg->MessageType[i] = b_cv[i];
  }
  msg->Label.set_size(1, 0);
  msg->Size = 0U;
  msg->Stride = 0U;
  //(msg);
}

//
// File trailer for std_msgs_MultiArrayDimensionStruct.cpp
//
// [EOF]
//
