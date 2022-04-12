//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: fresnelg2.cpp
//
// MATLAB Coder version            : 5.4
// C/C++ source code generated on  : 12-Apr-2022 11:44:16
//

// Include Files
#include "fresnelg2.h"
#include "fresnel.h"
#include "proc_planner_data.h"
#include "repmat.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <cmath>
#include <string.h>

// Function Declarations
static void binary_expand_op(creal_T *in1, const coder::array<double, 2U> &in3,
                             const coder::array<creal_T, 2U> &in4,
                             const coder::array<creal_T, 2U> &in5,
                             const coder::array<creal_T, 2U> &in6);

static void binary_expand_op(coder::array<creal_T, 1U> &in1,
                             const coder::array<creal_T, 2U> &in2, int in3,
                             int in4);

static void binary_expand_op(coder::array<creal_T, 1U> &in1,
                             const coder::array<creal_T, 2U> &in2, int in3);

static void binary_expand_op(coder::array<creal_T, 1U> &in1,
                             const coder::array<creal_T, 2U> &in2, int in3,
                             const coder::array<creal_T, 2U> &in4, int in5,
                             int in6);

static void binary_expand_op(creal_T *in1, const coder::array<creal_T, 1U> &in3,
                             double in4, const signed char in5[2],
                             const coder::array<creal_T, 2U> &in6);

static void e_binary_expand_op(creal_T *in1,
                               const coder::array<double, 2U> &in3,
                               const coder::array<creal_T, 2U> &in4,
                               const coder::array<creal_T, 2U> &in5,
                               const coder::array<creal_T, 2U> &in6);

// Function Definitions
//
// Arguments    : creal_T *in1
//                const coder::array<double, 2U> &in3
//                const coder::array<creal_T, 2U> &in4
//                const coder::array<creal_T, 2U> &in5
//                const coder::array<creal_T, 2U> &in6
// Return Type  : void
//
static void binary_expand_op(creal_T *in1, const coder::array<double, 2U> &in3,
                             const coder::array<creal_T, 2U> &in4,
                             const coder::array<creal_T, 2U> &in5,
                             const coder::array<creal_T, 2U> &in6)
{
  int aux_0_1;
  int aux_1_1;
  int aux_2_1;
  int aux_3_1;
  int i;
  int loop_ub;
  int stride_0_0;
  int stride_0_1;
  int stride_1_0;
  int stride_1_1;
  int stride_2_0;
  int stride_2_1;
  int stride_3_0;
  int stride_3_1;
  stride_0_0 = (in3.size(0) != 1);
  stride_0_1 = (in3.size(1) != 1);
  stride_1_0 = (in4.size(0) != 1);
  stride_1_1 = (in4.size(1) != 1);
  stride_2_0 = (in5.size(0) != 1);
  stride_2_1 = (in5.size(1) != 1);
  stride_3_0 = (in6.size(0) != 1);
  stride_3_1 = (in6.size(1) != 1);
  aux_0_1 = 0;
  aux_1_1 = 0;
  aux_2_1 = 0;
  aux_3_1 = 0;
  if (in6.size(1) == 1) {
    i = in5.size(1);
  } else {
    i = in6.size(1);
  }
  if (i == 1) {
    if (in4.size(1) == 1) {
      loop_ub = in3.size(1);
    } else {
      loop_ub = in4.size(1);
    }
  } else if (in6.size(1) == 1) {
    loop_ub = in5.size(1);
  } else {
    loop_ub = in6.size(1);
  }
  for (i = 0; i < loop_ub; i++) {
    int b_loop_ub;
    int i1;
    if (in6.size(0) == 1) {
      i1 = in5.size(0);
    } else {
      i1 = in6.size(0);
    }
    if (i1 == 1) {
      if (in4.size(0) == 1) {
        b_loop_ub = in3.size(0);
      } else {
        b_loop_ub = in4.size(0);
      }
    } else if (in6.size(0) == 1) {
      b_loop_ub = in5.size(0);
    } else {
      b_loop_ub = in6.size(0);
    }
    for (i1 = 0; i1 < b_loop_ub; i1++) {
      double in3_im;
      double in3_re;
      double in5_im;
      double in5_re;
      int in3_re_tmp;
      int in5_re_tmp;
      in3_re_tmp = i1 * stride_1_0;
      in3_re = in3[i1 * stride_0_0 + in3.size(0) * aux_0_1] *
               in4[in3_re_tmp + in4.size(0) * aux_1_1].re;
      in3_im = in3[i1 * stride_0_0 + in3.size(0) * aux_0_1] *
               in4[in3_re_tmp + in4.size(0) * aux_1_1].im;
      in3_re_tmp = i1 * stride_2_0;
      in5_re_tmp = i1 * stride_3_0;
      in5_re = in5[in3_re_tmp + in5.size(0) * aux_2_1].re -
               in6[in5_re_tmp + in6.size(0) * aux_3_1].re;
      in5_im = in5[in3_re_tmp + in5.size(0) * aux_2_1].im -
               in6[in5_re_tmp + in6.size(0) * aux_3_1].im;
      in1->re = in3_re * in5_re - in3_im * in5_im;
      in1->im = -(in3_re * in5_im + in3_im * in5_re);
    }
    aux_3_1 += stride_3_1;
    aux_2_1 += stride_2_1;
    aux_1_1 += stride_1_1;
    aux_0_1 += stride_0_1;
  }
}

