	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 10, 15	sdk_version 10, 15, 6
	.globl	_rsum                   ## -- Begin function rsum
	.p2align	4, 0x90
_rsum:                                  ## @rsum
	.cfi_startproc
## %bb.0:
	testl	%esi, %esi
	jle	LBB0_1
## %bb.2:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	pushq	%rbx
	pushq	%rax
	.cfi_offset %rbx, -24
	movl	(%rdi), %ebx
	addq	$4, %rdi
	decl	%esi
	callq	_rsum
	addl	%ebx, %eax
	addq	$8, %rsp
	popq	%rbx
	popq	%rbp
	retq
LBB0_1:
	xorl	%eax, %eax
	retq
	.cfi_endproc
                                        ## -- End function
.subsections_via_symbols
