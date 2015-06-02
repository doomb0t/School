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
	subq	$72, %rsp
	.cfi_offset 3, -24
	movl	$8, %esi
	movl	$10000, %edi
	call	calloc
	movq	%rax, -80(%rbp)
	movl	$0, %eax
	movq	%rax, -24(%rbp)
	movl	$0, %eax
	movq	%rax, -40(%rbp)
	movl	$0, %eax
	movq	%rax, -48(%rbp)
	movl	$0, %eax
	movq	%rax, -56(%rbp)
	movl	$0, %eax
	movq	%rax, -64(%rbp)
	movl	$0, %eax
	movq	%rax, -72(%rbp)
	movl	$.LC1, %edi
	call	puts
	movl	$0, -28(%rbp)
	jmp	.L2
.L6:
	movq	-80(%rbp), %rax
	leaq	80000(%rax), %rbx
	jmp	.L3
.L4:
	movsd	(%rbx), %xmm1
	leaq	-8(%rbx), %rax
	movsd	(%rax), %xmm0
	addsd	%xmm1, %xmm0
	leaq	-16(%rbx), %rax
	movsd	(%rax), %xmm1
	addsd	%xmm1, %xmm0
	leaq	-24(%rbx), %rax
	movsd	(%rax), %xmm1
	addsd	%xmm1, %xmm0
	movsd	-40(%rbp), %xmm1
	addsd	%xmm1, %xmm0
	movsd	%xmm0, -40(%rbp)
	movsd	(%rbx), %xmm1
	leaq	-32(%rbx), %rax
	movsd	(%rax), %xmm0
	addsd	%xmm1, %xmm0
	leaq	-40(%rbx), %rax
	movsd	(%rax), %xmm1
	addsd	%xmm1, %xmm0
	leaq	-48(%rbx), %rax
	movsd	(%rax), %xmm1
	addsd	%xmm1, %xmm0
	movsd	-48(%rbp), %xmm1
	addsd	%xmm1, %xmm0
	movsd	%xmm0, -48(%rbp)
	movsd	(%rbx), %xmm1
	leaq	-56(%rbx), %rax
	movsd	(%rax), %xmm0
	addsd	%xmm1, %xmm0
	leaq	-64(%rbx), %rax
	movsd	(%rax), %xmm1
	addsd	%xmm1, %xmm0
	leaq	-72(%rbx), %rax
	movsd	(%rax), %xmm1
	addsd	%xmm1, %xmm0
	movsd	-56(%rbp), %xmm1
	addsd	%xmm1, %xmm0
	movsd	%xmm0, -56(%rbp)
	movsd	(%rbx), %xmm1
	leaq	-80(%rbx), %rax
	movsd	(%rax), %xmm0
	addsd	%xmm1, %xmm0
	leaq	-88(%rbx), %rax
	movsd	(%rax), %xmm1
	addsd	%xmm1, %xmm0
	leaq	-96(%rbx), %rax
	movsd	(%rax), %xmm1
	addsd	%xmm1, %xmm0
	movsd	-64(%rbp), %xmm1
	addsd	%xmm1, %xmm0
	movsd	%xmm0, -64(%rbp)
	movsd	(%rbx), %xmm1
	leaq	-104(%rbx), %rax
	movsd	(%rax), %xmm0
	addsd	%xmm1, %xmm0
	leaq	-112(%rbx), %rax
	movsd	(%rax), %xmm1
	addsd	%xmm1, %xmm0
	leaq	-120(%rbx), %rax
	movsd	(%rax), %xmm1
	addsd	%xmm1, %xmm0
	movsd	-72(%rbp), %xmm1
	addsd	%xmm1, %xmm0
	movsd	%xmm0, -72(%rbp)
	subq	$120, %rbx
.L3:
	leaq	-120(%rbx), %rax
	cmpq	-80(%rbp), %rax
	ja	.L4
	cmpq	-80(%rbp), %rbx
	jbe	.L5
	movsd	(%rbx), %xmm0
	movsd	-24(%rbp), %xmm1
	addsd	%xmm1, %xmm0
	movsd	%xmm0, -24(%rbp)
.L5:
	addl	$1, -28(%rbp)
.L2:
	cmpl	$599999, -28(%rbp)
	jle	.L6
	movsd	-40(%rbp), %xmm0
	addsd	-48(%rbp), %xmm0
	addsd	-56(%rbp), %xmm0
	addsd	-64(%rbp), %xmm0
	addsd	-72(%rbp), %xmm0
	movsd	-24(%rbp), %xmm1
	addsd	%xmm1, %xmm0
	movsd	%xmm0, -24(%rbp)
	movl	$0, %eax
	addq	$72, %rsp
	popq	%rbx
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2:
	.size	main, .-main
	.ident	"GCC: (SUSE Linux) 4.8.1 20130909 [gcc-4_8-branch revision 202388]"
	.section	.note.GNU-stack,"",@progbits
