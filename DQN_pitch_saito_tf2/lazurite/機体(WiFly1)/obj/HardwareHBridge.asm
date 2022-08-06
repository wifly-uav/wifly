;; Compile Options : /TML620504F /MS /near /IC:\LAZURI~1\LIBRAR~1\BM1383 /IC:\LAZURI~1\LIBRAR~1\BM1422 /IC:\LAZURI~1\LIBRAR~1\HARDWA~1 /IC:\LAZURI~1\LIBRAR~1\HARDWA~2 /IC:\LAZURI~1\LIBRAR~1\KXG03_~1 /IC:\LAZURI~1\LIBRAR~1\VL53L0X /IC:\LAZURI~1\LIBRAR~1\Wire /IC:\LAZURI~1\hardware\LAZURI~2 /IC:\LAZURI~1\hardware\LAZURI~2\lazurite /IC:\LAZURI~1\hardware\LAZURI~2\ML620Q~1 /IC:\LAZURI~1\hardware\LAZURI~2\ML620Q~1\clock /IC:\LAZURI~1\hardware\LAZURI~2\ML620Q~1\common /IC:\LAZURI~1\hardware\LAZURI~2\ML620Q~1\irq /IC:\LAZURI~1\hardware\LAZURI~2\ML620Q~1\lp /IC:\LAZURI~1\hardware\LAZURI~2\ML620Q~1\MCU_SM~1 /IC:\LAZURI~1\hardware\LAZURI~2\ML620Q~1\wdt /IC:\LAZURI~1\hardware\LAZURI~2\sub_ghz\ /D_ML620Q504 /DLAZURITE_MINI /DLAZURITE_IDE /DSUBGHZ /DPWR_LED /DLDO_CNT /SS 512 /SL 65 /SD /Oa /Ot /W 3 /Faobj\ /Lv 
;; Version Number  : Ver.3.53.1
;; File Name       : HardwareHBridge.c

	type (ML620504F) 
	model small, near
	$$NVARHardwareHBridge segment data 2h #0h
	$$TABhhb$HardwareHBridge segment table 2h #0h
	$$hhb_attach$HardwareHBridge segment code 2h #0h
	$$hhb_close$HardwareHBridge segment code 2h #0h
	$$hhb_detach$HardwareHBridge segment code 2h #0h
	$$hhb_dt$HardwareHBridge segment code 2h #0h
	$$hhb_init$HardwareHBridge segment code 2h #0h
	$$hhb_start$HardwareHBridge segment code 2h #0h
	$$hhb_stop$HardwareHBridge segment code 2h #0h
	$$hhb_write$HardwareHBridge segment code 2h #0h
	$$hhp_update$HardwareHBridge segment code 2h #0h
