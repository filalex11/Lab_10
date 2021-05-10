#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"
/*
	Вывести список имен всех функций, вызываемых в программе на языке С, содержащейся в символьном файле.
*/
int main () {
	FILE *f = fopen ("file.txt", "r");
	if (f == NULL) {
		printf ("ERROR!\n");
		return 1;
	}
	char *word = (char*) malloc (256 * sizeof (char));
	char *string = (char*) malloc (1024 * sizeof (char));
	while (fgets (word, 255, f)) {
		strcat (string, word);
	}
	fclose (f);
	free (word);
	char **words = (char**) malloc ((word_count (string) + 1) * sizeof (char*));
	argssplit (string, words);
	/*while (*words) {
		printf ("%s\n", *words++);
	}*/
	int i = 0;
	while (words[i]) {
		if ((search_sym (words[i]) == 1) && (check_operator (words[i - 1]))) {
			printf ("%s\n", words[i - 1]);
		}
		++i;
	}
	/*while (*words) {
		printf ("%s\n", *words++);
	}*/
	return 0;
}
