//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: clothoidG1fit2wp.cpp
//
// MATLAB Coder version            : 5.4
// C/C++ source code generated on  : 12-Apr-2022 11:44:16
//

// Include Files
#include "clothoidG1fit2wp.h"
#include "div.h"
#include "eml_mtimes_helper.h"
#include "find.h"
#include "fresnel.h"
#include "proc_planner_data.h"
#include "proc_planner_rtwutil.h"
#include "rt_nonfinite.h"
#include "sqrt.h"
#include "unsafeSxfun.h"
#include "coder_array.h"
#include <cmath>
#include <string.h>

// Variable Definitions
static const double dv[351]{
    -1.5361481088532109E-40, -5.1782003708968662E-38, 5.8080516979367073E-38,
    -6.2922109794702842E-36, 1.7744129415359022E-35,  -9.8266873453160865E-36,
    -3.0557011816989596E-34, 1.9988681524430764E-33,  -2.7007621230825949E-33,
    9.6497076628562535E-34,  -8.50146594503621E-33,   8.7613736854720049E-32,
    -2.8258679893784358E-31, 2.3637604856716169E-31,  -5.8556266604372106E-32,
    -1.2863962524996432E-31, 2.229093841830142E-30,   -1.1057059963507232E-29,
    2.3139349101185755E-29,  -1.2630223562649489E-29, 2.0068564650639364E-30,
    -1.1052377502159136E-30, 3.0309726719642508E-29,  -2.57153235020298E-28,
    7.9357820762496212E-28,  -1.1834423538462616E-27, 3.7518152500494656E-28,
    -9.5988758699827141E-30, -5.8444661902772888E-30, 2.2799302267031842E-28,
    -3.118708591261201E-27,  1.6937953593997347E-26,  -3.4234259338177584E-26,
    3.675290577810477E-26,   -1.6183294340108731E-27, -2.9209077909746285E-27,
    -2.0493494333051533E-29, 1.0232091530758262E-27,  -2.0119872415420161E-26,
    1.8157191663212143E-25,  -6.8278782273948665E-25, 7.9289707228553727E-25,
    -5.1713140278139824E-25, -3.5757401738269863E-25, 1.7191521549607673E-25,
    -5.001307006229815E-29,  2.9234616420394369E-27,  -7.3372627735809734E-26,
    9.6978563886575261E-25,  -6.3976458551757164E-24, 1.6073455072306433E-23,
    -7.37463587795066E-25,   -7.0522343048774666E-24, 1.4805755563608624E-23,
    -5.1965352404273039E-24, -8.5391792173019132E-29, 5.4962692899068422E-27,
    -1.5546891778194411E-25, 2.6049795261751296E-24,  -2.6172058881327836E-23,
    1.2985982037510549E-22,  -1.423772303418446E-22,  -5.8282903661876709E-22,
    4.1133508360308628E-22,  -1.742659308147939E-22,  8.07786256209318E-23,
    -9.7738126735700558E-29, 6.6212355845436972E-27,  -1.7707072436748613E-25,
    2.8057133511879665E-24,  -3.4869970759687543E-23, 3.0241871214865029E-22,
    -9.92012310209099E-22,   -3.2149566866116185E-21, 1.8710249707031661E-20,
    -1.2453541845369618E-21, -7.5062472154050874E-21, 2.8499865852964518E-22,
    -6.9207112182904389E-29, 4.4179830835754724E-27,  -4.4762524882779791E-26,
    -2.450817653228083E-24,  7.1914140604820392E-23,  -7.2673875098954476E-22,
    3.3571441047866719E-21,  -1.5906878744538782E-20, 1.0715370660853569E-19,
    -2.1813900762258771E-19, -3.7882773476137619E-19, 4.4188357957185649E-19,
    -5.2046323054922296E-20, -2.8170935396816464E-29, 7.8914114794548443E-28,
    1.528966070127476E-25,   -1.1332880987718864E-23, 3.3104475572268851E-22,
    -4.9647512138578754E-21, 3.9715384015216385E-20,  -1.6290821269847189E-19,
    3.36612516663913E-19,    -3.36275918384194E-19,   -2.8323208988729979E-18,
    1.5348780107717589E-17,  -1.2231243924447674E-17, 1.5460269152965008E-18,
    -1.0350259940425787E-29, -4.7414043171551787E-28, 1.9707672417753685E-25,
    -1.4495788889042659E-23, 5.1378340796211685E-22,  -1.0210774519786583E-20,
    1.165542649503511E-19,   -7.1421779330877591E-19, 1.6365283191176908E-18,
    4.9170568130837211E-18,  -4.4186234291063853E-17, 1.6247947613884891E-16,
    -3.4187835062780104E-16, 2.2495563268135524E-16,  -2.8304172442233909E-17,
    -9.54190907880087E-30,   4.33416352213585E-28,    7.30606772876727E-26,
    -8.4789175470441986E-24, 3.9746370968729408E-22,  -1.0350198533651566E-20,
    1.589371276512773E-19,   -1.3721089740423357E-18, 4.7868869804965763E-18,
    1.9699426816042335E-17,  -2.7595647699194014E-16, 1.2612122765846683E-15,
    -3.3199758280144047E-15, 5.1284109097493322E-15,  -2.9773954125181772E-15,
    3.6686222388116938E-16,  -7.13761114432792E-30,   8.6070327678610011E-28,
    -2.5253411261423782E-26, -1.429985806399278E-24,  1.4200678258817658E-22,
    -5.2901273901739912E-21, 1.0879148930261737E-19,  -1.2468905412479112E-18,
    5.651703115185149E-18,   4.073824764700649E-17,   -7.7193016891576893E-16,
    5.1280294092344238E-15,  -1.8830251965098877E-14, 4.2082102420983456E-14,
    -5.4816521831539046E-14, 2.9056289127761095E-14,  -3.5049036301087839E-15,
    -2.7032712394278119E-30, 4.4439845217679321E-28,  -2.8561533629781625E-26,
    7.4263493149653183E-25,  7.7648205291611823E-24,  -1.1313407629960782E-21,
    3.4992489982228452E-20,  -5.11237062122324E-19,   1.9082838069139238E-18,
    6.02161124473958E-17,    -1.1855133738581856E-15, 1.0647602057665829E-14,
    -5.5915318620809614E-14, 1.8096099090326831E-13,  -3.6385985586845819E-13,
    4.2410069501559273E-13,  -2.106362282048389E-13,  2.4385529408308407E-14,
    -4.8547818044528891E-31, 9.5570081279537094E-29,  -7.8572054752482576E-27,
    3.3174769183447452E-25,  -6.2142341258768858E-24, -5.0991712996566211E-23,
    5.1392990708290932E-21,  -8.807706142947147E-20,  -5.8182766640448854E-19,
    5.1419279154935842E-17,  -1.04407697522146E-15,   1.1898094238539857E-14,
    -8.5367937011271162E-14, 3.9513126620957262E-13,  -1.1748533341492665E-12,
    2.1917257282808794E-12,  -2.3566809884820566E-12, 1.0795020408261728E-12,
    -1.5837465906955864E-13, -2.7533507225420422E-32, 5.7619182837708977E-30,
    -4.6471657116787863E-28, 1.4048422360791874E-26,  3.7650962241144584E-25,
    -4.9228435831327322E-23, 1.9071729205179347E-21,  -3.3490783882201909E-20,
    -7.018689437542322E-20,  1.8324124104655822E-17,  -4.7883976550407734E-16,
    7.0487303907715931E-15,  -6.735734123826801E-14,  4.3114382655453385E-13,
    -1.8436618496422663E-12, 5.1655481921478335E-12,  -9.1498502333527442E-12,
    9.53768065186612E-12,    -5.5096965823391316E-12, -1.9256688414961511E-12,
    2.6993907913031997E-33,  -8.3658508533748674E-31, 1.2360111759498158E-28,
    -1.1391057286564071E-26, 7.1943116140837765E-25,  -3.2278401611187206E-23,
    1.0313736180462972E-21,  -2.2595952680170383E-20, 2.9013328570466337E-19,
    -1.4189880636575127E-19, -8.2575877751974837E-17, 1.9535524420193836E-15,
    -2.60333162544509E-14,   2.2905798368369833E-13,  -1.3730942326110817E-12,
    5.5797967300488639E-12,  -1.5044456366394642E-11, 2.5612747661164289E-11,
    -1.9627816796196334E-11, -2.8036172295220303E-11, -1.9615478304946413E-10,
    3.8934925377973957E-34,  -1.2639609126235819E-31, 1.9287682878359229E-29,
    -1.8332237204928374E-27, 1.2092531131064511E-25,  -5.8236835135326278E-24,
    2.0915581782354698E-22,  -5.5964099612773872E-21, 1.0833579869797173E-19,
    -1.3736666335311385E-18, 6.6209633655847283E-18,  1.4362053626673917E-16,
    -4.0159095765450877E-15, 5.320276578988179E-14,   -4.5399145021925304E-13,
    2.6343951113716903E-12,  -1.0426603808524378E-11, 2.7378813158203465E-11,
    -2.4213032965198892E-11, -6.43589148489966E-11,   8.7111108876109732E-11,
    -1.58880825805031E-8,    1.2049379324305816E-35,  -4.3610770108214582E-33,
    7.4936434757448969E-31,  -8.1105245364317889E-29, 6.1705088386370215E-27,
    -3.480752271664829E-25,  1.4948191338667704E-23,  -4.9368146563727049E-22,
    1.2499110582545291E-20,  -2.3793207120554828E-19, 3.2322327482741956E-18,
    -2.6498507726404211E-17, 7.8731033015748051E-18,  3.2775331491296092E-15,
    -5.1807698267687295E-14, 4.62732644627914E-13,    -2.7239785524170987E-12,
    1.0896716883650769E-11,  -1.8645986337651637E-11, 2.5459617591435155E-12,
    -1.3347654837468073E-8,  1.3161132276731047E-7,   -1.3227534741608429E-6,
    -9.7984625010885519E-38, 3.2900432333335651E-35,  -4.4581754057254838E-33,
    2.5824817729473294E-31,  5.2049615357860253E-30,  -2.1583876518311414E-27,
    1.9476950757610683E-25,  -1.0716316264212252E-23, 4.1440657240625748E-22,
    -1.1817624319451798E-20, 2.5249339155046378E-19,  -4.0233948389965105E-18,
    4.64169135391771E-17,    -3.5476759515651092E-16, 1.1999262837080123E-15,
    8.516412269170767E-15,   -1.527199343162684E-13,  1.1449867637138848E-12,
    -3.6599461401055181E-12, -4.6103940452468584E-11, -4.7424213964325014E-9,
    1.4095535848735113E-8,   1.1415162393763462E-5,   -0.00011904761791914855,
    -7.7487127476207258E-39, 3.1576790378728681E-36,  -5.9250135047007422E-34,
    6.7643789484475193E-32,  -5.220570875188387E-30,  2.8506788574160792E-28,
    -1.1098370767710674E-26, 2.9468645436878283E-25,  -4.2328657438375513E-24,
    -3.3901276335768838E-23, 3.8407990599986091E-21,  -1.1933448342985106E-19,
    2.3702576054378613E-18,  -3.3709086299905129E-17, 3.5240422748635714E-16,
    -2.688297081936284E-15,  1.4426938768292247E-14,  -4.5785087028675909E-14,
    1.6710103243486247E-14,  -1.1024143067873009E-11, -3.3079062392811025E-10,
    2.8376658214791753E-8,   2.8265347449301076E-6,   3.9682541488440042E-5,
    -0.016666666666889381,   -8.6841596356231729E-42, 3.1939131296905081E-39,
    -4.8490390875687847E-37, 3.2729122440862841E-35,  5.3980586162289553E-34,
    -3.3686936226391223E-31, 3.7197707807256541E-29,  -2.5380412938111731E-27,
    1.2494404817163045E-25,  -4.6966036280739172E-24, 1.3852307187625331E-22,
    -3.2509821682467773E-21, 6.1100085267801761E-20,  -9.20594856358596E-19,
    1.1081925404564449E-17,  -1.0575868027372313E-16, 7.920139233623936E-16,
    -4.5514965597202215E-15, 1.3296256931854534E-14,  -3.345171633728989E-13,
    1.7101904098836834E-11,  2.4300392651460408E-9,   4.6155748216027864E-8,
    -1.5460729722609369E-5,  -0.00238095238099261,    1.0000000000000047};

// Function Declarations
static void b_times(coder::array<creal_T, 1U> &in1,
                    const coder::array<creal_T, 1U> &in2);

static void binary_expand_op(coder::array<double, 1U> &in1,
                             const coder::array<double, 1U> &in2,
                             const coder::array<double, 1U> &in3,
                             const coder::array<double, 1U> &in4,
                             const coder::array<double, 1U> &in5,
                             const coder::array<double, 1U> &in6);

static void binary_expand_op(
    coder::array<creal_T, 1U> &in1, const coder::array<double, 1U> &in2,
    const coder::array<creal_T, 1U> &in3, const coder::array<creal_T, 1U> &in5,
    const coder::array<creal_T, 1U> &in6, const coder::array<creal_T, 1U> &in7,
    const coder::array<creal_T, 1U> &in8, const coder::array<creal_T, 1U> &in9,
    const coder::array<creal_T, 1U> &in10, const coder::array<double, 1U> &in12,
    const coder::array<creal_T, 1U> &in13);

static void binary_expand_op(coder::array<creal_T, 1U> &in1,
                             const coder::array<double, 1U> &in2,
                             const coder::array<creal_T, 1U> &in5);

static void binary_expand_op(coder::array<creal_T, 1U> &in1,
                             const coder::array<creal_T, 1U> &in3,
                             const coder::array<creal_T, 1U> &in4,
                             const coder::array<creal_T, 1U> &in5);

static void binary_expand_op(coder::array<creal_T, 1U> &in1, int in2,
                             const coder::array<creal_T, 1U> &in3,
                             const coder::array<creal_T, 1U> &in4);

static void binary_expand_op(coder::array<creal_T, 1U> &in1,
                             const coder::array<creal_T, 1U> &in2, int in3,
                             const coder::array<creal_T, 1U> &in5,
                             const coder::array<creal_T, 1U> &in6,
                             const coder::array<creal_T, 1U> &in7,
                             const coder::array<creal_T, 1U> &in8,
                             const coder::array<creal_T, 1U> &in9);

static void binary_expand_op(coder::array<double, 1U> &in1,
                             const coder::array<double, 1U> &in2,
                             const coder::array<double, 1U> &in3,
                             const coder::array<double, 1U> &in4,
                             const coder::array<double, 1U> &in5);

static void binary_expand_op(coder::array<double, 1U> &in1,
                             const double in2[351], int in3,
                             const coder::array<double, 2U> &in4, double in5,
                             const coder::array<double, 2U> &in6, double in7);

static void binary_expand_op(coder::array<double, 1U> &in1,
                             const coder::array<creal_T, 1U> &in2,
                             const coder::array<creal_T, 1U> &in3);

static void binary_expand_op(coder::array<double, 1U> &in1, int in2,
                             const double in3[351], int in4,
                             const coder::array<double, 2U> &in5, int in6,
                             const coder::array<double, 2U> &in7);

static void binary_expand_op(coder::array<double, 1U> &in1, int in2,
                             const double in3[351], int in4,
                             const coder::array<double, 2U> &in5,
                             const coder::array<double, 2U> &in6, int in7);

static void binary_expand_op(coder::array<double, 1U> &in1,
                             const double in2[351], int in3,
                             const coder::array<double, 2U> &in4, int in5,
                             const coder::array<double, 2U> &in6, int in7);

static void binary_expand_op(coder::array<double, 1U> &in1,
                             const coder::array<double, 1U> &in2,
                             const coder::array<double, 1U> &in3,
                             const coder::array<double, 1U> &in4);

namespace coder {
namespace matlabshared {
namespace tracking {
namespace internal {
namespace scenario {
static void fetchAgrad(const ::coder::array<double, 1U> &x,
                       const ::coder::array<double, 1U> &y,
                       ::coder::array<double, 1U> &a,
                       ::coder::array<double, 1U> &dadx,
                       ::coder::array<double, 1U> &dady);

static void fresnelgLargea1(const ::coder::array<double, 1U> &a,
                            const ::coder::array<double, 1U> &d,
                            const ::coder::array<double, 1U> &c,
                            ::coder::array<creal_T, 1U> &rsfa,
                            ::coder::array<creal_T, 1U> &drsfa);

static void fresnelgSmalla1(const ::coder::array<double, 1U> &a,
                            const ::coder::array<double, 1U> &d,
                            const ::coder::array<double, 1U> &c,
                            ::coder::array<creal_T, 1U> &z,
                            ::coder::array<creal_T, 1U> &dz);

} // namespace scenario
} // namespace internal
} // namespace tracking
} // namespace matlabshared
} // namespace coder
static void e_binary_expand_op(coder::array<double, 1U> &in1,
                               const coder::array<double, 1U> &in2,
                               const coder::array<double, 1U> &in3,
                               const coder::array<double, 1U> &in4,
                               const coder::array<double, 1U> &in5,
                               const coder::array<double, 1U> &in6);

static void e_binary_expand_op(coder::array<double, 1U> &in1,
                               const coder::array<double, 1U> &in2,
                               const coder::array<double, 1U> &in3,
                               const coder::array<double, 1U> &in4,
                               const coder::array<double, 1U> &in5);

static void e_binary_expand_op(coder::array<double, 1U> &in1,
                               const coder::array<double, 1U> &in2);

static void f_binary_expand_op(coder::array<double, 1U> &in1,
                               const coder::array<double, 1U> &in2,
                               const coder::array<double, 1U> &in3,
                               const coder::array<double, 1U> &in4,
                               const coder::array<double, 1U> &in5);

static void minus(coder::array<creal_T, 1U> &in1,
                  const coder::array<creal_T, 1U> &in2,
                  const coder::array<creal_T, 1U> &in3);

static void plus(coder::array<double, 1U> &in1,
                 const coder::array<double, 1U> &in2,
                 const coder::array<double, 1U> &in3);

static void plus(coder::array<creal_T, 1U> &in1,
                 const coder::array<creal_T, 1U> &in2);

static double rt_powd_snf(double u0, double u1);

static void times(coder::array<creal_T, 1U> &in1,
                  const coder::array<creal_T, 1U> &in2,
                  const coder::array<creal_T, 1U> &in3);

static void times(coder::array<creal_T, 1U> &in1,
                  const coder::array<creal_T, 1U> &in2);

static void times(coder::array<double, 1U> &in1,
                  const coder::array<double, 1U> &in2);

static void times(coder::array<double, 1U> &in1,
                  const coder::array<double, 1U> &in2,
                  const coder::array<double, 1U> &in3);

// Function Definitions
//
// Arguments    : coder::array<creal_T, 1U> &in1
//                const coder::array<creal_T, 1U> &in2
// Return Type  : void
//
static void b_times(coder::array<creal_T, 1U> &in1,
                    const coder::array<creal_T, 1U> &in2)
{
  coder::array<creal_T, 1U> b_in1;
  int i;
  int loop_ub;
  int stride_0_0;
  int stride_1_0;
  if (in2.size(0) == 1) {
    i = in1.size(0);
  } else {
    i = in2.size(0);
  }
  b_in1.set_size(i);
  stride_0_0 = (in1.size(0) != 1);
  stride_1_0 = (in2.size(0) != 1);
  if (in2.size(0) == 1) {
    loop_ub = in1.size(0);
  } else {
    loop_ub = in2.size(0);
  }
  for (i = 0; i < loop_ub; i++) {
    double d;
    double d1;
    int i1;
    i1 = i * stride_1_0;
    d = in2[i1].im;
    d1 = in2[i1].re;
    b_in1[i].re = in1[i * stride_0_0].re * d1 - in1[i * stride_0_0].im * d;
    b_in1[i].im = in1[i * stride_0_0].re * d + in1[i * stride_0_0].im * d1;
  }
  in1.set_size(b_in1.size(0));
  loop_ub = b_in1.size(0);
  for (i = 0; i < loop_ub; i++) {
    in1[i] = b_in1[i];
  }
}

//
// Arguments    : coder::array<double, 1U> &in1
//                const double in2[351]
//                int in3
//                const coder::array<double, 2U> &in4
//                double in5
//                const coder::array<double, 2U> &in6
//                double in7
// Return Type  : void
//
static void binary_expand_op(coder::array<double, 1U> &in1,
                             const double in2[351], int in3,
                             const coder::array<double, 2U> &in4, double in5,
                             const coder::array<double, 2U> &in6, double in7)
{
  coder::array<double, 1U> b_in1;
  double b_in2;
  int b_loop_ub;
  int i;
  int loop_ub;
  int stride_0_0;
  int stride_1_0;
  int stride_2_0;
  b_in2 = in2[in3];
  i = in4.size(0);
  loop_ub = in6.size(0);
  if (loop_ub == 1) {
    b_loop_ub = i;
  } else {
    b_loop_ub = loop_ub;
  }
  if (b_loop_ub == 1) {
    b_loop_ub = in1.size(0);
  } else if (loop_ub == 1) {
    b_loop_ub = i;
  } else {
    b_loop_ub = loop_ub;
  }
  b_in1.set_size(b_loop_ub);
  stride_0_0 = (in1.size(0) != 1);
  stride_1_0 = (i != 1);
  stride_2_0 = (loop_ub != 1);
  if (loop_ub == 1) {
    b_loop_ub = i;
  } else {
    b_loop_ub = loop_ub;
  }
  if (b_loop_ub == 1) {
    loop_ub = in1.size(0);
  } else if (loop_ub == 1) {
    loop_ub = i;
  }
  for (i = 0; i < loop_ub; i++) {
    b_in1[i] = in1[i * stride_0_0] +
               b_in2 *
                   in4[i * stride_1_0 +
                       in4.size(0) * (static_cast<int>(in5 + 1.0) - 1)] *
                   in6[i * stride_2_0 +
                       in6.size(0) * (static_cast<int>(in7 + 1.0) - 1)];
  }
  in1.set_size(b_in1.size(0));
  loop_ub = b_in1.size(0);
  for (i = 0; i < loop_ub; i++) {
    in1[i] = b_in1[i];
  }
}

