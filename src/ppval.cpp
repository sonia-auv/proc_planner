//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: ppval.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 05-Feb-2022 14:39:35
//

// Include Files
#include "ppval.h"
#include "bsearch.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <cmath>
#include <string.h>

// Function Definitions
//
// Arguments    : const ::coder::array<double, 2U> &pp_breaks
//                const ::coder::array<double, 3U> &pp_coefs
//                const ::coder::array<double, 1U> &x
//                ::coder::array<double, 2U> &v
// Return Type  : void
//
namespace coder {
void ppval(const ::coder::array<double, 2U> &pp_breaks,
           const ::coder::array<double, 3U> &pp_coefs,
           const ::coder::array<double, 1U> &x, ::coder::array<double, 2U> &v)
{
  int coefStride;
  int elementsPerPage;
  int numTerms;
  int nx;
  numTerms = pp_coefs.size(2);
  elementsPerPage = pp_coefs.size(0);
  coefStride = pp_coefs.size(0) * (pp_breaks.size(1) - 1);
  v.set_size(pp_coefs.size(0), x.size(0));
  nx = x.size(0) - 1;
  if (pp_coefs.size(0) == 1) {
    for (int ix{0}; ix <= nx; ix++) {
      double b_v;
      if ((numTerms > 1) && std::isnan(x[ix])) {
        b_v = x[ix];
      } else {
        double xloc;
        int ip;
        ip = internal::b_bsearch(pp_breaks, x[ix]) - 1;
        xloc = x[ix] - pp_breaks[ip];
        b_v = pp_coefs[ip];
        for (int ic{2}; ic <= numTerms; ic++) {
          b_v = xloc * b_v + pp_coefs[ip + (ic - 1) * coefStride];
        }
      }
      v[ix] = b_v;
    }
  } else {
    for (int ix{0}; ix <= nx; ix++) {
      int iv0;
      iv0 = ix * elementsPerPage;
      if ((numTerms > 1) && std::isnan(x[ix])) {
        for (int j{0}; j < elementsPerPage; j++) {
          v[iv0 + j] = x[ix];
        }
      } else {
        double xloc;
        int icp;
        int ip;
        int j;
        ip = internal::b_bsearch(pp_breaks, x[ix]) - 1;
        icp = ip * elementsPerPage;
        xloc = x[ix] - pp_breaks[ip];
        for (j = 0; j < elementsPerPage; j++) {
          v[iv0 + j] = pp_coefs[icp + j];
        }
        for (int ic{2}; ic <= numTerms; ic++) {
          ip = icp + (ic - 1) * coefStride;
          for (j = 0; j < elementsPerPage; j++) {
            int i;
            i = iv0 + j;
            v[i] = xloc * v[i] + pp_coefs[ip + j];
          }
        }
      }
    }
  }
}

//
// Arguments    : const ::coder::array<double, 2U> &pp_breaks
//                const ::coder::array<double, 3U> &pp_coefs
//                double x
//                ::coder::array<double, 1U> &v
// Return Type  : void
//
void ppval(const ::coder::array<double, 2U> &pp_breaks,
           const ::coder::array<double, 3U> &pp_coefs, double x,
           ::coder::array<double, 1U> &v)
{
  int coefStride;
  int elementsPerPage;
  int numTerms;
  numTerms = pp_coefs.size(2);
  elementsPerPage = pp_coefs.size(0);
  coefStride = pp_coefs.size(0) * (pp_breaks.size(1) - 1);
  v.set_size(pp_coefs.size(0));
  if (pp_coefs.size(0) == 1) {
    double b_v;
    if ((pp_coefs.size(2) > 1) && std::isnan(x)) {
      b_v = x;
    } else {
      double xloc;
      int ip;
      ip = internal::b_bsearch(pp_breaks, x) - 1;
      xloc = x - pp_breaks[ip];
      b_v = pp_coefs[ip];
      for (int ic{2}; ic <= numTerms; ic++) {
        b_v = xloc * b_v + pp_coefs[ip + (ic - 1) * coefStride];
      }
    }
    v[0] = b_v;
  } else if ((pp_coefs.size(2) > 1) && std::isnan(x)) {
    for (int j{0}; j < elementsPerPage; j++) {
      v[j] = x;
    }
  } else {
    double xloc;
    int icp;
    int ip;
    int j;
    ip = internal::b_bsearch(pp_breaks, x) - 1;
    icp = ip * pp_coefs.size(0);
    xloc = x - pp_breaks[ip];
    for (j = 0; j < elementsPerPage; j++) {
      v[j] = pp_coefs[icp + j];
    }
    for (int ic{2}; ic <= numTerms; ic++) {
      ip = icp + (ic - 1) * coefStride;
      for (j = 0; j < elementsPerPage; j++) {
        v[j] = xloc * v[j] + pp_coefs[ip + j];
      }
    }
  }
}

} // namespace coder

//
// File trailer for ppval.cpp
//
// [EOF]
//
