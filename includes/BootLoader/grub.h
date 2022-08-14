#ifndef __GRUB_INFO_TABLE__
#define __GRUB_INFO_TABLE__

/* a.out 符号表。 */
typedef struct aout_symbol_table
{
    unsigned long tabsize;
    unsigned long strsize;
    unsigned long addr;
    unsigned long reserved;
} aout_symbol_table_t;
 
/* ELF 的 section header table。 */
typedef struct elf_section_header_table
{
    unsigned long num;
    unsigned long size;
    unsigned long addr;
    unsigned long shndx;

}elf_section_header_table_t;
/* Multiboot 信息。 */
typedef struct multiboot_info
{
    unsigned long flags;

    //(如果flags[0]被置位则出现)
    unsigned long mem_lower; 
    unsigned long mem_upper;

    //(如果flags[1]被置位则出现)
    unsigned long boot_device;

    //(如果flags[2]被置位则出现)
    unsigned long cmdline;

    //(如果flags[3]被置位则出现)
    unsigned long mods_count;
    unsigned long mods_addr;

    // (如果flags[4]或flags[5]被置位则出现)
    union
    {
        aout_symbol_table_t aout_sym;
        elf_section_header_table_t elf_sec;
    } u;

    //(如果flags[6]被置位则出现)
    unsigned long mmap_length;
    unsigned long mmap_addr;

    //(如果flags[7]被置位则出现)
    unsigned long drives_length;
    unsigned long drives_addr;

    //(如果flags[8]被置位则出现)
    unsigned long config_table;

    //(如果flags[9]被置位则出现)
    unsigned long boot_loader_name;

    // (如果flags[10]被置位则出现)
    unsigned long apm_table;

    //(如果flags[11]被置位则出现)
    unsigned long vbe_control_info;
    unsigned long vbe_mode_info;
    unsigned long vbe_mode;
    unsigned long vbe_interface_seg;
    unsigned long vbe_interface_off;
    unsigned long vbe_interface_len;

} multiboot_info_t;



/* 检测 FLAGS 中的位 BIT 是否被置位。 */
#define CHECK_FLAG(flags,bit)   ((flags) & (1 << (bit)))

#endif