//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: std_msgs_MultiArrayLayoutStruct.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 01-Feb-2022 18:48:34
//

// Include Files
#include "std_msgs_MultiArrayLayoutStruct.h"
#include "proc_planner_types.h"
#include "rt_nonfinite.h"
#include "std_msgs_MultiArrayDimensionStruct.h"
#include "coder_array.h"
#include <string.h>

// Function Definitions
//
// Message struct definition for std_msgs/MultiArrayLayout
//
// Arguments    : std_msgs_MultiArrayLayoutStruct_T *msg
// Return Type  : void
//
void std_msgs_MultiArrayLayoutStruct(std_msgs_MultiArrayLayoutStruct_T *msg)
{
  static const char b_cv[25]{'s', 't', 'd', '_', 'm', 's', 'g', 's', '/',
                             'M', 'u', 'l', 't', 'i', 'A', 'r', 'r', 'a',
                             'y', 'L', 'a', 'y', 'o', 'u', 't'};
  std_msgs_MultiArrayDimensionStruct_T t1_Dim;
  std_msgs_MultiArrayDimensionStruct(&t1_Dim);
  for (int i{0}; i < 25; i++) {
    msg->MessageType[i] = b_cv[i];
  }
  msg->Dim.set_size(1);
  msg->Dim[0] = t1_Dim;
  msg->DataOffset = 0U;
  msg->Dim.set_size(0);
  //(msg);
}

//
// File trailer for std_msgs_MultiArrayLayoutStruct.cpp
//
// [EOF]
//
