//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: TrajectoryGenerator.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 03-Feb-2022 14:08:22
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
  double ts;
  double amax;
  double vlmax;
  double vamax;
};

class TrajectoryGenerator {
public:
  bool status;
  coder::array<double, 2U> pointList;
  coder::array<double, 2U> quatList;
  coder::array<double, 1U> timeList;
  double nbPoint;

private:
  double n;
  sonia_common_MultiAddPoseStruct_T MAPM;
  struct_T param;
};

#endif
//
// File trailer for TrajectoryGenerator.h
//
// [EOF]
//
