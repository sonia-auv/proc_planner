/* Copyright 2020 The MathWorks, Inc. */
#ifndef RATE_HELPER_H
#define RATE_HELPER_H

#include <ros/ros.h>

namespace coder {
namespace ros {
class MATLABRate {
  public:
    MATLABRate()
        : rate(1){};
    MATLABRate(double r)
        : rate(r){};
    bool isSimTime(){return ::ros::Time::isSimTime();};
  public:
    ::ros::Rate rate;
};
} // namespace ros
} // namespace coder

#endif
