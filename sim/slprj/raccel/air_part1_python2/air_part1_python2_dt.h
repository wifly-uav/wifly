#include "ext_types.h"
static DataTypeInfo rtDataTypeInfoTable [ ] = { { "real_T" , 0 , 8 } , {
"real32_T" , 1 , 4 } , { "int8_T" , 2 , 1 } , { "uint8_T" , 3 , 1 } , {
"int16_T" , 4 , 2 } , { "uint16_T" , 5 , 2 } , { "int32_T" , 6 , 4 } , {
"uint32_T" , 7 , 4 } , { "boolean_T" , 8 , 1 } , { "fcn_call_T" , 9 , 0 } , {
"int_T" , 10 , 4 } , { "pointer_T" , 11 , 8 } , { "action_T" , 12 , 8 } , {
"timer_uint32_pair_T" , 13 , 8 } , { "physical_connection" , 14 , 8 } , {
"int64_T" , 15 , 8 } , { "uint64_T" , 16 , 8 } , { "uint32_T" , 17 , 4 } , {
"dp0kdzdsab" , 18 , 352 } , { "gvzvlbrjok" , 19 , 248 } , { "uint64_T" , 20 ,
8 } , { "int64_T" , 21 , 8 } , { "uint_T" , 22 , 32 } , { "char_T" , 23 , 8 }
, { "uchar_T" , 24 , 8 } , { "time_T" , 25 , 8 } } ; static uint_T
rtDataTypeSizes [ ] = { sizeof ( real_T ) , sizeof ( real32_T ) , sizeof (
int8_T ) , sizeof ( uint8_T ) , sizeof ( int16_T ) , sizeof ( uint16_T ) ,
sizeof ( int32_T ) , sizeof ( uint32_T ) , sizeof ( boolean_T ) , sizeof (
fcn_call_T ) , sizeof ( int_T ) , sizeof ( pointer_T ) , sizeof ( action_T )
, 2 * sizeof ( uint32_T ) , sizeof ( int32_T ) , sizeof ( int64_T ) , sizeof
( uint64_T ) , sizeof ( uint32_T ) , sizeof ( dp0kdzdsab ) , sizeof (
gvzvlbrjok ) , sizeof ( uint64_T ) , sizeof ( int64_T ) , sizeof ( uint_T ) ,
sizeof ( char_T ) , sizeof ( uchar_T ) , sizeof ( time_T ) } ; static const
char_T * rtDataTypeNames [ ] = { "real_T" , "real32_T" , "int8_T" , "uint8_T"
, "int16_T" , "uint16_T" , "int32_T" , "uint32_T" , "boolean_T" ,
"fcn_call_T" , "int_T" , "pointer_T" , "action_T" , "timer_uint32_pair_T" ,
"physical_connection" , "int64_T" , "uint64_T" , "uint32_T" , "dp0kdzdsab" ,
"gvzvlbrjok" , "uint64_T" , "int64_T" , "uint_T" , "char_T" , "uchar_T" ,
"time_T" } ; static DataTypeTransition rtBTransitions [ ] = { { ( char_T * )
( & rtB . a405zozv5t ) , 0 , 0 , 57 } , { ( char_T * ) ( & rtB . otnxjer3d0 )
, 17 , 0 , 1 } , { ( char_T * ) ( & rtB . hjr01anyo4 [ 0 ] ) , 3 , 0 , 524 }
, { ( char_T * ) ( & rtB . ktoqcjl1wu . n5nj1b05gf ) , 0 , 0 , 1 } , { (
char_T * ) ( & rtB . elpvuejile . o5vabvlgjn ) , 0 , 0 , 1 } , { ( char_T * )
( & rtB . eoqlazxz1z . nf3awaueuw ) , 0 , 0 , 1 } , { ( char_T * ) ( & rtB .
c21bk5qnit . fsek3luzie ) , 0 , 0 , 1 } , { ( char_T * ) ( & rtB . f2cxkdl2mb
. etkpdfh3bw ) , 0 , 0 , 3 } , { ( char_T * ) ( & rtB . hwhgormc0n .
n5nj1b05gf ) , 0 , 0 , 1 } , { ( char_T * ) ( & rtB . aelnqmel4f . jb2b5najpv
) , 0 , 0 , 1 } , { ( char_T * ) ( & rtB . p2tfl52njg . fsek3luzie ) , 0 , 0
, 1 } , { ( char_T * ) ( & rtB . jdelhdqjdy . n5nj1b05gf ) , 0 , 0 , 1 } , {
( char_T * ) ( & rtB . dgjrsvf3r0 . o5vabvlgjn ) , 0 , 0 , 1 } , { ( char_T *
) ( & rtB . ch5un3rjrb . nf3awaueuw ) , 0 , 0 , 1 } , { ( char_T * ) ( & rtB
. dwjvl3kmbe . fsek3luzie ) , 0 , 0 , 1 } , { ( char_T * ) ( & rtB .
fisn2ndewy . etkpdfh3bw ) , 0 , 0 , 3 } , { ( char_T * ) ( & rtB . jsqwvo4npa
. n5nj1b05gf ) , 0 , 0 , 1 } , { ( char_T * ) ( & rtB . ixdl5r0pbu .
jb2b5najpv ) , 0 , 0 , 1 } , { ( char_T * ) ( & rtB . c5fiym5p0p . fsek3luzie
) , 0 , 0 , 1 } , { ( char_T * ) ( & rtB . fvmfewdhwz . etkpdfh3bw ) , 0 , 0
, 3 } , { ( char_T * ) ( & rtB . btyuoi1co3 . a0dacr3vu5 ) , 0 , 0 , 4 } , {
( char_T * ) ( & rtB . ojl1qzu4tl . a0dacr3vu5 ) , 0 , 0 , 4 } , { ( char_T *
) ( & rtDW . hwcuhwqvaz ) , 18 , 0 , 1 } , { ( char_T * ) ( & rtDW .
bvsrcp4u0i ) , 19 , 0 , 1 } , { ( char_T * ) ( & rtDW . l30tmqcnmm ) , 0 , 0
, 56 } , { ( char_T * ) ( & rtDW . ijbiiwv2x1 . LoggedData ) , 11 , 0 , 73 }
, { ( char_T * ) ( & rtDW . jl0mnuibbh ) , 17 , 0 , 3 } , { ( char_T * ) ( &
rtDW . f0ny4gmuvx [ 0 ] ) , 10 , 0 , 30 } , { ( char_T * ) ( & rtDW .
ag0g5gwgl3 ) , 3 , 0 , 2 } , { ( char_T * ) ( & rtDW . gvaglrbdot ) , 8 , 0 ,
14 } } ; static DataTypeTransitionTable rtBTransTable = { 30U ,
rtBTransitions } ; static DataTypeTransition rtPTransitions [ ] = { { (
char_T * ) ( & rtP . PWM_Period ) , 0 , 0 , 4 } , { ( char_T * ) ( & rtP .
WrapToZero_Threshold ) , 17 , 0 , 1 } , { ( char_T * ) ( & rtP .
Integrator1_IC ) , 0 , 0 , 210 } , { ( char_T * ) ( & rtP .
Output_InitialCondition ) , 17 , 0 , 3 } } ; static DataTypeTransitionTable
rtPTransTable = { 4U , rtPTransitions } ;
