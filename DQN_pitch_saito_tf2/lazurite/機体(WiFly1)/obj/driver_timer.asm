;; Compile Options : /TML620504F /MS /near /IC:\LAZURI~1\LIBRAR~1\BM1383 /IC:\LAZURI~1\LIBRAR~1\BM1422 /IC:\LAZURI~1\LIBRAR~1\HARDWA~1 /IC:\LAZURI~1\LIBRAR~1\HARDWA~2 /IC:\LAZURI~1\LIBRAR~1\KXG03_~1 /IC:\LAZURI~1\LIBRAR~1\VL53L0X /IC:\LAZURI~1\LIBRAR~1\Wire /IC:\LAZURI~1\hardware\LAZURI~2 /IC:\LAZURI~1\hardware\LAZURI~2\lazurite /IC:\LAZURI~1\hardware\LAZURI~2\ML620Q~1 /IC:\LAZURI~1\hardware\LAZURI~2\ML620Q~1\clock /IC:\LAZURI~1\hardware\LAZURI~2\ML620Q~1\common /IC:\LAZURI~1\hardware\LAZURI~2\ML620Q~1\irq /IC:\LAZURI~1\hardware\LAZURI~2\ML620Q~1\lp /IC:\LAZURI~1\hardware\LAZURI~2\ML620Q~1\MCU_SM~1 /IC:\LAZURI~1\hardware\LAZURI~2\ML620Q~1\wdt /IC:\LAZURI~1\hardware\LAZURI~2\sub_ghz\ /D_ML620Q504 /DLAZURITE_MINI /DLAZURITE_IDE /DSUBGHZ /DPWR_LED /DLDO_CNT /SS 512 /SL 65 /SD /Oa /Ot /W 3 /Faobj\ /Lv 
;; Version Number  : Ver.3.53.1
;; File Name       : driver_timer.c

	type (ML620504F) 
	model small, near
	$$TABnum_to_bit$driver_timer segment table 2h #0h
	$$timer_16bit_set$driver_timer segment code 2h #0h
	$$timer_16bit_start$driver_timer segment code 2h #0h
	$$timer_16bit_stop$driver_timer segment code 2h #0h
	$$timer_8bit_set$driver_timer segment code 2h #0h
	$$timer_8bit_start$driver_timer segment code 2h #0h
	$$timer_8bit_stop$driver_timer segment code 2h #0h
