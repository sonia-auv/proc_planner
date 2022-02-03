//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: dclothoidwp.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 03-Feb-2022 14:08:22
//

// Include Files
#include "dclothoidwp.h"
#include "diff.h"
#include "proc_planner_data.h"
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
static void midcurve(const ::coder::array<creal_T, 2U> &Pb,
                     const ::coder::array<creal_T, 2U> &Vbd,
                     const ::coder::array<double, 2U> &Lab,
                     const ::coder::array<double, 2U> &Lbd,
                     const ::coder::array<double, 2U> &Lde,
                     const ::coder::array<double, 2U> &alpha,
                     const ::coder::array<double, 2U> &beta,
                     ::coder::array<creal_T, 2U> &Pc);

static void optimize(const ::coder::array<creal_T, 2U> &zcurrent,
                     const ::coder::array<creal_T, 2U> &zorig,
                     const creal_T varargin_1[2],
                     ::coder::array<creal_T, 2U> &Zout);

static void optimize(const ::coder::array<creal_T, 2U> &zcurrent,
                     const ::coder::array<creal_T, 2U> &zorig,
                     ::coder::array<creal_T, 2U> &Zout);

static void packageCodegen(const ::coder::array<double, 2U> &r,
                           const ::coder::array<double, 2U> &s, double n,
                           ::coder::array<double, 1U> &u,
                           ::coder::array<double, 1U> &v);

} // namespace scenario
} // namespace internal
} // namespace tracking
} // namespace matlabshared
} // namespace coder

