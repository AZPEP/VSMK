#pragma pack(push,1)
typedef struct 
{
    unsigned int vector;
    unsigned int err_code;
    unsigned int eip;
    unsigned short cs;
    unsigned eflags;
} isr_param;
#pragma pack(pop)

void interrupt_handler(isr_param* param);

//void _asm_isr0();
void isr0();