//
// Arguments    : coder::array<creal_T, 1U> &in1
//                const coder::array<creal_T, 1U> &in2
//                int in3
//                const coder::array<creal_T, 1U> &in5
//                const coder::array<creal_T, 1U> &in6
//                const coder::array<creal_T, 1U> &in7
//                const coder::array<creal_T, 1U> &in8
//                const coder::array<creal_T, 1U> &in9
// Return Type  : void
//
static void binary_expand_op(coder::array<creal_T, 1U> &in1,
                             const coder::array<creal_T, 1U> &in2, int in3,
                             const coder::array<creal_T, 1U> &in5,
                             const coder::array<creal_T, 1U> &in6,
                             const coder::array<creal_T, 1U> &in7,
                             const coder::array<creal_T, 1U> &in8,
                             const coder::array<creal_T, 1U> &in9)
{
  coder::array<creal_T, 1U> b_in2;
  double d;
  int i;
  int loop_ub;
  int stride_0_0;
  int stride_1_0;
  int stride_2_0;
  int stride_3_0;
  int stride_4_0;
  int stride_5_0;
  int stride_6_0;
  d = 2.0 * (static_cast<double>(in3) + 1.0) - 1.0;
  if (in9.size(0) == 1) {
    i = in8.size(0);
  } else {
    i = in9.size(0);
  }
  if (in7.size(0) == 1) {
    stride_0_0 = in6.size(0);
  } else {
    stride_0_0 = in7.size(0);
  }
  if (stride_0_0 == 1) {
    if (in5.size(0) == 1) {
      stride_0_0 = in1.size(0);
    } else {
      stride_0_0 = in5.size(0);
    }
  } else if (in7.size(0) == 1) {
    stride_0_0 = in6.size(0);
  } else {
    stride_0_0 = in7.size(0);
  }
  if (in7.size(0) == 1) {
    stride_1_0 = in6.size(0);
  } else {
    stride_1_0 = in7.size(0);
  }
  if (i == 1) {
    if (stride_0_0 == 1) {
      i = in2.size(0);
    } else if (stride_1_0 == 1) {
      if (in5.size(0) == 1) {
        i = in1.size(0);
      } else {
        i = in5.size(0);
      }
    } else if (in7.size(0) == 1) {
      i = in6.size(0);
    } else {
      i = in7.size(0);
    }
  } else if (in9.size(0) == 1) {
    i = in8.size(0);
  } else {
    i = in9.size(0);
  }
  b_in2.set_size(i);
  stride_0_0 = (in2.size(0) != 1);
  stride_1_0 = (in1.size(0) != 1);
  stride_2_0 = (in5.size(0) != 1);
  stride_3_0 = (in6.size(0) != 1);
  stride_4_0 = (in7.size(0) != 1);
  stride_5_0 = (in8.size(0) != 1);
  stride_6_0 = (in9.size(0) != 1);
  if (in9.size(0) == 1) {
    i = in8.size(0);
  } else {
    i = in9.size(0);
  }
  if (i == 1) {
    if (in7.size(0) == 1) {
      i = in6.size(0);
    } else {
      i = in7.size(0);
    }
    if (i == 1) {
      if (in5.size(0) == 1) {
        i = in1.size(0);
      } else {
        i = in5.size(0);
      }
    } else if (in7.size(0) == 1) {
      i = in6.size(0);
    } else {
      i = in7.size(0);
    }
    if (i == 1) {
      loop_ub = in2.size(0);
    } else {
      if (in7.size(0) == 1) {
        i = in6.size(0);
      } else {
        i = in7.size(0);
      }
      if (i == 1) {
        if (in5.size(0) == 1) {
          loop_ub = in1.size(0);
        } else {
          loop_ub = in5.size(0);
        }
      } else if (in7.size(0) == 1) {
        loop_ub = in6.size(0);
      } else {
        loop_ub = in7.size(0);
      }
    }
  } else if (in9.size(0) == 1) {
    loop_ub = in8.size(0);
  } else {
    loop_ub = in9.size(0);
  }
  for (i = 0; i < loop_ub; i++) {
    double b_in4_re_tmp;
    double b_in6_re_tmp;
    double c_in4_re_tmp;
    double in3_im;
    double in3_re;
    double in6_re_tmp;
    double re;
    int in4_re_tmp;
    int in8_re_tmp;
    in4_re_tmp = i * stride_2_0;
    b_in4_re_tmp = in5[in4_re_tmp].im;
    c_in4_re_tmp = in5[in4_re_tmp].re;
    in4_re_tmp = i * stride_4_0;
    in3_re = (static_cast<double>(in3) + 1.0) + in7[in4_re_tmp].re;
    in3_im = in7[in4_re_tmp].im;
    in4_re_tmp = i * stride_3_0;
    in6_re_tmp = in6[in4_re_tmp].re;
    b_in6_re_tmp = in6[in4_re_tmp].im;
    in4_re_tmp = i * stride_1_0;
    re = (d * in1[in4_re_tmp].re + (0.0 * c_in4_re_tmp - 0.5 * b_in4_re_tmp)) +
         (in6_re_tmp * in3_re - b_in6_re_tmp * in3_im);
    b_in4_re_tmp =
        (d * in1[in4_re_tmp].im + (0.0 * b_in4_re_tmp + 0.5 * c_in4_re_tmp)) +
        (in6_re_tmp * in3_im + b_in6_re_tmp * in3_re);
    in4_re_tmp = i * stride_5_0;
    in8_re_tmp = i * stride_6_0;
    c_in4_re_tmp = in8[in4_re_tmp].re;
    in3_re = in9[in8_re_tmp].im;
    in3_im = in8[in4_re_tmp].im;
    in6_re_tmp = in9[in8_re_tmp].re;
    b_in2[i].re =
        (in2[i * stride_0_0].re * re - in2[i * stride_0_0].im * b_in4_re_tmp) +
        (c_in4_re_tmp * in6_re_tmp - in3_im * in3_re);
    b_in2[i].im =
        (in2[i * stride_0_0].re * b_in4_re_tmp + in2[i * stride_0_0].im * re) +
        (c_in4_re_tmp * in3_re + in3_im * in6_re_tmp);
  }
  in1.set_size(b_in2.size(0));
  loop_ub = b_in2.size(0);
  for (i = 0; i < loop_ub; i++) {
    in1[i] = b_in2[i];
  }
}

//
// Arguments    : coder::array<creal_T, 1U> &in1
//                const coder::array<creal_T, 1U> &in3
//                const coder::array<creal_T, 1U> &in4
//                const coder::array<creal_T, 1U> &in5
// Return Type  : void
//
static void binary_expand_op(coder::array<creal_T, 1U> &in1,
                             const coder::array<creal_T, 1U> &in3,
                             const coder::array<creal_T, 1U> &in4,
                             const coder::array<creal_T, 1U> &in5)
{
  coder::array<creal_T, 1U> b_in1;
  int i;
  int loop_ub;
  int stride_0_0;
  int stride_1_0;
  int stride_2_0;
  int stride_3_0;
  if (in5.size(0) == 1) {
    i = in4.size(0);
  } else {
    i = in5.size(0);
  }
  if (i == 1) {
    if (in3.size(0) == 1) {
      i = in1.size(0);
    } else {
      i = in3.size(0);
    }
  } else if (in5.size(0) == 1) {
    i = in4.size(0);
  } else {
    i = in5.size(0);
  }
  b_in1.set_size(i);
  stride_0_0 = (in1.size(0) != 1);
  stride_1_0 = (in3.size(0) != 1);
  stride_2_0 = (in4.size(0) != 1);
  stride_3_0 = (in5.size(0) != 1);
  if (in5.size(0) == 1) {
    i = in4.size(0);
  } else {
    i = in5.size(0);
  }
  if (i == 1) {
    if (in3.size(0) == 1) {
      loop_ub = in1.size(0);
    } else {
      loop_ub = in3.size(0);
    }
  } else if (in5.size(0) == 1) {
    loop_ub = in4.size(0);
  } else {
    loop_ub = in5.size(0);
  }
  for (i = 0; i < loop_ub; i++) {
    double b_in2_re_tmp;
    double c_in2_re_tmp;
    double d_in2_re_tmp;
    double e_in2_re_tmp;
    int in2_re_tmp;
    in2_re_tmp = i * stride_1_0;
    b_in2_re_tmp = in3[in2_re_tmp].im;
    c_in2_re_tmp = in3[in2_re_tmp].re;
    in2_re_tmp = i * stride_3_0;
    d_in2_re_tmp = in5[in2_re_tmp].im;
    e_in2_re_tmp = in5[in2_re_tmp].re;
    in2_re_tmp = i * stride_2_0;
    b_in1[i].re =
        (in1[i * stride_0_0].re + (0.0 * c_in2_re_tmp - b_in2_re_tmp)) -
        (in4[in2_re_tmp].re + (0.0 * e_in2_re_tmp - d_in2_re_tmp));
    b_in1[i].im =
        (in1[i * stride_0_0].im + (0.0 * b_in2_re_tmp + c_in2_re_tmp)) -
        (in4[in2_re_tmp].im + (0.0 * d_in2_re_tmp + e_in2_re_tmp));
  }
  in1.set_size(b_in1.size(0));
  loop_ub = b_in1.size(0);
  for (i = 0; i < loop_ub; i++) {
    in1[i] = b_in1[i];
  }
}

//
// Arguments    : coder::array<double, 1U> &in1
//                const coder::array<double, 1U> &in2
//                const coder::array<double, 1U> &in3
//                const coder::array<double, 1U> &in4
//                const coder::array<double, 1U> &in5
// Return Type  : void
//
static void binary_expand_op(coder::array<double, 1U> &in1,
                             const coder::array<double, 1U> &in2,
                             const coder::array<double, 1U> &in3,
                             const coder::array<double, 1U> &in4,
                             const coder::array<double, 1U> &in5)
{
  coder::array<double, 1U> b_in2;
  int i;
  int loop_ub;
  int stride_0_0;
  int stride_1_0;
  int stride_2_0;
  int stride_3_0;
  int stride_4_0;
  if (in5.size(0) == 1) {
    i = in4.size(0);
  } else {
    i = in5.size(0);
  }
  if (in3.size(0) == 1) {
    stride_0_0 = in1.size(0);
  } else {
    stride_0_0 = in3.size(0);
  }
  if (i == 1) {
    if (stride_0_0 == 1) {
      i = in2.size(0);
    } else if (in3.size(0) == 1) {
      i = in1.size(0);
    } else {
      i = in3.size(0);
    }
  } else if (in5.size(0) == 1) {
    i = in4.size(0);
  } else {
    i = in5.size(0);
  }
  b_in2.set_size(i);
  stride_0_0 = (in2.size(0) != 1);
  stride_1_0 = (in1.size(0) != 1);
  stride_2_0 = (in3.size(0) != 1);
  stride_3_0 = (in4.size(0) != 1);
  stride_4_0 = (in5.size(0) != 1);
  if (in5.size(0) == 1) {
    i = in4.size(0);
  } else {
    i = in5.size(0);
  }
  if (i == 1) {
    if (in3.size(0) == 1) {
      i = in1.size(0);
    } else {
      i = in3.size(0);
    }
    if (i == 1) {
      loop_ub = in2.size(0);
    } else if (in3.size(0) == 1) {
      loop_ub = in1.size(0);
    } else {
      loop_ub = in3.size(0);
    }
  } else if (in5.size(0) == 1) {
    loop_ub = in4.size(0);
  } else {
    loop_ub = in5.size(0);
  }
  for (i = 0; i < loop_ub; i++) {
    b_in2[i] =
        in2[i * stride_0_0] * (in1[i * stride_1_0] / in3[i * stride_2_0]) +
        (in4[i * stride_3_0] + 1.0) / in5[i * stride_4_0];
  }
  in1.set_size(b_in2.size(0));
  loop_ub = b_in2.size(0);
  for (i = 0; i < loop_ub; i++) {
    in1[i] = b_in2[i];
  }
}

//
// Arguments    : coder::array<creal_T, 1U> &in1
//                int in2
//                const coder::array<creal_T, 1U> &in3
//                const coder::array<creal_T, 1U> &in4
// Return Type  : void
//
static void binary_expand_op(coder::array<creal_T, 1U> &in1, int in2,
                             const coder::array<creal_T, 1U> &in3,
                             const coder::array<creal_T, 1U> &in4)
{
  coder::array<creal_T, 1U> r;
  double d;
  int i;
  int loop_ub;
  int stride_0_0;
  int stride_1_0;
  int stride_2_0;
  d = 2.0 * (static_cast<double>(in2) + 1.0) - 1.0;
  if (in4.size(0) == 1) {
    i = in3.size(0);
  } else {
    i = in4.size(0);
  }
  if (i == 1) {
    i = in1.size(0);
  } else if (in4.size(0) == 1) {
    i = in3.size(0);
  } else {
    i = in4.size(0);
  }
  r.set_size(i);
  stride_0_0 = (in1.size(0) != 1);
  stride_1_0 = (in3.size(0) != 1);
  stride_2_0 = (in4.size(0) != 1);
  if (in4.size(0) == 1) {
    i = in3.size(0);
  } else {
    i = in4.size(0);
  }
  if (i == 1) {
    loop_ub = in1.size(0);
  } else if (in4.size(0) == 1) {
    loop_ub = in3.size(0);
  } else {
    loop_ub = in4.size(0);
  }
  for (i = 0; i < loop_ub; i++) {
    double b_in2_re_tmp;
    double c_in2_re_tmp;
    double in2_im;
    double in2_re;
    int in2_re_tmp;
    in2_re_tmp = i * stride_1_0;
    in2_re = (static_cast<double>(in2) + 1.0) + in3[in2_re_tmp].re;
    in2_im = in3[in2_re_tmp].im;
    in2_re_tmp = i * stride_2_0;
    b_in2_re_tmp = in4[in2_re_tmp].im;
    c_in2_re_tmp = in4[in2_re_tmp].re;
    r[i].re = d * in1[i * stride_0_0].re +
              (in2_re * c_in2_re_tmp - in2_im * b_in2_re_tmp);
    r[i].im = d * in1[i * stride_0_0].im +
              (in2_re * b_in2_re_tmp + in2_im * c_in2_re_tmp);
  }
  in1.set_size(r.size(0));
  loop_ub = r.size(0);
  for (i = 0; i < loop_ub; i++) {
    in1[i] = r[i];
  }
}

//
// Arguments    : coder::array<double, 1U> &in1
//                const coder::array<double, 1U> &in2
//                const coder::array<double, 1U> &in3
//                const coder::array<double, 1U> &in4
//                const coder::array<double, 1U> &in5
//                const coder::array<double, 1U> &in6
// Return Type  : void
//
static void binary_expand_op(coder::array<double, 1U> &in1,
                             const coder::array<double, 1U> &in2,
                             const coder::array<double, 1U> &in3,
                             const coder::array<double, 1U> &in4,
                             const coder::array<double, 1U> &in5,
                             const coder::array<double, 1U> &in6)
{
  int i;
  int loop_ub;
  int stride_0_0;
  int stride_1_0;
  int stride_2_0;
  int stride_3_0;
  int stride_4_0;
  if (in6.size(0) == 1) {
    i = in5.size(0);
  } else {
    i = in6.size(0);
  }
  if (in4.size(0) == 1) {
    stride_0_0 = in3.size(0);
  } else {
    stride_0_0 = in4.size(0);
  }
  if (i == 1) {
    if (stride_0_0 == 1) {
      i = in2.size(0);
    } else if (in4.size(0) == 1) {
      i = in3.size(0);
    } else {
      i = in4.size(0);
    }
  } else if (in6.size(0) == 1) {
    i = in5.size(0);
  } else {
    i = in6.size(0);
  }
  in1.set_size(i);
  stride_0_0 = (in2.size(0) != 1);
  stride_1_0 = (in3.size(0) != 1);
  stride_2_0 = (in4.size(0) != 1);
  stride_3_0 = (in5.size(0) != 1);
  stride_4_0 = (in6.size(0) != 1);
  if (in6.size(0) == 1) {
    i = in5.size(0);
  } else {
    i = in6.size(0);
  }
  if (i == 1) {
    if (in4.size(0) == 1) {
      i = in3.size(0);
    } else {
      i = in4.size(0);
    }
    if (i == 1) {
      loop_ub = in2.size(0);
    } else if (in4.size(0) == 1) {
      loop_ub = in3.size(0);
    } else {
      loop_ub = in4.size(0);
    }
  } else if (in6.size(0) == 1) {
    loop_ub = in5.size(0);
  } else {
    loop_ub = in6.size(0);
  }
  for (i = 0; i < loop_ub; i++) {
    in1[i] = in2[i * stride_0_0] * (in3[i * stride_1_0] / in4[i * stride_2_0]) +
             (1.0 - in5[i * stride_3_0]) / in6[i * stride_4_0];
  }
}

//
// Arguments    : coder::array<creal_T, 1U> &in1
//                const coder::array<double, 1U> &in2
//                const coder::array<creal_T, 1U> &in5
// Return Type  : void
//
static void binary_expand_op(coder::array<creal_T, 1U> &in1,
                             const coder::array<double, 1U> &in2,
                             const coder::array<creal_T, 1U> &in5)
{
  coder::array<creal_T, 1U> b_in2;
  int i;
  int loop_ub;
  int stride_0_0;
  int stride_1_0;
  int stride_2_0;
  if (in5.size(0) == 1) {
    if (in1.size(0) == 1) {
      i = in2.size(0);
    } else {
      i = in1.size(0);
    }
  } else {
    i = in5.size(0);
  }
  b_in2.set_size(i);
  stride_0_0 = (in2.size(0) != 1);
  stride_1_0 = (in1.size(0) != 1);
  stride_2_0 = (in5.size(0) != 1);
  if (in5.size(0) == 1) {
    if (in1.size(0) == 1) {
      loop_ub = in2.size(0);
    } else {
      loop_ub = in1.size(0);
    }
  } else {
    loop_ub = in5.size(0);
  }
  for (i = 0; i < loop_ub; i++) {
    double bi;
    double bim;
    double br;
    double brm;
    double in3_im;
    double in3_re;
    double in4_re;
    int br_tmp;
    br_tmp = i * stride_1_0;
    br = in1[br_tmp].re;
    bi = in1[br_tmp].im;
    if (bi == 0.0) {
      in3_re = -3.1415926535897931 / br;
      in3_im = 0.0;
    } else if (br == 0.0) {
      in3_re = 0.0;
      in3_im = -(-3.1415926535897931 / bi);
    } else {
      brm = std::abs(br);
      bim = std::abs(bi);
      if (brm > bim) {
        brm = bi / br;
        bim = br + brm * bi;
        in3_re = (brm * 0.0 + -3.1415926535897931) / bim;
        in3_im = (0.0 - brm * -3.1415926535897931) / bim;
      } else if (bim == brm) {
        if (br > 0.0) {
          br = 0.5;
        } else {
          br = -0.5;
        }
        if (bi > 0.0) {
          bim = 0.5;
        } else {
          bim = -0.5;
        }
        in3_re = (-3.1415926535897931 * br + 0.0 * bim) / brm;
        in3_im = (0.0 * br - -3.1415926535897931 * bim) / brm;
      } else {
        brm = br / bi;
        bim = bi + brm * br;
        in3_re = brm * -3.1415926535897931 / bim;
        in3_im = (brm * 0.0 - -3.1415926535897931) / bim;
      }
    }
    br_tmp = i * stride_2_0;
    br = in5[br_tmp].re;
    bi = in5[br_tmp].im;
    if (bi == 0.0) {
      in4_re = 1.0 / br;
      bim = 0.0;
    } else if (br == 0.0) {
      in4_re = 0.0;
      bim = -(1.0 / bi);
    } else {
      brm = std::abs(br);
      bim = std::abs(bi);
      if (brm > bim) {
        brm = bi / br;
        bim = br + brm * bi;
        in4_re = (brm * 0.0 + 1.0) / bim;
        bim = (0.0 - brm) / bim;
      } else if (bim == brm) {
        if (br > 0.0) {
          br = 0.5;
        } else {
          br = -0.5;
        }
        if (bi > 0.0) {
          bim = 0.5;
        } else {
          bim = -0.5;
        }
        in4_re = (br + 0.0 * bim) / brm;
        bim = (0.0 * br - bim) / brm;
      } else {
        brm = br / bi;
        bim = bi + brm * br;
        in4_re = brm / bim;
        bim = (brm * 0.0 - 1.0) / bim;
      }
    }
    b_in2[i].re = in2[i * stride_0_0] * in3_re - in4_re;
    b_in2[i].im = in2[i * stride_0_0] * in3_im - bim;
  }
  in1.set_size(b_in2.size(0));
  loop_ub = b_in2.size(0);
  for (i = 0; i < loop_ub; i++) {
    in1[i] = b_in2[i];
  }
}

//
// Arguments    : coder::array<double, 1U> &in1
//                const coder::array<creal_T, 1U> &in2
//                const coder::array<creal_T, 1U> &in3
// Return Type  : void
//
static void binary_expand_op(coder::array<double, 1U> &in1,
                             const coder::array<creal_T, 1U> &in2,
                             const coder::array<creal_T, 1U> &in3)
{
  coder::array<double, 1U> b_in1;
  int i;
  int loop_ub;
  int stride_0_0;
  int stride_1_0;
  int stride_2_0;
  if (in3.size(0) == 1) {
    i = in2.size(0);
  } else {
    i = in3.size(0);
  }
  if (i == 1) {
    i = in1.size(0);
  } else if (in3.size(0) == 1) {
    i = in2.size(0);
  } else {
    i = in3.size(0);
  }
  b_in1.set_size(i);
  stride_0_0 = (in1.size(0) != 1);
  stride_1_0 = (in2.size(0) != 1);
  stride_2_0 = (in3.size(0) != 1);
  if (in3.size(0) == 1) {
    i = in2.size(0);
  } else {
    i = in3.size(0);
  }
  if (i == 1) {
    loop_ub = in1.size(0);
  } else if (in3.size(0) == 1) {
    loop_ub = in2.size(0);
  } else {
    loop_ub = in3.size(0);
  }
  for (i = 0; i < loop_ub; i++) {
    double ai;
    double ar;
    double bi;
    double br;
    double in2_re;
    int ar_tmp;
    ar_tmp = i * stride_1_0;
    ar = in2[ar_tmp].re;
    ai = in2[ar_tmp].im;
    ar_tmp = i * stride_2_0;
    br = in3[ar_tmp].re;
    bi = in3[ar_tmp].im;
    if (bi == 0.0) {
      if (ai == 0.0) {
        in2_re = ar / br;
      } else if (ar == 0.0) {
        in2_re = 0.0;
      } else {
        in2_re = ar / br;
      }
    } else if (br == 0.0) {
      if (ar == 0.0) {
        in2_re = ai / bi;
      } else if (ai == 0.0) {
        in2_re = 0.0;
      } else {
        in2_re = ai / bi;
      }
    } else {
      double bim;
      in2_re = std::abs(br);
      bim = std::abs(bi);
      if (in2_re > bim) {
        in2_re = bi / br;
        in2_re = (ar + in2_re * ai) / (br + in2_re * bi);
      } else if (bim == in2_re) {
        if (br > 0.0) {
          br = 0.5;
        } else {
          br = -0.5;
        }
        if (bi > 0.0) {
          bi = 0.5;
        } else {
          bi = -0.5;
        }
        in2_re = (ar * br + ai * bi) / in2_re;
      } else {
        in2_re = br / bi;
        in2_re = (in2_re * ar + ai) / (bi + in2_re * br);
      }
    }
    b_in1[i] = -(-in1[i * stride_0_0] * in2_re);
  }
  in1.set_size(b_in1.size(0));
  loop_ub = b_in1.size(0);
  for (i = 0; i < loop_ub; i++) {
    in1[i] = b_in1[i];
  }
}

//
// Arguments    : coder::array<double, 1U> &in1
//                int in2
//                const double in3[351]
//                int in4
//                const coder::array<double, 2U> &in5
//                int in6
//                const coder::array<double, 2U> &in7
// Return Type  : void
//
static void binary_expand_op(coder::array<double, 1U> &in1, int in2,
                             const double in3[351], int in4,
                             const coder::array<double, 2U> &in5, int in6,
                             const coder::array<double, 2U> &in7)
{
  coder::array<double, 1U> b_in1;
  double b_in2;
  int b_loop_ub;
  int i;
  int loop_ub;
  int stride_0_0;
  int stride_1_0;
  int stride_2_0;
  b_in2 = (static_cast<double>(in2) + 1.0) * in3[in4];
  i = in5.size(0);
  loop_ub = in7.size(0);
  if (loop_ub == 1) {
    b_loop_ub = i;
  } else {
    b_loop_ub = loop_ub;
  }
  if (b_loop_ub == 1) {
    b_loop_ub = in1.size(0);
  } else if (loop_ub == 1) {
    b_loop_ub = i;
  } else {
    b_loop_ub = loop_ub;
  }
  b_in1.set_size(b_loop_ub);
  stride_0_0 = (in1.size(0) != 1);
  stride_1_0 = (i != 1);
  stride_2_0 = (loop_ub != 1);
  if (loop_ub == 1) {
    b_loop_ub = i;
  } else {
    b_loop_ub = loop_ub;
  }
  if (b_loop_ub == 1) {
    loop_ub = in1.size(0);
  } else if (loop_ub == 1) {
    loop_ub = i;
  }
  for (i = 0; i < loop_ub; i++) {
    b_in1[i] =
        in1[i * stride_0_0] + b_in2 * in5[i * stride_1_0 + in5.size(0) * in6] *
                                  in7[i * stride_2_0 + in7.size(0) * (in2 - 1)];
  }
  in1.set_size(b_in1.size(0));
  loop_ub = b_in1.size(0);
  for (i = 0; i < loop_ub; i++) {
    in1[i] = b_in1[i];
  }
}

