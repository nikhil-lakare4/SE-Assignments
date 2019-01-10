;Roll NO: SEB205
;Name: Nikhil Lakare
;Asg No: 9
;Asg Name: Calculation Of Factorial 


;---------------------------------------------------------------------

extern printf

;---------------------------------------------------------------------

%include "macro.asm"

;------------------------------------------------------------------------------------
section		.data

	
	ano		db	10,"----------------------------------AS:11---------------------------------",10
			db	10,"----------Calculation Of Mean, Variance & Std Deviation Using MCP--------",10		
	ano_len		equ	$ - ano
	
	;nmsg		db	10,"ENTER THE NUMBER TO CALCULATE IT'S FACTORIAL: 	"
	;nmsg_len		equ	$ - nmsg
	
	;fmsg		db	10,"FACTORIAL OF NUMBER IS:			"
	;fmsg_len		equ	$ - fmsg
	
	;ermsg		db	10,"ERROR! RETRY!"
	;ermsg_len	equ	$ - ermsg
	
	exmsg		db	10,10,"------------EXITING FROM PROGRAM-------------",10
	exmsg_len	equ	$ - exmsg
	
	array 		dq	11.11, 22.22, 33.33, 44.44, 55.55
	
	count		db	5
	
	astr		db	10,"Array Elements are ",10,"%e, %e, %e, %e, %e",10,0
	
	ostr		db	10,"The Results are ",10
			db	10,"Mean 		= %e",10
			db	10,"Variance 		= %e",10
			db	10,"Standard Deviation 	= %e",10,0
	
	nline		db	10,10
	
;-------------------------------------------------------------------------------------

section		.bss

	
	mean		resq	1
	var		resq	1
	sd		resq	1
	
	
;-------------------------------------------------------------------------------------
section		.text

global		main

	main:
		push	rbp
		
		print	ano, ano_len	
		
		mov	rdi, astr
		mov	rax, 5
		
		movq	xmm0, [array]
		movq	xmm1, [array+8]
		movq	xmm2, [array+16]
		movq	xmm3, [array+24]
		movq	xmm4, [array+32]
		
		call 	printf
		
		finit
		
;---------------------------------------------------------------------------------------------
;Mean:
		fldz
		
		mov	rbx, array
		xor	rsi, rsi
		xor	rcx, rcx
		mov	cx, [count]
		
	back1:	fadd	qword[rbx+(rsi*8)]
	
		inc	rsi
		
		loop	back1
		
		fidiv	word[count]
		
		fstp	qword[mean]
;----------------------------------------------------------------------------------------------
;Variance:
		fldz
		
		mov	rbx, array
		xor	rsi, rsi
		xor	rcx, rcx
		mov	cx, [count]
		
	back2:	fld	qword[rbx+(rsi*8)]
		fsub	qword[mean]
		fmul	st0
		fadd
		
		inc	rsi
		
		loop	back2
		
		fidiv	word[count]
		
		fst	qword[var]
;-------------------------------------------------------------------------------------------------
;Standard Deviation:

		fsqrt
		
		fstp 	qword[sd]
		
;------------------------------------------------------------------------------------------------

		mov	rdi, ostr
		mov	rax, 3
		
		movq	xmm0, [mean]
		movq	xmm1, [var]
		movq	xmm2, [sd]
		
		call 	printf
		
		print	exmsg, exmsg_len
		
		pop 	rbp
		
	exit
	
		
;---------------------------------------------------------------------------------------;-------------------------------------------------------------------------------
