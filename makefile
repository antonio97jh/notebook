CC = gcc

CFLAGS = -Wall -Wextra $(INCLUDE) $(LIBS)

INCLUDE = -I./include

LIBS = -lncurses

SRCS = src/main.c src/core/Cursor.c src/core/Editor.c src/io/file.c

TARGET = gnotes

all: $(TARGET)

$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) -o $(TARGET)

clean:
	rm -f $(TARGET)