//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: proc_planner.cpp
//
// MATLAB Coder version            : 5.4
// C/C++ source code generated on  : 12-Apr-2022 11:44:16
//

// Include Files
#include "proc_planner.h"
#include "ParameterTree.h"
#include "Publisher.h"
#include "Rate.h"
#include "Subscriber.h"
#include "TrajectoryGenerator.h"
#include "dot.h"
#include "eul2quat.h"
#include "geometry_msgs_TransformStruct.h"
#include "geometry_msgs_TwistStruct.h"
#include "getenv.h"
#include "minOrMax.h"
#include "norm.h"
#include "proc_planner_data.h"
#include "proc_planner_initialize.h"
#include "proc_planner_rtwutil.h"
#include "proc_planner_types.h"
#include "quat2eul.h"
#include "quaternion.h"
#include "quatmultiply.h"
#include "repelem.h"
#include "rt_nonfinite.h"
#include "startsWith.h"
#include "std_msgs_BoolStruct.h"
#include "tic.h"
#include "toc.h"
#include "trajectory_msgs_MultiDOFJointTrajectoryPointStruct.h"
#include "waypointTrajectory.h"
#include "coder_array.h"
#include "coder_posix_time.h"
#include "mlroscpp_param.h"
#include "mlroscpp_pub.h"
#include "mlroscpp_rate.h"
#include <cmath>
#include <functional>
#include <stdio.h>
#include <string.h>

// Function Declarations
static void
getRosParam(double *param_ts, double *param_lowSpeed_amax,
            double *param_lowSpeed_vlmax, double *param_lowSpeed_vamax,
            double *param_normalSpeed_amax, double *param_normalSpeed_vlmax,
            double *param_normalSpeed_vamax, double *param_highSpeed_amax,
            double *param_highSpeed_vlmax, double *param_highSpeed_vamax);

