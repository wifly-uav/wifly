#include "air_part1_python2.h"
#include "rtwtypes.h"
#include "air_part1_python2_types.h"
#include "air_part1_python2_private.h"
#include "mwmathutil.h"
#include <string.h>
#include "asynciocoder_api.hpp"
#include "coder_posix_time.h"
#include <stddef.h>
#include <stdlib.h>
#include "rt_logging_mmi.h"
#include "air_part1_python2_capi.h"
#include "multiword_types.h"
#include "air_part1_python2_dt.h"
#include "sfcn_loader_c_api.h"
extern void * CreateDiagnosticAsVoidPtr_wrapper ( const char * id , int nargs
, ... ) ; RTWExtModeInfo * gblRTWExtModeInfo = NULL ; void
raccelForceExtModeShutdown ( boolean_T extModeStartPktReceived ) { if ( !
extModeStartPktReceived ) { boolean_T stopRequested = false ;
rtExtModeWaitForStartPkt ( gblRTWExtModeInfo , 6 , & stopRequested ) ; }
rtExtModeShutdown ( 6 ) ; }
#include "slsv_diagnostic_codegen_c_api.h"
#include "slsa_sim_engine.h"
const int_T gblNumToFiles = 0 ; const int_T gblNumFrFiles = 0 ; const int_T
gblNumFrWksBlocks = 0 ;
#ifdef RSIM_WITH_SOLVER_MULTITASKING
boolean_T gbl_raccel_isMultitasking = 1 ;
#else
boolean_T gbl_raccel_isMultitasking = 0 ;
#endif
boolean_T gbl_raccel_tid01eq = 1 ; int_T gbl_raccel_NumST = 7 ; const char_T
* gbl_raccel_Version = "10.6 (R2022b) 13-May-2022" ; void
raccel_setup_MMIStateLog ( SimStruct * S ) {
#ifdef UseMMIDataLogging
rt_FillStateSigInfoFromMMI ( ssGetRTWLogInfo ( S ) , & ssGetErrorStatus ( S )
) ;
#else
UNUSED_PARAMETER ( S ) ;
#endif
} static DataMapInfo rt_dataMapInfo ; DataMapInfo * rt_dataMapInfoPtr = &
rt_dataMapInfo ; rtwCAPI_ModelMappingInfo * rt_modelMapInfoPtr = & (
rt_dataMapInfo . mmi ) ; const int_T gblNumRootInportBlks = 0 ; const int_T
gblNumModelInputs = 0 ; extern const char * gblInportFileName ; extern
rtInportTUtable * gblInportTUtables ; const int_T gblInportDataTypeIdx [ ] =
{ - 1 } ; const int_T gblInportDims [ ] = { - 1 } ; const int_T
gblInportComplex [ ] = { - 1 } ; const int_T gblInportInterpoFlag [ ] = { - 1
} ; const int_T gblInportContinuous [ ] = { - 1 } ; int_T enableFcnCallFlag [
] = { 1 , 1 , 1 , 1 , 1 , 1 , 1 } ; const char *
raccelLoadInputsAndAperiodicHitTimes ( SimStruct * S , const char *
inportFileName , int * matFileFormat ) { return rt_RAccelReadInportsMatFile (
S , inportFileName , matFileFormat ) ; }
#include "simstruc.h"
#include "fixedpoint.h"
#include "slsa_sim_engine.h"
#include "simtarget/slSimTgtSLExecSimBridge.h"
B rtB ; X rtX ; DW rtDW ; static SimStruct model_S ; SimStruct * const rtS =
& model_S ; static void pgkvysv3zg ( akean23d1n * * pEmxArray , int32_T
numDimensions ) ; static void guyyw1px3n ( ax0y0tfz0lj * pStruct ) ; static
void o3ufq2hnej ( hscjo2zzvmb * pStruct ) ; static void gglhpceojs (
kc1cjr2jks * * pEmxArray , int32_T numDimensions ) ; static void bnsqmwm4pz (
g1hz5apriqr * pStruct ) ; static void o3ufq2hnejy ( kwgo0x2v41z * pStruct ) ;
static void cul5ac3gcr ( ovagoamv4wz * pStruct ) ; static void ggpbldjcut (
gvzvlbrjok * pStruct ) ; static void jzxbjwmmtq ( kc1cjr2jks * emxArray ,
int32_T oldNumel ) ; static void lioe0t4jfb ( kc1cjr2jks * * pEmxArray ) ;
static void dvc4xvihap ( uint32_T varargin_1 , kc1cjr2jks * str ) ; static
void a0hl5tbmat ( const char_T in [ 4096 ] , char_T out_data [ ] , int32_T
out_size [ 2 ] ) ; static void kcbbxsln5r ( akean23d1n * emxArray , int32_T
oldNumel ) ; static ovagoamv4wz * pjg025uf43m ( ovagoamv4wz * obj ) ; static
void l0afvsmpfaw ( gvzvlbrjok * obj ) ; static void guyyw1px3ny ( ax0y0tfz0l
* pStruct ) ; static void o3ufq2hnejy5 ( hscjo2zzvm * pStruct ) ; static void
bnsqmwm4pzz ( g1hz5apriq * pStruct ) ; static void o3ufq2hnejy5y ( kwgo0x2v41
* pStruct ) ; static void cul5ac3gcr5 ( ovagoamv4w * pStruct ) ; static void
ggpbldjcutv ( dp0kdzdsab * pStruct ) ; static void dv5oz50wz1 ( akean23d1n *
* pEmxArray ) ; static ovagoamv4w * pjg025uf43 ( ovagoamv4w * obj ) ; static
void l0afvsmpfa ( dp0kdzdsab * obj ) ; static boolean_T ganujgx1ii ( const
g1hz5apriqr * obj , const kc1cjr2jks * byteOrder ) ; static void idziggsqd5j
( real_T * tstart_tv_sec , real_T * tstart_tv_nsec ) ; static real_T
lwekp2pixwo ( real_T tstart_tv_sec , real_T tstart_tv_nsec ) ; static void
fpycd4xlib4 ( const e4wb5cpnqg * obj , char_T status_data [ ] , int32_T
status_size [ 2 ] ) ; static boolean_T aygswycpr4 ( const char_T a_data [ ] ,
const int32_T a_size [ 2 ] ) ; static void praqpj5wy4 ( e4wb5cpnqg * obj ) ;
static real_T guurnuuuj0 ( const hscjo2zzvm * obj ) ; static void idziggsqd5
( real_T * tstart_tv_sec , real_T * tstart_tv_nsec ) ; static real_T
lwekp2pixw ( real_T tstart_tv_sec , real_T tstart_tv_nsec ) ; static void
d3nhfujrg5 ( const akean23d1n * packet , real_T startIndex , real_T endIndex
, akean23d1n * result ) ; static void d3nhfujrg53 ( const akean23d1n * packet
, real_T endIndex , akean23d1n * result ) ; static void lage0maggu (
ax0y0tfz0l * obj , real_T countRequested , akean23d1n * dataRead , real_T *
countRead ) ; static void fodfy3ik2d ( jrxtexkjqq * * pEmxArray , int32_T
numDimensions ) ; static void fpycd4xlib ( const ax0y0tfz0l * obj , char_T
status_data [ ] , int32_T status_size [ 2 ] ) ; static void dqkilabzr0 (
kkw0h0uzlf * pStruct ) ; static void i0ja5foi4d ( jrxtexkjqq * emxArray ,
int32_T fromIndex , int32_T toIndex ) ; static void pciyoa0qmy ( kkw0h0uzlf *
pStruct ) ; static void cum2hm0yhj ( jrxtexkjqq * emxArray , int32_T
fromIndex , int32_T toIndex ) ; static void b53du0mj04 ( jrxtexkjqq *
emxArray , int32_T oldNumel ) ; static void lex4eakni1 ( const ax0y0tfz0l *
obj , real_T countRequested , jrxtexkjqq * packets , real_T * countRead ) ;
static boolean_T aygswycpr4b ( const char_T a_data [ ] , const int32_T a_size
[ 2 ] ) ; static boolean_T aygswycpr4bq ( const char_T a_data [ ] , const
int32_T a_size [ 2 ] ) ; static void ptoz3k2zwg ( jrxtexkjqq * * pEmxArray )
; static void fp42yixhj2 ( ax0y0tfz0l * obj , real_T countRequested ,
akean23d1n * data , real_T * countRead , char_T err_data [ ] , int32_T
err_size [ 2 ] ) ; static void jyfcrkpivu ( f2zhfwyqun * pStruct ) ; static
void nyam2ysxlg ( f3xnlpfjxl * pEmxArray ) ; static void n1edmma3kh (
f2zhfwyqun * data , int32_T fromIndex , int32_T toIndex ) ; static void
fc5mtwhqzm ( f2zhfwyqun * pStruct ) ; static void nltwq0frzf ( f2zhfwyqun *
data , int32_T fromIndex , int32_T toIndex ) ; static void dormalfjas (
f2zhfwyqun * data , const int32_T size [ 2 ] , int32_T oldNumel ) ; static
void n53cyulecy ( akean23d1n * * dst , akean23d1n * const * src ) ; static
void fvc3gzsemj ( f2zhfwyqun * dst , const f2zhfwyqun * src ) ; static void
pjh3oqzupt ( ixviaac30n * pEmxArray ) ; static void lmz4rzqjqf ( f2zhfwyqun *
data , const int32_T * size , int32_T oldNumel ) ; static void hiixlsiwmm (
ixviaac30n * pEmxArray ) ; static void halhyajxk0 ( f3xnlpfjxl * pEmxArray )
; static void ixxwtfu0ne ( hscjo2zzvm * obj , const akean23d1n * data ) ;
static void cop24uerxs ( const hscjo2zzvm * obj , real_T startIndex , real_T
endIndex , akean23d1n * result ) ; static void omichggouu ( hscjo2zzvm * obj
, real_T numBytesToRead , akean23d1n * data ) ; static void kphoq4rcnq (
g1hz5apriq * obj , real_T numToRead , akean23d1n * data ) ; static void
ncc2f0srjcu0 ( const kwgo0x2v41z * obj ) ; static void ncc2f0srjcu0z ( const
hscjo2zzvmb * obj ) ; static void jebmsvss5a ( ax0y0tfz0lj * pStruct ) ;
static void ksxjvd1rwm ( hscjo2zzvmb * pStruct ) ; static void hkbnv3dtnw (
g1hz5apriqr * pStruct ) ; static void ksxjvd1rwmo ( kwgo0x2v41z * pStruct ) ;
static void lpykouywvt ( ovagoamv4wz * pStruct ) ; static void kwd3nombnh (
gvzvlbrjok * pStruct ) ; static void ncc2f0srjc ( const kwgo0x2v41 * obj ) ;
static void ncc2f0srjcu ( hscjo2zzvm * obj ) ; static void jebmsvss5aw (
ax0y0tfz0l * pStruct ) ; static void ksxjvd1rwmoz ( hscjo2zzvm * pStruct ) ;
static void hkbnv3dtnwv ( g1hz5apriq * pStruct ) ; static void ksxjvd1rwmozh
( kwgo0x2v41 * pStruct ) ; static void lpykouywvt3 ( ovagoamv4w * pStruct ) ;
static void kwd3nombnhc ( dp0kdzdsab * pStruct ) ;
#ifndef __RTW_UTFREE__  
extern void * utMalloc ( size_t ) ;
#endif
void * rt_TDelayCreateBuf ( int_T numBuffer , int_T bufSz , int_T elemSz ) {
return ( ( void * ) utMalloc ( numBuffer * bufSz * elemSz ) ) ; }
#ifndef __RTW_UTFREE__  
extern void * utMalloc ( size_t ) ; extern void utFree ( void * ) ;
#endif
boolean_T rt_TDelayUpdateTailOrGrowBuf ( int_T * bufSzPtr , int_T * tailPtr ,
int_T * headPtr , int_T * lastPtr , real_T tMinusDelay , real_T * * uBufPtr ,
boolean_T isfixedbuf , boolean_T istransportdelay , int_T * maxNewBufSzPtr )
{ int_T testIdx ; int_T tail = * tailPtr ; int_T bufSz = * bufSzPtr ; real_T
* tBuf = * uBufPtr + bufSz ; real_T * xBuf = ( NULL ) ; int_T numBuffer = 2 ;
if ( istransportdelay ) { numBuffer = 3 ; xBuf = * uBufPtr + 2 * bufSz ; }
testIdx = ( tail < ( bufSz - 1 ) ) ? ( tail + 1 ) : 0 ; if ( ( tMinusDelay <=
tBuf [ testIdx ] ) && ! isfixedbuf ) { int_T j ; real_T * tempT ; real_T *
tempU ; real_T * tempX = ( NULL ) ; real_T * uBuf = * uBufPtr ; int_T
newBufSz = bufSz + 1024 ; if ( newBufSz > * maxNewBufSzPtr ) { *
maxNewBufSzPtr = newBufSz ; } tempU = ( real_T * ) utMalloc ( numBuffer *
newBufSz * sizeof ( real_T ) ) ; if ( tempU == ( NULL ) ) { return ( false )
; } tempT = tempU + newBufSz ; if ( istransportdelay ) tempX = tempT +
newBufSz ; for ( j = tail ; j < bufSz ; j ++ ) { tempT [ j - tail ] = tBuf [
j ] ; tempU [ j - tail ] = uBuf [ j ] ; if ( istransportdelay ) tempX [ j -
tail ] = xBuf [ j ] ; } for ( j = 0 ; j < tail ; j ++ ) { tempT [ j + bufSz -
tail ] = tBuf [ j ] ; tempU [ j + bufSz - tail ] = uBuf [ j ] ; if (
istransportdelay ) tempX [ j + bufSz - tail ] = xBuf [ j ] ; } if ( * lastPtr
> tail ) { * lastPtr -= tail ; } else { * lastPtr += ( bufSz - tail ) ; } *
tailPtr = 0 ; * headPtr = bufSz ; utFree ( uBuf ) ; * bufSzPtr = newBufSz ; *
uBufPtr = tempU ; } else { * tailPtr = testIdx ; } return ( true ) ; } real_T
rt_TDelayInterpolate ( real_T tMinusDelay , real_T tStart , real_T * uBuf ,
int_T bufSz , int_T * lastIdx , int_T oldestIdx , int_T newIdx , real_T
initOutput , boolean_T discrete , boolean_T minorStepAndTAtLastMajorOutput )
{ int_T i ; real_T yout , t1 , t2 , u1 , u2 ; real_T * tBuf = uBuf + bufSz ;
if ( ( newIdx == 0 ) && ( oldestIdx == 0 ) && ( tMinusDelay > tStart ) )
return initOutput ; if ( tMinusDelay <= tStart ) return initOutput ; if ( (
tMinusDelay <= tBuf [ oldestIdx ] ) ) { if ( discrete ) { return ( uBuf [
oldestIdx ] ) ; } else { int_T tempIdx = oldestIdx + 1 ; if ( oldestIdx ==
bufSz - 1 ) tempIdx = 0 ; t1 = tBuf [ oldestIdx ] ; t2 = tBuf [ tempIdx ] ;
u1 = uBuf [ oldestIdx ] ; u2 = uBuf [ tempIdx ] ; if ( t2 == t1 ) { if (
tMinusDelay >= t2 ) { yout = u2 ; } else { yout = u1 ; } } else { real_T f1 =
( t2 - tMinusDelay ) / ( t2 - t1 ) ; real_T f2 = 1.0 - f1 ; yout = f1 * u1 +
f2 * u2 ; } return yout ; } } if ( minorStepAndTAtLastMajorOutput ) { if (
newIdx != 0 ) { if ( * lastIdx == newIdx ) { ( * lastIdx ) -- ; } newIdx -- ;
} else { if ( * lastIdx == newIdx ) { * lastIdx = bufSz - 1 ; } newIdx =
bufSz - 1 ; } } i = * lastIdx ; if ( tBuf [ i ] < tMinusDelay ) { while (
tBuf [ i ] < tMinusDelay ) { if ( i == newIdx ) break ; i = ( i < ( bufSz - 1
) ) ? ( i + 1 ) : 0 ; } } else { while ( tBuf [ i ] >= tMinusDelay ) { i = (
i > 0 ) ? i - 1 : ( bufSz - 1 ) ; } i = ( i < ( bufSz - 1 ) ) ? ( i + 1 ) : 0
; } * lastIdx = i ; if ( discrete ) { double tempEps = ( DBL_EPSILON ) *
128.0 ; double localEps = tempEps * muDoubleScalarAbs ( tBuf [ i ] ) ; if (
tempEps > localEps ) { localEps = tempEps ; } localEps = localEps / 2.0 ; if
( tMinusDelay >= ( tBuf [ i ] - localEps ) ) { yout = uBuf [ i ] ; } else {
if ( i == 0 ) { yout = uBuf [ bufSz - 1 ] ; } else { yout = uBuf [ i - 1 ] ;
} } } else { if ( i == 0 ) { t1 = tBuf [ bufSz - 1 ] ; u1 = uBuf [ bufSz - 1
] ; } else { t1 = tBuf [ i - 1 ] ; u1 = uBuf [ i - 1 ] ; } t2 = tBuf [ i ] ;
u2 = uBuf [ i ] ; if ( t2 == t1 ) { if ( tMinusDelay >= t2 ) { yout = u2 ; }
else { yout = u1 ; } } else { real_T f1 = ( t2 - tMinusDelay ) / ( t2 - t1 )
; real_T f2 = 1.0 - f1 ; yout = f1 * u1 + f2 * u2 ; } } return ( yout ) ; }
#ifndef __RTW_UTFREE__  
extern void utFree ( void * ) ;
#endif
void rt_TDelayFreeBuf ( void * buf ) { utFree ( buf ) ; } void imsa1beie2 (
real_T f4vmbwzk3c , real_T foc0nilpad , real_T ooxukj4j5y , real_T ldabbrc4qw
, real_T a0swvc3tzr , jaojyey2gb * localB ) { real_T h ; real_T h2 ; real_T
theta_ ; h2 = 2.0 * f4vmbwzk3c * foc0nilpad * muDoubleScalarCos ( a0swvc3tzr
) + ( f4vmbwzk3c * f4vmbwzk3c + foc0nilpad * foc0nilpad ) ; h =
muDoubleScalarSqrt ( h2 ) ; localB -> dxojvg2mzp = 1.5707963267948966 -
muDoubleScalarAcos ( ( ( ooxukj4j5y * ooxukj4j5y - h2 ) + ldabbrc4qw *
ldabbrc4qw ) / ( 2.0 * ooxukj4j5y * ldabbrc4qw ) ) ; theta_ =
muDoubleScalarAcos ( ( ( - ( ldabbrc4qw * ldabbrc4qw ) + h2 ) + ooxukj4j5y *
ooxukj4j5y ) / ( 2.0 * h * ooxukj4j5y ) ) + muDoubleScalarAtan2 ( f4vmbwzk3c
- foc0nilpad * muDoubleScalarCos ( a0swvc3tzr ) , foc0nilpad *
muDoubleScalarSin ( a0swvc3tzr ) ) ; localB -> ftth4nxmgz =
1.5707963267948966 - ( a0swvc3tzr - ( 1.5707963267948966 - (
3.1415926535897931 - theta_ ) ) ) ; if ( a0swvc3tzr > 3.1415926535897931 ) {
localB -> a0dacr3vu5 = - muDoubleScalarAcos ( ( ( f4vmbwzk3c * f4vmbwzk3c +
h2 ) - foc0nilpad * foc0nilpad ) / ( 2.0 * h * f4vmbwzk3c ) ) +
muDoubleScalarAcos ( ( ( ldabbrc4qw * ldabbrc4qw + h2 ) - ooxukj4j5y *
ooxukj4j5y ) / ( 2.0 * h * ldabbrc4qw ) ) ; } else { localB -> a0dacr3vu5 =
muDoubleScalarAcos ( ( ( f4vmbwzk3c * f4vmbwzk3c + h2 ) - foc0nilpad *
foc0nilpad ) / ( 2.0 * h * f4vmbwzk3c ) ) + muDoubleScalarAcos ( ( (
ldabbrc4qw * ldabbrc4qw + h2 ) - ooxukj4j5y * ooxukj4j5y ) / ( 2.0 * h *
ldabbrc4qw ) ) ; } localB -> d0v1fgzgtc = 1.5707963267948966 - (
3.1415926535897931 - theta_ ) ; } void jlcrjksjko ( real_T bukdskjxf1 ,
real_T mvl5xc11ep , real_T c2jruv34kj , real_T pnvl4igfri , ocg145ebmd *
localB ) { real_T Ct ; real_T Ftr_N ; real_T Ucp ; real_T a ; a = bukdskjxf1
* 3.1415926535897931 / 180.0 ; if ( bukdskjxf1 > 45.0 ) { Ct = 0.0 ; } else {
Ucp = muDoubleScalarCos ( 2.0 * a ) ; Ct = Ucp * Ucp * 0.4 ; } Ucp =
c2jruv34kj * 3.1415926535897931 / 180.0 * 0.055 ; if ( ( pnvl4igfri == 1.0 )
|| ( pnvl4igfri == 3.0 ) ) { Ftr_N = 3.4 * muDoubleScalarSin ( a ) *
0.013382549999999998 * ( Ucp * Ucp ) ; Ct = 0.013382549999999998 * Ct * ( Ucp
* Ucp ) ; } else { Ftr_N = 0.0 ; Ct = 0.0 ; } Ucp = mvl5xc11ep *
3.1415926535897931 / 180.0 * 0.003218775389867781 * Ucp + Ftr_N ; localB ->
etkpdfh3bw = Ucp * muDoubleScalarCos ( a ) - Ct * muDoubleScalarSin ( a ) ;
localB -> hogtdrsbl0 = Ucp * muDoubleScalarSin ( a ) + Ct * muDoubleScalarCos
( a ) ; localB -> ayo4a0rtpb = 0.055 ; } void a3gzjtzg5m ( real_T idvnpwtwk3
, dooynonrws * localB ) { localB -> fsek3luzie = muDoubleScalarTan (
idvnpwtwk3 * 3.1415926535897931 / 180.0 ) * 0.1375 ; } void g1ij20yo5c (
real_T fdoshxgzib , real_T l44au10k3c , real_T l55oqbw44q , real_T awjvapmqyo
, clfyjfqiuu * localB ) { if ( ( l44au10k3c > 0.0 ) && ( fdoshxgzib >
muDoubleScalarSin ( l55oqbw44q * 3.1415926535897931 / 180.0 ) * 0.1 ) ) {
localB -> jb2b5najpv = 1.0 ; } else if ( ( l44au10k3c <= 0.0 ) && (
fdoshxgzib > 0.198 - muDoubleScalarSin ( - awjvapmqyo * 3.1415926535897931 /
180.0 ) * 0.1 * 2.0 ) ) { localB -> jb2b5najpv = 2.0 ; } else if ( l44au10k3c
<= 0.0 ) { localB -> jb2b5najpv = 3.0 ; } else { localB -> jb2b5najpv = 4.0 ;
} } void jj2h00reln ( real_T i2lswpncqn , b332zk4fge * localB ) { if (
i2lswpncqn > 90.0 ) { localB -> n5nj1b05gf = 180.0 - i2lswpncqn ; } else {
localB -> n5nj1b05gf = i2lswpncqn ; } } void mjmlfjqs31 ( real_T hrxqmttc5l ,
real_T kzn4nrbum2 , real_T aksqgdxrso , real_T amdfrjgwsy , l3mdrvvpuy *
localB ) { if ( ( kzn4nrbum2 < 0.0 ) && ( hrxqmttc5l < muDoubleScalarSin (
aksqgdxrso * 3.1415926535897931 / 180.0 ) * - 0.1 ) ) { localB -> nf3awaueuw
= 1.0 ; } else if ( ( kzn4nrbum2 >= 0.0 ) && ( hrxqmttc5l < - 0.197 -
muDoubleScalarSin ( - amdfrjgwsy * 3.1415926535897931 / 180.0 ) * - 0.1 * 2.0
) ) { localB -> nf3awaueuw = 2.0 ; } else if ( kzn4nrbum2 >= 0.0 ) { localB
-> nf3awaueuw = 3.0 ; } else { localB -> nf3awaueuw = 4.0 ; } } void
dtuuqh01ed ( real_T jutpbufeve , real_T e0c4jdrz1w , real_T fgswrovla2 ,
real_T dprp01z3vm , gywknl2xur * localB ) { if ( jutpbufeve == 1.0 ) { localB
-> o5vabvlgjn = fgswrovla2 ; } else if ( jutpbufeve == 2.0 ) { localB ->
o5vabvlgjn = muDoubleScalarMin ( muDoubleScalarAsin ( ( muDoubleScalarSin (
fgswrovla2 * 3.1415926535897931 / 180.0 ) * 0.1 - ( e0c4jdrz1w + 0.197 ) ) /
0.1 ) * 180.0 / 3.1415926535897931 , fgswrovla2 ) ; } else if ( jutpbufeve ==
3.0 ) { localB -> o5vabvlgjn = dprp01z3vm ; } else { localB -> o5vabvlgjn =
muDoubleScalarMax ( - muDoubleScalarAsin ( ( muDoubleScalarSin ( - dprp01z3vm
* 3.1415926535897931 / 180.0 ) * 0.1 / 2.0 + e0c4jdrz1w ) / 0.05 ) * 180.0 /
3.1415926535897931 , dprp01z3vm ) ; } } static void pgkvysv3zg ( akean23d1n *
* pEmxArray , int32_T numDimensions ) { akean23d1n * emxArray ; int32_T i ; *
pEmxArray = ( akean23d1n * ) malloc ( sizeof ( akean23d1n ) ) ; emxArray = *
pEmxArray ; emxArray -> data = ( uint8_T * ) NULL ; emxArray -> numDimensions
= numDimensions ; emxArray -> size = ( int32_T * ) malloc ( sizeof ( int32_T
) * ( uint32_T ) numDimensions ) ; emxArray -> allocatedSize = 0 ; emxArray
-> canFreeData = true ; for ( i = 0 ; i < numDimensions ; i ++ ) { emxArray
-> size [ i ] = 0 ; } } static void guyyw1px3n ( ax0y0tfz0lj * pStruct ) {
pgkvysv3zg ( & pStruct -> ExampleData , 2 ) ; } static void o3ufq2hnej (
hscjo2zzvmb * pStruct ) { guyyw1px3n ( & pStruct -> InputStream ) ; } static
void gglhpceojs ( kc1cjr2jks * * pEmxArray , int32_T numDimensions ) {
kc1cjr2jks * emxArray ; int32_T i ; * pEmxArray = ( kc1cjr2jks * ) malloc (
sizeof ( kc1cjr2jks ) ) ; emxArray = * pEmxArray ; emxArray -> data = (
char_T * ) NULL ; emxArray -> numDimensions = numDimensions ; emxArray ->
size = ( int32_T * ) malloc ( sizeof ( int32_T ) * ( uint32_T ) numDimensions
) ; emxArray -> allocatedSize = 0 ; emxArray -> canFreeData = true ; for ( i
= 0 ; i < numDimensions ; i ++ ) { emxArray -> size [ i ] = 0 ; } } static
void bnsqmwm4pz ( g1hz5apriqr * pStruct ) { o3ufq2hnej ( & pStruct ->
UnreadDataBuffer ) ; gglhpceojs ( & pStruct -> ByteOrder , 2 ) ; } static
void o3ufq2hnejy ( kwgo0x2v41z * pStruct ) { guyyw1px3n ( & pStruct ->
InputStream ) ; } static void cul5ac3gcr ( ovagoamv4wz * pStruct ) {
bnsqmwm4pz ( & pStruct -> _pobj0 ) ; o3ufq2hnejy ( & pStruct -> _pobj1 ) ; }
static void ggpbldjcut ( gvzvlbrjok * pStruct ) { cul5ac3gcr ( & pStruct ->
TCPIPObj ) ; } static void jzxbjwmmtq ( kc1cjr2jks * emxArray , int32_T
oldNumel ) { int32_T i ; int32_T newNumel ; void * newData ; if ( oldNumel <
0 ) { oldNumel = 0 ; } newNumel = 1 ; for ( i = 0 ; i < emxArray ->
numDimensions ; i ++ ) { newNumel *= emxArray -> size [ i ] ; } if ( newNumel
> emxArray -> allocatedSize ) { i = emxArray -> allocatedSize ; if ( i < 16 )
{ i = 16 ; } while ( i < newNumel ) { if ( i > 1073741823 ) { i = MAX_int32_T
; } else { i <<= 1 ; } } newData = calloc ( ( uint32_T ) i , sizeof ( char_T
) ) ; if ( emxArray -> data != NULL ) { memcpy ( newData , emxArray -> data ,
sizeof ( char_T ) * ( uint32_T ) oldNumel ) ; if ( emxArray -> canFreeData )
{ free ( emxArray -> data ) ; } } emxArray -> data = ( char_T * ) newData ;
emxArray -> allocatedSize = i ; emxArray -> canFreeData = true ; } } static
void lioe0t4jfb ( kc1cjr2jks * * pEmxArray ) { if ( * pEmxArray != (
kc1cjr2jks * ) NULL ) { if ( ( ( * pEmxArray ) -> data != ( char_T * ) NULL )
&& ( * pEmxArray ) -> canFreeData ) { free ( ( * pEmxArray ) -> data ) ; }
free ( ( * pEmxArray ) -> size ) ; free ( * pEmxArray ) ; * pEmxArray = (
kc1cjr2jks * ) NULL ; } } static void dvc4xvihap ( uint32_T varargin_1 ,
kc1cjr2jks * str ) { kc1cjr2jks * str_p ; int32_T nbytes ; int32_T tmp ;
nbytes = snprintf ( NULL , 0 , "%u" , varargin_1 ) ; gglhpceojs ( & str_p , 2
) ; tmp = str_p -> size [ 0 ] * str_p -> size [ 1 ] ; str_p -> size [ 0 ] = 1
; str_p -> size [ 1 ] = nbytes + 1 ; jzxbjwmmtq ( str_p , tmp ) ; snprintf (
& str_p -> data [ 0 ] , ( size_t ) ( nbytes + 1 ) , "%u" , varargin_1 ) ; if
( nbytes < 1 ) { nbytes = 0 ; } tmp = str -> size [ 0 ] * str -> size [ 1 ] ;
str -> size [ 0 ] = 1 ; str -> size [ 1 ] = nbytes ; jzxbjwmmtq ( str , tmp )
; if ( nbytes - 1 >= 0 ) { memcpy ( & str -> data [ 0 ] , & str_p -> data [ 0
] , ( uint32_T ) nbytes * sizeof ( char_T ) ) ; } lioe0t4jfb ( & str_p ) ; }
static void a0hl5tbmat ( const char_T in [ 4096 ] , char_T out_data [ ] ,
int32_T out_size [ 2 ] ) { int32_T b_k ; int32_T len ; len = 0 ; b_k = 0 ;
while ( ( b_k < 4096 ) && ( ! ( in [ b_k ] == '\x00' ) ) ) { len ++ ; b_k ++
; } if ( len < 1 ) { len = 0 ; } out_size [ 0 ] = 1 ; out_size [ 1 ] = len ;
if ( len - 1 >= 0 ) { memcpy ( & out_data [ 0 ] , & in [ 0 ] , ( uint32_T )
len * sizeof ( char_T ) ) ; } } static void kcbbxsln5r ( akean23d1n *
emxArray , int32_T oldNumel ) { int32_T i ; int32_T newNumel ; void * newData
; if ( oldNumel < 0 ) { oldNumel = 0 ; } newNumel = 1 ; for ( i = 0 ; i <
emxArray -> numDimensions ; i ++ ) { newNumel *= emxArray -> size [ i ] ; }
if ( newNumel > emxArray -> allocatedSize ) { i = emxArray -> allocatedSize ;
if ( i < 16 ) { i = 16 ; } while ( i < newNumel ) { if ( i > 1073741823 ) { i
= MAX_int32_T ; } else { i <<= 1 ; } } newData = calloc ( ( uint32_T ) i ,
sizeof ( uint8_T ) ) ; if ( emxArray -> data != NULL ) { memcpy ( newData ,
emxArray -> data , sizeof ( uint8_T ) * ( uint32_T ) oldNumel ) ; if (
emxArray -> canFreeData ) { free ( emxArray -> data ) ; } } emxArray -> data
= ( uint8_T * ) newData ; emxArray -> allocatedSize = i ; emxArray ->
canFreeData = true ; } } static ovagoamv4wz * pjg025uf43m ( ovagoamv4wz * obj
) { CoderChannel chImpl ; CoderInputStream streamImpl ; CoderOutputStream
streamImpl_p ; g1hz5apriqr * iobj_0 ; hscjo2zzvmb * obj_p ; kc1cjr2jks * c ;
kc1cjr2jks * options_ServiceName ; kwgo0x2v41z * iobj_1 ; ovagoamv4wz * b_obj
; real_T varargin_8_idx_0 ; real_T varargin_8_idx_1 ; int32_T loop_ub ;
int32_T success ; uint32_T tmp ; char_T deviceFullPath_data [ 4096 ] ; char_T
devicePlugin_data [ 4096 ] ; char_T localAbsPath [ 4096 ] ; char_T errorID [
1024 ] ; char_T errorText [ 1024 ] ; char_T b [ 9 ] ; boolean_T hasSyncError
; boolean_T result ; static const char_T tmp_p [ 9 ] = { '1' , '2' , '7' ,
'.' , '0' , '.' , '0' , '.' , '1' } ; static const lchp1rikuv tmp_e = { true
, true , 0ULL } ; static const char_T tmp_i [ 13 ] = { 'l' , 'i' , 't' , 't'
, 'l' , 'e' , '-' , 'e' , 'n' , 'd' , 'i' , 'a' , 'n' } ; int32_T
deviceFullPath_size [ 2 ] ; int32_T converterPlugin_size_idx_1 ; obj ->
ConnectTimeout = ( rtInf ) ; obj -> InputBufferSize = ( rtInf ) ; obj ->
OutputBufferSize = ( rtInf ) ; b_obj = obj ; for ( success = 0 ; success < 9
; success ++ ) { obj -> RemoteHost [ success ] = tmp_p [ success ] ; } obj ->
RemotePort = 9999.0 ; iobj_0 = & obj -> _pobj0 ; iobj_1 = & obj -> _pobj1 ;
for ( success = 0 ; success < 9 ; success ++ ) { b [ success ] = obj ->
RemoteHost [ success ] ; } varargin_8_idx_0 = muDoubleScalarRound ( obj ->
RemotePort ) ; if ( varargin_8_idx_0 < 4.294967296E+9 ) { if (
varargin_8_idx_0 >= 0.0 ) { tmp = ( uint32_T ) varargin_8_idx_0 ; } else {
tmp = 0U ; } } else if ( varargin_8_idx_0 >= 4.294967296E+9 ) { tmp =
MAX_uint32_T ; } else { tmp = 0U ; } gglhpceojs ( & options_ServiceName , 2 )
; dvc4xvihap ( tmp , options_ServiceName ) ; coderComputeAbsolutePath (
"tcpclientdevice.dll" , & localAbsPath [ 0 ] ) ; a0hl5tbmat ( localAbsPath ,
deviceFullPath_data , deviceFullPath_size ) ; if ( deviceFullPath_size [ 1 ]
!= 0 ) { success = deviceFullPath_size [ 1 ] ; loop_ub = deviceFullPath_size
[ 1 ] ; memcpy ( & devicePlugin_data [ 0 ] , & deviceFullPath_data [ 0 ] , (
uint32_T ) loop_ub * sizeof ( char_T ) ) ; } else { coderComputeAbsolutePath
(
 "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\shared\\networklib\\bin\\win64\\tcpclientdevice.dll"
, & localAbsPath [ 0 ] ) ; a0hl5tbmat ( localAbsPath , deviceFullPath_data ,
deviceFullPath_size ) ; if ( deviceFullPath_size [ 1 ] != 0 ) { success =
deviceFullPath_size [ 1 ] ; loop_ub = deviceFullPath_size [ 1 ] ; memcpy ( &
devicePlugin_data [ 0 ] , & deviceFullPath_data [ 0 ] , ( uint32_T ) loop_ub
* sizeof ( char_T ) ) ; } else { success = 0 ; } } coderComputeAbsolutePath (
"networkcoderconverter.dll" , & localAbsPath [ 0 ] ) ; a0hl5tbmat (
localAbsPath , deviceFullPath_data , deviceFullPath_size ) ; if (
deviceFullPath_size [ 1 ] != 0 ) { converterPlugin_size_idx_1 =
deviceFullPath_size [ 1 ] ; loop_ub = deviceFullPath_size [ 1 ] ; memcpy ( &
localAbsPath [ 0 ] , & deviceFullPath_data [ 0 ] , ( uint32_T ) loop_ub *
sizeof ( char_T ) ) ; } else { coderComputeAbsolutePath (
 "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\shared\\networklib\\bin\\win64\\networkcoderconverter.dll"
, & localAbsPath [ 0 ] ) ; a0hl5tbmat ( localAbsPath , deviceFullPath_data ,
deviceFullPath_size ) ; if ( deviceFullPath_size [ 1 ] != 0 ) {
converterPlugin_size_idx_1 = deviceFullPath_size [ 1 ] ; loop_ub =
deviceFullPath_size [ 1 ] ; memcpy ( & localAbsPath [ 0 ] , &
deviceFullPath_data [ 0 ] , ( uint32_T ) loop_ub * sizeof ( char_T ) ) ; }
else { converterPlugin_size_idx_1 = 0 ; } } varargin_8_idx_0 = obj ->
InputBufferSize ; varargin_8_idx_1 = obj -> OutputBufferSize ; obj -> _pobj1
. CustomProps = tmp_e ; obj -> _pobj1 . ChannelImpl = 0 ; if ( success - 1 >=
0 ) { memcpy ( & rtB . b_devicePluginPath_data_mbvzarwird [ 0 ] , &
devicePlugin_data [ 0 ] , ( uint32_T ) success * sizeof ( char_T ) ) ; } rtB
. b_devicePluginPath_data_mbvzarwird [ success ] = '\x00' ; if (
converterPlugin_size_idx_1 - 1 >= 0 ) { memcpy ( & rtB .
b_converterPluginPath_data_cl54gopm0x [ 0 ] , & localAbsPath [ 0 ] , (
uint32_T ) converterPlugin_size_idx_1 * sizeof ( char_T ) ) ; } rtB .
b_converterPluginPath_data_cl54gopm0x [ converterPlugin_size_idx_1 ] = '\x00'
; chImpl = coderChannelCreate ( & rtB . b_devicePluginPath_data_mbvzarwird [
0 ] , & rtB . b_converterPluginPath_data_cl54gopm0x [ 0 ] , varargin_8_idx_0
, varargin_8_idx_1 , & errorID [ 0 ] , & errorText [ 0 ] ) ; obj -> _pobj1 .
ChannelImpl = chImpl ; chImpl = obj -> _pobj1 . ChannelImpl ; gglhpceojs ( &
c , 2 ) ; if ( options_ServiceName -> size [ 1 ] == 1 ) { success = c -> size
[ 0 ] * c -> size [ 1 ] ; c -> size [ 0 ] = 1 ; c -> size [ 1 ] = 2 ;
jzxbjwmmtq ( c , success ) ; c -> data [ 0 ] = options_ServiceName -> data [
0 ] ; c -> data [ 1 ] = options_ServiceName -> data [ 0 ] ; } else { success
= c -> size [ 0 ] * c -> size [ 1 ] ; c -> size [ 0 ] = 1 ; c -> size [ 1 ] =
options_ServiceName -> size [ 1 ] ; jzxbjwmmtq ( c , success ) ; loop_ub =
options_ServiceName -> size [ 1 ] ; if ( loop_ub - 1 >= 0 ) { memcpy ( & c ->
data [ 0 ] , & options_ServiceName -> data [ 0 ] , ( uint32_T ) loop_ub *
sizeof ( char_T ) ) ; } } success = coderChannelInit ( chImpl , 2 ,
"HostName" , "char" , 9 , & b [ 0 ] , "ServiceName" , "char" ,
options_ServiceName -> size [ 1 ] , & c -> data [ 0 ] ) ; lioe0t4jfb ( & c )
; lioe0t4jfb ( & options_ServiceName ) ; if ( success == 0 ) {
coderChannelHasSyncError ( chImpl , & hasSyncError ) ; if ( ! hasSyncError )
{ coderChannelGetLastError ( chImpl , & errorID [ 0 ] , & errorText [ 0 ] ) ;
} else { coderChannelGetLastSyncError ( chImpl , & errorID [ 0 ] , &
errorText [ 0 ] ) ; } } chImpl = obj -> _pobj1 . ChannelImpl ; streamImpl =
coderChannelGetInputStream ( chImpl ) ; iobj_1 -> InputStream . StreamImpl =
streamImpl ; success = iobj_1 -> InputStream . ExampleData -> size [ 0 ] *
iobj_1 -> InputStream . ExampleData -> size [ 1 ] ; iobj_1 -> InputStream .
ExampleData -> size [ 0 ] = 1 ; iobj_1 -> InputStream . ExampleData -> size [
1 ] = 1 ; kcbbxsln5r ( iobj_1 -> InputStream . ExampleData , success ) ;
iobj_1 -> InputStream . ExampleData -> data [ 0 ] = 0U ; iobj_1 ->
InputStream . matlabCodegenIsDeleted = false ; chImpl = obj -> _pobj1 .
ChannelImpl ; iobj_1 -> OutputStream . Timeout = 10.0 ; streamImpl_p =
coderChannelGetOutputStream ( chImpl ) ; iobj_1 -> OutputStream . StreamImpl
= streamImpl_p ; iobj_1 -> OutputStream . matlabCodegenIsDeleted = false ;
obj -> _pobj1 . matlabCodegenIsDeleted = false ; obj -> AsyncIOChannel = &
obj -> _pobj1 ; iobj_1 = obj -> AsyncIOChannel ; iobj_0 -> NumBytesWritten =
0.0 ; for ( success = 0 ; success < 13 ; success ++ ) { iobj_0 ->
MachineByteOrder [ success ] = tmp_i [ success ] ; } iobj_0 -> AsyncIOChannel
= iobj_1 ; success = iobj_0 -> ByteOrder -> size [ 0 ] * iobj_0 -> ByteOrder
-> size [ 1 ] ; iobj_0 -> ByteOrder -> size [ 0 ] = 1 ; iobj_0 -> ByteOrder
-> size [ 1 ] = 0 ; iobj_0 -> ByteOrder -> size [ 0 ] = 1 ; iobj_0 ->
ByteOrder -> size [ 1 ] = 13 ; jzxbjwmmtq ( iobj_0 -> ByteOrder , success ) ;
for ( success = 0 ; success < 13 ; success ++ ) { iobj_0 -> ByteOrder -> data
[ success ] = tmp_i [ success ] ; } obj_p = & iobj_0 -> UnreadDataBuffer ;
coderComputeAbsolutePath ( "buffer.dll" , & localAbsPath [ 0 ] ) ; a0hl5tbmat
( localAbsPath , deviceFullPath_data , deviceFullPath_size ) ; if (
deviceFullPath_size [ 1 ] != 0 ) { success = deviceFullPath_size [ 1 ] ;
loop_ub = deviceFullPath_size [ 1 ] ; memcpy ( & devicePlugin_data [ 0 ] , &
deviceFullPath_data [ 0 ] , ( uint32_T ) loop_ub * sizeof ( char_T ) ) ; }
else { coderComputeAbsolutePath (
 "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\shared\\testmeaslib\\general\\bin\\win64\\buffer.dll"
, & localAbsPath [ 0 ] ) ; a0hl5tbmat ( localAbsPath , deviceFullPath_data ,
deviceFullPath_size ) ; if ( deviceFullPath_size [ 1 ] != 0 ) { success =
deviceFullPath_size [ 1 ] ; loop_ub = deviceFullPath_size [ 1 ] ; memcpy ( &
devicePlugin_data [ 0 ] , & deviceFullPath_data [ 0 ] , ( uint32_T ) loop_ub
* sizeof ( char_T ) ) ; } else { success = 0 ; } } coderComputeAbsolutePath (
"buffercoderconverter.dll" , & localAbsPath [ 0 ] ) ; a0hl5tbmat (
localAbsPath , deviceFullPath_data , deviceFullPath_size ) ; if (
deviceFullPath_size [ 1 ] != 0 ) { converterPlugin_size_idx_1 =
deviceFullPath_size [ 1 ] ; loop_ub = deviceFullPath_size [ 1 ] ; memcpy ( &
localAbsPath [ 0 ] , & deviceFullPath_data [ 0 ] , ( uint32_T ) loop_ub *
sizeof ( char_T ) ) ; } else { coderComputeAbsolutePath (
 "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\shared\\testmeaslib\\general\\bin\\win64\\buffercoderconverter.dll"
, & localAbsPath [ 0 ] ) ; a0hl5tbmat ( localAbsPath , deviceFullPath_data ,
deviceFullPath_size ) ; if ( deviceFullPath_size [ 1 ] != 0 ) {
converterPlugin_size_idx_1 = deviceFullPath_size [ 1 ] ; loop_ub =
deviceFullPath_size [ 1 ] ; memcpy ( & localAbsPath [ 0 ] , &
deviceFullPath_data [ 0 ] , ( uint32_T ) loop_ub * sizeof ( char_T ) ) ; }
else { converterPlugin_size_idx_1 = 0 ; } } iobj_0 -> UnreadDataBuffer .
ChannelImpl = 0 ; if ( success - 1 >= 0 ) { memcpy ( & rtB .
b_devicePluginPath_data_mbvzarwird [ 0 ] , & devicePlugin_data [ 0 ] , (
uint32_T ) success * sizeof ( char_T ) ) ; } rtB .
b_devicePluginPath_data_mbvzarwird [ success ] = '\x00' ; if (
converterPlugin_size_idx_1 - 1 >= 0 ) { memcpy ( & rtB .
b_converterPluginPath_data_cl54gopm0x [ 0 ] , & localAbsPath [ 0 ] , (
uint32_T ) converterPlugin_size_idx_1 * sizeof ( char_T ) ) ; } rtB .
b_converterPluginPath_data_cl54gopm0x [ converterPlugin_size_idx_1 ] = '\x00'
; chImpl = coderChannelCreate ( & rtB . b_devicePluginPath_data_mbvzarwird [
0 ] , & rtB . b_converterPluginPath_data_cl54gopm0x [ 0 ] , ( rtInf ) , 0.0 ,
& errorID [ 0 ] , & errorText [ 0 ] ) ; iobj_0 -> UnreadDataBuffer .
ChannelImpl = chImpl ; chImpl = iobj_0 -> UnreadDataBuffer . ChannelImpl ;
success = coderChannelInit ( chImpl , 0 ) ; if ( success == 0 ) {
coderChannelHasSyncError ( chImpl , & hasSyncError ) ; if ( ! hasSyncError )
{ coderChannelGetLastError ( chImpl , & errorID [ 0 ] , & errorText [ 0 ] ) ;
} else { coderChannelGetLastSyncError ( chImpl , & errorID [ 0 ] , &
errorText [ 0 ] ) ; } } chImpl = iobj_0 -> UnreadDataBuffer . ChannelImpl ;
streamImpl = coderChannelGetInputStream ( chImpl ) ; obj_p -> InputStream .
StreamImpl = streamImpl ; success = obj_p -> InputStream . ExampleData ->
size [ 0 ] * obj_p -> InputStream . ExampleData -> size [ 1 ] ; obj_p ->
InputStream . ExampleData -> size [ 0 ] = 1 ; obj_p -> InputStream .
ExampleData -> size [ 1 ] = 1 ; kcbbxsln5r ( obj_p -> InputStream .
ExampleData , success ) ; obj_p -> InputStream . ExampleData -> data [ 0 ] =
0U ; obj_p -> InputStream . matlabCodegenIsDeleted = false ; chImpl = iobj_0
-> UnreadDataBuffer . ChannelImpl ; obj_p -> OutputStream . Timeout = 10.0 ;
streamImpl_p = coderChannelGetOutputStream ( chImpl ) ; obj_p -> OutputStream
. StreamImpl = streamImpl_p ; obj_p -> OutputStream . matlabCodegenIsDeleted
= false ; iobj_0 -> UnreadDataBuffer . matlabCodegenIsDeleted = false ;
chImpl = iobj_0 -> UnreadDataBuffer . ChannelImpl ; success =
coderChannelIsOpen ( chImpl , & result ) ; if ( success == 0 ) {
coderChannelHasSyncError ( chImpl , & hasSyncError ) ; if ( ! hasSyncError )
{ coderChannelGetLastError ( chImpl , & errorID [ 0 ] , & errorText [ 0 ] ) ;
} else { coderChannelGetLastSyncError ( chImpl , & errorID [ 0 ] , &
errorText [ 0 ] ) ; } } if ( ! result ) { chImpl = iobj_0 -> UnreadDataBuffer
. ChannelImpl ; success = coderChannelOpen ( chImpl , 0 ) ; if ( success == 0
) { coderChannelHasSyncError ( chImpl , & hasSyncError ) ; if ( !
hasSyncError ) { coderChannelGetLastError ( chImpl , & errorID [ 0 ] , &
errorText [ 0 ] ) ; } else { coderChannelGetLastSyncError ( chImpl , &
errorID [ 0 ] , & errorText [ 0 ] ) ; } } } iobj_0 -> matlabCodegenIsDeleted
= false ; obj -> TransportChannel = iobj_0 ; obj -> IsWriteOnly = true ; obj
-> IsSharingPort = true ; iobj_0 = obj -> TransportChannel ; success = iobj_0
-> ByteOrder -> size [ 0 ] * iobj_0 -> ByteOrder -> size [ 1 ] ; iobj_0 ->
ByteOrder -> size [ 0 ] = 1 ; iobj_0 -> ByteOrder -> size [ 1 ] = 0 ; iobj_0
-> ByteOrder -> size [ 0 ] = 1 ; iobj_0 -> ByteOrder -> size [ 1 ] = 13 ;
jzxbjwmmtq ( iobj_0 -> ByteOrder , success ) ; for ( success = 0 ; success <
13 ; success ++ ) { iobj_0 -> ByteOrder -> data [ success ] = tmp_i [ success
] ; } obj -> matlabCodegenIsDeleted = false ; return b_obj ; } static void
l0afvsmpfaw ( gvzvlbrjok * obj ) { CoderChannel chImpl ; e4wb5cpnqg *
outputStream ; g1hz5apriqr * obj_p ; kc1cjr2jks * c ; kc1cjr2jks *
options_ServiceName ; kwgo0x2v41z * obj_e ; real_T d [ 2 ] ; real_T e [ 2 ] ;
real_T f [ 2 ] ; real_T options_ConnectTimeout ; int32_T success ; uint32_T
tmp ; char_T errorID [ 1024 ] ; char_T errorText [ 1024 ] ; char_T b [ 9 ] ;
boolean_T g [ 2 ] ; boolean_T h [ 2 ] ; boolean_T i [ 2 ] ; boolean_T
hasSyncError ; boolean_T options_IsSharingPort ; boolean_T
options_IsWriteOnly ; boolean_T result ; boolean_T value ; static const
char_T tmp_p [ 5 ] = { 'u' , 'i' , 'n' , 't' , '8' } ; static const char_T
tmp_e [ 10 ] = { 'b' , 'i' , 'g' , '-' , 'e' , 'n' , 'd' , 'i' , 'a' , 'n' }
; obj -> isSetupComplete = false ; obj -> isInitialized = 1 ; for ( success =
0 ; success < 5 ; success ++ ) { obj -> InputDataType [ success ] = tmp_p [
success ] ; } pjg025uf43m ( & obj -> TCPIPObj ) ; outputStream = & obj ->
TCPIPObj . AsyncIOChannel -> OutputStream ; outputStream -> Timeout = 10.0 ;
obj_p = obj -> TCPIPObj . TransportChannel ; success = obj_p -> ByteOrder ->
size [ 0 ] * obj_p -> ByteOrder -> size [ 1 ] ; obj_p -> ByteOrder -> size [
0 ] = 1 ; obj_p -> ByteOrder -> size [ 1 ] = 0 ; obj_p -> ByteOrder -> size [
0 ] = 1 ; obj_p -> ByteOrder -> size [ 1 ] = 10 ; jzxbjwmmtq ( obj_p ->
ByteOrder , success ) ; for ( success = 0 ; success < 10 ; success ++ ) {
obj_p -> ByteOrder -> data [ success ] = tmp_e [ success ] ; } obj_p = obj ->
TCPIPObj . TransportChannel ; obj_e = obj_p -> AsyncIOChannel ; chImpl =
obj_e -> ChannelImpl ; success = coderChannelIsOpen ( chImpl , & result ) ;
if ( success == 0 ) { coderChannelHasSyncError ( chImpl , & hasSyncError ) ;
if ( ! hasSyncError ) { coderChannelGetLastError ( chImpl , & errorID [ 0 ] ,
& errorText [ 0 ] ) ; } else { coderChannelGetLastSyncError ( chImpl , &
errorID [ 0 ] , & errorText [ 0 ] ) ; } } obj -> TCPIPObj . TransferDelay =
true ; obj_e = obj -> TCPIPObj . AsyncIOChannel ; chImpl = obj_e ->
ChannelImpl ; success = coderChannelIsOpen ( chImpl , & result ) ; if (
success == 0 ) { coderChannelHasSyncError ( chImpl , & hasSyncError ) ; if (
! hasSyncError ) { coderChannelGetLastError ( chImpl , & errorID [ 0 ] , &
errorText [ 0 ] ) ; } else { coderChannelGetLastSyncError ( chImpl , &
errorID [ 0 ] , & errorText [ 0 ] ) ; } } for ( success = 0 ; success < 9 ;
success ++ ) { b [ success ] = obj -> TCPIPObj . RemoteHost [ success ] ; }
options_ConnectTimeout = muDoubleScalarRound ( obj -> TCPIPObj . RemotePort )
; if ( options_ConnectTimeout < 4.294967296E+9 ) { if (
options_ConnectTimeout >= 0.0 ) { tmp = ( uint32_T ) options_ConnectTimeout ;
} else { tmp = 0U ; } } else if ( options_ConnectTimeout >= 4.294967296E+9 )
{ tmp = MAX_uint32_T ; } else { tmp = 0U ; } gglhpceojs ( &
options_ServiceName , 2 ) ; dvc4xvihap ( tmp , options_ServiceName ) ;
options_ConnectTimeout = obj -> TCPIPObj . ConnectTimeout ;
options_IsWriteOnly = obj -> TCPIPObj . IsWriteOnly ; options_IsSharingPort =
obj -> TCPIPObj . IsSharingPort ; obj_p = obj -> TCPIPObj . TransportChannel
; obj_e = obj_p -> AsyncIOChannel ; chImpl = obj_e -> ChannelImpl ; success =
coderChannelIsOpen ( chImpl , & result ) ; if ( success == 0 ) {
coderChannelHasSyncError ( chImpl , & hasSyncError ) ; if ( ! hasSyncError )
{ coderChannelGetLastError ( chImpl , & errorID [ 0 ] , & errorText [ 0 ] ) ;
} else { coderChannelGetLastSyncError ( chImpl , & errorID [ 0 ] , &
errorText [ 0 ] ) ; } } if ( ! result ) { value = obj -> TCPIPObj .
TransferDelay ; } else { obj_e = obj -> TCPIPObj . AsyncIOChannel ; value =
obj_e -> CustomProps . TransferDelay ; chImpl = obj_e -> ChannelImpl ;
success = coderChannelGetPropertyValue ( chImpl , "TransferDelay" , "logical"
, 1 , & value ) ; if ( success == 0 ) { coderChannelHasSyncError ( chImpl , &
hasSyncError ) ; if ( ! hasSyncError ) { coderChannelGetLastError ( chImpl ,
& errorID [ 0 ] , & errorText [ 0 ] ) ; } else { coderChannelGetLastSyncError
( chImpl , & errorID [ 0 ] , & errorText [ 0 ] ) ; } } } obj_e = obj ->
TCPIPObj . AsyncIOChannel ; chImpl = obj_e -> ChannelImpl ; success =
coderChannelIsOpen ( chImpl , & result ) ; if ( success == 0 ) {
coderChannelHasSyncError ( chImpl , & hasSyncError ) ; if ( ! hasSyncError )
{ coderChannelGetLastError ( chImpl , & errorID [ 0 ] , & errorText [ 0 ] ) ;
} else { coderChannelGetLastSyncError ( chImpl , & errorID [ 0 ] , &
errorText [ 0 ] ) ; } } if ( ! result ) { chImpl = obj_e -> ChannelImpl ;
gglhpceojs ( & c , 2 ) ; if ( options_ServiceName -> size [ 1 ] == 1 ) {
success = c -> size [ 0 ] * c -> size [ 1 ] ; c -> size [ 0 ] = 1 ; c -> size
[ 1 ] = 2 ; jzxbjwmmtq ( c , success ) ; c -> data [ 0 ] =
options_ServiceName -> data [ 0 ] ; c -> data [ 1 ] = options_ServiceName ->
data [ 0 ] ; } else { success = c -> size [ 0 ] * c -> size [ 1 ] ; c -> size
[ 0 ] = 1 ; c -> size [ 1 ] = options_ServiceName -> size [ 1 ] ; jzxbjwmmtq
( c , success ) ; success = options_ServiceName -> size [ 1 ] ; if ( success
- 1 >= 0 ) { memcpy ( & c -> data [ 0 ] , & options_ServiceName -> data [ 0 ]
, ( uint32_T ) success * sizeof ( char_T ) ) ; } } d [ 0 ] = 65536.0 ; d [ 1
] = 65536.0 ; e [ 0 ] = 65536.0 ; e [ 1 ] = 65536.0 ; f [ 0 ] =
options_ConnectTimeout ; f [ 1 ] = options_ConnectTimeout ; g [ 0 ] =
options_IsWriteOnly ; g [ 1 ] = options_IsWriteOnly ; h [ 0 ] =
options_IsSharingPort ; h [ 1 ] = options_IsSharingPort ; i [ 0 ] = value ; i
[ 1 ] = value ; success = coderChannelOpen ( chImpl , 8 , "HostName" , "char"
, 9 , & b [ 0 ] , "ServiceName" , "char" , options_ServiceName -> size [ 1 ]
, & c -> data [ 0 ] , "ReceiveSize" , "double" , 1 , & d [ 0 ] , "SendSize" ,
"double" , 1 , & e [ 0 ] , "ConnectTimeout" , "double" , 1 , & f [ 0 ] ,
"IsWriteOnly" , "logical" , 1 , & g [ 0 ] , "IsSharingPort" , "logical" , 1 ,
& h [ 0 ] , "TransferDelay" , "logical" , 1 , & i [ 0 ] ) ; lioe0t4jfb ( & c
) ; if ( success == 0 ) { coderChannelHasSyncError ( chImpl , & hasSyncError
) ; if ( ! hasSyncError ) { coderChannelGetLastError ( chImpl , & errorID [ 0
] , & errorText [ 0 ] ) ; } else { coderChannelGetLastSyncError ( chImpl , &
errorID [ 0 ] , & errorText [ 0 ] ) ; } } } lioe0t4jfb ( &
options_ServiceName ) ; obj_p = obj -> TCPIPObj . TransportChannel ; obj_p ->
WriteAsync = false ; obj -> isSetupComplete = true ; } static void
guyyw1px3ny ( ax0y0tfz0l * pStruct ) { pgkvysv3zg ( & pStruct ->
PartialPacket , 2 ) ; pgkvysv3zg ( & pStruct -> ExampleData , 2 ) ; } static
void o3ufq2hnejy5 ( hscjo2zzvm * pStruct ) { guyyw1px3ny ( & pStruct ->
InputStream ) ; pgkvysv3zg ( & pStruct -> PartialPacket , 2 ) ; } static void
bnsqmwm4pzz ( g1hz5apriq * pStruct ) { o3ufq2hnejy5 ( & pStruct ->
UnreadDataBuffer ) ; gglhpceojs ( & pStruct -> ByteOrder , 2 ) ; gglhpceojs (
& pStruct -> NativeDataType , 2 ) ; gglhpceojs ( & pStruct -> DataFieldName ,
2 ) ; } static void o3ufq2hnejy5y ( kwgo0x2v41 * pStruct ) { guyyw1px3ny ( &
pStruct -> InputStream ) ; } static void cul5ac3gcr5 ( ovagoamv4w * pStruct )
{ bnsqmwm4pzz ( & pStruct -> _pobj0 ) ; o3ufq2hnejy5y ( & pStruct -> _pobj1 )
; } static void ggpbldjcutv ( dp0kdzdsab * pStruct ) { cul5ac3gcr5 ( &
pStruct -> TCPIPObj ) ; } static void dv5oz50wz1 ( akean23d1n * * pEmxArray )
{ if ( * pEmxArray != ( akean23d1n * ) NULL ) { if ( ( ( * pEmxArray ) ->
data != ( uint8_T * ) NULL ) && ( * pEmxArray ) -> canFreeData ) { free ( ( *
pEmxArray ) -> data ) ; } free ( ( * pEmxArray ) -> size ) ; free ( *
pEmxArray ) ; * pEmxArray = ( akean23d1n * ) NULL ; } } static ovagoamv4w *
pjg025uf43 ( ovagoamv4w * obj ) { CoderChannel chImpl ; CoderInputStream
streamImpl ; CoderOutputStream streamImpl_p ; akean23d1n * exampleData ;
g1hz5apriq * iobj_0 ; hscjo2zzvm * obj_p ; kc1cjr2jks * c ; kc1cjr2jks *
options_ServiceName ; kwgo0x2v41 * iobj_1 ; ovagoamv4w * b_obj ; real_T
varargin_8_idx_0 ; real_T varargin_8_idx_1 ; int32_T loop_ub ; int32_T
success ; uint32_T tmp ; char_T deviceFullPath_data [ 4096 ] ; char_T
devicePlugin_data [ 4096 ] ; char_T localAbsPath [ 4096 ] ; char_T errorID [
1024 ] ; char_T errorText [ 1024 ] ; char_T b [ 9 ] ; boolean_T hasSyncError
; boolean_T result ; static const char_T tmp_p [ 9 ] = { '1' , '2' , '7' ,
'.' , '0' , '.' , '0' , '.' , '1' } ; static const lchp1rikuv tmp_e = { true
, true , 0ULL } ; static const char_T tmp_i [ 13 ] = { 'l' , 'i' , 't' , 't'
, 'l' , 'e' , '-' , 'e' , 'n' , 'd' , 'i' , 'a' , 'n' } ; static const char_T
tmp_m [ 5 ] = { 'u' , 'i' , 'n' , 't' , '8' } ; int32_T deviceFullPath_size [
2 ] ; int32_T converterPlugin_size_idx_1 ; obj -> ConnectTimeout = ( rtInf )
; obj -> InputBufferSize = ( rtInf ) ; obj -> OutputBufferSize = ( rtInf ) ;
obj -> TransferDelay = true ; b_obj = obj ; for ( success = 0 ; success < 9 ;
success ++ ) { obj -> RemoteHost [ success ] = tmp_p [ success ] ; } obj ->
RemotePort = 9999.0 ; iobj_0 = & obj -> _pobj0 ; iobj_1 = & obj -> _pobj1 ;
for ( success = 0 ; success < 9 ; success ++ ) { b [ success ] = obj ->
RemoteHost [ success ] ; } varargin_8_idx_0 = muDoubleScalarRound ( obj ->
RemotePort ) ; if ( varargin_8_idx_0 < 4.294967296E+9 ) { if (
varargin_8_idx_0 >= 0.0 ) { tmp = ( uint32_T ) varargin_8_idx_0 ; } else {
tmp = 0U ; } } else if ( varargin_8_idx_0 >= 4.294967296E+9 ) { tmp =
MAX_uint32_T ; } else { tmp = 0U ; } gglhpceojs ( & options_ServiceName , 2 )
; dvc4xvihap ( tmp , options_ServiceName ) ; coderComputeAbsolutePath (
"tcpclientdevice.dll" , & localAbsPath [ 0 ] ) ; a0hl5tbmat ( localAbsPath ,
deviceFullPath_data , deviceFullPath_size ) ; if ( deviceFullPath_size [ 1 ]
!= 0 ) { success = deviceFullPath_size [ 1 ] ; loop_ub = deviceFullPath_size
[ 1 ] ; memcpy ( & devicePlugin_data [ 0 ] , & deviceFullPath_data [ 0 ] , (
uint32_T ) loop_ub * sizeof ( char_T ) ) ; } else { coderComputeAbsolutePath
(
 "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\shared\\networklib\\bin\\win64\\tcpclientdevice.dll"
, & localAbsPath [ 0 ] ) ; a0hl5tbmat ( localAbsPath , deviceFullPath_data ,
deviceFullPath_size ) ; if ( deviceFullPath_size [ 1 ] != 0 ) { success =
deviceFullPath_size [ 1 ] ; loop_ub = deviceFullPath_size [ 1 ] ; memcpy ( &
devicePlugin_data [ 0 ] , & deviceFullPath_data [ 0 ] , ( uint32_T ) loop_ub
* sizeof ( char_T ) ) ; } else { success = 0 ; } } coderComputeAbsolutePath (
"networkcoderconverter.dll" , & localAbsPath [ 0 ] ) ; a0hl5tbmat (
localAbsPath , deviceFullPath_data , deviceFullPath_size ) ; if (
deviceFullPath_size [ 1 ] != 0 ) { converterPlugin_size_idx_1 =
deviceFullPath_size [ 1 ] ; loop_ub = deviceFullPath_size [ 1 ] ; memcpy ( &
localAbsPath [ 0 ] , & deviceFullPath_data [ 0 ] , ( uint32_T ) loop_ub *
sizeof ( char_T ) ) ; } else { coderComputeAbsolutePath (
 "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\shared\\networklib\\bin\\win64\\networkcoderconverter.dll"
, & localAbsPath [ 0 ] ) ; a0hl5tbmat ( localAbsPath , deviceFullPath_data ,
deviceFullPath_size ) ; if ( deviceFullPath_size [ 1 ] != 0 ) {
converterPlugin_size_idx_1 = deviceFullPath_size [ 1 ] ; loop_ub =
deviceFullPath_size [ 1 ] ; memcpy ( & localAbsPath [ 0 ] , &
deviceFullPath_data [ 0 ] , ( uint32_T ) loop_ub * sizeof ( char_T ) ) ; }
else { converterPlugin_size_idx_1 = 0 ; } } varargin_8_idx_0 = obj ->
InputBufferSize ; varargin_8_idx_1 = obj -> OutputBufferSize ; obj -> _pobj1
. CustomProps = tmp_e ; obj -> _pobj1 . ChannelImpl = 0 ; if ( success - 1 >=
0 ) { memcpy ( & rtB . b_devicePluginPath_data [ 0 ] , & devicePlugin_data [
0 ] , ( uint32_T ) success * sizeof ( char_T ) ) ; } rtB .
b_devicePluginPath_data [ success ] = '\x00' ; if (
converterPlugin_size_idx_1 - 1 >= 0 ) { memcpy ( & rtB .
b_converterPluginPath_data [ 0 ] , & localAbsPath [ 0 ] , ( uint32_T )
converterPlugin_size_idx_1 * sizeof ( char_T ) ) ; } rtB .
b_converterPluginPath_data [ converterPlugin_size_idx_1 ] = '\x00' ; chImpl =
coderChannelCreate ( & rtB . b_devicePluginPath_data [ 0 ] , & rtB .
b_converterPluginPath_data [ 0 ] , varargin_8_idx_0 , varargin_8_idx_1 , &
errorID [ 0 ] , & errorText [ 0 ] ) ; obj -> _pobj1 . ChannelImpl = chImpl ;
chImpl = obj -> _pobj1 . ChannelImpl ; gglhpceojs ( & c , 2 ) ; if (
options_ServiceName -> size [ 1 ] == 1 ) { success = c -> size [ 0 ] * c ->
size [ 1 ] ; c -> size [ 0 ] = 1 ; c -> size [ 1 ] = 2 ; jzxbjwmmtq ( c ,
success ) ; c -> data [ 0 ] = options_ServiceName -> data [ 0 ] ; c -> data [
1 ] = options_ServiceName -> data [ 0 ] ; } else { success = c -> size [ 0 ]
* c -> size [ 1 ] ; c -> size [ 0 ] = 1 ; c -> size [ 1 ] =
options_ServiceName -> size [ 1 ] ; jzxbjwmmtq ( c , success ) ; loop_ub =
options_ServiceName -> size [ 1 ] ; if ( loop_ub - 1 >= 0 ) { memcpy ( & c ->
data [ 0 ] , & options_ServiceName -> data [ 0 ] , ( uint32_T ) loop_ub *
sizeof ( char_T ) ) ; } } success = coderChannelInit ( chImpl , 2 ,
"HostName" , "char" , 9 , & b [ 0 ] , "ServiceName" , "char" ,
options_ServiceName -> size [ 1 ] , & c -> data [ 0 ] ) ; lioe0t4jfb ( & c )
; lioe0t4jfb ( & options_ServiceName ) ; if ( success == 0 ) {
coderChannelHasSyncError ( chImpl , & hasSyncError ) ; if ( ! hasSyncError )
{ coderChannelGetLastError ( chImpl , & errorID [ 0 ] , & errorText [ 0 ] ) ;
} else { coderChannelGetLastSyncError ( chImpl , & errorID [ 0 ] , &
errorText [ 0 ] ) ; } } chImpl = obj -> _pobj1 . ChannelImpl ; iobj_1 ->
InputStream . Timeout = 10.0 ; streamImpl = coderChannelGetInputStream (
chImpl ) ; iobj_1 -> InputStream . StreamImpl = streamImpl ; success = iobj_1
-> InputStream . ExampleData -> size [ 0 ] * iobj_1 -> InputStream .
ExampleData -> size [ 1 ] ; iobj_1 -> InputStream . ExampleData -> size [ 0 ]
= 1 ; iobj_1 -> InputStream . ExampleData -> size [ 1 ] = 1 ; kcbbxsln5r (
iobj_1 -> InputStream . ExampleData , success ) ; iobj_1 -> InputStream .
ExampleData -> data [ 0 ] = 0U ; pgkvysv3zg ( & exampleData , 2 ) ; success =
exampleData -> size [ 0 ] * exampleData -> size [ 1 ] ; exampleData -> size [
0 ] = iobj_1 -> InputStream . ExampleData -> size [ 0 ] ; kcbbxsln5r (
exampleData , success ) ; iobj_1 -> InputStream . PartialPacket -> size [ 0 ]
= exampleData -> size [ 0 ] ; iobj_1 -> InputStream . PartialPacket -> size [
1 ] = 0 ; iobj_1 -> InputStream . PartialPacketStart = 0.0 ; iobj_1 ->
InputStream . PartialPacketCount = 0.0 ; iobj_1 -> InputStream .
matlabCodegenIsDeleted = false ; chImpl = obj -> _pobj1 . ChannelImpl ;
iobj_1 -> OutputStream . Timeout = 10.0 ; streamImpl_p =
coderChannelGetOutputStream ( chImpl ) ; iobj_1 -> OutputStream . StreamImpl
= streamImpl_p ; iobj_1 -> OutputStream . matlabCodegenIsDeleted = false ;
obj -> _pobj1 . matlabCodegenIsDeleted = false ; obj -> AsyncIOChannel = &
obj -> _pobj1 ; iobj_1 = obj -> AsyncIOChannel ; iobj_0 -> AllowPartialReads
= false ; for ( success = 0 ; success < 13 ; success ++ ) { iobj_0 ->
MachineByteOrder [ success ] = tmp_i [ success ] ; } iobj_0 -> AsyncIOChannel
= iobj_1 ; success = iobj_0 -> ByteOrder -> size [ 0 ] * iobj_0 -> ByteOrder
-> size [ 1 ] ; iobj_0 -> ByteOrder -> size [ 0 ] = 1 ; iobj_0 -> ByteOrder
-> size [ 1 ] = 0 ; iobj_0 -> ByteOrder -> size [ 0 ] = 1 ; iobj_0 ->
ByteOrder -> size [ 1 ] = 13 ; jzxbjwmmtq ( iobj_0 -> ByteOrder , success ) ;
for ( success = 0 ; success < 13 ; success ++ ) { iobj_0 -> ByteOrder -> data
[ success ] = tmp_i [ success ] ; } success = iobj_0 -> DataFieldName -> size
[ 0 ] * iobj_0 -> DataFieldName -> size [ 1 ] ; iobj_0 -> DataFieldName ->
size [ 0 ] = 1 ; iobj_0 -> DataFieldName -> size [ 1 ] = 0 ; iobj_0 ->
DataFieldName -> size [ 0 ] = 1 ; iobj_0 -> DataFieldName -> size [ 1 ] = 4 ;
jzxbjwmmtq ( iobj_0 -> DataFieldName , success ) ; iobj_0 -> DataFieldName ->
data [ 0 ] = 'D' ; iobj_0 -> DataFieldName -> data [ 1 ] = 'a' ; iobj_0 ->
DataFieldName -> data [ 2 ] = 't' ; iobj_0 -> DataFieldName -> data [ 3 ] =
'a' ; success = iobj_0 -> NativeDataType -> size [ 0 ] * iobj_0 ->
NativeDataType -> size [ 1 ] ; iobj_0 -> NativeDataType -> size [ 0 ] = 1 ;
iobj_0 -> NativeDataType -> size [ 1 ] = 0 ; iobj_0 -> NativeDataType -> size
[ 0 ] = 1 ; iobj_0 -> NativeDataType -> size [ 1 ] = 5 ; jzxbjwmmtq ( iobj_0
-> NativeDataType , success ) ; for ( success = 0 ; success < 5 ; success ++
) { iobj_0 -> NativeDataType -> data [ success ] = tmp_m [ success ] ; }
obj_p = & iobj_0 -> UnreadDataBuffer ; iobj_0 -> UnreadDataBuffer .
BytesPerElement = 1.0 ; coderComputeAbsolutePath ( "buffer.dll" , &
localAbsPath [ 0 ] ) ; a0hl5tbmat ( localAbsPath , deviceFullPath_data ,
deviceFullPath_size ) ; if ( deviceFullPath_size [ 1 ] != 0 ) { success =
deviceFullPath_size [ 1 ] ; loop_ub = deviceFullPath_size [ 1 ] ; memcpy ( &
devicePlugin_data [ 0 ] , & deviceFullPath_data [ 0 ] , ( uint32_T ) loop_ub
* sizeof ( char_T ) ) ; } else { coderComputeAbsolutePath (
 "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\shared\\testmeaslib\\general\\bin\\win64\\buffer.dll"
, & localAbsPath [ 0 ] ) ; a0hl5tbmat ( localAbsPath , deviceFullPath_data ,
deviceFullPath_size ) ; if ( deviceFullPath_size [ 1 ] != 0 ) { success =
deviceFullPath_size [ 1 ] ; loop_ub = deviceFullPath_size [ 1 ] ; memcpy ( &
devicePlugin_data [ 0 ] , & deviceFullPath_data [ 0 ] , ( uint32_T ) loop_ub
* sizeof ( char_T ) ) ; } else { success = 0 ; } } coderComputeAbsolutePath (
"buffercoderconverter.dll" , & localAbsPath [ 0 ] ) ; a0hl5tbmat (
localAbsPath , deviceFullPath_data , deviceFullPath_size ) ; if (
deviceFullPath_size [ 1 ] != 0 ) { converterPlugin_size_idx_1 =
deviceFullPath_size [ 1 ] ; loop_ub = deviceFullPath_size [ 1 ] ; memcpy ( &
localAbsPath [ 0 ] , & deviceFullPath_data [ 0 ] , ( uint32_T ) loop_ub *
sizeof ( char_T ) ) ; } else { coderComputeAbsolutePath (
 "C:\\Program Files\\MATLAB\\R2022b\\toolbox\\shared\\testmeaslib\\general\\bin\\win64\\buffercoderconverter.dll"
, & localAbsPath [ 0 ] ) ; a0hl5tbmat ( localAbsPath , deviceFullPath_data ,
deviceFullPath_size ) ; if ( deviceFullPath_size [ 1 ] != 0 ) {
converterPlugin_size_idx_1 = deviceFullPath_size [ 1 ] ; loop_ub =
deviceFullPath_size [ 1 ] ; memcpy ( & localAbsPath [ 0 ] , &
deviceFullPath_data [ 0 ] , ( uint32_T ) loop_ub * sizeof ( char_T ) ) ; }
else { converterPlugin_size_idx_1 = 0 ; } } iobj_0 -> UnreadDataBuffer .
ChannelImpl = 0 ; if ( success - 1 >= 0 ) { memcpy ( & rtB .
b_devicePluginPath_data [ 0 ] , & devicePlugin_data [ 0 ] , ( uint32_T )
success * sizeof ( char_T ) ) ; } rtB . b_devicePluginPath_data [ success ] =
'\x00' ; if ( converterPlugin_size_idx_1 - 1 >= 0 ) { memcpy ( & rtB .
b_converterPluginPath_data [ 0 ] , & localAbsPath [ 0 ] , ( uint32_T )
converterPlugin_size_idx_1 * sizeof ( char_T ) ) ; } rtB .
b_converterPluginPath_data [ converterPlugin_size_idx_1 ] = '\x00' ; chImpl =
coderChannelCreate ( & rtB . b_devicePluginPath_data [ 0 ] , & rtB .
b_converterPluginPath_data [ 0 ] , ( rtInf ) , 0.0 , & errorID [ 0 ] , &
errorText [ 0 ] ) ; iobj_0 -> UnreadDataBuffer . ChannelImpl = chImpl ;
chImpl = iobj_0 -> UnreadDataBuffer . ChannelImpl ; success =
coderChannelInit ( chImpl , 0 ) ; if ( success == 0 ) {
coderChannelHasSyncError ( chImpl , & hasSyncError ) ; if ( ! hasSyncError )
{ coderChannelGetLastError ( chImpl , & errorID [ 0 ] , & errorText [ 0 ] ) ;
} else { coderChannelGetLastSyncError ( chImpl , & errorID [ 0 ] , &
errorText [ 0 ] ) ; } } chImpl = iobj_0 -> UnreadDataBuffer . ChannelImpl ;
obj_p -> InputStream . Timeout = 10.0 ; streamImpl =
coderChannelGetInputStream ( chImpl ) ; obj_p -> InputStream . StreamImpl =
streamImpl ; success = obj_p -> InputStream . ExampleData -> size [ 0 ] *
obj_p -> InputStream . ExampleData -> size [ 1 ] ; obj_p -> InputStream .
ExampleData -> size [ 0 ] = 1 ; obj_p -> InputStream . ExampleData -> size [
1 ] = 1 ; kcbbxsln5r ( obj_p -> InputStream . ExampleData , success ) ; obj_p
-> InputStream . ExampleData -> data [ 0 ] = 0U ; success = exampleData ->
size [ 0 ] * exampleData -> size [ 1 ] ; exampleData -> size [ 0 ] = obj_p ->
InputStream . ExampleData -> size [ 0 ] ; kcbbxsln5r ( exampleData , success
) ; obj_p -> InputStream . PartialPacket -> size [ 0 ] = exampleData -> size
[ 0 ] ; dv5oz50wz1 ( & exampleData ) ; obj_p -> InputStream . PartialPacket
-> size [ 1 ] = 0 ; obj_p -> InputStream . PartialPacketStart = 0.0 ; obj_p
-> InputStream . PartialPacketCount = 0.0 ; obj_p -> InputStream .
matlabCodegenIsDeleted = false ; chImpl = iobj_0 -> UnreadDataBuffer .
ChannelImpl ; obj_p -> OutputStream . Timeout = 10.0 ; streamImpl_p =
coderChannelGetOutputStream ( chImpl ) ; obj_p -> OutputStream . StreamImpl =
streamImpl_p ; obj_p -> OutputStream . matlabCodegenIsDeleted = false ;
iobj_0 -> UnreadDataBuffer . TotalElementsWritten = 0.0 ; iobj_0 ->
UnreadDataBuffer . PartialPacket -> size [ 0 ] = 1 ; iobj_0 ->
UnreadDataBuffer . PartialPacket -> size [ 1 ] = 0 ; iobj_0 ->
UnreadDataBuffer . PartialPacket -> size [ 0 ] = 0 ; iobj_0 ->
UnreadDataBuffer . PartialPacket -> size [ 1 ] = 0 ; iobj_0 ->
UnreadDataBuffer . PartialPacketStart = 0.0 ; iobj_0 -> UnreadDataBuffer .
PartialPacketCount = 0.0 ; iobj_0 -> UnreadDataBuffer .
matlabCodegenIsDeleted = false ; chImpl = iobj_0 -> UnreadDataBuffer .
ChannelImpl ; success = coderChannelIsOpen ( chImpl , & result ) ; if (
success == 0 ) { coderChannelHasSyncError ( chImpl , & hasSyncError ) ; if (
! hasSyncError ) { coderChannelGetLastError ( chImpl , & errorID [ 0 ] , &
errorText [ 0 ] ) ; } else { coderChannelGetLastSyncError ( chImpl , &
errorID [ 0 ] , & errorText [ 0 ] ) ; } } if ( ! result ) { chImpl = iobj_0
-> UnreadDataBuffer . ChannelImpl ; success = coderChannelOpen ( chImpl , 0 )
; if ( success == 0 ) { coderChannelHasSyncError ( chImpl , & hasSyncError )
; if ( ! hasSyncError ) { coderChannelGetLastError ( chImpl , & errorID [ 0 ]
, & errorText [ 0 ] ) ; } else { coderChannelGetLastSyncError ( chImpl , &
errorID [ 0 ] , & errorText [ 0 ] ) ; } } } iobj_0 -> matlabCodegenIsDeleted
= false ; obj -> TransportChannel = iobj_0 ; obj -> IsWriteOnly = false ; obj
-> IsSharingPort = true ; iobj_0 = obj -> TransportChannel ; success = iobj_0
-> ByteOrder -> size [ 0 ] * iobj_0 -> ByteOrder -> size [ 1 ] ; iobj_0 ->
ByteOrder -> size [ 0 ] = 1 ; iobj_0 -> ByteOrder -> size [ 1 ] = 0 ; iobj_0
-> ByteOrder -> size [ 0 ] = 1 ; iobj_0 -> ByteOrder -> size [ 1 ] = 13 ;
jzxbjwmmtq ( iobj_0 -> ByteOrder , success ) ; for ( success = 0 ; success <
13 ; success ++ ) { iobj_0 -> ByteOrder -> data [ success ] = tmp_i [ success
] ; } iobj_0 = obj -> TransportChannel ; success = iobj_0 -> NativeDataType
-> size [ 0 ] * iobj_0 -> NativeDataType -> size [ 1 ] ; iobj_0 ->
NativeDataType -> size [ 0 ] = 1 ; iobj_0 -> NativeDataType -> size [ 1 ] = 0
; iobj_0 -> NativeDataType -> size [ 0 ] = 1 ; iobj_0 -> NativeDataType ->
size [ 1 ] = 5 ; jzxbjwmmtq ( iobj_0 -> NativeDataType , success ) ; for (
success = 0 ; success < 5 ; success ++ ) { iobj_0 -> NativeDataType -> data [
success ] = tmp_m [ success ] ; } iobj_0 = obj -> TransportChannel ; success
= iobj_0 -> DataFieldName -> size [ 0 ] * iobj_0 -> DataFieldName -> size [ 1
] ; iobj_0 -> DataFieldName -> size [ 0 ] = 1 ; iobj_0 -> DataFieldName ->
size [ 1 ] = 0 ; iobj_0 -> DataFieldName -> size [ 0 ] = 1 ; iobj_0 ->
DataFieldName -> size [ 1 ] = 4 ; jzxbjwmmtq ( iobj_0 -> DataFieldName ,
success ) ; iobj_0 -> DataFieldName -> data [ 0 ] = 'D' ; iobj_0 ->
DataFieldName -> data [ 1 ] = 'a' ; iobj_0 -> DataFieldName -> data [ 2 ] =
't' ; iobj_0 -> DataFieldName -> data [ 3 ] = 'a' ; obj ->
matlabCodegenIsDeleted = false ; return b_obj ; } static void l0afvsmpfa (
dp0kdzdsab * obj ) { CoderChannel chImpl ; ax0y0tfz0l * inputStream ;
e4wb5cpnqg * outputStream ; g1hz5apriq * obj_p ; kc1cjr2jks * c ; kc1cjr2jks
* options_ServiceName ; kwgo0x2v41 * obj_e ; real_T d [ 2 ] ; real_T e [ 2 ]
; real_T f [ 2 ] ; real_T options_ConnectTimeout ; int32_T success ; uint32_T
tmp ; char_T errorID [ 1024 ] ; char_T errorText [ 1024 ] ; char_T b [ 9 ] ;
boolean_T g [ 2 ] ; boolean_T h [ 2 ] ; boolean_T i [ 2 ] ; boolean_T
hasSyncError ; boolean_T options_IsSharingPort ; boolean_T
options_IsWriteOnly ; boolean_T result ; boolean_T value ; static const
char_T tmp_p [ 10 ] = { 'b' , 'i' , 'g' , '-' , 'e' , 'n' , 'd' , 'i' , 'a' ,
'n' } ; obj -> isSetupComplete = false ; obj -> isInitialized = 1 ;
pjg025uf43 ( & obj -> TCPIPObj ) ; outputStream = & obj -> TCPIPObj .
AsyncIOChannel -> OutputStream ; outputStream -> Timeout = 10.0 ; inputStream
= & obj -> TCPIPObj . AsyncIOChannel -> InputStream ; inputStream -> Timeout
= 10.0 ; obj_p = obj -> TCPIPObj . TransportChannel ; success = obj_p ->
ByteOrder -> size [ 0 ] * obj_p -> ByteOrder -> size [ 1 ] ; obj_p ->
ByteOrder -> size [ 0 ] = 1 ; obj_p -> ByteOrder -> size [ 1 ] = 0 ; obj_p ->
ByteOrder -> size [ 0 ] = 1 ; obj_p -> ByteOrder -> size [ 1 ] = 10 ;
jzxbjwmmtq ( obj_p -> ByteOrder , success ) ; for ( success = 0 ; success <
10 ; success ++ ) { obj_p -> ByteOrder -> data [ success ] = tmp_p [ success
] ; } obj_e = obj -> TCPIPObj . AsyncIOChannel ; chImpl = obj_e ->
ChannelImpl ; success = coderChannelIsOpen ( chImpl , & result ) ; if (
success == 0 ) { coderChannelHasSyncError ( chImpl , & hasSyncError ) ; if (
! hasSyncError ) { coderChannelGetLastError ( chImpl , & errorID [ 0 ] , &
errorText [ 0 ] ) ; } else { coderChannelGetLastSyncError ( chImpl , &
errorID [ 0 ] , & errorText [ 0 ] ) ; } } for ( success = 0 ; success < 9 ;
success ++ ) { b [ success ] = obj -> TCPIPObj . RemoteHost [ success ] ; }
options_ConnectTimeout = muDoubleScalarRound ( obj -> TCPIPObj . RemotePort )
; if ( options_ConnectTimeout < 4.294967296E+9 ) { if (
options_ConnectTimeout >= 0.0 ) { tmp = ( uint32_T ) options_ConnectTimeout ;
} else { tmp = 0U ; } } else if ( options_ConnectTimeout >= 4.294967296E+9 )
{ tmp = MAX_uint32_T ; } else { tmp = 0U ; } gglhpceojs ( &
options_ServiceName , 2 ) ; dvc4xvihap ( tmp , options_ServiceName ) ;
options_ConnectTimeout = obj -> TCPIPObj . ConnectTimeout ;
options_IsWriteOnly = obj -> TCPIPObj . IsWriteOnly ; options_IsSharingPort =
obj -> TCPIPObj . IsSharingPort ; obj_p = obj -> TCPIPObj . TransportChannel
; obj_e = obj_p -> AsyncIOChannel ; chImpl = obj_e -> ChannelImpl ; success =
coderChannelIsOpen ( chImpl , & result ) ; if ( success == 0 ) {
coderChannelHasSyncError ( chImpl , & hasSyncError ) ; if ( ! hasSyncError )
{ coderChannelGetLastError ( chImpl , & errorID [ 0 ] , & errorText [ 0 ] ) ;
} else { coderChannelGetLastSyncError ( chImpl , & errorID [ 0 ] , &
errorText [ 0 ] ) ; } } if ( ! result ) { value = obj -> TCPIPObj .
TransferDelay ; } else { obj_e = obj -> TCPIPObj . AsyncIOChannel ; value =
obj_e -> CustomProps . TransferDelay ; chImpl = obj_e -> ChannelImpl ;
success = coderChannelGetPropertyValue ( chImpl , "TransferDelay" , "logical"
, 1 , & value ) ; if ( success == 0 ) { coderChannelHasSyncError ( chImpl , &
hasSyncError ) ; if ( ! hasSyncError ) { coderChannelGetLastError ( chImpl ,
& errorID [ 0 ] , & errorText [ 0 ] ) ; } else { coderChannelGetLastSyncError
( chImpl , & errorID [ 0 ] , & errorText [ 0 ] ) ; } } } obj_e = obj ->
TCPIPObj . AsyncIOChannel ; chImpl = obj_e -> ChannelImpl ; success =
coderChannelIsOpen ( chImpl , & result ) ; if ( success == 0 ) {
coderChannelHasSyncError ( chImpl , & hasSyncError ) ; if ( ! hasSyncError )
{ coderChannelGetLastError ( chImpl , & errorID [ 0 ] , & errorText [ 0 ] ) ;
} else { coderChannelGetLastSyncError ( chImpl , & errorID [ 0 ] , &
errorText [ 0 ] ) ; } } if ( ! result ) { chImpl = obj_e -> ChannelImpl ;
gglhpceojs ( & c , 2 ) ; if ( options_ServiceName -> size [ 1 ] == 1 ) {
success = c -> size [ 0 ] * c -> size [ 1 ] ; c -> size [ 0 ] = 1 ; c -> size
[ 1 ] = 2 ; jzxbjwmmtq ( c , success ) ; c -> data [ 0 ] =
options_ServiceName -> data [ 0 ] ; c -> data [ 1 ] = options_ServiceName ->
data [ 0 ] ; } else { success = c -> size [ 0 ] * c -> size [ 1 ] ; c -> size
[ 0 ] = 1 ; c -> size [ 1 ] = options_ServiceName -> size [ 1 ] ; jzxbjwmmtq
( c , success ) ; success = options_ServiceName -> size [ 1 ] ; if ( success
- 1 >= 0 ) { memcpy ( & c -> data [ 0 ] , & options_ServiceName -> data [ 0 ]
, ( uint32_T ) success * sizeof ( char_T ) ) ; } } d [ 0 ] = 65536.0 ; d [ 1
] = 65536.0 ; e [ 0 ] = 65536.0 ; e [ 1 ] = 65536.0 ; f [ 0 ] =
options_ConnectTimeout ; f [ 1 ] = options_ConnectTimeout ; g [ 0 ] =
options_IsWriteOnly ; g [ 1 ] = options_IsWriteOnly ; h [ 0 ] =
options_IsSharingPort ; h [ 1 ] = options_IsSharingPort ; i [ 0 ] = value ; i
[ 1 ] = value ; success = coderChannelOpen ( chImpl , 8 , "HostName" , "char"
, 9 , & b [ 0 ] , "ServiceName" , "char" , options_ServiceName -> size [ 1 ]
, & c -> data [ 0 ] , "ReceiveSize" , "double" , 1 , & d [ 0 ] , "SendSize" ,
"double" , 1 , & e [ 0 ] , "ConnectTimeout" , "double" , 1 , & f [ 0 ] ,
"IsWriteOnly" , "logical" , 1 , & g [ 0 ] , "IsSharingPort" , "logical" , 1 ,
& h [ 0 ] , "TransferDelay" , "logical" , 1 , & i [ 0 ] ) ; lioe0t4jfb ( & c
) ; if ( success == 0 ) { coderChannelHasSyncError ( chImpl , & hasSyncError
) ; if ( ! hasSyncError ) { coderChannelGetLastError ( chImpl , & errorID [ 0
] , & errorText [ 0 ] ) ; } else { coderChannelGetLastSyncError ( chImpl , &
errorID [ 0 ] , & errorText [ 0 ] ) ; } } } lioe0t4jfb ( &
options_ServiceName ) ; obj -> isSetupComplete = true ; } real_T
rt_urand_Upu32_Yd_f_pw_snf ( uint32_T * u ) { uint32_T hi ; uint32_T lo ; lo
= * u % 127773U * 16807U ; hi = * u / 127773U * 2836U ; if ( lo < hi ) { * u
= 2147483647U - ( hi - lo ) ; } else { * u = lo - hi ; } return ( real_T ) *
u * 4.6566128752457969E-10 ; } real_T rt_nrand_Upu32_Yd_f_pw_snf ( uint32_T *
u ) { real_T si ; real_T sr ; real_T y ; do { sr = 2.0 *
rt_urand_Upu32_Yd_f_pw_snf ( u ) - 1.0 ; si = 2.0 *
rt_urand_Upu32_Yd_f_pw_snf ( u ) - 1.0 ; si = sr * sr + si * si ; } while (
si > 1.0 ) ; y = muDoubleScalarSqrt ( - 2.0 * muDoubleScalarLog ( si ) / si )
* sr ; return y ; } static boolean_T ganujgx1ii ( const g1hz5apriqr * obj ,
const kc1cjr2jks * byteOrder ) { int32_T b_kstr ; boolean_T b_bool ; static
const char_T tmp [ 128 ] = { '\x00' , '\x01' , '\x02' , '\x03' , '\x04' ,
'\x05' , '\x06' , '\x07' , '\x08' , '\x09' , '\x0a' , '\x0b' , '\x0c' ,
'\x0d' , '\x0e' , '\x0f' , '\x10' , '\x11' , '\x12' , '\x13' , '\x14' ,
'\x15' , '\x16' , '\x17' , '\x18' , '\x19' , '\x1a' , '\x1b' , '\x1c' ,
'\x1d' , '\x1e' , '\x1f' , ' ' , '!' , '\"' , '#' , '$' , '%' , '&' , '\'' ,
'(' , ')' , '*' , '+' , ',' , '-' , '.' , '/' , '0' , '1' , '2' , '3' , '4' ,
'5' , '6' , '7' , '8' , '9' , ':' , ';' , '<' , '=' , '>' , '?' , '@' , 'a' ,
'b' , 'c' , 'd' , 'e' , 'f' , 'g' , 'h' , 'i' , 'j' , 'k' , 'l' , 'm' , 'n' ,
'o' , 'p' , 'q' , 'r' , 's' , 't' , 'u' , 'v' , 'w' , 'x' , 'y' , 'z' , '[' ,
'\\' , ']' , '^' , '_' , '`' , 'a' , 'b' , 'c' , 'd' , 'e' , 'f' , 'g' , 'h'
, 'i' , 'j' , 'k' , 'l' , 'm' , 'n' , 'o' , 'p' , 'q' , 'r' , 's' , 't' , 'u'
, 'v' , 'w' , 'x' , 'y' , 'z' , '{' , '|' , '}' , '~' , '\x7f' } ; int32_T
exitg1 ; b_bool = false ; if ( byteOrder -> size [ 1 ] != 13 ) { } else {
b_kstr = 1 ; do { exitg1 = 0 ; if ( b_kstr - 1 < 13 ) { if ( tmp [ ( uint8_T
) byteOrder -> data [ b_kstr - 1 ] & 127 ] != tmp [ ( uint8_T ) obj ->
MachineByteOrder [ b_kstr - 1 ] & 127 ] ) { exitg1 = 1 ; } else { b_kstr ++ ;
} } else { b_bool = true ; exitg1 = 1 ; } } while ( exitg1 == 0 ) ; } return
! b_bool ; } static void idziggsqd5j ( real_T * tstart_tv_sec , real_T *
tstart_tv_nsec ) { coderTimespec b_timespec ; if ( ! rtDW . nmtkuzrjds ) {
rtDW . nmtkuzrjds = true ; coderInitTimeFunctions ( & rtDW . jlvcxty141 ) ; }
coderTimeClockGettimeMonotonic ( & b_timespec , rtDW . jlvcxty141 ) ; *
tstart_tv_sec = b_timespec . tv_sec ; * tstart_tv_nsec = b_timespec . tv_nsec
; } static real_T lwekp2pixwo ( real_T tstart_tv_sec , real_T tstart_tv_nsec
) { coderTimespec b_timespec ; if ( ! rtDW . nmtkuzrjds ) { rtDW . nmtkuzrjds
= true ; coderInitTimeFunctions ( & rtDW . jlvcxty141 ) ; }
coderTimeClockGettimeMonotonic ( & b_timespec , rtDW . jlvcxty141 ) ; return
( b_timespec . tv_nsec - tstart_tv_nsec ) / 1.0E+9 + ( b_timespec . tv_sec -
tstart_tv_sec ) ; } static void fpycd4xlib4 ( const e4wb5cpnqg * obj , char_T
status_data [ ] , int32_T status_size [ 2 ] ) { CoderChannel chImpl ;
coderTimespec b_timespec ; coderTimespec b_timespec_p ; real_T et ; real_T
startTic_tv_nsec ; real_T startTic_tv_sec ; real_T timeoutInSeconds ; int32_T
success ; char_T errorID [ 1024 ] ; char_T errorText [ 1024 ] ; boolean_T
done ; boolean_T hasSyncError ; boolean_T timeout ; static const char_T tmp [
9 ] = { 'c' , 'o' , 'm' , 'p' , 'l' , 'e' , 't' , 'e' , 'd' } ; static const
char_T tmp_p [ 7 ] = { 't' , 'i' , 'm' , 'e' , 'o' , 'u' , 't' } ;
timeoutInSeconds = obj -> Timeout ; status_size [ 0 ] = 1 ; status_size [ 1 ]
= 0 ; timeout = false ; done = false ; success = coderStreamGetSpaceAvailable
( obj -> StreamImpl , & et ) ; if ( success == 0 ) { chImpl =
coderStreamGetChannel ( obj -> StreamImpl ) ; coderChannelHasSyncError (
chImpl , & hasSyncError ) ; if ( ! hasSyncError ) { coderChannelGetLastError
( chImpl , & errorID [ 0 ] , & errorText [ 0 ] ) ; } else {
coderChannelGetLastSyncError ( chImpl , & errorID [ 0 ] , & errorText [ 0 ] )
; } } hasSyncError = ( et > 0.0 ) ; idziggsqd5j ( & startTic_tv_sec , &
startTic_tv_nsec ) ; while ( ( ! hasSyncError ) && ( ! done ) && ( ! timeout
) ) { et = lwekp2pixwo ( startTic_tv_sec , startTic_tv_nsec ) ; if ( et < 1.0
) { b_timespec_p . tv_sec = 0.0 ; b_timespec_p . tv_nsec = 0.0 ;
coderTimeSleep ( & b_timespec_p ) ; } else { b_timespec . tv_sec = 0.0 ;
b_timespec . tv_nsec = 5.0E+6 ; coderTimeSleep ( & b_timespec ) ; } et =
lwekp2pixwo ( startTic_tv_sec , startTic_tv_nsec ) ; timeout = ( et >
timeoutInSeconds ) ; success = coderStreamIsDeviceDone ( obj -> StreamImpl ,
& done ) ; if ( success == 0 ) { chImpl = coderStreamGetChannel ( obj ->
StreamImpl ) ; coderChannelHasSyncError ( chImpl , & hasSyncError ) ; if ( !
hasSyncError ) { coderChannelGetLastError ( chImpl , & errorID [ 0 ] , &
errorText [ 0 ] ) ; } else { coderChannelGetLastSyncError ( chImpl , &
errorID [ 0 ] , & errorText [ 0 ] ) ; } } if ( done ) { done = true ; } else
{ success = coderStreamIsOpen ( obj -> StreamImpl , & done ) ; if ( success
== 0 ) { chImpl = coderStreamGetChannel ( obj -> StreamImpl ) ;
coderChannelHasSyncError ( chImpl , & hasSyncError ) ; if ( ! hasSyncError )
{ coderChannelGetLastError ( chImpl , & errorID [ 0 ] , & errorText [ 0 ] ) ;
} else { coderChannelGetLastSyncError ( chImpl , & errorID [ 0 ] , &
errorText [ 0 ] ) ; } } if ( ! done ) { done = true ; } else { done = false ;
} } success = coderStreamGetSpaceAvailable ( obj -> StreamImpl , & et ) ; if
( success == 0 ) { chImpl = coderStreamGetChannel ( obj -> StreamImpl ) ;
coderChannelHasSyncError ( chImpl , & hasSyncError ) ; if ( ! hasSyncError )
{ coderChannelGetLastError ( chImpl , & errorID [ 0 ] , & errorText [ 0 ] ) ;
} else { coderChannelGetLastSyncError ( chImpl , & errorID [ 0 ] , &
errorText [ 0 ] ) ; } } hasSyncError = ( et > 0.0 ) ; } if ( hasSyncError ) {
status_size [ 0 ] = 1 ; status_size [ 1 ] = 9 ; for ( success = 0 ; success <
9 ; success ++ ) { status_data [ success ] = tmp [ success ] ; } } else if (
done ) { status_size [ 0 ] = 1 ; status_size [ 1 ] = 4 ; status_data [ 0 ] =
'd' ; status_data [ 1 ] = 'o' ; status_data [ 2 ] = 'n' ; status_data [ 3 ] =
'e' ; } else if ( timeout ) { status_size [ 0 ] = 1 ; status_size [ 1 ] = 7 ;
for ( success = 0 ; success < 7 ; success ++ ) { status_data [ success ] =
tmp_p [ success ] ; } } } static boolean_T aygswycpr4 ( const char_T a_data [
] , const int32_T a_size [ 2 ] ) { int32_T b_kstr ; char_T b [ 9 ] ;
boolean_T b_bool ; static const char_T tmp [ 9 ] = { 'c' , 'o' , 'm' , 'p' ,
'l' , 'e' , 't' , 'e' , 'd' } ; static const char_T tmp_p [ 128 ] = { '\x00'
, '\x01' , '\x02' , '\x03' , '\x04' , '\x05' , '\x06' , '\x07' , '\x08' ,
'\x09' , '\x0a' , '\x0b' , '\x0c' , '\x0d' , '\x0e' , '\x0f' , '\x10' ,
'\x11' , '\x12' , '\x13' , '\x14' , '\x15' , '\x16' , '\x17' , '\x18' ,
'\x19' , '\x1a' , '\x1b' , '\x1c' , '\x1d' , '\x1e' , '\x1f' , ' ' , '!' ,
'\"' , '#' , '$' , '%' , '&' , '\'' , '(' , ')' , '*' , '+' , ',' , '-' , '.'
, '/' , '0' , '1' , '2' , '3' , '4' , '5' , '6' , '7' , '8' , '9' , ':' , ';'
, '<' , '=' , '>' , '?' , '@' , 'a' , 'b' , 'c' , 'd' , 'e' , 'f' , 'g' , 'h'
, 'i' , 'j' , 'k' , 'l' , 'm' , 'n' , 'o' , 'p' , 'q' , 'r' , 's' , 't' , 'u'
, 'v' , 'w' , 'x' , 'y' , 'z' , '[' , '\\' , ']' , '^' , '_' , '`' , 'a' ,
'b' , 'c' , 'd' , 'e' , 'f' , 'g' , 'h' , 'i' , 'j' , 'k' , 'l' , 'm' , 'n' ,
'o' , 'p' , 'q' , 'r' , 's' , 't' , 'u' , 'v' , 'w' , 'x' , 'y' , 'z' , '{' ,
'|' , '}' , '~' , '\x7f' } ; int32_T exitg1 ; for ( b_kstr = 0 ; b_kstr < 9 ;
b_kstr ++ ) { b [ b_kstr ] = tmp [ b_kstr ] ; } b_bool = false ; if ( a_size
[ 1 ] != 9 ) { } else { b_kstr = 1 ; do { exitg1 = 0 ; if ( b_kstr - 1 < 9 )
{ if ( tmp_p [ ( uint8_T ) a_data [ b_kstr - 1 ] & 127 ] != tmp_p [ ( int32_T
) b [ b_kstr - 1 ] ] ) { exitg1 = 1 ; } else { b_kstr ++ ; } } else { b_bool
= true ; exitg1 = 1 ; } } while ( exitg1 == 0 ) ; } return b_bool ; } static
void praqpj5wy4 ( e4wb5cpnqg * obj ) { CoderChannel chImpl ;
CoderOutputStream streamImpl ; coderTimespec b_timespec ; coderTimespec
b_timespec_p ; e4wb5cpnqg * obj_p ; real_T et ; real_T startTic_tv_nsec ;
real_T startTic_tv_sec ; real_T timeoutInSeconds ; int32_T success ; char_T
errorID [ 1024 ] ; char_T errorText [ 1024 ] ; char_T status_data [ 9 ] ;
char_T b [ 7 ] ; boolean_T done ; boolean_T hasSyncError ; boolean_T timeout
; static const char_T tmp [ 9 ] = { 'c' , 'o' , 'm' , 'p' , 'l' , 'e' , 't' ,
'e' , 'd' } ; static const char_T tmp_p [ 7 ] = { 't' , 'i' , 'm' , 'e' , 'o'
, 'u' , 't' } ; static const char_T tmp_e [ 7 ] = { 'i' , 'n' , 'v' , 'a' ,
'l' , 'i' , 'd' } ; static const char_T tmp_i [ 128 ] = { '\x00' , '\x01' ,
'\x02' , '\x03' , '\x04' , '\x05' , '\x06' , '\x07' , '\x08' , '\x09' ,
'\x0a' , '\x0b' , '\x0c' , '\x0d' , '\x0e' , '\x0f' , '\x10' , '\x11' ,
'\x12' , '\x13' , '\x14' , '\x15' , '\x16' , '\x17' , '\x18' , '\x19' ,
'\x1a' , '\x1b' , '\x1c' , '\x1d' , '\x1e' , '\x1f' , ' ' , '!' , '\"' , '#'
, '$' , '%' , '&' , '\'' , '(' , ')' , '*' , '+' , ',' , '-' , '.' , '/' ,
'0' , '1' , '2' , '3' , '4' , '5' , '6' , '7' , '8' , '9' , ':' , ';' , '<' ,
'=' , '>' , '?' , '@' , 'a' , 'b' , 'c' , 'd' , 'e' , 'f' , 'g' , 'h' , 'i' ,
'j' , 'k' , 'l' , 'm' , 'n' , 'o' , 'p' , 'q' , 'r' , 's' , 't' , 'u' , 'v' ,
'w' , 'x' , 'y' , 'z' , '[' , '\\' , ']' , '^' , '_' , '`' , 'a' , 'b' , 'c'
, 'd' , 'e' , 'f' , 'g' , 'h' , 'i' , 'j' , 'k' , 'l' , 'm' , 'n' , 'o' , 'p'
, 'q' , 'r' , 's' , 't' , 'u' , 'v' , 'w' , 'x' , 'y' , 'z' , '{' , '|' , '}'
, '~' , '\x7f' } ; int32_T exitg1 ; int32_T status_size_idx_1 ; obj_p = obj ;
timeoutInSeconds = obj -> Timeout ; status_size_idx_1 = 0 ; timeout = false ;
done = false ; streamImpl = obj -> StreamImpl ; success =
coderStreamGetDataAvailable ( streamImpl , & et ) ; if ( success == 0 ) {
chImpl = coderStreamGetChannel ( streamImpl ) ; coderChannelHasSyncError (
chImpl , & hasSyncError ) ; if ( ! hasSyncError ) { coderChannelGetLastError
( chImpl , & errorID [ 0 ] , & errorText [ 0 ] ) ; } else {
coderChannelGetLastSyncError ( chImpl , & errorID [ 0 ] , & errorText [ 0 ] )
; } } hasSyncError = ( et == 0.0 ) ; idziggsqd5j ( & startTic_tv_sec , &
startTic_tv_nsec ) ; while ( ( ! hasSyncError ) && ( ! done ) && ( ! timeout
) ) { et = lwekp2pixwo ( startTic_tv_sec , startTic_tv_nsec ) ; if ( et < 1.0
) { b_timespec_p . tv_sec = 0.0 ; b_timespec_p . tv_nsec = 0.0 ;
coderTimeSleep ( & b_timespec_p ) ; } else { b_timespec . tv_sec = 0.0 ;
b_timespec . tv_nsec = 5.0E+6 ; coderTimeSleep ( & b_timespec ) ; } et =
lwekp2pixwo ( startTic_tv_sec , startTic_tv_nsec ) ; timeout = ( et >
timeoutInSeconds ) ; streamImpl = obj_p -> StreamImpl ; success =
coderStreamIsDeviceDone ( streamImpl , & done ) ; if ( success == 0 ) {
chImpl = coderStreamGetChannel ( streamImpl ) ; coderChannelHasSyncError (
chImpl , & hasSyncError ) ; if ( ! hasSyncError ) { coderChannelGetLastError
( chImpl , & errorID [ 0 ] , & errorText [ 0 ] ) ; } else {
coderChannelGetLastSyncError ( chImpl , & errorID [ 0 ] , & errorText [ 0 ] )
; } } if ( done ) { done = true ; } else { streamImpl = obj_p -> StreamImpl ;
success = coderStreamIsOpen ( streamImpl , & done ) ; if ( success == 0 ) {
chImpl = coderStreamGetChannel ( streamImpl ) ; coderChannelHasSyncError (
chImpl , & hasSyncError ) ; if ( ! hasSyncError ) { coderChannelGetLastError
( chImpl , & errorID [ 0 ] , & errorText [ 0 ] ) ; } else {
coderChannelGetLastSyncError ( chImpl , & errorID [ 0 ] , & errorText [ 0 ] )
; } } if ( ! done ) { done = true ; } else { done = false ; } } streamImpl =
obj_p -> StreamImpl ; success = coderStreamGetDataAvailable ( streamImpl , &
et ) ; if ( success == 0 ) { chImpl = coderStreamGetChannel ( streamImpl ) ;
coderChannelHasSyncError ( chImpl , & hasSyncError ) ; if ( ! hasSyncError )
{ coderChannelGetLastError ( chImpl , & errorID [ 0 ] , & errorText [ 0 ] ) ;
} else { coderChannelGetLastSyncError ( chImpl , & errorID [ 0 ] , &
errorText [ 0 ] ) ; } } hasSyncError = ( et == 0.0 ) ; } if ( hasSyncError )
{ status_size_idx_1 = 9 ; for ( success = 0 ; success < 9 ; success ++ ) {
status_data [ success ] = tmp [ success ] ; } } else if ( done ) {
status_size_idx_1 = 4 ; status_data [ 0 ] = 'd' ; status_data [ 1 ] = 'o' ;
status_data [ 2 ] = 'n' ; status_data [ 3 ] = 'e' ; } else if ( timeout ) {
status_size_idx_1 = 7 ; for ( success = 0 ; success < 7 ; success ++ ) {
status_data [ success ] = tmp_p [ success ] ; } } for ( success = 0 ; success
< 7 ; success ++ ) { b [ success ] = tmp_e [ success ] ; } timeout = false ;
if ( status_size_idx_1 != 7 ) { } else { success = 1 ; do { exitg1 = 0 ; if (
success - 1 < 7 ) { if ( tmp_i [ ( int32_T ) status_data [ success - 1 ] ] !=
tmp_i [ ( int32_T ) b [ success - 1 ] ] ) { exitg1 = 1 ; } else { success ++
; } } else { timeout = true ; exitg1 = 1 ; } } while ( exitg1 == 0 ) ; } if (
! timeout ) { streamImpl = obj -> StreamImpl ; success = coderStreamFlush (
streamImpl ) ; if ( success == 0 ) { chImpl = coderStreamGetChannel (
streamImpl ) ; coderChannelHasSyncError ( chImpl , & hasSyncError ) ; if ( !
hasSyncError ) { coderChannelGetLastError ( chImpl , & errorID [ 0 ] , &
errorText [ 0 ] ) ; } else { coderChannelGetLastSyncError ( chImpl , &
errorID [ 0 ] , & errorText [ 0 ] ) ; } } } } static real_T guurnuuuj0 (
const hscjo2zzvm * obj ) { CoderChannel chImpl ; real_T count ; int32_T
success ; char_T errorID [ 1024 ] ; char_T errorText [ 1024 ] ; boolean_T
hasSyncError ; success = coderStreamGetDataAvailable ( obj -> InputStream .
StreamImpl , & count ) ; if ( success == 0 ) { chImpl = coderStreamGetChannel
( obj -> InputStream . StreamImpl ) ; coderChannelHasSyncError ( chImpl , &
hasSyncError ) ; if ( ! hasSyncError ) { coderChannelGetLastError ( chImpl ,
& errorID [ 0 ] , & errorText [ 0 ] ) ; } else { coderChannelGetLastSyncError
( chImpl , & errorID [ 0 ] , & errorText [ 0 ] ) ; } } return ( ( obj ->
InputStream . PartialPacketCount + count ) + obj -> PartialPacketCount ) /
obj -> BytesPerElement ; } static void idziggsqd5 ( real_T * tstart_tv_sec ,
real_T * tstart_tv_nsec ) { coderTimespec b_timespec ; if ( ! rtDW .
iaghp1202d ) { rtDW . iaghp1202d = true ; coderInitTimeFunctions ( & rtDW .
dfsexifu4j ) ; } coderTimeClockGettimeMonotonic ( & b_timespec , rtDW .
dfsexifu4j ) ; * tstart_tv_sec = b_timespec . tv_sec ; * tstart_tv_nsec =
b_timespec . tv_nsec ; } static real_T lwekp2pixw ( real_T tstart_tv_sec ,
real_T tstart_tv_nsec ) { coderTimespec b_timespec ; if ( ! rtDW . iaghp1202d
) { rtDW . iaghp1202d = true ; coderInitTimeFunctions ( & rtDW . dfsexifu4j )
; } coderTimeClockGettimeMonotonic ( & b_timespec , rtDW . dfsexifu4j ) ;
return ( b_timespec . tv_nsec - tstart_tv_nsec ) / 1.0E+9 + ( b_timespec .
tv_sec - tstart_tv_sec ) ; } static void d3nhfujrg5 ( const akean23d1n *
packet , real_T startIndex , real_T endIndex , akean23d1n * result ) {
int32_T e ; int32_T f ; int32_T i ; int32_T i_p ; int32_T loop_ub ; if ( (
packet -> size [ 0 ] == 1 ) || ( packet -> size [ 1 ] == 1 ) ) { if (
startIndex > endIndex ) { f = 0 ; e = 0 ; } else { f = ( int32_T ) startIndex
- 1 ; e = ( int32_T ) endIndex ; } i_p = result -> size [ 0 ] * result ->
size [ 1 ] ; result -> size [ 0 ] = 1 ; result -> size [ 1 ] = e - f ;
kcbbxsln5r ( result , i_p ) ; e -= f ; for ( i_p = 0 ; i_p < e ; i_p ++ ) {
result -> data [ result -> size [ 0 ] * i_p ] = packet -> data [ f + i_p ] ;
} } else { if ( startIndex > endIndex ) { f = 0 ; e = 0 ; } else { f = (
int32_T ) startIndex - 1 ; e = ( int32_T ) endIndex ; } i_p = result -> size
[ 0 ] * result -> size [ 1 ] ; result -> size [ 0 ] = packet -> size [ 0 ] ;
result -> size [ 1 ] = e - f ; kcbbxsln5r ( result , i_p ) ; e -= f ; for (
i_p = 0 ; i_p < e ; i_p ++ ) { loop_ub = packet -> size [ 0 ] ; for ( i = 0 ;
i < loop_ub ; i ++ ) { result -> data [ i + result -> size [ 0 ] * i_p ] =
packet -> data [ ( f + i_p ) * packet -> size [ 0 ] + i ] ; } } } } static
void d3nhfujrg53 ( const akean23d1n * packet , real_T endIndex , akean23d1n *
result ) { int32_T d ; int32_T i ; int32_T i_p ; int32_T loop_ub ; if ( (
packet -> size [ 0 ] == 1 ) || ( packet -> size [ 1 ] == 1 ) ) { if (
endIndex < 1.0 ) { d = 0 ; } else { d = ( int32_T ) endIndex ; } i_p = result
-> size [ 0 ] * result -> size [ 1 ] ; result -> size [ 0 ] = 1 ; result ->
size [ 1 ] = d ; kcbbxsln5r ( result , i_p ) ; for ( i_p = 0 ; i_p < d ; i_p
++ ) { result -> data [ result -> size [ 0 ] * i_p ] = packet -> data [ i_p ]
; } } else { if ( endIndex < 1.0 ) { d = 0 ; } else { d = ( int32_T )
endIndex ; } i_p = result -> size [ 0 ] * result -> size [ 1 ] ; result ->
size [ 0 ] = packet -> size [ 0 ] ; result -> size [ 1 ] = d ; kcbbxsln5r (
result , i_p ) ; for ( i_p = 0 ; i_p < d ; i_p ++ ) { loop_ub = packet ->
size [ 0 ] ; for ( i = 0 ; i < loop_ub ; i ++ ) { result -> data [ i + result
-> size [ 0 ] * i_p ] = packet -> data [ packet -> size [ 0 ] * i_p + i ] ; }
} } } static void lage0maggu ( ax0y0tfz0l * obj , real_T countRequested ,
akean23d1n * dataRead , real_T * countRead ) { akean23d1n * tempDataRead ;
real_T ppc ; ppc = obj -> PartialPacketCount ; if ( obj -> PartialPacketCount
> 0.0 ) { pgkvysv3zg ( & tempDataRead , 2 ) ; if ( countRequested < obj ->
PartialPacketCount ) { d3nhfujrg5 ( obj -> PartialPacket , obj ->
PartialPacketStart , ( obj -> PartialPacketStart + countRequested ) - 1.0 ,
tempDataRead ) ; * countRead = countRequested ; obj -> PartialPacketStart +=
countRequested ; obj -> PartialPacketCount = ppc - countRequested ; } else {
d3nhfujrg5 ( obj -> PartialPacket , obj -> PartialPacketStart , ( obj ->
PartialPacketStart + obj -> PartialPacketCount ) - 1.0 , tempDataRead ) ; *
countRead = obj -> PartialPacketCount ; obj -> PartialPacket -> size [ 0 ] =
obj -> ExampleData -> size [ 0 ] ; obj -> PartialPacket -> size [ 1 ] = 0 ;
obj -> PartialPacket -> size [ 1 ] = 0 ; obj -> PartialPacketStart = 0.0 ;
obj -> PartialPacketCount = 0.0 ; } d3nhfujrg53 ( tempDataRead , ( real_T )
tempDataRead -> size [ 1 ] , dataRead ) ; dv5oz50wz1 ( & tempDataRead ) ; }
else { dataRead -> size [ 0 ] = 1 ; dataRead -> size [ 1 ] = 0 ; * countRead
= 0.0 ; } } static void fodfy3ik2d ( jrxtexkjqq * * pEmxArray , int32_T
numDimensions ) { jrxtexkjqq * emxArray ; int32_T i ; * pEmxArray = (
jrxtexkjqq * ) malloc ( sizeof ( jrxtexkjqq ) ) ; emxArray = * pEmxArray ;
emxArray -> data = ( kkw0h0uzlf * ) NULL ; emxArray -> numDimensions =
numDimensions ; emxArray -> size = ( int32_T * ) malloc ( sizeof ( int32_T )
* ( uint32_T ) numDimensions ) ; emxArray -> allocatedSize = 0 ; emxArray ->
canFreeData = true ; for ( i = 0 ; i < numDimensions ; i ++ ) { emxArray ->
size [ i ] = 0 ; } } static void fpycd4xlib ( const ax0y0tfz0l * obj , char_T
status_data [ ] , int32_T status_size [ 2 ] ) { CoderChannel chImpl ;
coderTimespec b_timespec ; coderTimespec b_timespec_p ; real_T et ; real_T
startTic_tv_nsec ; real_T startTic_tv_sec ; real_T timeoutInSeconds ; int32_T
success ; char_T errorID [ 1024 ] ; char_T errorText [ 1024 ] ; boolean_T
done ; boolean_T hasSyncError ; boolean_T timeout ; static const char_T tmp [
9 ] = { 'c' , 'o' , 'm' , 'p' , 'l' , 'e' , 't' , 'e' , 'd' } ; static const
char_T tmp_p [ 7 ] = { 't' , 'i' , 'm' , 'e' , 'o' , 'u' , 't' } ;
timeoutInSeconds = obj -> Timeout ; status_size [ 0 ] = 1 ; status_size [ 1 ]
= 0 ; timeout = false ; done = false ; success = coderStreamGetDataAvailable
( obj -> StreamImpl , & et ) ; if ( success == 0 ) { chImpl =
coderStreamGetChannel ( obj -> StreamImpl ) ; coderChannelHasSyncError (
chImpl , & hasSyncError ) ; if ( ! hasSyncError ) { coderChannelGetLastError
( chImpl , & errorID [ 0 ] , & errorText [ 0 ] ) ; } else {
coderChannelGetLastSyncError ( chImpl , & errorID [ 0 ] , & errorText [ 0 ] )
; } } hasSyncError = ( et > 0.0 ) ; idziggsqd5 ( & startTic_tv_sec , &
startTic_tv_nsec ) ; while ( ( ! hasSyncError ) && ( ! done ) && ( ! timeout
) ) { et = lwekp2pixw ( startTic_tv_sec , startTic_tv_nsec ) ; if ( et < 1.0
) { b_timespec_p . tv_sec = 0.0 ; b_timespec_p . tv_nsec = 0.0 ;
coderTimeSleep ( & b_timespec_p ) ; } else { b_timespec . tv_sec = 0.0 ;
b_timespec . tv_nsec = 5.0E+6 ; coderTimeSleep ( & b_timespec ) ; } et =
lwekp2pixw ( startTic_tv_sec , startTic_tv_nsec ) ; timeout = ( et >
timeoutInSeconds ) ; success = coderStreamIsDeviceDone ( obj -> StreamImpl ,
& done ) ; if ( success == 0 ) { chImpl = coderStreamGetChannel ( obj ->
StreamImpl ) ; coderChannelHasSyncError ( chImpl , & hasSyncError ) ; if ( !
hasSyncError ) { coderChannelGetLastError ( chImpl , & errorID [ 0 ] , &
errorText [ 0 ] ) ; } else { coderChannelGetLastSyncError ( chImpl , &
errorID [ 0 ] , & errorText [ 0 ] ) ; } } if ( done ) { done = true ; } else
{ success = coderStreamIsOpen ( obj -> StreamImpl , & done ) ; if ( success
== 0 ) { chImpl = coderStreamGetChannel ( obj -> StreamImpl ) ;
coderChannelHasSyncError ( chImpl , & hasSyncError ) ; if ( ! hasSyncError )
{ coderChannelGetLastError ( chImpl , & errorID [ 0 ] , & errorText [ 0 ] ) ;
} else { coderChannelGetLastSyncError ( chImpl , & errorID [ 0 ] , &
errorText [ 0 ] ) ; } } if ( ! done ) { done = true ; } else { done = false ;
} } success = coderStreamGetDataAvailable ( obj -> StreamImpl , & et ) ; if (
success == 0 ) { chImpl = coderStreamGetChannel ( obj -> StreamImpl ) ;
coderChannelHasSyncError ( chImpl , & hasSyncError ) ; if ( ! hasSyncError )
{ coderChannelGetLastError ( chImpl , & errorID [ 0 ] , & errorText [ 0 ] ) ;
} else { coderChannelGetLastSyncError ( chImpl , & errorID [ 0 ] , &
errorText [ 0 ] ) ; } } hasSyncError = ( et > 0.0 ) ; } if ( hasSyncError ) {
status_size [ 0 ] = 1 ; status_size [ 1 ] = 9 ; for ( success = 0 ; success <
9 ; success ++ ) { status_data [ success ] = tmp [ success ] ; } } else if (
done ) { status_size [ 0 ] = 1 ; status_size [ 1 ] = 4 ; status_data [ 0 ] =
'd' ; status_data [ 1 ] = 'o' ; status_data [ 2 ] = 'n' ; status_data [ 3 ] =
'e' ; } else if ( timeout ) { status_size [ 0 ] = 1 ; status_size [ 1 ] = 7 ;
for ( success = 0 ; success < 7 ; success ++ ) { status_data [ success ] =
tmp_p [ success ] ; } } } static void dqkilabzr0 ( kkw0h0uzlf * pStruct ) {
pgkvysv3zg ( & pStruct -> f1 , 2 ) ; } static void i0ja5foi4d ( jrxtexkjqq *
emxArray , int32_T fromIndex , int32_T toIndex ) { int32_T i ; for ( i =
fromIndex ; i < toIndex ; i ++ ) { dqkilabzr0 ( & emxArray -> data [ i ] ) ;
} } static void pciyoa0qmy ( kkw0h0uzlf * pStruct ) { dv5oz50wz1 ( & pStruct
-> f1 ) ; } static void cum2hm0yhj ( jrxtexkjqq * emxArray , int32_T
fromIndex , int32_T toIndex ) { int32_T i ; for ( i = fromIndex ; i < toIndex
; i ++ ) { pciyoa0qmy ( & emxArray -> data [ i ] ) ; } } static void
b53du0mj04 ( jrxtexkjqq * emxArray , int32_T oldNumel ) { int32_T i ; int32_T
newNumel ; void * newData ; if ( oldNumel < 0 ) { oldNumel = 0 ; } newNumel =
1 ; for ( i = 0 ; i < emxArray -> numDimensions ; i ++ ) { newNumel *=
emxArray -> size [ i ] ; } if ( newNumel > emxArray -> allocatedSize ) { i =
emxArray -> allocatedSize ; if ( i < 16 ) { i = 16 ; } while ( i < newNumel )
{ if ( i > 1073741823 ) { i = MAX_int32_T ; } else { i <<= 1 ; } } newData =
calloc ( ( uint32_T ) i , sizeof ( kkw0h0uzlf ) ) ; if ( emxArray -> data !=
NULL ) { memcpy ( newData , emxArray -> data , sizeof ( kkw0h0uzlf ) * (
uint32_T ) oldNumel ) ; if ( emxArray -> canFreeData ) { free ( emxArray ->
data ) ; } } emxArray -> data = ( kkw0h0uzlf * ) newData ; emxArray ->
allocatedSize = i ; emxArray -> canFreeData = true ; } if ( oldNumel >
newNumel ) { cum2hm0yhj ( emxArray , newNumel , oldNumel ) ; } else if (
oldNumel < newNumel ) { i0ja5foi4d ( emxArray , oldNumel , newNumel ) ; } }
static void lex4eakni1 ( const ax0y0tfz0l * obj , real_T countRequested ,
jrxtexkjqq * packets , real_T * countRead ) { CoderChannel chImpl ;
akean23d1n * packet ; real_T bufferCounts [ 80 ] ; real_T countToRead ;
real_T numBuffers ; int32_T b_bufferIndex ; int32_T i ; int32_T outsize ;
int32_T success ; char_T errorID [ 1024 ] ; char_T errorText [ 1024 ] ;
boolean_T hasSyncError ; countToRead = 0.0 ; memset ( & bufferCounts [ 0 ] ,
0 , 80U * sizeof ( real_T ) ) ; numBuffers = 80.0 ; success =
coderInputStreamPeek ( obj -> StreamImpl , countRequested , & countToRead , &
bufferCounts [ 0 ] , & numBuffers ) ; if ( success == 0 ) { chImpl =
coderStreamGetChannel ( obj -> StreamImpl ) ; coderChannelHasSyncError (
chImpl , & hasSyncError ) ; if ( ! hasSyncError ) { coderChannelGetLastError
( chImpl , & errorID [ 0 ] , & errorText [ 0 ] ) ; } else {
coderChannelGetLastSyncError ( chImpl , & errorID [ 0 ] , & errorText [ 0 ] )
; } } success = ( int32_T ) numBuffers - 1 ; i = packets -> size [ 0 ] *
packets -> size [ 1 ] ; packets -> size [ 0 ] = 1 ; packets -> size [ 1 ] = (
int32_T ) numBuffers ; b53du0mj04 ( packets , i ) ; for ( b_bufferIndex = 0 ;
b_bufferIndex <= success ; b_bufferIndex ++ ) { outsize = ( int32_T )
bufferCounts [ b_bufferIndex ] ; i = packets -> data [ b_bufferIndex ] . f1
-> size [ 0 ] * packets -> data [ b_bufferIndex ] . f1 -> size [ 1 ] ;
packets -> data [ b_bufferIndex ] . f1 -> size [ 0 ] = 1 ; packets -> data [
b_bufferIndex ] . f1 -> size [ 1 ] = outsize ; kcbbxsln5r ( packets -> data [
b_bufferIndex ] . f1 , i ) ; for ( i = 0 ; i < outsize ; i ++ ) { packets ->
data [ b_bufferIndex ] . f1 -> data [ i ] = 0U ; } } success =
coderInputStreamReadBuffers ( obj -> StreamImpl , countToRead , numBuffers )
; if ( success == 0 ) { chImpl = coderStreamGetChannel ( obj -> StreamImpl )
; coderChannelHasSyncError ( chImpl , & hasSyncError ) ; if ( ! hasSyncError
) { coderChannelGetLastError ( chImpl , & errorID [ 0 ] , & errorText [ 0 ] )
; } else { coderChannelGetLastSyncError ( chImpl , & errorID [ 0 ] , &
errorText [ 0 ] ) ; } } * countRead = 0.0 ; outsize = ( int32_T ) numBuffers
- 1 ; pgkvysv3zg ( & packet , 2 ) ; for ( b_bufferIndex = 0 ; b_bufferIndex
<= outsize ; b_bufferIndex ++ ) { i = packet -> size [ 0 ] * packet -> size [
1 ] ; packet -> size [ 0 ] = 1 ; packet -> size [ 1 ] = packets -> data [
b_bufferIndex ] . f1 -> size [ 1 ] ; kcbbxsln5r ( packet , i ) ; success =
packets -> data [ b_bufferIndex ] . f1 -> size [ 1 ] ; for ( i = 0 ; i <
success ; i ++ ) { packet -> data [ i ] = packets -> data [ b_bufferIndex ] .
f1 -> data [ i ] ; } success = coderInputStreamReadBufferData ( obj ->
StreamImpl , b_bufferIndex + 1 , 1 , "" , "uint8" , packets -> data [
b_bufferIndex ] . f1 -> size [ 1 ] , & packet -> data [ 0 ] ) ; if ( success
== 0 ) { chImpl = coderStreamGetChannel ( obj -> StreamImpl ) ;
coderChannelHasSyncError ( chImpl , & hasSyncError ) ; if ( ! hasSyncError )
{ coderChannelGetLastError ( chImpl , & errorID [ 0 ] , & errorText [ 0 ] ) ;
} else { coderChannelGetLastSyncError ( chImpl , & errorID [ 0 ] , &
errorText [ 0 ] ) ; } } coderInputStreamFreeBuffer ( obj -> StreamImpl ,
b_bufferIndex + 1 ) ; i = packets -> data [ b_bufferIndex ] . f1 -> size [ 0
] * packets -> data [ b_bufferIndex ] . f1 -> size [ 1 ] ; packets -> data [
b_bufferIndex ] . f1 -> size [ 0 ] = 1 ; packets -> data [ b_bufferIndex ] .
f1 -> size [ 1 ] = packet -> size [ 1 ] ; kcbbxsln5r ( packets -> data [
b_bufferIndex ] . f1 , i ) ; success = packet -> size [ 1 ] ; for ( i = 0 ; i
< success ; i ++ ) { packets -> data [ b_bufferIndex ] . f1 -> data [ i ] =
packet -> data [ i ] ; } * countRead += bufferCounts [ b_bufferIndex ] ; }
dv5oz50wz1 ( & packet ) ; } static boolean_T aygswycpr4b ( const char_T
a_data [ ] , const int32_T a_size [ 2 ] ) { int32_T b_kstr ; char_T b [ 7 ] ;
boolean_T b_bool ; static const char_T tmp [ 7 ] = { 'i' , 'n' , 'v' , 'a' ,
'l' , 'i' , 'd' } ; static const char_T tmp_p [ 128 ] = { '\x00' , '\x01' ,
'\x02' , '\x03' , '\x04' , '\x05' , '\x06' , '\x07' , '\x08' , '\x09' ,
'\x0a' , '\x0b' , '\x0c' , '\x0d' , '\x0e' , '\x0f' , '\x10' , '\x11' ,
'\x12' , '\x13' , '\x14' , '\x15' , '\x16' , '\x17' , '\x18' , '\x19' ,
'\x1a' , '\x1b' , '\x1c' , '\x1d' , '\x1e' , '\x1f' , ' ' , '!' , '\"' , '#'
, '$' , '%' , '&' , '\'' , '(' , ')' , '*' , '+' , ',' , '-' , '.' , '/' ,
'0' , '1' , '2' , '3' , '4' , '5' , '6' , '7' , '8' , '9' , ':' , ';' , '<' ,
'=' , '>' , '?' , '@' , 'a' , 'b' , 'c' , 'd' , 'e' , 'f' , 'g' , 'h' , 'i' ,
'j' , 'k' , 'l' , 'm' , 'n' , 'o' , 'p' , 'q' , 'r' , 's' , 't' , 'u' , 'v' ,
'w' , 'x' , 'y' , 'z' , '[' , '\\' , ']' , '^' , '_' , '`' , 'a' , 'b' , 'c'
, 'd' , 'e' , 'f' , 'g' , 'h' , 'i' , 'j' , 'k' , 'l' , 'm' , 'n' , 'o' , 'p'
, 'q' , 'r' , 's' , 't' , 'u' , 'v' , 'w' , 'x' , 'y' , 'z' , '{' , '|' , '}'
, '~' , '\x7f' } ; int32_T exitg1 ; for ( b_kstr = 0 ; b_kstr < 7 ; b_kstr ++
) { b [ b_kstr ] = tmp [ b_kstr ] ; } b_bool = false ; if ( a_size [ 1 ] != 7
) { } else { b_kstr = 1 ; do { exitg1 = 0 ; if ( b_kstr - 1 < 7 ) { if (
tmp_p [ ( uint8_T ) a_data [ b_kstr - 1 ] & 127 ] != tmp_p [ ( int32_T ) b [
b_kstr - 1 ] ] ) { exitg1 = 1 ; } else { b_kstr ++ ; } } else { b_bool = true
; exitg1 = 1 ; } } while ( exitg1 == 0 ) ; } return b_bool ; } static
boolean_T aygswycpr4bq ( const char_T a_data [ ] , const int32_T a_size [ 2 ]
) { int32_T b_kstr ; char_T b [ 4 ] ; boolean_T b_bool ; static const char_T
tmp [ 128 ] = { '\x00' , '\x01' , '\x02' , '\x03' , '\x04' , '\x05' , '\x06'
, '\x07' , '\x08' , '\x09' , '\x0a' , '\x0b' , '\x0c' , '\x0d' , '\x0e' ,
'\x0f' , '\x10' , '\x11' , '\x12' , '\x13' , '\x14' , '\x15' , '\x16' ,
'\x17' , '\x18' , '\x19' , '\x1a' , '\x1b' , '\x1c' , '\x1d' , '\x1e' ,
'\x1f' , ' ' , '!' , '\"' , '#' , '$' , '%' , '&' , '\'' , '(' , ')' , '*' ,
'+' , ',' , '-' , '.' , '/' , '0' , '1' , '2' , '3' , '4' , '5' , '6' , '7' ,
'8' , '9' , ':' , ';' , '<' , '=' , '>' , '?' , '@' , 'a' , 'b' , 'c' , 'd' ,
'e' , 'f' , 'g' , 'h' , 'i' , 'j' , 'k' , 'l' , 'm' , 'n' , 'o' , 'p' , 'q' ,
'r' , 's' , 't' , 'u' , 'v' , 'w' , 'x' , 'y' , 'z' , '[' , '\\' , ']' , '^'
, '_' , '`' , 'a' , 'b' , 'c' , 'd' , 'e' , 'f' , 'g' , 'h' , 'i' , 'j' , 'k'
, 'l' , 'm' , 'n' , 'o' , 'p' , 'q' , 'r' , 's' , 't' , 'u' , 'v' , 'w' , 'x'
, 'y' , 'z' , '{' , '|' , '}' , '~' , '\x7f' } ; int32_T exitg1 ; b [ 0 ] =
'd' ; b [ 1 ] = 'o' ; b [ 2 ] = 'n' ; b [ 3 ] = 'e' ; b_bool = false ; if (
a_size [ 1 ] != 4 ) { } else { b_kstr = 1 ; do { exitg1 = 0 ; if ( b_kstr - 1
< 4 ) { if ( tmp [ ( uint8_T ) a_data [ b_kstr - 1 ] & 127 ] != tmp [ (
int32_T ) b [ b_kstr - 1 ] ] ) { exitg1 = 1 ; } else { b_kstr ++ ; } } else {
b_bool = true ; exitg1 = 1 ; } } while ( exitg1 == 0 ) ; } return b_bool ; }
static void ptoz3k2zwg ( jrxtexkjqq * * pEmxArray ) { int32_T i ; int32_T
numEl ; if ( * pEmxArray != ( jrxtexkjqq * ) NULL ) { if ( ( * pEmxArray ) ->
data != ( kkw0h0uzlf * ) NULL ) { numEl = 1 ; for ( i = 0 ; i < ( * pEmxArray
) -> numDimensions ; i ++ ) { numEl *= ( * pEmxArray ) -> size [ i ] ; } for
( i = 0 ; i < numEl ; i ++ ) { pciyoa0qmy ( & ( * pEmxArray ) -> data [ i ] )
; } if ( ( * pEmxArray ) -> canFreeData ) { free ( ( * pEmxArray ) -> data )
; } } free ( ( * pEmxArray ) -> size ) ; free ( * pEmxArray ) ; * pEmxArray =
( jrxtexkjqq * ) NULL ; } } static void fp42yixhj2 ( ax0y0tfz0l * obj ,
real_T countRequested , akean23d1n * data , real_T * countRead , char_T
err_data [ ] , int32_T err_size [ 2 ] ) { CoderChannel chImpl ; akean23d1n *
data_e ; akean23d1n * data_p ; akean23d1n * varargin_1 ; jrxtexkjqq * packets
; real_T count ; int32_T status_size [ 2 ] ; int32_T c ; int32_T exitg1 ;
int32_T iy ; int32_T success ; int32_T ysize_idx_0 ; int32_T ysize_idx_1 ;
char_T errorID [ 1024 ] ; char_T errorText [ 1024 ] ; char_T status_data [ 9
] ; boolean_T guard1 = false ; boolean_T guard11 = false ; boolean_T
hasSyncError ; iy = obj -> ExampleData -> size [ 0 ] * obj -> ExampleData ->
size [ 1 ] ; obj -> ExampleData -> size [ 0 ] = 1 ; obj -> ExampleData ->
size [ 1 ] = 1 ; kcbbxsln5r ( obj -> ExampleData , iy ) ; obj -> ExampleData
-> data [ 0 ] = 0U ; err_size [ 0 ] = 1 ; err_size [ 1 ] = 0 ; lage0maggu (
obj , countRequested , data , countRead ) ; if ( * countRead ==
countRequested ) { pgkvysv3zg ( & data_p , 2 ) ; iy = data_p -> size [ 0 ] *
data_p -> size [ 1 ] ; data_p -> size [ 0 ] = data -> size [ 0 ] ; data_p ->
size [ 1 ] = data -> size [ 1 ] ; kcbbxsln5r ( data_p , iy ) ; success = data
-> size [ 0 ] * data -> size [ 1 ] - 1 ; if ( success >= 0 ) { memcpy ( &
data_p -> data [ 0 ] , & data -> data [ 0 ] , ( uint32_T ) ( success + 1 ) *
sizeof ( uint8_T ) ) ; } d3nhfujrg53 ( data_p , ( real_T ) data -> size [ 1 ]
, data ) ; dv5oz50wz1 ( & data_p ) ; } else { fodfy3ik2d ( & packets , 2 ) ;
pgkvysv3zg ( & varargin_1 , 2 ) ; pgkvysv3zg ( & data_e , 2 ) ; guard1 =
false ; do { exitg1 = 0 ; if ( * countRead < countRequested ) { success =
coderStreamGetDataAvailable ( obj -> StreamImpl , & count ) ; if ( success ==
0 ) { chImpl = coderStreamGetChannel ( obj -> StreamImpl ) ;
coderChannelHasSyncError ( chImpl , & hasSyncError ) ; if ( ! hasSyncError )
{ coderChannelGetLastError ( chImpl , & errorID [ 0 ] , & errorText [ 0 ] ) ;
} else { coderChannelGetLastSyncError ( chImpl , & errorID [ 0 ] , &
errorText [ 0 ] ) ; } } guard11 = false ; if ( count == 0.0 ) { fpycd4xlib (
obj , status_data , status_size ) ; if ( ! aygswycpr4 ( status_data ,
status_size ) ) { err_size [ 0 ] = 1 ; err_size [ 1 ] = status_size [ 1 ] ;
iy = status_size [ 1 ] ; if ( iy - 1 >= 0 ) { memcpy ( & err_data [ 0 ] , &
status_data [ 0 ] , ( uint32_T ) iy * sizeof ( char_T ) ) ; } if (
aygswycpr4b ( status_data , status_size ) ) { data -> size [ 0 ] = 1 ; data
-> size [ 1 ] = 0 ; } else { if ( aygswycpr4bq ( status_data , status_size )
) { err_size [ 0 ] = 1 ; err_size [ 1 ] = 0 ; } guard1 = true ; } exitg1 = 1
; } else { guard11 = true ; } } else { guard11 = true ; } if ( guard11 ) {
lex4eakni1 ( obj , countRequested - * countRead , packets , & count ) ; c =
packets -> size [ 1 ] - 1 ; for ( success = 0 ; success <= c ; success ++ ) {
iy = varargin_1 -> size [ 0 ] * varargin_1 -> size [ 1 ] ; varargin_1 -> size
[ 0 ] = data -> size [ 0 ] ; varargin_1 -> size [ 1 ] = data -> size [ 1 ] ;
kcbbxsln5r ( varargin_1 , iy ) ; iy = data -> size [ 0 ] * data -> size [ 1 ]
; if ( iy - 1 >= 0 ) { memcpy ( & varargin_1 -> data [ 0 ] , & data -> data [
0 ] , ( uint32_T ) iy * sizeof ( uint8_T ) ) ; } ysize_idx_0 = data -> size [
0 ] ; ysize_idx_1 = data -> size [ 1 ] + packets -> data [ success ] . f1 ->
size [ 1 ] ; iy = data -> size [ 0 ] * data -> size [ 1 ] ; data -> size [ 0
] = varargin_1 -> size [ 0 ] ; data -> size [ 1 ] = varargin_1 -> size [ 1 ]
; kcbbxsln5r ( data , iy ) ; iy = varargin_1 -> size [ 0 ] * varargin_1 ->
size [ 1 ] ; if ( iy - 1 >= 0 ) { memcpy ( & data -> data [ 0 ] , &
varargin_1 -> data [ 0 ] , ( uint32_T ) iy * sizeof ( uint8_T ) ) ; } iy =
data -> size [ 0 ] * data -> size [ 1 ] ; data -> size [ 0 ] = ysize_idx_0 ;
data -> size [ 1 ] = ysize_idx_1 ; kcbbxsln5r ( data , iy ) ; iy = varargin_1
-> size [ 0 ] * varargin_1 -> size [ 1 ] ; ysize_idx_0 = packets -> data [
success ] . f1 -> size [ 1 ] ; for ( ysize_idx_1 = 0 ; ysize_idx_1 <
ysize_idx_0 ; ysize_idx_1 ++ ) { data -> data [ iy + ysize_idx_1 ] = packets
-> data [ success ] . f1 -> data [ ysize_idx_1 ] ; } } * countRead += count ;
guard1 = false ; } } else { guard1 = true ; exitg1 = 1 ; } } while ( exitg1
== 0 ) ; if ( guard1 ) { if ( * countRead > countRequested ) { d3nhfujrg5 (
data , countRequested + 1.0 , * countRead , obj -> PartialPacket ) ; obj ->
PartialPacketStart = 1.0 ; obj -> PartialPacketCount = obj -> PartialPacket
-> size [ 1 ] ; iy = data_e -> size [ 0 ] * data_e -> size [ 1 ] ; data_e ->
size [ 0 ] = data -> size [ 0 ] ; data_e -> size [ 1 ] = data -> size [ 1 ] ;
kcbbxsln5r ( data_e , iy ) ; success = data -> size [ 0 ] * data -> size [ 1
] - 1 ; if ( success >= 0 ) { memcpy ( & data_e -> data [ 0 ] , & data ->
data [ 0 ] , ( uint32_T ) ( success + 1 ) * sizeof ( uint8_T ) ) ; }
d3nhfujrg53 ( data_e , countRequested , data ) ; * countRead = countRequested
; } if ( err_size [ 1 ] != 0 ) { iy = obj -> PartialPacket -> size [ 0 ] *
obj -> PartialPacket -> size [ 1 ] ; obj -> PartialPacket -> size [ 0 ] =
data -> size [ 0 ] ; obj -> PartialPacket -> size [ 1 ] = data -> size [ 1 ]
; kcbbxsln5r ( obj -> PartialPacket , iy ) ; iy = data -> size [ 0 ] * data
-> size [ 1 ] ; for ( ysize_idx_1 = 0 ; ysize_idx_1 < iy ; ysize_idx_1 ++ ) {
obj -> PartialPacket -> data [ ysize_idx_1 ] = data -> data [ ysize_idx_1 ] ;
} obj -> PartialPacketStart = 1.0 ; obj -> PartialPacketCount = data -> size
[ 1 ] ; data -> size [ 0 ] = 1 ; data -> size [ 1 ] = 0 ; * countRead = 0.0 ;
} } dv5oz50wz1 ( & data_e ) ; dv5oz50wz1 ( & varargin_1 ) ; ptoz3k2zwg ( &
packets ) ; } } static void jyfcrkpivu ( f2zhfwyqun * pStruct ) { pgkvysv3zg
( & pStruct -> f1 , 2 ) ; } static void nyam2ysxlg ( f3xnlpfjxl * pEmxArray )
{ int32_T i ; for ( i = 0 ; i < 2 ; i ++ ) { pEmxArray -> size [ i ] = 0 ; }
} static void n1edmma3kh ( f2zhfwyqun * data , int32_T fromIndex , int32_T
toIndex ) { int32_T i ; for ( i = fromIndex ; i < toIndex ; i ++ ) {
jyfcrkpivu ( data ) ; } } static void fc5mtwhqzm ( f2zhfwyqun * pStruct ) {
dv5oz50wz1 ( & pStruct -> f1 ) ; } static void nltwq0frzf ( f2zhfwyqun * data
, int32_T fromIndex , int32_T toIndex ) { int32_T i ; for ( i = fromIndex ; i
< toIndex ; i ++ ) { fc5mtwhqzm ( data ) ; } } static void dormalfjas (
f2zhfwyqun * data , const int32_T size [ 2 ] , int32_T oldNumel ) { int32_T
newNumel ; if ( oldNumel < 0 ) { oldNumel = 0 ; } newNumel = size [ 0 ] *
size [ 1 ] ; if ( oldNumel > newNumel ) { nltwq0frzf ( data , newNumel ,
oldNumel ) ; } else if ( oldNumel < newNumel ) { n1edmma3kh ( data , oldNumel
, newNumel ) ; } } static void n53cyulecy ( akean23d1n * * dst , akean23d1n *
const * src ) { int32_T i ; int32_T numElDst ; int32_T numElSrc ; numElDst =
1 ; numElSrc = 1 ; for ( i = 0 ; i < ( * dst ) -> numDimensions ; i ++ ) {
numElDst *= ( * dst ) -> size [ i ] ; numElSrc *= ( * src ) -> size [ i ] ; }
for ( i = 0 ; i < ( * dst ) -> numDimensions ; i ++ ) { ( * dst ) -> size [ i
] = ( * src ) -> size [ i ] ; } kcbbxsln5r ( * dst , numElDst ) ; for ( i = 0
; i < numElSrc ; i ++ ) { ( * dst ) -> data [ i ] = ( * src ) -> data [ i ] ;
} } static void fvc3gzsemj ( f2zhfwyqun * dst , const f2zhfwyqun * src ) {
n53cyulecy ( & dst -> f1 , & src -> f1 ) ; } static void pjh3oqzupt (
ixviaac30n * pEmxArray ) { int32_T i ; for ( i = 0 ; i < 1 ; i ++ ) {
pEmxArray -> size = 0 ; } } static void lmz4rzqjqf ( f2zhfwyqun * data ,
const int32_T * size , int32_T oldNumel ) { int32_T newNumel ; if ( oldNumel
< 0 ) { oldNumel = 0 ; } newNumel = * size ; if ( oldNumel > newNumel ) {
nltwq0frzf ( data , newNumel , oldNumel ) ; } else if ( oldNumel < newNumel )
{ n1edmma3kh ( data , oldNumel , newNumel ) ; } } static void hiixlsiwmm (
ixviaac30n * pEmxArray ) { int32_T i ; int32_T numEl ; numEl = 1 ; for ( i =
0 ; i < 1 ; i ++ ) { numEl *= pEmxArray -> size ; } for ( i = 0 ; i < numEl ;
i ++ ) { fc5mtwhqzm ( & pEmxArray -> data ) ; } } static void halhyajxk0 (
f3xnlpfjxl * pEmxArray ) { int32_T i ; int32_T numEl ; numEl = 1 ; for ( i =
0 ; i < 2 ; i ++ ) { numEl *= pEmxArray -> size [ i ] ; } for ( i = 0 ; i <
numEl ; i ++ ) { fc5mtwhqzm ( & pEmxArray -> data ) ; } } static void
ixxwtfu0ne ( hscjo2zzvm * obj , const akean23d1n * data ) { CoderChannel
chImpl ; CoderOutputStream streamImpl ; coderTimespec b_timespec ;
coderTimespec b_timespec_p ; e4wb5cpnqg * obj_e ; e4wb5cpnqg * obj_p ;
f2zhfwyqun c ; f3xnlpfjxl b ; ixviaac30n c_p ; real_T countWritten ; real_T
countWrittenThisIteration ; real_T et ; real_T packetStartIndex ; real_T
startTic_tv_nsec ; real_T timeoutInSeconds ; int32_T countToWrite ; int32_T
loop_ub ; int32_T success ; char_T errorID [ 1024 ] ; char_T errorText [ 1024
] ; char_T status_data [ 9 ] ; boolean_T done ; boolean_T hasSyncError ;
boolean_T timeout ; static const char_T tmp [ 9 ] = { 'c' , 'o' , 'm' , 'p' ,
'l' , 'e' , 't' , 'e' , 'd' } ; static const char_T tmp_p [ 7 ] = { 't' , 'i'
, 'm' , 'e' , 'o' , 'u' , 't' } ; int32_T status_size [ 2 ] ; boolean_T
exitg1 ; boolean_T exitg2 ; boolean_T guard1 = false ; obj -> BytesPerElement
= 1.0 ; obj_p = & obj -> OutputStream ; countWritten = 0.0 ; countToWrite =
data -> size [ 1 ] ; jyfcrkpivu ( & c ) ; success = c . f1 -> size [ 0 ] * c
. f1 -> size [ 1 ] ; c . f1 -> size [ 0 ] = data -> size [ 0 ] ; c . f1 ->
size [ 1 ] = data -> size [ 1 ] ; kcbbxsln5r ( c . f1 , success ) ; loop_ub =
data -> size [ 0 ] * data -> size [ 1 ] ; for ( success = 0 ; success <
loop_ub ; success ++ ) { c . f1 -> data [ success ] = data -> data [ success
] ; } nyam2ysxlg ( & b ) ; success = b . size [ 0 ] * b . size [ 1 ] ; b .
size [ 0 ] = 1 ; b . size [ 1 ] = 1 ; dormalfjas ( & b . data , b . size ,
success ) ; fvc3gzsemj ( & b . data , & c ) ; fc5mtwhqzm ( & c ) ;
packetStartIndex = 1.0 ; pjh3oqzupt ( & c_p ) ; exitg1 = false ; while ( ( !
exitg1 ) && ( countWritten < countToWrite ) ) { streamImpl = obj_p ->
StreamImpl ; success = coderStreamGetSpaceAvailable ( streamImpl , & et ) ;
if ( success == 0 ) { chImpl = coderStreamGetChannel ( streamImpl ) ;
coderChannelHasSyncError ( chImpl , & hasSyncError ) ; if ( ! hasSyncError )
{ coderChannelGetLastError ( chImpl , & errorID [ 0 ] , & errorText [ 0 ] ) ;
} else { coderChannelGetLastSyncError ( chImpl , & errorID [ 0 ] , &
errorText [ 0 ] ) ; } } guard1 = false ; if ( et == 0.0 ) { obj_e = obj_p ;
timeoutInSeconds = obj_p -> Timeout ; status_size [ 0 ] = 1 ; status_size [ 1
] = 0 ; timeout = false ; done = false ; streamImpl = obj_p -> StreamImpl ;
success = coderStreamGetSpaceAvailable ( streamImpl , & et ) ; if ( success
== 0 ) { chImpl = coderStreamGetChannel ( streamImpl ) ;
coderChannelHasSyncError ( chImpl , & hasSyncError ) ; if ( ! hasSyncError )
{ coderChannelGetLastError ( chImpl , & errorID [ 0 ] , & errorText [ 0 ] ) ;
} else { coderChannelGetLastSyncError ( chImpl , & errorID [ 0 ] , &
errorText [ 0 ] ) ; } } hasSyncError = ( et > 0.0 ) ; idziggsqd5 ( &
countWrittenThisIteration , & startTic_tv_nsec ) ; while ( ( ! hasSyncError )
&& ( ! done ) && ( ! timeout ) ) { et = lwekp2pixw (
countWrittenThisIteration , startTic_tv_nsec ) ; if ( et < 1.0 ) {
b_timespec_p . tv_sec = 0.0 ; b_timespec_p . tv_nsec = 0.0 ; coderTimeSleep (
& b_timespec_p ) ; } else { b_timespec . tv_sec = 0.0 ; b_timespec . tv_nsec
= 5.0E+6 ; coderTimeSleep ( & b_timespec ) ; } et = lwekp2pixw (
countWrittenThisIteration , startTic_tv_nsec ) ; timeout = ( et >
timeoutInSeconds ) ; streamImpl = obj_e -> StreamImpl ; success =
coderStreamIsDeviceDone ( streamImpl , & done ) ; if ( success == 0 ) {
chImpl = coderStreamGetChannel ( streamImpl ) ; coderChannelHasSyncError (
chImpl , & hasSyncError ) ; if ( ! hasSyncError ) { coderChannelGetLastError
( chImpl , & errorID [ 0 ] , & errorText [ 0 ] ) ; } else {
coderChannelGetLastSyncError ( chImpl , & errorID [ 0 ] , & errorText [ 0 ] )
; } } if ( done ) { done = true ; } else { streamImpl = obj_e -> StreamImpl ;
success = coderStreamIsOpen ( streamImpl , & done ) ; if ( success == 0 ) {
chImpl = coderStreamGetChannel ( streamImpl ) ; coderChannelHasSyncError (
chImpl , & hasSyncError ) ; if ( ! hasSyncError ) { coderChannelGetLastError
( chImpl , & errorID [ 0 ] , & errorText [ 0 ] ) ; } else {
coderChannelGetLastSyncError ( chImpl , & errorID [ 0 ] , & errorText [ 0 ] )
; } } if ( ! done ) { done = true ; } else { done = false ; } } streamImpl =
obj_e -> StreamImpl ; success = coderStreamGetSpaceAvailable ( streamImpl , &
et ) ; if ( success == 0 ) { chImpl = coderStreamGetChannel ( streamImpl ) ;
coderChannelHasSyncError ( chImpl , & hasSyncError ) ; if ( ! hasSyncError )
{ coderChannelGetLastError ( chImpl , & errorID [ 0 ] , & errorText [ 0 ] ) ;
} else { coderChannelGetLastSyncError ( chImpl , & errorID [ 0 ] , &
errorText [ 0 ] ) ; } } hasSyncError = ( et > 0.0 ) ; } if ( hasSyncError ) {
status_size [ 0 ] = 1 ; status_size [ 1 ] = 9 ; for ( success = 0 ; success <
9 ; success ++ ) { status_data [ success ] = tmp [ success ] ; } } else if (
done ) { status_size [ 0 ] = 1 ; status_size [ 1 ] = 4 ; status_data [ 0 ] =
'd' ; status_data [ 1 ] = 'o' ; status_data [ 2 ] = 'n' ; status_data [ 3 ] =
'e' ; } else if ( timeout ) { status_size [ 0 ] = 1 ; status_size [ 1 ] = 7 ;
for ( success = 0 ; success < 7 ; success ++ ) { status_data [ success ] =
tmp_p [ success ] ; } } if ( ! aygswycpr4 ( status_data , status_size ) ) {
exitg1 = true ; } else { guard1 = true ; } } else { guard1 = true ; } if (
guard1 ) { et = 0.0 ; timeoutInSeconds = packetStartIndex ; loop_ub = 0 ;
exitg2 = false ; while ( ( ! exitg2 ) && ( loop_ub <= ( int32_T ) ( ( 1.0 -
packetStartIndex ) + 1.0 ) - 1 ) ) { success = c_p . size ; c_p . size = 1 ;
lmz4rzqjqf ( & c_p . data , & c_p . size , success ) ; fvc3gzsemj ( & c_p .
data , & b . data ) ; streamImpl = obj_p -> StreamImpl ; success =
coderOutputStreamWriteTypedDataOld ( streamImpl , & countWrittenThisIteration
, 1 , "uint8" , b . data . f1 -> size [ 0 ] * b . data . f1 -> size [ 1 ] , &
c_p . data . f1 -> data [ 0 ] ) ; if ( success == 0 ) { chImpl =
coderStreamGetChannel ( streamImpl ) ; coderChannelHasSyncError ( chImpl , &
hasSyncError ) ; if ( ! hasSyncError ) { coderChannelGetLastError ( chImpl ,
& errorID [ 0 ] , & errorText [ 0 ] ) ; } else { coderChannelGetLastSyncError
( chImpl , & errorID [ 0 ] , & errorText [ 0 ] ) ; } } if (
countWrittenThisIteration == 0.0 ) { exitg2 = true ; } else { et +=
countWrittenThisIteration ; timeoutInSeconds ++ ; loop_ub ++ ; } }
countWritten += et ; packetStartIndex = timeoutInSeconds ; } } hiixlsiwmm ( &
c_p ) ; halhyajxk0 ( & b ) ; countWritten = obj -> TotalElementsWritten + (
real_T ) data -> size [ 0 ] ; obj -> TotalElementsWritten = countWritten ; }
static void cop24uerxs ( const hscjo2zzvm * obj , real_T startIndex , real_T
endIndex , akean23d1n * result ) { int32_T e ; int32_T f ; int32_T i ;
int32_T loop_ub ; int32_T loop_ub_p ; if ( ( obj -> PartialPacket -> size [ 0
] == 1 ) || ( obj -> PartialPacket -> size [ 1 ] == 1 ) ) { if ( startIndex >
endIndex ) { f = 0 ; e = 0 ; } else { f = ( int32_T ) startIndex - 1 ; e = (
int32_T ) endIndex ; } i = result -> size [ 0 ] * result -> size [ 1 ] ;
result -> size [ 0 ] = 1 ; result -> size [ 1 ] = e - f ; kcbbxsln5r ( result
, i ) ; loop_ub = e - f ; for ( e = 0 ; e < loop_ub ; e ++ ) { result -> data
[ result -> size [ 0 ] * e ] = obj -> PartialPacket -> data [ f + e ] ; } }
else { if ( startIndex > endIndex ) { f = 0 ; e = 0 ; } else { f = ( int32_T
) startIndex - 1 ; e = ( int32_T ) endIndex ; } i = result -> size [ 0 ] *
result -> size [ 1 ] ; result -> size [ 0 ] = obj -> PartialPacket -> size [
0 ] ; result -> size [ 1 ] = e - f ; kcbbxsln5r ( result , i ) ; loop_ub = e
- f ; for ( e = 0 ; e < loop_ub ; e ++ ) { loop_ub_p = obj -> PartialPacket
-> size [ 0 ] ; for ( i = 0 ; i < loop_ub_p ; i ++ ) { result -> data [ i +
result -> size [ 0 ] * e ] = obj -> PartialPacket -> data [ ( f + e ) * obj
-> PartialPacket -> size [ 0 ] + i ] ; } } } } static void omichggouu (
hscjo2zzvm * obj , real_T numBytesToRead , akean23d1n * data ) { CoderChannel
chImpl ; CoderInputStream streamImpl ; akean23d1n * excessData ; akean23d1n *
x1 ; akean23d1n * x1_e ; akean23d1n * x1_p ; ax0y0tfz0l * obj_p ; jrxtexkjqq
* packets ; real_T count ; real_T ppc ; real_T pps ; real_T remainingCount ;
int32_T status_size [ 2 ] ; int32_T err_size_idx_1 ; int32_T exitg1 ; int32_T
iy ; int32_T obj_e ; int32_T success ; int32_T ysize_idx_0 ; int32_T
ysize_idx_1 ; char_T errorID [ 1024 ] ; char_T errorText [ 1024 ] ; char_T
status_data [ 9 ] ; boolean_T guard1 = false ; boolean_T guard11 = false ;
boolean_T hasSyncError ; if ( numBytesToRead == 0.0 ) { data -> size [ 0 ] =
0 ; data -> size [ 1 ] = 0 ; } else { ppc = obj -> PartialPacketCount ; if (
ppc > 0.0 ) { pps = obj -> PartialPacketStart ; if ( numBytesToRead < ppc ) {
cop24uerxs ( obj , pps , ( pps + numBytesToRead ) - 1.0 , data ) ;
remainingCount = numBytesToRead ; obj -> PartialPacketStart = pps +
numBytesToRead ; obj -> PartialPacketCount = ppc - numBytesToRead ; } else {
cop24uerxs ( obj , pps , ( pps + ppc ) - 1.0 , data ) ; remainingCount = ppc
; obj -> PartialPacket -> size [ 0 ] = 1 ; obj -> PartialPacket -> size [ 1 ]
= 0 ; obj -> PartialPacket -> size [ 0 ] = 0 ; obj -> PartialPacket -> size [
1 ] = 0 ; obj -> PartialPacketStart = 0.0 ; obj -> PartialPacketCount = 0.0 ;
} } else { data -> size [ 0 ] = 0 ; data -> size [ 1 ] = 0 ; remainingCount =
0.0 ; } remainingCount = numBytesToRead - remainingCount ; if (
remainingCount > 0.0 ) { streamImpl = obj -> InputStream . StreamImpl ;
success = coderStreamGetDataAvailable ( streamImpl , & ppc ) ; if ( success
== 0 ) { chImpl = coderStreamGetChannel ( streamImpl ) ;
coderChannelHasSyncError ( chImpl , & hasSyncError ) ; if ( ! hasSyncError )
{ coderChannelGetLastError ( chImpl , & errorID [ 0 ] , & errorText [ 0 ] ) ;
} else { coderChannelGetLastSyncError ( chImpl , & errorID [ 0 ] , &
errorText [ 0 ] ) ; } } streamImpl = obj -> InputStream . StreamImpl ;
success = coderStreamGetDataAvailable ( streamImpl , & ppc ) ; if ( success
== 0 ) { chImpl = coderStreamGetChannel ( streamImpl ) ;
coderChannelHasSyncError ( chImpl , & hasSyncError ) ; if ( ! hasSyncError )
{ coderChannelGetLastError ( chImpl , & errorID [ 0 ] , & errorText [ 0 ] ) ;
} else { coderChannelGetLastSyncError ( chImpl , & errorID [ 0 ] , &
errorText [ 0 ] ) ; } } ppc += obj -> InputStream . PartialPacketCount ;
obj_p = & obj -> InputStream ; iy = obj -> InputStream . ExampleData -> size
[ 0 ] * obj -> InputStream . ExampleData -> size [ 1 ] ; obj -> InputStream .
ExampleData -> size [ 0 ] = 1 ; obj -> InputStream . ExampleData -> size [ 1
] = 1 ; kcbbxsln5r ( obj -> InputStream . ExampleData , iy ) ; obj ->
InputStream . ExampleData -> data [ 0 ] = 0U ; err_size_idx_1 = 0 ;
pgkvysv3zg ( & x1 , 2 ) ; lage0maggu ( & obj -> InputStream , ppc , x1 , &
pps ) ; if ( pps == ppc ) { pgkvysv3zg ( & x1_p , 2 ) ; iy = x1_p -> size [ 0
] * x1_p -> size [ 1 ] ; x1_p -> size [ 0 ] = x1 -> size [ 0 ] ; x1_p -> size
[ 1 ] = x1 -> size [ 1 ] ; kcbbxsln5r ( x1_p , iy ) ; success = x1 -> size [
0 ] * x1 -> size [ 1 ] - 1 ; if ( success >= 0 ) { memcpy ( & x1_p -> data [
0 ] , & x1 -> data [ 0 ] , ( uint32_T ) ( success + 1 ) * sizeof ( uint8_T )
) ; } d3nhfujrg53 ( x1_p , ( real_T ) x1 -> size [ 1 ] , x1 ) ; dv5oz50wz1 (
& x1_p ) ; } else { pgkvysv3zg ( & excessData , 2 ) ; fodfy3ik2d ( & packets
, 2 ) ; pgkvysv3zg ( & x1_e , 2 ) ; guard1 = false ; do { exitg1 = 0 ; if (
pps < ppc ) { streamImpl = obj_p -> StreamImpl ; success =
coderStreamGetDataAvailable ( streamImpl , & count ) ; if ( success == 0 ) {
chImpl = coderStreamGetChannel ( streamImpl ) ; coderChannelHasSyncError (
chImpl , & hasSyncError ) ; if ( ! hasSyncError ) { coderChannelGetLastError
( chImpl , & errorID [ 0 ] , & errorText [ 0 ] ) ; } else {
coderChannelGetLastSyncError ( chImpl , & errorID [ 0 ] , & errorText [ 0 ] )
; } } guard11 = false ; if ( count == 0.0 ) { fpycd4xlib ( obj_p ,
status_data , status_size ) ; if ( ! aygswycpr4 ( status_data , status_size )
) { err_size_idx_1 = status_size [ 1 ] ; if ( aygswycpr4b ( status_data ,
status_size ) ) { x1 -> size [ 0 ] = 1 ; x1 -> size [ 1 ] = 0 ; } else { if (
aygswycpr4bq ( status_data , status_size ) ) { err_size_idx_1 = 0 ; } guard1
= true ; } exitg1 = 1 ; } else { guard11 = true ; } } else { guard11 = true ;
} if ( guard11 ) { lex4eakni1 ( obj_p , ppc - pps , packets , & count ) ;
obj_e = packets -> size [ 1 ] - 1 ; for ( success = 0 ; success <= obj_e ;
success ++ ) { iy = excessData -> size [ 0 ] * excessData -> size [ 1 ] ;
excessData -> size [ 0 ] = x1 -> size [ 0 ] ; excessData -> size [ 1 ] = x1
-> size [ 1 ] ; kcbbxsln5r ( excessData , iy ) ; iy = x1 -> size [ 0 ] * x1
-> size [ 1 ] ; if ( iy - 1 >= 0 ) { memcpy ( & excessData -> data [ 0 ] , &
x1 -> data [ 0 ] , ( uint32_T ) iy * sizeof ( uint8_T ) ) ; } ysize_idx_0 =
x1 -> size [ 0 ] ; ysize_idx_1 = x1 -> size [ 1 ] + packets -> data [ success
] . f1 -> size [ 1 ] ; iy = x1 -> size [ 0 ] * x1 -> size [ 1 ] ; x1 -> size
[ 0 ] = excessData -> size [ 0 ] ; x1 -> size [ 1 ] = excessData -> size [ 1
] ; kcbbxsln5r ( x1 , iy ) ; iy = excessData -> size [ 0 ] * excessData ->
size [ 1 ] ; if ( iy - 1 >= 0 ) { memcpy ( & x1 -> data [ 0 ] , & excessData
-> data [ 0 ] , ( uint32_T ) iy * sizeof ( uint8_T ) ) ; } iy = x1 -> size [
0 ] * x1 -> size [ 1 ] ; x1 -> size [ 0 ] = ysize_idx_0 ; x1 -> size [ 1 ] =
ysize_idx_1 ; kcbbxsln5r ( x1 , iy ) ; iy = excessData -> size [ 0 ] *
excessData -> size [ 1 ] ; ysize_idx_0 = packets -> data [ success ] . f1 ->
size [ 1 ] ; for ( ysize_idx_1 = 0 ; ysize_idx_1 < ysize_idx_0 ; ysize_idx_1
++ ) { x1 -> data [ iy + ysize_idx_1 ] = packets -> data [ success ] . f1 ->
data [ ysize_idx_1 ] ; } } pps += count ; guard1 = false ; } } else { guard1
= true ; exitg1 = 1 ; } } while ( exitg1 == 0 ) ; if ( guard1 ) { if ( pps >
ppc ) { d3nhfujrg5 ( x1 , ppc + 1.0 , pps , excessData ) ; iy = obj_p ->
PartialPacket -> size [ 0 ] * obj_p -> PartialPacket -> size [ 1 ] ; obj_p ->
PartialPacket -> size [ 0 ] = excessData -> size [ 0 ] ; obj_p ->
PartialPacket -> size [ 1 ] = excessData -> size [ 1 ] ; kcbbxsln5r ( obj_p
-> PartialPacket , iy ) ; iy = excessData -> size [ 0 ] * excessData -> size
[ 1 ] ; for ( ysize_idx_1 = 0 ; ysize_idx_1 < iy ; ysize_idx_1 ++ ) { obj_p
-> PartialPacket -> data [ ysize_idx_1 ] = excessData -> data [ ysize_idx_1 ]
; } obj_p -> PartialPacketStart = 1.0 ; obj_p -> PartialPacketCount =
excessData -> size [ 1 ] ; iy = x1_e -> size [ 0 ] * x1_e -> size [ 1 ] ;
x1_e -> size [ 0 ] = x1 -> size [ 0 ] ; x1_e -> size [ 1 ] = x1 -> size [ 1 ]
; kcbbxsln5r ( x1_e , iy ) ; success = x1 -> size [ 0 ] * x1 -> size [ 1 ] -
1 ; if ( success >= 0 ) { memcpy ( & x1_e -> data [ 0 ] , & x1 -> data [ 0 ]
, ( uint32_T ) ( success + 1 ) * sizeof ( uint8_T ) ) ; } d3nhfujrg53 ( x1_e
, ppc , x1 ) ; } if ( err_size_idx_1 != 0 ) { iy = obj_p -> PartialPacket ->
size [ 0 ] * obj_p -> PartialPacket -> size [ 1 ] ; obj_p -> PartialPacket ->
size [ 0 ] = x1 -> size [ 0 ] ; obj_p -> PartialPacket -> size [ 1 ] = x1 ->
size [ 1 ] ; kcbbxsln5r ( obj_p -> PartialPacket , iy ) ; iy = x1 -> size [ 0
] * x1 -> size [ 1 ] ; for ( ysize_idx_1 = 0 ; ysize_idx_1 < iy ; ysize_idx_1
++ ) { obj_p -> PartialPacket -> data [ ysize_idx_1 ] = x1 -> data [
ysize_idx_1 ] ; } obj_p -> PartialPacketStart = 1.0 ; obj_p ->
PartialPacketCount = x1 -> size [ 1 ] ; x1 -> size [ 0 ] = 1 ; x1 -> size [ 1
] = 0 ; } } dv5oz50wz1 ( & x1_e ) ; ptoz3k2zwg ( & packets ) ; dv5oz50wz1 ( &
excessData ) ; } if ( remainingCount < x1 -> size [ 1 ] ) { iy = obj ->
PartialPacket -> size [ 0 ] * obj -> PartialPacket -> size [ 1 ] ; obj ->
PartialPacket -> size [ 0 ] = 1 ; obj -> PartialPacket -> size [ 1 ] = 0 ;
obj -> PartialPacket -> size [ 0 ] = x1 -> size [ 0 ] ; obj -> PartialPacket
-> size [ 1 ] = x1 -> size [ 1 ] ; kcbbxsln5r ( obj -> PartialPacket , iy ) ;
iy = x1 -> size [ 0 ] * x1 -> size [ 1 ] ; for ( ysize_idx_1 = 0 ;
ysize_idx_1 < iy ; ysize_idx_1 ++ ) { obj -> PartialPacket -> data [
ysize_idx_1 ] = x1 -> data [ ysize_idx_1 ] ; } obj -> PartialPacketStart =
1.0 ; obj -> PartialPacketCount = x1 -> size [ 1 ] ; ppc = obj ->
PartialPacketCount ; if ( ppc > 0.0 ) { pps = obj -> PartialPacketStart ; if
( remainingCount < ppc ) { cop24uerxs ( obj , pps , ( pps + remainingCount )
- 1.0 , x1 ) ; obj -> PartialPacketStart = pps + remainingCount ; obj ->
PartialPacketCount = ppc - remainingCount ; } else { cop24uerxs ( obj , pps ,
( pps + ppc ) - 1.0 , x1 ) ; obj -> PartialPacket -> size [ 0 ] = 1 ; obj ->
PartialPacket -> size [ 1 ] = 0 ; obj -> PartialPacket -> size [ 0 ] = 0 ;
obj -> PartialPacket -> size [ 1 ] = 0 ; obj -> PartialPacketStart = 0.0 ;
obj -> PartialPacketCount = 0.0 ; } } else { x1 -> size [ 0 ] = 0 ; x1 ->
size [ 1 ] = 0 ; } if ( ( data -> size [ 0 ] != 0 ) && ( data -> size [ 1 ]
!= 0 ) ) { success = data -> size [ 0 ] ; } else if ( ( x1 -> size [ 0 ] != 0
) && ( x1 -> size [ 1 ] != 0 ) ) { success = x1 -> size [ 0 ] ; } else {
success = data -> size [ 0 ] ; ysize_idx_1 = x1 -> size [ 0 ] ; success =
muIntScalarMax_sint32 ( ysize_idx_1 , success ) ; } hasSyncError = ( success
== 0 ) ; if ( hasSyncError || ( ( data -> size [ 0 ] != 0 ) && ( data -> size
[ 1 ] != 0 ) ) ) { ysize_idx_1 = data -> size [ 1 ] ; } else { ysize_idx_1 =
0 ; } if ( hasSyncError || ( ( x1 -> size [ 0 ] != 0 ) && ( x1 -> size [ 1 ]
!= 0 ) ) ) { obj_e = x1 -> size [ 1 ] ; } else { obj_e = 0 ; } iy = data ->
size [ 0 ] * data -> size [ 1 ] ; data -> size [ 0 ] = success ; data -> size
[ 1 ] = ysize_idx_1 + obj_e ; kcbbxsln5r ( data , iy ) ; iy = success *
ysize_idx_1 ; obj_e *= success ; for ( ysize_idx_1 = 0 ; ysize_idx_1 < obj_e
; ysize_idx_1 ++ ) { data -> data [ ysize_idx_1 + iy ] = x1 -> data [
ysize_idx_1 ] ; } } else { if ( ( data -> size [ 0 ] != 0 ) && ( data -> size
[ 1 ] != 0 ) ) { success = data -> size [ 0 ] ; } else if ( ( x1 -> size [ 0
] != 0 ) && ( x1 -> size [ 1 ] != 0 ) ) { success = x1 -> size [ 0 ] ; } else
{ success = data -> size [ 0 ] ; ysize_idx_1 = x1 -> size [ 0 ] ; success =
muIntScalarMax_sint32 ( ysize_idx_1 , success ) ; } hasSyncError = ( success
== 0 ) ; if ( hasSyncError || ( ( data -> size [ 0 ] != 0 ) && ( data -> size
[ 1 ] != 0 ) ) ) { ysize_idx_1 = data -> size [ 1 ] ; } else { ysize_idx_1 =
0 ; } if ( hasSyncError || ( ( x1 -> size [ 0 ] != 0 ) && ( x1 -> size [ 1 ]
!= 0 ) ) ) { obj_e = x1 -> size [ 1 ] ; } else { obj_e = 0 ; } iy = data ->
size [ 0 ] * data -> size [ 1 ] ; data -> size [ 0 ] = success ; data -> size
[ 1 ] = ysize_idx_1 + obj_e ; kcbbxsln5r ( data , iy ) ; iy = success *
ysize_idx_1 ; obj_e *= success ; for ( ysize_idx_1 = 0 ; ysize_idx_1 < obj_e
; ysize_idx_1 ++ ) { data -> data [ ysize_idx_1 + iy ] = x1 -> data [
ysize_idx_1 ] ; } } dv5oz50wz1 ( & x1 ) ; } } } static void kphoq4rcnq (
g1hz5apriq * obj , real_T numToRead , akean23d1n * data ) { real_T value ;
value = guurnuuuj0 ( & obj -> UnreadDataBuffer ) ; if ( numToRead > value ) {
value = guurnuuuj0 ( & obj -> UnreadDataBuffer ) ; if ( value != 0.0 ) {
value = guurnuuuj0 ( & obj -> UnreadDataBuffer ) ; if ( value == 0.0 ) { data
-> size [ 0 ] = 0 ; data -> size [ 1 ] = 0 ; } else { omichggouu ( & obj ->
UnreadDataBuffer , value * obj -> UnreadDataBuffer . BytesPerElement , data )
; } } else { data -> size [ 0 ] = 0 ; data -> size [ 1 ] = 0 ; } } else {
value = guurnuuuj0 ( & obj -> UnreadDataBuffer ) ; value = muDoubleScalarMin
( numToRead , value ) ; if ( value == 0.0 ) { data -> size [ 0 ] = 0 ; data
-> size [ 1 ] = 0 ; } else { omichggouu ( & obj -> UnreadDataBuffer , value *
obj -> UnreadDataBuffer . BytesPerElement , data ) ; } } } static void
ncc2f0srjcu0 ( const kwgo0x2v41z * obj ) { int32_T success ; char_T errorID [
1024 ] ; char_T errorText [ 1024 ] ; boolean_T hasSyncError ; boolean_T
result ; success = coderChannelIsOpen ( obj -> ChannelImpl , & result ) ; if
( success == 0 ) { coderChannelHasSyncError ( obj -> ChannelImpl , &
hasSyncError ) ; if ( ! hasSyncError ) { coderChannelGetLastError ( obj ->
ChannelImpl , & errorID [ 0 ] , & errorText [ 0 ] ) ; } else {
coderChannelGetLastSyncError ( obj -> ChannelImpl , & errorID [ 0 ] , &
errorText [ 0 ] ) ; } } if ( result ) { success = coderChannelClose ( obj ->
ChannelImpl ) ; if ( success == 0 ) { coderChannelHasSyncError ( obj ->
ChannelImpl , & hasSyncError ) ; if ( ! hasSyncError ) {
coderChannelGetLastError ( obj -> ChannelImpl , & errorID [ 0 ] , & errorText
[ 0 ] ) ; } else { coderChannelGetLastSyncError ( obj -> ChannelImpl , &
errorID [ 0 ] , & errorText [ 0 ] ) ; } } } } static void ncc2f0srjcu0z (
const hscjo2zzvmb * obj ) { CoderChannel chImpl ; int32_T success ; char_T
errorID [ 1024 ] ; char_T errorText [ 1024 ] ; boolean_T hasSyncError ;
boolean_T result ; success = coderChannelIsOpen ( obj -> ChannelImpl , &
result ) ; if ( success == 0 ) { coderChannelHasSyncError ( obj ->
ChannelImpl , & hasSyncError ) ; if ( ! hasSyncError ) {
coderChannelGetLastError ( obj -> ChannelImpl , & errorID [ 0 ] , & errorText
[ 0 ] ) ; } else { coderChannelGetLastSyncError ( obj -> ChannelImpl , &
errorID [ 0 ] , & errorText [ 0 ] ) ; } } if ( result ) { success =
coderChannelClose ( obj -> ChannelImpl ) ; if ( success == 0 ) {
coderChannelHasSyncError ( obj -> ChannelImpl , & hasSyncError ) ; if ( !
hasSyncError ) { coderChannelGetLastError ( obj -> ChannelImpl , & errorID [
0 ] , & errorText [ 0 ] ) ; } else { coderChannelGetLastSyncError ( obj ->
ChannelImpl , & errorID [ 0 ] , & errorText [ 0 ] ) ; } } success =
coderStreamFlush ( obj -> InputStream . StreamImpl ) ; if ( success == 0 ) {
chImpl = coderStreamGetChannel ( obj -> InputStream . StreamImpl ) ;
coderChannelHasSyncError ( chImpl , & hasSyncError ) ; if ( ! hasSyncError )
{ coderChannelGetLastError ( chImpl , & errorID [ 0 ] , & errorText [ 0 ] ) ;
} else { coderChannelGetLastSyncError ( chImpl , & errorID [ 0 ] , &
errorText [ 0 ] ) ; } } success = coderStreamFlush ( obj -> OutputStream .
StreamImpl ) ; if ( success == 0 ) { chImpl = coderStreamGetChannel ( obj ->
OutputStream . StreamImpl ) ; coderChannelHasSyncError ( chImpl , &
hasSyncError ) ; if ( ! hasSyncError ) { coderChannelGetLastError ( chImpl ,
& errorID [ 0 ] , & errorText [ 0 ] ) ; } else { coderChannelGetLastSyncError
( chImpl , & errorID [ 0 ] , & errorText [ 0 ] ) ; } } } } static void
jebmsvss5a ( ax0y0tfz0lj * pStruct ) { dv5oz50wz1 ( & pStruct -> ExampleData
) ; } static void ksxjvd1rwm ( hscjo2zzvmb * pStruct ) { jebmsvss5a ( &
pStruct -> InputStream ) ; } static void hkbnv3dtnw ( g1hz5apriqr * pStruct )
{ ksxjvd1rwm ( & pStruct -> UnreadDataBuffer ) ; lioe0t4jfb ( & pStruct ->
ByteOrder ) ; } static void ksxjvd1rwmo ( kwgo0x2v41z * pStruct ) {
jebmsvss5a ( & pStruct -> InputStream ) ; } static void lpykouywvt (
ovagoamv4wz * pStruct ) { hkbnv3dtnw ( & pStruct -> _pobj0 ) ; ksxjvd1rwmo (
& pStruct -> _pobj1 ) ; } static void kwd3nombnh ( gvzvlbrjok * pStruct ) {
lpykouywvt ( & pStruct -> TCPIPObj ) ; } static void ncc2f0srjc ( const
kwgo0x2v41 * obj ) { int32_T success ; char_T errorID [ 1024 ] ; char_T
errorText [ 1024 ] ; boolean_T hasSyncError ; boolean_T result ; success =
coderChannelIsOpen ( obj -> ChannelImpl , & result ) ; if ( success == 0 ) {
coderChannelHasSyncError ( obj -> ChannelImpl , & hasSyncError ) ; if ( !
hasSyncError ) { coderChannelGetLastError ( obj -> ChannelImpl , & errorID [
0 ] , & errorText [ 0 ] ) ; } else { coderChannelGetLastSyncError ( obj ->
ChannelImpl , & errorID [ 0 ] , & errorText [ 0 ] ) ; } } if ( result ) {
success = coderChannelClose ( obj -> ChannelImpl ) ; if ( success == 0 ) {
coderChannelHasSyncError ( obj -> ChannelImpl , & hasSyncError ) ; if ( !
hasSyncError ) { coderChannelGetLastError ( obj -> ChannelImpl , & errorID [
0 ] , & errorText [ 0 ] ) ; } else { coderChannelGetLastSyncError ( obj ->
ChannelImpl , & errorID [ 0 ] , & errorText [ 0 ] ) ; } } } } static void
ncc2f0srjcu ( hscjo2zzvm * obj ) { CoderChannel chImpl ; int32_T success ;
char_T errorID [ 1024 ] ; char_T errorText [ 1024 ] ; boolean_T hasSyncError
; boolean_T result ; success = coderChannelIsOpen ( obj -> ChannelImpl , &
result ) ; if ( success == 0 ) { coderChannelHasSyncError ( obj ->
ChannelImpl , & hasSyncError ) ; if ( ! hasSyncError ) {
coderChannelGetLastError ( obj -> ChannelImpl , & errorID [ 0 ] , & errorText
[ 0 ] ) ; } else { coderChannelGetLastSyncError ( obj -> ChannelImpl , &
errorID [ 0 ] , & errorText [ 0 ] ) ; } } if ( result ) { success =
coderChannelClose ( obj -> ChannelImpl ) ; if ( success == 0 ) {
coderChannelHasSyncError ( obj -> ChannelImpl , & hasSyncError ) ; if ( !
hasSyncError ) { coderChannelGetLastError ( obj -> ChannelImpl , & errorID [
0 ] , & errorText [ 0 ] ) ; } else { coderChannelGetLastSyncError ( obj ->
ChannelImpl , & errorID [ 0 ] , & errorText [ 0 ] ) ; } } obj ->
TotalElementsWritten = 0.0 ; obj -> InputStream . PartialPacket -> size [ 0 ]
= obj -> InputStream . ExampleData -> size [ 0 ] ; obj -> InputStream .
PartialPacket -> size [ 1 ] = 0 ; obj -> InputStream . PartialPacket -> size
[ 1 ] = 0 ; obj -> InputStream . PartialPacketStart = 0.0 ; obj ->
InputStream . PartialPacketCount = 0.0 ; success = coderStreamFlush ( obj ->
InputStream . StreamImpl ) ; if ( success == 0 ) { chImpl =
coderStreamGetChannel ( obj -> InputStream . StreamImpl ) ;
coderChannelHasSyncError ( chImpl , & hasSyncError ) ; if ( ! hasSyncError )
{ coderChannelGetLastError ( chImpl , & errorID [ 0 ] , & errorText [ 0 ] ) ;
} else { coderChannelGetLastSyncError ( chImpl , & errorID [ 0 ] , &
errorText [ 0 ] ) ; } } obj -> PartialPacket -> size [ 0 ] = 1 ; obj ->
PartialPacket -> size [ 1 ] = 0 ; obj -> PartialPacket -> size [ 0 ] = 0 ;
obj -> PartialPacket -> size [ 1 ] = 0 ; obj -> PartialPacketStart = 0.0 ;
obj -> PartialPacketCount = 0.0 ; success = coderStreamFlush ( obj ->
OutputStream . StreamImpl ) ; if ( success == 0 ) { chImpl =
coderStreamGetChannel ( obj -> OutputStream . StreamImpl ) ;
coderChannelHasSyncError ( chImpl , & hasSyncError ) ; if ( ! hasSyncError )
{ coderChannelGetLastError ( chImpl , & errorID [ 0 ] , & errorText [ 0 ] ) ;
} else { coderChannelGetLastSyncError ( chImpl , & errorID [ 0 ] , &
errorText [ 0 ] ) ; } } } } static void jebmsvss5aw ( ax0y0tfz0l * pStruct )
{ dv5oz50wz1 ( & pStruct -> PartialPacket ) ; dv5oz50wz1 ( & pStruct ->
ExampleData ) ; } static void ksxjvd1rwmoz ( hscjo2zzvm * pStruct ) {
jebmsvss5aw ( & pStruct -> InputStream ) ; dv5oz50wz1 ( & pStruct ->
PartialPacket ) ; } static void hkbnv3dtnwv ( g1hz5apriq * pStruct ) {
ksxjvd1rwmoz ( & pStruct -> UnreadDataBuffer ) ; lioe0t4jfb ( & pStruct ->
ByteOrder ) ; lioe0t4jfb ( & pStruct -> NativeDataType ) ; lioe0t4jfb ( &
pStruct -> DataFieldName ) ; } static void ksxjvd1rwmozh ( kwgo0x2v41 *
pStruct ) { jebmsvss5aw ( & pStruct -> InputStream ) ; } static void
lpykouywvt3 ( ovagoamv4w * pStruct ) { hkbnv3dtnwv ( & pStruct -> _pobj0 ) ;
ksxjvd1rwmozh ( & pStruct -> _pobj1 ) ; } static void kwd3nombnhc (
dp0kdzdsab * pStruct ) { lpykouywvt3 ( & pStruct -> TCPIPObj ) ; } void
MdlInitialize ( void ) { real_T tmp ; int32_T r ; int32_T t ; uint32_T tseed
; rtX . eypdcundes = rtP . Integrator1_IC ; rtDW . jl0mnuibbh = rtP .
Output_InitialCondition ; rtX . lh2zlfy5gs = rtP . Integrator_IC ; rtX .
o2miuctf5t = rtP . Integrator1_IC_aul1jddy20 ; rtDW . l30tmqcnmm = ( rtInf )
; rtDW . iv3sxafqgs = ( rtInf ) ; rtDW . egmxveifc2 = ( rtInf ) ; rtDW .
jrcajuutzs = ( rtInf ) ; rtDW . l4a3zwvtji = ( rtInf ) ; rtDW . evnfi3oakh =
( rtInf ) ; rtDW . ajtguqv0em = ( rtInf ) ; rtDW . omefgf0cmg = ( rtInf ) ;
rtDW . leiplki144 = ( rtInf ) ; rtDW . oujf1dobik = ( rtInf ) ; rtDW .
cbkkysibro = ( rtInf ) ; rtDW . e33if4mgu4 = ( rtInf ) ; rtX . g1kxrlwt1c =
rtP . Integrator3_IC ; rtX . m0ift0f3ns = rtP . Integrator2_IC ; rtX .
lq2uwsqwxu = rtP . Integrator_IC_edh1bx55d3 ; tmp = muDoubleScalarFloor ( rtP
. BandLimitedWhiteNoise1_seed ) ; if ( muDoubleScalarIsNaN ( tmp ) ||
muDoubleScalarIsInf ( tmp ) ) { tmp = 0.0 ; } else { tmp = muDoubleScalarRem
( tmp , 4.294967296E+9 ) ; } tseed = tmp < 0.0 ? ( uint32_T ) - ( int32_T ) (
uint32_T ) - tmp : ( uint32_T ) tmp ; r = ( int32_T ) ( tseed >> 16U ) ; t =
( int32_T ) ( tseed & 32768U ) ; tseed = ( ( ( ( tseed - ( ( uint32_T ) r <<
16U ) ) + ( uint32_T ) t ) << 16U ) + ( uint32_T ) t ) + ( uint32_T ) r ; if
( tseed < 1U ) { tseed = 1144108930U ; } else if ( tseed > 2147483646U ) {
tseed = 2147483646U ; } rtDW . baqauvm4f0 = tseed ; rtDW . jsetdp311j =
rt_nrand_Upu32_Yd_f_pw_snf ( & rtDW . baqauvm4f0 ) * rtP . WhiteNoise_StdDev
+ rtP . WhiteNoise_Mean ; rtX . fl2s00rq4n = rtP . Integrator1_IC_p55ptnmnhu
; rtX . cb0w3bhvxx = rtP . Integrator_IC_ltzbm21qdw ; rtDW . ha3ig5blsd = (
rtInf ) ; rtDW . pv2wfqzep2 = ( rtInf ) ; rtDW . ohxmf4okd1 = ( rtInf ) ;
rtDW . ovo4hnxxnn = ( rtInf ) ; rtDW . lkqen1tuni = ( rtInf ) ; rtDW .
hiojixic5x = ( rtInf ) ; rtDW . mutemtyha2 = ( rtInf ) ; rtDW . frxhgtfui5 =
( rtInf ) ; rtDW . fl21cmk5gk = ( rtInf ) ; rtDW . juomdslsik = ( rtInf ) ;
rtDW . e0edvudjse = ( rtInf ) ; rtDW . e13leb2tmm = ( rtInf ) ; tmp =
muDoubleScalarFloor ( rtP . BandLimitedWhiteNoise_seed ) ; if (
muDoubleScalarIsNaN ( tmp ) || muDoubleScalarIsInf ( tmp ) ) { tmp = 0.0 ; }
else { tmp = muDoubleScalarRem ( tmp , 4.294967296E+9 ) ; } tseed = tmp < 0.0
? ( uint32_T ) - ( int32_T ) ( uint32_T ) - tmp : ( uint32_T ) tmp ; r = (
int32_T ) ( tseed >> 16U ) ; t = ( int32_T ) ( tseed & 32768U ) ; tseed = ( (
( ( tseed - ( ( uint32_T ) r << 16U ) ) + ( uint32_T ) t ) << 16U ) + (
uint32_T ) t ) + ( uint32_T ) r ; if ( tseed < 1U ) { tseed = 1144108930U ; }
else if ( tseed > 2147483646U ) { tseed = 2147483646U ; } rtDW . eam5on10cp =
tseed ; rtDW . mkxeuv2wc4 = rt_nrand_Upu32_Yd_f_pw_snf ( & rtDW . eam5on10cp
) * rtP . WhiteNoise_StdDev_iarpuhegie + rtP . WhiteNoise_Mean_cm2ydxtnvw ;
rtDW . dzzfid2chy = 0.0 ; rtDW . gvaglrbdot = true ; rtDW . ottvoj0yqy = true
; rtDW . dhockh40iz = true ; rtDW . cosaluxqrd = true ; rtDW . iz0phm120z =
0.0 ; rtDW . ehbdlfy2zi = true ; rtDW . hkguujkgog = true ; rtDW . nkmva5gdkf
= true ; rtDW . k043rv4keo = true ; } void MdlEnable ( void ) {
ssSetNumTicksToNextHitForControllableSampleTime ( rtS , 5 , 1.0 ) ; ;
ssSetNumTicksToNextHitForControllableSampleTime ( rtS , 4 , 1.0 ) ; ; } void
MdlStart ( void ) { { bool externalInputIsInDatasetFormat = false ; void *
pISigstreamManager = rt_GetISigstreamManager ( rtS ) ;
rtwISigstreamManagerGetInputIsInDatasetFormat ( pISigstreamManager , &
externalInputIsInDatasetFormat ) ; if ( externalInputIsInDatasetFormat ) { }
} { { { bool isStreamoutAlreadyRegistered = false ; { sdiSignalSourceInfoU
srcInfo ; sdiLabelU loggedName = sdiGetLabelFromChars ( "&#x89D2;&#x5EA6;" )
; sdiLabelU origSigName = sdiGetLabelFromChars ( "&#x89D2;&#x5EA6;" ) ;
sdiLabelU propName = sdiGetLabelFromChars ( "&#x89D2;&#x5EA6;" ) ; sdiLabelU
blockPath = sdiGetLabelFromChars ( "air_part1_python2/To Workspace" ) ;
sdiLabelU blockSID = sdiGetLabelFromChars ( "" ) ; sdiLabelU subPath =
sdiGetLabelFromChars ( "" ) ; sdiDims sigDims ; sdiLabelU sigName =
sdiGetLabelFromChars ( "&#x89D2;&#x5EA6;" ) ; sdiAsyncRepoDataTypeHandle hDT
= sdiAsyncRepoGetBuiltInDataTypeHandle ( DATA_TYPE_DOUBLE ) ; { sdiComplexity
sigComplexity = REAL ; sdiSampleTimeContinuity stCont =
SAMPLE_TIME_CONTINUOUS ; int_T sigDimsArray [ 1 ] = { 1 } ; sigDims . nDims =
1 ; sigDims . dimensions = sigDimsArray ; srcInfo . numBlockPathElems = 1 ;
srcInfo . fullBlockPath = ( sdiFullBlkPathU ) & blockPath ; srcInfo . SID = (
sdiSignalIDU ) & blockSID ; srcInfo . subPath = subPath ; srcInfo . portIndex
= 0 + 1 ; srcInfo . signalName = sigName ; srcInfo . sigSourceUUID = 0 ; rtDW
. mngvkp03ok . AQHandles = sdiStartAsyncioQueueCreation ( hDT , & srcInfo ,
rt_dataMapInfo . mmi . InstanceMap . fullPath ,
"30e84324-ec03-4fb8-b9c5-c35cd3dd2e06" , sigComplexity , & sigDims ,
DIMENSIONS_MODE_FIXED , stCont , "" ) ; sdiCompleteAsyncioQueueCreation (
rtDW . mngvkp03ok . AQHandles , hDT , & srcInfo ) ; if ( rtDW . mngvkp03ok .
AQHandles ) { sdiSetSignalSampleTimeString ( rtDW . mngvkp03ok . AQHandles ,
"5e-05" , 5.0E-5 , ssGetTFinal ( rtS ) ) ; sdiSetSignalRefRate ( rtDW .
mngvkp03ok . AQHandles , 0.0 ) ; sdiSetRunStartTime ( rtDW . mngvkp03ok .
AQHandles , ssGetTaskTime ( rtS , 1 ) ) ; sdiAsyncRepoSetSignalExportSettings
( rtDW . mngvkp03ok . AQHandles , 1 , 0 ) ; sdiAsyncRepoSetSignalExportName (
rtDW . mngvkp03ok . AQHandles , loggedName , origSigName , propName ) ;
sdiAsyncRepoSetBlockPathDomain ( rtDW . mngvkp03ok . AQHandles ) ; }
sdiFreeLabel ( sigName ) ; sdiFreeLabel ( loggedName ) ; sdiFreeLabel (
origSigName ) ; sdiFreeLabel ( propName ) ; sdiFreeLabel ( blockPath ) ;
sdiFreeLabel ( blockSID ) ; sdiFreeLabel ( subPath ) ; } } if ( !
isStreamoutAlreadyRegistered ) { { sdiLabelU varName = sdiGetLabelFromChars (
"simout" ) ; sdiRegisterWksVariable ( rtDW . mngvkp03ok . AQHandles , varName
, "timeseries" ) ; sdiFreeLabel ( varName ) ; } } } } } { { { bool
isStreamoutAlreadyRegistered = false ; { sdiSignalSourceInfoU srcInfo ;
sdiLabelU loggedName = sdiGetLabelFromChars (
"&#x7FBD;&#x3070;&#x305F;&#x304D;&#x5468;&#x6CE2;&#x6570;roll/s" ) ;
sdiLabelU origSigName = sdiGetLabelFromChars (
"&#x7FBD;&#x3070;&#x305F;&#x304D;&#x5468;&#x6CE2;&#x6570;roll/s" ) ;
sdiLabelU propName = sdiGetLabelFromChars (
"&#x7FBD;&#x3070;&#x305F;&#x304D;&#x5468;&#x6CE2;&#x6570;roll/s" ) ;
sdiLabelU blockPath = sdiGetLabelFromChars (
"air_part1_python2/To Workspace1" ) ; sdiLabelU blockSID =
sdiGetLabelFromChars ( "" ) ; sdiLabelU subPath = sdiGetLabelFromChars ( "" )
; sdiDims sigDims ; sdiLabelU sigName = sdiGetLabelFromChars (
"&#x7FBD;&#x3070;&#x305F;&#x304D;&#x5468;&#x6CE2;&#x6570;roll/s" ) ;
sdiAsyncRepoDataTypeHandle hDT = sdiAsyncRepoGetBuiltInDataTypeHandle (
DATA_TYPE_DOUBLE ) ; { sdiComplexity sigComplexity = REAL ;
sdiSampleTimeContinuity stCont = SAMPLE_TIME_CONTINUOUS ; int_T sigDimsArray
[ 1 ] = { 1 } ; sigDims . nDims = 1 ; sigDims . dimensions = sigDimsArray ;
srcInfo . numBlockPathElems = 1 ; srcInfo . fullBlockPath = ( sdiFullBlkPathU
) & blockPath ; srcInfo . SID = ( sdiSignalIDU ) & blockSID ; srcInfo .
subPath = subPath ; srcInfo . portIndex = 0 + 1 ; srcInfo . signalName =
sigName ; srcInfo . sigSourceUUID = 0 ; rtDW . bpkyyz2duh . AQHandles =
sdiStartAsyncioQueueCreation ( hDT , & srcInfo , rt_dataMapInfo . mmi .
InstanceMap . fullPath , "d9bd3c4d-3cb6-45a5-81ef-3b3c321d7332" ,
sigComplexity , & sigDims , DIMENSIONS_MODE_FIXED , stCont , "" ) ;
sdiCompleteAsyncioQueueCreation ( rtDW . bpkyyz2duh . AQHandles , hDT , &
srcInfo ) ; if ( rtDW . bpkyyz2duh . AQHandles ) {
sdiSetSignalSampleTimeString ( rtDW . bpkyyz2duh . AQHandles , "5e-05" ,
5.0E-5 , ssGetTFinal ( rtS ) ) ; sdiSetSignalRefRate ( rtDW . bpkyyz2duh .
AQHandles , 0.0 ) ; sdiSetRunStartTime ( rtDW . bpkyyz2duh . AQHandles ,
ssGetTaskTime ( rtS , 1 ) ) ; sdiAsyncRepoSetSignalExportSettings ( rtDW .
bpkyyz2duh . AQHandles , 1 , 0 ) ; sdiAsyncRepoSetSignalExportName ( rtDW .
bpkyyz2duh . AQHandles , loggedName , origSigName , propName ) ;
sdiAsyncRepoSetBlockPathDomain ( rtDW . bpkyyz2duh . AQHandles ) ; }
sdiFreeLabel ( sigName ) ; sdiFreeLabel ( loggedName ) ; sdiFreeLabel (
origSigName ) ; sdiFreeLabel ( propName ) ; sdiFreeLabel ( blockPath ) ;
sdiFreeLabel ( blockSID ) ; sdiFreeLabel ( subPath ) ; } } if ( !
isStreamoutAlreadyRegistered ) { { sdiLabelU varName = sdiGetLabelFromChars (
"hz" ) ; sdiRegisterWksVariable ( rtDW . bpkyyz2duh . AQHandles , varName ,
"timeseries" ) ; sdiFreeLabel ( varName ) ; } } } } } { { { bool
isStreamoutAlreadyRegistered = false ; { sdiSignalSourceInfoU srcInfo ;
sdiLabelU loggedName = sdiGetLabelFromChars ( "&#x5DE6;&#x7FFC;&#x529B;" ) ;
sdiLabelU origSigName = sdiGetLabelFromChars ( "&#x5DE6;&#x7FFC;&#x529B;" ) ;
sdiLabelU propName = sdiGetLabelFromChars ( "&#x5DE6;&#x7FFC;&#x529B;" ) ;
sdiLabelU blockPath = sdiGetLabelFromChars (
"air_part1_python2/To Workspace2" ) ; sdiLabelU blockSID =
sdiGetLabelFromChars ( "" ) ; sdiLabelU subPath = sdiGetLabelFromChars ( "" )
; sdiDims sigDims ; sdiLabelU sigName = sdiGetLabelFromChars (
"&#x5DE6;&#x7FFC;&#x529B;" ) ; sdiAsyncRepoDataTypeHandle hDT =
sdiAsyncRepoGetBuiltInDataTypeHandle ( DATA_TYPE_DOUBLE ) ; { sdiComplexity
sigComplexity = REAL ; sdiSampleTimeContinuity stCont =
SAMPLE_TIME_CONTINUOUS ; int_T sigDimsArray [ 1 ] = { 1 } ; sigDims . nDims =
1 ; sigDims . dimensions = sigDimsArray ; srcInfo . numBlockPathElems = 1 ;
srcInfo . fullBlockPath = ( sdiFullBlkPathU ) & blockPath ; srcInfo . SID = (
sdiSignalIDU ) & blockSID ; srcInfo . subPath = subPath ; srcInfo . portIndex
= 0 + 1 ; srcInfo . signalName = sigName ; srcInfo . sigSourceUUID = 0 ; rtDW
. gwcnekeexx . AQHandles = sdiStartAsyncioQueueCreation ( hDT , & srcInfo ,
rt_dataMapInfo . mmi . InstanceMap . fullPath ,
"b4d1a1c6-d235-4f94-9051-1593b510c082" , sigComplexity , & sigDims ,
DIMENSIONS_MODE_FIXED , stCont , "" ) ; sdiCompleteAsyncioQueueCreation (
rtDW . gwcnekeexx . AQHandles , hDT , & srcInfo ) ; if ( rtDW . gwcnekeexx .
AQHandles ) { sdiSetSignalSampleTimeString ( rtDW . gwcnekeexx . AQHandles ,
"5e-05" , 5.0E-5 , ssGetTFinal ( rtS ) ) ; sdiSetSignalRefRate ( rtDW .
gwcnekeexx . AQHandles , 0.0 ) ; sdiSetRunStartTime ( rtDW . gwcnekeexx .
AQHandles , ssGetTaskTime ( rtS , 1 ) ) ; sdiAsyncRepoSetSignalExportSettings
( rtDW . gwcnekeexx . AQHandles , 1 , 0 ) ; sdiAsyncRepoSetSignalExportName (
rtDW . gwcnekeexx . AQHandles , loggedName , origSigName , propName ) ;
sdiAsyncRepoSetBlockPathDomain ( rtDW . gwcnekeexx . AQHandles ) ; }
sdiFreeLabel ( sigName ) ; sdiFreeLabel ( loggedName ) ; sdiFreeLabel (
origSigName ) ; sdiFreeLabel ( propName ) ; sdiFreeLabel ( blockPath ) ;
sdiFreeLabel ( blockSID ) ; sdiFreeLabel ( subPath ) ; } } if ( !
isStreamoutAlreadyRegistered ) { { sdiLabelU varName = sdiGetLabelFromChars (
"lf" ) ; sdiRegisterWksVariable ( rtDW . gwcnekeexx . AQHandles , varName ,
"timeseries" ) ; sdiFreeLabel ( varName ) ; } } } } } { { { bool
isStreamoutAlreadyRegistered = false ; { sdiSignalSourceInfoU srcInfo ;
sdiLabelU loggedName = sdiGetLabelFromChars ( "&#x53F3;&#x7FFC;&#x529B;" ) ;
sdiLabelU origSigName = sdiGetLabelFromChars ( "&#x53F3;&#x7FFC;&#x529B;" ) ;
sdiLabelU propName = sdiGetLabelFromChars ( "&#x53F3;&#x7FFC;&#x529B;" ) ;
sdiLabelU blockPath = sdiGetLabelFromChars (
"air_part1_python2/To Workspace3" ) ; sdiLabelU blockSID =
sdiGetLabelFromChars ( "" ) ; sdiLabelU subPath = sdiGetLabelFromChars ( "" )
; sdiDims sigDims ; sdiLabelU sigName = sdiGetLabelFromChars (
"&#x53F3;&#x7FFC;&#x529B;" ) ; sdiAsyncRepoDataTypeHandle hDT =
sdiAsyncRepoGetBuiltInDataTypeHandle ( DATA_TYPE_DOUBLE ) ; { sdiComplexity
sigComplexity = REAL ; sdiSampleTimeContinuity stCont =
SAMPLE_TIME_CONTINUOUS ; int_T sigDimsArray [ 1 ] = { 1 } ; sigDims . nDims =
1 ; sigDims . dimensions = sigDimsArray ; srcInfo . numBlockPathElems = 1 ;
srcInfo . fullBlockPath = ( sdiFullBlkPathU ) & blockPath ; srcInfo . SID = (
sdiSignalIDU ) & blockSID ; srcInfo . subPath = subPath ; srcInfo . portIndex
= 0 + 1 ; srcInfo . signalName = sigName ; srcInfo . sigSourceUUID = 0 ; rtDW
. jzk55zhlch . AQHandles = sdiStartAsyncioQueueCreation ( hDT , & srcInfo ,
rt_dataMapInfo . mmi . InstanceMap . fullPath ,
"089286ac-911d-4feb-8452-a6ab3d4667ef" , sigComplexity , & sigDims ,
DIMENSIONS_MODE_FIXED , stCont , "" ) ; sdiCompleteAsyncioQueueCreation (
rtDW . jzk55zhlch . AQHandles , hDT , & srcInfo ) ; if ( rtDW . jzk55zhlch .
AQHandles ) { sdiSetSignalSampleTimeString ( rtDW . jzk55zhlch . AQHandles ,
"5e-05" , 5.0E-5 , ssGetTFinal ( rtS ) ) ; sdiSetSignalRefRate ( rtDW .
jzk55zhlch . AQHandles , 0.0 ) ; sdiSetRunStartTime ( rtDW . jzk55zhlch .
AQHandles , ssGetTaskTime ( rtS , 1 ) ) ; sdiAsyncRepoSetSignalExportSettings
( rtDW . jzk55zhlch . AQHandles , 1 , 0 ) ; sdiAsyncRepoSetSignalExportName (
rtDW . jzk55zhlch . AQHandles , loggedName , origSigName , propName ) ;
sdiAsyncRepoSetBlockPathDomain ( rtDW . jzk55zhlch . AQHandles ) ; }
sdiFreeLabel ( sigName ) ; sdiFreeLabel ( loggedName ) ; sdiFreeLabel (
origSigName ) ; sdiFreeLabel ( propName ) ; sdiFreeLabel ( blockPath ) ;
sdiFreeLabel ( blockSID ) ; sdiFreeLabel ( subPath ) ; } } if ( !
isStreamoutAlreadyRegistered ) { { sdiLabelU varName = sdiGetLabelFromChars (
"rf" ) ; sdiRegisterWksVariable ( rtDW . jzk55zhlch . AQHandles , varName ,
"timeseries" ) ; sdiFreeLabel ( varName ) ; } } } } } { SimStruct * rts =
ssGetSFunction ( rtS , 0 ) ; sfcnStart ( rts ) ; if ( ssGetErrorStatus ( rts
) != ( NULL ) ) return ; } { SimStruct * rts = ssGetSFunction ( rtS , 1 ) ;
sfcnStart ( rts ) ; if ( ssGetErrorStatus ( rts ) != ( NULL ) ) return ; }
ggpbldjcut ( & rtDW . bvsrcp4u0i ) ; rtDW . bvsrcp4u0i . TCPIPObj . _pobj1 .
InputStream . matlabCodegenIsDeleted = true ; rtDW . bvsrcp4u0i . TCPIPObj .
_pobj0 . UnreadDataBuffer . InputStream . matlabCodegenIsDeleted = true ;
rtDW . bvsrcp4u0i . TCPIPObj . _pobj1 . OutputStream . matlabCodegenIsDeleted
= true ; rtDW . bvsrcp4u0i . TCPIPObj . _pobj0 . UnreadDataBuffer .
OutputStream . matlabCodegenIsDeleted = true ; rtDW . bvsrcp4u0i . TCPIPObj .
_pobj1 . matlabCodegenIsDeleted = true ; rtDW . bvsrcp4u0i . TCPIPObj .
_pobj0 . UnreadDataBuffer . matlabCodegenIsDeleted = true ; rtDW . bvsrcp4u0i
. TCPIPObj . _pobj0 . matlabCodegenIsDeleted = true ; rtDW . bvsrcp4u0i .
TCPIPObj . matlabCodegenIsDeleted = true ; rtDW . ag0g5gwgl3 = 0U ; rtDW .
nbwsx1apcl = true ; rtDW . bvsrcp4u0i . isInitialized = 0 ; rtDW . bvsrcp4u0i
. matlabCodegenIsDeleted = false ; rtDW . mmap3xsiti = true ; l0afvsmpfaw ( &
rtDW . bvsrcp4u0i ) ; ggpbldjcutv ( & rtDW . hwcuhwqvaz ) ; rtDW . hwcuhwqvaz
. TCPIPObj . _pobj1 . InputStream . matlabCodegenIsDeleted = true ; rtDW .
hwcuhwqvaz . TCPIPObj . _pobj0 . UnreadDataBuffer . InputStream .
matlabCodegenIsDeleted = true ; rtDW . hwcuhwqvaz . TCPIPObj . _pobj1 .
OutputStream . matlabCodegenIsDeleted = true ; rtDW . hwcuhwqvaz . TCPIPObj .
_pobj0 . UnreadDataBuffer . OutputStream . matlabCodegenIsDeleted = true ;
rtDW . hwcuhwqvaz . TCPIPObj . _pobj1 . matlabCodegenIsDeleted = true ; rtDW
. hwcuhwqvaz . TCPIPObj . _pobj0 . UnreadDataBuffer . matlabCodegenIsDeleted
= true ; rtDW . hwcuhwqvaz . TCPIPObj . _pobj0 . matlabCodegenIsDeleted =
true ; rtDW . hwcuhwqvaz . TCPIPObj . matlabCodegenIsDeleted = true ; rtDW .
bspqyhc1ui = 0U ; rtDW . jpzpmlt0aw = true ; rtDW . hwcuhwqvaz .
isInitialized = 0 ; rtDW . hwcuhwqvaz . matlabCodegenIsDeleted = false ; rtDW
. gmsb3q2zlj = true ; l0afvsmpfa ( & rtDW . hwcuhwqvaz ) ; { SimStruct * rts
= ssGetSFunction ( rtS , 2 ) ; sfcnStart ( rts ) ; if ( ssGetErrorStatus (
rts ) != ( NULL ) ) return ; } { SimStruct * rts = ssGetSFunction ( rtS , 3 )
; sfcnStart ( rts ) ; if ( ssGetErrorStatus ( rts ) != ( NULL ) ) return ; }
{ SimStruct * rts = ssGetSFunction ( rtS , 4 ) ; sfcnStart ( rts ) ; if (
ssGetErrorStatus ( rts ) != ( NULL ) ) return ; } { SimStruct * rts =
ssGetSFunction ( rtS , 5 ) ; sfcnStart ( rts ) ; if ( ssGetErrorStatus ( rts
) != ( NULL ) ) return ; } { SimStruct * rts = ssGetSFunction ( rtS , 6 ) ;
sfcnStart ( rts ) ; if ( ssGetErrorStatus ( rts ) != ( NULL ) ) return ; } {
SimStruct * rts = ssGetSFunction ( rtS , 7 ) ; sfcnStart ( rts ) ; if (
ssGetErrorStatus ( rts ) != ( NULL ) ) return ; } { int_T j ; char ptrKey [
1024 ] ; { real_T * pBuffer = ( real_T * ) rt_TDelayCreateBuf ( 2 , 1024 ,
sizeof ( real_T ) ) ; if ( pBuffer == ( NULL ) ) { ssSetErrorStatus ( rtS ,
"vtdelay memory allocation error" ) ; return ; } rtDW . mr2aud2zdd . Tail = 0
; rtDW . mr2aud2zdd . Head = 0 ; rtDW . mr2aud2zdd . Last = 0 ; rtDW .
mr2aud2zdd . CircularBufSize = 1024 ; for ( j = 0 ; j < 1024 ; j ++ ) {
pBuffer [ j ] = rtP . VariableTimeDelay1_InitOutput ; pBuffer [ 1024 + j ] =
ssGetT ( rtS ) ; } rtDW . pqulut3liz . TUbufferPtrs [ 0 ] = ( void * ) &
pBuffer [ 0 ] ; sprintf ( ptrKey ,
"air_part1_python2/Variable\nTime Delay1_TUbuffer%d" , 0 ) ;
slsaSaveRawMemoryForSimTargetOP ( rtS , ptrKey , ( void * * ) ( & rtDW .
pqulut3liz . TUbufferPtrs [ 0 ] ) , 2 * 1024 * sizeof ( real_T ) , ( NULL ) ,
( NULL ) ) ; } } { int_T j ; char ptrKey [ 1024 ] ; { real_T * pBuffer = (
real_T * ) rt_TDelayCreateBuf ( 2 , 1024 , sizeof ( real_T ) ) ; if ( pBuffer
== ( NULL ) ) { ssSetErrorStatus ( rtS , "vtdelay memory allocation error" )
; return ; } rtDW . hmazbcxsfm . Tail = 0 ; rtDW . hmazbcxsfm . Head = 0 ;
rtDW . hmazbcxsfm . Last = 0 ; rtDW . hmazbcxsfm . CircularBufSize = 1024 ;
for ( j = 0 ; j < 1024 ; j ++ ) { pBuffer [ j ] = rtP .
VariableTimeDelay_InitOutput ; pBuffer [ 1024 + j ] = ssGetT ( rtS ) ; } rtDW
. l24xckmdwx . TUbufferPtrs [ 0 ] = ( void * ) & pBuffer [ 0 ] ; sprintf (
ptrKey , "air_part1_python2/Variable\nTime Delay_TUbuffer%d" , 0 ) ;
slsaSaveRawMemoryForSimTargetOP ( rtS , ptrKey , ( void * * ) ( & rtDW .
l24xckmdwx . TUbufferPtrs [ 0 ] ) , 2 * 1024 * sizeof ( real_T ) , ( NULL ) ,
( NULL ) ) ; } } MdlInitialize ( ) ; MdlEnable ( ) ; } void MdlOutputs (
int_T tid ) { real_T nlmnoqve2u ; real_T cedpwfbkxg ; real_T bq4ocmcshw ;
real_T jqi4dfmf3b ; real_T abtzudaa22 ; real_T l1f4lt4bzr ; real_T nltgngrv0f
; real_T nwn55h0jth ; real_T h1gj42rjt1 ; real_T fyamgsybsv ; real_T
hbk42ogwqv ; real_T kge0hyy05m ; real_T fzkgaahydo ; uint32_T dy1tpvtpxp ;
uint32_T pcqdvow2ge ; CoderChannel chImpl ; CoderInputStream streamImpl_p ;
CoderOutputStream streamImpl ; akean23d1n * b_rawData ; akean23d1n *
outputVal ; akean23d1n * rawData ; akean23d1n * tempDataArray ; akean23d1n *
x ; ax0y0tfz0l * obj_m ; bkeu4uuq53 c ; coderTimespec b_timespec ; e4wb5cpnqg
* obj_e ; g1hz5apriq * obj_i ; g1hz5apriq * varargin_1_p ; g1hz5apriqr * obj
; g1hz5apriqr * varargin_1 ; kc1cjr2jks * out ; kwgo0x2v41 * obj_g ;
kwgo0x2v41z * obj_p ; mfwlu25r5h c_p ; int64_T varargin_2 [ 256 ] ; int64_T y
; real_T Ct ; real_T a ; real_T aolrab3vsg ; real_T atth0jv4h4 ; real_T
bjfnshtvtj ; real_T cyhwdk1y1a ; real_T czl2hnisq2 ; real_T fexu0l1x0s ;
real_T gol0mqxiqq ; real_T h ; real_T h2 ; real_T hqku2g2u0k ; real_T
j2dhsdxshg ; real_T jolkdr5rbf ; real_T jpanute2ig ; real_T l1phen4mok ;
real_T m3cwp3vr0t ; real_T meyaghcm42 ; real_T mfkqizvjlz ; real_T miejctwg5s
; real_T n4xqv5gnnc ; real_T ngpyrblgeg ; real_T nlnz051lqu ; real_T
nydfixtxb0 ; real_T opny1a35qe ; real_T oyxofam2xe ; real_T phros1savd ;
real_T pjmp1jmbdg ; real_T pydc0a2xwf ; real_T theta_ ; real_T * lastU ;
uint64_T numBytesWritten ; int32_T loop_ub ; int32_T success ; char_T errorID
[ 1024 ] ; char_T errorText [ 1024 ] ; char_T status_data [ 9 ] ; char_T a_p
[ 5 ] ; char_T b [ 5 ] ; uint8_T b_x [ 8 ] ; uint8_T xtmp ; boolean_T
hasEnoughData ; boolean_T hasSyncError ; static const char_T tmp [ 5 ] = {
'i' , 'n' , 't' , '6' , '4' } ; static const char_T tmp_p [ 128 ] = { '\x00'
, '\x01' , '\x02' , '\x03' , '\x04' , '\x05' , '\x06' , '\x07' , '\x08' ,
'\x09' , '\x0a' , '\x0b' , '\x0c' , '\x0d' , '\x0e' , '\x0f' , '\x10' ,
'\x11' , '\x12' , '\x13' , '\x14' , '\x15' , '\x16' , '\x17' , '\x18' ,
'\x19' , '\x1a' , '\x1b' , '\x1c' , '\x1d' , '\x1e' , '\x1f' , ' ' , '!' ,
'\"' , '#' , '$' , '%' , '&' , '\'' , '(' , ')' , '*' , '+' , ',' , '-' , '.'
, '/' , '0' , '1' , '2' , '3' , '4' , '5' , '6' , '7' , '8' , '9' , ':' , ';'
, '<' , '=' , '>' , '?' , '@' , 'a' , 'b' , 'c' , 'd' , 'e' , 'f' , 'g' , 'h'
, 'i' , 'j' , 'k' , 'l' , 'm' , 'n' , 'o' , 'p' , 'q' , 'r' , 's' , 't' , 'u'
, 'v' , 'w' , 'x' , 'y' , 'z' , '[' , '\\' , ']' , '^' , '_' , '`' , 'a' ,
'b' , 'c' , 'd' , 'e' , 'f' , 'g' , 'h' , 'i' , 'j' , 'k' , 'l' , 'm' , 'n' ,
'o' , 'p' , 'q' , 'r' , 's' , 't' , 'u' , 'v' , 'w' , 'x' , 'y' , 'z' , '{' ,
'|' , '}' , '~' , '\x7f' } ; int32_T status_size [ 2 ] ; int32_T exitg1 ;
uint8_T * x_p ; boolean_T exitg2 ; boolean_T exitg3 ; boolean_T guard1 =
false ; oyxofam2xe = rtX . eypdcundes ; if ( ssIsSampleHit ( rtS , 1 , 0 ) )
{ dy1tpvtpxp = rtDW . jl0mnuibbh ; nlnz051lqu = ( real_T ) dy1tpvtpxp * rtP .
timestep_Value ; rtB . a405zozv5t = rtP . a6_Value - nlnz051lqu * rtP .
timestep2_Value ; } rtB . buugn1y4kg = rtX . eypdcundes * rtB . a405zozv5t *
rtP . Gain ; if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { } rtB . m0fvlyj223 = rtX
. lh2zlfy5gs ; if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { } j2dhsdxshg =
muDoubleScalarRem ( rtX . o2miuctf5t , rtP . constant2_Value ) ; h2 = 2.0 *
rtP . a_Value * rtP . b_Value * muDoubleScalarCos ( j2dhsdxshg ) + ( rtP .
a_Value * rtP . a_Value + rtP . b_Value * rtP . b_Value ) ; h =
muDoubleScalarSqrt ( h2 ) ; jolkdr5rbf = 1.5707963267948966 -
muDoubleScalarAcos ( ( ( rtP . c_Value * rtP . c_Value - h2 ) + rtP . d_Value
* rtP . d_Value ) / ( 2.0 * rtP . c_Value * rtP . d_Value ) ) ; theta_ =
muDoubleScalarAcos ( ( ( - ( rtP . d_Value * rtP . d_Value ) + h2 ) + rtP .
c_Value * rtP . c_Value ) / ( 2.0 * h * rtP . c_Value ) ) +
muDoubleScalarAtan2 ( rtP . a_Value - rtP . b_Value * muDoubleScalarCos (
j2dhsdxshg ) , rtP . b_Value * muDoubleScalarSin ( j2dhsdxshg ) ) ;
jpanute2ig = 1.5707963267948966 - ( j2dhsdxshg - ( 1.5707963267948966 - (
3.1415926535897931 - theta_ ) ) ) ; if ( j2dhsdxshg > 3.1415926535897931 ) {
pjmp1jmbdg = - muDoubleScalarAcos ( ( ( rtP . a_Value * rtP . a_Value + h2 )
- rtP . b_Value * rtP . b_Value ) / ( 2.0 * h * rtP . a_Value ) ) +
muDoubleScalarAcos ( ( ( rtP . d_Value * rtP . d_Value + h2 ) - rtP . c_Value
* rtP . c_Value ) / ( 2.0 * h * rtP . d_Value ) ) ; } else { pjmp1jmbdg =
muDoubleScalarAcos ( ( ( rtP . a_Value * rtP . a_Value + h2 ) - rtP . b_Value
* rtP . b_Value ) / ( 2.0 * h * rtP . a_Value ) ) + muDoubleScalarAcos ( ( (
rtP . d_Value * rtP . d_Value + h2 ) - rtP . c_Value * rtP . c_Value ) / (
2.0 * h * rtP . d_Value ) ) ; } rtB . mqpvdapacf = rtP .
constant3_Value_e1gwiy1pb3 - rtP . u_Gain * pjmp1jmbdg ; rtB . frqdqeq5gg =
rtB . mqpvdapacf - rtP . Constant_Value_iq4hlvezb4 ; a3gzjtzg5m ( rtB .
frqdqeq5gg , & rtB . p2tfl52njg ) ; if ( ( rtDW . l30tmqcnmm >= ssGetT ( rtS
) ) && ( rtDW . iv3sxafqgs >= ssGetT ( rtS ) ) ) { nlmnoqve2u = 0.0 ; } else
{ h2 = rtDW . l30tmqcnmm ; lastU = & rtDW . njuyqff5u5 ; if ( rtDW .
l30tmqcnmm < rtDW . iv3sxafqgs ) { if ( rtDW . iv3sxafqgs < ssGetT ( rtS ) )
{ h2 = rtDW . iv3sxafqgs ; lastU = & rtDW . dahp1m1tnz ; } } else if ( rtDW .
l30tmqcnmm >= ssGetT ( rtS ) ) { h2 = rtDW . iv3sxafqgs ; lastU = & rtDW .
dahp1m1tnz ; } nlmnoqve2u = ( rtB . p2tfl52njg . fsek3luzie - * lastU ) / (
ssGetT ( rtS ) - h2 ) ; } g1ij20yo5c ( rtB . p2tfl52njg . fsek3luzie ,
nlmnoqve2u , rtP . open_AOAdegree_Value_bru0w4josw , rtP .
close_AOAdegree_Value_crud0nlfli , & rtB . aelnqmel4f ) ; if ( rtB .
aelnqmel4f . jb2b5najpv == 1.0 ) { rtB . c1l0t1ppoz = rtP .
open_AOAdegree_Value_bru0w4josw ; } else if ( rtB . aelnqmel4f . jb2b5najpv
== 2.0 ) { rtB . c1l0t1ppoz = muDoubleScalarMin ( muDoubleScalarAsin ( (
muDoubleScalarSin ( rtP . open_AOAdegree_Value_bru0w4josw *
3.1415926535897931 / 180.0 ) * 0.1 - ( 0.198 - rtB . p2tfl52njg . fsek3luzie
) ) / 0.1 ) * 180.0 / 3.1415926535897931 , rtP .
open_AOAdegree_Value_bru0w4josw ) ; } else if ( rtB . aelnqmel4f . jb2b5najpv
== 3.0 ) { rtB . c1l0t1ppoz = rtP . close_AOAdegree_Value_crud0nlfli ; } else
{ rtB . c1l0t1ppoz = muDoubleScalarMax ( - muDoubleScalarAsin ( (
muDoubleScalarSin ( - rtP . close_AOAdegree_Value_crud0nlfli *
3.1415926535897931 / 180.0 ) * 0.1 / 2.0 - rtB . p2tfl52njg . fsek3luzie ) /
0.05 ) * 180.0 / 3.1415926535897931 , rtP . close_AOAdegree_Value_crud0nlfli
) ; } cedpwfbkxg = rtP . Constant1_Value_bfs2kyqhyj - rtB . c1l0t1ppoz ;
jj2h00reln ( cedpwfbkxg , & rtB . hwhgormc0n ) ; if ( ( rtDW . egmxveifc2 >=
ssGetT ( rtS ) ) && ( rtDW . jrcajuutzs >= ssGetT ( rtS ) ) ) { mfkqizvjlz =
0.0 ; } else { h2 = rtDW . egmxveifc2 ; lastU = & rtDW . nyak4kxjb0 ; if (
rtDW . egmxveifc2 < rtDW . jrcajuutzs ) { if ( rtDW . jrcajuutzs < ssGetT (
rtS ) ) { h2 = rtDW . jrcajuutzs ; lastU = & rtDW . bto3rz2afq ; } } else if
( rtDW . egmxveifc2 >= ssGetT ( rtS ) ) { h2 = rtDW . jrcajuutzs ; lastU = &
rtDW . bto3rz2afq ; } mfkqizvjlz = ( rtB . c1l0t1ppoz - * lastU ) / ( ssGetT
( rtS ) - h2 ) ; } rtB . itbqmhqgrz = muDoubleScalarAbs ( mfkqizvjlz ) ; if (
( rtDW . l4a3zwvtji >= ssGetT ( rtS ) ) && ( rtDW . evnfi3oakh >= ssGetT (
rtS ) ) ) { bjfnshtvtj = 0.0 ; } else { h2 = rtDW . l4a3zwvtji ; lastU = &
rtDW . ecriaizrd0 ; if ( rtDW . l4a3zwvtji < rtDW . evnfi3oakh ) { if ( rtDW
. evnfi3oakh < ssGetT ( rtS ) ) { h2 = rtDW . evnfi3oakh ; lastU = & rtDW .
jqu0hns3uo ; } } else if ( rtDW . l4a3zwvtji >= ssGetT ( rtS ) ) { h2 = rtDW
. evnfi3oakh ; lastU = & rtDW . jqu0hns3uo ; } bjfnshtvtj = ( rtB .
mqpvdapacf - * lastU ) / ( ssGetT ( rtS ) - h2 ) ; } a = rtB . hwhgormc0n .
n5nj1b05gf * 3.1415926535897931 / 180.0 ; if ( rtB . hwhgormc0n . n5nj1b05gf
> 45.0 ) { Ct = 0.0 ; } else { h2 = muDoubleScalarCos ( 2.0 * a ) ; Ct = h2 *
h2 * 0.4 ; } h2 = muDoubleScalarAbs ( bjfnshtvtj ) * 3.1415926535897931 /
180.0 * 0.055 ; if ( ( rtB . aelnqmel4f . jb2b5najpv == 1.0 ) || ( rtB .
aelnqmel4f . jb2b5najpv == 3.0 ) ) { h = 3.4 * muDoubleScalarSin ( a ) *
0.013382549999999998 * ( h2 * h2 ) ; Ct = 0.013382549999999998 * Ct * ( h2 *
h2 ) ; } else { h = 0.0 ; Ct = 0.0 ; } h2 = rtB . itbqmhqgrz *
3.1415926535897931 / 180.0 * 0.003218775389867781 * h2 + h ; gol0mqxiqq = h2
* muDoubleScalarCos ( a ) - Ct * muDoubleScalarSin ( a ) ; l1phen4mok = h2 *
muDoubleScalarSin ( a ) + Ct * muDoubleScalarCos ( a ) ; n4xqv5gnnc =
muDoubleScalarCos ( rtP . Gain_Gain * rtB . mqpvdapacf ) * 0.055 * l1phen4mok
; ngpyrblgeg = rtP . constant3_Value - j2dhsdxshg ; h2 = 2.0 * rtP . a_Value
* rtP . b_Value * muDoubleScalarCos ( ngpyrblgeg ) + ( rtP . a_Value * rtP .
a_Value + rtP . b_Value * rtP . b_Value ) ; h = muDoubleScalarSqrt ( h2 ) ;
opny1a35qe = 1.5707963267948966 - muDoubleScalarAcos ( ( ( rtP . c_Value *
rtP . c_Value - h2 ) + rtP . d_Value * rtP . d_Value ) / ( 2.0 * rtP .
c_Value * rtP . d_Value ) ) ; a = muDoubleScalarAcos ( ( ( - ( rtP . d_Value
* rtP . d_Value ) + h2 ) + rtP . c_Value * rtP . c_Value ) / ( 2.0 * h * rtP
. c_Value ) ) + muDoubleScalarAtan2 ( rtP . a_Value - rtP . b_Value *
muDoubleScalarCos ( ngpyrblgeg ) , rtP . b_Value * muDoubleScalarSin (
ngpyrblgeg ) ) ; aolrab3vsg = 1.5707963267948966 - ( ngpyrblgeg - (
1.5707963267948966 - ( 3.1415926535897931 - a ) ) ) ; if ( ngpyrblgeg >
3.1415926535897931 ) { fexu0l1x0s = - muDoubleScalarAcos ( ( ( rtP . a_Value
* rtP . a_Value + h2 ) - rtP . b_Value * rtP . b_Value ) / ( 2.0 * h * rtP .
a_Value ) ) + muDoubleScalarAcos ( ( ( rtP . d_Value * rtP . d_Value + h2 ) -
rtP . c_Value * rtP . c_Value ) / ( 2.0 * h * rtP . d_Value ) ) ; } else {
fexu0l1x0s = muDoubleScalarAcos ( ( ( rtP . a_Value * rtP . a_Value + h2 ) -
rtP . b_Value * rtP . b_Value ) / ( 2.0 * h * rtP . a_Value ) ) +
muDoubleScalarAcos ( ( ( rtP . d_Value * rtP . d_Value + h2 ) - rtP . c_Value
* rtP . c_Value ) / ( 2.0 * h * rtP . d_Value ) ) ; } rtB . e4k3uwbbqo = rtP
. u_Gain_fqvbril3va * fexu0l1x0s - rtP . constant3_Value_bufvhyvmaf ; rtB .
oj1fmvrj3c = rtB . e4k3uwbbqo - rtP . Constant_Value_dbb4dojqmp ; a3gzjtzg5m
( rtB . oj1fmvrj3c , & rtB . c21bk5qnit ) ; if ( ( rtDW . ajtguqv0em >=
ssGetT ( rtS ) ) && ( rtDW . omefgf0cmg >= ssGetT ( rtS ) ) ) { bq4ocmcshw =
0.0 ; } else { h2 = rtDW . ajtguqv0em ; lastU = & rtDW . b42g2henkn ; if (
rtDW . ajtguqv0em < rtDW . omefgf0cmg ) { if ( rtDW . omefgf0cmg < ssGetT (
rtS ) ) { h2 = rtDW . omefgf0cmg ; lastU = & rtDW . eo5jyafoo5 ; } } else if
( rtDW . ajtguqv0em >= ssGetT ( rtS ) ) { h2 = rtDW . omefgf0cmg ; lastU = &
rtDW . eo5jyafoo5 ; } bq4ocmcshw = ( rtB . c21bk5qnit . fsek3luzie - * lastU
) / ( ssGetT ( rtS ) - h2 ) ; } mjmlfjqs31 ( rtB . c21bk5qnit . fsek3luzie ,
bq4ocmcshw , rtP . open_AOAdegree_Value_a135evdloz , rtP .
close_AOAdegree_Value_mqej5anoke , & rtB . eoqlazxz1z ) ; dtuuqh01ed ( rtB .
eoqlazxz1z . nf3awaueuw , rtB . c21bk5qnit . fsek3luzie , rtP .
open_AOAdegree_Value_a135evdloz , rtP . close_AOAdegree_Value_mqej5anoke , &
rtB . elpvuejile ) ; jqi4dfmf3b = rtP . Constant1_Value_fqnw4iunxo - rtB .
elpvuejile . o5vabvlgjn ; jj2h00reln ( jqi4dfmf3b , & rtB . ktoqcjl1wu ) ; if
( ( rtDW . leiplki144 >= ssGetT ( rtS ) ) && ( rtDW . oujf1dobik >= ssGetT (
rtS ) ) ) { phros1savd = 0.0 ; } else { h2 = rtDW . leiplki144 ; lastU = &
rtDW . g4ztp0b3on ; if ( rtDW . leiplki144 < rtDW . oujf1dobik ) { if ( rtDW
. oujf1dobik < ssGetT ( rtS ) ) { h2 = rtDW . oujf1dobik ; lastU = & rtDW .
pcv4wpi3ke ; } } else if ( rtDW . leiplki144 >= ssGetT ( rtS ) ) { h2 = rtDW
. oujf1dobik ; lastU = & rtDW . pcv4wpi3ke ; } phros1savd = ( rtB .
elpvuejile . o5vabvlgjn - * lastU ) / ( ssGetT ( rtS ) - h2 ) ; } if (
phros1savd > rtP . Saturation_UpperSat ) { h2 = rtP . Saturation_UpperSat ; }
else if ( phros1savd < rtP . Saturation_LowerSat ) { h2 = rtP .
Saturation_LowerSat ; } else { h2 = phros1savd ; } rtB . i54d4oicep =
muDoubleScalarAbs ( h2 ) ; if ( ( rtDW . cbkkysibro >= ssGetT ( rtS ) ) && (
rtDW . e33if4mgu4 >= ssGetT ( rtS ) ) ) { rtB . ku0cdrtwff = 0.0 ; } else {
h2 = rtDW . cbkkysibro ; lastU = & rtDW . akkonxbiyb ; if ( rtDW . cbkkysibro
< rtDW . e33if4mgu4 ) { if ( rtDW . e33if4mgu4 < ssGetT ( rtS ) ) { h2 = rtDW
. e33if4mgu4 ; lastU = & rtDW . bkzeyuvdfi ; } } else if ( rtDW . cbkkysibro
>= ssGetT ( rtS ) ) { h2 = rtDW . e33if4mgu4 ; lastU = & rtDW . bkzeyuvdfi ;
} rtB . ku0cdrtwff = ( rtB . e4k3uwbbqo - * lastU ) / ( ssGetT ( rtS ) - h2 )
; } abtzudaa22 = muDoubleScalarAbs ( rtB . ku0cdrtwff ) ; jlcrjksjko ( rtB .
ktoqcjl1wu . n5nj1b05gf , rtB . i54d4oicep , abtzudaa22 , rtB . eoqlazxz1z .
nf3awaueuw , & rtB . f2cxkdl2mb ) ; cyhwdk1y1a = muDoubleScalarCos ( rtP .
Gain_Gain_an1pdnuefr * rtB . e4k3uwbbqo ) * rtB . f2cxkdl2mb . ayo4a0rtpb *
rtB . f2cxkdl2mb . hogtdrsbl0 ; rtB . bwgs3crvzk = n4xqv5gnnc + cyhwdk1y1a ;
if ( bjfnshtvtj > rtP . Switch_Threshold ) { h2 = rtP . a1_Value ; } else {
h2 = rtP . a2_Value ; } atth0jv4h4 = muDoubleScalarAbs ( muDoubleScalarCos (
1.5707963267948966 - ( 3.1415926535897931 - theta_ ) ) * muDoubleScalarSin (
jolkdr5rbf ) * gol0mqxiqq ) * h2 * rtP . e_Value ; if ( rtB . ku0cdrtwff >
rtP . Switch1_Threshold ) { h2 = rtP . a1_Value ; } else { h2 = rtP .
a2_Value ; } pydc0a2xwf = muDoubleScalarAbs ( muDoubleScalarCos (
1.5707963267948966 - ( 3.1415926535897931 - a ) ) * muDoubleScalarSin (
opny1a35qe ) * rtB . f2cxkdl2mb . etkpdfh3bw ) * h2 * rtP . e_Value ; rtB .
exrmi0ldfj = atth0jv4h4 + pydc0a2xwf ; rtB . be3gvejel2 = ( ( n4xqv5gnnc +
cyhwdk1y1a ) + atth0jv4h4 ) + pydc0a2xwf ; if ( ssIsSampleHit ( rtS , 1 , 0 )
) { } rtB . lonvbzqzr1 = rtX . g1kxrlwt1c ; meyaghcm42 = rtX . m0ift0f3ns ;
rtB . firups0wj2 = rtP . u_Gain_b4npwylgl1 * rtX . m0ift0f3ns ; if (
ssIsSampleHit ( rtS , 1 , 0 ) ) { rtB . mjlpzkqz1n = rtP . _Value_ihbzrbcjcd
- nlnz051lqu * rtP . timestep1_Value ; } l1f4lt4bzr = muDoubleScalarRem ( rtX
. lq2uwsqwxu , rtP . constant_Value ) ; imsa1beie2 ( rtP . a_Value , rtP .
b_Value , rtP . c_Value , rtP . d_Value , l1f4lt4bzr , & rtB . ojl1qzu4tl ) ;
rtB . etvoly05ch = rtP . constant3_Value_d4zn1mb3f1 - rtP . u_Gain_lklkiehjn3
* rtB . ojl1qzu4tl . a0dacr3vu5 ; nltgngrv0f = rtP . constant1_Value -
l1f4lt4bzr ; imsa1beie2 ( rtP . a_Value , rtP . b_Value , rtP . c_Value , rtP
. d_Value , nltgngrv0f , & rtB . btyuoi1co3 ) ; rtB . gkuq4mb5x4 = rtP .
u_Gain_pcqi2zh5ks * rtB . btyuoi1co3 . a0dacr3vu5 - rtP .
constant3_Value_gdybbqcsvv ; if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { } if (
ssIsSampleHit ( rtS , 3 , 0 ) ) { rtB . gg1qdr0ca0 = rtP . Output_Gain * rtDW
. jsetdp311j * rtP . Gain_Gain_iih4ui3cnf ; } rtB . fn1r3pr3py = rtB .
be3gvejel2 - rtB . gg1qdr0ca0 ; if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { rtB .
gyqrec4ceq = rtP . a7_Value - nlnz051lqu * rtP . timestep3_Value ; }
hqku2g2u0k = rtX . fl2s00rq4n ; rtB . a3plauwk5y = rtX . fl2s00rq4n * rtB .
gyqrec4ceq * rtP . _Gain ; if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { } rtB .
facwgsdsd1 = rtX . cb0w3bhvxx ; if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { {
SimStruct * rts = ssGetSFunction ( rtS , 0 ) ; sfcnOutputs ( rts , 0 ) ; } {
SimStruct * rts = ssGetSFunction ( rtS , 1 ) ; sfcnOutputs ( rts , 0 ) ; } (
void ) memcpy ( ( uint8_T * ) & rtB . iar4fhawbp [ 0 ] + 0 , ( uint8_T * ) &
rtB . hjr01anyo4 [ 0 ] , 128 ) ; ( void ) memcpy ( ( uint8_T * ) & rtB .
iar4fhawbp [ 0 ] + 128 , ( uint8_T * ) & rtB . f3ybeuoetm [ 0 ] , 128 ) ; for
( success = 0 ; success < 5 ; success ++ ) { a_p [ success ] = rtDW .
bvsrcp4u0i . InputDataType [ success ] ; b [ success ] = tmp [ success ] ; }
hasSyncError = false ; success = 1 ; do { exitg1 = 0 ; if ( success - 1 < 5 )
{ if ( tmp_p [ ( uint8_T ) a_p [ success - 1 ] & 127 ] != tmp_p [ ( int32_T )
b [ success - 1 ] ] ) { exitg1 = 1 ; } else { success ++ ; } } else {
hasSyncError = true ; exitg1 = 1 ; } } while ( exitg1 == 0 ) ; gglhpceojs ( &
out , 2 ) ; if ( hasSyncError ) { for ( success = 0 ; success < 256 ; success
++ ) { varargin_2 [ success ] = rtB . iar4fhawbp [ success ] ; } obj = rtDW .
bvsrcp4u0i . TCPIPObj . TransportChannel ; obj_p = obj -> AsyncIOChannel ;
chImpl = obj_p -> ChannelImpl ; success = coderChannelIsOpen ( chImpl , &
hasSyncError ) ; if ( success == 0 ) { coderChannelHasSyncError ( chImpl , &
hasSyncError ) ; if ( ! hasSyncError ) { coderChannelGetLastError ( chImpl ,
& errorID [ 0 ] , & errorText [ 0 ] ) ; } else { coderChannelGetLastSyncError
( chImpl , & errorID [ 0 ] , & errorText [ 0 ] ) ; } } varargin_1 = rtDW .
bvsrcp4u0i . TCPIPObj . TransportChannel ; obj = varargin_1 ; success = out
-> size [ 0 ] * out -> size [ 1 ] ; out -> size [ 0 ] = 1 ; out -> size [ 1 ]
= varargin_1 -> ByteOrder -> size [ 1 ] ; jzxbjwmmtq ( out , success ) ;
loop_ub = varargin_1 -> ByteOrder -> size [ 1 ] ; for ( success = 0 ; success
< loop_ub ; success ++ ) { out -> data [ success ] = varargin_1 -> ByteOrder
-> data [ success ] ; } if ( ganujgx1ii ( varargin_1 , out ) ) { for (
success = 0 ; success < 256 ; success ++ ) { memcpy ( ( void * ) & b_x [ 0 ]
, ( void * ) & varargin_2 [ success ] , ( uint32_T ) ( ( size_t ) 8 * sizeof
( uint8_T ) ) ) ; xtmp = b_x [ 0 ] ; b_x [ 0 ] = b_x [ 7 ] ; b_x [ 7 ] = xtmp
; xtmp = b_x [ 1 ] ; b_x [ 1 ] = b_x [ 6 ] ; b_x [ 6 ] = xtmp ; xtmp = b_x [
2 ] ; b_x [ 2 ] = b_x [ 5 ] ; b_x [ 5 ] = xtmp ; xtmp = b_x [ 3 ] ; b_x [ 3 ]
= b_x [ 4 ] ; b_x [ 4 ] = xtmp ; memcpy ( ( void * ) & y , ( void * ) & b_x [
0 ] , ( uint32_T ) ( ( size_t ) 1 * sizeof ( int64_T ) ) ) ; varargin_2 [
success ] = y ; } } memcpy ( ( void * ) & c_p . f1 [ 0 ] , ( void * ) &
varargin_2 [ 0 ] , ( uint32_T ) ( ( size_t ) 2048 * sizeof ( uint8_T ) ) ) ;
if ( varargin_1 -> WriteAsync ) { obj_e = & varargin_1 -> AsyncIOChannel ->
OutputStream ; a = 0.0 ; h2 = 1.0 ; exitg2 = false ; while ( ( ! exitg2 ) &&
( a < 2048.0 ) ) { streamImpl = obj_e -> StreamImpl ; success =
coderStreamGetSpaceAvailable ( streamImpl , & theta_ ) ; if ( success == 0 )
{ chImpl = coderStreamGetChannel ( streamImpl ) ; coderChannelHasSyncError (
chImpl , & hasSyncError ) ; if ( ! hasSyncError ) { coderChannelGetLastError
( chImpl , & errorID [ 0 ] , & errorText [ 0 ] ) ; } else {
coderChannelGetLastSyncError ( chImpl , & errorID [ 0 ] , & errorText [ 0 ] )
; } } guard1 = false ; if ( theta_ == 0.0 ) { fpycd4xlib4 ( obj_e ,
status_data , status_size ) ; if ( ! aygswycpr4 ( status_data , status_size )
) { exitg2 = true ; } else { guard1 = true ; } } else { guard1 = true ; } if
( guard1 ) { theta_ = 0.0 ; h = h2 ; loop_ub = 0 ; exitg3 = false ; while ( (
! exitg3 ) && ( loop_ub <= ( int32_T ) ( ( 1.0 - h2 ) + 1.0 ) - 1 ) ) {
streamImpl = obj_e -> StreamImpl ; success =
coderOutputStreamWriteTypedDataOld ( streamImpl , & Ct , 1 , "uint8" , 2048 ,
& c_p . f1 [ 0 ] ) ; if ( success == 0 ) { chImpl = coderStreamGetChannel (
streamImpl ) ; coderChannelHasSyncError ( chImpl , & hasSyncError ) ; if ( !
hasSyncError ) { coderChannelGetLastError ( chImpl , & errorID [ 0 ] , &
errorText [ 0 ] ) ; } else { coderChannelGetLastSyncError ( chImpl , &
errorID [ 0 ] , & errorText [ 0 ] ) ; } } if ( Ct == 0.0 ) { exitg3 = true ;
} else { theta_ += Ct ; h ++ ; loop_ub ++ ; } } a += theta_ ; h2 = h ; } }
varargin_1 -> NumBytesWritten += a ; } else { obj_p = varargin_1 ->
AsyncIOChannel ; chImpl = obj_p -> ChannelImpl ; success =
coderChannelExecute ( chImpl , "Write" , 1 , "Data" , "uint8" , 2048 , & c_p
. f1 [ 0 ] ) ; if ( success == 0 ) { coderChannelHasSyncError ( chImpl , &
hasSyncError ) ; if ( ! hasSyncError ) { coderChannelGetLastError ( chImpl ,
& errorID [ 0 ] , & errorText [ 0 ] ) ; } else { coderChannelGetLastSyncError
( chImpl , & errorID [ 0 ] , & errorText [ 0 ] ) ; } } obj_p = varargin_1 ->
AsyncIOChannel ; numBytesWritten = obj_p -> CustomProps .
LatestNumBytesWrittenToDevice ; chImpl = obj_p -> ChannelImpl ; success =
coderChannelGetPropertyValue ( chImpl , "LatestNumBytesWrittenToDevice" ,
"uint64" , 1 , & numBytesWritten ) ; if ( success == 0 ) {
coderChannelHasSyncError ( chImpl , & hasSyncError ) ; if ( ! hasSyncError )
{ coderChannelGetLastError ( chImpl , & errorID [ 0 ] , & errorText [ 0 ] ) ;
} else { coderChannelGetLastSyncError ( chImpl , & errorID [ 0 ] , &
errorText [ 0 ] ) ; } } varargin_1 -> NumBytesWritten += ( real_T )
numBytesWritten ; } praqpj5wy4 ( & obj -> AsyncIOChannel -> OutputStream ) ;
} else { obj = rtDW . bvsrcp4u0i . TCPIPObj . TransportChannel ; obj_p = obj
-> AsyncIOChannel ; chImpl = obj_p -> ChannelImpl ; success =
coderChannelIsOpen ( chImpl , & hasSyncError ) ; if ( success == 0 ) {
coderChannelHasSyncError ( chImpl , & hasSyncError ) ; if ( ! hasSyncError )
{ coderChannelGetLastError ( chImpl , & errorID [ 0 ] , & errorText [ 0 ] ) ;
} else { coderChannelGetLastSyncError ( chImpl , & errorID [ 0 ] , &
errorText [ 0 ] ) ; } } varargin_1 = rtDW . bvsrcp4u0i . TCPIPObj .
TransportChannel ; obj = varargin_1 ; x_p = & rtB . iar4fhawbp [ 0 ] ;
success = out -> size [ 0 ] * out -> size [ 1 ] ; out -> size [ 0 ] = 1 ; out
-> size [ 1 ] = varargin_1 -> ByteOrder -> size [ 1 ] ; jzxbjwmmtq ( out ,
success ) ; loop_ub = varargin_1 -> ByteOrder -> size [ 1 ] ; for ( success =
0 ; success < loop_ub ; success ++ ) { out -> data [ success ] = varargin_1
-> ByteOrder -> data [ success ] ; } if ( ganujgx1ii ( varargin_1 , out ) ) {
x_p = & rtB . iar4fhawbp [ 0 ] ; } memcpy ( ( void * ) & c . f1 [ 0 ] , (
void * ) & x_p [ 0 ] , ( uint32_T ) ( ( size_t ) 256 * sizeof ( uint8_T ) ) )
; if ( varargin_1 -> WriteAsync ) { obj_e = & varargin_1 -> AsyncIOChannel ->
OutputStream ; a = 0.0 ; h2 = 1.0 ; exitg2 = false ; while ( ( ! exitg2 ) &&
( a < 256.0 ) ) { streamImpl = obj_e -> StreamImpl ; success =
coderStreamGetSpaceAvailable ( streamImpl , & theta_ ) ; if ( success == 0 )
{ chImpl = coderStreamGetChannel ( streamImpl ) ; coderChannelHasSyncError (
chImpl , & hasSyncError ) ; if ( ! hasSyncError ) { coderChannelGetLastError
( chImpl , & errorID [ 0 ] , & errorText [ 0 ] ) ; } else {
coderChannelGetLastSyncError ( chImpl , & errorID [ 0 ] , & errorText [ 0 ] )
; } } guard1 = false ; if ( theta_ == 0.0 ) { fpycd4xlib4 ( obj_e ,
status_data , status_size ) ; if ( ! aygswycpr4 ( status_data , status_size )
) { exitg2 = true ; } else { guard1 = true ; } } else { guard1 = true ; } if
( guard1 ) { theta_ = 0.0 ; h = h2 ; loop_ub = 0 ; exitg3 = false ; while ( (
! exitg3 ) && ( loop_ub <= ( int32_T ) ( ( 1.0 - h2 ) + 1.0 ) - 1 ) ) {
streamImpl = obj_e -> StreamImpl ; success =
coderOutputStreamWriteTypedDataOld ( streamImpl , & Ct , 1 , "uint8" , 256 ,
& c . f1 [ 0 ] ) ; if ( success == 0 ) { chImpl = coderStreamGetChannel (
streamImpl ) ; coderChannelHasSyncError ( chImpl , & hasSyncError ) ; if ( !
hasSyncError ) { coderChannelGetLastError ( chImpl , & errorID [ 0 ] , &
errorText [ 0 ] ) ; } else { coderChannelGetLastSyncError ( chImpl , &
errorID [ 0 ] , & errorText [ 0 ] ) ; } } if ( Ct == 0.0 ) { exitg3 = true ;
} else { theta_ += Ct ; h ++ ; loop_ub ++ ; } } a += theta_ ; h2 = h ; } }
varargin_1 -> NumBytesWritten += a ; } else { obj_p = varargin_1 ->
AsyncIOChannel ; chImpl = obj_p -> ChannelImpl ; success =
coderChannelExecute ( chImpl , "Write" , 1 , "Data" , "uint8" , 256 , & c .
f1 [ 0 ] ) ; if ( success == 0 ) { coderChannelHasSyncError ( chImpl , &
hasSyncError ) ; if ( ! hasSyncError ) { coderChannelGetLastError ( chImpl ,
& errorID [ 0 ] , & errorText [ 0 ] ) ; } else { coderChannelGetLastSyncError
( chImpl , & errorID [ 0 ] , & errorText [ 0 ] ) ; } } obj_p = varargin_1 ->
AsyncIOChannel ; numBytesWritten = obj_p -> CustomProps .
LatestNumBytesWrittenToDevice ; chImpl = obj_p -> ChannelImpl ; success =
coderChannelGetPropertyValue ( chImpl , "LatestNumBytesWrittenToDevice" ,
"uint64" , 1 , & numBytesWritten ) ; if ( success == 0 ) {
coderChannelHasSyncError ( chImpl , & hasSyncError ) ; if ( ! hasSyncError )
{ coderChannelGetLastError ( chImpl , & errorID [ 0 ] , & errorText [ 0 ] ) ;
} else { coderChannelGetLastSyncError ( chImpl , & errorID [ 0 ] , &
errorText [ 0 ] ) ; } } varargin_1 -> NumBytesWritten += ( real_T )
numBytesWritten ; } praqpj5wy4 ( & obj -> AsyncIOChannel -> OutputStream ) ;
} lioe0t4jfb ( & out ) ; { if ( rtDW . mngvkp03ok . AQHandles &&
ssGetLogOutput ( rtS ) ) { sdiWriteSignal ( rtDW . mngvkp03ok . AQHandles ,
ssGetTaskTime ( rtS , 1 ) , ( char * ) & rtB . lonvbzqzr1 + 0 ) ; } } { if (
rtDW . bpkyyz2duh . AQHandles && ssGetLogOutput ( rtS ) ) { sdiWriteSignal (
rtDW . bpkyyz2duh . AQHandles , ssGetTaskTime ( rtS , 1 ) , ( char * ) & rtB
. a3plauwk5y + 0 ) ; } } } rtB . ha2jxgqr02 = rtB . etvoly05ch - rtP .
Constant_Value ; a3gzjtzg5m ( rtB . ha2jxgqr02 , & rtB . c5fiym5p0p ) ; if (
( rtDW . ha3ig5blsd >= ssGetT ( rtS ) ) && ( rtDW . pv2wfqzep2 >= ssGetT (
rtS ) ) ) { nwn55h0jth = 0.0 ; } else { h2 = rtDW . ha3ig5blsd ; lastU = &
rtDW . og3gej3jwz ; if ( rtDW . ha3ig5blsd < rtDW . pv2wfqzep2 ) { if ( rtDW
. pv2wfqzep2 < ssGetT ( rtS ) ) { h2 = rtDW . pv2wfqzep2 ; lastU = & rtDW .
lakc2myacn ; } } else if ( rtDW . ha3ig5blsd >= ssGetT ( rtS ) ) { h2 = rtDW
. pv2wfqzep2 ; lastU = & rtDW . lakc2myacn ; } nwn55h0jth = ( rtB .
c5fiym5p0p . fsek3luzie - * lastU ) / ( ssGetT ( rtS ) - h2 ) ; } g1ij20yo5c
( rtB . c5fiym5p0p . fsek3luzie , nwn55h0jth , rtP . open_AOAdegree_Value ,
rtP . close_AOAdegree_Value , & rtB . ixdl5r0pbu ) ; if ( rtB . ixdl5r0pbu .
jb2b5najpv == 1.0 ) { rtB . p4ublk43y4 = rtP . open_AOAdegree_Value ; } else
if ( rtB . ixdl5r0pbu . jb2b5najpv == 2.0 ) { rtB . p4ublk43y4 =
muDoubleScalarMin ( muDoubleScalarAsin ( ( muDoubleScalarSin ( rtP .
open_AOAdegree_Value * 3.1415926535897931 / 180.0 ) * 0.1 - ( 0.198 - rtB .
c5fiym5p0p . fsek3luzie ) ) / 0.1 ) * 180.0 / 3.1415926535897931 , rtP .
open_AOAdegree_Value ) ; } else if ( rtB . ixdl5r0pbu . jb2b5najpv == 3.0 ) {
rtB . p4ublk43y4 = rtP . close_AOAdegree_Value ; } else { rtB . p4ublk43y4 =
muDoubleScalarMax ( - muDoubleScalarAsin ( ( muDoubleScalarSin ( - rtP .
close_AOAdegree_Value * 3.1415926535897931 / 180.0 ) * 0.1 / 2.0 - rtB .
c5fiym5p0p . fsek3luzie ) / 0.05 ) * 180.0 / 3.1415926535897931 , rtP .
close_AOAdegree_Value ) ; } h1gj42rjt1 = rtP . Constant1_Value - rtB .
p4ublk43y4 ; jj2h00reln ( h1gj42rjt1 , & rtB . jsqwvo4npa ) ; if ( ( rtDW .
ohxmf4okd1 >= ssGetT ( rtS ) ) && ( rtDW . ovo4hnxxnn >= ssGetT ( rtS ) ) ) {
czl2hnisq2 = 0.0 ; } else { h2 = rtDW . ohxmf4okd1 ; lastU = & rtDW .
jhaog44chc ; if ( rtDW . ohxmf4okd1 < rtDW . ovo4hnxxnn ) { if ( rtDW .
ovo4hnxxnn < ssGetT ( rtS ) ) { h2 = rtDW . ovo4hnxxnn ; lastU = & rtDW .
hpm14ul0f3 ; } } else if ( rtDW . ohxmf4okd1 >= ssGetT ( rtS ) ) { h2 = rtDW
. ovo4hnxxnn ; lastU = & rtDW . hpm14ul0f3 ; } czl2hnisq2 = ( rtB .
p4ublk43y4 - * lastU ) / ( ssGetT ( rtS ) - h2 ) ; } if ( czl2hnisq2 > rtP .
Saturation_UpperSat_gxwe5io0f4 ) { h2 = rtP . Saturation_UpperSat_gxwe5io0f4
; } else if ( czl2hnisq2 < rtP . Saturation_LowerSat_ggci1m3fwr ) { h2 = rtP
. Saturation_LowerSat_ggci1m3fwr ; } else { h2 = czl2hnisq2 ; } rtB .
htcqv5fxtd = muDoubleScalarAbs ( h2 ) ; if ( ( rtDW . lkqen1tuni >= ssGetT (
rtS ) ) && ( rtDW . hiojixic5x >= ssGetT ( rtS ) ) ) { rtB . a43mlssova = 0.0
; } else { h2 = rtDW . lkqen1tuni ; lastU = & rtDW . ly5fhjl0pp ; if ( rtDW .
lkqen1tuni < rtDW . hiojixic5x ) { if ( rtDW . hiojixic5x < ssGetT ( rtS ) )
{ h2 = rtDW . hiojixic5x ; lastU = & rtDW . ps3do31sj3 ; } } else if ( rtDW .
lkqen1tuni >= ssGetT ( rtS ) ) { h2 = rtDW . hiojixic5x ; lastU = & rtDW .
ps3do31sj3 ; } rtB . a43mlssova = ( rtB . etvoly05ch - * lastU ) / ( ssGetT (
rtS ) - h2 ) ; } fyamgsybsv = muDoubleScalarAbs ( rtB . a43mlssova ) ;
jlcrjksjko ( rtB . jsqwvo4npa . n5nj1b05gf , rtB . htcqv5fxtd , fyamgsybsv ,
rtB . ixdl5r0pbu . jb2b5najpv , & rtB . fvmfewdhwz ) ; rtB . goi1oiwwan = rtB
. gkuq4mb5x4 - rtP . Constant_Value_ndti5ul2ir ; a3gzjtzg5m ( rtB .
goi1oiwwan , & rtB . dwjvl3kmbe ) ; if ( ( rtDW . mutemtyha2 >= ssGetT ( rtS
) ) && ( rtDW . frxhgtfui5 >= ssGetT ( rtS ) ) ) { hbk42ogwqv = 0.0 ; } else
{ h2 = rtDW . mutemtyha2 ; lastU = & rtDW . dhidrj0fdd ; if ( rtDW .
mutemtyha2 < rtDW . frxhgtfui5 ) { if ( rtDW . frxhgtfui5 < ssGetT ( rtS ) )
{ h2 = rtDW . frxhgtfui5 ; lastU = & rtDW . lrysnrlfpz ; } } else if ( rtDW .
mutemtyha2 >= ssGetT ( rtS ) ) { h2 = rtDW . frxhgtfui5 ; lastU = & rtDW .
lrysnrlfpz ; } hbk42ogwqv = ( rtB . dwjvl3kmbe . fsek3luzie - * lastU ) / (
ssGetT ( rtS ) - h2 ) ; } mjmlfjqs31 ( rtB . dwjvl3kmbe . fsek3luzie ,
hbk42ogwqv , rtP . open_AOAdegree_Value_puyaicdqcr , rtP .
close_AOAdegree_Value_h2ko2tzd3h , & rtB . ch5un3rjrb ) ; dtuuqh01ed ( rtB .
ch5un3rjrb . nf3awaueuw , rtB . dwjvl3kmbe . fsek3luzie , rtP .
open_AOAdegree_Value_puyaicdqcr , rtP . close_AOAdegree_Value_h2ko2tzd3h , &
rtB . dgjrsvf3r0 ) ; kge0hyy05m = rtP . Constant1_Value_gwfubws50w - rtB .
dgjrsvf3r0 . o5vabvlgjn ; jj2h00reln ( kge0hyy05m , & rtB . jdelhdqjdy ) ; if
( ( rtDW . fl21cmk5gk >= ssGetT ( rtS ) ) && ( rtDW . juomdslsik >= ssGetT (
rtS ) ) ) { nydfixtxb0 = 0.0 ; } else { h2 = rtDW . fl21cmk5gk ; lastU = &
rtDW . h4ow2pync3 ; if ( rtDW . fl21cmk5gk < rtDW . juomdslsik ) { if ( rtDW
. juomdslsik < ssGetT ( rtS ) ) { h2 = rtDW . juomdslsik ; lastU = & rtDW .
js0lpcxyrc ; } } else if ( rtDW . fl21cmk5gk >= ssGetT ( rtS ) ) { h2 = rtDW
. juomdslsik ; lastU = & rtDW . js0lpcxyrc ; } nydfixtxb0 = ( rtB .
dgjrsvf3r0 . o5vabvlgjn - * lastU ) / ( ssGetT ( rtS ) - h2 ) ; } if (
nydfixtxb0 > rtP . Saturation_UpperSat_nctbwbdtp3 ) { h2 = rtP .
Saturation_UpperSat_nctbwbdtp3 ; } else if ( nydfixtxb0 < rtP .
Saturation_LowerSat_khkejnf40e ) { h2 = rtP . Saturation_LowerSat_khkejnf40e
; } else { h2 = nydfixtxb0 ; } rtB . bzfi1eqihy = muDoubleScalarAbs ( h2 ) ;
if ( ( rtDW . e0edvudjse >= ssGetT ( rtS ) ) && ( rtDW . e13leb2tmm >= ssGetT
( rtS ) ) ) { rtB . k2tv1y1gn5 = 0.0 ; } else { h2 = rtDW . e0edvudjse ;
lastU = & rtDW . cmm1vcvsn0 ; if ( rtDW . e0edvudjse < rtDW . e13leb2tmm ) {
if ( rtDW . e13leb2tmm < ssGetT ( rtS ) ) { h2 = rtDW . e13leb2tmm ; lastU =
& rtDW . inoqsfj0bw ; } } else if ( rtDW . e0edvudjse >= ssGetT ( rtS ) ) {
h2 = rtDW . e13leb2tmm ; lastU = & rtDW . inoqsfj0bw ; } rtB . k2tv1y1gn5 = (
rtB . gkuq4mb5x4 - * lastU ) / ( ssGetT ( rtS ) - h2 ) ; } fzkgaahydo =
muDoubleScalarAbs ( rtB . k2tv1y1gn5 ) ; jlcrjksjko ( rtB . jdelhdqjdy .
n5nj1b05gf , rtB . bzfi1eqihy , fzkgaahydo , rtB . ch5un3rjrb . nf3awaueuw ,
& rtB . fisn2ndewy ) ; rtB . mfao3xhxn3 = rtB . fvmfewdhwz . hogtdrsbl0 + rtB
. fisn2ndewy . hogtdrsbl0 ; if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { { if (
rtDW . gwcnekeexx . AQHandles && ssGetLogOutput ( rtS ) ) { sdiWriteSignal (
rtDW . gwcnekeexx . AQHandles , ssGetTaskTime ( rtS , 1 ) , ( char * ) & rtB
. mfao3xhxn3 + 0 ) ; } } } rtB . hyhxikiti2 = l1phen4mok + rtB . f2cxkdl2mb .
hogtdrsbl0 ; if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { { if ( rtDW . jzk55zhlch
. AQHandles && ssGetLogOutput ( rtS ) ) { sdiWriteSignal ( rtDW . jzk55zhlch
. AQHandles , ssGetTaskTime ( rtS , 1 ) , ( char * ) & rtB . hyhxikiti2 + 0 )
; } } } if ( ssIsSampleHit ( rtS , 2 , 0 ) ) { obj_i = rtDW . hwcuhwqvaz .
TCPIPObj . TransportChannel ; obj_g = obj_i -> AsyncIOChannel ; chImpl =
obj_g -> ChannelImpl ; success = coderChannelIsOpen ( chImpl , & hasSyncError
) ; if ( success == 0 ) { coderChannelHasSyncError ( chImpl , & hasSyncError
) ; if ( ! hasSyncError ) { coderChannelGetLastError ( chImpl , & errorID [ 0
] , & errorText [ 0 ] ) ; } else { coderChannelGetLastSyncError ( chImpl , &
errorID [ 0 ] , & errorText [ 0 ] ) ; } } varargin_1_p = rtDW . hwcuhwqvaz .
TCPIPObj . TransportChannel ; obj_i = varargin_1_p ; pgkvysv3zg ( & rawData ,
2 ) ; rawData -> size [ 0 ] = 0 ; rawData -> size [ 1 ] = 0 ; theta_ =
guurnuuuj0 ( & varargin_1_p -> UnreadDataBuffer ) ; if ( theta_ >= 6.0 ) {
kphoq4rcnq ( varargin_1_p , 6.0 , rawData ) ; } else { theta_ = guurnuuuj0 (
& varargin_1_p -> UnreadDataBuffer ) ; a = 6.0 - theta_ ; hasEnoughData =
false ; idziggsqd5 ( & h2 , & h ) ; exitg2 = false ; while ( ( ! exitg2 ) &&
( lwekp2pixw ( h2 , h ) < obj_i -> AsyncIOChannel -> InputStream . Timeout )
) { obj_m = & obj_i -> AsyncIOChannel -> InputStream ; streamImpl_p = obj_m
-> StreamImpl ; success = coderStreamGetDataAvailable ( streamImpl_p , &
theta_ ) ; if ( success == 0 ) { chImpl = coderStreamGetChannel (
streamImpl_p ) ; coderChannelHasSyncError ( chImpl , & hasSyncError ) ; if (
! hasSyncError ) { coderChannelGetLastError ( chImpl , & errorID [ 0 ] , &
errorText [ 0 ] ) ; } else { coderChannelGetLastSyncError ( chImpl , &
errorID [ 0 ] , & errorText [ 0 ] ) ; } } theta_ += obj_m ->
PartialPacketCount ; if ( theta_ >= a ) { hasEnoughData = true ; exitg2 =
true ; } else { b_timespec . tv_sec = 0.0 ; b_timespec . tv_nsec = 1.0E+7 ;
coderTimeSleep ( & b_timespec ) ; } } if ( hasEnoughData ) { obj_m = & obj_i
-> AsyncIOChannel -> InputStream ; streamImpl_p = obj_m -> StreamImpl ;
success = coderStreamGetDataAvailable ( streamImpl_p , & theta_ ) ; if (
success == 0 ) { chImpl = coderStreamGetChannel ( streamImpl_p ) ;
coderChannelHasSyncError ( chImpl , & hasSyncError ) ; if ( ! hasSyncError )
{ coderChannelGetLastError ( chImpl , & errorID [ 0 ] , & errorText [ 0 ] ) ;
} else { coderChannelGetLastSyncError ( chImpl , & errorID [ 0 ] , &
errorText [ 0 ] ) ; } } theta_ += obj_m -> PartialPacketCount ; fp42yixhj2 (
& obj_i -> AsyncIOChannel -> InputStream , theta_ , rawData , & a ,
status_data , status_size ) ; ixxwtfu0ne ( & obj_i -> UnreadDataBuffer ,
rawData ) ; kphoq4rcnq ( obj_i , 6.0 , rawData ) ; } else if ( obj_i ->
AllowPartialReads ) { obj_m = & obj_i -> AsyncIOChannel -> InputStream ;
streamImpl_p = obj_m -> StreamImpl ; success = coderStreamGetDataAvailable (
streamImpl_p , & theta_ ) ; if ( success == 0 ) { chImpl =
coderStreamGetChannel ( streamImpl_p ) ; coderChannelHasSyncError ( chImpl ,
& hasSyncError ) ; if ( ! hasSyncError ) { coderChannelGetLastError ( chImpl
, & errorID [ 0 ] , & errorText [ 0 ] ) ; } else {
coderChannelGetLastSyncError ( chImpl , & errorID [ 0 ] , & errorText [ 0 ] )
; } } theta_ += obj_m -> PartialPacketCount ; if ( theta_ > 0.0 ) { obj_m = &
obj_i -> AsyncIOChannel -> InputStream ; streamImpl_p = obj_m -> StreamImpl ;
success = coderStreamGetDataAvailable ( streamImpl_p , & theta_ ) ; if (
success == 0 ) { chImpl = coderStreamGetChannel ( streamImpl_p ) ;
coderChannelHasSyncError ( chImpl , & hasSyncError ) ; if ( ! hasSyncError )
{ coderChannelGetLastError ( chImpl , & errorID [ 0 ] , & errorText [ 0 ] ) ;
} else { coderChannelGetLastSyncError ( chImpl , & errorID [ 0 ] , &
errorText [ 0 ] ) ; } } theta_ += obj_m -> PartialPacketCount ; pgkvysv3zg (
& b_rawData , 2 ) ; fp42yixhj2 ( & obj_i -> AsyncIOChannel -> InputStream ,
theta_ , b_rawData , & a , status_data , status_size ) ; ixxwtfu0ne ( & obj_i
-> UnreadDataBuffer , b_rawData ) ; dv5oz50wz1 ( & b_rawData ) ; } theta_ =
guurnuuuj0 ( & obj_i -> UnreadDataBuffer ) ; if ( theta_ > 0.0 ) { theta_ =
guurnuuuj0 ( & obj_i -> UnreadDataBuffer ) ; kphoq4rcnq ( obj_i ,
muDoubleScalarMin ( 6.0 , theta_ ) , rawData ) ; } } } pgkvysv3zg ( &
outputVal , 2 ) ; if ( ( rawData -> size [ 0 ] == 0 ) || ( rawData -> size [
1 ] == 0 ) ) { outputVal -> size [ 0 ] = 0 ; outputVal -> size [ 1 ] = 0 ; }
else { pgkvysv3zg ( & x , 2 ) ; success = x -> size [ 0 ] * x -> size [ 1 ] ;
x -> size [ 0 ] = 1 ; x -> size [ 1 ] = rawData -> size [ 1 ] ; kcbbxsln5r (
x , success ) ; loop_ub = rawData -> size [ 1 ] ; for ( success = 0 ; success
< loop_ub ; success ++ ) { x -> data [ success ] = rawData -> data [ rawData
-> size [ 0 ] * success ] ; } pgkvysv3zg ( & tempDataArray , 2 ) ; success =
tempDataArray -> size [ 0 ] * tempDataArray -> size [ 1 ] ; tempDataArray ->
size [ 0 ] = 1 ; tempDataArray -> size [ 1 ] = rawData -> size [ 1 ] ;
kcbbxsln5r ( tempDataArray , success ) ; memcpy ( ( void * ) & tempDataArray
-> data [ 0 ] , ( void * ) & x -> data [ 0 ] , ( uint32_T ) ( ( size_t )
rawData -> size [ 1 ] * sizeof ( uint8_T ) ) ) ; dv5oz50wz1 ( & x ) ; success
= outputVal -> size [ 0 ] * outputVal -> size [ 1 ] ; outputVal -> size [ 0 ]
= 1 ; outputVal -> size [ 1 ] = tempDataArray -> size [ 1 ] ; kcbbxsln5r (
outputVal , success ) ; loop_ub = tempDataArray -> size [ 1 ] ; memcpy ( &
outputVal -> data [ 0 ] , & tempDataArray -> data [ 0 ] , ( uint32_T )
loop_ub * sizeof ( uint8_T ) ) ; dv5oz50wz1 ( & tempDataArray ) ; }
dv5oz50wz1 ( & rawData ) ; for ( success = 0 ; success < 6 ; success ++ ) {
rtB . lpstap4ud2 [ success ] = outputVal -> data [ success ] ; } dv5oz50wz1 (
& outputVal ) ; ( void ) memcpy ( & rtB . ixgganvvtz , & rtB . lpstap4ud2 [ 0
] , 1 ) ; ( void ) memcpy ( & rtB . ktsgdw2c41 , & rtB . lpstap4ud2 [ 1 ] , 1
) ; ( void ) memcpy ( & rtB . mimixuazso , & rtB . lpstap4ud2 [ 2 ] , 1 ) ; (
void ) memcpy ( & rtB . jbdewy33ag , & rtB . lpstap4ud2 [ 3 ] , 1 ) ; ( void
) memcpy ( & rtB . jyujvnq2h1 , & rtB . lpstap4ud2 [ 4 ] , 1 ) ; ( void )
memcpy ( & rtB . kmzeugzpgl , & rtB . lpstap4ud2 [ 5 ] , 1 ) ; { SimStruct *
rts = ssGetSFunction ( rtS , 2 ) ; sfcnOutputs ( rts , 0 ) ; } { SimStruct *
rts = ssGetSFunction ( rtS , 3 ) ; sfcnOutputs ( rts , 0 ) ; } { SimStruct *
rts = ssGetSFunction ( rtS , 4 ) ; sfcnOutputs ( rts , 0 ) ; } { SimStruct *
rts = ssGetSFunction ( rtS , 5 ) ; sfcnOutputs ( rts , 0 ) ; } { SimStruct *
rts = ssGetSFunction ( rtS , 6 ) ; sfcnOutputs ( rts , 0 ) ; } { SimStruct *
rts = ssGetSFunction ( rtS , 7 ) ; sfcnOutputs ( rts , 0 ) ; } } if (
ssIsSampleHit ( rtS , 3 , 0 ) ) { rtB . hhfhv1g453 = rtP .
Output_Gain_kseoije4vl * rtDW . mkxeuv2wc4 * rtP . Gain1_Gain ; } if (
ssIsSampleHit ( rtS , 1 , 0 ) ) { pcqdvow2ge = ( dy1tpvtpxp + rtP .
FixPtConstant_Value ) & 1048575U ; if ( pcqdvow2ge > rtP .
WrapToZero_Threshold ) { rtB . otnxjer3d0 = rtP . Constant_Value_dsvukcvkuu ;
} else { rtB . otnxjer3d0 = pcqdvow2ge ; } } { real_T * * uBuffer = ( real_T
* * ) & rtDW . pqulut3liz . TUbufferPtrs [ 0 ] ; real_T simTime = ssGetT (
rtS ) ; real_T appliedDelay ; appliedDelay = rtP . a5_Value ; if (
appliedDelay > rtP . VariableTimeDelay1_MaxDelay ) { appliedDelay = rtP .
VariableTimeDelay1_MaxDelay ; } if ( appliedDelay < 0.0 ) { appliedDelay =
0.0 ; } rtB . pdvh3wfivp = rt_TDelayInterpolate ( simTime - appliedDelay ,
0.0 , * uBuffer , rtDW . mr2aud2zdd . CircularBufSize , & rtDW . mr2aud2zdd .
Last , rtDW . mr2aud2zdd . Tail , rtDW . mr2aud2zdd . Head , rtP .
VariableTimeDelay1_InitOutput , 1 , ( boolean_T ) ( ssIsMinorTimeStep ( rtS )
&& ( ( * uBuffer + rtDW . mr2aud2zdd . CircularBufSize ) [ rtDW . mr2aud2zdd
. Head ] == ssGetT ( rtS ) ) ) ) ; } if ( ssIsSampleHit ( rtS , 5 , 0 ) ) {
h2 = muDoubleScalarFloor ( ( 2.8421709430404007E-14 * rtB . pdvh3wfivp * rtP
. PWM_Period + rtB . pdvh3wfivp * rtP . PWM_Period ) / 5.0E-5 ) ; if (
muDoubleScalarIsNaN ( h2 ) || muDoubleScalarIsInf ( h2 ) ) { h2 = 0.0 ; }
else { h2 = muDoubleScalarRem ( h2 , 4.294967296E+9 ) ; } if ( ( ( ( h2 < 0.0
? ( uint32_T ) - ( int32_T ) ( uint32_T ) - h2 : ( uint32_T ) h2 ) == 0U ) ||
( rtB . pdvh3wfivp <= 0.0 ) ) && rtDW . ottvoj0yqy ) { rtB . n4zpljasue = 0.0
; rtDW . gvaglrbdot = false ; } else { rtB . n4zpljasue = rtDW . gvaglrbdot ;
} } { real_T * * uBuffer = ( real_T * * ) & rtDW . l24xckmdwx . TUbufferPtrs
[ 0 ] ; real_T simTime = ssGetT ( rtS ) ; real_T appliedDelay ; appliedDelay
= rtP . a5_Value ; if ( appliedDelay > rtP . VariableTimeDelay_MaxDelay ) {
appliedDelay = rtP . VariableTimeDelay_MaxDelay ; } if ( appliedDelay < 0.0 )
{ appliedDelay = 0.0 ; } rtB . m0wxbflasp = rt_TDelayInterpolate ( simTime -
appliedDelay , 0.0 , * uBuffer , rtDW . hmazbcxsfm . CircularBufSize , & rtDW
. hmazbcxsfm . Last , rtDW . hmazbcxsfm . Tail , rtDW . hmazbcxsfm . Head ,
rtP . VariableTimeDelay_InitOutput , 1 , ( boolean_T ) ( ssIsMinorTimeStep (
rtS ) && ( ( * uBuffer + rtDW . hmazbcxsfm . CircularBufSize ) [ rtDW .
hmazbcxsfm . Head ] == ssGetT ( rtS ) ) ) ) ; } if ( ssIsSampleHit ( rtS , 4
, 0 ) ) { h2 = muDoubleScalarFloor ( ( 2.8421709430404007E-14 * rtB .
m0wxbflasp * rtP . PWM1_Period + rtB . m0wxbflasp * rtP . PWM1_Period ) /
5.0E-5 ) ; if ( muDoubleScalarIsNaN ( h2 ) || muDoubleScalarIsInf ( h2 ) ) {
h2 = 0.0 ; } else { h2 = muDoubleScalarRem ( h2 , 4.294967296E+9 ) ; } if ( (
( ( h2 < 0.0 ? ( uint32_T ) - ( int32_T ) ( uint32_T ) - h2 : ( uint32_T ) h2
) == 0U ) || ( rtB . m0wxbflasp <= 0.0 ) ) && rtDW . hkguujkgog ) { rtB .
ipbondrkcl = 0.0 ; rtDW . ehbdlfy2zi = false ; } else { rtB . ipbondrkcl =
rtDW . ehbdlfy2zi ; } } if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { rtB .
jqaxfynhz3 = rtB . mjlpzkqz1n * rtB . n4zpljasue ; rtB . oqvlx0tggb = rtB .
mjlpzkqz1n * rtB . ipbondrkcl ; } if ( rtB . k2tv1y1gn5 > rtP .
Switch2_Threshold ) { h2 = rtP . a3_Value ; } else { h2 = rtP . a4_Value ; }
if ( rtB . a43mlssova > rtP . Switch3_Threshold ) { theta_ = rtP . a3_Value ;
} else { theta_ = rtP . a4_Value ; } rtB . klwp3o5znj = ( ( rtB . fn1r3pr3py
- ( ( ( ( muDoubleScalarCos ( rtP . Gain_Gain_oodfwwlgw5 * rtB . etvoly05ch )
* rtB . fvmfewdhwz . ayo4a0rtpb * rtB . fvmfewdhwz . hogtdrsbl0 +
muDoubleScalarCos ( rtP . Gain_Gain_gqjpcqg2pu * rtB . gkuq4mb5x4 ) * rtB .
fisn2ndewy . ayo4a0rtpb * rtB . fvmfewdhwz . hogtdrsbl0 ) + muDoubleScalarAbs
( muDoubleScalarCos ( rtB . btyuoi1co3 . d0v1fgzgtc ) * muDoubleScalarSin (
rtB . btyuoi1co3 . dxojvg2mzp ) * rtB . fisn2ndewy . etkpdfh3bw ) * h2 * rtP
. e_Value ) + muDoubleScalarAbs ( rtB . fvmfewdhwz . etkpdfh3bw *
muDoubleScalarCos ( rtB . ojl1qzu4tl . d0v1fgzgtc ) * muDoubleScalarSin ( rtB
. ojl1qzu4tl . dxojvg2mzp ) ) * theta_ * rtP . e_Value ) - rtB . hhfhv1g453 )
) - rtP . Gain_dcquyu5zec * meyaghcm42 ) * ( 1.0 / rtP . Value_mdbqjrgdok ) ;
if ( ssIsSampleHit ( rtS , 2 , 0 ) ) { m3cwp3vr0t = ( rtP . u_Gain_i3zbnwm4y2
* rtB . bkayq3jpfr + rtP . u_Gain_pqq0pxqop5 * rtB . arjieh1qz2 ) + rtB .
b0atyboa0x ; miejctwg5s = ( rtP . u_Gain_m2whdurejq * rtB . ov41nszkfe + rtP
. u_Gain_iw0b3pebia * rtB . ff3s1fh5wh ) + rtB . crmbrbsz2x ; } rtB .
omvc30ouxs = ( rtB . fvmfewdhwz . etkpdfh3bw * muDoubleScalarAbs (
muDoubleScalarCos ( rtB . ojl1qzu4tl . dxojvg2mzp ) ) * muDoubleScalarAbs (
muDoubleScalarCos ( rtB . ojl1qzu4tl . ftth4nxmgz ) ) + muDoubleScalarAbs (
muDoubleScalarCos ( rtB . btyuoi1co3 . dxojvg2mzp ) ) * muDoubleScalarAbs (
muDoubleScalarCos ( rtB . btyuoi1co3 . ftth4nxmgz ) ) * rtB . fisn2ndewy .
etkpdfh3bw ) * rtP . Gain_o44e2s1oov * rtP . _Gain_igqv4gz3am * rtP .
_Gain_ezpdmdm44b + rtP . Ncm_Value ; rtB . n0yzexgdyh = rtP .
_Gain_a2p4tfbpm4 * rtB . a3plauwk5y ; rtB . atbvn2nrjn = rtP .
_Gain_iaiof1ych2 * rtB . buugn1y4kg ; rtB . d3mqkoc1ln = rtP .
_Gain_ec3r4dr3zn * oyxofam2xe ; if ( ssIsSampleHit ( rtS , 1 , 0 ) ) { } rtB
. mnvxcylwkr = ( ( rtB . jqaxfynhz3 - rtP . _Gain_nwjfwxlfng * oyxofam2xe ) -
rtP . Gain_c5zyi33wrb * rtB . m0fvlyj223 ) * ( 1.0 / rtP . _Value ) ; rtB .
pgeeu4rvpl = ( ( rtP . _Gain_fl03d5u1kp * rtB . m0fvlyj223 - rtB . d3mqkoc1ln
) - rtB . omvc30ouxs ) * rtP . u_Gain_gp00rtkqtb * ( 1.0 / rtP . Value ) ;
rtB . aeq3t23mz4 = ( ( rtB . oqvlx0tggb - rtP . _Gain_ex1r0c12fd * hqku2g2u0k
) - rtP . Gain_jvjms1w3ad * rtB . facwgsdsd1 ) * ( 1.0 / rtP .
_Value_fcrkhd1pwn ) ; rtB . fywlqxnu4j = ( ( rtP . _Gain_lcqhixjq0z * rtB .
facwgsdsd1 - rtP . _Gain_ni4xvt1vxz * hqku2g2u0k ) - ( ( gol0mqxiqq *
muDoubleScalarAbs ( muDoubleScalarCos ( jolkdr5rbf ) ) * muDoubleScalarAbs (
muDoubleScalarCos ( jpanute2ig ) ) + rtB . f2cxkdl2mb . etkpdfh3bw *
muDoubleScalarAbs ( muDoubleScalarCos ( opny1a35qe ) ) * muDoubleScalarAbs (
muDoubleScalarCos ( aolrab3vsg ) ) ) * rtP . _Gain_ocd1v2y2wv * rtP .
_Gain_jqvyrpyhlw * rtP . _Gain_dq53dumoid + rtP . Ncm1_Value ) ) * rtP .
u_Gain_jngffoyzbc * ( 1.0 / rtP . Value_dfptlknwpi ) ; if ( ssIsSampleHit (
rtS , 2 , 0 ) ) { rtB . nzqgm2nb3k = rtP . u_Gain_nudgobpj1r * miejctwg5s ;
rtB . iewiqnu5gm = rtP . u_Gain_mdaasjyeq0 * m3cwp3vr0t ; } if (
ssIsSampleHit ( rtS , 1 , 0 ) ) { } UNUSED_PARAMETER ( tid ) ; } void
MdlOutputsTID6 ( int_T tid ) { UNUSED_PARAMETER ( tid ) ; } void MdlUpdate (
int_T tid ) { real_T dc ; real_T * lastU ; uint32_T numTicksToNextSampleHit ;
uint32_T totalTicksInPeriod ; SimStruct * S ; void * diag ; if (
ssIsSampleHit ( rtS , 1 , 0 ) ) { rtDW . jl0mnuibbh = rtB . otnxjer3d0 ; } if
( rtDW . l30tmqcnmm == ( rtInf ) ) { rtDW . l30tmqcnmm = ssGetT ( rtS ) ;
lastU = & rtDW . njuyqff5u5 ; } else if ( rtDW . iv3sxafqgs == ( rtInf ) ) {
rtDW . iv3sxafqgs = ssGetT ( rtS ) ; lastU = & rtDW . dahp1m1tnz ; } else if
( rtDW . l30tmqcnmm < rtDW . iv3sxafqgs ) { rtDW . l30tmqcnmm = ssGetT ( rtS
) ; lastU = & rtDW . njuyqff5u5 ; } else { rtDW . iv3sxafqgs = ssGetT ( rtS )
; lastU = & rtDW . dahp1m1tnz ; } * lastU = rtB . p2tfl52njg . fsek3luzie ;
if ( rtDW . egmxveifc2 == ( rtInf ) ) { rtDW . egmxveifc2 = ssGetT ( rtS ) ;
lastU = & rtDW . nyak4kxjb0 ; } else if ( rtDW . jrcajuutzs == ( rtInf ) ) {
rtDW . jrcajuutzs = ssGetT ( rtS ) ; lastU = & rtDW . bto3rz2afq ; } else if
( rtDW . egmxveifc2 < rtDW . jrcajuutzs ) { rtDW . egmxveifc2 = ssGetT ( rtS
) ; lastU = & rtDW . nyak4kxjb0 ; } else { rtDW . jrcajuutzs = ssGetT ( rtS )
; lastU = & rtDW . bto3rz2afq ; } * lastU = rtB . c1l0t1ppoz ; if ( rtDW .
l4a3zwvtji == ( rtInf ) ) { rtDW . l4a3zwvtji = ssGetT ( rtS ) ; lastU = &
rtDW . ecriaizrd0 ; } else if ( rtDW . evnfi3oakh == ( rtInf ) ) { rtDW .
evnfi3oakh = ssGetT ( rtS ) ; lastU = & rtDW . jqu0hns3uo ; } else if ( rtDW
. l4a3zwvtji < rtDW . evnfi3oakh ) { rtDW . l4a3zwvtji = ssGetT ( rtS ) ;
lastU = & rtDW . ecriaizrd0 ; } else { rtDW . evnfi3oakh = ssGetT ( rtS ) ;
lastU = & rtDW . jqu0hns3uo ; } * lastU = rtB . mqpvdapacf ; if ( rtDW .
ajtguqv0em == ( rtInf ) ) { rtDW . ajtguqv0em = ssGetT ( rtS ) ; lastU = &
rtDW . b42g2henkn ; } else if ( rtDW . omefgf0cmg == ( rtInf ) ) { rtDW .
omefgf0cmg = ssGetT ( rtS ) ; lastU = & rtDW . eo5jyafoo5 ; } else if ( rtDW
. ajtguqv0em < rtDW . omefgf0cmg ) { rtDW . ajtguqv0em = ssGetT ( rtS ) ;
lastU = & rtDW . b42g2henkn ; } else { rtDW . omefgf0cmg = ssGetT ( rtS ) ;
lastU = & rtDW . eo5jyafoo5 ; } * lastU = rtB . c21bk5qnit . fsek3luzie ; if
( rtDW . leiplki144 == ( rtInf ) ) { rtDW . leiplki144 = ssGetT ( rtS ) ;
lastU = & rtDW . g4ztp0b3on ; } else if ( rtDW . oujf1dobik == ( rtInf ) ) {
rtDW . oujf1dobik = ssGetT ( rtS ) ; lastU = & rtDW . pcv4wpi3ke ; } else if
( rtDW . leiplki144 < rtDW . oujf1dobik ) { rtDW . leiplki144 = ssGetT ( rtS
) ; lastU = & rtDW . g4ztp0b3on ; } else { rtDW . oujf1dobik = ssGetT ( rtS )
; lastU = & rtDW . pcv4wpi3ke ; } * lastU = rtB . elpvuejile . o5vabvlgjn ;
if ( rtDW . cbkkysibro == ( rtInf ) ) { rtDW . cbkkysibro = ssGetT ( rtS ) ;
lastU = & rtDW . akkonxbiyb ; } else if ( rtDW . e33if4mgu4 == ( rtInf ) ) {
rtDW . e33if4mgu4 = ssGetT ( rtS ) ; lastU = & rtDW . bkzeyuvdfi ; } else if
( rtDW . cbkkysibro < rtDW . e33if4mgu4 ) { rtDW . cbkkysibro = ssGetT ( rtS
) ; lastU = & rtDW . akkonxbiyb ; } else { rtDW . e33if4mgu4 = ssGetT ( rtS )
; lastU = & rtDW . bkzeyuvdfi ; } * lastU = rtB . e4k3uwbbqo ; if (
ssIsSampleHit ( rtS , 3 , 0 ) ) { rtDW . jsetdp311j =
rt_nrand_Upu32_Yd_f_pw_snf ( & rtDW . baqauvm4f0 ) * rtP . WhiteNoise_StdDev
+ rtP . WhiteNoise_Mean ; } if ( rtDW . ha3ig5blsd == ( rtInf ) ) { rtDW .
ha3ig5blsd = ssGetT ( rtS ) ; lastU = & rtDW . og3gej3jwz ; } else if ( rtDW
. pv2wfqzep2 == ( rtInf ) ) { rtDW . pv2wfqzep2 = ssGetT ( rtS ) ; lastU = &
rtDW . lakc2myacn ; } else if ( rtDW . ha3ig5blsd < rtDW . pv2wfqzep2 ) {
rtDW . ha3ig5blsd = ssGetT ( rtS ) ; lastU = & rtDW . og3gej3jwz ; } else {
rtDW . pv2wfqzep2 = ssGetT ( rtS ) ; lastU = & rtDW . lakc2myacn ; } * lastU
= rtB . c5fiym5p0p . fsek3luzie ; if ( rtDW . ohxmf4okd1 == ( rtInf ) ) {
rtDW . ohxmf4okd1 = ssGetT ( rtS ) ; lastU = & rtDW . jhaog44chc ; } else if
( rtDW . ovo4hnxxnn == ( rtInf ) ) { rtDW . ovo4hnxxnn = ssGetT ( rtS ) ;
lastU = & rtDW . hpm14ul0f3 ; } else if ( rtDW . ohxmf4okd1 < rtDW .
ovo4hnxxnn ) { rtDW . ohxmf4okd1 = ssGetT ( rtS ) ; lastU = & rtDW .
jhaog44chc ; } else { rtDW . ovo4hnxxnn = ssGetT ( rtS ) ; lastU = & rtDW .
hpm14ul0f3 ; } * lastU = rtB . p4ublk43y4 ; if ( rtDW . lkqen1tuni == ( rtInf
) ) { rtDW . lkqen1tuni = ssGetT ( rtS ) ; lastU = & rtDW . ly5fhjl0pp ; }
else if ( rtDW . hiojixic5x == ( rtInf ) ) { rtDW . hiojixic5x = ssGetT ( rtS
) ; lastU = & rtDW . ps3do31sj3 ; } else if ( rtDW . lkqen1tuni < rtDW .
hiojixic5x ) { rtDW . lkqen1tuni = ssGetT ( rtS ) ; lastU = & rtDW .
ly5fhjl0pp ; } else { rtDW . hiojixic5x = ssGetT ( rtS ) ; lastU = & rtDW .
ps3do31sj3 ; } * lastU = rtB . etvoly05ch ; if ( rtDW . mutemtyha2 == ( rtInf
) ) { rtDW . mutemtyha2 = ssGetT ( rtS ) ; lastU = & rtDW . dhidrj0fdd ; }
else if ( rtDW . frxhgtfui5 == ( rtInf ) ) { rtDW . frxhgtfui5 = ssGetT ( rtS
) ; lastU = & rtDW . lrysnrlfpz ; } else if ( rtDW . mutemtyha2 < rtDW .
frxhgtfui5 ) { rtDW . mutemtyha2 = ssGetT ( rtS ) ; lastU = & rtDW .
dhidrj0fdd ; } else { rtDW . frxhgtfui5 = ssGetT ( rtS ) ; lastU = & rtDW .
lrysnrlfpz ; } * lastU = rtB . dwjvl3kmbe . fsek3luzie ; if ( rtDW .
fl21cmk5gk == ( rtInf ) ) { rtDW . fl21cmk5gk = ssGetT ( rtS ) ; lastU = &
rtDW . h4ow2pync3 ; } else if ( rtDW . juomdslsik == ( rtInf ) ) { rtDW .
juomdslsik = ssGetT ( rtS ) ; lastU = & rtDW . js0lpcxyrc ; } else if ( rtDW
. fl21cmk5gk < rtDW . juomdslsik ) { rtDW . fl21cmk5gk = ssGetT ( rtS ) ;
lastU = & rtDW . h4ow2pync3 ; } else { rtDW . juomdslsik = ssGetT ( rtS ) ;
lastU = & rtDW . js0lpcxyrc ; } * lastU = rtB . dgjrsvf3r0 . o5vabvlgjn ; if
( rtDW . e0edvudjse == ( rtInf ) ) { rtDW . e0edvudjse = ssGetT ( rtS ) ;
lastU = & rtDW . cmm1vcvsn0 ; } else if ( rtDW . e13leb2tmm == ( rtInf ) ) {
rtDW . e13leb2tmm = ssGetT ( rtS ) ; lastU = & rtDW . inoqsfj0bw ; } else if
( rtDW . e0edvudjse < rtDW . e13leb2tmm ) { rtDW . e0edvudjse = ssGetT ( rtS
) ; lastU = & rtDW . cmm1vcvsn0 ; } else { rtDW . e13leb2tmm = ssGetT ( rtS )
; lastU = & rtDW . inoqsfj0bw ; } * lastU = rtB . gkuq4mb5x4 ; if (
ssIsSampleHit ( rtS , 3 , 0 ) ) { rtDW . mkxeuv2wc4 =
rt_nrand_Upu32_Yd_f_pw_snf ( & rtDW . eam5on10cp ) * rtP .
WhiteNoise_StdDev_iarpuhegie + rtP . WhiteNoise_Mean_cm2ydxtnvw ; } { real_T
* * uBuffer = ( real_T * * ) & rtDW . pqulut3liz . TUbufferPtrs [ 0 ] ; int
numBuffers = 2 ; real_T simTime = ssGetT ( rtS ) ; rtDW . mr2aud2zdd . Head =
( ( rtDW . mr2aud2zdd . Head < ( rtDW . mr2aud2zdd . CircularBufSize - 1 ) )
? ( rtDW . mr2aud2zdd . Head + 1 ) : 0 ) ; if ( rtDW . mr2aud2zdd . Head ==
rtDW . mr2aud2zdd . Tail ) { if ( ! rt_TDelayUpdateTailOrGrowBuf ( & rtDW .
mr2aud2zdd . CircularBufSize , & rtDW . mr2aud2zdd . Tail , & rtDW .
mr2aud2zdd . Head , & rtDW . mr2aud2zdd . Last , simTime - rtP .
VariableTimeDelay1_MaxDelay , uBuffer , ( boolean_T ) 0 , ( boolean_T ) 0 , &
rtDW . mr2aud2zdd . MaxNewBufSize ) ) { ssSetErrorStatus ( rtS ,
"vtdelay memory allocation error" ) ; return ; }
slsaSaveRawMemoryForSimTargetOP ( rtS ,
"air_part1_python2/Variable\nTime Delay1_TUbuffer0" , ( void * * ) ( &
uBuffer [ 0 ] ) , numBuffers * rtDW . mr2aud2zdd . CircularBufSize * sizeof (
real_T ) , ( NULL ) , ( NULL ) ) ; } ( * uBuffer + rtDW . mr2aud2zdd .
CircularBufSize ) [ rtDW . mr2aud2zdd . Head ] = simTime ; ( * uBuffer ) [
rtDW . mr2aud2zdd . Head ] = rtB . nzqgm2nb3k ; } if ( ssIsSampleHit ( rtS ,
5 , 0 ) ) { if ( rtDW . gvaglrbdot ) { dc = rtB . pdvh3wfivp ; if ( ( rtP .
PWM_Period < 0.0001 ) || ( muDoubleScalarIsNaN ( rtP . PWM_Period ) || ( rtP
. PWM_Period == ( rtInf ) ) ) ) { S = rtS ; diag = CreateDiagnosticAsVoidPtr
( "Simulink:blocks:InvInputPeriodForVPGDiscMode" , 4 , 3 ,
"air_part1_python2/PWM/Variable Pulse Generator" , 2 , rtP . PWM_Period , 2 ,
ssGetTaskTime ( rtS , 5 ) , 2 , 5.0E-5 ) ; rt_ssSet_slErrMsg ( S , diag ) ; }
if ( dc > 1.0 ) { dc = 1.0 ; if ( rtDW . dhockh40iz ) { S = rtS ; diag =
CreateDiagnosticAsVoidPtr ( "Simulink:blocks:warnDutyCycleGreaterThanOne" , 3
, 2 , ssGetTaskTime ( rtS , 5 ) , 2 , rtB . pdvh3wfivp , 3 ,
"air_part1_python2/PWM/Variable Pulse Generator" ) ;
rt_ssReportDiagnosticAsWarning ( S , diag ) ; rtDW . dhockh40iz = false ; } }
dc = muDoubleScalarFloor ( ( 2.2204460492503131E-16 * dc * rtP . PWM_Period +
dc * rtP . PWM_Period ) / 5.0E-5 ) ; if ( muDoubleScalarIsNaN ( dc ) ||
muDoubleScalarIsInf ( dc ) ) { dc = 0.0 ; } else { dc = muDoubleScalarRem (
dc , 4.294967296E+9 ) ; } numTicksToNextSampleHit = dc < 0.0 ? ( uint32_T ) -
( int32_T ) ( uint32_T ) - dc : ( uint32_T ) dc ; if (
numTicksToNextSampleHit <= 0U ) { S = rtS ; diag = CreateDiagnosticAsVoidPtr
( "Simulink:blocks:InvSamplingRateForVPG" , 5 , 3 ,
"air_part1_python2/PWM/Variable Pulse Generator" , 2 , 5.0E-5 , 2 , rtB .
pdvh3wfivp , 2 , rtP . PWM_Period , 2 , ssGetTaskTime ( rtS , 5 ) ) ;
rt_ssSet_slErrMsg ( S , diag ) ; } dc = muDoubleScalarFloor ( (
2.2204460492503131E-16 * rtP . PWM_Period + rtP . PWM_Period ) / 5.0E-5 ) ;
if ( muDoubleScalarIsNaN ( dc ) || muDoubleScalarIsInf ( dc ) ) { dc = 0.0 ;
} else { dc = muDoubleScalarRem ( dc , 4.294967296E+9 ) ; }
totalTicksInPeriod = dc < 0.0 ? ( uint32_T ) - ( int32_T ) ( uint32_T ) - dc
: ( uint32_T ) dc ; if ( numTicksToNextSampleHit < totalTicksInPeriod ) {
ssSetNumTicksToNextHitForControllableSampleTime ( rtS , 5 , ( real_T )
numTicksToNextSampleHit ) ; ; rtDW . gvaglrbdot = false ; rtDW . ottvoj0yqy =
false ; } else { ssSetNumTicksToNextHitForControllableSampleTime ( rtS , 5 ,
( real_T ) totalTicksInPeriod ) ; ; rtDW . gvaglrbdot = true ; rtDW .
ottvoj0yqy = true ; } rtDW . dzzfid2chy = totalTicksInPeriod -
numTicksToNextSampleHit ; } else { if ( rtDW . ottvoj0yqy ) { dc = rtB .
pdvh3wfivp ; if ( ( rtP . PWM_Period <= 0.0 ) || ( muDoubleScalarIsNaN ( rtP
. PWM_Period ) || ( rtP . PWM_Period == ( rtInf ) ) ) ) { S = rtS ; diag =
CreateDiagnosticAsVoidPtr ( "Simulink:blocks:InvInputPeriodForVPG" , 3 , 3 ,
"air_part1_python2/PWM/Variable Pulse Generator" , 2 , rtP . PWM_Period , 2 ,
ssGetTaskTime ( rtS , 5 ) ) ; rt_ssSet_slErrMsg ( S , diag ) ; } if ( ( dc <
0.0 ) && rtDW . cosaluxqrd ) { S = rtS ; diag = CreateDiagnosticAsVoidPtr (
"Simulink:blocks:warnDutyCycleLessThanZero" , 3 , 2 , ssGetTaskTime ( rtS , 5
) , 2 , rtB . pdvh3wfivp , 3 ,
"air_part1_python2/PWM/Variable Pulse Generator" ) ;
rt_ssReportDiagnosticAsWarning ( S , diag ) ; rtDW . cosaluxqrd = false ; }
dc = muDoubleScalarFloor ( ( 2.2204460492503131E-16 * rtP . PWM_Period + rtP
. PWM_Period ) / 5.0E-5 ) ; if ( muDoubleScalarIsNaN ( dc ) ||
muDoubleScalarIsInf ( dc ) ) { dc = 0.0 ; } else { dc = muDoubleScalarRem (
dc , 4.294967296E+9 ) ; } ssSetNumTicksToNextHitForControllableSampleTime (
rtS , 5 , ( real_T ) ( dc < 0.0 ? ( uint32_T ) - ( int32_T ) ( uint32_T ) -
dc : ( uint32_T ) dc ) ) ; ; } else if ( rtDW . dzzfid2chy > 0.0 ) {
ssSetNumTicksToNextHitForControllableSampleTime ( rtS , 5 , rtDW . dzzfid2chy
) ; ; } rtDW . gvaglrbdot = true ; rtDW . ottvoj0yqy = true ; } } { real_T *
* uBuffer = ( real_T * * ) & rtDW . l24xckmdwx . TUbufferPtrs [ 0 ] ; int
numBuffers = 2 ; real_T simTime = ssGetT ( rtS ) ; rtDW . hmazbcxsfm . Head =
( ( rtDW . hmazbcxsfm . Head < ( rtDW . hmazbcxsfm . CircularBufSize - 1 ) )
? ( rtDW . hmazbcxsfm . Head + 1 ) : 0 ) ; if ( rtDW . hmazbcxsfm . Head ==
rtDW . hmazbcxsfm . Tail ) { if ( ! rt_TDelayUpdateTailOrGrowBuf ( & rtDW .
hmazbcxsfm . CircularBufSize , & rtDW . hmazbcxsfm . Tail , & rtDW .
hmazbcxsfm . Head , & rtDW . hmazbcxsfm . Last , simTime - rtP .
VariableTimeDelay_MaxDelay , uBuffer , ( boolean_T ) 0 , ( boolean_T ) 0 , &
rtDW . hmazbcxsfm . MaxNewBufSize ) ) { ssSetErrorStatus ( rtS ,
"vtdelay memory allocation error" ) ; return ; }
slsaSaveRawMemoryForSimTargetOP ( rtS ,
"air_part1_python2/Variable\nTime Delay_TUbuffer0" , ( void * * ) ( & uBuffer
[ 0 ] ) , numBuffers * rtDW . hmazbcxsfm . CircularBufSize * sizeof ( real_T
) , ( NULL ) , ( NULL ) ) ; } ( * uBuffer + rtDW . hmazbcxsfm .
CircularBufSize ) [ rtDW . hmazbcxsfm . Head ] = simTime ; ( * uBuffer ) [
rtDW . hmazbcxsfm . Head ] = rtB . iewiqnu5gm ; } if ( ssIsSampleHit ( rtS ,
4 , 0 ) ) { if ( rtDW . ehbdlfy2zi ) { dc = rtB . m0wxbflasp ; if ( ( rtP .
PWM1_Period < 0.0001 ) || ( muDoubleScalarIsNaN ( rtP . PWM1_Period ) || (
rtP . PWM1_Period == ( rtInf ) ) ) ) { S = rtS ; diag =
CreateDiagnosticAsVoidPtr ( "Simulink:blocks:InvInputPeriodForVPGDiscMode" ,
4 , 3 , "air_part1_python2/PWM1/Variable Pulse Generator" , 2 , rtP .
PWM1_Period , 2 , ssGetTaskTime ( rtS , 4 ) , 2 , 5.0E-5 ) ;
rt_ssSet_slErrMsg ( S , diag ) ; } if ( dc > 1.0 ) { dc = 1.0 ; if ( rtDW .
nkmva5gdkf ) { S = rtS ; diag = CreateDiagnosticAsVoidPtr (
"Simulink:blocks:warnDutyCycleGreaterThanOne" , 3 , 2 , ssGetTaskTime ( rtS ,
4 ) , 2 , rtB . m0wxbflasp , 3 ,
"air_part1_python2/PWM1/Variable Pulse Generator" ) ;
rt_ssReportDiagnosticAsWarning ( S , diag ) ; rtDW . nkmva5gdkf = false ; } }
dc = muDoubleScalarFloor ( ( 2.2204460492503131E-16 * dc * rtP . PWM1_Period
+ dc * rtP . PWM1_Period ) / 5.0E-5 ) ; if ( muDoubleScalarIsNaN ( dc ) ||
muDoubleScalarIsInf ( dc ) ) { dc = 0.0 ; } else { dc = muDoubleScalarRem (
dc , 4.294967296E+9 ) ; } numTicksToNextSampleHit = dc < 0.0 ? ( uint32_T ) -
( int32_T ) ( uint32_T ) - dc : ( uint32_T ) dc ; if (
numTicksToNextSampleHit <= 0U ) { S = rtS ; diag = CreateDiagnosticAsVoidPtr
( "Simulink:blocks:InvSamplingRateForVPG" , 5 , 3 ,
"air_part1_python2/PWM1/Variable Pulse Generator" , 2 , 5.0E-5 , 2 , rtB .
m0wxbflasp , 2 , rtP . PWM1_Period , 2 , ssGetTaskTime ( rtS , 4 ) ) ;
rt_ssSet_slErrMsg ( S , diag ) ; } dc = muDoubleScalarFloor ( (
2.2204460492503131E-16 * rtP . PWM1_Period + rtP . PWM1_Period ) / 5.0E-5 ) ;
if ( muDoubleScalarIsNaN ( dc ) || muDoubleScalarIsInf ( dc ) ) { dc = 0.0 ;
} else { dc = muDoubleScalarRem ( dc , 4.294967296E+9 ) ; }
totalTicksInPeriod = dc < 0.0 ? ( uint32_T ) - ( int32_T ) ( uint32_T ) - dc
: ( uint32_T ) dc ; if ( numTicksToNextSampleHit < totalTicksInPeriod ) {
ssSetNumTicksToNextHitForControllableSampleTime ( rtS , 4 , ( real_T )
numTicksToNextSampleHit ) ; ; rtDW . ehbdlfy2zi = false ; rtDW . hkguujkgog =
false ; } else { ssSetNumTicksToNextHitForControllableSampleTime ( rtS , 4 ,
( real_T ) totalTicksInPeriod ) ; ; rtDW . ehbdlfy2zi = true ; rtDW .
hkguujkgog = true ; } rtDW . iz0phm120z = totalTicksInPeriod -
numTicksToNextSampleHit ; } else { if ( rtDW . hkguujkgog ) { dc = rtB .
m0wxbflasp ; if ( ( rtP . PWM1_Period <= 0.0 ) || ( muDoubleScalarIsNaN ( rtP
. PWM1_Period ) || ( rtP . PWM1_Period == ( rtInf ) ) ) ) { S = rtS ; diag =
CreateDiagnosticAsVoidPtr ( "Simulink:blocks:InvInputPeriodForVPG" , 3 , 3 ,
"air_part1_python2/PWM1/Variable Pulse Generator" , 2 , rtP . PWM1_Period , 2
, ssGetTaskTime ( rtS , 4 ) ) ; rt_ssSet_slErrMsg ( S , diag ) ; } if ( ( dc
< 0.0 ) && rtDW . k043rv4keo ) { S = rtS ; diag = CreateDiagnosticAsVoidPtr (
"Simulink:blocks:warnDutyCycleLessThanZero" , 3 , 2 , ssGetTaskTime ( rtS , 4
) , 2 , rtB . m0wxbflasp , 3 ,
"air_part1_python2/PWM1/Variable Pulse Generator" ) ;
rt_ssReportDiagnosticAsWarning ( S , diag ) ; rtDW . k043rv4keo = false ; }
dc = muDoubleScalarFloor ( ( 2.2204460492503131E-16 * rtP . PWM1_Period + rtP
. PWM1_Period ) / 5.0E-5 ) ; if ( muDoubleScalarIsNaN ( dc ) ||
muDoubleScalarIsInf ( dc ) ) { dc = 0.0 ; } else { dc = muDoubleScalarRem (
dc , 4.294967296E+9 ) ; } ssSetNumTicksToNextHitForControllableSampleTime (
rtS , 4 , ( real_T ) ( dc < 0.0 ? ( uint32_T ) - ( int32_T ) ( uint32_T ) -
dc : ( uint32_T ) dc ) ) ; ; } else if ( rtDW . iz0phm120z > 0.0 ) {
ssSetNumTicksToNextHitForControllableSampleTime ( rtS , 4 , rtDW . iz0phm120z
) ; ; } rtDW . ehbdlfy2zi = true ; rtDW . hkguujkgog = true ; } }
UNUSED_PARAMETER ( tid ) ; } void MdlUpdateTID6 ( int_T tid ) {
UNUSED_PARAMETER ( tid ) ; } void MdlDerivatives ( void ) { XDot * _rtXdot ;
_rtXdot = ( ( XDot * ) ssGetdX ( rtS ) ) ; _rtXdot -> eypdcundes = rtB .
pgeeu4rvpl ; _rtXdot -> lh2zlfy5gs = rtB . mnvxcylwkr ; _rtXdot -> o2miuctf5t
= rtB . n0yzexgdyh ; _rtXdot -> g1kxrlwt1c = rtB . firups0wj2 ; _rtXdot ->
m0ift0f3ns = rtB . klwp3o5znj ; _rtXdot -> lq2uwsqwxu = rtB . atbvn2nrjn ;
_rtXdot -> fl2s00rq4n = rtB . fywlqxnu4j ; _rtXdot -> cb0w3bhvxx = rtB .
aeq3t23mz4 ; { } { } } void MdlProjection ( void ) { } void MdlTerminate (
void ) { CoderChannel chImpl ; ax0y0tfz0l * obj_b ; ax0y0tfz0lj * obj_g ;
e4wb5cpnqg * obj_m ; g1hz5apriq * obj_f ; g1hz5apriqr * obj_p ; hscjo2zzvm *
obj_c ; hscjo2zzvmb * obj_e ; kwgo0x2v41 * obj_k ; kwgo0x2v41z * obj_i ;
ovagoamv4w * obj_j ; ovagoamv4wz * obj ; int32_T success ; char_T errorID [
1024 ] ; char_T errorText [ 1024 ] ; boolean_T hasSyncError ; boolean_T
result ; { SimStruct * rts = ssGetSFunction ( rtS , 0 ) ; sfcnTerminate ( rts
) ; } { SimStruct * rts = ssGetSFunction ( rtS , 1 ) ; sfcnTerminate ( rts )
; } if ( ! rtDW . bvsrcp4u0i . matlabCodegenIsDeleted ) { rtDW . bvsrcp4u0i .
matlabCodegenIsDeleted = true ; if ( ( rtDW . bvsrcp4u0i . isInitialized == 1
) && rtDW . bvsrcp4u0i . isSetupComplete ) { ncc2f0srjcu0 ( rtDW . bvsrcp4u0i
. TCPIPObj . AsyncIOChannel ) ; } } obj = & rtDW . bvsrcp4u0i . TCPIPObj ; if
( ! obj -> matlabCodegenIsDeleted ) { obj -> matlabCodegenIsDeleted = true ;
ncc2f0srjcu0 ( obj -> AsyncIOChannel ) ; } obj_p = & rtDW . bvsrcp4u0i .
TCPIPObj . _pobj0 ; if ( ! obj_p -> matlabCodegenIsDeleted ) { obj_p ->
matlabCodegenIsDeleted = true ; ncc2f0srjcu0z ( & obj_p -> UnreadDataBuffer )
; } obj_e = & rtDW . bvsrcp4u0i . TCPIPObj . _pobj0 . UnreadDataBuffer ; if (
! obj_e -> matlabCodegenIsDeleted ) { obj_e -> matlabCodegenIsDeleted = true
; chImpl = obj_e -> ChannelImpl ; success = coderChannelIsOpen ( chImpl , &
result ) ; if ( success == 0 ) { coderChannelHasSyncError ( chImpl , &
hasSyncError ) ; if ( ! hasSyncError ) { coderChannelGetLastError ( chImpl ,
& errorID [ 0 ] , & errorText [ 0 ] ) ; } else { coderChannelGetLastSyncError
( chImpl , & errorID [ 0 ] , & errorText [ 0 ] ) ; } } if ( result ) {
ncc2f0srjcu0z ( obj_e ) ; } if ( ! ( obj_e -> ChannelImpl == 0 ) ) { chImpl =
obj_e -> ChannelImpl ; success = coderChannelIsOpen ( chImpl , & result ) ;
if ( success == 0 ) { coderChannelHasSyncError ( chImpl , & hasSyncError ) ;
if ( ! hasSyncError ) { coderChannelGetLastError ( chImpl , & errorID [ 0 ] ,
& errorText [ 0 ] ) ; } else { coderChannelGetLastSyncError ( chImpl , &
errorID [ 0 ] , & errorText [ 0 ] ) ; } } if ( result ) { ncc2f0srjcu0z (
obj_e ) ; } chImpl = obj_e -> ChannelImpl ; success = coderChannelTerm (
chImpl ) ; if ( success == 0 ) { coderChannelHasSyncError ( chImpl , &
hasSyncError ) ; if ( ! hasSyncError ) { coderChannelGetLastError ( chImpl ,
& errorID [ 0 ] , & errorText [ 0 ] ) ; } else { coderChannelGetLastSyncError
( chImpl , & errorID [ 0 ] , & errorText [ 0 ] ) ; } } chImpl = obj_e ->
ChannelImpl ; coderChannelDestroy ( chImpl ) ; obj_e -> ChannelImpl = 0 ; } }
obj_i = & rtDW . bvsrcp4u0i . TCPIPObj . _pobj1 ; if ( ! obj_i ->
matlabCodegenIsDeleted ) { obj_i -> matlabCodegenIsDeleted = true ; if ( ! (
obj_i -> ChannelImpl == 0 ) ) { chImpl = obj_i -> ChannelImpl ; success =
coderChannelIsOpen ( chImpl , & result ) ; if ( success == 0 ) {
coderChannelHasSyncError ( chImpl , & hasSyncError ) ; if ( ! hasSyncError )
{ coderChannelGetLastError ( chImpl , & errorID [ 0 ] , & errorText [ 0 ] ) ;
} else { coderChannelGetLastSyncError ( chImpl , & errorID [ 0 ] , &
errorText [ 0 ] ) ; } } if ( result ) { ncc2f0srjcu0 ( obj_i ) ; } chImpl =
obj_i -> ChannelImpl ; success = coderChannelTerm ( chImpl ) ; if ( success
== 0 ) { coderChannelHasSyncError ( chImpl , & hasSyncError ) ; if ( !
hasSyncError ) { coderChannelGetLastError ( chImpl , & errorID [ 0 ] , &
errorText [ 0 ] ) ; } else { coderChannelGetLastSyncError ( chImpl , &
errorID [ 0 ] , & errorText [ 0 ] ) ; } } chImpl = obj_i -> ChannelImpl ;
coderChannelDestroy ( chImpl ) ; obj_i -> ChannelImpl = 0 ; } } obj_m = &
rtDW . bvsrcp4u0i . TCPIPObj . _pobj0 . UnreadDataBuffer . OutputStream ; if
( ! obj_m -> matlabCodegenIsDeleted ) { obj_m -> matlabCodegenIsDeleted =
true ; } obj_m = & rtDW . bvsrcp4u0i . TCPIPObj . _pobj1 . OutputStream ; if
( ! obj_m -> matlabCodegenIsDeleted ) { obj_m -> matlabCodegenIsDeleted =
true ; } obj_g = & rtDW . bvsrcp4u0i . TCPIPObj . _pobj0 . UnreadDataBuffer .
InputStream ; if ( ! obj_g -> matlabCodegenIsDeleted ) { obj_g ->
matlabCodegenIsDeleted = true ; } obj_g = & rtDW . bvsrcp4u0i . TCPIPObj .
_pobj1 . InputStream ; if ( ! obj_g -> matlabCodegenIsDeleted ) { obj_g ->
matlabCodegenIsDeleted = true ; } kwd3nombnh ( & rtDW . bvsrcp4u0i ) ; if ( !
rtDW . hwcuhwqvaz . matlabCodegenIsDeleted ) { rtDW . hwcuhwqvaz .
matlabCodegenIsDeleted = true ; if ( ( rtDW . hwcuhwqvaz . isInitialized == 1
) && rtDW . hwcuhwqvaz . isSetupComplete ) { ncc2f0srjc ( rtDW . hwcuhwqvaz .
TCPIPObj . AsyncIOChannel ) ; } } obj_j = & rtDW . hwcuhwqvaz . TCPIPObj ; if
( ! obj_j -> matlabCodegenIsDeleted ) { obj_j -> matlabCodegenIsDeleted =
true ; ncc2f0srjc ( obj_j -> AsyncIOChannel ) ; } obj_f = & rtDW . hwcuhwqvaz
. TCPIPObj . _pobj0 ; if ( ! obj_f -> matlabCodegenIsDeleted ) { obj_f ->
matlabCodegenIsDeleted = true ; ncc2f0srjcu ( & obj_f -> UnreadDataBuffer ) ;
} obj_c = & rtDW . hwcuhwqvaz . TCPIPObj . _pobj0 . UnreadDataBuffer ; if ( !
obj_c -> matlabCodegenIsDeleted ) { obj_c -> matlabCodegenIsDeleted = true ;
chImpl = obj_c -> ChannelImpl ; success = coderChannelIsOpen ( chImpl , &
result ) ; if ( success == 0 ) { coderChannelHasSyncError ( chImpl , &
hasSyncError ) ; if ( ! hasSyncError ) { coderChannelGetLastError ( chImpl ,
& errorID [ 0 ] , & errorText [ 0 ] ) ; } else { coderChannelGetLastSyncError
( chImpl , & errorID [ 0 ] , & errorText [ 0 ] ) ; } } if ( result ) {
ncc2f0srjcu ( obj_c ) ; } if ( ! ( obj_c -> ChannelImpl == 0 ) ) { chImpl =
obj_c -> ChannelImpl ; success = coderChannelIsOpen ( chImpl , & result ) ;
if ( success == 0 ) { coderChannelHasSyncError ( chImpl , & hasSyncError ) ;
if ( ! hasSyncError ) { coderChannelGetLastError ( chImpl , & errorID [ 0 ] ,
& errorText [ 0 ] ) ; } else { coderChannelGetLastSyncError ( chImpl , &
errorID [ 0 ] , & errorText [ 0 ] ) ; } } if ( result ) { ncc2f0srjcu ( obj_c
) ; } chImpl = obj_c -> ChannelImpl ; success = coderChannelTerm ( chImpl ) ;
if ( success == 0 ) { coderChannelHasSyncError ( chImpl , & hasSyncError ) ;
if ( ! hasSyncError ) { coderChannelGetLastError ( chImpl , & errorID [ 0 ] ,
& errorText [ 0 ] ) ; } else { coderChannelGetLastSyncError ( chImpl , &
errorID [ 0 ] , & errorText [ 0 ] ) ; } } chImpl = obj_c -> ChannelImpl ;
coderChannelDestroy ( chImpl ) ; obj_c -> ChannelImpl = 0 ; } } obj_k = &
rtDW . hwcuhwqvaz . TCPIPObj . _pobj1 ; if ( ! obj_k ->
matlabCodegenIsDeleted ) { obj_k -> matlabCodegenIsDeleted = true ; if ( ! (
obj_k -> ChannelImpl == 0 ) ) { chImpl = obj_k -> ChannelImpl ; success =
coderChannelIsOpen ( chImpl , & result ) ; if ( success == 0 ) {
coderChannelHasSyncError ( chImpl , & hasSyncError ) ; if ( ! hasSyncError )
{ coderChannelGetLastError ( chImpl , & errorID [ 0 ] , & errorText [ 0 ] ) ;
} else { coderChannelGetLastSyncError ( chImpl , & errorID [ 0 ] , &
errorText [ 0 ] ) ; } } if ( result ) { ncc2f0srjc ( obj_k ) ; } chImpl =
obj_k -> ChannelImpl ; success = coderChannelTerm ( chImpl ) ; if ( success
== 0 ) { coderChannelHasSyncError ( chImpl , & hasSyncError ) ; if ( !
hasSyncError ) { coderChannelGetLastError ( chImpl , & errorID [ 0 ] , &
errorText [ 0 ] ) ; } else { coderChannelGetLastSyncError ( chImpl , &
errorID [ 0 ] , & errorText [ 0 ] ) ; } } chImpl = obj_k -> ChannelImpl ;
coderChannelDestroy ( chImpl ) ; obj_k -> ChannelImpl = 0 ; } } obj_m = &
rtDW . hwcuhwqvaz . TCPIPObj . _pobj0 . UnreadDataBuffer . OutputStream ; if
( ! obj_m -> matlabCodegenIsDeleted ) { obj_m -> matlabCodegenIsDeleted =
true ; } obj_m = & rtDW . hwcuhwqvaz . TCPIPObj . _pobj1 . OutputStream ; if
( ! obj_m -> matlabCodegenIsDeleted ) { obj_m -> matlabCodegenIsDeleted =
true ; } obj_b = & rtDW . hwcuhwqvaz . TCPIPObj . _pobj0 . UnreadDataBuffer .
InputStream ; if ( ! obj_b -> matlabCodegenIsDeleted ) { obj_b ->
matlabCodegenIsDeleted = true ; } obj_b = & rtDW . hwcuhwqvaz . TCPIPObj .
_pobj1 . InputStream ; if ( ! obj_b -> matlabCodegenIsDeleted ) { obj_b ->
matlabCodegenIsDeleted = true ; } kwd3nombnhc ( & rtDW . hwcuhwqvaz ) ; {
SimStruct * rts = ssGetSFunction ( rtS , 2 ) ; sfcnTerminate ( rts ) ; } {
SimStruct * rts = ssGetSFunction ( rtS , 3 ) ; sfcnTerminate ( rts ) ; } {
SimStruct * rts = ssGetSFunction ( rtS , 4 ) ; sfcnTerminate ( rts ) ; } {
SimStruct * rts = ssGetSFunction ( rtS , 5 ) ; sfcnTerminate ( rts ) ; } {
SimStruct * rts = ssGetSFunction ( rtS , 6 ) ; sfcnTerminate ( rts ) ; } {
SimStruct * rts = ssGetSFunction ( rtS , 7 ) ; sfcnTerminate ( rts ) ; }
rt_TDelayFreeBuf ( rtDW . pqulut3liz . TUbufferPtrs [ 0 ] ) ;
rt_TDelayFreeBuf ( rtDW . l24xckmdwx . TUbufferPtrs [ 0 ] ) ; { if ( rtDW .
mngvkp03ok . AQHandles ) { sdiTerminateStreaming ( & rtDW . mngvkp03ok .
AQHandles ) ; } } { if ( rtDW . bpkyyz2duh . AQHandles ) {
sdiTerminateStreaming ( & rtDW . bpkyyz2duh . AQHandles ) ; } } { if ( rtDW .
gwcnekeexx . AQHandles ) { sdiTerminateStreaming ( & rtDW . gwcnekeexx .
AQHandles ) ; } } { if ( rtDW . jzk55zhlch . AQHandles ) {
sdiTerminateStreaming ( & rtDW . jzk55zhlch . AQHandles ) ; } } } static void
mr_air_part1_python2_cacheDataAsMxArray ( mxArray * destArray , mwIndex i ,
int j , const void * srcData , size_t numBytes ) ; static void
mr_air_part1_python2_cacheDataAsMxArray ( mxArray * destArray , mwIndex i ,
int j , const void * srcData , size_t numBytes ) { mxArray * newArray =
mxCreateUninitNumericMatrix ( ( size_t ) 1 , numBytes , mxUINT8_CLASS ,
mxREAL ) ; memcpy ( ( uint8_T * ) mxGetData ( newArray ) , ( const uint8_T *
) srcData , numBytes ) ; mxSetFieldByNumber ( destArray , i , j , newArray )
; } static void mr_air_part1_python2_restoreDataFromMxArray ( void * destData
, const mxArray * srcArray , mwIndex i , int j , size_t numBytes ) ; static
void mr_air_part1_python2_restoreDataFromMxArray ( void * destData , const
mxArray * srcArray , mwIndex i , int j , size_t numBytes ) { memcpy ( (
uint8_T * ) destData , ( const uint8_T * ) mxGetData ( mxGetFieldByNumber (
srcArray , i , j ) ) , numBytes ) ; } static void
mr_air_part1_python2_cacheBitFieldToMxArray ( mxArray * destArray , mwIndex i
, int j , uint_T bitVal ) ; static void
mr_air_part1_python2_cacheBitFieldToMxArray ( mxArray * destArray , mwIndex i
, int j , uint_T bitVal ) { mxSetFieldByNumber ( destArray , i , j ,
mxCreateDoubleScalar ( ( double ) bitVal ) ) ; } static uint_T
mr_air_part1_python2_extractBitFieldFromMxArray ( const mxArray * srcArray ,
mwIndex i , int j , uint_T numBits ) ; static uint_T
mr_air_part1_python2_extractBitFieldFromMxArray ( const mxArray * srcArray ,
mwIndex i , int j , uint_T numBits ) { const uint_T varVal = ( uint_T )
mxGetScalar ( mxGetFieldByNumber ( srcArray , i , j ) ) ; return varVal & ( (
1u << numBits ) - 1u ) ; } static void
mr_air_part1_python2_cacheDataToMxArrayWithOffset ( mxArray * destArray ,
mwIndex i , int j , mwIndex offset , const void * srcData , size_t numBytes )
; static void mr_air_part1_python2_cacheDataToMxArrayWithOffset ( mxArray *
destArray , mwIndex i , int j , mwIndex offset , const void * srcData ,
size_t numBytes ) { uint8_T * varData = ( uint8_T * ) mxGetData (
mxGetFieldByNumber ( destArray , i , j ) ) ; memcpy ( ( uint8_T * ) & varData
[ offset * numBytes ] , ( const uint8_T * ) srcData , numBytes ) ; } static
void mr_air_part1_python2_restoreDataFromMxArrayWithOffset ( void * destData
, const mxArray * srcArray , mwIndex i , int j , mwIndex offset , size_t
numBytes ) ; static void
mr_air_part1_python2_restoreDataFromMxArrayWithOffset ( void * destData ,
const mxArray * srcArray , mwIndex i , int j , mwIndex offset , size_t
numBytes ) { const uint8_T * varData = ( const uint8_T * ) mxGetData (
mxGetFieldByNumber ( srcArray , i , j ) ) ; memcpy ( ( uint8_T * ) destData ,
( const uint8_T * ) & varData [ offset * numBytes ] , numBytes ) ; } static
void mr_air_part1_python2_cacheBitFieldToCellArrayWithOffset ( mxArray *
destArray , mwIndex i , int j , mwIndex offset , uint_T fieldVal ) ; static
void mr_air_part1_python2_cacheBitFieldToCellArrayWithOffset ( mxArray *
destArray , mwIndex i , int j , mwIndex offset , uint_T fieldVal ) {
mxSetCell ( mxGetFieldByNumber ( destArray , i , j ) , offset ,
mxCreateDoubleScalar ( ( double ) fieldVal ) ) ; } static uint_T
mr_air_part1_python2_extractBitFieldFromCellArrayWithOffset ( const mxArray *
srcArray , mwIndex i , int j , mwIndex offset , uint_T numBits ) ; static
uint_T mr_air_part1_python2_extractBitFieldFromCellArrayWithOffset ( const
mxArray * srcArray , mwIndex i , int j , mwIndex offset , uint_T numBits ) {
const uint_T fieldVal = ( uint_T ) mxGetScalar ( mxGetCell (
mxGetFieldByNumber ( srcArray , i , j ) , offset ) ) ; return fieldVal & ( (
1u << numBits ) - 1u ) ; } mxArray * mr_air_part1_python2_GetDWork ( ) {
static const char * ssDWFieldNames [ 3 ] = { "rtB" , "rtDW" , "NULL_PrevZCX"
, } ; mxArray * ssDW = mxCreateStructMatrix ( 1 , 1 , 3 , ssDWFieldNames ) ;
mr_air_part1_python2_cacheDataAsMxArray ( ssDW , 0 , 0 , ( const void * ) & (
rtB ) , sizeof ( rtB ) ) ; { static const char * rtdwDataFieldNames [ 86 ] =
{ "rtDW.hwcuhwqvaz" , "rtDW.bvsrcp4u0i" , "rtDW.l30tmqcnmm" ,
"rtDW.njuyqff5u5" , "rtDW.iv3sxafqgs" , "rtDW.dahp1m1tnz" , "rtDW.egmxveifc2"
, "rtDW.nyak4kxjb0" , "rtDW.jrcajuutzs" , "rtDW.bto3rz2afq" ,
"rtDW.l4a3zwvtji" , "rtDW.ecriaizrd0" , "rtDW.evnfi3oakh" , "rtDW.jqu0hns3uo"
, "rtDW.ajtguqv0em" , "rtDW.b42g2henkn" , "rtDW.omefgf0cmg" ,
"rtDW.eo5jyafoo5" , "rtDW.leiplki144" , "rtDW.g4ztp0b3on" , "rtDW.oujf1dobik"
, "rtDW.pcv4wpi3ke" , "rtDW.cbkkysibro" , "rtDW.akkonxbiyb" ,
"rtDW.e33if4mgu4" , "rtDW.bkzeyuvdfi" , "rtDW.jsetdp311j" , "rtDW.ha3ig5blsd"
, "rtDW.og3gej3jwz" , "rtDW.pv2wfqzep2" , "rtDW.lakc2myacn" ,
"rtDW.ohxmf4okd1" , "rtDW.jhaog44chc" , "rtDW.ovo4hnxxnn" , "rtDW.hpm14ul0f3"
, "rtDW.lkqen1tuni" , "rtDW.ly5fhjl0pp" , "rtDW.hiojixic5x" ,
"rtDW.ps3do31sj3" , "rtDW.mutemtyha2" , "rtDW.dhidrj0fdd" , "rtDW.frxhgtfui5"
, "rtDW.lrysnrlfpz" , "rtDW.fl21cmk5gk" , "rtDW.h4ow2pync3" ,
"rtDW.juomdslsik" , "rtDW.js0lpcxyrc" , "rtDW.e0edvudjse" , "rtDW.cmm1vcvsn0"
, "rtDW.e13leb2tmm" , "rtDW.inoqsfj0bw" , "rtDW.mkxeuv2wc4" ,
"rtDW.dzzfid2chy" , "rtDW.iz0phm120z" , "rtDW.jlvcxty141" , "rtDW.dfsexifu4j"
, "rtDW.csw4zgvz1w" , "rtDW.lvn51ym2qo" , "rtDW.jl0mnuibbh" ,
"rtDW.baqauvm4f0" , "rtDW.eam5on10cp" , "rtDW.f0ny4gmuvx" , "rtDW.l3xbscxi2g"
, "rtDW.dcitng5a3n" , "rtDW.jmc5mhc4s2" , "rtDW.exvrlracxo" ,
"rtDW.p22db1quvf" , "rtDW.euinuevdxm" , "rtDW.mr2aud2zdd" , "rtDW.hmazbcxsfm"
, "rtDW.ag0g5gwgl3" , "rtDW.bspqyhc1ui" , "rtDW.gvaglrbdot" ,
"rtDW.ottvoj0yqy" , "rtDW.dhockh40iz" , "rtDW.cosaluxqrd" , "rtDW.ehbdlfy2zi"
, "rtDW.hkguujkgog" , "rtDW.nkmva5gdkf" , "rtDW.k043rv4keo" ,
"rtDW.mmap3xsiti" , "rtDW.nmtkuzrjds" , "rtDW.nbwsx1apcl" , "rtDW.gmsb3q2zlj"
, "rtDW.iaghp1202d" , "rtDW.jpzpmlt0aw" , } ; mxArray * rtdwData =
mxCreateStructMatrix ( 1 , 1 , 86 , rtdwDataFieldNames ) ;
mr_air_part1_python2_cacheDataAsMxArray ( rtdwData , 0 , 0 , ( const void * )
& ( rtDW . hwcuhwqvaz ) , sizeof ( rtDW . hwcuhwqvaz ) ) ;
mr_air_part1_python2_cacheDataAsMxArray ( rtdwData , 0 , 1 , ( const void * )
& ( rtDW . bvsrcp4u0i ) , sizeof ( rtDW . bvsrcp4u0i ) ) ;
mr_air_part1_python2_cacheDataAsMxArray ( rtdwData , 0 , 2 , ( const void * )
& ( rtDW . l30tmqcnmm ) , sizeof ( rtDW . l30tmqcnmm ) ) ;
mr_air_part1_python2_cacheDataAsMxArray ( rtdwData , 0 , 3 , ( const void * )
& ( rtDW . njuyqff5u5 ) , sizeof ( rtDW . njuyqff5u5 ) ) ;
mr_air_part1_python2_cacheDataAsMxArray ( rtdwData , 0 , 4 , ( const void * )
& ( rtDW . iv3sxafqgs ) , sizeof ( rtDW . iv3sxafqgs ) ) ;
mr_air_part1_python2_cacheDataAsMxArray ( rtdwData , 0 , 5 , ( const void * )
& ( rtDW . dahp1m1tnz ) , sizeof ( rtDW . dahp1m1tnz ) ) ;
mr_air_part1_python2_cacheDataAsMxArray ( rtdwData , 0 , 6 , ( const void * )
& ( rtDW . egmxveifc2 ) , sizeof ( rtDW . egmxveifc2 ) ) ;
mr_air_part1_python2_cacheDataAsMxArray ( rtdwData , 0 , 7 , ( const void * )
& ( rtDW . nyak4kxjb0 ) , sizeof ( rtDW . nyak4kxjb0 ) ) ;
mr_air_part1_python2_cacheDataAsMxArray ( rtdwData , 0 , 8 , ( const void * )
& ( rtDW . jrcajuutzs ) , sizeof ( rtDW . jrcajuutzs ) ) ;
mr_air_part1_python2_cacheDataAsMxArray ( rtdwData , 0 , 9 , ( const void * )
& ( rtDW . bto3rz2afq ) , sizeof ( rtDW . bto3rz2afq ) ) ;
mr_air_part1_python2_cacheDataAsMxArray ( rtdwData , 0 , 10 , ( const void *
) & ( rtDW . l4a3zwvtji ) , sizeof ( rtDW . l4a3zwvtji ) ) ;
mr_air_part1_python2_cacheDataAsMxArray ( rtdwData , 0 , 11 , ( const void *
) & ( rtDW . ecriaizrd0 ) , sizeof ( rtDW . ecriaizrd0 ) ) ;
mr_air_part1_python2_cacheDataAsMxArray ( rtdwData , 0 , 12 , ( const void *
) & ( rtDW . evnfi3oakh ) , sizeof ( rtDW . evnfi3oakh ) ) ;
mr_air_part1_python2_cacheDataAsMxArray ( rtdwData , 0 , 13 , ( const void *
) & ( rtDW . jqu0hns3uo ) , sizeof ( rtDW . jqu0hns3uo ) ) ;
mr_air_part1_python2_cacheDataAsMxArray ( rtdwData , 0 , 14 , ( const void *
) & ( rtDW . ajtguqv0em ) , sizeof ( rtDW . ajtguqv0em ) ) ;
mr_air_part1_python2_cacheDataAsMxArray ( rtdwData , 0 , 15 , ( const void *
) & ( rtDW . b42g2henkn ) , sizeof ( rtDW . b42g2henkn ) ) ;
mr_air_part1_python2_cacheDataAsMxArray ( rtdwData , 0 , 16 , ( const void *
) & ( rtDW . omefgf0cmg ) , sizeof ( rtDW . omefgf0cmg ) ) ;
mr_air_part1_python2_cacheDataAsMxArray ( rtdwData , 0 , 17 , ( const void *
) & ( rtDW . eo5jyafoo5 ) , sizeof ( rtDW . eo5jyafoo5 ) ) ;
mr_air_part1_python2_cacheDataAsMxArray ( rtdwData , 0 , 18 , ( const void *
) & ( rtDW . leiplki144 ) , sizeof ( rtDW . leiplki144 ) ) ;
mr_air_part1_python2_cacheDataAsMxArray ( rtdwData , 0 , 19 , ( const void *
) & ( rtDW . g4ztp0b3on ) , sizeof ( rtDW . g4ztp0b3on ) ) ;
mr_air_part1_python2_cacheDataAsMxArray ( rtdwData , 0 , 20 , ( const void *
) & ( rtDW . oujf1dobik ) , sizeof ( rtDW . oujf1dobik ) ) ;
mr_air_part1_python2_cacheDataAsMxArray ( rtdwData , 0 , 21 , ( const void *
) & ( rtDW . pcv4wpi3ke ) , sizeof ( rtDW . pcv4wpi3ke ) ) ;
mr_air_part1_python2_cacheDataAsMxArray ( rtdwData , 0 , 22 , ( const void *
) & ( rtDW . cbkkysibro ) , sizeof ( rtDW . cbkkysibro ) ) ;
mr_air_part1_python2_cacheDataAsMxArray ( rtdwData , 0 , 23 , ( const void *
) & ( rtDW . akkonxbiyb ) , sizeof ( rtDW . akkonxbiyb ) ) ;
mr_air_part1_python2_cacheDataAsMxArray ( rtdwData , 0 , 24 , ( const void *
) & ( rtDW . e33if4mgu4 ) , sizeof ( rtDW . e33if4mgu4 ) ) ;
mr_air_part1_python2_cacheDataAsMxArray ( rtdwData , 0 , 25 , ( const void *
) & ( rtDW . bkzeyuvdfi ) , sizeof ( rtDW . bkzeyuvdfi ) ) ;
mr_air_part1_python2_cacheDataAsMxArray ( rtdwData , 0 , 26 , ( const void *
) & ( rtDW . jsetdp311j ) , sizeof ( rtDW . jsetdp311j ) ) ;
mr_air_part1_python2_cacheDataAsMxArray ( rtdwData , 0 , 27 , ( const void *
) & ( rtDW . ha3ig5blsd ) , sizeof ( rtDW . ha3ig5blsd ) ) ;
mr_air_part1_python2_cacheDataAsMxArray ( rtdwData , 0 , 28 , ( const void *
) & ( rtDW . og3gej3jwz ) , sizeof ( rtDW . og3gej3jwz ) ) ;
mr_air_part1_python2_cacheDataAsMxArray ( rtdwData , 0 , 29 , ( const void *
) & ( rtDW . pv2wfqzep2 ) , sizeof ( rtDW . pv2wfqzep2 ) ) ;
mr_air_part1_python2_cacheDataAsMxArray ( rtdwData , 0 , 30 , ( const void *
) & ( rtDW . lakc2myacn ) , sizeof ( rtDW . lakc2myacn ) ) ;
mr_air_part1_python2_cacheDataAsMxArray ( rtdwData , 0 , 31 , ( const void *
) & ( rtDW . ohxmf4okd1 ) , sizeof ( rtDW . ohxmf4okd1 ) ) ;
mr_air_part1_python2_cacheDataAsMxArray ( rtdwData , 0 , 32 , ( const void *
) & ( rtDW . jhaog44chc ) , sizeof ( rtDW . jhaog44chc ) ) ;
mr_air_part1_python2_cacheDataAsMxArray ( rtdwData , 0 , 33 , ( const void *
) & ( rtDW . ovo4hnxxnn ) , sizeof ( rtDW . ovo4hnxxnn ) ) ;
mr_air_part1_python2_cacheDataAsMxArray ( rtdwData , 0 , 34 , ( const void *
) & ( rtDW . hpm14ul0f3 ) , sizeof ( rtDW . hpm14ul0f3 ) ) ;
mr_air_part1_python2_cacheDataAsMxArray ( rtdwData , 0 , 35 , ( const void *
) & ( rtDW . lkqen1tuni ) , sizeof ( rtDW . lkqen1tuni ) ) ;
mr_air_part1_python2_cacheDataAsMxArray ( rtdwData , 0 , 36 , ( const void *
) & ( rtDW . ly5fhjl0pp ) , sizeof ( rtDW . ly5fhjl0pp ) ) ;
mr_air_part1_python2_cacheDataAsMxArray ( rtdwData , 0 , 37 , ( const void *
) & ( rtDW . hiojixic5x ) , sizeof ( rtDW . hiojixic5x ) ) ;
mr_air_part1_python2_cacheDataAsMxArray ( rtdwData , 0 , 38 , ( const void *
) & ( rtDW . ps3do31sj3 ) , sizeof ( rtDW . ps3do31sj3 ) ) ;
mr_air_part1_python2_cacheDataAsMxArray ( rtdwData , 0 , 39 , ( const void *
) & ( rtDW . mutemtyha2 ) , sizeof ( rtDW . mutemtyha2 ) ) ;
mr_air_part1_python2_cacheDataAsMxArray ( rtdwData , 0 , 40 , ( const void *
) & ( rtDW . dhidrj0fdd ) , sizeof ( rtDW . dhidrj0fdd ) ) ;
mr_air_part1_python2_cacheDataAsMxArray ( rtdwData , 0 , 41 , ( const void *
) & ( rtDW . frxhgtfui5 ) , sizeof ( rtDW . frxhgtfui5 ) ) ;
mr_air_part1_python2_cacheDataAsMxArray ( rtdwData , 0 , 42 , ( const void *
) & ( rtDW . lrysnrlfpz ) , sizeof ( rtDW . lrysnrlfpz ) ) ;
mr_air_part1_python2_cacheDataAsMxArray ( rtdwData , 0 , 43 , ( const void *
) & ( rtDW . fl21cmk5gk ) , sizeof ( rtDW . fl21cmk5gk ) ) ;
mr_air_part1_python2_cacheDataAsMxArray ( rtdwData , 0 , 44 , ( const void *
) & ( rtDW . h4ow2pync3 ) , sizeof ( rtDW . h4ow2pync3 ) ) ;
mr_air_part1_python2_cacheDataAsMxArray ( rtdwData , 0 , 45 , ( const void *
) & ( rtDW . juomdslsik ) , sizeof ( rtDW . juomdslsik ) ) ;
mr_air_part1_python2_cacheDataAsMxArray ( rtdwData , 0 , 46 , ( const void *
) & ( rtDW . js0lpcxyrc ) , sizeof ( rtDW . js0lpcxyrc ) ) ;
mr_air_part1_python2_cacheDataAsMxArray ( rtdwData , 0 , 47 , ( const void *
) & ( rtDW . e0edvudjse ) , sizeof ( rtDW . e0edvudjse ) ) ;
mr_air_part1_python2_cacheDataAsMxArray ( rtdwData , 0 , 48 , ( const void *
) & ( rtDW . cmm1vcvsn0 ) , sizeof ( rtDW . cmm1vcvsn0 ) ) ;
mr_air_part1_python2_cacheDataAsMxArray ( rtdwData , 0 , 49 , ( const void *
) & ( rtDW . e13leb2tmm ) , sizeof ( rtDW . e13leb2tmm ) ) ;
mr_air_part1_python2_cacheDataAsMxArray ( rtdwData , 0 , 50 , ( const void *
) & ( rtDW . inoqsfj0bw ) , sizeof ( rtDW . inoqsfj0bw ) ) ;
mr_air_part1_python2_cacheDataAsMxArray ( rtdwData , 0 , 51 , ( const void *
) & ( rtDW . mkxeuv2wc4 ) , sizeof ( rtDW . mkxeuv2wc4 ) ) ;
mr_air_part1_python2_cacheDataAsMxArray ( rtdwData , 0 , 52 , ( const void *
) & ( rtDW . dzzfid2chy ) , sizeof ( rtDW . dzzfid2chy ) ) ;
mr_air_part1_python2_cacheDataAsMxArray ( rtdwData , 0 , 53 , ( const void *
) & ( rtDW . iz0phm120z ) , sizeof ( rtDW . iz0phm120z ) ) ;
mr_air_part1_python2_cacheDataAsMxArray ( rtdwData , 0 , 54 , ( const void *
) & ( rtDW . jlvcxty141 ) , sizeof ( rtDW . jlvcxty141 ) ) ;
mr_air_part1_python2_cacheDataAsMxArray ( rtdwData , 0 , 55 , ( const void *
) & ( rtDW . dfsexifu4j ) , sizeof ( rtDW . dfsexifu4j ) ) ;
mr_air_part1_python2_cacheDataAsMxArray ( rtdwData , 0 , 56 , ( const void *
) & ( rtDW . csw4zgvz1w ) , sizeof ( rtDW . csw4zgvz1w ) ) ;
mr_air_part1_python2_cacheDataAsMxArray ( rtdwData , 0 , 57 , ( const void *
) & ( rtDW . lvn51ym2qo ) , sizeof ( rtDW . lvn51ym2qo ) ) ;
mr_air_part1_python2_cacheDataAsMxArray ( rtdwData , 0 , 58 , ( const void *
) & ( rtDW . jl0mnuibbh ) , sizeof ( rtDW . jl0mnuibbh ) ) ;
mr_air_part1_python2_cacheDataAsMxArray ( rtdwData , 0 , 59 , ( const void *
) & ( rtDW . baqauvm4f0 ) , sizeof ( rtDW . baqauvm4f0 ) ) ;
mr_air_part1_python2_cacheDataAsMxArray ( rtdwData , 0 , 60 , ( const void *
) & ( rtDW . eam5on10cp ) , sizeof ( rtDW . eam5on10cp ) ) ;
mr_air_part1_python2_cacheDataAsMxArray ( rtdwData , 0 , 61 , ( const void *
) & ( rtDW . f0ny4gmuvx ) , sizeof ( rtDW . f0ny4gmuvx ) ) ;
mr_air_part1_python2_cacheDataAsMxArray ( rtdwData , 0 , 62 , ( const void *
) & ( rtDW . l3xbscxi2g ) , sizeof ( rtDW . l3xbscxi2g ) ) ;
mr_air_part1_python2_cacheDataAsMxArray ( rtdwData , 0 , 63 , ( const void *
) & ( rtDW . dcitng5a3n ) , sizeof ( rtDW . dcitng5a3n ) ) ;
mr_air_part1_python2_cacheDataAsMxArray ( rtdwData , 0 , 64 , ( const void *
) & ( rtDW . jmc5mhc4s2 ) , sizeof ( rtDW . jmc5mhc4s2 ) ) ;
mr_air_part1_python2_cacheDataAsMxArray ( rtdwData , 0 , 65 , ( const void *
) & ( rtDW . exvrlracxo ) , sizeof ( rtDW . exvrlracxo ) ) ;
mr_air_part1_python2_cacheDataAsMxArray ( rtdwData , 0 , 66 , ( const void *
) & ( rtDW . p22db1quvf ) , sizeof ( rtDW . p22db1quvf ) ) ;
mr_air_part1_python2_cacheDataAsMxArray ( rtdwData , 0 , 67 , ( const void *
) & ( rtDW . euinuevdxm ) , sizeof ( rtDW . euinuevdxm ) ) ;
mr_air_part1_python2_cacheDataAsMxArray ( rtdwData , 0 , 68 , ( const void *
) & ( rtDW . mr2aud2zdd ) , sizeof ( rtDW . mr2aud2zdd ) ) ;
mr_air_part1_python2_cacheDataAsMxArray ( rtdwData , 0 , 69 , ( const void *
) & ( rtDW . hmazbcxsfm ) , sizeof ( rtDW . hmazbcxsfm ) ) ;
mr_air_part1_python2_cacheDataAsMxArray ( rtdwData , 0 , 70 , ( const void *
) & ( rtDW . ag0g5gwgl3 ) , sizeof ( rtDW . ag0g5gwgl3 ) ) ;
mr_air_part1_python2_cacheDataAsMxArray ( rtdwData , 0 , 71 , ( const void *
) & ( rtDW . bspqyhc1ui ) , sizeof ( rtDW . bspqyhc1ui ) ) ;
mr_air_part1_python2_cacheDataAsMxArray ( rtdwData , 0 , 72 , ( const void *
) & ( rtDW . gvaglrbdot ) , sizeof ( rtDW . gvaglrbdot ) ) ;
mr_air_part1_python2_cacheDataAsMxArray ( rtdwData , 0 , 73 , ( const void *
) & ( rtDW . ottvoj0yqy ) , sizeof ( rtDW . ottvoj0yqy ) ) ;
mr_air_part1_python2_cacheDataAsMxArray ( rtdwData , 0 , 74 , ( const void *
) & ( rtDW . dhockh40iz ) , sizeof ( rtDW . dhockh40iz ) ) ;
mr_air_part1_python2_cacheDataAsMxArray ( rtdwData , 0 , 75 , ( const void *
) & ( rtDW . cosaluxqrd ) , sizeof ( rtDW . cosaluxqrd ) ) ;
mr_air_part1_python2_cacheDataAsMxArray ( rtdwData , 0 , 76 , ( const void *
) & ( rtDW . ehbdlfy2zi ) , sizeof ( rtDW . ehbdlfy2zi ) ) ;
mr_air_part1_python2_cacheDataAsMxArray ( rtdwData , 0 , 77 , ( const void *
) & ( rtDW . hkguujkgog ) , sizeof ( rtDW . hkguujkgog ) ) ;
mr_air_part1_python2_cacheDataAsMxArray ( rtdwData , 0 , 78 , ( const void *
) & ( rtDW . nkmva5gdkf ) , sizeof ( rtDW . nkmva5gdkf ) ) ;
mr_air_part1_python2_cacheDataAsMxArray ( rtdwData , 0 , 79 , ( const void *
) & ( rtDW . k043rv4keo ) , sizeof ( rtDW . k043rv4keo ) ) ;
mr_air_part1_python2_cacheDataAsMxArray ( rtdwData , 0 , 80 , ( const void *
) & ( rtDW . mmap3xsiti ) , sizeof ( rtDW . mmap3xsiti ) ) ;
mr_air_part1_python2_cacheDataAsMxArray ( rtdwData , 0 , 81 , ( const void *
) & ( rtDW . nmtkuzrjds ) , sizeof ( rtDW . nmtkuzrjds ) ) ;
mr_air_part1_python2_cacheDataAsMxArray ( rtdwData , 0 , 82 , ( const void *
) & ( rtDW . nbwsx1apcl ) , sizeof ( rtDW . nbwsx1apcl ) ) ;
mr_air_part1_python2_cacheDataAsMxArray ( rtdwData , 0 , 83 , ( const void *
) & ( rtDW . gmsb3q2zlj ) , sizeof ( rtDW . gmsb3q2zlj ) ) ;
mr_air_part1_python2_cacheDataAsMxArray ( rtdwData , 0 , 84 , ( const void *
) & ( rtDW . iaghp1202d ) , sizeof ( rtDW . iaghp1202d ) ) ;
mr_air_part1_python2_cacheDataAsMxArray ( rtdwData , 0 , 85 , ( const void *
) & ( rtDW . jpzpmlt0aw ) , sizeof ( rtDW . jpzpmlt0aw ) ) ;
mxSetFieldByNumber ( ssDW , 0 , 1 , rtdwData ) ; } return ssDW ; } void
mr_air_part1_python2_SetDWork ( const mxArray * ssDW ) { ( void ) ssDW ;
mr_air_part1_python2_restoreDataFromMxArray ( ( void * ) & ( rtB ) , ssDW , 0
, 0 , sizeof ( rtB ) ) ; { const mxArray * rtdwData = mxGetFieldByNumber (
ssDW , 0 , 1 ) ; mr_air_part1_python2_restoreDataFromMxArray ( ( void * ) & (
rtDW . hwcuhwqvaz ) , rtdwData , 0 , 0 , sizeof ( rtDW . hwcuhwqvaz ) ) ;
mr_air_part1_python2_restoreDataFromMxArray ( ( void * ) & ( rtDW .
bvsrcp4u0i ) , rtdwData , 0 , 1 , sizeof ( rtDW . bvsrcp4u0i ) ) ;
mr_air_part1_python2_restoreDataFromMxArray ( ( void * ) & ( rtDW .
l30tmqcnmm ) , rtdwData , 0 , 2 , sizeof ( rtDW . l30tmqcnmm ) ) ;
mr_air_part1_python2_restoreDataFromMxArray ( ( void * ) & ( rtDW .
njuyqff5u5 ) , rtdwData , 0 , 3 , sizeof ( rtDW . njuyqff5u5 ) ) ;
mr_air_part1_python2_restoreDataFromMxArray ( ( void * ) & ( rtDW .
iv3sxafqgs ) , rtdwData , 0 , 4 , sizeof ( rtDW . iv3sxafqgs ) ) ;
mr_air_part1_python2_restoreDataFromMxArray ( ( void * ) & ( rtDW .
dahp1m1tnz ) , rtdwData , 0 , 5 , sizeof ( rtDW . dahp1m1tnz ) ) ;
mr_air_part1_python2_restoreDataFromMxArray ( ( void * ) & ( rtDW .
egmxveifc2 ) , rtdwData , 0 , 6 , sizeof ( rtDW . egmxveifc2 ) ) ;
mr_air_part1_python2_restoreDataFromMxArray ( ( void * ) & ( rtDW .
nyak4kxjb0 ) , rtdwData , 0 , 7 , sizeof ( rtDW . nyak4kxjb0 ) ) ;
mr_air_part1_python2_restoreDataFromMxArray ( ( void * ) & ( rtDW .
jrcajuutzs ) , rtdwData , 0 , 8 , sizeof ( rtDW . jrcajuutzs ) ) ;
mr_air_part1_python2_restoreDataFromMxArray ( ( void * ) & ( rtDW .
bto3rz2afq ) , rtdwData , 0 , 9 , sizeof ( rtDW . bto3rz2afq ) ) ;
mr_air_part1_python2_restoreDataFromMxArray ( ( void * ) & ( rtDW .
l4a3zwvtji ) , rtdwData , 0 , 10 , sizeof ( rtDW . l4a3zwvtji ) ) ;
mr_air_part1_python2_restoreDataFromMxArray ( ( void * ) & ( rtDW .
ecriaizrd0 ) , rtdwData , 0 , 11 , sizeof ( rtDW . ecriaizrd0 ) ) ;
mr_air_part1_python2_restoreDataFromMxArray ( ( void * ) & ( rtDW .
evnfi3oakh ) , rtdwData , 0 , 12 , sizeof ( rtDW . evnfi3oakh ) ) ;
mr_air_part1_python2_restoreDataFromMxArray ( ( void * ) & ( rtDW .
jqu0hns3uo ) , rtdwData , 0 , 13 , sizeof ( rtDW . jqu0hns3uo ) ) ;
mr_air_part1_python2_restoreDataFromMxArray ( ( void * ) & ( rtDW .
ajtguqv0em ) , rtdwData , 0 , 14 , sizeof ( rtDW . ajtguqv0em ) ) ;
mr_air_part1_python2_restoreDataFromMxArray ( ( void * ) & ( rtDW .
b42g2henkn ) , rtdwData , 0 , 15 , sizeof ( rtDW . b42g2henkn ) ) ;
mr_air_part1_python2_restoreDataFromMxArray ( ( void * ) & ( rtDW .
omefgf0cmg ) , rtdwData , 0 , 16 , sizeof ( rtDW . omefgf0cmg ) ) ;
mr_air_part1_python2_restoreDataFromMxArray ( ( void * ) & ( rtDW .
eo5jyafoo5 ) , rtdwData , 0 , 17 , sizeof ( rtDW . eo5jyafoo5 ) ) ;
mr_air_part1_python2_restoreDataFromMxArray ( ( void * ) & ( rtDW .
leiplki144 ) , rtdwData , 0 , 18 , sizeof ( rtDW . leiplki144 ) ) ;
mr_air_part1_python2_restoreDataFromMxArray ( ( void * ) & ( rtDW .
g4ztp0b3on ) , rtdwData , 0 , 19 , sizeof ( rtDW . g4ztp0b3on ) ) ;
mr_air_part1_python2_restoreDataFromMxArray ( ( void * ) & ( rtDW .
oujf1dobik ) , rtdwData , 0 , 20 , sizeof ( rtDW . oujf1dobik ) ) ;
mr_air_part1_python2_restoreDataFromMxArray ( ( void * ) & ( rtDW .
pcv4wpi3ke ) , rtdwData , 0 , 21 , sizeof ( rtDW . pcv4wpi3ke ) ) ;
mr_air_part1_python2_restoreDataFromMxArray ( ( void * ) & ( rtDW .
cbkkysibro ) , rtdwData , 0 , 22 , sizeof ( rtDW . cbkkysibro ) ) ;
mr_air_part1_python2_restoreDataFromMxArray ( ( void * ) & ( rtDW .
akkonxbiyb ) , rtdwData , 0 , 23 , sizeof ( rtDW . akkonxbiyb ) ) ;
mr_air_part1_python2_restoreDataFromMxArray ( ( void * ) & ( rtDW .
e33if4mgu4 ) , rtdwData , 0 , 24 , sizeof ( rtDW . e33if4mgu4 ) ) ;
mr_air_part1_python2_restoreDataFromMxArray ( ( void * ) & ( rtDW .
bkzeyuvdfi ) , rtdwData , 0 , 25 , sizeof ( rtDW . bkzeyuvdfi ) ) ;
mr_air_part1_python2_restoreDataFromMxArray ( ( void * ) & ( rtDW .
jsetdp311j ) , rtdwData , 0 , 26 , sizeof ( rtDW . jsetdp311j ) ) ;
mr_air_part1_python2_restoreDataFromMxArray ( ( void * ) & ( rtDW .
ha3ig5blsd ) , rtdwData , 0 , 27 , sizeof ( rtDW . ha3ig5blsd ) ) ;
mr_air_part1_python2_restoreDataFromMxArray ( ( void * ) & ( rtDW .
og3gej3jwz ) , rtdwData , 0 , 28 , sizeof ( rtDW . og3gej3jwz ) ) ;
mr_air_part1_python2_restoreDataFromMxArray ( ( void * ) & ( rtDW .
pv2wfqzep2 ) , rtdwData , 0 , 29 , sizeof ( rtDW . pv2wfqzep2 ) ) ;
mr_air_part1_python2_restoreDataFromMxArray ( ( void * ) & ( rtDW .
lakc2myacn ) , rtdwData , 0 , 30 , sizeof ( rtDW . lakc2myacn ) ) ;
mr_air_part1_python2_restoreDataFromMxArray ( ( void * ) & ( rtDW .
ohxmf4okd1 ) , rtdwData , 0 , 31 , sizeof ( rtDW . ohxmf4okd1 ) ) ;
mr_air_part1_python2_restoreDataFromMxArray ( ( void * ) & ( rtDW .
jhaog44chc ) , rtdwData , 0 , 32 , sizeof ( rtDW . jhaog44chc ) ) ;
mr_air_part1_python2_restoreDataFromMxArray ( ( void * ) & ( rtDW .
ovo4hnxxnn ) , rtdwData , 0 , 33 , sizeof ( rtDW . ovo4hnxxnn ) ) ;
mr_air_part1_python2_restoreDataFromMxArray ( ( void * ) & ( rtDW .
hpm14ul0f3 ) , rtdwData , 0 , 34 , sizeof ( rtDW . hpm14ul0f3 ) ) ;
mr_air_part1_python2_restoreDataFromMxArray ( ( void * ) & ( rtDW .
lkqen1tuni ) , rtdwData , 0 , 35 , sizeof ( rtDW . lkqen1tuni ) ) ;
mr_air_part1_python2_restoreDataFromMxArray ( ( void * ) & ( rtDW .
ly5fhjl0pp ) , rtdwData , 0 , 36 , sizeof ( rtDW . ly5fhjl0pp ) ) ;
mr_air_part1_python2_restoreDataFromMxArray ( ( void * ) & ( rtDW .
hiojixic5x ) , rtdwData , 0 , 37 , sizeof ( rtDW . hiojixic5x ) ) ;
mr_air_part1_python2_restoreDataFromMxArray ( ( void * ) & ( rtDW .
ps3do31sj3 ) , rtdwData , 0 , 38 , sizeof ( rtDW . ps3do31sj3 ) ) ;
mr_air_part1_python2_restoreDataFromMxArray ( ( void * ) & ( rtDW .
mutemtyha2 ) , rtdwData , 0 , 39 , sizeof ( rtDW . mutemtyha2 ) ) ;
mr_air_part1_python2_restoreDataFromMxArray ( ( void * ) & ( rtDW .
dhidrj0fdd ) , rtdwData , 0 , 40 , sizeof ( rtDW . dhidrj0fdd ) ) ;
mr_air_part1_python2_restoreDataFromMxArray ( ( void * ) & ( rtDW .
frxhgtfui5 ) , rtdwData , 0 , 41 , sizeof ( rtDW . frxhgtfui5 ) ) ;
mr_air_part1_python2_restoreDataFromMxArray ( ( void * ) & ( rtDW .
lrysnrlfpz ) , rtdwData , 0 , 42 , sizeof ( rtDW . lrysnrlfpz ) ) ;
mr_air_part1_python2_restoreDataFromMxArray ( ( void * ) & ( rtDW .
fl21cmk5gk ) , rtdwData , 0 , 43 , sizeof ( rtDW . fl21cmk5gk ) ) ;
mr_air_part1_python2_restoreDataFromMxArray ( ( void * ) & ( rtDW .
h4ow2pync3 ) , rtdwData , 0 , 44 , sizeof ( rtDW . h4ow2pync3 ) ) ;
mr_air_part1_python2_restoreDataFromMxArray ( ( void * ) & ( rtDW .
juomdslsik ) , rtdwData , 0 , 45 , sizeof ( rtDW . juomdslsik ) ) ;
mr_air_part1_python2_restoreDataFromMxArray ( ( void * ) & ( rtDW .
js0lpcxyrc ) , rtdwData , 0 , 46 , sizeof ( rtDW . js0lpcxyrc ) ) ;
mr_air_part1_python2_restoreDataFromMxArray ( ( void * ) & ( rtDW .
e0edvudjse ) , rtdwData , 0 , 47 , sizeof ( rtDW . e0edvudjse ) ) ;
mr_air_part1_python2_restoreDataFromMxArray ( ( void * ) & ( rtDW .
cmm1vcvsn0 ) , rtdwData , 0 , 48 , sizeof ( rtDW . cmm1vcvsn0 ) ) ;
mr_air_part1_python2_restoreDataFromMxArray ( ( void * ) & ( rtDW .
e13leb2tmm ) , rtdwData , 0 , 49 , sizeof ( rtDW . e13leb2tmm ) ) ;
mr_air_part1_python2_restoreDataFromMxArray ( ( void * ) & ( rtDW .
inoqsfj0bw ) , rtdwData , 0 , 50 , sizeof ( rtDW . inoqsfj0bw ) ) ;
mr_air_part1_python2_restoreDataFromMxArray ( ( void * ) & ( rtDW .
mkxeuv2wc4 ) , rtdwData , 0 , 51 , sizeof ( rtDW . mkxeuv2wc4 ) ) ;
mr_air_part1_python2_restoreDataFromMxArray ( ( void * ) & ( rtDW .
dzzfid2chy ) , rtdwData , 0 , 52 , sizeof ( rtDW . dzzfid2chy ) ) ;
mr_air_part1_python2_restoreDataFromMxArray ( ( void * ) & ( rtDW .
iz0phm120z ) , rtdwData , 0 , 53 , sizeof ( rtDW . iz0phm120z ) ) ;
mr_air_part1_python2_restoreDataFromMxArray ( ( void * ) & ( rtDW .
jlvcxty141 ) , rtdwData , 0 , 54 , sizeof ( rtDW . jlvcxty141 ) ) ;
mr_air_part1_python2_restoreDataFromMxArray ( ( void * ) & ( rtDW .
dfsexifu4j ) , rtdwData , 0 , 55 , sizeof ( rtDW . dfsexifu4j ) ) ;
mr_air_part1_python2_restoreDataFromMxArray ( ( void * ) & ( rtDW .
csw4zgvz1w ) , rtdwData , 0 , 56 , sizeof ( rtDW . csw4zgvz1w ) ) ;
mr_air_part1_python2_restoreDataFromMxArray ( ( void * ) & ( rtDW .
lvn51ym2qo ) , rtdwData , 0 , 57 , sizeof ( rtDW . lvn51ym2qo ) ) ;
mr_air_part1_python2_restoreDataFromMxArray ( ( void * ) & ( rtDW .
jl0mnuibbh ) , rtdwData , 0 , 58 , sizeof ( rtDW . jl0mnuibbh ) ) ;
mr_air_part1_python2_restoreDataFromMxArray ( ( void * ) & ( rtDW .
baqauvm4f0 ) , rtdwData , 0 , 59 , sizeof ( rtDW . baqauvm4f0 ) ) ;
mr_air_part1_python2_restoreDataFromMxArray ( ( void * ) & ( rtDW .
eam5on10cp ) , rtdwData , 0 , 60 , sizeof ( rtDW . eam5on10cp ) ) ;
mr_air_part1_python2_restoreDataFromMxArray ( ( void * ) & ( rtDW .
f0ny4gmuvx ) , rtdwData , 0 , 61 , sizeof ( rtDW . f0ny4gmuvx ) ) ;
mr_air_part1_python2_restoreDataFromMxArray ( ( void * ) & ( rtDW .
l3xbscxi2g ) , rtdwData , 0 , 62 , sizeof ( rtDW . l3xbscxi2g ) ) ;
mr_air_part1_python2_restoreDataFromMxArray ( ( void * ) & ( rtDW .
dcitng5a3n ) , rtdwData , 0 , 63 , sizeof ( rtDW . dcitng5a3n ) ) ;
mr_air_part1_python2_restoreDataFromMxArray ( ( void * ) & ( rtDW .
jmc5mhc4s2 ) , rtdwData , 0 , 64 , sizeof ( rtDW . jmc5mhc4s2 ) ) ;
mr_air_part1_python2_restoreDataFromMxArray ( ( void * ) & ( rtDW .
exvrlracxo ) , rtdwData , 0 , 65 , sizeof ( rtDW . exvrlracxo ) ) ;
mr_air_part1_python2_restoreDataFromMxArray ( ( void * ) & ( rtDW .
p22db1quvf ) , rtdwData , 0 , 66 , sizeof ( rtDW . p22db1quvf ) ) ;
mr_air_part1_python2_restoreDataFromMxArray ( ( void * ) & ( rtDW .
euinuevdxm ) , rtdwData , 0 , 67 , sizeof ( rtDW . euinuevdxm ) ) ;
mr_air_part1_python2_restoreDataFromMxArray ( ( void * ) & ( rtDW .
mr2aud2zdd ) , rtdwData , 0 , 68 , sizeof ( rtDW . mr2aud2zdd ) ) ;
mr_air_part1_python2_restoreDataFromMxArray ( ( void * ) & ( rtDW .
hmazbcxsfm ) , rtdwData , 0 , 69 , sizeof ( rtDW . hmazbcxsfm ) ) ;
mr_air_part1_python2_restoreDataFromMxArray ( ( void * ) & ( rtDW .
ag0g5gwgl3 ) , rtdwData , 0 , 70 , sizeof ( rtDW . ag0g5gwgl3 ) ) ;
mr_air_part1_python2_restoreDataFromMxArray ( ( void * ) & ( rtDW .
bspqyhc1ui ) , rtdwData , 0 , 71 , sizeof ( rtDW . bspqyhc1ui ) ) ;
mr_air_part1_python2_restoreDataFromMxArray ( ( void * ) & ( rtDW .
gvaglrbdot ) , rtdwData , 0 , 72 , sizeof ( rtDW . gvaglrbdot ) ) ;
mr_air_part1_python2_restoreDataFromMxArray ( ( void * ) & ( rtDW .
ottvoj0yqy ) , rtdwData , 0 , 73 , sizeof ( rtDW . ottvoj0yqy ) ) ;
mr_air_part1_python2_restoreDataFromMxArray ( ( void * ) & ( rtDW .
dhockh40iz ) , rtdwData , 0 , 74 , sizeof ( rtDW . dhockh40iz ) ) ;
mr_air_part1_python2_restoreDataFromMxArray ( ( void * ) & ( rtDW .
cosaluxqrd ) , rtdwData , 0 , 75 , sizeof ( rtDW . cosaluxqrd ) ) ;
mr_air_part1_python2_restoreDataFromMxArray ( ( void * ) & ( rtDW .
ehbdlfy2zi ) , rtdwData , 0 , 76 , sizeof ( rtDW . ehbdlfy2zi ) ) ;
mr_air_part1_python2_restoreDataFromMxArray ( ( void * ) & ( rtDW .
hkguujkgog ) , rtdwData , 0 , 77 , sizeof ( rtDW . hkguujkgog ) ) ;
mr_air_part1_python2_restoreDataFromMxArray ( ( void * ) & ( rtDW .
nkmva5gdkf ) , rtdwData , 0 , 78 , sizeof ( rtDW . nkmva5gdkf ) ) ;
mr_air_part1_python2_restoreDataFromMxArray ( ( void * ) & ( rtDW .
k043rv4keo ) , rtdwData , 0 , 79 , sizeof ( rtDW . k043rv4keo ) ) ;
mr_air_part1_python2_restoreDataFromMxArray ( ( void * ) & ( rtDW .
mmap3xsiti ) , rtdwData , 0 , 80 , sizeof ( rtDW . mmap3xsiti ) ) ;
mr_air_part1_python2_restoreDataFromMxArray ( ( void * ) & ( rtDW .
nmtkuzrjds ) , rtdwData , 0 , 81 , sizeof ( rtDW . nmtkuzrjds ) ) ;
mr_air_part1_python2_restoreDataFromMxArray ( ( void * ) & ( rtDW .
nbwsx1apcl ) , rtdwData , 0 , 82 , sizeof ( rtDW . nbwsx1apcl ) ) ;
mr_air_part1_python2_restoreDataFromMxArray ( ( void * ) & ( rtDW .
gmsb3q2zlj ) , rtdwData , 0 , 83 , sizeof ( rtDW . gmsb3q2zlj ) ) ;
mr_air_part1_python2_restoreDataFromMxArray ( ( void * ) & ( rtDW .
iaghp1202d ) , rtdwData , 0 , 84 , sizeof ( rtDW . iaghp1202d ) ) ;
mr_air_part1_python2_restoreDataFromMxArray ( ( void * ) & ( rtDW .
jpzpmlt0aw ) , rtdwData , 0 , 85 , sizeof ( rtDW . jpzpmlt0aw ) ) ; } }
mxArray * mr_air_part1_python2_GetSimStateDisallowedBlocks ( ) { mxArray *
data = mxCreateCellMatrix ( 10 , 3 ) ; mwIndex subs [ 2 ] , offset ; { static
const char * blockType [ 10 ] = { "Scope" , "Scope" , "Scope" , "Scope" ,
"Scope" , "Scope" , "Scope" , "Scope" , "Scope" , "S-Function" , } ; static
const char * blockPath [ 10 ] = { "air_part1_python2/Scope" ,
"air_part1_python2/Scope1" , "air_part1_python2/Scope11" ,
"air_part1_python2/Scope14" , "air_part1_python2/Scope2" ,
"air_part1_python2/Scope3" , "air_part1_python2/Scope4" ,
"air_part1_python2/Scope6" , "air_part1_python2/Scope7" ,
"air_part1_python2/ASCII Encode" , } ; static const int reason [ 10 ] = { 0 ,
0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , } ; for ( subs [ 0 ] = 0 ; subs [ 0 ] <
10 ; ++ ( subs [ 0 ] ) ) { subs [ 1 ] = 0 ; offset = mxCalcSingleSubscript (
data , 2 , subs ) ; mxSetCell ( data , offset , mxCreateString ( blockType [
subs [ 0 ] ] ) ) ; subs [ 1 ] = 1 ; offset = mxCalcSingleSubscript ( data , 2
, subs ) ; mxSetCell ( data , offset , mxCreateString ( blockPath [ subs [ 0
] ] ) ) ; subs [ 1 ] = 2 ; offset = mxCalcSingleSubscript ( data , 2 , subs )
; mxSetCell ( data , offset , mxCreateDoubleScalar ( ( double ) reason [ subs
[ 0 ] ] ) ) ; } } return data ; } void MdlInitializeSizes ( void ) {
ssSetNumContStates ( rtS , 8 ) ; ssSetNumPeriodicContStates ( rtS , 0 ) ;
ssSetNumY ( rtS , 0 ) ; ssSetNumU ( rtS , 0 ) ; ssSetDirectFeedThrough ( rtS
, 0 ) ; ssSetNumSampleTimes ( rtS , 6 ) ; ssSetNumBlocks ( rtS , 335 ) ;
ssSetNumBlockIO ( rtS , 99 ) ; ssSetNumBlockParams ( rtS , 218 ) ; } void
MdlInitializeSampleTimes ( void ) { ssSetSampleTime ( rtS , 0 , 0.0 ) ;
ssSetSampleTime ( rtS , 1 , 5.0E-5 ) ; ssSetSampleTime ( rtS , 2 , 0.04 ) ;
ssSetSampleTime ( rtS , 3 , 0.05 ) ; ssSetSampleTime ( rtS , 4 , 5.0E-5 ) ;
ssSetSampleTime ( rtS , 5 , 5.0E-5 ) ; ssSetOffsetTime ( rtS , 0 , 0.0 ) ;
ssSetOffsetTime ( rtS , 1 , 0.0 ) ; ssSetOffsetTime ( rtS , 2 , 0.0 ) ;
ssSetOffsetTime ( rtS , 3 , 0.0 ) ; ssSetOffsetTime ( rtS , 4 , - 20.0 ) ;
ssSetOffsetTime ( rtS , 5 , - 21.0 ) ; } void raccel_set_checksum ( ) {
ssSetChecksumVal ( rtS , 0 , 2532647534U ) ; ssSetChecksumVal ( rtS , 1 ,
717479846U ) ; ssSetChecksumVal ( rtS , 2 , 1968865415U ) ; ssSetChecksumVal
( rtS , 3 , 3579019364U ) ; }
#if defined(_MSC_VER)
#pragma optimize( "", off )
#endif
SimStruct * raccel_register_model ( ssExecutionInfo * executionInfo ) {
static struct _ssMdlInfo mdlInfo ; static struct _ssBlkInfo2 blkInfo2 ;
static struct _ssBlkInfoSLSize blkInfoSLSize ; ( void ) memset ( ( char * )
rtS , 0 , sizeof ( SimStruct ) ) ; ( void ) memset ( ( char * ) & mdlInfo , 0
, sizeof ( struct _ssMdlInfo ) ) ; ( void ) memset ( ( char * ) & blkInfo2 ,
0 , sizeof ( struct _ssBlkInfo2 ) ) ; ( void ) memset ( ( char * ) &
blkInfoSLSize , 0 , sizeof ( struct _ssBlkInfoSLSize ) ) ; ssSetBlkInfo2Ptr (
rtS , & blkInfo2 ) ; ssSetBlkInfoSLSizePtr ( rtS , & blkInfoSLSize ) ;
ssSetMdlInfoPtr ( rtS , & mdlInfo ) ; ssSetExecutionInfo ( rtS ,
executionInfo ) ; slsaAllocOPModelData ( rtS ) ; { static time_T mdlPeriod [
NSAMPLE_TIMES ] ; static time_T mdlOffset [ NSAMPLE_TIMES ] ; static time_T
mdlTaskTimes [ NSAMPLE_TIMES ] ; static int_T mdlTsMap [ NSAMPLE_TIMES ] ;
static int_T mdlSampleHits [ NSAMPLE_TIMES ] ; static boolean_T
mdlTNextWasAdjustedPtr [ NSAMPLE_TIMES ] ; static int_T mdlPerTaskSampleHits
[ NSAMPLE_TIMES * NSAMPLE_TIMES ] ; static time_T mdlTimeOfNextSampleHit [
NSAMPLE_TIMES ] ; { int_T i ; for ( i = 0 ; i < NSAMPLE_TIMES ; i ++ ) {
mdlPeriod [ i ] = 0.0 ; mdlOffset [ i ] = 0.0 ; mdlTaskTimes [ i ] = 0.0 ;
mdlTsMap [ i ] = i ; mdlSampleHits [ i ] = 1 ; } } ssSetSampleTimePtr ( rtS ,
& mdlPeriod [ 0 ] ) ; ssSetOffsetTimePtr ( rtS , & mdlOffset [ 0 ] ) ;
ssSetSampleTimeTaskIDPtr ( rtS , & mdlTsMap [ 0 ] ) ; ssSetTPtr ( rtS , &
mdlTaskTimes [ 0 ] ) ; ssSetSampleHitPtr ( rtS , & mdlSampleHits [ 0 ] ) ;
ssSetTNextWasAdjustedPtr ( rtS , & mdlTNextWasAdjustedPtr [ 0 ] ) ;
ssSetPerTaskSampleHitsPtr ( rtS , & mdlPerTaskSampleHits [ 0 ] ) ;
ssSetTimeOfNextSampleHitPtr ( rtS , & mdlTimeOfNextSampleHit [ 0 ] ) ; }
ssSetSolverMode ( rtS , SOLVER_MODE_SINGLETASKING ) ; { ssSetBlockIO ( rtS ,
( ( void * ) & rtB ) ) ; ( void ) memset ( ( ( void * ) & rtB ) , 0 , sizeof
( B ) ) ; } { real_T * x = ( real_T * ) & rtX ; ssSetContStates ( rtS , x ) ;
( void ) memset ( ( void * ) x , 0 , sizeof ( X ) ) ; } { void * dwork = (
void * ) & rtDW ; ssSetRootDWork ( rtS , dwork ) ; ( void ) memset ( dwork ,
0 , sizeof ( DW ) ) ; } { static DataTypeTransInfo dtInfo ; ( void ) memset (
( char_T * ) & dtInfo , 0 , sizeof ( dtInfo ) ) ; ssSetModelMappingInfo ( rtS
, & dtInfo ) ; dtInfo . numDataTypes = 26 ; dtInfo . dataTypeSizes = &
rtDataTypeSizes [ 0 ] ; dtInfo . dataTypeNames = & rtDataTypeNames [ 0 ] ;
dtInfo . BTransTable = & rtBTransTable ; dtInfo . PTransTable = &
rtPTransTable ; dtInfo . dataTypeInfoTable = rtDataTypeInfoTable ; }
air_part1_python2_InitializeDataMapInfo ( ) ; ssSetIsRapidAcceleratorActive (
rtS , true ) ; ssSetRootSS ( rtS , rtS ) ; ssSetVersion ( rtS ,
SIMSTRUCT_VERSION_LEVEL2 ) ; ssSetModelName ( rtS , "air_part1_python2" ) ;
ssSetPath ( rtS , "air_part1_python2" ) ; ssSetTStart ( rtS , 0.0 ) ;
ssSetTFinal ( rtS , 35.0 ) ; ssSetStepSize ( rtS , 5.0E-5 ) ;
ssSetFixedStepSize ( rtS , 5.0E-5 ) ; { static RTWLogInfo rt_DataLoggingInfo
; rt_DataLoggingInfo . loggingInterval = ( NULL ) ; ssSetRTWLogInfo ( rtS , &
rt_DataLoggingInfo ) ; } { { static int_T rt_LoggedStateWidths [ ] = { 1 , 1
, 1 , 1 , 1 , 1 , 1 , 1 , 1 } ; static int_T rt_LoggedStateNumDimensions [ ]
= { 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 } ; static int_T
rt_LoggedStateDimensions [ ] = { 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 , 1 } ; static
boolean_T rt_LoggedStateIsVarDims [ ] = { 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 }
; static BuiltInDTypeId rt_LoggedStateDataTypeIds [ ] = { SS_DOUBLE ,
SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE , SS_DOUBLE ,
SS_DOUBLE , SS_DOUBLE } ; static int_T rt_LoggedStateComplexSignals [ ] = { 0
, 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 } ; static RTWPreprocessingFcnPtr
rt_LoggingStatePreprocessingFcnPtrs [ ] = { ( NULL ) , ( NULL ) , ( NULL ) ,
( NULL ) , ( NULL ) , ( NULL ) , ( NULL ) , ( NULL ) , ( NULL ) } ; static
const char_T * rt_LoggedStateLabels [ ] = { "CSTATE" , "CSTATE" , "CSTATE" ,
"CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" , "CSTATE" , "DSTATE" } ; static
const char_T * rt_LoggedStateBlockNames [ ] = {
"air_part1_python2/&#x30E2;&#x30FC;&#x30BF;&#x30FC;/Integrator1" ,
"air_part1_python2/&#x30E2;&#x30FC;&#x30BF;&#x30FC;/Integrator" ,
"air_part1_python2/Integrator1" , "air_part1_python2/Integrator3" ,
"air_part1_python2/Integrator2" , "air_part1_python2/Integrator" ,
"air_part1_python2/&#x30E2;&#x30FC;&#x30BF;&#x30FC;1/Integrator1" ,
"air_part1_python2/&#x30E2;&#x30FC;&#x30BF;&#x30FC;1/Integrator" ,
"air_part1_python2/Counter\nFree-Running/Output" } ; static const char_T *
rt_LoggedStateNames [ ] = { "" , "" , "" , "" , "" , "" , "" , "" , "DSTATE"
} ; static boolean_T rt_LoggedStateCrossMdlRef [ ] = { 0 , 0 , 0 , 0 , 0 , 0
, 0 , 0 , 0 } ; static RTWLogDataTypeConvert rt_RTWLogDataTypeConvert [ ] = {
{ 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE ,
SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0
, 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 ,
0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 ,
SS_DOUBLE , SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE ,
SS_DOUBLE , 0 , 0 , 0 , 1.0 , 0 , 0.0 } , { 0 , SS_DOUBLE , SS_DOUBLE , 0 , 0
, 0 , 1.0 , 0 , 0.0 } , { 1 , SS_DOUBLE , SS_UINT32 , 64 , 1 , 0 , 1.0 , 0 ,
0.0 } } ; static int_T rt_LoggedStateIdxList [ ] = { 0 , 1 , 2 , 3 , 4 , 5 ,
6 , 7 , 111 } ; static RTWLogSignalInfo rt_LoggedStateSignalInfo = { 9 ,
rt_LoggedStateWidths , rt_LoggedStateNumDimensions , rt_LoggedStateDimensions
, rt_LoggedStateIsVarDims , ( NULL ) , ( NULL ) , rt_LoggedStateDataTypeIds ,
rt_LoggedStateComplexSignals , ( NULL ) , rt_LoggingStatePreprocessingFcnPtrs
, { rt_LoggedStateLabels } , ( NULL ) , ( NULL ) , ( NULL ) , {
rt_LoggedStateBlockNames } , { rt_LoggedStateNames } ,
rt_LoggedStateCrossMdlRef , rt_RTWLogDataTypeConvert , rt_LoggedStateIdxList
} ; static void * rt_LoggedStateSignalPtrs [ 9 ] ; rtliSetLogXSignalPtrs (
ssGetRTWLogInfo ( rtS ) , ( LogSignalPtrsType ) rt_LoggedStateSignalPtrs ) ;
rtliSetLogXSignalInfo ( ssGetRTWLogInfo ( rtS ) , & rt_LoggedStateSignalInfo
) ; rt_LoggedStateSignalPtrs [ 0 ] = ( void * ) & rtX . eypdcundes ;
rt_LoggedStateSignalPtrs [ 1 ] = ( void * ) & rtX . lh2zlfy5gs ;
rt_LoggedStateSignalPtrs [ 2 ] = ( void * ) & rtX . o2miuctf5t ;
rt_LoggedStateSignalPtrs [ 3 ] = ( void * ) & rtX . g1kxrlwt1c ;
rt_LoggedStateSignalPtrs [ 4 ] = ( void * ) & rtX . m0ift0f3ns ;
rt_LoggedStateSignalPtrs [ 5 ] = ( void * ) & rtX . lq2uwsqwxu ;
rt_LoggedStateSignalPtrs [ 6 ] = ( void * ) & rtX . fl2s00rq4n ;
rt_LoggedStateSignalPtrs [ 7 ] = ( void * ) & rtX . cb0w3bhvxx ;
rt_LoggedStateSignalPtrs [ 8 ] = ( void * ) & rtDW . jl0mnuibbh ; }
rtliSetLogT ( ssGetRTWLogInfo ( rtS ) , "tout" ) ; rtliSetLogX (
ssGetRTWLogInfo ( rtS ) , "" ) ; rtliSetLogXFinal ( ssGetRTWLogInfo ( rtS ) ,
"xFinal" ) ; rtliSetLogVarNameModifier ( ssGetRTWLogInfo ( rtS ) , "none" ) ;
rtliSetLogFormat ( ssGetRTWLogInfo ( rtS ) , 4 ) ; rtliSetLogMaxRows (
ssGetRTWLogInfo ( rtS ) , 0 ) ; rtliSetLogDecimation ( ssGetRTWLogInfo ( rtS
) , 1 ) ; rtliSetLogY ( ssGetRTWLogInfo ( rtS ) , "" ) ;
rtliSetLogYSignalInfo ( ssGetRTWLogInfo ( rtS ) , ( NULL ) ) ;
rtliSetLogYSignalPtrs ( ssGetRTWLogInfo ( rtS ) , ( NULL ) ) ; } { static
struct _ssStatesInfo2 statesInfo2 ; ssSetStatesInfo2 ( rtS , & statesInfo2 )
; } { static ssPeriodicStatesInfo periodicStatesInfo ;
ssSetPeriodicStatesInfo ( rtS , & periodicStatesInfo ) ; } { static
ssJacobianPerturbationBounds jacobianPerturbationBounds ;
ssSetJacobianPerturbationBounds ( rtS , & jacobianPerturbationBounds ) ; } {
static ssSolverInfo slvrInfo ; static boolean_T contStatesDisabled [ 8 ] ;
static ssNonContDerivSigInfo nonContDerivSigInfo [ 6 ] = { { 1 * sizeof (
real_T ) , ( char * ) ( & rtB . oqvlx0tggb ) , ( NULL ) } , { 1 * sizeof (
real_T ) , ( char * ) ( & rtB . jqaxfynhz3 ) , ( NULL ) } , { 1 * sizeof (
real_T ) , ( char * ) ( & rtB . hhfhv1g453 ) , ( NULL ) } , { 1 * sizeof (
real_T ) , ( char * ) ( & rtB . gyqrec4ceq ) , ( NULL ) } , { 1 * sizeof (
real_T ) , ( char * ) ( & rtB . gg1qdr0ca0 ) , ( NULL ) } , { 1 * sizeof (
real_T ) , ( char * ) ( & rtB . a405zozv5t ) , ( NULL ) } } ;
ssSetNumNonContDerivSigInfos ( rtS , 6 ) ; ssSetNonContDerivSigInfos ( rtS ,
nonContDerivSigInfo ) ; ssSetSolverInfo ( rtS , & slvrInfo ) ;
ssSetSolverName ( rtS , "ode3" ) ; ssSetVariableStepSolver ( rtS , 0 ) ;
ssSetSolverConsistencyChecking ( rtS , 0 ) ; ssSetSolverAdaptiveZcDetection (
rtS , 1 ) ; ssSetSolverRobustResetMethod ( rtS , 0 ) ;
ssSetSolverStateProjection ( rtS , 0 ) ; ssSetSolverMassMatrixType ( rtS , (
ssMatrixType ) 0 ) ; ssSetSolverMassMatrixNzMax ( rtS , 0 ) ;
ssSetModelOutputs ( rtS , MdlOutputs ) ; ssSetModelUpdate ( rtS , MdlUpdate )
; ssSetModelDerivatives ( rtS , MdlDerivatives ) ; ssSetTNextTid ( rtS ,
INT_MIN ) ; ssSetTNext ( rtS , rtMinusInf ) ; ssSetSolverNeedsReset ( rtS ) ;
ssSetNumNonsampledZCs ( rtS , 0 ) ; ssSetContStateDisabled ( rtS ,
contStatesDisabled ) ; } ssSetChecksumVal ( rtS , 0 , 2532647534U ) ;
ssSetChecksumVal ( rtS , 1 , 717479846U ) ; ssSetChecksumVal ( rtS , 2 ,
1968865415U ) ; ssSetChecksumVal ( rtS , 3 , 3579019364U ) ; { static const
sysRanDType rtAlwaysEnabled = SUBSYS_RAN_BC_ENABLE ; static RTWExtModeInfo
rt_ExtModeInfo ; static const sysRanDType * systemRan [ 27 ] ;
gblRTWExtModeInfo = & rt_ExtModeInfo ; ssSetRTWExtModeInfo ( rtS , &
rt_ExtModeInfo ) ; rteiSetSubSystemActiveVectorAddresses ( & rt_ExtModeInfo ,
systemRan ) ; systemRan [ 0 ] = & rtAlwaysEnabled ; systemRan [ 1 ] = &
rtAlwaysEnabled ; systemRan [ 2 ] = & rtAlwaysEnabled ; systemRan [ 3 ] = &
rtAlwaysEnabled ; systemRan [ 4 ] = & rtAlwaysEnabled ; systemRan [ 5 ] = &
rtAlwaysEnabled ; systemRan [ 6 ] = & rtAlwaysEnabled ; systemRan [ 7 ] = &
rtAlwaysEnabled ; systemRan [ 8 ] = & rtAlwaysEnabled ; systemRan [ 9 ] = &
rtAlwaysEnabled ; systemRan [ 10 ] = & rtAlwaysEnabled ; systemRan [ 11 ] = &
rtAlwaysEnabled ; systemRan [ 12 ] = & rtAlwaysEnabled ; systemRan [ 13 ] = &
rtAlwaysEnabled ; systemRan [ 14 ] = & rtAlwaysEnabled ; systemRan [ 15 ] = &
rtAlwaysEnabled ; systemRan [ 16 ] = & rtAlwaysEnabled ; systemRan [ 17 ] = &
rtAlwaysEnabled ; systemRan [ 18 ] = & rtAlwaysEnabled ; systemRan [ 19 ] = &
rtAlwaysEnabled ; systemRan [ 20 ] = & rtAlwaysEnabled ; systemRan [ 21 ] = &
rtAlwaysEnabled ; systemRan [ 22 ] = & rtAlwaysEnabled ; systemRan [ 23 ] = &
rtAlwaysEnabled ; systemRan [ 24 ] = & rtAlwaysEnabled ; systemRan [ 25 ] = &
rtAlwaysEnabled ; systemRan [ 26 ] = & rtAlwaysEnabled ;
rteiSetModelMappingInfoPtr ( ssGetRTWExtModeInfo ( rtS ) , &
ssGetModelMappingInfo ( rtS ) ) ; rteiSetChecksumsPtr ( ssGetRTWExtModeInfo (
rtS ) , ssGetChecksums ( rtS ) ) ; rteiSetTPtr ( ssGetRTWExtModeInfo ( rtS )
, ssGetTPtr ( rtS ) ) ; } slsaDisallowedBlocksForSimTargetOP ( rtS ,
mr_air_part1_python2_GetSimStateDisallowedBlocks ) ;
slsaGetWorkFcnForSimTargetOP ( rtS , mr_air_part1_python2_GetDWork ) ;
slsaSetWorkFcnForSimTargetOP ( rtS , mr_air_part1_python2_SetDWork ) ;
rt_RapidReadMatFileAndUpdateParams ( rtS ) ; if ( ssGetErrorStatus ( rtS ) )
{ return rtS ; } ssSetNumSFunctions ( rtS , 8 ) ; { static SimStruct
childSFunctions [ 8 ] ; static SimStruct * childSFunctionPtrs [ 8 ] ; ( void
) memset ( ( void * ) & childSFunctions [ 0 ] , 0 , sizeof ( childSFunctions
) ) ; ssSetSFunctions ( rtS , & childSFunctionPtrs [ 0 ] ) ; { int_T i ; for
( i = 0 ; i < 8 ; i ++ ) { ssSetSFunction ( rtS , i , & childSFunctions [ i ]
) ; } } { SimStruct * rts = ssGetSFunction ( rtS , 0 ) ; static time_T
sfcnPeriod [ 1 ] ; static time_T sfcnOffset [ 1 ] ; static int_T sfcnTsMap [
1 ] ; ( void ) memset ( ( void * ) sfcnPeriod , 0 , sizeof ( time_T ) * 1 ) ;
( void ) memset ( ( void * ) sfcnOffset , 0 , sizeof ( time_T ) * 1 ) ;
ssSetSampleTimePtr ( rts , & sfcnPeriod [ 0 ] ) ; ssSetOffsetTimePtr ( rts ,
& sfcnOffset [ 0 ] ) ; ssSetSampleTimeTaskIDPtr ( rts , sfcnTsMap ) ; {
static struct _ssBlkInfo2 _blkInfo2 ; struct _ssBlkInfo2 * blkInfo2 = &
_blkInfo2 ; ssSetBlkInfo2Ptr ( rts , blkInfo2 ) ; } { static struct
_ssPortInfo2 _portInfo2 ; struct _ssPortInfo2 * portInfo2 = & _portInfo2 ;
_ssSetBlkInfo2PortInfo2Ptr ( rts , portInfo2 ) ; } ssSetMdlInfoPtr ( rts ,
ssGetMdlInfoPtr ( rtS ) ) ; { static struct _ssSFcnModelMethods2 methods2 ;
ssSetModelMethods2 ( rts , & methods2 ) ; } { static struct
_ssSFcnModelMethods3 methods3 ; ssSetModelMethods3 ( rts , & methods3 ) ; } {
static struct _ssSFcnModelMethods4 methods4 ; ssSetModelMethods4 ( rts , &
methods4 ) ; } { static struct _ssStatesInfo2 statesInfo2 ; static
ssPeriodicStatesInfo periodicStatesInfo ; static ssJacobianPerturbationBounds
jacPerturbationBounds ; ssSetStatesInfo2 ( rts , & statesInfo2 ) ;
ssSetPeriodicStatesInfo ( rts , & periodicStatesInfo ) ;
ssSetJacobianPerturbationBounds ( rts , & jacPerturbationBounds ) ; } {
_ssSetNumInputPorts ( rts , 1 ) ; static struct _ssPortInputs inputPortInfo [
1 ] ; ssSetPortInfoForInputs ( rts , & inputPortInfo [ 0 ] ) ; { static
struct _ssInPortUnit inputPortUnits [ 1 ] ; _ssSetPortInfo2ForInputUnits (
rts , & inputPortUnits [ 0 ] ) ; } ssSetInputPortUnit ( rts , 0 , 0 ) ; {
static struct _ssInPortCoSimAttribute inputPortCoSimAttribute [ 1 ] ;
_ssSetPortInfo2ForInputCoSimAttribute ( rts , & inputPortCoSimAttribute [ 0 ]
) ; } ssSetInputPortIsContinuousQuantity ( rts , 0 , 0 ) ; { static real_T
const * sfcnUPtrs [ 1 ] ; sfcnUPtrs [ 0 ] = & rtB . lonvbzqzr1 ;
ssSetInputPortSignalPtrs ( rts , 0 , ( InputPtrsType ) & sfcnUPtrs [ 0 ] ) ;
_ssSetInputPortNumDimensions ( rts , 0 , 1 ) ; ssSetInputPortWidthAsInt ( rts
, 0 , 1 ) ; } } { static struct _ssPortOutputs outputPortInfo [ 1 ] ;
ssSetPortInfoForOutputs ( rts , & outputPortInfo [ 0 ] ) ;
_ssSetNumOutputPorts ( rts , 1 ) ; { static struct _ssOutPortUnit
outputPortUnits [ 1 ] ; _ssSetPortInfo2ForOutputUnits ( rts , &
outputPortUnits [ 0 ] ) ; } ssSetOutputPortUnit ( rts , 0 , 0 ) ; { static
struct _ssOutPortCoSimAttribute outputPortCoSimAttribute [ 1 ] ;
_ssSetPortInfo2ForOutputCoSimAttribute ( rts , & outputPortCoSimAttribute [ 0
] ) ; } ssSetOutputPortIsContinuousQuantity ( rts , 0 , 0 ) ; {
_ssSetOutputPortNumDimensions ( rts , 0 , 1 ) ; ssSetOutputPortWidthAsInt (
rts , 0 , 128 ) ; ssSetOutputPortSignal ( rts , 0 , ( ( uint8_T * ) rtB .
hjr01anyo4 ) ) ; } } ssSetModelName ( rts , "ASCII Encode" ) ; ssSetPath (
rts , "air_part1_python2/ASCII Encode" ) ; if ( ssGetRTModel ( rtS ) == (
NULL ) ) { ssSetParentSS ( rts , rtS ) ; ssSetRootSS ( rts , ssGetRootSS (
rtS ) ) ; } else { ssSetRTModel ( rts , ssGetRTModel ( rtS ) ) ;
ssSetParentSS ( rts , ( NULL ) ) ; ssSetRootSS ( rts , rts ) ; } ssSetVersion
( rts , SIMSTRUCT_VERSION_LEVEL2 ) ; { static mxArray * sfcnParams [ 4 ] ;
ssSetSFcnParamsCount ( rts , 4 ) ; ssSetSFcnParamsPtr ( rts , & sfcnParams [
0 ] ) ; ssSetSFcnParam ( rts , 0 , ( mxArray * ) rtP . ASCIIEncode_P1_Size )
; ssSetSFcnParam ( rts , 1 , ( mxArray * ) rtP . ASCIIEncode_P2_Size ) ;
ssSetSFcnParam ( rts , 2 , ( mxArray * ) rtP . ASCIIEncode_P3_Size ) ;
ssSetSFcnParam ( rts , 3 , ( mxArray * ) rtP . ASCIIEncode_P4_Size ) ; }
ssSetPWork ( rts , ( void * * ) & rtDW . gnziensnjw ) ; { static struct
_ssDWorkRecord dWorkRecord [ 1 ] ; static struct _ssDWorkAuxRecord
dWorkAuxRecord [ 1 ] ; ssSetSFcnDWork ( rts , dWorkRecord ) ;
ssSetSFcnDWorkAux ( rts , dWorkAuxRecord ) ; ssSetNumDWorkAsInt ( rts , 1 ) ;
ssSetDWorkWidthAsInt ( rts , 0 , 1 ) ; ssSetDWorkDataType ( rts , 0 ,
SS_POINTER ) ; ssSetDWorkComplexSignal ( rts , 0 , 0 ) ; ssSetDWork ( rts , 0
, & rtDW . gnziensnjw ) ; } slasciiencode ( rts ) ; sfcnInitializeSizes ( rts
) ; sfcnInitializeSampleTimes ( rts ) ; ssSetSampleTime ( rts , 0 , 5.0E-5 )
; ssSetOffsetTime ( rts , 0 , 0.0 ) ; sfcnTsMap [ 0 ] = 1 ;
ssSetNumNonsampledZCsAsInt ( rts , 0 ) ; _ssSetInputPortConnected ( rts , 0 ,
1 ) ; _ssSetOutputPortConnected ( rts , 0 , 1 ) ; _ssSetOutputPortBeingMerged
( rts , 0 , 0 ) ; ssSetInputPortBufferDstPort ( rts , 0 , - 1 ) ; } {
SimStruct * rts = ssGetSFunction ( rtS , 1 ) ; static time_T sfcnPeriod [ 1 ]
; static time_T sfcnOffset [ 1 ] ; static int_T sfcnTsMap [ 1 ] ; ( void )
memset ( ( void * ) sfcnPeriod , 0 , sizeof ( time_T ) * 1 ) ; ( void )
memset ( ( void * ) sfcnOffset , 0 , sizeof ( time_T ) * 1 ) ;
ssSetSampleTimePtr ( rts , & sfcnPeriod [ 0 ] ) ; ssSetOffsetTimePtr ( rts ,
& sfcnOffset [ 0 ] ) ; ssSetSampleTimeTaskIDPtr ( rts , sfcnTsMap ) ; {
static struct _ssBlkInfo2 _blkInfo2 ; struct _ssBlkInfo2 * blkInfo2 = &
_blkInfo2 ; ssSetBlkInfo2Ptr ( rts , blkInfo2 ) ; } { static struct
_ssPortInfo2 _portInfo2 ; struct _ssPortInfo2 * portInfo2 = & _portInfo2 ;
_ssSetBlkInfo2PortInfo2Ptr ( rts , portInfo2 ) ; } ssSetMdlInfoPtr ( rts ,
ssGetMdlInfoPtr ( rtS ) ) ; { static struct _ssSFcnModelMethods2 methods2 ;
ssSetModelMethods2 ( rts , & methods2 ) ; } { static struct
_ssSFcnModelMethods3 methods3 ; ssSetModelMethods3 ( rts , & methods3 ) ; } {
static struct _ssSFcnModelMethods4 methods4 ; ssSetModelMethods4 ( rts , &
methods4 ) ; } { static struct _ssStatesInfo2 statesInfo2 ; static
ssPeriodicStatesInfo periodicStatesInfo ; static ssJacobianPerturbationBounds
jacPerturbationBounds ; ssSetStatesInfo2 ( rts , & statesInfo2 ) ;
ssSetPeriodicStatesInfo ( rts , & periodicStatesInfo ) ;
ssSetJacobianPerturbationBounds ( rts , & jacPerturbationBounds ) ; } {
_ssSetNumInputPorts ( rts , 1 ) ; static struct _ssPortInputs inputPortInfo [
1 ] ; ssSetPortInfoForInputs ( rts , & inputPortInfo [ 0 ] ) ; { static
struct _ssInPortUnit inputPortUnits [ 1 ] ; _ssSetPortInfo2ForInputUnits (
rts , & inputPortUnits [ 0 ] ) ; } ssSetInputPortUnit ( rts , 0 , 0 ) ; {
static struct _ssInPortCoSimAttribute inputPortCoSimAttribute [ 1 ] ;
_ssSetPortInfo2ForInputCoSimAttribute ( rts , & inputPortCoSimAttribute [ 0 ]
) ; } ssSetInputPortIsContinuousQuantity ( rts , 0 , 0 ) ; { static real_T
const * sfcnUPtrs [ 1 ] ; sfcnUPtrs [ 0 ] = & rtB . firups0wj2 ;
ssSetInputPortSignalPtrs ( rts , 0 , ( InputPtrsType ) & sfcnUPtrs [ 0 ] ) ;
_ssSetInputPortNumDimensions ( rts , 0 , 1 ) ; ssSetInputPortWidthAsInt ( rts
, 0 , 1 ) ; } } { static struct _ssPortOutputs outputPortInfo [ 1 ] ;
ssSetPortInfoForOutputs ( rts , & outputPortInfo [ 0 ] ) ;
_ssSetNumOutputPorts ( rts , 1 ) ; { static struct _ssOutPortUnit
outputPortUnits [ 1 ] ; _ssSetPortInfo2ForOutputUnits ( rts , &
outputPortUnits [ 0 ] ) ; } ssSetOutputPortUnit ( rts , 0 , 0 ) ; { static
struct _ssOutPortCoSimAttribute outputPortCoSimAttribute [ 1 ] ;
_ssSetPortInfo2ForOutputCoSimAttribute ( rts , & outputPortCoSimAttribute [ 0
] ) ; } ssSetOutputPortIsContinuousQuantity ( rts , 0 , 0 ) ; {
_ssSetOutputPortNumDimensions ( rts , 0 , 1 ) ; ssSetOutputPortWidthAsInt (
rts , 0 , 128 ) ; ssSetOutputPortSignal ( rts , 0 , ( ( uint8_T * ) rtB .
f3ybeuoetm ) ) ; } } ssSetModelName ( rts , "ASCII Encode1" ) ; ssSetPath (
rts , "air_part1_python2/ASCII Encode1" ) ; if ( ssGetRTModel ( rtS ) == (
NULL ) ) { ssSetParentSS ( rts , rtS ) ; ssSetRootSS ( rts , ssGetRootSS (
rtS ) ) ; } else { ssSetRTModel ( rts , ssGetRTModel ( rtS ) ) ;
ssSetParentSS ( rts , ( NULL ) ) ; ssSetRootSS ( rts , rts ) ; } ssSetVersion
( rts , SIMSTRUCT_VERSION_LEVEL2 ) ; { static mxArray * sfcnParams [ 4 ] ;
ssSetSFcnParamsCount ( rts , 4 ) ; ssSetSFcnParamsPtr ( rts , & sfcnParams [
0 ] ) ; ssSetSFcnParam ( rts , 0 , ( mxArray * ) rtP . ASCIIEncode1_P1_Size )
; ssSetSFcnParam ( rts , 1 , ( mxArray * ) rtP . ASCIIEncode1_P2_Size ) ;
ssSetSFcnParam ( rts , 2 , ( mxArray * ) rtP . ASCIIEncode1_P3_Size ) ;
ssSetSFcnParam ( rts , 3 , ( mxArray * ) rtP . ASCIIEncode1_P4_Size ) ; }
ssSetPWork ( rts , ( void * * ) & rtDW . flhcdf5cvg ) ; { static struct
_ssDWorkRecord dWorkRecord [ 1 ] ; static struct _ssDWorkAuxRecord
dWorkAuxRecord [ 1 ] ; ssSetSFcnDWork ( rts , dWorkRecord ) ;
ssSetSFcnDWorkAux ( rts , dWorkAuxRecord ) ; ssSetNumDWorkAsInt ( rts , 1 ) ;
ssSetDWorkWidthAsInt ( rts , 0 , 1 ) ; ssSetDWorkDataType ( rts , 0 ,
SS_POINTER ) ; ssSetDWorkComplexSignal ( rts , 0 , 0 ) ; ssSetDWork ( rts , 0
, & rtDW . flhcdf5cvg ) ; } slasciiencode ( rts ) ; sfcnInitializeSizes ( rts
) ; sfcnInitializeSampleTimes ( rts ) ; ssSetSampleTime ( rts , 0 , 5.0E-5 )
; ssSetOffsetTime ( rts , 0 , 0.0 ) ; sfcnTsMap [ 0 ] = 1 ;
ssSetNumNonsampledZCsAsInt ( rts , 0 ) ; _ssSetInputPortConnected ( rts , 0 ,
1 ) ; _ssSetOutputPortConnected ( rts , 0 , 1 ) ; _ssSetOutputPortBeingMerged
( rts , 0 , 0 ) ; ssSetInputPortBufferDstPort ( rts , 0 , - 1 ) ; } {
SimStruct * rts = ssGetSFunction ( rtS , 2 ) ; static time_T sfcnPeriod [ 1 ]
; static time_T sfcnOffset [ 1 ] ; static int_T sfcnTsMap [ 1 ] ; ( void )
memset ( ( void * ) sfcnPeriod , 0 , sizeof ( time_T ) * 1 ) ; ( void )
memset ( ( void * ) sfcnOffset , 0 , sizeof ( time_T ) * 1 ) ;
ssSetSampleTimePtr ( rts , & sfcnPeriod [ 0 ] ) ; ssSetOffsetTimePtr ( rts ,
& sfcnOffset [ 0 ] ) ; ssSetSampleTimeTaskIDPtr ( rts , sfcnTsMap ) ; {
static struct _ssBlkInfo2 _blkInfo2 ; struct _ssBlkInfo2 * blkInfo2 = &
_blkInfo2 ; ssSetBlkInfo2Ptr ( rts , blkInfo2 ) ; } { static struct
_ssPortInfo2 _portInfo2 ; struct _ssPortInfo2 * portInfo2 = & _portInfo2 ;
_ssSetBlkInfo2PortInfo2Ptr ( rts , portInfo2 ) ; } ssSetMdlInfoPtr ( rts ,
ssGetMdlInfoPtr ( rtS ) ) ; { static struct _ssSFcnModelMethods2 methods2 ;
ssSetModelMethods2 ( rts , & methods2 ) ; } { static struct
_ssSFcnModelMethods3 methods3 ; ssSetModelMethods3 ( rts , & methods3 ) ; } {
static struct _ssSFcnModelMethods4 methods4 ; ssSetModelMethods4 ( rts , &
methods4 ) ; } { static struct _ssStatesInfo2 statesInfo2 ; static
ssPeriodicStatesInfo periodicStatesInfo ; static ssJacobianPerturbationBounds
jacPerturbationBounds ; ssSetStatesInfo2 ( rts , & statesInfo2 ) ;
ssSetPeriodicStatesInfo ( rts , & periodicStatesInfo ) ;
ssSetJacobianPerturbationBounds ( rts , & jacPerturbationBounds ) ; } {
_ssSetNumInputPorts ( rts , 1 ) ; static struct _ssPortInputs inputPortInfo [
1 ] ; ssSetPortInfoForInputs ( rts , & inputPortInfo [ 0 ] ) ; { static
struct _ssInPortUnit inputPortUnits [ 1 ] ; _ssSetPortInfo2ForInputUnits (
rts , & inputPortUnits [ 0 ] ) ; } ssSetInputPortUnit ( rts , 0 , 0 ) ; {
static struct _ssInPortCoSimAttribute inputPortCoSimAttribute [ 1 ] ;
_ssSetPortInfo2ForInputCoSimAttribute ( rts , & inputPortCoSimAttribute [ 0 ]
) ; } ssSetInputPortIsContinuousQuantity ( rts , 0 , 0 ) ; {
ssSetInputPortRequiredContiguous ( rts , 0 , 1 ) ; ssSetInputPortSignal ( rts
, 0 , & rtB . ixgganvvtz ) ; _ssSetInputPortNumDimensions ( rts , 0 , 1 ) ;
ssSetInputPortWidthAsInt ( rts , 0 , 1 ) ; } } { static struct _ssPortOutputs
outputPortInfo [ 1 ] ; ssSetPortInfoForOutputs ( rts , & outputPortInfo [ 0 ]
) ; _ssSetNumOutputPorts ( rts , 1 ) ; { static struct _ssOutPortUnit
outputPortUnits [ 1 ] ; _ssSetPortInfo2ForOutputUnits ( rts , &
outputPortUnits [ 0 ] ) ; } ssSetOutputPortUnit ( rts , 0 , 0 ) ; { static
struct _ssOutPortCoSimAttribute outputPortCoSimAttribute [ 1 ] ;
_ssSetPortInfo2ForOutputCoSimAttribute ( rts , & outputPortCoSimAttribute [ 0
] ) ; } ssSetOutputPortIsContinuousQuantity ( rts , 0 , 0 ) ; {
_ssSetOutputPortNumDimensions ( rts , 0 , 1 ) ; ssSetOutputPortWidthAsInt (
rts , 0 , 1 ) ; ssSetOutputPortSignal ( rts , 0 , ( ( real_T * ) & rtB .
bkayq3jpfr ) ) ; } } ssSetModelName ( rts , "ASCII Decode" ) ; ssSetPath (
rts , "air_part1_python2/ASCII Decode" ) ; if ( ssGetRTModel ( rtS ) == (
NULL ) ) { ssSetParentSS ( rts , rtS ) ; ssSetRootSS ( rts , ssGetRootSS (
rtS ) ) ; } else { ssSetRTModel ( rts , ssGetRTModel ( rtS ) ) ;
ssSetParentSS ( rts , ( NULL ) ) ; ssSetRootSS ( rts , rts ) ; } ssSetVersion
( rts , SIMSTRUCT_VERSION_LEVEL2 ) ; { static mxArray * sfcnParams [ 3 ] ;
ssSetSFcnParamsCount ( rts , 3 ) ; ssSetSFcnParamsPtr ( rts , & sfcnParams [
0 ] ) ; ssSetSFcnParam ( rts , 0 , ( mxArray * ) rtP . ASCIIDecode_P1_Size )
; ssSetSFcnParam ( rts , 1 , ( mxArray * ) rtP . ASCIIDecode_P2_Size ) ;
ssSetSFcnParam ( rts , 2 , ( mxArray * ) rtP . ASCIIDecode_P3_Size ) ; }
ssSetIWork ( rts , ( int_T * ) & rtDW . l3xbscxi2g [ 0 ] ) ; ssSetPWork ( rts
, ( void * * ) & rtDW . kao0trtwi5 [ 0 ] ) ; { static struct _ssDWorkRecord
dWorkRecord [ 2 ] ; static struct _ssDWorkAuxRecord dWorkAuxRecord [ 2 ] ;
ssSetSFcnDWork ( rts , dWorkRecord ) ; ssSetSFcnDWorkAux ( rts ,
dWorkAuxRecord ) ; ssSetNumDWorkAsInt ( rts , 2 ) ; ssSetDWorkWidthAsInt (
rts , 0 , 4 ) ; ssSetDWorkDataType ( rts , 0 , SS_INTEGER ) ;
ssSetDWorkComplexSignal ( rts , 0 , 0 ) ; ssSetDWork ( rts , 0 , & rtDW .
l3xbscxi2g [ 0 ] ) ; ssSetDWorkWidthAsInt ( rts , 1 , 2 ) ;
ssSetDWorkDataType ( rts , 1 , SS_POINTER ) ; ssSetDWorkComplexSignal ( rts ,
1 , 0 ) ; ssSetDWork ( rts , 1 , & rtDW . kao0trtwi5 [ 0 ] ) ; }
slasciidecode ( rts ) ; sfcnInitializeSizes ( rts ) ;
sfcnInitializeSampleTimes ( rts ) ; ssSetSampleTime ( rts , 0 , 0.04 ) ;
ssSetOffsetTime ( rts , 0 , 0.0 ) ; sfcnTsMap [ 0 ] = 2 ;
ssSetInputPortWidthAsInt ( rts , 0 , 1 ) ; ssSetInputPortDataType ( rts , 0 ,
SS_UINT8 ) ; ssSetInputPortComplexSignal ( rts , 0 , 0 ) ;
ssSetInputPortFrameData ( rts , 0 , 0 ) ; ssSetInputPortUnit ( rts , 0 , 0 )
; ssSetInputPortIsContinuousQuantity ( rts , 0 , 0 ) ;
ssSetNumNonsampledZCsAsInt ( rts , 0 ) ; _ssSetInputPortConnected ( rts , 0 ,
1 ) ; _ssSetOutputPortConnected ( rts , 0 , 1 ) ; _ssSetOutputPortBeingMerged
( rts , 0 , 0 ) ; ssSetInputPortBufferDstPort ( rts , 0 , - 1 ) ; } {
SimStruct * rts = ssGetSFunction ( rtS , 3 ) ; static time_T sfcnPeriod [ 1 ]
; static time_T sfcnOffset [ 1 ] ; static int_T sfcnTsMap [ 1 ] ; ( void )
memset ( ( void * ) sfcnPeriod , 0 , sizeof ( time_T ) * 1 ) ; ( void )
memset ( ( void * ) sfcnOffset , 0 , sizeof ( time_T ) * 1 ) ;
ssSetSampleTimePtr ( rts , & sfcnPeriod [ 0 ] ) ; ssSetOffsetTimePtr ( rts ,
& sfcnOffset [ 0 ] ) ; ssSetSampleTimeTaskIDPtr ( rts , sfcnTsMap ) ; {
static struct _ssBlkInfo2 _blkInfo2 ; struct _ssBlkInfo2 * blkInfo2 = &
_blkInfo2 ; ssSetBlkInfo2Ptr ( rts , blkInfo2 ) ; } { static struct
_ssPortInfo2 _portInfo2 ; struct _ssPortInfo2 * portInfo2 = & _portInfo2 ;
_ssSetBlkInfo2PortInfo2Ptr ( rts , portInfo2 ) ; } ssSetMdlInfoPtr ( rts ,
ssGetMdlInfoPtr ( rtS ) ) ; { static struct _ssSFcnModelMethods2 methods2 ;
ssSetModelMethods2 ( rts , & methods2 ) ; } { static struct
_ssSFcnModelMethods3 methods3 ; ssSetModelMethods3 ( rts , & methods3 ) ; } {
static struct _ssSFcnModelMethods4 methods4 ; ssSetModelMethods4 ( rts , &
methods4 ) ; } { static struct _ssStatesInfo2 statesInfo2 ; static
ssPeriodicStatesInfo periodicStatesInfo ; static ssJacobianPerturbationBounds
jacPerturbationBounds ; ssSetStatesInfo2 ( rts , & statesInfo2 ) ;
ssSetPeriodicStatesInfo ( rts , & periodicStatesInfo ) ;
ssSetJacobianPerturbationBounds ( rts , & jacPerturbationBounds ) ; } {
_ssSetNumInputPorts ( rts , 1 ) ; static struct _ssPortInputs inputPortInfo [
1 ] ; ssSetPortInfoForInputs ( rts , & inputPortInfo [ 0 ] ) ; { static
struct _ssInPortUnit inputPortUnits [ 1 ] ; _ssSetPortInfo2ForInputUnits (
rts , & inputPortUnits [ 0 ] ) ; } ssSetInputPortUnit ( rts , 0 , 0 ) ; {
static struct _ssInPortCoSimAttribute inputPortCoSimAttribute [ 1 ] ;
_ssSetPortInfo2ForInputCoSimAttribute ( rts , & inputPortCoSimAttribute [ 0 ]
) ; } ssSetInputPortIsContinuousQuantity ( rts , 0 , 0 ) ; {
ssSetInputPortRequiredContiguous ( rts , 0 , 1 ) ; ssSetInputPortSignal ( rts
, 0 , & rtB . ktsgdw2c41 ) ; _ssSetInputPortNumDimensions ( rts , 0 , 1 ) ;
ssSetInputPortWidthAsInt ( rts , 0 , 1 ) ; } } { static struct _ssPortOutputs
outputPortInfo [ 1 ] ; ssSetPortInfoForOutputs ( rts , & outputPortInfo [ 0 ]
) ; _ssSetNumOutputPorts ( rts , 1 ) ; { static struct _ssOutPortUnit
outputPortUnits [ 1 ] ; _ssSetPortInfo2ForOutputUnits ( rts , &
outputPortUnits [ 0 ] ) ; } ssSetOutputPortUnit ( rts , 0 , 0 ) ; { static
struct _ssOutPortCoSimAttribute outputPortCoSimAttribute [ 1 ] ;
_ssSetPortInfo2ForOutputCoSimAttribute ( rts , & outputPortCoSimAttribute [ 0
] ) ; } ssSetOutputPortIsContinuousQuantity ( rts , 0 , 0 ) ; {
_ssSetOutputPortNumDimensions ( rts , 0 , 1 ) ; ssSetOutputPortWidthAsInt (
rts , 0 , 1 ) ; ssSetOutputPortSignal ( rts , 0 , ( ( real_T * ) & rtB .
arjieh1qz2 ) ) ; } } ssSetModelName ( rts , "ASCII Decode1" ) ; ssSetPath (
rts , "air_part1_python2/ASCII Decode1" ) ; if ( ssGetRTModel ( rtS ) == (
NULL ) ) { ssSetParentSS ( rts , rtS ) ; ssSetRootSS ( rts , ssGetRootSS (
rtS ) ) ; } else { ssSetRTModel ( rts , ssGetRTModel ( rtS ) ) ;
ssSetParentSS ( rts , ( NULL ) ) ; ssSetRootSS ( rts , rts ) ; } ssSetVersion
( rts , SIMSTRUCT_VERSION_LEVEL2 ) ; { static mxArray * sfcnParams [ 3 ] ;
ssSetSFcnParamsCount ( rts , 3 ) ; ssSetSFcnParamsPtr ( rts , & sfcnParams [
0 ] ) ; ssSetSFcnParam ( rts , 0 , ( mxArray * ) rtP . ASCIIDecode1_P1_Size )
; ssSetSFcnParam ( rts , 1 , ( mxArray * ) rtP . ASCIIDecode1_P2_Size ) ;
ssSetSFcnParam ( rts , 2 , ( mxArray * ) rtP . ASCIIDecode1_P3_Size ) ; }
ssSetIWork ( rts , ( int_T * ) & rtDW . dcitng5a3n [ 0 ] ) ; ssSetPWork ( rts
, ( void * * ) & rtDW . okuzazai0s [ 0 ] ) ; { static struct _ssDWorkRecord
dWorkRecord [ 2 ] ; static struct _ssDWorkAuxRecord dWorkAuxRecord [ 2 ] ;
ssSetSFcnDWork ( rts , dWorkRecord ) ; ssSetSFcnDWorkAux ( rts ,
dWorkAuxRecord ) ; ssSetNumDWorkAsInt ( rts , 2 ) ; ssSetDWorkWidthAsInt (
rts , 0 , 4 ) ; ssSetDWorkDataType ( rts , 0 , SS_INTEGER ) ;
ssSetDWorkComplexSignal ( rts , 0 , 0 ) ; ssSetDWork ( rts , 0 , & rtDW .
dcitng5a3n [ 0 ] ) ; ssSetDWorkWidthAsInt ( rts , 1 , 2 ) ;
ssSetDWorkDataType ( rts , 1 , SS_POINTER ) ; ssSetDWorkComplexSignal ( rts ,
1 , 0 ) ; ssSetDWork ( rts , 1 , & rtDW . okuzazai0s [ 0 ] ) ; }
slasciidecode ( rts ) ; sfcnInitializeSizes ( rts ) ;
sfcnInitializeSampleTimes ( rts ) ; ssSetSampleTime ( rts , 0 , 0.04 ) ;
ssSetOffsetTime ( rts , 0 , 0.0 ) ; sfcnTsMap [ 0 ] = 2 ;
ssSetInputPortWidthAsInt ( rts , 0 , 1 ) ; ssSetInputPortDataType ( rts , 0 ,
SS_UINT8 ) ; ssSetInputPortComplexSignal ( rts , 0 , 0 ) ;
ssSetInputPortFrameData ( rts , 0 , 0 ) ; ssSetInputPortUnit ( rts , 0 , 0 )
; ssSetInputPortIsContinuousQuantity ( rts , 0 , 0 ) ;
ssSetNumNonsampledZCsAsInt ( rts , 0 ) ; _ssSetInputPortConnected ( rts , 0 ,
1 ) ; _ssSetOutputPortConnected ( rts , 0 , 1 ) ; _ssSetOutputPortBeingMerged
( rts , 0 , 0 ) ; ssSetInputPortBufferDstPort ( rts , 0 , - 1 ) ; } {
SimStruct * rts = ssGetSFunction ( rtS , 4 ) ; static time_T sfcnPeriod [ 1 ]
; static time_T sfcnOffset [ 1 ] ; static int_T sfcnTsMap [ 1 ] ; ( void )
memset ( ( void * ) sfcnPeriod , 0 , sizeof ( time_T ) * 1 ) ; ( void )
memset ( ( void * ) sfcnOffset , 0 , sizeof ( time_T ) * 1 ) ;
ssSetSampleTimePtr ( rts , & sfcnPeriod [ 0 ] ) ; ssSetOffsetTimePtr ( rts ,
& sfcnOffset [ 0 ] ) ; ssSetSampleTimeTaskIDPtr ( rts , sfcnTsMap ) ; {
static struct _ssBlkInfo2 _blkInfo2 ; struct _ssBlkInfo2 * blkInfo2 = &
_blkInfo2 ; ssSetBlkInfo2Ptr ( rts , blkInfo2 ) ; } { static struct
_ssPortInfo2 _portInfo2 ; struct _ssPortInfo2 * portInfo2 = & _portInfo2 ;
_ssSetBlkInfo2PortInfo2Ptr ( rts , portInfo2 ) ; } ssSetMdlInfoPtr ( rts ,
ssGetMdlInfoPtr ( rtS ) ) ; { static struct _ssSFcnModelMethods2 methods2 ;
ssSetModelMethods2 ( rts , & methods2 ) ; } { static struct
_ssSFcnModelMethods3 methods3 ; ssSetModelMethods3 ( rts , & methods3 ) ; } {
static struct _ssSFcnModelMethods4 methods4 ; ssSetModelMethods4 ( rts , &
methods4 ) ; } { static struct _ssStatesInfo2 statesInfo2 ; static
ssPeriodicStatesInfo periodicStatesInfo ; static ssJacobianPerturbationBounds
jacPerturbationBounds ; ssSetStatesInfo2 ( rts , & statesInfo2 ) ;
ssSetPeriodicStatesInfo ( rts , & periodicStatesInfo ) ;
ssSetJacobianPerturbationBounds ( rts , & jacPerturbationBounds ) ; } {
_ssSetNumInputPorts ( rts , 1 ) ; static struct _ssPortInputs inputPortInfo [
1 ] ; ssSetPortInfoForInputs ( rts , & inputPortInfo [ 0 ] ) ; { static
struct _ssInPortUnit inputPortUnits [ 1 ] ; _ssSetPortInfo2ForInputUnits (
rts , & inputPortUnits [ 0 ] ) ; } ssSetInputPortUnit ( rts , 0 , 0 ) ; {
static struct _ssInPortCoSimAttribute inputPortCoSimAttribute [ 1 ] ;
_ssSetPortInfo2ForInputCoSimAttribute ( rts , & inputPortCoSimAttribute [ 0 ]
) ; } ssSetInputPortIsContinuousQuantity ( rts , 0 , 0 ) ; {
ssSetInputPortRequiredContiguous ( rts , 0 , 1 ) ; ssSetInputPortSignal ( rts
, 0 , & rtB . mimixuazso ) ; _ssSetInputPortNumDimensions ( rts , 0 , 1 ) ;
ssSetInputPortWidthAsInt ( rts , 0 , 1 ) ; } } { static struct _ssPortOutputs
outputPortInfo [ 1 ] ; ssSetPortInfoForOutputs ( rts , & outputPortInfo [ 0 ]
) ; _ssSetNumOutputPorts ( rts , 1 ) ; { static struct _ssOutPortUnit
outputPortUnits [ 1 ] ; _ssSetPortInfo2ForOutputUnits ( rts , &
outputPortUnits [ 0 ] ) ; } ssSetOutputPortUnit ( rts , 0 , 0 ) ; { static
struct _ssOutPortCoSimAttribute outputPortCoSimAttribute [ 1 ] ;
_ssSetPortInfo2ForOutputCoSimAttribute ( rts , & outputPortCoSimAttribute [ 0
] ) ; } ssSetOutputPortIsContinuousQuantity ( rts , 0 , 0 ) ; {
_ssSetOutputPortNumDimensions ( rts , 0 , 1 ) ; ssSetOutputPortWidthAsInt (
rts , 0 , 1 ) ; ssSetOutputPortSignal ( rts , 0 , ( ( real_T * ) & rtB .
b0atyboa0x ) ) ; } } ssSetModelName ( rts , "ASCII Decode2" ) ; ssSetPath (
rts , "air_part1_python2/ASCII Decode2" ) ; if ( ssGetRTModel ( rtS ) == (
NULL ) ) { ssSetParentSS ( rts , rtS ) ; ssSetRootSS ( rts , ssGetRootSS (
rtS ) ) ; } else { ssSetRTModel ( rts , ssGetRTModel ( rtS ) ) ;
ssSetParentSS ( rts , ( NULL ) ) ; ssSetRootSS ( rts , rts ) ; } ssSetVersion
( rts , SIMSTRUCT_VERSION_LEVEL2 ) ; { static mxArray * sfcnParams [ 3 ] ;
ssSetSFcnParamsCount ( rts , 3 ) ; ssSetSFcnParamsPtr ( rts , & sfcnParams [
0 ] ) ; ssSetSFcnParam ( rts , 0 , ( mxArray * ) rtP . ASCIIDecode2_P1_Size )
; ssSetSFcnParam ( rts , 1 , ( mxArray * ) rtP . ASCIIDecode2_P2_Size ) ;
ssSetSFcnParam ( rts , 2 , ( mxArray * ) rtP . ASCIIDecode2_P3_Size ) ; }
ssSetIWork ( rts , ( int_T * ) & rtDW . jmc5mhc4s2 [ 0 ] ) ; ssSetPWork ( rts
, ( void * * ) & rtDW . pjgwumfyer [ 0 ] ) ; { static struct _ssDWorkRecord
dWorkRecord [ 2 ] ; static struct _ssDWorkAuxRecord dWorkAuxRecord [ 2 ] ;
ssSetSFcnDWork ( rts , dWorkRecord ) ; ssSetSFcnDWorkAux ( rts ,
dWorkAuxRecord ) ; ssSetNumDWorkAsInt ( rts , 2 ) ; ssSetDWorkWidthAsInt (
rts , 0 , 4 ) ; ssSetDWorkDataType ( rts , 0 , SS_INTEGER ) ;
ssSetDWorkComplexSignal ( rts , 0 , 0 ) ; ssSetDWork ( rts , 0 , & rtDW .
jmc5mhc4s2 [ 0 ] ) ; ssSetDWorkWidthAsInt ( rts , 1 , 2 ) ;
ssSetDWorkDataType ( rts , 1 , SS_POINTER ) ; ssSetDWorkComplexSignal ( rts ,
1 , 0 ) ; ssSetDWork ( rts , 1 , & rtDW . pjgwumfyer [ 0 ] ) ; }
slasciidecode ( rts ) ; sfcnInitializeSizes ( rts ) ;
sfcnInitializeSampleTimes ( rts ) ; ssSetSampleTime ( rts , 0 , 0.04 ) ;
ssSetOffsetTime ( rts , 0 , 0.0 ) ; sfcnTsMap [ 0 ] = 2 ;
ssSetInputPortWidthAsInt ( rts , 0 , 1 ) ; ssSetInputPortDataType ( rts , 0 ,
SS_UINT8 ) ; ssSetInputPortComplexSignal ( rts , 0 , 0 ) ;
ssSetInputPortFrameData ( rts , 0 , 0 ) ; ssSetInputPortUnit ( rts , 0 , 0 )
; ssSetInputPortIsContinuousQuantity ( rts , 0 , 0 ) ;
ssSetNumNonsampledZCsAsInt ( rts , 0 ) ; _ssSetInputPortConnected ( rts , 0 ,
1 ) ; _ssSetOutputPortConnected ( rts , 0 , 1 ) ; _ssSetOutputPortBeingMerged
( rts , 0 , 0 ) ; ssSetInputPortBufferDstPort ( rts , 0 , - 1 ) ; } {
SimStruct * rts = ssGetSFunction ( rtS , 5 ) ; static time_T sfcnPeriod [ 1 ]
; static time_T sfcnOffset [ 1 ] ; static int_T sfcnTsMap [ 1 ] ; ( void )
memset ( ( void * ) sfcnPeriod , 0 , sizeof ( time_T ) * 1 ) ; ( void )
memset ( ( void * ) sfcnOffset , 0 , sizeof ( time_T ) * 1 ) ;
ssSetSampleTimePtr ( rts , & sfcnPeriod [ 0 ] ) ; ssSetOffsetTimePtr ( rts ,
& sfcnOffset [ 0 ] ) ; ssSetSampleTimeTaskIDPtr ( rts , sfcnTsMap ) ; {
static struct _ssBlkInfo2 _blkInfo2 ; struct _ssBlkInfo2 * blkInfo2 = &
_blkInfo2 ; ssSetBlkInfo2Ptr ( rts , blkInfo2 ) ; } { static struct
_ssPortInfo2 _portInfo2 ; struct _ssPortInfo2 * portInfo2 = & _portInfo2 ;
_ssSetBlkInfo2PortInfo2Ptr ( rts , portInfo2 ) ; } ssSetMdlInfoPtr ( rts ,
ssGetMdlInfoPtr ( rtS ) ) ; { static struct _ssSFcnModelMethods2 methods2 ;
ssSetModelMethods2 ( rts , & methods2 ) ; } { static struct
_ssSFcnModelMethods3 methods3 ; ssSetModelMethods3 ( rts , & methods3 ) ; } {
static struct _ssSFcnModelMethods4 methods4 ; ssSetModelMethods4 ( rts , &
methods4 ) ; } { static struct _ssStatesInfo2 statesInfo2 ; static
ssPeriodicStatesInfo periodicStatesInfo ; static ssJacobianPerturbationBounds
jacPerturbationBounds ; ssSetStatesInfo2 ( rts , & statesInfo2 ) ;
ssSetPeriodicStatesInfo ( rts , & periodicStatesInfo ) ;
ssSetJacobianPerturbationBounds ( rts , & jacPerturbationBounds ) ; } {
_ssSetNumInputPorts ( rts , 1 ) ; static struct _ssPortInputs inputPortInfo [
1 ] ; ssSetPortInfoForInputs ( rts , & inputPortInfo [ 0 ] ) ; { static
struct _ssInPortUnit inputPortUnits [ 1 ] ; _ssSetPortInfo2ForInputUnits (
rts , & inputPortUnits [ 0 ] ) ; } ssSetInputPortUnit ( rts , 0 , 0 ) ; {
static struct _ssInPortCoSimAttribute inputPortCoSimAttribute [ 1 ] ;
_ssSetPortInfo2ForInputCoSimAttribute ( rts , & inputPortCoSimAttribute [ 0 ]
) ; } ssSetInputPortIsContinuousQuantity ( rts , 0 , 0 ) ; {
ssSetInputPortRequiredContiguous ( rts , 0 , 1 ) ; ssSetInputPortSignal ( rts
, 0 , & rtB . jbdewy33ag ) ; _ssSetInputPortNumDimensions ( rts , 0 , 1 ) ;
ssSetInputPortWidthAsInt ( rts , 0 , 1 ) ; } } { static struct _ssPortOutputs
outputPortInfo [ 1 ] ; ssSetPortInfoForOutputs ( rts , & outputPortInfo [ 0 ]
) ; _ssSetNumOutputPorts ( rts , 1 ) ; { static struct _ssOutPortUnit
outputPortUnits [ 1 ] ; _ssSetPortInfo2ForOutputUnits ( rts , &
outputPortUnits [ 0 ] ) ; } ssSetOutputPortUnit ( rts , 0 , 0 ) ; { static
struct _ssOutPortCoSimAttribute outputPortCoSimAttribute [ 1 ] ;
_ssSetPortInfo2ForOutputCoSimAttribute ( rts , & outputPortCoSimAttribute [ 0
] ) ; } ssSetOutputPortIsContinuousQuantity ( rts , 0 , 0 ) ; {
_ssSetOutputPortNumDimensions ( rts , 0 , 1 ) ; ssSetOutputPortWidthAsInt (
rts , 0 , 1 ) ; ssSetOutputPortSignal ( rts , 0 , ( ( real_T * ) & rtB .
ov41nszkfe ) ) ; } } ssSetModelName ( rts , "ASCII Decode3" ) ; ssSetPath (
rts , "air_part1_python2/ASCII Decode3" ) ; if ( ssGetRTModel ( rtS ) == (
NULL ) ) { ssSetParentSS ( rts , rtS ) ; ssSetRootSS ( rts , ssGetRootSS (
rtS ) ) ; } else { ssSetRTModel ( rts , ssGetRTModel ( rtS ) ) ;
ssSetParentSS ( rts , ( NULL ) ) ; ssSetRootSS ( rts , rts ) ; } ssSetVersion
( rts , SIMSTRUCT_VERSION_LEVEL2 ) ; { static mxArray * sfcnParams [ 3 ] ;
ssSetSFcnParamsCount ( rts , 3 ) ; ssSetSFcnParamsPtr ( rts , & sfcnParams [
0 ] ) ; ssSetSFcnParam ( rts , 0 , ( mxArray * ) rtP . ASCIIDecode3_P1_Size )
; ssSetSFcnParam ( rts , 1 , ( mxArray * ) rtP . ASCIIDecode3_P2_Size ) ;
ssSetSFcnParam ( rts , 2 , ( mxArray * ) rtP . ASCIIDecode3_P3_Size ) ; }
ssSetIWork ( rts , ( int_T * ) & rtDW . exvrlracxo [ 0 ] ) ; ssSetPWork ( rts
, ( void * * ) & rtDW . bmpybbr13l [ 0 ] ) ; { static struct _ssDWorkRecord
dWorkRecord [ 2 ] ; static struct _ssDWorkAuxRecord dWorkAuxRecord [ 2 ] ;
ssSetSFcnDWork ( rts , dWorkRecord ) ; ssSetSFcnDWorkAux ( rts ,
dWorkAuxRecord ) ; ssSetNumDWorkAsInt ( rts , 2 ) ; ssSetDWorkWidthAsInt (
rts , 0 , 4 ) ; ssSetDWorkDataType ( rts , 0 , SS_INTEGER ) ;
ssSetDWorkComplexSignal ( rts , 0 , 0 ) ; ssSetDWork ( rts , 0 , & rtDW .
exvrlracxo [ 0 ] ) ; ssSetDWorkWidthAsInt ( rts , 1 , 2 ) ;
ssSetDWorkDataType ( rts , 1 , SS_POINTER ) ; ssSetDWorkComplexSignal ( rts ,
1 , 0 ) ; ssSetDWork ( rts , 1 , & rtDW . bmpybbr13l [ 0 ] ) ; }
slasciidecode ( rts ) ; sfcnInitializeSizes ( rts ) ;
sfcnInitializeSampleTimes ( rts ) ; ssSetSampleTime ( rts , 0 , 0.04 ) ;
ssSetOffsetTime ( rts , 0 , 0.0 ) ; sfcnTsMap [ 0 ] = 2 ;
ssSetInputPortWidthAsInt ( rts , 0 , 1 ) ; ssSetInputPortDataType ( rts , 0 ,
SS_UINT8 ) ; ssSetInputPortComplexSignal ( rts , 0 , 0 ) ;
ssSetInputPortFrameData ( rts , 0 , 0 ) ; ssSetInputPortUnit ( rts , 0 , 0 )
; ssSetInputPortIsContinuousQuantity ( rts , 0 , 0 ) ;
ssSetNumNonsampledZCsAsInt ( rts , 0 ) ; _ssSetInputPortConnected ( rts , 0 ,
1 ) ; _ssSetOutputPortConnected ( rts , 0 , 1 ) ; _ssSetOutputPortBeingMerged
( rts , 0 , 0 ) ; ssSetInputPortBufferDstPort ( rts , 0 , - 1 ) ; } {
SimStruct * rts = ssGetSFunction ( rtS , 6 ) ; static time_T sfcnPeriod [ 1 ]
; static time_T sfcnOffset [ 1 ] ; static int_T sfcnTsMap [ 1 ] ; ( void )
memset ( ( void * ) sfcnPeriod , 0 , sizeof ( time_T ) * 1 ) ; ( void )
memset ( ( void * ) sfcnOffset , 0 , sizeof ( time_T ) * 1 ) ;
ssSetSampleTimePtr ( rts , & sfcnPeriod [ 0 ] ) ; ssSetOffsetTimePtr ( rts ,
& sfcnOffset [ 0 ] ) ; ssSetSampleTimeTaskIDPtr ( rts , sfcnTsMap ) ; {
static struct _ssBlkInfo2 _blkInfo2 ; struct _ssBlkInfo2 * blkInfo2 = &
_blkInfo2 ; ssSetBlkInfo2Ptr ( rts , blkInfo2 ) ; } { static struct
_ssPortInfo2 _portInfo2 ; struct _ssPortInfo2 * portInfo2 = & _portInfo2 ;
_ssSetBlkInfo2PortInfo2Ptr ( rts , portInfo2 ) ; } ssSetMdlInfoPtr ( rts ,
ssGetMdlInfoPtr ( rtS ) ) ; { static struct _ssSFcnModelMethods2 methods2 ;
ssSetModelMethods2 ( rts , & methods2 ) ; } { static struct
_ssSFcnModelMethods3 methods3 ; ssSetModelMethods3 ( rts , & methods3 ) ; } {
static struct _ssSFcnModelMethods4 methods4 ; ssSetModelMethods4 ( rts , &
methods4 ) ; } { static struct _ssStatesInfo2 statesInfo2 ; static
ssPeriodicStatesInfo periodicStatesInfo ; static ssJacobianPerturbationBounds
jacPerturbationBounds ; ssSetStatesInfo2 ( rts , & statesInfo2 ) ;
ssSetPeriodicStatesInfo ( rts , & periodicStatesInfo ) ;
ssSetJacobianPerturbationBounds ( rts , & jacPerturbationBounds ) ; } {
_ssSetNumInputPorts ( rts , 1 ) ; static struct _ssPortInputs inputPortInfo [
1 ] ; ssSetPortInfoForInputs ( rts , & inputPortInfo [ 0 ] ) ; { static
struct _ssInPortUnit inputPortUnits [ 1 ] ; _ssSetPortInfo2ForInputUnits (
rts , & inputPortUnits [ 0 ] ) ; } ssSetInputPortUnit ( rts , 0 , 0 ) ; {
static struct _ssInPortCoSimAttribute inputPortCoSimAttribute [ 1 ] ;
_ssSetPortInfo2ForInputCoSimAttribute ( rts , & inputPortCoSimAttribute [ 0 ]
) ; } ssSetInputPortIsContinuousQuantity ( rts , 0 , 0 ) ; {
ssSetInputPortRequiredContiguous ( rts , 0 , 1 ) ; ssSetInputPortSignal ( rts
, 0 , & rtB . jyujvnq2h1 ) ; _ssSetInputPortNumDimensions ( rts , 0 , 1 ) ;
ssSetInputPortWidthAsInt ( rts , 0 , 1 ) ; } } { static struct _ssPortOutputs
outputPortInfo [ 1 ] ; ssSetPortInfoForOutputs ( rts , & outputPortInfo [ 0 ]
) ; _ssSetNumOutputPorts ( rts , 1 ) ; { static struct _ssOutPortUnit
outputPortUnits [ 1 ] ; _ssSetPortInfo2ForOutputUnits ( rts , &
outputPortUnits [ 0 ] ) ; } ssSetOutputPortUnit ( rts , 0 , 0 ) ; { static
struct _ssOutPortCoSimAttribute outputPortCoSimAttribute [ 1 ] ;
_ssSetPortInfo2ForOutputCoSimAttribute ( rts , & outputPortCoSimAttribute [ 0
] ) ; } ssSetOutputPortIsContinuousQuantity ( rts , 0 , 0 ) ; {
_ssSetOutputPortNumDimensions ( rts , 0 , 1 ) ; ssSetOutputPortWidthAsInt (
rts , 0 , 1 ) ; ssSetOutputPortSignal ( rts , 0 , ( ( real_T * ) & rtB .
ff3s1fh5wh ) ) ; } } ssSetModelName ( rts , "ASCII Decode4" ) ; ssSetPath (
rts , "air_part1_python2/ASCII Decode4" ) ; if ( ssGetRTModel ( rtS ) == (
NULL ) ) { ssSetParentSS ( rts , rtS ) ; ssSetRootSS ( rts , ssGetRootSS (
rtS ) ) ; } else { ssSetRTModel ( rts , ssGetRTModel ( rtS ) ) ;
ssSetParentSS ( rts , ( NULL ) ) ; ssSetRootSS ( rts , rts ) ; } ssSetVersion
( rts , SIMSTRUCT_VERSION_LEVEL2 ) ; { static mxArray * sfcnParams [ 3 ] ;
ssSetSFcnParamsCount ( rts , 3 ) ; ssSetSFcnParamsPtr ( rts , & sfcnParams [
0 ] ) ; ssSetSFcnParam ( rts , 0 , ( mxArray * ) rtP . ASCIIDecode4_P1_Size )
; ssSetSFcnParam ( rts , 1 , ( mxArray * ) rtP . ASCIIDecode4_P2_Size ) ;
ssSetSFcnParam ( rts , 2 , ( mxArray * ) rtP . ASCIIDecode4_P3_Size ) ; }
ssSetIWork ( rts , ( int_T * ) & rtDW . p22db1quvf [ 0 ] ) ; ssSetPWork ( rts
, ( void * * ) & rtDW . omnw5jj5ix [ 0 ] ) ; { static struct _ssDWorkRecord
dWorkRecord [ 2 ] ; static struct _ssDWorkAuxRecord dWorkAuxRecord [ 2 ] ;
ssSetSFcnDWork ( rts , dWorkRecord ) ; ssSetSFcnDWorkAux ( rts ,
dWorkAuxRecord ) ; ssSetNumDWorkAsInt ( rts , 2 ) ; ssSetDWorkWidthAsInt (
rts , 0 , 4 ) ; ssSetDWorkDataType ( rts , 0 , SS_INTEGER ) ;
ssSetDWorkComplexSignal ( rts , 0 , 0 ) ; ssSetDWork ( rts , 0 , & rtDW .
p22db1quvf [ 0 ] ) ; ssSetDWorkWidthAsInt ( rts , 1 , 2 ) ;
ssSetDWorkDataType ( rts , 1 , SS_POINTER ) ; ssSetDWorkComplexSignal ( rts ,
1 , 0 ) ; ssSetDWork ( rts , 1 , & rtDW . omnw5jj5ix [ 0 ] ) ; }
slasciidecode ( rts ) ; sfcnInitializeSizes ( rts ) ;
sfcnInitializeSampleTimes ( rts ) ; ssSetSampleTime ( rts , 0 , 0.04 ) ;
ssSetOffsetTime ( rts , 0 , 0.0 ) ; sfcnTsMap [ 0 ] = 2 ;
ssSetInputPortWidthAsInt ( rts , 0 , 1 ) ; ssSetInputPortDataType ( rts , 0 ,
SS_UINT8 ) ; ssSetInputPortComplexSignal ( rts , 0 , 0 ) ;
ssSetInputPortFrameData ( rts , 0 , 0 ) ; ssSetInputPortUnit ( rts , 0 , 0 )
; ssSetInputPortIsContinuousQuantity ( rts , 0 , 0 ) ;
ssSetNumNonsampledZCsAsInt ( rts , 0 ) ; _ssSetInputPortConnected ( rts , 0 ,
1 ) ; _ssSetOutputPortConnected ( rts , 0 , 1 ) ; _ssSetOutputPortBeingMerged
( rts , 0 , 0 ) ; ssSetInputPortBufferDstPort ( rts , 0 , - 1 ) ; } {
SimStruct * rts = ssGetSFunction ( rtS , 7 ) ; static time_T sfcnPeriod [ 1 ]
; static time_T sfcnOffset [ 1 ] ; static int_T sfcnTsMap [ 1 ] ; ( void )
memset ( ( void * ) sfcnPeriod , 0 , sizeof ( time_T ) * 1 ) ; ( void )
memset ( ( void * ) sfcnOffset , 0 , sizeof ( time_T ) * 1 ) ;
ssSetSampleTimePtr ( rts , & sfcnPeriod [ 0 ] ) ; ssSetOffsetTimePtr ( rts ,
& sfcnOffset [ 0 ] ) ; ssSetSampleTimeTaskIDPtr ( rts , sfcnTsMap ) ; {
static struct _ssBlkInfo2 _blkInfo2 ; struct _ssBlkInfo2 * blkInfo2 = &
_blkInfo2 ; ssSetBlkInfo2Ptr ( rts , blkInfo2 ) ; } { static struct
_ssPortInfo2 _portInfo2 ; struct _ssPortInfo2 * portInfo2 = & _portInfo2 ;
_ssSetBlkInfo2PortInfo2Ptr ( rts , portInfo2 ) ; } ssSetMdlInfoPtr ( rts ,
ssGetMdlInfoPtr ( rtS ) ) ; { static struct _ssSFcnModelMethods2 methods2 ;
ssSetModelMethods2 ( rts , & methods2 ) ; } { static struct
_ssSFcnModelMethods3 methods3 ; ssSetModelMethods3 ( rts , & methods3 ) ; } {
static struct _ssSFcnModelMethods4 methods4 ; ssSetModelMethods4 ( rts , &
methods4 ) ; } { static struct _ssStatesInfo2 statesInfo2 ; static
ssPeriodicStatesInfo periodicStatesInfo ; static ssJacobianPerturbationBounds
jacPerturbationBounds ; ssSetStatesInfo2 ( rts , & statesInfo2 ) ;
ssSetPeriodicStatesInfo ( rts , & periodicStatesInfo ) ;
ssSetJacobianPerturbationBounds ( rts , & jacPerturbationBounds ) ; } {
_ssSetNumInputPorts ( rts , 1 ) ; static struct _ssPortInputs inputPortInfo [
1 ] ; ssSetPortInfoForInputs ( rts , & inputPortInfo [ 0 ] ) ; { static
struct _ssInPortUnit inputPortUnits [ 1 ] ; _ssSetPortInfo2ForInputUnits (
rts , & inputPortUnits [ 0 ] ) ; } ssSetInputPortUnit ( rts , 0 , 0 ) ; {
static struct _ssInPortCoSimAttribute inputPortCoSimAttribute [ 1 ] ;
_ssSetPortInfo2ForInputCoSimAttribute ( rts , & inputPortCoSimAttribute [ 0 ]
) ; } ssSetInputPortIsContinuousQuantity ( rts , 0 , 0 ) ; {
ssSetInputPortRequiredContiguous ( rts , 0 , 1 ) ; ssSetInputPortSignal ( rts
, 0 , & rtB . kmzeugzpgl ) ; _ssSetInputPortNumDimensions ( rts , 0 , 1 ) ;
ssSetInputPortWidthAsInt ( rts , 0 , 1 ) ; } } { static struct _ssPortOutputs
outputPortInfo [ 1 ] ; ssSetPortInfoForOutputs ( rts , & outputPortInfo [ 0 ]
) ; _ssSetNumOutputPorts ( rts , 1 ) ; { static struct _ssOutPortUnit
outputPortUnits [ 1 ] ; _ssSetPortInfo2ForOutputUnits ( rts , &
outputPortUnits [ 0 ] ) ; } ssSetOutputPortUnit ( rts , 0 , 0 ) ; { static
struct _ssOutPortCoSimAttribute outputPortCoSimAttribute [ 1 ] ;
_ssSetPortInfo2ForOutputCoSimAttribute ( rts , & outputPortCoSimAttribute [ 0
] ) ; } ssSetOutputPortIsContinuousQuantity ( rts , 0 , 0 ) ; {
_ssSetOutputPortNumDimensions ( rts , 0 , 1 ) ; ssSetOutputPortWidthAsInt (
rts , 0 , 1 ) ; ssSetOutputPortSignal ( rts , 0 , ( ( real_T * ) & rtB .
crmbrbsz2x ) ) ; } } ssSetModelName ( rts , "ASCII Decode5" ) ; ssSetPath (
rts , "air_part1_python2/ASCII Decode5" ) ; if ( ssGetRTModel ( rtS ) == (
NULL ) ) { ssSetParentSS ( rts , rtS ) ; ssSetRootSS ( rts , ssGetRootSS (
rtS ) ) ; } else { ssSetRTModel ( rts , ssGetRTModel ( rtS ) ) ;
ssSetParentSS ( rts , ( NULL ) ) ; ssSetRootSS ( rts , rts ) ; } ssSetVersion
( rts , SIMSTRUCT_VERSION_LEVEL2 ) ; { static mxArray * sfcnParams [ 3 ] ;
ssSetSFcnParamsCount ( rts , 3 ) ; ssSetSFcnParamsPtr ( rts , & sfcnParams [
0 ] ) ; ssSetSFcnParam ( rts , 0 , ( mxArray * ) rtP . ASCIIDecode5_P1_Size )
; ssSetSFcnParam ( rts , 1 , ( mxArray * ) rtP . ASCIIDecode5_P2_Size ) ;
ssSetSFcnParam ( rts , 2 , ( mxArray * ) rtP . ASCIIDecode5_P3_Size ) ; }
ssSetIWork ( rts , ( int_T * ) & rtDW . euinuevdxm [ 0 ] ) ; ssSetPWork ( rts
, ( void * * ) & rtDW . lt2xcx2ium [ 0 ] ) ; { static struct _ssDWorkRecord
dWorkRecord [ 2 ] ; static struct _ssDWorkAuxRecord dWorkAuxRecord [ 2 ] ;
ssSetSFcnDWork ( rts , dWorkRecord ) ; ssSetSFcnDWorkAux ( rts ,
dWorkAuxRecord ) ; ssSetNumDWorkAsInt ( rts , 2 ) ; ssSetDWorkWidthAsInt (
rts , 0 , 4 ) ; ssSetDWorkDataType ( rts , 0 , SS_INTEGER ) ;
ssSetDWorkComplexSignal ( rts , 0 , 0 ) ; ssSetDWork ( rts , 0 , & rtDW .
euinuevdxm [ 0 ] ) ; ssSetDWorkWidthAsInt ( rts , 1 , 2 ) ;
ssSetDWorkDataType ( rts , 1 , SS_POINTER ) ; ssSetDWorkComplexSignal ( rts ,
1 , 0 ) ; ssSetDWork ( rts , 1 , & rtDW . lt2xcx2ium [ 0 ] ) ; }
slasciidecode ( rts ) ; sfcnInitializeSizes ( rts ) ;
sfcnInitializeSampleTimes ( rts ) ; ssSetSampleTime ( rts , 0 , 0.04 ) ;
ssSetOffsetTime ( rts , 0 , 0.0 ) ; sfcnTsMap [ 0 ] = 2 ;
ssSetInputPortWidthAsInt ( rts , 0 , 1 ) ; ssSetInputPortDataType ( rts , 0 ,
SS_UINT8 ) ; ssSetInputPortComplexSignal ( rts , 0 , 0 ) ;
ssSetInputPortFrameData ( rts , 0 , 0 ) ; ssSetInputPortUnit ( rts , 0 , 0 )
; ssSetInputPortIsContinuousQuantity ( rts , 0 , 0 ) ;
ssSetNumNonsampledZCsAsInt ( rts , 0 ) ; _ssSetInputPortConnected ( rts , 0 ,
1 ) ; _ssSetOutputPortConnected ( rts , 0 , 1 ) ; _ssSetOutputPortBeingMerged
( rts , 0 , 0 ) ; ssSetInputPortBufferDstPort ( rts , 0 , - 1 ) ; } } return
rtS ; }
#if defined(_MSC_VER)
#pragma optimize( "", on )
#endif
const int_T gblParameterTuningTid = 6 ; void MdlOutputsParameterSampleTime (
int_T tid ) { MdlOutputsTID6 ( tid ) ; }
