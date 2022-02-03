//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: proc_planner.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 02-Feb-2022 17:45:08
//

// Include Files
#include "proc_planner.h"
#include "Publisher.h"
#include "Rate.h"
#include "Subscriber.h"
#include "TrajectoryGenerator.h"
#include "dot.h"
#include "geometry_msgs_TransformStruct.h"
#include "geometry_msgs_TwistStruct.h"
#include "minOrMax.h"
#include "norm.h"
#include "proc_planner_data.h"
#include "proc_planner_initialize.h"
#include "proc_planner_internal_types.h"
#include "proc_planner_rtwutil.h"
#include "proc_planner_types.h"
#include "quaternion.h"
#include "rt_nonfinite.h"
#include "sonia_common_AddPoseStruct.h"
#include "sonia_common_MultiAddPoseStruct.h"
#include "std_msgs_BoolStruct.h"
#include "trajectory_msgs_MultiDOFJointTrajectoryPointStruct.h"
#include "waypointTrajectory.h"
#include "coder_array.h"
#include <cmath>
#include <string.h>

// Function Definitions
//
// Definir les message ros
//
// Arguments    : void
// Return Type  : void
//
void proc_planner()
{
  TrajectoryGenerator TG;
  coder::b_quaternion varargout_2;
  coder::quaternion obj;
  coder::ros::Publisher pospub;
  coder::ros::Rate b_r;
  coder::ros::Subscriber mapSub;
  coder::ros::b_Publisher trajpub;
  coder::ros::b_Subscriber *sub;
  coder::ros::c_Publisher validSub;
  coder::waypointTrajectory trajObj;
  coder::array<geometry_msgs_TransformStruct_T, 2U> y;
  coder::array<geometry_msgs_TwistStruct_T, 2U> b_y;
  coder::array<sonia_common_AddPoseStruct_T, 1U> rMaddposemsg_Pose;
  coder::array<double, 2U> c_TG;
  coder::array<double, 1U> b_TG;
  geometry_msgs_PointStruct_T t3_Position;
  geometry_msgs_QuaternionStruct_T t3_Orientation;
  geometry_msgs_TransformStruct_T transformBuff;
  geometry_msgs_TwistStruct_T twistBuff;
  sonia_common_AddPoseStruct_T unusedExpr;
  sonia_common_MultiAddPoseStruct_T r;
  sonia_common_MultiAddPoseStruct_T r1;
  std_msgs_BoolStruct_T validMsg;
  trajectory_msgs_MultiDOFJointTrajectoryPointStruct_T trajMsg;
  double bufferQuat[4];
  double q[4];
  double qRel[4];
  double a[3];
  double c[3];
  double s[3];
  double varargout_5[3];
  char rMaddposemsg_MessageType[25];
  char t3_MessageType[18];
  bool status;
  if (!isInitialized_proc_planner) {
    proc_planner_initialize();
  }
  pospub.matlabCodegenIsDeleted = true;
  mapSub.matlabCodegenIsDeleted = true;
  trajpub.matlabCodegenIsDeleted = true;
  validSub.matlabCodegenIsDeleted = true;
  TG._pobj0.matlabCodegenIsDeleted = true;
  TG.matlabCodegenIsDeleted = true;
  sonia_common_AddPoseStruct(&unusedExpr);
  sonia_common_MultiAddPoseStruct(&r);
  sonia_common_MultiAddPoseStruct(&r1);
  validMsg = std_msgs_BoolStruct();
  //  Definir les publisher ros
  pospub.init();
  mapSub.init();
  //  Definir les Subscrier ROS
  trajpub.init();
  validSub.init();
  //  Definir les parametre de trajectoire
  b_r.init();
  while (1) {
    mapSub.receive(rMaddposemsg_MessageType, rMaddposemsg_Pose, &status);
    //  Si Recois un nouveau message
    if (status) {
      double b_d;
      double d;
      double tl;
      double vl;
      int b_i;
      int i;
      int loop_ub;
      TG.matlabCodegenDestructor();
      TG._pobj0.matlabCodegenDestructor();
      TG.status = 1.0;
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
      TG.n = 3.0;
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
      TG.icSub->receive(t3_MessageType, &t3_Position, &t3_Orientation, &status);
      for (i = 0; i < 18; i++) {
        TG.icMsg.MessageType[i] = t3_MessageType[i];
      }
      TG.icMsg.Position = t3_Position;
      TG.icMsg.Orientation = t3_Orientation;
      //              this.icMsg = this.icSub.LatestMessage;
      //
      //              status = ~isempty(this.icMsg);
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
        d = TG.n - 2.0;
        b_i = 0;
        int exitg1;
        do {
          exitg1 = 0;
          if (b_i <= static_cast<int>(d) - 1) {
            //  pour chaques waypoints
            //  transformer les angle d'euler quaternions
            s[0] = TG.MAPM.Pose[b_i].Orientation.Z;
            s[1] = TG.MAPM.Pose[b_i].Orientation.Y;
            s[2] = TG.MAPM.Pose[b_i].Orientation.X;
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
            q[0] = b_d * c[2] + tl * vl;
            q[1] = b_d * vl - tl * c[2];
            b_d = s[0] * c[1];
            tl = c[0] * s[1];
            q[2] = tl * c[2] + b_d * vl;
            q[3] = b_d * c[2] - tl * vl;
            //  cree le vecteur pose
            c[0] = TG.MAPM.Pose[b_i].Position.X;
            c[1] = TG.MAPM.Pose[b_i].Position.Y;
            c[2] = TG.MAPM.Pose[b_i].Position.Z;
            //  transformer le point en fonction du frame
            switch (TG.MAPM.Pose[b_i].Frame) {
            case 0U:
              //  position et angle absolue
              TG.pointList[static_cast<int>((static_cast<double>(b_i) + 1.0) +
                                            1.0) -
                           1] = c[0];
              TG.pointList[(static_cast<int>((static_cast<double>(b_i) + 1.0) +
                                             1.0) +
                            TG.pointList.size(0)) -
                           1] = c[1];
              TG.pointList[(static_cast<int>((static_cast<double>(b_i) + 1.0) +
                                             1.0) +
                            TG.pointList.size(0) * 2) -
                           1] = c[2];
              TG.quatList[static_cast<int>((static_cast<double>(b_i) + 1.0) +
                                           1.0) -
                          1] = q[0];
              TG.quatList[(static_cast<int>((static_cast<double>(b_i) + 1.0) +
                                            1.0) +
                           TG.quatList.size(0)) -
                          1] = q[1];
              TG.quatList[(static_cast<int>((static_cast<double>(b_i) + 1.0) +
                                            1.0) +
                           TG.quatList.size(0) * 2) -
                          1] = q[2];
              TG.quatList[(static_cast<int>((static_cast<double>(b_i) + 1.0) +
                                            1.0) +
                           TG.quatList.size(0) * 3) -
                          1] = q[3];
              b_i++;
              break;
            case 1U:
              //  position et angle relatif
              // =================================================================
              //  Fonction qui tourne un vecteur selon un quaternion.
              //  quaternion partie scalaire
              //  quaternion partie vectoriel
              //  QuatRotate n'est pas compilable
              b_d = 2.0 * coder::dot(*(double(*)[3]) & q[1], c);
              tl = q[0] * q[0] -
                   coder::dot(*(double(*)[3]) & q[1], *(double(*)[3]) & q[1]);
              vl = 2.0 * q[0];
              s[0] = TG.pointList[b_i] + ((b_d * q[1] + tl * c[0]) +
                                          vl * (q[2] * c[2] - c[1] * q[3]));
              s[1] =
                  TG.pointList[b_i + TG.pointList.size(0)] +
                  ((b_d * q[2] + tl * c[1]) + vl * (c[0] * q[3] - q[1] * c[2]));
              s[2] =
                  TG.pointList[b_i + TG.pointList.size(0) * 2] +
                  ((b_d * q[3] + tl * c[2]) + vl * (q[1] * c[1] - c[0] * q[2]));
              TG.pointList[static_cast<int>((static_cast<double>(b_i) + 1.0) +
                                            1.0) -
                           1] = s[0];
              TG.pointList[(static_cast<int>((static_cast<double>(b_i) + 1.0) +
                                             1.0) +
                            TG.pointList.size(0)) -
                           1] = s[1];
              TG.pointList[(static_cast<int>((static_cast<double>(b_i) + 1.0) +
                                             1.0) +
                            TG.pointList.size(0) * 2) -
                           1] = s[2];
              bufferQuat[0] = TG.quatList[b_i];
              bufferQuat[1] = TG.quatList[b_i + TG.quatList.size(0)];
              bufferQuat[2] = TG.quatList[b_i + TG.quatList.size(0) * 2];
              bufferQuat[3] = TG.quatList[b_i + TG.quatList.size(0) * 3];
              status = TG.MAPM.Pose[b_i].Rotation;
              // ==================================================================
              //  Fonnction qui retoure le quaternion le plus court/long selon
              //  l'utilisateur
              vl = ((bufferQuat[0] * q[0] + bufferQuat[1] * q[1]) +
                    bufferQuat[2] * q[2]) +
                   bufferQuat[3] * q[3];
              //  conjuger le quaternion au besoin
              if (((vl > 1.0) && (!status)) || ((vl < 1.0) && status)) {
                q[1] = -q[1];
                q[2] = -q[2];
                q[3] = -q[3];
              }
              TG.quatList[static_cast<int>((static_cast<double>(b_i) + 1.0) +
                                           1.0) -
                          1] = ((bufferQuat[0] * q[0] - bufferQuat[1] * q[1]) -
                                bufferQuat[2] * q[2]) -
                               bufferQuat[3] * q[3];
              TG.quatList[(static_cast<int>((static_cast<double>(b_i) + 1.0) +
                                            1.0) +
                           TG.quatList.size(0)) -
                          1] = (bufferQuat[0] * q[1] + q[0] * bufferQuat[1]) +
                               (bufferQuat[2] * q[3] - q[2] * bufferQuat[3]);
              TG.quatList[(static_cast<int>((static_cast<double>(b_i) + 1.0) +
                                            1.0) +
                           TG.quatList.size(0) * 2) -
                          1] = (bufferQuat[0] * q[2] + q[0] * bufferQuat[2]) +
                               (q[1] * bufferQuat[3] - bufferQuat[1] * q[3]);
              TG.quatList[(static_cast<int>((static_cast<double>(b_i) + 1.0) +
                                            1.0) +
                           TG.quatList.size(0) * 3) -
                          1] = (bufferQuat[0] * q[3] + q[0] * bufferQuat[3]) +
                               (bufferQuat[1] * q[2] - q[1] * bufferQuat[2]);
              b_i++;
              break;
            case 2U:
              //  position relatif et angle absolue
              // =================================================================
              //  Fonction qui tourne un vecteur selon un quaternion.
              //  quaternion partie scalaire
              //  quaternion partie vectoriel
              //  QuatRotate n'est pas compilable
              b_d = 2.0 * coder::dot(*(double(*)[3]) & q[1], c);
              tl = q[0] * q[0] -
                   coder::dot(*(double(*)[3]) & q[1], *(double(*)[3]) & q[1]);
              vl = 2.0 * q[0];
              s[0] = TG.pointList[b_i] + ((b_d * q[1] + tl * c[0]) +
                                          vl * (q[2] * c[2] - c[1] * q[3]));
              s[1] =
                  TG.pointList[b_i + TG.pointList.size(0)] +
                  ((b_d * q[2] + tl * c[1]) + vl * (c[0] * q[3] - q[1] * c[2]));
              s[2] =
                  TG.pointList[b_i + TG.pointList.size(0) * 2] +
                  ((b_d * q[3] + tl * c[2]) + vl * (q[1] * c[1] - c[0] * q[2]));
              TG.pointList[static_cast<int>((static_cast<double>(b_i) + 1.0) +
                                            1.0) -
                           1] = s[0];
              TG.pointList[(static_cast<int>((static_cast<double>(b_i) + 1.0) +
                                             1.0) +
                            TG.pointList.size(0)) -
                           1] = s[1];
              TG.pointList[(static_cast<int>((static_cast<double>(b_i) + 1.0) +
                                             1.0) +
                            TG.pointList.size(0) * 2) -
                           1] = s[2];
              TG.quatList[static_cast<int>((static_cast<double>(b_i) + 1.0) +
                                           1.0) -
                          1] = q[0];
              TG.quatList[(static_cast<int>((static_cast<double>(b_i) + 1.0) +
                                            1.0) +
                           TG.quatList.size(0)) -
                          1] = q[1];
              TG.quatList[(static_cast<int>((static_cast<double>(b_i) + 1.0) +
                                            1.0) +
                           TG.quatList.size(0) * 2) -
                          1] = q[2];
              TG.quatList[(static_cast<int>((static_cast<double>(b_i) + 1.0) +
                                            1.0) +
                           TG.quatList.size(0) * 3) -
                          1] = q[3];
              b_i++;
              break;
            case 3U:
              //  position absolue et angle relatif
              TG.pointList[static_cast<int>((static_cast<double>(b_i) + 1.0) +
                                            1.0) -
                           1] = c[0];
              TG.pointList[(static_cast<int>((static_cast<double>(b_i) + 1.0) +
                                             1.0) +
                            TG.pointList.size(0)) -
                           1] = c[1];
              TG.pointList[(static_cast<int>((static_cast<double>(b_i) + 1.0) +
                                             1.0) +
                            TG.pointList.size(0) * 2) -
                           1] = c[2];
              bufferQuat[0] = TG.quatList[b_i];
              bufferQuat[1] = TG.quatList[b_i + TG.quatList.size(0)];
              bufferQuat[2] = TG.quatList[b_i + TG.quatList.size(0) * 2];
              bufferQuat[3] = TG.quatList[b_i + TG.quatList.size(0) * 3];
              status = TG.MAPM.Pose[b_i].Rotation;
              // ==================================================================
              //  Fonnction qui retoure le quaternion le plus court/long selon
              //  l'utilisateur
              vl = ((bufferQuat[0] * q[0] + bufferQuat[1] * q[1]) +
                    bufferQuat[2] * q[2]) +
                   bufferQuat[3] * q[3];
              //  conjuger le quaternion au besoin
              if (((vl > 1.0) && (!status)) || ((vl < 1.0) && status)) {
                q[1] = -q[1];
                q[2] = -q[2];
                q[3] = -q[3];
              }
              TG.quatList[static_cast<int>((static_cast<double>(b_i) + 1.0) +
                                           1.0) -
                          1] = ((bufferQuat[0] * q[0] - bufferQuat[1] * q[1]) -
                                bufferQuat[2] * q[2]) -
                               bufferQuat[3] * q[3];
              TG.quatList[(static_cast<int>((static_cast<double>(b_i) + 1.0) +
                                            1.0) +
                           TG.quatList.size(0)) -
                          1] = (bufferQuat[0] * q[1] + q[0] * bufferQuat[1]) +
                               (bufferQuat[2] * q[3] - q[2] * bufferQuat[3]);
              TG.quatList[(static_cast<int>((static_cast<double>(b_i) + 1.0) +
                                            1.0) +
                           TG.quatList.size(0) * 2) -
                          1] = (bufferQuat[0] * q[2] + q[0] * bufferQuat[2]) +
                               (q[1] * bufferQuat[3] - bufferQuat[1] * q[3]);
              TG.quatList[(static_cast<int>((static_cast<double>(b_i) + 1.0) +
                                            1.0) +
                           TG.quatList.size(0) * 3) -
                          1] = (bufferQuat[0] * q[3] + q[0] * bufferQuat[3]) +
                               (bufferQuat[1] * q[2] - q[1] * bufferQuat[2]);
              b_i++;
              break;
            default:
              //  Le referentiel n'est pas valide
              TG.status = 0.0;
              exitg1 = 1;
              break;
            }
          } else {
            //  Copier le dernier waypoint 2 fois pour éviter un comportement
            //  du generateur de trajecteur
            loop_ub = TG.pointList.size(0) - 2;
            b_i = TG.pointList.size(0) - 1;
            s[0] = TG.pointList[loop_ub];
            s[1] = TG.pointList[loop_ub + TG.pointList.size(0)];
            s[2] = TG.pointList[loop_ub + TG.pointList.size(0) * 2];
            TG.pointList[b_i] = s[0];
            TG.pointList[b_i + TG.pointList.size(0)] = s[1];
            TG.pointList[b_i + TG.pointList.size(0) * 2] = s[2];
            loop_ub = TG.quatList.size(0) - 2;
            b_i = TG.quatList.size(0) - 1;
            q[0] = TG.quatList[loop_ub];
            q[1] = TG.quatList[loop_ub + TG.quatList.size(0)];
            q[2] = TG.quatList[loop_ub + TG.quatList.size(0) * 2];
            q[3] = TG.quatList[loop_ub + TG.quatList.size(0) * 3];
            TG.quatList[b_i] = q[0];
            TG.quatList[b_i + TG.quatList.size(0)] = q[1];
            TG.quatList[b_i + TG.quatList.size(0) * 2] = q[2];
            TG.quatList[b_i + TG.quatList.size(0) * 3] = q[3];
            //  Calculer les temps entre chaque waypoints
            // ==================================================================
            //  Fonnction qui calcul le temps entre chaque waypoint
            d = TG.n;
            i = static_cast<int>(d + -1.0);
            for (b_i = 0; b_i < i; b_i++) {
              //  pour chaques waypoints
              //  Trouver la distance Eucledienne entre 2 points
              s[0] = TG.pointList[b_i + 1] - TG.pointList[b_i];
              s[1] = TG.pointList[(b_i + TG.pointList.size(0)) + 1] -
                     TG.pointList[b_i + TG.pointList.size(0)];
              s[2] = TG.pointList[(b_i + TG.pointList.size(0) * 2) + 1] -
                     TG.pointList[b_i + TG.pointList.size(0) * 2];
              b_d = coder::b_norm(s);
              //  Déterminer le temps selon aMax
              vl = TG.param.amax;
              vl = std::sqrt(vl);
              tl = 4.0 * std::sqrt(3.0 * b_d) / (3.0 * vl);
              //  Déterminer la vitesse maximum de la trajectoire
              vl = TG.param.amax * tl / 4.0;
              //  Si la vitesse est plus grande que la vitesse maximum
              if (vl > TG.param.vlmax) {
                //  Calculer le temps selon vmax
                tl = 4.0 * b_d / (3.0 * TG.param.vlmax);
              }
              //  Déterminer l'angle entre les 2 quaternions
              q[0] = TG.quatList[b_i];
              q[1] = TG.quatList[b_i + TG.quatList.size(0)];
              q[2] = TG.quatList[b_i + TG.quatList.size(0) * 2];
              q[3] = TG.quatList[b_i + TG.quatList.size(0) * 3];
              q[1] = -q[1];
              q[2] = -q[2];
              q[3] = -q[3];
              bufferQuat[0] = TG.quatList[b_i + 1];
              bufferQuat[1] = TG.quatList[(b_i + TG.quatList.size(0)) + 1];
              bufferQuat[2] = TG.quatList[(b_i + TG.quatList.size(0) * 2) + 1];
              bufferQuat[3] = TG.quatList[(b_i + TG.quatList.size(0) * 3) + 1];
              qRel[0] = ((q[0] * bufferQuat[0] - q[1] * bufferQuat[1]) -
                         q[2] * bufferQuat[2]) -
                        q[3] * bufferQuat[3];
              qRel[1] = (q[0] * bufferQuat[1] + bufferQuat[0] * q[1]) +
                        (q[2] * bufferQuat[3] - bufferQuat[2] * q[3]);
              qRel[2] = (q[0] * bufferQuat[2] + bufferQuat[0] * q[2]) +
                        (bufferQuat[1] * q[3] - q[1] * bufferQuat[3]);
              qRel[3] = (q[0] * bufferQuat[3] + bufferQuat[0] * q[3]) +
                        (q[1] * bufferQuat[2] - bufferQuat[1] * q[2]);
              //  Déterminer le temps angulaire
              vl = 2.0 *
                   rt_atan2d_snf(coder::b_norm(*(double(*)[3]) & qRel[1]),
                                 qRel[0]) /
                   TG.param.vamax;
              c[0] = tl;
              c[1] = vl;
              c[2] = TG.param.ts;
              TG.timeList[b_i + 1] =
                  TG.timeList[b_i] + coder::internal::maximum(c);
            }
            //  Déterminer le nombre de points
            vl = TG.timeList[TG.timeList.size(0) - 1] / TG.param.ts;
            vl = std::floor(vl);
            TG.nbPoint = vl;
            exitg1 = 1;
          }
        } while (exitg1 == 0);
      } else {
        TG.status = 0.0;
      }
      TG.matlabCodegenIsDeleted = false;
      //  Envoyer a ros si le mAddpose est valide
      validMsg.Data = (TG.status != 0.0);
      validSub.send(validMsg);
      //  Si la trajectoire est valide
      if (TG.status != 0.0) {
        //  Interpoler les waypoints
        // ==================================================================
        //  Fonction Main qui génère les waypoints
        //  Crée l'objet waypoint trajectory
        // ==================================================================
        //  Fonnction qui interpole les waypoints
        if (TG.quatList.size(0) == 0) {
          obj.a.set_size(TG.quatList.size(0), 4);
          loop_ub = TG.quatList.size(0) * 4;
          for (i = 0; i < loop_ub; i++) {
            obj.a[i] = TG.quatList[i];
          }
          obj.b.set_size(TG.quatList.size(0), 4);
          loop_ub = TG.quatList.size(0) * 4;
          for (i = 0; i < loop_ub; i++) {
            obj.b[i] = TG.quatList[i];
          }
          obj.c.set_size(TG.quatList.size(0), 4);
          loop_ub = TG.quatList.size(0) * 4;
          for (i = 0; i < loop_ub; i++) {
            obj.c[i] = TG.quatList[i];
          }
          obj.d.set_size(TG.quatList.size(0), 4);
          loop_ub = TG.quatList.size(0) * 4;
          for (i = 0; i < loop_ub; i++) {
            obj.d[i] = TG.quatList[i];
          }
        } else {
          loop_ub = TG.quatList.size(0);
          b_i = TG.quatList.size(0);
          b_TG.set_size(b_i);
          for (i = 0; i < b_i; i++) {
            b_TG[i] = TG.quatList[i];
          }
          obj.a.set_size(loop_ub, 1);
          for (i = 0; i < loop_ub; i++) {
            obj.a[i] = b_TG[i];
          }
          loop_ub = TG.quatList.size(0);
          b_i = TG.quatList.size(0);
          b_TG.set_size(b_i);
          for (i = 0; i < b_i; i++) {
            b_TG[i] = TG.quatList[i + TG.quatList.size(0)];
          }
          obj.b.set_size(loop_ub, 1);
          for (i = 0; i < loop_ub; i++) {
            obj.b[i] = b_TG[i];
          }
          loop_ub = TG.quatList.size(0);
          b_i = TG.quatList.size(0);
          b_TG.set_size(b_i);
          for (i = 0; i < b_i; i++) {
            b_TG[i] = TG.quatList[i + TG.quatList.size(0) * 2];
          }
          obj.c.set_size(loop_ub, 1);
          for (i = 0; i < loop_ub; i++) {
            obj.c[i] = b_TG[i];
          }
          loop_ub = TG.quatList.size(0);
          b_i = TG.quatList.size(0);
          b_TG.set_size(b_i);
          for (i = 0; i < b_i; i++) {
            b_TG[i] = TG.quatList[i + TG.quatList.size(0) * 3];
          }
          obj.d.set_size(loop_ub, 1);
          for (i = 0; i < loop_ub; i++) {
            obj.d[i] = b_TG[i];
          }
        }
        c_TG.set_size(TG.pointList.size(0), 3);
        loop_ub = TG.pointList.size(0) * TG.pointList.size(1) - 1;
        for (i = 0; i <= loop_ub; i++) {
          c_TG[i] = TG.pointList[i];
        }
        b_TG.set_size(TG.timeList.size(0));
        loop_ub = TG.timeList.size(0) - 1;
        for (i = 0; i <= loop_ub; i++) {
          b_TG[i] = TG.timeList[i];
        }
        trajObj.init(c_TG, b_TG, 1.0 / TG.param.ts, &obj);
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
        vl = TG.nbPoint;
        i = static_cast<int>(vl);
        b_y.set_size(1, i);
        for (loop_ub = 0; loop_ub < i; loop_ub++) {
          b_y[loop_ub] = twistBuff;
        }
        trajMsg.Velocities.set_size(b_y.size(1));
        loop_ub = b_y.size(1);
        for (i = 0; i < loop_ub; i++) {
          trajMsg.Velocities[i] = b_y[i];
        }
        vl = TG.nbPoint;
        i = static_cast<int>(vl);
        b_y.set_size(1, i);
        for (loop_ub = 0; loop_ub < i; loop_ub++) {
          b_y[loop_ub] = twistBuff;
        }
        trajMsg.Accelerations.set_size(b_y.size(1));
        loop_ub = b_y.size(1);
        for (i = 0; i < loop_ub; i++) {
          trajMsg.Accelerations[i] = b_y[i];
        }
        //  Générer les points de la trajectoire
        d = TG.nbPoint;
        i = static_cast<int>(d);
        for (b_i = 0; b_i < i; b_i++) {
          trajObj.step(c, &varargout_2, s, a, varargout_5);
          //  Remplire le message Transform.
          transformBuff.Translation.X = c[0];
          transformBuff.Translation.Y = c[1];
          transformBuff.Translation.Z = c[2];
          //  Convertir l'objet quaternion en vecteur
          bufferQuat[0] = varargout_2.a;
          bufferQuat[1] = varargout_2.b;
          bufferQuat[2] = varargout_2.c;
          bufferQuat[3] = varargout_2.d;
          transformBuff.Rotation.W = varargout_2.a;
          transformBuff.Rotation.X = varargout_2.b;
          transformBuff.Rotation.Y = varargout_2.c;
          transformBuff.Rotation.Z = varargout_2.d;
          trajMsg.Transforms[b_i] = transformBuff;
          //  Convertir les vitesse dans le ref sub
          // =================================================================
          //  Fonction qui tourne un vecteur selon un quaternion.
          //  quaternion partie scalaire
          //  quaternion partie vectoriel
          //  QuatRotate n'est pas compilable
          b_d = 2.0 * coder::dot(*(double(*)[3]) & bufferQuat[1], s);
          tl = varargout_2.a * varargout_2.a -
               coder::dot(*(double(*)[3]) & bufferQuat[1],
                          *(double(*)[3]) & bufferQuat[1]);
          vl = 2.0 * varargout_2.a;
          //  Remplire les vitesse
          twistBuff.Linear.X =
              (b_d * varargout_2.b + tl * s[0]) +
              vl * (varargout_2.c * s[2] - s[1] * varargout_2.d);
          twistBuff.Linear.Y =
              (b_d * varargout_2.c + tl * s[1]) +
              vl * (s[0] * varargout_2.d - varargout_2.b * s[2]);
          twistBuff.Linear.Z =
              (b_d * varargout_2.d + tl * s[2]) +
              vl * (varargout_2.b * s[1] - s[0] * varargout_2.c);
          twistBuff.Angular.X = -varargout_5[0];
          //  (-) pour convertir les vitesse angulaire dans le ref sub
          twistBuff.Angular.Y = -varargout_5[1];
          twistBuff.Angular.Z = -varargout_5[2];
          trajMsg.Velocities[b_i] = twistBuff;
          //  Ecrire le point dans le message
          //  Convertir les accels dans le ref sub
          // =================================================================
          //  Fonction qui tourne un vecteur selon un quaternion.
          //  quaternion partie scalaire
          //  quaternion partie vectoriel
          //  QuatRotate n'est pas compilable
          b_d = 2.0 * coder::dot(*(double(*)[3]) & bufferQuat[1], a);
          tl = varargout_2.a * varargout_2.a -
               coder::dot(*(double(*)[3]) & bufferQuat[1],
                          *(double(*)[3]) & bufferQuat[1]);
          //  Remplire les acceleration
          twistBuff.Linear.X =
              (b_d * varargout_2.b + tl * a[0]) +
              vl * (varargout_2.c * a[2] - a[1] * varargout_2.d);
          twistBuff.Linear.Y =
              (b_d * varargout_2.c + tl * a[1]) +
              vl * (a[0] * varargout_2.d - varargout_2.b * a[2]);
          twistBuff.Linear.Z =
              (b_d * varargout_2.d + tl * a[2]) +
              vl * (varargout_2.b * a[1] - a[0] * varargout_2.c);
          twistBuff.Angular.X = 0.0;
          twistBuff.Angular.Y = 0.0;
          twistBuff.Angular.Z = 0.0;
          trajMsg.Accelerations[b_i] = twistBuff;
        }
        //  Envoyer le message
        trajpub.send(&trajMsg);
        //  Si on roule en simulation
        //  Retourner true (sucess)
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
