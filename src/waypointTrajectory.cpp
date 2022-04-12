//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: waypointTrajectory.cpp
//
// MATLAB Coder version            : 5.4
// C/C++ source code generated on  : 12-Apr-2022 11:44:16
//

// Include Files
#include "waypointTrajectory.h"
#include "bsearch.h"
#include "clothoidG1fit2wp.h"
#include "derivpp.h"
#include "discretize.h"
#include "find.h"
#include "fresnelg2.h"
#include "getOrientationState.h"
#include "getPositionalState.h"
#include "pchip.h"
#include "ppval.h"
#include "quaternion.h"
#include "quaternionC2fit.h"
#include "rt_nonfinite.h"
#include "solveMissingCourse.h"
#include "coder_array.h"
#include <cfloat>
#include <cmath>
#include <string.h>

// Function Declarations
static void binary_expand_op(coder::array<double, 2U> &in1,
                             const coder::array<double, 1U> &in2,
                             const coder::array<double, 2U> &in3);

static void binary_expand_op(coder::array<double, 2U> &in1,
                             const coder::array<double, 1U> &in2);

static int div_nzp_s32_floor(int numerator, int denominator);

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
       (!(TimeOfArrival[TimeOfArrival.size(0) - 1] >= 0.0))) &&
      (TimeOfArrival[TimeOfArrival.size(0) - 1] < 0.0)) {
    IsDoneStatus = true;
  }
}

