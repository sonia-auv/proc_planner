//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: proc_planner.cpp
//
// MATLAB Coder version            : 5.4
// C/C++ source code generated on  : 12-May-2022 22:37:14
//

// Include Files
#include "proc_planner.h"
#include "ParameterTree.h"
#include "Publisher.h"
#include "Rate.h"
#include "Subscriber.h"
#include "TrajectoryGenerator.h"
#include "proc_planner_data.h"
#include "proc_planner_initialize.h"
#include "proc_planner_types.h"
#include "rt_nonfinite.h"
#include "startsWith.h"
#include "std_msgs_Int8Struct.h"
#include "tic.h"
#include "toc.h"
#include "coder_array.h"
#include "coder_posix_time.h"
#include "mlroscpp_param.h"
#include "mlroscpp_pub.h"
#include "mlroscpp_rate.h"
#include <cmath>
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
  static const char j_name[47]{'/', 'p', 'r', 'o', 'c', '_', 'p', 'l', 'a', 'n',
                               'n', 'e', 'r', '/', 'n', 'o', 'r', 'm', 'a', 'l',
                               '_', 's', 'p', 'e', 'e', 'd', '/', 'm', 'a', 'x',
                               'i', 'm', 'u', 'm', '_', 'a', 'n', 'g', 'u', 'l',
                               'a', 'r', '_', 'r', 'a', 't', 'e'};
  static const char l_name[45]{'/', 'p', 'r', 'o', 'c', '_', 'p', 'l', 'a',
                               'n', 'n', 'e', 'r', '/', 'h', 'i', 'g', 'h',
                               '_', 's', 'p', 'e', 'e', 'd', '/', 'm', 'a',
                               'x', 'i', 'm', 'u', 'm', '_', 'a', 'c', 'c',
                               'e', 'l', 'e', 'r', 'a', 't', 'i', 'o', 'n'};
  static const char o_name[45]{'/', 'p', 'r', 'o', 'c', '_', 'p', 'l', 'a',
                               'n', 'n', 'e', 'r', '/', 'h', 'i', 'g', 'h',
                               '_', 's', 'p', 'e', 'e', 'd', '/', 'm', 'a',
                               'x', 'i', 'm', 'u', 'm', '_', 'a', 'n', 'g',
                               'u', 'l', 'a', 'r', '_', 'r', 'a', 't', 'e'};
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
  static const char n_name[41]{
      '/', 'p', 'r', 'o', 'c', '_', 'p', 'l', 'a', 'n', 'n', 'e', 'r', '/',
      'h', 'i', 'g', 'h', '_', 's', 'p', 'e', 'e', 'd', '/', 'm', 'a', 'x',
      'i', 'm', 'u', 'm', '_', 'v', 'e', 'l', 'o', 'c', 'i', 't', 'y'};
  static const char d_name[40]{
      '/', 'p', 'r', 'o', 'c', '_', 'p', 'l', 'a', 'n', 'n', 'e', 'r', '/',
      'l', 'o', 'w', '_', 's', 'p', 'e', 'e', 'd', '/', 'm', 'a', 'x', 'i',
      'm', 'u', 'm', '_', 'v', 'e', 'l', 'o', 'c', 'i', 't', 'y'};
  char *rawValue;
  TrajectoryGenerator TG;
  coder::ros::ParameterTree lobj_1;
  coder::ros::Publisher trajpub;
  coder::ros::Rate r;
  coder::ros::Subscriber madpSub;
  coder::ros::b_Publisher validPub;
  coder::ros::b_Subscriber icSub;
  coder::array<sonia_common_AddPoseStruct_T, 1U> t2_Pose;
  coder::array<char, 2U> formatSpec;
  coder::array<char, 2U> parameterName;
  geometry_msgs_PointStruct_T t3_Position;
  geometry_msgs_QuaternionStruct_T t3_Orientation;
  std_msgs_Int8Struct_T validMsg;
  double b_expl_temp;
  double expl_temp;
  double param_highSpeed_amax;
  double param_highSpeed_vamax;
  double param_highSpeed_vlmax;
  double param_lowSpeed_amax;
  double param_lowSpeed_vamax;
  double param_lowSpeed_vlmax;
  double param_normalSpeed_amax;
  double param_normalSpeed_vamax;
  double param_normalSpeed_vlmax;
  int loop_ub;
  char f_name[47];
  char k_name[45];
  char name[44];
  char h_name[43];
  char m_name[41];
  char c_name[40];
  char t2_MessageType[25];
  unsigned char t2_InterpolationMethod;
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
  //  Definir les variables
  //  Variables globals
  newMadpPose = false;
  newInitialPose = false;
  TrajIsGenerating = false;
  //  Variables locals
  r.init();
  //  Definir les message ros
  validMsg = std_msgs_Int8Struct();
  //  Definir les Subscrier ros
  madpSub.init();
  icSub.init();
  //  Definir les publisher ROS
  trajpub.init();
  validPub.init();
  //  Definir les parametre de trajectoire
  //  Get rosparam
  lobj_1.ParameterHelper = MATLABROSParameter();
  UNUSED_PARAM(lobj_1.ParameterHelper);
  // ROSPARAM Construct an instance of this class
  //    Detailed explanation goes here
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
    param_lowSpeed_amax = 0.0;
    std::mem_fn (&MATLABROSParameter::getParameter<double>)(
        &lobj_1.ParameterHelper, &parameterName[0], &param_lowSpeed_amax);
  } else {
    param_lowSpeed_amax = 0.05;
  }
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
    param_lowSpeed_vlmax = 0.0;
    std::mem_fn (&MATLABROSParameter::getParameter<double>)(
        &lobj_1.ParameterHelper, &parameterName[0], &param_lowSpeed_vlmax);
  } else {
    param_lowSpeed_vlmax = 0.2;
  }
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
    param_lowSpeed_vamax = 0.0;
    std::mem_fn (&MATLABROSParameter::getParameter<double>)(
        &lobj_1.ParameterHelper, &parameterName[0], &param_lowSpeed_vamax);
  } else {
    param_lowSpeed_vamax = 0.3;
  }
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
    param_normalSpeed_amax = 0.0;
    std::mem_fn (&MATLABROSParameter::getParameter<double>)(
        &lobj_1.ParameterHelper, &parameterName[0], &param_normalSpeed_amax);
  } else {
    param_normalSpeed_amax = 0.1;
  }
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
    param_normalSpeed_vlmax = 0.0;
    std::mem_fn (&MATLABROSParameter::getParameter<double>)(
        &lobj_1.ParameterHelper, &parameterName[0], &param_normalSpeed_vlmax);
  } else {
    param_normalSpeed_vlmax = 0.5;
  }
  for (int i{0}; i < 47; i++) {
    f_name[i] = j_name[i];
  }
  std::mem_fn (&MATLABROSParameter::isValidPattern)(&lobj_1.ParameterHelper,
                                                    &f_name[0]);
  formatSpec.set_size(1, 47);
  for (int i{0}; i < 47; i++) {
    formatSpec[i] = j_name[i];
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
      f_name[i] = j_name[i];
    }
    std::mem_fn (&MATLABROSParameter::isValidPattern)(&lobj_1.ParameterHelper,
                                                      &f_name[0]);
    formatSpec.set_size(1, 47);
    for (int i{0}; i < 47; i++) {
      formatSpec[i] = j_name[i];
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
    param_normalSpeed_vamax = 0.0;
    std::mem_fn (&MATLABROSParameter::getParameter<double>)(
        &lobj_1.ParameterHelper, &parameterName[0], &param_normalSpeed_vamax);
  } else {
    param_normalSpeed_vamax = 0.5;
  }
  for (int i{0}; i < 45; i++) {
    k_name[i] = l_name[i];
  }
  std::mem_fn (&MATLABROSParameter::isValidPattern)(&lobj_1.ParameterHelper,
                                                    &k_name[0]);
  formatSpec.set_size(1, 45);
  for (int i{0}; i < 45; i++) {
    formatSpec[i] = l_name[i];
  }
  if (coder::startsWith(formatSpec)) {
    parameterName.set_size(1, 44);
    parameterName[0] = '~';
    for (int i{0}; i < 43; i++) {
      parameterName[i + 1] = formatSpec[i + 2];
    }
    formatSpec.set_size(1, 44);
    for (int i{0}; i < 44; i++) {
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
    for (int i{0}; i < 45; i++) {
      k_name[i] = l_name[i];
    }
    std::mem_fn (&MATLABROSParameter::isValidPattern)(&lobj_1.ParameterHelper,
                                                      &k_name[0]);
    formatSpec.set_size(1, 45);
    for (int i{0}; i < 45; i++) {
      formatSpec[i] = l_name[i];
    }
    if (coder::startsWith(formatSpec)) {
      parameterName.set_size(1, 44);
      parameterName[0] = '~';
      for (int i{0}; i < 43; i++) {
        parameterName[i + 1] = formatSpec[i + 2];
      }
      formatSpec.set_size(1, 44);
      for (int i{0}; i < 44; i++) {
        formatSpec[i] = parameterName[i];
      }
    }
    parameterName.set_size(1, formatSpec.size(1) + 1);
    loop_ub = formatSpec.size(1);
    for (int i{0}; i < loop_ub; i++) {
      parameterName[i] = formatSpec[i];
    }
    parameterName[formatSpec.size(1)] = '\x00';
    param_highSpeed_amax = 0.0;
    std::mem_fn (&MATLABROSParameter::getParameter<double>)(
        &lobj_1.ParameterHelper, &parameterName[0], &param_highSpeed_amax);
  } else {
    param_highSpeed_amax = 0.15;
  }
  for (int i{0}; i < 41; i++) {
    m_name[i] = n_name[i];
  }
  std::mem_fn (&MATLABROSParameter::isValidPattern)(&lobj_1.ParameterHelper,
                                                    &m_name[0]);
  formatSpec.set_size(1, 41);
  for (int i{0}; i < 41; i++) {
    formatSpec[i] = n_name[i];
  }
  if (coder::startsWith(formatSpec)) {
    parameterName.set_size(1, 40);
    parameterName[0] = '~';
    for (int i{0}; i < 39; i++) {
      parameterName[i + 1] = formatSpec[i + 2];
    }
    formatSpec.set_size(1, 40);
    for (int i{0}; i < 40; i++) {
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
    for (int i{0}; i < 41; i++) {
      m_name[i] = n_name[i];
    }
    std::mem_fn (&MATLABROSParameter::isValidPattern)(&lobj_1.ParameterHelper,
                                                      &m_name[0]);
    formatSpec.set_size(1, 41);
    for (int i{0}; i < 41; i++) {
      formatSpec[i] = n_name[i];
    }
    if (coder::startsWith(formatSpec)) {
      parameterName.set_size(1, 40);
      parameterName[0] = '~';
      for (int i{0}; i < 39; i++) {
        parameterName[i + 1] = formatSpec[i + 2];
      }
      formatSpec.set_size(1, 40);
      for (int i{0}; i < 40; i++) {
        formatSpec[i] = parameterName[i];
      }
    }
    parameterName.set_size(1, formatSpec.size(1) + 1);
    loop_ub = formatSpec.size(1);
    for (int i{0}; i < loop_ub; i++) {
      parameterName[i] = formatSpec[i];
    }
    parameterName[formatSpec.size(1)] = '\x00';
    param_highSpeed_vlmax = 0.0;
    std::mem_fn (&MATLABROSParameter::getParameter<double>)(
        &lobj_1.ParameterHelper, &parameterName[0], &param_highSpeed_vlmax);
  } else {
    param_highSpeed_vlmax = 0.8;
  }
  for (int i{0}; i < 45; i++) {
    k_name[i] = o_name[i];
  }
  std::mem_fn (&MATLABROSParameter::isValidPattern)(&lobj_1.ParameterHelper,
                                                    &k_name[0]);
  formatSpec.set_size(1, 45);
  for (int i{0}; i < 45; i++) {
    formatSpec[i] = o_name[i];
  }
  if (coder::startsWith(formatSpec)) {
    parameterName.set_size(1, 44);
    parameterName[0] = '~';
    for (int i{0}; i < 43; i++) {
      parameterName[i + 1] = formatSpec[i + 2];
    }
    formatSpec.set_size(1, 44);
    for (int i{0}; i < 44; i++) {
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
    for (int i{0}; i < 45; i++) {
      k_name[i] = o_name[i];
    }
    std::mem_fn (&MATLABROSParameter::isValidPattern)(&lobj_1.ParameterHelper,
                                                      &k_name[0]);
    formatSpec.set_size(1, 45);
    for (int i{0}; i < 45; i++) {
      formatSpec[i] = o_name[i];
    }
    if (coder::startsWith(formatSpec)) {
      parameterName.set_size(1, 44);
      parameterName[0] = '~';
      for (int i{0}; i < 43; i++) {
        parameterName[i + 1] = formatSpec[i + 2];
      }
      formatSpec.set_size(1, 44);
      for (int i{0}; i < 44; i++) {
        formatSpec[i] = parameterName[i];
      }
    }
    parameterName.set_size(1, formatSpec.size(1) + 1);
    loop_ub = formatSpec.size(1);
    for (int i{0}; i < loop_ub; i++) {
      parameterName[i] = formatSpec[i];
    }
    parameterName[formatSpec.size(1)] = '\x00';
    param_highSpeed_vamax = 0.0;
    std::mem_fn (&MATLABROSParameter::getParameter<double>)(
        &lobj_1.ParameterHelper, &parameterName[0], &param_highSpeed_vamax);
  } else {
    param_highSpeed_vamax = 0.8;
  }
  //  Ros Spin
  printf("INFO : proc planner : Node is started \n");
  fflush(stdout);
  printf("INFO : proc planner : Wait for poses \n");
  fflush(stdout);
  MATLABRate_reset(r.RateHelper);
  coder::tic(&expl_temp, &b_expl_temp);
  while (1) {
    if (newMadpPose && newInitialPose) {
      signed char i1;
      //  Cree l'objet trajectoire
      madpSub.get_LatestMessage(t2_MessageType, &t2_InterpolationMethod,
                                t2_Pose);
      icSub.get_LatestMessage(&t3_Position, &t3_Orientation);
      TG.init(t2_MessageType, t2_InterpolationMethod, t2_Pose,
              param_lowSpeed_amax, param_lowSpeed_vlmax, param_lowSpeed_vamax,
              param_normalSpeed_amax, param_normalSpeed_vlmax,
              param_normalSpeed_vamax, param_highSpeed_amax,
              param_highSpeed_vlmax, param_highSpeed_vamax, t3_Position,
              t3_Orientation);
      //  Envoyer a ros si le mAddpose est valide
      expl_temp = std::round(TG.status);
      if (expl_temp < 128.0) {
        if (expl_temp >= -128.0) {
          i1 = static_cast<signed char>(expl_temp);
        } else {
          i1 = MIN_int8_T;
        }
      } else if (expl_temp >= 128.0) {
        i1 = MAX_int8_T;
      } else {
        i1 = 0;
      }
      validMsg.Data = i1;
      MATLABPUBLISHER_publish(validPub.PublisherHelper, &validMsg);
      //  Si la trajectoire est valide generer la trajectoire
      if (TG.status == 0.0) {
        TG.Compute(&trajpub);
      }
      newMadpPose = false;
      newInitialPose = false;
      TrajIsGenerating = false;
      printf("INFO : proc planner : Wait for poses \n");
      fflush(stdout);
    }
    MATLABRate_sleep(r.RateHelper);
    coder::toc(r.PreviousPeriod.tv_sec, r.PreviousPeriod.tv_nsec);
    coder::tic(&r.PreviousPeriod.tv_sec, &r.PreviousPeriod.tv_nsec);
  }
}

//
// File trailer for proc_planner.cpp
//
// [EOF]
//
