clean:
	python3 ./tools/dir.py rmdir Build DisErr

make_build: clean
	python3 ./tools/dir.py mkdir Build DisErr