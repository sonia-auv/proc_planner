//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: qrsolve.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 19-Feb-2022 14:46:56
//

// Include Files
#include "qrsolve.h"
#include "rt_nonfinite.h"
#include "xnrm2.h"
#include "xzlarfg.h"
#include "coder_array.h"
#include <cmath>
#include <string.h>

// Function Definitions
//
// Arguments    : const ::coder::array<double, 2U> &A
//                const ::coder::array<double, 1U> &B
//                ::coder::array<double, 1U> &Y
// Return Type  : void
//
namespace coder {
namespace internal {
void qrsolve(const ::coder::array<double, 2U> &A,
             const ::coder::array<double, 1U> &B, ::coder::array<double, 1U> &Y)
{
  array<double, 2U> b_A;
  array<double, 1U> tau;
  array<double, 1U> vn1;
  array<double, 1U> vn2;
  array<double, 1U> work;
  array<int, 2U> jpvt;
  double atmp;
  double smax;
  int b_i;
  int i;
  int lastc;
  int m;
  int minmana;
  int minmn;
  int n;
  int pvt;
  int rankA;
  b_A.set_size(A.size(0), A.size(1));
  minmana = A.size(0) * A.size(1);
  for (i = 0; i < minmana; i++) {
    b_A[i] = A[i];
  }
  m = A.size(0);
  n = A.size(1);
  lastc = A.size(0);
  minmana = A.size(1);
  if (lastc <= minmana) {
    minmana = lastc;
  }
  tau.set_size(minmana);
  for (i = 0; i < minmana; i++) {
    tau[i] = 0.0;
  }
  if ((A.size(0) == 0) || (A.size(1) == 0)) {
    jpvt.set_size(1, A.size(1));
    minmana = A.size(1);
    for (i = 0; i < minmana; i++) {
      jpvt[i] = 0;
    }
    for (pvt = 0; pvt < n; pvt++) {
      jpvt[pvt] = pvt + 1;
    }
  } else {
    double d;
    int k;
    int ma;
    jpvt.set_size(1, A.size(1));
    minmana = A.size(1);
    for (i = 0; i < minmana; i++) {
      jpvt[i] = 0;
    }
    for (k = 0; k < n; k++) {
      jpvt[k] = k + 1;
    }
    ma = A.size(0);
    lastc = A.size(0);
    minmn = A.size(1);
    if (lastc <= minmn) {
      minmn = lastc;
    }
    work.set_size(A.size(1));
    minmana = A.size(1);
    for (i = 0; i < minmana; i++) {
      work[i] = 0.0;
    }
    vn1.set_size(A.size(1));
    minmana = A.size(1);
    for (i = 0; i < minmana; i++) {
      vn1[i] = 0.0;
    }
    vn2.set_size(A.size(1));
    minmana = A.size(1);
    for (i = 0; i < minmana; i++) {
      vn2[i] = 0.0;
    }
    for (pvt = 0; pvt < n; pvt++) {
      d = blas::xnrm2(m, A, pvt * ma + 1);
      vn1[pvt] = d;
      vn2[pvt] = d;
    }
    for (b_i = 0; b_i < minmn; b_i++) {
      double s;
      int ii;
      int ip1;
      int mmi;
      int nmi;
      ip1 = b_i + 2;
      rankA = b_i * ma;
      ii = rankA + b_i;
      nmi = n - b_i;
      mmi = m - b_i;
      if (nmi < 1) {
        minmana = -1;
      } else {
        minmana = 0;
        if (nmi > 1) {
          smax = std::abs(vn1[b_i]);
          for (k = 2; k <= nmi; k++) {
            s = std::abs(vn1[(b_i + k) - 1]);
            if (s > smax) {
              minmana = k - 1;
              smax = s;
            }
          }
        }
      }
      pvt = b_i + minmana;
      if (pvt + 1 != b_i + 1) {
        minmana = pvt * ma;
        for (k = 0; k < m; k++) {
          lastc = minmana + k;
          smax = b_A[lastc];
          i = rankA + k;
          b_A[lastc] = b_A[i];
          b_A[i] = smax;
        }
        minmana = jpvt[pvt];
        jpvt[pvt] = jpvt[b_i];
        jpvt[b_i] = minmana;
        vn1[pvt] = vn1[b_i];
        vn2[pvt] = vn2[b_i];
      }
      if (b_i + 1 < m) {
        atmp = b_A[ii];
        d = reflapack::xzlarfg(mmi, &atmp, b_A, ii + 2);
        tau[b_i] = d;
        b_A[ii] = atmp;
      } else {
        d = 0.0;
        tau[b_i] = 0.0;
      }
      if (b_i + 1 < n) {
        int jA;
        int lastv;
        atmp = b_A[ii];
        b_A[ii] = 1.0;
        jA = (ii + ma) + 1;
        if (d != 0.0) {
          bool exitg2;
          lastv = mmi;
          minmana = (ii + mmi) - 1;
          while ((lastv > 0) && (b_A[minmana] == 0.0)) {
            lastv--;
            minmana--;
          }
          lastc = nmi - 1;
          exitg2 = false;
          while ((!exitg2) && (lastc > 0)) {
            int exitg1;
            minmana = jA + (lastc - 1) * ma;
            k = minmana;
            do {
              exitg1 = 0;
              if (k <= (minmana + lastv) - 1) {
                if (b_A[k - 1] != 0.0) {
                  exitg1 = 1;
                } else {
                  k++;
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
          if (lastc != 0) {
            for (rankA = 0; rankA < lastc; rankA++) {
              work[rankA] = 0.0;
            }
            rankA = 0;
            i = jA + ma * (lastc - 1);
            for (pvt = jA; ma < 0 ? pvt >= i : pvt <= i; pvt += ma) {
              smax = 0.0;
              minmana = (pvt + lastv) - 1;
              for (k = pvt; k <= minmana; k++) {
                smax += b_A[k - 1] * b_A[(ii + k) - pvt];
              }
              work[rankA] = work[rankA] + smax;
              rankA++;
            }
          }
          s = -tau[b_i];
          if (!(s == 0.0)) {
            for (pvt = 0; pvt < lastc; pvt++) {
              if (work[pvt] != 0.0) {
                smax = work[pvt] * s;
                i = lastv + jA;
                for (minmana = jA; minmana < i; minmana++) {
                  b_A[minmana - 1] =
                      b_A[minmana - 1] + b_A[(ii + minmana) - jA] * smax;
                }
              }
              jA += ma;
            }
          }
        }
        b_A[ii] = atmp;
      }
      for (pvt = ip1; pvt <= n; pvt++) {
        minmana = b_i + (pvt - 1) * ma;
        d = vn1[pvt - 1];
        if (d != 0.0) {
          smax = std::abs(b_A[minmana]) / d;
          smax = 1.0 - smax * smax;
          if (smax < 0.0) {
            smax = 0.0;
          }
          s = d / vn2[pvt - 1];
          s = smax * (s * s);
          if (s <= 1.4901161193847656E-8) {
            if (b_i + 1 < m) {
              d = blas::xnrm2(mmi - 1, b_A, minmana + 2);
              vn1[pvt - 1] = d;
              vn2[pvt - 1] = d;
            } else {
              vn1[pvt - 1] = 0.0;
              vn2[pvt - 1] = 0.0;
            }
          } else {
            vn1[pvt - 1] = d * std::sqrt(smax);
          }
        }
      }
    }
  }
  rankA = 0;
  if (b_A.size(0) < b_A.size(1)) {
    minmn = b_A.size(0);
    minmana = b_A.size(1);
  } else {
    minmn = b_A.size(1);
    minmana = b_A.size(0);
  }
  if (minmn > 0) {
    smax = std::fmin(1.4901161193847656E-8,
                     2.2204460492503131E-15 * static_cast<double>(minmana)) *
           std::abs(b_A[0]);
    while ((rankA < minmn) &&
           (!(std::abs(b_A[rankA + b_A.size(0) * rankA]) <= smax))) {
      rankA++;
    }
  }
  work.set_size(B.size(0));
  minmana = B.size(0);
  for (i = 0; i < minmana; i++) {
    work[i] = B[i];
  }
  Y.set_size(b_A.size(1));
  minmana = b_A.size(1);
  for (i = 0; i < minmana; i++) {
    Y[i] = 0.0;
  }
  m = b_A.size(0);
  lastc = b_A.size(0);
  minmana = b_A.size(1);
  if (lastc <= minmana) {
    minmana = lastc;
  }
  for (pvt = 0; pvt < minmana; pvt++) {
    if (tau[pvt] != 0.0) {
      smax = work[pvt];
      i = pvt + 2;
      for (b_i = i; b_i <= m; b_i++) {
        smax += b_A[(b_i + b_A.size(0) * pvt) - 1] * work[b_i - 1];
      }
      smax *= tau[pvt];
      if (smax != 0.0) {
        work[pvt] = work[pvt] - smax;
        for (b_i = i; b_i <= m; b_i++) {
          work[b_i - 1] =
              work[b_i - 1] - b_A[(b_i + b_A.size(0) * pvt) - 1] * smax;
        }
      }
    }
  }
  for (b_i = 0; b_i < rankA; b_i++) {
    Y[jpvt[b_i] - 1] = work[b_i];
  }
  for (pvt = rankA; pvt >= 1; pvt--) {
    i = jpvt[pvt - 1];
    Y[i - 1] = Y[i - 1] / b_A[(pvt + b_A.size(0) * (pvt - 1)) - 1];
    for (b_i = 0; b_i <= pvt - 2; b_i++) {
      Y[jpvt[b_i] - 1] =
          Y[jpvt[b_i] - 1] -
          Y[jpvt[pvt - 1] - 1] * b_A[b_i + b_A.size(0) * (pvt - 1)];
    }
  }
}

} // namespace internal
} // namespace coder

//
// File trailer for qrsolve.cpp
//
// [EOF]
//
