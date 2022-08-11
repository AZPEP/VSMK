include ../config/makefile-build
C_SRC = $(wildcard *.c)
C_OBJ = $(patsubst %c, %o, $(C_SRC))  


CC_FLAGS=-I$(shell ./)../includes -m32

build: $(C_OBJ)
	cp $(C_OBJ) ../Build
	rm *.o
makeISO-grub2:

%.o : %.c
	$(CC) -o $@ $(CC_FLAGS) -c $<  