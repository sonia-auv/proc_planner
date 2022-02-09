//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: schur.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 08-Feb-2022 23:30:50
//

// Include Files
#include "schur.h"
#include "rt_nonfinite.h"
#include "xdhseqr.h"
#include "xgemv.h"
#include "xgerc.h"
#include "xzlarfg.h"
#include "coder_array.h"
#include <cmath>
#include <string.h>

// Function Definitions
//
// Arguments    : ::coder::array<double, 2U> &A
//                ::coder::array<double, 2U> &V
// Return Type  : void
//
namespace coder {
void schur(::coder::array<double, 2U> &A, ::coder::array<double, 2U> &V)
{
  array<double, 1U> tau;
  array<double, 1U> work;
  double alpha1;
  int istart;
  int nx;
  bool p;
  nx = A.size(0) * A.size(1);
  p = true;
  for (istart = 0; istart < nx; istart++) {
    if ((!p) || (std::isinf(A[istart]) || std::isnan(A[istart]))) {
      p = false;
    }
  }
  if (!p) {
    V.set_size(A.size(0), A.size(1));
    nx = A.size(0) * A.size(1);
    for (int i{0}; i < nx; i++) {
      V[i] = rtNaN;
    }
    nx = A.size(0);
    if ((A.size(0) != 0) && (A.size(1) != 0) && (1 < A.size(0))) {
      int jend;
      istart = 2;
      if (A.size(0) - 2 < A.size(1) - 1) {
        jend = A.size(0) - 1;
      } else {
        jend = A.size(1);
      }
      for (int ic0{0}; ic0 < jend; ic0++) {
        for (int b_i{istart}; b_i <= nx; b_i++) {
          V[(b_i + V.size(0) * ic0) - 1] = 0.0;
        }
        istart++;
      }
    }
  } else {
    int b_i;
    int i;
    int ic0;
    int jend;
    int n;
    n = A.size(0);
    if (A.size(0) < 1) {
      i = 0;
    } else {
      i = A.size(0) - 1;
    }
    tau.set_size(i);
    work.set_size(A.size(0));
    nx = A.size(0);
    for (i = 0; i < nx; i++) {
      work[i] = 0.0;
    }
    i = A.size(0);
    for (b_i = 0; b_i <= i - 2; b_i++) {
      double temp;
      int exitg1;
      int ia;
      int in;
      int iv0_tmp;
      int lastc;
      int lastv;
      int n_tmp_tmp;
      bool exitg2;
      in = (b_i + 1) * n;
      alpha1 = A[(b_i + A.size(0) * b_i) + 1];
      nx = b_i + 3;
      if (nx > n) {
        nx = n;
      }
      temp =
          internal::reflapack::xzlarfg((n - b_i) - 1, &alpha1, A, nx + b_i * n);
      tau[b_i] = temp;
      A[(b_i + A.size(0) * b_i) + 1] = 1.0;
      n_tmp_tmp = n - b_i;
      iv0_tmp = (b_i + b_i * n) + 2;
      ic0 = in + 1;
      if (temp != 0.0) {
        lastv = n_tmp_tmp - 2;
        nx = (iv0_tmp + n_tmp_tmp) - 4;
        while ((lastv + 1 > 0) && (A[nx + 1] == 0.0)) {
          lastv--;
          nx--;
        }
        lastc = n;
        exitg2 = false;
        while ((!exitg2) && (lastc > 0)) {
          nx = in + lastc;
          ia = nx;
          do {
            exitg1 = 0;
            if ((n > 0) && (ia <= nx + lastv * n)) {
              if (A[ia - 1] != 0.0) {
                exitg1 = 1;
              } else {
                ia += n;
              }
            } else {
              lastc--;
              exitg1 = 2;
            }
          } while (exitg1 == 0);
          if (exitg1 == 1) {
            exitg2 = true;
          }
        }
      } else {
        lastv = -1;
        lastc = 0;
      }
      if (lastv + 1 > 0) {
        int i1;
        int i2;
        if (lastc != 0) {
          for (nx = 0; nx < lastc; nx++) {
            work[nx] = 0.0;
          }
          nx = iv0_tmp - 1;
          i1 = (in + n * lastv) + 1;
          for (jend = ic0; n < 0 ? jend >= i1 : jend <= i1; jend += n) {
            i2 = (jend + lastc) - 1;
            for (ia = jend; ia <= i2; ia++) {
              istart = ia - jend;
              work[istart] = work[istart] + A[ia - 1] * A[nx];
            }
            nx++;
          }
        }
        if (!(-tau[b_i] == 0.0)) {
          nx = in;
          for (ic0 = 0; ic0 <= lastv; ic0++) {
            i1 = (iv0_tmp + ic0) - 1;
            if (A[i1] != 0.0) {
              temp = A[i1] * -tau[b_i];
              i1 = nx + 1;
              i2 = lastc + nx;
              for (istart = i1; istart <= i2; istart++) {
                A[istart - 1] = A[istart - 1] + work[(istart - nx) - 1] * temp;
              }
            }
            nx += n;
          }
        }
      }
      ic0 = (b_i + in) + 2;
      if (tau[b_i] != 0.0) {
        lastv = n_tmp_tmp - 1;
        nx = (iv0_tmp + n_tmp_tmp) - 3;
        while ((lastv > 0) && (A[nx] == 0.0)) {
          lastv--;
          nx--;
        }
        lastc = n_tmp_tmp - 1;
        exitg2 = false;
        while ((!exitg2) && (lastc > 0)) {
          nx = ic0 + (lastc - 1) * n;
          ia = nx;
          do {
            exitg1 = 0;
            if (ia <= (nx + lastv) - 1) {
              if (A[ia - 1] != 0.0) {
                exitg1 = 1;
              } else {
                ia++;
              }
            } else {
              lastc--;
              exitg1 = 2;
            }
          } while (exitg1 == 0);
          if (exitg1 == 1) {
            exitg2 = true;
          }
        }
      } else {
        lastv = 0;
        lastc = 0;
      }
      if (lastv > 0) {
        internal::blas::xgemv(lastv, lastc, A, ic0, n, A, iv0_tmp, work);
        internal::blas::xgerc(lastv, lastc, -tau[b_i], iv0_tmp, work, A, ic0,
                              n);
      }
      A[(b_i + A.size(0) * b_i) + 1] = alpha1;
    }
    V.set_size(A.size(0), A.size(1));
    nx = A.size(0) * A.size(1);
    for (i = 0; i < nx; i++) {
      V[i] = A[i];
    }
    internal::reflapack::eml_dlahqr(V);
    nx = V.size(0);
    if ((V.size(0) != 0) && (V.size(1) != 0) && (3 < V.size(0))) {
      istart = 4;
      if (V.size(0) - 4 < V.size(1) - 1) {
        jend = V.size(0) - 3;
      } else {
        jend = V.size(1);
      }
      for (ic0 = 0; ic0 < jend; ic0++) {
        for (b_i = istart; b_i <= nx; b_i++) {
          V[(b_i + V.size(0) * ic0) - 1] = 0.0;
        }
        istart++;
      }
    }
  }
}

} // namespace coder

//
// File trailer for schur.cpp
//
// [EOF]
//
