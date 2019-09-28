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

void encrypt(char dest[BUFSIZE], char src[BUFSIZE], Seq *seq) {
	char c;
	int i = 0, cpos = 0;

	// Loop through each letter in the buffer
	for (i = 0; src[i] != '\0'; i++) {
		c = src[i];
		cpos = pos(c, seq);

		if (cpos != -1) {
			if (cpos == 0) {
				dest[i] = value_of(seq->length - 1, seq);
			} else {
				dest[i] = value_of(cpos - 1, seq);
				swap(cpos, cpos - 1, seq);
			}
			move_end(cpos, seq);
		} else {
			dest[i] = c;
			add(c, seq);
		}
	}

	// Add end of string at the end of the output string
	dest[i] = '\0';
}

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

	char encrypted[BUFSIZE];
	char to_encrypt[BUFSIZE] = "abcbcca";
	char expected[BUFSIZE] = "abcabaa";

	printf("Input: %s\n", to_encrypt);
    
	encrypt(encrypted, to_encrypt, &seq);
    
	printf("Output: %s\n", encrypted);
    
	if (strcmp(encrypted, expected) == 0)
		printf("Pass!\n");
	else
		printf("Fail!\n");

    return 0;
}
