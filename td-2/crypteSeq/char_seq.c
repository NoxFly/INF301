#include "char_seq.h"

void init_char_seq(char_seq *seq)
{
	seq->length = 0;
	seq->items[0] = '\0';
}

int pos(char c, char_seq *seq)
{
	int i;

	for (i = 0; i < seq->length; i++) {
		if (seq->items[i] == c)
			return i;
	}

	return -1;
}

void append(char c, char_seq *seq)
{
    seq->items[seq->length] = c;
    seq->length++;
    seq->items[seq->length] = '\0';
}

void swap_end(int idx, char_seq *seq)
{
    int i;
    char tmp = seq->items[idx];

    // Decalage des elements à la droite de idx par 1 vers la gauche
    for (i = idx; i < seq->length; i++) {
        seq->items[i] = seq->items[i + 1];
    }

    // Placement de c à la fin de la sequence (i est la position du caractere de fin de sequence)
    seq->items[i - 1] = tmp;
}
