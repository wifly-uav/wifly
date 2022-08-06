;; Compile Options : /TML620504F /MS /near /IC:\LAZURI~1\LIBRAR~1\BM1383 /IC:\LAZURI~1\LIBRAR~1\BM1422 /IC:\LAZURI~1\LIBRAR~1\HARDWA~1 /IC:\LAZURI~1\LIBRAR~1\HARDWA~2 /IC:\LAZURI~1\LIBRAR~1\KXG03_~1 /IC:\LAZURI~1\LIBRAR~1\VL53L0X /IC:\LAZURI~1\LIBRAR~1\Wire /IC:\LAZURI~1\hardware\LAZURI~2 /IC:\LAZURI~1\hardware\LAZURI~2\lazurite /IC:\LAZURI~1\hardware\LAZURI~2\ML620Q~1 /IC:\LAZURI~1\hardware\LAZURI~2\ML620Q~1\clock /IC:\LAZURI~1\hardware\LAZURI~2\ML620Q~1\common /IC:\LAZURI~1\hardware\LAZURI~2\ML620Q~1\irq /IC:\LAZURI~1\hardware\LAZURI~2\ML620Q~1\lp /IC:\LAZURI~1\hardware\LAZURI~2\ML620Q~1\MCU_SM~1 /IC:\LAZURI~1\hardware\LAZURI~2\ML620Q~1\wdt /IC:\LAZURI~1\hardware\LAZURI~2\sub_ghz\ /D_ML620Q504 /DLAZURITE_MINI /DLAZURITE_IDE /DSUBGHZ /DPWR_LED /DLDO_CNT /SS 512 /SL 65 /SD /Oa /Ot /W 3 /Faobj\ /Lv 
;; Version Number  : Ver.3.53.1
;; File Name       : driver_i2c.c

	type (ML620504F) 
	model small, near
	$$NVARdriver_i2c segment data 2h #0h
	$$NTABdriver_i2c segment table 2h #0h
	$$i2c0_isr$driver_i2c segment code 2h #0h
	$$i2c1_isr$driver_i2c segment code 2h #0h
	$$i2c_begin$driver_i2c segment code 2h #0h
	$$i2c_check_read_last_data$driver_i2c segment code 2h #0h
	$$i2c_close$driver_i2c segment code 2h #0h
	$$i2c_force_stop$driver_i2c segment code 2h #0h
	$$i2c_get_err_status$driver_i2c segment code 2h #0h
	$$i2c_get_status$driver_i2c segment code 2h #0h
	$$i2c_init$driver_i2c segment code 2h #0h
	$$i2c_isr$driver_i2c segment code 2h #0h
	$$i2c_read_amount$driver_i2c segment code 2h #0h
	$$i2c_send_stopbit$driver_i2c segment code 2h #0h
	$$i2c_set_address$driver_i2c segment code 2h #0h
	$$i2c_set_rx_buf$driver_i2c segment code 2h #0h
	$$i2c_set_tx_buf$driver_i2c segment code 2h #0h
	$$i2c_start$driver_i2c segment code 2h #0h
	$$i2c_update_err_code$driver_i2c segment code 2h #0h
	$$i2c_write_amount$driver_i2c segment code 2h #0h
	$$NTABi2c_isr$driver_i2c segment table 2h #0h
CVERSION 3.53.1
CGLOBAL 01H 03H 0000H "i2c_set_tx_buf" 08H 02H 82H 00H 82H 06H 00H 00H 07H
CGLOBAL 01H 03H 0000H "i2c_set_rx_buf" 08H 02H 81H 00H 82H 06H 00H 00H 07H
CGLOBAL 01H 03H 0000H "i2c_begin" 08H 02H 80H 00H 80H 02H 00H 00H 07H
CGLOBAL 01H 02H 0000H "i2c_get_err_status" 08H 02H 8AH 00H 80H 00H 00H 00H 00H
CGLOBAL 01H 03H 0000H "i2c_send_stopbit" 08H 02H 84H 00H 80H 00H 00H 00H 07H
CGLOBAL 01H 03H 0000H "i2c_get_status" 08H 02H 86H 00H 80H 00H 00H 00H 00H
CGLOBAL 01H 03H 0000H "i2c_set_address" 08H 02H 83H 00H 80H 00H 00H 00H 07H
CGLOBAL 01H 02H 0000H "i2c_check_read_last_data" 08H 02H 8FH 00H 80H 00H 00H 00H 00H
CGLOBAL 01H 03H 0000H "i2c_isr" 08H 02H 87H 00H 81H 0cH 00H 00H 07H
CGLOBAL 01H 02H 0000H "i2c_update_err_code" 08H 02H 90H 00H 80H 04H 00H 00H 00H
CGLOBAL 01H 03H 0000H "i2c_force_stop" 08H 02H 8BH 00H 81H 04H 00H 00H 07H
CGLOBAL 01H 03H 0000H "i2c0_isr" 08H 02H 8EH 00H 80H 00H 00H 00H 07H
CGLOBAL 01H 03H 0000H "i2c_start" 08H 02H 85H 00H 80H 08H 00H 00H 07H
CGLOBAL 01H 03H 0000H "i2c_close" 08H 02H 0A1H 00H 80H 00H 00H 00H 07H
CGLOBAL 01H 03H 0000H "i2c_init" 08H 02H 7FH 00H 81H 04H 00H 00H 07H
CGLOBAL 01H 02H 0000H "i2c_read_amount" 08H 02H 88H 00H 80H 00H 00H 00H 01H
CGLOBAL 01H 03H 0000H "i2c1_isr" 08H 02H 8DH 00H 80H 00H 00H 00H 07H
CGLOBAL 01H 02H 0000H "i2c_write_amount" 08H 02H 89H 00H 80H 00H 00H 00H 01H
CSTRUCTTAG 0000H 0000H 0003H 000AH 00000012H "_Notag"
CSTRUCTMEM 42H 00000001H 00000000H "flag" 02H 00H 00H
CSTRUCTMEM 42H 00000002H 00000002H "rx_buffer" 04H 03H 00H 00H 00H
CSTRUCTMEM 42H 00000002H 00000004H "rx_index" 02H 00H 01H
CSTRUCTMEM 42H 00000002H 00000006H "rx_length" 02H 00H 01H
CSTRUCTMEM 42H 00000002H 00000008H "tx_buffer" 04H 03H 00H 00H 00H
CSTRUCTMEM 42H 00000002H 0000000AH "tx_index" 02H 00H 01H
CSTRUCTMEM 42H 00000002H 0000000CH "tx_length" 02H 00H 01H
CSTRUCTMEM 43H 00000001H 0000000EH "status" 02H 00H 00H
CSTRUCTMEM 42H 00000001H 0000000FH "bStop" 02H 00H 00H
CSTRUCTMEM 42H 00000001H 00000010H "err_code" 02H 00H 00H
CSTRUCTTAG 0000H 0000H 0002H 0008H 00000001H "_Notag"
CSTRUCTMEM 52H 00000001H 00000000H "b0" 02H 00H 00H
CSTRUCTMEM 52H 00000001H 00000001H "b1" 02H 00H 00H
CSTRUCTMEM 52H 00000001H 00000002H "b2" 02H 00H 00H
CSTRUCTMEM 52H 00000001H 00000003H "b3" 02H 00H 00H
CSTRUCTMEM 52H 00000001H 00000004H "b4" 02H 00H 00H
CSTRUCTMEM 52H 00000001H 00000005H "b5" 02H 00H 00H
CSTRUCTMEM 52H 00000001H 00000006H "b6" 02H 00H 00H
CSTRUCTMEM 52H 00000001H 00000007H "b7" 02H 00H 00H
CSTRUCTTAG 0000H 0000H 0001H 0002H 00000008H "_Notag"
CSTRUCTMEM 43H 00000004H 00000000H "quot" 02H 00H 02H
CSTRUCTMEM 43H 00000004H 00000004H "rem" 02H 00H 02H
CSTRUCTTAG 0000H 0000H 0000H 0002H 00000004H "_Notag"
CSTRUCTMEM 43H 00000002H 00000000H "quot" 02H 00H 01H
CSTRUCTMEM 43H 00000002H 00000002H "rem" 02H 00H 01H
CTYPEDEF 0000H 0000H 43H "INT8" 02H 00H 00H
CTYPEDEF 0000H 0000H 43H "_Ptrdifft" 02H 00H 01H
CTYPEDEF 0000H 0000H 42H "bool" 02H 00H 00H
CTYPEDEF 0000H 0000H 42H "byte" 02H 00H 00H
CTYPEDEF 0000H 0000H 43H "INT32" 02H 00H 02H
CTYPEDEF 0000H 0000H 43H "INT16" 02H 00H 01H
CTYPEDEF 0000H 0000H 42H "_Sizet" 02H 00H 01H
CTYPEDEF 0000H 0000H 42H "BOOLEAN" 02H 00H 00H
CTYPEDEF 0000H 0000H 42H "UCHAR" 02H 00H 00H
CTYPEDEF 0000H 0000H 43H "ptrdiff_t" 02H 00H 01H
CTYPEDEF 0000H 0000H 42H "size_t" 02H 00H 01H
CTYPEDEF 0000H 0000H 42H "uint8_t" 02H 00H 00H
CTYPEDEF 0000H 0000H 43H "int8_t" 02H 00H 00H
CTYPEDEF 0000H 0000H 43H "int16_t" 02H 00H 08H
CTYPEDEF 0000H 0000H 43H "int32_t" 02H 00H 02H
CTYPEDEF 0000H 0000H 42H "UINT8" 02H 00H 00H
CTYPEDEF 0000H 0000H 03H "_Cmpfun_nf" 08H 02H 01H 00H 00H 00H 00H 00H 01H
CTYPEDEF 0000H 0000H 03H "_Cmpfun_nn" 08H 02H 00H 00H 00H 00H 00H 00H 01H
CTYPEDEF 0000H 0000H 43H "CHAR" 02H 00H 00H
CTYPEDEF 0000H 0000H 03H "_Cmpfun_ff" 08H 02H 03H 00H 00H 00H 00H 00H 01H
CTYPEDEF 0000H 0000H 03H "_Cmpfun_fn" 08H 02H 02H 00H 00H 00H 00H 00H 01H
CTYPEDEF 0000H 0000H 42H "UINT16" 02H 00H 01H
CTYPEDEF 0000H 0000H 42H "UINT32" 02H 00H 02H
CTYPEDEF 0000H 0000H 42H "boolean" 02H 00H 00H
CTYPEDEF 0000H 0000H 42H "word" 02H 00H 01H
CTYPEDEF 0000H 0000H 42H "BOOL" 02H 00H 00H
CTYPEDEF 0000H 0000H 43H "_I2C_PARAM" 04H 00H 05H 03H 00H
CTYPEDEF 0000H 0000H 43H "div_t" 04H 00H 05H 00H 00H
CTYPEDEF 0000H 0000H 43H "ldiv_t" 04H 00H 05H 01H 00H
CTYPEDEF 0000H 0000H 42H "uint32_t" 02H 00H 02H
CTYPEDEF 0000H 0000H 43H "_BYTE_FIELD" 04H 00H 05H 02H 00H
CTYPEDEF 0000H 0000H 42H "uint16_t" 02H 00H 08H
CSGLOBAL 43H 0024H "I2C" 07H 01H 02H 00H 00H 05H 03H 00H
CFILE 0001H 000000DAH "C:\\LazuriteIDE\\bin\\U8Dev\\Inc\\stdlib.h"
CFILE 0002H 0000007AH "C:\\LazuriteIDE\\bin\\U8Dev\\Inc\\yvals.h"
CFILE 0003H 0000001EH "C:\\LazuriteIDE\\bin\\U8Dev\\Inc\\stddef.h"
CFILE 0004H 0000007BH "C:\\LAZURI~1\\hardware\\LAZURI~2\\common.h"
CFILE 0005H 00000F42H "C:\\LazuriteIDE\\bin\\U8Dev\\Inc\\ml620504F.h"
CFILE 0006H 000000C9H "C:\\LazuriteIDE\\bin\\U8Dev\\Inc\\string.h"
CFILE 0007H 00000022H "C:\\LAZURI~1\\hardware\\LAZURI~2\\ML620Q~1\\MCU_SM~1\\mcu.h"
CFILE 0008H 00000045H "C:\\LAZURI~1\\hardware\\LAZURI~2\\ML620Q~1\\common\\rdwr_reg.h"
CFILE 0009H 00000218H "C:\\LAZURI~1\\hardware\\LAZURI~2\\lazurite\\binary.h"
CFILE 000AH 0000006FH "C:\\LAZURI~1\\hardware\\lazurite_subghz\\ml620q504\\driver_irq.h"
CFILE 000BH 00000331H "C:\\LAZURI~1\\hardware\\LAZURI~2\\ML620Q~1\\irq\\irq.h"
CFILE 000CH 00000057H "C:\\LAZURI~1\\hardware\\lazurite_subghz\\ml620q504\\driver_i2c.h"
CFILE 0000H 000001B1H "C:\\LAZURI~1\\hardware\\lazurite_subghz\\ml620q504\\driver_i2c.c"

	rseg $$i2c_init$driver_i2c
