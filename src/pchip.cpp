//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: pchip.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 19-Feb-2022 14:46:56
//

// Include Files
#include "pchip.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <cmath>
#include <string.h>

// Function Declarations
namespace coder {
static double exteriorSlope(double d1, double d2, double h1, double h2);

}

// Function Definitions
//
// Arguments    : double d1
//                double d2
//                double h1
//                double h2
// Return Type  : double
//
namespace coder {
static double exteriorSlope(double d1, double d2, double h1, double h2)
{
  double s;
  double signd1;
  double signs;
  s = ((2.0 * h1 + h2) * d1 - h1 * d2) / (h1 + h2);
  signd1 = d1;
  if (d1 < 0.0) {
    signd1 = -1.0;
  } else if (d1 > 0.0) {
    signd1 = 1.0;
  } else if (d1 == 0.0) {
    signd1 = 0.0;
  }
  signs = s;
  if (s < 0.0) {
    signs = -1.0;
  } else if (s > 0.0) {
    signs = 1.0;
  } else if (s == 0.0) {
    signs = 0.0;
  }
  if (signs != signd1) {
    s = 0.0;
  } else {
    signs = d2;
    if (d2 < 0.0) {
      signs = -1.0;
    } else if (d2 > 0.0) {
      signs = 1.0;
    } else if (d2 == 0.0) {
      signs = 0.0;
    }
    if ((signd1 != signs) && (std::abs(s) > std::abs(3.0 * d1))) {
      s = 3.0 * d1;
    }
  }
  return s;
}

//
// Arguments    : const ::coder::array<double, 1U> &x
//                const ::coder::array<double, 1U> &y
//                ::coder::array<double, 2U> &v_breaks
//                ::coder::array<double, 2U> &v_coefs
// Return Type  : void
//
void pchip(const ::coder::array<double, 1U> &x,
           const ::coder::array<double, 1U> &y,
           ::coder::array<double, 2U> &v_breaks,
           ::coder::array<double, 2U> &v_coefs)
{
  array<double, 2U> del;
  array<double, 2U> h;
  array<double, 1U> slopes;
  double d;
  double d1;
  double hs;
  double hs3;
  int k;
  int nx;
  int nxm1;
  nx = x.size(0);
  nxm1 = x.size(0) - 2;
  h.set_size(1, x.size(0) - 1);
  for (k = 0; k <= nxm1; k++) {
    h[k] = x[k + 1] - x[k];
  }
  del.set_size(1, y.size(0) - 1);
  for (k = 0; k <= nxm1; k++) {
    del[k] = (y[k + 1] - y[k]) / h[k];
  }
  slopes.set_size(y.size(0));
  if (x.size(0) == 2) {
    for (k = 0; k < nx; k++) {
      slopes[k] = del[0];
    }
  } else {
    nx = x.size(0);
    for (k = 0; k <= nx - 3; k++) {
      double w1;
      d = h[k];
      d1 = h[k + 1];
      hs = d + d1;
      hs3 = 3.0 * hs;
      w1 = (d + hs) / hs3;
      hs = (d1 + hs) / hs3;
      slopes[k + 1] = 0.0;
      d = del[k];
      if (d < 0.0) {
        d1 = del[k + 1];
        if (d1 <= d) {
          slopes[k + 1] = d / (w1 * (d / d1) + hs);
        } else if (d1 < 0.0) {
          slopes[k + 1] = d1 / (w1 + hs * (d1 / d));
        }
      } else if (d > 0.0) {
        d1 = del[k + 1];
        if (d1 >= d) {
          slopes[k + 1] = d / (w1 * (d / del[k + 1]) + hs);
        } else if (d1 > 0.0) {
          slopes[k + 1] = del[k + 1] / (w1 + hs * (del[k + 1] / d));
        }
      }
    }
    slopes[0] = exteriorSlope(del[0], del[1], h[0], h[1]);
    slopes[x.size(0) - 1] =
        exteriorSlope(del[x.size(0) - 2], del[x.size(0) - 3], h[x.size(0) - 2],
                      h[x.size(0) - 3]);
  }
  nxm1 = x.size(0);
  v_breaks.set_size(1, x.size(0));
  nx = x.size(0);
  for (k = 0; k < nx; k++) {
    v_breaks[k] = x[k];
  }
  nx = slopes.size(0) - 1;
  v_coefs.set_size(slopes.size(0) - 1, 4);
  for (k = 0; k <= nxm1 - 2; k++) {
    d = del[k];
    d1 = h[k];
    hs3 = (d - slopes[k]) / d1;
    hs = (slopes[k + 1] - d) / d1;
    v_coefs[k] = (hs - hs3) / d1;
    v_coefs[nx + k] = 2.0 * hs3 - hs;
    v_coefs[(nx << 1) + k] = slopes[k];
    v_coefs[3 * nx + k] = y[k];
  }
}

} // namespace coder

//
// File trailer for pchip.cpp
//
// [EOF]
//
