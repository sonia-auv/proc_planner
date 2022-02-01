//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: Subscriber.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 01-Feb-2022 18:48:34
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
  void matlabCodegenDestructor();
  ~Subscriber();
  Subscriber();

private:
  void Subscriber_delete() const;

public:
  bool matlabCodegenIsDeleted;
  char TopicName[5];
  double BufferSize;
  double MessageCount;

private:
  void *SubscriberHelper;
  std_msgs_Float64MultiArrayStruct_T MsgStruct;
  std::mutex Mutex;
};

class b_Subscriber {
public:
  b_Subscriber *init();
  void lock();
  void unlock();
  void callback();
  double get_MessageCount() const;
  void matlabCodegenDestructor();
  ~b_Subscriber();
  b_Subscriber();

private:
  void Subscriber_delete() const;

public:
  bool matlabCodegenIsDeleted;
  char TopicName[5];
  double BufferSize;
  double MessageCount;

private:
  void *SubscriberHelper;
  std_msgs_BoolStruct_T MsgStruct;
  std::mutex Mutex;
};

class c_Subscriber {
public:
  c_Subscriber *init();
  void lock();
  void unlock();
  void callback();
  double get_MessageCount() const;
  void matlabCodegenDestructor();
  ~c_Subscriber();
  c_Subscriber();

private:
  void Subscriber_delete() const;

public:
  bool matlabCodegenIsDeleted;
  char TopicName[5];
  double BufferSize;
  double MessageCount;

private:
  void *SubscriberHelper;
  nav_msgs_OdometryStruct_T MsgStruct;
  std::mutex Mutex;
};

class d_Subscriber {
public:
  d_Subscriber *init();
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
  ~d_Subscriber();
  d_Subscriber();

private:
  void Subscriber_delete() const;

public:
  bool matlabCodegenIsDeleted;
  char TopicName[20];
  double BufferSize;
  double MessageCount;

private:
  void *SubscriberHelper;
  sonia_common_MultiAddPoseStruct_T MsgStruct;
  std::mutex Mutex;
};

class e_Subscriber {
public:
  e_Subscriber *init();
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
  ~e_Subscriber();
  e_Subscriber();
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