//
// Arguments    : coder::array<creal_T, 1U> &in1
//                const coder::array<creal_T, 2U> &in2
//                int in3
//                int in4
// Return Type  : void
//
static void binary_expand_op(coder::array<creal_T, 1U> &in1,
                             const coder::array<creal_T, 2U> &in2, int in3,
                             int in4)
{
  coder::array<creal_T, 1U> b_in1;
  int i;
  int loop_ub;
  int stride_0_0;
  int stride_1_0;
  i = in2.size(0);
  if (i == 1) {
    stride_0_0 = in1.size(0);
  } else {
    stride_0_0 = i;
  }
  b_in1.set_size(stride_0_0);
  stride_0_0 = (in1.size(0) != 1);
  stride_1_0 = (i != 1);
  if (i == 1) {
    loop_ub = in1.size(0);
  } else {
    loop_ub = i;
  }
  for (i = 0; i < loop_ub; i++) {
    double ai;
    double in2_im;
    double in2_re;
    int ar_tmp;
    ar_tmp = i * stride_1_0;
    in2_im = in2[ar_tmp + in2.size(0) * in3].re;
    ai = in2[ar_tmp + in2.size(0) * in3].im;
    if (ai == 0.0) {
      in2_re = in2_im / static_cast<double>(in4 + 1);
      in2_im = 0.0;
    } else if (in2_im == 0.0) {
      in2_re = 0.0;
      in2_im = ai / static_cast<double>(in4 + 1);
    } else {
      in2_re = in2_im / static_cast<double>(in4 + 1);
      in2_im = ai / static_cast<double>(in4 + 1);
    }
    ar_tmp = i * stride_0_0;
    b_in1[i].re = in1[ar_tmp].re + in2_re;
    b_in1[i].im = in1[ar_tmp].im + in2_im;
  }
  in1.set_size(b_in1.size(0));
  loop_ub = b_in1.size(0);
  for (i = 0; i < loop_ub; i++) {
    in1[i] = b_in1[i];
  }
}

//
// Arguments    : coder::array<creal_T, 1U> &in1
//                const coder::array<creal_T, 2U> &in2
//                int in3
// Return Type  : void
//
static void binary_expand_op(coder::array<creal_T, 1U> &in1,
                             const coder::array<creal_T, 2U> &in2, int in3)
{
  coder::array<creal_T, 1U> b_in1;
  int i;
  int loop_ub;
  int stride_0_0;
  int stride_1_0;
  i = in2.size(0);
  if (i == 1) {
    stride_0_0 = in1.size(0);
  } else {
    stride_0_0 = i;
  }
  b_in1.set_size(stride_0_0);
  stride_0_0 = (in1.size(0) != 1);
  stride_1_0 = (i != 1);
  if (i == 1) {
    loop_ub = in1.size(0);
  } else {
    loop_ub = i;
  }
  for (i = 0; i < loop_ub; i++) {
    double ai;
    double in2_im;
    double in2_re;
    int ar_tmp;
    ar_tmp = i * stride_1_0;
    in2_im = in2[ar_tmp + in2.size(0) * in3].re;
    ai = in2[ar_tmp + in2.size(0) * in3].im;
    if (ai == 0.0) {
      in2_re = in2_im / ((static_cast<double>(in3) + 1.0) + 1.0);
      in2_im = 0.0;
    } else if (in2_im == 0.0) {
      in2_re = 0.0;
      in2_im = ai / ((static_cast<double>(in3) + 1.0) + 1.0);
    } else {
      in2_re = in2_im / ((static_cast<double>(in3) + 1.0) + 1.0);
      in2_im = ai / ((static_cast<double>(in3) + 1.0) + 1.0);
    }
    ar_tmp = i * stride_0_0;
    b_in1[i].re = in1[ar_tmp].re + in2_re;
    b_in1[i].im = in1[ar_tmp].im + in2_im;
  }
  in1.set_size(b_in1.size(0));
  loop_ub = b_in1.size(0);
  for (i = 0; i < loop_ub; i++) {
    in1[i] = b_in1[i];
  }
}

