default	rel
section	.text
global	_ft_strcmp								; reference symbol globally

; int		ft_strcmp(char *s1, char *s2);
_ft_strcmp:
	xor		rcx, rcx							; (rcx == i) i = 0;
	jmp		cmp_str
inc_rcx:
	inc		rcx									; i++;
cmp_str:
	xor		rax, rax							; (for al) rax = 0;
	mov		al, BYTE [rdi + rcx]				; rax = s1[i];
	sub		al, BYTE [rsi + rcx]				; rax = s1[i] - s2[i];
	cmp		al, 0								; if (s1[i] == s2[i])
	jz		inc_rcx								; ZF == 1 ? jump : next
get:
	ret
