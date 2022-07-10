//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: ros_DurationStruct.cpp
//
// MATLAB Coder version            : 5.4
// C/C++ source code generated on  : 10-Jul-2022 02:34:17
//

// Include Files
#include "ros_DurationStruct.h"
#include "proc_planner_types.h"
#include "rt_nonfinite.h"

// Function Definitions
//
// Message struct definition for ros/Duration
//
// Arguments    : void
// Return Type  : ros_DurationStruct_T
//
ros_DurationStruct_T ros_DurationStruct()
{
  ros_DurationStruct_T msg;
  msg.Sec = 0;
  msg.Nsec = 0;
  //(&msg);
  return msg;
}

//
// File trailer for ros_DurationStruct.cpp
//
// [EOF]
//