CFUNCTION 127

_i2c_init	:
CBLOCK 127 1 73

;;{
CLINEA 0000H 0001H 0049H 0001H 0001H
;;*****************************************
;;	register/stack information
;;*****************************************
;;*****************************************

	push	lr
	push	er8
	mov	r8,	r0
CBLOCK 127 2 73
CRET 0002H
CARGUMENT 46H 0001H 001CH "ch" 02H 00H 00H

;;	if(ch>=2) return;
CLINEA 0000H 0001H 004AH 0002H 0012H
	cmp	r0,	#02h
	blt	_$L1
CBLOCKEND 127 2 101

;;}
CLINEA 0000H 0001H 0065H 0001H 0001H
_$L0 :
	pop	er8
	pop	pc

;;	if(ch>=2) return;
CLINEA 0000H 0000H 004AH 0002H 0012H
_$L1 :

;;	I2C[ch].status = I2C_MODE_IDLE;
CLINEA 0000H 0001H 004DH 0002H 0020H
	mov	r1,	#00h
	mov	er2,	er0
	sllc	r3,	#03h
	sll	r2,	#03h
	add	er2,	er0
	add	er2,	er2
	mov	er0,	er2
	mov	r2,	#01h
	st	r2,	NEAR _I2C+0eh[er0]

;;	I2C[ch].flag = false;
CLINEA 0000H 0001H 004EH 0002H 0016H
	mov	r0,	r8
	mov	r1,	#00h
	mov	er2,	er0
	sllc	r3,	#03h
	sll	r2,	#03h
	add	er2,	er0
	add	er2,	er2
	mov	er0,	er2
	mov	r2,	#00h
	st	r2,	NEAR _I2C[er0]

;;	I2C[ch].err_code = 0;
CLINEA 0000H 0001H 004FH 0002H 0016H
	mov	r0,	r8
	mov	r1,	#00h
	mov	er2,	er0
	sllc	r3,	#03h
	sll	r2,	#03h
	add	er2,	er0
	add	er2,	er2
	mov	er0,	er2
	mov	r2,	#00h
	st	r2,	NEAR _I2C+010h[er0]

;;	if(ch == 0)
CLINEA 0000H 0001H 0052H 0002H 000CH
	cmp	r8,	#00h
	bne	_$L3
CBLOCK 127 3 83

;;		clear_bit(DI2C0);
CLINEA 0000H 0001H 0054H 0003H 0013H
	rb	0f06ah.6

;;		P40D=1;P40MD1 = 0; P40MD0 = 1; P40C1 = 1; P40C0 = 0;	// port setting
CLINEA 0000H 0001H 0055H 0003H 0046H
	sb	0f230h.0
	rb	0f235h.0
	sb	0f234h.0
	sb	0f233h.0
	rb	0f232h.0

;;		P41D=1;P41MD1 = 0; P41MD0 = 1; P41C1 = 1; P41C0 = 0;	// port setting
CLINEA 0000H 0001H 0056H 0003H 0046H
	sb	0f230h.1
	rb	0f235h.1
	sb	0f234h.1
	sb	0f233h.1
	rb	0f232h.1

;;		I2C0MOD = 0x0203;									// OSCLK=16M, 400kbps, I2C start
CLINEA 0000H 0001H 0057H 0003H 003CH
	mov	r0,	#03h
	mov	r1,	#02h
	st	er0,	0f748h

;;		irq_sethandler(IRQ_NO_I2C0INT,i2c0_isr);		// set interrupt handler
CLINEA 0000H 0001H 0058H 0003H 0044H
	mov	r2,	#BYTE1 OFFSET _i2c0_isr
	mov	r3,	#BYTE2 OFFSET _i2c0_isr
	mov	r0,	#0bh
	bl	_irq_sethandler

;;		EI2C0 = 1;
CLINEA 0000H 0001H 0059H 0003H 000CH
	sb	0f012h.2

;;	else if(ch == 1)
CLINEA 0000H 0001H 005BH 0002H 0011H
	bal	_$L6
_$L3 :
	cmp	r8,	#01h
	beq	_$M1
	b	_$L0
_$M1 :
CBLOCK 127 4 92

;;		clear_bit(DI2C1);
CLINEA 0000H 0001H 005DH 0003H 0013H
	rb	0f06ah.7

;;		P35D=1,P35MD1 = 0;	P35MD0 = 1;P35C1 = 1; P35C0 = 0;	// port setting
CLINEA 0000H 0001H 005EH 0003H 0045H
	sb	0f228h.5
	rb	0f22dh.5
	sb	0f22ch.5
	sb	0f22bh.5
	rb	0f22ah.5

;;		P34D=1,P34MD1 = 0;	P34MD0 = 1;P34C1 = 1; P34C0 = 0;	// port setting
CLINEA 0000H 0001H 005FH 0003H 0045H
	sb	0f228h.4
	rb	0f22dh.4
	sb	0f22ch.4
	sb	0f22bh.4
	rb	0f22ah.4

;;		I2C1MOD = 0x0203;									// OSCLK=16M, 400kbps, I2C start
CLINEA 0000H 0001H 0060H 0003H 003CH
	mov	r0,	#03h
	mov	r1,	#02h
	st	er0,	0f758h

;;		irq_sethandler(IRQ_NO_I2C1INT,i2c1_isr);		// set interrupt handler
CLINEA 0000H 0001H 0061H 0003H 0044H
	mov	r2,	#BYTE1 OFFSET _i2c1_isr
	mov	r3,	#BYTE2 OFFSET _i2c1_isr
	mov	r0,	#0ch
	bl	_irq_sethandler

;;		EI2C1 = 1;
CLINEA 0000H 0001H 0062H 0003H 000CH
	sb	0f012h.3
