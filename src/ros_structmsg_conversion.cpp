#include "ros_structmsg_conversion.h"


// Conversions between geometry_msgs_PointStruct_T and geometry_msgs::Point

void struct2msg(geometry_msgs::Point* msgPtr, geometry_msgs_PointStruct_T const* structPtr)
{
  const std::string rosMessageType("geometry_msgs/Point");

  msgPtr->x =  structPtr->X;
  msgPtr->y =  structPtr->Y;
  msgPtr->z =  structPtr->Z;
}

void msg2struct(geometry_msgs_PointStruct_T* structPtr, geometry_msgs::Point const* msgPtr)
{
  const std::string rosMessageType("geometry_msgs/Point");

  structPtr->X =  msgPtr->x;
  structPtr->Y =  msgPtr->y;
  structPtr->Z =  msgPtr->z;
}


// Conversions between geometry_msgs_PoseStruct_T and geometry_msgs::Pose

void struct2msg(geometry_msgs::Pose* msgPtr, geometry_msgs_PoseStruct_T const* structPtr)
{
  const std::string rosMessageType("geometry_msgs/Pose");

  struct2msg(&msgPtr->orientation, &structPtr->Orientation);
  struct2msg(&msgPtr->position, &structPtr->Position);
}

void msg2struct(geometry_msgs_PoseStruct_T* structPtr, geometry_msgs::Pose const* msgPtr)
{
  const std::string rosMessageType("geometry_msgs/Pose");

  msg2struct(&structPtr->Orientation, &msgPtr->orientation);
  msg2struct(&structPtr->Position, &msgPtr->position);
}


// Conversions between geometry_msgs_QuaternionStruct_T and geometry_msgs::Quaternion

void struct2msg(geometry_msgs::Quaternion* msgPtr, geometry_msgs_QuaternionStruct_T const* structPtr)
{
  const std::string rosMessageType("geometry_msgs/Quaternion");

  msgPtr->w =  structPtr->W;
  msgPtr->x =  structPtr->X;
  msgPtr->y =  structPtr->Y;
  msgPtr->z =  structPtr->Z;
}

void msg2struct(geometry_msgs_QuaternionStruct_T* structPtr, geometry_msgs::Quaternion const* msgPtr)
{
  const std::string rosMessageType("geometry_msgs/Quaternion");

  structPtr->W =  msgPtr->w;
  structPtr->X =  msgPtr->x;
  structPtr->Y =  msgPtr->y;
  structPtr->Z =  msgPtr->z;
}


// Conversions between geometry_msgs_TransformStruct_T and geometry_msgs::Transform

void struct2msg(geometry_msgs::Transform* msgPtr, geometry_msgs_TransformStruct_T const* structPtr)
{
  const std::string rosMessageType("geometry_msgs/Transform");

  struct2msg(&msgPtr->rotation, &structPtr->Rotation);
  struct2msg(&msgPtr->translation, &structPtr->Translation);
}

void msg2struct(geometry_msgs_TransformStruct_T* structPtr, geometry_msgs::Transform const* msgPtr)
{
  const std::string rosMessageType("geometry_msgs/Transform");

  msg2struct(&structPtr->Rotation, &msgPtr->rotation);
  msg2struct(&structPtr->Translation, &msgPtr->translation);
}


// Conversions between geometry_msgs_TwistStruct_T and geometry_msgs::Twist

void struct2msg(geometry_msgs::Twist* msgPtr, geometry_msgs_TwistStruct_T const* structPtr)
{
  const std::string rosMessageType("geometry_msgs/Twist");

  struct2msg(&msgPtr->angular, &structPtr->Angular);
  struct2msg(&msgPtr->linear, &structPtr->Linear);
}

void msg2struct(geometry_msgs_TwistStruct_T* structPtr, geometry_msgs::Twist const* msgPtr)
{
  const std::string rosMessageType("geometry_msgs/Twist");

  msg2struct(&structPtr->Angular, &msgPtr->angular);
  msg2struct(&structPtr->Linear, &msgPtr->linear);
}


// Conversions between geometry_msgs_Vector3Struct_T and geometry_msgs::Vector3

