/*Learn-in-depth
    Eng.Abdelrahman */



MEMORY
{
    flash(rx) : ORIGIN = 0x08000000 , LENGTH = 128K
    sram(rwx) : ORIGIN = 0x20000000 , LENGTH = 20K
}

SECTIONS
{
    .text : {
        _S_Text = . ;
        *(.vectors*) 
        *(.text*)
        . = ALIGN(4);
        *(.rodata*)
        _E_Text = . ;
    } >flash

    .data : {
        _S_Data = . ;
        *(.data)
        . = ALIGN(4);
        _E_Data = . ;
        _D_Size = _E_Data - _S_Data ; 
    } >sram AT> flash

    .interrupts : {
        _S_Interr = . ;
        *(.interrupts-of-vector-table)
        . = ALIGN(4);
        *(.not_used)
        _E_Interr = . ;
    }>flash

    .bss : 
    {
        _S_bss = . ;
        *(.bss)
        . = ALIGN(4);
        _E_bss = . ;
        . = ALIGN(4);
    } >sram

     . = . + 0x1000 ;
        stack_top = . ;
        
}