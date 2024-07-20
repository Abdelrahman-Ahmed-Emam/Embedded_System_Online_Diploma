/* Learn in depth
    Eng.Abdelrahman     */
#include "Platforms_Type.h"
extern uint32 stack_top;
extern uint32 _S_Text;
extern uint32 _E_Text;
extern uint32 _S_Data;
extern uint32 _E_Data;
extern uint32 _D_Size;
extern uint32 _S_bss;
extern uint32 _E_bss;
extern int main(void);

void Reset_Handler();
void Default_Handler()
{
    Reset_Handler();
}
void NMI_Handler(void) __attribute__((weak, alias("Default_Handler")));
void Hard_fault_Handler(void) __attribute__((weak, alias("Default_Handler")));
void MM_Fault_Handler(void) __attribute__((weak, alias("Default_Handler")));
void Bus_Fault_Handler(void) __attribute__((weak, alias("Default_Handler")));
void Usage_Fault_Handler(void) __attribute__((weak, alias("Default_Handler")));

uint32 vectors[] __attribute__((section(".vectors"))) = {

    (uint32)&stack_top,
    (uint32)&Reset_Handler,
    (uint32)&NMI_Handler,
    (uint32)&Hard_fault_Handler,
    (uint32)&MM_Fault_Handler,
    (uint32)&Bus_Fault_Handler,
    (uint32)&Usage_Fault_Handler};

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