CVERSION 3.53.1
CSGLOBAL 03H 0000H "hhp_update" 08H 02H 54H 00H 80H 00H 00H 00H 07H
CSGLOBAL 02H 0000H "hhb_detach" 08H 02H 4DH 00H 82H 0cH 00H 00H 00H
CSGLOBAL 03H 0000H "hhb_dt" 08H 02H 53H 00H 80H 04H 00H 00H 07H
CSGLOBAL 03H 0000H "hhb_write" 08H 02H 51H 00H 83H 0aH 00H 00H 07H
CSGLOBAL 03H 0000H "hhb_close" 08H 02H 50H 00H 80H 02H 00H 00H 07H
CSGLOBAL 03H 0000H "hhb_stop" 08H 02H 4FH 00H 80H 00H 00H 00H 07H
CSGLOBAL 03H 0000H "hhb_init" 08H 02H 4BH 00H 80H 04H 00H 00H 07H
CSGLOBAL 03H 0000H "hhb_start" 08H 02H 4EH 00H 80H 00H 00H 00H 07H
CSGLOBAL 02H 0000H "hhb_attach" 08H 02H 4CH 00H 82H 0eH 00H 00H 00H
CSTRUCTTAG 0000H 0000H 0001H 0009H 00000012H "_Notag"
CSTRUCTMEM 43H 00000002H 00000000H "init" 0AH 03H 00H 02H 42H 00H 00H 00H 00H 00H 07H
CSTRUCTMEM 42H 00000002H 00000002H "attach" 0AH 03H 00H 02H 43H 00H 00H 00H 00H 00H 00H
CSTRUCTMEM 42H 00000002H 00000004H "detach" 0AH 03H 00H 02H 44H 00H 00H 00H 00H 00H 00H
CSTRUCTMEM 43H 00000002H 00000006H "start" 0AH 03H 00H 02H 45H 00H 00H 00H 00H 00H 07H
CSTRUCTMEM 43H 00000002H 00000008H "stop" 0AH 03H 00H 02H 46H 00H 00H 00H 00H 00H 07H
CSTRUCTMEM 43H 00000002H 0000000AH "close" 0AH 03H 00H 02H 47H 00H 00H 00H 00H 00H 07H
CSTRUCTMEM 43H 00000002H 0000000CH "write" 0AH 03H 00H 02H 48H 00H 00H 00H 00H 00H 07H
CSTRUCTMEM 43H 00000002H 0000000EH "dt" 0AH 03H 00H 02H 49H 00H 00H 00H 00H 00H 07H
CSTRUCTMEM 43H 00000002H 00000010H "update" 0AH 03H 00H 02H 4AH 00H 00H 00H 00H 00H 07H
CSTRUCTTAG 0000H 0000H 0000H 0008H 00000001H "_Notag"
CSTRUCTMEM 52H 00000001H 00000000H "b0" 02H 00H 00H
CSTRUCTMEM 52H 00000001H 00000001H "b1" 02H 00H 00H
CSTRUCTMEM 52H 00000001H 00000002H "b2" 02H 00H 00H
CSTRUCTMEM 52H 00000001H 00000003H "b3" 02H 00H 00H
CSTRUCTMEM 52H 00000001H 00000004H "b4" 02H 00H 00H
CSTRUCTMEM 52H 00000001H 00000005H "b5" 02H 00H 00H
CSTRUCTMEM 52H 00000001H 00000006H "b6" 02H 00H 00H
CSTRUCTMEM 52H 00000001H 00000007H "b7" 02H 00H 00H
CTYPEDEF 0000H 0000H 43H "INT8" 02H 00H 00H
CTYPEDEF 0000H 0000H 43H "_Ptrdifft" 02H 00H 01H
CTYPEDEF 0000H 0000H 42H "bool" 02H 00H 00H
CTYPEDEF 0000H 0000H 42H "byte" 02H 00H 00H
CTYPEDEF 0000H 0000H 43H "INT32" 02H 00H 02H
CTYPEDEF 0000H 0000H 43H "INT16" 02H 00H 01H
CTYPEDEF 0000H 0000H 42H "_Sizet" 02H 00H 01H
CTYPEDEF 0000H 0000H 42H "BOOLEAN" 02H 00H 00H
CTYPEDEF 0000H 0000H 42H "UCHAR" 02H 00H 00H
CTYPEDEF 0000H 0000H 42H "size_t" 02H 00H 01H
CTYPEDEF 0000H 0000H 42H "uint8_t" 02H 00H 00H
CTYPEDEF 0000H 0000H 43H "int8_t" 02H 00H 00H
CTYPEDEF 0000H 0000H 43H "int16_t" 02H 00H 08H
CTYPEDEF 0000H 0000H 43H "int32_t" 02H 00H 02H
CTYPEDEF 0000H 0000H 42H "UINT8" 02H 00H 00H
CTYPEDEF 0000H 0000H 43H "HardwareHBridge" 04H 00H 05H 01H 00H
CTYPEDEF 0000H 0000H 43H "CHAR" 02H 00H 00H
CTYPEDEF 0000H 0000H 42H "UINT16" 02H 00H 01H
CTYPEDEF 0000H 0000H 42H "UINT32" 02H 00H 02H
CTYPEDEF 0000H 0000H 42H "boolean" 02H 00H 00H
CTYPEDEF 0000H 0000H 42H "word" 02H 00H 01H
CTYPEDEF 0000H 0000H 42H "BOOL" 02H 00H 00H
CTYPEDEF 0000H 0000H 42H "uint32_t" 02H 00H 02H
CTYPEDEF 0000H 0000H 43H "_BYTE_FIELD" 04H 00H 05H 00H 00H
CTYPEDEF 0000H 0000H 42H "uint16_t" 02H 00H 08H
CGLOBAL 02H 00H 0000H "ml620504f_tmout_to_pin" 05H 01H 00H 00H 00H 00H
CGLOBAL 01H 01H 0012H "hhb" 04H 00H 05H 01H 00H
CSGLOBAL 42H 0008H "dt" 05H 01H 04H 00H 00H 08H
CGLOBAL 02H 00H 0000H "ml620504f_pin_to_bit" 05H 01H 00H 00H 00H 00H
CGLOBAL 02H 00H 0000H "pin_to_pwm" 05H 01H 00H 00H 00H 00H
CGLOBAL 02H 01H 0000H "ml620504f_pin_to_port" 05H 01H 00H 00H 00H 01H
CFILE 0001H 0000007BH "C:\\LAZURI~1\\hardware\\LAZURI~2\\common.h"
CFILE 0002H 00000F42H "C:\\LazuriteIDE\\bin\\U8Dev\\Inc\\ml620504F.h"
CFILE 0003H 000000C9H "C:\\LazuriteIDE\\bin\\U8Dev\\Inc\\string.h"
CFILE 0004H 0000007AH "C:\\LazuriteIDE\\bin\\U8Dev\\Inc\\yvals.h"
CFILE 0005H 00000022H "C:\\LAZURI~1\\hardware\\LAZURI~2\\ML620Q~1\\MCU_SM~1\\mcu.h"
CFILE 0006H 00000045H "C:\\LAZURI~1\\hardware\\LAZURI~2\\ML620Q~1\\common\\rdwr_reg.h"
CFILE 0007H 00000028H "C:\\LAZURI~1\\LIBRAR~1\\HARDWA~1\\HardwareHBridge.h"
CFILE 0000H 000000C1H "C:\\LAZURI~1\\LIBRAR~1\\HARDWA~1\\HardwareHBridge.c"

	rseg $$hhb_init$HardwareHBridge
CFUNCTION 75

_hhb_init	:
CBLOCK 75 1 36

