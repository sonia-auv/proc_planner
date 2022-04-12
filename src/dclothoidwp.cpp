//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: dclothoidwp.cpp
//
// MATLAB Coder version            : 5.4
// C/C++ source code generated on  : 12-Apr-2022 11:44:16
//

// Include Files
#include "dclothoidwp.h"
#include "diff.h"
#include "div.h"
#include "proc_planner_data.h"
#include "proc_planner_rtwutil.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <cmath>
#include <string.h>

// Function Declarations
static void binary_expand_op(coder::array<creal_T, 2U> &in1,
                             const coder::array<creal_T, 2U> &in2, int in3,
                             int in4, int in5);

static void binary_expand_op(coder::array<creal_T, 2U> &in1,
                             const coder::array<creal_T, 2U> &in2, int in3,
                             int in4, const coder::array<creal_T, 2U> &in5,
                             int in6);

static void binary_expand_op(coder::array<creal_T, 2U> &in1,
                             const coder::array<creal_T, 2U> &in2, int in3,
                             int in4, const coder::array<creal_T, 2U> &in5,
                             int in6, int in7);

static void binary_expand_op(coder::array<creal_T, 2U> &in1,
                             const coder::array<creal_T, 2U> &in2, int in3,
                             const coder::array<creal_T, 2U> &in4, int in5,
                             int in6, const coder::array<double, 2U> &in7,
                             int in8, int in9, int in10, int in11, int in12,
                             int in13, int in14,
                             const coder::array<double, 2U> &in15,
                             const coder::array<double, 2U> &in16);

static void binary_expand_op(coder::array<double, 2U> &in1,
                             const coder::array<double, 2U> &in2,
                             const coder::array<double, 2U> &in3);

static void binary_expand_op(coder::array<creal_T, 2U> &in1,
                             const coder::array<creal_T, 2U> &in2,
                             const coder::array<double, 2U> &in4,
                             const coder::array<creal_T, 2U> &in6);

