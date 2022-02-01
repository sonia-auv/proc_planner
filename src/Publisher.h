//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: Publisher.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 01-Feb-2022 18:48:34
//

#ifndef PUBLISHER_H
#define PUBLISHER_H

// Include Files
#include "proc_planner_types.h"
#include "rtwtypes.h"
#include "mlroscpp_pub.h"
#include <cstddef>
#include <cstdlib>

// Type Definitions
namespace coder {
namespace ros {
class Publisher {
public:
  Publisher *init();
  void matlabCodegenDestructor();
  ~Publisher();
  Publisher();

private:
  void Publisher_delete() const;

public:
  bool matlabCodegenIsDeleted;
  char TopicName[17];
  double BufferSize;
  bool IsLatching;

private:
  MATLABPublisher<geometry_msgs::Vector3, geometry_msgs_Vector3Struct_T>
      *PublisherHelper;
};

class b_Publisher {
public:
  b_Publisher *init();
  void matlabCodegenDestructor();
  ~b_Publisher();
  b_Publisher();

private:
  void Publisher_delete() const;

public:
  bool matlabCodegenIsDeleted;
  char TopicName[8];
  double BufferSize;
  bool IsLatching;

private:
  MATLABPublisher<geometry_msgs::Twist, geometry_msgs_TwistStruct_T>
      *PublisherHelper;
};

class c_Publisher {
public:
  c_Publisher *init();
  void
  send(const trajectory_msgs_MultiDOFJointTrajectoryPointStruct_T *msgToSend);
  void matlabCodegenDestructor();
  ~c_Publisher();
  c_Publisher();

private:
  void Publisher_delete() const;

public:
  bool matlabCodegenIsDeleted;
  char TopicName[34];
  double BufferSize;
  bool IsLatching;

private:
  trajectory_msgs_MultiDOFJointTrajectoryPointStruct_T MsgStruct;
  MATLABPublisher<trajectory_msgs::MultiDOFJointTrajectoryPoint,
                  trajectory_msgs_MultiDOFJointTrajectoryPointStruct_T>
      *PublisherHelper;
};

class d_Publisher {
public:
  d_Publisher *init();
  void matlabCodegenDestructor();
  ~d_Publisher();
  d_Publisher();

private:
  void Publisher_delete() const;

public:
  bool matlabCodegenIsDeleted;
  char TopicName[20];
  double BufferSize;
  bool IsLatching;

private:
  MATLABPublisher<sonia_common::MultiAddPose, sonia_common_MultiAddPoseStruct_T>
      *PublisherHelper;
};

} // namespace ros
} // namespace coder

#endif
//
// File trailer for Publisher.h
//
// [EOF]
//
