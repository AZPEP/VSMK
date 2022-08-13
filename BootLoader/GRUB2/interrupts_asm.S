//#define __ASM__
//#include <BootLoader/interrupt.h>
//#define __ASM_INTR_DIAGNOSIS

.code32

.macro isr_template vector, no_error_code=1
    .global _asm_isr\vector
    .type _asm_isr\vector @function
    _asm_isr\vector:
        .if \no_error_code
            pushl $0x0
        .endif
        pushl $\vector
        jmp interrupt_wrapper
    
.endm

.section .text

    isr_template 0

    interrupt_wrapper:
        movl %esp,%eax
        andl $0xfffffff0,%esp
        subl $16, %esp
        movl %eax,(%esp)

        call interrupt_handler
        
        popl %eax
        movl %eax,%esp
        addl $8, %esp

        iret 
    