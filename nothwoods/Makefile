CC=clang
CFLAGS=-g -Wall

EXEC=nothwoods

all: $(EXEC)

main.o: main.c nothwoods.h

type_seq.o: type_seq.c type_seq.h

nothwoods.o: nothwoods.c nothwoods.h type_seq.h

$(EXEC): main.o type_seq.o nothwoods.o
	$(CC) $(CFLAGS) $^ -o $(EXEC)

%.o: %.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f *.o

clear:
	rm -f $(EXEC)
