//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: Rate.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 19-Feb-2022 14:46:56
//

// Include Files
#include "Rate.h"
#include "rt_nonfinite.h"
#include "tic.h"
#include "toc.h"
#include "coder_posix_time.h"
#include "mlroscpp_rate.h"
#include "ros/ros.h"
#include <string.h>

// Function Definitions
//
// Arguments    : void
// Return Type  : Rate *
//
namespace coder {
namespace ros {
Rate *Rate::init()
{
  Rate *obj;
  double b_expl_temp;
  double expl_temp;
  obj = this;
  obj->RateHelper = MATLABRate(1.0);
  //(obj->RateHelper);
  obj->DesiredRate = 1.0;
  tic(&expl_temp, &b_expl_temp);
  tic(&obj->PreviousPeriod.tv_sec, &obj->PreviousPeriod.tv_nsec);
  return obj;
}

//
// Arguments    : void
// Return Type  : void
//
void Rate::reset()
{
  double b_expl_temp;
  double expl_temp;
  //(&RateHelper);
  this->RateHelper.rate.reset(); //();
  tic(&expl_temp, &b_expl_temp);
}

//
// Arguments    : void
// Return Type  : void
//
void Rate::waitfor()
{
  //(&RateHelper);
  this->RateHelper.rate.sleep(); //();
  toc(PreviousPeriod.tv_sec, PreviousPeriod.tv_nsec);
  tic(&PreviousPeriod.tv_sec, &PreviousPeriod.tv_nsec);
}

} // namespace ros
} // namespace coder

//
// File trailer for Rate.cpp
//
// [EOF]
//
