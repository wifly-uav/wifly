;; Compile Options : /TML620504F /MS /near /IC:\LAZURI~1\LIBRAR~1\BM1383 /IC:\LAZURI~1\LIBRAR~1\BM1422 /IC:\LAZURI~1\LIBRAR~1\HARDWA~1 /IC:\LAZURI~1\LIBRAR~1\HARDWA~2 /IC:\LAZURI~1\LIBRAR~1\KXG03_~1 /IC:\LAZURI~1\LIBRAR~1\VL53L0X /IC:\LAZURI~1\LIBRAR~1\Wire /IC:\LAZURI~1\hardware\LAZURI~2 /IC:\LAZURI~1\hardware\LAZURI~2\lazurite /IC:\LAZURI~1\hardware\LAZURI~2\ML620Q~1 /IC:\LAZURI~1\hardware\LAZURI~2\ML620Q~1\clock /IC:\LAZURI~1\hardware\LAZURI~2\ML620Q~1\common /IC:\LAZURI~1\hardware\LAZURI~2\ML620Q~1\irq /IC:\LAZURI~1\hardware\LAZURI~2\ML620Q~1\lp /IC:\LAZURI~1\hardware\LAZURI~2\ML620Q~1\MCU_SM~1 /IC:\LAZURI~1\hardware\LAZURI~2\ML620Q~1\wdt /IC:\LAZURI~1\hardware\LAZURI~2\sub_ghz\ /D_ML620Q504 /DLAZURITE_MINI /DLAZURITE_IDE /DSUBGHZ /DPWR_LED /DLDO_CNT /SS 512 /SL 65 /SD /Oa /Ot /W 3 /Faobj\ /Lv 
;; Version Number  : Ver.3.53.1
;; File Name       : driver_uart.c

	type (ML620504F) 
	model small, near
	$$NVARdriver_uart segment data 2h #0h
	$$NINITVAR segment data 2h #0h
	$$NINITTAB segment table 2h any
	$$TABuart_gpio_rx_bitmask$driver_uart segment table 2h #0h
	$$TABuart_gpio_tx_bitmask$driver_uart segment table 2h #0h
	$$uart_begin$driver_uart segment code 2h #0h
	$$uart_check_irq$driver_uart segment code 2h #0h
	$$uart_end$driver_uart segment code 2h #0h
	$$uart_fifo_in$driver_uart segment code 2h #0h
	$$uart_fifo_init$driver_uart segment code 2h #0h
	$$uart_fifo_out$driver_uart segment code 2h #0h
	$$uart_fifo_out_peek$driver_uart segment code 2h #0h
	$$uart_flush$driver_uart segment code 2h #0h
	$$uart_gpio_end$driver_uart segment code 2h #0h
	$$uart_gpio_init$driver_uart segment code 2h #0h
	$$uart_peek$driver_uart segment code 2h #0h
	$$uart_rx_available$driver_uart segment code 2h #0h
	$$uart_rx_isr$driver_uart segment code 2h #0h
	$$uart_rx_read$driver_uart segment code 2h #0h
	$$uart_tx_available$driver_uart segment code 2h #0h
	$$uart_tx_isr$driver_uart segment code 2h #0h
	$$uart_tx_write$driver_uart segment code 2h #0h
	$$uartf_begin$driver_uart segment code 2h #0h
	$$uartf_end$driver_uart segment code 2h #0h
	$$uartf_flush$driver_uart segment code 2h #0h
	$$uartf_isr$driver_uart segment code 2h #0h
	$$uartf_peek$driver_uart segment code 2h #0h
	$$uartf_rx_available$driver_uart segment code 2h #0h
	$$uartf_rx_read$driver_uart segment code 2h #0h
	$$uartf_tx_available$driver_uart segment code 2h #0h
	$$uartf_tx_write$driver_uart segment code 2h #0h
CVERSION 3.53.1
CGLOBAL 01H 03H 0000H "uartf_rx_read" 08H 02H 62H 00H 81H 04H 00H 00H 01H
CGLOBAL 01H 03H 0000H "uart_check_irq" 08H 02H 6DH 00H 81H 02H 00H 00H 07H
CGLOBAL 01H 03H 0000H "uart_fifo_init" 08H 02H 67H 00H 80H 00H 00H 00H 07H
CGLOBAL 01H 03H 0000H "uart_gpio_init" 08H 02H 51H 00H 80H 08H 00H 00H 07H
CGLOBAL 01H 03H 0000H "uart_rx_read" 08H 02H 61H 00H 81H 04H 00H 00H 01H
CGLOBAL 01H 03H 0000H "uartf_begin" 08H 02H 5BH 00H 83H 14H 00H 00H 07H
CGLOBAL 01H 02H 0000H "uartf_tx_write" 08H 02H 60H 00H 81H 06H 00H 00H 01H
CGLOBAL 01H 03H 0000H "uart_gpio_end" 08H 02H 52H 00H 82H 0aH 00H 00H 07H
CGLOBAL 01H 03H 0000H "uart_peek" 08H 02H 65H 00H 80H 00H 00H 00H 01H
CGLOBAL 01H 03H 0000H "uart_tx_available" 08H 02H 57H 00H 80H 00H 00H 00H 01H
CGLOBAL 01H 03H 0000H "uart_rx_available" 08H 02H 58H 00H 80H 00H 00H 00H 01H
CGLOBAL 01H 03H 0000H "uart_flush" 08H 02H 63H 00H 80H 00H 00H 00H 07H
CGLOBAL 01H 03H 0000H "uart_begin" 08H 02H 56H 00H 83H 10H 00H 00H 07H
CGLOBAL 01H 03H 0000H "uart_end" 08H 02H 53H 00H 80H 00H 00H 00H 07H
CGLOBAL 01H 03H 0000H "uart_rx_isr" 08H 02H 6BH 00H 80H 00H 00H 00H 07H
CSGLOBAL 03H 0000H "uart_tx_isr" 08H 02H 73H 00H 81H 02H 00H 00H 07H
CGLOBAL 01H 03H 0000H "uart_fifo_out_peek" 08H 02H 6AH 00H 80H 02H 00H 00H 01H
CGLOBAL 01H 03H 0000H "uartf_flush" 08H 02H 64H 00H 80H 00H 00H 00H 07H
CGLOBAL 01H 03H 0000H "uartf_rx_available" 08H 02H 5DH 00H 80H 00H 00H 00H 01H
CGLOBAL 01H 03H 0000H "uartf_tx_available" 08H 02H 5EH 00H 80H 00H 00H 00H 01H
CGLOBAL 01H 03H 0000H "uartf_isr" 08H 02H 6CH 00H 83H 06H 00H 00H 07H
CGLOBAL 01H 03H 0000H "uartf_end" 08H 02H 5CH 00H 80H 00H 00H 00H 07H
CGLOBAL 01H 03H 0000H "uart_fifo_out" 08H 02H 69H 00H 80H 02H 00H 00H 01H
CGLOBAL 01H 03H 0000H "uartf_peek" 08H 02H 66H 00H 80H 00H 00H 00H 01H
CGLOBAL 01H 02H 0000H "uart_tx_write" 08H 02H 5FH 00H 81H 06H 00H 00H 01H
CGLOBAL 01H 02H 0000H "uart_fifo_in" 08H 02H 68H 00H 80H 04H 00H 00H 01H
CSTRUCTTAG 0000H 0000H 0001H 0005H 00000008H "_Notag"
CSTRUCTMEM 42H 00000001H 00000000H "max_length" 02H 00H 00H
CSTRUCTMEM 42H 00000002H 00000002H "buf" 04H 03H 00H 00H 00H
CSTRUCTMEM 42H 00000001H 00000004H "wr_p" 02H 00H 00H
CSTRUCTMEM 42H 00000001H 00000005H "rd_p" 02H 00H 00H
CSTRUCTMEM 42H 00000001H 00000006H "length" 02H 00H 00H
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
CTYPEDEF 0000H 0000H 43H "FIFO_CTRL" 04H 00H 05H 01H 00H
CTYPEDEF 0000H 0000H 43H "CHAR" 02H 00H 00H
CTYPEDEF 0000H 0000H 42H "UINT16" 02H 00H 01H
CTYPEDEF 0000H 0000H 42H "UINT32" 02H 00H 02H
CTYPEDEF 0000H 0000H 42H "boolean" 02H 00H 00H
CTYPEDEF 0000H 0000H 42H "word" 02H 00H 01H
CTYPEDEF 0000H 0000H 42H "BOOL" 02H 00H 00H
CTYPEDEF 0000H 0000H 42H "uint32_t" 02H 00H 02H
CTYPEDEF 0000H 0000H 43H "_BYTE_FIELD" 04H 00H 05H 00H 00H
CTYPEDEF 0000H 0000H 42H "uint16_t" 02H 00H 08H
CGLOBAL 01H 41H 000CH "uart_gpio_adr" 07H 01H 06H 00H 03H 00H 00H 00H
CSGLOBAL 42H 0080H "uart_rx_buf" 05H 01H 80H 00H 00H 00H
CSGLOBAL 42H 0080H "uart_tx_buf" 05H 01H 80H 00H 00H 00H
CGLOBAL 01H 01H 0006H "uart_gpio_tx_bitmask" 05H 01H 06H 00H 00H 00H
CGLOBAL 01H 43H 0001H "uartf_tx_sending" 02H 00H 00H
CSGLOBAL 43H 0008H "uart_rx_fifo" 04H 00H 05H 01H 00H
CSGLOBAL 43H 0008H "uart_tx_fifo" 04H 00H 05H 01H 00H
CSGLOBAL 43H 0001H "uart_tx_flag" 02H 00H 00H
CGLOBAL 01H 01H 0006H "uart_gpio_rx_bitmask" 05H 01H 06H 00H 00H 00H
CSGLOBAL 43H 0001H "uartf_tx_flag" 02H 00H 00H
CSGLOBAL 43H 0008H "uartf_tx_fifo" 04H 00H 05H 01H 00H
CSGLOBAL 43H 0008H "uartf_rx_fifo" 04H 00H 05H 01H 00H
CSGLOBAL 42H 0080H "uartf_rx_buf" 05H 01H 80H 00H 00H 00H
CSGLOBAL 42H 0080H "uartf_tx_buf" 05H 01H 80H 00H 00H 00H
CGLOBAL 01H 43H 0001H "uart_tx_sending" 02H 00H 00H
CFILE 0001H 0000007BH "C:\\LAZURI~1\\hardware\\LAZURI~2\\common.h"
CFILE 0002H 00000F42H "C:\\LazuriteIDE\\bin\\U8Dev\\Inc\\ml620504F.h"
CFILE 0003H 000000C9H "C:\\LazuriteIDE\\bin\\U8Dev\\Inc\\string.h"
CFILE 0004H 0000007AH "C:\\LazuriteIDE\\bin\\U8Dev\\Inc\\yvals.h"
CFILE 0005H 00000045H "C:\\LAZURI~1\\hardware\\LAZURI~2\\ML620Q~1\\common\\rdwr_reg.h"
CFILE 0006H 00000022H "C:\\LAZURI~1\\hardware\\LAZURI~2\\ML620Q~1\\MCU_SM~1\\mcu.h"
CFILE 0007H 0000006FH "C:\\LAZURI~1\\hardware\\lazurite_subghz\\ml620q504\\driver_irq.h"
CFILE 0008H 00000331H "C:\\LAZURI~1\\hardware\\LAZURI~2\\ML620Q~1\\irq\\irq.h"
CFILE 0009H 00000053H "C:\\LAZURI~1\\hardware\\lazurite_subghz\\ml620q504\\driver_uart.h"
CFILE 000AH 00000040H "C:\\LAZURI~1\\hardware\\LAZURI~2\\ML620Q~1\\wdt\\wdt.h"
CFILE 000BH 00000022H "C:\\LAZURI~1\\hardware\\LAZURI~2\\ML620Q~1\\lp\\lp_manage.h"
CFILE 0000H 0000025CH "C:\\LAZURI~1\\hardware\\lazurite_subghz\\ml620q504\\driver_uart.c"

	rseg $$uart_gpio_init$driver_uart
