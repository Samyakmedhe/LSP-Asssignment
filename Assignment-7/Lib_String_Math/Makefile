CC = gcc
CFLAGS = -Wall -fPIC
LDFLAGS = -shared

STRING_LIB = libmystring.so
MATH_LIB   = libmymath.so
CLIENT     = client

all: $(STRING_LIB) $(MATH_LIB) $(CLIENT)

$(STRING_LIB): mystring.o
	$(CC) $(LDFLAGS) mystring.o -o $(STRING_LIB)

mystring.o: mystring.c mystring.h
	$(CC) $(CFLAGS) -c mystring.c


$(MATH_LIB): mymath.o
	$(CC) $(LDFLAGS) mymath.o -o $(MATH_LIB)

mymath.o: mymath.c mymath.h
	$(CC) $(CFLAGS) -c mymath.c


$(CLIENT): client.c mystring.h mymath.h
	$(CC) client.c -L. -lmystring -lmymath -o $(CLIENT)


run: all
	export LD_LIBRARY_PATH=.; ./$(CLIENT)



clean:
	rm -f *.o *.so $(CLIENT)
