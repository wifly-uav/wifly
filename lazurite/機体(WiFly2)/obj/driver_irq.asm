;; Compile Options : /TML620504F /MS /near /IC:\LAZURI~1\LIBRAR~1\BM1383 /IC:\LAZURI~1\LIBRAR~1\BM1422 /IC:\LAZURI~1\LIBRAR~1\HARDWA~1 /IC:\LAZURI~1\LIBRAR~1\HARDWA~2 /IC:\LAZURI~1\LIBRAR~1\KXG03_~1 /IC:\LAZURI~1\LIBRAR~1\VL53L0X /IC:\LAZURI~1\LIBRAR~1\Wire /IC:\LAZURI~1\hardware\LAZURI~2 /IC:\LAZURI~1\hardware\LAZURI~2\lazurite /IC:\LAZURI~1\hardware\LAZURI~2\ML620Q~1 /IC:\LAZURI~1\hardware\LAZURI~2\ML620Q~1\clock /IC:\LAZURI~1\hardware\LAZURI~2\ML620Q~1\common /IC:\LAZURI~1\hardware\LAZURI~2\ML620Q~1\irq /IC:\LAZURI~1\hardware\LAZURI~2\ML620Q~1\lp /IC:\LAZURI~1\hardware\LAZURI~2\ML620Q~1\MCU_SM~1 /IC:\LAZURI~1\hardware\LAZURI~2\ML620Q~1\wdt /IC:\LAZURI~1\hardware\LAZURI~2\sub_ghz\ /D_ML620Q504 /DLAZURITE_MINI /DLAZURITE_IDE /DSUBGHZ /DPWR_LED /DLDO_CNT /SS 512 /SL 65 /SD /Oa /Ot /W 3 /Faobj\ /Lv 
;; Version Number  : Ver.3.53.1
;; File Name       : driver_irq.c

	type (ML620504F) 
	model small, near
	$$NVARdriver_irq segment data 2h #0h
	$$NINITVAR segment data 2h #0h
	$$NINITTAB segment table 2h any
	$$_intNullHdr$driver_irq segment code 2h #0h
	$$dis_interrupts$driver_irq segment code 2h #0h
	$$enb_interrupts$driver_irq segment code 2h #0h
	$$getMIE$driver_irq segment code 2h #0h
	$$irq_init$driver_irq segment code 2h #0h
	$$irq_sethandler$driver_irq segment code 2h #0h
	$$rst_interrupts$driver_irq segment code 2h #0h
	$$s_handlerCMP0INT$driver_irq segment code 2h #0h
	$$s_handlerCMP1INT$driver_irq segment code 2h #0h
	$$s_handlerEXI0INT$driver_irq segment code 2h #0h
	$$s_handlerEXI1INT$driver_irq segment code 2h #0h
	$$s_handlerEXI2INT$driver_irq segment code 2h #0h
	$$s_handlerEXI3INT$driver_irq segment code 2h #0h
	$$s_handlerEXI4INT$driver_irq segment code 2h #0h
	$$s_handlerEXI5INT$driver_irq segment code 2h #0h
	$$s_handlerEXI6INT$driver_irq segment code 2h #0h
	$$s_handlerEXI7INT$driver_irq segment code 2h #0h
	$$s_handlerFTM0INT$driver_irq segment code 2h #0h
	$$s_handlerFTM1INT$driver_irq segment code 2h #0h
	$$s_handlerFTM2INT$driver_irq segment code 2h #0h
	$$s_handlerFTM3INT$driver_irq segment code 2h #0h
	$$s_handlerI2C0INT$driver_irq segment code 2h #0h
	$$s_handlerI2C1INT$driver_irq segment code 2h #0h
	$$s_handlerLOSCINT$driver_irq segment code 2h #0h
	$$s_handlerLTBC0INT$driver_irq segment code 2h #0h
	$$s_handlerLTBC1INT$driver_irq segment code 2h #0h
	$$s_handlerLTBC2INT$driver_irq segment code 2h #0h
	$$s_handlerMD0INT$driver_irq segment code 2h #0h
	$$s_handlerRADINT$driver_irq segment code 2h #0h
	$$s_handlerSADINT$driver_irq segment code 2h #0h
	$$s_handlerSIO0INT$driver_irq segment code 2h #0h
	$$s_handlerSIOF0INT$driver_irq segment code 2h #0h
	$$s_handlerTM0INT$driver_irq segment code 2h #0h
	$$s_handlerTM1INT$driver_irq segment code 2h #0h
	$$s_handlerTM2INT$driver_irq segment code 2h #0h
	$$s_handlerTM3INT$driver_irq segment code 2h #0h
	$$s_handlerTM4INT$driver_irq segment code 2h #0h
	$$s_handlerTM5INT$driver_irq segment code 2h #0h
	$$s_handlerTM6INT$driver_irq segment code 2h #0h
	$$s_handlerTM7INT$driver_irq segment code 2h #0h
	$$s_handlerUA0INT$driver_irq segment code 2h #0h
	$$s_handlerUA1INT$driver_irq segment code 2h #0h
	$$s_handlerUAF0INT$driver_irq segment code 2h #0h
	$$s_handlerVLSINT$driver_irq segment code 2h #0h
	$$s_handlerWDTINT$driver_irq segment code 2h #0h
