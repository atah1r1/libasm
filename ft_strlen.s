section.text:
    global _ft_strlen

_ft_strlen:
    xor     rax, rax                                    ; rax is returned value && initialize with zero
    _start_loop:
        cmp BYTE [rdi + rax], 0x00                      ; compare each byte to \0
        jz  _end_loop                                   ; if the compare was true (means jz stores 0) go to end loop
        inc rax                                         ; increment count
        jmp _start_loop                                 ; restart loop
    _end_loop:
    ret