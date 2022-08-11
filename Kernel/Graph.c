#include <Graph.h>
#include <stdint.h>

vga_attribute *Graph_Addr = 0xb8000;
vga_attribute Theme_Color = VGA_COLOR_BLACK;

uint32_t Now_Graph_Column = 0;
uint32_t Now_Graph_Row = 0;

#define Screen_Width 80
#define Screen_Height 25

void Graph_Set_Theme(unsigned short FontColor, unsigned short BackColor)
{
	//设置主题颜色
	Theme_Color = (BackColor << 4 | FontColor) << 8;
}

void Graph_Put_Char(char chr)
{
	if (chr == '\n')
	{
		Now_Graph_Column = 0;
		Now_Graph_Row++;
	}
	else if (chr == '\r')
	{
		Now_Graph_Column = 0;
	}
	else
	{
		*(Graph_Addr + Now_Graph_Column + Now_Graph_Row * Screen_Width) = (Theme_Color | chr);
		Now_Graph_Column++;
		if (Now_Graph_Column >= Screen_Width)
		{
			Now_Graph_Column = 0;
			Now_Graph_Row++;
		}
	}

	if (Now_Graph_Row >= Screen_Height)
	{
		Screen_Scrool_Up();
		Now_Graph_Row--;
	}
}

void Graph_Put_Str(char *str)
{
	//我们打算做一个近似于标准的Print函数
	while (*str != '\0')
	{
		Graph_Put_Char(*str);
		str++;
	}
}

void Screen_Scrool_Up()
{
	/*
		代码暂时无法实现
		需要编写memcpy()
	*/
}

void Graph_Clear_Screen()
{
	/*
	清屏指令
	通过遍历方式
	*/

	for (uint32_t x = 0; x < Screen_Height; x++)
	{
		for (uint32_t y = 0; y < Screen_Width; y++)
		{
			*(Graph_Addr + y * Screen_Width + x) = Theme_Color;
		}
	}
}