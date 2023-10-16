/*Learn-in-depth
    Eng.Abdelrahman */



MEMORY
{
    flash(rx) : ORIGIN = 0x00000000 , LENGTH = 512M
    sram(rwx) : ORIGIN = 0x20000000 , LENGTH = 512M
}

SECTIONS
{
    .text : {
        _S_Text = . ;
        *(.vectors*) 
        *(.text*)
        *(.rodata*)
        . = ALIGN(4);
        _E_Text = . ;
    } >flash

    .data : {
        _S_Data = . ;
        *(.data)
        . = ALIGN(4);
        _E_Data = . ;
        _D_Size = _E_Data - _S_Data ; 
    } >sram AT> flash


    .bss : 
    {
        _S_bss = . ;
        *(.bss)
        . = ALIGN(4);
        _E_bss = . ;
        . = ALIGN(4);
    } >sram
    
}