buildBootLoader-grub2:
	make -C BootLoader/GRUB2 build

build-other:
	make -C Kernel/ make build

clean:
	python3 ./tools/dir.py rmdir Build DisErr

make_build: clean
	python3 ./tools/dir.py mkdir Build DisErr

build-grub2: make_build buildBootLoader-grub2 build-other 
	cp make_build.inc Build/makefile

	make -C Build makeISO