/*
Stars OS - By AZPEP_BiliBili@Gitee

BootLoader/GRUB2/x86/Boot.S

BootLoader从这里开始，也是内核的开始

GRUB2会加载内核，并从这里开始引导

任务清单：
    让GRUB2能够识别、加载内核
    初始化GDT&IDT
    初始化内核
    运行内核
    当内核退出时，陷入死循环
*/

//引用库

#include "../../includes/BootLoader/multiboot.h"

.code32

.section .multiboot
/*
multiboot标准头，使得GRUB2能够正确的识别、加载内核
该段引入了Include/multiboot.h的三个宏

引用宏：
位于"Include/multiboot.h"
BootLoader_Grub2_Common_Head
BootLoader_Grub2_Flags
BootLoader_Grub2_CheckSum
BootLoader_Multiboot_Header_Addr
BootLoader_Multiboot_Load_Addr
BootLoader_Multiboot_Load_End_Addr
BootLoader_Multiboot_Bss_End_Addr
BootLoader_Multiboot_Entry_Addr
BootLoader_Screen_Mode_Type
BootLoader_Screen_Width
BootLoader_Screen_Height
BootLoader_Screen_Depth

*/
    .long BootLoader_Grub2_Common_Head
    .long BootLoader_Grub2_Flags
    .long BootLoader_Grub2_CheckSum(BootLoader_Grub2_Flags)

    /*
    如果flags[16]被置位，请取消掉这段注释

    .long BootLoader_Multiboot_Header_Addr
    .long BootLoader_Multiboot_Load_Addr
    .long BootLoader_Multiboot_Load_End_Addr
    .long BootLoader_Multiboot_Bss_End_Addr
    .long BootLoader_Multiboot_Entry_Addr

    */

    /*
    如果flags[2]被置位，请取消掉这段注释

    .long BootLoader_Screen_Mode_Type
    .long BootLoader_Screen_Width
    .long BootLoader_Screen_Height
    .long BootLoader_Screen_Depth
    */
.section .bss
    /* 变量段 */
    .align 16 //对齐到16整数倍字节

    /* Multiboot Info段 */
    /*
    mb_info:
        .skip 4096,0
    */

    /* 栈段 */
    stack_bottom:   //栈底
        .skip 16318,0
    stack_top:      //栈顶

.section .text
    /* 代码段 */
    .global	main
    /* 我们在lib/Kernel_Link_Map.lds中规定，start_为程序入口 */
    /* 按照GCC规定，main为函数入口 */
    
    /*
    引用列表

    Kernel/Kernel_Core.c
    _Kernel_Init 
    _Kernel_Main

    Kernel/gdt.c
    _gdt[] 
    _gdt_limit

    */
    main:

        movl $stack_top,%esp //设置栈顶

        push %ebx
        push %eax
        call _Info_Main
        
        call _Kernel_Init   //初始化内核

        //加载GDT
        //这时已使用_init_gdt()初始化gdt
        sub $0x06,%esp
        movl $_gdt, 2(%esp)
        movw _gdt_limit,%ax
        movw %ax,(%esp)
        lgdt (%esp)

        //加载IDT
        //这时已使用_init_idt()初始化idt
        movl $_idt, 2(%esp)
        movw _idt_limit,%ax
        movw %ax,(%esp)
        lidt (%esp)
        
        addl $0x06,%esp

        //初始化寄存器
        movw $0x10,%cx
        movw %cx,%ds
        movw %cx,%es
        movw %cx,%fs
        movw %cx,%gs
        movw %cx,%ss

        pushw $0x08
        pushl $_after_gdt

        retf
    _after_gdt:
        pushl %ebx
        call _Kernel_Main   //内核主程序

    
    cli
    .Stop_Kernel:

    /*
    这里是内核中止的地方
     */
    
    hlt
    jmp .Stop_Kernel