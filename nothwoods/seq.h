#ifndef __CHAR_SEQ_H__
#define __CHAR_SEQ_H__
#include <stdio.h>

#define MAXSEQ 512 /* taille maximale d'une sequence (nombre de caracteres dans le tableau ascii) */

/* Definition du type couple, les éléments de la sequence */
typedef struct couple_t
{
	char reference;
	char image;
} Couple;

/* Definition du type seq */
typedef struct seq_t
{
	int length;
	Couple items[MAXSEQ];
} Seq;

/*
 * Initialise une sequence vide
 */
void init_seq(Seq *seq);

/*
 * Trouve la position d'un couple selon sa reference dans une sequence
 */
int pos(char ref, Seq *seq);

/*
 * Trouve l'image d'un couple à une position donnée
 */
char value_of(int idx, Seq *seq);

/*
 * Ajoute un couple a la fin de la sequence
 */
void append(Couple *couple, Seq *seq);

/*
 * Crée un couple et l'ajoute a la fin de la sequence
 */
void add(char image, Seq *seq);

/*
 * Permute deux couples selon leurs position
 */
void swap(int idx, int idx_p, Seq *seq);

/*
 * Permute un couple a la fin de la sequence selon sa reference
 */
void swap_end(int idx, Seq *seq);

#endif
