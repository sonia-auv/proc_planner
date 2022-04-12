//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: clothoidG2fitMissingCourse.cpp
//
// MATLAB Coder version            : 5.4
// C/C++ source code generated on  : 12-Apr-2022 11:44:16
//

// Include Files
#include "clothoidG2fitMissingCourse.h"
#include "LMFsolve.h"
#include "anonymous_function.h"
#include "cat.h"
#include "clothoidG1fit2wp.h"
#include "colon.h"
#include "dclothoidwp.h"
#include "find.h"
#include "proc_planner_internal_types.h"
#include "proc_planner_rtwutil.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <cmath>
#include <string.h>

// Function Declarations
static void binary_expand_op(coder::array<double, 1U> &in1,
                             const coder::array<double, 1U> &in2, int in3,
                             const coder::array<double, 1U> &in4, int in5,
                             int in6);

static void binary_expand_op(coder::array<double, 1U> &in1,
                             const coder::array<double, 1U> &in2,
                             const coder::array<double, 1U> &in3, int in4,
                             int in5, int in6);

namespace coder {
namespace matlabshared {
namespace tracking {
namespace internal {
namespace scenario {
static void fitCourse_anonFcn1(const ::coder::array<double, 2U> &waypoints,
                               const ::coder::array<double, 1U> &x,
                               ::coder::array<double, 1U> &varargout_1,
                               ::coder::array<double, 2U> &varargout_2);

static void fitCourse_anonFcn2(const ::coder::array<double, 2U> &waypoints,
                               const ::coder::array<double, 1U> &course,
                               const ::coder::array<double, 1U> &x,
                               ::coder::array<double, 1U> &varargout_1,
                               ::coder::array<double, 2U> &varargout_2);

static void fitCourse_anonFcn4(const ::coder::array<double, 2U> &waypoints,
                               const ::coder::array<double, 1U> &course,
                               const ::coder::array<double, 1U> &x,
                               ::coder::array<double, 1U> &varargout_1,
                               ::coder::array<double, 2U> &varargout_2);

} // namespace scenario
} // namespace internal
} // namespace tracking
} // namespace matlabshared
} // namespace coder
static void e_binary_expand_op(coder::array<double, 1U> &in1,
                               const coder::array<double, 1U> &in2, int in3,
                               const coder::array<double, 1U> &in4, int in5,
                               int in6);

static void e_binary_expand_op(coder::array<double, 1U> &in1,
                               const coder::array<double, 1U> &in2,
                               const coder::array<double, 1U> &in3, int in4,
                               int in5, int in6);

static void f_binary_expand_op(coder::array<double, 1U> &in1,
                               const coder::array<double, 1U> &in2,
                               const coder::array<double, 1U> &in3, int in4,
                               int in5, int in6);

// Function Definitions
//
// Arguments    : coder::array<double, 1U> &in1
//                const coder::array<double, 1U> &in2
//                int in3
//                const coder::array<double, 1U> &in4
//                int in5
//                int in6
// Return Type  : void
//
static void binary_expand_op(coder::array<double, 1U> &in1,
                             const coder::array<double, 1U> &in2, int in3,
                             const coder::array<double, 1U> &in4, int in5,
                             int in6)
{
  coder::array<double, 1U> b_in2;
  int b_in6;
  int loop_ub;
  int stride_1_0;
  if ((in6 - in5) + 1 == 1) {
    b_in6 = in3 + 1;
  } else {
    b_in6 = (in6 - in5) + 1;
  }
  b_in2.set_size(b_in6);
  b_in6 = (in3 + 1 != 1);
  stride_1_0 = ((in6 - in5) + 1 != 1);
  if ((in6 - in5) + 1 == 1) {
    loop_ub = in3 + 1;
  } else {
    loop_ub = (in6 - in5) + 1;
  }
  for (int i{0}; i < loop_ub; i++) {
    b_in2[i] = in2[i * b_in6] - in4[in5 + i * stride_1_0];
  }
  in1.set_size(b_in2.size(0) + 1);
  loop_ub = b_in2.size(0);
  for (int i{0}; i < loop_ub; i++) {
    in1[i] = b_in2[i];
  }
  in1[b_in2.size(0)] = in2[in2.size(0) - 1];
}

//
// Arguments    : coder::array<double, 1U> &in1
//                const coder::array<double, 1U> &in2
//                const coder::array<double, 1U> &in3
//                int in4
//                int in5
//                int in6
// Return Type  : void
//
static void binary_expand_op(coder::array<double, 1U> &in1,
                             const coder::array<double, 1U> &in2,
                             const coder::array<double, 1U> &in3, int in4,
                             int in5, int in6)
{
  coder::array<double, 1U> b_in2;
  int b_in6;
  int loop_ub;
  int stride_1_0;
  if ((in6 - in5) + 1 == 1) {
    b_in6 = in4 + 1;
  } else {
    b_in6 = (in6 - in5) + 1;
  }
  b_in2.set_size(b_in6);
  b_in6 = (in4 + 1 != 1);
  stride_1_0 = ((in6 - in5) + 1 != 1);
  if ((in6 - in5) + 1 == 1) {
    loop_ub = in4 + 1;
  } else {
    loop_ub = (in6 - in5) + 1;
  }
  for (int i{0}; i < loop_ub; i++) {
    b_in2[i] = in2[i * b_in6] - in3[in5 + i * stride_1_0];
  }
  in1.set_size(b_in2.size(0) + 1);
  in1[0] = in2[in2.size(0) - 1] - in3[0];
  loop_ub = b_in2.size(0);
  for (int i{0}; i < loop_ub; i++) {
    in1[i + 1] = b_in2[i];
  }
}

