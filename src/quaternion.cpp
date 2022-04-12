//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: quaternion.cpp
//
// MATLAB Coder version            : 5.4
// C/C++ source code generated on  : 12-Apr-2022 11:44:16
//

// Include Files
#include "quaternion.h"
#include "div.h"
#include "normalize.h"
#include "rotmat.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <cmath>
#include <string.h>

// Function Definitions
//
// Arguments    : const ::coder::array<double, 2U> &varargin_1
// Return Type  : void
//
namespace coder {
void quaternion::init(const ::coder::array<double, 2U> &varargin_1)
{
  array<double, 1U> b_varargin_1;
  if (varargin_1.size(0) == 0) {
    a.set_size(0, 4);
    b.set_size(0, 4);
    c.set_size(0, 4);
    d.set_size(0, 4);
  } else {
    int loop_ub;
    loop_ub = varargin_1.size(0);
    b_varargin_1.set_size(varargin_1.size(0));
    for (int i{0}; i < loop_ub; i++) {
      b_varargin_1[i] = varargin_1[i];
    }
    a.set_size(varargin_1.size(0), 1);
    loop_ub = varargin_1.size(0);
    for (int i{0}; i < loop_ub; i++) {
      a[i] = b_varargin_1[i];
    }
    loop_ub = varargin_1.size(0);
    b_varargin_1.set_size(varargin_1.size(0));
    for (int i{0}; i < loop_ub; i++) {
      b_varargin_1[i] = varargin_1[i + varargin_1.size(0)];
    }
    b.set_size(varargin_1.size(0), 1);
    loop_ub = varargin_1.size(0);
    for (int i{0}; i < loop_ub; i++) {
      b[i] = b_varargin_1[i];
    }
    loop_ub = varargin_1.size(0);
    b_varargin_1.set_size(varargin_1.size(0));
    for (int i{0}; i < loop_ub; i++) {
      b_varargin_1[i] = varargin_1[i + varargin_1.size(0) * 2];
    }
    c.set_size(varargin_1.size(0), 1);
    loop_ub = varargin_1.size(0);
    for (int i{0}; i < loop_ub; i++) {
      c[i] = b_varargin_1[i];
    }
    loop_ub = varargin_1.size(0);
    b_varargin_1.set_size(varargin_1.size(0));
    for (int i{0}; i < loop_ub; i++) {
      b_varargin_1[i] = varargin_1[i + varargin_1.size(0) * 3];
    }
    d.set_size(varargin_1.size(0), 1);
    loop_ub = varargin_1.size(0);
    for (int i{0}; i < loop_ub; i++) {
      d[i] = b_varargin_1[i];
    }
  }
}

//
// Arguments    : void
// Return Type  : void
//
void quaternion::init()
{
  a.set_size(1, 1);
  a[0] = 0.0;
  b.set_size(1, 1);
  b[0] = 0.0;
  c.set_size(1, 1);
  c[0] = 0.0;
  d.set_size(1, 1);
  d[0] = 0.0;
}

//
// Arguments    : ::coder::array<double, 3U> &r
// Return Type  : void
//
void quaternion::rotmat(::coder::array<double, 3U> &r)
{
  array<double, 2U> n;
  array<double, 1U> aasq;
  array<double, 1U> ab2;
  array<double, 1U> ac2;
  array<double, 1U> ad2;
  array<double, 1U> bbsq;
  array<double, 1U> bc2;
  array<double, 1U> bd2;
  array<double, 1U> ccsq;
  array<double, 1U> cd2;
  array<double, 1U> ddsq;
  double b_d;
  int k;
  int nx;
  if (a.size(1) == 1) {
    nx = b.size(1);
  } else {
    nx = a.size(1);
  }
  if (a.size(1) == 1) {
    k = b.size(1);
  } else {
    k = a.size(1);
  }
  if (k == 1) {
    k = c.size(1);
  } else if (a.size(1) == 1) {
    k = b.size(1);
  } else {
    k = a.size(1);
  }
  if ((a.size(1) == b.size(1)) && (nx == c.size(1)) && (k == d.size(1))) {
    n.set_size(1, a.size(1));
    nx = a.size(1);
    for (k = 0; k < nx; k++) {
      double d1;
      double d2;
      double d3;
      b_d = a[k];
      d1 = b[k];
      d2 = c[k];
      d3 = d[k];
      n[k] = ((b_d * b_d + d1 * d1) + d2 * d2) + d3 * d3;
    }
  } else {
    binary_expand_op(n, this);
  }
  nx = n.size(1);
  for (k = 0; k < nx; k++) {
    n[k] = std::sqrt(n[k]);
  }
  if (a.size(1) == n.size(1)) {
    nx = a.size(1) - 1;
    a.set_size(1, a.size(1));
    for (k = 0; k <= nx; k++) {
      a[k] = a[k] / n[k];
    }
  } else {
    g_binary_expand_op(this, n);
  }
  if (b.size(1) == n.size(1)) {
    nx = b.size(1) - 1;
    b.set_size(1, b.size(1));
    for (k = 0; k <= nx; k++) {
      b[k] = b[k] / n[k];
    }
  } else {
    f_binary_expand_op(this, n);
  }
  if (c.size(1) == n.size(1)) {
    nx = c.size(1) - 1;
    c.set_size(1, c.size(1));
    for (k = 0; k <= nx; k++) {
      c[k] = c[k] / n[k];
    }
  } else {
    e_binary_expand_op(this, n);
  }
  if (d.size(1) == n.size(1)) {
    nx = d.size(1) - 1;
    d.set_size(1, d.size(1));
    for (k = 0; k <= nx; k++) {
      d[k] = d[k] / n[k];
    }
  } else {
    binary_expand_op(this, n);
  }
  if (a.size(1) == b.size(1)) {
    ab2.set_size(a.size(1));
    nx = a.size(1);
    for (k = 0; k < nx; k++) {
      ab2[k] = a[k] * b[k] * 2.0;
    }
  } else {
    i_binary_expand_op(ab2, this);
  }
  if (a.size(1) == c.size(1)) {
    ac2.set_size(a.size(1));
    nx = a.size(1);
    for (k = 0; k < nx; k++) {
      ac2[k] = a[k] * c[k] * 2.0;
    }
  } else {
    h_binary_expand_op(ac2, this);
  }
  if (a.size(1) == d.size(1)) {
    ad2.set_size(a.size(1));
    nx = a.size(1);
    for (k = 0; k < nx; k++) {
      ad2[k] = a[k] * d[k] * 2.0;
    }
  } else {
    g_binary_expand_op(ad2, this);
  }
  if (b.size(1) == c.size(1)) {
    bc2.set_size(b.size(1));
    nx = b.size(1);
    for (k = 0; k < nx; k++) {
      bc2[k] = b[k] * c[k] * 2.0;
    }
  } else {
    f_binary_expand_op(bc2, this);
  }
  if (b.size(1) == d.size(1)) {
    bd2.set_size(b.size(1));
    nx = b.size(1);
    for (k = 0; k < nx; k++) {
      bd2[k] = b[k] * d[k] * 2.0;
    }
  } else {
    e_binary_expand_op(bd2, this);
  }
  if (c.size(1) == d.size(1)) {
    cd2.set_size(c.size(1));
    nx = c.size(1);
    for (k = 0; k < nx; k++) {
      cd2[k] = c[k] * d[k] * 2.0;
    }
  } else {
    binary_expand_op(cd2, this);
  }
  aasq.set_size(a.size(1));
  nx = a.size(1);
  for (k = 0; k < nx; k++) {
    b_d = a[k];
    aasq[k] = b_d * b_d * 2.0 - 1.0;
  }
  bbsq.set_size(b.size(1));
  nx = b.size(1);
  for (k = 0; k < nx; k++) {
    b_d = b[k];
    bbsq[k] = b_d * b_d * 2.0;
  }
  ccsq.set_size(c.size(1));
  nx = c.size(1);
  for (k = 0; k < nx; k++) {
    b_d = c[k];
    ccsq[k] = b_d * b_d * 2.0;
  }
  ddsq.set_size(d.size(1));
  nx = d.size(1);
  for (k = 0; k < nx; k++) {
    b_d = d[k];
    ddsq[k] = b_d * b_d * 2.0;
  }
  r.set_size(3, 3, a.size(1));
  nx = 9 * a.size(1);
  for (k = 0; k < nx; k++) {
    r[k] = 0.0;
  }
  k = a.size(1);
  for (nx = 0; nx < k; nx++) {
    r[9 * nx] = aasq[nx] + bbsq[nx];
    r[9 * nx + 3] = bc2[nx] + ad2[nx];
    r[9 * nx + 6] = bd2[nx] - ac2[nx];
    r[9 * nx + 1] = bc2[nx] - ad2[nx];
    r[9 * nx + 4] = aasq[nx] + ccsq[nx];
    r[9 * nx + 7] = cd2[nx] + ab2[nx];
    r[9 * nx + 2] = bd2[nx] + ac2[nx];
    r[9 * nx + 5] = cd2[nx] - ab2[nx];
    r[9 * nx + 8] = aasq[nx] + ddsq[nx];
  }
  nx = 1;
  if (r.size(2) != 1) {
    nx = r.size(2);
  }
  r.set_size(3, 3, nx);
}

//
// Arguments    : coder::array<double, 2U> &in1
//                const coder::quaternion *in2
//                const coder::quaternion *in3
//                const coder::array<double, 2U> &in4
//                const coder::quaternion *in5
//                const coder::array<double, 2U> &in6
// Return Type  : void
//
} // namespace coder
void binary_expand_op(coder::array<double, 2U> &in1,
                      const coder::quaternion *in2,
                      const coder::quaternion *in3,
                      const coder::array<double, 2U> &in4,
                      const coder::quaternion *in5,
                      const coder::array<double, 2U> &in6)
{
  int i;
  int loop_ub;
  int stride_0_1;
  int stride_1_1;
  int stride_2_1;
  int stride_3_1;
  int stride_4_1;
  int stride_5_1;
  int stride_6_1;
  int stride_7_1;
  if (in3->b.size(1) == 1) {
    i = in6.size(1);
  } else {
    i = in3->b.size(1);
  }
  if (in3->a.size(1) == 1) {
    stride_0_1 = in5->c.size(1);
  } else {
    stride_0_1 = in3->a.size(1);
  }
  if (in3->d.size(1) == 1) {
    stride_1_1 = in4.size(1);
  } else {
    stride_1_1 = in3->d.size(1);
  }
  if (i == 1) {
    if (stride_0_1 == 1) {
      if (stride_1_1 == 1) {
        if (in3->c.size(1) == 1) {
          i = in2->a.size(1);
        } else {
          i = in3->c.size(1);
        }
      } else if (in3->d.size(1) == 1) {
        i = in4.size(1);
      } else {
        i = in3->d.size(1);
      }
    } else if (in3->a.size(1) == 1) {
      i = in5->c.size(1);
    } else {
      i = in3->a.size(1);
    }
  } else if (in3->b.size(1) == 1) {
    i = in6.size(1);
  } else {
    i = in3->b.size(1);
  }
  in1.set_size(1, i);
  stride_0_1 = (in2->a.size(1) != 1);
  stride_1_1 = (in3->c.size(1) != 1);
  stride_2_1 = (in4.size(1) != 1);
  stride_3_1 = (in3->d.size(1) != 1);
  stride_4_1 = (in5->c.size(1) != 1);
  stride_5_1 = (in3->a.size(1) != 1);
  stride_6_1 = (in6.size(1) != 1);
  stride_7_1 = (in3->b.size(1) != 1);
  if (in3->b.size(1) == 1) {
    i = in6.size(1);
  } else {
    i = in3->b.size(1);
  }
  if (i == 1) {
    if (in3->a.size(1) == 1) {
      i = in5->c.size(1);
    } else {
      i = in3->a.size(1);
    }
    if (i == 1) {
      if (in3->d.size(1) == 1) {
        i = in4.size(1);
      } else {
        i = in3->d.size(1);
      }
      if (i == 1) {
        if (in3->c.size(1) == 1) {
          loop_ub = in2->a.size(1);
        } else {
          loop_ub = in3->c.size(1);
        }
      } else if (in3->d.size(1) == 1) {
        loop_ub = in4.size(1);
      } else {
        loop_ub = in3->d.size(1);
      }
    } else if (in3->a.size(1) == 1) {
      loop_ub = in5->c.size(1);
    } else {
      loop_ub = in3->a.size(1);
    }
  } else if (in3->b.size(1) == 1) {
    loop_ub = in6.size(1);
  } else {
    loop_ub = in3->b.size(1);
  }
  for (i = 0; i < loop_ub; i++) {
    in1[i] = ((in2->a[i * stride_0_1] * in3->c[i * stride_1_1] -
               in4[i * stride_2_1] * in3->d[i * stride_3_1]) +
              in5->c[i * stride_4_1] * in3->a[i * stride_5_1]) +
             in6[i * stride_6_1] * in3->b[i * stride_7_1];
  }
}

