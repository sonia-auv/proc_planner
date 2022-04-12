//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: div.cpp
//
// MATLAB Coder version            : 5.4
// C/C++ source code generated on  : 12-Apr-2022 11:44:16
//

// Include Files
#include "div.h"
#include "proc_planner_data.h"
#include "quaternion.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <cmath>
#include <string.h>

// Function Definitions
//
// Arguments    : coder::quaternion *in1
//                const coder::array<double, 2U> &in2
// Return Type  : void
//
void binary_expand_op(coder::quaternion *in1,
                      const coder::array<double, 2U> &in2)
{
  coder::array<double, 2U> b_in1;
  int i;
  int loop_ub;
  int stride_0_1;
  int stride_1_1;
  if (in2.size(1) == 1) {
    i = in1->d.size(1);
  } else {
    i = in2.size(1);
  }
  b_in1.set_size(1, i);
  stride_0_1 = (in1->d.size(1) != 1);
  stride_1_1 = (in2.size(1) != 1);
  if (in2.size(1) == 1) {
    loop_ub = in1->d.size(1);
  } else {
    loop_ub = in2.size(1);
  }
  for (i = 0; i < loop_ub; i++) {
    b_in1[i] = in1->d[i * stride_0_1] / in2[i * stride_1_1];
  }
  in1->d.set_size(1, b_in1.size(1));
  loop_ub = b_in1.size(1);
  for (i = 0; i < loop_ub; i++) {
    in1->d[i] = b_in1[i];
  }
}

//
// Arguments    : coder::quaternion *in1
//                const coder::quaternion *in2
//                const coder::array<double, 2U> &in3
// Return Type  : void
//
void binary_expand_op(coder::quaternion *in1, const coder::quaternion *in2,
                      const coder::array<double, 2U> &in3)
{
  int i;
  int loop_ub;
  int stride_0_1;
  int stride_1_1;
  if (in3.size(1) == 1) {
    i = in2->d.size(1);
  } else {
    i = in3.size(1);
  }
  in1->d.set_size(1, i);
  stride_0_1 = (in2->d.size(1) != 1);
  stride_1_1 = (in3.size(1) != 1);
  if (in3.size(1) == 1) {
    loop_ub = in2->d.size(1);
  } else {
    loop_ub = in3.size(1);
  }
  for (i = 0; i < loop_ub; i++) {
    in1->d[i] = in2->d[i * stride_0_1] / in3[i * stride_1_1];
  }
}

//
// Arguments    : coder::quaternion *in1
//                const coder::array<double, 2U> &in2
//                const coder::array<double, 2U> &in3
// Return Type  : void
//
void binary_expand_op(coder::quaternion *in1,
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
  in1->d.set_size(1, i);
  stride_0_1 = (in2.size(1) != 1);
  stride_1_1 = (in3.size(1) != 1);
  if (in3.size(1) == 1) {
    loop_ub = in2.size(1);
  } else {
    loop_ub = in3.size(1);
  }
  for (i = 0; i < loop_ub; i++) {
    in1->d[i] = in2[i * stride_0_1] / in3[i * stride_1_1];
  }
}

