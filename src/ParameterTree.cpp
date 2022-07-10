//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: ParameterTree.cpp
//
// MATLAB Coder version            : 5.4
// C/C++ source code generated on  : 25-Jun-2022 15:23:16
//

// Include Files
#include "ParameterTree.h"
#include "rt_nonfinite.h"
#include "startsWith.h"
#include "coder_array.h"
#include "mlroscpp_param.h"

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
  static const char b_name[45]{'/', 'p', 'r', 'o', 'c', '_', 'p', 'l', 'a',
                               'n', 'n', 'e', 'r', '/', 'h', 'i', 'g', 'h',
                               '_', 's', 'p', 'e', 'e', 'd', '/', 'm', 'a',
                               'x', 'i', 'm', 'u', 'm', '_', 'a', 'c', 'c',
                               'e', 'l', 'e', 'r', 'a', 't', 'i', 'o', 'n'};
  array<char, 2U> r;
  char name[45];
  for (int i{0}; i < 45; i++) {
    name[i] = b_name[i];
  }
  std::mem_fn (&MATLABROSParameter::isValidPattern)(&obj->ParameterHelper,
                                                    &name[0]);
  validName.set_size(1, 45);
  for (int i{0}; i < 45; i++) {
    validName[i] = b_name[i];
  }
  if (startsWith(validName)) {
    r.set_size(1, 44);
    r[0] = '~';
    for (int i{0}; i < 43; i++) {
      r[i + 1] = validName[i + 2];
    }
    validName.set_size(1, 44);
    for (int i{0}; i < 44; i++) {
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
  static const char b_name[41]{
      '/', 'p', 'r', 'o', 'c', '_', 'p', 'l', 'a', 'n', 'n', 'e', 'r', '/',
      'h', 'i', 'g', 'h', '_', 's', 'p', 'e', 'e', 'd', '/', 'm', 'a', 'x',
      'i', 'm', 'u', 'm', '_', 'v', 'e', 'l', 'o', 'c', 'i', 't', 'y'};
  array<char, 2U> r;
  char name[41];
  for (int i{0}; i < 41; i++) {
    name[i] = b_name[i];
  }
  std::mem_fn (&MATLABROSParameter::isValidPattern)(&obj->ParameterHelper,
                                                    &name[0]);
  validName.set_size(1, 41);
  for (int i{0}; i < 41; i++) {
    validName[i] = b_name[i];
  }
  if (startsWith(validName)) {
    r.set_size(1, 40);
    r[0] = '~';
    for (int i{0}; i < 39; i++) {
      r[i + 1] = validName[i + 2];
    }
    validName.set_size(1, 40);
    for (int i{0}; i < 40; i++) {
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
  static const char b_name[47]{'/', 'p', 'r', 'o', 'c', '_', 'p', 'l', 'a', 'n',
                               'n', 'e', 'r', '/', 'n', 'o', 'r', 'm', 'a', 'l',
                               '_', 's', 'p', 'e', 'e', 'd', '/', 'm', 'a', 'x',
                               'i', 'm', 'u', 'm', '_', 'a', 'n', 'g', 'u', 'l',
                               'a', 'r', '_', 'r', 'a', 't', 'e'};
  array<char, 2U> r;
  char name[47];
  for (int i{0}; i < 47; i++) {
    name[i] = b_name[i];
  }
  std::mem_fn (&MATLABROSParameter::isValidPattern)(&obj->ParameterHelper,
                                                    &name[0]);
  validName.set_size(1, 47);
  for (int i{0}; i < 47; i++) {
    validName[i] = b_name[i];
  }
  if (startsWith(validName)) {
    r.set_size(1, 46);
    r[0] = '~';
    for (int i{0}; i < 45; i++) {
      r[i + 1] = validName[i + 2];
    }
    validName.set_size(1, 46);
    for (int i{0}; i < 46; i++) {
      validName[i] = r[i];
    }
  }
}

//
// Arguments    : ParameterTree *obj
//                ::coder::array<char, 2U> &validName
// Return Type  : void
//
void ParameterTree::d_canonicalizeName(ParameterTree *obj,
                                       ::coder::array<char, 2U> &validName)
{
  static const char b_name[45]{'/', 'p', 'r', 'o', 'c', '_', 'p', 'l', 'a',
                               'n', 'n', 'e', 'r', '/', 'h', 'i', 'g', 'h',
                               '_', 's', 'p', 'e', 'e', 'd', '/', 'm', 'a',
                               'x', 'i', 'm', 'u', 'm', '_', 'a', 'n', 'g',
                               'u', 'l', 'a', 'r', '_', 'r', 'a', 't', 'e'};
  array<char, 2U> r;
  char name[45];
  for (int i{0}; i < 45; i++) {
    name[i] = b_name[i];
  }
  std::mem_fn (&MATLABROSParameter::isValidPattern)(&obj->ParameterHelper,
                                                    &name[0]);
  validName.set_size(1, 45);
  for (int i{0}; i < 45; i++) {
    validName[i] = b_name[i];
  }
  if (startsWith(validName)) {
    r.set_size(1, 44);
    r[0] = '~';
    for (int i{0}; i < 43; i++) {
      r[i + 1] = validName[i + 2];
    }
    validName.set_size(1, 44);
    for (int i{0}; i < 44; i++) {
      validName[i] = r[i];
    }
  }
}

//
// Arguments    : ParameterTree *obj
//                ::coder::array<char, 2U> &validName
// Return Type  : void
//
void ParameterTree::e_canonicalizeName(ParameterTree *obj,
                                       ::coder::array<char, 2U> &validName)
{
  static const char b_name[23]{'/', 'p', 'r', 'o', 'c', '_', 'p', 'l',
                               'a', 'n', 'n', 'e', 'r', '/', 'm', 'a',
                               'x', '_', 'd', 'e', 'p', 't', 'h'};
  array<char, 2U> r;
  char name[23];
  for (int i{0}; i < 23; i++) {
    name[i] = b_name[i];
  }
  std::mem_fn (&MATLABROSParameter::isValidPattern)(&obj->ParameterHelper,
                                                    &name[0]);
  validName.set_size(1, 23);
  for (int i{0}; i < 23; i++) {
    validName[i] = b_name[i];
  }
  if (startsWith(validName)) {
    r.set_size(1, 22);
    r[0] = '~';
    for (int i{0}; i < 21; i++) {
      r[i + 1] = validName[i + 2];
    }
    validName.set_size(1, 22);
    for (int i{0}; i < 22; i++) {
      validName[i] = r[i];
    }
  }
}

//
// Arguments    : ParameterTree *obj
//                ::coder::array<char, 2U> &validName
// Return Type  : void
//
void ParameterTree::f_canonicalizeName(ParameterTree *obj,
                                       ::coder::array<char, 2U> &validName)
{
  static const char b_name[29]{'/', 'p', 'r', 'o', 'c', '_', 'p', 'l', 'a', 'n',
                               'n', 'e', 'r', '/', 's', 'u', 'r', 'f', 'a', 'c',
                               'e', '_', 'w', 'a', 'r', 'n', 'i', 'n', 'g'};
  array<char, 2U> r;
  char name[29];
  for (int i{0}; i < 29; i++) {
    name[i] = b_name[i];
  }
  std::mem_fn (&MATLABROSParameter::isValidPattern)(&obj->ParameterHelper,
                                                    &name[0]);
  validName.set_size(1, 29);
  for (int i{0}; i < 29; i++) {
    validName[i] = b_name[i];
  }
  if (startsWith(validName)) {
    r.set_size(1, 28);
    r[0] = '~';
    for (int i{0}; i < 27; i++) {
      r[i + 1] = validName[i + 2];
    }
    validName.set_size(1, 28);
    for (int i{0}; i < 28; i++) {
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
