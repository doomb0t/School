	.file	"a04.c"
	.section	.rodata
	.align 8
.LC1:
	.string	"CS201 - Asgmt 4 - Jonathon Sonesen "
	.text
	.globl	main
	.type	main, @function
main:
.LFB2:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	pushq	%rbx
	subq	$24, %rsp
	.cfi_offset 3, -24
	movl	$8, %esi
	movl	$10000, %edi
	call	calloc
	movq	%rax, -24(%rbp)
	movl	$.LC1, %edi
	call	puts
	movl	$0, -28(%rbp)
	jmp	.L2
.L6:
	movq	-24(%rbp), %rax
	leaq	80000(%rax), %rbx
	jmp	.L3
.L4:
	subq	$16, %rbx
.L3:
	leaq	-8(%rbx), %rax
	cmpq	-24(%rbp), %rax
	ja	.L4
	cmpq	-24(%rbp), %rbx
	addl	$1, -28(%rbp)
.L2:
	cmpl	$599999, -28(%rbp)
	jle	.L6
	movl	$0, %eax
	addq	$24, %rsp
	popq	%rbx
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 4.9.2-10ubuntu13) 4.9.2"
	.section	.note.GNU-stack,"",@progbits
