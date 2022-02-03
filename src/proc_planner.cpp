//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: proc_planner.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 03-Feb-2022 14:08:22
//

// Include Files
#include "proc_planner.h"
#include "Publisher.h"
#include "Subscriber.h"
#include "TrajectoryGenerator.h"
#include "geometry_msgs_PoseStruct.h"
#include "geometry_msgs_TransformStruct.h"
#include "geometry_msgs_TwistStruct.h"
#include "minOrMax.h"
#include "norm.h"
#include "proc_planner_rtwutil.h"
#include "proc_planner_types.h"
#include "quaternion.h"
#include "repelem.h"
#include "rt_nonfinite.h"
#include "sonia_common_AddPoseStruct.h"
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
  coder::quaternion r2;
  coder::ros::Publisher pospub;
  coder::ros::Subscriber mapSub;
  coder::ros::b_Publisher trajpub;
  coder::ros::b_Subscriber icSub;
  coder::ros::c_Publisher validSub;
  coder::waypointTrajectory trajObj;
  coder::array<geometry_msgs_TransformStruct_T, 2U> r3;
  coder::array<geometry_msgs_TwistStruct_T, 2U> r4;
  coder::array<sonia_common_AddPoseStruct_T, 1U> rMaddposemsg_Pose;
  geometry_msgs_PointStruct_T icMsg_Position;
  geometry_msgs_PoseStruct_T b_unusedExpr;
  geometry_msgs_QuaternionStruct_T icMsg_Orientation;
  geometry_msgs_TransformStruct_T transformBuff;
  geometry_msgs_TwistStruct_T twistBuff;
  sonia_common_AddPoseStruct_T unusedExpr;
  sonia_common_MultiAddPoseStruct_T r;
  sonia_common_MultiAddPoseStruct_T r1;
  std_msgs_BoolStruct_T validMsg;
  trajectory_msgs_MultiDOFJointTrajectoryPointStruct_T trajMsg;
  double qRel[4];
  double c[3];
  double s[3];
  double varargout_4[3];
  double varargout_5[3];
  pospub.matlabCodegenIsDeleted = true;
  mapSub.matlabCodegenIsDeleted = true;
  icSub.matlabCodegenIsDeleted = true;
  trajpub.matlabCodegenIsDeleted = true;
  validSub.matlabCodegenIsDeleted = true;
  // r = rateControl(rosSpin);
  //  Definir les message ros
  sonia_common_AddPoseStruct(&unusedExpr);
  sonia_common_MultiAddPoseStruct(&r);
  sonia_common_MultiAddPoseStruct(&r1);
  validMsg = std_msgs_BoolStruct();
  geometry_msgs_PoseStruct(&b_unusedExpr);
  //  IC topic
  //  Definir les Subscrier ros
  pospub.init();
  mapSub.init();
  icSub.init();
  //  Definir les publisher ROS
  trajpub.init();
  validSub.init();
  //  Definir les parametre de trajectoire
  printf("proc planner : Node is started \n");
  fflush(stdout);
  // reset(r)
  while (1) {
    double a;
    double b_norm;
    double q_idx_0;
    double q_idx_1;
    double q_idx_2;
    double q_idx_3;
    double q_tmp;
    int b_i;
    int i;
    bool guard1{false};
    printf("proc planner : Wait for poses \n");
    fflush(stdout);
    mapSub.receive(rMaddposemsg_Pose);
    printf("proc planner : Poses received \n");
    fflush(stdout);
    printf("proc planner : Wait for initial pose \n");
    fflush(stdout);
    icSub.receive(&icMsg_Position, &icMsg_Orientation);
    printf("proc planner : Initial poses received \n");
    fflush(stdout);
    //  Si Recois un nouveau message
    TG.status = true;
    TG.nbPoint = 1.0;
    // ==================================================================
    //  Constructeur
    //  nombre de waypoints + iC
    //  Initialiser les tableaux
    TG.pointList.set_size(3, 3);
    for (i = 0; i < 9; i++) {
      TG.pointList[i] = 0.0;
    }
    TG.quatList.set_size(3, 4);
    for (i = 0; i < 12; i++) {
      TG.quatList[i] = 0.0;
    }
    TG.timeList.set_size(3);
    TG.timeList[1] = 0.0;
    TG.timeList[2] = 0.0;
    //  Initialiser les parametres
    //  trouver le waypoint initial
    //  lire la position initale
    //  [this.icMsg, status] = receive(this.icSub,5);
    // this.icMsg = this.icSub.LatestMessage;
    // ==================================================================
    //  Fonnction qui retoure le waypoint initial
    // status = ~isempty(this.icMsg);
    //  Replire les listes.
    TG.pointList[0] = icMsg_Position.X;
    TG.pointList[TG.pointList.size(0)] = icMsg_Position.Y;
    TG.pointList[TG.pointList.size(0) * 2] = icMsg_Position.Z;
    TG.quatList[0] = icMsg_Orientation.W;
    TG.quatList[TG.quatList.size(0)] = icMsg_Orientation.X;
    TG.quatList[TG.quatList.size(0) * 2] = icMsg_Orientation.Y;
    TG.quatList[TG.quatList.size(0) * 3] = icMsg_Orientation.Z;
    TG.timeList[0] = 0.0;
    //  Process le message addpose
    // ==================================================================
    //  Fonction qui interprete les waypoints reçu par ROS
    //  pour chaques waypoints
    //  transformer les angle d'euler quaternions
    s[0] = 0.017453292519943295 * rMaddposemsg_Pose[0].Orientation.Z / 2.0;
    s[1] = 0.017453292519943295 * rMaddposemsg_Pose[0].Orientation.Y / 2.0;
    s[2] = 0.017453292519943295 * rMaddposemsg_Pose[0].Orientation.X / 2.0;
    c[0] = std::cos(s[0]);
    s[0] = std::sin(s[0]);
    c[1] = std::cos(s[1]);
    s[1] = std::sin(s[1]);
    c[2] = std::cos(s[2]);
    s[2] = std::sin(s[2]);
    b_norm = c[0] * c[1];
    q_tmp = s[0] * s[1];
    q_idx_0 = b_norm * c[2] + q_tmp * s[2];
    q_idx_1 = b_norm * s[2] - q_tmp * c[2];
    b_norm = s[0] * c[1];
    q_tmp = c[0] * s[1];
    q_idx_2 = q_tmp * c[2] + b_norm * s[2];
    q_idx_3 = b_norm * c[2] - q_tmp * s[2];
    //  cree le vecteur pose
    //  transformer le point en fonction du frame
    guard1 = false;
    switch (rMaddposemsg_Pose[0].Frame) {
    case 0U:
      //  position et angle absolue
      TG.pointList[1] = rMaddposemsg_Pose[0].Position.X;
      TG.pointList[TG.pointList.size(0) + 1] = rMaddposemsg_Pose[0].Position.Y;
      TG.pointList[TG.pointList.size(0) * 2 + 1] =
          rMaddposemsg_Pose[0].Position.Z;
      TG.quatList[1] = q_idx_0;
      TG.quatList[TG.quatList.size(0) + 1] = q_idx_1;
      TG.quatList[TG.quatList.size(0) * 2 + 1] = q_idx_2;
      TG.quatList[TG.quatList.size(0) * 3 + 1] = q_idx_3;
      guard1 = true;
      break;
    case 1U:
      //  position et angle relatif
      // =================================================================
      //  Fonction qui tourne un vecteur selon un quaternion.
      //  quaternion partie scalaire
      //  quaternion partie vectoriel
      //  QuatRotate n'est pas compilable
      a = 2.0 * ((rMaddposemsg_Pose[0].Position.X * q_idx_1 +
                  rMaddposemsg_Pose[0].Position.Y * q_idx_2) +
                 rMaddposemsg_Pose[0].Position.Z * q_idx_3);
      q_tmp = q_idx_0 * q_idx_0 -
              ((q_idx_1 * q_idx_1 + q_idx_2 * q_idx_2) + q_idx_3 * q_idx_3);
      b_norm = 2.0 * q_idx_0;
      TG.pointList[1] =
          TG.pointList[0] +
          ((a * q_idx_1 + q_tmp * rMaddposemsg_Pose[0].Position.X) +
           b_norm * (q_idx_2 * rMaddposemsg_Pose[0].Position.Z -
                     rMaddposemsg_Pose[0].Position.Y * q_idx_3));
      TG.pointList[TG.pointList.size(0) + 1] =
          TG.pointList[TG.pointList.size(0)] +
          ((a * q_idx_2 + q_tmp * rMaddposemsg_Pose[0].Position.Y) +
           b_norm * (rMaddposemsg_Pose[0].Position.X * q_idx_3 -
                     q_idx_1 * rMaddposemsg_Pose[0].Position.Z));
      TG.pointList[TG.pointList.size(0) * 2 + 1] =
          TG.pointList[TG.pointList.size(0) * 2] +
          ((a * q_idx_3 + q_tmp * rMaddposemsg_Pose[0].Position.Z) +
           b_norm * (q_idx_1 * rMaddposemsg_Pose[0].Position.Y -
                     rMaddposemsg_Pose[0].Position.X * q_idx_2));
      // ==================================================================
      //  Fonnction qui retoure le quaternion le plus court/long selon
      //  l'utilisateur
      b_norm = ((TG.quatList[0] * q_idx_0 +
                 TG.quatList[TG.quatList.size(0)] * q_idx_1) +
                TG.quatList[TG.quatList.size(0) * 2] * q_idx_2) +
               TG.quatList[TG.quatList.size(0) * 3] * q_idx_3;
      //  conjuger le quaternion au besoin
      if (((b_norm > 1.0) && (!rMaddposemsg_Pose[0].Rotation)) ||
          ((b_norm < 1.0) && rMaddposemsg_Pose[0].Rotation)) {
        q_idx_1 = -q_idx_1;
        q_idx_2 = -q_idx_2;
        q_idx_3 = -q_idx_3;
      }
      TG.quatList[1] = ((TG.quatList[0] * q_idx_0 -
                         TG.quatList[TG.quatList.size(0)] * q_idx_1) -
                        TG.quatList[TG.quatList.size(0) * 2] * q_idx_2) -
                       TG.quatList[TG.quatList.size(0) * 3] * q_idx_3;
      TG.quatList[TG.quatList.size(0) + 1] =
          (TG.quatList[0] * q_idx_1 +
           q_idx_0 * TG.quatList[TG.quatList.size(0)]) +
          (TG.quatList[TG.quatList.size(0) * 2] * q_idx_3 -
           q_idx_2 * TG.quatList[TG.quatList.size(0) * 3]);
      TG.quatList[TG.quatList.size(0) * 2 + 1] =
          (TG.quatList[0] * q_idx_2 +
           q_idx_0 * TG.quatList[TG.quatList.size(0) * 2]) +
          (q_idx_1 * TG.quatList[TG.quatList.size(0) * 3] -
           TG.quatList[TG.quatList.size(0)] * q_idx_3);
      TG.quatList[TG.quatList.size(0) * 3 + 1] =
          (TG.quatList[0] * q_idx_3 +
           q_idx_0 * TG.quatList[TG.quatList.size(0) * 3]) +
          (TG.quatList[TG.quatList.size(0)] * q_idx_2 -
           q_idx_1 * TG.quatList[TG.quatList.size(0) * 2]);
      guard1 = true;
      break;
    case 2U:
      //  position relatif et angle absolue
      // =================================================================
      //  Fonction qui tourne un vecteur selon un quaternion.
      //  quaternion partie scalaire
      //  quaternion partie vectoriel
      //  QuatRotate n'est pas compilable
      a = 2.0 * ((rMaddposemsg_Pose[0].Position.X * q_idx_1 +
                  rMaddposemsg_Pose[0].Position.Y * q_idx_2) +
                 rMaddposemsg_Pose[0].Position.Z * q_idx_3);
      q_tmp = q_idx_0 * q_idx_0 -
              ((q_idx_1 * q_idx_1 + q_idx_2 * q_idx_2) + q_idx_3 * q_idx_3);
      b_norm = 2.0 * q_idx_0;
      TG.pointList[1] =
          TG.pointList[0] +
          ((a * q_idx_1 + q_tmp * rMaddposemsg_Pose[0].Position.X) +
           b_norm * (q_idx_2 * rMaddposemsg_Pose[0].Position.Z -
                     rMaddposemsg_Pose[0].Position.Y * q_idx_3));
      TG.pointList[TG.pointList.size(0) + 1] =
          TG.pointList[TG.pointList.size(0)] +
          ((a * q_idx_2 + q_tmp * rMaddposemsg_Pose[0].Position.Y) +
           b_norm * (rMaddposemsg_Pose[0].Position.X * q_idx_3 -
                     q_idx_1 * rMaddposemsg_Pose[0].Position.Z));
      TG.pointList[TG.pointList.size(0) * 2 + 1] =
          TG.pointList[TG.pointList.size(0) * 2] +
          ((a * q_idx_3 + q_tmp * rMaddposemsg_Pose[0].Position.Z) +
           b_norm * (q_idx_1 * rMaddposemsg_Pose[0].Position.Y -
                     rMaddposemsg_Pose[0].Position.X * q_idx_2));
      TG.quatList[1] = q_idx_0;
      TG.quatList[TG.quatList.size(0) + 1] = q_idx_1;
      TG.quatList[TG.quatList.size(0) * 2 + 1] = q_idx_2;
      TG.quatList[TG.quatList.size(0) * 3 + 1] = q_idx_3;
      guard1 = true;
      break;
    case 3U:
      //  position absolue et angle relatif
      TG.pointList[1] = rMaddposemsg_Pose[0].Position.X;
      TG.pointList[TG.pointList.size(0) + 1] = rMaddposemsg_Pose[0].Position.Y;
      TG.pointList[TG.pointList.size(0) * 2 + 1] =
          rMaddposemsg_Pose[0].Position.Z;
      // ==================================================================
      //  Fonnction qui retoure le quaternion le plus court/long selon
      //  l'utilisateur
      b_norm = ((TG.quatList[0] * q_idx_0 +
                 TG.quatList[TG.quatList.size(0)] * q_idx_1) +
                TG.quatList[TG.quatList.size(0) * 2] * q_idx_2) +
               TG.quatList[TG.quatList.size(0) * 3] * q_idx_3;
      //  conjuger le quaternion au besoin
      if (((b_norm > 1.0) && (!rMaddposemsg_Pose[0].Rotation)) ||
          ((b_norm < 1.0) && rMaddposemsg_Pose[0].Rotation)) {
        q_idx_1 = -q_idx_1;
        q_idx_2 = -q_idx_2;
        q_idx_3 = -q_idx_3;
      }
      TG.quatList[1] = ((TG.quatList[0] * q_idx_0 -
                         TG.quatList[TG.quatList.size(0)] * q_idx_1) -
                        TG.quatList[TG.quatList.size(0) * 2] * q_idx_2) -
                       TG.quatList[TG.quatList.size(0) * 3] * q_idx_3;
      TG.quatList[TG.quatList.size(0) + 1] =
          (TG.quatList[0] * q_idx_1 +
           q_idx_0 * TG.quatList[TG.quatList.size(0)]) +
          (TG.quatList[TG.quatList.size(0) * 2] * q_idx_3 -
           q_idx_2 * TG.quatList[TG.quatList.size(0) * 3]);
      TG.quatList[TG.quatList.size(0) * 2 + 1] =
          (TG.quatList[0] * q_idx_2 +
           q_idx_0 * TG.quatList[TG.quatList.size(0) * 2]) +
          (q_idx_1 * TG.quatList[TG.quatList.size(0) * 3] -
           TG.quatList[TG.quatList.size(0)] * q_idx_3);
      TG.quatList[TG.quatList.size(0) * 3 + 1] =
          (TG.quatList[0] * q_idx_3 +
           q_idx_0 * TG.quatList[TG.quatList.size(0) * 3]) +
          (TG.quatList[TG.quatList.size(0)] * q_idx_2 -
           q_idx_1 * TG.quatList[TG.quatList.size(0) * 2]);
      guard1 = true;
      break;
    default:
      //  Le referentiel n'est pas valide
      TG.status = false;
      break;
    }
    if (guard1) {
      //  Copier le dernier waypoint 2 fois pour éviter un comportement
      //  du generateur de trajecteur
      TG.pointList[2] = TG.pointList[1];
      TG.pointList[TG.pointList.size(0) + 2] =
          TG.pointList[TG.pointList.size(0) + 1];
      TG.pointList[TG.pointList.size(0) * 2 + 2] =
          TG.pointList[TG.pointList.size(0) * 2 + 1];
      TG.quatList[2] = TG.quatList[1];
      TG.quatList[TG.quatList.size(0) + 2] =
          TG.quatList[TG.quatList.size(0) + 1];
      TG.quatList[TG.quatList.size(0) * 2 + 2] =
          TG.quatList[TG.quatList.size(0) * 2 + 1];
      TG.quatList[TG.quatList.size(0) * 3 + 2] =
          TG.quatList[TG.quatList.size(0) * 3 + 1];
      //  Calculer les temps entre chaque waypoints
      // ==================================================================
      //  Fonnction qui calcul le temps entre chaque waypoint
      for (b_i = 0; b_i < 2; b_i++) {
        double d;
        double tl;
        //  pour chaques waypoints
        //  Trouver la distance Eucledienne entre 2 points
        s[0] = TG.pointList[b_i + 1] - TG.pointList[b_i];
        s[1] = TG.pointList[(b_i + TG.pointList.size(0)) + 1] -
               TG.pointList[b_i + TG.pointList.size(0)];
        s[2] = TG.pointList[(b_i + TG.pointList.size(0) * 2) + 1] -
               TG.pointList[b_i + TG.pointList.size(0) * 2];
        b_norm = coder::b_norm(s);
        //  Déterminer le temps selon aMax
        tl = 4.0 * std::sqrt(3.0 * b_norm) / 1.1618950038622251;
        //  Déterminer la vitesse maximum de la trajectoire
        //  Si la vitesse est plus grande que la vitesse maximum
        if (0.15 * tl / 4.0 > 0.8) {
          //  Calculer le temps selon vmax
          tl = 4.0 * b_norm / 2.4000000000000004;
        }
        //  Déterminer l'angle entre les 2 quaternions
        q_idx_0 = TG.quatList[b_i];
        q_idx_1 = -TG.quatList[b_i + TG.quatList.size(0)];
        q_idx_2 = -TG.quatList[b_i + TG.quatList.size(0) * 2];
        q_idx_3 = -TG.quatList[b_i + TG.quatList.size(0) * 3];
        q_tmp = TG.quatList[b_i + 1];
        b_norm = TG.quatList[(b_i + TG.quatList.size(0)) + 1];
        a = TG.quatList[(b_i + TG.quatList.size(0) * 2) + 1];
        d = TG.quatList[(b_i + TG.quatList.size(0) * 3) + 1];
        qRel[0] =
            ((q_idx_0 * q_tmp - q_idx_1 * b_norm) - q_idx_2 * a) - q_idx_3 * d;
        qRel[1] =
            (q_idx_0 * b_norm + q_tmp * q_idx_1) + (q_idx_2 * d - a * q_idx_3);
        qRel[2] =
            (q_idx_0 * a + q_tmp * q_idx_2) + (b_norm * q_idx_3 - q_idx_1 * d);
        qRel[3] =
            (q_idx_0 * d + q_tmp * q_idx_3) + (q_idx_1 * a - b_norm * q_idx_2);
        //  Déterminer le temps angulaire
        q_tmp = coder::b_norm(*(double(*)[3]) & qRel[1]);
        s[0] = tl;
        s[1] = 2.0 * rt_atan2d_snf(q_tmp, qRel[0]) / 0.78539816339744828;
        s[2] = 0.1;
        TG.timeList[b_i + 1] = TG.timeList[b_i] + coder::internal::maximum(s);
      }
      //  Déterminer le nombre de points
      TG.nbPoint = std::floor(TG.timeList[2] / 0.1);
    }
    //  Envoyer a ros si le mAddpose est valide
    validMsg.Data = TG.status;
    validSub.send(validMsg);
    //  Si la trajectoire est valide
    if (TG.status) {
      //  Interpoler les waypoints
      // ==================================================================
      //  Fonction Main qui génère les waypoints
      //  Crée l'objet waypoint trajectory
      // ==================================================================
      //  Fonnction qui interpole les waypoints
      r2.init(TG.quatList);
      trajObj.init(TG.pointList, TG.timeList, &r2);
      //  Initialiser le message trajectoire.
      trajectory_msgs_MultiDOFJointTrajectoryPointStruct(&trajMsg);
      //  message point
      geometry_msgs_TransformStruct(&transformBuff);
      //  trajectoire
      geometry_msgs_TwistStruct(&twistBuff);
      //  trajectoire
      //  initialiser la dimention vecteur de points
      coder::repelem(&transformBuff, TG.nbPoint, r3);
      trajMsg.Transforms.set_size(r3.size(1));
      b_i = r3.size(1);
      for (i = 0; i < b_i; i++) {
        trajMsg.Transforms[i] = r3[i];
      }
      coder::repelem(&twistBuff, TG.nbPoint, r4);
      trajMsg.Velocities.set_size(r4.size(1));
      b_i = r4.size(1);
      for (i = 0; i < b_i; i++) {
        trajMsg.Velocities[i] = r4[i];
      }
      coder::repelem(&twistBuff, TG.nbPoint, r4);
      trajMsg.Accelerations.set_size(r4.size(1));
      b_i = r4.size(1);
      for (i = 0; i < b_i; i++) {
        trajMsg.Accelerations[i] = r4[i];
      }
      //  Générer les points de la trajectoire
      i = static_cast<int>(TG.nbPoint);
      for (b_i = 0; b_i < i; b_i++) {
        trajObj.step(c, &varargout_2, s, varargout_4, varargout_5);
        //  Remplire le message Transform.
        transformBuff.Translation.X = c[0];
        transformBuff.Translation.Y = c[1];
        transformBuff.Translation.Z = c[2];
        //  Convertir l'objet quaternion en vecteur
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
        a = 2.0 * ((s[0] * varargout_2.b + s[1] * varargout_2.c) +
                   s[2] * varargout_2.d);
        b_norm =
            varargout_2.a * varargout_2.a -
            ((varargout_2.b * varargout_2.b + varargout_2.c * varargout_2.c) +
             varargout_2.d * varargout_2.d);
        q_tmp = 2.0 * varargout_2.a;
        //  Remplire les vitesse
        twistBuff.Angular.X = -varargout_5[0];
        //  (-) pour convertir les vitesse angulaire dans le ref sub
        twistBuff.Angular.Y = -varargout_5[1];
        twistBuff.Angular.Z = -varargout_5[2];
        //  Ecrire le point dans le message
        //  Convertir les accels dans le ref sub
        // =================================================================
        //  Fonction qui tourne un vecteur selon un quaternion.
        //  quaternion partie scalaire
        //  quaternion partie vectoriel
        //  QuatRotate n'est pas compilable
        twistBuff.Linear.X =
            (a * varargout_2.b + b_norm * s[0]) +
            q_tmp * (varargout_2.c * s[2] - s[1] * varargout_2.d);
        twistBuff.Linear.Y =
            (a * varargout_2.c + b_norm * s[1]) +
            q_tmp * (s[0] * varargout_2.d - varargout_2.b * s[2]);
        twistBuff.Linear.Z =
            (a * varargout_2.d + b_norm * s[2]) +
            q_tmp * (varargout_2.b * s[1] - s[0] * varargout_2.c);
        trajMsg.Velocities[b_i] = twistBuff;
        a = 2.0 *
            ((varargout_4[0] * varargout_2.b + varargout_4[1] * varargout_2.c) +
             varargout_4[2] * varargout_2.d);
        //  Remplire les acceleration
        twistBuff.Linear.X = (a * varargout_2.b + b_norm * varargout_4[0]) +
                             q_tmp * (varargout_2.c * varargout_4[2] -
                                      varargout_4[1] * varargout_2.d);
        twistBuff.Linear.Y = (a * varargout_2.c + b_norm * varargout_4[1]) +
                             q_tmp * (varargout_4[0] * varargout_2.d -
                                      varargout_2.b * varargout_4[2]);
        twistBuff.Linear.Z = (a * varargout_2.d + b_norm * varargout_4[2]) +
                             q_tmp * (varargout_2.b * varargout_4[1] -
                                      varargout_4[0] * varargout_2.c);
        twistBuff.Angular.X = 0.0;
        twistBuff.Angular.Y = 0.0;
        twistBuff.Angular.Z = 0.0;
        trajMsg.Accelerations[b_i] = twistBuff;
      }
      //  Envoyer le message
      trajpub.send(&trajMsg);
      //  Si on roule en simulation
      //  Retourner true (sucess)
      printf("proc planner : Trajectory list is sended \n");
      fflush(stdout);
    }
    //  waitfor(r);
  }
}

//
// File trailer for proc_planner.cpp
//
// [EOF]
//
