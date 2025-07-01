CC = gcc
CFLAGS = -Wall

Target = weather

SRC = $(wildcard src/*.c)
# searches for all *.c files in the src directory
HEADERS = $(wildcard src/headers/*.h)
# searches for all *.h files in the src/headers directory

OBJ = $(SRC:.c=.o)

$(TARGET): $(OBJ) 
	$(CC) $(OBJ) -o $(TARGET)

# Make object files beforehand and compile only the changes *.c files 
#results in faster execution.
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean
clean:
	rm -f $(TARGET) $(OBJ)