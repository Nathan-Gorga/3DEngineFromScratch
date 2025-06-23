CC = clang
CFLAGS = -std=c99 -Wall -Wpedantic

3DEngine : main.o renderer.o draw.o shape.o
	$(CC) main.o renderer.o draw.o shape.o -lm -lSDL2 -o 3DEngine
	make clean
	./3DEngine


main.o : main.c
	$(CC) $(CFLAGS) -c main.c -o main.o 


renderer.o : renderer/renderer.c
	$(CC) $(CFLAGS) -c renderer/renderer.c -o renderer.o

draw.o : draw/draw.c
	$(CC) $(CFLAGS) -c draw/draw.c -o draw.o

shape.o : shape/shape.c
	$(CC) $(CFLAGS) -c shape/shape.c -o shape.o

clean:
	rm -f *.o 




