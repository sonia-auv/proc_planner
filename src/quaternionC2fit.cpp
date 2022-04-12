//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: quaternionC2fit.cpp
//
// MATLAB Coder version            : 5.4
// C/C++ source code generated on  : 12-Apr-2022 11:44:16
//

// Include Files
#include "quaternionC2fit.h"
#include "div.h"
#include "find.h"
#include "normalize.h"
#include "quaternion.h"
#include "rt_nonfinite.h"
#include "svd.h"
#include "coder_array.h"
#include <cmath>
#include <string.h>

// Function Declarations
static void binary_expand_op(coder::array<double, 2U> &in1,
                             const coder::array<double, 2U> &in2, int in3,
                             int in4, const coder::array<double, 2U> &in5,
                             int in6, int in7);

// Function Definitions
//
// Arguments    : coder::array<double, 2U> &in1
//                const coder::array<double, 2U> &in2
//                int in3
//                int in4
//                const coder::array<double, 2U> &in5
//                int in6
//                int in7
// Return Type  : void
//
static void binary_expand_op(coder::array<double, 2U> &in1,
                             const coder::array<double, 2U> &in2, int in3,
                             int in4, const coder::array<double, 2U> &in5,
                             int in6, int in7)
{
  int b_in7;
  int loop_ub;
  int stride_1_0;
  if ((in7 - in6) + 1 == 1) {
    b_in7 = (in4 - in3) + 1;
  } else {
    b_in7 = (in7 - in6) + 1;
  }
  in1.set_size(b_in7, 3);
  b_in7 = ((in4 - in3) + 1 != 1);
  stride_1_0 = ((in7 - in6) + 1 != 1);
  if ((in7 - in6) + 1 == 1) {
    loop_ub = (in4 - in3) + 1;
  } else {
    loop_ub = (in7 - in6) + 1;
  }
  for (int i{0}; i < 3; i++) {
    for (int i1{0}; i1 < loop_ub; i1++) {
      in1[i1 + in1.size(0) * i] =
          in2[(in3 + i1 * b_in7) + in2.size(0) * i] -
          in5[(in6 + i1 * stride_1_0) + in5.size(0) * i];
    }
  }
}

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
  quaternion q;
  quaternion qn;
  array<double, 2U> m;
  array<double, 2U> rv;
  array<double, 2U> varargin_1;
  array<double, 2U> varargin_2;
  array<double, 2U> varargin_3;
  array<double, 2U> xb;
  array<double, 2U> xd;
  array<double, 1U> ang;
  array<double, 1U> mag;
  array<int, 2U> r;
  array<int, 2U> r1;
  array<int, 2U> r2;
  array<int, 2U> r3;
  array<int, 2U> r4;
  array<int, 1U> r5;
  array<bool, 2U> idx;
  array<bool, 1U> b_dtheta;
  double absxk;
  double scale;
  double t;
  double yv;
  int b_i;
  int i;
  int i1;
  int k;
  int nx;
  int xoffset;
  q.c.set_size(1, qi->c.size(1));
  nx = qi->c.size(1);
  for (i = 0; i < nx; i++) {
    q.c[i] = -qi->c[i];
  }
  xb.set_size(1, qi->b.size(1));
  nx = qi->b.size(1);
  for (i = 0; i < nx; i++) {
    xb[i] = -qi->b[i];
  }
  xd.set_size(1, qi->d.size(1));
  nx = qi->d.size(1);
  for (i = 0; i < nx; i++) {
    xd[i] = -qi->d[i];
  }
  if (qi->a.size(1) == 1) {
    i = qf->a.size(1);
  } else {
    i = qi->a.size(1);
  }
  if (xb.size(1) == 1) {
    nx = qf->b.size(1);
  } else {
    nx = xb.size(1);
  }
  if (qi->a.size(1) == 1) {
    k = qf->a.size(1);
  } else {
    k = qi->a.size(1);
  }
  if (k == 1) {
    if (xb.size(1) == 1) {
      k = qf->b.size(1);
    } else {
      k = xb.size(1);
    }
  } else if (qi->a.size(1) == 1) {
    k = qf->a.size(1);
  } else {
    k = qi->a.size(1);
  }
  if (q.c.size(1) == 1) {
    xoffset = qf->c.size(1);
  } else {
    xoffset = q.c.size(1);
  }
  if (qi->a.size(1) == 1) {
    b_i = qf->a.size(1);
  } else {
    b_i = qi->a.size(1);
  }
  if (b_i == 1) {
    if (xb.size(1) == 1) {
      b_i = qf->b.size(1);
    } else {
      b_i = xb.size(1);
    }
  } else if (qi->a.size(1) == 1) {
    b_i = qf->a.size(1);
  } else {
    b_i = qi->a.size(1);
  }
  if (qi->a.size(1) == 1) {
    i1 = qf->a.size(1);
  } else {
    i1 = qi->a.size(1);
  }
  if (b_i == 1) {
    if (q.c.size(1) == 1) {
      b_i = qf->c.size(1);
    } else {
      b_i = q.c.size(1);
    }
  } else if (i1 == 1) {
    if (xb.size(1) == 1) {
      b_i = qf->b.size(1);
    } else {
      b_i = xb.size(1);
    }
  } else if (qi->a.size(1) == 1) {
    b_i = qf->a.size(1);
  } else {
    b_i = qi->a.size(1);
  }
  if (xd.size(1) == 1) {
    i1 = qf->d.size(1);
  } else {
    i1 = xd.size(1);
  }
  if ((qi->a.size(1) == qf->a.size(1)) && (xb.size(1) == qf->b.size(1)) &&
      (i == nx) && (q.c.size(1) == qf->c.size(1)) && (k == xoffset) &&
      (xd.size(1) == qf->d.size(1)) && (b_i == i1)) {
    varargin_1.set_size(1, qi->a.size(1));
    nx = qi->a.size(1);
    for (i = 0; i < nx; i++) {
      varargin_1[i] =
          ((qi->a[i] * qf->a[i] - xb[i] * qf->b[i]) - q.c[i] * qf->c[i]) -
          xd[i] * qf->d[i];
    }
  } else {
    f_binary_expand_op(varargin_1, qi, qf, xb, &q, xd);
  }
  if (qi->a.size(1) == 1) {
    i = qf->b.size(1);
  } else {
    i = qi->a.size(1);
  }
  if (xb.size(1) == 1) {
    nx = qf->a.size(1);
  } else {
    nx = xb.size(1);
  }
  if (qi->a.size(1) == 1) {
    k = qf->b.size(1);
  } else {
    k = qi->a.size(1);
  }
  if (k == 1) {
    if (xb.size(1) == 1) {
      k = qf->a.size(1);
    } else {
      k = xb.size(1);
    }
  } else if (qi->a.size(1) == 1) {
    k = qf->b.size(1);
  } else {
    k = qi->a.size(1);
  }
  if (q.c.size(1) == 1) {
    xoffset = qf->d.size(1);
  } else {
    xoffset = q.c.size(1);
  }
  if (qi->a.size(1) == 1) {
    b_i = qf->b.size(1);
  } else {
    b_i = qi->a.size(1);
  }
  if (b_i == 1) {
    if (xb.size(1) == 1) {
      b_i = qf->a.size(1);
    } else {
      b_i = xb.size(1);
    }
  } else if (qi->a.size(1) == 1) {
    b_i = qf->b.size(1);
  } else {
    b_i = qi->a.size(1);
  }
  if (qi->a.size(1) == 1) {
    i1 = qf->b.size(1);
  } else {
    i1 = qi->a.size(1);
  }
  if (b_i == 1) {
    if (q.c.size(1) == 1) {
      b_i = qf->d.size(1);
    } else {
      b_i = q.c.size(1);
    }
  } else if (i1 == 1) {
    if (xb.size(1) == 1) {
      b_i = qf->a.size(1);
    } else {
      b_i = xb.size(1);
    }
  } else if (qi->a.size(1) == 1) {
    b_i = qf->b.size(1);
  } else {
    b_i = qi->a.size(1);
  }
  if (xd.size(1) == 1) {
    i1 = qf->c.size(1);
  } else {
    i1 = xd.size(1);
  }
  if ((qi->a.size(1) == qf->b.size(1)) && (xb.size(1) == qf->a.size(1)) &&
      (i == nx) && (q.c.size(1) == qf->d.size(1)) && (k == xoffset) &&
      (xd.size(1) == qf->c.size(1)) && (b_i == i1)) {
    varargin_2.set_size(1, qi->a.size(1));
    nx = qi->a.size(1);
    for (i = 0; i < nx; i++) {
      varargin_2[i] =
          ((qi->a[i] * qf->b[i] + xb[i] * qf->a[i]) + q.c[i] * qf->d[i]) -
          xd[i] * qf->c[i];
    }
  } else {
    e_binary_expand_op(varargin_2, qi, qf, xb, &q, xd);
  }
  if (qi->a.size(1) == 1) {
    i = qf->c.size(1);
  } else {
    i = qi->a.size(1);
  }
  if (xb.size(1) == 1) {
    nx = qf->d.size(1);
  } else {
    nx = xb.size(1);
  }
  if (qi->a.size(1) == 1) {
    k = qf->c.size(1);
  } else {
    k = qi->a.size(1);
  }
  if (k == 1) {
    if (xb.size(1) == 1) {
      k = qf->d.size(1);
    } else {
      k = xb.size(1);
    }
  } else if (qi->a.size(1) == 1) {
    k = qf->c.size(1);
  } else {
    k = qi->a.size(1);
  }
  if (q.c.size(1) == 1) {
    xoffset = qf->a.size(1);
  } else {
    xoffset = q.c.size(1);
  }
  if (qi->a.size(1) == 1) {
    b_i = qf->c.size(1);
  } else {
    b_i = qi->a.size(1);
  }
  if (b_i == 1) {
    if (xb.size(1) == 1) {
      b_i = qf->d.size(1);
    } else {
      b_i = xb.size(1);
    }
  } else if (qi->a.size(1) == 1) {
    b_i = qf->c.size(1);
  } else {
    b_i = qi->a.size(1);
  }
  if (qi->a.size(1) == 1) {
    i1 = qf->c.size(1);
  } else {
    i1 = qi->a.size(1);
  }
  if (b_i == 1) {
    if (q.c.size(1) == 1) {
      b_i = qf->a.size(1);
    } else {
      b_i = q.c.size(1);
    }
  } else if (i1 == 1) {
    if (xb.size(1) == 1) {
      b_i = qf->d.size(1);
    } else {
      b_i = xb.size(1);
    }
  } else if (qi->a.size(1) == 1) {
    b_i = qf->c.size(1);
  } else {
    b_i = qi->a.size(1);
  }
  if (xd.size(1) == 1) {
    i1 = qf->b.size(1);
  } else {
    i1 = xd.size(1);
  }
  if ((qi->a.size(1) == qf->c.size(1)) && (xb.size(1) == qf->d.size(1)) &&
      (i == nx) && (q.c.size(1) == qf->a.size(1)) && (k == xoffset) &&
      (xd.size(1) == qf->b.size(1)) && (b_i == i1)) {
    varargin_3.set_size(1, qi->a.size(1));
    nx = qi->a.size(1);
    for (i = 0; i < nx; i++) {
      varargin_3[i] =
          ((qi->a[i] * qf->c[i] - xb[i] * qf->d[i]) + q.c[i] * qf->a[i]) +
          xd[i] * qf->b[i];
    }
  } else {
    binary_expand_op(varargin_3, qi, qf, xb, &q, xd);
  }
  if (qi->a.size(1) == 1) {
    i = qf->d.size(1);
  } else {
    i = qi->a.size(1);
  }
  if (xb.size(1) == 1) {
    nx = qf->c.size(1);
  } else {
    nx = xb.size(1);
  }
  if (qi->a.size(1) == 1) {
    k = qf->d.size(1);
  } else {
    k = qi->a.size(1);
  }
  if (k == 1) {
    if (xb.size(1) == 1) {
      k = qf->c.size(1);
    } else {
      k = xb.size(1);
    }
  } else if (qi->a.size(1) == 1) {
    k = qf->d.size(1);
  } else {
    k = qi->a.size(1);
  }
  if (q.c.size(1) == 1) {
    xoffset = qf->b.size(1);
  } else {
    xoffset = q.c.size(1);
  }
  if (qi->a.size(1) == 1) {
    b_i = qf->d.size(1);
  } else {
    b_i = qi->a.size(1);
  }
  if (b_i == 1) {
    if (xb.size(1) == 1) {
      b_i = qf->c.size(1);
    } else {
      b_i = xb.size(1);
    }
  } else if (qi->a.size(1) == 1) {
    b_i = qf->d.size(1);
  } else {
    b_i = qi->a.size(1);
  }
  if (qi->a.size(1) == 1) {
    i1 = qf->d.size(1);
  } else {
    i1 = qi->a.size(1);
  }
  if (b_i == 1) {
    if (q.c.size(1) == 1) {
      b_i = qf->b.size(1);
    } else {
      b_i = q.c.size(1);
    }
  } else if (i1 == 1) {
    if (xb.size(1) == 1) {
      b_i = qf->c.size(1);
    } else {
      b_i = xb.size(1);
    }
  } else if (qi->a.size(1) == 1) {
    b_i = qf->d.size(1);
  } else {
    b_i = qi->a.size(1);
  }
  if (xd.size(1) == 1) {
    i1 = qf->a.size(1);
  } else {
    i1 = xd.size(1);
  }
  if ((qi->a.size(1) == qf->d.size(1)) && (xb.size(1) == qf->c.size(1)) &&
      (i == nx) && (q.c.size(1) == qf->b.size(1)) && (k == xoffset) &&
      (xd.size(1) == qf->a.size(1)) && (b_i == i1)) {
    nx = qi->a.size(1) - 1;
    xb.set_size(1, qi->a.size(1));
    for (i = 0; i <= nx; i++) {
      xb[i] = ((qi->a[i] * qf->d[i] + xb[i] * qf->c[i]) - q.c[i] * qf->b[i]) +
              xd[i] * qf->a[i];
    }
  } else {
    binary_expand_op(xb, qi, qf, &q, xd);
  }
  if (varargin_1.size(1) == 1) {
    i = varargin_2.size(1);
  } else {
    i = varargin_1.size(1);
  }
  if (varargin_1.size(1) == 1) {
    nx = varargin_2.size(1);
  } else {
    nx = varargin_1.size(1);
  }
  if (nx == 1) {
    nx = varargin_3.size(1);
  } else if (varargin_1.size(1) == 1) {
    nx = varargin_2.size(1);
  } else {
    nx = varargin_1.size(1);
  }
  if ((varargin_1.size(1) == varargin_2.size(1)) && (i == varargin_3.size(1)) &&
      (nx == xb.size(1))) {
    xd.set_size(1, varargin_1.size(1));
    nx = varargin_1.size(1);
    for (i = 0; i < nx; i++) {
      scale = varargin_1[i];
      absxk = varargin_2[i];
      t = varargin_3[i];
      yv = xb[i];
      xd[i] = ((scale * scale + absxk * absxk) + t * t) + yv * yv;
    }
  } else {
    e_binary_expand_op(xd, varargin_1, varargin_2, varargin_3, xb);
  }
  nx = xd.size(1);
  for (k = 0; k < nx; k++) {
    xd[k] = std::sqrt(xd[k]);
  }
  if (varargin_1.size(1) == xd.size(1)) {
    deltaQuat.a.set_size(1, varargin_1.size(1));
    nx = varargin_1.size(1);
    for (i = 0; i < nx; i++) {
      deltaQuat.a[i] = varargin_1[i] / xd[i];
    }
  } else {
    g_binary_expand_op(&deltaQuat, varargin_1, xd);
  }
  if (varargin_2.size(1) == xd.size(1)) {
    deltaQuat.b.set_size(1, varargin_2.size(1));
    nx = varargin_2.size(1);
    for (i = 0; i < nx; i++) {
      deltaQuat.b[i] = varargin_2[i] / xd[i];
    }
  } else {
    f_binary_expand_op(&deltaQuat, varargin_2, xd);
  }
  if (varargin_3.size(1) == xd.size(1)) {
    deltaQuat.c.set_size(1, varargin_3.size(1));
    nx = varargin_3.size(1);
    for (i = 0; i < nx; i++) {
      deltaQuat.c[i] = varargin_3[i] / xd[i];
    }
  } else {
    e_binary_expand_op(&deltaQuat, varargin_3, xd);
  }
  if (xb.size(1) == xd.size(1)) {
    deltaQuat.d.set_size(1, xb.size(1));
    nx = xb.size(1);
    for (i = 0; i < nx; i++) {
      deltaQuat.d[i] = xb[i] / xd[i];
    }
  } else {
    binary_expand_op(&deltaQuat, xb, xd);
  }
  idx.set_size(1, deltaQuat.a.size(1));
  nx = deltaQuat.a.size(1);
  for (i = 0; i < nx; i++) {
    idx[i] = (deltaQuat.a[i] < 0.0);
  }
  xoffset = idx.size(1) - 1;
  nx = 0;
  for (b_i = 0; b_i <= xoffset; b_i++) {
    if (idx[b_i]) {
      nx++;
    }
  }
  r.set_size(1, nx);
  nx = 0;
  for (b_i = 0; b_i <= xoffset; b_i++) {
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
  xd.set_size(1, r.size(1));
  nx = r.size(1);
  for (i = 0; i < nx; i++) {
    xd[i] = deltaQuat.d[r[i] - 1];
  }
  xoffset = idx.size(1) - 1;
  nx = 0;
  for (b_i = 0; b_i <= xoffset; b_i++) {
    if (idx[b_i]) {
      nx++;
    }
  }
  r1.set_size(1, nx);
  nx = 0;
  for (b_i = 0; b_i <= xoffset; b_i++) {
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
  xoffset = idx.size(1) - 1;
  nx = 0;
  for (b_i = 0; b_i <= xoffset; b_i++) {
    if (idx[b_i]) {
      nx++;
    }
  }
  r2.set_size(1, nx);
  nx = 0;
  for (b_i = 0; b_i <= xoffset; b_i++) {
    if (idx[b_i]) {
      r2[nx] = b_i + 1;
      nx++;
    }
  }
  nx = varargin_2.size(1) - 1;
  for (i = 0; i <= nx; i++) {
    deltaQuat.b[r2[i] - 1] = -varargin_2[i];
  }
  xoffset = idx.size(1) - 1;
  nx = 0;
  for (b_i = 0; b_i <= xoffset; b_i++) {
    if (idx[b_i]) {
      nx++;
    }
  }
  r3.set_size(1, nx);
  nx = 0;
  for (b_i = 0; b_i <= xoffset; b_i++) {
    if (idx[b_i]) {
      r3[nx] = b_i + 1;
      nx++;
    }
  }
  nx = varargin_3.size(1) - 1;
  for (i = 0; i <= nx; i++) {
    deltaQuat.c[r3[i] - 1] = -varargin_3[i];
  }
  xoffset = idx.size(1) - 1;
  nx = 0;
  for (b_i = 0; b_i <= xoffset; b_i++) {
    if (idx[b_i]) {
      nx++;
    }
  }
  r4.set_size(1, nx);
  nx = 0;
  for (b_i = 0; b_i <= xoffset; b_i++) {
    if (idx[b_i]) {
      r4[nx] = b_i + 1;
      nx++;
    }
  }
  nx = xd.size(1) - 1;
  for (i = 0; i <= nx; i++) {
    deltaQuat.d[r4[i] - 1] = -xd[i];
  }
  if (deltaQuat.a.size(1) == 1) {
    i = deltaQuat.b.size(1);
  } else {
    i = deltaQuat.a.size(1);
  }
  if (deltaQuat.a.size(1) == 1) {
    nx = deltaQuat.b.size(1);
  } else {
    nx = deltaQuat.a.size(1);
  }
  if (nx == 1) {
    nx = deltaQuat.c.size(1);
  } else if (deltaQuat.a.size(1) == 1) {
    nx = deltaQuat.b.size(1);
  } else {
    nx = deltaQuat.a.size(1);
  }
  if ((deltaQuat.a.size(1) == deltaQuat.b.size(1)) &&
      (i == deltaQuat.c.size(1)) && (nx == deltaQuat.d.size(1))) {
    xd.set_size(1, deltaQuat.a.size(1));
    nx = deltaQuat.a.size(1);
    for (i = 0; i < nx; i++) {
      scale = deltaQuat.a[i];
      absxk = deltaQuat.b[i];
      t = deltaQuat.c[i];
      yv = deltaQuat.d[i];
      xd[i] = ((scale * scale + absxk * absxk) + t * t) + yv * yv;
    }
  } else {
    binary_expand_op(xd, &deltaQuat);
  }
  nx = xd.size(1);
  for (k = 0; k < nx; k++) {
    xd[k] = std::sqrt(xd[k]);
  }
  if (deltaQuat.a.size(1) == xd.size(1)) {
    qn.a.set_size(1, deltaQuat.a.size(1));
    nx = deltaQuat.a.size(1);
    for (i = 0; i < nx; i++) {
      qn.a[i] = deltaQuat.a[i] / xd[i];
    }
  } else {
    g_binary_expand_op(&qn, &deltaQuat, xd);
  }
  if (deltaQuat.b.size(1) == xd.size(1)) {
    qn.b.set_size(1, deltaQuat.b.size(1));
    nx = deltaQuat.b.size(1);
    for (i = 0; i < nx; i++) {
      qn.b[i] = deltaQuat.b[i] / xd[i];
    }
  } else {
    f_binary_expand_op(&qn, &deltaQuat, xd);
  }
  if (deltaQuat.c.size(1) == xd.size(1)) {
    qn.c.set_size(1, deltaQuat.c.size(1));
    nx = deltaQuat.c.size(1);
    for (i = 0; i < nx; i++) {
      qn.c[i] = deltaQuat.c[i] / xd[i];
    }
  } else {
    e_binary_expand_op(&qn, &deltaQuat, xd);
  }
  if (deltaQuat.d.size(1) == xd.size(1)) {
    qn.d.set_size(1, deltaQuat.d.size(1));
    nx = deltaQuat.d.size(1);
    for (i = 0; i < nx; i++) {
      qn.d[i] = deltaQuat.d[i] / xd[i];
    }
  } else {
    binary_expand_op(&qn, &deltaQuat, xd);
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
  rv.set_size(m.size(0), 3);
  for (i = 0; i < 3; i++) {
    for (xoffset = 0; xoffset < nx; xoffset++) {
      scale = m[xoffset + m.size(0) * (i + 1)];
      rv[xoffset + rv.size(0) * i] = scale * scale;
    }
  }
  if (rv.size(0) == 0) {
    mag.set_size(0);
  } else {
    nx = rv.size(0);
    mag.set_size(rv.size(0));
    for (b_i = 0; b_i < nx; b_i++) {
      mag[b_i] = rv[b_i];
    }
    for (k = 0; k < 2; k++) {
      xoffset = (k + 1) * nx;
      for (b_i = 0; b_i < nx; b_i++) {
        mag[b_i] = mag[b_i] + rv[xoffset + b_i];
      }
    }
  }
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
      rv[nx] = ang[nx] * m[nx + m.size(0)] / mag[nx];
      rv[nx + rv.size(0)] = ang[nx] * m[nx + m.size(0) * 2] / mag[nx];
      rv[nx + rv.size(0) * 2] = ang[nx] * m[nx + m.size(0) * 3] / mag[nx];
    }
  }
  dtheta.set_size(rv.size(0));
  nx = rv.size(0);
  for (i = 0; i < nx; i++) {
    dtheta[i] = 0.0;
  }
  nx = rv.size(0);
  for (xoffset = 0; xoffset < nx; xoffset++) {
    scale = 3.3121686421112381E-170;
    absxk = std::abs(rv[xoffset]);
    if (absxk > 3.3121686421112381E-170) {
      yv = 1.0;
      scale = absxk;
    } else {
      t = absxk / 3.3121686421112381E-170;
      yv = t * t;
    }
    absxk = std::abs(rv[xoffset + nx]);
    if (absxk > scale) {
      t = scale / absxk;
      yv = yv * t * t + 1.0;
      scale = absxk;
    } else {
      t = absxk / scale;
      yv += t * t;
    }
    absxk = std::abs(rv[xoffset + (nx << 1)]);
    if (absxk > scale) {
      t = scale / absxk;
      yv = yv * t * t + 1.0;
      scale = absxk;
    } else {
      t = absxk / scale;
      yv += t * t;
    }
    dtheta[xoffset] = scale * std::sqrt(yv);
  }
  nx = dtheta.size(0);
  xoffset = rv.size(0);
  if (nx <= xoffset) {
    xoffset = nx;
  }
  if (dtheta.size(0) == 1) {
    xoffset = rv.size(0);
  } else if (rv.size(0) == 1) {
    xoffset = dtheta.size(0);
  } else if (rv.size(0) == dtheta.size(0)) {
    xoffset = rv.size(0);
  }
  e.set_size(xoffset, 3);
  nx = dtheta.size(0);
  xoffset = rv.size(0);
  if (nx <= xoffset) {
    xoffset = nx;
  }
  if (dtheta.size(0) == 1) {
    xoffset = rv.size(0);
  } else if (rv.size(0) == 1) {
    xoffset = dtheta.size(0);
  } else if (rv.size(0) == dtheta.size(0)) {
    xoffset = rv.size(0);
  }
  if (xoffset != 0) {
    nx = (rv.size(0) != 1);
    xoffset = (dtheta.size(0) != 1);
    for (k = 0; k < 3; k++) {
      i = e.size(0) - 1;
      for (b_i = 0; b_i <= i; b_i++) {
        e[b_i + e.size(0) * k] =
            rv[nx * b_i + rv.size(0) * k] / dtheta[xoffset * b_i];
      }
    }
  }
  b_dtheta.set_size(dtheta.size(0));
  nx = dtheta.size(0);
  for (i = 0; i < nx; i++) {
    b_dtheta[i] = (dtheta[i] <= 0.0);
  }
  eml_find(b_dtheta, r5);
  ang.set_size(r5.size(0));
  nx = r5.size(0);
  for (i = 0; i < nx; i++) {
    ang[i] = r5[i];
  }
  nx = ang.size(0);
  for (i = 0; i < 3; i++) {
    for (xoffset = 0; xoffset < nx; xoffset++) {
      e[(static_cast<int>(ang[xoffset]) + e.size(0) * i) - 1] = 0.0;
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
  int i;
  int i1;
  int i2;
  int i3;
  int i4;
  int i5;
  int i6;
  int i7;
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
  if (n - 1.0 < 2.0) {
    i = 0;
    i1 = 0;
    i2 = 0;
  } else {
    i = 1;
    i1 = static_cast<int>(n - 1.0);
    i2 = 1;
  }
  loop_ub = i1 - i;
  i1 = static_cast<int>((n - 1.0) + -1.0);
  i3 = static_cast<int>(-((-1.0 - (n - 2.0)) + 2.0));
  if (n - 1.0 < 2.0) {
    i4 = 0;
    i5 = 0;
    i6 = 0;
    i7 = 0;
  } else {
    i4 = 1;
    i5 = static_cast<int>(n - 1.0);
    i6 = 1;
    i7 = static_cast<int>(n - 1.0);
  }
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
    bool MATRIX_INPUT_AND_P_IS_TWO;
    bool VECTOR_INPUT_AND_P_IS_NUMERIC;
    for (loop_ub_tmp = 0; loop_ub_tmp < 3; loop_ub_tmp++) {
      for (int j{0}; j < loop_ub; j++) {
        wprev[(i2 + j) + wprev.size(0) * loop_ub_tmp] =
            w[(i + j) + w.size(0) * loop_ub_tmp];
      }
    }
    for (loop_ub_tmp = 0; loop_ub_tmp < i1; loop_ub_tmp++) {
      a[loop_ub_tmp + 1] = 2.0 / h[loop_ub_tmp];
      b_tmp = h[loop_ub_tmp + 1];
      b[loop_ub_tmp + 1] = 4.0 / h[loop_ub_tmp] + 4.0 / b_tmp;
      c[loop_ub_tmp + 1] = 2.0 / b_tmp;
      if (dtheta[loop_ub_tmp] > 1.0E-6) {
        ca = std::cos(dtheta[loop_ub_tmp]);
        sa = std::sin(dtheta[loop_ub_tmp]);
        b0_tmp = e[loop_ub_tmp + e.size(0)];
        b_b0_tmp = e[loop_ub_tmp + e.size(0) * 2];
        c_b0_tmp = wprev[(loop_ub_tmp + wprev.size(0) * 2) + 1];
        absxk = wprev[(loop_ub_tmp + wprev.size(0)) + 1];
        temp2_idx_0 = b0_tmp * c_b0_tmp - absxk * b_b0_tmp;
        windote = e[loop_ub_tmp];
        t = wprev[loop_ub_tmp + 1];
        temp2_idx_1 = t * b_b0_tmp - windote * c_b0_tmp;
        temp1_idx_2 = windote * absxk - t * b0_tmp;
        windote = (t * e[loop_ub_tmp] + absxk * e[loop_ub_tmp + e.size(0)]) +
                  c_b0_tmp * e[loop_ub_tmp + e.size(0) * 2];
        b_a = 0.5 *
              (((t * t + absxk * absxk) + c_b0_tmp * c_b0_tmp) -
               windote * windote) *
              (dtheta[loop_ub_tmp] - sa) / (1.0 - ca);
        absxk = windote * (dtheta[loop_ub_tmp] * sa - 2.0 * (1.0 - ca)) /
                (dtheta[loop_ub_tmp] * (1.0 - ca));
        b0_tmp = e[loop_ub_tmp + e.size(0) * 2];
        b_b0_tmp = e[loop_ub_tmp + e.size(0)];
        c_b0_tmp = e[loop_ub_tmp];
        temp1_idx_0 = b_a * e[loop_ub_tmp] +
                      absxk * (temp2_idx_1 * b0_tmp - b_b0_tmp * temp1_idx_2);
        temp1_idx_1 = b_a * e[loop_ub_tmp + e.size(0)] +
                      absxk * (c_b0_tmp * temp1_idx_2 - temp2_idx_0 * b0_tmp);
        temp1_idx_2 = b_a * e[loop_ub_tmp + e.size(0) * 2] +
                      absxk * (temp2_idx_0 * b_b0_tmp - c_b0_tmp * temp2_idx_1);
      } else {
        temp1_idx_0 = 0.0;
        temp1_idx_1 = 0.0;
        temp1_idx_2 = 0.0;
      }
      t = h[loop_ub_tmp] * h[loop_ub_tmp];
      windote = b_tmp * b_tmp;
      absxk = dtheta[loop_ub_tmp + 1];
      w[loop_ub_tmp + 1] = 6.0 * (dtheta[loop_ub_tmp] * e[loop_ub_tmp] / t +
                                  absxk * e[loop_ub_tmp + 1] / windote) -
                           temp1_idx_0;
      w[(loop_ub_tmp + w.size(0)) + 1] =
          6.0 * (dtheta[loop_ub_tmp] * e[loop_ub_tmp + e.size(0)] / t +
                 absxk * e[(loop_ub_tmp + e.size(0)) + 1] / windote) -
          temp1_idx_1;
      w[(loop_ub_tmp + w.size(0) * 2) + 1] =
          6.0 * (dtheta[loop_ub_tmp] * e[loop_ub_tmp + e.size(0) * 2] / t +
                 absxk * e[(loop_ub_tmp + e.size(0) * 2) + 1] / windote) -
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
    for (loop_ub_tmp = 0; loop_ub_tmp < i1; loop_ub_tmp++) {
      b_tmp = a[loop_ub_tmp + 2];
      b[loop_ub_tmp + 2] =
          b[loop_ub_tmp + 2] - c[loop_ub_tmp + 1] * b_tmp / b[loop_ub_tmp + 1];
      temp1_idx_0 = w[loop_ub_tmp + 1];
      temp1_idx_1 = w[(loop_ub_tmp + w.size(0)) + 1];
      temp1_idx_2 = w[(loop_ub_tmp + w.size(0) * 2) + 1];
      b0_tmp = dtheta[loop_ub_tmp + 1];
      if (b0_tmp > 1.0E-6) {
        b_a = std::sin(b0_tmp) / b0_tmp;
        absxk = (std::cos(b0_tmp) - 1.0) / b0_tmp;
        b_b0_tmp = e[loop_ub_tmp + 1];
        c_b0_tmp = e[(loop_ub_tmp + e.size(0)) + 1];
        b0_tmp = e[(loop_ub_tmp + e.size(0) * 2) + 1];
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
      w[loop_ub_tmp + 2] =
          w[loop_ub_tmp + 2] - temp1_idx_0 * b_tmp / b[loop_ub_tmp + 1];
      w[(loop_ub_tmp + w.size(0)) + 2] =
          w[(loop_ub_tmp + w.size(0)) + 2] -
          temp1_idx_1 * b_tmp / b[loop_ub_tmp + 1];
      w[(loop_ub_tmp + w.size(0) * 2) + 2] =
          w[(loop_ub_tmp + w.size(0) * 2) + 2] -
          temp1_idx_2 * b_tmp / b[loop_ub_tmp + 1];
    }
    windote = b[static_cast<int>(n - 1.0) - 1];
    w[static_cast<int>(n - 1.0) - 1] =
        w[static_cast<int>(n - 1.0) - 1] / windote;
    w[(static_cast<int>(n - 1.0) + w.size(0)) - 1] =
        w[(static_cast<int>(n - 1.0) + w.size(0)) - 1] / windote;
    w[(static_cast<int>(n - 1.0) + w.size(0) * 2) - 1] =
        w[(static_cast<int>(n - 1.0) + w.size(0) * 2) - 1] / windote;
    for (loop_ub_tmp = 0; loop_ub_tmp < i3; loop_ub_tmp++) {
      t = (n - 2.0) + -static_cast<double>(loop_ub_tmp);
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
    m = i5 - i4;
    if (m == i7 - i6) {
      x.set_size(m, 3);
      for (loop_ub_tmp = 0; loop_ub_tmp < 3; loop_ub_tmp++) {
        for (int j{0}; j < m; j++) {
          x[j + x.size(0) * loop_ub_tmp] =
              w[(i4 + j) + w.size(0) * loop_ub_tmp] -
              wprev[(i6 + j) + wprev.size(0) * loop_ub_tmp];
        }
      }
    } else {
      binary_expand_op(x, w, i4, i5 - 1, wprev, i6, i7 - 1);
    }
    VECTOR_INPUT_AND_P_IS_NUMERIC = false;
    MATRIX_INPUT_AND_P_IS_TWO = false;
    if (x.size(0) == 1) {
      VECTOR_INPUT_AND_P_IS_NUMERIC = true;
    } else {
      MATRIX_INPUT_AND_P_IS_TWO = true;
    }
    if (x.size(0) == 0) {
      ca = 0.0;
    } else if (MATRIX_INPUT_AND_P_IS_TWO) {
      m = x.size(0);
      ca = 0.0;
      for (int j{0}; j < 3; j++) {
        for (loop_ub_tmp = 0; loop_ub_tmp < m; loop_ub_tmp++) {
          windote = std::abs(x[loop_ub_tmp + x.size(0) * j]);
          if (std::isnan(windote) || (windote > ca)) {
            ca = windote;
          }
        }
      }
      if ((!std::isinf(ca)) && (!std::isnan(ca))) {
        ::coder::internal::svd(x, s);
        ca = s[0];
      }
    } else if (VECTOR_INPUT_AND_P_IS_NUMERIC) {
      m = x.size(0) * 3;
      ca = 0.0;
      if (m >= 1) {
        if (m == 1) {
          ca = std::abs(x[0]);
        } else {
          windote = 3.3121686421112381E-170;
          for (loop_ub_tmp = 0; loop_ub_tmp < m; loop_ub_tmp++) {
            absxk = std::abs(x[loop_ub_tmp]);
            if (absxk > windote) {
              t = windote / absxk;
              ca = ca * t * t + 1.0;
              windote = absxk;
            } else {
              t = absxk / windote;
              ca += t * t;
            }
          }
          ca = windote * std::sqrt(ca);
        }
      }
    } else {
      ca = rtNaN;
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
