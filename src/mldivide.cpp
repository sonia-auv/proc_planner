//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: mldivide.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 03-Feb-2022 14:08:22
//

// Include Files
#include "mldivide.h"
#include "qrsolve.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <cmath>
#include <string.h>

// Function Definitions
//
// Arguments    : const ::coder::array<double, 2U> &A
//                ::coder::array<double, 1U> &B
// Return Type  : void
//
namespace coder {
void mldivide(const ::coder::array<double, 2U> &A,
              ::coder::array<double, 1U> &B)
{
  array<double, 2U> b_A;
  array<double, 1U> b_B;
  array<int, 2U> ipiv;
  if ((A.size(0) == 0) || (A.size(1) == 0) || (B.size(0) == 0)) {
    int n;
    B.set_size(A.size(1));
    n = A.size(1);
    for (int i{0}; i < n; i++) {
      B[i] = 0.0;
    }
  } else if (A.size(0) == A.size(1)) {
    double smax;
    int LDA;
    int b_n;
    int i;
    int k;
    int n;
    int u0;
    int yk;
    u0 = A.size(0);
    b_n = A.size(1);
    if (u0 <= b_n) {
      b_n = u0;
    }
    u0 = B.size(0);
    if (u0 <= b_n) {
      b_n = u0;
    }
    LDA = A.size(0);
    b_A.set_size(A.size(0), A.size(1));
    n = A.size(0) * A.size(1);
    for (i = 0; i < n; i++) {
      b_A[i] = A[i];
    }
    if (b_n < 1) {
      n = 0;
    } else {
      n = b_n;
    }
    ipiv.set_size(1, n);
    if (n > 0) {
      ipiv[0] = 1;
      yk = 1;
      for (k = 2; k <= n; k++) {
        yk++;
        ipiv[k - 1] = yk;
      }
    }
    if (b_n >= 1) {
      int ldap1;
      ldap1 = A.size(0);
      u0 = b_n - 1;
      if (u0 > b_n) {
        u0 = b_n;
      }
      for (int j{0}; j < u0; j++) {
        int b;
        int jA;
        int jj;
        int jp1j;
        int mmj_tmp;
        mmj_tmp = b_n - j;
        b = j * (LDA + 1);
        jj = j * (ldap1 + 1);
        jp1j = b + 2;
        if (mmj_tmp < 1) {
          n = -1;
        } else {
          n = 0;
          if (mmj_tmp > 1) {
            smax = std::abs(b_A[jj]);
            for (k = 2; k <= mmj_tmp; k++) {
              double s;
              s = std::abs(b_A[(b + k) - 1]);
              if (s > smax) {
                n = k - 1;
                smax = s;
              }
            }
          }
        }
        if (b_A[jj + n] != 0.0) {
          if (n != 0) {
            yk = j + n;
            ipiv[j] = yk + 1;
            for (k = 0; k < b_n; k++) {
              n = k * LDA;
              jA = j + n;
              smax = b_A[jA];
              i = yk + n;
              b_A[jA] = b_A[i];
              b_A[i] = smax;
            }
          }
          i = jj + mmj_tmp;
          for (yk = jp1j; yk <= i; yk++) {
            b_A[yk - 1] = b_A[yk - 1] / b_A[jj];
          }
        }
        yk = b + LDA;
        jA = jj + ldap1;
        for (jp1j = 0; jp1j <= mmj_tmp - 2; jp1j++) {
          n = yk + jp1j * LDA;
          smax = b_A[n];
          if (b_A[n] != 0.0) {
            i = jA + 2;
            n = mmj_tmp + jA;
            for (b = i; b <= n; b++) {
              b_A[b - 1] = b_A[b - 1] + b_A[((jj + b) - jA) - 1] * -smax;
            }
          }
          jA += LDA;
        }
      }
    }
    LDA = b_A.size(0);
    for (yk = 0; yk <= b_n - 2; yk++) {
      i = ipiv[yk];
      if (i != yk + 1) {
        smax = B[yk];
        B[yk] = B[i - 1];
        B[i - 1] = smax;
      }
    }
    if (B.size(0) != 0) {
      for (k = 0; k < b_n; k++) {
        n = LDA * k;
        if (B[k] != 0.0) {
          i = k + 2;
          for (yk = i; yk <= b_n; yk++) {
            B[yk - 1] = B[yk - 1] - B[k] * b_A[(yk + n) - 1];
          }
        }
      }
    }
    if (B.size(0) != 0) {
      for (k = b_n; k >= 1; k--) {
        n = LDA * (k - 1);
        smax = B[k - 1];
        if (smax != 0.0) {
          B[k - 1] = smax / b_A[(k + n) - 1];
          for (yk = 0; yk <= k - 2; yk++) {
            B[yk] = B[yk] - B[k - 1] * b_A[yk + n];
          }
        }
      }
    }
  } else {
    int n;
    b_B.set_size(B.size(0));
    n = B.size(0) - 1;
    for (int i{0}; i <= n; i++) {
      b_B[i] = B[i];
    }
    internal::qrsolve(A, b_B, B);
  }
}

} // namespace coder

//
// File trailer for mldivide.cpp
//
// [EOF]
//
