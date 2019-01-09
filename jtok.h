/*
 * jtok Copyright (C) 2011-2019 Jess Mahan <jess@alienrobotarmy.com>
 *
 * jtok is a *better* string tokenizing routine. use this
 * in place of strtok(), strsep(), etc.
 *
 * int jtok(struct tokens *tok, char *string, char delim)
 *
 *
 * Usage:
 *
 * struct JToken tok;
 * tok.so = 0; tok.eo = 0; tok.match = NULL;
 * jtok(&tok, "this,is,a,test", ',');
 * free(tok.match);
 *
 *
 * Return Value:
 *
 * jotk returns an integer and stores the token in '(struct JToken)->match'
 * 0 = No token found;
 * 1 = Token found;
 * Even if no token was found jtok will still copy the contents of
 * char *string into tok.match, which must be freed after the final
 * call to jtok.
 *
 *
 * Notes:
 *
 * You mush initialize the JToken struct before using:
 *   tok.so = 0; tok.eo = 0; tok.match = NULL;
 * Failure to do so will result in unexpected behaviour.
 *
 *
 * Example:
 *
 * int main(int argc, char *argv[]) {
 *   int ret = 0;
 *   struct JToken tok;
 *   tok.so = 0; tok.eo = 0; tok.match = NULL;
 *   while ((ret = jtok(&tok, argv[1], ',')) > 0) {
 *     fprintf(stdout, "%s\n", tok.match);
 *   }
 *   free(tok.match);
 *   return 0;
 * }
 */

struct JToken {
    int so;
    int eo;
    char *match;
};
int jtok(struct JToken *tok, char *string, char delim);
