default	rel
section	.text
global	_ft_strcmp								; reference symbol globally

; int		ft_strcmp(char *s1, char *s2);
_ft_strcmp:
	xor		rcx, rcx							; (rcx == i) i = 0;
	xor		rax, rax							; s1_tmp = 0;
	xor		rdx, rdx							; s2_tmp = 0;
	jmp		compare
increase:
	cmp		al, 0								; s1[i] == '\0' ?
	jz		equal
	inc		rcx									; i++;
compare:
	mov		al, BYTE [rdi + rcx]				; al = s1[i];
	mov		dl, BYTE [rsi + rcx]				; dl = s2[i];
	cmp		al, dl								; if (s1[i] == s2[i])
	jz		increase							; 0 ? goto increase
	jnz		different							; !0 ? goto different
equal:
	mov		rax, 0								; return (0);
	ret
different:
	sub		rax, rdx							; return (s1[i] - s2[i]);
	ret
