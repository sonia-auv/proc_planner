//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: TrajectoryGenerator.cpp
//
// MATLAB Coder version            : 5.4
// C/C++ source code generated on  : 09-Jul-2022 18:30:27
//

// Include Files
#include "TrajectoryGenerator.h"
#include "Publisher.h"
#include "colon.h"
#include "diff.h"
#include "geometry_msgs_TransformStruct.h"
#include "geometry_msgs_TwistStruct.h"
#include "interp1.h"
#include "pinv.h"
#include "proc_planner_internal_types.h"
#include "proc_planner_types.h"
#include "quat2eul.h"
#include "rt_nonfinite.h"
#include "trajectory_msgs_MultiDOFJointTrajectoryPointStruct.h"
#include "coder_array.h"
#include "mlroscpp_pub.h"
#include <cmath>
#include <stdio.h>

// Function Definitions
//
// Vérifier la pré-validation
//
// Arguments    : const coder::ros::Publisher *trajpub
// Return Type  : void
//
void TrajectoryGenerator::Compute(const coder::ros::Publisher *trajpub)
{
  static const signed char b[9]{1, 0, 0, 0, 1, 0, 0, 0, 1};
  coder::array<geometry_msgs_TransformStruct_T, 2U> b_y;
  coder::array<geometry_msgs_TwistStruct_T, 2U> c_y;
  coder::array<double, 2U> qdot;
  coder::array<double, 2U> t;
  coder::array<double, 2U> trajList;
  coder::array<double, 1U> b_this;
  coder::array<double, 1U> r;
  geometry_msgs_TransformStruct_T transformBuff;
  geometry_msgs_TwistStruct_T twistBuff;
  trajectory_msgs_MultiDOFJointTrajectoryPointStruct_T trajMsg;
  double dv[9];
  double a[3];
  // ==================================================================
  //  Fonction Main qui génère les waypoints
  if (status == 0.0) {
    double absxk;
    double scale;
    int i;
    int j;
    int ni;
    short i2;
    //  Interpoler les waypoints
    //  vecteur temps
    // ==================================================================
    //  Fonction qui interpole les waypoints
    absxk = param.ts;
    scale = timeList[timeList.size(0) - 1];
    if (std::isnan(absxk) || std::isnan(absxk) || std::isnan(scale)) {
      t.set_size(1, 1);
      t[0] = rtNaN;
    } else if ((absxk == 0.0) || ((absxk < scale) && (absxk < 0.0)) ||
               ((scale < absxk) && (absxk > 0.0))) {
      t.set_size(1, 0);
    } else if ((std::isinf(absxk) || std::isinf(scale)) &&
               (std::isinf(absxk) || (absxk == scale))) {
      t.set_size(1, 1);
      t[0] = rtNaN;
    } else if (std::isinf(absxk)) {
      t.set_size(1, 1);
      t[0] = absxk;
    } else if ((std::floor(absxk) == absxk) && (absxk == absxk)) {
      t.set_size(1, static_cast<int>((scale - absxk) / absxk) + 1);
      ni = static_cast<int>((scale - absxk) / absxk);
      for (i = 0; i <= ni; i++) {
        t[i] = absxk + absxk * static_cast<double>(i);
      }
    } else {
      coder::eml_float_colon(absxk, absxk, scale, t);
    }
    //  Interpoler la trajectoire lineaire
    //  Le parametre verif permet au constructeur de verifier si le mode existe
    //  sans interpoler. Determiner le type d'imterpolation
    // ==================================================================
    //  Fonction qui envoie les message sur ros
    switch (MAPM.InterpolationMethod) {
    case 0U:
      //  piecewise cubic interpolation
      ni = pointList.size(0);
      b_this.set_size(ni);
      for (i = 0; i < ni; i++) {
        b_this[i] = pointList[i];
      }
      coder::interp1(timeList, b_this, t, trajList);
      break;
    case 1U:
      //  spline
      ni = pointList.size(0);
      b_this.set_size(ni);
      for (i = 0; i < ni; i++) {
        b_this[i] = pointList[i];
      }
      coder::b_interp1(timeList, b_this, t, trajList);
      break;
    case 2U:
      //  Cubic convolution
      ni = pointList.size(0);
      b_this.set_size(ni);
      for (i = 0; i < ni; i++) {
        b_this[i] = pointList[i];
      }
      coder::c_interp1(timeList, b_this, t, trajList);
      break;
    default:
      trajList.set_size(1, 1);
      trajList[0] = 0.0;
      break;
    }
    ni = trajList.size(1);
    for (i = 0; i < ni; i++) {
      trajPosition[i] = trajList[i];
    }
    //  Le parametre verif permet au constructeur de verifier si le mode existe
    //  sans interpoler. Determiner le type d'imterpolation
    // ==================================================================
    //  Fonction qui envoie les message sur ros
    switch (MAPM.InterpolationMethod) {
    case 0U:
      //  piecewise cubic interpolation
      ni = pointList.size(0);
      b_this.set_size(ni);
      for (i = 0; i < ni; i++) {
        b_this[i] = pointList[i + pointList.size(0)];
      }
      coder::interp1(timeList, b_this, t, trajList);
      break;
    case 1U:
      //  spline
      ni = pointList.size(0);
      b_this.set_size(ni);
      for (i = 0; i < ni; i++) {
        b_this[i] = pointList[i + pointList.size(0)];
      }
      coder::b_interp1(timeList, b_this, t, trajList);
      break;
    case 2U:
      //  Cubic convolution
      ni = pointList.size(0);
      b_this.set_size(ni);
      for (i = 0; i < ni; i++) {
        b_this[i] = pointList[i + pointList.size(0)];
      }
      coder::c_interp1(timeList, b_this, t, trajList);
      break;
    default:
      trajList.set_size(1, 1);
      trajList[0] = 0.0;
      break;
    }
    ni = trajList.size(1);
    for (i = 0; i < ni; i++) {
      trajPosition[i + trajPosition.size(0)] = trajList[i];
    }
    ni = pointList.size(0);
    b_this.set_size(ni);
    for (i = 0; i < ni; i++) {
      b_this[i] = pointList[i + pointList.size(0) * 2];
    }
    coder::interp1(timeList, b_this, t, trajList);
    ni = trajList.size(1);
    for (i = 0; i < ni; i++) {
      trajPosition[i + trajPosition.size(0) * 2] = trajList[i];
    }
    //  par sécurité, on ne veux pas de courbe en z. laissez pchip
    //  Deriver la trajectoire pour avoir les vitesse linéare;
    ni = trajPosition.size(0);
    b_this.set_size(ni);
    for (i = 0; i < ni; i++) {
      b_this[i] = trajPosition[i];
    }
    coder::diff(b_this, r);
    trajBodyVelocity[0] = 0.0;
    ni = r.size(0);
    for (i = 0; i < ni; i++) {
      trajBodyVelocity[i + 1] = r[i];
    }
    ni = trajPosition.size(0);
    b_this.set_size(ni);
    for (i = 0; i < ni; i++) {
      b_this[i] = trajPosition[i + trajPosition.size(0)];
    }
    coder::diff(b_this, r);
    trajBodyVelocity[trajBodyVelocity.size(0)] = 0.0;
    ni = r.size(0);
    for (i = 0; i < ni; i++) {
      trajBodyVelocity[(i + trajBodyVelocity.size(0)) + 1] = r[i];
    }
    ni = trajPosition.size(0);
    b_this.set_size(ni);
    for (i = 0; i < ni; i++) {
      b_this[i] = trajPosition[i + trajPosition.size(0) * 2];
    }
    coder::diff(b_this, r);
    trajBodyVelocity[trajBodyVelocity.size(0) * 2] = 0.0;
    ni = r.size(0);
    for (i = 0; i < ni; i++) {
      trajBodyVelocity[(i + trajBodyVelocity.size(0) * 2) + 1] = r[i];
    }
    //  Deriver la vitesse pour avoir les acceleration linéare;
    ni = trajBodyVelocity.size(0);
    b_this.set_size(ni);
    for (i = 0; i < ni; i++) {
      b_this[i] = trajBodyVelocity[i];
    }
    coder::diff(b_this, r);
    trajLinearAcceleration[0] = 0.0;
    ni = r.size(0);
    for (i = 0; i < ni; i++) {
      trajLinearAcceleration[i + 1] = r[i];
    }
    ni = trajBodyVelocity.size(0);
    b_this.set_size(ni);
    for (i = 0; i < ni; i++) {
      b_this[i] = trajBodyVelocity[i + trajBodyVelocity.size(0)];
    }
    coder::diff(b_this, r);
    trajLinearAcceleration[trajLinearAcceleration.size(0)] = 0.0;
    ni = r.size(0);
    for (i = 0; i < ni; i++) {
      trajLinearAcceleration[(i + trajLinearAcceleration.size(0)) + 1] = r[i];
    }
    ni = trajBodyVelocity.size(0);
    b_this.set_size(ni);
    for (i = 0; i < ni; i++) {
      b_this[i] = trajBodyVelocity[i + trajBodyVelocity.size(0) * 2];
    }
    coder::diff(b_this, r);
    trajLinearAcceleration[trajLinearAcceleration.size(0) * 2] = 0.0;
    ni = r.size(0);
    for (i = 0; i < ni; i++) {
      trajLinearAcceleration[(i + trajLinearAcceleration.size(0) * 2) + 1] =
          r[i];
    }
    //  Interpoler l'orientation avec pchip. résultat plus smooth/moins jerk que
    //  slerp. De plus, pas d'oscillation
    ni = quatList.size(0);
    b_this.set_size(ni);
    for (i = 0; i < ni; i++) {
      b_this[i] = quatList[i];
    }
    coder::interp1(timeList, b_this, t, trajList);
    ni = trajList.size(1);
    for (i = 0; i < ni; i++) {
      trajQuat[i] = trajList[i];
    }
    //  eta
    ni = quatList.size(0);
    b_this.set_size(ni);
    for (i = 0; i < ni; i++) {
      b_this[i] = quatList[i + quatList.size(0)];
    }
    coder::interp1(timeList, b_this, t, trajList);
    ni = trajList.size(1);
    for (i = 0; i < ni; i++) {
      trajQuat[i + trajQuat.size(0)] = trajList[i];
    }
    //  epsilon 1
    ni = quatList.size(0);
    b_this.set_size(ni);
    for (i = 0; i < ni; i++) {
      b_this[i] = quatList[i + quatList.size(0) * 2];
    }
    coder::interp1(timeList, b_this, t, trajList);
    ni = trajList.size(1);
    for (i = 0; i < ni; i++) {
      trajQuat[i + trajQuat.size(0) * 2] = trajList[i];
    }
    //  epsilon 2
    ni = quatList.size(0);
    b_this.set_size(ni);
    for (i = 0; i < ni; i++) {
      b_this[i] = quatList[i + quatList.size(0) * 3];
    }
    coder::interp1(timeList, b_this, t, trajList);
    ni = trajList.size(1);
    for (i = 0; i < ni; i++) {
      trajQuat[i + trajQuat.size(0) * 3] = trajList[i];
    }
    //  epsilon 3
    //  Dériver l'orientation
    i = static_cast<int>(nbPoint);
    qdot.set_size(i, 4);
    ni = i << 2;
    for (int i1{0}; i1 < ni; i1++) {
      qdot[i1] = 0.0;
    }
    ni = trajQuat.size(0);
    b_this.set_size(ni);
    for (int i1{0}; i1 < ni; i1++) {
      b_this[i1] = trajQuat[i1];
    }
    coder::diff(b_this, r);
    qdot[0] = 0.0;
    ni = r.size(0);
    for (int i1{0}; i1 < ni; i1++) {
      qdot[i1 + 1] = r[i1];
    }
    //  eta_dot
    ni = trajQuat.size(0);
    b_this.set_size(ni);
    for (int i1{0}; i1 < ni; i1++) {
      b_this[i1] = trajQuat[i1 + trajQuat.size(0)];
    }
    coder::diff(b_this, r);
    qdot[qdot.size(0)] = 0.0;
    ni = r.size(0);
    for (int i1{0}; i1 < ni; i1++) {
      qdot[(i1 + qdot.size(0)) + 1] = r[i1];
    }
    //  epsilon 1 dot
    ni = trajQuat.size(0);
    b_this.set_size(ni);
    for (int i1{0}; i1 < ni; i1++) {
      b_this[i1] = trajQuat[i1 + trajQuat.size(0) * 2];
    }
    coder::diff(b_this, r);
    qdot[qdot.size(0) * 2] = 0.0;
    ni = r.size(0);
    for (int i1{0}; i1 < ni; i1++) {
      qdot[(i1 + qdot.size(0) * 2) + 1] = r[i1];
    }
    //  epsilon 2 dot
    ni = trajQuat.size(0);
    b_this.set_size(ni);
    for (int i1{0}; i1 < ni; i1++) {
      b_this[i1] = trajQuat[i1 + trajQuat.size(0) * 3];
    }
    coder::diff(b_this, r);
    qdot[qdot.size(0) * 3] = 0.0;
    ni = r.size(0);
    for (int i1{0}; i1 < ni; i1++) {
      qdot[(i1 + qdot.size(0) * 3) + 1] = r[i1];
    }
    //  epsilon 3 dot
    //  Post traitement
    if (i - 1 >= 0) {
      dv[0] = 0.0;
      dv[4] = 0.0;
      dv[8] = 0.0;
    }
    for (int b_i{0}; b_i < i; b_i++) {
      double dv1[12];
      double invE2[12];
      double b_t;
      double y;
      //  Normaliser les quaternions car l'interpolation de type spline ne le
      //  garentie pas. Fossen(2021) eq 2.86 p.37
      // =================================================================
      //  Fonction qui normalise un quaternion.
      //  quatnormalize de matlab demande areospace block set pour etre
      //  compilable.
      scale = 3.3121686421112381E-170;
      absxk = std::abs(trajQuat[b_i]);
      if (absxk > 3.3121686421112381E-170) {
        y = 1.0;
        scale = absxk;
      } else {
        b_t = absxk / 3.3121686421112381E-170;
        y = b_t * b_t;
      }
      absxk = std::abs(trajQuat[b_i + trajQuat.size(0)]);
      if (absxk > scale) {
        b_t = scale / absxk;
        y = y * b_t * b_t + 1.0;
        scale = absxk;
      } else {
        b_t = absxk / scale;
        y += b_t * b_t;
      }
      absxk = std::abs(trajQuat[b_i + trajQuat.size(0) * 2]);
      if (absxk > scale) {
        b_t = scale / absxk;
        y = y * b_t * b_t + 1.0;
        scale = absxk;
      } else {
        b_t = absxk / scale;
        y += b_t * b_t;
      }
      absxk = std::abs(trajQuat[b_i + trajQuat.size(0) * 3]);
      if (absxk > scale) {
        b_t = scale / absxk;
        y = y * b_t * b_t + 1.0;
        scale = absxk;
      } else {
        b_t = absxk / scale;
        y += b_t * b_t;
      }
      y = scale * std::sqrt(y);
      trajQuat[b_i] = trajQuat[b_i] / y;
      trajQuat[b_i + trajQuat.size(0)] = trajQuat[b_i + trajQuat.size(0)] / y;
      trajQuat[b_i + trajQuat.size(0) * 2] =
          trajQuat[b_i + trajQuat.size(0) * 2] / y;
      trajQuat[b_i + trajQuat.size(0) * 3] =
          trajQuat[b_i + trajQuat.size(0) * 3] / y;
      //  verifier la discontinuité du quaternion.
      if ((b_i + 1U > 1U) && (((trajQuat[b_i - 1] * trajQuat[b_i] +
                                trajQuat[(b_i + trajQuat.size(0)) - 1] *
                                    trajQuat[b_i + trajQuat.size(0)]) +
                               trajQuat[(b_i + trajQuat.size(0) * 2) - 1] *
                                   trajQuat[b_i + trajQuat.size(0) * 2]) +
                                  trajQuat[(b_i + trajQuat.size(0) * 3) - 1] *
                                      trajQuat[b_i + trajQuat.size(0) * 3] <
                              0.0)) {
        trajQuat[b_i] = -trajQuat[b_i];
        trajQuat[b_i + trajQuat.size(0)] = -trajQuat[b_i + trajQuat.size(0)];
        trajQuat[b_i + trajQuat.size(0) * 2] =
            -trajQuat[b_i + trajQuat.size(0) * 2];
        trajQuat[b_i + trajQuat.size(0) * 3] =
            -trajQuat[b_i + trajQuat.size(0) * 3];
      }
      //  Convertir les vitesse lineaire dans le ref sub
      // =================================================================
      //  Fonction qui tourne un vecteur selon un quaternion.
      //  quaternion partie scalaire
      //  quaternion partie vectoriel
      //  QuatRotate n'est pas compilable
      y = 2.0 * ((trajQuat[b_i + trajQuat.size(0)] * trajBodyVelocity[b_i] +
                  trajQuat[b_i + trajQuat.size(0) * 2] *
                      trajBodyVelocity[b_i + trajBodyVelocity.size(0)]) +
                 trajQuat[b_i + trajQuat.size(0) * 3] *
                     trajBodyVelocity[b_i + trajBodyVelocity.size(0) * 2]);
      b_t = trajQuat[b_i] * trajQuat[b_i] -
            ((trajQuat[b_i + trajQuat.size(0)] *
                  trajQuat[b_i + trajQuat.size(0)] +
              trajQuat[b_i + trajQuat.size(0) * 2] *
                  trajQuat[b_i + trajQuat.size(0) * 2]) +
             trajQuat[b_i + trajQuat.size(0) * 3] *
                 trajQuat[b_i + trajQuat.size(0) * 3]);
      absxk = 2.0 * trajQuat[b_i];
      a[0] = absxk * (trajQuat[b_i + trajQuat.size(0) * 2] *
                          trajBodyVelocity[b_i + trajBodyVelocity.size(0) * 2] -
                      trajBodyVelocity[b_i + trajBodyVelocity.size(0)] *
                          trajQuat[b_i + trajQuat.size(0) * 3]);
      a[1] = absxk *
             (trajBodyVelocity[b_i] * trajQuat[b_i + trajQuat.size(0) * 3] -
              trajQuat[b_i + trajQuat.size(0)] *
                  trajBodyVelocity[b_i + trajBodyVelocity.size(0) * 2]);
      a[2] = absxk *
             (trajQuat[b_i + trajQuat.size(0)] *
                  trajBodyVelocity[b_i + trajBodyVelocity.size(0)] -
              trajBodyVelocity[b_i] * trajQuat[b_i + trajQuat.size(0) * 2]);
      //  Convertir des quaternion instantané en vitesse angulaire
      // =================================================================
      //  Fonction qui convertie un quaternion instantané en vitesses
      //  angulaires. Fossen(2021) eq 2.77 - 2.78 page 35
      // =================================================================
      //  Calcule la matrice de transformation vitesse angulaire à quaternion
      //  instantané Fossen(2021) eq 2.47 p30
      // =================================================================
      //  Fonction qui Convertie un vecteur 3x1 en une matrice antisymétrique
      //  3x3
      scale = trajQuat[b_i];
      dv[3] = -trajQuat[b_i + trajQuat.size(0) * 3];
      dv[6] = trajQuat[b_i + trajQuat.size(0) * 2];
      dv[1] = trajQuat[b_i + trajQuat.size(0) * 3];
      dv[7] = -trajQuat[b_i + trajQuat.size(0)];
      dv[2] = -trajQuat[b_i + trajQuat.size(0) * 2];
      dv[5] = trajQuat[b_i + trajQuat.size(0)];
      for (int i1{0}; i1 < 3; i1++) {
        trajBodyVelocity[b_i + trajBodyVelocity.size(0) * i1] =
            (y * trajQuat[b_i + trajQuat.size(0) * (i1 + 1)] +
             b_t * trajBodyVelocity[b_i + trajBodyVelocity.size(0) * i1]) +
            a[i1];
        ni = i1 << 2;
        dv1[ni] = 0.5 * -trajQuat[b_i + trajQuat.size(0) * (i1 + 1)];
        dv1[ni + 1] =
            0.5 * (scale * static_cast<double>(b[3 * i1]) + dv[3 * i1]);
        j = 3 * i1 + 1;
        dv1[ni + 2] = 0.5 * (scale * static_cast<double>(b[j]) + dv[j]);
        j = 3 * i1 + 2;
        dv1[ni + 3] = 0.5 * (scale * static_cast<double>(b[j]) + dv[j]);
      }
      coder::pinv(dv1, invE2);
      //  Convertir les vitesse angulaire dans le ref sub
      //  Convertire les accélération angulaire dans le ref sub
      // =================================================================
      //  Fonction qui tourne un vecteur selon un quaternion.
      //  quaternion partie scalaire
      //  quaternion partie vectoriel
      //  QuatRotate n'est pas compilable
      scale = 0.0;
      b_t = 0.0;
      for (ni = 0; ni < 3; ni++) {
        trajAngulairRates[b_i + trajAngulairRates.size(0) * ni] =
            -(((invE2[ni] * qdot[b_i] +
                invE2[ni + 3] * qdot[b_i + qdot.size(0)]) +
               invE2[ni + 6] * qdot[b_i + qdot.size(0) * 2]) +
              invE2[ni + 9] * qdot[b_i + qdot.size(0) * 3]);
        trajAngulairRates[b_i + trajAngulairRates.size(0) * ni] =
            -trajAngulairRates[b_i + trajAngulairRates.size(0) * ni];
        absxk = trajQuat[b_i + trajQuat.size(0) * (ni + 1)];
        scale +=
            absxk *
            trajLinearAcceleration[b_i + trajLinearAcceleration.size(0) * ni];
        b_t += absxk * absxk;
      }
      y = 2.0 * scale;
      b_t = trajQuat[b_i] * trajQuat[b_i] - b_t;
      scale = 2.0 * trajQuat[b_i];
      a[1] =
          scale *
          (trajLinearAcceleration[b_i] * trajQuat[b_i + trajQuat.size(0) * 3] -
           trajQuat[b_i + trajQuat.size(0)] *
               trajLinearAcceleration[b_i +
                                      trajLinearAcceleration.size(0) * 2]);
      a[2] =
          scale *
          (trajQuat[b_i + trajQuat.size(0)] *
               trajLinearAcceleration[b_i + trajLinearAcceleration.size(0)] -
           trajLinearAcceleration[b_i] * trajQuat[b_i + trajQuat.size(0) * 2]);
      trajLinearAcceleration[b_i] =
          (y * trajQuat[b_i + trajQuat.size(0)] +
           b_t * trajLinearAcceleration[b_i]) +
          scale *
              (trajQuat[b_i + trajQuat.size(0) * 2] *
                   trajLinearAcceleration[b_i +
                                          trajLinearAcceleration.size(0) * 2] -
               trajLinearAcceleration[b_i + trajLinearAcceleration.size(0)] *
                   trajQuat[b_i + trajQuat.size(0) * 3]);
      trajLinearAcceleration[b_i + trajLinearAcceleration.size(0)] =
          (y * trajQuat[b_i + trajQuat.size(0) * 2] +
           b_t * trajLinearAcceleration[b_i + trajLinearAcceleration.size(0)]) +
          a[1];
      trajLinearAcceleration[b_i + trajLinearAcceleration.size(0) * 2] =
          (y * trajQuat[b_i + trajQuat.size(0) * 3] +
           b_t * trajLinearAcceleration[b_i +
                                        trajLinearAcceleration.size(0) * 2]) +
          a[2];
    }
    //  Calucler les acceleration angulaire
    ni = trajAngulairRates.size(0);
    b_this.set_size(ni);
    for (int i1{0}; i1 < ni; i1++) {
      b_this[i1] = trajAngulairRates[i1];
    }
    coder::diff(b_this, r);
    trajAngularAcceleration[0] = 0.0;
    ni = r.size(0);
    for (int i1{0}; i1 < ni; i1++) {
      trajAngularAcceleration[i1 + 1] = r[i1];
    }
    //  p_dot
    ni = trajAngulairRates.size(0);
    b_this.set_size(ni);
    for (int i1{0}; i1 < ni; i1++) {
      b_this[i1] = trajAngulairRates[i1 + trajAngulairRates.size(0)];
    }
    coder::diff(b_this, r);
    trajAngularAcceleration[trajAngularAcceleration.size(0)] = 0.0;
    ni = r.size(0);
    for (int i1{0}; i1 < ni; i1++) {
      trajAngularAcceleration[(i1 + trajAngularAcceleration.size(0)) + 1] =
          r[i1];
    }
    //  q_dot
    ni = trajAngulairRates.size(0);
    b_this.set_size(ni);
    for (int i1{0}; i1 < ni; i1++) {
      b_this[i1] = trajAngulairRates[i1 + trajAngulairRates.size(0) * 2];
    }
    coder::diff(b_this, r);
    trajAngularAcceleration[trajAngularAcceleration.size(0) * 2] = 0.0;
    ni = r.size(0);
    for (int i1{0}; i1 < ni; i1++) {
      trajAngularAcceleration[(i1 + trajAngularAcceleration.size(0) * 2) + 1] =
          r[i1];
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
    scale = nbPoint;
    b_y.set_size(1, static_cast<int>(scale));
    ni = static_cast<int>(scale);
    for (j = 0; j < ni; j++) {
      b_y[j] = transformBuff;
    }
    trajMsg.Transforms.set_size(b_y.size(1));
    ni = b_y.size(1);
    for (int i1{0}; i1 < ni; i1++) {
      trajMsg.Transforms[i1] = b_y[i1];
    }
    c_y.set_size(1, i);
    for (j = 0; j < i; j++) {
      c_y[j] = twistBuff;
    }
    trajMsg.Velocities.set_size(c_y.size(1));
    ni = c_y.size(1);
    for (int i1{0}; i1 < ni; i1++) {
      trajMsg.Velocities[i1] = c_y[i1];
    }
    c_y.set_size(1, i);
    for (j = 0; j < i; j++) {
      c_y[j] = twistBuff;
    }
    trajMsg.Accelerations.set_size(c_y.size(1));
    ni = c_y.size(1);
    for (int i1{0}; i1 < ni; i1++) {
      trajMsg.Accelerations[i1] = c_y[i1];
    }
    //  Remplire le message ROS
    for (int b_i{0}; b_i < i; b_i++) {
      //  Remplire le message Transform.
      transformBuff.Translation.X = trajPosition[b_i];
      transformBuff.Translation.Y = trajPosition[b_i + trajPosition.size(0)];
      transformBuff.Translation.Z =
          trajPosition[b_i + trajPosition.size(0) * 2];
      transformBuff.Rotation.W = trajQuat[b_i];
      transformBuff.Rotation.X = trajQuat[b_i + trajQuat.size(0)];
      transformBuff.Rotation.Y = trajQuat[b_i + trajQuat.size(0) * 2];
      transformBuff.Rotation.Z = trajQuat[b_i + trajQuat.size(0) * 3];
      trajMsg.Transforms[b_i] = transformBuff;
      //  Remplire les vitesse
      twistBuff.Linear.X = trajBodyVelocity[b_i];
      twistBuff.Linear.Y = trajBodyVelocity[b_i + trajBodyVelocity.size(0)];
      twistBuff.Linear.Z = trajBodyVelocity[b_i + trajBodyVelocity.size(0) * 2];
      twistBuff.Angular.X = trajAngulairRates[b_i];
      twistBuff.Angular.Y = trajAngulairRates[b_i + trajAngulairRates.size(0)];
      twistBuff.Angular.Z =
          trajAngulairRates[b_i + trajAngulairRates.size(0) * 2];
      trajMsg.Velocities[b_i] = twistBuff;
      //  Remplire les acceleration
      twistBuff.Linear.X = trajLinearAcceleration[b_i];
      twistBuff.Linear.Y =
          trajLinearAcceleration[b_i + trajLinearAcceleration.size(0)];
      twistBuff.Linear.Z =
          trajLinearAcceleration[b_i + trajLinearAcceleration.size(0) * 2];
      twistBuff.Angular.X = trajAngularAcceleration[b_i];
      twistBuff.Angular.Y =
          trajAngularAcceleration[b_i + trajAngularAcceleration.size(0)];
      twistBuff.Angular.Z =
          trajAngularAcceleration[b_i + trajAngularAcceleration.size(0) * 2];
      trajMsg.Accelerations[b_i] = twistBuff;
    }
    //  Envoyer le message
    MATLABPUBLISHER_publish(trajpub->PublisherHelper, &trajMsg);
    scale = std::round(nbPoint);
    if (scale < 32768.0) {
      if (scale >= -32768.0) {
        i2 = static_cast<short>(scale);
      } else {
        i2 = MIN_int16_T;
      }
    } else if (scale >= 32768.0) {
      i2 = MAX_int16_T;
    } else {
      i2 = 0;
    }
    printf("INFO : proc planner : Trajectory generation succeded with %d "
           "points. \n",
           i2);
    fflush(stdout);
    //  Si on roule en simulation
    //  Retourner true (sucess)
  }
}

//
// Arguments    : void
// Return Type  : void
//
void TrajectoryGenerator::processWpt()
{
  double d;
  int i;
  // ==================================================================
  //  Fonction qui interprete les waypoints reçu par ROS
  d = nMAPM;
  i = 0;
  int exitg1;
  do {
    exitg1 = 0;
    if (i <= static_cast<int>(d) - 1) {
      double q[4];
      double R_Bar;
      double a;
      double absxk;
      double b_scale;
      double c_idx_0;
      double c_idx_1;
      double c_idx_2;
      double c_scale;
      double i_tmp_tmp;
      double s_idx_0;
      double s_idx_1;
      double s_idx_2;
      double scale;
      double t;
      int b_this;
      int c_this;
      bool guard1{false};
      //  pour chaques AddPose
      //  transformer les angle d'euler quaternions
      s_idx_0 = 0.017453292519943295 * MAPM.Pose[i].Orientation.Z / 2.0;
      s_idx_1 = 0.017453292519943295 * MAPM.Pose[i].Orientation.Y / 2.0;
      s_idx_2 = 0.017453292519943295 * MAPM.Pose[i].Orientation.X / 2.0;
      c_idx_0 = std::cos(s_idx_0);
      s_idx_0 = std::sin(s_idx_0);
      c_idx_1 = std::cos(s_idx_1);
      s_idx_1 = std::sin(s_idx_1);
      c_idx_2 = std::cos(s_idx_2);
      s_idx_2 = std::sin(s_idx_2);
      absxk = c_idx_0 * c_idx_1;
      scale = s_idx_0 * s_idx_1;
      q[0] = absxk * c_idx_2 + scale * s_idx_2;
      q[1] = absxk * s_idx_2 - scale * c_idx_2;
      absxk = s_idx_0 * c_idx_1;
      scale = c_idx_0 * s_idx_1;
      q[2] = scale * c_idx_2 + absxk * s_idx_2;
      q[3] = absxk * c_idx_2 - scale * s_idx_2;
      //  cree le vecteur pose
      c_idx_0 = MAPM.Pose[i].Position.X;
      c_idx_1 = MAPM.Pose[i].Position.Y;
      c_idx_2 = MAPM.Pose[i].Position.Z;
      //  transformer le point en fonction du frame
      guard1 = false;
      switch (MAPM.Pose[i].Frame) {
      case 0U:
        //  position et angle absolue
        //  Regarder la discontinuité entre le qk et qk-1
        // =================================================================
        //  Fonction qui assure la continuité entre 2 quaternions
        absxk = (static_cast<double>(i) + 1.0) + icOffset;
        if (((quatList[static_cast<int>(absxk - 1.0) - 1] * q[0] +
              quatList[(static_cast<int>(absxk - 1.0) + quatList.size(0)) - 1] *
                  q[1]) +
             quatList[(static_cast<int>(absxk - 1.0) + quatList.size(0) * 2) -
                      1] *
                 q[2]) +
                quatList[(static_cast<int>(absxk - 1.0) +
                          quatList.size(0) * 3) -
                         1] *
                    q[3] <
            0.0) {
          q[0] = -q[0];
          q[1] = -q[1];
          q[2] = -q[2];
          q[3] = -q[3];
        }
        quatList[static_cast<int>(absxk) - 1] = q[0];
        quatList[(static_cast<int>(absxk) + quatList.size(0)) - 1] = q[1];
        quatList[(static_cast<int>(absxk) + quatList.size(0) * 2) - 1] = q[2];
        quatList[(static_cast<int>(absxk) + quatList.size(0) * 3) - 1] = q[3];
        b_this = static_cast<int>((static_cast<double>(i) + 1.0) + icOffset);
        pointList[b_this - 1] = c_idx_0;
        pointList[(b_this + pointList.size(0)) - 1] = c_idx_1;
        pointList[(b_this + pointList.size(0) * 2) - 1] = c_idx_2;
        guard1 = true;
        break;
      case 1U:
        //  position et angle relatif
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
        absxk =
            quatList[static_cast<int>(
                         ((static_cast<double>(i) + 1.0) + icOffset) - 1.0) -
                     1];
        scale =
            quatList[(static_cast<int>(
                          ((static_cast<double>(i) + 1.0) + icOffset) - 1.0) +
                      quatList.size(0) * 2) -
                     1];
        t = quatList[(static_cast<int>(
                          ((static_cast<double>(i) + 1.0) + icOffset) - 1.0) +
                      quatList.size(0) * 3) -
                     1];
        R_Bar =
            quatList[(static_cast<int>(
                          ((static_cast<double>(i) + 1.0) + icOffset) - 1.0) +
                      quatList.size(0)) -
                     1];
        b_this = static_cast<int>((static_cast<double>(i) + 1.0) + icOffset);
        quatList[b_this - 1] =
            ((quatList[static_cast<int>(
                           ((static_cast<double>(i) + 1.0) + icOffset) - 1.0) -
                       1] *
                  q[0] -
              quatList[(static_cast<int>(
                            ((static_cast<double>(i) + 1.0) + icOffset) - 1.0) +
                        quatList.size(0)) -
                       1] *
                  q[1]) -
             quatList[(static_cast<int>(
                           ((static_cast<double>(i) + 1.0) + icOffset) - 1.0) +
                       quatList.size(0) * 2) -
                      1] *
                 q[2]) -
            quatList[(static_cast<int>(
                          ((static_cast<double>(i) + 1.0) + icOffset) - 1.0) +
                      quatList.size(0) * 3) -
                     1] *
                q[3];
        quatList[(b_this + quatList.size(0)) - 1] =
            (absxk * q[1] + q[0] * R_Bar) + (scale * q[3] - q[2] * t);
        quatList[(b_this + quatList.size(0) * 2) - 1] =
            (absxk * q[2] + q[0] * scale) + (q[1] * t - R_Bar * q[3]);
        quatList[(b_this + quatList.size(0) * 3) - 1] =
            (absxk * q[3] + q[0] * t) + (R_Bar * q[2] - q[1] * scale);
        c_this =
            static_cast<int>(((static_cast<double>(i) + 1.0) + icOffset) - 1.0);
        // =================================================================
        //  Fonction qui tourne un vecteur selon un quaternion.
        //  quaternion partie scalaire
        //  quaternion partie vectoriel
        //  QuatRotate n'est pas compilable
        a = 2.0 * ((quatList[(c_this + quatList.size(0)) - 1] * c_idx_0 +
                    quatList[(c_this + quatList.size(0) * 2) - 1] * c_idx_1) +
                   quatList[(c_this + quatList.size(0) * 3) - 1] * c_idx_2);
        b_scale =
            quatList[static_cast<int>(
                         ((static_cast<double>(i) + 1.0) + icOffset) - 1.0) -
                     1] *
                quatList[static_cast<int>(
                             ((static_cast<double>(i) + 1.0) + icOffset) -
                             1.0) -
                         1] -
            ((quatList[(c_this + quatList.size(0)) - 1] *
                  quatList[(c_this + quatList.size(0)) - 1] +
              quatList[(c_this + quatList.size(0) * 2) - 1] *
                  quatList[(c_this + quatList.size(0) * 2) - 1]) +
             quatList[(c_this + quatList.size(0) * 3) - 1] *
                 quatList[(c_this + quatList.size(0) * 3) - 1]);
        c_scale =
            2.0 *
            quatList[static_cast<int>(
                         ((static_cast<double>(i) + 1.0) + icOffset) - 1.0) -
                     1];
        R_Bar =
            pointList[(c_this + pointList.size(0)) - 1] +
            ((a * quatList[(c_this + quatList.size(0) * 2) - 1] +
              b_scale * c_idx_1) +
             c_scale *
                 (c_idx_0 * quatList[(static_cast<int>(
                                          ((static_cast<double>(i) + 1.0) +
                                           icOffset) -
                                          1.0) +
                                      quatList.size(0) * 3) -
                                     1] -
                  quatList[(static_cast<int>(
                                ((static_cast<double>(i) + 1.0) + icOffset) -
                                1.0) +
                            quatList.size(0)) -
                           1] *
                      c_idx_2));
        absxk =
            pointList[(c_this + pointList.size(0) * 2) - 1] +
            ((a * quatList[(c_this + quatList.size(0) * 3) - 1] +
              b_scale * c_idx_2) +
             c_scale *
                 (quatList[(static_cast<int>(
                                ((static_cast<double>(i) + 1.0) + icOffset) -
                                1.0) +
                            quatList.size(0)) -
                           1] *
                      c_idx_1 -
                  c_idx_0 * quatList[(static_cast<int>(
                                          ((static_cast<double>(i) + 1.0) +
                                           icOffset) -
                                          1.0) +
                                      quatList.size(0) * 2) -
                                     1]));
        pointList[b_this - 1] =
            pointList[c_this - 1] +
            ((a * quatList[(c_this + quatList.size(0)) - 1] +
              b_scale * c_idx_0) +
             c_scale *
                 (quatList[(static_cast<int>(
                                ((static_cast<double>(i) + 1.0) + icOffset) -
                                1.0) +
                            quatList.size(0) * 2) -
                           1] *
                      c_idx_2 -
                  c_idx_1 * quatList[(static_cast<int>(
                                          ((static_cast<double>(i) + 1.0) +
                                           icOffset) -
                                          1.0) +
                                      quatList.size(0) * 3) -
                                     1]));
        pointList[(b_this + pointList.size(0)) - 1] = R_Bar;
        pointList[(b_this + pointList.size(0) * 2) - 1] = absxk;
        guard1 = true;
        break;
      case 2U:
        //  position relatif et angle absolue
        //  Regarder la discontinuité entre le qk et qk-1
        // =================================================================
        //  Fonction qui assure la continuité entre 2 quaternions
        i_tmp_tmp = (static_cast<double>(i) + 1.0) + icOffset;
        if (((quatList[static_cast<int>(i_tmp_tmp - 1.0) - 1] * q[0] +
              quatList[(static_cast<int>(i_tmp_tmp - 1.0) + quatList.size(0)) -
                       1] *
                  q[1]) +
             quatList[(static_cast<int>(i_tmp_tmp - 1.0) +
                       quatList.size(0) * 2) -
                      1] *
                 q[2]) +
                quatList[(static_cast<int>(i_tmp_tmp - 1.0) +
                          quatList.size(0) * 3) -
                         1] *
                    q[3] <
            0.0) {
          q[0] = -q[0];
          q[1] = -q[1];
          q[2] = -q[2];
          q[3] = -q[3];
        }
        quatList[static_cast<int>(i_tmp_tmp) - 1] = q[0];
        quatList[(static_cast<int>(i_tmp_tmp) + quatList.size(0)) - 1] = q[1];
        quatList[(static_cast<int>(i_tmp_tmp) + quatList.size(0) * 2) - 1] =
            q[2];
        quatList[(static_cast<int>(i_tmp_tmp) + quatList.size(0) * 3) - 1] =
            q[3];
        // =================================================================
        //  Fonction qui tourne un vecteur selon un quaternion.
        //  quaternion partie scalaire
        //  quaternion partie vectoriel
        //  QuatRotate n'est pas compilable
        a = 2.0 *
            ((quatList[(static_cast<int>(i_tmp_tmp - 1.0) + quatList.size(0)) -
                       1] *
                  c_idx_0 +
              quatList[(static_cast<int>(i_tmp_tmp - 1.0) +
                        quatList.size(0) * 2) -
                       1] *
                  c_idx_1) +
             quatList[(static_cast<int>(i_tmp_tmp - 1.0) +
                       quatList.size(0) * 3) -
                      1] *
                 c_idx_2);
        absxk =
            quatList[static_cast<int>(
                         ((static_cast<double>(i) + 1.0) + icOffset) - 1.0) -
                     1];
        b_scale =
            absxk * absxk -
            ((quatList[(static_cast<int>(i_tmp_tmp - 1.0) + quatList.size(0)) -
                       1] *
                  quatList[(static_cast<int>(i_tmp_tmp - 1.0) +
                            quatList.size(0)) -
                           1] +
              quatList[(static_cast<int>(i_tmp_tmp - 1.0) +
                        quatList.size(0) * 2) -
                       1] *
                  quatList[(static_cast<int>(i_tmp_tmp - 1.0) +
                            quatList.size(0) * 2) -
                           1]) +
             quatList[(static_cast<int>(i_tmp_tmp - 1.0) +
                       quatList.size(0) * 3) -
                      1] *
                 quatList[(static_cast<int>(i_tmp_tmp - 1.0) +
                           quatList.size(0) * 3) -
                          1]);
        c_scale = 2.0 * absxk;
        scale =
            quatList[(static_cast<int>(
                          ((static_cast<double>(i) + 1.0) + icOffset) - 1.0) +
                      quatList.size(0) * 3) -
                     1];
        t = quatList[(static_cast<int>(
                          ((static_cast<double>(i) + 1.0) + icOffset) - 1.0) +
                      quatList.size(0) * 2) -
                     1];
        absxk =
            quatList[(static_cast<int>(
                          ((static_cast<double>(i) + 1.0) + icOffset) - 1.0) +
                      quatList.size(0)) -
                     1];
        R_Bar =
            pointList[(static_cast<int>(i_tmp_tmp - 1.0) + pointList.size(0)) -
                      1] +
            ((a * quatList[(static_cast<int>(i_tmp_tmp - 1.0) +
                            quatList.size(0) * 2) -
                           1] +
              b_scale * c_idx_1) +
             c_scale * (c_idx_0 * scale - absxk * c_idx_2));
        absxk = pointList[(static_cast<int>(i_tmp_tmp - 1.0) +
                           pointList.size(0) * 2) -
                          1] +
                ((a * quatList[(static_cast<int>(i_tmp_tmp - 1.0) +
                                quatList.size(0) * 3) -
                               1] +
                  b_scale * c_idx_2) +
                 c_scale * (absxk * c_idx_1 - c_idx_0 * t));
        pointList[static_cast<int>(i_tmp_tmp) - 1] =
            pointList[static_cast<int>(i_tmp_tmp - 1.0) - 1] +
            ((a * quatList[(static_cast<int>(i_tmp_tmp - 1.0) +
                            quatList.size(0)) -
                           1] +
              b_scale * c_idx_0) +
             c_scale * (t * c_idx_2 - c_idx_1 * scale));
        pointList[(static_cast<int>(i_tmp_tmp) + pointList.size(0)) - 1] =
            R_Bar;
        pointList[(static_cast<int>(i_tmp_tmp) + pointList.size(0) * 2) - 1] =
            absxk;
        guard1 = true;
        break;
      case 3U:
        //  position absolue et angle relatif
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
        absxk =
            (quatList[static_cast<int>(
                          ((static_cast<double>(i) + 1.0) + icOffset) - 1.0) -
                      1] *
                 q[1] +
             q[0] * quatList[(static_cast<int>(
                                  ((static_cast<double>(i) + 1.0) + icOffset) -
                                  1.0) +
                              quatList.size(0)) -
                             1]) +
            (quatList[(static_cast<int>(
                           ((static_cast<double>(i) + 1.0) + icOffset) - 1.0) +
                       quatList.size(0) * 2) -
                      1] *
                 q[3] -
             q[2] * quatList[(static_cast<int>(
                                  ((static_cast<double>(i) + 1.0) + icOffset) -
                                  1.0) +
                              quatList.size(0) * 3) -
                             1]);
        scale =
            (quatList[static_cast<int>(
                          ((static_cast<double>(i) + 1.0) + icOffset) - 1.0) -
                      1] *
                 q[2] +
             q[0] * quatList[(static_cast<int>(
                                  ((static_cast<double>(i) + 1.0) + icOffset) -
                                  1.0) +
                              quatList.size(0) * 2) -
                             1]) +
            (q[1] * quatList[(static_cast<int>(
                                  ((static_cast<double>(i) + 1.0) + icOffset) -
                                  1.0) +
                              quatList.size(0) * 3) -
                             1] -
             quatList[(static_cast<int>(
                           ((static_cast<double>(i) + 1.0) + icOffset) - 1.0) +
                       quatList.size(0)) -
                      1] *
                 q[3]);
        t = (quatList[static_cast<int>(
                          ((static_cast<double>(i) + 1.0) + icOffset) - 1.0) -
                      1] *
                 q[3] +
             q[0] * quatList[(static_cast<int>(
                                  ((static_cast<double>(i) + 1.0) + icOffset) -
                                  1.0) +
                              quatList.size(0) * 3) -
                             1]) +
            (quatList[(static_cast<int>(
                           ((static_cast<double>(i) + 1.0) + icOffset) - 1.0) +
                       quatList.size(0)) -
                      1] *
                 q[2] -
             q[1] * quatList[(static_cast<int>(
                                  ((static_cast<double>(i) + 1.0) + icOffset) -
                                  1.0) +
                              quatList.size(0) * 2) -
                             1]);
        b_this = static_cast<int>((static_cast<double>(i) + 1.0) + icOffset);
        quatList[b_this - 1] =
            ((quatList[static_cast<int>(
                           ((static_cast<double>(i) + 1.0) + icOffset) - 1.0) -
                       1] *
                  q[0] -
              quatList[(static_cast<int>(
                            ((static_cast<double>(i) + 1.0) + icOffset) - 1.0) +
                        quatList.size(0)) -
                       1] *
                  q[1]) -
             quatList[(static_cast<int>(
                           ((static_cast<double>(i) + 1.0) + icOffset) - 1.0) +
                       quatList.size(0) * 2) -
                      1] *
                 q[2]) -
            quatList[(static_cast<int>(
                          ((static_cast<double>(i) + 1.0) + icOffset) - 1.0) +
                      quatList.size(0) * 3) -
                     1] *
                q[3];
        quatList[(b_this + quatList.size(0)) - 1] = absxk;
        quatList[(b_this + quatList.size(0) * 2) - 1] = scale;
        quatList[(b_this + quatList.size(0) * 3) - 1] = t;
        pointList[b_this - 1] = c_idx_0;
        pointList[(b_this + pointList.size(0)) - 1] = c_idx_1;
        pointList[(b_this + pointList.size(0) * 2) - 1] = c_idx_2;
        guard1 = true;
        break;
      default: {
        unsigned int varargin_1_idx_0;
        unsigned char id;
        //  Référentiel obstacles
        id = MAPM.Pose[i].Frame;
        //  determiner le nombre d'obstacle
        // ==================================================================
        //  Fonction qui vérifie frame obstacles
        varargin_1_idx_0 =
            static_cast<unsigned int>(obstacleData.Obstacles.size(0));
        s_idx_0 = 0.0;
        s_idx_1 = 0.0;
        s_idx_2 = 0.0;
        t = 0.0;
        R_Bar = 0.0;
        absxk = 0.0;
        scale = 0.0;
        //  check if obstacle exist
        if (static_cast<int>(varargin_1_idx_0) < 1) {
          b_this = 1;
        } else {
          b_this = static_cast<int>(varargin_1_idx_0);
        }
        if ((id <= b_this + 10U) && (id > 10)) {
          //  check if obstacle is found
          if (obstacleData.Obstacles[id - 11].IsValid) {
            s_idx_0 = obstacleData.Obstacles[id - 11].Pose.Position.X;
            s_idx_1 = obstacleData.Obstacles[id - 11].Pose.Position.Y;
            s_idx_2 = obstacleData.Obstacles[id - 11].Pose.Position.Z;
            t = obstacleData.Obstacles[id - 11].Pose.Orientation.W;
            R_Bar = obstacleData.Obstacles[id - 11].Pose.Orientation.X;
            absxk = obstacleData.Obstacles[id - 11].Pose.Orientation.Y;
            scale = obstacleData.Obstacles[id - 11].Pose.Orientation.Z;
          } else {
            status = -7.0;
            printf("INFO : proc planner : Desired obstacle is not detected.\n");
            fflush(stdout);
          }
        } else {
          status = -2.0;
          printf("INFO : proc planner : Invalid Reference Frame.\n");
          fflush(stdout);
        }
        if (status >= 0.0) {
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
          b_this = static_cast<int>((static_cast<double>(i) + 1.0) + icOffset);
          quatList[b_this - 1] =
              ((t * q[0] - R_Bar * q[1]) - absxk * q[2]) - scale * q[3];
          quatList[(b_this + quatList.size(0)) - 1] =
              (t * q[1] + q[0] * R_Bar) + (absxk * q[3] - q[2] * scale);
          quatList[(b_this + quatList.size(0) * 2) - 1] =
              (t * q[2] + q[0] * absxk) + (q[1] * scale - R_Bar * q[3]);
          quatList[(b_this + quatList.size(0) * 3) - 1] =
              (t * q[3] + q[0] * scale) + (R_Bar * q[2] - q[1] * absxk);
          c_this = static_cast<int>(
              ((static_cast<double>(i) + 1.0) + icOffset) - 1.0);
          q[2] = quatList[(c_this + quatList.size(0) * 2) - 1];
          q[3] = quatList[(c_this + quatList.size(0) * 3) - 1];
          // =================================================================
          //  Fonction qui tourne un vecteur selon un quaternion.
          //  quaternion partie scalaire
          //  quaternion partie vectoriel
          //  QuatRotate n'est pas compilable
          a = 2.0 * ((quatList[(c_this + quatList.size(0)) - 1] * c_idx_0 +
                      quatList[(c_this + quatList.size(0) * 2) - 1] * c_idx_1) +
                     quatList[(c_this + quatList.size(0) * 3) - 1] * c_idx_2);
          b_scale =
              quatList[static_cast<int>(
                           ((static_cast<double>(i) + 1.0) + icOffset) - 1.0) -
                       1] *
                  quatList[static_cast<int>(
                               ((static_cast<double>(i) + 1.0) + icOffset) -
                               1.0) -
                           1] -
              ((quatList[(c_this + quatList.size(0)) - 1] *
                    quatList[(c_this + quatList.size(0)) - 1] +
                quatList[(c_this + quatList.size(0) * 2) - 1] *
                    quatList[(c_this + quatList.size(0) * 2) - 1]) +
               quatList[(c_this + quatList.size(0) * 3) - 1] *
                   quatList[(c_this + quatList.size(0) * 3) - 1]);
          c_scale =
              2.0 *
              quatList[static_cast<int>(
                           ((static_cast<double>(i) + 1.0) + icOffset) - 1.0) -
                       1];
          absxk =
              c_scale *
              (c_idx_0 *
                   quatList[(static_cast<int>(
                                 ((static_cast<double>(i) + 1.0) + icOffset) -
                                 1.0) +
                             quatList.size(0) * 3) -
                            1] -
               quatList[(static_cast<int>(
                             ((static_cast<double>(i) + 1.0) + icOffset) -
                             1.0) +
                         quatList.size(0)) -
                        1] *
                   c_idx_2);
          scale =
              c_scale *
              (quatList[(static_cast<int>(
                             ((static_cast<double>(i) + 1.0) + icOffset) -
                             1.0) +
                         quatList.size(0)) -
                        1] *
                   c_idx_1 -
               c_idx_0 *
                   quatList[(static_cast<int>(
                                 ((static_cast<double>(i) + 1.0) + icOffset) -
                                 1.0) +
                             quatList.size(0) * 2) -
                            1]);
          pointList[b_this - 1] =
              s_idx_0 +
              ((a * quatList[(c_this + quatList.size(0)) - 1] +
                b_scale * c_idx_0) +
               c_scale *
                   (quatList[(static_cast<int>(
                                  ((static_cast<double>(i) + 1.0) + icOffset) -
                                  1.0) +
                              quatList.size(0) * 2) -
                             1] *
                        c_idx_2 -
                    c_idx_1 * quatList[(static_cast<int>(
                                            ((static_cast<double>(i) + 1.0) +
                                             icOffset) -
                                            1.0) +
                                        quatList.size(0) * 3) -
                                       1]));
          pointList[(b_this + pointList.size(0)) - 1] =
              s_idx_1 + ((a * q[2] + b_scale * c_idx_1) + absxk);
          pointList[(b_this + pointList.size(0) * 2) - 1] =
              s_idx_2 + ((a * q[3] + b_scale * c_idx_2) + scale);
          guard1 = true;
        } else {
          exitg1 = 1;
        }
      } break;
      }
      if (guard1) {
        double dv[3];
        //  copier le parametre de vitesse
        speedList[static_cast<int>((static_cast<double>(i) + 1.0) + icOffset) -
                  1] = MAPM.Pose[i].Speed;
        //  determiner le yaw pour le vecteur course
        b_this = static_cast<int>((static_cast<double>(i) + 1.0) + icOffset);
        q[0] = quatList[b_this - 1];
        q[1] = quatList[(b_this + quatList.size(0)) - 1];
        q[2] = quatList[(b_this + quatList.size(0) * 2) - 1];
        q[3] = quatList[(b_this + quatList.size(0) * 3) - 1];
        // ==================================================================
        //  Fonction qui retourne l'angle de course
        coder::quat2eul(q, dv);
        c_idx_0 = 57.295779513082323 * dv[0];
        if (c_idx_0 < 0.0) {
          c_idx_0 += 360.0;
        }
        courseList[static_cast<int>((static_cast<double>(i) + 1.0) + icOffset) -
                   1] = c_idx_0;
        //  verifier si faut arrondire la trajectoire.
        if ((static_cast<double>(i) + 1.0 > 1.0) &&
            (MAPM.Pose[static_cast<int>((static_cast<double>(i) + 1.0) - 1.0) -
                       1]
                 .Fine != 0.0)) {
          bool valid;
          i_tmp_tmp = (static_cast<double>(i) + 1.0) + icOffset;
          // ==================================================================
          //  Fonction qui arrondie les waypoints.
          R_Bar = MAPM.Pose[static_cast<int>((i_tmp_tmp - icOffset) - 1.0) - 1]
                      .Fine;
          //  Si rayon positif calculer la courbe
          if (R_Bar > 0.0) {
            double b;
            double c;
            double d1;
            double d2;
            double d3;
            double d4;
            double d5;
            double d6;
            //  Definition point.
            //  Determiner les vecteurs
            //  Determiner les longeures du triangle
            c_scale = 3.3121686421112381E-170;
            b_scale = 3.3121686421112381E-170;
            scale = 3.3121686421112381E-170;
            s_idx_2 = pointList[static_cast<int>(i_tmp_tmp) - 2];
            c_idx_2 = pointList[static_cast<int>(i_tmp_tmp) - 3];
            d1 = s_idx_2 - c_idx_2;
            c_idx_0 = d1;
            d2 = pointList[static_cast<int>(i_tmp_tmp) - 1];
            d3 = d2 - s_idx_2;
            s_idx_0 = d3;
            absxk = std::abs(d2 - c_idx_2);
            if (absxk > 3.3121686421112381E-170) {
              a = 1.0;
              c_scale = absxk;
            } else {
              t = absxk / 3.3121686421112381E-170;
              a = t * t;
            }
            absxk = std::abs(d1);
            if (absxk > 3.3121686421112381E-170) {
              b = 1.0;
              b_scale = absxk;
            } else {
              t = absxk / 3.3121686421112381E-170;
              b = t * t;
            }
            absxk = std::abs(d3);
            if (absxk > 3.3121686421112381E-170) {
              c = 1.0;
              scale = absxk;
            } else {
              t = absxk / 3.3121686421112381E-170;
              c = t * t;
            }
            d2 = pointList[(static_cast<int>(i_tmp_tmp) + pointList.size(0)) -
                           2];
            d4 = pointList[(static_cast<int>(i_tmp_tmp) + pointList.size(0)) -
                           3];
            d1 = d2 - d4;
            c_idx_1 = d1;
            d5 = pointList[(static_cast<int>(i_tmp_tmp) + pointList.size(0)) -
                           1];
            d3 = d5 - d2;
            s_idx_1 = d3;
            absxk = std::abs(d5 - d4);
            if (absxk > c_scale) {
              t = c_scale / absxk;
              a = a * t * t + 1.0;
              c_scale = absxk;
            } else {
              t = absxk / c_scale;
              a += t * t;
            }
            absxk = std::abs(d1);
            if (absxk > b_scale) {
              t = b_scale / absxk;
              b = b * t * t + 1.0;
              b_scale = absxk;
            } else {
              t = absxk / b_scale;
              b += t * t;
            }
            absxk = std::abs(d3);
            if (absxk > scale) {
              t = scale / absxk;
              c = c * t * t + 1.0;
              scale = absxk;
            } else {
              t = absxk / scale;
              c += t * t;
            }
            d5 = pointList[(static_cast<int>(i_tmp_tmp) +
                            pointList.size(0) * 2) -
                           2];
            d6 = pointList[(static_cast<int>(i_tmp_tmp) +
                            pointList.size(0) * 2) -
                           3];
            d1 = d5 - d6;
            absxk = pointList[(static_cast<int>(i_tmp_tmp) +
                               pointList.size(0) * 2) -
                              1];
            d3 = absxk - d5;
            absxk = std::abs(absxk - d6);
            if (absxk > c_scale) {
              t = c_scale / absxk;
              a = a * t * t + 1.0;
              c_scale = absxk;
            } else {
              t = absxk / c_scale;
              a += t * t;
            }
            absxk = std::abs(d1);
            if (absxk > b_scale) {
              t = b_scale / absxk;
              b = b * t * t + 1.0;
              b_scale = absxk;
            } else {
              t = absxk / b_scale;
              b += t * t;
            }
            absxk = std::abs(d3);
            if (absxk > scale) {
              t = scale / absxk;
              c = c * t * t + 1.0;
              scale = absxk;
            } else {
              t = absxk / scale;
              c += t * t;
            }
            a = c_scale * std::sqrt(a);
            b = b_scale * std::sqrt(b);
            c = scale * std::sqrt(c);
            //  Calculer alpha 1 (loi de cos)
            //  radians
            //  Calculer R
            scale =
                R_Bar / std::tan(0.5 * std::acos(((-(a * a) + b * b) + c * c) /
                                                 (2.0 * b * c)));
            //  Verifier que le rayon n'est pas trop grand
            if ((scale < b) || (scale < c)) {
              //  Calculer les points tangeant au cercle de rayon.
              absxk = b - scale;
              c_idx_0 = c_idx_2 + c_idx_0 / b * absxk;
              s_idx_0 = s_idx_2 + s_idx_0 / c * scale;
              c_idx_1 = d4 + c_idx_1 / b * absxk;
              s_idx_1 = d2 + s_idx_1 / c * scale;
              c_idx_2 = d6 + d1 / b * absxk;
              s_idx_2 = d5 + d3 / c * scale;
              valid = true;
            } else {
              c_idx_0 = 0.0;
              s_idx_0 = 0.0;
              c_idx_1 = 0.0;
              s_idx_1 = 0.0;
              c_idx_2 = 0.0;
              s_idx_2 = 0.0;
              valid = false;
            }
            //  Si rayon negatif. copier le point 2 fois
          } else {
            c_idx_0 = pointList[static_cast<int>(i_tmp_tmp - 1.0) - 1];
            s_idx_0 = c_idx_0;
            c_idx_1 = pointList[(static_cast<int>(i_tmp_tmp - 1.0) +
                                 pointList.size(0)) -
                                1];
            s_idx_1 = c_idx_1;
            c_idx_2 = pointList[(static_cast<int>(i_tmp_tmp - 1.0) +
                                 pointList.size(0) * 2) -
                                1];
            s_idx_2 = c_idx_2;
            valid = true;
          }
          if (!valid) {
            status = -4.0;
            printf("INFO : proc planner : Circle radius is to large.\n");
            fflush(stdout);
            exitg1 = 1;
          } else {
            //  Decaler les waypoints
            R_Bar = pointList[(b_this + pointList.size(0)) - 1];
            absxk = pointList[(b_this + pointList.size(0) * 2) - 1];
            pointList[static_cast<int>(i_tmp_tmp + 1.0) - 1] =
                pointList[b_this - 1];
            pointList[(static_cast<int>(i_tmp_tmp + 1.0) + pointList.size(0)) -
                      1] = R_Bar;
            pointList[(static_cast<int>(i_tmp_tmp + 1.0) +
                       pointList.size(0) * 2) -
                      1] = absxk;
            pointList[b_this - 1] = s_idx_0;
            pointList[(b_this + pointList.size(0)) - 1] = s_idx_1;
            pointList[(b_this + pointList.size(0) * 2) - 1] = s_idx_2;
            c_this = static_cast<int>(
                ((static_cast<double>(i) + 1.0) + icOffset) - 1.0);
            pointList[c_this - 1] = c_idx_0;
            pointList[(c_this + pointList.size(0)) - 1] = c_idx_1;
            pointList[(c_this + pointList.size(0) * 2) - 1] = c_idx_2;
            q[1] = quatList[(b_this + quatList.size(0)) - 1];
            q[2] = quatList[(b_this + quatList.size(0) * 2) - 1];
            q[3] = quatList[(b_this + quatList.size(0) * 3) - 1];
            quatList[static_cast<int>(i_tmp_tmp + 1.0) - 1] =
                quatList[b_this - 1];
            quatList[(static_cast<int>(i_tmp_tmp + 1.0) + quatList.size(0)) -
                     1] = q[1];
            quatList[(static_cast<int>(i_tmp_tmp + 1.0) +
                      quatList.size(0) * 2) -
                     1] = q[2];
            quatList[(static_cast<int>(i_tmp_tmp + 1.0) +
                      quatList.size(0) * 3) -
                     1] = q[3];
            q[1] = quatList[(c_this + quatList.size(0)) - 1];
            q[2] = quatList[(c_this + quatList.size(0) * 2) - 1];
            q[3] = quatList[(c_this + quatList.size(0) * 3) - 1];
            quatList[b_this - 1] = quatList[c_this - 1];
            quatList[(b_this + quatList.size(0)) - 1] = q[1];
            quatList[(b_this + quatList.size(0) * 2) - 1] = q[2];
            quatList[(b_this + quatList.size(0) * 3) - 1] = q[3];
            q[1] = quatList[(static_cast<int>(i_tmp_tmp - 2.0) +
                             quatList.size(0)) -
                            1];
            q[2] = quatList[(static_cast<int>(i_tmp_tmp - 2.0) +
                             quatList.size(0) * 2) -
                            1];
            q[3] = quatList[(static_cast<int>(i_tmp_tmp - 2.0) +
                             quatList.size(0) * 3) -
                            1];
            quatList[c_this - 1] =
                quatList[static_cast<int>(
                             ((static_cast<double>(i) + 1.0) + icOffset) -
                             2.0) -
                         1];
            quatList[(c_this + quatList.size(0)) - 1] = q[1];
            quatList[(c_this + quatList.size(0) * 2) - 1] = q[2];
            quatList[(c_this + quatList.size(0) * 3) - 1] = q[3];
            speedList[static_cast<int>(
                          ((static_cast<double>(i) + 1.0) + icOffset) + 1.0) -
                      1] =
                speedList[static_cast<int>((static_cast<double>(i) + 1.0) +
                                           icOffset) -
                          1];
            speedList[static_cast<int>((static_cast<double>(i) + 1.0) +
                                       icOffset) -
                      1] =
                speedList[static_cast<int>(
                              ((static_cast<double>(i) + 1.0) + icOffset) -
                              1.0) -
                          1];
            courseList[static_cast<int>(
                           ((static_cast<double>(i) + 1.0) + icOffset) + 1.0) -
                       1] =
                courseList[static_cast<int>((static_cast<double>(i) + 1.0) +
                                            icOffset) -
                           1];
            courseList[static_cast<int>((static_cast<double>(i) + 1.0) +
                                        icOffset) -
                       1] =
                courseList[static_cast<int>(
                               ((static_cast<double>(i) + 1.0) + icOffset) -
                               1.0) -
                           1];
            courseList[static_cast<int>(
                           ((static_cast<double>(i) + 1.0) + icOffset) - 1.0) -
                       1] =
                courseList[static_cast<int>(
                               ((static_cast<double>(i) + 1.0) + icOffset) -
                               2.0) -
                           1];
            //  nouveau waypoint. augmente le offset
            icOffset++;
            i++;
          }
        } else {
          i++;
        }
      }
    } else {
      int b_this;
      int c_this;
      //  Copier le dernier waypoint 2 fois pour éviter un comportement
      //  du generateur de trajecteur
      b_this = pointList.size(0) - 2;
      c_this = pointList.size(0) - 1;
      pointList[c_this] = pointList[b_this];
      pointList[c_this + pointList.size(0)] =
          pointList[b_this + pointList.size(0)];
      pointList[c_this + pointList.size(0) * 2] =
          pointList[b_this + pointList.size(0) * 2];
      b_this = quatList.size(0) - 2;
      c_this = quatList.size(0) - 1;
      quatList[c_this] = quatList[b_this];
      quatList[c_this + quatList.size(0)] = quatList[b_this + quatList.size(0)];
      quatList[c_this + quatList.size(0) * 2] =
          quatList[b_this + quatList.size(0) * 2];
      quatList[c_this + quatList.size(0) * 3] =
          quatList[b_this + quatList.size(0) * 3];
      courseList[courseList.size(1) - 1] = courseList[courseList.size(1) - 2];
      speedList[speedList.size(1) - 1] = speedList[speedList.size(1) - 2];
      exitg1 = 1;
    }
  } while (exitg1 == 0);
}

//
// File trailer for TrajectoryGenerator.cpp
//
// [EOF]
//
