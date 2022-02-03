//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
// File: clothoidG1fit2wp.cpp
//
// MATLAB Coder version            : 5.3
// C/C++ source code generated on  : 03-Feb-2022 14:08:22
//

// Include Files
#include "clothoidG1fit2wp.h"
#include "find.h"
#include "fresnel.h"
#include "power.h"
#include "proc_planner_data.h"
#include "proc_planner_rtwutil.h"
#include "rt_nonfinite.h"
#include "sqrt.h"
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
namespace coder {
namespace matlabshared {
namespace tracking {
namespace internal {
namespace scenario {
static void fetchA(const ::coder::array<double, 1U> &x,
                   const ::coder::array<double, 1U> &y,
                   ::coder::array<double, 1U> &a);

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

// Function Definitions
//
// Arguments    : const ::coder::array<double, 1U> &x
//                const ::coder::array<double, 1U> &y
//                ::coder::array<double, 1U> &a
// Return Type  : void
//
namespace coder {
namespace matlabshared {
namespace tracking {
namespace internal {
namespace scenario {
static void fetchA(const ::coder::array<double, 1U> &x,
                   const ::coder::array<double, 1U> &y,
                   ::coder::array<double, 1U> &a)
{
  array<double, 2U> cumr;
  array<double, 2U> cums;
  array<double, 2U> varargin_2;
  array<double, 1U> r;
  array<double, 1U> s;
  array<double, 1U> v;
  double b_i;
  double j;
  int i;
  int ibcol;
  int jtilecol;
  int k;
  int n;
  int nx;
  signed char input_sizes_idx_1;
  signed char sizes_idx_1;
  bool empty_non_axis_sizes;
  v.set_size(x.size(0));
  nx = x.size(0);
  for (jtilecol = 0; jtilecol < nx; jtilecol++) {
    v[jtilecol] = x[jtilecol] + y[jtilecol];
  }
  a.set_size(x.size(0));
  nx = x.size(0);
  for (jtilecol = 0; jtilecol < nx; jtilecol++) {
    a[jtilecol] = x[jtilecol] - y[jtilecol];
  }
  r.set_size(a.size(0));
  nx = a.size(0);
  for (k = 0; k < nx; k++) {
    r[k] = a[k] * a[k];
  }
  s.set_size(v.size(0));
  nx = v.size(0);
  for (k = 0; k < nx; k++) {
    s[k] = v[k] * v[k];
  }
  n = 351;
  varargin_2.set_size(r.size(0), 25);
  nx = r.size(0);
  for (jtilecol = 0; jtilecol < 25; jtilecol++) {
    ibcol = jtilecol * nx;
    for (k = 0; k < nx; k++) {
      varargin_2[ibcol + k] = r[k];
    }
  }
  if (x.size(0) != 0) {
    ibcol = x.size(0);
  } else if (varargin_2.size(0) != 0) {
    ibcol = varargin_2.size(0);
  } else {
    ibcol = x.size(0);
  }
  empty_non_axis_sizes = (ibcol == 0);
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
    for (k = 0; k <= jtilecol - 2; k++) {
      i = cumr.size(0);
      for (nx = 0; nx < i; nx++) {
        cumr[nx + cumr.size(0) * (k + 1)] =
            cumr[nx + cumr.size(0) * k] * cumr[nx + cumr.size(0) * (k + 1)];
      }
    }
  }
  varargin_2.set_size(s.size(0), 25);
  nx = s.size(0);
  for (jtilecol = 0; jtilecol < 25; jtilecol++) {
    ibcol = jtilecol * nx;
    for (k = 0; k < nx; k++) {
      varargin_2[ibcol + k] = s[k];
    }
  }
  if (x.size(0) != 0) {
    ibcol = x.size(0);
  } else if (varargin_2.size(0) != 0) {
    ibcol = varargin_2.size(0);
  } else {
    ibcol = x.size(0);
  }
  empty_non_axis_sizes = (ibcol == 0);
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
    for (k = 0; k <= jtilecol - 2; k++) {
      i = cums.size(0);
      for (nx = 0; nx < i; nx++) {
        cums[nx + cums.size(0) * (k + 1)] =
            cums[nx + cums.size(0) * k] * cums[nx + cums.size(0) * (k + 1)];
      }
    }
  }
  a.set_size(x.size(0));
  nx = x.size(0);
  for (jtilecol = 0; jtilecol < nx; jtilecol++) {
    a[jtilecol] = 0.0;
  }
  b_i = 0.0;
  j = 0.0;
  while (n > 0) {
    nx = a.size(0);
    for (jtilecol = 0; jtilecol < nx; jtilecol++) {
      a[jtilecol] =
          a[jtilecol] +
          dv[n - 1] *
              cumr[jtilecol +
                   cumr.size(0) * (static_cast<int>(b_i + 1.0) - 1)] *
              cums[jtilecol + cums.size(0) * (static_cast<int>(j + 1.0) - 1)];
    }
    j++;
    if (b_i + j > 25.0) {
      b_i++;
      j = 0.0;
    }
    n--;
  }
  a.set_size(v.size(0));
  nx = v.size(0);
  for (jtilecol = 0; jtilecol < nx; jtilecol++) {
    a[jtilecol] = 3.0 * v[jtilecol] * a[jtilecol];
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
static void fetchAgrad(const ::coder::array<double, 1U> &x,
                       const ::coder::array<double, 1U> &y,
                       ::coder::array<double, 1U> &a,
                       ::coder::array<double, 1U> &dadx,
                       ::coder::array<double, 1U> &dady)
{
  array<double, 2U> cumr;
  array<double, 2U> cums;
  array<double, 2U> varargin_2;
  array<double, 1U> r;
  array<double, 1U> s;
  array<double, 1U> u;
  array<double, 1U> v;
  int i;
  int ibcol;
  int k;
  int loop_ub;
  int n;
  int nx;
  signed char input_sizes_idx_1;
  signed char sizes_idx_1;
  bool empty_non_axis_sizes;
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
  r.set_size(u.size(0));
  nx = u.size(0);
  for (k = 0; k < nx; k++) {
    r[k] = u[k] * u[k];
  }
  s.set_size(v.size(0));
  nx = v.size(0);
  for (k = 0; k < nx; k++) {
    s[k] = v[k] * v[k];
  }
  n = 350;
  varargin_2.set_size(r.size(0), 25);
  nx = r.size(0);
  for (loop_ub = 0; loop_ub < 25; loop_ub++) {
    ibcol = loop_ub * nx;
    for (k = 0; k < nx; k++) {
      varargin_2[ibcol + k] = r[k];
    }
  }
  if (x.size(0) != 0) {
    nx = x.size(0);
  } else if (varargin_2.size(0) != 0) {
    nx = varargin_2.size(0);
  } else {
    nx = x.size(0);
  }
  empty_non_axis_sizes = (nx == 0);
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
  cumr.set_size(nx, input_sizes_idx_1 + sizes_idx_1);
  loop_ub = input_sizes_idx_1;
  for (i = 0; i < loop_ub; i++) {
    for (ibcol = 0; ibcol < nx; ibcol++) {
      cumr[ibcol] = 1.0;
    }
  }
  loop_ub = sizes_idx_1;
  for (i = 0; i < loop_ub; i++) {
    for (ibcol = 0; ibcol < nx; ibcol++) {
      cumr[ibcol + cumr.size(0) * (i + input_sizes_idx_1)] =
          varargin_2[ibcol + nx * i];
    }
  }
  if ((cumr.size(0) != 0) && (cumr.size(1) != 0)) {
    i = cumr.size(1);
    for (k = 0; k <= i - 2; k++) {
      ibcol = cumr.size(0);
      for (nx = 0; nx < ibcol; nx++) {
        cumr[nx + cumr.size(0) * (k + 1)] =
            cumr[nx + cumr.size(0) * k] * cumr[nx + cumr.size(0) * (k + 1)];
      }
    }
  }
  varargin_2.set_size(s.size(0), 25);
  nx = s.size(0);
  for (loop_ub = 0; loop_ub < 25; loop_ub++) {
    ibcol = loop_ub * nx;
    for (k = 0; k < nx; k++) {
      varargin_2[ibcol + k] = s[k];
    }
  }
  if (x.size(0) != 0) {
    nx = x.size(0);
  } else if (varargin_2.size(0) != 0) {
    nx = varargin_2.size(0);
  } else {
    nx = x.size(0);
  }
  empty_non_axis_sizes = (nx == 0);
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
  cums.set_size(nx, input_sizes_idx_1 + sizes_idx_1);
  loop_ub = input_sizes_idx_1;
  for (i = 0; i < loop_ub; i++) {
    for (ibcol = 0; ibcol < nx; ibcol++) {
      cums[ibcol] = 1.0;
    }
  }
  loop_ub = sizes_idx_1;
  for (i = 0; i < loop_ub; i++) {
    for (ibcol = 0; ibcol < nx; ibcol++) {
      cums[ibcol + cums.size(0) * (i + input_sizes_idx_1)] =
          varargin_2[ibcol + nx * i];
    }
  }
  if ((cums.size(0) != 0) && (cums.size(1) != 0)) {
    i = cums.size(1);
    for (k = 0; k <= i - 2; k++) {
      ibcol = cums.size(0);
      for (nx = 0; nx < ibcol; nx++) {
        cums[nx + cums.size(0) * (k + 1)] =
            cums[nx + cums.size(0) * k] * cums[nx + cums.size(0) * (k + 1)];
      }
    }
  }
  a.set_size(x.size(0));
  loop_ub = x.size(0);
  for (i = 0; i < loop_ub; i++) {
    a[i] = 0.0;
  }
  r.set_size(x.size(0));
  loop_ub = x.size(0);
  for (i = 0; i < loop_ub; i++) {
    r[i] = 0.0;
  }
  s.set_size(x.size(0));
  loop_ub = x.size(0);
  for (i = 0; i < loop_ub; i++) {
    s[i] = 0.0;
  }
  nx = 0;
  ibcol = 0;
  while (n + 1 > 0) {
    double b_i;
    loop_ub = a.size(0);
    for (i = 0; i < loop_ub; i++) {
      a[i] = a[i] + dv[n] * cumr[i + cumr.size(0) * nx] *
                        cums[i + cums.size(0) * ibcol];
    }
    if (nx > 0) {
      b_i = (static_cast<double>(nx) + 1.0) * dv[n];
      loop_ub = r.size(0);
      for (i = 0; i < loop_ub; i++) {
        r[i] = r[i] + b_i * cumr[i + cumr.size(0) * (nx - 1)] *
                          cums[i + cums.size(0) * ibcol];
      }
    }
    if (ibcol > 0) {
      b_i = (static_cast<double>(ibcol) + 1.0) * dv[n];
      loop_ub = s.size(0);
      for (i = 0; i < loop_ub; i++) {
        s[i] = s[i] + b_i * cumr[i + cumr.size(0) * nx] *
                          cums[i + cums.size(0) * (ibcol - 1)];
      }
    }
    ibcol++;
    if (nx + ibcol > 25) {
      nx++;
      ibcol = 0;
    }
    n--;
  }
  loop_ub = s.size(0);
  for (i = 0; i < loop_ub; i++) {
    s[i] = s[i] * v[i];
  }
  loop_ub = r.size(0);
  for (i = 0; i < loop_ub; i++) {
    r[i] = r[i] * u[i];
  }
  dady.set_size(v.size(0));
  loop_ub = v.size(0);
  for (i = 0; i < loop_ub; i++) {
    dady[i] = 2.0 * v[i];
  }
  dadx.set_size(dady.size(0));
  loop_ub = dady.size(0);
  for (i = 0; i < loop_ub; i++) {
    dadx[i] = 3.0 * (dady[i] * (s[i] + r[i]) + a[i]);
  }
  loop_ub = dady.size(0);
  for (i = 0; i < loop_ub; i++) {
    dady[i] = 3.0 * (dady[i] * (s[i] - r[i]) + a[i]);
  }
  a.set_size(v.size(0));
  loop_ub = v.size(0);
  for (i = 0; i < loop_ub; i++) {
    a[i] = 3.0 * v[i] * a[i];
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
  array<creal_T, 1U> c_b;
  array<creal_T, 1U> d_x;
  array<creal_T, 1U> da2;
  array<creal_T, 1U> fa;
  array<creal_T, 1U> s;
  array<creal_T, 1U> x;
  array<double, 1U> b_a;
  array<double, 1U> b_x;
  array<double, 1U> b_y_tmp;
  array<double, 1U> c_x;
  array<double, 1U> ratio;
  array<double, 1U> y_tmp;
  double ar;
  double bi;
  double br;
  double brm;
  double im;
  double r;
  double re;
  double re_tmp;
  double sgnbr;
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
  ratio.set_size(d.size(0));
  nx = d.size(0);
  for (k = 0; k < nx; k++) {
    ratio[k] = d[k] - a[k];
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
  x.set_size(a1.size(0));
  nx = a1.size(0);
  for (k = 0; k < nx; k++) {
    x[k].re = a1[k].re + a2[k].re;
    x[k].im = a1[k].im + a2[k].im;
  }
  b_x.set_size(x.size(0));
  nx = x.size(0);
  for (k = 0; k < nx; k++) {
    b_x[k] = x[k].re;
  }
  fresnelr(b_x, fa);
  b_x.set_size(x.size(0));
  nx = x.size(0);
  for (k = 0; k < nx; k++) {
    b_x[k] = -x[k].im;
  }
  fresnelr(b_x, b);
  nx = b.size(0);
  for (k = 0; k < nx; k++) {
    b[k].im = -b[k].im;
  }
  b_x.set_size(a2.size(0));
  nx = a2.size(0);
  for (k = 0; k < nx; k++) {
    b_x[k] = a2[k].re;
  }
  fresnelr(b_x, x);
  b_x.set_size(a2.size(0));
  nx = a2.size(0);
  for (k = 0; k < nx; k++) {
    b_x[k] = -a2[k].im;
  }
  fresnelr(b_x, s);
  nx = s.size(0);
  for (k = 0; k < nx; k++) {
    s[k].im = -s[k].im;
  }
  nx = fa.size(0);
  for (k = 0; k < nx; k++) {
    re_tmp = b[k].im;
    r = b[k].re;
    br = s[k].im;
    brm = s[k].re;
    fa[k].re = (fa[k].re + (0.0 * r - re_tmp)) - (x[k].re + (0.0 * brm - br));
    fa[k].im = (fa[k].im + (0.0 * re_tmp + r)) - (x[k].im + (0.0 * br + brm));
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
  b_x.set_size(a.size(0));
  nx = a.size(0);
  for (k = 0; k < nx; k++) {
    b_x[k] = 4.0 * a[k];
  }
  b_a.set_size(d.size(0));
  nx = d.size(0);
  for (k = 0; k < nx; k++) {
    b_a[k] = d[k] - a[k];
  }
  c_x.set_size(b_a.size(0));
  nx = b_a.size(0);
  for (k = 0; k < nx; k++) {
    c_x[k] = b_a[k] * b_a[k];
  }
  b_r.set_size(c.size(0));
  nx = c.size(0);
  for (k = 0; k < nx; k++) {
    r = c[k] - c_x[k] / b_x[k];
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
  drsfa.set_size(s.size(0));
  nx = s.size(0);
  for (k = 0; k < nx; k++) {
    r = s[k].re;
    br = b_r[k].im;
    brm = s[k].im;
    sgnbr = b_r[k].re;
    drsfa[k].re = r * sgnbr - brm * br;
    drsfa[k].im = r * br + brm * sgnbr;
  }
  rsfa.set_size(drsfa.size(0));
  nx = drsfa.size(0);
  for (k = 0; k < nx; k++) {
    r = drsfa[k].re;
    br = fa[k].im;
    brm = drsfa[k].im;
    sgnbr = fa[k].re;
    rsfa[k].re = r * sgnbr - brm * br;
    rsfa[k].im = r * br + brm * sgnbr;
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
  d_x.set_size(b_y_tmp.size(0));
  nx = b_y_tmp.size(0);
  for (k = 0; k < nx; k++) {
    d_x[k].re = b_y_tmp[k];
    d_x[k].im = 0.0;
  }
  nx = d_x.size(0);
  for (k = 0; k < nx; k++) {
    ::coder::internal::scalar::b_sqrt(&d_x[k]);
  }
  power(d_x, da2);
  d_x.set_size(b_y_tmp.size(0));
  nx = b_y_tmp.size(0);
  for (k = 0; k < nx; k++) {
    d_x[k].re = b_y_tmp[k];
    d_x[k].im = 0.0;
  }
  nx = d_x.size(0);
  for (k = 0; k < nx; k++) {
    ::coder::internal::scalar::b_sqrt(&d_x[k]);
  }
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
    br = d_x[k].re;
    bi = d_x[k].im;
    if (bi == 0.0) {
      br = 1.0 / br;
      r = 0.0;
    } else if (br == 0.0) {
      br = 0.0;
      r = -(1.0 / bi);
    } else {
      brm = std::abs(br);
      r = std::abs(bi);
      if (brm > r) {
        brm = bi / br;
        r = br + brm * bi;
        br = (brm * 0.0 + 1.0) / r;
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
        br = (sgnbr + 0.0 * r) / brm;
        r = (0.0 * sgnbr - r) / brm;
      } else {
        brm = br / bi;
        r = bi + brm * br;
        br = brm / r;
        r = (brm * 0.0 - 1.0) / r;
      }
    }
    da2[k].re = ratio[k] * re - br;
    da2[k].im = ratio[k] * im - r;
  }
  nx = a1.size(0);
  for (k = 0; k < nx; k++) {
    a1[k].re = a1[k].re + a2[k].re;
    a1[k].im = a1[k].im + a2[k].im;
  }
  b_b.set_size(a1.size(0));
  nx = a1.size(0);
  for (k = 0; k < nx; k++) {
    r = a1[k].re;
    br = a1[k].im;
    b_b[k].re = r * r - br * br;
    r *= br;
    b_b[k].im = r + r;
  }
  nx = b_b.size(0);
  for (k = 0; k < nx; k++) {
    re_tmp = b_b[k].im;
    r = b_b[k].re;
    b_b[k].re = 0.0 * r - 1.5707963267948966 * re_tmp;
    b_b[k].im = 0.0 * re_tmp + 1.5707963267948966 * r;
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
  c_b.set_size(a2.size(0));
  nx = a2.size(0);
  for (k = 0; k < nx; k++) {
    r = a2[k].re;
    br = a2[k].im;
    c_b[k].re = r * r - br * br;
    r *= br;
    c_b[k].im = r + r;
  }
  nx = c_b.size(0);
  for (k = 0; k < nx; k++) {
    re_tmp = c_b[k].im;
    r = c_b[k].re;
    c_b[k].re = 0.0 * r - 1.5707963267948966 * re_tmp;
    c_b[k].im = 0.0 * re_tmp + 1.5707963267948966 * r;
  }
  nx = c_b.size(0);
  for (k = 0; k < nx; k++) {
    if (c_b[k].im == 0.0) {
      c_b[k].re = std::exp(c_b[k].re);
      c_b[k].im = 0.0;
    } else if (std::isinf(c_b[k].im) && std::isinf(c_b[k].re) &&
               (c_b[k].re < 0.0)) {
      c_b[k].re = 0.0;
      c_b[k].im = 0.0;
    } else {
      r = std::exp(c_b[k].re / 2.0);
      c_b[k].re = r * (r * std::cos(c_b[k].im));
      c_b[k].im = r * (r * std::sin(c_b[k].im));
    }
  }
  b_y_tmp.set_size(a.size(0));
  nx = a.size(0);
  for (k = 0; k < nx; k++) {
    b_y_tmp[k] = a[k];
  }
  nx = a.size(0);
  for (k = 0; k < nx; k++) {
    r = b_y_tmp[k];
    if (b_y_tmp[k] < 0.0) {
      r = -1.0;
    } else if (b_y_tmp[k] > 0.0) {
      r = 1.0;
    } else if (b_y_tmp[k] == 0.0) {
      r = 0.0;
    }
    b_y_tmp[k] = r;
  }
  d_x.set_size(y_tmp.size(0));
  nx = y_tmp.size(0);
  for (k = 0; k < nx; k++) {
    d_x[k].re = 3.1415926535897931 / y_tmp[k];
    d_x[k].im = 0.0;
  }
  nx = d_x.size(0);
  for (k = 0; k < nx; k++) {
    ::coder::internal::scalar::b_sqrt(&d_x[k]);
  }
  power(d_x, b);
  nx = b.size(0);
  for (k = 0; k < nx; k++) {
    b[k].re = -b[k].re;
    b[k].im = -b[k].im;
  }
  nx = ratio.size(0);
  for (k = 0; k < nx; k++) {
    ratio[k] = ratio[k] / b_x[k];
  }
  nx = drsfa.size(0);
  for (k = 0; k < nx; k++) {
    double b_drsfa_re_tmp;
    double drsfa_re_tmp;
    double y_tmp_im;
    double y_tmp_re;
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
    re_tmp = da2[k].re;
    re += re_tmp;
    r = da2[k].im;
    im += r;
    br = b_b[k].re;
    brm = b_b[k].im;
    sgnbr = c_b[k].re;
    bi = c_b[k].im;
    y_tmp_re = b_y_tmp[k] * ((br * re - brm * im) - (sgnbr * re_tmp - bi * r));
    y_tmp_im = b_y_tmp[k] * ((br * im + brm * re) - (sgnbr * r + bi * re_tmp));
    drsfa_re_tmp = drsfa[k].re;
    b_drsfa_re_tmp = drsfa[k].im;
    re_tmp = b_r[k].re;
    im = b_r[k].im;
    r = 2.0 * ratio[k] + 1.0;
    re = r * (ratio[k] * (re_tmp * 0.0 - im * 2.0));
    sgnbr = r * (ratio[k] * (re_tmp * 2.0 + im * 0.0));
    bi = s[k].re;
    brm = s[k].im;
    ar = b[k].re;
    r = b[k].im;
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
    ar = (bi * re - brm * sgnbr) + (re_tmp * br - im * r);
    r = (bi * sgnbr + brm * re) + (re_tmp * r + im * br);
    br = fa[k].re;
    brm = fa[k].im;
    drsfa[k].re = (drsfa_re_tmp * y_tmp_re - b_drsfa_re_tmp * y_tmp_im) +
                  (br * ar - brm * r);
    drsfa[k].im = (drsfa_re_tmp * y_tmp_im + b_drsfa_re_tmp * y_tmp_re) +
                  (br * r + brm * ar);
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
  array<double, 1U> b_y;
  array<double, 1U> c_y;
  array<double, 1U> dk;
  array<double, 1U> k;
  array<double, 1U> y;
  double ai;
  double ar;
  double br;
  double r;
  double re;
  double y_tmp_re;
  int b_k;
  int i;
  int nx;
  dk.set_size(a.size(0));
  nx = a.size(0);
  for (i = 0; i < nx; i++) {
    dk[i] = 2.0 * a[i];
  }
  k.set_size(d.size(0));
  nx = d.size(0);
  for (i = 0; i < nx; i++) {
    k[i] = d[i] - a[i];
  }
  y_tmp.set_size(dk.size(0));
  nx = dk.size(0);
  for (i = 0; i < nx; i++) {
    y_tmp[i].re = dk[i] * 0.0;
    y_tmp[i].im = dk[i] * 0.5;
  }
  y.set_size(k.size(0));
  nx = k.size(0);
  for (b_k = 0; b_k < nx; b_k++) {
    y[b_k] = k[b_k] * k[b_k];
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
  m2C.set_size(y_tmp.size(0));
  nx = y_tmp.size(0);
  for (i = 0; i < nx; i++) {
    ar = y_tmp[i].re;
    ai = y_tmp[i].im;
    br = y[i];
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
  b_y.set_size(k.size(0));
  nx = k.size(0);
  for (b_k = 0; b_k < nx; b_k++) {
    b_y[b_k] = rt_powd_snf(k[b_k], 3.0);
  }
  dm2C.set_size(dk.size(0));
  nx = dk.size(0);
  for (i = 0; i < nx; i++) {
    ar = -(0.0 * dk[i] + 0.0 * k[i]);
    ai = -(2.0 * dk[i] + 2.0 * k[i]);
    br = b_y[i];
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
  c_y.set_size(k.size(0));
  nx = k.size(0);
  for (b_k = 0; b_k < nx; b_k++) {
    c_y[b_k] = k[b_k] * k[b_k];
  }
  dt.set_size(k.size(0));
  nx = k.size(0);
  for (i = 0; i < nx; i++) {
    y_tmp_re = dp[i].re;
    r = dp[i].im;
    ar = -(k[i] * y_tmp_re + (0.0 * (y_tmp_re - 1.0) - r));
    ai = -(k[i] * r + (0.0 * r + (y_tmp_re - 1.0)));
    br = c_y[i];
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
      re = rtNaN;
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
    int i1;
    int loop_ub;
    i = 2 * (n + 1) - 1;
    loop_ub = t.size(0);
    for (i1 = 0; i1 < loop_ub; i1++) {
      n_re = (static_cast<double>(n) + 1.0) + nik[i1].re;
      ar = nik[i1].im;
      r = e[i1].im;
      y_tmp_re = e[i1].re;
      t[i1].re = static_cast<double>(i) * t[i1].re + (n_re * y_tmp_re - ar * r);
      t[i1].im = static_cast<double>(i) * t[i1].im + (n_re * r + ar * y_tmp_re);
    }
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
    t.set_size(m2C.size(0));
    for (i = 0; i < b_k; i++) {
      br = m2C[i].re;
      ai = t[i].im;
      r = m2C[i].im;
      y_tmp_re = t[i].re;
      t[i].re = br * y_tmp_re - r * ai;
      t[i].im = br * ai + r * y_tmp_re;
    }
    loop_ub = dz.size(0);
    for (i = 0; i < loop_ub; i++) {
      dz[i].re = dz[i].re + dt[i].re;
      dz[i].im = dz[i].im + dt[i].im;
    }
    loop_ub = z.size(0);
    for (i = 0; i < loop_ub; i++) {
      z[i].re = z[i].re + t[i].re;
      z[i].im = z[i].im + t[i].im;
    }
    loop_ub = e.size(0);
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
    loop_ub = e.size(0);
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
  nx = z.size(0);
  for (i = 0; i < nx; i++) {
    br = z[i].re;
    ai = y_tmp[i].im;
    r = z[i].im;
    y_tmp_re = y_tmp[i].re;
    z[i].re = br * y_tmp_re - r * ai;
    z[i].im = br * ai + r * y_tmp_re;
  }
  nx = dz.size(0);
  for (i = 0; i < nx; i++) {
    br = dz[i].re;
    ai = y_tmp[i].im;
    r = dz[i].im;
    y_tmp_re = y_tmp[i].re;
    dz[i].re = br * y_tmp_re - r * ai;
    dz[i].im = br * ai + r * y_tmp_re;
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
  array<creal_T, 1U> b_y;
  array<creal_T, 1U> df_da;
  array<creal_T, 1U> r1;
  array<creal_T, 1U> y;
  array<creal_T, 1U> z;
  array<double, 1U> a;
  array<double, 1U> b_a;
  array<double, 1U> b_k1;
  array<double, 1U> b_phi0;
  array<double, 1U> c_y;
  array<double, 1U> d_y;
  array<double, 1U> da_dphi0;
  array<double, 1U> da_dphi1;
  array<double, 1U> ismall;
  array<double, 1U> phi;
  array<double, 1U> phi0;
  array<int, 1U> ii;
  array<bool, 1U> criteria;
  double bim;
  double r;
  int k;
  int nx;
  z.set_size(z1.size(0));
  nx = z1.size(0);
  for (k = 0; k < nx; k++) {
    z[k].re = z1[k].re - z0[k].re;
    z[k].im = z1[k].im - z0[k].im;
  }
  nx = z.size(0);
  phi.set_size(z.size(0));
  for (k = 0; k < nx; k++) {
    phi[k] = rt_atan2d_snf(z[k].im, z[k].re);
  }
  y.set_size(theta0.size(0));
  nx = theta0.size(0);
  for (k = 0; k < nx; k++) {
    r = theta0[k] - phi[k];
    y[k].re = r * 0.0;
    y[k].im = r;
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
  y.set_size(theta1.size(0));
  nx = theta1.size(0);
  for (k = 0; k < nx; k++) {
    r = theta1[k] - phi[k];
    y[k].re = r * 0.0;
    y[k].im = r;
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
  k1.set_size(phi.size(0));
  nx = phi.size(0);
  for (k = 0; k < nx; k++) {
    k1[k] = phi[k] - phi0[k];
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
  phi.set_size(k1.size(0));
  nx = k1.size(0);
  for (k = 0; k < nx; k++) {
    phi[k] = k1[k] - a[k];
  }
  ismall.set_size(phi.size(0));
  nx = phi.size(0);
  for (k = 0; k < nx; k++) {
    ismall[k] = phi[k] * phi[k];
  }
  nx = ismall.size(0);
  for (k = 0; k < nx; k++) {
    ismall[k] = ismall[k] / (4.0 * a[k]);
  }
  nx = ismall.size(0);
  phi.set_size(ismall.size(0));
  for (k = 0; k < nx; k++) {
    phi[k] = std::abs(ismall[k]);
  }
  criteria.set_size(phi.size(0));
  nx = phi.size(0);
  for (k = 0; k < nx; k++) {
    criteria[k] = (phi[k] < 628.31853071795865);
  }
  eml_find(criteria, ii);
  phi.set_size(ii.size(0));
  nx = ii.size(0);
  for (k = 0; k < nx; k++) {
    phi[k] = ii[k];
  }
  nx = criteria.size(0);
  for (k = 0; k < nx; k++) {
    criteria[k] = !criteria[k];
  }
  eml_find(criteria, ii);
  ismall.set_size(ii.size(0));
  nx = ii.size(0);
  for (k = 0; k < nx; k++) {
    ismall[k] = ii[k];
  }
  criteria.set_size(k1.size(0));
  nx = k1.size(0);
  for (k = 0; k < nx; k++) {
    criteria[k] = ((k1[k] == 0.0) && (a[k] == 0.0));
  }
  eml_find(criteria, ii);
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
  if (ii.size(0) != 0) {
    b_r.set_size(ii.size(0));
    nx = ii.size(0);
    for (k = 0; k < nx; k++) {
      r = phi0[ii[k] - 1];
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
      y[ii[k] - 1] = b_r[k];
    }
    nx = ii.size(0);
    for (k = 0; k < nx; k++) {
      df_da[ii[k] - 1].re = 0.0;
      df_da[ii[k] - 1].im = 0.0;
    }
  }
  nx = z.size(0);
  l.set_size(z.size(0));
  for (k = 0; k < nx; k++) {
    l[k] = rt_hypotd_snf(z[k].re, z[k].im);
  }
  nx = l.size(0);
  for (k = 0; k < nx; k++) {
    l[k] = l[k] / y[k].re;
  }
  nx = z.size(0);
  dk1_dtheta1.set_size(z.size(0));
  for (k = 0; k < nx; k++) {
    dk1_dtheta1[k] = rt_hypotd_snf(z[k].re, z[k].im);
  }
  b_y.set_size(y.size(0));
  nx = y.size(0);
  for (k = 0; k < nx; k++) {
    r = y[k].re;
    bim = y[k].im;
    b_y[k].re = r * r - bim * bim;
    r *= bim;
    b_y[k].im = r + r;
  }
  nx = dk1_dtheta1.size(0);
  for (k = 0; k < nx; k++) {
    double ai;
    double ar;
    double bi;
    double br;
    ar = df_da[k].re;
    ai = df_da[k].im;
    br = b_y[k].re;
    bi = b_y[k].im;
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
  dk1_dtheta0.set_size(dk1_dtheta1.size(0));
  nx = dk1_dtheta1.size(0);
  for (k = 0; k < nx; k++) {
    dk1_dtheta0[k] = dk1_dtheta1[k] * da_dphi0[k];
  }
  dk0_dtheta0.set_size(l.size(0));
  nx = l.size(0);
  for (k = 0; k < nx; k++) {
    dk0_dtheta0[k] = l[k] * l[k];
  }
  k0.set_size(k1.size(0));
  nx = k1.size(0);
  for (k = 0; k < nx; k++) {
    k0[k] = k1[k] - a[k];
  }
  dk0_dtheta0.set_size(k0.size(0));
  nx = k0.size(0);
  for (k = 0; k < nx; k++) {
    dk0_dtheta0[k] =
        k0[k] * (dk1_dtheta0[k] / dk0_dtheta0[k]) + (-1.0 - da_dphi0[k]) / l[k];
  }
  nx = dk1_dtheta1.size(0);
  for (k = 0; k < nx; k++) {
    dk1_dtheta1[k] = dk1_dtheta1[k] * da_dphi1[k];
  }
  dk0_dtheta1.set_size(l.size(0));
  nx = l.size(0);
  for (k = 0; k < nx; k++) {
    dk0_dtheta1[k] = l[k] * l[k];
  }
  dk0_dtheta1.set_size(k0.size(0));
  nx = k0.size(0);
  for (k = 0; k < nx; k++) {
    dk0_dtheta1[k] =
        k0[k] * (dk1_dtheta1[k] / dk0_dtheta1[k]) + (1.0 - da_dphi1[k]) / l[k];
  }
  c_y.set_size(l.size(0));
  nx = l.size(0);
  for (k = 0; k < nx; k++) {
    c_y[k] = l[k] * l[k];
  }
  nx = k1.size(0);
  for (k = 0; k < nx; k++) {
    k1[k] = k1[k] + a[k];
  }
  dk1_dtheta0.set_size(k1.size(0));
  nx = k1.size(0);
  for (k = 0; k < nx; k++) {
    dk1_dtheta0[k] =
        k1[k] * (dk1_dtheta0[k] / c_y[k]) + (da_dphi0[k] + -1.0) / l[k];
  }
  d_y.set_size(l.size(0));
  nx = l.size(0);
  for (k = 0; k < nx; k++) {
    d_y[k] = l[k] * l[k];
  }
  dk1_dtheta1.set_size(k1.size(0));
  nx = k1.size(0);
  for (k = 0; k < nx; k++) {
    dk1_dtheta1[k] =
        k1[k] * (dk1_dtheta1[k] / d_y[k]) + (da_dphi1[k] + 1.0) / l[k];
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
  nx = k0.size(0);
  for (k = 0; k < nx; k++) {
    k0[k] = k0[k] / l[k];
  }
  nx = k1.size(0);
  for (k = 0; k < nx; k++) {
    k1[k] = k1[k] / l[k];
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
  array<creal_T, 1U> b_r;
  array<creal_T, 1U> f;
  array<creal_T, 1U> r1;
  array<creal_T, 1U> z;
  array<double, 1U> a;
  array<double, 1U> b_a;
  array<double, 1U> b_k1;
  array<double, 1U> b_phi0;
  array<double, 1U> ismall;
  array<double, 1U> phi;
  array<double, 1U> phi0;
  array<int, 1U> ii;
  array<bool, 1U> criteria;
  double r;
  int k;
  int nx;
  z.set_size(z1.size(0));
  nx = z1.size(0);
  for (k = 0; k < nx; k++) {
    z[k].re = z1[k].re - z0[k].re;
    z[k].im = z1[k].im - z0[k].im;
  }
  nx = z.size(0);
  phi.set_size(z.size(0));
  for (k = 0; k < nx; k++) {
    phi[k] = rt_atan2d_snf(z[k].im, z[k].re);
  }
  f.set_size(theta0.size(0));
  nx = theta0.size(0);
  for (k = 0; k < nx; k++) {
    r = theta0[k] - phi[k];
    f[k].re = r * 0.0;
    f[k].im = r;
  }
  nx = f.size(0);
  for (k = 0; k < nx; k++) {
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
  for (k = 0; k < nx; k++) {
    phi0[k] = rt_atan2d_snf(f[k].im, f[k].re);
  }
  f.set_size(theta1.size(0));
  nx = theta1.size(0);
  for (k = 0; k < nx; k++) {
    r = theta1[k] - phi[k];
    f[k].re = r * 0.0;
    f[k].im = r;
  }
  nx = f.size(0);
  for (k = 0; k < nx; k++) {
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
  for (k = 0; k < nx; k++) {
    phi[k] = rt_atan2d_snf(f[k].im, f[k].re);
  }
  k1.set_size(phi.size(0));
  nx = phi.size(0);
  for (k = 0; k < nx; k++) {
    k1[k] = phi[k] - phi0[k];
  }
  fetchA(phi0, phi, a);
  f.set_size(a.size(0));
  nx = a.size(0);
  for (k = 0; k < nx; k++) {
    f[k].re = 0.0;
    f[k].im = 0.0;
  }
  phi.set_size(k1.size(0));
  nx = k1.size(0);
  for (k = 0; k < nx; k++) {
    phi[k] = k1[k] - a[k];
  }
  ismall.set_size(phi.size(0));
  nx = phi.size(0);
  for (k = 0; k < nx; k++) {
    ismall[k] = phi[k] * phi[k];
  }
  nx = ismall.size(0);
  for (k = 0; k < nx; k++) {
    ismall[k] = ismall[k] / (4.0 * a[k]);
  }
  nx = ismall.size(0);
  phi.set_size(ismall.size(0));
  for (k = 0; k < nx; k++) {
    phi[k] = std::abs(ismall[k]);
  }
  criteria.set_size(phi.size(0));
  nx = phi.size(0);
  for (k = 0; k < nx; k++) {
    criteria[k] = (phi[k] < 628.31853071795865);
  }
  eml_find(criteria, ii);
  phi.set_size(ii.size(0));
  nx = ii.size(0);
  for (k = 0; k < nx; k++) {
    phi[k] = ii[k];
  }
  nx = criteria.size(0);
  for (k = 0; k < nx; k++) {
    criteria[k] = !criteria[k];
  }
  eml_find(criteria, ii);
  ismall.set_size(ii.size(0));
  nx = ii.size(0);
  for (k = 0; k < nx; k++) {
    ismall[k] = ii[k];
  }
  criteria.set_size(k1.size(0));
  nx = k1.size(0);
  for (k = 0; k < nx; k++) {
    criteria[k] = ((k1[k] == 0.0) && (a[k] == 0.0));
  }
  eml_find(criteria, ii);
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
      f[static_cast<int>(phi[k]) - 1] = b_r[k];
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
      f[static_cast<int>(ismall[k]) - 1] = b_r[k];
    }
  }
  if (ii.size(0) != 0) {
    b_r.set_size(ii.size(0));
    nx = ii.size(0);
    for (k = 0; k < nx; k++) {
      r = phi0[ii[k] - 1];
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
      f[ii[k] - 1] = b_r[k];
    }
  }
  nx = z.size(0);
  l.set_size(z.size(0));
  for (k = 0; k < nx; k++) {
    l[k] = rt_hypotd_snf(z[k].re, z[k].im);
  }
  nx = l.size(0);
  for (k = 0; k < nx; k++) {
    l[k] = l[k] / f[k].re;
  }
  k0.set_size(k1.size(0));
  nx = k1.size(0);
  for (k = 0; k < nx; k++) {
    k0[k] = (k1[k] - a[k]) / l[k];
  }
  nx = k1.size(0);
  for (k = 0; k < nx; k++) {
    k1[k] = (k1[k] + a[k]) / l[k];
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

} // namespace scenario
} // namespace internal
} // namespace tracking
} // namespace matlabshared
} // namespace coder

//
// File trailer for clothoidG1fit2wp.cpp
//
// [EOF]
//
