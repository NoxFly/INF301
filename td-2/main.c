#include <stdio.h>
#include <string.h>

#define MAX_LEN 1000

void encode(char *uncoded, char *encoded);
int indexOf(char *str, char c);
void splice(char *str, int idx);

int main(int argc, char **argv) {
    char str[] = "abcbcca";
    char encoded[MAX_LEN];

    encode(str, encoded);

    return 0;
}

void encode(char *uncoded, char *encoded) {
    char seq[26];
    const int l = strlen(uncoded);

    for(int i=0; i<l; i++) {

       char c = uncoded[i], c2;
       int idx;

       if((idx = indexOf(seq, c)) < -1) { // recupere l'index de c dans seq
            // dans la sequence
            if(idx > 0) c2 = seq[idx-1];
            else c2 = seq[strlen(seq)-1];


            encoded[i] = c2;
            splice(seq, idx);

       } else {
           // pas dans la sequence
            encoded[i] = c; // ajout du caractere dans le message code
       }
        
        seq[strlen(seq)] = c; // ajout du caractere dans la seq
    }


}

// retourne la position de c dans str. -1 si pas present
int indexOf(char *str, char c) {
    for(int i=0; i<strlen(str); i++) {
        if(str[i] == c) return i;
    }

    return -1;
}

void splice(char *str, int idx) {
    int l = strlen(str);
    int d = 0;
    for(int i=0; i<l; i++) {
        if(i == idx) d++;
        else str[i-d] = str[i];
    }
}