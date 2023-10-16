#include "Platforms_Type.h"
#include "TivaC.h"

volatile Registers *SYSCTL_ENABLE = (volatile Registers *)SYSCTL_RCGC2_R;
volatile Registers *GPIO_F_DATA = (volatile Registers *)GPIOF_DATA_R;
volatile Registers *GPIO_F_DEN = (volatile Registers *)GPIOF_DEN_R;
volatile Registers *GPIO_F_DIR = (volatile Registers *)GPIOF_DIR_R;
vuint32_t counter = 0;

int main(void)
{
    SYSCTL_ENABLE->All_Pins = 0X00000020;
    for (counter = 0; counter < 400; counter++)
        ;
    GPIO_F_DEN->pins.pin3 = 1;

    GPIO_F_DIR->pins.pin3 = 1;
    while (1)
    {
        GPIO_F_DATA->pins.pin3 = 1;
        for (counter = 0; counter < 500000; counter++)
            ;
        GPIO_F_DATA->pins.pin3 = 0;
        for (counter = 0; counter < 500000; counter++)
            ;
    }
    return 0;
}
