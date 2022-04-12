//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: TrajectoryGenerator.h
//
// MATLAB Coder version            : 5.4
// C/C++ source code generated on  : 12-Apr-2022 11:44:16
//

#ifndef TRAJECTORYGENERATOR_H
#define TRAJECTORYGENERATOR_H

// Include Files
#include "proc_planner_types.h"
#include "rtwtypes.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdlib>

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
};

class TrajectoryGenerator {
public:
  bool status;
  double n;
  coder::array<double, 2U> pointList;
  coder::array<double, 2U> quatList;
  coder::array<double, 1U> timeList;
  coder::array<double, 2U> courseList;
  coder::array<double, 2U> speedList;
  double nbPoint;

private:
  sonia_common_MultiAddPoseStruct_T MAPM;
  b_struct_T param;
};

#endif
//
// File trailer for TrajectoryGenerator.h
//
// [EOF]
//
