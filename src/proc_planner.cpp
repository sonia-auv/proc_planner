//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: proc_planner.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 01-Feb-2022 18:48:34
//

// Include Files
#include "proc_planner.h"
#include "Publisher.h"
#include "Rate.h"
#include "Subscriber.h"
#include "TrajectoryGenerator.h"
#include "geometry_msgs_TransformStruct.h"
#include "geometry_msgs_TwistStruct.h"
#include "geometry_msgs_Vector3Struct.h"
#include "minOrMax.h"
#include "norm.h"
#include "proc_planner_data.h"
#include "proc_planner_initialize.h"
#include "proc_planner_internal_types.h"
#include "proc_planner_rtwutil.h"
#include "proc_planner_types.h"
#include "quaternion.h"
#include "repelem.h"
#include "rt_nonfinite.h"
#include "sonia_common_AddPoseStruct.h"
#include "sonia_common_MultiAddPoseStruct.h"
#include "trajectory_msgs_MultiDOFJointTrajectoryPointStruct.h"
#include "waypointTrajectory.h"
#include "coder_array.h"
#include <cmath>
#include <string.h>

// Function Definitions
//
// Create a Subscriber to subscribe to /dest topic
//
// Arguments    : void
// Return Type  : void
//
void proc_planner()
{
  TrajectoryGenerator TG;
  coder::b_quaternion varargout_2;
  coder::quaternion r2;
  coder::ros::Publisher pospub;
  coder::ros::Rate b_r;
  coder::ros::Subscriber destSub;
  coder::ros::b_Publisher velPub;
  coder::ros::b_Subscriber stopSub;
  coder::ros::c_Publisher trajpub;
  coder::ros::c_Subscriber odomSub;
  coder::ros::d_Publisher b_pospub;
  coder::ros::d_Subscriber mapSub;
  coder::ros::e_Subscriber *sub;
  coder::waypointTrajectory trajObj;
  coder::array<geometry_msgs_TransformStruct_T, 2U> y;
  coder::array<geometry_msgs_TwistStruct_T, 2U> r3;
  coder::array<sonia_common_AddPoseStruct_T, 1U> rMaddposemsg_Pose;
  coder::array<double, 2U> b_TG;
  coder::array<double, 1U> c_TG;
  geometry_msgs_PointStruct_T t7_Position;
  geometry_msgs_QuaternionStruct_T t7_Orientation;
  geometry_msgs_TransformStruct_T transformBuff;
  geometry_msgs_TwistStruct_T twistBuff;
  sonia_common_AddPoseStruct_T unusedExpr;
  sonia_common_MultiAddPoseStruct_T r;
  sonia_common_MultiAddPoseStruct_T r1;
  trajectory_msgs_MultiDOFJointTrajectoryPointStruct_T trajMsg;
  double qRel[4];
  double a[3];
  double c[3];
  double s[3];
  double varargout_5[3];
  char rMaddposemsg_MessageType[25];
  char t7_MessageType[18];
  bool status;
  if (!isInitialized_proc_planner) {
    proc_planner_initialize();
  }
  destSub.matlabCodegenIsDeleted = true;
  stopSub.matlabCodegenIsDeleted = true;
  odomSub.matlabCodegenIsDeleted = true;
  pospub.matlabCodegenIsDeleted = true;
  velPub.matlabCodegenIsDeleted = true;
  mapSub.matlabCodegenIsDeleted = true;
  trajpub.matlabCodegenIsDeleted = true;
  TG._pobj0.matlabCodegenIsDeleted = true;
  TG.matlabCodegenIsDeleted = true;
  b_pospub.matlabCodegenIsDeleted = true;
  destSub.init();
  //  Create a Subscriber to subscribe to /stop topic
  stopSub.init();
  //  Create a Subscriber to subscribe to /odom topic
  odomSub.init();
  //  Create a Publisher to publish to /cmd_vel topic
  pospub.init();
  geometry_msgs_Vector3Struct();
  velPub.init();
  geometry_msgs_TwistStruct(&twistBuff);
  sonia_common_AddPoseStruct(&unusedExpr);
  sonia_common_MultiAddPoseStruct(&r);
  sonia_common_MultiAddPoseStruct(&r1);
  b_pospub.init();
  mapSub.init();
  trajpub.init();
  //  Maddposemsg.Pose = [Maddposemsg.Pose, addposemsg];
  // send(pospub,Maddposemsg);
  b_r.init();
  while (1) {
    mapSub.receive(rMaddposemsg_MessageType, rMaddposemsg_Pose, &status);
    if (status) {
      double d;
      double vl;
      int i;
      int loop_ub;
      TG.matlabCodegenDestructor();
      TG._pobj0.matlabCodegenDestructor();
      TG.nbPoint = 1.0;
      // ==================================================================
      //  Constructeur
      for (i = 0; i < 25; i++) {
        TG.MAPM.MessageType[i] = rMaddposemsg_MessageType[i];
      }
      TG.MAPM.Pose.set_size(rMaddposemsg_Pose.size(0));
      loop_ub = rMaddposemsg_Pose.size(0);
      for (i = 0; i < loop_ub; i++) {
        TG.MAPM.Pose[i] = rMaddposemsg_Pose[i];
      }
      //  nombre de waypoints + iC
      TG.n = 2.0;
      //  Initialiser les tableaux
      loop_ub = static_cast<int>(TG.n);
      TG.pointList.set_size(loop_ub, 3);
      loop_ub *= 3;
      for (i = 0; i < loop_ub; i++) {
        TG.pointList[i] = 0.0;
      }
      loop_ub = static_cast<int>(TG.n);
      TG.quatList.set_size(loop_ub, 4);
      loop_ub <<= 2;
      for (i = 0; i < loop_ub; i++) {
        TG.quatList[i] = 0.0;
      }
      TG.timeList.set_size(static_cast<int>(TG.n));
      loop_ub = static_cast<int>(TG.n);
      for (i = 0; i < loop_ub; i++) {
        TG.timeList[i] = 0.0;
      }
      //  Initialiser les parametres
      TG.param.ts = 0.1;
      TG.param.amax = 0.15;
      TG.param.vlmax = 0.8;
      TG.param.vamax = 0.78539816339744828;
      sub = TG._pobj0.init();
      TG.icSub = sub;
      //  trouver le waypoint initial
      //  lire la position initale
      // ==================================================================
      //  Fonnction qui retoure le waypoint initial
      TG.icSub->receive(t7_MessageType, &t7_Position, &t7_Orientation, &status);
      for (i = 0; i < 18; i++) {
        TG.icMsg.MessageType[i] = t7_MessageType[i];
      }
      TG.icMsg.Position = t7_Position;
      TG.icMsg.Orientation = t7_Orientation;
      if (status) {
        //  Replire les listes.
        TG.pointList[0] = TG.icMsg.Position.X;
        TG.pointList[TG.pointList.size(0)] = TG.icMsg.Position.Y;
        TG.pointList[TG.pointList.size(0) * 2] = TG.icMsg.Position.Z;
        TG.quatList[0] = TG.icMsg.Orientation.W;
        TG.quatList[TG.quatList.size(0)] = TG.icMsg.Orientation.X;
        TG.quatList[TG.quatList.size(0) * 2] = TG.icMsg.Orientation.Y;
        TG.quatList[TG.quatList.size(0) * 3] = TG.icMsg.Orientation.Z;
        TG.timeList[0] = 0.0;
        //  Process le message addpose
        // ==================================================================
        //  Fonction qui interprete les waypoints reçu par ROS
        d = TG.n - 1.0;
        loop_ub = 0;
        int exitg1;
        do {
          exitg1 = 0;
          if (loop_ub <= static_cast<int>(d) - 1) {
            double b_d;
            double q_idx_0;
            double q_idx_1;
            double q_idx_2;
            double q_idx_3;
            double tl;
            //  pour chaques waypoints
            //  transformer les angle d'euler quaternions
            s[0] = TG.MAPM.Pose[loop_ub].Orientation.Z;
            s[1] = TG.MAPM.Pose[loop_ub].Orientation.Y;
            s[2] = TG.MAPM.Pose[loop_ub].Orientation.X;
            vl = 0.017453292519943295 * s[0] / 2.0;
            c[0] = std::cos(vl);
            vl = std::sin(vl);
            s[0] = vl;
            vl = 0.017453292519943295 * s[1] / 2.0;
            c[1] = std::cos(vl);
            vl = std::sin(vl);
            s[1] = vl;
            vl = 0.017453292519943295 * s[2] / 2.0;
            c[2] = std::cos(vl);
            vl = std::sin(vl);
            b_d = c[0] * c[1];
            tl = s[0] * s[1];
            q_idx_0 = b_d * c[2] + tl * vl;
            q_idx_1 = b_d * vl - tl * c[2];
            b_d = s[0] * c[1];
            tl = c[0] * s[1];
            q_idx_2 = tl * c[2] + b_d * vl;
            q_idx_3 = b_d * c[2] - tl * vl;
            //  cree le vecteur pose
            c[0] = TG.MAPM.Pose[loop_ub].Position.X;
            c[1] = TG.MAPM.Pose[loop_ub].Position.Y;
            c[2] = TG.MAPM.Pose[loop_ub].Position.Z;
            //  transformer le point en fonction du frame
            switch (TG.MAPM.Pose[loop_ub].Frame) {
            case 0U:
              //  position et angle absolue
              TG.pointList[static_cast<int>(
                               (static_cast<double>(loop_ub) + 1.0) + 1.0) -
                           1] = c[0];
              TG.pointList[(static_cast<int>(
                                (static_cast<double>(loop_ub) + 1.0) + 1.0) +
                            TG.pointList.size(0)) -
                           1] = c[1];
              TG.pointList[(static_cast<int>(
                                (static_cast<double>(loop_ub) + 1.0) + 1.0) +
                            TG.pointList.size(0) * 2) -
                           1] = c[2];
              TG.quatList[static_cast<int>(
                              (static_cast<double>(loop_ub) + 1.0) + 1.0) -
                          1] = q_idx_0;
              TG.quatList[(static_cast<int>(
                               (static_cast<double>(loop_ub) + 1.0) + 1.0) +
                           TG.quatList.size(0)) -
                          1] = q_idx_1;
              TG.quatList[(static_cast<int>(
                               (static_cast<double>(loop_ub) + 1.0) + 1.0) +
                           TG.quatList.size(0) * 2) -
                          1] = q_idx_2;
              TG.quatList[(static_cast<int>(
                               (static_cast<double>(loop_ub) + 1.0) + 1.0) +
                           TG.quatList.size(0) * 3) -
                          1] = q_idx_3;
              loop_ub++;
              break;
            case 1U: {
              double bufferQuat_idx_0;
              double bufferQuat_idx_1;
              double bufferQuat_idx_2;
              double bufferQuat_idx_3;
              //  position et angle relatif
              // =================================================================
              //  Fonction qui tourne un vecteur selon un quaternion.
              //  quaternion partie scalaire
              //  quaternion partie vectoriel
              //  QuatRotate n'est pas compilable
              vl = 2.0 * ((c[0] * q_idx_1 + c[1] * q_idx_2) + c[2] * q_idx_3);
              b_d =
                  q_idx_0 * q_idx_0 -
                  ((q_idx_1 * q_idx_1 + q_idx_2 * q_idx_2) + q_idx_3 * q_idx_3);
              tl = 2.0 * q_idx_0;
              s[0] = TG.pointList[loop_ub] +
                     ((vl * q_idx_1 + b_d * c[0]) +
                      tl * (q_idx_2 * c[2] - c[1] * q_idx_3));
              s[1] = TG.pointList[loop_ub + TG.pointList.size(0)] +
                     ((vl * q_idx_2 + b_d * c[1]) +
                      tl * (c[0] * q_idx_3 - q_idx_1 * c[2]));
              s[2] = TG.pointList[loop_ub + TG.pointList.size(0) * 2] +
                     ((vl * q_idx_3 + b_d * c[2]) +
                      tl * (q_idx_1 * c[1] - c[0] * q_idx_2));
              TG.pointList[static_cast<int>(
                               (static_cast<double>(loop_ub) + 1.0) + 1.0) -
                           1] = s[0];
              TG.pointList[(static_cast<int>(
                                (static_cast<double>(loop_ub) + 1.0) + 1.0) +
                            TG.pointList.size(0)) -
                           1] = s[1];
              TG.pointList[(static_cast<int>(
                                (static_cast<double>(loop_ub) + 1.0) + 1.0) +
                            TG.pointList.size(0) * 2) -
                           1] = s[2];
              bufferQuat_idx_0 = TG.quatList[loop_ub];
              bufferQuat_idx_1 = TG.quatList[loop_ub + TG.quatList.size(0)];
              bufferQuat_idx_2 = TG.quatList[loop_ub + TG.quatList.size(0) * 2];
              bufferQuat_idx_3 = TG.quatList[loop_ub + TG.quatList.size(0) * 3];
              status = TG.MAPM.Pose[loop_ub].Rotation;
              // ==================================================================
              //  Fonnction qui retoure le quaternion le plus court/long selon
              //  l'utilisateur
              vl = bufferQuat_idx_0 * q_idx_0;
              b_d = ((vl + bufferQuat_idx_1 * q_idx_1) +
                     bufferQuat_idx_2 * q_idx_2) +
                    bufferQuat_idx_3 * q_idx_3;
              //  conjuger le quaternion au besoin
              if (((b_d > 1.0) && (!status)) || ((b_d < 1.0) && status)) {
                q_idx_1 = -q_idx_1;
                q_idx_2 = -q_idx_2;
                q_idx_3 = -q_idx_3;
              }
              TG.quatList[static_cast<int>(
                              (static_cast<double>(loop_ub) + 1.0) + 1.0) -
                          1] = ((vl - bufferQuat_idx_1 * q_idx_1) -
                                bufferQuat_idx_2 * q_idx_2) -
                               bufferQuat_idx_3 * q_idx_3;
              TG.quatList[(static_cast<int>(
                               (static_cast<double>(loop_ub) + 1.0) + 1.0) +
                           TG.quatList.size(0)) -
                          1] =
                  (bufferQuat_idx_0 * q_idx_1 + q_idx_0 * bufferQuat_idx_1) +
                  (bufferQuat_idx_2 * q_idx_3 - q_idx_2 * bufferQuat_idx_3);
              TG.quatList[(static_cast<int>(
                               (static_cast<double>(loop_ub) + 1.0) + 1.0) +
                           TG.quatList.size(0) * 2) -
                          1] =
                  (bufferQuat_idx_0 * q_idx_2 + q_idx_0 * bufferQuat_idx_2) +
                  (q_idx_1 * bufferQuat_idx_3 - bufferQuat_idx_1 * q_idx_3);
              TG.quatList[(static_cast<int>(
                               (static_cast<double>(loop_ub) + 1.0) + 1.0) +
                           TG.quatList.size(0) * 3) -
                          1] =
                  (bufferQuat_idx_0 * q_idx_3 + q_idx_0 * bufferQuat_idx_3) +
                  (bufferQuat_idx_1 * q_idx_2 - q_idx_1 * bufferQuat_idx_2);
              loop_ub++;
            } break;
            case 2U:
              //  position relatif et angle absolue
              // =================================================================
              //  Fonction qui tourne un vecteur selon un quaternion.
              //  quaternion partie scalaire
              //  quaternion partie vectoriel
              //  QuatRotate n'est pas compilable
              vl = 2.0 * ((c[0] * q_idx_1 + c[1] * q_idx_2) + c[2] * q_idx_3);
              b_d =
                  q_idx_0 * q_idx_0 -
                  ((q_idx_1 * q_idx_1 + q_idx_2 * q_idx_2) + q_idx_3 * q_idx_3);
              tl = 2.0 * q_idx_0;
              s[0] = TG.pointList[loop_ub] +
                     ((vl * q_idx_1 + b_d * c[0]) +
                      tl * (q_idx_2 * c[2] - c[1] * q_idx_3));
              s[1] = TG.pointList[loop_ub + TG.pointList.size(0)] +
                     ((vl * q_idx_2 + b_d * c[1]) +
                      tl * (c[0] * q_idx_3 - q_idx_1 * c[2]));
              s[2] = TG.pointList[loop_ub + TG.pointList.size(0) * 2] +
                     ((vl * q_idx_3 + b_d * c[2]) +
                      tl * (q_idx_1 * c[1] - c[0] * q_idx_2));
              TG.pointList[static_cast<int>(
                               (static_cast<double>(loop_ub) + 1.0) + 1.0) -
                           1] = s[0];
              TG.pointList[(static_cast<int>(
                                (static_cast<double>(loop_ub) + 1.0) + 1.0) +
                            TG.pointList.size(0)) -
                           1] = s[1];
              TG.pointList[(static_cast<int>(
                                (static_cast<double>(loop_ub) + 1.0) + 1.0) +
                            TG.pointList.size(0) * 2) -
                           1] = s[2];
              TG.quatList[static_cast<int>(
                              (static_cast<double>(loop_ub) + 1.0) + 1.0) -
                          1] = q_idx_0;
              TG.quatList[(static_cast<int>(
                               (static_cast<double>(loop_ub) + 1.0) + 1.0) +
                           TG.quatList.size(0)) -
                          1] = q_idx_1;
              TG.quatList[(static_cast<int>(
                               (static_cast<double>(loop_ub) + 1.0) + 1.0) +
                           TG.quatList.size(0) * 2) -
                          1] = q_idx_2;
              TG.quatList[(static_cast<int>(
                               (static_cast<double>(loop_ub) + 1.0) + 1.0) +
                           TG.quatList.size(0) * 3) -
                          1] = q_idx_3;
              loop_ub++;
              break;
            case 3U: {
              double bufferQuat_idx_0;
              double bufferQuat_idx_1;
              double bufferQuat_idx_2;
              double bufferQuat_idx_3;
              //  position absolue et angle relatif
              TG.pointList[static_cast<int>(
                               (static_cast<double>(loop_ub) + 1.0) + 1.0) -
                           1] = c[0];
              TG.pointList[(static_cast<int>(
                                (static_cast<double>(loop_ub) + 1.0) + 1.0) +
                            TG.pointList.size(0)) -
                           1] = c[1];
              TG.pointList[(static_cast<int>(
                                (static_cast<double>(loop_ub) + 1.0) + 1.0) +
                            TG.pointList.size(0) * 2) -
                           1] = c[2];
              bufferQuat_idx_0 = TG.quatList[loop_ub];
              bufferQuat_idx_1 = TG.quatList[loop_ub + TG.quatList.size(0)];
              bufferQuat_idx_2 = TG.quatList[loop_ub + TG.quatList.size(0) * 2];
              bufferQuat_idx_3 = TG.quatList[loop_ub + TG.quatList.size(0) * 3];
              status = TG.MAPM.Pose[loop_ub].Rotation;
              // ==================================================================
              //  Fonnction qui retoure le quaternion le plus court/long selon
              //  l'utilisateur
              b_d = ((bufferQuat_idx_0 * q_idx_0 + bufferQuat_idx_1 * q_idx_1) +
                     bufferQuat_idx_2 * q_idx_2) +
                    bufferQuat_idx_3 * q_idx_3;
              //  conjuger le quaternion au besoin
              if (((b_d > 1.0) && (!status)) || ((b_d < 1.0) && status)) {
                q_idx_1 = -q_idx_1;
                q_idx_2 = -q_idx_2;
                q_idx_3 = -q_idx_3;
              }
              TG.quatList[static_cast<int>(
                              (static_cast<double>(loop_ub) + 1.0) + 1.0) -
                          1] =
                  ((bufferQuat_idx_0 * q_idx_0 - bufferQuat_idx_1 * q_idx_1) -
                   bufferQuat_idx_2 * q_idx_2) -
                  bufferQuat_idx_3 * q_idx_3;
              TG.quatList[(static_cast<int>(
                               (static_cast<double>(loop_ub) + 1.0) + 1.0) +
                           TG.quatList.size(0)) -
                          1] =
                  (bufferQuat_idx_0 * q_idx_1 + q_idx_0 * bufferQuat_idx_1) +
                  (bufferQuat_idx_2 * q_idx_3 - q_idx_2 * bufferQuat_idx_3);
              TG.quatList[(static_cast<int>(
                               (static_cast<double>(loop_ub) + 1.0) + 1.0) +
                           TG.quatList.size(0) * 2) -
                          1] =
                  (bufferQuat_idx_0 * q_idx_2 + q_idx_0 * bufferQuat_idx_2) +
                  (q_idx_1 * bufferQuat_idx_3 - bufferQuat_idx_1 * q_idx_3);
              TG.quatList[(static_cast<int>(
                               (static_cast<double>(loop_ub) + 1.0) + 1.0) +
                           TG.quatList.size(0) * 3) -
                          1] =
                  (bufferQuat_idx_0 * q_idx_3 + q_idx_0 * bufferQuat_idx_3) +
                  (bufferQuat_idx_1 * q_idx_2 - q_idx_1 * bufferQuat_idx_2);
              loop_ub++;
            } break;
            default:
              //  Le referentiel n'est pas valide
              exitg1 = 1;
              break;
            }
          } else {
            //  Calculer les temps entre chaque waypoints
            // ==================================================================
            //  Fonnction qui calcul le temps entre chaque waypoint
            d = TG.n;
            i = static_cast<int>(d + -1.0);
            for (loop_ub = 0; loop_ub < i; loop_ub++) {
              double b_d;
              double bufferQuat_idx_0;
              double bufferQuat_idx_1;
              double bufferQuat_idx_2;
              double bufferQuat_idx_3;
              double q_idx_0;
              double q_idx_1;
              double q_idx_2;
              double q_idx_3;
              double tl;
              //  pour chaques waypoints
              //  Trouver la distance Eucledienne entre 2 points
              s[0] = TG.pointList[loop_ub + 1] - TG.pointList[loop_ub];
              s[1] = TG.pointList[(loop_ub + TG.pointList.size(0)) + 1] -
                     TG.pointList[loop_ub + TG.pointList.size(0)];
              s[2] = TG.pointList[(loop_ub + TG.pointList.size(0) * 2) + 1] -
                     TG.pointList[loop_ub + TG.pointList.size(0) * 2];
              b_d = coder::b_norm(s);
              //  Déterminer le temps selon aMax
              vl = TG.param.amax;
              tl = 4.0 * std::sqrt(3.0 * b_d) / (3.0 * std::sqrt(vl));
              //  Déterminer la vitesse maximum de la trajectoire
              vl = TG.param.amax * tl / 4.0;
              //  Si la vitesse est plus grande que la vitesse maximum
              if (vl > TG.param.vlmax) {
                //  Calculer le temps selon vmax
                tl = 4.0 * b_d / (3.0 * TG.param.vlmax);
              }
              //  Déterminer l'angle entre les 2 quaternions
              q_idx_0 = TG.quatList[loop_ub];
              q_idx_1 = TG.quatList[loop_ub + TG.quatList.size(0)];
              q_idx_2 = TG.quatList[loop_ub + TG.quatList.size(0) * 2];
              q_idx_3 = TG.quatList[loop_ub + TG.quatList.size(0) * 3];
              q_idx_1 = -q_idx_1;
              q_idx_2 = -q_idx_2;
              q_idx_3 = -q_idx_3;
              bufferQuat_idx_0 = TG.quatList[loop_ub + 1];
              bufferQuat_idx_1 =
                  TG.quatList[(loop_ub + TG.quatList.size(0)) + 1];
              bufferQuat_idx_2 =
                  TG.quatList[(loop_ub + TG.quatList.size(0) * 2) + 1];
              bufferQuat_idx_3 =
                  TG.quatList[(loop_ub + TG.quatList.size(0) * 3) + 1];
              qRel[0] =
                  ((q_idx_0 * bufferQuat_idx_0 - q_idx_1 * bufferQuat_idx_1) -
                   q_idx_2 * bufferQuat_idx_2) -
                  q_idx_3 * bufferQuat_idx_3;
              qRel[1] =
                  (q_idx_0 * bufferQuat_idx_1 + bufferQuat_idx_0 * q_idx_1) +
                  (q_idx_2 * bufferQuat_idx_3 - bufferQuat_idx_2 * q_idx_3);
              qRel[2] =
                  (q_idx_0 * bufferQuat_idx_2 + bufferQuat_idx_0 * q_idx_2) +
                  (bufferQuat_idx_1 * q_idx_3 - q_idx_1 * bufferQuat_idx_3);
              qRel[3] =
                  (q_idx_0 * bufferQuat_idx_3 + bufferQuat_idx_0 * q_idx_3) +
                  (q_idx_1 * bufferQuat_idx_2 - bufferQuat_idx_1 * q_idx_2);
              //  Déterminer le temps angulaire
              vl = 2.0 *
                   rt_atan2d_snf(coder::b_norm(*(double(*)[3]) & qRel[1]),
                                 qRel[0]) /
                   TG.param.vamax;
              c[0] = tl;
              c[1] = vl;
              c[2] = TG.param.ts;
              TG.timeList[loop_ub + 1] =
                  TG.timeList[loop_ub] + coder::internal::maximum(c);
            }
            //  Déterminer le nombre de points
            vl = TG.timeList[TG.timeList.size(0) - 1] / TG.param.ts;
            vl = std::floor(vl);
            TG.nbPoint = vl;
            exitg1 = 1;
          }
        } while (exitg1 == 0);
      }
      TG.matlabCodegenIsDeleted = false;
      //  Interpoler les waypoints
      // ==================================================================
      //  Fonction Main qui génère les waypoints
      //  Crée l'objet waypoint trajectory
      // ==================================================================
      //  Fonnction qui interpole les waypoints
      r2.init(TG.quatList);
      b_TG.set_size(TG.pointList.size(0), 3);
      loop_ub = TG.pointList.size(0) * TG.pointList.size(1) - 1;
      for (i = 0; i <= loop_ub; i++) {
        b_TG[i] = TG.pointList[i];
      }
      c_TG.set_size(TG.timeList.size(0));
      loop_ub = TG.timeList.size(0) - 1;
      for (i = 0; i <= loop_ub; i++) {
        c_TG[i] = TG.timeList[i];
      }
      trajObj.init(b_TG, c_TG, 1.0 / TG.param.ts, &r2);
      //  Initialiser le message trajectoire.
      trajectory_msgs_MultiDOFJointTrajectoryPointStruct(&trajMsg);
      //  message point
      geometry_msgs_TransformStruct(&transformBuff);
      //  trajectoire
      geometry_msgs_TwistStruct(&twistBuff);
      //  trajectoire
      //  initialiser la dimention vecteur de points
      vl = TG.nbPoint;
      i = static_cast<int>(vl);
      y.set_size(1, i);
      for (loop_ub = 0; loop_ub < i; loop_ub++) {
        y[loop_ub] = transformBuff;
      }
      trajMsg.Transforms.set_size(y.size(1));
      loop_ub = y.size(1);
      for (i = 0; i < loop_ub; i++) {
        trajMsg.Transforms[i] = y[i];
      }
      coder::repelem(&twistBuff, TG.nbPoint, r3);
      trajMsg.Velocities.set_size(r3.size(1));
      loop_ub = r3.size(1);
      for (i = 0; i < loop_ub; i++) {
        trajMsg.Velocities[i] = r3[i];
      }
      coder::repelem(&twistBuff, TG.nbPoint, r3);
      trajMsg.Accelerations.set_size(r3.size(1));
      loop_ub = r3.size(1);
      for (i = 0; i < loop_ub; i++) {
        trajMsg.Accelerations[i] = r3[i];
      }
      //  Générer les points de la trajectoire
      d = TG.nbPoint;
      i = static_cast<int>(d);
      for (loop_ub = 0; loop_ub < i; loop_ub++) {
        trajObj.step(c, &varargout_2, s, a, varargout_5);
        //  Remplire le message Transform.
        transformBuff.Translation.X = c[0];
        transformBuff.Translation.Y = c[1];
        transformBuff.Translation.Z = c[2];
        //  Convertir l'objet quaternion en vecteur
        transformBuff.Rotation.W = varargout_2.a;
        transformBuff.Rotation.X = varargout_2.b;
        transformBuff.Rotation.Y = varargout_2.c;
        transformBuff.Rotation.Z = varargout_2.d;
        trajMsg.Transforms[loop_ub] = transformBuff;
        //  Remplire les vitesse
        twistBuff.Linear.X = s[0];
        twistBuff.Linear.Y = s[1];
        twistBuff.Linear.Z = s[2];
        twistBuff.Angular.X = varargout_5[0];
        twistBuff.Angular.Y = varargout_5[1];
        twistBuff.Angular.Z = varargout_5[2];
        trajMsg.Velocities[loop_ub] = twistBuff;
        //  Ecrire le point dans le message
        //  Remplire les acceleration
        twistBuff.Linear.X = a[0];
        twistBuff.Linear.Y = a[1];
        twistBuff.Linear.Z = a[2];
        twistBuff.Angular.X = 0.0;
        twistBuff.Angular.Y = 0.0;
        twistBuff.Angular.Z = 0.0;
        trajMsg.Accelerations[loop_ub] = twistBuff;
        //  Envoyer le message
        trajpub.send(&trajMsg);
      }
    }
    b_r.waitfor();
  }
}

//
// File trailer for proc_planner.cpp
//
// [EOF]
//
