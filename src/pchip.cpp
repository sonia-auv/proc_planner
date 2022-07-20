//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// pchip.cpp
//
// Code generation for function 'pchip'
//

// Include files
#include "pchip.h"
#include "rt_nonfinite.h"
#include <cmath>

// Function Definitions
namespace coder {
double exteriorSlope(double d1, double d2, double h1, double h2)
{
  double s;
  double signd1;
  double signs;
  s = ((2.0 * h1 + h2) * d1 - h1 * d2) / (h1 + h2);
  signd1 = d1;
  if (!std::isnan(d1)) {
    if (d1 < 0.0) {
      signd1 = -1.0;
    } else {
      signd1 = (d1 > 0.0);
    }
  }
  signs = s;
  if (!std::isnan(s)) {
    if (s < 0.0) {
      signs = -1.0;
    } else {
      signs = (s > 0.0);
    }
  }
  if (signs != signd1) {
    s = 0.0;
  } else {
    signs = d2;
    if (!std::isnan(d2)) {
      if (d2 < 0.0) {
        signs = -1.0;
      } else {
        signs = (d2 > 0.0);
      }
    }
    if ((signd1 != signs) && (std::abs(s) > std::abs(3.0 * d1))) {
      s = 3.0 * d1;
    }
  }
  return s;
}

} // namespace coder

// End of code generation (pchip.cpp)
