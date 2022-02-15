//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: isequaln.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 09-Feb-2022 14:06:20
//

// Include Files
#include "isequaln.h"
#include "proc_planner_types.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <cmath>
#include <string.h>

// Function Definitions
//
// Arguments    : const char varargin_1_MessageType[25]
//                const ::coder::array<sonia_common_AddPoseStruct_T, 1U>
//                &varargin_1_Pose const char varargin_2_MessageType[25] const
//                ::coder::array<sonia_common_AddPoseStruct_T, 1U>
//                &varargin_2_Pose
// Return Type  : bool
//
namespace coder {
bool isequaln(
    const char varargin_1_MessageType[25],
    const ::coder::array<sonia_common_AddPoseStruct_T, 1U> &varargin_1_Pose,
    const char varargin_2_MessageType[25],
    const ::coder::array<sonia_common_AddPoseStruct_T, 1U> &varargin_2_Pose)
{
  int k;
  bool exitg1;
  bool out;
  bool p;
  p = (varargin_1_Pose.size(0) == varargin_2_Pose.size(0));
  if (p && (varargin_1_Pose.size(0) != 0) && (varargin_2_Pose.size(0) != 0)) {
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k <= varargin_2_Pose.size(0) - 1)) {
      if ((varargin_1_Pose[k].Rotation == varargin_2_Pose[k].Rotation) &&
          ((varargin_1_Pose[k].Fine == varargin_2_Pose[k].Fine) ||
           (std::isnan(varargin_1_Pose[k].Fine) &&
            std::isnan(varargin_2_Pose[k].Fine))) &&
          (varargin_1_Pose[k].Speed == varargin_2_Pose[k].Speed) &&
          (varargin_1_Pose[k].Frame == varargin_2_Pose[k].Frame) &&
          ((varargin_1_Pose[k].Orientation.Z ==
            varargin_2_Pose[k].Orientation.Z) ||
           (std::isnan(varargin_1_Pose[k].Orientation.Z) &&
            std::isnan(varargin_2_Pose[k].Orientation.Z))) &&
          ((varargin_1_Pose[k].Orientation.Y ==
            varargin_2_Pose[k].Orientation.Y) ||
           (std::isnan(varargin_1_Pose[k].Orientation.Y) &&
            std::isnan(varargin_2_Pose[k].Orientation.Y))) &&
          ((varargin_1_Pose[k].Orientation.X ==
            varargin_2_Pose[k].Orientation.X) ||
           (std::isnan(varargin_1_Pose[k].Orientation.X) &&
            std::isnan(varargin_2_Pose[k].Orientation.X)))) {
        int b_k;
        bool exitg2;
        out = true;
        b_k = 0;
        exitg2 = false;
        while ((!exitg2) && (b_k < 21)) {
          if (!(varargin_1_Pose[k].Orientation.MessageType[b_k] ==
                varargin_2_Pose[k].Orientation.MessageType[b_k])) {
            out = false;
            exitg2 = true;
          } else {
            b_k++;
          }
        }
        if (out &&
            ((varargin_1_Pose[k].Position.Z == varargin_2_Pose[k].Position.Z) ||
             (std::isnan(varargin_1_Pose[k].Position.Z) &&
              std::isnan(varargin_2_Pose[k].Position.Z))) &&
            ((varargin_1_Pose[k].Position.Y == varargin_2_Pose[k].Position.Y) ||
             (std::isnan(varargin_1_Pose[k].Position.Y) &&
              std::isnan(varargin_2_Pose[k].Position.Y))) &&
            ((varargin_1_Pose[k].Position.X == varargin_2_Pose[k].Position.X) ||
             (std::isnan(varargin_1_Pose[k].Position.X) &&
              std::isnan(varargin_2_Pose[k].Position.X)))) {
          out = true;
          b_k = 0;
          exitg2 = false;
          while ((!exitg2) && (b_k < 19)) {
            if (!(varargin_1_Pose[k].Position.MessageType[b_k] ==
                  varargin_2_Pose[k].Position.MessageType[b_k])) {
              out = false;
              exitg2 = true;
            } else {
              b_k++;
            }
          }
          if (out) {
            out = true;
            b_k = 0;
            exitg2 = false;
            while ((!exitg2) && (b_k < 20)) {
              if (!(varargin_1_Pose[k].MessageType[b_k] ==
                    varargin_2_Pose[k].MessageType[b_k])) {
                out = false;
                exitg2 = true;
              } else {
                b_k++;
              }
            }
            if (out) {
              k++;
            } else {
              p = false;
              exitg1 = true;
            }
          } else {
            p = false;
            exitg1 = true;
          }
        } else {
          p = false;
          exitg1 = true;
        }
      } else {
        p = false;
        exitg1 = true;
      }
    }
  }
  if (p) {
    out = true;
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 25)) {
      if (!(varargin_1_MessageType[k] == varargin_2_MessageType[k])) {
        out = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
    if (out) {
      p = true;
    } else {
      p = false;
    }
  } else {
    p = false;
  }
  return p;
}

