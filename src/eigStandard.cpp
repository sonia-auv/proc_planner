//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: eigStandard.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 05-Feb-2022 14:39:35
//

// Include Files
#include "eigStandard.h"
#include "proc_planner_data.h"
#include "proc_planner_rtwutil.h"
#include "rt_nonfinite.h"
#include "xzhgeqz.h"
#include "xzlartg.h"
#include "coder_array.h"
#include <cmath>
#include <string.h>

// Function Definitions
//
// Arguments    : const ::coder::array<double, 2U> &A
//                ::coder::array<creal_T, 1U> &V
// Return Type  : void
//
namespace coder {
void eigStandard(const ::coder::array<double, 2U> &A,
                 ::coder::array<creal_T, 1U> &V)
{
  array<creal_T, 2U> At;
  array<creal_T, 1U> beta1;
  creal_T atmp;
  double absxk;
  double anrm;
  double anrmto;
  double cfrom1;
  double cto1;
  double ctoc;
  double stemp_im_tmp;
  int ii;
  int nzcount;
  At.set_size(A.size(0), A.size(1));
  ii = A.size(0) * A.size(1);
  for (nzcount = 0; nzcount < ii; nzcount++) {
    At[nzcount].re = A[nzcount];
    At[nzcount].im = 0.0;
  }
  V.set_size(At.size(0));
  ii = At.size(0);
  for (nzcount = 0; nzcount < ii; nzcount++) {
    V[nzcount].re = 0.0;
    V[nzcount].im = 0.0;
  }
  beta1.set_size(At.size(0));
  ii = At.size(0);
  for (nzcount = 0; nzcount < ii; nzcount++) {
    beta1[nzcount].re = 0.0;
    beta1[nzcount].im = 0.0;
  }
  if ((At.size(0) != 0) && (At.size(1) != 0)) {
    bool exitg1;
    anrm = 0.0;
    ii = 0;
    exitg1 = false;
    while ((!exitg1) && (ii <= At.size(0) * At.size(1) - 1)) {
      absxk = rt_hypotd_snf(At[ii].re, At[ii].im);
      if (std::isnan(absxk)) {
        anrm = rtNaN;
        exitg1 = true;
      } else {
        if (absxk > anrm) {
          anrm = absxk;
        }
        ii++;
      }
    }
    if (std::isinf(anrm) || std::isnan(anrm)) {
      V.set_size(At.size(0));
      ii = At.size(0);
      for (nzcount = 0; nzcount < ii; nzcount++) {
        V[nzcount].re = rtNaN;
        V[nzcount].im = 0.0;
      }
      beta1.set_size(At.size(0));
      ii = At.size(0);
      for (nzcount = 0; nzcount < ii; nzcount++) {
        beta1[nzcount].re = rtNaN;
        beta1[nzcount].im = 0.0;
      }
    } else {
      int i;
      int ihi;
      int ilo;
      int j;
      int jrow;
      int n;
      bool guard1{false};
      bool ilascl;
      bool notdone;
      ilascl = false;
      anrmto = anrm;
      guard1 = false;
      if ((anrm > 0.0) && (anrm < 6.7178761075670888E-139)) {
        anrmto = 6.7178761075670888E-139;
        ilascl = true;
        guard1 = true;
      } else if (anrm > 1.4885657073574029E+138) {
        anrmto = 1.4885657073574029E+138;
        ilascl = true;
        guard1 = true;
      }
      if (guard1) {
        absxk = anrm;
        ctoc = anrmto;
        notdone = true;
        while (notdone) {
          cfrom1 = absxk * 2.0041683600089728E-292;
          cto1 = ctoc / 4.9896007738368E+291;
          if ((cfrom1 > ctoc) && (ctoc != 0.0)) {
            stemp_im_tmp = 2.0041683600089728E-292;
            absxk = cfrom1;
          } else if (cto1 > absxk) {
            stemp_im_tmp = 4.9896007738368E+291;
            ctoc = cto1;
          } else {
            stemp_im_tmp = ctoc / absxk;
            notdone = false;
          }
          ii = At.size(0) * At.size(1);
          for (nzcount = 0; nzcount < ii; nzcount++) {
            At[nzcount].re = stemp_im_tmp * At[nzcount].re;
            At[nzcount].im = stemp_im_tmp * At[nzcount].im;
          }
        }
      }
      ilo = 1;
      ihi = At.size(0);
      if (At.size(0) <= 1) {
        ihi = 1;
      } else {
        int exitg3;
        bool exitg4;
        do {
          exitg3 = 0;
          i = 0;
          j = 0;
          notdone = false;
          ii = ihi;
          exitg1 = false;
          while ((!exitg1) && (ii > 0)) {
            nzcount = 0;
            i = ii;
            j = ihi;
            jrow = 0;
            exitg4 = false;
            while ((!exitg4) && (jrow <= ihi - 1)) {
              if ((At[(ii + At.size(0) * jrow) - 1].re != 0.0) ||
                  (At[(ii + At.size(0) * jrow) - 1].im != 0.0) ||
                  (ii == jrow + 1)) {
                if (nzcount == 0) {
                  j = jrow + 1;
                  nzcount = 1;
                  jrow++;
                } else {
                  nzcount = 2;
                  exitg4 = true;
                }
              } else {
                jrow++;
              }
            }
            if (nzcount < 2) {
              notdone = true;
              exitg1 = true;
            } else {
              ii--;
            }
          }
          if (!notdone) {
            exitg3 = 2;
          } else {
            n = At.size(0);
            if (i != ihi) {
              for (ii = 1; ii <= n; ii++) {
                atmp = At[(i + At.size(0) * (ii - 1)) - 1];
                At[(i + At.size(0) * (ii - 1)) - 1] =
                    At[(ihi + At.size(0) * (ii - 1)) - 1];
                At[(ihi + At.size(0) * (ii - 1)) - 1] = atmp;
              }
            }
            if (j != ihi) {
              for (ii = 0; ii < ihi; ii++) {
                atmp = At[ii + At.size(0) * (j - 1)];
                At[ii + At.size(0) * (j - 1)] = At[ii + At.size(0) * (ihi - 1)];
                At[ii + At.size(0) * (ihi - 1)] = atmp;
              }
            }
            ihi--;
            if (ihi == 1) {
              exitg3 = 1;
            }
          }
        } while (exitg3 == 0);
        if (exitg3 != 1) {
          int exitg2;
          do {
            exitg2 = 0;
            i = 0;
            j = 0;
            notdone = false;
            jrow = ilo;
            exitg1 = false;
            while ((!exitg1) && (jrow <= ihi)) {
              nzcount = 0;
              i = ihi;
              j = jrow;
              ii = ilo;
              exitg4 = false;
              while ((!exitg4) && (ii <= ihi)) {
                if ((At[(ii + At.size(0) * (jrow - 1)) - 1].re != 0.0) ||
                    (At[(ii + At.size(0) * (jrow - 1)) - 1].im != 0.0) ||
                    (ii == jrow)) {
                  if (nzcount == 0) {
                    i = ii;
                    nzcount = 1;
                    ii++;
                  } else {
                    nzcount = 2;
                    exitg4 = true;
                  }
                } else {
                  ii++;
                }
              }
              if (nzcount < 2) {
                notdone = true;
                exitg1 = true;
              } else {
                jrow++;
              }
            }
            if (!notdone) {
              exitg2 = 1;
            } else {
              n = At.size(0);
              if (i != ilo) {
                for (ii = ilo; ii <= n; ii++) {
                  atmp = At[(i + At.size(0) * (ii - 1)) - 1];
                  At[(i + At.size(0) * (ii - 1)) - 1] =
                      At[(ilo + At.size(0) * (ii - 1)) - 1];
                  At[(ilo + At.size(0) * (ii - 1)) - 1] = atmp;
                }
              }
              if (j != ilo) {
                for (ii = 0; ii < ihi; ii++) {
                  atmp = At[ii + At.size(0) * (j - 1)];
                  At[ii + At.size(0) * (j - 1)] =
                      At[ii + At.size(0) * (ilo - 1)];
                  At[ii + At.size(0) * (ilo - 1)] = atmp;
                }
              }
              ilo++;
              if (ilo == ihi) {
                exitg2 = 1;
              }
            }
          } while (exitg2 == 0);
        }
      }
      n = At.size(0);
      if ((At.size(0) > 1) && (ihi >= ilo + 2)) {
        for (ii = ilo - 1; ii + 1 < ihi - 1; ii++) {
          nzcount = ii + 2;
          for (jrow = ihi - 1; jrow + 1 > ii + 2; jrow--) {
            internal::reflapack::xzlartg(
                At[(jrow + At.size(0) * ii) - 1], At[jrow + At.size(0) * ii],
                &absxk, &atmp, &At[(jrow + At.size(0) * ii) - 1]);
            At[jrow + At.size(0) * ii].re = 0.0;
            At[jrow + At.size(0) * ii].im = 0.0;
            for (j = nzcount; j <= n; j++) {
              ctoc = At[jrow + At.size(0) * (j - 1)].im;
              cfrom1 = At[jrow + At.size(0) * (j - 1)].re;
              cto1 = At[(jrow + At.size(0) * (j - 1)) - 1].re;
              stemp_im_tmp = At[(jrow + At.size(0) * (j - 1)) - 1].im;
              At[jrow + At.size(0) * (j - 1)].re =
                  absxk * cfrom1 - (atmp.re * cto1 + atmp.im * stemp_im_tmp);
              At[jrow + At.size(0) * (j - 1)].im =
                  absxk * ctoc - (atmp.re * stemp_im_tmp - atmp.im * cto1);
              At[(jrow + At.size(0) * (j - 1)) - 1].re =
                  absxk * cto1 + (atmp.re * cfrom1 - atmp.im * ctoc);
              At[(jrow + At.size(0) * (j - 1)) - 1].im =
                  absxk * stemp_im_tmp + (atmp.re * ctoc + atmp.im * cfrom1);
            }
            atmp.re = -atmp.re;
            atmp.im = -atmp.im;
            for (i = 1; i <= ihi; i++) {
              ctoc = At[(i + At.size(0) * (jrow - 1)) - 1].im;
              cfrom1 = At[(i + At.size(0) * (jrow - 1)) - 1].re;
              cto1 = At[(i + At.size(0) * jrow) - 1].re;
              stemp_im_tmp = At[(i + At.size(0) * jrow) - 1].im;
              At[(i + At.size(0) * (jrow - 1)) - 1].re =
                  absxk * cfrom1 - (atmp.re * cto1 + atmp.im * stemp_im_tmp);
              At[(i + At.size(0) * (jrow - 1)) - 1].im =
                  absxk * ctoc - (atmp.re * stemp_im_tmp - atmp.im * cto1);
              At[(i + At.size(0) * jrow) - 1].re =
                  absxk * cto1 + (atmp.re * cfrom1 - atmp.im * ctoc);
              At[(i + At.size(0) * jrow) - 1].im =
                  absxk * stemp_im_tmp + (atmp.re * ctoc + atmp.im * cfrom1);
            }
          }
        }
      }
      internal::reflapack::xzhgeqz(At, ilo, ihi, &ii, V, beta1);
      if ((ii == 0) && ilascl) {
        notdone = true;
        while (notdone) {
          cfrom1 = anrmto * 2.0041683600089728E-292;
          cto1 = anrm / 4.9896007738368E+291;
          if ((cfrom1 > anrm) && (anrm != 0.0)) {
            stemp_im_tmp = 2.0041683600089728E-292;
            anrmto = cfrom1;
          } else if (cto1 > anrmto) {
            stemp_im_tmp = 4.9896007738368E+291;
            anrm = cto1;
          } else {
            stemp_im_tmp = anrm / anrmto;
            notdone = false;
          }
          ii = V.size(0);
          for (nzcount = 0; nzcount < ii; nzcount++) {
            V[nzcount].re = stemp_im_tmp * V[nzcount].re;
            V[nzcount].im = stemp_im_tmp * V[nzcount].im;
          }
        }
      }
    }
  }
  ii = V.size(0);
  for (nzcount = 0; nzcount < ii; nzcount++) {
    double ai;
    anrm = V[nzcount].re;
    ai = V[nzcount].im;
    stemp_im_tmp = beta1[nzcount].re;
    cfrom1 = beta1[nzcount].im;
    if (cfrom1 == 0.0) {
      if (ai == 0.0) {
        anrmto = anrm / stemp_im_tmp;
        absxk = 0.0;
      } else if (anrm == 0.0) {
        anrmto = 0.0;
        absxk = ai / stemp_im_tmp;
      } else {
        anrmto = anrm / stemp_im_tmp;
        absxk = ai / stemp_im_tmp;
      }
    } else if (stemp_im_tmp == 0.0) {
      if (anrm == 0.0) {
        anrmto = ai / cfrom1;
        absxk = 0.0;
      } else if (ai == 0.0) {
        anrmto = 0.0;
        absxk = -(anrm / cfrom1);
      } else {
        anrmto = ai / cfrom1;
        absxk = -(anrm / cfrom1);
      }
    } else {
      cto1 = std::abs(stemp_im_tmp);
      absxk = std::abs(cfrom1);
      if (cto1 > absxk) {
        ctoc = cfrom1 / stemp_im_tmp;
        absxk = stemp_im_tmp + ctoc * cfrom1;
        anrmto = (anrm + ctoc * ai) / absxk;
        absxk = (ai - ctoc * anrm) / absxk;
      } else if (absxk == cto1) {
        if (stemp_im_tmp > 0.0) {
          ctoc = 0.5;
        } else {
          ctoc = -0.5;
        }
        if (cfrom1 > 0.0) {
          absxk = 0.5;
        } else {
          absxk = -0.5;
        }
        anrmto = (anrm * ctoc + ai * absxk) / cto1;
        absxk = (ai * ctoc - anrm * absxk) / cto1;
      } else {
        ctoc = stemp_im_tmp / cfrom1;
        absxk = cfrom1 + ctoc * stemp_im_tmp;
        anrmto = (ctoc * anrm + ai) / absxk;
        absxk = (ctoc * ai - anrm) / absxk;
      }
    }
    V[nzcount].re = anrmto;
    V[nzcount].im = absxk;
  }
}

} // namespace coder

//
// File trailer for eigStandard.cpp
//
// [EOF]
//
