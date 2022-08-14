#include <SystemInfo.h>
#include <BootLoader/grub.h>
#include <Graph.h>

multiboot_info_t *mbi;

int sys_mb_magic;
int sys_mb_flags;

int sys_mem_config;
unsigned int sys_mem_lower,sys_mem_upper;

int sys_devices_config;
unsigned int sys_devices_boot_device;
unsigned int sys_devices_Devices_Type,sys_devices_Partten_Number_1,sys_devices_Partten_Number_2,sys_devices_Partten_Number_3;

int sys_cmdline_config;
unsigned long sys_cmdline_addr;
char sys_cmdline[512];

int sys_mmap_config;
unsigned long sys_mmap_base_addr_low;
unsigned long sys_mmap_base_addr_high;
unsigned long sys_mmap_length_low;
unsigned long sys_mmap_length_high;
unsigned long sys_mmap_type;

int sys_boot_loader_name_config;
unsigned long sys_boot_loader_name_addr;
char sys_boot_loader_name[64];

void _Info_Main(unsigned long magic, unsigned long addr){
    mbi=(multiboot_info_t*)addr;

    sys_mb_magic=magic;
    sys_mb_flags=mbi->flags;

    //flags[0]=1
    if(CHECK_FLAG(mbi->flags,0)){
        sys_mem_config=1;

        sys_mem_lower=(unsigned)mbi->mem_lower;
        sys_mem_upper=(unsigned)mbi->mem_upper;

        //printf("Memory: Lower=%d,Upper=%d\n\n",sys_mem_lower,sys_mem_upper);
    }

    //flags[1]=1
    if(CHECK_FLAG(mbi->flags,1)){
        sys_devices_config=1;

        sys_devices_boot_device=mbi->boot_device;
        //printf("Boot Devices=%d\n",sys_devices_boot_device);
        Get_Boot_Devices(sys_devices_boot_device);
    }

    //flags[2]=1
    if(CHECK_FLAG(mbi->flags,2)){
        sys_cmdline_config=1;
        sys_cmdline_addr=mbi->cmdline;
        

        copy_string(sys_cmdline_addr,sys_cmdline);


        
        //Graph_Set_Theme(VGA_COLOR_WHITE,VGA_COLOR_BLACK);
        //printf("%d\n%s",sys_cmdline_addr,sys_cmdline);
        
    }

    //flags[3],flags[4],flags[5]，mbi[20-40]不用

    if(CHECK_FLAG(mbi->flags,9)){
        sys_boot_loader_name_config=1;
        sys_boot_loader_name_addr=mbi->boot_loader_name;
        
        copy_string(sys_boot_loader_name_addr,sys_boot_loader_name);

        /*
        Graph_Set_Theme(VGA_COLOR_WHITE,VGA_COLOR_BLACK);
        printf("%d\n%d\n%s",sys_boot_loader_name_config,sys_boot_loader_name_addr,sys_boot_loader_name);
        while(1);
        */
    }
}

void Get_Boot_Devices(unsigned int Boot_Devices){
    char* Boot_Devices_str=(char)Boot_Devices;

    sys_devices_Devices_Type=(int)Boot_Devices_str[0];
    sys_devices_Partten_Number_1=(int)Boot_Devices_str[1];
    sys_devices_Partten_Number_2=(int)Boot_Devices_str[2];
    sys_devices_Partten_Number_3=(int)Boot_Devices_str[3];

    return;
}

void copy_string(char* p1, char* p2) {
    for (; *p1 != '\0'; *p1++,*p2++)
    {
        *p2 = *p1;
    }
    *p2 = '\0';
}
