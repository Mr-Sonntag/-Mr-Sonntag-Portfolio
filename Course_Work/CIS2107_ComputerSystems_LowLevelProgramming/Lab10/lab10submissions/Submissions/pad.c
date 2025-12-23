#include <stddef.h>
#include <stdlib.h>

#include "myStrings.h"

char *pad(char *s, int d) {

    if (s == NULL) return NULL;
    char *temp = s;
    int len = 0;

    while (*temp != '\0') {
        temp++;
        len++;
    }

    if (len == d) {
        return s;
    }if (len>d) {
        return NULL;
    }
    int pad = len;
    while (pad <= d) {
        if (d % pad == 0) {
            char *new = malloc(sizeof(char) * (pad+1));
            for (int i = 0; i < pad; i++) {
                if (i < len) {
                    new[i] = s[i];
                }else {
                    new[i] = ' ';
                }
            }
            new[pad] = '\0';
            return new;
        }
        pad++;
    }

    return s;
}
