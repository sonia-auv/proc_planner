//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: ros_node.h
//
// MATLAB Coder version            : 5.4
// C/C++ source code generated on  : 09-Jul-2022 16:26:05
//

#ifndef ROS_NODE_H
#define ROS_NODE_H

// Include Files
#include "Publisher.h"
#include "Subscriber.h"
#include "proc_planner_internal_types.h"
#include "rtwtypes.h"
#include <cstddef>
#include <cstdlib>

// Type Definitions
class ros_node {
public:
  static void persistentDataStore_init();
  coder::ros::Subscriber *madpSub;
  coder::ros::b_Subscriber *icSub;
  coder::ros::c_Subscriber *obstacleSub;
  coder::ros::Publisher *trajpub;
  coder::ros::b_Publisher *validPub;
  b_struct_T param;
  bool TrajIsGenerating;
  coder::ros::b_Publisher _pobj0;
  coder::ros::Publisher _pobj1;
  coder::ros::c_Subscriber _pobj2;
  coder::ros::b_Subscriber _pobj3;
  coder::ros::Subscriber _pobj4;
};

#endif
//
// File trailer for ros_node.h
//
// [EOF]
//