CFUNCTION 81

_uart_gpio_init	:
CBLOCK 81 1 145

;;{
CLINEA 0000H 0001H 0091H 0001H 0001H
;;*****************************************
;;	register/stack information
;;*****************************************
;;*****************************************

	push	xr4
	push	bp
	push	er8
	mov	r8,	r0
CBLOCK 81 2 145
CARGUMENT 46H 0001H 001CH "n" 02H 00H 00H
CLOCAL 46H 0002H 0027H 0002H "port" 04H 03H 00H 00H 00H
CLOCAL 46H 0001H 0018H 0002H "bit" 02H 00H 00H

;;	if(n>5) return;
CLINEA 0000H 0001H 0094H 0002H 0010H
	cmp	r0,	#05h
	ble	_$M1
	b	_$L0
_$M1 :

;;	port = uart_gpio_adr[n];
CLINEA 0000H 0001H 0095H 0002H 0019H
	mov	r12,	r0
	mov	r13,	#00h
	mov	er0,	bp
	add	er0,	bp
	l	er6,	NEAR _uart_gpio_adr[er0]

;;	bit = uart_gpio_rx_bitmask[n];
CLINEA 0000H 0001H 0096H 0002H 001FH
	mov	er2,	bp
	l	r4,	NEAR _uart_gpio_rx_bitmask[er2]

;;	*(port+GPIO_DIR_OFFSET) |= bit;		//DIR = 1
CLINEA 0000H 0001H 0097H 0002H 002BH
	l	r0,	01h[er6]
	or	r0,	r4
	st	r0,	01h[er6]

;;	*(port+GPIO_C0_OFFSET)  &= ~bit;	//C0  = 0
CLINEA 0000H 0001H 0098H 0002H 002BH
	mov	r0,	r4
	xor	r0,	#0ffh
	l	r1,	02h[er6]
	and	r1,	r0
	st	r1,	02h[er6]

;;	*(port+GPIO_C1_OFFSET)  |= bit;		//C1  = 1
CLINEA 0000H 0001H 0099H 0002H 002BH
	l	r0,	03h[er6]
	or	r0,	r4
	st	r0,	03h[er6]

;;	*(port+GPIO_MD0_OFFSET) |= bit;		//MD0 = 1
CLINEA 0000H 0001H 009AH 0002H 002BH
	l	r0,	04h[er6]
	or	r0,	r4
	st	r0,	04h[er6]

;;	*(port+GPIO_MD1_OFFSET) |= bit;		//MD1 = 1
CLINEA 0000H 0001H 009BH 0002H 002BH
	l	r0,	05h[er6]
	or	r0,	r4
	st	r0,	05h[er6]

;;	bit = uart_gpio_tx_bitmask[n];
CLINEA 0000H 0001H 009DH 0002H 001FH
	mov	r0,	r8
	mov	r1,	#00h
	l	r2,	NEAR _uart_gpio_tx_bitmask[er0]

;;	*(port+GPIO_DIR_OFFSET) &= ~bit;	//DIR = 0
CLINEA 0000H 0001H 009EH 0002H 002BH
	mov	r0,	r2
	xor	r0,	#0ffh
	l	r1,	01h[er6]
	and	r1,	r0
	st	r1,	01h[er6]

;;	*(port+GPIO_C0_OFFSET)  |= bit;		//C0  = 1
CLINEA 0000H 0001H 009FH 0002H 002BH
	l	r0,	02h[er6]
	or	r0,	r2
	st	r0,	02h[er6]

;;	*(port+GPIO_C1_OFFSET)  |= bit;		//C1  = 1
CLINEA 0000H 0001H 00A0H 0002H 002BH
	l	r0,	03h[er6]
	or	r0,	r2
	st	r0,	03h[er6]

;;	*(port+GPIO_MD0_OFFSET) |= bit;		//MD0 = 1
CLINEA 0000H 0001H 00A1H 0002H 002BH
	l	r0,	04h[er6]
	or	r0,	r2
	st	r0,	04h[er6]

;;	*(port+GPIO_MD1_OFFSET) |= bit;		//MD1 = 1
CLINEA 0000H 0001H 00A2H 0002H 002BH
	l	r0,	05h[er6]
	or	r0,	r2
	st	r0,	05h[er6]
CBLOCKEND 81 2 164

;;}
CLINEA 0000H 0001H 00A4H 0001H 0001H
_$L0 :
	pop	er8
	pop	bp
	pop	xr4
	rt
CBLOCKEND 81 1 164
CFUNCTIONEND 81


	rseg $$uart_gpio_end$driver_uart
CFUNCTION 82

_uart_gpio_end	:
CBLOCK 82 1 167

