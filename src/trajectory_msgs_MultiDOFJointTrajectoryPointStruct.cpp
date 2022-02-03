//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: trajectory_msgs_MultiDOFJointTrajectoryPointStruct.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 02-Feb-2022 17:45:08
//

// Include Files
#include "trajectory_msgs_MultiDOFJointTrajectoryPointStruct.h"
#include "geometry_msgs_TransformStruct.h"
#include "geometry_msgs_TwistStruct.h"
#include "proc_planner_types.h"
#include "ros_DurationStruct.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <string.h>

// Function Definitions
//
// Message struct definition for trajectory_msgs/MultiDOFJointTrajectoryPoint
//
// Arguments    : trajectory_msgs_MultiDOFJointTrajectoryPointStruct_T *msg
// Return Type  : void
//
void trajectory_msgs_MultiDOFJointTrajectoryPointStruct(
    trajectory_msgs_MultiDOFJointTrajectoryPointStruct_T *msg)
{
  static const char cv[44]{
      't', 'r', 'a', 'j', 'e', 'c', 't', 'o', 'r', 'y', '_', 'm', 's', 'g', 's',
      '/', 'M', 'u', 'l', 't', 'i', 'D', 'O', 'F', 'J', 'o', 'i', 'n', 't', 'T',
      'r', 'a', 'j', 'e', 'c', 't', 'o', 'r', 'y', 'P', 'o', 'i', 'n', 't'};
  geometry_msgs_TransformStruct_T t2_Transforms;
  geometry_msgs_TwistStruct_T t2_Accelerations;
  geometry_msgs_TwistStruct_T t2_Velocities;
  geometry_msgs_TransformStruct(&t2_Transforms);
  geometry_msgs_TwistStruct(&t2_Velocities);
  geometry_msgs_TwistStruct(&t2_Accelerations);
  msg->TimeFromStart = ros_DurationStruct();
  for (int i{0}; i < 44; i++) {
    msg->MessageType[i] = cv[i];
  }
  msg->Transforms.set_size(1);
  msg->Transforms[0] = t2_Transforms;
  msg->Velocities.set_size(1);
  msg->Velocities[0] = t2_Velocities;
  msg->Accelerations.set_size(1);
  msg->Accelerations[0] = t2_Accelerations;
  msg->Transforms.set_size(0);
  msg->Velocities.set_size(0);
  msg->Accelerations.set_size(0);
  //(msg);
}

//
// File trailer for trajectory_msgs_MultiDOFJointTrajectoryPointStruct.cpp
//
// [EOF]
//
