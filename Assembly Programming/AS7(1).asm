;Roll NO: SEB205
;Name: Nikhil Lakare
;Asg No: 7
;Asg Name: Bubble Sort
;---------------------------------------------------------------------

global	buf, abuf_len, char
extern	FAR_PROC

;------------------------------------------------------------------------------------
section		.data


	exitline		db 	10,"Exiting From Program............................",10,10
	exitline_len	equ	$ - exitline

	ano		db	10,"--------------------AS:7------------------------",10
			db	10,"---------Sorting Array With Bubble Sort---------",10		
	ano_len		equ	$ - ano
	
	fmsg		db	10,"Enter the file name: "
	fmsg_len		equ	$ - fmsg
	
	bufmsg		db	10,"BUFF_ARRAY IS: "
	bufmsg_len	equ	$ - bufmsg
	
	omsg		db	10,"File Opened Successfully!",10
	omsg_len		equ	$ - omsg
	
	cmsg		db	10,10,"File Closed Successfully!",10
	cmsg_len		equ	$ - cmsg

	;fname		db	"hello.txt",0
	
	errmsg		db	10,"Error in opening the file! ",10
	errmsg_len	equ	$ - errmsg
	
	
;-----------------------------------------------------------------------------------------

section 	.bss

	fname		resb	50
	abuf_len		resq	1
	fhandle		resq	1
	buf		resb	500	
	buf_len		equ	$ - buf
	buff_array	resb	50
	char_ans		resb	2
	
;-------------------------------------------------------------------------------------------

%include "macro.asm"

;------------------------------------------------------------------------------------


section	.text

global	_start

   _start:

	print	ano, ano_len
	
	print 	fmsg, fmsg_len
	read	fname, 50
	dec	rax			;remove last enter character 
	mov	byte[fname+rax], 0

	fopen	fname
	cmp	rax, -1
	js	ferror
	mov	[fhandle], rax
	print	omsg, omsg_len

	fread	[fhandle], buf, buf_len
	mov 	[abuf_len], rax
	dec	rax			;exclude eof
	
	call 	BUFF_ARRAY
	
	print	bufmsg, bufmsg_len
	print	buff_array, rbp
	
	fclose	[fhandle]
	
	print 	cmsg, cmsg_len
	
	print	exitline, exitline_len
	
exit	

ferror:	print	errmsg, errmsg_len
	print	exitline, exitline_len
	
exit
;--------------------------------------------------------------------------------------------
BUFF_ARRAY:

	mov	rsi, buf
	mov	rdi, buff_array
	mov	rcx, rax
	xor	rbp, rbp
	
back:	mov	al, [rsi]
	mov	[rdi], al
	inc	rbp
	inc	rsi
	inc	rsi
	inc	rdi
	dec	rcx
	dec	rcx
	jnz	back
	
ret

;--------------------------------------------------------------------

BUBBLE_SORT:



ret
	


