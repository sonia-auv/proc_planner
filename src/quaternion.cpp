//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: quaternion.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 19-Feb-2022 14:46:56
//

// Include Files
#include "quaternion.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <cmath>
#include <string.h>

// Function Definitions
//
// Arguments    : void
// Return Type  : void
//
namespace coder {
void quaternion::init()
{
  a.set_size(1, 1);
  a[0] = 0.0;
  b.set_size(1, 1);
  b[0] = 0.0;
  c.set_size(1, 1);
  c[0] = 0.0;
  d.set_size(1, 1);
  d[0] = 0.0;
}

//
// Arguments    : ::coder::array<double, 3U> &r
// Return Type  : void
//
void quaternion::rotmat(::coder::array<double, 3U> &r)
{
  array<double, 3U> rmat;
  array<double, 2U> n;
  array<double, 1U> aasq;
  array<double, 1U> ab2;
  array<double, 1U> ac2;
  array<double, 1U> ad2;
  array<double, 1U> bbsq;
  array<double, 1U> bc2;
  array<double, 1U> bd2;
  array<double, 1U> ccsq;
  array<double, 1U> cd2;
  array<double, 1U> ddsq;
  double b_d;
  int k;
  int nx;
  n.set_size(1, a.size(1));
  nx = a.size(1);
  for (k = 0; k < nx; k++) {
    double d1;
    double d2;
    double d3;
    b_d = a[k];
    d1 = b[k];
    d2 = c[k];
    d3 = d[k];
    n[k] = ((b_d * b_d + d1 * d1) + d2 * d2) + d3 * d3;
  }
  nx = n.size(1);
  for (k = 0; k < nx; k++) {
    n[k] = std::sqrt(n[k]);
  }
  a.set_size(1, a.size(1));
  nx = a.size(1) - 1;
  for (k = 0; k <= nx; k++) {
    a[k] = a[k] / n[k];
  }
  b.set_size(1, b.size(1));
  nx = b.size(1) - 1;
  for (k = 0; k <= nx; k++) {
    b[k] = b[k] / n[k];
  }
  c.set_size(1, c.size(1));
  nx = c.size(1) - 1;
  for (k = 0; k <= nx; k++) {
    c[k] = c[k] / n[k];
  }
  d.set_size(1, d.size(1));
  nx = d.size(1) - 1;
  for (k = 0; k <= nx; k++) {
    d[k] = d[k] / n[k];
  }
  ab2.set_size(a.size(1));
  nx = a.size(1);
  for (k = 0; k < nx; k++) {
    ab2[k] = a[k] * b[k] * 2.0;
  }
  ac2.set_size(a.size(1));
  nx = a.size(1);
  for (k = 0; k < nx; k++) {
    ac2[k] = a[k] * c[k] * 2.0;
  }
  ad2.set_size(a.size(1));
  nx = a.size(1);
  for (k = 0; k < nx; k++) {
    ad2[k] = a[k] * d[k] * 2.0;
  }
  bc2.set_size(b.size(1));
  nx = b.size(1);
  for (k = 0; k < nx; k++) {
    bc2[k] = b[k] * c[k] * 2.0;
  }
  bd2.set_size(b.size(1));
  nx = b.size(1);
  for (k = 0; k < nx; k++) {
    bd2[k] = b[k] * d[k] * 2.0;
  }
  cd2.set_size(c.size(1));
  nx = c.size(1);
  for (k = 0; k < nx; k++) {
    cd2[k] = c[k] * d[k] * 2.0;
  }
  aasq.set_size(a.size(1));
  nx = a.size(1);
  for (k = 0; k < nx; k++) {
    b_d = a[k];
    aasq[k] = b_d * b_d * 2.0 - 1.0;
  }
  bbsq.set_size(b.size(1));
  nx = b.size(1);
  for (k = 0; k < nx; k++) {
    b_d = b[k];
    bbsq[k] = b_d * b_d * 2.0;
  }
  ccsq.set_size(c.size(1));
  nx = c.size(1);
  for (k = 0; k < nx; k++) {
    b_d = c[k];
    ccsq[k] = b_d * b_d * 2.0;
  }
  ddsq.set_size(d.size(1));
  nx = d.size(1);
  for (k = 0; k < nx; k++) {
    b_d = d[k];
    ddsq[k] = b_d * b_d * 2.0;
  }
  rmat.set_size(3, 3, a.size(1));
  nx = 9 * a.size(1);
  for (k = 0; k < nx; k++) {
    rmat[k] = 0.0;
  }
  k = a.size(1);
  for (nx = 0; nx < k; nx++) {
    rmat[9 * nx] = aasq[nx] + bbsq[nx];
    rmat[9 * nx + 3] = bc2[nx] + ad2[nx];
    rmat[9 * nx + 6] = bd2[nx] - ac2[nx];
    rmat[9 * nx + 1] = bc2[nx] - ad2[nx];
    rmat[9 * nx + 4] = aasq[nx] + ccsq[nx];
    rmat[9 * nx + 7] = cd2[nx] + ab2[nx];
    rmat[9 * nx + 2] = bd2[nx] + ac2[nx];
    rmat[9 * nx + 5] = cd2[nx] - ab2[nx];
    rmat[9 * nx + 8] = aasq[nx] + ddsq[nx];
  }
  nx = 1;
  if (rmat.size(2) != 1) {
    nx = rmat.size(2);
  }
  r.set_size(3, 3, nx);
  nx *= 9;
  for (k = 0; k < nx; k++) {
    r[k] = rmat[k];
  }
}

} // namespace coder

//
// File trailer for quaternion.cpp
//
// [EOF]
//