//
// Arguments    : coder::array<double, 1U> &in1
//                int in2
//                const double in3[351]
//                int in4
//                const coder::array<double, 2U> &in5
//                const coder::array<double, 2U> &in6
//                int in7
// Return Type  : void
//
static void binary_expand_op(coder::array<double, 1U> &in1, int in2,
                             const double in3[351], int in4,
                             const coder::array<double, 2U> &in5,
                             const coder::array<double, 2U> &in6, int in7)
{
  coder::array<double, 1U> b_in1;
  double b_in2;
  int b_loop_ub;
  int i;
  int loop_ub;
  int stride_0_0;
  int stride_1_0;
  int stride_2_0;
  b_in2 = (static_cast<double>(in2) + 1.0) * in3[in4];
  i = in5.size(0);
  loop_ub = in6.size(0);
  if (loop_ub == 1) {
    b_loop_ub = i;
  } else {
    b_loop_ub = loop_ub;
  }
  if (b_loop_ub == 1) {
    b_loop_ub = in1.size(0);
  } else if (loop_ub == 1) {
    b_loop_ub = i;
  } else {
    b_loop_ub = loop_ub;
  }
  b_in1.set_size(b_loop_ub);
  stride_0_0 = (in1.size(0) != 1);
  stride_1_0 = (i != 1);
  stride_2_0 = (loop_ub != 1);
  if (loop_ub == 1) {
    b_loop_ub = i;
  } else {
    b_loop_ub = loop_ub;
  }
  if (b_loop_ub == 1) {
    loop_ub = in1.size(0);
  } else if (loop_ub == 1) {
    loop_ub = i;
  }
  for (i = 0; i < loop_ub; i++) {
    b_in1[i] = in1[i * stride_0_0] +
               b_in2 * in5[i * stride_1_0 + in5.size(0) * (in2 - 1)] *
                   in6[i * stride_2_0 + in6.size(0) * in7];
  }
  in1.set_size(b_in1.size(0));
  loop_ub = b_in1.size(0);
  for (i = 0; i < loop_ub; i++) {
    in1[i] = b_in1[i];
  }
}

//
// Arguments    : coder::array<double, 1U> &in1
//                const double in2[351]
//                int in3
//                const coder::array<double, 2U> &in4
//                int in5
//                const coder::array<double, 2U> &in6
//                int in7
// Return Type  : void
//
static void binary_expand_op(coder::array<double, 1U> &in1,
                             const double in2[351], int in3,
                             const coder::array<double, 2U> &in4, int in5,
                             const coder::array<double, 2U> &in6, int in7)
{
  coder::array<double, 1U> b_in1;
  double b_in2;
  int b_loop_ub;
  int i;
  int loop_ub;
  int stride_0_0;
  int stride_1_0;
  int stride_2_0;
  b_in2 = in2[in3];
  i = in4.size(0);
  loop_ub = in6.size(0);
  if (loop_ub == 1) {
    b_loop_ub = i;
  } else {
    b_loop_ub = loop_ub;
  }
  if (b_loop_ub == 1) {
    b_loop_ub = in1.size(0);
  } else if (loop_ub == 1) {
    b_loop_ub = i;
  } else {
    b_loop_ub = loop_ub;
  }
  b_in1.set_size(b_loop_ub);
  stride_0_0 = (in1.size(0) != 1);
  stride_1_0 = (i != 1);
  stride_2_0 = (loop_ub != 1);
  if (loop_ub == 1) {
    b_loop_ub = i;
  } else {
    b_loop_ub = loop_ub;
  }
  if (b_loop_ub == 1) {
    loop_ub = in1.size(0);
  } else if (loop_ub == 1) {
    loop_ub = i;
  }
  for (i = 0; i < loop_ub; i++) {
    b_in1[i] =
        in1[i * stride_0_0] + b_in2 * in4[i * stride_1_0 + in4.size(0) * in5] *
                                  in6[i * stride_2_0 + in6.size(0) * in7];
  }
  in1.set_size(b_in1.size(0));
  loop_ub = b_in1.size(0);
  for (i = 0; i < loop_ub; i++) {
    in1[i] = b_in1[i];
  }
}

//
// Arguments    : coder::array<double, 1U> &in1
//                const coder::array<double, 1U> &in2
//                const coder::array<double, 1U> &in3
//                const coder::array<double, 1U> &in4
// Return Type  : void
//
static void binary_expand_op(coder::array<double, 1U> &in1,
                             const coder::array<double, 1U> &in2,
                             const coder::array<double, 1U> &in3,
                             const coder::array<double, 1U> &in4)
{
  coder::array<double, 1U> r;
  int i;
  int loop_ub;
  int stride_0_0;
  int stride_1_0;
  int stride_2_0;
  int stride_3_0;
  if (in3.size(0) == 1) {
    i = in2.size(0);
  } else {
    i = in3.size(0);
  }
  if (in4.size(0) == 1) {
    if (i == 1) {
      i = in1.size(0);
    } else if (in3.size(0) == 1) {
      i = in2.size(0);
    } else {
      i = in3.size(0);
    }
  } else {
    i = in4.size(0);
  }
  r.set_size(i);
  stride_0_0 = (in1.size(0) != 1);
  stride_1_0 = (in2.size(0) != 1);
  stride_2_0 = (in3.size(0) != 1);
  stride_3_0 = (in4.size(0) != 1);
  if (in4.size(0) == 1) {
    if (in3.size(0) == 1) {
      i = in2.size(0);
    } else {
      i = in3.size(0);
    }
    if (i == 1) {
      loop_ub = in1.size(0);
    } else if (in3.size(0) == 1) {
      loop_ub = in2.size(0);
    } else {
      loop_ub = in3.size(0);
    }
  } else {
    loop_ub = in4.size(0);
  }
  for (i = 0; i < loop_ub; i++) {
    r[i] = 3.0 *
           (in1[i * stride_0_0] * (in2[i * stride_1_0] - in3[i * stride_2_0]) +
            in4[i * stride_3_0]);
  }
  in1.set_size(r.size(0));
  loop_ub = r.size(0);
  for (i = 0; i < loop_ub; i++) {
    in1[i] = r[i];
  }
}

//
// Arguments    : coder::array<creal_T, 1U> &in1
//                const coder::array<double, 1U> &in2
//                const coder::array<creal_T, 1U> &in3
//                const coder::array<creal_T, 1U> &in5
//                const coder::array<creal_T, 1U> &in6
//                const coder::array<creal_T, 1U> &in7
//                const coder::array<creal_T, 1U> &in8
//                const coder::array<creal_T, 1U> &in9
//                const coder::array<creal_T, 1U> &in10
//                const coder::array<double, 1U> &in12
//                const coder::array<creal_T, 1U> &in13
// Return Type  : void
//
static void binary_expand_op(
    coder::array<creal_T, 1U> &in1, const coder::array<double, 1U> &in2,
    const coder::array<creal_T, 1U> &in3, const coder::array<creal_T, 1U> &in5,
    const coder::array<creal_T, 1U> &in6, const coder::array<creal_T, 1U> &in7,
    const coder::array<creal_T, 1U> &in8, const coder::array<creal_T, 1U> &in9,
    const coder::array<creal_T, 1U> &in10, const coder::array<double, 1U> &in12,
    const coder::array<creal_T, 1U> &in13)
{
  coder::array<creal_T, 1U> b_in1;
  int br_tmp;
  int i;
  int i1;
  int i2;
  int in7_re_tmp;
  int loop_ub;
  int stride_0_0;
  int stride_10_0;
  int stride_11_0;
  int stride_12_0;
  int stride_13_0;
  int stride_1_0;
  int stride_2_0;
  int stride_3_0;
  int stride_4_0;
  int stride_5_0;
  int stride_6_0;
  int stride_7_0;
  int stride_8_0;
  int stride_9_0;
  if (in13.size(0) == 1) {
    i = in10.size(0);
  } else {
    i = in13.size(0);
  }
  if (in12.size(0) == 1) {
    i1 = in10.size(0);
  } else {
    i1 = in12.size(0);
  }
  if (i == 1) {
    if (i1 == 1) {
      i = in9.size(0);
    } else if (in12.size(0) == 1) {
      i = in10.size(0);
    } else {
      i = in12.size(0);
    }
  } else if (in13.size(0) == 1) {
    i = in10.size(0);
  } else {
    i = in13.size(0);
  }
  if (in13.size(0) == 1) {
    i1 = in10.size(0);
  } else {
    i1 = in13.size(0);
  }
  if (in12.size(0) == 1) {
    i2 = in10.size(0);
  } else {
    i2 = in12.size(0);
  }
  if (i == 1) {
    i = in8.size(0);
  } else if (i1 == 1) {
    if (i2 == 1) {
      i = in9.size(0);
    } else if (in12.size(0) == 1) {
      i = in10.size(0);
    } else {
      i = in12.size(0);
    }
  } else if (in13.size(0) == 1) {
    i = in10.size(0);
  } else {
    i = in13.size(0);
  }
  if (in6.size(0) == 1) {
    i1 = in7.size(0);
    i2 = in5.size(0);
  } else {
    i1 = in6.size(0);
    i2 = in6.size(0);
  }
  if (i1 == 1) {
    if (i2 == 1) {
      i1 = in3.size(0);
    } else if (in6.size(0) == 1) {
      i1 = in5.size(0);
    } else {
      i1 = in6.size(0);
    }
  } else if (in6.size(0) == 1) {
    i1 = in7.size(0);
  } else {
    i1 = in6.size(0);
  }
  if (in6.size(0) == 1) {
    i2 = in7.size(0);
    loop_ub = in5.size(0);
  } else {
    i2 = in6.size(0);
    loop_ub = in6.size(0);
  }
  if (i1 == 1) {
    i1 = in2.size(0);
  } else if (i2 == 1) {
    if (loop_ub == 1) {
      i1 = in3.size(0);
    } else if (in6.size(0) == 1) {
      i1 = in5.size(0);
    } else {
      i1 = in6.size(0);
    }
  } else if (in6.size(0) == 1) {
    i1 = in7.size(0);
  } else {
    i1 = in6.size(0);
  }
  if (in6.size(0) == 1) {
    i2 = in7.size(0);
    loop_ub = in5.size(0);
  } else {
    i2 = in6.size(0);
    loop_ub = in6.size(0);
  }
  if (i2 == 1) {
    if (loop_ub == 1) {
      i2 = in3.size(0);
    } else if (in6.size(0) == 1) {
      i2 = in5.size(0);
    } else {
      i2 = in6.size(0);
    }
  } else if (in6.size(0) == 1) {
    i2 = in7.size(0);
  } else {
    i2 = in6.size(0);
  }
  if (in6.size(0) == 1) {
    loop_ub = in7.size(0);
    br_tmp = in5.size(0);
  } else {
    loop_ub = in6.size(0);
    br_tmp = in6.size(0);
  }
  if (in13.size(0) == 1) {
    in7_re_tmp = in10.size(0);
  } else {
    in7_re_tmp = in13.size(0);
  }
  if (in12.size(0) == 1) {
    stride_0_0 = in10.size(0);
  } else {
    stride_0_0 = in12.size(0);
  }
  if (in7_re_tmp == 1) {
    if (stride_0_0 == 1) {
      in7_re_tmp = in9.size(0);
    } else if (in12.size(0) == 1) {
      in7_re_tmp = in10.size(0);
    } else {
      in7_re_tmp = in12.size(0);
    }
  } else if (in13.size(0) == 1) {
    in7_re_tmp = in10.size(0);
  } else {
    in7_re_tmp = in13.size(0);
  }
  if (in13.size(0) == 1) {
    stride_0_0 = in10.size(0);
  } else {
    stride_0_0 = in13.size(0);
  }
  if (in12.size(0) == 1) {
    stride_1_0 = in10.size(0);
  } else {
    stride_1_0 = in12.size(0);
  }
  if (i == 1) {
    if (i1 == 1) {
      i = in1.size(0);
    } else if (i2 == 1) {
      i = in2.size(0);
    } else if (loop_ub == 1) {
      if (br_tmp == 1) {
        i = in3.size(0);
      } else if (in6.size(0) == 1) {
        i = in5.size(0);
      } else {
        i = in6.size(0);
      }
    } else if (in6.size(0) == 1) {
      i = in7.size(0);
    } else {
      i = in6.size(0);
    }
  } else if (in7_re_tmp == 1) {
    i = in8.size(0);
  } else if (stride_0_0 == 1) {
    if (stride_1_0 == 1) {
      i = in9.size(0);
    } else if (in12.size(0) == 1) {
      i = in10.size(0);
    } else {
      i = in12.size(0);
    }
  } else if (in13.size(0) == 1) {
    i = in10.size(0);
  } else {
    i = in13.size(0);
  }
  b_in1.set_size(i);
  stride_0_0 = (in1.size(0) != 1);
  stride_1_0 = (in2.size(0) != 1);
  stride_2_0 = (in3.size(0) != 1);
  stride_3_0 = (in5.size(0) != 1);
  stride_4_0 = (in6.size(0) != 1);
  stride_5_0 = (in7.size(0) != 1);
  stride_6_0 = (in6.size(0) != 1);
  stride_7_0 = (in8.size(0) != 1);
  stride_8_0 = (in9.size(0) != 1);
  stride_9_0 = (in10.size(0) != 1);
  stride_10_0 = (in12.size(0) != 1);
  stride_11_0 = (in12.size(0) != 1);
  stride_12_0 = (in10.size(0) != 1);
  stride_13_0 = (in13.size(0) != 1);
  if (in13.size(0) == 1) {
    i = in10.size(0);
  } else {
    i = in13.size(0);
  }
  if (in12.size(0) == 1) {
    i1 = in10.size(0);
  } else {
    i1 = in12.size(0);
  }
  if (i == 1) {
    if (i1 == 1) {
      i = in9.size(0);
    } else if (in12.size(0) == 1) {
      i = in10.size(0);
    } else {
      i = in12.size(0);
    }
  } else if (in13.size(0) == 1) {
    i = in10.size(0);
  } else {
    i = in13.size(0);
  }
  if (in13.size(0) == 1) {
    i1 = in10.size(0);
  } else {
    i1 = in13.size(0);
  }
  if (in12.size(0) == 1) {
    i2 = in10.size(0);
  } else {
    i2 = in12.size(0);
  }
  if (i == 1) {
    i = in8.size(0);
  } else if (i1 == 1) {
    if (i2 == 1) {
      i = in9.size(0);
    } else if (in12.size(0) == 1) {
      i = in10.size(0);
    } else {
      i = in12.size(0);
    }
  } else if (in13.size(0) == 1) {
    i = in10.size(0);
  } else {
    i = in13.size(0);
  }
  if (i == 1) {
    if (in6.size(0) == 1) {
      i = in7.size(0);
      i1 = in5.size(0);
    } else {
      i = in6.size(0);
      i1 = in6.size(0);
    }
    if (i == 1) {
      if (i1 == 1) {
        i = in3.size(0);
      } else if (in6.size(0) == 1) {
        i = in5.size(0);
      } else {
        i = in6.size(0);
      }
    } else if (in6.size(0) == 1) {
      i = in7.size(0);
    } else {
      i = in6.size(0);
    }
    if (in6.size(0) == 1) {
      i1 = in7.size(0);
      i2 = in5.size(0);
    } else {
      i1 = in6.size(0);
      i2 = in6.size(0);
    }
    if (i == 1) {
      i = in2.size(0);
    } else if (i1 == 1) {
      if (i2 == 1) {
        i = in3.size(0);
      } else if (in6.size(0) == 1) {
        i = in5.size(0);
      } else {
        i = in6.size(0);
      }
    } else if (in6.size(0) == 1) {
      i = in7.size(0);
    } else {
      i = in6.size(0);
    }
    if (i == 1) {
      loop_ub = in1.size(0);
    } else {
      if (in6.size(0) == 1) {
        i = in7.size(0);
        i1 = in5.size(0);
      } else {
        i = in6.size(0);
        i1 = in6.size(0);
      }
      if (i == 1) {
        if (i1 == 1) {
          i = in3.size(0);
        } else if (in6.size(0) == 1) {
          i = in5.size(0);
        } else {
          i = in6.size(0);
        }
      } else if (in6.size(0) == 1) {
        i = in7.size(0);
      } else {
        i = in6.size(0);
      }
      if (i == 1) {
        loop_ub = in2.size(0);
      } else {
        if (in6.size(0) == 1) {
          i = in7.size(0);
        } else {
          i = in6.size(0);
        }
        if (i == 1) {
          if (in6.size(0) == 1) {
            i = in5.size(0);
          } else {
            i = in6.size(0);
          }
          if (i == 1) {
            loop_ub = in3.size(0);
          } else if (in6.size(0) == 1) {
            loop_ub = in5.size(0);
          } else {
            loop_ub = in6.size(0);
          }
        } else if (in6.size(0) == 1) {
          loop_ub = in7.size(0);
        } else {
          loop_ub = in6.size(0);
        }
      }
    }
  } else {
    if (in13.size(0) == 1) {
      i = in10.size(0);
    } else {
      i = in13.size(0);
    }
    if (in12.size(0) == 1) {
      i1 = in10.size(0);
    } else {
      i1 = in12.size(0);
    }
    if (i == 1) {
      if (i1 == 1) {
        i = in9.size(0);
      } else if (in12.size(0) == 1) {
        i = in10.size(0);
      } else {
        i = in12.size(0);
      }
    } else if (in13.size(0) == 1) {
      i = in10.size(0);
    } else {
      i = in13.size(0);
    }
    if (i == 1) {
      loop_ub = in8.size(0);
    } else {
      if (in13.size(0) == 1) {
        i = in10.size(0);
      } else {
        i = in13.size(0);
      }
      if (i == 1) {
        if (in12.size(0) == 1) {
          i = in10.size(0);
        } else {
          i = in12.size(0);
        }
        if (i == 1) {
          loop_ub = in9.size(0);
        } else if (in12.size(0) == 1) {
          loop_ub = in10.size(0);
        } else {
          loop_ub = in12.size(0);
        }
      } else if (in13.size(0) == 1) {
        loop_ub = in10.size(0);
      } else {
        loop_ub = in13.size(0);
      }
    }
  }
  for (i = 0; i < loop_ub; i++) {
    double b_in7_re_tmp;
    double bi;
    double br;
    double brm;
    double c_in7_re_tmp;
    double d_in7_re_tmp;
    double in10_re;
    double in2_im;
    double in2_re;
    double in2_re_tmp;
    double in4_im;
    double in4_re;
    br_tmp = i * stride_3_0;
    br = in5[br_tmp].re;
    bi = in5[br_tmp].im;
    if (bi == 0.0) {
      in4_re = 1.0 / br;
      in4_im = 0.0;
    } else if (br == 0.0) {
      in4_re = 0.0;
      in4_im = -(1.0 / bi);
    } else {
      brm = std::abs(br);
      in4_im = std::abs(bi);
      if (brm > in4_im) {
        brm = bi / br;
        in4_im = br + brm * bi;
        in4_re = (brm * 0.0 + 1.0) / in4_im;
        in4_im = (0.0 - brm) / in4_im;
      } else if (in4_im == brm) {
        if (br > 0.0) {
          br = 0.5;
        } else {
          br = -0.5;
        }
        if (bi > 0.0) {
          in4_im = 0.5;
        } else {
          in4_im = -0.5;
        }
        in4_re = (br + 0.0 * in4_im) / brm;
        in4_im = (0.0 * br - in4_im) / brm;
      } else {
        brm = br / bi;
        in4_im = bi + brm * br;
        in4_re = brm / in4_im;
        in4_im = (brm * 0.0 - 1.0) / in4_im;
      }
    }
    br_tmp = i * stride_4_0;
    in4_re += in6[br_tmp].re;
    in4_im += in6[br_tmp].im;
    br_tmp = i * stride_2_0;
    br = in3[br_tmp].re;
    bi = in3[br_tmp].im;
    br_tmp = i * stride_5_0;
    in7_re_tmp = i * stride_6_0;
    brm = in7[br_tmp].re;
    b_in7_re_tmp = in6[in7_re_tmp].im;
    c_in7_re_tmp = in7[br_tmp].im;
    d_in7_re_tmp = in6[in7_re_tmp].re;
    in2_re_tmp = in2[i * stride_1_0];
    in2_re = in2_re_tmp * ((br * in4_re - bi * in4_im) -
                           (brm * d_in7_re_tmp - c_in7_re_tmp * b_in7_re_tmp));
    in2_im = in2_re_tmp * ((br * in4_im + bi * in4_re) -
                           (brm * b_in7_re_tmp + c_in7_re_tmp * d_in7_re_tmp));
    br_tmp = i * stride_9_0;
    brm = in10[br_tmp].re;
    b_in7_re_tmp = in10[br_tmp].im;
    in4_im = in12[i * stride_10_0];
    br = 2.0 * in12[i * stride_11_0] + 1.0;
    in10_re = br * (in4_im * (brm * 0.0 - b_in7_re_tmp * 2.0));
    c_in7_re_tmp = br * (in4_im * (brm * 2.0 + b_in7_re_tmp * 0.0));
    br_tmp = i * stride_8_0;
    d_in7_re_tmp = in9[br_tmp].re;
    in2_re_tmp = in9[br_tmp].im;
    br_tmp = i * stride_13_0;
    in4_im = -in13[br_tmp].re;
    br = -in13[br_tmp].im;
    if (br == 0.0) {
      bi = in4_im / 3.1415926535897931;
      br = 0.0;
    } else if (in4_im == 0.0) {
      bi = 0.0;
      br /= 3.1415926535897931;
    } else {
      bi = in4_im / 3.1415926535897931;
      br /= 3.1415926535897931;
    }
    br_tmp = i * stride_12_0;
    brm = in10[br_tmp].re;
    b_in7_re_tmp = in10[br_tmp].im;
    in4_re = (d_in7_re_tmp * in10_re - in2_re_tmp * c_in7_re_tmp) +
             (brm * bi - b_in7_re_tmp * br);
    in4_im = (d_in7_re_tmp * c_in7_re_tmp + in2_re_tmp * in10_re) +
             (brm * br + b_in7_re_tmp * bi);
    br_tmp = i * stride_7_0;
    br = in8[br_tmp].re;
    brm = in8[br_tmp].im;
    b_in1[i].re =
        (in1[i * stride_0_0].re * in2_re - in1[i * stride_0_0].im * in2_im) +
        (br * in4_re - brm * in4_im);
    b_in1[i].im =
        (in1[i * stride_0_0].re * in2_im + in1[i * stride_0_0].im * in2_re) +
        (br * in4_im + brm * in4_re);
  }
  in1.set_size(b_in1.size(0));
  loop_ub = b_in1.size(0);
  for (i = 0; i < loop_ub; i++) {
    in1[i] = b_in1[i];
  }
}

