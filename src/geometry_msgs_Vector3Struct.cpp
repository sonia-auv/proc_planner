//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: geometry_msgs_Vector3Struct.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 05-Feb-2022 14:39:35
//

// Include Files
#include "geometry_msgs_Vector3Struct.h"
#include "proc_planner_types.h"
#include "rt_nonfinite.h"
#include <string.h>

// Function Definitions
//
// Message struct definition for geometry_msgs/Vector3
//
// Arguments    : void
// Return Type  : geometry_msgs_Vector3Struct_T
//
geometry_msgs_Vector3Struct_T geometry_msgs_Vector3Struct()
{
  static const geometry_msgs_Vector3Struct_T b_msg{
      {'g', 'e', 'o', 'm', 'e', 't', 'r', 'y', '_', 'm', 's',
       'g', 's', '/', 'V', 'e', 'c', 't', 'o', 'r', '3'}, // MessageType
      0.0,                                                // X
      0.0,                                                // Y
      0.0                                                 // Z
  };
  geometry_msgs_Vector3Struct_T msg;
  msg = b_msg;
  //(&b_msg);
  return msg;
}

//
// File trailer for geometry_msgs_Vector3Struct.cpp
//
// [EOF]
//
