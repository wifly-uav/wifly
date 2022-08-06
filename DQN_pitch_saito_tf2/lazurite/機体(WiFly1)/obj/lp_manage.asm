;; Compile Options : /TML620504F /MS /near /IC:\LAZURI~1\LIBRAR~1\BM1383 /IC:\LAZURI~1\LIBRAR~1\BM1422 /IC:\LAZURI~1\LIBRAR~1\HARDWA~1 /IC:\LAZURI~1\LIBRAR~1\HARDWA~2 /IC:\LAZURI~1\LIBRAR~1\KXG03_~1 /IC:\LAZURI~1\LIBRAR~1\VL53L0X /IC:\LAZURI~1\LIBRAR~1\Wire /IC:\LAZURI~1\hardware\LAZURI~2 /IC:\LAZURI~1\hardware\LAZURI~2\lazurite /IC:\LAZURI~1\hardware\LAZURI~2\ML620Q~1 /IC:\LAZURI~1\hardware\LAZURI~2\ML620Q~1\clock /IC:\LAZURI~1\hardware\LAZURI~2\ML620Q~1\common /IC:\LAZURI~1\hardware\LAZURI~2\ML620Q~1\irq /IC:\LAZURI~1\hardware\LAZURI~2\ML620Q~1\lp /IC:\LAZURI~1\hardware\LAZURI~2\ML620Q~1\MCU_SM~1 /IC:\LAZURI~1\hardware\LAZURI~2\ML620Q~1\wdt /IC:\LAZURI~1\hardware\LAZURI~2\sub_ghz\ /D_ML620Q504 /DLAZURITE_MINI /DLAZURITE_IDE /DSUBGHZ /DPWR_LED /DLDO_CNT /SS 512 /SL 65 /SD /Oa /Ot /W 3 /Faobj\ /Lv 
;; Version Number  : Ver.3.53.1
;; File Name       : lp_manage.c

	type (ML620504F) 
	model small, near
	$$lp_setDeepHaltMode$lp_manage segment code 2h #0h
	$$lp_setHaltHMode$lp_manage segment code 2h #0h
	$$lp_setHaltMode$lp_manage segment code 2h #0h
	$$lp_setStopMode$lp_manage segment code 2h #0h
CVERSION 3.53.1
CGLOBAL 01H 03H 0000H "lp_setDeepHaltMode" 08H 02H 03H 00H 80H 00H 00H 00H 07H
CGLOBAL 01H 03H 0000H "lp_setHaltMode" 08H 02H 01H 00H 80H 00H 00H 00H 07H
CGLOBAL 01H 03H 0000H "lp_setStopMode" 08H 02H 00H 00H 80H 00H 00H 00H 07H
CGLOBAL 01H 03H 0000H "lp_setHaltHMode" 08H 02H 02H 00H 80H 00H 00H 00H 07H
CSTRUCTTAG 0000H 0000H 0000H 0008H 00000001H "_Notag"
CSTRUCTMEM 52H 00000001H 00000000H "b0" 02H 00H 00H
CSTRUCTMEM 52H 00000001H 00000001H "b1" 02H 00H 00H
CSTRUCTMEM 52H 00000001H 00000002H "b2" 02H 00H 00H
CSTRUCTMEM 52H 00000001H 00000003H "b3" 02H 00H 00H
CSTRUCTMEM 52H 00000001H 00000004H "b4" 02H 00H 00H
CSTRUCTMEM 52H 00000001H 00000005H "b5" 02H 00H 00H
CSTRUCTMEM 52H 00000001H 00000006H "b6" 02H 00H 00H
CSTRUCTMEM 52H 00000001H 00000007H "b7" 02H 00H 00H
CTYPEDEF 0000H 0000H 43H "_BYTE_FIELD" 04H 00H 05H 00H 00H
CFILE 0001H 00000022H "C:\\LAZURI~1\\hardware\\LAZURI~2\\ML620Q~1\\MCU_SM~1\\mcu.h"
CFILE 0002H 00000F42H "C:\\LazuriteIDE\\bin\\U8Dev\\Inc\\ml620504F.h"
CFILE 0003H 00000045H "C:\\LAZURI~1\\hardware\\LAZURI~2\\ML620Q~1\\common\\rdwr_reg.h"
CFILE 0004H 00000022H "C:\\LAZURI~1\\hardware\\lazurite_subghz\\ml620q504\\lp\\lp_manage.h"
CFILE 0000H 00000062H "C:\\LAZURI~1\\hardware\\lazurite_subghz\\ml620q504\\lp\\lp_manage.c"

	rseg $$lp_setStopMode$lp_manage