//
// Arguments    : const ::coder::array<double, 1U> &x
//                const ::coder::array<double, 1U> &y
//                ::coder::array<double, 1U> &a
//                ::coder::array<double, 1U> &dadx
//                ::coder::array<double, 1U> &dady
// Return Type  : void
//
namespace coder {
namespace matlabshared {
namespace tracking {
namespace internal {
namespace scenario {
static void fetchAgrad(const ::coder::array<double, 1U> &x,
                       const ::coder::array<double, 1U> &y,
                       ::coder::array<double, 1U> &a,
                       ::coder::array<double, 1U> &dadx,
                       ::coder::array<double, 1U> &dady)
{
  array<double, 2U> cumr;
  array<double, 2U> cums;
  array<double, 2U> varargin_2;
  array<double, 1U> dadr;
  array<double, 1U> dads;
  array<double, 1U> u;
  array<double, 1U> v;
  double varargin_1;
  int i;
  int ibcol;
  int loop_ub;
  int n;
  int nrows;
  signed char input_sizes_idx_1;
  signed char sizes_idx_1;
  bool empty_non_axis_sizes;
  if (x.size(0) == y.size(0)) {
    u.set_size(x.size(0));
    loop_ub = x.size(0);
    for (i = 0; i < loop_ub; i++) {
      u[i] = x[i] - y[i];
    }
    v.set_size(x.size(0));
    loop_ub = x.size(0);
    for (i = 0; i < loop_ub; i++) {
      v[i] = x[i] + y[i];
    }
  } else {
    minus(u, x, y);
    plus(v, x, y);
  }
  n = 350;
  dadr.set_size(u.size(0));
  loop_ub = u.size(0);
  for (i = 0; i < loop_ub; i++) {
    varargin_1 = u[i];
    dadr[i] = varargin_1 * varargin_1;
  }
  varargin_2.set_size(dadr.size(0), 25);
  nrows = dadr.size(0);
  for (loop_ub = 0; loop_ub < 25; loop_ub++) {
    ibcol = loop_ub * nrows;
    for (int k{0}; k < nrows; k++) {
      varargin_2[ibcol + k] = dadr[k];
    }
  }
  if (x.size(0) != 0) {
    nrows = x.size(0);
  } else if (varargin_2.size(0) != 0) {
    nrows = varargin_2.size(0);
  } else {
    nrows = x.size(0);
  }
  empty_non_axis_sizes = (nrows == 0);
  if (empty_non_axis_sizes || (x.size(0) != 0)) {
    input_sizes_idx_1 = 1;
  } else {
    input_sizes_idx_1 = 0;
  }
  if (empty_non_axis_sizes || (varargin_2.size(0) != 0)) {
    sizes_idx_1 = 25;
  } else {
    sizes_idx_1 = 0;
  }
  cumr.set_size(nrows, input_sizes_idx_1 + sizes_idx_1);
  loop_ub = input_sizes_idx_1;
  for (i = 0; i < loop_ub; i++) {
    for (ibcol = 0; ibcol < nrows; ibcol++) {
      cumr[ibcol] = 1.0;
    }
  }
  loop_ub = sizes_idx_1;
  for (i = 0; i < loop_ub; i++) {
    for (ibcol = 0; ibcol < nrows; ibcol++) {
      cumr[ibcol + cumr.size(0) * (i + input_sizes_idx_1)] =
          varargin_2[ibcol + nrows * i];
    }
  }
  if ((cumr.size(0) != 0) && (cumr.size(1) != 0)) {
    i = cumr.size(1);
    for (int k{0}; k <= i - 2; k++) {
      ibcol = cumr.size(0);
      for (nrows = 0; nrows < ibcol; nrows++) {
        cumr[nrows + cumr.size(0) * (k + 1)] =
            cumr[nrows + cumr.size(0) * k] *
            cumr[nrows + cumr.size(0) * (k + 1)];
      }
    }
  }
  dadr.set_size(v.size(0));
  loop_ub = v.size(0);
  for (i = 0; i < loop_ub; i++) {
    varargin_1 = v[i];
    dadr[i] = varargin_1 * varargin_1;
  }
  varargin_2.set_size(dadr.size(0), 25);
  nrows = dadr.size(0);
  for (loop_ub = 0; loop_ub < 25; loop_ub++) {
    ibcol = loop_ub * nrows;
    for (int k{0}; k < nrows; k++) {
      varargin_2[ibcol + k] = dadr[k];
    }
  }
  if (x.size(0) != 0) {
    nrows = x.size(0);
  } else if (varargin_2.size(0) != 0) {
    nrows = varargin_2.size(0);
  } else {
    nrows = x.size(0);
  }
  empty_non_axis_sizes = (nrows == 0);
  if (empty_non_axis_sizes || (x.size(0) != 0)) {
    input_sizes_idx_1 = 1;
  } else {
    input_sizes_idx_1 = 0;
  }
  if (empty_non_axis_sizes || (varargin_2.size(0) != 0)) {
    sizes_idx_1 = 25;
  } else {
    sizes_idx_1 = 0;
  }
  cums.set_size(nrows, input_sizes_idx_1 + sizes_idx_1);
  loop_ub = input_sizes_idx_1;
  for (i = 0; i < loop_ub; i++) {
    for (ibcol = 0; ibcol < nrows; ibcol++) {
      cums[ibcol] = 1.0;
    }
  }
  loop_ub = sizes_idx_1;
  for (i = 0; i < loop_ub; i++) {
    for (ibcol = 0; ibcol < nrows; ibcol++) {
      cums[ibcol + cums.size(0) * (i + input_sizes_idx_1)] =
          varargin_2[ibcol + nrows * i];
    }
  }
  if ((cums.size(0) != 0) && (cums.size(1) != 0)) {
    i = cums.size(1);
    for (int k{0}; k <= i - 2; k++) {
      ibcol = cums.size(0);
      for (nrows = 0; nrows < ibcol; nrows++) {
        cums[nrows + cums.size(0) * (k + 1)] =
            cums[nrows + cums.size(0) * k] *
            cums[nrows + cums.size(0) * (k + 1)];
      }
    }
  }
  a.set_size(x.size(0));
  loop_ub = x.size(0);
  for (i = 0; i < loop_ub; i++) {
    a[i] = 0.0;
  }
  dadr.set_size(x.size(0));
  loop_ub = x.size(0);
  for (i = 0; i < loop_ub; i++) {
    dadr[i] = 0.0;
  }
  dads.set_size(x.size(0));
  loop_ub = x.size(0);
  for (i = 0; i < loop_ub; i++) {
    dads[i] = 0.0;
  }
  nrows = 0;
  ibcol = 0;
  while (n + 1 > 0) {
    if (cumr.size(0) == 1) {
      i = cums.size(0);
    } else {
      i = cumr.size(0);
    }
    if ((cumr.size(0) == cums.size(0)) && (a.size(0) == i)) {
      loop_ub = a.size(0);
      for (i = 0; i < loop_ub; i++) {
        a[i] = a[i] + dv[n] * cumr[i + cumr.size(0) * nrows] *
                          cums[i + cums.size(0) * ibcol];
      }
    } else {
      binary_expand_op(a, dv, n, cumr, nrows, cums, ibcol);
    }
    if (nrows > 0) {
      if (cumr.size(0) == 1) {
        i = cums.size(0);
      } else {
        i = cumr.size(0);
      }
      if ((cumr.size(0) == cums.size(0)) && (dadr.size(0) == i)) {
        varargin_1 = (static_cast<double>(nrows) + 1.0) * dv[n];
        loop_ub = dadr.size(0);
        for (i = 0; i < loop_ub; i++) {
          dadr[i] = dadr[i] + varargin_1 *
                                  cumr[i + cumr.size(0) * (nrows - 1)] *
                                  cums[i + cums.size(0) * ibcol];
        }
      } else {
        binary_expand_op(dadr, nrows, dv, n, cumr, cums, ibcol);
      }
    }
    if (ibcol > 0) {
      if (cumr.size(0) == 1) {
        i = cums.size(0);
      } else {
        i = cumr.size(0);
      }
      if ((cumr.size(0) == cums.size(0)) && (dads.size(0) == i)) {
        varargin_1 = (static_cast<double>(ibcol) + 1.0) * dv[n];
        loop_ub = dads.size(0);
        for (i = 0; i < loop_ub; i++) {
          dads[i] = dads[i] + varargin_1 * cumr[i + cumr.size(0) * nrows] *
                                  cums[i + cums.size(0) * (ibcol - 1)];
        }
      } else {
        binary_expand_op(dads, ibcol, dv, n, cumr, nrows, cums);
      }
    }
    ibcol++;
    if (nrows + ibcol > 25) {
      nrows++;
      ibcol = 0;
    }
    n--;
  }
  if (dads.size(0) == v.size(0)) {
    loop_ub = dads.size(0);
    for (i = 0; i < loop_ub; i++) {
      dads[i] = dads[i] * v[i];
    }
  } else {
    times(dads, v);
  }
  if (dadr.size(0) == u.size(0)) {
    loop_ub = dadr.size(0);
    for (i = 0; i < loop_ub; i++) {
      dadr[i] = dadr[i] * u[i];
    }
  } else {
    times(dadr, u);
  }
  dady.set_size(v.size(0));
  loop_ub = v.size(0);
  for (i = 0; i < loop_ub; i++) {
    dady[i] = 2.0 * v[i];
  }
  if (dads.size(0) == 1) {
    i = dadr.size(0);
  } else {
    i = dads.size(0);
  }
  if (dady.size(0) == 1) {
    if (dads.size(0) == 1) {
      n = dadr.size(0);
    } else {
      n = dads.size(0);
    }
  } else {
    n = dady.size(0);
  }
  if ((dads.size(0) == dadr.size(0)) && (dady.size(0) == i) &&
      (n == a.size(0))) {
    dadx.set_size(dady.size(0));
    loop_ub = dady.size(0);
    for (i = 0; i < loop_ub; i++) {
      dadx[i] = 3.0 * (dady[i] * (dads[i] + dadr[i]) + a[i]);
    }
  } else {
    f_binary_expand_op(dadx, dady, dads, dadr, a);
  }
  if (dads.size(0) == 1) {
    i = dadr.size(0);
  } else {
    i = dads.size(0);
  }
  if (dady.size(0) == 1) {
    if (dads.size(0) == 1) {
      n = dadr.size(0);
    } else {
      n = dads.size(0);
    }
  } else {
    n = dady.size(0);
  }
  if ((dads.size(0) == dadr.size(0)) && (dady.size(0) == i) &&
      (n == a.size(0))) {
    loop_ub = dady.size(0);
    for (i = 0; i < loop_ub; i++) {
      dady[i] = 3.0 * (dady[i] * (dads[i] - dadr[i]) + a[i]);
    }
  } else {
    binary_expand_op(dady, dads, dadr, a);
  }
  if (v.size(0) == a.size(0)) {
    a.set_size(v.size(0));
    loop_ub = v.size(0);
    for (i = 0; i < loop_ub; i++) {
      a[i] = 3.0 * v[i] * a[i];
    }
  } else {
    e_binary_expand_op(a, v);
  }
}

//
// Arguments    : const ::coder::array<double, 1U> &a
//                const ::coder::array<double, 1U> &d
//                const ::coder::array<double, 1U> &c
//                ::coder::array<creal_T, 1U> &rsfa
//                ::coder::array<creal_T, 1U> &drsfa
// Return Type  : void
//
static void fresnelgLargea1(const ::coder::array<double, 1U> &a,
                            const ::coder::array<double, 1U> &d,
                            const ::coder::array<double, 1U> &c,
                            ::coder::array<creal_T, 1U> &rsfa,
                            ::coder::array<creal_T, 1U> &drsfa)
{
  array<creal_T, 1U> a1;
  array<creal_T, 1U> a2;
  array<creal_T, 1U> b;
  array<creal_T, 1U> b_b;
  array<creal_T, 1U> b_r;
  array<creal_T, 1U> b_x;
  array<creal_T, 1U> c_r;
  array<creal_T, 1U> da2;
  array<creal_T, 1U> fa;
  array<creal_T, 1U> s;
  array<creal_T, 1U> x;
  array<double, 1U> b_a1;
  array<double, 1U> b_y_tmp;
  array<double, 1U> r1;
  array<double, 1U> ratio;
  array<double, 1U> y_tmp;
  creal_T varargin_1;
  creal_T varargout_1;
  double ar;
  double b_re;
  double bi;
  double br;
  double brm;
  double im;
  double r;
  double re;
  double re_tmp;
  double sgnbr;
  int i;
  int i1;
  int i10;
  int i2;
  int i3;
  int i4;
  int i5;
  int i6;
  int i7;
  int i8;
  int i9;
  int k;
  int nx;
  y_tmp.set_size(a.size(0));
  nx = a.size(0);
  for (k = 0; k < nx; k++) {
    y_tmp[k] = 2.0 * a[k];
  }
  a1.set_size(y_tmp.size(0));
  nx = y_tmp.size(0);
  for (k = 0; k < nx; k++) {
    a1[k].re = y_tmp[k] / 3.1415926535897931;
    a1[k].im = 0.0;
  }
  nx = a1.size(0);
  for (k = 0; k < nx; k++) {
    ::coder::internal::scalar::b_sqrt(&a1[k]);
  }
  b_y_tmp.set_size(a.size(0));
  nx = a.size(0);
  for (k = 0; k < nx; k++) {
    b_y_tmp[k] = 6.2831853071795862 * a[k];
  }
  if (d.size(0) == a.size(0)) {
    ratio.set_size(d.size(0));
    nx = d.size(0);
    for (k = 0; k < nx; k++) {
      ratio[k] = d[k] - a[k];
    }
  } else {
    minus(ratio, d, a);
  }
  a2.set_size(b_y_tmp.size(0));
  nx = b_y_tmp.size(0);
  for (k = 0; k < nx; k++) {
    a2[k].re = b_y_tmp[k];
    a2[k].im = 0.0;
  }
  nx = a2.size(0);
  for (k = 0; k < nx; k++) {
    ::coder::internal::scalar::b_sqrt(&a2[k]);
  }
  if (ratio.size(0) == a2.size(0)) {
    a2.set_size(ratio.size(0));
    nx = ratio.size(0);
    for (k = 0; k < nx; k++) {
      ar = ratio[k];
      br = a2[k].re;
      bi = a2[k].im;
      if (bi == 0.0) {
        re = ar / br;
        im = 0.0;
      } else if (br == 0.0) {
        if (ar == 0.0) {
          re = 0.0 / bi;
          im = 0.0;
        } else {
          re = 0.0;
          im = -(ar / bi);
        }
      } else {
        brm = std::abs(br);
        r = std::abs(bi);
        if (brm > r) {
          brm = bi / br;
          r = br + brm * bi;
          re = (ar + brm * 0.0) / r;
          im = (0.0 - brm * ar) / r;
        } else if (r == brm) {
          if (br > 0.0) {
            sgnbr = 0.5;
          } else {
            sgnbr = -0.5;
          }
          if (bi > 0.0) {
            r = 0.5;
          } else {
            r = -0.5;
          }
          re = (ar * sgnbr + 0.0 * r) / brm;
          im = (0.0 * sgnbr - ar * r) / brm;
        } else {
          brm = br / bi;
          r = bi + brm * br;
          re = brm * ar / r;
          im = (brm * 0.0 - ar) / r;
        }
      }
      a2[k].re = re;
      a2[k].im = im;
    }
  } else {
    binary_expand_op(a2, ratio);
  }
  if (a1.size(0) == a2.size(0)) {
    nx = a1.size(0);
    for (k = 0; k < nx; k++) {
      a1[k].re = a1[k].re + a2[k].re;
      a1[k].im = a1[k].im + a2[k].im;
    }
  } else {
    plus(a1, a2);
  }
  b_a1.set_size(a1.size(0));
  nx = a1.size(0);
  for (k = 0; k < nx; k++) {
    b_a1[k] = a1[k].re;
  }
  fresnelr(b_a1, fa);
  b_a1.set_size(a1.size(0));
  nx = a1.size(0);
  for (k = 0; k < nx; k++) {
    b_a1[k] = -a1[k].im;
  }
  fresnelr(b_a1, b);
  nx = b.size(0);
  for (k = 0; k < nx; k++) {
    b[k].im = -b[k].im;
  }
  b_a1.set_size(a2.size(0));
  nx = a2.size(0);
  for (k = 0; k < nx; k++) {
    b_a1[k] = a2[k].re;
  }
  fresnelr(b_a1, b_r);
  b_a1.set_size(a2.size(0));
  nx = a2.size(0);
  for (k = 0; k < nx; k++) {
    b_a1[k] = -a2[k].im;
  }
  fresnelr(b_a1, b_b);
  nx = b_b.size(0);
  for (k = 0; k < nx; k++) {
    b_b[k].im = -b_b[k].im;
  }
  if (fa.size(0) == 1) {
    nx = b.size(0);
  } else {
    nx = fa.size(0);
  }
  if (b_r.size(0) == 1) {
    k = b_b.size(0);
  } else {
    k = b_r.size(0);
  }
  if ((fa.size(0) == b.size(0)) && (b_r.size(0) == b_b.size(0)) && (nx == k)) {
    nx = fa.size(0);
    for (k = 0; k < nx; k++) {
      sgnbr = b[k].im;
      bi = b[k].re;
      re_tmp = b_b[k].im;
      r = b_b[k].re;
      fa[k].re =
          (fa[k].re + (0.0 * bi - sgnbr)) - (b_r[k].re + (0.0 * r - re_tmp));
      fa[k].im =
          (fa[k].im + (0.0 * sgnbr + bi)) - (b_r[k].im + (0.0 * re_tmp + r));
    }
  } else {
    binary_expand_op(fa, b, b_r, b_b);
  }
  s.set_size(y_tmp.size(0));
  nx = y_tmp.size(0);
  for (k = 0; k < nx; k++) {
    s[k].re = 3.1415926535897931 / y_tmp[k];
    s[k].im = 0.0;
  }
  nx = s.size(0);
  for (k = 0; k < nx; k++) {
    ::coder::internal::scalar::b_sqrt(&s[k]);
  }
  b_a1.set_size(a.size(0));
  nx = a.size(0);
  for (k = 0; k < nx; k++) {
    b_a1[k] = 4.0 * a[k];
  }
  r1.set_size(ratio.size(0));
  nx = ratio.size(0);
  for (k = 0; k < nx; k++) {
    r = ratio[k];
    r1[k] = r * r;
  }
  if (r1.size(0) == 1) {
    nx = b_a1.size(0);
  } else {
    nx = r1.size(0);
  }
  if ((r1.size(0) == b_a1.size(0)) && (c.size(0) == nx)) {
    c_r.set_size(c.size(0));
    nx = c.size(0);
    for (k = 0; k < nx; k++) {
      brm = c[k] - r1[k] / b_a1[k];
      c_r[k].re = brm * 0.0;
      c_r[k].im = brm;
    }
  } else {
    binary_expand_op(c_r, c, r1, b_a1);
  }
  nx = c_r.size(0);
  for (k = 0; k < nx; k++) {
    if (c_r[k].im == 0.0) {
      c_r[k].re = std::exp(c_r[k].re);
      c_r[k].im = 0.0;
    } else if (std::isinf(c_r[k].im) && std::isinf(c_r[k].re) &&
               (c_r[k].re < 0.0)) {
      c_r[k].re = 0.0;
      c_r[k].im = 0.0;
    } else {
      r = std::exp(c_r[k].re / 2.0);
      c_r[k].re = r * (r * std::cos(c_r[k].im));
      c_r[k].im = r * (r * std::sin(c_r[k].im));
    }
  }
  if (s.size(0) == c_r.size(0)) {
    drsfa.set_size(s.size(0));
    nx = s.size(0);
    for (k = 0; k < nx; k++) {
      brm = s[k].re;
      sgnbr = c_r[k].im;
      r = s[k].im;
      br = c_r[k].re;
      drsfa[k].re = brm * br - r * sgnbr;
      drsfa[k].im = brm * sgnbr + r * br;
    }
  } else {
    times(drsfa, s, c_r);
  }
  if (drsfa.size(0) == fa.size(0)) {
    rsfa.set_size(drsfa.size(0));
    nx = drsfa.size(0);
    for (k = 0; k < nx; k++) {
      brm = drsfa[k].re;
      sgnbr = fa[k].im;
      r = drsfa[k].im;
      br = fa[k].re;
      rsfa[k].re = brm * br - r * sgnbr;
      rsfa[k].im = brm * sgnbr + r * br;
    }
  } else {
    times(rsfa, drsfa, fa);
  }
  x.set_size(b_y_tmp.size(0));
  nx = b_y_tmp.size(0);
  for (k = 0; k < nx; k++) {
    x[k].re = b_y_tmp[k];
    x[k].im = 0.0;
  }
  nx = x.size(0);
  for (k = 0; k < nx; k++) {
    ::coder::internal::scalar::b_sqrt(&x[k]);
  }
  b_x.set_size(b_y_tmp.size(0));
  nx = b_y_tmp.size(0);
  for (k = 0; k < nx; k++) {
    b_x[k].re = b_y_tmp[k];
    b_x[k].im = 0.0;
  }
  nx = b_x.size(0);
  for (k = 0; k < nx; k++) {
    ::coder::internal::scalar::b_sqrt(&b_x[k]);
  }
  b.set_size(b_y_tmp.size(0));
  nx = b_y_tmp.size(0);
  for (k = 0; k < nx; k++) {
    b[k].re = b_y_tmp[k];
    b[k].im = 0.0;
  }
  nx = b.size(0);
  for (k = 0; k < nx; k++) {
    ::coder::internal::scalar::b_sqrt(&b[k]);
  }
  da2.set_size(b_x.size(0));
  nx = b_x.size(0);
  for (k = 0; k < nx; k++) {
    varargin_1 = b_x[k];
    if ((varargin_1.im == 0.0) && (varargin_1.re >= 0.0)) {
      varargout_1.re = rt_powd_snf(varargin_1.re, 3.0);
      varargout_1.im = 0.0;
    } else if (varargin_1.re == 0.0) {
      varargout_1.re = 0.0;
      varargout_1.im = -rt_powd_snf(varargin_1.im, 3.0);
    } else {
      if (varargin_1.im == 0.0) {
        if (varargin_1.re < 0.0) {
          br = std::log(std::abs(varargin_1.re));
          r = 3.1415926535897931;
        } else {
          br = std::log(varargin_1.re);
          r = 0.0;
        }
      } else if ((std::abs(varargin_1.re) > 8.9884656743115785E+307) ||
                 (std::abs(varargin_1.im) > 8.9884656743115785E+307)) {
        br = std::log(rt_hypotd_snf(varargin_1.re / 2.0, varargin_1.im / 2.0)) +
             0.69314718055994529;
        r = rt_atan2d_snf(varargin_1.im, varargin_1.re);
      } else {
        br = std::log(rt_hypotd_snf(varargin_1.re, varargin_1.im));
        r = rt_atan2d_snf(varargin_1.im, varargin_1.re);
      }
      varargout_1.re = 3.0 * br;
      varargout_1.im = 3.0 * r;
      if (varargout_1.im == 0.0) {
        brm = varargout_1.re;
        varargout_1.re = std::exp(brm);
        varargout_1.im = 0.0;
      } else if (std::isinf(varargout_1.im) && std::isinf(varargout_1.re) &&
                 (varargout_1.re < 0.0)) {
        varargout_1.re = 0.0;
        varargout_1.im = 0.0;
      } else {
        r = std::exp(varargout_1.re / 2.0);
        brm = varargout_1.im;
        sgnbr = varargout_1.im;
        varargout_1.re = r * (r * std::cos(brm));
        varargout_1.im = r * (r * std::sin(sgnbr));
      }
    }
    da2[k] = varargout_1;
  }
  if (ratio.size(0) == 1) {
    nx = da2.size(0);
  } else {
    nx = ratio.size(0);
  }
  if ((ratio.size(0) == da2.size(0)) && (nx == b.size(0))) {
    da2.set_size(ratio.size(0));
    nx = ratio.size(0);
    for (k = 0; k < nx; k++) {
      br = da2[k].re;
      bi = da2[k].im;
      if (bi == 0.0) {
        re = -3.1415926535897931 / br;
        im = 0.0;
      } else if (br == 0.0) {
        re = 0.0;
        im = -(-3.1415926535897931 / bi);
      } else {
        brm = std::abs(br);
        r = std::abs(bi);
        if (brm > r) {
          brm = bi / br;
          r = br + brm * bi;
          re = (brm * 0.0 + -3.1415926535897931) / r;
          im = (0.0 - brm * -3.1415926535897931) / r;
        } else if (r == brm) {
          if (br > 0.0) {
            sgnbr = 0.5;
          } else {
            sgnbr = -0.5;
          }
          if (bi > 0.0) {
            r = 0.5;
          } else {
            r = -0.5;
          }
          re = (-3.1415926535897931 * sgnbr + 0.0 * r) / brm;
          im = (0.0 * sgnbr - -3.1415926535897931 * r) / brm;
        } else {
          brm = br / bi;
          r = bi + brm * br;
          re = brm * -3.1415926535897931 / r;
          im = (brm * 0.0 - -3.1415926535897931) / r;
        }
      }
      br = b[k].re;
      bi = b[k].im;
      if (bi == 0.0) {
        b_re = 1.0 / br;
        r = 0.0;
      } else if (br == 0.0) {
        b_re = 0.0;
        r = -(1.0 / bi);
      } else {
        brm = std::abs(br);
        r = std::abs(bi);
        if (brm > r) {
          brm = bi / br;
          r = br + brm * bi;
          b_re = (brm * 0.0 + 1.0) / r;
          r = (0.0 - brm) / r;
        } else if (r == brm) {
          if (br > 0.0) {
            sgnbr = 0.5;
          } else {
            sgnbr = -0.5;
          }
          if (bi > 0.0) {
            r = 0.5;
          } else {
            r = -0.5;
          }
          b_re = (sgnbr + 0.0 * r) / brm;
          r = (0.0 * sgnbr - r) / brm;
        } else {
          brm = br / bi;
          r = bi + brm * br;
          b_re = brm / r;
          r = (brm * 0.0 - 1.0) / r;
        }
      }
      da2[k].re = ratio[k] * re - b_re;
      da2[k].im = ratio[k] * im - r;
    }
  } else {
    binary_expand_op(da2, ratio, b);
  }
  b_r.set_size(a1.size(0));
  nx = a1.size(0);
  for (k = 0; k < nx; k++) {
    varargin_1 = a1[k];
    varargout_1.re =
        varargin_1.re * varargin_1.re - varargin_1.im * varargin_1.im;
    r = varargin_1.re * varargin_1.im;
    varargout_1.im = r + r;
    b_r[k] = varargout_1;
  }
  nx = b_r.size(0);
  for (k = 0; k < nx; k++) {
    sgnbr = b_r[k].im;
    bi = b_r[k].re;
    b_r[k].re = 0.0 * bi - 1.5707963267948966 * sgnbr;
    b_r[k].im = 0.0 * sgnbr + 1.5707963267948966 * bi;
  }
  nx = b_r.size(0);
  for (k = 0; k < nx; k++) {
    if (b_r[k].im == 0.0) {
      b_r[k].re = std::exp(b_r[k].re);
      b_r[k].im = 0.0;
    } else if (std::isinf(b_r[k].im) && std::isinf(b_r[k].re) &&
               (b_r[k].re < 0.0)) {
      b_r[k].re = 0.0;
      b_r[k].im = 0.0;
    } else {
      r = std::exp(b_r[k].re / 2.0);
      b_r[k].re = r * (r * std::cos(b_r[k].im));
      b_r[k].im = r * (r * std::sin(b_r[k].im));
    }
  }
  b_b.set_size(a2.size(0));
  nx = a2.size(0);
  for (k = 0; k < nx; k++) {
    varargin_1 = a2[k];
    varargout_1.re =
        varargin_1.re * varargin_1.re - varargin_1.im * varargin_1.im;
    r = varargin_1.re * varargin_1.im;
    varargout_1.im = r + r;
    b_b[k] = varargout_1;
  }
  nx = b_b.size(0);
  for (k = 0; k < nx; k++) {
    sgnbr = b_b[k].im;
    bi = b_b[k].re;
    b_b[k].re = 0.0 * bi - 1.5707963267948966 * sgnbr;
    b_b[k].im = 0.0 * sgnbr + 1.5707963267948966 * bi;
  }
  nx = b_b.size(0);
  for (k = 0; k < nx; k++) {
    if (b_b[k].im == 0.0) {
      b_b[k].re = std::exp(b_b[k].re);
      b_b[k].im = 0.0;
    } else if (std::isinf(b_b[k].im) && std::isinf(b_b[k].re) &&
               (b_b[k].re < 0.0)) {
      b_b[k].re = 0.0;
      b_b[k].im = 0.0;
    } else {
      r = std::exp(b_b[k].re / 2.0);
      b_b[k].re = r * (r * std::cos(b_b[k].im));
      b_b[k].im = r * (r * std::sin(b_b[k].im));
    }
  }
  r1.set_size(a.size(0));
  nx = a.size(0);
  for (k = 0; k < nx; k++) {
    r1[k] = a[k];
  }
  nx = a.size(0);
  for (k = 0; k < nx; k++) {
    r = r1[k];
    if (!std::isnan(r1[k])) {
      if (r1[k] < 0.0) {
        r = -1.0;
      } else {
        r = (r1[k] > 0.0);
      }
    }
    r1[k] = r;
  }
  b_x.set_size(y_tmp.size(0));
  nx = y_tmp.size(0);
  for (k = 0; k < nx; k++) {
    b_x[k].re = 3.1415926535897931 / y_tmp[k];
    b_x[k].im = 0.0;
  }
  nx = b_x.size(0);
  for (k = 0; k < nx; k++) {
    ::coder::internal::scalar::b_sqrt(&b_x[k]);
  }
  if (ratio.size(0) == b_a1.size(0)) {
    nx = ratio.size(0);
    for (k = 0; k < nx; k++) {
      ratio[k] = ratio[k] / b_a1[k];
    }
  } else {
    rdivide(ratio, b_a1);
  }
  b.set_size(b_x.size(0));
  nx = b_x.size(0);
  for (k = 0; k < nx; k++) {
    varargin_1 = b_x[k];
    if ((varargin_1.im == 0.0) && (varargin_1.re >= 0.0)) {
      varargout_1.re = rt_powd_snf(varargin_1.re, 3.0);
      varargout_1.im = 0.0;
    } else if (varargin_1.re == 0.0) {
      varargout_1.re = 0.0;
      varargout_1.im = -rt_powd_snf(varargin_1.im, 3.0);
    } else {
      if (varargin_1.im == 0.0) {
        if (varargin_1.re < 0.0) {
          br = std::log(std::abs(varargin_1.re));
          r = 3.1415926535897931;
        } else {
          br = std::log(varargin_1.re);
          r = 0.0;
        }
      } else if ((std::abs(varargin_1.re) > 8.9884656743115785E+307) ||
                 (std::abs(varargin_1.im) > 8.9884656743115785E+307)) {
        br = std::log(rt_hypotd_snf(varargin_1.re / 2.0, varargin_1.im / 2.0)) +
             0.69314718055994529;
        r = rt_atan2d_snf(varargin_1.im, varargin_1.re);
      } else {
        br = std::log(rt_hypotd_snf(varargin_1.re, varargin_1.im));
        r = rt_atan2d_snf(varargin_1.im, varargin_1.re);
      }
      varargout_1.re = 3.0 * br;
      varargout_1.im = 3.0 * r;
      if (varargout_1.im == 0.0) {
        brm = varargout_1.re;
        varargout_1.re = std::exp(brm);
        varargout_1.im = 0.0;
      } else if (std::isinf(varargout_1.im) && std::isinf(varargout_1.re) &&
                 (varargout_1.re < 0.0)) {
        varargout_1.re = 0.0;
        varargout_1.im = 0.0;
      } else {
        r = std::exp(varargout_1.re / 2.0);
        brm = varargout_1.im;
        sgnbr = varargout_1.im;
        varargout_1.re = r * (r * std::cos(brm));
        varargout_1.im = r * (r * std::sin(sgnbr));
      }
    }
    b[k] = varargout_1;
  }
  if (x.size(0) == 1) {
    nx = da2.size(0);
  } else {
    nx = x.size(0);
  }
  if (b_r.size(0) == 1) {
    if (x.size(0) == 1) {
      k = da2.size(0);
    } else {
      k = x.size(0);
    }
  } else {
    k = b_r.size(0);
  }
  if (b_b.size(0) == 1) {
    i = da2.size(0);
  } else {
    i = b_b.size(0);
  }
  if (b_r.size(0) == 1) {
    if (x.size(0) == 1) {
      i1 = da2.size(0);
    } else {
      i1 = x.size(0);
    }
  } else {
    i1 = b_r.size(0);
  }
  if (i1 == 1) {
    if (b_b.size(0) == 1) {
      i1 = da2.size(0);
    } else {
      i1 = b_b.size(0);
    }
  } else if (b_r.size(0) == 1) {
    if (x.size(0) == 1) {
      i1 = da2.size(0);
    } else {
      i1 = x.size(0);
    }
  } else {
    i1 = b_r.size(0);
  }
  if (b_r.size(0) == 1) {
    if (x.size(0) == 1) {
      i2 = da2.size(0);
    } else {
      i2 = x.size(0);
    }
  } else {
    i2 = b_r.size(0);
  }
  if (r1.size(0) == 1) {
    if (i2 == 1) {
      if (b_b.size(0) == 1) {
        i2 = da2.size(0);
      } else {
        i2 = b_b.size(0);
      }
    } else if (b_r.size(0) == 1) {
      if (x.size(0) == 1) {
        i2 = da2.size(0);
      } else {
        i2 = x.size(0);
      }
    } else {
      i2 = b_r.size(0);
    }
  } else {
    i2 = r1.size(0);
  }
  if (c_r.size(0) == 1) {
    i3 = ratio.size(0);
  } else {
    i3 = c_r.size(0);
  }
  if (c_r.size(0) == 1) {
    i4 = ratio.size(0);
  } else {
    i4 = c_r.size(0);
  }
  if (i4 == 1) {
    i4 = ratio.size(0);
  } else if (c_r.size(0) == 1) {
    i4 = ratio.size(0);
  } else {
    i4 = c_r.size(0);
  }
  if (c_r.size(0) == 1) {
    i5 = ratio.size(0);
  } else {
    i5 = c_r.size(0);
  }
  if (s.size(0) == 1) {
    if (i5 == 1) {
      i5 = ratio.size(0);
    } else if (c_r.size(0) == 1) {
      i5 = ratio.size(0);
    } else {
      i5 = c_r.size(0);
    }
  } else {
    i5 = s.size(0);
  }
  if (c_r.size(0) == 1) {
    i6 = b.size(0);
  } else {
    i6 = c_r.size(0);
  }
  if (c_r.size(0) == 1) {
    i7 = ratio.size(0);
  } else {
    i7 = c_r.size(0);
  }
  if (s.size(0) == 1) {
    if (i7 == 1) {
      i7 = ratio.size(0);
    } else if (c_r.size(0) == 1) {
      i7 = ratio.size(0);
    } else {
      i7 = c_r.size(0);
    }
  } else {
    i7 = s.size(0);
  }
  if (c_r.size(0) == 1) {
    i8 = ratio.size(0);
  } else {
    i8 = c_r.size(0);
  }
  if (i7 == 1) {
    if (c_r.size(0) == 1) {
      i7 = b.size(0);
    } else {
      i7 = c_r.size(0);
    }
  } else if (s.size(0) == 1) {
    if (i8 == 1) {
      i7 = ratio.size(0);
    } else if (c_r.size(0) == 1) {
      i7 = ratio.size(0);
    } else {
      i7 = c_r.size(0);
    }
  } else {
    i7 = s.size(0);
  }
  if (b_r.size(0) == 1) {
    if (x.size(0) == 1) {
      i8 = da2.size(0);
    } else {
      i8 = x.size(0);
    }
  } else {
    i8 = b_r.size(0);
  }
  if (drsfa.size(0) == 1) {
    if (r1.size(0) == 1) {
      if (i8 == 1) {
        if (b_b.size(0) == 1) {
          i8 = da2.size(0);
        } else {
          i8 = b_b.size(0);
        }
      } else if (b_r.size(0) == 1) {
        if (x.size(0) == 1) {
          i8 = da2.size(0);
        } else {
          i8 = x.size(0);
        }
      } else {
        i8 = b_r.size(0);
      }
    } else {
      i8 = r1.size(0);
    }
  } else {
    i8 = drsfa.size(0);
  }
  if (c_r.size(0) == 1) {
    i9 = ratio.size(0);
  } else {
    i9 = c_r.size(0);
  }
  if (s.size(0) == 1) {
    if (i9 == 1) {
      i9 = ratio.size(0);
    } else if (c_r.size(0) == 1) {
      i9 = ratio.size(0);
    } else {
      i9 = c_r.size(0);
    }
  } else {
    i9 = s.size(0);
  }
  if (c_r.size(0) == 1) {
    i10 = ratio.size(0);
  } else {
    i10 = c_r.size(0);
  }
  if (fa.size(0) == 1) {
    if (i9 == 1) {
      if (c_r.size(0) == 1) {
        i9 = b.size(0);
      } else {
        i9 = c_r.size(0);
      }
    } else if (s.size(0) == 1) {
      if (i10 == 1) {
        i9 = ratio.size(0);
      } else if (c_r.size(0) == 1) {
        i9 = ratio.size(0);
      } else {
        i9 = c_r.size(0);
      }
    } else {
      i9 = s.size(0);
    }
  } else {
    i9 = fa.size(0);
  }
  if ((x.size(0) == da2.size(0)) && (b_r.size(0) == nx) &&
      (b_b.size(0) == da2.size(0)) && (k == i) && (r1.size(0) == i1) &&
      (drsfa.size(0) == i2) && (c_r.size(0) == ratio.size(0)) &&
      (i3 == ratio.size(0)) && (s.size(0) == i4) &&
      (c_r.size(0) == b.size(0)) && (i5 == i6) && (fa.size(0) == i7) &&
      (i8 == i9)) {
    nx = drsfa.size(0);
    for (k = 0; k < nx; k++) {
      double b_drsfa_re_tmp;
      double drsfa_re_tmp;
      double r_re;
      br = x[k].re;
      bi = x[k].im;
      if (bi == 0.0) {
        re = 1.0 / br;
        im = 0.0;
      } else if (br == 0.0) {
        re = 0.0;
        im = -(1.0 / bi);
      } else {
        brm = std::abs(br);
        r = std::abs(bi);
        if (brm > r) {
          brm = bi / br;
          r = br + brm * bi;
          re = (brm * 0.0 + 1.0) / r;
          im = (0.0 - brm) / r;
        } else if (r == brm) {
          if (br > 0.0) {
            sgnbr = 0.5;
          } else {
            sgnbr = -0.5;
          }
          if (bi > 0.0) {
            r = 0.5;
          } else {
            r = -0.5;
          }
          re = (sgnbr + 0.0 * r) / brm;
          im = (0.0 * sgnbr - r) / brm;
        } else {
          brm = br / bi;
          r = bi + brm * br;
          re = brm / r;
          im = (brm * 0.0 - 1.0) / r;
        }
      }
      sgnbr = da2[k].re;
      re += sgnbr;
      r = da2[k].im;
      im += r;
      bi = b_r[k].re;
      re_tmp = b_r[k].im;
      br = b_b[k].re;
      brm = b_b[k].im;
      b_re = r1[k] * ((bi * re - re_tmp * im) - (br * sgnbr - brm * r));
      im = r1[k] * ((bi * im + re_tmp * re) - (br * r + brm * sgnbr));
      drsfa_re_tmp = drsfa[k].re;
      b_drsfa_re_tmp = drsfa[k].im;
      re_tmp = c_r[k].re;
      re = c_r[k].im;
      r = 2.0 * ratio[k] + 1.0;
      r_re = r * (ratio[k] * (re_tmp * 0.0 - re * 2.0));
      sgnbr = r * (ratio[k] * (re_tmp * 2.0 + re * 0.0));
      bi = s[k].re;
      brm = s[k].im;
      ar = -b[k].re;
      r = -b[k].im;
      if (r == 0.0) {
        br = ar / 3.1415926535897931;
        r = 0.0;
      } else if (ar == 0.0) {
        br = 0.0;
        r /= 3.1415926535897931;
      } else {
        br = ar / 3.1415926535897931;
        r /= 3.1415926535897931;
      }
      ar = (bi * r_re - brm * sgnbr) + (re_tmp * br - re * r);
      r = (bi * sgnbr + brm * r_re) + (re_tmp * r + re * br);
      br = fa[k].re;
      brm = fa[k].im;
      drsfa[k].re =
          (drsfa_re_tmp * b_re - b_drsfa_re_tmp * im) + (br * ar - brm * r);
      drsfa[k].im =
          (drsfa_re_tmp * im + b_drsfa_re_tmp * b_re) + (br * r + brm * ar);
    }
  } else {
    binary_expand_op(drsfa, r1, b_r, x, da2, b_b, fa, s, c_r, ratio, b);
  }
}

//
// Arguments    : const ::coder::array<double, 1U> &a
//                const ::coder::array<double, 1U> &d
//                const ::coder::array<double, 1U> &c
//                ::coder::array<creal_T, 1U> &z
//                ::coder::array<creal_T, 1U> &dz
// Return Type  : void
//
static void fresnelgSmalla1(const ::coder::array<double, 1U> &a,
                            const ::coder::array<double, 1U> &d,
                            const ::coder::array<double, 1U> &c,
                            ::coder::array<creal_T, 1U> &z,
                            ::coder::array<creal_T, 1U> &dz)
{
  array<creal_T, 1U> dm2C;
  array<creal_T, 1U> dp;
  array<creal_T, 1U> dt;
  array<creal_T, 1U> e;
  array<creal_T, 1U> m2C;
  array<creal_T, 1U> nik;
  array<creal_T, 1U> t;
  array<creal_T, 1U> y_tmp;
  array<double, 1U> b_r;
  array<double, 1U> b_y_tmp;
  array<double, 1U> dk;
  array<double, 1U> k;
  double ai;
  double ar;
  double br;
  double r;
  double re;
  double y_tmp_re;
  int b_k;
  int i;
  int i1;
  int nx;
  dk.set_size(a.size(0));
  nx = a.size(0);
  for (i = 0; i < nx; i++) {
    dk[i] = 2.0 * a[i];
  }
  if (d.size(0) == a.size(0)) {
    k.set_size(d.size(0));
    nx = d.size(0);
    for (i = 0; i < nx; i++) {
      k[i] = d[i] - a[i];
    }
  } else {
    minus(k, d, a);
  }
  y_tmp.set_size(dk.size(0));
  nx = dk.size(0);
  for (i = 0; i < nx; i++) {
    y_tmp[i].re = dk[i] * 0.0;
    y_tmp[i].im = dk[i] * 0.5;
  }
  b_y_tmp.set_size(k.size(0));
  nx = k.size(0);
  for (i = 0; i < nx; i++) {
    r = k[i];
    b_y_tmp[i] = r * r;
  }
  nik.set_size(k.size(0));
  nx = k.size(0);
  for (i = 0; i < nx; i++) {
    nik[i].re = k[i] * 0.0;
    nik[i].im = -k[i];
  }
  e.set_size(nik.size(0));
  nx = nik.size(0);
  for (i = 0; i < nx; i++) {
    e[i].re = -nik[i].re;
    e[i].im = -nik[i].im;
  }
  nx = e.size(0);
  for (b_k = 0; b_k < nx; b_k++) {
    if (e[b_k].im == 0.0) {
      e[b_k].re = std::exp(e[b_k].re);
      e[b_k].im = 0.0;
    } else if (std::isinf(e[b_k].im) && std::isinf(e[b_k].re) &&
               (e[b_k].re < 0.0)) {
      e[b_k].re = 0.0;
      e[b_k].im = 0.0;
    } else {
      r = std::exp(e[b_k].re / 2.0);
      e[b_k].re = r * (r * std::cos(e[b_k].im));
      e[b_k].im = r * (r * std::sin(e[b_k].im));
    }
  }
  if (y_tmp.size(0) == b_y_tmp.size(0)) {
    m2C.set_size(y_tmp.size(0));
    nx = y_tmp.size(0);
    for (i = 0; i < nx; i++) {
      ar = y_tmp[i].re;
      ai = y_tmp[i].im;
      br = b_y_tmp[i];
      if (ai == 0.0) {
        y_tmp_re = ar / br;
        r = 0.0;
      } else if (ar == 0.0) {
        y_tmp_re = 0.0;
        r = ai / br;
      } else {
        y_tmp_re = rtNaN;
        r = ai / br;
      }
      m2C[i].re = -2.0 * y_tmp_re;
      m2C[i].im = -2.0 * r;
    }
  } else {
    binary_expand_op(m2C, y_tmp, b_y_tmp);
  }
  b_r.set_size(k.size(0));
  nx = k.size(0);
  for (i = 0; i < nx; i++) {
    r = k[i];
    b_r[i] = rt_powd_snf(r, 3.0);
  }
  if (dk.size(0) == 1) {
    i = k.size(0);
  } else {
    i = dk.size(0);
  }
  if ((dk.size(0) == k.size(0)) && (i == b_r.size(0))) {
    dm2C.set_size(dk.size(0));
    nx = dk.size(0);
    for (i = 0; i < nx; i++) {
      ar = -(0.0 * dk[i] + 0.0 * k[i]);
      ai = -(2.0 * dk[i] + 2.0 * k[i]);
      br = b_r[i];
      if (ai == 0.0) {
        dm2C[i].re = ar / br;
        dm2C[i].im = 0.0;
      } else if (ar == 0.0) {
        dm2C[i].re = 0.0;
        dm2C[i].im = ai / br;
      } else {
        dm2C[i].re = rtNaN;
        dm2C[i].im = ai / br;
      }
    }
  } else {
    e_binary_expand_op(dm2C, dk, k, b_r);
  }
  if (e.size(0) == nik.size(0)) {
    t.set_size(e.size(0));
    nx = e.size(0);
    for (i = 0; i < nx; i++) {
      ar = 1.0 - e[i].re;
      ai = 0.0 - e[i].im;
      br = nik[i].re;
      r = nik[i].im;
      if (r == 0.0) {
        if (ai == 0.0) {
          t[i].re = ar / br;
          t[i].im = 0.0;
        } else if (ar == 0.0) {
          t[i].re = 0.0;
          t[i].im = ai / br;
        } else {
          t[i].re = ar / br;
          t[i].im = ai / br;
        }
      } else if (br == 0.0) {
        if (ar == 0.0) {
          t[i].re = ai / r;
          t[i].im = 0.0;
        } else if (ai == 0.0) {
          t[i].re = 0.0;
          t[i].im = -(ar / r);
        } else {
          t[i].re = ai / r;
          t[i].im = -(ar / r);
        }
      } else {
        t[i].re = rtNaN;
        t[i].im = rtNaN;
      }
    }
  } else {
    binary_expand_op(t, e, nik);
  }
  dp.set_size(k.size(0));
  nx = k.size(0);
  for (i = 0; i < nx; i++) {
    dp[i].re = k[i] * 0.0;
    dp[i].im = k[i];
  }
  nx = dp.size(0);
  for (b_k = 0; b_k < nx; b_k++) {
    if (dp[b_k].im == 0.0) {
      dp[b_k].re = std::exp(dp[b_k].re);
      dp[b_k].im = 0.0;
    } else if (std::isinf(dp[b_k].im) && std::isinf(dp[b_k].re) &&
               (dp[b_k].re < 0.0)) {
      dp[b_k].re = 0.0;
      dp[b_k].im = 0.0;
    } else {
      r = std::exp(dp[b_k].re / 2.0);
      dp[b_k].re = r * (r * std::cos(dp[b_k].im));
      dp[b_k].im = r * (r * std::sin(dp[b_k].im));
    }
  }
  if (k.size(0) == 1) {
    i = dp.size(0);
  } else {
    i = k.size(0);
  }
  if (k.size(0) == 1) {
    i1 = dp.size(0);
  } else {
    i1 = k.size(0);
  }
  if (i1 == 1) {
    i1 = dp.size(0);
  } else if (k.size(0) == 1) {
    i1 = dp.size(0);
  } else {
    i1 = k.size(0);
  }
  if ((k.size(0) == dp.size(0)) && (i == dp.size(0)) &&
      (i1 == b_y_tmp.size(0))) {
    dt.set_size(k.size(0));
    nx = k.size(0);
    for (i = 0; i < nx; i++) {
      y_tmp_re = dp[i].re;
      r = dp[i].im;
      ar = -(k[i] * y_tmp_re + (0.0 * (y_tmp_re - 1.0) - r));
      ai = -(k[i] * r + (0.0 * r + (y_tmp_re - 1.0)));
      br = b_y_tmp[i];
      if (ai == 0.0) {
        dt[i].re = ar / br;
        dt[i].im = 0.0;
      } else if (ar == 0.0) {
        dt[i].re = 0.0;
        dt[i].im = ai / br;
      } else {
        dt[i].re = ar / br;
        dt[i].im = ai / br;
      }
    }
  } else {
    binary_expand_op(dt, k, dp, b_y_tmp);
  }
  nx = nik.size(0);
  for (i = 0; i < nx; i++) {
    ar = nik[i].re;
    ai = nik[i].im;
    if (ai == 0.0) {
      re = ar / 2.0;
      r = 0.0;
    } else if (ar == 0.0) {
      re = 0.0;
      r = ai / 2.0;
    } else {
      re = ar / 2.0;
      r = ai / 2.0;
    }
    nik[i].re = re;
    nik[i].im = r;
  }
  nx = e.size(0);
  for (i = 0; i < nx; i++) {
    e[i].re = -e[i].re;
    e[i].im = -e[i].im;
  }
  nx = dp.size(0);
  for (i = 0; i < nx; i++) {
    br = dp[i].im;
    ai = dp[i].re;
    dp[i].re = 0.0 * ai - br;
    dp[i].im = 0.0 * br + ai;
  }
  z.set_size(t.size(0));
  nx = t.size(0);
  for (i = 0; i < nx; i++) {
    z[i] = t[i];
  }
  dz.set_size(dt.size(0));
  nx = dt.size(0);
  for (i = 0; i < nx; i++) {
    dz[i] = dt[i];
  }
  nx = m2C.size(0);
  b_k = m2C.size(0);
  for (int n{0}; n < 20; n++) {
    double n_re;
    double t_re_tmp;
    int i2;
    int i3;
    int loop_ub;
    loop_ub = t.size(0);
    if (nik.size(0) == 1) {
      i = e.size(0);
    } else {
      i = nik.size(0);
    }
    if ((nik.size(0) == e.size(0)) && (t.size(0) == i)) {
      i = 2 * (n + 1) - 1;
      for (i1 = 0; i1 < loop_ub; i1++) {
        n_re = (static_cast<double>(n) + 1.0) + nik[i1].re;
        ar = nik[i1].im;
        r = e[i1].im;
        y_tmp_re = e[i1].re;
        t[i1].re =
            static_cast<double>(i) * t[i1].re + (n_re * y_tmp_re - ar * r);
        t[i1].im =
            static_cast<double>(i) * t[i1].im + (n_re * r + ar * y_tmp_re);
      }
    } else {
      binary_expand_op(t, n, nik, e);
    }
    if (dt.size(0) == 1) {
      i = e.size(0);
    } else {
      i = dt.size(0);
    }
    if (dp.size(0) == 1) {
      i1 = nik.size(0);
    } else {
      i1 = dp.size(0);
    }
    if (dt.size(0) == 1) {
      loop_ub = e.size(0);
    } else {
      loop_ub = dt.size(0);
    }
    if (loop_ub == 1) {
      if (dp.size(0) == 1) {
        loop_ub = nik.size(0);
      } else {
        loop_ub = dp.size(0);
      }
    } else if (dt.size(0) == 1) {
      loop_ub = e.size(0);
    } else {
      loop_ub = dt.size(0);
    }
    if (dt.size(0) == 1) {
      i2 = e.size(0);
    } else {
      i2 = dt.size(0);
    }
    if (m2C.size(0) == 1) {
      if (i2 == 1) {
        if (dp.size(0) == 1) {
          i2 = nik.size(0);
        } else {
          i2 = dp.size(0);
        }
      } else if (dt.size(0) == 1) {
        i2 = e.size(0);
      } else {
        i2 = dt.size(0);
      }
    } else {
      i2 = m2C.size(0);
    }
    if (t.size(0) == 1) {
      i3 = dm2C.size(0);
    } else {
      i3 = t.size(0);
    }
    if ((dt.size(0) == e.size(0)) && (dp.size(0) == nik.size(0)) && (i == i1) &&
        (m2C.size(0) == loop_ub) && (t.size(0) == dm2C.size(0)) && (i2 == i3)) {
      i = 2 * (n + 1) - 1;
      dt.set_size(m2C.size(0));
      for (i1 = 0; i1 < nx; i1++) {
        br = e[i1].im;
        ai = e[i1].re;
        n_re = (static_cast<double>(n) + 1.0) + nik[i1].re;
        ar = nik[i1].im;
        y_tmp_re = dp[i1].re;
        r = dp[i1].im;
        re = (static_cast<double>(i) * dt[i1].re + (0.0 * ai - 0.5 * br)) +
             (y_tmp_re * n_re - r * ar);
        r = (static_cast<double>(i) * dt[i1].im + (0.0 * br + 0.5 * ai)) +
            (y_tmp_re * ar + r * n_re);
        y_tmp_re = m2C[i1].re;
        br = m2C[i1].im;
        ai = t[i1].re;
        n_re = dm2C[i1].im;
        ar = t[i1].im;
        t_re_tmp = dm2C[i1].re;
        dt[i1].re = (y_tmp_re * re - br * r) + (ai * t_re_tmp - ar * n_re);
        dt[i1].im = (y_tmp_re * r + br * re) + (ai * n_re + ar * t_re_tmp);
      }
    } else {
      binary_expand_op(dt, m2C, n, e, dp, nik, t, dm2C);
    }
    if (m2C.size(0) == t.size(0)) {
      t.set_size(m2C.size(0));
      for (i = 0; i < b_k; i++) {
        br = m2C[i].re;
        ai = t[i].im;
        r = m2C[i].im;
        y_tmp_re = t[i].re;
        t[i].re = br * y_tmp_re - r * ai;
        t[i].im = br * ai + r * y_tmp_re;
      }
    } else {
      times(t, m2C);
    }
    loop_ub = dz.size(0);
    if (dz.size(0) == dt.size(0)) {
      for (i = 0; i < loop_ub; i++) {
        dz[i].re = dz[i].re + dt[i].re;
        dz[i].im = dz[i].im + dt[i].im;
      }
    } else {
      plus(dz, dt);
    }
    loop_ub = z.size(0);
    if (z.size(0) == t.size(0)) {
      for (i = 0; i < loop_ub; i++) {
        z[i].re = z[i].re + t[i].re;
        z[i].im = z[i].im + t[i].im;
      }
    } else {
      plus(z, t);
    }
    loop_ub = e.size(0);
    if (y_tmp.size(0) == 1) {
      i = dp.size(0);
    } else {
      i = y_tmp.size(0);
    }
    if ((y_tmp.size(0) == dp.size(0)) && (e.size(0) == i)) {
      dp.set_size(e.size(0));
      for (i = 0; i < loop_ub; i++) {
        t_re_tmp = e[i].im;
        n_re = e[i].re;
        r = y_tmp[i].re;
        y_tmp_re = dp[i].im;
        br = y_tmp[i].im;
        ai = dp[i].re;
        ar = (n_re * 0.0 - t_re_tmp) + (r * ai - br * y_tmp_re);
        ai = (n_re + t_re_tmp * 0.0) + (r * y_tmp_re + br * ai);
        if (ai == 0.0) {
          dp[i].re = ar / ((static_cast<double>(n) + 1.0) + 1.0);
          dp[i].im = 0.0;
        } else if (ar == 0.0) {
          dp[i].re = 0.0;
          dp[i].im = ai / ((static_cast<double>(n) + 1.0) + 1.0);
        } else {
          dp[i].re = ar / ((static_cast<double>(n) + 1.0) + 1.0);
          dp[i].im = ai / ((static_cast<double>(n) + 1.0) + 1.0);
        }
      }
    } else {
      binary_expand_op(dp, e, y_tmp, n);
    }
    loop_ub = e.size(0);
    if (e.size(0) == y_tmp.size(0)) {
      for (i = 0; i < loop_ub; i++) {
        t_re_tmp = e[i].re;
        n_re = y_tmp[i].im;
        r = e[i].im;
        y_tmp_re = y_tmp[i].re;
        br = t_re_tmp * y_tmp_re - r * n_re;
        r = t_re_tmp * n_re + r * y_tmp_re;
        if (r == 0.0) {
          e[i].re = br / ((static_cast<double>(n) + 1.0) + 1.0);
          e[i].im = 0.0;
        } else if (br == 0.0) {
          e[i].re = 0.0;
          e[i].im = r / ((static_cast<double>(n) + 1.0) + 1.0);
        } else {
          e[i].re = br / ((static_cast<double>(n) + 1.0) + 1.0);
          e[i].im = r / ((static_cast<double>(n) + 1.0) + 1.0);
        }
      }
    } else {
      binary_expand_op(e, y_tmp, n);
    }
  }
  y_tmp.set_size(c.size(0));
  nx = c.size(0);
  for (i = 0; i < nx; i++) {
    y_tmp[i].re = c[i] * 0.0;
    y_tmp[i].im = c[i];
  }
  nx = y_tmp.size(0);
  for (b_k = 0; b_k < nx; b_k++) {
    if (y_tmp[b_k].im == 0.0) {
      y_tmp[b_k].re = std::exp(y_tmp[b_k].re);
      y_tmp[b_k].im = 0.0;
    } else if (std::isinf(y_tmp[b_k].im) && std::isinf(y_tmp[b_k].re) &&
               (y_tmp[b_k].re < 0.0)) {
      y_tmp[b_k].re = 0.0;
      y_tmp[b_k].im = 0.0;
    } else {
      r = std::exp(y_tmp[b_k].re / 2.0);
      y_tmp[b_k].re = r * (r * std::cos(y_tmp[b_k].im));
      y_tmp[b_k].im = r * (r * std::sin(y_tmp[b_k].im));
    }
  }
  if (z.size(0) == y_tmp.size(0)) {
    nx = z.size(0);
    for (i = 0; i < nx; i++) {
      br = z[i].re;
      ai = y_tmp[i].im;
      r = z[i].im;
      y_tmp_re = y_tmp[i].re;
      z[i].re = br * y_tmp_re - r * ai;
      z[i].im = br * ai + r * y_tmp_re;
    }
  } else {
    b_times(z, y_tmp);
  }
  if (dz.size(0) == y_tmp.size(0)) {
    nx = dz.size(0);
    for (i = 0; i < nx; i++) {
      br = dz[i].re;
      ai = y_tmp[i].im;
      r = dz[i].im;
      y_tmp_re = y_tmp[i].re;
      dz[i].re = br * y_tmp_re - r * ai;
      dz[i].im = br * ai + r * y_tmp_re;
    }
  } else {
    b_times(dz, y_tmp);
  }
}

//
// Arguments    : coder::array<double, 1U> &in1
//                const coder::array<double, 1U> &in2
// Return Type  : void
//
} // namespace scenario
} // namespace internal
} // namespace tracking
} // namespace matlabshared
} // namespace coder
static void e_binary_expand_op(coder::array<double, 1U> &in1,
                               const coder::array<double, 1U> &in2)
{
  coder::array<double, 1U> r;
  int i;
  int loop_ub;
  int stride_0_0;
  int stride_1_0;
  if (in1.size(0) == 1) {
    i = in2.size(0);
  } else {
    i = in1.size(0);
  }
  r.set_size(i);
  stride_0_0 = (in2.size(0) != 1);
  stride_1_0 = (in1.size(0) != 1);
  if (in1.size(0) == 1) {
    loop_ub = in2.size(0);
  } else {
    loop_ub = in1.size(0);
  }
  for (i = 0; i < loop_ub; i++) {
    r[i] = 3.0 * in2[i * stride_0_0] * in1[i * stride_1_0];
  }
  in1.set_size(r.size(0));
  loop_ub = r.size(0);
  for (i = 0; i < loop_ub; i++) {
    in1[i] = r[i];
  }
}

