#include <stddef.h>

#include "myStrings.h"

int is_empty(char *s) {
    int empty = 1;
    if (s == NULL) return empty;

    while (*s==' ' || *s=='\t' || *s == '\n' || *s == '\r' || *s == '\f' || *s == '\v') {
        s++;
    }

    if (*s == '\0') return empty;

    return --empty;
}