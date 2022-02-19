//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: TrajectoryGenerator.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 19-Feb-2022 14:46:56
//

#ifndef TRAJECTORYGENERATOR_H
#define TRAJECTORYGENERATOR_H

// Include Files
#include "proc_planner_internal_types.h"
#include "proc_planner_types.h"
#include "rtwtypes.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdlib>

// Type Definitions
class TrajectoryGenerator {
public:
  TrajectoryGenerator *init(const char multiAddposeMsg_MessageType[25],
                            const coder::array<sonia_common_AddPoseStruct_T, 1U>
                                &multiAddposeMsg_Pose,
                            double param_amax, double param_vlmax,
                            double param_vamax, double icMsg_Position_X,
                            double icMsg_Position_Y, double icMsg_Position_Z,
                            double icMsg_Orientation_X,
                            double icMsg_Orientation_Y,
                            double icMsg_Orientation_Z,
                            double icMsg_Orientation_W);
  bool status;
  coder::array<double, 2U> pointList;
  coder::array<double, 2U> quatList;
  coder::array<double, 1U> timeList;
  coder::array<double, 2U> courseList;
  double nbPoint;
  struct_T param;

private:
  double n;
  sonia_common_MultiAddPoseStruct_T MAPM;
};

#endif
//
// File trailer for TrajectoryGenerator.h
//
// [EOF]
//