//
// Arguments    : coder::array<double, 1U> &in1
//                const coder::array<double, 1U> &in2
//                const coder::array<double, 1U> &in3
//                const coder::array<double, 1U> &in4
//                const coder::array<double, 1U> &in5
// Return Type  : void
//
static void e_binary_expand_op(coder::array<double, 1U> &in1,
                               const coder::array<double, 1U> &in2,
                               const coder::array<double, 1U> &in3,
                               const coder::array<double, 1U> &in4,
                               const coder::array<double, 1U> &in5)
{
  coder::array<double, 1U> b_in2;
  int i;
  int loop_ub;
  int stride_0_0;
  int stride_1_0;
  int stride_2_0;
  int stride_3_0;
  int stride_4_0;
  if (in5.size(0) == 1) {
    i = in4.size(0);
  } else {
    i = in5.size(0);
  }
  if (in3.size(0) == 1) {
    stride_0_0 = in1.size(0);
  } else {
    stride_0_0 = in3.size(0);
  }
  if (i == 1) {
    if (stride_0_0 == 1) {
      i = in2.size(0);
    } else if (in3.size(0) == 1) {
      i = in1.size(0);
    } else {
      i = in3.size(0);
    }
  } else if (in5.size(0) == 1) {
    i = in4.size(0);
  } else {
    i = in5.size(0);
  }
  b_in2.set_size(i);
  stride_0_0 = (in2.size(0) != 1);
  stride_1_0 = (in1.size(0) != 1);
  stride_2_0 = (in3.size(0) != 1);
  stride_3_0 = (in4.size(0) != 1);
  stride_4_0 = (in5.size(0) != 1);
  if (in5.size(0) == 1) {
    i = in4.size(0);
  } else {
    i = in5.size(0);
  }
  if (i == 1) {
    if (in3.size(0) == 1) {
      i = in1.size(0);
    } else {
      i = in3.size(0);
    }
    if (i == 1) {
      loop_ub = in2.size(0);
    } else if (in3.size(0) == 1) {
      loop_ub = in1.size(0);
    } else {
      loop_ub = in3.size(0);
    }
  } else if (in5.size(0) == 1) {
    loop_ub = in4.size(0);
  } else {
    loop_ub = in5.size(0);
  }
  for (i = 0; i < loop_ub; i++) {
    b_in2[i] =
        in2[i * stride_0_0] * (in1[i * stride_1_0] / in3[i * stride_2_0]) +
        (in4[i * stride_3_0] + -1.0) / in5[i * stride_4_0];
  }
  in1.set_size(b_in2.size(0));
  loop_ub = b_in2.size(0);
  for (i = 0; i < loop_ub; i++) {
    in1[i] = b_in2[i];
  }
}

