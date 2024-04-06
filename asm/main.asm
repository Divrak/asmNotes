.code
	drawLine proc
		; extern "C" void drawLine(CHAR_INFO *screenBuffer, Spos pos, int len, CHAR_INFO symbol);
		; RCX - screenBuffer
		; RDX - pos
		; R8 - len
		; R9 - symbol
		; ret RAX

		push rax
		push rcx
		push rdi

		;ֲûגמהטל סטלגמכû
		mov rdi, rcx
		mov eax, r9d
		mov rcx, r8

		rep	stosd

		pop rdi
		pop rcx
		pop rax

		ret	
	drawLine endp
end