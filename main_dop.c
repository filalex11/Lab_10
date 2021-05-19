#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"
/*
	Вывести список имен всех функций, вызываемых в программе на языке С, содержащейся в символьном файле.
*/
int main (int argc, char *argv[]) {
	if (argc != 2) {
		printf ("USAGE: %s input_file\n", argv[0]);
		return 2;
	}
	
	FILE *f = fopen (argv[1], "r");
	if (f == NULL) {
		printf ("ERROR! FILE \"%s\" NOT FOUND!\n", argv[1]);
		return 2;
	}
	int capacity = 1024;
	char *word = (char*) malloc (256 * sizeof (char));
	char *string = (char*) malloc (capacity * sizeof (char));
	while (fgets (word, 255, f)) {
		strcat (string, word);
		if (capacity - strlen (string) < 255) {
			capacity *= 2;
			char *tmp = realloc (string, capacity * sizeof (char));
			if (tmp == NULL) {
				free (string);
				printf ("NOT ENOUGH MEMORY!\n");
				return 1;
			} else {
				string = tmp;
			}
		}
	}
	fclose (f);
	free (word);
	char **words = (char**) malloc ((word_count (string) + 1) * sizeof (char*));
	argssplit (string, words);
	int i = 0, j = 0;
	while (words[i]) {
		if ((search_sym (words[i]) == 1) && (check_operator (words[i - 1]))) {
			while (words[i - 1][j]) {
				if (((words[i - 1][j]) == '_') || (isalpha (words[i - 1][j]))) {
					printf ("%c", words[i - 1][j]);
				}
				++j;
			}
			printf ("\n");
			j = 0;
		}
		++i;
	}
	return 0;
}
