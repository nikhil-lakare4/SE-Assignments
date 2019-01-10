;Rollno. : SEB212
;Name : NIKHIL
;Asg No. : 7
;Assignment name : Bubble Sort
;------------------------------------------------------------------------------------------------------------------


;------------------------------------------------------------------------------------------------------------------


%include "macro.asm"

;------------------------------------------------------------------------------------------------------------------
section .data

	nline	db	10,10

	ano	db	"-------------------Assignment : 7-----------------------",10,10
		
	ano_len	equ	$-ano
	
	fmsg		db	10,"Enter name of file : "
	fmsg_len	equ	$-fmsg
	
	errmsg		db	10,"Error in opening file ..:(",10
	errmsg_len	equ	$-errmsg
	
	armsg		db	10,"ARRAY 		:  "
	armsg_len	equ	$-armsg
	
	flmsg		db	10,"CONTENT  OF FILE ",10
	flmsg_len	equ	$-flmsg
	
	smsg		db	10,"SORTED ARRAY 	:  "
	smsg_len		equ 	$-smsg

	
	
	
;------------------------------------------------------------------------------------------------------------------


section	.bss

	
	fhandle		resQ	1
	abuf_len		resQ	1
	fname		resb	30
	buf		resb	50
	buf_len		equ	$-buf	

	arr		RESB	50		;array 



;------------------------------------------------------------------------------------------------------------------



section .text

global _start

_start:

	Print	ano,ano_len

	Print	fmsg,fmsg_len		
	Read	fname,50			;rea
	dec	RAX			;enter to 0
	mov	byte[fname+rax],0


	fopen	fname			;for opening file
	cmp	RAX,-1
	JS	ferror
	mov	[fhandle],rax
	
	fread	[fhandle],buf,buf_len
	dec 	rax				;eof
	mov	[abuf_len],RAX
	
	Print	flmsg,flmsg_len
	Print	buf,[abuf_len]
	CALL	BUF_ARRAY
	
	Print	armsg,armsg_len
	Print	arr,rbp
	
	fwrite	[fhandle],smsg,smsg_len		;to write smsg in file
	
	CALL	bsort
	
	inc	RBP
	
	fwrite	[fhandle],arr,rbp			;to write sorted array in file
	
	Print	smsg,smsg_len
	Print	arr,rbp	
	
	fclose	[fhandle]
	Print	nline,1
	Print	nline,1

Exit

ferror:	Print	errmsg,errmsg_len

Exit
	
	
	
;------------------------------------------------------------------------------------------------------------------

BUF_ARRAY:

	mov	RDI,arr			;starting address of arr array to rdi
	mov	RSI,buf			;content of file from buf to RSI(starting address)
	mov	RCX,[abuf_len]
	xor	RBP,RBP			;RBP for total numbers in array and used to print array (length)

back0:	mov	al,[RSI]			;byte by byte
	mov	[RDI],al
	inc	RBP
		
	inc 	RSI
	inc	RSI
	
	inc	RDI

	
	dec 	RCX
	dec	RCX
	
	JNZ	back0
	
RET

;------------------------------------------------------------------------------------------------------------------

bsort:
	dec	RBP
	xor	RCX,RCX

	
oloop:
	
	xor	RBX,RBX
	mov	RSI,arr
	
iloop:
	mov	RDI,RSI
	inc	RDI
	
	mov	al,[RSI]
	cmp	al,[RDI]
	jbe	nextpass
	
	mov	ah,[RDI]
	mov	[RDI],al
	mov	[RSI],ah
	
nextpass:

	inc 	RSI
	inc	RBX
	cmp	RBX,RBP
	jb	iloop
	
	inc	RCX
	cmp	RCX,RBP
	jb	oloop
	
RET
	
	

;------------------------------------------------------------------------------------------------------------------


