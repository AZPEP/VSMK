#include <BootLoader/interrupt.h>
#include <Graph.h>

void isr0(isr_param *param){
    Graph_Set_Theme(VGA_COLOR_RED, VGA_COLOR_WHITE);
    Graph_Clear_Screen();
    printf("!!PANIC Error!!\n");
    printf("Vector=%d,\nError Code=%d,\nEIP=%d,\nCS=%d,\nEFLAGS=%d\n",param->vector,param->err_code,param->eip,param->cs,param->eflags);

    __asm__("cli");
    __asm__("hlt");
}

void interrupt_handler(isr_param *param){
    switch (param->vector)
    {
    case 0:
        isr0(param);
        break;
    }
}