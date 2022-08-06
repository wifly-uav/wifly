;; Compile Options : /TML620504F /MS /near /IC:\LAZURI~1\LIBRAR~1\BM1383 /IC:\LAZURI~1\LIBRAR~1\BM1422 /IC:\LAZURI~1\LIBRAR~1\HARDWA~1 /IC:\LAZURI~1\LIBRAR~1\HARDWA~2 /IC:\LAZURI~1\LIBRAR~1\KXG03_~1 /IC:\LAZURI~1\LIBRAR~1\VL53L0X /IC:\LAZURI~1\LIBRAR~1\Wire /IC:\LAZURI~1\hardware\LAZURI~2 /IC:\LAZURI~1\hardware\LAZURI~2\lazurite /IC:\LAZURI~1\hardware\LAZURI~2\ML620Q~1 /IC:\LAZURI~1\hardware\LAZURI~2\ML620Q~1\clock /IC:\LAZURI~1\hardware\LAZURI~2\ML620Q~1\common /IC:\LAZURI~1\hardware\LAZURI~2\ML620Q~1\irq /IC:\LAZURI~1\hardware\LAZURI~2\ML620Q~1\lp /IC:\LAZURI~1\hardware\LAZURI~2\ML620Q~1\MCU_SM~1 /IC:\LAZURI~1\hardware\LAZURI~2\ML620Q~1\wdt /IC:\LAZURI~1\hardware\LAZURI~2\sub_ghz\ /D_ML620Q504 /DLAZURITE_MINI /DLAZURITE_IDE /DSUBGHZ /DPWR_LED /DLDO_CNT /SS 512 /SL 65 /SD /Oa /Ot /W 3 /Faobj\ /Lv 
;; Version Number  : Ver.3.53.1
;; File Name       : aes.c

	type (ML620504F) 
	model small, near
	$$NVARaes segment data 2h #0h
	$$AES128_CBC_decrypt$aes segment code 2h #0h
	$$AES128_CBC_decrypt_buffer$aes segment code 2h #0h
	$$AES128_CBC_encrypt$aes segment code 2h #0h
	$$AES128_CBC_encrypt_buffer$aes segment code 2h #0h
	$$AES128_ECB_decrypt$aes segment code 2h #0h
	$$AES128_ECB_encrypt$aes segment code 2h #0h
	$$AES128_getStatus$aes segment code 2h #0h
	$$AES128_setKey$aes segment code 2h #0h
	$$AddRoundKey$aes segment code 2h #0h
	$$BlockCopy$aes segment code 2h #0h
	$$Cipher$aes segment code 2h #0h
	$$InvCipher$aes segment code 2h #0h
	$$InvMixColumns$aes segment code 2h #0h
	$$InvShiftRows$aes segment code 2h #0h
	$$InvSubBytes$aes segment code 2h #0h
	$$KeyExpansion$aes segment code 2h #0h
	$$MixColumns$aes segment code 2h #0h
	$$ShiftRows$aes segment code 2h #0h
	$$SubBytes$aes segment code 2h #0h
	$$TABRcon$aes segment table 2h #0h
	$$TABrsbox$aes segment table 2h #0h
	$$TABsbox$aes segment table 2h #0h
	$$XorWithIv$aes segment code 2h #0h
	$$getSBoxInvert$aes segment code 2h #0h
	$$getSBoxValue$aes segment code 2h #0h
	$$xtime$aes segment code 2h #0h
CVERSION 3.53.1
CSGLOBAL 03H 0000H "ShiftRows" 08H 02H 4FH 00H 80H 02H 00H 00H 07H
CGLOBAL 01H 03H 0000H "AES128_CBC_decrypt_buffer" 08H 02H 45H 00H 83H 12H 00H 00H 07H
CSGLOBAL 03H 0000H "Cipher" 08H 02H 55H 00H 81H 04H 00H 00H 07H
CGLOBAL 01H 03H 0000H "AES128_CBC_encrypt_buffer" 08H 02H 44H 00H 83H 12H 00H 00H 07H
CGLOBAL 01H 02H 0000H "AES128_CBC_decrypt" 08H 02H 47H 00H 83H 12H 00H 00H 00H
CSGLOBAL 03H 0000H "MixColumns" 08H 02H 51H 00H 81H 08H 00H 00H 07H
CSGLOBAL 03H 0000H "SubBytes" 08H 02H 4EH 00H 81H 08H 00H 00H 07H
CSGLOBAL 03H 0000H "BlockCopy" 08H 02H 57H 00H 80H 06H 00H 00H 07H
CGLOBAL 01H 03H 0000H "AES128_ECB_encrypt" 08H 02H 42H 00H 83H 06H 00H 00H 07H
CSGLOBAL 02H 0000H "getSBoxValue" 08H 02H 4AH 00H 80H 00H 00H 00H 00H
CGLOBAL 01H 02H 0000H "AES128_getStatus" 08H 02H 49H 00H 80H 00H 00H 00H 00H
CSGLOBAL 03H 0000H "XorWithIv" 08H 02H 5AH 00H 80H 06H 00H 00H 07H
CSGLOBAL 03H 0000H "KeyExpansion" 08H 02H 4CH 00H 83H 12H 00H 00H 07H
CSGLOBAL 02H 0000H "getSBoxInvert" 08H 02H 4BH 00H 80H 00H 00H 00H 00H
CSGLOBAL 02H 0000H "xtime" 08H 02H 50H 00H 80H 02H 00H 00H 00H
CGLOBAL 01H 02H 0000H "AES128_CBC_encrypt" 08H 02H 46H 00H 83H 18H 00H 00H 00H
CSGLOBAL 03H 0000H "InvMixColumns" 08H 02H 52H 00H 83H 24H 00H 00H 07H
CSGLOBAL 03H 0000H "InvSubBytes" 08H 02H 53H 00H 81H 08H 00H 00H 07H
CGLOBAL 01H 03H 0000H "AES128_setKey" 08H 02H 48H 00H 80H 00H 00H 00H 07H
CSGLOBAL 03H 0000H "InvCipher" 08H 02H 56H 00H 81H 04H 00H 00H 07H
CGLOBAL 01H 03H 0000H "AES128_ECB_decrypt" 08H 02H 43H 00H 83H 06H 00H 00H 07H
CSGLOBAL 03H 0000H "AddRoundKey" 08H 02H 4DH 00H 80H 08H 00H 00H 07H
CSGLOBAL 03H 0000H "InvShiftRows" 08H 02H 54H 00H 80H 02H 00H 00H 07H
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
CTYPEDEF 0000H 0000H 43H "CHAR" 02H 00H 00H
CTYPEDEF 0000H 0000H 42H "UINT16" 02H 00H 01H
CTYPEDEF 0000H 0000H 42H "UINT32" 02H 00H 02H
CTYPEDEF 0000H 0000H 42H "boolean" 02H 00H 00H
CTYPEDEF 0000H 0000H 42H "state_t" 08H 01H 04H 00H 01H 04H 00H 00H 00H
CTYPEDEF 0000H 0000H 42H "word" 02H 00H 01H
CTYPEDEF 0000H 0000H 42H "BOOL" 02H 00H 00H
CTYPEDEF 0000H 0000H 42H "uint32_t" 02H 00H 02H
CTYPEDEF 0000H 0000H 43H "_BYTE_FIELD" 04H 00H 05H 00H 00H
CTYPEDEF 0000H 0000H 42H "uint16_t" 02H 00H 08H
CSGLOBAL 42H 0002H "state" 0AH 03H 00H 01H 04H 00H 01H 04H 00H 00H 00H
CSGLOBAL 42H 0002H "p_key" 04H 03H 00H 00H 00H
CSGLOBAL 42H 00B0H "RoundKey" 05H 01H 0B0H 00H 00H 00H
CSGLOBAL 42H 0002H "Iv" 04H 03H 00H 00H 00H
CSGLOBAL 42H 0100H "workspace" 05H 01H 00H 01H 00H 00H
CSGLOBAL 42H 0001H "secEn" 02H 00H 00H
CSGLOBAL 00H 00FFH "Rcon" 05H 01H 0FFH 00H 00H 00H
CSGLOBAL 42H 0010H "ivTable" 05H 01H 10H 00H 00H 00H
CSGLOBAL 00H 0100H "sbox" 05H 01H 00H 01H 00H 00H
CSGLOBAL 40H 0002H "Key" 04H 03H 00H 00H 00H
CSGLOBAL 00H 0100H "rsbox" 05H 01H 00H 01H 00H 00H
CFILE 0001H 000000C9H "C:\\LazuriteIDE\\bin\\U8Dev\\Inc\\string.h"
CFILE 0002H 0000007AH "C:\\LazuriteIDE\\bin\\U8Dev\\Inc\\yvals.h"
CFILE 0003H 00000048H "C:\\LAZURI~1\\hardware\\lazurite_subghz\\SUB_GHZ\\aes\\aes.h"
CFILE 0004H 0000007BH "C:\\LAZURI~1\\hardware\\LAZURI~2\\common.h"
CFILE 0005H 00000F42H "C:\\LazuriteIDE\\bin\\U8Dev\\Inc\\ml620504F.h"
CFILE 0000H 000002B2H "C:\\LAZURI~1\\hardware\\lazurite_subghz\\SUB_GHZ\\aes\\aes.c"

	rseg $$getSBoxValue$aes
CFUNCTION 74

_getSBoxValue	:
CBLOCK 74 1 190

;;{
CLINEA 0000H 0001H 00BEH 0001H 0001H
;;*****************************************
;;	register/stack information
;;*****************************************
;;*****************************************

CBLOCK 74 2 190
CARGUMENT 46H 0001H 0014H "num" 02H 00H 00H

;;  return sbox[num];
CLINEA 0000H 0001H 00BFH 0003H 0013H
	mov	r1,	#00h
	l	r0,	NEAR _sbox[er0]
CBLOCKEND 74 2 192

;;}
CLINEA 0000H 0000H 00C0H 0001H 0001H
	rt
CBLOCKEND 74 1 192
CFUNCTIONEND 74


	rseg $$getSBoxInvert$aes
CFUNCTION 75

_getSBoxInvert	:
CBLOCK 75 1 195

;;{
CLINEA 0000H 0001H 00C3H 0001H 0001H
;;*****************************************
;;	register/stack information
;;*****************************************
;;*****************************************

CBLOCK 75 2 195
CARGUMENT 46H 0001H 0014H "num" 02H 00H 00H

;;  return rsbox[num];
CLINEA 0000H 0001H 00C4H 0003H 0014H
	mov	r1,	#00h
	l	r0,	NEAR _rsbox[er0]
CBLOCKEND 75 2 197

;;}
CLINEA 0000H 0000H 00C5H 0001H 0001H
	rt
CBLOCKEND 75 1 197
CFUNCTIONEND 75


	rseg $$KeyExpansion$aes
CFUNCTION 76

_KeyExpansion	:
CBLOCK 76 1 201

