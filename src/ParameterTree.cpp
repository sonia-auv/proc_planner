//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: ParameterTree.cpp
//
// MATLAB Coder version            : 5.4
// C/C++ source code generated on  : 09-Jul-2022 18:30:27
//

// Include Files
#include "ParameterTree.h"
#include "rt_nonfinite.h"
#include "startsWith.h"
#include "coder_array.h"
#include "mlroscpp_param.h"
#include <functional>

// Variable Definitions
static const char cv[44]{'/', 'p', 'r', 'o', 'c', '_', 'p', 'l', 'a', 'n', 'n',
                         'e', 'r', '/', 'l', 'o', 'w', '_', 's', 'p', 'e', 'e',
                         'd', '/', 'm', 'a', 'x', 'i', 'm', 'u', 'm', '_', 'a',
                         'c', 'c', 'e', 'l', 'e', 'r', 'a', 't', 'i', 'o', 'n'};

static const char cv1[40]{'/', 'p', 'r', 'o', 'c', '_', 'p', 'l', 'a', 'n',
                          'n', 'e', 'r', '/', 'l', 'o', 'w', '_', 's', 'p',
                          'e', 'e', 'd', '/', 'm', 'a', 'x', 'i', 'm', 'u',
                          'm', '_', 'v', 'e', 'l', 'o', 'c', 'i', 't', 'y'};

static const char cv2[44]{
    '/', 'p', 'r', 'o', 'c', '_', 'p', 'l', 'a', 'n', 'n', 'e', 'r', '/', 'l',
    'o', 'w', '_', 's', 'p', 'e', 'e', 'd', '/', 'm', 'a', 'x', 'i', 'm', 'u',
    'm', '_', 'a', 'n', 'g', 'u', 'l', 'a', 'r', '_', 'r', 'a', 't', 'e'};

static const char cv3[47]{'/', 'p', 'r', 'o', 'c', '_', 'p', 'l', 'a', 'n',
                          'n', 'e', 'r', '/', 'n', 'o', 'r', 'm', 'a', 'l',
                          '_', 's', 'p', 'e', 'e', 'd', '/', 'm', 'a', 'x',
                          'i', 'm', 'u', 'm', '_', 'a', 'c', 'c', 'e', 'l',
                          'e', 'r', 'a', 't', 'i', 'o', 'n'};

static const char cv4[43]{'/', 'p', 'r', 'o', 'c', '_', 'p', 'l', 'a', 'n', 'n',
                          'e', 'r', '/', 'n', 'o', 'r', 'm', 'a', 'l', '_', 's',
                          'p', 'e', 'e', 'd', '/', 'm', 'a', 'x', 'i', 'm', 'u',
                          'm', '_', 'v', 'e', 'l', 'o', 'c', 'i', 't', 'y'};

static const char cv5[47]{'/', 'p', 'r', 'o', 'c', '_', 'p', 'l', 'a', 'n',
                          'n', 'e', 'r', '/', 'n', 'o', 'r', 'm', 'a', 'l',
                          '_', 's', 'p', 'e', 'e', 'd', '/', 'm', 'a', 'x',
                          'i', 'm', 'u', 'm', '_', 'a', 'n', 'g', 'u', 'l',
                          'a', 'r', '_', 'r', 'a', 't', 'e'};

static const char cv6[45]{
    '/', 'p', 'r', 'o', 'c', '_', 'p', 'l', 'a', 'n', 'n', 'e', 'r', '/', 'h',
    'i', 'g', 'h', '_', 's', 'p', 'e', 'e', 'd', '/', 'm', 'a', 'x', 'i', 'm',
    'u', 'm', '_', 'a', 'c', 'c', 'e', 'l', 'e', 'r', 'a', 't', 'i', 'o', 'n'};