void struct2msg(geometry_msgs::Vector3* msgPtr, geometry_msgs_Vector3Struct_T const* structPtr)
{
  const std::string rosMessageType("geometry_msgs/Vector3");

  msgPtr->x =  structPtr->X;
  msgPtr->y =  structPtr->Y;
  msgPtr->z =  structPtr->Z;
}

void msg2struct(geometry_msgs_Vector3Struct_T* structPtr, geometry_msgs::Vector3 const* msgPtr)
{
  const std::string rosMessageType("geometry_msgs/Vector3");

  structPtr->X =  msgPtr->x;
  structPtr->Y =  msgPtr->y;
  structPtr->Z =  msgPtr->z;
}


// Conversions between ros_DurationStruct_T and ros::Duration

void struct2msg(ros::Duration* msgPtr, ros_DurationStruct_T const* structPtr)
{
  const std::string rosMessageType("ros_time/Duration");

  msgPtr->nsec =  structPtr->Nsec;
  msgPtr->sec =  structPtr->Sec;
}

void msg2struct(ros_DurationStruct_T* structPtr, ros::Duration const* msgPtr)
{
  const std::string rosMessageType("ros_time/Duration");

  structPtr->Nsec =  msgPtr->nsec;
  structPtr->Sec =  msgPtr->sec;
}


// Conversions between ros_TimeStruct_T and ros::Time

void struct2msg(ros::Time* msgPtr, ros_TimeStruct_T const* structPtr)
{
  const std::string rosMessageType("ros_time/Time");

  msgPtr->nsec =  structPtr->Nsec;
  msgPtr->sec =  structPtr->Sec;
}

void msg2struct(ros_TimeStruct_T* structPtr, ros::Time const* msgPtr)
{
  const std::string rosMessageType("ros_time/Time");

  structPtr->Nsec =  msgPtr->nsec;
  structPtr->Sec =  msgPtr->sec;
}


// Conversions between sonia_common_AddPoseStruct_T and sonia_common::AddPose

void struct2msg(sonia_common::AddPose* msgPtr, sonia_common_AddPoseStruct_T const* structPtr)
{
  const std::string rosMessageType("sonia_common/AddPose");

  msgPtr->fine =  structPtr->Fine;
  msgPtr->frame =  structPtr->Frame;
  struct2msg(&msgPtr->orientation, &structPtr->Orientation);
  struct2msg(&msgPtr->position, &structPtr->Position);
  msgPtr->rotation =  structPtr->Rotation;
  msgPtr->speed =  structPtr->Speed;
}

void msg2struct(sonia_common_AddPoseStruct_T* structPtr, sonia_common::AddPose const* msgPtr)
{
  const std::string rosMessageType("sonia_common/AddPose");

  structPtr->Fine =  msgPtr->fine;
  structPtr->Frame =  msgPtr->frame;
  msg2struct(&structPtr->Orientation, &msgPtr->orientation);
  msg2struct(&structPtr->Position, &msgPtr->position);
  structPtr->Rotation =  msgPtr->rotation;
  structPtr->Speed =  msgPtr->speed;
}


// Conversions between sonia_common_MultiAddPoseStruct_T and sonia_common::MultiAddPose

void struct2msg(sonia_common::MultiAddPose* msgPtr, sonia_common_MultiAddPoseStruct_T const* structPtr)
{
  const std::string rosMessageType("sonia_common/MultiAddPose");

  msgPtr->interpolation_method =  structPtr->InterpolationMethod;
  convertFromStructNestedArray(msgPtr->pose, structPtr->Pose);
}

void msg2struct(sonia_common_MultiAddPoseStruct_T* structPtr, sonia_common::MultiAddPose const* msgPtr)
{
  const std::string rosMessageType("sonia_common/MultiAddPose");

  structPtr->InterpolationMethod =  msgPtr->interpolation_method;
  convertToStructNestedArray(structPtr->Pose, msgPtr->pose);
}


// Conversions between sonia_common_ObstacleArrayStruct_T and sonia_common::ObstacleArray

void struct2msg(sonia_common::ObstacleArray* msgPtr, sonia_common_ObstacleArrayStruct_T const* structPtr)
{
  const std::string rosMessageType("sonia_common/ObstacleArray");

  struct2msg(&msgPtr->header, &structPtr->Header);
  convertFromStructNestedArray(msgPtr->obstacles, structPtr->Obstacles);
}