;;{
CLINEA 0000H 0001H 00A7H 0001H 0001H
;;*****************************************
;;	register/stack information
;;*****************************************
	_bit$2	set	-1
;;*****************************************

	push	fp
	mov	fp,	sp
	add	sp,	#-02
	push	bp
	push	er8
	push	er4
	mov	r8,	r0
CBLOCK 82 2 167
CARGUMENT 46H 0001H 001CH "n" 02H 00H 00H
CLOCAL 46H 0002H 0026H 0002H "port" 04H 03H 00H 00H 00H
CLOCAL 42H 0001H 0001H 0002H "bit" 02H 00H 00H

;;	if(n>5) return;
CLINEA 0000H 0001H 00AAH 0002H 0010H
	cmp	r0,	#05h
	ble	_$M3
	b	_$L3
_$M3 :

;;	port = uart_gpio_adr[n];
CLINEA 0000H 0001H 00ACH 0002H 0019H
	mov	r12,	r0
	mov	r13,	#00h
	mov	er0,	bp
	add	er0,	bp
	l	er2,	NEAR _uart_gpio_adr[er0]
	mov	er4,	er2	;; _lport$0

;;	bit = uart_gpio_rx_bitmask[n];
CLINEA 0000H 0001H 00ADH 0002H 001FH
	l	r2,	NEAR _uart_gpio_rx_bitmask[bp]
	st	r2,	_bit$2[fp]

;;	*(port+GPIO_DIR_OFFSET)&= ~bit;		//DIR = 0
CLINEA 0000H 0001H 00AEH 0002H 002BH
	l	bp,	NEAR _uart_gpio_adr[er0]
	l	r0,	_bit$2[fp]
	xor	r0,	#0ffh
	l	r1,	1[bp]
	and	r1,	r0
	st	r1,	1[bp]

;;	*(port+GPIO_C0_OFFSET) &= ~bit;		//C0  = 0
CLINEA 0000H 0001H 00AFH 0002H 002BH
	l	r0,	_bit$2[fp]
	xor	r0,	#0ffh
	l	r1,	02h[er4]
	and	r1,	r0
	st	r1,	02h[er4]

;;	*(port+GPIO_C1_OFFSET) &= ~bit;		//C1  = 0
CLINEA 0000H 0001H 00B0H 0002H 002BH
	l	r0,	_bit$2[fp]
	xor	r0,	#0ffh
	l	r1,	03h[er4]
	and	r1,	r0
	st	r1,	03h[er4]

;;	*(port+GPIO_MD0_OFFSET)&= ~bit;		//MD0 = 0
CLINEA 0000H 0001H 00B1H 0002H 002BH
	l	r0,	_bit$2[fp]
	xor	r0,	#0ffh
	l	r1,	04h[er4]
	and	r1,	r0
	st	r1,	04h[er4]

;;	*(port+GPIO_MD1_OFFSET)&= ~bit;		//MD1 = 0
CLINEA 0000H 0001H 00B2H 0002H 002BH
	l	r0,	_bit$2[fp]
	xor	r0,	#0ffh
	l	r1,	05h[er4]
	and	r1,	r0
	st	r1,	05h[er4]

;;	 bit = uart_gpio_tx_bitmask[n];
CLINEA 0000H 0001H 00B4H 0003H 0020H
	mov	r0,	r8
	mov	r1,	#00h
	l	r0,	NEAR _uart_gpio_tx_bitmask[er0]
	st	r0,	_bit$2[fp]

;;	*(port+GPIO_DIR_OFFSET)&= ~bit;		//DIR = 0
CLINEA 0000H 0001H 00B5H 0002H 002BH
	l	r0,	_bit$2[fp]
	xor	r0,	#0ffh
	l	r1,	01h[er4]
	and	r1,	r0
	st	r1,	01h[er4]

;;	*(port+GPIO_C0_OFFSET) &= ~bit;		//C0  = 0
CLINEA 0000H 0001H 00B6H 0002H 002BH
	l	r0,	_bit$2[fp]
	xor	r0,	#0ffh
	l	r1,	02h[er4]
	and	r1,	r0
	st	r1,	02h[er4]

;;	*(port+GPIO_C1_OFFSET) &= ~bit;		//C1  = 0
CLINEA 0000H 0001H 00B7H 0002H 002BH
	l	r0,	_bit$2[fp]
	xor	r0,	#0ffh
	l	r1,	03h[er4]
	and	r1,	r0
	st	r1,	03h[er4]

;;	*(port+GPIO_MD0_OFFSET)&= ~bit;		//MD0 = 0
CLINEA 0000H 0001H 00B8H 0002H 002BH
	l	r0,	_bit$2[fp]
	xor	r0,	#0ffh
	l	r1,	04h[er4]
	and	r1,	r0
	st	r1,	04h[er4]

;;	*(port+GPIO_MD1_OFFSET)&= ~bit;		//MD1 = 0
CLINEA 0000H 0001H 00B9H 0002H 002BH
	l	r0,	_bit$2[fp]
	xor	r0,	#0ffh
	l	r1,	05h[er4]
	and	r1,	r0
	st	r1,	05h[er4]
CBLOCKEND 82 2 187

;;}
CLINEA 0000H 0001H 00BBH 0001H 0001H
_$L3 :
	pop	er4
	pop	er8
	pop	bp
	mov	sp,	fp
	pop	fp
	rt
CBLOCKEND 82 1 187
CFUNCTIONEND 82


	rseg $$uart_begin$driver_uart
CFUNCTION 86

_uart_begin	:
CBLOCK 86 1 193

;;{
CLINEA 0000H 0001H 00C1H 0001H 0001H
;;*****************************************
;;	register/stack information
;;*****************************************
	_rxcallback$4	set	4
	_txcallback$6	set	6
;;*****************************************

	push	lr
	push	fp
	mov	fp,	sp
	push	xr8
	mov	er8,	er0
	mov	er10,	er2
CBLOCK 86 2 193
CRET 0006H
CARGUMENT 46H 0004H 2928H "baud" 02H 00H 02H
CARGUMENT 43H 0002H 0004H "rxcallback" 0AH 03H 00H 02H 78H 00H 00H 00H 00H 00H 07H
CARGUMENT 43H 0002H 0006H "txcallback" 0AH 03H 00H 02H 79H 00H 00H 00H 00H 00H 07H

;;	clear_bit(DUA0);					// enable UART0
CLINEA 0000H 0001H 00C3H 0002H 0025H
	rb	0f06ah.2

;;	clear_bit(DUA1);					// enable UART0
CLINEA 0000H 0001H 00C4H 0002H 0025H
	rb	0f06ah.3

;;	baud = 16000000/baud-1;					// calculate baud rate
CLINEA 0000H 0001H 00C7H 0002H 0033H
	mov	r0,	#00h
	mov	r1,	#024h
	mov	r2,	#0f4h
	mov	r3,	#00h
	push	xr0
	push	xr8
	bl	__uldivu8sw
	add	sp,	#4 
	pop	xr0
	add	er0,	#-1

;;	write_reg16(UA0BRT, (UINT16)baud);		// set baud rate
CLINEA 0000H 0001H 00C8H 0002H 0035H
	st	er0,	0f714h

;;	write_reg8(UA0MOD1, 0x08);				// parity bit = non, stop bit = 1, flow = non
CLINEA 0000H 0001H 00C9H 0002H 004CH
	mov	r0,	#08h
	st	r0,	0f713h

;;	write_reg8(UA0MOD0, 0x04);				// base clock = OSCLK(16MHz)
CLINEA 0000H 0001H 00CAH 0002H 003BH
	mov	r0,	#04h
	st	r0,	0f712h

;;	clear_bit(QUA0);						// clear irq
CLINEA 0000H 0001H 00D3H 0002H 0023H
	rb	0f01ah.4

;;	clear_bit(QUA1);						// clear irq
CLINEA 0000H 0001H 00D4H 0002H 0023H
	rb	0f01ah.5

;;	set_bit(EUA0);						// disenable interrupt of UART RX 
CLINEA 0000H 0001H 00D5H 0002H 0037H
	sb	0f012h.4

;;	set_bit(EUA1);						// disenable interrupt of UART TX
CLINEA 0000H 0001H 00D6H 0002H 0036H
	sb	0f012h.5

;;	if(rxcallback) {
CLINEA 0000H 0001H 00D7H 0002H 0011H
	l	er0,	_rxcallback$4[fp]
	beq	_$L7
CBLOCK 86 3 215

;;		irq_sethandler(IRQ_NO_UA0INT, rxcallback);		// set interrupt handler of rx
CLINEA 0000H 0001H 00D8H 0003H 004CH
	mov	er2,	er0
	mov	r0,	#0dh
	bl	_irq_sethandler
CBLOCKEND 86 3 217

;;	} else {
CLINEA 0000H 0000H 00D9H 0002H 0009H
	bal	_$L9
_$L7 :
CBLOCK 86 4 217

;;		irq_sethandler(IRQ_NO_UA0INT, uart_rx_isr);		// set interrupt handler of rx
CLINEA 0000H 0001H 00DAH 0003H 004DH
	mov	r2,	#BYTE1 OFFSET _uart_rx_isr
	mov	r3,	#BYTE2 OFFSET _uart_rx_isr
	mov	r0,	#0dh
	bl	_irq_sethandler

;;		uart_fifo_init(&uart_rx_fifo);
CLINEA 0000H 0001H 00DBH 0003H 0020H
	mov	r0,	#BYTE1 OFFSET _uart_rx_fifo
	mov	r1,	#BYTE2 OFFSET _uart_rx_fifo
	bl	_uart_fifo_init
CBLOCKEND 86 4 220

;;	}
CLINEA 0000H 0000H 00DCH 0002H 0002H
_$L9 :

;;	if(txcallback) {
CLINEA 0000H 0001H 00DDH 0002H 0011H
	l	er0,	_txcallback$6[fp]
	beq	_$L10
CBLOCK 86 5 221

;;		irq_sethandler(IRQ_NO_UA1INT, txcallback);		// set interrupt handler of tx
CLINEA 0000H 0001H 00DEH 0003H 004CH
	mov	er2,	er0
	mov	r0,	#0eh
	bl	_irq_sethandler
CBLOCKEND 86 5 223

;;	} else {
CLINEA 0000H 0000H 00DFH 0002H 0009H
	bal	_$L12
_$L10 :
CBLOCK 86 6 223

;;		irq_sethandler(IRQ_NO_UA1INT, uart_tx_isr);		// set interrupt handler of tx
CLINEA 0000H 0001H 00E0H 0003H 004DH
	mov	r2,	#BYTE1 OFFSET _uart_tx_isr
	mov	r3,	#BYTE2 OFFSET _uart_tx_isr
	mov	r0,	#0eh
	bl	_irq_sethandler

;;		uart_fifo_init(&uart_tx_fifo);
CLINEA 0000H 0001H 00E1H 0003H 0020H
	mov	r0,	#BYTE1 OFFSET _uart_tx_fifo
	mov	r1,	#BYTE2 OFFSET _uart_tx_fifo
	bl	_uart_fifo_init

;;		uart_tx_flag = false;
CLINEA 0000H 0001H 00E2H 0003H 0017H
	mov	r0,	#00h
	st	r0,	NEAR _uart_tx_flag

;;		uart_tx_sending = false;
CLINEA 0000H 0001H 00E3H 0003H 001AH
	st	r0,	NEAR _uart_tx_sending
CBLOCKEND 86 6 228

;;	}
CLINEA 0000H 0000H 00E4H 0002H 0002H
_$L12 :

;;	set_bit(U0EN);	// UART Enable
CLINEA 0000H 0001H 00E9H 0002H 001EH
	sb	0f711h.0
CBLOCKEND 86 2 236

;;}
CLINEA 0000H 0000H 00ECH 0001H 0001H
	pop	xr8
	mov	sp,	fp
	pop	fp
	pop	pc