CVERSION 3.53.1
CSGLOBAL 03H 0000H "s_handlerLTBC2INT" 08H 02H 36H 00H 91H 0aH 00H 00H 07H
CGLOBAL 01H 03H 0000H "dis_interrupts" 08H 02H 0DH 00H 81H 04H 00H 00H 07H
CGLOBAL 01H 03H 0000H "irq_init" 08H 02H 08H 00H 80H 02H 00H 00H 07H
CSGLOBAL 03H 0000H "s_handlerUA1INT" 08H 02H 1FH 00H 91H 0aH 00H 00H 07H
CSGLOBAL 03H 0000H "s_handlerTM1INT" 08H 02H 29H 00H 91H 0aH 00H 00H 07H
CSGLOBAL 03H 0000H "s_handlerCMP0INT" 08H 02H 26H 00H 91H 0aH 00H 00H 07H
CSGLOBAL 03H 0000H "s_handlerUA0INT" 08H 02H 1EH 00H 91H 0aH 00H 00H 07H
CSGLOBAL 03H 0000H "s_handlerTM0INT" 08H 02H 28H 00H 91H 0aH 00H 00H 07H
CSGLOBAL 03H 0000H "s_handlerCMP1INT" 08H 02H 27H 00H 91H 0aH 00H 00H 07H
CSGLOBAL 03H 0000H "s_handlerVLSINT" 08H 02H 22H 00H 91H 0aH 00H 00H 07H
CSGLOBAL 03H 0000H "s_handlerFTM2INT" 08H 02H 32H 00H 91H 0aH 00H 00H 07H
CSGLOBAL 03H 0000H "s_handlerFTM3INT" 08H 02H 33H 00H 91H 0aH 00H 00H 07H
CSGLOBAL 03H 0000H "s_handlerI2C0INT" 08H 02H 1CH 00H 91H 0aH 00H 00H 07H
CSGLOBAL 03H 0000H "s_handlerSIO0INT" 08H 02H 1AH 00H 91H 0aH 00H 00H 07H
CSGLOBAL 03H 0000H "s_handlerSADINT" 08H 02H 24H 00H 91H 0aH 00H 00H 07H
CSGLOBAL 03H 0000H "s_handlerI2C1INT" 08H 02H 1DH 00H 91H 0aH 00H 00H 07H
CSGLOBAL 03H 0000H "s_handlerTM3INT" 08H 02H 2BH 00H 91H 0aH 00H 00H 07H
CSGLOBAL 03H 0000H "s_handlerTM2INT" 08H 02H 2AH 00H 91H 0aH 00H 00H 07H
CSGLOBAL 03H 0000H "s_handlerEXI4INT" 08H 02H 16H 00H 91H 0aH 00H 00H 07H
CSGLOBAL 03H 0000H "s_handlerUAF0INT" 08H 02H 20H 00H 91H 0aH 00H 00H 07H
CSGLOBAL 03H 0000H "s_handlerEXI5INT" 08H 02H 17H 00H 91H 0aH 00H 00H 07H
CSGLOBAL 03H 0000H "s_handlerLOSCINT" 08H 02H 21H 00H 91H 0aH 00H 00H 07H
CSGLOBAL 03H 0000H "s_handlerEXI0INT" 08H 02H 12H 00H 91H 0aH 00H 00H 07H
CSGLOBAL 03H 0000H "s_handlerMD0INT" 08H 02H 23H 00H 91H 0aH 00H 00H 07H
CSGLOBAL 03H 0000H "s_handlerEXI1INT" 08H 02H 13H 00H 91H 0aH 00H 00H 07H
CGLOBAL 01H 02H 0000H "getMIE" 08H 02H 63H 00H 80H 00H 00H 00H 00H
CSGLOBAL 03H 0000H "s_handlerEXI6INT" 08H 02H 18H 00H 91H 0aH 00H 00H 07H
CGLOBAL 01H 03H 0000H "enb_interrupts" 08H 02H 0CH 00H 80H 00H 00H 00H 07H
CSGLOBAL 03H 0000H "s_handlerEXI7INT" 08H 02H 19H 00H 91H 0aH 00H 00H 07H
CSGLOBAL 03H 0000H "s_handlerWDTINT" 08H 02H 11H 00H 91H 0aH 00H 00H 07H
CGLOBAL 01H 03H 0000H "rst_interrupts" 08H 02H 0EH 00H 80H 00H 00H 00H 07H
CSGLOBAL 03H 0000H "s_handlerEXI2INT" 08H 02H 14H 00H 91H 0aH 00H 00H 07H
CGLOBAL 01H 03H 0000H "irq_sethandler" 08H 02H 0AH 00H 80H 04H 00H 00H 01H
CSGLOBAL 03H 0000H "s_handlerEXI3INT" 08H 02H 15H 00H 91H 0aH 00H 00H 07H
CSGLOBAL 03H 0000H "s_handlerTM5INT" 08H 02H 2DH 00H 91H 0aH 00H 00H 07H
CSGLOBAL 03H 0000H "s_handlerRADINT" 08H 02H 25H 00H 91H 0aH 00H 00H 07H
CSGLOBAL 03H 0000H "s_handlerSIOF0INT" 08H 02H 1BH 00H 91H 0aH 00H 00H 07H
CSGLOBAL 03H 0000H "s_handlerTM4INT" 08H 02H 2CH 00H 91H 0aH 00H 00H 07H
CSGLOBAL 03H 0000H "s_handlerLTBC0INT" 08H 02H 34H 00H 91H 0aH 00H 00H 07H
CSGLOBAL 03H 0000H "s_handlerLTBC1INT" 08H 02H 35H 00H 91H 0aH 00H 00H 07H
CSGLOBAL 03H 0000H "s_handlerTM7INT" 08H 02H 2FH 00H 91H 0aH 00H 00H 07H
CSGLOBAL 03H 0000H "s_handlerTM6INT" 08H 02H 2EH 00H 91H 0aH 00H 00H 07H
CGLOBAL 01H 03H 0000H "_intNullHdr" 08H 02H 0BH 00H 80H 00H 00H 00H 07H
CSGLOBAL 03H 0000H "s_handlerFTM0INT" 08H 02H 30H 00H 91H 0aH 00H 00H 07H
CSGLOBAL 03H 0000H "s_handlerFTM1INT" 08H 02H 31H 00H 91H 0aH 00H 00H 07H
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
CSGLOBAL 42H 0002H "di_flag" 02H 00H 08H
CSGLOBAL 43H 004CH "_sIrqHdr" 0DH 01H 26H 00H 03H 00H 02H 0FH 00H 10H 00H 00H 00H 07H
CFILE 0001H 00000022H "C:\\LAZURI~1\\hardware\\LAZURI~2\\ML620Q~1\\MCU_SM~1\\mcu.h"
CFILE 0002H 00000F42H "C:\\LazuriteIDE\\bin\\U8Dev\\Inc\\ml620504F.h"
CFILE 0003H 00000045H "C:\\LAZURI~1\\hardware\\LAZURI~2\\ML620Q~1\\common\\rdwr_reg.h"
CFILE 0004H 0000006FH "C:\\LAZURI~1\\hardware\\lazurite_subghz\\ml620q504\\driver_irq.h"
CFILE 0005H 00000331H "C:\\LAZURI~1\\hardware\\LAZURI~2\\ML620Q~1\\irq\\irq.h"
CFILE 0000H 00000272H "C:\\LAZURI~1\\hardware\\lazurite_subghz\\ml620q504\\driver_irq.c"

	rseg $$_intNullHdr$driver_irq
CFUNCTION 11

__intNullHdr	:
CBLOCK 11 1 143

;;{
CLINEA 0000H 0001H 008FH 0001H 0001H
;;*****************************************
;;	register/stack information
;;*****************************************
;;*****************************************

CBLOCK 11 2 143
CBLOCKEND 11 2 145

;;}
CLINEA 0000H 0000H 0091H 0001H 0001H
	rt
CBLOCKEND 11 1 145
CFUNCTIONEND 11


	rseg $$s_handlerWDTINT$driver_irq
CFUNCTION 17

_s_handlerWDTINT	:
CBLOCK 17 1 148

;;{
CLINEA 0000H 0001H 0094H 0001H 0001H
;;*****************************************
;;	register/stack information
;;*****************************************
;;*****************************************

	push	lr, ea
	push	xr0
	l	r0,	DSR
	push	r0
CBLOCK 17 2 148

;;	_sIrqHdr[IRQ_NO_WDTINT]();
CLINEA 0000H 0001H 0098H 0002H 001BH
	l	er0,	NEAR __sIrqHdr
	bl	er0
CBLOCKEND 17 2 153

;;}
CLINEA 0000H 0001H 0099H 0001H 0001H
	pop	r0
	st	r0,	DSR
	pop	xr0
	pop	ea, lr
	rti
CBLOCKEND 17 1 153
CFUNCTIONEND 17


	rseg $$s_handlerEXI0INT$driver_irq
CFUNCTION 18

_s_handlerEXI0INT	:
CBLOCK 18 1 156

;;{
CLINEA 0000H 0001H 009CH 0001H 0001H
;;*****************************************
;;	register/stack information
;;*****************************************
;;*****************************************

	push	lr, ea
	push	xr0
	l	r0,	DSR
	push	r0
CBLOCK 18 2 156

;;	irq_ext0_dis(); 
CLINEA 0000H 0001H 00A0H 0002H 0011H
	rb	0f011h.0

;;	_sIrqHdr[IRQ_NO_EXI0INT]();
CLINEA 0000H 0001H 00A1H 0002H 001CH
	l	er0,	NEAR __sIrqHdr+02h
	bl	er0

;;	irq_ext0_ena();
CLINEA 0000H 0001H 00A2H 0002H 0010H
	sb	0f011h.0
CBLOCKEND 18 2 164

;;}
CLINEA 0000H 0001H 00A4H 0001H 0001H
	pop	r0
	st	r0,	DSR
	pop	xr0
	pop	ea, lr
	rti
CBLOCKEND 18 1 164
CFUNCTIONEND 18


	rseg $$s_handlerEXI1INT$driver_irq
CFUNCTION 19

_s_handlerEXI1INT	:
CBLOCK 19 1 167

;;{
CLINEA 0000H 0001H 00A7H 0001H 0001H
;;*****************************************
;;	register/stack information
;;*****************************************
;;*****************************************

	push	lr, ea
	push	xr0
	l	r0,	DSR
	push	r0
CBLOCK 19 2 167

;;	irq_ext1_dis(); 
CLINEA 0000H 0001H 00ABH 0002H 0011H
	rb	0f011h.1

;;	_sIrqHdr[IRQ_NO_EXI1INT]();
CLINEA 0000H 0001H 00ACH 0002H 001CH
	l	er0,	NEAR __sIrqHdr+04h
	bl	er0

;;	irq_ext1_ena();
CLINEA 0000H 0001H 00ADH 0002H 0010H
	sb	0f011h.1
CBLOCKEND 19 2 174

;;}
CLINEA 0000H 0001H 00AEH 0001H 0001H
	pop	r0
	st	r0,	DSR
	pop	xr0
	pop	ea, lr
	rti
CBLOCKEND 19 1 174
CFUNCTIONEND 19


	rseg $$s_handlerEXI2INT$driver_irq
CFUNCTION 20

_s_handlerEXI2INT	:
CBLOCK 20 1 177

;;{
CLINEA 0000H 0001H 00B1H 0001H 0001H
;;*****************************************
;;	register/stack information
;;*****************************************
;;*****************************************

	push	lr, ea
	push	xr0
	l	r0,	DSR
	push	r0
CBLOCK 20 2 177

;;	irq_ext2_dis(); 
CLINEA 0000H 0001H 00B5H 0002H 0011H
	rb	0f011h.2

;;	_sIrqHdr[IRQ_NO_EXI2INT]();
CLINEA 0000H 0001H 00B6H 0002H 001CH
	l	er0,	NEAR __sIrqHdr+06h
	bl	er0

;;	irq_ext2_ena();
CLINEA 0000H 0001H 00B7H 0002H 0010H
	sb	0f011h.2
CBLOCKEND 20 2 184

;;}
CLINEA 0000H 0001H 00B8H 0001H 0001H
	pop	r0
	st	r0,	DSR
	pop	xr0
	pop	ea, lr
	rti
