section.text:
	global _ft_write
	extern  ___error

; ft_write (rdi, rsi, rdx)
_ft_write:
	mov rax, 0x2000004		; set call to write
    syscall					; call rax (write)
		jc _exit_error		; if doesn't work, write set flags carry to 1 so jmp exit error
	jmp _exit				; jump exit

_exit_error:
	push rax				;save errno
	call ___error			;rax is now points to external variable errno.
	pop qword[rax]			;The QWORD PTR is just a size specifier (It means that a 64 bit value is read from the address)
	mov rax, -1				; set return to -1
	ret						; return

_exit:
	ret						; return