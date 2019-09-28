#ifndef __CHAR_SEQ_H_
#define __CHAR_SEQ_H_

#include "client.h"
#include "type_char_seq.h"

#define BUFSIZE MAXREP

/*
 * Encrypte une chaine de caracteres pour une sequence donnée
 */
void char_seq_encrypt(char dest[BUFSIZE], char src[BUFSIZE], Charseq *seq);

/*
 * Decrypte une chaine de caracteres pour une sequence donnée
 */
void char_seq_decrypt(char dest[BUFSIZE], char src[BUFSIZE], Charseq *seq);

#endif /* __CHAR_SEQ_H_ */