;;{
CLINEA 0000H 0001H 00C9H 0001H 0001H
;;*****************************************
;;	register/stack information
;;*****************************************
	_tempa$12	set	-4
;;*****************************************

	push	lr
	push	fp
	mov	fp,	sp
	add	sp,	#-04
	push	xr8
	push	xr4
	push	bp
CBLOCK 76 2 201
CRET 0010H
CLOCAL 46H 0004H 2726H 0002H "i" 02H 00H 02H
CLOCAL 46H 0004H 2928H 0002H "j" 02H 00H 02H
CLOCAL 46H 0004H 2928H 0002H "k" 02H 00H 02H
CLOCAL 42H 0004H 0004H 0002H "tempa" 05H 01H 04H 00H 00H 00H

;;  for(i = 0; i < Nk; ++i)
CLINEA 0000H 0001H 00CEH 0003H 0019H
	mov	er0,	#0 
	mov	er4,	#0 	;; _li$0
	mov	er6,	#0 	;; _li$0
_$L5 :
CBLOCK 76 3 207

;;    RoundKey[(i * 4) + 0] = Key[(i * 4) + 0];
CLINEA 0000H 0001H 00D0H 0005H 002DH
	sllc	r1,	#02h
	sll	r0,	#02h
	l	er2,	NEAR _Key
	add	er0,	er2
	mov	er2,	er4
	sllc	r3,	#02h
	sll	r2,	#02h
	l	r0,	[er0]
	st	r0,	NEAR _RoundKey[er2]

;;    RoundKey[(i * 4) + 1] = Key[(i * 4) + 1];
CLINEA 0000H 0001H 00D1H 0005H 002DH
	mov	er0,	er4
	sllc	r1,	#02h
	sll	r0,	#02h
	l	er2,	NEAR _Key
	add	er0,	er2
	mov	er2,	er4
	sllc	r3,	#02h
	sll	r2,	#02h
	l	r0,	01h[er0]
	st	r0,	NEAR _RoundKey+01h[er2]

;;    RoundKey[(i * 4) + 2] = Key[(i * 4) + 2];
CLINEA 0000H 0001H 00D2H 0005H 002DH
	mov	er0,	er4
	sllc	r1,	#02h
	sll	r0,	#02h
	l	er2,	NEAR _Key
	add	er0,	er2
	mov	er2,	er4
	sllc	r3,	#02h
	sll	r2,	#02h
	l	r0,	02h[er0]
	st	r0,	NEAR _RoundKey+02h[er2]

;;    RoundKey[(i * 4) + 3] = Key[(i * 4) + 3];
CLINEA 0000H 0001H 00D3H 0005H 002DH
	mov	er0,	er4
	sllc	r1,	#02h
	sll	r0,	#02h
	l	er2,	NEAR _Key
	add	er0,	er2
	mov	er2,	er4
	sllc	r3,	#02h
	sll	r2,	#02h
	l	r0,	03h[er0]
	st	r0,	NEAR _RoundKey+03h[er2]
CBLOCKEND 76 3 212

;;  for(i = 0; i < Nk; ++i)
CLINEA 0000H 0000H 00CEH 0003H 0019H
	mov	er0,	er4
	mov	er2,	er6
	add	er0,	#1 
	addc	r2,	#00h
	addc	r3,	#00h
	mov	er4,	er0	;; _li$0
	mov	er6,	er2	;; _li$0

;;  for(i = 0; i < Nk; ++i)
CLINEA 0000H 0000H 00CEH 0009H 001EH
	cmp	r0,	#04h
	cmpc	r1,	#00h
	cmpc	r2,	#00h
	cmpc	r3,	#00h
	blt	_$L5

;;  for(; (i < (Nb * (Nr + 1))); ++i)
CLINEA 0000H 0000H 00D7H 0001H 0001H
	b	_$L31

;;  for(; (i < (Nb * (Nr + 1))); ++i)
CLINEA 0000H 0000H 00D7H 0020H 0022H
_$L11 :
CBLOCK 76 4 216

;;    for(j = 0; j < 4; ++j)
CLINEA 0000H 0001H 00D9H 0009H 000EH
	mov	er8,	#0 	;; _lj$4
	mov	er10,	#0 	;; _lj$4

;;    for(j = 0; j < 4; ++j)
CLINEA 0000H 0000H 00D9H 0017H 0019H
_$L17 :
CBLOCK 76 5 218

;;      tempa[j]=RoundKey[(i-1) * 4 + j];
CLINEA 0000H 0001H 00DBH 0007H 0027H
	mov	er0,	er4
	add	er0,	#-1
	sllc	r1,	#02h
	sll	r0,	#02h
	add	er0,	er8
	mov	bp,	er8
	add	bp,	fp
	l	r0,	NEAR _RoundKey[er0]
	st	r0,	-4[bp]
CBLOCKEND 76 5 220

;;    for(j = 0; j < 4; ++j)
CLINEA 0000H 0000H 00D9H 0017H 0019H
	mov	er0,	er8
	mov	er2,	er10
	add	er0,	#1 
	addc	r2,	#00h
	addc	r3,	#00h
	mov	er8,	er0	;; _lj$4
	mov	er10,	er2	;; _lj$4

;;    for(j = 0; j < 4; ++j)
CLINEA 0000H 0000H 00D9H 0010H 0015H
	cmp	r0,	#04h
	cmpc	r1,	#00h
	cmpc	r2,	#00h
	cmpc	r3,	#00h
	blt	_$L17

;;    if (i % Nk == 0)
CLINEA 0000H 0001H 00DDH 0005H 0014H
	mov	er0,	er4
	mov	er2,	er6
	and	r0,	#03h
	and	r1,	#00h
	and	r2,	#00h
	and	r3,	#00h
	cmp	r0,	#00h
	cmpc	r1,	#00h
	cmpc	r2,	#00h
	cmpc	r3,	#00h
	bne	_$L21
CBLOCK 76 6 222
CBLOCK 76 7 227

;;        k = tempa[0];
CLINEA 0000H 0001H 00E4H 0009H 0015H
	l	r0,	_tempa$12[fp]
	mov	r1,	#00h
	mov	er8,	er0	;; _lk$8

;;        tempa[0] = tempa[1];
CLINEA 0000H 0001H 00E5H 0009H 001CH
	l	r0,	_tempa$12+01h[fp]
	st	r0,	_tempa$12[fp]

;;        tempa[1] = tempa[2];
CLINEA 0000H 0001H 00E6H 0009H 001CH
	l	r0,	_tempa$12+02h[fp]
	st	r0,	_tempa$12+01h[fp]

;;        tempa[2] = tempa[3];
CLINEA 0000H 0001H 00E7H 0009H 001CH
	l	r0,	_tempa$12+03h[fp]
	st	r0,	_tempa$12+02h[fp]

;;        tempa[3] = k;
CLINEA 0000H 0001H 00E8H 0009H 0015H
	st	r8,	_tempa$12+03h[fp]
CBLOCKEND 76 7 233
CBLOCK 76 8 239

;;        tempa[0] = getSBoxValue(tempa[0]);
CLINEA 0000H 0000H 00F0H 0009H 002AH
	l	r0,	_tempa$12[fp]
	bl	_getSBoxValue
	st	r0,	_tempa$12[fp]

;;        tempa[1] = getSBoxValue(tempa[1]);
CLINEA 0000H 0000H 00F1H 0009H 002AH
	l	r0,	_tempa$12+01h[fp]
	bl	_getSBoxValue
	st	r0,	_tempa$12+01h[fp]

;;        tempa[2] = getSBoxValue(tempa[2]);
CLINEA 0000H 0000H 00F2H 0009H 002AH
	l	r0,	_tempa$12+02h[fp]
	bl	_getSBoxValue
	st	r0,	_tempa$12+02h[fp]

;;        tempa[3] = getSBoxValue(tempa[3]);
CLINEA 0000H 0000H 00F3H 0009H 002AH
	l	r0,	_tempa$12+03h[fp]
	bl	_getSBoxValue
	st	r0,	_tempa$12+03h[fp]

;;      tempa[0] =  tempa[0] ^ Rcon[i/Nk];
CLINEA 0000H 0001H 00F6H 0007H 0028H
	mov	er2,	er6
	mov	er0,	er4
	srlc	r0,	#02h
	srlc	r1,	#02h
	l	r2,	_tempa$12[fp]
	l	r0,	NEAR _Rcon[er0]
	xor	r2,	r0
	st	r2,	_tempa$12[fp]

;;    else if (Nk > 6 && i % Nk == 4)
CLINEA 0000H 0000H 00F8H 0005H 0023H
_$L21 :

;;    RoundKey[i * 4 + 0] = RoundKey[(i - Nk) * 4 + 0] ^ tempa[0];
CLINEA 0000H 0001H 0102H 0005H 0040H
	mov	er0,	er4
	add	er0,	#-4
	sllc	r1,	#02h
	sll	r0,	#02h
	l	r2,	NEAR _RoundKey[er0]
	l	r3,	_tempa$12[fp]
	xor	r2,	r3
	mov	bp,	er4
	sllc	r13,	#02h
	sll	r12,	#02h
	st	r2,	NEAR _RoundKey[bp]

;;    RoundKey[i * 4 + 1] = RoundKey[(i - Nk) * 4 + 1] ^ tempa[1];
CLINEA 0000H 0001H 0103H 0005H 0040H
	l	r2,	NEAR _RoundKey+01h[er0]
	l	r3,	_tempa$12+01h[fp]
	xor	r2,	r3
	mov	bp,	er4
	sllc	r13,	#02h
	sll	r12,	#02h
	st	r2,	NEAR _RoundKey+01h[bp]

;;    RoundKey[i * 4 + 2] = RoundKey[(i - Nk) * 4 + 2] ^ tempa[2];
CLINEA 0000H 0001H 0104H 0005H 0040H
	l	r2,	NEAR _RoundKey+02h[er0]
	l	r3,	_tempa$12+02h[fp]
	xor	r2,	r3
	mov	bp,	er4
	sllc	r13,	#02h
	sll	r12,	#02h
	st	r2,	NEAR _RoundKey+02h[bp]

;;    RoundKey[i * 4 + 3] = RoundKey[(i - Nk) * 4 + 3] ^ tempa[3];
CLINEA 0000H 0001H 0105H 0005H 0040H
	l	r0,	NEAR _RoundKey+03h[er0]
	l	r1,	_tempa$12+03h[fp]
	xor	r0,	r1
	mov	er2,	er4
	sllc	r3,	#02h
	sll	r2,	#02h
	st	r0,	NEAR _RoundKey+03h[er2]
CBLOCKEND 76 4 262
CBLOCKEND 76 8 263
CBLOCKEND 76 6 263

;;  for(; (i < (Nb * (Nr + 1))); ++i)
CLINEA 0000H 0000H 00D7H 0020H 0022H
	mov	er0,	er4
	mov	er2,	er6
	add	er0,	#1 
	addc	r2,	#00h
	addc	r3,	#00h
	mov	er4,	er0	;; _li$0
	mov	er6,	er2	;; _li$0

;;  for(; (i < (Nb * (Nr + 1))); ++i)
CLINEA 0000H 0000H 00D7H 0001H 0001H
_$L31 :

;;  for(; (i < (Nb * (Nr + 1))); ++i)
CLINEA 0000H 0000H 00D7H 0010H 0015H
	cmp	r0,	#02ch
	cmpc	r1,	#00h
	cmpc	r2,	#00h
	cmpc	r3,	#00h
	bge	_$M3
	b	_$L11
_$M3 :
CBLOCKEND 76 2 263

;;}
CLINEA 0000H 0001H 0107H 0001H 0001H
	pop	bp
	pop	xr4
	pop	xr8
	mov	sp,	fp
	pop	fp
	pop	pc
CBLOCKEND 76 1 263
CFUNCTIONEND 76


	rseg $$AddRoundKey$aes
CFUNCTION 77

_AddRoundKey	:
CBLOCK 77 1 268

;;{
CLINEA 0000H 0001H 010CH 0001H 0001H
;;*****************************************
;;	register/stack information
;;*****************************************
;;*****************************************

	push	xr8
	push	xr4
	mov	r8,	r0
CBLOCK 77 2 268
CARGUMENT 46H 0001H 001CH "round" 02H 00H 00H
CLOCAL 46H 0001H 001DH 0002H "i" 02H 00H 00H
CLOCAL 46H 0001H 001EH 0002H "j" 02H 00H 00H

;;  for(i=0;i<4;++i)
CLINEA 0000H 0001H 010EH 0003H 0012H
	mov	r9,	#00h	;; _li$0
_$L35 :
CBLOCK 77 3 271

;;    for(j = 0; j < 4; ++j)
CLINEA 0000H 0001H 0110H 0009H 000EH
	mov	r10,	#00h	;; _lj$2

;;    for(j = 0; j < 4; ++j)
CLINEA 0000H 0000H 0110H 0017H 0019H
_$L41 :
CBLOCK 77 4 273

;;      (*state)[i][j] ^= RoundKey[round * Nb * 4 + i * Nb + j];
CLINEA 0000H 0001H 0112H 0007H 003EH
	mov	r0,	r9
	mov	r1,	#00h
	sllc	r1,	#02h
	sll	r0,	#02h
	mov	er2,	er0
	l	er4,	NEAR _state
	add	er2,	er4
	mov	r4,	r10
	mov	r5,	#00h
	add	er2,	er4
	mov	r6,	r8
	mov	r7,	#00h
	sllc	r7,	#04h
	sll	r6,	#04h
	add	er6,	er0
	add	er6,	er4
	l	r0,	[er2]
	l	r1,	NEAR _RoundKey[er6]
	xor	r0,	r1
	st	r0,	[er2]
CBLOCKEND 77 4 275

;;    for(j = 0; j < 4; ++j)
CLINEA 0000H 0000H 0110H 0017H 0019H
	add	r10,	#01h

;;    for(j = 0; j < 4; ++j)
CLINEA 0000H 0000H 0110H 0010H 0015H
	cmp	r10,	#04h
	blt	_$L41
CBLOCKEND 77 3 276

;;  for(i=0;i<4;++i)
CLINEA 0000H 0000H 010EH 0003H 0012H
	add	r9,	#01h

;;  for(i=0;i<4;++i)
CLINEA 0000H 0000H 010EH 0010H 0015H
	cmp	r9,	#04h
	blt	_$L35
CBLOCKEND 77 2 277

;;}
CLINEA 0000H 0001H 0115H 0001H 0001H
	pop	xr4
	pop	xr8
	rt
CBLOCKEND 77 1 277
CFUNCTIONEND 77


	rseg $$SubBytes$aes
CFUNCTION 78

_SubBytes	:
CBLOCK 78 1 282

;;{
CLINEA 0000H 0001H 011AH 0001H 0001H
;;*****************************************
;;	register/stack information
;;*****************************************
;;*****************************************

	push	lr
	push	xr4
	push	er8
CBLOCK 78 2 282
CRET 0006H
CLOCAL 46H 0001H 001AH 0002H "i" 02H 00H 00H
CLOCAL 46H 0001H 001BH 0002H "j" 02H 00H 00H

;;  for(i = 0; i < 4; ++i)
CLINEA 0000H 0001H 011CH 0003H 0018H
	mov	r6,	#00h	;; _li$0
_$L48 :
CBLOCK 78 3 285

;;    for(j = 0; j < 4; ++j)
CLINEA 0000H 0001H 011EH 0009H 000EH
	mov	r7,	#00h	;; _lj$2

;;    for(j = 0; j < 4; ++j)
CLINEA 0000H 0000H 011EH 0017H 0019H
_$L54 :
CBLOCK 78 4 287

;;      (*state)[j][i] = getSBoxValue((*state)[j][i]);
CLINEA 0000H 0000H 0120H 0007H 0034H
	mov	r2,	r6
	mov	r3,	#00h
	mov	r0,	r7
	mov	r1,	#00h
	sllc	r1,	#02h
	sll	r0,	#02h
	l	er4,	NEAR _state
	add	er0,	er4
	add	er0,	er2
	l	r0,	[er0]
	bl	_getSBoxValue
	mov	r8,	r0
	mov	r2,	r6
	mov	r3,	#00h
	mov	r0,	r7
	mov	r1,	#00h
	sllc	r1,	#02h
	sll	r0,	#02h
	l	er4,	NEAR _state
	add	er0,	er4
	add	er0,	er2
	st	r8,	[er0]
CBLOCKEND 78 4 289

;;    for(j = 0; j < 4; ++j)
CLINEA 0000H 0000H 011EH 0017H 0019H
	add	r7,	#01h

;;    for(j = 0; j < 4; ++j)
CLINEA 0000H 0000H 011EH 0010H 0015H
	cmp	r7,	#04h
	blt	_$L54
CBLOCKEND 78 3 290

;;  for(i = 0; i < 4; ++i)
CLINEA 0000H 0000H 011CH 0003H 0018H
	add	r6,	#01h

;;  for(i = 0; i < 4; ++i)
CLINEA 0000H 0000H 011CH 0010H 0015H
	cmp	r6,	#04h
	blt	_$L48
CBLOCKEND 78 2 291

;;}
CLINEA 0000H 0001H 0123H 0001H 0001H
	pop	er8
	pop	xr4
	pop	pc