CVERSION 3.53.1
CGLOBAL 01H 03H 0000H "timer_16bit_set" 08H 02H 56H 00H 83H 0eH 00H 00H 07H
CGLOBAL 01H 03H 0000H "timer_16bit_start" 08H 02H 57H 00H 80H 02H 00H 00H 07H
CGLOBAL 01H 03H 0000H "timer_8bit_set" 08H 02H 52H 00H 83H 0eH 00H 00H 07H
CGLOBAL 01H 03H 0000H "timer_16bit_stop" 08H 02H 58H 00H 80H 02H 00H 00H 07H
CGLOBAL 01H 03H 0000H "timer_8bit_stop" 08H 02H 54H 00H 80H 02H 00H 00H 07H
CGLOBAL 01H 03H 0000H "timer_8bit_start" 08H 02H 53H 00H 80H 02H 00H 00H 07H
CSTRUCTTAG 0000H 0000H 0000H 0008H 00000001H "_Notag"
CSTRUCTMEM 52H 00000001H 00000000H "b0" 02H 00H 00H
CSTRUCTMEM 52H 00000001H 00000001H "b1" 02H 00H 00H
CSTRUCTMEM 52H 00000001H 00000002H "b2" 02H 00H 00H
CSTRUCTMEM 52H 00000001H 00000003H "b3" 02H 00H 00H
CSTRUCTMEM 52H 00000001H 00000004H "b4" 02H 00H 00H
CSTRUCTMEM 52H 00000001H 00000005H "b5" 02H 00H 00H
CSTRUCTMEM 52H 00000001H 00000006H "b6" 02H 00H 00H
CSTRUCTMEM 52H 00000001H 00000007H "b7" 02H 00H 00H
CENUMTAG 0000H 0000H 0001H 0008H "_Notag"
CENUMMEM 00000000H "TM_CH0"
CENUMMEM 00000001H "TM_CH1"
CENUMMEM 00000002H "TM_CH2"
CENUMMEM 00000003H "TM_CH3"
CENUMMEM 00000004H "TM_CH4"
CENUMMEM 00000005H "TM_CH5"
CENUMMEM 00000006H "TM_CH6"
CENUMMEM 00000007H "TM_CH7"
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
CTYPEDEF 0000H 0000H 43H "TM_CH" 04H 00H 0AH 01H 00H
CTYPEDEF 0000H 0000H 43H "CHAR" 02H 00H 00H
CTYPEDEF 0000H 0000H 42H "UINT16" 02H 00H 01H
CTYPEDEF 0000H 0000H 42H "UINT32" 02H 00H 02H
CTYPEDEF 0000H 0000H 42H "boolean" 02H 00H 00H
CTYPEDEF 0000H 0000H 42H "word" 02H 00H 01H
CTYPEDEF 0000H 0000H 42H "BOOL" 02H 00H 00H
CTYPEDEF 0000H 0000H 42H "uint32_t" 02H 00H 02H
CTYPEDEF 0000H 0000H 43H "_BYTE_FIELD" 04H 00H 05H 00H 00H
CTYPEDEF 0000H 0000H 42H "uint16_t" 02H 00H 08H
CGLOBAL 01H 01H 0008H "num_to_bit" 05H 01H 08H 00H 00H 00H
CFILE 0001H 0000007BH "C:\\LAZURI~1\\hardware\\LAZURI~2\\common.h"
CFILE 0002H 00000F42H "C:\\LazuriteIDE\\bin\\U8Dev\\Inc\\ml620504F.h"
CFILE 0003H 000000C9H "C:\\LazuriteIDE\\bin\\U8Dev\\Inc\\string.h"
CFILE 0004H 0000007AH "C:\\LazuriteIDE\\bin\\U8Dev\\Inc\\yvals.h"
CFILE 0005H 00000035H "C:\\LAZURI~1\\hardware\\lazurite_subghz\\ml620q504\\driver_timer.h"
CFILE 0006H 0000006FH "C:\\LAZURI~1\\hardware\\lazurite_subghz\\ml620q504\\driver_irq.h"
CFILE 0007H 00000331H "C:\\LAZURI~1\\hardware\\LAZURI~2\\ML620Q~1\\irq\\irq.h"
CFILE 0008H 00000045H "C:\\LAZURI~1\\hardware\\LAZURI~2\\ML620Q~1\\common\\rdwr_reg.h"
CFILE 0009H 00000022H "C:\\LAZURI~1\\hardware\\LAZURI~2\\ML620Q~1\\MCU_SM~1\\mcu.h"
CFILE 0000H 000000A6H "C:\\LAZURI~1\\hardware\\lazurite_subghz\\ml620q504\\driver_timer.c"

	rseg $$timer_8bit_set$driver_timer
CFUNCTION 82

_timer_8bit_set	:
CBLOCK 82 1 54

;;{
CLINEA 0000H 0001H 0036H 0001H 0001H
;;*****************************************
;;	register/stack information
;;*****************************************
	_func$4	set	4
;;*****************************************

	push	lr
	push	fp
	mov	fp,	sp
	push	xr8
	push	xr4
	push	bp
	mov	r8,	r0
	mov	r10,	r2
	mov	r9,	r1
CBLOCK 82 2 54
CRET 000CH
CARGUMENT 46H 0001H 001CH "ch" 02H 00H 00H
CARGUMENT 46H 0001H 001DH "TMnCON" 02H 00H 00H
CARGUMENT 46H 0001H 001EH "TMnD" 02H 00H 00H
CARGUMENT 43H 0002H 0004H "func" 0AH 03H 00H 02H 59H 00H 00H 00H 00H 00H 07H
CLOCAL 46H 0002H 002AH 0002H "pTMnD" 04H 03H 00H 00H 00H
CLOCAL 46H 0002H 0026H 0002H "pTMnC" 04H 03H 00H 00H 00H
CLOCAL 46H 0002H 0027H 0002H "pTMnCON" 04H 03H 00H 00H 00H

;;	if(ch >= 8) return;
CLINEA 0000H 0001H 003CH 0002H 0014H
	cmp	r0,	#08h
	blt	_$L1
CBLOCKEND 82 2 82

;;}
CLINEA 0000H 0001H 0052H 0001H 0001H
_$L0 :
	pop	bp
	pop	xr4
	pop	xr8
	mov	sp,	fp
	pop	fp
	pop	pc