//
// Arguments    : coder::array<double, 2U> &in1
//                const coder::array<double, 2U> &in2
//                const coder::array<double, 2U> &in3
//                const coder::array<double, 2U> &in4
//                const coder::array<double, 2U> &in5
// Return Type  : void
//
void binary_expand_op(coder::array<double, 2U> &in1,
                      const coder::array<double, 2U> &in2,
                      const coder::array<double, 2U> &in3,
                      const coder::array<double, 2U> &in4,
                      const coder::array<double, 2U> &in5)
{
  coder::array<double, 2U> b_in2;
  int i;
  int i1;
  int loop_ub;
  int stride_0_1;
  int stride_1_1;
  int stride_2_1;
  int stride_3_1;
  int stride_4_1;
  int stride_5_1;
  int stride_6_1;
  int stride_7_1;
  int stride_8_1;
  int stride_9_1;
  if (in5.size(1) == 1) {
    i = in1.size(1);
  } else {
    i = in5.size(1);
  }
  if (i == 1) {
    i = in2.size(1);
  } else if (in5.size(1) == 1) {
    i = in1.size(1);
  } else {
    i = in5.size(1);
  }
  if (in5.size(1) == 1) {
    i1 = in1.size(1);
  } else {
    i1 = in5.size(1);
  }
  if (i == 1) {
    if (in5.size(1) == 1) {
      i = in1.size(1);
    } else {
      i = in5.size(1);
    }
  } else if (i1 == 1) {
    i = in2.size(1);
  } else if (in5.size(1) == 1) {
    i = in1.size(1);
  } else {
    i = in5.size(1);
  }
  if (in5.size(1) == 1) {
    i1 = in4.size(1);
  } else {
    i1 = in5.size(1);
  }
  if (i1 == 1) {
    if (in1.size(1) == 1) {
      i1 = in3.size(1);
    } else {
      i1 = in1.size(1);
    }
  } else if (in5.size(1) == 1) {
    i1 = in4.size(1);
  } else {
    i1 = in5.size(1);
  }
  if (in5.size(1) == 1) {
    loop_ub = in4.size(1);
    stride_0_1 = in1.size(1);
  } else {
    loop_ub = in5.size(1);
    stride_0_1 = in5.size(1);
  }
  if (stride_0_1 == 1) {
    stride_0_1 = in2.size(1);
  } else if (in5.size(1) == 1) {
    stride_0_1 = in1.size(1);
  } else {
    stride_0_1 = in5.size(1);
  }
  if (in5.size(1) == 1) {
    stride_1_1 = in1.size(1);
  } else {
    stride_1_1 = in5.size(1);
  }
  if (i == 1) {
    if (i1 == 1) {
      i = in2.size(1);
    } else if (loop_ub == 1) {
      if (in1.size(1) == 1) {
        i = in3.size(1);
      } else {
        i = in1.size(1);
      }
    } else if (in5.size(1) == 1) {
      i = in4.size(1);
    } else {
      i = in5.size(1);
    }
  } else if (stride_0_1 == 1) {
    if (in5.size(1) == 1) {
      i = in1.size(1);
    } else {
      i = in5.size(1);
    }
  } else if (stride_1_1 == 1) {
    i = in2.size(1);
  } else if (in5.size(1) == 1) {
    i = in1.size(1);
  } else {
    i = in5.size(1);
  }
  b_in2.set_size(1, i);
  stride_0_1 = (in2.size(1) != 1);
  stride_1_1 = (in3.size(1) != 1);
  stride_2_1 = (in1.size(1) != 1);
  stride_3_1 = (in4.size(1) != 1);
  stride_4_1 = (in5.size(1) != 1);
  stride_5_1 = (in1.size(1) != 1);
  stride_6_1 = (in5.size(1) != 1);
  stride_7_1 = (in2.size(1) != 1);
  stride_8_1 = (in1.size(1) != 1);
  stride_9_1 = (in5.size(1) != 1);
  if (in5.size(1) == 1) {
    i = in1.size(1);
  } else {
    i = in5.size(1);
  }
  if (i == 1) {
    i = in2.size(1);
  } else if (in5.size(1) == 1) {
    i = in1.size(1);
  } else {
    i = in5.size(1);
  }
  if (in5.size(1) == 1) {
    i1 = in1.size(1);
  } else {
    i1 = in5.size(1);
  }
  if (i == 1) {
    if (in5.size(1) == 1) {
      i = in1.size(1);
    } else {
      i = in5.size(1);
    }
  } else if (i1 == 1) {
    i = in2.size(1);
  } else if (in5.size(1) == 1) {
    i = in1.size(1);
  } else {
    i = in5.size(1);
  }
  if (i == 1) {
    if (in5.size(1) == 1) {
      i = in4.size(1);
    } else {
      i = in5.size(1);
    }
    if (i == 1) {
      if (in1.size(1) == 1) {
        i = in3.size(1);
      } else {
        i = in1.size(1);
      }
    } else if (in5.size(1) == 1) {
      i = in4.size(1);
    } else {
      i = in5.size(1);
    }
    if (i == 1) {
      loop_ub = in2.size(1);
    } else {
      if (in5.size(1) == 1) {
        i = in4.size(1);
      } else {
        i = in5.size(1);
      }
      if (i == 1) {
        if (in1.size(1) == 1) {
          loop_ub = in3.size(1);
        } else {
          loop_ub = in1.size(1);
        }
      } else if (in5.size(1) == 1) {
        loop_ub = in4.size(1);
      } else {
        loop_ub = in5.size(1);
      }
    }
  } else {
    if (in5.size(1) == 1) {
      i = in1.size(1);
    } else {
      i = in5.size(1);
    }
    if (i == 1) {
      i = in2.size(1);
    } else if (in5.size(1) == 1) {
      i = in1.size(1);
    } else {
      i = in5.size(1);
    }
    if (i == 1) {
      if (in5.size(1) == 1) {
        loop_ub = in1.size(1);
      } else {
        loop_ub = in5.size(1);
      }
    } else {
      if (in5.size(1) == 1) {
        i = in1.size(1);
      } else {
        i = in5.size(1);
      }
      if (i == 1) {
        loop_ub = in2.size(1);
      } else if (in5.size(1) == 1) {
        loop_ub = in1.size(1);
      } else {
        loop_ub = in5.size(1);
      }
    }
  }
  for (i = 0; i < loop_ub; i++) {
    b_in2[i] =
        in2[i * stride_0_1] *
        (in3[i * stride_1_1] * in1[i * stride_2_1] +
         in4[i * stride_3_1] * in5[i * stride_4_1]) /
        (2.0 * (in1[i * stride_5_1] * in5[i * stride_6_1]) +
         in2[i * stride_7_1] * (in1[i * stride_8_1] + in5[i * stride_9_1]));
  }
  in1.set_size(1, b_in2.size(1));
  loop_ub = b_in2.size(1);
  for (i = 0; i < loop_ub; i++) {
    in1[i] = b_in2[i];
  }
}

