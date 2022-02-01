//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: xzhgeqz.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 01-Feb-2022 18:48:34
//

// Include Files
#include "xzhgeqz.h"
#include "proc_planner_data.h"
#include "rt_nonfinite.h"
#include "sqrt.h"
#include "xzlartg.h"
#include "coder_array.h"
#include <cmath>
#include <string.h>

// Function Declarations
static int div_nzp_s32(int numerator);

// Function Definitions
//
// Arguments    : int numerator
// Return Type  : int
//
static int div_nzp_s32(int numerator)
{
  unsigned int b_numerator;
  int quotient;
  if (numerator < 0) {
    b_numerator = ~static_cast<unsigned int>(numerator) + 1U;
  } else {
    b_numerator = static_cast<unsigned int>(numerator);
  }
  b_numerator /= 10U;
  if (numerator < 0) {
    quotient = -static_cast<int>(b_numerator);
  } else {
    quotient = static_cast<int>(b_numerator);
  }
  return quotient;
}

//
// Arguments    : const ::coder::array<creal_T, 2U> &A
//                int ilo
//                int ihi
//                int *info
//                ::coder::array<creal_T, 1U> &alpha1
//                ::coder::array<creal_T, 1U> &beta1
// Return Type  : void
//
namespace coder {
namespace internal {
namespace reflapack {
void xzhgeqz(const ::coder::array<creal_T, 2U> &A, int ilo, int ihi, int *info,
             ::coder::array<creal_T, 1U> &alpha1,
             ::coder::array<creal_T, 1U> &beta1)
{
  array<creal_T, 2U> b_A;
  creal_T b_ascale;
  creal_T ctemp;
  creal_T shift;
  double anorm;
  double ascale;
  double b_atol;
  double bscale;
  double colscale;
  double colssq;
  double eshift_im;
  double eshift_re;
  double scale;
  double ssq;
  double t;
  int col;
  int ilast;
  int ilastm1;
  int j;
  int jp1;
  int n;
  int nm1;
  bool failed;
  bool guard1{false};
  bool guard2{false};
  b_A.set_size(A.size(0), A.size(1));
  jp1 = A.size(0) * A.size(1);
  for (ilastm1 = 0; ilastm1 < jp1; ilastm1++) {
    b_A[ilastm1] = A[ilastm1];
  }
  *info = 0;
  if ((A.size(0) == 1) && (A.size(1) == 1)) {
    ihi = 1;
  }
  n = A.size(0);
  alpha1.set_size(A.size(0));
  jp1 = A.size(0);
  for (ilastm1 = 0; ilastm1 < jp1; ilastm1++) {
    alpha1[ilastm1].re = 0.0;
    alpha1[ilastm1].im = 0.0;
  }
  beta1.set_size(A.size(0));
  jp1 = A.size(0);
  for (ilastm1 = 0; ilastm1 < jp1; ilastm1++) {
    beta1[ilastm1].re = 1.0;
    beta1[ilastm1].im = 0.0;
  }
  eshift_re = 0.0;
  eshift_im = 0.0;
  ctemp.re = 0.0;
  ctemp.im = 0.0;
  anorm = 0.0;
  if (ilo <= ihi) {
    scale = 3.3121686421112381E-170;
    ssq = 0.0;
    nm1 = ihi - ilo;
    for (j = 0; j <= nm1; j++) {
      colscale = 3.3121686421112381E-170;
      colssq = 0.0;
      col = (ilo + j) - 1;
      jp1 = j + 1;
      if (jp1 > nm1) {
        jp1 = nm1;
      }
      ilastm1 = ilo + jp1;
      for (jp1 = ilo; jp1 <= ilastm1; jp1++) {
        anorm = std::abs(A[(jp1 + A.size(0) * col) - 1].re);
        if (anorm > colscale) {
          t = colscale / anorm;
          colssq = colssq * t * t + 1.0;
          colscale = anorm;
        } else {
          t = anorm / colscale;
          colssq += t * t;
        }
        anorm = std::abs(A[(jp1 + A.size(0) * col) - 1].im);
        if (anorm > colscale) {
          t = colscale / anorm;
          colssq = colssq * t * t + 1.0;
          colscale = anorm;
        } else {
          t = anorm / colscale;
          colssq += t * t;
        }
      }
      if (scale >= colscale) {
        t = colscale / scale;
        ssq += t * t * colssq;
      } else {
        t = scale / colscale;
        ssq = colssq + t * t * ssq;
        scale = colscale;
      }
    }
    anorm = scale * std::sqrt(ssq);
  }
  t = 2.2204460492503131E-16 * anorm;
  b_atol = 2.2250738585072014E-308;
  if (t > 2.2250738585072014E-308) {
    b_atol = t;
  }
  t = 2.2250738585072014E-308;
  if (anorm > 2.2250738585072014E-308) {
    t = anorm;
  }
  ascale = 1.0 / t;
  bscale = 1.0 / std::sqrt(static_cast<double>(A.size(0)));
  failed = true;
  ilastm1 = ihi + 1;
  for (j = ilastm1; j <= n; j++) {
    alpha1[j - 1] = A[(j + A.size(0) * (j - 1)) - 1];
  }
  guard1 = false;
  guard2 = false;
  if (ihi >= ilo) {
    int iiter;
    int ilastm;
    int jiter;
    bool goto60;
    bool goto70;
    bool goto90;
    col = ilo;
    n = ilo;
    ilast = ihi - 1;
    ilastm1 = ihi - 2;
    ilastm = ihi;
    iiter = 0;
    goto60 = false;
    goto70 = false;
    goto90 = false;
    jiter = 0;
    int exitg1;
    do {
      exitg1 = 0;
      if (jiter <= 30 * ((ihi - ilo) + 1) - 1) {
        bool b_guard1{false};
        bool exitg2;
        b_guard1 = false;
        if (ilast + 1 == ilo) {
          goto60 = true;
          b_guard1 = true;
        } else if (std::abs(b_A[ilast + b_A.size(0) * ilastm1].re) +
                       std::abs(b_A[ilast + b_A.size(0) * ilastm1].im) <=
                   b_atol) {
          b_A[ilast + b_A.size(0) * ilastm1].re = 0.0;
          b_A[ilast + b_A.size(0) * ilastm1].im = 0.0;
          goto60 = true;
          b_guard1 = true;
        } else {
          bool guard3{false};
          j = ilastm1;
          guard3 = false;
          exitg2 = false;
          while ((!exitg2) && (j + 1 >= ilo)) {
            if (j + 1 == ilo) {
              guard3 = true;
              exitg2 = true;
            } else if (std::abs(b_A[j + b_A.size(0) * (j - 1)].re) +
                           std::abs(b_A[j + b_A.size(0) * (j - 1)].im) <=
                       b_atol) {
              b_A[j + b_A.size(0) * (j - 1)].re = 0.0;
              b_A[j + b_A.size(0) * (j - 1)].im = 0.0;
              guard3 = true;
              exitg2 = true;
            } else {
              j--;
              guard3 = false;
            }
          }
          if (guard3) {
            col = j + 1;
            goto70 = true;
          }
          if (goto70) {
            b_guard1 = true;
          } else {
            jp1 = alpha1.size(0);
            alpha1.set_size(jp1);
            for (ilastm1 = 0; ilastm1 < jp1; ilastm1++) {
              alpha1[ilastm1].re = rtNaN;
              alpha1[ilastm1].im = 0.0;
            }
            jp1 = beta1.size(0);
            beta1.set_size(jp1);
            for (ilastm1 = 0; ilastm1 < jp1; ilastm1++) {
              beta1[ilastm1].re = rtNaN;
              beta1[ilastm1].im = 0.0;
            }
            *info = 1;
            exitg1 = 1;
          }
        }
        if (b_guard1) {
          if (goto60) {
            goto60 = false;
            alpha1[ilast] = b_A[ilast + b_A.size(0) * ilast];
            ilast = ilastm1;
            ilastm1--;
            if (ilast + 1 < ilo) {
              failed = false;
              guard2 = true;
              exitg1 = 1;
            } else {
              iiter = 0;
              eshift_re = 0.0;
              eshift_im = 0.0;
              ilastm = ilast + 1;
              jiter++;
            }
          } else {
            if (goto70) {
              goto70 = false;
              iiter++;
              if (iiter - div_nzp_s32(iiter) * 10 != 0) {
                double stemp_im;
                double stemp_re;
                double t1_im;
                double t1_im_tmp;
                double t1_re;
                anorm = ascale * b_A[ilastm1 + b_A.size(0) * ilastm1].re;
                t = ascale * b_A[ilastm1 + b_A.size(0) * ilastm1].im;
                if (t == 0.0) {
                  shift.re = anorm / bscale;
                  shift.im = 0.0;
                } else if (anorm == 0.0) {
                  shift.re = 0.0;
                  shift.im = t / bscale;
                } else {
                  shift.re = anorm / bscale;
                  shift.im = t / bscale;
                }
                anorm = ascale * b_A[ilast + b_A.size(0) * ilast].re;
                t = ascale * b_A[ilast + b_A.size(0) * ilast].im;
                if (t == 0.0) {
                  stemp_re = anorm / bscale;
                  stemp_im = 0.0;
                } else if (anorm == 0.0) {
                  stemp_re = 0.0;
                  stemp_im = t / bscale;
                } else {
                  stemp_re = anorm / bscale;
                  stemp_im = t / bscale;
                }
                t1_re = 0.5 * (shift.re + stemp_re);
                t1_im = 0.5 * (shift.im + stemp_im);
                t1_im_tmp = t1_re * t1_im;
                anorm = ascale * b_A[ilastm1 + b_A.size(0) * ilast].re;
                t = ascale * b_A[ilastm1 + b_A.size(0) * ilast].im;
                if (t == 0.0) {
                  colscale = anorm / bscale;
                  colssq = 0.0;
                } else if (anorm == 0.0) {
                  colscale = 0.0;
                  colssq = t / bscale;
                } else {
                  colscale = anorm / bscale;
                  colssq = t / bscale;
                }
                anorm = ascale * b_A[ilast + b_A.size(0) * ilastm1].re;
                t = ascale * b_A[ilast + b_A.size(0) * ilastm1].im;
                if (t == 0.0) {
                  ssq = anorm / bscale;
                  anorm = 0.0;
                } else if (anorm == 0.0) {
                  ssq = 0.0;
                  anorm = t / bscale;
                } else {
                  ssq = anorm / bscale;
                  anorm = t / bscale;
                }
                t = shift.re * stemp_re - shift.im * stemp_im;
                scale = shift.re * stemp_im + shift.im * stemp_re;
                shift.re = ((t1_re * t1_re - t1_im * t1_im) +
                            (colscale * ssq - colssq * anorm)) -
                           t;
                shift.im = ((t1_im_tmp + t1_im_tmp) +
                            (colscale * anorm + colssq * ssq)) -
                           scale;
                scalar::b_sqrt(&shift);
                if ((t1_re - stemp_re) * shift.re +
                        (t1_im - stemp_im) * shift.im <=
                    0.0) {
                  shift.re += t1_re;
                  shift.im += t1_im;
                } else {
                  shift.re = t1_re - shift.re;
                  shift.im = t1_im - shift.im;
                }
              } else {
                anorm = ascale * b_A[ilast + b_A.size(0) * ilastm1].re;
                t = ascale * b_A[ilast + b_A.size(0) * ilastm1].im;
                if (t == 0.0) {
                  colscale = anorm / bscale;
                  colssq = 0.0;
                } else if (anorm == 0.0) {
                  colscale = 0.0;
                  colssq = t / bscale;
                } else {
                  colscale = anorm / bscale;
                  colssq = t / bscale;
                }
                eshift_re += colscale;
                eshift_im += colssq;
                shift.re = eshift_re;
                shift.im = eshift_im;
              }
              j = ilastm1;
              jp1 = ilastm1 + 1;
              exitg2 = false;
              while ((!exitg2) && (j + 1 > col)) {
                n = j + 1;
                ctemp.re =
                    ascale * b_A[j + b_A.size(0) * j].re - shift.re * bscale;
                ctemp.im =
                    ascale * b_A[j + b_A.size(0) * j].im - shift.im * bscale;
                anorm = std::abs(ctemp.re) + std::abs(ctemp.im);
                t = ascale * (std::abs(b_A[jp1 + b_A.size(0) * j].re) +
                              std::abs(b_A[jp1 + b_A.size(0) * j].im));
                scale = anorm;
                if (t > anorm) {
                  scale = t;
                }
                if ((scale < 1.0) && (scale != 0.0)) {
                  anorm /= scale;
                  t /= scale;
                }
                if ((std::abs(b_A[j + b_A.size(0) * (j - 1)].re) +
                     std::abs(b_A[j + b_A.size(0) * (j - 1)].im)) *
                        t <=
                    anorm * b_atol) {
                  goto90 = true;
                  exitg2 = true;
                } else {
                  jp1 = j;
                  j--;
                }
              }
              if (!goto90) {
                n = col;
                ctemp.re =
                    ascale * b_A[(col + b_A.size(0) * (col - 1)) - 1].re -
                    shift.re * bscale;
                ctemp.im =
                    ascale * b_A[(col + b_A.size(0) * (col - 1)) - 1].im -
                    shift.im * bscale;
              }
              goto90 = false;
              b_ascale.re = ascale * b_A[n + b_A.size(0) * (n - 1)].re;
              b_ascale.im = ascale * b_A[n + b_A.size(0) * (n - 1)].im;
              xzlartg(ctemp, b_ascale, &anorm, &shift);
              j = n;
              nm1 = n - 2;
              while (j < ilast + 1) {
                if (j > n) {
                  xzlartg(b_A[(j + b_A.size(0) * nm1) - 1],
                          b_A[j + b_A.size(0) * nm1], &anorm, &shift,
                          &b_A[(j + b_A.size(0) * nm1) - 1]);
                  b_A[j + b_A.size(0) * nm1].re = 0.0;
                  b_A[j + b_A.size(0) * nm1].im = 0.0;
                }
                for (nm1 = j; nm1 <= ilastm; nm1++) {
                  t = b_A[j + b_A.size(0) * (nm1 - 1)].im;
                  scale = b_A[j + b_A.size(0) * (nm1 - 1)].re;
                  ssq = b_A[(j + b_A.size(0) * (nm1 - 1)) - 1].re;
                  colscale = b_A[(j + b_A.size(0) * (nm1 - 1)) - 1].im;
                  b_A[j + b_A.size(0) * (nm1 - 1)].re =
                      anorm * scale - (shift.re * ssq + shift.im * colscale);
                  b_A[j + b_A.size(0) * (nm1 - 1)].im =
                      anorm * t - (shift.re * colscale - shift.im * ssq);
                  b_A[(j + b_A.size(0) * (nm1 - 1)) - 1].re =
                      anorm * ssq + (shift.re * scale - shift.im * t);
                  b_A[(j + b_A.size(0) * (nm1 - 1)) - 1].im =
                      anorm * colscale + (shift.re * t + shift.im * scale);
                }
                shift.re = -shift.re;
                shift.im = -shift.im;
                nm1 = j;
                if (ilast + 1 < j + 2) {
                  nm1 = ilast - 1;
                }
                for (jp1 = col; jp1 <= nm1 + 2; jp1++) {
                  t = b_A[(jp1 + b_A.size(0) * (j - 1)) - 1].im;
                  scale = b_A[(jp1 + b_A.size(0) * (j - 1)) - 1].re;
                  ssq = b_A[(jp1 + b_A.size(0) * j) - 1].re;
                  colscale = b_A[(jp1 + b_A.size(0) * j) - 1].im;
                  b_A[(jp1 + b_A.size(0) * (j - 1)) - 1].re =
                      anorm * scale - (shift.re * ssq + shift.im * colscale);
                  b_A[(jp1 + b_A.size(0) * (j - 1)) - 1].im =
                      anorm * t - (shift.re * colscale - shift.im * ssq);
                  b_A[(jp1 + b_A.size(0) * j) - 1].re =
                      anorm * ssq + (shift.re * scale - shift.im * t);
                  b_A[(jp1 + b_A.size(0) * j) - 1].im =
                      anorm * colscale + (shift.re * t + shift.im * scale);
                }
                nm1 = j - 1;
                j++;
              }
            }
            jiter++;
          }
        }
      } else {
        guard2 = true;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  } else {
    guard1 = true;
  }
  if (guard2) {
    if (failed) {
      *info = ilast + 1;
      for (jp1 = 0; jp1 <= ilast; jp1++) {
        alpha1[jp1].re = rtNaN;
        alpha1[jp1].im = 0.0;
        beta1[jp1].re = rtNaN;
        beta1[jp1].im = 0.0;
      }
    } else {
      guard1 = true;
    }
  }
  if (guard1) {
    for (j = 0; j <= ilo - 2; j++) {
      alpha1[j] = b_A[j + b_A.size(0) * j];
    }
  }
}

} // namespace reflapack
} // namespace internal
} // namespace coder

//
// File trailer for xzhgeqz.cpp
//
// [EOF]
//