;;	if(ch >= 8) return;
CLINEA 0000H 0000H 003CH 0002H 0014H
_$L1 :

;;	pTMnD += ch;
CLINEA 0000H 0001H 003FH 0002H 000DH
	mov	r1,	#00h
	mov	er2,	er0
	add	r2,	#00h
	addc	r3,	#0f3h
	mov	bp,	er2	;; _lpTMnD$0

;;	pTMnC += ch;
CLINEA 0000H 0001H 0041H 0002H 000DH
	mov	er2,	er0
	add	r2,	#010h
	addc	r3,	#0f3h
	mov	er4,	er2	;; _lpTMnC$2

;;	pTMnCON += ch;
CLINEA 0000H 0001H 0043H 0002H 000FH
	mov	er2,	er0
	add	r2,	#020h
	addc	r3,	#0f3h
	mov	er6,	er2	;; _lpTMnCON$4

;;	BLKCON0 &= ~num_to_bit[ch];					// enabling timer0, timer1
CLINEA 0000H 0001H 0045H 0002H 003BH
	l	r0,	NEAR _num_to_bit[er0]
	xor	r0,	#0ffh
	l	r1,	0f068h
	and	r1,	r0
	st	r1,	0f068h

;;	TMSTP0  |=  num_to_bit[ch];					// stop timer0, timer1
CLINEA 0000H 0001H 0046H 0002H 0037H
	mov	r0,	r8
	mov	r1,	#00h
	l	r2,	0f332h
	l	r0,	NEAR _num_to_bit[er0]
	or	r2,	r0
	st	r2,	0f332h

;;	IRQ5 &= ~num_to_bit[ch];						// clear irq of timer0, timer1
CLINEA 0000H 0001H 0048H 0002H 003DH
	mov	r0,	r8
	l	r0,	NEAR _num_to_bit[er0]
	xor	r0,	#0ffh
	l	r1,	0f01dh
	and	r1,	r0
	st	r1,	0f01dh

;;	IE5  &= ~num_to_bit[ch];						// clear ie of timer0, timer1
CLINEA 0000H 0001H 0049H 0002H 003CH
	mov	r0,	r8
	mov	r1,	#00h
	l	r0,	NEAR _num_to_bit[er0]
	xor	r0,	#0ffh
	l	r1,	0f015h
	and	r1,	r0
	st	r1,	0f015h

;;	*pTMnD = TMnD;
CLINEA 0000H 0001H 004BH 0002H 000FH
	st	r10,	[bp]

;;	*pTMnC = 0;
CLINEA 0000H 0001H 004CH 0002H 000CH
	mov	r0,	#00h
	st	r0,	[er4]

;;	*pTMnCON = TMnCON;
CLINEA 0000H 0001H 004DH 0002H 0013H
	st	r9,	[er6]

;;	irq_sethandler((unsigned char)(IRQ_NO_TM0INT + ch),func);		// set IRQ handler
CLINEA 0000H 0001H 004FH 0002H 004EH
	l	er2,	_func$4[fp]
	mov	r0,	r8
	add	r0,	#017h
	bl	_irq_sethandler

;;	return;
CLINEA 0000H 0001H 0051H 0002H 0008H
	bal	_$L0
CBLOCKEND 82 1 82
CFUNCTIONEND 82


	rseg $$timer_8bit_start$driver_timer
CFUNCTION 83

_timer_8bit_start	:
CBLOCK 83 1 85

;;{
CLINEA 0000H 0001H 0055H 0001H 0001H
;;*****************************************
;;	register/stack information
;;*****************************************
;;*****************************************

	push	er8
	mov	r8,	r0
CBLOCK 83 2 85
CARGUMENT 46H 0001H 001CH "ch" 02H 00H 00H

;;	if(ch >= 8) return;
CLINEA 0000H 0001H 0057H 0002H 0014H
	cmp	r0,	#08h
	blt	_$L4
CBLOCKEND 83 2 92

;;}
CLINEA 0000H 0001H 005CH 0001H 0001H
_$L3 :
	pop	er8
	rt

;;	if(ch >= 8) return;
CLINEA 0000H 0000H 0057H 0002H 0014H
_$L4 :

;;	IE5    |= num_to_bit[ch];						// set ie of timer0, timer1
CLINEA 0000H 0001H 0059H 0002H 003BH
	mov	r1,	#00h
	l	r2,	0f015h
	l	r0,	NEAR _num_to_bit[er0]
	or	r2,	r0
	st	r2,	0f015h