CBLOCKEND 127 4 99

;;	}
CLINEA 0000H 0000H 0063H 0002H 0002H
_$L6 :

;;	return;
CLINEA 0000H 0001H 0064H 0002H 0008H
	b	_$L0
CBLOCKEND 127 3 101
CBLOCKEND 127 1 101
CFUNCTIONEND 127


	rseg $$i2c_begin$driver_i2c
CFUNCTION 128

_i2c_begin	:
CBLOCK 128 1 105

;;{
CLINEA 0000H 0001H 0069H 0001H 0001H
;;*****************************************
;;	register/stack information
;;*****************************************
;;*****************************************

	push	er8
	mov	r8,	r0
CBLOCK 128 2 105
CARGUMENT 46H 0001H 001CH "ch" 02H 00H 00H

;;	if(ch>=2) return;
CLINEA 0000H 0001H 006BH 0002H 0012H
	cmp	r0,	#02h
	blt	_$L9
CBLOCKEND 128 2 116

;;}
CLINEA 0000H 0001H 0074H 0001H 0001H
_$L8 :
	pop	er8
	rt

;;	if(ch>=2) return;
CLINEA 0000H 0000H 006BH 0002H 0012H
_$L9 :

;;	I2C[ch].tx_index = 0;
CLINEA 0000H 0001H 006EH 0002H 0016H
	mov	r1,	#00h
	mov	er2,	er0
	sllc	r3,	#03h
	sll	r2,	#03h
	add	er2,	er0
	add	er2,	er2
	mov	er0,	er2
	mov	er2,	#0 
	st	er2,	NEAR _I2C+0ah[er0]

;;	I2C[ch].tx_length = 0;
CLINEA 0000H 0001H 006FH 0002H 0017H
	mov	r0,	r8
	mov	r1,	#00h
	mov	er2,	er0
	sllc	r3,	#03h
	sll	r2,	#03h
	add	er2,	er0
	add	er2,	er2
	mov	er0,	er2
	mov	er2,	#0 
	st	er2,	NEAR _I2C+0ch[er0]

;;	I2C[ch].rx_index = 0;
CLINEA 0000H 0001H 0070H 0002H 0016H
	mov	r0,	r8
	mov	r1,	#00h
	mov	er2,	er0
	sllc	r3,	#03h
	sll	r2,	#03h
	add	er2,	er0
	add	er2,	er2
	mov	er0,	er2
	mov	er2,	#0 
	st	er2,	NEAR _I2C+04h[er0]

;;	I2C[ch].rx_length = 0;
CLINEA 0000H 0001H 0071H 0002H 0017H
	mov	r0,	r8
	mov	r1,	#00h
	mov	er2,	er0
	sllc	r3,	#03h
	sll	r2,	#03h
	add	er2,	er0
	add	er2,	er2
	mov	er0,	er2
	mov	er2,	#0 
	st	er2,	NEAR _I2C+06h[er0]

;;	I2C[ch].status = I2C_MODE_READY;
CLINEA 0000H 0001H 0072H 0002H 0021H
	mov	r0,	r8
	mov	r1,	#00h
	mov	er2,	er0
	sllc	r3,	#03h
	sll	r2,	#03h
	add	er2,	er0
	add	er2,	er2
	mov	er0,	er2
	mov	r2,	#02h
	st	r2,	NEAR _I2C+0eh[er0]

;;	return;
CLINEA 0000H 0001H 0073H 0002H 0008H
	bal	_$L8
CBLOCKEND 128 1 116
CFUNCTIONEND 128


	rseg $$i2c_set_rx_buf$driver_i2c
CFUNCTION 129

_i2c_set_rx_buf	:
CBLOCK 129 1 119

;;{
CLINEA 0000H 0001H 0077H 0001H 0001H
;;*****************************************
;;	register/stack information
;;*****************************************
	_length$4	set	2
;;*****************************************

	push	fp
	mov	fp,	sp
	push	xr8
	mov	r8,	r0
	mov	er10,	er2
CBLOCK 129 2 119
CARGUMENT 46H 0001H 001CH "ch" 02H 00H 00H
CARGUMENT 46H 0002H 0029H "rxbufp" 04H 03H 00H 00H 00H
CARGUMENT 42H 0002H 0002H "length" 02H 00H 01H

;;	I2C[ch].rx_buffer = rxbufp;
CLINEA 0000H 0001H 0078H 0002H 001CH
	mov	r1,	#00h
	mov	er2,	er0
	sllc	r3,	#03h
	sll	r2,	#03h
	add	er2,	er0
	add	er2,	er2
	st	er10,	NEAR _I2C+02h[er2]

;;	I2C[ch].rx_length = length;
CLINEA 0000H 0001H 0079H 0002H 001CH
	mov	er2,	er0
	sllc	r3,	#03h
	sll	r2,	#03h
	add	er2,	er0
	add	er2,	er2
	mov	er0,	er2
	l	er2,	_length$4[fp]
	st	er2,	NEAR _I2C+06h[er0]

;;	I2C[ch].rx_index = 0;
CLINEA 0000H 0001H 007AH 0002H 0016H
	mov	r0,	r8
	mov	r1,	#00h
	mov	er2,	er0
	sllc	r3,	#03h
	sll	r2,	#03h
	add	er2,	er0
	add	er2,	er2
	mov	er0,	er2
	mov	er2,	#0 
	st	er2,	NEAR _I2C+04h[er0]
CBLOCKEND 129 2 124

;;}
CLINEA 0000H 0000H 007CH 0001H 0001H
	pop	xr8
	mov	sp,	fp
	pop	fp
	rt
CBLOCKEND 129 1 124
CFUNCTIONEND 129


	rseg $$i2c_set_tx_buf$driver_i2c
CFUNCTION 130

_i2c_set_tx_buf	:
CBLOCK 130 1 127

;;{
CLINEA 0000H 0001H 007FH 0001H 0001H
;;*****************************************
;;	register/stack information
;;*****************************************
	_length$4	set	2
;;*****************************************

	push	fp
	mov	fp,	sp
	push	xr8
	mov	r8,	r0
	mov	er10,	er2
CBLOCK 130 2 127
CARGUMENT 46H 0001H 001CH "ch" 02H 00H 00H
CARGUMENT 46H 0002H 0029H "txbufp" 04H 03H 00H 00H 00H
CARGUMENT 42H 0002H 0002H "length" 02H 00H 01H

;;	I2C[ch].tx_buffer = txbufp;
CLINEA 0000H 0001H 0080H 0002H 001CH
	mov	r1,	#00h
	mov	er2,	er0
	sllc	r3,	#03h
	sll	r2,	#03h
	add	er2,	er0
	add	er2,	er2
	st	er10,	NEAR _I2C+08h[er2]

;;	I2C[ch].tx_length = length;
CLINEA 0000H 0001H 0081H 0002H 001CH
	mov	er2,	er0
	sllc	r3,	#03h
	sll	r2,	#03h
	add	er2,	er0
	add	er2,	er2
	mov	er0,	er2
	l	er2,	_length$4[fp]
	st	er2,	NEAR _I2C+0ch[er0]

;;	I2C[ch].tx_index = 0;
CLINEA 0000H 0001H 0082H 0002H 0016H
	mov	r0,	r8
	mov	r1,	#00h
	mov	er2,	er0
	sllc	r3,	#03h
	sll	r2,	#03h
	add	er2,	er0
	add	er2,	er2
	mov	er0,	er2
	mov	er2,	#0 
	st	er2,	NEAR _I2C+0ah[er0]
CBLOCKEND 130 2 132

;;}
CLINEA 0000H 0000H 0084H 0001H 0001H
	pop	xr8
	mov	sp,	fp
	pop	fp
	rt
CBLOCKEND 130 1 132
CFUNCTIONEND 130


	rseg $$i2c_set_address$driver_i2c
CFUNCTION 131

_i2c_set_address	:
CBLOCK 131 1 135

;;{
CLINEA 0000H 0001H 0087H 0001H 0001H
;;*****************************************
;;	register/stack information
;;*****************************************
;;*****************************************

	mov	r3,	r1
CBLOCK 131 2 135
CARGUMENT 46H 0001H 0014H "ch" 02H 00H 00H
CARGUMENT 46H 0001H 0017H "address" 02H 00H 00H

;;	if(ch == 0)
CLINEA 0000H 0001H 0088H 0002H 000CH
	cmp	r0,	#00h
	bne	_$L14
CBLOCK 131 3 137

;;		write_reg8(I2C0SA,(address << 1));		// set address to upper 7bit, LSB is RD/RW bit
CLINEA 0000H 0001H 008AH 0003H 0054H
	mov	r0,	r1
	sll	r0,	#01h
	st	r0,	0f742h

;;	else if(ch == 1)
CLINEA 0000H 0001H 008CH 0002H 0011H
	rt
_$L14 :
	cmp	r0,	#01h
	bne	_$L17
CBLOCK 131 4 141

;;		write_reg8(I2C1SA,(address << 1));		// set address to upper 7bit, LSB is RD/RW bit
CLINEA 0000H 0001H 008EH 0003H 0054H
	mov	r0,	r3
	sll	r0,	#01h
	st	r0,	0f752h
CBLOCKEND 131 4 143

;;	}
CLINEA 0000H 0000H 008FH 0002H 0002H
_$L17 :
CBLOCKEND 131 3 145
CBLOCKEND 131 2 145

;;}
CLINEA 0000H 0000H 0091H 0001H 0001H
	rt
