//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: TrajectoryGenerator.h
//
// MATLAB Coder version            : 5.4
// C/C++ source code generated on  : 28-Apr-2022 22:18:34
//

#ifndef TRAJECTORYGENERATOR_H
#define TRAJECTORYGENERATOR_H

// Include Files
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
  void Compute(const coder::ros::Publisher *trajpub);
  TrajectoryGenerator *
  init(const char multiAddposeMsg_MessageType[25],
       unsigned char multiAddposeMsg_InterpolationMethod,
       const coder::array<sonia_common_AddPoseStruct_T, 1U>
           &multiAddposeMsg_Pose,
       double param_lowSpeed_amax, double param_lowSpeed_vlmax,
       double param_lowSpeed_vamax, double param_normalSpeed_amax,
       double param_normalSpeed_vlmax, double param_normalSpeed_vamax,
       double param_highSpeed_amax, double param_highSpeed_vlmax,
       double param_highSpeed_vamax,
       const geometry_msgs_PointStruct_T icMsg_Position,
       const geometry_msgs_QuaternionStruct_T icMsg_Orientation);
  double status;

private:
  sonia_common_MultiAddPoseStruct_T MAPM;
  b_struct_T param;
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
