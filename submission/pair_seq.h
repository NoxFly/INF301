#ifndef __PAIR_SEQ_H_
#define __PAIR_SEQ_H_

#include "client.h"
#include "type_pair_seq.h"

#define BUFSIZE MAXREP

/*
 * Encrypte une chaine de caracteres pour une sequence donnée
 */
void pair_seq_encrypt(char dest[BUFSIZE], char src[BUFSIZE], Pairseq *seq);

/*
 * Decrypte une chaine de caracteres pour une sequence donnée
 */
//void pair_seq_decrypt(char dest[BUFSIZE], char src[BUFSIZE], Pairseq *seq);

#endif /* __PAIR_SEQ_H_ */
