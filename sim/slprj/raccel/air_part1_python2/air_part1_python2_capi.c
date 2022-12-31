#include "rtw_capi.h"
#ifdef HOST_CAPI_BUILD
#include "air_part1_python2_capi_host.h"
#define sizeof(s) ((size_t)(0xFFFF))
#undef rt_offsetof
#define rt_offsetof(s,el) ((uint16_T)(0xFFFF))
#define TARGET_CONST
#define TARGET_STRING(s) (s)
#ifndef SS_UINT64
#define SS_UINT64 20
#endif
#ifndef SS_INT64
#define SS_INT64 21
#endif
#else
#include "builtin_typeid_types.h"
#include "air_part1_python2.h"
#include "air_part1_python2_capi.h"
#include "air_part1_python2_private.h"
#ifdef LIGHT_WEIGHT_CAPI
#define TARGET_CONST
#define TARGET_STRING(s)               ((NULL))
#else
#define TARGET_CONST                   const
#define TARGET_STRING(s)               (s)
#endif
#endif
static const rtwCAPI_Signals rtBlockSignals [ ] = { { 0 , 0 , TARGET_STRING (
"air_part1_python2/5" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 1 ,
0 , TARGET_STRING ( "air_part1_python2/Gain" ) , TARGET_STRING ( "" ) , 0 , 0
, 0 , 0 , 1 } , { 2 , 0 , TARGET_STRING ( "air_part1_python2/Gain1" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 1 } , { 3 , 0 , TARGET_STRING (
"air_part1_python2/ギア比" ) , TARGET_STRING ( "羽ばたき周波数" ) , 0 , 0 , 0
, 0 , 0 } , { 4 , 0 , TARGET_STRING ( "air_part1_python2/ギア比1" ) ,
TARGET_STRING ( "羽ばたき周波数roll/s" ) , 0 , 0 , 0 , 0 , 0 } , { 5 , 0 ,
TARGET_STRING ( "air_part1_python2/ギア比4" ) , TARGET_STRING ( "角速度rad/s"
) , 0 , 0 , 0 , 0 , 0 } , { 6 , 0 , TARGET_STRING (
"air_part1_python2/ギア比5" ) , TARGET_STRING ( "角速度rad/s" ) , 0 , 0 , 0 ,
0 , 0 } , { 7 , 0 , TARGET_STRING ( "air_part1_python2/変換2" ) ,
TARGET_STRING ( "duty比" ) , 0 , 0 , 0 , 0 , 2 } , { 8 , 0 , TARGET_STRING (
"air_part1_python2/変換3" ) , TARGET_STRING ( "duty比" ) , 0 , 0 , 0 , 0 , 2
} , { 9 , 0 , TARGET_STRING ( "air_part1_python2/Integrator3" ) ,
TARGET_STRING ( "角度" ) , 0 , 0 , 0 , 0 , 0 } , { 10 , 0 , TARGET_STRING (
"air_part1_python2/Product" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 3 } ,
{ 11 , 0 , TARGET_STRING ( "air_part1_python2/Product1" ) , TARGET_STRING (
"" ) , 0 , 0 , 0 , 0 , 3 } , { 12 , 0 , TARGET_STRING (
"air_part1_python2/Product6" ) , TARGET_STRING ( "角加速度" ) , 0 , 0 , 0 , 0
, 0 } , { 13 , 0 , TARGET_STRING ( "air_part1_python2/ASCII Decode" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 2 } , { 14 , 0 , TARGET_STRING (
"air_part1_python2/ASCII Decode1" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 ,
2 } , { 15 , 0 , TARGET_STRING ( "air_part1_python2/ASCII Decode2" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 2 } , { 16 , 0 , TARGET_STRING (
"air_part1_python2/ASCII Decode3" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 ,
2 } , { 17 , 0 , TARGET_STRING ( "air_part1_python2/ASCII Decode4" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 2 } , { 18 , 0 , TARGET_STRING (
"air_part1_python2/ASCII Decode5" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 ,
2 } , { 19 , 0 , TARGET_STRING ( "air_part1_python2/ASCII Encode" ) ,
TARGET_STRING ( "" ) , 0 , 1 , 1 , 0 , 3 } , { 20 , 0 , TARGET_STRING (
"air_part1_python2/ASCII Encode1" ) , TARGET_STRING ( "" ) , 0 , 1 , 1 , 0 ,
3 } , { 21 , 0 , TARGET_STRING ( "air_part1_python2/Byte Packing" ) ,
TARGET_STRING ( "" ) , 0 , 1 , 2 , 0 , 3 } , { 22 , 0 , TARGET_STRING (
"air_part1_python2/Byte Unpack" ) , TARGET_STRING ( "" ) , 0 , 1 , 0 , 0 , 2
} , { 23 , 0 , TARGET_STRING ( "air_part1_python2/Byte Unpack" ) ,
TARGET_STRING ( "" ) , 1 , 1 , 0 , 0 , 2 } , { 24 , 0 , TARGET_STRING (
"air_part1_python2/Byte Unpack" ) , TARGET_STRING ( "" ) , 2 , 1 , 0 , 0 , 2
} , { 25 , 0 , TARGET_STRING ( "air_part1_python2/Byte Unpack" ) ,
TARGET_STRING ( "" ) , 3 , 1 , 0 , 0 , 2 } , { 26 , 0 , TARGET_STRING (
"air_part1_python2/Byte Unpack" ) , TARGET_STRING ( "" ) , 4 , 1 , 0 , 0 , 2
} , { 27 , 0 , TARGET_STRING ( "air_part1_python2/Byte Unpack" ) ,
TARGET_STRING ( "" ) , 5 , 1 , 0 , 0 , 2 } , { 28 , 0 , TARGET_STRING (
"air_part1_python2/Sum1" ) , TARGET_STRING ( "左翼力" ) , 0 , 0 , 0 , 0 , 0 }
, { 29 , 0 , TARGET_STRING ( "air_part1_python2/Sum10" ) , TARGET_STRING ( ""
) , 0 , 0 , 0 , 0 , 0 } , { 30 , 0 , TARGET_STRING (
"air_part1_python2/Sum11" ) , TARGET_STRING ( "右翼力" ) , 0 , 0 , 0 , 0 , 0
} , { 31 , 0 , TARGET_STRING ( "air_part1_python2/Sum12" ) , TARGET_STRING (
"右翼力" ) , 0 , 0 , 0 , 0 , 0 } , { 32 , 0 , TARGET_STRING (
"air_part1_python2/Sum15" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 3 } , {
33 , 0 , TARGET_STRING ( "air_part1_python2/Sum16" ) , TARGET_STRING ( "" ) ,
0 , 0 , 0 , 0 , 3 } , { 34 , 0 , TARGET_STRING ( "air_part1_python2/Sum17" )
, TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 3 } , { 35 , 0 , TARGET_STRING (
"air_part1_python2/Sum19" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , {
36 , 0 , TARGET_STRING ( "air_part1_python2/Sum4" ) , TARGET_STRING (
"右翼力" ) , 0 , 0 , 0 , 0 , 0 } , { 37 , 0 , TARGET_STRING (
"air_part1_python2/Sum6" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , {
38 , 0 , TARGET_STRING ( "air_part1_python2/Variable Time Delay" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 39 , 0 , TARGET_STRING (
"air_part1_python2/Variable Time Delay1" ) , TARGET_STRING ( "" ) , 0 , 0 , 0
, 0 , 0 } , { 40 , 1 , TARGET_STRING ( "air_part1_python2/TCP//IP Receive" )
, TARGET_STRING ( "" ) , 0 , 1 , 3 , 0 , 2 } , { 41 , 0 , TARGET_STRING (
"air_part1_python2/PWM/Variable Pulse Generator" ) , TARGET_STRING ( "" ) , 0
, 0 , 0 , 0 , 3 } , { 42 , 0 , TARGET_STRING (
"air_part1_python2/PWM1/Variable Pulse Generator" ) , TARGET_STRING ( "" ) ,
0 , 0 , 0 , 0 , 3 } , { 43 , 0 , TARGET_STRING (
"air_part1_python2/モーター/粘性減衰係数" ) , TARGET_STRING ( "摩擦" ) , 0 ,
0 , 0 , 0 , 0 } , { 44 , 0 , TARGET_STRING (
"air_part1_python2/モーター/Integrator" ) , TARGET_STRING ( "" ) , 0 , 0 , 0
, 0 , 0 } , { 45 , 0 , TARGET_STRING ( "air_part1_python2/モーター/Product1"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 46 , 0 , TARGET_STRING (
"air_part1_python2/モーター/Product6" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 ,
0 , 0 } , { 47 , 0 , TARGET_STRING ( "air_part1_python2/モーター1/Integrator"
) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 48 , 0 , TARGET_STRING (
"air_part1_python2/モーター1/Product1" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 ,
0 , 0 } , { 49 , 0 , TARGET_STRING ( "air_part1_python2/モーター1/Product6" )
, TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 50 , 3 , TARGET_STRING (
"air_part1_python2/幾何学1/MATLAB Function" ) , TARGET_STRING ( "" ) , 0 , 0
, 0 , 0 , 0 } , { 51 , 3 , TARGET_STRING (
"air_part1_python2/幾何学1/MATLAB Function" ) , TARGET_STRING ( "" ) , 1 , 0
, 0 , 0 , 0 } , { 52 , 3 , TARGET_STRING (
"air_part1_python2/幾何学1/MATLAB Function" ) , TARGET_STRING ( "" ) , 2 , 0
, 0 , 0 , 0 } , { 53 , 3 , TARGET_STRING (
"air_part1_python2/幾何学1/MATLAB Function" ) , TARGET_STRING ( "" ) , 3 , 0
, 0 , 0 , 0 } , { 54 , 0 , TARGET_STRING (
"air_part1_python2/幾何学1/Derivative" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 ,
0 , 0 } , { 55 , 0 , TARGET_STRING ( "air_part1_python2/幾何学1/Sum6" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 56 , 4 , TARGET_STRING (
"air_part1_python2/幾何学2/MATLAB Function" ) , TARGET_STRING ( "" ) , 0 , 0
, 0 , 0 , 0 } , { 57 , 4 , TARGET_STRING (
"air_part1_python2/幾何学2/MATLAB Function" ) , TARGET_STRING ( "" ) , 1 , 0
, 0 , 0 , 0 } , { 58 , 4 , TARGET_STRING (
"air_part1_python2/幾何学2/MATLAB Function" ) , TARGET_STRING ( "" ) , 2 , 0
, 0 , 0 , 0 } , { 59 , 4 , TARGET_STRING (
"air_part1_python2/幾何学2/MATLAB Function" ) , TARGET_STRING ( "" ) , 3 , 0
, 0 , 0 , 0 } , { 60 , 0 , TARGET_STRING (
"air_part1_python2/幾何学2/Derivative" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 ,
0 , 0 } , { 61 , 0 , TARGET_STRING ( "air_part1_python2/幾何学2/Sum6" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 62 , 0 , TARGET_STRING (
"air_part1_python2/幾何学3/Sum6" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0
} , { 63 , 0 , TARGET_STRING ( "air_part1_python2/幾何学4/Derivative" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 64 , 0 , TARGET_STRING (
"air_part1_python2/幾何学4/Sum6" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0
} , { 65 , 7 , TARGET_STRING ( "air_part1_python2/空力1/MATLAB Function" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 66 , 7 , TARGET_STRING (
"air_part1_python2/空力1/MATLAB Function" ) , TARGET_STRING ( "" ) , 1 , 0 ,
0 , 0 , 0 } , { 67 , 7 , TARGET_STRING (
"air_part1_python2/空力1/MATLAB Function" ) , TARGET_STRING ( "" ) , 2 , 0 ,
0 , 0 , 0 } , { 68 , 8 , TARGET_STRING (
"air_part1_python2/空力1/MATLAB Function1" ) , TARGET_STRING ( "" ) , 0 , 0 ,
0 , 0 , 0 } , { 69 , 9 , TARGET_STRING (
"air_part1_python2/空力1/MATLAB Function2" ) , TARGET_STRING ( "" ) , 0 , 0 ,
0 , 0 , 0 } , { 70 , 10 , TARGET_STRING (
"air_part1_python2/空力1/MATLAB Function3" ) , TARGET_STRING ( "" ) , 0 , 0 ,
0 , 0 , 0 } , { 71 , 11 , TARGET_STRING (
"air_part1_python2/空力1/MATLAB Function4" ) , TARGET_STRING ( "" ) , 0 , 0 ,
0 , 0 , 0 } , { 72 , 0 , TARGET_STRING ( "air_part1_python2/空力1/Abs" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 73 , 0 , TARGET_STRING (
"air_part1_python2/空力1/Sum" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 }
, { 74 , 12 , TARGET_STRING ( "air_part1_python2/空力2/MATLAB Function" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 75 , 12 , TARGET_STRING (
"air_part1_python2/空力2/MATLAB Function" ) , TARGET_STRING ( "" ) , 1 , 0 ,
0 , 0 , 0 } , { 76 , 12 , TARGET_STRING (
"air_part1_python2/空力2/MATLAB Function" ) , TARGET_STRING ( "" ) , 2 , 0 ,
0 , 0 , 0 } , { 77 , 13 , TARGET_STRING (
"air_part1_python2/空力2/MATLAB Function1" ) , TARGET_STRING ( "" ) , 0 , 0 ,
0 , 0 , 0 } , { 78 , 14 , TARGET_STRING (
"air_part1_python2/空力2/MATLAB Function2" ) , TARGET_STRING ( "" ) , 0 , 0 ,
0 , 0 , 0 } , { 79 , 15 , TARGET_STRING (
"air_part1_python2/空力2/MATLAB Function3" ) , TARGET_STRING ( "" ) , 0 , 0 ,
0 , 0 , 0 } , { 80 , 16 , TARGET_STRING (
"air_part1_python2/空力2/MATLAB Function4" ) , TARGET_STRING ( "" ) , 0 , 0 ,
0 , 0 , 0 } , { 81 , 0 , TARGET_STRING ( "air_part1_python2/空力2/Abs" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 82 , 0 , TARGET_STRING (
"air_part1_python2/空力2/Sum" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 }
, { 83 , 18 , TARGET_STRING ( "air_part1_python2/空力3/MATLAB Function1" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 84 , 19 , TARGET_STRING (
"air_part1_python2/空力3/MATLAB Function2" ) , TARGET_STRING ( "" ) , 0 , 0 ,
0 , 0 , 0 } , { 85 , 20 , TARGET_STRING (
"air_part1_python2/空力3/MATLAB Function3" ) , TARGET_STRING ( "" ) , 0 , 0 ,
0 , 0 , 0 } , { 86 , 21 , TARGET_STRING (
"air_part1_python2/空力3/MATLAB Function4" ) , TARGET_STRING ( "" ) , 0 , 0 ,
0 , 0 , 0 } , { 87 , 0 , TARGET_STRING ( "air_part1_python2/空力3/Abs" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 88 , 0 , TARGET_STRING (
"air_part1_python2/空力3/Sum" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 }
, { 89 , 22 , TARGET_STRING ( "air_part1_python2/空力4/MATLAB Function" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 90 , 22 , TARGET_STRING (
"air_part1_python2/空力4/MATLAB Function" ) , TARGET_STRING ( "" ) , 1 , 0 ,
0 , 0 , 0 } , { 91 , 22 , TARGET_STRING (
"air_part1_python2/空力4/MATLAB Function" ) , TARGET_STRING ( "" ) , 2 , 0 ,
0 , 0 , 0 } , { 92 , 23 , TARGET_STRING (
"air_part1_python2/空力4/MATLAB Function1" ) , TARGET_STRING ( "" ) , 0 , 0 ,
0 , 0 , 0 } , { 93 , 24 , TARGET_STRING (
"air_part1_python2/空力4/MATLAB Function2" ) , TARGET_STRING ( "" ) , 0 , 0 ,
0 , 0 , 0 } , { 94 , 25 , TARGET_STRING (
"air_part1_python2/空力4/MATLAB Function3" ) , TARGET_STRING ( "" ) , 0 , 0 ,
0 , 0 , 0 } , { 95 , 26 , TARGET_STRING (
"air_part1_python2/空力4/MATLAB Function4" ) , TARGET_STRING ( "" ) , 0 , 0 ,
0 , 0 , 0 } , { 96 , 0 , TARGET_STRING ( "air_part1_python2/空力4/Abs" ) ,
TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 } , { 97 , 0 , TARGET_STRING (
"air_part1_python2/空力4/Sum" ) , TARGET_STRING ( "" ) , 0 , 0 , 0 , 0 , 0 }
, { 98 , 0 , TARGET_STRING (
"air_part1_python2/Counter Free-Running/Wrap To Zero/FixPt Switch" ) ,
TARGET_STRING ( "" ) , 0 , 2 , 0 , 1 , 3 } , { 0 , 0 , ( NULL ) , ( NULL ) ,
0 , 0 , 0 , 0 , 0 } } ; static const rtwCAPI_BlockParameters
rtBlockParameters [ ] = { { 99 , TARGET_STRING (
"air_part1_python2/Band-Limited White Noise" ) , TARGET_STRING ( "seed" ) , 0
, 0 , 0 } , { 100 , TARGET_STRING (
"air_part1_python2/Band-Limited White Noise1" ) , TARGET_STRING ( "seed" ) ,
0 , 0 , 0 } , { 101 , TARGET_STRING ( "air_part1_python2/PWM" ) ,
TARGET_STRING ( "Period" ) , 0 , 0 , 0 } , { 102 , TARGET_STRING (
"air_part1_python2/PWM1" ) , TARGET_STRING ( "Period" ) , 0 , 0 , 0 } , { 103
, TARGET_STRING ( "air_part1_python2/a" ) , TARGET_STRING ( "Value" ) , 0 , 0
, 0 } , { 104 , TARGET_STRING ( "air_part1_python2/a1" ) , TARGET_STRING (
"Value" ) , 0 , 0 , 0 } , { 105 , TARGET_STRING ( "air_part1_python2/a2" ) ,
TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 106 , TARGET_STRING (
"air_part1_python2/a3" ) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 107 ,
TARGET_STRING ( "air_part1_python2/a4" ) , TARGET_STRING ( "Value" ) , 0 , 0
, 0 } , { 108 , TARGET_STRING ( "air_part1_python2/a5" ) , TARGET_STRING (
"Value" ) , 0 , 0 , 0 } , { 109 , TARGET_STRING ( "air_part1_python2/a6" ) ,
TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 110 , TARGET_STRING (
"air_part1_python2/a7" ) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 111 ,
TARGET_STRING ( "air_part1_python2/b" ) , TARGET_STRING ( "Value" ) , 0 , 0 ,
0 } , { 112 , TARGET_STRING ( "air_part1_python2/c" ) , TARGET_STRING (
"Value" ) , 0 , 0 , 0 } , { 113 , TARGET_STRING (
"air_part1_python2/constant" ) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , {
114 , TARGET_STRING ( "air_part1_python2/constant1" ) , TARGET_STRING (
"Value" ) , 0 , 0 , 0 } , { 115 , TARGET_STRING (
"air_part1_python2/constant2" ) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , {
116 , TARGET_STRING ( "air_part1_python2/constant3" ) , TARGET_STRING (
"Value" ) , 0 , 0 , 0 } , { 117 , TARGET_STRING ( "air_part1_python2/d" ) ,
TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 118 , TARGET_STRING (
"air_part1_python2/e" ) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 119 ,
TARGET_STRING ( "air_part1_python2/timestep" ) , TARGET_STRING ( "Value" ) ,
0 , 0 , 0 } , { 120 , TARGET_STRING ( "air_part1_python2/timestep1" ) ,
TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 121 , TARGET_STRING (
"air_part1_python2/timestep2" ) , TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , {
122 , TARGET_STRING ( "air_part1_python2/timestep3" ) , TARGET_STRING (
"Value" ) , 0 , 0 , 0 } , { 123 , TARGET_STRING (
"air_part1_python2/慣性モーメント" ) , TARGET_STRING ( "Value" ) , 0 , 0 , 0
} , { 124 , TARGET_STRING ( "air_part1_python2/負荷トルク(Ncm)" ) ,
TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 125 , TARGET_STRING (
"air_part1_python2/負荷トルク(Ncm)1" ) , TARGET_STRING ( "Value" ) , 0 , 0 ,
0 } , { 126 , TARGET_STRING ( "air_part1_python2/電圧" ) , TARGET_STRING (
"Value" ) , 0 , 0 , 0 } , { 127 , TARGET_STRING ( "air_part1_python2/5" ) ,
TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 128 , TARGET_STRING (
"air_part1_python2/Gain" ) , TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 129 ,
TARGET_STRING ( "air_part1_python2/Gain1" ) , TARGET_STRING ( "Gain" ) , 0 ,
0 , 0 } , { 130 , TARGET_STRING ( "air_part1_python2/ギア比" ) ,
TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 131 , TARGET_STRING (
"air_part1_python2/ギア比1" ) , TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , {
132 , TARGET_STRING ( "air_part1_python2/ギア比2" ) , TARGET_STRING ( "Gain"
) , 0 , 0 , 0 } , { 133 , TARGET_STRING ( "air_part1_python2/ギア比3" ) ,
TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 134 , TARGET_STRING (
"air_part1_python2/ギア比4" ) , TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , {
135 , TARGET_STRING ( "air_part1_python2/ギア比5" ) , TARGET_STRING ( "Gain"
) , 0 , 0 , 0 } , { 136 , TARGET_STRING ( "air_part1_python2/モーメント" ) ,
TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 137 , TARGET_STRING (
"air_part1_python2/モーメント1" ) , TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } ,
{ 138 , TARGET_STRING ( "air_part1_python2/モーメント2" ) , TARGET_STRING (
"Gain" ) , 0 , 0 , 0 } , { 139 , TARGET_STRING (
"air_part1_python2/モーメント3" ) , TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } ,
{ 140 , TARGET_STRING ( "air_part1_python2/変換2" ) , TARGET_STRING ( "Gain"
) , 0 , 0 , 0 } , { 141 , TARGET_STRING ( "air_part1_python2/変換3" ) ,
TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 142 , TARGET_STRING (
"air_part1_python2/変換4" ) , TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 143
, TARGET_STRING ( "air_part1_python2/変換5" ) , TARGET_STRING ( "Gain" ) , 0
, 0 , 0 } , { 144 , TARGET_STRING ( "air_part1_python2/変換6" ) ,
TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 145 , TARGET_STRING (
"air_part1_python2/変換7" ) , TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 146
, TARGET_STRING ( "air_part1_python2/空気抵抗" ) , TARGET_STRING ( "Gain" ) ,
0 , 0 , 0 } , { 147 , TARGET_STRING ( "air_part1_python2/Integrator" ) ,
TARGET_STRING ( "InitialCondition" ) , 0 , 0 , 0 } , { 148 , TARGET_STRING (
"air_part1_python2/Integrator1" ) , TARGET_STRING ( "InitialCondition" ) , 0
, 0 , 0 } , { 149 , TARGET_STRING ( "air_part1_python2/Integrator2" ) ,
TARGET_STRING ( "InitialCondition" ) , 0 , 0 , 0 } , { 150 , TARGET_STRING (
"air_part1_python2/Integrator3" ) , TARGET_STRING ( "InitialCondition" ) , 0
, 0 , 0 } , { 151 , TARGET_STRING ( "air_part1_python2/ASCII Decode" ) ,
TARGET_STRING ( "P1" ) , 0 , 4 , 0 } , { 152 , TARGET_STRING (
"air_part1_python2/ASCII Decode" ) , TARGET_STRING ( "P2" ) , 0 , 0 , 0 } , {
153 , TARGET_STRING ( "air_part1_python2/ASCII Decode" ) , TARGET_STRING (
"P3" ) , 0 , 0 , 0 } , { 154 , TARGET_STRING (
"air_part1_python2/ASCII Decode1" ) , TARGET_STRING ( "P1" ) , 0 , 4 , 0 } ,
{ 155 , TARGET_STRING ( "air_part1_python2/ASCII Decode1" ) , TARGET_STRING (
"P2" ) , 0 , 0 , 0 } , { 156 , TARGET_STRING (
"air_part1_python2/ASCII Decode1" ) , TARGET_STRING ( "P3" ) , 0 , 0 , 0 } ,
{ 157 , TARGET_STRING ( "air_part1_python2/ASCII Decode2" ) , TARGET_STRING (
"P1" ) , 0 , 4 , 0 } , { 158 , TARGET_STRING (
"air_part1_python2/ASCII Decode2" ) , TARGET_STRING ( "P2" ) , 0 , 0 , 0 } ,
{ 159 , TARGET_STRING ( "air_part1_python2/ASCII Decode2" ) , TARGET_STRING (
"P3" ) , 0 , 0 , 0 } , { 160 , TARGET_STRING (
"air_part1_python2/ASCII Decode3" ) , TARGET_STRING ( "P1" ) , 0 , 4 , 0 } ,
{ 161 , TARGET_STRING ( "air_part1_python2/ASCII Decode3" ) , TARGET_STRING (
"P2" ) , 0 , 0 , 0 } , { 162 , TARGET_STRING (
"air_part1_python2/ASCII Decode3" ) , TARGET_STRING ( "P3" ) , 0 , 0 , 0 } ,
{ 163 , TARGET_STRING ( "air_part1_python2/ASCII Decode4" ) , TARGET_STRING (
"P1" ) , 0 , 4 , 0 } , { 164 , TARGET_STRING (
"air_part1_python2/ASCII Decode4" ) , TARGET_STRING ( "P2" ) , 0 , 0 , 0 } ,
{ 165 , TARGET_STRING ( "air_part1_python2/ASCII Decode4" ) , TARGET_STRING (
"P3" ) , 0 , 0 , 0 } , { 166 , TARGET_STRING (
"air_part1_python2/ASCII Decode5" ) , TARGET_STRING ( "P1" ) , 0 , 4 , 0 } ,
{ 167 , TARGET_STRING ( "air_part1_python2/ASCII Decode5" ) , TARGET_STRING (
"P2" ) , 0 , 0 , 0 } , { 168 , TARGET_STRING (
"air_part1_python2/ASCII Decode5" ) , TARGET_STRING ( "P3" ) , 0 , 0 , 0 } ,
{ 169 , TARGET_STRING ( "air_part1_python2/ASCII Encode" ) , TARGET_STRING (
"P1" ) , 0 , 5 , 0 } , { 170 , TARGET_STRING (
"air_part1_python2/ASCII Encode" ) , TARGET_STRING ( "P2" ) , 0 , 0 , 0 } , {
171 , TARGET_STRING ( "air_part1_python2/ASCII Encode" ) , TARGET_STRING (
"P3" ) , 0 , 0 , 0 } , { 172 , TARGET_STRING (
"air_part1_python2/ASCII Encode" ) , TARGET_STRING ( "P4" ) , 0 , 0 , 0 } , {
173 , TARGET_STRING ( "air_part1_python2/ASCII Encode1" ) , TARGET_STRING (
"P1" ) , 0 , 5 , 0 } , { 174 , TARGET_STRING (
"air_part1_python2/ASCII Encode1" ) , TARGET_STRING ( "P2" ) , 0 , 0 , 0 } ,
{ 175 , TARGET_STRING ( "air_part1_python2/ASCII Encode1" ) , TARGET_STRING (
"P3" ) , 0 , 0 , 0 } , { 176 , TARGET_STRING (
"air_part1_python2/ASCII Encode1" ) , TARGET_STRING ( "P4" ) , 0 , 0 , 0 } ,
{ 177 , TARGET_STRING ( "air_part1_python2/Switch" ) , TARGET_STRING (
"Threshold" ) , 0 , 0 , 0 } , { 178 , TARGET_STRING (
"air_part1_python2/Switch1" ) , TARGET_STRING ( "Threshold" ) , 0 , 0 , 0 } ,
{ 179 , TARGET_STRING ( "air_part1_python2/Switch2" ) , TARGET_STRING (
"Threshold" ) , 0 , 0 , 0 } , { 180 , TARGET_STRING (
"air_part1_python2/Switch3" ) , TARGET_STRING ( "Threshold" ) , 0 , 0 , 0 } ,
{ 181 , TARGET_STRING ( "air_part1_python2/Variable Time Delay" ) ,
TARGET_STRING ( "MaximumDelay" ) , 0 , 0 , 0 } , { 182 , TARGET_STRING (
"air_part1_python2/Variable Time Delay" ) , TARGET_STRING ( "InitialOutput" )
, 0 , 0 , 0 } , { 183 , TARGET_STRING (
"air_part1_python2/Variable Time Delay1" ) , TARGET_STRING ( "MaximumDelay" )
, 0 , 0 , 0 } , { 184 , TARGET_STRING (
"air_part1_python2/Variable Time Delay1" ) , TARGET_STRING ( "InitialOutput"
) , 0 , 0 , 0 } , { 185 , TARGET_STRING (
"air_part1_python2/Band-Limited White Noise/Output" ) , TARGET_STRING (
"Gain" ) , 0 , 0 , 0 } , { 186 , TARGET_STRING (
"air_part1_python2/Band-Limited White Noise/White Noise" ) , TARGET_STRING (
"Mean" ) , 0 , 0 , 0 } , { 187 , TARGET_STRING (
"air_part1_python2/Band-Limited White Noise/White Noise" ) , TARGET_STRING (
"StdDev" ) , 0 , 0 , 0 } , { 188 , TARGET_STRING (
"air_part1_python2/Band-Limited White Noise1/Output" ) , TARGET_STRING (
"Gain" ) , 0 , 0 , 0 } , { 189 , TARGET_STRING (
"air_part1_python2/Band-Limited White Noise1/White Noise" ) , TARGET_STRING (
"Mean" ) , 0 , 0 , 0 } , { 190 , TARGET_STRING (
"air_part1_python2/Band-Limited White Noise1/White Noise" ) , TARGET_STRING (
"StdDev" ) , 0 , 0 , 0 } , { 191 , TARGET_STRING (
"air_part1_python2/Counter Free-Running/Wrap To Zero" ) , TARGET_STRING (
"Threshold" ) , 2 , 0 , 1 } , { 192 , TARGET_STRING (
"air_part1_python2/Counter Free-Running/Output" ) , TARGET_STRING (
"InitialCondition" ) , 2 , 0 , 1 } , { 193 , TARGET_STRING (
"air_part1_python2/モーター/インダクタンス" ) , TARGET_STRING ( "Value" ) , 0
, 0 , 0 } , { 194 , TARGET_STRING (
"air_part1_python2/モーター/慣性モーメント" ) , TARGET_STRING ( "Value" ) , 0
, 0 , 0 } , { 195 , TARGET_STRING ( "air_part1_python2/モーター/トルク定数" )
, TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 196 , TARGET_STRING (
"air_part1_python2/モーター/トルク定数1" ) , TARGET_STRING ( "Gain" ) , 0 , 0
, 0 } , { 197 , TARGET_STRING ( "air_part1_python2/モーター/抵抗" ) ,
TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 198 , TARGET_STRING (
"air_part1_python2/モーター/粘性減衰係数" ) , TARGET_STRING ( "Gain" ) , 0 ,
0 , 0 } , { 199 , TARGET_STRING ( "air_part1_python2/モーター/逆気電圧係数" )
, TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 200 , TARGET_STRING (
"air_part1_python2/モーター/Integrator" ) , TARGET_STRING (
"InitialCondition" ) , 0 , 0 , 0 } , { 201 , TARGET_STRING (
"air_part1_python2/モーター/Integrator1" ) , TARGET_STRING (
"InitialCondition" ) , 0 , 0 , 0 } , { 202 , TARGET_STRING (
"air_part1_python2/モーター1/インダクタンス" ) , TARGET_STRING ( "Value" ) ,
0 , 0 , 0 } , { 203 , TARGET_STRING (
"air_part1_python2/モーター1/慣性モーメント" ) , TARGET_STRING ( "Value" ) ,
0 , 0 , 0 } , { 204 , TARGET_STRING (
"air_part1_python2/モーター1/トルク定数" ) , TARGET_STRING ( "Gain" ) , 0 , 0
, 0 } , { 205 , TARGET_STRING ( "air_part1_python2/モーター1/トルク定数1" ) ,
TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 206 , TARGET_STRING (
"air_part1_python2/モーター1/抵抗" ) , TARGET_STRING ( "Gain" ) , 0 , 0 , 0 }
, { 207 , TARGET_STRING ( "air_part1_python2/モーター1/粘性減衰係数" ) ,
TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 208 , TARGET_STRING (
"air_part1_python2/モーター1/逆気電圧係数" ) , TARGET_STRING ( "Gain" ) , 0 ,
0 , 0 } , { 209 , TARGET_STRING ( "air_part1_python2/モーター1/Integrator" )
, TARGET_STRING ( "InitialCondition" ) , 0 , 0 , 0 } , { 210 , TARGET_STRING
( "air_part1_python2/モーター1/Integrator1" ) , TARGET_STRING (
"InitialCondition" ) , 0 , 0 , 0 } , { 211 , TARGET_STRING (
"air_part1_python2/幾何学1/constant3" ) , TARGET_STRING ( "Value" ) , 0 , 0 ,
0 } , { 212 , TARGET_STRING ( "air_part1_python2/幾何学1/単位変換2" ) ,
TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 213 , TARGET_STRING (
"air_part1_python2/幾何学2/constant3" ) , TARGET_STRING ( "Value" ) , 0 , 0 ,
0 } , { 214 , TARGET_STRING ( "air_part1_python2/幾何学2/単位変換2" ) ,
TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 215 , TARGET_STRING (
"air_part1_python2/幾何学3/constant3" ) , TARGET_STRING ( "Value" ) , 0 , 0 ,
0 } , { 216 , TARGET_STRING ( "air_part1_python2/幾何学3/単位変換2" ) ,
TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 217 , TARGET_STRING (
"air_part1_python2/幾何学4/constant3" ) , TARGET_STRING ( "Value" ) , 0 , 0 ,
0 } , { 218 , TARGET_STRING ( "air_part1_python2/幾何学4/単位変換2" ) ,
TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 219 , TARGET_STRING (
"air_part1_python2/空力1/Constant" ) , TARGET_STRING ( "Value" ) , 0 , 0 , 0
} , { 220 , TARGET_STRING ( "air_part1_python2/空力1/Constant1" ) ,
TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 221 , TARGET_STRING (
"air_part1_python2/空力1/close_AOA(degree)" ) , TARGET_STRING ( "Value" ) , 0
, 0 , 0 } , { 222 , TARGET_STRING (
"air_part1_python2/空力1/open_AOA(degree)" ) , TARGET_STRING ( "Value" ) , 0
, 0 , 0 } , { 223 , TARGET_STRING ( "air_part1_python2/空力1/Gain" ) ,
TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 224 , TARGET_STRING (
"air_part1_python2/空力1/Saturation" ) , TARGET_STRING ( "UpperLimit" ) , 0 ,
0 , 0 } , { 225 , TARGET_STRING ( "air_part1_python2/空力1/Saturation" ) ,
TARGET_STRING ( "LowerLimit" ) , 0 , 0 , 0 } , { 226 , TARGET_STRING (
"air_part1_python2/空力2/Constant" ) , TARGET_STRING ( "Value" ) , 0 , 0 , 0
} , { 227 , TARGET_STRING ( "air_part1_python2/空力2/Constant1" ) ,
TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 228 , TARGET_STRING (
"air_part1_python2/空力2/close_AOA(degree)" ) , TARGET_STRING ( "Value" ) , 0
, 0 , 0 } , { 229 , TARGET_STRING (
"air_part1_python2/空力2/open_AOA(degree)" ) , TARGET_STRING ( "Value" ) , 0
, 0 , 0 } , { 230 , TARGET_STRING ( "air_part1_python2/空力2/Gain" ) ,
TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 231 , TARGET_STRING (
"air_part1_python2/空力2/Saturation" ) , TARGET_STRING ( "UpperLimit" ) , 0 ,
0 , 0 } , { 232 , TARGET_STRING ( "air_part1_python2/空力2/Saturation" ) ,
TARGET_STRING ( "LowerLimit" ) , 0 , 0 , 0 } , { 233 , TARGET_STRING (
"air_part1_python2/空力3/Constant" ) , TARGET_STRING ( "Value" ) , 0 , 0 , 0
} , { 234 , TARGET_STRING ( "air_part1_python2/空力3/Constant1" ) ,
TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 235 , TARGET_STRING (
"air_part1_python2/空力3/close_AOA(degree)" ) , TARGET_STRING ( "Value" ) , 0
, 0 , 0 } , { 236 , TARGET_STRING (
"air_part1_python2/空力3/open_AOA(degree)" ) , TARGET_STRING ( "Value" ) , 0
, 0 , 0 } , { 237 , TARGET_STRING ( "air_part1_python2/空力3/Gain" ) ,
TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 238 , TARGET_STRING (
"air_part1_python2/空力4/Constant" ) , TARGET_STRING ( "Value" ) , 0 , 0 , 0
} , { 239 , TARGET_STRING ( "air_part1_python2/空力4/Constant1" ) ,
TARGET_STRING ( "Value" ) , 0 , 0 , 0 } , { 240 , TARGET_STRING (
"air_part1_python2/空力4/close_AOA(degree)" ) , TARGET_STRING ( "Value" ) , 0
, 0 , 0 } , { 241 , TARGET_STRING (
"air_part1_python2/空力4/open_AOA(degree)" ) , TARGET_STRING ( "Value" ) , 0
, 0 , 0 } , { 242 , TARGET_STRING ( "air_part1_python2/空力4/Gain" ) ,
TARGET_STRING ( "Gain" ) , 0 , 0 , 0 } , { 243 , TARGET_STRING (
"air_part1_python2/空力4/Saturation" ) , TARGET_STRING ( "UpperLimit" ) , 0 ,
0 , 0 } , { 244 , TARGET_STRING ( "air_part1_python2/空力4/Saturation" ) ,
TARGET_STRING ( "LowerLimit" ) , 0 , 0 , 0 } , { 245 , TARGET_STRING (
"air_part1_python2/Counter Free-Running/Increment Real World/FixPt Constant"
) , TARGET_STRING ( "Value" ) , 2 , 0 , 1 } , { 246 , TARGET_STRING (
"air_part1_python2/Counter Free-Running/Wrap To Zero/Constant" ) ,
TARGET_STRING ( "Value" ) , 2 , 0 , 1 } , { 0 , ( NULL ) , ( NULL ) , 0 , 0 ,
0 } } ; static int_T rt_LoggedStateIdxList [ ] = { - 1 } ; static const
rtwCAPI_Signals rtRootInputs [ ] = { { 0 , 0 , ( NULL ) , ( NULL ) , 0 , 0 ,
0 , 0 , 0 } } ; static const rtwCAPI_Signals rtRootOutputs [ ] = { { 0 , 0 ,
( NULL ) , ( NULL ) , 0 , 0 , 0 , 0 , 0 } } ; static const
rtwCAPI_ModelParameters rtModelParameters [ ] = { { 0 , ( NULL ) , 0 , 0 , 0
} } ;
#ifndef HOST_CAPI_BUILD
static void * rtDataAddrMap [ ] = { & rtB . firups0wj2 , & rtB . gg1qdr0ca0 ,
& rtB . hhfhv1g453 , & rtB . buugn1y4kg , & rtB . a3plauwk5y , & rtB .
n0yzexgdyh , & rtB . atbvn2nrjn , & rtB . nzqgm2nb3k , & rtB . iewiqnu5gm , &
rtB . lonvbzqzr1 , & rtB . jqaxfynhz3 , & rtB . oqvlx0tggb , & rtB .
klwp3o5znj , & rtB . bkayq3jpfr , & rtB . arjieh1qz2 , & rtB . b0atyboa0x , &
rtB . ov41nszkfe , & rtB . ff3s1fh5wh , & rtB . crmbrbsz2x , & rtB .
hjr01anyo4 [ 0 ] , & rtB . f3ybeuoetm [ 0 ] , & rtB . iar4fhawbp [ 0 ] , &
rtB . ixgganvvtz , & rtB . ktsgdw2c41 , & rtB . mimixuazso , & rtB .
jbdewy33ag , & rtB . jyujvnq2h1 , & rtB . kmzeugzpgl , & rtB . mfao3xhxn3 , &
rtB . be3gvejel2 , & rtB . exrmi0ldfj , & rtB . bwgs3crvzk , & rtB .
a405zozv5t , & rtB . mjlpzkqz1n , & rtB . gyqrec4ceq , & rtB . fn1r3pr3py , &
rtB . hyhxikiti2 , & rtB . omvc30ouxs , & rtB . m0wxbflasp , & rtB .
pdvh3wfivp , & rtB . lpstap4ud2 [ 0 ] , & rtB . n4zpljasue , & rtB .
ipbondrkcl , & rtB . d3mqkoc1ln , & rtB . m0fvlyj223 , & rtB . mnvxcylwkr , &
rtB . pgeeu4rvpl , & rtB . facwgsdsd1 , & rtB . aeq3t23mz4 , & rtB .
fywlqxnu4j , & rtB . ojl1qzu4tl . a0dacr3vu5 , & rtB . ojl1qzu4tl .
dxojvg2mzp , & rtB . ojl1qzu4tl . ftth4nxmgz , & rtB . ojl1qzu4tl .
d0v1fgzgtc , & rtB . a43mlssova , & rtB . etvoly05ch , & rtB . btyuoi1co3 .
a0dacr3vu5 , & rtB . btyuoi1co3 . dxojvg2mzp , & rtB . btyuoi1co3 .
ftth4nxmgz , & rtB . btyuoi1co3 . d0v1fgzgtc , & rtB . k2tv1y1gn5 , & rtB .
gkuq4mb5x4 , & rtB . mqpvdapacf , & rtB . ku0cdrtwff , & rtB . e4k3uwbbqo , &
rtB . fvmfewdhwz . etkpdfh3bw , & rtB . fvmfewdhwz . hogtdrsbl0 , & rtB .
fvmfewdhwz . ayo4a0rtpb , & rtB . c5fiym5p0p . fsek3luzie , & rtB .
ixdl5r0pbu . jb2b5najpv , & rtB . p4ublk43y4 , & rtB . jsqwvo4npa .
n5nj1b05gf , & rtB . htcqv5fxtd , & rtB . ha2jxgqr02 , & rtB . fisn2ndewy .
etkpdfh3bw , & rtB . fisn2ndewy . hogtdrsbl0 , & rtB . fisn2ndewy .
ayo4a0rtpb , & rtB . dwjvl3kmbe . fsek3luzie , & rtB . ch5un3rjrb .
nf3awaueuw , & rtB . dgjrsvf3r0 . o5vabvlgjn , & rtB . jdelhdqjdy .
n5nj1b05gf , & rtB . bzfi1eqihy , & rtB . goi1oiwwan , & rtB . p2tfl52njg .
fsek3luzie , & rtB . aelnqmel4f . jb2b5najpv , & rtB . c1l0t1ppoz , & rtB .
hwhgormc0n . n5nj1b05gf , & rtB . itbqmhqgrz , & rtB . frqdqeq5gg , & rtB .
f2cxkdl2mb . etkpdfh3bw , & rtB . f2cxkdl2mb . hogtdrsbl0 , & rtB .
f2cxkdl2mb . ayo4a0rtpb , & rtB . c21bk5qnit . fsek3luzie , & rtB .
eoqlazxz1z . nf3awaueuw , & rtB . elpvuejile . o5vabvlgjn , & rtB .
ktoqcjl1wu . n5nj1b05gf , & rtB . i54d4oicep , & rtB . oj1fmvrj3c , & rtB .
otnxjer3d0 , & rtP . BandLimitedWhiteNoise_seed , & rtP .
BandLimitedWhiteNoise1_seed , & rtP . PWM_Period , & rtP . PWM1_Period , &
rtP . a_Value , & rtP . a1_Value , & rtP . a2_Value , & rtP . a3_Value , &
rtP . a4_Value , & rtP . a5_Value , & rtP . a6_Value , & rtP . a7_Value , &
rtP . b_Value , & rtP . c_Value , & rtP . constant_Value , & rtP .
constant1_Value , & rtP . constant2_Value , & rtP . constant3_Value , & rtP .
d_Value , & rtP . e_Value , & rtP . timestep_Value , & rtP . timestep1_Value
, & rtP . timestep2_Value , & rtP . timestep3_Value , & rtP .
Value_mdbqjrgdok , & rtP . Ncm_Value , & rtP . Ncm1_Value , & rtP .
_Value_ihbzrbcjcd , & rtP . u_Gain_b4npwylgl1 , & rtP . Gain_Gain_iih4ui3cnf
, & rtP . Gain1_Gain , & rtP . Gain , & rtP . _Gain , & rtP .
_Gain_ezpdmdm44b , & rtP . _Gain_dq53dumoid , & rtP . _Gain_a2p4tfbpm4 , &
rtP . _Gain_iaiof1ych2 , & rtP . Gain_o44e2s1oov , & rtP . _Gain_jqvyrpyhlw ,
& rtP . _Gain_igqv4gz3am , & rtP . _Gain_ocd1v2y2wv , & rtP .
u_Gain_nudgobpj1r , & rtP . u_Gain_mdaasjyeq0 , & rtP . u_Gain_i3zbnwm4y2 , &
rtP . u_Gain_pqq0pxqop5 , & rtP . u_Gain_m2whdurejq , & rtP .
u_Gain_iw0b3pebia , & rtP . Gain_dcquyu5zec , & rtP .
Integrator_IC_edh1bx55d3 , & rtP . Integrator1_IC_aul1jddy20 , & rtP .
Integrator2_IC , & rtP . Integrator3_IC , & rtP . ASCIIDecode_P1 [ 0 ] , &
rtP . ASCIIDecode_P2 , & rtP . ASCIIDecode_P3 , & rtP . ASCIIDecode1_P1 [ 0 ]
, & rtP . ASCIIDecode1_P2 , & rtP . ASCIIDecode1_P3 , & rtP . ASCIIDecode2_P1
[ 0 ] , & rtP . ASCIIDecode2_P2 , & rtP . ASCIIDecode2_P3 , & rtP .
ASCIIDecode3_P1 [ 0 ] , & rtP . ASCIIDecode3_P2 , & rtP . ASCIIDecode3_P3 , &
rtP . ASCIIDecode4_P1 [ 0 ] , & rtP . ASCIIDecode4_P2 , & rtP .
ASCIIDecode4_P3 , & rtP . ASCIIDecode5_P1 [ 0 ] , & rtP . ASCIIDecode5_P2 , &
rtP . ASCIIDecode5_P3 , & rtP . ASCIIEncode_P1 [ 0 ] , & rtP . ASCIIEncode_P2
, & rtP . ASCIIEncode_P3 , & rtP . ASCIIEncode_P4 , & rtP . ASCIIEncode1_P1 [
0 ] , & rtP . ASCIIEncode1_P2 , & rtP . ASCIIEncode1_P3 , & rtP .
ASCIIEncode1_P4 , & rtP . Switch_Threshold , & rtP . Switch1_Threshold , &
rtP . Switch2_Threshold , & rtP . Switch3_Threshold , & rtP .
VariableTimeDelay_MaxDelay , & rtP . VariableTimeDelay_InitOutput , & rtP .
VariableTimeDelay1_MaxDelay , & rtP . VariableTimeDelay1_InitOutput , & rtP .
Output_Gain_kseoije4vl , & rtP . WhiteNoise_Mean_cm2ydxtnvw , & rtP .
WhiteNoise_StdDev_iarpuhegie , & rtP . Output_Gain , & rtP . WhiteNoise_Mean
, & rtP . WhiteNoise_StdDev , & rtP . WrapToZero_Threshold , & rtP .
Output_InitialCondition , & rtP . _Value , & rtP . Value , & rtP .
_Gain_fl03d5u1kp , & rtP . u_Gain_gp00rtkqtb , & rtP . Gain_c5zyi33wrb , &
rtP . _Gain_ec3r4dr3zn , & rtP . _Gain_nwjfwxlfng , & rtP . Integrator_IC , &
rtP . Integrator1_IC , & rtP . _Value_fcrkhd1pwn , & rtP . Value_dfptlknwpi ,
& rtP . _Gain_lcqhixjq0z , & rtP . u_Gain_jngffoyzbc , & rtP .
Gain_jvjms1w3ad , & rtP . _Gain_ni4xvt1vxz , & rtP . _Gain_ex1r0c12fd , & rtP
. Integrator_IC_ltzbm21qdw , & rtP . Integrator1_IC_p55ptnmnhu , & rtP .
constant3_Value_d4zn1mb3f1 , & rtP . u_Gain_lklkiehjn3 , & rtP .
constant3_Value_gdybbqcsvv , & rtP . u_Gain_pcqi2zh5ks , & rtP .
constant3_Value_e1gwiy1pb3 , & rtP . u_Gain , & rtP .
constant3_Value_bufvhyvmaf , & rtP . u_Gain_fqvbril3va , & rtP .
Constant_Value , & rtP . Constant1_Value , & rtP . close_AOAdegree_Value , &
rtP . open_AOAdegree_Value , & rtP . Gain_Gain_oodfwwlgw5 , & rtP .
Saturation_UpperSat_gxwe5io0f4 , & rtP . Saturation_LowerSat_ggci1m3fwr , &
rtP . Constant_Value_ndti5ul2ir , & rtP . Constant1_Value_gwfubws50w , & rtP
. close_AOAdegree_Value_h2ko2tzd3h , & rtP . open_AOAdegree_Value_puyaicdqcr
, & rtP . Gain_Gain_gqjpcqg2pu , & rtP . Saturation_UpperSat_nctbwbdtp3 , &
rtP . Saturation_LowerSat_khkejnf40e , & rtP . Constant_Value_iq4hlvezb4 , &
rtP . Constant1_Value_bfs2kyqhyj , & rtP . close_AOAdegree_Value_crud0nlfli ,
& rtP . open_AOAdegree_Value_bru0w4josw , & rtP . Gain_Gain , & rtP .
Constant_Value_dbb4dojqmp , & rtP . Constant1_Value_fqnw4iunxo , & rtP .
close_AOAdegree_Value_mqej5anoke , & rtP . open_AOAdegree_Value_a135evdloz ,
& rtP . Gain_Gain_an1pdnuefr , & rtP . Saturation_UpperSat , & rtP .
Saturation_LowerSat , & rtP . FixPtConstant_Value , & rtP .
Constant_Value_dsvukcvkuu , } ; static int32_T * rtVarDimsAddrMap [ ] = { (
NULL ) } ;
#endif
static TARGET_CONST rtwCAPI_DataTypeMap rtDataTypeMap [ ] = { { "double" ,
"real_T" , 0 , 0 , sizeof ( real_T ) , ( uint8_T ) SS_DOUBLE , 0 , 0 , 0 } ,
{ "unsigned char" , "uint8_T" , 0 , 0 , sizeof ( uint8_T ) , ( uint8_T )
SS_UINT8 , 0 , 0 , 0 } , { "unsigned int" , "uint32_T" , 0 , 0 , sizeof (
uint32_T ) , ( uint8_T ) SS_UINT32 , 0 , 0 , 0 } } ;
#ifdef HOST_CAPI_BUILD
#undef sizeof
#endif
static TARGET_CONST rtwCAPI_ElementMap rtElementMap [ ] = { { ( NULL ) , 0 ,
0 , 0 , 0 } , } ; static const rtwCAPI_DimensionMap rtDimensionMap [ ] = { {
rtwCAPI_SCALAR , 0 , 2 , 0 } , { rtwCAPI_VECTOR , 2 , 2 , 0 } , {
rtwCAPI_VECTOR , 4 , 2 , 0 } , { rtwCAPI_MATRIX_COL_MAJOR , 6 , 2 , 0 } , {
rtwCAPI_VECTOR , 8 , 2 , 0 } , { rtwCAPI_VECTOR , 10 , 2 , 0 } } ; static
const uint_T rtDimensionArray [ ] = { 1 , 1 , 128 , 1 , 256 , 1 , 6 , 1 , 1 ,
3 , 1 , 4 } ; static const real_T rtcapiStoredFloats [ ] = { 0.0 , 0.05 ,
0.04 , 5.0E-5 , 1.0 } ; static const rtwCAPI_FixPtMap rtFixPtMap [ ] = { { (
NULL ) , ( NULL ) , rtwCAPI_FIX_RESERVED , 0 , 0 , ( boolean_T ) 0 } , { (
const void * ) & rtcapiStoredFloats [ 4 ] , ( const void * ) &
rtcapiStoredFloats [ 0 ] , rtwCAPI_FIX_UNIFORM_SCALING , 20 , 0 , ( boolean_T
) 0 } } ; static const rtwCAPI_SampleTimeMap rtSampleTimeMap [ ] = { { (
const void * ) & rtcapiStoredFloats [ 0 ] , ( const void * ) &
rtcapiStoredFloats [ 0 ] , ( int8_T ) 0 , ( uint8_T ) 0 } , { ( const void *
) & rtcapiStoredFloats [ 1 ] , ( const void * ) & rtcapiStoredFloats [ 0 ] ,
( int8_T ) 3 , ( uint8_T ) 0 } , { ( const void * ) & rtcapiStoredFloats [ 2
] , ( const void * ) & rtcapiStoredFloats [ 0 ] , ( int8_T ) 2 , ( uint8_T )
0 } , { ( const void * ) & rtcapiStoredFloats [ 3 ] , ( const void * ) &
rtcapiStoredFloats [ 0 ] , ( int8_T ) 1 , ( uint8_T ) 0 } } ; static
rtwCAPI_ModelMappingStaticInfo mmiStatic = { { rtBlockSignals , 99 ,
rtRootInputs , 0 , rtRootOutputs , 0 } , { rtBlockParameters , 148 ,
rtModelParameters , 0 } , { ( NULL ) , 0 } , { rtDataTypeMap , rtDimensionMap
, rtFixPtMap , rtElementMap , rtSampleTimeMap , rtDimensionArray } , "float"
, { 2532647534U , 717479846U , 1968865415U , 3579019364U } , ( NULL ) , 0 , (
boolean_T ) 0 , rt_LoggedStateIdxList } ; const
rtwCAPI_ModelMappingStaticInfo * air_part1_python2_GetCAPIStaticMap ( void )
{ return & mmiStatic ; }
#ifndef HOST_CAPI_BUILD
void air_part1_python2_InitializeDataMapInfo ( void ) { rtwCAPI_SetVersion (
( * rt_dataMapInfoPtr ) . mmi , 1 ) ; rtwCAPI_SetStaticMap ( ( *
rt_dataMapInfoPtr ) . mmi , & mmiStatic ) ; rtwCAPI_SetLoggingStaticMap ( ( *
rt_dataMapInfoPtr ) . mmi , ( NULL ) ) ; rtwCAPI_SetDataAddressMap ( ( *
rt_dataMapInfoPtr ) . mmi , rtDataAddrMap ) ; rtwCAPI_SetVarDimsAddressMap (
( * rt_dataMapInfoPtr ) . mmi , rtVarDimsAddrMap ) ;
rtwCAPI_SetInstanceLoggingInfo ( ( * rt_dataMapInfoPtr ) . mmi , ( NULL ) ) ;
rtwCAPI_SetChildMMIArray ( ( * rt_dataMapInfoPtr ) . mmi , ( NULL ) ) ;
rtwCAPI_SetChildMMIArrayLen ( ( * rt_dataMapInfoPtr ) . mmi , 0 ) ; }
#else
#ifdef __cplusplus
extern "C" {
#endif
void air_part1_python2_host_InitializeDataMapInfo (
air_part1_python2_host_DataMapInfo_T * dataMap , const char * path ) {
rtwCAPI_SetVersion ( dataMap -> mmi , 1 ) ; rtwCAPI_SetStaticMap ( dataMap ->
mmi , & mmiStatic ) ; rtwCAPI_SetDataAddressMap ( dataMap -> mmi , ( NULL ) )
; rtwCAPI_SetVarDimsAddressMap ( dataMap -> mmi , ( NULL ) ) ;
rtwCAPI_SetPath ( dataMap -> mmi , path ) ; rtwCAPI_SetFullPath ( dataMap ->
mmi , ( NULL ) ) ; rtwCAPI_SetChildMMIArray ( dataMap -> mmi , ( NULL ) ) ;
rtwCAPI_SetChildMMIArrayLen ( dataMap -> mmi , 0 ) ; }
#ifdef __cplusplus
}
#endif
#endif