//
// Arguments    : coder::array<double, 1U> &in1
//                const coder::array<double, 1U> &in2
//                const coder::array<double, 1U> &in3
// Return Type  : void
//
void binary_expand_op(coder::array<double, 1U> &in1,
                      const coder::array<double, 1U> &in2,
                      const coder::array<double, 1U> &in3)
{
  coder::array<double, 1U> b_in1;
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
  b_in1.set_size(i);
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
  for (i = 0; i < loop_ub; i++) {
    b_in1[i] =
        (in1[i * stride_0_0] + in2[i * stride_1_0]) / in3[i * stride_2_0];
  }
  in1.set_size(b_in1.size(0));
  loop_ub = b_in1.size(0);
  for (i = 0; i < loop_ub; i++) {
    in1[i] = b_in1[i];
  }
}

//
// Arguments    : coder::array<double, 1U> &in1
//                const coder::array<creal_T, 1U> &in2
// Return Type  : void
//
void binary_expand_op(coder::array<double, 1U> &in1,
                      const coder::array<creal_T, 1U> &in2)
{
  coder::array<double, 1U> b_in1;
  int i;
  int loop_ub;
  int stride_0_0;
  int stride_1_0;
  if (in2.size(0) == 1) {
    i = in1.size(0);
  } else {
    i = in2.size(0);
  }
  b_in1.set_size(i);
  stride_0_0 = (in1.size(0) != 1);
  stride_1_0 = (in2.size(0) != 1);
  if (in2.size(0) == 1) {
    loop_ub = in1.size(0);
  } else {
    loop_ub = in2.size(0);
  }
  for (i = 0; i < loop_ub; i++) {
    b_in1[i] = in1[i * stride_0_0] / in2[i * stride_1_0].re;
  }
  in1.set_size(b_in1.size(0));
  loop_ub = b_in1.size(0);
  for (i = 0; i < loop_ub; i++) {
    in1[i] = b_in1[i];
  }
}

//
// Arguments    : coder::array<creal_T, 1U> &in1
//                const coder::array<creal_T, 1U> &in2
//                int in3
// Return Type  : void
//
void binary_expand_op(coder::array<creal_T, 1U> &in1,
                      const coder::array<creal_T, 1U> &in2, int in3)
{
  coder::array<creal_T, 1U> b_in1;
  int i;
  int loop_ub;
  int stride_0_0;
  int stride_1_0;
  if (in2.size(0) == 1) {
    i = in1.size(0);
  } else {
    i = in2.size(0);
  }
  b_in1.set_size(i);
  stride_0_0 = (in1.size(0) != 1);
  stride_1_0 = (in2.size(0) != 1);
  if (in2.size(0) == 1) {
    loop_ub = in1.size(0);
  } else {
    loop_ub = in2.size(0);
  }
  for (i = 0; i < loop_ub; i++) {
    double b_in1_re_tmp;
    double in1_im;
    double in1_re;
    int in1_re_tmp;
    in1_re_tmp = i * stride_1_0;
    in1_im = in2[in1_re_tmp].im;
    b_in1_re_tmp = in2[in1_re_tmp].re;
    in1_re =
        in1[i * stride_0_0].re * b_in1_re_tmp - in1[i * stride_0_0].im * in1_im;
    in1_im =
        in1[i * stride_0_0].re * in1_im + in1[i * stride_0_0].im * b_in1_re_tmp;
    if (in1_im == 0.0) {
      b_in1[i].re = in1_re / ((static_cast<double>(in3) + 1.0) + 1.0);
      b_in1[i].im = 0.0;
    } else if (in1_re == 0.0) {
      b_in1[i].re = 0.0;
      b_in1[i].im = in1_im / ((static_cast<double>(in3) + 1.0) + 1.0);
    } else {
      b_in1[i].re = in1_re / ((static_cast<double>(in3) + 1.0) + 1.0);
      b_in1[i].im = in1_im / ((static_cast<double>(in3) + 1.0) + 1.0);
    }
  }
  in1.set_size(b_in1.size(0));
  loop_ub = b_in1.size(0);
  for (i = 0; i < loop_ub; i++) {
    in1[i] = b_in1[i];
  }
}

