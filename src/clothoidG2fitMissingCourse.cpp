//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: clothoidG2fitMissingCourse.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 01-Feb-2022 18:48:34
//

// Include Files
#include "clothoidG2fitMissingCourse.h"
#include "LMFsolve.h"
#include "anonymous_function.h"
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
namespace coder {
namespace matlabshared {
namespace tracking {
namespace internal {
namespace scenario {
static void fillPartitions(const ::coder::array<double, 2U> &waypoints,
                           ::coder::array<double, 1U> &course,
                           const ::coder::array<double, 1U> &ibegin,
                           const ::coder::array<double, 1U> &iend);

static void fitCourse(const ::coder::array<double, 2U> &waypoints,
                      ::coder::array<double, 1U> &course);

static void fitCourse_anonFcn1(const ::coder::array<double, 2U> &waypoints,
                               const ::coder::array<double, 1U> &x,
                               ::coder::array<double, 1U> &varargout_1,
                               ::coder::array<double, 2U> &varargout_2);

static void fitCourse_anonFcn2(const ::coder::array<double, 2U> &waypoints,
                               const ::coder::array<double, 1U> &course,
                               const ::coder::array<double, 1U> &x,
                               ::coder::array<double, 1U> &varargout_1,
                               ::coder::array<double, 2U> &varargout_2);

static void fitLoopCourse_anonFcn1(const ::coder::array<double, 2U> &waypoints,
                                   const ::coder::array<double, 1U> &x,
                                   ::coder::array<double, 1U> &varargout_1,
                                   ::coder::array<double, 2U> &varargout_2);

static void partitionCourse(const ::coder::array<double, 1U> &course,
                            ::coder::array<double, 1U> &ibegin,
                            ::coder::array<double, 1U> &iend);

} // namespace scenario
} // namespace internal
} // namespace tracking
} // namespace matlabshared
} // namespace coder

// Function Definitions
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
static void fillPartitions(const ::coder::array<double, 2U> &waypoints,
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
    int i1;
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
      loop_ub = static_cast<int>(std::floor(iend[b_i] - ibegin[b_i]));
      range.set_size(1, loop_ub + 1);
      for (i1 = 0; i1 <= loop_ub; i1++) {
        range[i1] = ibegin[b_i] + static_cast<double>(i1);
      }
    } else {
      eml_float_colon(ibegin[b_i], iend[b_i], range);
    }
    r.set_size(1, range.size(1));
    loop_ub = range.size(1);
    for (i1 = 0; i1 < loop_ub; i1++) {
      r[i1] = static_cast<int>(range[i1]);
    }
    r1.set_size(range.size(1));
    loop_ub = range.size(1);
    for (i1 = 0; i1 < loop_ub; i1++) {
      r1[i1] = course[static_cast<int>(range[i1]) - 1];
    }
    b_waypoints.set_size(range.size(1), 3);
    loop_ub = range.size(1);
    for (i1 = 0; i1 < 3; i1++) {
      for (int i2{0}; i2 < loop_ub; i2++) {
        b_waypoints[i2 + b_waypoints.size(0) * i1] =
            waypoints[(static_cast<int>(range[i2]) + waypoints.size(0) * i1) -
                      1];
      }
    }
    fitCourse(b_waypoints, r1);
    loop_ub = r.size(1);
    for (i1 = 0; i1 < loop_ub; i1++) {
      course[r[i1] - 1] = r1[i1];
    }
  }
}

