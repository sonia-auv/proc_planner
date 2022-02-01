#ifndef _ROS_STRUCTMSG_CONVERSION_H_
#define _ROS_STRUCTMSG_CONVERSION_H_

#include <ros/ros.h>
#include <geometry_msgs/Point.h>
#include <geometry_msgs/Pose.h>
#include <geometry_msgs/PoseWithCovariance.h>
#include <geometry_msgs/Quaternion.h>
#include <geometry_msgs/Transform.h>
#include <geometry_msgs/Twist.h>
#include <geometry_msgs/TwistWithCovariance.h>
#include <geometry_msgs/Vector3.h>
#include <nav_msgs/Odometry.h>
#include <ros/duration.h>
#include <ros/time.h>
#include <sonia_common/AddPose.h>
#include <sonia_common/MultiAddPose.h>
#include <std_msgs/Bool.h>
#include <std_msgs/Float64MultiArray.h>
#include <std_msgs/Header.h>
#include <std_msgs/MultiArrayDimension.h>
#include <std_msgs/MultiArrayLayout.h>
#include <trajectory_msgs/MultiDOFJointTrajectoryPoint.h>
#include "proc_planner_types.h"
#include "mlroscpp_msgconvert_utils.h"


void struct2msg(geometry_msgs::Point* msgPtr, geometry_msgs_PointStruct_T const* structPtr);
void msg2struct(geometry_msgs_PointStruct_T* structPtr, geometry_msgs::Point const* msgPtr);

void struct2msg(geometry_msgs::Pose* msgPtr, geometry_msgs_PoseStruct_T const* structPtr);
void msg2struct(geometry_msgs_PoseStruct_T* structPtr, geometry_msgs::Pose const* msgPtr);

void struct2msg(geometry_msgs::PoseWithCovariance* msgPtr, geometry_msgs_PoseWithCovarianceStruct_T const* structPtr);
void msg2struct(geometry_msgs_PoseWithCovarianceStruct_T* structPtr, geometry_msgs::PoseWithCovariance const* msgPtr);

void struct2msg(geometry_msgs::Quaternion* msgPtr, geometry_msgs_QuaternionStruct_T const* structPtr);
void msg2struct(geometry_msgs_QuaternionStruct_T* structPtr, geometry_msgs::Quaternion const* msgPtr);

void struct2msg(geometry_msgs::Transform* msgPtr, geometry_msgs_TransformStruct_T const* structPtr);
void msg2struct(geometry_msgs_TransformStruct_T* structPtr, geometry_msgs::Transform const* msgPtr);

void struct2msg(geometry_msgs::Twist* msgPtr, geometry_msgs_TwistStruct_T const* structPtr);
void msg2struct(geometry_msgs_TwistStruct_T* structPtr, geometry_msgs::Twist const* msgPtr);

void struct2msg(geometry_msgs::TwistWithCovariance* msgPtr, geometry_msgs_TwistWithCovarianceStruct_T const* structPtr);
void msg2struct(geometry_msgs_TwistWithCovarianceStruct_T* structPtr, geometry_msgs::TwistWithCovariance const* msgPtr);

void struct2msg(geometry_msgs::Vector3* msgPtr, geometry_msgs_Vector3Struct_T const* structPtr);
void msg2struct(geometry_msgs_Vector3Struct_T* structPtr, geometry_msgs::Vector3 const* msgPtr);

void struct2msg(nav_msgs::Odometry* msgPtr, nav_msgs_OdometryStruct_T const* structPtr);
void msg2struct(nav_msgs_OdometryStruct_T* structPtr, nav_msgs::Odometry const* msgPtr);

void struct2msg(ros::Duration* msgPtr, ros_DurationStruct_T const* structPtr);
void msg2struct(ros_DurationStruct_T* structPtr, ros::Duration const* msgPtr);

void struct2msg(ros::Time* msgPtr, ros_TimeStruct_T const* structPtr);
void msg2struct(ros_TimeStruct_T* structPtr, ros::Time const* msgPtr);

void struct2msg(sonia_common::AddPose* msgPtr, sonia_common_AddPoseStruct_T const* structPtr);
void msg2struct(sonia_common_AddPoseStruct_T* structPtr, sonia_common::AddPose const* msgPtr);

void struct2msg(sonia_common::MultiAddPose* msgPtr, sonia_common_MultiAddPoseStruct_T const* structPtr);
void msg2struct(sonia_common_MultiAddPoseStruct_T* structPtr, sonia_common::MultiAddPose const* msgPtr);

void struct2msg(std_msgs::Bool* msgPtr, std_msgs_BoolStruct_T const* structPtr);
void msg2struct(std_msgs_BoolStruct_T* structPtr, std_msgs::Bool const* msgPtr);

void struct2msg(std_msgs::Float64MultiArray* msgPtr, std_msgs_Float64MultiArrayStruct_T const* structPtr);
void msg2struct(std_msgs_Float64MultiArrayStruct_T* structPtr, std_msgs::Float64MultiArray const* msgPtr);

void struct2msg(std_msgs::Header* msgPtr, std_msgs_HeaderStruct_T const* structPtr);
void msg2struct(std_msgs_HeaderStruct_T* structPtr, std_msgs::Header const* msgPtr);

void struct2msg(std_msgs::MultiArrayDimension* msgPtr, std_msgs_MultiArrayDimensionStruct_T const* structPtr);
void msg2struct(std_msgs_MultiArrayDimensionStruct_T* structPtr, std_msgs::MultiArrayDimension const* msgPtr);

void struct2msg(std_msgs::MultiArrayLayout* msgPtr, std_msgs_MultiArrayLayoutStruct_T const* structPtr);
void msg2struct(std_msgs_MultiArrayLayoutStruct_T* structPtr, std_msgs::MultiArrayLayout const* msgPtr);

void struct2msg(trajectory_msgs::MultiDOFJointTrajectoryPoint* msgPtr, trajectory_msgs_MultiDOFJointTrajectoryPointStruct_T const* structPtr);
void msg2struct(trajectory_msgs_MultiDOFJointTrajectoryPointStruct_T* structPtr, trajectory_msgs::MultiDOFJointTrajectoryPoint const* msgPtr);


#endif
