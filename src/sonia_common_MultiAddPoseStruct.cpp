//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// sonia_common_MultiAddPoseStruct.cpp
//
// Code generation for function 'sonia_common_MultiAddPoseStruct'
//

// Include files
#include "sonia_common_MultiAddPoseStruct.h"
#include "proc_planner_types.h"
#include "rt_nonfinite.h"
#include "sonia_common_AddPoseStruct.h"
#include "coder_array.h"

// Function Definitions
void sonia_common_MultiAddPoseStruct(sonia_common_MultiAddPoseStruct_T *msg)
{
  static const char b_cv[25]{'s', 'o', 'n', 'i', 'a', '_', 'c', 'o', 'm',
                             'm', 'o', 'n', '/', 'M', 'u', 'l', 't', 'i',
                             'A', 'd', 'd', 'P', 'o', 's', 'e'};
  sonia_common_AddPoseStruct_T t1_Pose;
  //  Message struct definition for sonia_common/MultiAddPose
  sonia_common_AddPoseStruct(&t1_Pose);
  for (int i{0}; i < 25; i++) {
    msg->MessageType[i] = b_cv[i];
  }
  msg->InterpolationMethod = 0U;
  msg->Pose.set_size(1);
  msg->Pose[0] = t1_Pose;
  msg->Pose.set_size(0);
  //(msg);
}

// End of code generation (sonia_common_MultiAddPoseStruct.cpp)
