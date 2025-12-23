#include <stdlib.h>

#include "myStrings.h"

char *dedup(char *s) {

    int len = 0;
    while (s[len] != '\0') len++;

    char *ded = malloc(sizeof(char)*(len+1));
    if (ded == NULL) return NULL;
    int seen[256] = {0};
    int index = 0;

    for (int i = 0; i < len; i++) {
        unsigned char c = (unsigned char)s[i];
        if (seen[c]==0) {
            seen[c]++;
            ded[index++] = c;
        }
    }

    ded[index] = '\0';
    return ded;

}