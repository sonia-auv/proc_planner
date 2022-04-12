//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: LMFsolve.cpp
//
// MATLAB Coder version            : 5.4
// C/C++ source code generated on  : 12-Apr-2022 11:44:16
//

// Include Files
#include "LMFsolve.h"
#include "accumarray.h"
#include "anonymous_function.h"
#include "clothoidG1fit2wp.h"
#include "clothoidG2fitMissingCourse.h"
#include "eigStandard.h"
#include "eml_mtimes_helper.h"
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
static void binary_expand_op(coder::array<double, 1U> &in1,
                             const coder::array<double, 2U> &in2,
                             const coder::array<unsigned int, 2U> &in3);

static void binary_expand_op(coder::array<double, 2U> &in1, int in2,
                             const coder::array<double, 2U> &in3,
                             const coder::array<double, 1U> &in4,
                             const coder::array<double, 1U> &in5);

static void binary_expand_op(coder::array<double, 2U> &in1,
                             const coder::array<double, 2U> &in2,
                             const coder::array<double, 2U> &in3,
                             const coder::array<double, 1U> &in4);

static void binary_expand_op(coder::array<double, 1U> &in1,
                             const coder::array<double, 2U> &in2);

static void binary_expand_op(const coder::array<double, 2U> &in1,
                             const coder::array<double, 2U> &in2,
                             coder::array<double, 1U> &in3);

static double binary_expand_op(double in1, double in2,
                               const coder::array<double, 1U> &in3,
                               const coder::array<double, 1U> &in4,
                               const coder::array<double, 2U> &in5,
                               const coder::array<double, 1U> &in6,
                               const coder::array<unsigned int, 2U> &in7,
                               const coder::array<unsigned int, 2U> &in8,
                               const coder::array<unsigned int, 2U> &in9);

static void binary_expand_op(coder::array<double, 1U> &in1, double in2,
                             const coder::array<double, 1U> &in3);

static void binary_expand_op(coder::array<double, 1U> &in1, double in2,
                             const coder::array<double, 1U> &in3,
                             const coder::array<double, 1U> &in4, int in5,
                             const coder::array<double, 1U> &in6);

static void binary_expand_op(coder::array<double, 1U> &in1,
                             const coder::array<double, 2U> &in2,
                             const coder::array<double, 1U> &in3,
                             const coder::array<unsigned int, 2U> &in4,
                             const coder::array<unsigned int, 2U> &in5,
                             const coder::array<int, 2U> &in6);

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

static void sympentdisolve(const ::coder::array<double, 1U> &d,
                           const ::coder::array<double, 1U> &e,
                           const ::coder::array<double, 1U> &f,
                           const ::coder::array<double, 2U> &b,
                           ::coder::array<double, 2U> &x);

} // namespace scenario
} // namespace internal
} // namespace tracking
} // namespace matlabshared
} // namespace coder
static void e_binary_expand_op(coder::array<double, 1U> &in1,
                               const coder::array<double, 2U> &in2,
                               const coder::array<unsigned int, 2U> &in3);

static void e_binary_expand_op(coder::array<double, 2U> &in1,
                               const coder::array<double, 2U> &in2,
                               const coder::array<double, 1U> &in3);

static void e_binary_expand_op(coder::array<double, 2U> &in1, int in2,
                               const coder::array<double, 2U> &in3,
                               const coder::array<double, 1U> &in4,
                               const coder::array<double, 1U> &in5);

static void e_binary_expand_op(coder::array<double, 1U> &in1,
                               const coder::array<double, 2U> &in2,
                               const coder::array<double, 1U> &in3,
                               const coder::array<unsigned int, 2U> &in4,
                               const coder::array<unsigned int, 2U> &in5,
                               const coder::array<int, 2U> &in6);

// Function Definitions
//
// Arguments    : coder::array<double, 1U> &in1
//                const coder::array<double, 2U> &in2
//                const coder::array<double, 1U> &in3
//                const coder::array<unsigned int, 2U> &in4
//                const coder::array<unsigned int, 2U> &in5
//                const coder::array<int, 2U> &in6
// Return Type  : void
//
static void binary_expand_op(coder::array<double, 1U> &in1,
                             const coder::array<double, 2U> &in2,
                             const coder::array<double, 1U> &in3,
                             const coder::array<unsigned int, 2U> &in4,
                             const coder::array<unsigned int, 2U> &in5,
                             const coder::array<int, 2U> &in6)
{
  coder::array<int, 1U> b_in3;
  coder::array<int, 1U> c_in3;
  int i;
  int i1;
  int loop_ub;
  int stride_0_0;
  int stride_1_0;
  int stride_2_0;
  int stride_3_0;
  int stride_4_0;
  int stride_5_0;
  b_in3.set_size(in5.size(1) + 1);
  b_in3[0] = in3.size(0) - 1;
  loop_ub = in5.size(1);
  for (i = 0; i < loop_ub; i++) {
    b_in3[i + 1] = static_cast<int>(in5[i]) - 1;
  }
  c_in3.set_size(in6.size(1) + 1);
  c_in3[0] = in3.size(0) - 1;
  loop_ub = in6.size(1);
  for (i = 0; i < loop_ub; i++) {
    c_in3[i + 1] = in6[i] - 1;
  }
  i = in2.size(0);
  loop_ub = in2.size(0);
  if (c_in3.size(0) == 1) {
    i1 = b_in3.size(0);
  } else {
    i1 = c_in3.size(0);
  }
  if (in4.size(1) == 1) {
    stride_0_0 = loop_ub;
  } else {
    stride_0_0 = in4.size(1);
  }
  if (i1 == 1) {
    if (stride_0_0 == 1) {
      if (in3.size(0) == 1) {
        i1 = i;
      } else {
        i1 = in3.size(0);
      }
    } else if (in4.size(1) == 1) {
      i1 = loop_ub;
    } else {
      i1 = in4.size(1);
    }
  } else if (c_in3.size(0) == 1) {
    i1 = b_in3.size(0);
  } else {
    i1 = c_in3.size(0);
  }
  in1.set_size(i1);
  stride_0_0 = (i != 1);
  stride_1_0 = (in3.size(0) != 1);
  stride_2_0 = (loop_ub != 1);
  stride_3_0 = (in4.size(1) != 1);
  stride_4_0 = (b_in3.size(0) != 1);
  stride_5_0 = (c_in3.size(0) != 1);
  if (c_in3.size(0) == 1) {
    i1 = b_in3.size(0);
  } else {
    i1 = c_in3.size(0);
  }
  if (i1 == 1) {
    if (in4.size(1) == 1) {
      i1 = loop_ub;
    } else {
      i1 = in4.size(1);
    }
    if (i1 == 1) {
      if (in3.size(0) == 1) {
        loop_ub = i;
      } else {
        loop_ub = in3.size(0);
      }
    } else if (in4.size(1) != 1) {
      loop_ub = in4.size(1);
    }
  } else if (c_in3.size(0) == 1) {
    loop_ub = b_in3.size(0);
  } else {
    loop_ub = c_in3.size(0);
  }
  for (i = 0; i < loop_ub; i++) {
    in1[i] =
        (in2[i * stride_0_0 + in2.size(0)] * in3[i * stride_1_0] +
         in2[i * stride_2_0] * in3[static_cast<int>(in4[i * stride_3_0]) - 1]) +
        in2[b_in3[i * stride_4_0] + in2.size(0) * 2] *
            in3[c_in3[i * stride_5_0]];
  }
}

//
// Arguments    : coder::array<double, 1U> &in1
//                double in2
//                const coder::array<double, 1U> &in3
//                const coder::array<double, 1U> &in4
//                int in5
//                const coder::array<double, 1U> &in6
// Return Type  : void
//
static void binary_expand_op(coder::array<double, 1U> &in1, double in2,
                             const coder::array<double, 1U> &in3,
                             const coder::array<double, 1U> &in4, int in5,
                             const coder::array<double, 1U> &in6)
{
  coder::array<double, 1U> b_in1;
  double b_in4;
  int i;
  int loop_ub;
  int stride_0_0;
  int stride_1_0;
  int stride_2_0;
  b_in4 = in4[in5];
  if (in6.size(0) == 1) {
    if (in3.size(0) == 1) {
      i = in1.size(0);
    } else {
      i = in3.size(0);
    }
  } else {
    i = in6.size(0);
  }
  b_in1.set_size(i);
  stride_0_0 = (in1.size(0) != 1);
  stride_1_0 = (in3.size(0) != 1);
  stride_2_0 = (in6.size(0) != 1);
  if (in6.size(0) == 1) {
    if (in3.size(0) == 1) {
      loop_ub = in1.size(0);
    } else {
      loop_ub = in3.size(0);
    }
  } else {
    loop_ub = in6.size(0);
  }
  for (i = 0; i < loop_ub; i++) {
    b_in1[i] = (in1[i * stride_0_0] - in2 * in3[i * stride_1_0]) -
               b_in4 * in6[i * stride_2_0];
  }
  in1.set_size(b_in1.size(0));
  loop_ub = b_in1.size(0);
  for (i = 0; i < loop_ub; i++) {
    in1[i] = b_in1[i];
  }
}

//
// Arguments    : coder::array<double, 1U> &in1
//                double in2
//                const coder::array<double, 1U> &in3
// Return Type  : void
//
static void binary_expand_op(coder::array<double, 1U> &in1, double in2,
                             const coder::array<double, 1U> &in3)
{
  coder::array<double, 1U> b_in1;
  int i;
  int loop_ub;
  int stride_0_0;
  int stride_1_0;
  if (in3.size(0) == 1) {
    i = in1.size(0);
  } else {
    i = in3.size(0);
  }
  b_in1.set_size(i);
  stride_0_0 = (in1.size(0) != 1);
  stride_1_0 = (in3.size(0) != 1);
  if (in3.size(0) == 1) {
    loop_ub = in1.size(0);
  } else {
    loop_ub = in3.size(0);
  }
  for (i = 0; i < loop_ub; i++) {
    b_in1[i] = in1[i * stride_0_0] - in2 * in3[i * stride_1_0];
  }
  in1.set_size(b_in1.size(0));
  loop_ub = b_in1.size(0);
  for (i = 0; i < loop_ub; i++) {
    in1[i] = b_in1[i];
  }
}

//
// Arguments    : coder::array<double, 1U> &in1
//                const coder::array<double, 2U> &in2
//                const coder::array<unsigned int, 2U> &in3
// Return Type  : void
//
static void binary_expand_op(coder::array<double, 1U> &in1,
                             const coder::array<double, 2U> &in2,
                             const coder::array<unsigned int, 2U> &in3)
{
  int i;
  int loop_ub;
  int stride_0_0;
  int stride_1_0;
  i = in2.size(0);
  if (in3.size(1) == 1) {
    stride_0_0 = i;
  } else {
    stride_0_0 = in3.size(1);
  }
  in1.set_size(stride_0_0);
  stride_0_0 = (i != 1);
  stride_1_0 = (in3.size(1) != 1);
  if (in3.size(1) == 1) {
    loop_ub = i;
  } else {
    loop_ub = in3.size(1);
  }
  for (i = 0; i < loop_ub; i++) {
    in1[i] = in2[i * stride_0_0] *
             in2[(static_cast<int>(in3[i * stride_1_0]) + in2.size(0) * 2) - 1];
  }
}