CBLOCKEND 86 1 236
CFUNCTIONEND 86


	rseg $$uartf_begin$driver_uart
CFUNCTION 91

_uartf_begin	:
CBLOCK 91 1 239

;;{
CLINEA 0000H 0001H 00EFH 0001H 0001H
;;*****************************************
;;	register/stack information
;;*****************************************
	_dummy$0	set	-2
;;*****************************************

	push	lr
	push	fp
	mov	fp,	sp
	add	sp,	#-02
	push	xr4
	push	er8
CBLOCK 91 2 239
CRET 000AH
CARGUMENT 46H 0004H 2524H "baud" 02H 00H 02H
CLOCAL 42H 0002H 0002H 0002H "dummy" 02H 00H 08H

;;	clear_bit(DUAF0);	// UART Enable
CLINEA 0000H 0001H 00F1H 0002H 0021H
	rb	0f06ah.4

;;	baud = 16000000*12/(baud*13*16);
CLINEA 0000H 0001H 00F3H 0002H 0021H
	push	xr0
	mov	r0,	#0d0h
	mov	r1,	#00h
	mov	er2,	#0 
	push	xr0
	bl	__lmulu8sw
	add	sp,	#4 
	pop	xr0
	mov	r4,	#00h
	mov	r5,	#0b0h
	mov	r6,	#071h
	mov	r7,	#0bh
	push	qr0
	bl	__uldivu8sw
	add	sp,	#4 
	pop	xr0
	mov	er8,	er0

;;	write_reg16(UAF0MOD,0x63);
CLINEA 0000H 0001H 00F5H 0002H 001BH
	mov	r0,	#063h
	mov	r1,	#00h
	st	er0,	0f7c6h

;;	write_reg16(UAF0MOD,0x03);
CLINEA 0000H 0001H 00F6H 0002H 001BH
	mov	er0,	#3 
	st	er0,	0f7c6h

;;	write_reg8(UAF0CAJ,0x0D);
CLINEA 0000H 0001H 00F8H 0002H 001AH
	mov	er0,	#13
	st	er0,	0f7cah

;;	set_bit(UF0DLAB);
CLINEA 0000H 0001H 00FAH 0002H 0012H
	sb	0f7c6h.7

;;	write_reg16(UAF0BUF, (UINT16)baud);
CLINEA 0000H 0001H 00FBH 0002H 0024H
	st	er8,	0f7c0h

;;	clear_bit(UF0DLAB);
CLINEA 0000H 0001H 00FCH 0002H 0014H
	rb	0f7c6h.7

;;	write_reg8(UAF0IER,0x07);						// all interrupts are enabled.
CLINEA 0000H 0001H 00FEH 0002H 003EH
	mov	er0,	#7 
	st	er0,	0f7c2h

;;	clear_bit(QUAF0);								// clear irq
CLINEA 0000H 0001H 0100H 0002H 0026H
	rb	0f01ah.6

;;	set_bit(EUAF0);									// enable interrupt of UART TX
CLINEA 0000H 0001H 0101H 0002H 0037H
	sb	0f012h.6

;;	irq_sethandler(IRQ_NO_UAF0INT, uartf_isr);		// set interrupt handler of rx
CLINEA 0000H 0001H 0102H 0002H 004BH
	mov	r2,	#BYTE1 OFFSET _uartf_isr
	mov	r3,	#BYTE2 OFFSET _uartf_isr
	mov	r0,	#0fh
	bl	_irq_sethandler

;;	uart_fifo_init(&uartf_tx_fifo);
CLINEA 0000H 0001H 0105H 0002H 0020H
	mov	r0,	#BYTE1 OFFSET _uartf_tx_fifo
	mov	r1,	#BYTE2 OFFSET _uartf_tx_fifo
	bl	_uart_fifo_init

;;	uart_fifo_init(&uartf_rx_fifo);
CLINEA 0000H 0001H 0106H 0002H 0020H
	mov	r0,	#BYTE1 OFFSET _uartf_rx_fifo
	mov	r1,	#BYTE2 OFFSET _uartf_rx_fifo
	bl	_uart_fifo_init

;;	uartf_tx_flag = false;
CLINEA 0000H 0001H 0108H 0002H 0017H
	mov	r0,	#00h
	st	r0,	NEAR _uartf_tx_flag

;;	set_bit(UF0RFR);
CLINEA 0000H 0001H 0109H 0002H 0011H
	sb	0f7c7h.1

;;	set_bit(UF0TFR);
CLINEA 0000H 0001H 010AH 0002H 0011H
	sb	0f7c7h.2

;;	dummy = read_reg16(UAF0BUF);
CLINEA 0000H 0001H 010BH 0002H 001DH
	l	er0,	0f7c0h
	st	er0,	_dummy$0[fp]

;;	dummy = read_reg16(UAF0IIR);
CLINEA 0000H 0001H 010CH 0002H 001DH
	l	er0,	0f7c4h
	st	er0,	_dummy$0[fp]
CBLOCK 91 3 271
CLOCAL 46H 0002H 0025H 0003H "dummy" 02H 00H 08H

;;		while(UAF0IIR==6) {
CLINEA 0000H 0001H 0112H 0003H 0015H
	bal	_$L14
_$L16 :
CBLOCK 91 4 274

;;			if(dummy==0x06)
CLINEA 0000H 0001H 0116H 0004H 0012H
	cmp	r2,	#06h
	cmpc	r3,	#00h
	bne	_$L18
CBLOCK 91 5 279

;;				dummy=UAF0BUF;
CLINEA 0000H 0001H 0118H 0005H 0012H
	l	er0,	0f7c0h
	mov	er2,	er0	;; _ldummy$2

;;				dummy=UAF0LSR;
CLINEA 0000H 0001H 0119H 0005H 0012H
	l	er0,	0f7c8h
	mov	er2,	er0	;; _ldummy$2

;;				dummy = UAF0IIR;
CLINEA 0000H 0001H 011CH 0005H 0014H
	l	er0,	0f7c4h
	mov	er2,	er0	;; _ldummy$2
CBLOCKEND 91 5 287

;;			}
CLINEA 0000H 0000H 011FH 0004H 0004H
_$L18 :

;;			dummy=UAF0IIR;
CLINEA 0000H 0001H 0120H 0004H 0011H
	l	er0,	0f7c4h
CBLOCKEND 91 4 289

;;		}
CLINEA 0000H 0000H 0121H 0003H 0003H
_$L14 :
	mov	er2,	er0	;; _ldummy$2

;;		while(UAF0IIR==6) {
CLINEA 0000H 0000H 0112H 0000H 0000H
	l	er0,	0f7c4h
	cmp	r0,	#06h
	cmpc	r1,	#00h
	beq	_$L16
CBLOCKEND 91 3 290
CBLOCKEND 91 2 292

;;}
CLINEA 0000H 0000H 0124H 0001H 0001H
	pop	er8
	pop	xr4
	mov	sp,	fp
	pop	fp
	pop	pc
CBLOCKEND 91 1 292
CFUNCTIONEND 91


	rseg $$uart_end$driver_uart
CFUNCTION 83

_uart_end	:
CBLOCK 83 1 296

;;{
CLINEA 0000H 0001H 0128H 0001H 0001H
;;*****************************************
;;	register/stack information
;;*****************************************
;;*****************************************

CBLOCK 83 2 296

;;	clear_bit(EUA0);						// disenable interrupt of UART RX 
CLINEA 0000H 0001H 012AH 0002H 0039H
	rb	0f012h.4

;;	clear_bit(EUA1);						// disenable interrupt of UART TX
CLINEA 0000H 0001H 012BH 0002H 0038H
	rb	0f012h.5

;;	clear_bit(QUA0);						// clear irq
CLINEA 0000H 0001H 012CH 0002H 0023H
	rb	0f01ah.4

;;	clear_bit(QUA1);						// clear irq
CLINEA 0000H 0001H 012DH 0002H 0023H
	rb	0f01ah.5

;;	clear_bit(U0EN);						// rx disenable
CLINEA 0000H 0001H 012EH 0002H 0026H
	rb	0f711h.0

;;	set_bit(DUA0);							// disenable UART0
CLINEA 0000H 0001H 0130H 0002H 0028H
	sb	0f06ah.2

;;	set_bit(DUA1);							// disenable UART0
CLINEA 0000H 0001H 0131H 0002H 0028H
	sb	0f06ah.3
CBLOCKEND 83 2 307

;;}
CLINEA 0000H 0000H 0133H 0001H 0001H
	rt
CBLOCKEND 83 1 307
CFUNCTIONEND 83


	rseg $$uartf_end$driver_uart
CFUNCTION 92

_uartf_end	:
CBLOCK 92 1 310

;;{
CLINEA 0000H 0001H 0136H 0001H 0001H
;;*****************************************
;;	register/stack information
;;*****************************************
;;*****************************************

CBLOCK 92 2 310

;;	clear_bit(EUAF0);						// disenable interrupt of UART RX 
CLINEA 0000H 0001H 0138H 0002H 003AH
	rb	0f012h.6

;;	clear_bit(QUAF0);						// clear irq
CLINEA 0000H 0001H 0139H 0002H 0024H
	rb	0f01ah.6

;;	set_bit(DUAF0);							// enable UART0
CLINEA 0000H 0001H 013AH 0002H 0026H
	sb	0f06ah.4
CBLOCKEND 92 2 316

;;}
CLINEA 0000H 0000H 013CH 0001H 0001H
	rt
