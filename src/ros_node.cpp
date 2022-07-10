//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: ros_node.cpp
//
// MATLAB Coder version            : 5.4
// C/C++ source code generated on  : 25-Jun-2022 15:23:16
//

// Include Files
#include "ros_node.h"
#include "Publisher.h"
#include "Rate.h"
#include "Subscriber.h"
#include "TrajectoryGenerator.h"
#include "colon.h"
#include "diff.h"
#include "geometry_msgs_TransformStruct.h"
#include "geometry_msgs_TwistStruct.h"
#include "interp1.h"
#include "norm.h"
#include "pinv.h"
#include "proc_planner_data.h"
#include "proc_planner_internal_types.h"
#include "proc_planner_types.h"
#include "repelem.h"
#include "rt_nonfinite.h"
#include "std_msgs_Int8Struct.h"
#include "tic.h"
#include "toc.h"
#include "trajectory_msgs_MultiDOFJointTrajectoryPointStruct.h"
#include "coder_array.h"
#include "coder_posix_time.h"
#include "mlroscpp_pub.h"
#include "mlroscpp_rate.h"
#include <cmath>
#include <stdio.h>

// Function Definitions
//
// Arguments    : void
// Return Type  : void
//
void ros_node::persistentDataStore_init()
{
  newMadpPose = false;
  newInitialPose = false;
}