//
// Arguments    : coder::array<double, 2U> &in1
//                int in2
//                const coder::array<double, 2U> &in3
//                const coder::array<double, 1U> &in4
//                const coder::array<double, 1U> &in5
// Return Type  : void
//
static void binary_expand_op(coder::array<double, 2U> &in1, int in2,
                             const coder::array<double, 2U> &in3,
                             const coder::array<double, 1U> &in4,
                             const coder::array<double, 1U> &in5)
{
  coder::array<double, 2U> b_in3;
  double b_in4;
  double b_in5;
  int b_in1;
  int c_in1;
  int d_in1;
  int i;
  int stride_1_1;
  int stride_2_1;
  b_in4 = in4[in2 + 1];
  b_in1 = in1.size(1) - 1;
  b_in5 = in5[in2];
  c_in1 = in1.size(1) - 1;
  i = in3.size(1);
  if (c_in1 + 1 == 1) {
    if (b_in1 + 1 == 1) {
      d_in1 = i;
    } else {
      d_in1 = b_in1 + 1;
    }
  } else {
    d_in1 = c_in1 + 1;
  }
  b_in3.set_size(1, d_in1);
  d_in1 = (i != 1);
  stride_1_1 = (b_in1 + 1 != 1);
  stride_2_1 = (c_in1 + 1 != 1);
  if (c_in1 + 1 == 1) {
    if (b_in1 + 1 == 1) {
      b_in1 = i;
    } else {
      b_in1++;
    }
  } else {
    b_in1 = c_in1 + 1;
  }
  for (i = 0; i < b_in1; i++) {
    b_in3[i] = (in3[(in2 + in3.size(0) * (i * d_in1)) + 2] -
                b_in4 * in1[(in2 + in1.size(0) * (i * stride_1_1)) + 1]) -
               b_in5 * in1[in2 + in1.size(0) * (i * stride_2_1)];
  }
  b_in1 = b_in3.size(1);
  for (i = 0; i < b_in1; i++) {
    in1[(in2 + in1.size(0) * i) + 2] = b_in3[i];
  }
}

//
// Arguments    : coder::array<double, 2U> &in1
//                const coder::array<double, 2U> &in2
//                const coder::array<double, 2U> &in3
//                const coder::array<double, 1U> &in4
// Return Type  : void
//
static void binary_expand_op(coder::array<double, 2U> &in1,
                             const coder::array<double, 2U> &in2,
                             const coder::array<double, 2U> &in3,
                             const coder::array<double, 1U> &in4)
{
  coder::array<double, 2U> b_in3;
  double b_in4;
  int b_in1;
  int b_in2;
  int c_in1;
  int c_in2;
  int d_in2;
  int i;
  int stride_1_1;
  b_in2 = in2.size(0);
  b_in4 = in4[in2.size(0) - 2];
  b_in1 = in1.size(1) - 1;
  c_in2 = in2.size(0);
  d_in2 = in2.size(0);
  i = in3.size(1);
  if (b_in1 + 1 == 1) {
    c_in1 = i;
  } else {
    c_in1 = b_in1 + 1;
  }
  b_in3.set_size(1, c_in1);
  c_in1 = (i != 1);
  stride_1_1 = (b_in1 + 1 != 1);
  if (b_in1 + 1 == 1) {
    b_in1 = i;
  } else {
    b_in1++;
  }
  for (i = 0; i < b_in1; i++) {
    b_in3[i] = in3[(b_in2 + in3.size(0) * (i * c_in1)) - 2] -
               b_in4 * in1[(c_in2 + in1.size(0) * (i * stride_1_1)) - 1];
  }
  b_in1 = b_in3.size(1);
  for (i = 0; i < b_in1; i++) {
    in1[(d_in2 + in1.size(0) * i) - 2] = b_in3[i];
  }
}

//
// Arguments    : double in1
//                double in2
//                const coder::array<double, 1U> &in3
//                const coder::array<double, 1U> &in4
//                const coder::array<double, 2U> &in5
//                const coder::array<double, 1U> &in6
//                const coder::array<unsigned int, 2U> &in7
//                const coder::array<unsigned int, 2U> &in8
//                const coder::array<unsigned int, 2U> &in9
// Return Type  : double
//
static double binary_expand_op(double in1, double in2,
                               const coder::array<double, 1U> &in3,
                               const coder::array<double, 1U> &in4,
                               const coder::array<double, 2U> &in5,
                               const coder::array<double, 1U> &in6,
                               const coder::array<unsigned int, 2U> &in7,
                               const coder::array<unsigned int, 2U> &in8,
                               const coder::array<unsigned int, 2U> &in9)
{
  coder::array<double, 1U> r;
  coder::array<int, 1U> b_in7;
  double b_in3;
  int i;
  int i1;
  int i2;
  int loop_ub;
  int stride_0_0;
  int stride_1_0;
  int stride_2_0;
  int stride_3_0;
  int stride_4_0;
  int stride_5_0;
  int stride_6_0;
  b_in7.set_size(in7.size(1) + 1);
  loop_ub = in7.size(1);
  for (i = 0; i < loop_ub; i++) {
    b_in7[i] = static_cast<int>(in7[i]) - 1;
  }
  b_in7[in7.size(1)] = 0;
  i = in5.size(0);
  loop_ub = in5.size(0);
  if (in9.size(1) == 1) {
    i1 = in8.size(1);
  } else {
    i1 = in9.size(1);
  }
  if (b_in7.size(0) == 1) {
    i2 = loop_ub;
  } else {
    i2 = b_in7.size(0);
  }
  if (i1 == 1) {
    if (i2 == 1) {
      if (in6.size(0) == 1) {
        i1 = i;
      } else {
        i1 = in6.size(0);
      }
    } else if (b_in7.size(0) == 1) {
      i1 = loop_ub;
    } else {
      i1 = b_in7.size(0);
    }
  } else if (in9.size(1) == 1) {
    i1 = in8.size(1);
  } else {
    i1 = in9.size(1);
  }
  if (in9.size(1) == 1) {
    i2 = in8.size(1);
  } else {
    i2 = in9.size(1);
  }
  if (b_in7.size(0) == 1) {
    stride_0_0 = loop_ub;
  } else {
    stride_0_0 = b_in7.size(0);
  }
  if (i1 == 1) {
    i1 = in4.size(0);
  } else if (i2 == 1) {
    if (stride_0_0 == 1) {
      if (in6.size(0) == 1) {
        i1 = i;
      } else {
        i1 = in6.size(0);
      }
    } else if (b_in7.size(0) == 1) {
      i1 = loop_ub;
    } else {
      i1 = b_in7.size(0);
    }
  } else if (in9.size(1) == 1) {
    i1 = in8.size(1);
  } else {
    i1 = in9.size(1);
  }
  r.set_size(i1);
  stride_0_0 = (in4.size(0) != 1);
  stride_1_0 = (i != 1);
  stride_2_0 = (in6.size(0) != 1);
  stride_3_0 = (loop_ub != 1);
  stride_4_0 = (b_in7.size(0) != 1);
  stride_5_0 = (in8.size(1) != 1);
  stride_6_0 = (in9.size(1) != 1);
  if (in9.size(1) == 1) {
    i1 = in8.size(1);
  } else {
    i1 = in9.size(1);
  }
  if (b_in7.size(0) == 1) {
    i2 = loop_ub;
  } else {
    i2 = b_in7.size(0);
  }
  if (i1 == 1) {
    if (i2 == 1) {
      if (in6.size(0) == 1) {
        i1 = i;
      } else {
        i1 = in6.size(0);
      }
    } else if (b_in7.size(0) == 1) {
      i1 = loop_ub;
    } else {
      i1 = b_in7.size(0);
    }
  } else if (in9.size(1) == 1) {
    i1 = in8.size(1);
  } else {
    i1 = in9.size(1);
  }
  if (i1 == 1) {
    loop_ub = in4.size(0);
  } else {
    if (in9.size(1) == 1) {
      i1 = in8.size(1);
    } else {
      i1 = in9.size(1);
    }
    if (i1 == 1) {
      if (b_in7.size(0) == 1) {
        i1 = loop_ub;
      } else {
        i1 = b_in7.size(0);
      }
      if (i1 == 1) {
        if (in6.size(0) == 1) {
          loop_ub = i;
        } else {
          loop_ub = in6.size(0);
        }
      } else if (b_in7.size(0) != 1) {
        loop_ub = b_in7.size(0);
      }
    } else if (in9.size(1) == 1) {
      loop_ub = in8.size(1);
    } else {
      loop_ub = in9.size(1);
    }
  }
  for (i = 0; i < loop_ub; i++) {
    r[i] = 2.0 * in4[i * stride_0_0] -
           ((in5[i * stride_1_0 + in5.size(0)] * in6[i * stride_2_0] +
             in5[i * stride_3_0] * in6[b_in7[i * stride_4_0]]) +
            in5[(static_cast<int>(in8[i * stride_5_0]) + in5.size(0) * 2) - 1] *
                in6[static_cast<int>(in9[i * stride_6_0]) - 1]);
  }
  b_in3 = 0.0;
  loop_ub = in3.size(0);
  for (i = 0; i < loop_ub; i++) {
    b_in3 += in3[i] * r[i];
  }
  return (in1 - in2) / b_in3;
}

//
// Arguments    : coder::array<double, 1U> &in1
//                const coder::array<double, 2U> &in2
// Return Type  : void
//
static void binary_expand_op(coder::array<double, 1U> &in1,
                             const coder::array<double, 2U> &in2)
{
  coder::array<double, 1U> b_in2;
  int i;
  int loop_ub;
  int stride_0_0;
  int stride_1_0;
  i = in2.size(0);
  if (in1.size(0) == 1) {
    stride_0_0 = i;
  } else {
    stride_0_0 = in1.size(0);
  }
  b_in2.set_size(stride_0_0);
  stride_0_0 = (i != 1);
  stride_1_0 = (in1.size(0) != 1);
  if (in1.size(0) == 1) {
    loop_ub = i;
  } else {
    loop_ub = in1.size(0);
  }
  for (i = 0; i < loop_ub; i++) {
    b_in2[i] = in2[i * stride_0_0 + in2.size(0) * 4] - in1[i * stride_1_0];
  }
  in1.set_size(b_in2.size(0));
  loop_ub = b_in2.size(0);
  for (i = 0; i < loop_ub; i++) {
    in1[i] = b_in2[i];
  }
}

