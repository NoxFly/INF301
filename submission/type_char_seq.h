#ifndef __TYPE_CHAR_SEQ_H_
#define __TYPE_CHAR_SEQ_H_

#define MAXSEQ 512 // (nombre de caracteres dans le tableau ascii)

/*
 * Definition du type Charseq
 */
typedef struct char_seq_t
{
	int length;
	char items[MAXSEQ];
} Charseq;

/*
 * Initialise une sequence
 */
void char_seq_init(Charseq *seq);

/*
 * Trouve l'indice d'un element dans une sequence.
 * Retourne -1 si l'element ne se trouve pas dans la sequence
 */
int char_seq_pos(char c, Charseq *seq);

/*
 * Ajoute un element a la fin de la sequence
 */
void char_seq_append(char c, Charseq *seq);

/*
 * Deplace un element a la fin de la sequence
 */
void char_seq_move_end(int idx, Charseq *seq);

#endif /* __TYPE_CHAR_SEQ_H_ */
