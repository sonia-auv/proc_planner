//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: geometry_msgs_TransformStruct.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 08-Feb-2022 23:30:50
//

// Include Files
#include "geometry_msgs_TransformStruct.h"
#include "geometry_msgs_QuaternionStruct.h"
#include "geometry_msgs_Vector3Struct.h"
#include "proc_planner_types.h"
#include "rt_nonfinite.h"
#include <string.h>

// Function Definitions
//
// Message struct definition for geometry_msgs/Transform
//
// Arguments    : geometry_msgs_TransformStruct_T *msg
// Return Type  : void
//
void geometry_msgs_TransformStruct(geometry_msgs_TransformStruct_T *msg)
{
  static const char b_cv[23]{'g', 'e', 'o', 'm', 'e', 't', 'r', 'y',
                             '_', 'm', 's', 'g', 's', '/', 'T', 'r',
                             'a', 'n', 's', 'f', 'o', 'r', 'm'};
  for (int i{0}; i < 23; i++) {
    msg->MessageType[i] = b_cv[i];
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