//
// Arguments    : const coder::array<double, 2U> &in1
//                const coder::array<double, 2U> &in2
//                coder::array<double, 1U> &in3
// Return Type  : void
//
static void binary_expand_op(const coder::array<double, 2U> &in1,
                             const coder::array<double, 2U> &in2,
                             coder::array<double, 1U> &in3)
{
  coder::array<double, 2U> b_in1;
  int aux_0_1;
  int aux_1_1;
  int i;
  int i1;
  int loop_ub;
  int stride_0_0;
  int stride_0_1;
  int stride_1_0;
  int stride_1_1;
  if (in2.size(0) == 1) {
    i = in1.size(0);
  } else {
    i = in2.size(0);
  }
  if (in2.size(1) == 1) {
    i1 = in1.size(1);
  } else {
    i1 = in2.size(1);
  }
  b_in1.set_size(i, i1);
  stride_0_0 = (in1.size(0) != 1);
  stride_0_1 = (in1.size(1) != 1);
  stride_1_0 = (in2.size(0) != 1);
  stride_1_1 = (in2.size(1) != 1);
  aux_0_1 = 0;
  aux_1_1 = 0;
  if (in2.size(1) == 1) {
    loop_ub = in1.size(1);
  } else {
    loop_ub = in2.size(1);
  }
  for (i = 0; i < loop_ub; i++) {
    int b_loop_ub;
    if (in2.size(0) == 1) {
      b_loop_ub = in1.size(0);
    } else {
      b_loop_ub = in2.size(0);
    }
    for (i1 = 0; i1 < b_loop_ub; i1++) {
      b_in1[i1 + b_in1.size(0) * i] =
          in1[i1 * stride_0_0 + in1.size(0) * aux_0_1] +
          in2[i1 * stride_1_0 + in2.size(0) * aux_1_1];
    }
    aux_1_1 += stride_1_1;
    aux_0_1 += stride_0_1;
  }
  coder::mldivide(b_in1, in3);
}

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
  array<double, 2U> b_u;
  array<double, 2U> u;
  array<double, 2U> v;
  array<double, 2U> zy;
  double b_I[16];
  double y[16];
  double X[4];
  double bkj;
  int boffset;
  int coffset;
  int i;
  int jA;
  int k;
  int kAcol;
  signed char ipiv[4];
  signed char input_sizes_idx_1;
  signed char sizes_idx_1;
  bool empty_non_axis_sizes;
  u.set_size(b.size(0), 4);
  kAcol = b.size(0) << 2;
  for (i = 0; i < kAcol; i++) {
    u[i] = 0.0;
  }
  u[0] = 1.0;
  u[u.size(0) + 1] = 1.0;
  u[(b.size(0) + u.size(0) * 2) - 2] = 1.0;
  u[(b.size(0) + u.size(0) * 3) - 1] = 1.0;
  if (u.size(0) != 0) {
    jA = u.size(0);
  } else if (b.size(0) != 0) {
    jA = b.size(0);
  } else {
    jA = 0;
  }
  empty_non_axis_sizes = (jA == 0);
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
  b_u.set_size(jA, input_sizes_idx_1 + sizes_idx_1);
  kAcol = input_sizes_idx_1;
  for (i = 0; i < kAcol; i++) {
    for (k = 0; k < jA; k++) {
      b_u[k + b_u.size(0) * i] = u[k + jA * i];
    }
  }
  kAcol = sizes_idx_1;
  for (i = 0; i < kAcol; i++) {
    for (k = 0; k < jA; k++) {
      b_u[k + b_u.size(0) * input_sizes_idx_1] = b[k];
    }
  }
  sympentdisolve(d, e, f, b_u, zy);
  kAcol = zy.size(0);
  u.set_size(zy.size(0), 4);
  for (i = 0; i < 4; i++) {
    for (k = 0; k < kAcol; k++) {
      u[k + u.size(0) * i] = zy[k + zy.size(0) * i];
    }
  }
  v.set_size(b.size(0), 4);
  kAcol = b.size(0) << 2;
  for (i = 0; i < kAcol; i++) {
    v[i] = 0.0;
  }
  v[b.size(0) - 2] = f[b.size(0) - 2];
  v[b.size(0) - 1] = e[b.size(0) - 1];
  v[(b.size(0) + v.size(0)) - 1] = f[b.size(0) - 1];
  v[v.size(0) * 2] = f[b.size(0) - 2];
  v[v.size(0) * 3] = e[b.size(0) - 1];
  v[v.size(0) * 3 + 1] = f[b.size(0) - 1];
  jA = v.size(0);
  kAcol = v.size(0);
  for (int j{0}; j < 4; j++) {
    coffset = j << 2;
    boffset = j * zy.size(0);
    y[coffset] = 0.0;
    y[coffset + 1] = 0.0;
    y[coffset + 2] = 0.0;
    y[coffset + 3] = 0.0;
    for (k = 0; k < jA; k++) {
      bkj = u[boffset + k];
      y[coffset] += v[k] * bkj;
      y[coffset + 1] += v[v.size(0) + k] * bkj;
      y[coffset + 2] += v[(v.size(0) << 1) + k] * bkj;
      y[coffset + 3] += v[3 * v.size(0) + k] * bkj;
    }
    X[j] = 0.0;
  }
  for (k = 0; k < kAcol; k++) {
    X[0] += v[k] * zy[k + zy.size(0) * 4];
    X[1] += v[v.size(0) + k] * zy[k + zy.size(0) * 4];
    X[2] += v[(v.size(0) << 1) + k] * zy[k + zy.size(0) * 4];
    X[3] += v[3 * v.size(0) + k] * zy[k + zy.size(0) * 4];
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
  for (int j{0}; j < 3; j++) {
    int b_tmp;
    boffset = 2 - j;
    b_tmp = j * 5;
    coffset = b_tmp + 2;
    jA = 4 - j;
    kAcol = 0;
    bkj = std::abs(b_I[b_tmp]);
    for (k = 2; k <= jA; k++) {
      double s;
      s = std::abs(b_I[(b_tmp + k) - 1]);
      if (s > bkj) {
        kAcol = k - 1;
        bkj = s;
      }
    }
    if (b_I[b_tmp + kAcol] != 0.0) {
      if (kAcol != 0) {
        jA = j + kAcol;
        ipiv[j] = static_cast<signed char>(jA + 1);
        bkj = b_I[j];
        b_I[j] = b_I[jA];
        b_I[jA] = bkj;
        bkj = b_I[j + 4];
        b_I[j + 4] = b_I[jA + 4];
        b_I[jA + 4] = bkj;
        bkj = b_I[j + 8];
        b_I[j + 8] = b_I[jA + 8];
        b_I[jA + 8] = bkj;
        bkj = b_I[j + 12];
        b_I[j + 12] = b_I[jA + 12];
        b_I[jA + 12] = bkj;
      }
      i = (b_tmp - j) + 4;
      for (jA = coffset; jA <= i; jA++) {
        b_I[jA - 1] /= b_I[b_tmp];
      }
    }
    jA = b_tmp;
    for (kAcol = 0; kAcol <= boffset; kAcol++) {
      bkj = b_I[(b_tmp + (kAcol << 2)) + 4];
      if (bkj != 0.0) {
        i = jA + 6;
        k = (jA - j) + 8;
        for (coffset = i; coffset <= k; coffset++) {
          b_I[coffset - 1] += b_I[((b_tmp + coffset) - jA) - 5] * -bkj;
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
    kAcol = k << 2;
    if (X[k] != 0.0) {
      i = k + 2;
      for (jA = i; jA < 5; jA++) {
        X[jA - 1] -= X[k] * b_I[(jA + kAcol) - 1];
      }
    }
  }
  for (k = 3; k >= 0; k--) {
    kAcol = k << 2;
    bkj = X[k];
    if (bkj != 0.0) {
      bkj /= b_I[k + kAcol];
      X[k] = bkj;
      for (jA = 0; jA < k; jA++) {
        X[jA] -= X[k] * b_I[jA + kAcol];
      }
    }
  }
  kAcol = zy.size(0) - 1;
  x.set_size(zy.size(0));
  for (jA = 0; jA <= kAcol; jA++) {
    x[jA] = ((u[jA] * X[0] + u[zy.size(0) + jA] * X[1]) +
             u[(zy.size(0) << 1) + jA] * X[2]) +
            u[3 * zy.size(0) + jA] * X[3];
  }
  if (zy.size(0) == x.size(0)) {
    kAcol = zy.size(0);
    x.set_size(zy.size(0));
    for (i = 0; i < kAcol; i++) {
      x[i] = zy[i + zy.size(0) * 4] - x[i];
    }
  } else {
    binary_expand_op(x, zy);
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
  if (d.size(0) - 1 < 2) {
    i = -1;
    j = 1;
  } else {
    i = 0;
    j = d.size(0);
  }
  loop_ub = (j - i) - 2;
  for (j = 0; j < loop_ub; j++) {
    u[(i + j) + 1] = 0.0;
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
  if (x.size(0) == z.size(0)) {
    loop_ub = x.size(0);
    for (i = 0; i < loop_ub; i++) {
      x[i] = x[i] - b_gamma * z[i];
    }
  } else {
    binary_expand_op(x, b_gamma, z);
  }
}

//
// Arguments    : const ::coder::array<double, 1U> &d
//                const ::coder::array<double, 1U> &e
//                const ::coder::array<double, 1U> &f
//                const ::coder::array<double, 2U> &b
//                ::coder::array<double, 2U> &x
// Return Type  : void
//
static void sympentdisolve(const ::coder::array<double, 1U> &d,
                           const ::coder::array<double, 1U> &e,
                           const ::coder::array<double, 1U> &f,
                           const ::coder::array<double, 2U> &b,
                           ::coder::array<double, 2U> &x)
{
  array<double, 2U> b_b;
  array<double, 2U> c;
  array<double, 2U> z;
  array<double, 1U> alpha;
  array<double, 1U> b_gamma;
  array<double, 1U> delta;
  int acoef;
  int b_acoef;
  int b_k;
  int i;
  int i1;
  x.set_size(b.size(0), b.size(1));
  acoef = b.size(0) * b.size(1);
  for (i = 0; i < acoef; i++) {
    x[i] = 0.0;
  }
  alpha.set_size(b.size(0));
  acoef = b.size(0);
  for (i = 0; i < acoef; i++) {
    alpha[i] = 0.0;
  }
  b_gamma.set_size(b.size(0) - 1);
  acoef = b.size(0);
  for (i = 0; i <= acoef - 2; i++) {
    b_gamma[i] = 0.0;
  }
  delta.set_size(b.size(0) - 2);
  acoef = b.size(0);
  for (i = 0; i <= acoef - 3; i++) {
    delta[i] = 0.0;
  }
  alpha[0] = d[0];
  b_gamma[0] = e[0] / alpha[0];
  delta[0] = f[0] / alpha[0];
  alpha[1] = d[1] - e[0] * b_gamma[0];
  b_gamma[1] = (e[1] - f[0] * b_gamma[0]) / alpha[1];
  delta[1] = f[1] / alpha[1];
  i = b.size(0);
  for (int k{0}; k <= i - 5; k++) {
    double b_d;
    double d1;
    b_d = b_gamma[k + 1];
    d1 = (d[k + 2] - f[k] * delta[k]) - alpha[k + 1] * (b_d * b_d);
    alpha[k + 2] = d1;
    b_gamma[k + 2] = (e[k + 2] - f[k + 1] * b_d) / d1;
    delta[k + 2] = f[k + 2] / d1;
  }
  alpha[b.size(0) - 2] =
      (d[b.size(0) - 2] - f[b.size(0) - 4] * delta[b.size(0) - 4]) -
      alpha[b.size(0) - 3] * (b_gamma[b.size(0) - 3] * b_gamma[b.size(0) - 3]);
  b_gamma[b.size(0) - 2] =
      (e[b.size(0) - 2] - f[b.size(0) - 3] * b_gamma[b.size(0) - 3]) /
      alpha[b.size(0) - 2];
  alpha[b.size(0) - 1] =
      (d[b.size(0) - 1] - f[b.size(0) - 3] * delta[b.size(0) - 3]) -
      alpha[b.size(0) - 2] * (b_gamma[b.size(0) - 2] * b_gamma[b.size(0) - 2]);
  z.set_size(b.size(0), b.size(1));
  acoef = b.size(0) * b.size(1);
  for (i = 0; i < acoef; i++) {
    z[i] = 0.0;
  }
  acoef = b.size(1);
  for (i = 0; i < acoef; i++) {
    z[z.size(0) * i] = b[b.size(0) * i];
  }
  if (b.size(1) == z.size(1)) {
    acoef = b.size(1);
    b_b.set_size(1, b.size(1));
    for (i = 0; i < acoef; i++) {
      b_b[i] = b[b.size(0) * i + 1] - b_gamma[0] * z[z.size(0) * i];
    }
    acoef = b_b.size(1);
    for (i = 0; i < acoef; i++) {
      z[z.size(0) * i + 1] = b_b[i];
    }
  } else {
    e_binary_expand_op(z, b, b_gamma);
  }
  i = b.size(0);
  for (int k{0}; k <= i - 3; k++) {
    acoef = b.size(1);
    if (b.size(1) == 1) {
      i1 = z.size(1);
    } else {
      i1 = b.size(1);
    }
    if ((b.size(1) == z.size(1)) && (i1 == z.size(1))) {
      b_b.set_size(1, b.size(1));
      for (i1 = 0; i1 < acoef; i1++) {
        b_b[i1] = (b[(k + b.size(0) * i1) + 2] -
                   b_gamma[k + 1] * z[(k + z.size(0) * i1) + 1]) -
                  delta[k] * z[k + z.size(0) * i1];
      }
      acoef = b_b.size(1);
      for (i1 = 0; i1 < acoef; i1++) {
        z[(k + z.size(0) * i1) + 2] = b_b[i1];
      }
    } else {
      binary_expand_op(z, k, b, b_gamma, delta);
    }
  }
  acoef = alpha.size(0);
  b_acoef = z.size(0);
  if (acoef <= b_acoef) {
    b_acoef = acoef;
  }
  if (alpha.size(0) == 1) {
    b_acoef = z.size(0);
  } else if (z.size(0) == 1) {
    b_acoef = alpha.size(0);
  } else if (z.size(0) == alpha.size(0)) {
    b_acoef = z.size(0);
  }
  c.set_size(b_acoef, z.size(1));
  acoef = alpha.size(0);
  b_acoef = z.size(0);
  if (acoef <= b_acoef) {
    b_acoef = acoef;
  }
  if (alpha.size(0) == 1) {
    b_acoef = z.size(0);
  } else if (z.size(0) == 1) {
    b_acoef = alpha.size(0);
  } else if (z.size(0) == alpha.size(0)) {
    b_acoef = z.size(0);
  }
  if ((b_acoef != 0) && (z.size(1) != 0)) {
    int bcoef;
    b_acoef = (z.size(1) != 1);
    i = z.size(1) - 1;
    acoef = (z.size(0) != 1);
    bcoef = (alpha.size(0) != 1);
    for (int k{0}; k <= i; k++) {
      int varargin_2;
      varargin_2 = b_acoef * k;
      i1 = c.size(0) - 1;
      for (b_k = 0; b_k <= i1; b_k++) {
        c[b_k + c.size(0) * k] =
            z[acoef * b_k + z.size(0) * varargin_2] / alpha[bcoef * b_k];
      }
    }
  }
  acoef = c.size(1);
  for (i = 0; i < acoef; i++) {
    x[(b.size(0) + x.size(0) * i) - 1] = c[(b.size(0) + c.size(0) * i) - 1];
  }
  if (c.size(1) == x.size(1)) {
    acoef = c.size(1);
    b_b.set_size(1, c.size(1));
    for (i = 0; i < acoef; i++) {
      b_b[i] = c[(b.size(0) + c.size(0) * i) - 2] -
               b_gamma[b.size(0) - 2] * x[(b.size(0) + x.size(0) * i) - 1];
    }
    acoef = b_b.size(1);
    for (i = 0; i < acoef; i++) {
      x[(b.size(0) + x.size(0) * i) - 2] = b_b[i];
    }
  } else {
    binary_expand_op(x, b, c, b_gamma);
  }
  i = b.size(0);
  for (int k{0}; k <= i - 3; k++) {
    b_k = (b.size(0) - k) - 3;
    acoef = c.size(1);
    if (c.size(1) == 1) {
      i1 = x.size(1);
    } else {
      i1 = c.size(1);
    }
    if ((c.size(1) == x.size(1)) && (i1 == x.size(1))) {
      b_b.set_size(1, c.size(1));
      for (i1 = 0; i1 < acoef; i1++) {
        b_b[i1] = (c[b_k + c.size(0) * i1] -
                   b_gamma[b_k] * x[(b_k + x.size(0) * i1) + 1]) -
                  delta[b_k] * x[(b_k + x.size(0) * i1) + 2];
      }
      acoef = b_b.size(1);
      for (i1 = 0; i1 < acoef; i1++) {
        x[b_k + x.size(0) * i1] = b_b[i1];
      }
    } else {
      e_binary_expand_op(x, b_k, c, b_gamma, delta);
    }
  }
}

//
// Arguments    : coder::array<double, 2U> &in1
//                int in2
//                const coder::array<double, 2U> &in3
//                const coder::array<double, 1U> &in4
//                const coder::array<double, 1U> &in5
// Return Type  : void
//
} // namespace scenario
} // namespace internal
} // namespace tracking
} // namespace matlabshared
} // namespace coder
static void e_binary_expand_op(coder::array<double, 2U> &in1, int in2,
                               const coder::array<double, 2U> &in3,
                               const coder::array<double, 1U> &in4,
                               const coder::array<double, 1U> &in5)
{
  coder::array<double, 2U> b_in3;
  double b_in4;
  double b_in5;
  int b_in1;
  int c_in1;
  int d_in1;
  int i;
  int stride_1_1;
  int stride_2_1;
  b_in4 = in4[in2];
  b_in1 = in1.size(1) - 1;
  b_in5 = in5[in2];
  c_in1 = in1.size(1) - 1;
  i = in3.size(1);
  if (c_in1 + 1 == 1) {
    if (b_in1 + 1 == 1) {
      d_in1 = i;
    } else {
      d_in1 = b_in1 + 1;
    }
  } else {
    d_in1 = c_in1 + 1;
  }
  b_in3.set_size(1, d_in1);
  d_in1 = (i != 1);
  stride_1_1 = (b_in1 + 1 != 1);
  stride_2_1 = (c_in1 + 1 != 1);
  if (c_in1 + 1 == 1) {
    if (b_in1 + 1 == 1) {
      b_in1 = i;
    } else {
      b_in1++;
    }
  } else {
    b_in1 = c_in1 + 1;
  }
  for (i = 0; i < b_in1; i++) {
    b_in3[i] = (in3[in2 + in3.size(0) * (i * d_in1)] -
                b_in4 * in1[(in2 + in1.size(0) * (i * stride_1_1)) + 1]) -
               b_in5 * in1[(in2 + in1.size(0) * (i * stride_2_1)) + 2];
  }
  b_in1 = b_in3.size(1);
  for (i = 0; i < b_in1; i++) {
    in1[in2 + in1.size(0) * i] = b_in3[i];
  }
}

