#include <stddef.h>
#include <stdlib.h>

#include "myStrings.h"

char *str_zip(char *s1, char *s2) {

    int len1 = 0;
    int len2 = 0;
    int pos = 0;
    char *temp = s1;

    while (*temp != '\0') {
        len1++;
        temp++;
    }

    temp = s2;
    while (*temp != '\0') {
        len2++;
        temp++;
    }

    char *zipped = malloc(sizeof(char)*(len1+len2));
    if (zipped == NULL) return NULL;


    if (len1 <= len2) {
        while (*s1 != '\0') {
            zipped[pos++] = *s1++;
            zipped[pos++] = *s2++;
        }
        while (*s2 != '\0') {
            zipped[pos++] = *s2++;
        }
    }else {
        while (*s2 != '\0') {
            zipped[pos++] = *s1++;
            zipped[pos++] = *s2++;
        }
        while (*s1 != '\0') {
            zipped[pos++] = *s1++;
        }
    }
    zipped[len1 + len2] = '\0';

    return zipped;
}