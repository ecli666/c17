CC	= gcc
CFLAGS	= -W -std=c17
TARGET	= gcc-asm

.PHONY: default clean

default:
	$(CC) $(CFLAGS) -o $(TARGET) src/gcc-asm.c

clean :
	rm -rf *.o $(TARGET)
