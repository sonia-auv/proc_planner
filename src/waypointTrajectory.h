//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: waypointTrajectory.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 08-Feb-2022 23:30:50
//

#ifndef WAYPOINTTRAJECTORY_H
#define WAYPOINTTRAJECTORY_H

// Include Files
#include "quaternion.h"
#include "rtwtypes.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdlib>

// Type Definitions
struct b_struct_T {
  coder::array<double, 2U> breaks;
  coder::array<double, 2U> coefs;
};

struct c_struct_T {
  coder::array<double, 2U> breaks;
  coder::array<double, 3U> coefs;
};

namespace coder {
class waypointTrajectory {
public:
  void step(double varargout_1[3], b_quaternion *varargout_2,
            double varargout_3[3], double varargout_4[3],
            double varargout_5[3]);
  waypointTrajectory *init(const ::coder::array<double, 2U> &varargin_1,
                           const ::coder::array<double, 1U> &varargin_2,
                           const quaternion *varargin_8);

protected:
  void setupWaypointParams();
  void setPose();

public:
  double SampleRate;
  array<double, 2U> Waypoints;
  array<double, 1U> TimeOfArrival;
  array<double, 2U> Velocities;
  array<double, 1U> Course;
  char ReferenceFrame[3];

private:
  int isInitialized;
  quaternion Quaternions;
  array<double, 1U> HorizontalCumulativeDistance;
  b_struct_T HorizontalDistancePiecewisePolynomial;
  c_struct_T HorizontalSpeedPiecewisePolynomial;
  c_struct_T HorizontalAccelerationPiecewisePolynomial;
  c_struct_T HorizontalJerkPiecewisePolynomial;
  array<double, 1U> HorizontalCurvatureInitial;
  array<double, 1U> HorizontalCurvatureFinal;
  array<creal_T, 1U> HorizontalInitialPosition;
  array<double, 1U> HorizontalPiecewiseLength;
  b_struct_T VerticalDistancePiecewisePolynomial;
  c_struct_T VerticalSpeedPiecewisePolynomial;
  c_struct_T VerticalAccelerationPiecewisePolynomial;
  c_struct_T VerticalJerkPiecewisePolynomial;
  double PathDuration;
  array<double, 1U> SegmentTimes;
  array<double, 1U> RadianSlewAngles;
  array<double, 2U> AxesOfRotation;
  array<double, 2U> RadianAngularVelocities;
  double CurrentTime;
  bool IsDoneStatus;
};

} // namespace coder

#endif
//
// File trailer for waypointTrajectory.h
//
// [EOF]
//
