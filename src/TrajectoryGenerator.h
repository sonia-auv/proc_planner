//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: TrajectoryGenerator.h
//
// MATLAB Coder version            : 5.4
// C/C++ source code generated on  : 25-Jun-2022 15:23:16
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
  TrajectoryGenerator *
  init(const char multiAddposeMsg_MessageType[25],
       unsigned char multiAddposeMsg_InterpolationMethod,
       const coder::array<sonia_common_AddPoseStruct_T, 1U>
           &multiAddposeMsg_Pose,
       const b_struct_T *b_param,
       const geometry_msgs_PointStruct_T icMsg_Position,
       const geometry_msgs_QuaternionStruct_T icMsg_Orientation);
  double status;
  sonia_common_MultiAddPoseStruct_T MAPM;
  b_struct_T param;
  coder::array<double, 2U> pointList;
  coder::array<double, 2U> quatList;
  coder::array<double, 1U> timeList;
  double nbPoint;
  coder::array<double, 2U> trajPosition;
  coder::array<double, 2U> trajQuat;
  coder::array<double, 2U> trajBodyVelocity;
  coder::array<double, 2U> trajAngulairRates;
  coder::array<double, 2U> trajLinearAcceleration;
  coder::array<double, 2U> trajAngularAcceleration;

private:
  double nMAPM;
  double n;
  double icOffset;
  coder::array<double, 2U> courseList;
  coder::array<double, 2U> speedList;
};

#endif
//
// File trailer for TrajectoryGenerator.h
//
// [EOF]
//