namespace coder {
namespace matlabshared {
namespace tracking {
namespace internal {
namespace scenario {
static void endpointpadding(const ::coder::array<creal_T, 2U> &zcurrent,
                            const creal_T varargin_1[2], creal_T *zleft,
                            creal_T *zright);

static void endpointpadding(const ::coder::array<creal_T, 2U> &zcurrent,
                            const ::coder::array<creal_T, 2U> &zorig,
                            creal_T *zleft, creal_T *zright);

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
static void e_binary_expand_op(coder::array<creal_T, 2U> &in1,
                               const coder::array<creal_T, 2U> &in2, int in3,
                               int in4, int in5);

// Function Definitions
//
// Arguments    : coder::array<creal_T, 2U> &in1
//                const coder::array<creal_T, 2U> &in2
//                int in3
//                int in4
//                int in5
// Return Type  : void
//
static void binary_expand_op(coder::array<creal_T, 2U> &in1,
                             const coder::array<creal_T, 2U> &in2, int in3,
                             int in4, int in5)
{
  int b_in5;
  int loop_ub;
  int stride_1_1;
  if (in5 + 1 == 1) {
    b_in5 = (in4 - in3) + 1;
  } else {
    b_in5 = in5 + 1;
  }
  in1.set_size(1, b_in5);
  b_in5 = ((in4 - in3) + 1 != 1);
  stride_1_1 = (in5 + 1 != 1);
  if (in5 + 1 == 1) {
    loop_ub = (in4 - in3) + 1;
  } else {
    loop_ub = in5 + 1;
  }
  for (int i{0}; i < loop_ub; i++) {
    double b_re_tmp;
    double c_re_tmp;
    double in2_im;
    double in2_re;
    int re_tmp;
    in2_re = in2[in3 + i * b_in5].re;
    in2_im = -in2[in3 + i * b_in5].im;
    re_tmp = i * stride_1_1;
    b_re_tmp = in2[re_tmp].im;
    c_re_tmp = in2[re_tmp].re;
    in1[i].re = in2_re * c_re_tmp - in2_im * b_re_tmp;
    in1[i].im = in2_re * b_re_tmp + in2_im * c_re_tmp;
  }
}

//
// Arguments    : coder::array<creal_T, 2U> &in1
//                const coder::array<creal_T, 2U> &in2
//                int in3
//                int in4
//                const coder::array<creal_T, 2U> &in5
//                int in6
// Return Type  : void
//
static void binary_expand_op(coder::array<creal_T, 2U> &in1,
                             const coder::array<creal_T, 2U> &in2, int in3,
                             int in4, const coder::array<creal_T, 2U> &in5,
                             int in6)
{
  int b_in6;
  int loop_ub;
  int stride_1_1;
  if (in6 + 1 == 1) {
    b_in6 = (in4 - in3) + 1;
  } else {
    b_in6 = in6 + 1;
  }
  in1.set_size(1, b_in6);
  b_in6 = ((in4 - in3) + 1 != 1);
  stride_1_1 = (in6 + 1 != 1);
  if (in6 + 1 == 1) {
    loop_ub = (in4 - in3) + 1;
  } else {
    loop_ub = in6 + 1;
  }
  for (int i{0}; i < loop_ub; i++) {
    double b_re_tmp;
    double c_re_tmp;
    double in2_im;
    double in2_re;
    int re_tmp;
    in2_re = in2[in3 + i * b_in6].re;
    in2_im = -in2[in3 + i * b_in6].im;
    re_tmp = i * stride_1_1;
    b_re_tmp = in5[re_tmp].im;
    c_re_tmp = in5[re_tmp].re;
    in1[i].re = in2_re * c_re_tmp - in2_im * b_re_tmp;
    in1[i].im = in2_re * b_re_tmp + in2_im * c_re_tmp;
  }
}

//
// Arguments    : coder::array<creal_T, 2U> &in1
//                const coder::array<creal_T, 2U> &in2
//                int in3
//                int in4
//                const coder::array<creal_T, 2U> &in5
//                int in6
//                int in7
// Return Type  : void
//
static void binary_expand_op(coder::array<creal_T, 2U> &in1,
                             const coder::array<creal_T, 2U> &in2, int in3,
                             int in4, const coder::array<creal_T, 2U> &in5,
                             int in6, int in7)
{
  int b_in7;
  int loop_ub;
  int stride_1_1;
  if ((in7 - in6) + 1 == 1) {
    b_in7 = (in4 - in3) + 1;
  } else {
    b_in7 = (in7 - in6) + 1;
  }
  in1.set_size(1, b_in7);
  b_in7 = ((in4 - in3) + 1 != 1);
  stride_1_1 = ((in7 - in6) + 1 != 1);
  if ((in7 - in6) + 1 == 1) {
    loop_ub = (in4 - in3) + 1;
  } else {
    loop_ub = (in7 - in6) + 1;
  }
  for (int i{0}; i < loop_ub; i++) {
    double b_re_tmp;
    double c_re_tmp;
    double in2_im;
    double in2_re;
    int re_tmp;
    in2_re = in2[in3 + i * b_in7].re;
    in2_im = -in2[in3 + i * b_in7].im;
    re_tmp = in6 + i * stride_1_1;
    b_re_tmp = in5[re_tmp].im;
    c_re_tmp = in5[re_tmp].re;
    in1[i].re = in2_re * c_re_tmp - in2_im * b_re_tmp;
    in1[i].im = in2_re * b_re_tmp + in2_im * c_re_tmp;
  }
}

//
// Arguments    : coder::array<creal_T, 2U> &in1
//                const coder::array<creal_T, 2U> &in2
//                int in3
//                const coder::array<creal_T, 2U> &in4
//                int in5
//                int in6
//                const coder::array<double, 2U> &in7
//                int in8
//                int in9
//                int in10
//                int in11
//                int in12
//                int in13
//                int in14
//                const coder::array<double, 2U> &in15
//                const coder::array<double, 2U> &in16
// Return Type  : void
//
static void binary_expand_op(coder::array<creal_T, 2U> &in1,
                             const coder::array<creal_T, 2U> &in2, int in3,
                             const coder::array<creal_T, 2U> &in4, int in5,
                             int in6, const coder::array<double, 2U> &in7,
                             int in8, int in9, int in10, int in11, int in12,
                             int in13, int in14,
                             const coder::array<double, 2U> &in15,
                             const coder::array<double, 2U> &in16)
{
  coder::array<creal_T, 2U> b_in2;
  coder::array<creal_T, 2U> b_in4;
  coder::array<double, 2U> b_in7;
  coder::array<double, 2U> c_in7;
  coder::array<double, 2U> d_in7;
  int loop_ub;
  int stride_0_1;
  int stride_1_1;
  b_in2.set_size(1, in3 + 1);
  for (int i{0}; i <= in3; i++) {
    b_in2[i] = in2[i];
  }
  loop_ub = in6 - in5;
  b_in4.set_size(1, loop_ub + 1);
  for (int i{0}; i <= loop_ub; i++) {
    b_in4[i] = in4[in5 + i];
  }
  b_in7.set_size(1, in8 + 1);
  for (int i{0}; i <= in8; i++) {
    b_in7[i] = in7[i];
  }
  if ((in12 - in11) + 1 == 1) {
    loop_ub = (in10 - in9) + 1;
  } else {
    loop_ub = (in12 - in11) + 1;
  }
  c_in7.set_size(1, loop_ub);
  stride_0_1 = ((in10 - in9) + 1 != 1);
  stride_1_1 = ((in12 - in11) + 1 != 1);
  if ((in12 - in11) + 1 == 1) {
    loop_ub = (in10 - in9) + 1;
  } else {
    loop_ub = (in12 - in11) + 1;
  }
  for (int i{0}; i < loop_ub; i++) {
    c_in7[i] = in7[in9 + i * stride_0_1] + in7[in11 + i * stride_1_1];
  }
  loop_ub = in14 - in13;
  d_in7.set_size(1, loop_ub + 1);
  for (int i{0}; i <= loop_ub; i++) {
    d_in7[i] = in7[in13 + i];
  }
  coder::matlabshared::tracking::internal::scenario::midcurve(
      b_in2, b_in4, b_in7, c_in7, d_in7, in15, in16, in1);
}

//
// Arguments    : coder::array<double, 2U> &in1
//                const coder::array<double, 2U> &in2
//                const coder::array<double, 2U> &in3
// Return Type  : void
//
static void binary_expand_op(coder::array<double, 2U> &in1,
                             const coder::array<double, 2U> &in2,
                             const coder::array<double, 2U> &in3)
{
  int i;
  int loop_ub;
  int stride_0_1;
  int stride_1_1;
  if (in3.size(1) == 1) {
    i = in2.size(1);
  } else {
    i = in3.size(1);
  }
  in1.set_size(1, i);
  stride_0_1 = (in2.size(1) != 1);
  stride_1_1 = (in3.size(1) != 1);
  if (in3.size(1) == 1) {
    loop_ub = in2.size(1);
  } else {
    loop_ub = in3.size(1);
  }
  for (i = 0; i < loop_ub; i++) {
    in1[i] = 2.0 * in2[i * stride_0_1] + in3[i * stride_1_1];
  }
}

//
// Arguments    : coder::array<creal_T, 2U> &in1
//                const coder::array<creal_T, 2U> &in2
//                const coder::array<double, 2U> &in4
//                const coder::array<creal_T, 2U> &in6
// Return Type  : void
//
static void binary_expand_op(coder::array<creal_T, 2U> &in1,
                             const coder::array<creal_T, 2U> &in2,
                             const coder::array<double, 2U> &in4,
                             const coder::array<creal_T, 2U> &in6)
{
  int i;
  int loop_ub;
  int stride_0_1;
  int stride_1_1;
  int stride_2_1;
  if (in6.size(1) == 1) {
    i = in4.size(1);
  } else {
    i = in6.size(1);
  }
  if (i == 1) {
    i = in2.size(1);
  } else if (in6.size(1) == 1) {
    i = in4.size(1);
  } else {
    i = in6.size(1);
  }
  in1.set_size(1, i);
  stride_0_1 = (in2.size(1) != 1);
  stride_1_1 = (in4.size(1) != 1);
  stride_2_1 = (in6.size(1) != 1);
  if (in6.size(1) == 1) {
    i = in4.size(1);
  } else {
    i = in6.size(1);
  }
  if (i == 1) {
    loop_ub = in2.size(1);
  } else if (in6.size(1) == 1) {
    loop_ub = in4.size(1);
  } else {
    loop_ub = in6.size(1);
  }
  for (i = 0; i < loop_ub; i++) {
    double b_in3_re;
    double c_in3_re_tmp;
    double d_in3_re_tmp;
    double in3_re;
    double in3_re_tmp;
    int b_in3_re_tmp;
    in3_re_tmp = in4[i * stride_1_1];
    in3_re = 0.0 * in3_re_tmp + 1.0;
    b_in3_re_tmp = i * stride_2_1;
    c_in3_re_tmp = in6[b_in3_re_tmp].im;
    d_in3_re_tmp = in6[b_in3_re_tmp].re;
    b_in3_re = in3_re * d_in3_re_tmp - in3_re_tmp * c_in3_re_tmp;
    in3_re_tmp = in3_re * c_in3_re_tmp + in3_re_tmp * d_in3_re_tmp;
    if (in3_re_tmp == 0.0) {
      in3_re = b_in3_re / 2.0;
      in3_re_tmp = 0.0;
    } else if (b_in3_re == 0.0) {
      in3_re = 0.0;
      in3_re_tmp /= 2.0;
    } else {
      in3_re = b_in3_re / 2.0;
      in3_re_tmp /= 2.0;
    }
    in1[i].re = in2[i * stride_0_1].re + in3_re;
    in1[i].im = in2[i * stride_0_1].im + in3_re_tmp;
  }
}

//
// Arguments    : const ::coder::array<creal_T, 2U> &zcurrent
//                const creal_T varargin_1[2]
//                creal_T *zleft
//                creal_T *zright
// Return Type  : void
//
namespace coder {
namespace matlabshared {
namespace tracking {
namespace internal {
namespace scenario {
static void endpointpadding(const ::coder::array<creal_T, 2U> &zcurrent,
                            const creal_T varargin_1[2], creal_T *zleft,
                            creal_T *zright)
{
  if (std::isnan(varargin_1[0].re) || std::isnan(varargin_1[0].im)) {
    zleft->re = zcurrent[0].re + 100.0 * (zcurrent[0].re - zcurrent[1].re);
    zleft->im = zcurrent[0].im + 100.0 * (zcurrent[0].im - zcurrent[1].im);
  } else {
    zleft->re = rtNaN;
    zleft->im = 0.0;
  }
  if (std::isnan(varargin_1[1].re) || std::isnan(varargin_1[1].im)) {
    zright->re = zcurrent[zcurrent.size(1) - 1].re +
                 100.0 * (zcurrent[zcurrent.size(1) - 1].re -
                          zcurrent[zcurrent.size(1) - 2].re);
    zright->im = zcurrent[zcurrent.size(1) - 1].im +
                 100.0 * (zcurrent[zcurrent.size(1) - 1].im -
                          zcurrent[zcurrent.size(1) - 2].im);
  } else {
    zright->re = rtNaN;
    zright->im = 0.0;
  }
}

//
// Arguments    : const ::coder::array<creal_T, 2U> &zcurrent
//                const ::coder::array<creal_T, 2U> &zorig
//                creal_T *zleft
//                creal_T *zright
// Return Type  : void
//
static void endpointpadding(const ::coder::array<creal_T, 2U> &zcurrent,
                            const ::coder::array<creal_T, 2U> &zorig,
                            creal_T *zleft, creal_T *zright)
{
  if ((zorig[0].re == zorig[zorig.size(1) - 1].re) &&
      (zorig[0].im == zorig[zorig.size(1) - 1].im) && (zorig.size(1) > 2)) {
    *zleft = zcurrent[zcurrent.size(1) - 2];
    *zright = zcurrent[1];
  } else {
    zleft->re = zcurrent[0].re + 100.0 * (zcurrent[0].re - zcurrent[1].re);
    zleft->im = zcurrent[0].im + 100.0 * (zcurrent[0].im - zcurrent[1].im);
    zright->re = zcurrent[zcurrent.size(1) - 1].re +
                 100.0 * (zcurrent[zcurrent.size(1) - 1].re -
                          zcurrent[zcurrent.size(1) - 2].re);
    zright->im = zcurrent[zcurrent.size(1) - 1].im +
                 100.0 * (zcurrent[zcurrent.size(1) - 1].im -
                          zcurrent[zcurrent.size(1) - 2].im);
  }
}

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
  int i;
  int i1;
  int i2;
  int i3;
  int i4;
  int i5;
  int k;
  int nx;
  if (Lde.size(1) == Lbd.size(1)) {
    a.set_size(1, Lde.size(1));
    nx = Lde.size(1);
    for (k = 0; k < nx; k++) {
      a[k] = 2.0 * Lde[k] + Lbd[k];
    }
  } else {
    binary_expand_op(a, Lde, Lbd);
  }
  if (Lab.size(1) == Lbd.size(1)) {
    b.set_size(1, Lab.size(1));
    nx = Lab.size(1);
    for (k = 0; k < nx; k++) {
      b[k] = 2.0 * Lab[k] + Lbd[k];
    }
  } else {
    binary_expand_op(b, Lab, Lbd);
  }
  if (alpha.size(1) == 1) {
    nx = a.size(1);
  } else {
    nx = alpha.size(1);
  }
  if (beta.size(1) == 1) {
    k = b.size(1);
  } else {
    k = beta.size(1);
  }
  if (alpha.size(1) == 1) {
    i = a.size(1);
  } else {
    i = alpha.size(1);
  }
  if (i == 1) {
    if (beta.size(1) == 1) {
      i = b.size(1);
    } else {
      i = beta.size(1);
    }
  } else if (alpha.size(1) == 1) {
    i = a.size(1);
  } else {
    i = alpha.size(1);
  }
  if (a.size(1) == 1) {
    i1 = b.size(1);
  } else {
    i1 = a.size(1);
  }
  if (a.size(1) == 1) {
    i2 = b.size(1);
  } else {
    i2 = a.size(1);
  }
  if (Lbd.size(1) == 1) {
    if (a.size(1) == 1) {
      i3 = b.size(1);
    } else {
      i3 = a.size(1);
    }
  } else {
    i3 = Lbd.size(1);
  }
  if (alpha.size(1) == 1) {
    i4 = a.size(1);
  } else {
    i4 = alpha.size(1);
  }
  if (Lbd.size(1) == 1) {
    if (i4 == 1) {
      if (beta.size(1) == 1) {
        i4 = b.size(1);
      } else {
        i4 = beta.size(1);
      }
    } else if (alpha.size(1) == 1) {
      i4 = a.size(1);
    } else {
      i4 = alpha.size(1);
    }
  } else {
    i4 = Lbd.size(1);
  }
  if (a.size(1) == 1) {
    i5 = b.size(1);
  } else {
    i5 = a.size(1);
  }
  if (i5 == 1) {
    if (Lbd.size(1) == 1) {
      if (a.size(1) == 1) {
        i5 = b.size(1);
      } else {
        i5 = a.size(1);
      }
    } else {
      i5 = Lbd.size(1);
    }
  } else if (a.size(1) == 1) {
    i5 = b.size(1);
  } else {
    i5 = a.size(1);
  }
  if ((alpha.size(1) == a.size(1)) && (beta.size(1) == b.size(1)) &&
      (nx == k) && (Lbd.size(1) == i) && (a.size(1) == b.size(1)) &&
      (a.size(1) == b.size(1)) && (Lbd.size(1) == i1) && (i2 == i3) &&
      (i4 == i5)) {
    nx = Lbd.size(1) - 1;
    a.set_size(1, Lbd.size(1));
    for (k = 0; k <= nx; k++) {
      re = a[k];
      im = Lbd[k];
      b_re = b[k];
      re = im * (alpha[k] * re + beta[k] * b_re) /
           (2.0 * (re * b_re) + im * (re + b_re));
      a[k] = re;
    }
  } else {
    binary_expand_op(a, Lbd, alpha, beta, b);
  }
  nx = a.size(1);
  for (k = 0; k < nx; k++) {
    a[k] = std::tan(a[k]);
  }
  if (a.size(1) == 1) {
    nx = Vbd.size(1);
  } else {
    nx = a.size(1);
  }
  if ((a.size(1) == Vbd.size(1)) && (Pb.size(1) == nx)) {
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
  } else {
    binary_expand_op(Pc, Pb, a, Vbd);
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
  creal_T zleft;
  creal_T zright;
  double b_d1;
  double d;
  double d2_im;
  double d2_re;
  int b_loop_ub;
  int i;
  int i1;
  int i2;
  int i3;
  int i4;
  int i5;
  int i6;
  int k;
  int loop_ub;
  int nx;
  endpointpadding(zcurrent, varargin_1, &zleft, &zright);
  z.set_size(1, zcurrent.size(1) + 2);
  z[0] = zleft;
  loop_ub = zcurrent.size(1);
  for (i = 0; i < loop_ub; i++) {
    z[i + 1] = zcurrent[i];
  }
  z[zcurrent.size(1) + 1] = zright;
  diff(z, d1);
  nx = d1.size(1);
  l1.set_size(1, d1.size(1));
  for (k = 0; k < nx; k++) {
    l1[k] = rt_hypotd_snf(d1[k].re, d1[k].im);
  }
  if (z.size(1) < 3) {
    i = 0;
    i1 = 0;
  } else {
    i = 2;
    i1 = z.size(1);
  }
  if (z.size(1) - 2 < 1) {
    i2 = 0;
  } else {
    i2 = z.size(1) - 2;
  }
  loop_ub = i1 - i;
  if (loop_ub == i2) {
    d2.set_size(1, loop_ub);
    for (i1 = 0; i1 < loop_ub; i1++) {
      i2 = i + i1;
      d2[i1].re = z[i2].re - z[i1].re;
      d2[i1].im = z[i2].im - z[i1].im;
    }
  } else {
    e_binary_expand_op(d2, z, i, i1 - 1, i2 - 1);
  }
  if (d2.size(1) - 1 < 2) {
    i = 0;
    i1 = 0;
  } else {
    i = 1;
    i1 = d2.size(1) - 1;
  }
  if (d1.size(1) - 3 < 1) {
    i2 = 0;
  } else {
    i2 = d1.size(1) - 3;
  }
  loop_ub = i1 - i;
  if (loop_ub == i2) {
    z.set_size(1, loop_ub);
    for (i1 = 0; i1 < loop_ub; i1++) {
      nx = i + i1;
      d2_re = d2[nx].re;
      d2_im = -d2[nx].im;
      d = d1[i1].im;
      b_d1 = d1[i1].re;
      z[i1].re = d2_re * b_d1 - d2_im * d;
      z[i1].im = d2_re * d + d2_im * b_d1;
    }
  } else {
    binary_expand_op(z, d2, i, i1 - 1, d1, i2 - 1);
  }
  nx = z.size(1);
  alpha.set_size(1, z.size(1));
  for (k = 0; k < nx; k++) {
    alpha[k] = rt_atan2d_snf(z[k].im, z[k].re);
  }
  if (d1.size(1) < 4) {
    i = 0;
    i1 = 0;
  } else {
    i = 3;
    i1 = d1.size(1);
  }
  if (d2.size(1) - 1 < 2) {
    i2 = 0;
    i3 = 0;
  } else {
    i2 = 1;
    i3 = d2.size(1) - 1;
  }
  loop_ub = i1 - i;
  if (loop_ub == i3 - i2) {
    z.set_size(1, loop_ub);
    for (i1 = 0; i1 < loop_ub; i1++) {
      nx = i + i1;
      d2_re = d1[nx].re;
      d2_im = -d1[nx].im;
      i3 = i2 + i1;
      d = d2[i3].im;
      b_d1 = d2[i3].re;
      z[i1].re = d2_re * b_d1 - d2_im * d;
      z[i1].im = d2_re * d + d2_im * b_d1;
    }
  } else {
    binary_expand_op(z, d1, i, i1 - 1, d2, i2, i3 - 1);
  }
  nx = z.size(1);
  beta.set_size(1, z.size(1));
  for (k = 0; k < nx; k++) {
    beta[k] = rt_atan2d_snf(z[k].im, z[k].re);
  }
  if ((!std::isnan(varargin_1[0].re)) && (!std::isnan(varargin_1[0].im))) {
    l1[0] = 0.0;
    alpha[0] = rt_atan2d_snf(
        d2[1].re * varargin_1[0].im + -d2[1].im * varargin_1[0].re,
        d2[1].re * varargin_1[0].re - -d2[1].im * varargin_1[0].im);
  }
  if ((!std::isnan(varargin_1[1].re)) && (!std::isnan(varargin_1[1].im))) {
    l1[l1.size(1) - 1] = 0.0;
    beta[beta.size(1) - 1] =
        rt_atan2d_snf(varargin_1[1].re * d2[d2.size(1) - 2].im +
                          -varargin_1[1].im * d2[d2.size(1) - 2].re,
                      varargin_1[1].re * d2[d2.size(1) - 2].re -
                          -varargin_1[1].im * d2[d2.size(1) - 2].im);
  }
  if (zcurrent.size(1) - 2 < 1) {
    loop_ub = -1;
  } else {
    loop_ub = zcurrent.size(1) - 3;
  }
  if (d2.size(1) - 1 < 2) {
    i = 0;
    i1 = -1;
  } else {
    i = 1;
    i1 = d2.size(1) - 2;
  }
  if (l1.size(1) - 3 < 1) {
    nx = -1;
  } else {
    nx = l1.size(1) - 4;
  }
  if (l1.size(1) - 2 < 2) {
    i2 = 0;
    i3 = 0;
  } else {
    i2 = 1;
    i3 = l1.size(1) - 2;
  }
  if (l1.size(1) - 1 < 3) {
    k = 0;
    i4 = 0;
  } else {
    k = 2;
    i4 = l1.size(1) - 1;
  }
  if (l1.size(1) < 4) {
    i5 = 0;
    i6 = 0;
  } else {
    i5 = 3;
    i6 = l1.size(1);
  }
  b_loop_ub = i3 - i2;
  if (b_loop_ub == i4 - k) {
    d1.set_size(1, loop_ub + 1);
    for (i3 = 0; i3 <= loop_ub; i3++) {
      d1[i3] = zcurrent[i3];
    }
    loop_ub = i1 - i;
    b_d2.set_size(1, loop_ub + 1);
    for (i1 = 0; i1 <= loop_ub; i1++) {
      b_d2[i1] = d2[i + i1];
    }
    b_l1.set_size(1, nx + 1);
    for (i = 0; i <= nx; i++) {
      b_l1[i] = l1[i];
    }
    c_l1.set_size(1, b_loop_ub);
    for (i = 0; i < b_loop_ub; i++) {
      c_l1[i] = l1[i2 + i] + l1[k + i];
    }
    loop_ub = i6 - i5;
    d_l1.set_size(1, loop_ub);
    for (i = 0; i < loop_ub; i++) {
      d_l1[i] = l1[i5 + i];
    }
    midcurve(d1, b_d2, b_l1, c_l1, d_l1, alpha, beta, z);
  } else {
    binary_expand_op(z, zcurrent, loop_ub, d2, i, i1, l1, nx, i2, i3 - 1, k,
                     i4 - 1, i5, i6 - 1, alpha, beta);
  }
  Zout.set_size(1, z.size(1) + 2);
  Zout[0] = zorig[0];
  loop_ub = z.size(1);
  for (i = 0; i < loop_ub; i++) {
    Zout[i + 1] = z[i];
  }
  Zout[z.size(1) + 1] = zorig[zorig.size(1) - 1];
  d = static_cast<double>(zcurrent.size(1) - zorig.size(1)) /
          (static_cast<double>(zorig.size(1)) - 1.0) +
      1.0;
  if ((d == 0.0) || (d < 0.0)) {
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
  array<double, 2U> b_l1;
  array<double, 2U> b_y;
  array<double, 2U> c_l1;
  array<double, 2U> d_l1;
  array<double, 2U> l1;
  array<double, 2U> y;
  creal_T zleft;
  creal_T zright;
  double b_d1;
  double d;
  double d2_im;
  double d2_re;
  int b_loop_ub;
  int i;
  int i1;
  int i10;
  int i11;
  int i12;
  int i13;
  int i2;
  int i3;
  int i4;
  int i5;
  int i6;
  int i7;
  int i8;
  int i9;
  int k;
  int loop_ub;
  int nx;
  endpointpadding(zcurrent, zorig, &zleft, &zright);
  z.set_size(1, zcurrent.size(1) + 2);
  z[0] = zleft;
  loop_ub = zcurrent.size(1);
  for (i = 0; i < loop_ub; i++) {
    z[i + 1] = zcurrent[i];
  }
  z[zcurrent.size(1) + 1] = zright;
  diff(z, d1);
  nx = d1.size(1);
  l1.set_size(1, d1.size(1));
  for (k = 0; k < nx; k++) {
    l1[k] = rt_hypotd_snf(d1[k].re, d1[k].im);
  }
  if (z.size(1) < 3) {
    i = 0;
    i1 = 0;
  } else {
    i = 2;
    i1 = z.size(1);
  }
  if (z.size(1) - 2 < 1) {
    nx = 0;
  } else {
    nx = z.size(1) - 2;
  }
  loop_ub = i1 - i;
  if (loop_ub == nx) {
    d2.set_size(1, loop_ub);
    for (i1 = 0; i1 < loop_ub; i1++) {
      nx = i + i1;
      d2[i1].re = z[nx].re - z[i1].re;
      d2[i1].im = z[nx].im - z[i1].im;
    }
  } else {
    e_binary_expand_op(d2, z, i, i1 - 1, nx - 1);
  }
  if (d2.size(1) - 1 < 2) {
    i = 0;
    i1 = 0;
  } else {
    i = 1;
    i1 = d2.size(1) - 1;
  }
  if (d1.size(1) - 3 < 1) {
    nx = 0;
  } else {
    nx = d1.size(1) - 3;
  }
  if (d1.size(1) < 4) {
    i2 = 0;
    i3 = 0;
  } else {
    i2 = 3;
    i3 = d1.size(1);
  }
  if (d2.size(1) - 1 < 2) {
    i4 = 0;
    i5 = 0;
  } else {
    i4 = 1;
    i5 = d2.size(1) - 1;
  }
  if (zcurrent.size(1) - 2 < 1) {
    loop_ub = -1;
  } else {
    loop_ub = zcurrent.size(1) - 3;
  }
  if (d2.size(1) - 1 < 2) {
    i6 = 0;
    i7 = -1;
  } else {
    i6 = 1;
    i7 = d2.size(1) - 2;
  }
  if (l1.size(1) - 3 < 1) {
    b_loop_ub = -1;
  } else {
    b_loop_ub = l1.size(1) - 4;
  }
  if (l1.size(1) - 2 < 2) {
    i8 = 0;
    i9 = 0;
  } else {
    i8 = 1;
    i9 = l1.size(1) - 2;
  }
  if (l1.size(1) - 1 < 3) {
    i10 = 0;
    i11 = 0;
  } else {
    i10 = 2;
    i11 = l1.size(1) - 1;
  }
  if (l1.size(1) < 4) {
    i12 = 0;
    i13 = 0;
  } else {
    i12 = 3;
    i13 = l1.size(1);
  }
  k = i1 - i;
  if (k == nx) {
    z.set_size(1, k);
    for (i1 = 0; i1 < k; i1++) {
      nx = i + i1;
      d2_re = d2[nx].re;
      d2_im = -d2[nx].im;
      d = d1[i1].im;
      b_d1 = d1[i1].re;
      z[i1].re = d2_re * b_d1 - d2_im * d;
      z[i1].im = d2_re * d + d2_im * b_d1;
    }
  } else {
    binary_expand_op(z, d2, i, i1 - 1, d1, nx - 1);
  }
  nx = z.size(1);
  y.set_size(1, z.size(1));
  for (k = 0; k < nx; k++) {
    y[k] = rt_atan2d_snf(z[k].im, z[k].re);
  }
  k = i3 - i2;
  if (k == i5 - i4) {
    z.set_size(1, k);
    for (i = 0; i < k; i++) {
      nx = i2 + i;
      d2_re = d1[nx].re;
      d2_im = -d1[nx].im;
      i1 = i4 + i;
      d = d2[i1].im;
      b_d1 = d2[i1].re;
      z[i].re = d2_re * b_d1 - d2_im * d;
      z[i].im = d2_re * d + d2_im * b_d1;
    }
  } else {
    binary_expand_op(z, d1, i2, i3 - 1, d2, i4, i5 - 1);
  }
  nx = z.size(1);
  b_y.set_size(1, z.size(1));
  for (k = 0; k < nx; k++) {
    b_y[k] = rt_atan2d_snf(z[k].im, z[k].re);
  }
  k = i9 - i8;
  if (k == i11 - i10) {
    d1.set_size(1, loop_ub + 1);
    for (i = 0; i <= loop_ub; i++) {
      d1[i] = zcurrent[i];
    }
    loop_ub = i7 - i6;
    b_d2.set_size(1, loop_ub + 1);
    for (i = 0; i <= loop_ub; i++) {
      b_d2[i] = d2[i6 + i];
    }
    b_l1.set_size(1, b_loop_ub + 1);
    for (i = 0; i <= b_loop_ub; i++) {
      b_l1[i] = l1[i];
    }
    c_l1.set_size(1, k);
    for (i = 0; i < k; i++) {
      c_l1[i] = l1[i8 + i] + l1[i10 + i];
    }
    loop_ub = i13 - i12;
    d_l1.set_size(1, loop_ub);
    for (i = 0; i < loop_ub; i++) {
      d_l1[i] = l1[i12 + i];
    }
    midcurve(d1, b_d2, b_l1, c_l1, d_l1, y, b_y, z);
  } else {
    binary_expand_op(z, zcurrent, loop_ub, d2, i6, i7, l1, b_loop_ub, i8,
                     i9 - 1, i10, i11 - 1, i12, i13 - 1, y, b_y);
  }
  Zout.set_size(1, z.size(1) + 2);
  Zout[0] = zorig[0];
  loop_ub = z.size(1);
  for (i = 0; i < loop_ub; i++) {
    Zout[i + 1] = z[i];
  }
  Zout[z.size(1) + 1] = zorig[zorig.size(1) - 1];
  d = static_cast<double>(zcurrent.size(1) - zorig.size(1)) /
          (static_cast<double>(zorig.size(1)) - 1.0) +
      1.0;
  if ((d == 0.0) || (d < 0.0)) {
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
  int loop_ub_tmp;
  loop_ub_tmp = static_cast<int>(n);
  u.set_size(loop_ub_tmp);
  v.set_size(loop_ub_tmp);
  for (int i{0}; i < loop_ub_tmp; i++) {
    u[i] = 0.0;
    v[i] = 0.0;
  }
  if (n < 1.0) {
    loop_ub_tmp = 0;
  } else {
    loop_ub_tmp = static_cast<int>(n);
  }
  for (int i{0}; i < loop_ub_tmp; i++) {
    u[i] = r[i];
  }
  if (n < 1.0) {
    loop_ub_tmp = 0;
  } else {
    loop_ub_tmp = static_cast<int>(n);
  }
  for (int i{0}; i < loop_ub_tmp; i++) {
    v[i] = s[i];
  }
}

//
// Arguments    : coder::array<creal_T, 2U> &in1
//                const coder::array<creal_T, 2U> &in2
//                int in3
//                int in4
//                int in5
// Return Type  : void
//
} // namespace scenario
} // namespace internal
} // namespace tracking
} // namespace matlabshared
} // namespace coder
static void e_binary_expand_op(coder::array<creal_T, 2U> &in1,
                               const coder::array<creal_T, 2U> &in2, int in3,
                               int in4, int in5)
{
  int b_in5;
  int loop_ub;
  int stride_1_1;
  if (in5 + 1 == 1) {
    b_in5 = (in4 - in3) + 1;
  } else {
    b_in5 = in5 + 1;
  }
  in1.set_size(1, b_in5);
  b_in5 = ((in4 - in3) + 1 != 1);
  stride_1_1 = (in5 + 1 != 1);
  if (in5 + 1 == 1) {
    loop_ub = (in4 - in3) + 1;
  } else {
    loop_ub = in5 + 1;
  }
  for (int i{0}; i < loop_ub; i++) {
    int i1;
    i1 = i * stride_1_1;
    in1[i].re = in2[in3 + i * b_in5].re - in2[i1].re;
    in1[i].im = in2[in3 + i * b_in5].im - in2[i1].im;
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
namespace coder {
namespace matlabshared {
namespace tracking {
namespace internal {
namespace scenario {
void dclothoidwp(const ::coder::array<double, 1U> &x,
                 const ::coder::array<double, 1U> &y,
                 const double varargin_1[2], const double varargin_2[2],
                 ::coder::array<double, 1U> &u, ::coder::array<double, 1U> &v)
{
  array<creal_T, 2U> Zout;
  array<creal_T, 2U> b_dz;
  array<creal_T, 2U> b_x;
  array<creal_T, 2U> b_z;
  array<creal_T, 2U> dz;
  array<creal_T, 1U> z;
  array<double, 2U> alpha;
  array<double, 2U> b_alpha;
  array<double, 2U> b_l;
  array<double, 2U> c_l;
  array<double, 2U> d_l;
  array<double, 2U> l;
  creal_T t0_f1[2];
  creal_T zleft;
  creal_T zright;
  double m;
  double nmax;
  int b_loop_ub;
  int b_varargin_2;
  int i;
  int loop_ub;
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
  i = static_cast<int>(nmax);
  for (int b_i{0}; b_i < 7; b_i++) {
    array<creal_T, 2U> c_z;
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
    nmax = 2.0 * m - 1.0;
    if (m < 1.0) {
      b_loop_ub = 0;
    } else {
      b_loop_ub = static_cast<int>(m);
    }
    b_z.set_size(1, b_loop_ub);
    for (i1 = 0; i1 < b_loop_ub; i1++) {
      b_z[i1] = Zout[i1];
    }
    endpointpadding(b_z, t0_f1, &zleft, &zright);
    if (m < 1.0) {
      b_loop_ub = 0;
    } else {
      b_loop_ub = static_cast<int>(m);
    }
    b_z.set_size(1, b_loop_ub + 2);
    b_z[0] = zleft;
    for (i1 = 0; i1 < b_loop_ub; i1++) {
      b_z[i1 + 1] = Zout[i1];
    }
    b_z[b_loop_ub + 1] = zright;
    diff(b_z, dz);
    nx = dz.size(1);
    l.set_size(1, dz.size(1));
    for (k = 0; k < nx; k++) {
      l[k] = rt_hypotd_snf(dz[k].re, dz[k].im);
    }
    if (dz.size(1) < 2) {
      i1 = 0;
      i2 = 0;
    } else {
      i1 = 1;
      i2 = dz.size(1);
    }
    if (dz.size(1) - 1 < 1) {
      i3 = 0;
    } else {
      i3 = dz.size(1) - 1;
    }
    b_loop_ub = i2 - i1;
    if (b_loop_ub == i3) {
      b_x.set_size(1, b_loop_ub);
      for (i2 = 0; i2 < b_loop_ub; i2++) {
        double d;
        double d1;
        double dz_im;
        double dz_re;
        nx = i1 + i2;
        dz_re = dz[nx].re;
        dz_im = -dz[nx].im;
        d = dz[i2].im;
        d1 = dz[i2].re;
        b_x[i2].re = dz_re * d1 - dz_im * d;
        b_x[i2].im = dz_re * d + dz_im * d1;
      }
    } else {
      binary_expand_op(b_x, dz, i1, i2 - 1, i3 - 1);
    }
    nx = b_x.size(1);
    b_alpha.set_size(1, b_x.size(1));
    for (k = 0; k < nx; k++) {
      b_alpha[k] = rt_atan2d_snf(b_x[k].im, b_x[k].re);
    }
    if ((!std::isnan(t0_f1[0].re)) && (!std::isnan(t0_f1[0].im))) {
      l[0] = 0.0;
      b_alpha[0] =
          rt_atan2d_snf(dz[1].re * t0_f1[0].im + -dz[1].im * t0_f1[0].re,
                        dz[1].re * t0_f1[0].re - -dz[1].im * t0_f1[0].im);
    }
    if ((!std::isnan(t0_f1[1].re)) && (!std::isnan(t0_f1[1].im))) {
      l[l.size(1) - 1] = 0.0;
      b_alpha[b_alpha.size(1) - 1] =
          rt_atan2d_snf(t0_f1[1].re * dz[dz.size(1) - 2].im +
                            -t0_f1[1].im * dz[dz.size(1) - 2].re,
                        t0_f1[1].re * dz[dz.size(1) - 2].re -
                            -t0_f1[1].im * dz[dz.size(1) - 2].im);
    }
    if (b_z.size(1) - 2 < 2) {
      i1 = 0;
      i2 = 0;
    } else {
      i1 = 1;
      i2 = b_z.size(1) - 2;
    }
    if (dz.size(1) - 1 < 2) {
      i3 = 0;
      nx = 0;
    } else {
      i3 = 1;
      nx = dz.size(1) - 1;
    }
    if (l.size(1) - 2 < 1) {
      b_loop_ub = 0;
    } else {
      b_loop_ub = l.size(1) - 2;
    }
    if (l.size(1) - 1 < 2) {
      k = 0;
      i4 = 0;
    } else {
      k = 1;
      i4 = l.size(1) - 1;
    }
    if (l.size(1) < 3) {
      i5 = 0;
      i6 = 0;
    } else {
      i5 = 2;
      i6 = l.size(1);
    }
    if (b_alpha.size(1) - 1 < 1) {
      c_loop_ub = 0;
    } else {
      c_loop_ub = b_alpha.size(1) - 1;
    }
    if (b_alpha.size(1) < 2) {
      i7 = 0;
      i8 = 0;
    } else {
      i7 = 1;
      i8 = b_alpha.size(1);
    }
    d_loop_ub = i2 - i1;
    b_x.set_size(1, d_loop_ub);
    for (i2 = 0; i2 < d_loop_ub; i2++) {
      b_x[i2] = b_z[i1 + i2];
    }
    d_loop_ub = nx - i3;
    b_dz.set_size(1, d_loop_ub);
    for (i1 = 0; i1 < d_loop_ub; i1++) {
      b_dz[i1] = dz[i3 + i1];
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
    midcurve(b_x, b_dz, b_l, c_l, d_l, alpha, l, b_z);
    b_x.set_size(1, i);
    for (i1 = 0; i1 < loop_ub; i1++) {
      b_x[i1].re = 0.0;
      b_x[i1].im = 0.0;
    }
    if (m < 1.0) {
      b_loop_ub = 0;
    } else {
      b_loop_ub = static_cast<int>(m);
    }
    if (nmax < 1.0) {
      i1 = 1;
    } else {
      i1 = 2;
    }
    for (i2 = 0; i2 < b_loop_ub; i2++) {
      b_x[i1 * i2] = Zout[i2];
    }
    if ((static_cast<unsigned int>(b_z.size(1)) << 1) + 1U < 2U) {
      i1 = 0;
      i2 = 1;
    } else {
      i1 = 1;
      i2 = 2;
    }
    b_loop_ub = b_z.size(1);
    for (i3 = 0; i3 < b_loop_ub; i3++) {
      b_x[i1 + i2 * i3] = b_z[i3];
    }
    if (nmax < 1.0) {
      b_loop_ub = 0;
    } else {
      b_loop_ub = static_cast<int>(nmax);
    }
    b_x.set_size(b_x.size(0), b_loop_ub);
    if (nmax < 1.0) {
      b_loop_ub = 0;
    } else {
      b_loop_ub = static_cast<int>(nmax);
    }
    for (i1 = 0; i1 < b_loop_ub; i1++) {
      Zout[i1] = b_x[i1];
    }
    if (nmax < 1.0) {
      b_loop_ub = 0;
    } else {
      b_loop_ub = static_cast<int>(nmax);
    }
    b_z.set_size(1, b_loop_ub);
    for (i1 = 0; i1 < b_loop_ub; i1++) {
      b_z[i1] = Zout[i1];
    }
    c_z = z.reshape(1, b_varargin_2);
    optimize(b_z, c_z, t0_f1, b_dz);
    b_loop_ub = b_dz.size(1);
    for (i1 = 0; i1 < b_loop_ub; i1++) {
      Zout[i1] = b_dz[i1];
    }
    if (nmax < 1.0) {
      b_loop_ub = 0;
    } else {
      b_loop_ub = static_cast<int>(nmax);
    }
    b_z.set_size(1, b_loop_ub);
    for (i1 = 0; i1 < b_loop_ub; i1++) {
      b_z[i1] = Zout[i1];
    }
    c_z = z.reshape(1, b_varargin_2);
    optimize(b_z, c_z, t0_f1, b_dz);
    b_loop_ub = b_dz.size(1);
    for (i1 = 0; i1 < b_loop_ub; i1++) {
      Zout[i1] = b_dz[i1];
    }
    if (nmax < 1.0) {
      b_loop_ub = 0;
    } else {
      b_loop_ub = static_cast<int>(nmax);
    }
    b_z.set_size(1, b_loop_ub);
    for (i1 = 0; i1 < b_loop_ub; i1++) {
      b_z[i1] = Zout[i1];
    }
    c_z = z.reshape(1, b_varargin_2);
    optimize(b_z, c_z, t0_f1, b_dz);
    b_loop_ub = b_dz.size(1);
    for (i1 = 0; i1 < b_loop_ub; i1++) {
      Zout[i1] = b_dz[i1];
    }
    m = nmax;
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
  array<creal_T, 2U> b_Zout;
  array<creal_T, 2U> b_x;
  array<creal_T, 2U> b_z;
  array<creal_T, 2U> dz;
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
    array<creal_T, 2U> c_z;
    creal_T zleft;
    creal_T zright;
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
    nmax = 2.0 * m - 1.0;
    if (m < 1.0) {
      b_loop_ub = 0;
      nx = 0;
    } else {
      b_loop_ub = static_cast<int>(m);
      nx = static_cast<int>(m);
    }
    b_Zout.set_size(1, b_loop_ub);
    for (i1 = 0; i1 < b_loop_ub; i1++) {
      b_Zout[i1] = Zout[i1];
    }
    b_z.set_size(1, nx);
    for (i1 = 0; i1 < nx; i1++) {
      b_z[i1] = Zout[i1];
    }
    if ((b_z[0].re == b_z[b_z.size(1) - 1].re) &&
        (b_z[0].im == b_z[b_z.size(1) - 1].im) && (b_z.size(1) > 2)) {
      zleft = b_Zout[b_Zout.size(1) - 2];
      zright = b_Zout[1];
    } else {
      zleft.re = b_Zout[0].re + 100.0 * (b_Zout[0].re - b_Zout[1].re);
      zleft.im = b_Zout[0].im + 100.0 * (b_Zout[0].im - b_Zout[1].im);
      zright.re = b_Zout[b_Zout.size(1) - 1].re +
                  100.0 * (b_Zout[b_Zout.size(1) - 1].re -
                           b_Zout[b_Zout.size(1) - 2].re);
      zright.im = b_Zout[b_Zout.size(1) - 1].im +
                  100.0 * (b_Zout[b_Zout.size(1) - 1].im -
                           b_Zout[b_Zout.size(1) - 2].im);
    }
    if (m < 1.0) {
      b_loop_ub = 0;
    } else {
      b_loop_ub = static_cast<int>(m);
    }
    b_z.set_size(1, b_loop_ub + 2);
    b_z[0] = zleft;
    for (i1 = 0; i1 < b_loop_ub; i1++) {
      b_z[i1 + 1] = Zout[i1];
    }
    b_z[b_loop_ub + 1] = zright;
    diff(b_z, dz);
    nx = dz.size(1);
    l.set_size(1, dz.size(1));
    for (k = 0; k < nx; k++) {
      l[k] = rt_hypotd_snf(dz[k].re, dz[k].im);
    }
    if (dz.size(1) < 2) {
      i1 = 0;
      i2 = 0;
    } else {
      i1 = 1;
      i2 = dz.size(1);
    }
    if (dz.size(1) - 1 < 1) {
      i3 = 0;
    } else {
      i3 = dz.size(1) - 1;
    }
    b_loop_ub = i2 - i1;
    if (b_loop_ub == i3) {
      b_x.set_size(1, b_loop_ub);
      for (i2 = 0; i2 < b_loop_ub; i2++) {
        double d;
        double d1;
        double dz_im;
        double dz_re;
        nx = i1 + i2;
        dz_re = dz[nx].re;
        dz_im = -dz[nx].im;
        d = dz[i2].im;
        d1 = dz[i2].re;
        b_x[i2].re = dz_re * d1 - dz_im * d;
        b_x[i2].im = dz_re * d + dz_im * d1;
      }
    } else {
      binary_expand_op(b_x, dz, i1, i2 - 1, i3 - 1);
    }
    nx = b_x.size(1);
    b_alpha.set_size(1, b_x.size(1));
    for (k = 0; k < nx; k++) {
      b_alpha[k] = rt_atan2d_snf(b_x[k].im, b_x[k].re);
    }
    if (b_z.size(1) - 2 < 2) {
      i1 = 0;
      i2 = 0;
    } else {
      i1 = 1;
      i2 = b_z.size(1) - 2;
    }
    if (dz.size(1) - 1 < 2) {
      i3 = 0;
      k = 0;
    } else {
      i3 = 1;
      k = dz.size(1) - 1;
    }
    if (l.size(1) - 2 < 1) {
      b_loop_ub = 0;
    } else {
      b_loop_ub = l.size(1) - 2;
    }
    if (l.size(1) - 1 < 2) {
      i4 = 0;
      i5 = 0;
    } else {
      i4 = 1;
      i5 = l.size(1) - 1;
    }
    if (l.size(1) < 3) {
      i6 = 0;
      i7 = 0;
    } else {
      i6 = 2;
      i7 = l.size(1);
    }
    if (b_alpha.size(1) - 1 < 1) {
      nx = 0;
    } else {
      nx = b_alpha.size(1) - 1;
    }
    if (b_alpha.size(1) < 2) {
      i8 = 0;
      i9 = 0;
    } else {
      i8 = 1;
      i9 = b_alpha.size(1);
    }
    c_loop_ub = i2 - i1;
    b_x.set_size(1, c_loop_ub);
    for (i2 = 0; i2 < c_loop_ub; i2++) {
      b_x[i2] = b_z[i1 + i2];
    }
    c_loop_ub = k - i3;
    b_Zout.set_size(1, c_loop_ub);
    for (i1 = 0; i1 < c_loop_ub; i1++) {
      b_Zout[i1] = dz[i3 + i1];
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
    midcurve(b_x, b_Zout, b_l, c_l, d_l, alpha, l, b_z);
    b_x.set_size(1, i);
    for (i1 = 0; i1 < loop_ub; i1++) {
      b_x[i1].re = 0.0;
      b_x[i1].im = 0.0;
    }
    if (m < 1.0) {
      b_loop_ub = 0;
    } else {
      b_loop_ub = static_cast<int>(m);
    }
    if (nmax < 1.0) {
      i1 = 1;
    } else {
      i1 = 2;
    }
    for (i2 = 0; i2 < b_loop_ub; i2++) {
      b_x[i1 * i2] = Zout[i2];
    }
    if ((static_cast<unsigned int>(b_z.size(1)) << 1) + 1U < 2U) {
      i1 = 0;
      i2 = 1;
    } else {
      i1 = 1;
      i2 = 2;
    }
    b_loop_ub = b_z.size(1);
    for (i3 = 0; i3 < b_loop_ub; i3++) {
      b_x[i1 + i2 * i3] = b_z[i3];
    }
    if (nmax < 1.0) {
      b_loop_ub = 0;
    } else {
      b_loop_ub = static_cast<int>(nmax);
    }
    b_x.set_size(b_x.size(0), b_loop_ub);
    if (nmax < 1.0) {
      b_loop_ub = 0;
    } else {
      b_loop_ub = static_cast<int>(nmax);
    }
    for (i1 = 0; i1 < b_loop_ub; i1++) {
      Zout[i1] = b_x[i1];
    }
    if (nmax < 1.0) {
      b_loop_ub = 0;
    } else {
      b_loop_ub = static_cast<int>(nmax);
    }
    b_Zout.set_size(1, b_loop_ub);
    for (i1 = 0; i1 < b_loop_ub; i1++) {
      b_Zout[i1] = Zout[i1];
    }
    c_z = z.reshape(1, varargin_2);
    optimize(b_Zout, c_z, b_z);
    b_loop_ub = b_z.size(1);
    for (i1 = 0; i1 < b_loop_ub; i1++) {
      Zout[i1] = b_z[i1];
    }
    if (nmax < 1.0) {
      b_loop_ub = 0;
    } else {
      b_loop_ub = static_cast<int>(nmax);
    }
    b_Zout.set_size(1, b_loop_ub);
    for (i1 = 0; i1 < b_loop_ub; i1++) {
      b_Zout[i1] = Zout[i1];
    }
    c_z = z.reshape(1, varargin_2);
    optimize(b_Zout, c_z, b_z);
    b_loop_ub = b_z.size(1);
    for (i1 = 0; i1 < b_loop_ub; i1++) {
      Zout[i1] = b_z[i1];
    }
    if (nmax < 1.0) {
      b_loop_ub = 0;
    } else {
      b_loop_ub = static_cast<int>(nmax);
    }
    b_Zout.set_size(1, b_loop_ub);
    for (i1 = 0; i1 < b_loop_ub; i1++) {
      b_Zout[i1] = Zout[i1];
    }
    c_z = z.reshape(1, varargin_2);
    optimize(b_Zout, c_z, b_z);
    b_loop_ub = b_z.size(1);
    for (i1 = 0; i1 < b_loop_ub; i1++) {
      Zout[i1] = b_z[i1];
    }
    m = nmax;
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
