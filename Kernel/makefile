C_SRC = $(wildcard *.c)
C_OBJ = $(patsubst %c, %o, $(C_SRC))  

CC=i686-elf-gcc
CC_FLAGS=-I$(shell ./)../includes

build: $(C_OBJ)
	cp $(C_OBJ) ../Build
%.o : %.c
	$(CC) -o $@ $(CC_FLAGS) -c $<  