void msg2struct(sonia_common_ObstacleArrayStruct_T* structPtr, sonia_common::ObstacleArray const* msgPtr)
{
  const std::string rosMessageType("sonia_common/ObstacleArray");

  msg2struct(&structPtr->Header, &msgPtr->header);
  convertToStructNestedArray(structPtr->Obstacles, msgPtr->obstacles);
}


// Conversions between sonia_common_ObstacleInfoStruct_T and sonia_common::ObstacleInfo

void struct2msg(sonia_common::ObstacleInfo* msgPtr, sonia_common_ObstacleInfoStruct_T const* structPtr)
{
  const std::string rosMessageType("sonia_common/ObstacleInfo");

  msgPtr->confidence =  structPtr->Confidence;
  msgPtr->is_valid =  structPtr->IsValid;
  convertFromStructPrimitiveArray(msgPtr->name, structPtr->Name);
  struct2msg(&msgPtr->pose, &structPtr->Pose);
}

void msg2struct(sonia_common_ObstacleInfoStruct_T* structPtr, sonia_common::ObstacleInfo const* msgPtr)
{
  const std::string rosMessageType("sonia_common/ObstacleInfo");

  structPtr->Confidence =  msgPtr->confidence;
  structPtr->IsValid =  msgPtr->is_valid;
  convertToStructPrimitiveArray(structPtr->Name, msgPtr->name);
  msg2struct(&structPtr->Pose, &msgPtr->pose);
}


// Conversions between std_msgs_HeaderStruct_T and std_msgs::Header

void struct2msg(std_msgs::Header* msgPtr, std_msgs_HeaderStruct_T const* structPtr)
{
  const std::string rosMessageType("std_msgs/Header");

  convertFromStructPrimitiveArray(msgPtr->frame_id, structPtr->FrameId);
  msgPtr->seq =  structPtr->Seq;
  struct2msg(&msgPtr->stamp, &structPtr->Stamp);
}

void msg2struct(std_msgs_HeaderStruct_T* structPtr, std_msgs::Header const* msgPtr)
{
  const std::string rosMessageType("std_msgs/Header");

  convertToStructPrimitiveArray(structPtr->FrameId, msgPtr->frame_id);
  structPtr->Seq =  msgPtr->seq;
  msg2struct(&structPtr->Stamp, &msgPtr->stamp);
}


// Conversions between std_msgs_Int8Struct_T and std_msgs::Int8

void struct2msg(std_msgs::Int8* msgPtr, std_msgs_Int8Struct_T const* structPtr)
{
  const std::string rosMessageType("std_msgs/Int8");

  msgPtr->data =  structPtr->Data;
}

void msg2struct(std_msgs_Int8Struct_T* structPtr, std_msgs::Int8 const* msgPtr)
{
  const std::string rosMessageType("std_msgs/Int8");

  structPtr->Data =  msgPtr->data;
}


// Conversions between trajectory_msgs_MultiDOFJointTrajectoryPointStruct_T and trajectory_msgs::MultiDOFJointTrajectoryPoint

void struct2msg(trajectory_msgs::MultiDOFJointTrajectoryPoint* msgPtr, trajectory_msgs_MultiDOFJointTrajectoryPointStruct_T const* structPtr)
{
  const std::string rosMessageType("trajectory_msgs/MultiDOFJointTrajectoryPoint");

  convertFromStructNestedArray(msgPtr->accelerations, structPtr->Accelerations);
  struct2msg(&msgPtr->time_from_start, &structPtr->TimeFromStart);
  convertFromStructNestedArray(msgPtr->transforms, structPtr->Transforms);
  convertFromStructNestedArray(msgPtr->velocities, structPtr->Velocities);
}

void msg2struct(trajectory_msgs_MultiDOFJointTrajectoryPointStruct_T* structPtr, trajectory_msgs::MultiDOFJointTrajectoryPoint const* msgPtr)
{
  const std::string rosMessageType("trajectory_msgs/MultiDOFJointTrajectoryPoint");

  convertToStructNestedArray(structPtr->Accelerations, msgPtr->accelerations);
  msg2struct(&structPtr->TimeFromStart, &msgPtr->time_from_start);
  convertToStructNestedArray(structPtr->Transforms, msgPtr->transforms);
  convertToStructNestedArray(structPtr->Velocities, msgPtr->velocities);
}

