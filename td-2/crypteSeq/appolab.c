#include "client.h"
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#define MAXMSG MAXREP

int seq_index(char c, char *seq) {
    int i;

    for (i = 0; seq[i] != '\0'; i++) {
        if (seq[i] == c)
            return i;
    }

    return -1;
}

void move_to_end(int idx, char *seq) {
    int i;
    char tmp = seq[idx];

    // Decalage des elements à la droite de idx par 1 vers la gauche
    for (i = idx; seq[i + 1] != '\0'; i++) {
        seq[i] = seq[i + 1];
    }

    // Placement de c à la fin de la sequence
    seq[i] = tmp;
}

void append(char c, char *seq) {
    int i = 0;

    // Comptage des elements de la liste
    while (seq[i] != '\0')
        i++;

    // Ajout de l'element c
    seq[i] = c;
    seq[i + 1] = '\0';
}

/*
 *  Encrypts the given buffer
 *
 *  dest: a string where the encrypted string will be copied
 *  src: the string to encrypt
 */
void encrypt(char dest[MAXMSG], char src[MAXMSG]) {
    char c, seq[MAXMSG];
    int i, idx;

    // Loop through each letter in the buffer
    for (i = 0; src[i] != '\0'; i++) {
        c = src[i];
        idx = seq_index(c, seq);

        if (idx != -1) {
            if (idx == 0) {
                dest[i] = c;
            } else {
                dest[i] = seq[idx - 1];
                move_to_end(idx, seq);
            }
        } else {
            dest[i] = c;
            append(c, seq);
        }
    }

    // Add end of string at the end of the output string
    dest[i] = '\0';
}

int main() {
    char c, reponse[MAXREP], message[MAXMSG];
    int i;

    // Affiche les échanges avec le serveur (false pour désactiver)
    mode_debug(true);

    // Connexion au serveur AppoLab
    connexion("im2ag-appolab.u-ga.fr", 443);
    // utilisez le port 443 en cas de problème sur le 9999

    // Remplacez <identifiant> et <mot de passe> ci dessous.
    envoyer_recevoir("login 11806394 AVRILIONIS", reponse);
    envoyer_recevoir("load crypteSeq", reponse);
    envoyer_recevoir("start", reponse);

    i = 0;
    fscanf(stdin, "%c", &c);
    while(!feof(stdin)) {
        message[i] = c;
        i++;
        fscanf(stdin, "%c", &c);
    }
    message[i] = '\0';

    envoyer_recevoir(message, reponse);

    return 0;
}
