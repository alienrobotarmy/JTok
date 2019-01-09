#include <stdio.h>
#include <stdlib.h>
#include "jtok.h"

int main(int argc, char *argv[])
{
    int ret = 0;
    char delim = argv[1][0];

    /* Inititalze JToken */
    struct JToken *tok = malloc(sizeof(struct JToken));
    tok->so = 0; // Token starting offset (do not modify this value)
    tok->eo = 0; // Token ending offset   (do not modify this value)
    tok->match = NULL;
    /* */

    /* Iterate through our text and display tokens, one at a time */
    while ((ret = jtok(tok, argv[2], delim)) > 0)
        fprintf(stdout, "[%s]\n", tok->match);

    /* Clean up */
    free(tok->match);
    free(tok);
    /* */

    return 0;
}

