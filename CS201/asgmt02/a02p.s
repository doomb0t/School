	.file	"a02p.c"
	.text
	.globl	quadraticRootC
	.type	quadraticRootC, @function
quadraticRootC:
.LFB2:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movsd	%xmm0, -8(%rbp)
	movsd	%xmm1, -16(%rbp)
	movsd	%xmm2, -24(%rbp)
	movsd	-16(%rbp), %xmm0
	mulsd	-16(%rbp), %xmm0
	movsd	-8(%rbp), %xmm2
	movsd	.LC0(%rip), %xmm1
	mulsd	%xmm2, %xmm1
	mulsd	-24(%rbp), %xmm1
	subsd	%xmm1, %xmm0
	call	sqrt
	movapd	%xmm0, %xmm1
	subsd	-16(%rbp), %xmm1
	movsd	-8(%rbp), %xmm0
	addsd	%xmm0, %xmm0
	divsd	%xmm0, %xmm1
	movapd	%xmm1, %xmm0
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2:
	.size	quadraticRootC, .-quadraticRootC
	.globl	quadraticRoot
	.type	quadraticRoot, @function
quadraticRoot:
.LFB3:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movsd	%xmm0, -24(%rbp)
	movsd	%xmm1, -32(%rbp)
	movsd	%xmm2, -40(%rbp)
	movl	.LC1(%rip), %eax
	movl	%eax, -4(%rbp)
	movl	.LC1(%rip), %eax
	movl	%eax, -8(%rbp)
#APP
# 18 "a02p.c" 1
	fld    -24(%rbp)              
fadd   %ST              
fld    -24(%rbp)              
fld    -40(%rbp)              
fmulp  %ST(1)           
fadd   %ST              
fadd   %ST              
fchs                     
fld    -32(%rbp)              
fld    -32(%rbp)              
fmulp  %ST(1)           
faddp  %ST(1)           
ftst                     
fstsw  %AX              
sahf                     
jb no_real_roots         
fsqrt                    
fld    -32(%rbp)              
fchs                     
fadd   %ST(1)           
fdivp  %ST(2)           
mov    %ecx, %eax    
fstp   qword(%eax)      
mov    $1, %eax         
jmp    short done        
done:                    

# 0 "" 2
#NO_APP
	movl	%ecx, -4(%rbp)
	movl	%edx, -8(%rbp)
	movl	$0, %eax
	movq	%rax, -48(%rbp)
	movsd	-48(%rbp), %xmm0
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE3:
	.size	quadraticRoot, .-quadraticRoot
	.section	.rodata
	.align 8
.LC3:
	.string	"CS201 - Assignment 2p - I. Forgot"
.LC4:
	.string	"need 3 arguments: a, b, c"
	.align 8
.LC5:
	.string	"quadraticRoot(%.3f, %.3f, %.3f) = %.3f, %.3f\n"
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
	subq	$80, %rsp
	movl	%edi, -52(%rbp)
	movq	%rsi, -64(%rbp)
	movl	$.LC3, %edi
	call	puts
	cmpl	$4, -52(%rbp)
	je	.L6
	movl	$.LC4, %edi
	call	puts
	movl	$-1, %eax
	jmp	.L7
.L6:
	movq	-64(%rbp), %rax
	addq	$8, %rax
	movq	(%rax), %rax
	movq	%rax, %rdi
	call	atof
	movq	%xmm0, %rax
	movq	%rax, -8(%rbp)
	movq	-64(%rbp), %rax
	addq	$16, %rax
	movq	(%rax), %rax
	movq	%rax, %rdi
	call	atof
	movq	%xmm0, %rax
	movq	%rax, -16(%rbp)
	movq	-64(%rbp), %rax
	addq	$24, %rax
	movq	(%rax), %rax
	movq	%rax, %rdi
	call	atof
	movq	%xmm0, %rax
	movq	%rax, -24(%rbp)
	movq	-24(%rbp), %rcx
	movq	-16(%rbp), %rdx
	movq	-8(%rbp), %rax
	movq	%rcx, -72(%rbp)
	movsd	-72(%rbp), %xmm2
	movq	%rdx, -72(%rbp)
	movsd	-72(%rbp), %xmm1
	movq	%rax, -72(%rbp)
	movsd	-72(%rbp), %xmm0
	call	quadraticRoot
	movq	%xmm0, %rax
	movq	%rax, -32(%rbp)
	movq	-24(%rbp), %rcx
	movq	-16(%rbp), %rdx
	movq	-8(%rbp), %rax
	movq	%rcx, -72(%rbp)
	movsd	-72(%rbp), %xmm2
	movq	%rdx, -72(%rbp)
	movsd	-72(%rbp), %xmm1
	movq	%rax, -72(%rbp)
	movsd	-72(%rbp), %xmm0
	call	quadraticRootC
	movq	%xmm0, %rax
	movq	%rax, -40(%rbp)
	movq	-40(%rbp), %rdi
	movq	-32(%rbp), %rsi
	movq	-24(%rbp), %rcx
	movq	-16(%rbp), %rdx
	movq	-8(%rbp), %rax
	movq	%rdi, -72(%rbp)
	movsd	-72(%rbp), %xmm4
	movq	%rsi, -72(%rbp)
	movsd	-72(%rbp), %xmm3
	movq	%rcx, -72(%rbp)
	movsd	-72(%rbp), %xmm2
	movq	%rdx, -72(%rbp)
	movsd	-72(%rbp), %xmm1
	movq	%rax, -72(%rbp)
	movsd	-72(%rbp), %xmm0
	movl	$.LC5, %edi
	movl	$5, %eax
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
.LC0:
	.long	0
	.long	1074790400
	.align 4
.LC1:
	.long	0
	.ident	"GCC: (GNU) 4.9.2 20150304 (prerelease)"
	.section	.note.GNU-stack,"",@progbits
