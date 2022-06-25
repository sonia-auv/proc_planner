//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: TrajectoryGenerator.cpp
//
// MATLAB Coder version            : 5.4
// C/C++ source code generated on  : 25-Jun-2022 15:23:16
//

// Include Files
#include "TrajectoryGenerator.h"
#include "dot.h"
#include "eul2quat.h"
#include "minOrMax.h"
#include "mod.h"
#include "norm.h"
#include "proc_planner_internal_types.h"
#include "proc_planner_rtwutil.h"
#include "proc_planner_types.h"
#include "quat2eul.h"
#include "quatmultiply.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <cmath>
#include <stdio.h>

// Function Definitions
//
// Initialise l'objet trajectoire et vérifie si le message multi add pose est
// valide.
//
// Arguments    : const char multiAddposeMsg_MessageType[25]
//                unsigned char multiAddposeMsg_InterpolationMethod
//                const coder::array<sonia_common_AddPoseStruct_T, 1U>
//                &multiAddposeMsg_Pose const b_struct_T *b_param const
//                geometry_msgs_PointStruct_T icMsg_Position const
//                geometry_msgs_QuaternionStruct_T icMsg_Orientation
// Return Type  : TrajectoryGenerator *
//
TrajectoryGenerator *TrajectoryGenerator::init(
    const char multiAddposeMsg_MessageType[25],
    unsigned char multiAddposeMsg_InterpolationMethod,
    const coder::array<sonia_common_AddPoseStruct_T, 1U> &multiAddposeMsg_Pose,
    const b_struct_T *b_param, const geometry_msgs_PointStruct_T icMsg_Position,
    const geometry_msgs_QuaternionStruct_T icMsg_Orientation)
{
  TrajectoryGenerator *this_;
  coder::array<double, 1U> varargin_1;
  double c_this[4];
  double q[4];
  double qRel[4];
  double eul[3];
  double v01[3];
  double R_Bar;
  double b;
  double b_d;
  double c;
  double d;
  double suppPoint;
  int b_this;
  int exitg1;
  int i;
  int loop_ub;
  bool guard1{false};
  this_ = this;
  this_->icOffset = 2.0;
  // ==================================================================
  //  Constructeur
  this_->status = 0.0;
  //  Validité de waypoints reçus.
  for (b_this = 0; b_this < 25; b_this++) {
    this_->MAPM.MessageType[b_this] = multiAddposeMsg_MessageType[b_this];
  }
  this_->MAPM.InterpolationMethod = multiAddposeMsg_InterpolationMethod;
  this_->MAPM.Pose.set_size(multiAddposeMsg_Pose.size(0));
  loop_ub = multiAddposeMsg_Pose.size(0);
  for (b_this = 0; b_this < loop_ub; b_this++) {
    this_->MAPM.Pose[b_this] = multiAddposeMsg_Pose[b_this];
  }
  double b_multiAddposeMsg_Pose[2];
  b_multiAddposeMsg_Pose[0] = multiAddposeMsg_Pose.size(0);
  b_multiAddposeMsg_Pose[1] = 1.0;
  this_->nMAPM = coder::internal::maximum(b_multiAddposeMsg_Pose);
  //  matlab and cpp dont use same index. return max instead
  //  Initialiser les parametres
  this_->param = *b_param;
  //  Importer la librairie quatUtilities
  //  Verifier que le dernier point ne contient pas de rayon.
  if (this_->MAPM.Pose[static_cast<int>(this_->nMAPM) - 1].Fine != 0.0) {
    this_->MAPM.Pose[static_cast<int>(this_->nMAPM) - 1].Fine = 0.0;
    printf("Warning : proc planner : last waypoint must have fine parameter "
           "set to 0 \n");
    fflush(stdout);
  }
  //  point supplementaire pour l'arrondissement.
  suppPoint = 0.0;
  d = this_->nMAPM;
  b_this = static_cast<int>(d);
  for (i = 0; i < b_this; i++) {
    if (!(this_->MAPM.Pose[i].Fine == 0.0)) {
      suppPoint++;
    }
  }
  //  nombre de waypoints  + point supp + offset + point initial
  this_->n = ((this_->nMAPM + suppPoint) + this_->icOffset) + 1.0;
  //  Initialiser les tableaux
  loop_ub = static_cast<int>(this_->n);
  this_->pointList.set_size(loop_ub, 3);
  loop_ub *= 3;
  for (b_this = 0; b_this < loop_ub; b_this++) {
    this_->pointList[b_this] = 0.0;
  }
  loop_ub = static_cast<int>(this_->n);
  this_->quatList.set_size(loop_ub, 4);
  loop_ub <<= 2;
  for (b_this = 0; b_this < loop_ub; b_this++) {
    this_->quatList[b_this] = 0.0;
  }
  loop_ub = static_cast<int>(this_->n);
  this_->timeList.set_size(loop_ub);
  for (b_this = 0; b_this < loop_ub; b_this++) {
    this_->timeList[b_this] = 0.0;
  }
  loop_ub = static_cast<int>(this_->n);
  this_->courseList.set_size(1, loop_ub);
  for (b_this = 0; b_this < loop_ub; b_this++) {
    this_->courseList[b_this] = 0.0;
  }
  loop_ub = static_cast<int>(this_->n);
  this_->speedList.set_size(1, loop_ub);
  for (b_this = 0; b_this < loop_ub; b_this++) {
    this_->speedList[b_this] = 0.0;
  }
  //  trouver le waypoint initial
  //  Replire les listes.
  // ==================================================================
  //  Fonnction qui retoure le waypoint initial
  this_->pointList[0] = icMsg_Position.X;
  this_->pointList[this_->pointList.size(0)] = icMsg_Position.Y;
  this_->pointList[this_->pointList.size(0) * 2] = icMsg_Position.Z;
  this_->quatList[0] = icMsg_Orientation.W;
  this_->quatList[this_->quatList.size(0)] = icMsg_Orientation.X;
  this_->quatList[this_->quatList.size(0) * 2] = icMsg_Orientation.Y;
  this_->quatList[this_->quatList.size(0) * 3] = icMsg_Orientation.Z;
  this_->timeList[0] = 0.0;
  this_->speedList[0] = 0.0;
  c_this[0] = this_->quatList[0];
  c_this[1] = this_->quatList[this_->quatList.size(0)];
  c_this[2] = this_->quatList[this_->quatList.size(0) * 2];
  c_this[3] = this_->quatList[this_->quatList.size(0) * 3];
  coder::quat2eul(c_this, v01);
  eul[0] = 57.295779513082323 * v01[0];
  this_->courseList[0] = eul[0];
  //  Copier le point 2 fois pour forcé accInit a 0.
  v01[0] = this_->pointList[0];
  v01[1] = this_->pointList[this_->pointList.size(0)];
  v01[2] = this_->pointList[this_->pointList.size(0) * 2];
  this_->pointList[1] = v01[0];
  this_->pointList[this_->pointList.size(0) + 1] = v01[1];
  this_->pointList[this_->pointList.size(0) * 2 + 1] = v01[2];
  c_this[0] = this_->quatList[0];
  c_this[1] = this_->quatList[this_->quatList.size(0)];
  c_this[2] = this_->quatList[this_->quatList.size(0) * 2];
  c_this[3] = this_->quatList[this_->quatList.size(0) * 3];
  this_->quatList[1] = c_this[0];
  this_->quatList[this_->quatList.size(0) + 1] = c_this[1];
  this_->quatList[this_->quatList.size(0) * 2 + 1] = c_this[2];
  this_->quatList[this_->quatList.size(0) * 3 + 1] = c_this[3];
  this_->timeList[1] = this_->param.ts;
  this_->courseList[1] = eul[0];
  this_->speedList[1] = this_->speedList[0];
  //  Verifier si le mode d'interpolation est valide
  //  Le parametre verif permet au constructeur de verifier si le mode existe
  //  sans interpoler. Determiner le type d'imterpolation
  // ==================================================================
  //  Fonction qui envoie les message sur ros
  switch (this_->MAPM.InterpolationMethod) {
  case 0U:
    //  piecewise cubic interpolation
    break;
  case 1U:
    //  spline
    break;
  case 2U:
    //  Cubic convolution
    break;
  default:
    this_->status = -1.0;
    printf(
        "INFO : proc planner : Interpolation strategy is not recognized  \n");
    fflush(stdout);
    break;
  }
  //  Process le message addpose
  // ==================================================================
  //  Fonction qui interprete les waypoints reçu par ROS
  d = this_->nMAPM;
  i = 0;
  do {
    exitg1 = 0;
    if (i <= static_cast<int>(d) - 1) {
      //  pour chaques AddPose
      //  transformer les angle d'euler quaternions
      eul[0] = this_->MAPM.Pose[i].Orientation.Z;
      eul[1] = this_->MAPM.Pose[i].Orientation.Y;
      eul[2] = this_->MAPM.Pose[i].Orientation.X;
      eul[0] *= 0.017453292519943295;
      eul[1] *= 0.017453292519943295;
      eul[2] *= 0.017453292519943295;
      coder::eul2quat(eul, q);
      //  cree le vecteur pose
      eul[0] = this_->MAPM.Pose[i].Position.X;
      eul[1] = this_->MAPM.Pose[i].Position.Y;
      eul[2] = this_->MAPM.Pose[i].Position.Z;
      //  transformer le point en fonction du frame
      guard1 = false;
      switch (this_->MAPM.Pose[i].Frame) {
      case 0U:
        //  position et angle absolue
        loop_ub = static_cast<int>(
            ((static_cast<double>(i) + 1.0) + this_->icOffset) - 1.0);
        qRel[0] = this_->quatList[loop_ub - 1];
        qRel[1] = this_->quatList[(loop_ub + this_->quatList.size(0)) - 1];
        qRel[2] = this_->quatList[(loop_ub + this_->quatList.size(0) * 2) - 1];
        qRel[3] = this_->quatList[(loop_ub + this_->quatList.size(0) * 3) - 1];
        //  Regarder la discontinuité entre le qk et qk-1
        // =================================================================
        //  Fonction qui assure la continuité entre 2 quaternions
        if (coder::dot(qRel, q) < 0.0) {
          q[0] = -q[0];
          q[1] = -q[1];
          q[2] = -q[2];
          q[3] = -q[3];
        }
        loop_ub =
            static_cast<int>((static_cast<double>(i) + 1.0) + this_->icOffset);
        this_->quatList[loop_ub - 1] = q[0];
        this_->quatList[(loop_ub + this_->quatList.size(0)) - 1] = q[1];
        this_->quatList[(loop_ub + this_->quatList.size(0) * 2) - 1] = q[2];
        this_->quatList[(loop_ub + this_->quatList.size(0) * 3) - 1] = q[3];
        loop_ub =
            static_cast<int>((static_cast<double>(i) + 1.0) + this_->icOffset);
        this_->pointList[loop_ub - 1] = eul[0];
        this_->pointList[(loop_ub + this_->pointList.size(0)) - 1] = eul[1];
        this_->pointList[(loop_ub + this_->pointList.size(0) * 2) - 1] = eul[2];
        guard1 = true;
        break;
      case 1U:
        //  position et angle relatif
        loop_ub = static_cast<int>(
            ((static_cast<double>(i) + 1.0) + this_->icOffset) - 1.0);
        qRel[0] = this_->quatList[loop_ub - 1];
        qRel[1] = this_->quatList[(loop_ub + this_->quatList.size(0)) - 1];
        qRel[2] = this_->quatList[(loop_ub + this_->quatList.size(0) * 2) - 1];
        qRel[3] = this_->quatList[(loop_ub + this_->quatList.size(0) * 3) - 1];
        // ---------------------------------------------------------------
        //  Code not ready for deploy yet. It is comment to avoid instablitiy
        //  during pool testing.
        // ---------------------------------------------------------------
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
        coder::quatmultiply(qRel, q, c_this);
        loop_ub =
            static_cast<int>((static_cast<double>(i) + 1.0) + this_->icOffset);
        this_->quatList[loop_ub - 1] = c_this[0];
        this_->quatList[(loop_ub + this_->quatList.size(0)) - 1] = c_this[1];
        this_->quatList[(loop_ub + this_->quatList.size(0) * 2) - 1] =
            c_this[2];
        this_->quatList[(loop_ub + this_->quatList.size(0) * 3) - 1] =
            c_this[3];
        loop_ub = static_cast<int>(
            ((static_cast<double>(i) + 1.0) + this_->icOffset) - 1.0);
        q[0] = this_->quatList[loop_ub - 1];
        q[1] = this_->quatList[(loop_ub + this_->quatList.size(0)) - 1];
        q[2] = this_->quatList[(loop_ub + this_->quatList.size(0) * 2) - 1];
        q[3] = this_->quatList[(loop_ub + this_->quatList.size(0) * 3) - 1];
        // =================================================================
        //  Fonction qui tourne un vecteur selon un quaternion.
        //  quaternion partie scalaire
        //  quaternion partie vectoriel
        //  QuatRotate n'est pas compilable
        b_d = 2.0 * coder::b_dot(*(double(*)[3]) & q[1], eul);
        suppPoint = q[0] * q[0] - coder::b_dot(*(double(*)[3]) & q[1],
                                               *(double(*)[3]) & q[1]);
        R_Bar = 2.0 * q[0];
        loop_ub = static_cast<int>(
            ((static_cast<double>(i) + 1.0) + this_->icOffset) - 1.0);
        b_this =
            static_cast<int>((static_cast<double>(i) + 1.0) + this_->icOffset);
        v01[0] = this_->pointList[loop_ub - 1] +
                 ((b_d * q[1] + suppPoint * eul[0]) +
                  R_Bar * (q[2] * eul[2] - eul[1] * q[3]));
        v01[1] = this_->pointList[(loop_ub + this_->pointList.size(0)) - 1] +
                 ((b_d * q[2] + suppPoint * eul[1]) +
                  R_Bar * (eul[0] * q[3] - q[1] * eul[2]));
        v01[2] =
            this_->pointList[(loop_ub + this_->pointList.size(0) * 2) - 1] +
            ((b_d * q[3] + suppPoint * eul[2]) +
             R_Bar * (q[1] * eul[1] - eul[0] * q[2]));
        this_->pointList[b_this - 1] = v01[0];
        this_->pointList[(b_this + this_->pointList.size(0)) - 1] = v01[1];
        this_->pointList[(b_this + this_->pointList.size(0) * 2) - 1] = v01[2];
        guard1 = true;
        break;
      case 2U:
        //  position relatif et angle absolue
        loop_ub = static_cast<int>(
            ((static_cast<double>(i) + 1.0) + this_->icOffset) - 1.0);
        qRel[0] = this_->quatList[loop_ub - 1];
        qRel[1] = this_->quatList[(loop_ub + this_->quatList.size(0)) - 1];
        qRel[2] = this_->quatList[(loop_ub + this_->quatList.size(0) * 2) - 1];
        qRel[3] = this_->quatList[(loop_ub + this_->quatList.size(0) * 3) - 1];
        //  Regarder la discontinuité entre le qk et qk-1
        // =================================================================
        //  Fonction qui assure la continuité entre 2 quaternions
        if (coder::dot(qRel, q) < 0.0) {
          q[0] = -q[0];
          q[1] = -q[1];
          q[2] = -q[2];
          q[3] = -q[3];
        }
        loop_ub =
            static_cast<int>((static_cast<double>(i) + 1.0) + this_->icOffset);
        this_->quatList[loop_ub - 1] = q[0];
        this_->quatList[(loop_ub + this_->quatList.size(0)) - 1] = q[1];
        this_->quatList[(loop_ub + this_->quatList.size(0) * 2) - 1] = q[2];
        this_->quatList[(loop_ub + this_->quatList.size(0) * 3) - 1] = q[3];
        loop_ub = static_cast<int>(
            ((static_cast<double>(i) + 1.0) + this_->icOffset) - 1.0);
        q[0] = this_->quatList[loop_ub - 1];
        q[1] = this_->quatList[(loop_ub + this_->quatList.size(0)) - 1];
        q[2] = this_->quatList[(loop_ub + this_->quatList.size(0) * 2) - 1];
        q[3] = this_->quatList[(loop_ub + this_->quatList.size(0) * 3) - 1];
        // =================================================================
        //  Fonction qui tourne un vecteur selon un quaternion.
        //  quaternion partie scalaire
        //  quaternion partie vectoriel
        //  QuatRotate n'est pas compilable
        b_d = 2.0 * coder::b_dot(*(double(*)[3]) & q[1], eul);
        suppPoint = q[0] * q[0] - coder::b_dot(*(double(*)[3]) & q[1],
                                               *(double(*)[3]) & q[1]);
        R_Bar = 2.0 * q[0];
        loop_ub = static_cast<int>(
            ((static_cast<double>(i) + 1.0) + this_->icOffset) - 1.0);
        b_this =
            static_cast<int>((static_cast<double>(i) + 1.0) + this_->icOffset);
        v01[0] = this_->pointList[loop_ub - 1] +
                 ((b_d * q[1] + suppPoint * eul[0]) +
                  R_Bar * (q[2] * eul[2] - eul[1] * q[3]));
        v01[1] = this_->pointList[(loop_ub + this_->pointList.size(0)) - 1] +
                 ((b_d * q[2] + suppPoint * eul[1]) +
                  R_Bar * (eul[0] * q[3] - q[1] * eul[2]));
        v01[2] =
            this_->pointList[(loop_ub + this_->pointList.size(0) * 2) - 1] +
            ((b_d * q[3] + suppPoint * eul[2]) +
             R_Bar * (q[1] * eul[1] - eul[0] * q[2]));
        this_->pointList[b_this - 1] = v01[0];
        this_->pointList[(b_this + this_->pointList.size(0)) - 1] = v01[1];
        this_->pointList[(b_this + this_->pointList.size(0) * 2) - 1] = v01[2];
        guard1 = true;
        break;
      case 3U:
        //  position absolue et angle relatif
        loop_ub = static_cast<int>(
            ((static_cast<double>(i) + 1.0) + this_->icOffset) - 1.0);
        qRel[0] = this_->quatList[loop_ub - 1];
        qRel[1] = this_->quatList[(loop_ub + this_->quatList.size(0)) - 1];
        qRel[2] = this_->quatList[(loop_ub + this_->quatList.size(0) * 2) - 1];
        qRel[3] = this_->quatList[(loop_ub + this_->quatList.size(0) * 3) - 1];
        // ---------------------------------------------------------------
        //  Code not ready for deploy yet. It is comment to avoid instablitiy
        //  during pool testing.
        // ---------------------------------------------------------------
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
        coder::quatmultiply(qRel, q, c_this);
        loop_ub =
            static_cast<int>((static_cast<double>(i) + 1.0) + this_->icOffset);
        this_->quatList[loop_ub - 1] = c_this[0];
        this_->quatList[(loop_ub + this_->quatList.size(0)) - 1] = c_this[1];
        this_->quatList[(loop_ub + this_->quatList.size(0) * 2) - 1] =
            c_this[2];
        this_->quatList[(loop_ub + this_->quatList.size(0) * 3) - 1] =
            c_this[3];
        loop_ub =
            static_cast<int>((static_cast<double>(i) + 1.0) + this_->icOffset);
        this_->pointList[loop_ub - 1] = eul[0];
        this_->pointList[(loop_ub + this_->pointList.size(0)) - 1] = eul[1];
        this_->pointList[(loop_ub + this_->pointList.size(0) * 2) - 1] = eul[2];
        guard1 = true;
        break;
      default:
        //  Le referentiel n'est pas valide
        this_->status = -2.0;
        printf("INFO : proc planner : Invalid Reference Frame.\n");
        fflush(stdout);
        exitg1 = 1;
        break;
      }
      if (guard1) {
        //  copier le parametre de vitesse
        this_->speedList[static_cast<int>((static_cast<double>(i) + 1.0) +
                                          this_->icOffset) -
                         1] = this_->MAPM.Pose[i].Speed;
        //  determiner le yaw pour le vecteur course
        loop_ub =
            static_cast<int>((static_cast<double>(i) + 1.0) + this_->icOffset);
        q[0] = this_->quatList[loop_ub - 1];
        q[1] = this_->quatList[(loop_ub + this_->quatList.size(0)) - 1];
        q[2] = this_->quatList[(loop_ub + this_->quatList.size(0) * 2) - 1];
        q[3] = this_->quatList[(loop_ub + this_->quatList.size(0) * 3) - 1];
        // ==================================================================
        //  Fonction qui retourne l'angle de course
        coder::quat2eul(q, v01);
        eul[0] = 57.295779513082323 * v01[0];
        if (eul[0] < 0.0) {
          eul[0] += 360.0;
        }
        this_->courseList[static_cast<int>((static_cast<double>(i) + 1.0) +
                                           this_->icOffset) -
                          1] = eul[0];
        //  verifier si faut arrondire la trajectoire.
        if ((static_cast<double>(i) + 1.0 > 1.0) &&
            (this_->MAPM
                 .Pose[static_cast<int>((static_cast<double>(i) + 1.0) - 1.0) -
                       1]
                 .Fine != 0.0)) {
          double P1_idx_0;
          double P1_idx_1;
          double P1_idx_2;
          bool valid;
          suppPoint = (static_cast<double>(i) + 1.0) + this_->icOffset;
          // ==================================================================
          //  Fonction qui arrondie les waypoints.
          R_Bar =
              this_->MAPM
                  .Pose[static_cast<int>((suppPoint - this_->icOffset) - 1.0) -
                        1]
                  .Fine;
          //  Si rayon positif calculer la courbe
          if (R_Bar > 0.0) {
            double P2[3];
            double v12[3];
            //  Definition point.
            eul[0] = this_->pointList[static_cast<int>(suppPoint - 2.0) - 1];
            eul[1] = this_->pointList[(static_cast<int>(suppPoint - 2.0) +
                                       this_->pointList.size(0)) -
                                      1];
            eul[2] = this_->pointList[(static_cast<int>(suppPoint - 2.0) +
                                       this_->pointList.size(0) * 2) -
                                      1];
            P1_idx_0 = this_->pointList[static_cast<int>(suppPoint - 1.0) - 1];
            P1_idx_1 = this_->pointList[(static_cast<int>(suppPoint - 1.0) +
                                         this_->pointList.size(0)) -
                                        1];
            P1_idx_2 = this_->pointList[(static_cast<int>(suppPoint - 1.0) +
                                         this_->pointList.size(0) * 2) -
                                        1];
            P2[0] = this_->pointList[static_cast<int>(suppPoint) - 1];
            P2[1] = this_->pointList[(static_cast<int>(suppPoint) +
                                      this_->pointList.size(0)) -
                                     1];
            P2[2] = this_->pointList[(static_cast<int>(suppPoint) +
                                      this_->pointList.size(0) * 2) -
                                     1];
            //  Determiner les vecteurs
            //  Determiner les longeures du triangle
            v01[0] = P1_idx_0 - eul[0];
            v12[0] = P2[0] - P1_idx_0;
            P2[0] -= eul[0];
            v01[1] = P1_idx_1 - eul[1];
            v12[1] = P2[1] - P1_idx_1;
            P2[1] -= eul[1];
            v01[2] = P1_idx_2 - eul[2];
            v12[2] = P2[2] - P1_idx_2;
            P2[2] -= eul[2];
            b_d = coder::b_norm(P2);
            b = coder::b_norm(v01);
            c = coder::b_norm(v12);
            //  Calculer alpha 1 (loi de cos)
            //  radians
            //  Calculer R
            suppPoint =
                R_Bar /
                std::tan(0.5 * std::acos(((-(b_d * b_d) + b * b) + c * c) /
                                         (2.0 * b * c)));
            //  Verifier que le rayon n'est pas trop grand
            if ((suppPoint < b) || (suppPoint < c)) {
              //  Calculer les points tangeant au cercle de rayon.
              R_Bar = b - suppPoint;
              eul[0] += v01[0] / b * R_Bar;
              P1_idx_0 += v12[0] / c * suppPoint;
              eul[1] += v01[1] / b * R_Bar;
              P1_idx_1 += v12[1] / c * suppPoint;
              eul[2] += v01[2] / b * R_Bar;
              P1_idx_2 += v12[2] / c * suppPoint;
              valid = true;
            } else {
              eul[0] = 0.0;
              P1_idx_0 = 0.0;
              eul[1] = 0.0;
              P1_idx_1 = 0.0;
              eul[2] = 0.0;
              P1_idx_2 = 0.0;
              valid = false;
            }
            //  Si rayon negatif. copier le point 2 fois
          } else {
            eul[0] = this_->pointList[static_cast<int>(suppPoint - 1.0) - 1];
            eul[1] = this_->pointList[(static_cast<int>(suppPoint - 1.0) +
                                       this_->pointList.size(0)) -
                                      1];
            eul[2] = this_->pointList[(static_cast<int>(suppPoint - 1.0) +
                                       this_->pointList.size(0) * 2) -
                                      1];
            P1_idx_0 = this_->pointList[static_cast<int>(suppPoint - 1.0) - 1];
            P1_idx_1 = this_->pointList[(static_cast<int>(suppPoint - 1.0) +
                                         this_->pointList.size(0)) -
                                        1];
            P1_idx_2 = this_->pointList[(static_cast<int>(suppPoint - 1.0) +
                                         this_->pointList.size(0) * 2) -
                                        1];
            valid = true;
          }
          if (!valid) {
            this_->status = -4.0;
            printf("INFO : proc planner : Circle radius is to large.\n");
            fflush(stdout);
            exitg1 = 1;
          } else {
            //  Decaler les waypoints
            loop_ub = static_cast<int>((static_cast<double>(i) + 1.0) +
                                       this_->icOffset);
            b_this = static_cast<int>(
                ((static_cast<double>(i) + 1.0) + this_->icOffset) + 1.0);
            v01[0] = this_->pointList[loop_ub - 1];
            v01[1] = this_->pointList[(loop_ub + this_->pointList.size(0)) - 1];
            v01[2] =
                this_->pointList[(loop_ub + this_->pointList.size(0) * 2) - 1];
            this_->pointList[b_this - 1] = v01[0];
            this_->pointList[(b_this + this_->pointList.size(0)) - 1] = v01[1];
            this_->pointList[(b_this + this_->pointList.size(0) * 2) - 1] =
                v01[2];
            loop_ub = static_cast<int>((static_cast<double>(i) + 1.0) +
                                       this_->icOffset);
            this_->pointList[loop_ub - 1] = P1_idx_0;
            this_->pointList[(loop_ub + this_->pointList.size(0)) - 1] =
                P1_idx_1;
            this_->pointList[(loop_ub + this_->pointList.size(0) * 2) - 1] =
                P1_idx_2;
            loop_ub = static_cast<int>(
                ((static_cast<double>(i) + 1.0) + this_->icOffset) - 1.0);
            this_->pointList[loop_ub - 1] = eul[0];
            this_->pointList[(loop_ub + this_->pointList.size(0)) - 1] = eul[1];
            this_->pointList[(loop_ub + this_->pointList.size(0) * 2) - 1] =
                eul[2];
            loop_ub = static_cast<int>((static_cast<double>(i) + 1.0) +
                                       this_->icOffset);
            b_this = static_cast<int>(
                ((static_cast<double>(i) + 1.0) + this_->icOffset) + 1.0);
            c_this[0] = this_->quatList[loop_ub - 1];
            c_this[1] =
                this_->quatList[(loop_ub + this_->quatList.size(0)) - 1];
            c_this[2] =
                this_->quatList[(loop_ub + this_->quatList.size(0) * 2) - 1];
            c_this[3] =
                this_->quatList[(loop_ub + this_->quatList.size(0) * 3) - 1];
            this_->quatList[b_this - 1] = c_this[0];
            this_->quatList[(b_this + this_->quatList.size(0)) - 1] = c_this[1];
            this_->quatList[(b_this + this_->quatList.size(0) * 2) - 1] =
                c_this[2];
            this_->quatList[(b_this + this_->quatList.size(0) * 3) - 1] =
                c_this[3];
            loop_ub = static_cast<int>(
                ((static_cast<double>(i) + 1.0) + this_->icOffset) - 1.0);
            b_this = static_cast<int>((static_cast<double>(i) + 1.0) +
                                      this_->icOffset);
            c_this[0] = this_->quatList[loop_ub - 1];
            c_this[1] =
                this_->quatList[(loop_ub + this_->quatList.size(0)) - 1];
            c_this[2] =
                this_->quatList[(loop_ub + this_->quatList.size(0) * 2) - 1];
            c_this[3] =
                this_->quatList[(loop_ub + this_->quatList.size(0) * 3) - 1];
            this_->quatList[b_this - 1] = c_this[0];
            this_->quatList[(b_this + this_->quatList.size(0)) - 1] = c_this[1];
            this_->quatList[(b_this + this_->quatList.size(0) * 2) - 1] =
                c_this[2];
            this_->quatList[(b_this + this_->quatList.size(0) * 3) - 1] =
                c_this[3];
            loop_ub = static_cast<int>(
                ((static_cast<double>(i) + 1.0) + this_->icOffset) - 2.0);
            b_this = static_cast<int>(
                ((static_cast<double>(i) + 1.0) + this_->icOffset) - 1.0);
            c_this[0] = this_->quatList[loop_ub - 1];
            c_this[1] =
                this_->quatList[(loop_ub + this_->quatList.size(0)) - 1];
            c_this[2] =
                this_->quatList[(loop_ub + this_->quatList.size(0) * 2) - 1];
            c_this[3] =
                this_->quatList[(loop_ub + this_->quatList.size(0) * 3) - 1];
            this_->quatList[b_this - 1] = c_this[0];
            this_->quatList[(b_this + this_->quatList.size(0)) - 1] = c_this[1];
            this_->quatList[(b_this + this_->quatList.size(0) * 2) - 1] =
                c_this[2];
            this_->quatList[(b_this + this_->quatList.size(0) * 3) - 1] =
                c_this[3];
            this_->speedList[static_cast<int>(((static_cast<double>(i) + 1.0) +
                                               this_->icOffset) +
                                              1.0) -
                             1] =
                this_->speedList[static_cast<int>(
                                     (static_cast<double>(i) + 1.0) +
                                     this_->icOffset) -
                                 1];
            this_->speedList[static_cast<int>((static_cast<double>(i) + 1.0) +
                                              this_->icOffset) -
                             1] =
                this_->speedList[static_cast<int>(
                                     ((static_cast<double>(i) + 1.0) +
                                      this_->icOffset) -
                                     1.0) -
                                 1];
            this_->courseList[static_cast<int>(((static_cast<double>(i) + 1.0) +
                                                this_->icOffset) +
                                               1.0) -
                              1] =
                this_->courseList[static_cast<int>(
                                      (static_cast<double>(i) + 1.0) +
                                      this_->icOffset) -
                                  1];
            this_->courseList[static_cast<int>((static_cast<double>(i) + 1.0) +
                                               this_->icOffset) -
                              1] =
                this_->courseList[static_cast<int>(
                                      ((static_cast<double>(i) + 1.0) +
                                       this_->icOffset) -
                                      1.0) -
                                  1];
            this_->courseList[static_cast<int>(((static_cast<double>(i) + 1.0) +
                                                this_->icOffset) -
                                               1.0) -
                              1] =
                this_->courseList[static_cast<int>(
                                      ((static_cast<double>(i) + 1.0) +
                                       this_->icOffset) -
                                      2.0) -
                                  1];
            //  nouveau waypoint. augmente le offset
            this_->icOffset++;
            i++;
          }
        } else {
          i++;
        }
      }
    } else {
      //  Copier le dernier waypoint 2 fois pour éviter un comportement
      //  du generateur de trajecteur
      loop_ub = this_->pointList.size(0) - 2;
      b_this = this_->pointList.size(0) - 1;
      v01[0] = this_->pointList[loop_ub];
      v01[1] = this_->pointList[loop_ub + this_->pointList.size(0)];
      v01[2] = this_->pointList[loop_ub + this_->pointList.size(0) * 2];
      this_->pointList[b_this] = v01[0];
      this_->pointList[b_this + this_->pointList.size(0)] = v01[1];
      this_->pointList[b_this + this_->pointList.size(0) * 2] = v01[2];
      loop_ub = this_->quatList.size(0) - 2;
      b_this = this_->quatList.size(0) - 1;
      c_this[0] = this_->quatList[loop_ub];
      c_this[1] = this_->quatList[loop_ub + this_->quatList.size(0)];
      c_this[2] = this_->quatList[loop_ub + this_->quatList.size(0) * 2];
      c_this[3] = this_->quatList[loop_ub + this_->quatList.size(0) * 3];
      this_->quatList[b_this] = c_this[0];
      this_->quatList[b_this + this_->quatList.size(0)] = c_this[1];
      this_->quatList[b_this + this_->quatList.size(0) * 2] = c_this[2];
      this_->quatList[b_this + this_->quatList.size(0) * 3] = c_this[3];
      this_->courseList[this_->courseList.size(1) - 1] =
          this_->courseList[this_->courseList.size(1) - 2];
      this_->speedList[this_->speedList.size(1) - 1] =
          this_->speedList[this_->speedList.size(1) - 2];
      exitg1 = 1;
    }
  } while (exitg1 == 0);
  //  Calculer les temps entre chaque waypoints
  if (this_->status == 0.0) {
    // ==================================================================
    //  Fonnction qui calcul le temps entre chaque waypoint
    d = this_->n;
    i = 1;
    do {
      exitg1 = 0;
      if (i - 1 <= static_cast<int>(d + -1.0) - 1) {
        //  pour chaques waypoints
        //  Determiner le parametre de vitesse
        guard1 = false;
        switch (static_cast<int>(this_->speedList[i])) {
        case 0:
          //  Vitesse normale
          suppPoint = this_->param.normalSpeed.amax;
          R_Bar = this_->param.normalSpeed.vlmax;
          b = this_->param.normalSpeed.vamax;
          guard1 = true;
          break;
        case 1:
          //  Vitesse rapide
          suppPoint = this_->param.highSpeed.amax;
          R_Bar = this_->param.highSpeed.vlmax;
          b = this_->param.highSpeed.vamax;
          guard1 = true;
          break;
        case 2:
          //  Vitesse lente
          suppPoint = this_->param.lowSpeed.amax;
          R_Bar = this_->param.lowSpeed.vlmax;
          b = this_->param.lowSpeed.vamax;
          guard1 = true;
          break;
        default:
          //  mode non reconue.
          this_->status = -3.0;
          printf("INFO : proc planner : Speed parameter is not recognized \n");
          fflush(stdout);
          this_->nbPoint = 1.0;
          exitg1 = 1;
          break;
        }
        if (guard1) {
          //  Trouver la distance Eucledienne entre 2 points
          v01[0] =
              this_->pointList[i] -
              this_->pointList[static_cast<int>(
                                   (static_cast<double>(i - 1) + 2.0) - 1.0) -
                               1];
          v01[1] =
              this_->pointList[i + this_->pointList.size(0)] -
              this_->pointList[(static_cast<int>(
                                    (static_cast<double>(i - 1) + 2.0) - 1.0) +
                                this_->pointList.size(0)) -
                               1];
          v01[2] =
              this_->pointList[i + this_->pointList.size(0) * 2] -
              this_->pointList[(static_cast<int>(
                                    (static_cast<double>(i - 1) + 2.0) - 1.0) +
                                this_->pointList.size(0) * 2) -
                               1];
          b_d = coder::b_norm(v01);
          //  Déterminer le temps selon aMax
          c = 4.0 * std::sqrt(3.0 * b_d) / (3.0 * std::sqrt(suppPoint));
          //  Déterminer la vitesse maximum de la trajectoire
          //  Si la vitesse est plus grande que la vitesse maximum
          if (suppPoint * c / 4.0 > R_Bar) {
            //  Calculer le temps selon vmax
            c = 4.0 * b_d / (3.0 * R_Bar);
          }
          //  Déterminer l'angle entre les 2 quaternions
          q[0] = this_->quatList[static_cast<int>(
                                     (static_cast<double>(i - 1) + 2.0) - 1.0) -
                                 1];
          q[1] =
              this_->quatList[(static_cast<int>(
                                   (static_cast<double>(i - 1) + 2.0) - 1.0) +
                               this_->quatList.size(0)) -
                              1];
          q[2] =
              this_->quatList[(static_cast<int>(
                                   (static_cast<double>(i - 1) + 2.0) - 1.0) +
                               this_->quatList.size(0) * 2) -
                              1];
          q[3] =
              this_->quatList[(static_cast<int>(
                                   (static_cast<double>(i - 1) + 2.0) - 1.0) +
                               this_->quatList.size(0) * 3) -
                              1];
          q[1] = -q[1];
          q[2] = -q[2];
          q[3] = -q[3];
          c_this[0] = this_->quatList[i];
          c_this[1] = this_->quatList[i + this_->quatList.size(0)];
          c_this[2] = this_->quatList[i + this_->quatList.size(0) * 2];
          c_this[3] = this_->quatList[i + this_->quatList.size(0) * 3];
          coder::quatmultiply(q, c_this, qRel);
          //  Déterminer le temps angulaire
          //  Déterminer le temps maximale
          suppPoint = coder::b_norm(*(double(*)[3]) & qRel[1]);
          eul[0] = c;
          eul[1] = 2.0 * rt_atan2d_snf(suppPoint, qRel[0]) / b;
          eul[2] = this_->param.ts;
          suppPoint = coder::internal::b_maximum(eul);
          //  Arrondire supperieur selont ts
          R_Bar = coder::b_mod(suppPoint, this_->param.ts);
          if (R_Bar > 0.0) {
            suppPoint += this_->param.ts - R_Bar;
          }
          this_->timeList[i] =
              this_->timeList[static_cast<int>(
                                  (static_cast<double>(i - 1) + 2.0) - 1.0) -
                              1] +
              suppPoint;
          i++;
        }
      } else {
        //  Déterminer le nombre de points
        suppPoint =
            this_->timeList[this_->timeList.size(0) - 1] / this_->param.ts;
        suppPoint = std::round(suppPoint);
        this_->nbPoint = suppPoint;
        exitg1 = 1;
      }
    } while (exitg1 == 0);
  } else {
    this_->nbPoint = 1.0;
  }
  //  vérifier la profondeur maximum.
  loop_ub = this_->pointList.size(0);
  varargin_1.set_size(loop_ub);
  for (b_this = 0; b_this < loop_ub; b_this++) {
    varargin_1[b_this] =
        this_->pointList[b_this + this_->pointList.size(0) * 2];
  }
  if (coder::internal::maximum(varargin_1) > this_->param.maxDepth) {
    this_->status = -6.0;
  }
  //  NEED MISSION CLEAN UP
  //              % Vérifier si le sub peut faire surface;
  //              if (min(this.pointList(:,3)) > this.param.surface_warning )
  //                  this.status = this.WARN_AUV_MAY_SURFACE;
  //              end
  //  Definir la taille de la trajectoire
  loop_ub = static_cast<int>(this_->nbPoint);
  this_->trajPosition.set_size(loop_ub, 3);
  loop_ub *= 3;
  for (b_this = 0; b_this < loop_ub; b_this++) {
    this_->trajPosition[b_this] = 0.0;
  }
  loop_ub = static_cast<int>(this_->nbPoint);
  this_->trajQuat.set_size(loop_ub, 4);
  loop_ub <<= 2;
  for (b_this = 0; b_this < loop_ub; b_this++) {
    this_->trajQuat[b_this] = 0.0;
  }
  loop_ub = static_cast<int>(this_->nbPoint);
  this_->trajBodyVelocity.set_size(loop_ub, 3);
  loop_ub *= 3;
  for (b_this = 0; b_this < loop_ub; b_this++) {
    this_->trajBodyVelocity[b_this] = 0.0;
  }
  loop_ub = static_cast<int>(this_->nbPoint);
  this_->trajAngulairRates.set_size(loop_ub, 3);
  loop_ub *= 3;
  for (b_this = 0; b_this < loop_ub; b_this++) {
    this_->trajAngulairRates[b_this] = 0.0;
  }
  loop_ub = static_cast<int>(this_->nbPoint);
  this_->trajLinearAcceleration.set_size(loop_ub, 3);
  loop_ub *= 3;
  for (b_this = 0; b_this < loop_ub; b_this++) {
    this_->trajLinearAcceleration[b_this] = 0.0;
  }
  loop_ub = static_cast<int>(this_->nbPoint);
  this_->trajAngularAcceleration.set_size(loop_ub, 3);
  loop_ub *= 3;
  for (b_this = 0; b_this < loop_ub; b_this++) {
    this_->trajAngularAcceleration[b_this] = 0.0;
  }
  return this_;
}

//
// File trailer for TrajectoryGenerator.cpp
//
// [EOF]
//
