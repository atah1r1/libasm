segment.text:
	global _ft_strcmp

_ft_strcmp:
	xor 	rax, rax							; define rax to 0
	jmp		_compa								; call compa

_compa:
	mov		al, BYTE [rdi]						; get the least significant byte in rdi where is stock the value of the char
	mov		bl, BYTE [rsi]						; get the least significant byte in rsi where is stock the value of the char
	cmp		al, 0								; if we are not at the end of rdi (arg0)
	je		_exit								; jump to _exit
	cmp		bl, 0								; if we are not at the end of rsi (arg1)
	je		_exit								; jump to _exit
	cmp 	al, bl								; compare al and bl
	jne 	_exit								; if the result of cmp is diferrent than 0 so the string are differents
	inc 	rdi									; increment the rdi pointer
	inc 	rsi									; increment the rsi pointer
	jmp 	_compa								; if we are here it's because the chars of string are equals the we can continue

_exit:					
	movzx	rax, al								; (zero extend) movzx = copy a register of inferior size in a bigger and fill the other bits with 0, and this register is rax
    movzx	rbx, bl								; same that previous but set it in rbx
    sub		rax, rbx							; stock the difference of rax and rbx in rax; Finaly : do the difference beetween the char at the rdi pointer and the char at the rsi pointer 
	ret											; return (rax)