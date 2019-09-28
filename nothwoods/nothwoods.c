#include "nothwoods.h"
#include "type_seq.h"

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

void decrypt(char dest[BUFSIZE], char src[BUFSIZE], Seq *seq) {
	// tbd
}
