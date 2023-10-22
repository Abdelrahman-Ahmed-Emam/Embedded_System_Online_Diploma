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
        *(.rodata*)
        . = ALIGN(4);
        _E_Text = . ;
    } >flash

    .data : {
        _S_Data = . ;
        *(.data)
        *(.data.*)
        . = ALIGN(4);
        _E_Data = . ;
        _D_Size = _E_Data - _S_Data ; 
    } >sram AT> flash


    .bss : 
    {
        _S_bss = . ;
        *(.bss)
        *(.bss.*)
        . = ALIGN(4);
        _E_bss = . ;
        . = ALIGN(4);
    } >sram
     . = . + 0x1000 ;
     _heap_end = . ;
     . = ALIGN(4);
     . = . +0X1000 ;
        stack_top = . ;
}