CBLOCKEND 78 1 291
CFUNCTIONEND 78


	rseg $$ShiftRows$aes
CFUNCTION 79

_ShiftRows	:
CBLOCK 79 1 297

;;{
CLINEA 0000H 0001H 0129H 0001H 0001H
;;*****************************************
;;	register/stack information
;;*****************************************
;;*****************************************

	push	bp
CBLOCK 79 2 297
CLOCAL 46H 0001H 0017H 0002H "temp" 02H 00H 00H

;;  temp           = (*state)[0][1];
CLINEA 0000H 0001H 012DH 0003H 0022H
	l	bp,	NEAR _state
	l	r0,	1[bp]

;;  (*state)[0][1] = (*state)[1][1];
CLINEA 0000H 0001H 012EH 0003H 0022H
	l	r2,	5[bp]
	st	r2,	1[bp]

;;  (*state)[1][1] = (*state)[2][1];
CLINEA 0000H 0001H 012FH 0003H 0022H
	l	bp,	NEAR _state
	l	r2,	9[bp]
	st	r2,	5[bp]

;;  (*state)[2][1] = (*state)[3][1];
CLINEA 0000H 0001H 0130H 0003H 0022H
	l	bp,	NEAR _state
	l	r2,	13[bp]
	st	r2,	9[bp]

;;  (*state)[3][1] = temp;
CLINEA 0000H 0001H 0131H 0003H 0018H
	l	bp,	NEAR _state
	st	r0,	13[bp]

;;  temp           = (*state)[0][2];
CLINEA 0000H 0001H 0134H 0003H 0022H
	l	bp,	NEAR _state
	l	r0,	2[bp]

;;  (*state)[0][2] = (*state)[2][2];
CLINEA 0000H 0001H 0135H 0003H 0022H
	l	r2,	10[bp]
	st	r2,	2[bp]

;;  (*state)[2][2] = temp;
CLINEA 0000H 0001H 0136H 0003H 0018H
	l	bp,	NEAR _state
	st	r0,	10[bp]

;;  temp       = (*state)[1][2];
CLINEA 0000H 0001H 0138H 0003H 001EH
	l	bp,	NEAR _state
	l	r0,	6[bp]

;;  (*state)[1][2] = (*state)[3][2];
CLINEA 0000H 0001H 0139H 0003H 0022H
	l	r2,	14[bp]
	st	r2,	6[bp]

;;  (*state)[3][2] = temp;
CLINEA 0000H 0001H 013AH 0003H 0018H
	l	bp,	NEAR _state
	st	r0,	14[bp]

;;  temp       = (*state)[0][3];
CLINEA 0000H 0001H 013DH 0003H 001EH
	l	bp,	NEAR _state
	l	r0,	3[bp]

;;  (*state)[0][3] = (*state)[3][3];
CLINEA 0000H 0001H 013EH 0003H 0022H
	l	r2,	15[bp]
	st	r2,	3[bp]

;;  (*state)[3][3] = (*state)[2][3];
CLINEA 0000H 0001H 013FH 0003H 0022H
	l	bp,	NEAR _state
	l	r2,	11[bp]
	st	r2,	15[bp]

;;  (*state)[2][3] = (*state)[1][3];
CLINEA 0000H 0001H 0140H 0003H 0022H
	l	bp,	NEAR _state
	l	r2,	7[bp]
	st	r2,	11[bp]

;;  (*state)[1][3] = temp;
CLINEA 0000H 0001H 0141H 0003H 0018H
	l	bp,	NEAR _state
	st	r0,	7[bp]
CBLOCKEND 79 2 322

;;}
CLINEA 0000H 0001H 0142H 0001H 0001H
	pop	bp
	rt
CBLOCKEND 79 1 322
CFUNCTIONEND 79


	rseg $$xtime$aes
CFUNCTION 80

_xtime	:
CBLOCK 80 1 325

;;{
CLINEA 0000H 0001H 0145H 0001H 0001H
;;*****************************************
;;	register/stack information
;;*****************************************
;;*****************************************

	push	er4
CBLOCK 80 2 325
CARGUMENT 46H 0001H 0014H "x" 02H 00H 00H

;;  return ((x<<1) ^ (((x>>7) & 1) * 0x1b));
CLINEA 0000H 0001H 0146H 0003H 002AH
	mov	r2,	r0
	mov	r3,	#00h
	mov	er0,	er2
	sll	r0,	#01h
	mov	r4,	r0
	mov	er0,	er2
	srlc	r0,	#07h
	sra	r1,	#07h
	and	r0,	#01h
	mov	r2,	#01bh
	mul	er0,	r2
	xor	r0,	r4
CBLOCKEND 80 2 327

;;}
CLINEA 0000H 0000H 0147H 0001H 0001H
	pop	er4
	rt
CBLOCKEND 80 1 327
CFUNCTIONEND 80


	rseg $$MixColumns$aes
CFUNCTION 81

_MixColumns	:
CBLOCK 81 1 331

;;{
CLINEA 0000H 0001H 014BH 0001H 0001H
;;*****************************************
;;	register/stack information
;;*****************************************
;;*****************************************

	push	lr
	push	xr4
	push	er8
CBLOCK 81 2 331
CRET 0006H
CLOCAL 46H 0001H 001AH 0002H "i" 02H 00H 00H
CLOCAL 46H 0001H 001BH 0002H "Tmp" 02H 00H 00H
CLOCAL 46H 0001H 001DH 0002H "Tm" 02H 00H 00H
CLOCAL 46H 0001H 001CH 0002H "t" 02H 00H 00H

;;  for(i = 0; i < 4; ++i)
CLINEA 0000H 0001H 014EH 0003H 0018H
	mov	r6,	#00h	;; _li$0
_$L63 :
CBLOCK 81 3 335

;;    t   = (*state)[i][0];
CLINEA 0000H 0001H 0150H 0005H 0019H
	mov	r0,	r6
	mov	r1,	#00h
	sllc	r1,	#02h
	sll	r0,	#02h
	l	er2,	NEAR _state
	add	er0,	er2
	l	r8,	[er0]
	mov	r4,	r8	;; _lt$6

;;    Tmp = (*state)[i][0] ^ (*state)[i][1] ^ (*state)[i][2] ^ (*state)[i][3] ;
CLINEA 0000H 0001H 0151H 0005H 004DH
	l	r5,	01h[er0]
	xor	r4,	r5
	l	r5,	02h[er0]
	xor	r4,	r5
	l	r5,	03h[er0]
	xor	r4,	r5
	mov	r7,	r4	;; _lTmp$2

;;    Tm  = (*state)[i][0] ^ (*state)[i][1] ; Tm = xtime(Tm);  (*state)[i][0] ^= Tm ^ Tmp ;
CLINEA 0000H 0000H 0152H 0005H 0059H
	mov	r2,	r8
	l	r0,	01h[er0]
	xor	r2,	r0
	mov	r0,	r2
	bl	_xtime
	mov	r9,	r0	;; _lTm$4
	mov	r0,	r6
	mov	r1,	#00h
	sllc	r1,	#02h
	sll	r0,	#02h
	mov	er2,	er0
	l	er4,	NEAR _state
	add	er2,	er4
	mov	r4,	r7
	xor	r4,	r9
	l	r5,	[er2]
	xor	r5,	r4
	st	r5,	[er2]

;;    Tm  = (*state)[i][1] ^ (*state)[i][2] ; Tm = xtime(Tm);  (*state)[i][1] ^= Tm ^ Tmp ;
CLINEA 0000H 0000H 0153H 0005H 0059H
	l	er2,	NEAR _state
	add	er0,	er2
	l	r2,	02h[er0]
	l	r0,	01h[er0]
	xor	r2,	r0
	mov	r0,	r2
	bl	_xtime
	mov	r9,	r0	;; _lTm$4
	mov	r0,	r6
	mov	r1,	#00h
	sllc	r1,	#02h
	sll	r0,	#02h
	l	er2,	NEAR _state
	add	er0,	er2
	mov	r2,	r7
	xor	r2,	r9
	l	r3,	01h[er0]
	xor	r3,	r2
	st	r3,	01h[er0]

;;    Tm  = (*state)[i][2] ^ (*state)[i][3] ; Tm = xtime(Tm);  (*state)[i][2] ^= Tm ^ Tmp ;
CLINEA 0000H 0000H 0154H 0005H 0059H
	l	r2,	02h[er0]
	l	r0,	03h[er0]
	xor	r2,	r0
	mov	r0,	r2
	bl	_xtime
	mov	r9,	r0	;; _lTm$4
	mov	r0,	r6
	mov	r1,	#00h
	sllc	r1,	#02h
	sll	r0,	#02h
	l	er2,	NEAR _state
	add	er0,	er2
	mov	r2,	r7
	xor	r2,	r9
	l	r3,	02h[er0]
	xor	r3,	r2
	st	r3,	02h[er0]

;;    Tm  = (*state)[i][3] ^ t ;        Tm = xtime(Tm);  (*state)[i][3] ^= Tm ^ Tmp ;
CLINEA 0000H 0000H 0155H 0005H 0053H
	l	r0,	03h[er0]
	xor	r0,	r8
	bl	_xtime
	mov	r9,	r0	;; _lTm$4
	mov	r0,	r6
	mov	r1,	#00h
	sllc	r1,	#02h
	sll	r0,	#02h
	l	er2,	NEAR _state
	add	er0,	er2
	mov	r2,	r7
	xor	r2,	r9
	l	r3,	03h[er0]
	xor	r3,	r2
	st	r3,	03h[er0]
CBLOCKEND 81 3 342

;;  for(i = 0; i < 4; ++i)
CLINEA 0000H 0000H 014EH 0003H 0018H
	add	r6,	#01h

;;  for(i = 0; i < 4; ++i)
CLINEA 0000H 0000H 014EH 0010H 0015H
	cmp	r6,	#04h
	bge	_$M9
	b	_$L63
_$M9 :
CBLOCKEND 81 2 343

;;}
CLINEA 0000H 0001H 0157H 0001H 0001H
	pop	er8
	pop	xr4
	pop	pc
CBLOCKEND 81 1 343
CFUNCTIONEND 81


	rseg $$InvMixColumns$aes
CFUNCTION 82

_InvMixColumns	:
CBLOCK 82 1 369

