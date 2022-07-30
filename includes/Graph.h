/*
Stars OS - By AZPEP_BiliBili@Gitee

Include/Graph.h
*/
#include "BootLoader/multiboot.h"

void Graph_Set_theme(unsigned short FontColor,unsigned short BackColor);

void Graph_Put_Char(char chr);
void Graph_Put_Str(char* str);
void tty_scrool_Up();


#define Screen_Weight BootLoader_Screen_Width
#define Screen_Height BootLoader_Screen_Height

#define Graph_EGA_Addr 0xb800