;;{
CLINEA 0000H 0001H 0024H 0001H 0001H
;;*****************************************
;;	register/stack information
;;*****************************************
;;*****************************************

	push	xr8
	mov	r8,	r0
	mov	er10,	er2
CBLOCK 75 2 36
CARGUMENT 46H 0001H 001CH "ch" 02H 00H 00H
CARGUMENT 46H 0002H 0029H "period" 02H 00H 01H

;;	if(ch>3) return;				// error
CLINEA 0000H 0001H 0025H 0002H 001DH
	cmp	r0,	#03h
	ble	_$L1
CBLOCKEND 75 2 47

;;}
CLINEA 0000H 0001H 002FH 0001H 0001H
_$L0 :
	pop	xr8
	rt

;;	if(ch>3) return;				// error
CLINEA 0000H 0000H 0025H 0002H 001DH
_$L1 :

;;	BLKCON1 |=  (unsigned char)(1 << ch);						// 	set_bit(DFTM0);   reset
CLINEA 0000H 0001H 0027H 0002H 0047H
	mov	er0,	#1 
	mov	r2,	r8
_$M2 :
	cmp	r2,	#07h
	ble	_$M1
	sllc	r1,	#07h
	sll	r0,	#07h
	add	r2,	#0f9h
	bne	_$M2
_$M1 :
	sll	r0,	r2
	l	r1,	0f069h
	or	r1,	r0
	st	r1,	0f069h

;;	BLKCON1 &= ~(unsigned char)(1 << ch);						// 	clear_bit(DFTM0);
CLINEA 0000H 0001H 0028H 0002H 0041H
	mov	er0,	#1 
	mov	r2,	r8
_$M4 :
	cmp	r2,	#07h
	ble	_$M3
	sllc	r1,	#07h
	sll	r0,	#07h
	add	r2,	#0f9h
	bne	_$M4
_$M3 :
	sll	r0,	r2
	xor	r0,	#0ffh
	l	r1,	0f069h
	and	r1,	r0
	st	r1,	0f069h

;;	*(&FT0CLKL + (ch << (5-sizeof(FT0CLKL)+1))) = 0x42;			//	FT0CLKL = 0x42;  HSCLK / 16
CLINEA 0000H 0001H 0029H 0002H 0055H
	mov	r0,	r8
	mov	r1,	#00h
	sllc	r1,	#05h
	sll	r0,	#05h
	mov	r2,	#042h
	st	r2,	0f40eh[er0]

;;	*(&FT0P    + (ch << (5-sizeof(FT0P)+1)))    = period;		//	FT0P = period;
CLINEA 0000H 0001H 002AH 0002H 0049H
	mov	r0,	r8
	mov	r1,	#00h
	sllc	r1,	#04h
	sll	r0,	#04h
	add	er0,	er0
	st	er10,	0f400h[er0]

;;	*(&FT0DT   + (ch << (5-sizeof(FT0DT)+1)))   = 1;			//	FT0DT = 1;  (for masking pulse)
CLINEA 0000H 0001H 002BH 0002H 0056H
	mov	r0,	r8
	mov	r1,	#00h
	sllc	r1,	#04h
	sll	r0,	#04h
	add	er0,	er0
	mov	er2,	#1 
	st	er2,	0f406h[er0]

;;	*(&FT0MODL + (ch << (5-sizeof(FT0MODL)+1))) = 0x42;			// PWM1, FTnDTEN = 1
CLINEA 0000H 0001H 002CH 0002H 004BH
	mov	r0,	r8
	mov	r1,	#00h
	sllc	r1,	#05h
	sll	r0,	#05h
	mov	r2,	#042h
	st	r2,	0f40ch[er0]

;;	dt[ch] = 1;
CLINEA 0000H 0001H 002DH 0002H 000CH
	mov	r0,	r8
	mov	r1,	#00h
	add	er0,	er0
	mov	er2,	#1 
	st	er2,	NEAR _dt[er0]

;;	return;
CLINEA 0000H 0001H 002EH 0002H 0008H
	bal	_$L0
CBLOCKEND 75 1 47
CFUNCTIONEND 75


	rseg $$hhb_attach$HardwareHBridge
CFUNCTION 76

_hhb_attach	:
CBLOCK 76 1 50

;;{
CLINEA 0000H 0001H 0032H 0001H 0001H
;;*****************************************
;;	register/stack information
;;*****************************************
	_pin$10	set	-2
	_port$4	set	-4
;;*****************************************

	push	fp
	mov	fp,	sp
	add	sp,	#-04
	push	xr4
	push	bp
	push	er8
	mov	r8,	r0
CBLOCK 76 2 50
CARGUMENT 46H 0001H 001CH "ch" 02H 00H 00H
CARGUMENT 46H 0001H 0015H "pin1" 02H 00H 00H
CARGUMENT 46H 0001H 0016H "pin2" 02H 00H 00H
CLOCAL 4AH 0001H 0000H 0002H "port_num" 02H 00H 00H
CLOCAL 46H 0001H 0019H 0002H "ftm" 02H 00H 00H
CLOCAL 42H 0002H 0004H 0002H "port" 04H 03H 00H 00H 00H
CLOCAL 46H 0001H 0018H 0002H "bit" 02H 00H 00H
CLOCAL 47H 0002H 0027H 0002H "i" 02H 00H 01H
CLOCAL 42H 0002H 0002H 0002H "pin" 05H 01H 02H 00H 00H 00H

;;	pin[0] = pin1;
CLINEA 0000H 0001H 0039H 0002H 000FH
	st	r1,	_pin$10[fp]

;;	pin[1] = pin2;
CLINEA 0000H 0001H 003AH 0002H 000FH
	st	r2,	_pin$10+01h[fp]

;;	if(ch > 3) return false;
CLINEA 0000H 0001H 003CH 0002H 0019H
	cmp	r0,	#03h
	ble	_$L4
	mov	r0,	#00h
CBLOCKEND 76 2 82

;;}
CLINEA 0000H 0001H 0052H 0001H 0001H
_$L3 :
	pop	er8
	pop	bp
	pop	xr4
	mov	sp,	fp
	pop	fp
	rt