//
// Arguments    : void
// Return Type  : void
//
void waypointTrajectory::setupWaypointParams()
{
  array<double, 2U> b_course;
  array<double, 2U> gndspeed;
  array<double, 2U> rate;
  array<double, 2U> varargin_1;
  array<double, 1U> course;
  array<double, 1U> r;
  double absx;
  double x;
  int b_input_sizes_idx_1;
  int input_sizes_idx_1;
  int nx;
  int sizes_idx_1;
  signed char n;
  bool empty_non_axis_sizes;
  course.set_size(Course.size(0));
  nx = Course.size(0);
  for (int i{0}; i < nx; i++) {
    course[i] = Course[i];
  }
  ppval(HorizontalSpeedPiecewisePolynomial.breaks,
        HorizontalSpeedPiecewisePolynomial.coefs, TimeOfArrival, gndspeed);
  ppval(VerticalSpeedPiecewisePolynomial.breaks,
        VerticalSpeedPiecewisePolynomial.coefs, TimeOfArrival, rate);
  r.set_size(Course.size(0));
  nx = Course.size(0);
  for (int i{0}; i < nx; i++) {
    r[i] = Course[i];
  }
  nx = Course.size(0);
  for (input_sizes_idx_1 = 0; input_sizes_idx_1 < nx; input_sizes_idx_1++) {
    if (std::isinf(r[input_sizes_idx_1]) || std::isnan(r[input_sizes_idx_1])) {
      r[input_sizes_idx_1] = rtNaN;
    } else {
      x = rt_remd_snf(r[input_sizes_idx_1], 360.0);
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
        n = 0;
      } else if (absx <= 135.0) {
        if (x > 0.0) {
          x = 0.017453292519943295 * (x - 90.0);
          n = 1;
        } else {
          x = 0.017453292519943295 * (x + 90.0);
          n = -1;
        }
      } else if (x > 0.0) {
        x = 0.017453292519943295 * (x - 180.0);
        n = 2;
      } else {
        x = 0.017453292519943295 * (x + 180.0);
        n = -2;
      }
      if (n == 0) {
        r[input_sizes_idx_1] = std::cos(x);
      } else if (n == 1) {
        r[input_sizes_idx_1] = -std::sin(x);
      } else if (n == -1) {
        r[input_sizes_idx_1] = std::sin(x);
      } else {
        r[input_sizes_idx_1] = -std::cos(x);
      }
    }
  }
  nx = Course.size(0);
  for (input_sizes_idx_1 = 0; input_sizes_idx_1 < nx; input_sizes_idx_1++) {
    if (std::isinf(course[input_sizes_idx_1]) ||
        std::isnan(course[input_sizes_idx_1])) {
      course[input_sizes_idx_1] = rtNaN;
    } else {
      x = rt_remd_snf(course[input_sizes_idx_1], 360.0);
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
        n = 0;
      } else if (absx <= 135.0) {
        if (x > 0.0) {
          x = 0.017453292519943295 * (x - 90.0);
          n = 1;
        } else {
          x = 0.017453292519943295 * (x + 90.0);
          n = -1;
        }
      } else if (x > 0.0) {
        x = 0.017453292519943295 * (x - 180.0);
        n = 2;
      } else {
        x = 0.017453292519943295 * (x + 180.0);
        n = -2;
      }
      if (n == 0) {
        course[input_sizes_idx_1] = std::sin(x);
      } else if (n == 1) {
        course[input_sizes_idx_1] = std::cos(x);
      } else if (n == -1) {
        course[input_sizes_idx_1] = -std::cos(x);
      } else {
        course[input_sizes_idx_1] = -std::sin(x);
      }
    }
  }
  if (r.size(0) == gndspeed.size(0)) {
    varargin_1.set_size(r.size(0), gndspeed.size(1));
    nx = gndspeed.size(1);
    for (int i{0}; i < nx; i++) {
      input_sizes_idx_1 = r.size(0);
      for (int i1{0}; i1 < input_sizes_idx_1; i1++) {
        varargin_1[i1 + varargin_1.size(0) * i] =
            r[i1] * gndspeed[i1 + gndspeed.size(0) * i];
      }
    }
  } else {
    binary_expand_op(varargin_1, r, gndspeed);
  }
  if (course.size(0) == gndspeed.size(0)) {
    b_course.set_size(course.size(0), gndspeed.size(1));
    nx = gndspeed.size(1);
    for (int i{0}; i < nx; i++) {
      input_sizes_idx_1 = course.size(0);
      for (int i1{0}; i1 < input_sizes_idx_1; i1++) {
        b_course[i1 + b_course.size(0) * i] =
            course[i1] * gndspeed[i1 + gndspeed.size(0) * i];
      }
    }
    gndspeed.set_size(b_course.size(0), b_course.size(1));
    nx = b_course.size(0) * b_course.size(1);
    for (int i{0}; i < nx; i++) {
      gndspeed[i] = b_course[i];
    }
  } else {
    binary_expand_op(gndspeed, course);
  }
  if ((varargin_1.size(0) != 0) && (varargin_1.size(1) != 0)) {
    nx = varargin_1.size(0);
  } else if ((gndspeed.size(0) != 0) && (gndspeed.size(1) != 0)) {
    nx = gndspeed.size(0);
  } else if ((rate.size(0) != 0) && (rate.size(1) != 0)) {
    nx = rate.size(0);
  } else {
    nx = varargin_1.size(0);
    if (gndspeed.size(0) > varargin_1.size(0)) {
      nx = gndspeed.size(0);
    }
    if (rate.size(0) > nx) {
      nx = rate.size(0);
    }
  }
  empty_non_axis_sizes = (nx == 0);
  if (empty_non_axis_sizes ||
      ((varargin_1.size(0) != 0) && (varargin_1.size(1) != 0))) {
    input_sizes_idx_1 = varargin_1.size(1);
  } else {
    input_sizes_idx_1 = 0;
  }
  if (empty_non_axis_sizes ||
      ((gndspeed.size(0) != 0) && (gndspeed.size(1) != 0))) {
    b_input_sizes_idx_1 = gndspeed.size(1);
  } else {
    b_input_sizes_idx_1 = 0;
  }
  if (empty_non_axis_sizes || ((rate.size(0) != 0) && (rate.size(1) != 0))) {
    sizes_idx_1 = rate.size(1);
  } else {
    sizes_idx_1 = 0;
  }
  Velocities.set_size(nx,
                      (input_sizes_idx_1 + b_input_sizes_idx_1) + sizes_idx_1);
  for (int i{0}; i < input_sizes_idx_1; i++) {
    for (int i1{0}; i1 < nx; i1++) {
      Velocities[i1 + Velocities.size(0) * i] = varargin_1[i1 + nx * i];
    }
  }
  for (int i{0}; i < b_input_sizes_idx_1; i++) {
    for (int i1{0}; i1 < nx; i1++) {
      Velocities[i1 + Velocities.size(0) * (i + input_sizes_idx_1)] =
          gndspeed[i1 + nx * i];
    }
  }
  for (int i{0}; i < sizes_idx_1; i++) {
    for (int i1{0}; i1 < nx; i1++) {
      Velocities[i1 + Velocities.size(0) *
                          ((i + input_sizes_idx_1) + b_input_sizes_idx_1)] =
          rate[i1 + nx * i];
    }
  }
}

//
// Arguments    : coder::array<double, 2U> &in1
//                const coder::array<double, 1U> &in2
//                const coder::array<double, 2U> &in3
// Return Type  : void
//
} // namespace coder
static void binary_expand_op(coder::array<double, 2U> &in1,
                             const coder::array<double, 1U> &in2,
                             const coder::array<double, 2U> &in3)
{
  int i;
  int in2_idx_0;
  int loop_ub;
  int stride_0_0;
  int stride_1_0;
  in2_idx_0 = in2.size(0);
  if (in3.size(0) == 1) {
    i = in2_idx_0;
  } else {
    i = in3.size(0);
  }
  in1.set_size(i, in3.size(1));
  stride_0_0 = (in2_idx_0 != 1);
  stride_1_0 = (in3.size(0) != 1);
  loop_ub = in3.size(1);
  for (i = 0; i < loop_ub; i++) {
    int b_loop_ub;
    if (in3.size(0) == 1) {
      b_loop_ub = in2_idx_0;
    } else {
      b_loop_ub = in3.size(0);
    }
    for (int i1{0}; i1 < b_loop_ub; i1++) {
      in1[i1 + in1.size(0) * i] =
          in2[i1 * stride_0_0] * in3[i1 * stride_1_0 + in3.size(0) * i];
    }
  }
}