CBLOCKEND 131 1 145
CFUNCTIONEND 131


	rseg $$i2c_get_status$driver_i2c
CFUNCTION 134

_i2c_get_status	:
CBLOCK 134 1 148

;;{
CLINEA 0000H 0001H 0094H 0001H 0001H
;;*****************************************
;;	register/stack information
;;*****************************************
;;*****************************************

CBLOCK 134 2 148
CARGUMENT 46H 0001H 0014H "ch" 02H 00H 00H

;;	return I2C[ch].status;
CLINEA 0000H 0001H 0095H 0002H 0017H
	mov	r1,	#00h
	mov	er2,	er0
	sllc	r3,	#03h
	sll	r2,	#03h
	add	er2,	er0
	add	er2,	er2
	l	r0,	NEAR _I2C+0eh[er2]
CBLOCKEND 134 2 150

;;}
CLINEA 0000H 0000H 0096H 0001H 0001H
	rt
CBLOCKEND 134 1 150
CFUNCTIONEND 134


	rseg $$i2c_send_stopbit$driver_i2c
CFUNCTION 132

_i2c_send_stopbit	:
CBLOCK 132 1 153

;;{
CLINEA 0000H 0001H 0099H 0001H 0001H
;;*****************************************
;;	register/stack information
;;*****************************************
;;*****************************************

CBLOCK 132 2 153
CARGUMENT 46H 0001H 0014H "ch" 02H 00H 00H

;;	if(ch == 0)
CLINEA 0000H 0001H 009AH 0002H 000CH
	cmp	r0,	#00h
	bne	_$L21
CBLOCK 132 3 155

;;		write_reg8(I2C0CON0, 0x02);
CLINEA 0000H 0001H 009CH 0003H 001DH
	mov	r0,	#02h
	st	r0,	0f746h

;;	else if(ch == 1)
CLINEA 0000H 0001H 009EH 0002H 0011H
	rt
_$L21 :
	cmp	r0,	#01h
	bne	_$L24
CBLOCK 132 4 159

;;		write_reg8(I2C1CON0, 0x02);
CLINEA 0000H 0001H 00A0H 0003H 001DH
	mov	r0,	#02h
	st	r0,	0f756h
CBLOCKEND 132 4 161

;;	}
CLINEA 0000H 0000H 00A1H 0002H 0002H
_$L24 :
CBLOCKEND 132 3 163
CBLOCKEND 132 2 163

;;}
CLINEA 0000H 0000H 00A3H 0001H 0001H
	rt
CBLOCKEND 132 1 163
CFUNCTIONEND 132


	rseg $$i2c_start$driver_i2c
CFUNCTION 133

_i2c_start	:
CBLOCK 133 1 166

;;{
CLINEA 0000H 0001H 00A6H 0001H 0001H
;;*****************************************
;;	register/stack information
;;*****************************************
;;*****************************************

	push	xr8
	push	bp
	push	er4
	mov	er8,	er0
	mov	r10,	r2
CBLOCK 133 2 166
CARGUMENT 46H 0001H 001CH "ch" 02H 00H 00H
CARGUMENT 46H 0001H 001DH "write" 02H 00H 00H
CARGUMENT 46H 0001H 001EH "cont" 02H 00H 00H
CLOCAL 46H 0002H 002AH 0002H "reg_SA" 04H 03H 00H 00H 00H
CLOCAL 46H 0002H 0026H 0002H "reg_CON" 04H 03H 00H 00H 00H
CLOCAL 46H 0001H 0014H 0002H "start_code" 02H 00H 00H

;;	if(ch>=2) return;
CLINEA 0000H 0001H 00ABH 0002H 0012H
	cmp	r0,	#02h
	blt	_$L27
CBLOCKEND 133 2 217

;;}
CLINEA 0000H 0001H 00D9H 0001H 0001H
_$L26 :
	pop	er4
	pop	bp
	pop	xr8
	rt

;;	if(ch>=2) return;
CLINEA 0000H 0000H 00ABH 0002H 0012H
_$L27 :

;;	I2C[ch].flag = false;
CLINEA 0000H 0001H 00ACH 0002H 0016H
	mov	r1,	#00h
	mov	er2,	er0
	sllc	r3,	#03h
	sll	r2,	#03h
	add	er2,	er0
	add	er2,	er2
	mov	er0,	er2
	mov	r2,	#00h
	st	r2,	NEAR _I2C[er0]

;;	I2C[ch].err_code = 0;
CLINEA 0000H 0001H 00ADH 0002H 0016H
	mov	r0,	r8
	mov	r1,	#00h
	mov	er2,	er0
	sllc	r3,	#03h
	sll	r2,	#03h
	add	er2,	er0
	add	er2,	er2
	mov	er0,	er2
	mov	r2,	#00h
	st	r2,	NEAR _I2C+010h[er0]

;;	switch(ch)
CLINEA 0000H 0001H 00B0H 0002H 000BH
CBLOCK 133 3 177
	cmp	r8,	#00h
	beq	_$L34

;;	switch(ch)
CLINEA 0000H 0000H 00B0H 0002H 000BH
	cmp	r8,	#01h
	beq	_$L35

;;		return;
CLINEA 0000H 0001H 00BBH 0003H 0009H
	bal	_$L26
CBLOCKEND 133 3 188

;;	}
CLINEA 0000H 0000H 00BCH 0002H 0002H
_$L32 :
	mov	r5,	#0f7h

;;	if(write == TRUE)
CLINEA 0000H 0001H 00BEH 0002H 0012H
	cmp	r9,	#01h
	bne	_$L36
CBLOCK 133 4 191

;;		*reg_SA &= 0xFE;					// set LSB of I2C address  to 0
CLINEA 0000H 0001H 00C0H 0003H 0036H
	l	r0,	[bp]
	and	r0,	#0feh
	st	r0,	[bp]

;;		I2C[ch].status = I2C_MODE_TX;		// set status to write
CLINEA 0000H 0001H 00C1H 0003H 0037H
	mov	r0,	r8
	mov	r1,	#00h
	mov	er2,	er0
	sllc	r3,	#03h
	sll	r2,	#03h
	add	er2,	er0
	add	er2,	er2
	mov	er0,	er2
	mov	r2,	#06h
CBLOCKEND 133 4 194

;;	else // read sequence
CLINEA 0000H 0001H 00C3H 0002H 0016H
	bal	_$L38
_$L36 :
CBLOCK 133 5 196

;;		*reg_SA |= 0x01;					// set LSB of I2C address to 1
CLINEA 0000H 0001H 00C5H 0003H 0035H
	l	r0,	[bp]
	or	r0,	#01h
	st	r0,	[bp]

;;		I2C[ch].status = I2C_MODE_RX_ADR;	// set status to read
CLINEA 0000H 0001H 00C6H 0003H 0039H
	mov	r0,	r8
	mov	r1,	#00h
	mov	er2,	er0
	sllc	r3,	#03h
	sll	r2,	#03h
	add	er2,	er0
	add	er2,	er2
	mov	er0,	er2
	mov	r2,	#07h
CBLOCKEND 133 5 199

;;	}
CLINEA 0000H 0000H 00C7H 0002H 0002H
_$L38 :
	st	r2,	NEAR _I2C+0eh[er0]

;;	I2C[ch].bStop = cont;
CLINEA 0000H 0001H 00CAH 0002H 0016H
	mov	r0,	r8
	mov	r1,	#00h
	mov	er2,	er0
	sllc	r3,	#03h
	sll	r2,	#03h
	add	er2,	er0
	add	er2,	er2
	st	r10,	NEAR _I2C+0fh[er2]

;;	if((*reg_CON&0x01) == 0)				// check start or restart
CLINEA 0000H 0001H 00CDH 0002H 0036H
	l	r0,	[er4]
	tb	r0.0
	bne	_$L39
CBLOCK 133 6 206

;;		start_code |= 0x01;
CLINEA 0000H 0001H 00CFH 0003H 0015H
	mov	r0,	#01h
CBLOCKEND 133 6 208

;;	else
CLINEA 0000H 0001H 00D1H 0002H 0005H
	bal	_$L41
_$L39 :
CBLOCK 133 7 210

;;		start_code |= 0x05;					// restart
CLINEA 0000H 0001H 00D3H 0003H 0024H
	mov	r0,	#05h
CBLOCKEND 133 7 212

;;	}
CLINEA 0000H 0000H 00D4H 0002H 0002H
_$L41 :

;;	*reg_CON = start_code;					// start
CLINEA 0000H 0001H 00D6H 0002H 0024H
	st	r0,	[er4]

;;	return;
CLINEA 0000H 0001H 00D8H 0002H 0008H
	b	_$L26

;;	case 0:			// I2C0
CLINEA 0000H 0001H 00B2H 0002H 0012H
_$L34 :

;;		reg_SA = &I2C0SA;
CLINEA 0000H 0001H 00B3H 0003H 0013H
	mov	r12,	#042h
	mov	r13,	#0f7h

;;		reg_CON = &I2C0CON0;
CLINEA 0000H 0001H 00B4H 0003H 0016H
	mov	r4,	#046h

;;		break;
CLINEA 0000H 0001H 00B5H 0003H 0008H
	bal	_$L32

;;	case 1:			// I2C1
CLINEA 0000H 0001H 00B6H 0002H 0012H
_$L35 :

;;		reg_SA = &I2C1SA;
CLINEA 0000H 0001H 00B7H 0003H 0013H
	mov	r12,	#052h
	mov	r13,	#0f7h