CBLOCKEND 92 1 316
CFUNCTIONEND 92


	rseg $$uart_rx_available$driver_uart
CFUNCTION 88

_uart_rx_available	:
CBLOCK 88 1 320

;;{
CLINEA 0000H 0001H 0140H 0001H 0001H
;;*****************************************
;;	register/stack information
;;*****************************************
;;*****************************************

CBLOCK 88 2 320

;;	return uart_rx_fifo.length;
CLINEA 0000H 0001H 0141H 0002H 001CH
	l	r0,	NEAR _uart_rx_fifo+06h
	mov	r1,	#00h
CBLOCKEND 88 2 322

;;}
CLINEA 0000H 0000H 0142H 0001H 0001H
	rt
CBLOCKEND 88 1 322
CFUNCTIONEND 88


	rseg $$uartf_rx_available$driver_uart
CFUNCTION 93

_uartf_rx_available	:
CBLOCK 93 1 325

;;{
CLINEA 0000H 0001H 0145H 0001H 0001H
;;*****************************************
;;	register/stack information
;;*****************************************
;;*****************************************

CBLOCK 93 2 325

;;	return uartf_rx_fifo.length;
CLINEA 0000H 0001H 0146H 0002H 001DH
	l	r0,	NEAR _uartf_rx_fifo+06h
	mov	r1,	#00h
CBLOCKEND 93 2 327

;;}
CLINEA 0000H 0000H 0147H 0001H 0001H
	rt
CBLOCKEND 93 1 327
CFUNCTIONEND 93


	rseg $$uart_tx_available$driver_uart
CFUNCTION 87

_uart_tx_available	:
CBLOCK 87 1 331

;;{
CLINEA 0000H 0001H 014BH 0001H 0001H
;;*****************************************
;;	register/stack information
;;*****************************************
;;*****************************************

CBLOCK 87 2 331

;;	return (uart_tx_fifo.max_length-uart_tx_fifo.length);
CLINEA 0000H 0001H 014CH 0002H 0036H
	l	r2,	NEAR _uart_tx_fifo+06h
	mov	r3,	#00h
	l	r0,	NEAR _uart_tx_fifo
	mov	r1,	#00h
	sub	r0,	r2
	subc	r1,	r3
CBLOCKEND 87 2 333

;;}
CLINEA 0000H 0000H 014DH 0001H 0001H
	rt
CBLOCKEND 87 1 333
CFUNCTIONEND 87


	rseg $$uartf_tx_available$driver_uart
CFUNCTION 94

_uartf_tx_available	:
CBLOCK 94 1 336

;;{
CLINEA 0000H 0001H 0150H 0001H 0001H
;;*****************************************
;;	register/stack information
;;*****************************************
;;*****************************************

CBLOCK 94 2 336

;;	return (uartf_tx_fifo.max_length-uartf_tx_fifo.length);
CLINEA 0000H 0001H 0151H 0002H 0038H
	l	r2,	NEAR _uartf_tx_fifo+06h
	mov	r3,	#00h
	l	r0,	NEAR _uartf_tx_fifo
	mov	r1,	#00h
	sub	r0,	r2
	subc	r1,	r3
CBLOCKEND 94 2 338

;;}
CLINEA 0000H 0000H 0152H 0001H 0001H
	rt
CBLOCKEND 94 1 338
CFUNCTIONEND 94


	rseg $$uart_tx_write$driver_uart
CFUNCTION 95

_uart_tx_write	:
CBLOCK 95 1 344

;;{
CLINEA 0000H 0001H 0158H 0001H 0001H
;;*****************************************
;;	register/stack information
;;*****************************************
;;*****************************************

	push	lr
	push	er8
	push	er4
	mov	r8,	r0
CBLOCK 95 2 344
CRET 0004H
CARGUMENT 47H 0001H 001CH "data" 02H 00H 00H
CLOCAL 46H 0002H 0026H 0002H "res" 02H 00H 01H

;;	dis_interrupts(DI_UART);
CLINEA 0000H 0001H 015CH 0002H 0019H
	mov	er0,	#2 
	bl	_dis_interrupts

;;	res = uart_fifo_in(&uart_tx_fifo,data);
CLINEA 0000H 0000H 015DH 0002H 0028H
	mov	r2,	r8
	mov	r0,	#BYTE1 OFFSET _uart_tx_fifo
	mov	r1,	#BYTE2 OFFSET _uart_tx_fifo
	bl	_uart_fifo_in
	mov	er4,	er0	;; _lres$0

;;	if(res == 1)
CLINEA 0000H 0001H 015FH 0002H 000DH
	cmp	r0,	#01h
	cmpc	r1,	#00h
	bne	_$L29
CBLOCK 95 3 352

;;		if(uart_tx_flag == false)
CLINEA 0000H 0001H 0161H 0003H 001BH
	l	r0,	NEAR _uart_tx_flag
	bne	_$L29
CBLOCK 95 4 354

;;			data = (char)uart_fifo_out(&uart_tx_fifo);
CLINEA 0000H 0000H 0163H 0004H 002DH
	mov	r0,	#BYTE1 OFFSET _uart_tx_fifo
	mov	r1,	#BYTE2 OFFSET _uart_tx_fifo
	bl	_uart_fifo_out

;;			write_reg8(UA1BUF,data);
CLINEA 0000H 0001H 0164H 0004H 001BH
	st	r0,	0f718h

;;			uart_tx_flag = true;
CLINEA 0000H 0001H 0165H 0004H 0017H
	mov	r0,	#01h
	st	r0,	NEAR _uart_tx_flag

;;			uart_tx_sending = true;
CLINEA 0000H 0001H 0166H 0004H 001AH
	st	r0,	NEAR _uart_tx_sending
CBLOCKEND 95 4 359

;;		}
CLINEA 0000H 0000H 0167H 0003H 0003H
_$L29 :
CBLOCKEND 95 3 360

;;	enb_interrupts(DI_UART);
CLINEA 0000H 0001H 016AH 0002H 0019H
	mov	er0,	#2 
	bl	_enb_interrupts

;;	return res;
CLINEA 0000H 0001H 016BH 0002H 000CH
	mov	er0,	er4
CBLOCKEND 95 2 364

;;}
CLINEA 0000H 0000H 016CH 0001H 0001H
	pop	er4
	pop	er8
	pop	pc
CBLOCKEND 95 1 364
CFUNCTIONEND 95


	rseg $$uartf_tx_write$driver_uart
CFUNCTION 96

_uartf_tx_write	:
CBLOCK 96 1 367

;;{
CLINEA 0000H 0001H 016FH 0001H 0001H
;;*****************************************
;;	register/stack information
;;*****************************************
;;*****************************************

	push	lr
	push	er8
	push	er4
	mov	r8,	r0
CBLOCK 96 2 367
CRET 0004H
CARGUMENT 47H 0001H 001CH "data" 02H 00H 00H
CLOCAL 46H 0002H 0026H 0002H "res" 02H 00H 01H

;;	dis_interrupts(DI_UARTF);
CLINEA 0000H 0001H 0173H 0002H 001AH
	mov	er0,	#4 
	bl	_dis_interrupts

;;	res = uart_fifo_in(&uartf_tx_fifo,data);
CLINEA 0000H 0000H 0174H 0002H 0029H
	mov	r2,	r8
	mov	r0,	#BYTE1 OFFSET _uartf_tx_fifo
	mov	r1,	#BYTE2 OFFSET _uartf_tx_fifo
	bl	_uart_fifo_in
	mov	er4,	er0	;; _lres$0

;;	if(res == 1)
CLINEA 0000H 0001H 0176H 0002H 000DH
	cmp	r0,	#01h
	cmpc	r1,	#00h
	bne	_$L34
CBLOCK 96 3 375

;;		if(uartf_tx_flag == false)
CLINEA 0000H 0001H 0178H 0003H 001CH
	l	r0,	NEAR _uartf_tx_flag
	bne	_$L34
CBLOCK 96 4 377

;;			data = (char)uart_fifo_out(&uartf_tx_fifo);
CLINEA 0000H 0000H 017AH 0004H 002EH
	mov	r0,	#BYTE1 OFFSET _uartf_tx_fifo
	mov	r1,	#BYTE2 OFFSET _uartf_tx_fifo
	bl	_uart_fifo_out

;;			write_reg8(UAF0BUF,data);
CLINEA 0000H 0001H 017BH 0004H 001CH
	mov	r1,	#00h
	st	er0,	0f7c0h

;;			set_bit(UF0IRQ);
CLINEA 0000H 0001H 017CH 0004H 0013H
	sb	0f7cch.0

;;			uartf_tx_flag = true;
CLINEA 0000H 0001H 017DH 0004H 0018H
	mov	r0,	#01h
	st	r0,	NEAR _uartf_tx_flag

;;			uartf_tx_sending = true;
CLINEA 0000H 0001H 017EH 0004H 001BH
	st	r0,	NEAR _uartf_tx_sending
CBLOCKEND 96 4 383

;;		}
CLINEA 0000H 0000H 017FH 0003H 0003H
_$L34 :
CBLOCKEND 96 3 384