//
// Arguments    : coder::array<creal_T, 1U> &in1
//                const coder::array<creal_T, 1U> &in2
//                const coder::array<creal_T, 1U> &in4
//                int in5
// Return Type  : void
//
void binary_expand_op(coder::array<creal_T, 1U> &in1,
                      const coder::array<creal_T, 1U> &in2,
                      const coder::array<creal_T, 1U> &in4, int in5)
{
  coder::array<creal_T, 1U> b_in2;
  int i;
  int loop_ub;
  int stride_0_0;
  int stride_1_0;
  int stride_2_0;
  if (in1.size(0) == 1) {
    i = in4.size(0);
  } else {
    i = in1.size(0);
  }
  if (i == 1) {
    i = in2.size(0);
  } else if (in1.size(0) == 1) {
    i = in4.size(0);
  } else {
    i = in1.size(0);
  }
  b_in2.set_size(i);
  stride_0_0 = (in2.size(0) != 1);
  stride_1_0 = (in4.size(0) != 1);
  stride_2_0 = (in1.size(0) != 1);
  if (in1.size(0) == 1) {
    i = in4.size(0);
  } else {
    i = in1.size(0);
  }
  if (i == 1) {
    loop_ub = in2.size(0);
  } else if (in1.size(0) == 1) {
    loop_ub = in4.size(0);
  } else {
    loop_ub = in1.size(0);
  }
  for (i = 0; i < loop_ub; i++) {
    double ar;
    double c_in4_re_tmp;
    double d_in4_re_tmp;
    double e_in4_re_tmp;
    double f_in4_re_tmp;
    int b_in4_re_tmp;
    int in4_re_tmp;
    in4_re_tmp = i * stride_1_0;
    b_in4_re_tmp = i * stride_2_0;
    c_in4_re_tmp = in4[in4_re_tmp].re;
    d_in4_re_tmp = in1[b_in4_re_tmp].im;
    e_in4_re_tmp = in4[in4_re_tmp].im;
    f_in4_re_tmp = in1[b_in4_re_tmp].re;
    ar = (in2[i * stride_0_0].re * 0.0 - in2[i * stride_0_0].im) +
         (c_in4_re_tmp * f_in4_re_tmp - e_in4_re_tmp * d_in4_re_tmp);
    c_in4_re_tmp = (in2[i * stride_0_0].re + in2[i * stride_0_0].im * 0.0) +
                   (c_in4_re_tmp * d_in4_re_tmp + e_in4_re_tmp * f_in4_re_tmp);
    if (c_in4_re_tmp == 0.0) {
      b_in2[i].re = ar / ((static_cast<double>(in5) + 1.0) + 1.0);
      b_in2[i].im = 0.0;
    } else if (ar == 0.0) {
      b_in2[i].re = 0.0;
      b_in2[i].im = c_in4_re_tmp / ((static_cast<double>(in5) + 1.0) + 1.0);
    } else {
      b_in2[i].re = ar / ((static_cast<double>(in5) + 1.0) + 1.0);
      b_in2[i].im = c_in4_re_tmp / ((static_cast<double>(in5) + 1.0) + 1.0);
    }
  }
  in1.set_size(b_in2.size(0));
  loop_ub = b_in2.size(0);
  for (i = 0; i < loop_ub; i++) {
    in1[i] = b_in2[i];
  }
}

//
// Arguments    : coder::array<creal_T, 1U> &in1
//                const coder::array<double, 1U> &in2
//                const coder::array<creal_T, 1U> &in3
//                const coder::array<double, 1U> &in6
// Return Type  : void
//
void binary_expand_op(coder::array<creal_T, 1U> &in1,
                      const coder::array<double, 1U> &in2,
                      const coder::array<creal_T, 1U> &in3,
                      const coder::array<double, 1U> &in6)
{
  int i;
  int loop_ub;
  int stride_0_0;
  int stride_1_0;
  int stride_2_0;
  int stride_3_0;
  if (in6.size(0) == 1) {
    if (in3.size(0) == 1) {
      i = in2.size(0);
    } else {
      i = in3.size(0);
    }
  } else {
    i = in6.size(0);
  }
  in1.set_size(i);
  stride_0_0 = (in2.size(0) != 1);
  stride_1_0 = (in3.size(0) != 1);
  stride_2_0 = (in3.size(0) != 1);
  stride_3_0 = (in6.size(0) != 1);
  if (in6.size(0) == 1) {
    if (in3.size(0) == 1) {
      loop_ub = in2.size(0);
    } else {
      loop_ub = in3.size(0);
    }
  } else {
    loop_ub = in6.size(0);
  }
  for (i = 0; i < loop_ub; i++) {
    double ar;
    double br;
    double in3_im;
    double in3_re;
    int in3_re_tmp;
    in3_re_tmp = i * stride_2_0;
    in3_re = in3[in3_re_tmp].re - 1.0;
    in3_im = in3[in3_re_tmp].im;
    in3_re_tmp = i * stride_1_0;
    ar = -(in2[i * stride_0_0] * in3[in3_re_tmp].re + (0.0 * in3_re - in3_im));
    in3_re =
        -(in2[i * stride_0_0] * in3[in3_re_tmp].im + (0.0 * in3_im + in3_re));
    br = in6[i * stride_3_0];
    if (in3_re == 0.0) {
      in3_im = ar / br;
      in3_re = 0.0;
    } else if (ar == 0.0) {
      in3_im = 0.0;
      in3_re /= br;
    } else {
      in3_im = ar / br;
      in3_re /= br;
    }
    in1[i].re = in3_im;
    in1[i].im = in3_re;
  }
}

