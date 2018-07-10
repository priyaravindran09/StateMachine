all:
	gcc -Wall -g main.c -o main
clean:
	rm -rf *.o main *.dSYM main
