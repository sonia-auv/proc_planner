//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: solveMissingCourse.cpp
//
// MATLAB Coder version            : 5.4
// C/C++ source code generated on  : 12-Apr-2022 11:44:16
//

// Include Files
#include "solveMissingCourse.h"
#include "LMFsolve.h"
#include "clothoidG1fit2wp.h"
#include "clothoidG2fitMissingCourse.h"
#include "colon.h"
#include "dclothoidwp.h"
#include "proc_planner_rtwutil.h"
#include "rt_nonfinite.h"
#include "waypointTrajectory.h"
#include "coder_array.h"
#include <cmath>
#include <string.h>

// Function Definitions
//
// Arguments    : coder::array<bool, 1U> &in1
//                const coder::waypointTrajectory *in2
//                int in3
//                int in4
//                int in5
//                int in6
//                int in7
//                int in8
// Return Type  : void
//
void b_binary_expand_op(coder::array<bool, 1U> &in1,
                        const coder::waypointTrajectory *in2, int in3, int in4,
                        int in5, int in6, int in7, int in8)
{
  int b_in8;
  int stride_0_0;
  int stride_1_0;
  int stride_2_0;
  int stride_3_0;
  if ((in8 - in7) + 1 == 1) {
    b_in8 = in6 + 1;
  } else {
    b_in8 = (in8 - in7) + 1;
  }
  if (b_in8 == 1) {
    if ((in5 - in4) + 1 == 1) {
      b_in8 = in3 + 1;
    } else {
      b_in8 = (in5 - in4) + 1;
    }
  } else if ((in8 - in7) + 1 == 1) {
    b_in8 = in6 + 1;
  } else {
    b_in8 = (in8 - in7) + 1;
  }
  in1.set_size(b_in8);
  stride_0_0 = (in3 + 1 != 1);
  stride_1_0 = ((in5 - in4) + 1 != 1);
  stride_2_0 = (in6 + 1 != 1);
  stride_3_0 = ((in8 - in7) + 1 != 1);
  if ((in8 - in7) + 1 == 1) {
    b_in8 = in6 + 1;
  } else {
    b_in8 = (in8 - in7) + 1;
  }
  if (b_in8 == 1) {
    if ((in5 - in4) + 1 == 1) {
      b_in8 = in3 + 1;
    } else {
      b_in8 = (in5 - in4) + 1;
    }
  } else if ((in8 - in7) + 1 == 1) {
    b_in8 = in6 + 1;
  } else {
    b_in8 = (in8 - in7) + 1;
  }
  for (int i{0}; i < b_in8; i++) {
    in1[i] =
        ((in2->Waypoints[i * stride_0_0] ==
          in2->Waypoints[in4 + i * stride_1_0]) &&
         (in2->Waypoints[i * stride_2_0 + in2->Waypoints.size(0)] ==
          in2->Waypoints[(in7 + i * stride_3_0) + in2->Waypoints.size(0)]));
  }
}

