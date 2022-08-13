include ../../config/makefile-build

C_SRC = $(wildcard *.c)
C_OBJ = $(patsubst %c, %o, $(C_SRC))  

S_SRC = $(wildcard *.S)
S_OBJ = $(patsubst %S, %o, $(S_SRC))  

s_SRC = $(wildcard *.s)
s_OBJ = $(patsubst %s, %o, $(s_SRC))  

CC_FLAGS=-I$(shell ./)../../includes

build: $(C_OBJ) $(S_OBJ) $(s_OBJ)
	cp $(C_OBJ) $(S_OBJ) $(s_OBJ) ../../Build 
#	cp $(C_OBJ) $(S_OBJ) $(s_OBJ) ../../Build
	rm *.o
makeISO-grub2:

%.o : %.c
	$(CC) -o $@ $(CC_FLAGS) -c $<  

%.o : %.S
	$(CC) -o $@ $(CC_FLAGS) -c $<  

%.o : %.s
	i686-elf-as -o $@ $(CC_FLAGS) -c $<  