//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: getOrientationState.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 02-Feb-2022 17:45:08
//

#ifndef GETORIENTATIONSTATE_H
#define GETORIENTATIONSTATE_H

// Include Files
#include "rtwtypes.h"
#include <cstddef>
#include <cstdlib>

// Type Declarations
namespace coder {
class quaternion;

}

// Function Declarations
namespace coder {
namespace fusion {
namespace scenario {
namespace internal {
void slew3(double t, double dt, const quaternion *qi, const double a[9],
           const double b[9], const double c[6], const double d[3],
           quaternion *q, double angVel[3], double angAcc[3],
           double angJerk[3]);

void slew3_init(double dt, double dtheta, const double e[3], const double wi[3],
                const double wf[3], double aa[9], double bb[9], double cc[6],
                double dd[3]);

} // namespace internal
} // namespace scenario
} // namespace fusion
} // namespace coder

#endif
//
// File trailer for getOrientationState.h
//
// [EOF]
//
