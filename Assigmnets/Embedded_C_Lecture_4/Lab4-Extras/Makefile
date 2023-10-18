#prepared by Eng.Abdelrahman
CC=arm-none-eabi-#toolchain
CFLAGS=-mcpu=cortex-m4	-gdwarf-2	 #the microcontroller name and with debug info
INCS= -I .    #include header files
LIBS= #Libraries used
SRC= $(wildcard *.c) #all files with extension .c
OBJ= $(SRC:.c=.o) #all files.c turned into files.o
As= $(wildcard *.s) #all files with extension .s
AsOBJ= $(As:.s=.o) #all files.s turned into files.o
Project_name=Lab4Extra#project name which will be the .bin or .elf file
##########################################################################################################
all: $(Project_name).hex
	@echo "--------Build is done----------"

%.o: %.s
	$(CC)as.exe $(CFLGAS) $< -o $@ 
	@echo "-------All assembly files are built----------"

%.o: %.c
	$(CC)gcc.exe $(CFLAGS) $(INCS) -c $< -o $@
	@echo "-------All C files are built-------------"

$(Project_name).elf: $(OBJ) $(AsOBJ)
	$(CC)ld.exe -T linker_script.ld $(LIBS) $(OBJ) $(AsOBJ) -o $@ -Map=Map_File.map
	cp $(Project_name).elf $(Project_name).axf
	@echo "----------The elf file is built-----------"

$(Project_name).bin: $(Project_name).elf
	$(CC)objcopy.exe -O binary $< $@



$(Project_name).hex: $(Project_name).elf
	$(CC)objcopy.exe -O ihex $< $@
clean_all:
	rm *.o *.elf *.hex

clean:
	rm *.elf *.bin 