//
// Arguments    : coder::array<creal_T, 1U> &in1
//                const coder::array<creal_T, 2U> &in2
//                int in3
//                const coder::array<creal_T, 2U> &in4
//                int in5
//                int in6
// Return Type  : void
//
static void binary_expand_op(coder::array<creal_T, 1U> &in1,
                             const coder::array<creal_T, 2U> &in2, int in3,
                             const coder::array<creal_T, 2U> &in4, int in5,
                             int in6)
{
  coder::array<creal_T, 1U> b_in1;
  int b_in2_re_tmp;
  int i;
  int in2_re_tmp;
  int loop_ub;
  int stride_0_0;
  int stride_1_0;
  int stride_2_0;
  i = in2.size(0);
  in2_re_tmp = in4.size(0);
  if (in2_re_tmp == 1) {
    b_in2_re_tmp = i;
  } else {
    b_in2_re_tmp = in2_re_tmp;
  }
  if (b_in2_re_tmp == 1) {
    b_in2_re_tmp = in1.size(0);
  } else if (in2_re_tmp == 1) {
    b_in2_re_tmp = i;
  } else {
    b_in2_re_tmp = in2_re_tmp;
  }
  b_in1.set_size(b_in2_re_tmp);
  stride_0_0 = (in1.size(0) != 1);
  stride_1_0 = (i != 1);
  stride_2_0 = (in2_re_tmp != 1);
  if (in2_re_tmp == 1) {
    b_in2_re_tmp = i;
  } else {
    b_in2_re_tmp = in2_re_tmp;
  }
  if (b_in2_re_tmp == 1) {
    loop_ub = in1.size(0);
  } else if (in2_re_tmp == 1) {
    loop_ub = i;
  } else {
    loop_ub = in2_re_tmp;
  }
  for (i = 0; i < loop_ub; i++) {
    double c_in2_re_tmp;
    double d_in2_re_tmp;
    double e_in2_re_tmp;
    double in2_im;
    double in2_re;
    in2_re_tmp = i * stride_1_0;
    b_in2_re_tmp = i * stride_2_0;
    in2_im = in2[in2_re_tmp + in2.size(0) * in3].re;
    c_in2_re_tmp = in4[b_in2_re_tmp + in4.size(0) * in5].im;
    d_in2_re_tmp = in2[in2_re_tmp + in2.size(0) * in3].im;
    e_in2_re_tmp = in4[b_in2_re_tmp + in4.size(0) * in5].re;
    in2_re = in2_im * e_in2_re_tmp - d_in2_re_tmp * c_in2_re_tmp;
    in2_im = in2_im * c_in2_re_tmp + d_in2_re_tmp * e_in2_re_tmp;
    if (in2_im == 0.0) {
      in2_re /= static_cast<double>(in6 + 2);
      in2_im = 0.0;
    } else if (in2_re == 0.0) {
      in2_re = 0.0;
      in2_im /= static_cast<double>(in6 + 2);
    } else {
      in2_re /= static_cast<double>(in6 + 2);
      in2_im /= static_cast<double>(in6 + 2);
    }
    in2_re_tmp = i * stride_0_0;
    b_in1[i].re = in1[in2_re_tmp].re + in2_re;
    b_in1[i].im = in1[in2_re_tmp].im + in2_im;
  }
  in1.set_size(b_in1.size(0));
  loop_ub = b_in1.size(0);
  for (i = 0; i < loop_ub; i++) {
    in1[i] = b_in1[i];
  }
}

//
// Arguments    : creal_T *in1
//                const coder::array<creal_T, 1U> &in3
//                double in4
//                const signed char in5[2]
//                const coder::array<creal_T, 2U> &in6
// Return Type  : void
//
static void binary_expand_op(creal_T *in1, const coder::array<creal_T, 1U> &in3,
                             double in4, const signed char in5[2],
                             const coder::array<creal_T, 2U> &in6)
{
  int aux_2_1;
  int in3_idx_0;
  int in5_idx_0;
  int in5_idx_1;
  int loop_ub;
  int stride_0_0;
  int stride_2_0;
  int stride_2_1;
  in3_idx_0 = in3.size(0);
  in5_idx_0 = in5[0];
  in5_idx_1 = in5[1];
  stride_0_0 = (in3_idx_0 != 1);
  stride_2_0 = (in6.size(0) != 1);
  stride_2_1 = (in6.size(1) != 1);
  aux_2_1 = 0;
  if (in6.size(1) == 1) {
    if (in5_idx_1 == 1) {
      loop_ub = 1;
    } else {
      loop_ub = in5_idx_1;
    }
  } else {
    loop_ub = in6.size(1);
  }
  for (int i{0}; i < loop_ub; i++) {
    int b_loop_ub;
    if (in6.size(0) == 1) {
      if (in5_idx_0 == 1) {
        b_loop_ub = in3_idx_0;
      } else {
        b_loop_ub = in5_idx_0;
      }
    } else {
      b_loop_ub = in6.size(0);
    }
    for (int i1{0}; i1 < b_loop_ub; i1++) {
      double b_re_tmp;
      double in3_im;
      double in3_re;
      double re_tmp;
      in5_idx_1 = i1 * stride_0_0;
      in3_re = in4 * in3[in5_idx_1].re;
      in3_im = in4 * in3[in5_idx_1].im;
      in5_idx_1 = i1 * stride_2_0;
      re_tmp = in6[in5_idx_1 + in6.size(0) * aux_2_1].im;
      b_re_tmp = in6[in5_idx_1 + in6.size(0) * aux_2_1].re;
      in1->re = in3_re * b_re_tmp - in3_im * re_tmp;
      in1->im = in3_re * re_tmp + in3_im * b_re_tmp;
    }
    aux_2_1 += stride_2_1;
  }
}

