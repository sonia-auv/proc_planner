//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: proc_planner_internal_types.h
//
// MATLAB Coder version            : 5.4
// C/C++ source code generated on  : 09-Jul-2022 16:26:05
//

#ifndef PROC_PLANNER_INTERNAL_TYPES_H
#define PROC_PLANNER_INTERNAL_TYPES_H

// Include Files
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
//
// File trailer for proc_planner_internal_types.h
//
// [EOF]
//
