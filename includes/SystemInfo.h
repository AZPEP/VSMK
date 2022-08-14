#pragma once
#ifndef __System_Info__
#define __System_Info__

#include <BootLoader/grub.h>
#include <stdint-gcc.h>
extern multiboot_info_t *mbi;

extern int sys_mb_magic;
extern int sys_mb_flags;

extern int sys_mem_config;
extern unsigned int sys_mem_lower,sys_mem_upper;

extern int sys_devices_config;
extern unsigned int sys_devices_boot_device;
extern unsigned int sys_devices_Devices_Type,sys_devices_Partten_Number_1,sys_devices_Partten_Number_2,sys_devices_Partten_Number_3;

extern int sys_cmdline_config;
extern unsigned long sys_cmdline_addr;
extern char sys_cmdline[512];

extern int sys_mmap_config;
extern unsigned long sys_mmap_base_addr_low;
extern unsigned long sys_mmap_base_addr_high;
extern unsigned long sys_mmap_length_low;
extern unsigned long sys_mmap_length_high;
extern unsigned long sys_mmap_type;

extern int sys_boot_loader_name_config;
extern unsigned long sys_boot_loader_name_addr;
extern char sys_boot_loader_name[64];
#endif