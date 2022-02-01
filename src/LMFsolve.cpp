//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: LMFsolve.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 01-Feb-2022 18:48:34
//

// Include Files
#include "LMFsolve.h"
#include "accumarray.h"
#include "anonymous_function.h"
#include "clothoidG2fitMissingCourse.h"
#include "eigStandard.h"
#include "mldivide.h"
#include "norm.h"
#include "proc_planner_internal_types.h"
#include "proc_planner_rtwutil.h"
#include "rt_nonfinite.h"
#include "schur.h"
#include "coder_array.h"
#include <cmath>
#include <cstring>
#include <string.h>

// Function Declarations
namespace coder {
namespace matlabshared {
namespace tracking {
namespace internal {
namespace scenario {
static void cycsympentdisolve(const ::coder::array<double, 1U> &d,
                              const ::coder::array<double, 1U> &e,
                              const ::coder::array<double, 1U> &f,
                              const ::coder::array<double, 1U> &b,
                              ::coder::array<double, 1U> &x);

static void cyctridisolve(const ::coder::array<double, 1U> &a,
                          ::coder::array<double, 1U> &b,
                          const ::coder::array<double, 1U> &c,
                          const ::coder::array<double, 1U> &d,
                          ::coder::array<double, 1U> &x);

static double leastEigvJtJ(const ::coder::array<double, 2U> &Jtri, double n);

} // namespace scenario
} // namespace internal
} // namespace tracking
} // namespace matlabshared
} // namespace coder

