#include "tree.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include "tree.h"

char * Strdup(char * w)
{
	char * s = (char *) malloc(strlen(w)+1);
	if (w!=NULL)
		strcpy(s, w);
	return s;
}

struct tnode *addtree(struct tnode *p, char *w)
{
	int cond;

	if (p==NULL) {
		p = talloc();
		p->word = Strdup(w);
		p->count = 1;
		p->left = NULL;
		p->right = NULL;
	}
	else if ((cond = strcmp(w, p->word))==0)
		p->count++;
	else if (cond < 0)
		p->left = addtree(p->left, w);
	else
		p->right = addtree(p->right, w);

	return p;
}

struct tnode *talloc()
{
	return (struct tnode *)malloc(sizeof(struct tnode));
}



void treeprint(struct tnode * p)
{
	if (p != NULL)
	{
		treeprint(p->left);
		printf("%4d %s\n", p->count, p->word);
		treeprint(p->right);
	}
}