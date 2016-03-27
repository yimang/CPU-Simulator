	.file	"test4.c"
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	pushl	%ebp
	.cfi_def_cfa_offset 8
	.cfi_offset 5, -8
	movl	%esp, %ebp
	.cfi_def_cfa_register 5
	subl	$64, %esp
	movl	$197, -12(%ebp)
	cmpl	$99, -12(%ebp)
	jg	.L2
	movl	$134, -4(%ebp)
	jmp	.L3
.L2:
	movl	$26, -4(%ebp)
.L3:
	movl	$0, -8(%ebp)
	jmp	.L4
.L5:
	movl	-12(%ebp), %edx
	movl	-4(%ebp), %eax
	addl	%eax, %edx
	movl	-8(%ebp), %eax
	movl	%edx, -52(%ebp,%eax,4)
	addl	$1, -8(%ebp)
.L4:
	cmpl	$2, -8(%ebp)
	jle	.L5
	movl	-44(%ebp), %eax
	addl	$18, %eax
	movl	%eax, -12(%ebp)
	movl	-4(%ebp), %eax
	leave
	.cfi_restore 5
	.cfi_def_cfa 4, 4
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (GNU) 5.3.1 20151207 (Red Hat 5.3.1-2)"
	.section	.note.GNU-stack,"",@progbits
