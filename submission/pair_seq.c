#include <stdio.h>

#include "char_seq.h"
#include "type_pair_seq.h"

void pair_seq_encrypt(char dest[BUFSIZE], char src[BUFSIZE], Pairseq *seq) {
	char c;
	int i = 0, cpos = 0;

	// Pour chaque caractere de l'entree
	for (i = 0; src[i] != '\0'; i++) {
		c = src[i];

		// Determiner la position du caractere dans la sequence
		// (selon le caractere de reference dans le couple)
		cpos = pair_seq_pos(c, seq);

		if (cpos != -1) {
			// si c existe dans la sequence
			if (cpos == 0) {
				// Si c se trouve au debut de la sequence, choisir
				// l'image du dernier couple de la sequence
				dest[i] = pair_seq_value_of(seq->length - 1, seq);
			} else {
				// Sinon, choisir l'image du couple qui
				// precede c dans la sequence
				dest[i] = pair_seq_value_of(cpos - 1, seq);

				// et echanger les valeurs des images des deux
				// couples utilisés
				pair_seq_swap(cpos, cpos - 1, seq);
			}
			// Deplacer le couple du caractere lu à la fin de la sequence
			pair_seq_move_end(cpos, seq);
		} else {
			// Sinon, ajouter c a la fin de la sequence
			dest[i] = c;
			pair_seq_add(c, seq);
		}
	}

	// Add end of string at the end of the output string
	dest[i] = '\0';
}
