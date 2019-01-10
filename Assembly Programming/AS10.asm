;Roll NO: SEB205
;Name: Nikhil Lakare
;Asg No: 10
;Asg Name: Calculation of roots of Quadratic Equation
;---------------------------------------------------------------------

extern printf

;---------------------------------------------------------------------

%include "macro.asm"

;------------------------------------------------------------------------------------
section		.data

	
	ano		db	10,"----------------------------------AS:10---------------------------------",10
			db	10,"----------------------Calculation of roots of Quadratic Equation--------",10		
	ano_len		equ	$ - ano
	
	exmsg		db	10,10,"------------EXITING FROM PROGRAM-------------",10
	exmsg_len	equ	$ - exmsg
	
	a		dq	1
	b		dq	2
	c		dq	1
	
	I4		dq	4
	
	astr		db	10,"Co-efficients of Given Quadratic Equation are a = %e, b = %e, c = %e",10,0
	
	ostr		db	10,"The roots of Quadratic Equation are ",10
			db	10,"Root 1  	= %e",10
			db	10,"Root 2 	= %e",10,0
	
	nline		db	10,10
	
;-------------------------------------------------------------------------------------

section		.bss

	
	delta		resq	1
	root1		resq	1
	root2		resq	1
	
	
;-------------------------------------------------------------------------------------
section		.text

global		main

	main:
		push	rbp
		
		print	ano, ano_len
		
		finit	
		
		mov	rdi, astr
	
		movq	xmm0, [a]
		movq	xmm1, [b]
		movq	xmm2, [c]
		
		mov	rax, 3
		call 	printf
		
;---------------------------------------------------------------------------------------------
;Mean:
		fld	qword[b]
		fmul	qword[b]
		fld	qword[a]
		fmul	qword[c]
		fmul	qword[I4]
		fsub
		fsqrt
		fst	[delta]
		
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
		
		movq	xmm0, [mean]
		movq	xmm1, [var]
		movq	xmm2, [sd]
		
		mov	rax, 3
		call 	printf
		
		print	exmsg, exmsg_len
		
		pop 	rbp
		
	exit	
;---------------------------------------------------------------------------------------;------------------------------------------------
