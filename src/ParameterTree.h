//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: ParameterTree.h
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 19-Feb-2022 14:46:56
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
  static void b_canonicalizeName(ParameterTree *obj,
                                 ::coder::array<char, 2U> &validName);
  static void c_canonicalizeName(ParameterTree *obj,
                                 ::coder::array<char, 2U> &validName);
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
