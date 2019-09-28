#include <stdio.h>
#include <stdbool.h>

#include "caesar.h"

void shift(char dest[BUFSIZE], char src[BUFSIZE], int offset) {
	int i;
	char c, ascii_offset;

	for (i = 0; src[i] != '\0'; i++) {
		c = src[i];

		// Déterminer si le caractère est dans l'alphabet
		if (('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z')) {

			// Calcul du decalage ascii du caractere
			ascii_offset = 'A';
			if (c >= 'a')
				ascii_offset = 'a';

			// Determination de la position de la lettre dans
			// l'alphabet (0...25) et decalage
			c = ((c - ascii_offset) + offset) % 26;

			// Normalisation du caractere decale
			if (c < 0)
				c +=	 26;

			// Calcul du caractere dans le tableau ascii
			c += ascii_offset;
		}

		dest[i] = c;
	}

	dest[i] = '\0';
}

void caesar_encrypt(char dest[BUFSIZE], char src[BUFSIZE], int key) {
	shift(dest, src, key);
}

void caesar_decrypt(char dest[BUFSIZE], char src[BUFSIZE], int key) {
	shift(dest, src, -key);
}

int caesar_key(char encrypted, char comparison) {
	int key = (encrypted - comparison) % 26;

	if (key < 0)
		return key + 26;

	return key;
}
