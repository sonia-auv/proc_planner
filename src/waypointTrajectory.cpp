//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: waypointTrajectory.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 03-Feb-2022 14:08:22
//

// Include Files
#include "waypointTrajectory.h"
#include "bsearch.h"
#include "clothoidG1fit2wp.h"
#include "clothoidG2fitMissingCourse.h"
#include "derivpp.h"
#include "discretize.h"
#include "fresnelg2.h"
#include "getOrientationState.h"
#include "pchip.h"
#include "ppval.h"
#include "proc_planner_rtwutil.h"
#include "quaternion.h"
#include "quaternionC2fit.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <cfloat>
#include <cmath>
#include <string.h>

// Function Declarations
static double rt_remd_snf(double u0, double u1);

// Function Definitions
//
// Arguments    : void
// Return Type  : void
//
namespace coder {
void waypointTrajectory::setPose()
{
  if (((!(TimeOfArrival[0] <= 0.0)) ||
       (!(0.0 <= TimeOfArrival[TimeOfArrival.size(0) - 1]))) &&
      (0.0 > TimeOfArrival[TimeOfArrival.size(0) - 1])) {
    IsDoneStatus = true;
  }
}

//
// Arguments    : void
// Return Type  : void
//
void waypointTrajectory::setupWaypointParams()
{
  array<double, 2U> gndspeed;
  array<double, 2U> rate;
  array<double, 1U> course;
  array<double, 1U> varargin_1;
  double absx;
  double x;
  int i;
  int i1;
  int k;
  int nx;
  int sizes_idx_1;
  signed char b_input_sizes_idx_1;
  signed char input_sizes_idx_1;
  bool empty_non_axis_sizes;
  course.set_size(Course.size(0));
  nx = Course.size(0);
  for (i = 0; i < nx; i++) {
    course[i] = Course[i];
  }
  ppval(HorizontalSpeedPiecewisePolynomial.breaks,
        HorizontalSpeedPiecewisePolynomial.coefs, TimeOfArrival, gndspeed);
  ppval(VerticalSpeedPiecewisePolynomial.breaks,
        VerticalSpeedPiecewisePolynomial.coefs, TimeOfArrival, rate);
  varargin_1.set_size(course.size(0));
  nx = course.size(0);
  for (i = 0; i < nx; i++) {
    varargin_1[i] = course[i];
  }
  nx = course.size(0);
  for (k = 0; k < nx; k++) {
    if (std::isinf(varargin_1[k]) || std::isnan(varargin_1[k])) {
      varargin_1[k] = rtNaN;
    } else {
      x = rt_remd_snf(varargin_1[k], 360.0);
      absx = std::abs(x);
      if (absx > 180.0) {
        if (x > 0.0) {
          x -= 360.0;
        } else {
          x += 360.0;
        }
        absx = std::abs(x);
      }
      if (absx <= 45.0) {
        x *= 0.017453292519943295;
        input_sizes_idx_1 = 0;
      } else if (absx <= 135.0) {
        if (x > 0.0) {
          x = 0.017453292519943295 * (x - 90.0);
          input_sizes_idx_1 = 1;
        } else {
          x = 0.017453292519943295 * (x + 90.0);
          input_sizes_idx_1 = -1;
        }
      } else if (x > 0.0) {
        x = 0.017453292519943295 * (x - 180.0);
        input_sizes_idx_1 = 2;
      } else {
        x = 0.017453292519943295 * (x + 180.0);
        input_sizes_idx_1 = -2;
      }
      if (input_sizes_idx_1 == 0) {
        varargin_1[k] = std::cos(x);
      } else if (input_sizes_idx_1 == 1) {
        varargin_1[k] = -std::sin(x);
      } else if (input_sizes_idx_1 == -1) {
        varargin_1[k] = std::sin(x);
      } else {
        varargin_1[k] = -std::cos(x);
      }
    }
  }
  nx = course.size(0);
  for (k = 0; k < nx; k++) {
    if (std::isinf(course[k]) || std::isnan(course[k])) {
      course[k] = rtNaN;
    } else {
      x = rt_remd_snf(course[k], 360.0);
      absx = std::abs(x);
      if (absx > 180.0) {
        if (x > 0.0) {
          x -= 360.0;
        } else {
          x += 360.0;
        }
        absx = std::abs(x);
      }
      if (absx <= 45.0) {
        x *= 0.017453292519943295;
        input_sizes_idx_1 = 0;
      } else if (absx <= 135.0) {
        if (x > 0.0) {
          x = 0.017453292519943295 * (x - 90.0);
          input_sizes_idx_1 = 1;
        } else {
          x = 0.017453292519943295 * (x + 90.0);
          input_sizes_idx_1 = -1;
        }
      } else if (x > 0.0) {
        x = 0.017453292519943295 * (x - 180.0);
        input_sizes_idx_1 = 2;
      } else {
        x = 0.017453292519943295 * (x + 180.0);
        input_sizes_idx_1 = -2;
      }
      if (input_sizes_idx_1 == 0) {
        course[k] = std::sin(x);
      } else if (input_sizes_idx_1 == 1) {
        course[k] = std::cos(x);
      } else if (input_sizes_idx_1 == -1) {
        course[k] = -std::cos(x);
      } else {
        course[k] = -std::sin(x);
      }
    }
  }
  nx = varargin_1.size(0);
  for (i = 0; i < nx; i++) {
    varargin_1[i] = varargin_1[i] * gndspeed[i];
  }
  nx = course.size(0);
  for (i = 0; i < nx; i++) {
    course[i] = course[i] * gndspeed[i];
  }
  if (varargin_1.size(0) != 0) {
    k = varargin_1.size(0);
  } else if (course.size(0) != 0) {
    k = course.size(0);
  } else if ((rate.size(0) != 0) && (rate.size(1) != 0)) {
    k = rate.size(0);
  } else {
    k = 0;
    if (rate.size(0) > 0) {
      k = rate.size(0);
    }
  }
  empty_non_axis_sizes = (k == 0);
  if (empty_non_axis_sizes || (varargin_1.size(0) != 0)) {
    input_sizes_idx_1 = 1;
  } else {
    input_sizes_idx_1 = 0;
  }
  if (empty_non_axis_sizes || (course.size(0) != 0)) {
    b_input_sizes_idx_1 = 1;
  } else {
    b_input_sizes_idx_1 = 0;
  }
  if (empty_non_axis_sizes || ((rate.size(0) != 0) && (rate.size(1) != 0))) {
    sizes_idx_1 = rate.size(1);
  } else {
    sizes_idx_1 = 0;
  }
  Velocities.set_size(k,
                      (input_sizes_idx_1 + b_input_sizes_idx_1) + sizes_idx_1);
  nx = input_sizes_idx_1;
  for (i = 0; i < nx; i++) {
    for (i1 = 0; i1 < k; i1++) {
      Velocities[i1] = varargin_1[i1];
    }
  }
  nx = b_input_sizes_idx_1;
  for (i = 0; i < nx; i++) {
    for (i1 = 0; i1 < k; i1++) {
      Velocities[i1 + Velocities.size(0) * input_sizes_idx_1] = course[i1];
    }
  }
  for (i = 0; i < sizes_idx_1; i++) {
    for (i1 = 0; i1 < k; i1++) {
      Velocities[i1 + Velocities.size(0) *
                          ((i + input_sizes_idx_1) + b_input_sizes_idx_1)] =
          rate[i1 + k * i];
    }
  }
}

//
// Arguments    : double u0
//                double u1
// Return Type  : double
//
} // namespace coder
static double rt_remd_snf(double u0, double u1)
{
  double y;
  if (std::isnan(u0) || std::isnan(u1) || std::isinf(u0)) {
    y = rtNaN;
  } else if (std::isinf(u1)) {
    y = u0;
  } else if ((u1 != 0.0) && (u1 != std::trunc(u1))) {
    double q;
    q = std::abs(u0 / u1);
    if (!(std::abs(q - std::floor(q + 0.5)) > DBL_EPSILON * q)) {
      y = 0.0 * u0;
    } else {
      y = std::fmod(u0, u1);
    }
  } else {
    y = std::fmod(u0, u1);
  }
  return y;
}