//
// Arguments    : coder::array<double, 2U> &in1
//                const coder::array<double, 1U> &in2
// Return Type  : void
//
static void binary_expand_op(coder::array<double, 2U> &in1,
                             const coder::array<double, 1U> &in2)
{
  coder::array<double, 2U> b_in2;
  int b_loop_ub;
  int i;
  int in2_idx_0;
  int loop_ub;
  int stride_0_0;
  int stride_1_0;
  in2_idx_0 = in2.size(0);
  if (in1.size(0) == 1) {
    i = in2_idx_0;
  } else {
    i = in1.size(0);
  }
  b_in2.set_size(i, in1.size(1));
  stride_0_0 = (in2_idx_0 != 1);
  stride_1_0 = (in1.size(0) != 1);
  loop_ub = in1.size(1);
  for (i = 0; i < loop_ub; i++) {
    if (in1.size(0) == 1) {
      b_loop_ub = in2_idx_0;
    } else {
      b_loop_ub = in1.size(0);
    }
    for (int i1{0}; i1 < b_loop_ub; i1++) {
      b_in2[i1 + b_in2.size(0) * i] =
          in2[i1 * stride_0_0] * in1[i1 * stride_1_0 + in1.size(0) * i];
    }
  }
  in1.set_size(b_in2.size(0), b_in2.size(1));
  loop_ub = b_in2.size(1);
  for (i = 0; i < loop_ub; i++) {
    b_loop_ub = b_in2.size(0);
    for (int i1{0}; i1 < b_loop_ub; i1++) {
      in1[i1 + in1.size(0) * i] = b_in2[i1 + b_in2.size(0) * i];
    }
  }
}

//
// Arguments    : int numerator
//                int denominator
// Return Type  : int
//
static int div_nzp_s32_floor(int numerator, int denominator)
{
  unsigned int absDenominator;
  unsigned int absNumerator;
  int quotient;
  unsigned int tempAbsQuotient;
  bool quotientNeedsNegation;
  if (numerator < 0) {
    absNumerator = ~static_cast<unsigned int>(numerator) + 1U;
  } else {
    absNumerator = static_cast<unsigned int>(numerator);
  }
  if (denominator < 0) {
    absDenominator = ~static_cast<unsigned int>(denominator) + 1U;
  } else {
    absDenominator = static_cast<unsigned int>(denominator);
  }
  quotientNeedsNegation = ((numerator < 0) != (denominator < 0));
  tempAbsQuotient = absNumerator / absDenominator;
  if (quotientNeedsNegation) {
    absNumerator %= absDenominator;
    if (absNumerator > 0U) {
      tempAbsQuotient++;
    }
    quotient = -static_cast<int>(tempAbsQuotient);
  } else {
    quotient = static_cast<int>(tempAbsQuotient);
  }
  return quotient;
}

