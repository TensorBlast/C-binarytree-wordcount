#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "tree.h"

#define MAXWORD 100
#define MAXLEN 100

int getword(char *, int);

static char buf[MAXLEN];
int c = 0;

int main()
{
	printf("Hello World\n");

	struct tnode *root;
	char word[MAXWORD];

	root = NULL;

	while(getword(word, MAXWORD) != EOF)
		if (isalpha(word[0]))
			root = addtree(root, word);

	printf("Word Counts: \n");
	treeprint(root);

	return 0;
}

int getword(char *word, int lim)
{
	int c, getch(void);
	void ungetch(int);
	char *w = word;

	while (isspace(c = getch()))
		;

	if (c != EOF)
		*w++ = c;

	if (!isalpha(c)) {
		*w = '\0';
		return c;
	}
	for (; --lim > 0; w++)
		if(!isalnum(*w = getch())) {
			ungetch(*w);
			break;
		}

	*w = '\0';
	return word[0];
}

int getch(void)
{
	return (c > 0)?buf[--c]:getchar();
}

void ungetch(int w)
{
	if(c >= MAXLEN)
		printf("ungetch: Buffer size exceeded\n");
	else
		buf[c++] = w;
}