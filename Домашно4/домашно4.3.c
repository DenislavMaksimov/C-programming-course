	.file	"\320\264\320\276\320\274\320\260\321\210\320\275\320\2764.2.c"
	.text
	.globl	nod
	.def	nod;	.scl	2;	.type	32;	.endef
	.seh_proc	nod
nod:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$16, %rsp
	.seh_stackalloc	16
	.seh_endprologue
	movl	%ecx, 16(%rbp)
	movl	%edx, 24(%rbp)
	jmp	.L2
.L3:
	movl	24(%rbp), %eax
	movl	%eax, -4(%rbp)
	movl	16(%rbp), %eax
	cltd
	idivl	24(%rbp)
	movl	%edx, 24(%rbp)
	movl	-4(%rbp), %eax
	movl	%eax, 16(%rbp)
.L2:
	cmpl	$0, 24(%rbp)
	jne	.L3
	movl	16(%rbp), %eax
	addq	$16, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.globl	nok
	.def	nok;	.scl	2;	.type	32;	.endef
	.seh_proc	nok
nok:
	pushq	%rbp
	.seh_pushreg	%rbp
	pushq	%rbx
	.seh_pushreg	%rbx
	subq	$40, %rsp
	.seh_stackalloc	40
	leaq	32(%rsp), %rbp
	.seh_setframe	%rbp, 32
	.seh_endprologue
	movl	%ecx, 32(%rbp)
	movl	%edx, 40(%rbp)
	movl	32(%rbp), %eax
	imull	40(%rbp), %eax
	movl	%eax, %ebx
	movl	40(%rbp), %edx
	movl	32(%rbp), %eax
	movl	%eax, %ecx
	call	nod
	movl	%eax, %ecx
	movl	%ebx, %eax
	cltd
	idivl	%ecx
	addq	$40, %rsp
	popq	%rbx
	popq	%rbp
	ret
	.seh_endproc
	.section .rdata,"dr"
	.align 8
.LC0:
	.ascii "\320\222\321\212\320\262\320\265\320\264\320\265\321\202\320\265 \320\264\320\262\320\265 \321\207\320\270\321\201\320\273\320\260: \0"
.LC1:
	.ascii "%d  \0"
.LC2:
	.ascii "%d\0"
	.align 8
.LC3:
	.ascii "\320\235\320\260\320\271-\320\274\320\260\320\273\320\272\320\276\321\202\320\276 \320\276\320\261\321\211\320\276 \320\272\321\200\320\260\321\202\320\275\320\276 \320\275\320\260 %d \320\270 %d \320\265: %d\12\0"
	.text
	.globl	main
	.def	main;	.scl	2;	.type	32;	.endef
	.seh_proc	main
main:
	pushq	%rbp
	.seh_pushreg	%rbp
	movq	%rsp, %rbp
	.seh_setframe	%rbp, 0
	subq	$48, %rsp
	.seh_stackalloc	48
	.seh_endprologue
	call	__main
	leaq	.LC0(%rip), %rax
	movq	%rax, %rcx
	call	__mingw_printf
	leaq	-8(%rbp), %rax
	movq	%rax, %rdx
	leaq	.LC1(%rip), %rax
	movq	%rax, %rcx
	call	__mingw_scanf
	leaq	-12(%rbp), %rax
	movq	%rax, %rdx
	leaq	.LC2(%rip), %rax
	movq	%rax, %rcx
	call	__mingw_scanf
	movl	-12(%rbp), %edx
	movl	-8(%rbp), %eax
	movl	%eax, %ecx
	call	nok
	movl	%eax, -4(%rbp)
	movl	-12(%rbp), %edx
	movl	-8(%rbp), %eax
	movl	-4(%rbp), %ecx
	movl	%ecx, %r9d
	movl	%edx, %r8d
	movl	%eax, %edx
	leaq	.LC3(%rip), %rax
	movq	%rax, %rcx
	call	__mingw_printf
	movl	$0, %eax
	addq	$48, %rsp
	popq	%rbp
	ret
	.seh_endproc
	.def	__main;	.scl	2;	.type	32;	.endef
	.ident	"GCC: (Rev1, Built by MSYS2 project) 14.2.0"
