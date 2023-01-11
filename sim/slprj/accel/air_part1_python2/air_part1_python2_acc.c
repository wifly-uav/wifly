#include "air_part1_python2_acc.h"
#include "rtwtypes.h"
#include "mwmathutil.h"
#include "air_part1_python2_acc_private.h"
#include "multiword_types.h"
#include <stdio.h>
#include "slexec_vm_simstruct_bridge.h"
#include "slexec_vm_zc_functions.h"
#include "slexec_vm_lookup_functions.h"
#include "slsv_diagnostic_codegen_c_api.h"
#include "simtarget/slSimTgtMdlrefSfcnBridge.h"
#include "simstruc.h"
#include "fixedpoint.h"
#define CodeFormat S-Function
#define AccDefine1 Accelerator_S-Function
#include "simtarget/slAccSfcnBridge.h"
#ifndef __RTW_UTFREE__  
extern void * utMalloc ( size_t ) ; extern void utFree ( void * ) ;
#endif
boolean_T air_part1_python2_acc_rt_TDelayUpdateTailOrGrowBuf ( int_T *
bufSzPtr , int_T * tailPtr , int_T * headPtr , int_T * lastPtr , real_T
tMinusDelay , real_T * * uBufPtr , boolean_T isfixedbuf , boolean_T
istransportdelay , int_T * maxNewBufSzPtr ) { int_T testIdx ; int_T tail = *
tailPtr ; int_T bufSz = * bufSzPtr ; real_T * tBuf = * uBufPtr + bufSz ;
real_T * xBuf = ( NULL ) ; int_T numBuffer = 2 ; if ( istransportdelay ) {
numBuffer = 3 ; xBuf = * uBufPtr + 2 * bufSz ; } testIdx = ( tail < ( bufSz -
1 ) ) ? ( tail + 1 ) : 0 ; if ( ( tMinusDelay <= tBuf [ testIdx ] ) && !
isfixedbuf ) { int_T j ; real_T * tempT ; real_T * tempU ; real_T * tempX = (
NULL ) ; real_T * uBuf = * uBufPtr ; int_T newBufSz = bufSz + 1024 ; if (
newBufSz > * maxNewBufSzPtr ) { * maxNewBufSzPtr = newBufSz ; } tempU = (
real_T * ) utMalloc ( numBuffer * newBufSz * sizeof ( real_T ) ) ; if ( tempU
== ( NULL ) ) { return ( false ) ; } tempT = tempU + newBufSz ; if (
istransportdelay ) tempX = tempT + newBufSz ; for ( j = tail ; j < bufSz ; j
++ ) { tempT [ j - tail ] = tBuf [ j ] ; tempU [ j - tail ] = uBuf [ j ] ; if
( istransportdelay ) tempX [ j - tail ] = xBuf [ j ] ; } for ( j = 0 ; j <
tail ; j ++ ) { tempT [ j + bufSz - tail ] = tBuf [ j ] ; tempU [ j + bufSz -
tail ] = uBuf [ j ] ; if ( istransportdelay ) tempX [ j + bufSz - tail ] =
xBuf [ j ] ; } if ( * lastPtr > tail ) { * lastPtr -= tail ; } else { *
lastPtr += ( bufSz - tail ) ; } * tailPtr = 0 ; * headPtr = bufSz ; utFree (
uBuf ) ; * bufSzPtr = newBufSz ; * uBufPtr = tempU ; } else { * tailPtr =
testIdx ; } return ( true ) ; } real_T
air_part1_python2_acc_rt_TDelayInterpolate ( real_T tMinusDelay , real_T
tStart , real_T * uBuf , int_T bufSz , int_T * lastIdx , int_T oldestIdx ,
int_T newIdx , real_T initOutput , boolean_T discrete , boolean_T
minorStepAndTAtLastMajorOutput ) { int_T i ; real_T yout , t1 , t2 , u1 , u2
; real_T * tBuf = uBuf + bufSz ; if ( ( newIdx == 0 ) && ( oldestIdx == 0 )
&& ( tMinusDelay > tStart ) ) return initOutput ; if ( tMinusDelay <= tStart
) return initOutput ; if ( ( tMinusDelay <= tBuf [ oldestIdx ] ) ) { if (
discrete ) { return ( uBuf [ oldestIdx ] ) ; } else { int_T tempIdx =
oldestIdx + 1 ; if ( oldestIdx == bufSz - 1 ) tempIdx = 0 ; t1 = tBuf [
oldestIdx ] ; t2 = tBuf [ tempIdx ] ; u1 = uBuf [ oldestIdx ] ; u2 = uBuf [
tempIdx ] ; if ( t2 == t1 ) { if ( tMinusDelay >= t2 ) { yout = u2 ; } else {
yout = u1 ; } } else { real_T f1 = ( t2 - tMinusDelay ) / ( t2 - t1 ) ;
real_T f2 = 1.0 - f1 ; yout = f1 * u1 + f2 * u2 ; } return yout ; } } if (
minorStepAndTAtLastMajorOutput ) { if ( newIdx != 0 ) { if ( * lastIdx ==
newIdx ) { ( * lastIdx ) -- ; } newIdx -- ; } else { if ( * lastIdx == newIdx
) { * lastIdx = bufSz - 1 ; } newIdx = bufSz - 1 ; } } i = * lastIdx ; if (
tBuf [ i ] < tMinusDelay ) { while ( tBuf [ i ] < tMinusDelay ) { if ( i ==
newIdx ) break ; i = ( i < ( bufSz - 1 ) ) ? ( i + 1 ) : 0 ; } } else { while
( tBuf [ i ] >= tMinusDelay ) { i = ( i > 0 ) ? i - 1 : ( bufSz - 1 ) ; } i =
( i < ( bufSz - 1 ) ) ? ( i + 1 ) : 0 ; } * lastIdx = i ; if ( discrete ) {
double tempEps = ( DBL_EPSILON ) * 128.0 ; double localEps = tempEps *
muDoubleScalarAbs ( tBuf [ i ] ) ; if ( tempEps > localEps ) { localEps =
tempEps ; } localEps = localEps / 2.0 ; if ( tMinusDelay >= ( tBuf [ i ] -
localEps ) ) { yout = uBuf [ i ] ; } else { if ( i == 0 ) { yout = uBuf [
bufSz - 1 ] ; } else { yout = uBuf [ i - 1 ] ; } } } else { if ( i == 0 ) {
t1 = tBuf [ bufSz - 1 ] ; u1 = uBuf [ bufSz - 1 ] ; } else { t1 = tBuf [ i -
1 ] ; u1 = uBuf [ i - 1 ] ; } t2 = tBuf [ i ] ; u2 = uBuf [ i ] ; if ( t2 ==
t1 ) { if ( tMinusDelay >= t2 ) { yout = u2 ; } else { yout = u1 ; } } else {
real_T f1 = ( t2 - tMinusDelay ) / ( t2 - t1 ) ; real_T f2 = 1.0 - f1 ; yout
= f1 * u1 + f2 * u2 ; } } return ( yout ) ; } void rt_ssGetBlockPath (
SimStruct * S , int_T sysIdx , int_T blkIdx , char_T * * path ) {
_ssGetBlockPath ( S , sysIdx , blkIdx , path ) ; } void rt_ssSet_slErrMsg (
void * S , void * diag ) { SimStruct * castedS = ( SimStruct * ) S ; if ( !
_ssIsErrorStatusAslErrMsg ( castedS ) ) { _ssSet_slErrMsg ( castedS , diag )
; } else { _ssDiscardDiagnostic ( castedS , diag ) ; } } void
rt_ssReportDiagnosticAsWarning ( void * S , void * diag ) {
_ssReportDiagnosticAsWarning ( ( SimStruct * ) S , diag ) ; } void
rt_ssReportDiagnosticAsInfo ( void * S , void * diag ) {
_ssReportDiagnosticAsInfo ( ( SimStruct * ) S , diag ) ; } real_T
rt_urand_Upu32_Yd_f_pw_snf ( uint32_T * u ) { uint32_T hi ; uint32_T lo ; lo
= * u % 127773U * 16807U ; hi = * u / 127773U * 2836U ; if ( lo < hi ) { * u
= 2147483647U - ( hi - lo ) ; } else { * u = lo - hi ; } return ( real_T ) *
u * 4.6566128752457969E-10 ; } real_T rt_nrand_Upu32_Yd_f_pw_snf ( uint32_T *
u ) { real_T si ; real_T sr ; real_T y ; do { sr = 2.0 *
rt_urand_Upu32_Yd_f_pw_snf ( u ) - 1.0 ; si = 2.0 *
rt_urand_Upu32_Yd_f_pw_snf ( u ) - 1.0 ; si = sr * sr + si * si ; } while (
si > 1.0 ) ; y = muDoubleScalarSqrt ( - 2.0 * muDoubleScalarLog ( si ) / si )
* sr ; return y ; } static void mdlOutputs ( SimStruct * S , int_T tid ) {
uint32_T B_26_1_0 ; uint32_T B_26_170_0 ; B_air_part1_python2_T * _rtB ;
DW_air_part1_python2_T * _rtDW ; P_air_part1_python2_T * _rtP ;
X_air_part1_python2_T * _rtX ; real_T lastTime ; real_T rtb_B_26_0_0 ; real_T
rtb_B_26_111_0 ; real_T rtb_B_26_124_0 ; real_T rtb_B_26_142_0 ; real_T
rtb_B_26_144_0 ; real_T rtb_B_26_148_0 ; real_T rtb_B_26_152_0 ; real_T
rtb_B_26_154_0 ; real_T rtb_B_26_156_0 ; real_T rtb_B_26_158_0 ; real_T
rtb_B_26_160_0 ; real_T rtb_B_26_162_0 ; real_T rtb_B_26_164_0 ; real_T
rtb_B_26_167_0 ; real_T rtb_B_26_203_0 ; real_T rtb_B_26_206_0 ; real_T
rtb_B_26_216_0 ; real_T rtb_B_26_22_0 ; real_T rtb_B_26_24_0 ; real_T
rtb_B_26_2_0 ; real_T rtb_B_26_30_0 ; real_T rtb_B_26_42_0 ; real_T
rtb_B_26_51_0 ; real_T rtb_B_26_58_0 ; real_T rtb_B_26_64_0 ; real_T
rtb_B_26_69_0 ; real_T rtb_B_26_90_0 ; real_T tmp ; real_T * lastU ; int32_T
isHit ; _rtDW = ( ( DW_air_part1_python2_T * ) ssGetRootDWork ( S ) ) ; _rtX
= ( ( X_air_part1_python2_T * ) ssGetContStates ( S ) ) ; _rtP = ( (
P_air_part1_python2_T * ) ssGetModelRtp ( S ) ) ; _rtB = ( (
B_air_part1_python2_T * ) _ssGetModelBlockIO ( S ) ) ; rtb_B_26_0_0 = _rtX ->
Integrator1_CSTATE ; isHit = ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 )
{ B_26_1_0 = _rtDW -> Output_DSTATE ; rtb_B_26_2_0 = ( real_T ) B_26_1_0 *
_rtB -> B_26_20_0_f ; _rtB -> B_26_4_0 = _rtB -> B_26_10_0 - rtb_B_26_2_0 *
_rtB -> B_26_22_0 ; } _rtB -> B_26_6_0 = _rtX -> Integrator1_CSTATE * _rtB ->
B_26_4_0 * _rtP -> P_1 ; isHit = ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit !=
0 ) { ssCallAccelRunBlock ( S , 26 , 7 , SS_CALL_MDL_OUTPUTS ) ; } _rtB ->
B_26_8_0 = _rtX -> Integrator_CSTATE ; isHit = ssIsSampleHit ( S , 1 , 0 ) ;
if ( isHit != 0 ) { ssCallAccelRunBlock ( S , 26 , 9 , SS_CALL_MDL_OUTPUTS )
; } _rtB -> B_26_11_0 = muDoubleScalarRem ( _rtX -> Integrator1_CSTATE_p ,
_rtB -> B_26_16_0 ) ; ssCallAccelRunBlock ( S , 4 , 0 , SS_CALL_MDL_OUTPUTS )
; _rtB -> B_26_14_0 = _rtB -> B_26_33_0 - _rtP -> P_4 * _rtB -> B_4_0_1 ;
_rtB -> B_26_15_0 = _rtB -> B_26_14_0 - _rtB -> B_26_49_0 ;
ssCallAccelRunBlock ( S , 17 , 0 , SS_CALL_MDL_OUTPUTS ) ; if ( ( _rtDW ->
TimeStampA >= ssGetT ( S ) ) && ( _rtDW -> TimeStampB >= ssGetT ( S ) ) ) {
_rtB -> B_26_17_0 = 0.0 ; } else { lastTime = _rtDW -> TimeStampA ; lastU = &
_rtDW -> LastUAtTimeA ; if ( _rtDW -> TimeStampA < _rtDW -> TimeStampB ) { if
( _rtDW -> TimeStampB < ssGetT ( S ) ) { lastTime = _rtDW -> TimeStampB ;
lastU = & _rtDW -> LastUAtTimeB ; } } else if ( _rtDW -> TimeStampA >= ssGetT
( S ) ) { lastTime = _rtDW -> TimeStampB ; lastU = & _rtDW -> LastUAtTimeB ;
} _rtB -> B_26_17_0 = ( _rtB -> B_17_0_1 - * lastU ) / ( ssGetT ( S ) -
lastTime ) ; } ssCallAccelRunBlock ( S , 18 , 0 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 19 , 0 , SS_CALL_MDL_OUTPUTS ) ; _rtB -> B_26_20_0
= _rtB -> B_26_50_0 - _rtB -> B_19_0_1 ; ssCallAccelRunBlock ( S , 20 , 0 ,
SS_CALL_MDL_OUTPUTS ) ; if ( ( _rtDW -> TimeStampA_d >= ssGetT ( S ) ) && (
_rtDW -> TimeStampB_i >= ssGetT ( S ) ) ) { rtb_B_26_22_0 = 0.0 ; } else {
lastTime = _rtDW -> TimeStampA_d ; lastU = & _rtDW -> LastUAtTimeA_o ; if (
_rtDW -> TimeStampA_d < _rtDW -> TimeStampB_i ) { if ( _rtDW -> TimeStampB_i
< ssGetT ( S ) ) { lastTime = _rtDW -> TimeStampB_i ; lastU = & _rtDW ->
LastUAtTimeB_i ; } } else if ( _rtDW -> TimeStampA_d >= ssGetT ( S ) ) {
lastTime = _rtDW -> TimeStampB_i ; lastU = & _rtDW -> LastUAtTimeB_i ; }
rtb_B_26_22_0 = ( _rtB -> B_19_0_1 - * lastU ) / ( ssGetT ( S ) - lastTime )
; } _rtB -> B_26_23_0 = muDoubleScalarAbs ( rtb_B_26_22_0 ) ; if ( ( _rtDW ->
TimeStampA_j >= ssGetT ( S ) ) && ( _rtDW -> TimeStampB_n >= ssGetT ( S ) ) )
{ rtb_B_26_24_0 = 0.0 ; } else { lastTime = _rtDW -> TimeStampA_j ; lastU = &
_rtDW -> LastUAtTimeA_p ; if ( _rtDW -> TimeStampA_j < _rtDW -> TimeStampB_n
) { if ( _rtDW -> TimeStampB_n < ssGetT ( S ) ) { lastTime = _rtDW ->
TimeStampB_n ; lastU = & _rtDW -> LastUAtTimeB_n ; } } else if ( _rtDW ->
TimeStampA_j >= ssGetT ( S ) ) { lastTime = _rtDW -> TimeStampB_n ; lastU = &
_rtDW -> LastUAtTimeB_n ; } rtb_B_26_24_0 = ( _rtB -> B_26_14_0 - * lastU ) /
( ssGetT ( S ) - lastTime ) ; } _rtB -> B_26_25_0 = muDoubleScalarAbs (
rtb_B_26_24_0 ) ; ssCallAccelRunBlock ( S , 16 , 0 , SS_CALL_MDL_OUTPUTS ) ;
rtb_B_26_30_0 = muDoubleScalarCos ( _rtP -> P_5 * _rtB -> B_26_14_0 ) * _rtB
-> B_16_0_3 * _rtB -> B_16_0_2 ; _rtB -> B_26_31_0 = _rtB -> B_26_17_0_c -
_rtB -> B_26_11_0 ; ssCallAccelRunBlock ( S , 5 , 0 , SS_CALL_MDL_OUTPUTS ) ;
_rtB -> B_26_34_0 = _rtP -> P_6 * _rtB -> B_5_0_1 - _rtB -> B_26_35_0_n ;
_rtB -> B_26_35_0 = _rtB -> B_26_34_0 - _rtB -> B_26_55_0 ;
ssCallAccelRunBlock ( S , 22 , 0 , SS_CALL_MDL_OUTPUTS ) ; if ( ( _rtDW ->
TimeStampA_p >= ssGetT ( S ) ) && ( _rtDW -> TimeStampB_p >= ssGetT ( S ) ) )
{ _rtB -> B_26_37_0 = 0.0 ; } else { lastTime = _rtDW -> TimeStampA_p ; lastU
= & _rtDW -> LastUAtTimeA_j ; if ( _rtDW -> TimeStampA_p < _rtDW ->
TimeStampB_p ) { if ( _rtDW -> TimeStampB_p < ssGetT ( S ) ) { lastTime =
_rtDW -> TimeStampB_p ; lastU = & _rtDW -> LastUAtTimeB_p ; } } else if (
_rtDW -> TimeStampA_p >= ssGetT ( S ) ) { lastTime = _rtDW -> TimeStampB_p ;
lastU = & _rtDW -> LastUAtTimeB_p ; } _rtB -> B_26_37_0 = ( _rtB -> B_22_0_1
- * lastU ) / ( ssGetT ( S ) - lastTime ) ; } ssCallAccelRunBlock ( S , 23 ,
0 , SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 24 , 0 ,
SS_CALL_MDL_OUTPUTS ) ; _rtB -> B_26_40_0 = _rtB -> B_26_56_0 - _rtB ->
B_24_0_1 ; ssCallAccelRunBlock ( S , 25 , 0 , SS_CALL_MDL_OUTPUTS ) ; if ( (
_rtDW -> TimeStampA_l >= ssGetT ( S ) ) && ( _rtDW -> TimeStampB_o >= ssGetT
( S ) ) ) { rtb_B_26_42_0 = 0.0 ; } else { lastTime = _rtDW -> TimeStampA_l ;
lastU = & _rtDW -> LastUAtTimeA_e ; if ( _rtDW -> TimeStampA_l < _rtDW ->
TimeStampB_o ) { if ( _rtDW -> TimeStampB_o < ssGetT ( S ) ) { lastTime =
_rtDW -> TimeStampB_o ; lastU = & _rtDW -> LastUAtTimeB_l ; } } else if (
_rtDW -> TimeStampA_l >= ssGetT ( S ) ) { lastTime = _rtDW -> TimeStampB_o ;
lastU = & _rtDW -> LastUAtTimeB_l ; } rtb_B_26_42_0 = ( _rtB -> B_24_0_1 - *
lastU ) / ( ssGetT ( S ) - lastTime ) ; } if ( rtb_B_26_42_0 > _rtP -> P_7 )
{ lastTime = _rtP -> P_7 ; } else if ( rtb_B_26_42_0 < _rtP -> P_8 ) {
lastTime = _rtP -> P_8 ; } else { lastTime = rtb_B_26_42_0 ; } _rtB ->
B_26_44_0 = muDoubleScalarAbs ( lastTime ) ; if ( ( _rtDW -> TimeStampA_dv >=
ssGetT ( S ) ) && ( _rtDW -> TimeStampB_d >= ssGetT ( S ) ) ) { _rtB ->
B_26_45_0 = 0.0 ; } else { lastTime = _rtDW -> TimeStampA_dv ; lastU = &
_rtDW -> LastUAtTimeA_m ; if ( _rtDW -> TimeStampA_dv < _rtDW -> TimeStampB_d
) { if ( _rtDW -> TimeStampB_d < ssGetT ( S ) ) { lastTime = _rtDW ->
TimeStampB_d ; lastU = & _rtDW -> LastUAtTimeB_nt ; } } else if ( _rtDW ->
TimeStampA_dv >= ssGetT ( S ) ) { lastTime = _rtDW -> TimeStampB_d ; lastU =
& _rtDW -> LastUAtTimeB_nt ; } _rtB -> B_26_45_0 = ( _rtB -> B_26_34_0 - *
lastU ) / ( ssGetT ( S ) - lastTime ) ; } _rtB -> B_26_46_0 =
muDoubleScalarAbs ( _rtB -> B_26_45_0 ) ; ssCallAccelRunBlock ( S , 21 , 0 ,
SS_CALL_MDL_OUTPUTS ) ; rtb_B_26_51_0 = muDoubleScalarCos ( _rtP -> P_9 *
_rtB -> B_26_34_0 ) * _rtB -> B_21_0_3 * _rtB -> B_21_0_2 ; _rtB -> B_26_52_0
= rtb_B_26_30_0 + rtb_B_26_51_0 ; if ( rtb_B_26_24_0 > _rtP -> P_10 ) {
lastTime = _rtB -> B_26_5_0 ; } else { lastTime = _rtB -> B_26_6_0_c ; }
rtb_B_26_58_0 = muDoubleScalarAbs ( muDoubleScalarCos ( _rtB -> B_4_0_4 ) *
muDoubleScalarSin ( _rtB -> B_4_0_2 ) * _rtB -> B_16_0_1 ) * lastTime * _rtB
-> B_26_19_0 ; if ( _rtB -> B_26_45_0 > _rtP -> P_11 ) { lastTime = _rtB ->
B_26_5_0 ; } else { lastTime = _rtB -> B_26_6_0_c ; } rtb_B_26_64_0 =
muDoubleScalarAbs ( muDoubleScalarCos ( _rtB -> B_5_0_4 ) * muDoubleScalarSin
( _rtB -> B_5_0_2 ) * _rtB -> B_21_0_1 ) * lastTime * _rtB -> B_26_19_0 ;
_rtB -> B_26_65_0 = rtb_B_26_58_0 + rtb_B_26_64_0 ; _rtB -> B_26_66_0 = ( (
rtb_B_26_30_0 + rtb_B_26_51_0 ) + rtb_B_26_58_0 ) + rtb_B_26_64_0 ; isHit =
ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) { ssCallAccelRunBlock ( S ,
26 , 67 , SS_CALL_MDL_OUTPUTS ) ; } _rtB -> B_26_68_0 = _rtX ->
Integrator3_CSTATE ; rtb_B_26_69_0 = _rtX -> Integrator2_CSTATE ; _rtB ->
B_26_70_0 = _rtP -> P_14 * _rtX -> Integrator2_CSTATE ; isHit = ssIsSampleHit
( S , 1 , 0 ) ; if ( isHit != 0 ) { ssCallAccelRunBlock ( S , 26 , 71 ,
SS_CALL_MDL_OUTPUTS ) ; _rtB -> B_26_73_0 = _rtB -> B_26_63_0 - rtb_B_26_2_0
* _rtB -> B_26_21_0 ; ssCallAccelRunBlock ( S , 26 , 74 , SS_CALL_MDL_OUTPUTS
) ; } _rtB -> B_26_76_0 = muDoubleScalarRem ( _rtX -> Integrator_CSTATE_p ,
_rtB -> B_26_14_0_b ) ; ssCallAccelRunBlock ( S , 2 , 0 , SS_CALL_MDL_OUTPUTS
) ; _rtB -> B_26_79_0 = _rtB -> B_26_29_0 - _rtP -> P_16 * _rtB -> B_2_0_1 ;
_rtB -> B_26_80_0 = _rtB -> B_26_15_0_p - _rtB -> B_26_76_0 ;
ssCallAccelRunBlock ( S , 3 , 0 , SS_CALL_MDL_OUTPUTS ) ; _rtB -> B_26_83_0 =
_rtP -> P_17 * _rtB -> B_3_0_1 - _rtB -> B_26_31_0_m ; isHit = ssIsSampleHit
( S , 1 , 0 ) ; if ( isHit != 0 ) { ssCallAccelRunBlock ( S , 26 , 84 ,
SS_CALL_MDL_OUTPUTS ) ; } isHit = ssIsSampleHit ( S , 3 , 0 ) ; if ( isHit !=
0 ) { _rtB -> B_26_87_0 = _rtP -> P_21 * _rtDW -> NextOutput * _rtP -> P_22 ;
} _rtB -> B_26_88_0 = _rtB -> B_26_66_0 - _rtB -> B_26_87_0 ; isHit =
ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) { ssCallAccelRunBlock ( S ,
26 , 89 , SS_CALL_MDL_OUTPUTS ) ; } rtb_B_26_90_0 = _rtX ->
Integrator1_CSTATE_j ; isHit = ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0
) { _rtB -> B_26_92_0 = _rtB -> B_26_11_0_c - rtb_B_26_2_0 * _rtB ->
B_26_23_0_g ; } _rtB -> B_26_94_0 = _rtX -> Integrator1_CSTATE_j * _rtB ->
B_26_92_0 * _rtP -> P_24 ; isHit = ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit
!= 0 ) { ssCallAccelRunBlock ( S , 26 , 95 , SS_CALL_MDL_OUTPUTS ) ; } _rtB
-> B_26_96_0 = _rtX -> Integrator_CSTATE_h ; isHit = ssIsSampleHit ( S , 1 ,
0 ) ; if ( isHit != 0 ) { ssCallAccelRunBlock ( S , 26 , 97 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 26 , 98 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 26 , 99 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 26 , 100 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 1 , 0 , SS_CALL_MDL_OUTPUTS
) ; { if ( _rtDW -> _asyncqueue_inserted_for_ToWorkspace_PWORK . AQHandles &&
ssGetLogOutput ( S ) ) { sdiWriteSignal ( _rtDW ->
_asyncqueue_inserted_for_ToWorkspace_PWORK . AQHandles , ssGetTaskTime ( S ,
1 ) , ( char * ) & _rtB -> B_26_68_0 + 0 ) ; } } { if ( _rtDW ->
_asyncqueue_inserted_for_ToWorkspace1_PWORK . AQHandles && ssGetLogOutput ( S
) ) { sdiWriteSignal ( _rtDW -> _asyncqueue_inserted_for_ToWorkspace1_PWORK .
AQHandles , ssGetTaskTime ( S , 1 ) , ( char * ) & _rtB -> B_26_94_0 + 0 ) ;
} } } _rtB -> B_26_104_0 = _rtB -> B_26_79_0 - _rtB -> B_26_37_0_p ;
ssCallAccelRunBlock ( S , 7 , 0 , SS_CALL_MDL_OUTPUTS ) ; if ( ( _rtDW ->
TimeStampA_k >= ssGetT ( S ) ) && ( _rtDW -> TimeStampB_if >= ssGetT ( S ) )
) { _rtB -> B_26_106_0 = 0.0 ; } else { lastTime = _rtDW -> TimeStampA_k ;
lastU = & _rtDW -> LastUAtTimeA_pl ; if ( _rtDW -> TimeStampA_k < _rtDW ->
TimeStampB_if ) { if ( _rtDW -> TimeStampB_if < ssGetT ( S ) ) { lastTime =
_rtDW -> TimeStampB_if ; lastU = & _rtDW -> LastUAtTimeB_d ; } } else if (
_rtDW -> TimeStampA_k >= ssGetT ( S ) ) { lastTime = _rtDW -> TimeStampB_if ;
lastU = & _rtDW -> LastUAtTimeB_d ; } _rtB -> B_26_106_0 = ( _rtB -> B_7_0_1
- * lastU ) / ( ssGetT ( S ) - lastTime ) ; } ssCallAccelRunBlock ( S , 8 , 0
, SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 9 , 0 ,
SS_CALL_MDL_OUTPUTS ) ; _rtB -> B_26_109_0 = _rtB -> B_26_38_0 - _rtB ->
B_9_0_1 ; ssCallAccelRunBlock ( S , 10 , 0 , SS_CALL_MDL_OUTPUTS ) ; if ( (
_rtDW -> TimeStampA_n >= ssGetT ( S ) ) && ( _rtDW -> TimeStampB_c >= ssGetT
( S ) ) ) { rtb_B_26_111_0 = 0.0 ; } else { lastTime = _rtDW -> TimeStampA_n
; lastU = & _rtDW -> LastUAtTimeA_i ; if ( _rtDW -> TimeStampA_n < _rtDW ->
TimeStampB_c ) { if ( _rtDW -> TimeStampB_c < ssGetT ( S ) ) { lastTime =
_rtDW -> TimeStampB_c ; lastU = & _rtDW -> LastUAtTimeB_nb ; } } else if (
_rtDW -> TimeStampA_n >= ssGetT ( S ) ) { lastTime = _rtDW -> TimeStampB_c ;
lastU = & _rtDW -> LastUAtTimeB_nb ; } rtb_B_26_111_0 = ( _rtB -> B_9_0_1 - *
lastU ) / ( ssGetT ( S ) - lastTime ) ; } if ( rtb_B_26_111_0 > _rtP -> P_42
) { lastTime = _rtP -> P_42 ; } else if ( rtb_B_26_111_0 < _rtP -> P_43 ) {
lastTime = _rtP -> P_43 ; } else { lastTime = rtb_B_26_111_0 ; } _rtB ->
B_26_113_0 = muDoubleScalarAbs ( lastTime ) ; if ( ( _rtDW -> TimeStampA_f >=
ssGetT ( S ) ) && ( _rtDW -> TimeStampB_a >= ssGetT ( S ) ) ) { _rtB ->
B_26_114_0 = 0.0 ; } else { lastTime = _rtDW -> TimeStampA_f ; lastU = &
_rtDW -> LastUAtTimeA_n ; if ( _rtDW -> TimeStampA_f < _rtDW -> TimeStampB_a
) { if ( _rtDW -> TimeStampB_a < ssGetT ( S ) ) { lastTime = _rtDW ->
TimeStampB_a ; lastU = & _rtDW -> LastUAtTimeB_lc ; } } else if ( _rtDW ->
TimeStampA_f >= ssGetT ( S ) ) { lastTime = _rtDW -> TimeStampB_a ; lastU = &
_rtDW -> LastUAtTimeB_lc ; } _rtB -> B_26_114_0 = ( _rtB -> B_26_79_0 - *
lastU ) / ( ssGetT ( S ) - lastTime ) ; } _rtB -> B_26_115_0 =
muDoubleScalarAbs ( _rtB -> B_26_114_0 ) ; ssCallAccelRunBlock ( S , 6 , 0 ,
SS_CALL_MDL_OUTPUTS ) ; _rtB -> B_26_117_0 = _rtB -> B_26_83_0 - _rtB ->
B_26_43_0 ; ssCallAccelRunBlock ( S , 12 , 0 , SS_CALL_MDL_OUTPUTS ) ; if ( (
_rtDW -> TimeStampA_c >= ssGetT ( S ) ) && ( _rtDW -> TimeStampB_e >= ssGetT
( S ) ) ) { _rtB -> B_26_119_0 = 0.0 ; } else { lastTime = _rtDW ->
TimeStampA_c ; lastU = & _rtDW -> LastUAtTimeA_d ; if ( _rtDW -> TimeStampA_c
< _rtDW -> TimeStampB_e ) { if ( _rtDW -> TimeStampB_e < ssGetT ( S ) ) {
lastTime = _rtDW -> TimeStampB_e ; lastU = & _rtDW -> LastUAtTimeB_j ; } }
else if ( _rtDW -> TimeStampA_c >= ssGetT ( S ) ) { lastTime = _rtDW ->
TimeStampB_e ; lastU = & _rtDW -> LastUAtTimeB_j ; } _rtB -> B_26_119_0 = (
_rtB -> B_12_0_1 - * lastU ) / ( ssGetT ( S ) - lastTime ) ; }
ssCallAccelRunBlock ( S , 13 , 0 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 14 , 0 , SS_CALL_MDL_OUTPUTS ) ; _rtB -> B_26_122_0
= _rtB -> B_26_44_0_j - _rtB -> B_14_0_1 ; ssCallAccelRunBlock ( S , 15 , 0 ,
SS_CALL_MDL_OUTPUTS ) ; if ( ( _rtDW -> TimeStampA_m >= ssGetT ( S ) ) && (
_rtDW -> TimeStampB_nz >= ssGetT ( S ) ) ) { rtb_B_26_124_0 = 0.0 ; } else {
lastTime = _rtDW -> TimeStampA_m ; lastU = & _rtDW -> LastUAtTimeA_di ; if (
_rtDW -> TimeStampA_m < _rtDW -> TimeStampB_nz ) { if ( _rtDW ->
TimeStampB_nz < ssGetT ( S ) ) { lastTime = _rtDW -> TimeStampB_nz ; lastU =
& _rtDW -> LastUAtTimeB_o ; } } else if ( _rtDW -> TimeStampA_m >= ssGetT ( S
) ) { lastTime = _rtDW -> TimeStampB_nz ; lastU = & _rtDW -> LastUAtTimeB_o ;
} rtb_B_26_124_0 = ( _rtB -> B_14_0_1 - * lastU ) / ( ssGetT ( S ) - lastTime
) ; } if ( rtb_B_26_124_0 > _rtP -> P_44 ) { lastTime = _rtP -> P_44 ; } else
if ( rtb_B_26_124_0 < _rtP -> P_45 ) { lastTime = _rtP -> P_45 ; } else {
lastTime = rtb_B_26_124_0 ; } _rtB -> B_26_126_0 = muDoubleScalarAbs (
lastTime ) ; if ( ( _rtDW -> TimeStampA_cb >= ssGetT ( S ) ) && ( _rtDW ->
TimeStampB_j >= ssGetT ( S ) ) ) { _rtB -> B_26_127_0 = 0.0 ; } else {
lastTime = _rtDW -> TimeStampA_cb ; lastU = & _rtDW -> LastUAtTimeA_g ; if (
_rtDW -> TimeStampA_cb < _rtDW -> TimeStampB_j ) { if ( _rtDW -> TimeStampB_j
< ssGetT ( S ) ) { lastTime = _rtDW -> TimeStampB_j ; lastU = & _rtDW ->
LastUAtTimeB_f ; } } else if ( _rtDW -> TimeStampA_cb >= ssGetT ( S ) ) {
lastTime = _rtDW -> TimeStampB_j ; lastU = & _rtDW -> LastUAtTimeB_f ; } _rtB
-> B_26_127_0 = ( _rtB -> B_26_83_0 - * lastU ) / ( ssGetT ( S ) - lastTime )
; } _rtB -> B_26_128_0 = muDoubleScalarAbs ( _rtB -> B_26_127_0 ) ;
ssCallAccelRunBlock ( S , 11 , 0 , SS_CALL_MDL_OUTPUTS ) ; _rtB -> B_26_130_0
= _rtB -> B_6_0_2 + _rtB -> B_11_0_2 ; isHit = ssIsSampleHit ( S , 1 , 0 ) ;
if ( isHit != 0 ) { { if ( _rtDW ->
_asyncqueue_inserted_for_ToWorkspace2_PWORK . AQHandles && ssGetLogOutput ( S
) ) { sdiWriteSignal ( _rtDW -> _asyncqueue_inserted_for_ToWorkspace2_PWORK .
AQHandles , ssGetTaskTime ( S , 1 ) , ( char * ) & _rtB -> B_26_130_0 + 0 ) ;
} } } _rtB -> B_26_132_0 = _rtB -> B_16_0_2 + _rtB -> B_21_0_2 ; isHit =
ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) { { if ( _rtDW ->
_asyncqueue_inserted_for_ToWorkspace3_PWORK . AQHandles && ssGetLogOutput ( S
) ) { sdiWriteSignal ( _rtDW -> _asyncqueue_inserted_for_ToWorkspace3_PWORK .
AQHandles , ssGetTaskTime ( S , 1 ) , ( char * ) & _rtB -> B_26_132_0 + 0 ) ;
} } } isHit = ssIsSampleHit ( S , 2 , 0 ) ; if ( isHit != 0 ) {
ssCallAccelRunBlock ( S , 0 , 0 , SS_CALL_MDL_OUTPUTS ) ; ( void ) memcpy ( &
_rtB -> B_26_135_0 , & _rtB -> B_0_0_0 [ 0 ] , 1 ) ; ( void ) memcpy ( & _rtB
-> B_26_135_1 , & _rtB -> B_0_0_0 [ 1 ] , 1 ) ; ( void ) memcpy ( & _rtB ->
B_26_135_2 , & _rtB -> B_0_0_0 [ 2 ] , 1 ) ; ( void ) memcpy ( & _rtB ->
B_26_135_3 , & _rtB -> B_0_0_0 [ 3 ] , 1 ) ; ( void ) memcpy ( & _rtB ->
B_26_135_4 , & _rtB -> B_0_0_0 [ 4 ] , 1 ) ; ( void ) memcpy ( & _rtB ->
B_26_135_5 , & _rtB -> B_0_0_0 [ 5 ] , 1 ) ; ssCallAccelRunBlock ( S , 26 ,
136 , SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 26 , 137 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 26 , 138 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 26 , 139 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 26 , 140 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 26 , 141 ,
SS_CALL_MDL_OUTPUTS ) ; } rtb_B_26_142_0 = muDoubleScalarCos ( _rtB ->
B_2_0_2 ) ; rtb_B_26_144_0 = muDoubleScalarCos ( _rtB -> B_2_0_3 ) ;
rtb_B_26_148_0 = muDoubleScalarCos ( _rtB -> B_3_0_4 ) * muDoubleScalarSin (
_rtB -> B_3_0_2 ) * _rtB -> B_11_0_1 ; rtb_B_26_152_0 = _rtB -> B_6_0_1 *
muDoubleScalarCos ( _rtB -> B_2_0_4 ) * muDoubleScalarSin ( _rtB -> B_2_0_2 )
; rtb_B_26_154_0 = muDoubleScalarCos ( _rtB -> B_4_0_2 ) ; rtb_B_26_156_0 =
muDoubleScalarCos ( _rtB -> B_4_0_3 ) ; rtb_B_26_158_0 = muDoubleScalarCos (
_rtB -> B_3_0_2 ) ; rtb_B_26_160_0 = muDoubleScalarCos ( _rtB -> B_3_0_3 ) ;
rtb_B_26_162_0 = muDoubleScalarCos ( _rtB -> B_5_0_2 ) ; rtb_B_26_164_0 =
muDoubleScalarCos ( _rtB -> B_5_0_3 ) ; isHit = ssIsSampleHit ( S , 3 , 0 ) ;
if ( isHit != 0 ) { rtb_B_26_167_0 = _rtP -> P_85 * _rtDW -> NextOutput_c ; }
isHit = ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 ) { B_26_170_0 = (
B_26_1_0 + _rtB -> B_26_0_0 ) & 1048575U ; if ( B_26_170_0 > _rtP -> P_171 )
{ _rtB -> B_26_172_0 = _rtB -> B_26_1_0 ; } else { _rtB -> B_26_172_0 =
B_26_170_0 ; } } isHit = ssIsSampleHit ( S , 3 , 0 ) ; if ( isHit != 0 ) {
_rtB -> B_26_173_0 = _rtP -> P_86 * rtb_B_26_167_0 ; } { real_T * * uBuffer =
( real_T * * ) & _rtDW -> VariableTimeDelay1_PWORK . TUbufferPtrs [ 0 ] ;
real_T simTime = ssGetT ( S ) ; real_T appliedDelay ; appliedDelay = _rtB ->
B_26_9_0 ; if ( appliedDelay > _rtP -> P_87 ) { appliedDelay = _rtP -> P_87 ;
} if ( appliedDelay < 0.0 ) { appliedDelay = 0.0 ; } _rtB -> B_26_174_0 =
air_part1_python2_acc_rt_TDelayInterpolate ( simTime - appliedDelay , 0.0 , *
uBuffer , _rtDW -> VariableTimeDelay1_IWORK . CircularBufSize , & _rtDW ->
VariableTimeDelay1_IWORK . Last , _rtDW -> VariableTimeDelay1_IWORK . Tail ,
_rtDW -> VariableTimeDelay1_IWORK . Head , _rtP -> P_88 , 1 , ( boolean_T ) (
ssIsMinorTimeStep ( S ) && ( ( * uBuffer + _rtDW -> VariableTimeDelay1_IWORK
. CircularBufSize ) [ _rtDW -> VariableTimeDelay1_IWORK . Head ] == ssGetT (
S ) ) ) ) ; } isHit = ssIsSampleHit ( S , 5 , 0 ) ; if ( isHit != 0 ) {
lastTime = muDoubleScalarFloor ( ( 2.8421709430404007E-14 * _rtB ->
B_26_174_0 * _rtB -> B_26_2_0 + _rtB -> B_26_174_0 * _rtB -> B_26_2_0 ) /
5.0E-5 ) ; if ( muDoubleScalarIsNaN ( lastTime ) || muDoubleScalarIsInf (
lastTime ) ) { lastTime = 0.0 ; } else { lastTime = muDoubleScalarRem (
lastTime , 4.294967296E+9 ) ; } if ( ( ( ( lastTime < 0.0 ? ( uint32_T ) - (
int32_T ) ( uint32_T ) - lastTime : ( uint32_T ) lastTime ) == 0U ) || ( _rtB
-> B_26_174_0 <= 0.0 ) ) && _rtDW -> isStartOfNextCycle ) { _rtB ->
B_26_175_0 = 0.0 ; _rtDW -> nextOutput = false ; } else { _rtB -> B_26_175_0
= _rtDW -> nextOutput ; } } { real_T * * uBuffer = ( real_T * * ) & _rtDW ->
VariableTimeDelay_PWORK . TUbufferPtrs [ 0 ] ; real_T simTime = ssGetT ( S )
; real_T appliedDelay ; appliedDelay = _rtB -> B_26_9_0 ; if ( appliedDelay >
_rtP -> P_89 ) { appliedDelay = _rtP -> P_89 ; } if ( appliedDelay < 0.0 ) {
appliedDelay = 0.0 ; } _rtB -> B_26_176_0 =
air_part1_python2_acc_rt_TDelayInterpolate ( simTime - appliedDelay , 0.0 , *
uBuffer , _rtDW -> VariableTimeDelay_IWORK . CircularBufSize , & _rtDW ->
VariableTimeDelay_IWORK . Last , _rtDW -> VariableTimeDelay_IWORK . Tail ,
_rtDW -> VariableTimeDelay_IWORK . Head , _rtP -> P_90 , 1 , ( boolean_T ) (
ssIsMinorTimeStep ( S ) && ( ( * uBuffer + _rtDW -> VariableTimeDelay_IWORK .
CircularBufSize ) [ _rtDW -> VariableTimeDelay_IWORK . Head ] == ssGetT ( S )
) ) ) ; } isHit = ssIsSampleHit ( S , 4 , 0 ) ; if ( isHit != 0 ) { lastTime
= muDoubleScalarFloor ( ( 2.8421709430404007E-14 * _rtB -> B_26_176_0 * _rtB
-> B_26_3_0 + _rtB -> B_26_176_0 * _rtB -> B_26_3_0 ) / 5.0E-5 ) ; if (
muDoubleScalarIsNaN ( lastTime ) || muDoubleScalarIsInf ( lastTime ) ) {
lastTime = 0.0 ; } else { lastTime = muDoubleScalarRem ( lastTime ,
4.294967296E+9 ) ; } if ( ( ( ( lastTime < 0.0 ? ( uint32_T ) - ( int32_T ) (
uint32_T ) - lastTime : ( uint32_T ) lastTime ) == 0U ) || ( _rtB ->
B_26_176_0 <= 0.0 ) ) && _rtDW -> isStartOfNextCycle_p ) { _rtB -> B_26_177_0
= 0.0 ; _rtDW -> nextOutput_b = false ; } else { _rtB -> B_26_177_0 = _rtDW
-> nextOutput_b ; } } isHit = ssIsSampleHit ( S , 1 , 0 ) ; if ( isHit != 0 )
{ _rtB -> B_26_178_0 = _rtB -> B_26_73_0 * _rtB -> B_26_175_0 ; _rtB ->
B_26_179_0 = _rtB -> B_26_73_0 * _rtB -> B_26_177_0 ; } if ( _rtB ->
B_26_127_0 > _rtP -> P_91 ) { lastTime = _rtB -> B_26_7_0 ; } else { lastTime
= _rtB -> B_26_8_0_k ; } if ( _rtB -> B_26_114_0 > _rtP -> P_92 ) { tmp =
_rtB -> B_26_7_0 ; } else { tmp = _rtB -> B_26_8_0_k ; } _rtB -> B_26_197_0 =
( ( _rtB -> B_26_88_0 - ( ( ( ( muDoubleScalarCos ( _rtP -> P_94 * _rtB ->
B_26_79_0 ) * _rtB -> B_6_0_3 * _rtB -> B_6_0_2 + muDoubleScalarCos ( _rtP ->
P_93 * _rtB -> B_26_83_0 ) * _rtB -> B_11_0_3 * _rtB -> B_6_0_2 ) +
muDoubleScalarAbs ( rtb_B_26_148_0 ) * lastTime * _rtB -> B_26_19_0 ) +
muDoubleScalarAbs ( rtb_B_26_152_0 ) * tmp * _rtB -> B_26_19_0 ) - _rtB ->
B_26_173_0 ) ) - _rtP -> P_95 * rtb_B_26_69_0 ) * ( 1.0 / _rtB -> B_26_36_0 )
; isHit = ssIsSampleHit ( S , 2 , 0 ) ; if ( isHit != 0 ) { rtb_B_26_203_0 =
( _rtP -> P_96 * _rtB -> B_26_136_0 + _rtP -> P_97 * _rtB -> B_26_137_0 ) +
_rtB -> B_26_138_0 ; rtb_B_26_206_0 = ( _rtP -> P_98 * _rtB -> B_26_139_0 +
_rtP -> P_99 * _rtB -> B_26_140_0 ) + _rtB -> B_26_141_0 ; } _rtB ->
B_26_211_0 = ( _rtB -> B_6_0_1 * muDoubleScalarAbs ( rtb_B_26_142_0 ) *
muDoubleScalarAbs ( rtb_B_26_144_0 ) + muDoubleScalarAbs ( rtb_B_26_158_0 ) *
muDoubleScalarAbs ( rtb_B_26_160_0 ) * _rtB -> B_11_0_1 ) * _rtP -> P_100 *
_rtP -> P_101 * _rtP -> P_102 + _rtB -> B_26_61_0 ; rtb_B_26_216_0 = ( _rtB
-> B_16_0_1 * muDoubleScalarAbs ( rtb_B_26_154_0 ) * muDoubleScalarAbs (
rtb_B_26_156_0 ) + _rtB -> B_21_0_1 * muDoubleScalarAbs ( rtb_B_26_162_0 ) *
muDoubleScalarAbs ( rtb_B_26_164_0 ) ) * _rtP -> P_103 * _rtP -> P_104 * _rtP
-> P_105 + _rtB -> B_26_62_0 ; _rtB -> B_26_217_0 = _rtP -> P_106 * _rtB ->
B_26_94_0 ; _rtB -> B_26_218_0 = _rtP -> P_107 * _rtB -> B_26_6_0 ; _rtB ->
B_26_219_0 = _rtP -> P_108 * rtb_B_26_0_0 ; isHit = ssIsSampleHit ( S , 1 , 0
) ; if ( isHit != 0 ) { ssCallAccelRunBlock ( S , 26 , 220 ,
SS_CALL_MDL_OUTPUTS ) ; } _rtB -> B_26_224_0 = ( ( _rtB -> B_26_178_0 - _rtP
-> P_109 * rtb_B_26_0_0 ) - _rtP -> P_110 * _rtB -> B_26_8_0 ) * ( 1.0 / _rtB
-> B_26_24_0 ) ; _rtB -> B_26_228_0 = ( ( _rtP -> P_111 * _rtB -> B_26_8_0 -
_rtB -> B_26_219_0 ) - _rtB -> B_26_211_0 ) * _rtP -> P_112 * ( 1.0 / _rtB ->
B_26_25_0_g ) ; _rtB -> B_26_232_0 = ( ( _rtB -> B_26_179_0 - _rtP -> P_113 *
rtb_B_26_90_0 ) - _rtP -> P_114 * _rtB -> B_26_96_0 ) * ( 1.0 / _rtB ->
B_26_26_0 ) ; _rtB -> B_26_237_0 = ( ( _rtP -> P_115 * _rtB -> B_26_96_0 -
_rtP -> P_116 * rtb_B_26_90_0 ) - rtb_B_26_216_0 ) * _rtP -> P_117 * ( 1.0 /
_rtB -> B_26_27_0 ) ; isHit = ssIsSampleHit ( S , 2 , 0 ) ; if ( isHit != 0 )
{ _rtB -> B_26_238_0 = _rtP -> P_118 * rtb_B_26_206_0 ; _rtB -> B_26_239_0 =
_rtP -> P_119 * rtb_B_26_203_0 ; } isHit = ssIsSampleHit ( S , 1 , 0 ) ; if (
isHit != 0 ) { ssCallAccelRunBlock ( S , 26 , 240 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 26 , 241 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 26 , 242 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 26 , 243 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 26 , 244 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 26 , 245 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 26 , 246 , SS_CALL_MDL_OUTPUTS ) ;
ssCallAccelRunBlock ( S , 26 , 247 , SS_CALL_MDL_OUTPUTS ) ; { if ( _rtDW ->
_asyncqueue_inserted_for_ToWorkspace1_PWORK_k . AQHandles && ssGetLogOutput (
S ) ) { sdiWriteSignal ( _rtDW ->
_asyncqueue_inserted_for_ToWorkspace1_PWORK_k . AQHandles , ssGetTaskTime ( S
, 1 ) , ( char * ) & _rtB -> B_9_0_1 + 0 ) ; } } { if ( _rtDW ->
_asyncqueue_inserted_for_ToWorkspace2_PWORK_b . AQHandles && ssGetLogOutput (
S ) ) { sdiWriteSignal ( _rtDW ->
_asyncqueue_inserted_for_ToWorkspace2_PWORK_b . AQHandles , ssGetTaskTime ( S
, 1 ) , ( char * ) & _rtB -> B_26_104_0 + 0 ) ; } } ssCallAccelRunBlock ( S ,
26 , 250 , SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 26 , 251 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 26 , 252 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 26 , 253 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 26 , 254 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 26 , 255 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 26 , 256 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 26 , 257 ,
SS_CALL_MDL_OUTPUTS ) ; { if ( _rtDW ->
_asyncqueue_inserted_for_ToWorkspace1_PWORK_k1 . AQHandles && ssGetLogOutput
( S ) ) { sdiWriteSignal ( _rtDW ->
_asyncqueue_inserted_for_ToWorkspace1_PWORK_k1 . AQHandles , ssGetTaskTime (
S , 1 ) , ( char * ) & _rtB -> B_26_117_0 + 0 ) ; } } ssCallAccelRunBlock ( S
, 26 , 259 , SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 26 , 260 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 26 , 261 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 26 , 262 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 26 , 263 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 26 , 264 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 26 , 265 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 26 , 266 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 26 , 267 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 26 , 268 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 26 , 269 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 26 , 270 ,
SS_CALL_MDL_OUTPUTS ) ; ssCallAccelRunBlock ( S , 26 , 271 ,
SS_CALL_MDL_OUTPUTS ) ; } UNUSED_PARAMETER ( tid ) ; } static void
mdlOutputsTID6 ( SimStruct * S , int_T tid ) { B_air_part1_python2_T * _rtB ;
P_air_part1_python2_T * _rtP ; _rtP = ( ( P_air_part1_python2_T * )
ssGetModelRtp ( S ) ) ; _rtB = ( ( B_air_part1_python2_T * )
_ssGetModelBlockIO ( S ) ) ; _rtB -> B_26_0_0 = _rtP -> P_172 ; _rtB ->
B_26_1_0 = _rtP -> P_173 ; _rtB -> B_26_2_0 = _rtP -> P_120 ; _rtB ->
B_26_3_0 = _rtP -> P_121 ; _rtB -> B_26_4_0_m = _rtP -> P_122 ; _rtB ->
B_26_5_0 = _rtP -> P_123 ; _rtB -> B_26_6_0_c = _rtP -> P_124 ; _rtB ->
B_26_7_0 = _rtP -> P_125 ; _rtB -> B_26_8_0_k = _rtP -> P_126 ; _rtB ->
B_26_9_0 = _rtP -> P_127 ; _rtB -> B_26_10_0 = _rtP -> P_128 ; _rtB ->
B_26_11_0_c = _rtP -> P_129 ; _rtB -> B_26_12_0 = _rtP -> P_130 ; _rtB ->
B_26_13_0 = _rtP -> P_131 ; _rtB -> B_26_14_0_b = _rtP -> P_132 ; _rtB ->
B_26_15_0_p = _rtP -> P_133 ; _rtB -> B_26_16_0 = _rtP -> P_134 ; _rtB ->
B_26_17_0_c = _rtP -> P_135 ; _rtB -> B_26_18_0 = _rtP -> P_136 ; _rtB ->
B_26_19_0 = _rtP -> P_137 ; _rtB -> B_26_20_0_f = _rtP -> P_138 ; _rtB ->
B_26_21_0 = _rtP -> P_139 ; _rtB -> B_26_22_0 = _rtP -> P_140 ; _rtB ->
B_26_23_0_g = _rtP -> P_141 ; _rtB -> B_26_24_0 = _rtP -> P_142 ; _rtB ->
B_26_25_0_g = _rtP -> P_143 ; _rtB -> B_26_26_0 = _rtP -> P_144 ; _rtB ->
B_26_27_0 = _rtP -> P_145 ; _rtB -> B_26_29_0 = _rtP -> P_146 ; _rtB ->
B_26_31_0_m = _rtP -> P_147 ; _rtB -> B_26_33_0 = _rtP -> P_148 ; _rtB ->
B_26_35_0_n = _rtP -> P_149 ; _rtB -> B_26_36_0 = _rtP -> P_150 ; _rtB ->
B_26_37_0_p = _rtP -> P_151 ; _rtB -> B_26_38_0 = _rtP -> P_152 ; _rtB ->
B_26_39_0 = _rtP -> P_153 ; _rtB -> B_26_40_0_l = _rtP -> P_154 ; _rtB ->
B_26_43_0 = _rtP -> P_155 ; _rtB -> B_26_44_0_j = _rtP -> P_156 ; _rtB ->
B_26_45_0_d = _rtP -> P_157 ; _rtB -> B_26_46_0_g = _rtP -> P_158 ; _rtB ->
B_26_49_0 = _rtP -> P_159 ; _rtB -> B_26_50_0 = _rtP -> P_160 ; _rtB ->
B_26_51_0 = _rtP -> P_161 ; _rtB -> B_26_52_0_l = _rtP -> P_162 ; _rtB ->
B_26_55_0 = _rtP -> P_163 ; _rtB -> B_26_56_0 = _rtP -> P_164 ; _rtB ->
B_26_57_0 = _rtP -> P_165 ; _rtB -> B_26_58_0 = _rtP -> P_166 ; _rtB ->
B_26_61_0 = _rtP -> P_167 ; _rtB -> B_26_62_0 = _rtP -> P_168 ; _rtB ->
B_26_63_0 = _rtP -> P_169 ; UNUSED_PARAMETER ( tid ) ; }
#define MDL_UPDATE
static void mdlUpdate ( SimStruct * S , int_T tid ) { B_air_part1_python2_T *
_rtB ; DW_air_part1_python2_T * _rtDW ; P_air_part1_python2_T * _rtP ; real_T
arg3 ; real_T dc ; real_T * lastU ; int32_T isHit ; uint32_T
numTicksToNextSampleHit ; uint32_T totalTicksInPeriod ; void * diag ; _rtDW =
( ( DW_air_part1_python2_T * ) ssGetRootDWork ( S ) ) ; _rtP = ( (
P_air_part1_python2_T * ) ssGetModelRtp ( S ) ) ; _rtB = ( (
B_air_part1_python2_T * ) _ssGetModelBlockIO ( S ) ) ; isHit = ssIsSampleHit
( S , 1 , 0 ) ; if ( isHit != 0 ) { _rtDW -> Output_DSTATE = _rtB ->
B_26_172_0 ; } if ( _rtDW -> TimeStampA == ( rtInf ) ) { _rtDW -> TimeStampA
= ssGetT ( S ) ; lastU = & _rtDW -> LastUAtTimeA ; } else if ( _rtDW ->
TimeStampB == ( rtInf ) ) { _rtDW -> TimeStampB = ssGetT ( S ) ; lastU = &
_rtDW -> LastUAtTimeB ; } else if ( _rtDW -> TimeStampA < _rtDW -> TimeStampB
) { _rtDW -> TimeStampA = ssGetT ( S ) ; lastU = & _rtDW -> LastUAtTimeA ; }
else { _rtDW -> TimeStampB = ssGetT ( S ) ; lastU = & _rtDW -> LastUAtTimeB ;
} * lastU = _rtB -> B_17_0_1 ; if ( _rtDW -> TimeStampA_d == ( rtInf ) ) {
_rtDW -> TimeStampA_d = ssGetT ( S ) ; lastU = & _rtDW -> LastUAtTimeA_o ; }
else if ( _rtDW -> TimeStampB_i == ( rtInf ) ) { _rtDW -> TimeStampB_i =
ssGetT ( S ) ; lastU = & _rtDW -> LastUAtTimeB_i ; } else if ( _rtDW ->
TimeStampA_d < _rtDW -> TimeStampB_i ) { _rtDW -> TimeStampA_d = ssGetT ( S )
; lastU = & _rtDW -> LastUAtTimeA_o ; } else { _rtDW -> TimeStampB_i = ssGetT
( S ) ; lastU = & _rtDW -> LastUAtTimeB_i ; } * lastU = _rtB -> B_19_0_1 ; if
( _rtDW -> TimeStampA_j == ( rtInf ) ) { _rtDW -> TimeStampA_j = ssGetT ( S )
; lastU = & _rtDW -> LastUAtTimeA_p ; } else if ( _rtDW -> TimeStampB_n == (
rtInf ) ) { _rtDW -> TimeStampB_n = ssGetT ( S ) ; lastU = & _rtDW ->
LastUAtTimeB_n ; } else if ( _rtDW -> TimeStampA_j < _rtDW -> TimeStampB_n )
{ _rtDW -> TimeStampA_j = ssGetT ( S ) ; lastU = & _rtDW -> LastUAtTimeA_p ;
} else { _rtDW -> TimeStampB_n = ssGetT ( S ) ; lastU = & _rtDW ->
LastUAtTimeB_n ; } * lastU = _rtB -> B_26_14_0 ; if ( _rtDW -> TimeStampA_p
== ( rtInf ) ) { _rtDW -> TimeStampA_p = ssGetT ( S ) ; lastU = & _rtDW ->
LastUAtTimeA_j ; } else if ( _rtDW -> TimeStampB_p == ( rtInf ) ) { _rtDW ->
TimeStampB_p = ssGetT ( S ) ; lastU = & _rtDW -> LastUAtTimeB_p ; } else if (
_rtDW -> TimeStampA_p < _rtDW -> TimeStampB_p ) { _rtDW -> TimeStampA_p =
ssGetT ( S ) ; lastU = & _rtDW -> LastUAtTimeA_j ; } else { _rtDW ->
TimeStampB_p = ssGetT ( S ) ; lastU = & _rtDW -> LastUAtTimeB_p ; } * lastU =
_rtB -> B_22_0_1 ; if ( _rtDW -> TimeStampA_l == ( rtInf ) ) { _rtDW ->
TimeStampA_l = ssGetT ( S ) ; lastU = & _rtDW -> LastUAtTimeA_e ; } else if (
_rtDW -> TimeStampB_o == ( rtInf ) ) { _rtDW -> TimeStampB_o = ssGetT ( S ) ;
lastU = & _rtDW -> LastUAtTimeB_l ; } else if ( _rtDW -> TimeStampA_l < _rtDW
-> TimeStampB_o ) { _rtDW -> TimeStampA_l = ssGetT ( S ) ; lastU = & _rtDW ->
LastUAtTimeA_e ; } else { _rtDW -> TimeStampB_o = ssGetT ( S ) ; lastU = &
_rtDW -> LastUAtTimeB_l ; } * lastU = _rtB -> B_24_0_1 ; if ( _rtDW ->
TimeStampA_dv == ( rtInf ) ) { _rtDW -> TimeStampA_dv = ssGetT ( S ) ; lastU
= & _rtDW -> LastUAtTimeA_m ; } else if ( _rtDW -> TimeStampB_d == ( rtInf )
) { _rtDW -> TimeStampB_d = ssGetT ( S ) ; lastU = & _rtDW -> LastUAtTimeB_nt
; } else if ( _rtDW -> TimeStampA_dv < _rtDW -> TimeStampB_d ) { _rtDW ->
TimeStampA_dv = ssGetT ( S ) ; lastU = & _rtDW -> LastUAtTimeA_m ; } else {
_rtDW -> TimeStampB_d = ssGetT ( S ) ; lastU = & _rtDW -> LastUAtTimeB_nt ; }
* lastU = _rtB -> B_26_34_0 ; isHit = ssIsSampleHit ( S , 3 , 0 ) ; if (
isHit != 0 ) { _rtDW -> NextOutput = rt_nrand_Upu32_Yd_f_pw_snf ( & _rtDW ->
RandSeed ) * _rtP -> P_19 + _rtP -> P_18 ; } if ( _rtDW -> TimeStampA_k == (
rtInf ) ) { _rtDW -> TimeStampA_k = ssGetT ( S ) ; lastU = & _rtDW ->
LastUAtTimeA_pl ; } else if ( _rtDW -> TimeStampB_if == ( rtInf ) ) { _rtDW
-> TimeStampB_if = ssGetT ( S ) ; lastU = & _rtDW -> LastUAtTimeB_d ; } else
if ( _rtDW -> TimeStampA_k < _rtDW -> TimeStampB_if ) { _rtDW -> TimeStampA_k
= ssGetT ( S ) ; lastU = & _rtDW -> LastUAtTimeA_pl ; } else { _rtDW ->
TimeStampB_if = ssGetT ( S ) ; lastU = & _rtDW -> LastUAtTimeB_d ; } * lastU
= _rtB -> B_7_0_1 ; if ( _rtDW -> TimeStampA_n == ( rtInf ) ) { _rtDW ->
TimeStampA_n = ssGetT ( S ) ; lastU = & _rtDW -> LastUAtTimeA_i ; } else if (
_rtDW -> TimeStampB_c == ( rtInf ) ) { _rtDW -> TimeStampB_c = ssGetT ( S ) ;
lastU = & _rtDW -> LastUAtTimeB_nb ; } else if ( _rtDW -> TimeStampA_n <
_rtDW -> TimeStampB_c ) { _rtDW -> TimeStampA_n = ssGetT ( S ) ; lastU = &
_rtDW -> LastUAtTimeA_i ; } else { _rtDW -> TimeStampB_c = ssGetT ( S ) ;
lastU = & _rtDW -> LastUAtTimeB_nb ; } * lastU = _rtB -> B_9_0_1 ; if ( _rtDW
-> TimeStampA_f == ( rtInf ) ) { _rtDW -> TimeStampA_f = ssGetT ( S ) ; lastU
= & _rtDW -> LastUAtTimeA_n ; } else if ( _rtDW -> TimeStampB_a == ( rtInf )
) { _rtDW -> TimeStampB_a = ssGetT ( S ) ; lastU = & _rtDW -> LastUAtTimeB_lc
; } else if ( _rtDW -> TimeStampA_f < _rtDW -> TimeStampB_a ) { _rtDW ->
TimeStampA_f = ssGetT ( S ) ; lastU = & _rtDW -> LastUAtTimeA_n ; } else {
_rtDW -> TimeStampB_a = ssGetT ( S ) ; lastU = & _rtDW -> LastUAtTimeB_lc ; }
* lastU = _rtB -> B_26_79_0 ; if ( _rtDW -> TimeStampA_c == ( rtInf ) ) {
_rtDW -> TimeStampA_c = ssGetT ( S ) ; lastU = & _rtDW -> LastUAtTimeA_d ; }
else if ( _rtDW -> TimeStampB_e == ( rtInf ) ) { _rtDW -> TimeStampB_e =
ssGetT ( S ) ; lastU = & _rtDW -> LastUAtTimeB_j ; } else if ( _rtDW ->
TimeStampA_c < _rtDW -> TimeStampB_e ) { _rtDW -> TimeStampA_c = ssGetT ( S )
; lastU = & _rtDW -> LastUAtTimeA_d ; } else { _rtDW -> TimeStampB_e = ssGetT
( S ) ; lastU = & _rtDW -> LastUAtTimeB_j ; } * lastU = _rtB -> B_12_0_1 ; if
( _rtDW -> TimeStampA_m == ( rtInf ) ) { _rtDW -> TimeStampA_m = ssGetT ( S )
; lastU = & _rtDW -> LastUAtTimeA_di ; } else if ( _rtDW -> TimeStampB_nz ==
( rtInf ) ) { _rtDW -> TimeStampB_nz = ssGetT ( S ) ; lastU = & _rtDW ->
LastUAtTimeB_o ; } else if ( _rtDW -> TimeStampA_m < _rtDW -> TimeStampB_nz )
{ _rtDW -> TimeStampA_m = ssGetT ( S ) ; lastU = & _rtDW -> LastUAtTimeA_di ;
} else { _rtDW -> TimeStampB_nz = ssGetT ( S ) ; lastU = & _rtDW ->
LastUAtTimeB_o ; } * lastU = _rtB -> B_14_0_1 ; if ( _rtDW -> TimeStampA_cb
== ( rtInf ) ) { _rtDW -> TimeStampA_cb = ssGetT ( S ) ; lastU = & _rtDW ->
LastUAtTimeA_g ; } else if ( _rtDW -> TimeStampB_j == ( rtInf ) ) { _rtDW ->
TimeStampB_j = ssGetT ( S ) ; lastU = & _rtDW -> LastUAtTimeB_f ; } else if (
_rtDW -> TimeStampA_cb < _rtDW -> TimeStampB_j ) { _rtDW -> TimeStampA_cb =
ssGetT ( S ) ; lastU = & _rtDW -> LastUAtTimeA_g ; } else { _rtDW ->
TimeStampB_j = ssGetT ( S ) ; lastU = & _rtDW -> LastUAtTimeB_f ; } * lastU =
_rtB -> B_26_83_0 ; isHit = ssIsSampleHit ( S , 3 , 0 ) ; if ( isHit != 0 ) {
_rtDW -> NextOutput_c = rt_nrand_Upu32_Yd_f_pw_snf ( & _rtDW -> RandSeed_c )
* _rtP -> P_83 + _rtP -> P_82 ; } { real_T * * uBuffer = ( real_T * * ) &
_rtDW -> VariableTimeDelay1_PWORK . TUbufferPtrs [ 0 ] ; real_T simTime =
ssGetT ( S ) ; _rtDW -> VariableTimeDelay1_IWORK . Head = ( ( _rtDW ->
VariableTimeDelay1_IWORK . Head < ( _rtDW -> VariableTimeDelay1_IWORK .
CircularBufSize - 1 ) ) ? ( _rtDW -> VariableTimeDelay1_IWORK . Head + 1 ) :
0 ) ; if ( _rtDW -> VariableTimeDelay1_IWORK . Head == _rtDW ->
VariableTimeDelay1_IWORK . Tail ) { if ( !
air_part1_python2_acc_rt_TDelayUpdateTailOrGrowBuf ( & _rtDW ->
VariableTimeDelay1_IWORK . CircularBufSize , & _rtDW ->
VariableTimeDelay1_IWORK . Tail , & _rtDW -> VariableTimeDelay1_IWORK . Head
, & _rtDW -> VariableTimeDelay1_IWORK . Last , simTime - _rtP -> P_87 ,
uBuffer , ( boolean_T ) 0 , ( boolean_T ) 0 , & _rtDW ->
VariableTimeDelay1_IWORK . MaxNewBufSize ) ) { ssSetErrorStatus ( S ,
"vtdelay memory allocation error" ) ; return ; } } ( * uBuffer + _rtDW ->
VariableTimeDelay1_IWORK . CircularBufSize ) [ _rtDW ->
VariableTimeDelay1_IWORK . Head ] = simTime ; ( * uBuffer ) [ _rtDW ->
VariableTimeDelay1_IWORK . Head ] = _rtB -> B_26_238_0 ; } isHit =
ssIsSampleHit ( S , 5 , 0 ) ; if ( isHit != 0 ) { if ( _rtDW -> nextOutput )
{ dc = _rtB -> B_26_174_0 ; if ( ( _rtB -> B_26_2_0 < 0.0001 ) || (
muDoubleScalarIsNaN ( _rtB -> B_26_2_0 ) || ( _rtB -> B_26_2_0 == ( rtInf ) )
) ) { arg3 = ssGetTaskTime ( S , 5 ) ; diag = CreateDiagnosticAsVoidPtr (
"Simulink:blocks:InvInputPeriodForVPGDiscMode" , 4 , 3 ,
"air_part1_python2/PWM/Variable Pulse Generator" , 2 , _rtB -> B_26_2_0 , 2 ,
arg3 , 2 , 5.0E-5 ) ; rt_ssSet_slErrMsg ( S , diag ) ; } if ( dc > 1.0 ) { dc
= 1.0 ; if ( _rtDW -> isFirstWarningDCGreaterThanOne ) { arg3 = ssGetTaskTime
( S , 5 ) ; diag = CreateDiagnosticAsVoidPtr (
"Simulink:blocks:warnDutyCycleGreaterThanOne" , 3 , 2 , arg3 , 2 , _rtB ->
B_26_174_0 , 3 , "air_part1_python2/PWM/Variable Pulse Generator" ) ;
rt_ssReportDiagnosticAsWarning ( S , diag ) ; _rtDW ->
isFirstWarningDCGreaterThanOne = false ; } } dc = muDoubleScalarFloor ( (
2.2204460492503131E-16 * dc * _rtB -> B_26_2_0 + dc * _rtB -> B_26_2_0 ) /
5.0E-5 ) ; if ( muDoubleScalarIsNaN ( dc ) || muDoubleScalarIsInf ( dc ) ) {
dc = 0.0 ; } else { dc = muDoubleScalarRem ( dc , 4.294967296E+9 ) ; }
numTicksToNextSampleHit = dc < 0.0 ? ( uint32_T ) - ( int32_T ) ( uint32_T )
- dc : ( uint32_T ) dc ; if ( numTicksToNextSampleHit <= 0U ) { dc =
ssGetTaskTime ( S , 5 ) ; diag = CreateDiagnosticAsVoidPtr (
"Simulink:blocks:InvSamplingRateForVPG" , 5 , 3 ,
"air_part1_python2/PWM/Variable Pulse Generator" , 2 , 5.0E-5 , 2 , _rtB ->
B_26_174_0 , 2 , _rtB -> B_26_2_0 , 2 , dc ) ; rt_ssSet_slErrMsg ( S , diag )
; } dc = muDoubleScalarFloor ( ( 2.2204460492503131E-16 * _rtB -> B_26_2_0 +
_rtB -> B_26_2_0 ) / 5.0E-5 ) ; if ( muDoubleScalarIsNaN ( dc ) ||
muDoubleScalarIsInf ( dc ) ) { dc = 0.0 ; } else { dc = muDoubleScalarRem (
dc , 4.294967296E+9 ) ; } totalTicksInPeriod = dc < 0.0 ? ( uint32_T ) - (
int32_T ) ( uint32_T ) - dc : ( uint32_T ) dc ; if ( numTicksToNextSampleHit
< totalTicksInPeriod ) { ssSetNumTicksToNextHitForControllableSampleTime ( S
, 5 , numTicksToNextSampleHit ) ; _rtDW -> nextOutput = false ; _rtDW ->
isStartOfNextCycle = false ; } else {
ssSetNumTicksToNextHitForControllableSampleTime ( S , 5 , totalTicksInPeriod
) ; _rtDW -> nextOutput = true ; _rtDW -> isStartOfNextCycle = true ; } _rtDW
-> startTimeOfNextCycle = totalTicksInPeriod - numTicksToNextSampleHit ; }
else { if ( _rtDW -> isStartOfNextCycle ) { dc = _rtB -> B_26_174_0 ; if ( (
_rtB -> B_26_2_0 <= 0.0 ) || ( muDoubleScalarIsNaN ( _rtB -> B_26_2_0 ) || (
_rtB -> B_26_2_0 == ( rtInf ) ) ) ) { arg3 = ssGetTaskTime ( S , 5 ) ; diag =
CreateDiagnosticAsVoidPtr ( "Simulink:blocks:InvInputPeriodForVPG" , 3 , 3 ,
"air_part1_python2/PWM/Variable Pulse Generator" , 2 , _rtB -> B_26_2_0 , 2 ,
arg3 ) ; rt_ssSet_slErrMsg ( S , diag ) ; } if ( ( dc < 0.0 ) && _rtDW ->
isFirstWarningDCLessThanZero ) { arg3 = ssGetTaskTime ( S , 5 ) ; diag =
CreateDiagnosticAsVoidPtr ( "Simulink:blocks:warnDutyCycleLessThanZero" , 3 ,
2 , arg3 , 2 , _rtB -> B_26_174_0 , 3 ,
"air_part1_python2/PWM/Variable Pulse Generator" ) ;
rt_ssReportDiagnosticAsWarning ( S , diag ) ; _rtDW ->
isFirstWarningDCLessThanZero = false ; } dc = muDoubleScalarFloor ( (
2.2204460492503131E-16 * _rtB -> B_26_2_0 + _rtB -> B_26_2_0 ) / 5.0E-5 ) ;
if ( muDoubleScalarIsNaN ( dc ) || muDoubleScalarIsInf ( dc ) ) { dc = 0.0 ;
} else { dc = muDoubleScalarRem ( dc , 4.294967296E+9 ) ; }
ssSetNumTicksToNextHitForControllableSampleTime ( S , 5 , dc < 0.0 ? (
uint32_T ) - ( int32_T ) ( uint32_T ) - dc : ( uint32_T ) dc ) ; } else if (
_rtDW -> startTimeOfNextCycle > 0.0 ) {
ssSetNumTicksToNextHitForControllableSampleTime ( S , 5 , _rtDW ->
startTimeOfNextCycle ) ; } _rtDW -> nextOutput = true ; _rtDW ->
isStartOfNextCycle = true ; } } { real_T * * uBuffer = ( real_T * * ) & _rtDW
-> VariableTimeDelay_PWORK . TUbufferPtrs [ 0 ] ; real_T simTime = ssGetT ( S
) ; _rtDW -> VariableTimeDelay_IWORK . Head = ( ( _rtDW ->
VariableTimeDelay_IWORK . Head < ( _rtDW -> VariableTimeDelay_IWORK .
CircularBufSize - 1 ) ) ? ( _rtDW -> VariableTimeDelay_IWORK . Head + 1 ) : 0
) ; if ( _rtDW -> VariableTimeDelay_IWORK . Head == _rtDW ->
VariableTimeDelay_IWORK . Tail ) { if ( !
air_part1_python2_acc_rt_TDelayUpdateTailOrGrowBuf ( & _rtDW ->
VariableTimeDelay_IWORK . CircularBufSize , & _rtDW ->
VariableTimeDelay_IWORK . Tail , & _rtDW -> VariableTimeDelay_IWORK . Head ,
& _rtDW -> VariableTimeDelay_IWORK . Last , simTime - _rtP -> P_89 , uBuffer
, ( boolean_T ) 0 , ( boolean_T ) 0 , & _rtDW -> VariableTimeDelay_IWORK .
MaxNewBufSize ) ) { ssSetErrorStatus ( S , "vtdelay memory allocation error"
) ; return ; } } ( * uBuffer + _rtDW -> VariableTimeDelay_IWORK .
CircularBufSize ) [ _rtDW -> VariableTimeDelay_IWORK . Head ] = simTime ; ( *
uBuffer ) [ _rtDW -> VariableTimeDelay_IWORK . Head ] = _rtB -> B_26_239_0 ;
} isHit = ssIsSampleHit ( S , 4 , 0 ) ; if ( isHit != 0 ) { if ( _rtDW ->
nextOutput_b ) { dc = _rtB -> B_26_176_0 ; if ( ( _rtB -> B_26_3_0 < 0.0001 )
|| ( muDoubleScalarIsNaN ( _rtB -> B_26_3_0 ) || ( _rtB -> B_26_3_0 == (
rtInf ) ) ) ) { arg3 = ssGetTaskTime ( S , 4 ) ; diag =
CreateDiagnosticAsVoidPtr ( "Simulink:blocks:InvInputPeriodForVPGDiscMode" ,
4 , 3 , "air_part1_python2/PWM1/Variable Pulse Generator" , 2 , _rtB ->
B_26_3_0 , 2 , arg3 , 2 , 5.0E-5 ) ; rt_ssSet_slErrMsg ( S , diag ) ; } if (
dc > 1.0 ) { dc = 1.0 ; if ( _rtDW -> isFirstWarningDCGreaterThanOne_b ) {
arg3 = ssGetTaskTime ( S , 4 ) ; diag = CreateDiagnosticAsVoidPtr (
"Simulink:blocks:warnDutyCycleGreaterThanOne" , 3 , 2 , arg3 , 2 , _rtB ->
B_26_176_0 , 3 , "air_part1_python2/PWM1/Variable Pulse Generator" ) ;
rt_ssReportDiagnosticAsWarning ( S , diag ) ; _rtDW ->
isFirstWarningDCGreaterThanOne_b = false ; } } dc = muDoubleScalarFloor ( (
2.2204460492503131E-16 * dc * _rtB -> B_26_3_0 + dc * _rtB -> B_26_3_0 ) /
5.0E-5 ) ; if ( muDoubleScalarIsNaN ( dc ) || muDoubleScalarIsInf ( dc ) ) {
dc = 0.0 ; } else { dc = muDoubleScalarRem ( dc , 4.294967296E+9 ) ; }
numTicksToNextSampleHit = dc < 0.0 ? ( uint32_T ) - ( int32_T ) ( uint32_T )
- dc : ( uint32_T ) dc ; if ( numTicksToNextSampleHit <= 0U ) { dc =
ssGetTaskTime ( S , 4 ) ; diag = CreateDiagnosticAsVoidPtr (
"Simulink:blocks:InvSamplingRateForVPG" , 5 , 3 ,
"air_part1_python2/PWM1/Variable Pulse Generator" , 2 , 5.0E-5 , 2 , _rtB ->
B_26_176_0 , 2 , _rtB -> B_26_3_0 , 2 , dc ) ; rt_ssSet_slErrMsg ( S , diag )
; } dc = muDoubleScalarFloor ( ( 2.2204460492503131E-16 * _rtB -> B_26_3_0 +
_rtB -> B_26_3_0 ) / 5.0E-5 ) ; if ( muDoubleScalarIsNaN ( dc ) ||
muDoubleScalarIsInf ( dc ) ) { dc = 0.0 ; } else { dc = muDoubleScalarRem (
dc , 4.294967296E+9 ) ; } totalTicksInPeriod = dc < 0.0 ? ( uint32_T ) - (
int32_T ) ( uint32_T ) - dc : ( uint32_T ) dc ; if ( numTicksToNextSampleHit
< totalTicksInPeriod ) { ssSetNumTicksToNextHitForControllableSampleTime ( S
, 4 , numTicksToNextSampleHit ) ; _rtDW -> nextOutput_b = false ; _rtDW ->
isStartOfNextCycle_p = false ; } else {
ssSetNumTicksToNextHitForControllableSampleTime ( S , 4 , totalTicksInPeriod
) ; _rtDW -> nextOutput_b = true ; _rtDW -> isStartOfNextCycle_p = true ; }
_rtDW -> startTimeOfNextCycle_n = totalTicksInPeriod -
numTicksToNextSampleHit ; } else { if ( _rtDW -> isStartOfNextCycle_p ) { dc
= _rtB -> B_26_176_0 ; if ( ( _rtB -> B_26_3_0 <= 0.0 ) || (
muDoubleScalarIsNaN ( _rtB -> B_26_3_0 ) || ( _rtB -> B_26_3_0 == ( rtInf ) )
) ) { arg3 = ssGetTaskTime ( S , 4 ) ; diag = CreateDiagnosticAsVoidPtr (
"Simulink:blocks:InvInputPeriodForVPG" , 3 , 3 ,
"air_part1_python2/PWM1/Variable Pulse Generator" , 2 , _rtB -> B_26_3_0 , 2
, arg3 ) ; rt_ssSet_slErrMsg ( S , diag ) ; } if ( ( dc < 0.0 ) && _rtDW ->
isFirstWarningDCLessThanZero_g ) { arg3 = ssGetTaskTime ( S , 4 ) ; diag =
CreateDiagnosticAsVoidPtr ( "Simulink:blocks:warnDutyCycleLessThanZero" , 3 ,
2 , arg3 , 2 , _rtB -> B_26_176_0 , 3 ,
"air_part1_python2/PWM1/Variable Pulse Generator" ) ;
rt_ssReportDiagnosticAsWarning ( S , diag ) ; _rtDW ->
isFirstWarningDCLessThanZero_g = false ; } dc = muDoubleScalarFloor ( (
2.2204460492503131E-16 * _rtB -> B_26_3_0 + _rtB -> B_26_3_0 ) / 5.0E-5 ) ;
if ( muDoubleScalarIsNaN ( dc ) || muDoubleScalarIsInf ( dc ) ) { dc = 0.0 ;
} else { dc = muDoubleScalarRem ( dc , 4.294967296E+9 ) ; }
ssSetNumTicksToNextHitForControllableSampleTime ( S , 4 , dc < 0.0 ? (
uint32_T ) - ( int32_T ) ( uint32_T ) - dc : ( uint32_T ) dc ) ; } else if (
_rtDW -> startTimeOfNextCycle_n > 0.0 ) {
ssSetNumTicksToNextHitForControllableSampleTime ( S , 4 , _rtDW ->
startTimeOfNextCycle_n ) ; } _rtDW -> nextOutput_b = true ; _rtDW ->
isStartOfNextCycle_p = true ; } } UNUSED_PARAMETER ( tid ) ; }
#define MDL_UPDATE
static void mdlUpdateTID6 ( SimStruct * S , int_T tid ) { UNUSED_PARAMETER (
tid ) ; }
#define MDL_DERIVATIVES
static void mdlDerivatives ( SimStruct * S ) { B_air_part1_python2_T * _rtB ;
DW_air_part1_python2_T * _rtDW ; P_air_part1_python2_T * _rtP ;
XDot_air_part1_python2_T * _rtXdot ; _rtDW = ( ( DW_air_part1_python2_T * )
ssGetRootDWork ( S ) ) ; _rtXdot = ( ( XDot_air_part1_python2_T * ) ssGetdX (
S ) ) ; _rtP = ( ( P_air_part1_python2_T * ) ssGetModelRtp ( S ) ) ; _rtB = (
( B_air_part1_python2_T * ) _ssGetModelBlockIO ( S ) ) ; _rtXdot ->
Integrator1_CSTATE = _rtB -> B_26_228_0 ; _rtXdot -> Integrator_CSTATE = _rtB
-> B_26_224_0 ; _rtXdot -> Integrator1_CSTATE_p = _rtB -> B_26_217_0 ;
_rtXdot -> Integrator3_CSTATE = _rtB -> B_26_70_0 ; _rtXdot ->
Integrator2_CSTATE = _rtB -> B_26_197_0 ; _rtXdot -> Integrator_CSTATE_p =
_rtB -> B_26_218_0 ; _rtXdot -> Integrator1_CSTATE_j = _rtB -> B_26_237_0 ;
_rtXdot -> Integrator_CSTATE_h = _rtB -> B_26_232_0 ; { } { } } static void
mdlInitializeSizes ( SimStruct * S ) { ssSetChecksumVal ( S , 0 , 3033975632U
) ; ssSetChecksumVal ( S , 1 , 303587088U ) ; ssSetChecksumVal ( S , 2 ,
786652794U ) ; ssSetChecksumVal ( S , 3 , 801828522U ) ; { mxArray *
slVerStructMat = ( NULL ) ; mxArray * slStrMat = mxCreateString ( "simulink"
) ; char slVerChar [ 10 ] ; int status = mexCallMATLAB ( 1 , & slVerStructMat
, 1 , & slStrMat , "ver" ) ; if ( status == 0 ) { mxArray * slVerMat =
mxGetField ( slVerStructMat , 0 , "Version" ) ; if ( slVerMat == ( NULL ) ) {
status = 1 ; } else { status = mxGetString ( slVerMat , slVerChar , 10 ) ; }
} mxDestroyArray ( slStrMat ) ; mxDestroyArray ( slVerStructMat ) ; if ( (
status == 1 ) || ( strcmp ( slVerChar , "10.6" ) != 0 ) ) { return ; } }
ssSetOptions ( S , SS_OPTION_EXCEPTION_FREE_CODE ) ; if ( ssGetSizeofDWork (
S ) != ( SLSize ) sizeof ( DW_air_part1_python2_T ) ) { static char msg [ 256
] ; sprintf ( msg , "Unexpected error: Internal DWork sizes do "
"not match for accelerator mex file (%ld vs %lu)." , ( signed long )
ssGetSizeofDWork ( S ) , ( unsigned long ) sizeof ( DW_air_part1_python2_T )
) ; ssSetErrorStatus ( S , msg ) ; } if ( ssGetSizeofGlobalBlockIO ( S ) != (
SLSize ) sizeof ( B_air_part1_python2_T ) ) { static char msg [ 256 ] ;
sprintf ( msg , "Unexpected error: Internal BlockIO sizes do "
"not match for accelerator mex file (%ld vs %lu)." , ( signed long )
ssGetSizeofGlobalBlockIO ( S ) , ( unsigned long ) sizeof (
B_air_part1_python2_T ) ) ; ssSetErrorStatus ( S , msg ) ; } { int
ssSizeofParams ; ssGetSizeofParams ( S , & ssSizeofParams ) ; if (
ssSizeofParams != sizeof ( P_air_part1_python2_T ) ) { static char msg [ 256
] ; sprintf ( msg , "Unexpected error: Internal Parameters sizes do "
"not match for accelerator mex file (%d vs %lu)." , ssSizeofParams , (
unsigned long ) sizeof ( P_air_part1_python2_T ) ) ; ssSetErrorStatus ( S ,
msg ) ; } } _ssSetModelRtp ( S , ( real_T * ) & air_part1_python2_rtDefaultP
) ; rt_InitInfAndNaN ( sizeof ( real_T ) ) ; } static void
mdlInitializeSampleTimes ( SimStruct * S ) { { SimStruct * childS ;
SysOutputFcn * callSysFcns ; childS = ssGetSFunction ( S , 0 ) ; callSysFcns
= ssGetCallSystemOutputFcnList ( childS ) ; callSysFcns [ 3 + 0 ] = (
SysOutputFcn ) ( NULL ) ; childS = ssGetSFunction ( S , 1 ) ; callSysFcns =
ssGetCallSystemOutputFcnList ( childS ) ; callSysFcns [ 3 + 0 ] = (
SysOutputFcn ) ( NULL ) ; childS = ssGetSFunction ( S , 2 ) ; callSysFcns =
ssGetCallSystemOutputFcnList ( childS ) ; callSysFcns [ 3 + 0 ] = (
SysOutputFcn ) ( NULL ) ; childS = ssGetSFunction ( S , 3 ) ; callSysFcns =
ssGetCallSystemOutputFcnList ( childS ) ; callSysFcns [ 3 + 0 ] = (
SysOutputFcn ) ( NULL ) ; childS = ssGetSFunction ( S , 4 ) ; callSysFcns =
ssGetCallSystemOutputFcnList ( childS ) ; callSysFcns [ 3 + 0 ] = (
SysOutputFcn ) ( NULL ) ; childS = ssGetSFunction ( S , 5 ) ; callSysFcns =
ssGetCallSystemOutputFcnList ( childS ) ; callSysFcns [ 3 + 0 ] = (
SysOutputFcn ) ( NULL ) ; childS = ssGetSFunction ( S , 6 ) ; callSysFcns =
ssGetCallSystemOutputFcnList ( childS ) ; callSysFcns [ 3 + 0 ] = (
SysOutputFcn ) ( NULL ) ; childS = ssGetSFunction ( S , 7 ) ; callSysFcns =
ssGetCallSystemOutputFcnList ( childS ) ; callSysFcns [ 3 + 0 ] = (
SysOutputFcn ) ( NULL ) ; childS = ssGetSFunction ( S , 8 ) ; callSysFcns =
ssGetCallSystemOutputFcnList ( childS ) ; callSysFcns [ 3 + 0 ] = (
SysOutputFcn ) ( NULL ) ; childS = ssGetSFunction ( S , 9 ) ; callSysFcns =
ssGetCallSystemOutputFcnList ( childS ) ; callSysFcns [ 3 + 0 ] = (
SysOutputFcn ) ( NULL ) ; childS = ssGetSFunction ( S , 10 ) ; callSysFcns =
ssGetCallSystemOutputFcnList ( childS ) ; callSysFcns [ 3 + 0 ] = (
SysOutputFcn ) ( NULL ) ; childS = ssGetSFunction ( S , 11 ) ; callSysFcns =
ssGetCallSystemOutputFcnList ( childS ) ; callSysFcns [ 3 + 0 ] = (
SysOutputFcn ) ( NULL ) ; childS = ssGetSFunction ( S , 12 ) ; callSysFcns =
ssGetCallSystemOutputFcnList ( childS ) ; callSysFcns [ 3 + 0 ] = (
SysOutputFcn ) ( NULL ) ; childS = ssGetSFunction ( S , 13 ) ; callSysFcns =
ssGetCallSystemOutputFcnList ( childS ) ; callSysFcns [ 3 + 0 ] = (
SysOutputFcn ) ( NULL ) ; childS = ssGetSFunction ( S , 14 ) ; callSysFcns =
ssGetCallSystemOutputFcnList ( childS ) ; callSysFcns [ 3 + 0 ] = (
SysOutputFcn ) ( NULL ) ; childS = ssGetSFunction ( S , 15 ) ; callSysFcns =
ssGetCallSystemOutputFcnList ( childS ) ; callSysFcns [ 3 + 0 ] = (
SysOutputFcn ) ( NULL ) ; childS = ssGetSFunction ( S , 16 ) ; callSysFcns =
ssGetCallSystemOutputFcnList ( childS ) ; callSysFcns [ 3 + 0 ] = (
SysOutputFcn ) ( NULL ) ; childS = ssGetSFunction ( S , 17 ) ; callSysFcns =
ssGetCallSystemOutputFcnList ( childS ) ; callSysFcns [ 3 + 0 ] = (
SysOutputFcn ) ( NULL ) ; childS = ssGetSFunction ( S , 18 ) ; callSysFcns =
ssGetCallSystemOutputFcnList ( childS ) ; callSysFcns [ 3 + 0 ] = (
SysOutputFcn ) ( NULL ) ; childS = ssGetSFunction ( S , 19 ) ; callSysFcns =
ssGetCallSystemOutputFcnList ( childS ) ; callSysFcns [ 3 + 0 ] = (
SysOutputFcn ) ( NULL ) ; childS = ssGetSFunction ( S , 20 ) ; callSysFcns =
ssGetCallSystemOutputFcnList ( childS ) ; callSysFcns [ 3 + 0 ] = (
SysOutputFcn ) ( NULL ) ; childS = ssGetSFunction ( S , 21 ) ; callSysFcns =
ssGetCallSystemOutputFcnList ( childS ) ; callSysFcns [ 3 + 0 ] = (
SysOutputFcn ) ( NULL ) ; childS = ssGetSFunction ( S , 22 ) ; callSysFcns =
ssGetCallSystemOutputFcnList ( childS ) ; callSysFcns [ 3 + 0 ] = (
SysOutputFcn ) ( NULL ) ; childS = ssGetSFunction ( S , 23 ) ; callSysFcns =
ssGetCallSystemOutputFcnList ( childS ) ; callSysFcns [ 3 + 0 ] = (
SysOutputFcn ) ( NULL ) ; } slAccRegPrmChangeFcn ( S , mdlOutputsTID6 ) ; }
static void mdlTerminate ( SimStruct * S ) { }
#include "simulink.c"
