//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: Publisher.cpp
//
// MATLAB Coder version            : 5.4
// C/C++ source code generated on  : 09-Jul-2022 18:30:27
//

// Include Files
#include "Publisher.h"
#include "proc_planner_types.h"
#include "rt_nonfinite.h"
#include "std_msgs_Int8Struct.h"
#include "trajectory_msgs_MultiDOFJointTrajectoryPointStruct.h"
#include "mlroscpp_pub.h"

// Function Definitions
//
// Arguments    : void
// Return Type  : Publisher *
//
namespace coder {
namespace ros {
Publisher *Publisher::init()
{
  static const char topic[34]{'/', 'p', 'r', 'o', 'c', '_', 'p', 'l', 'a',
                              'n', 'n', 'e', 'r', '/', 's', 'e', 'n', 'd',
                              '_', 't', 'r', 'a', 'j', 'e', 'c', 't', 'o',
                              'r', 'y', '_', 'l', 'i', 's', 't'};
  Publisher *obj;
  trajectory_msgs_MultiDOFJointTrajectoryPointStruct_T r;
  obj = this;
  for (int i{0}; i < 34; i++) {
    obj->TopicName[i] = topic[i];
  }
  obj->BufferSize = 1.0;
  obj->IsLatching = false;
  trajectory_msgs_MultiDOFJointTrajectoryPointStruct(&r);
  obj->PublisherHelper = std::unique_ptr<
      MATLABPublisher<trajectory_msgs::MultiDOFJointTrajectoryPoint,
                      trajectory_msgs_MultiDOFJointTrajectoryPointStruct_T>>(
      new MATLABPublisher<
          trajectory_msgs::MultiDOFJointTrajectoryPoint,
          trajectory_msgs_MultiDOFJointTrajectoryPointStruct_T>()); //();
  MATLABPUBLISHER_createPublisher(obj->PublisherHelper, &obj->TopicName[0],
                                  34.0, obj->BufferSize, obj->IsLatching);
  return obj;
}

//
// Arguments    : void
// Return Type  : b_Publisher *
//
b_Publisher *b_Publisher::init()
{
  static const char topic[32]{'/', 'p', 'r', 'o', 'c', '_', 'p', 'l',
                              'a', 'n', 'n', 'e', 'r', '/', 'i', 's',
                              '_', 'w', 'a', 'y', 'p', 'o', 'i', 'n',
                              't', 's', '_', 'v', 'a', 'l', 'i', 'd'};
  b_Publisher *obj;
  obj = this;
  for (int i{0}; i < 32; i++) {
    obj->TopicName[i] = topic[i];
  }
  obj->BufferSize = 1.0;
  obj->IsLatching = false;
  std_msgs_Int8Struct();
  obj->PublisherHelper =
      std::unique_ptr<MATLABPublisher<std_msgs::Int8, std_msgs_Int8Struct_T>>(
          new MATLABPublisher<std_msgs::Int8, std_msgs_Int8Struct_T>()); //();
  MATLABPUBLISHER_createPublisher(obj->PublisherHelper, &obj->TopicName[0],
                                  32.0, obj->BufferSize, obj->IsLatching);
  return obj;
}

} // namespace ros
} // namespace coder

//
// File trailer for Publisher.cpp
//
// [EOF]
//