//
// Arguments    : coder::array<double, 1U> &in1
//                const coder::array<double, 2U> &in2
//                const coder::array<double, 1U> &in3
//                const coder::array<unsigned int, 2U> &in4
//                const coder::array<unsigned int, 2U> &in5
//                const coder::array<int, 2U> &in6
// Return Type  : void
//
static void e_binary_expand_op(coder::array<double, 1U> &in1,
                               const coder::array<double, 2U> &in2,
                               const coder::array<double, 1U> &in3,
                               const coder::array<unsigned int, 2U> &in4,
                               const coder::array<unsigned int, 2U> &in5,
                               const coder::array<int, 2U> &in6)
{
  coder::array<int, 1U> b_in3;
  coder::array<int, 1U> c_in3;
  int i;
  int i1;
  int loop_ub;
  int stride_0_0;
  int stride_1_0;
  int stride_2_0;
  int stride_3_0;
  int stride_4_0;
  int stride_5_0;
  b_in3.set_size(in5.size(1) + 1);
  b_in3[0] = in3.size(0) - 1;
  loop_ub = in5.size(1);
  for (i = 0; i < loop_ub; i++) {
    b_in3[i + 1] = static_cast<int>(in5[i]) - 1;
  }
  c_in3.set_size(in6.size(1) + 1);
  c_in3[0] = in3.size(0) - 1;
  loop_ub = in6.size(1);
  for (i = 0; i < loop_ub; i++) {
    c_in3[i + 1] = in6[i] - 1;
  }
  i = in2.size(0);
  loop_ub = in2.size(0);
  if (c_in3.size(0) == 1) {
    i1 = b_in3.size(0);
  } else {
    i1 = c_in3.size(0);
  }
  if (in4.size(1) == 1) {
    stride_0_0 = loop_ub;
  } else {
    stride_0_0 = in4.size(1);
  }
  if (i1 == 1) {
    if (stride_0_0 == 1) {
      if (in3.size(0) == 1) {
        i1 = i;
      } else {
        i1 = in3.size(0);
      }
    } else if (in4.size(1) == 1) {
      i1 = loop_ub;
    } else {
      i1 = in4.size(1);
    }
  } else if (c_in3.size(0) == 1) {
    i1 = b_in3.size(0);
  } else {
    i1 = c_in3.size(0);
  }
  in1.set_size(i1);
  stride_0_0 = (i != 1);
  stride_1_0 = (in3.size(0) != 1);
  stride_2_0 = (loop_ub != 1);
  stride_3_0 = (in4.size(1) != 1);
  stride_4_0 = (b_in3.size(0) != 1);
  stride_5_0 = (c_in3.size(0) != 1);
  if (c_in3.size(0) == 1) {
    i1 = b_in3.size(0);
  } else {
    i1 = c_in3.size(0);
  }
  if (i1 == 1) {
    if (in4.size(1) == 1) {
      i1 = loop_ub;
    } else {
      i1 = in4.size(1);
    }
    if (i1 == 1) {
      if (in3.size(0) == 1) {
        loop_ub = i;
      } else {
        loop_ub = in3.size(0);
      }
    } else if (in4.size(1) != 1) {
      loop_ub = in4.size(1);
    }
  } else if (c_in3.size(0) == 1) {
    loop_ub = b_in3.size(0);
  } else {
    loop_ub = c_in3.size(0);
  }
  for (i = 0; i < loop_ub; i++) {
    in1[i] = (in2[i * stride_0_0 + in2.size(0)] * in3[i * stride_1_0] +
              in2[i * stride_2_0 + in2.size(0) * 2] *
                  in3[static_cast<int>(in4[i * stride_3_0]) - 1]) +
             in2[b_in3[i * stride_4_0]] * in3[c_in3[i * stride_5_0]];
  }
}

