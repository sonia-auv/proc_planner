//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: quaternionBase.cpp
//
// MATLAB Coder version            : 5.4
// C/C++ source code generated on  : 12-Apr-2022 11:44:16
//

// Include Files
#include "quaternionBase.h"
#include "quaternion.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <string.h>

// Function Definitions
//
// Arguments    : coder::quaternion *in1
//                const coder::quaternion *in2
//                const coder::b_quaternion in3
// Return Type  : void
//
void binary_expand_op(coder::quaternion *in1, const coder::quaternion *in2,
                      const coder::b_quaternion in3)
{
  int i;
  int loop_ub;
  int stride_0_1;
  int stride_1_1;
  int stride_2_1;
  int stride_3_1;
  if (in2->d.size(1) == 1) {
    if (in2->c.size(1) == 1) {
      if (in2->b.size(1) == 1) {
        i = in2->a.size(1);
      } else {
        i = in2->b.size(1);
      }
    } else {
      i = in2->c.size(1);
    }
  } else {
    i = in2->d.size(1);
  }
  in1->d.set_size(1, i);
  stride_0_1 = (in2->a.size(1) != 1);
  stride_1_1 = (in2->b.size(1) != 1);
  stride_2_1 = (in2->c.size(1) != 1);
  stride_3_1 = (in2->d.size(1) != 1);
  if (in2->d.size(1) == 1) {
    if (in2->c.size(1) == 1) {
      if (in2->b.size(1) == 1) {
        loop_ub = in2->a.size(1);
      } else {
        loop_ub = in2->b.size(1);
      }
    } else {
      loop_ub = in2->c.size(1);
    }
  } else {
    loop_ub = in2->d.size(1);
  }
  for (i = 0; i < loop_ub; i++) {
    in1->d[i] =
        ((in2->a[i * stride_0_1] * in3.d + in2->b[i * stride_1_1] * in3.c) -
         in2->c[i * stride_2_1] * in3.b) +
        in2->d[i * stride_3_1] * in3.a;
  }
}

//
// Arguments    : coder::quaternion *in1
//                const coder::quaternion *in2
//                const coder::b_quaternion in3
// Return Type  : void
//
void e_binary_expand_op(coder::quaternion *in1, const coder::quaternion *in2,
                        const coder::b_quaternion in3)
{
  int i;
  int loop_ub;
  int stride_0_1;
  int stride_1_1;
  int stride_2_1;
  int stride_3_1;
  if (in2->d.size(1) == 1) {
    if (in2->c.size(1) == 1) {
      if (in2->b.size(1) == 1) {
        i = in2->a.size(1);
      } else {
        i = in2->b.size(1);
      }
    } else {
      i = in2->c.size(1);
    }
  } else {
    i = in2->d.size(1);
  }
  in1->c.set_size(1, i);
  stride_0_1 = (in2->a.size(1) != 1);
  stride_1_1 = (in2->b.size(1) != 1);
  stride_2_1 = (in2->c.size(1) != 1);
  stride_3_1 = (in2->d.size(1) != 1);
  if (in2->d.size(1) == 1) {
    if (in2->c.size(1) == 1) {
      if (in2->b.size(1) == 1) {
        loop_ub = in2->a.size(1);
      } else {
        loop_ub = in2->b.size(1);
      }
    } else {
      loop_ub = in2->c.size(1);
    }
  } else {
    loop_ub = in2->d.size(1);
  }
  for (i = 0; i < loop_ub; i++) {
    in1->c[i] =
        ((in2->a[i * stride_0_1] * in3.c - in2->b[i * stride_1_1] * in3.d) +
         in2->c[i * stride_2_1] * in3.a) +
        in2->d[i * stride_3_1] * in3.b;
  }
}

//
// Arguments    : coder::quaternion *in1
//                const coder::quaternion *in2
//                const coder::b_quaternion in3
// Return Type  : void
//
void f_binary_expand_op(coder::quaternion *in1, const coder::quaternion *in2,
                        const coder::b_quaternion in3)
{
  int i;
  int loop_ub;
  int stride_0_1;
  int stride_1_1;
  int stride_2_1;
  int stride_3_1;
  if (in2->d.size(1) == 1) {
    if (in2->c.size(1) == 1) {
      if (in2->b.size(1) == 1) {
        i = in2->a.size(1);
      } else {
        i = in2->b.size(1);
      }
    } else {
      i = in2->c.size(1);
    }
  } else {
    i = in2->d.size(1);
  }
  in1->b.set_size(1, i);
  stride_0_1 = (in2->a.size(1) != 1);
  stride_1_1 = (in2->b.size(1) != 1);
  stride_2_1 = (in2->c.size(1) != 1);
  stride_3_1 = (in2->d.size(1) != 1);
  if (in2->d.size(1) == 1) {
    if (in2->c.size(1) == 1) {
      if (in2->b.size(1) == 1) {
        loop_ub = in2->a.size(1);
      } else {
        loop_ub = in2->b.size(1);
      }
    } else {
      loop_ub = in2->c.size(1);
    }
  } else {
    loop_ub = in2->d.size(1);
  }
  for (i = 0; i < loop_ub; i++) {
    in1->b[i] =
        ((in2->a[i * stride_0_1] * in3.b + in2->b[i * stride_1_1] * in3.a) +
         in2->c[i * stride_2_1] * in3.d) -
        in2->d[i * stride_3_1] * in3.c;
  }
}

//
// Arguments    : coder::quaternion *in1
//                const coder::quaternion *in2
//                const coder::b_quaternion in3
// Return Type  : void
//
void g_binary_expand_op(coder::quaternion *in1, const coder::quaternion *in2,
                        const coder::b_quaternion in3)
{
  int i;
  int loop_ub;
  int stride_0_1;
  int stride_1_1;
  int stride_2_1;
  int stride_3_1;
  if (in2->d.size(1) == 1) {
    if (in2->c.size(1) == 1) {
      if (in2->b.size(1) == 1) {
        i = in2->a.size(1);
      } else {
        i = in2->b.size(1);
      }
    } else {
      i = in2->c.size(1);
    }
  } else {
    i = in2->d.size(1);
  }
  in1->a.set_size(1, i);
  stride_0_1 = (in2->a.size(1) != 1);
  stride_1_1 = (in2->b.size(1) != 1);
  stride_2_1 = (in2->c.size(1) != 1);
  stride_3_1 = (in2->d.size(1) != 1);
  if (in2->d.size(1) == 1) {
    if (in2->c.size(1) == 1) {
      if (in2->b.size(1) == 1) {
        loop_ub = in2->a.size(1);
      } else {
        loop_ub = in2->b.size(1);
      }
    } else {
      loop_ub = in2->c.size(1);
    }
  } else {
    loop_ub = in2->d.size(1);
  }
  for (i = 0; i < loop_ub; i++) {
    in1->a[i] =
        ((in2->a[i * stride_0_1] * in3.a - in2->b[i * stride_1_1] * in3.b) -
         in2->c[i * stride_2_1] * in3.c) -
        in2->d[i * stride_3_1] * in3.d;
  }
}

//
// File trailer for quaternionBase.cpp
//
// [EOF]
//
