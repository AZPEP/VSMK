/*
Stars OS - By AZPEP_BiliBili@Gitee

Include/Graph.h
*/

typedef unsigned short vga_attribute;

#define VGA_COLOR_BLACK 0
#define VGA_COLOR_BLUE 1
#define VGA_COLOR_GREEN 2
#define VGA_COLOR_CYAN 3
#define VGA_COLOR_RED 4
#define VGA_COLOR_MAGENTA 5
#define VGA_COLOR_BROWN 6
#define VGA_COLOR_DARK_GREY 8
#define VGA_COLOR_LIGHT_GREY 7
#define VGA_COLOR_LIGHT_BLUE 9
#define VGA_COLOR_LIGHT_GREEN 10
#define VGA_COLOR_LIGHT_CYAN 11
#define VGA_COLOR_LIGHT_RED 12
#define VGA_COLOR_LIGHT_MAGENTA 13
#define VGA_COLOR_LIGHT_BROWN 14
#define VGA_COLOR_WHITE 15

#include "BootLoader/multiboot.h"

void Graph_Set_Theme(vga_attribute FontColor, vga_attribute BackColor);

void Graph_Put_Char(char chr);
void Graph_Put_Str(char *str);
void Screen_Scrool_Up();
void Graph_Clear_Screen();


#define Graph_EGA_Addr 0xb800
