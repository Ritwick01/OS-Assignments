all: Q1a Q1b

Q1a: Q1a.c
	gcc -S Q1a.c
	gcc -c Q1a.c
	gcc Q1a.c -o Q1a

Q1b: Q1b.c
	gcc -S Q1b.c
	gcc -c Q1b.c
	gcc Q1b.c -pthread -o Q1b

clean:
	rm *.o *.s Q1a Q1b
