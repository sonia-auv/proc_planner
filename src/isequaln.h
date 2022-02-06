//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: isequaln.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 05-Feb-2022 14:39:35
//

#ifndef ISEQUALN_H
#define ISEQUALN_H

// Include Files
#include "rtwtypes.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdlib>

// Type Declarations
struct sonia_common_AddPoseStruct_T;

struct geometry_msgs_PointStruct_T;

struct geometry_msgs_QuaternionStruct_T;

// Function Declarations
namespace coder {
bool isequaln(
    const char varargin_1_MessageType[25],
    const ::coder::array<sonia_common_AddPoseStruct_T, 1U> &varargin_1_Pose,
    const char varargin_2_MessageType[25],
    const ::coder::array<sonia_common_AddPoseStruct_T, 1U> &varargin_2_Pose);

bool isequaln(const char varargin_1_MessageType[18],
              const char varargin_1_Position_MessageType[19],
              double varargin_1_Position_X, double varargin_1_Position_Y,
              double varargin_1_Position_Z,
              const char varargin_1_Orientation_MessageType[24],
              double varargin_1_Orientation_X, double varargin_1_Orientation_Y,
              double varargin_1_Orientation_Z, double varargin_1_Orientation_W,
              const char varargin_2_MessageType[18],
              const geometry_msgs_PointStruct_T varargin_2_Position,
              const geometry_msgs_QuaternionStruct_T varargin_2_Orientation);

} // namespace coder

#endif
//
// File trailer for isequaln.h
//
// [EOF]
//
