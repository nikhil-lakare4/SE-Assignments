;Roll NO: SEB205
;Name: Nikhil Lakare
;Asg No: 6
;Asg Name: Display the content of system address registers
;---------------------------------------------------------------------

global	buf, abuf_len, char
extern	FAR_PROC

;------------------------------------------------------------------------------------
section		.data


	exitline		db 	10,"Exiting From Program............................",10,10
	exitline_len	equ	$ - exitline

	ano		db	10,"--------------------AS:5------------------------",10
			db	10,"----------File Opening & File Closing-----------",10		
	ano_len		equ	$ - ano
	
	fmsg		db	10,"Enter the file name: "
	fmsg_len		equ	$ - fmsg
	
	charmsg		db	10,"Enter the character to be searched: "
	charmsg_len	equ	$ - charmsg
	
	
	
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
	char		resb	2
	
;-------------------------------------------------------------------------------------------

%include "macro.asm"

;------------------------------------------------------------------------------------


section	.text

global	_start

   _start:

	print	ano, ano_len
	
	print 	fmsg, fmsg_len
	read	fname, 50
	dec	rax
	mov	byte[fname+rax], 0
	
	print	charmsg, charmsg_len
	read	char, 2

	fopen	fname
	cmp	rax, -1
	je	ferror
	mov	[fhandle], rax
	print	omsg, omsg_len

	fread	[fhandle], buf, buf_len
	mov 	[abuf_len], rax
	
	call 	FAR_PROC
	
	fclose	[fhandle]
	
	print 	cmsg, cmsg_len
	
	print	exitline, exitline_len
	
exit	

ferror:	print	errmsg, errmsg_len
	print	exitline, exitline_len
	
exit

;--------------------------------------------------------------------------------------------
