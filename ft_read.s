default	rel
section	.text
global	_ft_read
extern	___error

; ssize_t		ft_read(int fildes, void *buf, size_t nbyte);
_ft_read:
	mov		rax, 0x2000003			; unique num of syscall was stored in rax
	syscall							; call read()
	jc		_err					; error ? goto _err
	ret
_err:
	push	rax						; stored error values in stack
	call	___error				; rax = error address
	pop		rdx						; rdx = error values (from stack)
	mov		[rax], rdx				; [rax] = error values (only rax values, No change address)
	mov		rax, -1;				; rax = -1;
	ret

