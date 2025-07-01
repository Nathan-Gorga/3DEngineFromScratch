# Compiler and flags
CC = clang
CFLAGS = -std=c99 -Wall -Wpedantic

# Directories
SRC_DIRS = . shapes/basic_shapes SDL_interface/draw SDL_interface/init \
           matrix_operations/math matrix_operations/projection \
           matrix_operations/translation matrix_operations/rotation \
           camera run FUNDAMENTAL_OP

# Source files
SRCS = \
  3DEngine.c \
  shapes/basic_shapes/basic_shapes.c \
  SDL_interface/draw/draw.c \
  SDL_interface/init/init.c \
  matrix_operations/math/math.c \
  matrix_operations/projection/projection.c \
  matrix_operations/translation/translation.c \
  matrix_operations/rotation/rotation.c \
  camera/camera.c \
  run/run.c \
  FUNDAMENTAL_OP/fundamental_op.c

# Object files (replace .c with .o)
OBJS = $(SRCS:.c=.o)

# Output binary
TARGET = 3DEngine

# Default target
all: $(TARGET)
	@$(MAKE) clean
	@./$(TARGET)

# Link step
$(TARGET): $(OBJS)
	$(CC) $(OBJS) -lm -lSDL2 -lSDL2_gfx -o $@
	@echo "Build complete."
	

# Pattern rule for compiling .c to .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up
clean:
	rm -f $(OBJS)