//
// Arguments    : coder::ros::Rate *b_spin
// Return Type  : void
//
void ros_node::spin(coder::ros::Rate *b_spin)
{
  static const signed char b[9]{1, 0, 0, 0, 1, 0, 0, 0, 1};
  TrajectoryGenerator TG;
  coder::ros::Publisher *b_trajpub;
  coder::ros::b_Publisher *obj;
  coder::array<geometry_msgs_TransformStruct_T, 2U> y;
  coder::array<geometry_msgs_TwistStruct_T, 2U> r1;
  coder::array<sonia_common_AddPoseStruct_T, 1U> t2_Pose;
  coder::array<double, 2U> qdot;
  coder::array<double, 2U> t;
  coder::array<double, 2U> trajList;
  coder::array<double, 1U> pointList;
  coder::array<double, 1U> timeList;
  coder::array<int, 1U> r;
  b_struct_T b_this;
  geometry_msgs_PointStruct_T t3_Position;
  geometry_msgs_QuaternionStruct_T t3_Orientation;
  geometry_msgs_TransformStruct_T transformBuff;
  geometry_msgs_TwistStruct_T twistBuff;
  std_msgs_Int8Struct_T validMsg;
  trajectory_msgs_MultiDOFJointTrajectoryPointStruct_T trajMsg;
  double dv[9];
  double b_expl_temp;
  double expl_temp;
  char t2_MessageType[25];
  unsigned char t2_InterpolationMethod;
  //  Ros Spin
  validMsg = std_msgs_Int8Struct();
  MATLABRate_reset(b_spin->RateHelper);
  coder::tic(&expl_temp, &b_expl_temp);
  printf("INFO : proc planner : Node is started \n");
  fflush(stdout);
  printf("INFO : proc planner : Wait for poses \n");
  fflush(stdout);
  while (1) {
    bool out;
    //  Regarder si un nouveau multi-addPose
    //  initialte variables
    //  GET
    out = newMadpPose;
    if (!out) {
      //  initialte variables
      //  SET
      newInitialPose = false;
    } else if (TrajIsGenerating) {
      TrajIsGenerating = false;
    } else {
      //  initialte variables
      //  GET
      out = newInitialPose;
      if (out) {
        signed char i;
        printf("INFO : proc planner : Initial poses received \n");
        fflush(stdout);
        TrajIsGenerating = true;
        //  Cree l'objet trajectoire
        madpSub->get_LatestMessage(t2_MessageType, &t2_InterpolationMethod,
                                   t2_Pose);
        icSub->get_LatestMessage(&t3_Position, &t3_Orientation);
        b_this = param;
        TG.init(t2_MessageType, t2_InterpolationMethod, t2_Pose, &b_this,
                t3_Position, t3_Orientation);
        //  Envoyer a ros si le mAddpose est valide
        expl_temp = std::round(TG.status);
        if (expl_temp < 128.0) {
          if (expl_temp >= -128.0) {
            i = static_cast<signed char>(expl_temp);
          } else {
            i = MIN_int8_T;
          }
        } else if (expl_temp >= 128.0) {
          i = MAX_int8_T;
        } else {
          i = 0;
        }
        validMsg.Data = i;
        obj = validPub;
        MATLABPUBLISHER_publish(obj->PublisherHelper, &validMsg);
        //  Si la trajectoire est valide generer la trajectoire
        if (TG.status == 0.0) {
          b_trajpub = trajpub;
          // Vérifier la pré-validation
          // ==================================================================
          //  Fonction Main qui génère les waypoints
          if (TG.status == 0.0) {
            double a;
            int i1;
            int loop_ub;
            short validatedHoleFilling_idx_0;
            //  Interpoler les waypoints
            //  vecteur temps
            // ==================================================================
            //  Fonction qui interpole les waypoints
            a = TG.param.ts;
            expl_temp = TG.param.ts;
            b_expl_temp = TG.timeList[TG.timeList.size(0) - 1];
            if (std::isnan(a) || std::isnan(expl_temp) ||
                std::isnan(b_expl_temp)) {
              t.set_size(1, 1);
              t[0] = rtNaN;
            } else if ((expl_temp == 0.0) ||
                       ((a < b_expl_temp) && (expl_temp < 0.0)) ||
                       ((b_expl_temp < a) && (expl_temp > 0.0))) {
              t.set_size(1, 0);
            } else if ((std::isinf(a) || std::isinf(b_expl_temp)) &&
                       (std::isinf(expl_temp) || (a == b_expl_temp))) {
              t.set_size(1, 1);
              t[0] = rtNaN;
            } else if (std::isinf(expl_temp)) {
              t.set_size(1, 1);
              t[0] = a;
            } else if ((std::floor(a) == a) &&
                       (std::floor(expl_temp) == expl_temp)) {
              loop_ub = static_cast<int>((b_expl_temp - a) / expl_temp);
              t.set_size(1, loop_ub + 1);
              for (i1 = 0; i1 <= loop_ub; i1++) {
                t[i1] = a + expl_temp * static_cast<double>(i1);
              }
            } else {
              coder::eml_float_colon(a, expl_temp, b_expl_temp, t);
            }
            //  Interpoler la trajectoire lineaire
            loop_ub = TG.trajPosition.size(0);
            r.set_size(loop_ub);
            for (i1 = 0; i1 < loop_ub; i1++) {
              r[i1] = i1;
            }
            timeList.set_size(TG.timeList.size(0));
            loop_ub = TG.timeList.size(0);
            for (i1 = 0; i1 < loop_ub; i1++) {
              timeList[i1] = TG.timeList[i1];
            }
            loop_ub = TG.pointList.size(0);
            pointList.set_size(loop_ub);
            for (i1 = 0; i1 < loop_ub; i1++) {
              pointList[i1] = TG.pointList[i1];
            }
            //  Le parametre verif permet au constructeur de verifier si le mode
            //  existe sans interpoler. Determiner le type d'imterpolation
            // ==================================================================
            //  Fonction qui envoie les message sur ros
            switch (TG.MAPM.InterpolationMethod) {
            case 0U:
              //  piecewise cubic interpolation
              coder::interp1(timeList, pointList, t, trajList);
              break;
            case 1U:
              //  spline
              coder::b_interp1(timeList, pointList, t, trajList);
              break;
            case 2U:
              //  Cubic convolution
              coder::c_interp1(timeList, pointList, t, trajList);
              break;
            default:
              trajList.set_size(1, 1);
              trajList[0] = 0.0;
              break;
            }
            loop_ub = trajList.size(1);
            for (i1 = 0; i1 < loop_ub; i1++) {
              TG.trajPosition[r[i1]] = trajList[i1];
            }
            loop_ub = TG.trajPosition.size(0);
            r.set_size(loop_ub);
            for (i1 = 0; i1 < loop_ub; i1++) {
              r[i1] = i1;
            }
            timeList.set_size(TG.timeList.size(0));
            loop_ub = TG.timeList.size(0);
            for (i1 = 0; i1 < loop_ub; i1++) {
              timeList[i1] = TG.timeList[i1];
            }
            loop_ub = TG.pointList.size(0);
            pointList.set_size(loop_ub);
            for (i1 = 0; i1 < loop_ub; i1++) {
              pointList[i1] = TG.pointList[i1 + TG.pointList.size(0)];
            }
            //  Le parametre verif permet au constructeur de verifier si le mode
            //  existe sans interpoler. Determiner le type d'imterpolation
            // ==================================================================
            //  Fonction qui envoie les message sur ros
            switch (TG.MAPM.InterpolationMethod) {
            case 0U:
              //  piecewise cubic interpolation
              coder::interp1(timeList, pointList, t, trajList);
              break;
            case 1U:
              //  spline
              coder::b_interp1(timeList, pointList, t, trajList);
              break;
            case 2U:
              //  Cubic convolution
              coder::c_interp1(timeList, pointList, t, trajList);
              break;
            default:
              trajList.set_size(1, 1);
              trajList[0] = 0.0;
              break;
            }
            loop_ub = trajList.size(1);
            for (i1 = 0; i1 < loop_ub; i1++) {
              TG.trajPosition[r[i1] + TG.trajPosition.size(0)] = trajList[i1];
            }
            loop_ub = TG.trajPosition.size(0);
            r.set_size(loop_ub);
            for (i1 = 0; i1 < loop_ub; i1++) {
              r[i1] = i1;
            }
            loop_ub = TG.pointList.size(0);
            pointList.set_size(loop_ub);
            for (i1 = 0; i1 < loop_ub; i1++) {
              pointList[i1] = TG.pointList[i1 + TG.pointList.size(0) * 2];
            }
            coder::interp1(TG.timeList, pointList, t, trajList);
            timeList.set_size(trajList.size(1));
            loop_ub = trajList.size(1);
            for (i1 = 0; i1 < loop_ub; i1++) {
              timeList[i1] = trajList[i1];
            }
            loop_ub = timeList.size(0);
            for (i1 = 0; i1 < loop_ub; i1++) {
              TG.trajPosition[r[i1] + TG.trajPosition.size(0) * 2] =
                  timeList[i1];
            }
            //  par sécurité, on ne veux pas de courbe en z. laissez pchip
            //  Deriver la trajectoire pour avoir les vitesse linéare;
            loop_ub = TG.trajBodyVelocity.size(0);
            r.set_size(loop_ub);
            for (i1 = 0; i1 < loop_ub; i1++) {
              r[i1] = i1;
            }
            loop_ub = TG.trajPosition.size(0);
            pointList.set_size(loop_ub);
            for (i1 = 0; i1 < loop_ub; i1++) {
              pointList[i1] = TG.trajPosition[i1];
            }
            coder::diff(pointList, timeList);
            pointList.set_size(timeList.size(0) + 1);
            pointList[0] = 0.0;
            loop_ub = timeList.size(0);
            for (i1 = 0; i1 < loop_ub; i1++) {
              pointList[i1 + 1] = timeList[i1];
            }
            loop_ub = pointList.size(0);
            for (i1 = 0; i1 < loop_ub; i1++) {
              TG.trajBodyVelocity[r[i1]] = pointList[i1];
            }
            loop_ub = TG.trajBodyVelocity.size(0);
            r.set_size(loop_ub);
            for (i1 = 0; i1 < loop_ub; i1++) {
              r[i1] = i1;
            }
            loop_ub = TG.trajPosition.size(0);
            pointList.set_size(loop_ub);
            for (i1 = 0; i1 < loop_ub; i1++) {
              pointList[i1] = TG.trajPosition[i1 + TG.trajPosition.size(0)];
            }
            coder::diff(pointList, timeList);
            pointList.set_size(timeList.size(0) + 1);
            pointList[0] = 0.0;
            loop_ub = timeList.size(0);
            for (i1 = 0; i1 < loop_ub; i1++) {
              pointList[i1 + 1] = timeList[i1];
            }
            loop_ub = pointList.size(0);
            for (i1 = 0; i1 < loop_ub; i1++) {
              TG.trajBodyVelocity[r[i1] + TG.trajBodyVelocity.size(0)] =
                  pointList[i1];
            }
            loop_ub = TG.trajBodyVelocity.size(0);
            r.set_size(loop_ub);
            for (i1 = 0; i1 < loop_ub; i1++) {
              r[i1] = i1;
            }
            loop_ub = TG.trajPosition.size(0);
            pointList.set_size(loop_ub);
            for (i1 = 0; i1 < loop_ub; i1++) {
              pointList[i1] = TG.trajPosition[i1 + TG.trajPosition.size(0) * 2];
            }
            coder::diff(pointList, timeList);
            pointList.set_size(timeList.size(0) + 1);
            pointList[0] = 0.0;
            loop_ub = timeList.size(0);
            for (i1 = 0; i1 < loop_ub; i1++) {
              pointList[i1 + 1] = timeList[i1];
            }
            loop_ub = pointList.size(0);
            for (i1 = 0; i1 < loop_ub; i1++) {
              TG.trajBodyVelocity[r[i1] + TG.trajBodyVelocity.size(0) * 2] =
                  pointList[i1];
            }
            //  Deriver la vitesse pour avoir les acceleration linéare;
            loop_ub = TG.trajLinearAcceleration.size(0);
            r.set_size(loop_ub);
            for (i1 = 0; i1 < loop_ub; i1++) {
              r[i1] = i1;
            }
            loop_ub = TG.trajBodyVelocity.size(0);
            pointList.set_size(loop_ub);
            for (i1 = 0; i1 < loop_ub; i1++) {
              pointList[i1] = TG.trajBodyVelocity[i1];
            }
            coder::diff(pointList, timeList);
            pointList.set_size(timeList.size(0) + 1);
            pointList[0] = 0.0;
            loop_ub = timeList.size(0);
            for (i1 = 0; i1 < loop_ub; i1++) {
              pointList[i1 + 1] = timeList[i1];
            }
            loop_ub = pointList.size(0);
            for (i1 = 0; i1 < loop_ub; i1++) {
              TG.trajLinearAcceleration[r[i1]] = pointList[i1];
            }
            loop_ub = TG.trajLinearAcceleration.size(0);
            r.set_size(loop_ub);
            for (i1 = 0; i1 < loop_ub; i1++) {
              r[i1] = i1;
            }
            loop_ub = TG.trajBodyVelocity.size(0);
            pointList.set_size(loop_ub);
            for (i1 = 0; i1 < loop_ub; i1++) {
              pointList[i1] =
                  TG.trajBodyVelocity[i1 + TG.trajBodyVelocity.size(0)];
            }
            coder::diff(pointList, timeList);
            pointList.set_size(timeList.size(0) + 1);
            pointList[0] = 0.0;
            loop_ub = timeList.size(0);
            for (i1 = 0; i1 < loop_ub; i1++) {
              pointList[i1 + 1] = timeList[i1];
            }
            loop_ub = pointList.size(0);
            for (i1 = 0; i1 < loop_ub; i1++) {
              TG.trajLinearAcceleration[r[i1] + TG.trajLinearAcceleration.size(
                                                    0)] = pointList[i1];
            }
            loop_ub = TG.trajLinearAcceleration.size(0);
            r.set_size(loop_ub);
            for (i1 = 0; i1 < loop_ub; i1++) {
              r[i1] = i1;
            }
            loop_ub = TG.trajBodyVelocity.size(0);
            pointList.set_size(loop_ub);
            for (i1 = 0; i1 < loop_ub; i1++) {
              pointList[i1] =
                  TG.trajBodyVelocity[i1 + TG.trajBodyVelocity.size(0) * 2];
            }
            coder::diff(pointList, timeList);
            pointList.set_size(timeList.size(0) + 1);
            pointList[0] = 0.0;
            loop_ub = timeList.size(0);
            for (i1 = 0; i1 < loop_ub; i1++) {
              pointList[i1 + 1] = timeList[i1];
            }
            loop_ub = pointList.size(0);
            for (i1 = 0; i1 < loop_ub; i1++) {
              TG.trajLinearAcceleration[r[i1] +
                                        TG.trajLinearAcceleration.size(0) * 2] =
                  pointList[i1];
            }
            //  Interpoler l'orientation avec pchip. résultat plus smooth/moins
            //  jerk que slerp. De plus, pas d'oscillation
            loop_ub = TG.trajQuat.size(0);
            r.set_size(loop_ub);
            for (i1 = 0; i1 < loop_ub; i1++) {
              r[i1] = i1;
            }
            loop_ub = TG.quatList.size(0);
            pointList.set_size(loop_ub);
            for (i1 = 0; i1 < loop_ub; i1++) {
              pointList[i1] = TG.quatList[i1];
            }
            coder::interp1(TG.timeList, pointList, t, trajList);
            timeList.set_size(trajList.size(1));
            loop_ub = trajList.size(1);
            for (i1 = 0; i1 < loop_ub; i1++) {
              timeList[i1] = trajList[i1];
            }
            loop_ub = timeList.size(0);
            for (i1 = 0; i1 < loop_ub; i1++) {
              TG.trajQuat[r[i1]] = timeList[i1];
            }
            //  eta
            loop_ub = TG.trajQuat.size(0);
            r.set_size(loop_ub);
            for (i1 = 0; i1 < loop_ub; i1++) {
              r[i1] = i1;
            }
            loop_ub = TG.quatList.size(0);
            pointList.set_size(loop_ub);
            for (i1 = 0; i1 < loop_ub; i1++) {
              pointList[i1] = TG.quatList[i1 + TG.quatList.size(0)];
            }
            coder::interp1(TG.timeList, pointList, t, trajList);
            timeList.set_size(trajList.size(1));
            loop_ub = trajList.size(1);
            for (i1 = 0; i1 < loop_ub; i1++) {
              timeList[i1] = trajList[i1];
            }
            loop_ub = timeList.size(0);
            for (i1 = 0; i1 < loop_ub; i1++) {
              TG.trajQuat[r[i1] + TG.trajQuat.size(0)] = timeList[i1];
            }
            //  epsilon 1
            loop_ub = TG.trajQuat.size(0);
            r.set_size(loop_ub);
            for (i1 = 0; i1 < loop_ub; i1++) {
              r[i1] = i1;
            }
            loop_ub = TG.quatList.size(0);
            pointList.set_size(loop_ub);
            for (i1 = 0; i1 < loop_ub; i1++) {
              pointList[i1] = TG.quatList[i1 + TG.quatList.size(0) * 2];
            }
            coder::interp1(TG.timeList, pointList, t, trajList);
            timeList.set_size(trajList.size(1));
            loop_ub = trajList.size(1);
            for (i1 = 0; i1 < loop_ub; i1++) {
              timeList[i1] = trajList[i1];
            }
            loop_ub = timeList.size(0);
            for (i1 = 0; i1 < loop_ub; i1++) {
              TG.trajQuat[r[i1] + TG.trajQuat.size(0) * 2] = timeList[i1];
            }
            //  epsilon 2
            loop_ub = TG.trajQuat.size(0);
            r.set_size(loop_ub);
            for (i1 = 0; i1 < loop_ub; i1++) {
              r[i1] = i1;
            }
            loop_ub = TG.quatList.size(0);
            pointList.set_size(loop_ub);
            for (i1 = 0; i1 < loop_ub; i1++) {
              pointList[i1] = TG.quatList[i1 + TG.quatList.size(0) * 3];
            }
            coder::interp1(TG.timeList, pointList, t, trajList);
            timeList.set_size(trajList.size(1));
            loop_ub = trajList.size(1);
            for (i1 = 0; i1 < loop_ub; i1++) {
              timeList[i1] = trajList[i1];
            }
            loop_ub = timeList.size(0);
            for (i1 = 0; i1 < loop_ub; i1++) {
              TG.trajQuat[r[i1] + TG.trajQuat.size(0) * 3] = timeList[i1];
            }
            //  epsilon 3
            //  Dériver l'orientation
            qdot.set_size(static_cast<int>(TG.nbPoint), 4);
            loop_ub = static_cast<int>(TG.nbPoint) << 2;
            for (i1 = 0; i1 < loop_ub; i1++) {
              qdot[i1] = 0.0;
            }
            loop_ub = TG.trajQuat.size(0);
            pointList.set_size(loop_ub);
            for (i1 = 0; i1 < loop_ub; i1++) {
              pointList[i1] = TG.trajQuat[i1];
            }
            coder::diff(pointList, timeList);
            qdot[0] = 0.0;
            loop_ub = timeList.size(0);
            for (i1 = 0; i1 < loop_ub; i1++) {
              qdot[i1 + 1] = timeList[i1];
            }
            //  eta_dot
            loop_ub = TG.trajQuat.size(0);
            pointList.set_size(loop_ub);
            for (i1 = 0; i1 < loop_ub; i1++) {
              pointList[i1] = TG.trajQuat[i1 + TG.trajQuat.size(0)];
            }
            coder::diff(pointList, timeList);
            qdot[qdot.size(0)] = 0.0;
            loop_ub = timeList.size(0);
            for (i1 = 0; i1 < loop_ub; i1++) {
              qdot[(i1 + qdot.size(0)) + 1] = timeList[i1];
            }
            //  epsilon 1 dot
            loop_ub = TG.trajQuat.size(0);
            pointList.set_size(loop_ub);
            for (i1 = 0; i1 < loop_ub; i1++) {
              pointList[i1] = TG.trajQuat[i1 + TG.trajQuat.size(0) * 2];
            }
            coder::diff(pointList, timeList);
            qdot[qdot.size(0) * 2] = 0.0;
            loop_ub = timeList.size(0);
            for (i1 = 0; i1 < loop_ub; i1++) {
              qdot[(i1 + qdot.size(0) * 2) + 1] = timeList[i1];
            }
            //  epsilon 2 dot
            loop_ub = TG.trajQuat.size(0);
            pointList.set_size(loop_ub);
            for (i1 = 0; i1 < loop_ub; i1++) {
              pointList[i1] = TG.trajQuat[i1 + TG.trajQuat.size(0) * 3];
            }
            coder::diff(pointList, timeList);
            qdot[qdot.size(0) * 3] = 0.0;
            loop_ub = timeList.size(0);
            for (i1 = 0; i1 < loop_ub; i1++) {
              qdot[(i1 + qdot.size(0) * 3) + 1] = timeList[i1];
            }
            //  epsilon 3 dot
            //  Post traitement
            expl_temp = TG.nbPoint;
            i1 = static_cast<int>(expl_temp);
            if (static_cast<int>(expl_temp) - 1 >= 0) {
              dv[0] = 0.0;
              dv[4] = 0.0;
              dv[8] = 0.0;
            }
            for (int b_i{0}; b_i < i1; b_i++) {
              double dv1[12];
              double invE2[12];
              double q[4];
              double b_invE2[3];
              double b_a;
              double b_idx_2;
              double b_idx_3;
              //  Normaliser les quaternions car l'interpolation de type spline
              //  ne le garentie pas.
              q[0] = TG.trajQuat[b_i];
              q[1] = TG.trajQuat[b_i + TG.trajQuat.size(0)];
              q[2] = TG.trajQuat[b_i + TG.trajQuat.size(0) * 2];
              q[3] = TG.trajQuat[b_i + TG.trajQuat.size(0) * 3];
              //  Fossen(2021) eq 2.86 p.37
              // =================================================================
              //  Fonction qui normalise un quaternion.
              //  quatnormalize de matlab demande areospace block set pour etre
              //  compilable.
              expl_temp = coder::c_norm(q);
              TG.trajQuat[b_i] = q[0] / expl_temp;
              TG.trajQuat[b_i + TG.trajQuat.size(0)] = q[1] / expl_temp;
              TG.trajQuat[b_i + TG.trajQuat.size(0) * 2] = q[2] / expl_temp;
              TG.trajQuat[b_i + TG.trajQuat.size(0) * 3] = q[3] / expl_temp;
              //  verifier la discontinuité du quaternion.
              if (b_i + 1U > 1U) {
                q[0] = TG.trajQuat[b_i - 1];
                q[1] = TG.trajQuat[(b_i + TG.trajQuat.size(0)) - 1];
                q[2] = TG.trajQuat[(b_i + TG.trajQuat.size(0) * 2) - 1];
                q[3] = TG.trajQuat[(b_i + TG.trajQuat.size(0) * 3) - 1];
                expl_temp = TG.trajQuat[b_i];
                b_expl_temp = TG.trajQuat[b_i + TG.trajQuat.size(0)];
                b_idx_2 = TG.trajQuat[b_i + TG.trajQuat.size(0) * 2];
                b_idx_3 = TG.trajQuat[b_i + TG.trajQuat.size(0) * 3];
                if (((q[0] * expl_temp + q[1] * b_expl_temp) + q[2] * b_idx_2) +
                        q[3] * b_idx_3 <
                    0.0) {
                  q[0] = -TG.trajQuat[b_i];
                  q[1] = -TG.trajQuat[b_i + TG.trajQuat.size(0)];
                  q[2] = -TG.trajQuat[b_i + TG.trajQuat.size(0) * 2];
                  q[3] = -TG.trajQuat[b_i + TG.trajQuat.size(0) * 3];
                  TG.trajQuat[b_i] = q[0];
                  TG.trajQuat[b_i + TG.trajQuat.size(0)] = q[1];
                  TG.trajQuat[b_i + TG.trajQuat.size(0) * 2] = q[2];
                  TG.trajQuat[b_i + TG.trajQuat.size(0) * 3] = q[3];
                }
              }
              //  Convertir les vitesse lineaire dans le ref sub
              expl_temp = TG.trajBodyVelocity[b_i];
              b_expl_temp =
                  TG.trajBodyVelocity[b_i + TG.trajBodyVelocity.size(0)];
              b_idx_2 =
                  TG.trajBodyVelocity[b_i + TG.trajBodyVelocity.size(0) * 2];
              q[0] = TG.trajQuat[b_i];
              q[1] = TG.trajQuat[b_i + TG.trajQuat.size(0)];
              q[2] = TG.trajQuat[b_i + TG.trajQuat.size(0) * 2];
              q[3] = TG.trajQuat[b_i + TG.trajQuat.size(0) * 3];
              // =================================================================
              //  Fonction qui tourne un vecteur selon un quaternion.
              //  quaternion partie scalaire
              //  quaternion partie vectoriel
              //  QuatRotate n'est pas compilable
              a = 2.0 *
                  ((q[1] * expl_temp + q[2] * b_expl_temp) + q[3] * b_idx_2);
              b_idx_3 =
                  q[0] * q[0] - ((q[1] * q[1] + q[2] * q[2]) + q[3] * q[3]);
              b_a = 2.0 * q[0];
              TG.trajBodyVelocity[b_i] =
                  (a * q[1] + b_idx_3 * expl_temp) +
                  b_a * (q[2] * b_idx_2 - b_expl_temp * q[3]);
              TG.trajBodyVelocity[b_i + TG.trajBodyVelocity.size(0)] =
                  (a * q[2] + b_idx_3 * b_expl_temp) +
                  b_a * (expl_temp * q[3] - q[1] * b_idx_2);
              TG.trajBodyVelocity[b_i + TG.trajBodyVelocity.size(0) * 2] =
                  (a * q[3] + b_idx_3 * b_idx_2) +
                  b_a * (q[1] * b_expl_temp - expl_temp * q[2]);
              //  Convertir des quaternion instantané en vitesse angulaire
              q[0] = TG.trajQuat[b_i];
              q[1] = TG.trajQuat[b_i + TG.trajQuat.size(0)];
              q[2] = TG.trajQuat[b_i + TG.trajQuat.size(0) * 2];
              q[3] = TG.trajQuat[b_i + TG.trajQuat.size(0) * 3];
              // =================================================================
              //  Fonction qui convertie un quaternion instantané en vitesses
              //  angulaires. Fossen(2021) eq 2.77 - 2.78 page 35
              // =================================================================
              //  Calcule la matrice de transformation vitesse angulaire à
              //  quaternion instantané Fossen(2021) eq 2.47 p30
              // =================================================================
              //  Fonction qui Convertie un vecteur 3x1 en une matrice
              //  antisymétrique 3x3
              dv[3] = -q[3];
              dv[6] = q[2];
              dv[1] = q[3];
              dv[7] = -q[1];
              dv[2] = -q[2];
              dv[5] = q[1];
              for (int i2{0}; i2 < 3; i2++) {
                int i3;
                loop_ub = i2 << 2;
                dv1[loop_ub] = 0.5 * -q[i2 + 1];
                dv1[loop_ub + 1] =
                    0.5 * (q[0] * static_cast<double>(b[3 * i2]) + dv[3 * i2]);
                i3 = 3 * i2 + 1;
                dv1[loop_ub + 2] =
                    0.5 * (q[0] * static_cast<double>(b[i3]) + dv[i3]);
                i3 = 3 * i2 + 2;
                dv1[loop_ub + 3] =
                    0.5 * (q[0] * static_cast<double>(b[i3]) + dv[i3]);
              }
              coder::pinv(dv1, invE2);
              for (int i2{0}; i2 < 3; i2++) {
                b_invE2[i2] = ((invE2[i2] * qdot[b_i] +
                                invE2[i2 + 3] * qdot[b_i + qdot.size(0)]) +
                               invE2[i2 + 6] * qdot[b_i + qdot.size(0) * 2]) +
                              invE2[i2 + 9] * qdot[b_i + qdot.size(0) * 3];
              }
              TG.trajAngulairRates[b_i] = -b_invE2[0];
              TG.trajAngulairRates[b_i + TG.trajAngulairRates.size(0)] =
                  -b_invE2[1];
              TG.trajAngulairRates[b_i + TG.trajAngulairRates.size(0) * 2] =
                  -b_invE2[2];
              //  Convertir les vitesse angulaire dans le ref sub
              expl_temp = -TG.trajAngulairRates[b_i];
              b_expl_temp =
                  -TG.trajAngulairRates[b_i + TG.trajAngulairRates.size(0)];
              b_idx_2 =
                  -TG.trajAngulairRates[b_i + TG.trajAngulairRates.size(0) * 2];
              TG.trajAngulairRates[b_i] = expl_temp;
              TG.trajAngulairRates[b_i + TG.trajAngulairRates.size(0)] =
                  b_expl_temp;
              TG.trajAngulairRates[b_i + TG.trajAngulairRates.size(0) * 2] =
                  b_idx_2;
              //  Convertire les accélération angulaire dans le ref sub
              expl_temp = TG.trajLinearAcceleration[b_i];
              b_expl_temp =
                  TG.trajLinearAcceleration[b_i +
                                            TG.trajLinearAcceleration.size(0)];
              b_idx_2 =
                  TG.trajLinearAcceleration[b_i +
                                            TG.trajLinearAcceleration.size(0) *
                                                2];
              q[0] = TG.trajQuat[b_i];
              q[1] = TG.trajQuat[b_i + TG.trajQuat.size(0)];
              q[2] = TG.trajQuat[b_i + TG.trajQuat.size(0) * 2];
              q[3] = TG.trajQuat[b_i + TG.trajQuat.size(0) * 3];
              // =================================================================
              //  Fonction qui tourne un vecteur selon un quaternion.
              //  quaternion partie scalaire
              //  quaternion partie vectoriel
              //  QuatRotate n'est pas compilable
              a = 2.0 *
                  ((q[1] * expl_temp + q[2] * b_expl_temp) + q[3] * b_idx_2);
              b_idx_3 =
                  q[0] * q[0] - ((q[1] * q[1] + q[2] * q[2]) + q[3] * q[3]);
              b_a = 2.0 * q[0];
              TG.trajLinearAcceleration[b_i] =
                  (a * q[1] + b_idx_3 * expl_temp) +
                  b_a * (q[2] * b_idx_2 - b_expl_temp * q[3]);
              TG.trajLinearAcceleration[b_i +
                                        TG.trajLinearAcceleration.size(0)] =
                  (a * q[2] + b_idx_3 * b_expl_temp) +
                  b_a * (expl_temp * q[3] - q[1] * b_idx_2);
              TG.trajLinearAcceleration[b_i +
                                        TG.trajLinearAcceleration.size(0) * 2] =
                  (a * q[3] + b_idx_3 * b_idx_2) +
                  b_a * (q[1] * b_expl_temp - expl_temp * q[2]);
            }
            //  Calucler les acceleration angulaire
            loop_ub = TG.trajAngularAcceleration.size(0);
            r.set_size(loop_ub);
            for (i1 = 0; i1 < loop_ub; i1++) {
              r[i1] = i1;
            }
            loop_ub = TG.trajAngulairRates.size(0);
            pointList.set_size(loop_ub);
            for (i1 = 0; i1 < loop_ub; i1++) {
              pointList[i1] = TG.trajAngulairRates[i1];
            }
            coder::diff(pointList, timeList);
            pointList.set_size(timeList.size(0) + 1);
            pointList[0] = 0.0;
            loop_ub = timeList.size(0);
            for (i1 = 0; i1 < loop_ub; i1++) {
              pointList[i1 + 1] = timeList[i1];
            }
            loop_ub = pointList.size(0);
            for (i1 = 0; i1 < loop_ub; i1++) {
              TG.trajAngularAcceleration[r[i1]] = pointList[i1];
            }
            //  p_dot
            loop_ub = TG.trajAngularAcceleration.size(0);
            r.set_size(loop_ub);
            for (i1 = 0; i1 < loop_ub; i1++) {
              r[i1] = i1;
            }
            loop_ub = TG.trajAngulairRates.size(0);
            pointList.set_size(loop_ub);
            for (i1 = 0; i1 < loop_ub; i1++) {
              pointList[i1] =
                  TG.trajAngulairRates[i1 + TG.trajAngulairRates.size(0)];
            }
            coder::diff(pointList, timeList);
            pointList.set_size(timeList.size(0) + 1);
            pointList[0] = 0.0;
            loop_ub = timeList.size(0);
            for (i1 = 0; i1 < loop_ub; i1++) {
              pointList[i1 + 1] = timeList[i1];
            }
            loop_ub = pointList.size(0);
            for (i1 = 0; i1 < loop_ub; i1++) {
              TG.trajAngularAcceleration[r[i1] +
                                         TG.trajAngularAcceleration.size(0)] =
                  pointList[i1];
            }
            //  q_dot
            loop_ub = TG.trajAngularAcceleration.size(0);
            r.set_size(loop_ub);
            for (i1 = 0; i1 < loop_ub; i1++) {
              r[i1] = i1;
            }
            loop_ub = TG.trajAngulairRates.size(0);
            pointList.set_size(loop_ub);
            for (i1 = 0; i1 < loop_ub; i1++) {
              pointList[i1] =
                  TG.trajAngulairRates[i1 + TG.trajAngulairRates.size(0) * 2];
            }
            coder::diff(pointList, timeList);
            pointList.set_size(timeList.size(0) + 1);
            pointList[0] = 0.0;
            loop_ub = timeList.size(0);
            for (i1 = 0; i1 < loop_ub; i1++) {
              pointList[i1 + 1] = timeList[i1];
            }
            loop_ub = pointList.size(0);
            for (i1 = 0; i1 < loop_ub; i1++) {
              TG.trajAngularAcceleration[r[i1] +
                                         TG.trajAngularAcceleration.size(0) *
                                             2] = pointList[i1];
            }
            //  rs_dot
            //  Envoyer la trajectoire sur ROS.
            //  Initialiser le message trajectoire.
            // ==================================================================
            //  Fonction qui envoie les message sur ros
            trajectory_msgs_MultiDOFJointTrajectoryPointStruct(&trajMsg);
            //  message point
            geometry_msgs_TransformStruct(&transformBuff);
            //  trajectoire
            geometry_msgs_TwistStruct(&twistBuff);
            //  trajectoire
            //  initialiser la dimention vecteur de points
            expl_temp = TG.nbPoint;
            i1 = static_cast<int>(expl_temp);
            y.set_size(1, i1);
            for (loop_ub = 0; loop_ub < i1; loop_ub++) {
              y[loop_ub] = transformBuff;
            }
            trajMsg.Transforms.set_size(y.size(1));
            loop_ub = y.size(1);
            for (i1 = 0; i1 < loop_ub; i1++) {
              trajMsg.Transforms[i1] = y[i1];
            }
            coder::repelem(&twistBuff, TG.nbPoint, r1);
            trajMsg.Velocities.set_size(r1.size(1));
            loop_ub = r1.size(1);
            for (i1 = 0; i1 < loop_ub; i1++) {
              trajMsg.Velocities[i1] = r1[i1];
            }
            coder::repelem(&twistBuff, TG.nbPoint, r1);
            trajMsg.Accelerations.set_size(r1.size(1));
            loop_ub = r1.size(1);
            for (i1 = 0; i1 < loop_ub; i1++) {
              trajMsg.Accelerations[i1] = r1[i1];
            }
            //  Remplire le message ROS
            expl_temp = TG.nbPoint;
            i1 = static_cast<int>(expl_temp);
            for (int b_i{0}; b_i < i1; b_i++) {
              //  Remplire le message Transform.
              transformBuff.Translation.X = TG.trajPosition[b_i];
              transformBuff.Translation.Y =
                  TG.trajPosition[b_i + TG.trajPosition.size(0)];
              transformBuff.Translation.Z =
                  TG.trajPosition[b_i + TG.trajPosition.size(0) * 2];
              transformBuff.Rotation.W = TG.trajQuat[b_i];
              transformBuff.Rotation.X = TG.trajQuat[b_i + TG.trajQuat.size(0)];
              transformBuff.Rotation.Y =
                  TG.trajQuat[b_i + TG.trajQuat.size(0) * 2];
              transformBuff.Rotation.Z =
                  TG.trajQuat[b_i + TG.trajQuat.size(0) * 3];
              trajMsg.Transforms[b_i] = transformBuff;
              //  Remplire les vitesse
              twistBuff.Linear.X = TG.trajBodyVelocity[b_i];
              twistBuff.Linear.Y =
                  TG.trajBodyVelocity[b_i + TG.trajBodyVelocity.size(0)];
              twistBuff.Linear.Z =
                  TG.trajBodyVelocity[b_i + TG.trajBodyVelocity.size(0) * 2];
              twistBuff.Angular.X = TG.trajAngulairRates[b_i];
              twistBuff.Angular.Y =
                  TG.trajAngulairRates[b_i + TG.trajAngulairRates.size(0)];
              twistBuff.Angular.Z =
                  TG.trajAngulairRates[b_i + TG.trajAngulairRates.size(0) * 2];
              trajMsg.Velocities[b_i] = twistBuff;
              //  Remplire les acceleration
              twistBuff.Linear.X = TG.trajLinearAcceleration[b_i];
              twistBuff.Linear.Y =
                  TG.trajLinearAcceleration[b_i +
                                            TG.trajLinearAcceleration.size(0)];
              twistBuff.Linear.Z =
                  TG.trajLinearAcceleration[b_i +
                                            TG.trajLinearAcceleration.size(0) *
                                                2];
              twistBuff.Angular.X = TG.trajAngularAcceleration[b_i];
              twistBuff.Angular.Y =
                  TG.trajAngularAcceleration[b_i + TG.trajAngularAcceleration
                                                       .size(0)];
              twistBuff.Angular.Z =
                  TG.trajAngularAcceleration
                      [b_i + TG.trajAngularAcceleration.size(0) * 2];
              trajMsg.Accelerations[b_i] = twistBuff;
            }
            //  Envoyer le message
            MATLABPUBLISHER_publish(b_trajpub->PublisherHelper, &trajMsg);
            expl_temp = std::round(TG.nbPoint);
            if (expl_temp < 32768.0) {
              if (expl_temp >= -32768.0) {
                validatedHoleFilling_idx_0 = static_cast<short>(expl_temp);
              } else {
                validatedHoleFilling_idx_0 = MIN_int16_T;
              }
            } else if (expl_temp >= 32768.0) {
              validatedHoleFilling_idx_0 = MAX_int16_T;
            } else {
              validatedHoleFilling_idx_0 = 0;
            }
            printf("INFO : proc planner : Trajectory generation succeded with "
                   "%d points. \n",
                   validatedHoleFilling_idx_0);
            fflush(stdout);
            //  Si on roule en simulation
            //  Retourner true (sucess)
          }
        }
        //  initialte variables
        //  SET
        newMadpPose = false;
        //  initialte variables
        //  SET
        newInitialPose = false;
      }
    }
    MATLABRate_sleep(b_spin->RateHelper);
    coder::toc(b_spin->PreviousPeriod.tv_sec, b_spin->PreviousPeriod.tv_nsec);
    coder::tic(&b_spin->PreviousPeriod.tv_sec, &b_spin->PreviousPeriod.tv_nsec);
  }
}

//
// File trailer for ros_node.cpp
//
// [EOF]
//
