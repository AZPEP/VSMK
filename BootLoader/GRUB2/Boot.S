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
//#include "Kernel.h"
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
    .long BootLoader_Multiboot_Header_Addr
    .long BootLoader_Multiboot_Load_Addr
    .long BootLoader_Multiboot_Load_End_Addr
    .long BootLoader_Multiboot_Bss_End_Addr
    .long BootLoader_Multiboot_Entry_Addr
    .long BootLoader_Screen_Mode_Type
    .long BootLoader_Screen_Width
    .long BootLoader_Screen_Height
    .long BootLoader_Screen_Depth

.section .bss
    /* 变量段 */
    .align 16 //对齐到16整数倍字节

    /* 栈段 */
    stack_bottom:   //栈底
        .skip 16318,0
    stack_top:      //栈顶

.section .text
    /* 代码段 */

    /* 映照ld规定，_start为程序入口 */
    _start:

        movl $stack_top,%esp //设置栈顶
        
        /*
        将要填充的代码：

        初始化GDT&IDT

         */
        
        /*
        注意,外部函数_Kernel_Init和_Kernel_SMain未编写，一旦编译会出现错误！！！
         */
        
        call _Kernel_Init   //初始化内核

        pushl %ebx
        call _Kernel_Main   //内核主程序

    
    cli
    .Stop_Kernel:

    /*
    这里是内核中止的地方
     */
    
    hlt
    jmp .Stop_Kernel