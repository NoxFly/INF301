CC=clang
CFLAGS=-g -Wall

EXEC=app1

all: $(EXEC)

# Executables recipes
app1: main.o client.o caesar.o char_seq.o type_char_seq.o
	$(CC) $(CFLAGS) $^ -o $@

# Dependencies
main.o: main.c client.h caesar.h char_seq.h type_char_seq.h

client.o: client.c client.h

caesar.o: caesar.c caesar.h client.h

type_char_seq.o: type_char_seq.c type_char_seq.h

char_seq.o: char_seq.c char_seq.h type_char_seq.h client.h

# Objects compilation recipe
%.o: %.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f *.o

clear:
	rm -f $(EXEC)
