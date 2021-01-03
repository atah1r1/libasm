section.text:
    global  _ft_strcmp

_ft_strcmp:
		push	r10
		mov		r10, 0				; i = -1

_loop:
		mov		al, byte [rdi+r10]	; al = str1[i]
		mov		bl, byte [rsi+r10]	; bl = str2[i]
        inc		r10					; i++
		cmp		al, 0				; if al == 0
		je		_end				; then zero
		cmp		bl, 0				; if bl == 0
		je		_end				; then zero
		cmp		al, bl				; if al == bl
    	je		_loop				; then loop
		jmp		_end

_end:
	pop		r10
	sub		rax, rbx
	ret