;;{
CLINEA 0000H 0001H 0171H 0001H 0001H
;;*****************************************
;;	register/stack information
;;*****************************************
;;*****************************************

	push	lr
	push	fp
	mov	fp,	sp
	add	sp,	#-022
	push	xr8
	push	xr4
	push	bp
CBLOCK 82 2 369
CRET 0022H
CLOCAL 47H 0002H 0029H 0002H "i" 02H 00H 01H
CLOCAL 46H 0001H 001DH 0002H "a" 02H 00H 00H
CLOCAL 46H 0001H 001AH 0002H "b" 02H 00H 00H
CLOCAL 46H 0001H 001BH 0002H "c" 02H 00H 00H
CLOCAL 46H 0001H 001CH 0002H "d" 02H 00H 00H

;;  for(i=0;i<4;++i)
CLINEA 0000H 0001H 0174H 0003H 0012H
	mov	er10,	#0 	;; _li$0
_$L70 :
CBLOCK 82 3 373

;;    a = (*state)[i][0];
CLINEA 0000H 0001H 0176H 0005H 0017H
	mov	er4,	er10
	sllc	r5,	#02h
	sll	r4,	#02h
	mov	er0,	er4
	l	er2,	NEAR _state
	add	er0,	er2
	l	r9,	[er0]
	mov	bp,	er4

;;    b = (*state)[i][1];
CLINEA 0000H 0001H 0177H 0005H 0017H
	l	r6,	01h[er0]

;;    c = (*state)[i][2];
CLINEA 0000H 0001H 0178H 0005H 0017H
	l	r7,	02h[er0]

;;    d = (*state)[i][3];
CLINEA 0000H 0001H 0179H 0005H 0017H
	l	r8,	03h[er0]

;;    (*state)[i][0] = Multiply(a, 0x0e) ^ Multiply(b, 0x0b) ^ Multiply(c, 0x0d) ^ Multiply(d, 0x09);
CLINEA 0000H 0000H 017BH 0005H 0063H
	mov	r0,	r9
	bl	_xtime
	mov	r1,	#00h
	mov	er4,	er0
	mov	r0,	r9
	bl	_xtime
	bl	_xtime
	mov	r1,	#00h
	xor	r0,	r4
	xor	r1,	r5
	mov	er4,	er0
	mov	r0,	r9
	bl	_xtime
	bl	_xtime
	bl	_xtime
	mov	r1,	#00h
	xor	r0,	r4
	xor	r1,	r5
	st	er0,	-2[fp]
	mov	r0,	r9
	bl	_xtime
	bl	_xtime
	bl	_xtime
	bl	_xtime
	mov	r0,	r6
	mov	r1,	#00h
	mov	er4,	er0
	bl	_xtime
	mov	r1,	#00h
	xor	r0,	r4
	xor	r1,	r5
	mov	er4,	er0
	mov	r0,	r6
	bl	_xtime
	bl	_xtime
	mov	r0,	r6
	bl	_xtime
	bl	_xtime
	bl	_xtime
	mov	r1,	#00h
	xor	r0,	r4
	xor	r1,	r5
	mov	er4,	er0
	mov	r0,	r6
	bl	_xtime
	bl	_xtime
	bl	_xtime
	bl	_xtime
	l	er0,	-2[fp]
	xor	r0,	r4
	xor	r1,	r5
	st	er0,	-4[fp]
	mov	r0,	r7
	mov	r1,	#00h
	mov	er4,	er0
	bl	_xtime
	mov	r0,	r7
	bl	_xtime
	bl	_xtime
	mov	r1,	#00h
	xor	r0,	r4
	xor	r1,	r5
	mov	er4,	er0
	mov	r0,	r7
	bl	_xtime
	bl	_xtime
	bl	_xtime
	mov	r1,	#00h
	xor	r0,	r4
	xor	r1,	r5
	mov	er4,	er0
	mov	r0,	r7
	bl	_xtime
	bl	_xtime
	bl	_xtime
	bl	_xtime
	l	er0,	-4[fp]
	xor	r0,	r4
	xor	r1,	r5
	st	er0,	-6[fp]
	mov	r0,	r8
	mov	r1,	#00h
	mov	er4,	er0
	bl	_xtime
	mov	r0,	r8
	bl	_xtime
	bl	_xtime
	mov	r0,	r8
	bl	_xtime
	bl	_xtime
	bl	_xtime
	mov	r1,	#00h
	xor	r0,	r4
	xor	r1,	r5
	mov	er4,	er0
	mov	r0,	r8
	bl	_xtime
	bl	_xtime
	bl	_xtime
	bl	_xtime
	l	r0,	-6[fp]
	xor	r0,	r4
	mov	er2,	bp
	l	er4,	NEAR _state
	add	er2,	er4
	st	r0,	[er2]

;;    (*state)[i][1] = Multiply(a, 0x09) ^ Multiply(b, 0x0e) ^ Multiply(c, 0x0b) ^ Multiply(d, 0x0d);
CLINEA 0000H 0000H 017CH 0005H 0063H
	mov	r0,	r9
	mov	r1,	#00h
	mov	er4,	er0
	bl	_xtime
	mov	r0,	r9
	bl	_xtime
	bl	_xtime
	mov	r0,	r9
	bl	_xtime
	bl	_xtime
	bl	_xtime
	mov	r1,	#00h
	xor	r0,	r4
	xor	r1,	r5
	st	er0,	-8[fp]
	mov	r0,	r9
	bl	_xtime
	bl	_xtime
	bl	_xtime
	bl	_xtime
	mov	r0,	r6
	bl	_xtime
	mov	r1,	#00h
	mov	er4,	er0
	mov	r0,	r6
	bl	_xtime
	bl	_xtime
	mov	r1,	#00h
	xor	r0,	r4
	xor	r1,	r5
	mov	er4,	er0
	mov	r0,	r6
	bl	_xtime
	bl	_xtime
	bl	_xtime
	mov	r1,	#00h
	xor	r0,	r4
	xor	r1,	r5
	mov	er4,	er0
	mov	r0,	r6
	bl	_xtime
	bl	_xtime
	bl	_xtime
	bl	_xtime
	l	er0,	-8[fp]
	xor	r0,	r4
	xor	r1,	r5
	st	er0,	-10[fp]
	mov	r0,	r7
	mov	r1,	#00h
	mov	er4,	er0
	bl	_xtime
	mov	r1,	#00h
	xor	r0,	r4
	xor	r1,	r5
	mov	er4,	er0
	mov	r0,	r7
	bl	_xtime
	bl	_xtime
	mov	r0,	r7
	bl	_xtime
	bl	_xtime
	bl	_xtime
	mov	r1,	#00h
	xor	r0,	r4
	xor	r1,	r5
	mov	er4,	er0
	mov	r0,	r7
	bl	_xtime
	bl	_xtime
	bl	_xtime
	bl	_xtime
	l	er0,	-10[fp]
	xor	r0,	r4
	xor	r1,	r5
	st	er0,	-12[fp]
	mov	r0,	r8
	mov	r1,	#00h
	mov	er4,	er0
	bl	_xtime
	mov	r0,	r8
	bl	_xtime
	bl	_xtime
	mov	r1,	#00h
	xor	r0,	r4
	xor	r1,	r5
	mov	er4,	er0
	mov	r0,	r8
	bl	_xtime
	bl	_xtime
	bl	_xtime
	mov	r1,	#00h
	xor	r0,	r4
	xor	r1,	r5
	mov	er4,	er0
	mov	r0,	r8
	bl	_xtime
	bl	_xtime
	bl	_xtime
	bl	_xtime
	l	r0,	-12[fp]
	xor	r0,	r4
	mov	er2,	bp
	l	er4,	NEAR _state
	add	er2,	er4
	st	r0,	01h[er2]

;;    (*state)[i][2] = Multiply(a, 0x0d) ^ Multiply(b, 0x09) ^ Multiply(c, 0x0e) ^ Multiply(d, 0x0b);
CLINEA 0000H 0000H 017DH 0005H 0063H
	mov	r0,	r9
	mov	r1,	#00h
	mov	er4,	er0
	bl	_xtime
	mov	r0,	r9
	bl	_xtime
	bl	_xtime
	mov	r1,	#00h
	xor	r0,	r4
	xor	r1,	r5
	mov	er4,	er0
	mov	r0,	r9
	bl	_xtime
	bl	_xtime
	bl	_xtime
	mov	r1,	#00h
	xor	r0,	r4
	xor	r1,	r5
	st	er0,	-14[fp]
	mov	r0,	r9
	bl	_xtime
	bl	_xtime
	bl	_xtime
	bl	_xtime
	mov	r0,	r6
	mov	r1,	#00h
	mov	er4,	er0
	bl	_xtime
	mov	r0,	r6
	bl	_xtime
	bl	_xtime
	mov	r0,	r6
	bl	_xtime
	bl	_xtime
	bl	_xtime
	mov	r1,	#00h
	xor	r0,	r4
	xor	r1,	r5
	mov	er4,	er0
	mov	r0,	r6
	bl	_xtime
	bl	_xtime
	bl	_xtime
	bl	_xtime
	l	er0,	-14[fp]
	xor	r0,	r4
	xor	r1,	r5
	st	er0,	-16[fp]
	mov	r0,	r7
	bl	_xtime
	mov	r1,	#00h
	mov	er4,	er0
	mov	r0,	r7
	bl	_xtime
	bl	_xtime
	mov	r1,	#00h
	xor	r0,	r4
	xor	r1,	r5
	mov	er4,	er0
	mov	r0,	r7
	bl	_xtime
	bl	_xtime
	bl	_xtime
	mov	r1,	#00h
	xor	r0,	r4
	xor	r1,	r5
	mov	er4,	er0
	mov	r0,	r7
	bl	_xtime
	bl	_xtime
	bl	_xtime
	bl	_xtime
	l	er0,	-16[fp]
	xor	r0,	r4
	xor	r1,	r5
	st	er0,	-18[fp]
	mov	r0,	r8
	mov	r1,	#00h
	mov	er4,	er0
	bl	_xtime
	mov	r1,	#00h
	xor	r0,	r4
	xor	r1,	r5
	mov	er4,	er0
	mov	r0,	r8
	bl	_xtime
	bl	_xtime
	mov	r0,	r8
	bl	_xtime
	bl	_xtime
	bl	_xtime
	mov	r1,	#00h
	xor	r0,	r4
	xor	r1,	r5
	mov	er4,	er0
	mov	r0,	r8
	bl	_xtime
	bl	_xtime
	bl	_xtime
	bl	_xtime
	l	r0,	-18[fp]
	xor	r0,	r4
	mov	er2,	bp
	l	er4,	NEAR _state
	add	er2,	er4
	st	r0,	02h[er2]

;;    (*state)[i][3] = Multiply(a, 0x0b) ^ Multiply(b, 0x0d) ^ Multiply(c, 0x09) ^ Multiply(d, 0x0e);
CLINEA 0000H 0000H 017EH 0005H 0063H
	mov	r0,	r9
	mov	r1,	#00h
	mov	er4,	er0
	bl	_xtime
	mov	r1,	#00h
	xor	r0,	r4
	xor	r1,	r5
	mov	er4,	er0
	mov	r0,	r9
	bl	_xtime
	bl	_xtime
	mov	r0,	r9
	bl	_xtime
	bl	_xtime
	bl	_xtime
	mov	r1,	#00h
	xor	r0,	r4
	xor	r1,	r5
	st	er0,	-20[fp]
	mov	r0,	r9
	bl	_xtime
	bl	_xtime
	bl	_xtime
	bl	_xtime
	mov	r0,	r6
	mov	r1,	#00h
	mov	er4,	er0
	bl	_xtime
	mov	r0,	r6
	bl	_xtime
	bl	_xtime
	mov	r1,	#00h
	xor	r0,	r4
	xor	r1,	r5
	mov	er4,	er0
	mov	r0,	r6
	bl	_xtime
	bl	_xtime
	bl	_xtime
	mov	r1,	#00h
	xor	r0,	r4
	xor	r1,	r5
	mov	er4,	er0
	mov	r0,	r6
	bl	_xtime
	bl	_xtime
	bl	_xtime
	bl	_xtime
	l	er0,	-20[fp]
	xor	r0,	r4
	xor	r1,	r5
	st	er0,	-22[fp]
	mov	r0,	r7
	mov	r1,	#00h
	mov	er4,	er0
	bl	_xtime
	mov	r0,	r7
	bl	_xtime
	bl	_xtime
	mov	r0,	r7
	bl	_xtime
	bl	_xtime
	bl	_xtime
	mov	r1,	#00h
	xor	r0,	r4
	xor	r1,	r5
	mov	er4,	er0
	mov	r0,	r7
	bl	_xtime
	bl	_xtime
	bl	_xtime
	bl	_xtime
	l	er0,	-22[fp]
	xor	r0,	r4
	xor	r1,	r5
	mov	er6,	er0
	mov	r0,	r8
	bl	_xtime
	mov	r1,	#00h
	mov	er4,	er0
	mov	r0,	r8
	bl	_xtime
	bl	_xtime
	mov	r1,	#00h
	xor	r0,	r4
	xor	r1,	r5
	mov	er4,	er0
	mov	r0,	r8
	bl	_xtime
	bl	_xtime
	bl	_xtime
	mov	r1,	#00h
	xor	r0,	r4
	xor	r1,	r5
	mov	er4,	er0
	mov	r0,	r8
	bl	_xtime
	bl	_xtime
	bl	_xtime
	bl	_xtime
	mov	r0,	r6
	xor	r0,	r4
	mov	er2,	bp
	l	er4,	NEAR _state
	add	er2,	er4
	st	r0,	03h[er2]
CBLOCKEND 82 3 383

;;  for(i=0;i<4;++i)
CLINEA 0000H 0000H 0174H 0003H 0012H
	add	er10,	#1 

;;  for(i=0;i<4;++i)
CLINEA 0000H 0000H 0174H 0010H 0015H
	cmp	r10,	#04h
	cmpc	r11,	#00h
	bges	_$M11
	b	_$L70
_$M11 :
CBLOCKEND 82 2 384

;;}
CLINEA 0000H 0001H 0180H 0001H 0001H
	pop	bp
	pop	xr4
	pop	xr8
	mov	sp,	fp
	pop	fp
	pop	pc
CBLOCKEND 82 1 384
CFUNCTIONEND 82


	rseg $$InvSubBytes$aes
CFUNCTION 83

_InvSubBytes	:
CBLOCK 83 1 390

;;{
CLINEA 0000H 0001H 0186H 0001H 0001H
;;*****************************************
;;	register/stack information
;;*****************************************
;;*****************************************

	push	lr
	push	xr4
	push	er8
CBLOCK 83 2 390
CRET 0006H
CLOCAL 46H 0001H 001AH 0002H "i" 02H 00H 00H
CLOCAL 46H 0001H 001BH 0002H "j" 02H 00H 00H

;;  for(i=0;i<4;++i)
CLINEA 0000H 0001H 0188H 0003H 0012H
	mov	r6,	#00h	;; _li$0
_$L77 :
CBLOCK 83 3 393

;;    for(j=0;j<4;++j)
CLINEA 0000H 0001H 018AH 0009H 000CH
	mov	r7,	#00h	;; _lj$2

;;    for(j=0;j<4;++j)
CLINEA 0000H 0000H 018AH 0011H 0013H
_$L83 :
CBLOCK 83 4 395

;;      (*state)[j][i] = getSBoxInvert((*state)[j][i]);
CLINEA 0000H 0000H 018CH 0007H 0035H
	mov	r2,	r6
	mov	r3,	#00h
	mov	r0,	r7
	mov	r1,	#00h
	sllc	r1,	#02h
	sll	r0,	#02h
	l	er4,	NEAR _state
	add	er0,	er4
	add	er0,	er2
	l	r0,	[er0]
	bl	_getSBoxInvert
	mov	r8,	r0
	mov	r2,	r6
	mov	r3,	#00h
	mov	r0,	r7
	mov	r1,	#00h
	sllc	r1,	#02h
	sll	r0,	#02h
	l	er4,	NEAR _state
	add	er0,	er4
	add	er0,	er2
	st	r8,	[er0]
CBLOCKEND 83 4 397

;;    for(j=0;j<4;++j)
CLINEA 0000H 0000H 018AH 0011H 0013H
	add	r7,	#01h

;;    for(j=0;j<4;++j)
CLINEA 0000H 0000H 018AH 000DH 0010H
	cmp	r7,	#04h
	blt	_$L83
CBLOCKEND 83 3 398

;;  for(i=0;i<4;++i)
CLINEA 0000H 0000H 0188H 0003H 0012H
	add	r6,	#01h

;;  for(i=0;i<4;++i)
CLINEA 0000H 0000H 0188H 000DH 0010H
	cmp	r6,	#04h
	blt	_$L77
CBLOCKEND 83 2 399

;;}
CLINEA 0000H 0001H 018FH 0001H 0001H
	pop	er8
	pop	xr4
	pop	pc
