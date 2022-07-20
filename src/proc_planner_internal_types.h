//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// proc_planner_internal_types.h
//
// Code generation for function 'proc_planner'
//

#ifndef PROC_PLANNER_INTERNAL_TYPES_H
#define PROC_PLANNER_INTERNAL_TYPES_H

// Include files
#include "proc_planner_types.h"
#include "rtwtypes.h"

// Type Definitions
struct struct_T {
  double amax;
  double vlmax;
  double vamax;
};

struct b_struct_T {
  double ts;
  struct_T lowSpeed;
  struct_T normalSpeed;
  struct_T highSpeed;
  double maxDepth;
  double surfaceWarning;
};

#endif
// End of code generation (proc_planner_internal_types.h)