;;	if(ch > 3) return false;
CLINEA 0000H 0000H 003CH 0002H 0019H
_$L4 :

;;	if((pin_to_pwm[pin[0]] == 0xFF) || (pin_to_pwm[pin[1]] == 0xFF)) return false;
CLINEA 0000H 0001H 003FH 0002H 004FH
	mov	r0,	r1
	mov	r1,	#00h
	l	r0,	NEAR _pin_to_pwm[er0]
	cmp	r0,	#0ffh
	beq	_$L7
	l	r0,	_pin$10+01h[fp]
	l	r0,	NEAR _pin_to_pwm[er0]
	cmp	r0,	#0ffh
	bne	_$L6
_$L7 :
	mov	r0,	#00h

;;	if((pin_to_pwm[pin[0]] == 0xFF) || (pin_to_pwm[pin[1]] == 0xFF)) return false;
CLINEA 0000H 0000H 003FH 0006H 0009H
	bal	_$L3
_$L6 :

;;	for(i=0;i<2;i++)
CLINEA 0000H 0001H 0042H 0006H 0009H
	mov	er6,	#0 	;; _li$8

;;	for(i=0;i<2;i++)
CLINEA 0000H 0000H 0042H 000EH 0010H
_$L15 :
CBLOCK 76 3 67

;;		ftm = pin_to_pwm[pin[i]];
CLINEA 0000H 0001H 0044H 0003H 001BH
	mov	bp,	er6
	add	bp,	fp
	l	r0,	-2[bp]
	mov	r1,	#00h
	l	r2,	NEAR _pin_to_pwm[er0]
	mov	r5,	r2	;; _lftm$2

;;		port = (unsigned char *)ml620504f_pin_to_port[port_num];
CLINEA 0000H 0001H 0046H 0003H 003AH
	mov	r0,	r2
	l	r12,	NEAR _ml620504f_tmout_to_pin[er0]
	mov	r13,	#00h
	mov	er0,	bp
	add	er0,	bp
	l	er2,	NEAR _ml620504f_pin_to_port[er0]
	st	er2,	_port$4[fp]

;;		bit = ml620504f_pin_to_bit[port_num];
CLINEA 0000H 0001H 0047H 0003H 0027H
	mov	er2,	bp
	l	r4,	NEAR _ml620504f_pin_to_bit[er2]

;;		*(port+1) &= ~bit;		// PnDIR  = 0
CLINEA 0000H 0001H 0049H 0003H 0023H
	l	bp,	NEAR _ml620504f_pin_to_port[er0]
	mov	r0,	r4
	xor	r0,	#0ffh
	l	r1,	1[bp]
	and	r1,	r0
	st	r1,	1[bp]

;;		*(port+2) |= bit;		// PnCON0 = 1
CLINEA 0000H 0001H 004AH 0003H 0022H
	l	bp,	_port$4[fp]
	l	r0,	2[bp]
	or	r0,	r4
	st	r0,	2[bp]

;;		*(port+3) |= bit;		// PnCON1 = 1
CLINEA 0000H 0001H 004BH 0003H 0022H
	l	bp,	_port$4[fp]
	l	r0,	3[bp]
	or	r0,	r4
	st	r0,	3[bp]

;;		*(port+4) |= bit;		// PnMOD0 = 1
CLINEA 0000H 0001H 004CH 0003H 0022H
	l	bp,	_port$4[fp]
	l	r0,	4[bp]
	or	r0,	r4
	st	r0,	4[bp]

;;		*(port+5) |= bit;		// PnMOD1 = 1
CLINEA 0000H 0001H 004DH 0003H 0022H
	l	bp,	_port$4[fp]
	l	r0,	5[bp]
	or	r0,	r4
	st	r0,	5[bp]

;;		*(&FTO0SL + ftm) = (unsigned char)((ch << 1) + i);
CLINEA 0000H 0001H 004FH 0003H 0034H
	mov	r0,	r8
	sll	r0,	#01h
	add	r0,	r6
	mov	r12,	r5
	mov	r13,	#00h
	st	r0,	-2944[bp]
CBLOCKEND 76 3 80

;;	for(i=0;i<2;i++)
CLINEA 0000H 0000H 0042H 000EH 0010H
	add	er6,	#1 

;;	for(i=0;i<2;i++)
CLINEA 0000H 0000H 0042H 000AH 000DH
	cmp	r6,	#02h
	cmpc	r7,	#00h
	blts	_$L15

;;	return true;
CLINEA 0000H 0001H 0051H 0002H 000DH
	mov	r0,	#01h
	b	_$L3
CBLOCKEND 76 1 82
CFUNCTIONEND 76


	rseg $$hhb_detach$HardwareHBridge
CFUNCTION 77

_hhb_detach	:
CBLOCK 77 1 85

