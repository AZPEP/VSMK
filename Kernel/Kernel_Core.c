#include <Graph.h>
#include <BootLoader/gdt.h>
#include <debug.h>

void _Kernel_Init(){
	_init_gdt();
	_init_idt();
	_debug_print_multiboot_info();
	
}

void _Kernel_Main(void *Info_Table){
    Graph_Set_Theme(VGA_COLOR_GREEN,VGA_COLOR_BLACK);

	Graph_Put_Str("Hello Stars OS!\n");
	Graph_Put_Str("This is line 2!\n");

	printf("Hello Stars OS,But Printf\n");
	
	//__asm__("int $0");
	//int err=1/0;
}