//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: proc_planner.cpp
//
// MATLAB Coder version            : 5.4
// C/C++ source code generated on  : 25-Jun-2022 15:23:16
//

// Include Files
#include "proc_planner.h"
#include "ParameterTree.h"
#include "Publisher.h"
#include "Rate.h"
#include "Subscriber.h"
#include "proc_planner_data.h"
#include "proc_planner_initialize.h"
#include "proc_planner_internal_types.h"
#include "ros_node.h"
#include "rt_nonfinite.h"
#include "startsWith.h"
#include "coder_array.h"
#include "mlroscpp_param.h"
#include <cstddef>
#include <functional>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function Definitions
//
// Si on roule en simulation
//
// Arguments    : void
// Return Type  : void
//
void proc_planner()
{
  static const char g_name[47]{'/', 'p', 'r', 'o', 'c', '_', 'p', 'l', 'a', 'n',
                               'n', 'e', 'r', '/', 'n', 'o', 'r', 'm', 'a', 'l',
                               '_', 's', 'p', 'e', 'e', 'd', '/', 'm', 'a', 'x',
                               'i', 'm', 'u', 'm', '_', 'a', 'c', 'c', 'e', 'l',
                               'e', 'r', 'a', 't', 'i', 'o', 'n'};
  static const char b_name[44]{
      '/', 'p', 'r', 'o', 'c', '_', 'p', 'l', 'a', 'n', 'n', 'e', 'r', '/', 'l',
      'o', 'w', '_', 's', 'p', 'e', 'e', 'd', '/', 'm', 'a', 'x', 'i', 'm', 'u',
      'm', '_', 'a', 'c', 'c', 'e', 'l', 'e', 'r', 'a', 't', 'i', 'o', 'n'};
  static const char e_name[44]{
      '/', 'p', 'r', 'o', 'c', '_', 'p', 'l', 'a', 'n', 'n', 'e', 'r', '/', 'l',
      'o', 'w', '_', 's', 'p', 'e', 'e', 'd', '/', 'm', 'a', 'x', 'i', 'm', 'u',
      'm', '_', 'a', 'n', 'g', 'u', 'l', 'a', 'r', '_', 'r', 'a', 't', 'e'};
  static const char i_name[43]{
      '/', 'p', 'r', 'o', 'c', '_', 'p', 'l', 'a', 'n', 'n', 'e', 'r', '/', 'n',
      'o', 'r', 'm', 'a', 'l', '_', 's', 'p', 'e', 'e', 'd', '/', 'm', 'a', 'x',
      'i', 'm', 'u', 'm', '_', 'v', 'e', 'l', 'o', 'c', 'i', 't', 'y'};
  static const char d_name[40]{
      '/', 'p', 'r', 'o', 'c', '_', 'p', 'l', 'a', 'n', 'n', 'e', 'r', '/',
      'l', 'o', 'w', '_', 's', 'p', 'e', 'e', 'd', '/', 'm', 'a', 'x', 'i',
      'm', 'u', 'm', '_', 'v', 'e', 'l', 'o', 'c', 'i', 't', 'y'};
  char *rawValue;
  coder::ros::ParameterTree lobj_1;
  coder::ros::Publisher *pub;
  coder::ros::Rate r;
  coder::ros::Subscriber *sub;
  coder::ros::b_Publisher *b_pub;
  coder::ros::b_Subscriber *b_sub;
  ros_node planner;
  coder::array<char, 2U> formatSpec;
  coder::array<char, 2U> parameterName;
  double b_val;
  double c_val;
  double d_val;
  double e_val;
  double f_val;
  double g_val;
  double h_val;
  double i_val;
  double j_val;
  double k_val;
  double val;
  int loop_ub;
  char f_name[47];
  char name[44];
  char h_name[43];
  char c_name[40];
  bool nameExists;
  if (!isInitialized_proc_planner) {
    proc_planner_initialize();
  }
  rawValue = getenv("AUV");
  if (rawValue == NULL) {
    formatSpec.set_size(1, 0);
  } else {
    size_t length;
    length = strlen(rawValue);
    formatSpec.set_size(1, (int)length);
    memcpy((void *)&formatSpec[0], (void *)rawValue,
           (size_t)(int)length * sizeof(char));
  }
  parameterName.set_size(1, formatSpec.size(1) + 1);
  loop_ub = formatSpec.size(1);
  for (int i{0}; i < loop_ub; i++) {
    parameterName[i] = formatSpec[i];
  }
  parameterName[formatSpec.size(1)] = '\x00';
  printf("INFO : proc planner : Load config for %s \n", &parameterName[0]);
  fflush(stdout);
  //  Variables locals
  r.init();
  //  Démarer le planner
  //  Definir les Subscrier ros
  planner.TrajIsGenerating = false;
  //  Constructor
  sub = planner._pobj3.init();
  planner.madpSub = sub;
  b_sub = planner._pobj2.init();
  planner.icSub = b_sub;
  //  Definir les publisher ROS
  pub = planner._pobj1.init();
  planner.trajpub = pub;
  b_pub = planner._pobj0.init();
  planner.validPub = b_pub;
  //  Get ros param
  //  Get rosparam
  lobj_1.ParameterHelper = MATLABROSParameter();
  UNUSED_PARAM(lobj_1.ParameterHelper);
  // ROSPARAM Construct an instance of this class
  //    Detailed explanation goes here
  //         %% get rosparam number
  for (int i{0}; i < 44; i++) {
    name[i] = b_name[i];
  }
  std::mem_fn (&MATLABROSParameter::isValidPattern)(&lobj_1.ParameterHelper,
                                                    &name[0]);
  formatSpec.set_size(1, 44);
  for (int i{0}; i < 44; i++) {
    formatSpec[i] = b_name[i];
  }
  if (coder::startsWith(formatSpec)) {
    parameterName.set_size(1, 43);
    parameterName[0] = '~';
    for (int i{0}; i < 42; i++) {
      parameterName[i + 1] = formatSpec[i + 2];
    }
    formatSpec.set_size(1, 43);
    for (int i{0}; i < 43; i++) {
      formatSpec[i] = parameterName[i];
    }
  }
  parameterName.set_size(1, formatSpec.size(1) + 1);
  loop_ub = formatSpec.size(1);
  for (int i{0}; i < loop_ub; i++) {
    parameterName[i] = formatSpec[i];
  }
  parameterName[formatSpec.size(1)] = '\x00';
  nameExists = std::mem_fn(&MATLABROSParameter::hasParam)(
      lobj_1.ParameterHelper, &parameterName[0]);
  if (nameExists) {
    for (int i{0}; i < 44; i++) {
      name[i] = b_name[i];
    }
    std::mem_fn (&MATLABROSParameter::isValidPattern)(&lobj_1.ParameterHelper,
                                                      &name[0]);
    formatSpec.set_size(1, 44);
    for (int i{0}; i < 44; i++) {
      formatSpec[i] = b_name[i];
    }
    if (coder::startsWith(formatSpec)) {
      parameterName.set_size(1, 43);
      parameterName[0] = '~';
      for (int i{0}; i < 42; i++) {
        parameterName[i + 1] = formatSpec[i + 2];
      }
      formatSpec.set_size(1, 43);
      for (int i{0}; i < 43; i++) {
        formatSpec[i] = parameterName[i];
      }
    }
    parameterName.set_size(1, formatSpec.size(1) + 1);
    loop_ub = formatSpec.size(1);
    for (int i{0}; i < loop_ub; i++) {
      parameterName[i] = formatSpec[i];
    }
    parameterName[formatSpec.size(1)] = '\x00';
    val = 0.0;
    std::mem_fn (&MATLABROSParameter::getParameter<double>)(
        &lobj_1.ParameterHelper, &parameterName[0], &val);
    printf("%s : %f \n", "/proc_planner/low_speed/maximum_acceleration", val);
    fflush(stdout);
  } else {
    val = 0.05;
  }
  //         %% get rosparam number
  for (int i{0}; i < 40; i++) {
    c_name[i] = d_name[i];
  }
  std::mem_fn (&MATLABROSParameter::isValidPattern)(&lobj_1.ParameterHelper,
                                                    &c_name[0]);
  formatSpec.set_size(1, 40);
  for (int i{0}; i < 40; i++) {
    formatSpec[i] = d_name[i];
  }
  if (coder::startsWith(formatSpec)) {
    parameterName.set_size(1, 39);
    parameterName[0] = '~';
    for (int i{0}; i < 38; i++) {
      parameterName[i + 1] = formatSpec[i + 2];
    }
    formatSpec.set_size(1, 39);
    for (int i{0}; i < 39; i++) {
      formatSpec[i] = parameterName[i];
    }
  }
  parameterName.set_size(1, formatSpec.size(1) + 1);
  loop_ub = formatSpec.size(1);
  for (int i{0}; i < loop_ub; i++) {
    parameterName[i] = formatSpec[i];
  }
  parameterName[formatSpec.size(1)] = '\x00';
  nameExists = std::mem_fn(&MATLABROSParameter::hasParam)(
      lobj_1.ParameterHelper, &parameterName[0]);
  if (nameExists) {
    for (int i{0}; i < 40; i++) {
      c_name[i] = d_name[i];
    }
    std::mem_fn (&MATLABROSParameter::isValidPattern)(&lobj_1.ParameterHelper,
                                                      &c_name[0]);
    formatSpec.set_size(1, 40);
    for (int i{0}; i < 40; i++) {
      formatSpec[i] = d_name[i];
    }
    if (coder::startsWith(formatSpec)) {
      parameterName.set_size(1, 39);
      parameterName[0] = '~';
      for (int i{0}; i < 38; i++) {
        parameterName[i + 1] = formatSpec[i + 2];
      }
      formatSpec.set_size(1, 39);
      for (int i{0}; i < 39; i++) {
        formatSpec[i] = parameterName[i];
      }
    }
    parameterName.set_size(1, formatSpec.size(1) + 1);
    loop_ub = formatSpec.size(1);
    for (int i{0}; i < loop_ub; i++) {
      parameterName[i] = formatSpec[i];
    }
    parameterName[formatSpec.size(1)] = '\x00';
    b_val = 0.0;
    std::mem_fn (&MATLABROSParameter::getParameter<double>)(
        &lobj_1.ParameterHelper, &parameterName[0], &b_val);
    printf("%s : %f \n", "/proc_planner/low_speed/maximum_velocity", b_val);
    fflush(stdout);
  } else {
    b_val = 0.2;
  }
  //         %% get rosparam number
  for (int i{0}; i < 44; i++) {
    name[i] = e_name[i];
  }
  std::mem_fn (&MATLABROSParameter::isValidPattern)(&lobj_1.ParameterHelper,
                                                    &name[0]);
  formatSpec.set_size(1, 44);
  for (int i{0}; i < 44; i++) {
    formatSpec[i] = e_name[i];
  }
  if (coder::startsWith(formatSpec)) {
    parameterName.set_size(1, 43);
    parameterName[0] = '~';
    for (int i{0}; i < 42; i++) {
      parameterName[i + 1] = formatSpec[i + 2];
    }
    formatSpec.set_size(1, 43);
    for (int i{0}; i < 43; i++) {
      formatSpec[i] = parameterName[i];
    }
  }
  parameterName.set_size(1, formatSpec.size(1) + 1);
  loop_ub = formatSpec.size(1);
  for (int i{0}; i < loop_ub; i++) {
    parameterName[i] = formatSpec[i];
  }
  parameterName[formatSpec.size(1)] = '\x00';
  nameExists = std::mem_fn(&MATLABROSParameter::hasParam)(
      lobj_1.ParameterHelper, &parameterName[0]);
  if (nameExists) {
    for (int i{0}; i < 44; i++) {
      name[i] = e_name[i];
    }
    std::mem_fn (&MATLABROSParameter::isValidPattern)(&lobj_1.ParameterHelper,
                                                      &name[0]);
    formatSpec.set_size(1, 44);
    for (int i{0}; i < 44; i++) {
      formatSpec[i] = e_name[i];
    }
    if (coder::startsWith(formatSpec)) {
      parameterName.set_size(1, 43);
      parameterName[0] = '~';
      for (int i{0}; i < 42; i++) {
        parameterName[i + 1] = formatSpec[i + 2];
      }
      formatSpec.set_size(1, 43);
      for (int i{0}; i < 43; i++) {
        formatSpec[i] = parameterName[i];
      }
    }
    parameterName.set_size(1, formatSpec.size(1) + 1);
    loop_ub = formatSpec.size(1);
    for (int i{0}; i < loop_ub; i++) {
      parameterName[i] = formatSpec[i];
    }
    parameterName[formatSpec.size(1)] = '\x00';
    c_val = 0.0;
    std::mem_fn (&MATLABROSParameter::getParameter<double>)(
        &lobj_1.ParameterHelper, &parameterName[0], &c_val);
    printf("%s : %f \n", "/proc_planner/low_speed/maximum_angular_rate", c_val);
    fflush(stdout);
  } else {
    c_val = 0.3;
  }
  //         %% get rosparam number
  for (int i{0}; i < 47; i++) {
    f_name[i] = g_name[i];
  }
  std::mem_fn (&MATLABROSParameter::isValidPattern)(&lobj_1.ParameterHelper,
                                                    &f_name[0]);
  formatSpec.set_size(1, 47);
  for (int i{0}; i < 47; i++) {
    formatSpec[i] = g_name[i];
  }
  if (coder::startsWith(formatSpec)) {
    parameterName.set_size(1, 46);
    parameterName[0] = '~';
    for (int i{0}; i < 45; i++) {
      parameterName[i + 1] = formatSpec[i + 2];
    }
    formatSpec.set_size(1, 46);
    for (int i{0}; i < 46; i++) {
      formatSpec[i] = parameterName[i];
    }
  }
  parameterName.set_size(1, formatSpec.size(1) + 1);
  loop_ub = formatSpec.size(1);
  for (int i{0}; i < loop_ub; i++) {
    parameterName[i] = formatSpec[i];
  }
  parameterName[formatSpec.size(1)] = '\x00';
  nameExists = std::mem_fn(&MATLABROSParameter::hasParam)(
      lobj_1.ParameterHelper, &parameterName[0]);
  if (nameExists) {
    for (int i{0}; i < 47; i++) {
      f_name[i] = g_name[i];
    }
    std::mem_fn (&MATLABROSParameter::isValidPattern)(&lobj_1.ParameterHelper,
                                                      &f_name[0]);
    formatSpec.set_size(1, 47);
    for (int i{0}; i < 47; i++) {
      formatSpec[i] = g_name[i];
    }
    if (coder::startsWith(formatSpec)) {
      parameterName.set_size(1, 46);
      parameterName[0] = '~';
      for (int i{0}; i < 45; i++) {
        parameterName[i + 1] = formatSpec[i + 2];
      }
      formatSpec.set_size(1, 46);
      for (int i{0}; i < 46; i++) {
        formatSpec[i] = parameterName[i];
      }
    }
    parameterName.set_size(1, formatSpec.size(1) + 1);
    loop_ub = formatSpec.size(1);
    for (int i{0}; i < loop_ub; i++) {
      parameterName[i] = formatSpec[i];
    }
    parameterName[formatSpec.size(1)] = '\x00';
    d_val = 0.0;
    std::mem_fn (&MATLABROSParameter::getParameter<double>)(
        &lobj_1.ParameterHelper, &parameterName[0], &d_val);
    printf("%s : %f \n", "/proc_planner/normal_speed/maximum_acceleration",
           d_val);
    fflush(stdout);
  } else {
    d_val = 0.1;
  }
  //         %% get rosparam number
  for (int i{0}; i < 43; i++) {
    h_name[i] = i_name[i];
  }
  std::mem_fn (&MATLABROSParameter::isValidPattern)(&lobj_1.ParameterHelper,
                                                    &h_name[0]);
  formatSpec.set_size(1, 43);
  for (int i{0}; i < 43; i++) {
    formatSpec[i] = i_name[i];
  }
  if (coder::startsWith(formatSpec)) {
    parameterName.set_size(1, 42);
    parameterName[0] = '~';
    for (int i{0}; i < 41; i++) {
      parameterName[i + 1] = formatSpec[i + 2];
    }
    formatSpec.set_size(1, 42);
    for (int i{0}; i < 42; i++) {
      formatSpec[i] = parameterName[i];
    }
  }
  parameterName.set_size(1, formatSpec.size(1) + 1);
  loop_ub = formatSpec.size(1);
  for (int i{0}; i < loop_ub; i++) {
    parameterName[i] = formatSpec[i];
  }
  parameterName[formatSpec.size(1)] = '\x00';
  nameExists = std::mem_fn(&MATLABROSParameter::hasParam)(
      lobj_1.ParameterHelper, &parameterName[0]);
  if (nameExists) {
    for (int i{0}; i < 43; i++) {
      h_name[i] = i_name[i];
    }
    std::mem_fn (&MATLABROSParameter::isValidPattern)(&lobj_1.ParameterHelper,
                                                      &h_name[0]);
    formatSpec.set_size(1, 43);
    for (int i{0}; i < 43; i++) {
      formatSpec[i] = i_name[i];
    }
    if (coder::startsWith(formatSpec)) {
      parameterName.set_size(1, 42);
      parameterName[0] = '~';
      for (int i{0}; i < 41; i++) {
        parameterName[i + 1] = formatSpec[i + 2];
      }
      formatSpec.set_size(1, 42);
      for (int i{0}; i < 42; i++) {
        formatSpec[i] = parameterName[i];
      }
    }
    parameterName.set_size(1, formatSpec.size(1) + 1);
    loop_ub = formatSpec.size(1);
    for (int i{0}; i < loop_ub; i++) {
      parameterName[i] = formatSpec[i];
    }
    parameterName[formatSpec.size(1)] = '\x00';
    e_val = 0.0;
    std::mem_fn (&MATLABROSParameter::getParameter<double>)(
        &lobj_1.ParameterHelper, &parameterName[0], &e_val);
    printf("%s : %f \n", "/proc_planner/normal_speed/maximum_velocity", e_val);
    fflush(stdout);
  } else {
    e_val = 0.5;
  }
  //         %% get rosparam number
  coder::ros::ParameterTree::canonicalizeName(&lobj_1, formatSpec);
  parameterName.set_size(1, formatSpec.size(1) + 1);
  loop_ub = formatSpec.size(1);
  for (int i{0}; i < loop_ub; i++) {
    parameterName[i] = formatSpec[i];
  }
  parameterName[formatSpec.size(1)] = '\x00';
  nameExists = std::mem_fn(&MATLABROSParameter::hasParam)(
      lobj_1.ParameterHelper, &parameterName[0]);
  if (nameExists) {
    coder::ros::ParameterTree::canonicalizeName(&lobj_1, formatSpec);
    parameterName.set_size(1, formatSpec.size(1) + 1);
    loop_ub = formatSpec.size(1);
    for (int i{0}; i < loop_ub; i++) {
      parameterName[i] = formatSpec[i];
    }
    parameterName[formatSpec.size(1)] = '\x00';
    f_val = 0.0;
    std::mem_fn (&MATLABROSParameter::getParameter<double>)(
        &lobj_1.ParameterHelper, &parameterName[0], &f_val);
    printf("%s : %f \n", "/proc_planner/normal_speed/maximum_angular_rate",
           f_val);
    fflush(stdout);
  } else {
    f_val = 0.5;
  }
  //         %% get rosparam number
  coder::ros::ParameterTree::b_canonicalizeName(&lobj_1, formatSpec);
  parameterName.set_size(1, formatSpec.size(1) + 1);
  loop_ub = formatSpec.size(1);
  for (int i{0}; i < loop_ub; i++) {
    parameterName[i] = formatSpec[i];
  }
  parameterName[formatSpec.size(1)] = '\x00';
  nameExists = std::mem_fn(&MATLABROSParameter::hasParam)(
      lobj_1.ParameterHelper, &parameterName[0]);
  if (nameExists) {
    coder::ros::ParameterTree::b_canonicalizeName(&lobj_1, formatSpec);
    parameterName.set_size(1, formatSpec.size(1) + 1);
    loop_ub = formatSpec.size(1);
    for (int i{0}; i < loop_ub; i++) {
      parameterName[i] = formatSpec[i];
    }
    parameterName[formatSpec.size(1)] = '\x00';
    g_val = 0.0;
    std::mem_fn (&MATLABROSParameter::getParameter<double>)(
        &lobj_1.ParameterHelper, &parameterName[0], &g_val);
    printf("%s : %f \n", "/proc_planner/high_speed/maximum_acceleration",
           g_val);
    fflush(stdout);
  } else {
    g_val = 0.15;
  }
  //         %% get rosparam number
  coder::ros::ParameterTree::c_canonicalizeName(&lobj_1, formatSpec);
  parameterName.set_size(1, formatSpec.size(1) + 1);
  loop_ub = formatSpec.size(1);
  for (int i{0}; i < loop_ub; i++) {
    parameterName[i] = formatSpec[i];
  }
  parameterName[formatSpec.size(1)] = '\x00';
  nameExists = std::mem_fn(&MATLABROSParameter::hasParam)(
      lobj_1.ParameterHelper, &parameterName[0]);
  if (nameExists) {
    coder::ros::ParameterTree::c_canonicalizeName(&lobj_1, formatSpec);
    parameterName.set_size(1, formatSpec.size(1) + 1);
    loop_ub = formatSpec.size(1);
    for (int i{0}; i < loop_ub; i++) {
      parameterName[i] = formatSpec[i];
    }
    parameterName[formatSpec.size(1)] = '\x00';
    h_val = 0.0;
    std::mem_fn (&MATLABROSParameter::getParameter<double>)(
        &lobj_1.ParameterHelper, &parameterName[0], &h_val);
    printf("%s : %f \n", "/proc_planner/high_speed/maximum_velocity", h_val);
    fflush(stdout);
  } else {
    h_val = 0.8;
  }
  //         %% get rosparam number
  coder::ros::ParameterTree::d_canonicalizeName(&lobj_1, formatSpec);
  parameterName.set_size(1, formatSpec.size(1) + 1);
  loop_ub = formatSpec.size(1);
  for (int i{0}; i < loop_ub; i++) {
    parameterName[i] = formatSpec[i];
  }
  parameterName[formatSpec.size(1)] = '\x00';
  nameExists = std::mem_fn(&MATLABROSParameter::hasParam)(
      lobj_1.ParameterHelper, &parameterName[0]);
  if (nameExists) {
    coder::ros::ParameterTree::d_canonicalizeName(&lobj_1, formatSpec);
    parameterName.set_size(1, formatSpec.size(1) + 1);
    loop_ub = formatSpec.size(1);
    for (int i{0}; i < loop_ub; i++) {
      parameterName[i] = formatSpec[i];
    }
    parameterName[formatSpec.size(1)] = '\x00';
    i_val = 0.0;
    std::mem_fn (&MATLABROSParameter::getParameter<double>)(
        &lobj_1.ParameterHelper, &parameterName[0], &i_val);
    printf("%s : %f \n", "/proc_planner/high_speed/maximum_angular_rate",
           i_val);
    fflush(stdout);
  } else {
    i_val = 0.8;
  }
  //         %% get rosparam number
  coder::ros::ParameterTree::e_canonicalizeName(&lobj_1, formatSpec);
  parameterName.set_size(1, formatSpec.size(1) + 1);
  loop_ub = formatSpec.size(1);
  for (int i{0}; i < loop_ub; i++) {
    parameterName[i] = formatSpec[i];
  }
  parameterName[formatSpec.size(1)] = '\x00';
  nameExists = std::mem_fn(&MATLABROSParameter::hasParam)(
      lobj_1.ParameterHelper, &parameterName[0]);
  if (nameExists) {
    coder::ros::ParameterTree::e_canonicalizeName(&lobj_1, formatSpec);
    parameterName.set_size(1, formatSpec.size(1) + 1);
    loop_ub = formatSpec.size(1);
    for (int i{0}; i < loop_ub; i++) {
      parameterName[i] = formatSpec[i];
    }
    parameterName[formatSpec.size(1)] = '\x00';
    j_val = 0.0;
    std::mem_fn (&MATLABROSParameter::getParameter<double>)(
        &lobj_1.ParameterHelper, &parameterName[0], &j_val);
    printf("%s : %f \n", "/proc_planner/max_depth", j_val);
    fflush(stdout);
  } else {
    j_val = 5.0;
  }
  //         %% get rosparam number
  coder::ros::ParameterTree::f_canonicalizeName(&lobj_1, formatSpec);
  parameterName.set_size(1, formatSpec.size(1) + 1);
  loop_ub = formatSpec.size(1);
  for (int i{0}; i < loop_ub; i++) {
    parameterName[i] = formatSpec[i];
  }
  parameterName[formatSpec.size(1)] = '\x00';
  nameExists = std::mem_fn(&MATLABROSParameter::hasParam)(
      lobj_1.ParameterHelper, &parameterName[0]);
  if (nameExists) {
    coder::ros::ParameterTree::f_canonicalizeName(&lobj_1, formatSpec);
    parameterName.set_size(1, formatSpec.size(1) + 1);
    loop_ub = formatSpec.size(1);
    for (int i{0}; i < loop_ub; i++) {
      parameterName[i] = formatSpec[i];
    }
    parameterName[formatSpec.size(1)] = '\x00';
    k_val = 0.0;
    std::mem_fn (&MATLABROSParameter::getParameter<double>)(
        &lobj_1.ParameterHelper, &parameterName[0], &k_val);
    printf("%s : %f \n", "/proc_planner/surface_warning", k_val);
    fflush(stdout);
  } else {
    k_val = 0.3;
  }
  planner.param.ts = 0.1;
  planner.param.lowSpeed.amax = val;
  planner.param.lowSpeed.vlmax = b_val;
  planner.param.lowSpeed.vamax = c_val;
  planner.param.normalSpeed.amax = d_val;
  planner.param.normalSpeed.vlmax = e_val;
  planner.param.normalSpeed.vamax = f_val;
  planner.param.highSpeed.amax = g_val;
  planner.param.highSpeed.vlmax = h_val;
  planner.param.highSpeed.vamax = i_val;
  planner.param.maxDepth = j_val;
  planner.param.surfaceWarning = k_val;
  planner.spin(&r);
}

//
// File trailer for proc_planner.cpp
//
// [EOF]
//
