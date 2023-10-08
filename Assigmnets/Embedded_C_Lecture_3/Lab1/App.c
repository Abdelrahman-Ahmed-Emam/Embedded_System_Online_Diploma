#include "Uart.h"
unsigned char message[] = "learn-in-depth: <Abdelrahman>";
void main(void)
{
    Uart_Send_text(message);
}