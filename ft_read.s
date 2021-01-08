section.text:
	global _ft_read
    extern  ___error

_ft_read:
	mov rax, 0x2000003 ; 0x2000000 (MacOS ?)+ 0x4 (write syscall)
	syscall ; 64 bits version of int 0x80
        jc _exit_error
	ret
_exit_error:
    push rax    ;save errno
	call ___error   ;rax is now points to external variable errno.
	pop qword[rax]  ;The QWORD PTR is just a size specifier (It means that a 64 bit value is read from the address)
    mov rax, -1
    ret