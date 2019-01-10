;Roll NO: SEB205
;Name: Nikhil Lakare
;Asg No: 2A
;Asg Name: Non Overlapping Block Tranfer
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

	ano		DB	10,"-------------Asg:2A-----------",10
			DB	10,"Non Overlapping Block Transfer",10	
	ano_len		EQU	$ - ano 

	bmsg		DB	10,"Block Before Transfer",10
	bmsg_len	EQU	$ - bmsg

	srcmsg		DB	"	Source Block: ",10
	srcmsg_len	EQU	$ - srcmsg

	dstmsg		DB	"	Destination Block: ",10
	dstmsg_len	EQU	$ - dstmsg

	amsg		DB	10,"Block After Transfer: ",10
	amsg_len	EQU	$ - amsg

	Array64		DQ	11H, -22H, -33H, 44H, 55H

	count		EQU	5		

;-------------------------------------------------------------

section	.bss

	

;----------------------------------------------------------------
section	.text

global	_start

	_start:

	print	ano, ano_len

	print	bmsg, bmsg_len
	
	print	srcmsg, srcmsg_len

	print	dstmsg, dstmsg_len

	print 	amsg, amsg_len

	print 	srcmsg, srcmsg_len

	print	dstmsg, dstmsg_len

	print 	nline, 2
	
	exit

;--------------------------------------------------------------------

