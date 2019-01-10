;Roll NO: SEB205
;Name: Nikhil Lakare
;Asg No: 6
;Asg Name: Display the content of system address registers
;---------------------------------------------------------------------

%include "macro.asm"

;------------------------------------------------------------------------------------
section		.data


	nline		db 	10,10

	ano		db	10,"---------------------------------AS:6-------------------------------",10
			db	10,"----------Display the content of system address registers-----------",10		
	ano_len		equ	$ - ano
	
	rmsg		db	10,"The processor is in Real Mode!",10
	rmsg_len		equ	$ - rmsg
	
	pmsg		db	10,"The processor is in Protected Mode!",10
	pmsg_len		equ	$ - pmsg
	
	gmsg		db	10,"The content of GDTR is	:"
	gmsg_len		equ	$ - gmsg
	
	lmsg		db	10,"The content of LDTR is	:"
	lmsg_len		equ	$ - lmsg
	
	imsg		db	10,"The content of IDTR is	:"
	imsg_len		equ	$ - imsg
	
	tmsg		db	10,"The content of TR is	:"
	tmsg_len		equ	$ - tmsg
	
	mmsg		db	10,"The content of MSW is	:"
	mmsg_len		equ	$ - mmsg
	
	
;-----------------------------------------------------------------------------------------

section 	.bss

	MSW	resW	1
	TR	resW	1
	LDTR	resW	1
	GDTR	resW	3
	IDTR	resW	3
	char_ans	resB	16
	
;-------------------------------------------------------------------------------------------

section	.text

global	_start

   _start:

	print	ano, ano_len
	
	SMSW	bx
	
	BT	bx, 0
	
	JC	pmode
		
	print	rmsg, rmsg_len
	
	JMP	next

    pmode	:	
    	
    	print	pmsg, pmsg_len
    	
    next	:
    
    	SMSW	[MSW]
    	print	mmsg, mmsg_len
    	mov	ax, [MSW]
    	call	display_4
    	
    	SLDT	[LDTR]
    	print	lmsg, lmsg_len
    	mov	ax, [LDTR]
    	call	display_4
    	
    	STR	[TR]
    	print	tmsg, tmsg_len
    	mov	ax, [TR]
    	call	display_4
    	
    	print 	gmsg, gmsg_len
    	
    	mov	ax, [GDTR+4]
	call	display_4
	
	mov	ax, [GDTR+2]
	call	display_4
	
	print 	colon, 1
	
	mov	ax, [GDTR+0]
	call	display_4
	    	
    	
    	print	nline, 2
    exit
    
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