//
// Arguments    : coder::array<double, 2U> &in1
//                const coder::quaternion *in2
//                const coder::quaternion *in3
//                const coder::quaternion *in4
//                const coder::array<double, 2U> &in5
// Return Type  : void
//
void binary_expand_op(coder::array<double, 2U> &in1,
                      const coder::quaternion *in2,
                      const coder::quaternion *in3,
                      const coder::quaternion *in4,
                      const coder::array<double, 2U> &in5)
{
  coder::array<double, 2U> b_in2;
  int i;
  int loop_ub;
  int stride_0_1;
  int stride_1_1;
  int stride_2_1;
  int stride_3_1;
  int stride_4_1;
  int stride_5_1;
  int stride_6_1;
  int stride_7_1;
  if (in3->a.size(1) == 1) {
    i = in5.size(1);
  } else {
    i = in3->a.size(1);
  }
  if (in3->b.size(1) == 1) {
    stride_0_1 = in4->c.size(1);
  } else {
    stride_0_1 = in3->b.size(1);
  }
  if (in3->c.size(1) == 1) {
    stride_1_1 = in1.size(1);
  } else {
    stride_1_1 = in3->c.size(1);
  }
  if (i == 1) {
    if (stride_0_1 == 1) {
      if (stride_1_1 == 1) {
        if (in3->d.size(1) == 1) {
          i = in2->a.size(1);
        } else {
          i = in3->d.size(1);
        }
      } else if (in3->c.size(1) == 1) {
        i = in1.size(1);
      } else {
        i = in3->c.size(1);
      }
    } else if (in3->b.size(1) == 1) {
      i = in4->c.size(1);
    } else {
      i = in3->b.size(1);
    }
  } else if (in3->a.size(1) == 1) {
    i = in5.size(1);
  } else {
    i = in3->a.size(1);
  }
  b_in2.set_size(1, i);
  stride_0_1 = (in2->a.size(1) != 1);
  stride_1_1 = (in3->d.size(1) != 1);
  stride_2_1 = (in1.size(1) != 1);
  stride_3_1 = (in3->c.size(1) != 1);
  stride_4_1 = (in4->c.size(1) != 1);
  stride_5_1 = (in3->b.size(1) != 1);
  stride_6_1 = (in5.size(1) != 1);
  stride_7_1 = (in3->a.size(1) != 1);
  if (in3->a.size(1) == 1) {
    i = in5.size(1);
  } else {
    i = in3->a.size(1);
  }
  if (i == 1) {
    if (in3->b.size(1) == 1) {
      i = in4->c.size(1);
    } else {
      i = in3->b.size(1);
    }
    if (i == 1) {
      if (in3->c.size(1) == 1) {
        i = in1.size(1);
      } else {
        i = in3->c.size(1);
      }
      if (i == 1) {
        if (in3->d.size(1) == 1) {
          loop_ub = in2->a.size(1);
        } else {
          loop_ub = in3->d.size(1);
        }
      } else if (in3->c.size(1) == 1) {
        loop_ub = in1.size(1);
      } else {
        loop_ub = in3->c.size(1);
      }
    } else if (in3->b.size(1) == 1) {
      loop_ub = in4->c.size(1);
    } else {
      loop_ub = in3->b.size(1);
    }
  } else if (in3->a.size(1) == 1) {
    loop_ub = in5.size(1);
  } else {
    loop_ub = in3->a.size(1);
  }
  for (i = 0; i < loop_ub; i++) {
    b_in2[i] = ((in2->a[i * stride_0_1] * in3->d[i * stride_1_1] +
                 in1[i * stride_2_1] * in3->c[i * stride_3_1]) -
                in4->c[i * stride_4_1] * in3->b[i * stride_5_1]) +
               in5[i * stride_6_1] * in3->a[i * stride_7_1];
  }
  in1.set_size(1, b_in2.size(1));
  loop_ub = b_in2.size(1);
  for (i = 0; i < loop_ub; i++) {
    in1[i] = b_in2[i];
  }
}

