#ifndef __CHAR_SEQ_H__
#define __CHAR_SEQ_H__
#include <stdio.h>

#define MAXSEQ 512 /* taille maximale d'une sequence (nombre de caracteres dans le tableau ascii) */

/* Definition du type char_seq */
typedef struct char_sequence
{
	int length;
	char items[MAXSEQ];
} char_seq;

/*
 * Initialise une sequence
 */
void init_char_seq(char_seq *seq);

/*
 * Trouve l'indice d'un element dans une sequence
 */
int pos(char c, char_seq *seq);

/*
 * Ajoute un element a la fin de la sequence
 */
void append(char c, char_seq *seq);

/*
 * Permute un element a la fin de la sequence
 */
void swap_end(int idx, char_seq *seq);

/*
 * Supprime un element de la sequence
 */
// void remove(int idx, char_seq *seq);

#endif
