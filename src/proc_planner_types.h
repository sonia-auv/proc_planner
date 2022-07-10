//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: proc_planner_types.h
//
// MATLAB Coder version            : 5.4
// C/C++ source code generated on  : 10-Jul-2022 02:34:17
//

#ifndef PROC_PLANNER_TYPES_H
#define PROC_PLANNER_TYPES_H

// Include Files
#include "rtwtypes.h"
#include "coder_array.h"

// Type Definitions
struct ros_TimeStruct_T {
  unsigned int Sec;
  unsigned int Nsec;
};

struct ros_DurationStruct_T {
  int Sec;
  int Nsec;
};

struct geometry_msgs_PointStruct_T {
  char MessageType[19];
  double X;
  double Y;
  double Z;
};

struct geometry_msgs_Vector3Struct_T {
  char MessageType[21];
  double X;
  double Y;
  double Z;
};

struct sonia_common_AddPoseStruct_T {
  char MessageType[20];
  geometry_msgs_PointStruct_T Position;
  geometry_msgs_Vector3Struct_T Orientation;
  unsigned char Frame;
  unsigned char Speed;
  double Fine;
  bool Rotation;
};

struct geometry_msgs_QuaternionStruct_T {
  char MessageType[24];
  double X;
  double Y;
  double Z;
  double W;
};

struct geometry_msgs_PoseStruct_T {
  char MessageType[18];
  geometry_msgs_PointStruct_T Position;
  geometry_msgs_QuaternionStruct_T Orientation;
};

struct std_msgs_Int8Struct_T {
  char MessageType[13];
  signed char Data;
};

struct geometry_msgs_TransformStruct_T {
  char MessageType[23];
  geometry_msgs_Vector3Struct_T Translation;
  geometry_msgs_QuaternionStruct_T Rotation;
};

struct geometry_msgs_TwistStruct_T {
  char MessageType[19];
  geometry_msgs_Vector3Struct_T Linear;
  geometry_msgs_Vector3Struct_T Angular;
};

struct sonia_common_ObstacleInfoStruct_T {
  char MessageType[25];
  coder::array<char, 2U> Name;
  bool IsValid;
  float Confidence;
  geometry_msgs_PoseStruct_T Pose;
};

struct sonia_common_MultiAddPoseStruct_T {
  char MessageType[25];
  unsigned char InterpolationMethod;
  coder::array<sonia_common_AddPoseStruct_T, 1U> Pose;
};

struct std_msgs_HeaderStruct_T {
  char MessageType[15];
  unsigned int Seq;
  ros_TimeStruct_T Stamp;
  coder::array<char, 2U> FrameId;
};

struct sonia_common_ObstacleArrayStruct_T {
  char MessageType[26];
  std_msgs_HeaderStruct_T Header;
  coder::array<sonia_common_ObstacleInfoStruct_T, 1U> Obstacles;
};

struct trajectory_msgs_MultiDOFJointTrajectoryPointStruct_T {
  char MessageType[44];
  coder::array<geometry_msgs_TransformStruct_T, 1U> Transforms;
  coder::array<geometry_msgs_TwistStruct_T, 1U> Velocities;
  coder::array<geometry_msgs_TwistStruct_T, 1U> Accelerations;
  ros_DurationStruct_T TimeFromStart;
};

#endif
//
// File trailer for proc_planner_types.h
//
// [EOF]
//
