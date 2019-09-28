#ifndef __CAESAR_H_
#define __CAESAR_H_

#include "client.h"
#define BUFSIZE MAXREP

/*
 * Encrypte une chaine de caracteres pour une clef donnee
 */
void caesar_encrypt(char dest[BUFSIZE], char src[BUFSIZE], int key);

/*
 * Decrypte une chaine de caracteres pour une clef donnee
 */
void caesar_decrypt(char dest[BUFSIZE], char src[BUFSIZE], int key);

/*
 * Determine la clé utilisée dans une chaine de caracteres cryptee selon
 * un caractere donne
 */
int caesar_key(char encrypted, char comparison);

#endif /* __CAESAR_H_ */
