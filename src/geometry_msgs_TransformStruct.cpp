//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// geometry_msgs_TransformStruct.cpp
//
// Code generation for function 'geometry_msgs_TransformStruct'
//

// Include files
#include "geometry_msgs_TransformStruct.h"
#include "geometry_msgs_QuaternionStruct.h"
#include "geometry_msgs_Vector3Struct.h"
#include "proc_planner_types.h"
#include "rt_nonfinite.h"

// Function Definitions
void geometry_msgs_TransformStruct(geometry_msgs_TransformStruct_T *msg)
{
  static const char b_cv[23]{'g', 'e', 'o', 'm', 'e', 't', 'r', 'y',
                             '_', 'm', 's', 'g', 's', '/', 'T', 'r',
                             'a', 'n', 's', 'f', 'o', 'r', 'm'};
  //  Message struct definition for geometry_msgs/Transform
  for (int i{0}; i < 23; i++) {
    msg->MessageType[i] = b_cv[i];
  }
  msg->Translation = geometry_msgs_Vector3Struct();
  msg->Rotation = geometry_msgs_QuaternionStruct();
  //(msg);
}

// End of code generation (geometry_msgs_TransformStruct.cpp)
