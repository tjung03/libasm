default	rel
section	.text
global	_ft_strdup
extern	_malloc


; char		*ft_strdup(char *s1);
_ft_strdup:
	xor		rcx, rcx				; size = 0;
	push	rdi						; stored s1 in stack
	jmp		get_size
inc_size:
	inc		rcx						; size++;
get_size:							; _ft_strlen
	cmp		BYTE [rdi + rcx], 0
	jnz		inc_size
malloc_new:
	inc		rcx						; include '\0'
	mov		rdi, rcx				; rdi(malloc size) = size + 1;
	call	_malloc	
	cmp		rax, 0					; malloc failed
	jz		end
copy_s1_to_new:						; _ft_strcpy
	pop		rdi						; upload s1 from stack
	xor		rcx, rcx				; i = 0;
	xor		rdx, rdx
	jmp		copy
inc_idx:
	inc		rcx						; i++;
copy:
	mov		dl, BYTE [rdi + rcx]
	mov		BYTE [rax + rcx], dl
	cmp		BYTE [rdi + rcx], 0
	jnz		inc_idx
end:								; return (new string);
	ret
