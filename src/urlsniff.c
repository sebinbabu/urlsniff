#include <malloc.h>
#include <stdio.h>
#include <string.h>

#include "parser.h"
#include "remote.h"

int print_urls(char *s) {
	int ret = 0;
	char url[2100];
	char *data = dl_to_buffer(s);
	if(data == NULL) {
		ret = 1;
	} else {
		char *t = data;
		while(url_extract(url, 2100, &t))
			fprintf(stdout, "%s\n", url);
		free(data);
	}
	return ret;
}

int main(int argc, char **argv) {
	if(argc < 2) {
		char str[2100];
		while(fscanf(stdin, "%s", str) > 0) {
			print_urls(str);
		}
	} else if(strcmp(argv[1], "help") == 0) {
		fprintf(stderr, "\n"\
						"Usage: \n"\
						" urlsniff [URL] [URL] ...\n\n"\
						"Fetch URLs from a webpage."
		);
	}
	else {
		for(int i = 1; i < argc; i++)
			print_urls(argv[i]);
	}
	return 0;
}
