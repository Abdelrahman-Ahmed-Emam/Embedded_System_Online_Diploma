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
        . = ALIGN(4);
        *(.vectors*) 
        *(.text*)
       
    } >flash

   
    .bss : 
    {  . = ALIGN(4);
        *(.bss)
       
    } >sram
     . = . + 0x1000 ;
        stack_top = . ;
}