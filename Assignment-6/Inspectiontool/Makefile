CC = gcc
CFLAGS = -Wall
TARGET = inspect
SRC = inspect.c
LIBSRC = testlib.c
LIB = libtest.so

all: $(LIB) $(TARGET)

$(LIB): $(LIBSRC)
	$(CC) -fPIC -shared $(LIBSRC) -o $(LIB)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -ldl -o $(TARGET)

run: all
	./$(TARGET) ./$(LIB) testfunc

clean:
	rm -f $(TARGET) $(LIB)