//
// Arguments    : coder::array<double, 2U> &in1
//                const coder::array<double, 2U> &in2
//                const coder::array<double, 1U> &in3
// Return Type  : void
//
static void e_binary_expand_op(coder::array<double, 2U> &in1,
                               const coder::array<double, 2U> &in2,
                               const coder::array<double, 1U> &in3)
{
  coder::array<double, 2U> b_in2;
  double b_in3;
  int b_in1;
  int c_in1;
  int i;
  int stride_1_1;
  b_in3 = in3[0];
  b_in1 = in1.size(1) - 1;
  i = in2.size(1);
  if (b_in1 + 1 == 1) {
    c_in1 = i;
  } else {
    c_in1 = b_in1 + 1;
  }
  b_in2.set_size(1, c_in1);
  c_in1 = (i != 1);
  stride_1_1 = (b_in1 + 1 != 1);
  if (b_in1 + 1 == 1) {
    b_in1 = i;
  } else {
    b_in1++;
  }
  for (i = 0; i < b_in1; i++) {
    b_in2[i] = in2[in2.size(0) * (i * c_in1) + 1] -
               b_in3 * in1[in1.size(0) * (i * stride_1_1)];
  }
  b_in1 = b_in2.size(1);
  for (i = 0; i < b_in1; i++) {
    in1[in1.size(0) * i + 1] = b_in2[i];
  }
}

//
// Arguments    : coder::array<double, 1U> &in1
//                const coder::array<double, 2U> &in2
//                const coder::array<unsigned int, 2U> &in3
// Return Type  : void
//
static void e_binary_expand_op(coder::array<double, 1U> &in1,
                               const coder::array<double, 2U> &in2,
                               const coder::array<unsigned int, 2U> &in3)
{
  coder::array<int, 1U> b_in3;
  int i;
  int i1;
  int i2;
  int loop_ub;
  int stride_0_0;
  int stride_1_0;
  int stride_2_0;
  int stride_3_0;
  b_in3.set_size(in3.size(1) + 1);
  loop_ub = in3.size(1);
  for (i = 0; i < loop_ub; i++) {
    b_in3[i] = static_cast<int>(in3[i]) - 1;
  }
  b_in3[in3.size(1)] = 0;
  i = in2.size(0);
  loop_ub = in2.size(0);
  i1 = in2.size(0);
  if (i1 == 1) {
    i2 = loop_ub;
  } else {
    i2 = i1;
  }
  if (i2 == 1) {
    if (b_in3.size(0) == 1) {
      i2 = i;
    } else {
      i2 = b_in3.size(0);
    }
  } else if (i1 == 1) {
    i2 = loop_ub;
  } else {
    i2 = i1;
  }
  in1.set_size(i2);
  stride_0_0 = (i != 1);
  stride_1_0 = (b_in3.size(0) != 1);
  stride_2_0 = (loop_ub != 1);
  stride_3_0 = (i1 != 1);
  if (i1 == 1) {
    i2 = loop_ub;
  } else {
    i2 = i1;
  }
  if (i2 == 1) {
    if (b_in3.size(0) == 1) {
      loop_ub = i;
    } else {
      loop_ub = b_in3.size(0);
    }
  } else if (i1 != 1) {
    loop_ub = i1;
  }
  for (i = 0; i < loop_ub; i++) {
    in1[i] = in2[i * stride_0_0] * in2[b_in3[i * stride_1_0] + in2.size(0)] +
             in2[i * stride_2_0 + in2.size(0)] *
                 in2[i * stride_3_0 + in2.size(0) * 2];
  }
}

