//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: sonia_common_MultiAddPoseStruct.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 09-Feb-2022 14:06:20
//

// Include Files
#include "sonia_common_MultiAddPoseStruct.h"
#include "proc_planner_types.h"
#include "rt_nonfinite.h"
#include "sonia_common_AddPoseStruct.h"
#include "coder_array.h"
#include <string.h>

// Function Definitions
//
// Message struct definition for sonia_common/MultiAddPose
//
// Arguments    : sonia_common_MultiAddPoseStruct_T *msg
// Return Type  : void
//
void sonia_common_MultiAddPoseStruct(sonia_common_MultiAddPoseStruct_T *msg)
{
  static const char b_cv[25]{'s', 'o', 'n', 'i', 'a', '_', 'c', 'o', 'm',
                             'm', 'o', 'n', '/', 'M', 'u', 'l', 't', 'i',
                             'A', 'd', 'd', 'P', 'o', 's', 'e'};
  sonia_common_AddPoseStruct_T t2_Pose;
  sonia_common_AddPoseStruct(&t2_Pose);
  for (int i{0}; i < 25; i++) {
    msg->MessageType[i] = b_cv[i];
  }
  msg->Pose.set_size(1);
  msg->Pose[0] = t2_Pose;
  msg->Pose.set_size(0);
  //(msg);
}

//
// File trailer for sonia_common_MultiAddPoseStruct.cpp
//
// [EOF]
//
