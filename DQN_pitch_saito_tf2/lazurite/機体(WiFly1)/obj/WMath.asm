;; Compile Options : /TML620504F /MS /near /IC:\LAZURI~1\LIBRAR~1\BM1383 /IC:\LAZURI~1\LIBRAR~1\BM1422 /IC:\LAZURI~1\LIBRAR~1\HARDWA~1 /IC:\LAZURI~1\LIBRAR~1\HARDWA~2 /IC:\LAZURI~1\LIBRAR~1\KXG03_~1 /IC:\LAZURI~1\LIBRAR~1\VL53L0X /IC:\LAZURI~1\LIBRAR~1\Wire /IC:\LAZURI~1\hardware\LAZURI~2 /IC:\LAZURI~1\hardware\LAZURI~2\lazurite /IC:\LAZURI~1\hardware\LAZURI~2\ML620Q~1 /IC:\LAZURI~1\hardware\LAZURI~2\ML620Q~1\clock /IC:\LAZURI~1\hardware\LAZURI~2\ML620Q~1\common /IC:\LAZURI~1\hardware\LAZURI~2\ML620Q~1\irq /IC:\LAZURI~1\hardware\LAZURI~2\ML620Q~1\lp /IC:\LAZURI~1\hardware\LAZURI~2\ML620Q~1\MCU_SM~1 /IC:\LAZURI~1\hardware\LAZURI~2\ML620Q~1\wdt /IC:\LAZURI~1\hardware\LAZURI~2\sub_ghz\ /D_ML620Q504 /DLAZURITE_MINI /DLAZURITE_IDE /DSUBGHZ /DPWR_LED /DLDO_CNT /SS 512 /SL 65 /SD /Oa /Ot /W 3 /Faobj\ /Lv 
;; Version Number  : Ver.3.53.1
;; File Name       : WMath.c

	type (ML620504F) 
	model small, near
	$$map$WMath segment code 2h #0h
	$$random$WMath segment code 2h #0h
	$$randomSeed$WMath segment code 2h #0h
CVERSION 3.53.1
CGLOBAL 01H 03H 0000H "map" 08H 02H 30H 00H 83H 1cH 00H 00H 02H
CGLOBAL 01H 03H 0000H "randomSeed" 08H 02H 2EH 00H 80H 00H 00H 00H 07H
CGLOBAL 01H 03H 0000H "random" 08H 02H 2FH 00H 83H 14H 00H 00H 02H
CSTRUCTTAG 0000H 0000H 0001H 0002H 00000008H "_Notag"
CSTRUCTMEM 43H 00000004H 00000000H "quot" 02H 00H 02H
CSTRUCTMEM 43H 00000004H 00000004H "rem" 02H 00H 02H
CSTRUCTTAG 0000H 0000H 0000H 0002H 00000004H "_Notag"
CSTRUCTMEM 43H 00000002H 00000000H "quot" 02H 00H 01H
CSTRUCTMEM 43H 00000002H 00000002H "rem" 02H 00H 01H
CTYPEDEF 0000H 0000H 43H "_Ptrdifft" 02H 00H 01H
CTYPEDEF 0000H 0000H 42H "_Sizet" 02H 00H 01H
CTYPEDEF 0000H 0000H 42H "size_t" 02H 00H 01H
CTYPEDEF 0000H 0000H 03H "_Cmpfun_nf" 08H 02H 01H 00H 00H 00H 00H 00H 01H
CTYPEDEF 0000H 0000H 03H "_Cmpfun_nn" 08H 02H 00H 00H 00H 00H 00H 00H 01H
CTYPEDEF 0000H 0000H 03H "_Cmpfun_ff" 08H 02H 03H 00H 00H 00H 00H 00H 01H
CTYPEDEF 0000H 0000H 03H "_Cmpfun_fn" 08H 02H 02H 00H 00H 00H 00H 00H 01H
CTYPEDEF 0000H 0000H 43H "div_t" 04H 00H 05H 00H 00H
CTYPEDEF 0000H 0000H 43H "ldiv_t" 04H 00H 05H 01H 00H
CFILE 0001H 000000DAH "C:\\LazuriteIDE\\bin\\U8Dev\\Inc\\stdlib.h"
CFILE 0002H 0000007AH "C:\\LazuriteIDE\\bin\\U8Dev\\Inc\\yvals.h"
CFILE 0000H 0000003BH "C:\\LAZURI~1\\hardware\\lazurite_subghz\\lazurite\\WMath.c"

	rseg $$randomSeed$WMath
CFUNCTION 46

_randomSeed	:
CBLOCK 46 1 41