//
// Arguments    : creal_T *in1
//                const coder::array<double, 2U> &in3
//                const coder::array<creal_T, 2U> &in4
//                const coder::array<creal_T, 2U> &in5
//                const coder::array<creal_T, 2U> &in6
// Return Type  : void
//
static void e_binary_expand_op(creal_T *in1,
                               const coder::array<double, 2U> &in3,
                               const coder::array<creal_T, 2U> &in4,
                               const coder::array<creal_T, 2U> &in5,
                               const coder::array<creal_T, 2U> &in6)
{
  int aux_0_1;
  int aux_1_1;
  int aux_2_1;
  int aux_3_1;
  int i;
  int loop_ub;
  int stride_0_0;
  int stride_0_1;
  int stride_1_0;
  int stride_1_1;
  int stride_2_0;
  int stride_2_1;
  int stride_3_0;
  int stride_3_1;
  stride_0_0 = (in3.size(0) != 1);
  stride_0_1 = (in3.size(1) != 1);
  stride_1_0 = (in4.size(0) != 1);
  stride_1_1 = (in4.size(1) != 1);
  stride_2_0 = (in5.size(0) != 1);
  stride_2_1 = (in5.size(1) != 1);
  stride_3_0 = (in6.size(0) != 1);
  stride_3_1 = (in6.size(1) != 1);
  aux_0_1 = 0;
  aux_1_1 = 0;
  aux_2_1 = 0;
  aux_3_1 = 0;
  if (in6.size(1) == 1) {
    i = in5.size(1);
  } else {
    i = in6.size(1);
  }
  if (i == 1) {
    if (in4.size(1) == 1) {
      loop_ub = in3.size(1);
    } else {
      loop_ub = in4.size(1);
    }
  } else if (in6.size(1) == 1) {
    loop_ub = in5.size(1);
  } else {
    loop_ub = in6.size(1);
  }
  for (i = 0; i < loop_ub; i++) {
    int b_loop_ub;
    int i1;
    if (in6.size(0) == 1) {
      i1 = in5.size(0);
    } else {
      i1 = in6.size(0);
    }
    if (i1 == 1) {
      if (in4.size(0) == 1) {
        b_loop_ub = in3.size(0);
      } else {
        b_loop_ub = in4.size(0);
      }
    } else if (in6.size(0) == 1) {
      b_loop_ub = in5.size(0);
    } else {
      b_loop_ub = in6.size(0);
    }
    for (i1 = 0; i1 < b_loop_ub; i1++) {
      double in3_im;
      double in3_re;
      double in5_im;
      double in5_re;
      int in3_re_tmp;
      int in5_re_tmp;
      in3_re_tmp = i1 * stride_1_0;
      in3_re = in3[i1 * stride_0_0 + in3.size(0) * aux_0_1] *
               in4[in3_re_tmp + in4.size(0) * aux_1_1].re;
      in3_im = in3[i1 * stride_0_0 + in3.size(0) * aux_0_1] *
               in4[in3_re_tmp + in4.size(0) * aux_1_1].im;
      in3_re_tmp = i1 * stride_2_0;
      in5_re_tmp = i1 * stride_3_0;
      in5_re = in5[in3_re_tmp + in5.size(0) * aux_2_1].re -
               in6[in5_re_tmp + in6.size(0) * aux_3_1].re;
      in5_im = in5[in3_re_tmp + in5.size(0) * aux_2_1].im -
               in6[in5_re_tmp + in6.size(0) * aux_3_1].im;
      in1->re = in3_re * in5_re - in3_im * in5_im;
      in1->im = in3_re * in5_im + in3_im * in5_re;
    }
    aux_3_1 += stride_3_1;
    aux_2_1 += stride_2_1;
    aux_1_1 += stride_1_1;
    aux_0_1 += stride_0_1;
  }
}

