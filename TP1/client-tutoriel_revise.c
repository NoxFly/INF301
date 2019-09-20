#include "client.h"
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>

#define MAXMSG MAXREP

void tutoriel1(char *reponse){
//TUTORIEL1
//Dans cet exercice, nous comprenons comment dialoguer avec le serveur Appolab
// en repondant les message predefini et fixée.
    
    envoyer_recevoir("load tutoriel", reponse);
    envoyer_recevoir("aide",reponse);
    envoyer_recevoir("start",reponse);
    envoyer_recevoir("oui",reponse);
    envoyer_recevoir("4",reponse);
    envoyer_recevoir("blanc",reponse);
    envoyer_recevoir("Pincemoi",reponse);
    envoyer_recevoir("Tutoriel",reponse); 
}

void tutoriel2(char *reponse){
//TUTORIEL2
// Les questions de cette question n'est plus fixée. Nous doublons les valeurs
// qui a été donné par le serveur.

   printf("Reponse du serveur : %s",reponse);
   envoyer_recevoir("load tutoriel2",reponse);
   envoyer_recevoir("aide",reponse);
   envoyer_recevoir("ok",reponse);
   envoyer_recevoir("start",reponse);

   int val = 0;
   char c[MAXMSG];
   //Le nombre reçu de serveur est un chaine de caracteres. Pour faire doubler le
   // nombre, il faut qu'on le convertit en int et reconvertir vers chaine de caracteres
   // pour qu'on peut le renvoyer au serveur
   for(int i = 0; i <= 4; i++){
        sscanf(reponse,"%d", &val);
        val = val*2;
        sprintf(c,"%d",val);
        envoyer_recevoir(c,reponse);
   }
   memset(c, 0, sizeof(c));
}

char convertMajuscule (char msg[]) {
   for (int i = 0; i<strlen(msg); i++) {
      if (msg[i]>=97 && msg[i]<=122){ msg[i] = msg[i] - 32;}
   }
   return *msg;
}

void tutoriel3(char *reponse){
//TUTORIEL 3
//Cet exercice nous demande de convertir le message reçu en majuscule.
    char c[MAXMSG];
    envoyer_recevoir("load tutoriel3",reponse);
    envoyer_recevoir("depart",reponse);
    envoyer_recevoir("OK",reponse);
    envoyer_recevoir("OUI",reponse);

  for (int i = 0; i<6; i++) {
       strcpy(c, reponse);
       convertMajuscule(c);
       printf("%s", c);
       envoyer_recevoir(c, reponse);  
    
    }
    //on n'utilise pas la fonction memset() car la fonction strcpy() deja fait le meme chose.
} 


char decalageCesar (char msg[], int decal) {
   for (int i = 0; i< strlen(msg); i++){
      if ((msg[i] >= 'a') && (msg[i] <= 'z')) {
         msg[i] = msg[i] + decal;
         if (msg[i] > 'z') msg[i] = msg[i] - 26;
         else if (msg[i] < 'a') msg[i] = msg[i] + 26;
      } else if ( (msg[i] >= 'A') && (msg[i] <= 'Z')){
         msg[i] = msg[i] + decal;
         if((msg[i] > 'Z')) { msg[i] = msg[i] - 26;
         } else if (msg[i] < 'A') msg[i] = msg[i] + 26;
      }
      else msg[i] = msg[i];
   }
   return *msg;
}

// je met le code ci-dessous comme la fonction decalageCesar et
// je change le nombre d'ASCII pour que ce soit plus lisible...?

//    for(int i = 0; i < 5;i++){
//        for(int j = 0; j<strlen(reponse);j++){
//          if(reponse[j]<123 && reponse[j]>96){
//            c[j] = reponse[j] - 5;
//            if(c[j]<96){
//              c[j] = c[j] + 26;
//            }
//          }
//          else if(reponse[j]<91 && reponse[j]> 64){
//            c[j] = reponse[j] - 5;
//            if(c[j]<64){
//              c[j] = c[j] + 26;
//            }
//          }
//          else{
//            c[j] = reponse[j];
//          }
//        }
//        envoyer_recevoir(c,reponse);
//        memset(c, 0, sizeof(c));
//    }