//
// Arguments    : coder::array<creal_T, 1U> &in1
//                const coder::array<creal_T, 1U> &in3
//                const coder::array<creal_T, 1U> &in4
// Return Type  : void
//
void binary_expand_op(coder::array<creal_T, 1U> &in1,
                      const coder::array<creal_T, 1U> &in3,
                      const coder::array<creal_T, 1U> &in4)
{
  int i;
  int loop_ub;
  int stride_0_0;
  int stride_1_0;
  if (in4.size(0) == 1) {
    i = in3.size(0);
  } else {
    i = in4.size(0);
  }
  in1.set_size(i);
  stride_0_0 = (in3.size(0) != 1);
  stride_1_0 = (in4.size(0) != 1);
  if (in4.size(0) == 1) {
    loop_ub = in3.size(0);
  } else {
    loop_ub = in4.size(0);
  }
  for (i = 0; i < loop_ub; i++) {
    double ai;
    double ar;
    double bi;
    double br;
    double im;
    double re;
    int br_tmp;
    ar = 1.0 - in3[i * stride_0_0].re;
    ai = 0.0 - in3[i * stride_0_0].im;
    br_tmp = i * stride_1_0;
    br = in4[br_tmp].re;
    bi = in4[br_tmp].im;
    if (bi == 0.0) {
      if (ai == 0.0) {
        re = ar / br;
        im = 0.0;
      } else if (ar == 0.0) {
        re = 0.0;
        im = ai / br;
      } else {
        re = ar / br;
        im = ai / br;
      }
    } else if (br == 0.0) {
      if (ar == 0.0) {
        re = ai / bi;
        im = 0.0;
      } else if (ai == 0.0) {
        re = 0.0;
        im = -(ar / bi);
      } else {
        re = ai / bi;
        im = -(ar / bi);
      }
    } else {
      double brm;
      brm = std::abs(br);
      im = std::abs(bi);
      if (brm > im) {
        double s;
        s = bi / br;
        im = br + s * bi;
        re = (ar + s * ai) / im;
        im = (ai - s * ar) / im;
      } else if (im == brm) {
        double s;
        if (br > 0.0) {
          s = 0.5;
        } else {
          s = -0.5;
        }
        if (bi > 0.0) {
          im = 0.5;
        } else {
          im = -0.5;
        }
        re = (ar * s + ai * im) / brm;
        im = (ai * s - ar * im) / brm;
      } else {
        double s;
        s = br / bi;
        im = bi + s * br;
        re = (s * ar + ai) / im;
        im = (s * ai - ar) / im;
      }
    }
    in1[i].re = re;
    in1[i].im = im;
  }
}

//
// Arguments    : coder::array<creal_T, 1U> &in1
//                const coder::array<double, 1U> &in2
// Return Type  : void
//
void binary_expand_op(coder::array<creal_T, 1U> &in1,
                      const coder::array<double, 1U> &in2)
{
  coder::array<creal_T, 1U> b_in2;
  int i;
  int loop_ub;
  int stride_0_0;
  int stride_1_0;
  if (in1.size(0) == 1) {
    i = in2.size(0);
  } else {
    i = in1.size(0);
  }
  b_in2.set_size(i);
  stride_0_0 = (in2.size(0) != 1);
  stride_1_0 = (in1.size(0) != 1);
  if (in1.size(0) == 1) {
    loop_ub = in2.size(0);
  } else {
    loop_ub = in1.size(0);
  }
  for (i = 0; i < loop_ub; i++) {
    double ar;
    double bi;
    double br;
    int br_tmp;
    ar = in2[i * stride_0_0];
    br_tmp = i * stride_1_0;
    br = in1[br_tmp].re;
    bi = in1[br_tmp].im;
    if (bi == 0.0) {
      b_in2[i].re = ar / br;
      b_in2[i].im = 0.0;
    } else if (br == 0.0) {
      if (ar == 0.0) {
        b_in2[i].re = 0.0 / bi;
        b_in2[i].im = 0.0;
      } else {
        b_in2[i].re = 0.0;
        b_in2[i].im = -(ar / bi);
      }
    } else {
      double bim;
      double brm;
      brm = std::abs(br);
      bim = std::abs(bi);
      if (brm > bim) {
        double s;
        s = bi / br;
        bim = br + s * bi;
        b_in2[i].re = (ar + s * 0.0) / bim;
        b_in2[i].im = (0.0 - s * ar) / bim;
      } else if (bim == brm) {
        double s;
        if (br > 0.0) {
          s = 0.5;
        } else {
          s = -0.5;
        }
        if (bi > 0.0) {
          bim = 0.5;
        } else {
          bim = -0.5;
        }
        b_in2[i].re = (ar * s + 0.0 * bim) / brm;
        b_in2[i].im = (0.0 * s - ar * bim) / brm;
      } else {
        double s;
        s = br / bi;
        bim = bi + s * br;
        b_in2[i].re = s * ar / bim;
        b_in2[i].im = (s * 0.0 - ar) / bim;
      }
    }
  }
  in1.set_size(b_in2.size(0));
  loop_ub = b_in2.size(0);
  for (i = 0; i < loop_ub; i++) {
    in1[i] = b_in2[i];
  }
}

