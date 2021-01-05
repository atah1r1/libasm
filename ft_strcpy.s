section.text:
	global _ft_strcpy

_ft_strcpy:
	push rdx ; cpy char (push onto stack)
	push rcx ; count
	mov rdx, 0x0
	mov rcx, 0x0
	cmp rsi, BYTE 0x0
	jz _is_null ; if the comparaison was true move to _is_null label
	_start_loop:
		mov dl, BYTE [rsi + rcx] ; put char pointed by rsi + rcx in dl (dl is rdx 8 bits (1 char - 8 bits))
		mov BYTE [rdi + rcx], dl ; put char in rdi + rcx
		cmp [rsi + rcx], BYTE 0x0 ; compare rsi char to \0
		jz _end_loop ; if compare true then go to flag _end_loop
		inc rcx ; increment the pointer 
		jmp _start_loop ; restart loop
	_end_loop:
	mov rax, rdi ; return dst
	pop rdx
	pop rcx
	ret

_is_null:
	mov rax, rsi
	pop rdx
	pop rcx
	ret