CBLOCKEND 20 1 184
CFUNCTIONEND 20


	rseg $$s_handlerEXI3INT$driver_irq
CFUNCTION 21

_s_handlerEXI3INT	:
CBLOCK 21 1 187

;;{
CLINEA 0000H 0001H 00BBH 0001H 0001H
;;*****************************************
;;	register/stack information
;;*****************************************
;;*****************************************

	push	lr, ea
	push	xr0
	l	r0,	DSR
	push	r0
CBLOCK 21 2 187

;;	irq_ext3_dis(); 
CLINEA 0000H 0001H 00BFH 0002H 0011H
	rb	0f011h.3

;;	_sIrqHdr[IRQ_NO_EXI3INT]();
CLINEA 0000H 0001H 00C0H 0002H 001CH
	l	er0,	NEAR __sIrqHdr+08h
	bl	er0

;;	irq_ext3_ena();
CLINEA 0000H 0001H 00C1H 0002H 0010H
	sb	0f011h.3
CBLOCKEND 21 2 194

;;}
CLINEA 0000H 0001H 00C2H 0001H 0001H
	pop	r0
	st	r0,	DSR
	pop	xr0
	pop	ea, lr
	rti
CBLOCKEND 21 1 194
CFUNCTIONEND 21


	rseg $$s_handlerEXI4INT$driver_irq
CFUNCTION 22

_s_handlerEXI4INT	:
CBLOCK 22 1 197

;;{
CLINEA 0000H 0001H 00C5H 0001H 0001H
;;*****************************************
;;	register/stack information
;;*****************************************
;;*****************************************

	push	lr, ea
	push	xr0
	l	r0,	DSR
	push	r0
CBLOCK 22 2 197

;;	irq_ext4_dis(); 
CLINEA 0000H 0001H 00C9H 0002H 0011H
	rb	0f011h.4

;;	_sIrqHdr[IRQ_NO_EXI4INT]();
CLINEA 0000H 0001H 00CAH 0002H 001CH
	l	er0,	NEAR __sIrqHdr+0ah
	bl	er0

;;	irq_ext4_ena();
CLINEA 0000H 0001H 00CBH 0002H 0010H
	sb	0f011h.4
CBLOCKEND 22 2 204

;;}
CLINEA 0000H 0001H 00CCH 0001H 0001H
	pop	r0
	st	r0,	DSR
	pop	xr0
	pop	ea, lr
	rti
CBLOCKEND 22 1 204
CFUNCTIONEND 22


	rseg $$s_handlerEXI5INT$driver_irq
CFUNCTION 23

_s_handlerEXI5INT	:
CBLOCK 23 1 207

;;{
CLINEA 0000H 0001H 00CFH 0001H 0001H
;;*****************************************
;;	register/stack information
;;*****************************************
;;*****************************************

	push	lr, ea
	push	xr0
	l	r0,	DSR
	push	r0
CBLOCK 23 2 207

;;	irq_ext5_dis(); 
CLINEA 0000H 0001H 00D3H 0002H 0011H
	rb	0f011h.5

;;	_sIrqHdr[IRQ_NO_EXI5INT]();
CLINEA 0000H 0001H 00D4H 0002H 001CH
	l	er0,	NEAR __sIrqHdr+0ch
	bl	er0

;;	irq_ext5_ena();
CLINEA 0000H 0001H 00D5H 0002H 0010H
	sb	0f011h.5
CBLOCKEND 23 2 214

;;}
CLINEA 0000H 0001H 00D6H 0001H 0001H
	pop	r0
	st	r0,	DSR
	pop	xr0
	pop	ea, lr
	rti
CBLOCKEND 23 1 214
CFUNCTIONEND 23


	rseg $$s_handlerEXI6INT$driver_irq
CFUNCTION 24

_s_handlerEXI6INT	:
CBLOCK 24 1 217

;;{
CLINEA 0000H 0001H 00D9H 0001H 0001H
;;*****************************************
;;	register/stack information
;;*****************************************
;;*****************************************

	push	lr, ea
	push	xr0
	l	r0,	DSR
	push	r0
CBLOCK 24 2 217

;;	irq_ext6_dis(); 
CLINEA 0000H 0001H 00DDH 0002H 0011H
	rb	0f011h.6

;;	_sIrqHdr[IRQ_NO_EXI6INT]();
CLINEA 0000H 0001H 00DEH 0002H 001CH
	l	er0,	NEAR __sIrqHdr+0eh
	bl	er0

;;	irq_ext6_ena();
CLINEA 0000H 0001H 00DFH 0002H 0010H
	sb	0f011h.6
CBLOCKEND 24 2 224

;;}
CLINEA 0000H 0001H 00E0H 0001H 0001H
	pop	r0
	st	r0,	DSR
	pop	xr0
	pop	ea, lr
	rti
CBLOCKEND 24 1 224
CFUNCTIONEND 24


	rseg $$s_handlerEXI7INT$driver_irq
CFUNCTION 25

_s_handlerEXI7INT	:
CBLOCK 25 1 227

;;{
CLINEA 0000H 0001H 00E3H 0001H 0001H
;;*****************************************
;;	register/stack information
;;*****************************************
;;*****************************************

	push	lr, ea
	push	xr0
	l	r0,	DSR
	push	r0
CBLOCK 25 2 227

;;	irq_ext7_dis(); 
CLINEA 0000H 0001H 00E7H 0002H 0011H
	rb	0f011h.7

;;	_sIrqHdr[IRQ_NO_EXI7INT]();
CLINEA 0000H 0001H 00E8H 0002H 001CH
	l	er0,	NEAR __sIrqHdr+010h
	bl	er0

;;	irq_ext7_ena();
CLINEA 0000H 0001H 00E9H 0002H 0010H
	sb	0f011h.7
CBLOCKEND 25 2 234

;;}
CLINEA 0000H 0001H 00EAH 0001H 0001H
	pop	r0
	st	r0,	DSR
	pop	xr0
	pop	ea, lr
	rti
CBLOCKEND 25 1 234
CFUNCTIONEND 25


	rseg $$s_handlerSIO0INT$driver_irq
CFUNCTION 26

_s_handlerSIO0INT	:
CBLOCK 26 1 237

;;{
CLINEA 0000H 0001H 00EDH 0001H 0001H
;;*****************************************
;;	register/stack information
;;*****************************************
;;*****************************************

	push	lr, ea
	push	xr0
	l	r0,	DSR
	push	r0
CBLOCK 26 2 237

;;	irq_sio0_dis();
CLINEA 0000H 0001H 00F1H 0002H 0010H
	rb	0f012h.0

;;	_sIrqHdr[IRQ_NO_SIO0INT]();
CLINEA 0000H 0001H 00F2H 0002H 001CH
	l	er0,	NEAR __sIrqHdr+012h
	bl	er0

;;	irq_sio0_ena();
CLINEA 0000H 0001H 00F3H 0002H 0010H
	sb	0f012h.0
CBLOCKEND 26 2 244

;;}
CLINEA 0000H 0001H 00F4H 0001H 0001H
	pop	r0
	st	r0,	DSR
	pop	xr0
	pop	ea, lr
	rti
CBLOCKEND 26 1 244
CFUNCTIONEND 26


	rseg $$s_handlerSIOF0INT$driver_irq
CFUNCTION 27

_s_handlerSIOF0INT	:
CBLOCK 27 1 247

;;{
CLINEA 0000H 0001H 00F7H 0001H 0001H
;;*****************************************
;;	register/stack information
;;*****************************************
;;*****************************************

	push	lr, ea
	push	xr0
	l	r0,	DSR
	push	r0
CBLOCK 27 2 247

;;	irq_siof0_dis();
CLINEA 0000H 0001H 00FBH 0002H 0011H
	rb	0f012h.1

;;	_sIrqHdr[IRQ_NO_SIOF0INT]();
CLINEA 0000H 0001H 00FCH 0002H 001DH
	l	er0,	NEAR __sIrqHdr+014h
	bl	er0

;;	irq_siof0_ena();
CLINEA 0000H 0001H 00FDH 0002H 0011H
	sb	0f012h.1
CBLOCKEND 27 2 254

;;}
CLINEA 0000H 0001H 00FEH 0001H 0001H
	pop	r0
	st	r0,	DSR
	pop	xr0
	pop	ea, lr
	rti
CBLOCKEND 27 1 254
CFUNCTIONEND 27


	rseg $$s_handlerI2C0INT$driver_irq
CFUNCTION 28

_s_handlerI2C0INT	:
CBLOCK 28 1 257