// Function Definitions
//
// Arguments    : const ::coder::array<creal_T, 2U> &Pb
//                const ::coder::array<creal_T, 2U> &Vbd
//                const ::coder::array<double, 2U> &Lab
//                const ::coder::array<double, 2U> &Lbd
//                const ::coder::array<double, 2U> &Lde
//                const ::coder::array<double, 2U> &alpha
//                const ::coder::array<double, 2U> &beta
//                ::coder::array<creal_T, 2U> &Pc
// Return Type  : void
//
namespace coder {
namespace matlabshared {
namespace tracking {
namespace internal {
namespace scenario {
static void midcurve(const ::coder::array<creal_T, 2U> &Pb,
                     const ::coder::array<creal_T, 2U> &Vbd,
                     const ::coder::array<double, 2U> &Lab,
                     const ::coder::array<double, 2U> &Lbd,
                     const ::coder::array<double, 2U> &Lde,
                     const ::coder::array<double, 2U> &alpha,
                     const ::coder::array<double, 2U> &beta,
                     ::coder::array<creal_T, 2U> &Pc)
{
  array<double, 2U> a;
  array<double, 2U> b;
  double b_re;
  double im;
  double re;
  int k;
  int nx;
  a.set_size(1, Lde.size(1));
  nx = Lde.size(1);
  for (k = 0; k < nx; k++) {
    a[k] = 2.0 * Lde[k] + Lbd[k];
  }
  b.set_size(1, Lab.size(1));
  nx = Lab.size(1);
  for (k = 0; k < nx; k++) {
    b[k] = 2.0 * Lab[k] + Lbd[k];
  }
  a.set_size(1, Lbd.size(1));
  nx = Lbd.size(1) - 1;
  for (k = 0; k <= nx; k++) {
    re = a[k];
    im = Lbd[k];
    b_re = b[k];
    re = im * (alpha[k] * re + beta[k] * b_re) /
         (2.0 * (re * b_re) + im * (re + b_re));
    a[k] = re;
  }
  nx = a.size(1);
  for (k = 0; k < nx; k++) {
    a[k] = std::tan(a[k]);
  }
  Pc.set_size(1, Pb.size(1));
  nx = Pb.size(1);
  for (k = 0; k < nx; k++) {
    double b_re_tmp;
    double re_tmp;
    re = 0.0 * a[k] + 1.0;
    im = a[k];
    re_tmp = Vbd[k].im;
    b_re_tmp = Vbd[k].re;
    b_re = re * b_re_tmp - im * re_tmp;
    im = re * re_tmp + im * b_re_tmp;
    if (im == 0.0) {
      re = b_re / 2.0;
      im = 0.0;
    } else if (b_re == 0.0) {
      re = 0.0;
      im /= 2.0;
    } else {
      re = b_re / 2.0;
      im /= 2.0;
    }
    Pc[k].re = Pb[k].re + re;
    Pc[k].im = Pb[k].im + im;
  }
  nx = Lbd.size(1);
  for (k = 0; k < nx; k++) {
    if (Lbd[k] == 0.0) {
      Pc[k] = Pb[k];
    }
  }
}

//
// Arguments    : const ::coder::array<creal_T, 2U> &zcurrent
//                const ::coder::array<creal_T, 2U> &zorig
//                const creal_T varargin_1[2]
//                ::coder::array<creal_T, 2U> &Zout
// Return Type  : void
//
static void optimize(const ::coder::array<creal_T, 2U> &zcurrent,
                     const ::coder::array<creal_T, 2U> &zorig,
                     const creal_T varargin_1[2],
                     ::coder::array<creal_T, 2U> &Zout)
{
  array<creal_T, 2U> b_d2;
  array<creal_T, 2U> d1;
  array<creal_T, 2U> d2;
  array<creal_T, 2U> z;
  array<double, 2U> alpha;
  array<double, 2U> b_l1;
  array<double, 2U> beta;
  array<double, 2U> c_l1;
  array<double, 2U> d_l1;
  array<double, 2U> l1;
  double zleft_im;
  double zleft_re;
  double zright_im;
  double zright_re;
  int i;
  int i1;
  int i2;
  int i3;
  int i4;
  int i5;
  int k;
  int loop_ub;
  int nx;
  bool b;
  bool b1;
  bool b2;
  bool b3;
  b = std::isnan(varargin_1[0].re);
  b1 = std::isnan(varargin_1[0].im);
  if (b || b1) {
    zleft_re = zcurrent[0].re + 100.0 * (zcurrent[0].re - zcurrent[1].re);
    zleft_im = zcurrent[0].im + 100.0 * (zcurrent[0].im - zcurrent[1].im);
  } else {
    zleft_re = rtNaN;
    zleft_im = 0.0;
  }
  b2 = std::isnan(varargin_1[1].re);
  b3 = std::isnan(varargin_1[1].im);
  if (b2 || b3) {
    zright_re = zcurrent[zcurrent.size(1) - 1].re +
                100.0 * (zcurrent[zcurrent.size(1) - 1].re -
                         zcurrent[zcurrent.size(1) - 2].re);
    zright_im = zcurrent[zcurrent.size(1) - 1].im +
                100.0 * (zcurrent[zcurrent.size(1) - 1].im -
                         zcurrent[zcurrent.size(1) - 2].im);
  } else {
    zright_re = rtNaN;
    zright_im = 0.0;
  }
  z.set_size(1, zcurrent.size(1) + 2);
  z[0].re = zleft_re;
  z[0].im = zleft_im;
  loop_ub = zcurrent.size(1);
  for (i = 0; i < loop_ub; i++) {
    z[i + 1] = zcurrent[i];
  }
  z[zcurrent.size(1) + 1].re = zright_re;
  z[zcurrent.size(1) + 1].im = zright_im;
  diff(z, d1);
  nx = d1.size(1);
  l1.set_size(1, d1.size(1));
  for (k = 0; k < nx; k++) {
    l1[k] = rt_hypotd_snf(d1[k].re, d1[k].im);
  }
  if (3 > z.size(1)) {
    i = 0;
    i1 = 0;
  } else {
    i = 2;
    i1 = z.size(1);
  }
  loop_ub = i1 - i;
  d2.set_size(1, loop_ub);
  for (i1 = 0; i1 < loop_ub; i1++) {
    i2 = i + i1;
    d2[i1].re = z[i2].re - z[i1].re;
    d2[i1].im = z[i2].im - z[i1].im;
  }
  if (2 > d2.size(1) - 1) {
    i = 0;
    i1 = 0;
  } else {
    i = 1;
    i1 = d2.size(1) - 1;
  }
  loop_ub = i1 - i;
  z.set_size(1, loop_ub);
  for (i1 = 0; i1 < loop_ub; i1++) {
    nx = i + i1;
    zleft_re = d2[nx].re;
    zleft_im = -d2[nx].im;
    zright_re = d1[i1].im;
    zright_im = d1[i1].re;
    z[i1].re = zleft_re * zright_im - zleft_im * zright_re;
    z[i1].im = zleft_re * zright_re + zleft_im * zright_im;
  }
  nx = z.size(1);
  alpha.set_size(1, z.size(1));
  for (k = 0; k < nx; k++) {
    alpha[k] = rt_atan2d_snf(z[k].im, z[k].re);
  }
  if (4 > d1.size(1)) {
    i = 0;
    i1 = 0;
  } else {
    i = 3;
    i1 = d1.size(1);
  }
  i2 = (2 <= d2.size(1) - 1);
  loop_ub = i1 - i;
  z.set_size(1, loop_ub);
  for (i1 = 0; i1 < loop_ub; i1++) {
    nx = i + i1;
    zleft_re = d1[nx].re;
    zleft_im = -d1[nx].im;
    nx = i2 + i1;
    zright_re = d2[nx].im;
    zright_im = d2[nx].re;
    z[i1].re = zleft_re * zright_im - zleft_im * zright_re;
    z[i1].im = zleft_re * zright_re + zleft_im * zright_im;
  }
  nx = z.size(1);
  beta.set_size(1, z.size(1));
  for (k = 0; k < nx; k++) {
    beta[k] = rt_atan2d_snf(z[k].im, z[k].re);
  }
  if ((!b) && (!b1)) {
    l1[0] = 0.0;
    alpha[0] = rt_atan2d_snf(
        d2[1].re * varargin_1[0].im + -d2[1].im * varargin_1[0].re,
        d2[1].re * varargin_1[0].re - -d2[1].im * varargin_1[0].im);
  }
  if ((!b2) && (!b3)) {
    l1[l1.size(1) - 1] = 0.0;
    beta[beta.size(1) - 1] =
        rt_atan2d_snf(varargin_1[1].re * d2[d2.size(1) - 2].im +
                          -varargin_1[1].im * d2[d2.size(1) - 2].re,
                      varargin_1[1].re * d2[d2.size(1) - 2].re -
                          -varargin_1[1].im * d2[d2.size(1) - 2].im);
  }
  if (1 > zcurrent.size(1) - 2) {
    loop_ub = 0;
  } else {
    loop_ub = zcurrent.size(1) - 2;
  }
  if (2 > d2.size(1) - 1) {
    i = 0;
    i1 = 0;
  } else {
    i = 1;
    i1 = d2.size(1) - 1;
  }
  if (1 > l1.size(1) - 3) {
    k = 0;
  } else {
    k = l1.size(1) - 3;
  }
  if (2 > l1.size(1) - 2) {
    i2 = 0;
    nx = 0;
  } else {
    i2 = 1;
    nx = l1.size(1) - 2;
  }
  if (3 > l1.size(1) - 1) {
    i3 = 0;
  } else {
    i3 = 2;
  }
  if (4 > l1.size(1)) {
    i4 = 0;
    i5 = 0;
  } else {
    i4 = 3;
    i5 = l1.size(1);
  }
  d1.set_size(1, loop_ub);
  for (int i6{0}; i6 < loop_ub; i6++) {
    d1[i6] = zcurrent[i6];
  }
  loop_ub = i1 - i;
  b_d2.set_size(1, loop_ub);
  for (i1 = 0; i1 < loop_ub; i1++) {
    b_d2[i1] = d2[i + i1];
  }
  b_l1.set_size(1, k);
  for (i = 0; i < k; i++) {
    b_l1[i] = l1[i];
  }
  loop_ub = nx - i2;
  c_l1.set_size(1, loop_ub);
  for (i = 0; i < loop_ub; i++) {
    c_l1[i] = l1[i2 + i] + l1[i3 + i];
  }
  loop_ub = i5 - i4;
  d_l1.set_size(1, loop_ub);
  for (i = 0; i < loop_ub; i++) {
    d_l1[i] = l1[i4 + i];
  }
  midcurve(d1, b_d2, b_l1, c_l1, d_l1, alpha, beta, z);
  Zout.set_size(1, z.size(1) + 2);
  Zout[0] = zorig[0];
  loop_ub = z.size(1);
  for (i = 0; i < loop_ub; i++) {
    Zout[i + 1] = z[i];
  }
  Zout[z.size(1) + 1] = zorig[zorig.size(1) - 1];
  zright_re = static_cast<double>(zcurrent.size(1) - zorig.size(1)) /
                  (static_cast<double>(zorig.size(1)) - 1.0) +
              1.0;
  if ((zright_re == 0.0) || (0.0 > zright_re)) {
    i = 1;
  } else {
    i = static_cast<int>(static_cast<double>(zcurrent.size(1) - zorig.size(1)) /
                             (static_cast<double>(zorig.size(1)) - 1.0) +
                         1.0);
  }
  loop_ub = zorig.size(1);
  for (i1 = 0; i1 < loop_ub; i1++) {
    Zout[i * i1] = zorig[i1];
  }
}

//
// Arguments    : const ::coder::array<creal_T, 2U> &zcurrent
//                const ::coder::array<creal_T, 2U> &zorig
//                ::coder::array<creal_T, 2U> &Zout
// Return Type  : void
//
static void optimize(const ::coder::array<creal_T, 2U> &zcurrent,
                     const ::coder::array<creal_T, 2U> &zorig,
                     ::coder::array<creal_T, 2U> &Zout)
{
  array<creal_T, 2U> b_d2;
  array<creal_T, 2U> d1;
  array<creal_T, 2U> d2;
  array<creal_T, 2U> z;
  array<double, 2U> alpha;
  array<double, 2U> b_l1;
  array<double, 2U> beta;
  array<double, 2U> c_l1;
  array<double, 2U> d_l1;
  array<double, 2U> l1;
  double zleft_im;
  double zleft_re;
  double zright_im;
  double zright_re;
  int i;
  int i1;
  int i2;
  int i3;
  int i4;
  int i5;
  int k;
  int loop_ub;
  int nx;
  if ((zorig[0].re == zorig[zorig.size(1) - 1].re) &&
      (zorig[0].im == zorig[zorig.size(1) - 1].im) && (zorig.size(1) > 2)) {
    zleft_re = zcurrent[zcurrent.size(1) - 2].re;
    zleft_im = zcurrent[zcurrent.size(1) - 2].im;
    zright_re = zcurrent[1].re;
    zright_im = zcurrent[1].im;
  } else {
    zleft_re = zcurrent[0].re + 100.0 * (zcurrent[0].re - zcurrent[1].re);
    zleft_im = zcurrent[0].im + 100.0 * (zcurrent[0].im - zcurrent[1].im);
    zright_re = zcurrent[zcurrent.size(1) - 1].re +
                100.0 * (zcurrent[zcurrent.size(1) - 1].re -
                         zcurrent[zcurrent.size(1) - 2].re);
    zright_im = zcurrent[zcurrent.size(1) - 1].im +
                100.0 * (zcurrent[zcurrent.size(1) - 1].im -
                         zcurrent[zcurrent.size(1) - 2].im);
  }
  z.set_size(1, zcurrent.size(1) + 2);
  z[0].re = zleft_re;
  z[0].im = zleft_im;
  loop_ub = zcurrent.size(1);
  for (i = 0; i < loop_ub; i++) {
    z[i + 1] = zcurrent[i];
  }
  z[zcurrent.size(1) + 1].re = zright_re;
  z[zcurrent.size(1) + 1].im = zright_im;
  diff(z, d1);
  nx = d1.size(1);
  l1.set_size(1, d1.size(1));
  for (k = 0; k < nx; k++) {
    l1[k] = rt_hypotd_snf(d1[k].re, d1[k].im);
  }
  if (3 > z.size(1)) {
    i = 0;
    i1 = 0;
  } else {
    i = 2;
    i1 = z.size(1);
  }
  loop_ub = i1 - i;
  d2.set_size(1, loop_ub);
  for (i1 = 0; i1 < loop_ub; i1++) {
    i2 = i + i1;
    d2[i1].re = z[i2].re - z[i1].re;
    d2[i1].im = z[i2].im - z[i1].im;
  }
  if (2 > d2.size(1) - 1) {
    i = 0;
    i1 = 0;
  } else {
    i = 1;
    i1 = d2.size(1) - 1;
  }
  loop_ub = i1 - i;
  z.set_size(1, loop_ub);
  for (i1 = 0; i1 < loop_ub; i1++) {
    nx = i + i1;
    zleft_re = d2[nx].re;
    zleft_im = -d2[nx].im;
    zright_re = d1[i1].im;
    zright_im = d1[i1].re;
    z[i1].re = zleft_re * zright_im - zleft_im * zright_re;
    z[i1].im = zleft_re * zright_re + zleft_im * zright_im;
  }
  nx = z.size(1);
  alpha.set_size(1, z.size(1));
  for (k = 0; k < nx; k++) {
    alpha[k] = rt_atan2d_snf(z[k].im, z[k].re);
  }
  if (4 > d1.size(1)) {
    i = 0;
    i1 = 0;
  } else {
    i = 3;
    i1 = d1.size(1);
  }
  i2 = (2 <= d2.size(1) - 1);
  loop_ub = i1 - i;
  z.set_size(1, loop_ub);
  for (i1 = 0; i1 < loop_ub; i1++) {
    nx = i + i1;
    zleft_re = d1[nx].re;
    zleft_im = -d1[nx].im;
    nx = i2 + i1;
    zright_re = d2[nx].im;
    zright_im = d2[nx].re;
    z[i1].re = zleft_re * zright_im - zleft_im * zright_re;
    z[i1].im = zleft_re * zright_re + zleft_im * zright_im;
  }
  nx = z.size(1);
  beta.set_size(1, z.size(1));
  for (k = 0; k < nx; k++) {
    beta[k] = rt_atan2d_snf(z[k].im, z[k].re);
  }
  if (1 > zcurrent.size(1) - 2) {
    loop_ub = 0;
  } else {
    loop_ub = zcurrent.size(1) - 2;
  }
  if (2 > d2.size(1) - 1) {
    i = 0;
    i1 = 0;
  } else {
    i = 1;
    i1 = d2.size(1) - 1;
  }
  if (1 > l1.size(1) - 3) {
    k = 0;
  } else {
    k = l1.size(1) - 3;
  }
  if (2 > l1.size(1) - 2) {
    i2 = 0;
    nx = 0;
  } else {
    i2 = 1;
    nx = l1.size(1) - 2;
  }
  if (3 > l1.size(1) - 1) {
    i3 = 0;
  } else {
    i3 = 2;
  }
  if (4 > l1.size(1)) {
    i4 = 0;
    i5 = 0;
  } else {
    i4 = 3;
    i5 = l1.size(1);
  }
  d1.set_size(1, loop_ub);
  for (int i6{0}; i6 < loop_ub; i6++) {
    d1[i6] = zcurrent[i6];
  }
  loop_ub = i1 - i;
  b_d2.set_size(1, loop_ub);
  for (i1 = 0; i1 < loop_ub; i1++) {
    b_d2[i1] = d2[i + i1];
  }
  b_l1.set_size(1, k);
  for (i = 0; i < k; i++) {
    b_l1[i] = l1[i];
  }
  loop_ub = nx - i2;
  c_l1.set_size(1, loop_ub);
  for (i = 0; i < loop_ub; i++) {
    c_l1[i] = l1[i2 + i] + l1[i3 + i];
  }
  loop_ub = i5 - i4;
  d_l1.set_size(1, loop_ub);
  for (i = 0; i < loop_ub; i++) {
    d_l1[i] = l1[i4 + i];
  }
  midcurve(d1, b_d2, b_l1, c_l1, d_l1, alpha, beta, z);
  Zout.set_size(1, z.size(1) + 2);
  Zout[0] = zorig[0];
  loop_ub = z.size(1);
  for (i = 0; i < loop_ub; i++) {
    Zout[i + 1] = z[i];
  }
  Zout[z.size(1) + 1] = zorig[zorig.size(1) - 1];
  zright_re = static_cast<double>(zcurrent.size(1) - zorig.size(1)) /
                  (static_cast<double>(zorig.size(1)) - 1.0) +
              1.0;
  if ((zright_re == 0.0) || (0.0 > zright_re)) {
    i = 1;
  } else {
    i = static_cast<int>(static_cast<double>(zcurrent.size(1) - zorig.size(1)) /
                             (static_cast<double>(zorig.size(1)) - 1.0) +
                         1.0);
  }
  loop_ub = zorig.size(1);
  for (i1 = 0; i1 < loop_ub; i1++) {
    Zout[i * i1] = zorig[i1];
  }
}

//
// Arguments    : const ::coder::array<double, 2U> &r
//                const ::coder::array<double, 2U> &s
//                double n
//                ::coder::array<double, 1U> &u
//                ::coder::array<double, 1U> &v
// Return Type  : void
//
static void packageCodegen(const ::coder::array<double, 2U> &r,
                           const ::coder::array<double, 2U> &s, double n,
                           ::coder::array<double, 1U> &u,
                           ::coder::array<double, 1U> &v)
{
  int i;
  int loop_ub_tmp;
  loop_ub_tmp = static_cast<int>(n);
  u.set_size(loop_ub_tmp);
  v.set_size(loop_ub_tmp);
  for (i = 0; i < loop_ub_tmp; i++) {
    u[i] = 0.0;
    v[i] = 0.0;
  }
  if (1.0 > n) {
    loop_ub_tmp = -1;
  } else {
    loop_ub_tmp = static_cast<int>(n) - 1;
  }
  for (i = 0; i <= loop_ub_tmp; i++) {
    u[i] = r[i];
  }
  if (1.0 > n) {
    loop_ub_tmp = -1;
  } else {
    loop_ub_tmp = static_cast<int>(n) - 1;
  }
  for (i = 0; i <= loop_ub_tmp; i++) {
    v[i] = s[i];
  }
}

//
// Arguments    : const ::coder::array<double, 1U> &x
//                const ::coder::array<double, 1U> &y
//                const double varargin_1[2]
//                const double varargin_2[2]
//                ::coder::array<double, 1U> &u
//                ::coder::array<double, 1U> &v
// Return Type  : void
//
void dclothoidwp(const ::coder::array<double, 1U> &x,
                 const ::coder::array<double, 1U> &y,
                 const double varargin_1[2], const double varargin_2[2],
                 ::coder::array<double, 1U> &u, ::coder::array<double, 1U> &v)
{
  array<creal_T, 2U> Zout;
  array<creal_T, 2U> b_z;
  array<creal_T, 2U> c_z;
  array<creal_T, 2U> dz;
  array<creal_T, 2U> zcurrent;
  array<creal_T, 1U> z;
  array<double, 2U> alpha;
  array<double, 2U> b_alpha;
  array<double, 2U> b_l;
  array<double, 2U> c_l;
  array<double, 2U> d_l;
  array<double, 2U> l;
  creal_T t0_f1[2];
  double m;
  double nmax;
  int b_loop_ub;
  int b_varargin_2;
  int i;
  int loop_ub;
  bool b;
  bool b1;
  bool b2;
  bool b3;
  z.set_size(x.size(0));
  loop_ub = x.size(0);
  for (i = 0; i < loop_ub; i++) {
    z[i].re = x[i];
    z[i].im = y[i];
  }
  b_varargin_2 = z.size(0);
  t0_f1[0].re = varargin_1[0];
  t0_f1[0].im = varargin_2[0];
  t0_f1[1].re = varargin_1[1];
  t0_f1[1].im = varargin_2[1];
  nmax = (static_cast<double>(z.size(0)) - 1.0) * 128.0 + 1.0;
  loop_ub =
      static_cast<int>((static_cast<double>(z.size(0)) - 1.0) * 128.0 + 1.0);
  i = static_cast<int>(nmax);
  Zout.set_size(1, i);
  for (i = 0; i < loop_ub; i++) {
    Zout[i].re = 0.0;
    Zout[i].im = 0.0;
  }
  m = z.size(0);
  b_loop_ub = z.size(0);
  for (i = 0; i < b_loop_ub; i++) {
    Zout[i] = z[i];
  }
  b = std::isnan(t0_f1[0].re);
  b1 = std::isnan(t0_f1[0].im);
  b2 = std::isnan(t0_f1[1].re);
  b3 = std::isnan(t0_f1[1].im);
  i = static_cast<int>(nmax);
  for (int b_i{0}; b_i < 7; b_i++) {
    array<creal_T, 2U> d_z;
    double mnew_tmp;
    double zcurrent_im_tmp;
    double zleft_im;
    double zleft_re;
    double zright_re;
    int c_loop_ub;
    int d_loop_ub;
    int i1;
    int i2;
    int i3;
    int i4;
    int i5;
    int i6;
    int i7;
    int i8;
    int k;
    int nx;
    mnew_tmp = 2.0 * m - 1.0;
    if (1.0 > m) {
      b_loop_ub = -1;
    } else {
      b_loop_ub = static_cast<int>(m) - 1;
    }
    zcurrent.set_size(1, b_loop_ub + 1);
    for (i1 = 0; i1 <= b_loop_ub; i1++) {
      zcurrent[i1] = Zout[i1];
    }
    if (b || b1) {
      zleft_re = zcurrent[0].re + 100.0 * (zcurrent[0].re - zcurrent[1].re);
      zleft_im = zcurrent[0].im + 100.0 * (zcurrent[0].im - zcurrent[1].im);
    } else {
      zleft_re = rtNaN;
      zleft_im = 0.0;
    }
    if (b2 || b3) {
      nmax = zcurrent[b_loop_ub].re;
      zcurrent_im_tmp = zcurrent[b_loop_ub].im;
      zright_re = nmax + 100.0 * (nmax - zcurrent[b_loop_ub - 1].re);
      nmax = zcurrent_im_tmp +
             100.0 * (zcurrent_im_tmp - zcurrent[b_loop_ub - 1].im);
    } else {
      zright_re = rtNaN;
      nmax = 0.0;
    }
    if (1.0 > m) {
      b_loop_ub = -1;
    } else {
      b_loop_ub = static_cast<int>(m) - 1;
    }
    b_z.set_size(1, b_loop_ub + 3);
    b_z[0].re = zleft_re;
    b_z[0].im = zleft_im;
    for (i1 = 0; i1 <= b_loop_ub; i1++) {
      b_z[i1 + 1] = Zout[i1];
    }
    b_z[b_loop_ub + 2].re = zright_re;
    b_z[b_loop_ub + 2].im = nmax;
    diff(b_z, dz);
    nx = dz.size(1);
    l.set_size(1, dz.size(1));
    for (k = 0; k < nx; k++) {
      l[k] = rt_hypotd_snf(dz[k].re, dz[k].im);
    }
    if (2 > dz.size(1)) {
      i1 = 0;
      i2 = 0;
    } else {
      i1 = 1;
      i2 = dz.size(1);
    }
    b_loop_ub = i2 - i1;
    zcurrent.set_size(1, b_loop_ub);
    for (i2 = 0; i2 < b_loop_ub; i2++) {
      nx = i1 + i2;
      nmax = dz[nx].re;
      zright_re = -dz[nx].im;
      zcurrent_im_tmp = dz[i2].im;
      zleft_re = dz[i2].re;
      zcurrent[i2].re = nmax * zleft_re - zright_re * zcurrent_im_tmp;
      zcurrent[i2].im = nmax * zcurrent_im_tmp + zright_re * zleft_re;
    }
    nx = zcurrent.size(1);
    b_alpha.set_size(1, zcurrent.size(1));
    for (k = 0; k < nx; k++) {
      b_alpha[k] = rt_atan2d_snf(zcurrent[k].im, zcurrent[k].re);
    }
    if ((!b) && (!b1)) {
      l[0] = 0.0;
      b_alpha[0] =
          rt_atan2d_snf(dz[1].re * t0_f1[0].im + -dz[1].im * t0_f1[0].re,
                        dz[1].re * t0_f1[0].re - -dz[1].im * t0_f1[0].im);
    }
    if ((!b2) && (!b3)) {
      l[l.size(1) - 1] = 0.0;
      b_alpha[b_alpha.size(1) - 1] =
          rt_atan2d_snf(t0_f1[1].re * dz[dz.size(1) - 2].im +
                            -t0_f1[1].im * dz[dz.size(1) - 2].re,
                        t0_f1[1].re * dz[dz.size(1) - 2].re -
                            -t0_f1[1].im * dz[dz.size(1) - 2].im);
    }
    if (2 > b_z.size(1) - 2) {
      i1 = 0;
      i2 = 0;
    } else {
      i1 = 1;
      i2 = b_z.size(1) - 2;
    }
    if (2 > dz.size(1) - 1) {
      i3 = 0;
      nx = 0;
    } else {
      i3 = 1;
      nx = dz.size(1) - 1;
    }
    if (1 > l.size(1) - 2) {
      b_loop_ub = 0;
    } else {
      b_loop_ub = l.size(1) - 2;
    }
    if (2 > l.size(1) - 1) {
      k = 0;
      i4 = 0;
    } else {
      k = 1;
      i4 = l.size(1) - 1;
    }
    if (3 > l.size(1)) {
      i5 = 0;
      i6 = 0;
    } else {
      i5 = 2;
      i6 = l.size(1);
    }
    if (1 > b_alpha.size(1) - 1) {
      c_loop_ub = 0;
    } else {
      c_loop_ub = b_alpha.size(1) - 1;
    }
    if (2 > b_alpha.size(1)) {
      i7 = 0;
      i8 = 0;
    } else {
      i7 = 1;
      i8 = b_alpha.size(1);
    }
    d_loop_ub = i2 - i1;
    c_z.set_size(1, d_loop_ub);
    for (i2 = 0; i2 < d_loop_ub; i2++) {
      c_z[i2] = b_z[i1 + i2];
    }
    d_loop_ub = nx - i3;
    zcurrent.set_size(1, d_loop_ub);
    for (i1 = 0; i1 < d_loop_ub; i1++) {
      zcurrent[i1] = dz[i3 + i1];
    }
    b_l.set_size(1, b_loop_ub);
    for (i1 = 0; i1 < b_loop_ub; i1++) {
      b_l[i1] = l[i1];
    }
    b_loop_ub = i4 - k;
    c_l.set_size(1, b_loop_ub);
    for (i1 = 0; i1 < b_loop_ub; i1++) {
      c_l[i1] = l[k + i1];
    }
    b_loop_ub = i6 - i5;
    d_l.set_size(1, b_loop_ub);
    for (i1 = 0; i1 < b_loop_ub; i1++) {
      d_l[i1] = l[i5 + i1];
    }
    alpha.set_size(1, c_loop_ub);
    for (i1 = 0; i1 < c_loop_ub; i1++) {
      alpha[i1] = b_alpha[i1];
    }
    b_loop_ub = i8 - i7;
    l.set_size(1, b_loop_ub);
    for (i1 = 0; i1 < b_loop_ub; i1++) {
      l[i1] = b_alpha[i7 + i1];
    }
    midcurve(c_z, zcurrent, b_l, c_l, d_l, alpha, l, b_z);
    zcurrent.set_size(1, i);
    for (i1 = 0; i1 < loop_ub; i1++) {
      zcurrent[i1].re = 0.0;
      zcurrent[i1].im = 0.0;
    }
    if (1.0 > m) {
      b_loop_ub = -1;
    } else {
      b_loop_ub = static_cast<int>(m) - 1;
    }
    if (1.0 > mnew_tmp) {
      i1 = 1;
    } else {
      i1 = 2;
    }
    for (i2 = 0; i2 <= b_loop_ub; i2++) {
      zcurrent[i1 * i2] = Zout[i2];
    }
    if (2U > (static_cast<unsigned int>(b_z.size(1)) << 1) + 1U) {
      i1 = 0;
      i2 = 1;
    } else {
      i1 = 1;
      i2 = 2;
    }
    b_loop_ub = b_z.size(1);
    for (i3 = 0; i3 < b_loop_ub; i3++) {
      zcurrent[i1 + i2 * i3] = b_z[i3];
    }
    if (1.0 > mnew_tmp) {
      b_loop_ub = -1;
    } else {
      b_loop_ub = static_cast<int>(mnew_tmp) - 1;
    }
    for (i1 = 0; i1 <= b_loop_ub; i1++) {
      Zout[i1] = zcurrent[i1];
    }
    if (1.0 > mnew_tmp) {
      b_loop_ub = 0;
    } else {
      b_loop_ub = static_cast<int>(mnew_tmp);
    }
    zcurrent.set_size(1, b_loop_ub);
    for (i1 = 0; i1 < b_loop_ub; i1++) {
      zcurrent[i1] = Zout[i1];
    }
    d_z = z.reshape(1, b_varargin_2);
    optimize(zcurrent, d_z, t0_f1, b_z);
    b_loop_ub = b_z.size(1);
    for (i1 = 0; i1 < b_loop_ub; i1++) {
      Zout[i1] = b_z[i1];
    }
    if (1.0 > mnew_tmp) {
      b_loop_ub = 0;
    } else {
      b_loop_ub = static_cast<int>(mnew_tmp);
    }
    zcurrent.set_size(1, b_loop_ub);
    for (i1 = 0; i1 < b_loop_ub; i1++) {
      zcurrent[i1] = Zout[i1];
    }
    d_z = z.reshape(1, b_varargin_2);
    optimize(zcurrent, d_z, t0_f1, b_z);
    b_loop_ub = b_z.size(1);
    for (i1 = 0; i1 < b_loop_ub; i1++) {
      Zout[i1] = b_z[i1];
    }
    if (1.0 > mnew_tmp) {
      b_loop_ub = 0;
    } else {
      b_loop_ub = static_cast<int>(mnew_tmp);
    }
    zcurrent.set_size(1, b_loop_ub);
    for (i1 = 0; i1 < b_loop_ub; i1++) {
      zcurrent[i1] = Zout[i1];
    }
    d_z = z.reshape(1, b_varargin_2);
    optimize(zcurrent, d_z, t0_f1, b_z);
    b_loop_ub = b_z.size(1);
    for (i1 = 0; i1 < b_loop_ub; i1++) {
      Zout[i1] = b_z[i1];
    }
    m = mnew_tmp;
  }
  l.set_size(1, Zout.size(1));
  loop_ub = Zout.size(1);
  for (i = 0; i < loop_ub; i++) {
    l[i] = Zout[i].re;
  }
  alpha.set_size(1, Zout.size(1));
  loop_ub = Zout.size(1);
  for (i = 0; i < loop_ub; i++) {
    alpha[i] = Zout[i].im;
  }
  packageCodegen(l, alpha, 128.0 * (static_cast<double>(x.size(0)) - 1.0) + 1.0,
                 u, v);
}

//
// Arguments    : const ::coder::array<double, 1U> &x
//                const ::coder::array<double, 1U> &y
//                ::coder::array<double, 1U> &u
//                ::coder::array<double, 1U> &v
// Return Type  : void
//
void dclothoidwp(const ::coder::array<double, 1U> &x,
                 const ::coder::array<double, 1U> &y,
                 ::coder::array<double, 1U> &u, ::coder::array<double, 1U> &v)
{
  array<creal_T, 2U> Zout;
  array<creal_T, 2U> b_z;
  array<creal_T, 2U> c_z;
  array<creal_T, 2U> dz;
  array<creal_T, 2U> zcurrent;
  array<creal_T, 1U> z;
  array<double, 2U> alpha;
  array<double, 2U> b_alpha;
  array<double, 2U> b_l;
  array<double, 2U> c_l;
  array<double, 2U> d_l;
  array<double, 2U> l;
  double m;
  double nmax;
  int b_loop_ub;
  int i;
  int loop_ub;
  int varargin_2;
  z.set_size(x.size(0));
  loop_ub = x.size(0);
  for (i = 0; i < loop_ub; i++) {
    z[i].re = x[i];
    z[i].im = y[i];
  }
  varargin_2 = z.size(0);
  nmax = (static_cast<double>(z.size(0)) - 1.0) * 128.0 + 1.0;
  loop_ub =
      static_cast<int>((static_cast<double>(z.size(0)) - 1.0) * 128.0 + 1.0);
  i = static_cast<int>(nmax);
  Zout.set_size(1, i);
  for (i = 0; i < loop_ub; i++) {
    Zout[i].re = 0.0;
    Zout[i].im = 0.0;
  }
  m = z.size(0);
  b_loop_ub = z.size(0);
  for (i = 0; i < b_loop_ub; i++) {
    Zout[i] = z[i];
  }
  i = static_cast<int>(nmax);
  for (int b_i{0}; b_i < 7; b_i++) {
    array<creal_T, 2U> d_z;
    double mnew_tmp;
    double zcurrent_im_tmp;
    double zleft_im;
    double zleft_re;
    double zright_re;
    int c_loop_ub;
    int i1;
    int i2;
    int i3;
    int i4;
    int i5;
    int i6;
    int i7;
    int i8;
    int i9;
    int k;
    int nx;
    mnew_tmp = 2.0 * m - 1.0;
    if (1.0 > m) {
      b_loop_ub = -1;
      nx = 0;
    } else {
      b_loop_ub = static_cast<int>(m) - 1;
      nx = static_cast<int>(m);
    }
    zcurrent.set_size(1, b_loop_ub + 1);
    for (i1 = 0; i1 <= b_loop_ub; i1++) {
      zcurrent[i1] = Zout[i1];
    }
    b_z.set_size(1, nx);
    for (i1 = 0; i1 < nx; i1++) {
      b_z[i1] = Zout[i1];
    }
    if ((b_z[0].re == b_z[nx - 1].re) && (b_z[0].im == b_z[nx - 1].im) &&
        (nx > 2)) {
      zleft_re = zcurrent[b_loop_ub - 1].re;
      zleft_im = zcurrent[b_loop_ub - 1].im;
      zright_re = zcurrent[1].re;
      nmax = zcurrent[1].im;
    } else {
      zleft_re = zcurrent[0].re + 100.0 * (zcurrent[0].re - zcurrent[1].re);
      zleft_im = zcurrent[0].im + 100.0 * (zcurrent[0].im - zcurrent[1].im);
      nmax = zcurrent[b_loop_ub].re;
      zcurrent_im_tmp = zcurrent[b_loop_ub].im;
      zright_re = nmax + 100.0 * (nmax - zcurrent[b_loop_ub - 1].re);
      nmax = zcurrent_im_tmp +
             100.0 * (zcurrent_im_tmp - zcurrent[b_loop_ub - 1].im);
    }
    if (1.0 > m) {
      b_loop_ub = -1;
    } else {
      b_loop_ub = static_cast<int>(m) - 1;
    }
    b_z.set_size(1, b_loop_ub + 3);
    b_z[0].re = zleft_re;
    b_z[0].im = zleft_im;
    for (i1 = 0; i1 <= b_loop_ub; i1++) {
      b_z[i1 + 1] = Zout[i1];
    }
    b_z[b_loop_ub + 2].re = zright_re;
    b_z[b_loop_ub + 2].im = nmax;
    diff(b_z, dz);
    nx = dz.size(1);
    l.set_size(1, dz.size(1));
    for (k = 0; k < nx; k++) {
      l[k] = rt_hypotd_snf(dz[k].re, dz[k].im);
    }
    if (2 > dz.size(1)) {
      i1 = 0;
      i2 = 0;
    } else {
      i1 = 1;
      i2 = dz.size(1);
    }
    b_loop_ub = i2 - i1;
    zcurrent.set_size(1, b_loop_ub);
    for (i2 = 0; i2 < b_loop_ub; i2++) {
      nx = i1 + i2;
      nmax = dz[nx].re;
      zcurrent_im_tmp = -dz[nx].im;
      zright_re = dz[i2].im;
      zleft_re = dz[i2].re;
      zcurrent[i2].re = nmax * zleft_re - zcurrent_im_tmp * zright_re;
      zcurrent[i2].im = nmax * zright_re + zcurrent_im_tmp * zleft_re;
    }
    nx = zcurrent.size(1);
    b_alpha.set_size(1, zcurrent.size(1));
    for (k = 0; k < nx; k++) {
      b_alpha[k] = rt_atan2d_snf(zcurrent[k].im, zcurrent[k].re);
    }
    if (2 > b_z.size(1) - 2) {
      i1 = 0;
      i2 = 0;
    } else {
      i1 = 1;
      i2 = b_z.size(1) - 2;
    }
    if (2 > dz.size(1) - 1) {
      i3 = 0;
      k = 0;
    } else {
      i3 = 1;
      k = dz.size(1) - 1;
    }
    if (1 > l.size(1) - 2) {
      b_loop_ub = 0;
    } else {
      b_loop_ub = l.size(1) - 2;
    }
    if (2 > l.size(1) - 1) {
      i4 = 0;
      i5 = 0;
    } else {
      i4 = 1;
      i5 = l.size(1) - 1;
    }
    if (3 > l.size(1)) {
      i6 = 0;
      i7 = 0;
    } else {
      i6 = 2;
      i7 = l.size(1);
    }
    if (1 > b_alpha.size(1) - 1) {
      nx = 0;
    } else {
      nx = b_alpha.size(1) - 1;
    }
    if (2 > b_alpha.size(1)) {
      i8 = 0;
      i9 = 0;
    } else {
      i8 = 1;
      i9 = b_alpha.size(1);
    }
    c_loop_ub = i2 - i1;
    c_z.set_size(1, c_loop_ub);
    for (i2 = 0; i2 < c_loop_ub; i2++) {
      c_z[i2] = b_z[i1 + i2];
    }
    c_loop_ub = k - i3;
    zcurrent.set_size(1, c_loop_ub);
    for (i1 = 0; i1 < c_loop_ub; i1++) {
      zcurrent[i1] = dz[i3 + i1];
    }
    b_l.set_size(1, b_loop_ub);
    for (i1 = 0; i1 < b_loop_ub; i1++) {
      b_l[i1] = l[i1];
    }
    b_loop_ub = i5 - i4;
    c_l.set_size(1, b_loop_ub);
    for (i1 = 0; i1 < b_loop_ub; i1++) {
      c_l[i1] = l[i4 + i1];
    }
    b_loop_ub = i7 - i6;
    d_l.set_size(1, b_loop_ub);
    for (i1 = 0; i1 < b_loop_ub; i1++) {
      d_l[i1] = l[i6 + i1];
    }
    alpha.set_size(1, nx);
    for (i1 = 0; i1 < nx; i1++) {
      alpha[i1] = b_alpha[i1];
    }
    b_loop_ub = i9 - i8;
    l.set_size(1, b_loop_ub);
    for (i1 = 0; i1 < b_loop_ub; i1++) {
      l[i1] = b_alpha[i8 + i1];
    }
    midcurve(c_z, zcurrent, b_l, c_l, d_l, alpha, l, b_z);
    zcurrent.set_size(1, i);
    for (i1 = 0; i1 < loop_ub; i1++) {
      zcurrent[i1].re = 0.0;
      zcurrent[i1].im = 0.0;
    }
    if (1.0 > m) {
      b_loop_ub = -1;
    } else {
      b_loop_ub = static_cast<int>(m) - 1;
    }
    if (1.0 > mnew_tmp) {
      i1 = 1;
    } else {
      i1 = 2;
    }
    for (i2 = 0; i2 <= b_loop_ub; i2++) {
      zcurrent[i1 * i2] = Zout[i2];
    }
    if (2U > (static_cast<unsigned int>(b_z.size(1)) << 1) + 1U) {
      i1 = 0;
      i2 = 1;
    } else {
      i1 = 1;
      i2 = 2;
    }
    b_loop_ub = b_z.size(1);
    for (i3 = 0; i3 < b_loop_ub; i3++) {
      zcurrent[i1 + i2 * i3] = b_z[i3];
    }
    if (1.0 > mnew_tmp) {
      b_loop_ub = -1;
    } else {
      b_loop_ub = static_cast<int>(mnew_tmp) - 1;
    }
    for (i1 = 0; i1 <= b_loop_ub; i1++) {
      Zout[i1] = zcurrent[i1];
    }
    if (1.0 > mnew_tmp) {
      b_loop_ub = 0;
    } else {
      b_loop_ub = static_cast<int>(mnew_tmp);
    }
    zcurrent.set_size(1, b_loop_ub);
    for (i1 = 0; i1 < b_loop_ub; i1++) {
      zcurrent[i1] = Zout[i1];
    }
    d_z = z.reshape(1, varargin_2);
    optimize(zcurrent, d_z, b_z);
    b_loop_ub = b_z.size(1);
    for (i1 = 0; i1 < b_loop_ub; i1++) {
      Zout[i1] = b_z[i1];
    }
    if (1.0 > mnew_tmp) {
      b_loop_ub = 0;
    } else {
      b_loop_ub = static_cast<int>(mnew_tmp);
    }
    zcurrent.set_size(1, b_loop_ub);
    for (i1 = 0; i1 < b_loop_ub; i1++) {
      zcurrent[i1] = Zout[i1];
    }
    d_z = z.reshape(1, varargin_2);
    optimize(zcurrent, d_z, b_z);
    b_loop_ub = b_z.size(1);
    for (i1 = 0; i1 < b_loop_ub; i1++) {
      Zout[i1] = b_z[i1];
    }
    if (1.0 > mnew_tmp) {
      b_loop_ub = 0;
    } else {
      b_loop_ub = static_cast<int>(mnew_tmp);
    }
    zcurrent.set_size(1, b_loop_ub);
    for (i1 = 0; i1 < b_loop_ub; i1++) {
      zcurrent[i1] = Zout[i1];
    }
    d_z = z.reshape(1, varargin_2);
    optimize(zcurrent, d_z, b_z);
    b_loop_ub = b_z.size(1);
    for (i1 = 0; i1 < b_loop_ub; i1++) {
      Zout[i1] = b_z[i1];
    }
    m = mnew_tmp;
  }
  l.set_size(1, Zout.size(1));
  loop_ub = Zout.size(1);
  for (i = 0; i < loop_ub; i++) {
    l[i] = Zout[i].re;
  }
  alpha.set_size(1, Zout.size(1));
  loop_ub = Zout.size(1);
  for (i = 0; i < loop_ub; i++) {
    alpha[i] = Zout[i].im;
  }
  packageCodegen(l, alpha, 128.0 * (static_cast<double>(x.size(0)) - 1.0) + 1.0,
                 u, v);
}

} // namespace scenario
} // namespace internal
} // namespace tracking
} // namespace matlabshared
} // namespace coder

//
// File trailer for dclothoidwp.cpp
//
// [EOF]
//