CBLOCKEND 83 1 399
CFUNCTIONEND 83


	rseg $$InvShiftRows$aes
CFUNCTION 84

_InvShiftRows	:
CBLOCK 84 1 402

;;{
CLINEA 0000H 0001H 0192H 0001H 0001H
;;*****************************************
;;	register/stack information
;;*****************************************
;;*****************************************

	push	bp
CBLOCK 84 2 402
CLOCAL 46H 0001H 0017H 0002H "temp" 02H 00H 00H

;;  temp=(*state)[3][1];
CLINEA 0000H 0001H 0196H 0003H 0016H
	l	bp,	NEAR _state
	l	r0,	13[bp]

;;  (*state)[3][1]=(*state)[2][1];
CLINEA 0000H 0001H 0197H 0003H 0020H
	l	r2,	9[bp]
	st	r2,	13[bp]

;;  (*state)[2][1]=(*state)[1][1];
CLINEA 0000H 0001H 0198H 0003H 0020H
	l	bp,	NEAR _state
	l	r2,	5[bp]
	st	r2,	9[bp]

;;  (*state)[1][1]=(*state)[0][1];
CLINEA 0000H 0001H 0199H 0003H 0020H
	l	bp,	NEAR _state
	l	r2,	1[bp]
	st	r2,	5[bp]

;;  (*state)[0][1]=temp;
CLINEA 0000H 0001H 019AH 0003H 0016H
	l	bp,	NEAR _state
	st	r0,	1[bp]

;;  temp=(*state)[0][2];
CLINEA 0000H 0001H 019DH 0003H 0016H
	l	bp,	NEAR _state
	l	r0,	2[bp]

;;  (*state)[0][2]=(*state)[2][2];
CLINEA 0000H 0001H 019EH 0003H 0020H
	l	r2,	10[bp]
	st	r2,	2[bp]

;;  (*state)[2][2]=temp;
CLINEA 0000H 0001H 019FH 0003H 0016H
	l	bp,	NEAR _state
	st	r0,	10[bp]

;;  temp=(*state)[1][2];
CLINEA 0000H 0001H 01A1H 0003H 0016H
	l	bp,	NEAR _state
	l	r0,	6[bp]

;;  (*state)[1][2]=(*state)[3][2];
CLINEA 0000H 0001H 01A2H 0003H 0020H
	l	r2,	14[bp]
	st	r2,	6[bp]

;;  (*state)[3][2]=temp;
CLINEA 0000H 0001H 01A3H 0003H 0016H
	l	bp,	NEAR _state
	st	r0,	14[bp]

;;  temp=(*state)[0][3];
CLINEA 0000H 0001H 01A6H 0003H 0016H
	l	bp,	NEAR _state
	l	r0,	3[bp]

;;  (*state)[0][3]=(*state)[1][3];
CLINEA 0000H 0001H 01A7H 0003H 0020H
	l	r2,	7[bp]
	st	r2,	3[bp]

;;  (*state)[1][3]=(*state)[2][3];
CLINEA 0000H 0001H 01A8H 0003H 0020H
	l	bp,	NEAR _state
	l	r2,	11[bp]
	st	r2,	7[bp]

;;  (*state)[2][3]=(*state)[3][3];
CLINEA 0000H 0001H 01A9H 0003H 0020H
	l	bp,	NEAR _state
	l	r2,	15[bp]
	st	r2,	11[bp]

;;  (*state)[3][3]=temp;
CLINEA 0000H 0001H 01AAH 0003H 0016H
	l	bp,	NEAR _state
	st	r0,	15[bp]
CBLOCKEND 84 2 427

;;}
CLINEA 0000H 0001H 01ABH 0001H 0001H
	pop	bp
	rt
CBLOCKEND 84 1 427
CFUNCTIONEND 84


	rseg $$Cipher$aes
CFUNCTION 85

_Cipher	:
CBLOCK 85 1 432

;;{
CLINEA 0000H 0001H 01B0H 0001H 0001H
;;*****************************************
;;	register/stack information
;;*****************************************
;;*****************************************

	push	lr
	push	er4
CBLOCK 85 2 432
CRET 0002H
CLOCAL 46H 0001H 0018H 0002H "round" 02H 00H 00H

;;  AddRoundKey(0); 
CLINEA 0000H 0001H 01B4H 0003H 0012H
	mov	r0,	#00h
	bl	_AddRoundKey

;;  for(round = 1; round < Nr; ++round)
CLINEA 0000H 0001H 01B9H 0003H 0025H
	mov	r4,	#01h	;; _lround$0
_$L91 :
CBLOCK 85 3 442

;;    SubBytes();
CLINEA 0000H 0001H 01BBH 0005H 000FH
	bl	_SubBytes

;;    ShiftRows();
CLINEA 0000H 0001H 01BCH 0005H 0010H
	bl	_ShiftRows

;;    MixColumns();
CLINEA 0000H 0001H 01BDH 0005H 0011H
	bl	_MixColumns

;;    AddRoundKey(round);
CLINEA 0000H 0001H 01BEH 0005H 0017H
	mov	r0,	r4
	bl	_AddRoundKey
CBLOCKEND 85 3 447

;;  for(round = 1; round < Nr; ++round)
CLINEA 0000H 0000H 01B9H 0003H 0025H
	add	r4,	#01h

;;  for(round = 1; round < Nr; ++round)
CLINEA 0000H 0000H 01B9H 000DH 0010H
	cmp	r4,	#0ah
	blt	_$L91

;;  SubBytes();
CLINEA 0000H 0001H 01C3H 0003H 000DH
	bl	_SubBytes

;;  ShiftRows();
CLINEA 0000H 0001H 01C4H 0003H 000EH
	bl	_ShiftRows

;;  AddRoundKey(Nr);
CLINEA 0000H 0001H 01C5H 0003H 0012H
	mov	r0,	#0ah
	bl	_AddRoundKey
CBLOCKEND 85 2 454

;;}
CLINEA 0000H 0001H 01C6H 0001H 0001H
	pop	er4
	pop	pc
CBLOCKEND 85 1 454
CFUNCTIONEND 85


	rseg $$InvCipher$aes
CFUNCTION 86

_InvCipher	:
CBLOCK 86 1 457

;;{
CLINEA 0000H 0001H 01C9H 0001H 0001H
;;*****************************************
;;	register/stack information
;;*****************************************
;;*****************************************

	push	lr
	push	er4
CBLOCK 86 2 457
CRET 0002H
CLOCAL 46H 0001H 0018H 0002H "round" 02H 00H 00H

;;  AddRoundKey(Nr); 
CLINEA 0000H 0001H 01CDH 0003H 0013H
	mov	r0,	#0ah
	bl	_AddRoundKey

;;  for(round=Nr-1;round>0;round--)
CLINEA 0000H 0001H 01D2H 0003H 0021H
	mov	r4,	#09h	;; _lround$0
_$L98 :
CBLOCK 86 3 467

;;    InvShiftRows();
CLINEA 0000H 0001H 01D4H 0005H 0013H
	bl	_InvShiftRows

;;    InvSubBytes();
CLINEA 0000H 0001H 01D5H 0005H 0012H
	bl	_InvSubBytes

;;    AddRoundKey(round);
CLINEA 0000H 0001H 01D6H 0005H 0017H
	mov	r0,	r4
	bl	_AddRoundKey

;;    InvMixColumns();
CLINEA 0000H 0001H 01D7H 0005H 0014H
	bl	_InvMixColumns
CBLOCKEND 86 3 472

;;  for(round=Nr-1;round>0;round--)
CLINEA 0000H 0000H 01D2H 0003H 0021H
	add	r4,	#0ffh

;;  for(round=Nr-1;round>0;round--)
CLINEA 0000H 0000H 01D2H 000DH 0010H
	cmp	r4,	#00h
	bgt	_$L98

;;  InvShiftRows();
CLINEA 0000H 0001H 01DCH 0003H 0011H
	bl	_InvShiftRows

;;  InvSubBytes();
CLINEA 0000H 0001H 01DDH 0003H 0010H
	bl	_InvSubBytes

;;  AddRoundKey(0);
CLINEA 0000H 0001H 01DEH 0003H 0011H
	mov	r0,	#00h
	bl	_AddRoundKey
CBLOCKEND 86 2 479

;;}
CLINEA 0000H 0001H 01DFH 0001H 0001H
	pop	er4
	pop	pc
CBLOCKEND 86 1 479
CFUNCTIONEND 86


	rseg $$BlockCopy$aes
CFUNCTION 87

_BlockCopy	:
CBLOCK 87 1 482

;;{
CLINEA 0000H 0001H 01E2H 0001H 0001H
;;*****************************************
;;	register/stack information
;;*****************************************
;;*****************************************

	push	xr8
	push	er6
	mov	er10,	er2
	mov	er8,	er0
CBLOCK 87 2 482
CARGUMENT 46H 0002H 0028H "output" 04H 03H 00H 00H 00H
CARGUMENT 46H 0002H 0029H "input" 04H 03H 00H 00H 00H
CLOCAL 46H 0001H 001AH 0002H "i" 02H 00H 00H

;;  for (i=0;i<KEYLEN;++i)
CLINEA 0000H 0001H 01E4H 0003H 0018H
	mov	r6,	#00h	;; _li$0
_$L105 :
CBLOCK 87 3 485

;;    output[i] = input[i];
CLINEA 0000H 0001H 01E6H 0005H 0019H
	mov	r0,	r6
	mov	r1,	#00h
	mov	er2,	er0
	add	er2,	er10
	add	er0,	er8
	l	r2,	[er2]
	st	r2,	[er0]
CBLOCKEND 87 3 487

;;  for (i=0;i<KEYLEN;++i)
CLINEA 0000H 0000H 01E4H 0003H 0018H
	add	r6,	#01h

;;  for (i=0;i<KEYLEN;++i)
CLINEA 0000H 0000H 01E4H 000DH 0010H
	cmp	r6,	#010h
	blt	_$L105
CBLOCKEND 87 2 488

;;}
CLINEA 0000H 0001H 01E8H 0001H 0001H
	pop	er6
	pop	xr8
	rt
CBLOCKEND 87 1 488
CFUNCTIONEND 87


	rseg $$AES128_ECB_encrypt$aes
CFUNCTION 66

_AES128_ECB_encrypt	:
CBLOCK 66 1 499

;;{
CLINEA 0000H 0001H 01F3H 0001H 0001H
;;*****************************************
;;	register/stack information
;;*****************************************
	_output$4	set	4
;;*****************************************

	push	lr
	push	fp
	mov	fp,	sp
	push	er10
	mov	er10,	er2
CBLOCK 66 2 499
CRET 0004H
CARGUMENT 46H 0002H 0024H "input" 04H 03H 00H 00H 00H
CARGUMENT 44H 0002H 0029H "key" 04H 03H 00H 00H 00H
CARGUMENT 42H 0002H 0004H "output" 04H 03H 00H 00H 00H

;;  BlockCopy(output, input);
CLINEA 0000H 0001H 01F5H 0003H 001BH
	mov	er2,	er0
	l	er0,	_output$4[fp]
	bl	_BlockCopy

;;  state = (state_t*)output;
CLINEA 0000H 0001H 01F6H 0003H 001BH
	l	er0,	_output$4[fp]
	st	er0,	NEAR _state

;;  Key = key;
CLINEA 0000H 0001H 01F8H 0003H 000CH
	st	er10,	NEAR _Key

;;  KeyExpansion();
CLINEA 0000H 0001H 01F9H 0003H 0011H
	bl	_KeyExpansion

;;  Cipher();
CLINEA 0000H 0001H 01FCH 0003H 000BH
	bl	_Cipher
CBLOCKEND 66 2 509

;;}
CLINEA 0000H 0001H 01FDH 0001H 0001H
	pop	er10
	mov	sp,	fp
	pop	fp
	pop	pc
CBLOCKEND 66 1 509
CFUNCTIONEND 66


	rseg $$AES128_ECB_decrypt$aes
CFUNCTION 67

_AES128_ECB_decrypt	:
CBLOCK 67 1 512

;;{
CLINEA 0000H 0001H 0200H 0001H 0001H
;;*****************************************
;;	register/stack information
;;*****************************************
	_output$4	set	4
;;*****************************************

	push	lr
	push	fp
	mov	fp,	sp
	push	er10
	mov	er10,	er2
CBLOCK 67 2 512
CRET 0004H
CARGUMENT 46H 0002H 0024H "input" 04H 03H 00H 00H 00H
CARGUMENT 44H 0002H 0029H "key" 04H 03H 00H 00H 00H
CARGUMENT 42H 0002H 0004H "output" 04H 03H 00H 00H 00H

;;  BlockCopy(output, input);
CLINEA 0000H 0001H 0202H 0003H 001BH
	mov	er2,	er0
	l	er0,	_output$4[fp]
	bl	_BlockCopy

;;  state = (state_t*)output;
CLINEA 0000H 0001H 0203H 0003H 001BH
	l	er0,	_output$4[fp]
	st	er0,	NEAR _state

;;  Key = key;
CLINEA 0000H 0001H 0206H 0003H 000CH
	st	er10,	NEAR _Key

;;  KeyExpansion();
CLINEA 0000H 0001H 0207H 0003H 0011H
	bl	_KeyExpansion

;;  InvCipher();
CLINEA 0000H 0001H 0209H 0003H 000EH
	bl	_InvCipher
CBLOCKEND 67 2 522

;;}
CLINEA 0000H 0001H 020AH 0001H 0001H
	pop	er10
	mov	sp,	fp
	pop	fp
	pop	pc