// Function Definitions
//
// Arguments    : double *param_ts
//                double *param_lowSpeed_amax
//                double *param_lowSpeed_vlmax
//                double *param_lowSpeed_vamax
//                double *param_normalSpeed_amax
//                double *param_normalSpeed_vlmax
//                double *param_normalSpeed_vamax
//                double *param_highSpeed_amax
//                double *param_highSpeed_vlmax
//                double *param_highSpeed_vamax
// Return Type  : void
//
static void
getRosParam(double *param_ts, double *param_lowSpeed_amax,
            double *param_lowSpeed_vlmax, double *param_lowSpeed_vamax,
            double *param_normalSpeed_amax, double *param_normalSpeed_vlmax,
            double *param_normalSpeed_vamax, double *param_highSpeed_amax,
            double *param_highSpeed_vlmax, double *param_highSpeed_vamax)
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
  coder::ros::ParameterTree lobj_1;
  coder::array<char, 2U> in;
  coder::array<char, 2U> parameterName;
  int loop_ub;
  char f_name[47];
  char k_name[45];
  char name[44];
  char h_name[43];
  char m_name[41];
  char c_name[40];
  bool nameExists;
  //  Get rosparam
  *param_ts = 0.1;
  lobj_1.ParameterHelper = MATLABROSParameter();
  UNUSED_PARAM(lobj_1.ParameterHelper);
  // ROSPARAM Construct an instance of this class
  //    Detailed explanation goes here
  for (int i{0}; i < 44; i++) {
    name[i] = b_name[i];
  }
  std::mem_fn (&MATLABROSParameter::isValidPattern)(&lobj_1.ParameterHelper,
                                                    &name[0]);
  in.set_size(1, 44);
  for (int i{0}; i < 44; i++) {
    in[i] = b_name[i];
  }
  if (coder::startsWith(in)) {
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
  nameExists = std::mem_fn(&MATLABROSParameter::hasParam)(
      lobj_1.ParameterHelper, &parameterName[0]);
  if (nameExists) {
    for (int i{0}; i < 44; i++) {
      name[i] = b_name[i];
    }
    std::mem_fn (&MATLABROSParameter::isValidPattern)(&lobj_1.ParameterHelper,
                                                      &name[0]);
    in.set_size(1, 44);
    for (int i{0}; i < 44; i++) {
      in[i] = b_name[i];
    }
    if (coder::startsWith(in)) {
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
    *param_lowSpeed_amax = 0.0;
    std::mem_fn (&MATLABROSParameter::getParameter<double>)(
        &lobj_1.ParameterHelper, &parameterName[0], param_lowSpeed_amax);
  } else {
    *param_lowSpeed_amax = 0.05;
  }
  for (int i{0}; i < 40; i++) {
    c_name[i] = d_name[i];
  }
  std::mem_fn (&MATLABROSParameter::isValidPattern)(&lobj_1.ParameterHelper,
                                                    &c_name[0]);
  in.set_size(1, 40);
  for (int i{0}; i < 40; i++) {
    in[i] = d_name[i];
  }
  if (coder::startsWith(in)) {
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
  nameExists = std::mem_fn(&MATLABROSParameter::hasParam)(
      lobj_1.ParameterHelper, &parameterName[0]);
  if (nameExists) {
    for (int i{0}; i < 40; i++) {
      c_name[i] = d_name[i];
    }
    std::mem_fn (&MATLABROSParameter::isValidPattern)(&lobj_1.ParameterHelper,
                                                      &c_name[0]);
    in.set_size(1, 40);
    for (int i{0}; i < 40; i++) {
      in[i] = d_name[i];
    }
    if (coder::startsWith(in)) {
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
    *param_lowSpeed_vlmax = 0.0;
    std::mem_fn (&MATLABROSParameter::getParameter<double>)(
        &lobj_1.ParameterHelper, &parameterName[0], param_lowSpeed_vlmax);
  } else {
    *param_lowSpeed_vlmax = 0.2;
  }
  for (int i{0}; i < 44; i++) {
    name[i] = e_name[i];
  }
  std::mem_fn (&MATLABROSParameter::isValidPattern)(&lobj_1.ParameterHelper,
                                                    &name[0]);
  in.set_size(1, 44);
  for (int i{0}; i < 44; i++) {
    in[i] = e_name[i];
  }
  if (coder::startsWith(in)) {
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
  nameExists = std::mem_fn(&MATLABROSParameter::hasParam)(
      lobj_1.ParameterHelper, &parameterName[0]);
  if (nameExists) {
    for (int i{0}; i < 44; i++) {
      name[i] = e_name[i];
    }
    std::mem_fn (&MATLABROSParameter::isValidPattern)(&lobj_1.ParameterHelper,
                                                      &name[0]);
    in.set_size(1, 44);
    for (int i{0}; i < 44; i++) {
      in[i] = e_name[i];
    }
    if (coder::startsWith(in)) {
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
    *param_lowSpeed_vamax = 0.0;
    std::mem_fn (&MATLABROSParameter::getParameter<double>)(
        &lobj_1.ParameterHelper, &parameterName[0], param_lowSpeed_vamax);
  } else {
    *param_lowSpeed_vamax = 0.3;
  }
  for (int i{0}; i < 47; i++) {
    f_name[i] = g_name[i];
  }
  std::mem_fn (&MATLABROSParameter::isValidPattern)(&lobj_1.ParameterHelper,
                                                    &f_name[0]);
  in.set_size(1, 47);
  for (int i{0}; i < 47; i++) {
    in[i] = g_name[i];
  }
  if (coder::startsWith(in)) {
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
  nameExists = std::mem_fn(&MATLABROSParameter::hasParam)(
      lobj_1.ParameterHelper, &parameterName[0]);
  if (nameExists) {
    for (int i{0}; i < 47; i++) {
      f_name[i] = g_name[i];
    }
    std::mem_fn (&MATLABROSParameter::isValidPattern)(&lobj_1.ParameterHelper,
                                                      &f_name[0]);
    in.set_size(1, 47);
    for (int i{0}; i < 47; i++) {
      in[i] = g_name[i];
    }
    if (coder::startsWith(in)) {
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
    *param_normalSpeed_amax = 0.0;
    std::mem_fn (&MATLABROSParameter::getParameter<double>)(
        &lobj_1.ParameterHelper, &parameterName[0], param_normalSpeed_amax);
  } else {
    *param_normalSpeed_amax = 0.1;
  }
  for (int i{0}; i < 43; i++) {
    h_name[i] = i_name[i];
  }
  std::mem_fn (&MATLABROSParameter::isValidPattern)(&lobj_1.ParameterHelper,
                                                    &h_name[0]);
  in.set_size(1, 43);
  for (int i{0}; i < 43; i++) {
    in[i] = i_name[i];
  }
  if (coder::startsWith(in)) {
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
  nameExists = std::mem_fn(&MATLABROSParameter::hasParam)(
      lobj_1.ParameterHelper, &parameterName[0]);
  if (nameExists) {
    for (int i{0}; i < 43; i++) {
      h_name[i] = i_name[i];
    }
    std::mem_fn (&MATLABROSParameter::isValidPattern)(&lobj_1.ParameterHelper,
                                                      &h_name[0]);
    in.set_size(1, 43);
    for (int i{0}; i < 43; i++) {
      in[i] = i_name[i];
    }
    if (coder::startsWith(in)) {
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
    *param_normalSpeed_vlmax = 0.0;
    std::mem_fn (&MATLABROSParameter::getParameter<double>)(
        &lobj_1.ParameterHelper, &parameterName[0], param_normalSpeed_vlmax);
  } else {
    *param_normalSpeed_vlmax = 0.5;
  }
  for (int i{0}; i < 47; i++) {
    f_name[i] = j_name[i];
  }
  std::mem_fn (&MATLABROSParameter::isValidPattern)(&lobj_1.ParameterHelper,
                                                    &f_name[0]);
  in.set_size(1, 47);
  for (int i{0}; i < 47; i++) {
    in[i] = j_name[i];
  }
  if (coder::startsWith(in)) {
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
  nameExists = std::mem_fn(&MATLABROSParameter::hasParam)(
      lobj_1.ParameterHelper, &parameterName[0]);
  if (nameExists) {
    for (int i{0}; i < 47; i++) {
      f_name[i] = j_name[i];
    }
    std::mem_fn (&MATLABROSParameter::isValidPattern)(&lobj_1.ParameterHelper,
                                                      &f_name[0]);
    in.set_size(1, 47);
    for (int i{0}; i < 47; i++) {
      in[i] = j_name[i];
    }
    if (coder::startsWith(in)) {
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
    *param_normalSpeed_vamax = 0.0;
    std::mem_fn (&MATLABROSParameter::getParameter<double>)(
        &lobj_1.ParameterHelper, &parameterName[0], param_normalSpeed_vamax);
  } else {
    *param_normalSpeed_vamax = 0.5;
  }
  for (int i{0}; i < 45; i++) {
    k_name[i] = l_name[i];
  }
  std::mem_fn (&MATLABROSParameter::isValidPattern)(&lobj_1.ParameterHelper,
                                                    &k_name[0]);
  in.set_size(1, 45);
  for (int i{0}; i < 45; i++) {
    in[i] = l_name[i];
  }
  if (coder::startsWith(in)) {
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
  nameExists = std::mem_fn(&MATLABROSParameter::hasParam)(
      lobj_1.ParameterHelper, &parameterName[0]);
  if (nameExists) {
    for (int i{0}; i < 45; i++) {
      k_name[i] = l_name[i];
    }
    std::mem_fn (&MATLABROSParameter::isValidPattern)(&lobj_1.ParameterHelper,
                                                      &k_name[0]);
    in.set_size(1, 45);
    for (int i{0}; i < 45; i++) {
      in[i] = l_name[i];
    }
    if (coder::startsWith(in)) {
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
    *param_highSpeed_amax = 0.0;
    std::mem_fn (&MATLABROSParameter::getParameter<double>)(
        &lobj_1.ParameterHelper, &parameterName[0], param_highSpeed_amax);
  } else {
    *param_highSpeed_amax = 0.15;
  }
  for (int i{0}; i < 41; i++) {
    m_name[i] = n_name[i];
  }
  std::mem_fn (&MATLABROSParameter::isValidPattern)(&lobj_1.ParameterHelper,
                                                    &m_name[0]);
  in.set_size(1, 41);
  for (int i{0}; i < 41; i++) {
    in[i] = n_name[i];
  }
  if (coder::startsWith(in)) {
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
  nameExists = std::mem_fn(&MATLABROSParameter::hasParam)(
      lobj_1.ParameterHelper, &parameterName[0]);
  if (nameExists) {
    for (int i{0}; i < 41; i++) {
      m_name[i] = n_name[i];
    }
    std::mem_fn (&MATLABROSParameter::isValidPattern)(&lobj_1.ParameterHelper,
                                                      &m_name[0]);
    in.set_size(1, 41);
    for (int i{0}; i < 41; i++) {
      in[i] = n_name[i];
    }
    if (coder::startsWith(in)) {
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
    *param_highSpeed_vlmax = 0.0;
    std::mem_fn (&MATLABROSParameter::getParameter<double>)(
        &lobj_1.ParameterHelper, &parameterName[0], param_highSpeed_vlmax);
  } else {
    *param_highSpeed_vlmax = 0.8;
  }
  for (int i{0}; i < 45; i++) {
    k_name[i] = o_name[i];
  }
  std::mem_fn (&MATLABROSParameter::isValidPattern)(&lobj_1.ParameterHelper,
                                                    &k_name[0]);
  in.set_size(1, 45);
  for (int i{0}; i < 45; i++) {
    in[i] = o_name[i];
  }
  if (coder::startsWith(in)) {
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
  nameExists = std::mem_fn(&MATLABROSParameter::hasParam)(
      lobj_1.ParameterHelper, &parameterName[0]);
  if (nameExists) {
    for (int i{0}; i < 45; i++) {
      k_name[i] = o_name[i];
    }
    std::mem_fn (&MATLABROSParameter::isValidPattern)(&lobj_1.ParameterHelper,
                                                      &k_name[0]);
    in.set_size(1, 45);
    for (int i{0}; i < 45; i++) {
      in[i] = o_name[i];
    }
    if (coder::startsWith(in)) {
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
    *param_highSpeed_vamax = 0.0;
    std::mem_fn (&MATLABROSParameter::getParameter<double>)(
        &lobj_1.ParameterHelper, &parameterName[0], param_highSpeed_vamax);
  } else {
    *param_highSpeed_vamax = 0.8;
  }
}

//
// Si on roule en simulation
//
// Arguments    : void
// Return Type  : void
//
void proc_planner()
{
  TrajectoryGenerator TG;
  coder::b_quaternion varargout_2;
  coder::quaternion b_r;
  coder::ros::Publisher trajpub;
  coder::ros::Rate r;
  coder::ros::Subscriber madpSub;
  coder::ros::b_Publisher validPub;
  coder::ros::b_Subscriber icSub;
  coder::waypointTrajectory trajObj;
  coder::array<geometry_msgs_TransformStruct_T, 2U> r1;
  coder::array<geometry_msgs_TwistStruct_T, 2U> r2;
  coder::array<sonia_common_AddPoseStruct_T, 1U> multiAddposeMsg_Pose;
  coder::array<char, 2U> formatSpec;
  coder::array<char, 2U> varargin_1;
  geometry_msgs_TransformStruct_T transformBuff;
  geometry_msgs_TwistStruct_T twistBuff;
  std_msgs_BoolStruct_T validMsg;
  trajectory_msgs_MultiDOFJointTrajectoryPointStruct_T trajMsg;
  double amax;
  double d;
  double icMsg_Orientation_W;
  double icMsg_Orientation_Z;
  double param_highSpeed_amax;
  double param_highSpeed_vamax;
  double param_highSpeed_vlmax;
  double param_lowSpeed_amax;
  double param_lowSpeed_vamax;
  double param_lowSpeed_vlmax;
  double param_normalSpeed_amax;
  double param_normalSpeed_vamax;
  double param_normalSpeed_vlmax;
  double param_ts;
  double tl;
  double vamax;
  double vlmax;
  int i;
  int loop_ub;
  if (!isInitialized_proc_planner) {
    proc_planner_initialize();
  }
  coder::b_getenv(formatSpec);
  varargin_1.set_size(1, formatSpec.size(1) + 1);
  loop_ub = formatSpec.size(1);
  for (i = 0; i < loop_ub; i++) {
    varargin_1[i] = formatSpec[i];
  }
  varargin_1[formatSpec.size(1)] = '\x00';
  printf("INFO : proc planner : Load config for %s \n", &varargin_1[0]);
  fflush(stdout);
  //  Definir les variables
  //  Variables globals
  newMadpPose = false;
  newInitalPose = false;
  //  Variables locals
  r.init();
  //  Definir les message ros
  validMsg = std_msgs_BoolStruct();
  //  Definir les Subscrier ros
  madpSub.init();
  icSub.init();
  //  Definir les publisher ROS
  trajpub.init();
  validPub.init();
  //  Definir les parametre de trajectoire
  getRosParam(&param_ts, &param_lowSpeed_amax, &param_lowSpeed_vlmax,
              &param_lowSpeed_vamax, &param_normalSpeed_amax,
              &param_normalSpeed_vlmax, &param_normalSpeed_vamax,
              &param_highSpeed_amax, &param_highSpeed_vlmax,
              &param_highSpeed_vamax);
  //  Ros Spin
  printf("INFO : proc planner : Node is started \n");
  fflush(stdout);
  printf("INFO : proc planner : Wait for poses \n");
  fflush(stdout);
  MATLABRate_reset(r.RateHelper);
  coder::tic(&amax, &vlmax);
  while (1) {
    if (newMadpPose && newInitalPose) {
      double b_TG[4];
      double bufferQuat[4];
      double q[4];
      double c_TG[3];
      double eul[3];
      double varargout_3[3];
      double b_multiAddposeMsg_Pose[2];
      int exitg2;
      int loop_ub_tmp;
      bool guard1{false};
      //  Cree l'objet trajectoire
      madpSub.get_LatestMessage(multiAddposeMsg_Pose);
      icSub.get_LatestMessage(&amax, &vlmax, &d, &vamax, &tl,
                              &icMsg_Orientation_Z, &icMsg_Orientation_W);
      TG.status = true;
      TG.nbPoint = 1.0;
      // ==================================================================
      //  Constructeur
      //  nombre de waypoints + iC
      b_multiAddposeMsg_Pose[0] = multiAddposeMsg_Pose.size(0);
      b_multiAddposeMsg_Pose[1] = 1.0;
      TG.n = coder::internal::maximum(b_multiAddposeMsg_Pose) + 3.0;
      //  matlab and cpp dont use same index. return max instead
      //  Initialiser les tableaux
      loop_ub_tmp = static_cast<int>(TG.n);
      TG.pointList.set_size(loop_ub_tmp, 3);
      loop_ub = static_cast<int>(TG.n) * 3;
      for (i = 0; i < loop_ub; i++) {
        TG.pointList[i] = 0.0;
      }
      TG.quatList.set_size(loop_ub_tmp, 4);
      loop_ub = static_cast<int>(TG.n) << 2;
      for (i = 0; i < loop_ub; i++) {
        TG.quatList[i] = 0.0;
      }
      TG.timeList.set_size(loop_ub_tmp);
      for (i = 0; i < loop_ub_tmp; i++) {
        TG.timeList[i] = 0.0;
      }
      TG.courseList.set_size(1, loop_ub_tmp);
      for (i = 0; i < loop_ub_tmp; i++) {
        TG.courseList[i] = 0.0;
      }
      TG.speedList.set_size(1, loop_ub_tmp);
      for (i = 0; i < loop_ub_tmp; i++) {
        TG.speedList[i] = 0.0;
      }
      //  Initialiser les parametres
      //  trouver le waypoint initial
      //  Replire les listes.
      // ==================================================================
      //  Fonnction qui retoure le waypoint initial
      TG.pointList[0] = amax;
      TG.pointList[TG.pointList.size(0)] = vlmax;
      TG.pointList[TG.pointList.size(0) * 2] = d;
      TG.quatList[0] = icMsg_Orientation_W;
      TG.quatList[TG.quatList.size(0)] = vamax;
      TG.quatList[TG.quatList.size(0) * 2] = tl;
      TG.quatList[TG.quatList.size(0) * 3] = icMsg_Orientation_Z;
      TG.timeList[0] = 0.0;
      TG.speedList[0] = 0.0;
      b_TG[0] = TG.quatList[0];
      b_TG[1] = TG.quatList[TG.quatList.size(0)];
      b_TG[2] = TG.quatList[TG.quatList.size(0) * 2];
      b_TG[3] = TG.quatList[TG.quatList.size(0) * 3];
      coder::quat2eul(b_TG, c_TG);
      eul[0] = 57.295779513082323 * c_TG[0];
      TG.courseList[0] = eul[0];
      //  Copier le point 2 fois pour forcé accInit a 0.
      TG.pointList[1] = TG.pointList[0];
      TG.pointList[TG.pointList.size(0) + 1] =
          TG.pointList[TG.pointList.size(0)];
      TG.pointList[TG.pointList.size(0) * 2 + 1] =
          TG.pointList[TG.pointList.size(0) * 2];
      TG.quatList[1] = TG.quatList[0];
      TG.quatList[TG.quatList.size(0) + 1] = TG.quatList[TG.quatList.size(0)];
      TG.quatList[TG.quatList.size(0) * 2 + 1] =
          TG.quatList[TG.quatList.size(0) * 2];
      TG.quatList[TG.quatList.size(0) * 3 + 1] =
          TG.quatList[TG.quatList.size(0) * 3];
      TG.timeList[1] = param_ts;
      TG.courseList[1] = eul[0];
      TG.speedList[1] = 0.0;
      //  Process le message addpose
      // ==================================================================
      //  Fonction qui interprete les waypoints reçu par ROS
      loop_ub = 1;
      do {
        exitg2 = 0;
        if (loop_ub - 1 <= static_cast<int>(TG.n - 3.0) - 1) {
          //  pour chaques waypoints
          //  transformer les angle d'euler quaternions
          varargout_3[0] = 0.017453292519943295 *
                           multiAddposeMsg_Pose[loop_ub - 1].Orientation.Z;
          varargout_3[1] = 0.017453292519943295 *
                           multiAddposeMsg_Pose[loop_ub - 1].Orientation.Y;
          varargout_3[2] = 0.017453292519943295 *
                           multiAddposeMsg_Pose[loop_ub - 1].Orientation.X;
          coder::eul2quat(varargout_3, q);
          //  cree le vecteur pose
          amax = multiAddposeMsg_Pose[loop_ub - 1].Position.X;
          eul[0] = amax;
          vlmax = multiAddposeMsg_Pose[loop_ub - 1].Position.Y;
          eul[1] = vlmax;
          d = multiAddposeMsg_Pose[loop_ub - 1].Position.Z;
          eul[2] = d;
          //  transformer le point en fonction du frame
          guard1 = false;
          switch (multiAddposeMsg_Pose[loop_ub - 1].Frame) {
          case 0U:
            //  position et angle absolue
            TG.quatList[static_cast<int>(
                            (static_cast<double>(loop_ub - 1) + 1.0) + 2.0) -
                        1] = q[0];
            TG.quatList[(static_cast<int>(
                             (static_cast<double>(loop_ub - 1) + 1.0) + 2.0) +
                         TG.quatList.size(0)) -
                        1] = q[1];
            TG.quatList[(static_cast<int>(
                             (static_cast<double>(loop_ub - 1) + 1.0) + 2.0) +
                         TG.quatList.size(0) * 2) -
                        1] = q[2];
            TG.quatList[(static_cast<int>(
                             (static_cast<double>(loop_ub - 1) + 1.0) + 2.0) +
                         TG.quatList.size(0) * 3) -
                        1] = q[3];
            TG.pointList[static_cast<int>(
                             (static_cast<double>(loop_ub - 1) + 1.0) + 2.0) -
                         1] = amax;
            TG.pointList[(static_cast<int>(
                              (static_cast<double>(loop_ub - 1) + 1.0) + 2.0) +
                          TG.pointList.size(0)) -
                         1] = vlmax;
            TG.pointList[(static_cast<int>(
                              (static_cast<double>(loop_ub - 1) + 1.0) + 2.0) +
                          TG.pointList.size(0) * 2) -
                         1] = d;
            guard1 = true;
            break;
          case 1U:
            //  position et angle relatif
            //            norm = dot(lq,q);
            //              % conjuger le quaternion au besoin
            //              %if  norm > 1 && dir == 0 || norm < 1 && dir == 1
            //             if  norm < 0  && dir == 0 || norm >= 0 && dir == 1
            //                  q = quatconj(q);
            //                  this.lastConj =true;
            //
            //              end
            // ==================================================================
            //  Fonnction qui retoure le quaternion le plus court/long selon
            //  l'utilisateur
            b_TG[0] = TG.quatList[loop_ub];
            b_TG[1] = TG.quatList[loop_ub + TG.quatList.size(0)];
            b_TG[2] = TG.quatList[loop_ub + TG.quatList.size(0) * 2];
            b_TG[3] = TG.quatList[loop_ub + TG.quatList.size(0) * 3];
            coder::quatmultiply(b_TG, q, bufferQuat);
            TG.quatList[static_cast<int>(
                            (static_cast<double>(loop_ub - 1) + 1.0) + 2.0) -
                        1] = bufferQuat[0];
            TG.quatList[(static_cast<int>(
                             (static_cast<double>(loop_ub - 1) + 1.0) + 2.0) +
                         TG.quatList.size(0)) -
                        1] = bufferQuat[1];
            TG.quatList[(static_cast<int>(
                             (static_cast<double>(loop_ub - 1) + 1.0) + 2.0) +
                         TG.quatList.size(0) * 2) -
                        1] = bufferQuat[2];
            TG.quatList[(static_cast<int>(
                             (static_cast<double>(loop_ub - 1) + 1.0) + 2.0) +
                         TG.quatList.size(0) * 3) -
                        1] = bufferQuat[3];
            // =================================================================
            //  Fonction qui tourne un vecteur selon un quaternion.
            //  quaternion partie scalaire
            //  quaternion partie vectoriel
            //  QuatRotate n'est pas compilable
            c_TG[0] = TG.quatList[loop_ub + TG.quatList.size(0)];
            c_TG[1] = TG.quatList[loop_ub + TG.quatList.size(0) * 2];
            c_TG[2] = TG.quatList[loop_ub + TG.quatList.size(0) * 3];
            tl = 2.0 * coder::dot(c_TG, eul);
            c_TG[0] = TG.quatList[loop_ub + TG.quatList.size(0)];
            varargout_3[0] = TG.quatList[loop_ub + TG.quatList.size(0)];
            c_TG[1] = TG.quatList[loop_ub + TG.quatList.size(0) * 2];
            varargout_3[1] = TG.quatList[loop_ub + TG.quatList.size(0) * 2];
            c_TG[2] = TG.quatList[loop_ub + TG.quatList.size(0) * 3];
            varargout_3[2] = TG.quatList[loop_ub + TG.quatList.size(0) * 3];
            icMsg_Orientation_Z = TG.quatList[loop_ub] * TG.quatList[loop_ub] -
                                  coder::dot(c_TG, varargout_3);
            vamax = 2.0 * TG.quatList[loop_ub];
            TG.pointList[static_cast<int>(
                             (static_cast<double>(loop_ub - 1) + 1.0) + 2.0) -
                         1] =
                TG.pointList[static_cast<int>(
                                 (static_cast<double>(loop_ub - 1) + 1.0) +
                                 1.0) -
                             1] +
                ((tl * TG.quatList[loop_ub + TG.quatList.size(0)] +
                  icMsg_Orientation_Z * amax) +
                 vamax * (TG.quatList[loop_ub + TG.quatList.size(0) * 2] *
                              multiAddposeMsg_Pose[loop_ub - 1].Position.Z -
                          multiAddposeMsg_Pose[loop_ub - 1].Position.Y *
                              TG.quatList[loop_ub + TG.quatList.size(0) * 3]));
            TG.pointList[(static_cast<int>(
                              (static_cast<double>(loop_ub - 1) + 1.0) + 2.0) +
                          TG.pointList.size(0)) -
                         1] =
                TG.pointList[(static_cast<int>(
                                  (static_cast<double>(loop_ub - 1) + 1.0) +
                                  1.0) +
                              TG.pointList.size(0)) -
                             1] +
                ((tl * TG.quatList[loop_ub + TG.quatList.size(0) * 2] +
                  icMsg_Orientation_Z * vlmax) +
                 vamax * (multiAddposeMsg_Pose[loop_ub - 1].Position.X *
                              TG.quatList[loop_ub + TG.quatList.size(0) * 3] -
                          TG.quatList[loop_ub + TG.quatList.size(0)] *
                              multiAddposeMsg_Pose[loop_ub - 1].Position.Z));
            TG.pointList[(static_cast<int>(
                              (static_cast<double>(loop_ub - 1) + 1.0) + 2.0) +
                          TG.pointList.size(0) * 2) -
                         1] =
                TG.pointList[(static_cast<int>(
                                  (static_cast<double>(loop_ub - 1) + 1.0) +
                                  1.0) +
                              TG.pointList.size(0) * 2) -
                             1] +
                ((tl * TG.quatList[loop_ub + TG.quatList.size(0) * 3] +
                  icMsg_Orientation_Z * d) +
                 vamax * (TG.quatList[loop_ub + TG.quatList.size(0)] *
                              multiAddposeMsg_Pose[loop_ub - 1].Position.Y -
                          multiAddposeMsg_Pose[loop_ub - 1].Position.X *
                              TG.quatList[loop_ub + TG.quatList.size(0) * 2]));
            guard1 = true;
            break;
          case 2U:
            //  position relatif et angle absolue
            TG.quatList[static_cast<int>(
                            (static_cast<double>(loop_ub - 1) + 1.0) + 2.0) -
                        1] = q[0];
            TG.quatList[(static_cast<int>(
                             (static_cast<double>(loop_ub - 1) + 1.0) + 2.0) +
                         TG.quatList.size(0)) -
                        1] = q[1];
            TG.quatList[(static_cast<int>(
                             (static_cast<double>(loop_ub - 1) + 1.0) + 2.0) +
                         TG.quatList.size(0) * 2) -
                        1] = q[2];
            TG.quatList[(static_cast<int>(
                             (static_cast<double>(loop_ub - 1) + 1.0) + 2.0) +
                         TG.quatList.size(0) * 3) -
                        1] = q[3];
            // =================================================================
            //  Fonction qui tourne un vecteur selon un quaternion.
            //  quaternion partie scalaire
            //  quaternion partie vectoriel
            //  QuatRotate n'est pas compilable
            c_TG[0] = TG.quatList[loop_ub + TG.quatList.size(0)];
            c_TG[1] = TG.quatList[loop_ub + TG.quatList.size(0) * 2];
            c_TG[2] = TG.quatList[loop_ub + TG.quatList.size(0) * 3];
            tl = 2.0 * coder::dot(c_TG, eul);
            c_TG[0] = TG.quatList[loop_ub + TG.quatList.size(0)];
            varargout_3[0] = TG.quatList[loop_ub + TG.quatList.size(0)];
            c_TG[1] = TG.quatList[loop_ub + TG.quatList.size(0) * 2];
            varargout_3[1] = TG.quatList[loop_ub + TG.quatList.size(0) * 2];
            c_TG[2] = TG.quatList[loop_ub + TG.quatList.size(0) * 3];
            varargout_3[2] = TG.quatList[loop_ub + TG.quatList.size(0) * 3];
            icMsg_Orientation_Z = TG.quatList[loop_ub] * TG.quatList[loop_ub] -
                                  coder::dot(c_TG, varargout_3);
            vamax = 2.0 * TG.quatList[loop_ub];
            TG.pointList[static_cast<int>(
                             (static_cast<double>(loop_ub - 1) + 1.0) + 2.0) -
                         1] =
                TG.pointList[static_cast<int>(
                                 (static_cast<double>(loop_ub - 1) + 1.0) +
                                 1.0) -
                             1] +
                ((tl * TG.quatList[loop_ub + TG.quatList.size(0)] +
                  icMsg_Orientation_Z * amax) +
                 vamax *
                     (TG.quatList[loop_ub + TG.quatList.size(0) * 2] * d -
                      vlmax * TG.quatList[loop_ub + TG.quatList.size(0) * 3]));
            TG.pointList[(static_cast<int>(
                              (static_cast<double>(loop_ub - 1) + 1.0) + 2.0) +
                          TG.pointList.size(0)) -
                         1] =
                TG.pointList[(static_cast<int>(
                                  (static_cast<double>(loop_ub - 1) + 1.0) +
                                  1.0) +
                              TG.pointList.size(0)) -
                             1] +
                ((tl * TG.quatList[loop_ub + TG.quatList.size(0) * 2] +
                  icMsg_Orientation_Z * vlmax) +
                 vamax *
                     (amax * TG.quatList[loop_ub + TG.quatList.size(0) * 3] -
                      TG.quatList[loop_ub + TG.quatList.size(0)] * d));
            TG.pointList[(static_cast<int>(
                              (static_cast<double>(loop_ub - 1) + 1.0) + 2.0) +
                          TG.pointList.size(0) * 2) -
                         1] =
                TG.pointList[(static_cast<int>(
                                  (static_cast<double>(loop_ub - 1) + 1.0) +
                                  1.0) +
                              TG.pointList.size(0) * 2) -
                             1] +
                ((tl * TG.quatList[loop_ub + TG.quatList.size(0) * 3] +
                  icMsg_Orientation_Z * d) +
                 vamax *
                     (TG.quatList[loop_ub + TG.quatList.size(0)] * vlmax -
                      amax * TG.quatList[loop_ub + TG.quatList.size(0) * 2]));
            guard1 = true;
            break;
          case 3U:
            //  position absolue et angle relatif
            //            norm = dot(lq,q);
            //              % conjuger le quaternion au besoin
            //              %if  norm > 1 && dir == 0 || norm < 1 && dir == 1
            //             if  norm < 0  && dir == 0 || norm >= 0 && dir == 1
            //                  q = quatconj(q);
            //                  this.lastConj =true;
            //
            //              end
            // ==================================================================
            //  Fonnction qui retoure le quaternion le plus court/long selon
            //  l'utilisateur
            b_TG[0] = TG.quatList[loop_ub];
            b_TG[1] = TG.quatList[loop_ub + TG.quatList.size(0)];
            b_TG[2] = TG.quatList[loop_ub + TG.quatList.size(0) * 2];
            b_TG[3] = TG.quatList[loop_ub + TG.quatList.size(0) * 3];
            coder::quatmultiply(b_TG, q, bufferQuat);
            TG.quatList[static_cast<int>(
                            (static_cast<double>(loop_ub - 1) + 1.0) + 2.0) -
                        1] = bufferQuat[0];
            TG.quatList[(static_cast<int>(
                             (static_cast<double>(loop_ub - 1) + 1.0) + 2.0) +
                         TG.quatList.size(0)) -
                        1] = bufferQuat[1];
            TG.quatList[(static_cast<int>(
                             (static_cast<double>(loop_ub - 1) + 1.0) + 2.0) +
                         TG.quatList.size(0) * 2) -
                        1] = bufferQuat[2];
            TG.quatList[(static_cast<int>(
                             (static_cast<double>(loop_ub - 1) + 1.0) + 2.0) +
                         TG.quatList.size(0) * 3) -
                        1] = bufferQuat[3];
            TG.pointList[static_cast<int>(
                             (static_cast<double>(loop_ub - 1) + 1.0) + 2.0) -
                         1] = amax;
            TG.pointList[(static_cast<int>(
                              (static_cast<double>(loop_ub - 1) + 1.0) + 2.0) +
                          TG.pointList.size(0)) -
                         1] = vlmax;
            TG.pointList[(static_cast<int>(
                              (static_cast<double>(loop_ub - 1) + 1.0) + 2.0) +
                          TG.pointList.size(0) * 2) -
                         1] = d;
            guard1 = true;
            break;
          default:
            //  Le referentiel n'est pas valide
            TG.status = false;
            printf("INFO : proc planner : Waypoints are not valid  \n");
            fflush(stdout);
            exitg2 = 1;
            break;
          }
          if (guard1) {
            //  copier le parametre de vitesse
            TG.speedList[static_cast<int>(
                             (static_cast<double>(loop_ub - 1) + 1.0) + 2.0) -
                         1] = multiAddposeMsg_Pose[loop_ub - 1].Speed;
            //  determiner le yaw pour le vecteur course
            b_TG[0] = TG.quatList[loop_ub + 1];
            b_TG[1] = TG.quatList[(loop_ub + TG.quatList.size(0)) + 1];
            b_TG[2] = TG.quatList[(loop_ub + TG.quatList.size(0) * 2) + 1];
            b_TG[3] = TG.quatList[(loop_ub + TG.quatList.size(0) * 3) + 1];
            coder::quat2eul(b_TG, c_TG);
            eul[0] = 57.295779513082323 * c_TG[0];
            if (eul[0] < 0.0) {
              eul[0] += 360.0;
            }
            TG.courseList[static_cast<int>(
                              (static_cast<double>(loop_ub - 1) + 1.0) + 2.0) -
                          1] = eul[0];
            loop_ub++;
          }
        } else {
          //  Copier le dernier waypoint 2 fois pour éviter un comportement
          //  du generateur de trajecteur
          loop_ub = TG.pointList.size(0) - 1;
          c_TG[1] =
              TG.pointList[(TG.pointList.size(0) + TG.pointList.size(0)) - 2];
          c_TG[2] =
              TG.pointList[(TG.pointList.size(0) + TG.pointList.size(0) * 2) -
                           2];
          TG.pointList[TG.pointList.size(0) - 1] =
              TG.pointList[TG.pointList.size(0) - 2];
          TG.pointList[loop_ub + TG.pointList.size(0)] = c_TG[1];
          TG.pointList[loop_ub + TG.pointList.size(0) * 2] = c_TG[2];
          loop_ub = TG.quatList.size(0) - 1;
          b_TG[1] =
              TG.quatList[(TG.quatList.size(0) + TG.quatList.size(0)) - 2];
          b_TG[2] =
              TG.quatList[(TG.quatList.size(0) + TG.quatList.size(0) * 2) - 2];
          b_TG[3] =
              TG.quatList[(TG.quatList.size(0) + TG.quatList.size(0) * 3) - 2];
          TG.quatList[TG.quatList.size(0) - 1] =
              TG.quatList[TG.quatList.size(0) - 2];
          TG.quatList[loop_ub + TG.quatList.size(0)] = b_TG[1];
          TG.quatList[loop_ub + TG.quatList.size(0) * 2] = b_TG[2];
          TG.quatList[loop_ub + TG.quatList.size(0) * 3] = b_TG[3];
          TG.courseList[TG.courseList.size(1) - 1] =
              TG.courseList[TG.courseList.size(1) - 2];
          TG.speedList[TG.speedList.size(1) - 1] = static_cast<unsigned char>(
              TG.speedList[TG.speedList.size(1) - 2]);
          //  Calculer les temps entre chaque waypoints
          // ==================================================================
          //  Fonnction qui calcul le temps entre chaque waypoint
          loop_ub = 1;
          exitg2 = 2;
        }
      } while (exitg2 == 0);
      if (exitg2 != 1) {
        int exitg1;
        do {
          exitg1 = 0;
          if (loop_ub - 1 <= static_cast<int>(TG.n + -1.0) - 1) {
            //  pour chaques waypoints
            //  Determiner le parametre de vitesse
            guard1 = false;
            switch (static_cast<unsigned char>(TG.speedList[loop_ub])) {
            case 0:
              //  Vitesse normale
              amax = param_normalSpeed_amax;
              vlmax = param_normalSpeed_vlmax;
              vamax = param_normalSpeed_vamax;
              guard1 = true;
              break;
            case 1:
              //  Vitesse rapide
              amax = param_highSpeed_amax;
              vlmax = param_highSpeed_vlmax;
              vamax = param_highSpeed_vamax;
              guard1 = true;
              break;
            case 2:
              //  Vitesse lente
              amax = param_lowSpeed_amax;
              vlmax = param_lowSpeed_vlmax;
              vamax = param_lowSpeed_vamax;
              guard1 = true;
              break;
            default:
              //  mode non reconue.
              printf("INFO : proc planner : Speed parameter not recognized \n");
              fflush(stdout);
              TG.status = false;
              exitg1 = 1;
              break;
            }
            if (guard1) {
              //  Trouver la distance Eucledienne entre 2 points
              c_TG[0] =
                  TG.pointList[loop_ub] -
                  TG.pointList[static_cast<int>(
                                   (static_cast<double>(loop_ub - 1) + 2.0) -
                                   1.0) -
                               1];
              c_TG[1] =
                  TG.pointList[loop_ub + TG.pointList.size(0)] -
                  TG.pointList[(static_cast<int>(
                                    (static_cast<double>(loop_ub - 1) + 2.0) -
                                    1.0) +
                                TG.pointList.size(0)) -
                               1];
              c_TG[2] =
                  TG.pointList[loop_ub + TG.pointList.size(0) * 2] -
                  TG.pointList[(static_cast<int>(
                                    (static_cast<double>(loop_ub - 1) + 2.0) -
                                    1.0) +
                                TG.pointList.size(0) * 2) -
                               1];
              d = coder::b_norm(c_TG);
              //  Déterminer le temps selon aMax
              tl = 4.0 * std::sqrt(3.0 * d) / (3.0 * std::sqrt(amax));
              //  Déterminer la vitesse maximum de la trajectoire
              //  Si la vitesse est plus grande que la vitesse maximum
              if (amax * tl / 4.0 > vlmax) {
                //  Calculer le temps selon vmax
                tl = 4.0 * d / (3.0 * vlmax);
              }
              //  Déterminer l'angle entre les 2 quaternions
              q[0] = TG.quatList[static_cast<int>(
                                     (static_cast<double>(loop_ub - 1) + 2.0) -
                                     1.0) -
                                 1];
              q[1] = TG.quatList[(static_cast<int>(
                                      (static_cast<double>(loop_ub - 1) + 2.0) -
                                      1.0) +
                                  TG.quatList.size(0)) -
                                 1];
              q[2] = TG.quatList[(static_cast<int>(
                                      (static_cast<double>(loop_ub - 1) + 2.0) -
                                      1.0) +
                                  TG.quatList.size(0) * 2) -
                                 1];
              q[3] = TG.quatList[(static_cast<int>(
                                      (static_cast<double>(loop_ub - 1) + 2.0) -
                                      1.0) +
                                  TG.quatList.size(0) * 3) -
                                 1];
              q[1] = -q[1];
              q[2] = -q[2];
              q[3] = -q[3];
              b_TG[0] = TG.quatList[loop_ub];
              b_TG[1] = TG.quatList[loop_ub + TG.quatList.size(0)];
              b_TG[2] = TG.quatList[loop_ub + TG.quatList.size(0) * 2];
              b_TG[3] = TG.quatList[loop_ub + TG.quatList.size(0) * 3];
              coder::quatmultiply(q, b_TG, bufferQuat);
              //  Déterminer le temps angulaire
              amax = coder::b_norm(*(double(*)[3]) & bufferQuat[1]);
              varargout_3[0] = tl;
              varargout_3[1] = 2.0 * rt_atan2d_snf(amax, bufferQuat[0]) / vamax;
              varargout_3[2] = param_ts;
              TG.timeList[loop_ub] =
                  TG.timeList[static_cast<int>(
                                  (static_cast<double>(loop_ub - 1) + 2.0) -
                                  1.0) -
                              1] +
                  coder::internal::b_maximum(varargout_3);
              loop_ub++;
            }
          } else {
            //  Déterminer le nombre de points
            TG.nbPoint =
                std::floor(TG.timeList[TG.timeList.size(0) - 1] / param_ts);
            exitg1 = 1;
          }
        } while (exitg1 == 0);
      }
      //  Envoyer a ros si le mAddpose est valide
      validMsg.Data = TG.status;
      MATLABPUBLISHER_publish(validPub.PublisherHelper, &validMsg);
      //  Si la trajectoire est valide
      if (TG.status) {
        short i1;
        //  Interpoler les waypoints
        // ==================================================================
        //  Fonction Main qui génère les waypoints
        //  Crée l'objet waypoint trajectory
        // ==================================================================
        //  Fonnction qui interpole les waypoints
        b_r.init(TG.quatList);
        trajObj.init(TG.pointList, TG.timeList, 1.0 / param_ts, &b_r,
                     TG.courseList);
        //  Initialiser le message trajectoire.
        trajectory_msgs_MultiDOFJointTrajectoryPointStruct(&trajMsg);
        //  message point
        geometry_msgs_TransformStruct(&transformBuff);
        //  trajectoire
        geometry_msgs_TwistStruct(&twistBuff);
        //  trajectoire
        //  initialiser la dimention vecteur de points
        coder::repelem(&transformBuff, TG.nbPoint, r1);
        trajMsg.Transforms.set_size(r1.size(1));
        loop_ub = r1.size(1);
        for (i = 0; i < loop_ub; i++) {
          trajMsg.Transforms[i] = r1[i];
        }
        coder::repelem(&twistBuff, TG.nbPoint, r2);
        trajMsg.Velocities.set_size(r2.size(1));
        loop_ub = r2.size(1);
        for (i = 0; i < loop_ub; i++) {
          trajMsg.Velocities[i] = r2[i];
        }
        coder::repelem(&twistBuff, TG.nbPoint, r2);
        trajMsg.Accelerations.set_size(r2.size(1));
        loop_ub = r2.size(1);
        for (i = 0; i < loop_ub; i++) {
          trajMsg.Accelerations[i] = r2[i];
        }
        q[0] = 0.0;
        q[1] = 0.0;
        q[2] = 0.0;
        q[3] = 0.0;
        //  Générer les points de la trajectoire
        i = static_cast<int>(TG.nbPoint);
        for (loop_ub = 0; loop_ub < i; loop_ub++) {
          double varargout_5[3];
          trajObj.step(eul, &varargout_2, varargout_3, c_TG, varargout_5);
          //  Remplire le message Transform.
          transformBuff.Translation.X = eul[0];
          transformBuff.Translation.Y = eul[1];
          transformBuff.Translation.Z = eul[2];
          //  Convertir l'objet quaternion en vecteur
          bufferQuat[0] = varargout_2.a;
          bufferQuat[1] = varargout_2.b;
          bufferQuat[2] = varargout_2.c;
          bufferQuat[3] = varargout_2.d;
          //  Verifier de retourner la rotation la plus petite
          if ((loop_ub + 1U > 1U) && (coder::b_dot(q, bufferQuat) < 0.0)) {
            bufferQuat[0] = -varargout_2.a;
            bufferQuat[1] = -varargout_2.b;
            bufferQuat[2] = -varargout_2.c;
            bufferQuat[3] = -varargout_2.d;
          }
          q[0] = bufferQuat[0];
          q[1] = bufferQuat[1];
          q[2] = bufferQuat[2];
          q[3] = bufferQuat[3];
          transformBuff.Rotation.W = bufferQuat[0];
          transformBuff.Rotation.X = bufferQuat[1];
          transformBuff.Rotation.Y = bufferQuat[2];
          transformBuff.Rotation.Z = bufferQuat[3];
          trajMsg.Transforms[loop_ub] = transformBuff;
          //  Convertir les vitesse dans le ref sub
          // =================================================================
          //  Fonction qui tourne un vecteur selon un quaternion.
          //  quaternion partie scalaire
          //  quaternion partie vectoriel
          //  QuatRotate n'est pas compilable
          tl = 2.0 * coder::dot(*(double(*)[3]) & bufferQuat[1], varargout_3);
          icMsg_Orientation_Z = bufferQuat[0] * bufferQuat[0] -
                                coder::dot(*(double(*)[3]) & bufferQuat[1],
                                           *(double(*)[3]) & bufferQuat[1]);
          amax = 2.0 * bufferQuat[0];
          //  Remplire les vitesse
          twistBuff.Linear.X =
              (tl * bufferQuat[1] + icMsg_Orientation_Z * varargout_3[0]) +
              amax * (bufferQuat[2] * varargout_3[2] -
                      varargout_3[1] * bufferQuat[3]);
          twistBuff.Linear.Y =
              (tl * bufferQuat[2] + icMsg_Orientation_Z * varargout_3[1]) +
              amax * (varargout_3[0] * bufferQuat[3] -
                      bufferQuat[1] * varargout_3[2]);
          twistBuff.Linear.Z =
              (tl * bufferQuat[3] + icMsg_Orientation_Z * varargout_3[2]) +
              amax * (bufferQuat[1] * varargout_3[1] -
                      varargout_3[0] * bufferQuat[2]);
          twistBuff.Angular.X = -varargout_5[0];
          //  (-) pour convertir les vitesse angulaire dans le ref sub
          twistBuff.Angular.Y = -varargout_5[1];
          twistBuff.Angular.Z = -varargout_5[2];
          trajMsg.Velocities[loop_ub] = twistBuff;
          //  Ecrire le point dans le message
          //  Convertir les accels dans le ref sub
          // =================================================================
          //  Fonction qui tourne un vecteur selon un quaternion.
          //  quaternion partie scalaire
          //  quaternion partie vectoriel
          //  QuatRotate n'est pas compilable
          tl = 2.0 * coder::dot(*(double(*)[3]) & bufferQuat[1], c_TG);
          icMsg_Orientation_Z = bufferQuat[0] * bufferQuat[0] -
                                coder::dot(*(double(*)[3]) & bufferQuat[1],
                                           *(double(*)[3]) & bufferQuat[1]);
          //  Remplire les acceleration
          twistBuff.Linear.X =
              (tl * bufferQuat[1] + icMsg_Orientation_Z * c_TG[0]) +
              amax * (bufferQuat[2] * c_TG[2] - c_TG[1] * bufferQuat[3]);
          twistBuff.Linear.Y =
              (tl * bufferQuat[2] + icMsg_Orientation_Z * c_TG[1]) +
              amax * (c_TG[0] * bufferQuat[3] - bufferQuat[1] * c_TG[2]);
          twistBuff.Linear.Z =
              (tl * bufferQuat[3] + icMsg_Orientation_Z * c_TG[2]) +
              amax * (bufferQuat[1] * c_TG[1] - c_TG[0] * bufferQuat[2]);
          twistBuff.Angular.X = 0.0;
          twistBuff.Angular.Y = 0.0;
          twistBuff.Angular.Z = 0.0;
          trajMsg.Accelerations[loop_ub] = twistBuff;
        }
        //  Envoyer le message
        MATLABPUBLISHER_publish(trajpub.PublisherHelper, &trajMsg);
        if (TG.nbPoint < 32768.0) {
          if (TG.nbPoint >= -32768.0) {
            i1 = static_cast<short>(TG.nbPoint);
          } else {
            i1 = MIN_int16_T;
          }
        } else if (TG.nbPoint >= 32768.0) {
          i1 = MAX_int16_T;
        } else {
          i1 = 0;
        }
        printf("INFO : proc planner : Trajectory generation succeded with %d "
               "points. \n",
               i1);
        fflush(stdout);
        //  Si on roule en simulation
        //  Retourner true (sucess)
      }
      newMadpPose = false;
      newInitalPose = false;
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
