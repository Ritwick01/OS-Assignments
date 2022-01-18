all: a

a: a.c
	nasm -f elf64 -o funcB.o funcB.asm
	gcc -no-pie a.c funcB.o -o a

clean:
	rm *.o a