;;	enb_interrupts(DI_UARTF);
CLINEA 0000H 0001H 0182H 0002H 001AH
	mov	er0,	#4 
	bl	_enb_interrupts

;;	return res;
CLINEA 0000H 0001H 0183H 0002H 000CH
	mov	er0,	er4
CBLOCKEND 96 2 388

;;}
CLINEA 0000H 0000H 0184H 0001H 0001H
	pop	er4
	pop	er8
	pop	pc
CBLOCKEND 96 1 388
CFUNCTIONEND 96


	rseg $$uart_rx_read$driver_uart
CFUNCTION 97

_uart_rx_read	:
CBLOCK 97 1 394

;;{
CLINEA 0000H 0001H 018AH 0001H 0001H
;;*****************************************
;;	register/stack information
;;*****************************************
;;*****************************************

	push	lr
	push	er4
CBLOCK 97 2 394
CRET 0002H
CLOCAL 47H 0002H 0026H 0002H "res" 02H 00H 01H

;;	dis_interrupts(DI_UART);
CLINEA 0000H 0001H 018DH 0002H 0019H
	mov	er0,	#2 
	bl	_dis_interrupts

;;	res = uart_fifo_out(&uart_rx_fifo);		// get data
CLINEA 0000H 0000H 018EH 0002H 0031H
	mov	r0,	#BYTE1 OFFSET _uart_rx_fifo
	mov	r1,	#BYTE2 OFFSET _uart_rx_fifo
	bl	_uart_fifo_out
	mov	er4,	er0	;; _lres$0

;;	enb_interrupts(DI_UART);
CLINEA 0000H 0001H 0190H 0002H 0019H
	mov	er0,	#2 
	bl	_enb_interrupts

;;	return res;
CLINEA 0000H 0001H 0192H 0002H 000CH
	mov	er0,	er4
CBLOCKEND 97 2 403

;;}
CLINEA 0000H 0000H 0193H 0001H 0001H
	pop	er4
	pop	pc
CBLOCKEND 97 1 403
CFUNCTIONEND 97


	rseg $$uartf_rx_read$driver_uart
CFUNCTION 98

_uartf_rx_read	:
CBLOCK 98 1 406

;;{
CLINEA 0000H 0001H 0196H 0001H 0001H
;;*****************************************
;;	register/stack information
;;*****************************************
;;*****************************************

	push	lr
	push	er4
CBLOCK 98 2 406
CRET 0002H
CLOCAL 47H 0002H 0026H 0002H "res" 02H 00H 01H

;;	dis_interrupts(DI_UARTF);
CLINEA 0000H 0001H 0199H 0002H 001AH
	mov	er0,	#4 
	bl	_dis_interrupts

;;	res = uart_fifo_out(&uartf_rx_fifo);		// get data
CLINEA 0000H 0000H 019AH 0002H 0032H
	mov	r0,	#BYTE1 OFFSET _uartf_rx_fifo
	mov	r1,	#BYTE2 OFFSET _uartf_rx_fifo
	bl	_uart_fifo_out
	mov	er4,	er0	;; _lres$0

;;	enb_interrupts(DI_UARTF);
CLINEA 0000H 0001H 019CH 0002H 001AH
	mov	er0,	#4 
	bl	_enb_interrupts

;;	return res;
CLINEA 0000H 0001H 019DH 0002H 000CH
	mov	er0,	er4
CBLOCKEND 98 2 414

;;}
CLINEA 0000H 0000H 019EH 0001H 0001H
	pop	er4
	pop	pc
CBLOCKEND 98 1 414
CFUNCTIONEND 98


	rseg $$uart_flush$driver_uart
CFUNCTION 99

_uart_flush	:
CBLOCK 99 1 417

;;{
CLINEA 0000H 0001H 01A1H 0001H 0001H
;;*****************************************
;;	register/stack information
;;*****************************************
;;*****************************************

CBLOCK 99 2 417

;;	uart_fifo_init(&uart_rx_fifo);
CLINEA 0000H 0001H 01A2H 0002H 001FH
	mov	r0,	#BYTE1 OFFSET _uart_rx_fifo
	mov	r1,	#BYTE2 OFFSET _uart_rx_fifo
	b	_uart_fifo_init
CBLOCKEND 99 2 420
CLINEA 0000H 0000H 01A4H 0001H 0001H
CBLOCKEND 99 1 420
CFUNCTIONEND 99


	rseg $$uartf_flush$driver_uart
CFUNCTION 100

_uartf_flush	:
CBLOCK 100 1 423

;;{
CLINEA 0000H 0001H 01A7H 0001H 0001H
;;*****************************************
;;	register/stack information
;;*****************************************
;;*****************************************

CBLOCK 100 2 423

;;	uart_fifo_init(&uartf_rx_fifo);
CLINEA 0000H 0001H 01A8H 0002H 0020H
	mov	r0,	#BYTE1 OFFSET _uartf_rx_fifo
	mov	r1,	#BYTE2 OFFSET _uartf_rx_fifo
	b	_uart_fifo_init
CBLOCKEND 100 2 426
CLINEA 0000H 0000H 01AAH 0001H 0001H
CBLOCKEND 100 1 426
CFUNCTIONEND 100


	rseg $$uart_peek$driver_uart
CFUNCTION 101

_uart_peek	:
CBLOCK 101 1 429

;;{
CLINEA 0000H 0001H 01ADH 0001H 0001H
;;*****************************************
;;	register/stack information
;;*****************************************
;;*****************************************

CBLOCK 101 2 429

;;	return uart_fifo_out_peek(&uart_rx_fifo);
CLINEA 0000H 0001H 01AEH 0002H 002AH
	mov	r0,	#BYTE1 OFFSET _uart_rx_fifo
	mov	r1,	#BYTE2 OFFSET _uart_rx_fifo
	b	_uart_fifo_out_peek
CBLOCKEND 101 2 431
CLINEA 0000H 0000H 01AFH 0001H 0001H
CBLOCKEND 101 1 431
CFUNCTIONEND 101


	rseg $$uartf_peek$driver_uart
CFUNCTION 102

_uartf_peek	:
CBLOCK 102 1 434

;;{
CLINEA 0000H 0001H 01B2H 0001H 0001H
;;*****************************************
;;	register/stack information
;;*****************************************
;;*****************************************

CBLOCK 102 2 434

;;	return uart_fifo_out_peek(&uartf_rx_fifo);
CLINEA 0000H 0001H 01B3H 0002H 002BH
	mov	r0,	#BYTE1 OFFSET _uartf_rx_fifo
	mov	r1,	#BYTE2 OFFSET _uartf_rx_fifo
	b	_uart_fifo_out_peek
CBLOCKEND 102 2 436
CLINEA 0000H 0000H 01B4H 0001H 0001H
CBLOCKEND 102 1 436
CFUNCTIONEND 102


	rseg $$uart_tx_isr$driver_uart
CFUNCTION 115

_uart_tx_isr	:
CBLOCK 115 1 440

;;{
CLINEA 0000H 0001H 01B8H 0001H 0001H
;;*****************************************
;;	register/stack information
;;*****************************************
;;*****************************************

	push	lr
CBLOCK 115 2 440
CRET 0000H
CLOCAL 47H 0002H 0024H 0002H "data" 02H 00H 01H

;;	if(uart_tx_flag == false)
CLINEA 0000H 0001H 01BAH 0002H 001AH
	l	r0,	NEAR _uart_tx_flag
	bne	_$L43
CBLOCK 115 3 443

;;		uart_tx_sending = false;
CLINEA 0000H 0001H 01BCH 0003H 001AH
	mov	r0,	#00h
	st	r0,	NEAR _uart_tx_sending
CBLOCKEND 115 3 445

;;	}
CLINEA 0000H 0000H 01BDH 0002H 0002H
_$L43 :

;;	data = uart_fifo_out(&uart_tx_fifo);
CLINEA 0000H 0000H 01BEH 0002H 0025H
	mov	r0,	#BYTE1 OFFSET _uart_tx_fifo
	mov	r1,	#BYTE2 OFFSET _uart_tx_fifo
	bl	_uart_fifo_out

;;	if(data < 0)
CLINEA 0000H 0001H 01BFH 0002H 000DH
	mov	er0,	er0
	bps	_$L45
CBLOCK 115 4 448

;;		uart_tx_flag = false;
CLINEA 0000H 0001H 01C1H 0003H 0017H
	mov	r0,	#00h
	st	r0,	NEAR _uart_tx_flag
CBLOCKEND 115 4 451
CBLOCKEND 115 2 454

;;}
CLINEA 0000H 0001H 01C6H 0001H 0001H
	pop	pc

;;	}
CLINEA 0000H 0000H 01C3H 0002H 0002H
_$L45 :

;;	write_reg8(UA1BUF, (char)data);
CLINEA 0000H 0001H 01C4H 0002H 0020H
	st	r0,	0f718h

;;	return;
CLINEA 0000H 0001H 01C5H 0002H 0008H
	pop	pc
CBLOCKEND 115 1 454
CFUNCTIONEND 115


	rseg $$uart_rx_isr$driver_uart
CFUNCTION 107

_uart_rx_isr	:
CBLOCK 107 1 458

;;{
CLINEA 0000H 0001H 01CAH 0001H 0001H
;;*****************************************
;;	register/stack information
;;*****************************************
;;*****************************************

CBLOCK 107 2 458
CLOCAL 4BH 0001H 0000H 0002H "data" 02H 00H 00H

;;	uart_fifo_in(&uart_rx_fifo, data);
CLINEA 0000H 0001H 01CDH 0002H 0023H
	l	r2,	0f710h
	mov	r0,	#BYTE1 OFFSET _uart_rx_fifo
	mov	r1,	#BYTE2 OFFSET _uart_rx_fifo
	b	_uart_fifo_in
CBLOCKEND 107 2 463
CLINEA 0000H 0000H 01CFH 0001H 0001H
CBLOCKEND 107 1 463
CFUNCTIONEND 107


	rseg $$uartf_isr$driver_uart
CFUNCTION 108

_uartf_isr	:
CBLOCK 108 1 466

;;{
CLINEA 0000H 0001H 01D2H 0001H 0001H
;;*****************************************
;;	register/stack information
;;*****************************************
	_status$2	set	-2
;;*****************************************

	push	lr
	push	fp
	mov	fp,	sp
	add	sp,	#-02
CBLOCK 108 2 466
CRET 0004H
CLOCAL 47H 0002H 0025H 0002H "data" 02H 00H 01H
CLOCAL 42H 0002H 0002H 0002H "status" 02H 00H 08H

;;	status = read_reg16(UAF0IIR);
CLINEA 0000H 0001H 01D5H 0002H 001EH
	l	er0,	0f7c4h
	st	er0,	_status$2[fp]

;;	switch(status&0x000E)
CLINEA 0000H 0001H 01D6H 0002H 0016H
	l	er0,	_status$2[fp]
	and	r0,	#0eh
	and	r1,	#00h
CBLOCK 108 3 471
	cmp	r1,	#00h
	bne	_$L53
	cmp	r0,	#02h
	beq	_$L57

;;	switch(status&0x000E)
CLINEA 0000H 0000H 01D6H 0002H 0016H
	cmp	r0,	#04h
	beq	_$L55

;;	switch(status&0x000E)
CLINEA 0000H 0000H 01D6H 0002H 0016H
	cmp	r0,	#06h
	beq	_$L54

;;	switch(status&0x000E)
CLINEA 0000H 0000H 01D6H 0002H 0016H
	cmp	r0,	#0ch
	beq	_$L55

;;	default:
CLINEA 0000H 0001H 01EFH 0002H 0009H
_$L53 :
CBLOCKEND 108 3 498

;;	}
CLINEA 0000H 0000H 01F2H 0002H 0002H
_$L52 :

;;	set_bit(UF0IRQ);
CLINEA 0000H 0001H 021AH 0002H 0011H
	sb	0f7cch.0
CBLOCKEND 108 2 540

;;}
CLINEA 0000H 0000H 021CH 0001H 0001H
	mov	sp,	fp
	pop	fp
	pop	pc

;;	case (3<<1):							// ERROR
CLINEA 0000H 0001H 01D8H 0002H 001CH
_$L54 :

;;		status = read_reg16(UAF0LSR);
CLINEA 0000H 0001H 01D9H 0003H 001FH
	l	er0,	0f7c8h
	st	er0,	_status$2[fp]

;;		break;
CLINEA 0000H 0001H 01DAH 0003H 0008H
	bal	_$L52

;;	case (2<<1):							// READ
CLINEA 0000H 0001H 01DBH 0002H 001BH
_$L55 :

;;		data = read_reg8(UAF0BUF);
CLINEA 0000H 0001H 01DDH 0003H 001CH
	l	er0,	0f7c0h
	and	r1,	#00h
	mov	er2,	er0	;; _ldata$0

;;		uart_fifo_in(&uartf_rx_fifo, (unsigned char)data);
CLINEA 0000H 0001H 01DEH 0003H 0034H
	mov	r0,	#BYTE1 OFFSET _uartf_rx_fifo
	mov	r1,	#BYTE2 OFFSET _uartf_rx_fifo
	bl	_uart_fifo_in

;;		break;
CLINEA 0000H 0001H 01DFH 0003H 0008H
	bal	_$L52

;;	case (1<<1):							// SEND
CLINEA 0000H 0001H 01E0H 0002H 001BH
_$L57 :

;;		data = uart_fifo_out(&uartf_tx_fifo);
CLINEA 0000H 0000H 01E1H 0003H 0027H
	mov	r0,	#BYTE1 OFFSET _uartf_tx_fifo
	mov	r1,	#BYTE2 OFFSET _uartf_tx_fifo
	bl	_uart_fifo_out
	mov	er2,	er0	;; _ldata$0

;;		if(uartf_tx_flag == false)
CLINEA 0000H 0001H 01E2H 0003H 001CH
	l	r0,	NEAR _uartf_tx_flag
	bne	_$L58
CBLOCK 108 4 483

;;			uart_tx_sending = false;
CLINEA 0000H 0001H 01E4H 0004H 001BH
	mov	r0,	#00h
	st	r0,	NEAR _uart_tx_sending
CBLOCKEND 108 4 485

;;		}
CLINEA 0000H 0000H 01E5H 0003H 0003H
_$L58 :

;;		if(data < 0)
CLINEA 0000H 0001H 01E6H 0003H 000EH
	mov	er0,	er2
	bps	_$L60
CBLOCK 108 5 487

;;			uartf_tx_flag = false;
CLINEA 0000H 0001H 01E8H 0004H 0019H
	mov	r0,	#00h
	st	r0,	NEAR _uartf_tx_flag
CBLOCKEND 108 5 489

;;		else
CLINEA 0000H 0001H 01EAH 0003H 0006H
	bal	_$L62
_$L60 :
CBLOCK 108 6 491

;;			write_reg8(UAF0BUF, (char)data);
CLINEA 0000H 0001H 01ECH 0004H 0023H
	mov	r0,	r2
	mov	r1,	#00h
	st	er0,	0f7c0h
CBLOCKEND 108 6 493

;;		}
CLINEA 0000H 0000H 01EDH 0003H 0003H
_$L62 :

