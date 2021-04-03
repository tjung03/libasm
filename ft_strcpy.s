default	rel
section	.text
global	_ft_strcpy					; reference symbol globally

; char	*ft_strcpy(char *dst, char *src);
_ft_strcpy:							; dst = rdi, src = rsi
	xor		rcx, rcx				; (rcx == i) i = 0;
	xor		rdx, rdx				; (rdx == temp) temp = 0;
	cmp		rsi, 0					; rsi == NULL ? 1 : 0
	jz		get						; (jz == je) jump if zero - (ZF == 1 ? jmp : next)
	jmp		cpy_src
inc_rcx:
	inc		rcx						; i++;
cpy_src:
	mov		dl, BYTE [rsi + rcx]	; (1) rdx(64) edx(32) dx(16) dh(8) dl(8)
	mov		BYTE [rdi + rcx], dl	; (2) to match the units of 1 byte
	cmp		BYTE [rsi + rcx], 0		; (*src == '\0') ? 1(ZF) : 0(ZF)
	jnz		inc_rcx					; jump if not zero - (ZF == 0 ? jmp : next)
get:
	mov		rax, rdi				; rax = dst;
	ret								; return (rax);
