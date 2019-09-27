#include <stdio.h>
#include <string.h>

#include "seq.h"

/*
 *  Auteur(s) :
 *  Date :
 *  Suivi des Modifications :
 *
 */


#define BUFSIZE 512
#define MAXSEQ 512

void printSeq(Seq seq) {
	printf("Length: %d\n", seq.length);
	for (int i = 0; i < seq.length; ++i)
	{
		printf("(%c, %c)\n", seq.items[i].reference, seq.items[i].image);
	}
}

int main() {
    
	Seq seq;
	init_seq(&seq);

	add('a', &seq);
	add('b', &seq);
	add('c', &seq);
	add('d', &seq);

	printf("pos(c) = %d\n", pos('p', &seq));
	printSeq(seq);

	swap(0, 2, &seq);
	printSeq(seq);

	printf("%c\n", value_of(2, &seq));

	move_end(1, &seq);
	printSeq(seq);

	add('e', &seq);
	add('f', &seq);
	add('g', &seq);
	add('o', &seq);
	add('p', &seq);
	add('q', &seq);
	add('z', &seq);
	printSeq(seq);

    return 0;
}
