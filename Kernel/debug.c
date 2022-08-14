#include <Graph.h>
#include <SystemInfo.h>

void _debug_print_multiboot_info(){
    Graph_Set_Theme(VGA_COLOR_BLACK,VGA_COLOR_WHITE);
    Graph_Clear_Screen();

    printf("------ multiboot info ------\n\n");
    printf("Multiboot Magic Number=%d\n",(int)sys_mb_magic);
    printf("flags=%d\n\n",sys_mb_flags);

    if(sys_mem_config == 1){
        printf("Memory: Lower=%d,Upper=%d\n\n",sys_mem_lower,sys_mem_upper);
    }
    if(sys_devices_config == 1){
        printf("Boot Devices=%d\n",sys_devices_boot_device);
        printf("Devices Type=%d,\nParameter1=%d,\nParameter2=%d,\nParameter3=%d\n\n",sys_devices_Devices_Type,sys_devices_Partten_Number_1,sys_devices_Partten_Number_2,sys_devices_Partten_Number_3);
    }
    if(sys_cmdline_config == 1){
        printf("CmdLine Addr=%d\n",sys_cmdline_addr);
        printf("CmdLine=%s\n\n",sys_cmdline);
    }
    if(sys_boot_loader_name_config == 1){
        printf("Boot Loader Name Addr=%d\n",sys_cmdline_addr);
        printf("Boot Loader Name=%s\n\n",sys_boot_loader_name);
    }
    __asm__("hlt");
}