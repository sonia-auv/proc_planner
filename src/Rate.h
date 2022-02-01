//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: Rate.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 01-Feb-2022 18:48:34
//

#ifndef RATE_H
#define RATE_H

// Include Files
#include "rtwtypes.h"
#include "coder_posix_time.h"
#include "mlroscpp_rate.h"
#include <cstddef>
#include <cstdlib>

// Type Definitions
namespace coder {
namespace ros {
class Rate {
public:
  Rate *init();
  void waitfor();
  MATLABRate RateHelper;
  double DesiredRate;

protected:
  coderTimespec PreviousPeriod;
};

} // namespace ros
} // namespace coder

#endif
//
// File trailer for Rate.h
//
// [EOF]
//
