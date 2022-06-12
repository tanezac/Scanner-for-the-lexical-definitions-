CC = gcc
CFLAGS = -g -Wall -Wshadow 
DEPS = token.h character.h testScanner.h scanner.h testScanner.c scanner.c p1.c
OBJ = testScanner.o scanner.o p1.o
LDFLAGS = -static
OUTPUT = scanner

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c -o $@ $<
scanner: $(OBJ)
	$(CC)  $(CFLAGS) -o $@ $^

.PHONY: all clean
clean:
	/bin/rm -f $(OUTPUT) *.o *.log
