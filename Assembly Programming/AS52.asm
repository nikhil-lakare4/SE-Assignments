;Roll NO: SEB205
;Name: Nikhil Lakare
;Asg No: 6
;Asg Name: Display the content of system address registers
;---------------------------------------------------------------------

global	FAR_PROC
extern	buf, abuf_len, char

;------------------------------------------------------------------------------------
section		.data


	smsg		db	10,"Number of spaces are		: "
	smsg_len		equ	$ - smsg
	
	nmsg		db	10,"Number of New lines are	: "
	nmsg_len		equ	$ - nmsg
	
	cmsg		db	10,"Number of characters are	: "
	cmsg_len		equ	$ - cmsg
	
	lmsg		db	10,"The content of file is	: "
	lmsg_len		equ	$ - lmsg
	
;-----------------------------------------------------------------------------------------

section 	.bss

	scount	resq	1
	ncount	resq	1
	ccount	resq	1
	char_ans	resb	16


;-------------------------------------------------------------------------------------------

%include "macro.asm"

;------------------------------------------------------------------------------------
section	.text

global	abc

   abc:
	
	FAR_PROC:
	
	;print	lmsg, lmsg_len
	
	;print	buf, abuf_len
	
	mov	rsi, buf
	mov	rcx, [abuf_len]
	mov	bl, [char]
	
back:	mov 	al, [rsi]
C1:	cmp	al, ' '
	jne	C2
	inc	qword[scount]
	jmp	next
	
C2:	cmp	al, 10
	jne	C3
	inc	qword[ncount]
	jmp	next

C3:	cmp	al, [char]
	jne	next
	inc	qword[ccount]

next:	inc 	rsi
	dec	rcx
	jnz	back
	
	print	smsg, smsg_len
	mov	rax, [scount]
	call 	display_4
	
	print	nmsg, nmsg_len
	mov	rax, [ncount]
	call 	display_4
	
	print	cmsg, cmsg_len
	mov	rax, [ccount]
	call 	display_4
	
	ret

;--------------------------------------------------------------------------------------------

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

;------------------------------------------------------------------------------------------------
