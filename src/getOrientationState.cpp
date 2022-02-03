//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: getOrientationState.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 02-Feb-2022 17:45:08
//

// Include Files
#include "getOrientationState.h"
#include "cross.h"
#include "dot.h"
#include "quaternion.h"
#include "rt_nonfinite.h"
#include "sum.h"
#include "coder_array.h"
#include <cmath>
#include <string.h>

// Function Declarations
namespace coder {
namespace fusion {
namespace scenario {
namespace internal {
static void bsxdiv(const ::coder::array<double, 2U> &x,
                   const ::coder::array<double, 2U> &y,
                   ::coder::array<double, 2U> &z);

static void bsxmul(const ::coder::array<double, 2U> &x,
                   const ::coder::array<double, 2U> &y,
                   ::coder::array<double, 2U> &z);

} // namespace internal
} // namespace scenario
} // namespace fusion
} // namespace coder

// Function Definitions
//
// Arguments    : const ::coder::array<double, 2U> &x
//                const ::coder::array<double, 2U> &y
//                ::coder::array<double, 2U> &z
// Return Type  : void
//
namespace coder {
namespace fusion {
namespace scenario {
namespace internal {
static void bsxdiv(const ::coder::array<double, 2U> &x,
                   const ::coder::array<double, 2U> &y,
                   ::coder::array<double, 2U> &z)
{
  int acoef;
  int bcoef;
  bcoef = y.size(0);
  acoef = x.size(0);
  if (bcoef <= acoef) {
    acoef = bcoef;
  }
  if (y.size(0) == 1) {
    acoef = x.size(0);
  } else if (x.size(0) == 1) {
    acoef = y.size(0);
  } else if (x.size(0) == y.size(0)) {
    acoef = x.size(0);
  }
  z.set_size(acoef, 3);
  bcoef = y.size(0);
  acoef = x.size(0);
  if (bcoef <= acoef) {
    acoef = bcoef;
  }
  if (y.size(0) == 1) {
    acoef = x.size(0);
  } else if (x.size(0) == 1) {
    acoef = y.size(0);
  } else if (x.size(0) == y.size(0)) {
    acoef = x.size(0);
  }
  if (acoef != 0) {
    int b_bcoef;
    bcoef = (y.size(1) != 1);
    acoef = (x.size(0) != 1);
    b_bcoef = (y.size(0) != 1);
    for (int k{0}; k < 3; k++) {
      int i;
      int varargin_3;
      varargin_3 = bcoef * k;
      i = z.size(0) - 1;
      for (int b_k{0}; b_k <= i; b_k++) {
        z[b_k + z.size(0) * k] = x[acoef * b_k + x.size(0) * k] /
                                 y[b_bcoef * b_k + y.size(0) * varargin_3];
      }
    }
  }
}

//
// Arguments    : const ::coder::array<double, 2U> &x
//                const ::coder::array<double, 2U> &y
//                ::coder::array<double, 2U> &z
// Return Type  : void
//
static void bsxmul(const ::coder::array<double, 2U> &x,
                   const ::coder::array<double, 2U> &y,
                   ::coder::array<double, 2U> &z)
{
  int acoef;
  int b_acoef;
  acoef = y.size(0);
  b_acoef = x.size(0);
  if (acoef <= b_acoef) {
    b_acoef = acoef;
  }
  if (y.size(0) == 1) {
    b_acoef = x.size(0);
  } else if (x.size(0) == 1) {
    b_acoef = y.size(0);
  } else if (x.size(0) == y.size(0)) {
    b_acoef = x.size(0);
  }
  z.set_size(b_acoef, 3);
  acoef = y.size(0);
  b_acoef = x.size(0);
  if (acoef <= b_acoef) {
    b_acoef = acoef;
  }
  if (y.size(0) == 1) {
    b_acoef = x.size(0);
  } else if (x.size(0) == 1) {
    b_acoef = y.size(0);
  } else if (x.size(0) == y.size(0)) {
    b_acoef = x.size(0);
  }
  if (b_acoef != 0) {
    int bcoef;
    acoef = (x.size(1) != 1);
    b_acoef = (x.size(0) != 1);
    bcoef = (y.size(0) != 1);
    for (int k{0}; k < 3; k++) {
      int i;
      int varargin_2;
      varargin_2 = acoef * k;
      i = z.size(0) - 1;
      for (int b_k{0}; b_k <= i; b_k++) {
        z[b_k + z.size(0) * k] = x[b_acoef * b_k + x.size(0) * varargin_2] *
                                 y[bcoef * b_k + y.size(0) * k];
      }
    }
  }
}

//
// Arguments    : double t
//                double dt
//                const quaternion *qi
//                const double a[9]
//                const double b[9]
//                const double c[6]
//                const double d[3]
//                quaternion *q
//                double angVel[3]
//                double angAcc[3]
//                double angJerk[3]
// Return Type  : void
//
void slew3(double t, double dt, const quaternion *qi, const double a[9],
           const double b[9], const double c[6], const double d[3],
           quaternion *q, double angVel[3], double angAcc[3], double angJerk[3])
{
  b_quaternion deltaQ;
  array<double, 2U> b_ang;
  array<double, 2U> b_temp1;
  array<double, 2U> ca;
  array<double, 2U> r;
  array<double, 2U> r1;
  array<double, 2U> r2;
  array<double, 2U> r3;
  array<double, 2U> r5;
  array<double, 2U> r6;
  array<double, 2U> sa;
  array<double, 2U> temp0;
  array<double, 2U> temp1;
  array<double, 2U> temp2;
  array<double, 2U> th3;
  array<double, 2U> u;
  array<double, 2U> udot;
  array<double, 2U> w;
  array<double, 2U> wd1;
  array<double, 2U> wd1xu;
  array<double, 2U> wd2;
  array<double, 2U> wd2xu;
  array<double, 1U> b_b;
  array<double, 1U> b_x;
  array<double, 1U> r4;
  array<double, 1U> r7;
  array<double, 1U> r8;
  array<double, 1U> thd1;
  array<double, 1U> thd2;
  array<double, 1U> ut2;
  array<double, 1U> w2;
  array<double, 1U> wwd;
  array<signed char, 2U> ii;
  double qimag[3];
  q->init();
  angVel[0] = 0.0;
  angAcc[0] = 0.0;
  angJerk[0] = 0.0;
  angVel[1] = 0.0;
  angAcc[1] = 0.0;
  angJerk[1] = 0.0;
  angVel[2] = 0.0;
  angAcc[2] = 0.0;
  angJerk[2] = 0.0;
  if (!(dt <= 0.0)) {
    double ang;
    double b_d;
    double b_t;
    double th0_idx_0;
    double th0_idx_1;
    double x;
    double x2;
    int bcoef;
    int i;
    x = t / dt;
    x2 = (x - 1.0) * (x - 1.0);
    deltaQ.a = 1.0;
    deltaQ.b = 0.0;
    deltaQ.c = 0.0;
    deltaQ.d = 0.0;
    b_d = ((a[6] * x + (x - 1.0) * a[3]) * x + x2 * a[0]) * x;
    th0_idx_0 = b_d;
    angVel[0] = (b[6] * x + (x - 1.0) * b[3]) * x + x2 * b[0];
    angAcc[0] = c[3] * x + (x - 1.0) * c[0];
    qimag[0] = b_d * b_d;
    b_d = ((a[7] * x + (x - 1.0) * a[4]) * x + x2 * a[1]) * x;
    th0_idx_1 = b_d;
    angVel[1] = (b[7] * x + (x - 1.0) * b[4]) * x + x2 * b[1];
    angAcc[1] = c[4] * x + (x - 1.0) * c[1];
    qimag[1] = b_d * b_d;
    b_d = ((a[8] * x + (x - 1.0) * a[5]) * x + x2 * a[2]) * x;
    angVel[2] = (b[8] * x + (x - 1.0) * b[5]) * x + x2 * b[2];
    angAcc[2] = c[5] * x + (x - 1.0) * c[2];
    x = std::sqrt((qimag[0] + qimag[1]) + b_d * b_d);
    x2 = std::sin(x / 2.0);
    if (x != 0.0) {
      deltaQ.a = std::cos(x / 2.0);
      deltaQ.b = th0_idx_0 / x * x2;
      deltaQ.c = th0_idx_1 / x * x2;
      deltaQ.d = b_d / x * x2;
    }
    q->a.set_size(1, qi->a.size(1));
    bcoef = qi->a.size(1);
    for (i = 0; i < bcoef; i++) {
      q->a[i] =
          ((qi->a[i] * deltaQ.a - qi->b[i] * deltaQ.b) - qi->c[i] * deltaQ.c) -
          qi->d[i] * deltaQ.d;
    }
    q->b.set_size(1, qi->a.size(1));
    bcoef = qi->a.size(1);
    for (i = 0; i < bcoef; i++) {
      q->b[i] =
          ((qi->a[i] * deltaQ.b + qi->b[i] * deltaQ.a) + qi->c[i] * deltaQ.d) -
          qi->d[i] * deltaQ.c;
    }
    q->c.set_size(1, qi->a.size(1));
    bcoef = qi->a.size(1);
    for (i = 0; i < bcoef; i++) {
      q->c[i] =
          ((qi->a[i] * deltaQ.c - qi->b[i] * deltaQ.d) + qi->c[i] * deltaQ.a) +
          qi->d[i] * deltaQ.b;
    }
    q->d.set_size(1, qi->a.size(1));
    bcoef = qi->a.size(1);
    for (i = 0; i < bcoef; i++) {
      q->d[i] =
          ((qi->a[i] * deltaQ.d + qi->b[i] * deltaQ.c) - qi->c[i] * deltaQ.b) +
          qi->d[i] * deltaQ.a;
    }
    x = 3.3121686421112381E-170;
    x2 = std::abs(th0_idx_0);
    if (x2 > 3.3121686421112381E-170) {
      ang = 1.0;
      x = x2;
    } else {
      b_t = x2 / 3.3121686421112381E-170;
      ang = b_t * b_t;
    }
    x2 = std::abs(th0_idx_1);
    if (x2 > x) {
      b_t = x / x2;
      ang = ang * b_t * b_t + 1.0;
      x = x2;
    } else {
      b_t = x2 / x;
      ang += b_t * b_t;
    }
    x2 = std::abs(b_d);
    if (x2 > x) {
      b_t = x / x2;
      ang = ang * b_t * b_t + 1.0;
      x = x2;
    } else {
      b_t = x2 / x;
      ang += b_t * b_t;
    }
    ang = x * std::sqrt(ang);
    qimag[0] = th0_idx_0 / ang;
    qimag[1] = th0_idx_1 / ang;
    qimag[2] = b_d / ang;
    if (ang <= 0.0) {
      ii.set_size(1, 1);
      ii[0] = 1;
      if (ii.size(1) == 0) {
        bcoef = 0;
      } else {
        bcoef = 1;
      }
    } else {
      bcoef = 0;
    }
    for (i = 0; i < 3; i++) {
      if (0 <= bcoef - 1) {
        qimag[i] = 0.0;
      }
    }
    angJerk[0] = d[0] - 0.5 * (angVel[1] * angAcc[2] - angAcc[1] * angVel[2]);
    angJerk[1] = d[1] - 0.5 * (angAcc[0] * angVel[2] - angVel[0] * angAcc[2]);
    angJerk[2] = d[2] - 0.5 * (angVel[0] * angAcc[1] - angAcc[0] * angVel[1]);
    if (ang > 1.0E-6) {
      int acoef;
      int b_k;
      int k;
      b_ang.set_size(1, 1);
      b_ang[0] = ang;
      wd2xu.set_size(1, 3);
      for (i = 0; i < 3; i++) {
        wd2xu[wd2xu.size(0) * i] = angVel[i];
      }
      wd2.set_size(1, 3);
      for (i = 0; i < 3; i++) {
        wd2[wd2.size(0) * i] = angAcc[i];
      }
      th3.set_size(1, 3);
      for (i = 0; i < 3; i++) {
        th3[th3.size(0) * i] = d[i];
      }
      u.set_size(1, 3);
      for (i = 0; i < 3; i++) {
        u[u.size(0) * i] = qimag[i];
      }
      ca.set_size(1, 1);
      ca[0] = ang;
      ca[0] = std::cos(ca[0]);
      sa.set_size(1, 1);
      sa[0] = ang;
      sa[0] = std::sin(sa[0]);
      cross(u, wd2xu, r);
      bsxdiv(r, b_ang, w);
      cross(w, u, udot);
      dot(u, wd2xu, thd1);
      bcoef = u.size(0);
      acoef = thd1.size(0);
      if (bcoef <= acoef) {
        acoef = bcoef;
      }
      if (u.size(0) == 1) {
        acoef = thd1.size(0);
      } else if (thd1.size(0) == 1) {
        acoef = u.size(0);
      } else if (thd1.size(0) == u.size(0)) {
        acoef = thd1.size(0);
      }
      r.set_size(acoef, 3);
      bcoef = u.size(0);
      acoef = thd1.size(0);
      if (bcoef <= acoef) {
        acoef = bcoef;
      }
      if (u.size(0) == 1) {
        acoef = thd1.size(0);
      } else if (thd1.size(0) == 1) {
        acoef = u.size(0);
      } else if (thd1.size(0) == u.size(0)) {
        acoef = thd1.size(0);
      }
      if (acoef != 0) {
        acoef = (thd1.size(0) != 1);
        bcoef = (u.size(0) != 1);
        for (k = 0; k < 3; k++) {
          i = r.size(0) - 1;
          for (b_k = 0; b_k <= i; b_k++) {
            r[b_k + r.size(0) * k] =
                thd1[acoef * b_k] * u[bcoef * b_k + u.size(0) * k];
          }
        }
      }
      bsxmul(sa, udot, r1);
      r2.set_size(1, 1);
      r2[0] = 1.0 - ca[0];
      bsxmul(r2, w, r3);
      bcoef = r.size(0) * 3;
      r.set_size(r.size(0), 3);
      for (i = 0; i < bcoef; i++) {
        r[i] = (r[i] + r1[i]) - r3[i];
      }
      dot(udot, wd2xu, thd2);
      dot(u, wd2, r4);
      bcoef = thd2.size(0);
      for (i = 0; i < bcoef; i++) {
        thd2[i] = thd2[i] + r4[i];
      }
      cross(u, wd2, temp1);
      r4.set_size(thd1.size(0));
      bcoef = thd1.size(0);
      for (i = 0; i < bcoef; i++) {
        r4[i] = 2.0 * thd1[i];
      }
      bcoef = w.size(0);
      acoef = r4.size(0);
      if (bcoef <= acoef) {
        acoef = bcoef;
      }
      if (w.size(0) == 1) {
        acoef = r4.size(0);
      } else if (r4.size(0) == 1) {
        acoef = w.size(0);
      } else if (r4.size(0) == w.size(0)) {
        acoef = r4.size(0);
      }
      r1.set_size(acoef, 3);
      bcoef = w.size(0);
      acoef = r4.size(0);
      if (bcoef <= acoef) {
        acoef = bcoef;
      }
      if (w.size(0) == 1) {
        acoef = r4.size(0);
      } else if (r4.size(0) == 1) {
        acoef = w.size(0);
      } else if (r4.size(0) == w.size(0)) {
        acoef = r4.size(0);
      }
      if (acoef != 0) {
        acoef = (r4.size(0) != 1);
        bcoef = (w.size(0) != 1);
        for (k = 0; k < 3; k++) {
          i = r1.size(0) - 1;
          for (b_k = 0; b_k <= i; b_k++) {
            r1[b_k + r1.size(0) * k] =
                r4[acoef * b_k] * w[bcoef * b_k + w.size(0) * k];
          }
        }
      }
      b_temp1.set_size(temp1.size(0), 3);
      bcoef = temp1.size(0) * 3;
      for (i = 0; i < bcoef; i++) {
        b_temp1[i] = temp1[i] - r1[i];
      }
      bsxdiv(b_temp1, b_ang, wd1);
      cross(wd1, u, wd1xu);
      bcoef = u.size(0);
      acoef = thd1.size(0);
      if (bcoef <= acoef) {
        acoef = bcoef;
      }
      if (u.size(0) == 1) {
        acoef = thd1.size(0);
      } else if (thd1.size(0) == 1) {
        acoef = u.size(0);
      } else if (thd1.size(0) == u.size(0)) {
        acoef = thd1.size(0);
      }
      temp0.set_size(acoef, 3);
      bcoef = u.size(0);
      acoef = thd1.size(0);
      if (bcoef <= acoef) {
        acoef = bcoef;
      }
      if (u.size(0) == 1) {
        acoef = thd1.size(0);
      } else if (thd1.size(0) == 1) {
        acoef = u.size(0);
      } else if (thd1.size(0) == u.size(0)) {
        acoef = thd1.size(0);
      }
      if (acoef != 0) {
        acoef = (thd1.size(0) != 1);
        bcoef = (u.size(0) != 1);
        for (k = 0; k < 3; k++) {
          i = temp0.size(0) - 1;
          for (b_k = 0; b_k <= i; b_k++) {
            temp0[b_k + temp0.size(0) * k] =
                thd1[acoef * b_k] * u[bcoef * b_k + u.size(0) * k];
          }
        }
      }
      bcoef = temp0.size(0) * 3;
      temp0.set_size(temp0.size(0), 3);
      for (i = 0; i < bcoef; i++) {
        temp0[i] = temp0[i] - w[i];
      }
      cross(r, temp0, temp1);
      bcoef = u.size(0);
      acoef = thd2.size(0);
      if (bcoef <= acoef) {
        acoef = bcoef;
      }
      if (u.size(0) == 1) {
        acoef = thd2.size(0);
      } else if (thd2.size(0) == 1) {
        acoef = u.size(0);
      } else if (thd2.size(0) == u.size(0)) {
        acoef = thd2.size(0);
      }
      r1.set_size(acoef, 3);
      bcoef = u.size(0);
      acoef = thd2.size(0);
      if (bcoef <= acoef) {
        acoef = bcoef;
      }
      if (u.size(0) == 1) {
        acoef = thd2.size(0);
      } else if (thd2.size(0) == 1) {
        acoef = u.size(0);
      } else if (thd2.size(0) == u.size(0)) {
        acoef = thd2.size(0);
      }
      if (acoef != 0) {
        acoef = (thd2.size(0) != 1);
        bcoef = (u.size(0) != 1);
        for (k = 0; k < 3; k++) {
          i = r1.size(0) - 1;
          for (b_k = 0; b_k <= i; b_k++) {
            r1[b_k + r1.size(0) * k] =
                thd2[acoef * b_k] * u[bcoef * b_k + u.size(0) * k];
          }
        }
      }
      bsxmul(sa, wd1xu, r3);
      r2.set_size(1, 1);
      r2[0] = 1.0 - ca[0];
      bsxmul(r2, wd1, r5);
      bcoef = udot.size(0);
      acoef = thd1.size(0);
      if (bcoef <= acoef) {
        acoef = bcoef;
      }
      if (udot.size(0) == 1) {
        acoef = thd1.size(0);
      } else if (thd1.size(0) == 1) {
        acoef = udot.size(0);
      } else if (thd1.size(0) == udot.size(0)) {
        acoef = thd1.size(0);
      }
      r6.set_size(acoef, 3);
      bcoef = udot.size(0);
      acoef = thd1.size(0);
      if (bcoef <= acoef) {
        acoef = bcoef;
      }
      if (udot.size(0) == 1) {
        acoef = thd1.size(0);
      } else if (thd1.size(0) == 1) {
        acoef = udot.size(0);
      } else if (thd1.size(0) == udot.size(0)) {
        acoef = thd1.size(0);
      }
      if (acoef != 0) {
        acoef = (thd1.size(0) != 1);
        bcoef = (udot.size(0) != 1);
        for (k = 0; k < 3; k++) {
          i = r6.size(0) - 1;
          for (b_k = 0; b_k <= i; b_k++) {
            r6[b_k + r6.size(0) * k] =
                thd1[acoef * b_k] * udot[bcoef * b_k + udot.size(0) * k];
          }
        }
      }
      bcoef = r1.size(0) * 3;
      r1.set_size(r1.size(0), 3);
      for (i = 0; i < bcoef; i++) {
        r1[i] = (((r1[i] + r3[i]) - r5[i]) + r6[i]) + temp1[i];
      }
      b_temp1.set_size(w.size(0), 3);
      bcoef = w.size(0) * 3;
      for (i = 0; i < bcoef; i++) {
        b_temp1[i] = w[i] * w[i];
      }
      sum(b_temp1, w2);
      dot(u, wd2xu, r4);
      dot(wd1xu, wd2xu, r7);
      dot(udot, wd2, b_b);
      dot(u, th3, r8);
      cross(wd2xu, wd2, r3);
      bsxdiv(r3, b_ang, temp1);
      cross(u, th3, temp2);
      b_temp1.set_size(1, 3);
      for (i = 0; i < 3; i++) {
        b_temp1[i] = wd2xu[i] * wd2xu[i];
      }
      sum(b_temp1, b_x);
      dot(u, wd2, ut2);
      dot(w, wd1, wwd);
      bcoef = b_x.size(0);
      for (i = 0; i < bcoef; i++) {
        b_x[i] = 2.0 * (b_x[i] / ang + ut2[i]);
      }
      bcoef = w.size(0);
      acoef = b_x.size(0);
      if (bcoef <= acoef) {
        acoef = bcoef;
      }
      if (w.size(0) == 1) {
        acoef = b_x.size(0);
      } else if (b_x.size(0) == 1) {
        acoef = w.size(0);
      } else if (b_x.size(0) == w.size(0)) {
        acoef = b_x.size(0);
      }
      r3.set_size(acoef, 3);
      bcoef = w.size(0);
      acoef = b_x.size(0);
      if (bcoef <= acoef) {
        acoef = bcoef;
      }
      if (w.size(0) == 1) {
        acoef = b_x.size(0);
      } else if (b_x.size(0) == 1) {
        acoef = w.size(0);
      } else if (b_x.size(0) == w.size(0)) {
        acoef = b_x.size(0);
      }
      if (acoef != 0) {
        acoef = (b_x.size(0) != 1);
        bcoef = (w.size(0) != 1);
        for (k = 0; k < 3; k++) {
          i = r3.size(0) - 1;
          for (b_k = 0; b_k <= i; b_k++) {
            r3[b_k + r3.size(0) * k] =
                b_x[acoef * b_k] * w[bcoef * b_k + w.size(0) * k];
          }
        }
      }
      b_x.set_size(thd1.size(0));
      bcoef = thd1.size(0);
      for (i = 0; i < bcoef; i++) {
        b_x[i] = 4.0 * thd1[i];
      }
      bcoef = wd1.size(0);
      acoef = b_x.size(0);
      if (bcoef <= acoef) {
        acoef = bcoef;
      }
      if (wd1.size(0) == 1) {
        acoef = b_x.size(0);
      } else if (b_x.size(0) == 1) {
        acoef = wd1.size(0);
      } else if (b_x.size(0) == wd1.size(0)) {
        acoef = b_x.size(0);
      }
      r5.set_size(acoef, 3);
      bcoef = wd1.size(0);
      acoef = b_x.size(0);
      if (bcoef <= acoef) {
        acoef = bcoef;
      }
      if (wd1.size(0) == 1) {
        acoef = b_x.size(0);
      } else if (b_x.size(0) == 1) {
        acoef = wd1.size(0);
      } else if (b_x.size(0) == wd1.size(0)) {
        acoef = b_x.size(0);
      }
      if (acoef != 0) {
        acoef = (b_x.size(0) != 1);
        bcoef = (wd1.size(0) != 1);
        for (k = 0; k < 3; k++) {
          i = r5.size(0) - 1;
          for (b_k = 0; b_k <= i; b_k++) {
            r5[b_k + r5.size(0) * k] =
                b_x[acoef * b_k] * wd1[bcoef * b_k + wd1.size(0) * k];
          }
        }
      }
      b_temp1.set_size(temp1.size(0), 3);
      bcoef = temp1.size(0) * 3;
      for (i = 0; i < bcoef; i++) {
        b_temp1[i] = ((temp1[i] + temp2[i]) - r3[i]) - r5[i];
      }
      bsxdiv(b_temp1, b_ang, wd2);
      bcoef = u.size(0);
      acoef = thd2.size(0);
      if (bcoef <= acoef) {
        acoef = bcoef;
      }
      if (u.size(0) == 1) {
        acoef = thd2.size(0);
      } else if (thd2.size(0) == 1) {
        acoef = u.size(0);
      } else if (thd2.size(0) == u.size(0)) {
        acoef = thd2.size(0);
      }
      r3.set_size(acoef, 3);
      bcoef = u.size(0);
      acoef = thd2.size(0);
      if (bcoef <= acoef) {
        acoef = bcoef;
      }
      if (u.size(0) == 1) {
        acoef = thd2.size(0);
      } else if (thd2.size(0) == 1) {
        acoef = u.size(0);
      } else if (thd2.size(0) == u.size(0)) {
        acoef = thd2.size(0);
      }
      if (acoef != 0) {
        acoef = (thd2.size(0) != 1);
        bcoef = (u.size(0) != 1);
        for (k = 0; k < 3; k++) {
          i = r3.size(0) - 1;
          for (b_k = 0; b_k <= i; b_k++) {
            r3[b_k + r3.size(0) * k] =
                thd2[acoef * b_k] * u[bcoef * b_k + u.size(0) * k];
          }
        }
      }
      bcoef = udot.size(0);
      acoef = thd1.size(0);
      if (bcoef <= acoef) {
        acoef = bcoef;
      }
      if (udot.size(0) == 1) {
        acoef = thd1.size(0);
      } else if (thd1.size(0) == 1) {
        acoef = udot.size(0);
      } else if (thd1.size(0) == udot.size(0)) {
        acoef = thd1.size(0);
      }
      r5.set_size(acoef, 3);
      bcoef = udot.size(0);
      acoef = thd1.size(0);
      if (bcoef <= acoef) {
        acoef = bcoef;
      }
      if (udot.size(0) == 1) {
        acoef = thd1.size(0);
      } else if (thd1.size(0) == 1) {
        acoef = udot.size(0);
      } else if (thd1.size(0) == udot.size(0)) {
        acoef = thd1.size(0);
      }
      if (acoef != 0) {
        acoef = (thd1.size(0) != 1);
        bcoef = (udot.size(0) != 1);
        for (k = 0; k < 3; k++) {
          i = r5.size(0) - 1;
          for (b_k = 0; b_k <= i; b_k++) {
            r5[b_k + r5.size(0) * k] =
                thd1[acoef * b_k] * udot[bcoef * b_k + udot.size(0) * k];
          }
        }
      }
      r6.set_size(r3.size(0), 3);
      bcoef = r3.size(0) * 3;
      for (i = 0; i < bcoef; i++) {
        r6[i] = (r3[i] + r5[i]) - wd1[i];
      }
      cross(r, r6, temp1);
      cross(r1, temp0, temp2);
      bcoef = r7.size(0);
      for (i = 0; i < bcoef; i++) {
        r7[i] = ((r7[i] - w2[i] * r4[i]) + 2.0 * b_b[i]) + r8[i];
      }
      bcoef = u.size(0);
      acoef = r7.size(0);
      if (bcoef <= acoef) {
        acoef = bcoef;
      }
      if (u.size(0) == 1) {
        acoef = r7.size(0);
      } else if (r7.size(0) == 1) {
        acoef = u.size(0);
      } else if (r7.size(0) == u.size(0)) {
        acoef = r7.size(0);
      }
      r3.set_size(acoef, 3);
      bcoef = u.size(0);
      acoef = r7.size(0);
      if (bcoef <= acoef) {
        acoef = bcoef;
      }
      if (u.size(0) == 1) {
        acoef = r7.size(0);
      } else if (r7.size(0) == 1) {
        acoef = u.size(0);
      } else if (r7.size(0) == u.size(0)) {
        acoef = r7.size(0);
      }
      if (acoef != 0) {
        acoef = (r7.size(0) != 1);
        bcoef = (u.size(0) != 1);
        for (k = 0; k < 3; k++) {
          i = r3.size(0) - 1;
          for (b_k = 0; b_k <= i; b_k++) {
            r3[b_k + r3.size(0) * k] =
                r7[acoef * b_k] * u[bcoef * b_k + u.size(0) * k];
          }
        }
      }
      cross(wd2, u, r6);
      bsxmul(sa, r6, r5);
      r2.set_size(1, 1);
      r2[0] = 1.0 - ca[0];
      bsxmul(r2, wd2, r6);
      bcoef = thd2.size(0);
      for (i = 0; i < bcoef; i++) {
        thd2[i] = 2.0 * thd2[i];
      }
      bcoef = udot.size(0);
      acoef = thd2.size(0);
      if (bcoef <= acoef) {
        acoef = bcoef;
      }
      if (udot.size(0) == 1) {
        acoef = thd2.size(0);
      } else if (thd2.size(0) == 1) {
        acoef = udot.size(0);
      } else if (thd2.size(0) == udot.size(0)) {
        acoef = thd2.size(0);
      }
      w.set_size(acoef, 3);
      bcoef = udot.size(0);
      acoef = thd2.size(0);
      if (bcoef <= acoef) {
        acoef = bcoef;
      }
      if (udot.size(0) == 1) {
        acoef = thd2.size(0);
      } else if (thd2.size(0) == 1) {
        acoef = udot.size(0);
      } else if (thd2.size(0) == udot.size(0)) {
        acoef = thd2.size(0);
      }
      if (acoef != 0) {
        acoef = (thd2.size(0) != 1);
        bcoef = (udot.size(0) != 1);
        for (k = 0; k < 3; k++) {
          i = w.size(0) - 1;
          for (b_k = 0; b_k <= i; b_k++) {
            w[b_k + w.size(0) * k] =
                thd2[acoef * b_k] * udot[bcoef * b_k + udot.size(0) * k];
          }
        }
      }
      b_ang.set_size(1, 1);
      b_ang[0] = ca[0] + 1.0;
      bsxmul(b_ang, wd1xu, th3);
      bcoef = u.size(0);
      acoef = w2.size(0);
      if (bcoef <= acoef) {
        acoef = bcoef;
      }
      if (u.size(0) == 1) {
        acoef = w2.size(0);
      } else if (w2.size(0) == 1) {
        acoef = u.size(0);
      } else if (w2.size(0) == u.size(0)) {
        acoef = w2.size(0);
      }
      wd2xu.set_size(acoef, 3);
      bcoef = u.size(0);
      acoef = w2.size(0);
      if (bcoef <= acoef) {
        acoef = bcoef;
      }
      if (u.size(0) == 1) {
        acoef = w2.size(0);
      } else if (w2.size(0) == 1) {
        acoef = u.size(0);
      } else if (w2.size(0) == u.size(0)) {
        acoef = w2.size(0);
      }
      if (acoef != 0) {
        acoef = (w2.size(0) != 1);
        bcoef = (u.size(0) != 1);
        for (k = 0; k < 3; k++) {
          i = wd2xu.size(0) - 1;
          for (b_k = 0; b_k <= i; b_k++) {
            wd2xu[b_k + wd2xu.size(0) * k] =
                w2[acoef * b_k] * u[bcoef * b_k + u.size(0) * k];
          }
        }
      }
      bsxmul(sa, wd1, wd2);
      b_temp1.set_size(th3.size(0), 3);
      bcoef = th3.size(0) * 3;
      for (i = 0; i < bcoef; i++) {
        b_temp1[i] = (th3[i] - wd2xu[i]) - wd2[i];
      }
      bcoef = b_temp1.size(0);
      acoef = thd1.size(0);
      if (bcoef <= acoef) {
        acoef = bcoef;
      }
      if (b_temp1.size(0) == 1) {
        acoef = thd1.size(0);
      } else if (thd1.size(0) == 1) {
        acoef = b_temp1.size(0);
      } else if (thd1.size(0) == b_temp1.size(0)) {
        acoef = thd1.size(0);
      }
      th3.set_size(acoef, 3);
      bcoef = b_temp1.size(0);
      acoef = thd1.size(0);
      if (bcoef <= acoef) {
        acoef = bcoef;
      }
      if (b_temp1.size(0) == 1) {
        acoef = thd1.size(0);
      } else if (thd1.size(0) == 1) {
        acoef = b_temp1.size(0);
      } else if (thd1.size(0) == b_temp1.size(0)) {
        acoef = thd1.size(0);
      }
      if (acoef != 0) {
        acoef = (thd1.size(0) != 1);
        bcoef = (b_temp1.size(0) != 1);
        for (k = 0; k < 3; k++) {
          i = th3.size(0) - 1;
          for (b_k = 0; b_k <= i; b_k++) {
            th3[b_k + th3.size(0) * k] =
                thd1[acoef * b_k] * b_temp1[bcoef * b_k + b_temp1.size(0) * k];
          }
        }
      }
      bcoef = wwd.size(0);
      for (i = 0; i < bcoef; i++) {
        wwd[i] = wwd[i] * sa[i];
      }
      bcoef = u.size(0);
      acoef = wwd.size(0);
      if (bcoef <= acoef) {
        acoef = bcoef;
      }
      if (u.size(0) == 1) {
        acoef = wwd.size(0);
      } else if (wwd.size(0) == 1) {
        acoef = u.size(0);
      } else if (wwd.size(0) == u.size(0)) {
        acoef = wwd.size(0);
      }
      wd2xu.set_size(acoef, 3);
      bcoef = u.size(0);
      acoef = wwd.size(0);
      if (bcoef <= acoef) {
        acoef = bcoef;
      }
      if (u.size(0) == 1) {
        acoef = wwd.size(0);
      } else if (wwd.size(0) == 1) {
        acoef = u.size(0);
      } else if (wwd.size(0) == u.size(0)) {
        acoef = wwd.size(0);
      }
      if (acoef != 0) {
        acoef = (wwd.size(0) != 1);
        bcoef = (u.size(0) != 1);
        for (k = 0; k < 3; k++) {
          i = wd2xu.size(0) - 1;
          for (b_k = 0; b_k <= i; b_k++) {
            wd2xu[b_k + wd2xu.size(0) * k] =
                wwd[acoef * b_k] * u[bcoef * b_k + u.size(0) * k];
          }
        }
      }
      bcoef = r.size(0);
      for (i = 0; i < 3; i++) {
        for (acoef = 0; acoef < bcoef; acoef++) {
          angVel[i] = r[acoef + r.size(0) * i];
        }
      }
      bcoef = r1.size(0);
      for (i = 0; i < 3; i++) {
        for (acoef = 0; acoef < bcoef; acoef++) {
          angAcc[i] = r1[acoef + r1.size(0) * i];
        }
      }
      bcoef = r3.size(0);
      for (i = 0; i < 3; i++) {
        for (acoef = 0; acoef < bcoef; acoef++) {
          angJerk[i] =
              ((((((r3[acoef + r3.size(0) * i] + r5[acoef + r5.size(0) * i]) -
                   r6[acoef + r6.size(0) * i]) +
                  w[acoef + w.size(0) * i]) +
                 th3[acoef + th3.size(0) * i]) -
                wd2xu[acoef + wd2xu.size(0) * i]) +
               temp1[acoef + temp1.size(0) * i]) +
              temp2[acoef + temp2.size(0) * i];
        }
      }
    }
  }
}

//
// Arguments    : double dt
//                double dtheta
//                const double e[3]
//                const double wi[3]
//                const double wf[3]
//                double aa[9]
//                double bb[9]
//                double cc[6]
//                double dd[3]
// Return Type  : void
//
void slew3_init(double dt, double dtheta, const double e[3], const double wi[3],
                const double wf[3], double aa[9], double bb[9], double cc[6],
                double dd[3])
{
  array<double, 2U> b_e;
  array<double, 2U> b_wf;
  array<double, 2U> bvec1;
  array<double, 2U> bvec2;
  array<double, 2U> r;
  array<double, 2U> r1;
  array<double, 1U> b0;
  array<signed char, 2U> ii;
  double bvec[3];
  double d;
  double d1;
  double d2;
  int bcoef;
  int i;
  int iNext;
  int vstride;
  if (dtheta > 1.0E-6) {
    ii.set_size(1, 1);
    ii[0] = 1;
  } else {
    ii.set_size(0, 0);
  }
  bvec[0] = wf[0];
  bvec[1] = wf[1];
  bvec[2] = wf[2];
  if ((ii.size(0) != 0) && (ii.size(1) != 0)) {
    int i1;
    int i2;
    int i3;
    b_e.set_size(1, 3);
    b_wf.set_size(1, 3);
    for (i = 0; i < 3; i++) {
      b_e[b_e.size(0) * i] = e[i];
      b_wf[b_wf.size(0) * i] = wf[i];
    }
    b0.set_size(b_e.size(0));
    vstride = b_e.size(0);
    i1 = -1;
    for (iNext = 0; iNext < vstride; iNext++) {
      i1++;
      bcoef = i1 + vstride;
      i2 = i1 + (vstride << 1);
      b0[iNext] =
          (b_e[i1] * b_wf[i1] + b_e[bcoef] * b_wf[bcoef]) + b_e[i2] * b_wf[i2];
    }
    b_e.set_size(1, 3);
    b_wf.set_size(1, 3);
    for (i = 0; i < 3; i++) {
      b_e[b_e.size(0) * i] = e[i];
      b_wf[b_wf.size(0) * i] = wf[i];
    }
    bvec2.set_size(b_e.size(0), 3);
    if (b_e.size(0) != 0) {
      vstride = b_e.size(0);
      iNext = b_e.size(0) * 3;
      for (bcoef = 1; iNext < 0 ? bcoef >= 1 : bcoef <= 1; bcoef += iNext) {
        for (i1 = 1; i1 <= vstride; i1++) {
          i2 = (i1 + vstride) - 1;
          i3 = i2 + vstride;
          bvec2[i1 - 1] = b_e[i2] * b_wf[i3] - b_e[i3] * b_wf[i2];
          bvec2[i2] = b_e[i3] * b_wf[i1 - 1] - b_e[i1 - 1] * b_wf[i3];
          bvec2[i3] = b_e[i1 - 1] * b_wf[i2] - b_e[i2] * b_wf[i1 - 1];
        }
      }
    }
    b_e.set_size(1, 3);
    for (i = 0; i < 3; i++) {
      b_e[b_e.size(0) * i] = e[i];
    }
    bvec1.set_size(bvec2.size(0), 3);
    if (bvec2.size(0) != 0) {
      vstride = bvec2.size(0);
      iNext = bvec2.size(0) * 3;
      for (bcoef = 1; iNext < 0 ? bcoef >= 1 : bcoef <= 1; bcoef += iNext) {
        for (i1 = 1; i1 <= vstride; i1++) {
          i2 = (i1 + vstride) - 1;
          i3 = i2 + vstride;
          bvec1[i1 - 1] = bvec2[i2] * b_e[i3] - bvec2[i3] * b_e[i2];
          bvec1[i2] = bvec2[i3] * b_e[i1 - 1] - bvec2[i1 - 1] * b_e[i3];
          bvec1[i3] = bvec2[i1 - 1] * b_e[i2] - bvec2[i2] * b_e[i1 - 1];
        }
      }
    }
    b_e.set_size(1, 3);
    for (i = 0; i < 3; i++) {
      b_e[b_e.size(0) * i] = e[i];
    }
    vstride = b_e.size(0);
    iNext = b0.size(0);
    if (vstride <= iNext) {
      iNext = vstride;
    }
    if (b_e.size(0) == 1) {
      iNext = b0.size(0);
    } else if (b0.size(0) == 1) {
      iNext = b_e.size(0);
    } else if (b0.size(0) == b_e.size(0)) {
      iNext = b0.size(0);
    }
    r.set_size(iNext, 3);
    vstride = b_e.size(0);
    iNext = b0.size(0);
    if (vstride <= iNext) {
      iNext = vstride;
    }
    if (b_e.size(0) == 1) {
      iNext = b0.size(0);
    } else if (b0.size(0) == 1) {
      iNext = b_e.size(0);
    } else if (b0.size(0) == b_e.size(0)) {
      iNext = b0.size(0);
    }
    if (iNext != 0) {
      vstride = (b0.size(0) != 1);
      bcoef = (b_e.size(0) != 1);
      for (iNext = 0; iNext < 3; iNext++) {
        i = r.size(0) - 1;
        for (i2 = 0; i2 <= i; i2++) {
          r[i2 + r.size(0) * iNext] =
              b0[vstride * i2] * b_e[bcoef * i2 + b_e.size(0) * iNext];
        }
      }
    }
    r1.set_size(1, 1);
    r1[0] = 0.5 * std::sin(dtheta) * dtheta / (1.0 - std::cos(dtheta));
    vstride = bvec1.size(0);
    iNext = r1.size(0);
    if (vstride <= iNext) {
      iNext = vstride;
    }
    if (bvec1.size(0) == 1) {
      iNext = r1.size(0);
    } else if (r1.size(0) == 1) {
      iNext = bvec1.size(0);
    } else if (r1.size(0) == bvec1.size(0)) {
      iNext = r1.size(0);
    }
    b_wf.set_size(iNext, 3);
    vstride = bvec1.size(0);
    iNext = r1.size(0);
    if (vstride <= iNext) {
      iNext = vstride;
    }
    if (bvec1.size(0) == 1) {
      iNext = r1.size(0);
    } else if (r1.size(0) == 1) {
      iNext = bvec1.size(0);
    } else if (r1.size(0) == bvec1.size(0)) {
      iNext = r1.size(0);
    }
    if (iNext != 0) {
      vstride = (r1.size(1) != 1);
      i3 = (r1.size(0) != 1);
      bcoef = (bvec1.size(0) != 1);
      for (iNext = 0; iNext < 3; iNext++) {
        i1 = vstride * iNext;
        i = b_wf.size(0) - 1;
        for (i2 = 0; i2 <= i; i2++) {
          b_wf[i2 + b_wf.size(0) * iNext] =
              r1[i3 * i2 + r1.size(0) * i1] *
              bvec1[bcoef * i2 + bvec1.size(0) * iNext];
        }
      }
    }
    r1.set_size(1, 1);
    r1[0] = 0.5 * dtheta;
    vstride = bvec2.size(0);
    iNext = r1.size(0);
    if (vstride <= iNext) {
      iNext = vstride;
    }
    if (bvec2.size(0) == 1) {
      iNext = r1.size(0);
    } else if (r1.size(0) == 1) {
      iNext = bvec2.size(0);
    } else if (r1.size(0) == bvec2.size(0)) {
      iNext = r1.size(0);
    }
    bvec1.set_size(iNext, 3);
    vstride = bvec2.size(0);
    iNext = r1.size(0);
    if (vstride <= iNext) {
      iNext = vstride;
    }
    if (bvec2.size(0) == 1) {
      iNext = r1.size(0);
    } else if (r1.size(0) == 1) {
      iNext = bvec2.size(0);
    } else if (r1.size(0) == bvec2.size(0)) {
      iNext = r1.size(0);
    }
    if (iNext != 0) {
      vstride = (r1.size(1) != 1);
      i3 = (r1.size(0) != 1);
      bcoef = (bvec2.size(0) != 1);
      for (iNext = 0; iNext < 3; iNext++) {
        i1 = vstride * iNext;
        i = bvec1.size(0) - 1;
        for (i2 = 0; i2 <= i; i2++) {
          bvec1[i2 + bvec1.size(0) * iNext] =
              r1[i3 * i2 + r1.size(0) * i1] *
              bvec2[bcoef * i2 + bvec2.size(0) * iNext];
        }
      }
    }
    vstride = r.size(0);
    for (i = 0; i < 3; i++) {
      for (iNext = 0; iNext < vstride; iNext++) {
        bvec[i] = (r[iNext + r.size(0) * i] + b_wf[iNext + b_wf.size(0) * i]) +
                  bvec1[iNext + bvec1.size(0) * i];
      }
    }
  }
  bb[0] = wi[0];
  d = e[0] * dtheta;
  d1 = d;
  aa[6] = d;
  bb[6] = bvec[0];
  d = wi[0] * dt;
  d2 = d;
  aa[0] = d;
  d = bvec[0] * dt - 3.0 * d1;
  aa[3] = d;
  d = (2.0 * d2 + 2.0 * d) / dt;
  d1 = d;
  bb[3] = d;
  d = (2.0 * wi[0] + d) / dt;
  d2 = d;
  cc[0] = d;
  d = (d1 + 2.0 * bvec[0]) / dt;
  cc[3] = d;
  dd[0] = (d2 + d) / dt;
  bb[1] = wi[1];
  d = e[1] * dtheta;
  d1 = d;
  aa[7] = d;
  bb[7] = bvec[1];
  d = wi[1] * dt;
  d2 = d;
  aa[1] = d;
  d = bvec[1] * dt - 3.0 * d1;
  aa[4] = d;
  d = (2.0 * d2 + 2.0 * d) / dt;
  d1 = d;
  bb[4] = d;
  d = (2.0 * wi[1] + d) / dt;
  d2 = d;
  cc[1] = d;
  d = (d1 + 2.0 * bvec[1]) / dt;
  cc[4] = d;
  dd[1] = (d2 + d) / dt;
  bb[2] = wi[2];
  d = e[2] * dtheta;
  d1 = d;
  aa[8] = d;
  bb[8] = bvec[2];
  d = wi[2] * dt;
  d2 = d;
  aa[2] = d;
  d = bvec[2] * dt - 3.0 * d1;
  aa[5] = d;
  d = (2.0 * d2 + 2.0 * d) / dt;
  d1 = d;
  bb[5] = d;
  d = (2.0 * wi[2] + d) / dt;
  d2 = d;
  cc[2] = d;
  d = (d1 + 2.0 * bvec[2]) / dt;
  cc[5] = d;
  dd[2] = (d2 + d) / dt;
  if (dt <= 0.0) {
    ii.set_size(1, 1);
    ii[0] = 1;
  } else {
    ii.set_size(0, 0);
  }
  vstride = ii.size(0) * ii.size(1);
  bcoef = ii.size(0) * ii.size(1);
  for (i = 0; i < 3; i++) {
    for (iNext = 0; iNext < 3; iNext++) {
      if (0 <= vstride - 1) {
        aa[iNext + 3 * i] = 0.0;
      }
      if (0 <= bcoef - 1) {
        bb[iNext + 3 * i] = 0.0;
      }
    }
  }
  vstride = ii.size(0) * ii.size(1);
  for (i = 0; i < 2; i++) {
    for (iNext = 0; iNext < 3; iNext++) {
      if (0 <= vstride - 1) {
        cc[iNext + 3 * i] = 0.0;
      }
    }
  }
  vstride = ii.size(0) * ii.size(1);
  for (i = 0; i < 3; i++) {
    if (0 <= vstride - 1) {
      dd[i] = 0.0;
    }
  }
}

} // namespace internal
} // namespace scenario
} // namespace fusion
} // namespace coder

//
// File trailer for getOrientationState.cpp
//
// [EOF]
//
