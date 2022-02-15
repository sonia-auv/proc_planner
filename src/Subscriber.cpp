//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: Subscriber.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 09-Feb-2022 14:06:20
//

// Include Files
#include "Subscriber.h"
#include "geometry_msgs_PoseStruct.h"
#include "proc_planner_data.h"
#include "proc_planner_types.h"
#include "rt_nonfinite.h"
#include "sonia_common_MultiAddPoseStruct.h"
#include "coder_array.h"
#include "mlroscpp_sub.h"
#include "mutex"
#include <string.h>

// Function Definitions
//
// Arguments    : void
// Return Type  : void
//
namespace coder {
namespace ros {
void b_Subscriber::Subscriber_delete() const
{
  delete (SubscriberHelper);
}

//
// Arguments    : void
// Return Type  : void
//
void Subscriber::Subscriber_delete() const
{
  delete (SubscriberHelper);
}

//
// Arguments    : void
// Return Type  : void
//
void Subscriber::callback()
{
  MessageCount = get_MessageCount() + 1.0;
}

//
// Arguments    : void
// Return Type  : void
//
void b_Subscriber::callback()
{
  MessageCount = get_MessageCount() + 1.0;
}

//
// Arguments    : void
// Return Type  : double
//
double Subscriber::get_MessageCount() const
{
  return MessageCount;
}

//
// Arguments    : void
// Return Type  : double
//
double b_Subscriber::get_MessageCount() const
{
  return MessageCount;
}

//
// Arguments    : void
// Return Type  : void
//
void b_Subscriber::lock()
{
  this->Mutex.lock(); //(&Mutex);
}

//
// Arguments    : void
// Return Type  : void
//
void Subscriber::lock()
{
  this->Mutex.lock(); //(&Mutex);
}

//
// Arguments    : void
// Return Type  : void
//
void Subscriber::matlabCodegenDestructor()
{
  if (!matlabCodegenIsDeleted) {
    matlabCodegenIsDeleted = true;
    Subscriber_delete();
  }
}

//
// Arguments    : void
// Return Type  : void
//
void b_Subscriber::matlabCodegenDestructor()
{
  if (!matlabCodegenIsDeleted) {
    matlabCodegenIsDeleted = true;
    Subscriber_delete();
  }
}

//
// Arguments    : void
// Return Type  : void
//
void Subscriber::unlock()
{
  this->Mutex.unlock(); //(&Mutex);
}

//
// Arguments    : void
// Return Type  : void
//
void b_Subscriber::unlock()
{
  this->Mutex.unlock(); //(&Mutex);
}

//
// Arguments    : void
// Return Type  : Subscriber
//
Subscriber::Subscriber()
{
  matlabCodegenIsDeleted = true;
}

//
// Arguments    : void
// Return Type  : b_Subscriber
//
b_Subscriber::b_Subscriber()
{
  matlabCodegenIsDeleted = true;
}

//
// Arguments    : void
// Return Type  : void
//
Subscriber::~Subscriber()
{
  matlabCodegenDestructor();
}

//
// Arguments    : void
// Return Type  : void
//
b_Subscriber::~b_Subscriber()
{
  matlabCodegenDestructor();
}

//
// Arguments    : char lastSubMsg_MessageType[18]
//                geometry_msgs_PointStruct_T *lastSubMsg_Position
//                geometry_msgs_QuaternionStruct_T *lastSubMsg_Orientation
// Return Type  : void
//
void b_Subscriber::get_LatestMessage(
    char lastSubMsg_MessageType[18],
    geometry_msgs_PointStruct_T *lastSubMsg_Position,
    geometry_msgs_QuaternionStruct_T *lastSubMsg_Orientation)
{
  lock();
  for (int i{0}; i < 18; i++) {
    lastSubMsg_MessageType[i] = MsgStruct.MessageType[i];
  }
  *lastSubMsg_Position = MsgStruct.Position;
  *lastSubMsg_Orientation = MsgStruct.Orientation;
  unlock();
}

//
// Arguments    : char lastSubMsg_MessageType[25]
//                ::coder::array<sonia_common_AddPoseStruct_T, 1U>
//                &lastSubMsg_Pose
// Return Type  : void
//
void Subscriber::get_LatestMessage(
    char lastSubMsg_MessageType[25],
    ::coder::array<sonia_common_AddPoseStruct_T, 1U> &lastSubMsg_Pose)
{
  int i;
  int loop_ub;
  lock();
  for (i = 0; i < 25; i++) {
    lastSubMsg_MessageType[i] = MsgStruct.MessageType[i];
  }
  lastSubMsg_Pose.set_size(MsgStruct.Pose.size(0));
  loop_ub = MsgStruct.Pose.size(0);
  for (i = 0; i < loop_ub; i++) {
    lastSubMsg_Pose[i] = MsgStruct.Pose[i];
  }
  unlock();
}

//
// Arguments    : void
// Return Type  : Subscriber *
//
Subscriber *Subscriber::init()
{
  Subscriber *obj;
  obj = this;
  for (int i{0}; i < 32; i++) {
    obj->TopicName[i] = cv[i];
  }
  void *input;
  obj->BufferSize = 1.0;
  obj->MessageCount = -1.0;
  //(&obj->Mutex);
  obj->lock();
  obj->unlock();
  sonia_common_MultiAddPoseStruct(&obj->MsgStruct);
  auto structPtr = (&obj->MsgStruct);
  sonia_common::MultiAddPose *msgPtr = nullptr;        //();
  auto sub = make_subscriber(this, msgPtr, structPtr); //();
  sub->createSubscriber(&obj->TopicName[0], 32.0, obj->BufferSize);
  obj->SubscriberHelper = sub; //();
  input = obj->SubscriberHelper;
  //(input);
  obj->callback();
  obj->matlabCodegenIsDeleted = false;
  return obj;
}

//
// Arguments    : void
// Return Type  : b_Subscriber *
//
b_Subscriber *b_Subscriber::init()
{
  b_Subscriber *obj;
  obj = this;
  for (int i{0}; i < 25; i++) {
    obj->TopicName[i] = cv1[i];
  }
  void *input;
  obj->BufferSize = 1.0;
  obj->MessageCount = -1.0;
  //(&obj->Mutex);
  obj->lock();
  obj->unlock();
  geometry_msgs_PoseStruct(&obj->MsgStruct);
  auto structPtr = (&obj->MsgStruct);
  geometry_msgs::Pose *msgPtr = nullptr;               //();
  auto sub = make_subscriber(this, msgPtr, structPtr); //();
  sub->createSubscriber(&obj->TopicName[0], 25.0, obj->BufferSize);
  obj->SubscriberHelper = sub; //();
  input = obj->SubscriberHelper;
  //(input);
  obj->callback();
  obj->matlabCodegenIsDeleted = false;
  return obj;
}

} // namespace ros
} // namespace coder

//
// File trailer for Subscriber.cpp
//
// [EOF]
//