//
// Arguments    : coder::array<double, 1U> &in1
//                const coder::array<double, 1U> &in2
// Return Type  : void
//
void binary_expand_op(coder::array<double, 1U> &in1,
                      const coder::array<double, 1U> &in2)
{
  coder::array<double, 1U> b_in1;
  int i;
  int loop_ub;
  int stride_0_0;
  int stride_1_0;
  if (in2.size(0) == 1) {
    i = in1.size(0);
  } else {
    i = in2.size(0);
  }
  b_in1.set_size(i);
  stride_0_0 = (in1.size(0) != 1);
  stride_1_0 = (in2.size(0) != 1);
  if (in2.size(0) == 1) {
    loop_ub = in1.size(0);
  } else {
    loop_ub = in2.size(0);
  }
  for (i = 0; i < loop_ub; i++) {
    b_in1[i] = in1[i * stride_0_0] / (4.0 * in2[i * stride_1_0]);
  }
  in1.set_size(b_in1.size(0));
  loop_ub = b_in1.size(0);
  for (i = 0; i < loop_ub; i++) {
    in1[i] = b_in1[i];
  }
}

//
// Arguments    : coder::quaternion *in1
//                const coder::array<double, 2U> &in2
// Return Type  : void
//
void e_binary_expand_op(coder::quaternion *in1,
                        const coder::array<double, 2U> &in2)
{
  coder::array<double, 2U> b_in1;
  int i;
  int loop_ub;
  int stride_0_1;
  int stride_1_1;
  if (in2.size(1) == 1) {
    i = in1->c.size(1);
  } else {
    i = in2.size(1);
  }
  b_in1.set_size(1, i);
  stride_0_1 = (in1->c.size(1) != 1);
  stride_1_1 = (in2.size(1) != 1);
  if (in2.size(1) == 1) {
    loop_ub = in1->c.size(1);
  } else {
    loop_ub = in2.size(1);
  }
  for (i = 0; i < loop_ub; i++) {
    b_in1[i] = in1->c[i * stride_0_1] / in2[i * stride_1_1];
  }
  in1->c.set_size(1, b_in1.size(1));
  loop_ub = b_in1.size(1);
  for (i = 0; i < loop_ub; i++) {
    in1->c[i] = b_in1[i];
  }
}

//
// Arguments    : coder::array<creal_T, 1U> &in1
//                const coder::array<double, 1U> &in3
//                const coder::array<double, 1U> &in4
//                const coder::array<double, 1U> &in5
// Return Type  : void
//
void e_binary_expand_op(coder::array<creal_T, 1U> &in1,
                        const coder::array<double, 1U> &in3,
                        const coder::array<double, 1U> &in4,
                        const coder::array<double, 1U> &in5)
{
  int i;
  int loop_ub;
  int stride_0_0;
  int stride_1_0;
  int stride_2_0;
  if (in5.size(0) == 1) {
    if (in4.size(0) == 1) {
      i = in3.size(0);
    } else {
      i = in4.size(0);
    }
  } else {
    i = in5.size(0);
  }
  in1.set_size(i);
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
  for (i = 0; i < loop_ub; i++) {
    double br;
    double im;
    double re;
    im = in4[i * stride_1_0];
    re = -(0.0 * in3[i * stride_0_0] + 0.0 * im);
    im = -(2.0 * in3[i * stride_0_0] + 2.0 * im);
    br = in5[i * stride_2_0];
    if (im == 0.0) {
      re /= br;
      im = 0.0;
    } else if (re == 0.0) {
      re = 0.0;
      im /= br;
    } else {
      re = rtNaN;
      im /= br;
    }
    in1[i].re = re;
    in1[i].im = im;
  }
}

//
// Arguments    : coder::quaternion *in1
//                const coder::array<double, 2U> &in2
//                const coder::array<double, 2U> &in3
// Return Type  : void
//
void e_binary_expand_op(coder::quaternion *in1,
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
  in1->c.set_size(1, i);
  stride_0_1 = (in2.size(1) != 1);
  stride_1_1 = (in3.size(1) != 1);
  if (in3.size(1) == 1) {
    loop_ub = in2.size(1);
  } else {
    loop_ub = in3.size(1);
  }
  for (i = 0; i < loop_ub; i++) {
    in1->c[i] = in2[i * stride_0_1] / in3[i * stride_1_1];
  }
}

//
// Arguments    : coder::quaternion *in1
//                const coder::quaternion *in2
//                const coder::array<double, 2U> &in3
// Return Type  : void
//
void e_binary_expand_op(coder::quaternion *in1, const coder::quaternion *in2,
                        const coder::array<double, 2U> &in3)
{
  int i;
  int loop_ub;
  int stride_0_1;
  int stride_1_1;
  if (in3.size(1) == 1) {
    i = in2->c.size(1);
  } else {
    i = in3.size(1);
  }
  in1->c.set_size(1, i);
  stride_0_1 = (in2->c.size(1) != 1);
  stride_1_1 = (in3.size(1) != 1);
  if (in3.size(1) == 1) {
    loop_ub = in2->c.size(1);
  } else {
    loop_ub = in3.size(1);
  }
  for (i = 0; i < loop_ub; i++) {
    in1->c[i] = in2->c[i * stride_0_1] / in3[i * stride_1_1];
  }
}