//
// Arguments    : const char varargin_1_MessageType[18]
//                const char varargin_1_Position_MessageType[19]
//                double varargin_1_Position_X
//                double varargin_1_Position_Y
//                double varargin_1_Position_Z
//                const char varargin_1_Orientation_MessageType[24]
//                double varargin_1_Orientation_X
//                double varargin_1_Orientation_Y
//                double varargin_1_Orientation_Z
//                double varargin_1_Orientation_W
//                const char varargin_2_MessageType[18]
//                const geometry_msgs_PointStruct_T varargin_2_Position
//                const geometry_msgs_QuaternionStruct_T varargin_2_Orientation
// Return Type  : bool
//
bool isequaln(const char varargin_1_MessageType[18],
              const char varargin_1_Position_MessageType[19],
              double varargin_1_Position_X, double varargin_1_Position_Y,
              double varargin_1_Position_Z,
              const char varargin_1_Orientation_MessageType[24],
              double varargin_1_Orientation_X, double varargin_1_Orientation_Y,
              double varargin_1_Orientation_Z, double varargin_1_Orientation_W,
              const char varargin_2_MessageType[18],
              const geometry_msgs_PointStruct_T varargin_2_Position,
              const geometry_msgs_QuaternionStruct_T varargin_2_Orientation)
{
  bool p;
  if (((varargin_1_Orientation_W == varargin_2_Orientation.W) ||
       (std::isnan(varargin_1_Orientation_W) &&
        std::isnan(varargin_2_Orientation.W))) &&
      ((varargin_1_Orientation_Z == varargin_2_Orientation.Z) ||
       (std::isnan(varargin_1_Orientation_Z) &&
        std::isnan(varargin_2_Orientation.Z))) &&
      ((varargin_1_Orientation_Y == varargin_2_Orientation.Y) ||
       (std::isnan(varargin_1_Orientation_Y) &&
        std::isnan(varargin_2_Orientation.Y))) &&
      ((varargin_1_Orientation_X == varargin_2_Orientation.X) ||
       (std::isnan(varargin_1_Orientation_X) &&
        std::isnan(varargin_2_Orientation.X)))) {
    int k;
    bool exitg1;
    bool out;
    out = true;
    k = 0;
    exitg1 = false;
    while ((!exitg1) && (k < 24)) {
      if (!(varargin_1_Orientation_MessageType[k] ==
            varargin_2_Orientation.MessageType[k])) {
        out = false;
        exitg1 = true;
      } else {
        k++;
      }
    }
    if (out &&
        ((varargin_1_Position_Z == varargin_2_Position.Z) ||
         (std::isnan(varargin_1_Position_Z) &&
          std::isnan(varargin_2_Position.Z))) &&
        ((varargin_1_Position_Y == varargin_2_Position.Y) ||
         (std::isnan(varargin_1_Position_Y) &&
          std::isnan(varargin_2_Position.Y))) &&
        ((varargin_1_Position_X == varargin_2_Position.X) ||
         (std::isnan(varargin_1_Position_X) &&
          std::isnan(varargin_2_Position.X)))) {
      out = true;
      k = 0;
      exitg1 = false;
      while ((!exitg1) && (k < 19)) {
        if (!(varargin_1_Position_MessageType[k] ==
              varargin_2_Position.MessageType[k])) {
          out = false;
          exitg1 = true;
        } else {
          k++;
        }
      }
      if (out) {
        out = true;
        k = 0;
        exitg1 = false;
        while ((!exitg1) && (k < 18)) {
          if (!(varargin_1_MessageType[k] == varargin_2_MessageType[k])) {
            out = false;
            exitg1 = true;
          } else {
            k++;
          }
        }
        if (out) {
          p = true;
        } else {
          p = false;
        }
      } else {
        p = false;
      }
    } else {
      p = false;
    }
  } else {
    p = false;
  }
  return p;
}

} // namespace coder

//
// File trailer for isequaln.cpp
//
// [EOF]
//