;;{
CLINEA 0000H 0001H 0101H 0001H 0001H
;;*****************************************
;;	register/stack information
;;*****************************************
;;*****************************************

	push	lr, ea
	push	xr0
	l	r0,	DSR
	push	r0
CBLOCK 28 2 257

;;	irq_i2c0_dis();
CLINEA 0000H 0001H 0105H 0002H 0010H
	rb	0f012h.2

;;	_sIrqHdr[IRQ_NO_I2C0INT]();
CLINEA 0000H 0001H 0106H 0002H 001CH
	l	er0,	NEAR __sIrqHdr+016h
	bl	er0

;;	irq_i2c0_ena();
CLINEA 0000H 0001H 0107H 0002H 0010H
	sb	0f012h.2
CBLOCKEND 28 2 264

;;}
CLINEA 0000H 0001H 0108H 0001H 0001H
	pop	r0
	st	r0,	DSR
	pop	xr0
	pop	ea, lr
	rti
CBLOCKEND 28 1 264
CFUNCTIONEND 28


	rseg $$s_handlerI2C1INT$driver_irq
CFUNCTION 29

_s_handlerI2C1INT	:
CBLOCK 29 1 267

;;{
CLINEA 0000H 0001H 010BH 0001H 0001H
;;*****************************************
;;	register/stack information
;;*****************************************
;;*****************************************

	push	lr, ea
	push	xr0
	l	r0,	DSR
	push	r0
CBLOCK 29 2 267

;;	irq_i2c1_dis();
CLINEA 0000H 0001H 010FH 0002H 0010H
	rb	0f012h.3

;;	_sIrqHdr[IRQ_NO_I2C1INT]();
CLINEA 0000H 0001H 0110H 0002H 001CH
	l	er0,	NEAR __sIrqHdr+018h
	bl	er0

;;	irq_i2c1_ena();
CLINEA 0000H 0001H 0111H 0002H 0010H
	sb	0f012h.3
CBLOCKEND 29 2 274

;;}
CLINEA 0000H 0001H 0112H 0001H 0001H
	pop	r0
	st	r0,	DSR
	pop	xr0
	pop	ea, lr
	rti
CBLOCKEND 29 1 274
CFUNCTIONEND 29


	rseg $$s_handlerUA0INT$driver_irq
CFUNCTION 30

_s_handlerUA0INT	:
CBLOCK 30 1 277

;;{
CLINEA 0000H 0001H 0115H 0001H 0001H
;;*****************************************
;;	register/stack information
;;*****************************************
;;*****************************************

	push	lr, ea
	push	xr0
	l	r0,	DSR
	push	r0
CBLOCK 30 2 277

;;	irq_ua0_dis();
CLINEA 0000H 0001H 0119H 0002H 000FH
	rb	0f012h.4

;;	_sIrqHdr[IRQ_NO_UA0INT]();
CLINEA 0000H 0001H 011AH 0002H 001BH
	l	er0,	NEAR __sIrqHdr+01ah
	bl	er0

;;	irq_ua0_ena();
CLINEA 0000H 0001H 011BH 0002H 000FH
	sb	0f012h.4
CBLOCKEND 30 2 284

;;}
CLINEA 0000H 0001H 011CH 0001H 0001H
	pop	r0
	st	r0,	DSR
	pop	xr0
	pop	ea, lr
	rti
CBLOCKEND 30 1 284
CFUNCTIONEND 30


	rseg $$s_handlerUA1INT$driver_irq
CFUNCTION 31

_s_handlerUA1INT	:
CBLOCK 31 1 287

;;{
CLINEA 0000H 0001H 011FH 0001H 0001H
;;*****************************************
;;	register/stack information
;;*****************************************
;;*****************************************

	push	lr, ea
	push	xr0
	l	r0,	DSR
	push	r0
CBLOCK 31 2 287

;;	irq_ua1_dis();
CLINEA 0000H 0001H 0123H 0002H 000FH
	rb	0f012h.5

;;	_sIrqHdr[IRQ_NO_UA1INT]();
CLINEA 0000H 0001H 0124H 0002H 001BH
	l	er0,	NEAR __sIrqHdr+01ch
	bl	er0

;;	irq_ua1_ena();
CLINEA 0000H 0001H 0125H 0002H 000FH
	sb	0f012h.5
CBLOCKEND 31 2 294

;;}
CLINEA 0000H 0001H 0126H 0001H 0001H
	pop	r0
	st	r0,	DSR
	pop	xr0
	pop	ea, lr
	rti
CBLOCKEND 31 1 294
CFUNCTIONEND 31


	rseg $$s_handlerUAF0INT$driver_irq
CFUNCTION 32

_s_handlerUAF0INT	:
CBLOCK 32 1 297

;;{
CLINEA 0000H 0001H 0129H 0001H 0001H
;;*****************************************
;;	register/stack information
;;*****************************************
;;*****************************************

	push	lr, ea
	push	xr0
	l	r0,	DSR
	push	r0
CBLOCK 32 2 297

;;	irq_uaf0_dis();
CLINEA 0000H 0001H 012DH 0002H 0010H
	rb	0f012h.6

;;	_sIrqHdr[IRQ_NO_UAF0INT]();
CLINEA 0000H 0001H 012EH 0002H 001CH
	l	er0,	NEAR __sIrqHdr+01eh
	bl	er0

;;	irq_uaf0_ena();
CLINEA 0000H 0001H 012FH 0002H 0010H
	sb	0f012h.6
CBLOCKEND 32 2 304

;;}
CLINEA 0000H 0001H 0130H 0001H 0001H
	pop	r0
	st	r0,	DSR
	pop	xr0
	pop	ea, lr
	rti
CBLOCKEND 32 1 304
CFUNCTIONEND 32


	rseg $$s_handlerLOSCINT$driver_irq
CFUNCTION 33

_s_handlerLOSCINT	:
CBLOCK 33 1 307

;;{
CLINEA 0000H 0001H 0133H 0001H 0001H
;;*****************************************
;;	register/stack information
;;*****************************************
;;*****************************************

	push	lr, ea
	push	xr0
	l	r0,	DSR
	push	r0
CBLOCK 33 2 307

;;	irq_losc_dis();
CLINEA 0000H 0001H 0137H 0002H 0010H
	rb	0f013h.5

;;	_sIrqHdr[IRQ_NO_LOSCINT]();
CLINEA 0000H 0001H 0138H 0002H 001CH
	l	er0,	NEAR __sIrqHdr+020h
	bl	er0

;;	irq_losc_ena();
CLINEA 0000H 0001H 0139H 0002H 0010H
	sb	0f013h.5
CBLOCKEND 33 2 314

;;}
CLINEA 0000H 0001H 013AH 0001H 0001H
	pop	r0
	st	r0,	DSR
	pop	xr0
	pop	ea, lr
	rti
CBLOCKEND 33 1 314
CFUNCTIONEND 33


	rseg $$s_handlerVLSINT$driver_irq
CFUNCTION 34

_s_handlerVLSINT	:
CBLOCK 34 1 317

;;{
CLINEA 0000H 0001H 013DH 0001H 0001H
;;*****************************************
;;	register/stack information
;;*****************************************
;;*****************************************

	push	lr, ea
	push	xr0
	l	r0,	DSR
	push	r0
CBLOCK 34 2 317

;;    irq_vls_dis();
CLINEA 0000H 0001H 0141H 0005H 0012H
	rb	0f013h.6

;;	_sIrqHdr[IRQ_NO_VLSINT]();
CLINEA 0000H 0001H 0142H 0002H 001BH
	l	er0,	NEAR __sIrqHdr+022h
	bl	er0

;;	irq_vls_ena();
CLINEA 0000H 0001H 0143H 0002H 000FH
	sb	0f013h.6
CBLOCKEND 34 2 324

;;}
CLINEA 0000H 0001H 0144H 0001H 0001H
	pop	r0
	st	r0,	DSR
	pop	xr0
	pop	ea, lr
	rti
CBLOCKEND 34 1 324
CFUNCTIONEND 34


	rseg $$s_handlerMD0INT$driver_irq
CFUNCTION 35

_s_handlerMD0INT	:
CBLOCK 35 1 327

;;{
CLINEA 0000H 0001H 0147H 0001H 0001H
;;*****************************************
;;	register/stack information
;;*****************************************
;;*****************************************

	push	lr, ea
	push	xr0
	l	r0,	DSR
	push	r0
CBLOCK 35 2 327

;;	irq_md0_dis();
CLINEA 0000H 0001H 014BH 0002H 000FH
	rb	0f013h.7

;;	_sIrqHdr[IRQ_NO_MD0INT]();
CLINEA 0000H 0001H 014CH 0002H 001BH
	l	er0,	NEAR __sIrqHdr+024h
	bl	er0

;;	irq_md0_ena();
CLINEA 0000H 0001H 014DH 0002H 000FH
	sb	0f013h.7
CBLOCKEND 35 2 334

;;}
CLINEA 0000H 0001H 014EH 0001H 0001H
	pop	r0
	st	r0,	DSR
	pop	xr0
	pop	ea, lr
	rti
