#ifndef RTW_HEADER_air_part1_python2_private_h_
#define RTW_HEADER_air_part1_python2_private_h_
#include "rtwtypes.h"
#include "builtin_typeid_types.h"
#include "multiword_types.h"
#include "air_part1_python2.h"
#include "air_part1_python2_types.h"
#if !defined(rt_VALIDATE_MEMORY)
#define rt_VALIDATE_MEMORY(S, ptr)     if(!(ptr)) {\
    ssSetErrorStatus(rtS, RT_MEMORY_ALLOCATION_ERROR);\
    }
#endif
#if !defined(rt_FREE)
#if !defined(_WIN32)
#define rt_FREE(ptr)     if((ptr) != (NULL)) {\
    free((ptr));\
    (ptr) = (NULL);\
    }
#else
#define rt_FREE(ptr)     if((ptr) != (NULL)) {\
    free((void *)(ptr));\
    (ptr) = (NULL);\
    }
#endif
#endif
#ifndef UCHAR_MAX
#include <limits.h>
#endif
#if ( UCHAR_MAX != (0xFFU) ) || ( SCHAR_MAX != (0x7F) )
#error Code was generated for compiler with different sized uchar/char. \Consider adjusting Test hardware word size settings on the \Hardware Implementation pane to match your compiler word sizes as \defined in limits.h of the compiler. Alternatively, you can \select the Test hardware is the same as production hardware option and \select the Enable portable word sizes option on the Code Generation > \Verification pane for ERT based targets, which will disable the \preprocessor word size checks.
#endif
#if ( USHRT_MAX != (0xFFFFU) ) || ( SHRT_MAX != (0x7FFF) )
#error Code was generated for compiler with different sized ushort/short. \Consider adjusting Test hardware word size settings on the \Hardware Implementation pane to match your compiler word sizes as \defined in limits.h of the compiler. Alternatively, you can \select the Test hardware is the same as production hardware option and \select the Enable portable word sizes option on the Code Generation > \Verification pane for ERT based targets, which will disable the \preprocessor word size checks.
#endif
#if ( UINT_MAX != (0xFFFFFFFFU) ) || ( INT_MAX != (0x7FFFFFFF) )
#error Code was generated for compiler with different sized uint/int. \Consider adjusting Test hardware word size settings on the \Hardware Implementation pane to match your compiler word sizes as \defined in limits.h of the compiler. Alternatively, you can \select the Test hardware is the same as production hardware option and \select the Enable portable word sizes option on the Code Generation > \Verification pane for ERT based targets, which will disable the \preprocessor word size checks.
#endif
#if ( ULONG_MAX != (0xFFFFFFFFU) ) || ( LONG_MAX != (0x7FFFFFFF) )
#error Code was generated for compiler with different sized ulong/long. \Consider adjusting Test hardware word size settings on the \Hardware Implementation pane to match your compiler word sizes as \defined in limits.h of the compiler. Alternatively, you can \select the Test hardware is the same as production hardware option and \select the Enable portable word sizes option on the Code Generation > \Verification pane for ERT based targets, which will disable the \preprocessor word size checks.
#endif
#ifndef __RTW_UTFREE__
extern void * utMalloc ( size_t ) ; extern void utFree ( void * ) ;
#endif
extern real_T rt_urand_Upu32_Yd_f_pw_snf ( uint32_T * u ) ; extern real_T
rt_nrand_Upu32_Yd_f_pw_snf ( uint32_T * u ) ; void * rt_TDelayCreateBuf (
int_T numBuffer , int_T bufSz , int_T elemSz ) ; boolean_T
rt_TDelayUpdateTailOrGrowBuf ( int_T * bufSzPtr , int_T * tailPtr , int_T *
headPtr , int_T * lastPtr , real_T tMinusDelay , real_T * * uBufPtr ,
boolean_T isfixedbuf , boolean_T istransportdelay , int_T * maxNewBufSzPtr )
; real_T rt_TDelayInterpolate ( real_T tMinusDelay , real_T tStart , real_T *
uBuf , int_T bufSz , int_T * lastIdx , int_T oldestIdx , int_T newIdx ,
real_T initOutput , boolean_T discrete , boolean_T
minorStepAndTAtLastMajorOutput ) ; extern void slasciiencode ( SimStruct *
rts ) ; extern void slasciidecode ( SimStruct * rts ) ; void rt_TDelayFreeBuf
( void * buf ) ; extern void imsa1beie2 ( real_T f4vmbwzk3c , real_T
foc0nilpad , real_T ooxukj4j5y , real_T ldabbrc4qw , real_T a0swvc3tzr ,
jaojyey2gb * localB ) ; extern void jlcrjksjko ( real_T bukdskjxf1 , real_T
mvl5xc11ep , real_T c2jruv34kj , real_T pnvl4igfri , ocg145ebmd * localB ) ;
extern void a3gzjtzg5m ( real_T idvnpwtwk3 , dooynonrws * localB ) ; extern
void g1ij20yo5c ( real_T fdoshxgzib , real_T l44au10k3c , real_T l55oqbw44q ,
real_T awjvapmqyo , clfyjfqiuu * localB ) ; extern void jj2h00reln ( real_T
i2lswpncqn , b332zk4fge * localB ) ; extern void mjmlfjqs31 ( real_T
hrxqmttc5l , real_T kzn4nrbum2 , real_T aksqgdxrso , real_T amdfrjgwsy ,
l3mdrvvpuy * localB ) ; extern void dtuuqh01ed ( real_T jutpbufeve , real_T
e0c4jdrz1w , real_T fgswrovla2 , real_T dprp01z3vm , gywknl2xur * localB ) ;
#if defined(MULTITASKING)
#error Model (air_part1_python2) was built in \SingleTasking solver mode, however the MULTITASKING define is \present. If you have multitasking (e.g. -DMT or -DMULTITASKING) \defined on the Code Generation page of Simulation parameter dialog, please \remove it and on the Solver page, select solver mode \MultiTasking. If the Simulation parameter dialog is configured \correctly, please verify that your template makefile is \configured correctly.
#endif
#endif