//
// Arguments    : const ::coder::array<double, 2U> &waypoints
//                ::coder::array<double, 1U> &course
// Return Type  : void
//
static void fitCourse(const ::coder::array<double, 2U> &waypoints,
                      ::coder::array<double, 1U> &course)
{
  anonymous_function b_this;
  anonymous_function c_this;
  array<double, 2U> Jtri;
  array<double, 2U> varargout_2;
  array<double, 1U> courselsq;
  array<double, 1U> dx;
  array<double, 1U> r;
  array<double, 1U> v;
  array<double, 1U> varargout_1;
  array<double, 1U> xnew;
  array<bool, 1U> b_x;
  double th[2];
  double x[2];
  double lambda;
  double lambdac;
  double maxiter;
  int b_i;
  int i;
  int loop_ub;
  int nx;
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
  r.set_size(waypoints.size(0));
  for (i = 0; i < loop_ub; i++) {
    r[i] = waypoints[i];
  }
  loop_ub = waypoints.size(0);
  dx.set_size(waypoints.size(0));
  for (i = 0; i < loop_ub; i++) {
    dx[i] = waypoints[i + waypoints.size(0)];
  }
  dclothoidwp(r, dx, x, th, xnew, v);
  i = waypoints.size(0);
  for (b_i = 0; b_i <= i - 3; b_i++) {
    nx = static_cast<int>((static_cast<double>(b_i) + 1.0) * 128.0 + 1.0) - 1;
    loop_ub = (b_i + 1) * 128 - 1;
    course[b_i + 1] =
        rt_atan2d_snf(v[nx] - v[loop_ub], xnew[nx] - xnew[loop_ub]);
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
    nx = course.size(0);
    dx.set_size(nx);
    for (i = 0; i < nx; i++) {
      dx[i] = 1.0E-7;
    }
    exitg1 = false;
    while ((!exitg1) && (iter < maxiter)) {
      bool exitg2;
      nx = dx.size(0);
      xnew.set_size(dx.size(0));
      for (loop_ub = 0; loop_ub < nx; loop_ub++) {
        xnew[loop_ub] = std::abs(dx[loop_ub]);
      }
      b_x.set_size(xnew.size(0));
      loop_ub = xnew.size(0);
      for (i = 0; i < loop_ub; i++) {
        b_x[i] = (xnew[i] >= 1.0E-7);
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
        for (loop_ub = 0; loop_ub < nx; loop_ub++) {
          xnew[loop_ub] = std::abs(r[loop_ub]);
        }
        b_x.set_size(xnew.size(0));
        loop_ub = xnew.size(0);
        for (i = 0; i < loop_ub; i++) {
          b_x[i] = (xnew[i] >= 1.0E-7);
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
          double b_varargout_1;
          iter++;
          solveDampenedHessian(Jtri, lambda, v, dx);
          xnew.set_size(courselsq.size(0));
          loop_ub = courselsq.size(0);
          for (i = 0; i < loop_ub; i++) {
            xnew[i] = courselsq[i] - dx[i];
          }
          fitCourse_anonFcn1(waypoints, xnew, varargout_1, varargout_2);
          b_varargout_1 = 0.0;
          loop_ub = varargout_1.size(0);
          for (i = 0; i < loop_ub; i++) {
            b_varargout_1 += varargout_1[i] * varargout_1[i];
          }
          fletcher(S, b_varargout_1, dx, v, Jtri, &lambda, &lambdac);
          if (b_varargout_1 < S) {
            S = b_varargout_1;
            courselsq.set_size(xnew.size(0));
            loop_ub = xnew.size(0);
            for (i = 0; i < loop_ub; i++) {
              courselsq[i] = xnew[i];
            }
            r.set_size(varargout_1.size(0));
            loop_ub = varargout_1.size(0);
            for (i = 0; i < loop_ub; i++) {
              r[i] = varargout_1[i];
            }
            Jtri.set_size(varargout_2.size(0), 3);
            loop_ub = varargout_2.size(0) * 3;
            for (i = 0; i < loop_ub; i++) {
              Jtri[i] = varargout_2[i];
            }
            mulJt(varargout_2, varargout_1, v);
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
    if (1.0 > static_cast<double>(course.size(0)) - 1.0) {
      loop_ub = 0;
    } else {
      loop_ub = course.size(0) - 1;
    }
    courselsq.set_size(loop_ub);
    for (i = 0; i < loop_ub; i++) {
      courselsq[i] = course[i];
    }
    maxiter = 100.0 * static_cast<double>(loop_ub);
    fitCourse_anonFcn2(waypoints, course, courselsq, r, Jtri);
    mulJt(Jtri, r, v);
    S = 0.0;
    nx = r.size(0);
    for (i = 0; i < nx; i++) {
      S += r[i] * r[i];
    }
    lambda = 0.0;
    lambdac = 0.75;
    iter = 0.0;
    dx.set_size(loop_ub);
    for (i = 0; i < loop_ub; i++) {
      dx[i] = 1.0E-7;
    }
    exitg1 = false;
    while ((!exitg1) && (iter < maxiter)) {
      bool exitg2;
      nx = dx.size(0);
      xnew.set_size(dx.size(0));
      for (loop_ub = 0; loop_ub < nx; loop_ub++) {
        xnew[loop_ub] = std::abs(dx[loop_ub]);
      }
      b_x.set_size(xnew.size(0));
      loop_ub = xnew.size(0);
      for (i = 0; i < loop_ub; i++) {
        b_x[i] = (xnew[i] >= 1.0E-7);
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
        for (loop_ub = 0; loop_ub < nx; loop_ub++) {
          xnew[loop_ub] = std::abs(r[loop_ub]);
        }
        b_x.set_size(xnew.size(0));
        loop_ub = xnew.size(0);
        for (i = 0; i < loop_ub; i++) {
          b_x[i] = (xnew[i] >= 1.0E-7);
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
          double b_varargout_1;
          iter++;
          solveDampenedHessian(Jtri, lambda, v, dx);
          xnew.set_size(courselsq.size(0));
          loop_ub = courselsq.size(0);
          for (i = 0; i < loop_ub; i++) {
            xnew[i] = courselsq[i] - dx[i];
          }
          fitCourse_anonFcn2(waypoints, course, xnew, varargout_1, varargout_2);
          b_varargout_1 = 0.0;
          loop_ub = varargout_1.size(0);
          for (i = 0; i < loop_ub; i++) {
            b_varargout_1 += varargout_1[i] * varargout_1[i];
          }
          fletcher(S, b_varargout_1, dx, v, Jtri, &lambda, &lambdac);
          if (b_varargout_1 < S) {
            S = b_varargout_1;
            courselsq.set_size(xnew.size(0));
            loop_ub = xnew.size(0);
            for (i = 0; i < loop_ub; i++) {
              courselsq[i] = xnew[i];
            }
            r.set_size(varargout_1.size(0));
            loop_ub = varargout_1.size(0);
            for (i = 0; i < loop_ub; i++) {
              r[i] = varargout_1[i];
            }
            Jtri.set_size(varargout_2.size(0), 3);
            loop_ub = varargout_2.size(0) * 3;
            for (i = 0; i < loop_ub; i++) {
              Jtri[i] = varargout_2[i];
            }
            mulJt(varargout_2, varargout_1, v);
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
    if (2 > course.size(0)) {
      i = 0;
      nx = 0;
    } else {
      i = 1;
      nx = course.size(0);
    }
    c_this.workspace.waypoints.set_size(waypoints.size(0), 3);
    loop_ub = waypoints.size(0) * 3;
    for (b_i = 0; b_i < loop_ub; b_i++) {
      c_this.workspace.waypoints[b_i] = waypoints[b_i];
    }
    c_this.workspace.course.set_size(course.size(0));
    loop_ub = course.size(0);
    for (b_i = 0; b_i < loop_ub; b_i++) {
      c_this.workspace.course[b_i] = course[b_i];
    }
    loop_ub = nx - i;
    courselsq.set_size(loop_ub);
    for (nx = 0; nx < loop_ub; nx++) {
      courselsq[nx] = course[i + nx];
    }
    LMFsolve(&c_this, courselsq);
    r.set_size(courselsq.size(0) + 1);
    r[0] = course[0];
    loop_ub = courselsq.size(0);
    for (i = 0; i < loop_ub; i++) {
      r[i + 1] = courselsq[i];
    }
    courselsq.set_size(r.size(0));
    loop_ub = r.size(0);
    for (i = 0; i < loop_ub; i++) {
      courselsq[i] = r[i];
    }
  } else {
    if (2.0 > static_cast<double>(course.size(0)) - 1.0) {
      i = 0;
      nx = 0;
    } else {
      i = 1;
      nx = course.size(0) - 1;
    }
    b_this.workspace.waypoints.set_size(waypoints.size(0), 3);
    loop_ub = waypoints.size(0) * 3;
    for (b_i = 0; b_i < loop_ub; b_i++) {
      b_this.workspace.waypoints[b_i] = waypoints[b_i];
    }
    b_this.workspace.course.set_size(course.size(0));
    loop_ub = course.size(0);
    for (b_i = 0; b_i < loop_ub; b_i++) {
      b_this.workspace.course[b_i] = course[b_i];
    }
    loop_ub = nx - i;
    courselsq.set_size(loop_ub);
    for (nx = 0; nx < loop_ub; nx++) {
      courselsq[nx] = course[i + nx];
    }
    b_LMFsolve(&b_this, courselsq);
    r.set_size(courselsq.size(0) + 2);
    r[0] = course[0];
    loop_ub = courselsq.size(0);
    for (i = 0; i < loop_ub; i++) {
      r[i + 1] = courselsq[i];
    }
    r[courselsq.size(0) + 1] = course[waypoints.size(0) - 1];
    courselsq.set_size(r.size(0));
    loop_ub = r.size(0);
    for (i = 0; i < loop_ub; i++) {
      courselsq[i] = r[i];
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
//                const ::coder::array<double, 1U> &x
//                ::coder::array<double, 1U> &varargout_1
//                ::coder::array<double, 2U> &varargout_2
// Return Type  : void
//
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
  int i4;
  int loop_ub;
  loop_ub = waypoints.size(0);
  hip.set_size(waypoints.size(0));
  for (i = 0; i < loop_ub; i++) {
    hip[i].re = waypoints[i];
    hip[i].im = waypoints[i + waypoints.size(0)];
  }
  if (1 > waypoints.size(0) - 1) {
    loop_ub = 0;
    b_loop_ub = 0;
  } else {
    loop_ub = waypoints.size(0) - 1;
    b_loop_ub = waypoints.size(0) - 1;
  }
  if (2 > waypoints.size(0)) {
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
  b_x.set_size(b_loop_ub);
  for (i4 = 0; i4 < b_loop_ub; i4++) {
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
  if (1 > k1.size(0) - 1) {
    loop_ub = 1;
  } else {
    loop_ub = k1.size(0);
  }
  i = (2 <= k0.size(0));
  varargout_1.set_size(loop_ub + 1);
  varargout_1[0] = 0.0 - k0[0];
  for (i1 = 0; i1 <= loop_ub - 2; i1++) {
    varargout_1[i1 + 1] = k1[i1] - k0[i + i1];
  }
  varargout_1[loop_ub] = k1[k1.size(0) - 1];
  if (1 > waypoints.size(0) - 2) {
    loop_ub = 1;
  } else {
    loop_ub = waypoints.size(0) - 1;
  }
  i = (2 <= waypoints.size(0) - 1);
  varargout_2.set_size(dk1_dc0.size(0) + 1, 3);
  b_loop_ub = dk1_dc0.size(0);
  for (i1 = 0; i1 < b_loop_ub; i1++) {
    varargout_2[i1] = dk1_dc0[i1];
  }
  varargout_2[dk1_dc0.size(0)] = 0.0;
  varargout_2[varargout_2.size(0)] = 0.0 - dk0_dc0[0];
  for (i1 = 0; i1 <= loop_ub - 2; i1++) {
    varargout_2[(i1 + varargout_2.size(0)) + 1] = dk1_dc1[i1] - dk0_dc0[i + i1];
  }
  varargout_2[loop_ub + varargout_2.size(0)] = dk1_dc1[waypoints.size(0) - 2];
  loop_ub = dk0_dc1.size(0);
  for (i = 0; i < loop_ub; i++) {
    varargout_2[i + varargout_2.size(0) * 2] = -dk0_dc1[i];
  }
  varargout_2[dk0_dc1.size(0) + varargout_2.size(0) * 2] = 0.0;
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
  array<int, 2U> r;
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
  if (1 > course.size(0) - 1) {
    loop_ub = 0;
  } else {
    loop_ub = course.size(0) - 1;
  }
  r.set_size(1, loop_ub);
  for (i = 0; i < loop_ub; i++) {
    r[i] = i;
  }
  loop_ub = r.size(1);
  for (i = 0; i < loop_ub; i++) {
    b_course[r[i]] = x[i];
  }
  if (1 > waypoints.size(0) - 1) {
    loop_ub = 0;
    b_loop_ub = 0;
  } else {
    loop_ub = waypoints.size(0) - 1;
    b_loop_ub = waypoints.size(0) - 1;
  }
  if (2 > waypoints.size(0)) {
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
  if (1 > k1.size(0) - 1) {
    loop_ub = 1;
  } else {
    loop_ub = k1.size(0);
  }
  i = (2 <= k0.size(0));
  varargout_1.set_size(loop_ub);
  varargout_1[0] = 0.0 - k0[0];
  for (i1 = 0; i1 <= loop_ub - 2; i1++) {
    varargout_1[i1 + 1] = k1[i1] - k0[i + i1];
  }
  if (1 > dk0_dc1.size(0) - 1) {
    loop_ub = 0;
  } else {
    loop_ub = dk0_dc1.size(0) - 1;
  }
  if (1 > dk1_dc0.size(0) - 1) {
    b_loop_ub = 1;
  } else {
    b_loop_ub = dk1_dc0.size(0);
  }
  if (1 > waypoints.size(0) - 2) {
    loop_ub_tmp = 2;
  } else {
    loop_ub_tmp = waypoints.size(0);
  }
  i = (2 <= waypoints.size(0) - 1);
  varargout_2.set_size(b_loop_ub, 3);
  for (i1 = 0; i1 <= b_loop_ub - 2; i1++) {
    varargout_2[i1] = dk1_dc0[i1];
  }
  varargout_2[b_loop_ub - 1] = 0.0;
  varargout_2[varargout_2.size(0)] = 0.0 - dk0_dc0[0];
  for (i1 = 0; i1 <= loop_ub_tmp - 3; i1++) {
    varargout_2[(i1 + varargout_2.size(0)) + 1] = dk1_dc1[i1] - dk0_dc0[i + i1];
  }
  for (i = 0; i < loop_ub; i++) {
    varargout_2[i + varargout_2.size(0) * 2] = -dk0_dc1[i];
  }
  varargout_2[loop_ub + varargout_2.size(0) * 2] = 0.0;
}

//
// Arguments    : const ::coder::array<double, 2U> &waypoints
//                const ::coder::array<double, 1U> &x
//                ::coder::array<double, 1U> &varargout_1
//                ::coder::array<double, 2U> &varargout_2
// Return Type  : void
//
static void fitLoopCourse_anonFcn1(const ::coder::array<double, 2U> &waypoints,
                                   const ::coder::array<double, 1U> &x,
                                   ::coder::array<double, 1U> &varargout_1,
                                   ::coder::array<double, 2U> &varargout_2)
{
  array<creal_T, 1U> b_hip;
  array<creal_T, 1U> hip;
  array<double, 2U> y;
  array<double, 1U> a__1;
  array<double, 1U> b_x;
  array<double, 1U> c_x;
  array<double, 1U> dk0_dc0;
  array<double, 1U> dk0_dc1;
  array<double, 1U> dk1_dc0;
  array<double, 1U> dk1_dc1;
  array<double, 1U> k0;
  array<double, 1U> k1;
  array<int, 1U> b_y;
  int b_loop_ub;
  int c_loop_ub;
  int i;
  int i1;
  int i2;
  int loop_ub;
  loop_ub = waypoints.size(0);
  hip.set_size(waypoints.size(0));
  for (i = 0; i < loop_ub; i++) {
    hip[i].re = waypoints[i];
    hip[i].im = waypoints[i + waypoints.size(0)];
  }
  if (1 > waypoints.size(0) - 1) {
    loop_ub = 0;
    b_loop_ub = 0;
  } else {
    loop_ub = waypoints.size(0) - 1;
    b_loop_ub = waypoints.size(0) - 1;
  }
  if (2 > waypoints.size(0)) {
    i = 0;
    i1 = 0;
  } else {
    i = 1;
    i1 = waypoints.size(0);
  }
  if (waypoints.size(0) - 1 < 2) {
    y.set_size(1, 0);
  } else {
    y.set_size(1, static_cast<int>(
                      (static_cast<double>(waypoints.size(0)) - 1.0) - 2.0) +
                      1);
    c_loop_ub =
        static_cast<int>((static_cast<double>(waypoints.size(0)) - 1.0) - 2.0);
    for (i2 = 0; i2 <= c_loop_ub; i2++) {
      y[i2] = static_cast<double>(i2) + 2.0;
    }
  }
  b_y.set_size(y.size(1) + 1);
  c_loop_ub = y.size(1);
  for (i2 = 0; i2 < c_loop_ub; i2++) {
    b_y[i2] = static_cast<int>(y[i2]) - 1;
  }
  b_y[y.size(1)] = 0;
  b_hip.set_size(loop_ub);
  for (i2 = 0; i2 < loop_ub; i2++) {
    b_hip[i2] = hip[i2];
  }
  b_x.set_size(b_loop_ub);
  for (i2 = 0; i2 < b_loop_ub; i2++) {
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
  if (1 > k1.size(0) - 1) {
    loop_ub = 1;
  } else {
    loop_ub = k1.size(0);
  }
  i = (2 <= k0.size(0));
  varargout_1.set_size(loop_ub);
  varargout_1[0] = k1[k1.size(0) - 1] - k0[0];
  for (i1 = 0; i1 <= loop_ub - 2; i1++) {
    varargout_1[i1 + 1] = k1[i1] - k0[i + i1];
  }
  if (waypoints.size(0) - 2 < 1) {
    y.set_size(1, 0);
  } else {
    y.set_size(1, static_cast<int>(
                      (static_cast<double>(waypoints.size(0)) - 2.0) - 1.0) +
                      1);
    loop_ub =
        static_cast<int>((static_cast<double>(waypoints.size(0)) - 2.0) - 1.0);
    for (i = 0; i <= loop_ub; i++) {
      y[i] = static_cast<double>(i) + 1.0;
    }
  }
  b_y.set_size(y.size(1) + 1);
  b_y[0] = waypoints.size(0) - 2;
  loop_ub = y.size(1);
  for (i = 0; i < loop_ub; i++) {
    b_y[i + 1] = static_cast<int>(y[i]) - 1;
  }
  a__1.set_size(b_y.size(0));
  loop_ub = b_y.size(0);
  for (i = 0; i < loop_ub; i++) {
    a__1[i] = dk1_dc1[b_y[i]];
  }
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
}

//
// Arguments    : const ::coder::array<double, 1U> &course
//                ::coder::array<double, 1U> &ibegin
//                ::coder::array<double, 1U> &iend
// Return Type  : void
//
static void partitionCourse(const ::coder::array<double, 1U> &course,
                            ::coder::array<double, 1U> &ibegin,
                            ::coder::array<double, 1U> &iend)
{
  array<int, 1U> ii;
  array<bool, 1U> r;
  array<bool, 1U> r1;
  int i;
  int i1;
  int i2;
  int loop_ub;
  if (1 > course.size(0) - 1) {
    loop_ub = 0;
  } else {
    loop_ub = course.size(0) - 1;
  }
  if (2 > course.size(0)) {
    i = 0;
    i1 = 0;
  } else {
    i = 1;
    i1 = course.size(0);
  }
  r.set_size(loop_ub);
  for (i2 = 0; i2 < loop_ub; i2++) {
    r[i2] = std::isnan(course[i2]);
  }
  loop_ub = i1 - i;
  r1.set_size(loop_ub);
  for (i1 = 0; i1 < loop_ub; i1++) {
    r1[i1] = std::isnan(course[i + i1]);
  }
  loop_ub = r.size(0);
  for (i = 0; i < loop_ub; i++) {
    r[i] = ((!r[i]) && r1[i]);
  }
  eml_find(r, ii);
  ibegin.set_size(ii.size(0));
  loop_ub = ii.size(0);
  for (i = 0; i < loop_ub; i++) {
    ibegin[i] = ii[i];
  }
  if (ibegin.size(0) == 0) {
    ibegin.set_size(0);
  }
  if (1 > course.size(0) - 1) {
    loop_ub = 0;
  } else {
    loop_ub = course.size(0) - 1;
  }
  if (2 > course.size(0)) {
    i = 0;
    i1 = 0;
  } else {
    i = 1;
    i1 = course.size(0);
  }
  r.set_size(loop_ub);
  for (i2 = 0; i2 < loop_ub; i2++) {
    r[i2] = std::isnan(course[i2]);
  }
  loop_ub = i1 - i;
  r1.set_size(loop_ub);
  for (i1 = 0; i1 < loop_ub; i1++) {
    r1[i1] = std::isnan(course[i + i1]);
  }
  loop_ub = r.size(0);
  for (i = 0; i < loop_ub; i++) {
    r[i] = (r[i] && (!r1[i]));
  }
  eml_find(r, ii);
  iend.set_size(ii.size(0));
  loop_ub = ii.size(0);
  for (i = 0; i < loop_ub; i++) {
    iend[i] = static_cast<double>(ii[i]) + 1.0;
  }
  if (iend.size(0) == 0) {
    iend.set_size(0);
  }
}

//
// Arguments    : const ::coder::array<double, 2U> &waypoints
//                ::coder::array<double, 1U> &course
// Return Type  : void
//
void clothoidG2fitMissingCourse(const ::coder::array<double, 2U> &waypoints,
                                ::coder::array<double, 1U> &course)
{
  array<double, 2U> Jtri;
  array<double, 2U> b_y;
  array<double, 2U> range;
  array<double, 2U> y;
  array<double, 1U> courselsq;
  array<double, 1U> dx;
  array<double, 1U> ibegin;
  array<double, 1U> iend;
  array<double, 1U> r;
  array<double, 1U> v;
  array<int, 2U> b_r;
  array<bool, 1U> x;
  double lambda;
  double lambdac;
  int k;
  bool exitg1;
  bool p;
  p = true;
  k = 0;
  exitg1 = false;
  while ((!exitg1) && (k < 2)) {
    if (!(waypoints[waypoints.size(0) * k] ==
          waypoints[(waypoints.size(0) + waypoints.size(0) * k) - 1])) {
      p = false;
      exitg1 = true;
    } else {
      k++;
    }
  }
  if (p) {
    if (std::isnan(course[0])) {
      course[0] = course[course.size(0) - 1];
    } else {
      course[course.size(0) - 1] = course[0];
    }
    partitionCourse(course, r, dx);
    if ((r.size(0) == 0) && std::isnan(course[0])) {
      double S;
      double iter;
      double maxiter;
      int i;
      int n;
      k = waypoints.size(0);
      r.set_size(waypoints.size(0));
      for (i = 0; i < k; i++) {
        r[i] = waypoints[i];
      }
      k = waypoints.size(0);
      dx.set_size(waypoints.size(0));
      for (i = 0; i < k; i++) {
        dx[i] = waypoints[i + waypoints.size(0)];
      }
      dclothoidwp(r, dx, ibegin, v);
      course.set_size(waypoints.size(0));
      k = waypoints.size(0);
      for (i = 0; i < k; i++) {
        course[i] = 0.0;
      }
      course[0] = rt_atan2d_snf(v[1] - v[0], ibegin[1] - ibegin[0]);
      course[waypoints.size(0) - 1] = rt_atan2d_snf(
          v[v.size(0) - 1] - v[v.size(0) - 2],
          ibegin[ibegin.size(0) - 1] - ibegin[ibegin.size(0) - 2]);
      i = waypoints.size(0);
      for (int b_i{0}; b_i <= i - 3; b_i++) {
        k = static_cast<int>((static_cast<double>(b_i) + 1.0) * 128.0 + 1.0) -
            1;
        n = (b_i + 1) * 128 - 1;
        course[b_i + 1] = rt_atan2d_snf(v[k] - v[n], ibegin[k] - ibegin[n]);
      }
      if (1 > waypoints.size(0) - 1) {
        k = 0;
      } else {
        k = waypoints.size(0) - 1;
      }
      courselsq.set_size(k);
      for (i = 0; i < k; i++) {
        courselsq[i] = course[i];
      }
      maxiter = 100.0 * static_cast<double>(k);
      fitLoopCourse_anonFcn1(waypoints, courselsq, r, Jtri);
      mulJt(Jtri, r, v);
      S = 0.0;
      n = r.size(0);
      for (i = 0; i < n; i++) {
        S += r[i] * r[i];
      }
      lambda = 0.0;
      lambdac = 0.75;
      iter = 0.0;
      dx.set_size(k);
      for (i = 0; i < k; i++) {
        dx[i] = 1.0E-7;
      }
      exitg1 = false;
      while ((!exitg1) && (iter < maxiter)) {
        bool exitg2;
        n = dx.size(0);
        ibegin.set_size(dx.size(0));
        for (k = 0; k < n; k++) {
          ibegin[k] = std::abs(dx[k]);
        }
        x.set_size(ibegin.size(0));
        k = ibegin.size(0);
        for (i = 0; i < k; i++) {
          x[i] = (ibegin[i] >= 1.0E-7);
        }
        p = false;
        n = 1;
        exitg2 = false;
        while ((!exitg2) && (n <= x.size(0))) {
          if (x[n - 1]) {
            p = true;
            exitg2 = true;
          } else {
            n++;
          }
        }
        if (p) {
          n = r.size(0);
          ibegin.set_size(r.size(0));
          for (k = 0; k < n; k++) {
            ibegin[k] = std::abs(r[k]);
          }
          x.set_size(ibegin.size(0));
          k = ibegin.size(0);
          for (i = 0; i < k; i++) {
            x[i] = (ibegin[i] >= 1.0E-7);
          }
          p = false;
          n = 1;
          exitg2 = false;
          while ((!exitg2) && (n <= x.size(0))) {
            if (x[n - 1]) {
              p = true;
              exitg2 = true;
            } else {
              n++;
            }
          }
          if (p) {
            double b_iend;
            iter++;
            solveDampenedHessian(Jtri, lambda, v, dx);
            ibegin.set_size(courselsq.size(0));
            k = courselsq.size(0);
            for (i = 0; i < k; i++) {
              ibegin[i] = courselsq[i] - dx[i];
            }
            fitLoopCourse_anonFcn1(waypoints, ibegin, iend, y);
            b_iend = 0.0;
            k = iend.size(0);
            for (i = 0; i < k; i++) {
              b_iend += iend[i] * iend[i];
            }
            fletcher(S, b_iend, dx, v, Jtri, &lambda, &lambdac);
            if (b_iend < S) {
              S = b_iend;
              courselsq.set_size(ibegin.size(0));
              k = ibegin.size(0);
              for (i = 0; i < k; i++) {
                courselsq[i] = ibegin[i];
              }
              r.set_size(iend.size(0));
              k = iend.size(0);
              for (i = 0; i < k; i++) {
                r[i] = iend[i];
              }
              Jtri.set_size(y.size(0), 3);
              k = y.size(0) * 3;
              for (i = 0; i < k; i++) {
                Jtri[i] = y[i];
              }
              mulJt(y, iend, v);
            }
          } else {
            exitg1 = true;
          }
        } else {
          exitg1 = true;
        }
      }
      course.set_size(courselsq.size(0) + 1);
      k = courselsq.size(0);
      for (i = 0; i < k; i++) {
        course[i] = courselsq[i];
      }
      course[courselsq.size(0)] = courselsq[0];
    } else if (std::isnan(course[0])) {
      int b_i;
      int i;
      int n;
      n = course.size(0);
      if (std::isnan(r[r.size(0) - 1])) {
        y.set_size(1, 1);
        y[0] = rtNaN;
      } else if (static_cast<double>(course.size(0)) - 1.0 < r[r.size(0) - 1]) {
        y.set_size(1, 0);
      } else if (std::isinf(r[r.size(0) - 1]) &&
                 (r[r.size(0) - 1] ==
                  static_cast<double>(course.size(0)) - 1.0)) {
        y.set_size(1, 1);
        y[0] = rtNaN;
      } else if (std::floor(r[r.size(0) - 1]) == r[r.size(0) - 1]) {
        double maxiter;
        maxiter = static_cast<double>(course.size(0)) - 1.0;
        y.set_size(1, static_cast<int>(std::floor(maxiter - r[r.size(0) - 1])) +
                          1);
        k = static_cast<int>(std::floor(maxiter - r[r.size(0) - 1]));
        for (i = 0; i <= k; i++) {
          y[i] = r[r.size(0) - 1] + static_cast<double>(i);
        }
      } else {
        eml_float_colon(r[r.size(0) - 1],
                        static_cast<double>(course.size(0)) - 1.0, y);
      }
      if (std::isnan(dx[0])) {
        b_y.set_size(1, 1);
        b_y[0] = rtNaN;
      } else if (dx[0] < 1.0) {
        b_y.set_size(1, 0);
      } else if (std::isinf(dx[0]) && (1.0 == dx[0])) {
        b_y.set_size(1, 1);
        b_y[0] = rtNaN;
      } else {
        k = static_cast<int>(std::floor(dx[0] - 1.0));
        b_y.set_size(1, k + 1);
        for (i = 0; i <= k; i++) {
          b_y[i] = static_cast<double>(i) + 1.0;
        }
      }
      range.set_size(1, y.size(1) + b_y.size(1));
      k = y.size(1);
      for (i = 0; i < k; i++) {
        range[i] = y[i];
      }
      k = b_y.size(1);
      for (i = 0; i < k; i++) {
        range[i + y.size(1)] = b_y[i];
      }
      b_r.set_size(1, range.size(1));
      k = range.size(1);
      for (i = 0; i < k; i++) {
        b_r[i] = static_cast<int>(range[i]);
      }
      ibegin.set_size(range.size(1));
      k = range.size(1);
      for (i = 0; i < k; i++) {
        ibegin[i] = course[static_cast<int>(range[i]) - 1];
      }
      Jtri.set_size(range.size(1), 3);
      k = range.size(1);
      for (i = 0; i < 3; i++) {
        for (b_i = 0; b_i < k; b_i++) {
          Jtri[b_i + Jtri.size(0) * i] =
              waypoints[(static_cast<int>(range[b_i]) + waypoints.size(0) * i) -
                        1];
        }
      }
      fitCourse(Jtri, ibegin);
      k = b_r.size(1);
      for (i = 0; i < k; i++) {
        course[b_r[i] - 1] = ibegin[i];
      }
      course[n - 1] = course[0];
      if (2 > dx.size(0)) {
        i = 0;
        b_i = 0;
      } else {
        i = 1;
        b_i = dx.size(0);
      }
      if (1 > r.size(0) - 1) {
        n = 0;
      } else {
        n = r.size(0) - 1;
      }
      r.set_size(n);
      n = b_i - i;
      for (b_i = 0; b_i < n; b_i++) {
        dx[b_i] = dx[i + b_i];
      }
      dx.set_size(n);
      fillPartitions(waypoints, course, r, dx);
    } else {
      fillPartitions(waypoints, course, r, dx);
    }
  } else {
    int i;
    partitionCourse(course, r, dx);
    ibegin.set_size(r.size(0));
    k = r.size(0);
    for (i = 0; i < k; i++) {
      ibegin[i] = r[i];
    }
    iend.set_size(dx.size(0));
    k = dx.size(0);
    for (i = 0; i < k; i++) {
      iend[i] = dx[i];
    }
    if (std::isnan(course[0])) {
      ibegin.set_size(r.size(0) + 1);
      ibegin[0] = 1.0;
      k = r.size(0);
      for (i = 0; i < k; i++) {
        ibegin[i + 1] = r[i];
      }
    }
    if (std::isnan(course[course.size(0) - 1])) {
      iend.set_size(dx.size(0) + 1);
      k = dx.size(0);
      for (i = 0; i < k; i++) {
        iend[i] = dx[i];
      }
      iend[dx.size(0)] = course.size(0);
    }
    fillPartitions(waypoints, course, ibegin, iend);
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
  array<int, 2U> r;
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
  if (2 > course.size(0)) {
    i = 0;
    i1 = 0;
  } else {
    i = 1;
    i1 = course.size(0);
  }
  loop_ub = i1 - i;
  r.set_size(1, loop_ub);
  for (i1 = 0; i1 < loop_ub; i1++) {
    r[i1] = i + i1;
  }
  loop_ub = r.size(1);
  for (i = 0; i < loop_ub; i++) {
    b_course[r[i]] = x[i];
  }
  if (1 > waypoints.size(0) - 1) {
    loop_ub = 0;
    b_loop_ub = 0;
  } else {
    loop_ub = waypoints.size(0) - 1;
    b_loop_ub = waypoints.size(0) - 1;
  }
  if (2 > waypoints.size(0)) {
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
  loop_ub = i1 - i;
  for (i1 = 0; i1 < loop_ub; i1++) {
    hip[i1] = hip[i + i1];
  }
  hip.set_size(loop_ub);
  loop_ub = i3 - i2;
  for (i = 0; i < loop_ub; i++) {
    b_course[i] = b_course[i2 + i];
  }
  b_course.set_size(loop_ub);
  clothoidG1fit2wp(b_hip, c_course, hip, b_course, k0, k1, a__2, dk0_dc0,
                   dk0_dc1, dk1_dc0, dk1_dc1);
  if (1 > k1.size(0) - 1) {
    loop_ub = 1;
  } else {
    loop_ub = k1.size(0);
  }
  i = (2 <= k0.size(0));
  varargout_1.set_size(loop_ub);
  for (i1 = 0; i1 <= loop_ub - 2; i1++) {
    varargout_1[i1] = k1[i1] - k0[i + i1];
  }
  varargout_1[loop_ub - 1] = k1[k1.size(0) - 1];
  if (2 > dk0_dc1.size(0)) {
    i = 0;
    i1 = 0;
  } else {
    i = 1;
    i1 = dk0_dc1.size(0);
  }
  if (2 > dk1_dc0.size(0)) {
    i2 = 0;
    i3 = 0;
  } else {
    i2 = 1;
    i3 = dk1_dc0.size(0);
  }
  if (1 > waypoints.size(0) - 2) {
    loop_ub = 0;
  } else {
    loop_ub = waypoints.size(0) - 2;
  }
  i4 = (2 <= waypoints.size(0) - 1);
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
  loop_ub = i1 - i;
  for (i1 = 0; i1 < loop_ub; i1++) {
    varargout_2[i1 + varargout_2.size(0) * 2] = -dk0_dc1[i + i1];
  }
  varargout_2[loop_ub + varargout_2.size(0) * 2] = 0.0;
}

//
// Arguments    : const ::coder::array<double, 2U> &waypoints
//                const ::coder::array<double, 1U> &course
//                const ::coder::array<double, 1U> &x
//                ::coder::array<double, 1U> &varargout_1
//                ::coder::array<double, 2U> &varargout_2
// Return Type  : void
//
void fitCourse_anonFcn4(const ::coder::array<double, 2U> &waypoints,
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
  array<int, 2U> r;
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
  if (2 > course.size(0) - 1) {
    i = 0;
    i1 = 0;
  } else {
    i = 1;
    i1 = course.size(0) - 1;
  }
  loop_ub = i1 - i;
  r.set_size(1, loop_ub);
  for (i1 = 0; i1 < loop_ub; i1++) {
    r[i1] = i + i1;
  }
  loop_ub = r.size(1);
  for (i = 0; i < loop_ub; i++) {
    b_course[r[i]] = x[i];
  }
  if (1 > waypoints.size(0) - 1) {
    loop_ub = 0;
    b_loop_ub = 0;
  } else {
    loop_ub = waypoints.size(0) - 1;
    b_loop_ub = waypoints.size(0) - 1;
  }
  if (2 > waypoints.size(0)) {
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
  loop_ub = i1 - i;
  for (i1 = 0; i1 < loop_ub; i1++) {
    hip[i1] = hip[i + i1];
  }
  hip.set_size(loop_ub);
  loop_ub = i3 - i2;
  for (i = 0; i < loop_ub; i++) {
    b_course[i] = b_course[i2 + i];
  }
  b_course.set_size(loop_ub);
  clothoidG1fit2wp(b_hip, c_course, hip, b_course, k0, k1, a__4, dk0_dc0,
                   dk0_dc1, dk1_dc0, dk1_dc1);
  if (1 > k1.size(0) - 1) {
    loop_ub = 0;
  } else {
    loop_ub = k1.size(0) - 1;
  }
  i = (2 <= k0.size(0));
  varargout_1.set_size(loop_ub);
  for (i1 = 0; i1 < loop_ub; i1++) {
    varargout_1[i1] = k1[i1] - k0[i + i1];
  }
  if (2 > dk0_dc1.size(0) - 1) {
    i = 0;
    i1 = 0;
  } else {
    i = 1;
    i1 = dk0_dc1.size(0) - 1;
  }
  if (2 > dk1_dc0.size(0) - 1) {
    i2 = 0;
    i3 = 1;
  } else {
    i2 = 1;
    i3 = dk1_dc0.size(0);
  }
  if (1 > waypoints.size(0) - 2) {
    loop_ub = 2;
  } else {
    loop_ub = waypoints.size(0);
  }
  i4 = (2 <= waypoints.size(0) - 1);
  b_loop_ub = i3 - i2;
  varargout_2.set_size(b_loop_ub, 3);
  for (i3 = 0; i3 <= b_loop_ub - 2; i3++) {
    varargout_2[i3] = dk1_dc0[i2 + i3];
  }
  varargout_2[b_loop_ub - 1] = 0.0;
  for (i2 = 0; i2 <= loop_ub - 3; i2++) {
    varargout_2[i2 + varargout_2.size(0)] = dk1_dc1[i2] - dk0_dc0[i4 + i2];
  }
  loop_ub = i1 - i;
  for (i1 = 0; i1 < loop_ub; i1++) {
    varargout_2[i1 + varargout_2.size(0) * 2] = -dk0_dc1[i + i1];
  }
  varargout_2[loop_ub + varargout_2.size(0) * 2] = 0.0;
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
