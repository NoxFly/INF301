#include <stdio.h>
#include <string.h>

#include "nothwoods.h"

/*
 *  Auteur(s) :
 *  Date :
 *  Suivi des Modifications :
 *
 */

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
