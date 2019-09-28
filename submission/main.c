#include "client.h"
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "caesar.h"

#define APPOLAB_PORT 443
#define APPOLAB_DEBUG false

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
    char appolab_id[MAXREP], appolab_password[MAXREP];
    int key;

    if (argc != 3)
    {
    	fprintf(stderr, "syntax: %s <appolab user identifier> <appolab password>\n", argv[0]);
    	return 1;
    }

    // Obtention des details d'authentification
    sscanf(argv[1], "%s", appolab_id);
    sscanf(argv[2], "%s", appolab_password);

    mode_debug(APPOLAB_DEBUG);

    // validate appolab exercices

    return 0;
}

/*
 * Fonction d'aide a l'authentification à AppoLab
 */
void authenticate(char *id, char *password)
{
	char auth_command[256], response[MAXREP];

	printf(MAG "Connecting to server ...\n" RESET);
	connexion("im2ag-appolab.u-ga.fr", APPOLAB_PORT);

	printf(MAG "Authenticating ...\n" RESET);
	sprintf(auth_command, "login %s %s", id, password);
	envoyer_recevoir(auth_command, response);

}

/*
 * Fonction d'aide a l'affichage des sections dans la ligne de commandes
 */
void print_h(char const *text)
{
	// Utilisation de prefix_print de client.h
	printf(BLUBOLD "\n=== %s ===\n" RESET, text);
}