static const char cv7[41]{'/', 'p', 'r', 'o', 'c', '_', 'p', 'l', 'a', 'n', 'n',
                          'e', 'r', '/', 'h', 'i', 'g', 'h', '_', 's', 'p', 'e',
                          'e', 'd', '/', 'm', 'a', 'x', 'i', 'm', 'u', 'm', '_',
                          'v', 'e', 'l', 'o', 'c', 'i', 't', 'y'};

static const char cv8[45]{
    '/', 'p', 'r', 'o', 'c', '_', 'p', 'l', 'a', 'n', 'n', 'e', 'r', '/', 'h',
    'i', 'g', 'h', '_', 's', 'p', 'e', 'e', 'd', '/', 'm', 'a', 'x', 'i', 'm',
    'u', 'm', '_', 'a', 'n', 'g', 'u', 'l', 'a', 'r', '_', 'r', 'a', 't', 'e'};

static const char cv9[23]{'/', 'p', 'r', 'o', 'c', '_', 'p', 'l',
                          'a', 'n', 'n', 'e', 'r', '/', 'm', 'a',
                          'x', '_', 'd', 'e', 'p', 't', 'h'};

static const char cv10[29]{'/', 'p', 'r', 'o', 'c', '_', 'p', 'l', 'a', 'n',
                           'n', 'e', 'r', '/', 's', 'u', 'r', 'f', 'a', 'c',
                           'e', '_', 'w', 'a', 'r', 'n', 'i', 'n', 'g'};

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
  array<char, 2U> r;
  char name[40];
  for (int i{0}; i < 40; i++) {
    name[i] = cv1[i];
  }
  std::mem_fn (&MATLABROSParameter::isValidPattern)(&obj->ParameterHelper,
                                                    &name[0]);
  validName.set_size(1, 40);
  for (int i{0}; i < 40; i++) {
    validName[i] = cv1[i];
  }
  if (startsWith(validName)) {
    r.set_size(1, 39);
    r[0] = '~';
    for (int i{0}; i < 38; i++) {
      r[i + 1] = validName[i + 2];
    }
    validName.set_size(1, 39);
    for (int i{0}; i < 39; i++) {
      validName[i] = r[i];
    }
  }
}

//
// Arguments    : void
// Return Type  : double
//
double ParameterTree::b_get()
{
  array<char, 2U> in;
  array<char, 2U> parameterName;
  double data;
  int loop_ub;
  char name[40];
  for (int i{0}; i < 40; i++) {
    name[i] = cv1[i];
  }
  std::mem_fn (&MATLABROSParameter::isValidPattern)(&ParameterHelper, &name[0]);
  in.set_size(1, 40);
  for (int i{0}; i < 40; i++) {
    in[i] = cv1[i];
  }
  if (startsWith(in)) {
    parameterName.set_size(1, 39);
    parameterName[0] = '~';
    for (int i{0}; i < 38; i++) {
      parameterName[i + 1] = in[i + 2];
    }
    in.set_size(1, 39);
    for (int i{0}; i < 39; i++) {
      in[i] = parameterName[i];
    }
  }
  parameterName.set_size(1, in.size(1) + 1);
  loop_ub = in.size(1);
  for (int i{0}; i < loop_ub; i++) {
    parameterName[i] = in[i];
  }
  parameterName[in.size(1)] = '\x00';
  data = 0.0;
  std::mem_fn (&MATLABROSParameter::getParameter<double>)(
      &ParameterHelper, &parameterName[0], &data);
  return data;
}

//
// Arguments    : ParameterTree *obj
//                ::coder::array<char, 2U> &validName
// Return Type  : void
//
void ParameterTree::c_canonicalizeName(ParameterTree *obj,
                                       ::coder::array<char, 2U> &validName)
{
  array<char, 2U> r;
  char name[44];
  for (int i{0}; i < 44; i++) {
    name[i] = cv2[i];
  }
  std::mem_fn (&MATLABROSParameter::isValidPattern)(&obj->ParameterHelper,
                                                    &name[0]);
  validName.set_size(1, 44);
  for (int i{0}; i < 44; i++) {
    validName[i] = cv2[i];
  }
  if (startsWith(validName)) {
    r.set_size(1, 43);
    r[0] = '~';
    for (int i{0}; i < 42; i++) {
      r[i + 1] = validName[i + 2];
    }
    validName.set_size(1, 43);
    for (int i{0}; i < 43; i++) {
      validName[i] = r[i];
    }
  }
}

