//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// Subscriber.cpp
//
// Code generation for function 'Subscriber'
//

// Include files
#include "Subscriber.h"
#include "geometry_msgs_PoseStruct.h"
#include "proc_planner_data.h"
#include "proc_planner_types.h"
#include "rt_nonfinite.h"
#include "sonia_common_MultiAddPoseStruct.h"
#include "sonia_common_ObstacleArrayStruct.h"
#include "coder_array.h"
#include "mlroscpp_sub.h"
#include <stdio.h>

// Function Definitions
namespace coder {
namespace ros {
void Subscriber::callback()
{
  MessageCount = get_MessageCount() + 1.0;
  if (IsInitialized) {
    //  MultiAddPose (mad) callback
    //  initialte variables
    //  SET
    newMadpPose = true;
    printf("INFO : proc planner : Poses received \n");
    fflush(stdout);
    printf("INFO : proc planner : Wait for initial pose \n");
    fflush(stdout);
  }
}

void b_Subscriber::callback()
{
  MessageCount = get_MessageCount() + 1.0;
  if (IsInitialized) {
    //  Initial condition (IC) callback
    //  initialte variables
    //  SET
    newInitialPose = true;
  }
}

void c_Subscriber::callback()
{
  MessageCount = get_MessageCount() + 1.0;
}

double Subscriber::get_MessageCount() const
{
  return MessageCount;
}

double b_Subscriber::get_MessageCount() const
{
  return MessageCount;
}

double c_Subscriber::get_MessageCount() const
{
  return MessageCount;
}

void Subscriber::get_LatestMessage(
    char lastSubMsg_MessageType[25],
    unsigned char *lastSubMsg_InterpolationMethod,
    ::coder::array<sonia_common_AddPoseStruct_T, 1U> &lastSubMsg_Pose) const
{
  int loop_ub;
  MATLABSUBSCRIBER_lock(SubscriberHelper);
  for (int i{0}; i < 25; i++) {
    lastSubMsg_MessageType[i] = MsgStruct.MessageType[i];
  }
  lastSubMsg_Pose.set_size(MsgStruct.Pose.size(0));
  loop_ub = MsgStruct.Pose.size(0);
  for (int i{0}; i < loop_ub; i++) {
    lastSubMsg_Pose[i] = MsgStruct.Pose[i];
  }
  MATLABSUBSCRIBER_unlock(SubscriberHelper);
  *lastSubMsg_InterpolationMethod = MsgStruct.InterpolationMethod;
}

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

void c_Subscriber::get_LatestMessage(
    sonia_common_ObstacleArrayStruct_T *lastSubMsg) const
{
  MATLABSUBSCRIBER_lock(SubscriberHelper);
  *lastSubMsg = MsgStruct;
  MATLABSUBSCRIBER_unlock(SubscriberHelper);
}

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

b_Subscriber *b_Subscriber::init()
{
  static const char topic[28]{'/', 'p', 'r', 'o', 'c', '_', 'c', 'o', 'n', 't',
                              'r', 'o', 'l', '/', 'c', 'u', 'r', 'r', 'e', 'n',
                              't', '_', 't', 'a', 'r', 'g', 'e', 't'};
  b_Subscriber *obj;
  obj = this;
  obj->IsInitialized = false;
  for (int i{0}; i < 28; i++) {
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
                                    28.0, obj->BufferSize);
  obj->callback();
  obj->IsInitialized = true;
  return obj;
}

c_Subscriber *c_Subscriber::init()
{
  static const char topic[28]{'/', 'p', 'r', 'o', 'c', '_', 'm', 'a', 'p', 'p',
                              'i', 'n', 'g', '/', 'o', 'b', 's', 't', 'a', 'c',
                              'l', 'e', '_', 'i', 'n', 'f', 'o', 's'};
  c_Subscriber *obj;
  obj = this;
  for (int i{0}; i < 28; i++) {
    obj->TopicName[i] = topic[i];
  }
  obj->BufferSize = 1.0;
  obj->MessageCount = 0.0;
  sonia_common_ObstacleArrayStruct(&obj->MsgStruct);
  auto structPtr = (&obj->MsgStruct);
  obj->SubscriberHelper =
      std::unique_ptr<MATLABSubscriber<sonia_common::ObstacleArray,
                                       sonia_common_ObstacleArrayStruct_T>>(
          new MATLABSubscriber<sonia_common::ObstacleArray,
                               sonia_common_ObstacleArrayStruct_T>(
              structPtr, [this] { this->callback(); })); //();
  MATLABSUBSCRIBER_createSubscriber(obj->SubscriberHelper, &obj->TopicName[0],
                                    28.0, obj->BufferSize);
  obj->callback();
  return obj;
}

} // namespace ros
} // namespace coder

// End of code generation (Subscriber.cpp)
