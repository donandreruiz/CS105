#
#
# Student makefile for Cache Lab
# Note: requires a 64-bit x86-64 system
#
CC = gcc
CFLAGS = -g -Wall -Werror

ringbuf: ringbuf.o
	$(CC) $(CFLAGS) -o ringbuf ringbuf.o -lpthread

#
# Clean the src dirctory
#
clean:
	rm -rf *.o
	rm -f *.tar
	rm -f ringbuf
