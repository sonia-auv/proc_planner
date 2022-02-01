//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: std_msgs_Float64MultiArrayStruct.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 01-Feb-2022 18:48:34
//

// Include Files
#include "std_msgs_Float64MultiArrayStruct.h"
#include "proc_planner_types.h"
#include "rt_nonfinite.h"
#include "std_msgs_MultiArrayLayoutStruct.h"
#include "coder_array.h"
#include <string.h>

// Function Definitions
//
// Message struct definition for std_msgs/Float64MultiArray
//
// Arguments    : std_msgs_Float64MultiArrayStruct_T *msg
// Return Type  : void
//
void std_msgs_Float64MultiArrayStruct(std_msgs_Float64MultiArrayStruct_T *msg)
{
  static const char b_cv[26]{'s', 't', 'd', '_', 'm', 's', 'g', 's', '/',
                             'F', 'l', 'o', 'a', 't', '6', '4', 'M', 'u',
                             'l', 't', 'i', 'A', 'r', 'r', 'a', 'y'};
  std_msgs_MultiArrayLayoutStruct(&msg->Layout);
  for (int i{0}; i < 26; i++) {
    msg->MessageType[i] = b_cv[i];
  }
  msg->Data.set_size(0);
  //(msg);
}

//
// File trailer for std_msgs_Float64MultiArrayStruct.cpp
//
// [EOF]
//
