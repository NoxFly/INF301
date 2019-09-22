CC=clang
CFLAGS=-Wall -g

EXEC=crypteSeqIO appolab

all: $(EXEC)

crypteSeqIO: crypteSeqIO.o char_seq.o

appolab: appolab.o client.o

client.o: client.c client.h

char_seq.o: char_seq.c char_seq.h

clean:
	rm -f *.o

clear:
	rm -f $(EXEC)
