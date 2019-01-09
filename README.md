# Jtok - a better tokenization function for C

JTok is a simple to use, leak free and thread safe tokenization.

It does not rely on static or global variables, which makes this for safe integration into threaded programs where strok(r) and strsep are know to be problematic. 

## Example Usage
This is our example file `test.c`
```c
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
```

Compile our test program
```sh
gcc -Wall -o test ./test.c ./jtok.c 
```

Run it using comma as a delimeter
```sh
./jtok , "this,is,a,test,of,jtok" 
```

### Stuff if can't do

Right now, JTok can only tokenize based on a single character.

### Tests
Using the sample program above, and feeding the contents of /etc/passwd:

`valgrind ./jtok "$(cat /etc/passwd)"`
```
==9729== Memcheck, a memory error detector
==9729== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==9729== Using Valgrind-3.13.0 and LibVEX; rerun with -h for copyright info
... [Hidden Contents of /etc/passwd] ...
==9729== 
==9729== HEAP SUMMARY:
==9729==     in use at exit: 0 bytes in 0 blocks
==9729==   total heap usage: 267 allocs, 267 frees, 3,651 bytes allocated
==9729== 
==9729== All heap blocks were freed -- no leaks are possible
==9729== 
==9729== For counts of detected and suppressed errors, rerun with: -v
==9729== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```