;;		break;
CLINEA 0000H 0001H 01EEH 0003H 0008H
	bal	_$L53
CBLOCKEND 108 1 540
CFUNCTIONEND 108


	rseg $$uart_fifo_in$driver_uart
CFUNCTION 104

_uart_fifo_in	:
CBLOCK 104 1 547

;;{
CLINEA 0000H 0001H 0223H 0001H 0001H
;;*****************************************
;;	register/stack information
;;*****************************************
;;*****************************************

	push	xr8
	mov	er8,	er0
	mov	r10,	r2
CBLOCK 104 2 547
CARGUMENT 47H 0002H 0028H "fifo_p" 06H 03H 00H 00H 05H 01H 00H
CARGUMENT 46H 0001H 001EH "data" 02H 00H 00H

;;	if ( fifo_p->length >= fifo_p->max_length) return 0;	// fifo is full
CLINEA 0000H 0001H 0224H 0002H 0045H
	l	r0,	06h[er0]
	l	r1,	[er8]
	cmp	r0,	r1
	blt	_$L64
	mov	er0,	#0 
CBLOCKEND 104 2 557

;;}
CLINEA 0000H 0001H 022DH 0001H 0001H
_$L63 :
	pop	xr8
	rt

;;	if ( fifo_p->length >= fifo_p->max_length) return 0;	// fifo is full
CLINEA 0000H 0000H 0224H 0002H 0045H
_$L64 :

;;	fifo_p->buf[fifo_p->wr_p] = data;						// input data to fifo
CLINEA 0000H 0001H 0225H 0002H 003DH
	l	r0,	04h[er8]
	mov	r1,	#00h
	l	er2,	02h[er8]
	add	er0,	er2
	st	r10,	[er0]

;;	fifo_p->length++;										// increment written length
CLINEA 0000H 0000H 0226H 0002H 0037H
	lea	06h[er8]
	inc	[ea]

;;	fifo_p->wr_p++;											// increment written pointer.
CLINEA 0000H 0000H 0227H 0002H 0038H
	lea	04h[er8]
	inc	[ea]
	l	r0,	04h[er8]

;;	if( fifo_p->wr_p >= fifo_p->max_length )				// if writtten pointer reach maximum length, it is reset.
CLINEA 0000H 0001H 0228H 0002H 0066H
	l	r1,	[er8]
	cmp	r0,	r1
	blt	_$L66
CBLOCK 104 3 553

;;		fifo_p->wr_p = 0;
CLINEA 0000H 0001H 022AH 0003H 0013H
	mov	r0,	#00h
	st	r0,	04h[er8]
CBLOCKEND 104 3 555

;;	}
CLINEA 0000H 0000H 022BH 0002H 0002H
_$L66 :

;;	return 1;
CLINEA 0000H 0001H 022CH 0002H 000AH
	mov	er0,	#1 
	bal	_$L63
CBLOCKEND 104 1 557
CFUNCTIONEND 104


	rseg $$uart_fifo_out$driver_uart
CFUNCTION 105

_uart_fifo_out	:
CBLOCK 105 1 561

;;{
CLINEA 0000H 0001H 0231H 0001H 0001H
;;*****************************************
;;	register/stack information
;;*****************************************
;;*****************************************

	push	er8
	mov	er8,	er0
CBLOCK 105 2 561
CARGUMENT 47H 0002H 0028H "fifo_p" 06H 03H 00H 00H 05H 01H 00H
CLOCAL 46H 0001H 0016H 0002H "tmp" 02H 00H 00H

;;	UCHAR tmp = fifo_p->rd_p;				// stack read pointer.
CLINEA 0000H 0001H 0232H 0002H 0034H
	l	r0,	05h[er0]
	mov	r2,	r0	;; _ltmp$0

;;	if ( fifo_p->length == 0) return -1;	// if no data, return -1
CLINEA 0000H 0001H 0233H 0002H 003EH
	l	r0,	06h[er8]
	bne	_$L69
	mov	er0,	#-1
CBLOCKEND 105 2 571

;;}
CLINEA 0000H 0001H 023BH 0001H 0001H
_$L68 :
	pop	er8
	rt