;;{
CLINEA 0000H 0001H 0029H 0001H 0001H
;;*****************************************
;;	register/stack information
;;*****************************************
;;*****************************************

CBLOCK 46 2 41
CARGUMENT 46H 0002H 0024H "seed" 02H 00H 01H

;;	srand(seed);
CLINEA 0000H 0001H 002AH 0002H 000DH
	b	_srand
CBLOCKEND 46 2 44
CLINEA 0000H 0000H 002CH 0001H 0001H
CBLOCKEND 46 1 44
CFUNCTIONEND 46


	rseg $$random$WMath
CFUNCTION 47

_random	:
CBLOCK 47 1 47

;;{
CLINEA 0000H 0001H 002FH 0001H 0001H
;;*****************************************
;;	register/stack information
;;*****************************************
	_howbig$4	set	4
;;*****************************************

	push	lr
	push	fp
	mov	fp,	sp
	push	xr8
	push	xr4
	mov	er8,	er0
	mov	er10,	er2
CBLOCK 47 2 47
CRET 000AH
CARGUMENT 47H 0004H 2928H "howsmall" 02H 00H 02H
CARGUMENT 43H 0004H 0004H "howbig" 02H 00H 02H
CLOCAL 47H 0004H 2726H 0002H "diff" 02H 00H 02H

;;	if(howsmall >= howbig) return howsmall;
CLINEA 0000H 0001H 0031H 0002H 0028H
	l	er4,	_howbig$4[fp]
	l	er6,	_howbig$4+02h[fp]
	cmp	er0,	er4
	cmpc	r2,	r6
	cmpc	r3,	r7
	blts	_$L2
CBLOCKEND 47 2 52

;;}
CLINEA 0000H 0001H 0034H 0001H 0001H
_$L1 :
	pop	xr4
	pop	xr8
	mov	sp,	fp
	pop	fp
	pop	pc

;;	if(howsmall >= howbig) return howsmall;
CLINEA 0000H 0000H 0031H 0002H 0028H
_$L2 :

;;	diff = howbig - howsmall;
CLINEA 0000H 0001H 0032H 0002H 001AH
	mov	er0,	er4
	mov	er2,	er6
	sub	r0,	r8
	subc	r1,	r9
	subc	r2,	r10
	subc	r3,	r11
	mov	er4,	er0	;; _ldiff$0
	mov	er6,	er2	;; _ldiff$0

;;	return (rand()%diff + howsmall);
CLINEA 0000H 0001H 0033H 0002H 0021H
	bl	_rand
	mov	r2,	r1
	extbw	er2
	mov	r2,	r3
	push	xr0
	push	xr4
	bl	__lmodu8sw
	add	sp,	#4 
	pop	xr0
	add	er0,	er8
	addc	r2,	r10
	addc	r3,	r11
	bal	_$L1
CBLOCKEND 47 1 52
CFUNCTIONEND 47


	rseg $$map$WMath
CFUNCTION 48

_map	:
CBLOCK 48 1 55

;;{
CLINEA 0000H 0001H 0037H 0001H 0001H
;;*****************************************
;;	register/stack information
;;*****************************************
	_out_max$16	set	16
	_out_min$12	set	12
	_in_min$4	set	4
	_in_max$8	set	8
;;*****************************************

	push	lr
	push	fp
	mov	fp,	sp
	add	sp,	#-08
	push	xr8
	push	xr4
	mov	er8,	er0
	mov	er10,	er2
CBLOCK 48 2 55
CRET 0012H
CARGUMENT 47H 0004H 2928H "x" 02H 00H 02H
CARGUMENT 43H 0004H 0004H "in_min" 02H 00H 02H
CARGUMENT 43H 0004H 0008H "in_max" 02H 00H 02H
CARGUMENT 43H 0004H 000CH "out_min" 02H 00H 02H
CARGUMENT 43H 0004H 0010H "out_max" 02H 00H 02H

;;	return (out_min + (x - in_min) * (out_max - out_min) / (in_max - in_min));
CLINEA 0000H 0001H 0038H 0002H 004BH
	l	er4,	_in_min$4[fp]
	l	er6,	_in_min$4+02h[fp]
	sub	r0,	r4
	subc	r1,	r5
	subc	r2,	r6
	subc	r3,	r7
	l	er4,	_out_max$16[fp]
	l	er6,	_out_max$16+02h[fp]
	st	er0,	-4[fp]
	st	er2,	-2[fp]
	l	er0,	_out_min$12[fp]
	l	er2,	_out_min$12+02h[fp]
	sub	r4,	r0
	subc	r5,	r1
	subc	r6,	r2
	subc	r7,	r3
	l	er8,	-4[fp]
	mov	er0,	er8
	push	xr4
	l	er6,	-2[fp]
	mov	er2,	er6
	pop	xr4
	push	xr0
	push	xr4
	bl	__lmulu8sw
	add	sp,	#4 
	pop	xr4
	l	er0,	_in_max$8[fp]
	l	er2,	_in_max$8+02h[fp]
	st	er4,	-8[fp]
	st	er6,	-6[fp]
	l	er4,	_in_min$4[fp]
	l	er6,	_in_min$4+02h[fp]
	sub	r0,	r4
	subc	r1,	r5
	subc	r2,	r6
	subc	r3,	r7
	push	xr0
	l	er0,	-8[fp]
	l	er2,	-6[fp]
	mov	er4,	er0
	mov	er6,	er2
	pop	xr0
	push	qr0
	bl	__ldivu8sw
	add	sp,	#4 
	pop	xr0
	l	er4,	_out_min$12[fp]
	l	er6,	_out_min$12+02h[fp]
	add	er0,	er4
	addc	r2,	r6
	addc	r3,	r7
CBLOCKEND 48 2 57

;;}
CLINEA 0000H 0000H 0039H 0001H 0001H
	pop	xr4
	pop	xr8
	mov	sp,	fp
	pop	fp
	pop	pc
CBLOCKEND 48 1 57
CFUNCTIONEND 48

	public _map
	public _randomSeed
	public _random
	extrn code near : _rand
	extrn code near : _srand
	extrn code near : _main
	extrn code : __lmulu8sw
	extrn code : __ldivu8sw
	extrn code : __lmodu8sw

	end
