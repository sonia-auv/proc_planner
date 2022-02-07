//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: derivpp.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 06-Feb-2022 23:10:59
//

// Include Files
#include "derivpp.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <string.h>

// Function Definitions
//
// Arguments    : const ::coder::array<double, 2U> &pp_breaks
//                const ::coder::array<double, 2U> &pp_coefs
//                ::coder::array<double, 2U> &dpp_breaks
//                ::coder::array<double, 3U> &dpp_coefs
// Return Type  : void
//
namespace coder {
namespace matlabshared {
namespace tracking {
namespace internal {
namespace scenario {
void derivpp(const ::coder::array<double, 2U> &pp_breaks,
             const ::coder::array<double, 2U> &pp_coefs,
             ::coder::array<double, 2U> &dpp_breaks,
             ::coder::array<double, 3U> &dpp_coefs)
{
  static const signed char iv[4]{0, 3, 2, 1};
  array<double, 2U> a;
  array<signed char, 2U> r;
  int ibmat;
  int itilerow;
  int jcol;
  int varargin_1;
  varargin_1 = pp_breaks.size(1) - 1;
  r.set_size(pp_breaks.size(1) - 1, 4);
  for (jcol = 0; jcol < 4; jcol++) {
    ibmat = jcol * varargin_1;
    for (itilerow = 0; itilerow < varargin_1; itilerow++) {
      r[ibmat + itilerow] = iv[jcol];
    }
  }
  a.set_size(pp_breaks.size(1) - 1, 4);
  varargin_1 = (pp_breaks.size(1) - 1) << 2;
  for (jcol = 0; jcol < varargin_1; jcol++) {
    a[jcol] = pp_coefs[jcol];
  }
  if (pp_breaks.size(1) - 1 != 0) {
    ibmat = pp_breaks.size(1) - 1;
    for (itilerow = 0; itilerow < ibmat; itilerow++) {
      double a__1;
      varargin_1 = itilerow + 3 * ibmat;
      a__1 = a[varargin_1];
      a[varargin_1] = a[itilerow + (ibmat << 1)];
      jcol = itilerow + ibmat;
      a[itilerow + 2 * ibmat] = a[jcol];
      a[jcol] = a[itilerow];
      a[itilerow] = a__1;
    }
  }
  dpp_coefs.set_size(1, pp_breaks.size(1) - 1, 4);
  varargin_1 = (pp_breaks.size(1) - 1) << 2;
  for (jcol = 0; jcol < varargin_1; jcol++) {
    dpp_coefs[jcol] = static_cast<double>(r[jcol]) * a[jcol];
  }
  dpp_breaks.set_size(1, pp_breaks.size(1));
  varargin_1 = pp_breaks.size(1);
  for (jcol = 0; jcol < varargin_1; jcol++) {
    dpp_breaks[jcol] = pp_breaks[jcol];
  }
}

//
// Arguments    : const ::coder::array<double, 2U> &pp_breaks
//                const ::coder::array<double, 3U> &pp_coefs
//                ::coder::array<double, 2U> &dpp_breaks
//                ::coder::array<double, 3U> &dpp_coefs
// Return Type  : void
//
void derivpp(const ::coder::array<double, 2U> &pp_breaks,
             const ::coder::array<double, 3U> &pp_coefs,
             ::coder::array<double, 2U> &dpp_breaks,
             ::coder::array<double, 3U> &dpp_coefs)
{
  static const signed char iv[4]{0, 3, 2, 1};
  array<double, 2U> a;
  array<signed char, 2U> r;
  int ibmat;
  int itilerow;
  int jcol;
  int varargin_1;
  varargin_1 = pp_breaks.size(1) - 1;
  r.set_size(pp_breaks.size(1) - 1, 4);
  for (jcol = 0; jcol < 4; jcol++) {
    ibmat = jcol * varargin_1;
    for (itilerow = 0; itilerow < varargin_1; itilerow++) {
      r[ibmat + itilerow] = iv[jcol];
    }
  }
  a.set_size(pp_breaks.size(1) - 1, 4);
  varargin_1 = (pp_breaks.size(1) - 1) << 2;
  for (jcol = 0; jcol < varargin_1; jcol++) {
    a[jcol] = pp_coefs[jcol];
  }
  if (pp_breaks.size(1) - 1 != 0) {
    ibmat = pp_breaks.size(1) - 1;
    for (itilerow = 0; itilerow < ibmat; itilerow++) {
      double a__1;
      varargin_1 = itilerow + 3 * ibmat;
      a__1 = a[varargin_1];
      a[varargin_1] = a[itilerow + (ibmat << 1)];
      jcol = itilerow + ibmat;
      a[itilerow + 2 * ibmat] = a[jcol];
      a[jcol] = a[itilerow];
      a[itilerow] = a__1;
    }
  }
  dpp_coefs.set_size(1, pp_breaks.size(1) - 1, 4);
  varargin_1 = (pp_breaks.size(1) - 1) << 2;
  for (jcol = 0; jcol < varargin_1; jcol++) {
    dpp_coefs[jcol] = static_cast<double>(r[jcol]) * a[jcol];
  }
  dpp_breaks.set_size(1, pp_breaks.size(1));
  varargin_1 = pp_breaks.size(1);
  for (jcol = 0; jcol < varargin_1; jcol++) {
    dpp_breaks[jcol] = pp_breaks[jcol];
  }
}

} // namespace scenario
} // namespace internal
} // namespace tracking
} // namespace matlabshared
} // namespace coder

//
// File trailer for derivpp.cpp
//
// [EOF]
//
