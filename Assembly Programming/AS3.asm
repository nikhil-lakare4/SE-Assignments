;Roll NO: SEB205
;Name: Nikhil Lakare
;Asg No: 3
;Asg Name: Conversion of HEX to BCD and BCD to HEX
;---------------------------------------------------------------------

;Macro Definations

%macro print 2

	mov 	rax, 1
	mov	rdi, 1
	mov	rsi, %1
	mov	rdx, %2
	syscall
	
%endmacro

%macro read 	2

	mov 	rax, 0			;read function	
	mov	rdi, 0			;from keyboard
	mov	rsi, %1		;buffer
	mov	rdx, %2		;buffer max length
	syscall
	
%endmacro

%macro	exit 	0
	
	mov 	rax, 60
	mov	rdi, 0
	
	syscall
	
%endmacro

;------------------------------------------------------------------------------------

section		.data

	
	ano		db	10,"--------------------AS:3----------------------",10
			db	10,"----------HEX TO BCD AND BCD TO HEX-----------",10		
	ano_len	equ	$ - ano
		
	menu		db	10,"-------------------MENU-----------------------",10
			db	10,"1. HEX TO BCD"
			db	10,"2. BCD TO HEX"
			db	10,"3. EXIT"
			db	10,"ENTER YOUR CHOICE: "	
	menu_len	equ	$ - menu
	
	hmsg		db	10,"ENTER THE HEX NO: 		"
	hmsg_len	equ	$ - hmsg
	
	ebmsg		db	10,"EQUIVALENT BCD NO IS:	"
	ebmsg_len		equ	$ - ebmsg
	
	bmsg		db	10,"ENTER THE BCD NO:		"
	bmsg_len	equ	$ - bmsg
	
	ehmsg		db	10,"EQUIVALENT HEX NO IS:	"
	ehmsg_len	equ	$ - ehmsg
	
	ermsg		db	10,"ERROR! RETRY!"
	ermsg_len	equ	$ - ermsg
	
	exmsg		db	10,"------------EXITING FROM PROGRAM-------------",10
	exmsg_len	equ	$ - exmsg
	
	nline		db	10,10
	
	
;-------------------------------------------------------------------------------------

section		.bss

	
	buf		resb	6
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
		
		call	HEXtoBCD
		
		jmp	MENU
		
	C2:	cmp	al, '2'
		jne	C3
		
		call	BCDtoHEX
		
		jmp	MENU
		
	C3:	cmp 	al, '3'
		jne	ERROR1
		
		print	exmsg, exmsg_len
		
		exit
		
	ERROR1:print 	ermsg, ermsg_len
		jmp	MENU
;---------------------------------------------------------------------------------------

display_4:

	mov 	rsi, char_ans+3
	mov	rcx, 4
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
	
	print	char_ans, 4

ret	

;-------------------------------------------------------------------------------
HEXtoBCD:

	print	hmsg, hmsg_len
	
	call	ACCEPT_4
	
	mov	rax, rbx
	
	call 	display_4
	
	print	ebmsg, ebmsg_len
	
	
	
	
	
	print	nline, 2
	

ret	
;-------------------------------------------------------------------------------
BCDtoHEX:

	print	bmsg, bmsg_len
	
	read	buf, 6
	mov	rbp, 5
	mov	rsi, buf
	xor	rcx, rcx
	xor	rax, rax
	mov	rbx, 10
	
back2:	mul	rbx
	mov	cl, [rsi]
	sub	cl, 30h
	add	rax, rcx
	inc	rsi
	dec	rbp
	jnz	back2
	
	mov 	rbp, rax
	
	print	ehmsg, ehmsg_len
	mov	rax, rbp
	call	display_4
	print 	nline, 2

ret	
;-------------------------------------------------------------------------------	

ACCEPT_4:

	read	buf, 5
	
	mov 	rcx, 4
	mov	rsi, buf
	xor	rax, rax
	xor	rbx, rbx
	
back3: SHL	rbx, 4
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
	
ERROR2: print	ermsg, ermsg_len
	exit
	
SUB57:	sub	al, 20h
SUB37:	sub	al, 07h
SUB30: sub	al, 30h

	add 	rbx, rax
	inc	rsi
	dec	rcx
	jnz	back3
	
ret

;----------------------------------------------------------------------------
	

		
