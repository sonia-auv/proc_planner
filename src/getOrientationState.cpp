//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: getOrientationState.cpp
//
// MATLAB Coder version            : 5.4
// C/C++ source code generated on  : 12-Apr-2022 11:44:16
//

// Include Files
#include "getOrientationState.h"
#include "clothoidG1fit2wp.h"
#include "dot.h"
#include "quaternion.h"
#include "quaternionBase.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <cmath>
#include <string.h>

// Function Declarations
static void binary_expand_op(double in1[3],
                             const coder::array<signed char, 2U> &in2,
                             const coder::array<double, 2U> &in3,
                             const coder::array<double, 2U> &in4,
                             const coder::array<double, 2U> &in5);

static void binary_expand_op(coder::array<double, 2U> &in1,
                             const coder::array<double, 2U> &in2,
                             const coder::array<double, 2U> &in3,
                             const coder::array<double, 2U> &in4);

static void binary_expand_op(coder::array<double, 2U> &in1,
                             const coder::array<double, 1U> &in2,
                             const coder::array<double, 2U> &in3,
                             const coder::array<double, 1U> &in4,
                             const coder::array<double, 2U> &in5);

static void binary_expand_op(coder::array<double, 2U> &in1,
                             const coder::array<double, 2U> &in2,
                             const coder::array<double, 2U> &in3,
                             const coder::array<double, 2U> &in4,
                             const coder::array<double, 2U> &in5,
                             const coder::array<double, 2U> &in6);

static void binary_expand_op(coder::array<double, 2U> &in1,
                             const coder::array<double, 1U> &in2,
                             const coder::array<double, 1U> &in3,
                             const coder::array<double, 1U> &in4,
                             const coder::array<double, 1U> &in5,
                             const coder::array<double, 1U> &in6,
                             const coder::array<double, 2U> &in7);

static void binary_expand_op(coder::array<double, 2U> &in1,
                             const coder::array<double, 1U> &in2,
                             const coder::array<double, 2U> &in3,
                             const coder::array<double, 2U> &in4);

static void binary_expand_op(
    coder::array<double, 2U> &in1, const coder::array<double, 2U> &in2,
    const coder::array<double, 2U> &in3, const coder::array<double, 2U> &in4,
    const coder::array<double, 2U> &in5, const coder::array<double, 2U> &in6,
    const coder::array<double, 2U> &in7, const coder::array<double, 2U> &in8);

namespace coder {
namespace fusion {
namespace scenario {
namespace internal {
static void angDeriv(const ::coder::array<double, 2U> &ang,
                     const ::coder::array<double, 2U> &th1,
                     const ::coder::array<double, 2U> &th2,
                     const ::coder::array<double, 2U> &th3,
                     const ::coder::array<double, 2U> &u,
                     ::coder::array<double, 2U> &angVel,
                     ::coder::array<double, 2U> &angAcc,
                     ::coder::array<double, 2U> &angJerk);

static void bsxdiv(const ::coder::array<double, 2U> &x,
                   const ::coder::array<double, 2U> &y,
                   ::coder::array<double, 2U> &z);

static void bsxmul(const ::coder::array<double, 1U> &x,
                   const ::coder::array<double, 2U> &y,
                   ::coder::array<double, 2U> &z);

static void bsxmul(const ::coder::array<double, 2U> &x,
                   const ::coder::array<double, 2U> &y,
                   ::coder::array<double, 2U> &z);

} // namespace internal
} // namespace scenario
} // namespace fusion
} // namespace coder
static void e_binary_expand_op(coder::array<double, 2U> &in1,
                               const coder::array<double, 2U> &in2,
                               const coder::array<double, 2U> &in3);

static void e_binary_expand_op(coder::array<double, 2U> &in1,
                               const coder::array<double, 1U> &in2,
                               const coder::array<double, 2U> &in3,
                               const coder::array<double, 2U> &in4);

static void f_binary_expand_op(coder::array<double, 2U> &in1,
                               const coder::array<double, 2U> &in2,
                               const coder::array<double, 2U> &in3);

static void f_binary_expand_op(coder::array<double, 2U> &in1,
                               const coder::array<double, 2U> &in2,
                               const coder::array<double, 2U> &in3,
                               const coder::array<double, 2U> &in4,
                               const coder::array<double, 2U> &in5);

static void minus(coder::array<double, 2U> &in1,
                  const coder::array<double, 2U> &in2);

// Function Definitions
//
// Arguments    : coder::array<double, 2U> &in1
//                const coder::array<double, 2U> &in2
//                const coder::array<double, 2U> &in3
//                const coder::array<double, 2U> &in4
//                const coder::array<double, 2U> &in5
//                const coder::array<double, 2U> &in6
// Return Type  : void
//
static void binary_expand_op(coder::array<double, 2U> &in1,
                             const coder::array<double, 2U> &in2,
                             const coder::array<double, 2U> &in3,
                             const coder::array<double, 2U> &in4,
                             const coder::array<double, 2U> &in5,
                             const coder::array<double, 2U> &in6)
{
  coder::array<double, 2U> b_in2;
  int i;
  int loop_ub;
  int stride_0_0;
  int stride_1_0;
  int stride_2_0;
  int stride_3_0;
  if (in5.size(0) == 1) {
    if (in4.size(0) == 1) {
      if (in3.size(0) == 1) {
        i = in2.size(0);
      } else {
        i = in3.size(0);
      }
    } else {
      i = in4.size(0);
    }
  } else {
    i = in5.size(0);
  }
  b_in2.set_size(i, 3);
  stride_0_0 = (in2.size(0) != 1);
  stride_1_0 = (in3.size(0) != 1);
  stride_2_0 = (in4.size(0) != 1);
  stride_3_0 = (in5.size(0) != 1);
  if (in5.size(0) == 1) {
    if (in4.size(0) == 1) {
      if (in3.size(0) == 1) {
        loop_ub = in2.size(0);
      } else {
        loop_ub = in3.size(0);
      }
    } else {
      loop_ub = in4.size(0);
    }
  } else {
    loop_ub = in5.size(0);
  }
  for (i = 0; i < 3; i++) {
    for (int i1{0}; i1 < loop_ub; i1++) {
      b_in2[i1 + b_in2.size(0) * i] =
          ((in2[i1 * stride_0_0 + in2.size(0) * i] +
            in3[i1 * stride_1_0 + in3.size(0) * i]) -
           in4[i1 * stride_2_0 + in4.size(0) * i]) -
          in5[i1 * stride_3_0 + in5.size(0) * i];
    }
  }
  coder::fusion::scenario::internal::bsxdiv(b_in2, in6, in1);
}

//
// Arguments    : coder::array<double, 2U> &in1
//                const coder::array<double, 2U> &in2
//                const coder::array<double, 2U> &in3
//                const coder::array<double, 2U> &in4
//                const coder::array<double, 2U> &in5
//                const coder::array<double, 2U> &in6
//                const coder::array<double, 2U> &in7
//                const coder::array<double, 2U> &in8
// Return Type  : void
//
static void binary_expand_op(
    coder::array<double, 2U> &in1, const coder::array<double, 2U> &in2,
    const coder::array<double, 2U> &in3, const coder::array<double, 2U> &in4,
    const coder::array<double, 2U> &in5, const coder::array<double, 2U> &in6,
    const coder::array<double, 2U> &in7, const coder::array<double, 2U> &in8)
{
  coder::array<double, 2U> b_in1;
  int i;
  int loop_ub;
  int stride_0_0;
  int stride_1_0;
  int stride_2_0;
  int stride_3_0;
  int stride_4_0;
  int stride_5_0;
  int stride_6_0;
  int stride_7_0;
  if (in8.size(0) == 1) {
    if (in7.size(0) == 1) {
      if (in6.size(0) == 1) {
        if (in5.size(0) == 1) {
          if (in4.size(0) == 1) {
            if (in3.size(0) == 1) {
              if (in2.size(0) == 1) {
                i = in1.size(0);
              } else {
                i = in2.size(0);
              }
            } else {
              i = in3.size(0);
            }
          } else {
            i = in4.size(0);
          }
        } else {
          i = in5.size(0);
        }
      } else {
        i = in6.size(0);
      }
    } else {
      i = in7.size(0);
    }
  } else {
    i = in8.size(0);
  }
  b_in1.set_size(i, 3);
  stride_0_0 = (in1.size(0) != 1);
  stride_1_0 = (in2.size(0) != 1);
  stride_2_0 = (in3.size(0) != 1);
  stride_3_0 = (in4.size(0) != 1);
  stride_4_0 = (in5.size(0) != 1);
  stride_5_0 = (in6.size(0) != 1);
  stride_6_0 = (in7.size(0) != 1);
  stride_7_0 = (in8.size(0) != 1);
  if (in8.size(0) == 1) {
    if (in7.size(0) == 1) {
      if (in6.size(0) == 1) {
        if (in5.size(0) == 1) {
          if (in4.size(0) == 1) {
            if (in3.size(0) == 1) {
              if (in2.size(0) == 1) {
                loop_ub = in1.size(0);
              } else {
                loop_ub = in2.size(0);
              }
            } else {
              loop_ub = in3.size(0);
            }
          } else {
            loop_ub = in4.size(0);
          }
        } else {
          loop_ub = in5.size(0);
        }
      } else {
        loop_ub = in6.size(0);
      }
    } else {
      loop_ub = in7.size(0);
    }
  } else {
    loop_ub = in8.size(0);
  }
  for (i = 0; i < 3; i++) {
    for (int i1{0}; i1 < loop_ub; i1++) {
      b_in1[i1 + b_in1.size(0) * i] =
          ((((((in1[i1 * stride_0_0 + in1.size(0) * i] +
                in2[i1 * stride_1_0 + in2.size(0) * i]) -
               in3[i1 * stride_2_0 + in3.size(0) * i]) +
              in4[i1 * stride_3_0 + in4.size(0) * i]) +
             in5[i1 * stride_4_0 + in5.size(0) * i]) -
            in6[i1 * stride_5_0 + in6.size(0) * i]) +
           in7[i1 * stride_6_0 + in7.size(0) * i]) +
          in8[i1 * stride_7_0 + in8.size(0) * i];
    }
  }
  in1.set_size(b_in1.size(0), 3);
  loop_ub = b_in1.size(0);
  for (i = 0; i < 3; i++) {
    for (int i1{0}; i1 < loop_ub; i1++) {
      in1[i1 + in1.size(0) * i] = b_in1[i1 + b_in1.size(0) * i];
    }
  }
}

