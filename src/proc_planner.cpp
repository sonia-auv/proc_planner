//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: proc_planner.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 09-Feb-2022 14:06:20
//

// Include Files
#include "proc_planner.h"
#include "ParameterTree.h"
#include "Publisher.h"
#include "Rate.h"
#include "Subscriber.h"
#include "TrajectoryGenerator.h"
#include "geometry_msgs_PoseStruct.h"
#include "geometry_msgs_TransformStruct.h"
#include "geometry_msgs_TwistStruct.h"
#include "isequaln.h"
#include "proc_planner_data.h"
#include "proc_planner_initialize.h"
#include "proc_planner_internal_types.h"
#include "proc_planner_types.h"
#include "quaternion.h"
#include "rt_nonfinite.h"
#include "sonia_common_AddPoseStruct.h"
#include "sonia_common_MultiAddPoseStruct.h"
#include "std_msgs_BoolStruct.h"
#include "trajectory_msgs_MultiDOFJointTrajectoryPointStruct.h"
#include "waypointTrajectory.h"
#include "coder_array.h"
#include "mlroscpp_param.h"
#include <cmath>
#include <functional>
#include <stdio.h>
#include <string.h>

// Function Definitions
//
// Si on roule en simulation
//
// Arguments    : void
// Return Type  : void
//
void proc_planner()
{
  TrajectoryGenerator TG;
  coder::b_quaternion varargout_2;
  coder::quaternion obj;
  coder::ros::ParameterTree lobj_9;
  coder::ros::Publisher trajpub;
  coder::ros::Rate r;
  coder::ros::Subscriber mapSub;
  coder::ros::b_Publisher validPub;
  coder::ros::b_Subscriber icSub;
  coder::ros::c_Publisher mapPub;
  coder::ros::d_Publisher icPub;
  coder::waypointTrajectory trajObj;
  coder::array<geometry_msgs_TransformStruct_T, 2U> y;
  coder::array<geometry_msgs_TwistStruct_T, 2U> b_y;
  coder::array<sonia_common_AddPoseStruct_T, 1U> Maddposemsg_Pose;
  coder::array<sonia_common_AddPoseStruct_T, 1U> t3_Pose;
  coder::array<double, 2U> c_TG;
  coder::array<double, 1U> b_TG;
  coder::array<char, 2U> in;
  coder::array<char, 2U> parameterName;
  geometry_msgs_PointStruct_T icMsg_Position;
  geometry_msgs_PointStruct_T t4_Position;
  geometry_msgs_PoseStruct_T emptyIcMsg;
  geometry_msgs_QuaternionStruct_T icMsg_Orientation;
  geometry_msgs_QuaternionStruct_T t4_Orientation;
  geometry_msgs_TransformStruct_T transformBuff;
  geometry_msgs_TwistStruct_T twistBuff;
  sonia_common_AddPoseStruct_T msg;
  sonia_common_MultiAddPoseStruct_T b_r;
  sonia_common_MultiAddPoseStruct_T emptyMAddPoseMsg;
  std_msgs_BoolStruct_T validMsg;
  trajectory_msgs_MultiDOFJointTrajectoryPointStruct_T trajMsg;
  double bufferVelocity[3];
  double varargout_3[3];
  double varargout_4[3];
  double varargout_5[3];
  double bufferQuat_idx_0;
  double bufferQuat_idx_1;
  double bufferQuat_idx_2;
  double bufferQuat_idx_3;
  double icMsg_Orientation_Y;
  double icMsg_Position_Y;
  double icMsg_Position_Z;
  double param_amax;
  double param_vamax;
  double param_vlmax;
  int i;
  int loop_ub;
  char Maddposemsg_MessageType[25];
  char t3_MessageType[25];
  char icMsg_MessageType[18];
  char t4_MessageType[18];
  bool nameExists;
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
  //  definir le node
  r.init();
  newMaddPose = false;
  newInitalPose = false;
  //  Definir les message ros
  sonia_common_MultiAddPoseStruct(&b_r);
  sonia_common_MultiAddPoseStruct(&emptyMAddPoseMsg);
  sonia_common_AddPoseStruct(&msg);
  emptyMAddPoseMsg.Pose.set_size(1);
  emptyMAddPoseMsg.Pose[0] = msg;
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
  //  Obtenir les rosparams
  lobj_9.ParameterHelper = MATLABROSParameter();
  UNUSED_PARAM(lobj_9.ParameterHelper);
  // ROSPARAM Construct an instance of this class
  //    Detailed explanation goes here
  coder::ros::ParameterTree::canonicalizeName(&lobj_9, in);
  parameterName.set_size(1, in.size(1) + 1);
  loop_ub = in.size(1);
  for (i = 0; i < loop_ub; i++) {
    parameterName[i] = in[i];
  }
  parameterName[in.size(1)] = '\x00';
  nameExists = std::mem_fn(&MATLABROSParameter::hasParam)(
      lobj_9.ParameterHelper, &parameterName[0]);
  if (nameExists) {
    coder::ros::ParameterTree::canonicalizeName(&lobj_9, in);
    parameterName.set_size(1, in.size(1) + 1);
    loop_ub = in.size(1);
    for (i = 0; i < loop_ub; i++) {
      parameterName[i] = in[i];
    }
    parameterName[in.size(1)] = '\x00';
    param_amax = 0.0;
    std::mem_fn (&MATLABROSParameter::getParameter<double>)(
        &lobj_9.ParameterHelper, &parameterName[0], &param_amax);
  } else {
    param_amax = 0.1;
  }
  coder::ros::ParameterTree::b_canonicalizeName(&lobj_9, in);
  parameterName.set_size(1, in.size(1) + 1);
  loop_ub = in.size(1);
  for (i = 0; i < loop_ub; i++) {
    parameterName[i] = in[i];
  }
  parameterName[in.size(1)] = '\x00';
  nameExists = std::mem_fn(&MATLABROSParameter::hasParam)(
      lobj_9.ParameterHelper, &parameterName[0]);
  if (nameExists) {
    coder::ros::ParameterTree::b_canonicalizeName(&lobj_9, in);
    parameterName.set_size(1, in.size(1) + 1);
    loop_ub = in.size(1);
    for (i = 0; i < loop_ub; i++) {
      parameterName[i] = in[i];
    }
    parameterName[in.size(1)] = '\x00';
    param_vlmax = 0.0;
    std::mem_fn (&MATLABROSParameter::getParameter<double>)(
        &lobj_9.ParameterHelper, &parameterName[0], &param_vlmax);
  } else {
    param_vlmax = 0.5;
  }
  coder::ros::ParameterTree::c_canonicalizeName(&lobj_9, in);
  parameterName.set_size(1, in.size(1) + 1);
  loop_ub = in.size(1);
  for (i = 0; i < loop_ub; i++) {
    parameterName[i] = in[i];
  }
  parameterName[in.size(1)] = '\x00';
  nameExists = std::mem_fn(&MATLABROSParameter::hasParam)(
      lobj_9.ParameterHelper, &parameterName[0]);
  if (nameExists) {
    coder::ros::ParameterTree::c_canonicalizeName(&lobj_9, in);
    parameterName.set_size(1, in.size(1) + 1);
    loop_ub = in.size(1);
    for (i = 0; i < loop_ub; i++) {
      parameterName[i] = in[i];
    }
    parameterName[in.size(1)] = '\x00';
    param_vamax = 0.0;
    std::mem_fn (&MATLABROSParameter::getParameter<double>)(
        &lobj_9.ParameterHelper, &parameterName[0], &param_vamax);
  } else {
    param_vamax = 0.78539816339744828;
  }
  printf("INFO : proc planner : Maximum acceleration is %f m/s^2. \n",
         param_amax);
  fflush(stdout);
  printf("INFO : proc planner : Maximum velocity is %f m/s. \n", param_vlmax);
  fflush(stdout);
  printf("INFO : proc planner : Maximum angular rate is %f rad/s. \n",
         param_vamax);
  fflush(stdout);
  //  Initialiser les topics
  mapSub.get_LatestMessage(Maddposemsg_MessageType, Maddposemsg_Pose);
  icSub.get_LatestMessage(icMsg_MessageType, &icMsg_Position,
                          &icMsg_Orientation);
  bufferQuat_idx_0 = icMsg_Orientation.X;
  icMsg_Orientation_Y = icMsg_Orientation.Y;
  bufferQuat_idx_1 = icMsg_Orientation.Z;
  bufferQuat_idx_2 = icMsg_Orientation.W;
  bufferQuat_idx_3 = icMsg_Position.X;
  icMsg_Position_Y = icMsg_Position.Y;
  icMsg_Position_Z = icMsg_Position.Z;
  printf("INFO : proc planner : Node is started \n");
  fflush(stdout);
  printf("INFO : proc planner : Wait for poses \n");
  fflush(stdout);
  r.reset();
  while (1) {
    // [ rMaddposemsg,status] = receive(mapSub,0.2);
    //  Si Recois un nouveau message MultiaddPose
    mapSub.get_LatestMessage(t3_MessageType, t3_Pose);
    if (!coder::isequaln(Maddposemsg_MessageType, Maddposemsg_Pose,
                         t3_MessageType, t3_Pose)) {
      mapSub.get_LatestMessage(Maddposemsg_MessageType, Maddposemsg_Pose);
      newMaddPose = true;
      printf("INFO : proc planner : Poses received \n");
      fflush(stdout);
      printf("INFO : proc planner : Wait for initial pose \n");
      fflush(stdout);
    }
    //  Si Recois un nouveau message initial waypoint
    icSub.get_LatestMessage(t4_MessageType, &t4_Position, &t4_Orientation);
    if ((!coder::isequaln(
            icMsg_MessageType, icMsg_Position.MessageType, bufferQuat_idx_3,
            icMsg_Position_Y, icMsg_Position_Z, icMsg_Orientation.MessageType,
            bufferQuat_idx_0, icMsg_Orientation_Y, bufferQuat_idx_1,
            bufferQuat_idx_2, t4_MessageType, t4_Position, t4_Orientation)) &&
        newMaddPose) {
      icSub.get_LatestMessage(icMsg_MessageType, &t4_Position, &t4_Orientation);
      for (i = 0; i < 24; i++) {
        icMsg_Orientation.MessageType[i] = t4_Orientation.MessageType[i];
      }
      bufferQuat_idx_0 = t4_Orientation.X;
      icMsg_Orientation_Y = t4_Orientation.Y;
      bufferQuat_idx_1 = t4_Orientation.Z;
      bufferQuat_idx_2 = t4_Orientation.W;
      for (i = 0; i < 19; i++) {
        icMsg_Position.MessageType[i] = t4_Position.MessageType[i];
      }
      bufferQuat_idx_3 = t4_Position.X;
      icMsg_Position_Y = t4_Position.Y;
      icMsg_Position_Z = t4_Position.Z;
      newInitalPose = true;
      printf("INFO : proc planner : Initial poses received \n");
      fflush(stdout);
    }
    //  [icMsg,status] = receive(icSub);
    if (newMaddPose && newInitalPose) {
      //  Cree l'objet trajectoire
      TG.init(Maddposemsg_MessageType, Maddposemsg_Pose, param_amax,
              param_vlmax, param_vamax, bufferQuat_idx_3, icMsg_Position_Y,
              icMsg_Position_Z, bufferQuat_idx_0, icMsg_Orientation_Y,
              bufferQuat_idx_1, bufferQuat_idx_2);
      //  Envoyer a ros si le mAddpose est valide
      validMsg.Data = TG.status;
      validPub.send(validMsg);
      //  Si la trajectoire est valide
      if (TG.status) {
        double lastQuat_idx_0;
        double lastQuat_idx_1;
        double lastQuat_idx_2;
        double lastQuat_idx_3;
        short validatedHoleFilling_idx_0;
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
          int b_loop_ub;
          loop_ub = TG.quatList.size(0);
          b_loop_ub = TG.quatList.size(0);
          b_TG.set_size(b_loop_ub);
          for (i = 0; i < b_loop_ub; i++) {
            b_TG[i] = TG.quatList[i];
          }
          obj.a.set_size(loop_ub, 1);
          for (i = 0; i < loop_ub; i++) {
            obj.a[i] = b_TG[i];
          }
          loop_ub = TG.quatList.size(0);
          b_loop_ub = TG.quatList.size(0);
          b_TG.set_size(b_loop_ub);
          for (i = 0; i < b_loop_ub; i++) {
            b_TG[i] = TG.quatList[i + TG.quatList.size(0)];
          }
          obj.b.set_size(loop_ub, 1);
          for (i = 0; i < loop_ub; i++) {
            obj.b[i] = b_TG[i];
          }
          loop_ub = TG.quatList.size(0);
          b_loop_ub = TG.quatList.size(0);
          b_TG.set_size(b_loop_ub);
          for (i = 0; i < b_loop_ub; i++) {
            b_TG[i] = TG.quatList[i + TG.quatList.size(0) * 2];
          }
          obj.c.set_size(loop_ub, 1);
          for (i = 0; i < loop_ub; i++) {
            obj.c[i] = b_TG[i];
          }
          loop_ub = TG.quatList.size(0);
          b_loop_ub = TG.quatList.size(0);
          b_TG.set_size(b_loop_ub);
          for (i = 0; i < b_loop_ub; i++) {
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
        bufferQuat_idx_0 = TG.nbPoint;
        i = static_cast<int>(bufferQuat_idx_0);
        y.set_size(1, i);
        for (loop_ub = 0; loop_ub < i; loop_ub++) {
          y[loop_ub] = transformBuff;
        }
        trajMsg.Transforms.set_size(y.size(1));
        loop_ub = y.size(1);
        for (i = 0; i < loop_ub; i++) {
          trajMsg.Transforms[i] = y[i];
        }
        bufferQuat_idx_0 = TG.nbPoint;
        i = static_cast<int>(bufferQuat_idx_0);
        b_y.set_size(1, i);
        for (loop_ub = 0; loop_ub < i; loop_ub++) {
          b_y[loop_ub] = twistBuff;
        }
        trajMsg.Velocities.set_size(b_y.size(1));
        loop_ub = b_y.size(1);
        for (i = 0; i < loop_ub; i++) {
          trajMsg.Velocities[i] = b_y[i];
        }
        bufferQuat_idx_0 = TG.nbPoint;
        i = static_cast<int>(bufferQuat_idx_0);
        b_y.set_size(1, i);
        for (loop_ub = 0; loop_ub < i; loop_ub++) {
          b_y[loop_ub] = twistBuff;
        }
        trajMsg.Accelerations.set_size(b_y.size(1));
        loop_ub = b_y.size(1);
        for (i = 0; i < loop_ub; i++) {
          trajMsg.Accelerations[i] = b_y[i];
        }
        lastQuat_idx_0 = 0.0;
        lastQuat_idx_1 = 0.0;
        lastQuat_idx_2 = 0.0;
        lastQuat_idx_3 = 0.0;
        //  Générer les points de la trajectoire
        bufferQuat_idx_0 = TG.nbPoint;
        i = static_cast<int>(bufferQuat_idx_0);
        for (loop_ub = 0; loop_ub < i; loop_ub++) {
          trajObj.step(bufferVelocity, &varargout_2, varargout_3, varargout_4,
                       varargout_5);
          //  Remplire le message Transform.
          transformBuff.Translation.X = bufferVelocity[0];
          transformBuff.Translation.Y = bufferVelocity[1];
          transformBuff.Translation.Z = bufferVelocity[2];
          //  Convertir l'objet quaternion en vecteur
          bufferQuat_idx_0 = varargout_2.a;
          bufferQuat_idx_1 = varargout_2.b;
          bufferQuat_idx_2 = varargout_2.c;
          bufferQuat_idx_3 = varargout_2.d;
          //  Verifier de retourner la rotation la plus petite
          if ((loop_ub + 1U > 1U) && (((lastQuat_idx_0 * varargout_2.a +
                                        lastQuat_idx_1 * varargout_2.b) +
                                       lastQuat_idx_2 * varargout_2.c) +
                                          lastQuat_idx_3 * varargout_2.d <
                                      0.0)) {
            bufferQuat_idx_0 = -varargout_2.a;
            bufferQuat_idx_1 = -varargout_2.b;
            bufferQuat_idx_2 = -varargout_2.c;
            bufferQuat_idx_3 = -varargout_2.d;
          }
          lastQuat_idx_0 = bufferQuat_idx_0;
          lastQuat_idx_1 = bufferQuat_idx_1;
          lastQuat_idx_2 = bufferQuat_idx_2;
          lastQuat_idx_3 = bufferQuat_idx_3;
          transformBuff.Rotation.W = bufferQuat_idx_0;
          transformBuff.Rotation.X = bufferQuat_idx_1;
          transformBuff.Rotation.Y = bufferQuat_idx_2;
          transformBuff.Rotation.Z = bufferQuat_idx_3;
          trajMsg.Transforms[loop_ub] = transformBuff;
          //  Convertir les vitesse dans le ref sub
          // =================================================================
          //  Fonction qui tourne un vecteur selon un quaternion.
          //  quaternion partie scalaire
          //  quaternion partie vectoriel
          //  QuatRotate n'est pas compilable
          icMsg_Position_Y = 2.0 * ((varargout_3[0] * bufferQuat_idx_1 +
                                     varargout_3[1] * bufferQuat_idx_2) +
                                    varargout_3[2] * bufferQuat_idx_3);
          icMsg_Position_Z = bufferQuat_idx_0 * bufferQuat_idx_0 -
                             ((bufferQuat_idx_1 * bufferQuat_idx_1 +
                               bufferQuat_idx_2 * bufferQuat_idx_2) +
                              bufferQuat_idx_3 * bufferQuat_idx_3);
          icMsg_Orientation_Y = 2.0 * bufferQuat_idx_0;
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
              (icMsg_Position_Y * bufferQuat_idx_1 +
               icMsg_Position_Z * varargout_3[0]) +
              icMsg_Orientation_Y * (bufferQuat_idx_2 * varargout_3[2] -
                                     varargout_3[1] * bufferQuat_idx_3);
          twistBuff.Linear.Y =
              (icMsg_Position_Y * bufferQuat_idx_2 +
               icMsg_Position_Z * varargout_3[1]) +
              icMsg_Orientation_Y * (varargout_3[0] * bufferQuat_idx_3 -
                                     bufferQuat_idx_1 * varargout_3[2]);
          twistBuff.Linear.Z =
              (icMsg_Position_Y * bufferQuat_idx_3 +
               icMsg_Position_Z * varargout_3[2]) +
              icMsg_Orientation_Y * (bufferQuat_idx_1 * varargout_3[1] -
                                     varargout_3[0] * bufferQuat_idx_2);
          trajMsg.Velocities[loop_ub] = twistBuff;
          icMsg_Position_Y = 2.0 * ((varargout_4[0] * bufferQuat_idx_1 +
                                     varargout_4[1] * bufferQuat_idx_2) +
                                    varargout_4[2] * bufferQuat_idx_3);
          //  Remplire les acceleration
          twistBuff.Linear.X =
              (icMsg_Position_Y * bufferQuat_idx_1 +
               icMsg_Position_Z * varargout_4[0]) +
              icMsg_Orientation_Y * (bufferQuat_idx_2 * varargout_4[2] -
                                     varargout_4[1] * bufferQuat_idx_3);
          twistBuff.Linear.Y =
              (icMsg_Position_Y * bufferQuat_idx_2 +
               icMsg_Position_Z * varargout_4[1]) +
              icMsg_Orientation_Y * (varargout_4[0] * bufferQuat_idx_3 -
                                     bufferQuat_idx_1 * varargout_4[2]);
          twistBuff.Linear.Z =
              (icMsg_Position_Y * bufferQuat_idx_3 +
               icMsg_Position_Z * varargout_4[2]) +
              icMsg_Orientation_Y * (bufferQuat_idx_1 * varargout_4[1] -
                                     varargout_4[0] * bufferQuat_idx_2);
          twistBuff.Angular.X = 0.0;
          twistBuff.Angular.Y = 0.0;
          twistBuff.Angular.Z = 0.0;
          trajMsg.Accelerations[loop_ub] = twistBuff;
        }
        //  Envoyer le message
        trajpub.send(&trajMsg);
        bufferQuat_idx_0 = std::round(TG.nbPoint);
        if (bufferQuat_idx_0 < 32768.0) {
          if (bufferQuat_idx_0 >= -32768.0) {
            validatedHoleFilling_idx_0 = static_cast<short>(bufferQuat_idx_0);
          } else {
            validatedHoleFilling_idx_0 = MIN_int16_T;
          }
        } else if (bufferQuat_idx_0 >= 32768.0) {
          validatedHoleFilling_idx_0 = MAX_int16_T;
        } else {
          validatedHoleFilling_idx_0 = 0;
        }
        printf("INFO : proc planner : Trajectory generation succeded with %d "
               "points. \n",
               validatedHoleFilling_idx_0);
        fflush(stdout);
        //  Si on roule en simulation
        //  Retourner true (sucess)
      }
      for (i = 0; i < 25; i++) {
        Maddposemsg_MessageType[i] = emptyMAddPoseMsg.MessageType[i];
      }
      Maddposemsg_Pose.set_size(1);
      Maddposemsg_Pose[0] = emptyMAddPoseMsg.Pose[0];
      for (i = 0; i < 18; i++) {
        icMsg_MessageType[i] = emptyIcMsg.MessageType[i];
      }
      for (i = 0; i < 19; i++) {
        icMsg_Position.MessageType[i] = emptyIcMsg.Position.MessageType[i];
      }
      bufferQuat_idx_3 = emptyIcMsg.Position.X;
      icMsg_Position_Y = emptyIcMsg.Position.Y;
      icMsg_Position_Z = emptyIcMsg.Position.Z;
      for (i = 0; i < 24; i++) {
        icMsg_Orientation.MessageType[i] =
            emptyIcMsg.Orientation.MessageType[i];
      }
      bufferQuat_idx_0 = emptyIcMsg.Orientation.X;
      icMsg_Orientation_Y = emptyIcMsg.Orientation.Y;
      bufferQuat_idx_1 = emptyIcMsg.Orientation.Z;
      bufferQuat_idx_2 = emptyIcMsg.Orientation.W;
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
