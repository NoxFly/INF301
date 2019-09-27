#include <stdio.h>
#include <string.h>

/*
 *  Auteur(s) :
 *  Date :
 *  Suivi des Modifications :
 *
 */


#define BUFSIZE 512
#define MAXSEQ 512

/*
 *  Trouve la position de l'element c dans une sequence de char
 *
 *  c: l'element qu'on cherche trouver
 *  seq: la sequence
 *
 *  returns: the index of the char c in the sequence, returns -1 if the char does not exist in the sequence
 */
int seq_index(char c, char *seq) {
	int i;

	for (i = 0; seq[i] != '\0'; i++) {
		if (seq[i] == c)
			return i;
	}

	return -1;
}

void move_to_end(int idx, char *seq) {
	int i;
	char tmp = seq[idx];

	// Decalage des elements à la droite de idx par 1 vers la gauche
	for (i = idx; seq[i + 1] != '\0'; i++) {
		seq[i] = seq[i + 1];
	}

	// Placement de c à la fin de la sequence
	seq[i] = tmp;
}

void append(char c, char *seq) {
	int i = 0;

	// Comptage des elements de la liste
	while (seq[i] != '\0')
		i++;

	// Ajout de l'element c
	seq[i] = c;
	seq[i + 1] = '\0';
}

/*
 *  Encrypts the given buffer
 *
 *  dest: a string where the encrypted string will be copied
 *  src: the string to encrypt
 *  seq: the encryption sequence
 */
void encrypt(char dest[BUFSIZE], char src[BUFSIZE], char seq[MAXSEQ]) {
	char c;
	int i = 0, idx = 0;

	// Loop through each letter in the buffer
	for (i = 0; src[i] != '\0'; i++) {
		c = src[i];
		idx = seq_index(c, seq);

		if (idx != -1) {
			if (idx == 0) {
				dest[i] = c;
			} else {
				dest[i] = seq[idx - 1];
				move_to_end(idx, seq);
			}
		} else {
			dest[i] = c;
			append(c, seq);
		}
	}

	// Add end of string at the end of the output string
	dest[i] = '\0';
}

int main() {
    char c, buffer[BUFSIZE], enc[BUFSIZE], seq[MAXSEQ];

	fscanf(stdin, "%c", &c);
    while(!feof(stdin)) {

    	buffer[0] = c;
    	buffer[1] = '\0';

    	encrypt(enc, buffer, seq);

    	printf("%s", enc);

    	fscanf(stdin, "%c", &c);
    }
    
    printf("\n");

    return 0;
}
