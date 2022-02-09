//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: proc_planner.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 08-Feb-2022 23:30:50
//

// Include Files
#include "proc_planner.h"
#include "Publisher.h"
#include "Rate.h"
#include "Subscriber.h"
#include "TrajectoryGenerator.h"
#include "dot.h"
#include "geometry_msgs_PoseStruct.h"
#include "geometry_msgs_TransformStruct.h"
#include "geometry_msgs_TwistStruct.h"
#include "isequaln.h"
#include "minOrMax.h"
#include "norm.h"
#include "proc_planner_data.h"
#include "proc_planner_initialize.h"
#include "proc_planner_rtwutil.h"
#include "proc_planner_types.h"
#include "quaternion.h"
#include "repelem.h"
#include "rt_nonfinite.h"
#include "sonia_common_MultiAddPoseStruct.h"
#include "std_msgs_BoolStruct.h"
#include "trajectory_msgs_MultiDOFJointTrajectoryPointStruct.h"
#include "waypointTrajectory.h"
#include "coder_array.h"
#include <cmath>
#include <stdio.h>
#include <string.h>

// Function Definitions
//
// definir le node
//
// Arguments    : void
// Return Type  : void
//
void proc_planner()
{
  TrajectoryGenerator TG;
  coder::b_quaternion varargout_2;
  coder::quaternion r1;
  coder::ros::Publisher trajpub;
  coder::ros::Rate r;
  coder::ros::Subscriber mapSub;
  coder::ros::b_Publisher validPub;
  coder::ros::b_Subscriber icSub;
  coder::ros::c_Publisher mapPub;
  coder::ros::d_Publisher icPub;
  coder::waypointTrajectory trajObj;
  coder::array<geometry_msgs_TransformStruct_T, 2U> y;
  coder::array<geometry_msgs_TwistStruct_T, 2U> r2;
  coder::array<sonia_common_AddPoseStruct_T, 1U> Maddposemsg_Pose;
  coder::array<sonia_common_AddPoseStruct_T, 1U> t4_Pose;
  geometry_msgs_PointStruct_T icMsg_Position;
  geometry_msgs_PointStruct_T t5_Position;
  geometry_msgs_PoseStruct_T emptyIcMsg;
  geometry_msgs_QuaternionStruct_T icMsg_Orientation;
  geometry_msgs_QuaternionStruct_T t5_Orientation;
  geometry_msgs_TransformStruct_T transformBuff;
  geometry_msgs_TwistStruct_T twistBuff;
  sonia_common_MultiAddPoseStruct_T b_r;
  sonia_common_MultiAddPoseStruct_T emptyMAddPoseMsg;
  std_msgs_BoolStruct_T validMsg;
  trajectory_msgs_MultiDOFJointTrajectoryPointStruct_T trajMsg;
  double bufferQuat[4];
  double q[4];
  double qRel[4];
  double c[3];
  double s[3];
  double varargout_4[3];
  double varargout_5[3];
  double b_Maddposemsg_Pose[2];
  double d;
  double icMsg_Orientation_W;
  double icMsg_Orientation_Y;
  double icMsg_Position_X;
  double icMsg_Position_Y;
  double icMsg_Position_Z;
  double tl;
  char Maddposemsg_MessageType[25];
  char t4_MessageType[25];
  char icMsg_MessageType[18];
  char t5_MessageType[18];
  bool newInitalPose;
  bool newMaddPose;
  if (!isInitialized_proc_planner) {
    proc_planner_initialize();
  }
  mapSub.matlabCodegenIsDeleted = true;
  icSub.matlabCodegenIsDeleted = true;
  trajpub.matlabCodegenIsDeleted = true;
  validPub.matlabCodegenIsDeleted = true;
  mapPub.matlabCodegenIsDeleted = true;
  icPub.matlabCodegenIsDeleted = true;
  r.init();
  newMaddPose = false;
  newInitalPose = false;
  //  Definir les message ros
  sonia_common_MultiAddPoseStruct(&b_r);
  sonia_common_MultiAddPoseStruct(&emptyMAddPoseMsg);
  validMsg = std_msgs_BoolStruct();
  geometry_msgs_PoseStruct(&emptyIcMsg);
  //  IC topic
  geometry_msgs_PoseStruct(&emptyIcMsg);
  //  Definir les Subscrier ros
  mapSub.init();
  icSub.init();
  //  Definir les publisher ROS
  trajpub.init();
  validPub.init();
  mapPub.init();
  icPub.init();
  //  Definir les parametre de trajectoire
  //  Initialiser les topics
  mapSub.get_LatestMessage(Maddposemsg_MessageType, Maddposemsg_Pose);
  icSub.get_LatestMessage(icMsg_MessageType, &icMsg_Position,
                          &icMsg_Orientation);
  d = icMsg_Orientation.X;
  icMsg_Orientation_Y = icMsg_Orientation.Y;
  tl = icMsg_Orientation.Z;
  icMsg_Orientation_W = icMsg_Orientation.W;
  icMsg_Position_X = icMsg_Position.X;
  icMsg_Position_Y = icMsg_Position.Y;
  icMsg_Position_Z = icMsg_Position.Z;
  printf("INFO : proc planner : Node is started \n");
  fflush(stdout);
  printf("INFO : proc planner : Wait for poses \n");
  fflush(stdout);
  r.reset();
  while (1) {
    int i;
    // [ rMaddposemsg,status] = receive(mapSub,0.2);
    //  Si Recois un nouveau message MultiaddPose
    mapSub.get_LatestMessage(t4_MessageType, t4_Pose);
    if (!coder::isequaln(Maddposemsg_MessageType, Maddposemsg_Pose,
                         t4_MessageType, t4_Pose)) {
      mapSub.get_LatestMessage(Maddposemsg_MessageType, Maddposemsg_Pose);
      newMaddPose = true;
      printf("INFO : proc planner : Poses received \n");
      fflush(stdout);
      printf("INFO : proc planner : Wait for initial pose \n");
      fflush(stdout);
    }
    //  Si Recois un nouveau message initial waypoint
    icSub.get_LatestMessage(t5_MessageType, &t5_Position, &t5_Orientation);
    if ((!coder::isequaln(icMsg_MessageType, icMsg_Position.MessageType,
                          icMsg_Position_X, icMsg_Position_Y, icMsg_Position_Z,
                          icMsg_Orientation.MessageType, d, icMsg_Orientation_Y,
                          tl, icMsg_Orientation_W, t5_MessageType, t5_Position,
                          t5_Orientation)) &&
        newMaddPose) {
      icSub.get_LatestMessage(icMsg_MessageType, &t5_Position, &t5_Orientation);
      for (i = 0; i < 24; i++) {
        icMsg_Orientation.MessageType[i] = t5_Orientation.MessageType[i];
      }
      d = t5_Orientation.X;
      icMsg_Orientation_Y = t5_Orientation.Y;
      tl = t5_Orientation.Z;
      icMsg_Orientation_W = t5_Orientation.W;
      for (i = 0; i < 19; i++) {
        icMsg_Position.MessageType[i] = t5_Position.MessageType[i];
      }
      icMsg_Position_X = t5_Position.X;
      icMsg_Position_Y = t5_Position.Y;
      icMsg_Position_Z = t5_Position.Z;
      newInitalPose = true;
      printf("INFO : proc planner : Initial poses received \n");
      fflush(stdout);
    }
    //  [icMsg,status] = receive(icSub);
    if (newMaddPose && newInitalPose) {
      int loop_ub;
      int loop_ub_tmp;
      //  Cree l'objet trajectoire
      TG.status = true;
      TG.nbPoint = 1.0;
      // ==================================================================
      //  Constructeur
      //  nombre de waypoints + iC
      b_Maddposemsg_Pose[0] = Maddposemsg_Pose.size(0);
      b_Maddposemsg_Pose[1] = 1.0;
      TG.n = coder::internal::maximum(b_Maddposemsg_Pose) + 3.0;
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
      //  Initialiser les parametres
      //  trouver le waypoint initial
      //  lire la position initale
      //  [this.icMsg, status] = receive(this.icSub,5);
      // this.icMsg = this.icSub.LatestMessage;
      // ==================================================================
      //  Fonnction qui retoure le waypoint initial
      // status = ~isempty(this.icMsg);
      //  Replire les listes.
      TG.pointList[0] = icMsg_Position_X;
      TG.pointList[TG.pointList.size(0)] = icMsg_Position_Y;
      TG.pointList[TG.pointList.size(0) * 2] = icMsg_Position_Z;
      TG.quatList[0] = icMsg_Orientation_W;
      TG.quatList[TG.quatList.size(0)] = d;
      TG.quatList[TG.quatList.size(0) * 2] = icMsg_Orientation_Y;
      TG.quatList[TG.quatList.size(0) * 3] = tl;
      TG.timeList[0] = 0.0;
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
      TG.timeList[1] = 0.1;
      //  Process le message addpose
      // ==================================================================
      //  Fonction qui interprete les waypoints reçu par ROS
      loop_ub_tmp = 0;
      int exitg1;
      do {
        exitg1 = 0;
        if (loop_ub_tmp <= static_cast<int>(TG.n - 3.0) - 1) {
          //  pour chaques waypoints
          //  transformer les angle d'euler quaternions
          s[0] = 0.017453292519943295 *
                 Maddposemsg_Pose[loop_ub_tmp].Orientation.Z / 2.0;
          s[1] = 0.017453292519943295 *
                 Maddposemsg_Pose[loop_ub_tmp].Orientation.Y / 2.0;
          s[2] = 0.017453292519943295 *
                 Maddposemsg_Pose[loop_ub_tmp].Orientation.X / 2.0;
          c[0] = std::cos(s[0]);
          s[0] = std::sin(s[0]);
          c[1] = std::cos(s[1]);
          s[1] = std::sin(s[1]);
          c[2] = std::cos(s[2]);
          s[2] = std::sin(s[2]);
          d = c[0] * c[1];
          icMsg_Orientation_Y = s[0] * s[1];
          q[0] = d * c[2] + icMsg_Orientation_Y * s[2];
          q[1] = d * s[2] - icMsg_Orientation_Y * c[2];
          d = s[0] * c[1];
          icMsg_Orientation_Y = c[0] * s[1];
          q[2] = icMsg_Orientation_Y * c[2] + d * s[2];
          q[3] = d * c[2] - icMsg_Orientation_Y * s[2];
          //  cree le vecteur pose
          d = Maddposemsg_Pose[loop_ub_tmp].Position.X;
          c[0] = d;
          icMsg_Orientation_Y = Maddposemsg_Pose[loop_ub_tmp].Position.Y;
          c[1] = icMsg_Orientation_Y;
          icMsg_Orientation_W = Maddposemsg_Pose[loop_ub_tmp].Position.Z;
          c[2] = icMsg_Orientation_W;
          //  transformer le point en fonction du frame
          switch (Maddposemsg_Pose[loop_ub_tmp].Frame) {
          case 0U:
            //  position et angle absolue
            TG.pointList[static_cast<int>(
                             (static_cast<double>(loop_ub_tmp) + 1.0) + 2.0) -
                         1] = d;
            TG.pointList[(static_cast<int>(
                              (static_cast<double>(loop_ub_tmp) + 1.0) + 2.0) +
                          TG.pointList.size(0)) -
                         1] = icMsg_Orientation_Y;
            TG.pointList[(static_cast<int>(
                              (static_cast<double>(loop_ub_tmp) + 1.0) + 2.0) +
                          TG.pointList.size(0) * 2) -
                         1] = icMsg_Orientation_W;
            TG.quatList[static_cast<int>(
                            (static_cast<double>(loop_ub_tmp) + 1.0) + 2.0) -
                        1] = q[0];
            TG.quatList[(static_cast<int>(
                             (static_cast<double>(loop_ub_tmp) + 1.0) + 2.0) +
                         TG.quatList.size(0)) -
                        1] = q[1];
            TG.quatList[(static_cast<int>(
                             (static_cast<double>(loop_ub_tmp) + 1.0) + 2.0) +
                         TG.quatList.size(0) * 2) -
                        1] = q[2];
            TG.quatList[(static_cast<int>(
                             (static_cast<double>(loop_ub_tmp) + 1.0) + 2.0) +
                         TG.quatList.size(0) * 3) -
                        1] = q[3];
            loop_ub_tmp++;
            break;
          case 1U:
            //  position et angle relatif
            // =================================================================
            //  Fonction qui tourne un vecteur selon un quaternion.
            //  quaternion partie scalaire
            //  quaternion partie vectoriel
            //  QuatRotate n'est pas compilable
            tl = 2.0 * coder::dot(*(double(*)[3]) & q[1], c);
            icMsg_Position_Y = q[0] * q[0] - coder::dot(*(double(*)[3]) & q[1],
                                                        *(double(*)[3]) & q[1]);
            icMsg_Position_X = 2.0 * q[0];
            TG.pointList[static_cast<int>(
                             (static_cast<double>(loop_ub_tmp) + 1.0) + 2.0) -
                         1] = TG.pointList[loop_ub_tmp] +
                              ((tl * q[1] + icMsg_Position_Y * d) +
                               icMsg_Position_X * (q[2] * icMsg_Orientation_W -
                                                   icMsg_Orientation_Y * q[3]));
            TG.pointList[(static_cast<int>(
                              (static_cast<double>(loop_ub_tmp) + 1.0) + 2.0) +
                          TG.pointList.size(0)) -
                         1] =
                TG.pointList[loop_ub_tmp + TG.pointList.size(0)] +
                ((tl * q[2] + icMsg_Position_Y * icMsg_Orientation_Y) +
                 icMsg_Position_X * (d * q[3] - q[1] * icMsg_Orientation_W));
            TG.pointList[(static_cast<int>(
                              (static_cast<double>(loop_ub_tmp) + 1.0) + 2.0) +
                          TG.pointList.size(0) * 2) -
                         1] =
                TG.pointList[loop_ub_tmp + TG.pointList.size(0) * 2] +
                ((tl * q[3] + icMsg_Position_Y * icMsg_Orientation_W) +
                 icMsg_Position_X * (q[1] * icMsg_Orientation_Y - d * q[2]));
            // ==================================================================
            //  Fonnction qui retoure le quaternion le plus court/long selon
            //  l'utilisateur
            bufferQuat[0] = TG.quatList[loop_ub_tmp];
            bufferQuat[1] = TG.quatList[loop_ub_tmp + TG.quatList.size(0)];
            bufferQuat[2] = TG.quatList[loop_ub_tmp + TG.quatList.size(0) * 2];
            bufferQuat[3] = TG.quatList[loop_ub_tmp + TG.quatList.size(0) * 3];
            d = coder::b_dot(bufferQuat, q);
            //  conjuger le quaternion au besoin
            // if  norm > 1 && dir == 0 || norm < 1 && dir == 1
            if (((d < 0.0) && (!Maddposemsg_Pose[loop_ub_tmp].Rotation)) ||
                ((d >= 0.0) && Maddposemsg_Pose[loop_ub_tmp].Rotation)) {
              q[0] = -q[0];
              q[1] = -q[1];
              q[2] = -q[2];
              q[3] = -q[3];
            }
            bufferQuat[1] =
                (TG.quatList[loop_ub_tmp] * q[1] +
                 q[0] * TG.quatList[loop_ub_tmp + TG.quatList.size(0)]) +
                (TG.quatList[loop_ub_tmp + TG.quatList.size(0) * 2] * q[3] -
                 q[2] * TG.quatList[loop_ub_tmp + TG.quatList.size(0) * 3]);
            bufferQuat[2] =
                (TG.quatList[loop_ub_tmp] * q[2] +
                 q[0] * TG.quatList[loop_ub_tmp + TG.quatList.size(0) * 2]) +
                (q[1] * TG.quatList[loop_ub_tmp + TG.quatList.size(0) * 3] -
                 TG.quatList[loop_ub_tmp + TG.quatList.size(0)] * q[3]);
            bufferQuat[3] =
                (TG.quatList[loop_ub_tmp] * q[3] +
                 q[0] * TG.quatList[loop_ub_tmp + TG.quatList.size(0) * 3]) +
                (TG.quatList[loop_ub_tmp + TG.quatList.size(0)] * q[2] -
                 q[1] * TG.quatList[loop_ub_tmp + TG.quatList.size(0) * 2]);
            TG.quatList[static_cast<int>(
                            (static_cast<double>(loop_ub_tmp) + 1.0) + 2.0) -
                        1] =
                ((TG.quatList[loop_ub_tmp] * q[0] -
                  TG.quatList[loop_ub_tmp + TG.quatList.size(0)] * q[1]) -
                 TG.quatList[loop_ub_tmp + TG.quatList.size(0) * 2] * q[2]) -
                TG.quatList[loop_ub_tmp + TG.quatList.size(0) * 3] * q[3];
            TG.quatList[(static_cast<int>(
                             (static_cast<double>(loop_ub_tmp) + 1.0) + 2.0) +
                         TG.quatList.size(0)) -
                        1] = bufferQuat[1];
            TG.quatList[(static_cast<int>(
                             (static_cast<double>(loop_ub_tmp) + 1.0) + 2.0) +
                         TG.quatList.size(0) * 2) -
                        1] = bufferQuat[2];
            TG.quatList[(static_cast<int>(
                             (static_cast<double>(loop_ub_tmp) + 1.0) + 2.0) +
                         TG.quatList.size(0) * 3) -
                        1] = bufferQuat[3];
            loop_ub_tmp++;
            break;
          case 2U:
            //  position relatif et angle absolue
            // =================================================================
            //  Fonction qui tourne un vecteur selon un quaternion.
            //  quaternion partie scalaire
            //  quaternion partie vectoriel
            //  QuatRotate n'est pas compilable
            tl = 2.0 * coder::dot(*(double(*)[3]) & q[1], c);
            icMsg_Position_Y = q[0] * q[0] - coder::dot(*(double(*)[3]) & q[1],
                                                        *(double(*)[3]) & q[1]);
            icMsg_Position_X = 2.0 * q[0];
            TG.pointList[static_cast<int>(
                             (static_cast<double>(loop_ub_tmp) + 1.0) + 2.0) -
                         1] =
                TG.pointList[loop_ub_tmp] +
                ((tl * q[1] + icMsg_Position_Y * d) +
                 icMsg_Position_X *
                     (q[2] * Maddposemsg_Pose[loop_ub_tmp].Position.Z -
                      Maddposemsg_Pose[loop_ub_tmp].Position.Y * q[3]));
            TG.pointList[(static_cast<int>(
                              (static_cast<double>(loop_ub_tmp) + 1.0) + 2.0) +
                          TG.pointList.size(0)) -
                         1] =
                TG.pointList[loop_ub_tmp + TG.pointList.size(0)] +
                ((tl * q[2] + icMsg_Position_Y * icMsg_Orientation_Y) +
                 icMsg_Position_X *
                     (Maddposemsg_Pose[loop_ub_tmp].Position.X * q[3] -
                      q[1] * Maddposemsg_Pose[loop_ub_tmp].Position.Z));
            TG.pointList[(static_cast<int>(
                              (static_cast<double>(loop_ub_tmp) + 1.0) + 2.0) +
                          TG.pointList.size(0) * 2) -
                         1] =
                TG.pointList[loop_ub_tmp + TG.pointList.size(0) * 2] +
                ((tl * q[3] + icMsg_Position_Y * icMsg_Orientation_W) +
                 icMsg_Position_X *
                     (q[1] * Maddposemsg_Pose[loop_ub_tmp].Position.Y -
                      Maddposemsg_Pose[loop_ub_tmp].Position.X * q[2]));
            TG.quatList[static_cast<int>(
                            (static_cast<double>(loop_ub_tmp) + 1.0) + 2.0) -
                        1] = q[0];
            TG.quatList[(static_cast<int>(
                             (static_cast<double>(loop_ub_tmp) + 1.0) + 2.0) +
                         TG.quatList.size(0)) -
                        1] = q[1];
            TG.quatList[(static_cast<int>(
                             (static_cast<double>(loop_ub_tmp) + 1.0) + 2.0) +
                         TG.quatList.size(0) * 2) -
                        1] = q[2];
            TG.quatList[(static_cast<int>(
                             (static_cast<double>(loop_ub_tmp) + 1.0) + 2.0) +
                         TG.quatList.size(0) * 3) -
                        1] = q[3];
            loop_ub_tmp++;
            break;
          case 3U:
            //  position absolue et angle relatif
            TG.pointList[static_cast<int>(
                             (static_cast<double>(loop_ub_tmp) + 1.0) + 2.0) -
                         1] = d;
            TG.pointList[(static_cast<int>(
                              (static_cast<double>(loop_ub_tmp) + 1.0) + 2.0) +
                          TG.pointList.size(0)) -
                         1] = icMsg_Orientation_Y;
            TG.pointList[(static_cast<int>(
                              (static_cast<double>(loop_ub_tmp) + 1.0) + 2.0) +
                          TG.pointList.size(0) * 2) -
                         1] = icMsg_Orientation_W;
            // ==================================================================
            //  Fonnction qui retoure le quaternion le plus court/long selon
            //  l'utilisateur
            bufferQuat[0] = TG.quatList[loop_ub_tmp];
            bufferQuat[1] = TG.quatList[loop_ub_tmp + TG.quatList.size(0)];
            bufferQuat[2] = TG.quatList[loop_ub_tmp + TG.quatList.size(0) * 2];
            bufferQuat[3] = TG.quatList[loop_ub_tmp + TG.quatList.size(0) * 3];
            d = coder::b_dot(bufferQuat, q);
            //  conjuger le quaternion au besoin
            // if  norm > 1 && dir == 0 || norm < 1 && dir == 1
            if (((d < 0.0) && (!Maddposemsg_Pose[loop_ub_tmp].Rotation)) ||
                ((d >= 0.0) && Maddposemsg_Pose[loop_ub_tmp].Rotation)) {
              q[0] = -q[0];
              q[1] = -q[1];
              q[2] = -q[2];
              q[3] = -q[3];
            }
            bufferQuat[1] =
                (TG.quatList[loop_ub_tmp] * q[1] +
                 q[0] * TG.quatList[loop_ub_tmp + TG.quatList.size(0)]) +
                (TG.quatList[loop_ub_tmp + TG.quatList.size(0) * 2] * q[3] -
                 q[2] * TG.quatList[loop_ub_tmp + TG.quatList.size(0) * 3]);
            bufferQuat[2] =
                (TG.quatList[loop_ub_tmp] * q[2] +
                 q[0] * TG.quatList[loop_ub_tmp + TG.quatList.size(0) * 2]) +
                (q[1] * TG.quatList[loop_ub_tmp + TG.quatList.size(0) * 3] -
                 TG.quatList[loop_ub_tmp + TG.quatList.size(0)] * q[3]);
            bufferQuat[3] =
                (TG.quatList[loop_ub_tmp] * q[3] +
                 q[0] * TG.quatList[loop_ub_tmp + TG.quatList.size(0) * 3]) +
                (TG.quatList[loop_ub_tmp + TG.quatList.size(0)] * q[2] -
                 q[1] * TG.quatList[loop_ub_tmp + TG.quatList.size(0) * 2]);
            TG.quatList[static_cast<int>(
                            (static_cast<double>(loop_ub_tmp) + 1.0) + 2.0) -
                        1] =
                ((TG.quatList[loop_ub_tmp] * q[0] -
                  TG.quatList[loop_ub_tmp + TG.quatList.size(0)] * q[1]) -
                 TG.quatList[loop_ub_tmp + TG.quatList.size(0) * 2] * q[2]) -
                TG.quatList[loop_ub_tmp + TG.quatList.size(0) * 3] * q[3];
            TG.quatList[(static_cast<int>(
                             (static_cast<double>(loop_ub_tmp) + 1.0) + 2.0) +
                         TG.quatList.size(0)) -
                        1] = bufferQuat[1];
            TG.quatList[(static_cast<int>(
                             (static_cast<double>(loop_ub_tmp) + 1.0) + 2.0) +
                         TG.quatList.size(0) * 2) -
                        1] = bufferQuat[2];
            TG.quatList[(static_cast<int>(
                             (static_cast<double>(loop_ub_tmp) + 1.0) + 2.0) +
                         TG.quatList.size(0) * 3) -
                        1] = bufferQuat[3];
            loop_ub_tmp++;
            break;
          default:
            //  Le referentiel n'est pas valide
            TG.status = false;
            printf("INFO : proc planner : Waypoints are not valid  \n");
            fflush(stdout);
            exitg1 = 1;
            break;
          }
        } else {
          //  Copier le dernier waypoint 2 fois pour éviter un comportement
          //  du generateur de trajecteur
          loop_ub_tmp = TG.pointList.size(0) - 1;
          s[1] =
              TG.pointList[(TG.pointList.size(0) + TG.pointList.size(0)) - 2];
          s[2] =
              TG.pointList[(TG.pointList.size(0) + TG.pointList.size(0) * 2) -
                           2];
          TG.pointList[TG.pointList.size(0) - 1] =
              TG.pointList[TG.pointList.size(0) - 2];
          TG.pointList[loop_ub_tmp + TG.pointList.size(0)] = s[1];
          TG.pointList[loop_ub_tmp + TG.pointList.size(0) * 2] = s[2];
          loop_ub_tmp = TG.quatList.size(0) - 1;
          bufferQuat[1] =
              TG.quatList[(TG.quatList.size(0) + TG.quatList.size(0)) - 2];
          bufferQuat[2] =
              TG.quatList[(TG.quatList.size(0) + TG.quatList.size(0) * 2) - 2];
          bufferQuat[3] =
              TG.quatList[(TG.quatList.size(0) + TG.quatList.size(0) * 3) - 2];
          TG.quatList[TG.quatList.size(0) - 1] =
              TG.quatList[TG.quatList.size(0) - 2];
          TG.quatList[loop_ub_tmp + TG.quatList.size(0)] = bufferQuat[1];
          TG.quatList[loop_ub_tmp + TG.quatList.size(0) * 2] = bufferQuat[2];
          TG.quatList[loop_ub_tmp + TG.quatList.size(0) * 3] = bufferQuat[3];
          //  Calculer les temps entre chaque waypoints
          // ==================================================================
          //  Fonnction qui calcul le temps entre chaque waypoint
          i = static_cast<int>(TG.n + -1.0);
          for (loop_ub_tmp = 0; loop_ub_tmp < i; loop_ub_tmp++) {
            //  pour chaques waypoints
            //  Trouver la distance Eucledienne entre 2 points
            s[0] = TG.pointList[loop_ub_tmp + 1] - TG.pointList[loop_ub_tmp];
            s[1] = TG.pointList[(loop_ub_tmp + TG.pointList.size(0)) + 1] -
                   TG.pointList[loop_ub_tmp + TG.pointList.size(0)];
            s[2] = TG.pointList[(loop_ub_tmp + TG.pointList.size(0) * 2) + 1] -
                   TG.pointList[loop_ub_tmp + TG.pointList.size(0) * 2];
            d = coder::b_norm(s);
            //  Déterminer le temps selon aMax
            tl = 4.0 * std::sqrt(3.0 * d) / 1.1618950038622251;
            //  Déterminer la vitesse maximum de la trajectoire
            //  Si la vitesse est plus grande que la vitesse maximum
            if (0.15 * tl / 4.0 > 0.8) {
              //  Calculer le temps selon vmax
              tl = 4.0 * d / 2.4000000000000004;
            }
            //  Déterminer l'angle entre les 2 quaternions
            q[0] = TG.quatList[loop_ub_tmp];
            q[1] = -TG.quatList[loop_ub_tmp + TG.quatList.size(0)];
            q[2] = -TG.quatList[loop_ub_tmp + TG.quatList.size(0) * 2];
            q[3] = -TG.quatList[loop_ub_tmp + TG.quatList.size(0) * 3];
            d = TG.quatList[loop_ub_tmp + 1];
            icMsg_Orientation_Y =
                TG.quatList[(loop_ub_tmp + TG.quatList.size(0)) + 1];
            icMsg_Orientation_W =
                TG.quatList[(loop_ub_tmp + TG.quatList.size(0) * 2) + 1];
            icMsg_Position_X =
                TG.quatList[(loop_ub_tmp + TG.quatList.size(0) * 3) + 1];
            qRel[0] = ((q[0] * d - q[1] * icMsg_Orientation_Y) -
                       q[2] * icMsg_Orientation_W) -
                      q[3] * icMsg_Position_X;
            qRel[1] = (q[0] * icMsg_Orientation_Y + d * q[1]) +
                      (q[2] * icMsg_Position_X - icMsg_Orientation_W * q[3]);
            qRel[2] = (q[0] * icMsg_Orientation_W + d * q[2]) +
                      (icMsg_Orientation_Y * q[3] - q[1] * icMsg_Position_X);
            qRel[3] = (q[0] * icMsg_Position_X + d * q[3]) +
                      (q[1] * icMsg_Orientation_W - icMsg_Orientation_Y * q[2]);
            //  Déterminer le temps angulaire
            d = coder::b_norm(*(double(*)[3]) & qRel[1]);
            s[0] = tl;
            s[1] = 2.0 * rt_atan2d_snf(d, qRel[0]) / 0.78539816339744828;
            s[2] = 0.1;
            TG.timeList[loop_ub_tmp + 1] =
                TG.timeList[loop_ub_tmp] + coder::internal::b_maximum(s);
          }
          //  Déterminer le nombre de points
          TG.nbPoint = std::floor(TG.timeList[TG.timeList.size(0) - 1] / 0.1);
          exitg1 = 1;
        }
      } while (exitg1 == 0);
      //  Envoyer a ros si le mAddpose est valide
      validMsg.Data = TG.status;
      validPub.send(validMsg);
      //  Si la trajectoire est valide
      if (TG.status) {
        short i1;
        //  Interpoler les waypoints
        // ==================================================================
        //  Fonction Main qui génère les waypoints
        //  Crée l'objet waypoint trajectory
        // ==================================================================
        //  Fonnction qui interpole les waypoints
        r1.init(TG.quatList);
        trajObj.init(TG.pointList, TG.timeList, &r1);
        //  Initialiser le message trajectoire.
        trajectory_msgs_MultiDOFJointTrajectoryPointStruct(&trajMsg);
        //  message point
        geometry_msgs_TransformStruct(&transformBuff);
        //  trajectoire
        geometry_msgs_TwistStruct(&twistBuff);
        //  trajectoire
        //  initialiser la dimention vecteur de points
        i = static_cast<int>(TG.nbPoint);
        y.set_size(1, i);
        for (loop_ub_tmp = 0; loop_ub_tmp < i; loop_ub_tmp++) {
          y[loop_ub_tmp] = transformBuff;
        }
        trajMsg.Transforms.set_size(y.size(1));
        loop_ub = y.size(1);
        for (loop_ub_tmp = 0; loop_ub_tmp < loop_ub; loop_ub_tmp++) {
          trajMsg.Transforms[loop_ub_tmp] = y[loop_ub_tmp];
        }
        coder::repelem(&twistBuff, TG.nbPoint, r2);
        trajMsg.Velocities.set_size(r2.size(1));
        loop_ub = r2.size(1);
        for (loop_ub_tmp = 0; loop_ub_tmp < loop_ub; loop_ub_tmp++) {
          trajMsg.Velocities[loop_ub_tmp] = r2[loop_ub_tmp];
        }
        coder::repelem(&twistBuff, TG.nbPoint, r2);
        trajMsg.Accelerations.set_size(r2.size(1));
        loop_ub = r2.size(1);
        for (loop_ub_tmp = 0; loop_ub_tmp < loop_ub; loop_ub_tmp++) {
          trajMsg.Accelerations[loop_ub_tmp] = r2[loop_ub_tmp];
        }
        q[0] = 0.0;
        q[1] = 0.0;
        q[2] = 0.0;
        q[3] = 0.0;
        //  Générer les points de la trajectoire
        for (loop_ub_tmp = 0; loop_ub_tmp < i; loop_ub_tmp++) {
          trajObj.step(c, &varargout_2, s, varargout_4, varargout_5);
          //  Remplire le message Transform.
          transformBuff.Translation.X = c[0];
          transformBuff.Translation.Y = c[1];
          transformBuff.Translation.Z = c[2];
          //  Convertir l'objet quaternion en vecteur
          bufferQuat[0] = varargout_2.a;
          bufferQuat[1] = varargout_2.b;
          bufferQuat[2] = varargout_2.c;
          bufferQuat[3] = varargout_2.d;
          //  Verifier de retourner la rotation la plus petite
          if ((loop_ub_tmp + 1U > 1U) && (coder::b_dot(q, bufferQuat) < 0.0)) {
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
          trajMsg.Transforms[loop_ub_tmp] = transformBuff;
          //  Convertir les vitesse dans le ref sub
          // =================================================================
          //  Fonction qui tourne un vecteur selon un quaternion.
          //  quaternion partie scalaire
          //  quaternion partie vectoriel
          //  QuatRotate n'est pas compilable
          tl = 2.0 * coder::dot(*(double(*)[3]) & bufferQuat[1], s);
          icMsg_Position_Y = bufferQuat[0] * bufferQuat[0] -
                             coder::dot(*(double(*)[3]) & bufferQuat[1],
                                        *(double(*)[3]) & bufferQuat[1]);
          d = 2.0 * bufferQuat[0];
          //  Remplire les vitesse
          twistBuff.Linear.X =
              (tl * bufferQuat[1] + icMsg_Position_Y * s[0]) +
              d * (bufferQuat[2] * s[2] - s[1] * bufferQuat[3]);
          twistBuff.Linear.Y =
              (tl * bufferQuat[2] + icMsg_Position_Y * s[1]) +
              d * (s[0] * bufferQuat[3] - bufferQuat[1] * s[2]);
          twistBuff.Linear.Z =
              (tl * bufferQuat[3] + icMsg_Position_Y * s[2]) +
              d * (bufferQuat[1] * s[1] - s[0] * bufferQuat[2]);
          twistBuff.Angular.X = -varargout_5[0];
          //  (-) pour convertir les vitesse angulaire dans le ref sub
          twistBuff.Angular.Y = -varargout_5[1];
          twistBuff.Angular.Z = -varargout_5[2];
          trajMsg.Velocities[loop_ub_tmp] = twistBuff;
          //  Ecrire le point dans le message
          //  Convertir les accels dans le ref sub
          // =================================================================
          //  Fonction qui tourne un vecteur selon un quaternion.
          //  quaternion partie scalaire
          //  quaternion partie vectoriel
          //  QuatRotate n'est pas compilable
          tl = 2.0 * coder::dot(*(double(*)[3]) & bufferQuat[1], varargout_4);
          icMsg_Position_Y = bufferQuat[0] * bufferQuat[0] -
                             coder::dot(*(double(*)[3]) & bufferQuat[1],
                                        *(double(*)[3]) & bufferQuat[1]);
          //  Remplire les acceleration
          twistBuff.Linear.X =
              (tl * bufferQuat[1] + icMsg_Position_Y * varargout_4[0]) +
              d * (bufferQuat[2] * varargout_4[2] -
                   varargout_4[1] * bufferQuat[3]);
          twistBuff.Linear.Y =
              (tl * bufferQuat[2] + icMsg_Position_Y * varargout_4[1]) +
              d * (varargout_4[0] * bufferQuat[3] -
                   bufferQuat[1] * varargout_4[2]);
          twistBuff.Linear.Z =
              (tl * bufferQuat[3] + icMsg_Position_Y * varargout_4[2]) +
              d * (bufferQuat[1] * varargout_4[1] -
                   varargout_4[0] * bufferQuat[2]);
          twistBuff.Angular.X = 0.0;
          twistBuff.Angular.Y = 0.0;
          twistBuff.Angular.Z = 0.0;
          trajMsg.Accelerations[loop_ub_tmp] = twistBuff;
        }
        //  Envoyer le message
        trajpub.send(&trajMsg);
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
      for (i = 0; i < 25; i++) {
        Maddposemsg_MessageType[i] = emptyMAddPoseMsg.MessageType[i];
      }
      Maddposemsg_Pose.set_size(emptyMAddPoseMsg.Pose.size(0));
      loop_ub = emptyMAddPoseMsg.Pose.size(0);
      for (i = 0; i < loop_ub; i++) {
        Maddposemsg_Pose[i] = emptyMAddPoseMsg.Pose[i];
      }
      for (i = 0; i < 18; i++) {
        icMsg_MessageType[i] = emptyIcMsg.MessageType[i];
      }
      for (i = 0; i < 19; i++) {
        icMsg_Position.MessageType[i] = emptyIcMsg.Position.MessageType[i];
      }
      icMsg_Position_X = emptyIcMsg.Position.X;
      icMsg_Position_Y = emptyIcMsg.Position.Y;
      icMsg_Position_Z = emptyIcMsg.Position.Z;
      for (i = 0; i < 24; i++) {
        icMsg_Orientation.MessageType[i] =
            emptyIcMsg.Orientation.MessageType[i];
      }
      d = emptyIcMsg.Orientation.X;
      icMsg_Orientation_Y = emptyIcMsg.Orientation.Y;
      tl = emptyIcMsg.Orientation.Z;
      icMsg_Orientation_W = emptyIcMsg.Orientation.W;
      mapPub.send(&emptyMAddPoseMsg);
      icPub.send(&emptyIcMsg);
      newMaddPose = false;
      newInitalPose = false;
      printf("INFO : proc planner : Wait for poses \n");
      fflush(stdout);
    }
    r.waitfor();
  }
}

//
// File trailer for proc_planner.cpp
//
// [EOF]
//