;;		reg_CON = &I2C1CON0;
CLINEA 0000H 0001H 00B8H 0003H 0016H
	mov	r4,	#056h

;;		break;
CLINEA 0000H 0001H 00B9H 0003H 0008H
	bal	_$L32
CBLOCKEND 133 1 217
CFUNCTIONEND 133


	rseg $$i2c0_isr$driver_i2c
CFUNCTION 142

_i2c0_isr	:
CBLOCK 142 1 221

;;{
CLINEA 0000H 0001H 00DDH 0001H 0001H
;;*****************************************
;;	register/stack information
;;*****************************************
;;*****************************************

CBLOCK 142 2 221

;;	I2C[0].flag = true;
CLINEA 0000H 0001H 00DEH 0002H 0014H
	mov	r0,	#01h
	st	r0,	NEAR _I2C
CBLOCKEND 142 2 223

;;}
CLINEA 0000H 0001H 00DFH 0001H 0001H
	rt
CBLOCKEND 142 1 223
CFUNCTIONEND 142


	rseg $$i2c1_isr$driver_i2c
CFUNCTION 141

_i2c1_isr	:
CBLOCK 141 1 227

;;{
CLINEA 0000H 0001H 00E3H 0001H 0001H
;;*****************************************
;;	register/stack information
;;*****************************************
;;*****************************************

CBLOCK 141 2 227

;;	I2C[1].flag = true;
CLINEA 0000H 0001H 00E4H 0002H 0014H
	mov	r0,	#01h
	st	r0,	NEAR _I2C+012h
CBLOCKEND 141 2 229

;;}
CLINEA 0000H 0001H 00E5H 0001H 0001H
	rt
CBLOCKEND 141 1 229
CFUNCTIONEND 141


	rseg $$i2c_isr$driver_i2c
CFUNCTION 135

_i2c_isr	:
CBLOCK 135 1 234

;;{
CLINEA 0000H 0001H 00EAH 0001H 0001H
;;*****************************************
;;	register/stack information
;;*****************************************
;;*****************************************

	push	lr
	push	xr8
	push	xr4
	push	bp
	mov	r8,	r0
CBLOCK 135 2 234
CRET 000AH
CARGUMENT 46H 0001H 001CH "ch" 02H 00H 00H
CLOCAL 46H 0002H 0027H 0002H "reg_CON" 04H 03H 00H 00H 00H
CLOCAL 46H 0002H 0029H 0002H "reg_TD" 04H 03H 00H 00H 00H
CLOCAL 46H 0002H 002AH 0002H "reg_RD" 04H 03H 00H 00H 00H
CLOCAL 46H 0001H 0018H 0002H "startcode" 02H 00H 00H
CLOCAL 4AH 0001H 0000H 0002H "i2c_result" 02H 00H 00H

;;	UCHAR startcode = 0;
CLINEA 0000H 0001H 00EEH 0002H 0015H
	mov	r4,	#00h	;; _lstartcode$6

;;	if(	I2C[ch].flag == false) return;
CLINEA 0000H 0001H 00F1H 0002H 0023H
	mov	r1,	#00h
	mov	er2,	er0
	sllc	r3,	#03h
	sll	r2,	#03h
	add	er2,	er0
	add	er2,	er2
	l	r0,	NEAR _I2C[er2]
	bne	_$L45
CBLOCKEND 135 2 348

;;}
CLINEA 0000H 0001H 015CH 0001H 0001H
_$L44 :
	pop	bp
	pop	xr4
	pop	xr8
	pop	pc

;;	if(	I2C[ch].flag == false) return;
CLINEA 0000H 0000H 00F1H 0002H 0023H
_$L45 :

;;	I2C[ch].flag = false;
CLINEA 0000H 0001H 00F3H 0002H 0016H
	mov	r0,	r8
	mov	r1,	#00h
	mov	er2,	er0
	sllc	r3,	#03h
	sll	r2,	#03h
	add	er2,	er0
	add	er2,	er2
	mov	er0,	er2
	mov	r2,	#00h
	st	r2,	NEAR _I2C[er0]

;;	switch(ch)
CLINEA 0000H 0001H 00F5H 0002H 000BH
CBLOCK 135 3 246
	cmp	r8,	#00h
	beq	_$L52

;;	switch(ch)
CLINEA 0000H 0000H 00F5H 0002H 000BH
	cmp	r8,	#01h
	beq	_$L53

;;		return;
CLINEA 0000H 0001H 0102H 0003H 0009H
	bal	_$L44
CBLOCKEND 135 3 259

;;	}
CLINEA 0000H 0000H 0103H 0002H 0002H
_$L50 :
	mov	r13,	#0f7h

;;	switch(I2C[ch].status)
CLINEA 0000H 0001H 0106H 0002H 0017H
	mov	r0,	r8
	mov	r1,	#00h
	mov	er2,	er0
	sllc	r3,	#03h
	sll	r2,	#03h
	add	er2,	er0
	add	er2,	er2
	l	r0,	NEAR _I2C+0eh[er2]
	extbw	er0
CBLOCK 135 4 263
	cmp	r0,	#09h
	cmpc	r1,	#00h
	ble	_$M13
	b	_$L58
_$M13 :
	cmp	r0,	#02h
	cmpc	r1,	#00h
	bge	_$M14
	b	_$L58
_$M14 :
	add	er0,	#-2
	sllc	r1,	#01h
	sll	r0,	#01h
	l	er0,	NEAR _$M12[er0]
	b	er0

;;	}
_$L57 :

;;	if(startcode != 0) *reg_CON = startcode;
CLINEA 0000H 0001H 0159H 0002H 0029H
	cmp	r4,	#00h
	beq	_$L44
	st	r4,	[er6]

;;	return;
CLINEA 0000H 0001H 015BH 0002H 0008H
	bal	_$L44

;;	case 0:
CLINEA 0000H 0001H 00F7H 0002H 0008H
_$L52 :

;;		reg_CON = &I2C0CON0;
CLINEA 0000H 0001H 00F8H 0003H 0016H
	mov	r6,	#046h
	mov	r7,	#0f7h

;;		reg_TD  = &I2C0TD;
CLINEA 0000H 0001H 00F9H 0003H 0014H
	mov	r10,	#044h
	mov	r11,	#0f7h

;;		reg_RD  = &I2C0RD;
CLINEA 0000H 0001H 00FAH 0003H 0014H
	mov	r12,	#040h

;;		break;
CLINEA 0000H 0001H 00FBH 0003H 0008H
	bal	_$L50

;;	case 1:
CLINEA 0000H 0001H 00FCH 0002H 0008H
_$L53 :

;;		reg_CON = &I2C1CON0;
CLINEA 0000H 0001H 00FDH 0003H 0016H
	mov	r6,	#056h
	mov	r7,	#0f7h

;;		reg_TD  = &I2C1TD;
CLINEA 0000H 0001H 00FEH 0003H 0014H
	mov	r10,	#054h
	mov	r11,	#0f7h

;;		reg_RD  = &I2C1RD;
CLINEA 0000H 0001H 00FFH 0003H 0014H
	mov	r12,	#050h

;;		break;
CLINEA 0000H 0001H 0100H 0003H 0008H
	bal	_$L50

;;	case I2C_MODE_TX:											// transfer following data
CLINEA 0000H 0001H 0109H 0002H 0037H
_$S59 :

;;		I2C[ch].err_code = i2c_update_err_code(ch,I2C[ch].tx_index);
CLINEA 0000H 0000H 010AH 0003H 003EH
	mov	r0,	r8
	mov	r1,	#00h
	mov	er2,	er0
	sllc	r3,	#03h
	sll	r2,	#03h
	add	er2,	er0
	add	er2,	er2
	l	er2,	NEAR _I2C+0ah[er2]
	bl	_i2c_update_err_code
	mov	r5,	r0
	mov	r0,	r8
	mov	r1,	#00h
	mov	er2,	er0
	sllc	r3,	#03h
	sll	r2,	#03h
	add	er2,	er0
	add	er2,	er2
	st	r5,	NEAR _I2C+010h[er2]

;;		if((I2C[ch].tx_index < I2C[ch].tx_length)&&(I2C[ch].err_code == I2C_RESULT_OK))
CLINEA 0000H 0001H 010BH 0003H 0051H
	mov	er2,	er0
	sllc	r3,	#03h
	sll	r2,	#03h
	add	er2,	er0
	add	er2,	er2
	mov	er0,	er2
	l	er2,	NEAR _I2C+0ah[er2]
	l	er0,	NEAR _I2C+0ch[er0]
	cmp	er2,	er0
	bge	_$L60
	mov	r0,	r8
	mov	r1,	#00h
	mov	er2,	er0
	sllc	r3,	#03h
	sll	r2,	#03h
	add	er2,	er0
	add	er2,	er2
	l	r0,	NEAR _I2C+010h[er2]
	bne	_$L60
CBLOCK 135 5 268

;;			*reg_TD = I2C[ch].tx_buffer[I2C[ch].tx_index];		// set next data to tx register
CLINEA 0000H 0001H 010DH 0004H 0052H
	mov	r0,	r8
	mov	er2,	er0
	sllc	r3,	#03h
	sll	r2,	#03h
	add	er2,	er0
	add	er2,	er2
	l	er0,	NEAR _I2C+08h[er2]
	l	er2,	NEAR _I2C+0ah[er2]
	add	er0,	er2
	l	r0,	[er0]
	st	r0,	[er10]