;;	TMSTR0 |= num_to_bit[ch];						// start timer0, timer1
CLINEA 0000H 0001H 005AH 0002H 0037H
	mov	r0,	r8
	l	r2,	0f330h
	l	r0,	NEAR _num_to_bit[er0]
	or	r2,	r0
	st	r2,	0f330h

;;	return;
CLINEA 0000H 0001H 005BH 0002H 0008H
	bal	_$L3
CBLOCKEND 83 1 92
CFUNCTIONEND 83


	rseg $$timer_8bit_stop$driver_timer
CFUNCTION 84

_timer_8bit_stop	:
CBLOCK 84 1 95

;;{
CLINEA 0000H 0001H 005FH 0001H 0001H
;;*****************************************
;;	register/stack information
;;*****************************************
;;*****************************************

	push	er8
	mov	r8,	r0
CBLOCK 84 2 95
CARGUMENT 46H 0001H 001CH "ch" 02H 00H 00H

;;	if(ch >= 8) return;
CLINEA 0000H 0001H 0061H 0002H 0014H
	cmp	r0,	#08h
	bge	_$L6

;;	TMSTP0 |= num_to_bit[ch];						// stop timer0, timer1
CLINEA 0000H 0001H 0063H 0002H 0036H
	mov	r1,	#00h
	l	r2,	0f332h
	l	r0,	NEAR _num_to_bit[er0]
	or	r2,	r0
	st	r2,	0f332h

;;	IE5 &= ~num_to_bit[ch];						// disenable timer0, timer1
CLINEA 0000H 0001H 0064H 0002H 0039H
	mov	r0,	r8
	l	r0,	NEAR _num_to_bit[er0]
	xor	r0,	#0ffh
	l	r1,	0f015h
	and	r1,	r0
	st	r1,	0f015h

;;	BLKCON0 |= num_to_bit[ch];					// power down timer0, timer1
CLINEA 0000H 0001H 0065H 0002H 003CH
	mov	r0,	r8
	mov	r1,	#00h
	l	r2,	0f068h
	l	r0,	NEAR _num_to_bit[er0]
	or	r2,	r0
	st	r2,	0f068h
CBLOCKEND 84 2 103

;;}
CLINEA 0000H 0001H 0067H 0001H 0001H
_$L6 :
	pop	er8
	rt
CBLOCKEND 84 1 103
CFUNCTIONEND 84


	rseg $$timer_16bit_set$driver_timer
CFUNCTION 86

_timer_16bit_set	:
CBLOCK 86 1 110

;;{
CLINEA 0000H 0001H 006EH 0001H 0001H
;;*****************************************
;;	register/stack information
;;*****************************************
	_func$4	set	4
;;*****************************************

	push	lr
	push	fp
	mov	fp,	sp
	push	xr8
	push	xr4
	push	bp
	mov	r8,	r0
	mov	er10,	er2
	mov	r9,	r1
CBLOCK 86 2 110
CRET 000CH
CARGUMENT 46H 0001H 001CH "ch" 02H 00H 00H
CARGUMENT 46H 0001H 001DH "TMnCON" 02H 00H 00H
CARGUMENT 46H 0002H 0029H "TMnnD" 02H 00H 01H
CARGUMENT 43H 0002H 0004H "func" 0AH 03H 00H 02H 5DH 00H 00H 00H 00H 00H 07H
CLOCAL 46H 0002H 002AH 0002H "pTMnnD" 04H 03H 00H 00H 08H
CLOCAL 46H 0002H 0026H 0002H "pTMnnC" 04H 03H 00H 00H 08H
CLOCAL 46H 0002H 0027H 0002H "pTMnCON" 04H 03H 00H 00H 00H

;;	if(ch >= 8) return;
CLINEA 0000H 0001H 0074H 0002H 0014H
	cmp	r0,	#08h
	blt	_$L10
CBLOCKEND 86 2 139

;;}
CLINEA 0000H 0001H 008BH 0001H 0001H
_$L9 :
	pop	bp
	pop	xr4
	pop	xr8
	mov	sp,	fp
	pop	fp
	pop	pc

;;	if(ch >= 8) return;
CLINEA 0000H 0000H 0074H 0002H 0014H
_$L10 :

;;	ch &= 0xFE;
CLINEA 0000H 0001H 0075H 0002H 000CH
	and	r8,	#0feh

