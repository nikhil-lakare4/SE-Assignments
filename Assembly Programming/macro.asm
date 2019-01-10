;Macro Definations

;------------------------------------------------------------------------------

%macro 	print 	2

	mov 	rax, 1		;	1 for print fuction
	mov	rdi, 1		;	1 for setting destination as screen
	mov	rsi, %1		;	1st Parameter
	mov	rdx, %2		;	Length
	syscall
	
%endmacro

;-------------------------------------------------------------------------------

%macro 	read 	2

	mov 	rax, 0		;	read function	
	mov	rdi, 0		;	from keyboard
	mov	rsi, %1		;	buffer
	mov	rdx, %2		;	buffer max length
	syscall
	
%endmacro

;--------------------------------------------------------------------------------

%macro	exit 	0
	
	mov 	rax, 60		;	0 for exit function
	mov	rdi, 0		
	
	syscall
	
%endmacro

;--------------------------------------------------------------------------------

%macro	fopen	1

	mov	rax, 2		;	2 for file open
	mov	rdi, %1		;	filename
	mov	rsi, 2		;	2 for read write mode
	mov	rdx, 0777o	;	for all permissions to user
	
	syscall
	
%endmacro
;--------------------------------------------------------------------------------

%macro	fclose	1

	mov	rax, 3		;	3 for close
	mov	rdi, %1		;	filehandle
	
	syscall
	
%endmacro

;--------------------------------------------------------------------------------

%macro	fread	3

	mov	rax, 0		;	read function
	mov	rdi, %1		;	filehandle
	mov	rsi, %2		;	buf
	mov	rdx, %3		;	buf_len
	
	syscall
	
%endmacro

