/*

Stars OS - By AZPEP_BiliBili@Gitee

Include/multiboot

由于我们要使用GRUB2进行引导，为了方便扩展，我们需要配置一些常量，这些常量便放置在这个文件中

*/
#define BootLoader_Grub2_Common_Head 0x1BADB002   //multiboot标准头
#define BootLoader_Grub2_Flags 0b00000000000000000000000000000111 //multiboot的第二个部分，是grub的标志位
#define BootLoader_Grub2_CheckSum(flags)    -(BootLoader_Grub2_Common_Head+flags) //CheckSum是multiboot的第3个部分

/* 
Multiboot Head 地址域

如果flags[16]被置位，则尽可能填写以下信息
否则请保持以下所有值为0x00000000
条件: 
        3              11
        1              65              0
flags = ???????????????1????????????????


*/
#define BootLoader_Multiboot_Header_Addr 0x00000000
#define BootLoader_Multiboot_Load_Addr 0x00000000
#define BootLoader_Multiboot_Load_End_Addr 0x00000000
#define BootLoader_Multiboot_Bss_End_Addr 0x00000000
#define BootLoader_Multiboot_Entry_Addr 0x00000000

/*

Multiboot Head 图形域

如果flags[2]，则必须填写以下信息
否则请保持以下所有值为0x00000000

条件：
        3               1
        1               5            2 0
flags = ?????????????????????????????1??

*/

#define BootLoader_Screen_Mode_Type 0x00000001
#define BootLoader_Screen_Width 0x000000A0
#define BootLoader_Screen_Height 0x00000032
#define BootLoader_Screen_Depth 0x00000000