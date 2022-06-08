//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: sonia_common_AddPoseStruct.cpp
//
// MATLAB Coder version            : 5.4
// C/C++ source code generated on  : 07-Jun-2022 23:08:47
//

// Include Files
#include "sonia_common_AddPoseStruct.h"
#include "geometry_msgs_PointStruct.h"
#include "geometry_msgs_Vector3Struct.h"
#include "proc_planner_types.h"
#include "rt_nonfinite.h"

// Function Definitions
//
// Message struct definition for sonia_common/AddPose
//
// Arguments    : sonia_common_AddPoseStruct_T *msg
// Return Type  : void
//
void sonia_common_AddPoseStruct(sonia_common_AddPoseStruct_T *msg)
{
  static const char cv[20]{'s', 'o', 'n', 'i', 'a', '_', 'c', 'o', 'm', 'm',
                           'o', 'n', '/', 'A', 'd', 'd', 'P', 'o', 's', 'e'};
  for (int i{0}; i < 20; i++) {
    msg->MessageType[i] = cv[i];
  }
  msg->Position = geometry_msgs_PointStruct();
  msg->Orientation = geometry_msgs_Vector3Struct();
  msg->Frame = 0U;
  msg->Speed = 0U;
  msg->Fine = 0.0;
  msg->Rotation = false;
  //(msg);
}

//
// File trailer for sonia_common_AddPoseStruct.cpp
//
// [EOF]
//