;;			I2C[ch].tx_index++;
CLINEA 0000H 0000H 010EH 0004H 0016H
	mov	r0,	r8
	mov	r1,	#00h
	mov	er2,	er0
	sllc	r3,	#03h
	sll	r2,	#03h
	add	er2,	er0
	add	er2,	er2
	mov	er0,	er2
	l	er2,	NEAR _I2C+0ah[er2]
	add	er2,	#1 
	st	er2,	NEAR _I2C+0ah[er0]

;;			startcode = 0x01;									// start transmitting
CLINEA 0000H 0001H 010FH 0004H 0032H
	mov	r4,	#01h	;; _lstartcode$6

;;		else													// tx_buffer full
CLINEA 0000H 0001H 0111H 0003H 0024H
	bal	_$L70
_$L60 :
CBLOCK 135 6 274

;;			if(I2C[ch].bStop == true)
CLINEA 0000H 0001H 0113H 0004H 001CH
	mov	r0,	r8
	mov	r1,	#00h
	mov	er2,	er0
	sllc	r3,	#03h
	sll	r2,	#03h
	add	er2,	er0
	add	er2,	er2
	l	r0,	NEAR _I2C+0fh[er2]
	cmp	r0,	#01h
	bne	_$L68
CBLOCK 135 7 276

;;				i2c_send_stopbit(ch);
CLINEA 0000H 0001H 0115H 0005H 0019H
	mov	r0,	r8
	bl	_i2c_send_stopbit

;;				I2C[ch].status = I2C_MODE_STOPBIT;
CLINEA 0000H 0001H 0116H 0005H 0026H
	mov	r0,	r8
	mov	r1,	#00h
	mov	er2,	er0
	sllc	r3,	#03h
	sll	r2,	#03h
	add	er2,	er0
	add	er2,	er2
	mov	er0,	er2
	mov	r2,	#03h
	st	r2,	NEAR _I2C+0eh[er0]
CBLOCKEND 135 7 279

;;			else
CLINEA 0000H 0001H 0118H 0004H 0007H
	bal	_$L70
_$L68 :
CBLOCK 135 8 281

;;				I2C[ch].status = I2C_MODE_READY;
CLINEA 0000H 0001H 011AH 0005H 0024H
	mov	r0,	r8
	mov	r1,	#00h
	mov	er2,	er0
	sllc	r3,	#03h
	sll	r2,	#03h
	add	er2,	er0
	add	er2,	er2
	mov	er0,	er2
	mov	r2,	#02h
	st	r2,	NEAR _I2C+0eh[er0]
CBLOCKEND 135 8 283

;;			}
CLINEA 0000H 0000H 011BH 0004H 0004H
_$L70 :
CBLOCKEND 135 6 284

;;		break;
CLINEA 0000H 0001H 011DH 0003H 0008H
	b	_$L57
CBLOCKEND 135 5 348

;;	case I2C_MODE_RX_ADR:										// In case of sending I2C address, skip to send data to buffer
CLINEA 0000H 0001H 011FH 0002H 005EH
_$S71 :

;;		I2C[ch].err_code = i2c_update_err_code(ch,I2C[ch].tx_index);
CLINEA 0000H 0000H 0120H 0003H 003EH
	mov	r0,	r8
	mov	r1,	#00h
	mov	er2,	er0
	sllc	r3,	#03h
	sll	r2,	#03h
	add	er2,	er0
	add	er2,	er2
	l	er2,	NEAR _I2C+0ah[er2]
	bl	_i2c_update_err_code
	mov	r5,	r0
	mov	r0,	r8
	mov	r1,	#00h
	mov	er2,	er0
	sllc	r3,	#03h
	sll	r2,	#03h
	add	er2,	er0
	add	er2,	er2
	st	r5,	NEAR _I2C+010h[er2]

;;		if((I2C[ch].err_code != I2C_RESULT_OK)&&(I2C[ch].bStop != true))					// error process
CLINEA 0000H 0001H 0121H 0003H 0057H
	mov	er2,	er0
	sllc	r3,	#03h
	sll	r2,	#03h
	add	er2,	er0
	add	er2,	er2
	l	r0,	NEAR _I2C+010h[er2]
	beq	_$L72
	mov	r0,	r8
	mov	er2,	er0
	sllc	r3,	#03h
	sll	r2,	#03h
	add	er2,	er0
	add	er2,	er2
	l	r0,	NEAR _I2C+0fh[er2]
	cmp	r0,	#01h
	beq	_$L72
CBLOCK 135 9 290

;;				I2C[ch].status = I2C_MODE_READY;
CLINEA 0000H 0001H 0123H 0005H 0024H
	mov	r0,	r8
	mov	er2,	er0
	sllc	r3,	#03h
	sll	r2,	#03h
	add	er2,	er0
	add	er2,	er2
	mov	er0,	er2
	mov	r2,	#02h
	st	r2,	NEAR _I2C+0eh[er0]

;;			break;
CLINEA 0000H 0001H 012DH 0004H 0009H
	b	_$L57
CBLOCKEND 135 9 302

;;		}
CLINEA 0000H 0000H 012EH 0003H 0003H
_$L72 :

;;		I2C[ch].status = I2C_MODE_RX;
CLINEA 0000H 0001H 012FH 0003H 001FH
	mov	r0,	r8
	mov	r1,	#00h
	mov	er2,	er0
	sllc	r3,	#03h
	sll	r2,	#03h
	add	er2,	er0
	add	er2,	er2
	mov	er0,	er2
	mov	r2,	#08h
	st	r2,	NEAR _I2C+0eh[er0]

;;		startcode = 0x01;										// start transmitting
CLINEA 0000H 0001H 0130H 0003H 0032H
	mov	r4,	#01h	;; _lstartcode$6

;;		if(i2c_check_read_last_data(ch) == true)
CLINEA 0000H 0001H 0131H 0003H 002AH
	mov	r0,	r8
	bl	_i2c_check_read_last_data
	cmp	r0,	#01h
	beq	_$M15
	b	_$L57
_$M15 :
CBLOCK 135 10 306

;;			startcode |= 0x80;									// if next data is last, ACK is set to HIGH
CLINEA 0000H 0001H 0133H 0004H 0049H
	mov	r4,	#081h	;; _lstartcode$6

;;			I2C[ch].status = I2C_MODE_RX_END;
CLINEA 0000H 0001H 0134H 0004H 0024H
	mov	r0,	r8
	mov	r1,	#00h
	mov	er2,	er0
	sllc	r3,	#03h
	sll	r2,	#03h
	add	er2,	er0
	add	er2,	er2
	mov	er0,	er2
	mov	r2,	#09h
	st	r2,	NEAR _I2C+0eh[er0]
CBLOCKEND 135 10 309

;;		break;
CLINEA 0000H 0001H 0136H 0003H 0008H
	b	_$L57

;;	case I2C_MODE_RX:											// reciever
CLINEA 0000H 0001H 0137H 0002H 0028H
_$S81 :

;;		I2C[ch].rx_buffer[I2C[ch].rx_index] = *reg_RD; 			// set next data to rx register
CLINEA 0000H 0001H 0138H 0003H 0053H
	mov	r0,	r8
	mov	r1,	#00h
	mov	er2,	er0
	sllc	r3,	#03h
	sll	r2,	#03h
	add	er2,	er0
	add	er2,	er2
	l	er0,	NEAR _I2C+02h[er2]
	l	er2,	NEAR _I2C+04h[er2]
	add	er0,	er2
	l	r2,	[bp]
	st	r2,	[er0]

;;		I2C[ch].rx_index++;
CLINEA 0000H 0000H 0139H 0003H 0015H
	mov	r0,	r8
	mov	r1,	#00h
	mov	er2,	er0
	sllc	r3,	#03h
	sll	r2,	#03h
	add	er2,	er0
	add	er2,	er2
	mov	er0,	er2
	l	er2,	NEAR _I2C+04h[er2]
	add	er2,	#1 
	st	er2,	NEAR _I2C+04h[er0]

;;		startcode = 0x01;										// start transmitting
CLINEA 0000H 0001H 013AH 0003H 0032H
	mov	r4,	#01h	;; _lstartcode$6

;;		if(i2c_check_read_last_data(ch) == true)
CLINEA 0000H 0001H 013BH 0003H 002AH
	mov	r0,	r8
	bl	_i2c_check_read_last_data
	cmp	r0,	#01h
	beq	_$M16
	b	_$L57
_$M16 :
CBLOCK 135 11 316

;;			startcode |= 0x80;									// if next data is last, ACK is set to HIGH
CLINEA 0000H 0001H 013DH 0004H 0049H
	mov	r4,	#081h	;; _lstartcode$6

;;			I2C[ch].status = I2C_MODE_RX_END;
CLINEA 0000H 0001H 013EH 0004H 0024H
	mov	r0,	r8
	mov	r1,	#00h
	mov	er2,	er0
	sllc	r3,	#03h
	sll	r2,	#03h
	add	er2,	er0
	add	er2,	er2
	mov	er0,	er2
	mov	r2,	#09h
	st	r2,	NEAR _I2C+0eh[er0]
CBLOCKEND 135 11 319

;;		break;
CLINEA 0000H 0001H 0140H 0003H 0008H
	b	_$L57

;;	case I2C_MODE_RX_END:
CLINEA 0000H 0001H 0141H 0002H 0016H
_$S84 :

