#include "parser.h"

char *tag = "href";


char to_lower(char c) {
	return c > 92 ? c : c + 32;
}

char is_whitespace(char c) {
	return c == '\t' || c == '\n' || c == ' ';
}

int url_extract(char *str, int n, char **p) {
	char *t = *p, *c = tag;
	char quote;

	while(*t != '\0') {
		while(*t && *c && to_lower(*t) == *c) {
			t++;
			c++;
		}

		if(*c == '\0') {
			int i = 0;
			while(*t != '\0' && is_whitespace(*t))
				t++;
			if(*t++ == '=') {
				while(*t != '\0' && is_whitespace(*t))
					t++;
				if(*t == '\'' || *t == '\"') {
					quote = *t++;
					while(*t != '\0' && *t != quote && i < n - 1)
				 		str[i++] = *t++;
					str[i] = '\0';
				}
			}
			if(i != 0) break;
		}
		c = tag;
		t++;
	}

	*p = t;
	return *t;
}
