	.file	"test3.c"
	.text
	.align 2
.globl main
	.type	main,@function
main:
.LFB2:
	pushl	%ebp
.LCFI0:
	movl	%esp, %ebp
.LCFI1:
	subl	$24, %esp
.LCFI2:
	andl	$-16, %esp
	movl	$0, %eax
	subl	%eax, %esp
	movl	$197, -4(%ebp)
	movl	-4(%ebp), %eax
	addl	$8, %eax
	movl	%eax, -8(%ebp)
	movl	-8(%ebp), %eax
	subl	$4, %eax
	movl	%eax, -12(%ebp)
	movl	-8(%ebp), %eax
	leave
	ret
.LFE2:
.Lfe1:
	.size	main,.Lfe1-main
	.section	.note.GNU-stack,"",@progbits
	.ident	"GCC: (GNU) 3.2.3 20030502 (Red Hat Linux 3.2.3-49)"
