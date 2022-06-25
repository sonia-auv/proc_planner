//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: ros_node.h
//
// MATLAB Coder version            : 5.4
// C/C++ source code generated on  : 25-Jun-2022 15:23:16
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

// Type Declarations
namespace coder {
namespace ros {
class Rate;

}
} // namespace coder

// Type Definitions
class ros_node {
public:
  void spin(coder::ros::Rate *b_spin);
  static void persistentDataStore_init();
  coder::ros::Subscriber *madpSub;
  coder::ros::b_Subscriber *icSub;
  coder::ros::Publisher *trajpub;
  coder::ros::b_Publisher *validPub;
  b_struct_T param;
  bool TrajIsGenerating;
  coder::ros::b_Publisher _pobj0;
  coder::ros::Publisher _pobj1;
  coder::ros::b_Subscriber _pobj2;
  coder::ros::Subscriber _pobj3;
};

#endif
//
// File trailer for ros_node.h
//
// [EOF]
//