CBLOCKEND 67 1 522
CFUNCTIONEND 67


	rseg $$XorWithIv$aes
CFUNCTION 90

_XorWithIv	:
CBLOCK 90 1 535

;;{
CLINEA 0000H 0001H 0217H 0001H 0001H
;;*****************************************
;;	register/stack information
;;*****************************************
;;*****************************************

	push	xr4
	push	er8
	mov	er8,	er0
CBLOCK 90 2 535
CARGUMENT 46H 0002H 0028H "buf" 04H 03H 00H 00H 00H
CLOCAL 46H 0001H 001AH 0002H "i" 02H 00H 00H

;;  for(i = 0; i < KEYLEN; ++i)
CLINEA 0000H 0001H 0219H 0003H 001DH
	mov	r6,	#00h	;; _li$0
_$L114 :
CBLOCK 90 3 538

;;    buf[i] ^= Iv[i];
CLINEA 0000H 0001H 021BH 0005H 0014H
	mov	r0,	r6
	mov	r1,	#00h
	mov	er2,	er0
	add	er2,	er8
	l	er4,	NEAR _Iv
	add	er4,	er0
	l	r0,	[er2]
	l	r1,	[er4]
	xor	r0,	r1
	st	r0,	[er2]
CBLOCKEND 90 3 540

;;  for(i = 0; i < KEYLEN; ++i)
CLINEA 0000H 0000H 0219H 0003H 001DH
	add	r6,	#01h

;;  for(i = 0; i < KEYLEN; ++i)
CLINEA 0000H 0000H 0219H 000DH 0010H
	cmp	r6,	#010h
	blt	_$L114
CBLOCKEND 90 2 541

;;}
CLINEA 0000H 0001H 021DH 0001H 0001H
	pop	er8
	pop	xr4
	rt
CBLOCKEND 90 1 541
CFUNCTIONEND 90


	rseg $$AES128_CBC_encrypt_buffer$aes
CFUNCTION 68

_AES128_CBC_encrypt_buffer	:
CBLOCK 68 1 546

;;{
CLINEA 0000H 0001H 0222H 0001H 0001H
;;*****************************************
;;	register/stack information
;;*****************************************
	_length$4	set	4
	_remainders$2	set	-2
	_key$8	set	8
	_iv$10	set	10
	_i$0	set	-1
;;*****************************************

	push	lr
	push	fp
	mov	fp,	sp
	add	sp,	#-02
	push	xr8
	push	xr4
	push	bp
	mov	er10,	er2
	mov	er8,	er0
CBLOCK 68 2 546
CRET 000EH
CARGUMENT 46H 0002H 0028H "output" 04H 03H 00H 00H 00H
CARGUMENT 46H 0002H 0029H "input" 04H 03H 00H 00H 00H
CARGUMENT 42H 0004H 0004H "length" 02H 00H 02H
CARGUMENT 40H 0002H 0008H "key" 04H 03H 00H 00H 00H
CARGUMENT 42H 0002H 000AH "iv" 04H 03H 00H 00H 00H
CLOCAL 42H 0001H 0001H 0002H "i" 02H 00H 00H
CLOCAL 42H 0001H 0002H 0002H "remainders" 02H 00H 00H

;;  uint8_t remainders = length % KEYLEN; /* Remaining bytes in the last non-full block */
CLINEA 0000H 0001H 0224H 0003H 0058H
	l	er0,	_length$4[fp]
	and	r0,	#0fh
	mov	r12,	r0

;;  BlockCopy(output, input);
CLINEA 0000H 0001H 0226H 0003H 001BH
	mov	er0,	er8
	bl	_BlockCopy

;;  state = (state_t*)output;
CLINEA 0000H 0001H 0227H 0003H 001BH
	st	er8,	NEAR _state

;;  if(0 != key)
CLINEA 0000H 0001H 022AH 0003H 000EH
	l	er0,	_key$8[fp]
	beq	_$L119
CBLOCK 68 3 555

;;    Key = key;
CLINEA 0000H 0001H 022CH 0005H 000EH
	st	er0,	NEAR _Key

;;    KeyExpansion();
CLINEA 0000H 0001H 022DH 0005H 0013H
	bl	_KeyExpansion
CBLOCKEND 68 3 558

;;  }
CLINEA 0000H 0000H 022EH 0003H 0003H
_$L119 :

;;  if(iv != 0)
CLINEA 0000H 0001H 0230H 0003H 000DH
	l	er0,	_iv$10[fp]
	beq	_$L121
CBLOCK 68 4 561

;;    Iv = (uint8_t*)iv;
CLINEA 0000H 0001H 0232H 0005H 0016H
	st	er0,	NEAR _Iv
CBLOCKEND 68 4 563

;;  }
CLINEA 0000H 0000H 0233H 0003H 0003H
_$L121 :

;;  for(i = 0; i < length; i += KEYLEN)
CLINEA 0000H 0001H 0235H 0007H 000CH
	mov	r0,	#00h

;;  for(i = 0; i < length; i += KEYLEN)
CLINEA 0000H 0000H 0235H 000EH 0018H
	bal	_$L128

;;  for(i = 0; i < length; i += KEYLEN)
CLINEA 0000H 0000H 0235H 001AH 0024H
_$L125 :
CBLOCK 68 5 566

;;    XorWithIv(input);
CLINEA 0000H 0001H 0237H 0005H 0015H
	mov	er0,	er10
	bl	_XorWithIv

;;    BlockCopy(output, input);
CLINEA 0000H 0001H 0238H 0005H 001DH
	mov	er2,	er10
	mov	er0,	er8
	bl	_BlockCopy

;;    state = (state_t*)output;
CLINEA 0000H 0001H 0239H 0005H 001DH
	st	er8,	NEAR _state

;;    Cipher();
CLINEA 0000H 0001H 023AH 0005H 000DH
	bl	_Cipher

;;    Iv = output;
CLINEA 0000H 0001H 023BH 0005H 0010H
	st	er8,	NEAR _Iv

;;    input += KEYLEN;
CLINEA 0000H 0001H 023CH 0005H 0014H
	add	er10,	#16

;;    output += KEYLEN;
CLINEA 0000H 0001H 023DH 0005H 0015H
	add	er8,	#16
CBLOCKEND 68 5 574

;;  for(i = 0; i < length; i += KEYLEN)
CLINEA 0000H 0000H 0235H 001AH 0024H
	l	r0,	_i$0[fp]
	add	r0,	#010h

;;  for(i = 0; i < length; i += KEYLEN)
CLINEA 0000H 0000H 0235H 000EH 0018H
_$L128 :
	st	r0,	_i$0[fp]
	mov	r1,	#00h
	mov	er2,	#0 
	l	er4,	_length$4[fp]
	l	er6,	_length$4+02h[fp]
	cmp	er0,	er4
	cmpc	r2,	r6
	cmpc	r3,	r7
	blt	_$L125

;;  if(remainders)
CLINEA 0000H 0001H 0240H 0003H 0010H
	mov	r0,	r12
	beq	_$L129
CBLOCK 68 6 577

;;    BlockCopy(output, input);
CLINEA 0000H 0001H 0242H 0005H 001DH
	mov	er2,	er10
	mov	er0,	er8
	bl	_BlockCopy

;;    memset(output + remainders, 0, KEYLEN - remainders); /* add 0-padding */
CLINEA 0000H 0001H 0243H 0005H 004CH
	mov	r4,	r12
	mov	r5,	#00h
	mov	er0,	#16
	sub	r0,	r4
	subc	r1,	r5
	push	er0
	mov	er2,	#0 
	add	er4,	er8
	mov	er0,	er4
	bl	_memset_n
	add	sp,	#2 

;;    state = (state_t*)output;
CLINEA 0000H 0001H 0244H 0005H 001DH
	st	er8,	NEAR _state

;;    Cipher();
CLINEA 0000H 0001H 0245H 0005H 000DH
	bl	_Cipher
CBLOCKEND 68 6 582

;;  }
CLINEA 0000H 0000H 0246H 0003H 0003H
_$L129 :
CBLOCKEND 68 2 583

;;}
CLINEA 0000H 0001H 0247H 0001H 0001H
	pop	bp
	pop	xr4
	pop	xr8
	mov	sp,	fp
	pop	fp
	pop	pc
CBLOCKEND 68 1 583
CFUNCTIONEND 68


	rseg $$AES128_CBC_decrypt_buffer$aes
CFUNCTION 69

_AES128_CBC_decrypt_buffer	:
CBLOCK 69 1 587

;;{
CLINEA 0000H 0001H 024BH 0001H 0001H
;;*****************************************
;;	register/stack information
;;*****************************************
	_length$4	set	4
	_remainders$2	set	-2
	_key$8	set	8
	_iv$10	set	10
	_i$0	set	-1
;;*****************************************

	push	lr
	push	fp
	mov	fp,	sp
	add	sp,	#-02
	push	xr8
	push	xr4
	push	bp
	mov	er10,	er2
	mov	er8,	er0
CBLOCK 69 2 587
CRET 000EH
CARGUMENT 46H 0002H 0028H "output" 04H 03H 00H 00H 00H
CARGUMENT 46H 0002H 0029H "input" 04H 03H 00H 00H 00H
CARGUMENT 42H 0004H 0004H "length" 02H 00H 02H
CARGUMENT 40H 0002H 0008H "key" 04H 03H 00H 00H 00H
CARGUMENT 42H 0002H 000AH "iv" 04H 03H 00H 00H 00H
CLOCAL 42H 0001H 0001H 0002H "i" 02H 00H 00H
CLOCAL 42H 0001H 0002H 0002H "remainders" 02H 00H 00H

;;  uint8_t remainders = length % KEYLEN; /* Remaining bytes in the last non-full block */
CLINEA 0000H 0001H 024DH 0003H 0058H
	l	er0,	_length$4[fp]
	and	r0,	#0fh
	mov	r12,	r0

;;  BlockCopy(output, input);
CLINEA 0000H 0001H 024FH 0003H 001BH
	mov	er0,	er8
	bl	_BlockCopy

;;  state = (state_t*)output;
CLINEA 0000H 0001H 0250H 0003H 001BH
	st	er8,	NEAR _state

;;  if(0 != key)
CLINEA 0000H 0001H 0253H 0003H 000EH
	l	er0,	_key$8[fp]
	beq	_$L132
CBLOCK 69 3 596

;;    Key = key;
CLINEA 0000H 0001H 0255H 0005H 000EH
	st	er0,	NEAR _Key

;;    KeyExpansion();
CLINEA 0000H 0001H 0256H 0005H 0013H
	bl	_KeyExpansion
CBLOCKEND 69 3 599

;;  }
CLINEA 0000H 0000H 0257H 0003H 0003H
_$L132 :

;;  if(iv != 0)
CLINEA 0000H 0001H 025AH 0003H 000DH
	l	er0,	_iv$10[fp]
	beq	_$L134
CBLOCK 69 4 603

;;    Iv = (uint8_t*)iv;
CLINEA 0000H 0001H 025CH 0005H 0016H
	st	er0,	NEAR _Iv
CBLOCKEND 69 4 605

;;  }
CLINEA 0000H 0000H 025DH 0003H 0003H
_$L134 :

;;  for(i = 0; i < length; i += KEYLEN)
CLINEA 0000H 0001H 025FH 0007H 000CH
	mov	r0,	#00h

;;  for(i = 0; i < length; i += KEYLEN)
CLINEA 0000H 0000H 025FH 000EH 0018H
	bal	_$L141

;;  for(i = 0; i < length; i += KEYLEN)
CLINEA 0000H 0000H 025FH 001AH 0024H
_$L138 :
CBLOCK 69 5 608

;;    BlockCopy(output, input);
CLINEA 0000H 0001H 0261H 0005H 001DH
	mov	er2,	er10
	mov	er0,	er8
	bl	_BlockCopy

;;    state = (state_t*)output;
CLINEA 0000H 0001H 0262H 0005H 001DH
	st	er8,	NEAR _state

;;    InvCipher();
CLINEA 0000H 0001H 0263H 0005H 0010H
	bl	_InvCipher

;;    XorWithIv(output);
CLINEA 0000H 0001H 0264H 0005H 0016H
	mov	er0,	er8
	bl	_XorWithIv

;;    Iv = input;
CLINEA 0000H 0001H 0265H 0005H 000FH
	st	er10,	NEAR _Iv

;;    input += KEYLEN;
CLINEA 0000H 0001H 0266H 0005H 0014H
	add	er10,	#16

;;    output += KEYLEN;
CLINEA 0000H 0001H 0267H 0005H 0015H
	add	er8,	#16
CBLOCKEND 69 5 616

;;  for(i = 0; i < length; i += KEYLEN)
CLINEA 0000H 0000H 025FH 001AH 0024H
	l	r0,	_i$0[fp]
	add	r0,	#010h

;;  for(i = 0; i < length; i += KEYLEN)
CLINEA 0000H 0000H 025FH 000EH 0018H
_$L141 :
	st	r0,	_i$0[fp]
	mov	r1,	#00h
	mov	er2,	#0 
	l	er4,	_length$4[fp]
	l	er6,	_length$4+02h[fp]
	cmp	er0,	er4
	cmpc	r2,	r6
	cmpc	r3,	r7
	blt	_$L138

