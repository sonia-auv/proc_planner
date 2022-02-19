//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: ParameterTree.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 19-Feb-2022 14:46:56
//

// Include Files
#include "ParameterTree.h"
#include "rt_nonfinite.h"
#include "startsWith.h"
#include "coder_array.h"
#include "mlroscpp_param.h"
#include <string.h>

// Function Definitions
//
// Arguments    : ParameterTree *obj
//                ::coder::array<char, 2U> &validName
// Return Type  : void
//
namespace coder {
namespace ros {
void ParameterTree::b_canonicalizeName(ParameterTree *obj,
                                       ::coder::array<char, 2U> &validName)
{
  static const char b_name[30]{'/', 'p', 'r', 'o', 'c', '_', 'p', 'l',
                               'a', 'n', 'n', 'e', 'r', '/', 'm', 'a',
                               'x', 'i', 'm', 'u', 'm', '_', 'v', 'e',
                               'l', 'o', 'c', 'i', 't', 'y'};
  array<char, 2U> r;
  int i;
  char name[30];
  for (i = 0; i < 30; i++) {
    name[i] = b_name[i];
  }
  std::mem_fn (&MATLABROSParameter::isValidPattern)(&obj->ParameterHelper,
                                                    &name[0]);
  validName.set_size(1, 30);
  for (i = 0; i < 30; i++) {
    validName[i] = b_name[i];
  }
  if (startsWith(validName)) {
    r.set_size(1, 29);
    r[0] = '~';
    for (i = 0; i < 28; i++) {
      r[i + 1] = validName[i + 2];
    }
    validName.set_size(1, 29);
    for (i = 0; i < 29; i++) {
      validName[i] = r[i];
    }
  }
}

//
// Arguments    : ParameterTree *obj
//                ::coder::array<char, 2U> &validName
// Return Type  : void
//
void ParameterTree::c_canonicalizeName(ParameterTree *obj,
                                       ::coder::array<char, 2U> &validName)
{
  static const char b_name[34]{'/', 'p', 'r', 'o', 'c', '_', 'p', 'l', 'a',
                               'n', 'n', 'e', 'r', '/', 'm', 'a', 'x', 'i',
                               'm', 'u', 'm', '_', 'a', 'n', 'g', 'u', 'l',
                               'a', 'r', '_', 'r', 'a', 't', 'e'};
  array<char, 2U> r;
  int i;
  char name[34];
  for (i = 0; i < 34; i++) {
    name[i] = b_name[i];
  }
  std::mem_fn (&MATLABROSParameter::isValidPattern)(&obj->ParameterHelper,
                                                    &name[0]);
  validName.set_size(1, 34);
  for (i = 0; i < 34; i++) {
    validName[i] = b_name[i];
  }
  if (startsWith(validName)) {
    r.set_size(1, 33);
    r[0] = '~';
    for (i = 0; i < 32; i++) {
      r[i + 1] = validName[i + 2];
    }
    validName.set_size(1, 33);
    for (i = 0; i < 33; i++) {
      validName[i] = r[i];
    }
  }
}

//
// Arguments    : ParameterTree *obj
//                ::coder::array<char, 2U> &validName
// Return Type  : void
//
void ParameterTree::canonicalizeName(ParameterTree *obj,
                                     ::coder::array<char, 2U> &validName)
{
  static const char b_name[34]{'/', 'p', 'r', 'o', 'c', '_', 'p', 'l', 'a',
                               'n', 'n', 'e', 'r', '/', 'm', 'a', 'x', 'i',
                               'm', 'u', 'm', '_', 'a', 'c', 'c', 'e', 'l',
                               'e', 'r', 'a', 't', 'i', 'o', 'n'};
  array<char, 2U> r;
  int i;
  char name[34];
  for (i = 0; i < 34; i++) {
    name[i] = b_name[i];
  }
  std::mem_fn (&MATLABROSParameter::isValidPattern)(&obj->ParameterHelper,
                                                    &name[0]);
  validName.set_size(1, 34);
  for (i = 0; i < 34; i++) {
    validName[i] = b_name[i];
  }
  if (startsWith(validName)) {
    r.set_size(1, 33);
    r[0] = '~';
    for (i = 0; i < 32; i++) {
      r[i + 1] = validName[i + 2];
    }
    validName.set_size(1, 33);
    for (i = 0; i < 33; i++) {
      validName[i] = r[i];
    }
  }
}

} // namespace ros
} // namespace coder

//
// File trailer for ParameterTree.cpp
//
// [EOF]
//
