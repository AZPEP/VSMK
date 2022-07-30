build-grub2:
	make -C BootLoader/GRUB2
clean:
	python3 ./tools/dir.py rmdir Build DisErr

make_build: clean
	python3 ./tools/dir.py mkdir Build DisErr

Cross_Toolkit:
	