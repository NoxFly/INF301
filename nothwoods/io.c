#include <stdio.h>
#include <string.h>

#include "nothwoods.h"

int main() {
    char c, buffer[BUFSIZE], enc[BUFSIZE];
    Seq seq;

    init_seq(&seq);

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
