CC = gcc
CFLAGS = -Wall -fPIC
LDFLAGS = -shared

HELPER_LIB = libhelper.so
PERFECT_LIB = libperfect.so

all: $(HELPER_LIB) $(PERFECT_LIB) main


$(HELPER_LIB): helper.o
	$(CC) $(LDFLAGS) -o $(HELPER_LIB) helper.o

helper.o: helper.c helper.h
	$(CC) $(CFLAGS) -c helper.c


$(PERFECT_LIB): perfect.o
	$(CC) $(LDFLAGS) -o $(PERFECT_LIB) perfect.o -L. -lhelper

perfect.o: perfect.c perfect.h helper.h
	$(CC) $(CFLAGS) -c perfect.c


main: main.c
	$(CC) main.c -L. -lperfect -lhelper -o main


clean:
	rm -f *.o *.so main