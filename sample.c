#include <stdio.h>

char* tag = "href";

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

int main() {
	char url[2100];
	char *html = "<ul class=\"footer-links\">\r\n\t\t\t\t\t\t\t<li><a href=\"https://www.chitkara.edu.in/chitkara-educational-trust\">Chitkara Educational Trust</a></li>\r\n\t\t\t\t\t\t\t<li><a href=\"https://www.chitkara.edu.in/overview/\">Chitkara University, Punjab</a></li>\r\n\t\t\t\t\t\t\t<li><a href=\"http://chitkarauniversity.edu.in/\" target=\"_blank\">Chitkara University, Himachal Pradesh</a></li>\r\n\t\t\t\t\t\t\t<li><a href=\"http://www.chitkaraschool.in\" target=\"_blank\">Chitkara International School</a></li>\r\n\t\t\t\t\t\t\t<li><a href=\"https://www.chitkara.edu.in/international-collaborations/\">Office of International Affairs</a></li>\r\n\t\t\t\t\t\t\t<li><a href=\"https://www.chitkara.edu.in/office-external-affairs/\">Office of External Affairs</a></li>\r\n\t\t\t\t\t\t\t<li><a href=\"https://www.chitkara.edu.in/can/\"  target=\"_blank\">Chitkara Alumni Network</a></li>\r\n                            <li><a href=\"https://curin.chitkara.edu.in/\"  target=\"_blank\">CURIN</a></li>\r\n\t\t\t\t\t\t\t<li><a href=\"http://cuceed.org/\"  target=\"_blank\">CEED</a></li>\r\n\t\t\t\t\t\t</ul>\r\n";
	char *t = html;
	while(url_extract(url, 2100, &t)) //2100 is max URL size
		printf("%s\n", url);
	return 0;
}
