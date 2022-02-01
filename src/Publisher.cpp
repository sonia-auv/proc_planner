//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: Publisher.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 01-Feb-2022 18:48:34
//

// Include Files
#include "Publisher.h"
#include "geometry_msgs_TwistStruct.h"
#include "geometry_msgs_Vector3Struct.h"
#include "proc_planner_data.h"
#include "proc_planner_types.h"
#include "rt_nonfinite.h"
#include "sonia_common_MultiAddPoseStruct.h"
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
void d_Publisher::Publisher_delete() const
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
// Return Type  : void
//
void d_Publisher::matlabCodegenDestructor()
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
// Return Type  : d_Publisher
//
d_Publisher::d_Publisher()
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
d_Publisher::~d_Publisher()
{
  matlabCodegenDestructor();
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
// Return Type  : c_Publisher *
//
c_Publisher *c_Publisher::init()
{
  static const char topic[34]{'/', 'p', 'r', 'o', 'c', '_', 'p', 'l', 'a',
                              'n', 'n', 'e', 'r', '/', 's', 'e', 'n', 'd',
                              '_', 't', 'r', 'a', 'j', 'e', 'c', 't', 'o',
                              'r', 'y', '_', 'l', 'i', 's', 't'};
  c_Publisher *obj;
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
// Arguments    : void
// Return Type  : d_Publisher *
//
d_Publisher *d_Publisher::init()
{
  d_Publisher *obj;
  sonia_common_MultiAddPoseStruct_T r;
  obj = this;
  for (int i{0}; i < 20; i++) {
    obj->TopicName[i] = cv[i];
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
// Return Type  : b_Publisher *
//
b_Publisher *b_Publisher::init()
{
  static const char topic[8]{'/', 'c', 'm', 'd', '_', 'v', 'e', 'l'};
  b_Publisher *obj;
  geometry_msgs_TwistStruct_T unusedExpr;
  obj = this;
  for (int i{0}; i < 8; i++) {
    obj->TopicName[i] = topic[i];
  }
  obj->BufferSize = 1.0;
  obj->IsLatching = true;
  geometry_msgs_TwistStruct(&unusedExpr);
  auto pub = new MATLABPublisher<geometry_msgs::Twist,
                                 geometry_msgs_TwistStruct_T>(); //();
  pub->createPublisher(&obj->TopicName[0], 8.0, obj->BufferSize,
                       obj->IsLatching);
  obj->PublisherHelper = pub; //();
  //(obj->PublisherHelper);
  obj->matlabCodegenIsDeleted = false;
  return obj;
}

//
// Arguments    : void
// Return Type  : Publisher *
//
Publisher *Publisher::init()
{
  static const char topic[17]{'p', 'r', 'o', 'c', '_', 'p', 'l', 'a', 'n',
                              'n', 'e', 'r', '/', 'p', 'o', 's', 'e'};
  Publisher *obj;
  obj = this;
  for (int i{0}; i < 17; i++) {
    obj->TopicName[i] = topic[i];
  }
  obj->BufferSize = 1.0;
  obj->IsLatching = true;
  geometry_msgs_Vector3Struct();
  auto pub = new MATLABPublisher<geometry_msgs::Vector3,
                                 geometry_msgs_Vector3Struct_T>(); //();
  pub->createPublisher(&obj->TopicName[0], 17.0, obj->BufferSize,
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
void c_Publisher::send(
    const trajectory_msgs_MultiDOFJointTrajectoryPointStruct_T *msgToSend)
{
  //(&MsgStruct);
  this->PublisherHelper->publish(*msgToSend);
}

} // namespace ros
} // namespace coder

//
// File trailer for Publisher.cpp
//
// [EOF]
//
