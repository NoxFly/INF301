#include "client.h"
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "type_char_seq.h"
#include "type_pair_seq.h"

#include "caesar.h"
#include "char_seq.h"
#include "pair_seq.h"

#define APPOLAB_PORT 443
#define APPOLAB_DEBUG true

#define MAXMSG MAXREP

#define BLUBOLD "\x1B[34;1m"
#define MAG   "\x1B[35m"
#define RESET "\x1B[0m"

// Voir implementations des fonctions d'aide ci-dessous
void authenticate(char *id, char *password);
void print_h(char const *text);

int main(int argc, char **argv)
{
    char reponse[MAXREP], message[MAXMSG];
    char msg_crypteSeq[MAXMSG], msg_nothwoods[MAXMSG];
    char appolab_id[MAXREP], appolab_password[MAXREP];

    // Pour planB
    int key;

    // Pour crypteSeq
    Charseq cseq;

    // Pour Nothwoods
    Pairseq pseq;

    if (argc != 3)
    {
    	fprintf(stderr, "syntax: %s <appolab user identifier> <appolab password>\n", argv[0]);
    	return 1;
    }

    // Obtention des details d'authentification
    sscanf(argv[1], "%s", appolab_id);
    sscanf(argv[2], "%s", appolab_password);

    mode_debug(APPOLAB_DEBUG);


    /*
     * projetX
     */
    print_h("projetX");
    authenticate(appolab_id, appolab_password);
    envoyer_recevoir("load projetX", reponse);
    envoyer_recevoir("help", reponse);

    // Decrypter la reponse grace a l'algorithme de Caesar (decalage par 5)
    caesar_decrypt(message, reponse, 5);
    printf("Message decode:\n%s\n", message);

    envoyer_recevoir("start", reponse);
    envoyer_recevoir("Veni, vidi, vici", reponse);


    /*
     * decrypte-v1
     */
    print_h("decrypte-v1");
    authenticate(appolab_id, appolab_password);
    envoyer_recevoir("load decrypte-v1", reponse);
    envoyer_recevoir("start", reponse);

    // Decodage des cinq messages envoyes par le serveur
    for (int i = 0; i < 5; i++) {
    	caesar_decrypt(message, reponse, 5);
    	printf("Sending message: %d of 5\n", i + 1);
    	envoyer_recevoir(message, reponse);
    }


    /*
     * planB
     */
    print_h("planB");
    authenticate(appolab_id, appolab_password);
    envoyer_recevoir("load planB", reponse);
    envoyer_recevoir("start", reponse);

	// Lire message code
	envoyer_recevoir("aide", reponse);

	// Calculer la clef
	key = caesar_key(reponse[0], 'C');

	// Coder "hasta la revolucion" selon la clef calculee
	caesar_encrypt(message, "hasta la revolucion", -key);
	envoyer_recevoir(message, reponse);

	// Rem: la reponse inclus "Bonne réponse !\n\n" au debut, veut garder seulement
	// le message de Bob vers Alice. Pout cela, on doit prendre compte des 18 caracteres
	// qui precedent le debut du message code.

	// Calculer la clef depuis la reponse
	key = caesar_key(reponse[18], 'C');
	caesar_decrypt(msg_crypteSeq, &reponse[18], key);
	printf("Message decode (instructions crypteSeq) :\n%s\n", msg_crypteSeq);

	caesar_encrypt(message, "hasta la victoria siempre", -key);
	envoyer_recevoir(message, reponse);


    /*
     * crypteSeq
     */
    print_h("crypteSeq");
    authenticate(appolab_id, appolab_password);
    envoyer_recevoir("load crypteSeq", reponse);
	envoyer_recevoir("start", reponse);

	char_seq_init(&cseq);

	// on supprime le dernier retour chariot de instructions_crypteSeq pour
	// que le message soit accepte par AppoLab
	msg_crypteSeq[strlen(msg_crypteSeq) - 1] = '\0';

	char_seq_encrypt(message, msg_crypteSeq, &cseq);
	envoyer_recevoir(message, reponse);

	// Decrypter la reponse
	char_seq_init(&cseq);
	char_seq_decrypt(reponse, &reponse[83], &cseq);
	printf("Message decode :\n%s\n", reponse);


    /*
     * Nothwoods
     */
    print_h("Nothwoods");
    authenticate(appolab_id, appolab_password);
    envoyer_recevoir("load Nothwoods", reponse);

    char_seq_init(&cseq);
    char_seq_decrypt(msg_nothwoods, reponse, &cseq);
    printf("Message decode (instructions Nothwoods) :\n%s\n", msg_nothwoods);

    pair_seq_init(&pseq);
    pair_seq_encrypt(message, msg_nothwoods, &pseq);
	envoyer_recevoir("start", reponse);
	envoyer_recevoir(message, reponse);

	printf("Reponse :\n%s\n", reponse);

    return 0;
}

/*
 * Fonction d'aide a l'authentification à AppoLab
 */
void authenticate(char *id, char *password)
{
	char auth_command[256], response_tmp[MAXREP];

	printf(MAG "Connecting to server ...\n" RESET);
	connexion("im2ag-appolab.u-ga.fr", APPOLAB_PORT);

	printf(MAG "Authenticating ...\n" RESET);
	sprintf(auth_command, "login %s %s", id, password);
	envoyer_recevoir(auth_command, response_tmp);

}

/*
 * Fonction d'aide a l'affichage des sections dans la ligne de commandes
 */
void print_h(char const *text)
{
	// Utilisation de prefix_print de client.h
	printf(BLUBOLD "\n=== %s ===\n" RESET, text);
}