//
// Arguments    : void
// Return Type  : double
//
double ParameterTree::c_get()
{
  array<char, 2U> in;
  array<char, 2U> parameterName;
  double data;
  int loop_ub;
  char name[44];
  for (int i{0}; i < 44; i++) {
    name[i] = cv2[i];
  }
  std::mem_fn (&MATLABROSParameter::isValidPattern)(&ParameterHelper, &name[0]);
  in.set_size(1, 44);
  for (int i{0}; i < 44; i++) {
    in[i] = cv2[i];
  }
  if (startsWith(in)) {
    parameterName.set_size(1, 43);
    parameterName[0] = '~';
    for (int i{0}; i < 42; i++) {
      parameterName[i + 1] = in[i + 2];
    }
    in.set_size(1, 43);
    for (int i{0}; i < 43; i++) {
      in[i] = parameterName[i];
    }
  }
  parameterName.set_size(1, in.size(1) + 1);
  loop_ub = in.size(1);
  for (int i{0}; i < loop_ub; i++) {
    parameterName[i] = in[i];
  }
  parameterName[in.size(1)] = '\x00';
  data = 0.0;
  std::mem_fn (&MATLABROSParameter::getParameter<double>)(
      &ParameterHelper, &parameterName[0], &data);
  return data;
}

