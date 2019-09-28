CC=clang
CFLAGS=-g -Wall

EXEC=nothwoods io

all: $(EXEC)

nothwoods: main.o type_seq.o nothwoods.o
	$(CC) $(CFLAGS) $^ -o $@
	
io: io.o type_seq.o nothwoods.o
	$(CC) $(CFLAGS) $^ -o $@

io.o: io.c nothwoods.h

main.o: main.c nothwoods.h

type_seq.o: type_seq.c type_seq.h

nothwoods.o: nothwoods.c nothwoods.h type_seq.h

%.o: %.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f *.o

clear:
	rm -f $(EXEC)