;;{
CLINEA 0000H 0001H 0055H 0001H 0001H
;;*****************************************
;;	register/stack information
;;*****************************************
	_pin$10	set	-2
	_level$12	set	-4
;;*****************************************

	push	fp
	mov	fp,	sp
	add	sp,	#-04
	push	xr4
	push	bp
CBLOCK 77 2 85
CARGUMENT 46H 0001H 0014H "pin1" 02H 00H 00H
CARGUMENT 46H 0001H 0015H "pin2" 02H 00H 00H
CARGUMENT 46H 0001H 0016H "level1" 02H 00H 00H
CARGUMENT 46H 0001H 0017H "level2" 02H 00H 00H
CLOCAL 4AH 0001H 0000H 0002H "port_num" 02H 00H 00H
CLOCAL 4AH 0001H 0000H 0002H "ftm" 02H 00H 00H
CLOCAL 46H 0002H 0025H 0002H "port" 04H 03H 00H 00H 00H
CLOCAL 46H 0001H 0018H 0002H "bit" 02H 00H 00H
CLOCAL 47H 0002H 0027H 0002H "i" 02H 00H 01H
CLOCAL 42H 0002H 0002H 0002H "pin" 05H 01H 02H 00H 00H 00H
CLOCAL 42H 0002H 0004H 0002H "level" 05H 01H 02H 00H 00H 00H

;;	pin[0] = pin1;
CLINEA 0000H 0001H 005DH 0002H 000FH
	st	r0,	_pin$10[fp]

;;	pin[1] = pin2;
CLINEA 0000H 0001H 005EH 0002H 000FH
	st	r1,	_pin$10+01h[fp]

;;	level[0] = level1;
CLINEA 0000H 0001H 005FH 0002H 0013H
	st	r2,	_level$12[fp]

;;	level[1] = level2;
CLINEA 0000H 0001H 0060H 0002H 0013H
	st	r3,	_level$12+01h[fp]

;;	if((pin_to_pwm[pin[0]] == 0xFF) || (pin_to_pwm[pin[1]] == 0xFF)) return false;
CLINEA 0000H 0001H 0062H 0002H 004FH
	mov	r1,	#00h
	l	r0,	NEAR _pin_to_pwm[er0]
	cmp	r0,	#0ffh
	beq	_$L21
	l	r0,	_pin$10+01h[fp]
	l	r0,	NEAR _pin_to_pwm[er0]
	cmp	r0,	#0ffh
	bne	_$L20
_$L21 :
	mov	r0,	#00h
CBLOCKEND 77 2 118

;;}
CLINEA 0000H 0001H 0076H 0001H 0001H
_$L19 :
	pop	bp
	pop	xr4
	mov	sp,	fp
	pop	fp
	rt

;;	if((pin_to_pwm[pin[0]] == 0xFF) || (pin_to_pwm[pin[1]] == 0xFF)) return false;
CLINEA 0000H 0000H 0062H 0006H 0009H
_$L20 :

;;	for(i=0;i<2;i++)
CLINEA 0000H 0001H 0065H 0006H 0009H
	mov	er6,	#0 	;; _li$8

;;	for(i=0;i<2;i++)
CLINEA 0000H 0000H 0065H 000EH 0010H
_$L29 :
CBLOCK 77 3 102

;;		port = (unsigned char *)ml620504f_pin_to_port[port_num];
CLINEA 0000H 0001H 0069H 0003H 003AH
	mov	bp,	er6
	add	bp,	fp
	l	r0,	-2[bp]
	mov	r1,	#00h
	l	r0,	NEAR _pin_to_pwm[er0]
	l	r12,	NEAR _ml620504f_tmout_to_pin[er0]
	mov	r13,	#00h
	mov	er0,	bp
	add	er0,	bp
	l	er0,	NEAR _ml620504f_pin_to_port[er0]
	mov	er2,	er0	;; _lport$4

;;		bit = ml620504f_pin_to_bit[port_num];
CLINEA 0000H 0001H 006AH 0003H 0027H
	l	r0,	NEAR _ml620504f_pin_to_bit[bp]
	mov	r4,	r0	;; _lbit$6

;;		if(level[i] == 0)
CLINEA 0000H 0001H 006BH 0003H 0013H
	mov	bp,	er6
	add	bp,	fp
	l	r0,	-4[bp]
	bne	_$L33

;;			*(port+0) &= ~bit;		// PnD    = 0
CLINEA 0000H 0001H 006CH 0004H 0024H
	mov	r0,	r4
	xor	r0,	#0ffh
	l	r1,	[er2]
	and	r0,	r1

;;		else
CLINEA 0000H 0001H 006DH 0003H 0006H
	bal	_$L35
_$L33 :

;;			*(port+0) |= bit;		// PnD    = 1
CLINEA 0000H 0001H 006EH 0004H 0023H
	l	r0,	[er2]
	or	r0,	r4
_$L35 :
	st	r0,	[er2]

;;		*(port+1) &= ~bit;		// PnDIR  = 0
CLINEA 0000H 0001H 006FH 0003H 0023H
	mov	r0,	r4
	xor	r0,	#0ffh
	l	r1,	01h[er2]
	and	r1,	r0
	st	r1,	01h[er2]

;;		*(port+2) |= bit;		// PnCON0 = 1
CLINEA 0000H 0001H 0070H 0003H 0022H
	l	r0,	02h[er2]
	or	r0,	r4
	st	r0,	02h[er2]

