//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: Subscriber.cpp
//
// MATLAB Coder version            : 5.4
// C/C++ source code generated on  : 12-Apr-2022 11:44:16
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
#include <stdio.h>
#include <string.h>

// Function Definitions
//
// Arguments    : void
// Return Type  : void
//
namespace coder {
namespace ros {
void Subscriber::callback()
{
  MessageCount = get_MessageCount() + 1.0;
  if (IsInitialized) {
    //  MultiAddPose (mad) callback
    newMadpPose = true;
    printf("INFO : proc planner : Poses received \n");
    fflush(stdout);
    printf("INFO : proc planner : Wait for initial pose \n");
    fflush(stdout);
  }
}

//
// Arguments    : void
// Return Type  : void
//
void b_Subscriber::callback()
{
  MessageCount = get_MessageCount() + 1.0;
  if (IsInitialized && newMadpPose) {
    //  Initial condition (IC) callback
    newInitalPose = true;
    printf("INFO : proc planner : Initial poses received \n");
    fflush(stdout);
  }
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
// Arguments    : ::coder::array<sonia_common_AddPoseStruct_T, 1U> &lastSubMsg_Pose
// Return Type  : void
//
void Subscriber::get_LatestMessage(
    ::coder::array<sonia_common_AddPoseStruct_T, 1U> &lastSubMsg_Pose) const
{
  int loop_ub;
  MATLABSUBSCRIBER_lock(SubscriberHelper);
  lastSubMsg_Pose.set_size(MsgStruct.Pose.size(0));
  loop_ub = MsgStruct.Pose.size(0);
  for (int i{0}; i < loop_ub; i++) {
    lastSubMsg_Pose[i] = MsgStruct.Pose[i];
  }
  MATLABSUBSCRIBER_unlock(SubscriberHelper);
}

//
// Arguments    : double *lastSubMsg_Position_X
//                double *lastSubMsg_Position_Y
//                double *lastSubMsg_Position_Z
//                double *lastSubMsg_Orientation_X
//                double *lastSubMsg_Orientation_Y
//                double *lastSubMsg_Orientation_Z
//                double *lastSubMsg_Orientation_W
// Return Type  : void
//
void b_Subscriber::get_LatestMessage(double *lastSubMsg_Position_X,
                                     double *lastSubMsg_Position_Y,
                                     double *lastSubMsg_Position_Z,
                                     double *lastSubMsg_Orientation_X,
                                     double *lastSubMsg_Orientation_Y,
                                     double *lastSubMsg_Orientation_Z,
                                     double *lastSubMsg_Orientation_W) const
{
  MATLABSUBSCRIBER_lock(SubscriberHelper);
  *lastSubMsg_Position_X = MsgStruct.Position.X;
  *lastSubMsg_Position_Y = MsgStruct.Position.Y;
  *lastSubMsg_Position_Z = MsgStruct.Position.Z;
  *lastSubMsg_Orientation_X = MsgStruct.Orientation.X;
  *lastSubMsg_Orientation_Y = MsgStruct.Orientation.Y;
  *lastSubMsg_Orientation_Z = MsgStruct.Orientation.Z;
  *lastSubMsg_Orientation_W = MsgStruct.Orientation.W;
  MATLABSUBSCRIBER_unlock(SubscriberHelper);
}

//
// Arguments    : void
// Return Type  : Subscriber *
//
Subscriber *Subscriber::init()
{
  static const char topic[32]{'/', 'p', 'r', 'o', 'c', '_', 'p', 'l',
                              'a', 'n', 'n', 'e', 'r', '/', 's', 'e',
                              'n', 'd', '_', 'm', 'u', 'l', 't', 'i',
                              '_', 'a', 'd', 'd', 'p', 'o', 's', 'e'};
  Subscriber *obj;
  obj = this;
  obj->IsInitialized = false;
  for (int i{0}; i < 32; i++) {
    obj->TopicName[i] = topic[i];
  }
  obj->BufferSize = 1.0;
  obj->MessageCount = 0.0;
  sonia_common_MultiAddPoseStruct(&obj->MsgStruct);
  auto structPtr = (&obj->MsgStruct);
  obj->SubscriberHelper =
      std::unique_ptr<MATLABSubscriber<sonia_common::MultiAddPose,
                                       sonia_common_MultiAddPoseStruct_T>>(
          new MATLABSubscriber<sonia_common::MultiAddPose,
                               sonia_common_MultiAddPoseStruct_T>(
              structPtr, [this] { this->callback(); })); //();
  MATLABSUBSCRIBER_createSubscriber(obj->SubscriberHelper, &obj->TopicName[0],
                                    32.0, obj->BufferSize);
  obj->callback();
  obj->IsInitialized = true;
  return obj;
}

//
// Arguments    : void
// Return Type  : b_Subscriber *
//
b_Subscriber *b_Subscriber::init()
{
  static const char topic[25]{'p', 'r', 'o', 'c', '_', 'p', 'l', 'a', 'n',
                              'n', 'e', 'r', '/', 'i', 'n', 'i', 't', 'i',
                              'a', 'l', '_', 'p', 'o', 's', 'e'};
  b_Subscriber *obj;
  obj = this;
  obj->IsInitialized = false;
  for (int i{0}; i < 25; i++) {
    obj->TopicName[i] = topic[i];
  }
  obj->BufferSize = 1.0;
  obj->MessageCount = 0.0;
  geometry_msgs_PoseStruct(&obj->MsgStruct);
  auto structPtr = (&obj->MsgStruct);
  obj->SubscriberHelper = std::unique_ptr<
      MATLABSubscriber<geometry_msgs::Pose, geometry_msgs_PoseStruct_T>>(
      new MATLABSubscriber<geometry_msgs::Pose, geometry_msgs_PoseStruct_T>(
          structPtr, [this] { this->callback(); })); //();
  MATLABSUBSCRIBER_createSubscriber(obj->SubscriberHelper, &obj->TopicName[0],
                                    25.0, obj->BufferSize);
  obj->callback();
  obj->IsInitialized = true;
  return obj;
}

} // namespace ros
} // namespace coder

//
// File trailer for Subscriber.cpp
//
// [EOF]
//
