//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: svd.cpp
//
// MATLAB Coder version            : 5.4
// C/C++ source code generated on  : 12-May-2022 22:37:14
//

// Include Files
#include "svd.h"
#include "rt_nonfinite.h"
#include "xaxpy.h"
#include "xdotc.h"
#include "xnrm2.h"
#include "xrot.h"
#include "xrotg.h"
#include "xswap.h"
#include <cmath>
#include <cstring>

// Function Definitions
//
// Arguments    : const double A[12]
//                double U[12]
//                double s[3]
//                double V[9]
// Return Type  : void
//
namespace coder {
namespace internal {
void svd(const double A[12], double U[12], double s[3], double V[9])
{
  double b_A[12];
  double Vf[9];
  double work[4];
  double b_s[3];
  double e[3];
  double nrm;
  double rt;
  double sm;
  double snorm;
  double sqds;
  int ii;
  int iter;
  int kase;
  int m;
  int qjj;
  int qp1;
  int qq;
  b_s[0] = 0.0;
  e[0] = 0.0;
  b_s[1] = 0.0;
  e[1] = 0.0;
  b_s[2] = 0.0;
  e[2] = 0.0;
  work[0] = 0.0;
  work[1] = 0.0;
  work[2] = 0.0;
  work[3] = 0.0;
  for (qjj = 0; qjj < 12; qjj++) {
    b_A[qjj] = A[qjj];
    U[qjj] = 0.0;
  }
  std::memset(&Vf[0], 0, 9U * sizeof(double));
  for (int q{0}; q < 3; q++) {
    bool apply_transform;
    qp1 = q + 2;
    iter = q << 2;
    qq = (q + iter) + 1;
    apply_transform = false;
    nrm = blas::xnrm2(4 - q, b_A, qq);
    if (nrm > 0.0) {
      apply_transform = true;
      if (b_A[qq - 1] < 0.0) {
        nrm = -nrm;
      }
      b_s[q] = nrm;
      if (std::abs(nrm) >= 1.0020841800044864E-292) {
        nrm = 1.0 / nrm;
        qjj = (qq - q) + 3;
        for (int k{qq}; k <= qjj; k++) {
          b_A[k - 1] *= nrm;
        }
      } else {
        qjj = (qq - q) + 3;
        for (int k{qq}; k <= qjj; k++) {
          b_A[k - 1] /= b_s[q];
        }
      }
      b_A[qq - 1]++;
      b_s[q] = -b_s[q];
    } else {
      b_s[q] = 0.0;
    }
    for (kase = qp1; kase < 4; kase++) {
      qjj = q + ((kase - 1) << 2);
      if (apply_transform) {
        blas::xaxpy(
            4 - q,
            -(blas::xdotc(4 - q, b_A, qq, b_A, qjj + 1) / b_A[q + (q << 2)]),
            qq, b_A, qjj + 1);
      }
      e[kase - 1] = b_A[qjj];
    }
    for (ii = q + 1; ii < 5; ii++) {
      kase = (ii + iter) - 1;
      U[kase] = b_A[kase];
    }
    if (q + 1 <= 1) {
      nrm = blas::xnrm2(e);
      if (nrm == 0.0) {
        e[0] = 0.0;
      } else {
        if (e[1] < 0.0) {
          e[0] = -nrm;
        } else {
          e[0] = nrm;
        }
        nrm = e[0];
        if (std::abs(e[0]) >= 1.0020841800044864E-292) {
          nrm = 1.0 / e[0];
          for (int k{qp1}; k < 4; k++) {
            e[k - 1] *= nrm;
          }
        } else {
          for (int k{qp1}; k < 4; k++) {
            e[k - 1] /= nrm;
          }
        }
        e[1]++;
        e[0] = -e[0];
        for (ii = qp1; ii < 5; ii++) {
          work[ii - 1] = 0.0;
        }
        for (kase = qp1; kase < 4; kase++) {
          blas::xaxpy(e[kase - 1], b_A, ((kase - 1) << 2) + 2, work);
        }
        for (kase = qp1; kase < 4; kase++) {
          blas::xaxpy(-e[kase - 1] / e[1], work, b_A, ((kase - 1) << 2) + 2);
        }
      }
      for (ii = qp1; ii < 4; ii++) {
        Vf[ii - 1] = e[ii - 1];
      }
    }
  }
  m = 1;
  e[1] = b_A[9];
  e[2] = 0.0;
  for (int q{2}; q >= 0; q--) {
    qp1 = q + 2;
    iter = q << 2;
    qq = q + iter;
    if (b_s[q] != 0.0) {
      for (kase = qp1; kase < 4; kase++) {
        qjj = (q + ((kase - 1) << 2)) + 1;
        blas::xaxpy(4 - q, -(blas::xdotc(4 - q, U, qq + 1, U, qjj) / U[qq]),
                    qq + 1, U, qjj);
      }
      for (ii = q + 1; ii < 5; ii++) {
        kase = (ii + iter) - 1;
        U[kase] = -U[kase];
      }
      U[qq]++;
      for (ii = 0; ii < q; ii++) {
        U[ii + iter] = 0.0;
      }
    } else {
      U[iter] = 0.0;
      U[iter + 1] = 0.0;
      U[iter + 2] = 0.0;
      U[iter + 3] = 0.0;
      U[qq] = 1.0;
    }
  }
  for (int q{2}; q >= 0; q--) {
    if ((q + 1 <= 1) && (e[0] != 0.0)) {
      blas::xaxpy(-(blas::xdotc(Vf, Vf, 5) / Vf[1]), Vf, 5);
      blas::xaxpy(-(blas::xdotc(Vf, Vf, 8) / Vf[1]), Vf, 8);
    }
    Vf[3 * q] = 0.0;
    Vf[3 * q + 1] = 0.0;
    Vf[3 * q + 2] = 0.0;
    Vf[q + 3 * q] = 1.0;
  }
  iter = 0;
  snorm = 0.0;
  for (int q{0}; q < 3; q++) {
    nrm = b_s[q];
    if (nrm != 0.0) {
      rt = std::abs(nrm);
      nrm /= rt;
      b_s[q] = rt;
      if (q + 1 < 3) {
        e[q] /= nrm;
      }
      kase = q << 2;
      qjj = kase + 4;
      for (int k{kase + 1}; k <= qjj; k++) {
        U[k - 1] *= nrm;
      }
    }
    if (q + 1 < 3) {
      nrm = e[q];
      if (nrm != 0.0) {
        rt = std::abs(nrm);
        nrm = rt / nrm;
        e[q] = rt;
        b_s[q + 1] *= nrm;
        kase = 3 * (q + 1);
        qjj = kase + 3;
        for (int k{kase + 1}; k <= qjj; k++) {
          Vf[k - 1] *= nrm;
        }
      }
    }
    snorm = std::fmax(snorm, std::fmax(std::abs(b_s[q]), std::abs(e[q])));
  }
  while ((m + 2 > 0) && (iter < 75)) {
    bool exitg1;
    qp1 = m + 1;
    ii = m + 1;
    exitg1 = false;
    while (!(exitg1 || (ii == 0))) {
      nrm = std::abs(e[ii - 1]);
      if ((nrm <= 2.2204460492503131E-16 *
                      (std::abs(b_s[ii - 1]) + std::abs(b_s[ii]))) ||
          (nrm <= 1.0020841800044864E-292) ||
          ((iter > 20) && (nrm <= 2.2204460492503131E-16 * snorm))) {
        e[ii - 1] = 0.0;
        exitg1 = true;
      } else {
        ii--;
      }
    }
    if (ii == m + 1) {
      kase = 4;
    } else {
      qjj = m + 2;
      kase = m + 2;
      exitg1 = false;
      while ((!exitg1) && (kase >= ii)) {
        qjj = kase;
        if (kase == ii) {
          exitg1 = true;
        } else {
          nrm = 0.0;
          if (kase < m + 2) {
            nrm = std::abs(e[kase - 1]);
          }
          if (kase > ii + 1) {
            nrm += std::abs(e[kase - 2]);
          }
          rt = std::abs(b_s[kase - 1]);
          if ((rt <= 2.2204460492503131E-16 * nrm) ||
              (rt <= 1.0020841800044864E-292)) {
            b_s[kase - 1] = 0.0;
            exitg1 = true;
          } else {
            kase--;
          }
        }
      }
      if (qjj == ii) {
        kase = 3;
      } else if (qjj == m + 2) {
        kase = 1;
      } else {
        kase = 2;
        ii = qjj;
      }
    }
    switch (kase) {
    case 1:
      rt = e[m];
      e[m] = 0.0;
      for (int k{qp1}; k >= ii + 1; k--) {
        blas::xrotg(&b_s[k - 1], &rt, &sm, &sqds);
        if (k > ii + 1) {
          rt = -sqds * e[0];
          e[0] *= sm;
        }
        blas::xrot(Vf, 3 * (k - 1) + 1, 3 * (m + 1) + 1, sm, sqds);
      }
      break;
    case 2: {
      rt = e[ii - 1];
      e[ii - 1] = 0.0;
      for (int k{ii + 1}; k <= m + 2; k++) {
        double b;
        blas::xrotg(&b_s[k - 1], &rt, &sm, &sqds);
        b = e[k - 1];
        rt = -sqds * b;
        e[k - 1] = b * sm;
        blas::b_xrot(U, ((k - 1) << 2) + 1, ((ii - 1) << 2) + 1, sm, sqds);
      }
    } break;
    case 3: {
      double b;
      double scale;
      nrm = b_s[m + 1];
      scale = std::fmax(
          std::fmax(std::fmax(std::fmax(std::abs(nrm), std::abs(b_s[m])),
                              std::abs(e[m])),
                    std::abs(b_s[ii])),
          std::abs(e[ii]));
      sm = nrm / scale;
      nrm = b_s[m] / scale;
      rt = e[m] / scale;
      sqds = b_s[ii] / scale;
      b = ((nrm + sm) * (nrm - sm) + rt * rt) / 2.0;
      nrm = sm * rt;
      nrm *= nrm;
      if ((b != 0.0) || (nrm != 0.0)) {
        rt = std::sqrt(b * b + nrm);
        if (b < 0.0) {
          rt = -rt;
        }
        rt = nrm / (b + rt);
      } else {
        rt = 0.0;
      }
      rt += (sqds + sm) * (sqds - sm);
      nrm = sqds * (e[ii] / scale);
      for (int k{ii + 1}; k <= qp1; k++) {
        blas::xrotg(&rt, &nrm, &sm, &sqds);
        if (k > ii + 1) {
          e[0] = rt;
        }
        nrm = e[k - 1];
        b = b_s[k - 1];
        e[k - 1] = sm * nrm - sqds * b;
        rt = sqds * b_s[k];
        b_s[k] *= sm;
        blas::xrot(Vf, 3 * (k - 1) + 1, 3 * k + 1, sm, sqds);
        b_s[k - 1] = sm * b + sqds * nrm;
        blas::xrotg(&b_s[k - 1], &rt, &sm, &sqds);
        rt = sm * e[k - 1] + sqds * b_s[k];
        b_s[k] = -sqds * e[k - 1] + sm * b_s[k];
        nrm = sqds * e[k];
        e[k] *= sm;
        blas::b_xrot(U, ((k - 1) << 2) + 1, (k << 2) + 1, sm, sqds);
      }
      e[m] = rt;
      iter++;
    } break;
    default:
      if (b_s[ii] < 0.0) {
        b_s[ii] = -b_s[ii];
        kase = 3 * ii;
        qjj = kase + 3;
        for (int k{kase + 1}; k <= qjj; k++) {
          Vf[k - 1] = -Vf[k - 1];
        }
      }
      qp1 = ii + 1;
      while ((ii + 1 < 3) && (b_s[ii] < b_s[qp1])) {
        rt = b_s[ii];
        b_s[ii] = b_s[qp1];
        b_s[qp1] = rt;
        blas::xswap(Vf, 3 * ii + 1, 3 * (ii + 1) + 1);
        blas::b_xswap(U, (ii << 2) + 1, ((ii + 1) << 2) + 1);
        ii = qp1;
        qp1++;
      }
      iter = 0;
      m--;
      break;
    }
  }
  for (int k{0}; k < 3; k++) {
    s[k] = b_s[k];
    V[3 * k] = Vf[3 * k];
    kase = 3 * k + 1;
    V[kase] = Vf[kase];
    kase = 3 * k + 2;
    V[kase] = Vf[kase];
  }
}

} // namespace internal
} // namespace coder

//
// File trailer for svd.cpp
//
// [EOF]
//