;;		*(port+3) |= bit;		// PnCON1 = 1
CLINEA 0000H 0001H 0071H 0003H 0022H
	l	r0,	03h[er2]
	or	r0,	r4
	st	r0,	03h[er2]

;;		*(port+4) &= ~bit;		// PnMOD0 = 0
CLINEA 0000H 0001H 0072H 0003H 0023H
	mov	r0,	r4
	xor	r0,	#0ffh
	l	r1,	04h[er2]
	and	r1,	r0
	st	r1,	04h[er2]

;;		*(port+5) &= ~bit;		// PnMOD1 = 0
CLINEA 0000H 0001H 0073H 0003H 0023H
	mov	r0,	r4
	xor	r0,	#0ffh
	l	r1,	05h[er2]
	and	r1,	r0
	st	r1,	05h[er2]
CBLOCKEND 77 3 116

;;	for(i=0;i<2;i++)
CLINEA 0000H 0000H 0065H 000EH 0010H
	add	er6,	#1 

;;	for(i=0;i<2;i++)
CLINEA 0000H 0000H 0065H 000AH 000DH
	cmp	r6,	#02h
	cmpc	r7,	#00h
	bges	_$M7
	b	_$L29
_$M7 :

;;	return true;
CLINEA 0000H 0001H 0075H 0002H 000DH
	mov	r0,	#01h
	b	_$L19
CBLOCKEND 77 1 118
CFUNCTIONEND 77


	rseg $$hhb_start$HardwareHBridge
CFUNCTION 78

_hhb_start	:
CBLOCK 78 1 120

;;{
CLINEA 0000H 0001H 0078H 0001H 0001H
;;*****************************************
;;	register/stack information
;;*****************************************
;;*****************************************

CBLOCK 78 2 120
CARGUMENT 46H 0001H 0014H "ch" 02H 00H 00H

;;	if(ch>3) return;				// error
CLINEA 0000H 0001H 0079H 0002H 001DH
	cmp	r0,	#03h
	bgt	_$L36

;;	*(&FT0CON0 + (ch << (5-sizeof(FT0CON0)+1))) = 1;			// set_bit(FT0RUN);
CLINEA 0000H 0001H 007AH 0002H 0047H
	mov	r1,	#00h
	sllc	r1,	#05h
	sll	r0,	#05h
	mov	r2,	#01h
	st	r2,	0f40ah[er0]
CBLOCKEND 78 2 123

;;}
CLINEA 0000H 0001H 007BH 0001H 0001H
_$L36 :
	rt
CBLOCKEND 78 1 123
CFUNCTIONEND 78


	rseg $$hhb_stop$HardwareHBridge
CFUNCTION 79

_hhb_stop	:
CBLOCK 79 1 125

;;{
CLINEA 0000H 0001H 007DH 0001H 0001H
;;*****************************************
;;	register/stack information
;;*****************************************
;;*****************************************

CBLOCK 79 2 125
CARGUMENT 46H 0001H 0014H "ch" 02H 00H 00H

;;	if(ch>3) return;				// error
CLINEA 0000H 0001H 007EH 0002H 001DH
	cmp	r0,	#03h
	bgt	_$L39

;;	*(&FT0CON0 + (ch << (5-sizeof(FT0CON0)+1))) = 0;			// clear_bit(FT0RUN);
CLINEA 0000H 0001H 007FH 0002H 0049H
	mov	r1,	#00h
	sllc	r1,	#05h
	sll	r0,	#05h
	mov	r2,	#00h
	st	r2,	0f40ah[er0]
CBLOCKEND 79 2 128

;;}
CLINEA 0000H 0001H 0080H 0001H 0001H
_$L39 :
	rt
CBLOCKEND 79 1 128
CFUNCTIONEND 79


	rseg $$hhb_close$HardwareHBridge
CFUNCTION 80

_hhb_close	:
CBLOCK 80 1 130

;;{
CLINEA 0000H 0001H 0082H 0001H 0001H
;;*****************************************
;;	register/stack information
;;*****************************************
;;*****************************************

	push	er8
	mov	r8,	r0
CBLOCK 80 2 130
CARGUMENT 46H 0001H 001CH "ch" 02H 00H 00H

;;	BLKCON1 |=  (unsigned char)(1 << ch);						// 	set_bit(DFTM0);   reset
CLINEA 0000H 0001H 0083H 0002H 0047H
	mov	er0,	#1 
	mov	r2,	r8
_$M12 :
	cmp	r2,	#07h
	ble	_$M11
	sllc	r1,	#07h
	sll	r0,	#07h
	add	r2,	#0f9h
	bne	_$M12
_$M11 :
	sll	r0,	r2
	l	r1,	0f069h
	or	r1,	r0
	st	r1,	0f069h

;;	if(ch>3) return;				// error
CLINEA 0000H 0001H 0084H 0002H 001DH
CBLOCKEND 80 2 133

;;}
CLINEA 0000H 0001H 0085H 0001H 0001H
	pop	er8
	rt
CBLOCKEND 80 1 133
CFUNCTIONEND 80


	rseg $$hhb_write$HardwareHBridge
CFUNCTION 81

_hhb_write	:
CBLOCK 81 1 135

