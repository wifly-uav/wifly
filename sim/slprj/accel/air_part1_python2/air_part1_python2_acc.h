#ifndef RTW_HEADER_air_part1_python2_acc_h_
#define RTW_HEADER_air_part1_python2_acc_h_
#ifndef air_part1_python2_acc_COMMON_INCLUDES_
#define air_part1_python2_acc_COMMON_INCLUDES_
#include <stdlib.h>
#define S_FUNCTION_NAME simulink_only_sfcn
#define S_FUNCTION_LEVEL 2
#ifndef RTW_GENERATED_S_FUNCTION
#define RTW_GENERATED_S_FUNCTION
#endif
#include "sl_AsyncioQueue/AsyncioQueueCAPI.h"
#include "rtwtypes.h"
#include "simstruc.h"
#include "fixedpoint.h"
#endif
#include "air_part1_python2_acc_types.h"
#include <stddef.h>
#include "rtGetInf.h"
#include "rt_nonfinite.h"
#include <string.h>
#include <float.h>
#include "mwmathutil.h"
#include "rt_defines.h"
typedef struct { real_T B_26_4_0 ; real_T B_26_6_0 ; real_T B_26_8_0 ; real_T
B_26_11_0 ; real_T B_26_14_0 ; real_T B_26_15_0 ; real_T B_26_17_0 ; real_T
B_26_20_0 ; real_T B_26_23_0 ; real_T B_26_25_0 ; real_T B_26_31_0 ; real_T
B_26_34_0 ; real_T B_26_35_0 ; real_T B_26_37_0 ; real_T B_26_40_0 ; real_T
B_26_44_0 ; real_T B_26_45_0 ; real_T B_26_46_0 ; real_T B_26_52_0 ; real_T
B_26_65_0 ; real_T B_26_66_0 ; real_T B_26_68_0 ; real_T B_26_70_0 ; real_T
B_26_73_0 ; real_T B_26_76_0 ; real_T B_26_79_0 ; real_T B_26_80_0 ; real_T
B_26_83_0 ; real_T B_26_87_0 ; real_T B_26_88_0 ; real_T B_26_92_0 ; real_T
B_26_94_0 ; real_T B_26_96_0 ; real_T B_26_104_0 ; real_T B_26_106_0 ; real_T
B_26_109_0 ; real_T B_26_113_0 ; real_T B_26_114_0 ; real_T B_26_115_0 ;
real_T B_26_117_0 ; real_T B_26_119_0 ; real_T B_26_122_0 ; real_T B_26_126_0
; real_T B_26_127_0 ; real_T B_26_128_0 ; real_T B_26_130_0 ; real_T
B_26_132_0 ; real_T B_26_136_0 ; real_T B_26_137_0 ; real_T B_26_138_0 ;
real_T B_26_139_0 ; real_T B_26_140_0 ; real_T B_26_141_0 ; real_T B_26_173_0
; real_T B_26_174_0 ; real_T B_26_175_0 ; real_T B_26_176_0 ; real_T
B_26_177_0 ; real_T B_26_178_0 ; real_T B_26_179_0 ; real_T B_26_197_0 ;
real_T B_26_211_0 ; real_T B_26_217_0 ; real_T B_26_218_0 ; real_T B_26_219_0
; real_T B_26_224_0 ; real_T B_26_228_0 ; real_T B_26_232_0 ; real_T
B_26_237_0 ; real_T B_26_238_0 ; real_T B_26_239_0 ; real_T B_26_2_0 ; real_T
B_26_3_0 ; real_T B_26_4_0_m ; real_T B_26_5_0 ; real_T B_26_6_0_c ; real_T
B_26_7_0 ; real_T B_26_8_0_k ; real_T B_26_9_0 ; real_T B_26_10_0 ; real_T
B_26_11_0_c ; real_T B_26_12_0 ; real_T B_26_13_0 ; real_T B_26_14_0_b ;
real_T B_26_15_0_p ; real_T B_26_16_0 ; real_T B_26_17_0_c ; real_T B_26_18_0
; real_T B_26_19_0 ; real_T B_26_20_0_f ; real_T B_26_21_0 ; real_T B_26_22_0
; real_T B_26_23_0_g ; real_T B_26_24_0 ; real_T B_26_25_0_g ; real_T
B_26_26_0 ; real_T B_26_27_0 ; real_T B_26_29_0 ; real_T B_26_31_0_m ; real_T
B_26_33_0 ; real_T B_26_35_0_n ; real_T B_26_36_0 ; real_T B_26_37_0_p ;
real_T B_26_38_0 ; real_T B_26_39_0 ; real_T B_26_40_0_l ; real_T B_26_43_0 ;
real_T B_26_44_0_j ; real_T B_26_45_0_d ; real_T B_26_46_0_g ; real_T
B_26_49_0 ; real_T B_26_50_0 ; real_T B_26_51_0 ; real_T B_26_52_0_l ; real_T
B_26_55_0 ; real_T B_26_56_0 ; real_T B_26_57_0 ; real_T B_26_58_0 ; real_T
B_26_61_0 ; real_T B_26_62_0 ; real_T B_26_63_0 ; real_T B_25_0_1 ; real_T
B_24_0_1 ; real_T B_23_0_1 ; real_T B_22_0_1 ; real_T B_21_0_1 ; real_T
B_21_0_2 ; real_T B_21_0_3 ; real_T B_20_0_1 ; real_T B_19_0_1 ; real_T
B_18_0_1 ; real_T B_17_0_1 ; real_T B_16_0_1 ; real_T B_16_0_2 ; real_T
B_16_0_3 ; real_T B_15_0_1 ; real_T B_14_0_1 ; real_T B_13_0_1 ; real_T
B_12_0_1 ; real_T B_11_0_1 ; real_T B_11_0_2 ; real_T B_11_0_3 ; real_T
B_10_0_1 ; real_T B_9_0_1 ; real_T B_8_0_1 ; real_T B_7_0_1 ; real_T B_6_0_1
; real_T B_6_0_2 ; real_T B_6_0_3 ; real_T B_5_0_1 ; real_T B_5_0_2 ; real_T
B_5_0_3 ; real_T B_5_0_4 ; real_T B_4_0_1 ; real_T B_4_0_2 ; real_T B_4_0_3 ;
real_T B_4_0_4 ; real_T B_3_0_1 ; real_T B_3_0_2 ; real_T B_3_0_3 ; real_T
B_3_0_4 ; real_T B_2_0_1 ; real_T B_2_0_2 ; real_T B_2_0_3 ; real_T B_2_0_4 ;
uint32_T B_26_172_0 ; uint32_T B_26_0_0 ; uint32_T B_26_1_0 ; uint8_T
B_26_98_0 [ 128 ] ; uint8_T B_26_99_0 [ 128 ] ; uint8_T B_26_100_0 [ 256 ] ;
uint8_T B_26_135_0 ; uint8_T B_26_135_1 ; uint8_T B_26_135_2 ; uint8_T
B_26_135_3 ; uint8_T B_26_135_4 ; uint8_T B_26_135_5 ; uint8_T B_0_0_0 [ 6 ]
; } B_air_part1_python2_T ; typedef struct { real_T TimeStampA ; real_T
LastUAtTimeA ; real_T TimeStampB ; real_T LastUAtTimeB ; real_T TimeStampA_d
; real_T LastUAtTimeA_o ; real_T TimeStampB_i ; real_T LastUAtTimeB_i ;
real_T TimeStampA_j ; real_T LastUAtTimeA_p ; real_T TimeStampB_n ; real_T
LastUAtTimeB_n ; real_T TimeStampA_p ; real_T LastUAtTimeA_j ; real_T
TimeStampB_p ; real_T LastUAtTimeB_p ; real_T TimeStampA_l ; real_T
LastUAtTimeA_e ; real_T TimeStampB_o ; real_T LastUAtTimeB_l ; real_T
TimeStampA_dv ; real_T LastUAtTimeA_m ; real_T TimeStampB_d ; real_T
LastUAtTimeB_nt ; real_T NextOutput ; real_T TimeStampA_k ; real_T
LastUAtTimeA_pl ; real_T TimeStampB_if ; real_T LastUAtTimeB_d ; real_T
TimeStampA_n ; real_T LastUAtTimeA_i ; real_T TimeStampB_c ; real_T
LastUAtTimeB_nb ; real_T TimeStampA_f ; real_T LastUAtTimeA_n ; real_T
TimeStampB_a ; real_T LastUAtTimeB_lc ; real_T TimeStampA_c ; real_T
LastUAtTimeA_d ; real_T TimeStampB_e ; real_T LastUAtTimeB_j ; real_T
TimeStampA_m ; real_T LastUAtTimeA_di ; real_T TimeStampB_nz ; real_T
LastUAtTimeB_o ; real_T TimeStampA_cb ; real_T LastUAtTimeA_g ; real_T
TimeStampB_j ; real_T LastUAtTimeB_f ; real_T NextOutput_c ; real_T
startTimeOfNextCycle ; real_T startTimeOfNextCycle_n ; struct { real_T
modelTStart ; } VariableTimeDelay1_RWORK ; struct { real_T modelTStart ; }
VariableTimeDelay_RWORK ; void * Scope_PWORK ; void * Scope1_PWORK ; void *
Scope11_PWORK [ 3 ] ; void * Scope14_PWORK [ 2 ] ; void * Scope2_PWORK [ 3 ]
; void * Scope3_PWORK [ 2 ] ; void * Scope4_PWORK [ 2 ] ; void * Scope6_PWORK
; void * Scope7_PWORK ; void * ASCIIEncode_PWORK ; void * ASCIIEncode1_PWORK
; struct { void * AQHandles ; } _asyncqueue_inserted_for_ToWorkspace_PWORK ;
struct { void * AQHandles ; } _asyncqueue_inserted_for_ToWorkspace1_PWORK ;
struct { void * AQHandles ; } _asyncqueue_inserted_for_ToWorkspace2_PWORK ;
struct { void * AQHandles ; } _asyncqueue_inserted_for_ToWorkspace3_PWORK ;
void * ASCIIDecode_PWORK [ 2 ] ; void * ASCIIDecode1_PWORK [ 2 ] ; void *
ASCIIDecode2_PWORK [ 2 ] ; void * ASCIIDecode3_PWORK [ 2 ] ; void *
ASCIIDecode4_PWORK [ 2 ] ; void * ASCIIDecode5_PWORK [ 2 ] ; struct { void *
TUbufferPtrs [ 2 ] ; } VariableTimeDelay1_PWORK ; struct { void *
TUbufferPtrs [ 2 ] ; } VariableTimeDelay_PWORK ; void * Scope_PWORK_o [ 2 ] ;
void * Scope_PWORK_j ; void * Scope1_PWORK_h ; void * Scope2_PWORK_l ; void *
Scope3_PWORK_p [ 2 ] ; void * Scope4_PWORK_g ; void * Scope5_PWORK ; void *
Scope6_PWORK_g ; void * Scope7_PWORK_i ; struct { void * AQHandles ; }
_asyncqueue_inserted_for_ToWorkspace1_PWORK_k ; struct { void * AQHandles ; }
_asyncqueue_inserted_for_ToWorkspace2_PWORK_b ; void * Scope_PWORK_p ; void *
Scope1_PWORK_a ; void * Scope2_PWORK_lg ; void * Scope3_PWORK_o [ 2 ] ; void
* Scope4_PWORK_gi ; void * Scope5_PWORK_h ; void * Scope6_PWORK_k ; void *
Scope7_PWORK_m ; struct { void * AQHandles ; }
_asyncqueue_inserted_for_ToWorkspace1_PWORK_k1 ; void * Scope_PWORK_a ; void
* Scope1_PWORK_hi ; void * Scope3_PWORK_c [ 2 ] ; void * Scope4_PWORK_o ;
void * Scope6_PWORK_i ; void * Scope_PWORK_e ; void * Scope1_PWORK_m ; void *
Scope2_PWORK_m ; void * Scope3_PWORK_b [ 2 ] ; void * Scope4_PWORK_or ; void
* Scope5_PWORK_d ; void * Scope6_PWORK_a ; void * Scope7_PWORK_j ; uint32_T
Output_DSTATE ; int32_T MATLABFunction4_sysIdxToRun ; int32_T
MATLABFunction3_sysIdxToRun ; int32_T MATLABFunction2_sysIdxToRun ; int32_T
MATLABFunction1_sysIdxToRun ; int32_T MATLABFunction_sysIdxToRun ; int32_T
MATLABFunction4_sysIdxToRun_p ; int32_T MATLABFunction3_sysIdxToRun_a ;
int32_T MATLABFunction2_sysIdxToRun_l ; int32_T MATLABFunction1_sysIdxToRun_k
; int32_T MATLABFunction_sysIdxToRun_o ; int32_T
MATLABFunction4_sysIdxToRun_b ; int32_T MATLABFunction3_sysIdxToRun_c ;
int32_T MATLABFunction2_sysIdxToRun_i ; int32_T MATLABFunction1_sysIdxToRun_p
; int32_T MATLABFunction_sysIdxToRun_e ; int32_T
MATLABFunction4_sysIdxToRun_k ; int32_T MATLABFunction3_sysIdxToRun_p ;
int32_T MATLABFunction2_sysIdxToRun_m ; int32_T MATLABFunction1_sysIdxToRun_a
; int32_T MATLABFunction_sysIdxToRun_h ; int32_T MATLABFunction_sysIdxToRun_i
; int32_T MATLABFunction_sysIdxToRun_p ; int32_T MATLABFunction_sysIdxToRun_d
; int32_T MATLABFunction_sysIdxToRun_g ; int32_T TCPIPSend_sysIdxToRun ;
int32_T TCPIPReceive_sysIdxToRun ; uint32_T RandSeed ; uint32_T RandSeed_c ;
uint32_T FixPtSum1_DWORK1 ; int_T BytePacking_IWORK [ 4 ] ; int_T
ASCIIDecode_IWORK [ 4 ] ; int_T ASCIIDecode1_IWORK [ 4 ] ; int_T
ASCIIDecode2_IWORK [ 4 ] ; int_T ASCIIDecode3_IWORK [ 4 ] ; int_T
ASCIIDecode4_IWORK [ 4 ] ; int_T ASCIIDecode5_IWORK [ 4 ] ; struct { int_T
Tail ; int_T Head ; int_T Last ; int_T CircularBufSize ; int_T MaxNewBufSize
; } VariableTimeDelay1_IWORK ; struct { int_T Tail ; int_T Head ; int_T Last
; int_T CircularBufSize ; int_T MaxNewBufSize ; } VariableTimeDelay_IWORK ;
boolean_T nextOutput ; boolean_T isStartOfNextCycle ; boolean_T
isFirstWarningDCGreaterThanOne ; boolean_T isFirstWarningDCLessThanZero ;
boolean_T nextOutput_b ; boolean_T isStartOfNextCycle_p ; boolean_T
isFirstWarningDCGreaterThanOne_b ; boolean_T isFirstWarningDCLessThanZero_g ;
} DW_air_part1_python2_T ; typedef struct { real_T Integrator1_CSTATE ;
real_T Integrator_CSTATE ; real_T Integrator1_CSTATE_p ; real_T
Integrator3_CSTATE ; real_T Integrator2_CSTATE ; real_T Integrator_CSTATE_p ;
real_T Integrator1_CSTATE_j ; real_T Integrator_CSTATE_h ; }
X_air_part1_python2_T ; typedef struct { real_T Integrator1_CSTATE ; real_T
Integrator_CSTATE ; real_T Integrator1_CSTATE_p ; real_T Integrator3_CSTATE ;
real_T Integrator2_CSTATE ; real_T Integrator_CSTATE_p ; real_T
Integrator1_CSTATE_j ; real_T Integrator_CSTATE_h ; }
XDot_air_part1_python2_T ; typedef struct { boolean_T Integrator1_CSTATE ;
boolean_T Integrator_CSTATE ; boolean_T Integrator1_CSTATE_p ; boolean_T
Integrator3_CSTATE ; boolean_T Integrator2_CSTATE ; boolean_T
Integrator_CSTATE_p ; boolean_T Integrator1_CSTATE_j ; boolean_T
Integrator_CSTATE_h ; } XDis_air_part1_python2_T ; struct
P_air_part1_python2_T_ { real_T P_0 ; real_T P_1 ; real_T P_2 ; real_T P_3 ;
real_T P_4 ; real_T P_5 ; real_T P_6 ; real_T P_7 ; real_T P_8 ; real_T P_9 ;
real_T P_10 ; real_T P_11 ; real_T P_12 ; real_T P_13 ; real_T P_14 ; real_T
P_15 ; real_T P_16 ; real_T P_17 ; real_T P_18 ; real_T P_19 ; real_T P_20 ;
real_T P_21 ; real_T P_22 ; real_T P_23 ; real_T P_24 ; real_T P_25 ; real_T
P_26 [ 2 ] ; real_T P_27 [ 4 ] ; real_T P_28 [ 2 ] ; real_T P_29 ; real_T
P_30 [ 2 ] ; real_T P_31 ; real_T P_32 [ 2 ] ; real_T P_33 ; real_T P_34 [ 2
] ; real_T P_35 [ 4 ] ; real_T P_36 [ 2 ] ; real_T P_37 ; real_T P_38 [ 2 ] ;
real_T P_39 ; real_T P_40 [ 2 ] ; real_T P_41 ; real_T P_42 ; real_T P_43 ;
real_T P_44 ; real_T P_45 ; real_T P_46 [ 2 ] ; real_T P_47 [ 3 ] ; real_T
P_48 [ 2 ] ; real_T P_49 ; real_T P_50 [ 2 ] ; real_T P_51 ; real_T P_52 [ 2
] ; real_T P_53 [ 3 ] ; real_T P_54 [ 2 ] ; real_T P_55 ; real_T P_56 [ 2 ] ;
real_T P_57 ; real_T P_58 [ 2 ] ; real_T P_59 [ 3 ] ; real_T P_60 [ 2 ] ;
real_T P_61 ; real_T P_62 [ 2 ] ; real_T P_63 ; real_T P_64 [ 2 ] ; real_T
P_65 [ 3 ] ; real_T P_66 [ 2 ] ; real_T P_67 ; real_T P_68 [ 2 ] ; real_T
P_69 ; real_T P_70 [ 2 ] ; real_T P_71 [ 3 ] ; real_T P_72 [ 2 ] ; real_T
P_73 ; real_T P_74 [ 2 ] ; real_T P_75 ; real_T P_76 [ 2 ] ; real_T P_77 [ 3
] ; real_T P_78 [ 2 ] ; real_T P_79 ; real_T P_80 [ 2 ] ; real_T P_81 ;
real_T P_82 ; real_T P_83 ; real_T P_84 ; real_T P_85 ; real_T P_86 ; real_T
P_87 ; real_T P_88 ; real_T P_89 ; real_T P_90 ; real_T P_91 ; real_T P_92 ;
real_T P_93 ; real_T P_94 ; real_T P_95 ; real_T P_96 ; real_T P_97 ; real_T
P_98 ; real_T P_99 ; real_T P_100 ; real_T P_101 ; real_T P_102 ; real_T
P_103 ; real_T P_104 ; real_T P_105 ; real_T P_106 ; real_T P_107 ; real_T
P_108 ; real_T P_109 ; real_T P_110 ; real_T P_111 ; real_T P_112 ; real_T
P_113 ; real_T P_114 ; real_T P_115 ; real_T P_116 ; real_T P_117 ; real_T
P_118 ; real_T P_119 ; real_T P_120 ; real_T P_121 ; real_T P_122 ; real_T
P_123 ; real_T P_124 ; real_T P_125 ; real_T P_126 ; real_T P_127 ; real_T
P_128 ; real_T P_129 ; real_T P_130 ; real_T P_131 ; real_T P_132 ; real_T
P_133 ; real_T P_134 ; real_T P_135 ; real_T P_136 ; real_T P_137 ; real_T
P_138 ; real_T P_139 ; real_T P_140 ; real_T P_141 ; real_T P_142 ; real_T
P_143 ; real_T P_144 ; real_T P_145 ; real_T P_146 ; real_T P_147 ; real_T
P_148 ; real_T P_149 ; real_T P_150 ; real_T P_151 ; real_T P_152 ; real_T
P_153 ; real_T P_154 ; real_T P_155 ; real_T P_156 ; real_T P_157 ; real_T
P_158 ; real_T P_159 ; real_T P_160 ; real_T P_161 ; real_T P_162 ; real_T
P_163 ; real_T P_164 ; real_T P_165 ; real_T P_166 ; real_T P_167 ; real_T
P_168 ; real_T P_169 ; uint32_T P_170 ; uint32_T P_171 ; uint32_T P_172 ;
uint32_T P_173 ; } ; extern P_air_part1_python2_T
air_part1_python2_rtDefaultP ;
#endif
