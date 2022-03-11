CC		= gcc
CFLAGS	= -W -std=c17
TARGET	= hello-world

.PHONY: default clean

default:
	$(CC) $(CFLAGS) -o $(TARGET) src/hello-world.c

clean :
	rm -rf *.o $(TARGET)