//
// Arguments    : double u0
//                double u1
// Return Type  : double
//
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
//                double varargin_4
//                const quaternion *varargin_8
//                const ::coder::array<double, 2U> &varargin_10
// Return Type  : waypointTrajectory *
//
namespace coder {
waypointTrajectory *
waypointTrajectory::init(const ::coder::array<double, 2U> &varargin_1,
                         const ::coder::array<double, 1U> &varargin_2,
                         double varargin_4, const quaternion *varargin_8,
                         const ::coder::array<double, 2U> &varargin_10)
{
  quaternion c_obj;
  quaternion d_obj;
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
  array<double, 2U> b_obj;
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
  array<double, 1U> aasq;
  array<double, 1U> ab2;
  array<double, 1U> ac2;
  array<double, 1U> ad2;
  array<double, 1U> b_cd2;
  array<double, 1U> bc2;
  array<double, 1U> bd2;
  array<double, 1U> cd2;
  array<unsigned int, 2U> b_y;
  array<int, 2U> y;
  array<int, 1U> r;
  array<bool, 1U> tf;
  array<bool, 1U> x_tmp;
  int b_k;
  int dimSize;
  int i;
  int i1;
  int i2;
  int k;
  int loop_ub;
  int m;
  int n;
  obj = this;
  obj->AutoPitch = false;
  obj->AutoBank = false;
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
  obj->SampleRate = varargin_4;
  obj->Quaternions = *varargin_8;
  obj->Course.set_size(varargin_10.size(1));
  loop_ub = varargin_10.size(1);
  for (i = 0; i < loop_ub; i++) {
    obj->Course[i] = varargin_10[i];
  }
  aasq.set_size(obj->TimeOfArrival.size(0));
  loop_ub = obj->TimeOfArrival.size(0);
  for (i = 0; i < loop_ub; i++) {
    aasq[i] = obj->TimeOfArrival[i];
  }
  n = obj->TimeOfArrival.size(0);
  cd2.set_size(obj->Course.size(0));
  loop_ub = obj->Course.size(0);
  for (i = 0; i < loop_ub; i++) {
    cd2[i] = 0.017453292519943295 * obj->Course[i];
  }
  if (obj->Waypoints.size(0) - 1 < 1) {
    loop_ub = 0;
  } else {
    loop_ub = obj->Waypoints.size(0) - 1;
  }
  if (obj->Waypoints.size(0) < 2) {
    i = -1;
    i1 = -1;
  } else {
    i = 0;
    i1 = obj->Waypoints.size(0) - 1;
  }
  if (obj->Waypoints.size(0) - 1 < 1) {
    k = 0;
  } else {
    k = obj->Waypoints.size(0) - 1;
  }
  if (obj->Waypoints.size(0) < 2) {
    dimSize = -1;
    i2 = -1;
  } else {
    dimSize = 0;
    i2 = obj->Waypoints.size(0) - 1;
  }
  if (loop_ub == 1) {
    m = i1 - i;
  } else {
    m = loop_ub;
  }
  if (k == 1) {
    b_k = i2 - dimSize;
  } else {
    b_k = k;
  }
  if ((loop_ub == i1 - i) && (k == i2 - dimSize) && (m == b_k)) {
    tf.set_size(loop_ub);
    for (i1 = 0; i1 < loop_ub; i1++) {
      tf[i1] =
          ((obj->Waypoints[i1] == obj->Waypoints[(i + i1) + 1]) &&
           (obj->Waypoints[i1 + obj->Waypoints.size(0)] ==
            obj->Waypoints[((dimSize + i1) + obj->Waypoints.size(0)) + 1]));
    }
  } else {
    b_binary_expand_op(tf, obj, loop_ub - 1, i + 1, i1, k - 1, dimSize + 1, i2);
  }
  x_tmp.set_size(tf.size(0));
  loop_ub = tf.size(0);
  for (i = 0; i < loop_ub; i++) {
    x_tmp[i] = !tf[i];
  }
  eml_find(x_tmp, r);
  ab2.set_size(r.size(0) + 1);
  ab2[0] = 1.0;
  loop_ub = r.size(0);
  for (i = 0; i < loop_ub; i++) {
    ab2[i + 1] = static_cast<double>(r[i]) + 1.0;
  }
  ad2.set_size(ab2.size(0));
  loop_ub = ab2.size(0);
  for (i = 0; i < loop_ub; i++) {
    ad2[i] = cd2[static_cast<int>(ab2[i]) - 1];
  }
  b_obj.set_size(ab2.size(0), 3);
  loop_ub = ab2.size(0);
  for (i = 0; i < 3; i++) {
    for (i1 = 0; i1 < loop_ub; i1++) {
      b_obj[i1 + b_obj.size(0) * i] =
          obj->Waypoints[(static_cast<int>(ab2[i1]) +
                          obj->Waypoints.size(0) * i) -
                         1];
    }
  }
  matlabshared::tracking::internal::scenario::clothoidG2FitMissingCourse(b_obj,
                                                                         ad2);
  loop_ub = ad2.size(0);
  for (i = 0; i < loop_ub; i++) {
    cd2[static_cast<int>(ab2[i]) - 1] = ad2[i];
  }
  eml_find(tf, r);
  ab2.set_size(r.size(0));
  loop_ub = r.size(0);
  for (i = 0; i < loop_ub; i++) {
    ab2[i] = r[i];
  }
  ac2.set_size(x_tmp.size(0));
  loop_ub = x_tmp.size(0);
  for (i = 0; i < loop_ub; i++) {
    ac2[i] = x_tmp[i];
  }
  if ((ac2.size(0) != 1) && (ac2.size(0) != 0) && (ac2.size(0) != 1)) {
    i = ac2.size(0);
    for (k = 0; k <= i - 2; k++) {
      ac2[k + 1] = ac2[k] + ac2[k + 1];
    }
  }
  loop_ub = ac2.size(0);
  for (i = 0; i < loop_ub; i++) {
    ac2[i] = ac2[i] + 1.0;
  }
  loop_ub = ab2.size(0);
  for (i = 0; i < loop_ub; i++) {
    k = static_cast<int>(ab2[i]);
    cd2[k] = ad2[static_cast<int>(ac2[k - 1]) - 1];
  }
  loop_ub = obj->Waypoints.size(0);
  hip.set_size(loop_ub);
  for (i = 0; i < loop_ub; i++) {
    hip[i].re = obj->Waypoints[i];
    hip[i].im = obj->Waypoints[i + obj->Waypoints.size(0)];
  }
  if (obj->TimeOfArrival.size(0) - 1 < 1) {
    loop_ub = 0;
  } else {
    loop_ub = n - 1;
  }
  if (obj->TimeOfArrival.size(0) - 1 < 1) {
    m = 0;
  } else {
    m = n - 1;
  }
  if (n < 2) {
    i = 0;
    i1 = 0;
    k = 0;
    dimSize = 0;
  } else {
    i = 1;
    i1 = obj->TimeOfArrival.size(0);
    k = 1;
    dimSize = obj->TimeOfArrival.size(0);
  }
  b_hip.set_size(loop_ub);
  for (i2 = 0; i2 < loop_ub; i2++) {
    b_hip[i2] = hip[i2];
  }
  bc2.set_size(m);
  for (i2 = 0; i2 < m; i2++) {
    bc2[i2] = cd2[i2];
  }
  loop_ub = i1 - i;
  c_hip.set_size(loop_ub);
  for (i1 = 0; i1 < loop_ub; i1++) {
    c_hip[i1] = hip[i + i1];
  }
  loop_ub = dimSize - k;
  b_cd2.set_size(loop_ub);
  for (i = 0; i < loop_ub; i++) {
    b_cd2[i] = cd2[k + i];
  }
  matlabshared::tracking::internal::scenario::clothoidG1fit2wp(
      b_hip, bc2, c_hip, b_cd2, ab2, ac2, ad2);
  bc2.set_size(ad2.size(0));
  loop_ub = ad2.size(0);
  for (i = 0; i < loop_ub; i++) {
    bc2[i] = ad2[i];
  }
  if ((ad2.size(0) != 1) && (ad2.size(0) != 0) && (ad2.size(0) != 1)) {
    i = ad2.size(0);
    for (k = 0; k <= i - 2; k++) {
      bc2[k + 1] = bc2[k] + bc2[k + 1];
    }
  }
  bd2.set_size(bc2.size(0) + 1);
  bd2[0] = 0.0;
  loop_ub = bc2.size(0);
  for (i = 0; i < loop_ub; i++) {
    bd2[i + 1] = bc2[i];
  }
  pchip(obj->TimeOfArrival, bd2, hpp_breaks, hpp_coefs);
  matlabshared::tracking::internal::scenario::derivpp(hpp_breaks, hpp_coefs,
                                                      hspp_breaks, hspp_coefs);
  matlabshared::tracking::internal::scenario::derivpp(hspp_breaks, hspp_coefs,
                                                      happ_breaks, happ_coefs);
  matlabshared::tracking::internal::scenario::derivpp(happ_breaks, happ_coefs,
                                                      hjpp_breaks, hjpp_coefs);
  loop_ub = obj->Waypoints.size(0);
  b_cd2.set_size(loop_ub);
  for (i = 0; i < loop_ub; i++) {
    b_cd2[i] = obj->Waypoints[i + obj->Waypoints.size(0) * 2];
  }
  pchip(obj->TimeOfArrival, b_cd2, vpp_breaks, vpp_coefs);
  matlabshared::tracking::internal::scenario::derivpp(vpp_breaks, vpp_coefs,
                                                      vspp_breaks, vspp_coefs);
  matlabshared::tracking::internal::scenario::derivpp(vspp_breaks, vspp_coefs,
                                                      vapp_breaks, vapp_coefs);
  matlabshared::tracking::internal::scenario::derivpp(vapp_breaks, vapp_coefs,
                                                      vjpp_breaks, vjpp_coefs);
  obj->HorizontalCumulativeDistance.set_size(bd2.size(0));
  loop_ub = bd2.size(0);
  for (i = 0; i < loop_ub; i++) {
    obj->HorizontalCumulativeDistance[i] = bd2[i];
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
  obj->HorizontalCurvatureFinal.set_size(ac2.size(0));
  loop_ub = ac2.size(0);
  for (i = 0; i < loop_ub; i++) {
    obj->HorizontalCurvatureFinal[i] = ac2[i];
  }
  obj->HorizontalInitialPosition.set_size(hip.size(0));
  loop_ub = hip.size(0);
  for (i = 0; i < loop_ub; i++) {
    obj->HorizontalInitialPosition[i] = hip[i];
  }
  obj->HorizontalPiecewiseLength.set_size(ad2.size(0));
  loop_ub = ad2.size(0);
  for (i = 0; i < loop_ub; i++) {
    obj->HorizontalPiecewiseLength[i] = ad2[i];
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
  obj->Course.set_size(cd2.size(0));
  loop_ub = cd2.size(0);
  for (i = 0; i < loop_ub; i++) {
    obj->Course[i] = 57.295779513082323 * cd2[i];
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
    ac2.set_size(0);
  } else {
    k = aasq.size(0) - 1;
    if (k > 1) {
      k = 1;
    }
    if (k < 1) {
      ac2.set_size(0);
    } else {
      ab2.set_size(1);
      ac2.set_size(aasq.size(0) - 1);
      if (aasq.size(0) - 1 != 0) {
        ab2[0] = aasq[0];
        for (k = 2; k <= dimSize; k++) {
          double ab2_tmp;
          double tmp2;
          tmp2 = ab2[0];
          ab2_tmp = aasq[k - 1];
          ab2[0] = ab2_tmp;
          ac2[k - 2] = ab2_tmp - tmp2;
        }
      }
    }
  }
  if (m - 1 < 1) {
    y.set_size(1, 0);
  } else {
    loop_ub = m - 2;
    y.set_size(1, m - 1);
    for (i = 0; i <= loop_ub; i++) {
      y[i] = i + 1;
    }
  }
  if (m < 2) {
    b_y.set_size(1, 0);
  } else {
    b_y.set_size(1, m - 1);
    loop_ub = m - 2;
    for (i = 0; i <= loop_ub; i++) {
      b_y[i] = i + 2U;
    }
  }
  c_obj.a.set_size(1, y.size(1));
  loop_ub = y.size(1);
  for (i = 0; i < loop_ub; i++) {
    c_obj.a[i] = q.a[y[i] - 1];
  }
  c_obj.b.set_size(1, y.size(1));
  loop_ub = y.size(1);
  for (i = 0; i < loop_ub; i++) {
    c_obj.b[i] = q.b[y[i] - 1];
  }
  c_obj.c.set_size(1, y.size(1));
  loop_ub = y.size(1);
  for (i = 0; i < loop_ub; i++) {
    c_obj.c[i] = q.c[y[i] - 1];
  }
  c_obj.d.set_size(1, y.size(1));
  loop_ub = y.size(1);
  for (i = 0; i < loop_ub; i++) {
    c_obj.d[i] = q.d[y[i] - 1];
  }
  d_obj.a.set_size(1, b_y.size(1));
  loop_ub = b_y.size(1);
  for (i = 0; i < loop_ub; i++) {
    d_obj.a[i] = q.a[static_cast<int>(b_y[i]) - 1];
  }
  d_obj.b.set_size(1, b_y.size(1));
  loop_ub = b_y.size(1);
  for (i = 0; i < loop_ub; i++) {
    d_obj.b[i] = q.b[static_cast<int>(b_y[i]) - 1];
  }
  d_obj.c.set_size(1, b_y.size(1));
  loop_ub = b_y.size(1);
  for (i = 0; i < loop_ub; i++) {
    d_obj.c[i] = q.c[static_cast<int>(b_y[i]) - 1];
  }
  d_obj.d.set_size(1, b_y.size(1));
  loop_ub = b_y.size(1);
  for (i = 0; i < loop_ub; i++) {
    d_obj.d[i] = q.d[static_cast<int>(b_y[i]) - 1];
  }
  fusion::scenario::internal::getang(&c_obj, &d_obj, ab2, b_obj);
  fusion::scenario::internal::rates(static_cast<double>(m), ac2, ab2, b_obj, w);
  obj->SegmentTimes.set_size(ac2.size(0));
  loop_ub = ac2.size(0);
  for (i = 0; i < loop_ub; i++) {
    obj->SegmentTimes[i] = ac2[i];
  }
  obj->RadianSlewAngles.set_size(ab2.size(0));
  loop_ub = ab2.size(0);
  for (i = 0; i < loop_ub; i++) {
    obj->RadianSlewAngles[i] = ab2[i];
  }
  obj->AxesOfRotation.set_size(b_obj.size(0), 3);
  loop_ub = b_obj.size(0) * 3;
  for (i = 0; i < loop_ub; i++) {
    obj->AxesOfRotation[i] = b_obj[i];
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
  quaternion b_orientation;
  quaternion orientation;
  array<creal_T, 1U> ah;
  array<creal_T, 1U> vh;
  array<double, 3U> m;
  array<double, 2U> acceleration;
  array<double, 2U> b_C;
  array<double, 2U> velocity;
  array<double, 1U> course;
  array<double, 1U> l_1;
  array<double, 1U> l_2;
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
      creal_T f_1;
      creal_T f_2;
      double A[9];
      double B[9];
      double C[6];
      double D[3];
      double b_obj[3];
      double c_obj[3];
      double obj[3];
      double b_f_1_tmp_tmp;
      double dkappa;
      double dkappa_tmp;
      double f_1_tmp_tmp;
      double idx;
      double l;
      double r;
      double xloc;
      double y_re;
      int boffset;
      int i;
      int ip;
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
               HorizontalDistancePiecewisePolynomial.coefs
                   [ip +
                    ((HorizontalDistancePiecewisePolynomial.breaks.size(1) - 1)
                     << 1)]) +
          HorizontalDistancePiecewisePolynomial
              .coefs[ip +
                     3 * (HorizontalDistancePiecewisePolynomial.breaks.size(1) -
                          1)];
      ppval(HorizontalSpeedPiecewisePolynomial.breaks,
            HorizontalSpeedPiecewisePolynomial.coefs, t, l_1);
      ppval(HorizontalAccelerationPiecewisePolynomial.breaks,
            HorizontalAccelerationPiecewisePolynomial.coefs, t, l_2);
      ip = 0;
      if (xloc >
          HorizontalCumulativeDistance[HorizontalCumulativeDistance.size(0) -
                                       1]) {
        ip = 1;
      }
      for (i = 0; i < ip; i++) {
        xloc =
            HorizontalCumulativeDistance[HorizontalCumulativeDistance.size(0) -
                                         1];
      }
      ip = 0;
      if (xloc < HorizontalCumulativeDistance[0]) {
        ip = 1;
      }
      for (i = 0; i < ip; i++) {
        xloc = HorizontalCumulativeDistance[0];
      }
      idx = mapElementsToBins(xloc, HorizontalCumulativeDistance);
      boffset = static_cast<int>(
                    mapElementsToBins(xloc, HorizontalCumulativeDistance)) -
                1;
      dkappa_tmp = HorizontalCurvatureInitial[static_cast<int>(idx) - 1];
      dkappa =
          (HorizontalCurvatureFinal[static_cast<int>(idx) - 1] - dkappa_tmp) /
          HorizontalPiecewiseLength[static_cast<int>(idx) - 1];
      ip = 0;
      if (std::isnan(dkappa)) {
        ip = 1;
      }
      for (i = 0; i < ip; i++) {
        dkappa = 0.0;
      }
      l = xloc - HorizontalCumulativeDistance[static_cast<int>(idx) - 1];
      f_1_tmp_tmp = course[static_cast<int>(idx) - 1];
      b_f_1_tmp_tmp = (dkappa / 2.0 * l + dkappa_tmp) * l;
      xloc = b_f_1_tmp_tmp + f_1_tmp_tmp;
      f_1.re = xloc * 0.0;
      if (xloc == 0.0) {
        xloc = f_1.re;
        f_1.re = std::exp(xloc);
        f_1.im = 0.0;
      } else {
        r = std::exp(f_1.re / 2.0);
        f_1.re = r * (r * std::cos(xloc));
        f_1.im = r * (r * std::sin(xloc));
      }
      y_re = (b_f_1_tmp_tmp + course[static_cast<int>(idx) - 1]) * 0.0;
      idx = b_f_1_tmp_tmp + course[static_cast<int>(idx) - 1];
      if (idx == 0.0) {
        y_re = std::exp(y_re);
        idx = 0.0;
      } else {
        r = std::exp(y_re / 2.0);
        y_re = r * (r * std::cos(idx));
        idx = r * (r * std::sin(idx));
      }
      xloc = dkappa * 0.0 * l + 0.0 * dkappa_tmp;
      b_f_1_tmp_tmp = dkappa * l + dkappa_tmp;
      f_2.re = y_re * xloc - idx * b_f_1_tmp_tmp;
      f_2.im = y_re * b_f_1_tmp_tmp + idx * xloc;
      dc = matlabshared::tracking::internal::scenario::fresnelg2(
          l, dkappa, dkappa_tmp, f_1_tmp_tmp);
      vh.set_size(l_1.size(0));
      ip = l_1.size(0);
      for (i = 0; i < ip; i++) {
        vh[i].re = l_1[i] * f_1.re;
        vh[i].im = l_1[i] * f_1.im;
      }
      course.set_size(l_1.size(0));
      ip = l_1.size(0);
      for (i = 0; i < ip; i++) {
        xloc = l_1[i];
        course[i] = xloc * xloc;
      }
      if (l_2.size(0) == course.size(0)) {
        ah.set_size(l_2.size(0));
        ip = l_2.size(0);
        for (i = 0; i < ip; i++) {
          ah[i].re = f_1.re * l_2[i] + f_2.re * course[i];
          ah[i].im = f_1.im * l_2[i] + f_2.im * course[i];
        }
      } else {
        binary_expand_op(ah, f_1, l_2, f_2, course);
      }
      ip = internal::b_bsearch(VerticalDistancePiecewisePolynomial.breaks, t) -
           1;
      xloc = t - VerticalDistancePiecewisePolynomial.breaks[ip];
      varargout_1[0] = HorizontalInitialPosition[boffset].re + dc.re;
      varargout_1[1] = HorizontalInitialPosition[boffset].im + dc.im;
      varargout_1[2] =
          xloc * (xloc * (xloc * VerticalDistancePiecewisePolynomial.coefs[ip] +
                          VerticalDistancePiecewisePolynomial
                              .coefs[(ip + VerticalDistancePiecewisePolynomial
                                               .breaks.size(1)) -
                                     1]) +
                  VerticalDistancePiecewisePolynomial.coefs
                      [ip +
                       ((VerticalDistancePiecewisePolynomial.breaks.size(1) - 1)
                        << 1)]) +
          VerticalDistancePiecewisePolynomial
              .coefs[ip +
                     3 * (VerticalDistancePiecewisePolynomial.breaks.size(1) -
                          1)];
      ppval(VerticalSpeedPiecewisePolynomial.breaks,
            VerticalSpeedPiecewisePolynomial.coefs, t, course);
      velocity.set_size(vh.size(0), 3);
      ip = vh.size(0);
      for (i = 0; i < ip; i++) {
        velocity[i] = vh[i].re;
      }
      ip = vh.size(0);
      for (i = 0; i < ip; i++) {
        velocity[i + velocity.size(0)] = vh[i].im;
      }
      ip = course.size(0);
      for (i = 0; i < ip; i++) {
        velocity[i + velocity.size(0) * 2] = course[i];
      }
      ppval(VerticalAccelerationPiecewisePolynomial.breaks,
            VerticalAccelerationPiecewisePolynomial.coefs, t, course);
      acceleration.set_size(ah.size(0), 3);
      ip = ah.size(0);
      for (i = 0; i < ip; i++) {
        acceleration[i] = ah[i].re;
      }
      ip = ah.size(0);
      for (i = 0; i < ip; i++) {
        acceleration[i + acceleration.size(0)] = ah[i].im;
      }
      ip = course.size(0);
      for (i = 0; i < ip; i++) {
        acceleration[i + acceleration.size(0) * 2] = course[i];
      }
      course.set_size(SegmentTimes.size(0));
      ip = SegmentTimes.size(0);
      for (i = 0; i < ip; i++) {
        course[i] = SegmentTimes[i];
      }
      l_1.set_size(RadianSlewAngles.size(0));
      ip = RadianSlewAngles.size(0);
      for (i = 0; i < ip; i++) {
        l_1[i] = RadianSlewAngles[i];
      }
      l_2.set_size(TimeOfArrival.size(0));
      ip = TimeOfArrival.size(0);
      for (i = 0; i < ip; i++) {
        l_2[i] = TimeOfArrival[i];
      }
      xloc = mapElementsToBins(t, l_2);
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
      fusion::scenario::internal::slew3_init(course[static_cast<int>(xloc) - 1],
                                             l_1[static_cast<int>(xloc) - 1],
                                             obj, b_obj, c_obj, A, B, C, D);
      ip = Quaternions.a.size(1);
      orientation.a.set_size(1, ip);
      for (i = 0; i < ip; i++) {
        orientation.a[i] =
            Quaternions
                .a[(static_cast<int>(xloc) + Quaternions.a.size(0) * i) - 1];
      }
      ip = Quaternions.b.size(1);
      orientation.b.set_size(1, ip);
      for (i = 0; i < ip; i++) {
        orientation.b[i] =
            Quaternions
                .b[(static_cast<int>(xloc) + Quaternions.b.size(0) * i) - 1];
      }
      ip = Quaternions.c.size(1);
      orientation.c.set_size(1, ip);
      for (i = 0; i < ip; i++) {
        orientation.c[i] =
            Quaternions
                .c[(static_cast<int>(xloc) + Quaternions.c.size(0) * i) - 1];
      }
      ip = Quaternions.d.size(1);
      orientation.d.set_size(1, ip);
      for (i = 0; i < ip; i++) {
        orientation.d[i] =
            Quaternions
                .d[(static_cast<int>(xloc) + Quaternions.d.size(0) * i) - 1];
      }
      b_orientation = orientation;
      fusion::scenario::internal::slew3(t - l_2[static_cast<int>(xloc) - 1],
                                        course[static_cast<int>(xloc) - 1],
                                        &b_orientation, A, B, C, D,
                                        &orientation, c_obj, obj, b_obj);
      b_orientation = orientation;
      b_orientation.rotmat(m);
      varargout_5[0] = c_obj[0];
      varargout_5[1] = c_obj[1];
      varargout_5[2] = c_obj[2];
      i = orientation.a.size(1);
      for (int b_i{0}; b_i < i; b_i++) {
        ip = m.size(1) - 1;
        b_C.set_size(1, m.size(1));
        for (int j{0}; j <= ip; j++) {
          boffset = j * m.size(0);
          b_C[j] =
              (c_obj[0] * m[boffset % m.size(0) +
                            m.size(0) * div_nzp_s32_floor(boffset, m.size(0))] +
               c_obj[1] *
                   m[(boffset + 1) % m.size(0) +
                     m.size(0) * div_nzp_s32_floor(boffset + 1, m.size(0))]) +
              c_obj[2] *
                  m[(boffset + 2) % m.size(0) +
                    m.size(0) * div_nzp_s32_floor(boffset + 2, m.size(0))];
        }
        varargout_5[0] = b_C[0];
        varargout_5[1] = b_C[1];
        varargout_5[2] = b_C[2];
      }
    } else {
      orientation.a.set_size(1, 1);
      orientation.a[0] = rtNaN;
      orientation.b.set_size(1, 1);
      orientation.b[0] = rtNaN;
      orientation.c.set_size(1, 1);
      orientation.c[0] = rtNaN;
      orientation.d.set_size(1, 1);
      orientation.d[0] = rtNaN;
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
    varargout_2->a = orientation.a[0];
    varargout_2->b = orientation.b[0];
    varargout_2->c = orientation.c[0];
    varargout_2->d = orientation.d[0];
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
