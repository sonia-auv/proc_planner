//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: geometry_msgs_PoseStruct.cpp
//
// MATLAB Coder version            : 5.4
// C/C++ source code generated on  : 12-Apr-2022 11:44:16
//

// Include Files
#include "geometry_msgs_PoseStruct.h"
#include "geometry_msgs_PointStruct.h"
#include "geometry_msgs_QuaternionStruct.h"
#include "proc_planner_types.h"
#include "rt_nonfinite.h"
#include <string.h>

// Function Definitions
//
// Message struct definition for geometry_msgs/Pose
//
// Arguments    : geometry_msgs_PoseStruct_T *msg
// Return Type  : void
//
void geometry_msgs_PoseStruct(geometry_msgs_PoseStruct_T *msg)
{
  static const char cv[18]{'g', 'e', 'o', 'm', 'e', 't', 'r', 'y', '_',
                           'm', 's', 'g', 's', '/', 'P', 'o', 's', 'e'};
  for (int i{0}; i < 18; i++) {
    msg->MessageType[i] = cv[i];
  }
  msg->Position = geometry_msgs_PointStruct();
  msg->Orientation = geometry_msgs_QuaternionStruct();
  //(msg);
}

//
// File trailer for geometry_msgs_PoseStruct.cpp
//
// [EOF]
//
