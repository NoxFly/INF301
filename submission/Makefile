CC=clang
CFLAGS=-g -Wall

EXEC=app1

all: $(EXEC)

app1: client.o main.o caesar.o
	$(CC) $(CFLAGS) $^ -o $@

client.o: client.c client.h

caesar.o: caesar.c caesar.h

main.o: main.c client.h caesar.h

%.o: %.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f *.o

clear:
	rm -f $(EXEC)
