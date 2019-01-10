;Roll NO: SEB205
;Name: Nikhil Lakare
;Asg No: 9
;Asg Name: Calculation Of Factorial 
;---------------------------------------------------------------------

%include "macro.asm"

;------------------------------------------------------------------------------------
section		.data

	
	ano		db	10,"---------------------AS:9--------------------",10
			db	10,"----------Calculation Of Factorial-----------",10		
	ano_len		equ	$ - ano
	
	nmsg		db	10,"ENTER THE NUMBER TO CALCULATE IT'S FACTORIAL: 	"
	nmsg_len		equ	$ - nmsg
	
	fmsg		db	10,"FACTORIAL OF NUMBER IS:			"
	fmsg_len		equ	$ - fmsg
	
	ermsg		db	10,"ERROR! RETRY!"
	ermsg_len	equ	$ - ermsg
	
	exmsg		db	10,10,"------------EXITING FROM PROGRAM-------------",10
	exmsg_len	equ	$ - exmsg
	
	nline		db	10,10
	
;-------------------------------------------------------------------------------------

section		.bss

	
	buf	resb	3
	n	resq	1
	char_ans	resb	16
	ans	resq	1
	
;-------------------------------------------------------------------------------------
section		.text

global		_start

	_start:
	
		print	ano, ano_len
		
		print 	nmsg, nmsg_len
		
		call 	ACCEPT_2
		
		call 	FACT
		
		print 	fmsg, fmsg_len
		
		mov	rax, [ans]
		
		call	display_16
		
		print	exmsg, exmsg_len
		
		exit
		
	ERROR:	print 	ermsg, ermsg_len
		
;---------------------------------------------------------------------------------------;-------------------------------------------------------------------------------

display_16:

	mov 	rsi, char_ans+15
	mov	rcx, 16
	mov	rbx, 10

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
	
	print	char_ans, 16

ret	

;-------------------------------------------------------------------------------

ACCEPT_2:

	read	buf, 3
	
	mov 	rcx, 2
	mov	rsi, buf
	xor	rax, rax
	xor	rbx, rbx
	
back3:	 SHL	rbx, 2
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

FACT:
	
	push 	rbx
	cmp 	rbx, 1
	jbe	final
	
	dec	rbx
	call 	FACT
	
final:	cmp 	qword[ans], 0
	jne	next
	mov	qword[ans], 1
	
next:	pop	rax
	cmp	rax, 0
	je	next1
	mul	qword[ans]
	mov	[ans], rax
	
next1:

RET
;-------------------------------------------------------------------------------