;;{
CLINEA 0000H 0001H 0087H 0001H 0001H
;;*****************************************
;;	register/stack information
;;*****************************************
	_time$2	set	4
;;*****************************************

	push	lr
	push	fp
	mov	fp,	sp
	push	xr4
	push	er8
	mov	r8,	r0
CBLOCK 81 2 135
CRET 0008H
CARGUMENT 46H 0001H 001CH "ch" 02H 00H 00H
CARGUMENT 43H 0004H 0004H "time" 02H 00H 02H

;;	if(ch>3) return;				// error
CLINEA 0000H 0001H 0088H 0002H 001DH
	cmp	r0,	#03h
	ble	_$M14
	b	_$L45
_$M14 :

;;	if(time == 0)
CLINEA 0000H 0001H 008AH 0002H 000EH
	l	er0,	_time$2[fp]
	l	er2,	_time$2+02h[fp]
	cmp	r0,	#00h
	cmpc	r1,	#00h
	cmpc	r2,	#00h
	cmpc	r3,	#00h
	bne	_$L48
CBLOCK 81 3 139

;;		*(&FT0EA + (ch << (5-sizeof(FT0EA)+1))) = 0;
CLINEA 0000H 0001H 008CH 0003H 002EH
	mov	r0,	r8
	mov	r1,	#00h
	sllc	r1,	#04h
	sll	r0,	#04h
	add	er0,	er0
	mov	er2,	#0 
	st	er2,	0f402h[er0]

;;		*(&FT0EB + (ch << (5-sizeof(FT0EB)+1))) = 0;
CLINEA 0000H 0001H 008DH 0003H 002EH
	mov	r0,	r8
	mov	r1,	#00h
	sllc	r1,	#04h
	sll	r0,	#04h
	add	er0,	er0

;;	else if(time > 0)
CLINEA 0000H 0001H 008FH 0002H 0012H
	b	_$L59
_$L48 :
	cmp	r0,	#00h
	cmpc	r1,	#00h
	cmpc	r2,	#00h
	cmpc	r3,	#00h
	bles	_$L51
CBLOCK 81 4 144

;;		*(&FT0EA + (ch << (5-sizeof(FT0EA)+1))) = (unsigned short)OVF16BIT(time + dt[ch]);
CLINEA 0000H 0000H 0091H 0003H 0054H
	mov	r0,	r8
	mov	r1,	#00h
	add	er0,	er0
	l	er0,	NEAR _dt[er0]
	mov	er2,	#0 
	l	er4,	_time$2[fp]
	l	er6,	_time$2+02h[fp]
	add	er0,	er4
	addc	r2,	r6
	addc	r3,	r7
	cmp	r0,	#0ffh
	cmpc	r1,	#0ffh
	cmpc	r2,	#00h
	cmpc	r3,	#00h
	bles	_$L53
	mov	er4,	#-1
	bal	_$L55
_$L53 :
	mov	r0,	r8
	mov	r1,	#00h
	add	er0,	er0
	l	er0,	NEAR _dt[er0]
	mov	er2,	#0 
	add	er0,	er4
	addc	r2,	r6
	addc	r3,	r7
	cmp	r0,	#01h
	cmpc	r1,	#00h
	cmpc	r2,	#0ffh
	cmpc	r3,	#0ffh
	bges	_$L56
	mov	er0,	#1 
	bal	_$L58
_$L56 :
	mov	r0,	r8
	mov	r1,	#00h
	add	er0,	er0
	l	er0,	NEAR _dt[er0]
	add	er0,	er4
_$L58 :
	mov	er4,	er0
_$L55 :
	mov	r0,	r8
	mov	r1,	#00h
	sllc	r1,	#04h
	sll	r0,	#04h
	add	er0,	er0
	st	er4,	0f402h[er0]

;;		*(&FT0EB + (ch << (5-sizeof(FT0EB)+1))) = 0;
CLINEA 0000H 0001H 0092H 0003H 002EH
	mov	r0,	r8
	mov	r1,	#00h
	sllc	r1,	#04h
	sll	r0,	#04h
	add	er0,	er0
	mov	er2,	#0 
CBLOCKEND 81 4 147

;;	else
CLINEA 0000H 0001H 0095H 0002H 0005H
	bal	_$L59
_$L51 :
CBLOCK 81 5 150

;;		*(&FT0EA + (ch << (5-sizeof(FT0EA)+1))) = 0;
CLINEA 0000H 0001H 0097H 0003H 002EH
	mov	r0,	r8
	mov	r1,	#00h
	sllc	r1,	#04h
	sll	r0,	#04h
	add	er0,	er0
	mov	er2,	#0 
	st	er2,	0f402h[er0]

;;		*(&FT0EB + (ch << (5-sizeof(FT0EB)+1))) = (unsigned short)OVF16BIT(abs(time) + dt[ch]);
CLINEA 0000H 0000H 0098H 0003H 0059H
	l	er0,	_time$2[fp]
	l	er2,	_time$2+02h[fp]
	bl	_abs
	l	er0,	_time$2[fp]
	l	er2,	_time$2+02h[fp]
	bl	_abs
	l	er0,	_time$2[fp]
	l	er2,	_time$2+02h[fp]
	bl	_abs
	mov	er4,	er0
	mov	r0,	r8
	mov	r1,	#00h
	add	er0,	er0
	l	er2,	NEAR _dt[er0]
	add	er2,	er4
	mov	r0,	r8
	mov	r1,	#00h
	sllc	r1,	#04h
	sll	r0,	#04h
	add	er0,	er0
CBLOCKEND 81 5 153

;;	}
CLINEA 0000H 0000H 0099H 0002H 0002H
_$L59 :
	st	er2,	0f404h[er0]

