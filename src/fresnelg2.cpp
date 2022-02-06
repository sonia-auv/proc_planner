//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: fresnelg2.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 05-Feb-2022 14:39:35
//

// Include Files
#include "fresnelg2.h"
#include "fresnel.h"
#include "proc_planner_data.h"
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
static void fresnelgzero(const ::coder::array<double, 2U> &x,
                         const ::coder::array<double, 2U> &dk,
                         const ::coder::array<double, 2U> &k,
                         const ::coder::array<double, 2U> &theta,
                         ::coder::array<creal_T, 1U> &z);

}
} // namespace internal
} // namespace tracking
} // namespace matlabshared
} // namespace coder

// Function Definitions
//
// Arguments    : const ::coder::array<double, 2U> &x
//                const ::coder::array<double, 2U> &dk
//                const ::coder::array<double, 2U> &k
//                const ::coder::array<double, 2U> &theta
//                ::coder::array<creal_T, 1U> &z
// Return Type  : void
//
namespace coder {
namespace matlabshared {
namespace tracking {
namespace internal {
namespace scenario {
static void fresnelgzero(const ::coder::array<double, 2U> &x,
                         const ::coder::array<double, 2U> &dk,
                         const ::coder::array<double, 2U> &k,
                         const ::coder::array<double, 2U> &theta,
                         ::coder::array<creal_T, 1U> &z)
{
  array<creal_T, 2U> A;
  array<creal_T, 2U> B;
  array<creal_T, 2U> b_A;
  array<creal_T, 2U> r1;
  array<double, 2U> r;
  double A_re;
  double ai;
  double b_r;
  double b_re_tmp;
  double re_tmp;
  int b_k;
  int iacol_tmp;
  int ibcol;
  int ibtile;
  int jcol;
  int jtilecol;
  int ncols;
  int nx;
  r.set_size(x.size(0), x.size(1));
  nx = x.size(0) * x.size(1);
  for (b_k = 0; b_k < nx; b_k++) {
    r[b_k] = x[b_k] * x[b_k];
  }
  r1.set_size(dk.size(0), dk.size(1));
  nx = dk.size(0) * dk.size(1);
  for (jcol = 0; jcol < nx; jcol++) {
    r1[jcol].re = r[jcol] * (dk[jcol] * 0.0);
    r1[jcol].im = r[jcol] * (dk[jcol] * 0.5);
  }
  A.set_size(r1.size(0), r1.size(1) * 5);
  nx = r1.size(0);
  ncols = r1.size(1);
  for (jtilecol = 0; jtilecol < 5; jtilecol++) {
    ibtile = jtilecol * (nx * ncols) - 1;
    for (jcol = 0; jcol < ncols; jcol++) {
      iacol_tmp = jcol * nx;
      ibcol = ibtile + iacol_tmp;
      for (b_k = 0; b_k < nx; b_k++) {
        A[(ibcol + b_k) + 1] = r1[iacol_tmp + b_k];
      }
    }
  }
  b_A.set_size(A.size(0), 5);
  if (A.size(0) != 0) {
    nx = (A.size(1) != 1);
    ncols = (A.size(0) != 1);
    for (b_k = 0; b_k < 5; b_k++) {
      ibtile = nx * b_k;
      jcol = b_A.size(0) - 1;
      for (ibcol = 0; ibcol <= jcol; ibcol++) {
        iacol_tmp = ncols * ibcol;
        b_r = A[iacol_tmp + A.size(0) * ibtile].re;
        ai = A[iacol_tmp + A.size(0) * ibtile].im;
        if (ai == 0.0) {
          b_A[ibcol + b_A.size(0) * b_k].re =
              b_r / (static_cast<double>(b_k) + 1.0);
          b_A[ibcol + b_A.size(0) * b_k].im = 0.0;
        } else if (b_r == 0.0) {
          b_A[ibcol + b_A.size(0) * b_k].re = 0.0;
          b_A[ibcol + b_A.size(0) * b_k].im =
              ai / (static_cast<double>(b_k) + 1.0);
        } else {
          b_A[ibcol + b_A.size(0) * b_k].re =
              b_r / (static_cast<double>(b_k) + 1.0);
          b_A[ibcol + b_A.size(0) * b_k].im =
              ai / (static_cast<double>(b_k) + 1.0);
        }
      }
    }
  }
  if (b_A.size(0) != 0) {
    for (b_k = 0; b_k < 4; b_k++) {
      jcol = b_A.size(0);
      for (ibcol = 0; ibcol < jcol; ibcol++) {
        b_r = b_A[ibcol + b_A.size(0) * b_k].re;
        re_tmp = b_A[ibcol + b_A.size(0) * (b_k + 1)].im;
        ai = b_A[ibcol + b_A.size(0) * b_k].im;
        b_re_tmp = b_A[ibcol + b_A.size(0) * (b_k + 1)].re;
        b_A[ibcol + b_A.size(0) * (b_k + 1)].re = b_r * b_re_tmp - ai * re_tmp;
        b_A[ibcol + b_A.size(0) * (b_k + 1)].im = b_r * re_tmp + ai * b_re_tmp;
      }
    }
  }
  r1.set_size(k.size(0), k.size(1));
  nx = k.size(0) * k.size(1);
  for (jcol = 0; jcol < nx; jcol++) {
    r1[jcol].re = x[jcol] * (k[jcol] * 0.0);
    r1[jcol].im = x[jcol] * k[jcol];
  }
  A.set_size(r1.size(0), r1.size(1) * 5);
  nx = r1.size(0);
  ncols = r1.size(1);
  for (jtilecol = 0; jtilecol < 5; jtilecol++) {
    ibtile = jtilecol * (nx * ncols) - 1;
    for (jcol = 0; jcol < ncols; jcol++) {
      iacol_tmp = jcol * nx;
      ibcol = ibtile + iacol_tmp;
      for (b_k = 0; b_k < nx; b_k++) {
        A[(ibcol + b_k) + 1] = r1[iacol_tmp + b_k];
      }
    }
  }
  B.set_size(A.size(0), 5);
  if (A.size(0) != 0) {
    nx = (A.size(1) != 1);
    ncols = (A.size(0) != 1);
    for (b_k = 0; b_k < 5; b_k++) {
      ibtile = nx * b_k;
      jcol = B.size(0) - 1;
      for (ibcol = 0; ibcol <= jcol; ibcol++) {
        iacol_tmp = ncols * ibcol;
        b_r = A[iacol_tmp + A.size(0) * ibtile].re;
        ai = A[iacol_tmp + A.size(0) * ibtile].im;
        if (ai == 0.0) {
          B[ibcol + B.size(0) * b_k].re =
              b_r / (static_cast<double>(b_k) + 1.0);
          B[ibcol + B.size(0) * b_k].im = 0.0;
        } else if (b_r == 0.0) {
          B[ibcol + B.size(0) * b_k].re = 0.0;
          B[ibcol + B.size(0) * b_k].im = ai / (static_cast<double>(b_k) + 1.0);
        } else {
          B[ibcol + B.size(0) * b_k].re =
              b_r / (static_cast<double>(b_k) + 1.0);
          B[ibcol + B.size(0) * b_k].im = ai / (static_cast<double>(b_k) + 1.0);
        }
      }
    }
  }
  if (B.size(0) != 0) {
    for (b_k = 0; b_k < 4; b_k++) {
      jcol = B.size(0);
      for (ibcol = 0; ibcol < jcol; ibcol++) {
        b_r = B[ibcol + B.size(0) * b_k].re;
        re_tmp = B[ibcol + B.size(0) * (b_k + 1)].im;
        ai = B[ibcol + B.size(0) * b_k].im;
        b_re_tmp = B[ibcol + B.size(0) * (b_k + 1)].re;
        B[ibcol + B.size(0) * (b_k + 1)].re = b_r * b_re_tmp - ai * re_tmp;
        B[ibcol + B.size(0) * (b_k + 1)].im = b_r * re_tmp + ai * b_re_tmp;
      }
    }
  }
  if ((x.size(0) == 0) || (x.size(1) == 0)) {
    ncols = 0;
  } else {
    nx = x.size(0);
    ncols = x.size(1);
    if (nx >= ncols) {
      ncols = nx;
    }
  }
  z.set_size(ncols);
  for (jcol = 0; jcol < ncols; jcol++) {
    z[jcol].re = 1.0;
    z[jcol].im = 0.0;
  }
  for (iacol_tmp = 0; iacol_tmp < 5; iacol_tmp++) {
    ncols = ((iacol_tmp + 1) << 1) + 1;
    nx = z.size(0);
    for (jcol = 0; jcol < nx; jcol++) {
      b_r = b_A[jcol + b_A.size(0) * iacol_tmp].re;
      ai = b_A[jcol + b_A.size(0) * iacol_tmp].im;
      if (ai == 0.0) {
        A_re = b_r / static_cast<double>(ncols);
        b_r = 0.0;
      } else if (b_r == 0.0) {
        A_re = 0.0;
        b_r = ai / static_cast<double>(ncols);
      } else {
        A_re = b_r / static_cast<double>(ncols);
        b_r = ai / static_cast<double>(ncols);
      }
      z[jcol].re = z[jcol].re + A_re;
      z[jcol].im = z[jcol].im + b_r;
    }
  }
  for (ibcol = 0; ibcol < 5; ibcol++) {
    nx = z.size(0);
    for (jcol = 0; jcol < nx; jcol++) {
      b_r = B[jcol + B.size(0) * ibcol].re;
      ai = B[jcol + B.size(0) * ibcol].im;
      if (ai == 0.0) {
        re_tmp = b_r / ((static_cast<double>(ibcol) + 1.0) + 1.0);
        b_r = 0.0;
      } else if (b_r == 0.0) {
        re_tmp = 0.0;
        b_r = ai / ((static_cast<double>(ibcol) + 1.0) + 1.0);
      } else {
        re_tmp = b_r / ((static_cast<double>(ibcol) + 1.0) + 1.0);
        b_r = ai / ((static_cast<double>(ibcol) + 1.0) + 1.0);
      }
      z[jcol].re = z[jcol].re + re_tmp;
      z[jcol].im = z[jcol].im + b_r;
    }
  }
  for (iacol_tmp = 0; iacol_tmp < 4; iacol_tmp++) {
    jcol = (iacol_tmp + 1) << 1;
    ibtile = 4 - jcol;
    for (ibcol = 0; ibcol <= ibtile; ibcol++) {
      ncols = (jcol + ibcol) + 2;
      nx = z.size(0);
      for (jtilecol = 0; jtilecol < nx; jtilecol++) {
        b_r = b_A[jtilecol + b_A.size(0) * iacol_tmp].re;
        ai = B[jtilecol + B.size(0) * ibcol].im;
        re_tmp = b_A[jtilecol + b_A.size(0) * iacol_tmp].im;
        b_re_tmp = B[jtilecol + B.size(0) * ibcol].re;
        A_re = b_r * b_re_tmp - re_tmp * ai;
        b_r = b_r * ai + re_tmp * b_re_tmp;
        if (b_r == 0.0) {
          A_re /= static_cast<double>(ncols);
          b_r = 0.0;
        } else if (A_re == 0.0) {
          A_re = 0.0;
          b_r /= static_cast<double>(ncols);
        } else {
          A_re /= static_cast<double>(ncols);
          b_r /= static_cast<double>(ncols);
        }
        z[jtilecol].re = z[jtilecol].re + A_re;
        z[jtilecol].im = z[jtilecol].im + b_r;
      }
    }
  }
  A.set_size(theta.size(0), theta.size(1));
  nx = theta.size(0) * theta.size(1);
  for (jcol = 0; jcol < nx; jcol++) {
    A[jcol].re = theta[jcol] * 0.0;
    A[jcol].im = theta[jcol];
  }
  nx = A.size(0) * A.size(1);
  for (b_k = 0; b_k < nx; b_k++) {
    if (A[b_k].im == 0.0) {
      A[b_k].re = std::exp(A[b_k].re);
      A[b_k].im = 0.0;
    } else if (std::isinf(A[b_k].im) && std::isinf(A[b_k].re) &&
               (A[b_k].re < 0.0)) {
      A[b_k].re = 0.0;
      A[b_k].im = 0.0;
    } else {
      b_r = std::exp(A[b_k].re / 2.0);
      re_tmp = A[b_k].im;
      A[b_k].re = b_r * (b_r * std::cos(A[b_k].im));
      A[b_k].im = b_r * (b_r * std::sin(re_tmp));
    }
  }
  nx = z.size(0);
  for (jcol = 0; jcol < nx; jcol++) {
    b_r = x[jcol] * z[jcol].re;
    re_tmp = x[jcol] * z[jcol].im;
    z[jcol].re = b_r * A[jcol].re - re_tmp * A[jcol].im;
    z[jcol].im = b_r * A[jcol].im + re_tmp * A[jcol].re;
  }
}

//
// Arguments    : double x
//                double dk
//                double k
//                double theta
// Return Type  : creal_T
//
creal_T fresnelg2(double x, double dk, double k, double theta)
{
  array<creal_T, 2U> e;
  array<creal_T, 2U> hidkxx;
  array<creal_T, 2U> m2C;
  array<creal_T, 2U> r1;
  array<creal_T, 2U> z0;
  array<creal_T, 2U> z1;
  array<creal_T, 1U> r;
  array<double, 2U> b_k;
  array<double, 2U> b_x;
  array<double, 2U> c_x;
  array<double, 2U> d_x;
  array<double, 2U> r2;
  array<double, 2U> y;
  array<signed char, 2U> igt;
  array<signed char, 2U> ii;
  array<signed char, 2U> ilt;
  array<signed char, 2U> ism;
  creal_T z;
  double d;
  double re;
  double thresh;
  double thresh_tmp;
  double x_im;
  double z1_re;
  int i;
  int loop_ub;
  thresh_tmp = k * k;
  thresh = dk / thresh_tmp;
  if (thresh > 1.0E-6) {
    ii.set_size(1, 1);
    ii[0] = 1;
  } else {
    ii.set_size(0, 0);
  }
  igt.set_size(ii.size(0), ii.size(1));
  loop_ub = ii.size(0) * ii.size(1);
  for (i = 0; i < loop_ub; i++) {
    igt[0] = 1;
  }
  if (thresh < -1.0E-6) {
    ii.set_size(1, 1);
    ii[0] = 1;
  } else {
    ii.set_size(0, 0);
  }
  ilt.set_size(ii.size(0), ii.size(1));
  loop_ub = ii.size(0) * ii.size(1);
  for (i = 0; i < loop_ub; i++) {
    ilt[0] = 1;
  }
  if ((-1.0E-6 <= thresh) && (thresh <= 1.0E-6)) {
    ii.set_size(1, 1);
    ii[0] = 1;
  } else {
    ii.set_size(0, 0);
  }
  ism.set_size(ii.size(0), ii.size(1));
  loop_ub = ii.size(0) * ii.size(1);
  for (i = 0; i < loop_ub; i++) {
    ism[0] = 1;
  }
  d = x * x;
  if ((std::abs(dk) * d < 0.001) && (std::abs(k * x) < 0.001)) {
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
    b_k.set_size(1, 1);
    b_k[0] = k / b_x[0];
    fresnel(b_k, z0);
    r1.set_size(1, 1);
    thresh = theta - thresh_tmp / (2.0 * dk);
    r1[0].re = thresh * 0.0;
    r1[0].im = thresh;
    if (r1[0].im == 0.0) {
      re = std::exp(r1[0].re);
      thresh = 0.0;
    } else {
      thresh = std::exp(r1[0].re / 2.0);
      re = thresh * (thresh * std::cos(r1[0].im));
      thresh *= thresh * std::sin(r1[0].im);
    }
    r1[0].re = re;
    r1[0].im = thresh;
    r1[0].re = re;
    r1[0].im = thresh;
    r1[0].re = re;
    r1[0].im = thresh;
    b_x.set_size(1, 1);
    b_x[0] = 3.1415926535897931 / dk;
    b_x[0] = std::sqrt(b_x[0]);
    thresh = b_x[0] * r1[0].re;
    x_im = b_x[0] * r1[0].im;
    z1_re = z1[0].re - z0[0].re;
    re = z1[0].im - z0[0].im;
    z.re = thresh * z1_re - x_im * re;
    z.im = thresh * re + x_im * z1_re;
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
    b_k.set_size(1, 1);
    b_k[0] = -k / b_x[0];
    fresnel(b_k, z0);
    r1.set_size(1, 1);
    r1[0].re = (theta - k * k / (2.0 * dk)) * 0.0;
    r1[0].im = -(theta - k * k / (2.0 * dk));
    if (r1[0].im == 0.0) {
      re = std::exp(r1[0].re);
      thresh = 0.0;
    } else {
      thresh = std::exp(r1[0].re / 2.0);
      re = thresh * (thresh * std::cos(r1[0].im));
      thresh *= thresh * std::sin(r1[0].im);
    }
    r1[0].re = re;
    r1[0].im = thresh;
    r1[0].re = re;
    r1[0].im = thresh;
    r1[0].re = re;
    r1[0].im = thresh;
    b_x.set_size(1, 1);
    b_x[0] = -3.1415926535897931 / dk;
    b_x[0] = std::sqrt(b_x[0]);
    thresh = b_x[0] * r1[0].re;
    x_im = b_x[0] * r1[0].im;
    z1_re = z1[0].re - z0[0].re;
    re = z1[0].im - z0[0].im;
    z.re = thresh * z1_re - x_im * re;
    z.im = -(thresh * re + x_im * z1_re);
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
    y.set_size(1, 1);
    y[0] = thresh_tmp;
    m2C.set_size(1, 1);
    if (hidkxx[0].im == 0.0) {
      thresh = hidkxx[0].re / y[0];
      x_im = 0.0;
    } else if (hidkxx[0].re == 0.0) {
      thresh = 0.0;
      x_im = hidkxx[0].im / y[0];
    } else {
      thresh = rtNaN;
      x_im = hidkxx[0].im / y[0];
    }
    m2C[0].re = -2.0 * thresh;
    m2C[0].im = -2.0 * x_im;
    r2.set_size(1, 1);
    r2[0] = d;
    hidkxx[0].re = r2[0] * hidkxx[0].re;
    hidkxx[0].im = r2[0] * hidkxx[0].im;
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
      z1_re = std::abs(z1[0].re);
      thresh = std::abs(z1[0].im);
      if (z1_re > thresh) {
        thresh = z1[0].im / z1[0].re;
        x_im = z1[0].re + thresh * z1[0].im;
        re = ((1.0 - e[0].re) + thresh * (0.0 - e[0].im)) / x_im;
        thresh = ((0.0 - e[0].im) - thresh * (1.0 - e[0].re)) / x_im;
      } else if (thresh == z1_re) {
        if (z1[0].re > 0.0) {
          thresh = 0.5;
        } else {
          thresh = -0.5;
        }
        if (z1[0].im > 0.0) {
          x_im = 0.5;
        } else {
          x_im = -0.5;
        }
        re = ((1.0 - e[0].re) * thresh + (0.0 - e[0].im) * x_im) / z1_re;
        thresh = ((0.0 - e[0].im) * thresh - (1.0 - e[0].re) * x_im) / z1_re;
      } else {
        thresh = z1[0].re / z1[0].im;
        x_im = z1[0].im + thresh * z1[0].re;
        re = (thresh * (1.0 - e[0].re) + (0.0 - e[0].im)) / x_im;
        thresh = (thresh * (0.0 - e[0].im) - (1.0 - e[0].re)) / x_im;
      }
    }
    z1[0].re = re;
    z1[0].im = thresh;
    e[0].re = -e[0].re;
    e[0].im = -e[0].im;
    r1.set_size(1, 1);
    r1[0] = z1[0];
    for (loop_ub = 0; loop_ub < 20; loop_ub++) {
      z1.set_size(1, 1);
      i = 2 * (loop_ub + 1) - 1;
      thresh = (static_cast<double>(loop_ub) + 1.0) + z0[0].re;
      re = static_cast<double>(i) * z1[0].re +
           (e[0].re * thresh - e[0].im * z0[0].im);
      thresh = static_cast<double>(i) * z1[0].im +
               (e[0].re * z0[0].im + e[0].im * thresh);
      z1[0].re = m2C[0].re * re - m2C[0].im * thresh;
      z1[0].im = m2C[0].re * thresh + m2C[0].im * re;
      r1[0].re = r1[0].re + z1[0].re;
      r1[0].im = r1[0].im + z1[0].im;
      thresh = e[0].re * hidkxx[0].re - e[0].im * hidkxx[0].im;
      x_im = e[0].re * hidkxx[0].im + e[0].im * hidkxx[0].re;
      if (x_im == 0.0) {
        e[0].re = thresh / ((static_cast<double>(loop_ub) + 1.0) + 1.0);
        e[0].im = 0.0;
      } else if (thresh == 0.0) {
        e[0].re = 0.0;
        e[0].im = x_im / ((static_cast<double>(loop_ub) + 1.0) + 1.0);
      } else {
        e[0].re = thresh / ((static_cast<double>(loop_ub) + 1.0) + 1.0);
        e[0].im = x_im / ((static_cast<double>(loop_ub) + 1.0) + 1.0);
      }
    }
    z1.set_size(1, 1);
    z1[0].re = theta * 0.0;
    z1[0].im = theta;
    if (z1[0].im == 0.0) {
      re = std::exp(z1[0].re);
      thresh = 0.0;
    } else {
      thresh = std::exp(z1[0].re / 2.0);
      re = thresh * (thresh * std::cos(z1[0].im));
      thresh *= thresh * std::sin(z1[0].im);
    }
    z1[0].re = re;
    z1[0].im = thresh;
    z1[0].re = re;
    z1[0].im = thresh;
    z1[0].re = re;
    z1[0].im = thresh;
    r1.set_size(1, 1);
    thresh = x * r1[0].re;
    x_im = x * r1[0].im;
    r1[0].re = thresh * z1[0].re - x_im * z1[0].im;
    r1[0].im = thresh * z1[0].im + x_im * z1[0].re;
    z = r1[0];
  }
  if ((ii.size(0) != 0) && (ii.size(1) != 0)) {
    b_x.set_size(1, 1);
    b_x[0] = x;
    c_x.set_size(1, 1);
    c_x[0] = dk;
    b_k.set_size(1, 1);
    b_k[0] = k;
    d_x.set_size(1, 1);
    d_x[0] = theta;
    fresnelgzero(b_x, c_x, b_k, d_x, r);
    z = r[0];
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