;;	pTMnnD += (ch>>1);
CLINEA 0000H 0001H 0078H 0002H 0013H
	mov	r2,	r8
	mov	r3,	#00h
	mov	er0,	er2
	srlc	r0,	#01h
	sra	r1,	#01h
	add	er0,	er0
	mov	bp,	er0
	add	r12,	#00h
	addc	r13,	#0f3h

;;	pTMnnC += (ch>>1);
CLINEA 0000H 0001H 007AH 0002H 0013H
	add	r0,	#010h
	addc	r1,	#0f3h
	mov	er4,	er0	;; _lpTMnnC$2

;;	pTMnCON += ch;
CLINEA 0000H 0001H 007CH 0002H 000FH
	mov	er0,	er2
	add	r0,	#020h
	addc	r1,	#0f3h
	mov	er6,	er0	;; _lpTMnCON$4

;;	BLKCON0 &= ~(num_to_bit[ch] | num_to_bit[ch+1]);		// enabling timer0, timer1
CLINEA 0000H 0001H 007EH 0002H 004DH
	l	r0,	NEAR _num_to_bit[er2]
	l	r1,	NEAR _num_to_bit+01h[er2]
	or	r0,	r1
	xor	r0,	#0ffh
	l	r1,	0f068h
	and	r1,	r0
	st	r1,	0f068h

;;	TMSTP0  |=  (num_to_bit[ch] | num_to_bit[ch+1]);		// stop timer0, timer1
CLINEA 0000H 0001H 007FH 0002H 0049H
	mov	r0,	r8
	mov	r1,	#00h
	mov	er2,	er0
	l	r0,	NEAR _num_to_bit[er0]
	l	r1,	NEAR _num_to_bit+01h[er2]
	or	r0,	r1
	l	r1,	0f332h
	or	r1,	r0
	st	r1,	0f332h

;;	IRQ5 &= ~(num_to_bit[ch] | num_to_bit[ch+1]);			// clear irq of timer0, timer1
CLINEA 0000H 0001H 0081H 0002H 004FH
	mov	r0,	r8
	mov	r1,	#00h
	mov	er2,	er0
	l	r0,	NEAR _num_to_bit[er0]
	l	r1,	NEAR _num_to_bit+01h[er2]
	or	r0,	r1
	xor	r0,	#0ffh
	l	r1,	0f01dh
	and	r1,	r0
	st	r1,	0f01dh

;;	IE5  &= ~(num_to_bit[ch] | num_to_bit[ch+1]);			// clear ie of timer0, timer1
CLINEA 0000H 0001H 0082H 0002H 004EH
	mov	r0,	r8
	mov	r1,	#00h
	mov	er2,	er0
	l	r0,	NEAR _num_to_bit[er0]
	l	r1,	NEAR _num_to_bit+01h[er2]
	or	r0,	r1
	xor	r0,	#0ffh
	l	r1,	0f015h
	and	r1,	r0
	st	r1,	0f015h

;;	*pTMnnD = TMnnD;
CLINEA 0000H 0001H 0084H 0002H 0011H
	st	er10,	[bp]

;;	*pTMnnC = 0;
CLINEA 0000H 0001H 0085H 0002H 000DH
	mov	er0,	#0 
	st	er0,	[er4]

;;	*pTMnCON = TMnCON;
CLINEA 0000H 0001H 0086H 0002H 0013H
	st	r9,	[er6]

;;	irq_sethandler((unsigned char)(IRQ_NO_TM0INT + ch + 1),func);				// set IRQ handler
CLINEA 0000H 0001H 0088H 0002H 0054H
	l	er2,	_func$4[fp]
	mov	r0,	r8
	add	r0,	#018h
	bl	_irq_sethandler

;;	return;
CLINEA 0000H 0001H 008AH 0002H 0008H
	b	_$L9
CBLOCKEND 86 1 139
CFUNCTIONEND 86


	rseg $$timer_16bit_start$driver_timer
CFUNCTION 87

_timer_16bit_start	:
CBLOCK 87 1 142

;;{
CLINEA 0000H 0001H 008EH 0001H 0001H
;;*****************************************
;;	register/stack information
;;*****************************************
;;*****************************************

	push	er8
	mov	r8,	r0
CBLOCK 87 2 142
CARGUMENT 46H 0001H 001CH "ch" 02H 00H 00H

;;	if(ch >= 8) return;
CLINEA 0000H 0001H 0090H 0002H 0014H
	cmp	r0,	#08h
	blt	_$L13
CBLOCKEND 87 2 150

;;}
CLINEA 0000H 0001H 0096H 0001H 0001H
_$L12 :
	pop	er8
	rt

