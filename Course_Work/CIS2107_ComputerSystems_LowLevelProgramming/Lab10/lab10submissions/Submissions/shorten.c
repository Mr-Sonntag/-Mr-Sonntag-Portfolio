
#include <stdio.h>
#include <stdlib.h>

#include "myStrings.h"

void shorten(char *s, int new_len) {
    int len = 0;
    char *temp = s;

    while (*temp != '\0') {
        len++;
        temp++;
    }

    if (len <= new_len) return;

    s[new_len] = '\0';

}