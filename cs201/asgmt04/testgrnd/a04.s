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
	subq	$40, %rsp
	.cfi_offset 3, -24
	movl	$8, %esi
	movl	$10000, %edi
	call	calloc
	movq	%rax, -24(%rbp)
	movl	$0, %eax
	movq	%rax, -32(%rbp)
	movl	$.LC1, %edi
	call	puts
	movl	$0, -36(%rbp)
	jmp	.L2
.L6:
	movq	-24(%rbp), %rax
	leaq	80000(%rax), %rbx
	jmp	.L3
.L4:
	movsd	(%rbx), %xmm1
	leaq	-8(%rbx), %rax
	movsd	(%rax), %xmm0
	addsd	%xmm1, %xmm0
	movsd	-32(%rbp), %xmm1
	addsd	%xmm0, %xmm1
	movq	%xmm1, %rax
	movq	%rax, -32(%rbp)
	subq	$16, %rbx
.L3:
	leaq	-8(%rbx), %rax
	cmpq	-24(%rbp), %rax
	ja	.L4
	cmpq	-24(%rbp), %rbx
	jbe	.L5
	movsd	(%rbx), %xmm0
	movsd	-32(%rbp), %xmm1
	addsd	%xmm0, %xmm1
	movq	%xmm1, %rax
	movq	%rax, -32(%rbp)
.L5:
	addl	$1, -36(%rbp)
.L2:
	cmpl	$599999, -36(%rbp)
	jle	.L6
	movl	$0, %eax
	addq	$40, %rsp
	popq	%rbx
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 4.9.2-10ubuntu13) 4.9.2"
	.section	.note.GNU-stack,"",@progbits