//
// Arguments    : const ::coder::array<double, 2U> &waypoints
//                const ::coder::array<double, 1U> &x
//                ::coder::array<double, 1U> &varargout_1
//                ::coder::array<double, 2U> &varargout_2
// Return Type  : void
//
namespace coder {
namespace matlabshared {
namespace tracking {
namespace internal {
namespace scenario {
static void fitCourse_anonFcn1(const ::coder::array<double, 2U> &waypoints,
                               const ::coder::array<double, 1U> &x,
                               ::coder::array<double, 1U> &varargout_1,
                               ::coder::array<double, 2U> &varargout_2)
{
  array<creal_T, 1U> b_hip;
  array<creal_T, 1U> hip;
  array<double, 1U> a__5;
  array<double, 1U> b_x;
  array<double, 1U> c_x;
  array<double, 1U> dk0_dc0;
  array<double, 1U> dk0_dc1;
  array<double, 1U> dk1_dc0;
  array<double, 1U> dk1_dc1;
  array<double, 1U> k0;
  array<double, 1U> k1;
  int b_loop_ub;
  int i;
  int i1;
  int i2;
  int i3;
  int loop_ub;
  loop_ub = waypoints.size(0);
  hip.set_size(waypoints.size(0));
  for (i = 0; i < loop_ub; i++) {
    hip[i].re = waypoints[i];
    hip[i].im = waypoints[i + waypoints.size(0)];
  }
  if (waypoints.size(0) - 1 < 1) {
    loop_ub = 0;
    b_loop_ub = 0;
  } else {
    loop_ub = waypoints.size(0) - 1;
    b_loop_ub = waypoints.size(0) - 1;
  }
  if (waypoints.size(0) < 2) {
    i = 0;
    i1 = 0;
    i2 = 0;
    i3 = 0;
  } else {
    i = 1;
    i1 = waypoints.size(0);
    i2 = 1;
    i3 = waypoints.size(0);
  }
  b_hip.set_size(loop_ub);
  for (int i4{0}; i4 < loop_ub; i4++) {
    b_hip[i4] = hip[i4];
  }
  b_x.set_size(b_loop_ub);
  for (int i4{0}; i4 < b_loop_ub; i4++) {
    b_x[i4] = x[i4];
  }
  loop_ub = i1 - i;
  for (i1 = 0; i1 < loop_ub; i1++) {
    hip[i1] = hip[i + i1];
  }
  hip.set_size(loop_ub);
  loop_ub = i3 - i2;
  c_x.set_size(loop_ub);
  for (i = 0; i < loop_ub; i++) {
    c_x[i] = x[i2 + i];
  }
  clothoidG1fit2wp(b_hip, b_x, hip, c_x, k0, k1, a__5, dk0_dc0, dk0_dc1,
                   dk1_dc0, dk1_dc1);
  if (k1.size(0) - 1 < 1) {
    loop_ub = 1;
  } else {
    loop_ub = k1.size(0);
  }
  if (k0.size(0) < 2) {
    i = 0;
    i1 = 0;
  } else {
    i = 1;
    i1 = k0.size(0);
  }
  if (loop_ub - 1 == i1 - i) {
    varargout_1.set_size(loop_ub + 1);
    varargout_1[0] = 0.0 - k0[0];
    for (i1 = 0; i1 <= loop_ub - 2; i1++) {
      varargout_1[i1 + 1] = k1[i1] - k0[i + i1];
    }
    varargout_1[loop_ub] = k1[k1.size(0) - 1];
  } else {
    e_binary_expand_op(varargout_1, k0, k1, loop_ub - 2, i, i1 - 1);
  }
  if (waypoints.size(0) - 2 < 1) {
    loop_ub = -1;
  } else {
    loop_ub = waypoints.size(0) - 3;
  }
  if (waypoints.size(0) - 1 < 2) {
    i = 0;
    i1 = 0;
  } else {
    i = 1;
    i1 = waypoints.size(0) - 1;
  }
  if (loop_ub + 1 == i1 - i) {
    varargout_2.set_size(dk1_dc0.size(0) + 1, 3);
    b_loop_ub = dk1_dc0.size(0);
    for (i1 = 0; i1 < b_loop_ub; i1++) {
      varargout_2[i1] = dk1_dc0[i1];
    }
    varargout_2[dk1_dc0.size(0)] = 0.0;
    varargout_2[varargout_2.size(0)] = 0.0 - dk0_dc0[0];
    for (i1 = 0; i1 <= loop_ub; i1++) {
      varargout_2[(i1 + varargout_2.size(0)) + 1] =
          dk1_dc1[i1] - dk0_dc0[i + i1];
    }
    varargout_2[(loop_ub + varargout_2.size(0)) + 2] =
        dk1_dc1[waypoints.size(0) - 2];
    loop_ub = dk0_dc1.size(0);
    for (i = 0; i < loop_ub; i++) {
      varargout_2[i + varargout_2.size(0) * 2] = -dk0_dc1[i];
    }
    varargout_2[dk0_dc1.size(0) + varargout_2.size(0) * 2] = 0.0;
  } else {
    binary_expand_op(varargout_2, dk1_dc0, dk0_dc0, dk1_dc1, loop_ub, i, i1 - 1,
                     waypoints, dk0_dc1);
  }
}

//
// Arguments    : const ::coder::array<double, 2U> &waypoints
//                const ::coder::array<double, 1U> &course
//                const ::coder::array<double, 1U> &x
//                ::coder::array<double, 1U> &varargout_1
//                ::coder::array<double, 2U> &varargout_2
// Return Type  : void
//
static void fitCourse_anonFcn2(const ::coder::array<double, 2U> &waypoints,
                               const ::coder::array<double, 1U> &course,
                               const ::coder::array<double, 1U> &x,
                               ::coder::array<double, 1U> &varargout_1,
                               ::coder::array<double, 2U> &varargout_2)
{
  array<creal_T, 1U> b_hip;
  array<creal_T, 1U> hip;
  array<double, 1U> a__3;
  array<double, 1U> b_course;
  array<double, 1U> c_course;
  array<double, 1U> dk0_dc0;
  array<double, 1U> dk0_dc1;
  array<double, 1U> dk1_dc0;
  array<double, 1U> dk1_dc1;
  array<double, 1U> k0;
  array<double, 1U> k1;
  int b_loop_ub;
  int i;
  int i1;
  int i2;
  int i3;
  int loop_ub;
  int loop_ub_tmp;
  b_course.set_size(course.size(0));
  loop_ub = course.size(0);
  for (i = 0; i < loop_ub; i++) {
    b_course[i] = course[i];
  }
  loop_ub = waypoints.size(0);
  hip.set_size(waypoints.size(0));
  for (i = 0; i < loop_ub; i++) {
    hip[i].re = waypoints[i];
    hip[i].im = waypoints[i + waypoints.size(0)];
  }
  if (course.size(0) - 1 < 1) {
    loop_ub = 0;
  } else {
    loop_ub = course.size(0) - 1;
  }
  for (i = 0; i < loop_ub; i++) {
    b_course[i] = x[i];
  }
  if (waypoints.size(0) - 1 < 1) {
    loop_ub = 0;
    b_loop_ub = 0;
  } else {
    loop_ub = waypoints.size(0) - 1;
    b_loop_ub = waypoints.size(0) - 1;
  }
  if (waypoints.size(0) < 2) {
    i = 0;
    i1 = 0;
    i2 = 0;
    i3 = 0;
  } else {
    i = 1;
    i1 = waypoints.size(0);
    i2 = 1;
    i3 = waypoints.size(0);
  }
  b_hip.set_size(loop_ub);
  for (loop_ub_tmp = 0; loop_ub_tmp < loop_ub; loop_ub_tmp++) {
    b_hip[loop_ub_tmp] = hip[loop_ub_tmp];
  }
  c_course.set_size(b_loop_ub);
  for (loop_ub_tmp = 0; loop_ub_tmp < b_loop_ub; loop_ub_tmp++) {
    c_course[loop_ub_tmp] = b_course[loop_ub_tmp];
  }
  loop_ub_tmp = i1 - i;
  for (i1 = 0; i1 < loop_ub_tmp; i1++) {
    hip[i1] = hip[i + i1];
  }
  hip.set_size(loop_ub_tmp);
  loop_ub_tmp = i3 - i2;
  for (i = 0; i < loop_ub_tmp; i++) {
    b_course[i] = b_course[i2 + i];
  }
  b_course.set_size(loop_ub_tmp);
  clothoidG1fit2wp(b_hip, c_course, hip, b_course, k0, k1, a__3, dk0_dc0,
                   dk0_dc1, dk1_dc0, dk1_dc1);
  if (k1.size(0) - 1 < 1) {
    loop_ub = 1;
  } else {
    loop_ub = k1.size(0);
  }
  if (k0.size(0) < 2) {
    i = 0;
    i1 = 0;
  } else {
    i = 1;
    i1 = k0.size(0);
  }
  if (loop_ub - 1 == i1 - i) {
    varargout_1.set_size(loop_ub);
    varargout_1[0] = 0.0 - k0[0];
    for (i1 = 0; i1 <= loop_ub - 2; i1++) {
      varargout_1[i1 + 1] = k1[i1] - k0[i + i1];
    }
  } else {
    f_binary_expand_op(varargout_1, k0, k1, loop_ub - 2, i, i1 - 1);
  }
  if (dk0_dc1.size(0) - 1 < 1) {
    loop_ub = -1;
  } else {
    loop_ub = dk0_dc1.size(0) - 2;
  }
  if (dk1_dc0.size(0) - 1 < 1) {
    b_loop_ub = 1;
  } else {
    b_loop_ub = dk1_dc0.size(0);
  }
  if (waypoints.size(0) - 2 < 1) {
    loop_ub_tmp = -1;
  } else {
    loop_ub_tmp = waypoints.size(0) - 3;
  }
  if (waypoints.size(0) - 1 < 2) {
    i = 0;
    i1 = 0;
  } else {
    i = 1;
    i1 = waypoints.size(0) - 1;
  }
  if (loop_ub_tmp + 1 == i1 - i) {
    varargout_2.set_size(b_loop_ub, 3);
    for (i1 = 0; i1 <= b_loop_ub - 2; i1++) {
      varargout_2[i1] = dk1_dc0[i1];
    }
    varargout_2[b_loop_ub - 1] = 0.0;
    varargout_2[varargout_2.size(0)] = 0.0 - dk0_dc0[0];
    for (i1 = 0; i1 <= loop_ub_tmp; i1++) {
      varargout_2[(i1 + varargout_2.size(0)) + 1] =
          dk1_dc1[i1] - dk0_dc0[i + i1];
    }
    for (i = 0; i <= loop_ub; i++) {
      varargout_2[i + varargout_2.size(0) * 2] = -dk0_dc1[i];
    }
    varargout_2[(loop_ub + varargout_2.size(0) * 2) + 1] = 0.0;
  } else {
    binary_expand_op(varargout_2, dk1_dc0, b_loop_ub - 2, dk0_dc0, dk1_dc1,
                     loop_ub_tmp, i, i1 - 1, dk0_dc1, loop_ub);
  }
}

//
// Arguments    : const ::coder::array<double, 2U> &waypoints
//                const ::coder::array<double, 1U> &course
//                const ::coder::array<double, 1U> &x
//                ::coder::array<double, 1U> &varargout_1
//                ::coder::array<double, 2U> &varargout_2
// Return Type  : void
//
static void fitCourse_anonFcn4(const ::coder::array<double, 2U> &waypoints,
                               const ::coder::array<double, 1U> &course,
                               const ::coder::array<double, 1U> &x,
                               ::coder::array<double, 1U> &varargout_1,
                               ::coder::array<double, 2U> &varargout_2)
{
  array<creal_T, 1U> b_hip;
  array<creal_T, 1U> hip;
  array<double, 1U> a__4;
  array<double, 1U> b_course;
  array<double, 1U> c_course;
  array<double, 1U> dk0_dc0;
  array<double, 1U> dk0_dc1;
  array<double, 1U> dk1_dc0;
  array<double, 1U> dk1_dc1;
  array<double, 1U> k0;
  array<double, 1U> k1;
  int b_loop_ub;
  int i;
  int i1;
  int i2;
  int i3;
  int i4;
  int loop_ub;
  b_course.set_size(course.size(0));
  loop_ub = course.size(0);
  for (i = 0; i < loop_ub; i++) {
    b_course[i] = course[i];
  }
  loop_ub = waypoints.size(0);
  hip.set_size(waypoints.size(0));
  for (i = 0; i < loop_ub; i++) {
    hip[i].re = waypoints[i];
    hip[i].im = waypoints[i + waypoints.size(0)];
  }
  if (course.size(0) - 1 < 2) {
    i = -1;
    i1 = 1;
  } else {
    i = 0;
    i1 = course.size(0);
  }
  loop_ub = (i1 - i) - 2;
  for (i1 = 0; i1 < loop_ub; i1++) {
    b_course[(i + i1) + 1] = x[i1];
  }
  if (waypoints.size(0) - 1 < 1) {
    loop_ub = 0;
    b_loop_ub = 0;
  } else {
    loop_ub = waypoints.size(0) - 1;
    b_loop_ub = waypoints.size(0) - 1;
  }
  if (waypoints.size(0) < 2) {
    i = 0;
    i1 = 0;
    i2 = 0;
    i3 = 0;
  } else {
    i = 1;
    i1 = waypoints.size(0);
    i2 = 1;
    i3 = waypoints.size(0);
  }
  b_hip.set_size(loop_ub);
  for (i4 = 0; i4 < loop_ub; i4++) {
    b_hip[i4] = hip[i4];
  }
  c_course.set_size(b_loop_ub);
  for (i4 = 0; i4 < b_loop_ub; i4++) {
    c_course[i4] = b_course[i4];
  }
  b_loop_ub = i1 - i;
  for (i1 = 0; i1 < b_loop_ub; i1++) {
    hip[i1] = hip[i + i1];
  }
  hip.set_size(b_loop_ub);
  b_loop_ub = i3 - i2;
  for (i = 0; i < b_loop_ub; i++) {
    b_course[i] = b_course[i2 + i];
  }
  b_course.set_size(b_loop_ub);
  clothoidG1fit2wp(b_hip, c_course, hip, b_course, k0, k1, a__4, dk0_dc0,
                   dk0_dc1, dk1_dc0, dk1_dc1);
  if (k1.size(0) - 1 < 1) {
    loop_ub = 0;
  } else {
    loop_ub = k1.size(0) - 1;
  }
  if (k0.size(0) < 2) {
    i = 0;
    i1 = 0;
  } else {
    i = 1;
    i1 = k0.size(0);
  }
  if (loop_ub == i1 - i) {
    varargout_1.set_size(loop_ub);
    for (i1 = 0; i1 < loop_ub; i1++) {
      varargout_1[i1] = k1[i1] - k0[i + i1];
    }
  } else {
    e_binary_expand_op(varargout_1, k1, loop_ub - 1, k0, i, i1 - 1);
  }
  if (dk0_dc1.size(0) - 1 < 2) {
    i = 0;
    i1 = -1;
  } else {
    i = 1;
    i1 = dk0_dc1.size(0) - 2;
  }
  if (dk1_dc0.size(0) - 1 < 2) {
    i2 = 0;
    i3 = 1;
  } else {
    i2 = 1;
    i3 = dk1_dc0.size(0);
  }
  if (waypoints.size(0) - 2 < 1) {
    loop_ub = -1;
  } else {
    loop_ub = waypoints.size(0) - 3;
  }
  if (waypoints.size(0) - 1 < 2) {
    i4 = 0;
    b_loop_ub = 0;
  } else {
    i4 = 1;
    b_loop_ub = waypoints.size(0) - 1;
  }
  if (loop_ub + 1 == b_loop_ub - i4) {
    b_loop_ub = i3 - i2;
    varargout_2.set_size(b_loop_ub, 3);
    for (i3 = 0; i3 <= b_loop_ub - 2; i3++) {
      varargout_2[i3] = dk1_dc0[i2 + i3];
    }
    varargout_2[b_loop_ub - 1] = 0.0;
    for (i2 = 0; i2 <= loop_ub; i2++) {
      varargout_2[i2 + varargout_2.size(0)] = dk1_dc1[i2] - dk0_dc0[i4 + i2];
    }
    b_loop_ub = i1 - i;
    for (i1 = 0; i1 <= b_loop_ub; i1++) {
      varargout_2[i1 + varargout_2.size(0) * 2] = -dk0_dc1[i + i1];
    }
    varargout_2[(b_loop_ub + varargout_2.size(0) * 2) + 1] = 0.0;
  } else {
    binary_expand_op(varargout_2, dk1_dc0, i2, i3 - 2, dk1_dc1, loop_ub,
                     dk0_dc0, i4, b_loop_ub - 1, dk0_dc1, i, i1);
  }
}

//
// Arguments    : coder::array<double, 1U> &in1
//                const coder::array<double, 1U> &in2
//                int in3
//                const coder::array<double, 1U> &in4
//                int in5
//                int in6
// Return Type  : void
//
} // namespace scenario
} // namespace internal
} // namespace tracking
} // namespace matlabshared
} // namespace coder
static void e_binary_expand_op(coder::array<double, 1U> &in1,
                               const coder::array<double, 1U> &in2, int in3,
                               const coder::array<double, 1U> &in4, int in5,
                               int in6)
{
  int b_in6;
  int loop_ub;
  int stride_1_0;
  if ((in6 - in5) + 1 == 1) {
    b_in6 = in3 + 1;
  } else {
    b_in6 = (in6 - in5) + 1;
  }
  in1.set_size(b_in6);
  b_in6 = (in3 + 1 != 1);
  stride_1_0 = ((in6 - in5) + 1 != 1);
  if ((in6 - in5) + 1 == 1) {
    loop_ub = in3 + 1;
  } else {
    loop_ub = (in6 - in5) + 1;
  }
  for (int i{0}; i < loop_ub; i++) {
    in1[i] = in2[i * b_in6] - in4[in5 + i * stride_1_0];
  }
}