;;  if(remainders)
CLINEA 0000H 0001H 026AH 0003H 0010H
	mov	r0,	r12
	beq	_$L142
CBLOCK 69 6 619

;;    BlockCopy(output, input);
CLINEA 0000H 0001H 026CH 0005H 001DH
	mov	er2,	er10
	mov	er0,	er8
	bl	_BlockCopy

;;    memset(output+remainders, 0, KEYLEN - remainders); /* add 0-padding */
CLINEA 0000H 0001H 026DH 0005H 004AH
	mov	r4,	r12
	mov	r5,	#00h
	mov	er0,	#16
	sub	r0,	r4
	subc	r1,	r5
	push	er0
	mov	er2,	#0 
	add	er4,	er8
	mov	er0,	er4
	bl	_memset_n
	add	sp,	#2 

;;    state = (state_t*)output;
CLINEA 0000H 0001H 026EH 0005H 001DH
	st	er8,	NEAR _state

;;    InvCipher();
CLINEA 0000H 0001H 026FH 0005H 0010H
	bl	_InvCipher
CBLOCKEND 69 6 624

;;  }
CLINEA 0000H 0000H 0270H 0003H 0003H
_$L142 :
CBLOCKEND 69 2 625

;;}
CLINEA 0000H 0001H 0271H 0001H 0001H
	pop	bp
	pop	xr4
	pop	xr8
	mov	sp,	fp
	pop	fp
	pop	pc
CBLOCKEND 69 1 625
CFUNCTIONEND 69


	rseg $$AES128_CBC_encrypt$aes
CFUNCTION 70

_AES128_CBC_encrypt	:
CBLOCK 70 1 628

