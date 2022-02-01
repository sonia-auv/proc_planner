//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: TrajectoryGenerator.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 01-Feb-2022 18:48:34
//

#ifndef TRAJECTORYGENERATOR_H
#define TRAJECTORYGENERATOR_H

// Include Files
#include "Subscriber.h"
#include "proc_planner_internal_types.h"
#include "proc_planner_types.h"
#include "rtwtypes.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdlib>

// Type Definitions
class TrajectoryGenerator {
public:
  void matlabCodegenDestructor();
  ~TrajectoryGenerator();
  TrajectoryGenerator();
  bool matlabCodegenIsDeleted;
  double n;
  coder::array<double, 2U> pointList;
  coder::array<double, 2U> quatList;
  coder::array<double, 1U> timeList;
  double nbPoint;
  sonia_common_MultiAddPoseStruct_T MAPM;
  struct_T param;
  geometry_msgs_PoseStruct_T icMsg;
  coder::ros::e_Subscriber *icSub;
  coder::ros::e_Subscriber _pobj0;
};

#endif
//
// File trailer for TrajectoryGenerator.h
//
// [EOF]
//