//
// Arguments    : coder::array<double, 1U> &in1
//                const coder::array<double, 1U> &in2
//                const coder::array<double, 1U> &in3
//                int in4
//                int in5
//                int in6
// Return Type  : void
//
static void e_binary_expand_op(coder::array<double, 1U> &in1,
                               const coder::array<double, 1U> &in2,
                               const coder::array<double, 1U> &in3, int in4,
                               int in5, int in6)
{
  coder::array<double, 1U> b_in3;
  int b_in6;
  int loop_ub;
  int stride_1_0;
  if ((in6 - in5) + 1 == 1) {
    b_in6 = in4 + 1;
  } else {
    b_in6 = (in6 - in5) + 1;
  }
  b_in3.set_size(b_in6);
  b_in6 = (in4 + 1 != 1);
  stride_1_0 = ((in6 - in5) + 1 != 1);
  if ((in6 - in5) + 1 == 1) {
    loop_ub = in4 + 1;
  } else {
    loop_ub = (in6 - in5) + 1;
  }
  for (int i{0}; i < loop_ub; i++) {
    b_in3[i] = in3[i * b_in6] - in2[in5 + i * stride_1_0];
  }
  in1.set_size(b_in3.size(0) + 2);
  in1[0] = 0.0 - in2[0];
  loop_ub = b_in3.size(0);
  for (int i{0}; i < loop_ub; i++) {
    in1[i + 1] = b_in3[i];
  }
  in1[b_in3.size(0) + 1] = in3[in3.size(0) - 1];
}

