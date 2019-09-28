#include "type_seq.h"

void init_seq(Seq *seq)
{
	seq->length = 0;
}

int pos(char ref, Seq *seq)
{
	int i;

	for (i = 0; i < seq->length; i++) {
		if (seq->items[i].reference == ref)
			return i;
	}

	return -1;
}

char value_of(int idx, Seq *seq)
{
    return seq->items[idx].image;
}

void append(Couple couple, Seq *seq)
{
    seq->items[seq->length] = couple;
    seq->length++;
}

void add(char image, Seq *seq)
{
    Couple _new = {image, image};
    append(_new, seq);
}

void swap(int idx, int idx_p, Seq *seq) {
    char temp = seq->items[idx].image;
    seq->items[idx].image = seq->items[idx_p].image;
    seq->items[idx_p].image = temp;
}

void move_end(int idx, Seq *seq)
{
    int i;
    Couple tmp = seq->items[idx];

    // Decalage des elements à la droite de idx par 1 vers la gauche
    for (i = idx; i < seq->length; i++) {
        seq->items[i] = seq->items[i + 1];
    }

    // Placement de c à la fin de la sequence (i est la position du caractere de fin de sequence)
    seq->items[i - 1] = tmp;
}
