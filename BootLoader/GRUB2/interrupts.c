#include <BootLoader/interrupt.h>
#include <Graph.h>
void isr0(isr_param* param){
    Graph_Set_Theme(VGA_COLOR_RED,VGA_COLOR_WHITE);
    Graph_Clear_Screen();
    Graph_Put_Str("!!PANIC!!");
}

void interrupt_handler(isr_param* param){
    switch (param->vector)
    {
        case 0:
            isr0(param);
            break;
    }
}