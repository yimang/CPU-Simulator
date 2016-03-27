	.file	"test6.c"
	.text
.globl foo
	.type	foo,@function
_foo:
	pushl	%ebp
	movl	%esp, %ebp
	movl	12(%ebp), %edx
	movl	8(%ebp), %eax
	subl	%edx, %eax
	leave
	ret
.Lfe1:
	.size	foo,.Lfe1-foo
.globl thrice
	.type	thrice,@function
_thrice:
	pushl	%ebp
	movl	%esp, %ebp
	movl	8(%ebp), %edx
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	sall	$1, %eax
	movl	%eax, (%edx)
	leave
	ret
.Lfe2:
	.size	thrice,.Lfe2-thrice
.globl main
	.type	main,@function
main:
	pushl	%ebp
	movl	%esp, %ebp
	subl	$56, %esp
	andl	$-16, %esp
	movl	$0, %eax
	subl	%eax, %esp
	movl	$19, -12(%ebp)
	cmpl	$9, -12(%ebp)
	jg	.L4
	movl	$13, -16(%ebp)
	jmp	.L5
.L4:
	movl	$65, -16(%ebp)
.L5:
	movl	$0, -12(%ebp)
.L6:
	cmpl	$1, -12(%ebp)
	jle	.L9
	jmp	.L7
.L9:
	movl	-12(%ebp), %edx
	movl	-16(%ebp), %eax
	addl	-12(%ebp), %eax
	movl	%eax, -56(%ebp,%edx,4)
	leal	-12(%ebp), %eax
	incl	(%eax)
	jmp	.L6
.L7:
	subl	$8, %esp
	pushl	$31
	pushl	-12(%ebp)
	call	_foo
	addl	$16, %esp
	movl	%eax, -44(%ebp)
	subl	$12, %esp
	leal	-16(%ebp), %eax
	pushl	%eax
	call	_thrice
	addl	$16, %esp
	movl	-16(%ebp), %eax
	leave
	ret
.Lfe3:
	.size	main,.Lfe3-main
	.section	.note.GNU-stack,"",@progbits
	.ident	"GCC: (GNU) 3.2.3 20030502 (Red Hat Linux 3.2.3-49)"
