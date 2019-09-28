/*
 * couple_seq.h
 *
 *  Created on: Sep 28, 2019
 *      Author: Photis
 */

#ifndef __COUPLE_SEQ_H_
#define __COUPLE_SEQ_H_

#include "type_seq.h"

#define BUFSIZE 512
#define MAXSEQ 512

void encrypt(char dest[BUFSIZE], char src[BUFSIZE], Seq *seq);
void decrypt(char dest[BUFSIZE], char src[BUFSIZE], Seq *seq);

#endif /* __COUPLE_SEQ_H_ */
