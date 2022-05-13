//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: trajectory_msgs_MultiDOFJointTrajectoryPointStruct.cpp
//
// MATLAB Coder version            : 5.4
// C/C++ source code generated on  : 12-May-2022 22:37:14
//

// Include Files
#include "trajectory_msgs_MultiDOFJointTrajectoryPointStruct.h"
#include "geometry_msgs_TransformStruct.h"
#include "geometry_msgs_TwistStruct.h"
#include "proc_planner_types.h"
#include "ros_DurationStruct.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

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
  geometry_msgs_TransformStruct_T t0_Transforms;
  geometry_msgs_TwistStruct_T t0_Accelerations;
  geometry_msgs_TwistStruct_T t0_Velocities;
  geometry_msgs_TransformStruct(&t0_Transforms);
  geometry_msgs_TwistStruct(&t0_Velocities);
  geometry_msgs_TwistStruct(&t0_Accelerations);
  msg->TimeFromStart = ros_DurationStruct();
  for (int i{0}; i < 44; i++) {
    msg->MessageType[i] = cv[i];
  }
  msg->Transforms.set_size(1);
  msg->Transforms[0] = t0_Transforms;
  msg->Velocities.set_size(1);
  msg->Velocities[0] = t0_Velocities;
  msg->Accelerations.set_size(1);
  msg->Accelerations[0] = t0_Accelerations;
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
