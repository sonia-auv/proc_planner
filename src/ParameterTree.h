//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: ParameterTree.h
//
// MATLAB Coder version            : 5.4
// C/C++ source code generated on  : 10-Jul-2022 02:34:17
//

#ifndef PARAMETERTREE_H
#define PARAMETERTREE_H

// Include Files
#include "rtwtypes.h"
#include "coder_array.h"
#include "mlroscpp_param.h"
#include <cstddef>
#include <cstdlib>

// Type Definitions
namespace coder {
namespace ros {
class ParameterTree {
public:
  static void canonicalizeName(ParameterTree *obj,
                               ::coder::array<char, 2U> &validName);
  double get();
  static void b_canonicalizeName(ParameterTree *obj,
                                 ::coder::array<char, 2U> &validName);
  double b_get();
  static void c_canonicalizeName(ParameterTree *obj,
                                 ::coder::array<char, 2U> &validName);
  double c_get();
  static void d_canonicalizeName(ParameterTree *obj,
                                 ::coder::array<char, 2U> &validName);
  double d_get();
  static void e_canonicalizeName(ParameterTree *obj,
                                 ::coder::array<char, 2U> &validName);
  double e_get();
  static void f_canonicalizeName(ParameterTree *obj,
                                 ::coder::array<char, 2U> &validName);
  double f_get();
  static void g_canonicalizeName(ParameterTree *obj,
                                 ::coder::array<char, 2U> &validName);
  double g_get();
  static void h_canonicalizeName(ParameterTree *obj,
                                 ::coder::array<char, 2U> &validName);
  double h_get();
  static void i_canonicalizeName(ParameterTree *obj,
                                 ::coder::array<char, 2U> &validName);
  double i_get();
  static void j_canonicalizeName(ParameterTree *obj,
                                 ::coder::array<char, 2U> &validName);
  double j_get();
  static void k_canonicalizeName(ParameterTree *obj,
                                 ::coder::array<char, 2U> &validName);
  double k_get();
  MATLABROSParameter ParameterHelper;
};

} // namespace ros
} // namespace coder

#endif
//
// File trailer for ParameterTree.h
//
// [EOF]
//
