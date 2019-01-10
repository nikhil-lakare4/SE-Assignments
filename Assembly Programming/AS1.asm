;Roll NO: SEB205
;Name: Nikhil Lakare
;Asg No: 1
;Asg Name: To display hello world using macro
;------------------------------------------------------------

;Macro Definations

%macro	print	2
	mov	RAX, 1			;print
	mov	RDI, 1			;stdout
	mov	RSI, %1
	mov 	RDX, %2
	syscall
%endmacro

%macro	exit	0
	mov	RAX, 60			;exit
	mov	RDI, 0			;0
	syscall
%endmacro

;-------------------------------------------------------------

section	.data

	nline		DB	10,10
`
	hmsg		DB	" H"

	ano		DB	10,"----------------Asg:1-----------------",10
			DB	"Count number of +ve & -ve nos in Array",10,10	
	ano_len		EQU	$ - ano 

	pmsg		DB	"Count of +ve nos is : "
	pmsg_len	EQU	$ - pmsg

	nmsg		DB	10,"Count of -ve nos is : "
	nmsg_len	EQU	$ - nmsg

	Array64		DQ	11H, -22H, -33H, 44H, 55H

	count		EQU	5		

;-------------------------------------------------------------

section	.bss

	pcount	resQ	1

	ncount	resQ	1 

	char_ans	resB	16
;----------------------------------------------------------------
section	.text

global	_start

	_start:

	mov	RCX, count
	mov	RSI, Array64
	mov 	RBX, 0		;+ve
	mov	RDX, 0		;-ve

back:	mov	RAX, [RSI]
	SHL 	RAX, 1		;CF = MSB
	JC	negative	

	inc 	RBX
	JMP	next


negative:	inc RDX
next:		add RSI, 8
		dec RCX
		JNZ back

		mov	[pcount], RBX
		mov	[ncount], RDX		

	print	ano, ano_len

	print	pmsg, pmsg_len
	mov 	RAX, [pcount]
	call 	display_16

	print	nmsg, nmsg_len
	mov 	RAX, [ncount]
	call 	display_16

	print 	nline, 2
	
	exit

display_16:

	mov 	RSI, char_ans+2
	mov	RCX, 16
	mov	RBX, 16

back1:	mov	RDX, 0
	DIV	RBX
	CMP	DL, 09H
	JBE	add30

	ADD	DL, 07H

add30:	ADD 	DL, 30H
	mov 	[RSI], DL
	dec 	RSI
	dec 	RCX
	JNZ	back1 
	
	print	char_ans, 16
	print	hmsg, 2

ret
