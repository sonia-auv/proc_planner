//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: derivpp.cpp
//
// MATLAB Coder version            : 5.4
// C/C++ source code generated on  : 12-Apr-2022 11:44:16
//

// Include Files
#include "derivpp.h"
#include "mkpp.h"
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
  array<double, 2U> r1;
  array<signed char, 2U> r;
  int ibmat;
  int itilerow;
  int ntilerows;
  r.set_size(pp_breaks.size(1) - 1, 4);
  ntilerows = pp_breaks.size(1) - 2;
  for (int jcol{0}; jcol < 4; jcol++) {
    ibmat = jcol * (ntilerows + 1);
    for (itilerow = 0; itilerow <= ntilerows; itilerow++) {
      r[ibmat + itilerow] = iv[jcol];
    }
  }
  a.set_size(pp_breaks.size(1) - 1, 4);
  ntilerows = (pp_breaks.size(1) - 1) << 2;
  for (itilerow = 0; itilerow < ntilerows; itilerow++) {
    a[itilerow] = pp_coefs[itilerow];
  }
  if (pp_breaks.size(1) - 1 != 0) {
    ibmat = pp_breaks.size(1) - 1;
    for (int jcol{0}; jcol < ibmat; jcol++) {
      double a__1;
      ntilerows = jcol + 3 * ibmat;
      a__1 = a[ntilerows];
      itilerow = jcol + (ibmat << 1);
      a[ntilerows] = a[itilerow];
      ntilerows = jcol + ibmat;
      a[itilerow] = a[ntilerows];
      a[ntilerows] = a[jcol];
      a[jcol] = a__1;
    }
  }
  if (r.size(0) == a.size(0)) {
    r1.set_size(r.size(0), 4);
    ntilerows = r.size(0) * 4;
    for (itilerow = 0; itilerow < ntilerows; itilerow++) {
      r1[itilerow] = static_cast<double>(r[itilerow]) * a[itilerow];
    }
    dpp_coefs.set_size(1, pp_breaks.size(1) - 1, 4);
    ntilerows = (pp_breaks.size(1) - 1) << 2;
    for (itilerow = 0; itilerow < ntilerows; itilerow++) {
      dpp_coefs[itilerow] = r1[itilerow];
    }
  } else {
    binary_expand_op(dpp_coefs, r, a, pp_breaks);
  }
  dpp_breaks.set_size(1, pp_breaks.size(1));
  ntilerows = pp_breaks.size(1);
  for (itilerow = 0; itilerow < ntilerows; itilerow++) {
    dpp_breaks[itilerow] = pp_breaks[itilerow];
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
  array<double, 2U> r1;
  array<signed char, 2U> r;
  int ibmat;
  int itilerow;
  int ntilerows;
  r.set_size(pp_breaks.size(1) - 1, 4);
  ntilerows = pp_breaks.size(1) - 2;
  for (int jcol{0}; jcol < 4; jcol++) {
    ibmat = jcol * (ntilerows + 1);
    for (itilerow = 0; itilerow <= ntilerows; itilerow++) {
      r[ibmat + itilerow] = iv[jcol];
    }
  }
  a.set_size(pp_breaks.size(1) - 1, 4);
  ntilerows = (pp_breaks.size(1) - 1) << 2;
  for (itilerow = 0; itilerow < ntilerows; itilerow++) {
    a[itilerow] = pp_coefs[itilerow];
  }
  if (pp_breaks.size(1) - 1 != 0) {
    ibmat = pp_breaks.size(1) - 1;
    for (int jcol{0}; jcol < ibmat; jcol++) {
      double a__1;
      ntilerows = jcol + 3 * ibmat;
      a__1 = a[ntilerows];
      itilerow = jcol + (ibmat << 1);
      a[ntilerows] = a[itilerow];
      ntilerows = jcol + ibmat;
      a[itilerow] = a[ntilerows];
      a[ntilerows] = a[jcol];
      a[jcol] = a__1;
    }
  }
  if (r.size(0) == a.size(0)) {
    r1.set_size(r.size(0), 4);
    ntilerows = r.size(0) * 4;
    for (itilerow = 0; itilerow < ntilerows; itilerow++) {
      r1[itilerow] = static_cast<double>(r[itilerow]) * a[itilerow];
    }
    dpp_coefs.set_size(1, pp_breaks.size(1) - 1, 4);
    ntilerows = (pp_breaks.size(1) - 1) << 2;
    for (itilerow = 0; itilerow < ntilerows; itilerow++) {
      dpp_coefs[itilerow] = r1[itilerow];
    }
  } else {
    binary_expand_op(dpp_coefs, r, a, pp_breaks);
  }
  dpp_breaks.set_size(1, pp_breaks.size(1));
  ntilerows = pp_breaks.size(1);
  for (itilerow = 0; itilerow < ntilerows; itilerow++) {
    dpp_breaks[itilerow] = pp_breaks[itilerow];
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
