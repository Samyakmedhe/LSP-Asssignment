CC = gcc
CFLAGS = -Wall -fPIC
LDFLAGS = -ldl

LIB = libStringCount.so
CLIENT = client

all: library client

library:
	$(CC) $(CFLAGS) -shared StringCount.c -o $(LIB)

client:
	$(CC) client.c $(LDFLAGS) -o $(CLIENT)

run:
	export LD_LIBRARY_PATH=.; ./$(CLIENT)

clean:
	rm -f $(LIB) $(CLIENT)