//
// Arguments    : double x
//                double dk
//                double k
//                double theta
// Return Type  : creal_T
//
namespace coder {
namespace matlabshared {
namespace tracking {
namespace internal {
namespace scenario {
creal_T fresnelg2(double x, double dk, double k, double theta)
{
  array<creal_T, 2U> A;
  array<creal_T, 2U> B;
  array<creal_T, 2U> c_z;
  array<creal_T, 2U> e;
  array<creal_T, 2U> hidkxx;
  array<creal_T, 2U> m2C;
  array<creal_T, 2U> z0;
  array<creal_T, 2U> z1;
  array<creal_T, 1U> b_z;
  array<double, 2U> b_x;
  array<double, 2U> c_x;
  array<double, 2U> d_x;
  array<double, 2U> igt;
  array<signed char, 2U> ii;
  array<signed char, 2U> ilt;
  array<signed char, 2U> ism;
  creal_T z;
  double d;
  double re;
  double thresh;
  double thresh_tmp_tmp;
  double varargout_1;
  double x_im;
  double x_re;
  double z1_im;
  int acoef;
  int ar_tmp;
  int i;
  thresh_tmp_tmp = k * k;
  thresh = dk / thresh_tmp_tmp;
  if (thresh > 1.0E-6) {
    ii.set_size(1, 1);
    ii[0] = 1;
  } else {
    ii.set_size(0, 0);
  }
  igt.set_size(ii.size(0), ii.size(1));
  acoef = ii.size(0) * ii.size(1);
  for (i = 0; i < acoef; i++) {
    igt[0] = 1.0;
  }
  if (thresh < -1.0E-6) {
    ii.set_size(1, 1);
    ii[0] = 1;
  } else {
    ii.set_size(0, 0);
  }
  ilt.set_size(ii.size(0), ii.size(1));
  acoef = ii.size(0) * ii.size(1);
  for (i = 0; i < acoef; i++) {
    ilt[0] = 1;
  }
  if ((thresh >= -1.0E-6) && (thresh <= 1.0E-6)) {
    ii.set_size(1, 1);
    ii[0] = 1;
  } else {
    ii.set_size(0, 0);
  }
  ism.set_size(ii.size(0), ii.size(1));
  acoef = ii.size(0) * ii.size(1);
  for (i = 0; i < acoef; i++) {
    ism[0] = 1;
  }
  varargout_1 = x * x;
  d = k * x;
  if ((std::abs(dk) * varargout_1 < 0.001) && (std::abs(d) < 0.001)) {
    ii.set_size(1, 1);
    ii[0] = 1;
  } else {
    ii.set_size(0, 0);
  }
  z.re = 0.0;
  z.im = 0.0;
  if ((igt.size(0) != 0) && (igt.size(1) != 0)) {
    b_x.set_size(1, 1);
    b_x[0] = dk / 3.1415926535897931;
    b_x[0] = std::sqrt(b_x[0]);
    c_x.set_size(1, 1);
    c_x[0] = 3.1415926535897931 * dk;
    c_x[0] = std::sqrt(c_x[0]);
    d_x.set_size(1, 1);
    d_x[0] = b_x[0] * x + k / c_x[0];
    fresnel(d_x, z1);
    b_x.set_size(1, 1);
    b_x[0] = 3.1415926535897931 * dk;
    b_x[0] = std::sqrt(b_x[0]);
    c_x.set_size(1, 1);
    c_x[0] = k / b_x[0];
    fresnel(c_x, z0);
    m2C.set_size(1, 1);
    thresh = theta - thresh_tmp_tmp / (2.0 * dk);
    m2C[0].re = thresh * 0.0;
    m2C[0].im = thresh;
    if (m2C[0].im == 0.0) {
      re = std::exp(m2C[0].re);
      thresh = 0.0;
    } else {
      thresh = std::exp(m2C[0].re / 2.0);
      re = thresh * (thresh * std::cos(m2C[0].im));
      thresh *= thresh * std::sin(m2C[0].im);
    }
    m2C[0].re = re;
    m2C[0].im = thresh;
    m2C[0].re = re;
    m2C[0].im = thresh;
    m2C[0].re = re;
    m2C[0].im = thresh;
    z.re = 0.0;
    z.im = 0.0;
    b_x.set_size(1, 1);
    b_x[0] = 3.1415926535897931 / dk;
    b_x[0] = std::sqrt(b_x[0]);
    if (z1.size(0) == 1) {
      i = z0.size(0);
    } else {
      i = z1.size(0);
    }
    if (z1.size(1) == 1) {
      ar_tmp = z0.size(1);
    } else {
      ar_tmp = z1.size(1);
    }
    if ((z1.size(0) == z0.size(0)) && (z1.size(1) == z0.size(1)) && (i == 1) &&
        (ar_tmp == 1)) {
      x_re = b_x[0] * m2C[0].re;
      x_im = b_x[0] * m2C[0].im;
      thresh = z1[0].re - z0[0].re;
      z1_im = z1[0].im - z0[0].im;
      z.re = x_re * thresh - x_im * z1_im;
      z.im = x_re * z1_im + x_im * thresh;
    } else {
      e_binary_expand_op(&z, b_x, m2C, z1, z0);
    }
  }
  if ((ilt.size(0) != 0) && (ilt.size(1) != 0)) {
    b_x.set_size(1, 1);
    b_x[0] = -dk / 3.1415926535897931;
    b_x[0] = std::sqrt(b_x[0]);
    c_x.set_size(1, 1);
    c_x[0] = -3.1415926535897931 * dk;
    c_x[0] = std::sqrt(c_x[0]);
    d_x.set_size(1, 1);
    d_x[0] = b_x[0] * x - k / c_x[0];
    fresnel(d_x, z1);
    b_x.set_size(1, 1);
    b_x[0] = -3.1415926535897931 * dk;
    b_x[0] = std::sqrt(b_x[0]);
    c_x.set_size(1, 1);
    c_x[0] = -k / b_x[0];
    fresnel(c_x, z0);
    m2C.set_size(1, 1);
    m2C[0].re = (theta - k * k / (2.0 * dk)) * 0.0;
    m2C[0].im = -(theta - k * k / (2.0 * dk));
    if (m2C[0].im == 0.0) {
      re = std::exp(m2C[0].re);
      thresh = 0.0;
    } else {
      thresh = std::exp(m2C[0].re / 2.0);
      re = thresh * (thresh * std::cos(m2C[0].im));
      thresh *= thresh * std::sin(m2C[0].im);
    }
    m2C[0].re = re;
    m2C[0].im = thresh;
    m2C[0].re = re;
    m2C[0].im = thresh;
    m2C[0].re = re;
    m2C[0].im = thresh;
    b_x.set_size(1, 1);
    b_x[0] = -3.1415926535897931 / dk;
    b_x[0] = std::sqrt(b_x[0]);
    if (z1.size(0) == 1) {
      i = z0.size(0);
    } else {
      i = z1.size(0);
    }
    if (z1.size(1) == 1) {
      ar_tmp = z0.size(1);
    } else {
      ar_tmp = z1.size(1);
    }
    if ((z1.size(0) == z0.size(0)) && (z1.size(1) == z0.size(1)) && (i == 1) &&
        (ar_tmp == 1)) {
      x_re = b_x[0] * m2C[0].re;
      x_im = b_x[0] * m2C[0].im;
      thresh = z1[0].re - z0[0].re;
      z1_im = z1[0].im - z0[0].im;
      z.re = x_re * thresh - x_im * z1_im;
      z.im = -(x_re * z1_im + x_im * thresh);
    } else {
      binary_expand_op(&z, b_x, m2C, z1, z0);
    }
  }
  if ((ism.size(0) != 0) && (ism.size(1) != 0)) {
    z1.set_size(1, 1);
    z1[0].re = x * (k * 0.0);
    z1[0].im = x * -k;
    z0.set_size(1, 1);
    if (z1[0].im == 0.0) {
      z0[0].re = z1[0].re / 2.0;
      z0[0].im = 0.0;
    } else if (z1[0].re == 0.0) {
      z0[0].re = 0.0;
      z0[0].im = z1[0].im / 2.0;
    } else {
      z0[0].re = rtNaN;
      z0[0].im = z1[0].im / 2.0;
    }
    hidkxx.set_size(1, 1);
    hidkxx[0].re = dk * 0.0;
    hidkxx[0].im = dk * 0.5;
    igt.set_size(1, 1);
    igt[0] = thresh_tmp_tmp;
    m2C.set_size(1, 1);
    if (hidkxx[0].im == 0.0) {
      thresh = hidkxx[0].re / igt[0];
      z1_im = 0.0;
    } else if (hidkxx[0].re == 0.0) {
      thresh = 0.0;
      z1_im = hidkxx[0].im / igt[0];
    } else {
      thresh = rtNaN;
      z1_im = hidkxx[0].im / igt[0];
    }
    m2C[0].re = -2.0 * thresh;
    m2C[0].im = -2.0 * z1_im;
    igt.set_size(1, 1);
    igt[0] = varargout_1;
    hidkxx[0].re = igt[0] * hidkxx[0].re;
    hidkxx[0].im = igt[0] * hidkxx[0].im;
    e.set_size(1, 1);
    e[0].re = -z1[0].re;
    e[0].im = -z1[0].im;
    if (e[0].im == 0.0) {
      re = std::exp(e[0].re);
      thresh = 0.0;
    } else {
      thresh = std::exp(e[0].re / 2.0);
      re = thresh * (thresh * std::cos(e[0].im));
      thresh *= thresh * std::sin(e[0].im);
    }
    e[0].re = re;
    e[0].im = thresh;
    e[0].re = re;
    e[0].im = thresh;
    e[0].re = re;
    e[0].im = thresh;
    z1.set_size(1, 1);
    if (z1[0].im == 0.0) {
      if (0.0 - e[0].im == 0.0) {
        re = (1.0 - e[0].re) / z1[0].re;
        thresh = 0.0;
      } else if (1.0 - e[0].re == 0.0) {
        re = 0.0;
        thresh = (0.0 - e[0].im) / z1[0].re;
      } else {
        re = (1.0 - e[0].re) / z1[0].re;
        thresh = (0.0 - e[0].im) / z1[0].re;
      }
    } else if (z1[0].re == 0.0) {
      if (1.0 - e[0].re == 0.0) {
        re = (0.0 - e[0].im) / z1[0].im;
        thresh = 0.0;
      } else if (0.0 - e[0].im == 0.0) {
        re = 0.0;
        thresh = -((1.0 - e[0].re) / z1[0].im);
      } else {
        re = (0.0 - e[0].im) / z1[0].im;
        thresh = -((1.0 - e[0].re) / z1[0].im);
      }
    } else {
      x_im = std::abs(z1[0].re);
      thresh = std::abs(z1[0].im);
      if (x_im > thresh) {
        thresh = z1[0].im / z1[0].re;
        z1_im = z1[0].re + thresh * z1[0].im;
        re = ((1.0 - e[0].re) + thresh * (0.0 - e[0].im)) / z1_im;
        thresh = ((0.0 - e[0].im) - thresh * (1.0 - e[0].re)) / z1_im;
      } else if (thresh == x_im) {
        if (z1[0].re > 0.0) {
          thresh = 0.5;
        } else {
          thresh = -0.5;
        }
        if (z1[0].im > 0.0) {
          z1_im = 0.5;
        } else {
          z1_im = -0.5;
        }
        re = ((1.0 - e[0].re) * thresh + (0.0 - e[0].im) * z1_im) / x_im;
        thresh = ((0.0 - e[0].im) * thresh - (1.0 - e[0].re) * z1_im) / x_im;
      } else {
        thresh = z1[0].re / z1[0].im;
        z1_im = z1[0].im + thresh * z1[0].re;
        re = (thresh * (1.0 - e[0].re) + (0.0 - e[0].im)) / z1_im;
        thresh = (thresh * (0.0 - e[0].im) - (1.0 - e[0].re)) / z1_im;
      }
    }
    z1[0].re = re;
    z1[0].im = thresh;
    e[0].re = -e[0].re;
    e[0].im = -e[0].im;
    c_z.set_size(1, 1);
    c_z[0] = z1[0];
    for (acoef = 0; acoef < 20; acoef++) {
      i = 2 * (acoef + 1) - 1;
      z1.set_size(1, 1);
      thresh = (static_cast<double>(acoef) + 1.0) + z0[0].re;
      re = static_cast<double>(i) * z1[0].re +
           (e[0].re * thresh - e[0].im * z0[0].im);
      thresh = static_cast<double>(i) * z1[0].im +
               (e[0].re * z0[0].im + e[0].im * thresh);
      z1[0].re = m2C[0].re * re - m2C[0].im * thresh;
      z1[0].im = m2C[0].re * thresh + m2C[0].im * re;
      c_z[0].re = c_z[0].re + z1[0].re;
      c_z[0].im = c_z[0].im + z1[0].im;
      thresh = e[0].re * hidkxx[0].re - e[0].im * hidkxx[0].im;
      z1_im = e[0].re * hidkxx[0].im + e[0].im * hidkxx[0].re;
      if (z1_im == 0.0) {
        e[0].re = thresh / ((static_cast<double>(acoef) + 1.0) + 1.0);
        e[0].im = 0.0;
      } else if (thresh == 0.0) {
        e[0].re = 0.0;
        e[0].im = z1_im / ((static_cast<double>(acoef) + 1.0) + 1.0);
      } else {
        e[0].re = thresh / ((static_cast<double>(acoef) + 1.0) + 1.0);
        e[0].im = z1_im / ((static_cast<double>(acoef) + 1.0) + 1.0);
      }
    }
    m2C.set_size(1, 1);
    m2C[0].re = theta * 0.0;
    m2C[0].im = theta;
    if (m2C[0].im == 0.0) {
      re = std::exp(m2C[0].re);
      thresh = 0.0;
    } else {
      thresh = std::exp(m2C[0].re / 2.0);
      re = thresh * (thresh * std::cos(m2C[0].im));
      thresh *= thresh * std::sin(m2C[0].im);
    }
    m2C[0].re = re;
    m2C[0].im = thresh;
    m2C[0].re = re;
    m2C[0].im = thresh;
    m2C[0].re = re;
    m2C[0].im = thresh;
    x_re = x * c_z[0].re;
    x_im = x * c_z[0].im;
    re = x_re * m2C[0].re - x_im * m2C[0].im;
    thresh = x_re * m2C[0].im + x_im * m2C[0].re;
    z.re = re;
    z.im = thresh;
  }
  if ((ii.size(0) != 0) && (ii.size(1) != 0)) {
    int b_acoef;
    int b_k;
    int c_k;
    int varargin_2;
    signed char size_tmp[2];
    size_tmp[0] = 1;
    size_tmp[1] = 1;
    igt.set_size(1, 1);
    igt[0] = varargout_1;
    z0.set_size(1, 1);
    z0[0].re = igt[0] * (dk * 0.0);
    z0[0].im = igt[0] * (dk * 0.5);
    repmat(z0, z1);
    A.set_size(z1.size(0), 5);
    if (z1.size(0) != 0) {
      acoef = (z1.size(1) != 1);
      b_acoef = (z1.size(0) != 1);
      for (b_k = 0; b_k < 5; b_k++) {
        varargin_2 = acoef * b_k;
        i = A.size(0) - 1;
        for (c_k = 0; c_k <= i; c_k++) {
          ar_tmp = b_acoef * c_k;
          thresh = z1[ar_tmp + z1.size(0) * varargin_2].re;
          x_im = z1[ar_tmp + z1.size(0) * varargin_2].im;
          if (x_im == 0.0) {
            A[c_k + A.size(0) * b_k].re =
                thresh / (static_cast<double>(b_k) + 1.0);
            A[c_k + A.size(0) * b_k].im = 0.0;
          } else if (thresh == 0.0) {
            A[c_k + A.size(0) * b_k].re = 0.0;
            A[c_k + A.size(0) * b_k].im =
                x_im / (static_cast<double>(b_k) + 1.0);
          } else {
            A[c_k + A.size(0) * b_k].re =
                thresh / (static_cast<double>(b_k) + 1.0);
            A[c_k + A.size(0) * b_k].im =
                x_im / (static_cast<double>(b_k) + 1.0);
          }
        }
      }
    }
    if (A.size(0) != 0) {
      for (b_k = 0; b_k < 4; b_k++) {
        i = A.size(0);
        for (c_k = 0; c_k < i; c_k++) {
          thresh = A[c_k + A.size(0) * b_k].re;
          z1_im = A[c_k + A.size(0) * (b_k + 1)].im;
          x_im = A[c_k + A.size(0) * b_k].im;
          x_re = A[c_k + A.size(0) * (b_k + 1)].re;
          A[c_k + A.size(0) * (b_k + 1)].re = thresh * x_re - x_im * z1_im;
          A[c_k + A.size(0) * (b_k + 1)].im = thresh * z1_im + x_im * x_re;
        }
      }
    }
    z0.set_size(1, 1);
    z0[0].re = x * (k * 0.0);
    z0[0].im = d;
    repmat(z0, z1);
    B.set_size(z1.size(0), 5);
    if (z1.size(0) != 0) {
      acoef = (z1.size(1) != 1);
      b_acoef = (z1.size(0) != 1);
      for (b_k = 0; b_k < 5; b_k++) {
        varargin_2 = acoef * b_k;
        i = B.size(0) - 1;
        for (c_k = 0; c_k <= i; c_k++) {
          ar_tmp = b_acoef * c_k;
          thresh = z1[ar_tmp + z1.size(0) * varargin_2].re;
          x_im = z1[ar_tmp + z1.size(0) * varargin_2].im;
          if (x_im == 0.0) {
            B[c_k + B.size(0) * b_k].re =
                thresh / (static_cast<double>(b_k) + 1.0);
            B[c_k + B.size(0) * b_k].im = 0.0;
          } else if (thresh == 0.0) {
            B[c_k + B.size(0) * b_k].re = 0.0;
            B[c_k + B.size(0) * b_k].im =
                x_im / (static_cast<double>(b_k) + 1.0);
          } else {
            B[c_k + B.size(0) * b_k].re =
                thresh / (static_cast<double>(b_k) + 1.0);
            B[c_k + B.size(0) * b_k].im =
                x_im / (static_cast<double>(b_k) + 1.0);
          }
        }
      }
    }
    if (B.size(0) != 0) {
      for (b_k = 0; b_k < 4; b_k++) {
        i = B.size(0);
        for (c_k = 0; c_k < i; c_k++) {
          thresh = B[c_k + B.size(0) * b_k].re;
          z1_im = B[c_k + B.size(0) * (b_k + 1)].im;
          x_im = B[c_k + B.size(0) * b_k].im;
          x_re = B[c_k + B.size(0) * (b_k + 1)].re;
          B[c_k + B.size(0) * (b_k + 1)].re = thresh * x_re - x_im * z1_im;
          B[c_k + B.size(0) * (b_k + 1)].im = thresh * z1_im + x_im * x_re;
        }
      }
    }
    b_z.set_size(1);
    b_z[0].re = 1.0;
    b_z[0].im = 0.0;
    for (b_acoef = 0; b_acoef < 5; b_acoef++) {
      b_k = (b_acoef + 1) << 1;
      acoef = b_z.size(0);
      if (b_z.size(0) == A.size(0)) {
        for (i = 0; i < acoef; i++) {
          thresh = A[i + A.size(0) * b_acoef].re;
          x_im = A[i + A.size(0) * b_acoef].im;
          if (x_im == 0.0) {
            thresh_tmp_tmp = thresh / (static_cast<double>(b_k) + 1.0);
            thresh = 0.0;
          } else if (thresh == 0.0) {
            thresh_tmp_tmp = 0.0;
            thresh = x_im / (static_cast<double>(b_k) + 1.0);
          } else {
            thresh_tmp_tmp = thresh / (static_cast<double>(b_k) + 1.0);
            thresh = x_im / (static_cast<double>(b_k) + 1.0);
          }
          b_z[i].re = b_z[i].re + thresh_tmp_tmp;
          b_z[i].im = b_z[i].im + thresh;
        }
      } else {
        binary_expand_op(b_z, A, b_acoef, b_k);
      }
    }
    for (varargin_2 = 0; varargin_2 < 5; varargin_2++) {
      acoef = b_z.size(0);
      if (b_z.size(0) == B.size(0)) {
        for (i = 0; i < acoef; i++) {
          thresh = B[i + B.size(0) * varargin_2].re;
          x_im = B[i + B.size(0) * varargin_2].im;
          if (x_im == 0.0) {
            z1_im = thresh / ((static_cast<double>(varargin_2) + 1.0) + 1.0);
            thresh = 0.0;
          } else if (thresh == 0.0) {
            z1_im = 0.0;
            thresh = x_im / ((static_cast<double>(varargin_2) + 1.0) + 1.0);
          } else {
            z1_im = thresh / ((static_cast<double>(varargin_2) + 1.0) + 1.0);
            thresh = x_im / ((static_cast<double>(varargin_2) + 1.0) + 1.0);
          }
          b_z[i].re = b_z[i].re + z1_im;
          b_z[i].im = b_z[i].im + thresh;
        }
      } else {
        binary_expand_op(b_z, B, varargin_2);
      }
    }
    for (b_acoef = 0; b_acoef < 4; b_acoef++) {
      i = (b_acoef + 1) << 1;
      c_k = 4 - i;
      for (varargin_2 = 0; varargin_2 <= c_k; varargin_2++) {
        b_k = i + varargin_2;
        acoef = b_z.size(0);
        if (A.size(0) == 1) {
          ar_tmp = B.size(0);
        } else {
          ar_tmp = A.size(0);
        }
        if ((A.size(0) == B.size(0)) && (b_z.size(0) == ar_tmp)) {
          for (ar_tmp = 0; ar_tmp < acoef; ar_tmp++) {
            thresh = A[ar_tmp + A.size(0) * b_acoef].re;
            z1_im = B[ar_tmp + B.size(0) * varargin_2].im;
            x_im = A[ar_tmp + A.size(0) * b_acoef].im;
            x_re = B[ar_tmp + B.size(0) * varargin_2].re;
            thresh_tmp_tmp = thresh * x_re - x_im * z1_im;
            thresh = thresh * z1_im + x_im * x_re;
            if (thresh == 0.0) {
              thresh_tmp_tmp /= static_cast<double>(b_k) + 2.0;
              thresh = 0.0;
            } else if (thresh_tmp_tmp == 0.0) {
              thresh_tmp_tmp = 0.0;
              thresh /= static_cast<double>(b_k) + 2.0;
            } else {
              thresh_tmp_tmp /= static_cast<double>(b_k) + 2.0;
              thresh /= static_cast<double>(b_k) + 2.0;
            }
            b_z[ar_tmp].re = b_z[ar_tmp].re + thresh_tmp_tmp;
            b_z[ar_tmp].im = b_z[ar_tmp].im + thresh;
          }
        } else {
          binary_expand_op(b_z, A, b_acoef, B, varargin_2, b_k);
        }
      }
    }
    m2C.set_size(1, 1);
    m2C[0].re = theta * 0.0;
    m2C[0].im = theta;
    if (m2C[0].im == 0.0) {
      re = std::exp(m2C[0].re);
      thresh = 0.0;
    } else {
      thresh = std::exp(m2C[0].re / 2.0);
      re = thresh * (thresh * std::cos(m2C[0].im));
      thresh *= thresh * std::sin(m2C[0].im);
    }
    m2C[0].re = re;
    m2C[0].im = thresh;
    m2C[0].re = re;
    m2C[0].im = thresh;
    m2C[0].re = re;
    m2C[0].im = thresh;
    if (b_z.size(0) == 1) {
      i = 1;
    } else {
      i = b_z.size(0);
    }
    if ((b_z.size(0) == 1) && (i == 1)) {
      thresh = x * b_z[0].re;
      z1_im = x * b_z[0].im;
      z.re = thresh * m2C[0].re - z1_im * m2C[0].im;
      z.im = thresh * m2C[0].im + z1_im * m2C[0].re;
    } else {
      binary_expand_op(&z, b_z, x, size_tmp, m2C);
    }
  }
  return z;
}

} // namespace scenario
} // namespace internal
} // namespace tracking
} // namespace matlabshared
} // namespace coder

//
// File trailer for fresnelg2.cpp
//
// [EOF]
//