;;		I2C[ch].rx_buffer[I2C[ch].rx_index] = *reg_RD; 			// set next data to rx register
CLINEA 0000H 0001H 0142H 0003H 0053H
	mov	r0,	r8
	mov	r1,	#00h
	mov	er2,	er0
	sllc	r3,	#03h
	sll	r2,	#03h
	add	er2,	er0
	add	er2,	er2
	l	er0,	NEAR _I2C+02h[er2]
	l	er2,	NEAR _I2C+04h[er2]
	add	er0,	er2
	l	r2,	[bp]
	st	r2,	[er0]

;;		I2C[ch].rx_index++;
CLINEA 0000H 0000H 0143H 0003H 0015H
	mov	r0,	r8
	mov	r1,	#00h
	mov	er2,	er0
	sllc	r3,	#03h
	sll	r2,	#03h
	add	er2,	er0
	add	er2,	er2
	mov	er0,	er2
	l	er2,	NEAR _I2C+04h[er2]
	add	er2,	#1 
	st	er2,	NEAR _I2C+04h[er0]

;;		if(I2C[ch].bStop == true)
CLINEA 0000H 0001H 0144H 0003H 001BH
	mov	r0,	r8
	mov	r1,	#00h
	mov	er2,	er0
	sllc	r3,	#03h
	sll	r2,	#03h
	add	er2,	er0
	add	er2,	er2
	l	r0,	NEAR _I2C+0fh[er2]
	cmp	r0,	#01h
	bne	_$L85
CBLOCK 135 12 325

;;			i2c_send_stopbit(ch);
CLINEA 0000H 0001H 0146H 0004H 0018H
	mov	r0,	r8
	bl	_i2c_send_stopbit

;;			I2C[ch].status = I2C_MODE_STOPBIT;
CLINEA 0000H 0001H 0147H 0004H 0025H
	mov	r0,	r8
	mov	r1,	#00h
	mov	er2,	er0
	sllc	r3,	#03h
	sll	r2,	#03h
	add	er2,	er0
	add	er2,	er2
	mov	er0,	er2
	mov	r2,	#03h
CBLOCKEND 135 12 328

;;		else
CLINEA 0000H 0001H 0149H 0003H 0006H
	bal	_$L87
_$L85 :
CBLOCK 135 13 330

;;			I2C[ch].status = I2C_MODE_READY;
CLINEA 0000H 0001H 014BH 0004H 0023H
	mov	r0,	r8
	mov	r1,	#00h
	mov	er2,	er0
	sllc	r3,	#03h
	sll	r2,	#03h
	add	er2,	er0
	add	er2,	er2
	mov	er0,	er2
	mov	r2,	#02h
CBLOCKEND 135 13 332

;;		}
CLINEA 0000H 0000H 014CH 0003H 0003H
_$L87 :
	st	r2,	NEAR _I2C+0eh[er0]

;;		break;
CLINEA 0000H 0001H 014DH 0003H 0008H
	b	_$L57

;;	case I2C_MODE_STOPBIT:
CLINEA 0000H 0001H 014FH 0002H 0017H
_$S88 :

;;		I2C[ch].status = I2C_MODE_READY;
CLINEA 0000H 0001H 0150H 0003H 0022H
	mov	r0,	r8
	mov	r1,	#00h
	mov	er2,	er0
	sllc	r3,	#03h
	sll	r2,	#03h
	add	er2,	er0
	add	er2,	er2
	mov	er0,	er2
	mov	r2,	#02h
	st	r2,	NEAR _I2C+0eh[er0]

;;		break;
CLINEA 0000H 0001H 0151H 0003H 0008H
	b	_$L57

;;	case I2C_MODE_READY:
CLINEA 0000H 0001H 0152H 0002H 0015H
_$S89 :

;;		break;
CLINEA 0000H 0001H 0153H 0003H 0008H
	b	_$L57

;;	default:
CLINEA 0000H 0001H 0155H 0002H 0009H
_$L58 :

;;		while(1){}
CLINEA 0000H 0000H 0156H 0003H 000CH
CBLOCK 135 14 342
CBLOCKEND 135 14 342
	bal	_$L58

;;		break;
CBLOCKEND 135 4 344
CBLOCKEND 135 1 348
CFUNCTIONEND 135


	rseg $$i2c_check_read_last_data$driver_i2c
CFUNCTION 143

_i2c_check_read_last_data	:
CBLOCK 143 1 351

;;{
CLINEA 0000H 0001H 015FH 0001H 0001H
;;*****************************************
;;	register/stack information
;;*****************************************
;;*****************************************

CBLOCK 143 2 351
CARGUMENT 46H 0001H 0014H "ch" 02H 00H 00H
CLOCAL 46H 0001H 0014H 0002H "ret" 02H 00H 00H

;;	if((I2C[ch].rx_length - I2C[ch].rx_index) > 1)
CLINEA 0000H 0001H 0161H 0002H 002FH
	mov	r1,	#00h
	mov	er2,	er0
	sllc	r3,	#03h
	sll	r2,	#03h
	add	er2,	er0
	add	er2,	er2
	l	er0,	NEAR _I2C+06h[er2]
	l	er2,	NEAR _I2C+04h[er2]
	sub	r0,	r2
	subc	r1,	r3
	cmp	r0,	#01h
	cmpc	r1,	#00h
	ble	_$L97

;;		ret = false;											// ACK = LOW
CLINEA 0000H 0001H 0162H 0003H 0025H
	mov	r0,	#00h

;;	else
CLINEA 0000H 0001H 0163H 0002H 0005H
	rt
_$L97 :

;;		ret = true;												// ACK = HIGH
CLINEA 0000H 0001H 0164H 0003H 0026H
	mov	r0,	#01h
_$L99 :

;;	return ret;
CLINEA 0000H 0001H 0165H 0002H 000CH
CBLOCKEND 143 2 358

;;}
CLINEA 0000H 0000H 0166H 0001H 0001H
	rt
CBLOCKEND 143 1 358
CFUNCTIONEND 143


	rseg $$i2c_update_err_code$driver_i2c
CFUNCTION 144

_i2c_update_err_code	:
CBLOCK 144 1 361

;;{
CLINEA 0000H 0001H 0169H 0001H 0001H
;;*****************************************
;;	register/stack information
;;*****************************************
;;*****************************************

	push	xr8
	mov	r8,	r0
	mov	er10,	er2
CBLOCK 144 2 361
CARGUMENT 46H 0001H 001CH "ch" 02H 00H 00H
CARGUMENT 46H 0002H 0029H "index" 02H 00H 01H
CLOCAL 46H 0001H 0015H 0002H "err_code" 02H 00H 00H

;;	unsigned char err_code = I2C_RESULT_OK;
CLINEA 0000H 0001H 016AH 0002H 0028H
	mov	r1,	#00h	;; _lerr_code$0

;;	if(ch == 0)
CLINEA 0000H 0001H 016BH 0002H 000CH
	cmp	r8,	#00h
	bne	_$L101
CBLOCK 144 3 364

;;		if(I20ER != 0)	err_code = I2C_RESULT_ERROR;
CLINEA 0000H 0001H 016DH 0003H 002DH
	tb	0f74ah.2
	beq	_$L103
	mov	r1,	#04h	;; _lerr_code$0
_$L103 :

;;		if(I20ACR != 0)
CLINEA 0000H 0001H 016EH 0003H 0011H
	tb	0f74ah.1
	beq	_$L115
CBLOCK 144 4 367

;;			err_code = (index ? I2C_RESULT_DNACK :I2C_RESULT_ANACK);
CLINEA 0000H 0000H 0170H 0004H 003BH
	mov	er10,	er10
	beq	_$L107
	mov	er0,	#3 
	bal	_$L109
_$L107 :
	mov	er0,	#2 
_$L109 :
	mov	r1,	r0	;; _lerr_code$0
CBLOCKEND 144 4 369

;;	else if(ch == 1)
CLINEA 0000H 0001H 0173H 0002H 0011H
	bal	_$L115
_$L101 :
	cmp	r8,	#01h
	bne	_$L115
CBLOCK 144 5 372

;;		if(I21ER != 0)	err_code = I2C_RESULT_ERROR;
CLINEA 0000H 0001H 0175H 0003H 002DH
	tb	0f75ah.2
	beq	_$L113
	mov	r1,	#04h	;; _lerr_code$0
_$L113 :

;;		if(I21ACR != 0)
CLINEA 0000H 0001H 0176H 0003H 0011H
	tb	0f75ah.1
	beq	_$L115
CBLOCK 144 6 375

;;			err_code = (index ?I2C_RESULT_DNACK :I2C_RESULT_ANACK);
CLINEA 0000H 0000H 0178H 0004H 003AH
	mov	er10,	er10
	beq	_$L117
	mov	er0,	#3 
	bal	_$L119
_$L117 :
	mov	er0,	#2 
_$L119 :
	mov	r1,	r0	;; _lerr_code$0
CBLOCKEND 144 6 377

;;		}
CLINEA 0000H 0000H 0179H 0003H 0003H
_$L115 :
CBLOCKEND 144 5 378

;;	return err_code;
CLINEA 0000H 0001H 017CH 0002H 0011H
	mov	r0,	r1
CBLOCKEND 144 3 381
CBLOCKEND 144 2 381

;;}
CLINEA 0000H 0000H 017DH 0001H 0001H
	pop	xr8
	rt
CBLOCKEND 144 1 381
CFUNCTIONEND 144


	rseg $$i2c_read_amount$driver_i2c
CFUNCTION 136

