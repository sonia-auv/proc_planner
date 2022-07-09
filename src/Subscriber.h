//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: Subscriber.h
//
// MATLAB Coder version            : 5.4
// C/C++ source code generated on  : 09-Jul-2022 18:30:27
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
  void get_LatestMessage(double *lastSubMsg_Position_X,
                         double *lastSubMsg_Position_Y,
                         double *lastSubMsg_Position_Z,
                         double *lastSubMsg_Orientation_X,
                         double *lastSubMsg_Orientation_Y,
                         double *lastSubMsg_Orientation_Z,
                         double *lastSubMsg_Orientation_W) const;
  char TopicName[28];
  double BufferSize;
  double MessageCount;

private:
  std::unique_ptr<
      MATLABSubscriber<geometry_msgs::Pose, geometry_msgs_PoseStruct_T>>
      SubscriberHelper;
  geometry_msgs_PoseStruct_T MsgStruct;
  bool IsInitialized;
};

class c_Subscriber {
public:
  c_Subscriber *init();
  void callback();
  double get_MessageCount() const;
  void get_LatestMessage(sonia_common_ObstacleArrayStruct_T *lastSubMsg) const;
  char TopicName[28];
  double BufferSize;
  double MessageCount;

private:
  std::unique_ptr<MATLABSubscriber<sonia_common::ObstacleArray,
                                   sonia_common_ObstacleArrayStruct_T>>
      SubscriberHelper;
  sonia_common_ObstacleArrayStruct_T MsgStruct;
};

} // namespace ros
} // namespace coder

#endif
//
// File trailer for Subscriber.h
//
// [EOF]
//
