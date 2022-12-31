#ifndef RTW_HEADER_air_part1_python2_types_h_
#define RTW_HEADER_air_part1_python2_types_h_
#include "rtwtypes.h"
#include "asynciocoder_api.hpp"
#ifndef struct_tag_syRUN6P8dnDtW4zHaczOEwG
#define struct_tag_syRUN6P8dnDtW4zHaczOEwG
struct tag_syRUN6P8dnDtW4zHaczOEwG { boolean_T InitAccess ; boolean_T
TransferDelay ; uint64_T LatestNumBytesWrittenToDevice ; } ;
#endif
#ifndef typedef_lchp1rikuv
#define typedef_lchp1rikuv
typedef struct tag_syRUN6P8dnDtW4zHaczOEwG lchp1rikuv ;
#endif
#include "asynciocoder_api.hpp"
#include "asynciocoder_api.hpp"
#include "asynciocoder_api.hpp"
#include "coder_posix_time.h"
#ifndef struct_tag_Io6M0197HNvEktjdcNX3TH
#define struct_tag_Io6M0197HNvEktjdcNX3TH
struct tag_Io6M0197HNvEktjdcNX3TH { boolean_T matlabCodegenIsDeleted ; real_T
Timeout ; CoderOutputStream StreamImpl ; } ;
#endif
#ifndef typedef_e4wb5cpnqg
#define typedef_e4wb5cpnqg
typedef struct tag_Io6M0197HNvEktjdcNX3TH e4wb5cpnqg ;
#endif
#ifndef struct_tag_gcdm7dQ1aHEzQeDe2amARE
#define struct_tag_gcdm7dQ1aHEzQeDe2amARE
struct tag_gcdm7dQ1aHEzQeDe2amARE { uint8_T f1 [ 2048 ] ; } ;
#endif
#ifndef typedef_mfwlu25r5h
#define typedef_mfwlu25r5h
typedef struct tag_gcdm7dQ1aHEzQeDe2amARE mfwlu25r5h ;
#endif
#ifndef struct_tag_Ba6DB06vtiiekOLgS9CVeB
#define struct_tag_Ba6DB06vtiiekOLgS9CVeB
struct tag_Ba6DB06vtiiekOLgS9CVeB { uint8_T f1 [ 256 ] ; } ;
#endif
#ifndef typedef_bkeu4uuq53
#define typedef_bkeu4uuq53
typedef struct tag_Ba6DB06vtiiekOLgS9CVeB bkeu4uuq53 ;
#endif
#ifndef struct_emxArray_uint8_T
#define struct_emxArray_uint8_T
struct emxArray_uint8_T { uint8_T * data ; int32_T * size ; int32_T
allocatedSize ; int32_T numDimensions ; boolean_T canFreeData ; } ;
#endif
#ifndef typedef_akean23d1n
#define typedef_akean23d1n
typedef struct emxArray_uint8_T akean23d1n ;
#endif
#ifndef struct_emxArray_char_T
#define struct_emxArray_char_T
struct emxArray_char_T { char_T * data ; int32_T * size ; int32_T
allocatedSize ; int32_T numDimensions ; boolean_T canFreeData ; } ;
#endif
#ifndef typedef_kc1cjr2jks
#define typedef_kc1cjr2jks
typedef struct emxArray_char_T kc1cjr2jks ;
#endif
#ifndef struct_tag_eqMNxBm2oqiBys2eK2JbWF
#define struct_tag_eqMNxBm2oqiBys2eK2JbWF
struct tag_eqMNxBm2oqiBys2eK2JbWF { boolean_T matlabCodegenIsDeleted ; real_T
Timeout ; CoderInputStream StreamImpl ; akean23d1n * PartialPacket ; real_T
PartialPacketStart ; real_T PartialPacketCount ; akean23d1n * ExampleData ; }
;
#endif
#ifndef typedef_ax0y0tfz0l
#define typedef_ax0y0tfz0l
typedef struct tag_eqMNxBm2oqiBys2eK2JbWF ax0y0tfz0l ;
#endif
#ifndef struct_tag_iPgdEUULAMzDvX1fzSFRcC
#define struct_tag_iPgdEUULAMzDvX1fzSFRcC
struct tag_iPgdEUULAMzDvX1fzSFRcC { boolean_T matlabCodegenIsDeleted ;
ax0y0tfz0l InputStream ; e4wb5cpnqg OutputStream ; CoderChannel ChannelImpl ;
lchp1rikuv CustomProps ; } ;
#endif
#ifndef typedef_kwgo0x2v41
#define typedef_kwgo0x2v41
typedef struct tag_iPgdEUULAMzDvX1fzSFRcC kwgo0x2v41 ;
#endif
#ifndef struct_tag_fS4Rk6jhpXOyxKX9dbYsfE
#define struct_tag_fS4Rk6jhpXOyxKX9dbYsfE
struct tag_fS4Rk6jhpXOyxKX9dbYsfE { boolean_T matlabCodegenIsDeleted ;
ax0y0tfz0l InputStream ; e4wb5cpnqg OutputStream ; CoderChannel ChannelImpl ;
real_T TotalElementsWritten ; akean23d1n * PartialPacket ; real_T
PartialPacketStart ; real_T PartialPacketCount ; real_T BytesPerElement ; } ;
#endif
#ifndef typedef_hscjo2zzvm
#define typedef_hscjo2zzvm
typedef struct tag_fS4Rk6jhpXOyxKX9dbYsfE hscjo2zzvm ;
#endif
#ifndef struct_tag_KZVmEYnKzBO0bbjMgdFCtD
#define struct_tag_KZVmEYnKzBO0bbjMgdFCtD
struct tag_KZVmEYnKzBO0bbjMgdFCtD { boolean_T matlabCodegenIsDeleted ; char_T
MachineByteOrder [ 13 ] ; kwgo0x2v41 * AsyncIOChannel ; hscjo2zzvm
UnreadDataBuffer ; kc1cjr2jks * ByteOrder ; kc1cjr2jks * NativeDataType ;
kc1cjr2jks * DataFieldName ; boolean_T AllowPartialReads ; } ;
#endif
#ifndef typedef_g1hz5apriq
#define typedef_g1hz5apriq
typedef struct tag_KZVmEYnKzBO0bbjMgdFCtD g1hz5apriq ;
#endif
#ifndef struct_tag_fVk8PnY13ZlHEd8EWlm7GC
#define struct_tag_fVk8PnY13ZlHEd8EWlm7GC
struct tag_fVk8PnY13ZlHEd8EWlm7GC { boolean_T matlabCodegenIsDeleted ; char_T
RemoteHost [ 9 ] ; real_T RemotePort ; boolean_T IsWriteOnly ; boolean_T
IsSharingPort ; real_T ConnectTimeout ; real_T InputBufferSize ; real_T
OutputBufferSize ; kwgo0x2v41 * AsyncIOChannel ; g1hz5apriq *
TransportChannel ; boolean_T TransferDelay ; g1hz5apriq _pobj0 ; kwgo0x2v41
_pobj1 ; } ;
#endif
#ifndef typedef_ovagoamv4w
#define typedef_ovagoamv4w
typedef struct tag_fVk8PnY13ZlHEd8EWlm7GC ovagoamv4w ;
#endif
#ifndef struct_tag_mPdMr8v01lQcBgzjDXPH4
#define struct_tag_mPdMr8v01lQcBgzjDXPH4
struct tag_mPdMr8v01lQcBgzjDXPH4 { boolean_T matlabCodegenIsDeleted ; int32_T
isInitialized ; boolean_T isSetupComplete ; ovagoamv4w TCPIPObj ; } ;
#endif
#ifndef typedef_dp0kdzdsab
#define typedef_dp0kdzdsab
typedef struct tag_mPdMr8v01lQcBgzjDXPH4 dp0kdzdsab ;
#endif
#ifndef struct_tag_Lg49zQshP9C0AXZ4N6qODG
#define struct_tag_Lg49zQshP9C0AXZ4N6qODG
struct tag_Lg49zQshP9C0AXZ4N6qODG { boolean_T matlabCodegenIsDeleted ;
CoderInputStream StreamImpl ; akean23d1n * ExampleData ; } ;
#endif
#ifndef typedef_ax0y0tfz0lj
#define typedef_ax0y0tfz0lj
typedef struct tag_Lg49zQshP9C0AXZ4N6qODG ax0y0tfz0lj ;
#endif
#ifndef struct_tag_LoCLE6ghdyNMbCWimvPqH
#define struct_tag_LoCLE6ghdyNMbCWimvPqH
struct tag_LoCLE6ghdyNMbCWimvPqH { boolean_T matlabCodegenIsDeleted ;
ax0y0tfz0lj InputStream ; e4wb5cpnqg OutputStream ; CoderChannel ChannelImpl
; lchp1rikuv CustomProps ; } ;
#endif
#ifndef typedef_kwgo0x2v41z
#define typedef_kwgo0x2v41z
typedef struct tag_LoCLE6ghdyNMbCWimvPqH kwgo0x2v41z ;
#endif
#ifndef struct_tag_qTOUowvox6uvVfnhFCU8iC
#define struct_tag_qTOUowvox6uvVfnhFCU8iC
struct tag_qTOUowvox6uvVfnhFCU8iC { boolean_T matlabCodegenIsDeleted ;
ax0y0tfz0lj InputStream ; e4wb5cpnqg OutputStream ; CoderChannel ChannelImpl
; } ;
#endif
#ifndef typedef_hscjo2zzvmb
#define typedef_hscjo2zzvmb
typedef struct tag_qTOUowvox6uvVfnhFCU8iC hscjo2zzvmb ;
#endif
#ifndef struct_tag_m5ENUefGK5JCQRCSPO0fEF
#define struct_tag_m5ENUefGK5JCQRCSPO0fEF
struct tag_m5ENUefGK5JCQRCSPO0fEF { boolean_T matlabCodegenIsDeleted ; char_T
MachineByteOrder [ 13 ] ; kwgo0x2v41z * AsyncIOChannel ; hscjo2zzvmb
UnreadDataBuffer ; real_T NumBytesWritten ; kc1cjr2jks * ByteOrder ;
boolean_T WriteAsync ; } ;
#endif
#ifndef typedef_g1hz5apriqr
#define typedef_g1hz5apriqr
typedef struct tag_m5ENUefGK5JCQRCSPO0fEF g1hz5apriqr ;
#endif
#ifndef struct_tag_bNdfmMhQLnekGhHzXi983D
#define struct_tag_bNdfmMhQLnekGhHzXi983D
struct tag_bNdfmMhQLnekGhHzXi983D { boolean_T matlabCodegenIsDeleted ; char_T
RemoteHost [ 9 ] ; real_T RemotePort ; boolean_T IsWriteOnly ; boolean_T
IsSharingPort ; real_T ConnectTimeout ; real_T InputBufferSize ; real_T
OutputBufferSize ; kwgo0x2v41z * AsyncIOChannel ; g1hz5apriqr *
TransportChannel ; boolean_T TransferDelay ; g1hz5apriqr _pobj0 ; kwgo0x2v41z
_pobj1 ; } ;
#endif
#ifndef typedef_ovagoamv4wz
#define typedef_ovagoamv4wz
typedef struct tag_bNdfmMhQLnekGhHzXi983D ovagoamv4wz ;
#endif
#ifndef struct_tag_xQLlL62i8YONlP7KsaEVPF
#define struct_tag_xQLlL62i8YONlP7KsaEVPF
struct tag_xQLlL62i8YONlP7KsaEVPF { boolean_T matlabCodegenIsDeleted ;
int32_T isInitialized ; boolean_T isSetupComplete ; ovagoamv4wz TCPIPObj ;
char_T InputDataType [ 5 ] ; } ;
#endif
#ifndef typedef_gvzvlbrjok
#define typedef_gvzvlbrjok
typedef struct tag_xQLlL62i8YONlP7KsaEVPF gvzvlbrjok ;
#endif
#ifndef struct_tag_tVNDDbBfXx0nORXjehL0f
#define struct_tag_tVNDDbBfXx0nORXjehL0f
struct tag_tVNDDbBfXx0nORXjehL0f { akean23d1n * f1 ; } ;
#endif
#ifndef typedef_kkw0h0uzlf
#define typedef_kkw0h0uzlf
typedef struct tag_tVNDDbBfXx0nORXjehL0f kkw0h0uzlf ;
#endif
#ifndef struct_emxArray_tag_tVNDDbBfXx0nORXjeh
#define struct_emxArray_tag_tVNDDbBfXx0nORXjeh
struct emxArray_tag_tVNDDbBfXx0nORXjeh { kkw0h0uzlf * data ; int32_T * size ;
int32_T allocatedSize ; int32_T numDimensions ; boolean_T canFreeData ; } ;
#endif
#ifndef typedef_jrxtexkjqq
#define typedef_jrxtexkjqq
typedef struct emxArray_tag_tVNDDbBfXx0nORXjeh jrxtexkjqq ;
#endif
#ifndef struct_tag_nwNlNAh44luWuWarnUt9lF
#define struct_tag_nwNlNAh44luWuWarnUt9lF
struct tag_nwNlNAh44luWuWarnUt9lF { akean23d1n * f1 ; } ;
#endif
#ifndef typedef_f2zhfwyqun
#define typedef_f2zhfwyqun
typedef struct tag_nwNlNAh44luWuWarnUt9lF f2zhfwyqun ;
#endif
#ifndef struct_emxArray_tag_nwNlNAh44luWuWarnU
#define struct_emxArray_tag_nwNlNAh44luWuWarnU
struct emxArray_tag_nwNlNAh44luWuWarnU { f2zhfwyqun data ; int32_T size [ 2 ]
; } ;
#endif
#ifndef typedef_f3xnlpfjxl
#define typedef_f3xnlpfjxl
typedef struct emxArray_tag_nwNlNAh44luWuWarnU f3xnlpfjxl ;
#endif
#ifndef struct_emxArray_b_tag_nwNlNAh44luWuWar
#define struct_emxArray_b_tag_nwNlNAh44luWuWar
struct emxArray_b_tag_nwNlNAh44luWuWar { f2zhfwyqun data ; int32_T size ; } ;
#endif
#ifndef typedef_ixviaac30n
#define typedef_ixviaac30n
typedef struct emxArray_b_tag_nwNlNAh44luWuWar ixviaac30n ;
#endif
#ifndef SS_UINT64
#define SS_UINT64 20
#endif
#ifndef SS_INT64
#define SS_INT64 21
#endif
typedef struct P_ P ;
#endif