//
// Arguments    : coder::quaternion *in1
//                const coder::array<double, 2U> &in2
//                const coder::array<double, 2U> &in3
// Return Type  : void
//
void f_binary_expand_op(coder::quaternion *in1,
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
  in1->b.set_size(1, i);
  stride_0_1 = (in2.size(1) != 1);
  stride_1_1 = (in3.size(1) != 1);
  if (in3.size(1) == 1) {
    loop_ub = in2.size(1);
  } else {
    loop_ub = in3.size(1);
  }
  for (i = 0; i < loop_ub; i++) {
    in1->b[i] = in2[i * stride_0_1] / in3[i * stride_1_1];
  }
}

//
// Arguments    : coder::quaternion *in1
//                const coder::array<double, 2U> &in2
// Return Type  : void
//
void f_binary_expand_op(coder::quaternion *in1,
                        const coder::array<double, 2U> &in2)
{
  coder::array<double, 2U> b_in1;
  int i;
  int loop_ub;
  int stride_0_1;
  int stride_1_1;
  if (in2.size(1) == 1) {
    i = in1->b.size(1);
  } else {
    i = in2.size(1);
  }
  b_in1.set_size(1, i);
  stride_0_1 = (in1->b.size(1) != 1);
  stride_1_1 = (in2.size(1) != 1);
  if (in2.size(1) == 1) {
    loop_ub = in1->b.size(1);
  } else {
    loop_ub = in2.size(1);
  }
  for (i = 0; i < loop_ub; i++) {
    b_in1[i] = in1->b[i * stride_0_1] / in2[i * stride_1_1];
  }
  in1->b.set_size(1, b_in1.size(1));
  loop_ub = b_in1.size(1);
  for (i = 0; i < loop_ub; i++) {
    in1->b[i] = b_in1[i];
  }
}

//
// Arguments    : coder::quaternion *in1
//                const coder::quaternion *in2
//                const coder::array<double, 2U> &in3
// Return Type  : void
//
void f_binary_expand_op(coder::quaternion *in1, const coder::quaternion *in2,
                        const coder::array<double, 2U> &in3)
{
  int i;
  int loop_ub;
  int stride_0_1;
  int stride_1_1;
  if (in3.size(1) == 1) {
    i = in2->b.size(1);
  } else {
    i = in3.size(1);
  }
  in1->b.set_size(1, i);
  stride_0_1 = (in2->b.size(1) != 1);
  stride_1_1 = (in3.size(1) != 1);
  if (in3.size(1) == 1) {
    loop_ub = in2->b.size(1);
  } else {
    loop_ub = in3.size(1);
  }
  for (i = 0; i < loop_ub; i++) {
    in1->b[i] = in2->b[i * stride_0_1] / in3[i * stride_1_1];
  }
}

//
// Arguments    : coder::quaternion *in1
//                const coder::array<double, 2U> &in2
//                const coder::array<double, 2U> &in3
// Return Type  : void
//
void g_binary_expand_op(coder::quaternion *in1,
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
  in1->a.set_size(1, i);
  stride_0_1 = (in2.size(1) != 1);
  stride_1_1 = (in3.size(1) != 1);
  if (in3.size(1) == 1) {
    loop_ub = in2.size(1);
  } else {
    loop_ub = in3.size(1);
  }
  for (i = 0; i < loop_ub; i++) {
    in1->a[i] = in2[i * stride_0_1] / in3[i * stride_1_1];
  }
}

//
// Arguments    : coder::quaternion *in1
//                const coder::array<double, 2U> &in2
// Return Type  : void
//
void g_binary_expand_op(coder::quaternion *in1,
                        const coder::array<double, 2U> &in2)
{
  coder::array<double, 2U> b_in1;
  int i;
  int loop_ub;
  int stride_0_1;
  int stride_1_1;
  if (in2.size(1) == 1) {
    i = in1->a.size(1);
  } else {
    i = in2.size(1);
  }
  b_in1.set_size(1, i);
  stride_0_1 = (in1->a.size(1) != 1);
  stride_1_1 = (in2.size(1) != 1);
  if (in2.size(1) == 1) {
    loop_ub = in1->a.size(1);
  } else {
    loop_ub = in2.size(1);
  }
  for (i = 0; i < loop_ub; i++) {
    b_in1[i] = in1->a[i * stride_0_1] / in2[i * stride_1_1];
  }
  in1->a.set_size(1, b_in1.size(1));
  loop_ub = b_in1.size(1);
  for (i = 0; i < loop_ub; i++) {
    in1->a[i] = b_in1[i];
  }
}

