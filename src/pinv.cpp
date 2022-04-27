//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: pinv.cpp
//
// MATLAB Coder version            : 5.4
// C/C++ source code generated on  : 26-Apr-2022 22:23:20
//

// Include Files
#include "pinv.h"
#include "rt_nonfinite.h"
#include "svd.h"
#include <cmath>
#include <cstring>
#include <math.h>

// Function Definitions
//
// Arguments    : const double A[12]
//                double X[12]
// Return Type  : void
//
namespace coder {
void pinv(const double A[12], double X[12])
{
  int br;
  int vcol;
  bool p;
  p = true;
  for (br = 0; br < 12; br++) {
    X[br] = 0.0;
    if ((!p) || (std::isinf(A[br]) || std::isnan(A[br]))) {
      p = false;
    }
  }
  if (!p) {
    for (int i{0}; i < 12; i++) {
      X[i] = rtNaN;
    }
  } else {
    double U[12];
    double V[9];
    double s[3];
    double absx;
    int r;
    internal::svd(A, U, s, V);
    absx = std::abs(s[0]);
    if ((!std::isinf(absx)) && (!std::isnan(absx))) {
      if (absx <= 2.2250738585072014E-308) {
        absx = 4.94065645841247E-324;
      } else {
        frexp(absx, &vcol);
        absx = std::ldexp(1.0, vcol - 53);
      }
    } else {
      absx = rtNaN;
    }
    absx *= 4.0;
    r = -1;
    br = 0;
    while ((br < 3) && (s[br] > absx)) {
      r++;
      br++;
    }
    if (r + 1 > 0) {
      int i;
      int j;
      vcol = 1;
      for (j = 0; j <= r; j++) {
        absx = 1.0 / s[j];
        i = vcol + 2;
        for (br = vcol; br <= i; br++) {
          V[br - 1] *= absx;
        }
        vcol += 3;
      }
      for (vcol = 0; vcol <= 9; vcol += 3) {
        i = vcol + 1;
        j = vcol + 3;
        if (i <= j) {
          std::memset(&X[i + -1], 0, ((j - i) + 1) * sizeof(double));
        }
      }
      br = 0;
      for (vcol = 0; vcol <= 9; vcol += 3) {
        int ar;
        ar = -1;
        br++;
        i = br + (r << 2);
        for (int ib{br}; ib <= i; ib += 4) {
          int i1;
          j = vcol + 1;
          i1 = vcol + 3;
          for (int ic{j}; ic <= i1; ic++) {
            X[ic - 1] += U[ib - 1] * V[(ar + ic) - vcol];
          }
          ar += 3;
        }
      }
    }
  }
}

} // namespace coder

//
// File trailer for pinv.cpp
//
// [EOF]
//
