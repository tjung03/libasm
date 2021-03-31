default	rel
section .text
global	_ft_strlen					; reference symbol globally

; size_t	ft_strlen(char *s);
_ft_strlen:
	xor		rax, rax				; (rax == i) i = 0;
	jmp		cmp_null				; goto compare null(0)
inc_rax:
	inc		rax						; i++;
cmp_null:
	cmp		BYTE [rdi + rax], 0
	jne		inc_rax					; Jump if not equal (cmp == 0 ? jmp : next)
get:
	ret								; return (i);
	