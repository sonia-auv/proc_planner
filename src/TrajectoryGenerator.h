//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: TrajectoryGenerator.h
//
// MATLAB Coder version            : 5.4
// C/C++ source code generated on  : 09-Jul-2022 18:30:27
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

// Type Declarations
namespace coder {
namespace ros {
class Publisher;

}
} // namespace coder

// Type Definitions
class TrajectoryGenerator {
public:
  void processWpt();
  void Compute(const coder::ros::Publisher *trajpub);
  double status;
  sonia_common_MultiAddPoseStruct_T MAPM;
  b_struct_T param;
  sonia_common_ObstacleArrayStruct_T obstacleData;
  double nMAPM;
  double n;
  double icOffset;
  coder::array<double, 2U> pointList;
  coder::array<double, 2U> quatList;
  coder::array<double, 1U> timeList;
  coder::array<double, 2U> courseList;
  coder::array<double, 2U> speedList;
  double nbPoint;
  coder::array<double, 2U> trajPosition;
  coder::array<double, 2U> trajQuat;
  coder::array<double, 2U> trajBodyVelocity;
  coder::array<double, 2U> trajAngulairRates;
  coder::array<double, 2U> trajLinearAcceleration;
  coder::array<double, 2U> trajAngularAcceleration;
};

#endif
//
// File trailer for TrajectoryGenerator.h
//
// [EOF]
//
