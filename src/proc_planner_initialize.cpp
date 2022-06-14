//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: proc_planner_initialize.cpp
//
// MATLAB Coder version            : 5.4
// C/C++ source code generated on  : 13-Jun-2022 22:36:24
//

// Include Files
#include "proc_planner_initialize.h"
#include "CoderTimeAPI.h"
#include "proc_planner_data.h"
#include "ros_node.h"
#include "rt_nonfinite.h"

// Function Definitions
//
// Arguments    : void
// Return Type  : void
//
void proc_planner_initialize()
{
  freq_not_empty_init();
  ros_node::persistentDataStore_init();
  isInitialized_proc_planner = true;
}

//
// File trailer for proc_planner_initialize.cpp
//
// [EOF]
//