CBLOCKEND 35 1 334
CFUNCTIONEND 35


	rseg $$s_handlerSADINT$driver_irq
CFUNCTION 36

_s_handlerSADINT	:
CBLOCK 36 1 337

;;{
CLINEA 0000H 0001H 0151H 0001H 0001H
;;*****************************************
;;	register/stack information
;;*****************************************
;;*****************************************

	push	lr, ea
	push	xr0
	l	r0,	DSR
	push	r0
CBLOCK 36 2 337

;;	irq_sad_dis();
CLINEA 0000H 0001H 0155H 0002H 000FH
	rb	0f014h.0

;;	_sIrqHdr[IRQ_NO_SADINT]();
CLINEA 0000H 0001H 0156H 0002H 001BH
	l	er0,	NEAR __sIrqHdr+026h
	bl	er0

;;	irq_sad_ena();
CLINEA 0000H 0001H 0157H 0002H 000FH
	sb	0f014h.0
CBLOCKEND 36 2 344

;;}
CLINEA 0000H 0001H 0158H 0001H 0001H
	pop	r0
	st	r0,	DSR
	pop	xr0
	pop	ea, lr
	rti
CBLOCKEND 36 1 344
CFUNCTIONEND 36


	rseg $$s_handlerRADINT$driver_irq
CFUNCTION 37

_s_handlerRADINT	:
CBLOCK 37 1 347

;;{
CLINEA 0000H 0001H 015BH 0001H 0001H
;;*****************************************
;;	register/stack information
;;*****************************************
;;*****************************************

	push	lr, ea
	push	xr0
	l	r0,	DSR
	push	r0
CBLOCK 37 2 347

;;	irq_rad_dis();
CLINEA 0000H 0001H 015FH 0002H 000FH
	rb	0f014h.1

;;	_sIrqHdr[IRQ_NO_RADINT]();
CLINEA 0000H 0001H 0160H 0002H 001BH
	l	er0,	NEAR __sIrqHdr+028h
	bl	er0

;;	irq_rad_ena();
CLINEA 0000H 0001H 0161H 0002H 000FH
	sb	0f014h.1
CBLOCKEND 37 2 354

;;}
CLINEA 0000H 0001H 0162H 0001H 0001H
	pop	r0
	st	r0,	DSR
	pop	xr0
	pop	ea, lr
	rti
CBLOCKEND 37 1 354
CFUNCTIONEND 37


	rseg $$s_handlerCMP0INT$driver_irq
CFUNCTION 38

_s_handlerCMP0INT	:
CBLOCK 38 1 357

;;{
CLINEA 0000H 0001H 0165H 0001H 0001H
;;*****************************************
;;	register/stack information
;;*****************************************
;;*****************************************

	push	lr, ea
	push	xr0
	l	r0,	DSR
	push	r0
CBLOCK 38 2 357

;;	irq_cmp0_dis();
CLINEA 0000H 0001H 0169H 0002H 0010H
	rb	0f014h.4

;;	_sIrqHdr[IRQ_NO_CMP0INT]();
CLINEA 0000H 0001H 016AH 0002H 001CH
	l	er0,	NEAR __sIrqHdr+02ah
	bl	er0

;;	irq_cmp0_ena();
CLINEA 0000H 0001H 016BH 0002H 0010H
	sb	0f014h.4
CBLOCKEND 38 2 364

;;}
CLINEA 0000H 0001H 016CH 0001H 0001H
	pop	r0
	st	r0,	DSR
	pop	xr0
	pop	ea, lr
	rti
CBLOCKEND 38 1 364
CFUNCTIONEND 38


	rseg $$s_handlerCMP1INT$driver_irq
CFUNCTION 39

_s_handlerCMP1INT	:
CBLOCK 39 1 367

;;{
CLINEA 0000H 0001H 016FH 0001H 0001H
;;*****************************************
;;	register/stack information
;;*****************************************
;;*****************************************

	push	lr, ea
	push	xr0
	l	r0,	DSR
	push	r0
CBLOCK 39 2 367

;;	irq_cmp1_dis();
CLINEA 0000H 0001H 0173H 0002H 0010H
	rb	0f014h.5

;;	_sIrqHdr[IRQ_NO_CMP1INT]();
CLINEA 0000H 0001H 0174H 0002H 001CH
	l	er0,	NEAR __sIrqHdr+02ch
	bl	er0

;;	irq_cmp1_ena();
CLINEA 0000H 0001H 0175H 0002H 0010H
	sb	0f014h.5
CBLOCKEND 39 2 374

;;}
CLINEA 0000H 0001H 0176H 0001H 0001H
	pop	r0
	st	r0,	DSR
	pop	xr0
	pop	ea, lr
	rti
CBLOCKEND 39 1 374
CFUNCTIONEND 39


	rseg $$s_handlerTM0INT$driver_irq
CFUNCTION 40

_s_handlerTM0INT	:
CBLOCK 40 1 377

;;{
CLINEA 0000H 0001H 0179H 0001H 0001H
;;*****************************************
;;	register/stack information
;;*****************************************
;;*****************************************

	push	lr, ea
	push	xr0
	l	r0,	DSR
	push	r0
CBLOCK 40 2 377

;;	irq_tm0_dis();
CLINEA 0000H 0001H 017DH 0002H 000FH
	rb	0f015h.0

;;	_sIrqHdr[IRQ_NO_TM0INT]();
CLINEA 0000H 0001H 017EH 0002H 001BH
	l	er0,	NEAR __sIrqHdr+02eh
	bl	er0

;;	irq_tm0_ena();
CLINEA 0000H 0001H 017FH 0002H 000FH
	sb	0f015h.0
CBLOCKEND 40 2 384

;;}
CLINEA 0000H 0001H 0180H 0001H 0001H
	pop	r0
	st	r0,	DSR
	pop	xr0
	pop	ea, lr
	rti
CBLOCKEND 40 1 384
CFUNCTIONEND 40


	rseg $$s_handlerTM1INT$driver_irq
CFUNCTION 41

_s_handlerTM1INT	:
CBLOCK 41 1 387

;;{
CLINEA 0000H 0001H 0183H 0001H 0001H
;;*****************************************
;;	register/stack information
;;*****************************************
;;*****************************************

	push	lr, ea
	push	xr0
	l	r0,	DSR
	push	r0
CBLOCK 41 2 387

;;	irq_tm1_dis();
CLINEA 0000H 0001H 0187H 0002H 000FH
	rb	0f015h.1

;;	_sIrqHdr[IRQ_NO_TM1INT]();
CLINEA 0000H 0001H 0188H 0002H 001BH
	l	er0,	NEAR __sIrqHdr+030h
	bl	er0

;;	irq_tm1_ena();
CLINEA 0000H 0001H 0189H 0002H 000FH
	sb	0f015h.1
CBLOCKEND 41 2 394

;;}
CLINEA 0000H 0001H 018AH 0001H 0001H
	pop	r0
	st	r0,	DSR
	pop	xr0
	pop	ea, lr
	rti
CBLOCKEND 41 1 394
CFUNCTIONEND 41


	rseg $$s_handlerTM2INT$driver_irq
CFUNCTION 42

_s_handlerTM2INT	:
CBLOCK 42 1 397

;;{
CLINEA 0000H 0001H 018DH 0001H 0001H
;;*****************************************
;;	register/stack information
;;*****************************************
;;*****************************************

	push	lr, ea
	push	xr0
	l	r0,	DSR
	push	r0
CBLOCK 42 2 397

;;	irq_tm2_dis();
CLINEA 0000H 0001H 0191H 0002H 000FH
	rb	0f015h.2

;;	_sIrqHdr[IRQ_NO_TM2INT]();
CLINEA 0000H 0001H 0192H 0002H 001BH
	l	er0,	NEAR __sIrqHdr+032h
	bl	er0

;;	irq_tm2_ena();
CLINEA 0000H 0001H 0193H 0002H 000FH
	sb	0f015h.2
CBLOCKEND 42 2 404

;;}
CLINEA 0000H 0001H 0194H 0001H 0001H
	pop	r0
	st	r0,	DSR
	pop	xr0
	pop	ea, lr
	rti
CBLOCKEND 42 1 404
CFUNCTIONEND 42


	rseg $$s_handlerTM3INT$driver_irq
CFUNCTION 43

_s_handlerTM3INT	:
CBLOCK 43 1 407

;;{
CLINEA 0000H 0001H 0197H 0001H 0001H
;;*****************************************
;;	register/stack information
;;*****************************************
;;*****************************************

	push	lr, ea
	push	xr0
	l	r0,	DSR
	push	r0
CBLOCK 43 2 407

;;	irq_tm3_dis();
CLINEA 0000H 0001H 019BH 0002H 000FH
	rb	0f015h.3

;;	_sIrqHdr[IRQ_NO_TM3INT]();
CLINEA 0000H 0001H 019CH 0002H 001BH
	l	er0,	NEAR __sIrqHdr+034h
	bl	er0

;;	irq_tm3_ena();
CLINEA 0000H 0001H 019DH 0002H 000FH
	sb	0f015h.3
CBLOCKEND 43 2 414

;;}
CLINEA 0000H 0001H 019EH 0001H 0001H
	pop	r0
	st	r0,	DSR
	pop	xr0
	pop	ea, lr
	rti
