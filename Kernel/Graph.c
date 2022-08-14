#include <Graph.h>
#include <stdint-gcc.h>

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
	
	//Now_Graph_Column=0;
	//Now_Graph_Row++;
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
			*(Graph_Addr + x * Screen_Width + y) = Theme_Color;
		}
	}

	Now_Graph_Column=0;
	Now_Graph_Row=0;
}


static void itoa (char *buf, int base, int d)
{
    char *p = buf;
    char *p1, *p2;
    unsigned long ud = d;
    int divisor = 10;
 
    /* 如果指定了 %d 并且 D 是负数，在开始添上负号。 */
    if (base == 'd' && d < 0)
    {
        *p++ = '-';
        buf++;
        ud = -d;
    }
    else if (base == 'x')
        divisor = 16;
 
    /* 用 DIVISOR 去除 UD 直到 UD == 0。 */
    do
    {
        int remainder = ud % divisor;
 
        *p++ = (remainder < 10) ? remainder + '0' : remainder + 'a' - 10;
    }
    while (ud /= divisor);
 
    /* 在字符串尾添上终结符。 */
    *p = 0;
 
    /* 反转 BUF。 */
    p1 = buf;
    p2 = p - 1;
    while (p1 < p2)
    {
        char tmp = *p1;
        *p1 = *p2;
        *p2 = tmp;
        p1++;
        p2--;
    }
}


/* 格式化字符串并在屏幕上输出，就像 libc 函数 printf 一样。 */
void printf (const char *format, ...)
{
    char **arg = (char **) &format;
    int c;
    char buf[20];
 
    arg++;
 
    while ((c = *format++) != 0)
    {
        if (c != '%')
            Graph_Put_Char (c);
        else
        {
            char *p;
 
            c = *format++;
            switch (c)
            {
            case 'd':
            case 'u':
            case 'x':
                itoa (buf, c, *((int *) arg++));
                p = buf;
                goto string;
                break;
 
            case 's':
                p = *arg++;
                if (! p)
                    p = "(null)";
 
string:
                while (*p)
                    Graph_Put_Char (*p++);
                break;
 
            default:
                Graph_Put_Char (*((int *) arg++));
                break;
            }
        }
    }
}