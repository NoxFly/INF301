#include <stdio.h>

int find_key(char txt[]);
char* uncrypt(char txt[], int key);

int main(int argc, char** argv) {
	printf("Hello world");
	return 0;
}

char* uncrypt(char txt[], int key) {
	/*
	
	int i = 0;
	while(txt[i] != '\0') {
		if(txt[i] > 'a' || txt[i] < 'z') {
			txt[i] = txt[i] - key;
		}
		i++;
	}

	*/
	return txt;
}


int find_key(char txt[]) {

	return 0;
}