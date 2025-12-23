#include "myStrings.h"

int ends_with_ignore_case(char *s, char *suff) {
    char *temp = s;
    int slen = 0;
    int sufflen = 0;
    while (*temp != '\0') {
        slen++;
        temp++;
    }
    temp = suff;

    while (*temp != '\0') {
        sufflen++;
        temp++;
    }
    int suffin = 0;
    for (int i = slen-sufflen; i < slen; i++) {
        if (s[i] != suff[suffin]) {
            return 0;
        }
        suffin++;
    }
    return 1;
}