//
// Arguments    : coder::array<double, 2U> &in1
//                const coder::array<double, 1U> &in2
//                const coder::array<double, 2U> &in3
//                const coder::array<double, 2U> &in4
// Return Type  : void
//
static void binary_expand_op(coder::array<double, 2U> &in1,
                             const coder::array<double, 1U> &in2,
                             const coder::array<double, 2U> &in3,
                             const coder::array<double, 2U> &in4)
{
  coder::array<double, 2U> b_in2;
  int i;
  int in2_idx_0;
  int loop_ub;
  int stride_0_0;
  int stride_1_0;
  in2_idx_0 = in2.size(0);
  if (in3.size(0) == 1) {
    i = in2_idx_0;
  } else {
    i = in3.size(0);
  }
  b_in2.set_size(i, in3.size(1));
  stride_0_0 = (in2_idx_0 != 1);
  stride_1_0 = (in3.size(0) != 1);
  loop_ub = in3.size(1);
  for (i = 0; i < loop_ub; i++) {
    int b_loop_ub;
    if (in3.size(0) == 1) {
      b_loop_ub = in2_idx_0;
    } else {
      b_loop_ub = in3.size(0);
    }
    for (int i1{0}; i1 < b_loop_ub; i1++) {
      b_in2[i1 + b_in2.size(0) * i] =
          in2[i1 * stride_0_0] * in3[i1 * stride_1_0 + in3.size(0) * i];
    }
  }
  coder::fusion::scenario::internal::bsxmul(b_in2, in4, in1);
}

//
// Arguments    : coder::array<double, 2U> &in1
//                const coder::array<double, 1U> &in2
//                const coder::array<double, 1U> &in3
//                const coder::array<double, 1U> &in4
//                const coder::array<double, 1U> &in5
//                const coder::array<double, 1U> &in6
//                const coder::array<double, 2U> &in7
// Return Type  : void
//
static void binary_expand_op(coder::array<double, 2U> &in1,
                             const coder::array<double, 1U> &in2,
                             const coder::array<double, 1U> &in3,
                             const coder::array<double, 1U> &in4,
                             const coder::array<double, 1U> &in5,
                             const coder::array<double, 1U> &in6,
                             const coder::array<double, 2U> &in7)
{
  coder::array<double, 1U> b_in2;
  int i;
  int loop_ub;
  int stride_0_0;
  int stride_1_0;
  int stride_2_0;
  int stride_3_0;
  int stride_4_0;
  if (in4.size(0) == 1) {
    i = in3.size(0);
  } else {
    i = in4.size(0);
  }
  if (in6.size(0) == 1) {
    if (in5.size(0) == 1) {
      if (i == 1) {
        i = in2.size(0);
      } else if (in4.size(0) == 1) {
        i = in3.size(0);
      } else {
        i = in4.size(0);
      }
    } else {
      i = in5.size(0);
    }
  } else {
    i = in6.size(0);
  }
  b_in2.set_size(i);
  stride_0_0 = (in2.size(0) != 1);
  stride_1_0 = (in3.size(0) != 1);
  stride_2_0 = (in4.size(0) != 1);
  stride_3_0 = (in5.size(0) != 1);
  stride_4_0 = (in6.size(0) != 1);
  if (in6.size(0) == 1) {
    if (in5.size(0) == 1) {
      if (in4.size(0) == 1) {
        i = in3.size(0);
      } else {
        i = in4.size(0);
      }
      if (i == 1) {
        loop_ub = in2.size(0);
      } else if (in4.size(0) == 1) {
        loop_ub = in3.size(0);
      } else {
        loop_ub = in4.size(0);
      }
    } else {
      loop_ub = in5.size(0);
    }
  } else {
    loop_ub = in6.size(0);
  }
  for (i = 0; i < loop_ub; i++) {
    b_in2[i] =
        ((in2[i * stride_0_0] - in3[i * stride_1_0] * in4[i * stride_2_0]) +
         2.0 * in5[i * stride_3_0]) +
        in6[i * stride_4_0];
  }
  coder::fusion::scenario::internal::bsxmul(b_in2, in7, in1);
}

//
// Arguments    : coder::array<double, 2U> &in1
//                const coder::array<double, 1U> &in2
//                const coder::array<double, 2U> &in3
//                const coder::array<double, 1U> &in4
//                const coder::array<double, 2U> &in5
// Return Type  : void
//
static void binary_expand_op(coder::array<double, 2U> &in1,
                             const coder::array<double, 1U> &in2,
                             const coder::array<double, 2U> &in3,
                             const coder::array<double, 1U> &in4,
                             const coder::array<double, 2U> &in5)
{
  coder::array<double, 2U> r;
  int b_in4_idx_0;
  int in2_idx_0;
  int in4_idx_0;
  int loop_ub;
  int stride_1_0;
  int stride_2_0;
  in2_idx_0 = in2.size(0);
  in4_idx_0 = in4.size(0);
  if (in4_idx_0 == 1) {
    if (in3.size(0) == 1) {
      b_in4_idx_0 = in2_idx_0;
    } else {
      b_in4_idx_0 = in3.size(0);
    }
  } else {
    b_in4_idx_0 = in4_idx_0;
  }
  r.set_size(b_in4_idx_0, in3.size(1));
  b_in4_idx_0 = (in2_idx_0 != 1);
  stride_1_0 = (in3.size(0) != 1);
  stride_2_0 = (in4_idx_0 != 1);
  loop_ub = in3.size(1);
  for (int i{0}; i < loop_ub; i++) {
    int b_loop_ub;
    if (in4_idx_0 == 1) {
      if (in3.size(0) == 1) {
        b_loop_ub = in2_idx_0;
      } else {
        b_loop_ub = in3.size(0);
      }
    } else {
      b_loop_ub = in4_idx_0;
    }
    for (int i1{0}; i1 < b_loop_ub; i1++) {
      r[i1 + r.size(0) * i] =
          2.0 *
          (in2[i1 * b_in4_idx_0] / in3[i1 * stride_1_0 + in3.size(0) * i] +
           in4[i1 * stride_2_0]);
    }
  }
  coder::fusion::scenario::internal::bsxmul(r, in5, in1);
}

//
// Arguments    : coder::array<double, 2U> &in1
//                const coder::array<double, 2U> &in2
//                const coder::array<double, 2U> &in3
//                const coder::array<double, 2U> &in4
// Return Type  : void
//
static void binary_expand_op(coder::array<double, 2U> &in1,
                             const coder::array<double, 2U> &in2,
                             const coder::array<double, 2U> &in3,
                             const coder::array<double, 2U> &in4)
{
  coder::array<double, 2U> b_in2;
  int i;
  int loop_ub;
  int stride_0_0;
  int stride_1_0;
  if (in3.size(0) == 1) {
    i = in2.size(0);
  } else {
    i = in3.size(0);
  }
  b_in2.set_size(i, 3);
  stride_0_0 = (in2.size(0) != 1);
  stride_1_0 = (in3.size(0) != 1);
  if (in3.size(0) == 1) {
    loop_ub = in2.size(0);
  } else {
    loop_ub = in3.size(0);
  }
  for (i = 0; i < 3; i++) {
    for (int i1{0}; i1 < loop_ub; i1++) {
      b_in2[i1 + b_in2.size(0) * i] = in2[i1 * stride_0_0 + in2.size(0) * i] -
                                      in3[i1 * stride_1_0 + in3.size(0) * i];
    }
  }
  coder::fusion::scenario::internal::bsxdiv(b_in2, in4, in1);
}

//
// Arguments    : double in1[3]
//                const coder::array<signed char, 2U> &in2
//                const coder::array<double, 2U> &in3
//                const coder::array<double, 2U> &in4
//                const coder::array<double, 2U> &in5
// Return Type  : void
//
static void binary_expand_op(double in1[3],
                             const coder::array<signed char, 2U> &in2,
                             const coder::array<double, 2U> &in3,
                             const coder::array<double, 2U> &in4,
                             const coder::array<double, 2U> &in5)
{
  int loop_ub;
  int stride_0_0;
  int stride_1_0;
  int stride_2_0;
  stride_0_0 = (in3.size(0) != 1);
  stride_1_0 = (in4.size(0) != 1);
  stride_2_0 = (in5.size(0) != 1);
  if (in5.size(0) == 1) {
    if (in4.size(0) == 1) {
      loop_ub = in3.size(0);
    } else {
      loop_ub = in4.size(0);
    }
  } else {
    loop_ub = in5.size(0);
  }
  for (int i{0}; i < 3; i++) {
    for (int i1{0}; i1 < loop_ub; i1++) {
      in1[(in2[i1] + i) - 1] = (in3[i1 * stride_0_0 + in3.size(0) * i] +
                                in4[i1 * stride_1_0 + in4.size(0) * i]) +
                               in5[i1 * stride_2_0 + in5.size(0) * i];
    }
  }
}

