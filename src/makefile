CC = clang
CFLAGS = -std=c99 -Wall -Wpedantic

3DEngine : main.o renderer.o draw.o
	$(CC) main.o renderer.o draw.o -lSDL2 -o 3DEngine
	make clean
	./3DEngine


main.o : main.c
	$(CC) $(CFLAGS) -c main.c -o main.o 


renderer.o : renderer/renderer.c
	$(CC) $(CFLAGS) -c renderer/renderer.c -o renderer.o

draw.o : draw/draw.c
	$(CC) $(CFLAGS) -c draw/draw.c -o draw.o

clean:
	rm -f *.o 