//
// Arguments    : coder::array<double, 1U> &in1
//                const coder::array<double, 1U> &in2
//                const coder::array<double, 1U> &in3
//                const coder::array<double, 1U> &in4
//                const coder::array<double, 1U> &in5
//                const coder::array<double, 1U> &in6
// Return Type  : void
//
static void e_binary_expand_op(coder::array<double, 1U> &in1,
                               const coder::array<double, 1U> &in2,
                               const coder::array<double, 1U> &in3,
                               const coder::array<double, 1U> &in4,
                               const coder::array<double, 1U> &in5,
                               const coder::array<double, 1U> &in6)
{
  int i;
  int loop_ub;
  int stride_0_0;
  int stride_1_0;
  int stride_2_0;
  int stride_3_0;
  int stride_4_0;
  if (in6.size(0) == 1) {
    i = in5.size(0);
  } else {
    i = in6.size(0);
  }
  if (in4.size(0) == 1) {
    stride_0_0 = in3.size(0);
  } else {
    stride_0_0 = in4.size(0);
  }
  if (i == 1) {
    if (stride_0_0 == 1) {
      i = in2.size(0);
    } else if (in4.size(0) == 1) {
      i = in3.size(0);
    } else {
      i = in4.size(0);
    }
  } else if (in6.size(0) == 1) {
    i = in5.size(0);
  } else {
    i = in6.size(0);
  }
  in1.set_size(i);
  stride_0_0 = (in2.size(0) != 1);
  stride_1_0 = (in3.size(0) != 1);
  stride_2_0 = (in4.size(0) != 1);
  stride_3_0 = (in5.size(0) != 1);
  stride_4_0 = (in6.size(0) != 1);
  if (in6.size(0) == 1) {
    i = in5.size(0);
  } else {
    i = in6.size(0);
  }
  if (i == 1) {
    if (in4.size(0) == 1) {
      i = in3.size(0);
    } else {
      i = in4.size(0);
    }
    if (i == 1) {
      loop_ub = in2.size(0);
    } else if (in4.size(0) == 1) {
      loop_ub = in3.size(0);
    } else {
      loop_ub = in4.size(0);
    }
  } else if (in6.size(0) == 1) {
    loop_ub = in5.size(0);
  } else {
    loop_ub = in6.size(0);
  }
  for (i = 0; i < loop_ub; i++) {
    in1[i] = in2[i * stride_0_0] * (in3[i * stride_1_0] / in4[i * stride_2_0]) +
             (-1.0 - in5[i * stride_3_0]) / in6[i * stride_4_0];
  }
}

//
// Arguments    : coder::array<double, 1U> &in1
//                const coder::array<double, 1U> &in2
//                const coder::array<double, 1U> &in3
//                const coder::array<double, 1U> &in4
//                const coder::array<double, 1U> &in5
// Return Type  : void
//
static void f_binary_expand_op(coder::array<double, 1U> &in1,
                               const coder::array<double, 1U> &in2,
                               const coder::array<double, 1U> &in3,
                               const coder::array<double, 1U> &in4,
                               const coder::array<double, 1U> &in5)
{
  int i;
  int loop_ub;
  int stride_0_0;
  int stride_1_0;
  int stride_2_0;
  int stride_3_0;
  if (in4.size(0) == 1) {
    i = in3.size(0);
  } else {
    i = in4.size(0);
  }
  if (in5.size(0) == 1) {
    if (i == 1) {
      i = in2.size(0);
    } else if (in4.size(0) == 1) {
      i = in3.size(0);
    } else {
      i = in4.size(0);
    }
  } else {
    i = in5.size(0);
  }
  in1.set_size(i);
  stride_0_0 = (in2.size(0) != 1);
  stride_1_0 = (in3.size(0) != 1);
  stride_2_0 = (in4.size(0) != 1);
  stride_3_0 = (in5.size(0) != 1);
  if (in5.size(0) == 1) {
    if (in4.size(0) == 1) {
      i = in3.size(0);
    } else {
      i = in4.size(0);
    }
    if (i == 1) {
      loop_ub = in2.size(0);
    } else if (in4.size(0) == 1) {
      loop_ub = in3.size(0);
    } else {
      loop_ub = in4.size(0);
    }
  } else {
    loop_ub = in5.size(0);
  }
  for (i = 0; i < loop_ub; i++) {
    in1[i] = 3.0 * (in2[i * stride_0_0] *
                        (in3[i * stride_1_0] + in4[i * stride_2_0]) +
                    in5[i * stride_3_0]);
  }
}

//
// Arguments    : coder::array<creal_T, 1U> &in1
//                const coder::array<creal_T, 1U> &in2
//                const coder::array<creal_T, 1U> &in3
// Return Type  : void
//
static void minus(coder::array<creal_T, 1U> &in1,
                  const coder::array<creal_T, 1U> &in2,
                  const coder::array<creal_T, 1U> &in3)
{
  int i;
  int loop_ub;
  int stride_0_0;
  int stride_1_0;
  if (in3.size(0) == 1) {
    i = in2.size(0);
  } else {
    i = in3.size(0);
  }
  in1.set_size(i);
  stride_0_0 = (in2.size(0) != 1);
  stride_1_0 = (in3.size(0) != 1);
  if (in3.size(0) == 1) {
    loop_ub = in2.size(0);
  } else {
    loop_ub = in3.size(0);
  }
  for (i = 0; i < loop_ub; i++) {
    int i1;
    i1 = i * stride_1_0;
    in1[i].re = in2[i * stride_0_0].re - in3[i1].re;
    in1[i].im = in2[i * stride_0_0].im - in3[i1].im;
  }
}

//
// Arguments    : coder::array<creal_T, 1U> &in1
//                const coder::array<creal_T, 1U> &in2
// Return Type  : void
//
static void plus(coder::array<creal_T, 1U> &in1,
                 const coder::array<creal_T, 1U> &in2)
{
  coder::array<creal_T, 1U> b_in1;
  int i;
  int loop_ub;
  int stride_0_0;
  int stride_1_0;
  if (in2.size(0) == 1) {
    i = in1.size(0);
  } else {
    i = in2.size(0);
  }
  b_in1.set_size(i);
  stride_0_0 = (in1.size(0) != 1);
  stride_1_0 = (in2.size(0) != 1);
  if (in2.size(0) == 1) {
    loop_ub = in1.size(0);
  } else {
    loop_ub = in2.size(0);
  }
  for (i = 0; i < loop_ub; i++) {
    int i1;
    i1 = i * stride_1_0;
    b_in1[i].re = in1[i * stride_0_0].re + in2[i1].re;
    b_in1[i].im = in1[i * stride_0_0].im + in2[i1].im;
  }
  in1.set_size(b_in1.size(0));
  loop_ub = b_in1.size(0);
  for (i = 0; i < loop_ub; i++) {
    in1[i] = b_in1[i];
  }
}

//
// Arguments    : coder::array<double, 1U> &in1
//                const coder::array<double, 1U> &in2
//                const coder::array<double, 1U> &in3
// Return Type  : void
//
static void plus(coder::array<double, 1U> &in1,
                 const coder::array<double, 1U> &in2,
                 const coder::array<double, 1U> &in3)
{
  int i;
  int loop_ub;
  int stride_0_0;
  int stride_1_0;
  if (in3.size(0) == 1) {
    i = in2.size(0);
  } else {
    i = in3.size(0);
  }
  in1.set_size(i);
  stride_0_0 = (in2.size(0) != 1);
  stride_1_0 = (in3.size(0) != 1);
  if (in3.size(0) == 1) {
    loop_ub = in2.size(0);
  } else {
    loop_ub = in3.size(0);
  }
  for (i = 0; i < loop_ub; i++) {
    in1[i] = in2[i * stride_0_0] + in3[i * stride_1_0];
  }
}

