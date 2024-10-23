CC = clang
CFLAGS = -Wall -Werror -Wextra -Wpedantic

all: txtedit

txtedit: txtedit.o
	$(CC) -o txtedit txtedit.o

txtedit.o: txtedit.c
	$(CC) $(CFLAGS) -c txtedit.c

clean:
	rm -f txtedit txtedit.o