//
// Arguments    : ParameterTree *obj
//                ::coder::array<char, 2U> &validName
// Return Type  : void
//
void ParameterTree::canonicalizeName(ParameterTree *obj,
                                     ::coder::array<char, 2U> &validName)
{
  array<char, 2U> r;
  char name[44];
  for (int i{0}; i < 44; i++) {
    name[i] = cv[i];
  }
  std::mem_fn (&MATLABROSParameter::isValidPattern)(&obj->ParameterHelper,
                                                    &name[0]);
  validName.set_size(1, 44);
  for (int i{0}; i < 44; i++) {
    validName[i] = cv[i];
  }
  if (startsWith(validName)) {
    r.set_size(1, 43);
    r[0] = '~';
    for (int i{0}; i < 42; i++) {
      r[i + 1] = validName[i + 2];
    }
    validName.set_size(1, 43);
    for (int i{0}; i < 43; i++) {
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
  array<char, 2U> r;
  char name[47];
  for (int i{0}; i < 47; i++) {
    name[i] = cv3[i];
  }
  std::mem_fn (&MATLABROSParameter::isValidPattern)(&obj->ParameterHelper,
                                                    &name[0]);
  validName.set_size(1, 47);
  for (int i{0}; i < 47; i++) {
    validName[i] = cv3[i];
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
// Arguments    : void
// Return Type  : double
//
double ParameterTree::d_get()
{
  array<char, 2U> in;
  array<char, 2U> parameterName;
  double data;
  int loop_ub;
  char name[47];
  for (int i{0}; i < 47; i++) {
    name[i] = cv3[i];
  }
  std::mem_fn (&MATLABROSParameter::isValidPattern)(&ParameterHelper, &name[0]);
  in.set_size(1, 47);
  for (int i{0}; i < 47; i++) {
    in[i] = cv3[i];
  }
  if (startsWith(in)) {
    parameterName.set_size(1, 46);
    parameterName[0] = '~';
    for (int i{0}; i < 45; i++) {
      parameterName[i + 1] = in[i + 2];
    }
    in.set_size(1, 46);
    for (int i{0}; i < 46; i++) {
      in[i] = parameterName[i];
    }
  }
  parameterName.set_size(1, in.size(1) + 1);
  loop_ub = in.size(1);
  for (int i{0}; i < loop_ub; i++) {
    parameterName[i] = in[i];
  }
  parameterName[in.size(1)] = '\x00';
  data = 0.0;
  std::mem_fn (&MATLABROSParameter::getParameter<double>)(
      &ParameterHelper, &parameterName[0], &data);
  return data;
}

//
// Arguments    : ParameterTree *obj
//                ::coder::array<char, 2U> &validName
// Return Type  : void
//
void ParameterTree::e_canonicalizeName(ParameterTree *obj,
                                       ::coder::array<char, 2U> &validName)
{
  array<char, 2U> r;
  char name[43];
  for (int i{0}; i < 43; i++) {
    name[i] = cv4[i];
  }
  std::mem_fn (&MATLABROSParameter::isValidPattern)(&obj->ParameterHelper,
                                                    &name[0]);
  validName.set_size(1, 43);
  for (int i{0}; i < 43; i++) {
    validName[i] = cv4[i];
  }
  if (startsWith(validName)) {
    r.set_size(1, 42);
    r[0] = '~';
    for (int i{0}; i < 41; i++) {
      r[i + 1] = validName[i + 2];
    }
    validName.set_size(1, 42);
    for (int i{0}; i < 42; i++) {
      validName[i] = r[i];
    }
  }
}

//
// Arguments    : void
// Return Type  : double
//
double ParameterTree::e_get()
{
  array<char, 2U> in;
  array<char, 2U> parameterName;
  double data;
  int loop_ub;
  char name[43];
  for (int i{0}; i < 43; i++) {
    name[i] = cv4[i];
  }
  std::mem_fn (&MATLABROSParameter::isValidPattern)(&ParameterHelper, &name[0]);
  in.set_size(1, 43);
  for (int i{0}; i < 43; i++) {
    in[i] = cv4[i];
  }
  if (startsWith(in)) {
    parameterName.set_size(1, 42);
    parameterName[0] = '~';
    for (int i{0}; i < 41; i++) {
      parameterName[i + 1] = in[i + 2];
    }
    in.set_size(1, 42);
    for (int i{0}; i < 42; i++) {
      in[i] = parameterName[i];
    }
  }
  parameterName.set_size(1, in.size(1) + 1);
  loop_ub = in.size(1);
  for (int i{0}; i < loop_ub; i++) {
    parameterName[i] = in[i];
  }
  parameterName[in.size(1)] = '\x00';
  data = 0.0;
  std::mem_fn (&MATLABROSParameter::getParameter<double>)(
      &ParameterHelper, &parameterName[0], &data);
  return data;
}

//
// Arguments    : ParameterTree *obj
//                ::coder::array<char, 2U> &validName
// Return Type  : void
//
void ParameterTree::f_canonicalizeName(ParameterTree *obj,
                                       ::coder::array<char, 2U> &validName)
{
  array<char, 2U> r;
  char name[47];
  for (int i{0}; i < 47; i++) {
    name[i] = cv5[i];
  }
  std::mem_fn (&MATLABROSParameter::isValidPattern)(&obj->ParameterHelper,
                                                    &name[0]);
  validName.set_size(1, 47);
  for (int i{0}; i < 47; i++) {
    validName[i] = cv5[i];
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
// Arguments    : void
// Return Type  : double
//
double ParameterTree::f_get()
{
  array<char, 2U> in;
  array<char, 2U> parameterName;
  double data;
  int loop_ub;
  char name[47];
  for (int i{0}; i < 47; i++) {
    name[i] = cv5[i];
  }
  std::mem_fn (&MATLABROSParameter::isValidPattern)(&ParameterHelper, &name[0]);
  in.set_size(1, 47);
  for (int i{0}; i < 47; i++) {
    in[i] = cv5[i];
  }
  if (startsWith(in)) {
    parameterName.set_size(1, 46);
    parameterName[0] = '~';
    for (int i{0}; i < 45; i++) {
      parameterName[i + 1] = in[i + 2];
    }
    in.set_size(1, 46);
    for (int i{0}; i < 46; i++) {
      in[i] = parameterName[i];
    }
  }
  parameterName.set_size(1, in.size(1) + 1);
  loop_ub = in.size(1);
  for (int i{0}; i < loop_ub; i++) {
    parameterName[i] = in[i];
  }
  parameterName[in.size(1)] = '\x00';
  data = 0.0;
  std::mem_fn (&MATLABROSParameter::getParameter<double>)(
      &ParameterHelper, &parameterName[0], &data);
  return data;
}

//
// Arguments    : ParameterTree *obj
//                ::coder::array<char, 2U> &validName
// Return Type  : void
//
void ParameterTree::g_canonicalizeName(ParameterTree *obj,
                                       ::coder::array<char, 2U> &validName)
{
  array<char, 2U> r;
  char name[45];
  for (int i{0}; i < 45; i++) {
    name[i] = cv6[i];
  }
  std::mem_fn (&MATLABROSParameter::isValidPattern)(&obj->ParameterHelper,
                                                    &name[0]);
  validName.set_size(1, 45);
  for (int i{0}; i < 45; i++) {
    validName[i] = cv6[i];
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
// Arguments    : void
// Return Type  : double
//
double ParameterTree::g_get()
{
  array<char, 2U> in;
  array<char, 2U> parameterName;
  double data;
  int loop_ub;
  char name[45];
  for (int i{0}; i < 45; i++) {
    name[i] = cv6[i];
  }
  std::mem_fn (&MATLABROSParameter::isValidPattern)(&ParameterHelper, &name[0]);
  in.set_size(1, 45);
  for (int i{0}; i < 45; i++) {
    in[i] = cv6[i];
  }
  if (startsWith(in)) {
    parameterName.set_size(1, 44);
    parameterName[0] = '~';
    for (int i{0}; i < 43; i++) {
      parameterName[i + 1] = in[i + 2];
    }
    in.set_size(1, 44);
    for (int i{0}; i < 44; i++) {
      in[i] = parameterName[i];
    }
  }
  parameterName.set_size(1, in.size(1) + 1);
  loop_ub = in.size(1);
  for (int i{0}; i < loop_ub; i++) {
    parameterName[i] = in[i];
  }
  parameterName[in.size(1)] = '\x00';
  data = 0.0;
  std::mem_fn (&MATLABROSParameter::getParameter<double>)(
      &ParameterHelper, &parameterName[0], &data);
  return data;
}

//
// Arguments    : void
// Return Type  : double
//
double ParameterTree::get()
{
  array<char, 2U> in;
  array<char, 2U> parameterName;
  double data;
  int loop_ub;
  char name[44];
  for (int i{0}; i < 44; i++) {
    name[i] = cv[i];
  }
  std::mem_fn (&MATLABROSParameter::isValidPattern)(&ParameterHelper, &name[0]);
  in.set_size(1, 44);
  for (int i{0}; i < 44; i++) {
    in[i] = cv[i];
  }
  if (startsWith(in)) {
    parameterName.set_size(1, 43);
    parameterName[0] = '~';
    for (int i{0}; i < 42; i++) {
      parameterName[i + 1] = in[i + 2];
    }
    in.set_size(1, 43);
    for (int i{0}; i < 43; i++) {
      in[i] = parameterName[i];
    }
  }
  parameterName.set_size(1, in.size(1) + 1);
  loop_ub = in.size(1);
  for (int i{0}; i < loop_ub; i++) {
    parameterName[i] = in[i];
  }
  parameterName[in.size(1)] = '\x00';
  data = 0.0;
  std::mem_fn (&MATLABROSParameter::getParameter<double>)(
      &ParameterHelper, &parameterName[0], &data);
  return data;
}

//
// Arguments    : ParameterTree *obj
//                ::coder::array<char, 2U> &validName
// Return Type  : void
//
void ParameterTree::h_canonicalizeName(ParameterTree *obj,
                                       ::coder::array<char, 2U> &validName)
{
  array<char, 2U> r;
  char name[41];
  for (int i{0}; i < 41; i++) {
    name[i] = cv7[i];
  }
  std::mem_fn (&MATLABROSParameter::isValidPattern)(&obj->ParameterHelper,
                                                    &name[0]);
  validName.set_size(1, 41);
  for (int i{0}; i < 41; i++) {
    validName[i] = cv7[i];
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
// Arguments    : void
// Return Type  : double
//
double ParameterTree::h_get()
{
  array<char, 2U> in;
  array<char, 2U> parameterName;
  double data;
  int loop_ub;
  char name[41];
  for (int i{0}; i < 41; i++) {
    name[i] = cv7[i];
  }
  std::mem_fn (&MATLABROSParameter::isValidPattern)(&ParameterHelper, &name[0]);
  in.set_size(1, 41);
  for (int i{0}; i < 41; i++) {
    in[i] = cv7[i];
  }
  if (startsWith(in)) {
    parameterName.set_size(1, 40);
    parameterName[0] = '~';
    for (int i{0}; i < 39; i++) {
      parameterName[i + 1] = in[i + 2];
    }
    in.set_size(1, 40);
    for (int i{0}; i < 40; i++) {
      in[i] = parameterName[i];
    }
  }
  parameterName.set_size(1, in.size(1) + 1);
  loop_ub = in.size(1);
  for (int i{0}; i < loop_ub; i++) {
    parameterName[i] = in[i];
  }
  parameterName[in.size(1)] = '\x00';
  data = 0.0;
  std::mem_fn (&MATLABROSParameter::getParameter<double>)(
      &ParameterHelper, &parameterName[0], &data);
  return data;
}

//
// Arguments    : ParameterTree *obj
//                ::coder::array<char, 2U> &validName
// Return Type  : void
//
void ParameterTree::i_canonicalizeName(ParameterTree *obj,
                                       ::coder::array<char, 2U> &validName)
{
  array<char, 2U> r;
  char name[45];
  for (int i{0}; i < 45; i++) {
    name[i] = cv8[i];
  }
  std::mem_fn (&MATLABROSParameter::isValidPattern)(&obj->ParameterHelper,
                                                    &name[0]);
  validName.set_size(1, 45);
  for (int i{0}; i < 45; i++) {
    validName[i] = cv8[i];
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
// Arguments    : void
// Return Type  : double
//
double ParameterTree::i_get()
{
  array<char, 2U> in;
  array<char, 2U> parameterName;
  double data;
  int loop_ub;
  char name[45];
  for (int i{0}; i < 45; i++) {
    name[i] = cv8[i];
  }
  std::mem_fn (&MATLABROSParameter::isValidPattern)(&ParameterHelper, &name[0]);
  in.set_size(1, 45);
  for (int i{0}; i < 45; i++) {
    in[i] = cv8[i];
  }
  if (startsWith(in)) {
    parameterName.set_size(1, 44);
    parameterName[0] = '~';
    for (int i{0}; i < 43; i++) {
      parameterName[i + 1] = in[i + 2];
    }
    in.set_size(1, 44);
    for (int i{0}; i < 44; i++) {
      in[i] = parameterName[i];
    }
  }
  parameterName.set_size(1, in.size(1) + 1);
  loop_ub = in.size(1);
  for (int i{0}; i < loop_ub; i++) {
    parameterName[i] = in[i];
  }
  parameterName[in.size(1)] = '\x00';
  data = 0.0;
  std::mem_fn (&MATLABROSParameter::getParameter<double>)(
      &ParameterHelper, &parameterName[0], &data);
  return data;
}

//
// Arguments    : ParameterTree *obj
//                ::coder::array<char, 2U> &validName
// Return Type  : void
//
void ParameterTree::j_canonicalizeName(ParameterTree *obj,
                                       ::coder::array<char, 2U> &validName)
{
  array<char, 2U> r;
  char name[23];
  for (int i{0}; i < 23; i++) {
    name[i] = cv9[i];
  }
  std::mem_fn (&MATLABROSParameter::isValidPattern)(&obj->ParameterHelper,
                                                    &name[0]);
  validName.set_size(1, 23);
  for (int i{0}; i < 23; i++) {
    validName[i] = cv9[i];
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
// Arguments    : void
// Return Type  : double
//
double ParameterTree::j_get()
{
  array<char, 2U> in;
  array<char, 2U> parameterName;
  double data;
  int loop_ub;
  char name[23];
  for (int i{0}; i < 23; i++) {
    name[i] = cv9[i];
  }
  std::mem_fn (&MATLABROSParameter::isValidPattern)(&ParameterHelper, &name[0]);
  in.set_size(1, 23);
  for (int i{0}; i < 23; i++) {
    in[i] = cv9[i];
  }
  if (startsWith(in)) {
    parameterName.set_size(1, 22);
    parameterName[0] = '~';
    for (int i{0}; i < 21; i++) {
      parameterName[i + 1] = in[i + 2];
    }
    in.set_size(1, 22);
    for (int i{0}; i < 22; i++) {
      in[i] = parameterName[i];
    }
  }
  parameterName.set_size(1, in.size(1) + 1);
  loop_ub = in.size(1);
  for (int i{0}; i < loop_ub; i++) {
    parameterName[i] = in[i];
  }
  parameterName[in.size(1)] = '\x00';
  data = 0.0;
  std::mem_fn (&MATLABROSParameter::getParameter<double>)(
      &ParameterHelper, &parameterName[0], &data);
  return data;
}

//
// Arguments    : ParameterTree *obj
//                ::coder::array<char, 2U> &validName
// Return Type  : void
//
void ParameterTree::k_canonicalizeName(ParameterTree *obj,
                                       ::coder::array<char, 2U> &validName)
{
  array<char, 2U> r;
  char name[29];
  for (int i{0}; i < 29; i++) {
    name[i] = cv10[i];
  }
  std::mem_fn (&MATLABROSParameter::isValidPattern)(&obj->ParameterHelper,
                                                    &name[0]);
  validName.set_size(1, 29);
  for (int i{0}; i < 29; i++) {
    validName[i] = cv10[i];
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

//
// Arguments    : void
// Return Type  : double
//
double ParameterTree::k_get()
{
  array<char, 2U> in;
  array<char, 2U> parameterName;
  double data;
  int loop_ub;
  char name[29];
  for (int i{0}; i < 29; i++) {
    name[i] = cv10[i];
  }
  std::mem_fn (&MATLABROSParameter::isValidPattern)(&ParameterHelper, &name[0]);
  in.set_size(1, 29);
  for (int i{0}; i < 29; i++) {
    in[i] = cv10[i];
  }
  if (startsWith(in)) {
    parameterName.set_size(1, 28);
    parameterName[0] = '~';
    for (int i{0}; i < 27; i++) {
      parameterName[i + 1] = in[i + 2];
    }
    in.set_size(1, 28);
    for (int i{0}; i < 28; i++) {
      in[i] = parameterName[i];
    }
  }
  parameterName.set_size(1, in.size(1) + 1);
  loop_ub = in.size(1);
  for (int i{0}; i < loop_ub; i++) {
    parameterName[i] = in[i];
  }
  parameterName[in.size(1)] = '\x00';
  data = 0.0;
  std::mem_fn (&MATLABROSParameter::getParameter<double>)(
      &ParameterHelper, &parameterName[0], &data);
  return data;
}

} // namespace ros
} // namespace coder

//
// File trailer for ParameterTree.cpp
//
// [EOF]
//
