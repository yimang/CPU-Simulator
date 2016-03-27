	.file	"test5.c"
	.text
	.align 2
.globl _Z3fooii
	.type	_Z3fooii,@function
_Z3fooii:
.LFB2:
	pushl	%ebp
.LCFI0:
	movl	%esp, %ebp
.LCFI1:
	movl	12(%ebp), %eax
	addl	8(%ebp), %eax
	leave
	ret
.LFE2:
.Lfe1:
	.size	_Z3fooii,.Lfe1-_Z3fooii
	.align 2
.globl _Z5twicePi
	.type	_Z5twicePi,@function
_Z5twicePi:
.LFB4:
	pushl	%ebp
.LCFI2:
	movl	%esp, %ebp
.LCFI3:
	movl	8(%ebp), %edx
	movl	8(%ebp), %eax
	movl	(%eax), %eax
	sall	$1, %eax
	movl	%eax, (%edx)
	leave
	ret
.LFE4:
.Lfe2:
	.size	_Z5twicePi,.Lfe2-_Z5twicePi
	.align 2
.globl main
	.type	main,@function
main:
.LFB6:
	pushl	%ebp
.LCFI4:
	movl	%esp, %ebp
.LCFI5:
	subl	$24, %esp
.LCFI6:
	andl	$-16, %esp
	movl	$0, %eax
	subl	%eax, %esp
	movl	$7, -4(%ebp)
	movl	$15, -8(%ebp)
	subl	$8, %esp
	pushl	$31
	pushl	-4(%ebp)
.LCFI7:
	call	_Z3fooii
	addl	$16, %esp
	movl	%eax, -12(%ebp)
	subl	$12, %esp
	leal	-8(%ebp), %eax
	pushl	%eax
	call	_Z5twicePi
	addl	$16, %esp
	movl	-12(%ebp), %eax
	leave
	ret
.LFE6:
.Lfe3:
	.size	main,.Lfe3-main
	.section	.note.GNU-stack,"",@progbits
	.ident	"GCC: (GNU) 3.2.3 20030502 (Red Hat Linux 3.2.3-49)"
