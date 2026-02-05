CC = gcc
CFLAGS = -Wall -fPIC
LDFLAGS = -shared

LIB = libdisplay.so
LIBSRC = display.c
CLIENT = client
CLIENTSRC = client.c

all: $(LIB) $(CLIENT)

$(LIB): $(LIBSRC)
	$(CC) $(CFLAGS) $(LDFLAGS) $(LIBSRC) -o $(LIB)

$(CLIENT): $(CLIENTSRC)
	$(CC) $(CLIENTSRC) -L. -ldisplay -o $(CLIENT)

run:
	export LD_LIBRARY_PATH=.; ./$(CLIENT)

clean:
	rm -f $(LIB) $(CLIENT)
