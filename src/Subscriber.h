//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: Subscriber.h
//
// MATLAB Coder version            : 5.4
// C/C++ source code generated on  : 26-Apr-2022 22:23:20
//

#ifndef SUBSCRIBER_H
#define SUBSCRIBER_H

// Include Files
#include "proc_planner_types.h"
#include "rtwtypes.h"
#include "coder_array.h"
#include "mlroscpp_sub.h"
#include <cstddef>
#include <cstdlib>

// Type Definitions
namespace coder {
namespace ros {
class Subscriber {
public:
  Subscriber *init();
  void callback();
  double get_MessageCount() const;
  void get_LatestMessage(
      char lastSubMsg_MessageType[25],
      unsigned char *lastSubMsg_InterpolationMethod,
      ::coder::array<sonia_common_AddPoseStruct_T, 1U> &lastSubMsg_Pose) const;
  char TopicName[32];
  double BufferSize;
  double MessageCount;

private:
  std::unique_ptr<MATLABSubscriber<sonia_common::MultiAddPose,
                                   sonia_common_MultiAddPoseStruct_T>>
      SubscriberHelper;
  sonia_common_MultiAddPoseStruct_T MsgStruct;
  bool IsInitialized;
};

class b_Subscriber {
public:
  b_Subscriber *init();
  void callback();
  double get_MessageCount() const;
  void get_LatestMessage(
      geometry_msgs_PointStruct_T *lastSubMsg_Position,
      geometry_msgs_QuaternionStruct_T *lastSubMsg_Orientation) const;
  char TopicName[25];
  double BufferSize;
  double MessageCount;

private:
  std::unique_ptr<
      MATLABSubscriber<geometry_msgs::Pose, geometry_msgs_PoseStruct_T>>
      SubscriberHelper;
  geometry_msgs_PoseStruct_T MsgStruct;
  bool IsInitialized;
};

} // namespace ros
} // namespace coder

#endif
//
// File trailer for Subscriber.h
//
// [EOF]
//