CFUNCTION 0

_lp_setStopMode	:
CBLOCK 0 1 32

;;{
CLINEA 0000H 0001H 0020H 0001H 0001H
;;*****************************************
;;	register/stack information
;;*****************************************
;;*****************************************

CBLOCK 0 2 32

;;	write_reg8( STPACP, 0x50 );
CLINEA 0000H 0001H 0022H 0002H 001CH
	mov	r0,	#050h
	st	r0,	0f008h

;;	write_reg8( STPACP, 0xA0 );
CLINEA 0000H 0001H 0023H 0002H 001CH
	mov	r0,	#0a0h
	st	r0,	0f008h

;;	set_bit( STP );
CLINEA 0000H 0001H 0028H 0002H 0010H
	sb	0f009h.1

;;	__asm("nop\n");
CLINEA 0000H 0001H 0029H 0002H 0010H
nop


;;	__asm("nop\n");
CLINEA 0000H 0001H 002AH 0002H 0010H
nop

CBLOCKEND 0 2 43

;;}
CLINEA 0000H 0001H 002BH 0001H 0001H
	rt
CBLOCKEND 0 1 43
CFUNCTIONEND 0


	rseg $$lp_setHaltHMode$lp_manage
CFUNCTION 2

_lp_setHaltHMode	:
CBLOCK 2 1 52

;;{
CLINEA 0000H 0001H 0034H 0001H 0001H
;;*****************************************
;;	register/stack information
;;*****************************************
;;*****************************************

CBLOCK 2 2 52

;;	set_bit( HLTH );
CLINEA 0000H 0001H 0039H 0002H 0011H
	sb	0f009h.3

;;	__asm("nop\n");
CLINEA 0000H 0001H 003AH 0002H 0010H
nop


;;	__asm("nop\n");
CLINEA 0000H 0001H 003BH 0002H 0010H
nop

CBLOCKEND 2 2 60

;;}
CLINEA 0000H 0001H 003CH 0001H 0001H
	rt
CBLOCKEND 2 1 60
CFUNCTIONEND 2


	rseg $$lp_setHaltMode$lp_manage
CFUNCTION 1

_lp_setHaltMode	:
CBLOCK 1 1 73

;;{
CLINEA 0000H 0001H 0049H 0001H 0001H
;;*****************************************
;;	register/stack information
;;*****************************************
;;*****************************************

CBLOCK 1 2 73

;;	set_bit( HLT );
CLINEA 0000H 0001H 004BH 0002H 0010H
	sb	0f009h.0

;;	__asm("nop\n");
CLINEA 0000H 0001H 004CH 0002H 0010H
nop


;;	__asm("nop\n");
CLINEA 0000H 0001H 004DH 0002H 0010H
nop

CBLOCKEND 1 2 78

;;}
CLINEA 0000H 0001H 004EH 0001H 0001H
	rt
CBLOCKEND 1 1 78
CFUNCTIONEND 1


	rseg $$lp_setDeepHaltMode$lp_manage
CFUNCTION 3

_lp_setDeepHaltMode	:
CBLOCK 3 1 87

;;{
CLINEA 0000H 0001H 0057H 0001H 0001H
;;*****************************************
;;	register/stack information
;;*****************************************
;;*****************************************

CBLOCK 3 2 87

;;	set_bit( DHLT );
CLINEA 0000H 0001H 005DH 0002H 0011H
	sb	0f009h.2

;;	__asm("nop\n");
CLINEA 0000H 0001H 005EH 0002H 0010H
nop


;;	__asm("nop\n");
CLINEA 0000H 0001H 005FH 0002H 0010H
nop

CBLOCKEND 3 2 96

;;}
CLINEA 0000H 0001H 0060H 0001H 0001H
	rt
CBLOCKEND 3 1 96
CFUNCTIONEND 3

	public _lp_setDeepHaltMode
	public _lp_setHaltMode
	public _lp_setStopMode
	public _lp_setHaltHMode
	extrn code near : _main

	end
