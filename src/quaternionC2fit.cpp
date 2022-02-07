//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: quaternionC2fit.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 06-Feb-2022 23:10:59
//

// Include Files
#include "quaternionC2fit.h"
#include "find.h"
#include "proc_planner_rtwutil.h"
#include "quaternion.h"
#include "rt_nonfinite.h"
#include "sum.h"
#include "svd.h"
#include "coder_array.h"
#include <cmath>
#include <string.h>

// Function Definitions
//
// Arguments    : const quaternion *qi
//                const quaternion *qf
//                ::coder::array<double, 1U> &dtheta
//                ::coder::array<double, 2U> &e
// Return Type  : void
//
namespace coder {
namespace fusion {
namespace scenario {
namespace internal {
void getang(const quaternion *qi, const quaternion *qf,
            ::coder::array<double, 1U> &dtheta, ::coder::array<double, 2U> &e)
{
  quaternion deltaQuat;
  quaternion qn;
  array<double, 2U> ax;
  array<double, 2U> m;
  array<double, 2U> rv;
  array<double, 2U> varargin_1;
  array<double, 2U> varargin_2;
  array<double, 2U> varargin_3;
  array<double, 2U> xb;
  array<double, 2U> xc;
  array<double, 2U> xd;
  array<double, 1U> ang;
  array<double, 1U> mag;
  array<int, 2U> r;
  array<int, 2U> r1;
  array<int, 2U> r2;
  array<int, 2U> r3;
  array<int, 2U> r4;
  array<int, 1U> ii;
  array<bool, 2U> idx;
  array<bool, 1U> b_dtheta;
  double absxk;
  double scale;
  double t;
  double yv;
  int b_i;
  int bcoef;
  int i;
  int k;
  int nx;
  xb.set_size(1, qi->b.size(1));
  nx = qi->b.size(1);
  for (i = 0; i < nx; i++) {
    xb[i] = -qi->b[i];
  }
  xc.set_size(1, qi->c.size(1));
  nx = qi->c.size(1);
  for (i = 0; i < nx; i++) {
    xc[i] = -qi->c[i];
  }
  xd.set_size(1, qi->d.size(1));
  nx = qi->d.size(1);
  for (i = 0; i < nx; i++) {
    xd[i] = -qi->d[i];
  }
  varargin_1.set_size(1, qi->a.size(1));
  nx = qi->a.size(1);
  for (i = 0; i < nx; i++) {
    varargin_1[i] =
        ((qi->a[i] * qf->a[i] - xb[i] * qf->b[i]) - xc[i] * qf->c[i]) -
        xd[i] * qf->d[i];
  }
  varargin_2.set_size(1, qi->a.size(1));
  nx = qi->a.size(1);
  for (i = 0; i < nx; i++) {
    varargin_2[i] =
        ((qi->a[i] * qf->b[i] + xb[i] * qf->a[i]) + xc[i] * qf->d[i]) -
        xd[i] * qf->c[i];
  }
  varargin_3.set_size(1, qi->a.size(1));
  nx = qi->a.size(1);
  for (i = 0; i < nx; i++) {
    varargin_3[i] =
        ((qi->a[i] * qf->c[i] - xb[i] * qf->d[i]) + xc[i] * qf->a[i]) +
        xd[i] * qf->b[i];
  }
  xb.set_size(1, qi->a.size(1));
  nx = qi->a.size(1) - 1;
  for (i = 0; i <= nx; i++) {
    xb[i] = ((qi->a[i] * qf->d[i] + xb[i] * qf->c[i]) - xc[i] * qf->b[i]) +
            xd[i] * qf->a[i];
  }
  xc.set_size(1, varargin_1.size(1));
  nx = varargin_1.size(1);
  for (i = 0; i < nx; i++) {
    scale = varargin_1[i];
    absxk = varargin_2[i];
    t = varargin_3[i];
    yv = xb[i];
    xc[i] = ((scale * scale + absxk * absxk) + t * t) + yv * yv;
  }
  nx = xc.size(1);
  for (k = 0; k < nx; k++) {
    xc[k] = std::sqrt(xc[k]);
  }
  deltaQuat.a.set_size(1, varargin_1.size(1));
  nx = varargin_1.size(1);
  for (i = 0; i < nx; i++) {
    deltaQuat.a[i] = varargin_1[i] / xc[i];
  }
  deltaQuat.b.set_size(1, varargin_2.size(1));
  nx = varargin_2.size(1);
  for (i = 0; i < nx; i++) {
    deltaQuat.b[i] = varargin_2[i] / xc[i];
  }
  deltaQuat.c.set_size(1, varargin_3.size(1));
  nx = varargin_3.size(1);
  for (i = 0; i < nx; i++) {
    deltaQuat.c[i] = varargin_3[i] / xc[i];
  }
  deltaQuat.d.set_size(1, xb.size(1));
  nx = xb.size(1);
  for (i = 0; i < nx; i++) {
    deltaQuat.d[i] = xb[i] / xc[i];
  }
  idx.set_size(1, deltaQuat.a.size(1));
  nx = deltaQuat.a.size(1);
  for (i = 0; i < nx; i++) {
    idx[i] = (deltaQuat.a[i] < 0.0);
  }
  bcoef = idx.size(1) - 1;
  nx = 0;
  for (b_i = 0; b_i <= bcoef; b_i++) {
    if (idx[b_i]) {
      nx++;
    }
  }
  r.set_size(1, nx);
  nx = 0;
  for (b_i = 0; b_i <= bcoef; b_i++) {
    if (idx[b_i]) {
      r[nx] = b_i + 1;
      nx++;
    }
  }
  varargin_2.set_size(1, r.size(1));
  nx = r.size(1);
  for (i = 0; i < nx; i++) {
    varargin_2[i] = deltaQuat.b[r[i] - 1];
  }
  varargin_3.set_size(1, r.size(1));
  nx = r.size(1);
  for (i = 0; i < nx; i++) {
    varargin_3[i] = deltaQuat.c[r[i] - 1];
  }
  xc.set_size(1, r.size(1));
  nx = r.size(1);
  for (i = 0; i < nx; i++) {
    xc[i] = deltaQuat.d[r[i] - 1];
  }
  bcoef = idx.size(1) - 1;
  nx = 0;
  for (b_i = 0; b_i <= bcoef; b_i++) {
    if (idx[b_i]) {
      nx++;
    }
  }
  r1.set_size(1, nx);
  nx = 0;
  for (b_i = 0; b_i <= bcoef; b_i++) {
    if (idx[b_i]) {
      r1[nx] = b_i + 1;
      nx++;
    }
  }
  nx = r.size(1);
  mag.set_size(r.size(1));
  for (i = 0; i < nx; i++) {
    mag[i] = -deltaQuat.a[r[i] - 1];
  }
  nx = mag.size(0);
  for (i = 0; i < nx; i++) {
    deltaQuat.a[r1[i] - 1] = mag[i];
  }
  bcoef = idx.size(1) - 1;
  nx = 0;
  for (b_i = 0; b_i <= bcoef; b_i++) {
    if (idx[b_i]) {
      nx++;
    }
  }
  r2.set_size(1, nx);
  nx = 0;
  for (b_i = 0; b_i <= bcoef; b_i++) {
    if (idx[b_i]) {
      r2[nx] = b_i + 1;
      nx++;
    }
  }
  nx = varargin_2.size(1) - 1;
  for (i = 0; i <= nx; i++) {
    deltaQuat.b[r2[i] - 1] = -varargin_2[i];
  }
  bcoef = idx.size(1) - 1;
  nx = 0;
  for (b_i = 0; b_i <= bcoef; b_i++) {
    if (idx[b_i]) {
      nx++;
    }
  }
  r3.set_size(1, nx);
  nx = 0;
  for (b_i = 0; b_i <= bcoef; b_i++) {
    if (idx[b_i]) {
      r3[nx] = b_i + 1;
      nx++;
    }
  }
  nx = varargin_3.size(1) - 1;
  for (i = 0; i <= nx; i++) {
    deltaQuat.c[r3[i] - 1] = -varargin_3[i];
  }
  bcoef = idx.size(1) - 1;
  nx = 0;
  for (b_i = 0; b_i <= bcoef; b_i++) {
    if (idx[b_i]) {
      nx++;
    }
  }
  r4.set_size(1, nx);
  nx = 0;
  for (b_i = 0; b_i <= bcoef; b_i++) {
    if (idx[b_i]) {
      r4[nx] = b_i + 1;
      nx++;
    }
  }
  nx = xc.size(1) - 1;
  for (i = 0; i <= nx; i++) {
    deltaQuat.d[r4[i] - 1] = -xc[i];
  }
  xc.set_size(1, deltaQuat.a.size(1));
  nx = deltaQuat.a.size(1);
  for (i = 0; i < nx; i++) {
    scale = deltaQuat.a[i];
    absxk = deltaQuat.b[i];
    t = deltaQuat.c[i];
    yv = deltaQuat.d[i];
    xc[i] = ((scale * scale + absxk * absxk) + t * t) + yv * yv;
  }
  nx = xc.size(1);
  for (k = 0; k < nx; k++) {
    xc[k] = std::sqrt(xc[k]);
  }
  qn.a.set_size(1, deltaQuat.a.size(1));
  nx = deltaQuat.a.size(1);
  for (i = 0; i < nx; i++) {
    qn.a[i] = deltaQuat.a[i] / xc[i];
  }
  qn.b.set_size(1, deltaQuat.b.size(1));
  nx = deltaQuat.b.size(1);
  for (i = 0; i < nx; i++) {
    qn.b[i] = deltaQuat.b[i] / xc[i];
  }
  qn.c.set_size(1, deltaQuat.c.size(1));
  nx = deltaQuat.c.size(1);
  for (i = 0; i < nx; i++) {
    qn.c[i] = deltaQuat.c[i] / xc[i];
  }
  qn.d.set_size(1, deltaQuat.d.size(1));
  nx = deltaQuat.d.size(1);
  for (i = 0; i < nx; i++) {
    qn.d[i] = deltaQuat.d[i] / xc[i];
  }
  m.set_size(qn.a.size(1), 4);
  nx = qn.a.size(1);
  for (i = 0; i < nx; i++) {
    m[i] = qn.a[i];
  }
  nx = qn.b.size(1);
  for (i = 0; i < nx; i++) {
    m[i + m.size(0)] = qn.b[i];
  }
  nx = qn.c.size(1);
  for (i = 0; i < nx; i++) {
    m[i + m.size(0) * 2] = qn.c[i];
  }
  nx = qn.d.size(1);
  for (i = 0; i < nx; i++) {
    m[i + m.size(0) * 3] = qn.d[i];
  }
  nx = m.size(0);
  ang.set_size(m.size(0));
  for (i = 0; i < nx; i++) {
    ang[i] = m[i];
  }
  i = m.size(0) - 1;
  for (k = 0; k <= i; k++) {
    ang[k] = std::acos(ang[k]);
  }
  nx = ang.size(0);
  for (i = 0; i < nx; i++) {
    ang[i] = 2.0 * ang[i];
  }
  nx = m.size(0);
  ax.set_size(m.size(0), 3);
  for (i = 0; i < 3; i++) {
    for (bcoef = 0; bcoef < nx; bcoef++) {
      ax[bcoef + ax.size(0) * i] = m[bcoef + m.size(0) * (i + 1)];
    }
  }
  rv.set_size(m.size(0), 3);
  nx = m.size(0) * 3;
  for (k = 0; k < nx; k++) {
    rv[k] =
        m[k % m.size(0) + m.size(0) * (div_nzp_s32_floor(k, m.size(0)) + 1)] *
        m[k % m.size(0) + m.size(0) * (div_nzp_s32_floor(k, m.size(0)) + 1)];
  }
  sum(rv, mag);
  nx = mag.size(0);
  for (k = 0; k < nx; k++) {
    mag[k] = std::sqrt(mag[k]);
  }
  rv.set_size(ang.size(0), 3);
  nx = ang.size(0) * 3;
  for (i = 0; i < nx; i++) {
    rv[i] = 0.0;
  }
  i = ang.size(0);
  for (nx = 0; nx < i; nx++) {
    if (mag[nx] > 2.2204460492503131E-15) {
      rv[nx] = ang[nx] * ax[nx] / mag[nx];
      rv[nx + rv.size(0)] = ang[nx] * ax[nx + ax.size(0)] / mag[nx];
      rv[nx + rv.size(0) * 2] = ang[nx] * ax[nx + ax.size(0) * 2] / mag[nx];
    }
  }
  dtheta.set_size(rv.size(0));
  nx = rv.size(0);
  for (i = 0; i < nx; i++) {
    dtheta[i] = 0.0;
  }
  nx = rv.size(0);
  for (bcoef = 0; bcoef < nx; bcoef++) {
    scale = 3.3121686421112381E-170;
    absxk = std::abs(rv[bcoef]);
    if (absxk > 3.3121686421112381E-170) {
      yv = 1.0;
      scale = absxk;
    } else {
      t = absxk / 3.3121686421112381E-170;
      yv = t * t;
    }
    absxk = std::abs(rv[bcoef + nx]);
    if (absxk > scale) {
      t = scale / absxk;
      yv = yv * t * t + 1.0;
      scale = absxk;
    } else {
      t = absxk / scale;
      yv += t * t;
    }
    absxk = std::abs(rv[bcoef + (nx << 1)]);
    if (absxk > scale) {
      t = scale / absxk;
      yv = yv * t * t + 1.0;
      scale = absxk;
    } else {
      t = absxk / scale;
      yv += t * t;
    }
    dtheta[bcoef] = scale * std::sqrt(yv);
  }
  nx = dtheta.size(0);
  bcoef = rv.size(0);
  if (nx <= bcoef) {
    bcoef = nx;
  }
  if (dtheta.size(0) == 1) {
    bcoef = rv.size(0);
  } else if (rv.size(0) == 1) {
    bcoef = dtheta.size(0);
  } else if (rv.size(0) == dtheta.size(0)) {
    bcoef = rv.size(0);
  }
  e.set_size(bcoef, 3);
  nx = dtheta.size(0);
  bcoef = rv.size(0);
  if (nx <= bcoef) {
    bcoef = nx;
  }
  if (dtheta.size(0) == 1) {
    bcoef = rv.size(0);
  } else if (rv.size(0) == 1) {
    bcoef = dtheta.size(0);
  } else if (rv.size(0) == dtheta.size(0)) {
    bcoef = rv.size(0);
  }
  if (bcoef != 0) {
    nx = (rv.size(0) != 1);
    bcoef = (dtheta.size(0) != 1);
    for (k = 0; k < 3; k++) {
      i = e.size(0) - 1;
      for (b_i = 0; b_i <= i; b_i++) {
        e[b_i + e.size(0) * k] =
            rv[nx * b_i + rv.size(0) * k] / dtheta[bcoef * b_i];
      }
    }
  }
  b_dtheta.set_size(dtheta.size(0));
  nx = dtheta.size(0);
  for (i = 0; i < nx; i++) {
    b_dtheta[i] = (dtheta[i] <= 0.0);
  }
  eml_find(b_dtheta, ii);
  ang.set_size(ii.size(0));
  nx = ii.size(0);
  for (i = 0; i < nx; i++) {
    ang[i] = ii[i];
  }
  nx = ang.size(0);
  for (i = 0; i < 3; i++) {
    for (bcoef = 0; bcoef < nx; bcoef++) {
      e[(static_cast<int>(ang[bcoef]) + e.size(0) * i) - 1] = 0.0;
    }
  }
}

//
// Arguments    : double n
//                const ::coder::array<double, 1U> &h
//                const ::coder::array<double, 1U> &dtheta
//                const ::coder::array<double, 2U> &e
//                ::coder::array<double, 2U> &w
// Return Type  : void
//
void rates(double n, const ::coder::array<double, 1U> &h,
           const ::coder::array<double, 1U> &dtheta,
           const ::coder::array<double, 2U> &e, ::coder::array<double, 2U> &w)
{
  array<double, 2U> wprev;
  array<double, 2U> x;
  array<double, 1U> a;
  array<double, 1U> b;
  array<double, 1U> c;
  array<double, 1U> s;
  double iter;
  int b_loop_ub;
  int i;
  int i1;
  int i2;
  int i3;
  int i4;
  int i5;
  int loop_ub;
  int loop_ub_tmp;
  int m;
  bool flag;
  iter = 0.0;
  flag = true;
  m = static_cast<int>(n);
  a.set_size(m);
  b.set_size(m);
  c.set_size(m);
  for (i = 0; i < m; i++) {
    a[i] = 0.0;
    b[i] = 0.0;
    c[i] = 0.0;
  }
  w.set_size(m, 3);
  loop_ub_tmp = static_cast<int>(n) * 3;
  wprev.set_size(m, 3);
  for (i = 0; i < loop_ub_tmp; i++) {
    w[i] = 0.0;
    wprev[i] = 0.0;
  }
  if (2.0 > n - 1.0) {
    i = 0;
    loop_ub_tmp = 0;
    i1 = 0;
  } else {
    i = 1;
    loop_ub_tmp = static_cast<int>(n - 1.0);
    i1 = 1;
  }
  loop_ub = loop_ub_tmp - i;
  loop_ub_tmp = static_cast<int>((n - 1.0) + -1.0);
  i2 = static_cast<int>(-((-1.0 - (n - 2.0)) + 2.0));
  if (2.0 > n - 1.0) {
    i3 = 0;
    i4 = 0;
    i5 = 0;
  } else {
    i3 = 1;
    i4 = static_cast<int>(n - 1.0);
    i5 = 1;
  }
  b_loop_ub = i4 - i3;
  while (flag) {
    double absxk;
    double b0_tmp;
    double b_a;
    double b_b0_tmp;
    double b_tmp;
    double c_b0_tmp;
    double ca;
    double sa;
    double t;
    double temp1_idx_0;
    double temp1_idx_1;
    double temp1_idx_2;
    double temp2_idx_0;
    double temp2_idx_1;
    double windote;
    int b_i;
    for (m = 0; m < 3; m++) {
      for (b_i = 0; b_i < loop_ub; b_i++) {
        wprev[(i1 + b_i) + wprev.size(0) * m] = w[(i + b_i) + w.size(0) * m];
      }
    }
    for (b_i = 0; b_i < loop_ub_tmp; b_i++) {
      a[b_i + 1] = 2.0 / h[b_i];
      b_tmp = h[b_i + 1];
      b[b_i + 1] = 4.0 / h[b_i] + 4.0 / b_tmp;
      c[b_i + 1] = 2.0 / b_tmp;
      if (dtheta[b_i] > 1.0E-6) {
        ca = std::cos(dtheta[b_i]);
        sa = std::sin(dtheta[b_i]);
        b0_tmp = e[b_i + e.size(0)];
        b_b0_tmp = e[b_i + e.size(0) * 2];
        c_b0_tmp = wprev[(b_i + wprev.size(0) * 2) + 1];
        absxk = wprev[(b_i + wprev.size(0)) + 1];
        temp2_idx_0 = b0_tmp * c_b0_tmp - absxk * b_b0_tmp;
        windote = e[b_i];
        t = wprev[b_i + 1];
        temp2_idx_1 = t * b_b0_tmp - windote * c_b0_tmp;
        temp1_idx_2 = windote * absxk - t * b0_tmp;
        windote = (t * e[b_i] + absxk * e[b_i + e.size(0)]) +
                  c_b0_tmp * e[b_i + e.size(0) * 2];
        b_a = 0.5 *
              (((t * t + absxk * absxk) + c_b0_tmp * c_b0_tmp) -
               windote * windote) *
              (dtheta[b_i] - sa) / (1.0 - ca);
        absxk = windote * (dtheta[b_i] * sa - 2.0 * (1.0 - ca)) /
                (dtheta[b_i] * (1.0 - ca));
        b0_tmp = e[b_i + e.size(0) * 2];
        b_b0_tmp = e[b_i + e.size(0)];
        c_b0_tmp = e[b_i];
        temp1_idx_0 = b_a * e[b_i] +
                      absxk * (temp2_idx_1 * b0_tmp - b_b0_tmp * temp1_idx_2);
        temp1_idx_1 = b_a * e[b_i + e.size(0)] +
                      absxk * (c_b0_tmp * temp1_idx_2 - temp2_idx_0 * b0_tmp);
        temp1_idx_2 = b_a * e[b_i + e.size(0) * 2] +
                      absxk * (temp2_idx_0 * b_b0_tmp - c_b0_tmp * temp2_idx_1);
      } else {
        temp1_idx_0 = 0.0;
        temp1_idx_1 = 0.0;
        temp1_idx_2 = 0.0;
      }
      t = h[b_i] * h[b_i];
      windote = b_tmp * b_tmp;
      absxk = dtheta[b_i + 1];
      w[b_i + 1] =
          6.0 * (dtheta[b_i] * e[b_i] / t + absxk * e[b_i + 1] / windote) -
          temp1_idx_0;
      w[(b_i + w.size(0)) + 1] =
          6.0 * (dtheta[b_i] * e[b_i + e.size(0)] / t +
                 absxk * e[(b_i + e.size(0)) + 1] / windote) -
          temp1_idx_1;
      w[(b_i + w.size(0) * 2) + 1] =
          6.0 * (dtheta[b_i] * e[b_i + e.size(0) * 2] / t +
                 absxk * e[(b_i + e.size(0) * 2) + 1] / windote) -
          temp1_idx_2;
    }
    temp1_idx_0 = 0.0;
    temp1_idx_1 = 0.0;
    temp1_idx_2 = 0.0;
    if (dtheta[0] > 1.0E-6) {
      b_a = std::sin(dtheta[0]) / dtheta[0];
      absxk = (std::cos(dtheta[0]) - 1.0) / dtheta[0];
      sa = (0.0 * e[0] + 0.0 * e[e.size(0)]) + 0.0 * e[e.size(0) * 2];
      temp2_idx_0 = e[e.size(0)] * 0.0 - 0.0 * e[e.size(0) * 2];
      temp2_idx_1 = 0.0 * e[e.size(0) * 2] - e[0] * 0.0;
      temp1_idx_2 = e[0] * 0.0 - 0.0 * e[e.size(0)];
      temp1_idx_0 = (sa * e[0] + b_a * (temp2_idx_1 * e[e.size(0) * 2] -
                                        e[e.size(0)] * temp1_idx_2)) +
                    absxk * temp2_idx_0;
      temp1_idx_1 =
          (sa * e[e.size(0)] +
           b_a * (e[0] * temp1_idx_2 - temp2_idx_0 * e[e.size(0) * 2])) +
          absxk * temp2_idx_1;
      temp1_idx_2 = (sa * e[e.size(0) * 2] +
                     b_a * (temp2_idx_0 * e[e.size(0)] - e[0] * temp2_idx_1)) +
                    absxk * temp1_idx_2;
    }
    w[1] = w[1] - a[1] * temp1_idx_0;
    temp1_idx_0 = 0.0;
    w[w.size(0) + 1] = w[w.size(0) + 1] - a[1] * temp1_idx_1;
    temp1_idx_1 = 0.0;
    w[w.size(0) * 2 + 1] = w[w.size(0) * 2 + 1] - a[1] * temp1_idx_2;
    temp1_idx_2 = 0.0;
    b0_tmp = dtheta[static_cast<int>(n - 1.0) - 1];
    if (b0_tmp > 1.0E-6) {
      ca = 0.5 * b0_tmp;
      b_a = ca * std::sin(b0_tmp) / (1.0 - std::cos(b0_tmp));
      absxk = e[static_cast<int>(n - 1.0) - 1];
      b_b0_tmp = 0.0 * absxk;
      t = e[(static_cast<int>(n - 1.0) + e.size(0)) - 1];
      c_b0_tmp = 0.0 * t;
      windote = e[(static_cast<int>(n - 1.0) + e.size(0) * 2) - 1];
      b0_tmp = 0.0 * windote;
      sa = (b_b0_tmp + c_b0_tmp) + b0_tmp;
      temp2_idx_0 = c_b0_tmp - b0_tmp;
      temp2_idx_1 = b0_tmp - b_b0_tmp;
      temp1_idx_2 = b_b0_tmp - c_b0_tmp;
      temp1_idx_0 =
          (sa * absxk + b_a * (temp2_idx_1 * windote - t * temp1_idx_2)) +
          ca * temp2_idx_0;
      temp1_idx_1 =
          (sa * t + b_a * (absxk * temp1_idx_2 - temp2_idx_0 * windote)) +
          ca * temp2_idx_1;
      temp1_idx_2 =
          (sa * windote + b_a * (temp2_idx_0 * t - absxk * temp2_idx_1)) +
          ca * temp1_idx_2;
    }
    windote = c[static_cast<int>(n - 1.0) - 1];
    temp1_idx_0 = w[static_cast<int>(n - 1.0) - 1] - windote * temp1_idx_0;
    temp1_idx_1 =
        w[(static_cast<int>(n - 1.0) + w.size(0)) - 1] - windote * temp1_idx_1;
    temp1_idx_2 = w[(static_cast<int>(n - 1.0) + w.size(0) * 2) - 1] -
                  windote * temp1_idx_2;
    w[static_cast<int>(n - 1.0) - 1] = temp1_idx_0;
    w[(static_cast<int>(n - 1.0) + w.size(0)) - 1] = temp1_idx_1;
    w[(static_cast<int>(n - 1.0) + w.size(0) * 2) - 1] = temp1_idx_2;
    for (b_i = 0; b_i < loop_ub_tmp; b_i++) {
      b_tmp = a[b_i + 2];
      b[b_i + 2] = b[b_i + 2] - c[b_i + 1] * b_tmp / b[b_i + 1];
      temp1_idx_0 = w[b_i + 1];
      temp1_idx_1 = w[(b_i + w.size(0)) + 1];
      temp1_idx_2 = w[(b_i + w.size(0) * 2) + 1];
      b0_tmp = dtheta[b_i + 1];
      if (b0_tmp > 1.0E-6) {
        b_a = std::sin(b0_tmp) / b0_tmp;
        absxk = (std::cos(b0_tmp) - 1.0) / b0_tmp;
        b_b0_tmp = e[b_i + 1];
        c_b0_tmp = e[(b_i + e.size(0)) + 1];
        b0_tmp = e[(b_i + e.size(0) * 2) + 1];
        sa = (temp1_idx_0 * b_b0_tmp + temp1_idx_1 * c_b0_tmp) +
             temp1_idx_2 * b0_tmp;
        temp2_idx_0 = c_b0_tmp * temp1_idx_2 - temp1_idx_1 * b0_tmp;
        temp2_idx_1 = temp1_idx_0 * b0_tmp - b_b0_tmp * temp1_idx_2;
        temp1_idx_2 = b_b0_tmp * temp1_idx_1 - temp1_idx_0 * c_b0_tmp;
        temp1_idx_0 = (sa * b_b0_tmp +
                       b_a * (temp2_idx_1 * b0_tmp - c_b0_tmp * temp1_idx_2)) +
                      absxk * temp2_idx_0;
        temp1_idx_1 = (sa * c_b0_tmp +
                       b_a * (b_b0_tmp * temp1_idx_2 - temp2_idx_0 * b0_tmp)) +
                      absxk * temp2_idx_1;
        temp1_idx_2 = (sa * b0_tmp + b_a * (temp2_idx_0 * c_b0_tmp -
                                            b_b0_tmp * temp2_idx_1)) +
                      absxk * temp1_idx_2;
      }
      w[b_i + 2] = w[b_i + 2] - temp1_idx_0 * b_tmp / b[b_i + 1];
      w[(b_i + w.size(0)) + 2] =
          w[(b_i + w.size(0)) + 2] - temp1_idx_1 * b_tmp / b[b_i + 1];
      w[(b_i + w.size(0) * 2) + 2] =
          w[(b_i + w.size(0) * 2) + 2] - temp1_idx_2 * b_tmp / b[b_i + 1];
    }
    windote = b[static_cast<int>(n - 1.0) - 1];
    w[static_cast<int>(n - 1.0) - 1] =
        w[static_cast<int>(n - 1.0) - 1] / windote;
    w[(static_cast<int>(n - 1.0) + w.size(0)) - 1] =
        w[(static_cast<int>(n - 1.0) + w.size(0)) - 1] / windote;
    w[(static_cast<int>(n - 1.0) + w.size(0) * 2) - 1] =
        w[(static_cast<int>(n - 1.0) + w.size(0) * 2) - 1] / windote;
    for (b_i = 0; b_i < i2; b_i++) {
      t = (n - 2.0) + -static_cast<double>(b_i);
      temp1_idx_0 = w[static_cast<int>(t)];
      temp1_idx_1 = w[static_cast<int>(t) + w.size(0)];
      temp1_idx_2 = w[static_cast<int>(t) + w.size(0) * 2];
      b0_tmp = dtheta[static_cast<int>(t) - 1];
      if (b0_tmp > 1.0E-6) {
        ca = 0.5 * b0_tmp;
        b_a = ca * std::sin(b0_tmp) / (1.0 - std::cos(b0_tmp));
        b_b0_tmp = e[static_cast<int>(t) - 1];
        c_b0_tmp = e[(static_cast<int>(t) + e.size(0)) - 1];
        b0_tmp = e[(static_cast<int>(t) + e.size(0) * 2) - 1];
        sa = (temp1_idx_0 * b_b0_tmp + temp1_idx_1 * c_b0_tmp) +
             temp1_idx_2 * b0_tmp;
        temp2_idx_0 = c_b0_tmp * temp1_idx_2 - temp1_idx_1 * b0_tmp;
        temp2_idx_1 = temp1_idx_0 * b0_tmp - b_b0_tmp * temp1_idx_2;
        temp1_idx_2 = b_b0_tmp * temp1_idx_1 - temp1_idx_0 * c_b0_tmp;
        temp1_idx_0 = (sa * b_b0_tmp +
                       b_a * (temp2_idx_1 * b0_tmp - c_b0_tmp * temp1_idx_2)) +
                      ca * temp2_idx_0;
        temp1_idx_1 = (sa * c_b0_tmp +
                       b_a * (b_b0_tmp * temp1_idx_2 - temp2_idx_0 * b0_tmp)) +
                      ca * temp2_idx_1;
        temp1_idx_2 = (sa * b0_tmp + b_a * (temp2_idx_0 * c_b0_tmp -
                                            b_b0_tmp * temp2_idx_1)) +
                      ca * temp1_idx_2;
      }
      windote = c[static_cast<int>(t) - 1];
      absxk = b[static_cast<int>(t) - 1];
      temp1_idx_0 =
          (w[static_cast<int>(t) - 1] - windote * temp1_idx_0) / absxk;
      temp1_idx_1 =
          (w[(static_cast<int>(t) + w.size(0)) - 1] - windote * temp1_idx_1) /
          absxk;
      temp1_idx_2 = (w[(static_cast<int>(t) + w.size(0) * 2) - 1] -
                     windote * temp1_idx_2) /
                    absxk;
      w[static_cast<int>(t) - 1] = temp1_idx_0;
      w[(static_cast<int>(t) + w.size(0)) - 1] = temp1_idx_1;
      w[(static_cast<int>(t) + w.size(0) * 2) - 1] = temp1_idx_2;
    }
    x.set_size(i4 - i3, 3);
    for (m = 0; m < 3; m++) {
      for (b_i = 0; b_i < b_loop_ub; b_i++) {
        x[b_i + x.size(0) * m] = w[(i3 + b_i) + w.size(0) * m] -
                                 wprev[(i5 + b_i) + wprev.size(0) * m];
      }
    }
    if (x.size(0) == 0) {
      ca = 0.0;
    } else if (x.size(0) == 1) {
      windote = 3.3121686421112381E-170;
      absxk = std::abs(x[0]);
      if (absxk > 3.3121686421112381E-170) {
        ca = 1.0;
        windote = absxk;
      } else {
        t = absxk / 3.3121686421112381E-170;
        ca = t * t;
      }
      absxk = std::abs(x[1]);
      if (absxk > windote) {
        t = windote / absxk;
        ca = ca * t * t + 1.0;
        windote = absxk;
      } else {
        t = absxk / windote;
        ca += t * t;
      }
      absxk = std::abs(x[2]);
      if (absxk > windote) {
        t = windote / absxk;
        ca = ca * t * t + 1.0;
        windote = absxk;
      } else {
        t = absxk / windote;
        ca += t * t;
      }
      ca = windote * std::sqrt(ca);
    } else {
      m = x.size(0);
      ca = 0.0;
      for (int j{0}; j < 3; j++) {
        for (b_i = 0; b_i < m; b_i++) {
          windote = std::abs(x[b_i + x.size(0) * j]);
          if (std::isnan(windote) || (windote > ca)) {
            ca = windote;
          }
        }
      }
      if ((!std::isinf(ca)) && (!std::isnan(ca))) {
        ::coder::internal::svd(x, s);
        ca = s[0];
      }
    }
    iter++;
    if ((!(iter < 10.0)) || (!(ca > 1.0E-9))) {
      flag = false;
    }
  }
  w[0] = 0.0;
  w[static_cast<int>(n) - 1] = 0.0;
  w[w.size(0)] = 0.0;
  w[(static_cast<int>(n) + w.size(0)) - 1] = 0.0;
  w[w.size(0) * 2] = 0.0;
  w[(static_cast<int>(n) + w.size(0) * 2) - 1] = 0.0;
}

} // namespace internal
} // namespace scenario
} // namespace fusion
} // namespace coder

//
// File trailer for quaternionC2fit.cpp
//
// [EOF]
//
