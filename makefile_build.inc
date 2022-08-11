include ../config/makefile-build
include ../config/build-grub2
cc=i686-elf-ld
cc_flags=-T ../lib/Kernel_Link_Map.lds

O_SRC = $(wildcard *.o)

makeISO_grub2:

	cp -r ../BootLoader/GRUB2/iso ./
	cp ./$(OSName)_$(Version) ./iso/boot

	echo default=0 >./iso/boot/grub/grub.cfg
	echo timeout=$(timeout) >>./iso/boot/grub/grub.cfg
	echo "" >>./iso/boot/grub/grub.cfg
	echo 'menuentry "$(OSName)_$(Version)" {' >>./iso/boot/grub/grub.cfg
	echo "multiboot /boot/$(OSName)_$(Version)" >>./iso/boot/grub/grub.cfg
	echo "}" >>./iso/boot/grub/grub.cfg

	grub-mkrescue -o $(OSName)_$(Version).iso ./iso

makeISO_grub2_debug:

	cp -r ../BootLoader/GRUB2/iso ./
	cp ./$(OSName)_$(Version) ./iso/boot

	echo default=0 >./iso/boot/grub/grub.cfg
	echo timeout=$(timeout) >>./iso/boot/grub/grub.cfg
	echo "" >>./iso/boot/grub/grub.cfg
	echo 'menuentry "$(OSName)_$(Version)" {' >>./iso/boot/grub/grub.cfg
	echo "multiboot /boot/$(OSName)_$(Version)" >>./iso/boot/grub/grub.cfg
	echo "}" >>./iso/boot/grub/grub.cfg

	grub-mkrescue -o Debug.iso ./iso
Link:
	$(cc) $(cc_flags) $(O_SRC) -o $(OSName)_$(Version)

	python3 ../tools/dir.py mkdir OBJ DisErr

	cp $(O_SRC) ./OBJ
	rm $(O_SRC)


#mkdir_ISO:
#	python3 ../tools/dir.py rmdir ../ISO DisErr
#	python3 ../tools/dir.py mkdir ../ISO DisErr

