//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: Publisher.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 02-Feb-2022 17:45:08
//

// Include Files
#include "Publisher.h"
#include "proc_planner_types.h"
#include "rt_nonfinite.h"
#include "sonia_common_MultiAddPoseStruct.h"
#include "std_msgs_BoolStruct.h"
#include "trajectory_msgs_MultiDOFJointTrajectoryPointStruct.h"
#include "mlroscpp_pub.h"
#include <string.h>

// Function Definitions
//
// Arguments    : void
// Return Type  : void
//
namespace coder {
namespace ros {
void c_Publisher::Publisher_delete() const
{
  delete (PublisherHelper);
}

//
// Arguments    : void
// Return Type  : void
//
void Publisher::Publisher_delete() const
{
  delete (PublisherHelper);
}

//
// Arguments    : void
// Return Type  : void
//
void b_Publisher::Publisher_delete() const
{
  delete (PublisherHelper);
}

//
// Arguments    : void
// Return Type  : void
//
void c_Publisher::matlabCodegenDestructor()
{
  if (!matlabCodegenIsDeleted) {
    matlabCodegenIsDeleted = true;
    Publisher_delete();
  }
}

//
// Arguments    : void
// Return Type  : void
//
void Publisher::matlabCodegenDestructor()
{
  if (!matlabCodegenIsDeleted) {
    matlabCodegenIsDeleted = true;
    Publisher_delete();
  }
}

//
// Arguments    : void
// Return Type  : void
//
void b_Publisher::matlabCodegenDestructor()
{
  if (!matlabCodegenIsDeleted) {
    matlabCodegenIsDeleted = true;
    Publisher_delete();
  }
}

//
// Arguments    : void
// Return Type  : c_Publisher
//
c_Publisher::c_Publisher()
{
  matlabCodegenIsDeleted = true;
}

//
// Arguments    : void
// Return Type  : b_Publisher
//
b_Publisher::b_Publisher()
{
  matlabCodegenIsDeleted = true;
}

//
// Arguments    : void
// Return Type  : Publisher
//
Publisher::Publisher()
{
  matlabCodegenIsDeleted = true;
}

//
// Arguments    : void
// Return Type  : void
//
b_Publisher::~b_Publisher()
{
  matlabCodegenDestructor();
}

//
// Arguments    : void
// Return Type  : void
//
c_Publisher::~c_Publisher()
{
  matlabCodegenDestructor();
}

//
// Arguments    : void
// Return Type  : void
//
Publisher::~Publisher()
{
  matlabCodegenDestructor();
}

//
// Arguments    : void
// Return Type  : Publisher *
//
Publisher *Publisher::init()
{
  static const char topic[20]{'/', 'p', 'r', 'o', 'c', '_', 'p', 'l', 'a', 'n',
                              'n', 'e', 'r', '/', 'm', 'a', 'd', 'p', 'o', 's'};
  Publisher *obj;
  sonia_common_MultiAddPoseStruct_T r;
  obj = this;
  for (int i{0}; i < 20; i++) {
    obj->TopicName[i] = topic[i];
  }
  obj->BufferSize = 1.0;
  obj->IsLatching = true;
  sonia_common_MultiAddPoseStruct(&r);
  auto pub = new MATLABPublisher<sonia_common::MultiAddPose,
                                 sonia_common_MultiAddPoseStruct_T>(); //();
  pub->createPublisher(&obj->TopicName[0], 20.0, obj->BufferSize,
                       obj->IsLatching);
  obj->PublisherHelper = pub; //();
  //(obj->PublisherHelper);
  obj->matlabCodegenIsDeleted = false;
  return obj;
}

//
// Arguments    : void
// Return Type  : c_Publisher *
//
c_Publisher *c_Publisher::init()
{
  static const char topic[31]{'/', 'p', 'r', 'o', 'c', '_', 'p', 'l',
                              'a', 'n', 'n', 'e', 'r', '/', 'i', 's',
                              '_', 'w', 'a', 'y', 'p', 'o', 'i', 'n',
                              't', '_', 'v', 'a', 'l', 'i', 'd'};
  c_Publisher *obj;
  obj = this;
  for (int i{0}; i < 31; i++) {
    obj->TopicName[i] = topic[i];
  }
  obj->BufferSize = 1.0;
  obj->IsLatching = true;
  obj->MsgStruct = std_msgs_BoolStruct();
  auto pub = new MATLABPublisher<std_msgs::Bool, std_msgs_BoolStruct_T>(); //();
  pub->createPublisher(&obj->TopicName[0], 31.0, obj->BufferSize,
                       obj->IsLatching);
  obj->PublisherHelper = pub; //();
  //(obj->PublisherHelper);
  obj->matlabCodegenIsDeleted = false;
  return obj;
}

//
// Arguments    : void
// Return Type  : b_Publisher *
//
b_Publisher *b_Publisher::init()
{
  static const char topic[34]{'/', 'p', 'r', 'o', 'c', '_', 'p', 'l', 'a',
                              'n', 'n', 'e', 'r', '/', 's', 'e', 'n', 'd',
                              '_', 't', 'r', 'a', 'j', 'e', 'c', 't', 'o',
                              'r', 'y', '_', 'l', 'i', 's', 't'};
  b_Publisher *obj;
  obj = this;
  for (int i{0}; i < 34; i++) {
    obj->TopicName[i] = topic[i];
  }
  obj->BufferSize = 1.0;
  obj->IsLatching = true;
  trajectory_msgs_MultiDOFJointTrajectoryPointStruct(&obj->MsgStruct);
  auto pub = new MATLABPublisher<
      trajectory_msgs::MultiDOFJointTrajectoryPoint,
      trajectory_msgs_MultiDOFJointTrajectoryPointStruct_T>(); //();
  pub->createPublisher(&obj->TopicName[0], 34.0, obj->BufferSize,
                       obj->IsLatching);
  obj->PublisherHelper = pub; //();
  //(obj->PublisherHelper);
  obj->matlabCodegenIsDeleted = false;
  return obj;
}

//
// Arguments    : const trajectory_msgs_MultiDOFJointTrajectoryPointStruct_T *msgToSend
// Return Type  : void
//
void b_Publisher::send(
    const trajectory_msgs_MultiDOFJointTrajectoryPointStruct_T *msgToSend)
{
  //(&MsgStruct);
  this->PublisherHelper->publish(*msgToSend);
}

//
// Arguments    : const std_msgs_BoolStruct_T msgToSend
// Return Type  : void
//
void c_Publisher::send(const std_msgs_BoolStruct_T msgToSend)
{
  //(&MsgStruct);
  this->PublisherHelper->publish(msgToSend);
}

} // namespace ros
} // namespace coder

//
// File trailer for Publisher.cpp
//
// [EOF]
//
