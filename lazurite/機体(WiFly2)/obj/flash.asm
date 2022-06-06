;; Compile Options : /TML620504F /MS /near /IC:\LAZURI~1\LIBRAR~1\BM1383 /IC:\LAZURI~1\LIBRAR~1\BM1422 /IC:\LAZURI~1\LIBRAR~1\HARDWA~1 /IC:\LAZURI~1\LIBRAR~1\HARDWA~2 /IC:\LAZURI~1\LIBRAR~1\KXG03_~1 /IC:\LAZURI~1\LIBRAR~1\VL53L0X /IC:\LAZURI~1\LIBRAR~1\Wire /IC:\LAZURI~1\hardware\LAZURI~2 /IC:\LAZURI~1\hardware\LAZURI~2\lazurite /IC:\LAZURI~1\hardware\LAZURI~2\ML620Q~1 /IC:\LAZURI~1\hardware\LAZURI~2\ML620Q~1\clock /IC:\LAZURI~1\hardware\LAZURI~2\ML620Q~1\common /IC:\LAZURI~1\hardware\LAZURI~2\ML620Q~1\irq /IC:\LAZURI~1\hardware\LAZURI~2\ML620Q~1\lp /IC:\LAZURI~1\hardware\LAZURI~2\ML620Q~1\MCU_SM~1 /IC:\LAZURI~1\hardware\LAZURI~2\ML620Q~1\wdt /IC:\LAZURI~1\hardware\LAZURI~2\sub_ghz\ /D_ML620Q504 /DLAZURITE_MINI /DLAZURITE_IDE /DSUBGHZ /DPWR_LED /DLDO_CNT /SS 512 /SL 65 /SD /Oa /Ot /W 3 /Faobj\ /Lv 
;; Version Number  : Ver.3.53.1
;; File Name       : flash.c

	type (ML620504F) 
	model small, near
	$$TABFlash$flash segment table 2h #0h
	$$flash_read_word$flash segment code 2h #0h
	$$flash_write_word$flash segment code 2h #0h
CVERSION 3.53.1
CGLOBAL 01H 03H 0000H "flash_write_word" 08H 02H 0BH 00H 83H 0aH 00H 00H 07H
CGLOBAL 01H 03H 0000H "flash_read_word" 08H 02H 0CH 00H 81H 04H 00H 00H 08H
CSTRUCTTAG 0000H 0000H 0000H 0005H 0000000AH "_Notag"
CSTRUCTMEM 43H 00000002H 00000000H "write" 0AH 03H 00H 02H 05H 00H 00H 00H 00H 00H 07H
CSTRUCTMEM 42H 00000002H 00000002H "read" 0AH 03H 00H 02H 06H 00H 00H 00H 00H 00H 08H
CSTRUCTMEM 43H 00000002H 00000004H "erase" 0AH 03H 00H 02H 07H 00H 00H 00H 00H 00H 07H
CSTRUCTMEM 43H 00000002H 00000006H "write_byte" 0AH 03H 00H 02H 08H 00H 00H 00H 00H 00H 07H
CSTRUCTMEM 42H 00000002H 00000008H "read_byte" 0AH 03H 00H 02H 09H 00H 00H 00H 00H 00H 00H
CTYPEDEF 0000H 0000H 43H "DATAFLASH" 04H 00H 05H 00H 00H
CGLOBAL 01H 01H 000AH "Flash" 04H 00H 05H 00H 00H
CFILE 0001H 00000029H "C:\\LAZURI~1\\hardware\\LAZURI~2\\ML620Q~1\\driver_flash.h"
CFILE 0002H 00000031H "C:\\LAZURI~1\\hardware\\lazurite_subghz\\lazurite\\flash.h"
CFILE 0003H 00000040H "C:\\LAZURI~1\\hardware\\LAZURI~2\\ML620Q~1\\wdt\\wdt.h"
CFILE 0004H 00000045H "C:\\LAZURI~1\\hardware\\LAZURI~2\\ML620Q~1\\common\\rdwr_reg.h"
CFILE 0000H 00000031H "C:\\LAZURI~1\\hardware\\lazurite_subghz\\lazurite\\flash.c"

	rseg $$flash_write_word$flash
CFUNCTION 11

_flash_write_word	:
CBLOCK 11 1 27

;;{
CLINEA 0000H 0001H 001BH 0001H 0001H
;;*****************************************
;;	register/stack information
;;*****************************************
	_data$4	set	4
;;*****************************************

	push	lr
	push	fp
	mov	fp,	sp
	push	xr8
	mov	er10,	er2
	mov	r8,	r0
CBLOCK 11 2 27
CRET 0006H
CARGUMENT 46H 0001H 001CH "sector" 02H 00H 00H
CARGUMENT 46H 0002H 0029H "address" 02H 00H 01H
CARGUMENT 42H 0002H 0004H "data" 02H 00H 01H

;;	wdt_clear();
CLINEA 0000H 0001H 001CH 0002H 000DH
	bl	_wdt_clear

;;	address <<= 1;
CLINEA 0000H 0001H 001DH 0002H 000FH
	sllc	r11,	#01h
	sll	r10,	#01h

;;	flash_write(sector, address, data);
CLINEA 0000H 0001H 001EH 0002H 0024H
	l	er0,	_data$4[fp]
	push	er0
	mov	er2,	er10
	mov	r0,	r8
	bl	_flash_write
	add	sp,	#2 
CBLOCKEND 11 2 32

;;}
CLINEA 0000H 0001H 0020H 0001H 0001H
	pop	xr8
	mov	sp,	fp
	pop	fp
	pop	pc
CBLOCKEND 11 1 32
CFUNCTIONEND 11


	rseg $$flash_read_word$flash
CFUNCTION 12

_flash_read_word	:
CBLOCK 12 1 35

;;{
CLINEA 0000H 0001H 0023H 0001H 0001H
;;*****************************************
;;	register/stack information
;;*****************************************
;;*****************************************

	push	lr
	push	er8
	mov	r8,	r0
CBLOCK 12 2 35
CRET 0002H
CARGUMENT 46H 0001H 001CH "sector" 02H 00H 00H
CARGUMENT 46H 0002H 0025H "address" 02H 00H 01H

;;	address <<= 1;
CLINEA 0000H 0001H 0024H 0002H 000FH
	mov	er0,	er2
	sllc	r1,	#01h
	sll	r0,	#01h

;;	return flash_read(sector, address);
CLINEA 0000H 0001H 0025H 0002H 0024H
	mov	er2,	er0
	mov	r0,	r8
	bl	_flash_read
CBLOCKEND 12 2 38

;;}
CLINEA 0000H 0000H 0026H 0001H 0001H
	pop	er8
	pop	pc
CBLOCKEND 12 1 38
CFUNCTIONEND 12

	public _flash_write_word
	public _Flash
	public _flash_read_word
	extrn code near : _flash_read
	extrn code near : _wdt_clear
	extrn code near : _flash_erase
	extrn code near : _flash_read_byte
	extrn code near : _flash_write_byte
	extrn code near : _flash_write
	extrn code near : _main

	rseg $$TABFlash$flash
_Flash :
	dw	_flash_write_word
	dw	_flash_read_word
	dw	_flash_erase
	dw	_flash_write_byte
	dw	_flash_read_byte

	end
