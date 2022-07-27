//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// proc_planner_initialize.cpp
//
// Code generation for function 'proc_planner_initialize'
//

// Include files
#include "proc_planner_initialize.h"
#include "CoderTimeAPI.h"
#include "proc_planner_data.h"
#include "ros_node.h"
#include "rt_nonfinite.h"

// Function Definitions
void proc_planner_initialize()
{
  freq_not_empty_init();
  ros_node::persistentDataStore_init();
  isInitialized_proc_planner = true;
}

// End of code generation (proc_planner_initialize.cpp)
