#include <stdio.h>
#include <string.h>

#define MAX_LEN 1000

void encode(char uncoded[MAX_LEN], char encoded[MAX_LEN]);
void decode(char encoded[MAX_LEN], char uncoded[MAX_LEN]);
int indexOf(char* str, char c);
void splice(char* str, int idx);

int main(int argc, char** argv) {
	char str[] = "abcbcca";
	char str2[] = "abcaabc";
	char encoded[MAX_LEN];
	char uncoded[MAX_LEN];

	encode(str, encoded);
	decode(str2, uncoded);

	printf("encoded: %s\nuncoded: %s\n", encoded, uncoded);

	return 0;
}

void encode(char uncoded[MAX_LEN], char encoded[MAX_LEN]) {
	const int l = strlen(uncoded);
	char seq[26];
	int j = 0;

	for (int i = 0; i < l; i++) {
		char c = uncoded[i], c2;
		int idx;

		if ((idx = indexOf(seq, c)) > -1) { // recupere l'index de c dans seq
			// dans la sequence
			if (idx > 0) c2 = seq[idx - 1];
			else c2 = seq[j];


			splice(seq, idx);
		}
		else {
			// pas dans la sequence
			if(i>0) j++;
			c2 = c;
		}

		encoded[i] = c2; // ajout du caractere dans le message code

		seq[j] = c; // ajout du caractere dans la seq

		printf("c: %c\n  idx: %i\n  seq: %s\n  c2: %c \n  encoded: %s\n  (j): %i\n\n", c, idx, seq, c2, encoded, j);
	}
}

void decode(char encoded[MAX_LEN], char uncoded[MAX_LEN]) {
	const int l = strlen(encoded);
	char seq[26];
	int j = 0;

	for (int i = 0; i < l; i++) {
		char c = encoded[i], c2;
		int idx;

		if ((idx = indexOf(seq, c)) > -1) { // recupere l'index de c dans seq
			// dans la sequence
			if (idx < j) c2 = seq[idx + 1];
			else c2 = seq[0];

			splice(seq, indexOf(seq, c2));
		}
		else {
			// pas dans la sequence
			if(i>0) j++;
			c2 = c; // ajout du caractere dans le message code
		}

		uncoded[i] = c2;
		seq[j] = c2; // ajout du caractere dans la seq
	}
}

// retourne la position de c dans str. -1 si pas present
int indexOf(char* str, char c) {
	for (int i = 0; i < strlen(str); i++) {
		if (str[i] == c) return i;
	}

	return -1;
}

void splice(char* str, int idx) {
	int l = strlen(str);
	int d = 0;
	for (int i = 0; i < l; i++) {
		if (i == idx) d++;
		else str[i - d] = str[i];
	}
}