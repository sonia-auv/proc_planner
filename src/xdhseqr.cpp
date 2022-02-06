//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: xdhseqr.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 05-Feb-2022 14:39:35
//

// Include Files
#include "xdhseqr.h"
#include "rt_nonfinite.h"
#include "xdlanv2.h"
#include "xzlarfg.h"
#include "coder_array.h"
#include <cmath>
#include <string.h>

// Function Definitions
//
// Arguments    : ::coder::array<double, 2U> &h
// Return Type  : int
//
namespace coder {
namespace internal {
namespace reflapack {
int eml_dlahqr(::coder::array<double, 2U> &h)
{
  double v[3];
  double aa;
  double ab;
  double ba;
  double bb;
  double d;
  double rt1r;
  double rt2r;
  double s;
  double tst;
  int info;
  int ldh;
  int n;
  n = h.size(0);
  ldh = h.size(0);
  info = 0;
  if ((n != 0) && (1 != n)) {
    double SMLNUM;
    double itmax;
    int i;
    int j;
    bool exitg1;
    v[0] = 0.0;
    v[1] = 0.0;
    v[2] = 0.0;
    for (j = 0; j <= n - 4; j++) {
      h[(j + h.size(0) * j) + 2] = 0.0;
      h[(j + h.size(0) * j) + 3] = 0.0;
    }
    if (1 <= n - 2) {
      h[(n + h.size(0) * (n - 3)) - 1] = 0.0;
    }
    itmax = 30.0 * std::fmax(10.0, static_cast<double>(n));
    SMLNUM = 2.2250738585072014E-308 *
             (static_cast<double>(n) / 2.2204460492503131E-16);
    i = n - 1;
    exitg1 = false;
    while ((!exitg1) && (i + 1 >= 1)) {
      int L;
      int hoffset;
      int iy;
      int k;
      int m;
      int nr;
      bool exitg2;
      bool goto150;
      L = 1;
      goto150 = false;
      iy = 0;
      exitg2 = false;
      while ((!exitg2) && (iy <= static_cast<int>(itmax))) {
        bool exitg3;
        k = i;
        exitg3 = false;
        while ((!exitg3) && (k + 1 > L)) {
          ba = std::abs(h[k + h.size(0) * (k - 1)]);
          if (ba <= SMLNUM) {
            exitg3 = true;
          } else {
            bb = std::abs(h[k + h.size(0) * k]);
            tst = std::abs(h[(k + h.size(0) * (k - 1)) - 1]) + bb;
            if (tst == 0.0) {
              if (k - 1 >= 1) {
                tst = std::abs(h[(k + h.size(0) * (k - 2)) - 1]);
              }
              if (k + 2 <= n) {
                tst += std::abs(h[(k + h.size(0) * k) + 1]);
              }
            }
            if (ba <= 2.2204460492503131E-16 * tst) {
              tst = std::abs(h[(k + h.size(0) * k) - 1]);
              if (ba > tst) {
                ab = ba;
                ba = tst;
              } else {
                ab = tst;
              }
              tst = std::abs(h[(k + h.size(0) * (k - 1)) - 1] -
                             h[k + h.size(0) * k]);
              if (bb > tst) {
                aa = bb;
                bb = tst;
              } else {
                aa = tst;
              }
              s = aa + ab;
              if (ba * (ab / s) <=
                  std::fmax(SMLNUM, 2.2204460492503131E-16 * (bb * (aa / s)))) {
                exitg3 = true;
              } else {
                k--;
              }
            } else {
              k--;
            }
          }
        }
        L = k + 1;
        if (k + 1 > 1) {
          h[k + h.size(0) * (k - 1)] = 0.0;
        }
        if (k + 1 >= i) {
          goto150 = true;
          exitg2 = true;
        } else {
          if (iy == 10) {
            s = std::abs(h[(k + h.size(0) * k) + 1]) +
                std::abs(h[(k + h.size(0) * (k + 1)) + 2]);
            tst = 0.75 * s + h[k + h.size(0) * k];
            aa = -0.4375 * s;
            ab = s;
            bb = tst;
          } else if (iy == 20) {
            s = std::abs(h[i + h.size(0) * (i - 1)]) +
                std::abs(h[(i + h.size(0) * (i - 2)) - 1]);
            tst = 0.75 * s + h[i + h.size(0) * i];
            aa = -0.4375 * s;
            ab = s;
            bb = tst;
          } else {
            tst = h[(i + h.size(0) * (i - 1)) - 1];
            ab = h[i + h.size(0) * (i - 1)];
            aa = h[(i + h.size(0) * i) - 1];
            bb = h[i + h.size(0) * i];
          }
          s = ((std::abs(tst) + std::abs(aa)) + std::abs(ab)) + std::abs(bb);
          if (s == 0.0) {
            rt1r = 0.0;
            ab = 0.0;
            rt2r = 0.0;
            aa = 0.0;
          } else {
            tst /= s;
            ab /= s;
            aa /= s;
            bb /= s;
            ba = (tst + bb) / 2.0;
            tst = (tst - ba) * (bb - ba) - aa * ab;
            ab = std::sqrt(std::abs(tst));
            if (tst >= 0.0) {
              rt1r = ba * s;
              rt2r = rt1r;
              ab *= s;
              aa = -ab;
            } else {
              rt1r = ba + ab;
              rt2r = ba - ab;
              if (std::abs(rt1r - bb) <= std::abs(rt2r - bb)) {
                rt1r *= s;
                rt2r = rt1r;
              } else {
                rt2r *= s;
                rt1r = rt2r;
              }
              ab = 0.0;
              aa = 0.0;
            }
          }
          m = i - 1;
          exitg3 = false;
          while ((!exitg3) && (m >= k + 1)) {
            tst = h[m + h.size(0) * (m - 1)];
            ba = h[(m + h.size(0) * (m - 1)) - 1];
            bb = ba - rt2r;
            s = (std::abs(bb) + std::abs(aa)) + std::abs(tst);
            tst /= s;
            v[0] = (tst * h[(m + h.size(0) * m) - 1] + (ba - rt1r) * (bb / s)) -
                   ab * (aa / s);
            v[1] = tst * (((ba + h[m + h.size(0) * m]) - rt1r) - rt2r);
            v[2] = tst * h[(m + h.size(0) * m) + 1];
            s = (std::abs(v[0]) + std::abs(v[1])) + std::abs(v[2]);
            v[0] /= s;
            v[1] /= s;
            v[2] /= s;
            if ((m == k + 1) ||
                (std::abs(h[(m + h.size(0) * (m - 2)) - 1]) *
                     (std::abs(v[1]) + std::abs(v[2])) <=
                 2.2204460492503131E-16 * std::abs(v[0]) *
                     ((std::abs(h[(m + h.size(0) * (m - 2)) - 2]) +
                       std::abs(ba)) +
                      std::abs(h[m + h.size(0) * m])))) {
              exitg3 = true;
            } else {
              m--;
            }
          }
          for (int b_k{m}; b_k <= i; b_k++) {
            nr = (i - b_k) + 2;
            if (3 <= nr) {
              nr = 3;
            }
            if (b_k > m) {
              hoffset = (b_k + ldh * (b_k - 2)) - 1;
              for (j = 0; j < nr; j++) {
                v[j] = h[j + hoffset];
              }
            }
            tst = v[0];
            ba = xzlarfg(nr, &tst, v);
            v[0] = tst;
            if (b_k > m) {
              h[(b_k + h.size(0) * (b_k - 2)) - 1] = tst;
              h[b_k + h.size(0) * (b_k - 2)] = 0.0;
              if (b_k < i) {
                h[(b_k + h.size(0) * (b_k - 2)) + 1] = 0.0;
              }
            } else if (m > k + 1) {
              h[(b_k + h.size(0) * (b_k - 2)) - 1] =
                  h[(b_k + h.size(0) * (b_k - 2)) - 1] * (1.0 - ba);
            }
            d = v[1];
            ab = ba * v[1];
            if (nr == 3) {
              s = v[2];
              tst = ba * v[2];
              for (j = b_k; j <= n; j++) {
                aa = (h[(b_k + h.size(0) * (j - 1)) - 1] +
                      d * h[b_k + h.size(0) * (j - 1)]) +
                     s * h[(b_k + h.size(0) * (j - 1)) + 1];
                h[(b_k + h.size(0) * (j - 1)) - 1] =
                    h[(b_k + h.size(0) * (j - 1)) - 1] - aa * ba;
                h[b_k + h.size(0) * (j - 1)] =
                    h[b_k + h.size(0) * (j - 1)] - aa * ab;
                h[(b_k + h.size(0) * (j - 1)) + 1] =
                    h[(b_k + h.size(0) * (j - 1)) + 1] - aa * tst;
              }
              if (b_k + 3 <= i + 1) {
                nr = b_k + 2;
              } else {
                nr = i;
              }
              for (j = 0; j <= nr; j++) {
                aa = (h[j + h.size(0) * (b_k - 1)] +
                      d * h[j + h.size(0) * b_k]) +
                     s * h[j + h.size(0) * (b_k + 1)];
                h[j + h.size(0) * (b_k - 1)] =
                    h[j + h.size(0) * (b_k - 1)] - aa * ba;
                h[j + h.size(0) * b_k] = h[j + h.size(0) * b_k] - aa * ab;
                h[j + h.size(0) * (b_k + 1)] =
                    h[j + h.size(0) * (b_k + 1)] - aa * tst;
              }
            } else if (nr == 2) {
              for (j = b_k; j <= n; j++) {
                tst = h[(b_k + h.size(0) * (j - 1)) - 1];
                aa = tst + d * h[b_k + h.size(0) * (j - 1)];
                h[(b_k + h.size(0) * (j - 1)) - 1] = tst - aa * ba;
                h[b_k + h.size(0) * (j - 1)] =
                    h[b_k + h.size(0) * (j - 1)] - aa * ab;
              }
              for (j = 0; j <= i; j++) {
                aa = h[j + h.size(0) * (b_k - 1)] + d * h[j + h.size(0) * b_k];
                h[j + h.size(0) * (b_k - 1)] =
                    h[j + h.size(0) * (b_k - 1)] - aa * ba;
                h[j + h.size(0) * b_k] = h[j + h.size(0) * b_k] - aa * ab;
              }
            }
          }
          iy++;
        }
      }
      if (!goto150) {
        info = i + 1;
        exitg1 = true;
      } else {
        if ((L != i + 1) && (L == i)) {
          d = h[(i + h.size(0) * i) - 1];
          s = h[i + h.size(0) * (i - 1)];
          tst = h[i + h.size(0) * i];
          xdlanv2(&h[(i + h.size(0) * (i - 1)) - 1], &d, &s, &tst, &ab, &aa,
                  &ba, &bb, &rt2r, &rt1r);
          h[(i + h.size(0) * i) - 1] = d;
          h[i + h.size(0) * (i - 1)] = s;
          h[i + h.size(0) * i] = tst;
          if (n > i + 1) {
            hoffset = (n - i) - 2;
            if (hoffset + 1 >= 1) {
              iy = i + (i + 1) * ldh;
              for (k = 0; k <= hoffset; k++) {
                nr = iy + k * ldh;
                m = nr - 1;
                tst = rt2r * h[m] + rt1r * h[nr];
                h[nr] = rt2r * h[nr] - rt1r * h[m];
                h[m] = tst;
              }
            }
          }
          if (i - 1 >= 1) {
            hoffset = (i - 1) * ldh;
            iy = i * ldh;
            for (k = 0; k <= i - 2; k++) {
              m = iy + k;
              nr = hoffset + k;
              tst = rt2r * h[nr] + rt1r * h[m];
              h[m] = rt2r * h[m] - rt1r * h[nr];
              h[nr] = tst;
            }
          }
        }
        i = L - 2;
      }
    }
  }
  return info;
}

} // namespace reflapack
} // namespace internal
} // namespace coder

//
// File trailer for xdhseqr.cpp
//
// [EOF]
//
