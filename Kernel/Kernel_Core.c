#include <Graph.h>
#include <BootLoader/gdt.h>

void _Kernel_Init(){
	_init_gdt();
	_init_idt();
}

void _Kernel_Main(void *Info_Table){
    Graph_Set_Theme(VGA_COLOR_GREEN,VGA_COLOR_BLACK);
	Graph_Clear_Screen();
	Graph_Put_Str("Hello Stars OS!\n");
	Graph_Put_Str("This is line 2!");

	__asm__("int $0");
}