;Roll NO: SEB205
;Name: Nikhil Lakare
;Asg No: 2C
;Asg Name: Overlapping Block Tranfer without string specific instruction
;------------------------------------------------------------

;Macro Definations

%macro	print	2
	mov	rax, 1			;print
	mov	rdi, 1			;stdout
	mov	rsi, %1
	mov 	rdx, %2
	syscall
%endmacro

%macro	exit	0
	mov	rax, 60			;exit
	mov	rdi, 0			;0
	syscall
%endmacro

;-------------------------------------------------------------

section	.data

	space		db	" "

	nline		db	10,10

	ano		db	10,"-------------Asg:2A-----------",10
			db	10,"Non Overlapping Block Transfer"	

	ano_len		equ	$ - ano 

	bmsg		db	10,10,"Block Before Transfer",10
	bmsg_len	equ	$ - bmsg

	srcmsg		db	10,"	Source Block		: "
	srcmsg_len	equ	$ - srcmsg

	dstmsg		db	10,"	Destination Block	: "
	dstmsg_len	equ	$ - dstmsg

	amsg		db	10,10,"Block After Transfer: ",10
	amsg_len	equ	$ - amsg

	sblock		db	10H, 20H, 30H, 40H, 50H

	dblock		db	0H, 0H, 0H, 0H, 0H

	count		equ	5		

;----------------------------------------------------------------

section	.bss

	char_ans	resb	16

;----------------------------------------------------------------
section	.text

global	_start

	_start:

		print	ano, ano_len
		

		print	bmsg, bmsg_len
	
		print	srcmsg, srcmsg_len

		mov	rsi, sblock	

		call 	block_display

		print	dstmsg, dstmsg_len

		mov	rsi, dblock-2	

		call 	block_display

	
		call	BT_NO


		print 	amsg, amsg_len

		print	srcmsg, srcmsg_len

		mov	rsi, sblock	

		call 	block_display

		print	dstmsg, dstmsg_len

		mov	rsi, dblock-2	

		call 	block_display

		print 	nline, 2
	
exit
;--------------------------------------------------------------------

display_16:

	mov 	rsi, char_ans+1
	mov	rcx, 2
	mov	rbx, 16

back1:	mov	rdx, 0
	div	rbx
	cmp	dl, 09H
	
	jbe	add30

	add	dl, 07H

add30:	add 	dl, 30H
	mov 	[rsi], DL
	
	dec 	rsi
	dec 	rcx
	
	jnz	back1 
	
	print	char_ans, 2

ret

;------------------------------------------------------------------------

block_display:

	mov	rbp, 5
	
	next_num:
	mov	al, [rsi]
	push	rsi

	call 	display_16
	print	space, 1

	pop	rsi
	inc	rsi
	dec	rbp
	
	jnz	next_num

ret

;------------------------------------------------------------------------

BT_NO:	
	mov	rcx, count
	mov	rsi, sblock+4	
	mov	rdi, dblock+2

	STD
	
	REP MOVSB	

ret
;-------------------------------------------------------------------------
