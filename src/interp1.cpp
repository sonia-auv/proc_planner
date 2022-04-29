//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: interp1.cpp
//
// MATLAB Coder version            : 5.4
// C/C++ source code generated on  : 28-Apr-2022 22:18:34
//

// Include Files
#include "interp1.h"
#include "bsearch.h"
#include "pchip.h"
#include "rt_nonfinite.h"
#include "spline.h"
#include "coder_array.h"
#include <cmath>
#include <math.h>

// Function Definitions
//
// Arguments    : const ::coder::array<double, 1U> &varargin_1
//                const ::coder::array<double, 1U> &varargin_2
//                const ::coder::array<double, 2U> &varargin_3
//                ::coder::array<double, 2U> &Vq
// Return Type  : void
//
namespace coder {
void b_interp1(const ::coder::array<double, 1U> &varargin_1,
               const ::coder::array<double, 1U> &varargin_2,
               const ::coder::array<double, 2U> &varargin_3,
               ::coder::array<double, 2U> &Vq)
{
  array<double, 2U> b_y;
  array<double, 2U> pp_breaks;
  array<double, 2U> pp_coefs;
  array<double, 1U> x;
  array<double, 1U> y;
  int ic;
  int n;
  int nx;
  bool b;
  y.set_size(varargin_2.size(0));
  n = varargin_2.size(0);
  for (ic = 0; ic < n; ic++) {
    y[ic] = varargin_2[ic];
  }
  x.set_size(varargin_1.size(0));
  n = varargin_1.size(0);
  for (ic = 0; ic < n; ic++) {
    x[ic] = varargin_1[ic];
  }
  nx = varargin_1.size(0) - 1;
  Vq.set_size(1, varargin_3.size(1));
  n = varargin_3.size(1);
  for (ic = 0; ic < n; ic++) {
    Vq[ic] = 0.0;
  }
  b = (varargin_3.size(1) == 0);
  if (!b) {
    int k;
    k = 0;
    int exitg1;
    do {
      exitg1 = 0;
      if (k <= nx) {
        if (std::isnan(varargin_1[k])) {
          exitg1 = 1;
        } else {
          k++;
        }
      } else {
        double xtmp;
        int nxi;
        if (varargin_1[1] < varargin_1[0]) {
          ic = (nx + 1) >> 1;
          for (nxi = 0; nxi < ic; nxi++) {
            xtmp = x[nxi];
            n = nx - nxi;
            x[nxi] = x[n];
            x[n] = xtmp;
          }
          if (varargin_2.size(0) > 1) {
            n = varargin_2.size(0) - 1;
            nx = varargin_2.size(0) >> 1;
            for (k = 0; k < nx; k++) {
              xtmp = y[k];
              nxi = n - k;
              y[k] = y[nxi];
              y[nxi] = xtmp;
            }
          }
        }
        nxi = varargin_3.size(1);
        b_y.set_size(1, y.size(0));
        n = y.size(0);
        for (ic = 0; ic < n; ic++) {
          b_y[ic] = y[ic];
        }
        spline(x, b_y, pp_breaks, pp_coefs);
        for (k = 0; k < nxi; k++) {
          xtmp = varargin_3[k];
          if (std::isnan(xtmp)) {
            Vq[k] = rtNaN;
          } else {
            n = pp_coefs.size(1);
            if ((pp_coefs.size(1) <= 1) || (!std::isnan(xtmp))) {
              double xloc;
              nx = internal::b_bsearch(pp_breaks, xtmp) - 1;
              xloc = xtmp - pp_breaks[nx];
              xtmp = pp_coefs[nx];
              for (ic = 2; ic <= n; ic++) {
                xtmp = xloc * xtmp +
                       pp_coefs[nx + (ic - 1) * (pp_breaks.size(1) - 1)];
              }
            }
            Vq[k] = xtmp;
          }
        }
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }
}

//
// Arguments    : const ::coder::array<double, 1U> &varargin_1
//                const ::coder::array<double, 1U> &varargin_2
//                const ::coder::array<double, 2U> &varargin_3
//                ::coder::array<double, 2U> &Vq
// Return Type  : void
//
void c_interp1(const ::coder::array<double, 1U> &varargin_1,
               const ::coder::array<double, 1U> &varargin_2,
               const ::coder::array<double, 2U> &varargin_3,
               ::coder::array<double, 2U> &Vq)
{
  array<double, 2U> b_y;
  array<double, 2U> pp_breaks;
  array<double, 2U> pp_coefs;
  array<double, 1U> x;
  array<double, 1U> y;
  int high_i;
  int n;
  int nx;
  int nxi;
  int nyrows;
  bool b;
  y.set_size(varargin_2.size(0));
  high_i = varargin_2.size(0);
  for (n = 0; n < high_i; n++) {
    y[n] = varargin_2[n];
  }
  x.set_size(varargin_1.size(0));
  high_i = varargin_1.size(0);
  for (n = 0; n < high_i; n++) {
    x[n] = varargin_1[n];
  }
  nyrows = varargin_2.size(0);
  nx = varargin_1.size(0) - 1;
  Vq.set_size(1, varargin_3.size(1));
  high_i = varargin_3.size(1);
  for (n = 0; n < high_i; n++) {
    Vq[n] = rtNaN;
  }
  b = (varargin_3.size(1) == 0);
  if (!b) {
    int k;
    k = 0;
    int exitg1;
    do {
      exitg1 = 0;
      if (k <= nx) {
        if (std::isnan(varargin_1[k])) {
          exitg1 = 1;
        } else {
          k++;
        }
      } else {
        double h;
        double xtmp;
        int nd2;
        if (varargin_1[1] < varargin_1[0]) {
          n = (nx + 1) >> 1;
          for (high_i = 0; high_i < n; high_i++) {
            xtmp = x[high_i];
            nd2 = nx - high_i;
            x[high_i] = x[nd2];
            x[nd2] = xtmp;
          }
          if (varargin_2.size(0) > 1) {
            n = varargin_2.size(0) - 1;
            nd2 = varargin_2.size(0) >> 1;
            for (k = 0; k < nd2; k++) {
              xtmp = y[k];
              high_i = n - k;
              y[k] = y[high_i];
              y[high_i] = xtmp;
            }
          }
        }
        h = 0.0;
        if ((!std::isinf(x[0])) && (!std::isinf(x[x.size(0) - 1]))) {
          bool exitg2;
          h = (x[x.size(0) - 1] - x[0]) /
              (static_cast<double>(x.size(0)) - 1.0);
          xtmp = std::fmax(std::abs(x[0]), std::abs(x[x.size(0) - 1]));
          if ((!std::isinf(xtmp)) && (!std::isnan(xtmp))) {
            if (xtmp <= 2.2250738585072014E-308) {
              xtmp = 4.94065645841247E-324;
            } else {
              frexp(xtmp, &nxi);
              xtmp = std::ldexp(1.0, nxi - 53);
            }
          } else {
            xtmp = rtNaN;
          }
          xtmp = std::fmin(4.0 * xtmp, h);
          k = 0;
          exitg2 = false;
          while ((!exitg2) && (k <= x.size(0) - 2)) {
            if (!(std::abs((x[k + 1] - x[k]) - h) <= xtmp)) {
              h = 0.0;
              exitg2 = true;
            } else {
              k++;
            }
          }
        }
        if (h > 0.0) {
          if (nyrows < 3) {
            nxi = varargin_3.size(1);
            for (k = 0; k < nxi; k++) {
              xtmp = varargin_3[k];
              if (std::isnan(xtmp)) {
                Vq[k] = rtNaN;
              } else if ((!(xtmp > x[x.size(0) - 1])) && (!(xtmp < x[0]))) {
                high_i = x.size(0);
                nd2 = 1;
                n = 2;
                while (high_i > n) {
                  nx = (nd2 >> 1) + (high_i >> 1);
                  if (((nd2 & 1) == 1) && ((high_i & 1) == 1)) {
                    nx++;
                  }
                  if (varargin_3[k] >= x[nx - 1]) {
                    nd2 = nx;
                    n = nx + 1;
                  } else {
                    high_i = nx;
                  }
                }
                xtmp = x[nd2 - 1];
                xtmp = (varargin_3[k] - xtmp) / (x[nd2] - xtmp);
                if (xtmp == 0.0) {
                  Vq[k] = y[nd2 - 1];
                } else if (xtmp == 1.0) {
                  Vq[k] = y[nd2];
                } else if (y[nd2 - 1] == y[nd2]) {
                  Vq[k] = y[nd2 - 1];
                } else {
                  Vq[k] = (1.0 - xtmp) * y[nd2 - 1] + xtmp * y[nd2];
                }
              }
            }
          } else {
            double minx;
            double penx;
            minx = x[0];
            penx = x[x.size(0) - 2];
            nxi = varargin_3.size(1);
            for (k = 0; k < nxi; k++) {
              xtmp = varargin_3[k];
              if (std::isnan(xtmp)) {
                Vq[k] = rtNaN;
              } else if ((xtmp >= minx) && (xtmp <= x[x.size(0) - 1])) {
                double c0;
                double c1;
                double c2;
                double s;
                double ssd2;
                double xloc;
                if (xtmp < x[1]) {
                  n = 1;
                  s = (xtmp - minx) / h;
                } else if (xtmp >= penx) {
                  n = nyrows - 1;
                  s = (xtmp - penx) / h;
                } else {
                  xloc = std::floor((xtmp - minx) / h);
                  n = static_cast<int>(xloc + 1.0);
                  if (xtmp >= x[static_cast<int>(xloc + 1.0)]) {
                    n = static_cast<int>(xloc + 1.0) + 1;
                  }
                  s = (xtmp - x[n - 1]) / h;
                }
                xtmp = s / 2.0;
                ssd2 = s * xtmp;
                xloc = 3.0 * s - 4.0;
                c0 = -s * (s * (xtmp - 1.0) + 0.5);
                c1 = ssd2 * (xloc - 1.0) + 1.0;
                c2 = -xtmp * (s * xloc - 1.0);
                xtmp = ssd2 * (s - 1.0);
                if (n < 2) {
                  xloc = y[n - 1];
                  s = y[n + 1];
                  Vq[k] = ((c0 * ((3.0 * xloc - 3.0 * y[n]) + s) + c1 * xloc) +
                           c2 * y[n]) +
                          xtmp * s;
                } else if (n < nyrows - 1) {
                  Vq[k] = ((c0 * y[n - 2] + c1 * y[n - 1]) + c2 * y[n]) +
                          xtmp * y[n + 1];
                } else {
                  xloc = y[n - 2];
                  Vq[k] = ((c0 * xloc + c1 * y[n - 1]) + c2 * y[n]) +
                          xtmp * ((3.0 * y[n] - 3.0 * y[n - 1]) + xloc);
                }
              }
            }
          }
        } else {
          nxi = varargin_3.size(1);
          b_y.set_size(1, y.size(0));
          high_i = y.size(0);
          for (n = 0; n < high_i; n++) {
            b_y[n] = y[n];
          }
          spline(x, b_y, pp_breaks, pp_coefs);
          for (k = 0; k < nxi; k++) {
            xtmp = varargin_3[k];
            if (std::isnan(xtmp)) {
              Vq[k] = rtNaN;
            } else if ((xtmp >= x[0]) && (xtmp <= x[x.size(0) - 1])) {
              double xloc;
              high_i = pp_coefs.size(1);
              nd2 = internal::b_bsearch(pp_breaks, xtmp) - 1;
              xloc = xtmp - pp_breaks[nd2];
              xtmp = pp_coefs[nd2];
              for (n = 2; n <= high_i; n++) {
                xtmp = xloc * xtmp +
                       pp_coefs[nd2 + (n - 1) * (pp_breaks.size(1) - 1)];
              }
              Vq[k] = xtmp;
            }
          }
        }
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }
}

//
// Arguments    : const ::coder::array<double, 1U> &varargin_1
//                const ::coder::array<double, 1U> &varargin_2
//                const ::coder::array<double, 2U> &varargin_3
//                ::coder::array<double, 2U> &Vq
// Return Type  : void
//
void interp1(const ::coder::array<double, 1U> &varargin_1,
             const ::coder::array<double, 1U> &varargin_2,
             const ::coder::array<double, 2U> &varargin_3,
             ::coder::array<double, 2U> &Vq)
{
  array<double, 2U> del;
  array<double, 2U> h;
  array<double, 2U> pp_coefs;
  array<double, 2U> slopes;
  array<double, 1U> x;
  array<double, 1U> y;
  int i;
  int n;
  int nx;
  bool b;
  y.set_size(varargin_2.size(0));
  n = varargin_2.size(0);
  for (i = 0; i < n; i++) {
    y[i] = varargin_2[i];
  }
  x.set_size(varargin_1.size(0));
  n = varargin_1.size(0);
  for (i = 0; i < n; i++) {
    x[i] = varargin_1[i];
  }
  nx = varargin_1.size(0) - 1;
  Vq.set_size(1, varargin_3.size(1));
  n = varargin_3.size(1);
  for (i = 0; i < n; i++) {
    Vq[i] = 0.0;
  }
  b = (varargin_3.size(1) == 0);
  if (!b) {
    int k;
    k = 0;
    int exitg1;
    do {
      exitg1 = 0;
      if (k <= nx) {
        if (std::isnan(varargin_1[k])) {
          exitg1 = 1;
        } else {
          k++;
        }
      } else {
        double d;
        double d1;
        double dzzdx;
        double hs3;
        double xtmp;
        int b_j1;
        int nxi;
        if (varargin_1[1] < varargin_1[0]) {
          i = (nx + 1) >> 1;
          for (b_j1 = 0; b_j1 < i; b_j1++) {
            xtmp = x[b_j1];
            n = nx - b_j1;
            x[b_j1] = x[n];
            x[n] = xtmp;
          }
          if (varargin_2.size(0) > 1) {
            n = varargin_2.size(0) - 1;
            nx = varargin_2.size(0) >> 1;
            for (k = 0; k < nx; k++) {
              xtmp = y[k];
              b_j1 = n - k;
              y[k] = y[b_j1];
              y[b_j1] = xtmp;
            }
          }
        }
        nxi = varargin_3.size(1);
        nx = x.size(0) - 2;
        h.set_size(1, x.size(0) - 1);
        del.set_size(1, y.size(0) - 1);
        for (k = 0; k <= nx; k++) {
          d = x[k + 1] - x[k];
          h[k] = d;
          del[k] = (y[k + 1] - y[k]) / d;
        }
        slopes.set_size(1, y.size(0));
        if (x.size(0) == 2) {
          slopes[0] = del[0];
          slopes[1] = del[0];
        } else {
          n = x.size(0);
          for (k = 0; k <= n - 3; k++) {
            d = h[k];
            d1 = h[k + 1];
            xtmp = d + d1;
            hs3 = 3.0 * xtmp;
            dzzdx = (d + xtmp) / hs3;
            xtmp = (d1 + xtmp) / hs3;
            slopes[k + 1] = 0.0;
            d = del[k];
            if (d < 0.0) {
              d1 = del[k + 1];
              if (d1 <= d) {
                slopes[k + 1] = d / (dzzdx * (d / d1) + xtmp);
              } else if (d1 < 0.0) {
                slopes[k + 1] = d1 / (dzzdx + xtmp * (d1 / d));
              }
            } else if (d > 0.0) {
              d1 = del[k + 1];
              if (d1 >= d) {
                slopes[k + 1] = d / (dzzdx * (d / del[k + 1]) + xtmp);
              } else if (d1 > 0.0) {
                slopes[k + 1] = del[k + 1] / (dzzdx + xtmp * (del[k + 1] / d));
              }
            }
          }
          slopes[0] = exteriorSlope(del[0], del[1], h[0], h[1]);
          slopes[x.size(0) - 1] =
              exteriorSlope(del[x.size(0) - 2], del[x.size(0) - 3],
                            h[x.size(0) - 2], h[x.size(0) - 3]);
        }
        nx = x.size(0);
        n = slopes.size(1) - 1;
        pp_coefs.set_size(slopes.size(1) - 1, 4);
        for (b_j1 = 0; b_j1 <= nx - 2; b_j1++) {
          d = del[b_j1];
          d1 = slopes[b_j1];
          hs3 = h[b_j1];
          dzzdx = (d - d1) / hs3;
          xtmp = (slopes[b_j1 + 1] - d) / hs3;
          pp_coefs[b_j1] = (xtmp - dzzdx) / hs3;
          pp_coefs[n + b_j1] = 2.0 * dzzdx - xtmp;
          pp_coefs[(n << 1) + b_j1] = d1;
          pp_coefs[3 * n + b_j1] = y[b_j1];
        }
        for (k = 0; k < nxi; k++) {
          xtmp = varargin_3[k];
          if (std::isnan(xtmp)) {
            Vq[k] = rtNaN;
          } else {
            if (!std::isnan(xtmp)) {
              h.set_size(1, x.size(0));
              n = x.size(0);
              for (i = 0; i < n; i++) {
                h[i] = x[i];
              }
              d = varargin_3[k];
              n = internal::b_bsearch(h, d) - 1;
              xtmp = d - x[n];
              xtmp = xtmp * (xtmp * (xtmp * pp_coefs[n] +
                                     pp_coefs[(n + x.size(0)) - 1]) +
                             pp_coefs[n + ((x.size(0) - 1) << 1)]) +
                     pp_coefs[n + 3 * (x.size(0) - 1)];
            }
            Vq[k] = xtmp;
          }
        }
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  }
}

} // namespace coder

//
// File trailer for interp1.cpp
//
// [EOF]
//
