#ifndef LAB_10_C
#define LAB_10_C
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"
char check_operator (char *str) {
	char *operators[] = {"while", "if", "for", "do", "="};
	int i = 0;
	while (i < 5) {
		if (!strcmp (str, operators[i])) {
			return 0;
		}
		++i;
	}
	return 1;
}

int search_sym (char *str) {
	if (!check_operator (str)) {
		return -1;
	}
	int i = 0;
	while (str[i]) {
		if (str[i] == '(') {
			if (i == 0) {
				return 1;
			} else {
				int j = 0;
				while (j < i) {
					printf ("%c", str[j]);
					++j;
				}
				printf ("\n");
			}
		}
		++i;
	}
	return -1;
}

int word_count (const char *string) {
	int count = 0, i = 0;
	char in_word = 0;
	while (string[i]) {
		if ((string[i] != ' ') && (string[i] != '\n') && (string[i] != '\t')) {
			in_word = 1;
		} else {
			if (in_word) {
				++count;
				in_word = 0;
			}
		}
		++i;
	}
	if (in_word) {
		++count;
	}
	return count;
}

void argssplit (char *args, char **argv) {
	int i = 0, j = 0, k = 0, capacity = 10;
	char in_word = 0;
	while (args[k]) {
		if ((args[k] != ' ') && (args[k] != '\n') && (args[k] != '\t')) {
			in_word = 1;
			if (j == 0) {
				argv[i] = (char*) malloc (capacity * sizeof (char));
				if (argv[i] == NULL) {
					printf ("NOT ENOUGH MEMORY!\n");
					exit (1);
				}
			}
			if (j == capacity) {
				capacity *= 2;
				char *tmp1 = (char*) realloc (argv[i], capacity * sizeof (char));
				if (tmp1 == NULL) {
					free (argv[i]);
					printf ("NOT ENOUGH MEMORY!\n");
					exit (1);
				} else {
					argv[i] = tmp1;
				}
			}
			argv[i][j] = args[k];
			++j;
		} else {
			if (in_word) {
				in_word = 0;
				argv[i][j] = '\0';
				++i;
				j = 0;
			}
		}
		++k;
	}
	
	if (in_word) {
		argv[i][j] = '\0';
	}
}
#endif	
