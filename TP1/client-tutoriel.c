#include "client.h"
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>

#define MAXMSG MAXREP

int main() {
    char reponse[MAXREP];
    char message[MAXMSG];

    // Affiche les échanges avec le serveur (false pour désactiver)
    mode_debug(true);

    // Connexion au serveur AppoLab
    connexion("im2ag-appolab.u-ga.fr", 9999);
    // utilisez le port 443 en cas de problème sur le 9999
    /* connexion("im2ag-appolab.u-ga.fr", 443); */

    // Remplacez <identifiant> et <mot de passe> ci dessous.
    envoyer_recevoir("login 11802767 RUSSO", reponse);

    ///////////////////////////////////////////
    //TUTORIEL1
    /*
    envoyer_recevoir("load tutoriel", reponse);
    envoyer_recevoir("aide",reponse);
    envoyer_recevoir("start",reponse);
    envoyer_recevoir("oui",reponse);
    envoyer_recevoir("4",reponse);
    envoyer_recevoir("blanc",reponse);
    envoyer_recevoir("Pincemoi",reponse);
    envoyer_recevoir("Tutoriel",reponse);
    */
   ////////////////////////////////////////////

   //TUTORIEL2
    /*
   printf("Reponse du serveur : %s",reponse);
   envoyer_recevoir("load tutoriel2",reponse);
   envoyer_recevoir("aide",reponse);
   envoyer_recevoir("ok",reponse);
   envoyer_recevoir("start",reponse);
   int val = 0;
   char c[50];
   for(int i = 0; i <= 4; i++){
        sscanf(reponse,"%d", &val);
        val = val*2;
        sprintf(c,"%d",val);
        envoyer_recevoir(c,reponse);
   }
   */

  //////////////////////////////////////////////

  //TUTORIEL 3
  /*
    char c[500];
    envoyer_recevoir("load tutoriel3",reponse);
    envoyer_recevoir("depart",reponse);
    envoyer_recevoir("OK",reponse);
    envoyer_recevoir("OUI",reponse);
    for(int i = 0; i<8;i++){
        for(int i = 0; i<strlen(reponse);i++){
            if(reponse[i]>96){
                c[i] = reponse[i] - 32;
            }
            else{
                c[i] = reponse[i];
            }
        }
        envoyer_recevoir(c,reponse);
        memset(c, 0, sizeof(c));
    }
    */
   /////////////////////////////////////////////////
   /*
   envoyer_recevoir("load decrypte-v1",reponse);
   envoyer_recevoir("start",reponse);
   char c[500];
   for(int i = 0; i < 5;i++){
       for(int j = 0; j<strlen(reponse);j++){
         if(reponse[j]<123 && reponse[j]>96){
           c[j] = reponse[j] - 5;
           if(c[j]<96){
             c[j] = c[j] + 26;
           }
         }
         else if(reponse[j]<91 && reponse[j]> 64){
           c[j] = reponse[j] - 5;
           if(c[j]<64){
             c[j] = c[j] + 26;
           }
         }
         else{
           c[j] = reponse[j];
         }
       }
       envoyer_recevoir(c,reponse);
       memset(c, 0, sizeof(c));

   }
   */
   ////////////////////////////////////////////
   /*
   envoyer_recevoir("load planB",reponse);
   envoyer_recevoir("help",reponse);
   char cher_bob[8];
   for(int i = 0;i<8;i++){
     cher_bob[i] = reponse[i];
   }
   char c[8];
   int compt = 0;
   while(strcmp(c,"Cher Bob")!=0){
     memset(c, 0, sizeof(c));
     for(int j = 0; j<strlen(cher_bob);j++){
       if(cher_bob[j]<123 && cher_bob[j]>96){
         c[j] = cher_bob[j] - compt;
         if(c[j]<97){
           c[j] = c[j] + 26;
         }
       }
       else if(cher_bob[j]<91 && cher_bob[j]> 64){
         c[j] = cher_bob[j] - compt;
         if(c[j]<65){
           c[j] = c[j] + 26;
         }
       }
       else{
         c[j] = cher_bob[j];
       }
     }
     compt ++;
     printf("La valeur de c est actuellement de %s\n",c);
   }
   */
    while (true) {
        int num_char;
        attendre_message();
        do {
            //printf("Le message du serveur est : %s\n",message);
            //printf("La reponse du serveur même sans le mode debug : %s\n",reponse);
            fgets (message, MAXMSG, stdin);
            num_char = strlen(message);
            printf("%d chars\n", num_char);
            message[num_char-1] = '\0'; /* on supprime le retour à la ligne */
        } while (num_char < 2);         /* on n'envoie pas de ligne vide */
        envoyer_recevoir(message, reponse);
    }

    return 0;
}
