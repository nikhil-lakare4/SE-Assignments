;Roll NO: SEB205
;Name: Nikhil Lakare
;Asg No: 4
;Asg Name: Multiplication of two 16-bit Numbers
;---------------------------------------------------------------------

%include "macro.asm"

;------------------------------------------------------------------------------------
section		.data

	
	ano		db	10,"---------------------------AS:4--------------------------",10
			db	10,"----------Multiplication Of Two 16-bit Numbers-----------",10		
	ano_len		equ	$ - ano
		
	menu		db	10,"-------------------MENU-----------------------",10
			db	10,"1. Successive Addition"
			db	10,"2. Shift and Add"
			db	10,"3. EXIT"
			db	10,"ENTER YOUR CHOICE: "	
	menu_len		equ	$ - menu
	
	n1msg		db	10,"ENTER THE FIRST NUMBER: 	"
	n1msg_len		equ	$ - n1msg
	
	n2msg		db	10,"ENTER THE SECOND NUMBER:	"
	n2msg_len		equ	$ - n2msg
	
	samsg		db	10,"RESULT BY SA METHOD IS:	"
	samsg_len		equ	$ - samsg
	
	shamsg		db	10,"RESULT BY SHA METHOD IS:	"
	shamsg_len	equ	$ - shamsg
	
	ermsg		db	10,"ERROR! RETRY!"
	ermsg_len	equ	$ - ermsg
	
	exmsg		db	10,"------------EXITING FROM PROGRAM-------------",10
	exmsg_len	equ	$ - exmsg
	
	nline		db	10,10
	
;-------------------------------------------------------------------------------------

section		.bss

	
	buf	resb	5
	n1	resw	1
	n2	resw	1
	ansl	resw	1
	ansh	resw	1
	char_ans	resb	16
	
;-------------------------------------------------------------------------------------
section		.text

global		_start

	_start:
	
		print	ano, ano_len
		
	MENU:	print	menu, menu_len
		
		read 	buf, 2
		mov	al, [buf]
		
	C1:	cmp	al, '1'
		jne	C2
		
		call	SA
		
		jmp	MENU
		
	C2:	cmp	al, '2'
		jne	C3
		
		call	SHA
		
		jmp	MENU
		
	C3:	cmp 	al, '3'
		jne	ERROR1
		
		print	exmsg, exmsg_len
		
		exit
		
	ERROR1:	print 	ermsg, ermsg_len
		jmp	MENU
		
;---------------------------------------------------------------------------------------
display_8:

	mov 	rsi, char_ans+7
	mov	rcx, 8
	mov	rbx, 16

back_1:	mov	rdx, 0
	div	rbx
	cmp	dl, 09H
	
	jbe	add30

	add	dl, 07H

add30:	add 	dl, 30H
	mov 	[rsi], DL
	
	dec 	rsi
	dec 	rcx
	
	jnz	back_1 
	
	print	char_ans, 8

ret	
;-------------------------------------------------------------------------------

display_4:

	mov 	rsi, char_ans+3
	mov	rcx, 4
	mov	rbx, 16

back_2:	mov	rdx, 0
	div	rbx
	cmp	dl, 09H
	
	jbe	add30_2

	add	dl, 07H

add30_2:	add 	dl, 30H
	mov 	[rsi], DL
	
	dec 	rsi
	dec 	rcx
	
	jnz	back_2 
	
	print	char_ans, 4

ret	

;-------------------------------------------------------------------------------

ACCEPT_4:

	read	buf, 5
	
	mov 	rcx, 4
	mov	rsi, buf
	xor	rax, rax
	xor	rbx, rbx
	
back3:	 SHL	rbx, 4
	mov	al, [rsi]
	CMP	AL, '0'
	JB	ERROR2
	CMP 	AL, '9'
	JBE	SUB30
	
	CMP	AL, 'A'
	JB	ERROR2
	CMP	Al, 'F'
	JBE	SUB37
	
	CMP	AL, 'a'
	JB	ERROR2
	CMP	AL, 'f'
	JBE	SUB57
	
ERROR2: 	print	ermsg, ermsg_len
	exit
	
SUB57:	sub	al, 20h
SUB37:	sub	al, 07h
SUB30: 	sub	al, 30h

	add 	rbx, rax
	inc	rsi
	dec	rcx
	jnz	back3
	
ret

;-------------------------------------------------------------------------------
SA:
	
	print	n1msg, n1msg_len
	call 	ACCEPT_4
	mov	[n1], bx
	
	print	n2msg, n2msg_len
	call 	ACCEPT_4
	mov	[n2], bx
	
	mov	bp, 0
	mov	[ansl], bp
	mov	[ansh], bp
	
	mov 	cx, [n2]
	mov	ax, [n1]
	
back_SA: add	[ansl], ax
	jnc	next_SA
	
	xor	bp, bp
	mov	bp, 1
	add	[ansh], bp
	
next_SA:	dec 	cx
	jnz	back_SA
	
	print	samsg, samsg_len
	mov	ax, [ansh]
	call	display_4
	mov	ax, [ansl]
	call	display_4
	
ret	
;-------------------------------------------------------------------------------
SHA:

	print 	n1msg, n1msg_len
	call	ACCEPT_4
	mov	[n1], bx
	
	print	n2msg, n2msg_len
	call 	ACCEPT_4
	mov	[n2], bx
	
	xor	ebp, ebp
	xor	ebx, ebx
	
	mov	cx, 16
	mov	ax, [n1]
	mov	bx, [n2]
	
back_SHA: SHL 	ebp, 1
	SHL	ax, 1
	JNC	next_SHA
	add 	ebp, ebx
next_SHA: dec	cx
	jnz	back_SHA
	
	print	shamsg,shamsg_len
	mov	eax, ebp
	call 	display_8
	
	print 	nline, 2
ret	
;-------------------------------------------------------------------------------	


		
