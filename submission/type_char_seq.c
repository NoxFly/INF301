#include "type_char_seq.h"

void char_seq_init(Charseq *seq)
{
	seq->length = 0;
	seq->items[0] = '\0';
}

int char_seq_pos(char c, Charseq *seq)
{
	int i;

	for (i = 0; i < seq->length; i++) {
		if (seq->items[i] == c)
			return i;
	}

	return -1;
}

void char_seq_append(char c, Charseq *seq)
{
    seq->items[seq->length] = c;
    seq->length++;
    seq->items[seq->length] = '\0';
}

void char_seq_move_end(int idx, Charseq *seq)
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