_i2c_read_amount	:
CBLOCK 136 1 384

;;{
CLINEA 0000H 0001H 0180H 0001H 0001H
;;*****************************************
;;	register/stack information
;;*****************************************
;;*****************************************

CBLOCK 136 2 384
CARGUMENT 46H 0001H 0014H "ch" 02H 00H 00H

;;	return(I2C[ch].rx_index);
CLINEA 0000H 0001H 0181H 0002H 001AH
	mov	r1,	#00h
	mov	er2,	er0
	sllc	r3,	#03h
	sll	r2,	#03h
	add	er2,	er0
	add	er2,	er2
	l	er0,	NEAR _I2C+04h[er2]
CBLOCKEND 136 2 386

;;}
CLINEA 0000H 0000H 0182H 0001H 0001H
	rt
CBLOCKEND 136 1 386
CFUNCTIONEND 136


	rseg $$i2c_get_err_status$driver_i2c
CFUNCTION 138

_i2c_get_err_status	:
CBLOCK 138 1 389

;;{
CLINEA 0000H 0001H 0185H 0001H 0001H
;;*****************************************
;;	register/stack information
;;*****************************************
;;*****************************************

CBLOCK 138 2 389
CARGUMENT 46H 0001H 0014H "ch" 02H 00H 00H

;;	return I2C[ch].err_code;
CLINEA 0000H 0001H 0186H 0002H 0019H
	mov	r1,	#00h
	mov	er2,	er0
	sllc	r3,	#03h
	sll	r2,	#03h
	add	er2,	er0
	add	er2,	er2
	l	r0,	NEAR _I2C+010h[er2]
CBLOCKEND 138 2 391

;;}
CLINEA 0000H 0000H 0187H 0001H 0001H
	rt
CBLOCKEND 138 1 391
CFUNCTIONEND 138


	rseg $$i2c_force_stop$driver_i2c
CFUNCTION 139

_i2c_force_stop	:
CBLOCK 139 1 394

;;{
CLINEA 0000H 0001H 018AH 0001H 0001H
;;*****************************************
;;	register/stack information
;;*****************************************
;;*****************************************

	push	lr
	push	er8
	mov	r8,	r0
CBLOCK 139 2 394
CRET 0002H
CARGUMENT 46H 0001H 001CH "ch" 02H 00H 00H

;;	i2c_send_stopbit(ch);
CLINEA 0000H 0001H 018BH 0002H 0016H
	bl	_i2c_send_stopbit

;;	I2C[ch].status = I2C_MODE_STOPBIT;
CLINEA 0000H 0001H 018CH 0002H 0023H
	mov	r0,	r8
	mov	r1,	#00h
	mov	er2,	er0
	sllc	r3,	#03h
	sll	r2,	#03h
	add	er2,	er0
	add	er2,	er2
	mov	er0,	er2
	mov	r2,	#03h
	st	r2,	NEAR _I2C+0eh[er0]
CBLOCKEND 139 2 397

;;}
CLINEA 0000H 0001H 018DH 0001H 0001H
	pop	er8
	pop	pc
CBLOCKEND 139 1 397
CFUNCTIONEND 139


	rseg $$i2c_close$driver_i2c
CFUNCTION 161

_i2c_close	:
CBLOCK 161 1 404

;;{
CLINEA 0000H 0001H 0194H 0001H 0001H
;;*****************************************
;;	register/stack information
;;*****************************************
;;*****************************************

CBLOCK 161 2 404
CARGUMENT 46H 0001H 0014H "ch" 02H 00H 00H

;;	switch(ch)
CLINEA 0000H 0001H 0195H 0002H 000BH
CBLOCK 161 3 406
	cmp	r0,	#00h
	beq	_$L129

;;	switch(ch)
CLINEA 0000H 0000H 0195H 0002H 000BH
	cmp	r0,	#01h
	beq	_$L130

;;	}
CLINEA 0000H 0000H 01A9H 0002H 0002H
CBLOCKEND 161 3 425
_$L127 :
CBLOCKEND 161 2 427

;;}
CLINEA 0000H 0000H 01ABH 0001H 0001H
	rt

;;	case 0:
CLINEA 0000H 0001H 0197H 0002H 0008H
_$L129 :

;;		P40MD1 = 0; P40MD0 = 0; P40C1 = 0; P40C0 = 0;	// port setting
CLINEA 0000H 0001H 0198H 0003H 003FH
	rb	0f235h.0
	rb	0f234h.0
	rb	0f233h.0
	rb	0f232h.0

;;		P41MD1 = 0; P41MD0 = 0; P41C1 = 0; P41C0 = 0;	// port setting
CLINEA 0000H 0001H 0199H 0003H 003FH
	rb	0f235h.1
	rb	0f234h.1
	rb	0f233h.1
	rb	0f232h.1

;;		I2C0MODL &= ~0x01;							// b1:400kbps,b0:I2C enable
CLINEA 0000H 0001H 019AH 0003H 0036H
	rb	0f748h.0

;;		EI2C0 = 0;		QI2C0 = 0;					// disenable I2C interrupt
CLINEA 0000H 0001H 019BH 0003H 0037H
	rb	0f012h.2
	rb	0f01ah.2

;;		I2C[ch].status = I2C_MODE_DIS;
CLINEA 0000H 0001H 019CH 0003H 0020H
	mov	r1,	#00h
	mov	er2,	er0
	sllc	r3,	#03h
	sll	r2,	#03h
	add	er2,	er0
	add	er2,	er2
	mov	er0,	er2
	mov	r2,	#00h
	st	r2,	NEAR _I2C+0eh[er0]

;;		set_bit(DI2C0);								// disenable I2C0
CLINEA 0000H 0001H 019DH 0003H 002AH
	sb	0f06ah.6

;;		break;
CLINEA 0000H 0001H 019EH 0003H 0008H
	rt

;;	case 1:
CLINEA 0000H 0001H 019FH 0002H 0008H
_$L130 :

;;		P35MD1 = 0;	P35MD0 = 0;P35C1 = 0; P35C0 = 0;	// port setting
CLINEA 0000H 0001H 01A0H 0003H 003EH
	rb	0f22dh.5
	rb	0f22ch.5
	rb	0f22bh.5
	rb	0f22ah.5

;;		P34MD1 = 0;	P34MD0 = 0;P34C1 = 0; P34C0 = 0;	// port setting
CLINEA 0000H 0001H 01A1H 0003H 003EH
	rb	0f22dh.4
	rb	0f22ch.4
	rb	0f22bh.4
	rb	0f22ah.4

;;		I2C1MODL &= ~0x01;								// I2C stop
CLINEA 0000H 0001H 01A2H 0003H 0027H
	rb	0f758h.0

;;		EI2C1 = 0;		QI2C1 = 0;					// disenable I2C interrupt
CLINEA 0000H 0001H 01A3H 0003H 0037H
	rb	0f012h.3
	rb	0f01ah.3

;;		I2C[ch].status = I2C_MODE_DIS;
CLINEA 0000H 0001H 01A4H 0003H 0020H
	mov	r1,	#00h
	mov	er2,	er0
	sllc	r3,	#03h
	sll	r2,	#03h
	add	er2,	er0
	add	er2,	er2
	mov	er0,	er2
	mov	r2,	#00h
	st	r2,	NEAR _I2C+0eh[er0]

;;		set_bit(DI2C1);								// disenable I2C1
CLINEA 0000H 0001H 01A5H 0003H 002AH
	sb	0f06ah.7

;;		break;
CLINEA 0000H 0001H 01A6H 0003H 0008H
	rt
CBLOCKEND 161 1 427
CFUNCTIONEND 161


	rseg $$i2c_write_amount$driver_i2c
CFUNCTION 137

_i2c_write_amount	:
CBLOCK 137 1 430

;;{
CLINEA 0000H 0001H 01AEH 0001H 0001H
;;*****************************************
;;	register/stack information
;;*****************************************
;;*****************************************

CBLOCK 137 2 430
CARGUMENT 46H 0001H 0014H "ch" 02H 00H 00H

;;	return(I2C[ch].tx_index);
CLINEA 0000H 0001H 01AFH 0002H 001AH
	mov	r1,	#00h
	mov	er2,	er0
	sllc	r3,	#03h
	sll	r2,	#03h
	add	er2,	er0
	add	er2,	er2
	l	er0,	NEAR _I2C+0ah[er2]
CBLOCKEND 137 2 432

;;}
CLINEA 0000H 0000H 01B0H 0001H 0001H
	rt
CBLOCKEND 137 1 432
CFUNCTIONEND 137

	public _i2c_set_tx_buf
	public _i2c_set_rx_buf
	public _i2c_begin
	public _i2c_get_err_status
	public _i2c_send_stopbit
	public _i2c_get_status
	public _i2c_set_address
	public _i2c_check_read_last_data
	public _i2c_isr
	public _i2c_update_err_code
	public _i2c_force_stop
	public _i2c0_isr
	public _i2c_start
	public _i2c_close
	public _i2c_init
	public _i2c_read_amount
	public _i2c1_isr
	public _i2c_write_amount
	extrn code near : _irq_sethandler
	extrn code near : _main

	rseg $$NTABi2c_isr$driver_i2c
_$M12 :
	dw	_$S89
	dw	_$S88
	dw	_$L58
	dw	_$L58
	dw	_$S59
	dw	_$S71
	dw	_$S81
	dw	_$S84

	rseg $$NVARdriver_i2c
_I2C :
	ds	024h

	end