//
// Arguments    : const ::coder::array<double, 2U> &waypoints
//                ::coder::array<double, 1U> &course
// Return Type  : void
//
namespace coder {
namespace matlabshared {
namespace tracking {
namespace internal {
namespace scenario {
void clothoidG2FitMissingCourse(const ::coder::array<double, 2U> &waypoints,
                                ::coder::array<double, 1U> &course)
{
  array<double, 2U> Jtri;
  array<double, 2U> b_y;
  array<double, 2U> range;
  array<double, 2U> y;
  array<double, 1U> dx;
  array<double, 1U> ibegin;
  array<double, 1U> iend;
  array<double, 1U> r;
  array<double, 1U> v;
  array<int, 2U> b_r;
  array<bool, 1U> x;
  double lambda;
  double lambdac;
  int b_outsize[2];
  int outsize[2];
  if (course.size(0) == 1) {
    int loop_ub;
    x.set_size(course.size(0));
    loop_ub = course.size(0);
    for (int i{0}; i < loop_ub; i++) {
      x[i] = std::isnan(course[i]);
    }
    if (x[0]) {
      course.set_size(1);
      course[0] = 0.0;
    }
  } else {
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
        int loop_ub;
        int n;
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
        dclothoidwp(r, dx, ibegin, v);
        course.set_size(waypoints.size(0));
        loop_ub = waypoints.size(0);
        for (i = 0; i < loop_ub; i++) {
          course[i] = 0.0;
        }
        course[0] = rt_atan2d_snf(v[1] - v[0], ibegin[1] - ibegin[0]);
        course[waypoints.size(0) - 1] = rt_atan2d_snf(
            v[v.size(0) - 1] - v[v.size(0) - 2],
            ibegin[ibegin.size(0) - 1] - ibegin[ibegin.size(0) - 2]);
        i = waypoints.size(0);
        for (loop_ub = 0; loop_ub <= i - 3; loop_ub++) {
          n = static_cast<int>((static_cast<double>(loop_ub) + 1.0) * 128.0 +
                               1.0) -
              1;
          k = (loop_ub + 1) * 128 - 1;
          course[loop_ub + 1] =
              rt_atan2d_snf(v[n] - v[k], ibegin[n] - ibegin[k]);
        }
        if (waypoints.size(0) - 1 < 1) {
          loop_ub = 0;
        } else {
          loop_ub = waypoints.size(0) - 1;
        }
        course.set_size(loop_ub);
        maxiter = 100.0 * static_cast<double>(loop_ub);
        fitLoopCourse_anonFcn1(waypoints, course, r, Jtri);
        mulJt(Jtri, r, v);
        S = 0.0;
        n = r.size(0);
        for (i = 0; i < n; i++) {
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
          n = dx.size(0);
          ibegin.set_size(dx.size(0));
          for (k = 0; k < n; k++) {
            ibegin[k] = std::abs(dx[k]);
          }
          if (ibegin.size(0) == loop_ub) {
            x.set_size(ibegin.size(0));
            n = ibegin.size(0);
            for (i = 0; i < n; i++) {
              x[i] = (ibegin[i] >= 1.0E-7);
            }
          } else {
            j_binary_expand_op(x, ibegin, outsize);
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
            if (ibegin.size(0) == loop_ub) {
              x.set_size(ibegin.size(0));
              n = ibegin.size(0);
              for (i = 0; i < n; i++) {
                x[i] = (ibegin[i] >= 1.0E-7);
              }
            } else {
              j_binary_expand_op(x, ibegin, b_outsize);
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
              if (course.size(0) == dx.size(0)) {
                ibegin.set_size(course.size(0));
                n = course.size(0);
                for (i = 0; i < n; i++) {
                  ibegin[i] = course[i] - dx[i];
                }
              } else {
                minus(ibegin, course, dx);
              }
              fitLoopCourse_anonFcn1(waypoints, ibegin, iend, y);
              b_iend = 0.0;
              n = iend.size(0);
              for (i = 0; i < n; i++) {
                b_iend += iend[i] * iend[i];
              }
              fletcher(S, b_iend, dx, v, Jtri, &lambda, &lambdac);
              if (b_iend < S) {
                S = b_iend;
                course.set_size(ibegin.size(0));
                n = ibegin.size(0);
                for (i = 0; i < n; i++) {
                  course[i] = ibegin[i];
                }
                r.set_size(iend.size(0));
                n = iend.size(0);
                for (i = 0; i < n; i++) {
                  r[i] = iend[i];
                }
                Jtri.set_size(y.size(0), 3);
                n = y.size(0) * 3;
                for (i = 0; i < n; i++) {
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
        maxiter = course[0];
        i = course.size(0);
        course.set_size(course.size(0) + 1);
        course[i] = maxiter;
      } else if (std::isnan(course[0])) {
        int i;
        int loop_ub;
        int n;
        n = course.size(0);
        if (std::isnan(r[r.size(0) - 1])) {
          y.set_size(1, 1);
          y[0] = rtNaN;
        } else if (static_cast<double>(course.size(0)) - 1.0 <
                   r[r.size(0) - 1]) {
          y.set_size(1, 0);
        } else if (std::isinf(r[r.size(0) - 1]) &&
                   (r[r.size(0) - 1] ==
                    static_cast<double>(course.size(0)) - 1.0)) {
          y.set_size(1, 1);
          y[0] = rtNaN;
        } else if (std::floor(r[r.size(0) - 1]) == r[r.size(0) - 1]) {
          double maxiter;
          maxiter = static_cast<double>(course.size(0)) - 1.0;
          y.set_size(1, static_cast<int>(maxiter - r[r.size(0) - 1]) + 1);
          loop_ub = static_cast<int>(maxiter - r[r.size(0) - 1]);
          for (i = 0; i <= loop_ub; i++) {
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
        } else {
          b_y.set_size(1, static_cast<int>(dx[0] - 1.0) + 1);
          loop_ub = static_cast<int>(dx[0] - 1.0);
          for (i = 0; i <= loop_ub; i++) {
            b_y[i] = static_cast<double>(i) + 1.0;
          }
        }
        range.set_size(1, y.size(1) + b_y.size(1));
        loop_ub = y.size(1);
        for (i = 0; i < loop_ub; i++) {
          range[i] = y[i];
        }
        loop_ub = b_y.size(1);
        for (i = 0; i < loop_ub; i++) {
          range[i + y.size(1)] = b_y[i];
        }
        b_r.set_size(1, range.size(1));
        loop_ub = range.size(1);
        for (i = 0; i < loop_ub; i++) {
          b_r[i] = static_cast<int>(range[i]);
        }
        ibegin.set_size(range.size(1));
        loop_ub = range.size(1);
        for (i = 0; i < loop_ub; i++) {
          ibegin[i] = course[static_cast<int>(range[i]) - 1];
        }
        Jtri.set_size(range.size(1), 3);
        loop_ub = range.size(1);
        for (i = 0; i < 3; i++) {
          for (k = 0; k < loop_ub; k++) {
            Jtri[k + Jtri.size(0) * i] =
                waypoints[(static_cast<int>(range[k]) + waypoints.size(0) * i) -
                          1];
          }
        }
        fitCourse(Jtri, ibegin);
        loop_ub = b_r.size(1);
        for (i = 0; i < loop_ub; i++) {
          course[b_r[i] - 1] = ibegin[i];
        }
        course[n - 1] = course[0];
        if (dx.size(0) < 2) {
          i = 0;
          k = 0;
        } else {
          i = 1;
          k = dx.size(0);
        }
        if (r.size(0) - 1 < 1) {
          n = 0;
        } else {
          n = r.size(0) - 1;
        }
        r.set_size(n);
        n = k - i;
        for (k = 0; k < n; k++) {
          dx[k] = dx[i + k];
        }
        dx.set_size(n);
        fillPartitions(waypoints, course, r, dx);
      } else {
        fillPartitions(waypoints, course, r, dx);
      }
    } else {
      int loop_ub;
      partitionCourse(course, r, dx);
      ibegin.set_size(r.size(0));
      loop_ub = r.size(0);
      for (int i{0}; i < loop_ub; i++) {
        ibegin[i] = r[i];
      }
      iend.set_size(dx.size(0));
      loop_ub = dx.size(0);
      for (int i{0}; i < loop_ub; i++) {
        iend[i] = dx[i];
      }
      if (std::isnan(course[0])) {
        ibegin.set_size(r.size(0) + 1);
        ibegin[0] = 1.0;
        loop_ub = r.size(0);
        for (int i{0}; i < loop_ub; i++) {
          ibegin[i + 1] = r[i];
        }
      }
      if (std::isnan(course[course.size(0) - 1])) {
        iend.set_size(dx.size(0) + 1);
        loop_ub = dx.size(0);
        for (int i{0}; i < loop_ub; i++) {
          iend[i] = dx[i];
        }
        iend[dx.size(0)] = course.size(0);
      }
      fillPartitions(waypoints, course, ibegin, iend);
    }
  }
}

} // namespace scenario
} // namespace internal
} // namespace tracking
} // namespace matlabshared
} // namespace coder

//
// File trailer for solveMissingCourse.cpp
//
// [EOF]
//
