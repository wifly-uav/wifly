#ifndef RTW_HEADER_air_part1_python2_h_
#define RTW_HEADER_air_part1_python2_h_
#ifndef air_part1_python2_COMMON_INCLUDES_
#define air_part1_python2_COMMON_INCLUDES_
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include "sl_AsyncioQueue/AsyncioQueueCAPI.h"
#include "rtwtypes.h"
#include "sigstream_rtw.h"
#include "simtarget/slSimTgtSigstreamRTW.h"
#include "simtarget/slSimTgtSlioCoreRTW.h"
#include "simtarget/slSimTgtSlioClientsRTW.h"
#include "simtarget/slSimTgtSlioSdiRTW.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "raccel.h"
#include "slsv_diagnostic_codegen_c_api.h"
#include "rt_logging_simtarget.h"
#include "dt_info.h"
#include "ext_work.h"
#include "asynciocoder_api.hpp"
#include "coder_posix_time.h"
#endif
#include "air_part1_python2_types.h"
#include "rtGetInf.h"
#include "rt_nonfinite.h"
#include <stddef.h>
#include <string.h>
#include <float.h>
#include "mwmathutil.h"
#include "rtw_modelmap_simtarget.h"
#include "rt_defines.h"
#define MODEL_NAME air_part1_python2
#define NSAMPLE_TIMES (7) 
#define NINPUTS (0)       
#define NOUTPUTS (0)     
#define NBLOCKIO (99) 
#define NUM_ZC_EVENTS (0) 
#ifndef NCSTATES
#define NCSTATES (8)   
#elif NCSTATES != 8
#error Invalid specification of NCSTATES defined in compiler command
#endif
#ifndef rtmGetDataMapInfo
#define rtmGetDataMapInfo(rtm) (*rt_dataMapInfoPtr)
#endif
#ifndef rtmSetDataMapInfo
#define rtmSetDataMapInfo(rtm, val) (rt_dataMapInfoPtr = &val)
#endif
#ifndef IN_RACCEL_MAIN
#endif
typedef struct { real_T a0dacr3vu5 ; real_T dxojvg2mzp ; real_T ftth4nxmgz ;
real_T d0v1fgzgtc ; } jaojyey2gb ; typedef struct { real_T etkpdfh3bw ;
real_T hogtdrsbl0 ; real_T ayo4a0rtpb ; } ocg145ebmd ; typedef struct {
real_T fsek3luzie ; } dooynonrws ; typedef struct { real_T jb2b5najpv ; }
clfyjfqiuu ; typedef struct { real_T n5nj1b05gf ; } b332zk4fge ; typedef
struct { real_T nf3awaueuw ; } l3mdrvvpuy ; typedef struct { real_T
o5vabvlgjn ; } gywknl2xur ; typedef struct { char_T b_devicePluginPath_data [
4097 ] ; char_T b_converterPluginPath_data [ 4097 ] ; char_T
b_devicePluginPath_data_mbvzarwird [ 4097 ] ; char_T
b_converterPluginPath_data_cl54gopm0x [ 4097 ] ; real_T a405zozv5t ; real_T
buugn1y4kg ; real_T m0fvlyj223 ; real_T mqpvdapacf ; real_T frqdqeq5gg ;
real_T itbqmhqgrz ; real_T e4k3uwbbqo ; real_T oj1fmvrj3c ; real_T i54d4oicep
; real_T ku0cdrtwff ; real_T bwgs3crvzk ; real_T exrmi0ldfj ; real_T
be3gvejel2 ; real_T lonvbzqzr1 ; real_T firups0wj2 ; real_T mjlpzkqz1n ;
real_T etvoly05ch ; real_T gkuq4mb5x4 ; real_T gg1qdr0ca0 ; real_T fn1r3pr3py
; real_T gyqrec4ceq ; real_T a3plauwk5y ; real_T facwgsdsd1 ; real_T
ha2jxgqr02 ; real_T htcqv5fxtd ; real_T a43mlssova ; real_T goi1oiwwan ;
real_T bzfi1eqihy ; real_T k2tv1y1gn5 ; real_T mfao3xhxn3 ; real_T hyhxikiti2
; real_T bkayq3jpfr ; real_T arjieh1qz2 ; real_T b0atyboa0x ; real_T
ov41nszkfe ; real_T ff3s1fh5wh ; real_T crmbrbsz2x ; real_T hhfhv1g453 ;
real_T pdvh3wfivp ; real_T n4zpljasue ; real_T m0wxbflasp ; real_T ipbondrkcl
; real_T jqaxfynhz3 ; real_T oqvlx0tggb ; real_T klwp3o5znj ; real_T
omvc30ouxs ; real_T n0yzexgdyh ; real_T atbvn2nrjn ; real_T d3mqkoc1ln ;
real_T mnvxcylwkr ; real_T pgeeu4rvpl ; real_T aeq3t23mz4 ; real_T fywlqxnu4j
; real_T nzqgm2nb3k ; real_T iewiqnu5gm ; real_T c1l0t1ppoz ; real_T
p4ublk43y4 ; uint32_T otnxjer3d0 ; uint8_T hjr01anyo4 [ 128 ] ; uint8_T
f3ybeuoetm [ 128 ] ; uint8_T iar4fhawbp [ 256 ] ; uint8_T ixgganvvtz ;
uint8_T ktsgdw2c41 ; uint8_T mimixuazso ; uint8_T jbdewy33ag ; uint8_T
jyujvnq2h1 ; uint8_T kmzeugzpgl ; uint8_T lpstap4ud2 [ 6 ] ; b332zk4fge
ktoqcjl1wu ; gywknl2xur elpvuejile ; l3mdrvvpuy eoqlazxz1z ; dooynonrws
c21bk5qnit ; ocg145ebmd f2cxkdl2mb ; b332zk4fge hwhgormc0n ; clfyjfqiuu
aelnqmel4f ; dooynonrws p2tfl52njg ; b332zk4fge jdelhdqjdy ; gywknl2xur
dgjrsvf3r0 ; l3mdrvvpuy ch5un3rjrb ; dooynonrws dwjvl3kmbe ; ocg145ebmd
fisn2ndewy ; b332zk4fge jsqwvo4npa ; clfyjfqiuu ixdl5r0pbu ; dooynonrws
c5fiym5p0p ; ocg145ebmd fvmfewdhwz ; jaojyey2gb btyuoi1co3 ; jaojyey2gb
ojl1qzu4tl ; } B ; typedef struct { dp0kdzdsab hwcuhwqvaz ; gvzvlbrjok
bvsrcp4u0i ; real_T l30tmqcnmm ; real_T njuyqff5u5 ; real_T iv3sxafqgs ;
real_T dahp1m1tnz ; real_T egmxveifc2 ; real_T nyak4kxjb0 ; real_T jrcajuutzs
; real_T bto3rz2afq ; real_T l4a3zwvtji ; real_T ecriaizrd0 ; real_T
evnfi3oakh ; real_T jqu0hns3uo ; real_T ajtguqv0em ; real_T b42g2henkn ;
real_T omefgf0cmg ; real_T eo5jyafoo5 ; real_T leiplki144 ; real_T g4ztp0b3on
; real_T oujf1dobik ; real_T pcv4wpi3ke ; real_T cbkkysibro ; real_T
akkonxbiyb ; real_T e33if4mgu4 ; real_T bkzeyuvdfi ; real_T jsetdp311j ;
real_T ha3ig5blsd ; real_T og3gej3jwz ; real_T pv2wfqzep2 ; real_T lakc2myacn
; real_T ohxmf4okd1 ; real_T jhaog44chc ; real_T ovo4hnxxnn ; real_T
hpm14ul0f3 ; real_T lkqen1tuni ; real_T ly5fhjl0pp ; real_T hiojixic5x ;
real_T ps3do31sj3 ; real_T mutemtyha2 ; real_T dhidrj0fdd ; real_T frxhgtfui5
; real_T lrysnrlfpz ; real_T fl21cmk5gk ; real_T h4ow2pync3 ; real_T
juomdslsik ; real_T js0lpcxyrc ; real_T e0edvudjse ; real_T cmm1vcvsn0 ;
real_T e13leb2tmm ; real_T inoqsfj0bw ; real_T mkxeuv2wc4 ; real_T dzzfid2chy
; real_T iz0phm120z ; real_T jlvcxty141 ; real_T dfsexifu4j ; struct { real_T
modelTStart ; } csw4zgvz1w ; struct { real_T modelTStart ; } lvn51ym2qo ;
struct { void * LoggedData ; } ijbiiwv2x1 ; struct { void * LoggedData ; }
kveuuyfcbs ; struct { void * LoggedData [ 3 ] ; } ciksye3m2u ; struct { void
* LoggedData [ 2 ] ; } jjh53xgtjl ; struct { void * LoggedData [ 3 ] ; }
dnhlundi3t ; struct { void * LoggedData [ 2 ] ; } ekwl0yqhsl ; struct { void
* LoggedData [ 2 ] ; } gsignuaw3o ; struct { void * LoggedData ; } jejtfjwqmh
; struct { void * LoggedData ; } bupitfmcrk ; void * gnziensnjw ; void *
flhcdf5cvg ; struct { void * AQHandles ; } mngvkp03ok ; struct { void *
AQHandles ; } bpkyyz2duh ; struct { void * AQHandles ; } gwcnekeexx ; struct
{ void * AQHandles ; } jzk55zhlch ; void * kao0trtwi5 [ 2 ] ; void *
okuzazai0s [ 2 ] ; void * pjgwumfyer [ 2 ] ; void * bmpybbr13l [ 2 ] ; void *
omnw5jj5ix [ 2 ] ; void * lt2xcx2ium [ 2 ] ; struct { void * TUbufferPtrs [ 2
] ; } pqulut3liz ; struct { void * TUbufferPtrs [ 2 ] ; } l24xckmdwx ; struct
{ void * LoggedData [ 2 ] ; } klrq4rnhqt ; struct { void * LoggedData ; }
jg1r1xv5jr ; struct { void * LoggedData ; } kkqpashrw5 ; struct { void *
LoggedData ; } ddrfqg2rek ; struct { void * LoggedData [ 2 ] ; } m3niq5rmug ;
struct { void * LoggedData ; } iwjbducmiq ; struct { void * LoggedData ; }
fdx4hqpd4d ; struct { void * LoggedData ; } onas52at42 ; struct { void *
LoggedData ; } ofdy3judrz ; struct { void * LoggedData ; } lozknuzswx ;
struct { void * LoggedData ; } pxxwkrx4sy ; struct { void * LoggedData ; }
ausvdyw0ag ; struct { void * LoggedData [ 2 ] ; } e0uvnzzdpa ; struct { void
* LoggedData ; } no1psf0mla ; struct { void * LoggedData ; } nuq2c3y2p2 ;
struct { void * LoggedData ; } jynhzjtulm ; struct { void * LoggedData ; }
jmbpewghqz ; struct { void * LoggedData ; } m554pxlqkb ; struct { void *
LoggedData ; } ngedooco0b ; struct { void * LoggedData [ 2 ] ; } c2e0arl3lb ;
struct { void * LoggedData ; } ow1b3l1s50 ; struct { void * LoggedData ; }
fjp5nmo3l5 ; struct { void * LoggedData ; } lg2i4xshxy ; struct { void *
LoggedData ; } lomz1vuozo ; struct { void * LoggedData ; } cz25bzuoih ;
struct { void * LoggedData [ 2 ] ; } omnabmm4il ; struct { void * LoggedData
; } eq3jhhlhby ; struct { void * LoggedData ; } hk0dpsz2d0 ; struct { void *
LoggedData ; } p3scgmzmwc ; struct { void * LoggedData ; } lagebt4c04 ;
uint32_T jl0mnuibbh ; uint32_T baqauvm4f0 ; uint32_T eam5on10cp ; int_T
f0ny4gmuvx [ 4 ] ; int_T l3xbscxi2g [ 4 ] ; int_T dcitng5a3n [ 4 ] ; int_T
jmc5mhc4s2 [ 4 ] ; int_T exvrlracxo [ 4 ] ; int_T p22db1quvf [ 4 ] ; int_T
euinuevdxm [ 4 ] ; struct { int_T Tail ; int_T Head ; int_T Last ; int_T
CircularBufSize ; int_T MaxNewBufSize ; } mr2aud2zdd ; struct { int_T Tail ;
int_T Head ; int_T Last ; int_T CircularBufSize ; int_T MaxNewBufSize ; }
hmazbcxsfm ; uint8_T ag0g5gwgl3 ; uint8_T bspqyhc1ui ; boolean_T gvaglrbdot ;
boolean_T ottvoj0yqy ; boolean_T dhockh40iz ; boolean_T cosaluxqrd ;
boolean_T ehbdlfy2zi ; boolean_T hkguujkgog ; boolean_T nkmva5gdkf ;
boolean_T k043rv4keo ; boolean_T mmap3xsiti ; boolean_T nmtkuzrjds ;
boolean_T nbwsx1apcl ; boolean_T gmsb3q2zlj ; boolean_T iaghp1202d ;
boolean_T jpzpmlt0aw ; } DW ; typedef struct { real_T eypdcundes ; real_T
lh2zlfy5gs ; real_T o2miuctf5t ; real_T g1kxrlwt1c ; real_T m0ift0f3ns ;
real_T lq2uwsqwxu ; real_T fl2s00rq4n ; real_T cb0w3bhvxx ; } X ; typedef
struct { real_T eypdcundes ; real_T lh2zlfy5gs ; real_T o2miuctf5t ; real_T
g1kxrlwt1c ; real_T m0ift0f3ns ; real_T lq2uwsqwxu ; real_T fl2s00rq4n ;
real_T cb0w3bhvxx ; } XDot ; typedef struct { boolean_T eypdcundes ;
boolean_T lh2zlfy5gs ; boolean_T o2miuctf5t ; boolean_T g1kxrlwt1c ;
boolean_T m0ift0f3ns ; boolean_T lq2uwsqwxu ; boolean_T fl2s00rq4n ;
boolean_T cb0w3bhvxx ; } XDis ; typedef struct { rtwCAPI_ModelMappingInfo mmi
; } DataMapInfo ; struct P_ { real_T PWM_Period ; real_T PWM1_Period ; real_T
BandLimitedWhiteNoise1_seed ; real_T BandLimitedWhiteNoise_seed ; uint32_T
WrapToZero_Threshold ; real_T Integrator1_IC ; real_T Gain ; real_T
Integrator_IC ; real_T Integrator1_IC_aul1jddy20 ; real_T u_Gain ; real_T
Gain_Gain ; real_T u_Gain_fqvbril3va ; real_T Saturation_UpperSat ; real_T
Saturation_LowerSat ; real_T Gain_Gain_an1pdnuefr ; real_T Switch_Threshold ;
real_T Switch1_Threshold ; real_T Integrator3_IC ; real_T Integrator2_IC ;
real_T u_Gain_b4npwylgl1 ; real_T Integrator_IC_edh1bx55d3 ; real_T
u_Gain_lklkiehjn3 ; real_T u_Gain_pcqi2zh5ks ; real_T WhiteNoise_Mean ;
real_T WhiteNoise_StdDev ; real_T Output_Gain ; real_T Gain_Gain_iih4ui3cnf ;
real_T Integrator1_IC_p55ptnmnhu ; real_T _Gain ; real_T
Integrator_IC_ltzbm21qdw ; real_T ASCIIEncode_P1_Size [ 2 ] ; real_T
ASCIIEncode_P1 [ 4 ] ; real_T ASCIIEncode_P2_Size [ 2 ] ; real_T
ASCIIEncode_P2 ; real_T ASCIIEncode_P3_Size [ 2 ] ; real_T ASCIIEncode_P3 ;
real_T ASCIIEncode_P4_Size [ 2 ] ; real_T ASCIIEncode_P4 ; real_T
ASCIIEncode1_P1_Size [ 2 ] ; real_T ASCIIEncode1_P1 [ 4 ] ; real_T
ASCIIEncode1_P2_Size [ 2 ] ; real_T ASCIIEncode1_P2 ; real_T
ASCIIEncode1_P3_Size [ 2 ] ; real_T ASCIIEncode1_P3 ; real_T
ASCIIEncode1_P4_Size [ 2 ] ; real_T ASCIIEncode1_P4 ; real_T
Saturation_UpperSat_gxwe5io0f4 ; real_T Saturation_LowerSat_ggci1m3fwr ;
real_T Saturation_UpperSat_nctbwbdtp3 ; real_T Saturation_LowerSat_khkejnf40e
; real_T ASCIIDecode_P1_Size [ 2 ] ; real_T ASCIIDecode_P1 [ 3 ] ; real_T
ASCIIDecode_P2_Size [ 2 ] ; real_T ASCIIDecode_P2 ; real_T
ASCIIDecode_P3_Size [ 2 ] ; real_T ASCIIDecode_P3 ; real_T
ASCIIDecode1_P1_Size [ 2 ] ; real_T ASCIIDecode1_P1 [ 3 ] ; real_T
ASCIIDecode1_P2_Size [ 2 ] ; real_T ASCIIDecode1_P2 ; real_T
ASCIIDecode1_P3_Size [ 2 ] ; real_T ASCIIDecode1_P3 ; real_T
ASCIIDecode2_P1_Size [ 2 ] ; real_T ASCIIDecode2_P1 [ 3 ] ; real_T
ASCIIDecode2_P2_Size [ 2 ] ; real_T ASCIIDecode2_P2 ; real_T
ASCIIDecode2_P3_Size [ 2 ] ; real_T ASCIIDecode2_P3 ; real_T
ASCIIDecode3_P1_Size [ 2 ] ; real_T ASCIIDecode3_P1 [ 3 ] ; real_T
ASCIIDecode3_P2_Size [ 2 ] ; real_T ASCIIDecode3_P2 ; real_T
ASCIIDecode3_P3_Size [ 2 ] ; real_T ASCIIDecode3_P3 ; real_T
ASCIIDecode4_P1_Size [ 2 ] ; real_T ASCIIDecode4_P1 [ 3 ] ; real_T
ASCIIDecode4_P2_Size [ 2 ] ; real_T ASCIIDecode4_P2 ; real_T
ASCIIDecode4_P3_Size [ 2 ] ; real_T ASCIIDecode4_P3 ; real_T
ASCIIDecode5_P1_Size [ 2 ] ; real_T ASCIIDecode5_P1 [ 3 ] ; real_T
ASCIIDecode5_P2_Size [ 2 ] ; real_T ASCIIDecode5_P2 ; real_T
ASCIIDecode5_P3_Size [ 2 ] ; real_T ASCIIDecode5_P3 ; real_T
WhiteNoise_Mean_cm2ydxtnvw ; real_T WhiteNoise_StdDev_iarpuhegie ; real_T
Output_Gain_kseoije4vl ; real_T Gain1_Gain ; real_T
VariableTimeDelay1_MaxDelay ; real_T VariableTimeDelay1_InitOutput ; real_T
VariableTimeDelay_MaxDelay ; real_T VariableTimeDelay_InitOutput ; real_T
Switch2_Threshold ; real_T Switch3_Threshold ; real_T Gain_Gain_gqjpcqg2pu ;
real_T Gain_Gain_oodfwwlgw5 ; real_T Gain_dcquyu5zec ; real_T
u_Gain_i3zbnwm4y2 ; real_T u_Gain_pqq0pxqop5 ; real_T u_Gain_m2whdurejq ;
real_T u_Gain_iw0b3pebia ; real_T Gain_o44e2s1oov ; real_T _Gain_igqv4gz3am ;
real_T _Gain_ezpdmdm44b ; real_T _Gain_ocd1v2y2wv ; real_T _Gain_jqvyrpyhlw ;
real_T _Gain_dq53dumoid ; real_T _Gain_a2p4tfbpm4 ; real_T _Gain_iaiof1ych2 ;
real_T _Gain_ec3r4dr3zn ; real_T _Gain_nwjfwxlfng ; real_T Gain_c5zyi33wrb ;
real_T _Gain_fl03d5u1kp ; real_T u_Gain_gp00rtkqtb ; real_T _Gain_ex1r0c12fd
; real_T Gain_jvjms1w3ad ; real_T _Gain_lcqhixjq0z ; real_T _Gain_ni4xvt1vxz
; real_T u_Gain_jngffoyzbc ; real_T u_Gain_nudgobpj1r ; real_T
u_Gain_mdaasjyeq0 ; real_T a_Value ; real_T a1_Value ; real_T a2_Value ;
real_T a3_Value ; real_T a4_Value ; real_T a5_Value ; real_T a6_Value ;
real_T a7_Value ; real_T b_Value ; real_T c_Value ; real_T constant_Value ;
real_T constant1_Value ; real_T constant2_Value ; real_T constant3_Value ;
real_T d_Value ; real_T e_Value ; real_T timestep_Value ; real_T
timestep1_Value ; real_T timestep2_Value ; real_T timestep3_Value ; real_T
_Value ; real_T Value ; real_T _Value_fcrkhd1pwn ; real_T Value_dfptlknwpi ;
real_T constant3_Value_d4zn1mb3f1 ; real_T constant3_Value_gdybbqcsvv ;
real_T constant3_Value_e1gwiy1pb3 ; real_T constant3_Value_bufvhyvmaf ;
real_T Value_mdbqjrgdok ; real_T Constant_Value ; real_T Constant1_Value ;
real_T open_AOAdegree_Value ; real_T close_AOAdegree_Value ; real_T
Constant_Value_ndti5ul2ir ; real_T Constant1_Value_gwfubws50w ; real_T
open_AOAdegree_Value_puyaicdqcr ; real_T close_AOAdegree_Value_h2ko2tzd3h ;
real_T Constant_Value_iq4hlvezb4 ; real_T Constant1_Value_bfs2kyqhyj ; real_T
open_AOAdegree_Value_bru0w4josw ; real_T close_AOAdegree_Value_crud0nlfli ;
real_T Constant_Value_dbb4dojqmp ; real_T Constant1_Value_fqnw4iunxo ; real_T
open_AOAdegree_Value_a135evdloz ; real_T close_AOAdegree_Value_mqej5anoke ;
real_T Ncm_Value ; real_T Ncm1_Value ; real_T _Value_ihbzrbcjcd ; uint32_T
Output_InitialCondition ; uint32_T FixPtConstant_Value ; uint32_T
Constant_Value_dsvukcvkuu ; } ; extern const char *
RT_MEMORY_ALLOCATION_ERROR ; extern B rtB ; extern X rtX ; extern DW rtDW ;
extern P rtP ; extern mxArray * mr_air_part1_python2_GetDWork ( ) ; extern
void mr_air_part1_python2_SetDWork ( const mxArray * ssDW ) ; extern mxArray
* mr_air_part1_python2_GetSimStateDisallowedBlocks ( ) ; extern const
rtwCAPI_ModelMappingStaticInfo * air_part1_python2_GetCAPIStaticMap ( void )
; extern SimStruct * const rtS ; extern const int_T gblNumToFiles ; extern
const int_T gblNumFrFiles ; extern const int_T gblNumFrWksBlocks ; extern
rtInportTUtable * gblInportTUtables ; extern const char * gblInportFileName ;
extern const int_T gblNumRootInportBlks ; extern const int_T
gblNumModelInputs ; extern const int_T gblInportDataTypeIdx [ ] ; extern
const int_T gblInportDims [ ] ; extern const int_T gblInportComplex [ ] ;
extern const int_T gblInportInterpoFlag [ ] ; extern const int_T
gblInportContinuous [ ] ; extern const int_T gblParameterTuningTid ; extern
DataMapInfo * rt_dataMapInfoPtr ; extern rtwCAPI_ModelMappingInfo *
rt_modelMapInfoPtr ; void MdlOutputs ( int_T tid ) ; void
MdlOutputsParameterSampleTime ( int_T tid ) ; void MdlUpdate ( int_T tid ) ;
void MdlTerminate ( void ) ; void MdlInitializeSizes ( void ) ; void
MdlInitializeSampleTimes ( void ) ; SimStruct * raccel_register_model (
ssExecutionInfo * executionInfo ) ;
#endif