//
// Arguments    : double u0
//                double u1
// Return Type  : double
//
static double rt_powd_snf(double u0, double u1)
{
  double y;
  if (std::isnan(u0) || std::isnan(u1)) {
    y = rtNaN;
  } else {
    double d;
    double d1;
    d = std::abs(u0);
    d1 = std::abs(u1);
    if (std::isinf(u1)) {
      if (d == 1.0) {
        y = 1.0;
      } else if (d > 1.0) {
        if (u1 > 0.0) {
          y = rtInf;
        } else {
          y = 0.0;
        }
      } else if (u1 > 0.0) {
        y = 0.0;
      } else {
        y = rtInf;
      }
    } else if (d1 == 0.0) {
      y = 1.0;
    } else if (d1 == 1.0) {
      if (u1 > 0.0) {
        y = u0;
      } else {
        y = 1.0 / u0;
      }
    } else if (u1 == 2.0) {
      y = u0 * u0;
    } else if ((u1 == 0.5) && (u0 >= 0.0)) {
      y = std::sqrt(u0);
    } else if ((u0 < 0.0) && (u1 > std::floor(u1))) {
      y = rtNaN;
    } else {
      y = std::pow(u0, u1);
    }
  }
  return y;
}

//
// Arguments    : coder::array<creal_T, 1U> &in1
//                const coder::array<creal_T, 1U> &in2
//                const coder::array<creal_T, 1U> &in3
// Return Type  : void
//
static void times(coder::array<creal_T, 1U> &in1,
                  const coder::array<creal_T, 1U> &in2,
                  const coder::array<creal_T, 1U> &in3)
{
  int i;
  int loop_ub;
  int stride_0_0;
  int stride_1_0;
  if (in3.size(0) == 1) {
    i = in2.size(0);
  } else {
    i = in3.size(0);
  }
  in1.set_size(i);
  stride_0_0 = (in2.size(0) != 1);
  stride_1_0 = (in3.size(0) != 1);
  if (in3.size(0) == 1) {
    loop_ub = in2.size(0);
  } else {
    loop_ub = in3.size(0);
  }
  for (i = 0; i < loop_ub; i++) {
    double b_re_tmp;
    double c_re_tmp;
    int re_tmp;
    re_tmp = i * stride_1_0;
    b_re_tmp = in3[re_tmp].im;
    c_re_tmp = in3[re_tmp].re;
    in1[i].re =
        in2[i * stride_0_0].re * c_re_tmp - in2[i * stride_0_0].im * b_re_tmp;
    in1[i].im =
        in2[i * stride_0_0].re * b_re_tmp + in2[i * stride_0_0].im * c_re_tmp;
  }
}

//
// Arguments    : coder::array<creal_T, 1U> &in1
//                const coder::array<creal_T, 1U> &in2
// Return Type  : void
//
static void times(coder::array<creal_T, 1U> &in1,
                  const coder::array<creal_T, 1U> &in2)
{
  coder::array<creal_T, 1U> b_in2;
  int i;
  int loop_ub;
  int stride_0_0;
  int stride_1_0;
  if (in1.size(0) == 1) {
    i = in2.size(0);
  } else {
    i = in1.size(0);
  }
  b_in2.set_size(i);
  stride_0_0 = (in2.size(0) != 1);
  stride_1_0 = (in1.size(0) != 1);
  if (in1.size(0) == 1) {
    loop_ub = in2.size(0);
  } else {
    loop_ub = in1.size(0);
  }
  for (i = 0; i < loop_ub; i++) {
    double d;
    double d1;
    int i1;
    i1 = i * stride_1_0;
    d = in1[i1].im;
    d1 = in1[i1].re;
    b_in2[i].re = in2[i * stride_0_0].re * d1 - in2[i * stride_0_0].im * d;
    b_in2[i].im = in2[i * stride_0_0].re * d + in2[i * stride_0_0].im * d1;
  }
  in1.set_size(b_in2.size(0));
  loop_ub = b_in2.size(0);
  for (i = 0; i < loop_ub; i++) {
    in1[i] = b_in2[i];
  }
}

//
// Arguments    : coder::array<double, 1U> &in1
//                const coder::array<double, 1U> &in2
// Return Type  : void
//
static void times(coder::array<double, 1U> &in1,
                  const coder::array<double, 1U> &in2)
{
  coder::array<double, 1U> b_in1;
  int i;
  int loop_ub;
  int stride_0_0;
  int stride_1_0;
  if (in2.size(0) == 1) {
    i = in1.size(0);
  } else {
    i = in2.size(0);
  }
  b_in1.set_size(i);
  stride_0_0 = (in1.size(0) != 1);
  stride_1_0 = (in2.size(0) != 1);
  if (in2.size(0) == 1) {
    loop_ub = in1.size(0);
  } else {
    loop_ub = in2.size(0);
  }
  for (i = 0; i < loop_ub; i++) {
    b_in1[i] = in1[i * stride_0_0] * in2[i * stride_1_0];
  }
  in1.set_size(b_in1.size(0));
  loop_ub = b_in1.size(0);
  for (i = 0; i < loop_ub; i++) {
    in1[i] = b_in1[i];
  }
}

//
// Arguments    : coder::array<double, 1U> &in1
//                const coder::array<double, 1U> &in2
//                const coder::array<double, 1U> &in3
// Return Type  : void
//
static void times(coder::array<double, 1U> &in1,
                  const coder::array<double, 1U> &in2,
                  const coder::array<double, 1U> &in3)
{
  int i;
  int loop_ub;
  int stride_0_0;
  int stride_1_0;
  if (in3.size(0) == 1) {
    i = in2.size(0);
  } else {
    i = in3.size(0);
  }
  in1.set_size(i);
  stride_0_0 = (in2.size(0) != 1);
  stride_1_0 = (in3.size(0) != 1);
  if (in3.size(0) == 1) {
    loop_ub = in2.size(0);
  } else {
    loop_ub = in3.size(0);
  }
  for (i = 0; i < loop_ub; i++) {
    in1[i] = in2[i * stride_0_0] * in3[i * stride_1_0];
  }
}