;;	if( (*(&FT0CON1 + (ch << (5-sizeof(FT0CON1)+1))) & 0x01) == 0)
CLINEA 0000H 0001H 009BH 0002H 003FH
	mov	r0,	r8
	mov	r1,	#00h
	sllc	r1,	#05h
	sll	r0,	#05h
	l	r0,	0f40bh[er0]
	tb	r0.0
	bne	_$L66
CBLOCKEND 81 3 159
CBLOCK 81 6 156

;;		*(&FT0CON1 + (ch << (5-sizeof(FT0CON1)+1))) |= 0x01;
CLINEA 0000H 0001H 009DH 0003H 0036H
	mov	r0,	r8
	mov	r1,	#00h
	sllc	r1,	#05h
	sll	r0,	#05h
	l	r2,	0f40bh[er0]
	or	r2,	#01h
	st	r2,	0f40bh[er0]
CBLOCKEND 81 6 158

;;	}
CLINEA 0000H 0000H 009EH 0002H 0002H
_$L66 :
CBLOCKEND 81 2 159

;;}
CLINEA 0000H 0001H 009FH 0001H 0001H
_$L45 :
	pop	er8
	pop	xr4
	mov	sp,	fp
	pop	fp
	pop	pc
CBLOCKEND 81 1 159
CFUNCTIONEND 81


	rseg $$hhb_dt$HardwareHBridge
CFUNCTION 83

_hhb_dt	:
CBLOCK 83 1 162

;;{
CLINEA 0000H 0001H 00A2H 0001H 0001H
;;*****************************************
;;	register/stack information
;;*****************************************
;;*****************************************

	push	xr8
	mov	r8,	r0
	mov	er10,	er2
CBLOCK 83 2 162
CARGUMENT 46H 0001H 001CH "ch" 02H 00H 00H
CARGUMENT 46H 0002H 0029H "deadtime" 02H 00H 01H

;;	if(ch>3) return;				// error.
CLINEA 0000H 0001H 00A3H 0002H 001EH
	cmp	r0,	#03h
	ble	_$L69
CBLOCKEND 83 2 168

;;}
CLINEA 0000H 0001H 00A8H 0001H 0001H
_$L68 :
	pop	xr8
	rt

;;	if(ch>3) return;				// error.
CLINEA 0000H 0000H 00A3H 0002H 001EH
_$L69 :

;;	if(deadtime == 0) return;		// error!! output signals are shorted.
CLINEA 0000H 0001H 00A4H 0002H 0042H
	mov	er2,	er2
	beq	_$L68

;;	*(&FT0DT + (ch << (5-sizeof(FT0DT)+1))) = deadtime;			// FTnST0 = One shot, FTnDTEN = 1, PWM2
CLINEA 0000H 0001H 00A5H 0002H 005EH
	mov	r0,	r8
	mov	r1,	#00h
	sllc	r1,	#04h
	sll	r0,	#04h
	add	er0,	er0
	st	er10,	0f406h[er0]

;;	dt[ch] = deadtime;
CLINEA 0000H 0001H 00A6H 0002H 0013H
	mov	r0,	r8
	mov	r1,	#00h
	add	er0,	er0
	st	er10,	NEAR _dt[er0]

;;	return;
CLINEA 0000H 0001H 00A7H 0002H 0008H
	bal	_$L68
CBLOCKEND 83 1 168
CFUNCTIONEND 83


	rseg $$hhp_update$HardwareHBridge
CFUNCTION 84

_hhp_update	:
CBLOCK 84 1 172

;;{
CLINEA 0000H 0001H 00ACH 0001H 0001H
;;*****************************************
;;	register/stack information
;;*****************************************
;;*****************************************

CBLOCK 84 2 172

;;	set_bit(FT0UD);
CLINEA 0000H 0001H 00ADH 0002H 0010H
	sb	0f40bh.0

;;	set_bit(FT1UD);
CLINEA 0000H 0001H 00AEH 0002H 0010H
	sb	0f42bh.0

;;	set_bit(FT2UD);
CLINEA 0000H 0001H 00AFH 0002H 0010H
	sb	0f44bh.0

;;	set_bit(FT3UD);	
CLINEA 0000H 0001H 00B0H 0002H 0011H
	sb	0f46bh.0
CBLOCKEND 84 2 177

;;}
CLINEA 0000H 0001H 00B1H 0001H 0001H
	rt
CBLOCKEND 84 1 177
CFUNCTIONEND 84

	extrn code near : _abs
	public _hhb
	extrn table near : _ml620504f_tmout_to_pin
	extrn table near : _ml620504f_pin_to_bit
	extrn table near : _pin_to_pwm
	extrn table near : _ml620504f_pin_to_port
	extrn code near : _main

	rseg $$TABhhb$HardwareHBridge
_hhb :
	dw	_hhb_init
	dw	_hhb_attach
	dw	_hhb_detach
	dw	_hhb_start
	dw	_hhb_stop
	dw	_hhb_close
	dw	_hhb_write
	dw	_hhb_dt
	dw	_hhp_update

	rseg $$NVARHardwareHBridge
_dt :
	ds	08h

	end