//
// Arguments    : coder::array<double, 2U> &in1
//                const coder::quaternion *in2
//                const coder::quaternion *in3
//                const coder::array<double, 2U> &in4
//                const coder::quaternion *in5
//                const coder::array<double, 2U> &in6
// Return Type  : void
//
void e_binary_expand_op(coder::array<double, 2U> &in1,
                        const coder::quaternion *in2,
                        const coder::quaternion *in3,
                        const coder::array<double, 2U> &in4,
                        const coder::quaternion *in5,
                        const coder::array<double, 2U> &in6)
{
  int i;
  int loop_ub;
  int stride_0_1;
  int stride_1_1;
  int stride_2_1;
  int stride_3_1;
  int stride_4_1;
  int stride_5_1;
  int stride_6_1;
  int stride_7_1;
  if (in3->c.size(1) == 1) {
    i = in6.size(1);
  } else {
    i = in3->c.size(1);
  }
  if (in3->d.size(1) == 1) {
    stride_0_1 = in5->c.size(1);
  } else {
    stride_0_1 = in3->d.size(1);
  }
  if (in3->a.size(1) == 1) {
    stride_1_1 = in4.size(1);
  } else {
    stride_1_1 = in3->a.size(1);
  }
  if (i == 1) {
    if (stride_0_1 == 1) {
      if (stride_1_1 == 1) {
        if (in3->b.size(1) == 1) {
          i = in2->a.size(1);
        } else {
          i = in3->b.size(1);
        }
      } else if (in3->a.size(1) == 1) {
        i = in4.size(1);
      } else {
        i = in3->a.size(1);
      }
    } else if (in3->d.size(1) == 1) {
      i = in5->c.size(1);
    } else {
      i = in3->d.size(1);
    }
  } else if (in3->c.size(1) == 1) {
    i = in6.size(1);
  } else {
    i = in3->c.size(1);
  }
  in1.set_size(1, i);
  stride_0_1 = (in2->a.size(1) != 1);
  stride_1_1 = (in3->b.size(1) != 1);
  stride_2_1 = (in4.size(1) != 1);
  stride_3_1 = (in3->a.size(1) != 1);
  stride_4_1 = (in5->c.size(1) != 1);
  stride_5_1 = (in3->d.size(1) != 1);
  stride_6_1 = (in6.size(1) != 1);
  stride_7_1 = (in3->c.size(1) != 1);
  if (in3->c.size(1) == 1) {
    i = in6.size(1);
  } else {
    i = in3->c.size(1);
  }
  if (i == 1) {
    if (in3->d.size(1) == 1) {
      i = in5->c.size(1);
    } else {
      i = in3->d.size(1);
    }
    if (i == 1) {
      if (in3->a.size(1) == 1) {
        i = in4.size(1);
      } else {
        i = in3->a.size(1);
      }
      if (i == 1) {
        if (in3->b.size(1) == 1) {
          loop_ub = in2->a.size(1);
        } else {
          loop_ub = in3->b.size(1);
        }
      } else if (in3->a.size(1) == 1) {
        loop_ub = in4.size(1);
      } else {
        loop_ub = in3->a.size(1);
      }
    } else if (in3->d.size(1) == 1) {
      loop_ub = in5->c.size(1);
    } else {
      loop_ub = in3->d.size(1);
    }
  } else if (in3->c.size(1) == 1) {
    loop_ub = in6.size(1);
  } else {
    loop_ub = in3->c.size(1);
  }
  for (i = 0; i < loop_ub; i++) {
    in1[i] = ((in2->a[i * stride_0_1] * in3->b[i * stride_1_1] +
               in4[i * stride_2_1] * in3->a[i * stride_3_1]) +
              in5->c[i * stride_4_1] * in3->d[i * stride_5_1]) -
             in6[i * stride_6_1] * in3->c[i * stride_7_1];
  }
}

