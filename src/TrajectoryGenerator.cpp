//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: TrajectoryGenerator.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 09-Feb-2022 14:06:20
//

// Include Files
#include "TrajectoryGenerator.h"
#include "norm.h"
#include "proc_planner_internal_types.h"
#include "proc_planner_rtwutil.h"
#include "proc_planner_types.h"
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
  double qRel[4];
  double c[3];
  double s[3];
  double b_d;
  double d;
  double q_idx_0;
  double q_idx_1;
  double q_idx_2;
  double q_idx_3;
  double q_tmp;
  double r_idx_2;
  double r_idx_3;
  double vl;
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
  //  Copier le point 2 fois pour forcé accInit a 0.
  s[0] = this_->pointList[0];
  s[1] = this_->pointList[this_->pointList.size(0)];
  s[2] = this_->pointList[this_->pointList.size(0) * 2];
  this_->pointList[1] = s[0];
  this_->pointList[this_->pointList.size(0) + 1] = s[1];
  this_->pointList[this_->pointList.size(0) * 2 + 1] = s[2];
  q_idx_0 = this_->quatList[0];
  q_idx_1 = this_->quatList[this_->quatList.size(0)];
  q_idx_2 = this_->quatList[this_->quatList.size(0) * 2];
  q_idx_3 = this_->quatList[this_->quatList.size(0) * 3];
  this_->quatList[1] = q_idx_0;
  this_->quatList[this_->quatList.size(0) + 1] = q_idx_1;
  this_->quatList[this_->quatList.size(0) * 2 + 1] = q_idx_2;
  this_->quatList[this_->quatList.size(0) * 3 + 1] = q_idx_3;
  this_->timeList[1] = this_->param.ts;
  //  Process le message addpose
  // ==================================================================
  //  Fonction qui interprete les waypoints reçu par ROS
  d = this_->n - 3.0;
  b_i = 0;
  int exitg1;
  do {
    exitg1 = 0;
    if (b_i <= static_cast<int>(d) - 1) {
      //  pour chaques waypoints
      //  transformer les angle d'euler quaternions
      s[0] = this_->MAPM.Pose[b_i].Orientation.Z;
      s[1] = this_->MAPM.Pose[b_i].Orientation.Y;
      s[2] = this_->MAPM.Pose[b_i].Orientation.X;
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
      q_tmp = s[0] * s[1];
      q_idx_0 = b_d * c[2] + q_tmp * vl;
      q_idx_1 = b_d * vl - q_tmp * c[2];
      b_d = s[0] * c[1];
      q_tmp = c[0] * s[1];
      q_idx_2 = q_tmp * c[2] + b_d * vl;
      q_idx_3 = b_d * c[2] - q_tmp * vl;
      //  cree le vecteur pose
      c[0] = this_->MAPM.Pose[b_i].Position.X;
      c[1] = this_->MAPM.Pose[b_i].Position.Y;
      c[2] = this_->MAPM.Pose[b_i].Position.Z;
      //  transformer le point en fonction du frame
      switch (this_->MAPM.Pose[b_i].Frame) {
      case 0U:
        //  position et angle absolue
        this_->pointList[static_cast<int>((static_cast<double>(b_i) + 1.0) +
                                          2.0) -
                         1] = c[0];
        this_->pointList[(static_cast<int>((static_cast<double>(b_i) + 1.0) +
                                           2.0) +
                          this_->pointList.size(0)) -
                         1] = c[1];
        this_->pointList[(static_cast<int>((static_cast<double>(b_i) + 1.0) +
                                           2.0) +
                          this_->pointList.size(0) * 2) -
                         1] = c[2];
        this_->quatList[static_cast<int>((static_cast<double>(b_i) + 1.0) +
                                         2.0) -
                        1] = q_idx_0;
        this_->quatList[(static_cast<int>((static_cast<double>(b_i) + 1.0) +
                                          2.0) +
                         this_->quatList.size(0)) -
                        1] = q_idx_1;
        this_->quatList[(static_cast<int>((static_cast<double>(b_i) + 1.0) +
                                          2.0) +
                         this_->quatList.size(0) * 2) -
                        1] = q_idx_2;
        this_->quatList[(static_cast<int>((static_cast<double>(b_i) + 1.0) +
                                          2.0) +
                         this_->quatList.size(0) * 3) -
                        1] = q_idx_3;
        b_i++;
        break;
      case 1U: {
        bool dir;
        //  position et angle relatif
        // =================================================================
        //  Fonction qui tourne un vecteur selon un quaternion.
        //  quaternion partie scalaire
        //  quaternion partie vectoriel
        //  QuatRotate n'est pas compilable
        vl = 2.0 * ((c[0] * q_idx_1 + c[1] * q_idx_2) + c[2] * q_idx_3);
        b_d = q_idx_0 * q_idx_0 -
              ((q_idx_1 * q_idx_1 + q_idx_2 * q_idx_2) + q_idx_3 * q_idx_3);
        q_tmp = 2.0 * q_idx_0;
        s[0] =
            this_->pointList[b_i] + ((vl * q_idx_1 + b_d * c[0]) +
                                     q_tmp * (q_idx_2 * c[2] - c[1] * q_idx_3));
        s[1] = this_->pointList[b_i + this_->pointList.size(0)] +
               ((vl * q_idx_2 + b_d * c[1]) +
                q_tmp * (c[0] * q_idx_3 - q_idx_1 * c[2]));
        s[2] = this_->pointList[b_i + this_->pointList.size(0) * 2] +
               ((vl * q_idx_3 + b_d * c[2]) +
                q_tmp * (q_idx_1 * c[1] - c[0] * q_idx_2));
        this_->pointList[static_cast<int>((static_cast<double>(b_i) + 1.0) +
                                          2.0) -
                         1] = s[0];
        this_->pointList[(static_cast<int>((static_cast<double>(b_i) + 1.0) +
                                           2.0) +
                          this_->pointList.size(0)) -
                         1] = s[1];
        this_->pointList[(static_cast<int>((static_cast<double>(b_i) + 1.0) +
                                           2.0) +
                          this_->pointList.size(0) * 2) -
                         1] = s[2];
        b_d = this_->quatList[b_i];
        q_tmp = this_->quatList[b_i + this_->quatList.size(0)];
        r_idx_2 = this_->quatList[b_i + this_->quatList.size(0) * 2];
        r_idx_3 = this_->quatList[b_i + this_->quatList.size(0) * 3];
        dir = this_->MAPM.Pose[b_i].Rotation;
        // ==================================================================
        //  Fonnction qui retoure le quaternion le plus court/long selon
        //  l'utilisateur
        vl = ((b_d * q_idx_0 + q_tmp * q_idx_1) + r_idx_2 * q_idx_2) +
             r_idx_3 * q_idx_3;
        //  conjuger le quaternion au besoin
        // if  norm > 1 && dir == 0 || norm < 1 && dir == 1
        if (((vl < 0.0) && (!dir)) || ((vl >= 0.0) && dir)) {
          q_idx_0 = -q_idx_0;
          q_idx_1 = -q_idx_1;
          q_idx_2 = -q_idx_2;
          q_idx_3 = -q_idx_3;
        }
        this_->quatList[static_cast<int>((static_cast<double>(b_i) + 1.0) +
                                         2.0) -
                        1] =
            ((b_d * q_idx_0 - q_tmp * q_idx_1) - r_idx_2 * q_idx_2) -
            r_idx_3 * q_idx_3;
        this_->quatList[(static_cast<int>((static_cast<double>(b_i) + 1.0) +
                                          2.0) +
                         this_->quatList.size(0)) -
                        1] = (b_d * q_idx_1 + q_idx_0 * q_tmp) +
                             (r_idx_2 * q_idx_3 - q_idx_2 * r_idx_3);
        this_->quatList[(static_cast<int>((static_cast<double>(b_i) + 1.0) +
                                          2.0) +
                         this_->quatList.size(0) * 2) -
                        1] = (b_d * q_idx_2 + q_idx_0 * r_idx_2) +
                             (q_idx_1 * r_idx_3 - q_tmp * q_idx_3);
        this_->quatList[(static_cast<int>((static_cast<double>(b_i) + 1.0) +
                                          2.0) +
                         this_->quatList.size(0) * 3) -
                        1] = (b_d * q_idx_3 + q_idx_0 * r_idx_3) +
                             (q_tmp * q_idx_2 - q_idx_1 * r_idx_2);
        b_i++;
      } break;
      case 2U:
        //  position relatif et angle absolue
        // =================================================================
        //  Fonction qui tourne un vecteur selon un quaternion.
        //  quaternion partie scalaire
        //  quaternion partie vectoriel
        //  QuatRotate n'est pas compilable
        vl = 2.0 * ((c[0] * q_idx_1 + c[1] * q_idx_2) + c[2] * q_idx_3);
        b_d = q_idx_0 * q_idx_0 -
              ((q_idx_1 * q_idx_1 + q_idx_2 * q_idx_2) + q_idx_3 * q_idx_3);
        q_tmp = 2.0 * q_idx_0;
        s[0] =
            this_->pointList[b_i] + ((vl * q_idx_1 + b_d * c[0]) +
                                     q_tmp * (q_idx_2 * c[2] - c[1] * q_idx_3));
        s[1] = this_->pointList[b_i + this_->pointList.size(0)] +
               ((vl * q_idx_2 + b_d * c[1]) +
                q_tmp * (c[0] * q_idx_3 - q_idx_1 * c[2]));
        s[2] = this_->pointList[b_i + this_->pointList.size(0) * 2] +
               ((vl * q_idx_3 + b_d * c[2]) +
                q_tmp * (q_idx_1 * c[1] - c[0] * q_idx_2));
        this_->pointList[static_cast<int>((static_cast<double>(b_i) + 1.0) +
                                          2.0) -
                         1] = s[0];
        this_->pointList[(static_cast<int>((static_cast<double>(b_i) + 1.0) +
                                           2.0) +
                          this_->pointList.size(0)) -
                         1] = s[1];
        this_->pointList[(static_cast<int>((static_cast<double>(b_i) + 1.0) +
                                           2.0) +
                          this_->pointList.size(0) * 2) -
                         1] = s[2];
        this_->quatList[static_cast<int>((static_cast<double>(b_i) + 1.0) +
                                         2.0) -
                        1] = q_idx_0;
        this_->quatList[(static_cast<int>((static_cast<double>(b_i) + 1.0) +
                                          2.0) +
                         this_->quatList.size(0)) -
                        1] = q_idx_1;
        this_->quatList[(static_cast<int>((static_cast<double>(b_i) + 1.0) +
                                          2.0) +
                         this_->quatList.size(0) * 2) -
                        1] = q_idx_2;
        this_->quatList[(static_cast<int>((static_cast<double>(b_i) + 1.0) +
                                          2.0) +
                         this_->quatList.size(0) * 3) -
                        1] = q_idx_3;
        b_i++;
        break;
      case 3U: {
        bool dir;
        //  position absolue et angle relatif
        this_->pointList[static_cast<int>((static_cast<double>(b_i) + 1.0) +
                                          2.0) -
                         1] = c[0];
        this_->pointList[(static_cast<int>((static_cast<double>(b_i) + 1.0) +
                                           2.0) +
                          this_->pointList.size(0)) -
                         1] = c[1];
        this_->pointList[(static_cast<int>((static_cast<double>(b_i) + 1.0) +
                                           2.0) +
                          this_->pointList.size(0) * 2) -
                         1] = c[2];
        b_d = this_->quatList[b_i];
        q_tmp = this_->quatList[b_i + this_->quatList.size(0)];
        r_idx_2 = this_->quatList[b_i + this_->quatList.size(0) * 2];
        r_idx_3 = this_->quatList[b_i + this_->quatList.size(0) * 3];
        dir = this_->MAPM.Pose[b_i].Rotation;
        // ==================================================================
        //  Fonnction qui retoure le quaternion le plus court/long selon
        //  l'utilisateur
        vl = ((b_d * q_idx_0 + q_tmp * q_idx_1) + r_idx_2 * q_idx_2) +
             r_idx_3 * q_idx_3;
        //  conjuger le quaternion au besoin
        // if  norm > 1 && dir == 0 || norm < 1 && dir == 1
        if (((vl < 0.0) && (!dir)) || ((vl >= 0.0) && dir)) {
          q_idx_0 = -q_idx_0;
          q_idx_1 = -q_idx_1;
          q_idx_2 = -q_idx_2;
          q_idx_3 = -q_idx_3;
        }
        this_->quatList[static_cast<int>((static_cast<double>(b_i) + 1.0) +
                                         2.0) -
                        1] =
            ((b_d * q_idx_0 - q_tmp * q_idx_1) - r_idx_2 * q_idx_2) -
            r_idx_3 * q_idx_3;
        this_->quatList[(static_cast<int>((static_cast<double>(b_i) + 1.0) +
                                          2.0) +
                         this_->quatList.size(0)) -
                        1] = (b_d * q_idx_1 + q_idx_0 * q_tmp) +
                             (r_idx_2 * q_idx_3 - q_idx_2 * r_idx_3);
        this_->quatList[(static_cast<int>((static_cast<double>(b_i) + 1.0) +
                                          2.0) +
                         this_->quatList.size(0) * 2) -
                        1] = (b_d * q_idx_2 + q_idx_0 * r_idx_2) +
                             (q_idx_1 * r_idx_3 - q_tmp * q_idx_3);
        this_->quatList[(static_cast<int>((static_cast<double>(b_i) + 1.0) +
                                          2.0) +
                         this_->quatList.size(0) * 3) -
                        1] = (b_d * q_idx_3 + q_idx_0 * r_idx_3) +
                             (q_tmp * q_idx_2 - q_idx_1 * r_idx_2);
        b_i++;
      } break;
      default:
        //  Le referentiel n'est pas valide
        this_->status = false;
        printf("INFO : proc planner : Waypoints are not valid  \n");
        fflush(stdout);
        exitg1 = 1;
        break;
      }
    } else {
      //  Copier le dernier waypoint 2 fois pour éviter un comportement
      //  du generateur de trajecteur
      idx = this_->pointList.size(0) - 2;
      b_this = this_->pointList.size(0) - 1;
      s[0] = this_->pointList[idx];
      s[1] = this_->pointList[idx + this_->pointList.size(0)];
      s[2] = this_->pointList[idx + this_->pointList.size(0) * 2];
      this_->pointList[b_this] = s[0];
      this_->pointList[b_this + this_->pointList.size(0)] = s[1];
      this_->pointList[b_this + this_->pointList.size(0) * 2] = s[2];
      idx = this_->quatList.size(0) - 2;
      b_this = this_->quatList.size(0) - 1;
      q_idx_0 = this_->quatList[idx];
      q_idx_1 = this_->quatList[idx + this_->quatList.size(0)];
      q_idx_2 = this_->quatList[idx + this_->quatList.size(0) * 2];
      q_idx_3 = this_->quatList[idx + this_->quatList.size(0) * 3];
      this_->quatList[b_this] = q_idx_0;
      this_->quatList[b_this + this_->quatList.size(0)] = q_idx_1;
      this_->quatList[b_this + this_->quatList.size(0) * 2] = q_idx_2;
      this_->quatList[b_this + this_->quatList.size(0) * 3] = q_idx_3;
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
      s[0] = this_->pointList[b_i + 1] - this_->pointList[b_i];
      s[1] = this_->pointList[(b_i + this_->pointList.size(0)) + 1] -
             this_->pointList[b_i + this_->pointList.size(0)];
      s[2] = this_->pointList[(b_i + this_->pointList.size(0) * 2) + 1] -
             this_->pointList[b_i + this_->pointList.size(0) * 2];
      b_d = coder::b_norm(s);
      //  Déterminer le temps selon aMax
      vl = this_->param.amax;
      vl = std::sqrt(vl);
      tl = 4.0 * std::sqrt(3.0 * b_d) / (3.0 * vl);
      //  Déterminer la vitesse maximum de la trajectoire
      vl = this_->param.amax * tl / 4.0;
      //  Si la vitesse est plus grande que la vitesse maximum
      if (vl > this_->param.vlmax) {
        //  Calculer le temps selon vmax
        tl = 4.0 * b_d / (3.0 * this_->param.vlmax);
      }
      //  Déterminer l'angle entre les 2 quaternions
      q_idx_0 = this_->quatList[b_i];
      q_idx_1 = this_->quatList[b_i + this_->quatList.size(0)];
      q_idx_2 = this_->quatList[b_i + this_->quatList.size(0) * 2];
      q_idx_3 = this_->quatList[b_i + this_->quatList.size(0) * 3];
      q_idx_1 = -q_idx_1;
      q_idx_2 = -q_idx_2;
      q_idx_3 = -q_idx_3;
      b_d = this_->quatList[b_i + 1];
      q_tmp = this_->quatList[(b_i + this_->quatList.size(0)) + 1];
      r_idx_2 = this_->quatList[(b_i + this_->quatList.size(0) * 2) + 1];
      r_idx_3 = this_->quatList[(b_i + this_->quatList.size(0) * 3) + 1];
      qRel[0] = ((q_idx_0 * b_d - q_idx_1 * q_tmp) - q_idx_2 * r_idx_2) -
                q_idx_3 * r_idx_3;
      qRel[1] = (q_idx_0 * q_tmp + b_d * q_idx_1) +
                (q_idx_2 * r_idx_3 - r_idx_2 * q_idx_3);
      qRel[2] = (q_idx_0 * r_idx_2 + b_d * q_idx_2) +
                (q_tmp * q_idx_3 - q_idx_1 * r_idx_3);
      qRel[3] = (q_idx_0 * r_idx_3 + b_d * q_idx_3) +
                (q_idx_1 * r_idx_2 - q_tmp * q_idx_2);
      //  Déterminer le temps angulaire
      vl = 2.0 *
           rt_atan2d_snf(coder::b_norm(*(double(*)[3]) & qRel[1]), qRel[0]) /
           this_->param.vamax;
      c[0] = tl;
      c[1] = vl;
      c[2] = this_->param.ts;
      if (!std::isnan(tl)) {
        idx = 1;
      } else {
        bool exitg2;
        idx = 0;
        k = 2;
        exitg2 = false;
        while ((!exitg2) && (k <= 3)) {
          if (!std::isnan(c[k - 1])) {
            idx = k;
            exitg2 = true;
          } else {
            k++;
          }
        }
      }
      if (idx != 0) {
        tl = c[idx - 1];
        b_this = idx + 1;
        for (k = b_this; k < 4; k++) {
          d = c[k - 1];
          if (tl < d) {
            tl = d;
          }
        }
      }
      this_->timeList[b_i + 1] = this_->timeList[b_i] + tl;
    }
    //  Déterminer le nombre de points
    vl = this_->timeList[this_->timeList.size(0) - 1] / this_->param.ts;
    vl = std::floor(vl);
    this_->nbPoint = vl;
  }
  return this_;
}

//
// File trailer for TrajectoryGenerator.cpp
//
// [EOF]
//
