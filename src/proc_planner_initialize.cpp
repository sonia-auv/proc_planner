//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: proc_planner_initialize.cpp
//
// MATLAB Coder version            : 5.4
// C/C++ source code generated on  : 12-Apr-2022 11:44:16
//

// Include Files
#include "proc_planner_initialize.h"
#include "CoderTimeAPI.h"
#include "proc_planner_data.h"
#include "rt_nonfinite.h"
#include <string.h>

// Function Definitions
//
// Arguments    : void
// Return Type  : void
//
void proc_planner_initialize()
{
  freq_not_empty_init();
  newInitalPose = false;
  newMadpPose = false;
  isInitialized_proc_planner = true;
}

//
// File trailer for proc_planner_initialize.cpp
//
// [EOF]
//
