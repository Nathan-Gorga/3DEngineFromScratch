
CC = clang
CFLAGS = -std=c99 -Wall -Wpedantic

3DEngine : main.o shapes.o draw.o init.o matrix_math.o matrix_projection.o matrix_translation.o camera.o matrix_rotation.o run.o
	$(CC) main.o shapes.o draw.o init.o matrix_math.o matrix_projection.o matrix_translation.o camera.o matrix_rotation.o run.o -lm -lSDL2 -o 3DEngine
	make clean
	./3DEngine


main.o : 3DEngine.c
	$(CC) $(CFLAGS) -c 3DEngine.c -o main.o 

shapes.o : shapes/basic_shapes/basic_shapes.c
	$(CC) $(CFLAGS) -c shapes/basic_shapes/basic_shapes.c -o shapes.o



draw.o : SDL_interface/draw/draw.c 
	$(CC) $(CFLAGS) -c SDL_interface/draw/draw.c -o draw.o

init.o : SDL_interface/init/init.c
	$(CC) $(CFLAGS) -c SDL_interface/init/init.c -o init.o



matrix_math.o : matrix_operations/math/math.c
	$(CC) $(CFLAGS) -c matrix_operations/math/math.c -o matrix_math.o

matrix_projection.o : matrix_operations/projection/projection.c
	$(CC) $(CFLAGS) -c matrix_operations/projection/projection.c -o matrix_projection.o


matrix_translation.o : matrix_operations/translation/translation.c
	$(CC) $(CFLAGS) -c matrix_operations/translation/translation.c -o matrix_translation.o

matrix_rotation.o : matrix_operations/rotation/rotation.c
	$(CC) $(CFLAGS) -c matrix_operations/rotation/rotation.c -o matrix_rotation.o


camera.o : camera/camera.c
	$(CC) $(CFLAGS) -c camera/camera.c -o camera.o


run.o : run/run.c
	$(CC) $(CFLAGS) -c run/run.c -o run.o

clean:
	rm -f *.o 




