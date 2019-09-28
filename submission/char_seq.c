#include <stdio.h>

#include "char_seq.h"
#include "type_char_seq.h"

void char_seq_encrypt(char dest[BUFSIZE], char src[BUFSIZE], Charseq *seq) {
	char c;
	int i = 0, cpos = 0;

	// Pour chaque caractere de l'entree
	for (i = 0; src[i] != '\0'; i++) {
		c = src[i];

		// Determination de la position de c dans la sequence
		cpos = char_seq_pos(c, seq);

		if (cpos != -1) {
			// si c existe dans la sequence
			if (cpos == 0) {
				// Si c se trouve au debut de la sequence, choisir le
				// dernier caractere de la sequence
				dest[i] = seq->items[seq->length - 1];
			} else {
				// sinon, choisir l'element qui precede c dans la sequence
				dest[i] = seq->items[cpos - 1];
			}
			// Deplacer le caractere lu à la fin de la sequence
			char_seq_move_end(cpos, seq);
		} else {
			// sinon, ajout de c dans la sequence
			dest[i] = c;
			char_seq_append(c, seq);
		}
	}

	// Ajout du caractere de fin de chaine de sortie
	dest[i] = '\0';
}

void char_seq_decrypt(char dest[BUFSIZE], char src[BUFSIZE], Charseq *seq) {
	char c;
	int i = 0, idx = 0;

	// Pour chaque caractere de l'entree
	for (i = 0; src[i] != '\0'; i++) {
		c = src[i];

		// Determination de la position de c dans la sequence
		idx = char_seq_pos(c, seq);

		if (idx != -1) {
			// si c existe dans la sequence
			if (idx == seq->length - 1) {
				// Si c se trouve a la fin de la sequence, choisir le
				// premier caractere de la sequence
				dest[i] = seq->items[0];
			} else {
				// sinon, choisir celui qui succede c dans la sequence
				dest[i] = seq->items[idx + 1];
			}
			// Deplacer le caractere remplace a la fin de la sequence
			char_seq_move_end(char_seq_pos(dest[i], seq), seq);
		} else {
			// sinon, ajout de c dans la sequence
			dest[i] = c;
			char_seq_append(c, seq);
		}
	}

	// Ajout du caractere de fin de chaine de sortie
	dest[i] = '\0';
}
