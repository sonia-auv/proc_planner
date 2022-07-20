//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// spline.cpp
//
// Code generation for function 'spline'
//

// Include files
#include "spline.h"
#include "rt_nonfinite.h"
#include "coder_array.h"

// Function Definitions
namespace coder {
void spline(const ::coder::array<double, 1U> &x,
            const ::coder::array<double, 2U> &y,
            ::coder::array<double, 2U> &output_breaks,
            ::coder::array<double, 2U> &output_coefs)
{
  array<double, 2U> dvdf;
  array<double, 2U> pp_coefs;
  array<double, 1U> dx;
  array<double, 1U> md;
  bool has_endslopes;
  has_endslopes = (y.size(1) == x.size(0) + 2);
  if ((x.size(0) <= 2) || ((x.size(0) <= 3) && (!has_endslopes))) {
    int szs_idx_1;
    has_endslopes = (y.size(1) == x.size(0) + 2);
    if (x.size(0) <= 2) {
      if (has_endslopes) {
        szs_idx_1 = 4;
      } else {
        szs_idx_1 = 2;
      }
    } else {
      szs_idx_1 = 3;
    }
    output_coefs.set_size(1, szs_idx_1);
    if (x.size(0) <= 2) {
      if (has_endslopes) {
        double pp1_coefs[4];
        double dnnm2;
        dnnm2 = y[0];
        if (x.size(0) - 2 >= 0) {
          double dzzdx;
          double r;
          double szdvdf_idx_1;
          r = x[1] - x[0];
          szdvdf_idx_1 = (y[2] - y[1]) / r;
          dzzdx = (szdvdf_idx_1 - dnnm2) / r;
          szdvdf_idx_1 = (y[y.size(1) - 1] - szdvdf_idx_1) / r;
          pp1_coefs[0] = (szdvdf_idx_1 - dzzdx) / r;
          pp1_coefs[1] = 2.0 * dzzdx - szdvdf_idx_1;
          pp1_coefs[2] = dnnm2;
          pp1_coefs[3] = y[1];
        }
        szs_idx_1 = output_coefs.size(1);
        output_coefs.set_size(1, szs_idx_1);
        for (int nxm1{0}; nxm1 < szs_idx_1; nxm1++) {
          output_coefs[nxm1] = pp1_coefs[nxm1];
        }
      } else {
        output_coefs[0] = (y[1] - y[0]) / (x[1] - x[0]);
        output_coefs[1] = y[0];
      }
      output_breaks.set_size(1, x.size(0));
      szs_idx_1 = x.size(0);
      for (int nxm1{0}; nxm1 < szs_idx_1; nxm1++) {
        output_breaks[nxm1] = x[nxm1];
      }
    } else {
      double dnnm2;
      double szdvdf_idx_1;
      szdvdf_idx_1 = x[1] - x[0];
      dnnm2 = (y[1] - y[0]) / szdvdf_idx_1;
      output_coefs[0] = ((y[2] - y[1]) / (x[2] - x[1]) - dnnm2) / (x[2] - x[0]);
      output_coefs[1] = dnnm2 - output_coefs[0] * szdvdf_idx_1;
      output_coefs[2] = y[0];
      output_breaks.set_size(1, 2);
      output_breaks[0] = x[0];
      output_breaks[1] = x[2];
    }
  } else {
    double dnnm2;
    double r;
    double szdvdf_idx_1;
    int nxm1;
    int szs_idx_1;
    int yoffset;
    nxm1 = x.size(0) - 1;
    if (has_endslopes) {
      szdvdf_idx_1 = static_cast<double>(y.size(1)) - 3.0;
      szs_idx_1 = y.size(1) - 2;
      yoffset = 1;
    } else {
      szdvdf_idx_1 = static_cast<double>(y.size(1)) - 1.0;
      szs_idx_1 = y.size(1);
      yoffset = 0;
    }
    output_coefs.set_size(1, szs_idx_1);
    dvdf.set_size(1, static_cast<int>(szdvdf_idx_1));
    dx.set_size(x.size(0) - 1);
    for (int k{0}; k < nxm1; k++) {
      szdvdf_idx_1 = x[k + 1] - x[k];
      dx[k] = szdvdf_idx_1;
      szs_idx_1 = yoffset + k;
      dvdf[k] = (y[szs_idx_1 + 1] - y[szs_idx_1]) / szdvdf_idx_1;
    }
    for (int k{2}; k <= nxm1; k++) {
      output_coefs[k - 1] =
          3.0 * (dx[k - 1] * dvdf[k - 2] + dx[k - 2] * dvdf[k - 1]);
    }
    if (has_endslopes) {
      szdvdf_idx_1 = 0.0;
      dnnm2 = 0.0;
      output_coefs[0] = y[0] * dx[1];
      output_coefs[x.size(0) - 1] = dx[x.size(0) - 3] * y[x.size(0) + 1];
    } else {
      szdvdf_idx_1 = x[2] - x[0];
      dnnm2 = x[x.size(0) - 1] - x[x.size(0) - 3];
      output_coefs[0] = ((dx[0] + 2.0 * szdvdf_idx_1) * dx[1] * dvdf[0] +
                         dx[0] * dx[0] * dvdf[1]) /
                        szdvdf_idx_1;
      output_coefs[x.size(0) - 1] =
          ((dx[x.size(0) - 2] + 2.0 * dnnm2) * dx[x.size(0) - 3] *
               dvdf[x.size(0) - 2] +
           dx[x.size(0) - 2] * dx[x.size(0) - 2] * dvdf[x.size(0) - 3]) /
          dnnm2;
    }
    md.set_size(x.size(0));
    md[0] = dx[1];
    md[x.size(0) - 1] = dx[x.size(0) - 3];
    for (int k{2}; k <= nxm1; k++) {
      md[k - 1] = 2.0 * (dx[k - 1] + dx[k - 2]);
    }
    r = dx[1] / md[0];
    md[1] = md[1] - r * szdvdf_idx_1;
    output_coefs[1] = output_coefs[1] - r * output_coefs[0];
    for (int k{3}; k <= nxm1; k++) {
      r = dx[k - 1] / md[k - 2];
      md[k - 1] = md[k - 1] - r * dx[k - 3];
      output_coefs[k - 1] = output_coefs[k - 1] - r * output_coefs[k - 2];
    }
    r = dnnm2 / md[x.size(0) - 2];
    md[x.size(0) - 1] = md[x.size(0) - 1] - r * dx[x.size(0) - 3];
    output_coefs[x.size(0) - 1] =
        output_coefs[x.size(0) - 1] - r * output_coefs[x.size(0) - 2];
    output_coefs[x.size(0) - 1] =
        output_coefs[x.size(0) - 1] / md[x.size(0) - 1];
    for (int k{nxm1}; k >= 2; k--) {
      output_coefs[k - 1] =
          (output_coefs[k - 1] - dx[k - 2] * output_coefs[k]) / md[k - 1];
    }
    output_coefs[0] =
        (output_coefs[0] - szdvdf_idx_1 * output_coefs[1]) / md[0];
    nxm1 = x.size(0);
    szs_idx_1 = output_coefs.size(1) - 1;
    pp_coefs.set_size(output_coefs.size(1) - 1, 4);
    for (int k{0}; k <= nxm1 - 2; k++) {
      double dzzdx;
      szdvdf_idx_1 = dvdf[k];
      dzzdx = (szdvdf_idx_1 - output_coefs[k]) / dx[k];
      szdvdf_idx_1 = (output_coefs[k + 1] - szdvdf_idx_1) / dx[k];
      pp_coefs[k] = (szdvdf_idx_1 - dzzdx) / dx[k];
      pp_coefs[szs_idx_1 + k] = 2.0 * dzzdx - szdvdf_idx_1;
      pp_coefs[(szs_idx_1 << 1) + k] = output_coefs[k];
      pp_coefs[3 * szs_idx_1 + k] = y[yoffset + k];
    }
    output_breaks.set_size(1, x.size(0));
    szs_idx_1 = x.size(0);
    for (nxm1 = 0; nxm1 < szs_idx_1; nxm1++) {
      output_breaks[nxm1] = x[nxm1];
    }
    output_coefs.set_size(pp_coefs.size(0), 4);
    szs_idx_1 = pp_coefs.size(0) * 4;
    for (nxm1 = 0; nxm1 < szs_idx_1; nxm1++) {
      output_coefs[nxm1] = pp_coefs[nxm1];
    }
  }
}

} // namespace coder

// End of code generation (spline.cpp)
