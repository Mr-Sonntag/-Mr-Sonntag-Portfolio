#include <stddef.h>
#include <stdlib.h>

#include "myStrings.h"

char *repeat(char *s, int x, char sep) {
    if (s == NULL) return NULL;

    char *temp = s;
    int slen = 0;

    while (*temp != '\0') {
        slen++;
        temp++;
    }

    char *out = malloc(sizeof(char) * (slen*x+x));

    for (int i = 0; i < x; i++) {
        for (int j = 0; j < slen; j++) {
            if (j+1>=slen && i+1 < x) {
                out[i*slen+slen+i] = sep;
            }
            out[i*slen+j+i] = s[j];
        }
    }
    out[slen*x+x-1] = '\0';
    return out;
}