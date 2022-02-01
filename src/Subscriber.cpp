//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: Subscriber.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 01-Feb-2022 18:48:34
//

// Include Files
#include "Subscriber.h"
#include "geometry_msgs_PoseStruct.h"
#include "nav_msgs_OdometryStruct.h"
#include "proc_planner_data.h"
#include "proc_planner_types.h"
#include "rt_nonfinite.h"
#include "sonia_common_MultiAddPoseStruct.h"
#include "std_msgs_BoolStruct.h"
#include "std_msgs_Float64MultiArrayStruct.h"
#include "coder_array.h"
#include "mlroscpp_sub.h"
#include "mutex"
#include "ros/duration.h"
#include "ros/time.h"
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
void c_Subscriber::Subscriber_delete() const
{
  delete (SubscriberHelper);
}

//
// Arguments    : void
// Return Type  : void
//
void d_Subscriber::Subscriber_delete() const
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
void d_Subscriber::callback()
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
// Return Type  : void
//
void c_Subscriber::callback()
{
  MessageCount = get_MessageCount() + 1.0;
}

//
// Arguments    : void
// Return Type  : void
//
void e_Subscriber::callback()
{
  MessageCount = get_MessageCount() + 1.0;
}

//
// Arguments    : char lastSubMsg_MessageType[25]
//                ::coder::array<sonia_common_AddPoseStruct_T, 1U>
//                &lastSubMsg_Pose
// Return Type  : void
//
void d_Subscriber::get_LatestMessage(
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
// Arguments    : char lastSubMsg_MessageType[18]
//                geometry_msgs_PointStruct_T *lastSubMsg_Position
//                geometry_msgs_QuaternionStruct_T *lastSubMsg_Orientation
// Return Type  : void
//
void e_Subscriber::get_LatestMessage(
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
// Arguments    : void
// Return Type  : double
//
double d_Subscriber::get_MessageCount() const
{
  return MessageCount;
}

//
// Arguments    : void
// Return Type  : double
//
double c_Subscriber::get_MessageCount() const
{
  return MessageCount;
}

//
// Arguments    : void
// Return Type  : double
//
double e_Subscriber::get_MessageCount() const
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
// Return Type  : double
//
double Subscriber::get_MessageCount() const
{
  return MessageCount;
}

//
// Arguments    : void
// Return Type  : void
//
void d_Subscriber::lock()
{
  this->Mutex.lock(); //(&Mutex);
}

//
// Arguments    : void
// Return Type  : void
//
void e_Subscriber::lock()
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
void c_Subscriber::lock()
{
  this->Mutex.lock(); //(&Mutex);
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
void d_Subscriber::matlabCodegenDestructor()
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
void c_Subscriber::matlabCodegenDestructor()
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
void d_Subscriber::unlock()
{
  this->Mutex.unlock(); //(&Mutex);
}

//
// Arguments    : void
// Return Type  : void
//
void c_Subscriber::unlock()
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
// Return Type  : void
//
void e_Subscriber::unlock()
{
  this->Mutex.unlock(); //(&Mutex);
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
// Return Type  : c_Subscriber
//
c_Subscriber::c_Subscriber()
{
  matlabCodegenIsDeleted = true;
}

//
// Arguments    : void
// Return Type  : d_Subscriber
//
d_Subscriber::d_Subscriber()
{
  matlabCodegenIsDeleted = true;
}

//
// Arguments    : void
// Return Type  : e_Subscriber
//
e_Subscriber::e_Subscriber()
{
  matlabCodegenIsDeleted = true;
}

//
// Arguments    : void
// Return Type  : void
//
c_Subscriber::~c_Subscriber()
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
d_Subscriber::~d_Subscriber()
{
  matlabCodegenDestructor();
}

//
// Arguments    : void
// Return Type  : void
//
e_Subscriber::~e_Subscriber()
{
  matlabCodegenDestructor();
}

//
// Arguments    : void
// Return Type  : e_Subscriber *
//
e_Subscriber *e_Subscriber::init()
{
  static const char topic[25]{'p', 'r', 'o', 'c', '_', 'p', 'l', 'a', 'n',
                              'n', 'e', 'r', '/', 'i', 'n', 'i', 't', 'i',
                              'a', 'l', '_', 'p', 'o', 's', 'e'};
  e_Subscriber *obj;
  obj = this;
  for (int i{0}; i < 25; i++) {
    obj->TopicName[i] = topic[i];
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

//
// Arguments    : void
// Return Type  : d_Subscriber *
//
d_Subscriber *d_Subscriber::init()
{
  d_Subscriber *obj;
  obj = this;
  for (int i{0}; i < 20; i++) {
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
  sub->createSubscriber(&obj->TopicName[0], 20.0, obj->BufferSize);
  obj->SubscriberHelper = sub; //();
  input = obj->SubscriberHelper;
  //(input);
  obj->callback();
  obj->matlabCodegenIsDeleted = false;
  return obj;
}

//
// Arguments    : void
// Return Type  : c_Subscriber *
//
c_Subscriber *c_Subscriber::init()
{
  static const char topic[5]{'/', 'o', 'd', 'o', 'm'};
  c_Subscriber *obj;
  obj = this;
  for (int i{0}; i < 5; i++) {
    obj->TopicName[i] = topic[i];
  }
  void *input;
  obj->BufferSize = 1.0;
  obj->MessageCount = -1.0;
  //(&obj->Mutex);
  obj->lock();
  obj->unlock();
  nav_msgs_OdometryStruct(&obj->MsgStruct);
  auto structPtr = (&obj->MsgStruct);
  nav_msgs::Odometry *msgPtr = nullptr;                //();
  auto sub = make_subscriber(this, msgPtr, structPtr); //();
  sub->createSubscriber(&obj->TopicName[0], 5.0, obj->BufferSize);
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
  static const char topic[5]{'/', 's', 't', 'o', 'p'};
  b_Subscriber *obj;
  obj = this;
  for (int i{0}; i < 5; i++) {
    obj->TopicName[i] = topic[i];
  }
  void *input;
  obj->BufferSize = 1.0;
  obj->MessageCount = -1.0;
  //(&obj->Mutex);
  obj->lock();
  obj->unlock();
  obj->MsgStruct = std_msgs_BoolStruct();
  auto structPtr = (&obj->MsgStruct);
  std_msgs::Bool *msgPtr = nullptr;                    //();
  auto sub = make_subscriber(this, msgPtr, structPtr); //();
  sub->createSubscriber(&obj->TopicName[0], 5.0, obj->BufferSize);
  obj->SubscriberHelper = sub; //();
  input = obj->SubscriberHelper;
  //(input);
  obj->callback();
  obj->matlabCodegenIsDeleted = false;
  return obj;
}

//
// Arguments    : void
// Return Type  : Subscriber *
//
Subscriber *Subscriber::init()
{
  static const char topic[5]{'/', 'd', 'e', 's', 't'};
  Subscriber *obj;
  obj = this;
  for (int i{0}; i < 5; i++) {
    obj->TopicName[i] = topic[i];
  }
  void *input;
  obj->BufferSize = 1.0;
  obj->MessageCount = -1.0;
  //(&obj->Mutex);
  obj->lock();
  obj->unlock();
  std_msgs_Float64MultiArrayStruct(&obj->MsgStruct);
  auto structPtr = (&obj->MsgStruct);
  std_msgs::Float64MultiArray *msgPtr = nullptr;       //();
  auto sub = make_subscriber(this, msgPtr, structPtr); //();
  sub->createSubscriber(&obj->TopicName[0], 5.0, obj->BufferSize);
  obj->SubscriberHelper = sub; //();
  input = obj->SubscriberHelper;
  //(input);
  obj->callback();
  obj->matlabCodegenIsDeleted = false;
  return obj;
}

//
// Arguments    : void
// Return Type  : void
//
void e_Subscriber::matlabCodegenDestructor()
{
  if (!matlabCodegenIsDeleted) {
    matlabCodegenIsDeleted = true;
    delete (SubscriberHelper);
  }
}

//
// Arguments    : char receivedMsg_MessageType[18]
//                geometry_msgs_PointStruct_T *receivedMsg_Position
//                geometry_msgs_QuaternionStruct_T *receivedMsg_Orientation
//                bool *status
// Return Type  : void
//
void e_Subscriber::receive(
    char receivedMsg_MessageType[18],
    geometry_msgs_PointStruct_T *receivedMsg_Position,
    geometry_msgs_QuaternionStruct_T *receivedMsg_Orientation, bool *status)
{
  static const char b_statusText[7]{'t', 'i', 'm', 'e', 'o', 'u', 't'};
  bool statusFlag;
  ::ros::Time tStop;
  double nMessages;
  char statusText[7];
  nMessages = get_MessageCount();
  *status = false;
  for (int i{0}; i < 7; i++) {
    statusText[i] = b_statusText[i];
  }
  ::ros::Duration tDur;
  tDur = tDur.fromSec(5.0);
  tStop = ::ros::Time::now() + (tDur);
  statusFlag = false;
  while (get_MessageCount() == nMessages) {
    if (::ros::Time::now() >= tStop)
      break;
    else {
      statusFlag = true;
    }                     //(tStop);
    *status = statusFlag; //(statusFlag);
  }
  getStatusText(*status, &statusText[0]);
  get_LatestMessage(receivedMsg_MessageType, receivedMsg_Position,
                    receivedMsg_Orientation);
}

//
// Arguments    : char receivedMsg_MessageType[25]
//                ::coder::array<sonia_common_AddPoseStruct_T, 1U>
//                &receivedMsg_Pose bool *status
// Return Type  : void
//
void d_Subscriber::receive(
    char receivedMsg_MessageType[25],
    ::coder::array<sonia_common_AddPoseStruct_T, 1U> &receivedMsg_Pose,
    bool *status)
{
  static const char b_statusText[7]{'t', 'i', 'm', 'e', 'o', 'u', 't'};
  bool statusFlag;
  ::ros::Time tStop;
  double nMessages;
  char statusText[7];
  nMessages = get_MessageCount();
  *status = false;
  for (int i{0}; i < 7; i++) {
    statusText[i] = b_statusText[i];
  }
  ::ros::Duration tDur;
  tDur = tDur.fromSec(0.1);
  tStop = ::ros::Time::now() + (tDur);
  statusFlag = false;
  while (get_MessageCount() == nMessages) {
    if (::ros::Time::now() >= tStop)
      break;
    else {
      statusFlag = true;
    }                     //(tStop);
    *status = statusFlag; //(statusFlag);
  }
  getStatusText(*status, &statusText[0]);
  get_LatestMessage(receivedMsg_MessageType, receivedMsg_Pose);
}

} // namespace ros
} // namespace coder

//
// File trailer for Subscriber.cpp
//
// [EOF]
//