// Function Definitions
//
// Arguments    : const ::coder::array<double, 1U> &d
//                const ::coder::array<double, 1U> &e
//                const ::coder::array<double, 1U> &f
//                const ::coder::array<double, 1U> &b
//                ::coder::array<double, 1U> &x
// Return Type  : void
//
namespace coder {
namespace matlabshared {
namespace tracking {
namespace internal {
namespace scenario {
static void cycsympentdisolve(const ::coder::array<double, 1U> &d,
                              const ::coder::array<double, 1U> &e,
                              const ::coder::array<double, 1U> &f,
                              const ::coder::array<double, 1U> &b,
                              ::coder::array<double, 1U> &x)
{
  array<double, 2U> b_b;
  array<double, 2U> c;
  array<double, 2U> c_b;
  array<double, 2U> u;
  array<double, 2U> v;
  array<double, 2U> z;
  array<double, 2U> zy;
  array<double, 1U> b_gamma;
  array<double, 1U> delta;
  double b_I[16];
  double y[16];
  double X[4];
  double bkj;
  double s;
  int acoef;
  int b_acoef;
  int b_i;
  int b_k;
  int bcoef;
  int i;
  int j;
  int jA;
  int k;
  signed char ipiv[4];
  signed char input_sizes_idx_1;
  signed char sizes_idx_1;
  bool empty_non_axis_sizes;
  u.set_size(b.size(0), 4);
  jA = b.size(0) << 2;
  for (i = 0; i < jA; i++) {
    u[i] = 0.0;
  }
  u[0] = 1.0;
  u[u.size(0) + 1] = 1.0;
  u[(b.size(0) + u.size(0) * 2) - 2] = 1.0;
  u[(b.size(0) + u.size(0) * 3) - 1] = 1.0;
  if (u.size(0) != 0) {
    acoef = u.size(0);
  } else if (b.size(0) != 0) {
    acoef = b.size(0);
  } else {
    acoef = 0;
  }
  empty_non_axis_sizes = (acoef == 0);
  if (empty_non_axis_sizes || (u.size(0) != 0)) {
    input_sizes_idx_1 = 4;
  } else {
    input_sizes_idx_1 = 0;
  }
  if (empty_non_axis_sizes || (b.size(0) != 0)) {
    sizes_idx_1 = 1;
  } else {
    sizes_idx_1 = 0;
  }
  b_b.set_size(acoef, input_sizes_idx_1 + sizes_idx_1);
  jA = input_sizes_idx_1;
  for (i = 0; i < jA; i++) {
    for (b_i = 0; b_i < acoef; b_i++) {
      b_b[b_i + b_b.size(0) * i] = u[b_i + acoef * i];
    }
  }
  jA = sizes_idx_1;
  for (i = 0; i < jA; i++) {
    for (b_i = 0; b_i < acoef; b_i++) {
      b_b[b_i + b_b.size(0) * input_sizes_idx_1] = b[b_i];
    }
  }
  zy.set_size(b_b.size(0), b_b.size(1));
  jA = b_b.size(0) * b_b.size(1);
  for (i = 0; i < jA; i++) {
    zy[i] = 0.0;
  }
  x.set_size(b_b.size(0));
  jA = b_b.size(0);
  for (i = 0; i < jA; i++) {
    x[i] = 0.0;
  }
  b_gamma.set_size(b_b.size(0) - 1);
  jA = b_b.size(0);
  for (i = 0; i <= jA - 2; i++) {
    b_gamma[i] = 0.0;
  }
  delta.set_size(b_b.size(0) - 2);
  jA = b_b.size(0);
  for (i = 0; i <= jA - 3; i++) {
    delta[i] = 0.0;
  }
  x[0] = d[0];
  b_gamma[0] = e[0] / x[0];
  delta[0] = f[0] / x[0];
  x[1] = d[1] - e[0] * b_gamma[0];
  b_gamma[1] = (e[1] - f[0] * b_gamma[0]) / x[1];
  delta[1] = f[1] / x[1];
  i = b_b.size(0);
  for (k = 0; k <= i - 5; k++) {
    bkj = b_gamma[k + 1];
    s = (d[k + 2] - f[k] * delta[k]) - x[k + 1] * (bkj * bkj);
    x[k + 2] = s;
    b_gamma[k + 2] = (e[k + 2] - f[k + 1] * bkj) / s;
    delta[k + 2] = f[k + 2] / s;
  }
  x[b_b.size(0) - 2] =
      (d[b_b.size(0) - 2] - f[b_b.size(0) - 4] * delta[b_b.size(0) - 4]) -
      x[b_b.size(0) - 3] *
          (b_gamma[b_b.size(0) - 3] * b_gamma[b_b.size(0) - 3]);
  b_gamma[b_b.size(0) - 2] =
      (e[b_b.size(0) - 2] - f[b_b.size(0) - 3] * b_gamma[b_b.size(0) - 3]) /
      x[b_b.size(0) - 2];
  x[b_b.size(0) - 1] =
      (d[b_b.size(0) - 1] - f[b_b.size(0) - 3] * delta[b_b.size(0) - 3]) -
      x[b_b.size(0) - 2] *
          (b_gamma[b_b.size(0) - 2] * b_gamma[b_b.size(0) - 2]);
  z.set_size(b_b.size(0), b_b.size(1));
  jA = b_b.size(0) * b_b.size(1);
  for (i = 0; i < jA; i++) {
    z[i] = 0.0;
  }
  jA = b_b.size(1);
  for (i = 0; i < jA; i++) {
    z[z.size(0) * i] = b_b[b_b.size(0) * i];
  }
  jA = b_b.size(1);
  c_b.set_size(1, b_b.size(1));
  for (i = 0; i < jA; i++) {
    c_b[i] = b_b[b_b.size(0) * i + 1] - b_gamma[0] * z[z.size(0) * i];
  }
  jA = c_b.size(1);
  for (i = 0; i < jA; i++) {
    z[z.size(0) * i + 1] = c_b[i];
  }
  i = b_b.size(0);
  for (k = 0; k <= i - 3; k++) {
    jA = b_b.size(1);
    c_b.set_size(1, b_b.size(1));
    for (b_i = 0; b_i < jA; b_i++) {
      c_b[b_i] = (b_b[(k + b_b.size(0) * b_i) + 2] -
                  b_gamma[k + 1] * z[(k + z.size(0) * b_i) + 1]) -
                 delta[k] * z[k + z.size(0) * b_i];
    }
    jA = c_b.size(1);
    for (b_i = 0; b_i < jA; b_i++) {
      z[(k + z.size(0) * b_i) + 2] = c_b[b_i];
    }
  }
  acoef = x.size(0);
  jA = z.size(0);
  if (acoef <= jA) {
    jA = acoef;
  }
  if (x.size(0) == 1) {
    jA = z.size(0);
  } else if (z.size(0) == 1) {
    jA = x.size(0);
  } else if (z.size(0) == x.size(0)) {
    jA = z.size(0);
  }
  c.set_size(jA, z.size(1));
  acoef = x.size(0);
  jA = z.size(0);
  if (acoef <= jA) {
    jA = acoef;
  }
  if (x.size(0) == 1) {
    jA = z.size(0);
  } else if (z.size(0) == 1) {
    jA = x.size(0);
  } else if (z.size(0) == x.size(0)) {
    jA = z.size(0);
  }
  if ((jA != 0) && (z.size(1) != 0)) {
    acoef = (z.size(1) != 1);
    i = z.size(1) - 1;
    for (k = 0; k <= i; k++) {
      jA = acoef * k;
      b_acoef = (z.size(0) != 1);
      bcoef = (x.size(0) != 1);
      b_i = c.size(0) - 1;
      for (b_k = 0; b_k <= b_i; b_k++) {
        c[b_k + c.size(0) * k] =
            z[b_acoef * b_k + z.size(0) * jA] / x[bcoef * b_k];
      }
    }
  }
  jA = c.size(1);
  for (i = 0; i < jA; i++) {
    zy[(b_b.size(0) + zy.size(0) * i) - 1] =
        c[(b_b.size(0) + c.size(0) * i) - 1];
  }
  jA = c.size(1);
  c_b.set_size(1, c.size(1));
  for (i = 0; i < jA; i++) {
    c_b[i] = c[(b_b.size(0) + c.size(0) * i) - 2] -
             b_gamma[b_b.size(0) - 2] * zy[(b_b.size(0) + zy.size(0) * i) - 1];
  }
  jA = c_b.size(1);
  for (i = 0; i < jA; i++) {
    zy[(b_b.size(0) + zy.size(0) * i) - 2] = c_b[i];
  }
  i = b_b.size(0);
  for (k = 0; k <= i - 3; k++) {
    b_k = (b_b.size(0) - k) - 3;
    jA = c.size(1);
    c_b.set_size(1, c.size(1));
    for (b_i = 0; b_i < jA; b_i++) {
      c_b[b_i] = (c[b_k + c.size(0) * b_i] -
                  b_gamma[b_k] * zy[(b_k + zy.size(0) * b_i) + 1]) -
                 delta[b_k] * zy[(b_k + zy.size(0) * b_i) + 2];
    }
    jA = c_b.size(1);
    for (b_i = 0; b_i < jA; b_i++) {
      zy[b_k + zy.size(0) * b_i] = c_b[b_i];
    }
  }
  jA = zy.size(0);
  u.set_size(zy.size(0), 4);
  for (i = 0; i < 4; i++) {
    for (b_i = 0; b_i < jA; b_i++) {
      u[b_i + u.size(0) * i] = zy[b_i + zy.size(0) * i];
    }
  }
  v.set_size(b.size(0), 4);
  jA = b.size(0) << 2;
  for (i = 0; i < jA; i++) {
    v[i] = 0.0;
  }
  v[b.size(0) - 2] = f[b.size(0) - 2];
  v[b.size(0) - 1] = e[b.size(0) - 1];
  v[(b.size(0) + v.size(0)) - 1] = f[b.size(0) - 1];
  v[v.size(0) * 2] = f[b.size(0) - 2];
  v[v.size(0) * 3] = e[b.size(0) - 1];
  v[v.size(0) * 3 + 1] = f[b.size(0) - 1];
  acoef = v.size(0);
  jA = v.size(0);
  for (j = 0; j < 4; j++) {
    b_acoef = j << 2;
    bcoef = j * zy.size(0);
    y[b_acoef] = 0.0;
    y[b_acoef + 1] = 0.0;
    y[b_acoef + 2] = 0.0;
    y[b_acoef + 3] = 0.0;
    for (k = 0; k < acoef; k++) {
      bkj = u[bcoef + k];
      y[b_acoef] += v[k] * bkj;
      y[b_acoef + 1] += v[v.size(0) + k] * bkj;
      y[b_acoef + 2] += v[(v.size(0) << 1) + k] * bkj;
      y[b_acoef + 3] += v[3 * v.size(0) + k] * bkj;
    }
    X[j] = 0.0;
  }
  for (k = 0; k < jA; k++) {
    bkj = zy[k + zy.size(0) * 4];
    X[0] += v[k] * bkj;
    X[1] += v[v.size(0) + k] * bkj;
    X[2] += v[(v.size(0) << 1) + k] * bkj;
    X[3] += v[3 * v.size(0) + k] * bkj;
  }
  std::memset(&b_I[0], 0, 16U * sizeof(double));
  b_I[0] = 1.0;
  b_I[5] = 1.0;
  b_I[10] = 1.0;
  b_I[15] = 1.0;
  for (i = 0; i < 16; i++) {
    b_I[i] += y[i];
  }
  ipiv[0] = 1;
  ipiv[1] = 2;
  ipiv[2] = 3;
  ipiv[3] = 4;
  for (j = 0; j < 3; j++) {
    bcoef = 2 - j;
    b_k = j * 5;
    b_acoef = b_k + 2;
    acoef = 4 - j;
    jA = 0;
    bkj = std::abs(b_I[b_k]);
    for (k = 2; k <= acoef; k++) {
      s = std::abs(b_I[(b_k + k) - 1]);
      if (s > bkj) {
        jA = k - 1;
        bkj = s;
      }
    }
    if (b_I[b_k + jA] != 0.0) {
      if (jA != 0) {
        acoef = j + jA;
        ipiv[j] = static_cast<signed char>(acoef + 1);
        bkj = b_I[j];
        b_I[j] = b_I[acoef];
        b_I[acoef] = bkj;
        bkj = b_I[j + 4];
        b_I[j + 4] = b_I[acoef + 4];
        b_I[acoef + 4] = bkj;
        bkj = b_I[j + 8];
        b_I[j + 8] = b_I[acoef + 8];
        b_I[acoef + 8] = bkj;
        bkj = b_I[j + 12];
        b_I[j + 12] = b_I[acoef + 12];
        b_I[acoef + 12] = bkj;
      }
      i = (b_k - j) + 4;
      for (b_i = b_acoef; b_i <= i; b_i++) {
        b_I[b_i - 1] /= b_I[b_k];
      }
    }
    jA = b_k;
    for (acoef = 0; acoef <= bcoef; acoef++) {
      bkj = b_I[(b_k + (acoef << 2)) + 4];
      if (bkj != 0.0) {
        i = jA + 6;
        b_i = (jA - j) + 8;
        for (b_acoef = i; b_acoef <= b_i; b_acoef++) {
          b_I[b_acoef - 1] += b_I[((b_k + b_acoef) - jA) - 5] * -bkj;
        }
      }
      jA += 4;
    }
    input_sizes_idx_1 = ipiv[j];
    if (input_sizes_idx_1 != j + 1) {
      bkj = X[j];
      X[j] = X[input_sizes_idx_1 - 1];
      X[input_sizes_idx_1 - 1] = bkj;
    }
  }
  for (k = 0; k < 4; k++) {
    jA = k << 2;
    if (X[k] != 0.0) {
      i = k + 2;
      for (b_i = i; b_i < 5; b_i++) {
        X[b_i - 1] -= X[k] * b_I[(b_i + jA) - 1];
      }
    }
  }
  for (k = 3; k >= 0; k--) {
    jA = k << 2;
    bkj = X[k];
    if (bkj != 0.0) {
      bkj /= b_I[k + jA];
      X[k] = bkj;
      for (b_i = 0; b_i < k; b_i++) {
        X[b_i] -= X[k] * b_I[b_i + jA];
      }
    }
  }
  acoef = zy.size(0) - 1;
  x.set_size(zy.size(0));
  for (b_i = 0; b_i <= acoef; b_i++) {
    x[b_i] = ((u[b_i] * X[0] + u[zy.size(0) + b_i] * X[1]) +
              u[(zy.size(0) << 1) + b_i] * X[2]) +
             u[3 * zy.size(0) + b_i] * X[3];
  }
  jA = zy.size(0);
  x.set_size(zy.size(0));
  for (i = 0; i < jA; i++) {
    x[i] = zy[i + zy.size(0) * 4] - x[i];
  }
}

//
// Arguments    : const ::coder::array<double, 1U> &a
//                ::coder::array<double, 1U> &b
//                const ::coder::array<double, 1U> &c
//                const ::coder::array<double, 1U> &d
//                ::coder::array<double, 1U> &x
// Return Type  : void
//
static void cyctridisolve(const ::coder::array<double, 1U> &a,
                          ::coder::array<double, 1U> &b,
                          const ::coder::array<double, 1U> &c,
                          const ::coder::array<double, 1U> &d,
                          ::coder::array<double, 1U> &x)
{
  array<double, 1U> b_b;
  array<double, 1U> u;
  array<double, 1U> z;
  array<int, 2U> r;
  double b_gamma;
  double mu;
  int i;
  int j;
  int loop_ub;
  b_gamma = -b[0];
  b[0] = b[0] - (-b[0]);
  b[d.size(0) - 1] =
      b[d.size(0) - 1] - a[d.size(0) - 1] * c[d.size(0) - 1] / b_gamma;
  b_b.set_size(b.size(0));
  loop_ub = b.size(0);
  for (i = 0; i < loop_ub; i++) {
    b_b[i] = b[i];
  }
  x.set_size(d.size(0));
  loop_ub = d.size(0);
  for (i = 0; i < loop_ub; i++) {
    x[i] = d[i];
  }
  i = d.size(0);
  for (j = 0; j <= i - 2; j++) {
    mu = a[j] / b_b[j];
    b_b[j + 1] = b_b[j + 1] - mu * c[j];
    x[j + 1] = x[j + 1] - mu * x[j];
  }
  x[d.size(0) - 1] = x[d.size(0) - 1] / b_b[d.size(0) - 1];
  i = d.size(0);
  for (j = 0; j <= i - 2; j++) {
    loop_ub = (d.size(0) - j) - 2;
    x[loop_ub] = (x[loop_ub] - c[loop_ub] * x[loop_ub + 1]) / b_b[loop_ub];
  }
  u.set_size(d.size(0));
  loop_ub = d.size(0);
  for (i = 0; i < loop_ub; i++) {
    u[i] = 0.0;
  }
  u[0] = b_gamma;
  u[d.size(0) - 1] = c[d.size(0) - 1];
  if (2 > d.size(0) - 1) {
    i = 0;
    j = 0;
  } else {
    i = 1;
    j = d.size(0) - 1;
  }
  loop_ub = j - i;
  r.set_size(1, loop_ub);
  for (j = 0; j < loop_ub; j++) {
    r[j] = i + j;
  }
  loop_ub = r.size(1);
  for (i = 0; i < loop_ub; i++) {
    u[r[i]] = 0.0;
  }
  b_b.set_size(b.size(0));
  loop_ub = b.size(0);
  for (i = 0; i < loop_ub; i++) {
    b_b[i] = b[i];
  }
  z.set_size(u.size(0));
  loop_ub = u.size(0);
  for (i = 0; i < loop_ub; i++) {
    z[i] = u[i];
  }
  i = u.size(0);
  for (j = 0; j <= i - 2; j++) {
    mu = a[j] / b_b[j];
    b_b[j + 1] = b_b[j + 1] - mu * c[j];
    z[j + 1] = z[j + 1] - mu * z[j];
  }
  z[u.size(0) - 1] = z[u.size(0) - 1] / b_b[u.size(0) - 1];
  i = u.size(0);
  for (j = 0; j <= i - 2; j++) {
    loop_ub = (u.size(0) - j) - 2;
    z[loop_ub] = (z[loop_ub] - c[loop_ub] * z[loop_ub + 1]) / b_b[loop_ub];
  }
  b_gamma = (x[0] + a[d.size(0) - 1] * x[d.size(0) - 1] / b_gamma) /
            ((z[0] + 1.0) + a[d.size(0) - 1] * z[d.size(0) - 1] / b_gamma);
  loop_ub = x.size(0);
  for (i = 0; i < loop_ub; i++) {
    x[i] = x[i] - b_gamma * z[i];
  }
}

//
// Arguments    : const ::coder::array<double, 2U> &Jtri
//                double n
// Return Type  : double
//
static double leastEigvJtJ(const ::coder::array<double, 2U> &Jtri, double n)
{
  array<creal_T, 1U> x;
  array<double, 2U> T;
  array<double, 2U> b_T;
  array<double, 2U> b_y;
  array<double, 2U> c_y;
  array<double, 2U> d_y;
  array<double, 2U> e_y;
  array<double, 2U> f_y;
  array<double, 2U> g_y;
  array<double, 2U> y;
  array<double, 1U> alpha;
  array<double, 1U> b;
  array<double, 1U> beta;
  array<double, 1U> center;
  array<double, 1U> dy;
  array<double, 1U> oldq;
  array<double, 1U> q;
  array<double, 1U> r;
  array<double, 1U> upper;
  array<double, 1U> v;
  double b_n[2];
  double bet;
  double d;
  double mu;
  int b_i;
  int i;
  int last;
  int loop_ub;
  int nx;
  bool exitg2;
  bet = 0.0;
  oldq.set_size(Jtri.size(0));
  loop_ub = Jtri.size(0);
  for (i = 0; i < loop_ub; i++) {
    oldq[i] = 0.0;
  }
  b.set_size(Jtri.size(0));
  loop_ub = Jtri.size(0);
  for (i = 0; i < loop_ub; i++) {
    b[i] = 1.0;
  }
  d = b_norm(b);
  q.set_size(Jtri.size(0));
  loop_ub = Jtri.size(0);
  for (i = 0; i < loop_ub; i++) {
    q[i] = 1.0 / d;
  }
  i = static_cast<int>(n);
  alpha.set_size(i);
  beta.set_size(i);
  for (b_i = 0; b_i < i; b_i++) {
    int i1;
    loop_ub = Jtri.size(0);
    b.set_size(Jtri.size(0));
    center.set_size(Jtri.size(0));
    upper.set_size(Jtri.size(0));
    for (i1 = 0; i1 < loop_ub; i1++) {
      b[i1] = Jtri[i1];
      center[i1] = Jtri[i1 + Jtri.size(0)];
      upper[i1] = Jtri[i1 + Jtri.size(0) * 2];
    }
    if ((Jtri[Jtri.size(0) - 1] == 0.0) &&
        (Jtri[(Jtri.size(0) + Jtri.size(0) * 2) - 1] == 0.0)) {
      b.set_size(center.size(0));
      loop_ub = center.size(0);
      for (i1 = 0; i1 < loop_ub; i1++) {
        b[i1] = center[i1];
      }
      dy.set_size(q.size(0));
      loop_ub = q.size(0);
      for (i1 = 0; i1 < loop_ub; i1++) {
        dy[i1] = q[i1];
      }
      i1 = q.size(0);
      for (last = 0; last <= i1 - 2; last++) {
        mu = Jtri[last + Jtri.size(0) * 2] / b[last];
        b[last + 1] = b[last + 1] - mu * Jtri[last];
        dy[last + 1] = dy[last + 1] - mu * dy[last];
      }
      dy[q.size(0) - 1] = dy[q.size(0) - 1] / b[q.size(0) - 1];
      i1 = q.size(0);
      for (last = 0; last <= i1 - 2; last++) {
        nx = (q.size(0) - last) - 2;
        dy[nx] = (dy[nx] - Jtri[nx] * dy[nx + 1]) / b[nx];
      }
      v.set_size(dy.size(0));
      loop_ub = dy.size(0);
      for (i1 = 0; i1 < loop_ub; i1++) {
        v[i1] = dy[i1];
      }
      i1 = dy.size(0);
      for (last = 0; last <= i1 - 2; last++) {
        mu = Jtri[last] / center[last];
        center[last + 1] =
            center[last + 1] - mu * Jtri[last + Jtri.size(0) * 2];
        v[last + 1] = v[last + 1] - mu * v[last];
      }
      v[dy.size(0) - 1] = v[dy.size(0) - 1] / center[dy.size(0) - 1];
      i1 = dy.size(0);
      for (last = 0; last <= i1 - 2; last++) {
        nx = (dy.size(0) - last) - 2;
        v[nx] = (v[nx] - Jtri[nx + Jtri.size(0) * 2] * v[nx + 1]) / center[nx];
      }
    } else {
      dy.set_size(center.size(0));
      loop_ub = center.size(0) - 1;
      for (i1 = 0; i1 <= loop_ub; i1++) {
        dy[i1] = center[i1];
      }
      cyctridisolve(upper, dy, b, q, r);
      cyctridisolve(b, center, upper, r, v);
    }
    mu = 0.0;
    loop_ub = q.size(0);
    for (i1 = 0; i1 < loop_ub; i1++) {
      mu += q[i1] * v[i1];
    }
    alpha[b_i] = mu;
    loop_ub = v.size(0);
    for (i1 = 0; i1 < loop_ub; i1++) {
      v[i1] = (v[i1] - bet * oldq[i1]) - mu * q[i1];
    }
    bet = b_norm(v);
    oldq.set_size(q.size(0));
    loop_ub = q.size(0);
    for (i1 = 0; i1 < loop_ub; i1++) {
      oldq[i1] = q[i1];
    }
    q.set_size(v.size(0));
    loop_ub = v.size(0);
    for (i1 = 0; i1 < loop_ub; i1++) {
      q[i1] = v[i1] / bet;
    }
    beta[b_i] = bet;
  }
  if (1.0 > n - 1.0) {
    loop_ub = 0;
    nx = 0;
  } else {
    loop_ub = static_cast<int>(n - 1.0);
    nx = static_cast<int>(n - 1.0);
  }
  if (n - 1.0 < 1.0) {
    y.set_size(1, 0);
  } else if (std::isinf(n - 1.0) && (1.0 == n - 1.0)) {
    y.set_size(1, 1);
    y[0] = rtNaN;
  } else {
    last = static_cast<int>(std::floor((n - 1.0) - 1.0));
    y.set_size(1, last + 1);
    for (i = 0; i <= last; i++) {
      y[i] = static_cast<double>(i) + 1.0;
    }
  }
  if (n < 1.0) {
    b_y.set_size(1, 0);
  } else if (std::isinf(n) && (1.0 == n)) {
    b_y.set_size(1, 1);
    b_y[0] = rtNaN;
  } else {
    last = static_cast<int>(std::floor(n - 1.0));
    b_y.set_size(1, last + 1);
    for (i = 0; i <= last; i++) {
      b_y[i] = static_cast<double>(i) + 1.0;
    }
  }
  if (n < 2.0) {
    c_y.set_size(1, 0);
    d_y.set_size(1, 0);
  } else {
    if (std::isinf(n) && (2.0 == n)) {
      c_y.set_size(1, 1);
      c_y[0] = rtNaN;
    } else {
      last = static_cast<int>(std::floor(n - 2.0));
      c_y.set_size(1, last + 1);
      for (i = 0; i <= last; i++) {
        c_y[i] = static_cast<double>(i) + 2.0;
      }
    }
    if (std::isinf(n) && (2.0 == n)) {
      d_y.set_size(1, 1);
      d_y[0] = rtNaN;
    } else {
      d_y.set_size(1, static_cast<int>(std::floor(n - 2.0)) + 1);
      last = static_cast<int>(std::floor(n - 2.0));
      for (i = 0; i <= last; i++) {
        d_y[i] = static_cast<double>(i) + 2.0;
      }
    }
  }
  if (n < 1.0) {
    e_y.set_size(1, 0);
  } else if (std::isinf(n) && (1.0 == n)) {
    e_y.set_size(1, 1);
    e_y[0] = rtNaN;
  } else {
    e_y.set_size(1, static_cast<int>(std::floor(n - 1.0)) + 1);
    last = static_cast<int>(std::floor(n - 1.0));
    for (i = 0; i <= last; i++) {
      e_y[i] = static_cast<double>(i) + 1.0;
    }
  }
  if (n - 1.0 < 1.0) {
    f_y.set_size(1, 0);
  } else if (std::isinf(n - 1.0) && (1.0 == n - 1.0)) {
    f_y.set_size(1, 1);
    f_y[0] = rtNaN;
  } else {
    f_y.set_size(1, static_cast<int>(std::floor((n - 1.0) - 1.0)) + 1);
    last = static_cast<int>(std::floor((n - 1.0) - 1.0));
    for (i = 0; i <= last; i++) {
      f_y[i] = static_cast<double>(i) + 1.0;
    }
  }
  g_y.set_size((y.size(1) + b_y.size(1)) + c_y.size(1), 2);
  last = y.size(1);
  for (i = 0; i < last; i++) {
    g_y[i] = y[i];
  }
  last = b_y.size(1);
  for (i = 0; i < last; i++) {
    g_y[i + y.size(1)] = b_y[i];
  }
  last = c_y.size(1);
  for (i = 0; i < last; i++) {
    g_y[(i + y.size(1)) + b_y.size(1)] = c_y[i];
  }
  last = d_y.size(1);
  for (i = 0; i < last; i++) {
    g_y[i + g_y.size(0)] = d_y[i];
  }
  last = e_y.size(1);
  for (i = 0; i < last; i++) {
    g_y[(i + d_y.size(1)) + g_y.size(0)] = e_y[i];
  }
  last = f_y.size(1);
  for (i = 0; i < last; i++) {
    g_y[((i + d_y.size(1)) + e_y.size(1)) + g_y.size(0)] = f_y[i];
  }
  oldq.set_size((loop_ub + alpha.size(0)) + nx);
  for (i = 0; i < loop_ub; i++) {
    oldq[i] = beta[i];
  }
  last = alpha.size(0);
  for (i = 0; i < last; i++) {
    oldq[i + loop_ub] = alpha[i];
  }
  for (i = 0; i < nx; i++) {
    oldq[(i + loop_ub) + alpha.size(0)] = beta[i];
  }
  b_n[0] = n;
  b_n[1] = n;
  accumarray(g_y, oldq, b_n, T);
  x.set_size(T.size(0));
  if ((T.size(0) != 0) && (T.size(1) != 0)) {
    bool p;
    nx = T.size(0) * T.size(1);
    p = true;
    for (loop_ub = 0; loop_ub < nx; loop_ub++) {
      if ((!p) || (std::isinf(T[loop_ub]) || std::isnan(T[loop_ub]))) {
        p = false;
      }
    }
    if (!p) {
      x.set_size(T.size(0));
      loop_ub = T.size(0);
      for (i = 0; i < loop_ub; i++) {
        x[i].re = rtNaN;
        x[i].im = 0.0;
      }
    } else {
      int exitg1;
      p = (T.size(0) == T.size(1));
      if (p) {
        last = 0;
        exitg2 = false;
        while ((!exitg2) && (last <= T.size(1) - 1)) {
          b_i = 0;
          do {
            exitg1 = 0;
            if (b_i <= last) {
              if (!(T[b_i + T.size(0) * last] == T[last + T.size(0) * b_i])) {
                p = false;
                exitg1 = 1;
              } else {
                b_i++;
              }
            } else {
              last++;
              exitg1 = 2;
            }
          } while (exitg1 == 0);
          if (exitg1 == 1) {
            exitg2 = true;
          }
        }
      }
      if (p) {
        schur(T, b_T);
        nx = b_T.size(0);
        b.set_size(b_T.size(0));
        for (loop_ub = 0; loop_ub < nx; loop_ub++) {
          b[loop_ub] = b_T[loop_ub + b_T.size(0) * loop_ub];
        }
        x.set_size(b.size(0));
        loop_ub = b.size(0);
        for (i = 0; i < loop_ub; i++) {
          x[i].re = b[i];
          x[i].im = 0.0;
        }
      } else {
        p = (T.size(0) == T.size(1));
        if (p) {
          last = 0;
          exitg2 = false;
          while ((!exitg2) && (last <= T.size(1) - 1)) {
            b_i = 0;
            do {
              exitg1 = 0;
              if (b_i <= last) {
                if (!(T[b_i + T.size(0) * last] ==
                      -T[last + T.size(0) * b_i])) {
                  p = false;
                  exitg1 = 1;
                } else {
                  b_i++;
                }
              } else {
                last++;
                exitg1 = 2;
              }
            } while (exitg1 == 0);
            if (exitg1 == 1) {
              exitg2 = true;
            }
          }
        }
        if (p) {
          schur(T, b_T);
          nx = b_T.size(0);
          x.set_size(b_T.size(0));
          b_i = 1;
          do {
            exitg1 = 0;
            if (b_i <= nx) {
              bool guard1{false};
              guard1 = false;
              if (b_i != nx) {
                d = b_T[b_i + b_T.size(0) * (b_i - 1)];
                if (d != 0.0) {
                  mu = std::abs(d);
                  x[b_i - 1].re = 0.0;
                  x[b_i - 1].im = mu;
                  x[b_i].re = 0.0;
                  x[b_i].im = -mu;
                  b_i += 2;
                } else {
                  guard1 = true;
                }
              } else {
                guard1 = true;
              }
              if (guard1) {
                x[b_i - 1].re = 0.0;
                x[b_i - 1].im = 0.0;
                b_i++;
              }
            } else {
              exitg1 = 1;
            }
          } while (exitg1 == 0);
        } else {
          eigStandard(T, x);
        }
      }
    }
  }
  nx = x.size(0);
  b.set_size(x.size(0));
  for (loop_ub = 0; loop_ub < nx; loop_ub++) {
    b[loop_ub] = rt_hypotd_snf(x[loop_ub].re, x[loop_ub].im);
  }
  last = b.size(0);
  if (b.size(0) <= 2) {
    if (b.size(0) == 0) {
      mu = rtNaN;
    } else if (b.size(0) == 1) {
      mu = b[0];
    } else if ((b[0] > b[1]) || (std::isnan(b[0]) && (!std::isnan(b[1])))) {
      mu = b[1];
    } else {
      mu = b[0];
    }
  } else {
    if (!std::isnan(b[0])) {
      nx = 1;
    } else {
      nx = 0;
      loop_ub = 2;
      exitg2 = false;
      while ((!exitg2) && (loop_ub <= last)) {
        if (!std::isnan(b[loop_ub - 1])) {
          nx = loop_ub;
          exitg2 = true;
        } else {
          loop_ub++;
        }
      }
    }
    if (nx == 0) {
      mu = b[0];
    } else {
      mu = b[nx - 1];
      i = nx + 1;
      for (loop_ub = i; loop_ub <= last; loop_ub++) {
        d = b[loop_ub - 1];
        if (mu > d) {
          mu = d;
        }
      }
    }
  }
  return 1.0 / mu;
}

//
// Arguments    : const anonymous_function *FUN
//                ::coder::array<double, 1U> &x
// Return Type  : void
//
void LMFsolve(const anonymous_function *FUN, ::coder::array<double, 1U> &x)
{
  array<double, 2U> Jtri;
  array<double, 2U> varargout_2;
  array<double, 1U> dx;
  array<double, 1U> r;
  array<double, 1U> v;
  array<double, 1U> varargout_1;
  array<double, 1U> xnew;
  array<bool, 1U> b_x;
  double S;
  double iter;
  double lambda;
  double lambdac;
  double maxiter;
  int k;
  int outsize_idx_0;
  bool exitg1;
  maxiter = 100.0 * static_cast<double>(x.size(0));
  fitCourse_anonFcn3(FUN->workspace.waypoints, FUN->workspace.course, x, r,
                     Jtri);
  mulJt(Jtri, r, v);
  S = 0.0;
  outsize_idx_0 = r.size(0);
  for (k = 0; k < outsize_idx_0; k++) {
    S += r[k] * r[k];
  }
  lambda = 0.0;
  lambdac = 0.75;
  iter = 0.0;
  outsize_idx_0 = x.size(0);
  dx.set_size(outsize_idx_0);
  for (k = 0; k < outsize_idx_0; k++) {
    dx[k] = 1.0E-7;
  }
  exitg1 = false;
  while ((!exitg1) && (iter < maxiter)) {
    bool exitg2;
    bool y;
    outsize_idx_0 = dx.size(0);
    xnew.set_size(dx.size(0));
    for (k = 0; k < outsize_idx_0; k++) {
      xnew[k] = std::abs(dx[k]);
    }
    b_x.set_size(xnew.size(0));
    outsize_idx_0 = xnew.size(0);
    for (k = 0; k < outsize_idx_0; k++) {
      b_x[k] = (xnew[k] >= 1.0E-7);
    }
    y = false;
    outsize_idx_0 = 1;
    exitg2 = false;
    while ((!exitg2) && (outsize_idx_0 <= b_x.size(0))) {
      if (b_x[outsize_idx_0 - 1]) {
        y = true;
        exitg2 = true;
      } else {
        outsize_idx_0++;
      }
    }
    if (y) {
      outsize_idx_0 = r.size(0);
      xnew.set_size(r.size(0));
      for (k = 0; k < outsize_idx_0; k++) {
        xnew[k] = std::abs(r[k]);
      }
      b_x.set_size(xnew.size(0));
      outsize_idx_0 = xnew.size(0);
      for (k = 0; k < outsize_idx_0; k++) {
        b_x[k] = (xnew[k] >= 1.0E-7);
      }
      y = false;
      outsize_idx_0 = 1;
      exitg2 = false;
      while ((!exitg2) && (outsize_idx_0 <= b_x.size(0))) {
        if (b_x[outsize_idx_0 - 1]) {
          y = true;
          exitg2 = true;
        } else {
          outsize_idx_0++;
        }
      }
      if (y) {
        double b_varargout_1;
        iter++;
        solveDampenedHessian(Jtri, lambda, v, dx);
        xnew.set_size(x.size(0));
        outsize_idx_0 = x.size(0);
        for (k = 0; k < outsize_idx_0; k++) {
          xnew[k] = x[k] - dx[k];
        }
        fitCourse_anonFcn3(FUN->workspace.waypoints, FUN->workspace.course,
                           xnew, varargout_1, varargout_2);
        b_varargout_1 = 0.0;
        outsize_idx_0 = varargout_1.size(0);
        for (k = 0; k < outsize_idx_0; k++) {
          b_varargout_1 += varargout_1[k] * varargout_1[k];
        }
        fletcher(S, b_varargout_1, dx, v, Jtri, &lambda, &lambdac);
        if (b_varargout_1 < S) {
          S = b_varargout_1;
          x.set_size(xnew.size(0));
          outsize_idx_0 = xnew.size(0);
          for (k = 0; k < outsize_idx_0; k++) {
            x[k] = xnew[k];
          }
          r.set_size(varargout_1.size(0));
          outsize_idx_0 = varargout_1.size(0);
          for (k = 0; k < outsize_idx_0; k++) {
            r[k] = varargout_1[k];
          }
          Jtri.set_size(varargout_2.size(0), 3);
          outsize_idx_0 = varargout_2.size(0) * 3;
          for (k = 0; k < outsize_idx_0; k++) {
            Jtri[k] = varargout_2[k];
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
}

//
// Arguments    : const anonymous_function *FUN
//                ::coder::array<double, 1U> &x
// Return Type  : void
//
void b_LMFsolve(const anonymous_function *FUN, ::coder::array<double, 1U> &x)
{
  array<double, 2U> Jtri;
  array<double, 2U> varargout_2;
  array<double, 1U> dx;
  array<double, 1U> r;
  array<double, 1U> v;
  array<double, 1U> varargout_1;
  array<double, 1U> xnew;
  array<bool, 1U> b_x;
  double S;
  double iter;
  double lambda;
  double lambdac;
  double maxiter;
  int k;
  int outsize_idx_0;
  bool exitg1;
  maxiter = 100.0 * static_cast<double>(x.size(0));
  fitCourse_anonFcn4(FUN->workspace.waypoints, FUN->workspace.course, x, r,
                     Jtri);
  mulJt(Jtri, r, v);
  S = 0.0;
  outsize_idx_0 = r.size(0);
  for (k = 0; k < outsize_idx_0; k++) {
    S += r[k] * r[k];
  }
  lambda = 0.0;
  lambdac = 0.75;
  iter = 0.0;
  outsize_idx_0 = x.size(0);
  dx.set_size(outsize_idx_0);
  for (k = 0; k < outsize_idx_0; k++) {
    dx[k] = 1.0E-7;
  }
  exitg1 = false;
  while ((!exitg1) && (iter < maxiter)) {
    bool exitg2;
    bool y;
    outsize_idx_0 = dx.size(0);
    xnew.set_size(dx.size(0));
    for (k = 0; k < outsize_idx_0; k++) {
      xnew[k] = std::abs(dx[k]);
    }
    b_x.set_size(xnew.size(0));
    outsize_idx_0 = xnew.size(0);
    for (k = 0; k < outsize_idx_0; k++) {
      b_x[k] = (xnew[k] >= 1.0E-7);
    }
    y = false;
    outsize_idx_0 = 1;
    exitg2 = false;
    while ((!exitg2) && (outsize_idx_0 <= b_x.size(0))) {
      if (b_x[outsize_idx_0 - 1]) {
        y = true;
        exitg2 = true;
      } else {
        outsize_idx_0++;
      }
    }
    if (y) {
      outsize_idx_0 = r.size(0);
      xnew.set_size(r.size(0));
      for (k = 0; k < outsize_idx_0; k++) {
        xnew[k] = std::abs(r[k]);
      }
      b_x.set_size(xnew.size(0));
      outsize_idx_0 = xnew.size(0);
      for (k = 0; k < outsize_idx_0; k++) {
        b_x[k] = (xnew[k] >= 1.0E-7);
      }
      y = false;
      outsize_idx_0 = 1;
      exitg2 = false;
      while ((!exitg2) && (outsize_idx_0 <= b_x.size(0))) {
        if (b_x[outsize_idx_0 - 1]) {
          y = true;
          exitg2 = true;
        } else {
          outsize_idx_0++;
        }
      }
      if (y) {
        double b_varargout_1;
        iter++;
        solveDampenedHessian(Jtri, lambda, v, dx);
        xnew.set_size(x.size(0));
        outsize_idx_0 = x.size(0);
        for (k = 0; k < outsize_idx_0; k++) {
          xnew[k] = x[k] - dx[k];
        }
        fitCourse_anonFcn4(FUN->workspace.waypoints, FUN->workspace.course,
                           xnew, varargout_1, varargout_2);
        b_varargout_1 = 0.0;
        outsize_idx_0 = varargout_1.size(0);
        for (k = 0; k < outsize_idx_0; k++) {
          b_varargout_1 += varargout_1[k] * varargout_1[k];
        }
        fletcher(S, b_varargout_1, dx, v, Jtri, &lambda, &lambdac);
        if (b_varargout_1 < S) {
          S = b_varargout_1;
          x.set_size(xnew.size(0));
          outsize_idx_0 = xnew.size(0);
          for (k = 0; k < outsize_idx_0; k++) {
            x[k] = xnew[k];
          }
          r.set_size(varargout_1.size(0));
          outsize_idx_0 = varargout_1.size(0);
          for (k = 0; k < outsize_idx_0; k++) {
            r[k] = varargout_1[k];
          }
          Jtri.set_size(varargout_2.size(0), 3);
          outsize_idx_0 = varargout_2.size(0) * 3;
          for (k = 0; k < outsize_idx_0; k++) {
            Jtri[k] = varargout_2[k];
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
}

//
// Arguments    : double S
//                double Snew
//                const ::coder::array<double, 1U> &dx
//                const ::coder::array<double, 1U> &v
//                const ::coder::array<double, 2U> &Jtri
//                double *lambda
//                double *lambdac
// Return Type  : void
//
void fletcher(double S, double Snew, const ::coder::array<double, 1U> &dx,
              const ::coder::array<double, 1U> &v,
              const ::coder::array<double, 2U> &Jtri, double *lambda,
              double *lambdac)
{
  array<double, 2U> b_y;
  array<double, 2U> c_y;
  array<double, 2U> r;
  array<double, 2U> y;
  array<double, 1U> center;
  array<double, 1U> lower;
  array<double, 1U> upper;
  array<double, 1U> z;
  array<int, 1U> b_dx;
  array<int, 1U> c_dx;
  array<int, 1U> d_y;
  double R;
  int i;
  int loop_ub;
  loop_ub = Jtri.size(0);
  lower.set_size(Jtri.size(0));
  for (i = 0; i < loop_ub; i++) {
    lower[i] = Jtri[i];
  }
  loop_ub = Jtri.size(0);
  center.set_size(Jtri.size(0));
  for (i = 0; i < loop_ub; i++) {
    center[i] = Jtri[i + Jtri.size(0)];
  }
  loop_ub = Jtri.size(0);
  upper.set_size(Jtri.size(0));
  for (i = 0; i < loop_ub; i++) {
    upper[i] = Jtri[i + Jtri.size(0) * 2];
  }
  if (dx.size(0) < 2) {
    y.set_size(1, 0);
  } else {
    y.set_size(1, dx.size(0) - 1);
    loop_ub = dx.size(0) - 2;
    for (i = 0; i <= loop_ub; i++) {
      y[i] = static_cast<double>(i) + 2.0;
    }
  }
  if (dx.size(0) - 1 < 1) {
    b_y.set_size(1, 0);
    c_y.set_size(1, 0);
  } else {
    b_y.set_size(
        1, static_cast<int>((static_cast<double>(dx.size(0)) - 1.0) - 1.0) + 1);
    loop_ub = static_cast<int>((static_cast<double>(dx.size(0)) - 1.0) - 1.0);
    for (i = 0; i <= loop_ub; i++) {
      b_y[i] = static_cast<double>(i) + 1.0;
    }
    c_y.set_size(
        1, static_cast<int>((static_cast<double>(dx.size(0)) - 1.0) - 1.0) + 1);
    loop_ub = static_cast<int>((static_cast<double>(dx.size(0)) - 1.0) - 1.0);
    for (i = 0; i <= loop_ub; i++) {
      c_y[i] = static_cast<double>(i) + 1.0;
    }
  }
  d_y.set_size(y.size(1) + 1);
  loop_ub = y.size(1);
  for (i = 0; i < loop_ub; i++) {
    d_y[i] = static_cast<int>(y[i]) - 1;
  }
  d_y[y.size(1)] = 0;
  b_dx.set_size(b_y.size(1) + 1);
  b_dx[0] = dx.size(0) - 1;
  loop_ub = b_y.size(1);
  for (i = 0; i < loop_ub; i++) {
    b_dx[i + 1] = static_cast<int>(b_y[i]) - 1;
  }
  c_dx.set_size(c_y.size(1) + 1);
  c_dx[0] = dx.size(0) - 1;
  loop_ub = c_y.size(1);
  for (i = 0; i < loop_ub; i++) {
    c_dx[i + 1] = static_cast<int>(c_y[i]) - 1;
  }
  z.set_size(center.size(0));
  loop_ub = center.size(0);
  for (i = 0; i < loop_ub; i++) {
    z[i] = (center[i] * dx[i] + upper[i] * dx[d_y[i]]) +
           lower[b_dx[i]] * dx[c_dx[i]];
  }
  if (dx.size(0) < 2) {
    y.set_size(1, 0);
  } else {
    y.set_size(1, dx.size(0) - 1);
    loop_ub = dx.size(0) - 2;
    for (i = 0; i <= loop_ub; i++) {
      y[i] = static_cast<double>(i) + 2.0;
    }
  }
  b_y.set_size(1, y.size(1) + 1);
  loop_ub = y.size(1);
  for (i = 0; i < loop_ub; i++) {
    b_y[i] = y[i];
  }
  b_y[y.size(1)] = 1.0;
  if (dx.size(0) - 1 < 1) {
    y.set_size(1, 0);
  } else {
    y.set_size(
        1, static_cast<int>((static_cast<double>(dx.size(0)) - 1.0) - 1.0) + 1);
    loop_ub = static_cast<int>((static_cast<double>(dx.size(0)) - 1.0) - 1.0);
    for (i = 0; i <= loop_ub; i++) {
      y[i] = static_cast<double>(i) + 1.0;
    }
  }
  c_y.set_size(1, y.size(1) + 1);
  c_y[0] = dx.size(0);
  loop_ub = y.size(1);
  for (i = 0; i < loop_ub; i++) {
    c_y[i + 1] = y[i];
  }
  if (dx.size(0) - 1 < 1) {
    y.set_size(1, 0);
  } else {
    y.set_size(
        1, static_cast<int>((static_cast<double>(dx.size(0)) - 1.0) - 1.0) + 1);
    loop_ub = static_cast<int>((static_cast<double>(dx.size(0)) - 1.0) - 1.0);
    for (i = 0; i <= loop_ub; i++) {
      y[i] = static_cast<double>(i) + 1.0;
    }
  }
  r.set_size(1, y.size(1) + 1);
  r[0] = dx.size(0);
  loop_ub = y.size(1);
  for (i = 0; i < loop_ub; i++) {
    r[i + 1] = y[i];
  }
  R = 0.0;
  loop_ub = dx.size(0);
  for (i = 0; i < loop_ub; i++) {
    R +=
        dx[i] *
        (2.0 * v[i] -
         ((center[i] * z[i] + lower[i] * z[static_cast<int>(b_y[i]) - 1]) +
          upper[static_cast<int>(c_y[i]) - 1] * z[static_cast<int>(r[i]) - 1]));
  }
  R = (S - Snew) / R;
  if (R > 0.75) {
    *lambda /= 2.0;
    if (*lambda < *lambdac) {
      *lambda = 0.0;
    }
  } else if (R < 0.25) {
    R = 0.0;
    loop_ub = dx.size(0);
    for (i = 0; i < loop_ub; i++) {
      R += dx[i] * v[i];
    }
    R = std::fmin(std::fmax(2.0, (Snew - S) / R + 2.0), 10.0);
    if (*lambda == 0.0) {
      *lambdac = leastEigvJtJ(
          Jtri, std::fmin(40.0, static_cast<double>(Jtri.size(0))));
      *lambda = *lambdac;
      R /= 2.0;
    }
    *lambda *= R;
  }
}

//
// Arguments    : const ::coder::array<double, 2U> &Jtri
//                const ::coder::array<double, 1U> &x
//                ::coder::array<double, 1U> &y
// Return Type  : void
//
void mulJt(const ::coder::array<double, 2U> &Jtri,
           const ::coder::array<double, 1U> &x, ::coder::array<double, 1U> &y)
{
  array<double, 2U> b_y;
  array<double, 2U> c_y;
  array<double, 2U> d_y;
  array<int, 1U> b_x;
  array<int, 1U> c_x;
  array<int, 1U> e_y;
  int i;
  int loop_ub;
  if (x.size(0) < 2) {
    b_y.set_size(1, 0);
  } else {
    b_y.set_size(1, x.size(0) - 1);
    loop_ub = x.size(0) - 2;
    for (i = 0; i <= loop_ub; i++) {
      b_y[i] = static_cast<double>(i) + 2.0;
    }
  }
  if (x.size(0) - 1 < 1) {
    c_y.set_size(1, 0);
    d_y.set_size(1, 0);
  } else {
    c_y.set_size(
        1, static_cast<int>((static_cast<double>(x.size(0)) - 1.0) - 1.0) + 1);
    loop_ub = static_cast<int>((static_cast<double>(x.size(0)) - 1.0) - 1.0);
    for (i = 0; i <= loop_ub; i++) {
      c_y[i] = static_cast<double>(i) + 1.0;
    }
    d_y.set_size(
        1, static_cast<int>((static_cast<double>(x.size(0)) - 1.0) - 1.0) + 1);
    loop_ub = static_cast<int>((static_cast<double>(x.size(0)) - 1.0) - 1.0);
    for (i = 0; i <= loop_ub; i++) {
      d_y[i] = static_cast<double>(i) + 1.0;
    }
  }
  e_y.set_size(b_y.size(1) + 1);
  loop_ub = b_y.size(1);
  for (i = 0; i < loop_ub; i++) {
    e_y[i] = static_cast<int>(b_y[i]) - 1;
  }
  e_y[b_y.size(1)] = 0;
  b_x.set_size(c_y.size(1) + 1);
  b_x[0] = x.size(0) - 1;
  loop_ub = c_y.size(1);
  for (i = 0; i < loop_ub; i++) {
    b_x[i + 1] = static_cast<int>(c_y[i]) - 1;
  }
  c_x.set_size(d_y.size(1) + 1);
  c_x[0] = x.size(0) - 1;
  loop_ub = d_y.size(1);
  for (i = 0; i < loop_ub; i++) {
    c_x[i + 1] = static_cast<int>(d_y[i]) - 1;
  }
  loop_ub = Jtri.size(0);
  y.set_size(Jtri.size(0));
  for (i = 0; i < loop_ub; i++) {
    y[i] = (Jtri[i + Jtri.size(0)] * x[i] + Jtri[i] * x[e_y[i]]) +
           Jtri[b_x[i] + Jtri.size(0) * 2] * x[c_x[i]];
  }
}

//
// Arguments    : const ::coder::array<double, 2U> &Jtri
//                double lambda
//                const ::coder::array<double, 1U> &v
//                ::coder::array<double, 1U> &dx
// Return Type  : void
//
void solveDampenedHessian(const ::coder::array<double, 2U> &Jtri, double lambda,
                          const ::coder::array<double, 1U> &v,
                          ::coder::array<double, 1U> &dx)
{
  array<double, 2U> A;
  array<double, 2U> J;
  array<double, 2U> b_A;
  array<double, 2U> c_y;
  array<double, 2U> d_y;
  array<double, 2U> e_y;
  array<double, 2U> f_y;
  array<double, 2U> g_y;
  array<double, 2U> h_y;
  array<double, 2U> y;
  array<double, 1U> a;
  array<double, 1U> alpha;
  array<double, 1U> b;
  array<double, 1U> c;
  array<double, 1U> d;
  array<double, 1U> e;
  array<double, 1U> f;
  array<int, 2U> b_v;
  array<int, 2U> c_v;
  array<int, 1U> b_y;
  double d_v[2];
  double bkj;
  int i;
  int k;
  int loop_ub;
  int nx;
  loop_ub = Jtri.size(0);
  a.set_size(Jtri.size(0));
  for (i = 0; i < loop_ub; i++) {
    a[i] = Jtri[i];
  }
  loop_ub = Jtri.size(0);
  b.set_size(Jtri.size(0));
  for (i = 0; i < loop_ub; i++) {
    b[i] = Jtri[i + Jtri.size(0)];
  }
  loop_ub = Jtri.size(0);
  c.set_size(Jtri.size(0));
  for (i = 0; i < loop_ub; i++) {
    c[i] = Jtri[i + Jtri.size(0) * 2];
  }
  d.set_size(Jtri.size(0));
  nx = Jtri.size(0);
  for (k = 0; k < nx; k++) {
    bkj = Jtri[k];
    d[k] = bkj * bkj;
  }
  e.set_size(Jtri.size(0));
  nx = Jtri.size(0);
  for (k = 0; k < nx; k++) {
    bkj = Jtri[k + Jtri.size(0)];
    e[k] = bkj * bkj;
  }
  if (v.size(0) - 1 < 1) {
    y.set_size(1, 0);
  } else {
    y.set_size(
        1, static_cast<int>((static_cast<double>(v.size(0)) - 1.0) - 1.0) + 1);
    loop_ub = static_cast<int>((static_cast<double>(v.size(0)) - 1.0) - 1.0);
    for (i = 0; i <= loop_ub; i++) {
      y[i] = static_cast<double>(i) + 1.0;
    }
  }
  alpha.set_size(y.size(1) + 1);
  nx = y.size(1) + 1;
  for (k = 0; k < nx; k++) {
    loop_ub = y.size(1);
    b_v.set_size(1, y.size(1) + 1);
    b_v[0] = v.size(0);
    c_v.set_size(1, y.size(1) + 1);
    c_v[0] = v.size(0);
    for (i = 0; i < loop_ub; i++) {
      bkj = y[i];
      b_v[i + 1] = static_cast<int>(bkj);
      c_v[i + 1] = static_cast<int>(bkj);
    }
    alpha[k] = c[b_v[k] - 1] * c[c_v[k] - 1];
  }
  loop_ub = d.size(0);
  for (i = 0; i < loop_ub; i++) {
    d[i] = ((d[i] + e[i]) + alpha[i]) * (lambda + 1.0);
  }
  if (v.size(0) < 2) {
    y.set_size(1, 0);
  } else {
    y.set_size(1, v.size(0) - 1);
    loop_ub = v.size(0) - 2;
    for (i = 0; i <= loop_ub; i++) {
      y[i] = static_cast<double>(i) + 2.0;
    }
  }
  b_y.set_size(y.size(1) + 1);
  loop_ub = y.size(1);
  for (i = 0; i < loop_ub; i++) {
    b_y[i] = static_cast<int>(y[i]) - 1;
  }
  b_y[y.size(1)] = 0;
  e.set_size(a.size(0));
  loop_ub = a.size(0);
  for (i = 0; i < loop_ub; i++) {
    e[i] = a[i] * b[b_y[i]] + b[i] * c[i];
  }
  if (v.size(0) < 2) {
    y.set_size(1, 0);
  } else {
    y.set_size(1, v.size(0) - 1);
    loop_ub = v.size(0) - 2;
    for (i = 0; i <= loop_ub; i++) {
      y[i] = static_cast<double>(i) + 2.0;
    }
  }
  c_y.set_size(1, y.size(1) + 1);
  loop_ub = y.size(1);
  for (i = 0; i < loop_ub; i++) {
    c_y[i] = y[i];
  }
  c_y[y.size(1)] = 1.0;
  f.set_size(a.size(0));
  loop_ub = a.size(0);
  for (i = 0; i < loop_ub; i++) {
    f[i] = a[i] * c[static_cast<int>(c_y[i]) - 1];
  }
  if (v.size(0) < 5) {
    int j;
    int nv;
    if (v.size(0) < 1) {
      y.set_size(1, 0);
      c_y.set_size(1, 0);
    } else {
      y.set_size(1, v.size(0));
      loop_ub = v.size(0) - 1;
      for (i = 0; i <= loop_ub; i++) {
        y[i] = static_cast<double>(i) + 1.0;
      }
      c_y.set_size(1, v.size(0));
      loop_ub = v.size(0) - 1;
      for (i = 0; i <= loop_ub; i++) {
        c_y[i] = static_cast<double>(i) + 1.0;
      }
    }
    if (v.size(0) < 2) {
      d_y.set_size(1, 0);
      e_y.set_size(1, 0);
    } else {
      d_y.set_size(1, v.size(0) - 1);
      loop_ub = v.size(0) - 2;
      for (i = 0; i <= loop_ub; i++) {
        d_y[i] = static_cast<double>(i) + 2.0;
      }
      e_y.set_size(1, v.size(0) - 1);
      loop_ub = v.size(0) - 2;
      for (i = 0; i <= loop_ub; i++) {
        e_y[i] = static_cast<double>(i) + 2.0;
      }
    }
    if (v.size(0) < 1) {
      f_y.set_size(1, 0);
      g_y.set_size(1, 0);
    } else {
      f_y.set_size(1, v.size(0));
      loop_ub = v.size(0) - 1;
      for (i = 0; i <= loop_ub; i++) {
        f_y[i] = static_cast<double>(i) + 1.0;
      }
      g_y.set_size(1, v.size(0));
      loop_ub = v.size(0) - 1;
      for (i = 0; i <= loop_ub; i++) {
        g_y[i] = static_cast<double>(i) + 1.0;
      }
    }
    h_y.set_size(((y.size(1) + c_y.size(1)) + d_y.size(1)) + 1, 2);
    loop_ub = y.size(1);
    for (i = 0; i < loop_ub; i++) {
      h_y[i] = y[i];
    }
    loop_ub = c_y.size(1);
    for (i = 0; i < loop_ub; i++) {
      h_y[i + y.size(1)] = c_y[i];
    }
    loop_ub = d_y.size(1);
    for (i = 0; i < loop_ub; i++) {
      h_y[(i + y.size(1)) + c_y.size(1)] = d_y[i];
    }
    h_y[(y.size(1) + c_y.size(1)) + d_y.size(1)] = 1.0;
    loop_ub = e_y.size(1);
    for (i = 0; i < loop_ub; i++) {
      h_y[i + h_y.size(0)] = e_y[i];
    }
    h_y[e_y.size(1) + h_y.size(0)] = 1.0;
    loop_ub = f_y.size(1);
    for (i = 0; i < loop_ub; i++) {
      h_y[((i + e_y.size(1)) + h_y.size(0)) + 1] = f_y[i];
    }
    loop_ub = g_y.size(1);
    for (i = 0; i < loop_ub; i++) {
      h_y[(((i + e_y.size(1)) + f_y.size(1)) + h_y.size(0)) + 1] = g_y[i];
    }
    d.set_size((a.size(0) + b.size(0)) + c.size(0));
    loop_ub = a.size(0);
    for (i = 0; i < loop_ub; i++) {
      d[i] = a[i];
    }
    loop_ub = b.size(0);
    for (i = 0; i < loop_ub; i++) {
      d[i + a.size(0)] = b[i];
    }
    loop_ub = c.size(0);
    for (i = 0; i < loop_ub; i++) {
      d[(i + a.size(0)) + b.size(0)] = c[i];
    }
    d_v[0] = static_cast<signed char>(v.size(0));
    d_v[1] = static_cast<signed char>(v.size(0));
    accumarray(h_y, d, d_v, J);
    nx = J.size(1);
    nv = J.size(0);
    loop_ub = J.size(1);
    A.set_size(J.size(1), J.size(1));
    for (j = 0; j < loop_ub; j++) {
      int b_i;
      int boffset;
      int coffset;
      coffset = j * nx;
      boffset = j * J.size(0);
      for (b_i = 0; b_i < nx; b_i++) {
        A[coffset + b_i] = 0.0;
      }
      for (k = 0; k < nv; k++) {
        bkj = J[boffset + k];
        for (b_i = 0; b_i < nx; b_i++) {
          i = coffset + b_i;
          A[i] = A[i] + J[b_i * J.size(0) + k] * bkj;
        }
      }
    }
    if ((A.size(0) == 1) && (A.size(1) == 1)) {
      b.set_size(1);
      b[0] = A[0];
    } else {
      nx = A.size(0);
      nv = A.size(1);
      if (nx <= nv) {
        nv = nx;
      }
      if (0 < A.size(1)) {
        nx = nv;
      } else {
        nx = 0;
      }
      b.set_size(nx);
      i = nx - 1;
      for (k = 0; k <= i; k++) {
        b[k] = A[k + A.size(0) * k];
      }
    }
    loop_ub = b.size(0);
    for (i = 0; i < loop_ub; i++) {
      b[i] = lambda * b[i];
    }
    nv = b.size(0);
    J.set_size(b.size(0), b.size(0));
    loop_ub = b.size(0) * b.size(0);
    for (i = 0; i < loop_ub; i++) {
      J[i] = 0.0;
    }
    for (j = 0; j < nv; j++) {
      J[j + J.size(0) * j] = b[j];
    }
    dx.set_size(v.size(0));
    loop_ub = v.size(0);
    for (i = 0; i < loop_ub; i++) {
      dx[i] = v[i];
    }
    b_A.set_size(A.size(0), A.size(1));
    loop_ub = A.size(0) * A.size(1);
    for (i = 0; i < loop_ub; i++) {
      b_A[i] = A[i] + J[i];
    }
    mldivide(b_A, dx);
  } else if ((Jtri[Jtri.size(0) - 1] == 0.0) &&
             (Jtri[(Jtri.size(0) + Jtri.size(0) * 2) - 1] == 0.0)) {
    int nv;
    dx.set_size(v.size(0));
    loop_ub = v.size(0);
    for (i = 0; i < loop_ub; i++) {
      dx[i] = 0.0;
    }
    alpha.set_size(v.size(0));
    loop_ub = v.size(0);
    for (i = 0; i < loop_ub; i++) {
      alpha[i] = 0.0;
    }
    a.set_size(v.size(0) - 1);
    loop_ub = v.size(0);
    for (i = 0; i <= loop_ub - 2; i++) {
      a[i] = 0.0;
    }
    b.set_size(v.size(0) - 2);
    loop_ub = v.size(0);
    for (i = 0; i <= loop_ub - 3; i++) {
      b[i] = 0.0;
    }
    alpha[0] = d[0];
    a[0] = e[0] / alpha[0];
    b[0] = f[0] / alpha[0];
    alpha[1] = d[1] - e[0] * a[0];
    a[1] = (e[1] - f[0] * a[0]) / alpha[1];
    b[1] = f[1] / alpha[1];
    i = v.size(0);
    for (k = 0; k <= i - 5; k++) {
      double b_d;
      bkj = a[k + 1];
      b_d = (d[k + 2] - f[k] * b[k]) - alpha[k + 1] * (bkj * bkj);
      alpha[k + 2] = b_d;
      a[k + 2] = (e[k + 2] - f[k + 1] * bkj) / b_d;
      b[k + 2] = f[k + 2] / b_d;
    }
    alpha[v.size(0) - 2] =
        (d[v.size(0) - 2] - f[v.size(0) - 4] * b[v.size(0) - 4]) -
        alpha[v.size(0) - 3] * (a[v.size(0) - 3] * a[v.size(0) - 3]);
    a[v.size(0) - 2] =
        (e[v.size(0) - 2] - f[v.size(0) - 3] * a[v.size(0) - 3]) /
        alpha[v.size(0) - 2];
    alpha[v.size(0) - 1] =
        (d[v.size(0) - 1] - f[v.size(0) - 3] * b[v.size(0) - 3]) -
        alpha[v.size(0) - 2] * (a[v.size(0) - 2] * a[v.size(0) - 2]);
    e.set_size(v.size(0));
    loop_ub = v.size(0);
    for (i = 0; i < loop_ub; i++) {
      e[i] = 0.0;
    }
    e[0] = v[0];
    e[1] = v[1] - a[0] * e[0];
    i = v.size(0);
    for (k = 0; k <= i - 3; k++) {
      e[k + 2] = (v[k + 2] - a[k + 1] * e[k + 1]) - b[k] * e[k];
    }
    nx = alpha.size(0);
    nv = e.size(0);
    if (nx <= nv) {
      nv = nx;
    }
    if (e.size(0) == alpha.size(0)) {
      nv = e.size(0);
    }
    c.set_size(nv);
    nx = alpha.size(0);
    nv = e.size(0);
    if (nx <= nv) {
      nv = nx;
    }
    if (e.size(0) == alpha.size(0)) {
      nv = e.size(0);
    }
    i = nv - 1;
    for (k = 0; k <= i; k++) {
      c[k] = e[k] / alpha[k];
    }
    dx[v.size(0) - 1] = c[v.size(0) - 1];
    dx[v.size(0) - 2] = c[v.size(0) - 2] - a[v.size(0) - 2] * dx[v.size(0) - 1];
    i = v.size(0);
    for (k = 0; k <= i - 3; k++) {
      nx = (v.size(0) - k) - 3;
      dx[nx] = (c[nx] - a[nx] * dx[nx + 1]) - b[nx] * dx[nx + 2];
    }
  } else {
    cycsympentdisolve(d, e, f, v, dx);
  }
}

} // namespace scenario
} // namespace internal
} // namespace tracking
} // namespace matlabshared
} // namespace coder

//
// File trailer for LMFsolve.cpp
//
// [EOF]
//
