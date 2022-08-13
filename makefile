include config/makefile-build
buildBootLoader-grub2:
	make -C BootLoader/GRUB2 build

build-other:
	make -C Kernel/ build

clean:
	python3 ./tools/dir.py rmdir Build DisErr

make_build: clean
	python3 ./tools/dir.py mkdir Build DisErr


build-grub2: make_build buildBootLoader-grub2 build-other 
	cp makefile_build.inc Build/makefile

	make -C Build Link
makeISO-grub2: build-grub2
	make -C Build makeISO_grub2

makeISO-grub2-debug:
	make -C Build makeISO_grub2_debug

debug-qemu-grub2: makeISO-grub2-debug
	qemu-system-i386 -cdrom ./ISO/Debug.iso

debug-bochs-grub2:
	bochs -f bochsrc-debug -q