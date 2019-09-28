#ifndef __TYPE_PAIR_SEQ_H_
#define __TYPE_PAIR_SEQ_H_

#define MAXSEQ 512 /* taille maximale d'une sequence (nombre de caracteres dans le tableau ascii) */

/* Definition du type couple, les éléments de la sequence */
typedef struct pair_t
{
	char reference;
	char image;
} Pair;

/* Definition du type seq */
typedef struct seq_t
{
	int length;
	Pair items[MAXSEQ];
} Pairseq;

/*
 * Initialise une sequence vide
 */
void pair_seq_init(Pairseq *seq);

/*
 * Trouve la position d'un couple selon sa reference dans une sequence. Renvoie -1 si l'element n'existe pas dans la sequence.
 */
int pair_seq_pos(char ref, Pairseq *seq);

/*
 * Trouve l'image d'un couple à une position donnée
 */
char pair_seq_value_of(int idx, Pairseq *seq);

/*
 * Ajoute un couple a la fin de la sequence
 */
void pair_seq_append(Pair couple, Pairseq *seq);

/*
 * Crée un couple et l'ajoute a la fin de la sequence
 */
void pair_seq_add(char image, Pairseq *seq);

/*
 * Permute les images de deux couples aux positions données
 */
void pair_seq_swap(int idx, int idx_p, Pairseq *seq);

/*
 * Permute un couple a la fin de la sequence selon sa reference
 */
void pair_seq_move_end(int idx, Pairseq *seq);

#endif /* __TYPE_PAIR_SEQ_H_ */
