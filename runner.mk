all:
	make ./Makefile.mk
	gcc runner.c -o ./build/runner.exe
	./build/runner