//
// Arguments    : const ::coder::array<double, 2U> &varargin_1
//                const ::coder::array<double, 1U> &varargin_2
//                const quaternion *varargin_8
// Return Type  : waypointTrajectory *
//
namespace coder {
waypointTrajectory *
waypointTrajectory::init(const ::coder::array<double, 2U> &varargin_1,
                         const ::coder::array<double, 1U> &varargin_2,
                         const quaternion *varargin_8)
{
  quaternion b_obj;
  quaternion c_obj;
  quaternion q;
  waypointTrajectory *obj;
  array<creal_T, 1U> b_hip;
  array<creal_T, 1U> c_hip;
  array<creal_T, 1U> hip;
  array<double, 3U> happ_coefs;
  array<double, 3U> hjpp_coefs;
  array<double, 3U> hspp_coefs;
  array<double, 3U> vapp_coefs;
  array<double, 3U> vjpp_coefs;
  array<double, 3U> vspp_coefs;
  array<double, 2U> happ_breaks;
  array<double, 2U> hjpp_breaks;
  array<double, 2U> hpp_breaks;
  array<double, 2U> hpp_coefs;
  array<double, 2U> hspp_breaks;
  array<double, 2U> vapp_breaks;
  array<double, 2U> vjpp_breaks;
  array<double, 2U> vpp_breaks;
  array<double, 2U> vpp_coefs;
  array<double, 2U> vspp_breaks;
  array<double, 2U> w;
  array<double, 2U> waypoints;
  array<double, 1U> aasq;
  array<double, 1U> ab2;
  array<double, 1U> ac2;
  array<double, 1U> ad2;
  array<double, 1U> b_ac2;
  array<double, 1U> bc2;
  array<double, 1U> bd2;
  array<double, 1U> cd2;
  int b_loop_ub;
  int dimSize;
  int i;
  int i1;
  int i2;
  int loop_ub;
  int m;
  obj = this;
  obj->ReferenceFrame[0] = 'N';
  obj->ReferenceFrame[1] = 'E';
  obj->ReferenceFrame[2] = 'D';
  obj->isInitialized = 0;
  obj->Waypoints.set_size(varargin_1.size(0), 3);
  loop_ub = varargin_1.size(0) * 3;
  for (i = 0; i < loop_ub; i++) {
    obj->Waypoints[i] = varargin_1[i];
  }
  obj->TimeOfArrival.set_size(varargin_2.size(0));
  loop_ub = varargin_2.size(0);
  for (i = 0; i < loop_ub; i++) {
    obj->TimeOfArrival[i] = varargin_2[i];
  }
  obj->SampleRate = 10.0;
  obj->Quaternions = *varargin_8;
  aasq.set_size(obj->TimeOfArrival.size(0));
  loop_ub = obj->TimeOfArrival.size(0);
  for (i = 0; i < loop_ub; i++) {
    aasq[i] = obj->TimeOfArrival[i];
  }
  waypoints.set_size(obj->Waypoints.size(0), 3);
  loop_ub = obj->Waypoints.size(0) * 3;
  for (i = 0; i < loop_ub; i++) {
    waypoints[i] = obj->Waypoints[i];
  }
  ac2.set_size(aasq.size(0));
  loop_ub = aasq.size(0);
  for (i = 0; i < loop_ub; i++) {
    ac2[i] = rtNaN;
  }
  matlabshared::tracking::internal::scenario::clothoidG2fitMissingCourse(
      waypoints, ac2);
  loop_ub = waypoints.size(0);
  hip.set_size(waypoints.size(0));
  for (i = 0; i < loop_ub; i++) {
    hip[i].re = waypoints[i];
    hip[i].im = waypoints[i + waypoints.size(0)];
  }
  if (1.0 > static_cast<double>(aasq.size(0)) - 1.0) {
    loop_ub = 0;
  } else {
    loop_ub = aasq.size(0) - 1;
  }
  if (1.0 > static_cast<double>(aasq.size(0)) - 1.0) {
    b_loop_ub = 0;
  } else {
    b_loop_ub = aasq.size(0) - 1;
  }
  if (2 > aasq.size(0)) {
    i = 0;
    i1 = 0;
    dimSize = 0;
    m = 0;
  } else {
    i = 1;
    i1 = aasq.size(0);
    dimSize = 1;
    m = aasq.size(0);
  }
  b_hip.set_size(loop_ub);
  for (i2 = 0; i2 < loop_ub; i2++) {
    b_hip[i2] = hip[i2];
  }
  bd2.set_size(b_loop_ub);
  for (i2 = 0; i2 < b_loop_ub; i2++) {
    bd2[i2] = ac2[i2];
  }
  loop_ub = i1 - i;
  c_hip.set_size(loop_ub);
  for (i1 = 0; i1 < loop_ub; i1++) {
    c_hip[i1] = hip[i + i1];
  }
  loop_ub = m - dimSize;
  b_ac2.set_size(loop_ub);
  for (i = 0; i < loop_ub; i++) {
    b_ac2[i] = ac2[dimSize + i];
  }
  matlabshared::tracking::internal::scenario::clothoidG1fit2wp(
      b_hip, bd2, c_hip, b_ac2, ab2, ad2, bc2);
  bd2.set_size(bc2.size(0));
  loop_ub = bc2.size(0);
  for (i = 0; i < loop_ub; i++) {
    bd2[i] = bc2[i];
  }
  if ((bc2.size(0) != 1) && (bc2.size(0) != 0) && (bc2.size(0) != 1)) {
    i = bc2.size(0);
    for (dimSize = 0; dimSize <= i - 2; dimSize++) {
      bd2[dimSize + 1] = bd2[dimSize] + bd2[dimSize + 1];
    }
  }
  cd2.set_size(bd2.size(0) + 1);
  cd2[0] = 0.0;
  loop_ub = bd2.size(0);
  for (i = 0; i < loop_ub; i++) {
    cd2[i + 1] = bd2[i];
  }
  pchip(aasq, cd2, hpp_breaks, hpp_coefs);
  matlabshared::tracking::internal::scenario::derivpp(hpp_breaks, hpp_coefs,
                                                      hspp_breaks, hspp_coefs);
  matlabshared::tracking::internal::scenario::derivpp(hspp_breaks, hspp_coefs,
                                                      happ_breaks, happ_coefs);
  matlabshared::tracking::internal::scenario::derivpp(happ_breaks, happ_coefs,
                                                      hjpp_breaks, hjpp_coefs);
  loop_ub = waypoints.size(0);
  b_ac2.set_size(waypoints.size(0));
  for (i = 0; i < loop_ub; i++) {
    b_ac2[i] = waypoints[i + waypoints.size(0) * 2];
  }
  pchip(aasq, b_ac2, vpp_breaks, vpp_coefs);
  matlabshared::tracking::internal::scenario::derivpp(vpp_breaks, vpp_coefs,
                                                      vspp_breaks, vspp_coefs);
  matlabshared::tracking::internal::scenario::derivpp(vspp_breaks, vspp_coefs,
                                                      vapp_breaks, vapp_coefs);
  matlabshared::tracking::internal::scenario::derivpp(vapp_breaks, vapp_coefs,
                                                      vjpp_breaks, vjpp_coefs);
  obj->HorizontalCumulativeDistance.set_size(cd2.size(0));
  loop_ub = cd2.size(0);
  for (i = 0; i < loop_ub; i++) {
    obj->HorizontalCumulativeDistance[i] = cd2[i];
  }
  obj->HorizontalDistancePiecewisePolynomial.breaks.set_size(
      1, hpp_breaks.size(1));
  loop_ub = hpp_breaks.size(1);
  for (i = 0; i < loop_ub; i++) {
    obj->HorizontalDistancePiecewisePolynomial.breaks[i] = hpp_breaks[i];
  }
  obj->HorizontalDistancePiecewisePolynomial.coefs.set_size(hpp_coefs.size(0),
                                                            4);
  loop_ub = hpp_coefs.size(0) * 4;
  for (i = 0; i < loop_ub; i++) {
    obj->HorizontalDistancePiecewisePolynomial.coefs[i] = hpp_coefs[i];
  }
  obj->HorizontalSpeedPiecewisePolynomial.breaks.set_size(1,
                                                          hspp_breaks.size(1));
  loop_ub = hspp_breaks.size(1);
  for (i = 0; i < loop_ub; i++) {
    obj->HorizontalSpeedPiecewisePolynomial.breaks[i] = hspp_breaks[i];
  }
  obj->HorizontalSpeedPiecewisePolynomial.coefs.set_size(
      hspp_coefs.size(0), hspp_coefs.size(1), hspp_coefs.size(2));
  loop_ub = hspp_coefs.size(0) * hspp_coefs.size(1) * hspp_coefs.size(2);
  for (i = 0; i < loop_ub; i++) {
    obj->HorizontalSpeedPiecewisePolynomial.coefs[i] = hspp_coefs[i];
  }
  obj->HorizontalAccelerationPiecewisePolynomial.breaks.set_size(
      1, happ_breaks.size(1));
  loop_ub = happ_breaks.size(1);
  for (i = 0; i < loop_ub; i++) {
    obj->HorizontalAccelerationPiecewisePolynomial.breaks[i] = happ_breaks[i];
  }
  obj->HorizontalAccelerationPiecewisePolynomial.coefs.set_size(
      happ_coefs.size(0), happ_coefs.size(1), happ_coefs.size(2));
  loop_ub = happ_coefs.size(0) * happ_coefs.size(1) * happ_coefs.size(2);
  for (i = 0; i < loop_ub; i++) {
    obj->HorizontalAccelerationPiecewisePolynomial.coefs[i] = happ_coefs[i];
  }
  obj->HorizontalJerkPiecewisePolynomial.breaks.set_size(1,
                                                         hjpp_breaks.size(1));
  loop_ub = hjpp_breaks.size(1);
  for (i = 0; i < loop_ub; i++) {
    obj->HorizontalJerkPiecewisePolynomial.breaks[i] = hjpp_breaks[i];
  }
  obj->HorizontalJerkPiecewisePolynomial.coefs.set_size(
      hjpp_coefs.size(0), hjpp_coefs.size(1), hjpp_coefs.size(2));
  loop_ub = hjpp_coefs.size(0) * hjpp_coefs.size(1) * hjpp_coefs.size(2);
  for (i = 0; i < loop_ub; i++) {
    obj->HorizontalJerkPiecewisePolynomial.coefs[i] = hjpp_coefs[i];
  }
  obj->HorizontalCurvatureInitial.set_size(ab2.size(0));
  loop_ub = ab2.size(0);
  for (i = 0; i < loop_ub; i++) {
    obj->HorizontalCurvatureInitial[i] = ab2[i];
  }
  obj->HorizontalCurvatureFinal.set_size(ad2.size(0));
  loop_ub = ad2.size(0);
  for (i = 0; i < loop_ub; i++) {
    obj->HorizontalCurvatureFinal[i] = ad2[i];
  }
  obj->HorizontalInitialPosition.set_size(hip.size(0));
  loop_ub = hip.size(0);
  for (i = 0; i < loop_ub; i++) {
    obj->HorizontalInitialPosition[i] = hip[i];
  }
  obj->HorizontalPiecewiseLength.set_size(bc2.size(0));
  loop_ub = bc2.size(0);
  for (i = 0; i < loop_ub; i++) {
    obj->HorizontalPiecewiseLength[i] = bc2[i];
  }
  obj->VerticalDistancePiecewisePolynomial.breaks.set_size(1,
                                                           vpp_breaks.size(1));
  loop_ub = vpp_breaks.size(1);
  for (i = 0; i < loop_ub; i++) {
    obj->VerticalDistancePiecewisePolynomial.breaks[i] = vpp_breaks[i];
  }
  obj->VerticalDistancePiecewisePolynomial.coefs.set_size(vpp_coefs.size(0), 4);
  loop_ub = vpp_coefs.size(0) * 4;
  for (i = 0; i < loop_ub; i++) {
    obj->VerticalDistancePiecewisePolynomial.coefs[i] = vpp_coefs[i];
  }
  obj->VerticalSpeedPiecewisePolynomial.breaks.set_size(1, vspp_breaks.size(1));
  loop_ub = vspp_breaks.size(1);
  for (i = 0; i < loop_ub; i++) {
    obj->VerticalSpeedPiecewisePolynomial.breaks[i] = vspp_breaks[i];
  }
  obj->VerticalSpeedPiecewisePolynomial.coefs.set_size(
      vspp_coefs.size(0), vspp_coefs.size(1), vspp_coefs.size(2));
  loop_ub = vspp_coefs.size(0) * vspp_coefs.size(1) * vspp_coefs.size(2);
  for (i = 0; i < loop_ub; i++) {
    obj->VerticalSpeedPiecewisePolynomial.coefs[i] = vspp_coefs[i];
  }
  obj->VerticalAccelerationPiecewisePolynomial.breaks.set_size(
      1, vapp_breaks.size(1));
  loop_ub = vapp_breaks.size(1);
  for (i = 0; i < loop_ub; i++) {
    obj->VerticalAccelerationPiecewisePolynomial.breaks[i] = vapp_breaks[i];
  }
  obj->VerticalAccelerationPiecewisePolynomial.coefs.set_size(
      vapp_coefs.size(0), vapp_coefs.size(1), vapp_coefs.size(2));
  loop_ub = vapp_coefs.size(0) * vapp_coefs.size(1) * vapp_coefs.size(2);
  for (i = 0; i < loop_ub; i++) {
    obj->VerticalAccelerationPiecewisePolynomial.coefs[i] = vapp_coefs[i];
  }
  obj->VerticalJerkPiecewisePolynomial.breaks.set_size(1, vjpp_breaks.size(1));
  loop_ub = vjpp_breaks.size(1);
  for (i = 0; i < loop_ub; i++) {
    obj->VerticalJerkPiecewisePolynomial.breaks[i] = vjpp_breaks[i];
  }
  obj->VerticalJerkPiecewisePolynomial.coefs.set_size(
      vjpp_coefs.size(0), vjpp_coefs.size(1), vjpp_coefs.size(2));
  loop_ub = vjpp_coefs.size(0) * vjpp_coefs.size(1) * vjpp_coefs.size(2);
  for (i = 0; i < loop_ub; i++) {
    obj->VerticalJerkPiecewisePolynomial.coefs[i] = vjpp_coefs[i];
  }
  obj->Course.set_size(ac2.size(0));
  loop_ub = ac2.size(0);
  for (i = 0; i < loop_ub; i++) {
    obj->Course[i] = 57.295779513082323 * ac2[i];
  }
  obj->PathDuration = aasq[aasq.size(0) - 1];
  q = obj->Quaternions;
  aasq.set_size(obj->TimeOfArrival.size(0));
  loop_ub = obj->TimeOfArrival.size(0);
  for (i = 0; i < loop_ub; i++) {
    aasq[i] = obj->TimeOfArrival[i];
  }
  m = q.a.size(0) * q.a.size(1);
  dimSize = aasq.size(0);
  if (aasq.size(0) == 0) {
    ab2.set_size(0);
  } else {
    b_loop_ub = aasq.size(0) - 1;
    if (b_loop_ub > 1) {
      b_loop_ub = 1;
    }
    if (b_loop_ub < 1) {
      ab2.set_size(0);
    } else {
      ac2.set_size(1);
      ab2.set_size(aasq.size(0) - 1);
      if (aasq.size(0) - 1 != 0) {
        ac2[0] = aasq[0];
        for (b_loop_ub = 2; b_loop_ub <= dimSize; b_loop_ub++) {
          double tmp1;
          double tmp2;
          tmp1 = aasq[b_loop_ub - 1];
          tmp2 = ac2[0];
          ac2[0] = tmp1;
          tmp1 -= tmp2;
          ab2[b_loop_ub - 2] = tmp1;
        }
      }
    }
  }
  if (m - 1 < 1) {
    hpp_breaks.set_size(1, 0);
  } else {
    hpp_breaks.set_size(
        1, static_cast<int>((static_cast<double>(m) - 1.0) - 1.0) + 1);
    loop_ub = static_cast<int>((static_cast<double>(m) - 1.0) - 1.0);
    for (i = 0; i <= loop_ub; i++) {
      hpp_breaks[i] = static_cast<double>(i) + 1.0;
    }
  }
  if (m < 2) {
    hspp_breaks.set_size(1, 0);
  } else {
    hspp_breaks.set_size(1, m - 1);
    loop_ub = m - 2;
    for (i = 0; i <= loop_ub; i++) {
      hspp_breaks[i] = static_cast<double>(i) + 2.0;
    }
  }
  b_obj.a.set_size(1, hpp_breaks.size(1));
  loop_ub = hpp_breaks.size(1);
  for (i = 0; i < loop_ub; i++) {
    b_obj.a[i] = q.a[static_cast<int>(hpp_breaks[i]) - 1];
  }
  b_obj.b.set_size(1, hpp_breaks.size(1));
  loop_ub = hpp_breaks.size(1);
  for (i = 0; i < loop_ub; i++) {
    b_obj.b[i] = q.b[static_cast<int>(hpp_breaks[i]) - 1];
  }
  b_obj.c.set_size(1, hpp_breaks.size(1));
  loop_ub = hpp_breaks.size(1);
  for (i = 0; i < loop_ub; i++) {
    b_obj.c[i] = q.c[static_cast<int>(hpp_breaks[i]) - 1];
  }
  b_obj.d.set_size(1, hpp_breaks.size(1));
  loop_ub = hpp_breaks.size(1);
  for (i = 0; i < loop_ub; i++) {
    b_obj.d[i] = q.d[static_cast<int>(hpp_breaks[i]) - 1];
  }
  c_obj.a.set_size(1, hspp_breaks.size(1));
  loop_ub = hspp_breaks.size(1);
  for (i = 0; i < loop_ub; i++) {
    c_obj.a[i] = q.a[static_cast<int>(hspp_breaks[i]) - 1];
  }
  c_obj.b.set_size(1, hspp_breaks.size(1));
  loop_ub = hspp_breaks.size(1);
  for (i = 0; i < loop_ub; i++) {
    c_obj.b[i] = q.b[static_cast<int>(hspp_breaks[i]) - 1];
  }
  c_obj.c.set_size(1, hspp_breaks.size(1));
  loop_ub = hspp_breaks.size(1);
  for (i = 0; i < loop_ub; i++) {
    c_obj.c[i] = q.c[static_cast<int>(hspp_breaks[i]) - 1];
  }
  c_obj.d.set_size(1, hspp_breaks.size(1));
  loop_ub = hspp_breaks.size(1);
  for (i = 0; i < loop_ub; i++) {
    c_obj.d[i] = q.d[static_cast<int>(hspp_breaks[i]) - 1];
  }
  fusion::scenario::internal::getang(&b_obj, &c_obj, ac2, waypoints);
  fusion::scenario::internal::rates(static_cast<double>(m), ab2, ac2, waypoints,
                                    w);
  obj->SegmentTimes.set_size(ab2.size(0));
  loop_ub = ab2.size(0);
  for (i = 0; i < loop_ub; i++) {
    obj->SegmentTimes[i] = ab2[i];
  }
  obj->RadianSlewAngles.set_size(ac2.size(0));
  loop_ub = ac2.size(0);
  for (i = 0; i < loop_ub; i++) {
    obj->RadianSlewAngles[i] = ac2[i];
  }
  obj->AxesOfRotation.set_size(waypoints.size(0), 3);
  loop_ub = waypoints.size(0) * 3;
  for (i = 0; i < loop_ub; i++) {
    obj->AxesOfRotation[i] = waypoints[i];
  }
  obj->RadianAngularVelocities.set_size(w.size(0), 3);
  loop_ub = w.size(0) * 3;
  for (i = 0; i < loop_ub; i++) {
    obj->RadianAngularVelocities[i] = w[i];
  }
  obj->setupWaypointParams();
  obj->CurrentTime = 0.0;
  obj->setPose();
  obj->IsDoneStatus = false;
  return obj;
}

//
// Arguments    : double varargout_1[3]
//                b_quaternion *varargout_2
//                double varargout_3[3]
//                double varargout_4[3]
//                double varargout_5[3]
// Return Type  : void
//
void waypointTrajectory::step(double varargout_1[3], b_quaternion *varargout_2,
                              double varargout_3[3], double varargout_4[3],
                              double varargout_5[3])
{
  quaternion b_q;
  quaternion q;
  array<creal_T, 1U> ah;
  array<creal_T, 1U> hip;
  array<double, 3U> m;
  array<double, 2U> acceleration;
  array<double, 2U> r;
  array<double, 2U> velocity;
  array<double, 1U> course;
  array<double, 1U> hcd;
  array<double, 1U> k0;
  array<double, 1U> k1;
  array<double, 1U> l_1;
  array<double, 1U> l_2;
  double A[9];
  double B[9];
  double C[6];
  double D[3];
  double b_obj[3];
  double c_obj[3];
  double obj[3];
  double dt;
  double t;
  if (isInitialized != 1) {
    isInitialized = 1;
    CurrentTime = 0.0;
    setPose();
    IsDoneStatus = false;
    CurrentTime = 0.0;
    setPose();
    IsDoneStatus = false;
  }
  t = CurrentTime;
  dt = 1.0 / SampleRate;
  if (isInitialized != 1) {
    isInitialized = 1;
    CurrentTime = 0.0;
    setPose();
    IsDoneStatus = false;
    CurrentTime = 0.0;
    setPose();
    IsDoneStatus = false;
  }
  if (!IsDoneStatus) {
    t += dt;
    if ((TimeOfArrival[0] <= t) &&
        (t <= TimeOfArrival[TimeOfArrival.size(0) - 1])) {
      creal_T dc;
      double dkappa;
      double dkappa_tmp;
      double f_1_im;
      double f_1_re;
      double f_1_re_tmp;
      double f_1_re_tmp_tmp;
      double f_2_re;
      double idx;
      double l;
      double xloc;
      double y_im;
      double y_re;
      int boffset;
      int i;
      int ip;
      hcd.set_size(HorizontalCumulativeDistance.size(0));
      ip = HorizontalCumulativeDistance.size(0);
      for (i = 0; i < ip; i++) {
        hcd[i] = HorizontalCumulativeDistance[i];
      }
      k0.set_size(HorizontalCurvatureInitial.size(0));
      ip = HorizontalCurvatureInitial.size(0);
      for (i = 0; i < ip; i++) {
        k0[i] = HorizontalCurvatureInitial[i];
      }
      k1.set_size(HorizontalCurvatureFinal.size(0));
      ip = HorizontalCurvatureFinal.size(0);
      for (i = 0; i < ip; i++) {
        k1[i] = HorizontalCurvatureFinal[i];
      }
      hip.set_size(HorizontalInitialPosition.size(0));
      ip = HorizontalInitialPosition.size(0);
      for (i = 0; i < ip; i++) {
        hip[i] = HorizontalInitialPosition[i];
      }
      course.set_size(Course.size(0));
      ip = Course.size(0);
      for (i = 0; i < ip; i++) {
        course[i] = 0.017453292519943295 * Course[i];
      }
      ip =
          internal::b_bsearch(HorizontalDistancePiecewisePolynomial.breaks, t) -
          1;
      xloc = t - HorizontalDistancePiecewisePolynomial.breaks[ip];
      xloc =
          xloc *
              (xloc * (xloc * HorizontalDistancePiecewisePolynomial.coefs[ip] +
                       HorizontalDistancePiecewisePolynomial
                           .coefs[(ip + HorizontalDistancePiecewisePolynomial
                                            .breaks.size(1)) -
                                  1]) +
               HorizontalDistancePiecewisePolynomial
                   .coefs[ip + 2 * (HorizontalDistancePiecewisePolynomial.breaks
                                        .size(1) -
                                    1)]) +
          HorizontalDistancePiecewisePolynomial
              .coefs[ip +
                     3 * (HorizontalDistancePiecewisePolynomial.breaks.size(1) -
                          1)];
      ppval(HorizontalSpeedPiecewisePolynomial.breaks,
            HorizontalSpeedPiecewisePolynomial.coefs, t, l_1);
      ppval(HorizontalAccelerationPiecewisePolynomial.breaks,
            HorizontalAccelerationPiecewisePolynomial.coefs, t, l_2);
      ip = 0;
      if (xloc > hcd[hcd.size(0) - 1]) {
        ip = 1;
      }
      for (i = 0; i < ip; i++) {
        xloc = hcd[hcd.size(0) - 1];
      }
      ip = 0;
      if (xloc < hcd[0]) {
        ip = 1;
      }
      for (i = 0; i < ip; i++) {
        xloc = hcd[0];
      }
      idx = mapElementsToBins(xloc, hcd);
      dkappa_tmp = k0[static_cast<int>(idx) - 1];
      dkappa = (k1[static_cast<int>(idx) - 1] - dkappa_tmp) /
               HorizontalPiecewiseLength[static_cast<int>(idx) - 1];
      ip = 0;
      if (std::isnan(dkappa)) {
        ip = 1;
      }
      for (i = 0; i < ip; i++) {
        dkappa = 0.0;
      }
      l = xloc - hcd[static_cast<int>(idx) - 1];
      f_1_re_tmp_tmp = course[static_cast<int>(idx) - 1];
      xloc = (dkappa / 2.0 * l + dkappa_tmp) * l + f_1_re_tmp_tmp;
      f_1_re_tmp = xloc * 0.0;
      if (xloc == 0.0) {
        f_1_re = std::exp(f_1_re_tmp);
        f_1_im = 0.0;
        y_re = f_1_re;
        y_im = 0.0;
      } else {
        f_2_re = std::exp(f_1_re_tmp / 2.0);
        f_1_re_tmp = std::cos(xloc);
        f_1_re = f_2_re * (f_2_re * f_1_re_tmp);
        xloc = std::sin(xloc);
        f_1_im = f_2_re * (f_2_re * xloc);
        y_re = f_2_re * (f_2_re * f_1_re_tmp);
        y_im = f_2_re * (f_2_re * xloc);
      }
      xloc = dkappa * 0.0 * l + 0.0 * dkappa_tmp;
      f_1_re_tmp = dkappa * l + dkappa_tmp;
      f_2_re = y_re * xloc - y_im * f_1_re_tmp;
      xloc = y_re * f_1_re_tmp + y_im * xloc;
      dc = matlabshared::tracking::internal::scenario::fresnelg2(
          l, dkappa, dkappa_tmp, f_1_re_tmp_tmp);
      y_re = hip[static_cast<int>(idx) - 1].re + dc.re;
      y_im = hip[static_cast<int>(idx) - 1].im + dc.im;
      hip.set_size(l_1.size(0));
      ip = l_1.size(0);
      for (i = 0; i < ip; i++) {
        hip[i].re = l_1[i] * f_1_re;
        hip[i].im = l_1[i] * f_1_im;
      }
      hcd.set_size(l_1.size(0));
      ip = l_1.size(0);
      for (boffset = 0; boffset < ip; boffset++) {
        hcd[boffset] = l_1[boffset] * l_1[boffset];
      }
      ah.set_size(l_2.size(0));
      ip = l_2.size(0);
      for (i = 0; i < ip; i++) {
        ah[i].re = f_1_re * l_2[i] + f_2_re * hcd[i];
        ah[i].im = f_1_im * l_2[i] + xloc * hcd[i];
      }
      ip = internal::b_bsearch(VerticalDistancePiecewisePolynomial.breaks, t) -
           1;
      xloc = t - VerticalDistancePiecewisePolynomial.breaks[ip];
      ppval(VerticalSpeedPiecewisePolynomial.breaks,
            VerticalSpeedPiecewisePolynomial.coefs, t, hcd);
      ppval(VerticalAccelerationPiecewisePolynomial.breaks,
            VerticalAccelerationPiecewisePolynomial.coefs, t, k0);
      varargout_1[0] = y_re;
      varargout_1[1] = y_im;
      varargout_1[2] =
          xloc * (xloc * (xloc * VerticalDistancePiecewisePolynomial.coefs[ip] +
                          VerticalDistancePiecewisePolynomial
                              .coefs[(ip + VerticalDistancePiecewisePolynomial
                                               .breaks.size(1)) -
                                     1]) +
                  VerticalDistancePiecewisePolynomial
                      .coefs[ip + 2 * (VerticalDistancePiecewisePolynomial
                                           .breaks.size(1) -
                                       1)]) +
          VerticalDistancePiecewisePolynomial
              .coefs[ip +
                     3 * (VerticalDistancePiecewisePolynomial.breaks.size(1) -
                          1)];
      velocity.set_size(hip.size(0), 3);
      ip = hip.size(0);
      for (i = 0; i < ip; i++) {
        velocity[i] = hip[i].re;
      }
      ip = hip.size(0);
      for (i = 0; i < ip; i++) {
        velocity[i + velocity.size(0)] = hip[i].im;
      }
      ip = hcd.size(0);
      for (i = 0; i < ip; i++) {
        velocity[i + velocity.size(0) * 2] = hcd[i];
      }
      acceleration.set_size(ah.size(0), 3);
      ip = ah.size(0);
      for (i = 0; i < ip; i++) {
        acceleration[i] = ah[i].re;
      }
      ip = ah.size(0);
      for (i = 0; i < ip; i++) {
        acceleration[i + acceleration.size(0)] = ah[i].im;
      }
      ip = k0.size(0);
      for (i = 0; i < ip; i++) {
        acceleration[i + acceleration.size(0) * 2] = k0[i];
      }
      hcd.set_size(SegmentTimes.size(0));
      ip = SegmentTimes.size(0);
      for (i = 0; i < ip; i++) {
        hcd[i] = SegmentTimes[i];
      }
      k0.set_size(RadianSlewAngles.size(0));
      ip = RadianSlewAngles.size(0);
      for (i = 0; i < ip; i++) {
        k0[i] = RadianSlewAngles[i];
      }
      k1.set_size(TimeOfArrival.size(0));
      ip = TimeOfArrival.size(0);
      for (i = 0; i < ip; i++) {
        k1[i] = TimeOfArrival[i];
      }
      xloc = mapElementsToBins(t, k1);
      obj[0] = AxesOfRotation[static_cast<int>(xloc) - 1];
      b_obj[0] = RadianAngularVelocities[static_cast<int>(xloc) - 1];
      c_obj[0] = RadianAngularVelocities[static_cast<int>(
          static_cast<unsigned int>(xloc))];
      obj[1] =
          AxesOfRotation[(static_cast<int>(xloc) + AxesOfRotation.size(0)) - 1];
      b_obj[1] = RadianAngularVelocities[(static_cast<int>(xloc) +
                                          RadianAngularVelocities.size(0)) -
                                         1];
      c_obj[1] = RadianAngularVelocities[static_cast<int>(
                                             static_cast<unsigned int>(xloc)) +
                                         RadianAngularVelocities.size(0)];
      obj[2] =
          AxesOfRotation[(static_cast<int>(xloc) + AxesOfRotation.size(0) * 2) -
                         1];
      b_obj[2] = RadianAngularVelocities[(static_cast<int>(xloc) +
                                          RadianAngularVelocities.size(0) * 2) -
                                         1];
      c_obj[2] = RadianAngularVelocities[static_cast<int>(
                                             static_cast<unsigned int>(xloc)) +
                                         RadianAngularVelocities.size(0) * 2];
      fusion::scenario::internal::slew3_init(hcd[static_cast<int>(xloc) - 1],
                                             k0[static_cast<int>(xloc) - 1],
                                             obj, b_obj, c_obj, A, B, C, D);
      ip = Quaternions.a.size(1);
      q.a.set_size(1, ip);
      for (i = 0; i < ip; i++) {
        q.a[i] =
            Quaternions
                .a[(static_cast<int>(xloc) + Quaternions.a.size(0) * i) - 1];
      }
      ip = Quaternions.b.size(1);
      q.b.set_size(1, ip);
      for (i = 0; i < ip; i++) {
        q.b[i] =
            Quaternions
                .b[(static_cast<int>(xloc) + Quaternions.b.size(0) * i) - 1];
      }
      ip = Quaternions.c.size(1);
      q.c.set_size(1, ip);
      for (i = 0; i < ip; i++) {
        q.c[i] =
            Quaternions
                .c[(static_cast<int>(xloc) + Quaternions.c.size(0) * i) - 1];
      }
      ip = Quaternions.d.size(1);
      q.d.set_size(1, ip);
      for (i = 0; i < ip; i++) {
        q.d[i] =
            Quaternions
                .d[(static_cast<int>(xloc) + Quaternions.d.size(0) * i) - 1];
      }
      b_q = q;
      fusion::scenario::internal::slew3(t - k1[static_cast<int>(xloc) - 1],
                                        hcd[static_cast<int>(xloc) - 1], &b_q,
                                        A, B, C, D, &q, c_obj, obj, b_obj);
      b_q = q;
      b_q.rotmat(m);
      varargout_5[0] = c_obj[0];
      varargout_5[1] = c_obj[1];
      varargout_5[2] = c_obj[2];
      i = q.a.size(1);
      for (int b_i{0}; b_i < i; b_i++) {
        ip = m.size(1) - 1;
        r.set_size(1, m.size(1));
        for (int j{0}; j <= ip; j++) {
          boffset = j * m.size(0);
          r[j] =
              (c_obj[0] *
                   m[(boffset % m.size(0) +
                      m.size(0) * div_nzp_s32_floor(boffset, m.size(0))) +
                     m.size(0) * m.size(1) * b_i] +
               c_obj[1] *
                   m[((boffset + 1) % m.size(0) +
                      m.size(0) * div_nzp_s32_floor(boffset + 1, m.size(0))) +
                     m.size(0) * m.size(1) * b_i]) +
              c_obj[2] *
                  m[((boffset + 2) % m.size(0) +
                     m.size(0) * div_nzp_s32_floor(boffset + 2, m.size(0))) +
                    m.size(0) * m.size(1) * b_i];
        }
        varargout_5[0] = r[0];
        varargout_5[1] = r[1];
        varargout_5[2] = r[2];
      }
    } else {
      q.a.set_size(1, 1);
      q.a[0] = rtNaN;
      q.b.set_size(1, 1);
      q.b[0] = rtNaN;
      q.c.set_size(1, 1);
      q.c[0] = rtNaN;
      q.d.set_size(1, 1);
      q.d[0] = rtNaN;
      velocity.set_size(1, 3);
      acceleration.set_size(1, 3);
      varargout_1[0] = rtNaN;
      velocity[0] = rtNaN;
      varargout_5[0] = rtNaN;
      acceleration[0] = rtNaN;
      varargout_1[1] = rtNaN;
      velocity[1] = rtNaN;
      varargout_5[1] = rtNaN;
      acceleration[1] = rtNaN;
      varargout_1[2] = rtNaN;
      velocity[2] = rtNaN;
      varargout_5[2] = rtNaN;
      acceleration[2] = rtNaN;
      if (t > TimeOfArrival[TimeOfArrival.size(0) - 1]) {
        IsDoneStatus = true;
      }
    }
    varargout_2->a = q.a[0];
    varargout_2->b = q.b[0];
    varargout_2->c = q.c[0];
    varargout_2->d = q.d[0];
    varargout_3[0] = velocity[0];
    varargout_4[0] = acceleration[0];
    varargout_3[1] = velocity[1];
    varargout_4[1] = acceleration[1];
    varargout_3[2] = velocity[2];
    varargout_4[2] = acceleration[2];
    if (isInitialized != 1) {
      isInitialized = 1;
      CurrentTime = 0.0;
      setPose();
      IsDoneStatus = false;
      CurrentTime = 0.0;
      setPose();
      IsDoneStatus = false;
    }
    if (!IsDoneStatus) {
      CurrentTime = t;
      if (t + dt > PathDuration) {
        IsDoneStatus = true;
      }
    }
  } else {
    varargout_2->a = rtNaN;
    varargout_2->b = rtNaN;
    varargout_2->c = rtNaN;
    varargout_2->d = rtNaN;
    varargout_1[0] = rtNaN;
    varargout_3[0] = rtNaN;
    varargout_5[0] = rtNaN;
    varargout_4[0] = rtNaN;
    varargout_1[1] = rtNaN;
    varargout_3[1] = rtNaN;
    varargout_5[1] = rtNaN;
    varargout_4[1] = rtNaN;
    varargout_1[2] = rtNaN;
    varargout_3[2] = rtNaN;
    varargout_5[2] = rtNaN;
    varargout_4[2] = rtNaN;
  }
}

} // namespace coder

//
// File trailer for waypointTrajectory.cpp
//
// [EOF]
//
