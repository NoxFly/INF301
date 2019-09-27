CC=clang
CFLAGS=-g -Wall

EXEC=nothwoods

all: $(EXEC)

seq.o: seq.c seq.h

nothwoods.o: nothwoods.c seq.h

$(EXEC): seq.o nothwoods.o
	$(CC) $(CFLAGS) $^ -o $(EXEC)

%.o: %.c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f *.o

clear:
	rm -f $(EXEC)
