#include "Platforms_Type.h"

void Reset_Handler(void);
extern int main(void);
extern uint32 _S_Text;
extern uint32 _E_Text;
extern uint32 _S_Data;
extern uint32 _E_Data;
extern uint32 _D_Size;
extern uint32 _S_bss;
extern uint32 _E_bss;

void Default_Handler(void)
{
    Reset_Handler();
}
void NMI_Handler(void) __attribute__((weak, alias("Default_Handler")));
void Hard_fault_Handler(void) __attribute__((weak, alias("Default_Handler")));
void MM_Fault_Handler(void) __attribute__((weak, alias("Default_Handler")));
void Bus_Fault_Handler(void) __attribute__((weak, alias("Default_Handler")));
void Usage_Fault_Handler(void) __attribute__((weak, alias("Default_Handler")));

static uint32 Stack_Top[256];

void (*const A_P_Fun[])() __attribute__((section(".vectors"))) = {

    (void (*)())((uint32 *)Stack_Top + sizeof(Stack_Top)),
    &Reset_Handler,
    &NMI_Handler,
    &Hard_fault_Handler,
    &MM_Fault_Handler,
    &Bus_Fault_Handler,
    &Usage_Fault_Handler};

void Reset_Handler()
{
    uint32 DATA_SIZE = (uint8 *)&_E_Data - (uint8 *)&_S_Data;
    uint8 *P_src = (uint8 *)&_E_Text;
    uint8 *P_dst = (uint8 *)&_S_Data;
    int i = 0;
    for (; i < DATA_SIZE; i++)
    {
        *((uint8 *)P_dst++) = *((uint8 *)P_src++);
    }

    uint32 BSS_SIZE = (uint8 *)&_E_bss - (uint8 *)&_S_bss;
    P_dst = (uint8 *)&_S_bss;
    for (i = 0; i < BSS_SIZE; i++)
    {
        *((uint8 *)P_dst++) = ((uint8)0);
    }

    main();
}