;;{
CLINEA 0000H 0001H 0274H 0001H 0001H
;;*****************************************
;;	register/stack information
;;*****************************************
	_index$8	set	8
	_length$4	set	4
	_padLen$0	set	-1
;;*****************************************

	push	lr
	push	fp
	mov	fp,	sp
	add	sp,	#-02
	push	xr8
	push	xr4
	push	bp
	mov	er10,	er2
	mov	er8,	er0
CBLOCK 70 2 628
CRET 000EH
CARGUMENT 46H 0002H 0028H "output" 04H 03H 00H 00H 00H
CARGUMENT 46H 0002H 0029H "input" 04H 03H 00H 00H 00H
CARGUMENT 42H 0004H 0004H "length" 02H 00H 02H
CARGUMENT 42H 0001H 0008H "index" 02H 00H 00H
CLOCAL 42H 0001H 0001H 0002H "padLen" 02H 00H 00H
CLOCAL 46H 0001H 001AH 0002H "i" 02H 00H 00H

;;    for(i=0; i < 16; i++) {
CLINEA 0000H 0001H 0279H 0005H 001BH
	mov	r0,	#00h
_$L147 :
CBLOCK 70 3 633

;;        *(ivTable+i) = *(p_key+i) ^ index;
CLINEA 0000H 0001H 027AH 0009H 002AH
	mov	r1,	#00h
	mov	er2,	er0
	l	er4,	NEAR _p_key
	add	er2,	er4
	l	r2,	[er2]
	l	r3,	_index$8[fp]
	xor	r2,	r3
	st	r2,	NEAR _ivTable[er0]
CBLOCKEND 70 3 635

;;    for(i=0; i < 16; i++) {
CLINEA 0000H 0000H 0279H 0005H 001BH
	add	r0,	#01h

;;    for(i=0; i < 16; i++) {
CLINEA 0000H 0000H 0279H 000EH 0018H
	cmp	r0,	#010h
	blt	_$L147

;;    memcpy(workspace, input, length);
CLINEA 0000H 0001H 027DH 0005H 0025H
	l	er0,	_length$4[fp]
	push	er0
	mov	er2,	er10
	mov	r0,	#BYTE1 OFFSET _workspace
	mov	r1,	#BYTE2 OFFSET _workspace
	bl	_memcpy_nn
	add	sp,	#2 

;;    padLen = (~(length % 16) + 1)&0x0f;
CLINEA 0000H 0001H 027FH 0005H 0027H
	l	er0,	_length$4[fp]
	and	r0,	#0fh
	and	r1,	#00h
	xor	r0,	#0ffh
	xor	r1,	#0ffh
	add	er0,	#1 
	and	r0,	#0fh
	st	r0,	_padLen$0[fp]

;;    if(!padLen){
CLINEA 0000H 0000H 0281H 0005H 0010H
	cmp	r0,	#00h
	bne	_$L151
CBLOCK 70 4 641

;;        padLen = 16;
CLINEA 0000H 0001H 0282H 0009H 0014H
	mov	r0,	#010h
	st	r0,	_padLen$0[fp]
CBLOCKEND 70 4 643

;;    }
CLINEA 0000H 0000H 0283H 0005H 0005H
_$L151 :

;;    for(i=0; i < padLen; i++){
CLINEA 0000H 0001H 0285H 0009H 000CH
	mov	r6,	#00h	;; _li$2

;;    for(i=0; i < padLen; i++){
CLINEA 0000H 0000H 0285H 000EH 0018H
	bal	_$L160

;;    for(i=0; i < padLen; i++){
CLINEA 0000H 0000H 0285H 001AH 001CH
_$L157 :
CBLOCK 70 5 645

;;       *(workspace + length + i) = PAD;
CLINEA 0000H 0001H 0286H 0008H 0027H
	l	bp,	_length$4[fp]
	mov	r1,	#00h
	add	bp,	er0
	mov	r0,	#00h
	st	r0,	NEAR _workspace[bp]
CBLOCKEND 70 5 647

;;    for(i=0; i < padLen; i++){
CLINEA 0000H 0000H 0285H 001AH 001CH
	add	r6,	#01h

;;    for(i=0; i < padLen; i++){
CLINEA 0000H 0000H 0285H 000EH 0018H
_$L160 :
	mov	r0,	r6
	l	r1,	_padLen$0[fp]
	cmp	r6,	r1
	blt	_$L157

;;    *(workspace + length + i - 1) = padLen;
CLINEA 0000H 0001H 0289H 0005H 002BH
	l	bp,	_length$4[fp]
	mov	r1,	#00h
	add	bp,	er0
	l	r0,	_padLen$0[fp]
	st	r0,	NEAR _workspace-01h[bp]

;;    AES128_CBC_encrypt_buffer(output, workspace, length+padLen, p_key, (uint8_t *)&ivTable);
CLINEA 0000H 0001H 028CH 0005H 005CH
	mov	r0,	#BYTE1 OFFSET _ivTable
	mov	r1,	#BYTE2 OFFSET _ivTable
	push	er0
	l	er0,	NEAR _p_key
	push	er0
	l	r0,	_padLen$0[fp]
	mov	r1,	#00h
	mov	er2,	#0 
	l	er4,	_length$4[fp]
	l	er6,	_length$4+02h[fp]
	add	er0,	er4
	addc	r2,	r6
	addc	r3,	r7
	push	xr0
	mov	r2,	#BYTE1 OFFSET _workspace
	mov	r3,	#BYTE2 OFFSET _workspace
	mov	er0,	er8
	bl	_AES128_CBC_encrypt_buffer
	add	sp,	#8 

;;    return padLen;
CLINEA 0000H 0001H 028EH 0005H 0012H
	l	r0,	_padLen$0[fp]
CBLOCKEND 70 2 655

;;}
CLINEA 0000H 0000H 028FH 0001H 0001H
	pop	bp
	pop	xr4
	pop	xr8
	mov	sp,	fp
	pop	fp
	pop	pc
CBLOCKEND 70 1 655
CFUNCTIONEND 70


	rseg $$AES128_CBC_decrypt$aes
CFUNCTION 71

_AES128_CBC_decrypt	:
CBLOCK 71 1 658

;;{
CLINEA 0000H 0001H 0292H 0001H 0001H
;;*****************************************
;;	register/stack information
;;*****************************************
	_index$8	set	8
	_length$4	set	4
;;*****************************************

	push	lr
	push	fp
	mov	fp,	sp
	push	xr8
	push	er4
	mov	er10,	er2
	mov	er8,	er0
CBLOCK 71 2 658
CRET 0008H
CARGUMENT 46H 0002H 0028H "output" 04H 03H 00H 00H 00H
CARGUMENT 46H 0002H 0029H "input" 04H 03H 00H 00H 00H
CARGUMENT 42H 0004H 0004H "length" 02H 00H 02H
CARGUMENT 42H 0001H 0008H "index" 02H 00H 00H
CLOCAL 46H 0001H 0018H 0002H "padLen" 02H 00H 00H
CLOCAL 46H 0001H 001AH 0002H "i" 02H 00H 00H

;;    for(i=0; i < 16; i++) {
CLINEA 0000H 0001H 0297H 0005H 001BH
	mov	r0,	#00h
_$L164 :
CBLOCK 71 3 663

;;        *(ivTable+i) = *(p_key+i) ^ index;
CLINEA 0000H 0001H 0298H 0009H 002AH
	mov	r1,	#00h
	mov	er2,	er0
	l	er4,	NEAR _p_key
	add	er2,	er4
	l	r2,	[er2]
	l	r3,	_index$8[fp]
	xor	r2,	r3
	st	r2,	NEAR _ivTable[er0]
CBLOCKEND 71 3 665

;;    for(i=0; i < 16; i++) {
CLINEA 0000H 0000H 0297H 0005H 001BH
	add	r0,	#01h

;;    for(i=0; i < 16; i++) {
CLINEA 0000H 0000H 0297H 000EH 0018H
	cmp	r0,	#010h
	blt	_$L164

;;    AES128_CBC_decrypt_buffer(workspace, input, length, p_key, (uint8_t *)&ivTable);
CLINEA 0000H 0001H 029BH 0005H 0054H
	mov	r0,	#BYTE1 OFFSET _ivTable
	mov	r1,	#BYTE2 OFFSET _ivTable
	push	er0
	l	er0,	NEAR _p_key
	push	er0
	l	er0,	_length$4[fp]
	l	er2,	_length$4+02h[fp]
	push	xr0
	mov	er2,	er10
	mov	r0,	#BYTE1 OFFSET _workspace
	mov	r1,	#BYTE2 OFFSET _workspace
	bl	_AES128_CBC_decrypt_buffer
	add	sp,	#8 

;;    padLen = *(workspace + length - 1);
CLINEA 0000H 0001H 029CH 0005H 0027H
	l	er0,	_length$4[fp]
	l	r2,	NEAR _workspace-01h[er0]
	mov	r4,	r2	;; _lpadLen$0

;;    if(padLen > 16) padLen = 16;
CLINEA 0000H 0001H 029EH 0005H 0020H
	cmp	r2,	#010h
	ble	_$L168
	mov	r4,	#010h	;; _lpadLen$0
_$L168 :

;;    memcpy(output, workspace, length-padLen);
CLINEA 0000H 0001H 029FH 0005H 002DH
	mov	r0,	r4
	mov	r1,	#00h
	mov	er2,	er0
	l	er0,	_length$4[fp]
	sub	r0,	r2
	subc	r1,	r3
	push	er0
	mov	r2,	#BYTE1 OFFSET _workspace
	mov	r3,	#BYTE2 OFFSET _workspace
	mov	er0,	er8
	bl	_memcpy_nn
	add	sp,	#2 

;;    return padLen;
CLINEA 0000H 0001H 02A1H 0005H 0012H
	mov	r0,	r4
CBLOCKEND 71 2 674

;;}
CLINEA 0000H 0000H 02A2H 0001H 0001H
	pop	er4
	pop	xr8
	mov	sp,	fp
	pop	fp
	pop	pc
CBLOCKEND 71 1 674
CFUNCTIONEND 71


	rseg $$AES128_setKey$aes
CFUNCTION 72

_AES128_setKey	:
CBLOCK 72 1 677

;;{
CLINEA 0000H 0001H 02A5H 0001H 0001H
;;*****************************************
;;	register/stack information
;;*****************************************
;;*****************************************

CBLOCK 72 2 677
CARGUMENT 46H 0002H 0024H "key" 04H 03H 00H 00H 00H

;;    p_key = key;
CLINEA 0000H 0001H 02A6H 0005H 0010H
	st	er0,	NEAR _p_key

;;    if (p_key == NULL) secEn = 0;
CLINEA 0000H 0001H 02A8H 0005H 0021H
	mov	er0,	er0
	bne	_$L171
	mov	r0,	#00h
	st	r0,	NEAR _secEn

;;    else secEn = 1;
CLINEA 0000H 0001H 02A9H 0005H 0013H
	rt
_$L171 :
	mov	r0,	#01h
	st	r0,	NEAR _secEn
CBLOCKEND 72 2 682

;;}
CLINEA 0000H 0001H 02AAH 0001H 0001H
	rt
CBLOCKEND 72 1 682
CFUNCTIONEND 72


	rseg $$AES128_getStatus$aes
CFUNCTION 73

_AES128_getStatus	:
CBLOCK 73 1 685

;;{
CLINEA 0000H 0001H 02ADH 0001H 0001H
;;*****************************************
;;	register/stack information
;;*****************************************
;;*****************************************

CBLOCK 73 2 685

;;    return secEn;
CLINEA 0000H 0001H 02AEH 0005H 0011H
	l	r0,	NEAR _secEn
CBLOCKEND 73 2 687

;;}
CLINEA 0000H 0000H 02AFH 0001H 0001H
	rt
CBLOCKEND 73 1 687
CFUNCTIONEND 73

	public _AES128_CBC_decrypt_buffer
	public _AES128_CBC_encrypt_buffer
	public _AES128_CBC_decrypt
	public _AES128_ECB_encrypt
	public _AES128_getStatus
	public _AES128_CBC_encrypt
	public _AES128_setKey
	public _AES128_ECB_decrypt
	extrn code near : _memcpy_nn
	extrn code near : _memset_n
	extrn code near : _main

	rseg $$TABsbox$aes
_sbox :
	db	063h
	db	07ch
	db	077h
	db	07bh
	db	0f2h
	db	06bh
	db	06fh
	db	0c5h
	db	030h
	db	01h
	db	067h
	db	02bh
	db	0feh
	db	0d7h
	db	0abh
	db	076h
	db	0cah
	db	082h
	db	0c9h
	db	07dh
	db	0fah
	db	059h
	db	047h
	db	0f0h
	db	0adh
	db	0d4h
	db	0a2h
	db	0afh
	db	09ch
	db	0a4h
	db	072h
	db	0c0h
	db	0b7h
	db	0fdh
	db	093h
	db	026h
	db	036h
	db	03fh
	db	0f7h
	db	0cch
	db	034h
	db	0a5h
	db	0e5h
	db	0f1h
	db	071h
	db	0d8h
	db	031h
	db	015h
	db	04h
	db	0c7h
	db	023h
	db	0c3h
	db	018h
	db	096h
	db	05h
	db	09ah
	db	07h
	db	012h
	db	080h
	db	0e2h
	db	0ebh
	db	027h
	db	0b2h
	db	075h
	db	09h
	db	083h
	db	02ch
	db	01ah
	db	01bh
	db	06eh
	db	05ah
	db	0a0h
	db	052h
	db	03bh
	db	0d6h
	db	0b3h
	db	029h
	db	0e3h
	db	02fh
	db	084h
	db	053h
	db	0d1h
	db	00h
	db	0edh
	db	020h
	db	0fch
	db	0b1h
	db	05bh
	db	06ah
	db	0cbh
	db	0beh
	db	039h
	db	04ah
	db	04ch
	db	058h
	db	0cfh
	db	0d0h
	db	0efh
	db	0aah
	db	0fbh
	db	043h
	db	04dh
	db	033h
	db	085h
	db	045h
	db	0f9h
	db	02h
	db	07fh
	db	050h
	db	03ch
	db	09fh
	db	0a8h
	db	051h
	db	0a3h
	db	040h
	db	08fh
	db	092h
	db	09dh
	db	038h
	db	0f5h
	db	0bch
	db	0b6h
	db	0dah
	db	021h
	db	010h
	db	0ffh
	db	0f3h
	db	0d2h
	db	0cdh
	db	0ch
	db	013h
	db	0ech
	db	05fh
	db	097h
	db	044h
	db	017h
	db	0c4h
	db	0a7h
	db	07eh
	db	03dh
	db	064h
	db	05dh
	db	019h
	db	073h
	db	060h
	db	081h
	db	04fh
	db	0dch
	db	022h
	db	02ah
	db	090h
	db	088h
	db	046h
	db	0eeh
	db	0b8h
	db	014h
	db	0deh
	db	05eh
	db	0bh
	db	0dbh
	db	0e0h
	db	032h
	db	03ah
	db	0ah
	db	049h
	db	06h
	db	024h
	db	05ch
	db	0c2h
	db	0d3h
	db	0ach
	db	062h
	db	091h
	db	095h
	db	0e4h
	db	079h
	db	0e7h
	db	0c8h
	db	037h
	db	06dh
	db	08dh
	db	0d5h
	db	04eh
	db	0a9h
	db	06ch
	db	056h
	db	0f4h
	db	0eah
	db	065h
	db	07ah
	db	0aeh
	db	08h
	db	0bah
	db	078h
	db	025h
	db	02eh
	db	01ch
	db	0a6h
	db	0b4h
	db	0c6h
	db	0e8h
	db	0ddh
	db	074h
	db	01fh
	db	04bh
	db	0bdh
	db	08bh
	db	08ah
	db	070h
	db	03eh
	db	0b5h
	db	066h
	db	048h
	db	03h
	db	0f6h
	db	0eh
	db	061h
	db	035h
	db	057h
	db	0b9h
	db	086h
	db	0c1h
	db	01dh
	db	09eh
	db	0e1h
	db	0f8h
	db	098h
	db	011h
	db	069h
	db	0d9h
	db	08eh
	db	094h
	db	09bh
	db	01eh
	db	087h
	db	0e9h
	db	0ceh
	db	055h
	db	028h
	db	0dfh
	db	08ch
	db	0a1h
	db	089h
	db	0dh
	db	0bfh
	db	0e6h
	db	042h
	db	068h
	db	041h
	db	099h
	db	02dh
	db	0fh
	db	0b0h
	db	054h
	db	0bbh
	db	016h

	rseg $$TABrsbox$aes
_rsbox :
	db	052h
	db	09h
	db	06ah
	db	0d5h
	db	030h
	db	036h
	db	0a5h
	db	038h
	db	0bfh
	db	040h
	db	0a3h
	db	09eh
	db	081h
	db	0f3h
	db	0d7h
	db	0fbh
	db	07ch
	db	0e3h
	db	039h
	db	082h
	db	09bh
	db	02fh
	db	0ffh
	db	087h
	db	034h
	db	08eh
	db	043h
	db	044h
	db	0c4h
	db	0deh
	db	0e9h
	db	0cbh
	db	054h
	db	07bh
	db	094h
	db	032h
	db	0a6h
	db	0c2h
	db	023h
	db	03dh
	db	0eeh
	db	04ch
	db	095h
	db	0bh
	db	042h
	db	0fah
	db	0c3h
	db	04eh
	db	08h
	db	02eh
	db	0a1h
	db	066h
	db	028h
	db	0d9h
	db	024h
	db	0b2h
	db	076h
	db	05bh
	db	0a2h
	db	049h
	db	06dh
	db	08bh
	db	0d1h
	db	025h
	db	072h
	db	0f8h
	db	0f6h
	db	064h
	db	086h
	db	068h
	db	098h
	db	016h
	db	0d4h
	db	0a4h
	db	05ch
	db	0cch
	db	05dh
	db	065h
	db	0b6h
	db	092h
	db	06ch
	db	070h
	db	048h
	db	050h
	db	0fdh
	db	0edh
	db	0b9h
	db	0dah
	db	05eh
	db	015h
	db	046h
	db	057h
	db	0a7h
	db	08dh
	db	09dh
	db	084h
	db	090h
	db	0d8h
	db	0abh
	db	00h
	db	08ch
	db	0bch
	db	0d3h
	db	0ah
	db	0f7h
	db	0e4h
	db	058h
	db	05h
	db	0b8h
	db	0b3h
	db	045h
	db	06h
	db	0d0h
	db	02ch
	db	01eh
	db	08fh
	db	0cah
	db	03fh
	db	0fh
	db	02h
	db	0c1h
	db	0afh
	db	0bdh
	db	03h
	db	01h
	db	013h
	db	08ah
	db	06bh
	db	03ah
	db	091h
	db	011h
	db	041h
	db	04fh
	db	067h
	db	0dch
	db	0eah
	db	097h
	db	0f2h
	db	0cfh
	db	0ceh
	db	0f0h
	db	0b4h
	db	0e6h
	db	073h
	db	096h
	db	0ach
	db	074h
	db	022h
	db	0e7h
	db	0adh
	db	035h
	db	085h
	db	0e2h
	db	0f9h
	db	037h
	db	0e8h
	db	01ch
	db	075h
	db	0dfh
	db	06eh
	db	047h
	db	0f1h
	db	01ah
	db	071h
	db	01dh
	db	029h
	db	0c5h
	db	089h
	db	06fh
	db	0b7h
	db	062h
	db	0eh
	db	0aah
	db	018h
	db	0beh
	db	01bh
	db	0fch
	db	056h
	db	03eh
	db	04bh
	db	0c6h
	db	0d2h
	db	079h
	db	020h
	db	09ah
	db	0dbh
	db	0c0h
	db	0feh
	db	078h
	db	0cdh
	db	05ah
	db	0f4h
	db	01fh
	db	0ddh
	db	0a8h
	db	033h
	db	088h
	db	07h
	db	0c7h
	db	031h
	db	0b1h
	db	012h
	db	010h
	db	059h
	db	027h
	db	080h
	db	0ech
	db	05fh
	db	060h
	db	051h
	db	07fh
	db	0a9h
	db	019h
	db	0b5h
	db	04ah
	db	0dh
	db	02dh
	db	0e5h
	db	07ah
	db	09fh
	db	093h
	db	0c9h
	db	09ch
	db	0efh
	db	0a0h
	db	0e0h
	db	03bh
	db	04dh
	db	0aeh
	db	02ah
	db	0f5h
	db	0b0h
	db	0c8h
	db	0ebh
	db	0bbh
	db	03ch
	db	083h
	db	053h
	db	099h
	db	061h
	db	017h
	db	02bh
	db	04h
	db	07eh
	db	0bah
	db	077h
	db	0d6h
	db	026h
	db	0e1h
	db	069h
	db	014h
	db	063h
	db	055h
	db	021h
	db	0ch
	db	07dh

	rseg $$TABRcon$aes
_Rcon :
	db	08dh
	db	01h
	db	02h
	db	04h
	db	08h
	db	010h
	db	020h
	db	040h
	db	080h
	db	01bh
	db	036h
	db	06ch
	db	0d8h
	db	0abh
	db	04dh
	db	09ah
	db	02fh
	db	05eh
	db	0bch
	db	063h
	db	0c6h
	db	097h
	db	035h
	db	06ah
	db	0d4h
	db	0b3h
	db	07dh
	db	0fah
	db	0efh
	db	0c5h
	db	091h
	db	039h
	db	072h
	db	0e4h
	db	0d3h
	db	0bdh
	db	061h
	db	0c2h
	db	09fh
	db	025h
	db	04ah
	db	094h
	db	033h
	db	066h
	db	0cch
	db	083h
	db	01dh
	db	03ah
	db	074h
	db	0e8h
	db	0cbh
	db	08dh
	db	01h
	db	02h
	db	04h
	db	08h
	db	010h
	db	020h
	db	040h
	db	080h
	db	01bh
	db	036h
	db	06ch
	db	0d8h
	db	0abh
	db	04dh
	db	09ah
	db	02fh
	db	05eh
	db	0bch
	db	063h
	db	0c6h
	db	097h
	db	035h
	db	06ah
	db	0d4h
	db	0b3h
	db	07dh
	db	0fah
	db	0efh
	db	0c5h
	db	091h
	db	039h
	db	072h
	db	0e4h
	db	0d3h
	db	0bdh
	db	061h
	db	0c2h
	db	09fh
	db	025h
	db	04ah
	db	094h
	db	033h
	db	066h
	db	0cch
	db	083h
	db	01dh
	db	03ah
	db	074h
	db	0e8h
	db	0cbh
	db	08dh
	db	01h
	db	02h
	db	04h
	db	08h
	db	010h
	db	020h
	db	040h
	db	080h
	db	01bh
	db	036h
	db	06ch
	db	0d8h
	db	0abh
	db	04dh
	db	09ah
	db	02fh
	db	05eh
	db	0bch
	db	063h
	db	0c6h
	db	097h
	db	035h
	db	06ah
	db	0d4h
	db	0b3h
	db	07dh
	db	0fah
	db	0efh
	db	0c5h
	db	091h
	db	039h
	db	072h
	db	0e4h
	db	0d3h
	db	0bdh
	db	061h
	db	0c2h
	db	09fh
	db	025h
	db	04ah
	db	094h
	db	033h
	db	066h
	db	0cch
	db	083h
	db	01dh
	db	03ah
	db	074h
	db	0e8h
	db	0cbh
	db	08dh
	db	01h
	db	02h
	db	04h
	db	08h
	db	010h
	db	020h
	db	040h
	db	080h
	db	01bh
	db	036h
	db	06ch
	db	0d8h
	db	0abh
	db	04dh
	db	09ah
	db	02fh
	db	05eh
	db	0bch
	db	063h
	db	0c6h
	db	097h
	db	035h
	db	06ah
	db	0d4h
	db	0b3h
	db	07dh
	db	0fah
	db	0efh
	db	0c5h
	db	091h
	db	039h
	db	072h
	db	0e4h
	db	0d3h
	db	0bdh
	db	061h
	db	0c2h
	db	09fh
	db	025h
	db	04ah
	db	094h
	db	033h
	db	066h
	db	0cch
	db	083h
	db	01dh
	db	03ah
	db	074h
	db	0e8h
	db	0cbh
	db	08dh
	db	01h
	db	02h
	db	04h
	db	08h
	db	010h
	db	020h
	db	040h
	db	080h
	db	01bh
	db	036h
	db	06ch
	db	0d8h
	db	0abh
	db	04dh
	db	09ah
	db	02fh
	db	05eh
	db	0bch
	db	063h
	db	0c6h
	db	097h
	db	035h
	db	06ah
	db	0d4h
	db	0b3h
	db	07dh
	db	0fah
	db	0efh
	db	0c5h
	db	091h
	db	039h
	db	072h
	db	0e4h
	db	0d3h
	db	0bdh
	db	061h
	db	0c2h
	db	09fh
	db	025h
	db	04ah
	db	094h
	db	033h
	db	066h
	db	0cch
	db	083h
	db	01dh
	db	03ah
	db	074h
	db	0e8h
	db	0cbh

	rseg $$NVARaes
_state :
	ds	02h
_p_key :
	ds	02h
_RoundKey :
	ds	0b0h
_Iv :
	ds	02h
_workspace :
	ds	0100h
_secEn :
	ds	01h
	align
_ivTable :
	ds	010h
_Key :
	ds	02h

	end
