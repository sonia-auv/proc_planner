//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// proc_planner.cpp
//
// Code generation for function 'proc_planner'
//

// Include files
#include "proc_planner.h"
#include "ParameterTree.h"
#include "Publisher.h"
#include "Rate.h"
#include "Subscriber.h"
#include "TrajectoryGenerator.h"
#include "getenv.h"
#include "minOrMax.h"
#include "mod.h"
#include "norm.h"
#include "proc_planner_data.h"
#include "proc_planner_initialize.h"
#include "proc_planner_internal_types.h"
#include "proc_planner_rtwutil.h"
#include "proc_planner_types.h"
#include "quat2eul.h"
#include "quatmultiply.h"
#include "ros_node.h"
#include "rt_nonfinite.h"
#include "std_msgs_Int8Struct.h"
#include "tic.h"
#include "toc.h"
#include "coder_array.h"
#include "coder_posix_time.h"
#include "mlroscpp_param.h"
#include "mlroscpp_pub.h"
#include "mlroscpp_rate.h"
#include <cmath>
#include <functional>
#include <stdio.h>

// Function Definitions
void proc_planner()
{
  TrajectoryGenerator TG;
  coder::ros::ParameterTree lobj_1;
  coder::ros::Publisher *pub;
  coder::ros::Rate r;
  coder::ros::Subscriber *sub;
  coder::ros::b_Publisher *b_pub;
  coder::ros::b_Subscriber *b_sub;
  coder::ros::c_Subscriber *c_sub;
  ros_node planner;
  coder::array<double, 1U> d_TG;
  coder::array<char, 2U> formatSpec;
  coder::array<char, 2U> parameterName;
  std_msgs_Int8Struct_T validMsg;
  double d;
  double icMsg_Orientation_W;
  double icMsg_Orientation_Z;
  double tl;
  double val;
  double vamax;
  double vlmax;
  int i;
  int loop_ub;
  unsigned char multiAddposeMsg_InterpolationMethod;
  bool nameExists;
  if (!isInitialized_proc_planner) {
    proc_planner_initialize();
  }
  //  Si on roule en simulation
  coder::b_getenv(formatSpec);
  parameterName.set_size(1, formatSpec.size(1) + 1);
  loop_ub = formatSpec.size(1);
  for (i = 0; i < loop_ub; i++) {
    parameterName[i] = formatSpec[i];
  }
  parameterName[formatSpec.size(1)] = '\x00';
  printf("INFO : proc planner : Load config for %s \n", &parameterName[0]);
  fflush(stdout);
  //  Variables locals
  r.init();
  //  Démarer le planner
  planner.TrajIsGenerating = false;
  //  Constructor
  //  Definir les Subscrier ros
  sub = planner._pobj4.init();
  planner.madpSub = sub;
  b_sub = planner._pobj3.init();
  planner.icSub = b_sub;
  c_sub = planner._pobj2.init();
  planner.obstacleSub = c_sub;
  //  Definir les publisher ROS
  pub = planner._pobj1.init();
  planner.trajpub = pub;
  b_pub = planner._pobj0.init();
  planner.validPub = b_pub;
  //  Get ros param
  //  Get rosparam
  TG.param.ts = 0.1;
  lobj_1.ParameterHelper = MATLABROSParameter();
  UNUSED_PARAM(lobj_1.ParameterHelper);
  // ROSPARAM Construct an instance of this class
  //    Detailed explanation goes here
  //         %% get rosparam number
  coder::ros::ParameterTree::canonicalizeName(&lobj_1, formatSpec);
  parameterName.set_size(1, formatSpec.size(1) + 1);
  loop_ub = formatSpec.size(1);
  for (i = 0; i < loop_ub; i++) {
    parameterName[i] = formatSpec[i];
  }
  parameterName[formatSpec.size(1)] = '\x00';
  nameExists = std::mem_fn(&MATLABROSParameter::hasParam)(
      lobj_1.ParameterHelper, &parameterName[0]);
  if (nameExists) {
    val = lobj_1.get();
    TG.param.lowSpeed.amax = val;
    printf("%s : %f \n", "/proc_planner/low_speed/maximum_acceleration", val);
    fflush(stdout);
  } else {
    TG.param.lowSpeed.amax = 0.05;
  }
  //         %% get rosparam number
  coder::ros::ParameterTree::b_canonicalizeName(&lobj_1, formatSpec);
  parameterName.set_size(1, formatSpec.size(1) + 1);
  loop_ub = formatSpec.size(1);
  for (i = 0; i < loop_ub; i++) {
    parameterName[i] = formatSpec[i];
  }
  parameterName[formatSpec.size(1)] = '\x00';
  nameExists = std::mem_fn(&MATLABROSParameter::hasParam)(
      lobj_1.ParameterHelper, &parameterName[0]);
  if (nameExists) {
    val = lobj_1.b_get();
    TG.param.lowSpeed.vlmax = val;
    printf("%s : %f \n", "/proc_planner/low_speed/maximum_velocity", val);
    fflush(stdout);
  } else {
    TG.param.lowSpeed.vlmax = 0.2;
  }
  //         %% get rosparam number
  coder::ros::ParameterTree::c_canonicalizeName(&lobj_1, formatSpec);
  parameterName.set_size(1, formatSpec.size(1) + 1);
  loop_ub = formatSpec.size(1);
  for (i = 0; i < loop_ub; i++) {
    parameterName[i] = formatSpec[i];
  }
  parameterName[formatSpec.size(1)] = '\x00';
  nameExists = std::mem_fn(&MATLABROSParameter::hasParam)(
      lobj_1.ParameterHelper, &parameterName[0]);
  if (nameExists) {
    val = lobj_1.c_get();
    TG.param.lowSpeed.vamax = val;
    printf("%s : %f \n", "/proc_planner/low_speed/maximum_angular_rate", val);
    fflush(stdout);
  } else {
    TG.param.lowSpeed.vamax = 0.3;
  }
  //         %% get rosparam number
  coder::ros::ParameterTree::d_canonicalizeName(&lobj_1, formatSpec);
  parameterName.set_size(1, formatSpec.size(1) + 1);
  loop_ub = formatSpec.size(1);
  for (i = 0; i < loop_ub; i++) {
    parameterName[i] = formatSpec[i];
  }
  parameterName[formatSpec.size(1)] = '\x00';
  nameExists = std::mem_fn(&MATLABROSParameter::hasParam)(
      lobj_1.ParameterHelper, &parameterName[0]);
  if (nameExists) {
    val = lobj_1.d_get();
    TG.param.normalSpeed.amax = val;
    printf("%s : %f \n", "/proc_planner/normal_speed/maximum_acceleration",
           val);
    fflush(stdout);
  } else {
    TG.param.normalSpeed.amax = 0.1;
  }
  //         %% get rosparam number
  coder::ros::ParameterTree::e_canonicalizeName(&lobj_1, formatSpec);
  parameterName.set_size(1, formatSpec.size(1) + 1);
  loop_ub = formatSpec.size(1);
  for (i = 0; i < loop_ub; i++) {
    parameterName[i] = formatSpec[i];
  }
  parameterName[formatSpec.size(1)] = '\x00';
  nameExists = std::mem_fn(&MATLABROSParameter::hasParam)(
      lobj_1.ParameterHelper, &parameterName[0]);
  if (nameExists) {
    val = lobj_1.e_get();
    TG.param.normalSpeed.vlmax = val;
    printf("%s : %f \n", "/proc_planner/normal_speed/maximum_velocity", val);
    fflush(stdout);
  } else {
    TG.param.normalSpeed.vlmax = 0.5;
  }
  //         %% get rosparam number
  coder::ros::ParameterTree::f_canonicalizeName(&lobj_1, formatSpec);
  parameterName.set_size(1, formatSpec.size(1) + 1);
  loop_ub = formatSpec.size(1);
  for (i = 0; i < loop_ub; i++) {
    parameterName[i] = formatSpec[i];
  }
  parameterName[formatSpec.size(1)] = '\x00';
  nameExists = std::mem_fn(&MATLABROSParameter::hasParam)(
      lobj_1.ParameterHelper, &parameterName[0]);
  if (nameExists) {
    val = lobj_1.f_get();
    TG.param.normalSpeed.vamax = val;
    printf("%s : %f \n", "/proc_planner/normal_speed/maximum_angular_rate",
           val);
    fflush(stdout);
  } else {
    TG.param.normalSpeed.vamax = 0.5;
  }
  //         %% get rosparam number
  coder::ros::ParameterTree::g_canonicalizeName(&lobj_1, formatSpec);
  parameterName.set_size(1, formatSpec.size(1) + 1);
  loop_ub = formatSpec.size(1);
  for (i = 0; i < loop_ub; i++) {
    parameterName[i] = formatSpec[i];
  }
  parameterName[formatSpec.size(1)] = '\x00';
  nameExists = std::mem_fn(&MATLABROSParameter::hasParam)(
      lobj_1.ParameterHelper, &parameterName[0]);
  if (nameExists) {
    val = lobj_1.g_get();
    TG.param.highSpeed.amax = val;
    printf("%s : %f \n", "/proc_planner/high_speed/maximum_acceleration", val);
    fflush(stdout);
  } else {
    TG.param.highSpeed.amax = 0.15;
  }
  //         %% get rosparam number
  coder::ros::ParameterTree::h_canonicalizeName(&lobj_1, formatSpec);
  parameterName.set_size(1, formatSpec.size(1) + 1);
  loop_ub = formatSpec.size(1);
  for (i = 0; i < loop_ub; i++) {
    parameterName[i] = formatSpec[i];
  }
  parameterName[formatSpec.size(1)] = '\x00';
  nameExists = std::mem_fn(&MATLABROSParameter::hasParam)(
      lobj_1.ParameterHelper, &parameterName[0]);
  if (nameExists) {
    val = lobj_1.h_get();
    TG.param.highSpeed.vlmax = val;
    printf("%s : %f \n", "/proc_planner/high_speed/maximum_velocity", val);
    fflush(stdout);
  } else {
    TG.param.highSpeed.vlmax = 0.8;
  }
  //         %% get rosparam number
  coder::ros::ParameterTree::i_canonicalizeName(&lobj_1, formatSpec);
  parameterName.set_size(1, formatSpec.size(1) + 1);
  loop_ub = formatSpec.size(1);
  for (i = 0; i < loop_ub; i++) {
    parameterName[i] = formatSpec[i];
  }
  parameterName[formatSpec.size(1)] = '\x00';
  nameExists = std::mem_fn(&MATLABROSParameter::hasParam)(
      lobj_1.ParameterHelper, &parameterName[0]);
  if (nameExists) {
    val = lobj_1.i_get();
    TG.param.highSpeed.vamax = val;
    printf("%s : %f \n", "/proc_planner/high_speed/maximum_angular_rate", val);
    fflush(stdout);
  } else {
    TG.param.highSpeed.vamax = 0.8;
  }
  //         %% get rosparam number
  coder::ros::ParameterTree::j_canonicalizeName(&lobj_1, formatSpec);
  parameterName.set_size(1, formatSpec.size(1) + 1);
  loop_ub = formatSpec.size(1);
  for (i = 0; i < loop_ub; i++) {
    parameterName[i] = formatSpec[i];
  }
  parameterName[formatSpec.size(1)] = '\x00';
  nameExists = std::mem_fn(&MATLABROSParameter::hasParam)(
      lobj_1.ParameterHelper, &parameterName[0]);
  if (nameExists) {
    val = lobj_1.j_get();
    TG.param.maxDepth = val;
    printf("%s : %f \n", "/proc_planner/max_depth", val);
    fflush(stdout);
  } else {
    TG.param.maxDepth = 5.0;
  }
  //         %% get rosparam number
  coder::ros::ParameterTree::k_canonicalizeName(&lobj_1, formatSpec);
  parameterName.set_size(1, formatSpec.size(1) + 1);
  loop_ub = formatSpec.size(1);
  for (i = 0; i < loop_ub; i++) {
    parameterName[i] = formatSpec[i];
  }
  parameterName[formatSpec.size(1)] = '\x00';
  nameExists = std::mem_fn(&MATLABROSParameter::hasParam)(
      lobj_1.ParameterHelper, &parameterName[0]);
  if (nameExists) {
    val = lobj_1.k_get();
    TG.param.surfaceWarning = val;
    printf("%s : %f \n", "/proc_planner/surface_warning", val);
    fflush(stdout);
  } else {
    TG.param.surfaceWarning = 0.3;
  }
  planner.param = TG.param;
  //  Ros Spin
  validMsg = std_msgs_Int8Struct();
  MATLABRate_reset(r.RateHelper);
  coder::tic(&val, &vlmax);
  printf("INFO : proc planner : Node is started \n");
  fflush(stdout);
  printf("INFO : proc planner : Wait for poses \n");
  fflush(stdout);
  while (1) {
    //  Regarder si un nouveau multi-addPose
    //  initialte variables
    //  GET
    nameExists = newMadpPose;
    if (!nameExists) {
      //  initialte variables
      //  SET
      newInitialPose = false;
    } else if (planner.TrajIsGenerating) {
      planner.TrajIsGenerating = false;
    } else {
      //  initialte variables
      //  GET
      nameExists = newInitialPose;
      if (nameExists) {
        double c_TG[4];
        double eul[3];
        double b_TG[2];
        double suppPoint;
        int loop_ub_tmp;
        signed char i1;
        printf("INFO : proc planner : Initial poses received \n");
        fflush(stdout);
        planner.TrajIsGenerating = true;
        //  Cree l'objet trajectoire
        planner.madpSub->get_LatestMessage(TG.MAPM.MessageType,
                                           &multiAddposeMsg_InterpolationMethod,
                                           TG.MAPM.Pose);
        TG.param = planner.param;
        planner.icSub->get_LatestMessage(&val, &vlmax, &d, &vamax, &tl,
                                         &icMsg_Orientation_Z,
                                         &icMsg_Orientation_W);
        planner.obstacleSub->get_LatestMessage(&TG.obstacleData);
        TG.icOffset = 2.0;
        // ==================================================================
        //  Constructeur
        //  Initialise l'objet trajectoire et vérifie si le message multi add
        //  pose est valide.
        TG.status = 0.0;
        //  Validité de waypoints reçus.
        //  prendre les infos des obstacles.
        TG.MAPM.InterpolationMethod = multiAddposeMsg_InterpolationMethod;
        b_TG[0] = TG.MAPM.Pose.size(0);
        b_TG[1] = 1.0;
        TG.nMAPM = coder::internal::maximum(b_TG);
        //  matlab and cpp dont use same index. return max instead
        //  Initialiser les parametres
        //  Importer la librairie quatUtilities
        //  Verifier que le dernier point ne contient pas de rayon.
        if (TG.MAPM.Pose[static_cast<int>(TG.nMAPM) - 1].Fine != 0.0) {
          TG.MAPM.Pose[static_cast<int>(TG.nMAPM) - 1].Fine = 0.0;
          printf("Warning : proc planner : last waypoint must have fine "
                 "parameter set to 0 \n");
          fflush(stdout);
        }
        //  point supplementaire pour l'arrondissement.
        suppPoint = 0.0;
        i = static_cast<int>(TG.nMAPM);
        for (loop_ub = 0; loop_ub < i; loop_ub++) {
          if (!(TG.MAPM.Pose[loop_ub].Fine == 0.0)) {
            suppPoint++;
          }
        }
        //  nombre de waypoints  + point supp + offset + point initial
        TG.n = ((TG.nMAPM + suppPoint) + 2.0) + 1.0;
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
        TG.courseList.set_size(1, loop_ub_tmp);
        for (i = 0; i < loop_ub_tmp; i++) {
          TG.courseList[i] = 0.0;
        }
        TG.speedList.set_size(1, loop_ub_tmp);
        for (i = 0; i < loop_ub_tmp; i++) {
          TG.speedList[i] = 0.0;
        }
        double dv[3];
        //  trouver le waypoint initial
        // ==================================================================
        //  Fonnction qui retoure le waypoint initial
        //  Replire les listes.
        TG.pointList[0] = val;
        TG.pointList[TG.pointList.size(0)] = vlmax;
        TG.pointList[TG.pointList.size(0) * 2] = d;
        TG.quatList[0] = icMsg_Orientation_W;
        TG.quatList[TG.quatList.size(0)] = vamax;
        TG.quatList[TG.quatList.size(0) * 2] = tl;
        TG.quatList[TG.quatList.size(0) * 3] = icMsg_Orientation_Z;
        TG.timeList[0] = 0.0;
        TG.speedList[0] = 0.0;
        c_TG[0] = TG.quatList[0];
        c_TG[1] = TG.quatList[TG.quatList.size(0)];
        c_TG[2] = TG.quatList[TG.quatList.size(0) * 2];
        c_TG[3] = TG.quatList[TG.quatList.size(0) * 3];
        coder::quat2eul(c_TG, dv);
        eul[0] = 57.295779513082323 * dv[0];
        TG.courseList[0] = eul[0];
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
        icMsg_Orientation_Z = TG.param.ts;
        TG.timeList[1] = icMsg_Orientation_Z;
        TG.courseList[1] = eul[0];
        TG.speedList[1] = 0.0;
        //  Verifier si le mode d'interpolation est valide
        // ==================================================================
        //  Fonction qui envoie les message sur ros
        //  Le parametre verif permet au constructeur de verifier si le mode
        //  existe sans interpoler. Determiner le type d'imterpolation
        switch (multiAddposeMsg_InterpolationMethod) {
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
          TG.status = -1.0;
          printf("INFO : proc planner : Interpolation strategy is not "
                 "recognized  \n");
          fflush(stdout);
          break;
        }
        //  Process le message addpose
        TG.processWpt();
        //  Calculer les temps entre chaque waypoints
        if (TG.status == 0.0) {
          // ==================================================================
          //  Fonnction qui calcul le temps entre chaque waypoint
          loop_ub = 1;
          int exitg1;
          do {
            exitg1 = 0;
            if (loop_ub - 1 <= static_cast<int>(TG.n + -1.0) - 1) {
              bool guard1{false};
              //  pour chaques waypoints
              //  Determiner le parametre de vitesse
              guard1 = false;
              switch (static_cast<int>(TG.speedList[loop_ub])) {
              case 0:
                //  Vitesse normale
                val = TG.param.normalSpeed.amax;
                vlmax = TG.param.normalSpeed.vlmax;
                vamax = TG.param.normalSpeed.vamax;
                guard1 = true;
                break;
              case 1:
                //  Vitesse rapide
                val = TG.param.highSpeed.amax;
                vlmax = TG.param.highSpeed.vlmax;
                vamax = TG.param.highSpeed.vamax;
                guard1 = true;
                break;
              case 2:
                //  Vitesse lente
                val = TG.param.lowSpeed.amax;
                vlmax = TG.param.lowSpeed.vlmax;
                vamax = TG.param.lowSpeed.vamax;
                guard1 = true;
                break;
              default:
                //  mode non reconue.
                TG.status = -3.0;
                printf("INFO : proc planner : Speed parameter is not "
                       "recognized \n");
                fflush(stdout);
                TG.nbPoint = 1.0;
                exitg1 = 1;
                break;
              }
              if (guard1) {
                double q[4];
                double qRel[4];
                //  Trouver la distance Eucledienne entre 2 points
                eul[0] =
                    TG.pointList[loop_ub] -
                    TG.pointList[static_cast<int>(
                                     (static_cast<double>(loop_ub - 1) + 2.0) -
                                     1.0) -
                                 1];
                eul[1] =
                    TG.pointList[loop_ub + TG.pointList.size(0)] -
                    TG.pointList[(static_cast<int>(
                                      (static_cast<double>(loop_ub - 1) + 2.0) -
                                      1.0) +
                                  TG.pointList.size(0)) -
                                 1];
                eul[2] =
                    TG.pointList[loop_ub + TG.pointList.size(0) * 2] -
                    TG.pointList[(static_cast<int>(
                                      (static_cast<double>(loop_ub - 1) + 2.0) -
                                      1.0) +
                                  TG.pointList.size(0) * 2) -
                                 1];
                d = coder::b_norm(eul);
                //  Déterminer le temps selon aMax
                tl = 4.0 * std::sqrt(3.0 * d) / (3.0 * std::sqrt(val));
                //  Déterminer la vitesse maximum de la trajectoire
                //  Si la vitesse est plus grande que la vitesse maximum
                if (val * tl / 4.0 > vlmax) {
                  //  Calculer le temps selon vmax
                  tl = 4.0 * d / (3.0 * vlmax);
                }
                //  Déterminer l'angle entre les 2 quaternions
                q[0] =
                    TG.quatList[static_cast<int>(
                                    (static_cast<double>(loop_ub - 1) + 2.0) -
                                    1.0) -
                                1];
                q[1] =
                    TG.quatList[(static_cast<int>(
                                     (static_cast<double>(loop_ub - 1) + 2.0) -
                                     1.0) +
                                 TG.quatList.size(0)) -
                                1];
                q[2] =
                    TG.quatList[(static_cast<int>(
                                     (static_cast<double>(loop_ub - 1) + 2.0) -
                                     1.0) +
                                 TG.quatList.size(0) * 2) -
                                1];
                q[3] =
                    TG.quatList[(static_cast<int>(
                                     (static_cast<double>(loop_ub - 1) + 2.0) -
                                     1.0) +
                                 TG.quatList.size(0) * 3) -
                                1];
                q[1] = -q[1];
                q[2] = -q[2];
                q[3] = -q[3];
                c_TG[0] = TG.quatList[loop_ub];
                c_TG[1] = TG.quatList[loop_ub + TG.quatList.size(0)];
                c_TG[2] = TG.quatList[loop_ub + TG.quatList.size(0) * 2];
                c_TG[3] = TG.quatList[loop_ub + TG.quatList.size(0) * 3];
                coder::quatmultiply(q, c_TG, qRel);
                //  Déterminer le temps angulaire
                //  Déterminer le temps maximale
                val = coder::b_norm(*(double(*)[3]) & qRel[1]);
                eul[0] = tl;
                eul[1] = 2.0 * rt_atan2d_snf(val, qRel[0]) / vamax;
                eul[2] = icMsg_Orientation_Z;
                val = coder::internal::b_maximum(eul);
                //  Arrondire supperieur selont ts
                vlmax = coder::b_mod(val, icMsg_Orientation_Z);
                if (vlmax > 0.0) {
                  val += icMsg_Orientation_Z - vlmax;
                }
                TG.timeList[loop_ub] =
                    TG.timeList[static_cast<int>(
                                    (static_cast<double>(loop_ub - 1) + 2.0) -
                                    1.0) -
                                1] +
                    val;
                loop_ub++;
              }
            } else {
              //  Déterminer le nombre de points
              TG.nbPoint = std::round(TG.timeList[TG.timeList.size(0) - 1] /
                                      icMsg_Orientation_Z);
              exitg1 = 1;
            }
          } while (exitg1 == 0);
        } else {
          TG.nbPoint = 1.0;
        }
        //  vérifier la profondeur maximum.
        loop_ub = TG.pointList.size(0);
        d_TG.set_size(TG.pointList.size(0));
        for (i = 0; i < loop_ub; i++) {
          d_TG[i] = TG.pointList[i + TG.pointList.size(0) * 2];
        }
        if (coder::internal::maximum(d_TG) > TG.param.maxDepth) {
          TG.status = -6.0;
        }
        //  NEED MISSION CLEAN UP
        //              % Vérifier si le sub peut faire surface;
        //              if (min(this.pointList(:,3)) >
        //              this.param.surface_warning )
        //                  this.status = this.WARN_AUV_MAY_SURFACE;
        //              end
        //  Definir la taille de la trajectoire
        TG.trajPosition.set_size(static_cast<int>(TG.nbPoint), 3);
        loop_ub_tmp = static_cast<int>(TG.nbPoint) * 3;
        for (i = 0; i < loop_ub_tmp; i++) {
          TG.trajPosition[i] = 0.0;
        }
        TG.trajQuat.set_size(static_cast<int>(TG.nbPoint), 4);
        loop_ub = static_cast<int>(TG.nbPoint) << 2;
        for (i = 0; i < loop_ub; i++) {
          TG.trajQuat[i] = 0.0;
        }
        TG.trajBodyVelocity.set_size(static_cast<int>(TG.nbPoint), 3);
        for (i = 0; i < loop_ub_tmp; i++) {
          TG.trajBodyVelocity[i] = 0.0;
        }
        TG.trajAngulairRates.set_size(static_cast<int>(TG.nbPoint), 3);
        for (i = 0; i < loop_ub_tmp; i++) {
          TG.trajAngulairRates[i] = 0.0;
        }
        TG.trajLinearAcceleration.set_size(static_cast<int>(TG.nbPoint), 3);
        for (i = 0; i < loop_ub_tmp; i++) {
          TG.trajLinearAcceleration[i] = 0.0;
        }
        TG.trajAngularAcceleration.set_size(static_cast<int>(TG.nbPoint), 3);
        for (i = 0; i < loop_ub_tmp; i++) {
          TG.trajAngularAcceleration[i] = 0.0;
        }
        //  Envoyer a ros si le mAddpose est valide
        icMsg_Orientation_Z = std::round(TG.status);
        if (icMsg_Orientation_Z < 128.0) {
          if (icMsg_Orientation_Z >= -128.0) {
            i1 = static_cast<signed char>(icMsg_Orientation_Z);
          } else {
            i1 = MIN_int8_T;
          }
        } else if (icMsg_Orientation_Z >= 128.0) {
          i1 = MAX_int8_T;
        } else {
          i1 = 0;
        }
        validMsg.Data = i1;
        b_pub = planner.validPub;
        MATLABPUBLISHER_publish(b_pub->PublisherHelper, &validMsg);
        //  Si la trajectoire est valide generer la trajectoire
        if (TG.status == 0.0) {
          TG.Compute(planner.trajpub);
        }
        //  initialte variables
        //  SET
        newMadpPose = false;
        //  initialte variables
        //  SET
        newInitialPose = false;
      }
    }
    MATLABRate_sleep(r.RateHelper);
    coder::toc(r.PreviousPeriod.tv_sec, r.PreviousPeriod.tv_nsec);
    coder::tic(&r.PreviousPeriod.tv_sec, &r.PreviousPeriod.tv_nsec);
  }
}

// End of code generation (proc_planner.cpp)
