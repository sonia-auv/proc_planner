//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: Subscriber.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 02-Feb-2022 17:45:08
//

#ifndef SUBSCRIBER_H
#define SUBSCRIBER_H

// Include Files
#include "proc_planner_types.h"
#include "rtwtypes.h"
#include "coder_array.h"
#include "mutex"
#include <cstddef>
#include <cstdlib>

// Type Definitions
namespace coder {
namespace ros {
class Subscriber {
public:
  Subscriber *init();
  void lock();
  void unlock();
  void callback();
  double get_MessageCount() const;
  void
  receive(char receivedMsg_MessageType[25],
          ::coder::array<sonia_common_AddPoseStruct_T, 1U> &receivedMsg_Pose,
          bool *status);
  void get_LatestMessage(
      char lastSubMsg_MessageType[25],
      ::coder::array<sonia_common_AddPoseStruct_T, 1U> &lastSubMsg_Pose);
  void matlabCodegenDestructor();
  ~Subscriber();
  Subscriber();

private:
  void Subscriber_delete() const;

public:
  bool matlabCodegenIsDeleted;
  char TopicName[32];
  double BufferSize;
  double MessageCount;

private:
  void *SubscriberHelper;
  sonia_common_MultiAddPoseStruct_T MsgStruct;
  std::mutex Mutex;
};

class b_Subscriber {
public:
  b_Subscriber *init();
  void lock();
  void unlock();
  void callback();
  double get_MessageCount() const;
  void receive(char receivedMsg_MessageType[18],
               geometry_msgs_PointStruct_T *receivedMsg_Position,
               geometry_msgs_QuaternionStruct_T *receivedMsg_Orientation,
               bool *status);
  void
  get_LatestMessage(char lastSubMsg_MessageType[18],
                    geometry_msgs_PointStruct_T *lastSubMsg_Position,
                    geometry_msgs_QuaternionStruct_T *lastSubMsg_Orientation);
  void matlabCodegenDestructor();
  ~b_Subscriber();
  b_Subscriber();
  bool matlabCodegenIsDeleted;
  char TopicName[25];
  double BufferSize;
  double MessageCount;

private:
  void *SubscriberHelper;
  geometry_msgs_PoseStruct_T MsgStruct;
  std::mutex Mutex;
};

} // namespace ros
} // namespace coder

#endif
//
// File trailer for Subscriber.h
//
// [EOF]
//