//
// Arguments    : coder::array<double, 1U> &in1
//                const coder::array<double, 1U> &in2
//                const coder::array<double, 1U> &in3
//                int in4
//                int in5
//                int in6
// Return Type  : void
//
static void f_binary_expand_op(coder::array<double, 1U> &in1,
                               const coder::array<double, 1U> &in2,
                               const coder::array<double, 1U> &in3, int in4,
                               int in5, int in6)
{
  coder::array<double, 1U> b_in3;
  int b_in6;
  int loop_ub;
  int stride_1_0;
  if ((in6 - in5) + 1 == 1) {
    b_in6 = in4 + 1;
  } else {
    b_in6 = (in6 - in5) + 1;
  }
  b_in3.set_size(b_in6);
  b_in6 = (in4 + 1 != 1);
  stride_1_0 = ((in6 - in5) + 1 != 1);
  if ((in6 - in5) + 1 == 1) {
    loop_ub = in4 + 1;
  } else {
    loop_ub = (in6 - in5) + 1;
  }
  for (int i{0}; i < loop_ub; i++) {
    b_in3[i] = in3[i * b_in6] - in2[in5 + i * stride_1_0];
  }
  in1.set_size(b_in3.size(0) + 1);
  in1[0] = 0.0 - in2[0];
  loop_ub = b_in3.size(0);
  for (int i{0}; i < loop_ub; i++) {
    in1[i + 1] = b_in3[i];
  }
}

