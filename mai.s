	.text
	.file	"mai.c"
	.globl	faz_o_l                         # -- Begin function faz_o_l
	.p2align	4, 0x90
	.type	faz_o_l,@function
faz_o_l:                                # @faz_o_l
	.cfi_startproc
# %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	movl	$0, -4(%rbp)
.LBB0_1:                                # =>This Inner Loop Header: Depth=1
	cmpl	$100000, -4(%rbp)               # imm = 0x186A0
	jge	.LBB0_3
# %bb.2:                                #   in Loop: Header=BB0_1 Depth=1
	movl	min, %eax
	addl	$1, %eax
	movl	%eax, min
	movl	-4(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -4(%rbp)
	jmp	.LBB0_1
.LBB0_3:
	xorl	%eax, %eax
                                        # kill: def $rax killed $eax
	popq	%rbp
	.cfi_def_cfa %rsp, 8
	retq
.Lfunc_end0:
	.size	faz_o_l, .Lfunc_end0-faz_o_l
	.cfi_endproc
                                        # -- End function
	.globl	main                            # -- Begin function main
	.p2align	4, 0x90
	.type	main,@function
main:                                   # @main
	.cfi_startproc
# %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$32, %rsp
	movl	$0, -4(%rbp)
	movl	%edi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	leaq	-24(%rbp), %rdi
	xorl	%eax, %eax
	movl	%eax, %ecx
	movabsq	$faz_o_l, %rdx
	movq	%rcx, %rsi
	callq	pthread_create
	leaq	-32(%rbp), %rdi
	xorl	%eax, %eax
	movl	%eax, %ecx
	movabsq	$faz_o_l, %rdx
	movq	%rcx, %rsi
	callq	pthread_create
	movq	-24(%rbp), %rdi
	xorl	%eax, %eax
	movl	%eax, %esi
	callq	pthread_join
	movq	-32(%rbp), %rdi
	xorl	%eax, %eax
	movl	%eax, %esi
	callq	pthread_join
	movl	min, %esi
	movabsq	$.L.str, %rdi
	movb	$0, %al
	callq	printf
	xorl	%eax, %eax
	addq	$32, %rsp
	popq	%rbp
	.cfi_def_cfa %rsp, 8
	retq
.Lfunc_end1:
	.size	main, .Lfunc_end1-main
	.cfi_endproc
                                        # -- End function
	.type	min,@object                     # @min
	.bss
	.globl	min
	.p2align	2
min:
	.long	0                               # 0x0
	.size	min, 4

	.type	.L.str,@object                  # @.str
	.section	.rodata.str1.1,"aMS",@progbits,1
.L.str:
	.asciz	"min: %d\n"
	.size	.L.str, 9

	.ident	"Ubuntu clang version 12.0.0-3ubuntu1~20.04.5"
	.section	".note.GNU-stack","",@progbits
	.addrsig
	.addrsig_sym faz_o_l
	.addrsig_sym pthread_create
	.addrsig_sym pthread_join
	.addrsig_sym printf
	.addrsig_sym min


				t1      t2
min				26		23
incrementado	27		24