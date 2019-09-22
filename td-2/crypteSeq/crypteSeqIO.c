#include <stdio.h>
#include <string.h>
#include "char_seq.h"

/*
 *  Auteur(s) :
 *  Date :
 *  Suivi des Modifications :
 *
 */


#define BUFSIZE 512
#define MAXSEQ 512

/*
 *  Encrypts the given buffer
 *
 *  dest: a string where the encrypted string will be copied
 *  src: the string to encrypt
 *  seq: the encryption sequence
 */
void encrypt(char dest[BUFSIZE], char src[BUFSIZE], char_seq *seq) {
	char c;
	int i = 0, idx = 0;

	// Loop through each letter in the buffer
	for (i = 0; src[i] != '\0'; i++) {
		c = src[i];
		idx = pos(c, seq);

		if (idx != -1) {
			if (idx == 0) {
				dest[i] = seq->items[seq->length - 1];
			} else {
				dest[i] = seq->items[idx - 1];
			}
			swap_end(idx, seq);
		} else {
			dest[i] = c;
			append(c, seq);
		}
	}

	// Add end of string at the end of the output string
	dest[i] = '\0';
}

int main() {
    char c, buffer[BUFSIZE], enc[BUFSIZE];
    char_seq seq;

    init_char_seq(&seq);

	fscanf(stdin, "%c", &c);
    while(!feof(stdin)) {

    	buffer[0] = c;
    	buffer[1] = '\0';

    	encrypt(enc, buffer, &seq);

    	printf("%s", enc);

    	fscanf(stdin, "%c", &c);
    }
    
    printf("\n");

    return 0;
}