void projetX(char *reponse){
    // Dans cet exercice, nous avons trouvé un message caché de Bob et le decrypter.
    // Bob a dit que le prochain message est dans l'exercice planB, mais
    // on peut s'entrainer d'abord dans l'exercice decrypte-v1.
    // Pour reussir cet exercice, il faut qu'on envoyer "Veni, vidi, vici" au serveur.
    
    envoyer_recevoir("load projetX", reponse);
    envoyer_recevoir("help", reponse);
    char c[MAXMSG];


    printf("%s", reponse);
    strcpy(c, reponse);
    decalageCesar(c, -5); //decalage par -5.
    printf("%s", c);
    envoyer_recevoir("depart", reponse);
    envoyer_recevoir("Veni, vidi, vici", reponse);
    memset(c, 0, sizeof(c));
}


void decrypte_v1(char *reponse){
   //Cet exercice consiste à recevoir une série de message cryptés avec un decalage
   // de César de 5 et à renvoyer à chaque fois la version decryptéé.

    envoyer_recevoir("load decrypte-v1",reponse);
    envoyer_recevoir("start",reponse);
    char c[MAXMSG];
    int cle = -5; //Decaler avec un decalage de 5.

    //Nous avons su qu'il y a 5 message à recevoir et à renvoyer.
    for(int i = 0; i<5; i++){
        strcpy(c, reponse); //copier le contenu du variable 'reponse' vers le chaine de caractere 'c'.
        decalageCesar(c, cle);
        printf("%s", c);
        envoyer_recevoir(c, reponse);
    
    memset(c, 0, sizeof(c));
    }
}

int trouver_decalage(char msg[], int idx){
    //Comparer le idx-ieme caractere du message avec le caractere 'C' parce que nous savons
    // que le debut de message est toujours "Chere".

   return msg[idx] - 'C';
}

void planB(char *reponse){
    //Dans cet exercice nous avons trouvé un message caché en appelant 'help'.
    //Le nombre de decalage dans cet exercice n'est pas fixé, donc on doit determiner le nombre.

    char c[MAXMSG];
    envoyer_recevoir("load planB\n", reponse);
    envoyer_recevoir("depart\n", reponse);
    envoyer_recevoir("help\n", reponse);

    strcpy(c, reponse);     

    // Pour trouver le nombre de decalage, nous utilisons la fonction trouver_decalage
    // en comparant la premiere caractere du message avec le caractere 'C' parce que nous savons
    // que le debut de message est toujours "Chere".
    int cle = trouver_decalage(c, 0);
    decalageCesar(c, -cle);

    strcpy(c, "hasta la revolucion");
    decalageCesar(c, -cle);
    envoyer_recevoir(c, reponse);

    strcpy(c, reponse);      
    //Dans cette partie le serveur ne renvoie seulement le message, mais aussi
    //"Bonne reponse". Pour cela, nous commençons de lire le message à partir
    // de l'indice 18.
    cle = trouver_decalage(c, 18);
    decalageCesar(c, -cle);
    printf("%s", c);

    //On renvoie ce message au serveur pour valider cet exercice
    strcpy(c, "hasta la victoria siempre");
    decalageCesar(c, -cle);
    envoyer_recevoir(c, reponse);

    memset(c, 0, sizeof(c));
}


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

    // tutoriel1(reponse);
    // tutoriel2(reponse);
    // tutoriel3(reponse);
    // projetX(reponse);
    // decrypte_v1(reponse);
    // planB(reponse);

  
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




/**********************************************************************
*            
*Archive                     
********************************************************************/



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
