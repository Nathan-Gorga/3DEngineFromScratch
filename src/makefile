CC = clang
CFLAGS = -std=c99 -Wall -Wpedantic

3DEngine : main.o 
	$(CC) main.o -lSDL2 -o 3DEngine
	make clean
	clear
	./3DEngine


main.o : main.c
	$(CC) $(CFLAGS) -c main.c -o main.o 


clean:
	rm -f *.o 