;;	if ( fifo_p->length == 0) return -1;	// if no data, return -1
CLINEA 0000H 0000H 0233H 0002H 003EH
_$L69 :

;;	fifo_p->length--;						// decrement written length
CLINEA 0000H 0000H 0234H 0002H 0033H
	add	r0,	#0ffh
	st	r0,	06h[er8]

;;	fifo_p->rd_p++;							// increment read pointer
CLINEA 0000H 0000H 0235H 0002H 0030H
	lea	05h[er8]
	inc	[ea]
	l	r0,	05h[er8]

;;	if( fifo_p->rd_p >= fifo_p->max_length )	// if read pointer reach to maximum, it is reset.
CLINEA 0000H 0001H 0236H 0002H 005BH
	l	r1,	[er8]
	cmp	r0,	r1
	blt	_$L71
CBLOCK 105 3 567

;;		fifo_p->rd_p = 0;
CLINEA 0000H 0001H 0238H 0003H 0013H
	mov	r0,	#00h
	st	r0,	05h[er8]
CBLOCKEND 105 3 569

;;	}
CLINEA 0000H 0000H 0239H 0002H 0002H
_$L71 :

;;	return fifo_p->buf[tmp];
CLINEA 0000H 0001H 023AH 0002H 0019H
	mov	r0,	r2
	mov	r1,	#00h
	l	er2,	02h[er8]
	add	er0,	er2
	l	r0,	[er0]
	mov	r1,	#00h
	bal	_$L68
CBLOCKEND 105 1 571
CFUNCTIONEND 105


	rseg $$uart_fifo_out_peek$driver_uart
CFUNCTION 106

_uart_fifo_out_peek	:
CBLOCK 106 1 574

;;{
CLINEA 0000H 0001H 023EH 0001H 0001H
;;*****************************************
;;	register/stack information
;;*****************************************
;;*****************************************

	push	er8
	mov	er8,	er0
CBLOCK 106 2 574
CARGUMENT 47H 0002H 0028H "fifo_p" 06H 03H 00H 00H 05H 01H 00H

;;	if ( fifo_p->length == 0) return -1;	// if no data, return -1
CLINEA 0000H 0001H 023FH 0002H 003EH
	l	r0,	06h[er0]
	bne	_$L74
	mov	er0,	#-1
CBLOCKEND 106 2 577

;;}
CLINEA 0000H 0001H 0241H 0001H 0001H
_$L73 :
	pop	er8
	rt

;;	if ( fifo_p->length == 0) return -1;	// if no data, return -1
CLINEA 0000H 0000H 023FH 0002H 003EH
_$L74 :

;;	return fifo_p->buf[fifo_p->rd_p];
CLINEA 0000H 0001H 0240H 0002H 0022H
	l	r0,	05h[er8]
	mov	r1,	#00h
	l	er2,	02h[er8]
	add	er0,	er2
	l	r0,	[er0]
	mov	r1,	#00h
	bal	_$L73
CBLOCKEND 106 1 577
CFUNCTIONEND 106


	rseg $$uart_fifo_init$driver_uart
CFUNCTION 103

_uart_fifo_init	:
CBLOCK 103 1 582

;;{
CLINEA 0000H 0001H 0246H 0001H 0001H
;;*****************************************
;;	register/stack information
;;*****************************************
;;*****************************************

	mov	er2,	er0
CBLOCK 103 2 582
CARGUMENT 47H 0002H 0025H "fifo_p" 06H 03H 00H 00H 05H 01H 00H

;;	fifo_p->wr_p = 0;
CLINEA 0000H 0001H 0247H 0002H 0012H
	mov	r0,	#00h
	st	r0,	04h[er2]

;;	fifo_p->rd_p = 0;
CLINEA 0000H 0001H 0248H 0002H 0012H
	st	r0,	05h[er2]

;;	fifo_p->length = 0;
CLINEA 0000H 0001H 0249H 0002H 0014H
	st	r0,	06h[er2]
CBLOCKEND 103 2 587

;;}
CLINEA 0000H 0000H 024BH 0001H 0001H
	rt
CBLOCKEND 103 1 587
CFUNCTIONEND 103


	rseg $$uart_check_irq$driver_uart
CFUNCTION 109

_uart_check_irq	:
CBLOCK 109 1 591

;;void uart_check_irq() {
CLINEA 0000H 0001H 024FH 0001H 0017H
;;*****************************************
;;	register/stack information
;;*****************************************
;;*****************************************

	push	lr
CBLOCK 109 2 591
CRET 0000H

;;	if (irq_uaf0_checkIRQ()) {
CLINEA 0000H 0001H 0250H 0002H 001BH
	tb	0f01ah.6
	beq	_$L78
CBLOCK 109 3 592

;;		irq_uaf0_dis();
CLINEA 0000H 0001H 0251H 0003H 0011H
	rb	0f012h.6

;;		irq_uaf0_clearIRQ();
CLINEA 0000H 0001H 0252H 0003H 0016H
	rb	0f01ah.6

;;		uartf_isr();
CLINEA 0000H 0001H 0253H 0003H 000EH
	bl	_uartf_isr

;;		irq_uaf0_ena();
CLINEA 0000H 0001H 0254H 0003H 0011H
	sb	0f012h.6

;;	} else if (irq_ua0_checkIRQ()) {
CLINEA 0000H 0000H 0255H 0002H 0021H
	bal	_$L81
_$L78 :
	tb	0f01ah.4
	beq	_$L81
CBLOCK 109 4 597

;;		irq_ua0_dis();
CLINEA 0000H 0001H 0256H 0003H 0010H
	rb	0f012h.4

;;		irq_ua0_clearIRQ();
CLINEA 0000H 0001H 0257H 0003H 0015H
	rb	0f01ah.4

;;		uart_rx_isr();
CLINEA 0000H 0001H 0258H 0003H 0010H
	bl	_uart_rx_isr

;;		irq_ua0_ena();
CLINEA 0000H 0001H 0259H 0003H 0010H
	sb	0f012h.4
CBLOCKEND 109 4 602

;;	}
CLINEA 0000H 0000H 025AH 0002H 0002H
_$L81 :
CBLOCKEND 109 3 603
CBLOCKEND 109 2 603

;;}
CLINEA 0000H 0001H 025BH 0001H 0001H
	pop	pc
CBLOCKEND 109 1 603
CFUNCTIONEND 109

	public _uartf_rx_read
	public _uart_gpio_adr
	public _uart_check_irq
	public _uart_fifo_init
	public _uart_gpio_init
	public _uart_rx_read
	public _uartf_begin
	public _uartf_tx_write
	public _uart_gpio_tx_bitmask
	public _uart_gpio_end
	public _uart_peek
	public _uart_tx_available
	public _uart_rx_available
	public _uart_flush
	public _uart_begin
	public _uart_end
	public _uartf_tx_sending
	public _uart_rx_isr
	public _uart_fifo_out_peek
	public _uart_gpio_rx_bitmask
	public _uartf_flush
	public _uartf_rx_available
	public _uartf_tx_available
	public _uart_tx_sending
	public _uartf_isr
	public _uartf_end
	public _uart_fifo_out
	public _uartf_peek
	public _uart_tx_write
	public _uart_fifo_in
	extrn code near : _dis_interrupts
	extrn code near : _enb_interrupts
	extrn code near : _irq_sethandler
	extrn code near : _main

	rseg $$NINITTAB
	db	00h
	db	00h
	db	080h
	align
	dw	_uart_tx_buf
	db	00h
	db	00h
	dw	00h
	db	080h
	align
	dw	_uart_rx_buf
	db	00h
	db	00h
	dw	00h
	db	080h
	align
	dw	_uartf_tx_buf
	db	00h
	db	00h
	dw	00h
	db	080h
	align
	dw	_uartf_rx_buf
	db	00h
	db	00h
	dw	00h
	dw	0f210h
	dw	0f228h
	dw	0f238h
	dw	0f230h
	dw	0f220h
	dw	0f228h

	rseg $$TABuart_gpio_rx_bitmask$driver_uart
_uart_gpio_rx_bitmask :
	db	01h
	db	01h
	db	01h
	db	010h
	db	01h
	db	010h

	rseg $$TABuart_gpio_tx_bitmask$driver_uart
_uart_gpio_tx_bitmask :
	db	02h
	db	02h
	db	02h
	db	020h
	db	02h
	db	020h

	rseg $$NINITVAR
_uart_tx_sending :
	ds	01h
_uartf_tx_sending :
	ds	01h
_uart_tx_fifo :
	ds	08h
_uart_rx_fifo :
	ds	08h
_uartf_tx_fifo :
	ds	08h
_uartf_rx_fifo :
	ds	08h
_uart_gpio_adr :
	ds	0ch

	rseg $$NVARdriver_uart
_uart_rx_buf :
	ds	080h
_uart_tx_buf :
	ds	080h
_uart_tx_flag :
	ds	01h
_uartf_tx_flag :
	ds	01h
_uartf_rx_buf :
	ds	080h
_uartf_tx_buf :
	ds	080h
	extrn code : __lmulu8sw
	extrn code : __uldivu8sw

	end
