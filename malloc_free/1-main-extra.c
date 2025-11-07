#include "main.h"
#include <stdio.h>
#include <stdlib.h>

static void show(const char *label, char *p)
{
    if (p == NULL)
        printf("%s: (NULL)\n", label);
    else
        printf("%s: \"%s\"\n", label, p);
}

int main(void)
{
    char *a = _strdup("Holberton School!");
    char *b = _strdup("");
    char *c = _strdup("First, solve the problem. Then, write the code.");
    char *d = _strdup(NULL);

    show("A", a);
    show("B", b);
    show("C", c);
    show("D", d);

    free(a);
    free(b);
    free(c);
    /* d == NULL, don't free */

    return (0);
}
