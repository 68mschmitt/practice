	.file	"helloworld.c"
	.text
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC0:
	.string	"Hello, World!"
	.text
	.globl	main
	.type	main, @function
main:
	subq	$8, %rsp
	leaq	.LC0(%rip), %rdi
	call	puts@PLT
	addq	$8, %rsp
	ret
	.size	main, .-main
	.ident	"GCC: (GNU) 14.2.1 20250207"
	.section	.note.GNU-stack,"",@progbits