;;	if(ch >= 8) return;
CLINEA 0000H 0000H 0090H 0002H 0014H
_$L13 :

;;	ch &= 0xFE;
CLINEA 0000H 0001H 0091H 0002H 000CH
	and	r8,	#0feh
	mov	r0,	r8

;;	IE5    |= (num_to_bit[ch+1]);							// set ie of timer0, timer1
CLINEA 0000H 0001H 0093H 0002H 0040H
	mov	r1,	#00h
	l	r2,	0f015h
	l	r0,	NEAR _num_to_bit+01h[er0]
	or	r2,	r0
	st	r2,	0f015h

;;	TMSTR0 |= (num_to_bit[ch]);							// start timer0, timer1
CLINEA 0000H 0001H 0094H 0002H 003AH
	mov	r0,	r8
	l	r2,	0f330h
	l	r0,	NEAR _num_to_bit[er0]
	or	r2,	r0
	st	r2,	0f330h

;;	return;
CLINEA 0000H 0001H 0095H 0002H 0008H
	bal	_$L12
CBLOCKEND 87 1 150
CFUNCTIONEND 87


	rseg $$timer_16bit_stop$driver_timer
CFUNCTION 88

_timer_16bit_stop	:
CBLOCK 88 1 153

;;{
CLINEA 0000H 0001H 0099H 0001H 0001H
;;*****************************************
;;	register/stack information
;;*****************************************
;;*****************************************

	push	er8
	mov	r8,	r0
CBLOCK 88 2 153
CARGUMENT 46H 0001H 001CH "ch" 02H 00H 00H

;;	if(ch >= 8) return;
CLINEA 0000H 0001H 009BH 0002H 0014H
	cmp	r0,	#08h
	blt	_$L16
CBLOCKEND 88 2 163

;;}
CLINEA 0000H 0001H 00A3H 0001H 0001H
_$L15 :
	pop	er8
	rt

;;	if(ch >= 8) return;
CLINEA 0000H 0000H 009BH 0002H 0014H
_$L16 :

;;	ch &= 0xFE;
CLINEA 0000H 0001H 009CH 0002H 000CH
	and	r8,	#0feh
	mov	r0,	r8

;;	TMSTP0 |= (num_to_bit[ch]);							// stop timer0, timer1
CLINEA 0000H 0001H 009EH 0002H 0039H
	mov	r1,	#00h
	l	r2,	0f332h
	l	r0,	NEAR _num_to_bit[er0]
	or	r2,	r0
	st	r2,	0f332h

;;	IE5 &= ~(num_to_bit[ch] | num_to_bit[ch+1]);		// disenable timer0, timer1
CLINEA 0000H 0001H 009FH 0002H 004AH
	mov	r0,	r8
	mov	er2,	er0
	l	r0,	NEAR _num_to_bit[er0]
	l	r1,	NEAR _num_to_bit+01h[er2]
	or	r0,	r1
	xor	r0,	#0ffh
	l	r1,	0f015h
	and	r1,	r0
	st	r1,	0f015h

;;	BLKCON0 |= (num_to_bit[ch] | num_to_bit[ch+1]);		// power down timer0, timer1
CLINEA 0000H 0001H 00A0H 0002H 004EH
	mov	r0,	r8
	mov	r1,	#00h
	mov	er2,	er0
	l	r0,	NEAR _num_to_bit[er0]
	l	r1,	NEAR _num_to_bit+01h[er2]
	or	r0,	r1
	l	r1,	0f068h
	or	r1,	r0
	st	r1,	0f068h

;;	return;
CLINEA 0000H 0001H 00A2H 0002H 0008H
	bal	_$L15
CBLOCKEND 88 1 163
CFUNCTIONEND 88

	public _timer_16bit_set
	public _timer_16bit_start
	public _timer_8bit_set
	public _timer_16bit_stop
	public _timer_8bit_stop
	public _num_to_bit
	public _timer_8bit_start
	extrn code near : _irq_sethandler
	extrn code near : _main

	rseg $$TABnum_to_bit$driver_timer
_num_to_bit :
	db	01h
	db	02h
	db	04h
	db	08h
	db	010h
	db	020h
	db	040h
	db	080h

	end
