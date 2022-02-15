//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: power.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 09-Feb-2022 14:06:20
//

// Include Files
#include "power.h"
#include "proc_planner_rtwutil.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <cmath>
#include <string.h>

// Function Definitions
//
// Arguments    : const ::coder::array<creal_T, 1U> &a
//                ::coder::array<creal_T, 1U> &y
// Return Type  : void
//
namespace coder {
void power(const ::coder::array<creal_T, 1U> &a, ::coder::array<creal_T, 1U> &y)
{
  int nx;
  y.set_size(a.size(0));
  nx = a.size(0);
  for (int k{0}; k < nx; k++) {
    double r;
    double y_im;
    r = a[k].re;
    y_im = a[k].im;
    if ((y_im == 0.0) && (r >= 0.0)) {
      y[k].re = rt_powd_snf(r, 3.0);
      y[k].im = 0.0;
    } else if (r == 0.0) {
      y[k].re = 0.0;
      y[k].im = -rt_powd_snf(y_im, 3.0);
    } else {
      double y_re;
      if (a[k].im == 0.0) {
        if (a[k].re < 0.0) {
          y_re = std::log(std::abs(a[k].re));
          y_im = 3.1415926535897931;
        } else {
          y_re = std::log(std::abs(a[k].re));
          y_im = 0.0;
        }
      } else if ((std::abs(a[k].re) > 8.9884656743115785E+307) ||
                 (std::abs(a[k].im) > 8.9884656743115785E+307)) {
        y_re =
            std::log(rt_hypotd_snf(r / 2.0, y_im / 2.0)) + 0.69314718055994529;
        y_im = rt_atan2d_snf(a[k].im, a[k].re);
      } else {
        y_re = std::log(rt_hypotd_snf(r, y_im));
        y_im = rt_atan2d_snf(y_im, r);
      }
      y_re *= 3.0;
      y_im *= 3.0;
      if (y_im == 0.0) {
        y[k].re = std::exp(y_re);
        y[k].im = 0.0;
      } else if (std::isinf(y_im) && std::isinf(y_re) && (y_re < 0.0)) {
        y[k].re = 0.0;
        y[k].im = 0.0;
      } else {
        r = std::exp(y_re / 2.0);
        y[k].re = r * (r * std::cos(y_im));
        y[k].im = r * (r * std::sin(y_im));
      }
    }
  }
}

} // namespace coder

//
// File trailer for power.cpp
//
// [EOF]
//
