section.text:
	global _ft_write
	extern  ___error

; ft_write (rdi, rsi, rdx)
_ft_write:
	mov r10, rdx				; save rdx = len in r8
	mov rax, 0x2000004		; set call to write
    syscall					; call rax (write)
		jc _exit_error		; if doesn't work, write set flags carry to 1 so jmp exit error
	jmp _exit				; jump exit

_exit_error:
	push rax				;save errono
	call ___error
	pop qword[rax]
	mov rax, -1				; set return to -1
	ret						; return

_exit:
	mov rax, r10			; set previous value of rdx save in r8, in return value
	ret						; return 