//
// Arguments    : const ::coder::array<double, 2U> &ang
//                const ::coder::array<double, 2U> &th1
//                const ::coder::array<double, 2U> &th2
//                const ::coder::array<double, 2U> &th3
//                const ::coder::array<double, 2U> &u
//                ::coder::array<double, 2U> &angVel
//                ::coder::array<double, 2U> &angAcc
//                ::coder::array<double, 2U> &angJerk
// Return Type  : void
//
namespace coder {
namespace fusion {
namespace scenario {
namespace internal {
static void angDeriv(const ::coder::array<double, 2U> &ang,
                     const ::coder::array<double, 2U> &th1,
                     const ::coder::array<double, 2U> &th2,
                     const ::coder::array<double, 2U> &th3,
                     const ::coder::array<double, 2U> &u,
                     ::coder::array<double, 2U> &angVel,
                     ::coder::array<double, 2U> &angAcc,
                     ::coder::array<double, 2U> &angJerk)
{
  array<double, 2U> b;
  array<double, 2U> b_c;
  array<double, 2U> b_ca;
  array<double, 2U> c;
  array<double, 2U> c_c;
  array<double, 2U> ca;
  array<double, 2U> r;
  array<double, 2U> r3;
  array<double, 2U> r4;
  array<double, 2U> sa;
  array<double, 2U> temp0;
  array<double, 2U> udot;
  array<double, 2U> w;
  array<double, 2U> wd1;
  array<double, 2U> wd1xu;
  array<double, 2U> wd2;
  array<double, 1U> r1;
  array<double, 1U> r2;
  array<double, 1U> thd1_tmp;
  array<double, 1U> thd2;
  array<double, 1U> w2;
  array<double, 1U> wwd;
  array<double, 1U> x;
  int b_i1;
  int b_i2;
  int b_i3;
  int i;
  int i1;
  int i2;
  int i3;
  int iNext;
  int k;
  int nx;
  ca.set_size(ang.size(0), ang.size(1));
  nx = ang.size(0) * ang.size(1);
  for (i3 = 0; i3 < nx; i3++) {
    ca[i3] = ang[i3];
  }
  nx = ang.size(0) * ang.size(1);
  for (k = 0; k < nx; k++) {
    ca[k] = std::cos(ca[k]);
  }
  sa.set_size(ang.size(0), ang.size(1));
  nx = ang.size(0) * ang.size(1);
  for (i3 = 0; i3 < nx; i3++) {
    sa[i3] = ang[i3];
  }
  nx = ang.size(0) * ang.size(1);
  for (k = 0; k < nx; k++) {
    sa[k] = std::sin(sa[k]);
  }
  c.set_size(u.size(0), 3);
  if (u.size(0) != 0) {
    nx = u.size(0);
    iNext = u.size(0) * 3;
    for (k = 1; iNext < 0 ? k >= 1 : k <= 1; k += iNext) {
      for (i1 = 1; i1 <= nx; i1++) {
        i2 = (i1 + nx) - 1;
        i3 = i2 + nx;
        c[i1 - 1] = u[i2] * th1[i3] - u[i3] * th1[i2];
        c[i2] = u[i3] * th1[i1 - 1] - u[i1 - 1] * th1[i3];
        c[i3] = u[i1 - 1] * th1[i2] - u[i2] * th1[i1 - 1];
      }
    }
  }
  bsxdiv(c, ang, w);
  udot.set_size(w.size(0), 3);
  if (w.size(0) != 0) {
    nx = w.size(0);
    iNext = w.size(0) * 3;
    for (k = 1; iNext < 0 ? k >= 1 : k <= 1; k += iNext) {
      for (i1 = 1; i1 <= nx; i1++) {
        i2 = (i1 + nx) - 1;
        i3 = i2 + nx;
        udot[i1 - 1] = w[i2] * u[i3] - w[i3] * u[i2];
        udot[i2] = w[i3] * u[i1 - 1] - w[i1 - 1] * u[i3];
        udot[i3] = w[i1 - 1] * u[i2] - w[i2] * u[i1 - 1];
      }
    }
  }
  dot(u, th1, thd1_tmp);
  bsxmul(thd1_tmp, u, temp0);
  bsxmul(sa, udot, angVel);
  b_ca.set_size(ca.size(0), ca.size(1));
  nx = ca.size(0) * ca.size(1);
  for (i3 = 0; i3 < nx; i3++) {
    b_ca[i3] = 1.0 - ca[i3];
  }
  bsxmul(b_ca, w, r);
  if (temp0.size(0) == 1) {
    iNext = angVel.size(0);
  } else {
    iNext = temp0.size(0);
  }
  if ((temp0.size(0) == angVel.size(0)) && (iNext == r.size(0))) {
    nx = temp0.size(0) * 3;
    angVel.set_size(temp0.size(0), 3);
    for (i3 = 0; i3 < nx; i3++) {
      angVel[i3] = (temp0[i3] + angVel[i3]) - r[i3];
    }
  } else {
    f_binary_expand_op(angVel, temp0, r);
  }
  dot(u, th2, r1);
  dot(udot, th1, thd2);
  if (thd2.size(0) == r1.size(0)) {
    nx = thd2.size(0);
    for (i3 = 0; i3 < nx; i3++) {
      thd2[i3] = thd2[i3] + r1[i3];
    }
  } else {
    plus(thd2, r1);
  }
  c.set_size(u.size(0), 3);
  if (u.size(0) != 0) {
    nx = u.size(0);
    iNext = u.size(0) * 3;
    for (k = 1; iNext < 0 ? k >= 1 : k <= 1; k += iNext) {
      for (i1 = 1; i1 <= nx; i1++) {
        i2 = (i1 + nx) - 1;
        i3 = i2 + nx;
        c[i1 - 1] = u[i2] * th2[i3] - u[i3] * th2[i2];
        c[i2] = u[i3] * th2[i1 - 1] - u[i1 - 1] * th2[i3];
        c[i3] = u[i1 - 1] * th2[i2] - u[i2] * th2[i1 - 1];
      }
    }
  }
  r2.set_size(thd1_tmp.size(0));
  nx = thd1_tmp.size(0);
  for (i3 = 0; i3 < nx; i3++) {
    r2[i3] = 2.0 * thd1_tmp[i3];
  }
  nx = w.size(0);
  iNext = r2.size(0);
  if (nx <= iNext) {
    iNext = nx;
  }
  if (w.size(0) == 1) {
    iNext = r2.size(0);
  } else if (r2.size(0) == 1) {
    iNext = w.size(0);
  } else if (r2.size(0) == w.size(0)) {
    iNext = r2.size(0);
  }
  r.set_size(iNext, 3);
  nx = w.size(0);
  iNext = r2.size(0);
  if (nx <= iNext) {
    iNext = nx;
  }
  if (w.size(0) == 1) {
    iNext = r2.size(0);
  } else if (r2.size(0) == 1) {
    iNext = w.size(0);
  } else if (r2.size(0) == w.size(0)) {
    iNext = r2.size(0);
  }
  if (iNext != 0) {
    nx = (r2.size(0) != 1);
    iNext = (w.size(0) != 1);
    for (k = 0; k < 3; k++) {
      i3 = r.size(0) - 1;
      for (i2 = 0; i2 <= i3; i2++) {
        r[i2 + r.size(0) * k] = r2[nx * i2] * w[iNext * i2 + w.size(0) * k];
      }
    }
  }
  if (c.size(0) == r.size(0)) {
    b_c.set_size(c.size(0), 3);
    nx = c.size(0) * 3;
    for (i3 = 0; i3 < nx; i3++) {
      b_c[i3] = c[i3] - r[i3];
    }
    bsxdiv(b_c, ang, wd1);
  } else {
    binary_expand_op(wd1, c, r, ang);
  }
  wd1xu.set_size(wd1.size(0), 3);
  if (wd1.size(0) != 0) {
    nx = wd1.size(0);
    iNext = wd1.size(0) * 3;
    for (k = 1; iNext < 0 ? k >= 1 : k <= 1; k += iNext) {
      for (i1 = 1; i1 <= nx; i1++) {
        i2 = (i1 + nx) - 1;
        i3 = i2 + nx;
        wd1xu[i1 - 1] = wd1[i2] * u[i3] - wd1[i3] * u[i2];
        wd1xu[i2] = wd1[i3] * u[i1 - 1] - wd1[i1 - 1] * u[i3];
        wd1xu[i3] = wd1[i1 - 1] * u[i2] - wd1[i2] * u[i1 - 1];
      }
    }
  }
  if (temp0.size(0) == w.size(0)) {
    nx = temp0.size(0) * 3;
    temp0.set_size(temp0.size(0), 3);
    for (i3 = 0; i3 < nx; i3++) {
      temp0[i3] = temp0[i3] - w[i3];
    }
  } else {
    minus(temp0, w);
  }
  bsxmul(thd2, u, b);
  nx = udot.size(0);
  iNext = thd1_tmp.size(0);
  if (nx <= iNext) {
    iNext = nx;
  }
  if (udot.size(0) == 1) {
    iNext = thd1_tmp.size(0);
  } else if (thd1_tmp.size(0) == 1) {
    iNext = udot.size(0);
  } else if (thd1_tmp.size(0) == udot.size(0)) {
    iNext = thd1_tmp.size(0);
  }
  r.set_size(iNext, 3);
  nx = udot.size(0);
  iNext = thd1_tmp.size(0);
  if (nx <= iNext) {
    iNext = nx;
  }
  if (udot.size(0) == 1) {
    iNext = thd1_tmp.size(0);
  } else if (thd1_tmp.size(0) == 1) {
    iNext = udot.size(0);
  } else if (thd1_tmp.size(0) == udot.size(0)) {
    iNext = thd1_tmp.size(0);
  }
  if (iNext != 0) {
    nx = (thd1_tmp.size(0) != 1);
    iNext = (udot.size(0) != 1);
    for (k = 0; k < 3; k++) {
      i3 = r.size(0) - 1;
      for (i2 = 0; i2 <= i3; i2++) {
        r[i2 + r.size(0) * k] =
            thd1_tmp[nx * i2] * udot[iNext * i2 + udot.size(0) * k];
      }
    }
  }
  c.set_size(angVel.size(0), 3);
  if (angVel.size(0) != 0) {
    nx = angVel.size(0);
    iNext = angVel.size(0) * 3;
    for (k = 1; iNext < 0 ? k >= 1 : k <= 1; k += iNext) {
      for (i1 = 1; i1 <= nx; i1++) {
        i2 = (i1 + nx) - 1;
        i3 = i2 + nx;
        c[i1 - 1] = angVel[i2] * temp0[i3] - angVel[i3] * temp0[i2];
        c[i2] = angVel[i3] * temp0[i1 - 1] - angVel[i1 - 1] * temp0[i3];
        c[i3] = angVel[i1 - 1] * temp0[i2] - angVel[i2] * temp0[i1 - 1];
      }
    }
  }
  bsxmul(sa, wd1xu, angAcc);
  b_ca.set_size(ca.size(0), ca.size(1));
  nx = ca.size(0) * ca.size(1);
  for (i3 = 0; i3 < nx; i3++) {
    b_ca[i3] = 1.0 - ca[i3];
  }
  bsxmul(b_ca, wd1, r3);
  if (b.size(0) == 1) {
    iNext = angAcc.size(0);
  } else {
    iNext = b.size(0);
  }
  if (b.size(0) == 1) {
    nx = angAcc.size(0);
  } else {
    nx = b.size(0);
  }
  if (nx == 1) {
    nx = r3.size(0);
  } else if (b.size(0) == 1) {
    nx = angAcc.size(0);
  } else {
    nx = b.size(0);
  }
  if (b.size(0) == 1) {
    i3 = angAcc.size(0);
  } else {
    i3 = b.size(0);
  }
  if (i3 == 1) {
    i3 = r3.size(0);
  } else if (b.size(0) == 1) {
    i3 = angAcc.size(0);
  } else {
    i3 = b.size(0);
  }
  if (b.size(0) == 1) {
    k = angAcc.size(0);
  } else {
    k = b.size(0);
  }
  if (i3 == 1) {
    i3 = r.size(0);
  } else if (k == 1) {
    i3 = r3.size(0);
  } else if (b.size(0) == 1) {
    i3 = angAcc.size(0);
  } else {
    i3 = b.size(0);
  }
  if ((b.size(0) == angAcc.size(0)) && (iNext == r3.size(0)) &&
      (nx == r.size(0)) && (i3 == c.size(0))) {
    nx = b.size(0) * 3;
    angAcc.set_size(b.size(0), 3);
    for (i3 = 0; i3 < nx; i3++) {
      angAcc[i3] = (((b[i3] + angAcc[i3]) - r3[i3]) + r[i3]) + c[i3];
    }
  } else {
    f_binary_expand_op(angAcc, b, r3, r, c);
  }
  wd2.set_size(w.size(0), 3);
  nx = w.size(0) * 3;
  for (i3 = 0; i3 < nx; i3++) {
    wd2[i3] = w[i3] * w[i3];
  }
  if (wd2.size(0) == 0) {
    w2.set_size(0);
  } else {
    iNext = wd2.size(0);
    w2.set_size(wd2.size(0));
    for (i2 = 0; i2 < iNext; i2++) {
      w2[i2] = wd2[i2];
    }
    for (k = 0; k < 2; k++) {
      nx = (k + 1) * iNext;
      for (i2 = 0; i2 < iNext; i2++) {
        w2[i2] = w2[i2] + wd2[nx + i2];
      }
    }
  }
  wd2.set_size(th1.size(0), 3);
  nx = th1.size(0) * 3;
  for (i3 = 0; i3 < nx; i3++) {
    wd2[i3] = th1[i3] * th1[i3];
  }
  if (wd2.size(0) == 0) {
    x.set_size(0);
  } else {
    iNext = wd2.size(0);
    x.set_size(wd2.size(0));
    for (i2 = 0; i2 < iNext; i2++) {
      x[i2] = wd2[i2];
    }
    for (k = 0; k < 2; k++) {
      nx = (k + 1) * iNext;
      for (i2 = 0; i2 < iNext; i2++) {
        x[i2] = x[i2] + wd2[nx + i2];
      }
    }
  }
  wwd.set_size(w.size(0));
  iNext = w.size(0);
  i1 = -1;
  for (nx = 0; nx < iNext; nx++) {
    i1++;
    wwd[nx] = (w[i1] * wd1[i1] + w[i1 + iNext] * wd1[i1 + iNext]) +
              w[i1 + (iNext << 1)] * wd1[i1 + (iNext << 1)];
  }
  c.set_size(th1.size(0), 3);
  if (th1.size(0) != 0) {
    nx = th1.size(0);
    iNext = th1.size(0) * 3;
    for (k = 1; iNext < 0 ? k >= 1 : k <= 1; k += iNext) {
      for (i1 = 1; i1 <= nx; i1++) {
        i2 = (i1 + nx) - 1;
        i3 = i2 + nx;
        c[i1 - 1] = th1[i2] * th2[i3] - th1[i3] * th2[i2];
        c[i2] = th1[i3] * th2[i1 - 1] - th1[i1 - 1] * th2[i3];
        c[i3] = th1[i1 - 1] * th2[i2] - th1[i2] * th2[i1 - 1];
      }
    }
  }
  b_c.set_size(u.size(0), 3);
  if (u.size(0) != 0) {
    nx = u.size(0);
    iNext = u.size(0) * 3;
    for (k = 1; iNext < 0 ? k >= 1 : k <= 1; k += iNext) {
      for (i1 = 1; i1 <= nx; i1++) {
        i2 = (i1 + nx) - 1;
        i3 = i2 + nx;
        b_c[i1 - 1] = u[i2] * th3[i3] - u[i3] * th3[i2];
        b_c[i2] = u[i3] * th3[i1 - 1] - u[i1 - 1] * th3[i3];
        b_c[i3] = u[i1 - 1] * th3[i2] - u[i2] * th3[i1 - 1];
      }
    }
  }
  bsxdiv(c, ang, r3);
  if (x.size(0) == 1) {
    iNext = ang.size(0);
  } else {
    iNext = x.size(0);
  }
  if ((x.size(0) == ang.size(0)) && (iNext == r1.size(0))) {
    b_ca.set_size(x.size(0), ang.size(1));
    nx = ang.size(1);
    for (i3 = 0; i3 < nx; i3++) {
      iNext = x.size(0);
      for (i2 = 0; i2 < iNext; i2++) {
        b_ca[i2 + b_ca.size(0) * i3] =
            2.0 * (x[i2] / ang[i2 + ang.size(0) * i3] + r1[i2]);
      }
    }
    bsxmul(b_ca, w, r4);
  } else {
    binary_expand_op(r4, x, ang, r1, w);
  }
  r1.set_size(thd1_tmp.size(0));
  nx = thd1_tmp.size(0);
  for (i3 = 0; i3 < nx; i3++) {
    r1[i3] = 4.0 * thd1_tmp[i3];
  }
  nx = wd1.size(0);
  iNext = r1.size(0);
  if (nx <= iNext) {
    iNext = nx;
  }
  if (wd1.size(0) == 1) {
    iNext = r1.size(0);
  } else if (r1.size(0) == 1) {
    iNext = wd1.size(0);
  } else if (r1.size(0) == wd1.size(0)) {
    iNext = r1.size(0);
  }
  c.set_size(iNext, 3);
  nx = wd1.size(0);
  iNext = r1.size(0);
  if (nx <= iNext) {
    iNext = nx;
  }
  if (wd1.size(0) == 1) {
    iNext = r1.size(0);
  } else if (r1.size(0) == 1) {
    iNext = wd1.size(0);
  } else if (r1.size(0) == wd1.size(0)) {
    iNext = r1.size(0);
  }
  if (iNext != 0) {
    nx = (r1.size(0) != 1);
    iNext = (wd1.size(0) != 1);
    for (k = 0; k < 3; k++) {
      i3 = c.size(0) - 1;
      for (i2 = 0; i2 <= i3; i2++) {
        c[i2 + c.size(0) * k] = r1[nx * i2] * wd1[iNext * i2 + wd1.size(0) * k];
      }
    }
  }
  if (r3.size(0) == 1) {
    iNext = b_c.size(0);
  } else {
    iNext = r3.size(0);
  }
  if (r3.size(0) == 1) {
    nx = b_c.size(0);
  } else {
    nx = r3.size(0);
  }
  if (nx == 1) {
    nx = r4.size(0);
  } else if (r3.size(0) == 1) {
    nx = b_c.size(0);
  } else {
    nx = r3.size(0);
  }
  if ((r3.size(0) == b_c.size(0)) && (iNext == r4.size(0)) &&
      (nx == c.size(0))) {
    c_c.set_size(r3.size(0), 3);
    nx = r3.size(0) * 3;
    for (i3 = 0; i3 < nx; i3++) {
      c_c[i3] = ((r3[i3] + b_c[i3]) - r4[i3]) - c[i3];
    }
    bsxdiv(c_c, ang, wd2);
  } else {
    binary_expand_op(wd2, r3, b_c, r4, c, ang);
  }
  c.set_size(wd2.size(0), 3);
  if (wd2.size(0) != 0) {
    nx = wd2.size(0);
    iNext = wd2.size(0) * 3;
    for (k = 1; iNext < 0 ? k >= 1 : k <= 1; k += iNext) {
      for (i1 = 1; i1 <= nx; i1++) {
        i2 = (i1 + nx) - 1;
        i3 = i2 + nx;
        c[i1 - 1] = wd2[i2] * u[i3] - wd2[i3] * u[i2];
        c[i2] = wd2[i3] * u[i1 - 1] - wd2[i1 - 1] * u[i3];
        c[i3] = wd2[i1 - 1] * u[i2] - wd2[i2] * u[i1 - 1];
      }
    }
  }
  if (b.size(0) == 1) {
    iNext = r.size(0);
  } else {
    iNext = b.size(0);
  }
  if ((b.size(0) == r.size(0)) && (iNext == wd1.size(0))) {
    nx = b.size(0) * 3;
    b.set_size(b.size(0), 3);
    for (i3 = 0; i3 < nx; i3++) {
      b[i3] = (b[i3] + r[i3]) - wd1[i3];
    }
  } else {
    e_binary_expand_op(b, r, wd1);
  }
  b_c.set_size(angVel.size(0), 3);
  if (angVel.size(0) != 0) {
    nx = angVel.size(0);
    iNext = angVel.size(0) * 3;
    for (k = 1; iNext < 0 ? k >= 1 : k <= 1; k += iNext) {
      for (i1 = 1; i1 <= nx; i1++) {
        i2 = (i1 + nx) - 1;
        i3 = i2 + nx;
        b_c[i1 - 1] = angVel[i2] * b[i3] - angVel[i3] * b[i2];
        b_c[i2] = angVel[i3] * b[i1 - 1] - angVel[i1 - 1] * b[i3];
        b_c[i3] = angVel[i1 - 1] * b[i2] - angVel[i2] * b[i1 - 1];
      }
    }
  }
  b.set_size(angAcc.size(0), 3);
  if (angAcc.size(0) != 0) {
    nx = angAcc.size(0);
    iNext = angAcc.size(0) * 3;
    for (k = 1; iNext < 0 ? k >= 1 : k <= 1; k += iNext) {
      for (i1 = 1; i1 <= nx; i1++) {
        i2 = (i1 + nx) - 1;
        i3 = i2 + nx;
        b[i1 - 1] = angAcc[i2] * temp0[i3] - angAcc[i3] * temp0[i2];
        b[i2] = angAcc[i3] * temp0[i1 - 1] - angAcc[i1 - 1] * temp0[i3];
        b[i3] = angAcc[i1 - 1] * temp0[i2] - angAcc[i2] * temp0[i1 - 1];
      }
    }
  }
  dot(wd1xu, th1, r1);
  dot(udot, th2, x);
  dot(u, th3, r2);
  if (w2.size(0) == 1) {
    iNext = thd1_tmp.size(0);
  } else {
    iNext = w2.size(0);
  }
  if (r1.size(0) == 1) {
    if (w2.size(0) == 1) {
      nx = thd1_tmp.size(0);
    } else {
      nx = w2.size(0);
    }
  } else {
    nx = r1.size(0);
  }
  if (r1.size(0) == 1) {
    if (w2.size(0) == 1) {
      i3 = thd1_tmp.size(0);
    } else {
      i3 = w2.size(0);
    }
  } else {
    i3 = r1.size(0);
  }
  if (i3 == 1) {
    i3 = x.size(0);
  } else if (r1.size(0) == 1) {
    if (w2.size(0) == 1) {
      i3 = thd1_tmp.size(0);
    } else {
      i3 = w2.size(0);
    }
  } else {
    i3 = r1.size(0);
  }
  if ((w2.size(0) == thd1_tmp.size(0)) && (r1.size(0) == iNext) &&
      (nx == x.size(0)) && (i3 == r2.size(0))) {
    nx = r1.size(0);
    for (i3 = 0; i3 < nx; i3++) {
      r1[i3] = ((r1[i3] - w2[i3] * thd1_tmp[i3]) + 2.0 * x[i3]) + r2[i3];
    }
    bsxmul(r1, u, angJerk);
  } else {
    binary_expand_op(angJerk, r1, w2, thd1_tmp, x, r2, u);
  }
  bsxmul(sa, c, r);
  b_ca.set_size(ca.size(0), ca.size(1));
  nx = ca.size(0) * ca.size(1);
  for (i3 = 0; i3 < nx; i3++) {
    b_ca[i3] = 1.0 - ca[i3];
  }
  bsxmul(b_ca, wd2, r3);
  nx = thd2.size(0);
  for (i3 = 0; i3 < nx; i3++) {
    thd2[i3] = 2.0 * thd2[i3];
  }
  nx = udot.size(0);
  iNext = thd2.size(0);
  if (nx <= iNext) {
    iNext = nx;
  }
  if (udot.size(0) == 1) {
    iNext = thd2.size(0);
  } else if (thd2.size(0) == 1) {
    iNext = udot.size(0);
  } else if (thd2.size(0) == udot.size(0)) {
    iNext = thd2.size(0);
  }
  r4.set_size(iNext, 3);
  nx = udot.size(0);
  iNext = thd2.size(0);
  if (nx <= iNext) {
    iNext = nx;
  }
  if (udot.size(0) == 1) {
    iNext = thd2.size(0);
  } else if (thd2.size(0) == 1) {
    iNext = udot.size(0);
  } else if (thd2.size(0) == udot.size(0)) {
    iNext = thd2.size(0);
  }
  if (iNext != 0) {
    nx = (thd2.size(0) != 1);
    iNext = (udot.size(0) != 1);
    for (k = 0; k < 3; k++) {
      i3 = r4.size(0) - 1;
      for (i2 = 0; i2 <= i3; i2++) {
        r4[i2 + r4.size(0) * k] =
            thd2[nx * i2] * udot[iNext * i2 + udot.size(0) * k];
      }
    }
  }
  b_ca.set_size(ca.size(0), ca.size(1));
  nx = ca.size(0) * ca.size(1);
  for (i3 = 0; i3 < nx; i3++) {
    b_ca[i3] = ca[i3] + 1.0;
  }
  bsxmul(b_ca, wd1xu, c);
  bsxmul(w2, u, wd2);
  bsxmul(sa, wd1, w);
  if (c.size(0) == 1) {
    iNext = wd2.size(0);
  } else {
    iNext = c.size(0);
  }
  if ((c.size(0) == wd2.size(0)) && (iNext == w.size(0))) {
    c_c.set_size(c.size(0), 3);
    nx = c.size(0) * 3;
    for (i3 = 0; i3 < nx; i3++) {
      c_c[i3] = (c[i3] - wd2[i3]) - w[i3];
    }
    nx = c_c.size(0);
    iNext = thd1_tmp.size(0);
    if (nx <= iNext) {
      iNext = nx;
    }
    if (c_c.size(0) == 1) {
      iNext = thd1_tmp.size(0);
    } else if (thd1_tmp.size(0) == 1) {
      iNext = c_c.size(0);
    } else if (thd1_tmp.size(0) == c_c.size(0)) {
      iNext = thd1_tmp.size(0);
    }
    c.set_size(iNext, 3);
    nx = c_c.size(0);
    iNext = thd1_tmp.size(0);
    if (nx <= iNext) {
      iNext = nx;
    }
    if (c_c.size(0) == 1) {
      iNext = thd1_tmp.size(0);
    } else if (thd1_tmp.size(0) == 1) {
      iNext = c_c.size(0);
    } else if (thd1_tmp.size(0) == c_c.size(0)) {
      iNext = thd1_tmp.size(0);
    }
    if (iNext != 0) {
      nx = (thd1_tmp.size(0) != 1);
      iNext = (c_c.size(0) != 1);
      for (k = 0; k < 3; k++) {
        i3 = c.size(0) - 1;
        for (i2 = 0; i2 <= i3; i2++) {
          c[i2 + c.size(0) * k] =
              thd1_tmp[nx * i2] * c_c[iNext * i2 + c_c.size(0) * k];
        }
      }
    }
  } else {
    e_binary_expand_op(c, thd1_tmp, wd2, w);
  }
  if (wwd.size(0) == sa.size(0)) {
    ca.set_size(wwd.size(0), sa.size(1));
    nx = sa.size(1);
    for (i3 = 0; i3 < nx; i3++) {
      iNext = wwd.size(0);
      for (i2 = 0; i2 < iNext; i2++) {
        ca[i2 + ca.size(0) * i3] = wwd[i2] * sa[i2 + sa.size(0) * i3];
      }
    }
    sa.set_size(ca.size(0), ca.size(1));
    nx = ca.size(1);
    for (i3 = 0; i3 < nx; i3++) {
      iNext = ca.size(0);
      for (i2 = 0; i2 < iNext; i2++) {
        sa[i2 + sa.size(0) * i3] = ca[i2 + ca.size(0) * i3];
      }
    }
    bsxmul(sa, u, wd2);
  } else {
    binary_expand_op(wd2, wwd, sa, u);
  }
  if (angJerk.size(0) == 1) {
    iNext = r.size(0);
  } else {
    iNext = angJerk.size(0);
  }
  if (angJerk.size(0) == 1) {
    nx = r.size(0);
  } else {
    nx = angJerk.size(0);
  }
  if (nx == 1) {
    nx = r3.size(0);
  } else if (angJerk.size(0) == 1) {
    nx = r.size(0);
  } else {
    nx = angJerk.size(0);
  }
  if (angJerk.size(0) == 1) {
    i3 = r.size(0);
  } else {
    i3 = angJerk.size(0);
  }
  if (i3 == 1) {
    i3 = r3.size(0);
  } else if (angJerk.size(0) == 1) {
    i3 = r.size(0);
  } else {
    i3 = angJerk.size(0);
  }
  if (angJerk.size(0) == 1) {
    k = r.size(0);
  } else {
    k = angJerk.size(0);
  }
  if (i3 == 1) {
    i3 = r4.size(0);
  } else if (k == 1) {
    i3 = r3.size(0);
  } else if (angJerk.size(0) == 1) {
    i3 = r.size(0);
  } else {
    i3 = angJerk.size(0);
  }
  if (angJerk.size(0) == 1) {
    k = r.size(0);
  } else {
    k = angJerk.size(0);
  }
  if (k == 1) {
    k = r3.size(0);
  } else if (angJerk.size(0) == 1) {
    k = r.size(0);
  } else {
    k = angJerk.size(0);
  }
  if (angJerk.size(0) == 1) {
    i1 = r.size(0);
  } else {
    i1 = angJerk.size(0);
  }
  if (k == 1) {
    k = r4.size(0);
  } else if (i1 == 1) {
    k = r3.size(0);
  } else if (angJerk.size(0) == 1) {
    k = r.size(0);
  } else {
    k = angJerk.size(0);
  }
  if (angJerk.size(0) == 1) {
    i1 = r.size(0);
  } else {
    i1 = angJerk.size(0);
  }
  if (i1 == 1) {
    i1 = r3.size(0);
  } else if (angJerk.size(0) == 1) {
    i1 = r.size(0);
  } else {
    i1 = angJerk.size(0);
  }
  if (angJerk.size(0) == 1) {
    i2 = r.size(0);
  } else {
    i2 = angJerk.size(0);
  }
  if (k == 1) {
    k = c.size(0);
  } else if (i1 == 1) {
    k = r4.size(0);
  } else if (i2 == 1) {
    k = r3.size(0);
  } else if (angJerk.size(0) == 1) {
    k = r.size(0);
  } else {
    k = angJerk.size(0);
  }
  if (angJerk.size(0) == 1) {
    i1 = r.size(0);
  } else {
    i1 = angJerk.size(0);
  }
  if (i1 == 1) {
    i1 = r3.size(0);
  } else if (angJerk.size(0) == 1) {
    i1 = r.size(0);
  } else {
    i1 = angJerk.size(0);
  }
  if (angJerk.size(0) == 1) {
    i2 = r.size(0);
  } else {
    i2 = angJerk.size(0);
  }
  if (i1 == 1) {
    i1 = r4.size(0);
  } else if (i2 == 1) {
    i1 = r3.size(0);
  } else if (angJerk.size(0) == 1) {
    i1 = r.size(0);
  } else {
    i1 = angJerk.size(0);
  }
  if (angJerk.size(0) == 1) {
    i2 = r.size(0);
  } else {
    i2 = angJerk.size(0);
  }
  if (i2 == 1) {
    i2 = r3.size(0);
  } else if (angJerk.size(0) == 1) {
    i2 = r.size(0);
  } else {
    i2 = angJerk.size(0);
  }
  if (angJerk.size(0) == 1) {
    i = r.size(0);
  } else {
    i = angJerk.size(0);
  }
  if (i1 == 1) {
    i1 = c.size(0);
  } else if (i2 == 1) {
    i1 = r4.size(0);
  } else if (i == 1) {
    i1 = r3.size(0);
  } else if (angJerk.size(0) == 1) {
    i1 = r.size(0);
  } else {
    i1 = angJerk.size(0);
  }
  if (angJerk.size(0) == 1) {
    i2 = r.size(0);
  } else {
    i2 = angJerk.size(0);
  }
  if (i2 == 1) {
    i2 = r3.size(0);
  } else if (angJerk.size(0) == 1) {
    i2 = r.size(0);
  } else {
    i2 = angJerk.size(0);
  }
  if (angJerk.size(0) == 1) {
    i = r.size(0);
  } else {
    i = angJerk.size(0);
  }
  if (i2 == 1) {
    i2 = r4.size(0);
  } else if (i == 1) {
    i2 = r3.size(0);
  } else if (angJerk.size(0) == 1) {
    i2 = r.size(0);
  } else {
    i2 = angJerk.size(0);
  }
  if (angJerk.size(0) == 1) {
    i = r.size(0);
  } else {
    i = angJerk.size(0);
  }
  if (i == 1) {
    i = r3.size(0);
  } else if (angJerk.size(0) == 1) {
    i = r.size(0);
  } else {
    i = angJerk.size(0);
  }
  if (angJerk.size(0) == 1) {
    b_i1 = r.size(0);
  } else {
    b_i1 = angJerk.size(0);
  }
  if (i1 == 1) {
    i1 = wd2.size(0);
  } else if (i2 == 1) {
    i1 = c.size(0);
  } else if (i == 1) {
    i1 = r4.size(0);
  } else if (b_i1 == 1) {
    i1 = r3.size(0);
  } else if (angJerk.size(0) == 1) {
    i1 = r.size(0);
  } else {
    i1 = angJerk.size(0);
  }
  if (angJerk.size(0) == 1) {
    i2 = r.size(0);
  } else {
    i2 = angJerk.size(0);
  }
  if (i2 == 1) {
    i2 = r3.size(0);
  } else if (angJerk.size(0) == 1) {
    i2 = r.size(0);
  } else {
    i2 = angJerk.size(0);
  }
  if (angJerk.size(0) == 1) {
    i = r.size(0);
  } else {
    i = angJerk.size(0);
  }
  if (i2 == 1) {
    i2 = r4.size(0);
  } else if (i == 1) {
    i2 = r3.size(0);
  } else if (angJerk.size(0) == 1) {
    i2 = r.size(0);
  } else {
    i2 = angJerk.size(0);
  }
  if (angJerk.size(0) == 1) {
    i = r.size(0);
  } else {
    i = angJerk.size(0);
  }
  if (i == 1) {
    i = r3.size(0);
  } else if (angJerk.size(0) == 1) {
    i = r.size(0);
  } else {
    i = angJerk.size(0);
  }
  if (angJerk.size(0) == 1) {
    b_i1 = r.size(0);
  } else {
    b_i1 = angJerk.size(0);
  }
  if (i2 == 1) {
    i2 = c.size(0);
  } else if (i == 1) {
    i2 = r4.size(0);
  } else if (b_i1 == 1) {
    i2 = r3.size(0);
  } else if (angJerk.size(0) == 1) {
    i2 = r.size(0);
  } else {
    i2 = angJerk.size(0);
  }
  if (angJerk.size(0) == 1) {
    i = r.size(0);
  } else {
    i = angJerk.size(0);
  }
  if (i == 1) {
    i = r3.size(0);
  } else if (angJerk.size(0) == 1) {
    i = r.size(0);
  } else {
    i = angJerk.size(0);
  }
  if (angJerk.size(0) == 1) {
    b_i1 = r.size(0);
  } else {
    b_i1 = angJerk.size(0);
  }
  if (i == 1) {
    i = r4.size(0);
  } else if (b_i1 == 1) {
    i = r3.size(0);
  } else if (angJerk.size(0) == 1) {
    i = r.size(0);
  } else {
    i = angJerk.size(0);
  }
  if (angJerk.size(0) == 1) {
    b_i1 = r.size(0);
  } else {
    b_i1 = angJerk.size(0);
  }
  if (b_i1 == 1) {
    b_i1 = r3.size(0);
  } else if (angJerk.size(0) == 1) {
    b_i1 = r.size(0);
  } else {
    b_i1 = angJerk.size(0);
  }
  if (angJerk.size(0) == 1) {
    b_i2 = r.size(0);
  } else {
    b_i2 = angJerk.size(0);
  }
  if (i2 == 1) {
    i2 = wd2.size(0);
  } else if (i == 1) {
    i2 = c.size(0);
  } else if (b_i1 == 1) {
    i2 = r4.size(0);
  } else if (b_i2 == 1) {
    i2 = r3.size(0);
  } else if (angJerk.size(0) == 1) {
    i2 = r.size(0);
  } else {
    i2 = angJerk.size(0);
  }
  if (angJerk.size(0) == 1) {
    i = r.size(0);
  } else {
    i = angJerk.size(0);
  }
  if (i == 1) {
    i = r3.size(0);
  } else if (angJerk.size(0) == 1) {
    i = r.size(0);
  } else {
    i = angJerk.size(0);
  }
  if (angJerk.size(0) == 1) {
    b_i1 = r.size(0);
  } else {
    b_i1 = angJerk.size(0);
  }
  if (i == 1) {
    i = r4.size(0);
  } else if (b_i1 == 1) {
    i = r3.size(0);
  } else if (angJerk.size(0) == 1) {
    i = r.size(0);
  } else {
    i = angJerk.size(0);
  }
  if (angJerk.size(0) == 1) {
    b_i1 = r.size(0);
  } else {
    b_i1 = angJerk.size(0);
  }
  if (b_i1 == 1) {
    b_i1 = r3.size(0);
  } else if (angJerk.size(0) == 1) {
    b_i1 = r.size(0);
  } else {
    b_i1 = angJerk.size(0);
  }
  if (angJerk.size(0) == 1) {
    b_i2 = r.size(0);
  } else {
    b_i2 = angJerk.size(0);
  }
  if (i == 1) {
    i = c.size(0);
  } else if (b_i1 == 1) {
    i = r4.size(0);
  } else if (b_i2 == 1) {
    i = r3.size(0);
  } else if (angJerk.size(0) == 1) {
    i = r.size(0);
  } else {
    i = angJerk.size(0);
  }
  if (angJerk.size(0) == 1) {
    b_i1 = r.size(0);
  } else {
    b_i1 = angJerk.size(0);
  }
  if (b_i1 == 1) {
    b_i1 = r3.size(0);
  } else if (angJerk.size(0) == 1) {
    b_i1 = r.size(0);
  } else {
    b_i1 = angJerk.size(0);
  }
  if (angJerk.size(0) == 1) {
    b_i2 = r.size(0);
  } else {
    b_i2 = angJerk.size(0);
  }
  if (b_i1 == 1) {
    b_i1 = r4.size(0);
  } else if (b_i2 == 1) {
    b_i1 = r3.size(0);
  } else if (angJerk.size(0) == 1) {
    b_i1 = r.size(0);
  } else {
    b_i1 = angJerk.size(0);
  }
  if (angJerk.size(0) == 1) {
    b_i2 = r.size(0);
  } else {
    b_i2 = angJerk.size(0);
  }
  if (b_i2 == 1) {
    b_i2 = r3.size(0);
  } else if (angJerk.size(0) == 1) {
    b_i2 = r.size(0);
  } else {
    b_i2 = angJerk.size(0);
  }
  if (angJerk.size(0) == 1) {
    b_i3 = r.size(0);
  } else {
    b_i3 = angJerk.size(0);
  }
  if (i2 == 1) {
    i2 = b_c.size(0);
  } else if (i == 1) {
    i2 = wd2.size(0);
  } else if (b_i1 == 1) {
    i2 = c.size(0);
  } else if (b_i2 == 1) {
    i2 = r4.size(0);
  } else if (b_i3 == 1) {
    i2 = r3.size(0);
  } else if (angJerk.size(0) == 1) {
    i2 = r.size(0);
  } else {
    i2 = angJerk.size(0);
  }
  if ((angJerk.size(0) == r.size(0)) && (iNext == r3.size(0)) &&
      (nx == r4.size(0)) && (i3 == c.size(0)) && (k == wd2.size(0)) &&
      (i1 == b_c.size(0)) && (i2 == b.size(0))) {
    nx = angJerk.size(0) * 3;
    angJerk.set_size(angJerk.size(0), 3);
    for (i3 = 0; i3 < nx; i3++) {
      angJerk[i3] =
          ((((((angJerk[i3] + r[i3]) - r3[i3]) + r4[i3]) + c[i3]) - wd2[i3]) +
           b_c[i3]) +
          b[i3];
    }
  } else {
    binary_expand_op(angJerk, r, r3, r4, c, wd2, b_c, b);
  }
}

//
// Arguments    : const ::coder::array<double, 2U> &x
//                const ::coder::array<double, 2U> &y
//                ::coder::array<double, 2U> &z
// Return Type  : void
//
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
// Arguments    : const ::coder::array<double, 1U> &x
//                const ::coder::array<double, 2U> &y
//                ::coder::array<double, 2U> &z
// Return Type  : void
//
static void bsxmul(const ::coder::array<double, 1U> &x,
                   const ::coder::array<double, 2U> &y,
                   ::coder::array<double, 2U> &z)
{
  int acoef;
  int bcoef;
  acoef = y.size(0);
  bcoef = x.size(0);
  if (acoef <= bcoef) {
    bcoef = acoef;
  }
  if (y.size(0) == 1) {
    bcoef = x.size(0);
  } else if (x.size(0) == 1) {
    bcoef = y.size(0);
  } else if (x.size(0) == y.size(0)) {
    bcoef = x.size(0);
  }
  z.set_size(bcoef, 3);
  acoef = y.size(0);
  bcoef = x.size(0);
  if (acoef <= bcoef) {
    bcoef = acoef;
  }
  if (y.size(0) == 1) {
    bcoef = x.size(0);
  } else if (x.size(0) == 1) {
    bcoef = y.size(0);
  } else if (x.size(0) == y.size(0)) {
    bcoef = x.size(0);
  }
  if (bcoef != 0) {
    acoef = (x.size(0) != 1);
    bcoef = (y.size(0) != 1);
    for (int k{0}; k < 3; k++) {
      int i;
      i = z.size(0) - 1;
      for (int b_k{0}; b_k <= i; b_k++) {
        z[b_k + z.size(0) * k] =
            x[acoef * b_k] * y[bcoef * b_k + y.size(0) * k];
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
// Arguments    : coder::array<double, 2U> &in1
//                const coder::array<double, 2U> &in2
//                const coder::array<double, 2U> &in3
// Return Type  : void
//
} // namespace internal
} // namespace scenario
} // namespace fusion
} // namespace coder
static void e_binary_expand_op(coder::array<double, 2U> &in1,
                               const coder::array<double, 2U> &in2,
                               const coder::array<double, 2U> &in3)
{
  coder::array<double, 2U> b_in1;
  int i;
  int loop_ub;
  int stride_0_0;
  int stride_1_0;
  int stride_2_0;
  if (in3.size(0) == 1) {
    if (in2.size(0) == 1) {
      i = in1.size(0);
    } else {
      i = in2.size(0);
    }
  } else {
    i = in3.size(0);
  }
  b_in1.set_size(i, 3);
  stride_0_0 = (in1.size(0) != 1);
  stride_1_0 = (in2.size(0) != 1);
  stride_2_0 = (in3.size(0) != 1);
  if (in3.size(0) == 1) {
    if (in2.size(0) == 1) {
      loop_ub = in1.size(0);
    } else {
      loop_ub = in2.size(0);
    }
  } else {
    loop_ub = in3.size(0);
  }
  for (i = 0; i < 3; i++) {
    for (int i1{0}; i1 < loop_ub; i1++) {
      b_in1[i1 + b_in1.size(0) * i] = (in1[i1 * stride_0_0 + in1.size(0) * i] +
                                       in2[i1 * stride_1_0 + in2.size(0) * i]) -
                                      in3[i1 * stride_2_0 + in3.size(0) * i];
    }
  }
  in1.set_size(b_in1.size(0), 3);
  loop_ub = b_in1.size(0);
  for (i = 0; i < 3; i++) {
    for (int i1{0}; i1 < loop_ub; i1++) {
      in1[i1 + in1.size(0) * i] = b_in1[i1 + b_in1.size(0) * i];
    }
  }
}

//
// Arguments    : coder::array<double, 2U> &in1
//                const coder::array<double, 1U> &in2
//                const coder::array<double, 2U> &in3
//                const coder::array<double, 2U> &in4
// Return Type  : void
//
static void e_binary_expand_op(coder::array<double, 2U> &in1,
                               const coder::array<double, 1U> &in2,
                               const coder::array<double, 2U> &in3,
                               const coder::array<double, 2U> &in4)
{
  coder::array<double, 2U> b_in1;
  int i;
  int loop_ub;
  int stride_0_0;
  int stride_1_0;
  int stride_2_0;
  if (in4.size(0) == 1) {
    if (in3.size(0) == 1) {
      i = in1.size(0);
    } else {
      i = in3.size(0);
    }
  } else {
    i = in4.size(0);
  }
  b_in1.set_size(i, 3);
  stride_0_0 = (in1.size(0) != 1);
  stride_1_0 = (in3.size(0) != 1);
  stride_2_0 = (in4.size(0) != 1);
  if (in4.size(0) == 1) {
    if (in3.size(0) == 1) {
      loop_ub = in1.size(0);
    } else {
      loop_ub = in3.size(0);
    }
  } else {
    loop_ub = in4.size(0);
  }
  for (i = 0; i < 3; i++) {
    for (int i1{0}; i1 < loop_ub; i1++) {
      b_in1[i1 + b_in1.size(0) * i] = (in1[i1 * stride_0_0 + in1.size(0) * i] -
                                       in3[i1 * stride_1_0 + in3.size(0) * i]) -
                                      in4[i1 * stride_2_0 + in4.size(0) * i];
    }
  }
  coder::fusion::scenario::internal::bsxmul(in2, b_in1, in1);
}

//
// Arguments    : coder::array<double, 2U> &in1
//                const coder::array<double, 2U> &in2
//                const coder::array<double, 2U> &in3
//                const coder::array<double, 2U> &in4
//                const coder::array<double, 2U> &in5
// Return Type  : void
//
static void f_binary_expand_op(coder::array<double, 2U> &in1,
                               const coder::array<double, 2U> &in2,
                               const coder::array<double, 2U> &in3,
                               const coder::array<double, 2U> &in4,
                               const coder::array<double, 2U> &in5)
{
  coder::array<double, 2U> b_in2;
  int i;
  int loop_ub;
  int stride_0_0;
  int stride_1_0;
  int stride_2_0;
  int stride_3_0;
  int stride_4_0;
  if (in5.size(0) == 1) {
    if (in4.size(0) == 1) {
      if (in3.size(0) == 1) {
        if (in1.size(0) == 1) {
          i = in2.size(0);
        } else {
          i = in1.size(0);
        }
      } else {
        i = in3.size(0);
      }
    } else {
      i = in4.size(0);
    }
  } else {
    i = in5.size(0);
  }
  b_in2.set_size(i, 3);
  stride_0_0 = (in2.size(0) != 1);
  stride_1_0 = (in1.size(0) != 1);
  stride_2_0 = (in3.size(0) != 1);
  stride_3_0 = (in4.size(0) != 1);
  stride_4_0 = (in5.size(0) != 1);
  if (in5.size(0) == 1) {
    if (in4.size(0) == 1) {
      if (in3.size(0) == 1) {
        if (in1.size(0) == 1) {
          loop_ub = in2.size(0);
        } else {
          loop_ub = in1.size(0);
        }
      } else {
        loop_ub = in3.size(0);
      }
    } else {
      loop_ub = in4.size(0);
    }
  } else {
    loop_ub = in5.size(0);
  }
  for (i = 0; i < 3; i++) {
    for (int i1{0}; i1 < loop_ub; i1++) {
      b_in2[i1 + b_in2.size(0) * i] =
          (((in2[i1 * stride_0_0 + in2.size(0) * i] +
             in1[i1 * stride_1_0 + in1.size(0) * i]) -
            in3[i1 * stride_2_0 + in3.size(0) * i]) +
           in4[i1 * stride_3_0 + in4.size(0) * i]) +
          in5[i1 * stride_4_0 + in5.size(0) * i];
    }
  }
  in1.set_size(b_in2.size(0), 3);
  loop_ub = b_in2.size(0);
  for (i = 0; i < 3; i++) {
    for (int i1{0}; i1 < loop_ub; i1++) {
      in1[i1 + in1.size(0) * i] = b_in2[i1 + b_in2.size(0) * i];
    }
  }
}

//
// Arguments    : coder::array<double, 2U> &in1
//                const coder::array<double, 2U> &in2
//                const coder::array<double, 2U> &in3
// Return Type  : void
//
static void f_binary_expand_op(coder::array<double, 2U> &in1,
                               const coder::array<double, 2U> &in2,
                               const coder::array<double, 2U> &in3)
{
  coder::array<double, 2U> b_in2;
  int i;
  int loop_ub;
  int stride_0_0;
  int stride_1_0;
  int stride_2_0;
  if (in3.size(0) == 1) {
    if (in1.size(0) == 1) {
      i = in2.size(0);
    } else {
      i = in1.size(0);
    }
  } else {
    i = in3.size(0);
  }
  b_in2.set_size(i, 3);
  stride_0_0 = (in2.size(0) != 1);
  stride_1_0 = (in1.size(0) != 1);
  stride_2_0 = (in3.size(0) != 1);
  if (in3.size(0) == 1) {
    if (in1.size(0) == 1) {
      loop_ub = in2.size(0);
    } else {
      loop_ub = in1.size(0);
    }
  } else {
    loop_ub = in3.size(0);
  }
  for (i = 0; i < 3; i++) {
    for (int i1{0}; i1 < loop_ub; i1++) {
      b_in2[i1 + b_in2.size(0) * i] = (in2[i1 * stride_0_0 + in2.size(0) * i] +
                                       in1[i1 * stride_1_0 + in1.size(0) * i]) -
                                      in3[i1 * stride_2_0 + in3.size(0) * i];
    }
  }
  in1.set_size(b_in2.size(0), 3);
  loop_ub = b_in2.size(0);
  for (i = 0; i < 3; i++) {
    for (int i1{0}; i1 < loop_ub; i1++) {
      in1[i1 + in1.size(0) * i] = b_in2[i1 + b_in2.size(0) * i];
    }
  }
}

//
// Arguments    : coder::array<double, 2U> &in1
//                const coder::array<double, 2U> &in2
// Return Type  : void
//
static void minus(coder::array<double, 2U> &in1,
                  const coder::array<double, 2U> &in2)
{
  coder::array<double, 2U> b_in1;
  int i;
  int loop_ub;
  int stride_0_0;
  int stride_1_0;
  if (in2.size(0) == 1) {
    i = in1.size(0);
  } else {
    i = in2.size(0);
  }
  b_in1.set_size(i, 3);
  stride_0_0 = (in1.size(0) != 1);
  stride_1_0 = (in2.size(0) != 1);
  if (in2.size(0) == 1) {
    loop_ub = in1.size(0);
  } else {
    loop_ub = in2.size(0);
  }
  for (i = 0; i < 3; i++) {
    for (int i1{0}; i1 < loop_ub; i1++) {
      b_in1[i1 + b_in1.size(0) * i] = in1[i1 * stride_0_0 + in1.size(0) * i] -
                                      in2[i1 * stride_1_0 + in2.size(0) * i];
    }
  }
  in1.set_size(b_in1.size(0), 3);
  loop_ub = b_in1.size(0);
  for (i = 0; i < 3; i++) {
    for (int i1{0}; i1 < loop_ub; i1++) {
      in1[i1 + in1.size(0) * i] = b_in1[i1 + b_in1.size(0) * i];
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
namespace coder {
namespace fusion {
namespace scenario {
namespace internal {
void slew3(double t, double dt, const quaternion *qi, const double a[9],
           const double b[9], const double c[6], const double d[3],
           quaternion *q, double angVel[3], double angAcc[3], double angJerk[3])
{
  b_quaternion deltaQ;
  array<double, 2U> b_ang;
  array<double, 2U> b_angAcc;
  array<double, 2U> b_angVel;
  array<double, 2U> b_qimag;
  array<double, 2U> c_d;
  array<double, 2U> r;
  array<double, 2U> r1;
  array<double, 2U> r2;
  array<signed char, 2U> ii;
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
    double qimag[3];
    double ang;
    double b_d;
    double b_t;
    double th0_idx_0;
    double th0_idx_1;
    double x;
    double x2;
    int i;
    int i1;
    int loop_ub;
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
    if (qi->a.size(1) == 1) {
      i = qi->b.size(1);
      i1 = qi->b.size(1);
    } else {
      i = qi->a.size(1);
      i1 = qi->a.size(1);
    }
    if (i1 == 1) {
      i1 = qi->c.size(1);
    } else if (qi->a.size(1) == 1) {
      i1 = qi->b.size(1);
    } else {
      i1 = qi->a.size(1);
    }
    if ((qi->a.size(1) == qi->b.size(1)) && (i == qi->c.size(1)) &&
        (i1 == qi->d.size(1))) {
      q->a.set_size(1, qi->a.size(1));
      loop_ub = qi->a.size(1);
      for (i = 0; i < loop_ub; i++) {
        q->a[i] = ((qi->a[i] * deltaQ.a - qi->b[i] * deltaQ.b) -
                   qi->c[i] * deltaQ.c) -
                  qi->d[i] * deltaQ.d;
      }
      q->b.set_size(1, qi->a.size(1));
      loop_ub = qi->a.size(1);
      for (i = 0; i < loop_ub; i++) {
        q->b[i] = ((qi->a[i] * deltaQ.b + qi->b[i] * deltaQ.a) +
                   qi->c[i] * deltaQ.d) -
                  qi->d[i] * deltaQ.c;
      }
      q->c.set_size(1, qi->a.size(1));
      loop_ub = qi->a.size(1);
      for (i = 0; i < loop_ub; i++) {
        q->c[i] = ((qi->a[i] * deltaQ.c - qi->b[i] * deltaQ.d) +
                   qi->c[i] * deltaQ.a) +
                  qi->d[i] * deltaQ.b;
      }
      q->d.set_size(1, qi->a.size(1));
      loop_ub = qi->a.size(1);
      for (i = 0; i < loop_ub; i++) {
        q->d[i] = ((qi->a[i] * deltaQ.d + qi->b[i] * deltaQ.c) -
                   qi->c[i] * deltaQ.b) +
                  qi->d[i] * deltaQ.a;
      }
    } else {
      g_binary_expand_op(q, qi, deltaQ);
      f_binary_expand_op(q, qi, deltaQ);
      e_binary_expand_op(q, qi, deltaQ);
      binary_expand_op(q, qi, deltaQ);
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
        loop_ub = 0;
      } else {
        loop_ub = 1;
      }
    } else {
      loop_ub = 0;
    }
    for (i = 0; i < 3; i++) {
      if (loop_ub - 1 >= 0) {
        qimag[i] = 0.0;
      }
    }
    angJerk[0] = d[0] - 0.5 * (angVel[1] * angAcc[2] - angAcc[1] * angVel[2]);
    angJerk[1] = d[1] - 0.5 * (angAcc[0] * angVel[2] - angVel[0] * angAcc[2]);
    angJerk[2] = d[2] - 0.5 * (angVel[0] * angAcc[1] - angAcc[0] * angVel[1]);
    if (ang > 1.0E-6) {
      int b_loop_ub;
      int c_loop_ub;
      b_ang.set_size(1, 1);
      b_ang[0] = ang;
      b_angVel.set_size(1, 3);
      b_angAcc.set_size(1, 3);
      c_d.set_size(1, 3);
      b_qimag.set_size(1, 3);
      for (i = 0; i < 3; i++) {
        b_angVel[b_angVel.size(0) * i] = angVel[i];
        b_angAcc[b_angAcc.size(0) * i] = angAcc[i];
        c_d[c_d.size(0) * i] = d[i];
        b_qimag[b_qimag.size(0) * i] = qimag[i];
      }
      angDeriv(b_ang, b_angVel, b_angAcc, c_d, b_qimag, r, r1, r2);
      loop_ub = r.size(0);
      b_loop_ub = r1.size(0);
      c_loop_ub = r2.size(0);
      for (i = 0; i < 3; i++) {
        for (i1 = 0; i1 < loop_ub; i1++) {
          angVel[i] = r[i1 + r.size(0) * i];
        }
        for (i1 = 0; i1 < b_loop_ub; i1++) {
          angAcc[i] = r1[i1 + r1.size(0) * i];
        }
        for (i1 = 0; i1 < c_loop_ub; i1++) {
          angJerk[i] = r2[i1 + r2.size(0) * i];
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
  array<double, 2U> a;
  array<double, 2U> b;
  array<double, 2U> b_e;
  array<double, 2U> bvec2;
  array<double, 2U> r1;
  array<double, 1U> r;
  array<signed char, 2U> ii;
  double bvec[3];
  double d;
  double d1;
  double d2;
  int i;
  int i1;
  int j;
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
    int acoef;
    int varargin_2;
    a.set_size(1, 3);
    for (i = 0; i < 3; i++) {
      a[a.size(0) * i] = e[i];
    }
    b.set_size(1, 3);
    for (i = 0; i < 3; i++) {
      b[b.size(0) * i] = wf[i];
    }
    bvec2.set_size(1, 3);
    bvec2[2] = a[0] * b[1] - b[0] * a[1];
    bvec2[1] = b[0] * a[2] - a[0] * b[2];
    bvec2[0] = a[1] * b[2] - b[1] * a[2];
    b.set_size(1, 3);
    for (i = 0; i < 3; i++) {
      b[b.size(0) * i] = e[i];
    }
    a.set_size(1, 3);
    a[2] = bvec2[0] * b[1] - b[0] * bvec2[1];
    a[1] = b[0] * bvec2[2] - bvec2[0] * b[2];
    a[0] = bvec2[1] * b[2] - b[1] * bvec2[2];
    b_e.set_size(1, 3);
    b.set_size(1, 3);
    for (i = 0; i < 3; i++) {
      b_e[b_e.size(0) * i] = e[i];
      b[b.size(0) * i] = wf[i];
    }
    r.set_size(b_e.size(0));
    vstride = b_e.size(0);
    i1 = -1;
    for (j = 0; j < vstride; j++) {
      i1++;
      r[j] = (b_e[i1] * b[i1] + b_e[i1 + vstride] * b[i1 + vstride]) +
             b_e[i1 + (vstride << 1)] * b[i1 + (vstride << 1)];
    }
    b_e.set_size(1, 3);
    for (i = 0; i < 3; i++) {
      b_e[b_e.size(0) * i] = e[i];
    }
    vstride = b_e.size(0);
    i1 = r.size(0);
    if (vstride <= i1) {
      i1 = vstride;
    }
    if (b_e.size(0) == 1) {
      i1 = r.size(0);
    } else if (r.size(0) == 1) {
      i1 = b_e.size(0);
    } else if (r.size(0) == b_e.size(0)) {
      i1 = r.size(0);
    }
    b.set_size(i1, 3);
    vstride = b_e.size(0);
    i1 = r.size(0);
    if (vstride <= i1) {
      i1 = vstride;
    }
    if (b_e.size(0) == 1) {
      i1 = r.size(0);
    } else if (r.size(0) == 1) {
      i1 = b_e.size(0);
    } else if (r.size(0) == b_e.size(0)) {
      i1 = r.size(0);
    }
    if (i1 != 0) {
      vstride = (r.size(0) != 1);
      i1 = (b_e.size(0) != 1);
      for (j = 0; j < 3; j++) {
        i = b.size(0) - 1;
        for (int k{0}; k <= i; k++) {
          b[k + b.size(0) * j] = r[vstride * k] * b_e[i1 * k + b_e.size(0) * j];
        }
      }
    }
    r1.set_size(1, 1);
    r1[0] = 0.5 * std::sin(dtheta) * dtheta / (1.0 - std::cos(dtheta));
    vstride = a.size(0);
    i1 = r1.size(0);
    if (vstride <= i1) {
      i1 = vstride;
    }
    if (a.size(0) == 1) {
      i1 = r1.size(0);
    } else if (r1.size(0) == 1) {
      i1 = a.size(0);
    } else if (r1.size(0) == a.size(0)) {
      i1 = r1.size(0);
    }
    b_e.set_size(i1, 3);
    vstride = a.size(0);
    i1 = r1.size(0);
    if (vstride <= i1) {
      i1 = vstride;
    }
    if (a.size(0) == 1) {
      i1 = r1.size(0);
    } else if (r1.size(0) == 1) {
      i1 = a.size(0);
    } else if (r1.size(0) == a.size(0)) {
      i1 = r1.size(0);
    }
    if (i1 != 0) {
      vstride = (r1.size(1) != 1);
      acoef = (r1.size(0) != 1);
      i1 = (a.size(0) != 1);
      for (j = 0; j < 3; j++) {
        varargin_2 = vstride * j;
        i = b_e.size(0) - 1;
        for (int k{0}; k <= i; k++) {
          b_e[k + b_e.size(0) * j] = r1[acoef * k + r1.size(0) * varargin_2] *
                                     a[i1 * k + a.size(0) * j];
        }
      }
    }
    r1.set_size(1, 1);
    r1[0] = 0.5 * dtheta;
    vstride = bvec2.size(0);
    i1 = r1.size(0);
    if (vstride <= i1) {
      i1 = vstride;
    }
    if (bvec2.size(0) == 1) {
      i1 = r1.size(0);
    } else if (r1.size(0) == 1) {
      i1 = bvec2.size(0);
    } else if (r1.size(0) == bvec2.size(0)) {
      i1 = r1.size(0);
    }
    a.set_size(i1, 3);
    vstride = bvec2.size(0);
    i1 = r1.size(0);
    if (vstride <= i1) {
      i1 = vstride;
    }
    if (bvec2.size(0) == 1) {
      i1 = r1.size(0);
    } else if (r1.size(0) == 1) {
      i1 = bvec2.size(0);
    } else if (r1.size(0) == bvec2.size(0)) {
      i1 = r1.size(0);
    }
    if (i1 != 0) {
      vstride = (r1.size(1) != 1);
      acoef = (r1.size(0) != 1);
      i1 = (bvec2.size(0) != 1);
      for (j = 0; j < 3; j++) {
        varargin_2 = vstride * j;
        i = a.size(0) - 1;
        for (int k{0}; k <= i; k++) {
          a[k + a.size(0) * j] = r1[acoef * k + r1.size(0) * varargin_2] *
                                 bvec2[i1 * k + bvec2.size(0) * j];
        }
      }
    }
    if (b.size(0) == 1) {
      i = b_e.size(0);
    } else {
      i = b.size(0);
    }
    if ((b.size(0) == b_e.size(0)) && (i == a.size(0))) {
      vstride = b.size(0);
      for (i = 0; i < 3; i++) {
        for (i1 = 0; i1 < vstride; i1++) {
          bvec[i] = (b[i1 + b.size(0) * i] + b_e[i1 + b_e.size(0) * i]) +
                    a[i1 + a.size(0) * i];
        }
      }
    } else {
      binary_expand_op(bvec, ii, b, b_e, a);
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
  j = ii.size(0) * ii.size(1);
  for (i = 0; i < 3; i++) {
    for (i1 = 0; i1 < 3; i1++) {
      if (vstride - 1 >= 0) {
        aa[i1 + 3 * i] = 0.0;
      }
      if (j - 1 >= 0) {
        bb[i1 + 3 * i] = 0.0;
      }
    }
  }
  vstride = ii.size(0) * ii.size(1);
  for (i = 0; i < 2; i++) {
    for (i1 = 0; i1 < 3; i1++) {
      if (vstride - 1 >= 0) {
        cc[i1 + 3 * i] = 0.0;
      }
    }
  }
  vstride = ii.size(0) * ii.size(1);
  for (i = 0; i < 3; i++) {
    if (vstride - 1 >= 0) {
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