//
// Arguments    : coder::quaternion *in1
//                const coder::quaternion *in2
//                const coder::array<double, 2U> &in3
// Return Type  : void
//
void g_binary_expand_op(coder::quaternion *in1, const coder::quaternion *in2,
                        const coder::array<double, 2U> &in3)
{
  int i;
  int loop_ub;
  int stride_0_1;
  int stride_1_1;
  if (in3.size(1) == 1) {
    i = in2->a.size(1);
  } else {
    i = in3.size(1);
  }
  in1->a.set_size(1, i);
  stride_0_1 = (in2->a.size(1) != 1);
  stride_1_1 = (in3.size(1) != 1);
  if (in3.size(1) == 1) {
    loop_ub = in2->a.size(1);
  } else {
    loop_ub = in3.size(1);
  }
  for (i = 0; i < loop_ub; i++) {
    in1->a[i] = in2->a[i * stride_0_1] / in3[i * stride_1_1];
  }
}

//
// Arguments    : coder::array<double, 1U> &in1
//                const coder::array<double, 1U> &in2
// Return Type  : void
//
void rdivide(coder::array<double, 1U> &in1, const coder::array<double, 1U> &in2)
{
  coder::array<double, 1U> b_in1;
  int i;
  int loop_ub;
  int stride_0_0;
  int stride_1_0;
  if (in2.size(0) == 1) {
    i = in1.size(0);
  } else {
    i = in2.size(0);
  }
  b_in1.set_size(i);
  stride_0_0 = (in1.size(0) != 1);
  stride_1_0 = (in2.size(0) != 1);
  if (in2.size(0) == 1) {
    loop_ub = in1.size(0);
  } else {
    loop_ub = in2.size(0);
  }
  for (i = 0; i < loop_ub; i++) {
    b_in1[i] = in1[i * stride_0_0] / in2[i * stride_1_0];
  }
  in1.set_size(b_in1.size(0));
  loop_ub = b_in1.size(0);
  for (i = 0; i < loop_ub; i++) {
    in1[i] = b_in1[i];
  }
}

//
// Arguments    : coder::array<creal_T, 1U> &in1
//                const coder::array<creal_T, 1U> &in2
// Return Type  : void
//
void rdivide(coder::array<creal_T, 1U> &in1,
             const coder::array<creal_T, 1U> &in2)
{
  coder::array<creal_T, 1U> b_in1;
  int i;
  int loop_ub;
  int stride_0_0;
  int stride_1_0;
  if (in2.size(0) == 1) {
    i = in1.size(0);
  } else {
    i = in2.size(0);
  }
  b_in1.set_size(i);
  stride_0_0 = (in1.size(0) != 1);
  stride_1_0 = (in2.size(0) != 1);
  if (in2.size(0) == 1) {
    loop_ub = in1.size(0);
  } else {
    loop_ub = in2.size(0);
  }
  for (i = 0; i < loop_ub; i++) {
    double ai;
    double ar;
    double bi;
    double br;
    int br_tmp;
    ar = in1[i * stride_0_0].re;
    ai = in1[i * stride_0_0].im;
    br_tmp = i * stride_1_0;
    br = in2[br_tmp].re;
    bi = in2[br_tmp].im;
    if (bi == 0.0) {
      if (ai == 0.0) {
        b_in1[i].re = ar / br;
        b_in1[i].im = 0.0;
      } else if (ar == 0.0) {
        b_in1[i].re = 0.0;
        b_in1[i].im = ai / br;
      } else {
        b_in1[i].re = ar / br;
        b_in1[i].im = ai / br;
      }
    } else if (br == 0.0) {
      if (ar == 0.0) {
        b_in1[i].re = ai / bi;
        b_in1[i].im = 0.0;
      } else if (ai == 0.0) {
        b_in1[i].re = 0.0;
        b_in1[i].im = -(ar / bi);
      } else {
        b_in1[i].re = ai / bi;
        b_in1[i].im = -(ar / bi);
      }
    } else {
      double bim;
      double brm;
      brm = std::abs(br);
      bim = std::abs(bi);
      if (brm > bim) {
        double s;
        s = bi / br;
        bim = br + s * bi;
        b_in1[i].re = (ar + s * ai) / bim;
        b_in1[i].im = (ai - s * ar) / bim;
      } else if (bim == brm) {
        double s;
        if (br > 0.0) {
          s = 0.5;
        } else {
          s = -0.5;
        }
        if (bi > 0.0) {
          bim = 0.5;
        } else {
          bim = -0.5;
        }
        b_in1[i].re = (ar * s + ai * bim) / brm;
        b_in1[i].im = (ai * s - ar * bim) / brm;
      } else {
        double s;
        s = br / bi;
        bim = bi + s * br;
        b_in1[i].re = (s * ar + ai) / bim;
        b_in1[i].im = (s * ai - ar) / bim;
      }
    }
  }
  in1.set_size(b_in1.size(0));
  loop_ub = b_in1.size(0);
  for (i = 0; i < loop_ub; i++) {
    in1[i] = b_in1[i];
  }
}

//
// File trailer for div.cpp
//
// [EOF]
//
