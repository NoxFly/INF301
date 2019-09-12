#include <stdio.h>

const int MAX_LENGTH = 300;

int find_key(char txt[]);
int is_alpha(char c);
int normalize_index(char c);
void decrypt(int key, char encoded[MAX_LENGTH], char decoded[MAX_LENGTH]);

int main(int argc, char *argv[]) {

	int key = 5;
	char decoded[MAX_LENGTH];
	char encoded[] = "hmjw gtg,\nstzx sj utzatsx uqzx stzx jhmfsljw ij rjxxfljx xnruqjrjsy ufw jrfnq.";

	decrypt(key, encoded, decoded);

	printf("Encoded: %s\n\n", encoded);
	printf("Decoded: %s\n\n", decoded);

	return 0;
}

void decrypt(int key, char encoded[MAX_LENGTH], char decoded[MAX_LENGTH]) {

	int i = 0;
	char c;

	while (encoded[i] != '\0') {
		c = encoded[i];

		if (is_alpha(c)) {
			c = normalize_index((c - 'a') - key % 26) + 'a';
		}

		decoded[i] = c;
		i++;
	}

	decoded[i] = '\0';

}

int normalize_index(char c) {
	if (c < 0) {
		return c + 26;
	}
	return c;
}

int is_alpha(char c) {
	return ('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z');
}
