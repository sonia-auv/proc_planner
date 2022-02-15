//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: xzhgeqz.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 09-Feb-2022 14:06:20
//

#ifndef XZHGEQZ_H
#define XZHGEQZ_H

// Include Files
#include "rtwtypes.h"
#include "coder_array.h"
#include <cstddef>
#include <cstdlib>

// Function Declarations
namespace coder {
namespace internal {
namespace reflapack {
void xzhgeqz(const ::coder::array<creal_T, 2U> &A, int ilo, int ihi, int *info,
             ::coder::array<creal_T, 1U> &alpha1,
             ::coder::array<creal_T, 1U> &beta1);

}
} // namespace internal
} // namespace coder

#endif
//
// File trailer for xzhgeqz.h
//
// [EOF]
//
