;Roll NO: SEB205
;Name: Nikhil Lakare
;Asg No: 6
;Asg Name: Display the content of system address registers
;---------------------------------------------------------------------

%include "macro.asm"

;------------------------------------------------------------------------------------
section		.data


	exitline		db 	10,"Exiting From Program............................",10,10
	exitline_len	equ	$ - exitline

	ano		db	10,"--------------------AS:5------------------------",10
			db	10,"----------File Opening & File Closing-----------",10		
	ano_len		equ	$ - ano
	
	omsg		db	10,"File Opened Successfully!",10
	omsg_len		equ	$ - omsg
	
	cmsg		db	10,"File Closed Successfully!",10
	cmsg_len		equ	$ - cmsg
	
	lmsg		db	10,"The content of file is	:"
	lmsg_len		equ	$ - lmsg
	
	fname		db	"hello.txt",0
	
	errmsg		db	10,"Error in opening the file! ",10
	errmsg_len	equ	$ - errmsg
	
	
;-----------------------------------------------------------------------------------------

section 	.bss

	fhandle	resq	1
	buf	resb	500	
	buf_len	equ	$ - buf
	
;-------------------------------------------------------------------------------------------

section	.text

global	_start

   _start:

	print	ano, ano_len

	fopen	fname
	
	cmp	rax, -1
	je	ferror
	
	mov	[fhandle], rax
	
	print	omsg, omsg_len

	fread	[fhandle], buf, buf_len
	
	print	lmsg, lmsg_len
	
	print	buf, buf_len
	
	fclose	[fhandle]
	
	print	exitline, exitline_len
	
exit	

ferror:	print	errmsg, errmsg_len
	print	exitline, exitline_len
	
exit

;--------------------------------------------------------------------------------------------
