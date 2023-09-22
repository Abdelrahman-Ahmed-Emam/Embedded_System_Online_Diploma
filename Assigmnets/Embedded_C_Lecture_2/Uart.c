#include "Uart.h"
#include "platforms_Type.h"
#define UARTODR *((vuint32_t *)((uint32 *)0x101f1000))
void Uart_Send_text(unsigned char *text)
{
    while (*text != '\0')
    {
        UARTODR = (uint32)*text;
        text++;
    }
}