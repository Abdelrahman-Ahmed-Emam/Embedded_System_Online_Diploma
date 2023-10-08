#prepared by Eng.Abdelrahman
CC=arm-none-eabi-#toolchain
CFLAGS=-mcpu=arm926ej-s  -g #the microcontroller name and with debug info
INCS= -I . #include header files
LIBS= #Libraries used
SRC= $(wildcard *.c) #all files with extension .c
OBJ= $(SRC:.c=.o) #all files.c turned into files.o
As= $(wildcard *.s) #all files with extension .s
AsOBJ= $(As:.s=.o) #all files.s turned into files.o
Project_name=learn-in-depth#project name which will be the .bin or .elf file
##########################################################################################################
all: $(Project_name).bin 
	@echo "--------Build is done----------"

%.o: %.s
	$(CC)as.exe $(CFLGAS) $< -o $@ 
	@echo "-------All assembly files are built----------"

%.o: %.c
	$(CC)gcc.exe $(CFLAGS) $(INCS) -c $< -o $@
	@echo "-------All C files are built-------------"

$(Project_name).elf: $(OBJ) $(AsOBJ)
	$(CC)ld.exe -T linker_script.ld $(LIBS) $(OBJ) $(AsOBJ) -o $@ -Map=Map_File.map
	@echo "----------The elf file is built-----------"

$(Project_name).bin: $(Project_name).elf
	$(CC)objcopy.exe -O binary $< $@

clean_all:
	rm *.o *.elf *.bin 

clean:
	rm *.elf *.bin 





