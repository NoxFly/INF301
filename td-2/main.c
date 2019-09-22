#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 1200

// retourne si le caractere donne est une lettre (minuscule ou majuscule)
int is_alpha(char c) {
	return ('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z');
}

// retourne la position de c dans str. -1 si pas present
int indexOf(char* str, char c) {
	for (unsigned int i = 0; i < strlen(str); i++) {
		if (str[i] == c) return i;
	}

	return -1;
}

// enleve le char c de la chaine de caractere str a l'emplacement idx
void splice(char* str, int idx) {
	int l = strlen(str); // longueur de str
	for(int i = idx+1; i < l; i++) {
		str[i - 1] = str[i];
	}
}

// encode selon la methode crypteSeq
void encode(char uncoded[MAX_LEN], char encoded[MAX_LEN]) {
	const int l = strlen(uncoded)-10;
	char seq[26];
	int j = 0;

	for (int i = 0; i < l; i++) {
		char c = uncoded[i], c2;
		int idx;

		if (is_alpha(c) || 1) {
			if ((idx = indexOf(seq, c)) > -1) { // recupere l'index de c dans seq
				// dans la sequence
				if (idx > 0) c2 = seq[idx - 1];
				else c2 = seq[j];


				splice(seq, idx);
			}
			else {
				// pas dans la sequence
				if (i > 0) j++;
				c2 = c;
			}

			seq[j] = c; // ajout du caractere dans la seq
		}
		else {
			c2 = c;
		}

		encoded[i] = c2; // ajout du caractere dans le message code
	}

	printf("\n%s\n", encoded);
}

// decrypte selon la methode crypteSeq
void decode(char encoded[MAX_LEN], char uncoded[MAX_LEN]) {
	const int l = strlen(encoded);
	char seq[26];
	int j = 0;

	for (int i = 0; i < l; i++) {
		char c = encoded[i], c2;
		int idx;

		if (is_alpha(c)) {
			if ((idx = indexOf(seq, c)) > -1) { // recupere l'index de c dans seq
				// dans la sequence
				if (idx < j) c2 = seq[idx + 1];
				else c2 = seq[0];

				splice(seq, indexOf(seq, c2));
			}
			else {
				// pas dans la sequence
				if (i > 0) j++;
				c2 = c; // ajout du caractere dans le message code
			}
		}
		else {
			c2 = c;
		}

		uncoded[i] = c2;
		seq[j] = c2; // ajout du caractere dans la seq
	}
}

// main
int main(int argc, char** argv) {

	char txt[1200];
	char txt_encode[1200];

	FILE* f = fopen("./txt-seq.txt", "r");
	int i = 0;
	char c;

	if(f) {
		while ((c = fgetc(f)) != EOF) {
			txt[i] = c;
			i++;
		}

		printf("\n%s\n", txt); // texte de base
		encode(txt, txt_encode); // encode le texte


		fclose(f);
	}

	return 0;
}