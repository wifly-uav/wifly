;; Compile Options : /TML620504F /MS /near /IC:\LAZURI~1\LIBRAR~1\BM1383 /IC:\LAZURI~1\LIBRAR~1\BM1422 /IC:\LAZURI~1\LIBRAR~1\HARDWA~1 /IC:\LAZURI~1\LIBRAR~1\HARDWA~2 /IC:\LAZURI~1\LIBRAR~1\KXG03_~1 /IC:\LAZURI~1\LIBRAR~1\VL53L0X /IC:\LAZURI~1\LIBRAR~1\Wire /IC:\LAZURI~1\hardware\LAZURI~2 /IC:\LAZURI~1\hardware\LAZURI~2\lazurite /IC:\LAZURI~1\hardware\LAZURI~2\ML620Q~1 /IC:\LAZURI~1\hardware\LAZURI~2\ML620Q~1\clock /IC:\LAZURI~1\hardware\LAZURI~2\ML620Q~1\common /IC:\LAZURI~1\hardware\LAZURI~2\ML620Q~1\irq /IC:\LAZURI~1\hardware\LAZURI~2\ML620Q~1\lp /IC:\LAZURI~1\hardware\LAZURI~2\ML620Q~1\MCU_SM~1 /IC:\LAZURI~1\hardware\LAZURI~2\ML620Q~1\wdt /IC:\LAZURI~1\hardware\LAZURI~2\sub_ghz\ /D_ML620Q504 /DLAZURITE_MINI /DLAZURITE_IDE /DSUBGHZ /DPWR_LED /DLDO_CNT /SS 512 /SL 65 /SD /Oa /Ot /W 3 /Faobj\ /Lv 
;; Version Number  : Ver.3.53.1
;; File Name       : random.c

	type (ML620504F) 
	model small, near
	$$NINITVAR segment data 2h #0h
	$$NINITTAB segment table 2h any
	$$rand$random segment code 2h #0h
	$$srand$random segment code 2h #0h
CVERSION 3.53.1
CGLOBAL 01H 03H 0000H "rand" 08H 02H 00H 00H 81H 0aH 00H 00H 01H
CGLOBAL 01H 03H 0000H "srand" 08H 02H 01H 00H 80H 00H 00H 00H 07H
CGLOBAL 01H 42H 0004H "seeds" 02H 00H 02H
CFILE 0000H 00000028H "C:\\LAZURI~1\\hardware\\lazurite_subghz\\lazurite\\random.c"

	rseg $$rand$random
CFUNCTION 0

_rand	:
CBLOCK 0 1 31

;;{	/* compute pseudo-random value */
CLINEA 0000H 0001H 001FH 0001H 0023H
;;*****************************************
;;	register/stack information
;;*****************************************
;;*****************************************

	push	lr
CBLOCK 0 2 31
CRET 0000H

;;	seeds = seeds * 1103515245 + 12345;
CLINEA 0000H 0001H 0020H 0002H 0024H
	l	er0,	NEAR _seeds
	l	er2,	NEAR _seeds+02h
	push	xr0
	mov	r0,	#06dh
	mov	r1,	#04eh
	mov	r2,	#0c6h
	mov	r3,	#041h
	push	xr0
	bl	__lmulu8sw
	add	sp,	#4 
	pop	xr0
	add	r0,	#039h
	addc	r1,	#030h
	addc	r2,	#00h
	addc	r3,	#00h
	st	er0,	NEAR _seeds
	st	er2,	NEAR _seeds+02h

;;	return ((unsigned int)(seeds >> 16) & RAND_MAX);
CLINEA 0000H 0001H 0021H 0002H 0031H
	mov	er0,	er2
	and	r1,	#07fh
CBLOCKEND 0 2 34

;;}
CLINEA 0000H 0000H 0022H 0001H 0001H
	pop	pc
CBLOCKEND 0 1 34
CFUNCTIONEND 0


	rseg $$srand$random
CFUNCTION 1

_srand	:
CBLOCK 1 1 37

;;{	/* alter the seeds */
CLINEA 0000H 0001H 0025H 0001H 0017H
;;*****************************************
;;	register/stack information
;;*****************************************
;;*****************************************

CBLOCK 1 2 37
CARGUMENT 46H 0002H 0024H "data" 02H 00H 01H

;;	seeds = data;
CLINEA 0000H 0001H 0026H 0002H 000EH
	mov	er2,	#0 
	st	er0,	NEAR _seeds
	st	er2,	NEAR _seeds+02h
CBLOCKEND 1 2 39

;;}
CLINEA 0000H 0001H 0027H 0001H 0001H
	rt
CBLOCKEND 1 1 39
CFUNCTIONEND 1

	public _seeds
	public _rand
	public _srand
	extrn code near : _main

	rseg $$NINITTAB
	dw	01h
	dw	00h

	rseg $$NINITVAR
_seeds :
	ds	04h
	extrn code : __lmulu8sw

	end
