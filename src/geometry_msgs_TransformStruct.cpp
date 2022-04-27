//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: geometry_msgs_TransformStruct.cpp
//
// MATLAB Coder version            : 5.4
// C/C++ source code generated on  : 26-Apr-2022 22:23:20
//

// Include Files
#include "geometry_msgs_TransformStruct.h"
#include "geometry_msgs_QuaternionStruct.h"
#include "geometry_msgs_Vector3Struct.h"
#include "proc_planner_types.h"
#include "rt_nonfinite.h"

// Function Definitions
//
// Message struct definition for geometry_msgs/Transform
//
// Arguments    : geometry_msgs_TransformStruct_T *msg
// Return Type  : void
//
void geometry_msgs_TransformStruct(geometry_msgs_TransformStruct_T *msg)
{
  static const char cv[23]{'g', 'e', 'o', 'm', 'e', 't', 'r', 'y',
                           '_', 'm', 's', 'g', 's', '/', 'T', 'r',
                           'a', 'n', 's', 'f', 'o', 'r', 'm'};
  for (int i{0}; i < 23; i++) {
    msg->MessageType[i] = cv[i];
  }
  msg->Translation = geometry_msgs_Vector3Struct();
  msg->Rotation = geometry_msgs_QuaternionStruct();
  //(msg);
}

//
// File trailer for geometry_msgs_TransformStruct.cpp
//
// [EOF]
//