//
// Arguments    : coder::array<double, 2U> &in1
//                const coder::quaternion *in2
//                const coder::quaternion *in3
//                const coder::array<double, 2U> &in4
//                const coder::quaternion *in5
//                const coder::array<double, 2U> &in6
// Return Type  : void
//
void f_binary_expand_op(coder::array<double, 2U> &in1,
                        const coder::quaternion *in2,
                        const coder::quaternion *in3,
                        const coder::array<double, 2U> &in4,
                        const coder::quaternion *in5,
                        const coder::array<double, 2U> &in6)
{
  int i;
  int loop_ub;
  int stride_0_1;
  int stride_1_1;
  int stride_2_1;
  int stride_3_1;
  int stride_4_1;
  int stride_5_1;
  int stride_6_1;
  int stride_7_1;
  if (in3->d.size(1) == 1) {
    i = in6.size(1);
  } else {
    i = in3->d.size(1);
  }
  if (in3->c.size(1) == 1) {
    stride_0_1 = in5->c.size(1);
  } else {
    stride_0_1 = in3->c.size(1);
  }
  if (in3->b.size(1) == 1) {
    stride_1_1 = in4.size(1);
  } else {
    stride_1_1 = in3->b.size(1);
  }
  if (i == 1) {
    if (stride_0_1 == 1) {
      if (stride_1_1 == 1) {
        if (in3->a.size(1) == 1) {
          i = in2->a.size(1);
        } else {
          i = in3->a.size(1);
        }
      } else if (in3->b.size(1) == 1) {
        i = in4.size(1);
      } else {
        i = in3->b.size(1);
      }
    } else if (in3->c.size(1) == 1) {
      i = in5->c.size(1);
    } else {
      i = in3->c.size(1);
    }
  } else if (in3->d.size(1) == 1) {
    i = in6.size(1);
  } else {
    i = in3->d.size(1);
  }
  in1.set_size(1, i);
  stride_0_1 = (in2->a.size(1) != 1);
  stride_1_1 = (in3->a.size(1) != 1);
  stride_2_1 = (in4.size(1) != 1);
  stride_3_1 = (in3->b.size(1) != 1);
  stride_4_1 = (in5->c.size(1) != 1);
  stride_5_1 = (in3->c.size(1) != 1);
  stride_6_1 = (in6.size(1) != 1);
  stride_7_1 = (in3->d.size(1) != 1);
  if (in3->d.size(1) == 1) {
    i = in6.size(1);
  } else {
    i = in3->d.size(1);
  }
  if (i == 1) {
    if (in3->c.size(1) == 1) {
      i = in5->c.size(1);
    } else {
      i = in3->c.size(1);
    }
    if (i == 1) {
      if (in3->b.size(1) == 1) {
        i = in4.size(1);
      } else {
        i = in3->b.size(1);
      }
      if (i == 1) {
        if (in3->a.size(1) == 1) {
          loop_ub = in2->a.size(1);
        } else {
          loop_ub = in3->a.size(1);
        }
      } else if (in3->b.size(1) == 1) {
        loop_ub = in4.size(1);
      } else {
        loop_ub = in3->b.size(1);
      }
    } else if (in3->c.size(1) == 1) {
      loop_ub = in5->c.size(1);
    } else {
      loop_ub = in3->c.size(1);
    }
  } else if (in3->d.size(1) == 1) {
    loop_ub = in6.size(1);
  } else {
    loop_ub = in3->d.size(1);
  }
  for (i = 0; i < loop_ub; i++) {
    in1[i] = ((in2->a[i * stride_0_1] * in3->a[i * stride_1_1] -
               in4[i * stride_2_1] * in3->b[i * stride_3_1]) -
              in5->c[i * stride_4_1] * in3->c[i * stride_5_1]) -
             in6[i * stride_6_1] * in3->d[i * stride_7_1];
  }
}

//
// File trailer for quaternion.cpp
//
// [EOF]
//