CBLOCKEND 43 1 414
CFUNCTIONEND 43


	rseg $$s_handlerTM4INT$driver_irq
CFUNCTION 44

_s_handlerTM4INT	:
CBLOCK 44 1 417

;;{
CLINEA 0000H 0001H 01A1H 0001H 0001H
;;*****************************************
;;	register/stack information
;;*****************************************
;;*****************************************

	push	lr, ea
	push	xr0
	l	r0,	DSR
	push	r0
CBLOCK 44 2 417

;;	irq_tm4_dis();
CLINEA 0000H 0001H 01A5H 0002H 000FH
	rb	0f015h.4

;;	_sIrqHdr[IRQ_NO_TM4INT]();
CLINEA 0000H 0001H 01A6H 0002H 001BH
	l	er0,	NEAR __sIrqHdr+036h
	bl	er0

;;	irq_tm4_ena();
CLINEA 0000H 0001H 01A7H 0002H 000FH
	sb	0f015h.4
CBLOCKEND 44 2 424

;;}
CLINEA 0000H 0001H 01A8H 0001H 0001H
	pop	r0
	st	r0,	DSR
	pop	xr0
	pop	ea, lr
	rti
CBLOCKEND 44 1 424
CFUNCTIONEND 44


	rseg $$s_handlerTM5INT$driver_irq
CFUNCTION 45

_s_handlerTM5INT	:
CBLOCK 45 1 427

;;{
CLINEA 0000H 0001H 01ABH 0001H 0001H
;;*****************************************
;;	register/stack information
;;*****************************************
;;*****************************************

	push	lr, ea
	push	xr0
	l	r0,	DSR
	push	r0
CBLOCK 45 2 427

;;	irq_tm5_dis();
CLINEA 0000H 0001H 01AFH 0002H 000FH
	rb	0f015h.5

;;	_sIrqHdr[IRQ_NO_TM5INT]();
CLINEA 0000H 0001H 01B0H 0002H 001BH
	l	er0,	NEAR __sIrqHdr+038h
	bl	er0

;;	irq_tm5_ena();
CLINEA 0000H 0001H 01B1H 0002H 000FH
	sb	0f015h.5
CBLOCKEND 45 2 434

;;}
CLINEA 0000H 0001H 01B2H 0001H 0001H
	pop	r0
	st	r0,	DSR
	pop	xr0
	pop	ea, lr
	rti
CBLOCKEND 45 1 434
CFUNCTIONEND 45


	rseg $$s_handlerTM6INT$driver_irq
CFUNCTION 46

_s_handlerTM6INT	:
CBLOCK 46 1 437

;;{
CLINEA 0000H 0001H 01B5H 0001H 0001H
;;*****************************************
;;	register/stack information
;;*****************************************
;;*****************************************

	push	lr, ea
	push	xr0
	l	r0,	DSR
	push	r0
CBLOCK 46 2 437

;;	irq_tm6_dis();
CLINEA 0000H 0001H 01B9H 0002H 000FH
	rb	0f015h.6

;;	_sIrqHdr[IRQ_NO_TM6INT]();
CLINEA 0000H 0001H 01BAH 0002H 001BH
	l	er0,	NEAR __sIrqHdr+03ah
	bl	er0

;;	irq_tm6_ena();
CLINEA 0000H 0001H 01BBH 0002H 000FH
	sb	0f015h.6
CBLOCKEND 46 2 444

;;}
CLINEA 0000H 0001H 01BCH 0001H 0001H
	pop	r0
	st	r0,	DSR
	pop	xr0
	pop	ea, lr
	rti
CBLOCKEND 46 1 444
CFUNCTIONEND 46


	rseg $$s_handlerTM7INT$driver_irq
CFUNCTION 47

_s_handlerTM7INT	:
CBLOCK 47 1 447

;;{
CLINEA 0000H 0001H 01BFH 0001H 0001H
;;*****************************************
;;	register/stack information
;;*****************************************
;;*****************************************

	push	lr, ea
	push	xr0
	l	r0,	DSR
	push	r0
CBLOCK 47 2 447

;;	irq_tm7_dis();
CLINEA 0000H 0001H 01C3H 0002H 000FH
	rb	0f015h.7

;;	_sIrqHdr[IRQ_NO_TM7INT]();
CLINEA 0000H 0001H 01C4H 0002H 001BH
	l	er0,	NEAR __sIrqHdr+03ch
	bl	er0

;;	irq_tm7_ena();
CLINEA 0000H 0001H 01C5H 0002H 000FH
	sb	0f015h.7
CBLOCKEND 47 2 454

;;}
CLINEA 0000H 0001H 01C6H 0001H 0001H
	pop	r0
	st	r0,	DSR
	pop	xr0
	pop	ea, lr
	rti
CBLOCKEND 47 1 454
CFUNCTIONEND 47


	rseg $$s_handlerFTM0INT$driver_irq
CFUNCTION 48

_s_handlerFTM0INT	:
CBLOCK 48 1 457

;;{
CLINEA 0000H 0001H 01C9H 0001H 0001H
;;*****************************************
;;	register/stack information
;;*****************************************
;;*****************************************

	push	lr, ea
	push	xr0
	l	r0,	DSR
	push	r0
CBLOCK 48 2 457

;;	irq_ftm0_dis();
CLINEA 0000H 0001H 01CDH 0002H 0010H
	rb	0f016h.0

;;	_sIrqHdr[IRQ_NO_FTM0INT]();
CLINEA 0000H 0001H 01CEH 0002H 001CH
	l	er0,	NEAR __sIrqHdr+03eh
	bl	er0

;;	irq_ftm0_ena();
CLINEA 0000H 0001H 01CFH 0002H 0010H
	sb	0f016h.0
CBLOCKEND 48 2 464

;;}
CLINEA 0000H 0001H 01D0H 0001H 0001H
	pop	r0
	st	r0,	DSR
	pop	xr0
	pop	ea, lr
	rti
CBLOCKEND 48 1 464
CFUNCTIONEND 48


	rseg $$s_handlerFTM1INT$driver_irq
CFUNCTION 49

_s_handlerFTM1INT	:
CBLOCK 49 1 467

;;{
CLINEA 0000H 0001H 01D3H 0001H 0001H
;;*****************************************
;;	register/stack information
;;*****************************************
;;*****************************************

	push	lr, ea
	push	xr0
	l	r0,	DSR
	push	r0
CBLOCK 49 2 467

;;	irq_ftm1_dis();
CLINEA 0000H 0001H 01D7H 0002H 0010H
	rb	0f016h.1

;;	_sIrqHdr[IRQ_NO_FTM1INT]();
CLINEA 0000H 0001H 01D8H 0002H 001CH
	l	er0,	NEAR __sIrqHdr+040h
	bl	er0

;;	irq_ftm1_ena();
CLINEA 0000H 0001H 01D9H 0002H 0010H
	sb	0f016h.1
CBLOCKEND 49 2 474

;;}
CLINEA 0000H 0001H 01DAH 0001H 0001H
	pop	r0
	st	r0,	DSR
	pop	xr0
	pop	ea, lr
	rti
CBLOCKEND 49 1 474
CFUNCTIONEND 49


	rseg $$s_handlerFTM2INT$driver_irq
CFUNCTION 50

_s_handlerFTM2INT	:
CBLOCK 50 1 477

;;{
CLINEA 0000H 0001H 01DDH 0001H 0001H
;;*****************************************
;;	register/stack information
;;*****************************************
;;*****************************************

	push	lr, ea
	push	xr0
	l	r0,	DSR
	push	r0
CBLOCK 50 2 477

;;	irq_ftm2_dis();
CLINEA 0000H 0001H 01E1H 0002H 0010H
	rb	0f016h.2

;;	_sIrqHdr[IRQ_NO_FTM2INT]();
CLINEA 0000H 0001H 01E2H 0002H 001CH
	l	er0,	NEAR __sIrqHdr+042h
	bl	er0

;;	irq_ftm2_ena();
CLINEA 0000H 0001H 01E3H 0002H 0010H
	sb	0f016h.2
CBLOCKEND 50 2 484

;;}
CLINEA 0000H 0001H 01E4H 0001H 0001H
	pop	r0
	st	r0,	DSR
	pop	xr0
	pop	ea, lr
	rti
CBLOCKEND 50 1 484
CFUNCTIONEND 50


	rseg $$s_handlerFTM3INT$driver_irq
CFUNCTION 51

