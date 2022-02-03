//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: fresnel.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 02-Feb-2022 17:45:08
//

// Include Files
#include "fresnel.h"
#include "find.h"
#include "proc_planner_data.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <cmath>
#include <string.h>

// Function Definitions
//
// Arguments    : const ::coder::array<double, 2U> &x
//                ::coder::array<creal_T, 2U> &z
// Return Type  : void
//
namespace coder {
namespace matlabshared {
namespace tracking {
namespace internal {
namespace scenario {
void fresnel(const ::coder::array<double, 2U> &x,
             ::coder::array<creal_T, 2U> &z)
{
  array<creal_T, 1U> b_x;
  array<double, 2U> x_tmp;
  array<double, 2U> xabs;
  array<double, 1U> u;
  array<double, 1U> x4;
  array<int, 1U> b_r;
  array<int, 1U> ii;
  array<int, 1U> r1;
  array<bool, 2U> b_x_tmp;
  double r;
  int i;
  int k;
  int nx;
  z.set_size(x.size(0), x.size(1));
  nx = x.size(0) * x.size(1);
  for (k = 0; k < nx; k++) {
    z[k].re = rtNaN;
    z[k].im = 0.0;
  }
  nx = x.size(0) * x.size(1);
  xabs.set_size(x.size(0), x.size(1));
  for (k = 0; k < nx; k++) {
    xabs[k] = std::abs(x[k]);
  }
  x_tmp.set_size(xabs.size(0), xabs.size(1));
  nx = xabs.size(0) * xabs.size(1);
  for (k = 0; k < nx; k++) {
    x_tmp[k] = xabs[k] * xabs[k];
  }
  b_x_tmp.set_size(x_tmp.size(0), x_tmp.size(1));
  nx = x_tmp.size(0) * x_tmp.size(1);
  for (k = 0; k < nx; k++) {
    b_x_tmp[k] = (x_tmp[k] < 2.5625);
  }
  b_eml_find(b_x_tmp, ii);
  x4.set_size(ii.size(0));
  nx = ii.size(0);
  for (k = 0; k < nx; k++) {
    x4[k] = x_tmp[ii[k] - 1];
  }
  nx = x4.size(0);
  for (k = 0; k < nx; k++) {
    x4[k] = x4[k] * x4[k];
  }
  nx = ii.size(0);
  for (k = 0; k < nx; k++) {
    z[ii[k] - 1].re =
        xabs[ii[k] - 1] *
        ((((((-4.9884311457357354E-8 * x4[k] + 9.5042806282985963E-6) * x4[k] +
             -0.00064519143568396507) *
                x4[k] +
            0.018884331939670384) *
               x4[k] +
           -0.20552590095501388) *
              x4[k] +
          1.0) /
         ((((((3.99982968972496E-12 * x4[k] + 9.1543921577465745E-10) * x4[k] +
              1.2500186247959882E-7) *
                 x4[k] +
             1.2226278902417902E-5) *
                x4[k] +
            0.00086802954294178428) *
               x4[k] +
           0.041214209072219982) *
              x4[k] +
          1.0));
    z[ii[k] - 1].im =
        xabs[ii[k] - 1] *
        (x_tmp[ii[k] - 1] *
         (((((-2991.8191940101983 * x4[k] + 708840.04525773856) * x4[k] +
             -6.2974148620586254E+7) *
                x4[k] +
            2.5489088057337637E+9) *
               x4[k] +
           -4.429795180596978E+10) *
              x4[k] +
          3.1801629787656781E+11) /
         ((((((x4[k] + 281.37626888999432) * x4[k] + 45584.781080653258) *
                 x4[k] +
             5.1734388877009638E+6) *
                x4[k] +
            4.1932024589811122E+8) *
               x4[k] +
           2.2441179564534092E+10) *
              x4[k] +
          6.0736638949008459E+11));
  }
  b_x_tmp.set_size(x_tmp.size(0), x_tmp.size(1));
  nx = x_tmp.size(0) * x_tmp.size(1);
  for (k = 0; k < nx; k++) {
    b_x_tmp[k] = ((2.5625 <= x_tmp[k]) && (x_tmp[k] <= 1.367076676E+9));
  }
  b_eml_find(b_x_tmp, ii);
  x4.set_size(ii.size(0));
  nx = ii.size(0);
  for (k = 0; k < nx; k++) {
    x4[k] = 1.0 / (3.1415926535897931 * x_tmp[ii[k] - 1]);
  }
  u.set_size(x4.size(0));
  nx = x4.size(0);
  for (k = 0; k < nx; k++) {
    u[k] = x4[k] * x4[k];
  }
  b_x.set_size(ii.size(0));
  nx = ii.size(0);
  for (k = 0; k < nx; k++) {
    b_x[k].re = x_tmp[ii[k] - 1] * 0.0;
    b_x[k].im = x_tmp[ii[k] - 1] * 1.5707963267948966;
  }
  nx = b_x.size(0);
  for (k = 0; k < nx; k++) {
    if (b_x[k].im == 0.0) {
      b_x[k].re = std::exp(b_x[k].re);
      b_x[k].im = 0.0;
    } else if (std::isinf(b_x[k].im) && std::isinf(b_x[k].re) &&
               (b_x[k].re < 0.0)) {
      b_x[k].re = 0.0;
      b_x[k].im = 0.0;
    } else {
      r = std::exp(b_x[k].re / 2.0);
      b_x[k].re = r * (r * std::cos(b_x[k].im));
      b_x[k].im = r * (r * std::sin(b_x[k].im));
    }
  }
  nx = u.size(0);
  for (k = 0; k < nx; k++) {
    double b_re;
    double im;
    double re;
    double u_im;
    r = u[k] *
            (((((((((0.42154355504367752 * u[k] + 0.1434079197807589) * u[k] +
                    0.011522095507358577) *
                       u[k] +
                   0.000345017939782574) *
                      u[k] +
                  4.6361374928786735E-6) *
                     u[k] +
                 3.0556898379025758E-8) *
                    u[k] +
                1.0230451416490724E-10) *
                   u[k] +
               1.7201074326816183E-13) *
                  u[k] +
              1.3428327623306275E-16) *
                 u[k] +
             3.763297112699879E-20) /
            ((((((((((u[k] + 0.75158639835337893) * u[k] +
                     0.11688892585919138) *
                        u[k] +
                    0.0064405152650885865) *
                       u[k] +
                   0.00015593440916415301) *
                      u[k] +
                  1.8462756734893055E-6) *
                     u[k] +
                 1.1269922476399903E-8) *
                    u[k] +
                3.6014002958937136E-11) *
                   u[k] +
               5.8875453362157839E-14) *
                  u[k] +
              4.5200143407412973E-17) *
                 u[k] +
             1.2544323709001127E-20) -
        1.0;
    u_im = x4[k] *
           ((((((((((0.50444207364338323 * u[k] + 0.19710283352552341) * u[k] +
                    0.018764858409257526) *
                       u[k] +
                   0.00068407938091539307) *
                      u[k] +
                  1.1513882611188428E-5) *
                     u[k] +
                 9.8285244368842225E-8) *
                    u[k] +
                4.4534441586175015E-10) *
                   u[k] +
               1.0826804113902088E-12) *
                  u[k] +
              1.375554606332618E-15) *
                 u[k] +
             8.3635443563067741E-19) *
                u[k] +
            1.8695871016278324E-22) /
           (((((((((((u[k] + 1.4749575992512833) * u[k] + 0.33774898912002) *
                        u[k] +
                    0.025360374142033879) *
                       u[k] +
                   0.00081467910718430615) *
                      u[k] +
                  1.2754507566772912E-5) *
                     u[k] +
                 1.0431458965757199E-7) *
                    u[k] +
                4.6068072814652043E-10) *
                   u[k] +
               1.1027321506624028E-12) *
                  u[k] +
              1.3879653125957886E-15) *
                 u[k] +
             8.3915881628311874E-19) *
                u[k] +
            1.8695871016278324E-22);
    re = 0.0 * r - u_im;
    im = 0.0 * u_im + r;
    r = b_x[k].im;
    u_im = b_x[k].re;
    b_re = re * u_im - im * r;
    im = re * r + im * u_im;
    r = 3.1415926535897931 * xabs[ii[k] - 1];
    if (im == 0.0) {
      re = b_re / r;
      im = 0.0;
    } else if (b_re == 0.0) {
      re = 0.0;
      im /= r;
    } else {
      re = b_re / r;
      im /= r;
    }
    z[ii[k] - 1].re = re + 0.5;
    z[ii[k] - 1].im = im + 0.5;
  }
  k = xabs.size(0) * xabs.size(1) - 1;
  nx = 0;
  for (i = 0; i <= k; i++) {
    if (xabs[i] * xabs[i] > 1.367076676E+9) {
      nx++;
    }
  }
  b_r.set_size(nx);
  nx = 0;
  for (i = 0; i <= k; i++) {
    if (xabs[i] * xabs[i] > 1.367076676E+9) {
      b_r[nx] = i + 1;
      nx++;
    }
  }
  nx = b_r.size(0) - 1;
  for (k = 0; k <= nx; k++) {
    z[b_r[k] - 1].re = 0.5;
    z[b_r[k] - 1].im = 0.5;
  }
  k = x.size(0) * x.size(1) - 1;
  nx = 0;
  for (i = 0; i <= k; i++) {
    if (x[i] < 0.0) {
      nx++;
    }
  }
  r1.set_size(nx);
  nx = 0;
  for (i = 0; i <= k; i++) {
    if (x[i] < 0.0) {
      r1[nx] = i + 1;
      nx++;
    }
  }
  b_x.set_size(r1.size(0));
  nx = r1.size(0);
  for (k = 0; k < nx; k++) {
    b_x[k].re = -z[r1[k] - 1].re;
    b_x[k].im = -z[r1[k] - 1].im;
  }
  nx = b_x.size(0);
  for (k = 0; k < nx; k++) {
    z[r1[k] - 1] = b_x[k];
  }
}

//
// Arguments    : const ::coder::array<double, 1U> &x
//                ::coder::array<creal_T, 1U> &z
// Return Type  : void
//
void fresnelr(const ::coder::array<double, 1U> &x,
              ::coder::array<creal_T, 1U> &z)
{
  array<creal_T, 1U> b_x;
  array<double, 1U> ibig;
  array<double, 1U> ismall;
  array<double, 1U> x4;
  array<double, 1U> xabs;
  array<int, 1U> b_r;
  array<int, 1U> ii;
  array<int, 1U> r1;
  array<bool, 1U> b_ibig;
  double r;
  int i;
  int loop_ub;
  int nx;
  z.set_size(x.size(0));
  loop_ub = x.size(0);
  for (i = 0; i < loop_ub; i++) {
    z[i].re = rtNaN;
    z[i].im = 0.0;
  }
  nx = x.size(0);
  xabs.set_size(x.size(0));
  for (loop_ub = 0; loop_ub < nx; loop_ub++) {
    xabs[loop_ub] = std::abs(x[loop_ub]);
  }
  ibig.set_size(xabs.size(0));
  loop_ub = xabs.size(0);
  for (i = 0; i < loop_ub; i++) {
    ibig[i] = xabs[i] * xabs[i];
  }
  b_ibig.set_size(ibig.size(0));
  loop_ub = ibig.size(0);
  for (i = 0; i < loop_ub; i++) {
    b_ibig[i] = (ibig[i] < 2.5625);
  }
  eml_find(b_ibig, ii);
  ismall.set_size(ii.size(0));
  loop_ub = ii.size(0);
  for (i = 0; i < loop_ub; i++) {
    ismall[i] = ii[i];
  }
  x4.set_size(ismall.size(0));
  loop_ub = ismall.size(0);
  for (i = 0; i < loop_ub; i++) {
    r = xabs[static_cast<int>(ismall[i]) - 1];
    x4[i] = r * r;
  }
  loop_ub = x4.size(0);
  for (i = 0; i < loop_ub; i++) {
    x4[i] = x4[i] * x4[i];
  }
  loop_ub = ismall.size(0);
  for (i = 0; i < loop_ub; i++) {
    nx = static_cast<int>(ismall[i]) - 1;
    r = xabs[nx];
    z[nx].re =
        r *
        ((((((-4.9884311457357354E-8 * x4[i] + 9.5042806282985963E-6) * x4[i] +
             -0.00064519143568396507) *
                x4[i] +
            0.018884331939670384) *
               x4[i] +
           -0.20552590095501388) *
              x4[i] +
          1.0) /
         ((((((3.99982968972496E-12 * x4[i] + 9.1543921577465745E-10) * x4[i] +
              1.2500186247959882E-7) *
                 x4[i] +
             1.2226278902417902E-5) *
                x4[i] +
            0.00086802954294178428) *
               x4[i] +
           0.041214209072219982) *
              x4[i] +
          1.0));
    z[nx].im =
        r * (r * r *
             (((((-2991.8191940101983 * x4[i] + 708840.04525773856) * x4[i] +
                 -6.2974148620586254E+7) *
                    x4[i] +
                2.5489088057337637E+9) *
                   x4[i] +
               -4.429795180596978E+10) *
                  x4[i] +
              3.1801629787656781E+11) /
             ((((((x4[i] + 281.37626888999432) * x4[i] + 45584.781080653258) *
                     x4[i] +
                 5.1734388877009638E+6) *
                    x4[i] +
                4.1932024589811122E+8) *
                   x4[i] +
               2.2441179564534092E+10) *
                  x4[i] +
              6.0736638949008459E+11));
  }
  b_ibig.set_size(ibig.size(0));
  loop_ub = ibig.size(0);
  for (i = 0; i < loop_ub; i++) {
    b_ibig[i] = ((2.5625 <= ibig[i]) && (ibig[i] <= 1.367076676E+9));
  }
  eml_find(b_ibig, ii);
  ibig.set_size(ii.size(0));
  loop_ub = ii.size(0);
  for (i = 0; i < loop_ub; i++) {
    ibig[i] = ii[i];
  }
  ismall.set_size(ibig.size(0));
  loop_ub = ibig.size(0);
  for (i = 0; i < loop_ub; i++) {
    r = xabs[static_cast<int>(ibig[i]) - 1];
    ismall[i] = 1.0 / (3.1415926535897931 * (r * r));
  }
  x4.set_size(ismall.size(0));
  loop_ub = ismall.size(0);
  for (i = 0; i < loop_ub; i++) {
    x4[i] = ismall[i] * ismall[i];
  }
  b_x.set_size(ibig.size(0));
  loop_ub = ibig.size(0);
  for (i = 0; i < loop_ub; i++) {
    r = xabs[static_cast<int>(ibig[i]) - 1];
    r *= r;
    b_x[i].re = r * 0.0;
    b_x[i].im = r * 1.5707963267948966;
  }
  nx = b_x.size(0);
  for (loop_ub = 0; loop_ub < nx; loop_ub++) {
    if (b_x[loop_ub].im == 0.0) {
      b_x[loop_ub].re = std::exp(b_x[loop_ub].re);
      b_x[loop_ub].im = 0.0;
    } else if (std::isinf(b_x[loop_ub].im) && std::isinf(b_x[loop_ub].re) &&
               (b_x[loop_ub].re < 0.0)) {
      b_x[loop_ub].re = 0.0;
      b_x[loop_ub].im = 0.0;
    } else {
      r = std::exp(b_x[loop_ub].re / 2.0);
      b_x[loop_ub].re = r * (r * std::cos(b_x[loop_ub].im));
      b_x[loop_ub].im = r * (r * std::sin(b_x[loop_ub].im));
    }
  }
  loop_ub = x4.size(0);
  for (i = 0; i < loop_ub; i++) {
    double b_re;
    double im;
    double re;
    double x4_im;
    r = x4[i] *
            (((((((((0.42154355504367752 * x4[i] + 0.1434079197807589) * x4[i] +
                    0.011522095507358577) *
                       x4[i] +
                   0.000345017939782574) *
                      x4[i] +
                  4.6361374928786735E-6) *
                     x4[i] +
                 3.0556898379025758E-8) *
                    x4[i] +
                1.0230451416490724E-10) *
                   x4[i] +
               1.7201074326816183E-13) *
                  x4[i] +
              1.3428327623306275E-16) *
                 x4[i] +
             3.763297112699879E-20) /
            ((((((((((x4[i] + 0.75158639835337893) * x4[i] +
                     0.11688892585919138) *
                        x4[i] +
                    0.0064405152650885865) *
                       x4[i] +
                   0.00015593440916415301) *
                      x4[i] +
                  1.8462756734893055E-6) *
                     x4[i] +
                 1.1269922476399903E-8) *
                    x4[i] +
                3.6014002958937136E-11) *
                   x4[i] +
               5.8875453362157839E-14) *
                  x4[i] +
              4.5200143407412973E-17) *
                 x4[i] +
             1.2544323709001127E-20) -
        1.0;
    x4_im =
        ismall[i] *
        ((((((((((0.50444207364338323 * x4[i] + 0.19710283352552341) * x4[i] +
                 0.018764858409257526) *
                    x4[i] +
                0.00068407938091539307) *
                   x4[i] +
               1.1513882611188428E-5) *
                  x4[i] +
              9.8285244368842225E-8) *
                 x4[i] +
             4.4534441586175015E-10) *
                x4[i] +
            1.0826804113902088E-12) *
               x4[i] +
           1.375554606332618E-15) *
              x4[i] +
          8.3635443563067741E-19) *
             x4[i] +
         1.8695871016278324E-22) /
        (((((((((((x4[i] + 1.4749575992512833) * x4[i] + 0.33774898912002) *
                     x4[i] +
                 0.025360374142033879) *
                    x4[i] +
                0.00081467910718430615) *
                   x4[i] +
               1.2754507566772912E-5) *
                  x4[i] +
              1.0431458965757199E-7) *
                 x4[i] +
             4.6068072814652043E-10) *
                x4[i] +
            1.1027321506624028E-12) *
               x4[i] +
           1.3879653125957886E-15) *
              x4[i] +
          8.3915881628311874E-19) *
             x4[i] +
         1.8695871016278324E-22);
    re = 0.0 * r - x4_im;
    im = 0.0 * x4_im + r;
    r = b_x[i].im;
    x4_im = b_x[i].re;
    b_re = re * x4_im - im * r;
    im = re * r + im * x4_im;
    nx = static_cast<int>(ibig[i]) - 1;
    r = 3.1415926535897931 * xabs[nx];
    if (im == 0.0) {
      re = b_re / r;
      im = 0.0;
    } else if (b_re == 0.0) {
      re = 0.0;
      im /= r;
    } else {
      re = b_re / r;
      im /= r;
    }
    z[nx].re = re + 0.5;
    z[nx].im = im + 0.5;
  }
  loop_ub = xabs.size(0) - 1;
  nx = 0;
  for (i = 0; i <= loop_ub; i++) {
    if (xabs[i] * xabs[i] > 1.367076676E+9) {
      nx++;
    }
  }
  b_r.set_size(nx);
  nx = 0;
  for (i = 0; i <= loop_ub; i++) {
    if (xabs[i] * xabs[i] > 1.367076676E+9) {
      b_r[nx] = i + 1;
      nx++;
    }
  }
  loop_ub = b_r.size(0);
  for (i = 0; i < loop_ub; i++) {
    z[b_r[i] - 1].re = 0.5;
    z[b_r[i] - 1].im = 0.5;
  }
  loop_ub = x.size(0) - 1;
  nx = 0;
  for (i = 0; i <= loop_ub; i++) {
    if (x[i] < 0.0) {
      nx++;
    }
  }
  r1.set_size(nx);
  nx = 0;
  for (i = 0; i <= loop_ub; i++) {
    if (x[i] < 0.0) {
      r1[nx] = i + 1;
      nx++;
    }
  }
  b_x.set_size(r1.size(0));
  loop_ub = r1.size(0);
  for (i = 0; i < loop_ub; i++) {
    b_x[i].re = -z[r1[i] - 1].re;
    b_x[i].im = -z[r1[i] - 1].im;
  }
  loop_ub = b_x.size(0);
  for (i = 0; i < loop_ub; i++) {
    z[r1[i] - 1] = b_x[i];
  }
}

} // namespace scenario
} // namespace internal
} // namespace tracking
} // namespace matlabshared
} // namespace coder

//
// File trailer for fresnel.cpp
//
// [EOF]
//
