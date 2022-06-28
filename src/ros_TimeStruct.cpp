//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: ros_TimeStruct.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 01-Feb-2022 18:48:34
//

// Include Files
#include "ros_TimeStruct.h"
#include "proc_planner_types.h"
#include "rt_nonfinite.h"
#include <string.h>

// Function Definitions
//
// Message struct definition for ros/Time
//
// Arguments    : void
// Return Type  : ros_TimeStruct_T
//
ros_TimeStruct_T ros_TimeStruct()
{
  ros_TimeStruct_T msg;
  msg.Sec = 0U;
  msg.Nsec = 0U;
  //(&msg);
  return msg;
}

//
// File trailer for ros_TimeStruct.cpp
//
// [EOF]
//