_s_handlerFTM3INT	:
CBLOCK 51 1 487

;;{
CLINEA 0000H 0001H 01E7H 0001H 0001H
;;*****************************************
;;	register/stack information
;;*****************************************
;;*****************************************

	push	lr, ea
	push	xr0
	l	r0,	DSR
	push	r0
CBLOCK 51 2 487

;;	irq_ftm3_dis();
CLINEA 0000H 0001H 01EBH 0002H 0010H
	rb	0f016h.3

;;	_sIrqHdr[IRQ_NO_FTM3INT]();
CLINEA 0000H 0001H 01ECH 0002H 001CH
	l	er0,	NEAR __sIrqHdr+044h
	bl	er0

;;	irq_ftm3_ena();
CLINEA 0000H 0001H 01EDH 0002H 0010H
	sb	0f016h.3
CBLOCKEND 51 2 494

;;}
CLINEA 0000H 0001H 01EEH 0001H 0001H
	pop	r0
	st	r0,	DSR
	pop	xr0
	pop	ea, lr
	rti
CBLOCKEND 51 1 494
CFUNCTIONEND 51


	rseg $$s_handlerLTBC0INT$driver_irq
CFUNCTION 52

_s_handlerLTBC0INT	:
CBLOCK 52 1 497

;;{
CLINEA 0000H 0001H 01F1H 0001H 0001H
;;*****************************************
;;	register/stack information
;;*****************************************
;;*****************************************

	push	lr, ea
	push	xr0
	l	r0,	DSR
	push	r0
CBLOCK 52 2 497

;;	irq_tbc0_dis();
CLINEA 0000H 0001H 01F5H 0002H 0010H
	rb	0f017h.0

;;	_sIrqHdr[IRQ_NO_LTBC0INT]();
CLINEA 0000H 0001H 01F6H 0002H 001DH
	l	er0,	NEAR __sIrqHdr+046h
	bl	er0

;;	irq_tbc0_ena();
CLINEA 0000H 0001H 01F7H 0002H 0010H
	sb	0f017h.0
CBLOCKEND 52 2 504

;;}
CLINEA 0000H 0001H 01F8H 0001H 0001H
	pop	r0
	st	r0,	DSR
	pop	xr0
	pop	ea, lr
	rti
CBLOCKEND 52 1 504
CFUNCTIONEND 52


	rseg $$s_handlerLTBC1INT$driver_irq
CFUNCTION 53

_s_handlerLTBC1INT	:
CBLOCK 53 1 507

;;{
CLINEA 0000H 0001H 01FBH 0001H 0001H
;;*****************************************
;;	register/stack information
;;*****************************************
;;*****************************************

	push	lr, ea
	push	xr0
	l	r0,	DSR
	push	r0
CBLOCK 53 2 507

;;	irq_tbc1_dis();
CLINEA 0000H 0001H 01FFH 0002H 0010H
	rb	0f017h.1

;;	_sIrqHdr[IRQ_NO_LTBC1INT]();
CLINEA 0000H 0001H 0200H 0002H 001DH
	l	er0,	NEAR __sIrqHdr+048h
	bl	er0

;;	irq_tbc1_ena();
CLINEA 0000H 0001H 0201H 0002H 0010H
	sb	0f017h.1
CBLOCKEND 53 2 514

;;}
CLINEA 0000H 0001H 0202H 0001H 0001H
	pop	r0
	st	r0,	DSR
	pop	xr0
	pop	ea, lr
	rti
CBLOCKEND 53 1 514
CFUNCTIONEND 53


	rseg $$s_handlerLTBC2INT$driver_irq
CFUNCTION 54

_s_handlerLTBC2INT	:
CBLOCK 54 1 517

;;{
CLINEA 0000H 0001H 0205H 0001H 0001H
;;*****************************************
;;	register/stack information
;;*****************************************
;;*****************************************

	push	lr, ea
	push	xr0
	l	r0,	DSR
	push	r0
CBLOCK 54 2 517

;;	irq_tbc2_dis();
CLINEA 0000H 0001H 0209H 0002H 0010H
	rb	0f017h.2

;;	_sIrqHdr[IRQ_NO_LTBC2INT]();
CLINEA 0000H 0001H 020AH 0002H 001DH
	l	er0,	NEAR __sIrqHdr+04ah
	bl	er0

;;	irq_tbc2_ena();
CLINEA 0000H 0001H 020BH 0002H 0010H
	sb	0f017h.2
CBLOCKEND 54 2 524

;;}
CLINEA 0000H 0001H 020CH 0001H 0001H
	pop	r0
	st	r0,	DSR
	pop	xr0
	pop	ea, lr
	rti
CBLOCKEND 54 1 524
CFUNCTIONEND 54


	rseg $$irq_init$driver_irq
CFUNCTION 8

_irq_init	:
CBLOCK 8 1 534

