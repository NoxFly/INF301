#include "type_pair_seq.h"

void pair_seq_init(Pairseq *seq)
{
	seq->length = 0;
}

int pair_seq_pos(char ref, Pairseq *seq)
{
	int i;

	for (i = 0; i < seq->length; i++) {
		if (seq->items[i].reference == ref)
			return i;
	}

	return -1;
}

char pair_seq_value_of(int idx, Pairseq *seq)
{
    return seq->items[idx].image;
}

void pair_seq_append(Pair couple, Pairseq *seq)
{
    seq->items[seq->length] = couple;
    seq->length++;
}

void pair_seq_add(char image, Pairseq *seq)
{
    Pair _new = {image, image};
    pair_seq_append(_new, seq);
}

void pair_seq_swap(int idx, int idx_p, Pairseq *seq) {
    char temp = seq->items[idx].image;
    seq->items[idx].image = seq->items[idx_p].image;
    seq->items[idx_p].image = temp;
}

void pair_seq_move_end(int idx, Pairseq *seq)
{
    int i;
    Pair tmp = seq->items[idx];

    // Decalage des elements à la droite de idx par 1 vers la gauche
    for (i = idx; i < seq->length; i++) {
        seq->items[i] = seq->items[i + 1];
    }

    // Placement de c à la fin de la sequence (i est la position du caractere de fin de sequence)
    seq->items[i - 1] = tmp;
}
