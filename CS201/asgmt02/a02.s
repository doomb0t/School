	.file	"a02.c"
	.text
	.globl	sphereVolumeC
	.type	sphereVolumeC, @function
sphereVolumeC:
.LFB2:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movsd	%xmm0, -24(%rbp)
	movabsq	$4614253070214989087, %rax
	movq	%rax, -8(%rbp)
	movsd	-8(%rbp), %xmm1
	movsd	.LC1(%rip), %xmm0
	mulsd	%xmm1, %xmm0
	mulsd	-24(%rbp), %xmm0
	mulsd	-24(%rbp), %xmm0
	mulsd	-24(%rbp), %xmm0
	movsd	.LC2(%rip), %xmm1
	divsd	%xmm1, %xmm0
	movsd	%xmm0, -32(%rbp)
	movq	-32(%rbp), %rax
	movq	%rax, -32(%rbp)
	movsd	-32(%rbp), %xmm0
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2:
	.size	sphereVolumeC, .-sphereVolumeC
	.globl	sphereVolume
	.type	sphereVolume, @function
sphereVolume:
.LFB3:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movsd	%xmm0, -8(%rbp)
#APP
# 18 "a02.c" 1
			mov		$0, %eax			

# 0 "" 2
#NO_APP
	movl	$0, %eax
	movq	%rax, -16(%rbp)
	movsd	-16(%rbp), %xmm0
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3:
	.size	sphereVolume, .-sphereVolume
	.section	.rodata
	.align 8
.LC4:
	.string	"CS201 - Assignment 2 - I. Forgot"
	.align 8
.LC5:
	.string	"need 1 argument: radius of sphere"
	.align 8
.LC6:
	.string	"sphereVolume(%.3f) = %.3f, %.3f\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB4:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$64, %rsp
	movl	%edi, -36(%rbp)
	movq	%rsi, -48(%rbp)
	movl	$.LC4, %edi
	call	puts
	cmpl	$2, -36(%rbp)
	je	.L6
	movl	$.LC5, %edi
	call	puts
	movl	$-1, %eax
	jmp	.L7
.L6:
	movq	-48(%rbp), %rax
	addq	$8, %rax
	movq	(%rax), %rax
	movq	%rax, %rdi
	call	atof
	movsd	%xmm0, -56(%rbp)
	movq	-56(%rbp), %rax
	movq	%rax, -8(%rbp)
	movq	-8(%rbp), %rax
	movq	%rax, -56(%rbp)
	movsd	-56(%rbp), %xmm0
	call	sphereVolume
	movsd	%xmm0, -56(%rbp)
	movq	-56(%rbp), %rax
	movq	%rax, -16(%rbp)
	movq	-8(%rbp), %rax
	movq	%rax, -56(%rbp)
	movsd	-56(%rbp), %xmm0
	call	sphereVolumeC
	movsd	%xmm0, -56(%rbp)
	movq	-56(%rbp), %rax
	movq	%rax, -24(%rbp)
	movq	-24(%rbp), %rcx
	movq	-16(%rbp), %rdx
	movq	-8(%rbp), %rax
	movq	%rcx, -56(%rbp)
	movsd	-56(%rbp), %xmm2
	movq	%rdx, -56(%rbp)
	movsd	-56(%rbp), %xmm1
	movq	%rax, -56(%rbp)
	movsd	-56(%rbp), %xmm0
	movl	$.LC6, %edi
	movl	$3, %eax
	call	printf
	movl	$0, %eax
.L7:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE4:
	.size	main, .-main
	.section	.rodata
	.align 8
.LC1:
	.long	0
	.long	1074790400
	.align 8
.LC2:
	.long	0
	.long	1074266112
	.ident	"GCC: (SUSE Linux) 4.8.1 20130909 [gcc-4_8-branch revision 202388]"
	.section	.note.GNU-stack,"",@progbits
