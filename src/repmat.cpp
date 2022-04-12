//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: repmat.cpp
//
// MATLAB Coder version            : 5.4
// C/C++ source code generated on  : 12-Apr-2022 11:44:16
//

// Include Files
#include "repmat.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <string.h>

// Function Definitions
//
// Arguments    : const ::coder::array<creal_T, 2U> &a
//                ::coder::array<creal_T, 2U> &b
// Return Type  : void
//
namespace coder {
void repmat(const ::coder::array<creal_T, 2U> &a,
            ::coder::array<creal_T, 2U> &b)
{
  int ncols;
  int nrows;
  b.set_size(a.size(0), a.size(1) * 5);
  nrows = a.size(0);
  ncols = a.size(1);
  for (int jtilecol{0}; jtilecol < 5; jtilecol++) {
    int ibtile;
    ibtile = jtilecol * (nrows * ncols) - 1;
    for (int jcol{0}; jcol < ncols; jcol++) {
      int iacol_tmp;
      int ibcol;
      iacol_tmp = jcol * nrows;
      ibcol = ibtile + iacol_tmp;
      for (int k{0}; k < nrows; k++) {
        b[(ibcol + k) + 1] = a[iacol_tmp + k];
      }
    }
  }
}

} // namespace coder

//
// File trailer for repmat.cpp
//
// [EOF]
//