;;{
CLINEA 0000H 0001H 0216H 0001H 0001H
;;*****************************************
;;	register/stack information
;;*****************************************
;;*****************************************

	push	er4
CBLOCK 8 2 534
CLOCAL 47H 0002H 0026H 0002H "irqNo" 02H 00H 01H

;;	write_reg16(IE01, 0x00);
CLINEA 0000H 0001H 0218H 0002H 0019H
	mov	er0,	#0 
	st	er0,	0f010h

;;	write_reg16(IE23, 0x00);
CLINEA 0000H 0001H 0219H 0002H 0019H
	st	er0,	0f012h

;;	write_reg16(IE45, 0x00);
CLINEA 0000H 0001H 021AH 0002H 0019H
	st	er0,	0f014h

;;	write_reg16(IE67, 0x00);
CLINEA 0000H 0001H 021BH 0002H 0019H
	st	er0,	0f016h

;;	write_reg16(IRQ01, 0x00);
CLINEA 0000H 0001H 021CH 0002H 001AH
	st	er0,	0f018h

;;	write_reg16(IRQ23, 0x00);
CLINEA 0000H 0001H 021DH 0002H 001AH
	st	er0,	0f01ah

;;	write_reg16(IRQ45, 0x00);
CLINEA 0000H 0001H 021EH 0002H 001AH
	st	er0,	0f01ch

;;	write_reg16(IRQ67, 0x00);
CLINEA 0000H 0001H 021FH 0002H 001AH
	st	er0,	0f01eh

;;	clear_bit(ILE);
CLINEA 0000H 0001H 0220H 0002H 0010H
	rb	0f020h.0

;;	for( irqNo = 0; irqNo < IRQ_SIZE; irqNo++ ) {
CLINEA 0000H 0001H 0223H 0002H 002EH
	mov	er4,	er0	;; _lirqNo$0
_$L42 :
CBLOCK 8 3 547

;;		_sIrqHdr[irqNo] = _intNullHdr;
CLINEA 0000H 0001H 0224H 0003H 0020H
	mov	er0,	er4
	add	er0,	er4
	mov	r2,	#BYTE1 OFFSET __intNullHdr
	mov	r3,	#BYTE2 OFFSET __intNullHdr
	st	er2,	NEAR __sIrqHdr[er0]
CBLOCKEND 8 3 549

;;	for( irqNo = 0; irqNo < IRQ_SIZE; irqNo++ ) {
CLINEA 0000H 0000H 0223H 0002H 002EH
	add	er4,	#1 
	cmp	r4,	#026h
	cmpc	r5,	#00h
	blts	_$L42
CBLOCKEND 8 2 550

;;}
CLINEA 0000H 0001H 0226H 0001H 0001H
	pop	er4
	rt
CBLOCKEND 8 1 550
CFUNCTIONEND 8


	rseg $$irq_sethandler$driver_irq
CFUNCTION 10

_irq_sethandler	:
CBLOCK 10 1 561

;;{
CLINEA 0000H 0001H 0231H 0001H 0001H
;;*****************************************
;;	register/stack information
;;*****************************************
;;*****************************************

	push	xr8
	mov	r8,	r0
	mov	er10,	er2
CBLOCK 10 2 561
CARGUMENT 46H 0001H 001CH "intNo" 02H 00H 00H
CARGUMENT 47H 0002H 0029H "func" 0AH 03H 00H 02H 5FH 00H 00H 00H 00H 00H 07H

;;	if( intNo >= (unsigned char)IRQ_SIZE ) {
CLINEA 0000H 0001H 0234H 0002H 0029H
	cmp	r0,	#026h
	blt	_$L47
CBLOCK 10 3 564

;;		return ( IRQ_R_ERR_INTNO );
CLINEA 0000H 0001H 0235H 0003H 001DH
	mov	er0,	#-1
CBLOCKEND 10 3 566
CBLOCKEND 10 2 575

;;}
CLINEA 0000H 0001H 023FH 0001H 0001H
_$L46 :
	pop	xr8
	rt

;;	}
CLINEA 0000H 0000H 0236H 0002H 0002H
_$L47 :

;;	if( func != (void *)0 ) {
CLINEA 0000H 0001H 0238H 0002H 001AH
	mov	er2,	er2
	beq	_$L49
CBLOCK 10 4 568

;;		_sIrqHdr[intNo] = func;
CLINEA 0000H 0001H 0239H 0003H 0019H
	mov	r0,	r8
	mov	r1,	#00h
	add	er0,	er0
	st	er10,	NEAR __sIrqHdr[er0]
CBLOCKEND 10 4 570

;;	else {
CLINEA 0000H 0001H 023BH 0002H 0007H
	bal	_$L51
_$L49 :
CBLOCK 10 5 571

;;		_sIrqHdr[intNo] = _intNullHdr;
CLINEA 0000H 0001H 023CH 0003H 0020H
	mov	r0,	r8
	mov	r1,	#00h
	add	er0,	er0
	mov	r2,	#BYTE1 OFFSET __intNullHdr
	mov	r3,	#BYTE2 OFFSET __intNullHdr
	st	er2,	NEAR __sIrqHdr[er0]
CBLOCKEND 10 5 573

;;	}
CLINEA 0000H 0000H 023DH 0002H 0002H
_$L51 :

;;	return ( IRQ_R_OK );
CLINEA 0000H 0001H 023EH 0002H 0015H
	mov	er0,	#0 
	bal	_$L46
CBLOCKEND 10 1 575
CFUNCTIONEND 10


	rseg $$rst_interrupts$driver_irq
CFUNCTION 14

_rst_interrupts	:
CBLOCK 14 1 580

;;{
CLINEA 0000H 0001H 0244H 0001H 0001H
;;*****************************************
;;	register/stack information
;;*****************************************
;;*****************************************

CBLOCK 14 2 580

;;	di_flag = 0;
CLINEA 0000H 0001H 0245H 0002H 000DH
	mov	er0,	#0 
	st	er0,	NEAR _di_flag

;;	__EI();
CLINEA 0000H 0001H 0246H 0002H 0008H
	ei
CBLOCKEND 14 2 583

;;}
CLINEA 0000H 0001H 0247H 0001H 0001H
	rt
CBLOCKEND 14 1 583
CFUNCTIONEND 14


	rseg $$getMIE$driver_irq
CFUNCTION 99

_getMIE	:
CBLOCK 99 1 586

;;{
CLINEA 0000H 0001H 024AH 0001H 0001H
;;*****************************************
;;	register/stack information
;;*****************************************
;;*****************************************

CBLOCK 99 2 586

;;#asm
CLINEA 0000H 0001H 024BH 0001H 0004H
        mov     r0,     psw             ;PSWをリード
        
        and     r0,     #8              ;MIEのみにデータに加工する
        srl     r0,     #3              ;
CBLOCKEND 99 2 593

;;}
CLINEA 0000H 0001H 0251H 0001H 0001H
	rt
CBLOCKEND 99 1 593
CFUNCTIONEND 99


	rseg $$enb_interrupts$driver_irq
CFUNCTION 12

_enb_interrupts	:
CBLOCK 12 1 596

;;{
CLINEA 0000H 0001H 0254H 0001H 0001H
;;*****************************************
;;	register/stack information
;;*****************************************
;;*****************************************

CBLOCK 12 2 596
CARGUMENT 46H 0002H 0024H "irq_ch" 02H 00H 01H

;;	if(di_flag & DI_INTERRUPT)		// 前回の割り込み禁止処理が割り込み処理中に行われた場合
CLINEA 0000H 0001H 0255H 0002H 0054H
	tb	NEAR _di_flag.7
	beq	_$L55
CBLOCK 12 3 599

;;		di_flag &= ~DI_INTERRUPT;
CLINEA 0000H 0001H 0258H 0003H 001BH
	rb	NEAR _di_flag.7

;;	else
CLINEA 0000H 0001H 025AH 0002H 0005H
	rt
_$L55 :
CBLOCK 12 4 603

;;		di_flag &= ~irq_ch;			// 割り込み禁止中フラグをリセット
CLINEA 0000H 0001H 025CH 0003H 0039H
	xor	r0,	#0ffh
	xor	r1,	#0ffh
	l	er2,	NEAR _di_flag
	and	r2,	r0
	and	r3,	r1
	st	er2,	NEAR _di_flag

;;		if(di_flag == 0) __EI();	// 何れからも割り込み禁止されていなければ割り込み許可
CLINEA 0000H 0001H 025DH 0003H 0050H
	mov	er2,	er2
	bne	_$L58
	ei
_$L58 :
CBLOCKEND 12 4 606
CBLOCKEND 12 3 607
CBLOCKEND 12 2 607

;;}
CLINEA 0000H 0001H 025FH 0001H 0001H
	rt
CBLOCKEND 12 1 607
CFUNCTIONEND 12


	rseg $$dis_interrupts$driver_irq
CFUNCTION 13

_dis_interrupts	:
CBLOCK 13 1 611

;;{
CLINEA 0000H 0001H 0263H 0001H 0001H
;;*****************************************
;;	register/stack information
;;*****************************************
;;*****************************************

	push	lr
	push	er8
	mov	er8,	er0
CBLOCK 13 2 611
CRET 0002H
CARGUMENT 46H 0002H 0028H "irq_ch" 02H 00H 01H

;;	if((getMIE()==0) && (di_flag==0))		
CLINEA 0000H 0001H 0266H 0002H 0024H
	bl	_getMIE
	cmp	r0,	#00h
	bne	_$L61
	l	er0,	NEAR _di_flag
	bne	_$L61
CBLOCK 13 3 615

;;		di_flag |= DI_INTERRUPT;
CLINEA 0000H 0001H 0268H 0003H 001AH
	sb	NEAR _di_flag.7
CBLOCKEND 13 3 617

;;	else
CLINEA 0000H 0001H 026AH 0002H 0005H
	bal	_$L68
_$L61 :
CBLOCK 13 4 619

;;		__DI();						// 割り込み禁止
CLINEA 0000H 0001H 026CH 0003H 001EH
	di

;;		di_flag |= irq_ch;			// 割り込み禁止中フラグをセット
CLINEA 0000H 0001H 026DH 0003H 0036H
	l	er0,	NEAR _di_flag
	or	r0,	r8
	or	r1,	r9
	st	er0,	NEAR _di_flag
CBLOCKEND 13 4 623

;;	}
CLINEA 0000H 0000H 026FH 0002H 0002H
_$L68 :
CBLOCKEND 13 2 624

;;}
CLINEA 0000H 0001H 0270H 0001H 0001H
	pop	er8
	pop	pc
CBLOCKEND 13 1 624
CFUNCTIONEND 13

	public _dis_interrupts
	public _irq_init
	public _getMIE
	public _enb_interrupts
	public _rst_interrupts
	public _irq_sethandler
	public __intNullHdr
	extrn code near : _main

	cseg #00h at 08h
	dw	_s_handlerWDTINT

	cseg #00h at 010h
	dw	_s_handlerEXI0INT
	dw	_s_handlerEXI1INT
	dw	_s_handlerEXI2INT
	dw	_s_handlerEXI3INT
	dw	_s_handlerEXI4INT
	dw	_s_handlerEXI5INT
	dw	_s_handlerEXI6INT
	dw	_s_handlerEXI7INT
	dw	_s_handlerSIO0INT
	dw	_s_handlerSIOF0INT
	dw	_s_handlerI2C0INT
	dw	_s_handlerI2C1INT
	dw	_s_handlerUA0INT
	dw	_s_handlerUA1INT
	dw	_s_handlerUAF0INT

	cseg #00h at 03Ah
	dw	_s_handlerLOSCINT
	dw	_s_handlerVLSINT
	dw	_s_handlerMD0INT
	dw	_s_handlerSADINT
	dw	_s_handlerRADINT

	cseg #00h at 048h
	dw	_s_handlerCMP0INT
	dw	_s_handlerCMP1INT

	cseg #00h at 050h
	dw	_s_handlerTM0INT
	dw	_s_handlerTM1INT
	dw	_s_handlerTM2INT
	dw	_s_handlerTM3INT
	dw	_s_handlerTM4INT
	dw	_s_handlerTM5INT
	dw	_s_handlerTM6INT
	dw	_s_handlerTM7INT
	dw	_s_handlerFTM0INT
	dw	_s_handlerFTM1INT
	dw	_s_handlerFTM2INT
	dw	_s_handlerFTM3INT

	cseg #00h at 070h
	dw	_s_handlerLTBC0INT
	dw	_s_handlerLTBC1INT
	dw	_s_handlerLTBC2INT

	rseg $$NINITTAB
	dw	00h

	rseg $$NINITVAR
_di_flag :
	ds	02h

	rseg $$NVARdriver_irq
__sIrqHdr :
	ds	04ch

	end
