//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: TrajectoryGenerator.cpp
//
// MATLAB Coder version            : 5.4
// C/C++ source code generated on  : 12-May-2022 22:37:14
//

// Include Files
#include "TrajectoryGenerator.h"
#include "Publisher.h"
#include "colon.h"
#include "diff.h"
#include "dot.h"
#include "geometry_msgs_TransformStruct.h"
#include "geometry_msgs_TwistStruct.h"
#include "interp1.h"
#include "minOrMax.h"
#include "mod.h"
#include "norm.h"
#include "pinv.h"
#include "proc_planner_rtwutil.h"
#include "proc_planner_types.h"
#include "quat2eul.h"
#include "quatmultiply.h"
#include "rt_nonfinite.h"
#include "trajectory_msgs_MultiDOFJointTrajectoryPointStruct.h"
#include "coder_array.h"
#include "mlroscpp_pub.h"
#include <cmath>
#include <stdio.h>

// Function Definitions
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
// Initialise l'objet trajectoire et vérifie si le message multi add pose est
// valide.
//
// Arguments    : const char multiAddposeMsg_MessageType[25]
//                unsigned char multiAddposeMsg_InterpolationMethod
//                const coder::array<sonia_common_AddPoseStruct_T, 1U>
//                &multiAddposeMsg_Pose double param_lowSpeed_amax double
//                param_lowSpeed_vlmax double param_lowSpeed_vamax double
//                param_normalSpeed_amax double param_normalSpeed_vlmax double
//                param_normalSpeed_vamax double param_highSpeed_amax double
//                param_highSpeed_vlmax double param_highSpeed_vamax const
//                geometry_msgs_PointStruct_T icMsg_Position const
//                geometry_msgs_QuaternionStruct_T icMsg_Orientation
// Return Type  : TrajectoryGenerator *
//
TrajectoryGenerator *TrajectoryGenerator::init(
    const char multiAddposeMsg_MessageType[25],
    unsigned char multiAddposeMsg_InterpolationMethod,
    const coder::array<sonia_common_AddPoseStruct_T, 1U> &multiAddposeMsg_Pose,
    double param_lowSpeed_amax, double param_lowSpeed_vlmax,
    double param_lowSpeed_vamax, double param_normalSpeed_amax,
    double param_normalSpeed_vlmax, double param_normalSpeed_vamax,
    double param_highSpeed_amax, double param_highSpeed_vlmax,
    double param_highSpeed_vamax,
    const geometry_msgs_PointStruct_T icMsg_Position,
    const geometry_msgs_QuaternionStruct_T icMsg_Orientation)
{
  TrajectoryGenerator *this_;
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
  if (multiAddposeMsg_Pose.size(0) < 1) {
    this_->nMAPM = 1.0;
  } else {
    this_->nMAPM = multiAddposeMsg_Pose.size(0);
  }
  //  matlab and cpp dont use same index. return max instead
  //  Initialiser les parametres
  this_->param.ts = 0.1;
  this_->param.lowSpeed.amax = param_lowSpeed_amax;
  this_->param.lowSpeed.vlmax = param_lowSpeed_vlmax;
  this_->param.lowSpeed.vamax = param_lowSpeed_vamax;
  this_->param.normalSpeed.amax = param_normalSpeed_amax;
  this_->param.normalSpeed.vlmax = param_normalSpeed_vlmax;
  this_->param.normalSpeed.vamax = param_normalSpeed_vamax;
  this_->param.highSpeed.amax = param_highSpeed_amax;
  this_->param.highSpeed.vlmax = param_highSpeed_vlmax;
  this_->param.highSpeed.vamax = param_highSpeed_vamax;
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
      double s_idx_0;
      double s_idx_1;
      double s_idx_2;
      //  pour chaques AddPose
      //  transformer les angle d'euler quaternions
      s_idx_0 = this_->MAPM.Pose[i].Orientation.Z;
      s_idx_1 = this_->MAPM.Pose[i].Orientation.Y;
      s_idx_2 = this_->MAPM.Pose[i].Orientation.X;
      b_d = 0.017453292519943295 * s_idx_0 / 2.0;
      eul[0] = std::cos(b_d);
      b_d = std::sin(b_d);
      s_idx_0 = b_d;
      b_d = 0.017453292519943295 * s_idx_1 / 2.0;
      eul[1] = std::cos(b_d);
      b_d = std::sin(b_d);
      s_idx_1 = b_d;
      b_d = 0.017453292519943295 * s_idx_2 / 2.0;
      eul[2] = std::cos(b_d);
      b_d = std::sin(b_d);
      suppPoint = eul[0] * eul[1];
      R_Bar = s_idx_0 * s_idx_1;
      q[0] = suppPoint * eul[2] + R_Bar * b_d;
      q[1] = suppPoint * b_d - R_Bar * eul[2];
      suppPoint = s_idx_0 * eul[1];
      R_Bar = eul[0] * s_idx_1;
      q[2] = R_Bar * eul[2] + suppPoint * b_d;
      q[3] = suppPoint * eul[2] - R_Bar * b_d;
      //  cree le vecteur pose
      eul[0] = this_->MAPM.Pose[i].Position.X;
      eul[1] = this_->MAPM.Pose[i].Position.Y;
      eul[2] = this_->MAPM.Pose[i].Position.Z;
      //  transformer le point en fonction du frame
      guard1 = false;
      switch (this_->MAPM.Pose[i].Frame) {
      case 0U:
        //  position et angle absolue
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
        b_d = 2.0 * coder::dot(*(double(*)[3]) & q[1], eul);
        suppPoint = q[0] * q[0] -
                    coder::dot(*(double(*)[3]) & q[1], *(double(*)[3]) & q[1]);
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
        b_d = 2.0 * coder::dot(*(double(*)[3]) & q[1], eul);
        suppPoint = q[0] * q[0] -
                    coder::dot(*(double(*)[3]) & q[1], *(double(*)[3]) & q[1]);
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
            s_idx_0 = this_->pointList[static_cast<int>(suppPoint - 1.0) - 1];
            s_idx_1 = this_->pointList[(static_cast<int>(suppPoint - 1.0) +
                                        this_->pointList.size(0)) -
                                       1];
            s_idx_2 = this_->pointList[(static_cast<int>(suppPoint - 1.0) +
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
            v01[0] = s_idx_0 - eul[0];
            v12[0] = P2[0] - s_idx_0;
            P2[0] -= eul[0];
            v01[1] = s_idx_1 - eul[1];
            v12[1] = P2[1] - s_idx_1;
            P2[1] -= eul[1];
            v01[2] = s_idx_2 - eul[2];
            v12[2] = P2[2] - s_idx_2;
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
              s_idx_0 += v12[0] / c * suppPoint;
              eul[1] += v01[1] / b * R_Bar;
              s_idx_1 += v12[1] / c * suppPoint;
              eul[2] += v01[2] / b * R_Bar;
              s_idx_2 += v12[2] / c * suppPoint;
              valid = true;
            } else {
              eul[0] = 0.0;
              s_idx_0 = 0.0;
              eul[1] = 0.0;
              s_idx_1 = 0.0;
              eul[2] = 0.0;
              s_idx_2 = 0.0;
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
            s_idx_0 = this_->pointList[static_cast<int>(suppPoint - 1.0) - 1];
            s_idx_1 = this_->pointList[(static_cast<int>(suppPoint - 1.0) +
                                        this_->pointList.size(0)) -
                                       1];
            s_idx_2 = this_->pointList[(static_cast<int>(suppPoint - 1.0) +
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
            this_->pointList[loop_ub - 1] = s_idx_0;
            this_->pointList[(loop_ub + this_->pointList.size(0)) - 1] =
                s_idx_1;
            this_->pointList[(loop_ub + this_->pointList.size(0) * 2) - 1] =
                s_idx_2;
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
          b_d = coder::b_norm(*(double(*)[3]) & qRel[1]);
          eul[0] = c;
          eul[1] = 2.0 * rt_atan2d_snf(b_d, qRel[0]) / b;
          eul[2] = this_->param.ts;
          suppPoint = coder::internal::maximum(eul);
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