//
// Arguments    : const anonymous_function *FUN
//                ::coder::array<double, 1U> &x
// Return Type  : void
//
namespace coder {
namespace matlabshared {
namespace tracking {
namespace internal {
namespace scenario {
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
  int b_outsize[2];
  int outsize[2];
  int nx;
  bool exitg1;
  maxiter = 100.0 * static_cast<double>(x.size(0));
  fitCourse_anonFcn3(FUN->workspace.waypoints, FUN->workspace.course, x, r,
                     Jtri);
  mulJt(Jtri, r, v);
  S = 0.0;
  nx = r.size(0);
  for (int k{0}; k < nx; k++) {
    S += r[k] * r[k];
  }
  lambda = 0.0;
  lambdac = 0.75;
  iter = 0.0;
  outsize[0] = x.size(0);
  b_outsize[0] = x.size(0);
  dx.set_size(outsize[0]);
  nx = outsize[0];
  for (int k{0}; k < nx; k++) {
    dx[k] = 1.0E-7;
  }
  exitg1 = false;
  while ((!exitg1) && (iter < maxiter)) {
    bool exitg2;
    bool y;
    nx = dx.size(0);
    xnew.set_size(dx.size(0));
    for (int k{0}; k < nx; k++) {
      xnew[k] = std::abs(dx[k]);
    }
    if (xnew.size(0) == outsize[0]) {
      b_x.set_size(xnew.size(0));
      nx = xnew.size(0);
      for (int k{0}; k < nx; k++) {
        b_x[k] = (xnew[k] >= 1.0E-7);
      }
    } else {
      j_binary_expand_op(b_x, xnew, outsize);
    }
    y = false;
    nx = 1;
    exitg2 = false;
    while ((!exitg2) && (nx <= b_x.size(0))) {
      if (b_x[nx - 1]) {
        y = true;
        exitg2 = true;
      } else {
        nx++;
      }
    }
    if (y) {
      nx = r.size(0);
      xnew.set_size(r.size(0));
      for (int k{0}; k < nx; k++) {
        xnew[k] = std::abs(r[k]);
      }
      if (xnew.size(0) == b_outsize[0]) {
        b_x.set_size(xnew.size(0));
        nx = xnew.size(0);
        for (int k{0}; k < nx; k++) {
          b_x[k] = (xnew[k] >= 1.0E-7);
        }
      } else {
        j_binary_expand_op(b_x, xnew, b_outsize);
      }
      y = false;
      nx = 1;
      exitg2 = false;
      while ((!exitg2) && (nx <= b_x.size(0))) {
        if (b_x[nx - 1]) {
          y = true;
          exitg2 = true;
        } else {
          nx++;
        }
      }
      if (y) {
        double b_varargout_1;
        iter++;
        solveDampenedHessian(Jtri, lambda, v, dx);
        if (x.size(0) == dx.size(0)) {
          xnew.set_size(x.size(0));
          nx = x.size(0);
          for (int k{0}; k < nx; k++) {
            xnew[k] = x[k] - dx[k];
          }
        } else {
          minus(xnew, x, dx);
        }
        fitCourse_anonFcn3(FUN->workspace.waypoints, FUN->workspace.course,
                           xnew, varargout_1, varargout_2);
        b_varargout_1 = 0.0;
        nx = varargout_1.size(0);
        for (int k{0}; k < nx; k++) {
          b_varargout_1 += varargout_1[k] * varargout_1[k];
        }
        fletcher(S, b_varargout_1, dx, v, Jtri, &lambda, &lambdac);
        if (b_varargout_1 < S) {
          S = b_varargout_1;
          x.set_size(xnew.size(0));
          nx = xnew.size(0);
          for (int k{0}; k < nx; k++) {
            x[k] = xnew[k];
          }
          r.set_size(varargout_1.size(0));
          nx = varargout_1.size(0);
          for (int k{0}; k < nx; k++) {
            r[k] = varargout_1[k];
          }
          Jtri.set_size(varargout_2.size(0), 3);
          nx = varargout_2.size(0) * 3;
          for (int k{0}; k < nx; k++) {
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
  array<creal_T, 1U> x;
  array<double, 2U> T;
  array<double, 2U> b_T;
  array<double, 2U> g_y;
  array<double, 1U> alpha;
  array<double, 1U> b;
  array<double, 1U> b_Jtri;
  array<double, 1U> b_v;
  array<double, 1U> beta;
  array<double, 1U> c_Jtri;
  array<double, 1U> dy;
  array<double, 1U> q;
  array<double, 1U> z;
  array<unsigned int, 2U> b_y;
  array<int, 2U> c_y;
  array<unsigned int, 2U> d_y;
  array<unsigned int, 2U> y;
  array<int, 1U> b_dx;
  array<int, 1U> c_dx;
  array<signed char, 2U> e_y;
  array<signed char, 2U> f_y;
  double R;
  int b_i;
  int i;
  int last;
  int loop_ub;
  int n;
  int nx;
  if (dx.size(0) < 2) {
    y.set_size(1, 0);
  } else {
    y.set_size(1, dx.size(0) - 1);
    loop_ub = dx.size(0) - 2;
    for (i = 0; i <= loop_ub; i++) {
      y[i] = i + 2U;
    }
  }
  b_y.set_size(1, y.size(1) + 1);
  loop_ub = y.size(1);
  for (i = 0; i < loop_ub; i++) {
    b_y[i] = y[i];
  }
  b_y[y.size(1)] = 1U;
  if (dx.size(0) - 1 < 1) {
    y.set_size(1, 0);
    c_y.set_size(1, 0);
  } else {
    y.set_size(1, dx.size(0) - 1);
    loop_ub = dx.size(0) - 2;
    for (i = 0; i <= loop_ub; i++) {
      y[i] = i + 1U;
    }
    loop_ub = dx.size(0) - 2;
    c_y.set_size(1, dx.size(0) - 1);
    for (i = 0; i <= loop_ub; i++) {
      c_y[i] = i + 1;
    }
  }
  if (Jtri.size(0) == 1) {
    i = dx.size(0);
    n = b_y.size(1);
    nx = dx.size(0);
  } else {
    i = Jtri.size(0);
    n = Jtri.size(0);
    nx = Jtri.size(0);
  }
  if (nx == 1) {
    if (Jtri.size(0) == 1) {
      nx = b_y.size(1);
    } else {
      nx = Jtri.size(0);
    }
  } else if (Jtri.size(0) == 1) {
    nx = dx.size(0);
  } else {
    nx = Jtri.size(0);
  }
  if (y.size(1) + 1 == 1) {
    loop_ub = c_y.size(1) + 1;
  } else {
    loop_ub = y.size(1) + 1;
  }
  if ((Jtri.size(0) == dx.size(0)) && (Jtri.size(0) == b_y.size(1)) &&
      (i == n) && (y.size(1) == c_y.size(1)) && (nx == loop_ub)) {
    b_dx.set_size(y.size(1) + 1);
    b_dx[0] = dx.size(0) - 1;
    loop_ub = y.size(1);
    for (i = 0; i < loop_ub; i++) {
      b_dx[i + 1] = static_cast<int>(y[i]) - 1;
    }
    c_dx.set_size(c_y.size(1) + 1);
    c_dx[0] = dx.size(0) - 1;
    loop_ub = c_y.size(1);
    for (i = 0; i < loop_ub; i++) {
      c_dx[i + 1] = c_y[i] - 1;
    }
    loop_ub = Jtri.size(0);
    z.set_size(Jtri.size(0));
    for (i = 0; i < loop_ub; i++) {
      z[i] = (Jtri[i + Jtri.size(0)] * dx[i] +
              Jtri[i + Jtri.size(0) * 2] * dx[static_cast<int>(b_y[i]) - 1]) +
             Jtri[b_dx[i]] * dx[c_dx[i]];
    }
  } else {
    e_binary_expand_op(z, Jtri, dx, b_y, y, c_y);
  }
  if (dx.size(0) < 2) {
    y.set_size(1, 0);
  } else {
    y.set_size(1, dx.size(0) - 1);
    loop_ub = dx.size(0) - 2;
    for (i = 0; i <= loop_ub; i++) {
      y[i] = i + 2U;
    }
  }
  if (dx.size(0) - 1 < 1) {
    c_y.set_size(1, 0);
  } else {
    loop_ub = dx.size(0) - 2;
    c_y.set_size(1, dx.size(0) - 1);
    for (i = 0; i <= loop_ub; i++) {
      c_y[i] = i + 1;
    }
  }
  b_y.set_size(1, c_y.size(1) + 1);
  b_y[0] = static_cast<unsigned int>(dx.size(0));
  loop_ub = c_y.size(1);
  for (i = 0; i < loop_ub; i++) {
    b_y[i + 1] = static_cast<unsigned int>(c_y[i]);
  }
  if (dx.size(0) - 1 < 1) {
    c_y.set_size(1, 0);
  } else {
    loop_ub = dx.size(0) - 2;
    c_y.set_size(1, dx.size(0) - 1);
    for (i = 0; i <= loop_ub; i++) {
      c_y[i] = i + 1;
    }
  }
  d_y.set_size(1, c_y.size(1) + 1);
  d_y[0] = static_cast<unsigned int>(dx.size(0));
  loop_ub = c_y.size(1);
  for (i = 0; i < loop_ub; i++) {
    d_y[i + 1] = static_cast<unsigned int>(c_y[i]);
  }
  if (Jtri.size(0) == 1) {
    i = z.size(0);
    n = y.size(1) + 1;
    nx = z.size(0);
  } else {
    i = Jtri.size(0);
    n = Jtri.size(0);
    nx = Jtri.size(0);
  }
  if (nx == 1) {
    if (Jtri.size(0) == 1) {
      nx = y.size(1) + 1;
    } else {
      nx = Jtri.size(0);
    }
  } else if (Jtri.size(0) == 1) {
    nx = z.size(0);
  } else {
    nx = Jtri.size(0);
  }
  if (b_y.size(1) == 1) {
    loop_ub = d_y.size(1);
  } else {
    loop_ub = b_y.size(1);
  }
  if (Jtri.size(0) == 1) {
    b_i = z.size(0);
  } else {
    b_i = Jtri.size(0);
  }
  if (b_i == 1) {
    if (Jtri.size(0) == 1) {
      b_i = y.size(1) + 1;
    } else {
      b_i = Jtri.size(0);
    }
  } else if (Jtri.size(0) == 1) {
    b_i = z.size(0);
  } else {
    b_i = Jtri.size(0);
  }
  if (Jtri.size(0) == 1) {
    last = z.size(0);
  } else {
    last = Jtri.size(0);
  }
  if (b_i == 1) {
    if (b_y.size(1) == 1) {
      b_i = d_y.size(1);
    } else {
      b_i = b_y.size(1);
    }
  } else if (last == 1) {
    if (Jtri.size(0) == 1) {
      b_i = y.size(1) + 1;
    } else {
      b_i = Jtri.size(0);
    }
  } else if (Jtri.size(0) == 1) {
    b_i = z.size(0);
  } else {
    b_i = Jtri.size(0);
  }
  if ((Jtri.size(0) == z.size(0)) && (Jtri.size(0) == y.size(1) + 1) &&
      (i == n) && (b_y.size(1) == d_y.size(1)) && (nx == loop_ub) &&
      (v.size(0) == b_i)) {
    b_dx.set_size(y.size(1) + 1);
    loop_ub = y.size(1);
    for (i = 0; i < loop_ub; i++) {
      b_dx[i] = static_cast<int>(y[i]) - 1;
    }
    b_dx[y.size(1)] = 0;
    R = 0.0;
    loop_ub = dx.size(0);
    for (i = 0; i < loop_ub; i++) {
      R += dx[i] * (2.0 * v[i] -
                    ((Jtri[i + Jtri.size(0)] * z[i] + Jtri[i] * z[b_dx[i]]) +
                     Jtri[(static_cast<int>(b_y[i]) + Jtri.size(0) * 2) - 1] *
                         z[static_cast<int>(d_y[i]) - 1]));
    }
    R = (S - Snew) / R;
  } else {
    R = binary_expand_op(S, Snew, dx, v, Jtri, z, y, b_y, d_y);
  }
  if (R > 0.75) {
    *lambda /= 2.0;
    if (*lambda < *lambdac) {
      *lambda = 0.0;
    }
  } else if (R < 0.25) {
    double nu;
    R = 0.0;
    loop_ub = dx.size(0);
    for (i = 0; i < loop_ub; i++) {
      R += dx[i] * v[i];
    }
    nu = std::fmin(std::fmax(2.0, (Snew - S) / R + 2.0), 10.0);
    if (*lambda == 0.0) {
      double bet;
      double d;
      bool exitg2;
      n = static_cast<int>(std::fmin(40.0, static_cast<double>(Jtri.size(0))));
      bet = 0.0;
      z.set_size(Jtri.size(0));
      loop_ub = Jtri.size(0);
      for (i = 0; i < loop_ub; i++) {
        z[i] = 0.0;
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
      alpha.set_size(n);
      beta.set_size(n);
      for (b_i = 0; b_i < n; b_i++) {
        if ((Jtri[Jtri.size(0) - 1] == 0.0) &&
            (Jtri[(Jtri.size(0) + Jtri.size(0) * 2) - 1] == 0.0)) {
          loop_ub = Jtri.size(0);
          b.set_size(Jtri.size(0));
          for (i = 0; i < loop_ub; i++) {
            b[i] = Jtri[i + Jtri.size(0)];
          }
          dy.set_size(q.size(0));
          loop_ub = q.size(0);
          for (i = 0; i < loop_ub; i++) {
            dy[i] = q[i];
          }
          i = q.size(0);
          for (last = 0; last <= i - 2; last++) {
            R = Jtri[last + Jtri.size(0) * 2] / b[last];
            b[last + 1] = b[last + 1] - R * Jtri[last];
            dy[last + 1] = dy[last + 1] - R * dy[last];
          }
          dy[q.size(0) - 1] = dy[q.size(0) - 1] / b[q.size(0) - 1];
          i = q.size(0);
          for (last = 0; last <= i - 2; last++) {
            nx = (q.size(0) - last) - 2;
            dy[nx] = (dy[nx] - Jtri[nx] * dy[nx + 1]) / b[nx];
          }
          loop_ub = Jtri.size(0);
          b.set_size(Jtri.size(0));
          for (i = 0; i < loop_ub; i++) {
            b[i] = Jtri[i + Jtri.size(0)];
          }
          b_v.set_size(dy.size(0));
          loop_ub = dy.size(0);
          for (i = 0; i < loop_ub; i++) {
            b_v[i] = dy[i];
          }
          i = dy.size(0);
          for (last = 0; last <= i - 2; last++) {
            R = Jtri[last] / b[last];
            b[last + 1] = b[last + 1] - R * Jtri[last + Jtri.size(0) * 2];
            b_v[last + 1] = b_v[last + 1] - R * b_v[last];
          }
          b_v[dy.size(0) - 1] = b_v[dy.size(0) - 1] / b[dy.size(0) - 1];
          i = dy.size(0);
          for (last = 0; last <= i - 2; last++) {
            nx = (dy.size(0) - last) - 2;
            b_v[nx] =
                (b_v[nx] - Jtri[nx + Jtri.size(0) * 2] * b_v[nx + 1]) / b[nx];
          }
        } else {
          loop_ub = Jtri.size(0);
          b.set_size(Jtri.size(0));
          b_Jtri.set_size(Jtri.size(0));
          c_Jtri.set_size(Jtri.size(0));
          for (i = 0; i < loop_ub; i++) {
            b[i] = Jtri[i + Jtri.size(0) * 2];
            b_Jtri[i] = Jtri[i + Jtri.size(0)];
            c_Jtri[i] = Jtri[i];
          }
          cyctridisolve(b, b_Jtri, c_Jtri, q, dy);
          loop_ub = Jtri.size(0);
          b.set_size(Jtri.size(0));
          b_Jtri.set_size(Jtri.size(0));
          c_Jtri.set_size(Jtri.size(0));
          for (i = 0; i < loop_ub; i++) {
            b[i] = Jtri[i];
            b_Jtri[i] = Jtri[i + Jtri.size(0)];
            c_Jtri[i] = Jtri[i + Jtri.size(0) * 2];
          }
          cyctridisolve(b, b_Jtri, c_Jtri, dy, b_v);
        }
        R = 0.0;
        loop_ub = q.size(0);
        for (i = 0; i < loop_ub; i++) {
          R += q[i] * b_v[i];
        }
        alpha[b_i] = R;
        if (b_v.size(0) == 1) {
          i = z.size(0);
        } else {
          i = b_v.size(0);
        }
        if ((b_v.size(0) == z.size(0)) && (i == q.size(0))) {
          loop_ub = b_v.size(0);
          for (i = 0; i < loop_ub; i++) {
            b_v[i] = (b_v[i] - bet * z[i]) - R * q[i];
          }
        } else {
          binary_expand_op(b_v, bet, z, alpha, b_i, q);
        }
        bet = b_norm(b_v);
        z.set_size(q.size(0));
        loop_ub = q.size(0);
        for (i = 0; i < loop_ub; i++) {
          z[i] = q[i];
        }
        q.set_size(b_v.size(0));
        loop_ub = b_v.size(0);
        for (i = 0; i < loop_ub; i++) {
          q[i] = b_v[i] / bet;
        }
        beta[b_i] = bet;
      }
      if (n - 1 < 1) {
        loop_ub = 0;
        last = 0;
        y.set_size(1, 0);
      } else {
        loop_ub = n - 1;
        last = n - 1;
        y.set_size(1, n - 1);
        nx = n - 2;
        for (i = 0; i <= nx; i++) {
          y[i] = i + 1U;
        }
      }
      if (n < 1) {
        c_y.set_size(1, 0);
      } else {
        c_y.set_size(1, n);
        for (i = 0; i < n; i++) {
          c_y[i] = i + 1;
        }
      }
      if (n < 2) {
        b_y.set_size(1, 0);
        d_y.set_size(1, 0);
      } else {
        b_y.set_size(1, n - 1);
        nx = n - 2;
        d_y.set_size(1, n - 1);
        for (i = 0; i <= nx; i++) {
          b_y[i] = i + 2U;
          d_y[i] = i + 2U;
        }
      }
      if (n < 1) {
        e_y.set_size(1, 0);
      } else {
        e_y.set_size(1, n);
        nx = n - 1;
        for (i = 0; i <= nx; i++) {
          e_y[i] = static_cast<signed char>(i + 1);
        }
      }
      if (n - 1 < 1) {
        f_y.set_size(1, 0);
      } else {
        f_y.set_size(1, n - 1);
        nx = n - 2;
        for (i = 0; i <= nx; i++) {
          f_y[i] = static_cast<signed char>(i + 1);
        }
      }
      g_y.set_size((y.size(1) + c_y.size(1)) + b_y.size(1), 2);
      nx = y.size(1);
      for (i = 0; i < nx; i++) {
        g_y[i] = y[i];
      }
      nx = c_y.size(1);
      for (i = 0; i < nx; i++) {
        g_y[i + y.size(1)] = c_y[i];
      }
      nx = b_y.size(1);
      for (i = 0; i < nx; i++) {
        g_y[(i + y.size(1)) + c_y.size(1)] = b_y[i];
      }
      nx = d_y.size(1);
      for (i = 0; i < nx; i++) {
        g_y[i + g_y.size(0)] = d_y[i];
      }
      nx = e_y.size(1);
      for (i = 0; i < nx; i++) {
        g_y[(i + d_y.size(1)) + g_y.size(0)] = e_y[i];
      }
      nx = f_y.size(1);
      for (i = 0; i < nx; i++) {
        g_y[((i + d_y.size(1)) + e_y.size(1)) + g_y.size(0)] = f_y[i];
      }
      b.set_size((loop_ub + alpha.size(0)) + last);
      for (i = 0; i < loop_ub; i++) {
        b[i] = beta[i];
      }
      nx = alpha.size(0);
      for (i = 0; i < nx; i++) {
        b[i + loop_ub] = alpha[i];
      }
      for (i = 0; i < last; i++) {
        b[(i + loop_ub) + alpha.size(0)] = beta[i];
      }
      double b_n[2];
      b_n[0] = n;
      b_n[1] = n;
      accumarray(g_y, b, b_n, T);
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
                  if (!(T[b_i + T.size(0) * last] ==
                        T[last + T.size(0) * b_i])) {
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
            n = b_T.size(0);
            z.set_size(b_T.size(0));
            for (loop_ub = 0; loop_ub < n; loop_ub++) {
              z[loop_ub] = b_T[loop_ub + b_T.size(0) * loop_ub];
            }
            x.set_size(z.size(0));
            loop_ub = z.size(0);
            for (i = 0; i < loop_ub; i++) {
              x[i].re = z[i];
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
              n = b_T.size(0);
              x.set_size(b_T.size(0));
              b_i = 1;
              do {
                exitg1 = 0;
                if (b_i <= n) {
                  bool guard1{false};
                  guard1 = false;
                  if (b_i != n) {
                    d = b_T[b_i + b_T.size(0) * (b_i - 1)];
                    if (d != 0.0) {
                      *lambda = std::abs(d);
                      x[b_i - 1].re = 0.0;
                      x[b_i - 1].im = *lambda;
                      x[b_i].re = 0.0;
                      x[b_i].im = -*lambda;
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
      z.set_size(x.size(0));
      for (loop_ub = 0; loop_ub < nx; loop_ub++) {
        z[loop_ub] = rt_hypotd_snf(x[loop_ub].re, x[loop_ub].im);
      }
      last = z.size(0);
      if (z.size(0) <= 2) {
        if (z.size(0) == 1) {
          R = z[0];
        } else if ((z[0] > z[z.size(0) - 1]) ||
                   (std::isnan(z[0]) && (!std::isnan(z[z.size(0) - 1])))) {
          R = z[z.size(0) - 1];
        } else {
          R = z[0];
        }
      } else {
        if (!std::isnan(z[0])) {
          nx = 1;
        } else {
          nx = 0;
          loop_ub = 2;
          exitg2 = false;
          while ((!exitg2) && (loop_ub <= last)) {
            if (!std::isnan(z[loop_ub - 1])) {
              nx = loop_ub;
              exitg2 = true;
            } else {
              loop_ub++;
            }
          }
        }
        if (nx == 0) {
          R = z[0];
        } else {
          R = z[nx - 1];
          i = nx + 1;
          for (loop_ub = i; loop_ub <= last; loop_ub++) {
            d = z[loop_ub - 1];
            if (R > d) {
              R = d;
            }
          }
        }
      }
      *lambdac = 1.0 / R;
      *lambda = *lambdac;
      nu /= 2.0;
    }
    *lambda *= nu;
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
  array<unsigned int, 2U> b_y;
  array<int, 2U> c_y;
  array<unsigned int, 2U> r;
  array<int, 1U> b_x;
  array<int, 1U> c_x;
  int i;
  int i1;
  int i2;
  int loop_ub;
  if (x.size(0) < 2) {
    b_y.set_size(1, 0);
  } else {
    b_y.set_size(1, x.size(0) - 1);
    loop_ub = x.size(0) - 2;
    for (i = 0; i <= loop_ub; i++) {
      b_y[i] = i + 2U;
    }
  }
  r.set_size(1, b_y.size(1) + 1);
  loop_ub = b_y.size(1);
  for (i = 0; i < loop_ub; i++) {
    r[i] = b_y[i];
  }
  r[b_y.size(1)] = 1U;
  if (x.size(0) - 1 < 1) {
    b_y.set_size(1, 0);
    c_y.set_size(1, 0);
  } else {
    b_y.set_size(1, x.size(0) - 1);
    loop_ub = x.size(0) - 2;
    for (i = 0; i <= loop_ub; i++) {
      b_y[i] = i + 1U;
    }
    loop_ub = x.size(0) - 2;
    c_y.set_size(1, x.size(0) - 1);
    for (i = 0; i <= loop_ub; i++) {
      c_y[i] = i + 1;
    }
  }
  if (Jtri.size(0) == 1) {
    i = x.size(0);
    loop_ub = r.size(1);
    i1 = x.size(0);
  } else {
    i = Jtri.size(0);
    loop_ub = Jtri.size(0);
    i1 = Jtri.size(0);
  }
  if (i1 == 1) {
    if (Jtri.size(0) == 1) {
      i1 = r.size(1);
    } else {
      i1 = Jtri.size(0);
    }
  } else if (Jtri.size(0) == 1) {
    i1 = x.size(0);
  } else {
    i1 = Jtri.size(0);
  }
  if (b_y.size(1) + 1 == 1) {
    i2 = c_y.size(1) + 1;
  } else {
    i2 = b_y.size(1) + 1;
  }
  if ((Jtri.size(0) == x.size(0)) && (Jtri.size(0) == r.size(1)) &&
      (i == loop_ub) && (b_y.size(1) == c_y.size(1)) && (i1 == i2)) {
    b_x.set_size(b_y.size(1) + 1);
    b_x[0] = x.size(0) - 1;
    loop_ub = b_y.size(1);
    for (i = 0; i < loop_ub; i++) {
      b_x[i + 1] = static_cast<int>(b_y[i]) - 1;
    }
    c_x.set_size(c_y.size(1) + 1);
    c_x[0] = x.size(0) - 1;
    loop_ub = c_y.size(1);
    for (i = 0; i < loop_ub; i++) {
      c_x[i + 1] = c_y[i] - 1;
    }
    loop_ub = Jtri.size(0);
    y.set_size(Jtri.size(0));
    for (i = 0; i < loop_ub; i++) {
      y[i] = (Jtri[i + Jtri.size(0)] * x[i] +
              Jtri[i] * x[static_cast<int>(r[i]) - 1]) +
             Jtri[b_x[i] + Jtri.size(0) * 2] * x[c_x[i]];
    }
  } else {
    binary_expand_op(y, Jtri, x, r, b_y, c_y);
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
  array<double, 2U> g_y;
  array<double, 1U> alpha;
  array<double, 1U> b_gamma;
  array<double, 1U> d;
  array<double, 1U> delta;
  array<double, 1U> e;
  array<double, 1U> f;
  array<unsigned int, 2U> b_y;
  array<unsigned int, 2U> y;
  array<int, 1U> b_v;
  array<signed char, 2U> c_y;
  array<signed char, 2U> d_y;
  array<signed char, 2U> e_y;
  array<signed char, 2U> f_y;
  double bkj;
  int i;
  int loop_ub;
  if (v.size(0) - 1 < 1) {
    y.set_size(1, 0);
  } else {
    y.set_size(1, v.size(0) - 1);
    loop_ub = v.size(0) - 2;
    for (i = 0; i <= loop_ub; i++) {
      y[i] = i + 1U;
    }
  }
  loop_ub = Jtri.size(0);
  d.set_size(Jtri.size(0));
  for (i = 0; i < loop_ub; i++) {
    bkj = Jtri[i];
    d[i] = bkj * bkj;
  }
  loop_ub = Jtri.size(0);
  e.set_size(Jtri.size(0));
  for (i = 0; i < loop_ub; i++) {
    bkj = Jtri[i + Jtri.size(0)];
    e[i] = bkj * bkj;
  }
  b_v.set_size(y.size(1) + 1);
  b_v[0] = v.size(0) - 1;
  loop_ub = y.size(1);
  for (i = 0; i < loop_ub; i++) {
    b_v[i + 1] = static_cast<int>(y[i]) - 1;
  }
  f.set_size(b_v.size(0));
  loop_ub = b_v.size(0);
  for (i = 0; i < loop_ub; i++) {
    bkj = Jtri[b_v[i] + Jtri.size(0) * 2];
    f[i] = bkj * bkj;
  }
  if (d.size(0) == 1) {
    i = e.size(0);
  } else {
    i = d.size(0);
  }
  if ((d.size(0) == e.size(0)) && (i == f.size(0))) {
    loop_ub = d.size(0);
    for (i = 0; i < loop_ub; i++) {
      d[i] = ((d[i] + e[i]) + f[i]) * (lambda + 1.0);
    }
  } else {
    binary_expand_op(d, e, f, lambda);
  }
  if (v.size(0) < 2) {
    y.set_size(1, 0);
  } else {
    y.set_size(1, v.size(0) - 1);
    loop_ub = v.size(0) - 2;
    for (i = 0; i <= loop_ub; i++) {
      y[i] = i + 2U;
    }
  }
  if (Jtri.size(0) == 1) {
    i = y.size(1) + 1;
  } else {
    i = Jtri.size(0);
  }
  if ((Jtri.size(0) == y.size(1) + 1) && (i == Jtri.size(0))) {
    b_v.set_size(y.size(1) + 1);
    loop_ub = y.size(1);
    for (i = 0; i < loop_ub; i++) {
      b_v[i] = static_cast<int>(y[i]) - 1;
    }
    b_v[y.size(1)] = 0;
    loop_ub = Jtri.size(0);
    e.set_size(Jtri.size(0));
    for (i = 0; i < loop_ub; i++) {
      e[i] = Jtri[i] * Jtri[b_v[i] + Jtri.size(0)] +
             Jtri[i + Jtri.size(0)] * Jtri[i + Jtri.size(0) * 2];
    }
  } else {
    e_binary_expand_op(e, Jtri, y);
  }
  if (v.size(0) < 2) {
    y.set_size(1, 0);
  } else {
    y.set_size(1, v.size(0) - 1);
    loop_ub = v.size(0) - 2;
    for (i = 0; i <= loop_ub; i++) {
      y[i] = i + 2U;
    }
  }
  b_y.set_size(1, y.size(1) + 1);
  loop_ub = y.size(1);
  for (i = 0; i < loop_ub; i++) {
    b_y[i] = y[i];
  }
  b_y[y.size(1)] = 1U;
  if (Jtri.size(0) == b_y.size(1)) {
    loop_ub = Jtri.size(0);
    f.set_size(Jtri.size(0));
    for (i = 0; i < loop_ub; i++) {
      f[i] = Jtri[i] * Jtri[(static_cast<int>(b_y[i]) + Jtri.size(0) * 2) - 1];
    }
  } else {
    binary_expand_op(f, Jtri, b_y);
  }
  if (v.size(0) < 5) {
    int nv;
    int u1;
    if (v.size(0) < 1) {
      y.set_size(1, 0);
      b_y.set_size(1, 0);
    } else {
      y.set_size(1, v.size(0));
      loop_ub = v.size(0) - 1;
      for (i = 0; i <= loop_ub; i++) {
        y[i] = i + 1U;
      }
      b_y.set_size(1, v.size(0));
      loop_ub = v.size(0) - 1;
      for (i = 0; i <= loop_ub; i++) {
        b_y[i] = i + 1U;
      }
    }
    if (v.size(0) < 2) {
      c_y.set_size(1, 0);
      d_y.set_size(1, 0);
    } else {
      c_y.set_size(1, v.size(0) - 1);
      loop_ub = v.size(0) - 2;
      for (i = 0; i <= loop_ub; i++) {
        c_y[i] = static_cast<signed char>(i + 2);
      }
      d_y.set_size(1, v.size(0) - 1);
      loop_ub = v.size(0) - 2;
      for (i = 0; i <= loop_ub; i++) {
        d_y[i] = static_cast<signed char>(i + 2);
      }
    }
    if (v.size(0) < 1) {
      e_y.set_size(1, 0);
      f_y.set_size(1, 0);
    } else {
      e_y.set_size(1, v.size(0));
      loop_ub = v.size(0) - 1;
      for (i = 0; i <= loop_ub; i++) {
        e_y[i] = static_cast<signed char>(i + 1);
      }
      f_y.set_size(1, v.size(0));
      loop_ub = v.size(0) - 1;
      for (i = 0; i <= loop_ub; i++) {
        f_y[i] = static_cast<signed char>(i + 1);
      }
    }
    g_y.set_size(((y.size(1) + b_y.size(1)) + c_y.size(1)) + 1, 2);
    loop_ub = y.size(1);
    for (i = 0; i < loop_ub; i++) {
      g_y[i] = y[i];
    }
    loop_ub = b_y.size(1);
    for (i = 0; i < loop_ub; i++) {
      g_y[i + y.size(1)] = b_y[i];
    }
    loop_ub = c_y.size(1);
    for (i = 0; i < loop_ub; i++) {
      g_y[(i + y.size(1)) + b_y.size(1)] = c_y[i];
    }
    g_y[(y.size(1) + b_y.size(1)) + c_y.size(1)] = 1.0;
    loop_ub = d_y.size(1);
    for (i = 0; i < loop_ub; i++) {
      g_y[i + g_y.size(0)] = d_y[i];
    }
    g_y[d_y.size(1) + g_y.size(0)] = 1.0;
    loop_ub = e_y.size(1);
    for (i = 0; i < loop_ub; i++) {
      g_y[((i + d_y.size(1)) + g_y.size(0)) + 1] = e_y[i];
    }
    loop_ub = f_y.size(1);
    for (i = 0; i < loop_ub; i++) {
      g_y[(((i + d_y.size(1)) + e_y.size(1)) + g_y.size(0)) + 1] = f_y[i];
    }
    loop_ub = Jtri.size(0);
    nv = Jtri.size(0);
    u1 = Jtri.size(0);
    d.set_size((Jtri.size(0) + Jtri.size(0)) + Jtri.size(0));
    for (i = 0; i < loop_ub; i++) {
      d[i] = Jtri[i];
    }
    for (i = 0; i < nv; i++) {
      d[i + loop_ub] = Jtri[i + Jtri.size(0)];
    }
    for (i = 0; i < u1; i++) {
      d[(i + loop_ub) + nv] = Jtri[i + Jtri.size(0) * 2];
    }
    double c_v[2];
    c_v[0] = v.size(0);
    c_v[1] = v.size(0);
    accumarray(g_y, d, c_v, J);
    u1 = J.size(1);
    nv = J.size(0);
    loop_ub = J.size(1);
    A.set_size(J.size(1), J.size(1));
    for (int j{0}; j < loop_ub; j++) {
      int boffset;
      int coffset;
      coffset = j * u1;
      boffset = j * J.size(0);
      for (int b_i{0}; b_i < u1; b_i++) {
        A[coffset + b_i] = 0.0;
      }
      for (int k{0}; k < nv; k++) {
        bkj = J[boffset + k];
        for (int b_i{0}; b_i < u1; b_i++) {
          i = coffset + b_i;
          A[i] = A[i] + J[b_i * J.size(0) + k] * bkj;
        }
      }
    }
    if ((A.size(0) == 1) && (A.size(1) == 1)) {
      e.set_size(1);
      e[0] = A[0];
    } else {
      nv = A.size(0);
      u1 = A.size(1);
      if (nv <= u1) {
        u1 = nv;
      }
      if (A.size(1) > 0) {
        nv = u1;
      } else {
        nv = 0;
      }
      e.set_size(nv);
      i = nv - 1;
      for (int k{0}; k <= i; k++) {
        e[k] = A[k + A.size(0) * k];
      }
    }
    loop_ub = e.size(0);
    for (i = 0; i < loop_ub; i++) {
      e[i] = lambda * e[i];
    }
    nv = e.size(0);
    J.set_size(e.size(0), e.size(0));
    loop_ub = e.size(0) * e.size(0);
    for (i = 0; i < loop_ub; i++) {
      J[i] = 0.0;
    }
    for (int j{0}; j < nv; j++) {
      J[j + J.size(0) * j] = e[j];
    }
    dx.set_size(v.size(0));
    loop_ub = v.size(0);
    for (i = 0; i < loop_ub; i++) {
      dx[i] = v[i];
    }
    if ((A.size(0) == J.size(0)) && (A.size(1) == J.size(1))) {
      b_A.set_size(A.size(0), A.size(1));
      loop_ub = A.size(0) * A.size(1);
      for (i = 0; i < loop_ub; i++) {
        b_A[i] = A[i] + J[i];
      }
      mldivide(b_A, dx);
    } else {
      binary_expand_op(A, J, dx);
    }
  } else if ((Jtri[Jtri.size(0) - 1] == 0.0) &&
             (Jtri[(Jtri.size(0) + Jtri.size(0) * 2) - 1] == 0.0)) {
    int nv;
    int u1;
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
    b_gamma.set_size(v.size(0) - 1);
    loop_ub = v.size(0);
    for (i = 0; i <= loop_ub - 2; i++) {
      b_gamma[i] = 0.0;
    }
    delta.set_size(v.size(0) - 2);
    loop_ub = v.size(0);
    for (i = 0; i <= loop_ub - 3; i++) {
      delta[i] = 0.0;
    }
    alpha[0] = d[0];
    b_gamma[0] = e[0] / alpha[0];
    delta[0] = f[0] / alpha[0];
    alpha[1] = d[1] - e[0] * b_gamma[0];
    b_gamma[1] = (e[1] - f[0] * b_gamma[0]) / alpha[1];
    delta[1] = f[1] / alpha[1];
    i = v.size(0);
    for (int k{0}; k <= i - 5; k++) {
      double b_d;
      bkj = b_gamma[k + 1];
      b_d = (d[k + 2] - f[k] * delta[k]) - alpha[k + 1] * (bkj * bkj);
      alpha[k + 2] = b_d;
      b_gamma[k + 2] = (e[k + 2] - f[k + 1] * bkj) / b_d;
      delta[k + 2] = f[k + 2] / b_d;
    }
    alpha[v.size(0) - 2] =
        (d[v.size(0) - 2] - f[v.size(0) - 4] * delta[v.size(0) - 4]) -
        alpha[v.size(0) - 3] *
            (b_gamma[v.size(0) - 3] * b_gamma[v.size(0) - 3]);
    b_gamma[v.size(0) - 2] =
        (e[v.size(0) - 2] - f[v.size(0) - 3] * b_gamma[v.size(0) - 3]) /
        alpha[v.size(0) - 2];
    alpha[v.size(0) - 1] =
        (d[v.size(0) - 1] - f[v.size(0) - 3] * delta[v.size(0) - 3]) -
        alpha[v.size(0) - 2] *
            (b_gamma[v.size(0) - 2] * b_gamma[v.size(0) - 2]);
    e.set_size(v.size(0));
    loop_ub = v.size(0);
    for (i = 0; i < loop_ub; i++) {
      e[i] = 0.0;
    }
    e[0] = v[0];
    e[1] = v[1] - b_gamma[0] * e[0];
    i = v.size(0);
    for (int k{0}; k <= i - 3; k++) {
      e[k + 2] = (v[k + 2] - b_gamma[k + 1] * e[k + 1]) - delta[k] * e[k];
    }
    nv = alpha.size(0);
    u1 = e.size(0);
    if (nv <= u1) {
      u1 = nv;
    }
    if (e.size(0) == alpha.size(0)) {
      u1 = e.size(0);
    }
    f.set_size(u1);
    nv = alpha.size(0);
    u1 = e.size(0);
    if (nv <= u1) {
      u1 = nv;
    }
    if (e.size(0) == alpha.size(0)) {
      u1 = e.size(0);
    }
    i = u1 - 1;
    for (int k{0}; k <= i; k++) {
      f[k] = e[k] / alpha[k];
    }
    dx[v.size(0) - 1] = f[v.size(0) - 1];
    dx[v.size(0) - 2] =
        f[v.size(0) - 2] - b_gamma[v.size(0) - 2] * dx[v.size(0) - 1];
    i = v.size(0);
    for (int k{0}; k <= i - 3; k++) {
      nv = (v.size(0) - k) - 3;
      dx[nv] = (f[nv] - b_gamma[nv] * dx[nv + 1]) - delta[nv] * dx[nv + 2];
    }
  } else {
    cycsympentdisolve(d, e, f, v, dx);
  }
}

//
// Arguments    : coder::array<bool, 1U> &in1
//                const coder::array<double, 1U> &in2
//                const int in3[2]
// Return Type  : void
//
} // namespace scenario
} // namespace internal
} // namespace tracking
} // namespace matlabshared
} // namespace coder
void j_binary_expand_op(coder::array<bool, 1U> &in1,
                        const coder::array<double, 1U> &in2, const int in3[2])
{
  int b_in3_idx_0;
  int in3_idx_0;
  in3_idx_0 = in3[0];
  if (in3_idx_0 == 1) {
    b_in3_idx_0 = in2.size(0);
  } else {
    b_in3_idx_0 = in3_idx_0;
  }
  in1.set_size(b_in3_idx_0);
  b_in3_idx_0 = (in2.size(0) != 1);
  if (in3_idx_0 == 1) {
    in3_idx_0 = in2.size(0);
  }
  for (int i{0}; i < in3_idx_0; i++) {
    in1[i] = (in2[i * b_in3_idx_0] >= 1.0E-7);
  }
}

//
// File trailer for LMFsolve.cpp
//
// [EOF]
//