//
// Arguments    : const ::coder::array<double, 2U> &waypoints
//                ::coder::array<double, 1U> &course
//                const ::coder::array<double, 1U> &ibegin
//                const ::coder::array<double, 1U> &iend
// Return Type  : void
//
namespace coder {
namespace matlabshared {
namespace tracking {
namespace internal {
namespace scenario {
void fillPartitions(const ::coder::array<double, 2U> &waypoints,
                    ::coder::array<double, 1U> &course,
                    const ::coder::array<double, 1U> &ibegin,
                    const ::coder::array<double, 1U> &iend)
{
  array<double, 2U> b_waypoints;
  array<double, 2U> range;
  array<double, 1U> r1;
  array<int, 2U> r;
  int i;
  i = ibegin.size(0);
  for (int b_i{0}; b_i < i; b_i++) {
    int loop_ub;
    if (std::isnan(ibegin[b_i]) || std::isnan(iend[b_i])) {
      range.set_size(1, 1);
      range[0] = rtNaN;
    } else if (iend[b_i] < ibegin[b_i]) {
      range.set_size(1, 0);
    } else if ((std::isinf(ibegin[b_i]) || std::isinf(iend[b_i])) &&
               (ibegin[b_i] == iend[b_i])) {
      range.set_size(1, 1);
      range[0] = rtNaN;
    } else if (std::floor(ibegin[b_i]) == ibegin[b_i]) {
      loop_ub = static_cast<int>(iend[b_i] - ibegin[b_i]);
      range.set_size(1, loop_ub + 1);
      for (int i1{0}; i1 <= loop_ub; i1++) {
        range[i1] = ibegin[b_i] + static_cast<double>(i1);
      }
    } else {
      eml_float_colon(ibegin[b_i], iend[b_i], range);
    }
    r.set_size(1, range.size(1));
    loop_ub = range.size(1);
    for (int i1{0}; i1 < loop_ub; i1++) {
      r[i1] = static_cast<int>(range[i1]);
    }
    r1.set_size(range.size(1));
    loop_ub = range.size(1);
    for (int i1{0}; i1 < loop_ub; i1++) {
      r1[i1] = course[static_cast<int>(range[i1]) - 1];
    }
    b_waypoints.set_size(range.size(1), 3);
    loop_ub = range.size(1);
    for (int i1{0}; i1 < 3; i1++) {
      for (int i2{0}; i2 < loop_ub; i2++) {
        b_waypoints[i2 + b_waypoints.size(0) * i1] =
            waypoints[(static_cast<int>(range[i2]) + waypoints.size(0) * i1) -
                      1];
      }
    }
    fitCourse(b_waypoints, r1);
    loop_ub = r.size(1);
    for (int i1{0}; i1 < loop_ub; i1++) {
      course[r[i1] - 1] = r1[i1];
    }
  }
}

//
// Arguments    : const ::coder::array<double, 2U> &waypoints
//                ::coder::array<double, 1U> &course
// Return Type  : void
//
void fitCourse(const ::coder::array<double, 2U> &waypoints,
               ::coder::array<double, 1U> &course)
{
  anonymous_function b_this;
  array<double, 2U> Jtri;
  array<double, 2U> varargout_2;
  array<double, 1U> b_waypoints;
  array<double, 1U> courselsq;
  array<double, 1U> dx;
  array<double, 1U> r;
  array<double, 1U> v;
  array<double, 1U> xnew;
  array<bool, 1U> b_x;
  double th[2];
  double x[2];
  double lambda;
  double lambdac;
  double maxiter;
  int b_outsize[2];
  int outsize[2];
  int i;
  int loop_ub;
  int nx;
  int x_re_tmp;
  bool freelead;
  bool freetail;
  freelead = std::isnan(course[0]);
  freetail = std::isnan(course[course.size(0) - 1]);
  maxiter = course[0];
  x[0] = std::cos(maxiter);
  maxiter = std::sin(maxiter);
  th[0] = maxiter;
  maxiter = course[course.size(0) - 1];
  x[1] = std::cos(maxiter);
  maxiter = std::sin(maxiter);
  th[1] = maxiter;
  loop_ub = waypoints.size(0);
  dx.set_size(waypoints.size(0));
  for (i = 0; i < loop_ub; i++) {
    dx[i] = waypoints[i];
  }
  loop_ub = waypoints.size(0);
  b_waypoints.set_size(waypoints.size(0));
  for (i = 0; i < loop_ub; i++) {
    b_waypoints[i] = waypoints[i + waypoints.size(0)];
  }
  dclothoidwp(dx, b_waypoints, x, th, xnew, v);
  i = waypoints.size(0);
  for (loop_ub = 0; loop_ub <= i - 3; loop_ub++) {
    nx = static_cast<int>((static_cast<double>(loop_ub) + 1.0) * 128.0 + 1.0) -
         1;
    x_re_tmp = (loop_ub + 1) * 128 - 1;
    course[loop_ub + 1] =
        rt_atan2d_snf(v[nx] - v[x_re_tmp], xnew[nx] - xnew[x_re_tmp]);
  }
  if (freelead) {
    course[0] = rt_atan2d_snf(v[1] - v[0], xnew[1] - xnew[0]);
  }
  if (freetail) {
    course[course.size(0) - 1] =
        rt_atan2d_snf(v[v.size(0) - 1] - v[v.size(0) - 2],
                      xnew[xnew.size(0) - 1] - xnew[xnew.size(0) - 2]);
  }
  if (freelead && freetail) {
    double S;
    double iter;
    bool exitg1;
    courselsq.set_size(course.size(0));
    loop_ub = course.size(0);
    for (i = 0; i < loop_ub; i++) {
      courselsq[i] = course[i];
    }
    maxiter = 100.0 * static_cast<double>(course.size(0));
    fitCourse_anonFcn1(waypoints, course, r, Jtri);
    mulJt(Jtri, r, v);
    S = 0.0;
    loop_ub = r.size(0);
    for (i = 0; i < loop_ub; i++) {
      S += r[i] * r[i];
    }
    lambda = 0.0;
    lambdac = 0.75;
    iter = 0.0;
    outsize[0] = course.size(0);
    b_outsize[0] = course.size(0);
    dx.set_size(outsize[0]);
    loop_ub = outsize[0];
    for (i = 0; i < loop_ub; i++) {
      dx[i] = 1.0E-7;
    }
    exitg1 = false;
    while ((!exitg1) && (iter < maxiter)) {
      bool exitg2;
      nx = dx.size(0);
      xnew.set_size(dx.size(0));
      for (x_re_tmp = 0; x_re_tmp < nx; x_re_tmp++) {
        xnew[x_re_tmp] = std::abs(dx[x_re_tmp]);
      }
      if (xnew.size(0) == outsize[0]) {
        b_x.set_size(xnew.size(0));
        loop_ub = xnew.size(0);
        for (i = 0; i < loop_ub; i++) {
          b_x[i] = (xnew[i] >= 1.0E-7);
        }
      } else {
        j_binary_expand_op(b_x, xnew, outsize);
      }
      freelead = false;
      nx = 1;
      exitg2 = false;
      while ((!exitg2) && (nx <= b_x.size(0))) {
        if (b_x[nx - 1]) {
          freelead = true;
          exitg2 = true;
        } else {
          nx++;
        }
      }
      if (freelead) {
        nx = r.size(0);
        xnew.set_size(r.size(0));
        for (x_re_tmp = 0; x_re_tmp < nx; x_re_tmp++) {
          xnew[x_re_tmp] = std::abs(r[x_re_tmp]);
        }
        if (xnew.size(0) == b_outsize[0]) {
          b_x.set_size(xnew.size(0));
          loop_ub = xnew.size(0);
          for (i = 0; i < loop_ub; i++) {
            b_x[i] = (xnew[i] >= 1.0E-7);
          }
        } else {
          j_binary_expand_op(b_x, xnew, b_outsize);
        }
        freelead = false;
        nx = 1;
        exitg2 = false;
        while ((!exitg2) && (nx <= b_x.size(0))) {
          if (b_x[nx - 1]) {
            freelead = true;
            exitg2 = true;
          } else {
            nx++;
          }
        }
        if (freelead) {
          double c_waypoints;
          iter++;
          solveDampenedHessian(Jtri, lambda, v, dx);
          if (courselsq.size(0) == dx.size(0)) {
            xnew.set_size(courselsq.size(0));
            loop_ub = courselsq.size(0);
            for (i = 0; i < loop_ub; i++) {
              xnew[i] = courselsq[i] - dx[i];
            }
          } else {
            minus(xnew, courselsq, dx);
          }
          fitCourse_anonFcn1(waypoints, xnew, b_waypoints, varargout_2);
          c_waypoints = 0.0;
          loop_ub = b_waypoints.size(0);
          for (i = 0; i < loop_ub; i++) {
            c_waypoints += b_waypoints[i] * b_waypoints[i];
          }
          fletcher(S, c_waypoints, dx, v, Jtri, &lambda, &lambdac);
          if (c_waypoints < S) {
            S = c_waypoints;
            courselsq.set_size(xnew.size(0));
            loop_ub = xnew.size(0);
            for (i = 0; i < loop_ub; i++) {
              courselsq[i] = xnew[i];
            }
            r.set_size(b_waypoints.size(0));
            loop_ub = b_waypoints.size(0);
            for (i = 0; i < loop_ub; i++) {
              r[i] = b_waypoints[i];
            }
            Jtri.set_size(varargout_2.size(0), 3);
            loop_ub = varargout_2.size(0) * 3;
            for (i = 0; i < loop_ub; i++) {
              Jtri[i] = varargout_2[i];
            }
            mulJt(varargout_2, b_waypoints, v);
          }
        } else {
          exitg1 = true;
        }
      } else {
        exitg1 = true;
      }
    }
  } else if (freelead) {
    double S;
    double iter;
    bool exitg1;
    if (course.size(0) - 1 < 1) {
      loop_ub = 0;
    } else {
      loop_ub = course.size(0) - 1;
    }
    courselsq.set_size(loop_ub);
    maxiter = 100.0 * static_cast<double>(loop_ub);
    dx.set_size(loop_ub);
    for (i = 0; i < loop_ub; i++) {
      courselsq[i] = course[i];
      dx[i] = course[i];
    }
    fitCourse_anonFcn2(waypoints, course, dx, r, Jtri);
    mulJt(Jtri, r, v);
    S = 0.0;
    nx = r.size(0);
    for (i = 0; i < nx; i++) {
      S += r[i] * r[i];
    }
    lambda = 0.0;
    lambdac = 0.75;
    iter = 0.0;
    outsize[0] = loop_ub;
    b_outsize[0] = loop_ub;
    dx.set_size(loop_ub);
    for (i = 0; i < loop_ub; i++) {
      dx[i] = 1.0E-7;
    }
    exitg1 = false;
    while ((!exitg1) && (iter < maxiter)) {
      bool exitg2;
      nx = dx.size(0);
      xnew.set_size(dx.size(0));
      for (x_re_tmp = 0; x_re_tmp < nx; x_re_tmp++) {
        xnew[x_re_tmp] = std::abs(dx[x_re_tmp]);
      }
      if (xnew.size(0) == loop_ub) {
        b_x.set_size(xnew.size(0));
        nx = xnew.size(0);
        for (i = 0; i < nx; i++) {
          b_x[i] = (xnew[i] >= 1.0E-7);
        }
      } else {
        j_binary_expand_op(b_x, xnew, outsize);
      }
      freelead = false;
      nx = 1;
      exitg2 = false;
      while ((!exitg2) && (nx <= b_x.size(0))) {
        if (b_x[nx - 1]) {
          freelead = true;
          exitg2 = true;
        } else {
          nx++;
        }
      }
      if (freelead) {
        nx = r.size(0);
        xnew.set_size(r.size(0));
        for (x_re_tmp = 0; x_re_tmp < nx; x_re_tmp++) {
          xnew[x_re_tmp] = std::abs(r[x_re_tmp]);
        }
        if (xnew.size(0) == loop_ub) {
          b_x.set_size(xnew.size(0));
          nx = xnew.size(0);
          for (i = 0; i < nx; i++) {
            b_x[i] = (xnew[i] >= 1.0E-7);
          }
        } else {
          j_binary_expand_op(b_x, xnew, b_outsize);
        }
        freelead = false;
        nx = 1;
        exitg2 = false;
        while ((!exitg2) && (nx <= b_x.size(0))) {
          if (b_x[nx - 1]) {
            freelead = true;
            exitg2 = true;
          } else {
            nx++;
          }
        }
        if (freelead) {
          double c_waypoints;
          iter++;
          solveDampenedHessian(Jtri, lambda, v, dx);
          if (courselsq.size(0) == dx.size(0)) {
            xnew.set_size(courselsq.size(0));
            nx = courselsq.size(0);
            for (i = 0; i < nx; i++) {
              xnew[i] = courselsq[i] - dx[i];
            }
          } else {
            minus(xnew, courselsq, dx);
          }
          fitCourse_anonFcn2(waypoints, course, xnew, b_waypoints, varargout_2);
          c_waypoints = 0.0;
          nx = b_waypoints.size(0);
          for (i = 0; i < nx; i++) {
            c_waypoints += b_waypoints[i] * b_waypoints[i];
          }
          fletcher(S, c_waypoints, dx, v, Jtri, &lambda, &lambdac);
          if (c_waypoints < S) {
            S = c_waypoints;
            courselsq.set_size(xnew.size(0));
            nx = xnew.size(0);
            for (i = 0; i < nx; i++) {
              courselsq[i] = xnew[i];
            }
            r.set_size(b_waypoints.size(0));
            nx = b_waypoints.size(0);
            for (i = 0; i < nx; i++) {
              r[i] = b_waypoints[i];
            }
            Jtri.set_size(varargout_2.size(0), 3);
            nx = varargout_2.size(0) * 3;
            for (i = 0; i < nx; i++) {
              Jtri[i] = varargout_2[i];
            }
            mulJt(varargout_2, b_waypoints, v);
          }
        } else {
          exitg1 = true;
        }
      } else {
        exitg1 = true;
      }
    }
    i = courselsq.size(0);
    courselsq.set_size(courselsq.size(0) + 1);
    courselsq[i] = course[waypoints.size(0) - 1];
  } else if (freetail) {
    if (course.size(0) < 2) {
      i = 0;
      nx = 0;
    } else {
      i = 1;
      nx = course.size(0);
    }
    b_this.workspace.waypoints.set_size(waypoints.size(0), 3);
    loop_ub = waypoints.size(0) * 3;
    for (x_re_tmp = 0; x_re_tmp < loop_ub; x_re_tmp++) {
      b_this.workspace.waypoints[x_re_tmp] = waypoints[x_re_tmp];
    }
    b_this.workspace.course.set_size(course.size(0));
    loop_ub = course.size(0);
    for (x_re_tmp = 0; x_re_tmp < loop_ub; x_re_tmp++) {
      b_this.workspace.course[x_re_tmp] = course[x_re_tmp];
    }
    loop_ub = nx - i;
    courselsq.set_size(loop_ub);
    for (nx = 0; nx < loop_ub; nx++) {
      courselsq[nx] = course[i + nx];
    }
    LMFsolve(&b_this, courselsq);
    dx.set_size(courselsq.size(0) + 1);
    dx[0] = course[0];
    loop_ub = courselsq.size(0);
    for (i = 0; i < loop_ub; i++) {
      dx[i + 1] = courselsq[i];
    }
    courselsq.set_size(dx.size(0));
    loop_ub = dx.size(0);
    for (i = 0; i < loop_ub; i++) {
      courselsq[i] = dx[i];
    }
  } else {
    double S;
    double iter;
    bool exitg1;
    if (course.size(0) - 1 < 2) {
      i = -1;
      nx = -1;
    } else {
      i = 0;
      nx = course.size(0) - 2;
    }
    loop_ub = nx - i;
    courselsq.set_size(loop_ub);
    maxiter = 100.0 * static_cast<double>(loop_ub);
    dx.set_size(loop_ub);
    for (nx = 0; nx < loop_ub; nx++) {
      courselsq[nx] = course[(i + nx) + 1];
      dx[nx] = course[(i + nx) + 1];
    }
    fitCourse_anonFcn4(waypoints, course, dx, r, Jtri);
    mulJt(Jtri, r, v);
    S = 0.0;
    nx = r.size(0);
    for (i = 0; i < nx; i++) {
      S += r[i] * r[i];
    }
    lambda = 0.0;
    lambdac = 0.75;
    iter = 0.0;
    outsize[0] = loop_ub;
    b_outsize[0] = loop_ub;
    dx.set_size(loop_ub);
    for (i = 0; i < loop_ub; i++) {
      dx[i] = 1.0E-7;
    }
    exitg1 = false;
    while ((!exitg1) && (iter < maxiter)) {
      bool exitg2;
      nx = dx.size(0);
      xnew.set_size(dx.size(0));
      for (x_re_tmp = 0; x_re_tmp < nx; x_re_tmp++) {
        xnew[x_re_tmp] = std::abs(dx[x_re_tmp]);
      }
      if (xnew.size(0) == loop_ub) {
        b_x.set_size(xnew.size(0));
        nx = xnew.size(0);
        for (i = 0; i < nx; i++) {
          b_x[i] = (xnew[i] >= 1.0E-7);
        }
      } else {
        j_binary_expand_op(b_x, xnew, outsize);
      }
      freelead = false;
      nx = 1;
      exitg2 = false;
      while ((!exitg2) && (nx <= b_x.size(0))) {
        if (b_x[nx - 1]) {
          freelead = true;
          exitg2 = true;
        } else {
          nx++;
        }
      }
      if (freelead) {
        nx = r.size(0);
        xnew.set_size(r.size(0));
        for (x_re_tmp = 0; x_re_tmp < nx; x_re_tmp++) {
          xnew[x_re_tmp] = std::abs(r[x_re_tmp]);
        }
        if (xnew.size(0) == loop_ub) {
          b_x.set_size(xnew.size(0));
          nx = xnew.size(0);
          for (i = 0; i < nx; i++) {
            b_x[i] = (xnew[i] >= 1.0E-7);
          }
        } else {
          j_binary_expand_op(b_x, xnew, b_outsize);
        }
        freelead = false;
        nx = 1;
        exitg2 = false;
        while ((!exitg2) && (nx <= b_x.size(0))) {
          if (b_x[nx - 1]) {
            freelead = true;
            exitg2 = true;
          } else {
            nx++;
          }
        }
        if (freelead) {
          double c_waypoints;
          iter++;
          solveDampenedHessian(Jtri, lambda, v, dx);
          if (courselsq.size(0) == dx.size(0)) {
            xnew.set_size(courselsq.size(0));
            nx = courselsq.size(0);
            for (i = 0; i < nx; i++) {
              xnew[i] = courselsq[i] - dx[i];
            }
          } else {
            minus(xnew, courselsq, dx);
          }
          fitCourse_anonFcn4(waypoints, course, xnew, b_waypoints, varargout_2);
          c_waypoints = 0.0;
          nx = b_waypoints.size(0);
          for (i = 0; i < nx; i++) {
            c_waypoints += b_waypoints[i] * b_waypoints[i];
          }
          fletcher(S, c_waypoints, dx, v, Jtri, &lambda, &lambdac);
          if (c_waypoints < S) {
            S = c_waypoints;
            courselsq.set_size(xnew.size(0));
            nx = xnew.size(0);
            for (i = 0; i < nx; i++) {
              courselsq[i] = xnew[i];
            }
            r.set_size(b_waypoints.size(0));
            nx = b_waypoints.size(0);
            for (i = 0; i < nx; i++) {
              r[i] = b_waypoints[i];
            }
            Jtri.set_size(varargout_2.size(0), 3);
            nx = varargout_2.size(0) * 3;
            for (i = 0; i < nx; i++) {
              Jtri[i] = varargout_2[i];
            }
            mulJt(varargout_2, b_waypoints, v);
          }
        } else {
          exitg1 = true;
        }
      } else {
        exitg1 = true;
      }
    }
    dx.set_size(courselsq.size(0) + 2);
    dx[0] = course[0];
    loop_ub = courselsq.size(0);
    for (i = 0; i < loop_ub; i++) {
      dx[i + 1] = courselsq[i];
    }
    dx[courselsq.size(0) + 1] = course[waypoints.size(0) - 1];
    courselsq.set_size(dx.size(0));
    loop_ub = dx.size(0);
    for (i = 0; i < loop_ub; i++) {
      courselsq[i] = dx[i];
    }
  }
  course.set_size(courselsq.size(0));
  loop_ub = courselsq.size(0);
  for (i = 0; i < loop_ub; i++) {
    course[i] = courselsq[i];
  }
}

//
// Arguments    : const ::coder::array<double, 2U> &waypoints
//                const ::coder::array<double, 1U> &course
//                const ::coder::array<double, 1U> &x
//                ::coder::array<double, 1U> &varargout_1
//                ::coder::array<double, 2U> &varargout_2
// Return Type  : void
//
void fitCourse_anonFcn3(const ::coder::array<double, 2U> &waypoints,
                        const ::coder::array<double, 1U> &course,
                        const ::coder::array<double, 1U> &x,
                        ::coder::array<double, 1U> &varargout_1,
                        ::coder::array<double, 2U> &varargout_2)
{
  array<creal_T, 1U> b_hip;
  array<creal_T, 1U> hip;
  array<double, 1U> a__2;
  array<double, 1U> b_course;
  array<double, 1U> c_course;
  array<double, 1U> dk0_dc0;
  array<double, 1U> dk0_dc1;
  array<double, 1U> dk1_dc0;
  array<double, 1U> dk1_dc1;
  array<double, 1U> k0;
  array<double, 1U> k1;
  int b_loop_ub;
  int i;
  int i1;
  int i2;
  int i3;
  int i4;
  int loop_ub;
  b_course.set_size(course.size(0));
  loop_ub = course.size(0);
  for (i = 0; i < loop_ub; i++) {
    b_course[i] = course[i];
  }
  loop_ub = waypoints.size(0);
  hip.set_size(waypoints.size(0));
  for (i = 0; i < loop_ub; i++) {
    hip[i].re = waypoints[i];
    hip[i].im = waypoints[i + waypoints.size(0)];
  }
  if (course.size(0) < 2) {
    i = -1;
    i1 = 0;
  } else {
    i = 0;
    i1 = course.size(0);
  }
  loop_ub = (i1 - i) - 1;
  for (i1 = 0; i1 < loop_ub; i1++) {
    b_course[(i + i1) + 1] = x[i1];
  }
  if (waypoints.size(0) - 1 < 1) {
    loop_ub = 0;
    b_loop_ub = 0;
  } else {
    loop_ub = waypoints.size(0) - 1;
    b_loop_ub = waypoints.size(0) - 1;
  }
  if (waypoints.size(0) < 2) {
    i = 0;
    i1 = 0;
    i2 = 0;
    i3 = 0;
  } else {
    i = 1;
    i1 = waypoints.size(0);
    i2 = 1;
    i3 = waypoints.size(0);
  }
  b_hip.set_size(loop_ub);
  for (i4 = 0; i4 < loop_ub; i4++) {
    b_hip[i4] = hip[i4];
  }
  c_course.set_size(b_loop_ub);
  for (i4 = 0; i4 < b_loop_ub; i4++) {
    c_course[i4] = b_course[i4];
  }
  b_loop_ub = i1 - i;
  for (i1 = 0; i1 < b_loop_ub; i1++) {
    hip[i1] = hip[i + i1];
  }
  hip.set_size(b_loop_ub);
  b_loop_ub = i3 - i2;
  for (i = 0; i < b_loop_ub; i++) {
    b_course[i] = b_course[i2 + i];
  }
  b_course.set_size(b_loop_ub);
  clothoidG1fit2wp(b_hip, c_course, hip, b_course, k0, k1, a__2, dk0_dc0,
                   dk0_dc1, dk1_dc0, dk1_dc1);
  if (k1.size(0) - 1 < 1) {
    loop_ub = 0;
  } else {
    loop_ub = k1.size(0) - 1;
  }
  if (k0.size(0) < 2) {
    i = 0;
    i1 = 0;
  } else {
    i = 1;
    i1 = k0.size(0);
  }
  if (loop_ub == i1 - i) {
    varargout_1.set_size(loop_ub + 1);
    for (i1 = 0; i1 < loop_ub; i1++) {
      varargout_1[i1] = k1[i1] - k0[i + i1];
    }
    varargout_1[loop_ub] = k1[k1.size(0) - 1];
  } else {
    binary_expand_op(varargout_1, k1, loop_ub - 1, k0, i, i1 - 1);
  }
  if (dk0_dc1.size(0) < 2) {
    i = 0;
    i1 = 0;
  } else {
    i = 1;
    i1 = dk0_dc1.size(0);
  }
  if (dk1_dc0.size(0) < 2) {
    i2 = 0;
    i3 = 0;
  } else {
    i2 = 1;
    i3 = dk1_dc0.size(0);
  }
  if (waypoints.size(0) - 2 < 1) {
    loop_ub = 0;
  } else {
    loop_ub = waypoints.size(0) - 2;
  }
  if (waypoints.size(0) - 1 < 2) {
    i4 = 0;
    b_loop_ub = 0;
  } else {
    i4 = 1;
    b_loop_ub = waypoints.size(0) - 1;
  }
  if (loop_ub == b_loop_ub - i4) {
    b_loop_ub = i3 - i2;
    varargout_2.set_size(b_loop_ub + 1, 3);
    for (i3 = 0; i3 < b_loop_ub; i3++) {
      varargout_2[i3] = dk1_dc0[i2 + i3];
    }
    varargout_2[b_loop_ub] = 0.0;
    for (i2 = 0; i2 < loop_ub; i2++) {
      varargout_2[i2 + varargout_2.size(0)] = dk1_dc1[i2] - dk0_dc0[i4 + i2];
    }
    varargout_2[loop_ub + varargout_2.size(0)] = dk1_dc1[waypoints.size(0) - 2];
    b_loop_ub = i1 - i;
    for (i1 = 0; i1 < b_loop_ub; i1++) {
      varargout_2[i1 + varargout_2.size(0) * 2] = -dk0_dc1[i + i1];
    }
    varargout_2[b_loop_ub + varargout_2.size(0) * 2] = 0.0;
  } else {
    binary_expand_op(varargout_2, dk1_dc0, i2, i3 - 1, dk1_dc1, loop_ub - 1,
                     dk0_dc0, i4, b_loop_ub - 1, waypoints, dk0_dc1, i, i1 - 1);
  }
}

//
// Arguments    : const ::coder::array<double, 2U> &waypoints
//                const ::coder::array<double, 1U> &x
//                ::coder::array<double, 1U> &varargout_1
//                ::coder::array<double, 2U> &varargout_2
// Return Type  : void
//
void fitLoopCourse_anonFcn1(const ::coder::array<double, 2U> &waypoints,
                            const ::coder::array<double, 1U> &x,
                            ::coder::array<double, 1U> &varargout_1,
                            ::coder::array<double, 2U> &varargout_2)
{
  array<creal_T, 1U> b_hip;
  array<creal_T, 1U> hip;
  array<double, 1U> a__1;
  array<double, 1U> b_x;
  array<double, 1U> c_x;
  array<double, 1U> dk0_dc0;
  array<double, 1U> dk0_dc1;
  array<double, 1U> dk1_dc0;
  array<double, 1U> dk1_dc1;
  array<double, 1U> k0;
  array<double, 1U> k1;
  array<int, 2U> y;
  array<int, 1U> b_y;
  int b_loop_ub;
  int c_loop_ub;
  int i;
  int i1;
  int loop_ub;
  loop_ub = waypoints.size(0);
  hip.set_size(waypoints.size(0));
  for (i = 0; i < loop_ub; i++) {
    hip[i].re = waypoints[i];
    hip[i].im = waypoints[i + waypoints.size(0)];
  }
  if (waypoints.size(0) - 1 < 1) {
    loop_ub = 0;
    b_loop_ub = 0;
  } else {
    loop_ub = waypoints.size(0) - 1;
    b_loop_ub = waypoints.size(0) - 1;
  }
  if (waypoints.size(0) < 2) {
    i = 0;
    i1 = 0;
  } else {
    i = 1;
    i1 = waypoints.size(0);
  }
  if (waypoints.size(0) - 1 < 2) {
    y.set_size(1, 0);
  } else {
    c_loop_ub = waypoints.size(0) - 3;
    y.set_size(1, waypoints.size(0) - 2);
    for (int i2{0}; i2 <= c_loop_ub; i2++) {
      y[i2] = i2 + 2;
    }
  }
  b_y.set_size(y.size(1) + 1);
  c_loop_ub = y.size(1);
  for (int i2{0}; i2 < c_loop_ub; i2++) {
    b_y[i2] = y[i2] - 1;
  }
  b_y[y.size(1)] = 0;
  b_hip.set_size(loop_ub);
  for (int i2{0}; i2 < loop_ub; i2++) {
    b_hip[i2] = hip[i2];
  }
  b_x.set_size(b_loop_ub);
  for (int i2{0}; i2 < b_loop_ub; i2++) {
    b_x[i2] = x[i2];
  }
  loop_ub = i1 - i;
  for (i1 = 0; i1 < loop_ub; i1++) {
    hip[i1] = hip[i + i1];
  }
  hip.set_size(loop_ub);
  c_x.set_size(b_y.size(0));
  loop_ub = b_y.size(0);
  for (i = 0; i < loop_ub; i++) {
    c_x[i] = x[b_y[i]];
  }
  clothoidG1fit2wp(b_hip, b_x, hip, c_x, k0, k1, a__1, dk0_dc0, dk0_dc1,
                   dk1_dc0, dk1_dc1);
  if (k1.size(0) - 1 < 1) {
    loop_ub = 1;
  } else {
    loop_ub = k1.size(0);
  }
  if (k0.size(0) < 2) {
    i = 0;
    i1 = 0;
  } else {
    i = 1;
    i1 = k0.size(0);
  }
  if (loop_ub - 1 == i1 - i) {
    varargout_1.set_size(loop_ub);
    varargout_1[0] = k1[k1.size(0) - 1] - k0[0];
    for (i1 = 0; i1 <= loop_ub - 2; i1++) {
      varargout_1[i1 + 1] = k1[i1] - k0[i + i1];
    }
  } else {
    binary_expand_op(varargout_1, k1, k0, loop_ub - 2, i, i1 - 1);
  }
  if (waypoints.size(0) - 2 < 1) {
    y.set_size(1, 0);
  } else {
    loop_ub = waypoints.size(0) - 3;
    y.set_size(1, waypoints.size(0) - 2);
    for (i = 0; i <= loop_ub; i++) {
      y[i] = i + 1;
    }
  }
  b_y.set_size(y.size(1) + 1);
  b_y[0] = waypoints.size(0) - 2;
  loop_ub = y.size(1);
  for (i = 0; i < loop_ub; i++) {
    b_y[i + 1] = y[i] - 1;
  }
  a__1.set_size(b_y.size(0));
  loop_ub = b_y.size(0);
  for (i = 0; i < loop_ub; i++) {
    a__1[i] = dk1_dc1[b_y[i]];
  }
  if (a__1.size(0) == dk0_dc0.size(0)) {
    varargout_2.set_size(dk1_dc0.size(0), 3);
    loop_ub = dk1_dc0.size(0);
    for (i = 0; i < loop_ub; i++) {
      varargout_2[i] = dk1_dc0[i];
    }
    loop_ub = a__1.size(0);
    for (i = 0; i < loop_ub; i++) {
      varargout_2[i + varargout_2.size(0)] = a__1[i] - dk0_dc0[i];
    }
    loop_ub = dk0_dc1.size(0);
    for (i = 0; i < loop_ub; i++) {
      varargout_2[i + varargout_2.size(0) * 2] = -dk0_dc1[i];
    }
  } else {
    binary_expand_op(varargout_2, dk1_dc0, a__1, dk0_dc0, dk0_dc1);
  }
}

//
// Arguments    : const ::coder::array<double, 1U> &course
//                ::coder::array<double, 1U> &ibegin
//                ::coder::array<double, 1U> &iend
// Return Type  : void
//
void partitionCourse(const ::coder::array<double, 1U> &course,
                     ::coder::array<double, 1U> &ibegin,
                     ::coder::array<double, 1U> &iend)
{
  array<int, 1U> r2;
  array<bool, 1U> r;
  array<bool, 1U> r1;
  int i;
  int i1;
  int loop_ub;
  if (course.size(0) - 1 < 1) {
    loop_ub = 0;
  } else {
    loop_ub = course.size(0) - 1;
  }
  if (course.size(0) < 2) {
    i = 0;
    i1 = 0;
  } else {
    i = 1;
    i1 = course.size(0);
  }
  r.set_size(loop_ub);
  for (int i2{0}; i2 < loop_ub; i2++) {
    r[i2] = std::isnan(course[i2]);
  }
  loop_ub = i1 - i;
  r1.set_size(loop_ub);
  for (i1 = 0; i1 < loop_ub; i1++) {
    r1[i1] = std::isnan(course[i + i1]);
  }
  if (r.size(0) == r1.size(0)) {
    loop_ub = r.size(0);
    for (i = 0; i < loop_ub; i++) {
      r[i] = ((!r[i]) && r1[i]);
    }
    eml_find(r, r2);
  } else {
    d_binary_expand_op(r2, r, r1);
  }
  ibegin.set_size(r2.size(0));
  loop_ub = r2.size(0);
  for (i = 0; i < loop_ub; i++) {
    ibegin[i] = r2[i];
  }
  if (ibegin.size(0) == 0) {
    ibegin.set_size(0);
  }
  if (course.size(0) - 1 < 1) {
    loop_ub = 0;
  } else {
    loop_ub = course.size(0) - 1;
  }
  if (course.size(0) < 2) {
    i = 0;
    i1 = 0;
  } else {
    i = 1;
    i1 = course.size(0);
  }
  r.set_size(loop_ub);
  for (int i2{0}; i2 < loop_ub; i2++) {
    r[i2] = std::isnan(course[i2]);
  }
  loop_ub = i1 - i;
  r1.set_size(loop_ub);
  for (i1 = 0; i1 < loop_ub; i1++) {
    r1[i1] = std::isnan(course[i + i1]);
  }
  if (r.size(0) == r1.size(0)) {
    loop_ub = r.size(0);
    for (i = 0; i < loop_ub; i++) {
      r[i] = (r[i] && (!r1[i]));
    }
    eml_find(r, r2);
  } else {
    c_binary_expand_op(r2, r, r1);
  }
  iend.set_size(r2.size(0));
  loop_ub = r2.size(0);
  for (i = 0; i < loop_ub; i++) {
    iend[i] = static_cast<double>(r2[i]) + 1.0;
  }
  if (iend.size(0) == 0) {
    iend.set_size(0);
  }
}

} // namespace scenario
} // namespace internal
} // namespace tracking
} // namespace matlabshared
} // namespace coder

//
// File trailer for clothoidG2fitMissingCourse.cpp
//
// [EOF]
//