//
// Arguments    : const ::coder::array<creal_T, 1U> &z0
//                const ::coder::array<double, 1U> &theta0
//                const ::coder::array<creal_T, 1U> &z1
//                const ::coder::array<double, 1U> &theta1
//                ::coder::array<double, 1U> &k0
//                ::coder::array<double, 1U> &k1
//                ::coder::array<double, 1U> &l
//                ::coder::array<double, 1U> &dk0_dtheta0
//                ::coder::array<double, 1U> &dk0_dtheta1
//                ::coder::array<double, 1U> &dk1_dtheta0
//                ::coder::array<double, 1U> &dk1_dtheta1
// Return Type  : void
//
namespace coder {
namespace matlabshared {
namespace tracking {
namespace internal {
namespace scenario {
void clothoidG1fit2wp(const ::coder::array<creal_T, 1U> &z0,
                      const ::coder::array<double, 1U> &theta0,
                      const ::coder::array<creal_T, 1U> &z1,
                      const ::coder::array<double, 1U> &theta1,
                      ::coder::array<double, 1U> &k0,
                      ::coder::array<double, 1U> &k1,
                      ::coder::array<double, 1U> &l,
                      ::coder::array<double, 1U> &dk0_dtheta0,
                      ::coder::array<double, 1U> &dk0_dtheta1,
                      ::coder::array<double, 1U> &dk1_dtheta0,
                      ::coder::array<double, 1U> &dk1_dtheta1)
{
  array<creal_T, 1U> b_r;
  array<creal_T, 1U> df_da;
  array<creal_T, 1U> r1;
  array<creal_T, 1U> y;
  array<creal_T, 1U> z;
  array<double, 1U> a;
  array<double, 1U> b_a;
  array<double, 1U> b_k1;
  array<double, 1U> b_phi0;
  array<double, 1U> da_dphi0;
  array<double, 1U> da_dphi1;
  array<double, 1U> ismall;
  array<double, 1U> phi;
  array<double, 1U> phi0;
  array<int, 1U> izero;
  array<bool, 1U> criteria;
  double r;
  int i;
  int k;
  int nx;
  if (z1.size(0) == z0.size(0)) {
    z.set_size(z1.size(0));
    nx = z1.size(0);
    for (k = 0; k < nx; k++) {
      z[k].re = z1[k].re - z0[k].re;
      z[k].im = z1[k].im - z0[k].im;
    }
  } else {
    minus(z, z1, z0);
  }
  nx = z.size(0);
  phi.set_size(z.size(0));
  for (k = 0; k < nx; k++) {
    phi[k] = rt_atan2d_snf(z[k].im, z[k].re);
  }
  if (theta0.size(0) == phi.size(0)) {
    y.set_size(theta0.size(0));
    nx = theta0.size(0);
    for (k = 0; k < nx; k++) {
      r = theta0[k] - phi[k];
      y[k].re = r * 0.0;
      y[k].im = r;
    }
  } else {
    binary_expand_op(y, theta0, phi);
  }
  nx = y.size(0);
  for (k = 0; k < nx; k++) {
    if (y[k].im == 0.0) {
      y[k].re = std::exp(y[k].re);
      y[k].im = 0.0;
    } else if (std::isinf(y[k].im) && std::isinf(y[k].re) && (y[k].re < 0.0)) {
      y[k].re = 0.0;
      y[k].im = 0.0;
    } else {
      r = std::exp(y[k].re / 2.0);
      y[k].re = r * (r * std::cos(y[k].im));
      y[k].im = r * (r * std::sin(y[k].im));
    }
  }
  nx = y.size(0);
  phi0.set_size(y.size(0));
  for (k = 0; k < nx; k++) {
    phi0[k] = rt_atan2d_snf(y[k].im, y[k].re);
  }
  if (theta1.size(0) == phi.size(0)) {
    y.set_size(theta1.size(0));
    nx = theta1.size(0);
    for (k = 0; k < nx; k++) {
      r = theta1[k] - phi[k];
      y[k].re = r * 0.0;
      y[k].im = r;
    }
  } else {
    binary_expand_op(y, theta1, phi);
  }
  nx = y.size(0);
  for (k = 0; k < nx; k++) {
    if (y[k].im == 0.0) {
      y[k].re = std::exp(y[k].re);
      y[k].im = 0.0;
    } else if (std::isinf(y[k].im) && std::isinf(y[k].re) && (y[k].re < 0.0)) {
      y[k].re = 0.0;
      y[k].im = 0.0;
    } else {
      r = std::exp(y[k].re / 2.0);
      y[k].re = r * (r * std::cos(y[k].im));
      y[k].im = r * (r * std::sin(y[k].im));
    }
  }
  nx = y.size(0);
  phi.set_size(y.size(0));
  for (k = 0; k < nx; k++) {
    phi[k] = rt_atan2d_snf(y[k].im, y[k].re);
  }
  if (phi.size(0) == phi0.size(0)) {
    k1.set_size(phi.size(0));
    nx = phi.size(0);
    for (k = 0; k < nx; k++) {
      k1[k] = phi[k] - phi0[k];
    }
  } else {
    minus(k1, phi, phi0);
  }
  fetchAgrad(phi0, phi, a, da_dphi0, da_dphi1);
  y.set_size(a.size(0));
  nx = a.size(0);
  for (k = 0; k < nx; k++) {
    y[k].re = 0.0;
    y[k].im = 0.0;
  }
  df_da.set_size(a.size(0));
  nx = a.size(0);
  for (k = 0; k < nx; k++) {
    df_da[k].re = 0.0;
    df_da[k].im = 0.0;
  }
  if (k1.size(0) == a.size(0)) {
    k0.set_size(k1.size(0));
    nx = k1.size(0);
    for (k = 0; k < nx; k++) {
      k0[k] = k1[k] - a[k];
    }
  } else {
    minus(k0, k1, a);
  }
  phi.set_size(k0.size(0));
  nx = k0.size(0);
  for (k = 0; k < nx; k++) {
    r = k0[k];
    phi[k] = r * r;
  }
  if (phi.size(0) == a.size(0)) {
    nx = phi.size(0);
    for (k = 0; k < nx; k++) {
      phi[k] = phi[k] / (4.0 * a[k]);
    }
  } else {
    binary_expand_op(phi, a);
  }
  nx = phi.size(0);
  ismall.set_size(phi.size(0));
  for (k = 0; k < nx; k++) {
    ismall[k] = std::abs(phi[k]);
  }
  criteria.set_size(ismall.size(0));
  nx = ismall.size(0);
  for (k = 0; k < nx; k++) {
    criteria[k] = (ismall[k] < 628.31853071795865);
  }
  eml_find(criteria, izero);
  phi.set_size(izero.size(0));
  nx = izero.size(0);
  for (k = 0; k < nx; k++) {
    phi[k] = izero[k];
  }
  nx = criteria.size(0);
  for (k = 0; k < nx; k++) {
    criteria[k] = !criteria[k];
  }
  eml_find(criteria, izero);
  ismall.set_size(izero.size(0));
  nx = izero.size(0);
  for (k = 0; k < nx; k++) {
    ismall[k] = izero[k];
  }
  if (k1.size(0) == a.size(0)) {
    criteria.set_size(k1.size(0));
    nx = k1.size(0);
    for (k = 0; k < nx; k++) {
      criteria[k] = ((k1[k] == 0.0) && (a[k] == 0.0));
    }
    eml_find(criteria, izero);
  } else {
    binary_expand_op(izero, k1, a);
  }
  if (phi.size(0) != 0) {
    b_a.set_size(phi.size(0));
    nx = phi.size(0);
    for (k = 0; k < nx; k++) {
      b_a[k] = a[static_cast<int>(phi[k]) - 1];
    }
    b_k1.set_size(phi.size(0));
    nx = phi.size(0);
    for (k = 0; k < nx; k++) {
      b_k1[k] = k1[static_cast<int>(phi[k]) - 1];
    }
    b_phi0.set_size(phi.size(0));
    nx = phi.size(0);
    for (k = 0; k < nx; k++) {
      b_phi0[k] = phi0[static_cast<int>(phi[k]) - 1];
    }
    fresnelgLargea1(b_a, b_k1, b_phi0, b_r, r1);
    nx = b_r.size(0);
    for (k = 0; k < nx; k++) {
      y[static_cast<int>(phi[k]) - 1] = b_r[k];
    }
    nx = r1.size(0);
    for (k = 0; k < nx; k++) {
      df_da[static_cast<int>(phi[k]) - 1] = r1[k];
    }
  }
  if (ismall.size(0) != 0) {
    b_a.set_size(ismall.size(0));
    nx = ismall.size(0);
    for (k = 0; k < nx; k++) {
      b_a[k] = a[static_cast<int>(ismall[k]) - 1];
    }
    b_k1.set_size(ismall.size(0));
    nx = ismall.size(0);
    for (k = 0; k < nx; k++) {
      b_k1[k] = k1[static_cast<int>(ismall[k]) - 1];
    }
    b_phi0.set_size(ismall.size(0));
    nx = ismall.size(0);
    for (k = 0; k < nx; k++) {
      b_phi0[k] = phi0[static_cast<int>(ismall[k]) - 1];
    }
    fresnelgSmalla1(b_a, b_k1, b_phi0, b_r, r1);
    nx = b_r.size(0);
    for (k = 0; k < nx; k++) {
      y[static_cast<int>(ismall[k]) - 1] = b_r[k];
    }
    nx = r1.size(0);
    for (k = 0; k < nx; k++) {
      df_da[static_cast<int>(ismall[k]) - 1] = r1[k];
    }
  }
  if (izero.size(0) != 0) {
    b_r.set_size(izero.size(0));
    nx = izero.size(0);
    for (k = 0; k < nx; k++) {
      r = phi0[izero[k] - 1];
      b_r[k].re = r * 0.0;
      b_r[k].im = r;
    }
    nx = b_r.size(0);
    for (k = 0; k < nx; k++) {
      if (b_r[k].im == 0.0) {
        b_r[k].re = std::exp(b_r[k].re);
        b_r[k].im = 0.0;
      } else if (std::isinf(b_r[k].im) && std::isinf(b_r[k].re) &&
                 (b_r[k].re < 0.0)) {
        b_r[k].re = 0.0;
        b_r[k].im = 0.0;
      } else {
        r = std::exp(b_r[k].re / 2.0);
        b_r[k].re = r * (r * std::cos(b_r[k].im));
        b_r[k].im = r * (r * std::sin(b_r[k].im));
      }
    }
    nx = b_r.size(0);
    for (k = 0; k < nx; k++) {
      y[izero[k] - 1] = b_r[k];
    }
    nx = izero.size(0);
    for (k = 0; k < nx; k++) {
      df_da[izero[k] - 1].re = 0.0;
      df_da[izero[k] - 1].im = 0.0;
    }
  }
  nx = z.size(0);
  l.set_size(z.size(0));
  for (k = 0; k < nx; k++) {
    l[k] = rt_hypotd_snf(z[k].re, z[k].im);
  }
  if (l.size(0) == y.size(0)) {
    nx = l.size(0);
    for (k = 0; k < nx; k++) {
      l[k] = l[k] / y[k].re;
    }
  } else {
    binary_expand_op(l, y);
  }
  nx = z.size(0);
  dk1_dtheta1.set_size(z.size(0));
  for (k = 0; k < nx; k++) {
    dk1_dtheta1[k] = rt_hypotd_snf(z[k].re, z[k].im);
  }
  b_r.set_size(y.size(0));
  nx = y.size(0);
  for (k = 0; k < nx; k++) {
    creal_T varargin_1;
    creal_T varargout_1;
    varargin_1 = y[k];
    varargout_1.re =
        varargin_1.re * varargin_1.re - varargin_1.im * varargin_1.im;
    r = varargin_1.re * varargin_1.im;
    varargout_1.im = r + r;
    b_r[k] = varargout_1;
  }
  if (df_da.size(0) == 1) {
    nx = b_r.size(0);
  } else {
    nx = df_da.size(0);
  }
  if ((df_da.size(0) == b_r.size(0)) && (dk1_dtheta1.size(0) == nx)) {
    nx = dk1_dtheta1.size(0);
    for (k = 0; k < nx; k++) {
      double ai;
      double ar;
      double bi;
      double br;
      ar = df_da[k].re;
      ai = df_da[k].im;
      br = b_r[k].re;
      bi = b_r[k].im;
      if (bi == 0.0) {
        if (ai == 0.0) {
          r = ar / br;
        } else if (ar == 0.0) {
          r = 0.0;
        } else {
          r = ar / br;
        }
      } else if (br == 0.0) {
        if (ar == 0.0) {
          r = ai / bi;
        } else if (ai == 0.0) {
          r = 0.0;
        } else {
          r = ai / bi;
        }
      } else {
        double bim;
        r = std::abs(br);
        bim = std::abs(bi);
        if (r > bim) {
          r = bi / br;
          r = (ar + r * ai) / (br + r * bi);
        } else if (bim == r) {
          if (br > 0.0) {
            br = 0.5;
          } else {
            br = -0.5;
          }
          if (bi > 0.0) {
            bi = 0.5;
          } else {
            bi = -0.5;
          }
          r = (ar * br + ai * bi) / r;
        } else {
          r = br / bi;
          r = (r * ar + ai) / (bi + r * br);
        }
      }
      dk1_dtheta1[k] = -(-dk1_dtheta1[k] * r);
    }
  } else {
    binary_expand_op(dk1_dtheta1, df_da, b_r);
  }
  if (dk1_dtheta1.size(0) == da_dphi0.size(0)) {
    dk1_dtheta0.set_size(dk1_dtheta1.size(0));
    nx = dk1_dtheta1.size(0);
    for (k = 0; k < nx; k++) {
      dk1_dtheta0[k] = dk1_dtheta1[k] * da_dphi0[k];
    }
  } else {
    times(dk1_dtheta0, dk1_dtheta1, da_dphi0);
  }
  phi.set_size(l.size(0));
  nx = l.size(0);
  for (k = 0; k < nx; k++) {
    r = l[k];
    phi[k] = r * r;
  }
  if (dk1_dtheta0.size(0) == 1) {
    nx = phi.size(0);
  } else {
    nx = dk1_dtheta0.size(0);
  }
  if (k0.size(0) == 1) {
    if (dk1_dtheta0.size(0) == 1) {
      k = phi.size(0);
    } else {
      k = dk1_dtheta0.size(0);
    }
  } else {
    k = k0.size(0);
  }
  if (da_dphi0.size(0) == 1) {
    i = l.size(0);
  } else {
    i = da_dphi0.size(0);
  }
  if ((dk1_dtheta0.size(0) == phi.size(0)) && (k0.size(0) == nx) &&
      (da_dphi0.size(0) == l.size(0)) && (k == i)) {
    dk0_dtheta0.set_size(k0.size(0));
    nx = k0.size(0);
    for (k = 0; k < nx; k++) {
      dk0_dtheta0[k] =
          k0[k] * (dk1_dtheta0[k] / phi[k]) + (-1.0 - da_dphi0[k]) / l[k];
    }
  } else {
    e_binary_expand_op(dk0_dtheta0, k0, dk1_dtheta0, phi, da_dphi0, l);
  }
  if (dk1_dtheta1.size(0) == da_dphi1.size(0)) {
    nx = dk1_dtheta1.size(0);
    for (k = 0; k < nx; k++) {
      dk1_dtheta1[k] = dk1_dtheta1[k] * da_dphi1[k];
    }
  } else {
    times(dk1_dtheta1, da_dphi1);
  }
  if (dk1_dtheta1.size(0) == 1) {
    nx = phi.size(0);
  } else {
    nx = dk1_dtheta1.size(0);
  }
  if (k0.size(0) == 1) {
    if (dk1_dtheta1.size(0) == 1) {
      k = phi.size(0);
    } else {
      k = dk1_dtheta1.size(0);
    }
  } else {
    k = k0.size(0);
  }
  if (da_dphi1.size(0) == 1) {
    i = l.size(0);
  } else {
    i = da_dphi1.size(0);
  }
  if ((dk1_dtheta1.size(0) == phi.size(0)) && (k0.size(0) == nx) &&
      (da_dphi1.size(0) == l.size(0)) && (k == i)) {
    dk0_dtheta1.set_size(k0.size(0));
    nx = k0.size(0);
    for (k = 0; k < nx; k++) {
      dk0_dtheta1[k] =
          k0[k] * (dk1_dtheta1[k] / phi[k]) + (1.0 - da_dphi1[k]) / l[k];
    }
  } else {
    binary_expand_op(dk0_dtheta1, k0, dk1_dtheta1, phi, da_dphi1, l);
  }
  if (k1.size(0) == a.size(0)) {
    nx = k1.size(0);
    for (k = 0; k < nx; k++) {
      k1[k] = k1[k] + a[k];
    }
  } else {
    plus(k1, a);
  }
  if (dk1_dtheta0.size(0) == 1) {
    nx = phi.size(0);
  } else {
    nx = dk1_dtheta0.size(0);
  }
  if (k1.size(0) == 1) {
    if (dk1_dtheta0.size(0) == 1) {
      k = phi.size(0);
    } else {
      k = dk1_dtheta0.size(0);
    }
  } else {
    k = k1.size(0);
  }
  if (da_dphi0.size(0) == 1) {
    i = l.size(0);
  } else {
    i = da_dphi0.size(0);
  }
  if ((dk1_dtheta0.size(0) == phi.size(0)) && (k1.size(0) == nx) &&
      (da_dphi0.size(0) == l.size(0)) && (k == i)) {
    dk1_dtheta0.set_size(k1.size(0));
    nx = k1.size(0);
    for (k = 0; k < nx; k++) {
      dk1_dtheta0[k] =
          k1[k] * (dk1_dtheta0[k] / phi[k]) + (da_dphi0[k] + -1.0) / l[k];
    }
  } else {
    e_binary_expand_op(dk1_dtheta0, k1, phi, da_dphi0, l);
  }
  if (dk1_dtheta1.size(0) == 1) {
    nx = phi.size(0);
  } else {
    nx = dk1_dtheta1.size(0);
  }
  if (k1.size(0) == 1) {
    if (dk1_dtheta1.size(0) == 1) {
      k = phi.size(0);
    } else {
      k = dk1_dtheta1.size(0);
    }
  } else {
    k = k1.size(0);
  }
  if (da_dphi1.size(0) == 1) {
    i = l.size(0);
  } else {
    i = da_dphi1.size(0);
  }
  if ((dk1_dtheta1.size(0) == phi.size(0)) && (k1.size(0) == nx) &&
      (da_dphi1.size(0) == l.size(0)) && (k == i)) {
    dk1_dtheta1.set_size(k1.size(0));
    nx = k1.size(0);
    for (k = 0; k < nx; k++) {
      dk1_dtheta1[k] =
          k1[k] * (dk1_dtheta1[k] / phi[k]) + (da_dphi1[k] + 1.0) / l[k];
    }
  } else {
    binary_expand_op(dk1_dtheta1, k1, phi, da_dphi1, l);
  }
  nx = l.size(0);
  for (k = 0; k < nx; k++) {
    if (l[k] == 0.0) {
      dk0_dtheta0[k] = 0.0;
    }
  }
  nx = l.size(0);
  for (k = 0; k < nx; k++) {
    if (l[k] == 0.0) {
      dk0_dtheta1[k] = 0.0;
    }
  }
  nx = l.size(0);
  for (k = 0; k < nx; k++) {
    if (l[k] == 0.0) {
      dk1_dtheta0[k] = 0.0;
    }
  }
  nx = l.size(0);
  for (k = 0; k < nx; k++) {
    if (l[k] == 0.0) {
      dk1_dtheta1[k] = 0.0;
    }
  }
  if (k0.size(0) == l.size(0)) {
    nx = k0.size(0);
    for (k = 0; k < nx; k++) {
      k0[k] = k0[k] / l[k];
    }
  } else {
    rdivide(k0, l);
  }
  if (k1.size(0) == l.size(0)) {
    nx = k1.size(0);
    for (k = 0; k < nx; k++) {
      k1[k] = k1[k] / l[k];
    }
  } else {
    rdivide(k1, l);
  }
  nx = l.size(0);
  for (k = 0; k < nx; k++) {
    if (l[k] == 0.0) {
      k0[k] = 0.0;
    }
  }
  nx = l.size(0);
  for (k = 0; k < nx; k++) {
    if (l[k] == 0.0) {
      k1[k] = 0.0;
    }
  }
}

//
// Arguments    : const ::coder::array<creal_T, 1U> &z0
//                const ::coder::array<double, 1U> &theta0
//                const ::coder::array<creal_T, 1U> &z1
//                const ::coder::array<double, 1U> &theta1
//                ::coder::array<double, 1U> &k0
//                ::coder::array<double, 1U> &k1
//                ::coder::array<double, 1U> &l
// Return Type  : void
//
void clothoidG1fit2wp(const ::coder::array<creal_T, 1U> &z0,
                      const ::coder::array<double, 1U> &theta0,
                      const ::coder::array<creal_T, 1U> &z1,
                      const ::coder::array<double, 1U> &theta1,
                      ::coder::array<double, 1U> &k0,
                      ::coder::array<double, 1U> &k1,
                      ::coder::array<double, 1U> &l)
{
  array<creal_T, 1U> f;
  array<creal_T, 1U> r1;
  array<creal_T, 1U> r2;
  array<creal_T, 1U> z;
  array<double, 2U> cumr;
  array<double, 2U> cums;
  array<double, 2U> varargin_2;
  array<double, 1U> a;
  array<double, 1U> b_a;
  array<double, 1U> b_k1;
  array<double, 1U> b_phi0;
  array<double, 1U> izero;
  array<double, 1U> phi;
  array<double, 1U> phi0;
  array<double, 1U> v;
  array<int, 1U> b_r;
  array<bool, 1U> criteria;
  double j;
  double r;
  int i;
  int ibcol;
  int jtilecol;
  int n;
  int nx;
  signed char input_sizes_idx_1;
  signed char sizes_idx_1;
  bool empty_non_axis_sizes;
  if (z1.size(0) == z0.size(0)) {
    z.set_size(z1.size(0));
    nx = z1.size(0);
    for (jtilecol = 0; jtilecol < nx; jtilecol++) {
      z[jtilecol].re = z1[jtilecol].re - z0[jtilecol].re;
      z[jtilecol].im = z1[jtilecol].im - z0[jtilecol].im;
    }
  } else {
    minus(z, z1, z0);
  }
  nx = z.size(0);
  phi.set_size(z.size(0));
  for (int k{0}; k < nx; k++) {
    phi[k] = rt_atan2d_snf(z[k].im, z[k].re);
  }
  if (theta0.size(0) == phi.size(0)) {
    f.set_size(theta0.size(0));
    nx = theta0.size(0);
    for (jtilecol = 0; jtilecol < nx; jtilecol++) {
      r = theta0[jtilecol] - phi[jtilecol];
      f[jtilecol].re = r * 0.0;
      f[jtilecol].im = r;
    }
  } else {
    binary_expand_op(f, theta0, phi);
  }
  nx = f.size(0);
  for (int k{0}; k < nx; k++) {
    if (f[k].im == 0.0) {
      f[k].re = std::exp(f[k].re);
      f[k].im = 0.0;
    } else if (std::isinf(f[k].im) && std::isinf(f[k].re) && (f[k].re < 0.0)) {
      f[k].re = 0.0;
      f[k].im = 0.0;
    } else {
      r = std::exp(f[k].re / 2.0);
      f[k].re = r * (r * std::cos(f[k].im));
      f[k].im = r * (r * std::sin(f[k].im));
    }
  }
  nx = f.size(0);
  phi0.set_size(f.size(0));
  for (int k{0}; k < nx; k++) {
    phi0[k] = rt_atan2d_snf(f[k].im, f[k].re);
  }
  if (theta1.size(0) == phi.size(0)) {
    f.set_size(theta1.size(0));
    nx = theta1.size(0);
    for (jtilecol = 0; jtilecol < nx; jtilecol++) {
      r = theta1[jtilecol] - phi[jtilecol];
      f[jtilecol].re = r * 0.0;
      f[jtilecol].im = r;
    }
  } else {
    binary_expand_op(f, theta1, phi);
  }
  nx = f.size(0);
  for (int k{0}; k < nx; k++) {
    if (f[k].im == 0.0) {
      f[k].re = std::exp(f[k].re);
      f[k].im = 0.0;
    } else if (std::isinf(f[k].im) && std::isinf(f[k].re) && (f[k].re < 0.0)) {
      f[k].re = 0.0;
      f[k].im = 0.0;
    } else {
      r = std::exp(f[k].re / 2.0);
      f[k].re = r * (r * std::cos(f[k].im));
      f[k].im = r * (r * std::sin(f[k].im));
    }
  }
  nx = f.size(0);
  phi.set_size(f.size(0));
  for (int k{0}; k < nx; k++) {
    phi[k] = rt_atan2d_snf(f[k].im, f[k].re);
  }
  if (phi.size(0) == phi0.size(0)) {
    k1.set_size(phi.size(0));
    nx = phi.size(0);
    for (jtilecol = 0; jtilecol < nx; jtilecol++) {
      k1[jtilecol] = phi[jtilecol] - phi0[jtilecol];
    }
  } else {
    minus(k1, phi, phi0);
  }
  if (phi0.size(0) == phi.size(0)) {
    v.set_size(phi0.size(0));
    nx = phi0.size(0);
    for (jtilecol = 0; jtilecol < nx; jtilecol++) {
      v[jtilecol] = phi0[jtilecol] + phi[jtilecol];
    }
  } else {
    plus(v, phi0, phi);
  }
  n = 350;
  if (phi0.size(0) == phi.size(0)) {
    izero.set_size(phi0.size(0));
    nx = phi0.size(0);
    for (jtilecol = 0; jtilecol < nx; jtilecol++) {
      r = phi0[jtilecol] - phi[jtilecol];
      izero[jtilecol] = r * r;
    }
  } else {
    e_binary_expand_op(izero, phi0, phi);
  }
  varargin_2.set_size(izero.size(0), 25);
  nx = izero.size(0);
  for (jtilecol = 0; jtilecol < 25; jtilecol++) {
    ibcol = jtilecol * nx;
    for (int k{0}; k < nx; k++) {
      varargin_2[ibcol + k] = izero[k];
    }
  }
  if (phi0.size(0) != 0) {
    ibcol = phi0.size(0);
  } else if (varargin_2.size(0) != 0) {
    ibcol = varargin_2.size(0);
  } else {
    ibcol = phi0.size(0);
  }
  empty_non_axis_sizes = (ibcol == 0);
  if (empty_non_axis_sizes || (phi0.size(0) != 0)) {
    input_sizes_idx_1 = 1;
  } else {
    input_sizes_idx_1 = 0;
  }
  if (empty_non_axis_sizes || (varargin_2.size(0) != 0)) {
    sizes_idx_1 = 25;
  } else {
    sizes_idx_1 = 0;
  }
  cumr.set_size(ibcol, input_sizes_idx_1 + sizes_idx_1);
  nx = input_sizes_idx_1;
  for (jtilecol = 0; jtilecol < nx; jtilecol++) {
    for (i = 0; i < ibcol; i++) {
      cumr[i] = 1.0;
    }
  }
  nx = sizes_idx_1;
  for (jtilecol = 0; jtilecol < nx; jtilecol++) {
    for (i = 0; i < ibcol; i++) {
      cumr[i + cumr.size(0) * (jtilecol + input_sizes_idx_1)] =
          varargin_2[i + ibcol * jtilecol];
    }
  }
  if ((cumr.size(0) != 0) && (cumr.size(1) != 0)) {
    jtilecol = cumr.size(1);
    for (int k{0}; k <= jtilecol - 2; k++) {
      i = cumr.size(0);
      for (nx = 0; nx < i; nx++) {
        cumr[nx + cumr.size(0) * (k + 1)] =
            cumr[nx + cumr.size(0) * k] * cumr[nx + cumr.size(0) * (k + 1)];
      }
    }
  }
  izero.set_size(v.size(0));
  nx = v.size(0);
  for (jtilecol = 0; jtilecol < nx; jtilecol++) {
    r = v[jtilecol];
    izero[jtilecol] = r * r;
  }
  varargin_2.set_size(izero.size(0), 25);
  nx = izero.size(0);
  for (jtilecol = 0; jtilecol < 25; jtilecol++) {
    ibcol = jtilecol * nx;
    for (int k{0}; k < nx; k++) {
      varargin_2[ibcol + k] = izero[k];
    }
  }
  if (phi0.size(0) != 0) {
    ibcol = phi0.size(0);
  } else if (varargin_2.size(0) != 0) {
    ibcol = varargin_2.size(0);
  } else {
    ibcol = phi0.size(0);
  }
  empty_non_axis_sizes = (ibcol == 0);
  if (empty_non_axis_sizes || (phi0.size(0) != 0)) {
    input_sizes_idx_1 = 1;
  } else {
    input_sizes_idx_1 = 0;
  }
  if (empty_non_axis_sizes || (varargin_2.size(0) != 0)) {
    sizes_idx_1 = 25;
  } else {
    sizes_idx_1 = 0;
  }
  cums.set_size(ibcol, input_sizes_idx_1 + sizes_idx_1);
  nx = input_sizes_idx_1;
  for (jtilecol = 0; jtilecol < nx; jtilecol++) {
    for (i = 0; i < ibcol; i++) {
      cums[i] = 1.0;
    }
  }
  nx = sizes_idx_1;
  for (jtilecol = 0; jtilecol < nx; jtilecol++) {
    for (i = 0; i < ibcol; i++) {
      cums[i + cums.size(0) * (jtilecol + input_sizes_idx_1)] =
          varargin_2[i + ibcol * jtilecol];
    }
  }
  if ((cums.size(0) != 0) && (cums.size(1) != 0)) {
    jtilecol = cums.size(1);
    for (int k{0}; k <= jtilecol - 2; k++) {
      i = cums.size(0);
      for (nx = 0; nx < i; nx++) {
        cums[nx + cums.size(0) * (k + 1)] =
            cums[nx + cums.size(0) * k] * cums[nx + cums.size(0) * (k + 1)];
      }
    }
  }
  a.set_size(phi0.size(0));
  nx = phi0.size(0);
  for (jtilecol = 0; jtilecol < nx; jtilecol++) {
    a[jtilecol] = 0.0;
  }
  r = 0.0;
  j = 0.0;
  while (n + 1 > 0) {
    if (cumr.size(0) == 1) {
      i = cums.size(0);
    } else {
      i = cumr.size(0);
    }
    if ((cumr.size(0) == cums.size(0)) && (a.size(0) == i)) {
      nx = a.size(0);
      for (jtilecol = 0; jtilecol < nx; jtilecol++) {
        a[jtilecol] =
            a[jtilecol] +
            dv[n] *
                cumr[jtilecol +
                     cumr.size(0) * (static_cast<int>(r + 1.0) - 1)] *
                cums[jtilecol + cums.size(0) * (static_cast<int>(j + 1.0) - 1)];
      }
    } else {
      binary_expand_op(a, dv, n, cumr, r, cums, j);
    }
    j++;
    if (r + j > 25.0) {
      r++;
      j = 0.0;
    }
    n--;
  }
  if (v.size(0) == a.size(0)) {
    a.set_size(v.size(0));
    nx = v.size(0);
    for (jtilecol = 0; jtilecol < nx; jtilecol++) {
      a[jtilecol] = 3.0 * v[jtilecol] * a[jtilecol];
    }
  } else {
    e_binary_expand_op(a, v);
  }
  f.set_size(a.size(0));
  nx = a.size(0);
  for (jtilecol = 0; jtilecol < nx; jtilecol++) {
    f[jtilecol].re = 0.0;
    f[jtilecol].im = 0.0;
  }
  if (k1.size(0) == a.size(0)) {
    k0.set_size(k1.size(0));
    nx = k1.size(0);
    for (jtilecol = 0; jtilecol < nx; jtilecol++) {
      k0[jtilecol] = k1[jtilecol] - a[jtilecol];
    }
  } else {
    minus(k0, k1, a);
  }
  phi.set_size(k0.size(0));
  nx = k0.size(0);
  for (jtilecol = 0; jtilecol < nx; jtilecol++) {
    r = k0[jtilecol];
    phi[jtilecol] = r * r;
  }
  if (phi.size(0) == a.size(0)) {
    nx = phi.size(0);
    for (jtilecol = 0; jtilecol < nx; jtilecol++) {
      phi[jtilecol] = phi[jtilecol] / (4.0 * a[jtilecol]);
    }
  } else {
    binary_expand_op(phi, a);
  }
  nx = phi.size(0);
  izero.set_size(phi.size(0));
  for (int k{0}; k < nx; k++) {
    izero[k] = std::abs(phi[k]);
  }
  criteria.set_size(izero.size(0));
  nx = izero.size(0);
  for (jtilecol = 0; jtilecol < nx; jtilecol++) {
    criteria[jtilecol] = (izero[jtilecol] < 628.31853071795865);
  }
  eml_find(criteria, b_r);
  phi.set_size(b_r.size(0));
  nx = b_r.size(0);
  for (jtilecol = 0; jtilecol < nx; jtilecol++) {
    phi[jtilecol] = b_r[jtilecol];
  }
  nx = criteria.size(0);
  for (jtilecol = 0; jtilecol < nx; jtilecol++) {
    criteria[jtilecol] = !criteria[jtilecol];
  }
  eml_find(criteria, b_r);
  v.set_size(b_r.size(0));
  nx = b_r.size(0);
  for (jtilecol = 0; jtilecol < nx; jtilecol++) {
    v[jtilecol] = b_r[jtilecol];
  }
  if (k1.size(0) == a.size(0)) {
    criteria.set_size(k1.size(0));
    nx = k1.size(0);
    for (jtilecol = 0; jtilecol < nx; jtilecol++) {
      criteria[jtilecol] = ((k1[jtilecol] == 0.0) && (a[jtilecol] == 0.0));
    }
    eml_find(criteria, b_r);
  } else {
    binary_expand_op(b_r, k1, a);
  }
  izero.set_size(b_r.size(0));
  nx = b_r.size(0);
  for (jtilecol = 0; jtilecol < nx; jtilecol++) {
    izero[jtilecol] = b_r[jtilecol];
  }
  if (phi.size(0) != 0) {
    b_a.set_size(phi.size(0));
    nx = phi.size(0);
    for (jtilecol = 0; jtilecol < nx; jtilecol++) {
      b_a[jtilecol] = a[static_cast<int>(phi[jtilecol]) - 1];
    }
    b_k1.set_size(phi.size(0));
    nx = phi.size(0);
    for (jtilecol = 0; jtilecol < nx; jtilecol++) {
      b_k1[jtilecol] = k1[static_cast<int>(phi[jtilecol]) - 1];
    }
    b_phi0.set_size(phi.size(0));
    nx = phi.size(0);
    for (jtilecol = 0; jtilecol < nx; jtilecol++) {
      b_phi0[jtilecol] = phi0[static_cast<int>(phi[jtilecol]) - 1];
    }
    fresnelgLargea1(b_a, b_k1, b_phi0, r1, r2);
    nx = r1.size(0);
    for (jtilecol = 0; jtilecol < nx; jtilecol++) {
      f[static_cast<int>(phi[jtilecol]) - 1] = r1[jtilecol];
    }
  }
  if (v.size(0) != 0) {
    b_a.set_size(v.size(0));
    nx = v.size(0);
    for (jtilecol = 0; jtilecol < nx; jtilecol++) {
      b_a[jtilecol] = a[static_cast<int>(v[jtilecol]) - 1];
    }
    b_k1.set_size(v.size(0));
    nx = v.size(0);
    for (jtilecol = 0; jtilecol < nx; jtilecol++) {
      b_k1[jtilecol] = k1[static_cast<int>(v[jtilecol]) - 1];
    }
    b_phi0.set_size(v.size(0));
    nx = v.size(0);
    for (jtilecol = 0; jtilecol < nx; jtilecol++) {
      b_phi0[jtilecol] = phi0[static_cast<int>(v[jtilecol]) - 1];
    }
    fresnelgSmalla1(b_a, b_k1, b_phi0, r1, r2);
    nx = r1.size(0);
    for (jtilecol = 0; jtilecol < nx; jtilecol++) {
      f[static_cast<int>(v[jtilecol]) - 1] = r1[jtilecol];
    }
  }
  if (izero.size(0) != 0) {
    r1.set_size(izero.size(0));
    nx = izero.size(0);
    for (jtilecol = 0; jtilecol < nx; jtilecol++) {
      r = phi0[static_cast<int>(izero[jtilecol]) - 1];
      r1[jtilecol].re = r * 0.0;
      r1[jtilecol].im = r;
    }
    nx = r1.size(0);
    for (int k{0}; k < nx; k++) {
      if (r1[k].im == 0.0) {
        r1[k].re = std::exp(r1[k].re);
        r1[k].im = 0.0;
      } else if (std::isinf(r1[k].im) && std::isinf(r1[k].re) &&
                 (r1[k].re < 0.0)) {
        r1[k].re = 0.0;
        r1[k].im = 0.0;
      } else {
        r = std::exp(r1[k].re / 2.0);
        r1[k].re = r * (r * std::cos(r1[k].im));
        r1[k].im = r * (r * std::sin(r1[k].im));
      }
    }
    nx = r1.size(0);
    for (jtilecol = 0; jtilecol < nx; jtilecol++) {
      f[static_cast<int>(izero[jtilecol]) - 1] = r1[jtilecol];
    }
  }
  nx = z.size(0);
  l.set_size(z.size(0));
  for (int k{0}; k < nx; k++) {
    l[k] = rt_hypotd_snf(z[k].re, z[k].im);
  }
  if (l.size(0) == f.size(0)) {
    nx = l.size(0);
    for (jtilecol = 0; jtilecol < nx; jtilecol++) {
      l[jtilecol] = l[jtilecol] / f[jtilecol].re;
    }
  } else {
    binary_expand_op(l, f);
  }
  if (k0.size(0) == l.size(0)) {
    nx = k0.size(0);
    for (jtilecol = 0; jtilecol < nx; jtilecol++) {
      k0[jtilecol] = k0[jtilecol] / l[jtilecol];
    }
  } else {
    rdivide(k0, l);
  }
  if (k1.size(0) == 1) {
    i = a.size(0);
  } else {
    i = k1.size(0);
  }
  if ((k1.size(0) == a.size(0)) && (i == l.size(0))) {
    nx = k1.size(0);
    for (jtilecol = 0; jtilecol < nx; jtilecol++) {
      k1[jtilecol] = (k1[jtilecol] + a[jtilecol]) / l[jtilecol];
    }
  } else {
    binary_expand_op(k1, a, l);
  }
  nx = l.size(0);
  for (ibcol = 0; ibcol < nx; ibcol++) {
    if (l[ibcol] == 0.0) {
      k0[ibcol] = 0.0;
    }
  }
  nx = l.size(0);
  for (ibcol = 0; ibcol < nx; ibcol++) {
    if (l[ibcol] == 0.0) {
      k1[ibcol] = 0.0;
    }
  }
}

//
// Arguments    : coder::array<double, 1U> &in1
//                const coder::array<double, 1U> &in2
//                const coder::array<double, 1U> &in3
// Return Type  : void
//
} // namespace scenario
} // namespace internal
} // namespace tracking
} // namespace matlabshared
} // namespace coder
void minus(coder::array<double, 1U> &in1, const coder::array<double, 1U> &in2,
           const coder::array<double, 1U> &in3)
{
  int i;
  int loop_ub;
  int stride_0_0;
  int stride_1_0;
  if (in3.size(0) == 1) {
    i = in2.size(0);
  } else {
    i = in3.size(0);
  }
  in1.set_size(i);
  stride_0_0 = (in2.size(0) != 1);
  stride_1_0 = (in3.size(0) != 1);
  if (in3.size(0) == 1) {
    loop_ub = in2.size(0);
  } else {
    loop_ub = in3.size(0);
  }
  for (i = 0; i < loop_ub; i++) {
    in1[i] = in2[i * stride_0_0] - in3[i * stride_1_0];
  }
}

//
// Arguments    : coder::array<double, 1U> &in1
//                const coder::array<double, 1U> &in2
// Return Type  : void
//
void plus(coder::array<double, 1U> &in1, const coder::array<double, 1U> &in2)
{
  coder::array<double, 1U> b_in1;
  int i;
  int loop_ub;
  int stride_0_0;
  int stride_1_0;
  if (in2.size(0) == 1) {
    i = in1.size(0);
  } else {
    i = in2.size(0);
  }
  b_in1.set_size(i);
  stride_0_0 = (in1.size(0) != 1);
  stride_1_0 = (in2.size(0) != 1);
  if (in2.size(0) == 1) {
    loop_ub = in1.size(0);
  } else {
    loop_ub = in2.size(0);
  }
  for (i = 0; i < loop_ub; i++) {
    b_in1[i] = in1[i * stride_0_0] + in2[i * stride_1_0];
  }
  in1.set_size(b_in1.size(0));
  loop_ub = b_in1.size(0);
  for (i = 0; i < loop_ub; i++) {
    in1[i] = b_in1[i];
  }
}

//
// File trailer for clothoidG1fit2wp.cpp
//
// [EOF]
//
