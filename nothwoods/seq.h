#ifndef __CHAR_SEQ_H__
#define __CHAR_SEQ_H__
#include <stdio.h>

#define MAXSEQ 512 /* taille maximale d'une sequence (nombre de caracteres dans le tableau ascii) */

/* Definition du type couple, les éléments de la sequence */
typedef struct couple_t
{
	char reference;
	char value;
} Couple;

/* Definition du type seq */
typedef struct seq_t
{
	int length;
	Couple items[MAXSEQ];
} Seq;

/*
 * Required functions: init, pos, append, add, swap_end

/*
 * Initialise une sequence
 */
void init_seq(Seq *seq);

/*
 * Trouve la position d'un couple selon sa valeur dans une sequence
 */
int index(char val, Seq *seq);

/*
 * Trouve la reference d'un couple selon sa valeur dans une sequence
 */
char pos(char val, Seq *seq);

/*
 * Ajoute un couple a la fin de la sequence
 */
void append(Couple *couple, Seq *seq);

/*
 * Crée un couple et l'ajoute a la fin de la sequence
 */
void add(char val, Seq *seq);

/*
 * Permute deux couples leurs reference
 */
void swap(char ref, char ref_p, Seq *seq);

/*
 * Permute un couple a la fin de la sequence selon sa reference
 */
void swap_end(char ref, Seq *seq);

#endif
