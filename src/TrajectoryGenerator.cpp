//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: TrajectoryGenerator.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 19-Feb-2022 14:46:56
//

// Include Files
#include "TrajectoryGenerator.h"
#include "proc_planner_internal_types.h"
#include "proc_planner_rtwutil.h"
#include "proc_planner_types.h"
#include "quat2eul.h"
#include "rt_nonfinite.h"
#include "coder_array.h"
#include <cmath>
#include <stdio.h>
#include <string.h>

// Function Definitions
//
// Arguments    : const char multiAddposeMsg_MessageType[25]
//                const coder::array<sonia_common_AddPoseStruct_T, 1U>
//                &multiAddposeMsg_Pose double param_amax double param_vlmax
//                double param_vamax
//                double icMsg_Position_X
//                double icMsg_Position_Y
//                double icMsg_Position_Z
//                double icMsg_Orientation_X
//                double icMsg_Orientation_Y
//                double icMsg_Orientation_Z
//                double icMsg_Orientation_W
// Return Type  : TrajectoryGenerator *
//
TrajectoryGenerator *TrajectoryGenerator::init(
    const char multiAddposeMsg_MessageType[25],
    const coder::array<sonia_common_AddPoseStruct_T, 1U> &multiAddposeMsg_Pose,
    double param_amax, double param_vlmax, double param_vamax,
    double icMsg_Position_X, double icMsg_Position_Y, double icMsg_Position_Z,
    double icMsg_Orientation_X, double icMsg_Orientation_Y,
    double icMsg_Orientation_Z, double icMsg_Orientation_W)
{
  TrajectoryGenerator *this_;
  double q[4];
  double b_dv[3];
  double eul[3];
  double b_d;
  double d;
  double r_idx_1;
  double r_idx_2;
  double r_idx_3;
  double s_idx_0;
  double s_idx_1;
  double s_idx_2;
  double scale;
  int b_i;
  int b_this;
  int i;
  int idx;
  this_ = this;
  this_->status = true;
  this_->nbPoint = 1.0;
  // ==================================================================
  //  Constructeur
  for (i = 0; i < 25; i++) {
    this_->MAPM.MessageType[i] = multiAddposeMsg_MessageType[i];
  }
  this_->MAPM.Pose.set_size(multiAddposeMsg_Pose.size(0));
  idx = multiAddposeMsg_Pose.size(0);
  for (i = 0; i < idx; i++) {
    this_->MAPM.Pose[i] = multiAddposeMsg_Pose[i];
  }
  //  nombre de waypoints + iC
  if (multiAddposeMsg_Pose.size(0) < 1) {
    i = 1;
  } else {
    i = multiAddposeMsg_Pose.size(0);
  }
  this_->n = static_cast<double>(i) + 3.0;
  //  matlab and cpp dont use same index. return max instead
  //  Initialiser les tableaux
  idx = static_cast<int>(this_->n);
  this_->pointList.set_size(idx, 3);
  idx *= 3;
  for (i = 0; i < idx; i++) {
    this_->pointList[i] = 0.0;
  }
  idx = static_cast<int>(this_->n);
  this_->quatList.set_size(idx, 4);
  idx <<= 2;
  for (i = 0; i < idx; i++) {
    this_->quatList[i] = 0.0;
  }
  idx = static_cast<int>(this_->n);
  this_->timeList.set_size(idx);
  for (i = 0; i < idx; i++) {
    this_->timeList[i] = 0.0;
  }
  idx = static_cast<int>(this_->n);
  this_->courseList.set_size(1, idx);
  for (i = 0; i < idx; i++) {
    this_->courseList[i] = 0.0;
  }
  //  Initialiser les parametres
  this_->param.ts = 0.1;
  this_->param.amax = param_amax;
  this_->param.vlmax = param_vlmax;
  this_->param.vamax = param_vamax;
  //  trouver le waypoint initial
  //  lire la position initale
  //  [this.icMsg, status] = receive(this.icSub,5);
  // this.icMsg = this.icSub.LatestMessage;
  // ==================================================================
  //  Fonnction qui retoure le waypoint initial
  // status = ~isempty(this.icMsg);
  //  Replire les listes.
  this_->pointList[0] = icMsg_Position_X;
  this_->pointList[this_->pointList.size(0)] = icMsg_Position_Y;
  this_->pointList[this_->pointList.size(0) * 2] = icMsg_Position_Z;
  this_->quatList[0] = icMsg_Orientation_W;
  this_->quatList[this_->quatList.size(0)] = icMsg_Orientation_X;
  this_->quatList[this_->quatList.size(0) * 2] = icMsg_Orientation_Y;
  this_->quatList[this_->quatList.size(0) * 3] = icMsg_Orientation_Z;
  this_->timeList[0] = 0.0;
  q[0] = this_->quatList[0];
  q[1] = this_->quatList[this_->quatList.size(0)];
  q[2] = this_->quatList[this_->quatList.size(0) * 2];
  q[3] = this_->quatList[this_->quatList.size(0) * 3];
  coder::quat2eul(q, b_dv);
  eul[0] = 57.295779513082323 * b_dv[0];
  this_->courseList[0] = eul[0];
  //  Copier le point 2 fois pour forcé accInit a 0.
  s_idx_0 = this_->pointList[0];
  s_idx_1 = this_->pointList[this_->pointList.size(0)];
  s_idx_2 = this_->pointList[this_->pointList.size(0) * 2];
  this_->pointList[1] = s_idx_0;
  this_->pointList[this_->pointList.size(0) + 1] = s_idx_1;
  this_->pointList[this_->pointList.size(0) * 2 + 1] = s_idx_2;
  q[0] = this_->quatList[0];
  q[1] = this_->quatList[this_->quatList.size(0)];
  q[2] = this_->quatList[this_->quatList.size(0) * 2];
  q[3] = this_->quatList[this_->quatList.size(0) * 3];
  this_->quatList[1] = q[0];
  this_->quatList[this_->quatList.size(0) + 1] = q[1];
  this_->quatList[this_->quatList.size(0) * 2 + 1] = q[2];
  this_->quatList[this_->quatList.size(0) * 3 + 1] = q[3];
  this_->timeList[1] = this_->param.ts;
  this_->courseList[1] = eul[0];
  //  Process le message addpose
  // ==================================================================
  //  Fonction qui interprete les waypoints reçu par ROS
  d = this_->n - 3.0;
  b_i = 0;
  int exitg1;
  do {
    exitg1 = 0;
    if (b_i <= static_cast<int>(d) - 1) {
      bool guard1{false};
      //  pour chaques waypoints
      //  transformer les angle d'euler quaternions
      s_idx_0 = this_->MAPM.Pose[b_i].Orientation.Z;
      s_idx_1 = this_->MAPM.Pose[b_i].Orientation.Y;
      s_idx_2 = this_->MAPM.Pose[b_i].Orientation.X;
      scale = 0.017453292519943295 * s_idx_0 / 2.0;
      eul[0] = std::cos(scale);
      scale = std::sin(scale);
      s_idx_0 = scale;
      scale = 0.017453292519943295 * s_idx_1 / 2.0;
      eul[1] = std::cos(scale);
      scale = std::sin(scale);
      s_idx_1 = scale;
      scale = 0.017453292519943295 * s_idx_2 / 2.0;
      eul[2] = std::cos(scale);
      scale = std::sin(scale);
      s_idx_2 = eul[0] * eul[1];
      b_d = s_idx_0 * s_idx_1;
      q[0] = s_idx_2 * eul[2] + b_d * scale;
      q[1] = s_idx_2 * scale - b_d * eul[2];
      s_idx_2 = s_idx_0 * eul[1];
      b_d = eul[0] * s_idx_1;
      q[2] = b_d * eul[2] + s_idx_2 * scale;
      q[3] = s_idx_2 * eul[2] - b_d * scale;
      //  cree le vecteur pose
      eul[0] = this_->MAPM.Pose[b_i].Position.X;
      eul[1] = this_->MAPM.Pose[b_i].Position.Y;
      eul[2] = this_->MAPM.Pose[b_i].Position.Z;
      //  transformer le point en fonction du frame
      guard1 = false;
      switch (this_->MAPM.Pose[b_i].Frame) {
      case 0U:
        //  position et angle absolue
        this_->quatList[static_cast<int>((static_cast<double>(b_i) + 1.0) +
                                         2.0) -
                        1] = q[0];
        this_->quatList[(static_cast<int>((static_cast<double>(b_i) + 1.0) +
                                          2.0) +
                         this_->quatList.size(0)) -
                        1] = q[1];
        this_->quatList[(static_cast<int>((static_cast<double>(b_i) + 1.0) +
                                          2.0) +
                         this_->quatList.size(0) * 2) -
                        1] = q[2];
        this_->quatList[(static_cast<int>((static_cast<double>(b_i) + 1.0) +
                                          2.0) +
                         this_->quatList.size(0) * 3) -
                        1] = q[3];
        this_->pointList[static_cast<int>((static_cast<double>(b_i) + 1.0) +
                                          2.0) -
                         1] = eul[0];
        this_->pointList[(static_cast<int>((static_cast<double>(b_i) + 1.0) +
                                           2.0) +
                          this_->pointList.size(0)) -
                         1] = eul[1];
        this_->pointList[(static_cast<int>((static_cast<double>(b_i) + 1.0) +
                                           2.0) +
                          this_->pointList.size(0) * 2) -
                         1] = eul[2];
        guard1 = true;
        break;
      case 1U:
        //  position et angle relatif
        b_d = this_->quatList[static_cast<int>(
                                  (static_cast<double>(b_i) + 1.0) + 1.0) -
                              1];
        r_idx_1 = this_->quatList[(static_cast<int>(
                                       (static_cast<double>(b_i) + 1.0) + 1.0) +
                                   this_->quatList.size(0)) -
                                  1];
        r_idx_2 = this_->quatList[(static_cast<int>(
                                       (static_cast<double>(b_i) + 1.0) + 1.0) +
                                   this_->quatList.size(0) * 2) -
                                  1];
        r_idx_3 = this_->quatList[(static_cast<int>(
                                       (static_cast<double>(b_i) + 1.0) + 1.0) +
                                   this_->quatList.size(0) * 3) -
                                  1];
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
        this_->quatList[static_cast<int>((static_cast<double>(b_i) + 1.0) +
                                         2.0) -
                        1] =
            ((b_d * q[0] - r_idx_1 * q[1]) - r_idx_2 * q[2]) - r_idx_3 * q[3];
        this_->quatList[(static_cast<int>((static_cast<double>(b_i) + 1.0) +
                                          2.0) +
                         this_->quatList.size(0)) -
                        1] =
            (b_d * q[1] + q[0] * r_idx_1) + (r_idx_2 * q[3] - q[2] * r_idx_3);
        this_->quatList[(static_cast<int>((static_cast<double>(b_i) + 1.0) +
                                          2.0) +
                         this_->quatList.size(0) * 2) -
                        1] =
            (b_d * q[2] + q[0] * r_idx_2) + (q[1] * r_idx_3 - r_idx_1 * q[3]);
        this_->quatList[(static_cast<int>((static_cast<double>(b_i) + 1.0) +
                                          2.0) +
                         this_->quatList.size(0) * 3) -
                        1] =
            (b_d * q[3] + q[0] * r_idx_3) + (r_idx_1 * q[2] - q[1] * r_idx_2);
        q[0] = this_->quatList[static_cast<int>(
                                   (static_cast<double>(b_i) + 1.0) + 1.0) -
                               1];
        q[1] = this_->quatList[(static_cast<int>(
                                    (static_cast<double>(b_i) + 1.0) + 1.0) +
                                this_->quatList.size(0)) -
                               1];
        q[2] = this_->quatList[(static_cast<int>(
                                    (static_cast<double>(b_i) + 1.0) + 1.0) +
                                this_->quatList.size(0) * 2) -
                               1];
        q[3] = this_->quatList[(static_cast<int>(
                                    (static_cast<double>(b_i) + 1.0) + 1.0) +
                                this_->quatList.size(0) * 3) -
                               1];
        // =================================================================
        //  Fonction qui tourne un vecteur selon un quaternion.
        //  quaternion partie scalaire
        //  quaternion partie vectoriel
        //  QuatRotate n'est pas compilable
        s_idx_2 = 2.0 * ((eul[0] * q[1] + eul[1] * q[2]) + eul[2] * q[3]);
        b_d = q[0] * q[0] - ((q[1] * q[1] + q[2] * q[2]) + q[3] * q[3]);
        scale = 2.0 * q[0];
        s_idx_0 = this_->pointList[static_cast<int>(
                                       (static_cast<double>(b_i) + 1.0) + 1.0) -
                                   1] +
                  ((s_idx_2 * q[1] + b_d * eul[0]) +
                   scale * (q[2] * eul[2] - eul[1] * q[3]));
        s_idx_1 =
            this_->pointList[(static_cast<int>(
                                  (static_cast<double>(b_i) + 1.0) + 1.0) +
                              this_->pointList.size(0)) -
                             1] +
            ((s_idx_2 * q[2] + b_d * eul[1]) +
             scale * (eul[0] * q[3] - q[1] * eul[2]));
        s_idx_2 =
            this_->pointList[(static_cast<int>(
                                  (static_cast<double>(b_i) + 1.0) + 1.0) +
                              this_->pointList.size(0) * 2) -
                             1] +
            ((s_idx_2 * q[3] + b_d * eul[2]) +
             scale * (q[1] * eul[1] - eul[0] * q[2]));
        this_->pointList[static_cast<int>((static_cast<double>(b_i) + 1.0) +
                                          2.0) -
                         1] = s_idx_0;
        this_->pointList[(static_cast<int>((static_cast<double>(b_i) + 1.0) +
                                           2.0) +
                          this_->pointList.size(0)) -
                         1] = s_idx_1;
        this_->pointList[(static_cast<int>((static_cast<double>(b_i) + 1.0) +
                                           2.0) +
                          this_->pointList.size(0) * 2) -
                         1] = s_idx_2;
        guard1 = true;
        break;
      case 2U:
        //  position relatif et angle absolue
        this_->quatList[static_cast<int>((static_cast<double>(b_i) + 1.0) +
                                         2.0) -
                        1] = q[0];
        this_->quatList[(static_cast<int>((static_cast<double>(b_i) + 1.0) +
                                          2.0) +
                         this_->quatList.size(0)) -
                        1] = q[1];
        this_->quatList[(static_cast<int>((static_cast<double>(b_i) + 1.0) +
                                          2.0) +
                         this_->quatList.size(0) * 2) -
                        1] = q[2];
        this_->quatList[(static_cast<int>((static_cast<double>(b_i) + 1.0) +
                                          2.0) +
                         this_->quatList.size(0) * 3) -
                        1] = q[3];
        q[0] = this_->quatList[static_cast<int>(
                                   (static_cast<double>(b_i) + 1.0) + 1.0) -
                               1];
        q[1] = this_->quatList[(static_cast<int>(
                                    (static_cast<double>(b_i) + 1.0) + 1.0) +
                                this_->quatList.size(0)) -
                               1];
        q[2] = this_->quatList[(static_cast<int>(
                                    (static_cast<double>(b_i) + 1.0) + 1.0) +
                                this_->quatList.size(0) * 2) -
                               1];
        q[3] = this_->quatList[(static_cast<int>(
                                    (static_cast<double>(b_i) + 1.0) + 1.0) +
                                this_->quatList.size(0) * 3) -
                               1];
        // =================================================================
        //  Fonction qui tourne un vecteur selon un quaternion.
        //  quaternion partie scalaire
        //  quaternion partie vectoriel
        //  QuatRotate n'est pas compilable
        s_idx_2 = 2.0 * ((eul[0] * q[1] + eul[1] * q[2]) + eul[2] * q[3]);
        b_d = q[0] * q[0] - ((q[1] * q[1] + q[2] * q[2]) + q[3] * q[3]);
        scale = 2.0 * q[0];
        s_idx_0 = this_->pointList[static_cast<int>(
                                       (static_cast<double>(b_i) + 1.0) + 1.0) -
                                   1] +
                  ((s_idx_2 * q[1] + b_d * eul[0]) +
                   scale * (q[2] * eul[2] - eul[1] * q[3]));
        s_idx_1 =
            this_->pointList[(static_cast<int>(
                                  (static_cast<double>(b_i) + 1.0) + 1.0) +
                              this_->pointList.size(0)) -
                             1] +
            ((s_idx_2 * q[2] + b_d * eul[1]) +
             scale * (eul[0] * q[3] - q[1] * eul[2]));
        s_idx_2 =
            this_->pointList[(static_cast<int>(
                                  (static_cast<double>(b_i) + 1.0) + 1.0) +
                              this_->pointList.size(0) * 2) -
                             1] +
            ((s_idx_2 * q[3] + b_d * eul[2]) +
             scale * (q[1] * eul[1] - eul[0] * q[2]));
        this_->pointList[static_cast<int>((static_cast<double>(b_i) + 1.0) +
                                          2.0) -
                         1] = s_idx_0;
        this_->pointList[(static_cast<int>((static_cast<double>(b_i) + 1.0) +
                                           2.0) +
                          this_->pointList.size(0)) -
                         1] = s_idx_1;
        this_->pointList[(static_cast<int>((static_cast<double>(b_i) + 1.0) +
                                           2.0) +
                          this_->pointList.size(0) * 2) -
                         1] = s_idx_2;
        guard1 = true;
        break;
      case 3U:
        //  position absolue et angle relatif
        b_d = this_->quatList[static_cast<int>(
                                  (static_cast<double>(b_i) + 1.0) + 1.0) -
                              1];
        r_idx_1 = this_->quatList[(static_cast<int>(
                                       (static_cast<double>(b_i) + 1.0) + 1.0) +
                                   this_->quatList.size(0)) -
                                  1];
        r_idx_2 = this_->quatList[(static_cast<int>(
                                       (static_cast<double>(b_i) + 1.0) + 1.0) +
                                   this_->quatList.size(0) * 2) -
                                  1];
        r_idx_3 = this_->quatList[(static_cast<int>(
                                       (static_cast<double>(b_i) + 1.0) + 1.0) +
                                   this_->quatList.size(0) * 3) -
                                  1];
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
        this_->quatList[static_cast<int>((static_cast<double>(b_i) + 1.0) +
                                         2.0) -
                        1] =
            ((b_d * q[0] - r_idx_1 * q[1]) - r_idx_2 * q[2]) - r_idx_3 * q[3];
        this_->quatList[(static_cast<int>((static_cast<double>(b_i) + 1.0) +
                                          2.0) +
                         this_->quatList.size(0)) -
                        1] =
            (b_d * q[1] + q[0] * r_idx_1) + (r_idx_2 * q[3] - q[2] * r_idx_3);
        this_->quatList[(static_cast<int>((static_cast<double>(b_i) + 1.0) +
                                          2.0) +
                         this_->quatList.size(0) * 2) -
                        1] =
            (b_d * q[2] + q[0] * r_idx_2) + (q[1] * r_idx_3 - r_idx_1 * q[3]);
        this_->quatList[(static_cast<int>((static_cast<double>(b_i) + 1.0) +
                                          2.0) +
                         this_->quatList.size(0) * 3) -
                        1] =
            (b_d * q[3] + q[0] * r_idx_3) + (r_idx_1 * q[2] - q[1] * r_idx_2);
        this_->pointList[static_cast<int>((static_cast<double>(b_i) + 1.0) +
                                          2.0) -
                         1] = eul[0];
        this_->pointList[(static_cast<int>((static_cast<double>(b_i) + 1.0) +
                                           2.0) +
                          this_->pointList.size(0)) -
                         1] = eul[1];
        this_->pointList[(static_cast<int>((static_cast<double>(b_i) + 1.0) +
                                           2.0) +
                          this_->pointList.size(0) * 2) -
                         1] = eul[2];
        guard1 = true;
        break;
      default:
        //  Le referentiel n'est pas valide
        this_->status = false;
        printf("INFO : proc planner : Waypoints are not valid  \n");
        fflush(stdout);
        exitg1 = 1;
        break;
      }
      if (guard1) {
        //  determiner le yaw pour le vecteur course
        q[0] = this_->quatList[static_cast<int>(
                                   (static_cast<double>(b_i) + 1.0) + 2.0) -
                               1];
        q[1] = this_->quatList[(static_cast<int>(
                                    (static_cast<double>(b_i) + 1.0) + 2.0) +
                                this_->quatList.size(0)) -
                               1];
        q[2] = this_->quatList[(static_cast<int>(
                                    (static_cast<double>(b_i) + 1.0) + 2.0) +
                                this_->quatList.size(0) * 2) -
                               1];
        q[3] = this_->quatList[(static_cast<int>(
                                    (static_cast<double>(b_i) + 1.0) + 2.0) +
                                this_->quatList.size(0) * 3) -
                               1];
        coder::quat2eul(q, b_dv);
        eul[0] = 57.295779513082323 * b_dv[0];
        if (eul[0] < 0.0) {
          eul[0] += 360.0;
        }
        this_->courseList[static_cast<int>((static_cast<double>(b_i) + 1.0) +
                                           2.0) -
                          1] = eul[0];
        b_i++;
      }
    } else {
      //  Copier le dernier waypoint 2 fois pour éviter un comportement
      //  du generateur de trajecteur
      idx = this_->pointList.size(0) - 2;
      b_this = this_->pointList.size(0) - 1;
      s_idx_0 = this_->pointList[idx];
      s_idx_1 = this_->pointList[idx + this_->pointList.size(0)];
      s_idx_2 = this_->pointList[idx + this_->pointList.size(0) * 2];
      this_->pointList[b_this] = s_idx_0;
      this_->pointList[b_this + this_->pointList.size(0)] = s_idx_1;
      this_->pointList[b_this + this_->pointList.size(0) * 2] = s_idx_2;
      idx = this_->quatList.size(0) - 2;
      b_this = this_->quatList.size(0) - 1;
      q[0] = this_->quatList[idx];
      q[1] = this_->quatList[idx + this_->quatList.size(0)];
      q[2] = this_->quatList[idx + this_->quatList.size(0) * 2];
      q[3] = this_->quatList[idx + this_->quatList.size(0) * 3];
      this_->quatList[b_this] = q[0];
      this_->quatList[b_this + this_->quatList.size(0)] = q[1];
      this_->quatList[b_this + this_->quatList.size(0) * 2] = q[2];
      this_->quatList[b_this + this_->quatList.size(0) * 3] = q[3];
      this_->courseList[this_->courseList.size(1) - 1] =
          this_->courseList[this_->courseList.size(1) - 2];
      exitg1 = 1;
    }
  } while (exitg1 == 0);
  if (this_->status) {
    //  Calculer les temps entre chaque waypoints
    // ==================================================================
    //  Fonnction qui calcul le temps entre chaque waypoint
    d = this_->n;
    i = static_cast<int>(d + -1.0);
    for (b_i = 0; b_i < i; b_i++) {
      double tl;
      int k;
      //  pour chaques waypoints
      //  Trouver la distance Eucledienne entre 2 points
      eul[0] = this_->pointList[b_i + 1] - this_->pointList[b_i];
      eul[1] = this_->pointList[(b_i + this_->pointList.size(0)) + 1] -
               this_->pointList[b_i + this_->pointList.size(0)];
      eul[2] = this_->pointList[(b_i + this_->pointList.size(0) * 2) + 1] -
               this_->pointList[b_i + this_->pointList.size(0) * 2];
      scale = 3.3121686421112381E-170;
      s_idx_0 = std::abs(eul[0]);
      if (s_idx_0 > 3.3121686421112381E-170) {
        b_d = 1.0;
        scale = s_idx_0;
      } else {
        s_idx_1 = s_idx_0 / 3.3121686421112381E-170;
        b_d = s_idx_1 * s_idx_1;
      }
      s_idx_0 = std::abs(eul[1]);
      if (s_idx_0 > scale) {
        s_idx_1 = scale / s_idx_0;
        b_d = b_d * s_idx_1 * s_idx_1 + 1.0;
        scale = s_idx_0;
      } else {
        s_idx_1 = s_idx_0 / scale;
        b_d += s_idx_1 * s_idx_1;
      }
      s_idx_0 = std::abs(eul[2]);
      if (s_idx_0 > scale) {
        s_idx_1 = scale / s_idx_0;
        b_d = b_d * s_idx_1 * s_idx_1 + 1.0;
        scale = s_idx_0;
      } else {
        s_idx_1 = s_idx_0 / scale;
        b_d += s_idx_1 * s_idx_1;
      }
      b_d = scale * std::sqrt(b_d);
      //  Déterminer le temps selon aMax
      s_idx_2 = this_->param.amax;
      s_idx_2 = std::sqrt(s_idx_2);
      tl = 4.0 * std::sqrt(3.0 * b_d) / (3.0 * s_idx_2);
      //  Déterminer la vitesse maximum de la trajectoire
      s_idx_2 = this_->param.amax * tl / 4.0;
      //  Si la vitesse est plus grande que la vitesse maximum
      if (s_idx_2 > this_->param.vlmax) {
        //  Calculer le temps selon vmax
        tl = 4.0 * b_d / (3.0 * this_->param.vlmax);
      }
      //  Déterminer l'angle entre les 2 quaternions
      q[0] = this_->quatList[b_i];
      q[1] = this_->quatList[b_i + this_->quatList.size(0)];
      q[2] = this_->quatList[b_i + this_->quatList.size(0) * 2];
      q[3] = this_->quatList[b_i + this_->quatList.size(0) * 3];
      q[1] = -q[1];
      q[2] = -q[2];
      q[3] = -q[3];
      b_d = this_->quatList[b_i + 1];
      r_idx_1 = this_->quatList[(b_i + this_->quatList.size(0)) + 1];
      r_idx_2 = this_->quatList[(b_i + this_->quatList.size(0) * 2) + 1];
      r_idx_3 = this_->quatList[(b_i + this_->quatList.size(0) * 3) + 1];
      //  Déterminer le temps angulaire
      scale = 3.3121686421112381E-170;
      s_idx_0 = std::abs((q[0] * r_idx_1 + b_d * q[1]) +
                         (q[2] * r_idx_3 - r_idx_2 * q[3]));
      if (s_idx_0 > 3.3121686421112381E-170) {
        s_idx_2 = 1.0;
        scale = s_idx_0;
      } else {
        s_idx_1 = s_idx_0 / 3.3121686421112381E-170;
        s_idx_2 = s_idx_1 * s_idx_1;
      }
      s_idx_0 = std::abs((q[0] * r_idx_2 + b_d * q[2]) +
                         (r_idx_1 * q[3] - q[1] * r_idx_3));
      if (s_idx_0 > scale) {
        s_idx_1 = scale / s_idx_0;
        s_idx_2 = s_idx_2 * s_idx_1 * s_idx_1 + 1.0;
        scale = s_idx_0;
      } else {
        s_idx_1 = s_idx_0 / scale;
        s_idx_2 += s_idx_1 * s_idx_1;
      }
      s_idx_0 = std::abs((q[0] * r_idx_3 + b_d * q[3]) +
                         (q[1] * r_idx_2 - r_idx_1 * q[2]));
      if (s_idx_0 > scale) {
        s_idx_1 = scale / s_idx_0;
        s_idx_2 = s_idx_2 * s_idx_1 * s_idx_1 + 1.0;
        scale = s_idx_0;
      } else {
        s_idx_1 = s_idx_0 / scale;
        s_idx_2 += s_idx_1 * s_idx_1;
      }
      s_idx_2 = scale * std::sqrt(s_idx_2);
      s_idx_2 = 2.0 *
                rt_atan2d_snf(s_idx_2,
                              ((q[0] * b_d - q[1] * r_idx_1) - q[2] * r_idx_2) -
                                  q[3] * r_idx_3) /
                this_->param.vamax;
      eul[0] = tl;
      eul[1] = s_idx_2;
      eul[2] = this_->param.ts;
      if (!std::isnan(tl)) {
        idx = 1;
      } else {
        bool exitg2;
        idx = 0;
        k = 2;
        exitg2 = false;
        while ((!exitg2) && (k <= 3)) {
          if (!std::isnan(eul[k - 1])) {
            idx = k;
            exitg2 = true;
          } else {
            k++;
          }
        }
      }
      if (idx != 0) {
        tl = eul[idx - 1];
        b_this = idx + 1;
        for (k = b_this; k < 4; k++) {
          d = eul[k - 1];
          if (tl < d) {
            tl = d;
          }
        }
      }
      this_->timeList[b_i + 1] = this_->timeList[b_i] + tl;
    }
    //  Déterminer le nombre de points
    s_idx_2 = this_->timeList[this_->timeList.size(0) - 1] / this_->param.ts;
    s_idx_2 = std::floor(s_idx_2);
    this_->nbPoint = s_idx_2;
  }
  return this_;
}

//
// File trailer for TrajectoryGenerator.cpp
//
// [EOF]
//
